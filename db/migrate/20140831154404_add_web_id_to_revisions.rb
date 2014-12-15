class AddWebIdToRevisions < ActiveRecord::Migration
  def self.up
    add_column "revisions", "web_id", :integer
    add_index "revisions", ["web_id"], :name => "index_revisions_on_web_id"
    Revision.find(:all).each {|rev|
      rev.web_id = rev.page.web_id
      rev.save
    }
  end

  def self.down
    remove_column "revisions", "web_id"
    remove_index "revisions", ["web_id"]
  end
end