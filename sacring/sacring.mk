# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


sacring_MD= SACANF.md SACEXT1.md SACEXT2.md SACEXT3.md SACEXT4.md SACEXT5.md SACEXT6.md SACEXT7.md SACEXT8.md SACMUFAC.md SACPFAC.md SACPGCD.md SACROOT.md SACUPFAC.md

sacring_MI= SACANF.mi SACEXT1.mi SACEXT2.mi SACEXT3.mi SACEXT4.mi SACEXT5.mi SACEXT6.mi SACEXT7.mi SACEXT8.mi SACMUFAC.mi SACPFAC.mi SACPGCD.mi SACROOT.mi SACUPFAC.mi

sacring_MDP=

sacring_MIP=

sacring_CINC=

sacring_CSRC=

sacring_OBJS=$(sacring_CSRC:.c=.o) $(sacring_MI:.mi=.o) $(sacring_MIP:.mip=.o)

sacring_ALLSRC= SACANF.md SACEXT1.md SACEXT2.md SACEXT3.md SACEXT4.md SACEXT5.md SACEXT6.md SACEXT7.md SACEXT8.md SACMUFAC.md SACPFAC.md SACPGCD.md SACROOT.md SACUPFAC.md SACANF.mi SACEXT1.mi SACEXT2.mi SACEXT3.mi SACEXT4.mi SACEXT5.mi SACEXT6.mi SACEXT7.mi SACEXT8.mi SACMUFAC.mi SACPFAC.mi SACPGCD.mi SACROOT.mi SACUPFAC.mi

