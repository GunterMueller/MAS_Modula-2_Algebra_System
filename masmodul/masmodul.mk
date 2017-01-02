# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masmodul_MD= GSYMFUIN.md GSYMFURN.md GSYMINP.md LINALGI.md LINALGRN.md NOETHER.md SACLDIO.md SUBST.md SYMMFU.md SYZFUNC.md SYZGB.md SYZHLP.md SYZMAIN.md TIPRNGB.md

masmodul_MI= GSYMFUIN.mi GSYMFURN.mi GSYMINP.mi LINALGI.mi LINALGRN.mi NOETHER.mi SACLDIO.mi SUBST.mi SYMMFU.mi SYZFUNC.mi SYZGB.mi SYZHLP.mi SYZMAIN.mi TIPRNGB.mi

masmodul_MDP=

masmodul_MIP=

masmodul_CINC=

masmodul_CSRC=

masmodul_OBJS=$(masmodul_CSRC:.c=.o) $(masmodul_MI:.mi=.o) $(masmodul_MIP:.mip=.o)

masmodul_ALLSRC= GSYMFUIN.md GSYMFURN.md GSYMINP.md LINALGI.md LINALGRN.md NOETHER.md SACLDIO.md SUBST.md SYMMFU.md SYZFUNC.md SYZGB.md SYZHLP.md SYZMAIN.md TIPRNGB.md GSYMFUIN.mi GSYMFURN.mi GSYMINP.mi LINALGI.mi LINALGRN.mi NOETHER.mi SACLDIO.mi SUBST.mi SYMMFU.mi SYZFUNC.mi SYZGB.mi SYZHLP.mi SYZMAIN.mi TIPRNGB.mi

