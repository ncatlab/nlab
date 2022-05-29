module CacheSweepingHelper

  def expire_cached_summary_pages(web)
    categories = WikiReference.list_categories(web)
    list_of_actions = %w(list recently_revised)
    if web.address == 'nlab'
      list_of_actions.delete('recently_revised')
    end
    list_of_actions.each do |action|
      expire_action :controller => 'wiki', :web => web.address, :action => action
      categories.each do |category|
        expire_action :controller => 'wiki', :web => web.address, :action => action, :category => category
      end
    end

    %w(authors atom_with_content atom_with_headlines atom_with_changes file_list).each do |action|
      expire_action :controller => 'wiki', :web => web.address, :action => action
    end

    %w(file_name created_at).each do |sort_order|
      expire_action :controller => 'wiki', :web => web.address, :action => 'file_list', :sort_order => sort_order
    end
  end

  # This method does not seem to be used.
  # Note that its functionality is included in expire_cached_summary_pages for non-nlab webs.
  def expire_recently_revised_page(web)
    categories = WikiReference.list_categories(web)
    expire_action :controller => 'wiki', :web => web.address, :action => 'recently_revised'
    categories.each do |category|
      expire_action :controller => 'wiki', :web => web.address, :action => 'recently_revised', :category => category
    end
  end

  def expire_cached_page(web, page_name)
    expire_action :controller => 'wiki', :web => web.address,
        :action => %w(show published tex print history source), :id => page_name
    expire_action :controller => 'wiki', :web => web.address,
        :action => 'show', :id => page_name, :mode => 'diff'
  end

  def expire_cached_revisions(web, page_name)
    # Hack to expire all revisions, even the ones created for non-existing revision numbers.
    # Saves time over manually expiring each revision, in particular for pages with thousands of revision (e.g. Sandbox).
    [ File.join('revision'),
      File.join('revision', 'diff'),
      File.join('source')
    ].each do |rel_path|
      base_path = File.join(
        Rails.configuration.cache_store[1],
        'views',
        web.address,
        rel_path,
      )
      # Rudimentary protection against file path manipulation attacks:
      # only take the prefix up until the first slash (Unix only).
      file_name = page_name.split('/', 2).first
      path = File.join(base_path, file_name)
      FileUtils.rm_rf(path)
    end
  end

  def expire_related_caches(web, page_name)
    expire_cached_summary_pages(web)
    pages_to_expire = (
       WikiReference.pages_redirected_to(web, page_name, nil) +
       WikiReference.pages_that_include(web, page_name)
    ).uniq
    pages_to_expire.each { |page_name_2| expire_cached_page(web, page_name_2) }
  end

  def expire_referencing_caches(web, page_name)
    WikiReference.pages_that_reference(web, page_name).each do |page_name_2|
      expire_cached_page(web, page_name_2)
    end
  end


end
