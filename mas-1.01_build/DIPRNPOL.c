#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
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

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_DIPRNPOL
#include "DIPRNPOL.h"
#endif

CHAR DIPRNPOL_rcsid [] = "$Id: DIPRNPOL.md,v 1.3 1992/06/12 13:36:28 kredel Exp $";
CHAR DIPRNPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPRNPOL.mi,v 1.4 1992/10/15 16:28:38 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPRNPOL_RPABS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_97_A)
# else
(RL, C_97_A)
MASSTOR_LIST RL, C_97_A;
# endif
{
  MASSTOR_LIST B, SL;

  SL = DIPRNPOL_RPSIGN(RL, C_97_A);
  if (SL >= 0) {
    B = C_97_A;
  } else {
    B = SACRPOL_RPNEG(RL, C_97_A);
  }
  return B;
}

MASSTOR_LIST DIPRNPOL_RPCONST
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_96_A)
# else
(RL, C_96_A)
MASSTOR_LIST RL, C_96_A;
# endif
{
  MASSTOR_LIST IL, AL, TL;

  TL = 0;
  if (C_96_A == 0) {
    return TL;
  }
  AL = C_96_A;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        if (SACPOL_PDEG(AL) != 0) {
          return TL;
        }
        AL = SACPOL_PLDCF(AL);
        if (IL >= B_2) break;
      }
  }
  TL = 1;
  return TL;
}

MASSTOR_LIST DIPRNPOL_RPEXP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_95_A, MASSTOR_LIST NL)
# else
(RL, C_95_A, NL)
MASSTOR_LIST RL, C_95_A, NL;
# endif
{
  MASSTOR_LIST B, IL;

  if (NL == 0) {
    B = SACPOL_PINV(0, SACRN_RNINT(1), RL);
    return B;
  }
  if (C_95_A == 0) {
    B = 0;
    return B;
  }
  B = C_95_A;
  {
    LONGINT B_3 = 1, B_4 = NL - 1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        B = SACRPOL_RPPROD(RL, B, C_95_A);
        if (IL >= B_4) break;
      }
  }
  return B;
}

MASSTOR_LIST DIPRNPOL_RPMON
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_94_A)
# else
(RL, C_94_A)
MASSTOR_LIST RL, C_94_A;
# endif
{
  MASSTOR_LIST AL, ALP, AP;

  if (C_94_A == 0) {
    AP = 0;
    return AP;
  }
  AL = SACPOL_PLBCF(RL, C_94_A);
  ALP = SACRN_RNINV(AL);
  AP = SACRPOL_RPRNP(RL, ALP, C_94_A);
  return AP;
}

MASSTOR_LIST DIPRNPOL_RPONE
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_93_A)
# else
(RL, C_93_A)
MASSTOR_LIST RL, C_93_A;
# endif
{
  MASSTOR_LIST IL, AL, TL;

  TL = 0;
  if (C_93_A == 0) {
    return TL;
  }
  AL = C_93_A;
  {
    LONGINT B_5 = 1, B_6 = RL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        if (SACPOL_PDEG(AL) != 0) {
          return TL;
        }
        AL = SACPOL_PLDCF(AL);
        if (IL >= B_6) break;
      }
  }
  TL = MASRN_RNONE(AL);
  return TL;
}

MASSTOR_LIST DIPRNPOL_RPSIGN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_92_A)
# else
(RL, C_92_A)
MASSTOR_LIST RL, C_92_A;
# endif
{
  MASSTOR_LIST J1Y, SL;

  J1Y = SACPOL_PLBCF(RL, C_92_A);
  SL = SACRN_RNSIGN(J1Y);
  return SL;
}

void DIPRNPOL_RPLWRS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_91_A, MASSTOR_LIST V, MASSTOR_LIST S)
# else
(RL, C_91_A, V, S)
MASSTOR_LIST RL, C_91_A, V, S;
# endif
{
  MASSTOR_LIST AL, AP, LS, RS, OS;

  MASBIOS_BLINES(1);
  LS = 10;
  RS = 60;
  OS = -1;
  MASBIOS_SOLINE(&OS, &LS, &RS);
  MASBIOS_BLINES(1);
  AP = C_91_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPRNPOL_RPWRTS(RL, AL, V, S);
    MASBIOS_BLINES(2);
  }
  MASBIOS_SOLINE(&OS, &LS, &RS);
  MASBIOS_BLINES(1);
  return;
}

