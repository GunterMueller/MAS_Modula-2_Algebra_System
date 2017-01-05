# Generated automatically from Makefile.in by configure.
# ------------------------------------------------------------- -*-Makefile-*-
# $Id: Makefile.in,v 1.11 1996/06/09 12:04:38 pesch Exp $
# ----------------------------------------------------------------------------
# Makefile.in for MAS
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------
# $Log: Makefile.in,v $
# Revision 1.11  1996/06/09 12:04:38  pesch
# Changed NOMK to MKMK. Make will not regenerate .mk files by default now.
#
# Revision 1.10  1996/06/08 18:23:51  pesch
# New target tfdist for test file distribution.
#
# Revision 1.9  1995/10/24 14:22:38  pesch
# Changed MASINPUTS to DEFAULT_MASINPUTS.
# Use CFLAGSOPT instead of CFLAGS when generating mas-opt
# Delete config.h.in prior to calling autoheader.
#
# Revision 1.8  1995/10/12 14:55:43  pesch
# Added masib
#
# Revision 1.7  1995/09/13  19:07:04  pesch
# Corrected dependencies for dist and cdist.
#
# Revision 1.6  1995/09/13  14:39:23  pesch
# Fixed typo.
#
# Revision 1.5  1995/09/13  14:19:49  pesch
# If the environment variable NOMK is set, .mk files will not be made
# (only touched).
#
# Revision 1.4  1995/06/08  16:34:37  pesch
# Modified dependencies for configure-generated files.
#
# Revision 1.3  1995/03/23  15:48:35  pesch
# New default masinputdir.
#
# Revision 1.2  1995/03/08  15:46:49  pesch
# Added targets bdist and cdist for binary resp. c-source distribution.
# Some minor modifications.
#
# Revision 1.1  1995/03/06  16:57:41  pesch
# New files to make mas using GNU autoconf and GNU make. This replaces
# the old Makefiles.
#
# ----------------------------------------------------------------------------

SHELL=/bin/sh

##############################################################################
# Installation directories
##############################################################################

# Prefix for all directories containing architecture independent files
prefix=/usr/local

# Prefix for all directories containing architecture dependent files
exec_prefix=${prefix}

# Directory to install programs in
bindir=$(exec_prefix)/bin

# Directory to install libraries in
libdir=$(prefix)/lib/mas

# Directory to install mas input files in
masinputdir=$(libdir)/masinput

# Directory to install C header files in
includedir=$(prefix)/include/mas

# Directory to install mtc definition modules in
mtcincludedir=$(libdir)/mtcinclude

##############################################################################
# Miscellaneous
##############################################################################

# Host type
host=

# Program name transformation rule
transform=s,x,x,

# Product
PRODUCT=MAS

# Version
VERSION=1.01

##############################################################################
# Source directories
##############################################################################

# The top level source directory
top_srcdir=.

# The actual source (sub)directory
srcdir=.

# Source directories without own library
LDIRS=masdom masib maslisp maslog masmain masmodul masnc maspoly masring masroot sacring

# All source directories
DIRS=$(LDIRS) masarith maskern lib

# Libraries for each source directory
masarith_LIB=libmarith.a
masdom_LIB=libmas.a
masib_LIB=libmas.a
maskern_LIB=libmkern.a
maslisp_LIB=libmas.a
maslog_LIB=libmas.a
masmain_LIB=libmas.a
masmodul_LIB=libmas.a
masnc_LIB=libmas.a
maspoly_LIB=libmas.a
masring_LIB=libmas.a
masroot_LIB=libmas.a
sacring_LIB=libmas.a
lib_LIB=libcx.a

# Where to look for source files
vpath 
vpath %.md $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.mi $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.mip $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.mdp $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.mk $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.c $(addprefix $(top_srcdir)/,$(DIRS))
vpath %.h $(addprefix $(top_srcdir)/,$(DIRS)) $(top_srcdir)
vpath %.in $(top_srcdir)
vpath %.awk $(top_srcdir)
vpath %.guess $(top_srcdir)
vpath %.sub $(top_srcdir)
vpath configure $(top_srcdir)
vpath install-sh $(top_srcdir)
vpath mkinstalldirs $(top_srcdir)

##############################################################################
# Programs
##############################################################################

# The C compiler
CC=gcc

# The C preprocessor
CPP=gcc -E

