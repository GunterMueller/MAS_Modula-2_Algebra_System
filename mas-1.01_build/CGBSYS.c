#include "SYSTEM_.h"

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

#ifndef DEFINITION_CGBMAIN
#include "CGBMAIN.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_MASSIGNAL
#include "MASSIGNAL.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_CGBSYS
#include "CGBSYS.h"
#endif

CHAR CGBSYS_rcsid [] = "$Id: CGBSYS.md,v 1.9 1996/06/08 16:47:14 pesch Exp $";
CHAR CGBSYS_copyright [] = "Copyright (c) 1989 - 1996 Universitaet Passau";

static CHAR rcsidi [] = "$Id: CGBSYS.mip,v 1.16 1996/06/08 16:47:15 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1996 Universitaet Passau";
static MASSTOR_LIST *pGSYS, *pCOND;
static void SigUsr1HandleCONSGB ARGS((INTEGER signo));
static MASSTOR_LIST CONSGB ARGS((MASSTOR_LIST BB, MASSTOR_LIST GSYS));
static void SigUsr1HandleCONSGBF ARGS((INTEGER signo));
static MASSTOR_LIST CONSGBF ARGS((MASSTOR_LIST BB, MASSTOR_LIST GSYS));


void CGBSYS_GRED
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PCO, MASSTOR_LIST PCI, MASSTOR_LIST RE, MASSTOR_LIST *RCO, MASSTOR_LIST *HA)
# else
(COND, PCO, PCI, RE, RCO, HA)
MASSTOR_LIST COND, PCO, PCI, RE;
MASSTOR_LIST *RCO, *HA;
# endif
{
  MASSTOR_LIST AL, ALIST, AP, APP, C, EL, FCOL, FL, FPOL, GCOL, GPOL, HE, KEY, Q, RA, RAL, RAP, RCOLS, RPOL, TL;

  CGBDSTR_ColpParts(PCO, &FPOL, &FCOL);
  CGBDSTR_ColpParts(PCI, &GPOL, &GCOL);
  if (!CGBDSTR_CondIsEmpty(COND)) {
    GCOL = CGBFUNC_SETCOL(COND, GCOL);
  }
  HE = CGBDSTR_ColpHT(PCI);
  CGBSYS_KEYCOL(RE, FCOL, &KEY, &ALIST);
  *RCO = MASSTOR_SIL;
  Q = MASSTOR_SIL;
  RA = CGBFUNC_FINDBC(RE, FPOL);
  if (HE == MASSTOR_SIL) {
    *HA = MASADOM_ADFI(RA, 0);
    EL = RE;
  } else {
    *HA = CGBFUNC_FINDBC(HE, GPOL);
    EL = DIPC_EVDIF(RE, HE);
  }
  MASSTOR_ADV(RA, &RAL, &RAP);
  FL = MASSTOR_FIRST(RAP);
  TL = DIPC_EVSIGN(EL);
  if (ALIST != MASSTOR_SIL) {
    AP = DIPC_DIPFMO(RA, EL);
    APP = DIPADOM_DIPROD(GPOL, AP);
    FPOL = DIPADOM_DIPBCP(FPOL, *HA);
    GCOL = CGBSYS_WHSRT(GCOL, EL, ALIST);
  } else {
    MASADOM_ADGCDC(RA, *HA, &C, &RA, HA);
    AP = DIPC_DIPFMO(RA, EL);
    APP = DIPADOM_DIPROD(GPOL, AP);
    FPOL = DIPADOM_DIPBCP(FPOL, *HA);
    if (TL != 0) {
      GCOL = CGBSYS_COLPRD(GCOL, EL);
    }
  }
  CGBSYS_GBDIFF(COND, FPOL, FCOL, APP, GCOL, &RPOL, &RCOLS);
  if (RPOL != 0) {
    AL = DIPC_DIPLBC(RPOL);
    if (MASADOM_ADSIGN(AL) == -1) {
      RPOL = DIPADOM_DIPNEG(RPOL);
    }
    if (!CGBDSTR_ColIsEmpty(RCOLS)) {
      *RCO = CGBDSTR_ColpCons(RPOL, RCOLS);
    }
  }
  return;
}

