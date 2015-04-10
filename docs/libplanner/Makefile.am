## Process this file with automake to produce Makefile.in

# The name of the module.
DOC_MODULE=libplanner

# The top-level XML file (SGML in the past).
DOC_MAIN_SGML_FILE=$(DOC_MODULE)-docs.xml

# Directories containing the source code.
# gtk-doc will search all .c and .h files beneath these paths
# for inline comments documenting functions and macros.
# e.g. DOC_SOURCE_DIR=$(top_srcdir)/gtk $(top_srcdir)/gdk
DOC_SOURCE_DIR=$(top_srcdir)/libplanner

# Extra options to pass to gtkdoc-scangobj. Not normally needed.
SCANGOBJ_OPTIONS=

# Extra options to supply to gtkdoc-scan
#SCAN_OPTIONS=--deprecated-guards="GTK_ENABLE_BROKEN|GTK_DISABLE_DEPRECATED"

# Extra options to supply to gtkdoc-mkdb.
# e.g. MKDB_OPTIONS=--xml-mode --output-format=xml
MKDB_OPTIONS=--xml-mode --output-format=xml

# Extra options to supply to gtkdoc-fixref
#FIXXREF_OPTIONS=--extra-dir=../file-modules/html --extra-dir=../file-modules/html

# Used for dependencies
HFILE_GLOB=$(top_srcdir)/libplanner/*.h
CFILE_GLOB=$(top_srcdir)/libplanner/*.c

# Header files or dirs to ignore when scanning. Use base file/dir names
# e.g. IGNORE_HFILES=gtkdebug.h gtkintl.h private_code
IGNORE_HFILES = \
  mrp-file-module.h \
  mrp-marshal.h \
  mrp-old-xml.h \
  mrp-parser.h \
  mrp-paths.h  \
  mrp-private.h \
  mrp-sql.h \
  mrp-storage-module-factory.h \
  mrp-storage-module.h  \
  mrp-storage-module-xml.h  \
  mrp-storage-mrproject.h \
  mrp-storage-sql.h \
  mrp-task-manager.h

# Extra SGML files that are included by $(DOC_MAIN_SGML_FILE)
# e.g. content_files=running.sgml building.sgml changes-2.0.sgml
content_files=

# CFLAGS and LDFLAGS for compiling scan program. Only needed
# if $(DOC_MODULE).types is non-empty.
GTKDOC_CFLAGS = 					\
	$(LIBPLANNER_CFLAGS)				\
	-I$(top_srcdir) 				\
	-I$(top_builddir)/libplanner

GTKDOC_LIBS =						\
	$(LIBPLANNER_LIBS)				\
	$(top_builddir)/libplanner/libplanner-1.la

# This includes the standard gtk-doc make rules, copied by gtkdocize.
include $(top_srcdir)/gtk-doc.make

# Comment this out if you want 'make check' to test you doc status
# and run some sanity checks
if ENABLE_GTK_DOC
TESTS_ENVIRONMENT = \
  DOC_MODULE=$(DOC_MODULE) DOC_MAIN_SGML_FILE=$(DOC_MAIN_SGML_FILE) \
  SRCDIR=$(abs_srcdir) BUILDDIR=$(abs_builddir)
TESTS = $(GTKDOC_CHECK)
endif
