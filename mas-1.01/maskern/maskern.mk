# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


maskern_MD= LISTTOOLS.md MASBIOS.md MASBIOSU.md MASCONF.md MASELEM.md MASERR.md MASSIGNAL.md MASSTOR.md MASmtc.md Portab.md SACBIOS.md SACLIST.md SYSINFO.md clock.md maskpathsea.md masreadline.md massig.md setjmp.md

maskern_MI= LISTTOOLS.mi MASBIOS.mi MASBIOSU.mi MASELEM.mi MASERR.mi MASSIGNAL.mi Portab.mi SACBIOS.mi SACLIST.mi SYSINFO.mi massig.mi setjmp.mi

maskern_MDP=

maskern_MIP= MASSTOR.mip MASmtc.mip

maskern_CINC=

maskern_CSRC= clock.c cmacros.c masconf.c maskpathsea.c masreadline.c

maskern_OBJS=$(maskern_CSRC:.c=.o) $(maskern_MI:.mi=.o) $(maskern_MIP:.mip=.o)

maskern_ALLSRC= LISTTOOLS.md MASBIOS.md MASBIOSU.md MASCONF.md MASELEM.md MASERR.md MASSIGNAL.md MASSTOR.md MASmtc.md Portab.md SACBIOS.md SACLIST.md SYSINFO.md clock.md maskpathsea.md masreadline.md massig.md setjmp.md LISTTOOLS.mi MASBIOS.mi MASBIOSU.mi MASELEM.mi MASERR.mi MASSIGNAL.mi Portab.mi SACBIOS.mi SACLIST.mi SYSINFO.mi massig.mi setjmp.mi MASSTOR.mip MASmtc.mip clock.c cmacros.c masconf.c maskpathsea.c masreadline.c

$(top_srcdir)/maskern/maskern.mk: $(maskern_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

LISTTOOLS.h: MASSTOR.h

$(maskern_LIB)(LISTTOOLS.o): LISTTOOLS.c LISTTOOLS.h
$(maskern_LIB)(LISTTOOLS.o): MASBIOS.h
$(maskern_LIB)(LISTTOOLS.o): MASELEM.h
$(maskern_LIB)(LISTTOOLS.o): MASSTOR.h
$(maskern_LIB)(LISTTOOLS.o): SACLIST.h

MASBIOS.h: MASELEM.h
MASBIOS.h: MASSTOR.h

$(maskern_LIB)(MASBIOS.o): MASBIOS.c MASBIOS.h
$(maskern_LIB)(MASBIOS.o): MASELEM.h
$(maskern_LIB)(MASBIOS.o): MASSTOR.h
$(maskern_LIB)(MASBIOS.o): MASERR.h
$(maskern_LIB)(MASBIOS.o): Portab.h
$(maskern_LIB)(MASBIOS.o): massig.h
$(maskern_LIB)(MASBIOS.o): maskpathsea.h
$(maskern_LIB)(MASBIOS.o): masreadline.h

MASBIOSU.h: MASSTOR.h

$(maskern_LIB)(MASBIOSU.o): MASBIOSU.c MASBIOSU.h
$(maskern_LIB)(MASBIOSU.o): MASELEM.h
$(maskern_LIB)(MASBIOSU.o): MASSTOR.h
$(maskern_LIB)(MASBIOSU.o): MASBIOS.h
$(maskern_LIB)(MASBIOSU.o): MASmtc.h
$(maskern_LIB)(MASBIOSU.o): SACLIST.h

MASCONF.h: MASELEM.h


$(maskern_LIB)(MASELEM.o): MASELEM.c MASELEM.h

MASERR.h: MASELEM.h

$(maskern_LIB)(MASERR.o): MASERR.c MASERR.h
$(maskern_LIB)(MASERR.o): MASmtc.h
$(maskern_LIB)(MASERR.o): setjmp.h
$(maskern_LIB)(MASERR.o): massig.h
$(maskern_LIB)(MASERR.o): MASELEM.h
$(maskern_LIB)(MASERR.o): MASCONF.h


$(maskern_LIB)(MASSIGNAL.o): MASSIGNAL.c MASSIGNAL.h
$(maskern_LIB)(MASSIGNAL.o): MASBIOS.h
$(maskern_LIB)(MASSIGNAL.o): MASSTOR.h
$(maskern_LIB)(MASSIGNAL.o): massig.h

MASSTOR.h: MASELEM.h



$(maskern_LIB)(Portab.o): Portab.c Portab.h

SACBIOS.h: MASELEM.h

$(maskern_LIB)(SACBIOS.o): SACBIOS.c SACBIOS.h
$(maskern_LIB)(SACBIOS.o): MASELEM.h
$(maskern_LIB)(SACBIOS.o): MASBIOS.h

SACLIST.h: MASSTOR.h

$(maskern_LIB)(SACLIST.o): SACLIST.c SACLIST.h
$(maskern_LIB)(SACLIST.o): MASELEM.h
$(maskern_LIB)(SACLIST.o): MASBIOS.h
$(maskern_LIB)(SACLIST.o): MASSTOR.h

SYSINFO.h: MASELEM.h
SYSINFO.h: MASSTOR.h

$(maskern_LIB)(SYSINFO.o): SYSINFO.c SYSINFO.h
$(maskern_LIB)(SYSINFO.o): MASBIOS.h
$(maskern_LIB)(SYSINFO.o): MASELEM.h
$(maskern_LIB)(SYSINFO.o): MASSTOR.h
$(maskern_LIB)(SYSINFO.o): SACLIST.h





$(maskern_LIB)(massig.o): massig.c massig.h


$(maskern_LIB)(setjmp.o): setjmp.c setjmp.h

$(maskern_LIB)(MASSTOR.o): MASSTOR.c MASSTOR.h
$(maskern_LIB)(MASSTOR.o): clock.h
$(maskern_LIB)(MASSTOR.o): MASCONF.h
$(maskern_LIB)(MASSTOR.o): MASELEM.h
$(maskern_LIB)(MASSTOR.o): MASERR.h
$(maskern_LIB)(MASSTOR.o): MASmtc.h
$(maskern_LIB)(MASSTOR.o): massig.h

$(maskern_LIB)(MASmtc.o): MASmtc.c MASmtc.h

$(maskern_LIB)(clock.o ): 

$(maskern_LIB)(cmacros.o ): 

$(maskern_LIB)(masconf.o): config.h

$(maskern_LIB)(masconf.o): MASCONF.h

$(maskern_LIB)(maskpathsea.o): config.h

$(maskern_LIB)(masreadline.o): config.h

# -EOF-
