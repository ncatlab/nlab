# coding: utf-8

# Announcements of nLab edits on the nForum (Zulip).
#
# On page save, the nLab only writes a row into the table nlab_zulip_outbox, and creates the file
# WAKE_FILE, upon which systemd starts the worker script/src/zulip_announcer/zulip_announcer.py.
# The worker posts the rows to Zulip and records the Zulip topic of each page in
# nlab_zulip_topics.
module ZulipAnnouncer

  ANNOUNCED_WEB_IDS = [1, 23]

  WAKE_FILE = File.join(Rails.root.to_s, "tmp", "zulip_announcer_wake")

  def self.announced?(web, page_name, author_name)
    ANNOUNCED_WEB_IDS.include?(web.id) && page_name != "Sandbox" &&
      !author_name.starts_with?("do not announce")
  end

  # Queues an announcement. kind is "create" or "edit"; old_page_name is
  # given if the edit renamed the page. Never raises: the page has already
  # been saved at this point.
  def self.enqueue(kind, web, page_id, page_name, author_name, comment, old_page_name = nil)
    execute([<<~SQL,
        INSERT INTO nlab_zulip_outbox
          (created_at, kind, web_id, web_address, page_id, page_name, old_page_name, author, comment, revision)
        SELECT UTC_TIMESTAMP(), ?, ?, ?, ?, ?, ?, ?, ?, COUNT(*)
        FROM revisions WHERE page_id = ?
      SQL
      kind, web.id, web.address, page_id, page_name, old_page_name,
      author_name, without_astral_characters(comment.to_s), page_id])
    # Without the wake file, the worker still sends the row within minutes (its timer).
    FileUtils.touch(WAKE_FILE)
  rescue StandardError => e
    ActiveRecord::Base.logger.error(
      "ZulipAnnouncer: could not queue the announcement of #{kind} of " +
      "page #{page_id} (#{page_name}) by #{author_name}: #{e}")
  end

  # Link to the page's Zulip topic, or nil if it has none yet.
  def self.discussion_url(page_id)
    ActiveRecord::Base.connection.select_value(sanitize([
      "SELECT url FROM nlab_zulip_topics WHERE page_id = ?", page_id]))
  rescue StandardError => e
    ActiveRecord::Base.logger.error("ZulipAnnouncer: #{e}")
    nil
  end

  # Link to the channel where the announcements of a web go.
  def self.channel_url(web_id)
    channel_id = ActiveRecord::Base.connection.select_value(sanitize([
      "SELECT channel_id FROM nlab_zulip_channels WHERE web_id = ?", web_id]))
    channel_id ? "#{ENV["NFORUM_URL"]}#narrow/channel/#{channel_id}" : ENV["NFORUM_URL"]
  rescue StandardError => e
    ActiveRecord::Base.logger.error("ZulipAnnouncer: #{e}")
    ENV["NFORUM_URL"]
  end

  def self.sanitize(statement_and_values)
    ActiveRecord::Base.send(:sanitize_sql_array, statement_and_values)
  end

  def self.execute(statement_and_values)
    ActiveRecord::Base.connection.execute(sanitize(statement_and_values))
  end

  # The database connection uses MySQL's 3-byte "utf8", which cannot store
  # characters outside the Basic Multilingual Plane, such as emoji.
  def self.without_astral_characters(text)
    text.gsub(/[^\u0000-\uFFFF]/, "\uFFFD")
  end

  private_class_method :sanitize, :execute, :without_astral_characters
end
