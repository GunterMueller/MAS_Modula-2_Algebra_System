#include "SYSTEM_.h"

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_DIPCJ
#include "DIPCJ.h"
#endif

CHAR DIPCJ_rcsid [] = "$Id: DIPCJ.md,v 1.2 1995/12/16 12:21:52 kredel Exp $";
CHAR DIPCJ_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPCJ.mi,v 1.1 1995/10/12 14:44:47 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";


MASSTOR_LIST DIPCJ_ADDTDG
# ifdef __STDC__
(MASSTOR_LIST deg, MASSTOR_LIST P)
# else
(deg, P)
MASSTOR_LIST deg, P;
# endif
{
  P = MASSTOR_COMP(deg, P);
  return P;
}

void DIPCJ_ADVTDG
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *p, MASSTOR_LIST *PP)
# else
(P, p, PP)
MASSTOR_LIST P;
MASSTOR_LIST *p, *PP;
# endif
{
  MASSTOR_ADV(P, p, PP);
}

void DIPCJ_DILEBBS
# ifdef __STDC__
(MASSTOR_LIST C_107_A)
# else
(C_107_A)
MASSTOR_LIST C_107_A;
# endif
{
  MASSTOR_LIST B, AP, ap, APP, BP, ev1, app, DUMMY, ev2;

  if (C_107_A == 0 || MASSTOR_LENGTH(C_107_A) == 1) {
    return;
  }
  B = MASSTOR_SIL;
  do {
    AP = C_107_A;
    MASSTOR_ADV(AP, &ap, &APP);
    BP = MASSTOR_SIL;
    ev1 = MASSTOR_FIRST(ap);
    while (APP != B) {
      MASSTOR_ADV(APP, &app, &DUMMY);
      ev2 = MASSTOR_FIRST(app);
      if (ev2 > 0 && (ev1 > ev2 || ev1 == 0)) {
        MASSTOR_SFIRST(AP, app);
        MASSTOR_SFIRST(APP, ap);
        BP = APP;
      } else {
        ap = app;
        ev1 = ev2;
      }
      AP = APP;
      APP = MASSTOR_RED(AP);
    }
    B = BP;
  } while (!(B == MASSTOR_SIL));
  return;
}

void DIPCJ_DILBBS
# ifdef __STDC__
(MASSTOR_LIST C_106_A)
# else
(C_106_A)
MASSTOR_LIST C_106_A;
# endif
{
  MASSTOR_LIST B, AP, ap, APP, BP, ev1, app, DUMMY, ev2;

  if (C_106_A == 0 || MASSTOR_LENGTH(C_106_A) == 1) {
    return;
  }
  B = MASSTOR_SIL;
  do {
    AP = C_106_A;
    MASSTOR_ADV(AP, &ap, &APP);
    BP = MASSTOR_SIL;
    ev1 = DIPC_EVTDEG(MASSTOR_FIRST(ap));
    while (APP != B) {
      MASSTOR_ADV(APP, &app, &DUMMY);
      ev2 = DIPC_EVTDEG(MASSTOR_FIRST(app));
      if (ev1 > ev2) {
        MASSTOR_SFIRST(AP, app);
        MASSTOR_SFIRST(APP, ap);
        BP = APP;
      } else {
        ap = app;
        ev1 = ev2;
      }
      AP = APP;
      APP = MASSTOR_RED(AP);
    }
    B = BP;
  } while (!(B == MASSTOR_SIL));
  return;
}

MASSTOR_LIST DIPCJ_DILEP2P
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST PS, p, tdg;

  PS = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    DIPCJ_ADVTDG(p, &tdg, &p);
    PS = MASSTOR_COMP(p, PS);
  }
  return PS;
}

MASSTOR_LIST DIPCJ_DILATDG
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST PP, PL, PS;

  PP = P;
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = DIPCJ_ADDTDG(DIPC_EVTDEG(MASSTOR_FIRST(PL)), PL);
    PS = MASSTOR_COMP(PL, PS);
  }
  return PS;
}

MASSTOR_LIST DIPCJ_DILTDG
# ifdef __STDC__
(MASSTOR_LIST C_105_A)
# else
(C_105_A)
MASSTOR_LIST C_105_A;
# endif
{
  MASSTOR_LIST tdg, TDG, PA, AL, EL;

  tdg = 0;
  while (C_105_A != MASSTOR_SIL) {
    MASSTOR_ADV(C_105_A, &PA, &C_105_A);
    DIPC_DIPMAD(PA, &AL, &EL, &PA);
    TDG = DIPC_EVTDEG(EL);
    if (tdg < TDG) {
      tdg = TDG;
    }
  }
  return tdg;
}

