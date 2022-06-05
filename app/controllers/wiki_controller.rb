# coding: utf-8
require 'fileutils'
require 'maruku'
require 'maruku/ext/math'
require 'zip/zip'
require 'instiki_stringsupport'
require 'resolv'

class WikiController < ApplicationController

  before_filter :load_page
  caches_action :show, :published, :tex, :print, :list, :recently_revised, :file_list, :source,
	:history, :revision, :atom_with_content, :atom_with_headlines, :atom_with_changes, :if => Proc.new { |c| c.send(:do_caching?) }
  caches_action :authors, :cache_path => Proc.new { |c| c.params }
  cache_sweeper :revision_sweeper

  layout 'default', :except => [:atom_with_content, :atom_with_headlines, :atom_with_changes, :atom, :source, :tex]

  def index
    if @web_name
      redirect_home
    elsif not @wiki.setup?
      redirect_to :controller => 'admin', :action => 'create_system'
    elsif @wiki.webs.size == 1
      redirect_home @wiki.webs.values.first.address
    else
      redirect_to :action => 'web_list'
    end
  end

  # Outside a single web --------------------------------------------------------

  def authenticate
    if password_check(params['password'])
      redirect_home
    else
      flash[:info] = password_error(params['password'])
      redirect_to :action => 'login', :web => @web_name
    end
  end

  def login
    # to template
  end

  def web_list
    @webs = wiki.webs.values.sort_by { |web| web.name }
  end

  # Within a single web ---------------------------------------------------------

  def authors
    @revisions = @web.revisions.all(
      :select => "author, count(DISTINCT page_id) AS c",
      :group  => "author",
      :having => "c > 2")
    @page_names_by_author = @revisions.inject({}) { |hash, rev|
      hash[rev.author.name] = @web.get_pages_by_author(rev.author)
      hash
    }
  end

  def file_list
    sort_order = params['sort_order'] || 'file_name'
    case sort_order
      when 'file_name'
	@alt_sort_order = 'created_at'
	@alt_sort_name = 'date'
      else
	@alt_sort_order = 'file_name'
	@alt_sort_name = 'filename'
    end
    @file_list = @web.file_list(sort_order)
  end

  def feeds
    @rss_with_content_allowed = rss_with_content_allowed?
    # show the template
  end

  def list
    parse_category
    @page_names_that_are_wanted = @pages_in_category.wanted_pages
    @pages_that_are_orphaned = @pages_in_category.orphaned_pages
  end

  def recently_revised
    parse_category
    @pages_by_revision = @pages_in_category.by_revision
    @pages_by_day = Hash.new { |h, day| h[day] = [] }
    @pages_by_revision.each do |page|
      day = Date.new(page.revised_at.year, page.revised_at.month, page.revised_at.day)
      @pages_by_day[day] << page
    end
  end

  def latest_revisions
    @set_name = 'the web'
    @revisions = Revision.all(
      :conditions => {:web_id => @web.id},
      :limit => 1000,
      :order => "revised_at DESC")
    @revisions = @revisions.paginate :page => params[:page], :per_page => 100
  end

  def atom_with_content
    if rss_with_content_allowed?
      render_atom(hide_description = false)
    else
      render :text => 'Atom feed with content for this web is blocked for security reasons. ' +
	'The web is password-protected and not published', :status => 403, :layout => 'error'
    end
  end

  def atom_with_headlines
    render_atom(hide_description = true)
  end

  def atom_with_changes(limit = 15)
    if rss_with_content_allowed?
      render_atom_changes(hide_description = false)
    else
      render :text => 'Atom feed with content for this web is blocked for security reasons. ' +
	'The web is password-protected and not published', :status => 403, :layout => 'error'
    end
  end

  def tex_list
    return unless is_post
    if [:markdownMML, :markdownPNG, :markdown].include?(@web.markup)
      @tex_content = ''
      # Ruby 1.9.x has ordered hashes; 1.8.x doesn't. So let's just parse the query ourselves.
      ordered_params = ActiveSupport::OrderedHash[*request.raw_post.split('&').collect {|k_v| k_v.split('=').collect {|x| CGI::unescape(x)}}.flatten]
      ordered_params.each do |name, p|
        if p == 'tex' && @web.has_page?(name)
          @tex_content << "\\section*\{#{Maruku.new(name).to_latex.strip}\}\n\n"
          @tex_content << Maruku.new(@web.page(name).content).to_latex
        end
      end
    else
      @tex_content = 'TeX export only supported with the Markdown text filters.'
    end
    if @tex_content == ''
      flash[:error] = "You didn't select any pages to export."
      redirect_to :back
      return
    end
    expire_action :controller => 'wiki', :web => @web.address, :action => 'list', :category => params['category']
    render(:layout => 'tex')
  end

  def search
     @query = params['query'] ? params['query'].purify : ''
     @title_results = @web.select { |page| page.name =~ /#{@query}/i }.sort
     if !@title_results.empty? && @title_results.include?(@query)
       @exact_match = [@query]
     else
       @exact_match = []
     end
     @results = @web.select { |page| page.content =~ /#{@query}/i}.sort
     all_pages_found = (@results + @title_results).uniq
     if all_pages_found.size == 1
       redirect_to_page(all_pages_found.first.name)
     end
  end

  # Within a single page --------------------------------------------------------

  def cancel_edit
    @page.unlock
    redirect_to_page(@page_name)
  end

  def edit
    if @page.nil?
      redirect_home
    elsif @page.locked?(Time.now) and not params['break_lock']
      redirect_to :web => @web_name, :action => 'locked', :id => @page_name
    else
      @page.lock(Time.now, @author)
      @link_to_nforum_discussion = link_to_nforum_discussion()
      if params["failed_edit"].nil? || params["failed_edit"].to_i != 1
        @failed_edit = false
        return
      end
      @failed_edit = true
      submitted_edits_directory_path = File.join(
        ENV["NLAB_SUBMITTED_EDITS_DIRECTORY"],
        @web.address)
      page_content_file_name = @page_name.split.join("_")
      page_content_file_name = page_content_file_name.gsub("/", "¤")
      submitted_edits_page_content_file_path = File.join(
        submitted_edits_directory_path,
        page_content_file_name)
      @submitted_edit = File.read(submitted_edits_page_content_file_path)
      submitted_announcements_directory_path = File.join(
        ENV["NLAB_SUBMITTED_ANNOUNCEMENTS_DIRECTORY"],
        @web.address)
      submitted_announcement_file_path = File.join(
        submitted_announcements_directory_path,
        page_content_file_name)
      if File.file?(submitted_announcement_file_path)
        @submitted_announcement = File.read(submitted_announcement_file_path)
      else
        @submitted_announcement = ""
      end
    end
  end

  def locked
    # to template
  end

  def new
    if !params["is_reference"].nil?
      @is_reference = true
    end
    redirect_to :web => @web_name, :action => 'edit', :id => @page_name unless @page.nil?
    if params["failed_edit"].nil? || params["failed_edit"].to_i != 1
      @failed_edit = false
      return
    end
    @failed_edit = true
    submitted_edits_directory_path = File.join(
      ENV["NLAB_SUBMITTED_EDITS_DIRECTORY"],
      @web.address)
    page_content_file_name = @page_name.split.join("_").gsub("/", "¤")
    submitted_edits_page_content_file_path = File.join(
      submitted_edits_directory_path,
      page_content_file_name)
    @submitted_edit = File.read(submitted_edits_page_content_file_path)

    submitted_announcements_directory_path = File.join(
      ENV["NLAB_SUBMITTED_ANNOUNCEMENTS_DIRECTORY"],
      @web.address)
    submitted_announcement_file_path = File.join(
      submitted_announcements_directory_path,
      page_content_file_name)
    if File.file?(submitted_announcement_file_path)
      @submitted_announcement = File.read(submitted_announcement_file_path)
    else
      @submitted_announcement = ""
    end
    # to template
  end

#  def pdf
#    page = wiki.read_page(@web_name, @page_name)
#    safe_page_name = @page.name.gsub(/\W/, '')
#    file_name = "#{safe_page_name}-#{@web.address}-#{@page.revised_at.strftime('%Y-%m-%d-%H-%M-%S')}"
#    file_path = File.join(@wiki.storage_path, file_name)
#
#    export_page_to_tex("#{file_path}.tex") unless FileTest.exists?("#{file_path}.tex")
#    # NB: this is _very_ slow
#    convert_tex_to_pdf("#{file_path}.tex")
#    send_file "#{file_path}.pdf"
#  end

  def print
    if @page.nil?
      redirect_home
    else
      @link_mode ||= :show
      @renderer = PageRenderer.new(@page.current_revision)
      # to template
    end
  end

  def published
    if not @web.published?
      render(:text => "Published version of web '#{@web_name}' is not available", :status => 404, :layout => 'error')
      return
    end

    @page_name ||= 'HomePage'
    @page ||= wiki.read_page(@web_name, @page_name)
    @link_mode ||= :publish
    if @page
       page_content_directory = File.join(
         ENV["NLAB_PAGE_CONTENT_DIRECTORY"],
         web_address(@page.web_id))
       page_content_file_name = @page.name.split.join("_")
       page_content_file_name = page_content_file_name.gsub("/", "¤")
       page_content_file_path = File.join(page_content_directory, page_content_file_name)
       if File.file?(page_content_file_path)
         @rendered_content = File.read(page_content_file_path)
       else
         @renderer = PageRenderer.new(@page.current_revision)
       end

    else
      real_pages = WikiReference.pages_that_redirect_for(@web, @page_name)
      real_page = real_pages.last
      if real_page
        if real_pages.length == 1
          flash[:info] = "Redirected from \"#{@page_name}\"."
        else
          list_pages = real_pages.collect do |r|
            "<a href=\"#{url_for(:web => @web.address, :action => 'published', :id => r, :only_path => true)}\">#{r.escapeHTML}</a>"
          end
          c = list_pages.length > 2 ? 'all' : 'both'
          flash[:error] = "Redirected from \"#{@page_name}\".\nNote: #{list_pages.to_sentence} #{c} redirect for \"#{@page_name}\".".html_safe
        end
          redirect_to :web => @web_name, :action => 'published', :id => real_page, :status => 301
      else
        render :template => "/errors/404.rhmtl", :status => 404, :locals => { :error_message => "Page '#{@page_name}' not found" }
      end
     end
  end

  def revision
    if @page.nil?
      redirect_home
    else
      get_page_and_revision
      @show_diff = (params[:mode] == 'diff')
      @link_to_nforum_discussion = link_to_nforum_discussion()
      @renderer = PageRenderer.new(@revision)
    end
  end

  def rollback
    get_page_and_revision
    if @page.locked?(Time.now) and not params['break_lock']
      redirect_to :web => @web_name, :action => 'locked', :id => @page_name
    else
      @page.lock(Time.now, @author)
    end
  end

  def save
    render(:status => 404, :text => 'Undefined page name', :layout => 'error') and return if @page_name.nil?
    return unless is_post

    # Check for spam
    if !(params["see_if_human"].blank?)
      flash[:error] = "Cannot save page due to activation of spam filter"
      return
    end

    if !params["is_reference"].nil?
      bibliography_entry = params["content"].purify

      submitted_edits_directory_path = File.join(
        ENV["NLAB_SUBMITTED_EDITS_DIRECTORY"],
        @web.address)
      if !File.exist?(submitted_edits_directory_path)
        Dir.mkdir(submitted_edits_directory_path)
      end

      reference_name = @page_name.split.join("_")
      reference_file_name = reference_name.gsub("/", "¤")
      submitted_edits_reference_file_path = File.join(
        submitted_edits_directory_path,
        reference_file_name)
      File.write(submitted_edits_reference_file_path, bibliography_entry)

      save_reference_path = ENV["NLAB_SAVE_REFERENCE_PATH"]
      filter_spam(bibliography_entry)
      response, error_message, status = Open3.capture3(
        save_reference_path,
        @author.purify,
        stdin_data: bibliography_entry)
      if !status.success?
        flash[:error] = error_message
        param_hash = {
          :web => @web_name,
          :id => @page_name,
          :is_reference => 1,
          :failed_edit => 1}
        redirect_to param_hash.update( :action => 'new' )
        return
      end
      citation_key = response.strip
      redirect_to :web => @web_name, :controller => 'reference',
        :action => 'show',
        :citation_key => citation_key
      return
    end

    if @page
      @page.unlock
    end

    submitted_edits_directory_path = File.join(
      ENV["NLAB_SUBMITTED_EDITS_DIRECTORY"],
      @web.address)
    if !File.exist?(submitted_edits_directory_path)
      Dir.mkdir(submitted_edits_directory_path)
    end

    author_name = params['author'].purify.strip
    author_name = 'Anonymous' if (author_name.empty? || (author_name =~ /^\s*$/))

    begin
      the_content = params['content'].purify
      filter_spam(the_content)
      cookies['author'] = { :value => author_name.dup.as_bytes, :expires => Time.utc(2030) }
      if @page
        new_name = params['new_name'] ? params['new_name'].purify : @page_name
        new_name = new_name.split.join(" ").strip
        new_name = @page_name if new_name.empty?
        if new_name != @page_name
          submitted_edit_page_name = @page_name
        else
          submitted_edit_page_name = new_name
        end

        if new_name.include?("¤")
          raise Instiki::ValidationError.new("Cannot use the symbol ¤ in a page name")
        end

        page_content_file_name = submitted_edit_page_name.split.join("_").gsub("/", "¤")
        page_content_file_name = page_content_file_name
        submitted_edits_page_content_file_path = File.join(
          submitted_edits_directory_path,
          page_content_file_name)
        File.write(submitted_edits_page_content_file_path, the_content)

        if @page_name != "Sandbox"
          spam_detector_path = ENV["NLAB_SPAM_DETECTOR_PATH"]
          if new_name != @page_name
            response, error_message, status = Open3.capture3(
              spam_detector_path,
              @page.id.to_s,
              author_name,
              "-t",
              new_name,
              stdin_data: the_content)
          else
            response, error_message, status = Open3.capture3(
              spam_detector_path,
              @page.id.to_s,
              author_name,
              stdin_data: the_content)
          end

          if !status.success?
            raise Instiki::ValidationError.new(error_message)
          elsif response.strip == "Blocked"
            raise Instiki::ValidationError.new(
              "Edit blocked by spam detector. This can happen if you've substantially rewritten a page. Decompose your edit into smaller pieces to placate the spam detector.")
          end
        end

        raise Instiki::ValidationError.new('A page named "' + new_name.escapeHTML + '" already exists.') if
            @page_name != new_name && @web.has_page?(new_name)
        announcement = params[:announcement]
        if !announcement.nil?
            make_announcement = announcement.purify.present?
        else
            make_announcement = false
        end

        submitted_announcements_directory_path = File.join(
          ENV["NLAB_SUBMITTED_ANNOUNCEMENTS_DIRECTORY"],
          @web.address)

        if !File.exist?(submitted_announcements_directory_path)
          Dir.mkdir(submitted_announcements_directory_path)
        end
        submitted_announcement_file_path = File.join(
          submitted_announcements_directory_path,
          page_content_file_name)
        if make_announcement
          File.write(submitted_announcement_file_path, announcement)
        else
          File.write(submitted_announcement_file_path, "")
        end

        if (@web.name == "nLab") && (@page_name != "Sandbox") &&
            (new_name != @page_name) && !make_announcement
          raise Instiki::ValidationError.new(
            "A change of page name must be indicated on the nForum")
        end

        begin
          wiki.revise_page(
            @web_name,
            @page_name,
            new_name,
            the_content,
            Time.now,
            Author.new(author_name, remote_ip),
            PageRenderer.new)
        rescue StandardError => e
          raise Instiki::ValidationError.new(e.to_s)
        end

        old_name = @page_name
        @page_name = new_name

        if old_name != @page_name
          require "fileutils"
          old_page_content_file_name = @page_name.split.join("_").gsub("/", "¤")
          [submitted_edits_directory_path, submitted_announcements_directory_path].each do |dir|
            FileUtils.safe_unlink(File.join(dir, old_page_content_file_name))
          end
        end

        if ([1, 23].include?(@web.id)) && (@page_name != "Sandbox")
          announcement = params[:announcement]
          if !announcement.nil?
            announcement = announcement.purify
          end
          make_announcement = announcement.present?
          generate_nforum_post_from_nlab_edit_path = File.join(
            Rails.root,
            "script/src/generate_nforum_post_from_nlab_edit/generate_nforum_post_from_nlab_edit.py")
          if @web.id == 39
            web_name = "HoTT"
          elsif @web.id == 23
            web_name = "CatLab"
          else
            web_name = @web.name
          end
          cmdline = [
            generate_nforum_post_from_nlab_edit_path,
            "edit",
            new_name,
            web_name,
            @web.id.to_s,
            make_announcement ? announcement : "",
            author_name,
            @page.id.to_s,
          ]
          if not make_announcement
            cmdline.push("--is_trivial")
          end
          if old_name != new_name
            cmdline.push("--old_page_name", old_name)
          end
          system(*cmdline)
        end
      else
        @page_name = @page_name.split.join(" ").strip
        page_content_file_name = @page_name.split.join("_").gsub("/", "¤")
        submitted_edits_page_content_file_path = File.join(
          submitted_edits_directory_path,
          page_content_file_name)
        File.write(submitted_edits_page_content_file_path, the_content)

        if [1, 23].include?(@web.id)
          submitted_announcements_directory_path = File.join(
            ENV["NLAB_SUBMITTED_ANNOUNCEMENTS_DIRECTORY"],
            @web.address)
          if !File.exist?(submitted_announcements_directory_path)
            Dir.mkdir(submitted_announcements_directory_path)
          end
          submitted_announcement_file_path = File.join(
            submitted_announcements_directory_path,
            page_content_file_name)
          announcement = params[:announcement].purify
          if announcement
            File.write(submitted_announcement_file_path, announcement)
          else
            File.write(submitted_announcement_file_path, "")
          end
        end

        if @page_name.include?("¤")
          raise Instiki::ValidationError.new(
            "Cannot use the symbol ¤ in a page name")
        end
        if the_content.blank?
          raise Instiki::ValidationError.new(
            "Some content must be added to a page before it can be created")
        end

        wiki.write_page(@web_name, @page_name, the_content, Time.now,
            Author.new(author_name, remote_ip), PageRenderer.new)

        if [1, 23].include?(@web.id)
          announcement = params[:announcement].purify
          generate_nforum_post_from_nlab_edit_path = File.join(
            Rails.root,
            "script/src/generate_nforum_post_from_nlab_edit/generate_nforum_post_from_nlab_edit.py")
          if @web.id == 39
            web_name = "HoTT"
          elsif @web.id == 23
            web_name = "CatLab"
          else
            web_name = @web.name
          end
          system(
            generate_nforum_post_from_nlab_edit_path,
            "create",
            @page_name,
            web_name,
            @web.id.to_s,
            announcement,
            author_name)
          #   "--ip_address",
          #   remote_ip
          # )
        end
      end
      redirect_to_page @page_name
    rescue Instiki::ValidationError => e
      flash[:error] = e.to_s
      logger.error e
      param_hash = {:web => @web_name, :id => @page_name, :failed_edit => 1}
      if @page
        @page.unlock
        redirect_to param_hash.update( :action => 'edit' )
      else
        redirect_to param_hash.update( :action => 'new' )
      end
    end
  end

  def show
    if @page
      begin
        @is_author = nlab_author?()
        @link_to_nforum_discussion = link_to_nforum_discussion()
        @show_diff = (params[:mode] == 'diff')
        if @show_diff
          @renderer = PageRenderer.new(@page.current_revision)
        else
          page_content_directory = File.join(
            ENV["NLAB_PAGE_CONTENT_DIRECTORY"],
            web_address(@page.web_id))
          page_content_file_name = @page.name.split.join("_")
          page_content_file_name = page_content_file_name.gsub("/", "¤")
          page_content_file_path = File.join(page_content_directory, page_content_file_name)
          if File.file?(page_content_file_path)
            @rendered_content = File.read(page_content_file_path)
          else
            renderer = PageRenderer.new(@page.current_revision)
            @rendered_content = renderer.display_content
          end
        end
        render :action => 'page'
      # TODO this rescue should differentiate between errors due to rendering and errors in
      # the application itself (for application errors, it's better not to rescue the error at all)
      rescue => e
        logger.error e
        flash[:error] = e.to_s
        if in_a_web?
          redirect_to :action => 'edit', :web => @web_name, :id => @page_name
        else
          raise e
        end
      end
    else
      if not @page_name.nil? and not @page_name.empty?
        real_pages = WikiReference.pages_that_redirect_for(@web, @page_name)
        real_page = real_pages.last
        if real_page
          if real_pages.length == 1
            flash[:info] = "Redirected from \"#{@page_name}\"."
          else
            list_pages = real_pages.collect do |r|
              "<a href=\"#{url_for(:web => @web.address, :action => 'show', :id => r, :only_path => true)}\">#{r.escapeHTML}</a>"
            end
            c = list_pages.length > 2 ? 'all' : 'both'
            flash[:error] = "Redirected from \"#{@page_name}\".\nNote: #{list_pages.to_sentence} #{c} redirect for \"#{@page_name}\".".html_safe
          end
          redirect_to :web => @web_name, :action => 'show', :id => real_page, :status => 301
        else
          # try converting @page_name to ascii and see if that exists
          page_name_tr = @page_name.tr(
            "ÀÁÂÃÄÅàáâãäåĀāĂăĄąÇçĆćĈĉĊċČčÐðĎďĐđÈÉÊËèéêëĒēĔĕĖėĘęĚěĜĝĞğĠġĢ‌​ģĤĥĦħÌÍÎÏìíîïĨĩĪīĬĭĮ‌​įİıĴĵĶķĸĹĺĻļĽľĿŀŁłÑñ‌​ŃńŅņŇňŉŊŋÒÓÔÕÖØòóôõö‌​øŌōŎŏŐőŔŕŖŗŘřŚśŜŝŞşŠ‌​šȘșſŢţŤťŦŧȚțÙÚÛÜùúûü‌​ŨũŪūŬŭŮůŰűŲųŴŵÝýÿŶŷŸ‌​ŹźŻżŽž",
            "AAAAAAaaaaaaAaAaAaCcCcCcCcCcDdDdDdEEEEeeeeEeEeEeEeEeGgGgGgG‌​gHhHhIIIIiiiiIiIiIiI‌​iIiJjKkkLlLlLlLlLlNn‌​NnNnNnnNnOOOOOOooooo‌​oOoOoOoRrRrRrSsSsSsS‌​sSssTtTtTtTtUUUUuuuu‌​UuUuUuUuUuUuWwYyyYyY‌​ZzZzZz")
          page_ = @wiki.read_page(@web_name, page_name_tr) if page_name_tr
          if page_
            flash[:info] = "Redirected from \"#{@page_name}\"."
            redirect_to :web => @web_name, :action => 'show', :id => page_, :status => 301
          else
            @error_message = "No page with name: '" + @page_name + "'"
            render :template => "/errors/404.rhtml", :status => 404, :locals => { :error_message => @error_message}
          end
        end
      else
        render :template => "/errors/404.rhtml", :status => 404, :locals => { :error_message => "Page name not specified" }
      end
    end
  end

  def show_by_id
    web = Web.find_by_address(@web_name)
    if web.nil?
      ApplicationController.logger.debug "Web '#{web_address}' not found"
      return nil
    else
      page_id = params['id'].purify
      page = web.pages.first(:conditions => ['id = ?', page_id])
      ApplicationController.logger.debug "Page with ID '#{page_id}' #{page.nil? ? 'not' : ''} found"
      redirect_to :web => @web_name, :action => 'show', :id => page, :status => 301
    end
  end

  def history
    if @page
      @link_to_nforum_discussion = link_to_nforum_discussion()
      @revisions_by_day = Hash.new { |h, day| h[day] = [] }
      @revision_numbers = Hash.new { |h, id| h[id] = [] }
      revision_number = @page.rev_ids.size
      @page.rev_ids.reverse.each do |rev|
        day = Date.new(rev.revised_at.year, rev.revised_at.month, rev.revised_at.day)
        @revisions_by_day[day] << rev
        @revision_numbers[rev.id] = revision_number
        revision_number = revision_number - 1
      end
      render :action => 'history'
    else
      if not @page_name.nil? and not @page_name.empty?
        redirect_to :web => @web_name, :action => 'new', :id => @page_name
      else
        render :text => 'Page name is not specified', :status => 404, :layout => 'error'
      end
    end
  end

  def source
    if @page.nil?
      redirect_home
    else
      @revision = @page.revisions[params['rev'].to_i - 1] if params['rev']
    end
  end

  def tex
    if [:markdownMML, :markdownPNG, :markdown].include?(@web.markup)
      @tex_content = Maruku.new(@page.content).to_latex
    else
      @tex_content = 'TeX export only supported with the Markdown text filters.'
    end
    render(:layout => 'tex')
  end

  def image_path(s)
    @template.image_path(s)
  end

  protected

  def do_caching?
    flash.empty?
  end

  def load_page
    @page_name = params['id'] ? params['id'].purify : nil
    @page = @wiki.read_page(@web_name, @page_name) if @page_name
  end

  private

#  def convert_tex_to_pdf(tex_path)
#    # TODO remove earlier PDF files with the same prefix
#    # TODO handle gracefully situation where pdflatex is not available
#    begin
#      wd = Dir.getwd
#      Dir.chdir(File.dirname(tex_path))
#      logger.info `pdflatex --interaction=nonstopmode #{File.basename(tex_path)}`
#    ensure
#      Dir.chdir(wd)
#    end
#  end

  def export_page_to_tex(file_path)
    if @web.markup == :markdownMML || @web.markup == :markdownPNG
      @tex_content = Maruku.new(@page.content).to_latex
    else
      @tex_content = 'TeX export only supported with the Markdown text filters.'
    end
    File.open(file_path, 'w') { |f| f.write(render_to_string(:template => 'wiki/tex', :layout => 'tex')) }
  end

  def export_pages_as_zip(file_type, &block)
    file_prefix = "#{@web.address}-#{file_type}-"
    timestamp = @web.revised_at.strftime('%Y-%m-%d-%H-%M-%S')
    file_path = @wiki.storage_path.join(file_prefix + timestamp + '.zip')
    tmp_path = "#{file_path}.tmp"

    Zip::ZipFile.open(tmp_path, Zip::ZipFile::CREATE) do |zip_out|
      @web.select.by_name.each do |page|
        zip_out.get_output_stream("#{CGI.escape(page.name)}.#{file_type}") do |f|
          f.puts(block.call(page))
        end
      end
      # add an index file, and the stylesheet and javascript directories, if exporting to HTML
      if file_type.to_s.downcase == html_ext
        zip_out.get_output_stream("index.#{html_ext}") do |f|
          f.puts "<html xmlns='http://www.w3.org/1999/xhtml'><head>" +
            "<meta http-equiv=\"Refresh\" content=\"0;URL=HomePage.#{html_ext}\" /></head></html>"
        end
        dir = Rails.root.join('public')
        Dir["#{dir}/{images,javascripts,stylesheets}/**/*"].each do |f|
          zip_out.add "public#{f.sub(dir.to_s,'')}", f
        end
      end
      files = @web.files_path
      Dir["#{files}/**/*"].each do |f|
        zip_out.add "files#{f.sub(files.to_s,'')}", f
      end
    end
    FileUtils.rm_rf(Dir[@wiki.storage_path.join(file_prefix + '*.zip').to_s])
    FileUtils.mv(tmp_path, file_path)
    send_file file_path
  end

#  def export_web_to_tex(file_path)
#    if @web.markup == :markdownMML
#      @tex_content = Maruku.new(@page.content).to_latex
#    else
#      @tex_content = 'TeX export only supported with the Markdown text filters.'
#    end
#    @tex_content = table_of_contents(@web.page('HomePage').content, render_tex_web)
#    File.open(file_path, 'w') { |f| f.write(render_to_string(:template => 'wiki/tex_web', :layout => tex)) }
#  end

  def get_page_and_revision
    rev = params['rev'].to_i if params['rev']
    prs = @page.rev_ids.size
    if rev && rev > 0 && rev <= prs
      @revision_number = rev
    else
      @revision_number = prs
    end
    @revision = @page.revisions[@revision_number - 1]
  end

  def parse_category
    @categories = WikiReference.list_categories(@web).sort
    @category = params['category']
    if @category
      @set_name = "category '#{@category}'"
      pages = WikiReference.pages_in_category(@web, @category).sort.map { |page_name| @web.page(page_name) }
      @pages_in_category = PageSet.new(@web, pages)
    else
      # no category specified, return all pages of the web
      @pages_in_category = @web.select_all.by_name
      @set_name = 'the web'
    end
  end

  def render_atom(hide_description = false, limit = 15)
    @pages_by_revision = @web.select.by_revision.first(limit)
    @hide_description = hide_description
    @link_action = @web.password ? 'published' : 'show'
    render :action => 'atom'
  end

  def render_atom_changes(hide_description = false, limit = 15)
    @revisions = @web.revisions_by_date.last(limit).reverse
    @hide_description = hide_description
    @link_action = @web.password ? 'published' : 'show'
    render :action => 'atom_changes'
  end

  def render_tex_web
    @web.select.by_name.inject({}) do |tex_web, page|
      if  @web.markup == :markdownMML || @web.markup == :markdownPNG
        tex_web[page.name] = Maruku.new(page.content).to_latex
      else
        tex_web[page.name] = 'TeX export only supported with the Markdown text filters.'
      end
      tex_web
    end
  end

  def rss_with_content_allowed?
    @web.password.nil? or @web.published?
  end

  def filter_spam(content)
    @@spam_patterns ||= load_spam_patterns
    @@spam_patterns.each do |pattern|
      raise Instiki::ValidationError.new("Your edit was blocked by spam filtering") if content =~ pattern
    end
  end

  def load_spam_patterns
    spam_patterns_file = Rails.root.join('config', 'spam_patterns.txt')
    if File.exists?(spam_patterns_file)
      spam_patterns_file.readlines.inject([]) { |patterns, line| patterns << Regexp.new(line.chomp, Regexp::IGNORECASE) }
    else
      []
    end
  end

  def link_to_nforum_discussion()
    if @page == nil
      return
    end
    detect_nforum_discussion_path = File.join(
      Rails.root,
      "script/src/detect_nforum_discussion/detect_nforum_discussion.py")
    link = %x(
      "#{detect_nforum_discussion_path}" "#{@page.name}")
    link.strip! unless link.nil?
    if !(link.nil?) && !(link == "")
      return link
    end
  end

  def nlab_author?()
    author_contributions_path = File.join(
      Rails.root,
      "script/src/author_contributions/author_contributions.py")
    is_nlab_author = %x(
      "#{author_contributions_path}" is_author "#{@page.name}")
    is_nlab_author.strip! == "True" unless is_nlab_author.nil?
  end

  def web_address(web_id)
    return Web.find(web_id).address
  end
end
