# Relative paths to Python "APIs" and contained paths.
ENV["NLAB_ALL_REFERENCES_PATH"] = "script/src/citations/all_references.py"
ENV["NLAB_AUTHOR_TO_USER_FILE"] = "script/author_to_user"
ENV["NLAB_BIBTEX_TEMPLATE"] = "script/src/citations/bibtex_template"
ENV["NLAB_CITATION_SOURCE_DIRECTORY"] = "script/src/citations/citation_source"
ENV["NLAB_DIAGRAM_API_PATH"] = "script/src/diagram_caching/diagram_caching.py"
ENV["NLAB_DIAGRAM_SOURCE_DIRECTORY"] = "script/src/diagrams/diagram_source"
ENV["NLAB_LATEX_REFERENCE_TEMPLATE"] = "script/src/citations/latex_reference_template"
ENV["NLAB_PAGE_RENDERER_PATH"] = "script/src/renderer/renderer.py"
ENV["NLAB_REFERENCE_RENDERER_PATH"] = "script/src/renderer/reference_renderer.py"
ENV["NLAB_SAVE_REFERENCE_PATH"] = "script/src/citations/save_reference.py"
ENV["NLAB_SEQUENTIAL_QUEUE_PATH"] = "script/src/sequential_queue/sequential_queue.py"
ENV["NLAB_SPAM_DETECTOR_PATH"] = "script/src/spam_detector/spam_detector.py"
ENV["NLAB_TIKZ_DIAGRAM_TEMPLATE"] = "script/src/diagrams/tikz_diagram_template"
ENV["NLAB_XYPIC_DIAGRAM_TEMPLATE"] = "script/src/diagrams/xypic_diagram_template"
ENV["XML_DETECTOR_API_PATH"] = "script/src/xml_detector/xml_detector.py"
ENV["XML_WHITELIST_PATH"] = "script/src/xml_detector/xml_whitelist"

# Page-content-related paths.
ENV["NLAB_PAGE_CONTENT_DIRECTORY"] = "page_content"
ENV["NLAB_SUBMITTED_ANNOUNCEMENTS_DIRECTORY"] = "page_content/submitted_announcements"
ENV["NLAB_SUBMITTED_EDITS_DIRECTORY"] = "page_content/submitted_edits"

# nForum-related
ENV["NLAB_NFORUM_PREFIX"] = "http://saunders2.andrew.cmu.edu:8009/discussion/"

# Working paths for the sequential queue API.
ENV["QUEUE_COMPLETED_JOBS_DIRECTORY"] = "sequential_queue/completed"
ENV["QUEUE_CONTROL_DIRECTORY"] = "sequential_queue/control"
ENV["QUEUE_JOB_ROOT_DIRECTORY"] = "sequential_queue/jobs"
ENV["QUEUE_MAXIMUM_NUMBER_OF_SIMULTANEOUS_JOBS"] = "50"

# Cache directory.
ENV["NLAB_CACHE_DIRECTORY"] = "cache/views"

# Web files root.
ENV["WEB_FILES_ROOT"] = "webs"

# Command-line for itex2MML.
# Currently packaged as a binary inside this repository.
ENV["RUN_COMMAND_FOR_LATEX_COMPILER"] = "script/itex2MML"

# Configuration of the diagram_caching script.
# See script/src/diagram_caching/diagram_caching.py for documentation.
ENV["NLAB_DIAGRAM_CACHE_DIRECTORY"] = "diagram_cache"
ENV["NLAB_PDFLATEX"] = "pdflatex"
ENV["NLAB_DIAGRAM_TIMEOUT"] = "5"
ENV["NLAB_DIAGRAM_LATEX_RESTRICT_OPEN"] = "1"

# Directory for edit logs.
ENV["EDIT_LOG_DIRECTORY_PATH"] = ENV["NLAB_LOG_DIRECTORY"] + "/edit_log"
