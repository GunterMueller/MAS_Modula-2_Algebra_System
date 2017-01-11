#include "SYSTEM_.h"

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

#ifndef DEFINITION_CGBSYS
#include "CGBSYS.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
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

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_CGBAPPL
#include "CGBAPPL.h"
#endif

CHAR CGBAPPL_rcsid [] = "$Id: CGBAPPL.md,v 1.5 1996/06/08 16:47:03 pesch Exp $";
CHAR CGBAPPL_copyright [] = "Copyright (c) 1989 - 1996 Universitaet Passau";

static MASSTOR_LIST LMARG, RMARG;
static CHAR rcsidi [] = "$Id: CGBAPPL.mip,v 1.6 1996/06/08 16:47:05 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1996 Universitaet Passau";


void CGBAPPL_GTEST
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST P, MASSTOR_LIST *C0, MASSTOR_LIST *C1)
# else
(C, P, C0, C1)
MASSTOR_LIST C, P;
MASSTOR_LIST *C0, *C1;
# endif
{
  MASSTOR_LIST CC0, CC1, COND, DEL, PAIRS, PCO, PELEM, PLIST, PPL;

  *C0 = MASSTOR_SIL;
  *C1 = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return;
  }
  if (MASSTOR_RED(P) == MASSTOR_SIL) {
    return;
  }
  CGBFUNC_DET(C, P, &DEL, &PPL);
  while (PPL != MASSTOR_SIL) {
    MASSTOR_ADV(PPL, &PELEM, &PPL);
    SACLIST_FIRST2(PELEM, &COND, &PLIST);
    PCO = CGBSYS_CHDEGL(PLIST);
    if (PCO == MASSTOR_SIL && MASSTOR_RED(PLIST) != MASSTOR_SIL) {
      PAIRS = CGBSYS_MKPAIR(PLIST);
      if (PAIRS != MASSTOR_SIL) {
        CGBAPPL_GBHELP(COND, PAIRS, PLIST, &CC0, &CC1);
        *C0 = SACLIST_CONC(*C0, CC0);
        *C1 = SACLIST_CONC(*C1, CC1);
      } else {
        if (SACLIST_MEMBER(COND, *C0) == 0) {
          *C0 = MASSTOR_COMP(COND, *C0);
        }
      }
    } else {
      if (SACLIST_MEMBER(COND, *C0) == 0) {
        *C0 = MASSTOR_COMP(COND, *C0);
      }
    }
  }
  return;
}

void CGBAPPL_GBHELP
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST PPAIRS, MASSTOR_LIST P, MASSTOR_LIST *C0, MASSTOR_LIST *C1)
# else
(COND, PPAIRS, P, C0, C1)
MASSTOR_LIST COND, PPAIRS, P;
MASSTOR_LIST *C0, *C1;
# endif
{
  MASSTOR_LIST FCO, GCO, HCO, N0, N1, PAIR, PAIRS;

  PAIRS = PPAIRS;
  *C0 = MASSTOR_SIL;
  *C1 = MASSTOR_SIL;
  while (PAIRS != MASSTOR_SIL) {
    MASSTOR_ADV(PAIRS, &PAIR, &PAIRS);
    FCO = SACLIST_SECOND(PAIR);
    GCO = SACLIST_THIRD(PAIR);
    HCO = CGBSYS_SPOL(COND, FCO, GCO);
    if (HCO != MASSTOR_SIL) {
      (*CGBMISC_PAR.NormalForm)(COND, HCO, P, &N0, &N1);
      if (N1 == MASSTOR_SIL) {
        if (SACLIST_MEMBER(COND, *C0) == 0) {
          *C0 = MASSTOR_COMP(COND, *C0);
        }
      }
      if (N0 == MASSTOR_SIL) {
        if (SACLIST_MEMBER(COND, *C1) == 0) {
          *C1 = MASSTOR_COMP(COND, *C1);
        }
      }
      if (N0 != MASSTOR_SIL && N1 != MASSTOR_SIL) {
        CGBAPPL_NSET(N0, N1, *C0, *C1, C0, C1);
      }
    } else {
      *C0 = MASSTOR_COMP(COND, *C0);
    }
  }
  return;
}

