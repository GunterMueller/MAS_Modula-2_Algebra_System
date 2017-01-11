#include "SYSTEM_.h"

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
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

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

CHAR CGBFUNC_rcsid [] = "$Id: CGBFUNC.md,v 1.7 1996/06/08 16:47:09 pesch Exp $";
CHAR CGBFUNC_copyright [] = "Copyright (c) 1989 - 1996 Universitaet Passau";

static CHAR rcsidi [] = "$Id: CGBFUNC.mip,v 1.9 1996/06/08 16:47:10 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1996 Universitaet Passau";


void CGBFUNC_WRCOL
# ifdef __STDC__
(MASSTOR_LIST COL, MASSTOR_LIST POL)
# else
(COL, POL)
MASSTOR_LIST COL, POL;
# endif
{
  MASSTOR_LIST COLR, COLW, PACK, QA, QALIST, QQ, T, TERM, TT, V, var;

  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Colours: ", 9L);
  if (CGBDSTR_ColIsEmpty(COL)) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  SACLIST_FIRST2(COL, &COLR, &COLW);
  V = DIPC_VALIS;
  TT = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &var, &V);
    TT = MASSTOR_COMP(0, TT);
  }
  if (COLR != MASSTOR_SIL) {
    MASBIOS_SWRITE("Red terms: ", 11L);
  }
  MASBIOS_BLINES(0);
  while (COLR != MASSTOR_SIL) {
    MASSTOR_ADV(COLR, &T, &COLR);
    TERM = CGBFUNC_FINDRM(T, POL);
    DIPADOM_DIWRIT(TERM, DIPC_VALIS);
    MASBIOS_BLINES(1);
  }
  MASBIOS_BLINES(0);
  if (COLW == MASSTOR_SIL) {
    return;
  }
  MASBIOS_SWRITE("White terms: ", 13L);
  MASBIOS_BLINES(0);
  while (COLW != MASSTOR_SIL) {
    MASSTOR_ADV(COLW, &PACK, &COLW);
    SACLIST_FIRST2(PACK, &T, &QALIST);
    TERM = CGBFUNC_FINDRM(T, POL);
    DIPADOM_DIWRIT(TERM, DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("List of factors: ", 17L);
    while (QALIST != MASSTOR_SIL) {
      MASSTOR_ADV(QALIST, &QA, &QALIST);
      QQ = DIPC_DIPFMO(QA, TT);
      DIPADOM_DIWRIT(QQ, DIPC_VALIS);
      MASBIOS_BLINES(1);
    }
  }
  MASBIOS_BLINES(0);
}

void CGBFUNC_WRTERM
# ifdef __STDC__
(MASSTOR_LIST TERM, MASSTOR_LIST V)
# else
(TERM, V)
MASSTOR_LIST TERM, V;
# endif
{
  MASSTOR_LIST E, EL, ES, SL, VL, VS;

  E = TERM;
  SL = DIPC_EVSIGN(E);
  if (SL == 0) {
    MASBIOS_SWRITE("DEG=0", 5L);
    MASBIOS_BLINES(0);
  } else {
    ES = SACLIST_CINV(E);
    VS = V;
    do {
      MASSTOR_ADV(ES, &EL, &ES);
      MASSTOR_ADV(VS, &VL, &VS);
      if (EL > 0) {
        MASBIOS_SWRITE(" ", 1L);
        SACLIST_CLOUT(VL);
        if (EL > 1) {
          MASBIOS_SWRITE("**", 2L);
          SACLIST_AWRITE(EL);
        }
      }
    } while (!(ES == MASSTOR_SIL));
  }
  MASBIOS_BLINES(0);
  return;
}

void CGBFUNC_DWRIT
# ifdef __STDC__
(MASSTOR_LIST DE)
# else
(DE)
MASSTOR_LIST DE;
# endif
{
  MASBIOS_SWRITE("Case Distinction: ", 18L);
  CGBDSTR_CdWrite(DE);
}

MASSTOR_LIST CGBFUNC_CGBCOL
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PL)
# else
(COND, PL)
MASSTOR_LIST COND, PL;
# endif
{
  PL = CGBFUNC_GREPOL(PL);
  if (!CGBDSTR_CondIsEmpty(COND)) {
    if (CGBDSTR_CondZero(COND) != MASSTOR_SIL) {
      MASBIOS_SWRITE("Basis without green terms: ", 27L);
      if (PL == MASSTOR_SIL) {
        MASBIOS_SWRITE("Empty.", 6L);
      } else {
        DIPADOM_DILWR(PL, DIPC_VALIS);
      }
    }
    MASBIOS_BLINES(0);
  }
  return PL;
}

