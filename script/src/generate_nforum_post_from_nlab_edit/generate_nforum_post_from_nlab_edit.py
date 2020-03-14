#!/usr/bin/python3.7

"""
API for generating an nForum post following an nLab page edit

---

To use, set up (if it is not already in place) a virtual environment as follows.

    python3 -m venv venv

    source venv/bin/activate

    pip3 install MySQLdb

    deactivate

Once the virtual environment has been set up, to use the API, launch the
virtual environment by running:

    source venv/bin/activate

Then run the script as follows (it will not work if using the ./ syntax).

    python generate_nforum_post_from_nlab_edit.py --help

This will describe the available options. As will be seen, there are two
subcommands, 'create' and 'edit', whose descriptions can be obtained by
running

   python generate_nforum_post_from_nlab_edit.py create --help

or

   python generate_nforum_post_from_nlab_edit.py edit --help

When finished, shut down the virtual environment by running:

    deactivate
"""

import argparse
import datetime
import logging
import MySQLdb
import os
import sys
import time
import urllib.parse

"""
Initialises logging. Logs to

nforum_announcer.log
"""
logger = logging.getLogger(__name__)
logger.setLevel(logging.INFO)
logging.Formatter.converter = time.gmtime
logging_formatter = logging.Formatter(
    "%(asctime)s %(levelname)s %(name)s %(message)s")
log_directory = os.environ["NLAB_LOG_DIRECTORY"]
logging_file_handler = logging.FileHandler(
    os.path.join(log_directory, "nforum_announcer.log"))
logging_file_handler.setFormatter(logging_formatter)
logger.addHandler(logging_file_handler)

class FailedToCarryOutQueryException(Exception):
    pass

"""
For a single database query
"""
def execute_single_with_parameters(query, parameters):
    database_user = os.environ["NLAB_DATABASE_USER"]
    database_password = os.environ["NLAB_DATABASE_PASSWORD"]
    database_name = os.environ["NLAB_DATABASE_NAME"]
    database_connection = MySQLdb.connect(
        user = database_user,
        password= database_password,
        db = database_name,
        charset = "utf8",
        use_unicode = True)
    cursor = database_connection.cursor()
    try:
        cursor.execute(query, parameters)
        results = cursor.fetchall()
        database_connection.commit()
    except MySQLdb.Error as e:
        logger.warning(
            "Failed to carry out the query " +
            query +
            " with parameters: " +
            str(parameters) +
            ". Error: " +
            str(e))
        database_connection.rollback()
        raise FailedToCarryOutQueryException()
    finally:
        cursor.close()
        database_connection.close()
    return results

"""
For a transaction (list of database queries)
"""
def execute_with_parameters(queries_with_parameters):
    database_user = os.environ["NLAB_DATABASE_USER"]
    database_password = os.environ["NLAB_DATABASE_PASSWORD"]
    database_name = os.environ["NLAB_DATABASE_NAME"]
    database_connection = MySQLdb.connect(
        user = database_user,
        password= database_password,
        db = database_name,
        charset = "utf8",
        use_unicode = True)
    cursor = database_connection.cursor()
    try:
        for query, parameters in queries_with_parameters:
            cursor.execute(query, parameters)
        results = cursor.fetchall()
        database_connection.commit()
        cursor.close()
    except MySQLdb.Error as e:
        logger.warning(
            "Failed to carry out the query " +
            query +
            " with parameters: " +
            str(parameters) +
            ". Error: " +
            str(e))
        database_connection.rollback()
        raise FailedToCarryOutQueryException()
    finally:
        database_connection.close()
    return results

class _NoSuchWebException(Exception):
    pass

def _address_of_web(web_id):
    query_results = execute_single_with_parameters(
        "SELECT address FROM webs WHERE id = %s",
        [ web_id ])
    try:
        return query_results[0][0]
    except IndexError:
        raise _NoSuchWebException

