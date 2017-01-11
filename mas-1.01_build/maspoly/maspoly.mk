# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


maspoly_MD= DIPC.md DIPI.md DIPIPOL.md DIPRN.md DIPRNPOL.md DIPTOO.md SACDPOL.md SACIPOL.md SACMPOL.md SACPOL.md SACRPOL.md

maspoly_MI= DIPC.mi DIPI.mi DIPIPOL.mi DIPRN.mi DIPRNPOL.mi DIPTOO.mi SACDPOL.mi SACIPOL.mi SACMPOL.mi SACPOL.mi SACRPOL.mi

maspoly_MDP=

maspoly_MIP=

maspoly_CINC=

maspoly_CSRC=

maspoly_OBJS=$(maspoly_CSRC:.c=.o) $(maspoly_MI:.mi=.o) $(maspoly_MIP:.mip=.o)

maspoly_ALLSRC= DIPC.md DIPI.md DIPIPOL.md DIPRN.md DIPRNPOL.md DIPTOO.md SACDPOL.md SACIPOL.md SACMPOL.md SACPOL.md SACRPOL.md DIPC.mi DIPI.mi DIPIPOL.mi DIPRN.mi DIPRNPOL.mi DIPTOO.mi SACDPOL.mi SACIPOL.mi SACMPOL.mi SACPOL.mi SACRPOL.mi

