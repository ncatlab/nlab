#!/usr/bin/env python3

"""
Announces nLab edits on the nForum (Zulip): sends the rows of the table nlab_zulip_outbox, which
the nLab writes on page save (lib/zulip_announcer.rb), to Zulip in order, deletes the ones it
sent, and exits. systemd starts it when the nLab creates tmp/zulip_announcer_wake, and every few
minutes, so that rows that failed are tried again.

Each nLab page has one Zulip topic (table nlab_zulip_topics), in the channel of its web (table
nlab_zulip_channels). Announcements are posted as the one active Zulip user whose full name or
"nLab name" profile field is the nLab author name, which requires the bot to have the
can_forge_sender permission; other announcements are posted by the bot. Every run also copies
these names into the table nlab_zulip_member_names, for the spam detector. See README.md for the
setup, the configuration (the environment variables) and the operation.
"""

import contextlib
import dataclasses
import datetime
import functools
import logging
import os
import pathlib
import sys
import time
import typing
import unicodedata
import urllib.parse

import MySQLdb
import MySQLdb.cursors
import requests
import zulip

import markdown_itex

MAX_TOPIC_NAME_LENGTH = 60
MAX_SUFFIX = 20

# The profile field in which Zulip users can give their nLab author name, if it differs from their
# full name.
NLAB_NAME_FIELD = "nLab name"

# The nLab's directory (Rails.root); this file is script/src/zulip_announcer/zulip_announcer.py in it.
NLAB_DIRECTORY = pathlib.Path(__file__).resolve().parents[3]

# Created by the nLab when it has queued an announcement. systemd starts this script while the
# file exists (see README.md), and the script deletes it.
WAKE_FILE = NLAB_DIRECTORY / "tmp" / "zulip_announcer_wake"

logger = logging.getLogger("zulip_announcer")


def _setup_logging():
    logging.Formatter.converter = time.gmtime
    log_file = os.path.join(os.environ["NLAB_LOG_DIRECTORY"], "zulip_announcer.log")
    logging.basicConfig(level=logging.INFO, format="%(asctime)s %(levelname)s %(name)s %(message)s",
                        handlers=[logging.FileHandler(log_file), logging.StreamHandler()])


# ----------------------------------------------------------------- database

def connect_database(**arguments):
    """A connection whose statements commit right away, and whose rows are dicts."""
    return MySQLdb.connect(charset="utf8mb4", use_unicode=True, autocommit=True, cursorclass=MySQLdb.cursors.DictCursor, **arguments)


def database_from_environment():
    arguments = dict(user=os.environ["NLAB_DATABASE_USER"], password=os.environ["NLAB_DATABASE_PASSWORD"], db=os.environ["NLAB_DATABASE_NAME"])
    if os.environ.get("NLAB_DATABASE_SOCKET"):
        arguments["unix_socket"] = os.environ["NLAB_DATABASE_SOCKET"]
    return connect_database(**arguments)


def query(database, sql, parameters=None):
    """Runs one SQL statement, with %s placeholders; returns its rows."""
    with database.cursor() as cursor:
        cursor.execute(sql, parameters)
        return cursor.fetchall()


def query_one(database, sql, parameters=None):
    """The first row of the statement's result, or None."""
    rows = query(database, sql, parameters)
    return rows[0] if rows else None


class Topic(typing.NamedTuple):
    channel_id: int
    name: str
    first_message_id: typing.Optional[int]
    last_message_id: typing.Optional[int]


def store_topic(database, page_id, topic, url):
    # REPLACE first deletes the rows with the same page_id or the same first_message_id (both
    # are unique keys): one row per page, and one page per topic.
    query(database,
          "REPLACE INTO nlab_zulip_topics (page_id, channel_id, topic, first_message_id, last_message_id, url, updated_at) "
          "VALUES (%s, %s, %s, %s, %s, %s, UTC_TIMESTAMP())",
          [page_id, topic.channel_id, topic.name, topic.first_message_id, topic.last_message_id, url])


@dataclasses.dataclass
class OutboxRow:
    """A row of nlab_zulip_outbox (see schema.sql)."""
    id: int
    created_at: datetime.datetime
    kind: str
    web_id: int
    web_address: str
    page_id: int
    page_name: str
    old_page_name: typing.Optional[str]
    author: str
    comment: str
    revision: int
    last_error: typing.Optional[str]

    def __post_init__(self):
        self.comment = self.comment.strip()