class NoNForumUserCorrespondingToNLabAuthorException(Exception):
    pass

"""
Finds the nForum user with the same 'Name' as an nLab author if there exists
such a user (case insensitive). If there is no match or more than one match
with 'Name', splits the nLab author at whitespace. If there are exactly two
names after the split, tries to match these against FirstName and LastName. If
this fails, tries to match against Names, joining the two names with an
underscore. If this too fails, tries to find the nLab author in the

author_to_user

file.
"""
def nforum_user_id(nlab_author):
    user_id = None
    query_results = execute_single_with_parameters(
        "SELECT UserID FROM mathforge_user WHERE Name = %s",
        [nlab_author])
    try:
        if len(query_results) <= 1:
            user_id = query_results[0][0]
            logger.info(
                "Successfully associated nLab author " +
                nlab_author +
                " to nForum user with UserID: " +
                str(user_id))
    except IndexError:
        pass
    if user_id:
        try:
            return (user_id, _nforum_local_id(user_id))
        except _NoLocalNForumUserCorrespondingToNLabAuthorException:
            user_id = None
            pass

    names = nlab_author.split()
    if len(names) == 2:
        query_results = execute_single_with_parameters(
            "SELECT UserID FROM mathforge_user " +
            "WHERE FirstName = %s AND LastName = %s",
            [names[0], names[1]])
        try:
            if len(query_results) <= 1:
                user_id = query_results[0][0]
                logger.info(
                    "Successfully associated nLab author " +
                    nlab_author +
                    " to nForum user with FirstName " +
                    names[0] +
                    " and LastName " +
                    names[1] +
                    ". UserID: " +
                    str(user_id))
        except IndexError:
            pass
        if user_id:
            try:
                return (user_id, _nforum_local_id(user_id))
            except _NoLocalNForumUserCorrespondingToNLabAuthorException:
                user_id = None
                pass

        names_joined_with_underscore = names[0] + "_" + names[1]
        query_results = execute_single_with_parameters(
            "SELECT UserID FROM mathforge_user " +
            "WHERE Name = %s",
            [names_joined_with_underscore])
        try:
            if len(query_results) <= 1:
                user_id = query_results[0][0]
                logger.info(
                    "Successfully associated nLab author " +
                    nlab_author +
                    " to nForum user " +
                    names_joined_with_underscore +
                    ". UserID: " +
                    str(user_id))
        except IndexError:
            pass
        if user_id:
            try:
                return (user_id, _nforum_local_id(user_id))
            except _NoLocalNForumUserCorrespondingToNLabAuthorException:
                user_id = None
                pass
    author_to_user_filename = os.environ["NLAB_AUTHOR_TO_USER_FILE"]
    with open(author_to_user_filename, "r") as author_to_user_file:
        for line in author_to_user_file:
            author_and_user = line.split(",")
            number_of_columns = len(author_and_user)
            if (number_of_columns > 2) or (number_of_columns < 2):
                logger.warning(
                    "Syntax error in author_to_user file at the following " +
                    "line: " +
                    line)
            else:
                author = author_and_user[0].strip()
                if author == nlab_author:
                    user = author_and_user[1].strip()
                    query_results = execute_single_with_parameters(
                        "SELECT UserID FROM mathforge_user " +
                        "WHERE Name = %s",
                        [user])
                    try:
                        if len(query_results) <= 1:
                            user_id = query_results[0][0]
                            logger.info(
                                "Successfully associated nLab author " +
                                nlab_author +
                                " to nForum user " +
                                user +
                                " using the author_to_user file. UserID: " +
                                str(user_id))
                    except IndexError:
                        pass
                    if user_id:
                        try:
                            return (user_id, _nforum_local_id(user_id))
                        except _NoLocalNForumUserCorrespondingToNLabAuthorException:
                            user_id = None
                            pass
                    break
    logger.info(
        "Did not find nForum user corresponding to nLab author: " +
        nlab_author)
    raise NoNForumUserCorrespondingToNLabAuthorException()

