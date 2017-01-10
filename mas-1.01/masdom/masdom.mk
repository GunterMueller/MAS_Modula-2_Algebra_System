# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masdom_MD= ADTOOLS.md CGBAPPL.md CGBDSTR.md CGBFUNC.md CGBMAIN.md CGBMISC.md CGBSYS.md DIPADOM.md DIPAGB.md DIPDCGB.md DIPDDGB.md DIPGB.md DIPTOOLS.md DOMAF.md DOMAPF.md DOMC.md DOMFF.md DOMI.md DOMIP.md DOMMD.md DOMMI.md DOMO.md DOMQ.md DOMRF.md DOMRN.md DOMRP.md MASADOM.md

masdom_MI= ADTOOLS.mi DIPADOM.mi DIPAGB.mi DIPDCGB.mi DIPDDGB.mi DIPGB.mi DIPTOOLS.mi DOMAF.mi DOMAPF.mi DOMC.mi DOMFF.mi DOMI.mi DOMIP.mi DOMMD.mi DOMMI.mi DOMO.mi DOMQ.mi DOMRF.mi DOMRN.mi DOMRP.mi MASADOM.mi

masdom_MDP=

masdom_MIP= CGBAPPL.mip CGBDSTR.mip CGBFUNC.mip CGBMAIN.mip CGBMISC.mip CGBSYS.mip

masdom_CINC= debug.h

masdom_CSRC=

masdom_OBJS=$(masdom_CSRC:.c=.o) $(masdom_MI:.mi=.o) $(masdom_MIP:.mip=.o)

masdom_ALLSRC= ADTOOLS.md CGBAPPL.md CGBDSTR.md CGBFUNC.md CGBMAIN.md CGBMISC.md CGBSYS.md DIPADOM.md DIPAGB.md DIPDCGB.md DIPDDGB.md DIPGB.md DIPTOOLS.md DOMAF.md DOMAPF.md DOMC.md DOMFF.md DOMI.md DOMIP.md DOMMD.md DOMMI.md DOMO.md DOMQ.md DOMRF.md DOMRN.md DOMRP.md MASADOM.md ADTOOLS.mi DIPADOM.mi DIPAGB.mi DIPDCGB.mi DIPDDGB.mi DIPGB.mi DIPTOOLS.mi DOMAF.mi DOMAPF.mi DOMC.mi DOMFF.mi DOMI.mi DOMIP.mi DOMMD.mi DOMMI.mi DOMO.mi DOMQ.mi DOMRF.mi DOMRN.mi DOMRP.mi MASADOM.mi CGBAPPL.mip CGBDSTR.mip CGBFUNC.mip CGBMAIN.mip CGBMISC.mip CGBSYS.mip debug.h

