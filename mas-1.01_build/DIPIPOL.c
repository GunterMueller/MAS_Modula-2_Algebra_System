#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_DIPIPOL
#include "DIPIPOL.h"
#endif

CHAR DIPIPOL_rcsid [] = "$Id: DIPIPOL.md,v 1.2 1992/02/12 17:33:50 pesch Exp $";
CHAR DIPIPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPIPOL.mi,v 1.3 1992/10/15 16:28:36 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPIPOL_VIPIIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_86_A, MASSTOR_LIST B)
# else
(RL, C_86_A, B)
MASSTOR_LIST RL, C_86_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, C;

  C = 0;
  if (C_86_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    return C;
  }
  AP = C_86_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    CL = SACIPOL_IPIP(RL, BL, AL);
    C = SACIPOL_IPSUM(RL, C, CL);
  } while (!(AP == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST DIPIPOL_HIPRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST NL)
# else
(RL, KL, QL, NL)
MASSTOR_LIST RL, KL, QL, NL;
# endif
{
  MASSTOR_LIST C_85_A, AL, DL, EL, J1Y, QL1, QL2, QLS, RLP, TL;

  if (RL > 1) {
    RLP = RL - 1;
    C_85_A = MASSTOR_BETA;
    EL = 0;
    while (EL <= NL) {
      J1Y = NL - EL;
      AL = DIPIPOL_HIPRAN(RLP, KL, QL, J1Y);
      if (AL != 0) {
        C_85_A = SACLIST_COMP2(EL, AL, C_85_A);
      }
      EL = EL + 1;
    }
    if (C_85_A == MASSTOR_SIL) {
      C_85_A = 0;
    }
    return C_85_A;
  }
  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLS, &TL);
  C_85_A = 0;
  AL = 0;
  DL = SACD_DRANN();
  if (DL < QLS) {
    AL = SACI_IRAND(KL);
  }
  if (AL == 0) {
    return C_85_A;
  }
  if (RL == 0) {
    C_85_A = AL;
  } else {
    C_85_A = SACLIST_LIST2(NL, AL);
  }
  return C_85_A;
}

MASSTOR_LIST DIPIPOL_IPRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST N)
# else
(RL, KL, QL, N)
MASSTOR_LIST RL, KL, QL, N;
# endif
{
  MASSTOR_LIST C_84_A, AL, DL, EL, NL, NP, QL1, QL2, QLS, RLP, TL;

  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLS, &TL);
  if (RL == 0) {
    DL = SACD_DRANN();
    if (DL < QLS) {
      C_84_A = SACI_IRAND(KL);
    } else {
      C_84_A = 0;
    }
    return C_84_A;
  }
  RLP = RL - 1;
  MASSTOR_ADV(N, &NL, &NP);
  C_84_A = MASSTOR_BETA;
  EL = 0;
  while (EL <= NL) {
    if (RLP == 0) {
      DL = SACD_DRANN();
      if (DL < QLS) {
        AL = SACI_IRAND(KL);
      } else {
        AL = 0;
      }
    } else {
      AL = DIPIPOL_IPRAN(RLP, KL, QL, NP);
    }
    if (AL != 0) {
      C_84_A = SACLIST_COMP2(EL, AL, C_84_A);
    }
    EL = EL + 1;
  }
  if (C_84_A == MASSTOR_SIL) {
    C_84_A = 0;
  }
  return C_84_A;
}

void BEGIN_DIPIPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACIPOL();

  }
}
