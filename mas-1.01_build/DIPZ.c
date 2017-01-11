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

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
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

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

#ifndef DEFINITION_DIPZ
#include "DIPZ.h"
#endif

CHAR DIPZ_rcsid [] = "$Id: DIPZ.md,v 1.2 1992/02/12 17:34:26 pesch Exp $";
CHAR DIPZ_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPZ.mi,v 1.3 1992/10/15 16:29:41 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPZ_DIRMPG
# ifdef __STDC__
(MASSTOR_LIST IL, MASSTOR_LIST F)
# else
(IL, F)
MASSTOR_LIST IL, F;
# endif
{
  MASSTOR_LIST C, CL, CLP, CP, CS, EINS, EL, J1Y, JL, EVOREM, EVOCOR, LL, NL, P, PL, PP, RL, RLS, TL, X, XP, YP;
  BOOLEAN ec;

  if (F == MASSTOR_SIL) {
    PP = 0;
    return PP;
  }
  J1Y = MASSTOR_FIRST(F);
  RL = DIPC_DIPNOV(J1Y);
  EINS = SACRN_RNINT(1);
  EVOREM = DIPC_EVORD;
  EVOCOR = DIPC_INVLEX;
  ec = EVOREM == EVOCOR;
  EL = MASSTOR_BETA;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (JL = B_1;; JL += 1) {
        EL = MASSTOR_COMP(0, EL);
        if (JL >= B_2) break;
      }
  }
  X = DIPC_DIPFMO(EINS, EL);
  LL = 1;
  NL = RL + LL;
  DIPC_PFDIP(X, &RLS, &P);
  P = SACPOL_PINV(RL, P, 1);
  P = DIPC_PMPV(NL, P, LL, 1);
  do {
    XP = DIPC_DIPMPV(X, IL, LL);
    LL = LL + 1;
    XP = DIPRNGB_DIRPNF(F, XP);
    if (!ec) {
      DIPC_EVORD = EVOCOR;
      DIPC_DIPBSO(XP);
    }
    DIPC_PFDIP(XP, &RLS, &YP);
    YP = SACPOL_PINV(RL, YP, LL);
    NL = RL + LL;
    YP = DIPC_PMPV(NL, YP, LL, 1);
    P = SACPOL_PINV(RL, P, 1);
    P = SACRPOL_RPSUM(NL, P, YP);
    CP = DIPC_PBCLI(RL, P);
    C = DIPC_DILFPL(LL, CP);
    CS = MASSTOR_BETA;
    while (C != MASSTOR_SIL) {
      MASSTOR_ADV(C, &CL, &C);
      CL = DIPRN_DIRPEM(CL, EINS);
      CS = MASSTOR_COMP(CL, CS);
    }
    C = MASSTOR_INV(CS);
    C = DIPRNGB_DIRLIS(C);
    TL = DIPDIM_DIGBZT(C);
    if (!ec) {
      DIPC_EVORD = EVOREM;
    }
  } while (!(TL == 0));
  LL = LL - 1;
  PP = SACPOL_PMON(EINS, LL);
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &CL, &C);
    EL = DIPC_DIPEVL(CL);
    J1Y = DIPC_EVDOV(EL);
    J1Y = MASSTOR_FIRST(J1Y);
    NL = LL - J1Y;
    J1Y = DIPC_DIPTBC(CL);
    CLP = SACRN_RNNEG(J1Y);
    PL = SACPOL_PMON(CLP, NL);
    PP = SACRPOL_RPSUM(1, PP, PL);
  }
  PP = DIPC_DIPFP(1, PP);
  return PP;
}

void BEGIN_DIPZ()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACRPOL();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_DIPDIM();

  }
}
