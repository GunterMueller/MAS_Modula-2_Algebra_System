# ------------------------------------------------------------- -*-Makefile-*-
# Generated automatically using makemake for MAS
# $Id: makemake.awk,v 1.3 1995/10/24 14:36:56 pesch Exp $
# ----------------------------------------------------------------------------
# This file is part of MAS.
# ----------------------------------------------------------------------------
# Copyright (c) 1995 Universitaet Passau
# ----------------------------------------------------------------------------


maslog_MD= MASLOG.md MLDEMO.md MLOGBASE.md MLOGIO.md PQBASE.md PQSMPL.md RQEPRRC.md TFORM.md

maslog_MI= MASLOG.mi MLDEMO.mi MLOGBASE.mi MLOGIO.mi PQBASE.mi PQSMPL.mi RQEPRRC.mi TFORM.mi

maslog_MDP=

maslog_MIP=

maslog_CINC=

maslog_CSRC=

maslog_OBJS=$(maslog_CSRC:.c=.o) $(maslog_MI:.mi=.o) $(maslog_MIP:.mip=.o)

maslog_ALLSRC= MASLOG.md MLDEMO.md MLOGBASE.md MLOGIO.md PQBASE.md PQSMPL.md RQEPRRC.md TFORM.md MASLOG.mi MLDEMO.mi MLOGBASE.mi MLOGIO.mi PQBASE.mi PQSMPL.mi RQEPRRC.mi TFORM.mi

$(top_srcdir)/maslog/maslog.mk: $(maslog_ALLSRC) $(MAKEMAKE) $(MAKEMAKEAWK)

MASLOG.h: MASSTOR.h
MASLOG.h: MASLISPU.h
MASLOG.h: MLOGBASE.h

$(maslog_LIB)(MASLOG.o): MASLOG.c MASLOG.h
$(maslog_LIB)(MASLOG.o): MASBIOS.h
$(maslog_LIB)(MASLOG.o): MASELEM.h
$(maslog_LIB)(MASLOG.o): MASERR.h
$(maslog_LIB)(MASLOG.o): MASLISPU.h
$(maslog_LIB)(MASLOG.o): MASSET.h
$(maslog_LIB)(MASLOG.o): MASSTOR.h
$(maslog_LIB)(MASLOG.o): MASSYM2.h
$(maslog_LIB)(MASLOG.o): MLOGBASE.h
$(maslog_LIB)(MASLOG.o): SACLIST.h

MLDEMO.h: MASSTOR.h
MLDEMO.h: MASLISPU.h

$(maslog_LIB)(MLDEMO.o): MLDEMO.c MLDEMO.h
$(maslog_LIB)(MLDEMO.o): MASELEM.h
$(maslog_LIB)(MLDEMO.o): MASSTOR.h
$(maslog_LIB)(MLDEMO.o): MASERR.h
$(maslog_LIB)(MLDEMO.o): MASLISPU.h
$(maslog_LIB)(MLDEMO.o): MASBIOS.h
$(maslog_LIB)(MLDEMO.o): MASSYM.h
$(maslog_LIB)(MLDEMO.o): MASSYM2.h
$(maslog_LIB)(MLDEMO.o): SACLIST.h
$(maslog_LIB)(MLDEMO.o): MLOGBASE.h
$(maslog_LIB)(MLDEMO.o): MASLOG.h
$(maslog_LIB)(MLDEMO.o): MLOGIO.h

MLOGBASE.h: MASSTOR.h

$(maslog_LIB)(MLOGBASE.o): MLOGBASE.c MLOGBASE.h
$(maslog_LIB)(MLOGBASE.o): MASBIOS.h
$(maslog_LIB)(MLOGBASE.o): MASSTOR.h
$(maslog_LIB)(MLOGBASE.o): MASLISPU.h
$(maslog_LIB)(MLOGBASE.o): MASSYM.h
$(maslog_LIB)(MLOGBASE.o): MASSYM2.h
$(maslog_LIB)(MLOGBASE.o): SACLIST.h

