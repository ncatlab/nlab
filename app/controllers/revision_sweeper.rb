require_dependency 'cache_sweeping_helper'

class RevisionSweeper < ActionController::Caching::Sweeper

  include CacheSweepingHelper

  observe Revision, Page

  # Also run after creation.
  def after_save(record)
    if record.is_a?(Page)
      expire_cached_page(record.web, record.name)
      expire_cached_revisions(record.web, record.name)
      expire_related_caches(record.web, record.name, record)
    end
  end

  def after_create(record)
    if record.is_a?(Page)
      expire_referencing_caches(record.web, record.name)
    end
  end

  def after_delete(record)
    if record.is_a?(Page)
      expire_cached_page(record.web, record.name)
      expire_cached_summary_pages(record.web)
      expire_related_caches(record.web, record.name, record)
      expire_cached_revisions(record.web, record.name)
    end
  end

end