void CGBAPPL_NSET
# ifdef __STDC__
(MASSTOR_LIST NN0, MASSTOR_LIST NN1, MASSTOR_LIST CC0, MASSTOR_LIST CC1, MASSTOR_LIST *C0, MASSTOR_LIST *C1)
# else
(NN0, NN1, CC0, CC1, C0, C1)
MASSTOR_LIST NN0, NN1, CC0, CC1;
MASSTOR_LIST *C0, *C1;
# endif
{
  MASSTOR_LIST C, COND, N0, N1, PCO;

  *C0 = CC0;
  *C1 = CC1;
  N0 = NN0;
  N1 = NN1;
  while (N1 != MASSTOR_SIL) {
    SACLIST_ADV3(N1, &COND, &PCO, &C, &N1);
    if (SACLIST_MEMBER(COND, *C1) == 0) {
      *C1 = MASSTOR_COMP(COND, *C1);
    }
  }
  while (N0 != MASSTOR_SIL) {
    SACLIST_ADV3(N0, &COND, &PCO, &C, &N0);
    if (SACLIST_MEMBER(COND, *C0) == 0 && SACLIST_MEMBER(COND, *C1) == 0) {
      *C0 = MASSTOR_COMP(COND, *C0);
    }
  }
  return;
}

void CGBAPPL_WRTEST
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST PP, MASSTOR_LIST CGB0, MASSTOR_LIST CGB1)
# else
(C, PP, CGB0, CGB1)
MASSTOR_LIST C, PP, CGB0, CGB1;
# endif
{
  MASSTOR_LIST C0, C1, COND, SL, TL;

  MASBIOS_SWRITE("Groebner test for ", 18L);
  MASBIOS_BLINES(1);
  if (C != MASSTOR_SIL) {
    CGBFUNC_DWRIT(C);
  }
  DIPADOM_DILWR(PP, DIPC_VALIS);
  C0 = CGB0;
  C1 = CGB1;
  MASBIOS_BLINES(0);
  if (C0 != MASSTOR_SIL && C1 != MASSTOR_SIL) {
    MASBIOS_SWRITE(" Conditions such that G is groebner basis ", 42L);
    TL = 0;
    MASBIOS_BLINES(1);
    while (C0 != MASSTOR_SIL) {
      MASSTOR_ADV(C0, &COND, &C0);
      SL = CGBAPPL_CPART(COND, C1);
      if (SL == 0) {
        SL = CGBAPPL_CPART(COND, C0);
      }
      if (SL == 0) {
        CGBDSTR_CondWrite(COND);
        TL = 1;
      }
    }
    if (TL == 0) {
      MASBIOS_SWRITE("sorry, none. ", 13L);
      MASBIOS_BLINES(0);
    }
  }
  if (C1 != MASSTOR_SIL) {
    MASBIOS_SWRITE(" Conditions such that G is no groebner basis ", 45L);
    MASBIOS_BLINES(1);
    while (C1 != MASSTOR_SIL) {
      MASSTOR_ADV(C1, &COND, &C1);
      if (CGBAPPL_CPART(COND, C1) == 0) {
        MASBIOS_BLINES(1);
        CGBDSTR_CondWrite(COND);
      }
    }
  }
  if (CGB1 == MASSTOR_SIL) {
    MASBIOS_SWRITE(" G is comprehensive-groebner-basis ", 35L);
  }
  MASBIOS_BLINES(0);
  return;
}

MASSTOR_LIST CGBAPPL_CPART
# ifdef __STDC__
(MASSTOR_LIST COND, MASSTOR_LIST CONDS)
# else
(COND, CONDS)
MASSTOR_LIST COND, CONDS;
# endif
{
  MASSTOR_LIST C_117_A, A0, A1, COND0, COND1, SL, X;

  SL = 0;
  if (CONDS == MASSTOR_SIL) {
    return SL;
  }
  X = CONDS;
  CGBDSTR_CondParts(COND, &COND0, &COND1);
  do {
    MASSTOR_ADV(X, &C_117_A, &X);
    CGBDSTR_CondParts(C_117_A, &A0, &A1);
    SL = CGBFUNC_AINB(COND0, A0);
    if (SL == 1) {
      SL = CGBFUNC_AINB(COND1, A1);
    }
  } while (!(X == MASSTOR_SIL || SL == 1));
  return SL;
}

