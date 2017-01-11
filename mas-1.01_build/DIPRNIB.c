#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPCJ
#include "DIPCJ.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPRNIB
#include "DIPRNIB.h"
#endif

CHAR DIPRNIB_rcsid [] = "$Id: DIPRNIB.md,v 1.1 1995/10/12 14:44:59 pesch Exp $";
CHAR DIPRNIB_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPRNIB.mi,v 1.1 1995/10/12 14:45:00 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";


MASSTOR_LIST DIPRNIB_DIRPNFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S)
# else
(P, S)
MASSTOR_LIST P, S;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = MASSTOR_SIL;
  SP = S;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPCJ_EVMTJ(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = SACRN_RNQ(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPRN_DIRPPR(QP, AP);
        SP = DIPRN_DIRPDF(SP, APP);
      }
    }
  } while (!(SP == 0));
  if (R == MASSTOR_SIL) {
    R = 0;
  } else {
    R = MASSTOR_INV(R);
  }
  return R;
}

MASSTOR_LIST DIPRNIB_DIRLISJ
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EL, FL, IRR, LL, PL, PP, PS, RL, RP, SL;

  PP = P;
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = DIPRN_DIRPMC(PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  if (LL <= 1) {
    return PP;
  }
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPRNIB_DIRPNFJ(PP, PL);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_1;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_1;
      }
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        PL = DIPRN_DIRPMC(PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_1;
    }
  } EXIT_1:;
  MASBIOS_BLINES(0);
  return PP;
}

MASSTOR_LIST DIPRNIB_DIRPCOM
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, EL;
  BOOLEAN FLAG;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  G = DIPRNIB_DIRLISJ(F);
  do {
    H = G;
    TDG = DIPCJ_DILTDG(H);
    FLAG = TRUE;
    while (H != MASSTOR_SIL && FLAG) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPNML(h);
      while (NM != MASSTOR_SIL && FLAG) {
        MASSTOR_ADV(NM, &nm, &NM);
        p = DIPCJ_DIRPMV(h, nm);
        if (DIPCJ_DILTDG(MASSTOR_COMP(p, EL)) <= TDG) {
          f = DIPRNIB_DIRPNFJ(G, p);
          if (f != 0) {
            G = DIPRNIB_DIRLISJ(MASSTOR_COMP(f, G));
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPRNIB_DIRPIB2
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, EL;
  BOOLEAN FLAG;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  G = DIPRNIB_DIRPCOM(F);
  do {
    H = G;
    TDG = DIPCJ_DILTDG(H);
    FLAG = TRUE;
    while (H != MASSTOR_SIL && FLAG) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPNML(h);
      while (NM != MASSTOR_SIL && FLAG) {
        MASSTOR_ADV(NM, &nm, &NM);
        p = DIPCJ_DIRPMV(h, nm);
        if (DIPCJ_DILTDG(MASSTOR_COMP(p, EL)) > TDG) {
          f = DIPRNIB_DIRPNFJ(G, p);
          if (f != 0) {
            G = DIPRNIB_DIRPCOM(MASSTOR_COMP(f, G));
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPRNIB_DIRPIB
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, H, h, NM, nm, f, T;

  T = MASSTOR_TIME();
  G = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    G = DIPRNIB_DIRLISJ(SACLIST_CONC(G, F));
    F = MASSTOR_SIL;
    H = G;
    while (H != MASSTOR_SIL) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPNML(h);
      while (NM != MASSTOR_SIL) {
        MASSTOR_ADV(NM, &nm, &NM);
        f = DIPRNIB_DIRPNFJ(G, DIPCJ_DIRPMV(h, nm));
        if (f != 0) {
          F = MASSTOR_COMP(f, F);
        }
      }
    }
  }
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(MASSTOR_TIME() - T);
  MASBIOS_SWRITE(" ms ", 4L);
  return G;
}

void BEGIN_DIPRNIB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPCJ();
    BEGIN_DIPRN();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACRN();

  }
}