class _NoLocalNForumUserCorrespondingToNLabAuthorException(Exception):
    pass

"""
Finds the LocalID corresponding to a UserID
"""
def _nforum_local_id(user_id):
    query_results = execute_single_with_parameters(
        "SELECT LocalID FROM mathforge_nforum_User WHERE UserID = %s",
        [user_id])
    try:
        local_id = query_results[0][0]
        logger.info(
            "Successfully looked up nForum LocalID " +
            str(local_id) +
            " to nForum UserID: " +
            str(user_id))
        return local_id
    except IndexError:
        logger.info(
            "No LocalID for nForum user with UserID: " +
            str(user_id))
        raise _NoLocalNForumUserCorrespondingToNLabAuthorException()

class UnableToDetermineRevisionNumberException(Exception):
    pass

def revision_number(nlab_page_id):
    query_results = execute_single_with_parameters(
        "SELECT COUNT(id) FROM revisions WHERE page_id = %s",
        [nlab_page_id])
    try:
        revision_number = query_results[0][0]
        logger.info(
            "Successfully found revision number for nLab page with ID " +
            str(nlab_page_id) +
            " to be: " +
            str(revision_number))
        return revision_number
    except IndexError:
        logger.warning(
            "Unable to determine revision number for nLab page with ID: " +
            str(nlab_page_id))
        raise UnableToDetermineRevisionNumberException()

class NoExistingDiscussionException(Exception):
    pass

def _latest_changes_category_id(latest_changes_web_name):
    category_name = "- " + latest_changes_web_name + ": Latest Changes"
    query_results = execute_single_with_parameters(
        "SELECT CategoryID FROM mathforge_nforum_Category " +
        "WHERE Name = %s",
        [category_name])
    try:
        return query_results[0][0]
    except IndexError:
        return 5

"""
Finds the DiscussionID of the last used forum thread whose name is that of
the nLab page. The search is case insensitive.
"""
def latest_forum_discussion_id(nlab_page_name, latest_changes_web_name):
    latest_changes_category_id = _latest_changes_category_id(
        latest_changes_web_name)
    query_results = execute_single_with_parameters(
        "SELECT DiscussionID FROM mathforge_nforum_Discussion " +
        "WHERE Name = BINARY %s " +
        "AND CategoryID = %s " +
        "ORDER BY DateLastActive DESC " +
        "LIMIT 1",
        [nlab_page_name,
         latest_changes_category_id])
    try:
        return query_results[0][0]
    except IndexError:
        raise NoExistingDiscussionException()