void CGBSYS_GBDIFF
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST C_108_A, MASSTOR_LIST ACOLS, MASSTOR_LIST B, MASSTOR_LIST BCOLS, MASSTOR_LIST *C, MASSTOR_LIST *CCOLS)
# else
(COND, C_108_A, ACOLS, B, BCOLS, C, CCOLS)
MASSTOR_LIST COND, C_108_A, ACOLS, B, BCOLS;
MASSTOR_LIST *C, *CCOLS;
# endif
{
  MASSTOR_LIST AKEY, AL, ALIST, APP, BKEY, BL, BLIST, CL, CP, CPP, EL, FL, R, SL, W;

  if (C_108_A == 0) {
    *C = B;
    *CCOLS = BCOLS;
    return;
  }
  if (B == 0) {
    *C = C_108_A;
    *CCOLS = ACOLS;
    return;
  }
  CP = MASSTOR_SIL;
  R = MASSTOR_SIL;
  W = MASSTOR_SIL;
  do {
    EL = DIPC_DIPEVL(C_108_A);
    FL = DIPC_DIPEVL(B);
    SL = DIPC_EVCOMP(EL, FL);
    if (SL == 1) {
      DIPC_DIPMAD(C_108_A, &AL, &EL, &C_108_A);
      CGBSYS_COLDIF(EL, ACOLS, R, W, &R, &W);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else if (SL == -1) {
      DIPC_DIPMAD(B, &BL, &FL, &B);
      CGBSYS_COLDIF(FL, BCOLS, R, W, &R, &W);
      CL = MASADOM_ADNEG(BL);
      CP = DIPC_DIPMCP(FL, CL, CP);
    } else {
      DIPC_DIPMAD(C_108_A, &AL, &EL, &C_108_A);
      DIPC_DIPMAD(B, &BL, &FL, &B);
      CL = MASADOM_ADDIF(AL, BL);
      if (MASADOM_ADSIGN(CL) != 0) {
        CP = DIPC_DIPMCP(EL, CL, CP);
        CGBSYS_KEYCOL(EL, ACOLS, &AKEY, &ALIST);
        CGBSYS_KEYCOL(FL, BCOLS, &BKEY, &BLIST);
        if (AKEY != 0 && BKEY == 0) {
          CGBSYS_MKACOL(ALIST, EL, R, W, &R, &W);
        }
        if (AKEY == 0 && BKEY != 0) {
          CGBSYS_MKACOL(BLIST, EL, R, W, &R, &W);
        }
        if (AKEY != 0 && BKEY != 0) {
          CGBSYS_MKCOL(COND, CL, EL, R, W, &R, &W);
        }
      }
    }
  } while (!(C_108_A == MASSTOR_SIL || B == MASSTOR_SIL));
  APP = C_108_A;
  if (C_108_A != MASSTOR_SIL) {
    CGBSYS_FINCOL(C_108_A, ACOLS, R, W, &R, &W);
  }
  if (B != MASSTOR_SIL) {
    CGBSYS_FINCOL(B, BCOLS, R, W, &R, &W);
  }
  if (C_108_A == MASSTOR_SIL) {
    if (B != MASSTOR_SIL) {
      APP = DIPADOM_DIPNEG(B);
    }
  }
  if (CP == MASSTOR_SIL) {
    *C = APP;
  } else {
    CPP = CP;
    *C = MASSTOR_INV(CP);
    MASSTOR_SRED(CPP, APP);
  }
  if (*C == MASSTOR_SIL) {
    *C = 0;
    *CCOLS = CGBDSTR_ColEmpty();
  } else {
    if (R != MASSTOR_SIL) {
      R = MASSTOR_INV(R);
    }
    if (W != MASSTOR_SIL) {
      W = MASSTOR_INV(W);
    }
    *CCOLS = CGBDSTR_ColCons(R, W);
  }
  return;
}

MASSTOR_LIST CGBSYS_COLPRD
# ifdef __STDC__
(MASSTOR_LIST COL1, MASSTOR_LIST TTERM)
# else
(COL1, TTERM)
MASSTOR_LIST COL1, TTERM;
# endif
{
  MASSTOR_LIST CRED, CWHITE;

  if (CGBDSTR_ColIsEmpty(COL1)) {
    return CGBDSTR_ColEmpty();
  }
  CGBDSTR_ColParts(COL1, &CRED, &CWHITE);
  if (CRED != MASSTOR_SIL) {
    CRED = CGBSYS_CMULT(CRED, TTERM, 1);
  }
  if (CWHITE != MASSTOR_SIL) {
    CWHITE = CGBSYS_CMULT(CWHITE, TTERM, 2);
  }
  return CGBDSTR_ColCons(CRED, CWHITE);
}

MASSTOR_LIST CGBSYS_CMULT
# ifdef __STDC__
(MASSTOR_LIST ONECL, MASSTOR_LIST TTERM, MASSTOR_LIST B)
# else
(ONECL, TTERM, B)
MASSTOR_LIST ONECL, TTERM, B;
# endif
{
  MASSTOR_LIST CCOL, CELEM, QLIST, T, TELEM;

  CCOL = MASSTOR_SIL;
  while (ONECL != MASSTOR_SIL) {
    MASSTOR_ADV(ONECL, &TELEM, &ONECL);
    if (B == 2) {
      SACLIST_FIRST2(TELEM, &T, &QLIST);
    } else {
      T = TELEM;
    }
    T = DIPC_EVSUM(TTERM, T);
    if (B == 2) {
      CELEM = SACLIST_LIST2(T, QLIST);
      CCOL = MASSTOR_COMP(CELEM, CCOL);
    } else {
      CCOL = MASSTOR_COMP(T, CCOL);
    }
  }
  return MASSTOR_INV(CCOL);
}

MASSTOR_LIST CGBSYS_WHSRT
# ifdef __STDC__
(MASSTOR_LIST COL, MASSTOR_LIST TTERM, MASSTOR_LIST ALIST)
# else
(COL, TTERM, ALIST)
MASSTOR_LIST COL, TTERM, ALIST;
# endif
{
  MASSTOR_LIST AL, BL, BLIST, CP, CRED, CWHIT0, CWHITE, CWHITP, SL;

  if (CGBDSTR_ColIsEmpty(COL)) {
    return CGBDSTR_ColEmpty();
  }
  SACLIST_FIRST2(COL, &CRED, &CWHITE);
  CWHIT0 = MASSTOR_SIL;
  if (CWHITE != MASSTOR_SIL && CRED != MASSTOR_SIL) {
    do {
      MASSTOR_ADV(CRED, &AL, &CRED);
      do {
        MASSTOR_ADV(CWHITE, &CP, &CWHITP);
        SACLIST_FIRST2(CP, &BL, &BLIST);
        SL = DIPC_EVCOMP(AL, BL);
        if (SL == 1) {
          CWHIT0 = MASSTOR_COMP(SACLIST_LIST2(DIPC_EVSUM(TTERM, AL), ALIST), CWHIT0);
        } else {
          CWHIT0 = MASSTOR_COMP(SACLIST_LIST2(DIPC_EVSUM(TTERM, BL), CGBSYS_WUPD(ALIST, BLIST)), CWHIT0);
          CWHITE = CWHITP;
        }
      } while (!(SL == 1 || CWHITE == MASSTOR_SIL));
      if (SL <= 0) {
        CWHIT0 = MASSTOR_COMP(SACLIST_LIST2(DIPC_EVSUM(TTERM, AL), ALIST), CWHIT0);
      }
    } while (!(CRED == MASSTOR_SIL || CWHITE == MASSTOR_SIL));
  }
  if (CWHITE == MASSTOR_SIL && CRED == MASSTOR_SIL) {
    return SACLIST_LIST2(MASSTOR_SIL, MASSTOR_INV(CWHIT0));
  }
  while (CRED != MASSTOR_SIL) {
    MASSTOR_ADV(CRED, &AL, &CRED);
    CWHIT0 = MASSTOR_COMP(SACLIST_LIST2(DIPC_EVSUM(TTERM, AL), ALIST), CWHIT0);
  }
  while (CWHITE != MASSTOR_SIL) {
    MASSTOR_ADV(CWHITE, &CP, &CWHITE);
    SACLIST_FIRST2(CP, &BL, &BLIST);
    CWHIT0 = MASSTOR_COMP(SACLIST_LIST2(DIPC_EVSUM(TTERM, BL), CGBSYS_WUPD(ALIST, BLIST)), CWHIT0);
  }
  return SACLIST_LIST2(MASSTOR_SIL, MASSTOR_INV(CWHIT0));
}

MASSTOR_LIST CGBSYS_WUPD
# ifdef __STDC__
(MASSTOR_LIST ALIST, MASSTOR_LIST BLIST)
# else
(ALIST, BLIST)
MASSTOR_LIST ALIST, BLIST;
# endif
{
  MASSTOR_LIST C_107_A, CLIST, SL;

  if (ALIST == BLIST) {
    return BLIST;
  }
  if (BLIST == MASSTOR_SIL) {
    return ALIST;
  }
  CLIST = BLIST;
  while (ALIST != MASSTOR_SIL) {
    MASSTOR_ADV(ALIST, &C_107_A, &ALIST);
    if (SACLIST_MEMBER(C_107_A, BLIST) == 0) {
      CLIST = MASSTOR_COMP(C_107_A, CLIST);
    }
  }
  return CLIST;
}

void CGBSYS_COLDIF
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST ACOLS, MASSTOR_LIST COLR, MASSTOR_LIST COLW, MASSTOR_LIST *CRED, MASSTOR_LIST *CWHITE)
# else
(T, ACOLS, COLR, COLW, CRED, CWHITE)
MASSTOR_LIST T, ACOLS, COLR, COLW;
MASSTOR_LIST *CRED, *CWHITE;
# endif
{
  MASSTOR_LIST ACRED, ACWHIT, CP;

  SACLIST_FIRST2(ACOLS, &ACRED, &ACWHIT);
  *CRED = COLR;
  *CWHITE = COLW;
  if (SACLIST_MEMBER(T, ACRED) == 1) {
    *CRED = MASSTOR_COMP(T, *CRED);
    return;
  }
  CP = CGBFUNC_FINDCP(T, ACWHIT);
  if (CP != MASSTOR_SIL) {
    *CWHITE = MASSTOR_COMP(CP, *CWHITE);
  }
  return;
}

void CGBSYS_KEYCOL
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST ACOLS, MASSTOR_LIST *KEY, MASSTOR_LIST *ALIST)
# else
(EL, ACOLS, KEY, ALIST)
MASSTOR_LIST EL, ACOLS;
MASSTOR_LIST *KEY, *ALIST;
# endif
{
  MASSTOR_LIST ACRED, ACWHIT, CP;

  *ALIST = MASSTOR_SIL;
  *KEY = 0;
  SACLIST_FIRST2(ACOLS, &ACRED, &ACWHIT);
  if (SACLIST_MEMBER(EL, ACRED) == 1) {
    *KEY = 1;
    return;
  }
  CP = CGBFUNC_FINDCP(EL, ACWHIT);
  if (CP != MASSTOR_SIL) {
    *KEY = 2;
    *ALIST = SACLIST_SECOND(CP);
  }
  return;
}

