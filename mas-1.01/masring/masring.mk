# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masring_MD= DIPDEC0.md DIPDIM.md DIPGCD.md DIPIDEAL.md DIPIDGB.md DIPIGB.md DIPRF.md DIPRNGB.md DIPROOT.md DIPZ.md MASFF.md MASPGCD.md MASUGB.md

masring_MI= DIPDEC0.mi DIPDIM.mi DIPGCD.mi DIPIDEAL.mi DIPIDGB.mi DIPIGB.mi DIPRF.mi DIPRNGB.mi DIPROOT.mi DIPZ.mi MASFF.mi MASPGCD.mi MASUGB.mi

masring_MDP=

masring_MIP=

masring_CINC=

masring_CSRC=

masring_OBJS=$(masring_CSRC:.c=.o) $(masring_MI:.mi=.o) $(masring_MIP:.mip=.o)

masring_ALLSRC= DIPDEC0.md DIPDIM.md DIPGCD.md DIPIDEAL.md DIPIDGB.md DIPIGB.md DIPRF.md DIPRNGB.md DIPROOT.md DIPZ.md MASFF.md MASPGCD.md MASUGB.md DIPDEC0.mi DIPDIM.mi DIPGCD.mi DIPIDEAL.mi DIPIDGB.mi DIPIGB.mi DIPRF.mi DIPRNGB.mi DIPROOT.mi DIPZ.mi MASFF.mi MASPGCD.mi MASUGB.mi