void CGBFUNC_DCLWR
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST B)
# else
(PL, B)
MASSTOR_LIST PL, B;
# endif
{
  MASSTOR_LIST COLS, PLIST, POL, X;

  if (PL == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(1);
    return;
  }
  PLIST = PL;
  while (PLIST != MASSTOR_SIL) {
    MASSTOR_ADV(PLIST, &X, &PLIST);
    if (X == MASSTOR_SIL) {
      MASBIOS_SWRITE("PCO empty.", 10L);
    } else {
      SACLIST_FIRST2(X, &POL, &COLS);
      DIPADOM_DILWR(MASSTOR_LIST1(POL), DIPC_VALIS);
      if (B == 1) {
        CGBFUNC_WRCOL(COLS, POL);
      }
    }
  }
  MASBIOS_BLINES(0);
  return;
}

MASSTOR_LIST CGBFUNC_FINDCP
# ifdef __STDC__
(MASSTOR_LIST TTERM, MASSTOR_LIST WHITE)
# else
(TTERM, WHITE)
MASSTOR_LIST TTERM, WHITE;
# endif
{
  MASSTOR_LIST CWHITE, SL, WPACK;

  if (TTERM == 0 || TTERM == MASSTOR_SIL || WHITE == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CWHITE = WHITE;
  do {
    MASSTOR_ADV(CWHITE, &WPACK, &CWHITE);
    if (SACLIST_EQUAL(TTERM, MASSTOR_FIRST(WPACK)) == 1) {
      return WPACK;
    }
  } while (!(CWHITE == MASSTOR_SIL));
  return MASSTOR_SIL;
}

MASSTOR_LIST CGBFUNC_FINDBC
# ifdef __STDC__
(MASSTOR_LIST RE, MASSTOR_LIST POL)
# else
(RE, POL)
MASSTOR_LIST RE, POL;
# endif
{
  MASSTOR_LIST PA, PE;

  do {
    DIPC_DIPMAD(POL, &PA, &PE, &POL);
  } while (!(SACLIST_EQUAL(RE, PE) == 1));
  return PA;
}

MASSTOR_LIST CGBFUNC_FINDRM
# ifdef __STDC__
(MASSTOR_LIST RE, MASSTOR_LIST POL)
# else
(RE, POL)
MASSTOR_LIST RE, POL;
# endif
{
  MASSTOR_LIST PA, PE;

  do {
    DIPC_DIPMAD(POL, &PA, &PE, &POL);
  } while (!(SACLIST_EQUAL(RE, PE) == 1));
  return DIPC_DIPFMO(PA, PE);
}

MASSTOR_LIST CGBFUNC_CGBFRM
# ifdef __STDC__
(MASSTOR_LIST CGBL)
# else
(CGBL)
MASSTOR_LIST CGBL;
# endif
{
  MASSTOR_LIST CGB, PCO;

  if (CGBL == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CGB = MASSTOR_SIL;
  do {
    MASSTOR_ADV(CGBL, &PCO, &CGBL);
    CGB = MASSTOR_COMP(MASSTOR_FIRST(PCO), CGB);
  } while (!(CGBL == MASSTOR_SIL));
  return CGB;
}

MASSTOR_LIST CGBFUNC_MKPOL
# ifdef __STDC__
(MASSTOR_LIST PCO)
# else
(PCO)
MASSTOR_LIST PCO;
# endif
{
  MASSTOR_LIST CRED, CWHITE, PCOL, POL, PPOL, RA, RE, SL;

  SACLIST_FIRST2(PCO, &POL, &PCOL);
  if (PCOL == MASSTOR_SIL) {
    return 0;
  }
  PPOL = MASSTOR_SIL;
  SACLIST_FIRST2(PCOL, &CRED, &CWHITE);
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &RA, &RE, &POL);
    if (SACLIST_MEMBER(RE, CRED) == 1) {
      PPOL = DIPC_DIPMCP(RE, RA, PPOL);
    } else {
      if (CGBFUNC_WMEMB(RE, CWHITE) == 1) {
        PPOL = DIPC_DIPMCP(RE, RA, PPOL);
      }
    }
  }
  if (PPOL == MASSTOR_SIL) {
    return 0;
  } else {
    return MASSTOR_INV(PPOL);
  }
}