# -------------------------------------------------------------------- Zulip

class ZulipError(zulip.ZulipError):
    """Zulip rejected a request. (The zulip package raises its other subclasses of
    zulip.ZulipError, e.g. when it cannot connect, and exceptions of requests.)"""

    def __init__(self, method, path, result):
        super().__init__("%s %s: %s" % (method, path, result.get("msg") or result))
        self.msg = result.get("msg")


class Zulip:
    """The few calls of Zulip's API that the announcer needs."""

    def __init__(self, site, client):
        self.site = site  # for links
        self.client = client

    def call(self, method, path, **parameters):
        result = self.client.call_endpoint(path, method=method, request=parameters)
        if result.get("result") != "success":
            raise ZulipError(method, path, result)
        return result

    def message(self, message_id):
        """The message, or None if it has been deleted."""
        try:
            return self.call("GET", "messages/%d" % message_id, apply_markdown=False)["message"]
        except ZulipError as e:
            # Zulip has no specific error code for this, only this message, which it translates
            # into the bot's language: the bot's language must be English.
            if e.msg == "Invalid message(s)":
                return None
            raise

    def first_message_id(self, channel_id, topic):
        """Id of the oldest message in the topic, or None."""
        narrow = [{"operator": "channel", "operand": channel_id}, {"operator": "topic", "operand": topic}]
        messages = self.call("GET", "messages", anchor="oldest", num_before=0, num_after=1, apply_markdown=False, narrow=narrow)["messages"]
        return messages[0]["id"] if messages else None

    @functools.cache
    def channel_name(self, channel_id):
        return self.call("GET", "streams/%d" % channel_id)["stream"]["name"]

    @functools.cache
    def members(self):
        """(public email, names) of the active users who are not bots; names are the full name
        and, if set, the "nLab name" profile field."""
        field_ids = [str(f["id"]) for f in self.call("GET", "realm/profile_fields")["custom_fields"] if f["name"] == NLAB_NAME_FIELD]
        if not field_ids:
            logger.warning("Zulip has no profile field %r; only full names are matched", NLAB_NAME_FIELD)
        members = []
        for user in self.call("GET", "users", include_custom_profile_fields=True)["members"]:
            if user["is_active"] and not user["is_bot"]:
                profile = user.get("profile_data") or {}
                names = [user["full_name"]] + [profile[i]["value"] for i in field_ids if profile.get(i, {}).get("value")]
                members.append((user["email"], names))
        return members

    def send(self, channel_id, topic, content, sender_email=None):
        """Posts as sender_email, or as the bot if that is None (call_endpoint leaves out None)."""
        return self.call("POST", "messages", type="stream", to=channel_id, topic=topic, content=content, sender=sender_email, read_by_sender=True)["id"]

    def rename_topic(self, message_id, topic):
        self.call("PATCH", "messages/%d" % message_id, topic=topic, propagate_mode="change_all", send_notification_to_old_thread=False, send_notification_to_new_thread=False)


def zulip_from_environment():
    """zulip.Client reads ZULIP_EMAIL, ZULIP_API_KEY and ZULIP_SITE itself."""
    site = os.environ["NFORUM_URL"]
    return Zulip(site, zulip.Client(site=os.environ.get("ZULIP_SITE") or site, retry_on_errors=False))


# --------------------------------------------------------------- formatting

def encode_hash_component(s):
    """As zerver/lib/url_encoding.py: encode_hash_component."""
    replacements = {"%": ".", "(": ".28", ")": ".29", ".": ".2E"}
    return "".join(replacements.get(c, c) for c in urllib.parse.quote(s, safe=""))


def topic_url(site, channel_id, channel_name, topic, message_id):
    return "%s/#narrow/channel/%d-%s/topic/%s/with/%d" % (
        site.rstrip("/"), channel_id, encode_hash_component(channel_name.replace(" ", "-")), encode_hash_component(topic), message_id)


def escape_markdown(text):
    """Literal text in Zulip Markdown (also prevents mentions)."""
    return "".join("\\" + c if c in "\\`*_{}[]()#+-.!|~<>$@:" else c for c in text)