# The CFLAGS must not include -O, since cpu registers must not be used
# with MAS (The garbage collector will not check them for valid adresses).
CFLAGS=$(filter-out -O,-finline -finline-functions -fstrength-reduce -fthread-jumps -fcse-follow-jumps -fcse-skip-blocks -frerun-cse-after-loop -fexpensive-optimizations -fdelayed-branch -fschedule-insns -fschedule-insns2)
CFLAGSOPT=$(filter-out -O,-fomit-frame-pointer -finline -finline-functions -fstrength-reduce -fthread-jumps -fcse-follow-jumps -fcse-skip-blocks -frerun-cse-after-loop -fexpensive-optimizations -fdelayed-branch -fschedule-insns -fschedule-insns2)

# The cpp flags
CPPFLAGS= -DDEFAULT_MASINPUTS="\"$(masinputdir)\"" -I$(top_srcdir) -I$(top_srcdir)/lib -I.

# The ld flags
LDFLAGS=
LIBS=-lreadline -ltermcap -lkpathsea 

# The MODULA-2 compiler mtc
MTC=/usr/bin/mtc

# The C preprocessor for use with Modula-2 input 
# (must accept .mip and .mdp files)
MTCCPP=/usr/bin/cpp

# Flags for mtc
MTCFLAGS =  $(addprefix -d$(top_srcdir)/,$(DIRS)) -d. -d.

# Flags for the C preprocessor for use with Modula-2 input
MTCCPPFLAGS=-P -DHAVE_LIBKPATHSEA -DHAVE_LIBREADLINE

# The install program
INSTALL=/usr/bin/install -c
INSTALL_PROGRAM=${INSTALL}
INSTALL_DATA=${INSTALL} -m 644

# Creating symbolic links
LN_S=ln -s

# The ranlib program
RANLIB=ranlib

# The makemake automatic makefile generator
MAKEMAKE=makemake
MAKEMAKEAWK=./makemake.awk

# The autoconf program (from GNU autoconf)
AUTOCONF=autoconf

# The touch program
TOUCH=touch

##############################################################################
# Rules
##############################################################################

.SUFFIXES:	
.SUFFIXES: .c .o .h .md .mi .mdp .mip .a .mk

.PRECIOUS: .mk

%.h:%.md
	$(MTC) $(MTCFLAGS) $<

%.c:%.mi
	$(MTC) $(MTCFLAGS) $<

%.mi:%.mip
	$(MTCCPP) $(MTCCPPFLAGS) $< -o $@

%.md:%.mdp
	$(MTCCPP) $(MTCCPPFLAGS) $< -o $@

%.mk:
ifdef MKMK
	$(MAKEMAKE) $(@D) > $@
else
	$(TOUCH) $@
endif

##############################################################################
# Variables
##############################################################################

# Object files for libmas.a
LOBJS=$(foreach dir,$(LDIRS),$($(dir)_OBJS))

# All object files
OBJS=$(foreach dir,$(DIRS),$($(dir)_OBJS))

# All md, mdp, mi, mip, c, h and mk source files, respectively
MD=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_MD)))
MDP=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_MDP)))
MI=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_MI)))
MIP=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_MIP)))

CINC=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_CINC)))
CSRC=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_CSRC)))

ALLSRC=$(foreach dir,$(DIRS),$(addprefix $(dir)/,$($(dir)_ALLSRC)))

MKFILES=$(foreach dir,$(DIRS),$(dir)/$(dir).mk)

# All MAS libraries
MASLIBS=libmas.a libmarith.a libmkern.a libcx.a

# All libraries wich need to be linked
LOADLIBES=$(MASLIBS) $(LIBS)

##############################################################################
# The default target: Build mas and the libraries
##############################################################################

.PHONY:	all
all: mas libs

##############################################################################
# Include the mk files
##############################################################################

include $(addprefix $(top_srcdir)/,$(MKFILES))

##############################################################################
# Compilation
##############################################################################

libmarith.a: libmarith.a($(masarith_OBJS))
	$(RANLIB) libmarith.a

libcx.a: libcx.a($(lib_OBJS))
	$(RANLIB) libcx.a

libmkern.a: libmkern.a($(maskern_OBJS))
	$(RANLIB) libmkern.a

libmas.a: libmas.a($(filter-out MAS.o, $(LOBJS)))
	$(RANLIB) libmas.a

# Build the libraries
.PHONY:	libs
libs: $(MASLIBS)

# Build mas
mas: libs MAS.o
	-mv -f $@ $@.old
	$(CC) $(LDFLAGS) MAS.o $(LOADLIBES) -o $@