void CGBAPPL_CGBQUA
# ifdef __STDC__
(MASSTOR_LIST PP)
# else
(PP)
MASSTOR_LIST PP;
# endif
{
  MASSTOR_LIST B, COEF, COEFLI, LS, P, PA, PCO, QQ, RS, SL, TL, TT, V, var;

  if (PP == MASSTOR_SIL) {
    return;
  }
  MASBIOS_BLINES(1);
  V = DIPC_VALIS;
  TT = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &var, &V);
    TT = MASSTOR_COMP(0, TT);
  }
  PCO = CGBSYS_CHDEGL(PP);
  if (PCO != MASSTOR_SIL) {
    MASBIOS_SWRITE("false", 5L);
    MASBIOS_BLINES(0);
    return;
  }
  P = PP;
  SL = 0;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &PCO, &P);
    CGBAPPL_MCOEF(PCO, &COEFLI, &COEF, &B);
    if (COEF != MASSTOR_SIL && B == 0) {
      SL = 1;
      if (COEF != 0) {
        QQ = DIPC_DIPFMO(COEF, TT);
        if (TL == 1) {
          MASBIOS_SWRITE("  and", 5L);
          MASBIOS_BLINES(1);
        }
        TL = 1;
        MASBIOS_SWRITE("( ( ", 4L);
        DIPADOM_DIWRIT(QQ, DIPC_VALIS);
        MASBIOS_SWRITE("  = 0  ", 7L);
        MASBIOS_SWRITE(")", 1L);
        if (COEFLI != MASSTOR_SIL) {
          MASBIOS_SWRITE("  or  ", 6L);
          MASBIOS_BLINES(1);
        }
      }
      while (COEFLI != MASSTOR_SIL) {
        MASSTOR_ADV(COEFLI, &PA, &COEFLI);
        MASBIOS_SWRITE("(", 1L);
        MASADOM_ADWRIT(PA);
        MASBIOS_SWRITE(" <> 0  ", 7L);
        MASBIOS_SWRITE(")", 1L);
        if (COEFLI != MASSTOR_SIL) {
          MASBIOS_SWRITE("  or", 4L);
        }
      }
      MASBIOS_SWRITE(")", 1L);
    }
  }
  if (SL == 0) {
    MASBIOS_SWRITE("true", 4L);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(1);
}

void CGBAPPL_MCOEF
# ifdef __STDC__
(MASSTOR_LIST PCO, MASSTOR_LIST *COEFLI, MASSTOR_LIST *COEF, MASSTOR_LIST *TL)
# else
(PCO, COEFLI, COEF, TL)
MASSTOR_LIST PCO;
MASSTOR_LIST *COEFLI, *COEF, *TL;
# endif
{
  MASSTOR_LIST COL, CRED, CWHITE, PA, PE, POL;

  *COEFLI = MASSTOR_SIL;
  *COEF = MASSTOR_SIL;
  if (PCO == MASSTOR_SIL) {
    return;
  }
  CGBDSTR_ColpParts(PCO, &POL, &COL);
  if (CGBDSTR_ColIsEmpty(COL)) {
    return;
  }
  *TL = 0;
  CGBDSTR_ColParts(COL, &CRED, &CWHITE);
  do {
    DIPC_DIPMAD(POL, &PA, &PE, &POL);
    if (MASADOM_ADSIGN(PA) == -1) {
      PA = MASADOM_ADNEG(PA);
    }
    if (SACLIST_MEMBER(PE, CRED) == 1) {
      if (POL == MASSTOR_SIL) {
        if (DIPC_DIPTDG(DIPC_DIPFMO(PA, PE)) != 0) {
          *TL = 1;
        } else {
          *COEF = 0;
        }
      } else {
        *TL = 1;
      }
    } else {
      if (CGBFUNC_WMEMB(PE, CWHITE) == 1) {
        if (POL == MASSTOR_SIL) {
          if (DIPC_DIPTDG(DIPC_DIPFMO(PA, PE)) == 0) {
            *COEF = PA;
          } else {
            if (SACLIST_MEMBER(PA, *COEFLI) == 0) {
              *COEFLI = MASSTOR_COMP(PA, *COEFLI);
            }
          }
        } else {
          if (SACLIST_MEMBER(PA, *COEFLI) == 0) {
            *COEFLI = MASSTOR_COMP(PA, *COEFLI);
          }
        }
      }
    }
  } while (!(POL == MASSTOR_SIL || *TL == 1));
  if (*TL == 1) {
    *COEFLI = MASSTOR_SIL;
    return;
  }
  *COEFLI = MASSTOR_INV(*COEFLI);
  return;
}