$(top_srcdir)/maspoly/maspoly.mk: $(maspoly_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

DIPC.h: MASSTOR.h

$(maspoly_LIB)(DIPC.o): DIPC.c DIPC.h
$(maspoly_LIB)(DIPC.o): DIPI.h
$(maspoly_LIB)(DIPC.o): DIPIPOL.h
$(maspoly_LIB)(DIPC.o): DIPTOOLS.h
$(maspoly_LIB)(DIPC.o): MASELEM.h
$(maspoly_LIB)(DIPC.o): MASSTOR.h
$(maspoly_LIB)(DIPC.o): MASERR.h
$(maspoly_LIB)(DIPC.o): SACLIST.h
$(maspoly_LIB)(DIPC.o): MASBIOS.h
$(maspoly_LIB)(DIPC.o): SACCOMB.h
$(maspoly_LIB)(DIPC.o): SACD.h
$(maspoly_LIB)(DIPC.o): SACI.h

DIPI.h: MASSTOR.h

$(maspoly_LIB)(DIPI.o): DIPI.c DIPI.h
$(maspoly_LIB)(DIPI.o): MASELEM.h
$(maspoly_LIB)(DIPI.o): MASSTOR.h
$(maspoly_LIB)(DIPI.o): MASERR.h
$(maspoly_LIB)(DIPI.o): SACLIST.h
$(maspoly_LIB)(DIPI.o): MASBIOS.h
$(maspoly_LIB)(DIPI.o): SACD.h
$(maspoly_LIB)(DIPI.o): SACI.h
$(maspoly_LIB)(DIPI.o): SACRN.h
$(maspoly_LIB)(DIPI.o): SACPOL.h
$(maspoly_LIB)(DIPI.o): DIPC.h
$(maspoly_LIB)(DIPI.o): MASI.h

DIPIPOL.h: MASSTOR.h

$(maspoly_LIB)(DIPIPOL.o): DIPIPOL.c DIPIPOL.h
$(maspoly_LIB)(DIPIPOL.o): MASSTOR.h
$(maspoly_LIB)(DIPIPOL.o): SACLIST.h
$(maspoly_LIB)(DIPIPOL.o): SACD.h
$(maspoly_LIB)(DIPIPOL.o): SACI.h
$(maspoly_LIB)(DIPIPOL.o): SACIPOL.h

DIPRN.h: MASSTOR.h

$(maspoly_LIB)(DIPRN.o): DIPRN.c DIPRN.h
$(maspoly_LIB)(DIPRN.o): MASSTOR.h
$(maspoly_LIB)(DIPRN.o): MASERR.h
$(maspoly_LIB)(DIPRN.o): MASBIOS.h
$(maspoly_LIB)(DIPRN.o): SACLIST.h
$(maspoly_LIB)(DIPRN.o): SACD.h
$(maspoly_LIB)(DIPRN.o): SACI.h
$(maspoly_LIB)(DIPRN.o): SACRN.h
$(maspoly_LIB)(DIPRN.o): SACPOL.h
$(maspoly_LIB)(DIPRN.o): MASRN.h
$(maspoly_LIB)(DIPRN.o): DIPC.h

DIPRNPOL.h: MASSTOR.h

$(maspoly_LIB)(DIPRNPOL.o): DIPRNPOL.c DIPRNPOL.h
$(maspoly_LIB)(DIPRNPOL.o): MASSTOR.h
$(maspoly_LIB)(DIPRNPOL.o): MASBIOS.h
$(maspoly_LIB)(DIPRNPOL.o): SACLIST.h
$(maspoly_LIB)(DIPRNPOL.o): SACI.h
$(maspoly_LIB)(DIPRNPOL.o): SACRN.h
$(maspoly_LIB)(DIPRNPOL.o): MASRN.h
$(maspoly_LIB)(DIPRNPOL.o): SACPOL.h
$(maspoly_LIB)(DIPRNPOL.o): SACRPOL.h

DIPTOO.h: MASSTOR.h

$(maspoly_LIB)(DIPTOO.o): DIPTOO.c DIPTOO.h
$(maspoly_LIB)(DIPTOO.o): MASELEM.h
$(maspoly_LIB)(DIPTOO.o): MASSTOR.h
$(maspoly_LIB)(DIPTOO.o): SACLIST.h
$(maspoly_LIB)(DIPTOO.o): MASBIOS.h
$(maspoly_LIB)(DIPTOO.o): SACD.h
$(maspoly_LIB)(DIPTOO.o): SACI.h
$(maspoly_LIB)(DIPTOO.o): SACRN.h
$(maspoly_LIB)(DIPTOO.o): SACPOL.h
$(maspoly_LIB)(DIPTOO.o): SACIPOL.h
$(maspoly_LIB)(DIPTOO.o): SACCOMB.h
$(maspoly_LIB)(DIPTOO.o): DIPC.h
$(maspoly_LIB)(DIPTOO.o): DIPI.h
$(maspoly_LIB)(DIPTOO.o): SACDPOL.h
$(maspoly_LIB)(DIPTOO.o): LINALGRN.h

SACDPOL.h: MASSTOR.h

$(maspoly_LIB)(SACDPOL.o): SACDPOL.c SACDPOL.h
$(maspoly_LIB)(SACDPOL.o): MASSTOR.h
$(maspoly_LIB)(SACDPOL.o): SACLIST.h
$(maspoly_LIB)(SACDPOL.o): SACM.h
$(maspoly_LIB)(SACDPOL.o): SACPOL.h

SACIPOL.h: MASSTOR.h

$(maspoly_LIB)(SACIPOL.o): SACIPOL.c SACIPOL.h
$(maspoly_LIB)(SACIPOL.o): MASELEM.h
$(maspoly_LIB)(SACIPOL.o): MASSTOR.h
$(maspoly_LIB)(SACIPOL.o): SACLIST.h
$(maspoly_LIB)(SACIPOL.o): MASBIOS.h
$(maspoly_LIB)(SACIPOL.o): SACD.h
$(maspoly_LIB)(SACIPOL.o): SACM.h
$(maspoly_LIB)(SACIPOL.o): SACI.h
$(maspoly_LIB)(SACIPOL.o): SACPOL.h

SACMPOL.h: MASSTOR.h

$(maspoly_LIB)(SACMPOL.o): SACMPOL.c SACMPOL.h
$(maspoly_LIB)(SACMPOL.o): MASELEM.h
$(maspoly_LIB)(SACMPOL.o): MASSTOR.h
$(maspoly_LIB)(SACMPOL.o): SACLIST.h
$(maspoly_LIB)(SACMPOL.o): SACD.h
$(maspoly_LIB)(SACMPOL.o): SACM.h
$(maspoly_LIB)(SACMPOL.o): SACI.h
$(maspoly_LIB)(SACMPOL.o): SACPOL.h
$(maspoly_LIB)(SACMPOL.o): SACIPOL.h

SACPOL.h: MASSTOR.h

$(maspoly_LIB)(SACPOL.o): SACPOL.c SACPOL.h
$(maspoly_LIB)(SACPOL.o): MASELEM.h
$(maspoly_LIB)(SACPOL.o): MASSTOR.h
$(maspoly_LIB)(SACPOL.o): SACLIST.h
$(maspoly_LIB)(SACPOL.o): MASBIOS.h
$(maspoly_LIB)(SACPOL.o): SACPRIM.h

SACRPOL.h: MASSTOR.h

$(maspoly_LIB)(SACRPOL.o): SACRPOL.c SACRPOL.h
$(maspoly_LIB)(SACRPOL.o): MASELEM.h
$(maspoly_LIB)(SACRPOL.o): MASSTOR.h
$(maspoly_LIB)(SACRPOL.o): SACLIST.h
$(maspoly_LIB)(SACRPOL.o): MASBIOS.h
$(maspoly_LIB)(SACRPOL.o): SACI.h
$(maspoly_LIB)(SACRPOL.o): SACRN.h
$(maspoly_LIB)(SACRPOL.o): SACPOL.h

# -EOF-
