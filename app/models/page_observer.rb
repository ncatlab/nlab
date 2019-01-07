# This class maintains the state of wiki references for newly deleted pages
class PageObserver < ActiveRecord::Observer

  def before_destroy(page)
    WikiReference.delete_all ['page_id = ?', page.id]
    WikiReference.update_all("link_type = '#{WikiReference::WANTED_PAGE}'",
        ['referenced_name = ?', page.name])
  end

end
