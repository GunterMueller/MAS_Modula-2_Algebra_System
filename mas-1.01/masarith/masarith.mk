# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masarith_MD= MASAPF.md MASC.md MASCOMB.md MASF.md MASI.md MASO.md MASQ.md MASRN.md MASSET.md MathLib.md SACCOMB.md SACD.md SACI.md SACM.md SACPRIM.md SACRN.md SACSET.md

masarith_MI= MASAPF.mi MASC.mi MASCOMB.mi MASF.mi MASI.mi MASO.mi MASQ.mi MASRN.mi MASSET.mi MathLib.mi SACCOMB.mi SACD.mi SACI.mi SACM.mi SACPRIM.mi SACRN.mi SACSET.mi

masarith_MDP=

masarith_MIP=

masarith_CINC=

masarith_CSRC=

masarith_OBJS=$(masarith_CSRC:.c=.o) $(masarith_MI:.mi=.o) $(masarith_MIP:.mip=.o)

masarith_ALLSRC= MASAPF.md MASC.md MASCOMB.md MASF.md MASI.md MASO.md MASQ.md MASRN.md MASSET.md MathLib.md SACCOMB.md SACD.md SACI.md SACM.md SACPRIM.md SACRN.md SACSET.md MASAPF.mi MASC.mi MASCOMB.mi MASF.mi MASI.mi MASO.mi MASQ.mi MASRN.mi MASSET.mi MathLib.mi SACCOMB.mi SACD.mi SACI.mi SACM.mi SACPRIM.mi SACRN.mi SACSET.mi

