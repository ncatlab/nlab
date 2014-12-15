class Author < String
  attr_accessor :ip
  attr_reader :name
  def initialize(name, ip = nil)
    @ip = ip
    super(name.as_utf8)
  end

  def name=(value)
    self.gsub!(/.+/, value)
  end

  alias_method :name, :to_s

  def <=>(other)
    name <=> other.to_s
  end

  def sanitize
    input = self.dup.force_encoding(Encoding::UTF_8)

    if input.valid_encoding?
      input
    else
      input.
        force_encoding(Encoding::ASCII_8BIT).
        encode!(Encoding::UTF_8,
                invalid: :replace,
                undef:   :replace)
    end
  end
end