class _ForumPostParameters:
    _nlab_edit_announcer_user_id = 1691
    _nlab_edit_announcer_local_user_id = 693

    def __init__(
            self,
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id):
        self.nlab_page_name = nlab_page_name
        self.latest_changes_web_name = latest_changes_web_name
        self.web_id = web_id
        self.user_id = user_id
        self.local_id = local_id

    """
    Creates discussion in the nForum in the 'Latest changes' category whose
    name is the same (case insensitive) as the nLab page. Posts an
    announcement of the nLab page to the nForum as the first comment in this
    discussion.
    """
    def create_discussion_and_post_to_it(self, announcement):
        latest_changes_category_id = _latest_changes_category_id(
            self.latest_changes_web_name)
        query_with_parameters_one = (
            "INSERT INTO mathforge_nforum_Discussion (" +
            "AuthUserID, Name, DateCreated, CategoryID) " +
            "VALUES (%s, %s, NOW(), %s)",
            [self.user_id,
             self.nlab_page_name,
             latest_changes_category_id])
        query_with_parameters_two = (
            "SET @discussion_id = LAST_INSERT_ID()",
            [])
        query_with_parameters_three = (
            "INSERT INTO mathforge_nforum_Comment (" +
            "DiscussionID, AuthUserID, DateCreated, Body, FormatType) " +
            "VALUES (@discussion_id, %s, NOW(), %s, %s)",
            [self.user_id,
             announcement,
             "MarkdownItex"])
        query_with_parameters_four = (
            "SET @comment_id = LAST_INSERT_ID()",
            [])
        query_with_parameters_five = (
            "UPDATE mathforge_nforum_Discussion " +
            "SET CountComments = 1, " +
            "DateLastActive = NOW(), " +
            "FirstCommentID = @comment_id, "  +
            "LastUserID = %s " +
            "WHERE DiscussionID = @discussion_id",
            [self.user_id])
        query_with_parameters_six = (
            "UPDATE mathforge_nforum_User " +
            "SET CountComments = CountComments + 1, " +
            "DateLastActive = NOW() " +
            "WHERE LocalID = %s;",
             [self.local_id])
        queries_with_parameters = [
            query_with_parameters_one,
            query_with_parameters_two,
            query_with_parameters_three,
            query_with_parameters_four,
            query_with_parameters_five,
            query_with_parameters_six]
        execute_with_parameters(queries_with_parameters)

    """
    Posts announcement to nForum when there is an existing discussion in the
    'Latest changes' category with the same name (case insensitive) as the nLab
    page.
    """
    def post_to_existing_discussion(
            self,
            discussion_id,
            announcement):
        query_with_parameters_one = (
            "INSERT INTO mathforge_nforum_Comment (" +
            "DiscussionID, AuthUserID, DateCreated, Body, FormatType) " +
            "VALUES (%s, %s, NOW(), %s, %s)",
            [discussion_id,
             self.user_id,
             announcement,
             "MarkdownItex"])
        query_with_parameters_two = (
            "UPDATE mathforge_nforum_Discussion " +
            "SET CountComments = CountComments + 1, " +
            "DateLastActive = NOW(), " +
            "LastUserID = %s " +
            "WHERE DiscussionID = %s",
            [self.user_id,
             discussion_id])
        query_with_parameters_three = (
            "UPDATE mathforge_nforum_User " +
            "SET CountComments = CountComments + 1, " +
            "DateLastActive = NOW() " +
            "WHERE LocalID = %s",
            [self.local_id])
        queries_with_parameters = [
            query_with_parameters_one,
            query_with_parameters_two,
            query_with_parameters_three ]
        execute_with_parameters(queries_with_parameters)

    """
    Posts announcement to nForum when there is an existing discussion in the
    'Latest changes' category with the same name (case insensitive) as the old
    name of an nLab page whose name has been changed, and changes the name of
    the discussion to the new name of the nLab page.
    """
    def post_to_existing_discussion_with_name_change(
            self,
            discussion_id,
            announcement):
        query_with_parameters_one = (
            "UPDATE mathforge_nforum_Discussion " +
            "SET Name = %s " +
            "WHERE DiscussionID = %s",
            [self.nlab_page_name,
             discussion_id])
        query_with_parameters_two = (
            "INSERT INTO mathforge_nforum_Comment (" +
            "DiscussionID, AuthUserID, DateCreated, Body, FormatType) " +
            "VALUES (%s, %s, NOW(), %s, %s)",
            [discussion_id,
             self.user_id,
             announcement,
             "MarkdownItex"])
        query_with_parameters_three = (
            "UPDATE mathforge_nforum_Discussion " +
            "SET CountComments = CountComments + 1, " +
            "DateLastActive = NOW(), " +
            "LastUserID = %s " +
            "WHERE DiscussionID = %s",
            [self.user_id,
             discussion_id])
        query_with_parameters_four = (
            "UPDATE mathforge_nforum_User " +
            "SET CountComments = CountComments + 1, " +
            "DateLastActive = NOW() " +
            "WHERE LocalID = %s",
            [self.local_id])
        queries_with_parameters = [
            query_with_parameters_one,
            query_with_parameters_two,
            query_with_parameters_three,
            query_with_parameters_four ]
        execute_with_parameters(queries_with_parameters)

