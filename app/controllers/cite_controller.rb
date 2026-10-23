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
    bib_entry_path = File.join(
      Rails.root,
      "script/src/bib_entry/bib_entry.py")
    if unicode
      if current
        bib_entry = IO.popen([bib_entry_path.to_s, page_name.to_s, revision_number.to_s, revision_id.to_s, "--current", "--unicode_permitted"], &:read)
      else
        bib_entry = IO.popen([bib_entry_path.to_s, page_name.to_s, revision_number.to_s, revision_id.to_s, "--unicode_permitted"], &:read)
      end
    else
      if current
        bib_entry = IO.popen([bib_entry_path.to_s, page_name.to_s, revision_number.to_s, revision_id.to_s, "--current"], &:read)
      else
        bib_entry = IO.popen([bib_entry_path.to_s, page_name.to_s, revision_number.to_s, revision_id.to_s], &:read)
      end
    end
    return bib_entry
  end

  helper_method :bib_entry
end