MASSTOR_LIST CGBFUNC_GREPOL
# ifdef __STDC__
(MASSTOR_LIST PL)
# else
(PL)
MASSTOR_LIST PL;
# endif
{
  MASSTOR_LIST PCO, PPOL, X;

  if (PL == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  X = MASSTOR_SIL;
  MASBIOS_BLINES(0);
  do {
    MASSTOR_ADV(PL, &PCO, &PL);
    PPOL = CGBFUNC_MKPOL(PCO);
    if (PPOL != 0) {
      X = MASSTOR_COMP(PPOL, X);
    }
  } while (!(PL == MASSTOR_SIL));
  if (X != MASSTOR_SIL) {
    return MASSTOR_INV(X);
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST CGBFUNC_WMEMB
# ifdef __STDC__
(MASSTOR_LIST TTERM, MASSTOR_LIST WHITE)
# else
(TTERM, WHITE)
MASSTOR_LIST TTERM, WHITE;
# endif
{
  MASSTOR_LIST SL, WPACK, WTERM;

  if (TTERM == 0 || TTERM == MASSTOR_SIL || WHITE == MASSTOR_SIL) {
    return 0;
  }
  do {
    MASSTOR_ADV(WHITE, &WPACK, &WHITE);
    WTERM = MASSTOR_FIRST(WPACK);
    SL = SACLIST_EQUAL(TTERM, WTERM);
  } while (!(SL == 1 || WHITE == MASSTOR_SIL));
  return SL;
}

MASSTOR_LIST CGBFUNC_EQPLCL
# ifdef __STDC__
(MASSTOR_LIST ALIST, MASSTOR_LIST BLIST)
# else
(ALIST, BLIST)
MASSTOR_LIST ALIST, BLIST;
# endif
{
  MASSTOR_LIST APCO, BPCO, SL;

  if (ALIST == MASSTOR_SIL || BLIST == MASSTOR_SIL) {
    return 0;
  }
  do {
    MASSTOR_ADV(ALIST, &APCO, &ALIST);
    MASSTOR_ADV(BLIST, &BPCO, &BLIST);
    SL = SACLIST_EQUAL(MASSTOR_FIRST(APCO), MASSTOR_FIRST(BPCO));
  } while (!(ALIST == MASSTOR_SIL || BLIST == MASSTOR_SIL || SL == 0));
  if (ALIST == MASSTOR_SIL && BLIST != MASSTOR_SIL) {
    return 0;
  }
  if (ALIST != MASSTOR_SIL && BLIST == MASSTOR_SIL) {
    return 0;
  }
  return SL;
}

MASSTOR_LIST CGBFUNC_CGBLM
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST EL1, EL2, L, LP, LP1, LP2, PC1, PC2, PL1, PL2;
  BOOLEAN gt;

  if (L1 == MASSTOR_SIL) {
    return L2;
  }
  if (L2 == MASSTOR_SIL) {
    return L1;
  }
  LP1 = L1;
  PC1 = MASSTOR_FIRST(L1);
  PL1 = CGBDSTR_ColpPol(PC1);
  EL1 = CGBDSTR_ColpHT(PC1);
  if (EL1 == MASSTOR_SIL) {
    EL1 = DIPC_DIPEVL(PL1);
  }
  LP2 = L2;
  PC2 = MASSTOR_FIRST(L2);
  PL2 = CGBDSTR_ColpPol(PC2);
  EL2 = CGBDSTR_ColpHT(PC2);
  if (EL2 == MASSTOR_SIL) {
    EL2 = DIPC_DIPEVL(PL2);
  }
  if (DIPC_EVCOMP(EL1, EL2) <= 0) {
    L = L1;
    LP = L1;
    LP1 = MASSTOR_RED(L1);
    gt = TRUE;
  } else {
    L = L2;
    LP = L2;
    LP2 = MASSTOR_RED(L2);
    gt = FALSE;
  }
  for (;;) {
    if (gt) {
      if (LP1 == MASSTOR_SIL) {
        MASSTOR_SRED(LP, LP2);
        goto EXIT_1;
      }
      PC1 = MASSTOR_FIRST(LP1);
      PL1 = CGBDSTR_ColpPol(PC1);
      EL1 = CGBDSTR_ColpHT(PC1);
      if (EL1 == MASSTOR_SIL) {
        EL1 = DIPC_DIPEVL(PL1);
      }
      if (DIPC_EVCOMP(EL1, EL2) <= 0) {
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        gt = TRUE;
      } else {
        MASSTOR_SRED(LP, LP2);
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        gt = FALSE;
      }
    } else {
      if (LP2 == MASSTOR_SIL) {
        MASSTOR_SRED(LP, LP1);
        goto EXIT_1;
      }
      PC2 = MASSTOR_FIRST(LP2);
      PL2 = CGBDSTR_ColpPol(PC2);
      EL2 = CGBDSTR_ColpHT(PC2);
      if (EL2 == MASSTOR_SIL) {
        EL2 = DIPC_DIPEVL(PL2);
      }
      if (DIPC_EVCOMP(EL1, EL2) <= 0) {
        MASSTOR_SRED(LP, LP1);
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        gt = TRUE;
      } else {
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        gt = FALSE;
      }
    }
  } EXIT_1:;
  return L;
}

MASSTOR_LIST CGBFUNC_CGBLPM
# ifdef __STDC__
(MASSTOR_LIST C_102_A)
# else
(C_102_A)
MASSTOR_LIST C_102_A;
# endif
{
  MASSTOR_LIST AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2, PCO, PCI, PLI;

  if (C_102_A == MASSTOR_SIL) {
    return C_102_A;
  }
  if (MASSTOR_RED(C_102_A) == MASSTOR_SIL) {
    return C_102_A;
  }
  C = MASSTOR_LIST1(0);
  CS = C;
  AP = C_102_A;
  do {
    MASSTOR_ADV(AP, &PCO, &APP);
    if (APP == MASSTOR_SIL) {
      BP = AP;
    } else {
      MASSTOR_ADV(APP, &PCI, &APPP);
      EL1 = CGBDSTR_ColpHT(PCO);
      if (EL1 == MASSTOR_SIL) {
        EL1 = DIPC_DIPEVL(CGBDSTR_ColpPol(PCO));
      }
      EL2 = CGBDSTR_ColpHT(PCI);
      if (EL2 == MASSTOR_SIL) {
        EL2 = DIPC_DIPEVL(CGBDSTR_ColpPol(PCI));
      }
      if (DIPC_EVCOMP(EL1, EL2) <= 0) {
        BP = AP;
        MASSTOR_SRED(APP, MASSTOR_SIL);
      } else {
        BP = APP;
        MASSTOR_SRED(APP, AP);
        MASSTOR_SRED(AP, MASSTOR_SIL);
      }
    }
    C = MASSTOR_COMP(BP, C);
    AP = APPP;
  } while (!(APP == MASSTOR_SIL || AP == MASSTOR_SIL));
  MASSTOR_ADV(C, &BP, &C);
  MASSTOR_SFIRST(CS, BP);
  MASSTOR_SRED(CS, C);
  MASSTOR_ADV(C, &B, &CP);
  while (C != CP) {
    MASSTOR_ADV(CP, &BP, &CPP);
    BPP = CGBFUNC_CGBLM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return MASSTOR_INV(B);
}

MASSTOR_LIST CGBFUNC_ADDCON
# ifdef __STDC__
(MASSTOR_LIST COEFL, MASSTOR_LIST COND)
# else
(COEFL, COND)
MASSTOR_LIST COEFL, COND;
# endif
{
  MASSTOR_LIST COEF, CONDZ, CONDN, CDIST1, CDIST2;

  if (COEFL == MASSTOR_SIL) {
    return MASSTOR_LIST1(COND);
  }
  MASSTOR_ADV(COEFL, &COEF, &COEFL);
  if ((*CGBMISC_PAR.CondEval)(COND, COEF) != CGBMISC_unknown) {
    return MASSTOR_LIST1(COND);
  }
  (*CGBMISC_PAR.CondRamif)(COEF, COND, &CONDZ, &CONDN);
  CDIST1 = MASSTOR_SIL;
  CDIST2 = MASSTOR_SIL;
  if (!CGBDSTR_CondIsEmpty(CONDZ)) {
    CDIST1 = CGBFUNC_ADDCON(COEFL, CONDZ);
  }
  if (!CGBDSTR_CondIsEmpty(CONDN)) {
    CDIST2 = CGBFUNC_ADDCON(COEFL, CONDN);
  }
  return SACLIST_CONC(CDIST2, CDIST1);
}

MASSTOR_LIST CGBFUNC_INICOL
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PI)
# else
(COND, PI)
MASSTOR_LIST COND, PI;
# endif
{
  MASSTOR_LIST C_101_A, ALIST, CRED, CWHITE, PA, PE, NF, WFACTS;
  CGBMISC_COLOUR C;

  if (PI == MASSTOR_SIL) {
    return CGBDSTR_ColEmpty();
  }
  CRED = MASSTOR_SIL;
  CWHITE = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(PI, &PA, &PE, &PI);
    if ((*CGBMISC_PAR.IsCnst)(PA)) {
      CRED = MASSTOR_COMP(PE, CRED);
    } else {
      ALIST = (*CGBMISC_PAR.Factorize)(PA);
      C = CGBMISC_nzero;
      WFACTS = MASSTOR_SIL;
      do {
        MASSTOR_ADV(ALIST, &C_101_A, &ALIST);
        if (!(*CGBMISC_PAR.IsCnst)(C_101_A)) {
          C = (*CGBMISC_PAR.CondEval)(COND, C_101_A);
          if (C == CGBMISC_unknown) {
            WFACTS = MASSTOR_COMP(C_101_A, WFACTS);
          }
        }
      } while (!(C == CGBMISC_zero || ALIST == MASSTOR_SIL));
      if (C != CGBMISC_zero) {
        if (WFACTS == MASSTOR_SIL) {
          CRED = MASSTOR_COMP(PE, CRED);
        } else {
          CWHITE = MASSTOR_COMP(SACLIST_LIST2(PE, WFACTS), CWHITE);
        }
      }
    }
  } while (!(PI == MASSTOR_SIL));
  if (CRED != MASSTOR_SIL) {
    CRED = MASSTOR_INV(CRED);
  }
  if (CWHITE != MASSTOR_SIL) {
    CWHITE = MASSTOR_INV(CWHITE);
  }
  return CGBDSTR_ColCons(CRED, CWHITE);
}

MASSTOR_LIST CGBFUNC_SETCOL
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST COL)
# else
(COND, COL)
MASSTOR_LIST COND, COL;
# endif
{
  MASSTOR_LIST C_100_A, ALIST, CP, CRED, CRED1, CWHIT1, CWHITE, T, TT, WFACTS, NF;
  CGBMISC_COLOUR C;

  if (CGBDSTR_CondIsEmpty(COND) || CGBDSTR_ColIsEmpty(COL)) {
    return COL;
  }
  CGBDSTR_ColParts(COL, &CRED, &CWHITE);
  if (CWHITE == MASSTOR_SIL) {
    return COL;
  }
  CRED1 = MASSTOR_SIL;
  CWHIT1 = MASSTOR_SIL;
  TT = 0;
  while (CWHITE != MASSTOR_SIL) {
    MASSTOR_ADV(CWHITE, &CP, &CWHITE);
    SACLIST_FIRST2(CP, &T, &ALIST);
    WFACTS = MASSTOR_SIL;
    C = CGBMISC_nzero;
    do {
      MASSTOR_ADV(ALIST, &C_100_A, &ALIST);
      if (!(*CGBMISC_PAR.IsCnst)(C_100_A)) {
        C = (*CGBMISC_PAR.CondEval)(COND, C_100_A);
        if (C == CGBMISC_unknown) {
          WFACTS = MASSTOR_COMP(C_100_A, WFACTS);
        }
      }
    } while (!(C == CGBMISC_zero || ALIST == MASSTOR_SIL));
    if (C == CGBMISC_zero) {
      TT = 1;
    } else {
      if (WFACTS == MASSTOR_SIL) {
        CRED1 = MASSTOR_COMP(T, CRED1);
      } else {
        CWHIT1 = MASSTOR_COMP(SACLIST_LIST2(T, WFACTS), CWHIT1);
      }
    }
  }
  if (TT == 0 && CRED1 == MASSTOR_SIL) {
    return COL;
  }
  if (CWHIT1 != MASSTOR_SIL) {
    CWHIT1 = MASSTOR_INV(CWHIT1);
  }
  if (CRED1 != MASSTOR_SIL) {
    if (CRED == MASSTOR_SIL) {
      CRED = MASSTOR_INV(CRED1);
    } else {
      CRED = CGBFUNC_REDSRT(CRED, MASSTOR_INV(CRED1));
    }
  }
  return CGBDSTR_ColCons(CRED, CWHIT1);
}

