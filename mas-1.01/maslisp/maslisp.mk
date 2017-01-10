# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


maslisp_MD= ALDPARSE.md MASLISP.md MASLISPU.md MASPARSE.md MASREP.md MASSPEC.md MASSYM.md MASSYM2.md MODVAR.md SACSYM.md SACSYM2.md

maslisp_MI= ALDPARSE.mi MASLISP.mi MASLISPU.mi MASPARSE.mi MASREP.mi MASSPEC.mi MASSYM.mi MASSYM2.mi MODVAR.mi SACSYM.mi SACSYM2.mi

maslisp_MDP=

maslisp_MIP=

maslisp_CINC=

maslisp_CSRC=

maslisp_OBJS=$(maslisp_CSRC:.c=.o) $(maslisp_MI:.mi=.o) $(maslisp_MIP:.mip=.o)

maslisp_ALLSRC= ALDPARSE.md MASLISP.md MASLISPU.md MASPARSE.md MASREP.md MASSPEC.md MASSYM.md MASSYM2.md MODVAR.md SACSYM.md SACSYM2.md ALDPARSE.mi MASLISP.mi MASLISPU.mi MASPARSE.mi MASREP.mi MASSPEC.mi MASSYM.mi MASSYM2.mi MODVAR.mi SACSYM.mi SACSYM2.mi

