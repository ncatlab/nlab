require_dependency 'cache_sweeping_helper'

class RevisionSweeper < ActionController::Caching::Sweeper

  include CacheSweepingHelper

  observe Revision, Page

  def before_save(record)
    if record.is_a?(Page)
      expire_cached_page(record.web, record.name)
      expire_cached_revisions(record.web, record.name)
      expire_caches(record.web, record.name)
    end
  end

  def after_save(record)
    if record.is_a?(Page) && record.web.id != '1'
      expire_caches(record.web, record.name)
    end
  end

  def after_create(record)
    if record.is_a?(Page) && record.web.id != '1'
       WikiReference.pages_that_reference(record.web, record.name).each do |page_name|
         expire_cached_page(record.web, page_name)
      end
    end
  end

  def after_delete(record)
    if record.is_a?(Page)
      expire_caches(record.web, record.name)
    end
  end

  def self.expire_page(web, page_name)
    new.expire_cached_page(web, page_name)
  end

  private

  def expire_caches(web, page_name)
    expire_cached_summary_pages(web)
    pages_to_expire = ([page_name] +
       WikiReference.pages_redirected_to(web, page_name) +
       WikiReference.pages_that_include(web, page_name)).uniq
    pages_to_expire.each { |page_name_2| expire_cached_page(web, page_name_2) }
  end

end