void CGBSYS_MKACOL
# ifdef __STDC__
(MASSTOR_LIST ALIST, MASSTOR_LIST EL, MASSTOR_LIST COLR, MASSTOR_LIST COLW, MASSTOR_LIST *CRED, MASSTOR_LIST *CWHITE)
# else
(ALIST, EL, COLR, COLW, CRED, CWHITE)
MASSTOR_LIST ALIST, EL, COLR, COLW;
MASSTOR_LIST *CRED, *CWHITE;
# endif
{
  *CRED = COLR;
  *CWHITE = COLW;
  if (ALIST == MASSTOR_SIL) {
    *CRED = MASSTOR_COMP(EL, *CRED);
    return;
  }
  *CWHITE = MASSTOR_COMP(SACLIST_LIST2(EL, ALIST), *CWHITE);
  return;
}

void CGBSYS_MKCOL
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST CA, MASSTOR_LIST CE, MASSTOR_LIST COLR, MASSTOR_LIST COLW, MASSTOR_LIST *CRED, MASSTOR_LIST *CWHITE)
# else
(COND, CA, CE, COLR, COLW, CRED, CWHITE)
MASSTOR_LIST COND, CA, CE, COLR, COLW;
MASSTOR_LIST *CRED, *CWHITE;
# endif
{
  MASSTOR_LIST C_106_A, CL, PACK, QALIST, WFACTS;
  CGBMISC_COLOUR C;

  *CRED = COLR;
  *CWHITE = COLW;
  if ((*CGBMISC_PAR.IsCnst)(CA)) {
    *CRED = MASSTOR_COMP(CE, *CRED);
    return;
  }
  QALIST = (*CGBMISC_PAR.Factorize)(CA);
  WFACTS = MASSTOR_SIL;
  CL = 0;
  while (QALIST != MASSTOR_SIL && CL == 0) {
    MASSTOR_ADV(QALIST, &C_106_A, &QALIST);
    if (!(*CGBMISC_PAR.IsCnst)(C_106_A)) {
      C = (*CGBMISC_PAR.CondEval)(COND, C_106_A);
      if (C == CGBMISC_unknown) {
        WFACTS = MASSTOR_COMP(C_106_A, WFACTS);
      } else if (C == CGBMISC_zero) {
        CL = 1;
      }
    }
  }
  if (CL == 0) {
    if (WFACTS == MASSTOR_SIL) {
      *CRED = MASSTOR_COMP(CE, *CRED);
    } else {
      PACK = SACLIST_LIST2(CE, WFACTS);
      *CWHITE = MASSTOR_COMP(PACK, *CWHITE);
    }
  }
  return;
}

void CGBSYS_FINCOL
# ifdef __STDC__
(MASSTOR_LIST APP, MASSTOR_LIST ACOLS, MASSTOR_LIST COLR, MASSTOR_LIST COLW, MASSTOR_LIST *CRED, MASSTOR_LIST *CWHITE)
# else
(APP, ACOLS, COLR, COLW, CRED, CWHITE)
MASSTOR_LIST APP, ACOLS, COLR, COLW;
MASSTOR_LIST *CRED, *CWHITE;
# endif
{
  MASSTOR_LIST AL, EL;

  *CRED = COLR;
  *CWHITE = COLW;
  while (APP != MASSTOR_SIL) {
    DIPC_DIPMAD(APP, &AL, &EL, &APP);
    CGBSYS_COLDIF(EL, ACOLS, *CRED, *CWHITE, CRED, CWHITE);
  }
  return;
}

void CGBSYS_NFORM
# ifdef __STDC__
(MASSTOR_LIST GA, MASSTOR_LIST FCO, MASSTOR_LIST P, MASSTOR_LIST *N0, MASSTOR_LIST *N1)
# else
(GA, FCO, P, N0, N1)
MASSTOR_LIST GA, FCO, P;
MASSTOR_LIST *N0, *N1;
# endif
{
  MASSTOR_LIST C, CCL, COL, COND, D, DCOND, DL, F, PCI, PCO, POL, QC, RE;

  *N0 = MASSTOR_SIL;
  *N1 = MASSTOR_SIL;
  if (FCO == MASSTOR_SIL) {
    return;
  }
  COND = GA;
  F = CGBDSTR_ColpPol(FCO);
  C = MASADOM_ADFI(DIPC_DIPLBC(F), 1);
  if (CGBDSTR_ColpIsZero(FCO)) {
    *N0 = SACLIST_LIST3(COND, FCO, C);
    return;
  }
  if (P == MASSTOR_SIL) {
    *N1 = SACLIST_LIST3(COND, FCO, C);
    return;
  }
  PCO = FCO;
  for (;;) {
    if (CGBDSTR_ColpIsZero(PCO)) {
      *N0 = SACLIST_LIST3(COND, PCO, C);
      goto EXIT_1;
    }
    CGBSYS_FINDPI(PCO, P, &PCI, &RE);
    if (PCI == MASSTOR_SIL) {
      goto EXIT_1;
    }
    CGBSYS_GRED(COND, PCO, PCI, RE, &PCO, &QC);
    C = MASADOM_ADPROD(C, QC);
  } EXIT_1:;
  if (*N0 != MASSTOR_SIL) {
    return;
  }
  if (CGBDSTR_ColpHT(PCO) != MASSTOR_SIL) {
    *N1 = SACLIST_LIST3(COND, PCO, C);
    return;
  }
  CGBDSTR_ColpParts(PCO, &POL, &COL);
  CGBFUNC_DETPOL(COND, POL, COL, &DL, &CCL);
  while (CCL != MASSTOR_SIL) {
    SACLIST_ADV2(CCL, &DCOND, &PCO, &CCL);
    if (CGBDSTR_ColpIsZero(PCO)) {
      *N0 = SACLIST_COMP3(DCOND, PCO, C, *N0);
    } else {
      *N1 = SACLIST_COMP3(DCOND, PCO, C, *N1);
    }
  }
  return;
}

void CGBSYS_NFTOP
# ifdef __STDC__
(MASSTOR_LIST GA, MASSTOR_LIST FCO, MASSTOR_LIST P, MASSTOR_LIST *N0, MASSTOR_LIST *N1)
# else
(GA, FCO, P, N0, N1)
MASSTOR_LIST GA, FCO, P;
MASSTOR_LIST *N0, *N1;
# endif
{
  MASSTOR_LIST AL, C, CCL, COL, D, DCOND, DL, F, N, NL, PCI, PCO, POL, QC, RE;

  *N0 = MASSTOR_SIL;
  *N1 = MASSTOR_SIL;
  if (FCO == MASSTOR_SIL) {
    return;
  }
  F = CGBDSTR_ColpPol(FCO);
  C = MASADOM_ADFI(DIPC_DIPLBC(F), 1);
  if (CGBDSTR_ColpIsZero(FCO)) {
    *N0 = SACLIST_LIST3(GA, FCO, C);
    return;
  }
  if (P == MASSTOR_SIL) {
    *N1 = SACLIST_LIST3(GA, FCO, C);
    return;
  }
  N = SACLIST_LIST2(C, SACLIST_LIST2(GA, FCO));
  while (N != MASSTOR_SIL) {
    SACLIST_ADV2(N, &C, &NL, &N);
    while (NL != MASSTOR_SIL) {
      SACLIST_ADV2(NL, &GA, &PCO, &NL);
      for (;;) {
        if (CGBDSTR_ColpIsZero(PCO)) {
          *N0 = SACLIST_COMP3(GA, PCO, C, *N0);
          goto EXIT_2;
        }
        CGBSYS_FINDPITOP(PCO, P, &PCI, &RE);
        if (PCI != MASSTOR_SIL) {
          CGBSYS_GRED(GA, PCO, PCI, RE, &PCO, &QC);
          C = MASADOM_ADPROD(C, QC);
        } else {
          if (CGBDSTR_ColpHT(PCO) != MASSTOR_SIL) {
            *N1 = SACLIST_COMP3(GA, PCO, C, *N1);
          } else {
            CGBDSTR_ColpParts(PCO, &POL, &COL);
            CGBFUNC_DETPOL(GA, POL, COL, &DL, &CCL);
            N = SACLIST_COMP2(C, CCL, N);
          }
          goto EXIT_2;
        }
      } EXIT_2:;
    }
  }
  return;
}