class _CreateForumPostParameters(_ForumPostParameters):
    def __init__(
            self,
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id,
            author,
            announcement):
        super().__init__(
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id)
        self.author = author
        if announcement is not None:
            self.announcement = announcement.strip()
        else:
            self.announcement = None

    """
    Comment body for announcing a page creation
    """
    def nforum_announcement(self, found_nforum_user):
        if not self.announcement:
            announcement = (
                "Page created, but author did not leave any comments.")
        else:
            announcement = self.announcement
        if not found_nforum_user:
            announcement += (
                "\n\n" +
                self.author)
        announcement += (
            "\n\n" +
            ", ".join(self.page_links()))
        return announcement

    def page_links(self):
        url_encoded_page_name = urllib.parse.quote_plus(self.nlab_page_name)
        web_address = _address_of_web(self.web_id)
        version = (
            '<a href="https://ncatlab.org/' +
            web_address +
            '/revision/' +
            url_encoded_page_name +
            '/' +
            str(1) +
            '">v' +
            str(1) +
            '</a>')
        current = (
            '<a href="https://ncatlab.org/' +
            web_address +
            '/show/' +
            url_encoded_page_name +
            '">current</a>')
        return (version, current)

class _EditForumPostParameters(_ForumPostParameters):
    def __init__(
            self,
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id,
            author,
            announcement,
            page_id):
        super().__init__(
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id)
        self.author = author
        if announcement is not None:
            self.announcement = announcement.strip()
        else:
            self.announcement = None
        self.page_id = page_id

    """
    See if there is an existing nForum discussion thread in the 'Latest changes'
    category with the same title as the edited nLab page, and post the
    announcement to this thread if so. If there is more than one, choose the
    last used. If there is no such thread, create one and post to it.
    """
    def post(self, found_nforum_user):
        try:
            discussion_id = latest_forum_discussion_id(
                self.nlab_page_name,
                self.latest_changes_web_name)
            self.post_to_existing_discussion(
                discussion_id,
                self.nforum_announcement(found_nforum_user))
        except NoExistingDiscussionException:
            forum_post_parameters = _ForumPostParameters(
                self.nlab_page_name,
                self.latest_changes_web_name,
                self.web_id,
                self.user_id,
                self.local_id)
            forum_post_parameters.create_discussion_and_post_to_it(
                self.nforum_announcement(found_nforum_user))

    def post_with_name_change(self, found_nforum_user, old_page_name):
        try:
            discussion_id = latest_forum_discussion_id(
                old_page_name,
                self.latest_changes_web_name)
            self.post_to_existing_discussion_with_name_change(
                discussion_id,
                self.nforum_announcement(found_nforum_user))
            logger.info(
                "Successfully changed the title of nForum " +
                "discussion from " +
                old_page_name +
                " to " +
                self.nlab_page_name)
        except NoExistingDiscussionException:
            forum_post_parameters = _ForumPostParameters(
                self.nlab_page_name,
                self.latest_changes_web_name,
                self.web_id,
                self.user_id,
                self.local_id)
            forum_post_parameters.create_discussion_and_post_to_it(
                self.nforum_announcement(found_nforum_user))

    """
    Comment body for announcing a page edit
    """
    def nforum_announcement(self, found_nforum_user):
        if not self.announcement:
            announcement = (
                "Non-trivial edit made, but author did not leave any comments.")
        else:
            announcement = self.announcement
        if not found_nforum_user:
            announcement += (
                "\n\n" +
                self.author)
        announcement += (
            "\n\n" +
            ", ".join(self.page_links()))
        return announcement

    def page_links(self):
        url_encoded_page_name = urllib.parse.quote_plus(self.nlab_page_name)
        web_address = _address_of_web(self.web_id)
        revision_number_for_edit = revision_number(self.page_id)
        version = (
            '<a href="https://ncatlab.org/' +
            web_address +
            '/revision/' +
            url_encoded_page_name +
            '/' +
            str(revision_number_for_edit) +
            '">v' +
            str(revision_number_for_edit) +
            '</a>')
        current = (
            '<a href="https://ncatlab.org/' +
            web_address +
            '/show/' +
            url_encoded_page_name +
            '">current</a>')
        if revision_number_for_edit > 1:
            diff = (
                '<a href="https://ncatlab.org/' +
                web_address +
                '/revision/diff/' +
                url_encoded_page_name +
                '/' +
                str(revision_number_for_edit) +
                '">diff</a>')
            return (diff, version, current)
        return (version, current)