$(top_srcdir)/sacring/sacring.mk: $(sacring_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

SACANF.h: MASSTOR.h

$(sacring_LIB)(SACANF.o): SACANF.c SACANF.h
$(sacring_LIB)(SACANF.o): MASSTOR.h
$(sacring_LIB)(SACANF.o): SACLIST.h
$(sacring_LIB)(SACANF.o): SACRN.h
$(sacring_LIB)(SACANF.o): SACPOL.h
$(sacring_LIB)(SACANF.o): SACIPOL.h
$(sacring_LIB)(SACANF.o): SACPGCD.h
$(sacring_LIB)(SACANF.o): SACRPOL.h
$(sacring_LIB)(SACANF.o): SACROOT.h

SACEXT1.h: MASSTOR.h

$(sacring_LIB)(SACEXT1.o): SACEXT1.c SACEXT1.h
$(sacring_LIB)(SACEXT1.o): MASSTOR.h
$(sacring_LIB)(SACEXT1.o): SACLIST.h
$(sacring_LIB)(SACEXT1.o): SACI.h

SACEXT2.h: MASSTOR.h

$(sacring_LIB)(SACEXT2.o): SACEXT2.c SACEXT2.h
$(sacring_LIB)(SACEXT2.o): MASSTOR.h
$(sacring_LIB)(SACEXT2.o): SACLIST.h
$(sacring_LIB)(SACEXT2.o): SACI.h

SACEXT3.h: MASSTOR.h

$(sacring_LIB)(SACEXT3.o): SACEXT3.c SACEXT3.h
$(sacring_LIB)(SACEXT3.o): MASSTOR.h
$(sacring_LIB)(SACEXT3.o): SACLIST.h

SACEXT4.h: MASSTOR.h

$(sacring_LIB)(SACEXT4.o): SACEXT4.c SACEXT4.h
$(sacring_LIB)(SACEXT4.o): MASSTOR.h
$(sacring_LIB)(SACEXT4.o): SACLIST.h
$(sacring_LIB)(SACEXT4.o): SACI.h
$(sacring_LIB)(SACEXT4.o): SACRN.h
$(sacring_LIB)(SACEXT4.o): SACCOMB.h
$(sacring_LIB)(SACEXT4.o): SACPOL.h
$(sacring_LIB)(SACEXT4.o): SACIPOL.h
$(sacring_LIB)(SACEXT4.o): SACRPOL.h
$(sacring_LIB)(SACEXT4.o): SACPGCD.h

SACEXT5.h: MASSTOR.h

$(sacring_LIB)(SACEXT5.o): SACEXT5.c SACEXT5.h
$(sacring_LIB)(SACEXT5.o): MASELEM.h
$(sacring_LIB)(SACEXT5.o): MASSTOR.h
$(sacring_LIB)(SACEXT5.o): MASERR.h
$(sacring_LIB)(SACEXT5.o): SACLIST.h
$(sacring_LIB)(SACEXT5.o): SACI.h
$(sacring_LIB)(SACEXT5.o): SACM.h
$(sacring_LIB)(SACEXT5.o): SACCOMB.h
$(sacring_LIB)(SACEXT5.o): SACPOL.h
$(sacring_LIB)(SACEXT5.o): SACIPOL.h
$(sacring_LIB)(SACEXT5.o): SACMPOL.h
$(sacring_LIB)(SACEXT5.o): SACPGCD.h
$(sacring_LIB)(SACEXT5.o): SACEXT4.h

SACEXT6.h: MASSTOR.h

$(sacring_LIB)(SACEXT6.o): SACEXT6.c SACEXT6.h
$(sacring_LIB)(SACEXT6.o): MASSTOR.h
$(sacring_LIB)(SACEXT6.o): SACLIST.h
$(sacring_LIB)(SACEXT6.o): SACEXT5.h
$(sacring_LIB)(SACEXT6.o): SACPFAC.h

SACEXT7.h: MASSTOR.h

$(sacring_LIB)(SACEXT7.o): SACEXT7.c SACEXT7.h
$(sacring_LIB)(SACEXT7.o): MASELEM.h
$(sacring_LIB)(SACEXT7.o): MASSTOR.h
$(sacring_LIB)(SACEXT7.o): SACLIST.h
$(sacring_LIB)(SACEXT7.o): MASBIOS.h
$(sacring_LIB)(SACEXT7.o): SACI.h
$(sacring_LIB)(SACEXT7.o): SACRN.h
$(sacring_LIB)(SACEXT7.o): SACPOL.h
$(sacring_LIB)(SACEXT7.o): SACIPOL.h
$(sacring_LIB)(SACEXT7.o): SACPGCD.h
$(sacring_LIB)(SACEXT7.o): SACROOT.h
$(sacring_LIB)(SACEXT7.o): SACEXT2.h
$(sacring_LIB)(SACEXT7.o): SACEXT4.h

SACEXT8.h: MASSTOR.h

$(sacring_LIB)(SACEXT8.o): SACEXT8.c SACEXT8.h
$(sacring_LIB)(SACEXT8.o): MASSTOR.h
$(sacring_LIB)(SACEXT8.o): MASELEM.h
$(sacring_LIB)(SACEXT8.o): SACLIST.h
$(sacring_LIB)(SACEXT8.o): MASBIOS.h
$(sacring_LIB)(SACEXT8.o): SACI.h
$(sacring_LIB)(SACEXT8.o): SACM.h
$(sacring_LIB)(SACEXT8.o): SACRN.h
$(sacring_LIB)(SACEXT8.o): SACPOL.h
$(sacring_LIB)(SACEXT8.o): SACIPOL.h
$(sacring_LIB)(SACEXT8.o): SACRPOL.h
$(sacring_LIB)(SACEXT8.o): SACMPOL.h
$(sacring_LIB)(SACEXT8.o): SACRPOL.h
$(sacring_LIB)(SACEXT8.o): SACEXT2.h
$(sacring_LIB)(SACEXT8.o): SACEXT4.h
$(sacring_LIB)(SACEXT8.o): SACEXT5.h
$(sacring_LIB)(SACEXT8.o): SACEXT7.h
$(sacring_LIB)(SACEXT8.o): MASRN.h
$(sacring_LIB)(SACEXT8.o): DIPC.h
$(sacring_LIB)(SACEXT8.o): SACPGCD.h
$(sacring_LIB)(SACEXT8.o): SACROOT.h
$(sacring_LIB)(SACEXT8.o): SACPFAC.h
$(sacring_LIB)(SACEXT8.o): SACANF.h
$(sacring_LIB)(SACEXT8.o): SACUPFAC.h

SACMUFAC.h: MASSTOR.h

$(sacring_LIB)(SACMUFAC.o): SACMUFAC.c SACMUFAC.h
$(sacring_LIB)(SACMUFAC.o): MASELEM.h
$(sacring_LIB)(SACMUFAC.o): MASSTOR.h
$(sacring_LIB)(SACMUFAC.o): MASBIOS.h
$(sacring_LIB)(SACMUFAC.o): SACLIST.h
$(sacring_LIB)(SACMUFAC.o): SACI.h
$(sacring_LIB)(SACMUFAC.o): SACM.h
$(sacring_LIB)(SACMUFAC.o): SACPRIM.h
$(sacring_LIB)(SACMUFAC.o): SACCOMB.h
$(sacring_LIB)(SACMUFAC.o): SACPOL.h
$(sacring_LIB)(SACMUFAC.o): SACIPOL.h
$(sacring_LIB)(SACMUFAC.o): SACMPOL.h
$(sacring_LIB)(SACMUFAC.o): SACDPOL.h
$(sacring_LIB)(SACMUFAC.o): SACPGCD.h
$(sacring_LIB)(SACMUFAC.o): SACLDIO.h

SACPFAC.h: MASSTOR.h

$(sacring_LIB)(SACPFAC.o): SACPFAC.c SACPFAC.h
$(sacring_LIB)(SACPFAC.o): MASELEM.h
$(sacring_LIB)(SACPFAC.o): MASSTOR.h
$(sacring_LIB)(SACPFAC.o): MASBIOS.h
$(sacring_LIB)(SACPFAC.o): SACLIST.h
$(sacring_LIB)(SACPFAC.o): SACI.h
$(sacring_LIB)(SACPFAC.o): SACM.h
$(sacring_LIB)(SACPFAC.o): SACPRIM.h
$(sacring_LIB)(SACPFAC.o): SACCOMB.h
$(sacring_LIB)(SACPFAC.o): SACPOL.h
$(sacring_LIB)(SACPFAC.o): SACIPOL.h
$(sacring_LIB)(SACPFAC.o): SACMPOL.h
$(sacring_LIB)(SACPFAC.o): SACDPOL.h
$(sacring_LIB)(SACPFAC.o): SACPGCD.h
$(sacring_LIB)(SACPFAC.o): SACUPFAC.h

SACPGCD.h: MASSTOR.h

$(sacring_LIB)(SACPGCD.o): SACPGCD.c SACPGCD.h
$(sacring_LIB)(SACPGCD.o): MASELEM.h
$(sacring_LIB)(SACPGCD.o): MASSTOR.h
$(sacring_LIB)(SACPGCD.o): MASERR.h
$(sacring_LIB)(SACPGCD.o): MASBIOS.h
$(sacring_LIB)(SACPGCD.o): SACLIST.h
$(sacring_LIB)(SACPGCD.o): SACI.h
$(sacring_LIB)(SACPGCD.o): SACM.h
$(sacring_LIB)(SACPGCD.o): SACCOMB.h
$(sacring_LIB)(SACPGCD.o): SACPOL.h
$(sacring_LIB)(SACPGCD.o): SACIPOL.h
$(sacring_LIB)(SACPGCD.o): SACMPOL.h
$(sacring_LIB)(SACPGCD.o): SACRPOL.h
$(sacring_LIB)(SACPGCD.o): SACDPOL.h

SACROOT.h: MASSTOR.h

$(sacring_LIB)(SACROOT.o): SACROOT.c SACROOT.h
$(sacring_LIB)(SACROOT.o): MASELEM.h
$(sacring_LIB)(SACROOT.o): MASSTOR.h
$(sacring_LIB)(SACROOT.o): MASBIOS.h
$(sacring_LIB)(SACROOT.o): SACLIST.h
$(sacring_LIB)(SACROOT.o): SACI.h
$(sacring_LIB)(SACROOT.o): SACRN.h
$(sacring_LIB)(SACROOT.o): SACPOL.h
$(sacring_LIB)(SACROOT.o): SACIPOL.h
$(sacring_LIB)(SACROOT.o): SACPGCD.h

SACUPFAC.h: MASSTOR.h

$(sacring_LIB)(SACUPFAC.o): SACUPFAC.c SACUPFAC.h
$(sacring_LIB)(SACUPFAC.o): MASELEM.h
$(sacring_LIB)(SACUPFAC.o): MASSTOR.h
$(sacring_LIB)(SACUPFAC.o): MASERR.h
$(sacring_LIB)(SACUPFAC.o): SACLIST.h
$(sacring_LIB)(SACUPFAC.o): SACI.h
$(sacring_LIB)(SACUPFAC.o): SACM.h
$(sacring_LIB)(SACUPFAC.o): SACPRIM.h
$(sacring_LIB)(SACUPFAC.o): SACCOMB.h
$(sacring_LIB)(SACUPFAC.o): SACPOL.h
$(sacring_LIB)(SACUPFAC.o): SACIPOL.h
$(sacring_LIB)(SACUPFAC.o): SACMPOL.h
$(sacring_LIB)(SACUPFAC.o): SACDPOL.h
$(sacring_LIB)(SACUPFAC.o): SACPGCD.h
$(sacring_LIB)(SACUPFAC.o): SACMUFAC.h

# -EOF-
