class AddAuthorRevisionsTable < ActiveRecord::Migration
  def self.up
    create_table "author_revisions", :force => true do |t|
      t.string   "author",      :limit => 60, :null => false
      t.integer  "revision_id", :default => 0, :null => false
      t.integer  "page_id",     :default => 0, :null => false
      t.integer  "web_id",      :default => 0, :null => false
    end

    add_index "author_revisions", ["author"], :name => "index_author_revisions_on_author"
    #add_index "author_revisions", ["page_id"], :name => "index_author_revisions_on_page_id"

    Revision.find(:all).each {|rev|
      ar = AuthorRevision.new(
        :author      => rev.author,
        :revision_id => rev.id,
        :page_id     => rev.page_id,
        :web_id      => rev.web_id)
      ar.save
    }
  end

  def self.down
    remove_table "author_revisions"
  end
end
