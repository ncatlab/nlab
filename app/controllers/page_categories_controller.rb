require "json"

class PageCategoriesController < ApplicationController
  layout "default", :except => []

  def all
    @name_text = name_text(@web.name)
    @all_categories = all_categories_in_web(@web.id)
    @number_of_categories = @all_categories.count
    return
  end

  private

  def all_categories_in_web(web_id)
    page_categories_path = File.join(
      Rails.root,
      "script/src/page_categories/page_categories.py")
    pages = %x(
      "#{page_categories_path}" all_categories "#{web_id}")
    JSON.parse(pages)
  end

  def name_text(web_name)
    if web_name == "nLab"
      return "The nLab"
    elsif nlab_author?(web_name)
      return "The personal wiki of " + web_name
    else
      return "The " + web_name + " wiki"
    end
  end

  def nlab_author?(possible_author)
    author_contributions_path = File.join(
      Rails.root,
      "script/src/author_contributions/author_contributions.py")
    is_nlab_author = %x(
      "#{author_contributions_path}" is_author "#{possible_author}")
    is_nlab_author.strip! == "True" unless is_nlab_author.nil?
  end
end