$(top_srcdir)/masdom/masdom.mk: $(masdom_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

ADTOOLS.h: MASSTOR.h

$(masdom_LIB)(ADTOOLS.o): ADTOOLS.c ADTOOLS.h
$(masdom_LIB)(ADTOOLS.o): DOMIP.h
$(masdom_LIB)(ADTOOLS.o): DOMRF.h
$(masdom_LIB)(ADTOOLS.o): DIPRF.h
$(masdom_LIB)(ADTOOLS.o): DOMI.h
$(masdom_LIB)(ADTOOLS.o): MASADOM.h
$(masdom_LIB)(ADTOOLS.o): MASBIOS.h
$(masdom_LIB)(ADTOOLS.o): MASBIOSU.h
$(masdom_LIB)(ADTOOLS.o): MASSTOR.h
$(masdom_LIB)(ADTOOLS.o): SACLIST.h

CGBAPPL.h: MASSTOR.h

CGBDSTR.h: MASSTOR.h

CGBFUNC.h: MASSTOR.h

CGBMAIN.h: MASSTOR.h

CGBMISC.h: MASSTOR.h

CGBSYS.h: MASSTOR.h

DIPADOM.h: MASSTOR.h

$(masdom_LIB)(DIPADOM.o): DIPADOM.c DIPADOM.h
$(masdom_LIB)(DIPADOM.o): MASSTOR.h
$(masdom_LIB)(DIPADOM.o): MASERR.h
$(masdom_LIB)(DIPADOM.o): MASBIOS.h
$(masdom_LIB)(DIPADOM.o): SACLIST.h
$(masdom_LIB)(DIPADOM.o): SACPOL.h
$(masdom_LIB)(DIPADOM.o): DIPC.h
$(masdom_LIB)(DIPADOM.o): MASADOM.h

DIPAGB.h: MASSTOR.h
DIPAGB.h: MASLISPU.h

$(masdom_LIB)(DIPAGB.o): DIPAGB.c DIPAGB.h
$(masdom_LIB)(DIPAGB.o): DIPADOM.h
$(masdom_LIB)(DIPAGB.o): DIPC.h
$(masdom_LIB)(DIPAGB.o): DIPGB.h
$(masdom_LIB)(DIPAGB.o): DIPTOOLS.h
$(masdom_LIB)(DIPAGB.o): MASADOM.h
$(masdom_LIB)(DIPAGB.o): MASBIOS.h
$(masdom_LIB)(DIPAGB.o): MASELEM.h
$(masdom_LIB)(DIPAGB.o): MASERR.h
$(masdom_LIB)(DIPAGB.o): MASLISPU.h
$(masdom_LIB)(DIPAGB.o): MASNCC.h
$(masdom_LIB)(DIPAGB.o): MASRN.h
$(masdom_LIB)(DIPAGB.o): MASSTOR.h
$(masdom_LIB)(DIPAGB.o): massig.h
$(masdom_LIB)(DIPAGB.o): SACLIST.h
$(masdom_LIB)(DIPAGB.o): SACPOL.h
$(masdom_LIB)(DIPAGB.o): SACRN.h

DIPDCGB.h: MASSTOR.h
DIPDCGB.h: MASLISPU.h

$(masdom_LIB)(DIPDCGB.o): DIPDCGB.c DIPDCGB.h
$(masdom_LIB)(DIPDCGB.o): MASBIOS.h
$(masdom_LIB)(DIPDCGB.o): MASSTOR.h
$(masdom_LIB)(DIPDCGB.o): MASERR.h
$(masdom_LIB)(DIPDCGB.o): MASLISPU.h
$(masdom_LIB)(DIPDCGB.o): SACLIST.h
$(masdom_LIB)(DIPDCGB.o): SACRN.h
$(masdom_LIB)(DIPDCGB.o): DIPC.h
$(masdom_LIB)(DIPDCGB.o): DIPADOM.h
$(masdom_LIB)(DIPDCGB.o): DIPTOO.h
$(masdom_LIB)(DIPDCGB.o): DIPAGB.h

DIPDDGB.h: MASSTOR.h

$(masdom_LIB)(DIPDDGB.o): DIPDDGB.c DIPDDGB.h
$(masdom_LIB)(DIPDDGB.o): MASSTOR.h
$(masdom_LIB)(DIPDDGB.o): MASERR.h
$(masdom_LIB)(DIPDDGB.o): SACLIST.h
$(masdom_LIB)(DIPDDGB.o): MASBIOS.h
$(masdom_LIB)(DIPDDGB.o): SACI.h
$(masdom_LIB)(DIPDDGB.o): DIPC.h
$(masdom_LIB)(DIPDDGB.o): DIPI.h
$(masdom_LIB)(DIPDDGB.o): MASADOM.h
$(masdom_LIB)(DIPDDGB.o): DIPADOM.h

DIPGB.h: MASSTOR.h

$(masdom_LIB)(DIPGB.o): DIPGB.c DIPGB.h
$(masdom_LIB)(DIPGB.o): MASSTOR.h
$(masdom_LIB)(DIPGB.o): SACLIST.h
$(masdom_LIB)(DIPGB.o): MASBIOS.h
$(masdom_LIB)(DIPGB.o): SACI.h
$(masdom_LIB)(DIPGB.o): SACRN.h
$(masdom_LIB)(DIPGB.o): DIPC.h
$(masdom_LIB)(DIPGB.o): DIPRNGB.h
$(masdom_LIB)(DIPGB.o): DIPADOM.h
$(masdom_LIB)(DIPGB.o): MASADOM.h

DIPTOOLS.h: MASSTOR.h

$(masdom_LIB)(DIPTOOLS.o): DIPTOOLS.c DIPTOOLS.h
$(masdom_LIB)(DIPTOOLS.o): ADTOOLS.h
$(masdom_LIB)(DIPTOOLS.o): DIPADOM.h
$(masdom_LIB)(DIPTOOLS.o): DIPC.h
$(masdom_LIB)(DIPTOOLS.o): MASADOM.h
$(masdom_LIB)(DIPTOOLS.o): MASBIOS.h
$(masdom_LIB)(DIPTOOLS.o): MASBIOSU.h
$(masdom_LIB)(DIPTOOLS.o): MASELEM.h
$(masdom_LIB)(DIPTOOLS.o): MASSTOR.h
$(masdom_LIB)(DIPTOOLS.o): MASERR.h
$(masdom_LIB)(DIPTOOLS.o): MASSYM.h
$(masdom_LIB)(DIPTOOLS.o): MASSYM2.h
$(masdom_LIB)(DIPTOOLS.o): SACLIST.h

DOMAF.h: MASADOM.h

$(masdom_LIB)(DOMAF.o): DOMAF.c DOMAF.h
$(masdom_LIB)(DOMAF.o): MASSTOR.h
$(masdom_LIB)(DOMAF.o): MASERR.h
$(masdom_LIB)(DOMAF.o): MASADOM.h
$(masdom_LIB)(DOMAF.o): MASBIOS.h
$(masdom_LIB)(DOMAF.o): SACLIST.h
$(masdom_LIB)(DOMAF.o): SACPOL.h
$(masdom_LIB)(DOMAF.o): SACRPOL.h
$(masdom_LIB)(DOMAF.o): SACANF.h
$(masdom_LIB)(DOMAF.o): DIPC.h
$(masdom_LIB)(DOMAF.o): DIPAGB.h
$(masdom_LIB)(DOMAF.o): DIPGB.h
$(masdom_LIB)(DOMAF.o): DIPI.h
$(masdom_LIB)(DOMAF.o): DIPRN.h
$(masdom_LIB)(DOMAF.o): DIPRNPOL.h
$(masdom_LIB)(DOMAF.o): SACRN.h
$(masdom_LIB)(DOMAF.o): MASRN.h
$(masdom_LIB)(DOMAF.o): SACEXT8.h
$(masdom_LIB)(DOMAF.o): SACPGCD.h
$(masdom_LIB)(DOMAF.o): SACUPFAC.h

DOMAPF.h: MASADOM.h

$(masdom_LIB)(DOMAPF.o): DOMAPF.c DOMAPF.h
$(masdom_LIB)(DOMAPF.o): MASSTOR.h
$(masdom_LIB)(DOMAPF.o): MASADOM.h
$(masdom_LIB)(DOMAPF.o): MASBIOS.h
$(masdom_LIB)(DOMAPF.o): SACLIST.h
$(masdom_LIB)(DOMAPF.o): MASAPF.h
$(masdom_LIB)(DOMAPF.o): DIPAGB.h
$(masdom_LIB)(DOMAPF.o): DIPGB.h

DOMC.h: MASADOM.h

$(masdom_LIB)(DOMC.o): DOMC.c DOMC.h
$(masdom_LIB)(DOMC.o): MASSTOR.h
$(masdom_LIB)(DOMC.o): MASERR.h
$(masdom_LIB)(DOMC.o): MASADOM.h
$(masdom_LIB)(DOMC.o): MASBIOS.h
$(masdom_LIB)(DOMC.o): SACLIST.h
$(masdom_LIB)(DOMC.o): MASC.h
$(masdom_LIB)(DOMC.o): DIPAGB.h
$(masdom_LIB)(DOMC.o): DIPGB.h

DOMFF.h: MASADOM.h

$(masdom_LIB)(DOMFF.o): DOMFF.c DOMFF.h
$(masdom_LIB)(DOMFF.o): MASSTOR.h
$(masdom_LIB)(DOMFF.o): MASERR.h
$(masdom_LIB)(DOMFF.o): MASADOM.h
$(masdom_LIB)(DOMFF.o): MASBIOS.h
$(masdom_LIB)(DOMFF.o): SACLIST.h
$(masdom_LIB)(DOMFF.o): SACI.h
$(masdom_LIB)(DOMFF.o): SACPOL.h
$(masdom_LIB)(DOMFF.o): MASFF.h
$(masdom_LIB)(DOMFF.o): DIPC.h
$(masdom_LIB)(DOMFF.o): DIPI.h
$(masdom_LIB)(DOMFF.o): DIPAGB.h
$(masdom_LIB)(DOMFF.o): DIPGB.h
$(masdom_LIB)(DOMFF.o): SACMUFAC.h
$(masdom_LIB)(DOMFF.o): SACPGCD.h
$(masdom_LIB)(DOMFF.o): SACPRIM.h

DOMI.h: MASADOM.h

$(masdom_LIB)(DOMI.o): DOMI.c DOMI.h
$(masdom_LIB)(DOMI.o): MASSTOR.h
$(masdom_LIB)(DOMI.o): MASBIOS.h
$(masdom_LIB)(DOMI.o): MASERR.h
$(masdom_LIB)(DOMI.o): MASADOM.h
$(masdom_LIB)(DOMI.o): SACI.h
$(masdom_LIB)(DOMI.o): SACLIST.h
$(masdom_LIB)(DOMI.o): DIPC.h
$(masdom_LIB)(DOMI.o): DIPTOOLS.h
$(masdom_LIB)(DOMI.o): SACPFAC.h
$(masdom_LIB)(DOMI.o): MASPGCD.h
$(masdom_LIB)(DOMI.o): DIPGB.h
$(masdom_LIB)(DOMI.o): DIPAGB.h

DOMIP.h: MASADOM.h

$(masdom_LIB)(DOMIP.o): DOMIP.c DOMIP.h
$(masdom_LIB)(DOMIP.o): DIPTOO.h
$(masdom_LIB)(DOMIP.o): DIPTOOLS.h
$(masdom_LIB)(DOMIP.o): MASSTOR.h
$(masdom_LIB)(DOMIP.o): MASERR.h
$(masdom_LIB)(DOMIP.o): MASADOM.h
$(masdom_LIB)(DOMIP.o): MASBIOS.h
$(masdom_LIB)(DOMIP.o): SACLIST.h
$(masdom_LIB)(DOMIP.o): SACPOL.h
$(masdom_LIB)(DOMIP.o): SACIPOL.h
$(masdom_LIB)(DOMIP.o): SACPGCD.h
$(masdom_LIB)(DOMIP.o): SACPFAC.h
$(masdom_LIB)(DOMIP.o): SACEXT4.h
$(masdom_LIB)(DOMIP.o): DIPC.h
$(masdom_LIB)(DOMIP.o): DIPI.h
$(masdom_LIB)(DOMIP.o): DIPGCD.h
$(masdom_LIB)(DOMIP.o): DIPAGB.h
$(masdom_LIB)(DOMIP.o): DIPGB.h

DOMMD.h: MASADOM.h

$(masdom_LIB)(DOMMD.o): DOMMD.c DOMMD.h
$(masdom_LIB)(DOMMD.o): MASSTOR.h
$(masdom_LIB)(DOMMD.o): MASERR.h
$(masdom_LIB)(DOMMD.o): MASADOM.h
$(masdom_LIB)(DOMMD.o): MASBIOS.h
$(masdom_LIB)(DOMMD.o): SACLIST.h
$(masdom_LIB)(DOMMD.o): SACI.h
$(masdom_LIB)(DOMMD.o): SACM.h
$(masdom_LIB)(DOMMD.o): SACPRIM.h
$(masdom_LIB)(DOMMD.o): DIPAGB.h
$(masdom_LIB)(DOMMD.o): DIPGB.h

DOMMI.h: MASADOM.h

$(masdom_LIB)(DOMMI.o): DOMMI.c DOMMI.h
$(masdom_LIB)(DOMMI.o): MASSTOR.h
$(masdom_LIB)(DOMMI.o): MASERR.h
$(masdom_LIB)(DOMMI.o): MASADOM.h
$(masdom_LIB)(DOMMI.o): MASBIOS.h
$(masdom_LIB)(DOMMI.o): SACLIST.h
$(masdom_LIB)(DOMMI.o): SACI.h
$(masdom_LIB)(DOMMI.o): SACM.h
$(masdom_LIB)(DOMMI.o): SACPRIM.h
$(masdom_LIB)(DOMMI.o): DIPAGB.h
$(masdom_LIB)(DOMMI.o): DIPGB.h

DOMO.h: MASADOM.h

$(masdom_LIB)(DOMO.o): DOMO.c DOMO.h
$(masdom_LIB)(DOMO.o): MASSTOR.h
$(masdom_LIB)(DOMO.o): MASERR.h
$(masdom_LIB)(DOMO.o): MASADOM.h
$(masdom_LIB)(DOMO.o): MASBIOS.h
$(masdom_LIB)(DOMO.o): SACLIST.h
$(masdom_LIB)(DOMO.o): MASO.h
$(masdom_LIB)(DOMO.o): DIPAGB.h
$(masdom_LIB)(DOMO.o): DIPGB.h

DOMQ.h: MASADOM.h

$(masdom_LIB)(DOMQ.o): DOMQ.c DOMQ.h
$(masdom_LIB)(DOMQ.o): MASSTOR.h
$(masdom_LIB)(DOMQ.o): MASERR.h
$(masdom_LIB)(DOMQ.o): MASADOM.h
$(masdom_LIB)(DOMQ.o): MASBIOS.h
$(masdom_LIB)(DOMQ.o): SACLIST.h
$(masdom_LIB)(DOMQ.o): MASQ.h
$(masdom_LIB)(DOMQ.o): DIPAGB.h
$(masdom_LIB)(DOMQ.o): DIPGB.h

DOMRF.h: MASADOM.h

$(masdom_LIB)(DOMRF.o): DOMRF.c DOMRF.h
$(masdom_LIB)(DOMRF.o): MASSTOR.h
$(masdom_LIB)(DOMRF.o): MASERR.h
$(masdom_LIB)(DOMRF.o): MASADOM.h
$(masdom_LIB)(DOMRF.o): MASBIOS.h
$(masdom_LIB)(DOMRF.o): SACLIST.h
$(masdom_LIB)(DOMRF.o): DIPRF.h
$(masdom_LIB)(DOMRF.o): SACPOL.h
$(masdom_LIB)(DOMRF.o): DIPAGB.h
$(masdom_LIB)(DOMRF.o): DIPGB.h

DOMRN.h: MASADOM.h

$(masdom_LIB)(DOMRN.o): DOMRN.c DOMRN.h
$(masdom_LIB)(DOMRN.o): MASSTOR.h
$(masdom_LIB)(DOMRN.o): MASERR.h
$(masdom_LIB)(DOMRN.o): MASADOM.h
$(masdom_LIB)(DOMRN.o): MASBIOS.h
$(masdom_LIB)(DOMRN.o): SACLIST.h
$(masdom_LIB)(DOMRN.o): SACRN.h
$(masdom_LIB)(DOMRN.o): MASRN.h
$(masdom_LIB)(DOMRN.o): DIPI.h
$(masdom_LIB)(DOMRN.o): DIPC.h
$(masdom_LIB)(DOMRN.o): DIPRN.h
$(masdom_LIB)(DOMRN.o): SACPFAC.h
$(masdom_LIB)(DOMRN.o): MASPGCD.h
$(masdom_LIB)(DOMRN.o): DIPGB.h
$(masdom_LIB)(DOMRN.o): DIPAGB.h

DOMRP.h: MASADOM.h

$(masdom_LIB)(DOMRP.o): DOMRP.c DOMRP.h
$(masdom_LIB)(DOMRP.o): MASSTOR.h
$(masdom_LIB)(DOMRP.o): MASERR.h
$(masdom_LIB)(DOMRP.o): MASADOM.h
$(masdom_LIB)(DOMRP.o): SACLIST.h
$(masdom_LIB)(DOMRP.o): SACRN.h
$(masdom_LIB)(DOMRP.o): SACPOL.h
$(masdom_LIB)(DOMRP.o): SACRPOL.h
$(masdom_LIB)(DOMRP.o): DIPC.h
$(masdom_LIB)(DOMRP.o): DIPRN.h
$(masdom_LIB)(DOMRP.o): DIPRNPOL.h
$(masdom_LIB)(DOMRP.o): DIPAGB.h
$(masdom_LIB)(DOMRP.o): DIPGB.h

MASADOM.h: MASSTOR.h

$(masdom_LIB)(MASADOM.o): MASADOM.c MASADOM.h
$(masdom_LIB)(MASADOM.o): DIPAGB.h
$(masdom_LIB)(MASADOM.o): DIPC.h
$(masdom_LIB)(MASADOM.o): DIPTOO.h
$(masdom_LIB)(MASADOM.o): DIPTOOLS.h
$(masdom_LIB)(MASADOM.o): DOMIP.h
$(masdom_LIB)(MASADOM.o): MASBIOS.h
$(masdom_LIB)(MASADOM.o): MASERR.h
$(masdom_LIB)(MASADOM.o): MASSTOR.h
$(masdom_LIB)(MASADOM.o): MASSYM2.h
$(masdom_LIB)(MASADOM.o): SACLIST.h

$(masdom_LIB)(CGBAPPL.o): CGBAPPL.c CGBAPPL.h
$(masdom_LIB)(CGBAPPL.o): CGBDSTR.h
$(masdom_LIB)(CGBAPPL.o): CGBFUNC.h
$(masdom_LIB)(CGBAPPL.o): CGBMISC.h
$(masdom_LIB)(CGBAPPL.o): CGBSYS.h
$(masdom_LIB)(CGBAPPL.o): DIPADOM.h
$(masdom_LIB)(CGBAPPL.o): DIPC.h
$(masdom_LIB)(CGBAPPL.o): DIPDIM.h
$(masdom_LIB)(CGBAPPL.o): MASADOM.h
$(masdom_LIB)(CGBAPPL.o): MASBIOS.h
$(masdom_LIB)(CGBAPPL.o): MASSTOR.h
$(masdom_LIB)(CGBAPPL.o): SACLIST.h
$(masdom_LIB)(CGBAPPL.o): SACPOL.h

$(masdom_LIB)(CGBDSTR.o): CGBDSTR.c CGBDSTR.h
$(masdom_LIB)(CGBDSTR.o): CGBMAIN.h
$(masdom_LIB)(CGBDSTR.o): CGBMISC.h
$(masdom_LIB)(CGBDSTR.o): DIPADOM.h
$(masdom_LIB)(CGBDSTR.o): DIPC.h
$(masdom_LIB)(CGBDSTR.o): MASADOM.h
$(masdom_LIB)(CGBDSTR.o): MASBIOS.h
$(masdom_LIB)(CGBDSTR.o): MASBIOSU.h
$(masdom_LIB)(CGBDSTR.o): MASERR.h
$(masdom_LIB)(CGBDSTR.o): MASSTOR.h
$(masdom_LIB)(CGBDSTR.o): MASSYM.h
$(masdom_LIB)(CGBDSTR.o): MLOGBASE.h
$(masdom_LIB)(CGBDSTR.o): PQBASE.h
$(masdom_LIB)(CGBDSTR.o): SACLIST.h
$(masdom_LIB)(CGBDSTR.o): SACPOL.h

$(masdom_LIB)(CGBFUNC.o): CGBFUNC.c CGBFUNC.h
$(masdom_LIB)(CGBFUNC.o): CGBDSTR.h
$(masdom_LIB)(CGBFUNC.o): CGBMISC.h
$(masdom_LIB)(CGBFUNC.o): DIPADOM.h
$(masdom_LIB)(CGBFUNC.o): DIPC.h
$(masdom_LIB)(CGBFUNC.o): MASADOM.h
$(masdom_LIB)(CGBFUNC.o): MASBIOS.h
$(masdom_LIB)(CGBFUNC.o): MASSTOR.h
$(masdom_LIB)(CGBFUNC.o): SACLIST.h

$(masdom_LIB)(CGBMAIN.o): CGBMAIN.c CGBMAIN.h
$(masdom_LIB)(CGBMAIN.o): CGBAPPL.h
$(masdom_LIB)(CGBMAIN.o): CGBDSTR.h
$(masdom_LIB)(CGBMAIN.o): CGBFUNC.h
$(masdom_LIB)(CGBMAIN.o): CGBMISC.h
$(masdom_LIB)(CGBMAIN.o): CGBSYS.h
$(masdom_LIB)(CGBMAIN.o): DIPADOM.h
$(masdom_LIB)(CGBMAIN.o): DIPC.h
$(masdom_LIB)(CGBMAIN.o): DIPDIM.h
$(masdom_LIB)(CGBMAIN.o): MASADOM.h
$(masdom_LIB)(CGBMAIN.o): MASBIOS.h
$(masdom_LIB)(CGBMAIN.o): MASBIOSU.h
$(masdom_LIB)(CGBMAIN.o): MASERR.h
$(masdom_LIB)(CGBMAIN.o): MASSTOR.h
$(masdom_LIB)(CGBMAIN.o): MASSYM2.h
$(masdom_LIB)(CGBMAIN.o): MLOGBASE.h
$(masdom_LIB)(CGBMAIN.o): PQBASE.h
$(masdom_LIB)(CGBMAIN.o): SACLIST.h
$(masdom_LIB)(CGBMAIN.o): SACPOL.h

$(masdom_LIB)(CGBMISC.o): CGBMISC.c CGBMISC.h
$(masdom_LIB)(CGBMISC.o): ADTOOLS.h
$(masdom_LIB)(CGBMISC.o): CGBAPPL.h
$(masdom_LIB)(CGBMISC.o): CGBDSTR.h
$(masdom_LIB)(CGBMISC.o): CGBFUNC.h
$(masdom_LIB)(CGBMISC.o): CGBSYS.h
$(masdom_LIB)(CGBMISC.o): DIPADOM.h
$(masdom_LIB)(CGBMISC.o): DIPC.h
$(masdom_LIB)(CGBMISC.o): DIPI.h
$(masdom_LIB)(CGBMISC.o): DIPIDGB.h
$(masdom_LIB)(CGBMISC.o): DIPIGB.h
$(masdom_LIB)(CGBMISC.o): DIPTOO.h
$(masdom_LIB)(CGBMISC.o): DIPTOOLS.h
$(masdom_LIB)(CGBMISC.o): MASADOM.h
$(masdom_LIB)(CGBMISC.o): MASBIOS.h
$(masdom_LIB)(CGBMISC.o): MASERR.h
$(masdom_LIB)(CGBMISC.o): MASSTOR.h
$(masdom_LIB)(CGBMISC.o): MASSYM2.h
$(masdom_LIB)(CGBMISC.o): SACLIST.h
$(masdom_LIB)(CGBMISC.o): SACPFAC.h
$(masdom_LIB)(CGBMISC.o): SACPOL.h

$(masdom_LIB)(CGBSYS.o): CGBSYS.c CGBSYS.h
$(masdom_LIB)(CGBSYS.o): CGBDSTR.h
$(masdom_LIB)(CGBSYS.o): CGBFUNC.h
$(masdom_LIB)(CGBSYS.o): CGBMAIN.h
$(masdom_LIB)(CGBSYS.o): CGBMISC.h
$(masdom_LIB)(CGBSYS.o): DIPADOM.h
$(masdom_LIB)(CGBSYS.o): DIPC.h
$(masdom_LIB)(CGBSYS.o): DIPRNGB.h
$(masdom_LIB)(CGBSYS.o): MASADOM.h
$(masdom_LIB)(CGBSYS.o): MASBIOS.h
$(masdom_LIB)(CGBSYS.o): MASERR.h
$(masdom_LIB)(CGBSYS.o): massig.h
$(masdom_LIB)(CGBSYS.o): MASSIGNAL.h
$(masdom_LIB)(CGBSYS.o): MASSTOR.h
$(masdom_LIB)(CGBSYS.o): SACLIST.h

# -EOF-
