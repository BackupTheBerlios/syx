INCLUDES		=	\
	-I$(top_srcdir) 	\
	$(SYX_DEP_CFLAGS)       \
	$(READLINE_DEP_CFLAGS)

pluginreadlinedir = $(plugindir)/readline

pluginreadline_LTLIBRARIES= libsyx-readline.la

libsyx_readline_la_SOURCES	= 	\
	plugin-init.c

libsyx_readline_la_LIBADD	= $(SYX_DEP_LIBS) $(READLINE_DEP_LIBS)

dist_streadlinedata_DATA = st/*.st

EXTRA_DIST = SConscript