MLOGIO.h: MASSTOR.h
MLOGIO.h: MASLISPU.h

$(maslog_LIB)(MLOGIO.o): MLOGIO.c MLOGIO.h
$(maslog_LIB)(MLOGIO.o): MASELEM.h
$(maslog_LIB)(MLOGIO.o): MASSTOR.h
$(maslog_LIB)(MLOGIO.o): MASERR.h
$(maslog_LIB)(MLOGIO.o): MASLISP.h
$(maslog_LIB)(MLOGIO.o): MASLISPU.h
$(maslog_LIB)(MLOGIO.o): MASBIOS.h
$(maslog_LIB)(MLOGIO.o): MASSYM.h
$(maslog_LIB)(MLOGIO.o): MASSYM2.h
$(maslog_LIB)(MLOGIO.o): SACLIST.h
$(maslog_LIB)(MLOGIO.o): MLOGBASE.h

PQBASE.h: MASSTOR.h

$(maslog_LIB)(PQBASE.o): PQBASE.c PQBASE.h
$(maslog_LIB)(PQBASE.o): DIPADOM.h
$(maslog_LIB)(PQBASE.o): DIPC.h
$(maslog_LIB)(PQBASE.o): DIPTOOLS.h
$(maslog_LIB)(PQBASE.o): DOMRN.h
$(maslog_LIB)(PQBASE.o): LISTTOOLS.h
$(maslog_LIB)(PQBASE.o): MASADOM.h
$(maslog_LIB)(PQBASE.o): MASBIOS.h
$(maslog_LIB)(PQBASE.o): MASELEM.h
$(maslog_LIB)(PQBASE.o): MASERR.h
$(maslog_LIB)(PQBASE.o): MASLISPU.h
$(maslog_LIB)(PQBASE.o): MASLOG.h
$(maslog_LIB)(PQBASE.o): MASSET.h
$(maslog_LIB)(PQBASE.o): MASSTOR.h
$(maslog_LIB)(PQBASE.o): MASSYM.h
$(maslog_LIB)(PQBASE.o): MASSYM2.h
$(maslog_LIB)(PQBASE.o): MLOGBASE.h
$(maslog_LIB)(PQBASE.o): MLOGIO.h
$(maslog_LIB)(PQBASE.o): SACLIST.h
$(maslog_LIB)(PQBASE.o): SACPOL.h
$(maslog_LIB)(PQBASE.o): SACSET.h

PQSMPL.h: MASSTOR.h
PQSMPL.h: MASLISPU.h

$(maslog_LIB)(PQSMPL.o): PQSMPL.c PQSMPL.h
$(maslog_LIB)(PQSMPL.o): MASELEM.h
$(maslog_LIB)(PQSMPL.o): MASSTOR.h
$(maslog_LIB)(PQSMPL.o): MASBIOS.h
$(maslog_LIB)(PQSMPL.o): SACLIST.h
$(maslog_LIB)(PQSMPL.o): MASERR.h
$(maslog_LIB)(PQSMPL.o): MASSYM.h
$(maslog_LIB)(PQSMPL.o): MASSYM2.h
$(maslog_LIB)(PQSMPL.o): MASLISPU.h
$(maslog_LIB)(PQSMPL.o): MLOGBASE.h
$(maslog_LIB)(PQSMPL.o): MASLOG.h
$(maslog_LIB)(PQSMPL.o): MLOGIO.h
$(maslog_LIB)(PQSMPL.o): DIPADOM.h
$(maslog_LIB)(PQSMPL.o): DIPC.h
$(maslog_LIB)(PQSMPL.o): DIPGB.h
$(maslog_LIB)(PQSMPL.o): MASADOM.h
$(maslog_LIB)(PQSMPL.o): SACSET.h
$(maslog_LIB)(PQSMPL.o): SACPOL.h
$(maslog_LIB)(PQSMPL.o): PQBASE.h
$(maslog_LIB)(PQSMPL.o): DIPTOOLS.h

