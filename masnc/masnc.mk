# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masnc_MD= DINNGB.md DIPE.md MASNC.md MASNCC.md MASNCGB.md

masnc_MI= DINNGB.mi DIPE.mi MASNC.mi MASNCC.mi MASNCGB.mi

masnc_MDP=

masnc_MIP=

masnc_CINC=

masnc_CSRC=

masnc_OBJS=$(masnc_CSRC:.c=.o) $(masnc_MI:.mi=.o) $(masnc_MIP:.mip=.o)

masnc_ALLSRC= DINNGB.md DIPE.md MASNC.md MASNCC.md MASNCGB.md DINNGB.mi DIPE.mi MASNC.mi MASNCC.mi MASNCGB.mi

$(top_srcdir)/masnc/masnc.mk: $(masnc_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

DINNGB.h: MASSTOR.h

$(masnc_LIB)(DINNGB.o): DINNGB.c DINNGB.h
$(masnc_LIB)(DINNGB.o): MASSTOR.h
$(masnc_LIB)(DINNGB.o): SACLIST.h
$(masnc_LIB)(DINNGB.o): SACPOL.h
$(masnc_LIB)(DINNGB.o): MASBIOS.h
$(masnc_LIB)(DINNGB.o): DIPRN.h
$(masnc_LIB)(DINNGB.o): SACRN.h
$(masnc_LIB)(DINNGB.o): DIPRNGB.h
$(masnc_LIB)(DINNGB.o): DIPC.h
$(masnc_LIB)(DINNGB.o): SACI.h
$(masnc_LIB)(DINNGB.o): MASNC.h

DIPE.h: MASSTOR.h

$(masnc_LIB)(DIPE.o): DIPE.c DIPE.h
$(masnc_LIB)(DIPE.o): MASELEM.h
$(masnc_LIB)(DIPE.o): MASSTOR.h
$(masnc_LIB)(DIPE.o): MASERR.h
$(masnc_LIB)(DIPE.o): SACLIST.h
$(masnc_LIB)(DIPE.o): MASBIOS.h
$(masnc_LIB)(DIPE.o): SACD.h
$(masnc_LIB)(DIPE.o): SACI.h
$(masnc_LIB)(DIPE.o): SACM.h
$(masnc_LIB)(DIPE.o): SACPRIM.h
$(masnc_LIB)(DIPE.o): MASI.h
$(masnc_LIB)(DIPE.o): SACPOL.h
$(masnc_LIB)(DIPE.o): SACIPOL.h
$(masnc_LIB)(DIPE.o): DIPI.h

MASNC.h: MASSTOR.h

$(masnc_LIB)(MASNC.o): MASNC.c MASNC.h
$(masnc_LIB)(MASNC.o): MASSTOR.h
$(masnc_LIB)(MASNC.o): MASERR.h
$(masnc_LIB)(MASNC.o): SACLIST.h
$(masnc_LIB)(MASNC.o): MASBIOS.h
$(masnc_LIB)(MASNC.o): SACRN.h
$(masnc_LIB)(MASNC.o): SACPOL.h
$(masnc_LIB)(MASNC.o): DIPC.h
$(masnc_LIB)(MASNC.o): MASRN.h
$(masnc_LIB)(MASNC.o): DIPRN.h

MASNCC.h: MASSTOR.h

$(masnc_LIB)(MASNCC.o): MASNCC.c MASNCC.h
$(masnc_LIB)(MASNCC.o): MASSTOR.h
$(masnc_LIB)(MASNCC.o): MASBIOS.h
$(masnc_LIB)(MASNCC.o): SACLIST.h
$(masnc_LIB)(MASNCC.o): SACSET.h
$(masnc_LIB)(MASNCC.o): SACRN.h
$(masnc_LIB)(MASNCC.o): MASRN.h
$(masnc_LIB)(MASNCC.o): SACPOL.h
$(masnc_LIB)(MASNCC.o): SACRPOL.h
$(masnc_LIB)(MASNCC.o): DIPC.h
$(masnc_LIB)(MASNCC.o): DIPTOO.h
$(masnc_LIB)(MASNCC.o): DIPRN.h
$(masnc_LIB)(MASNCC.o): DIPRNGB.h
$(masnc_LIB)(MASNCC.o): DIPDIM.h
$(masnc_LIB)(MASNCC.o): MASNC.h
$(masnc_LIB)(MASNCC.o): MASNCGB.h

MASNCGB.h: MASSTOR.h

$(masnc_LIB)(MASNCGB.o): MASNCGB.c MASNCGB.h
$(masnc_LIB)(MASNCGB.o): MASSTOR.h
$(masnc_LIB)(MASNCGB.o): MASERR.h
$(masnc_LIB)(MASNCGB.o): SACLIST.h
$(masnc_LIB)(MASNCGB.o): MASBIOS.h
$(masnc_LIB)(MASNCGB.o): SACRN.h
$(masnc_LIB)(MASNCGB.o): DIPC.h
$(masnc_LIB)(MASNCGB.o): DIPRN.h
$(masnc_LIB)(MASNCGB.o): DIPRNGB.h
$(masnc_LIB)(MASNCGB.o): MASNC.h

# -EOF-