void CGBSYS_FINDPI
# ifdef __STDC__
(MASSTOR_LIST PCO, MASSTOR_LIST P, MASSTOR_LIST *PCI, MASSTOR_LIST *RE)
# else
(PCO, P, PCI, RE)
MASSTOR_LIST PCO, P;
MASSTOR_LIST *PCI, *RE;
# endif
{
  MASSTOR_LIST ALIST, COL, HE, KEY, POL, PP, RA;

  CGBDSTR_ColpParts(PCO, &POL, &COL);
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &RA, RE, &POL);
    CGBSYS_KEYCOL(*RE, COL, &KEY, &ALIST);
    if (KEY != 0) {
      PP = P;
      do {
        MASSTOR_ADV(PP, PCI, &PP);
        HE = CGBDSTR_ColpHT(*PCI);
        if (HE != MASSTOR_SIL) {
          if (DIPC_EVMT(*RE, HE) == 1) {
            return;
          }
        } else {
          MASERR_ERROR(MASERR_severe, "Error in FINDPI, this cannot happen.", 36L);
        }
      } while (!(PP == MASSTOR_SIL));
    }
  }
  *PCI = MASSTOR_SIL;
}

void CGBSYS_FINDPITOP
# ifdef __STDC__
(MASSTOR_LIST PCO, MASSTOR_LIST P, MASSTOR_LIST *PCI, MASSTOR_LIST *RE)
# else
(PCO, P, PCI, RE)
MASSTOR_LIST PCO, P;
MASSTOR_LIST *PCI, *RE;
# endif
{
  MASSTOR_LIST ALIST, HE, PI, RA;

  *RE = CGBDSTR_ColpHT(PCO);
  if (*RE == MASSTOR_SIL) {
    *RE = MASSTOR_FIRST(MASSTOR_FIRST(CGBDSTR_ColWhite(CGBDSTR_ColpCol(PCO))));
  }
  do {
    MASSTOR_ADV(P, PCI, &P);
    HE = CGBDSTR_ColpHT(*PCI);
    if (HE != MASSTOR_SIL) {
      if (DIPC_EVMT(*RE, HE) == 1) {
        return;
      }
    } else {
      MASERR_ERROR(MASERR_severe, "Error in FINDPITOP, this cannot happen.", 39L);
    }
  } while (!(P == MASSTOR_SIL));
  *PCI = MASSTOR_SIL;
}