MASSTOR_LIST DIPCJ_DIPCLP
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST i, TA, TE, PP;

  i = 0;
  if (P == MASSTOR_SIL) {
    return i;
  }
  DIPC_DIPMAD(P, &TA, &TE, &PP);
  i = DIPCJ_DIPCLT(TE);
  return i;
}

MASSTOR_LIST DIPCJ_DIPCLT
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST i, PL, Q;

  i = 0;
  PL = SACLIST_CINV(P);
  if (PL == MASSTOR_SIL) {
    return i;
  }
  do {
    MASSTOR_ADV(PL, &Q, &PL);
    INC(i);
  } while (!(Q != 0 || PL == MASSTOR_SIL));
  return i;
}

void DIPCJ_DIPFIRST
# ifdef __STDC__
(MASSTOR_LIST P, BOOLEAN extended, MASSTOR_LIST *pp, MASSTOR_LIST *PP)
# else
(P, extended, pp, PP)
MASSTOR_LIST P;
BOOLEAN extended;
MASSTOR_LIST *pp, *PP;
# endif
{
  MASSTOR_ADV(P, pp, PP);
}

void DIPCJ_DIPSSM
# ifdef __STDC__
(MASSTOR_LIST P, BOOLEAN extended, MASSTOR_LIST *pp, MASSTOR_LIST *PP)
# else
(P, extended, pp, PP)
MASSTOR_LIST P;
BOOLEAN extended;
MASSTOR_LIST *pp, *PP;
# endif
{
  if (extended) {
    DIPCJ_DILEBBS(P);
  } else {
    DIPCJ_DILBBS(P);
  }
  MASSTOR_ADV(P, pp, PP);
}

MASSTOR_LIST DIPCJ_DILCAN
# ifdef __STDC__
(MASSTOR_LIST P, MASLISPU_PROCF1 F)
# else
(P, F)
MASSTOR_LIST P;
MASLISPU_PROCF1 F;
# endif
{
  MASSTOR_LIST PP, PL, PS;

  PP = P;
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = (*F)(PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  return PS;
}

MASSTOR_LIST DIPCJ_DIILPP
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST PP, PL, PS, PC;

  PP = P;
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    DIPI_DIIPCP(PL, &PC, &PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  return PS;
}

MASSTOR_LIST DIPCJ_DIRPMV
# ifdef __STDC__
(MASSTOR_LIST C_104_A, MASSTOR_LIST B)
# else
(C_104_A, B)
MASSTOR_LIST C_104_A, B;
# endif
{
  MASSTOR_LIST S, A1, AA, AE, R;

  if (C_104_A == 0 || B == 0) {
    return 0;
  }
  S = MASSTOR_SIL;
  A1 = SACLIST_CINV(C_104_A);
  do {
    DIPC_DIPMAD(A1, &AE, &AA, &A1);
    R = DIPC_EVSUM(AE, B);
    S = MASSTOR_COMP(R, MASSTOR_COMP(AA, S));
  } while (!(A1 == MASSTOR_SIL));
  return S;
}

MASSTOR_LIST DIPCJ_EVDIF2
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST W, WL, US, VS, c, UL, VL;

  W = MASSTOR_SIL;
  if (U == MASSTOR_SIL) {
    return W;
  }
  US = U;
  VS = V;
  c = 0;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = UL - VL;
    W = MASSTOR_COMP(WL, W);
    c = c + WL;
  } while (!(US == MASSTOR_SIL));
  if (c > 0) {
    W = MASSTOR_INV(W);
  } else {
    W = 0;
  }
  return W;
}

MASSTOR_LIST DIPCJ_EVMTJ
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST US, VS, UL, VL;

  if (U == MASSTOR_SIL) {
    return 1;
  }
  if (V == MASSTOR_SIL) {
    return 0;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
  } while (!(UL != VL || US == MASSTOR_SIL));
  if (VL > UL) {
    return 0;
  } else {
    if (US == MASSTOR_SIL) {
      return 1;
    }
  }
  do {
    MASSTOR_ADV(VS, &VL, &VS);
  } while (!(VL > 0 || VS == MASSTOR_SIL));
  if (VL > 0) {
    return 0;
  } else {
    return 1;
  }
}

