require 'mkmf'

$CFLAGS << ' -Ditex2MML_CAPTURE'
create_makefile("itex2MML")