void CGBAPPL_NFEXEC
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST PPS, MASSTOR_LIST PP, MASSTOR_LIST *NOUT)
# else
(C, PPS, PP, NOUT)
MASSTOR_LIST C, PPS, PP;
MASSTOR_LIST *NOUT;
# endif
{
  MASSTOR_LIST COL, COND, D, N0, N1, NN0, NN1, PELEM, PL, PLIST, POL, PPL, PS, X;

  *NOUT = MASSTOR_SIL;
  CGBFUNC_DET(C, PP, &D, &PL);
  PS = PPS;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &POL, &PS);
    NN0 = MASSTOR_SIL;
    NN1 = MASSTOR_SIL;
    PPL = PL;
    while (PPL != MASSTOR_SIL) {
      MASSTOR_ADV(PPL, &PELEM, &PPL);
      SACLIST_FIRST2(PELEM, &COND, &PLIST);
      PLIST = CGBSYS_REXTP(PLIST);
      (*CGBMISC_PAR.NormalForm)(COND, CGBDSTR_ColpConsCond(POL, COND), PLIST, &N0, &N1);
      NN0 = SACLIST_CONC(NN0, N0);
      NN1 = SACLIST_CONC(NN1, N1);
    }
    *NOUT = SACLIST_COMP3(POL, NN0, NN1, *NOUT);
  }
  return;
}

void CGBAPPL_WRQFN0
# ifdef __STDC__
(MASSTOR_LIST N0)
# else
(N0)
MASSTOR_LIST N0;
# endif
{
  MASSTOR_LIST AT, C, C0, COND, COND0, COND1, LS, NN0, PA, PCO, RS, TT, V, var;

  MASBIOS_SWRITE("Quantifier free formula for ", 28L);
  MASBIOS_SWRITE("parametric ideal membership ", 28L);
  MASBIOS_BLINES(1);
  if (N0 == MASSTOR_SIL) {
    MASBIOS_SWRITE("false ", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_BLINES(1);
  LS = LMARG;
  RS = RMARG;
  LMARG = 3;
  RMARG = 70;
  MASBIOS_BLINES(0);
  V = DIPC_VALIS;
  TT = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &var, &V);
    TT = MASSTOR_COMP(0, TT);
  }
  NN0 = N0;
  while (NN0 != MASSTOR_SIL) {
    SACLIST_ADV3(NN0, &COND, &PCO, &C, &NN0);
    CGBDSTR_CondParts(COND, &COND0, &COND1);
    C0 = COND0;
    MASBIOS_SWRITE("(", 1L);
    while (COND0 != MASSTOR_SIL) {
      MASSTOR_ADV(COND0, &PA, &COND0);
      AT = DIPC_DIPFMO(PA, TT);
      MASBIOS_SWRITE("(", 1L);
      DIPADOM_DIWRIT(AT, DIPC_VALIS);
      MASBIOS_SWRITE(" eq 0  ", 7L);
      MASBIOS_SWRITE(")", 1L);
      if (COND0 != MASSTOR_SIL) {
        MASBIOS_SWRITE("  and ", 6L);
      }
    }
    if (C0 != MASSTOR_SIL && COND1 != MASSTOR_SIL) {
      MASBIOS_SWRITE("  and ", 6L);
      MASBIOS_BLINES(0);
    }
    while (COND1 != MASSTOR_SIL) {
      MASSTOR_ADV(COND1, &PA, &COND1);
      AT = DIPC_DIPFMO(PA, TT);
      MASBIOS_SWRITE("(", 1L);
      DIPADOM_DIWRIT(AT, DIPC_VALIS);
      MASBIOS_SWRITE(" neq 0  ", 8L);
      MASBIOS_SWRITE(")", 1L);
      if (COND1 != MASSTOR_SIL) {
        MASBIOS_SWRITE("  and ", 6L);
      }
    }
    MASBIOS_SWRITE(")", 1L);
    MASBIOS_BLINES(0);
    if (NN0 != MASSTOR_SIL) {
      MASBIOS_SWRITE(" OR ", 4L);
      MASBIOS_BLINES(0);
    }
  }
  LMARG = LS;
  RMARG = RS;
  MASBIOS_BLINES(0);
  return;
}