void DIPRNPOL_RPWRTS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_90_A, MASSTOR_LIST V, MASSTOR_LIST S)
# else
(RL, C_90_A, V, S)
MASSTOR_LIST RL, C_90_A, V, S;
# endif
{
  MASSTOR_LIST AL, AP, EL, IL, LL, RLP, V1, VB, VP;

  if (RL == 0 || C_90_A == 0) {
    SACI_IWRITE(C_90_A);
    return;
  }
  AP = C_90_A;
  RLP = RL - 1;
  VB = SACLIST_CINV(V);
  LL = MASSTOR_LENGTH(AP);
  if (LL > 2) {
    MASBIOS_SWRITE("(", 1L);
  }
  MASSTOR_ADV(VB, &V1, &VP);
  VP = MASSTOR_INV(VP);
  IL = 0;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL != 0) {
      if (RL > 1) {
        MASBIOS_SWRITE("+", 1L);
      } else {
        if (SACRN_RNSIGN(AL) > 0) {
          MASBIOS_SWRITE("+", 1L);
        }
      }
    }
    if (RLP == 0) {
      if (S < 0) {
        SACRN_RNWRIT(AL);
      } else {
        MASRN_RNDWR(AL, S);
      }
    } else {
      DIPRNPOL_RPWRTS(RLP, AL, VP, S);
    }
    if (EL > 0) {
      MASBIOS_SWRITE("*", 1L);
      SACLIST_CLOUT(V1);
      if (EL > 1) {
        MASBIOS_SWRITE("*", 1L);
        MASBIOS_SWRITE("*", 1L);
        SACI_IWRITE(EL);
      }
    }
    IL = 1;
  } while (!(AP == MASSTOR_SIL));
  if (LL > 2) {
    MASBIOS_SWRITE(")", 1L);
  }
  return;
}

void DIPRNPOL_RUPEGC
# ifdef __STDC__
(MASSTOR_LIST C_89_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *U, MASSTOR_LIST *V)
# else
(C_89_A, B, C, U, V)
MASSTOR_LIST C_89_A, B;
MASSTOR_LIST *C, *U, *V;
# endif
{
  MASSTOR_LIST D, RP;

  DIPRNPOL_RUPHEG(C_89_A, B, C, V);
  if (C_89_A == 0) {
    *U = 0;
  } else {
    D = SACRPOL_RPPROD(1, B, *V);
    D = SACRPOL_RPDIF(1, *C, D);
    SACRPOL_RPQR(1, D, C_89_A, U, &RP);
  }
  return;
}

MASSTOR_LIST DIPRNPOL_RUPGCD
# ifdef __STDC__
(MASSTOR_LIST C_88_A, MASSTOR_LIST B)
# else
(C_88_A, B)
MASSTOR_LIST C_88_A, B;
# endif
{
  MASSTOR_LIST Q, A1, A2, A3, C, ML, NL;

  if (C_88_A == 0) {
    C = DIPRNPOL_RPMON(1, B);
    return C;
  }
  if (B == 0) {
    C = DIPRNPOL_RPMON(1, C_88_A);
    return C;
  }
  ML = SACPOL_PDEG(C_88_A);
  NL = SACPOL_PDEG(B);
  if (ML >= NL) {
    A1 = C_88_A;
    A2 = B;
  } else {
    A1 = B;
    A2 = C_88_A;
  }
  do {
    SACRPOL_RPQR(1, A1, A2, &Q, &A3);
    A1 = A2;
    A2 = A3;
  } while (!(A2 == 0));
  C = DIPRNPOL_RPMON(1, A1);
  return C;
}

void DIPRNPOL_RUPHEG
# ifdef __STDC__
(MASSTOR_LIST C_87_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *V)
# else
(C_87_A, B, C, V)
MASSTOR_LIST C_87_A, B;
MASSTOR_LIST *C, *V;
# endif
{
  MASSTOR_LIST A1, A2, A3, AL, ALP, J1Y, Q, V1, V2, V3;

  V1 = 0;
  V2 = SACPOL_PINV(0, SACRN_RNINT(1), 1);
  A1 = C_87_A;
  A2 = B;
  while (A2 != 0) {
    SACRPOL_RPQR(1, A1, A2, &Q, &A3);
    J1Y = SACRPOL_RPPROD(1, Q, V2);
    V3 = SACRPOL_RPDIF(1, V1, J1Y);
    A1 = A2;
    A2 = A3;
    V1 = V2;
    V2 = V3;
  }
  if (A1 == 0) {
    *C = 0;
    *V = 0;
    return;
  }
  AL = SACPOL_PLDCF(A1);
  ALP = SACRN_RNINV(AL);
  *C = SACRPOL_RPRNP(1, ALP, A1);
  *V = SACRPOL_RPRNP(1, ALP, V1);
  return;
}

MASSTOR_LIST DIPRNPOL_RUPLCM
# ifdef __STDC__
(MASSTOR_LIST C_86_A, MASSTOR_LIST B)
# else
(C_86_A, B)
MASSTOR_LIST C_86_A, B;
# endif
{
  MASSTOR_LIST AP, APP, BP, N, C, CP;

  AP = DIPRNPOL_RPABS(1, C_86_A);
  BP = DIPRNPOL_RPABS(1, B);
  if (AP == 0) {
    C = BP;
    return C;
  }
  if (BP == 0) {
    C = AP;
    return C;
  }
  CP = DIPRNPOL_RUPGCD(AP, BP);
  SACRPOL_RPQR(1, AP, CP, &APP, &N);
  C = SACRPOL_RPPROD(1, APP, BP);
  return C;
}

void BEGIN_DIPRNPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_SACPOL();
    BEGIN_SACRPOL();

  }
}
