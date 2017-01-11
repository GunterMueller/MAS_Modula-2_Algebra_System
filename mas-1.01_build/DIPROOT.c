#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_SACROOT
#include "SACROOT.h"
#endif

#ifndef DEFINITION_SACANF
#include "SACANF.h"
#endif

#ifndef DEFINITION_DIPIDEAL
#include "DIPIDEAL.h"
#endif

#ifndef DEFINITION_DIPDEC0
#include "DIPDEC0.h"
#endif

#ifndef DEFINITION_DIPROOT
#include "DIPROOT.h"
#endif

CHAR DIPROOT_rcsid [] = "$Id: DIPROOT.md,v 1.3 1996/06/08 14:13:51 kredel Exp $";
CHAR DIPROOT_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define TRAFL	2
static CHAR rcsidi [] = "$Id: DIPROOT.mi,v 1.5 1996/06/08 14:13:56 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPROOT_DIGBSI
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST T, MASSTOR_LIST C_170_A)
# else
(P, T, C_170_A)
MASSTOR_LIST P, T, C_170_A;
# endif
{
  MASSTOR_LIST AL, B, BP, EL, FL1, FL2, I, IL, J, J1Y, PL, RL, RLP, SL, TL, VL;

  J1Y = MASSTOR_FIRST(P);
  RL = DIPC_DIPNOV(J1Y);
  EL = DIPC_DIPEVL(C_170_A);
  while (EL != MASSTOR_SIL && MASSTOR_FIRST(EL) == 0) {
    EL = MASSTOR_RED(EL);
  }
  IL = MASSTOR_LENGTH(EL);
  if (IL == 0) {
    AL = DIPC_DIPLBC(C_170_A);
    SL = SACRN_RNSIGN(AL);
    return SL;
  }
  B = C_170_A;
  {
    LONGINT B_1 = RL, B_2 = IL + 1;

    if (B_1 >= B_2)
      for (J = B_1;; J += -1) {
        DIPC_DIPADM(B, &FL1, &FL2, &B, &BP);
        if (J <= B_2) break;
      }
  }
  B = DIPC_DIPEXC(B, 1, IL);
  for (J = IL; J >= 2; J += -1) {
    DIPC_DIPADM(B, &FL1, &FL2, &B, &BP);
  }
  DIPC_PFDIP(B, &RLP, &B);
  TL = SACLIST_LELT(T, IL);
  SACLIST_FIRST3(TL, &VL, &I, &PL);
  SL = SACANF_AFSIGN(PL, I, B);
  return SL;
}

MASSTOR_LIST DIPROOT_DIITNT
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST C_169_A, A1, A2, EL, FL, I, I1, I2, IL, ILP, J1Y, L, P, PB, PL, PP, R, RL, S1, S2, TB, TL, TP, TPP, TS, V, VL, VP;

  TP = MASSTOR_BETA;
  TL = MASSTOR_BETA;
  if (T == MASSTOR_SIL) {
    return TP;
  }
  SACLIST_ADV3(T, &FL, &VP, &PP, &TB);
  RL = MASSTOR_LENGTH(VP);
  IL = 1;
  PB = MASSTOR_RED(PP);
  SACLIST_ADV3(TB, &FL, &V, &P, &TB);
  SACLIST_FIRST2(P, &EL, &PL);
  VL = MASSTOR_FIRST(V);
  L = SACROOT_IPRIM(PL);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &I, &L);
    J1Y = SACLIST_LIST3(VL, I, PL);
    R = MASSTOR_LIST1(J1Y);
    TP = MASSTOR_COMP(R, TP);
  }
  TP = MASSTOR_INV(TP);
  while (TB != MASSTOR_SIL) {
    ILP = IL;
    IL = IL + 1;
    TS = MASSTOR_BETA;
    SACLIST_ADV3(TB, &FL, &V, &P, &TB);
    MASSTOR_ADV(PB, &C_169_A, &PB);
    SACLIST_FIRST2(P, &EL, &PL);
    VL = MASSTOR_FIRST(V);
    L = SACROOT_IPRIM(PL);
    while (L != MASSTOR_SIL) {
      MASSTOR_ADV(L, &I, &L);
      SACLIST_FIRST2(I, &I1, &I2);
      A1 = DIPRN_DIRPEV(C_169_A, IL, I1);
      A1 = DIPC_DIPINV(A1, ILP, 1);
      A1 = DIPRNGB_DIRPNF(PP, A1);
      A2 = DIPRN_DIRPEV(C_169_A, IL, I2);
      A2 = DIPC_DIPINV(A2, ILP, 1);
      A2 = DIPRNGB_DIRPNF(PP, A2);
      TPP = TP;
      while (TPP != MASSTOR_SIL) {
        MASSTOR_ADV(TPP, &TL, &TPP);
        S1 = DIPROOT_DIGBSI(PP, TL, A1);
        S2 = DIPROOT_DIGBSI(PP, TL, A2);
        if (S1 * S2 <= 0) {
          R = SACLIST_LIST3(VL, I, PL);
          TL = SACLIST_CINV(TL);
          TL = MASSTOR_COMP(R, TL);
          TL = MASSTOR_INV(TL);
          TS = MASSTOR_COMP(TL, TS);
        }
      }
    }
    TP = MASSTOR_INV(TS);
  }
  return TP;
}

