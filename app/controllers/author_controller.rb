require "json"

class AuthorController < ApplicationController
  layout "default", :except => []

  def author
    name = params["name"]
    if !nlab_author?(name)
      render(
        :status => 404,
        :template => "/errors/404.rhtml")
      return
    end
    @author = name
    @last_pages_contributed_to = last_pages_contributed_to(name)
    @pages_contributed_to = pages_contributed_to(name)
    @number_of_contributions = @pages_contributed_to.count
    return
  end

  def link_to_nlab_page(page)
    "https://ncatlab.org/" + @web_name + "/show/" + URI.encode(page)
  end

  helper_method :link_to_nlab_page

  def link_to_nlab_revision(revision_number, page)
    "https://ncatlab.org/" +
        @web_name +
        "/revision/diff/" +
        URI.encode(page) +
        "/" +
        revision_number.to_s
  end

  helper_method :link_to_nlab_revision

  private

  def nlab_author?(possible_author)
    author_contributions_binary = File.join(
      Rails.root,
      "script/author_contributions")
    is_nlab_author = %x(
      "#{author_contributions_binary}" is_author "#{possible_author}")
    is_nlab_author.strip! == "True" unless is_nlab_author.nil?
  end

  def pages_contributed_to(nlab_author)
    author_contributions_binary = File.join(
      Rails.root,
      "script/author_contributions")
    pages = %x(
      "#{author_contributions_binary}" pages "#{nlab_author}")
    JSON.parse(pages)
  end

  def last_pages_contributed_to(nlab_author)
    author_contributions_binary = File.join(
      Rails.root,
      "script/author_contributions")
    pages = %x(
      "#{author_contributions_binary}" recent "#{nlab_author}")
    JSON.parse(pages)
  end
end