MASSTOR_LIST CGBSYS_SPOL
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST HA, MASSTOR_LIST HB)
# else
(COND, HA, HB)
MASSTOR_LIST COND, HA, HB;
# endif
{
  MASSTOR_LIST C_105_A, ACOL, AL, APP, B, BCOL, BL, BPP, CL, DL, DL1, EL, EL1, GL, H, HCOLS, RAL, RAP, SL;

  if (HA == MASSTOR_SIL || HB == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CGBDSTR_ColpParts(HA, &C_105_A, &ACOL);
  CGBDSTR_ColpParts(HB, &B, &BCOL);
  EL = CGBDSTR_ColpHT(HA);
  DL = CGBDSTR_ColpHT(HB);
  GL = DIPC_EVLCM(EL, DL);
  if (SACLIST_EQUAL(GL, DIPC_EVSUM(EL, DL)) == 1) {
    return MASSTOR_SIL;
  }
  ACOL = CGBFUNC_SETCOL(COND, ACOL);
  AL = CGBFUNC_FINDBC(EL, C_105_A);
  MASSTOR_ADV(AL, &RAL, &RAP);
  BCOL = CGBFUNC_SETCOL(COND, BCOL);
  BL = CGBFUNC_FINDBC(DL, B);
  MASADOM_ADGCDC(AL, BL, &CL, &AL, &BL);
  EL1 = DIPC_EVDIF(GL, EL);
  DL1 = DIPC_EVDIF(GL, DL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, DL1);
  if (DIPC_EVSIGN(EL1) != 0) {
    ACOL = CGBSYS_COLPRD(ACOL, EL1);
  }
  APP = DIPADOM_DIPROD(C_105_A, APP);
  if (DIPC_EVSIGN(DL1) != 0) {
    BCOL = CGBSYS_COLPRD(BCOL, DL1);
  }
  CGBSYS_GBDIFF(COND, APP, ACOL, DIPADOM_DIPROD(B, BPP), BCOL, &H, &HCOLS);
  if (H != 0) {
    if (MASADOM_ADSIGN(DIPC_DIPLBC(H)) == -1) {
      H = DIPADOM_DIPNEG(H);
    }
    if (!CGBDSTR_ColIsEmpty(HCOLS)) {
      return CGBDSTR_ColpCons(H, HCOLS);
    }
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST CGBSYS_GBSYS
# ifdef __STDC__
(MASSTOR_LIST CNDS, MASSTOR_LIST P)
# else
(CNDS, P)
MASSTOR_LIST CNDS, P;
# endif
{
  MASSTOR_LIST BB, COND, CONDS, GSYS, PAIRS, PCO, PELEM, PL, PP;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CGBFUNC_DET(CNDS, P, &CONDS, &PL);
  if (CGBMISC_PAR.outputlevel > 0) {
    MASBIOS_SWRITE("The polynomial system is determined by: ", 40L);
    MASBIOS_BLINES(0);
    CGBFUNC_DWRIT(CONDS);
    MASBIOS_BLINES(1);
  }
  BB = MASSTOR_SIL;
  GSYS = MASSTOR_SIL;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &PELEM, &PL);
    SACLIST_FIRST2(PELEM, &COND, &PP);
    PCO = CGBSYS_CHDEGL(PP);
    if (PCO != MASSTOR_SIL) {
      GSYS = CGBSYS_GBUPD(COND, MASSTOR_LIST1(PCO), GSYS);
    } else {
      PAIRS = CGBSYS_MKPAIR(PP);
      if (PAIRS != MASSTOR_SIL) {
        BB = SACLIST_COMP3(COND, CGBSYS_REXTP(PP), PAIRS, BB);
      } else {
        GSYS = CGBSYS_GBUPD(COND, PP, GSYS);
      }
    }
  }
  return CONSGB(BB, GSYS);
}

static void SigUsr1HandleCONSGB
# ifdef __STDC__
(INTEGER signo)
# else
(signo)
INTEGER signo;
# endif
{
  massig_Action C_104_dummy;
  MASSTOR_LIST Dummy;

  C_104_dummy = signal(massig_SIGUSR1, massig_SIG_IGN);
  Dummy = MASBIOS_SOUNIT("CON:x", 5L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SIGUSR1 received in CONSGB:", 27L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Groebner system at the moment:", 30L);
  MASBIOS_BLINES(1);
  CGBMAIN_WRGBS(*pGSYS);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Actual condition:", 17L);
  MASBIOS_BLINES(1);
  CGBDSTR_CondWrite(*pCOND);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(0);
  Dummy = MASBIOS_CUNIT("CON:x", 5L);
  C_104_dummy = signal(massig_SIGUSR1, SigUsr1HandleCONSGB);
}

static MASSTOR_LIST CONSGB
# ifdef __STDC__
(MASSTOR_LIST BB, MASSTOR_LIST GSYS)
# else
(BB, GSYS)
MASSTOR_LIST BB, GSYS;
# endif
{
  MASSTOR_LIST COND, GS1, HCO, HCOL, N0, N1, P, PAIR, PAIRS, PLIST, PRSL;
  massig_Action sighandleold;

  PLIST = BB;
  COND = CGBDSTR_CondEmpty();
  pGSYS = (LONGINT *)ADR(GSYS);
  pCOND = (LONGINT *)ADR(COND);
  sighandleold = signal(massig_SIGUSR1, SigUsr1HandleCONSGB);
  while (PLIST != MASSTOR_SIL) {
    SACLIST_ADV3(PLIST, &COND, &P, &PAIRS, &PLIST);
    while (PAIRS != MASSTOR_SIL) {
      MASSTOR_ADV(PAIRS, &PAIR, &PAIRS);
      PRSL = MASSTOR_SIL;
      GS1 = MASSTOR_SIL;
      HCO = CGBSYS_SPOL(COND, SACLIST_SECOND(PAIR), SACLIST_THIRD(PAIR));
      if (HCO == MASSTOR_SIL) {
        if (PAIRS == MASSTOR_SIL) {
          GSYS = CGBSYS_GBUPD(COND, P, GSYS);
        }
      } else {
        if (CGBDSTR_ColpIsCnst(HCO)) {
          PAIRS = MASSTOR_SIL;
          GSYS = CGBSYS_GBUPD(COND, MASSTOR_LIST1(HCO), GSYS);
        } else {
          (*CGBMISC_PAR.NormalForm)(COND, HCO, P, &N0, &N1);
          CGBSYS_VRNORM(COND, P, N0, N1, PAIRS, &P, &PAIRS, &PRSL, &GS1);
        }
      }
      if (PRSL != MASSTOR_SIL) {
        PLIST = SACLIST_CONC(PRSL, PLIST);
      }
      GSYS = SACLIST_CONC(GSYS, GS1);
    }
  }
  sighandleold = signal(massig_SIGUSR1, sighandleold);
  return GSYS;
}

MASSTOR_LIST CGBSYS_GBSYSF
# ifdef __STDC__
(MASSTOR_LIST CNDS, MASSTOR_LIST P)
# else
(CNDS, P)
MASSTOR_LIST CNDS, P;
# endif
{
  MASSTOR_LIST BB, COND, CONDS, GSYS, PAIRS, PCO, PELEM, PL, PP, p, FL, F, f, tmpFL, tmpF, fl, pl;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  FL = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    F = (*CGBMISC_PAR.Factors)(p);
    if (FL == MASSTOR_SIL) {
      while (F != MASSTOR_SIL) {
        MASSTOR_ADV(F, &f, &F);
        FL = MASSTOR_COMP(MASSTOR_LIST1(f), FL);
      }
    } else {
      tmpFL = FL;
      FL = MASSTOR_SIL;
      while (tmpFL != MASSTOR_SIL) {
        MASSTOR_ADV(tmpFL, &fl, &tmpFL);
        tmpF = F;
        while (tmpF != MASSTOR_SIL) {
          MASSTOR_ADV(tmpF, &f, &tmpF);
          FL = MASSTOR_COMP(MASSTOR_COMP(f, fl), FL);
        }
      }
    }
  }
  PL = MASSTOR_SIL;
  while (FL != MASSTOR_SIL) {
    MASSTOR_ADV(FL, &fl, &FL);
    CGBFUNC_DET(CNDS, fl, &CONDS, &pl);
    PL = SACLIST_CONC(pl, PL);
  }
  if (CGBMISC_PAR.outputlevel > 0) {
    MASBIOS_SWRITE("The polynomial system is determined by: ", 40L);
    MASBIOS_BLINES(0);
    CGBDSTR_CdWrite(CONDS);
    MASBIOS_BLINES(1);
  }
  BB = MASSTOR_SIL;
  GSYS = MASSTOR_SIL;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &PELEM, &PL);
    SACLIST_FIRST2(PELEM, &COND, &PP);
    PCO = CGBSYS_CHDEGL(PP);
    if (PCO != MASSTOR_SIL) {
      GSYS = CGBSYS_GBUPD(COND, MASSTOR_LIST1(PCO), GSYS);
    } else {
      PAIRS = CGBSYS_MKPAIR(PP);
      if (PAIRS != MASSTOR_SIL) {
        BB = SACLIST_COMP3(COND, CGBSYS_REXTP(PP), PAIRS, BB);
      } else {
        GSYS = CGBSYS_GBUPD(COND, PP, GSYS);
      }
    }
  }
  return CONSGBF(BB, GSYS);
}

static void SigUsr1HandleCONSGBF
# ifdef __STDC__
(INTEGER signo)
# else
(signo)
INTEGER signo;
# endif
{
  massig_Action C_103_dummy;
  MASSTOR_LIST Dummy;

  C_103_dummy = signal(massig_SIGUSR1, massig_SIG_IGN);
  Dummy = MASBIOS_SOUNIT("CON:x", 5L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SIGUSR1 received in CONSGB:", 27L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Groebner system at the moment:", 30L);
  MASBIOS_BLINES(1);
  CGBMAIN_WRGBS(*pGSYS);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Actual condition:", 17L);
  MASBIOS_BLINES(1);
  CGBDSTR_CondWrite(*pCOND);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("______________________________________________________________________________", 78L);
  MASBIOS_BLINES(0);
  Dummy = MASBIOS_CUNIT("CON:x", 5L);
  C_103_dummy = signal(massig_SIGUSR1, SigUsr1HandleCONSGBF);
}

static MASSTOR_LIST CONSGBF
# ifdef __STDC__
(MASSTOR_LIST BB, MASSTOR_LIST GSYS)
# else
(BB, GSYS)
MASSTOR_LIST BB, GSYS;
# endif
{
  MASSTOR_LIST COND, GS1, HCO, HCOL, N0, N1, P, PAIR, PAIRS, PLIST, PRSL, tmpN1, con, cond, pcol, c, p, col, FL, f, CD, CL, C_102_con, pol;
  massig_Action sighandleold;

  PLIST = BB;
  COND = CGBDSTR_CondEmpty();
  pGSYS = (LONGINT *)ADR(GSYS);
  pCOND = (LONGINT *)ADR(COND);
  sighandleold = signal(massig_SIGUSR1, SigUsr1HandleCONSGBF);
  while (PLIST != MASSTOR_SIL) {
    SACLIST_ADV3(PLIST, &COND, &P, &PAIRS, &PLIST);
    while (PAIRS != MASSTOR_SIL) {
      MASSTOR_ADV(PAIRS, &PAIR, &PAIRS);
      PRSL = MASSTOR_SIL;
      GS1 = MASSTOR_SIL;
      HCO = CGBSYS_SPOL(COND, SACLIST_SECOND(PAIR), SACLIST_THIRD(PAIR));
      if (HCO == MASSTOR_SIL) {
        if (PAIRS == MASSTOR_SIL) {
          GSYS = CGBSYS_GBUPD(COND, P, GSYS);
        }
      } else {
        if (CGBDSTR_ColpIsCnst(HCO)) {
          PAIRS = MASSTOR_SIL;
          GSYS = CGBSYS_GBUPD(COND, MASSTOR_LIST1(HCO), GSYS);
        } else {
          (*CGBMISC_PAR.NormalForm)(COND, HCO, P, &N0, &N1);
          tmpN1 = N1;
          N1 = MASSTOR_SIL;
          while (tmpN1 != MASSTOR_SIL) {
            SACLIST_ADV3(tmpN1, &cond, &pcol, &c, &tmpN1);
            SACLIST_FIRST2(pcol, &p, &col);
            FL = (*CGBMISC_PAR.Factors)(p);
            while (FL != MASSTOR_SIL) {
              MASSTOR_ADV(FL, &f, &FL);
              CGBFUNC_DETPOL(COND, f, CGBDSTR_ColConsCond(f, COND), &CD, &CL);
              while (CL != MASSTOR_SIL) {
                SACLIST_ADV2(CL, &con, &pol, &CL);
                if (CGBDSTR_ColpIsZero(pol)) {
                  N0 = SACLIST_COMP3(con, pol, 1, N0);
                } else {
                  N1 = SACLIST_COMP3(con, pol, 1, N1);
                }
              }
            }
          }
          CGBSYS_VRNORM(COND, P, N0, N1, PAIRS, &P, &PAIRS, &PRSL, &GS1);
        }
      }
      if (PRSL != MASSTOR_SIL) {
        PLIST = SACLIST_CONC(PRSL, PLIST);
      }
      GSYS = SACLIST_CONC(GSYS, GS1);
    }
  }
  sighandleold = signal(massig_SIGUSR1, sighandleold);
  return GSYS;
}