MASSTOR_LIST DIPCJ_DIPNML
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST F, E, e, le, C_103_A, f, B;

  if (G == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  e = SACLIST_CINV(DIPC_DIPEVL(G));
  le = MASSTOR_LENGTH(e);
  C_103_A = MASSTOR_SIL;
  F = MASSTOR_SIL;
  do {
    MASSTOR_ADV(e, &f, &e);
    C_103_A = MASSTOR_COMP(0, C_103_A);
  } while (!(f != 0 || e == MASSTOR_SIL));
  while (MASSTOR_LENGTH(C_103_A) < le) {
    B = MASSTOR_COMP(1, C_103_A);
    C_103_A = MASSTOR_COMP(0, C_103_A);
    while (MASSTOR_LENGTH(B) < le) {
      B = MASSTOR_COMP(0, B);
    }
    F = MASSTOR_COMP((MASSTOR_LIST)B, F);
  }
  return F;
}

MASSTOR_LIST DIPCJ_DIPPGL2
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST V, MASSTOR_LIST LL)
# else
(F, V, LL)
MASSTOR_LIST F, V, LL;
# endif
{
  MASSTOR_LIST PP, VV, clp, vv, P, gf;

  if (F == MASSTOR_SIL || V == MASSTOR_SIL || LL == 0) {
    return F;
  }
  MASSTOR_ADV(F, &gf, &F);
  gf = gf + 1;
  PP = MASSTOR_SIL;
  VV = V;
  clp = LL - DIPCJ_DIPCLP(F);
  if (clp == 0) {
    return PP;
  }
  while (clp > 0) {
    MASSTOR_ADV(VV, &vv, &VV);
    P = DIPC_DIPEVP(F, vv);
    PP = MASSTOR_COMP((MASSTOR_LIST)MASSTOR_COMP(gf, P), PP);
    clp = clp - 1;
  }
  return PP;
}

MASSTOR_LIST DIPCJ_DIPPGL3
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST V, MASSTOR_LIST LL)
# else
(F, V, LL)
MASSTOR_LIST F, V, LL;
# endif
{
  MASSTOR_LIST PP, VV, clp, vv, P;

  if (F == MASSTOR_SIL || V == MASSTOR_SIL || LL == 0) {
    return F;
  }
  PP = MASSTOR_SIL;
  VV = V;
  clp = LL - DIPCJ_DIPCLP(F);
  if (clp == 0) {
    return PP;
  }
  while (clp > 0) {
    MASSTOR_ADV(VV, &vv, &VV);
    P = DIPC_DIPEVP(F, vv);
    PP = MASSTOR_COMP((MASSTOR_LIST)P, PP);
    clp = clp - 1;
  }
  return PP;
}

MASSTOR_LIST DIPCJ_DIPPGL
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST F, e, LL, LLA, LLB, C_102_A, f, B, P;

  if (V == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  e = SACLIST_CINV(DIPC_DIPEVL(V));
  LL = MASSTOR_LENGTH(e);
  LLA = 0;
  C_102_A = MASSTOR_SIL;
  F = MASSTOR_SIL;
  do {
    MASSTOR_ADV(e, &f, &e);
    C_102_A = MASSTOR_COMP(0, C_102_A);
    LLA = LLA + 1;
  } while (!(f != 0 || e == NIL));
  while (LLA < LL) {
    B = MASSTOR_COMP(1, C_102_A);
    C_102_A = MASSTOR_COMP(0, C_102_A);
    LLA = LLA + 1;
    LLB = LLA;
    while (LLB < LL) {
      B = MASSTOR_COMP(0, B);
      LLB = LLB + 1;
    }
    P = DIPC_DIPEVP(V, B);
    F = MASSTOR_COMP((MASSTOR_LIST)P, F);
  }
  return F;
}

MASSTOR_LIST DIPCJ_DIPVL
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST C_101_A, F, LL, B, i;

  if (V == MASSTOR_SIL || MASSTOR_LENGTH(V) == 0) {
    return MASSTOR_SIL;
  }
  C_101_A = MASSTOR_LIST1(0);
  F = MASSTOR_SIL;
  LL = MASSTOR_LENGTH(DIPC_DIPEVL(V)) - 1;
  while (LL > 0) {
    LL = LL - 1;
    B = MASSTOR_COMP(1, C_101_A);
    {
      LONGINT B_1 = 1, B_2 = LL;

      if (B_1 <= B_2)
        for (i = B_1;; i += 1) {
          B = MASSTOR_COMP(0, B);
          if (i >= B_2) break;
        }
    }
    F = MASSTOR_COMP((MASSTOR_LIST)B, F);
    C_101_A = MASSTOR_COMP(0, C_101_A);
  }
  return F;
}

void BEGIN_DIPCJ()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASLISPU();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
