# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


masmain_MD= MASLOAD.md MASLOADA.md MASLOADB.md MASLOADC.md MASLOADD.md MASLOADE.md MASLOADG.md MASLOADJ.md MASLOADL.md MASLOADM.md MASLOADQ.md MASLOADS.md MASU.md MASYMDIP.md MLMASLOG.md MLMLDEMO.md MLPQSMPL.md

masmain_MI= MAS.mi MASLOAD.mi MASLOADA.mi MASLOADB.mi MASLOADC.mi MASLOADD.mi MASLOADE.mi MASLOADG.mi MASLOADJ.mi MASLOADL.mi MASLOADM.mi MASLOADQ.mi MASLOADS.mi MASU.mi MASYMDIP.mi MLMASLOG.mi MLMLDEMO.mi MLPQSMPL.mi

masmain_MDP=

masmain_MIP=

masmain_CINC=

masmain_CSRC=

masmain_OBJS=$(masmain_CSRC:.c=.o) $(masmain_MI:.mi=.o) $(masmain_MIP:.mip=.o)

masmain_ALLSRC= MASLOAD.md MASLOADA.md MASLOADB.md MASLOADC.md MASLOADD.md MASLOADE.md MASLOADG.md MASLOADJ.md MASLOADL.md MASLOADM.md MASLOADQ.md MASLOADS.md MASU.md MASYMDIP.md MLMASLOG.md MLMLDEMO.md MLPQSMPL.md MAS.mi MASLOAD.mi MASLOADA.mi MASLOADB.mi MASLOADC.mi MASLOADD.mi MASLOADE.mi MASLOADG.mi MASLOADJ.mi MASLOADL.mi MASLOADM.mi MASLOADQ.mi MASLOADS.mi MASU.mi MASYMDIP.mi MLMASLOG.mi MLMLDEMO.mi MLPQSMPL.mi

