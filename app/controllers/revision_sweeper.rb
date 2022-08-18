require_dependency 'cache_sweeping_helper'

class RevisionSweeper < ActionController::Caching::Sweeper

  include CacheSweepingHelper

  observe Revision, Page

  # Also runs after creation.
  def after_save(record)
    if record.is_a?(Revision)
      revision = record
      # If the page name changed in page.revise, revision.page.name will refer to:
      # * the old name if the revision was updated using current_revision.update_attributes
      # * the new name if the revision was created using revisions.build.
      # We want to expire only the old page name here (the new one doesn't need expiring).
      # But I don't know how to do that here.
      # So we also expire the old page name in the else-branch.
      expire_cached_page(revision.web, revision.page.name)
      expire_global_recently_revised_page(revision.web)

      # Only necessary if the current revision has been updated?
      # Not necessarily at the moment, non-existing revisions may have been cached with the current page.
      expire_cached_revisions(revision.web, revision.page.name)

      expire_related_caches(revision.web, revision.page.name, nil)
    else
      page = record
      # If the page name has changed, expire the old page.
      if page.changed.include? 'name'
        name_prev = page.changes['name'][0]
        expire_cached_page(page.web, name_prev)

        # Actually, we would need to do this whenever redirects etc. are updated.
        # But we don't have a good way of tracking that.
        expire_referencing_caches(revision.web, revision.page.name)
      end
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
      expire_referencing_caches(page.web, page.name)
      expire_cached_revisions(page.web, page.name)
    end
  end

  def self.expire_page(web, page_name)
    new.expire_cached_page(web, page_name)
  end

end
