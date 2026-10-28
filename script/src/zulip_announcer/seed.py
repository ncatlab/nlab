#!/usr/bin/env python3

"""
Fills the tables nlab_zulip_channels and nlab_zulip_topics of the Zulip announcer from the old
nForum's tables, once, right after the nForum has been imported into Zulip. See README.md.
"""

import argparse
import contextlib
import json

from zulip_announcer import Topic, database_from_environment, query, query_one, store_topic, topic_url

# The nForum categories whose discussions became the announcement topics.
WEBS = {1: "nLab", 23: "CatLab"}
DEFAULT_CATEGORY_ID = 5


def seed(database, ids, replace=False):
    """Fill nlab_zulip_channels and nlab_zulip_topics. ids is the nforum_ids.json written by the
    converter's post_import.py. All in one transaction, which is committed at the end: if this
    fails, closing the connection rolls it back."""
    database.autocommit(False)
    for table in ("nlab_zulip_channels", "nlab_zulip_topics"):
        if query(database, "SELECT 1 FROM " + table + " LIMIT 1"):
            if not replace:
                raise SystemExit(table + " is not empty; use --replace")
            query(database, "DELETE FROM " + table)

    # Channels: the ones that the webs' "Latest Changes" categories became.
    category_of_web = {}
    for web_id, web_name in WEBS.items():
        row = query_one(database, "SELECT CategoryID FROM mathforge_nforum_Category WHERE Name = %s", ["- " + web_name + ": Latest Changes"])
        category_of_web[web_id] = row["CategoryID"] if row else DEFAULT_CATEGORY_ID
        query(database, "INSERT INTO nlab_zulip_channels (web_id, channel_id) VALUES (%s, %s)", [web_id, ids["categories"][str(category_of_web[web_id])]])

    # Topics: for each page, the most recently active discussion with exactly the page's name in
    # its web's "Latest Changes" category, as the old detect_nforum_discussion.py and the
    # announcer chose it.
    discussion_of = {}
    for category_id in set(category_of_web.values()):
        for d in query(database, "SELECT DiscussionID, Name FROM mathforge_nforum_Discussion WHERE CategoryID = %s ORDER BY DateLastActive, DiscussionID", [category_id]):
            if str(d["DiscussionID"]) in ids["discussions"]:
                discussion_of[(category_id, d["Name"])] = str(d["DiscussionID"])

    last_message = {}
    for key, message_id in ids["comments"].items():
        discussion_id = key.split("/")[1]
        last_message[discussion_id] = max(message_id, last_message.get(discussion_id, 0))

    topics = 0
    for web_id in WEBS:
        for page in query(database, "SELECT id, name FROM pages WHERE web_id = %s", [web_id]):
            discussion_id = discussion_of.get((category_of_web[web_id], page["name"]))
            if discussion_id is None:
                continue
            d = ids["discussions"][discussion_id]
            topic = Topic(d["channel_id"], d["topic"], d["first_message_id"], last_message[discussion_id])
            store_topic(database, page["id"], topic, topic_url(ids["realm_url"], topic.channel_id, d["channel"], topic.name, topic.last_message_id))
            topics += 1

    database.commit()
    print("seeded %d channels and %d page topics" % (len(WEBS), topics))


def main():
    parser = argparse.ArgumentParser(description="Fill the Zulip announcer's channel and topic tables after the import")
    parser.add_argument("--ids", required=True, help="nforum_ids.json written by post_import.py")
    parser.add_argument("--replace", action="store_true", help="Replace existing rows")
    arguments = parser.parse_args()
    with open(arguments.ids) as f:
        ids = json.load(f)
    with contextlib.closing(database_from_environment()) as database:
        seed(database, ids, arguments.replace)


if __name__ == "__main__":
    main()