void CGBSYS_VRNORM
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PP, MASSTOR_LIST N0, MASSTOR_LIST N1, MASSTOR_LIST PPAIRS, MASSTOR_LIST *P, MASSTOR_LIST *PAIRS, MASSTOR_LIST *PAIRSL, MASSTOR_LIST *GSYS)
# else
(COND, PP, N0, N1, PPAIRS, P, PAIRS, PAIRSL, GSYS)
MASSTOR_LIST COND, PP, N0, N1, PPAIRS;
MASSTOR_LIST *P, *PAIRS, *PAIRSL, *GSYS;
# endif
{
  MASSTOR_LIST C, GSYS0, GSYS1, N1P, NCO, NPCOND, PRS0, PRS1;

  *PAIRSL = MASSTOR_SIL;
  *GSYS = MASSTOR_SIL;
  PRS0 = MASSTOR_SIL;
  PRS1 = MASSTOR_SIL;
  GSYS0 = MASSTOR_SIL;
  GSYS1 = MASSTOR_SIL;
  *P = PP;
  *PAIRS = MASSTOR_SIL;
  if (N1 == MASSTOR_SIL) {
    if (PPAIRS == MASSTOR_SIL) {
      *GSYS = CGBSYS_GBUPD(COND, *P, *GSYS);
    } else {
      *PAIRS = PPAIRS;
    }
    return;
  }
  if (N0 != MASSTOR_SIL) {
    if (PPAIRS == MASSTOR_SIL) {
      CGBSYS_GSYSN0(N0, *P, &GSYS0);
    } else {
      CGBSYS_MKN0(N0, *P, PPAIRS, &PRS0);
    }
  }
  SACLIST_ADV3(N1, &NPCOND, &NCO, &C, &N1P);
  if (N1P == MASSTOR_SIL && N0 == MASSTOR_SIL) {
    if (CGBDSTR_ColpIsCnst(NCO)) {
      *GSYS = CGBSYS_GBUPD(COND, MASSTOR_LIST1(NCO), *GSYS);
      return;
    } else {
      *PAIRS = CGBSYS_MKNEWP(*P, NCO, PPAIRS);
      *P = CGBSYS_MINPP(*P, NCO);
    }
  } else {
    CGBSYS_MKN1(N1, *P, PPAIRS, &PRS1, &GSYS1);
  }
  *PAIRSL = SACLIST_CONC(PRS0, PRS1);
  *GSYS = SACLIST_CONC(GSYS0, GSYS1);
  return;
}

MASSTOR_LIST CGBSYS_CHDEGL
# ifdef __STDC__
(MASSTOR_LIST PLIST)
# else
(PLIST)
MASSTOR_LIST PLIST;
# endif
{
  MASSTOR_LIST PCO;

  if (PLIST == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  do {
    MASSTOR_ADV(PLIST, &PCO, &PLIST);
    if (CGBDSTR_ColpIsCnst(PCO)) {
      return PCO;
    }
  } while (!(PLIST == MASSTOR_SIL));
  return MASSTOR_SIL;
}

void CGBSYS_MKN1
# ifdef __STDC__
(MASSTOR_LIST NN1, MASSTOR_LIST P, MASSTOR_LIST PAIRS, MASSTOR_LIST *PPLIST, MASSTOR_LIST *GSYS)
# else
(NN1, P, PAIRS, PPLIST, GSYS)
MASSTOR_LIST NN1, P, PAIRS;
MASSTOR_LIST *PPLIST, *GSYS;
# endif
{
  MASSTOR_LIST C, NPCOND, PCO, PP;

  *PPLIST = MASSTOR_SIL;
  *GSYS = MASSTOR_SIL;
  while (NN1 != MASSTOR_SIL) {
    SACLIST_ADV3(NN1, &NPCOND, &PCO, &C, &NN1);
    if (CGBDSTR_ColpIsCnst(PCO)) {
      *GSYS = CGBSYS_GBUPD(NPCOND, MASSTOR_LIST1(PCO), *GSYS);
    } else {
      PP = CGBSYS_MINPP(P, PCO);
      *PPLIST = SACLIST_COMP3(NPCOND, PP, CGBSYS_MKNEWP(P, PCO, PAIRS), *PPLIST);
      if (CGBMISC_PAR.outputlevel == 1) {
        MASBIOS_SWRITE("New case", 8L);
        MASBIOS_BLINES(0);
        CGBDSTR_CondWrite(NPCOND);
        MASBIOS_BLINES(1);
        CGBFUNC_DCLWR(PP, 0);
      }
    }
  }
  return;
}

void CGBSYS_MKN0
# ifdef __STDC__
(MASSTOR_LIST NN0, MASSTOR_LIST P, MASSTOR_LIST PAIRS, MASSTOR_LIST *PPLIST)
# else
(NN0, P, PAIRS, PPLIST)
MASSTOR_LIST NN0, P, PAIRS;
MASSTOR_LIST *PPLIST;
# endif
{
  MASSTOR_LIST C, NPCOND, PCO;

  *PPLIST = MASSTOR_SIL;
  while (NN0 != MASSTOR_SIL) {
    SACLIST_ADV3(NN0, &NPCOND, &PCO, &C, &NN0);
    *PPLIST = SACLIST_COMP3(NPCOND, P, PAIRS, *PPLIST);
  }
  return;
}

void CGBSYS_GSYSN0
# ifdef __STDC__
(MASSTOR_LIST NN0, MASSTOR_LIST P, MASSTOR_LIST *GSYS)
# else
(NN0, P, GSYS)
MASSTOR_LIST NN0, P;
MASSTOR_LIST *GSYS;
# endif
{
  MASSTOR_LIST C, NPCOND, PCO;

  *GSYS = MASSTOR_SIL;
  while (NN0 != MASSTOR_SIL) {
    SACLIST_ADV3(NN0, &NPCOND, &PCO, &C, &NN0);
    *GSYS = CGBSYS_GBUPD(NPCOND, P, *GSYS);
  }
  return;
}

MASSTOR_LIST CGBSYS_MINPP
# ifdef __STDC__
(MASSTOR_LIST PP, MASSTOR_LIST PCO)
# else
(PP, PCO)
MASSTOR_LIST PP, PCO;
# endif
{
  MASSTOR_LIST EI, P, PCI;

  P = MASSTOR_SIL;
  EI = CGBDSTR_ColpHT(PCO);
  if (EI == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "Error in MINPP, this cannot happen.", 35L);
  }
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PCI, &PP);
    if (DIPC_EVMT(CGBDSTR_ColpHT(PCI), EI) == 0) {
      P = MASSTOR_COMP(PCI, P);
    }
  }
  return MASSTOR_INV(MASSTOR_COMP(PCO, P));
}

