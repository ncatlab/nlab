class CiteController < ApplicationController
  layout "default", :except => []

  def cite_current
    page_name = params["page_name"]
    if !@web.has_page?(page_name)
      render(
        :status => 404,
        :text => "#{page_name} is not the name of any nLab page",
        :layout => "/errors/404.rhtml")
      return
    end
    @page_name = page_name
    page = @wiki.read_page(@web_name, @page_name)
    @revision_number = page.rev_ids.size
    @revision_id = page.revisions[@revision_number - 1].id
    return
  end

  def cite
    page_name = params["page_name"]
    if !@web.has_page?(page_name)
      render(
        :status => 404,
        :text => "#{page_name} is not the name of any nLab page",
        :layout => "/errors/404.rhtml")
      return
    end
    @page_name = page_name
    @revision_number = params["revision_number"]
    page = @wiki.read_page(@web_name, @page_name)
    @revision_id = page.revisions[Integer(@revision_number) - 1].id
    return
  end

  def bib_entry(page_name, revision_number, revision_id, current, unicode)
    bib_entry_binary = File.join(
      Rails.root,
      "script/bib_entry")
    if unicode
      if current
        bib_entry = %x(
          "#{bib_entry_binary}" "#{page_name}" "#{revision_number}" "#{revision_id}" --current --unicode_permitted)
      else
        bib_entry = %x(
          "#{bib_entry_binary}" "#{page_name}" "#{revision_number}" "#{revision_id}" --unicode_permitted)
      end
    else
      if current
        bib_entry = %x(
          "#{bib_entry_binary}" "#{page_name}" "#{revision_number}" "#{revision_id}" --current)
      else
        bib_entry = %x(
          "#{bib_entry_binary}" "#{page_name}" "#{revision_number}" "#{revision_id}")
      end
    end
    return bib_entry
  end

  helper_method :bib_entry

  def link_to_nlab_page(page_name)
    "https://ncatlab.org/" + @web_name + "/show/" + URI.encode(page_name)
  end

  helper_method :link_to_nlab_page
end
