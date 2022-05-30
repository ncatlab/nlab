require_dependency 'cache_sweeping_helper'

class WebSweeper < ActionController::Caching::Sweeper

  include CacheSweepingHelper

  observe Web, Page, WikiFile
  
  def after_save(record)
    if record.is_a?(Web)
      web = record
      web.pages.find_each { |page| expire_cached_page(web, page.name) }
      expire_cached_summary_pages(web)
    elsif record.is_a?(WikiFile)
      wiki_file = record
      wiki_file.web.pages_that_link_to_file(wiki_file.file_name).each do |page|
        expire_cached_page(wiki_file.web, page)
      end
      expire_cached_summary_pages(wiki_file.web)
    end
  end

  def after_destroy(record)
    if record.is_a?(Web)
      web = record
      expire_cached_summary_pages(web)
    elif record.is_a?(WikiFile)
      wiki_file = record
      expire_cached_summary_pages(wiki_file.web)
    end
  end

end