MASSTOR_LIST CGBAPPL_DIMEXE
# ifdef __STDC__
(MASSTOR_LIST GS, MASSTOR_LIST V)
# else
(GS, V)
MASSTOR_LIST GS, V;
# endif
{
  MASSTOR_LIST COND, DIML, DL, PLIST, X, XELEM;

  if (GS == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  X = GS;
  DIML = MASSTOR_SIL;
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &XELEM, &X);
    SACLIST_FIRST2(XELEM, &COND, &PLIST);
    CGBDSTR_CondWrite(COND);
    MASBIOS_SWRITE("Groebner basis ", 15L);
    if (PLIST == MASSTOR_SIL) {
      MASBIOS_SWRITE("Basis is empty ", 15L);
      MASBIOS_BLINES(1);
    } else {
      CGBFUNC_DCLWR(PLIST, 0);
      DL = CGBAPPL_INTDIM(V, CGBFUNC_CGBCOL(COND, PLIST));
      MASBIOS_BLINES(0);
      if (DL != MASSTOR_SIL) {
        DIML = SACLIST_COMP2(COND, DL, DIML);
      }
    }
  }
  return DIML;
}

MASSTOR_LIST CGBAPPL_INTDIM
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST PP)
# else
(V, PP)
MASSTOR_LIST V, PP;
# endif
{
  MASSTOR_LIST DL, M, ML, S, VV, var;

  if (PP == MASSTOR_SIL) {
    MASBIOS_SWRITE("Basis is empty", 14L);
    MASBIOS_BLINES(0);
    VV = DIPC_VALIS;
    DL = 0;
    while (VV != MASSTOR_SIL) {
      MASSTOR_ADV(VV, &var, &VV);
      DL = DL + 1;
    }
    MASBIOS_SWRITE("dimension =", 11L);
    SACLIST_OWRITE(DL);
    MASBIOS_BLINES(1);
    return DL;
  }
  DIPDIM_DILDIM(PP, &DL, &S, &M);
  MASBIOS_SWRITE("dimension =", 11L);
  SACLIST_OWRITE(DL);
  MASBIOS_BLINES(1);
  if (DL != -1) {
    VV = DIPDIM_IXSUBS(V, S);
    MASBIOS_SWRITE("maximal independent set =", 25L);
    SACPOL_VLWRIT(VV);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("M     =", 7L);
    MASBIOS_SWRITE("(", 1L);
    while (M != MASSTOR_SIL) {
      MASSTOR_ADV(M, &ML, &M);
      VV = DIPDIM_IXSUBS(V, ML);
      SACPOL_VLWRIT(VV);
      if (M != MASSTOR_SIL) {
        MASBIOS_SWRITE(",", 1L);
      }
    }
    MASBIOS_SWRITE(")", 1L);
    MASBIOS_BLINES(1);
  }
  return DL;
}

