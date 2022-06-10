require "open3"

class Page < ActiveRecord::Base
  belongs_to :web
  has_many :revisions, :order => 'id', :dependent => :destroy
  #In many cases, we don't need to instantiate the full revisions (with all that textual data)
  has_many :rev_ids, :order => 'id', :class_name => 'Revision', :select => 'id, revised_at, page_id, author, ip'
  has_many :wiki_references, :order => 'referenced_name'
  has_one :current_revision, :class_name => 'Revision', :order => 'id DESC'

  def name
    read_attribute(:name).as_utf8
  end

  def revise(content, name, time, author, is_create = false)
    revisions_size = new_record? ? 0 : rev_ids.size
    if (revisions_size > 0) and content == current_revision.content and name == self.name
      raise Instiki::ValidationError.new(
          "You have tried to save page '#{name}' without changing its content")
    end

    if web.id == 1 and author.name == 'Anonymous' and author.ip == '73.168.5.183'
      raise Instiki::ValidationError.new(
          "Hello anonymous editor. Please respond to https://nforum.ncatlab.org/discussion/14612/flood-of-unresponsive-anonymous-edits/?Focus=99880#Comment_99880 before making any further edits!")
    end

    self.name = name
    author = Author.new(author.to_s) unless author.is_a?(Author)

    revision = Revision.new(
       :page => self, :content => content, :author => author, :revised_at => time)

    renderer_path = ENV["NLAB_PAGE_RENDERER_PATH"]

    # Check that the actual page can be rendererd
    response, error_message, status = Open3.capture3(
      renderer_path,
      self.id.to_s,
      "-o",
      "-c",
      stdin_data: revision.content)

    if !status.success?
      raise Instiki::ValidationError.new(error_message)
    end

    # A user may change a page, look at it and make some more changes - several times.
    # Not to record every such iteration as a new revision, if the previous revision was done
    # by the same author, not more than 30 minutes ago, then update the last revision instead of
    # creating a new one
    if (revisions_size > 0) && continous_revision?(time, author)
      current_revision.update_attributes(:content => content, :revised_at => time)
    else
      revisions.build(:content => content, :author => author, :revised_at => time)
    end
    save

    # Asynchronously render all pages affected by the rendering of the current
    # page
    Open3.popen2e(
      renderer_path,
      self.id.to_s,
      "-c") do | stdin, stdout_and_stderr, wait_thread |
      stdin.puts(revision.content)
      stdin.close
      stdout_and_stderr.close
    end

    self
  end

  def rollback(revision_number, time, author_ip)
    roll_back_revision = self.revisions[revision_number]
    if roll_back_revision.nil?
      raise Instiki::ValidationError.new("Revision #{revision_number} not found")
    end
    author = Author.new(roll_back_revision.author.name, author_ip)
    revise(roll_back_revision.content, self.name, time, author)
  end

  def revisions?
    rev_ids.size > 1
  end

  def previous_revision(revision)
    revision_index = rev_ids.each_with_index do |rev, index|
      if rev.id == revision.id
        break index
      else
        nil
      end
    end
    if revision_index.nil? or revision_index == 0
      nil
    else
      revisions[revision_index - 1]
    end
  end

  def references
    web.select.pages_that_reference(name)
  end

  def wiki_words
    wiki_references.select { |ref| ref.wiki_word? }.map { |ref| ref.referenced_name }
  end

  def categories
    wiki_references.select { |ref| ref.category? }.map { |ref| ref.referenced_name }
  end

  def linked_from
    Array.new # disable for now
    # web.select.pages_that_link_to(name)
  end

  def redirects
    wiki_references.select { |ref| ref.redirected_page? }.map { |ref| ref.referenced_name }
  end

  def included_from
    Array.new # disable for now
    # web.select.pages_that_include(name)
  end

  # Returns the original wiki-word name as separate words, so "MyPage" becomes "My Page".
  def plain_name
    web.brackets_only? ? name.escapeHTML.html_safe : WikiWords.separate(name).escapeHTML.html_safe
  end

  LOCKING_PERIOD = 30.minutes

  def lock(time, locked_by)
    update_attributes(:locked_at => time, :locked_by => locked_by)
  end

  def lock_duration(time)
    ((time - locked_at) / 60).to_i unless locked_at.nil?
  end

  def unlock
    update_attribute(:locked_at, nil)
  end

  def locked?(comparison_time)
    locked_at + LOCKING_PERIOD > comparison_time unless locked_at.nil?
  end

  def to_param
    name.as_utf8
  end

  class RenderingError < StandardError
  end

  private

  # This method appears not to be unused.
  def expire_cache(web_address, page_name)
    require "fileutils"
    cache_directory = File.join(
      ENV["NLAB_CACHE_DIRECTORY"],
      web_address,
      "show")
    cached_content_path = File.join(
      cache_directory,
      "\"" + CGI.escape(page_name) + ".cache" + "\"")
    FileUtils.safe_unlink(cached_content_path)
  end

  def continous_revision?(time, author)
    (current_revision.author == author) && (revised_at + 30.minutes > time)
  end

  # Forward method calls to the current revision, so the page responds to all revision calls
  def method_missing(method_id, *args, &block)
    method_name = method_id.to_s
    # Perform a hand-off to AR::Base#method_missing
    if @attributes.include?(method_name) or md = /(=|\?|_before_type_cast)$/.match(method_name)
      super(method_id, *args, &block)
    else
      current_revision.send(method_id)
    end
  end
end
