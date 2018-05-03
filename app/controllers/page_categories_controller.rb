require "json"

class PageCategoriesController < ApplicationController
  layout "default", :except => []

  def all
    @name_text = name_text(@web.name)
    @all_categories = all_categories_in_web(@web.id)
    @number_of_categories = @all_categories.count
    return
  end

  def link_to_category(category)
      "https://ncatlab.org/" + @web_name + "/all_pages/" + URI.encode(category)
  end

  helper_method :link_to_category

  private

  def all_categories_in_web(web_id)
    page_categories_binary = File.join(
      Rails.root,
      "script/page_categories")
    pages = %x(
      "#{page_categories_binary}" all_categories "#{web_id}")
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
    author_contributions_binary = File.join(
      Rails.root,
      "script/author_contributions")
    is_nlab_author = %x(
      "#{author_contributions_binary}" is_author "#{possible_author}")
    is_nlab_author.strip! == "True" unless is_nlab_author.nil?
  end
end
