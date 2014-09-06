class Revision < ActiveRecord::Base
  belongs_to :page
  belongs_to :web
  composed_of :author, :mapping => [ %w(author name), %w(ip ip) ]

  before_save :update_web_id

  def content
    read_attribute(:content).as_utf8
  end

  def number
    # for long arrays, this is faster than array.index
    Hash[self.page.rev_ids.map.with_index.to_a][self] + 1
  end

  def update_web_id
    if !self.web_id and self.page and self.page.web_id
      self.web_id = self.page.web_id
    end
  end
end
