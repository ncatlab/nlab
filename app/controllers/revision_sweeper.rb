require_dependency 'cache_sweeping_helper'

class RevisionSweeper < ActionController::Caching::Sweeper

  include CacheSweepingHelper

  observe Revision, Page

  # Also runs after creation.
  def after_save(record)
    if record.is_a?(Revision)
      revision = record
      expire_cached_page(revision.web, revision.page.name)
      expire_global_recently_revised_page(revision.web)
      # Only necessary if the current revision has been updated.
      expire_cached_revisions(revision.web, revision.page.name)
    end
  end

  def after_create(record)
    if record.is_a?(Page)
      page = record
      expire_cached_summary_pages(page.web)
      expire_related_caches(page.web, page.name, page)
      expire_referencing_caches(page.web, page.name)
    end
  end

  def after_delete(record)
    if record.is_a?(Page)
      page = record
      expire_cached_page(page.web, page.name)
      expire_cached_summary_pages(page.web)
      expire_related_caches(page.web, page.name, page)
      expire_cached_revisions(page.web, page.name)
    end
  end

  def self.expire_page(web, page_name)
    new.expire_cached_page(web, page_name)
  end

end