void DIPROOT_DIITWR
# ifdef __STDC__
(MASSTOR_LIST TP, MASSTOR_LIST EPS)
# else
(TP, EPS)
MASSTOR_LIST TP, EPS;
# endif
{
  MASSTOR_LIST E, I, J, J1Y, R, RL, T, TL, VS;

  T = TP;
  if (T == MASSTOR_SIL) {
    return;
  }
  J1Y = SACI_IEXP(10, EPS);
  E = SACRN_RNRED(1, J1Y);
  VS = DIPC_VALIS;
  RL = MASSTOR_LENGTH(VS);
  J = 0;
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &TL, &T);
    J = J + 1;
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Zero set tupel no ", 18L);
    SACLIST_AWRITE(J);
    MASBIOS_BLINES(1);
    while (TL != MASSTOR_SIL) {
      MASSTOR_ADV(TL, &R, &TL);
      DIPROOT_RIRWRT(R, E);
    }
    MASBIOS_BLINES(1);
  }
  return;
}

void DIPROOT_DINTWR
# ifdef __STDC__
(MASSTOR_LIST TP, MASSTOR_LIST EPS)
# else
(TP, EPS)
MASSTOR_LIST TP, EPS;
# endif
{
  MASSTOR_LIST E, FL, I, J, J1Y, PL, RL, T, TL, U, UP, V, VS;

  T = TP;
  if (T == MASSTOR_SIL) {
    return;
  }
  J1Y = SACI_IEXP(10, EPS);
  E = SACRN_RNRED(1, J1Y);
  VS = DIPC_VALIS;
  RL = MASSTOR_LENGTH(VS);
  J = 0;
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &TL, &T);
    J = J + 1;
    MASBIOS_SWRITE("Zero set tupel no ", 18L);
    SACLIST_AWRITE(J);
    MASBIOS_BLINES(1);
    while (TL != MASSTOR_SIL) {
      SACLIST_ADV3(TL, &FL, &V, &PL, &TL);
      switch ((INTEGER)FL) {
      case 1:;
        DIPROOT_DIROWR(V, PL, E);
        break;
      case 2:;
        MASBIOS_SWRITE("The groebner basis in the variables ", 36L);
        U = DIPIDEAL_DIPLDV(PL, VS);
        UP = SACSET_USDIFF(VS, U);
        SACPOL_VLWRIT(U);
        DIPRN_DIRLWR(PL, V, -1);
        if (U == MASSTOR_SIL) {
          MASBIOS_SWRITE("There are no roots at all", 25L);
        } else {
          MASBIOS_SWRITE("Exponent zero variables ", 24L);
          SACPOL_VLWRIT(UP);
        }
        MASBIOS_BLINES(2);
        break;
      case 3:;
        MASBIOS_SWRITE("The total ring D", 16L);
        SACPOL_VLWRIT(V);
        MASBIOS_BLINES(2);
        break;
      case 4:;
        MASBIOS_SWRITE("The generating polynomial for tree ", 35L);
        DIPRN_DIRLWR(PL, V, -1);
        MASBIOS_BLINES(2);
        break;
      case 5:;
        MASBIOS_SWRITE("Groebner basis for tree", 23L);
        DIPRN_DIRLWR(PL, V, -1);
        MASBIOS_BLINES(2);
        break;
      case 6:;
        MASBIOS_SWRITE("Characterising groebner basis", 29L);
        DIPRN_DIRLWR(PL, V, -1);
        MASBIOS_BLINES(2);
        break;
      default :
        MASBIOS_SWRITE("Invalid flag in DINTWR ", 23L);
        SACLIST_OWRITE(FL);
        MASBIOS_BLINES(1);
        break;
      }
    }
  }
  MASBIOS_BLINES(1);
}