"""
Sets up the command line argument parsing
"""
def argument_parser():
    parser = argparse.ArgumentParser(
        description = "Announces an nLab edit on the nForum")
    subparsers = parser.add_subparsers(dest="subcommand")
    parser_create_page = subparsers.add_parser(
        "create",
        help = "Announces an nLab page creation on the nForum, creating a " +
        "new nForum discussion in the 'Latest Changes' category with the " +
        "same title as the created nLab page, and posting an announcement to " +
        "it.")
    parser_edit_page = subparsers.add_parser(
        "edit",
        help = "Announces an nLab page edit on the nForum. If it is not a "
        "trivial edit, finds the latest nForum discussion in the " +
        "'Latest Changes' category with the same name as the edited nLab " +
        "page and posts an announcement to it, or creates a new discussion " +
        "in this category with this title if it does not already exist, and " +
        "posts an announcement to it. If it is a trivial edit, only logs " +
        "it. If the edit involves a change of name of the nLab page and a " +
        "discussion on the nForum with the same title as the old name of the " +
        "nLab page exists, changes the title of the discussion to the new " +
        "name of the page.")
    parser_create_page.add_argument(
        "nlab_page_name",
        help = "Name of created nLab page")
    parser_create_page.add_argument(
        "latest_changes_web_name",
        help = (
            "Name of web to which the created nLab page belongs, as " +
            "displayed in the nForum latest changes category name"))
    parser_create_page.add_argument(
        "web_id",
        help = "ID of web to which the created nLab page belongs")
    parser_create_page.add_argument(
        "announcement",
        help = "Comments on the created nLab page")
    parser_create_page.add_argument(
        "author",
        help = "Author of the created nLab page")
    parser_edit_page.add_argument(
        "nlab_page_name",
        help = "Name of edited nLab page. If the edit involves a change " +
            "in the name of the page, this should be the new name of the " +
            "page")
    parser_edit_page.add_argument(
        "latest_changes_web_name",
        help = (
            "Name of web to which the edited nLab page belongs, as " +
            "displayed in the nForum latest changes category name"))
    parser_edit_page.add_argument(
        "web_id",
        help = "ID of web to which the edited nLab page belongs")
    parser_edit_page.add_argument(
        "announcement",
        help = "Comments on the edited nLab page")
    parser_edit_page.add_argument(
        "author",
        help = "Author of the edited nLab page")
    parser_edit_page.add_argument(
        "page_id",
        help = "ID of the edited nLab page")
    parser_edit_page.add_argument(
        "-o",
        "--old_page_name",
        help = (
            "Old page name for the edited nLab page if the edit involves " +
            "a name change"))
    parser_edit_page.add_argument(
        "--is_trivial",
        action = "store_true",
        help = "Indicate that the edit was trivial")
    return parser

