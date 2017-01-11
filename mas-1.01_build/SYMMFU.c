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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_SYMMFU
#include "SYMMFU.h"
#endif

CHAR SYMMFU_rcsid [] = "$Id: SYMMFU.md,v 1.3 1992/10/16 13:58:12 kredel Exp $";
CHAR SYMMFU_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SYMMFU.mi,v 1.3 1992/10/15 16:29:19 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST EVZERO ARGS((MASSTOR_LIST RL));


void SYMMFU_DIRPSR
# ifdef __STDC__
(MASSTOR_LIST Q, MASSTOR_LIST PL, MASSTOR_LIST *P1, MASSTOR_LIST *P2)
# else
(Q, PL, P1, P2)
MASSTOR_LIST Q, PL;
MASSTOR_LIST *P1, *P2;
# endif
{
  MASSTOR_LIST FL, P3, P4, TA, TE, TL, X;

  *P1 = 0;
  *P2 = PL;
  if (*P2 == 0) {
    return;
  }
  P3 = MASSTOR_SIL;
  *P1 = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(*P2, &TA, &TE, P2);
    if (*P2 == MASSTOR_SIL) {
      *P2 = 0;
    }
    TL = SYMMFU_EVASC(TE);
    if (TL == 1) {
      SYMMFU_DIRPSE(Q, TE, &P4, &FL);
      P4 = DIPRN_DIRPRP(P4, TA);
      P4 = DIPC_DIPMRD(P4);
      if (P4 != MASSTOR_SIL) {
        *P2 = DIPRN_DIRPDF(*P2, P4);
      }
      *P1 = DIPC_DIPMCP(FL, TA, *P1);
    } else {
      P3 = DIPC_DIPMCP(TE, TA, P3);
    }
  } while (!(*P2 == 0));
  if (P3 == MASSTOR_SIL) {
    *P2 = 0;
  } else {
    *P2 = MASSTOR_INV(P3);
  }
  if (*P1 == MASSTOR_SIL) {
    *P1 = 0;
  } else {
    *P1 = MASSTOR_INV(*P1);
  }
  return;
}

void SYMMFU_DIRPSE
# ifdef __STDC__
(MASSTOR_LIST Q, MASSTOR_LIST U, MASSTOR_LIST *PL, MASSTOR_LIST *V)
# else
(Q, U, PL, V)
MASSTOR_LIST Q, U;
MASSTOR_LIST *PL, *V;
# endif
{
  MASSTOR_LIST E, EL1, ELS, O, QL, QP, RL, SL, UP, X;

  *V = MASSTOR_SIL;
  RL = MASSTOR_LENGTH(U);
  E = EVZERO(RL);
  O = SACRN_RNINT(1);
  *PL = DIPC_DIPFMO(O, E);
  if (U == MASSTOR_SIL) {
    return;
  }
  UP = U;
  QP = Q;
  SL = 0;
  do {
    MASSTOR_ADV(QP, &QL, &QP);
    MASSTOR_ADV(UP, &EL1, &UP);
    if (EL1 > SL) {
      ELS = EL1 - SL;
      SL = EL1;
      *V = MASSTOR_COMP(ELS, *V);
      QL = DIPRN_DIRPEX(QL, ELS);
      *PL = DIPRN_DIRPPR(*PL, QL);
    } else {
      *V = MASSTOR_COMP(0, *V);
    }
  } while (!(UP == MASSTOR_SIL));
  *V = MASSTOR_INV(*V);
  return;
}

MASSTOR_LIST SYMMFU_DIRPES
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST E, EL, FL, GL, IL, J1Y, O, C_81_ORD, P, PL, Q, T, TL, X, XL;

  Q = MASSTOR_SIL;
  if (RL < 1) {
    return Q;
  }
  J1Y = RL + 1;
  E = EVZERO(J1Y);
  O = SACRN_RNRED(1, 1);
  DIPC_EVCADD(E, 1, 1, &TL, &XL);
  T = DIPC_DIPFMO(O, TL);
  P = DIPC_DIPFMO(O, E);
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        DIPC_EVCADD(E, IL + 1, 1, &EL, &XL);
        PL = DIPC_DIPFMO(O, EL);
        PL = DIPRN_DIRPDF(PL, T);
        P = DIPRN_DIRPPR(P, PL);
        if (IL >= B_2) break;
      }
  }
  do {
    DIPC_DIPADM(P, &FL, &GL, &PL, &P);
    PL = DIPRN_DIRPAB(PL);
    DIPC_DIPBSO(PL);
    Q = MASSTOR_COMP(PL, Q);
  } while (!(P == 0));
  Q = MASSTOR_INV(Q);
  Q = MASSTOR_RED(Q);
  Q = MASSTOR_INV(Q);
  return Q;
}

MASSTOR_LIST SYMMFU_EVASC
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST EL, FL, TL, UP;

  TL = 0;
  if (U == MASSTOR_SIL) {
    return TL;
  }
  MASSTOR_ADV(U, &EL, &UP);
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &FL, &UP);
    if (EL > FL) {
      return TL;
    }
    EL = FL;
  }
  TL = 1;
  return TL;
}

static MASSTOR_LIST EVZERO
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST IL, U;

  U = MASSTOR_SIL;
  {
    LONGINT B_3 = 1, B_4 = RL;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        U = MASSTOR_COMP(0, U);
        if (IL >= B_4) break;
      }
  }
  return U;
}

void BEGIN_SYMMFU()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPRN();

  }
}