void DIPROOT_DIROWR
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST P, MASSTOR_LIST EPS)
# else
(V, P, EPS)
MASSTOR_LIST V, P, EPS;
# endif
{
  MASSTOR_LIST AL, BL, CL, EL, I, IL, J1Y, J2Y, KL, L, ILEN, LM, LS, PL, QL, S, VL, W, Z;

  if (MASSTOR_LENGTH(V) != 1) {
    return;
  }
  SACLIST_FIRST2(P, &EL, &PL);
  VL = MASSTOR_FIRST(V);
  MASBIOS_SWRITE("Characterising polynomial for the real roots is", 47L);
  MASBIOS_BLINES(1);
  QL = DIPC_DIPFP(1, PL);
  QL = DIPRN_DIRFIP(QL);
  MASBIOS_SWRITE("p", 1L);
  SACPOL_VLWRIT(V);
  MASBIOS_SWRITE(" = ", 3L);
  DIPRN_DIRPWR(QL, V, -1);
  if (EL != 1) {
    MASBIOS_SWRITE("**", 2L);
    SACLIST_AWRITE(EL);
  }
  MASBIOS_BLINES(1);
  if (TRAFL < 100) {
    return;
  }
  L = SACROOT_IPRIM(PL);
  if (L == MASSTOR_SIL) {
    MASBIOS_SWRITE("There are no real roots", 23L);
  } else {
    MASBIOS_SWRITE("The isolating interval", 22L);
    if (MASSTOR_RED(L) == MASSTOR_SIL) {
      MASBIOS_SWRITE(" for the the real root is", 25L);
    } else {
      MASBIOS_SWRITE("s for the the real roots are", 28L);
    }
  }
  MASBIOS_BLINES(1);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &IL, &L);
    SACLIST_FIRST2(IL, &AL, &BL);
    SACLIST_CLOUT(VL);
    MASBIOS_SWRITE(" = ", 3L);
    MASBIOS_SWRITE("(", 1L);
    SACRN_RNWRIT(AL);
    MASBIOS_SWRITE(", ", 2L);
    SACRN_RNWRIT(BL);
    MASBIOS_SWRITE(")", 1L);
    MASBIOS_BLINES(1);
    if (TRAFL >= 2) {
      if (SACLIST_EQUAL(AL, BL) != 1) {
        J1Y = SACRN_RNDEN(EPS);
        J1Y = SACI_ILOG2(J1Y);
        KL = J1Y + 1;
        KL = -KL;
        I = SACROOT_IPRCHS(PL, IL, KL);
        IL = MASSTOR_FIRST(I);
        SACLIST_FIRST2(IL, &AL, &BL);
      }
      J1Y = SACRN_RNDEN(AL);
      J2Y = SACRN_RNDEN(BL);
      ILEN = SACI_IMAX(J1Y, J2Y);
      J1Y = SACRN_RNDEN(EPS);
      ILEN = SACI_IMIN(ILEN, J1Y);
      Z = 10;
      LS = 1;
      S = 0;
      while (SACI_ICOMP(ILEN, LS) >= 0) {
        S = S + 1;
        LS = SACI_IPROD(LS, Z);
      }
      W = SACRN_RNRED(1, 2);
      CL = SACRN_RNSUM(AL, BL);
      CL = SACRN_RNPROD(CL, W);
      SACLIST_CLOUT(VL);
      MASBIOS_SWRITE(" = ", 3L);
      MASRN_RNDWR(CL, S);
      MASBIOS_BLINES(1);
    }
  }
}

