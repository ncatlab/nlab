# These environment variables are only used by the Python scripts in script/src.
# The exception is NFORUM_URL in environment_variables_static.rb, which is also used in the Ruby code.
# Those Python scripts are called from the Ruby code.

# Database connection (as used by the Python scripts).
ENV["NLAB_DATABASE_NAME"] = "nlab"
ENV["NLAB_DATABASE_USER"] = "nlab"
ENV["NLAB_DATABASE_PASSWORD"] = ""

# Log directory (for the Python scripts).
ENV["NLAB_LOG_DIRECTORY"] = "log"

# Preconfigured values (unlikely that change is needed).
require File.join(File.dirname(__FILE__), "environment_variables_static")