# Build an optimized version of MAS
# By seeing all .c files at once gcc might optimize across files
# This may take some time ...
mas-opt: $(addprefix $(top_srcdir)/,$(CSRC)) $(subst .mi,.c,$(notdir $(MI))) $(subst .mip,.c,$(notdir $(MIP))) $(notdir $(CINC)) $(subst .md,.h,$(notdir $(MD))) $(subst .mdp,.h,$(notdir $(MDP)))
	-mv -f $@ $@.old
	$(CC) $(CFLAGSOPT) $(CPPFLAGS) $(LDFLAGS) $(addprefix $(top_srcdir)/,$(CSRC)) $(subst .mi,.c,$(notdir $(MI))) $(subst .mip,.c,$(notdir $(MIP))) $(LIBS) -o $@

##############################################################################
# Installation
##############################################################################

# Install everything
.PHONY:	install
install: install-mas install-libs

# Delete all installed (i.e. created by the install target) files
.PHONY:	uninstall
uninstall: uninstall-mas uninstall-libs

# Install mas
.PHONY:	install-mas
install-mas: mas installdirs-mas
	$(INSTALL_PROGRAM) mas $(bindir)/`echo mas|sed '$(transform)'`

# Delete the installed mas
.PHONY:	uninstall-mas
uninstall-mas:
	$(RM) $(bindir)/`echo mas|sed '$(transform)'`

# Create directory to install mas in, if not present
.PHONY:	installdirs-mas
installdirs-mas: $(top_srcdir)/mkinstalldirs
	$(top_srcdir)/mkinstalldirs $(bindir)

# Install libraries
.PHONY:	install-libs
install-libs: $(MASLIBS) $(notdir $(MD) $(MDP:.mdp=.md) $(MD:.md=.h) $(MDP:.mdp=.h)) installdirs-libs
	for p in $(MASLIBS); do $(INSTALL_DATA) $$p $(libdir); done
	for p in $(addprefix $(top_srcdir)/,$(MD)) $(notdir $(MDP:.mdp=.md)); do $(INSTALL_DATA) $$p $(mtcincludedir); done
	for p in $(notdir $(MD:.md=.h) $(MDP:.mdp=.h)); do $(INSTALL_DATA) $$p $(includedir); done

# Delete all installed libraries
.PHONY:	uninstall-libs
uninstall-libs:
	for p in $(MASLIBS); do $(RM) $(libdir)/$$p; done
	for p in $(notdir $(MD) $(MDP:.mdp=.md)); do $(RM) $(mtcincludedir)/$$p; done
	for p in $(notdir $(MD:.md=.h) $(MDP:.mdp=.h)); do $(RM) $(includedir)/$$p; done

# Create directories to install libraries in, if not present
.PHONY:	installdirs-libs
installdirs-libs: $(top_srcdir)/mkinstalldirs
	$(top_srcdir)/mkinstalldirs $(libdir) $(includedir) $(mtcincludedir)

# Check for presence of the mkinstalldirs program
$(top_srcdir)/mkinstalldirs:
	@echo "Sorry, mkinstalldirs is missing!"
	@echo "You probably got an incomplete distribution!"

##############################################################################
# Makefile
# config.h
# The makemake script
##############################################################################

Makefile $(MAKEMAKE) config.h: $(top_srcdir)/Makefile.in $(top_srcdir)/makemake.in $(top_srcdir)/config.h.in $(top_srcdir)/configure
	$(top_srcdir)/configure --prefix=$(prefix)

##############################################################################
# .mk file generation
##############################################################################

.PHONY:	mkfiles
mkfiles: $(addprefix $(top_srcdir)/,$(MKFILES)) $(MAKEMAKE) $(MAKEMAKEAWK)

##############################################################################
# configure
##############################################################################

$(top_srcdir)/configure: $(top_srcdir)/configure.in
	cd $(top_srcdir); autoconf
	chmod +x $(top_srcdir)/configure

##############################################################################
# config.h.in
##############################################################################

$(top_srcdir)/config.h.in: $(top_srcdir)/configure.in $(top_srcdir)/acconfig.h
	cd $(top_srcdir); $(RM) config.h.in; autoheader 

##############################################################################
# Cleaning
##############################################################################

