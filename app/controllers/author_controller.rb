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

  private

  def nlab_author?(possible_author)
    author_contributions_path = File.join(
      Rails.root,
      "script/src/author_contributions/author_contributions.py")
    is_nlab_author = IO.popen([author_contributions_path.to_s, "is_author", possible_author.to_s], &:read)
    is_nlab_author.strip! == "True" unless is_nlab_author.nil?
  end

  def pages_contributed_to(nlab_author)
    author_contributions_path = File.join(
      Rails.root,
      "script/src/author_contributions/author_contributions.py")
    pages = IO.popen([author_contributions_path.to_s, "pages", nlab_author.to_s], &:read)
    JSON.parse(pages)
  end

  def last_pages_contributed_to(nlab_author)
    author_contributions_path = File.join(
      Rails.root,
      "script/src/author_contributions/author_contributions.py")
    pages = IO.popen([author_contributions_path.to_s, "recent", nlab_author.to_s], &:read)
    JSON.parse(pages)
  end
end