void CGBAPPL_WRDIMS
# ifdef __STDC__
(MASSTOR_LIST DIML)
# else
(DIML)
MASSTOR_LIST DIML;
# endif
{
  MASSTOR_LIST COND, CONDS, DIM, DIMO, DL, X, XP;

  if (DIML == MASSTOR_SIL) {
    return;
  }
  MASBIOS_SWRITE("Quantifier free formula for ", 28L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("parametric dimension ", 21L);
  MASBIOS_BLINES(1);
  X = DIML;
  DIMO = MASSTOR_SIL;
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &COND, &DIM, &X);
    CONDS = MASSTOR_SIL;
    if (SACLIST_MEMBER(DIM, DIMO) == 0) {
      DIMO = MASSTOR_COMP(DIM, DIMO);
      CONDS = MASSTOR_COMP(COND, CONDS);
      XP = X;
      while (XP != MASSTOR_SIL) {
        SACLIST_ADV2(XP, &COND, &DL, &XP);
        if (DL == DIM) {
          CONDS = MASSTOR_COMP(COND, CONDS);
        }
      }
      MASBIOS_SWRITE("dimension = ", 12L);
      SACLIST_OWRITE(DIM);
      MASBIOS_BLINES(0);
      CGBAPPL_WRCONJ(CONDS);
    }
  }
  MASBIOS_BLINES(1);
  return;
}

void CGBAPPL_WRCONJ
# ifdef __STDC__
(MASSTOR_LIST CONDS)
# else
(CONDS)
MASSTOR_LIST CONDS;
# endif
{
  MASSTOR_LIST AT, C, C0, COND, COND0, COND1, LS, PA, RS, TT, V, var;

  if (CONDS == MASSTOR_SIL) {
    MASBIOS_SWRITE("false ", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_BLINES(1);
  LS = LMARG;
  RS = RMARG;
  LMARG = 3;
  RMARG = 70;
  MASBIOS_BLINES(0);
  V = DIPC_VALIS;
  TT = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &var, &V);
    TT = MASSTOR_COMP(0, TT);
  }
  C = CONDS;
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &COND, &C);
    CGBDSTR_CondParts(COND, &COND0, &COND1);
    C0 = COND0;
    MASBIOS_SWRITE("(", 1L);
    while (COND0 != MASSTOR_SIL) {
      MASSTOR_ADV(COND0, &PA, &COND0);
      AT = DIPC_DIPFMO(PA, TT);
      MASBIOS_SWRITE("(", 1L);
      DIPADOM_DIWRIT(AT, DIPC_VALIS);
      MASBIOS_SWRITE(" eq 0  ", 7L);
      MASBIOS_SWRITE(")", 1L);
      if (COND0 != MASSTOR_SIL) {
        MASBIOS_SWRITE("  AND ", 6L);
      }
    }
    if (C0 != MASSTOR_SIL && COND1 != MASSTOR_SIL) {
      MASBIOS_SWRITE("  and ", 6L);
      MASBIOS_BLINES(0);
    }
    while (COND1 != MASSTOR_SIL) {
      MASSTOR_ADV(COND1, &PA, &COND1);
      AT = DIPC_DIPFMO(PA, TT);
      MASBIOS_SWRITE("(", 1L);
      DIPADOM_DIWRIT(AT, DIPC_VALIS);
      MASBIOS_SWRITE(" neq 0  ", 8L);
      MASBIOS_SWRITE(")", 1L);
      if (COND1 != MASSTOR_SIL) {
        MASBIOS_SWRITE("  and ", 6L);
      }
    }
    MASBIOS_SWRITE(")", 1L);
    MASBIOS_BLINES(0);
    if (C != MASSTOR_SIL) {
      MASBIOS_SWRITE(" or ", 4L);
      MASBIOS_BLINES(0);
    }
  }
  LMARG = LS;
  RMARG = RS;
  MASBIOS_BLINES(0);
  return;
}

void BEGIN_CGBAPPL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_CGBDSTR();
    BEGIN_CGBFUNC();
    BEGIN_CGBMISC();
    BEGIN_CGBSYS();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPDIM();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACPOL();

  }
}