# Delete all files created by building the program, except those one will not
# usually want to rebuild
.PHONY:	mostlyclean
mostlyclean:
	$(RM) $(OBJS) $(notdir $(MIP:.mip=.mi)) $(notdir $(MIP:.mip=.c)) $(notdir $(MI:.mi=.c)) $(notdir $(MDP:.mdp=.md)) $(notdir $(MDP:.mdp=.h)$(MD:.md=.h))

# Delete all files created by building the program, except those that are
# in the distribution and those that record the configuration
.PHONY:	clean
clean: mostlyclean
	$(RM) $(MASLIBS) mas mas.old mas-opt mas-opt.old

# Delete all files that were not in the distribution
.PHONY:	distclean
distclean: clean
	$(RM) Makefile config.cache config.h config.log config.status

# Delete all files that can be rebuild using configure and the
# generated Makefile, except configure
.PHONY:	realclean
realclean: distclean
	$(RM) $(addprefix $(top_srcdir), $(MKFILES) config.h.in)

# Delete all files that can be rebuild
.PHONY:	realrealclean
realrealclean: distclean
	$(RM) $(addprefix $(top_srcdir),configure)

##############################################################################
# Distributing
##############################################################################

# Source distribution
.PHONY:	dist
distdir=mas-$(VER)
distname=mas-$(VER).tar.gz

DIST_DIRS=$(DIRS)

DIST_TOP_PROGRAMS=config.guess config.sub configure install-sh mkinstalldirs
DIST_OTHER_PROGRAMS=
DIST_PROGRAMS=$(DIST_TOP_PROGRAMS) $(DIST_OTHER_PROGRAMS)

DIST_TOP_DATAS= INSTALL Makefile.in acconfig.h config.h.in configure.in makemake.awk makemake.in 
DIST_OTHER_DATAS=$(MKFILES) $(MD) $(MDP) $(MI) $(MIP) $(CINC) $(CSRC)
DIST_DATAS=$(DIST_TOP_DATAS) $(DIST_OTHER_DATAS)

DIST_TOP_FILES=$(DIST_TOP_DATAS) $(DIST_TOP_PROGRAMS)
DIST_OTHER_FILES=$(DIST_OTHER_DATAS) $(DIST_OTHER_PROGRAMS)
DIST_FILES=$(DIST_DATAS) $(DIST_PROGRAMS)

ifndef VER
dist:
	@echo "Please give a version number, e.g. $(MAKE) dist VER=0.001"
else
dist: $(distdir) $(addprefix $(distdir)/,$(DIST_FILES))
	chmod 644 $(addprefix $(distdir)/,$(DIST_DATAS))
	chmod 755 $(distdir) $(addprefix $(distdir)/,$(DIST_DIRS) $(DIST_PROGRAMS))
	gnutar cfhz $(distname) $(addprefix ./$(distdir)/,$(DIST_FILES))

$(distdir): $(top_srcdir)/mkinstalldirs $(addprefix $(top_srcdir)/,$(DIST_DIRS) $(DIST_TOP_FILES))
	$(top_srcdir)/mkinstalldirs $(distdir)
	$(LN_S) $(addprefix ../$(top_srcdir)/,$(DIST_DIRS) $(DIST_TOP_FILES)) $(distdir)
endif

# C Source distribution
.PHONY:	cdist
cdistdir=mas-c-$(VER)
cdistname=mas-c-$(VER).tar.gz

CDIST_DIRS=$(DIRS)

CDIST_MKFILES=$(foreach f, $(DIST_DIRS), $(f)/$(f).mk)

CDIST_TOP_PROGRAMS=$(DIST_TOP_PROGRAMS)
CDIST_OTHER_PROGRAMS=$(DIST_OTHER_PROGRAMS)
CDIST_PROGRAMS=$(CDIST_TOP_PROGRAMS) $(CDIST_OTHER_PROGRAMS)

CDIST_TOP_DATAS=$(DIST_TOP_DATAS)
CDIST_OTHER_DATAS=$(CDIST_MKFILES) 
CDIST_GEN_DATAS=$(subst .mip,.c,$(MIP)) $(subst .mi,.c,$(MI)) $(subst .mdp,.h,$(MDP)) $(subst .md,.h,$(MD))
CDIST_DATAS=$(CDIST_TOP_DATAS) $(CDIST_OTHER_DATAS) $(CDIST_GEN_DATAS)

CDIST_TOP_FILES=$(CDIST_TOP_DATAS) $(CDIST_TOP_PROGRAMS)
CDIST_OTHER_FILES=$(CDIST_OTHER_DATAS) $(CDIST_OTHER_PROGRAMS)
CDIST_FILES=$(CDIST_DATAS) $(CDIST_PROGRAMS)