MASSTOR_LIST CGBSYS_UPDPP
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST P)
# else
(COND, P)
MASSTOR_LIST COND, P;
# endif
{
  MASSTOR_LIST COL, PCO, POL, PP;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  PP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &PCO, &P);
    SACLIST_FIRST2(PCO, &POL, &COL);
    PP = MASSTOR_COMP(SACLIST_LIST2(POL, CGBFUNC_SETCOL(COND, COL)), PP);
  } while (!(P == MASSTOR_SIL));
  return MASSTOR_INV(PP);
}

MASSTOR_LIST CGBSYS_GBUPD
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST P, MASSTOR_LIST GBSYS)
# else
(COND, P, GBSYS)
MASSTOR_LIST COND, P, GBSYS;
# endif
{
  MASSTOR_LIST ELEM, PP;

  PP = CGBSYS_REXTP(CGBSYS_UPDPP(COND, P));
  GBSYS = MASSTOR_COMP(SACLIST_LIST2(COND, PP), GBSYS);
  if (CGBMISC_PAR.outputlevel == 1) {
    MASBIOS_SWRITE("New Groebner-Basis: ", 20L);
    MASBIOS_BLINES(0);
    CGBDSTR_CondWrite(COND);
    MASBIOS_BLINES(1);
    CGBFUNC_DCLWR(PP, 0);
  }
  return GBSYS;
}

MASSTOR_LIST CGBSYS_MKPAIR
# ifdef __STDC__
(MASSTOR_LIST PP)
# else
(PP)
MASSTOR_LIST PP;
# endif
{
  MASSTOR_LIST ELI, ELJ, PI, PJ, QP, PAIRS;

  if (PP == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (MASSTOR_RED(PP) == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  PAIRS = MASSTOR_SIL;
  do {
    MASSTOR_ADV(PP, &PI, &QP);
    ELI = CGBDSTR_ColpHT(PI);
    if (ELI != MASSTOR_SIL) {
      while (QP != MASSTOR_SIL) {
        MASSTOR_ADV(QP, &PJ, &QP);
        ELJ = CGBDSTR_ColpHT(PJ);
        if (ELJ != MASSTOR_SIL) {
          PAIRS = MASSTOR_COMP(SACLIST_LIST3(DIPC_EVLCM(ELI, ELJ), PI, PJ), PAIRS);
        }
      }
    }
    PP = MASSTOR_RED(PP);
  } while (!(PP == MASSTOR_SIL));
  if (PAIRS != MASSTOR_SIL) {
    return DIPRNGB_EVPLSO(PAIRS);
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST CGBSYS_PRSCOP
# ifdef __STDC__
(MASSTOR_LIST PAIRS)
# else
(PAIRS)
MASSTOR_LIST PAIRS;
# endif
{
  MASSTOR_LIST PAIR, PPAIRS;

  if (PAIRS == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  PPAIRS = MASSTOR_SIL;
  while (PAIRS != MASSTOR_SIL) {
    MASSTOR_ADV(PAIRS, &PAIR, &PAIRS);
    PPAIRS = MASSTOR_COMP(PAIR, PPAIRS);
  }
  return MASSTOR_INV(PPAIRS);
}

MASSTOR_LIST CGBSYS_MKNEWP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST POL, MASSTOR_LIST PRS)
# else
(P, POL, PRS)
MASSTOR_LIST P, POL, PRS;
# endif
{
  MASSTOR_LIST ELI, ELJ, PLI, PPAIRS;

  PPAIRS = MASSTOR_SIL;
  ELI = CGBDSTR_ColpHT(POL);
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &PLI, &P);
    ELJ = CGBDSTR_ColpHT(PLI);
    if (ELJ != MASSTOR_SIL) {
      PPAIRS = MASSTOR_COMP(SACLIST_LIST3(DIPC_EVLCM(ELI, ELJ), POL, PLI), PPAIRS);
    }
  }
  PPAIRS = DIPRNGB_EVPLSO(PPAIRS);
  if (PRS != MASSTOR_SIL) {
    return DIPRNGB_EVPLM(CGBSYS_PRSCOP(PRS), PPAIRS);
  }
  return PPAIRS;
}

void CGBSYS_MKCGB
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST *X, MASSTOR_LIST *I)
# else
(PL, X, I)
MASSTOR_LIST PL;
MASSTOR_LIST *X, *I;
# endif
{
  MASSTOR_LIST PCO, PELEM, PLIST;

  *X = MASSTOR_SIL;
  *I = 0;
  if (PL == MASSTOR_SIL) {
    return;
  }
  MASSTOR_ADV(PL, &PELEM, &PL);
  PLIST = SACLIST_SECOND(PELEM);
  while (PLIST != MASSTOR_SIL) {
    MASSTOR_ADV(PLIST, &PCO, &PLIST);
    *X = MASSTOR_COMP(MASSTOR_FIRST(PCO), *X);
  }
  *I = 1;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &PELEM, &PL);
    *X = CGBSYS_ADDCGB(SACLIST_SECOND(PELEM), *X);
    *I = *I + 1;
  }
  if (*X != MASSTOR_SIL) {
    *X = MASSTOR_INV(DIPC_DIPLPM(*X));
  }
  return;
}

MASSTOR_LIST CGBSYS_ADDCGB
# ifdef __STDC__
(MASSTOR_LIST PLIST, MASSTOR_LIST P)
# else
(PLIST, P)
MASSTOR_LIST PLIST, P;
# endif
{
  MASSTOR_LIST APCO, APOL;

  if (PLIST == MASSTOR_SIL) {
    return P;
  }
  do {
    MASSTOR_ADV(PLIST, &APCO, &PLIST);
    APOL = MASSTOR_FIRST(APCO);
    if (SACLIST_MEMBER(APOL, P) == 0) {
      P = MASSTOR_COMP(APOL, P);
    }
  } while (!(PLIST == MASSTOR_SIL));
  return P;
}

MASSTOR_LIST CGBSYS_GSRED
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  MASSTOR_LIST PELEM, RS;

  if (GS == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  RS = MASSTOR_SIL;
  do {
    MASSTOR_ADV(GS, &PELEM, &GS);
    RS = MASSTOR_COMP(CGBSYS_REDUCT(PELEM), RS);
  } while (!(GS == MASSTOR_SIL));
  return RS;
}

MASSTOR_LIST CGBSYS_REDUCT
# ifdef __STDC__
(MASSTOR_LIST PELEM)
# else
(PELEM)
MASSTOR_LIST PELEM;
# endif
{
  MASSTOR_LIST COND, J1Y, NCO, PCO, PLIST, QP, RLIST;

  SACLIST_FIRST2(PELEM, &COND, &PLIST);
  if (PLIST == MASSTOR_SIL) {
    return SACLIST_LIST2(COND, MASSTOR_SIL);
  }
  PCO = CGBSYS_CHDEGL(PLIST);
  if (PCO != MASSTOR_SIL) {
    return SACLIST_LIST2(COND, MASSTOR_LIST1(PCO));
  } else {
    PLIST = CGBSYS_REXTP(PLIST);
  }
  if (PLIST == MASSTOR_SIL) {
    return SACLIST_LIST2(COND, PLIST);
  }
  if (MASSTOR_RED(PLIST) == MASSTOR_SIL) {
    return SACLIST_LIST2(COND, PLIST);
  }
  QP = PLIST;
  RLIST = MASSTOR_SIL;
  do {
    MASSTOR_ADV(PLIST, &PCO, &PLIST);
    CGBSYS_RDNORM(COND, PCO, QP, &NCO);
    if (NCO != MASSTOR_SIL) {
      RLIST = MASSTOR_COMP(NCO, RLIST);
    }
  } while (!(PLIST == MASSTOR_SIL));
  return SACLIST_LIST2(COND, MASSTOR_INV(RLIST));
}