$(top_srcdir)/masring/masring.mk: $(masring_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

DIPDEC0.h: MASSTOR.h

$(masring_LIB)(DIPDEC0.o): DIPDEC0.c DIPDEC0.h
$(masring_LIB)(DIPDEC0.o): MASSTOR.h
$(masring_LIB)(DIPDEC0.o): MASERR.h
$(masring_LIB)(DIPDEC0.o): MASBIOS.h
$(masring_LIB)(DIPDEC0.o): SACLIST.h
$(masring_LIB)(DIPDEC0.o): SACSET.h
$(masring_LIB)(DIPDEC0.o): SACCOMB.h
$(masring_LIB)(DIPDEC0.o): SACPOL.h
$(masring_LIB)(DIPDEC0.o): SACRN.h
$(masring_LIB)(DIPDEC0.o): DIPC.h
$(masring_LIB)(DIPDEC0.o): DIPTOO.h
$(masring_LIB)(DIPDEC0.o): DIPI.h
$(masring_LIB)(DIPDEC0.o): DIPRN.h
$(masring_LIB)(DIPDEC0.o): DIPRNGB.h
$(masring_LIB)(DIPDEC0.o): DIPIDEAL.h
$(masring_LIB)(DIPDEC0.o): DIPZ.h
$(masring_LIB)(DIPDEC0.o): DIPDIM.h
$(masring_LIB)(DIPDEC0.o): SACUPFAC.h

DIPDIM.h: MASSTOR.h

$(masring_LIB)(DIPDIM.o): DIPDIM.c DIPDIM.h
$(masring_LIB)(DIPDIM.o): MASSTOR.h
$(masring_LIB)(DIPDIM.o): SACLIST.h
$(masring_LIB)(DIPDIM.o): MASBIOS.h
$(masring_LIB)(DIPDIM.o): DIPC.h
$(masring_LIB)(DIPDIM.o): SACPOL.h

DIPGCD.h: MASSTOR.h

$(masring_LIB)(DIPGCD.o): DIPGCD.c DIPGCD.h
$(masring_LIB)(DIPGCD.o): MASSTOR.h
$(masring_LIB)(DIPGCD.o): SACLIST.h
$(masring_LIB)(DIPGCD.o): SACIPOL.h
$(masring_LIB)(DIPGCD.o): SACPGCD.h
$(masring_LIB)(DIPGCD.o): SACPFAC.h
$(masring_LIB)(DIPGCD.o): DIPC.h
$(masring_LIB)(DIPGCD.o): DIPI.h
$(masring_LIB)(DIPGCD.o): DIPRN.h

DIPIDEAL.h: MASSTOR.h

$(masring_LIB)(DIPIDEAL.o): DIPIDEAL.c DIPIDEAL.h
$(masring_LIB)(DIPIDEAL.o): MASSTOR.h
$(masring_LIB)(DIPIDEAL.o): MASERR.h
$(masring_LIB)(DIPIDEAL.o): SACLIST.h
$(masring_LIB)(DIPIDEAL.o): SACPOL.h
$(masring_LIB)(DIPIDEAL.o): DIPC.h
$(masring_LIB)(DIPIDEAL.o): DIPTOO.h
$(masring_LIB)(DIPIDEAL.o): DIPRN.h
$(masring_LIB)(DIPIDEAL.o): DIPRNGB.h

DIPIDGB.h: MASSTOR.h

$(masring_LIB)(DIPIDGB.o): DIPIDGB.c DIPIDGB.h
$(masring_LIB)(DIPIDGB.o): MASSTOR.h
$(masring_LIB)(DIPIDGB.o): SACLIST.h
$(masring_LIB)(DIPIDGB.o): MASBIOS.h
$(masring_LIB)(DIPIDGB.o): SACI.h
$(masring_LIB)(DIPIDGB.o): DIPC.h
$(masring_LIB)(DIPIDGB.o): DIPI.h

DIPIGB.h: MASSTOR.h

$(masring_LIB)(DIPIGB.o): DIPIGB.c DIPIGB.h
$(masring_LIB)(DIPIGB.o): MASSTOR.h
$(masring_LIB)(DIPIGB.o): SACLIST.h
$(masring_LIB)(DIPIGB.o): MASBIOS.h
$(masring_LIB)(DIPIGB.o): SACI.h
$(masring_LIB)(DIPIGB.o): SACRN.h
$(masring_LIB)(DIPIGB.o): DIPC.h
$(masring_LIB)(DIPIGB.o): DIPI.h
$(masring_LIB)(DIPIGB.o): DIPRNGB.h

DIPRF.h: MASSTOR.h

$(masring_LIB)(DIPRF.o): DIPRF.c DIPRF.h
$(masring_LIB)(DIPRF.o): MASSTOR.h
$(masring_LIB)(DIPRF.o): MASERR.h
$(masring_LIB)(DIPRF.o): MASBIOS.h
$(masring_LIB)(DIPRF.o): SACLIST.h
$(masring_LIB)(DIPRF.o): SACI.h
$(masring_LIB)(DIPRF.o): SACPOL.h
$(masring_LIB)(DIPRF.o): SACIPOL.h
$(masring_LIB)(DIPRF.o): DIPC.h
$(masring_LIB)(DIPRF.o): DIPI.h
$(masring_LIB)(DIPRF.o): SACPGCD.h

DIPRNGB.h: MASSTOR.h

$(masring_LIB)(DIPRNGB.o): DIPRNGB.c DIPRNGB.h
$(masring_LIB)(DIPRNGB.o): MASSTOR.h
$(masring_LIB)(DIPRNGB.o): SACLIST.h
$(masring_LIB)(DIPRNGB.o): MASBIOS.h
$(masring_LIB)(DIPRNGB.o): SACRN.h
$(masring_LIB)(DIPRNGB.o): DIPC.h
$(masring_LIB)(DIPRNGB.o): DIPRN.h

DIPROOT.h: MASSTOR.h

$(masring_LIB)(DIPROOT.o): DIPROOT.c DIPROOT.h
$(masring_LIB)(DIPROOT.o): MASSTOR.h
$(masring_LIB)(DIPROOT.o): MASERR.h
$(masring_LIB)(DIPROOT.o): MASBIOS.h
$(masring_LIB)(DIPROOT.o): SACLIST.h
$(masring_LIB)(DIPROOT.o): SACSET.h
$(masring_LIB)(DIPROOT.o): SACI.h
$(masring_LIB)(DIPROOT.o): SACRN.h
$(masring_LIB)(DIPROOT.o): MASRN.h
$(masring_LIB)(DIPROOT.o): SACPOL.h
$(masring_LIB)(DIPROOT.o): DIPC.h
$(masring_LIB)(DIPROOT.o): DIPRN.h
$(masring_LIB)(DIPROOT.o): DIPRNGB.h
$(masring_LIB)(DIPROOT.o): SACROOT.h
$(masring_LIB)(DIPROOT.o): SACANF.h
$(masring_LIB)(DIPROOT.o): DIPIDEAL.h
$(masring_LIB)(DIPROOT.o): DIPDEC0.h

DIPZ.h: MASSTOR.h

$(masring_LIB)(DIPZ.o): DIPZ.c DIPZ.h
$(masring_LIB)(DIPZ.o): MASSTOR.h
$(masring_LIB)(DIPZ.o): MASBIOS.h
$(masring_LIB)(DIPZ.o): SACLIST.h
$(masring_LIB)(DIPZ.o): SACRN.h
$(masring_LIB)(DIPZ.o): SACPOL.h
$(masring_LIB)(DIPZ.o): SACRPOL.h
$(masring_LIB)(DIPZ.o): DIPC.h
$(masring_LIB)(DIPZ.o): DIPRN.h
$(masring_LIB)(DIPZ.o): DIPRNGB.h
$(masring_LIB)(DIPZ.o): DIPDIM.h

MASFF.h: MASSTOR.h

$(masring_LIB)(MASFF.o): MASFF.c MASFF.h
$(masring_LIB)(MASFF.o): MASSTOR.h
$(masring_LIB)(MASFF.o): SACLIST.h
$(masring_LIB)(MASFF.o): SACM.h
$(masring_LIB)(MASFF.o): SACRN.h
$(masring_LIB)(MASFF.o): SACPOL.h
$(masring_LIB)(MASFF.o): SACIPOL.h
$(masring_LIB)(MASFF.o): SACMPOL.h
$(masring_LIB)(MASFF.o): DIPC.h
$(masring_LIB)(MASFF.o): DIPI.h

MASPGCD.h: MASSTOR.h

$(masring_LIB)(MASPGCD.o): MASPGCD.c MASPGCD.h
$(masring_LIB)(MASPGCD.o): MASSTOR.h
$(masring_LIB)(MASPGCD.o): SACEXT4.h
$(masring_LIB)(MASPGCD.o): SACIPOL.h
$(masring_LIB)(MASPGCD.o): SACLIST.h
$(masring_LIB)(MASPGCD.o): SACPGCD.h

MASUGB.h: MASSTOR.h

$(masring_LIB)(MASUGB.o): MASUGB.c MASUGB.h
$(masring_LIB)(MASUGB.o): MASSTOR.h
$(masring_LIB)(MASUGB.o): MASERR.h
$(masring_LIB)(MASUGB.o): MASBIOS.h
$(masring_LIB)(MASUGB.o): SACLIST.h
$(masring_LIB)(MASUGB.o): SACRN.h
$(masring_LIB)(MASUGB.o): MASRN.h
$(masring_LIB)(MASUGB.o): SACI.h
$(masring_LIB)(MASUGB.o): SACPOL.h
$(masring_LIB)(MASUGB.o): SACSET.h
$(masring_LIB)(MASUGB.o): DIPC.h
$(masring_LIB)(MASUGB.o): DIPRN.h
$(masring_LIB)(MASUGB.o): DIPRNGB.h
$(masring_LIB)(MASUGB.o): MASSYM2.h
$(masring_LIB)(MASUGB.o): MASELEM.h

# -EOF-
