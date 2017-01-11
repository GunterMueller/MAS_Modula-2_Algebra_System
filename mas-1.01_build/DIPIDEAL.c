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

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_DIPIDEAL
#include "DIPIDEAL.h"
#endif

CHAR DIPIDEAL_rcsid [] = "$Id: DIPIDEAL.md,v 1.3 1993/05/11 10:53:31 kredel Exp $";
CHAR DIPIDEAL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPIDEAL.mi,v 1.4 1993/05/11 10:53:31 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPIDEAL_DIPLDV
# ifdef __STDC__
(MASSTOR_LIST C_114_A, MASSTOR_LIST V)
# else
(C_114_A, V)
MASSTOR_LIST C_114_A, V;
# endif
{
  MASSTOR_LIST AL, AP, U, VL, VP, W, WL;

  if (C_114_A == MASSTOR_SIL) {
    VP = V;
    return U;
  }
  W = DIPTOO_DIPLDM(C_114_A);
  VP = SACLIST_CINV(V);
  U = MASSTOR_BETA;
  while (VP != MASSTOR_SIL) {
    MASSTOR_ADV(VP, &VL, &VP);
    MASSTOR_ADV(W, &WL, &W);
    if (SACPOL_PDEG(WL) != 0) {
      U = MASSTOR_COMP(VL, U);
    }
  }
  return U;
}

MASSTOR_LIST DIPIDEAL_DIRLCT
# ifdef __STDC__
(MASSTOR_LIST C_113_A, MASSTOR_LIST B)
# else
(C_113_A, B)
MASSTOR_LIST C_113_A, B;
# endif
{
  MASSTOR_LIST AL, AS, BL, TL;

  if (C_113_A == MASSTOR_SIL) {
    TL = 1;
    return TL;
  }
  if (B == MASSTOR_SIL) {
    TL = 0;
    return TL;
  }
  AS = C_113_A;
  TL = 0;
  do {
    MASSTOR_ADV(AS, &AL, &AS);
    BL = DIPRNGB_DIRPNF(B, AL);
    if (BL != 0) {
      return TL;
    }
  } while (!(AS == MASSTOR_SIL));
  TL = 1;
  return TL;
}

MASSTOR_LIST DIPIDEAL_DIRLIP
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_112_A, MASSTOR_LIST B)
# else
(PL, C_112_A, B)
MASSTOR_LIST PL, C_112_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, CL;

  if (C_112_A == MASSTOR_SIL || B == MASSTOR_SIL) {
    C = MASSTOR_BETA;
    return C;
  }
  AS = C_112_A;
  BS = B;
  C = MASSTOR_BETA;
  do {
    MASSTOR_ADV(BS, &BL, &BS);
    AP = AS;
    do {
      MASSTOR_ADV(AP, &AL, &AP);
      CL = DIPRN_DIRPPR(AL, BL);
      C = MASSTOR_COMP(CL, C);
    } while (!(AP == MASSTOR_SIL));
  } while (!(BS == MASSTOR_SIL));
  if (PL != 0) {
    C = MASSTOR_COMP(PL, C);
  }
  C = DIPRNGB_DIRPGB(C, 1);
  return C;
}

MASSTOR_LIST DIPIDEAL_DIRLPI
# ifdef __STDC__
(MASSTOR_LIST C_111_A, MASSTOR_LIST P, MASSTOR_LIST VP)
# else
(C_111_A, P, VP)
MASSTOR_LIST C_111_A, P, VP;
# endif
{
  MASSTOR_LIST AL, AP, AS, EL, J1Y, PL, PP, Q, QP, QS, RL, RLP, TL;

  EL = 0;
  PP = P;
  PL = 0;
  QS = PP;
  J1Y = MASSTOR_FIRST(C_111_A);
  RL = DIPC_DIPNOV(J1Y);
  J1Y = MASSTOR_LENGTH(VP);
  RLP = J1Y - RL;
  AP = C_111_A;
  if (RLP > 0) {
    AS = MASSTOR_BETA;
    MASSTOR_ADV(PP, &PL, &PP);
    while (AP != MASSTOR_SIL) {
      MASSTOR_ADV(AP, &AL, &AP);
      AL = DIPC_DIPINV(AL, 0, RLP);
      AS = MASSTOR_COMP(AL, AS);
    }
    AP = MASSTOR_INV(AS);
  }
  do {
    Q = QS;
    EL = EL + 1;
    QS = DIPIDEAL_DIRLIP(PL, Q, PP);
    TL = DIPIDEAL_DIRLCT(AP, QS);
  } while (!(TL == 0));
  do {
    AS = SACLIST_CCONC(AP, QS);
    AS = DIPRNGB_DIRPGB(AS, 1);
    TL = DIPIDEAL_DIRLCT(Q, AS);
    if (TL != 1) {
      Q = QS;
      EL = EL + 1;
      QS = DIPIDEAL_DIRLIP(PL, Q, PP);
    }
  } while (!(TL == 1));
  QP = SACLIST_LIST4(P, EL, VP, AS);
  return QP;
}

void BEGIN_DIPIDEAL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_DIPTOO();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();

  }
}
