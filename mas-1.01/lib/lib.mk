# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


lib_MD=

lib_MI=

lib_MDP=

lib_MIP=

lib_CINC= getopt.h init-path.h

lib_CSRC= getopt.c getopt1.c init-path.c raise.c

lib_OBJS=$(lib_CSRC:.c=.o) $(lib_MI:.mi=.o) $(lib_MIP:.mip=.o)

lib_ALLSRC= getopt.h init-path.h getopt.c getopt1.c init-path.c raise.c

$(top_srcdir)/lib/lib.mk: $(lib_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

$(lib_LIB)(getopt.o ): getopt.h 

$(lib_LIB)(getopt1.o ): getopt.h 

$(lib_LIB)(init-path.o): config.h

$(lib_LIB)(raise.o): config.h

# -EOF-
