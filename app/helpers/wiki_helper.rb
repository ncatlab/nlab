module WikiHelper

  def navigation_menu_for_revision
    menu = []
    menu << forward
    menu << back_for_revision if @revision_number > 1
    menu << current_revision
    menu << see_or_hide_changes_for_revision if @revision_number > 1
    menu << history if @page.rev_ids.size > 1
    menu << rollback
    menu
  end

  def navigation_menu_for_page
    menu = []
    menu << edit_page
    menu << edit_web if @page.name == "HomePage"
    menu << nforum_discussion
    if @page.rev_ids.size > 1
      menu << back_for_page
      menu << see_or_hide_changes_for_page
    end
    menu << history if @page.rev_ids.size > 1
    menu
  end

  def edit_page
    link_text = (@page.name == "HomePage" ? 'Edit Page' : 'Edit')
    link_to(link_text, {:web => @web.address, :action => 'edit', :id => @page.name},
        {:class => 'navlink', :accesskey => 'E', :id => 'edit', :rel => 'nofollow'})
  end

  def edit_web
    link_to('Edit Web', {:web => @web.address, :action => 'edit_web'},
        {:class => 'navlink', :accesskey => 'W', :id => 'edit_web', :rel => 'nofollow'})
  end

  def nforum_discussion
    generic_nforum_link = "<a href=\"https://nforum.ncatlab.org/discussions/?CategoryID=0\">Discuss</a>"
    if !(([1, 23, 39].include?(@web.id)) && (@page != nil) && (@page.name != "Sandbox"))
      return generic_nforum_link
    elsif @link_to_nforum_discussion.nil? || @link_to_nforum_discussion == ""
       return generic_nforum_link
    end
    "<a href=\"" + @link_to_nforum_discussion + "\">Discuss</a>"
  end

  def history
    link_to_history(
      @page,
      "History (#{@page.rev_ids.size - 1} #{@page.rev_ids.size - 1 == 1 ? 'revision' : 'revisions'})",
      {:class => 'navlink', :accesskey => 'S', :id => 'history', :rel => 'nofollow'})
  end

  def forward
    if @revision_number < @page.rev_ids.size - 1
      "<span class=\"backintime\">" +
      link_to('Next revision',
          {:web => @web.address, :action => 'revision', :id => @page.name, :rev => @revision_number + 1},
          {:class => 'navlinkbackintime', :accesskey => 'F', :id => 'to_next_revision', :rel => 'nofollow'}) +
          " (#{@revision.page.rev_ids.size - @revision_number} more)".html_safe +

     "</span>"
    else
      "<span class=\"backintime\">" +
      link_to('Next revision', {:web => @web.address, :action => 'show', :id => @page.name},
          {:class => 'navlinkbackintime', :accesskey => 'F', :id => 'to_next_revision', :rel => 'nofollow'}) +
          " (to current)".html_safe +
      "</span>"
    end
  end

  def back_for_revision
    "<span class=\"backintime\">" +
    link_to('Previous revision',
        {:web => @web.address, :action => 'revision', :id => @page.name, :rev => @revision_number - 1},
        {:class => 'navlinkbackintime', :id => 'to_previous_revision', :rel => 'nofollow'}) +
        " (#{@revision_number - 1} more)".html_safe +
    "</span>"
  end

  def back_for_page
    "<span class=\"backintime\">" +
    link_to("Previous revision",
        {:web => @web.address, :action => 'revision', :id => @page.name,
        :rev => @page.rev_ids.size - 1},
        {:class => 'navlinkbackintime', :accesskey => 'B', :id => 'to_previous_revision', :rel => 'nofollow'}) +
    "</span>"
  end

  def current_revision
    link_to('Current version of page', {:web => @web.address, :action => 'show', :id => @page.name},
        {:class => 'navlink', :id => 'to_current_revision'})
  end

  def see_or_hide_changes_for_revision
    link_to(@show_diff ? 'Hide changes' : 'Changes from previous revision',
        {:web => @web.address, :action => 'revision', :id => @page.name, :rev => @revision_number,
         :mode => (@show_diff ? nil : 'diff') },
        {:class => 'navlink', :accesskey => 'C', :id => 'see_changes', :rel => 'nofollow'})
  end

  def see_or_hide_changes_for_page
    link_to(@show_diff ? 'Hide changes' : 'Changes from previous revision',
        {:web => @web.address, :action => 'show', :id => @page.name, :mode => (@show_diff ? nil : 'diff') },
        {:class => 'navlink', :accesskey => 'C', :id => 'see_changes', :rel => 'nofollow'})
  end

  def rollback
    link_to('Rollback',
        {:web => @web.address, :action => 'rollback', :id => @page.name, :rev => @revision_number},
        {:class => 'navlink', :id => 'rollback', :rel => 'nofollow'})
  end
end
