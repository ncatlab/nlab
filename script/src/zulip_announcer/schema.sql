-- Tables of the Zulip edit announcer (see README.md). Run once:
--
--     mysql nlab < script/src/zulip_announcer/schema.sql

-- One row per pending announcement, written by the nLab on page save (lib/zulip_announcer.rb).
-- The worker sends the rows to Zulip in id order and deletes the ones it has sent.
CREATE TABLE nlab_zulip_outbox (
  id INT NOT NULL AUTO_INCREMENT,
  created_at DATETIME NOT NULL,
  -- 'create' or 'edit'
  kind VARCHAR(10) NOT NULL,
  web_id INT NOT NULL,
  web_address VARCHAR(255) NOT NULL,
  page_id INT NOT NULL,
  -- name after the edit; old_page_name is set if the edit renamed the page
  page_name VARCHAR(255) NOT NULL,
  old_page_name VARCHAR(255) NULL,
  author VARCHAR(255) NOT NULL,
  -- the author's comment (MarkdownItex), empty for a rename without comment
  comment MEDIUMTEXT NOT NULL,
  -- number of revisions of the page after the edit
  revision INT NOT NULL,
  -- why the last attempt to send this row failed
  last_error TEXT NULL,
  PRIMARY KEY (id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- The Zulip channel that the announcements of each announced web go to. Filled by seed.py.
CREATE TABLE nlab_zulip_channels (
  web_id INT NOT NULL,
  channel_id INT NOT NULL,
  PRIMARY KEY (web_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- The Zulip topic of each announced page. Keyed by page id, so it survives page renames. The
-- topic is identified by its first message, and belongs to at most one page. `topic` and `url`
-- are refreshed whenever the worker posts, so they follow topics that moderators have renamed or
-- moved.
CREATE TABLE nlab_zulip_topics (
  page_id INT NOT NULL,
  channel_id INT NOT NULL,
  topic VARCHAR(255) NOT NULL,
  first_message_id BIGINT NOT NULL,
  last_message_id BIGINT NOT NULL,
  -- link to the topic, near the latest announcement; used by "Discuss"
  url VARCHAR(2048) NOT NULL,
  updated_at DATETIME NOT NULL,
  PRIMARY KEY (page_id),
  UNIQUE KEY index_nlab_zulip_topics_on_first_message_id (first_message_id)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

-- The names of the active Zulip users who are not bots: full names and "nLab name" profile
-- fields. Copied from Zulip on every run of the worker. The spam detector is more lenient with the
-- nLab authors listed here. The collation ignores case and accents, as the announcer does.
CREATE TABLE nlab_zulip_member_names (
  name VARCHAR(255) NOT NULL,
  PRIMARY KEY (name)
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;