$(top_srcdir)/masmain/masmain.mk: $(masmain_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

$(masmain_LIB)(MAS.o): MAS.c
$(masmain_LIB)(MAS.o): MASCONF.h
$(masmain_LIB)(MAS.o): MASSTOR.h
$(masmain_LIB)(MAS.o): MASERR.h
$(masmain_LIB)(MAS.o): MASBIOS.h
$(masmain_LIB)(MAS.o): MASSYM.h
$(masmain_LIB)(MAS.o): MASLISP.h
$(masmain_LIB)(MAS.o): MASSPEC.h
$(masmain_LIB)(MAS.o): MASLOAD.h
$(masmain_LIB)(MAS.o): MASU.h


$(masmain_LIB)(MASLOAD.o): MASLOAD.c MASLOAD.h
$(masmain_LIB)(MASLOAD.o): MASLOADA.h
$(masmain_LIB)(MASLOAD.o): MASLOADB.h
$(masmain_LIB)(MASLOAD.o): MASLOADC.h
$(masmain_LIB)(MASLOAD.o): MASLOADD.h
$(masmain_LIB)(MASLOAD.o): MASLOADE.h
$(masmain_LIB)(MASLOAD.o): MASLOADG.h
$(masmain_LIB)(MASLOAD.o): MASLOADJ.h
$(masmain_LIB)(MASLOAD.o): MASLOADL.h
$(masmain_LIB)(MASLOAD.o): MASLOADM.h
$(masmain_LIB)(MASLOAD.o): MASLOADS.h
$(masmain_LIB)(MASLOAD.o): MASLOADQ.h
$(masmain_LIB)(MASLOAD.o): MLMASLOG.h
$(masmain_LIB)(MASLOAD.o): MLMLDEMO.h
$(masmain_LIB)(MASLOAD.o): MLPQSMPL.h


$(masmain_LIB)(MASLOADA.o): MASLOADA.c MASLOADA.h
$(masmain_LIB)(MASLOADA.o): MASSTOR.h
$(masmain_LIB)(MASLOADA.o): MASLISPU.h
$(masmain_LIB)(MASLOADA.o): SACI.h
$(masmain_LIB)(MASLOADA.o): SACCOMB.h
$(masmain_LIB)(MASLOADA.o): SACRN.h
$(masmain_LIB)(MASLOADA.o): SACM.h
$(masmain_LIB)(MASLOADA.o): MASRN.h
$(masmain_LIB)(MASLOADA.o): MASI.h
$(masmain_LIB)(MASLOADA.o): MASAPF.h
$(masmain_LIB)(MASLOADA.o): SACPRIM.h
$(masmain_LIB)(MASLOADA.o): MASF.h


$(masmain_LIB)(MASLOADB.o): MASLOADB.c MASLOADB.h
$(masmain_LIB)(MASLOADB.o): MASLISPU.h
$(masmain_LIB)(MASLOADB.o): SACPOL.h
$(masmain_LIB)(MASLOADB.o): SACDPOL.h
$(masmain_LIB)(MASLOADB.o): SACIPOL.h
$(masmain_LIB)(MASLOADB.o): SACPGCD.h
$(masmain_LIB)(MASLOADB.o): SACPFAC.h
$(masmain_LIB)(MASLOADB.o): SACROOT.h
$(masmain_LIB)(MASLOADB.o): DIPC.h
$(masmain_LIB)(MASLOADB.o): DIPI.h
$(masmain_LIB)(MASLOADB.o): DIPRN.h
$(masmain_LIB)(MASLOADB.o): DIPRNPOL.h
$(masmain_LIB)(MASLOADB.o): DIPRNGB.h
$(masmain_LIB)(MASLOADB.o): DIPIGB.h
$(masmain_LIB)(MASLOADB.o): DIPGCD.h
$(masmain_LIB)(MASLOADB.o): DIPTOO.h
$(masmain_LIB)(MASLOADB.o): MASYMDIP.h


$(masmain_LIB)(MASLOADC.o): MASLOADC.c MASLOADC.h
$(masmain_LIB)(MASLOADC.o): MASSTOR.h
$(masmain_LIB)(MASLOADC.o): MASLISPU.h
$(masmain_LIB)(MASLOADC.o): MASBIOS.h
$(masmain_LIB)(MASLOADC.o): SACLIST.h
$(masmain_LIB)(MASLOADC.o): SACPOL.h
$(masmain_LIB)(MASLOADC.o): DIPC.h
$(masmain_LIB)(MASLOADC.o): DIPI.h
$(masmain_LIB)(MASLOADC.o): DIPRN.h
$(masmain_LIB)(MASLOADC.o): MASNC.h
$(masmain_LIB)(MASLOADC.o): MASNCGB.h
$(masmain_LIB)(MASLOADC.o): MASNCC.h


$(masmain_LIB)(MASLOADD.o): MASLOADD.c MASLOADD.h
$(masmain_LIB)(MASLOADD.o): MASSTOR.h
$(masmain_LIB)(MASLOADD.o): MASLISPU.h
$(masmain_LIB)(MASLOADD.o): DIPC.h
$(masmain_LIB)(MASLOADD.o): DIPROOT.h
$(masmain_LIB)(MASLOADD.o): DIPDEC0.h
$(masmain_LIB)(MASLOADD.o): DIPDIM.h
$(masmain_LIB)(MASLOADD.o): DIPIDEAL.h
$(masmain_LIB)(MASLOADD.o): MASUGB.h
$(masmain_LIB)(MASLOADD.o): DIPIDGB.h


$(masmain_LIB)(MASLOADE.o): MASLOADE.c MASLOADE.h
$(masmain_LIB)(MASLOADE.o): MASLISPU.h
$(masmain_LIB)(MASLOADE.o): DIPADOM.h
$(masmain_LIB)(MASLOADE.o): MASADOM.h
$(masmain_LIB)(MASLOADE.o): DIPTOOLS.h
$(masmain_LIB)(MASLOADE.o): DINNGB.h
$(masmain_LIB)(MASLOADE.o): DOMAF.h
$(masmain_LIB)(MASLOADE.o): DOMI.h
$(masmain_LIB)(MASLOADE.o): DOMFF.h
$(masmain_LIB)(MASLOADE.o): DOMIP.h
$(masmain_LIB)(MASLOADE.o): DOMMD.h
$(masmain_LIB)(MASLOADE.o): DOMMI.h
$(masmain_LIB)(MASLOADE.o): DOMRF.h
$(masmain_LIB)(MASLOADE.o): DOMRN.h
$(masmain_LIB)(MASLOADE.o): DOMRP.h
$(masmain_LIB)(MASLOADE.o): DOMC.h
$(masmain_LIB)(MASLOADE.o): CGBMAIN.h
$(masmain_LIB)(MASLOADE.o): CGBDSTR.h
$(masmain_LIB)(MASLOADE.o): CGBMISC.h
$(masmain_LIB)(MASLOADE.o): DOMQ.h
$(masmain_LIB)(MASLOADE.o): DOMO.h
$(masmain_LIB)(MASLOADE.o): DOMAPF.h
$(masmain_LIB)(MASLOADE.o): DIPGB.h
$(masmain_LIB)(MASLOADE.o): DIPDDGB.h
$(masmain_LIB)(MASLOADE.o): DIPDCGB.h
$(masmain_LIB)(MASLOADE.o): DIPAGB.h
$(masmain_LIB)(MASLOADE.o): ADTOOLS.h


$(masmain_LIB)(MASLOADG.o): MASLOADG.c MASLOADG.h
$(masmain_LIB)(MASLOADG.o): GSYMFUIN.h
$(masmain_LIB)(MASLOADG.o): GSYMFURN.h
$(masmain_LIB)(MASLOADG.o): GSYMINP.h
$(masmain_LIB)(MASLOADG.o): MASLISPU.h
$(masmain_LIB)(MASLOADG.o): NOETHER.h
$(masmain_LIB)(MASLOADG.o): TIPRNGB.h
$(masmain_LIB)(MASLOADG.o): SACPOL.h
$(masmain_LIB)(MASLOADG.o): SUBST.h


$(masmain_LIB)(MASLOADJ.o): MASLOADJ.c MASLOADJ.h
$(masmain_LIB)(MASLOADJ.o): ADEXTRA.h
$(masmain_LIB)(MASLOADJ.o): DIPDCIB.h
$(masmain_LIB)(MASLOADJ.o): DIPIB.h
$(masmain_LIB)(MASLOADJ.o): DIPIIB.h
$(masmain_LIB)(MASLOADJ.o): DIPRNIB.h
$(masmain_LIB)(MASLOADJ.o): MASLISPU.h
$(masmain_LIB)(MASLOADJ.o): MASSTOR.h


$(masmain_LIB)(MASLOADL.o): MASLOADL.c MASLOADL.h
$(masmain_LIB)(MASLOADL.o): MASLISPU.h
$(masmain_LIB)(MASLOADL.o): LINALGRN.h
$(masmain_LIB)(MASLOADL.o): LINALGI.h
$(masmain_LIB)(MASLOADL.o): SACLDIO.h


$(masmain_LIB)(MASLOADM.o): MASLOADM.c MASLOADM.h
$(masmain_LIB)(MASLOADM.o): MASLISPU.h
$(masmain_LIB)(MASLOADM.o): LINALG.h
$(masmain_LIB)(MASLOADM.o): RRADOM.h
$(masmain_LIB)(MASLOADM.o): RRINT.h
$(masmain_LIB)(MASLOADM.o): RRUADOM.h
$(masmain_LIB)(MASLOADM.o): RRUINT.h


$(masmain_LIB)(MASLOADQ.o): MASLOADQ.c MASLOADQ.h
$(masmain_LIB)(MASLOADQ.o): MASSTOR.h
$(masmain_LIB)(MASLOADQ.o): MASLISPU.h
$(masmain_LIB)(MASLOADQ.o): MASC.h
$(masmain_LIB)(MASLOADQ.o): MASQ.h
$(masmain_LIB)(MASLOADQ.o): MASO.h
$(masmain_LIB)(MASLOADQ.o): MASFF.h


$(masmain_LIB)(MASLOADS.o): MASLOADS.c MASLOADS.h
$(masmain_LIB)(MASLOADS.o): MASSTOR.h
$(masmain_LIB)(MASLOADS.o): MASLISPU.h
$(masmain_LIB)(MASLOADS.o): SYZMAIN.h
$(masmain_LIB)(MASLOADS.o): SYZGB.h
$(masmain_LIB)(MASLOADS.o): SYZHLP.h

MASU.h: MASSTOR.h

$(masmain_LIB)(MASU.o): MASU.c MASU.h
$(masmain_LIB)(MASU.o): MASELEM.h
$(masmain_LIB)(MASU.o): MASSTOR.h
$(masmain_LIB)(MASU.o): MASBIOS.h
$(masmain_LIB)(MASU.o): MASBIOSU.h
$(masmain_LIB)(MASU.o): SACLIST.h
$(masmain_LIB)(MASU.o): MASSYM2.h
$(masmain_LIB)(MASU.o): MASSYM.h
$(masmain_LIB)(MASU.o): MASLISPU.h
$(masmain_LIB)(MASU.o): MASLISP.h
$(masmain_LIB)(MASU.o): MASSPEC.h
$(masmain_LIB)(MASU.o): MASREP.h
$(masmain_LIB)(MASU.o): MASPARSE.h
$(masmain_LIB)(MASU.o): ALDPARSE.h

MASYMDIP.h: MASSTOR.h

$(masmain_LIB)(MASYMDIP.o): MASYMDIP.c MASYMDIP.h
$(masmain_LIB)(MASYMDIP.o): MASSTOR.h
$(masmain_LIB)(MASYMDIP.o): MASERR.h
$(masmain_LIB)(MASYMDIP.o): MASBIOS.h
$(masmain_LIB)(MASYMDIP.o): MASBIOSU.h
$(masmain_LIB)(MASYMDIP.o): SACLIST.h
$(masmain_LIB)(MASYMDIP.o): SACSET.h
$(masmain_LIB)(MASYMDIP.o): MASSYM2.h
$(masmain_LIB)(MASYMDIP.o): MASSYM.h
$(masmain_LIB)(MASYMDIP.o): MASLISPU.h
$(masmain_LIB)(MASYMDIP.o): MASLISP.h
$(masmain_LIB)(MASYMDIP.o): MASSPEC.h
$(masmain_LIB)(MASYMDIP.o): SACRN.h
$(masmain_LIB)(MASYMDIP.o): MASAPF.h
$(masmain_LIB)(MASYMDIP.o): SACPOL.h
$(masmain_LIB)(MASYMDIP.o): DIPC.h
$(masmain_LIB)(MASYMDIP.o): DIPI.h
$(masmain_LIB)(MASYMDIP.o): DIPRN.h
$(masmain_LIB)(MASYMDIP.o): DIPTOO.h

MLMASLOG.h: MASSTOR.h

$(masmain_LIB)(MLMASLOG.o): MLMASLOG.c MLMASLOG.h
$(masmain_LIB)(MLMASLOG.o): MASLOG.h
$(masmain_LIB)(MLMASLOG.o): MLOGBASE.h
$(masmain_LIB)(MLMASLOG.o): MLOGIO.h
$(masmain_LIB)(MLMASLOG.o): MODVAR.h
$(masmain_LIB)(MLMASLOG.o): MASLISPU.h
$(masmain_LIB)(MLMASLOG.o): PQBASE.h
$(masmain_LIB)(MLMASLOG.o): RQEPRRC.h
$(masmain_LIB)(MLMASLOG.o): SYSINFO.h
$(masmain_LIB)(MLMASLOG.o): TFORM.h

MLMLDEMO.h: MASSTOR.h

$(masmain_LIB)(MLMLDEMO.o): MLMLDEMO.c MLMLDEMO.h
$(masmain_LIB)(MLMLDEMO.o): MLDEMO.h
$(masmain_LIB)(MLMLDEMO.o): MASLISPU.h

MLPQSMPL.h: MASSTOR.h

$(masmain_LIB)(MLPQSMPL.o): MLPQSMPL.c MLPQSMPL.h
$(masmain_LIB)(MLPQSMPL.o): MASLISPU.h
$(masmain_LIB)(MLPQSMPL.o): PQSMPL.h

# -EOF-