$(top_srcdir)/maslisp/maslisp.mk: $(maslisp_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

ALDPARSE.h: MASSTOR.h

$(maslisp_LIB)(ALDPARSE.o): ALDPARSE.c ALDPARSE.h
$(maslisp_LIB)(ALDPARSE.o): MASSTOR.h
$(maslisp_LIB)(ALDPARSE.o): MASBIOS.h
$(maslisp_LIB)(ALDPARSE.o): SACLIST.h
$(maslisp_LIB)(ALDPARSE.o): MASSYM2.h
$(maslisp_LIB)(ALDPARSE.o): MASSYM.h
$(maslisp_LIB)(ALDPARSE.o): MASLISPU.h
$(maslisp_LIB)(ALDPARSE.o): MASLISP.h
$(maslisp_LIB)(ALDPARSE.o): MASSPEC.h

MASLISP.h: MASSTOR.h

$(maslisp_LIB)(MASLISP.o): MASLISP.c MASLISP.h
$(maslisp_LIB)(MASLISP.o): MASSTOR.h
$(maslisp_LIB)(MASLISP.o): MASERR.h
$(maslisp_LIB)(MASLISP.o): MASBIOS.h
$(maslisp_LIB)(MASLISP.o): MASBIOSU.h
$(maslisp_LIB)(MASLISP.o): SACLIST.h
$(maslisp_LIB)(MASLISP.o): MASSYM2.h
$(maslisp_LIB)(MASLISP.o): MASSYM.h
$(maslisp_LIB)(MASLISP.o): MASLISPU.h

MASLISPU.h: MASSTOR.h

$(maslisp_LIB)(MASLISPU.o): MASLISPU.c MASLISPU.h
$(maslisp_LIB)(MASLISPU.o): MASELEM.h
$(maslisp_LIB)(MASLISPU.o): MASSTOR.h
$(maslisp_LIB)(MASLISPU.o): MASERR.h
$(maslisp_LIB)(MASLISPU.o): MASBIOS.h
$(maslisp_LIB)(MASLISPU.o): SACLIST.h
$(maslisp_LIB)(MASLISPU.o): MASSYM2.h
$(maslisp_LIB)(MASLISPU.o): MASSYM.h

MASPARSE.h: MASSTOR.h

$(maslisp_LIB)(MASPARSE.o): MASPARSE.c MASPARSE.h
$(maslisp_LIB)(MASPARSE.o): MASELEM.h
$(maslisp_LIB)(MASPARSE.o): MASSTOR.h
$(maslisp_LIB)(MASPARSE.o): MASBIOS.h
$(maslisp_LIB)(MASPARSE.o): SACLIST.h
$(maslisp_LIB)(MASPARSE.o): MASSYM2.h
$(maslisp_LIB)(MASPARSE.o): MASSYM.h
$(maslisp_LIB)(MASPARSE.o): MASLISPU.h
$(maslisp_LIB)(MASPARSE.o): MASLISP.h

MASREP.h: MASSTOR.h

$(maslisp_LIB)(MASREP.o): MASREP.c MASREP.h
$(maslisp_LIB)(MASREP.o): MASSTOR.h
$(maslisp_LIB)(MASREP.o): SACLIST.h
$(maslisp_LIB)(MASREP.o): MASSYM2.h
$(maslisp_LIB)(MASREP.o): MASLISPU.h
$(maslisp_LIB)(MASREP.o): MASLISP.h
$(maslisp_LIB)(MASREP.o): MASSPEC.h

MASSPEC.h: MASSTOR.h

$(maslisp_LIB)(MASSPEC.o): MASSPEC.c MASSPEC.h
$(maslisp_LIB)(MASSPEC.o): MASSTOR.h
$(maslisp_LIB)(MASSPEC.o): MASERR.h
$(maslisp_LIB)(MASSPEC.o): MASBIOS.h
$(maslisp_LIB)(MASSPEC.o): MASBIOSU.h
$(maslisp_LIB)(MASSPEC.o): SACLIST.h
$(maslisp_LIB)(MASSPEC.o): MASSYM2.h
$(maslisp_LIB)(MASSPEC.o): MASSYM.h
$(maslisp_LIB)(MASSPEC.o): MASLISPU.h
$(maslisp_LIB)(MASSPEC.o): MASLISP.h

MASSYM.h: MASSTOR.h

$(maslisp_LIB)(MASSYM.o): MASSYM.c MASSYM.h
$(maslisp_LIB)(MASSYM.o): MASSTOR.h
$(maslisp_LIB)(MASSYM.o): MASBIOS.h
$(maslisp_LIB)(MASSYM.o): SACLIST.h
$(maslisp_LIB)(MASSYM.o): MASSYM2.h

MASSYM2.h: MASELEM.h
MASSYM2.h: MASSTOR.h

$(maslisp_LIB)(MASSYM2.o): MASSYM2.c MASSYM2.h
$(maslisp_LIB)(MASSYM2.o): MASELEM.h
$(maslisp_LIB)(MASSYM2.o): MASSTOR.h
$(maslisp_LIB)(MASSYM2.o): MASBIOS.h
$(maslisp_LIB)(MASSYM2.o): SACLIST.h

MODVAR.h: MASSTOR.h

$(maslisp_LIB)(MODVAR.o): MODVAR.c MODVAR.h
$(maslisp_LIB)(MODVAR.o): MASBIOS.h
$(maslisp_LIB)(MODVAR.o): MASELEM.h
$(maslisp_LIB)(MODVAR.o): MASERR.h
$(maslisp_LIB)(MODVAR.o): MASLISP.h
$(maslisp_LIB)(MODVAR.o): MASLISPU.h
$(maslisp_LIB)(MODVAR.o): MASSTOR.h
$(maslisp_LIB)(MODVAR.o): MASSYM2.h
$(maslisp_LIB)(MODVAR.o): SACLIST.h

SACSYM.h: MASELEM.h
SACSYM.h: MASSTOR.h

$(maslisp_LIB)(SACSYM.o): SACSYM.c SACSYM.h
$(maslisp_LIB)(SACSYM.o): MASELEM.h
$(maslisp_LIB)(SACSYM.o): MASSTOR.h
$(maslisp_LIB)(SACSYM.o): MASBIOS.h
$(maslisp_LIB)(SACSYM.o): SACLIST.h

SACSYM2.h: MASSTOR.h

$(maslisp_LIB)(SACSYM2.o): SACSYM2.c SACSYM2.h
$(maslisp_LIB)(SACSYM2.o): MASSTOR.h
$(maslisp_LIB)(SACSYM2.o): MASERR.h
$(maslisp_LIB)(SACSYM2.o): SACLIST.h
$(maslisp_LIB)(SACSYM2.o): SACSYM.h

# -EOF-
