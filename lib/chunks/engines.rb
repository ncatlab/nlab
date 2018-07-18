$: << File.dirname(__FILE__) + "../../lib"

require_dependency 'chunks/chunk'
require 'instiki_stringsupport'
require 'maruku'
require 'maruku/ext/math'
require_dependency 'rdocsupport'
require 'redcloth'
require 'oldredcloth'

# The markup engines are Chunks that call the one of RedCloth
# or RDoc to convert text. This markup occurs when the chunk is required
# to mask itself.
module Engines
  class AbstractEngine < Chunk::Abstract

    # Create a new chunk for the whole content and replace it with its mask.
    def self.apply_to(content)
      new_chunk = self.new(content)
      content.replace(new_chunk.mask)
    end

    private

    # Never create engines by constructor - use apply_to instead
    def initialize(content)
      @content = content
    end

  end

  class Textile < AbstractEngine
    def mask
      @content.as_utf8
      redcloth = RedCloth.new(@content, [:hard_breaks] + @content.options[:engine_opts])
      redcloth.filter_html = false
      redcloth.no_span_caps = false
      html = redcloth.to_html(:textile)
    end
  end

  class Markdown < AbstractEngine
    def mask
      text = @content.as_utf8.delete("\r").to_utf8
      html = Maruku.new(text, {:math_enabled => false}).to_html
      html.gsub(/\A<div class="maruku_wrapper_div">\n?(.*?)\n?<\/div>\Z/m, '\1')
    end
  end

  class MarkdownMML < AbstractEngine
    def mask
      text = @content.as_utf8.delete("\r").to_utf8
      (t = Time.now; nil)
      html = Maruku.new(text,
           {:math_enabled => true,
            :html_math_generate_ids => true,
            :math_numbered => ['\\[','\\begin{equation}']}).to_html
      (ApplicationController.logger.info("Maruku took " + (Time.now-t).to_s + " seconds."); nil)
      html.gsub(/\A<div class="maruku_wrapper_div">\n?(.*?)\n?<\/div>\Z/m, '\1')
    end
  end

  class MarkdownPNG < AbstractEngine
    def mask
      text = @content.as_utf8.delete("\r").to_utf8
      html = Maruku.new(text,
           {:math_enabled => true,
            :math_numbered => ['\\[','\\begin{equation}'],
            :html_math_output_mathml => false,
            :html_math_output_png => true,
            :html_png_engine => 'blahtex',
            :html_png_dir => @content.web.files_path.join('pngs').to_s,
            :html_png_url => @content.options[:png_url]}).to_html
      html.gsub(/\A<div class="maruku_wrapper_div">\n?(.*?)\n?<\/div>\Z/m, '\1')
    end
  end

  class Mixed < AbstractEngine
    def mask
      @content.as_utf8
      redcloth = OldRedCloth.new(@content.to_str, @content.options[:engine_opts])
      redcloth.filter_html = false
      redcloth.no_span_caps = false
      html = redcloth.to_html
    end
  end

  class RDoc < AbstractEngine
    def mask
      html = RDocSupport::RDocFormatter.new(@content.as_utf8.to_str).to_html
    end
  end

  MAP = { :textile => Textile, :markdown => Markdown, :markdownMML => MarkdownMML, :markdownPNG => MarkdownPNG, :mixed => Mixed, :rdoc => RDoc }
  MAP.default = MarkdownMML
end