def name_key(name):
    """Names are compared ignoring case, accents and repeated whitespace (as in the nForum
    converter's nlab_names.py). The old nForum lookups ignored case and accents, too."""
    decomposed = unicodedata.normalize("NFKD", " ".join(name.split()))
    return "".join(c for c in decomposed if not unicodedata.combining(c)).casefold()


def _truncate(name, limit):
    return name if len(name) <= limit else name[:limit - 1].rstrip() + "…"


def topic_name_candidates(page_name):
    """Topic names for a page, in order of preference."""
    base = " ".join(page_name.split()) or "(unnamed page)"
    yield _truncate(base, MAX_TOPIC_NAME_LENGTH)
    for n in range(2, MAX_SUFFIX + 1):
        suffix = " (%d)" % n
        yield _truncate(base, MAX_TOPIC_NAME_LENGTH - len(suffix)) + suffix


# ---------------------------------------------------------------- announcer

class Announcer:

    def __init__(self, database, zulip, nlab_url):
        self.database = database
        self.zulip = zulip
        self.nlab_url = nlab_url

    def query(self, sql, parameters=None):
        return query(self.database, sql, parameters)

    def query_one(self, sql, parameters=None):
        return query_one(self.database, sql, parameters)

    def process_pending(self):
        """Sends the pending announcements, in order, and deletes the ones that were sent. A row
        that fails stays, with its error, and is tried again by the next run. Returns the number
        of rows that failed."""
        failures = 0
        for row in self.query("SELECT * FROM nlab_zulip_outbox ORDER BY id"):
            row = OutboxRow(**row)
            try:
                message_id = self.process(row)
            except Exception as e:
                failures += 1
                # No traceback when Zulip is down or refuses: these are logged for every pending row on every run.
                logger.error("Failed to announce outbox row %d (page %d, %s): %r", row.id, row.page_id, row.page_name, e,
                             exc_info=not isinstance(e, (zulip.ZulipError, requests.RequestException)))
                self.query("UPDATE nlab_zulip_outbox SET last_error = %s WHERE id = %s", [repr(e), row.id])
                continue
            if message_id is None:
                logger.info("Processed outbox row %d (page %d, %s, author %s): nothing to announce", row.id, row.page_id, row.page_name, row.author)
            else:
                logger.info("Announced outbox row %d (page %d, %s, author %s): message %d", row.id, row.page_id, row.page_name, row.author, message_id)
            self.query("DELETE FROM nlab_zulip_outbox WHERE id = %s", [row.id])
        return failures

    def process(self, row):
        """Announces one outbox row; returns the message id, or None if nothing was posted (a
        rename without comment)."""
        topic = self.current_topic(row.page_id)
        if topic and row.old_page_name and row.old_page_name != row.page_name:
            topic = self.rename(row.page_id, topic, row.page_name)
        if not row.comment and row.kind == "edit":
            if topic:
                self.store(row.page_id, topic, self.zulip.channel_name(topic.channel_id))
            return None

        if topic is None:
            channel_id = self.channel_id(row.web_id)
            name, first_message_id = self.choose_topic_name(channel_id, row.page_name, row.page_id)
            topic = Topic(channel_id, name, first_message_id, None)
        # Everything that can fail happens before sending, so that a retry rarely posts twice.
        channel_name = self.zulip.channel_name(topic.channel_id)
        sender_email = self.sender_email(row.author)
        message_id = self.zulip.send(topic.channel_id, topic.name, self.compose(row, sender_email), sender_email)
        self.store(row.page_id, topic._replace(first_message_id=topic.first_message_id or message_id, last_message_id=message_id), channel_name)
        return message_id

    def channel_id(self, web_id):
        row = self.query_one("SELECT channel_id FROM nlab_zulip_channels WHERE web_id = %s", [web_id])
        if row is None:
            raise ValueError("no Zulip channel configured for web %d" % web_id)
        return row["channel_id"]

    def current_topic(self, page_id):
        """The page's topic as it is now in Zulip, or None."""
        row = self.query_one("SELECT first_message_id, last_message_id FROM nlab_zulip_topics WHERE page_id = %s", [page_id])
        if row is None:
            return None
        message = self.zulip.message(row["first_message_id"])
        if message is None:
            logger.info("Message %d, the start of the topic of page %d, is gone; a new topic will be used", row["first_message_id"], page_id)
            return None
        return Topic(message["stream_id"], message["subject"], row["first_message_id"], row["last_message_id"])

    def choose_topic_name(self, channel_id, page_name, page_id, own_first_message_id=None):
        """(name, first message id or None) of the topic to use for a page: the first candidate
        name that is unused, already the page's own topic, or an existing topic that no other page
        claims (e.g. one that someone started by hand, or the topic of a deleted page)."""
        for name in topic_name_candidates(page_name):
            first_message_id = self.zulip.first_message_id(channel_id, name)
            if first_message_id is None:
                return name, None
            if first_message_id == own_first_message_id:
                return name, first_message_id
            claimed = self.query(
                "SELECT t.page_id FROM nlab_zulip_topics t JOIN pages p ON p.id = t.page_id WHERE t.first_message_id = %s AND t.page_id <> %s",
                [first_message_id, page_id])
            if not claimed:
                return name, first_message_id
        raise ValueError("no free topic name for page %r" % page_name)

    def rename(self, page_id, topic, new_page_name):
        name, _ = self.choose_topic_name(topic.channel_id, new_page_name, page_id, topic.first_message_id)
        if name != topic.name:
            self.zulip.rename_topic(topic.first_message_id, name)
            logger.info("Renamed topic %r to %r (page %d)", topic.name, name, page_id)
        return topic._replace(name=name)

    def compose(self, row, sender_email):
        """Markdown content; the author's name is added if the bot posts."""
        if row.comment:
            text = markdown_itex.to_zulip_markdown(row.comment, self.nlab_url)
        else:  # only page creations get here without a comment
            text = "Page created, but author did not leave any comments."
        parts = [text]
        if sender_email is None:
            parts.append(escape_markdown(row.author))
        parts.append(", ".join(self.page_links(row)))
        return "\n\n".join(parts)

    def page_links(self, row):
        page = urllib.parse.quote_plus(row.page_name)
        base = self.nlab_url + row.web_address
        links = []
        if row.kind == "edit" and row.revision > 1:
            links.append("[diff](%s/revision/diff/%s/%d)" % (base, page, row.revision))
        links.append("[v%d](%s/revision/%s/%d)" % (row.revision, base, page, row.revision))
        links.append("[current](%s/show/%s)" % (base, page))
        return links

    def sender_email(self, author):
        """Zulip's (public) email of the one member (see Zulip.members) with the author's name, or
        None. If several members have the name, the bot posts: anyone can take any name."""
        emails = {email for email, names in self.zulip.members() if name_key(author) in map(name_key, names)}
        return emails.pop() if len(emails) == 1 else None

    def refresh_member_names(self):
        """Replaces the contents of nlab_zulip_member_names by the members' names, in one
        transaction: if Zulip cannot be reached, the old names stay."""
        names = {" ".join(name.split()) for _, member_names in self.zulip.members() for name in member_names}
        self.query("START TRANSACTION")
        try:
            self.query("DELETE FROM nlab_zulip_member_names")
            with self.database.cursor() as cursor:
                # IGNORE: the column ignores case and accents, as name_key does.
                cursor.executemany("INSERT IGNORE INTO nlab_zulip_member_names (name) VALUES (%s)", [[n] for n in sorted(names) if n])
            self.database.commit()
        except BaseException:
            self.database.rollback()
            raise

    def store(self, page_id, topic, channel_name):
        topic = topic._replace(last_message_id=topic.last_message_id or topic.first_message_id)
        store_topic(self.database, page_id, topic, topic_url(self.zulip.site, topic.channel_id, channel_name, topic.name, topic.last_message_id))


# --------------------------------------------------------------------- main

def main():
    """Sends the pending announcements; exit status 1 if some failed."""
    if len(sys.argv) > 1:
        sys.exit("zulip_announcer.py takes no arguments; see README.md")
    _setup_logging()
    # Before reading the outbox: an edit from now on creates the file again, and systemd starts
    # the next run once this one has finished.
    WAKE_FILE.unlink(missing_ok=True)
    try:
        with contextlib.closing(database_from_environment()) as database:
            announcer = Announcer(database, zulip_from_environment(), os.environ["NLAB_URL"])
            announcer.refresh_member_names()
            failures = announcer.process_pending()
    except Exception:  # e.g. Zulip or the database is down; the outbox stays as it is
        logger.exception("Cannot send the pending announcements")
        return 1
    return 1 if failures else 0


if __name__ == "__main__":
    sys.exit(main())
