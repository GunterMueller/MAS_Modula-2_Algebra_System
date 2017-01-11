#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

CHAR MASNC_rcsid [] = "$Id: MASNC.md,v 1.3 1992/10/16 14:07:55 kredel Exp $";
CHAR MASNC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASNC.mi,v 1.3 1992/10/15 16:29:46 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASNC_DINPPR
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST C_105_A, MASSTOR_LIST B)
# else
(T, C_105_A, B)
MASSTOR_LIST T, C_105_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, C1, C2, CL, CS, E1, E2, E3, E4, EL, EL1, EL1S, EP, F1, F2, F3, FL, FL1, FL1S, FP, FS, GL, J1Y, N, O, RL, XL, XL1, XL2;

  C = 0;
  if (C_105_A == 0) {
    return C;
  }
  if (B == 0) {
    return C;
  }
  if (DIPRN_DIRPON(C_105_A) == 1) {
    C = B;
    return C;
  }
  if (DIPRN_DIRPON(B) == 1) {
    C = C_105_A;
    return C;
  }
  O = SACRN_RNINT(1);
  RL = DIPC_DIPNOV(C_105_A);
  N = MASNC_EVZERO(RL);
  AP = C_105_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    BP = B;
    do {
      DIPC_DIPMAD(BP, &BL, &FL, &BP);
      EP = DIPC_EVDOV(EL);
      EL1 = RL + 1;
      if (EP != MASSTOR_SIL) {
        EL1 = MASSTOR_FIRST(EP);
      }
      FP = DIPC_EVDOV(FL);
      FL1 = 0;
      if (FP != MASSTOR_SIL) {
        FS = SACLIST_CINV(FP);
        FL1 = MASSTOR_FIRST(FS);
      }
      J1Y = RL + 1;
      FL1S = J1Y - FL1;
      J1Y = RL + 1;
      EL1S = J1Y - EL1;
      if (EL1S <= FL1S) {
        GL = DIPC_EVSUM(EL, FL);
        CS = DIPC_DIPFMO(O, GL);
      } else {
        DIPC_EVSU(EL, EL1, 0, &E1, &XL1);
        DIPC_EVSU(FL, FL1, 0, &F1, &XL2);
        DIPC_EVCADD(N, EL1, XL1, &E2, &XL);
        DIPC_EVCADD(N, FL1, XL2, &F2, &XL);
        MASNC_DINPTL(T, E2, F2, &CS, &E3, &F3);
        if (F3 != MASSTOR_SIL) {
          C2 = DIPC_DIPFMO(O, F3);
          CS = MASNC_DINPPR(T, CS, C2);
          if (E3 == MASSTOR_SIL) {
            E4 = E2;
          } else {
            E4 = DIPC_EVDIF(E2, E3);
          }
          MASNC_DINPTU(T, E4, F2, CS);
        }
        if (E3 != MASSTOR_SIL) {
          C1 = DIPC_DIPFMO(O, E3);
          CS = MASNC_DINPPR(T, C1, CS);
          MASNC_DINPTU(T, E2, F2, CS);
        }
        C1 = DIPC_DIPFMO(O, E1);
        C2 = DIPC_DIPFMO(O, F1);
        CS = MASNC_DINPPR(T, CS, C2);
        CS = MASNC_DINPPR(T, C1, CS);
      }
      CL = SACRN_RNPROD(AL, BL);
      CS = DIPRN_DIRPRP(CS, CL);
      C = DIPRN_DIRPSM(C, CS);
    } while (!(BP == MASSTOR_SIL));
  } while (!(AP == MASSTOR_SIL));
  return C;
}

