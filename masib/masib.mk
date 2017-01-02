# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masib_MD= ADEXTRA.md DIPCJ.md DIPDCIB.md DIPIB.md DIPIIB.md DIPRNIB.md

masib_MI= ADEXTRA.mi DIPCJ.mi DIPDCIB.mi DIPIB.mi DIPIIB.mi DIPRNIB.mi

masib_MDP=

masib_MIP=

masib_CINC=

masib_CSRC=

masib_OBJS=$(masib_CSRC:.c=.o) $(masib_MI:.mi=.o) $(masib_MIP:.mip=.o)

masib_ALLSRC= ADEXTRA.md DIPCJ.md DIPDCIB.md DIPIB.md DIPIIB.md DIPRNIB.md ADEXTRA.mi DIPCJ.mi DIPDCIB.mi DIPIB.mi DIPIIB.mi DIPRNIB.mi

$(top_srcdir)/masib/masib.mk: $(masib_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

ADEXTRA.h: MASSTOR.h

$(masib_LIB)(ADEXTRA.o): ADEXTRA.c ADEXTRA.h
$(masib_LIB)(ADEXTRA.o): DIPC.h
$(masib_LIB)(ADEXTRA.o): DIPCJ.h
$(masib_LIB)(ADEXTRA.o): DIPGB.h
$(masib_LIB)(ADEXTRA.o): DIPIB.h
$(masib_LIB)(ADEXTRA.o): MASADOM.h
$(masib_LIB)(ADEXTRA.o): MASBIOS.h
$(masib_LIB)(ADEXTRA.o): MASSTOR.h
$(masib_LIB)(ADEXTRA.o): SACLIST.h

DIPCJ.h: MASSTOR.h
DIPCJ.h: MASLISPU.h

$(masib_LIB)(DIPCJ.o): DIPCJ.c DIPCJ.h
$(masib_LIB)(DIPCJ.o): DIPADOM.h
$(masib_LIB)(DIPCJ.o): DIPC.h
$(masib_LIB)(DIPCJ.o): DIPI.h
$(masib_LIB)(DIPCJ.o): MASLISPU.h
$(masib_LIB)(DIPCJ.o): MASSTOR.h
$(masib_LIB)(DIPCJ.o): SACLIST.h

DIPDCIB.h: MASSTOR.h

$(masib_LIB)(DIPDCIB.o): DIPDCIB.c DIPDCIB.h
$(masib_LIB)(DIPDCIB.o): ADEXTRA.h
$(masib_LIB)(DIPDCIB.o): DIPADOM.h
$(masib_LIB)(DIPDCIB.o): DIPC.h
$(masib_LIB)(DIPDCIB.o): DIPCJ.h
$(masib_LIB)(DIPDCIB.o): DIPIB.h
$(masib_LIB)(DIPDCIB.o): MASBIOS.h
$(masib_LIB)(DIPDCIB.o): MASERR.h
$(masib_LIB)(DIPDCIB.o): MASLISPU.h
$(masib_LIB)(DIPDCIB.o): MASSTOR.h
$(masib_LIB)(DIPDCIB.o): SACI.h
$(masib_LIB)(DIPDCIB.o): SACLIST.h

DIPIB.h: MASSTOR.h

$(masib_LIB)(DIPIB.o): DIPIB.c DIPIB.h
$(masib_LIB)(DIPIB.o): ADEXTRA.h
$(masib_LIB)(DIPIB.o): DIPADOM.h
$(masib_LIB)(DIPIB.o): DIPC.h
$(masib_LIB)(DIPIB.o): DIPCJ.h
$(masib_LIB)(DIPIB.o): DIPTOOLS.h
$(masib_LIB)(DIPIB.o): MASADOM.h
$(masib_LIB)(DIPIB.o): MASBIOS.h
$(masib_LIB)(DIPIB.o): MASERR.h
$(masib_LIB)(DIPIB.o): MASLISPU.h
$(masib_LIB)(DIPIB.o): MASSTOR.h
$(masib_LIB)(DIPIB.o): SACI.h
$(masib_LIB)(DIPIB.o): SACLIST.h

DIPIIB.h: MASSTOR.h

$(masib_LIB)(DIPIIB.o): DIPIIB.c DIPIIB.h
$(masib_LIB)(DIPIIB.o): DIPC.h
$(masib_LIB)(DIPIIB.o): DIPI.h
$(masib_LIB)(DIPIIB.o): DIPCJ.h
$(masib_LIB)(DIPIIB.o): MASBIOS.h
$(masib_LIB)(DIPIIB.o): MASERR.h
$(masib_LIB)(DIPIIB.o): MASLISPU.h
$(masib_LIB)(DIPIIB.o): MASSTOR.h
$(masib_LIB)(DIPIIB.o): SACI.h
$(masib_LIB)(DIPIIB.o): SACLIST.h

DIPRNIB.h: MASSTOR.h

$(masib_LIB)(DIPRNIB.o): DIPRNIB.c DIPRNIB.h
$(masib_LIB)(DIPRNIB.o): DIPC.h
$(masib_LIB)(DIPRNIB.o): DIPCJ.h
$(masib_LIB)(DIPRNIB.o): DIPRN.h
$(masib_LIB)(DIPRNIB.o): MASADOM.h
$(masib_LIB)(DIPRNIB.o): MASBIOS.h
$(masib_LIB)(DIPRNIB.o): MASSTOR.h
$(masib_LIB)(DIPRNIB.o): SACLIST.h
$(masib_LIB)(DIPRNIB.o): SACRN.h

# -EOF-
