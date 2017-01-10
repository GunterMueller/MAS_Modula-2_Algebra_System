# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masroot_MD= LINALG.md RRADOM.md RRINT.md RRUADOM.md RRUINT.md

masroot_MI= LINALG.mi RRADOM.mi RRINT.mi RRUADOM.mi RRUINT.mi

masroot_MDP=

masroot_MIP=

masroot_CINC=

masroot_CSRC=

masroot_OBJS=$(masroot_CSRC:.c=.o) $(masroot_MI:.mi=.o) $(masroot_MIP:.mip=.o)

masroot_ALLSRC= LINALG.md RRADOM.md RRINT.md RRUADOM.md RRUINT.md LINALG.mi RRADOM.mi RRINT.mi RRUADOM.mi RRUINT.mi

$(top_srcdir)/masroot/masroot.mk: $(masroot_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

LINALG.h: MASSTOR.h

$(masroot_LIB)(LINALG.o): LINALG.c LINALG.h
$(masroot_LIB)(LINALG.o): MASSTOR.h
$(masroot_LIB)(LINALG.o): SACLIST.h
$(masroot_LIB)(LINALG.o): MASADOM.h
$(masroot_LIB)(LINALG.o): SACI.h
$(masroot_LIB)(LINALG.o): MASBIOS.h
$(masroot_LIB)(LINALG.o): LINALGI.h
$(masroot_LIB)(LINALG.o): LINALGRN.h
$(masroot_LIB)(LINALG.o): MASI.h

RRADOM.h: MASSTOR.h

$(masroot_LIB)(RRADOM.o): RRADOM.c RRADOM.h
$(masroot_LIB)(RRADOM.o): MASSTOR.h
$(masroot_LIB)(RRADOM.o): SACLIST.h
$(masroot_LIB)(RRADOM.o): DIPC.h
$(masroot_LIB)(RRADOM.o): DIPADOM.h
$(masroot_LIB)(RRADOM.o): MASADOM.h
$(masroot_LIB)(RRADOM.o): MASELEM.h
$(masroot_LIB)(RRADOM.o): MASBIOS.h
$(masroot_LIB)(RRADOM.o): SACI.h
$(masroot_LIB)(RRADOM.o): SACRN.h
$(masroot_LIB)(RRADOM.o): LINALG.h
$(masroot_LIB)(RRADOM.o): LINALGI.h
$(masroot_LIB)(RRADOM.o): LINALGRN.h

RRINT.h: MASSTOR.h

$(masroot_LIB)(RRINT.o): RRINT.c RRINT.h
$(masroot_LIB)(RRINT.o): MASSTOR.h
$(masroot_LIB)(RRINT.o): SACLIST.h
$(masroot_LIB)(RRINT.o): MASELEM.h
$(masroot_LIB)(RRINT.o): MASBIOS.h
$(masroot_LIB)(RRINT.o): MASI.h
$(masroot_LIB)(RRINT.o): SACI.h
$(masroot_LIB)(RRINT.o): DIPI.h
$(masroot_LIB)(RRINT.o): DIPC.h
$(masroot_LIB)(RRINT.o): LINALGI.h
$(masroot_LIB)(RRINT.o): LINALGRN.h
$(masroot_LIB)(RRINT.o): LINALG.h
$(masroot_LIB)(RRINT.o): RRADOM.h

RRUADOM.h: MASSTOR.h

$(masroot_LIB)(RRUADOM.o): RRUADOM.c RRUADOM.h
$(masroot_LIB)(RRUADOM.o): MASSTOR.h
$(masroot_LIB)(RRUADOM.o): SACLIST.h
$(masroot_LIB)(RRUADOM.o): DIPC.h
$(masroot_LIB)(RRUADOM.o): DIPADOM.h
$(masroot_LIB)(RRUADOM.o): MASBIOS.h
$(masroot_LIB)(RRUADOM.o): MASADOM.h
$(masroot_LIB)(RRUADOM.o): LINALG.h
$(masroot_LIB)(RRUADOM.o): RRADOM.h

RRUINT.h: MASSTOR.h

$(masroot_LIB)(RRUINT.o): RRUINT.c RRUINT.h
$(masroot_LIB)(RRUINT.o): MASBIOS.h
$(masroot_LIB)(RRUINT.o): MASSTOR.h
$(masroot_LIB)(RRUINT.o): SACLIST.h
$(masroot_LIB)(RRUINT.o): SACI.h
$(masroot_LIB)(RRUINT.o): DIPC.h
$(masroot_LIB)(RRUINT.o): DIPI.h
$(masroot_LIB)(RRUINT.o): LINALG.h
$(masroot_LIB)(RRUINT.o): LINALGRN.h
$(masroot_LIB)(RRUINT.o): RRINT.h
$(masroot_LIB)(RRUINT.o): RRADOM.h

# -EOF-
