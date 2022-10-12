require "date"
require "json"

class ReferenceController < ApplicationController
  layout "default", :except => []

  def show
     @citation_key = params[:citation_key]
     reference_renderer_path = ENV["NLAB_REFERENCE_RENDERER_PATH"]
     response, error_message, status = Open3.capture3(
        reference_renderer_path,
        @citation_key)
      if !status.success?
        flash[:error] = error_message
        return
      end
      response_json = JSON.parse(response)
      @rendered_reference = response_json["reference"]
      @reference_added_at = DateTime.strptime(
          response_json["made_at"],
          "%Y-%m-%d %H:%M:%S")
      return
  end

end