$(top_srcdir)/masmodul/masmodul.mk: $(masmodul_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

GSYMFUIN.h: MASSTOR.h
GSYMFUIN.h: MASELEM.h

$(masmodul_LIB)(GSYMFUIN.o): GSYMFUIN.c GSYMFUIN.h
$(masmodul_LIB)(GSYMFUIN.o): MASELEM.h
$(masmodul_LIB)(GSYMFUIN.o): MASSTOR.h
$(masmodul_LIB)(GSYMFUIN.o): MASBIOS.h
$(masmodul_LIB)(GSYMFUIN.o): SACLIST.h
$(masmodul_LIB)(GSYMFUIN.o): SACSET.h
$(masmodul_LIB)(GSYMFUIN.o): SACLDIO.h
$(masmodul_LIB)(GSYMFUIN.o): DIPI.h
$(masmodul_LIB)(GSYMFUIN.o): DIPC.h

GSYMFURN.h: MASSTOR.h
GSYMFURN.h: MASELEM.h

$(masmodul_LIB)(GSYMFURN.o): GSYMFURN.c GSYMFURN.h
$(masmodul_LIB)(GSYMFURN.o): MASELEM.h
$(masmodul_LIB)(GSYMFURN.o): MASSTOR.h
$(masmodul_LIB)(GSYMFURN.o): MASBIOS.h
$(masmodul_LIB)(GSYMFURN.o): SACLIST.h
$(masmodul_LIB)(GSYMFURN.o): SACSET.h
$(masmodul_LIB)(GSYMFURN.o): SACRN.h
$(masmodul_LIB)(GSYMFURN.o): LINALGRN.h
$(masmodul_LIB)(GSYMFURN.o): DIPC.h
$(masmodul_LIB)(GSYMFURN.o): DIPRN.h
$(masmodul_LIB)(GSYMFURN.o): DIPRNGB.h
$(masmodul_LIB)(GSYMFURN.o): GSYMFUIN.h

GSYMINP.h: MASSTOR.h

$(masmodul_LIB)(GSYMINP.o): GSYMINP.c GSYMINP.h
$(masmodul_LIB)(GSYMINP.o): DIPC.h
$(masmodul_LIB)(GSYMINP.o): DIPI.h
$(masmodul_LIB)(GSYMINP.o): DIPRN.h
$(masmodul_LIB)(GSYMINP.o): MASBIOS.h
$(masmodul_LIB)(GSYMINP.o): MASSTOR.h
$(masmodul_LIB)(GSYMINP.o): SACPOL.h

LINALGI.h: MASSTOR.h

$(masmodul_LIB)(LINALGI.o): LINALGI.c LINALGI.h
$(masmodul_LIB)(LINALGI.o): MASELEM.h
$(masmodul_LIB)(LINALGI.o): MASBIOS.h
$(masmodul_LIB)(LINALGI.o): MASSTOR.h
$(masmodul_LIB)(LINALGI.o): MASERR.h
$(masmodul_LIB)(LINALGI.o): SACLIST.h
$(masmodul_LIB)(LINALGI.o): SACI.h
$(masmodul_LIB)(LINALGI.o): SACRN.h
$(masmodul_LIB)(LINALGI.o): LINALGRN.h

LINALGRN.h: MASSTOR.h

$(masmodul_LIB)(LINALGRN.o): LINALGRN.c LINALGRN.h
$(masmodul_LIB)(LINALGRN.o): MASELEM.h
$(masmodul_LIB)(LINALGRN.o): MASBIOS.h
$(masmodul_LIB)(LINALGRN.o): MASSTOR.h
$(masmodul_LIB)(LINALGRN.o): MASERR.h
$(masmodul_LIB)(LINALGRN.o): SACLIST.h
$(masmodul_LIB)(LINALGRN.o): SACRN.h
$(masmodul_LIB)(LINALGRN.o): MASRN.h
$(masmodul_LIB)(LINALGRN.o): MASAPF.h

NOETHER.h: MASSTOR.h
NOETHER.h: MASELEM.h

$(masmodul_LIB)(NOETHER.o): NOETHER.c NOETHER.h
$(masmodul_LIB)(NOETHER.o): MASELEM.h
$(masmodul_LIB)(NOETHER.o): MASSTOR.h
$(masmodul_LIB)(NOETHER.o): MASBIOS.h
$(masmodul_LIB)(NOETHER.o): SACLIST.h
$(masmodul_LIB)(NOETHER.o): SACSET.h
$(masmodul_LIB)(NOETHER.o): SACRN.h
$(masmodul_LIB)(NOETHER.o): DIPRN.h
$(masmodul_LIB)(NOETHER.o): DIPC.h
$(masmodul_LIB)(NOETHER.o): GSYMFUIN.h
$(masmodul_LIB)(NOETHER.o): GSYMFURN.h

SACLDIO.h: MASSTOR.h

$(masmodul_LIB)(SACLDIO.o): SACLDIO.c SACLDIO.h
$(masmodul_LIB)(SACLDIO.o): MASELEM.h
$(masmodul_LIB)(SACLDIO.o): MASSTOR.h
$(masmodul_LIB)(SACLDIO.o): MASERR.h
$(masmodul_LIB)(SACLDIO.o): MASBIOS.h
$(masmodul_LIB)(SACLDIO.o): SACLIST.h
$(masmodul_LIB)(SACLDIO.o): SACD.h
$(masmodul_LIB)(SACLDIO.o): SACI.h
$(masmodul_LIB)(SACLDIO.o): SACM.h
$(masmodul_LIB)(SACLDIO.o): SACPRIM.h
$(masmodul_LIB)(SACLDIO.o): SACCOMB.h
$(masmodul_LIB)(SACLDIO.o): SACPOL.h
$(masmodul_LIB)(SACLDIO.o): SACIPOL.h
$(masmodul_LIB)(SACLDIO.o): SACMPOL.h

SUBST.h: MASSTOR.h
SUBST.h: MASELEM.h

$(masmodul_LIB)(SUBST.o): SUBST.c SUBST.h
$(masmodul_LIB)(SUBST.o): MASELEM.h
$(masmodul_LIB)(SUBST.o): MASSTOR.h
$(masmodul_LIB)(SUBST.o): MASBIOS.h
$(masmodul_LIB)(SUBST.o): SACLIST.h
$(masmodul_LIB)(SUBST.o): SACRN.h
$(masmodul_LIB)(SUBST.o): LINALGRN.h
$(masmodul_LIB)(SUBST.o): DIPRN.h
$(masmodul_LIB)(SUBST.o): DIPC.h
$(masmodul_LIB)(SUBST.o): GSYMFUIN.h
$(masmodul_LIB)(SUBST.o): GSYMFURN.h
$(masmodul_LIB)(SUBST.o): NOETHER.h

SYMMFU.h: MASSTOR.h

$(masmodul_LIB)(SYMMFU.o): SYMMFU.c SYMMFU.h
$(masmodul_LIB)(SYMMFU.o): MASSTOR.h
$(masmodul_LIB)(SYMMFU.o): MASBIOS.h
$(masmodul_LIB)(SYMMFU.o): SACLIST.h
$(masmodul_LIB)(SYMMFU.o): SACRN.h
$(masmodul_LIB)(SYMMFU.o): DIPC.h
$(masmodul_LIB)(SYMMFU.o): DIPRN.h

SYZFUNC.h: MASSTOR.h

$(masmodul_LIB)(SYZFUNC.o): SYZFUNC.c SYZFUNC.h
$(masmodul_LIB)(SYZFUNC.o): DIPC.h
$(masmodul_LIB)(SYZFUNC.o): DIPRN.h
$(masmodul_LIB)(SYZFUNC.o): DIPRNGB.h
$(masmodul_LIB)(SYZFUNC.o): MASBIOS.h
$(masmodul_LIB)(SYZFUNC.o): MASNC.h
$(masmodul_LIB)(SYZFUNC.o): MASNCGB.h
$(masmodul_LIB)(SYZFUNC.o): MASSTOR.h
$(masmodul_LIB)(SYZFUNC.o): SACLIST.h
$(masmodul_LIB)(SYZFUNC.o): SACRN.h
$(masmodul_LIB)(SYZFUNC.o): SYZHLP.h

SYZGB.h: MASSTOR.h

$(masmodul_LIB)(SYZGB.o): SYZGB.c SYZGB.h
$(masmodul_LIB)(SYZGB.o): DIPC.h
$(masmodul_LIB)(SYZGB.o): DIPRN.h
$(masmodul_LIB)(SYZGB.o): DIPRNGB.h
$(masmodul_LIB)(SYZGB.o): MASBIOS.h
$(masmodul_LIB)(SYZGB.o): MASNC.h
$(masmodul_LIB)(SYZGB.o): MASNCGB.h
$(masmodul_LIB)(SYZGB.o): MASSTOR.h
$(masmodul_LIB)(SYZGB.o): SACLIST.h
$(masmodul_LIB)(SYZGB.o): SYZFUNC.h
$(masmodul_LIB)(SYZGB.o): SYZHLP.h

SYZHLP.h: MASSTOR.h

$(masmodul_LIB)(SYZHLP.o): SYZHLP.c SYZHLP.h
$(masmodul_LIB)(SYZHLP.o): DIPC.h
$(masmodul_LIB)(SYZHLP.o): DIPRN.h
$(masmodul_LIB)(SYZHLP.o): MASBIOS.h
$(masmodul_LIB)(SYZHLP.o): MASNC.h
$(masmodul_LIB)(SYZHLP.o): MASSTOR.h
$(masmodul_LIB)(SYZHLP.o): SACLIST.h
$(masmodul_LIB)(SYZHLP.o): SACPOL.h

SYZMAIN.h: MASSTOR.h

$(masmodul_LIB)(SYZMAIN.o): SYZMAIN.c SYZMAIN.h
$(masmodul_LIB)(SYZMAIN.o): DIPRN.h
$(masmodul_LIB)(SYZMAIN.o): DIPRNGB.h
$(masmodul_LIB)(SYZMAIN.o): MASBIOS.h
$(masmodul_LIB)(SYZMAIN.o): MASNC.h
$(masmodul_LIB)(SYZMAIN.o): MASNCGB.h
$(masmodul_LIB)(SYZMAIN.o): MASSTOR.h
$(masmodul_LIB)(SYZMAIN.o): SACLIST.h
$(masmodul_LIB)(SYZMAIN.o): SYZFUNC.h
$(masmodul_LIB)(SYZMAIN.o): SYZGB.h
$(masmodul_LIB)(SYZMAIN.o): SYZHLP.h

TIPRNGB.h: MASSTOR.h

$(masmodul_LIB)(TIPRNGB.o): TIPRNGB.c TIPRNGB.h
$(masmodul_LIB)(TIPRNGB.o): MASSTOR.h
$(masmodul_LIB)(TIPRNGB.o): SACLIST.h
$(masmodul_LIB)(TIPRNGB.o): MASBIOS.h
$(masmodul_LIB)(TIPRNGB.o): SACRN.h
$(masmodul_LIB)(TIPRNGB.o): DIPC.h
$(masmodul_LIB)(TIPRNGB.o): DIPRN.h
$(masmodul_LIB)(TIPRNGB.o): DIPRNGB.h

# -EOF-