def main():
    parser = argument_parser()
    arguments = parser.parse_args()
    nlab_page_name = arguments.nlab_page_name
    latest_changes_web_name = arguments.latest_changes_web_name
    web_id = arguments.web_id
    announcement = arguments.announcement
    author = arguments.author
    failure_message = None
    try:
        user_id, local_id = nforum_user_id(author)
        found_nforum_user = True
    except NoNForumUserCorrespondingToNLabAuthorException:
        user_id = _ForumPostParameters._nlab_edit_announcer_user_id
        local_id = _ForumPostParameters._nlab_edit_announcer_local_user_id
        found_nforum_user = False
    if arguments.subcommand == "create":
        forum_post_parameters = _CreateForumPostParameters(
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id,
            author,
            announcement)
        try:
            forum_post_parameters.create_discussion_and_post_to_it(
                forum_post_parameters.nforum_announcement(found_nforum_user))
            logger.info(
                "Successfully made nForum discussion for newly created nLab " +
                "page with name: " +
                nlab_page_name +
                ". Author: " +
                author +
                ". Web id: " +
                str(web_id))
        except FailedToCarryOutQueryException:
            logger.warning(
                "Due to a database error, could not make nForum discussion " +
                "for newly created nLab page with name: " +
                nlab_page_name +
                ". Author: " +
                author +
                ". Web id: " +
                str(web_id) +
                ". Announcement: " +
                announcement)
            failure_message = "Failed to make nForum discussion"
        except Exception as e:
            logger.warning(
                "Due to an unforeseen error, could not make nForum " +
                "discussion for newly created nLab page with name: " +
                nlab_page_name +
                ". Author: " +
                author +
                ". Web id: " +
                str(web_id) +
                ". Announcement: " +
                announcement +
                ". Error: " +
                str(e))
            failure_message = "Failed to make nForum discussion"
    else:
        if arguments.is_trivial:
            logger.info(
                "Trivial edit made to " +
                arguments.nlab_page_name +
                " in web with id " +
                str(web_id) +
                " by " +
                author +
                " at " +
                str(datetime.datetime.utcnow().replace(microsecond=0)) +
                " UTC")
            return
        forum_post_parameters =_EditForumPostParameters(
            nlab_page_name,
            latest_changes_web_name,
            web_id,
            user_id,
            local_id,
            author,
            announcement,
            arguments.page_id)
        old_page_name = arguments.old_page_name
        try:
            if old_page_name:
                forum_post_parameters.post_with_name_change(
                    found_nforum_user,
                    old_page_name)
                logger.info(
                    "Successfully made nForum post for newly edited nLab " +
                    "page with name: " +
                    nlab_page_name +
                    ". Author: " +
                    author +
                    ". Web id: " +
                    str(web_id))
            else:
                forum_post_parameters.post(found_nforum_user)
                logger.info(
                    "Successfully made nForum post for newly edited nLab " +
                    "page with name: " +
                    nlab_page_name +
                    ". Author: " +
                    author +
                    ". Web id: " +
                    str(web_id))
        except FailedToCarryOutQueryException:
            log_message = (
                "Due to a database error, could not make nForum post for " +
                "newly edited nLab page with name: " +
                nlab_page_name +
                ". Author: " +
                author +
                ". Web id: " +
                str(web_id))
            if old_page_name:
                log_message = log_message + (
                    ". Change of page name from " +
                    old_page_name +
                    " to " +
                    nlab_page_name)
            log_message = log_message + (
                ". Announcement: " +
                announcement)
            logger.warning(log_message)
            overall_failure_message = (
                "Failed to make nForum post to the discussion for the " +
                "edited nLab page")
        except Exception as e:
            log_message = (
                "Due to an unforeseen error, could not make nForum post for " +
                "newly edited nLab page with name: " +
                nlab_page_name +
                ". Author: " +
                author +
                ". Web id: " +
                str(web_id))
            if old_page_name:
                log_message = log_message + (
                    ". Change of page name from " +
                    old_page_name +
                    " to " +
                    nlab_page_name)
            log_message = log_message + (
                ". Announcement: " +
                announcement +
                " Error: " +
                str(e))
            logger.warning(log_message)
            failure_message = (
                "Failed to make nForum post to the discussion for the " +
                "edited nLab page")
    if failure_message is not None:
        sys.exit(failure_message)

if __name__ == "__main__":
    main()