void MASNC_DINPTL
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST EL, MASSTOR_LIST FL, MASSTOR_LIST *C, MASSTOR_LIST *EP, MASSTOR_LIST *FP)
# else
(T, EL, FL, C, EP, FP)
MASSTOR_LIST T, EL, FL;
MASSTOR_LIST *C, *EP, *FP;
# endif
{
  MASSTOR_LIST GL, GL1, GL2, O, PP, Q1, Q2, SL, TL;

  PP = T;
  *EP = MASSTOR_SIL;
  *FP = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    SACLIST_ADV3(PP, &Q1, &Q2, C, &PP);
    GL1 = DIPC_DIPEVL(Q1);
    GL2 = DIPC_DIPEVL(Q2);
    SL = DIPC_EVMT(EL, GL1);
    TL = DIPC_EVMT(FL, GL2);
    if (SL * TL == 1) {
      *EP = DIPC_EVDIF(EL, GL1);
      *FP = DIPC_EVDIF(FL, GL2);
      if (DIPC_EVSIGN(*EP) == 0) {
        *EP = MASSTOR_BETA;
      }
      if (DIPC_EVSIGN(*FP) == 0) {
        *FP = MASSTOR_BETA;
      }
      return;
    }
  }
  GL = DIPC_EVSUM(EL, FL);
  O = SACRN_RNINT(1);
  *C = DIPC_DIPFMO(O, GL);
  return;
}

void MASNC_DINPTU
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST EL, MASSTOR_LIST FL, MASSTOR_LIST C)
# else
(T, EL, FL, C)
MASSTOR_LIST T, EL, FL, C;
# endif
{
  MASSTOR_LIST C1, C2, GL1, GL2, O, PL, PP, Q1, Q2, SL, TL, TP, TS, V;

  O = SACRN_RNINT(1);
  C1 = DIPC_DIPFMO(O, EL);
  C2 = DIPC_DIPFMO(O, FL);
  if (DIPC_VALIS != MASSTOR_SIL) {
    V = DIPC_VALIS;
    MASBIOS_SWRITE("NEW RELATION = ", 15L);
    DIPRN_DIRPWR(C1, V, -1);
    MASBIOS_SWRITE(" .*. ", 5L);
    DIPRN_DIRPWR(C2, V, -1);
    MASBIOS_SWRITE(" = ", 3L);
    DIPRN_DIRPWR(C, V, -1);
    MASBIOS_BLINES(0);
  }
  TS = MASSTOR_SIL;
  PP = T;
  while (PP != MASSTOR_SIL) {
    SACLIST_ADV2(PP, &Q1, &Q2, &PP);
    PP = MASSTOR_RED(PP);
    GL1 = DIPC_DIPEVL(Q1);
    GL2 = DIPC_DIPEVL(Q2);
    SL = DIPC_EVMT(GL1, EL);
    TL = DIPC_EVMT(GL2, FL);
    if (SL * TL == 1) {
      TS = PP;
    }
  }
  if (TS == MASSTOR_SIL) {
    TS = T;
  }
  if (T == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "DINPTU empty relation table", 27L);
    return;
  }
  MASSTOR_ADV(TS, &PL, &TP);
  TP = SACLIST_COMP3(C2, C, PL, TP);
  MASSTOR_SFIRST(TS, C1);
  MASSTOR_SRED(TS, TP);
  return;
}

MASSTOR_LIST MASNC_DINPEX
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST C_104_A, MASSTOR_LIST NL)
# else
(T, C_104_A, NL)
MASSTOR_LIST T, C_104_A, NL;
# endif
{
  MASSTOR_LIST B, BL, BLP, I, RL;

  if (NL == 0) {
    RL = DIPC_DIPNOV(C_104_A);
    BLP = SACRN_RNINT(1);
    BL = DIPC_DIPFMO(BLP, MASSTOR_BETA);
    B = DIPC_DIPINV(BL, 0, RL);
    return B;
  }
  if (C_104_A == 0) {
    B = 0;
    return B;
  }
  B = C_104_A;
  {
    LONGINT B_1 = 1, B_2 = NL - 1;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        B = MASNC_DINPPR(T, B, C_104_A);
        if (I >= B_2) break;
      }
  }
  return B;
}