ifndef VER
cdist:
	@echo "Please give a version number, e.g. $(MAKE) cdist VER=0.001"
else
cdist: $(cdistdir) $(addprefix $(cdistdir)/,$(CDIST_FILES))
	chmod 644 $(addprefix $(cdistdir)/,$(CDIST_DATAS))
	chmod 755 $(cdistdir) $(addprefix $(cdistdir)/,$(CDIST_DIRS) $(CDIST_PROGRAMS))
	gnutar cfhz $(cdistname) $(addprefix ./$(cdistdir)/,$(CDIST_FILES))

$(cdistdir): $(top_srcdir)/mkinstalldirs $(addprefix $(cdistdir)/,$(CDIST_DIRS)) $(addprefix $(top_srcdir)/, $(CDIST_TOP_FILES))
	$(top_srcdir)/mkinstalldirs $(cdistdir) 
	$(LN_S) $(addprefix ../$(top_srcdir)/, $(CDIST_TOP_FILES)) $(cdistdir)

$(addprefix $(cdistdir)/,$(CDIST_DIRS)): $(top_srcdir)/mkinstalldirs $(notdir $(CDIST_GEN_DATAS))
	$(top_srcdir)/mkinstalldirs $@
	$(LN_S) $(addprefix ../../,$(subst .mip,.c,$($(notdir $@)_MIP))) \
	        $(addprefix ../../,$(subst .mi,.c,$($(notdir $@)_MI))) \
	        $(addprefix ../../,$(subst .mdp,.h,$($(notdir $@)_MDP))) \
	        $(addprefix ../../,$(subst .md,.h,$($(notdir $@)_MD))) \
	        $(addprefix ../../$(top_srcdir)/$(notdir $@)/,$($(notdir $@)_CSRC)) \
	        $(addprefix ../../$(top_srcdir)/$(notdir $@)/,$($(notdir $@)_CINC)) \
	        $@

endif

# binary distribution
.PHONY:	bdist
bdistdir=mas-$(host)-$(VER)
bdistname=mas-$(host)-$(VER).tar.gz

BDIST_DIRS=

BDIST_TOP_PROGRAMS=
BDIST_OTHER_PROGRAMS=
BDIST_PROGRAMS=$(BDIST_TOP_PROGRAMS) $(BDIST_OTHER_PROGRAMS)

BDIST_TOP_DATAS=
BDIST_OTHER_DATAS=
BDIST_DATAS=$(BDIST_TOP_DATAS) $(BDIST_OTHER_DATAS)

BDIST_TOP_FILES=
BDIST_OTHER_FILES=
BDIST_FILES=$(CDIST_DATAS) $(CDIST_PROGRAMS)

ifndef VER
bdist:
	@echo "Please give a version number, e.g. $(MAKE) bdist VER=0.001"
else
bdist: $(bdistdir) mas-opt
	chmod 755 $(bdistdir)/mas
	gnutar cfhz $(bdistname) $(addprefix ./$(bdistdir)/,mas)

$(bdistdir): $(top_srcdir)/mkinstalldirs
	$(top_srcdir)/mkinstalldirs $(bdistdir) 
	$(LN_S) $(addprefix ../, mas-opt) $(bdistdir)/mas

endif

# test files distribution
.PHONY:	tfdist
tfdistdir=mas-test-$(VER)
tfdistname=mas-test-$(VER).tar.gz

ifndef VER
tfdist:
	@echo "Please give a version number, e.g. $(MAKE) tfdist VER=0.001"
else
tfdist: $(tfdistdir)
	chmod 755 $(tfdistdir) $(tfdistdir)/examples $(tfdistdir)/examples/test
	chmod 644 $(tfdistdir)/examples/test/*
	chmod 664 $(tfdistdir)/examples/test-all.mas
	gnutar cfhz $(tfdistname) $(addprefix $(tfdistdir)/,examples)

$(tfdistdir): $(top_srcdir)/mkinstalldirs
	$(top_srcdir)/mkinstalldirs $(tfdistdir) $(tfdistdir)/examples
	$(LN_S) ../../$(top_srcdir)/examples/test-all.mas $(tfdistdir)/examples
	$(LN_S) ../../$(top_srcdir)/examples/test $(tfdistdir)/examples

endif

##############################################################################
# Checking
##############################################################################

.PHONY:	check
check:
	@echo "Sorry, not available."
#
# -EOF-