MASSTOR_LIST CGBFUNC_REDSRT
# ifdef __STDC__
(MASSTOR_LIST RALT, MASSTOR_LIST RNEU)
# else
(RALT, RNEU)
MASSTOR_LIST RALT, RNEU;
# endif
{
  MASSTOR_LIST CCR, CRED, CRED0, CRED1, CREDP, SL, T, T1;

  CRED = RALT;
  CRED1 = RNEU;
  CRED0 = MASSTOR_SIL;
  do {
    MASSTOR_ADV(CRED1, &T1, &CRED1);
    do {
      MASSTOR_ADV(CRED, &T, &CREDP);
      SL = DIPC_EVCOMP(T1, T);
      if (SL == 1) {
        CRED0 = MASSTOR_COMP(T1, CRED0);
      } else {
        CRED0 = MASSTOR_COMP(T, CRED0);
        CRED = CREDP;
      }
    } while (!(SL == 1 || CRED == MASSTOR_SIL));
    if (SL <= 0) {
      CRED0 = MASSTOR_COMP(T1, CRED0);
    }
  } while (!(CRED1 == MASSTOR_SIL || CRED == MASSTOR_SIL));
  if (CRED == MASSTOR_SIL && CRED1 == MASSTOR_SIL) {
    return MASSTOR_INV(CRED0);
  }
  if (CRED != MASSTOR_SIL) {
    CCR = CRED;
  } else {
    CCR = CRED1;
  }
  while (CCR != MASSTOR_SIL) {
    MASSTOR_ADV(CCR, &T, &CCR);
    CRED0 = MASSTOR_COMP(T, CRED0);
  }
  return MASSTOR_INV(CRED0);
}

