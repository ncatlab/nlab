class Revision < ActiveRecord::Base
  belongs_to :page
  composed_of :author, :mapping => [ %w(author name), %w(ip ip) ]

  def content
    read_attribute(:content).as_utf8
  end

  def number
    # for long arrays, this is faster than array.index
    Hash[self.page.rev_ids.map.with_index.to_a][self] + 1
  end
end