$(top_srcdir)/masarith/masarith.mk: $(masarith_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

MASAPF.h: MASSTOR.h

$(masarith_LIB)(MASAPF.o): MASAPF.c MASAPF.h
$(masarith_LIB)(MASAPF.o): MASELEM.h
$(masarith_LIB)(MASAPF.o): MASBIOS.h
$(masarith_LIB)(MASAPF.o): MASSTOR.h
$(masarith_LIB)(MASAPF.o): MASERR.h
$(masarith_LIB)(MASAPF.o): SACLIST.h
$(masarith_LIB)(MASAPF.o): SACD.h
$(masarith_LIB)(MASAPF.o): SACI.h
$(masarith_LIB)(MASAPF.o): SACRN.h

MASC.h: MASSTOR.h

$(masarith_LIB)(MASC.o): MASC.c MASC.h
$(masarith_LIB)(MASC.o): MASBIOS.h
$(masarith_LIB)(MASC.o): MASSTOR.h
$(masarith_LIB)(MASC.o): MASERR.h
$(masarith_LIB)(MASC.o): SACLIST.h
$(masarith_LIB)(MASC.o): SACRN.h
$(masarith_LIB)(MASC.o): MASRN.h

MASCOMB.h: MASSTOR.h

$(masarith_LIB)(MASCOMB.o): MASCOMB.c MASCOMB.h
$(masarith_LIB)(MASCOMB.o): MASSTOR.h
$(masarith_LIB)(MASCOMB.o): SACLIST.h
$(masarith_LIB)(MASCOMB.o): LISTTOOLS.h

MASF.h: MASELEM.h
MASF.h: MASSTOR.h

$(masarith_LIB)(MASF.o): MASF.c MASF.h
$(masarith_LIB)(MASF.o): MASELEM.h
$(masarith_LIB)(MASF.o): MASSTOR.h
$(masarith_LIB)(MASF.o): SACLIST.h
$(masarith_LIB)(MASF.o): SACI.h
$(masarith_LIB)(MASF.o): SACRN.h
$(masarith_LIB)(MASF.o): MathLib.h

MASI.h: MASSTOR.h

$(masarith_LIB)(MASI.o): MASI.c MASI.h
$(masarith_LIB)(MASI.o): MASSTOR.h
$(masarith_LIB)(MASI.o): SACLIST.h
$(masarith_LIB)(MASI.o): SACD.h
$(masarith_LIB)(MASI.o): SACI.h

MASO.h: MASSTOR.h

$(masarith_LIB)(MASO.o): MASO.c MASO.h
$(masarith_LIB)(MASO.o): MASBIOS.h
$(masarith_LIB)(MASO.o): MASSTOR.h
$(masarith_LIB)(MASO.o): MASERR.h
$(masarith_LIB)(MASO.o): SACLIST.h
$(masarith_LIB)(MASO.o): SACRN.h
$(masarith_LIB)(MASO.o): MASQ.h

MASQ.h: MASSTOR.h

$(masarith_LIB)(MASQ.o): MASQ.c MASQ.h
$(masarith_LIB)(MASQ.o): MASBIOS.h
$(masarith_LIB)(MASQ.o): MASSTOR.h
$(masarith_LIB)(MASQ.o): MASERR.h
$(masarith_LIB)(MASQ.o): SACLIST.h
$(masarith_LIB)(MASQ.o): SACRN.h
$(masarith_LIB)(MASQ.o): MASRN.h

MASRN.h: MASSTOR.h

$(masarith_LIB)(MASRN.o): MASRN.c MASRN.h
$(masarith_LIB)(MASRN.o): MASELEM.h
$(masarith_LIB)(MASRN.o): MASSTOR.h
$(masarith_LIB)(MASRN.o): MASBIOS.h
$(masarith_LIB)(MASRN.o): SACLIST.h
$(masarith_LIB)(MASRN.o): SACD.h
$(masarith_LIB)(MASRN.o): SACI.h
$(masarith_LIB)(MASRN.o): SACRN.h

MASSET.h: MASSTOR.h

$(masarith_LIB)(MASSET.o): MASSET.c MASSET.h
$(masarith_LIB)(MASSET.o): MASSTOR.h
$(masarith_LIB)(MASSET.o): MASBIOS.h
$(masarith_LIB)(MASSET.o): SACLIST.h
$(masarith_LIB)(MASSET.o): MASSYM.h


$(masarith_LIB)(MathLib.o): MathLib.c MathLib.h

SACCOMB.h: MASSTOR.h

$(masarith_LIB)(SACCOMB.o): SACCOMB.c SACCOMB.h
$(masarith_LIB)(SACCOMB.o): MASELEM.h
$(masarith_LIB)(SACCOMB.o): MASSTOR.h
$(masarith_LIB)(SACCOMB.o): SACLIST.h
$(masarith_LIB)(SACCOMB.o): SACSET.h
$(masarith_LIB)(SACCOMB.o): SACM.h
$(masarith_LIB)(SACCOMB.o): SACI.h

SACD.h: MASSTOR.h

$(masarith_LIB)(SACD.o): SACD.c SACD.h
$(masarith_LIB)(SACD.o): MASELEM.h
$(masarith_LIB)(SACD.o): MASSTOR.h
$(masarith_LIB)(SACD.o): SACLIST.h

SACI.h: MASSTOR.h

$(masarith_LIB)(SACI.o): SACI.c SACI.h
$(masarith_LIB)(SACI.o): MASELEM.h
$(masarith_LIB)(SACI.o): MASBIOS.h
$(masarith_LIB)(SACI.o): MASSTOR.h
$(masarith_LIB)(SACI.o): SACLIST.h
$(masarith_LIB)(SACI.o): SACD.h

SACM.h: MASSTOR.h

$(masarith_LIB)(SACM.o): SACM.c SACM.h
$(masarith_LIB)(SACM.o): MASELEM.h
$(masarith_LIB)(SACM.o): MASSTOR.h
$(masarith_LIB)(SACM.o): SACD.h
$(masarith_LIB)(SACM.o): SACI.h

SACPRIM.h: MASSTOR.h

$(masarith_LIB)(SACPRIM.o): SACPRIM.c SACPRIM.h
$(masarith_LIB)(SACPRIM.o): MASELEM.h
$(masarith_LIB)(SACPRIM.o): MASBIOS.h
$(masarith_LIB)(SACPRIM.o): MASSTOR.h
$(masarith_LIB)(SACPRIM.o): MASERR.h
$(masarith_LIB)(SACPRIM.o): SACLIST.h
$(masarith_LIB)(SACPRIM.o): SACSET.h
$(masarith_LIB)(SACPRIM.o): SACD.h
$(masarith_LIB)(SACPRIM.o): SACI.h
$(masarith_LIB)(SACPRIM.o): SACM.h

SACRN.h: MASSTOR.h

$(masarith_LIB)(SACRN.o): SACRN.c SACRN.h
$(masarith_LIB)(SACRN.o): MASELEM.h
$(masarith_LIB)(SACRN.o): MASBIOS.h
$(masarith_LIB)(SACRN.o): MASSTOR.h
$(masarith_LIB)(SACRN.o): SACLIST.h
$(masarith_LIB)(SACRN.o): SACI.h

SACSET.h: MASSTOR.h

$(masarith_LIB)(SACSET.o): SACSET.c SACSET.h
$(masarith_LIB)(SACSET.o): MASSTOR.h
$(masarith_LIB)(SACSET.o): SACLIST.h

# -EOF-