MASSTOR_LIST CGBFUNC_TESTHT
# ifdef __STDC__
(MASSTOR_LIST COL)
# else
(COL)
MASSTOR_LIST COL;
# endif
{
  MASSTOR_LIST CP, CE, CRED, CWHITE, RE, SL;

  if (CGBDSTR_ColIsEmpty(COL)) {
    return MASSTOR_SIL;
  }
  CGBDSTR_ColParts(COL, &CRED, &CWHITE);
  if (CWHITE == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (CRED == MASSTOR_SIL) {
    return MASSTOR_FIRST(CWHITE);
  }
  CP = MASSTOR_FIRST(CWHITE);
  if (DIPC_EVCOMP(MASSTOR_FIRST(CP), MASSTOR_FIRST(CRED)) <= 0) {
    return MASSTOR_SIL;
  }
  return CP;
}

void CGBFUNC_DETPOL
# ifdef __STDC__
(MASSTOR_LIST GA, MASSTOR_LIST PI, MASSTOR_LIST COL, MASSTOR_LIST *DLIST, MASSTOR_LIST *CLIST)
# else
(GA, PI, COL, DLIST, CLIST)
MASSTOR_LIST GA, PI, COL;
MASSTOR_LIST *DLIST, *CLIST;
# endif
{
  MASSTOR_LIST CCL, CP, DCOND, DD, DL, X, C0, C1;

  *DLIST = MASSTOR_SIL;
  *CLIST = MASSTOR_SIL;
  CP = CGBFUNC_TESTHT(COL);
  if (CP == MASSTOR_SIL) {
    *DLIST = MASSTOR_LIST1(GA);
    *CLIST = SACLIST_LIST2(GA, CGBDSTR_ColpCons(PI, COL));
    return;
  }
  DD = CGBFUNC_ADDCON(SACLIST_SECOND(CP), GA);
  while (DD != MASSTOR_SIL) {
    MASSTOR_ADV(DD, &DCOND, &DD);
    CGBFUNC_DETPOL(DCOND, PI, CGBFUNC_SETCOL(DCOND, COL), &DL, &CCL);
    *DLIST = SACLIST_CONC(*DLIST, DL);
    *CLIST = SACLIST_CONC(*CLIST, CCL);
  }
  return;
}

void CGBFUNC_DET
# ifdef __STDC__
(MASSTOR_LIST CONDS, MASSTOR_LIST P, MASSTOR_LIST *DLIST, MASSTOR_LIST *PPL)
# else
(CONDS, P, DLIST, PPL)
MASSTOR_LIST CONDS, P;
MASSTOR_LIST *DLIST, *PPL;
# endif
{
  MASSTOR_LIST CCL, CLIST, D, DL, GA, PI, X;

  *DLIST = CONDS;
  *PPL = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  CLIST = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &PI, &P);
    D = *DLIST;
    *DLIST = MASSTOR_SIL;
    if (D == MASSTOR_SIL) {
      CGBFUNC_DETPOL(CGBDSTR_CondEmpty(), PI, CGBDSTR_ColConsCond(PI, CGBDSTR_CondEmpty()), &DL, &CCL);
      *DLIST = DL;
      CLIST = SACLIST_CONC(CLIST, CCL);
    } else {
      do {
        MASSTOR_ADV(D, &GA, &D);
        CGBFUNC_DETPOL(GA, PI, CGBDSTR_ColConsCond(PI, GA), &DL, &CCL);
        *DLIST = SACLIST_CONC(*DLIST, DL);
        CLIST = SACLIST_CONC(CLIST, CCL);
      } while (!(D == MASSTOR_SIL));
    }
  }
  *PPL = CGBFUNC_VERIFY(*DLIST, CLIST);
  return;
}