RQEPRRC.h: MASLISPU.h
RQEPRRC.h: MASSTOR.h

$(maslog_LIB)(RQEPRRC.o): RQEPRRC.c RQEPRRC.h
$(maslog_LIB)(RQEPRRC.o): ADTOOLS.h
$(maslog_LIB)(RQEPRRC.o): CGBDSTR.h
$(maslog_LIB)(RQEPRRC.o): CGBFUNC.h
$(maslog_LIB)(RQEPRRC.o): CGBMISC.h
$(maslog_LIB)(RQEPRRC.o): CGBMAIN.h
$(maslog_LIB)(RQEPRRC.o): DIPADOM.h
$(maslog_LIB)(RQEPRRC.o): DIPC.h
$(maslog_LIB)(RQEPRRC.o): DIPDIM.h
$(maslog_LIB)(RQEPRRC.o): DIPRF.h
$(maslog_LIB)(RQEPRRC.o): DIPTOOLS.h
$(maslog_LIB)(RQEPRRC.o): LINALG.h
$(maslog_LIB)(RQEPRRC.o): LISTTOOLS.h
$(maslog_LIB)(RQEPRRC.o): MASADOM.h
$(maslog_LIB)(RQEPRRC.o): MASBIOS.h
$(maslog_LIB)(RQEPRRC.o): MASCOMB.h
$(maslog_LIB)(RQEPRRC.o): MASELEM.h
$(maslog_LIB)(RQEPRRC.o): MASERR.h
$(maslog_LIB)(RQEPRRC.o): MASLOG.h
$(maslog_LIB)(RQEPRRC.o): MASSET.h
$(maslog_LIB)(RQEPRRC.o): MASSTOR.h
$(maslog_LIB)(RQEPRRC.o): MASSYM2.h
$(maslog_LIB)(RQEPRRC.o): MLOGBASE.h
$(maslog_LIB)(RQEPRRC.o): PQBASE.h
$(maslog_LIB)(RQEPRRC.o): RRADOM.h
$(maslog_LIB)(RQEPRRC.o): SACCOMB.h
$(maslog_LIB)(RQEPRRC.o): SACIPOL.h
$(maslog_LIB)(RQEPRRC.o): SACLIST.h
$(maslog_LIB)(RQEPRRC.o): SACPOL.h
$(maslog_LIB)(RQEPRRC.o): SYSINFO.h
$(maslog_LIB)(RQEPRRC.o): TFORM.h

TFORM.h: MASLISPU.h
TFORM.h: MASSTOR.h

$(maslog_LIB)(TFORM.o): TFORM.c TFORM.h
$(maslog_LIB)(TFORM.o): MASBIOS.h
$(maslog_LIB)(TFORM.o): MASBIOSU.h
$(maslog_LIB)(TFORM.o): MASELEM.h
$(maslog_LIB)(TFORM.o): MASERR.h
$(maslog_LIB)(TFORM.o): MASLISPU.h
$(maslog_LIB)(TFORM.o): MASLOG.h
$(maslog_LIB)(TFORM.o): MASSET.h
$(maslog_LIB)(TFORM.o): MASSTOR.h
$(maslog_LIB)(TFORM.o): MASSYM.h
$(maslog_LIB)(TFORM.o): MASSYM2.h
$(maslog_LIB)(TFORM.o): MLOGBASE.h
$(maslog_LIB)(TFORM.o): MLOGIO.h
$(maslog_LIB)(TFORM.o): LISTTOOLS.h
$(maslog_LIB)(TFORM.o): PQBASE.h
$(maslog_LIB)(TFORM.o): SACLIST.h
$(maslog_LIB)(TFORM.o): SACSET.h

# -EOF-