MASSTOR_LIST MASNC_DINLRD
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST T)
# else
(V, T)
MASSTOR_LIST V, T;
# endif
{
  MASSTOR_LIST C_103_A, AL, C, IDUM;

  C_103_A = MASSTOR_BETA;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_harmless, "DINLRD, ( expected.", 19L);
    return C_103_A;
  }
  do {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(',')) {
      C = MASBIOS_CREADB();
    }
    if (C != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      AL = MASNC_DINPRD(V, T);
      C_103_A = MASSTOR_COMP(AL, C_103_A);
    }
  } while (!(C == MASBIOS_MASORD(')')));
  C_103_A = MASSTOR_INV(C_103_A);
  return C_103_A;
}

MASSTOR_LIST MASNC_DINPRD
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST T)
# else
(V, T)
MASSTOR_LIST V, T;
# endif
{
  MASSTOR_LIST C_102_A, A1, A2, AL, AP, C, EL, ES, FL, IL, J1Y, JL, RL, VL;

  C_102_A = 0;
  C = MASBIOS_CREADB();
  if (C == 0) {
    return C_102_A;
  }
  MASBIOS_BKSP();
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD(',')) {
    MASERR_ERROR(MASERR_harmless, "DINPRD, no , expected.", 22L);
    return C_102_A;
  }
  FL = 0;
  if (C == MASBIOS_MASORD('(')) {
    C = MASBIOS_CREADB();
    FL = 1;
  }
  if (C == MASBIOS_MASORD(')')) {
    if (FL == 1) {
      return C_102_A;
    } else {
      MASERR_ERROR(MASERR_harmless, "DINLRD, no ) expected.", 22L);
      return C_102_A;
    }
  }
  RL = MASSTOR_LENGTH(V);
  ES = MASSTOR_BETA;
  {
    LONGINT B_3 = 1, B_4 = RL;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        ES = MASSTOR_COMP(0, ES);
        if (IL >= B_4) break;
      }
  }
  J1Y = SACRN_RNINT(1);
  A1 = DIPC_DIPFMO(J1Y, ES);
  AP = A1;
  for (;;) {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      if (FL == 0) {
        MASBIOS_BKSP();
      }
      return C_102_A;
    }
    if (C == MASBIOS_MASORD(',')) {
      MASBIOS_BKSP();
      return C_102_A;
    }
    if (C == MASBIOS_MASORD('-')) {
      AP = DIPRN_DIRPNG(AP);
    }
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-')) {
      C = MASBIOS_CREADB();
    }
    MASBIOS_BKSP();
    if (MASBIOS_DIGIT(C)) {
      AL = MASRN_RNDRD();
      EL = DIPC_EPREAD();
      AL = MASRN_RNEXP(AL, EL);
      AP = DIPRN_DIRPRP(AP, AL);
    } else if (C == MASBIOS_MASORD('(')) {
      AL = MASNC_DINPRD(V, T);
      EL = DIPC_EPREAD();
      AL = MASNC_DINPEX(T, AL, EL);
      AP = MASNC_DINPPR(T, AP, AL);
    } else if (MASBIOS_LETTER(C)) {
      VL = SACPOL_VREAD();
      JL = SACPOL_VLSRCH(VL, V);
      if (JL == 0) {
        MASERR_ERROR(MASERR_harmless, "DINLRD, unknown variable.", 25L);
        return C_102_A;
      }
      EL = DIPC_EPREAD();
      A2 = DIPC_DIPMPV(A1, JL, EL);
      AP = MASNC_DINPPR(T, AP, A2);
    }
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD(')') || C == MASBIOS_MASORD(',')) {
      C_102_A = DIPRN_DIRPSM(C_102_A, AP);
      AP = A1;
    }
  } EXIT_1:;
}

MASSTOR_LIST MASNC_EVZERO
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST IL, U;

  U = MASSTOR_BETA;
  {
    LONGINT B_5 = 1, B_6 = RL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        U = MASSTOR_COMP(0, U);
        if (IL >= B_6) break;
      }
  }
  return U;
}

void BEGIN_MASNC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_MASRN();
    BEGIN_DIPRN();

  }
}