MASSTOR_LIST CGBFUNC_VERIFY
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST CLIST)
# else
(D, CLIST)
MASSTOR_LIST D, CLIST;
# endif
{
  MASSTOR_LIST CCOND, CCOND0, CCOND1, DCOND, DCOND0, DCOND1, PLIST, PCO, CLIST1, PPL;

  if (CLIST == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (D == MASSTOR_SIL) {
    PLIST = MASSTOR_SIL;
    do {
      SACLIST_ADV2(CLIST, &CCOND, &PCO, &CLIST);
      PLIST = MASSTOR_COMP(PCO, PLIST);
    } while (!(CLIST == MASSTOR_SIL));
    return MASSTOR_COMP(SACLIST_LIST2(MASSTOR_SIL, CGBFUNC_CGBLPM(PLIST)), MASSTOR_SIL);
  }
  PPL = MASSTOR_SIL;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &DCOND, &D);
    SACLIST_FIRST2(DCOND, &DCOND0, &DCOND1);
    PLIST = MASSTOR_SIL;
    CLIST1 = CLIST;
    do {
      SACLIST_ADV2(CLIST1, &CCOND, &PCO, &CLIST1);
      if (CCOND == MASSTOR_SIL) {
        PLIST = MASSTOR_COMP(PCO, PLIST);
      } else {
        SACLIST_FIRST2(CCOND, &CCOND0, &CCOND1);
        if (CGBFUNC_AINB(CCOND0, DCOND0) == 1) {
          if (CGBFUNC_AINB(CCOND1, DCOND1) == 1) {
            PLIST = MASSTOR_COMP(PCO, PLIST);
          }
        }
      }
    } while (!(CLIST1 == MASSTOR_SIL));
    PLIST = CGBFUNC_CGBLPM(PLIST);
    PPL = MASSTOR_COMP(SACLIST_LIST2(DCOND, PLIST), PPL);
  }
  return PPL;
}

MASSTOR_LIST CGBFUNC_AINB
# ifdef __STDC__
(MASSTOR_LIST ALIST, MASSTOR_LIST BLIST)
# else
(ALIST, BLIST)
MASSTOR_LIST ALIST, BLIST;
# endif
{
  MASSTOR_LIST C_99_A, SL;

  if (ALIST == MASSTOR_SIL) {
    return 1;
  }
  if (BLIST == MASSTOR_SIL) {
    return 0;
  }
  do {
    MASSTOR_ADV(ALIST, &C_99_A, &ALIST);
    SL = SACLIST_MEMBER(C_99_A, BLIST);
  } while (!(ALIST == MASSTOR_SIL || SL == 0));
  return SL;
}

void BEGIN_CGBFUNC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_CGBDSTR();
    BEGIN_CGBMISC();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