MASSTOR_LIST CGBSYS_REXTP
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EI, EJ, PB, PCI, PCO, PS, QP, TL;

  if (P == MASSTOR_SIL) {
    return P;
  }
  QP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &PCO, &P);
    EI = CGBDSTR_ColpHT(PCO);
    if (EI != MASSTOR_SIL) {
      PB = P;
      TL = 0;
      while (PB != MASSTOR_SIL && TL == 0) {
        MASSTOR_ADV(PB, &PCI, &PB);
        EJ = CGBDSTR_ColpHT(PCI);
        if (EJ != MASSTOR_SIL) {
          TL = DIPC_EVMT(EI, EJ);
        }
      }
      PB = QP;
      while (PB != MASSTOR_SIL && TL == 0) {
        MASSTOR_ADV(PB, &PCI, &PB);
        EJ = CGBDSTR_ColpHT(PCI);
        if (EJ != MASSTOR_SIL) {
          TL = DIPC_EVMT(EI, EJ);
        }
      }
      if (TL == 0) {
        QP = MASSTOR_COMP(PCO, QP);
      }
    }
  } while (!(P == MASSTOR_SIL));
  return MASSTOR_INV(QP);
}

void CGBSYS_RDNORM
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST FCO, MASSTOR_LIST P, MASSTOR_LIST *NCO)
# else
(COND, FCO, P, NCO)
MASSTOR_LIST COND, FCO, P;
MASSTOR_LIST *NCO;
# endif
{
  MASSTOR_LIST PCI, QC, RE;

  *NCO = FCO;
  for (;;) {
    CGBSYS_REFIND(*NCO, P, &PCI, &RE);
    if (PCI == MASSTOR_SIL) {
      goto EXIT_3;
    }
    CGBSYS_GRED(COND, *NCO, PCI, RE, NCO, &QC);
  } EXIT_3:;
  return;
}

void CGBSYS_REFIND
# ifdef __STDC__
(MASSTOR_LIST PCO, MASSTOR_LIST P, MASSTOR_LIST *PLI, MASSTOR_LIST *RE)
# else
(PCO, P, PLI, RE)
MASSTOR_LIST PCO, P;
MASSTOR_LIST *PLI, *RE;
# endif
{
  MASSTOR_LIST ALIST, HE, HT, KEY, POL, PP, RA, SL;

  *RE = MASSTOR_SIL;
  *PLI = MASSTOR_SIL;
  if (PCO == MASSTOR_SIL || P == MASSTOR_SIL) {
    return;
  }
  POL = CGBDSTR_ColpPol(PCO);
  HT = CGBDSTR_ColpHT(PCO);
  SL = 0;
  while (POL != MASSTOR_SIL && SL == 0) {
    DIPC_DIPMAD(POL, &RA, RE, &POL);
    CGBSYS_KEYCOL(*RE, CGBDSTR_ColpCol(PCO), &KEY, &ALIST);
    if (KEY != 0 && SACLIST_EQUAL(HT, *RE) == 0) {
      PP = P;
      do {
        MASSTOR_ADV(PP, PLI, &PP);
        HE = CGBDSTR_ColpHT(*PLI);
        if (HE != MASSTOR_SIL) {
          if (DIPC_EVMT(*RE, HE) == 1) {
            return;
          }
        }
      } while (!(PP == MASSTOR_SIL));
    }
  }
  *PLI = MASSTOR_SIL;
}

MASSTOR_LIST CGBSYS_RMGRT
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PP)
# else
(COND, PP)
MASSTOR_LIST COND, PP;
# endif
{
  MASSTOR_LIST COL, COND0, COND1, P, PCO, PPCO, PPOL;

  if (CGBDSTR_CondIsEmpty(COND)) {
    return PP;
  }
  CGBDSTR_CondParts(COND, &COND0, &COND1);
  if (COND0 == MASSTOR_SIL) {
    return PP;
  }
  P = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PCO, &PP);
    COL = SACLIST_SECOND(PCO);
    PPOL = CGBFUNC_MKPOL(PCO);
    MASBIOS_BLINES(0);
    if (!CGBDSTR_ColIsEmpty(COL)) {
      P = MASSTOR_COMP(SACLIST_LIST2(PPOL, COL), P);
    }
  }
  return MASSTOR_INV(P);
}

MASSTOR_LIST CGBSYS_GLOBRE
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST P)
# else
(COND, P)
MASSTOR_LIST COND, P;
# endif
{
  MASSTOR_LIST CGB, COL, NCO, PCO, PLIST, POL, QP;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  PLIST = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &POL, &P);
    PLIST = MASSTOR_COMP(CGBDSTR_ColpConsCond(POL, COND), PLIST);
  } while (!(P == MASSTOR_SIL));
  PLIST = MASSTOR_INV(PLIST);
  PCO = CGBSYS_CHDEGL(PLIST);
  if (PCO != MASSTOR_SIL) {
    return MASSTOR_LIST1(PCO);
  }
  PLIST = CGBSYS_GLEXTP(CGBSYS_RMGRT(COND, PLIST));
  if (PLIST == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (MASSTOR_RED(PLIST) == MASSTOR_SIL) {
    return PLIST;
  }
  QP = PLIST;
  CGB = MASSTOR_SIL;
  while (PLIST != MASSTOR_SIL) {
    MASSTOR_ADV(PLIST, &PCO, &PLIST);
    CGBSYS_RDNORM(COND, PCO, QP, &NCO);
    CGBSYS_RDNORM(COND, NCO, CGB, &NCO);
    if (NCO != MASSTOR_SIL && CGBFUNC_WMEMB(CGBDSTR_ColpPol(NCO), CGB) == 0) {
      CGB = MASSTOR_COMP(NCO, CGB);
    }
  }
  return CGBFUNC_CGBLPM(CGB);
}

MASSTOR_LIST CGBSYS_GLEXTP
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EI, EJ, PB, PCI, PCO, PP, TL;

  if (P == MASSTOR_SIL) {
    return P;
  }
  if (MASSTOR_RED(P) == MASSTOR_SIL) {
    return P;
  }
  PP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &PCO, &P);
    EI = CGBDSTR_ColpHT(PCO);
    TL = 0;
    if (EI != MASSTOR_SIL) {
      PB = P;
      while (PB != MASSTOR_SIL && TL == 0) {
        MASSTOR_ADV(PB, &PCI, &PB);
        EJ = CGBDSTR_ColpHT(PCI);
        if (EJ != MASSTOR_SIL) {
          TL = DIPC_EVMT(EI, EJ);
        }
      }
      PB = PP;
      while (PB != MASSTOR_SIL && TL == 0) {
        MASSTOR_ADV(PB, &PCI, &PB);
        EJ = CGBDSTR_ColpHT(PCI);
        if (EJ != MASSTOR_SIL) {
          TL = DIPC_EVMT(EI, EJ);
        }
      }
    }
    if (TL == 0) {
      PP = MASSTOR_COMP(PCO, PP);
    }
  } while (!(P == MASSTOR_SIL));
  return MASSTOR_INV(PP);
}

void BEGIN_CGBSYS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_CGBDSTR();
    BEGIN_CGBFUNC();
    BEGIN_CGBMAIN();
    BEGIN_CGBMISC();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPRNGB();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_massig();
    BEGIN_MASSIGNAL();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