void DIPROOT_GBZSET
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST PP, MASSTOR_LIST EPS)
# else
(V, PP, EPS)
MASSTOR_LIST V, PP, EPS;
# endif
{
  MASSTOR_LIST N, T, T0, T1, TL, TP;

  N = DIPDEC0_DIRGZS(V, PP, V);
  T = DIPDEC0_DINTZS(N);
  MASBIOS_SWRITE("The normalized tupels", 21L);
  MASBIOS_BLINES(1);
  DIPROOT_DINTWR(T, EPS);
  DIPDEC0_DITSPL(T, &T0, &T1);
  if (T0 == MASSTOR_SIL) {
    return;
  }
  T0 = DIPDEC0_DINTSR(T0);
  MASBIOS_SWRITE("The refined tupels", 18L);
  MASBIOS_BLINES(1);
  DIPROOT_DINTWR(T0, EPS);
  TP = MASSTOR_SIL;
  while (T0 != MASSTOR_SIL) {
    MASSTOR_ADV(T0, &TL, &T0);
    TL = DIPROOT_DIITNT(TL);
    TP = SACLIST_CONC(TP, TL);
  }
  MASBIOS_SWRITE("The zero set for dim 0 tupels", 29L);
  MASBIOS_BLINES(1);
  DIPROOT_DIITWR(TP, EPS);
}

void DIPROOT_RIRWRT
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST EPS)
# else
(R, EPS)
MASSTOR_LIST R, EPS;
# endif
{
  MASSTOR_LIST AL, BL, CL, I, IL, ILEN, J1Y, J2Y, KL, LM, LS, PL, QL, S, V, VL, W, Z;

  SACLIST_FIRST3(R, &VL, &IL, &PL);
  if (TRAFL >= 2) {
    MASBIOS_SWRITE("Characterising polynomial for the real root is", 46L);
    MASBIOS_BLINES(1);
    QL = DIPC_DIPFP(1, PL);
    QL = DIPRN_DIRFIP(QL);
    V = MASSTOR_LIST1(VL);
    MASBIOS_SWRITE("p", 1L);
    SACPOL_VLWRIT(V);
    MASBIOS_SWRITE(" = ", 3L);
    DIPRN_DIRPWR(QL, V, -1);
    MASBIOS_BLINES(1);
  }
  if (IL == MASSTOR_SIL) {
    return;
  }
  SACLIST_FIRST2(IL, &AL, &BL);
  if (TRAFL >= 2) {
    MASBIOS_SWRITE("The isolating interval for the real root is", 43L);
    MASBIOS_BLINES(1);
    SACLIST_CLOUT(VL);
    MASBIOS_SWRITE(" = (", 4L);
    SACRN_RNWRIT(AL);
    MASBIOS_SWRITE(", ", 2L);
    SACRN_RNWRIT(BL);
    MASBIOS_SWRITE(")", 1L);
    MASBIOS_BLINES(1);
  }
  if (SACLIST_EQUAL(AL, BL) != 1) {
    J1Y = SACRN_RNDEN(EPS);
    J1Y = SACI_ILOG2(J1Y);
    KL = J1Y + 1;
    KL = -KL;
    I = SACROOT_IPRCHS(PL, IL, KL);
    IL = MASSTOR_FIRST(I);
  }
  SACLIST_FIRST2(IL, &AL, &BL);
  J1Y = SACRN_RNDEN(AL);
  J2Y = SACRN_RNDEN(BL);
  ILEN = SACI_IMAX(J1Y, J2Y);
  J1Y = SACRN_RNDEN(EPS);
  ILEN = SACI_IMIN(ILEN, J1Y);
  Z = 10;
  LS = 1;
  S = 0;
  while (SACI_ICOMP(ILEN, LS) >= 0) {
    S = S + 1;
    LS = SACI_IPROD(LS, Z);
  }
  if (TRAFL >= 2) {
    MASBIOS_SWRITE("The decimal approximation for the real root is", 46L);
    MASBIOS_BLINES(1);
  }
  SACLIST_CLOUT(VL);
  MASBIOS_SWRITE(" = ", 3L);
  W = SACRN_RNRED(1, 2);
  CL = SACRN_RNSUM(AL, BL);
  CL = SACRN_RNPROD(CL, W);
  MASRN_RNDWR(CL, S);
  MASBIOS_BLINES(1);
}

void BEGIN_DIPROOT()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACSET();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_SACROOT();
    BEGIN_SACANF();
    BEGIN_DIPIDEAL();
    BEGIN_DIPDEC0();

  }
}
