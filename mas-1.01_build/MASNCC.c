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

#ifndef DEFINITION_SACSET
#include "SACSET.h"
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

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_MASNCGB
#include "MASNCGB.h"
#endif

#ifndef DEFINITION_MASNCC
#include "MASNCC.h"
#endif

CHAR MASNCC_rcsid [] = "$Id: MASNCC.md,v 1.2 1992/02/12 17:33:31 pesch Exp $";
CHAR MASNCC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASNCC.mi,v 1.3 1992/10/15 16:29:47 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASNCC_DINCCO
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST C_132_A, MASSTOR_LIST B)
# else
(T, C_132_A, B)
MASSTOR_LIST T, C_132_A, B;
# endif
{
  MASSTOR_LIST C, C1, C2;

  C1 = MASNC_DINPPR(T, C_132_A, B);
  C2 = MASNC_DINPPR(T, B, C_132_A);
  C = DIPRN_DIRPDF(C1, C2);
  return C;
}

MASSTOR_LIST MASNCC_DINCCP
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST E)
# else
(T, E)
MASSTOR_LIST T, E;
# endif
{
  MASSTOR_LIST C, CL, CP, EINS, V, EVOREM, EVOCOR, ES, EP, EH, EB, e, ep, f, l, n, m, a, P, PP, PE, p, pp, r, r1, r2, rp, X, Y, Z;
  BOOLEAN ec;

  PP = 0;
  if (E == MASSTOR_SIL) {
    return PP;
  }
  EVOREM = DIPC_EVORD;
  EVOCOR = DIPC_INVLEX;
  ec = EVOREM == EVOCOR;
  e = MASSTOR_FIRST(E);
  r = MASSTOR_LENGTH(e);
  EINS = SACRN_RNINT(1);
  if (r == 0) {
    PP = DIPC_DIPFMO(EINS, MASSTOR_COMP(1, e));
    return PP;
  }
  EP = MASNCC_EVLGTD(r, 1, MASSTOR_SIL);
  EP = SACLIST_SECOND(EP);
  PE = MASNCC_DILFEL(EINS, EP);
  PE = MASSTOR_INV(PE);
  EH = MASNCC_DILFEL(EINS, E);
  EH = DIPC_DIPLPM(EH);
  EP = PE;
  C = MASSTOR_SIL;
  while (EP != MASSTOR_SIL) {
    MASSTOR_ADV(EP, &Z, &EP);
    P = 0;
    l = 0;
    n = r;
    ES = EH;
    MASBIOS_SWRITE("commutators with: ", 18L);
    DIPRN_DIRPWR(Z, DIPC_VALIS, -1);
    MASBIOS_BLINES(0);
    do {
      MASSTOR_ADV(ES, &X, &ES);
      P = SACPOL_PINV(r, P, 1);
      l = l + 1;
      n = r + l;
      Y = MASNCC_DINCCO(T, X, Z);
      if (Y != 0) {
        if (!ec) {
          DIPC_EVORD = EVOCOR;
          DIPC_DIPBSO(Y);
          DIPC_EVORD = EVOREM;
        }
        DIPC_PFDIP(Y, &rp, &Y);
        Y = SACPOL_PINV(r, Y, l);
        Y = DIPC_PMPV(n, Y, l, 1);
        P = SACRPOL_RPSUM(n, P, Y);
      }
    } while (!(ES == MASSTOR_SIL));
    CP = DIPC_PBCLI(r, P);
    CP = DIPC_DILFPL(l, CP);
    MASBIOS_SWRITE("added coefficient system: ", 26L);
    MASBIOS_BLINES(0);
    V = DIPC_STVL(l);
    DIPRN_DIRLWR(CP, V, -1);
    MASBIOS_BLINES(1);
    C = SACLIST_CCONC(CP, C);
    C = DIPRNGB_DIRLIS(C);
  }
  if (!ec) {
    DIPC_EVORD = EVOCOR;
  }
  C = DIPC_DIPLPM(C);
  if (!ec) {
    DIPC_EVORD = EVOREM;
  }
  MASBIOS_SWRITE("Coefficient system: ", 20L);
  MASBIOS_BLINES(0);
  V = DIPC_STVL(l);
  DIPRN_DIRLWR(C, V, -1);
  MASBIOS_BLINES(1);
  PP = 0;
  r1 = MASSTOR_LENGTH(EH);
  r2 = MASSTOR_LENGTH(C);
  rp = r1 - r2;
  if (rp > 0) {
    EB = MASNCC_EVLGTD(rp, 1, MASSTOR_SIL);
    EB = SACLIST_SECOND(EB);
  } else {
    EB = MASSTOR_SIL;
  }
  ES = MASNCC_EVLINV(EB, 0, r);
  ES = MASSTOR_INV(ES);
  m = 0;
  EP = MASSTOR_SIL;
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &CL, &C);
    m = m + 1;
    DIPC_DIPMAD(CL, &a, &f, &CL);
    e = DIPC_EVDOV(f);
    n = l - MASSTOR_FIRST(e) + 1;
    e = SACLIST_LELT(EH, n);
    e = DIPC_DIPEVL(e);
    e = MASNCC_EVINV(e, r, rp);
    p = DIPC_DIPFMO(a, e);
    EP = MASSTOR_INV(EP);
    while (m < n) {
      MASSTOR_ADV(ES, &ep, &ES);
      EP = MASSTOR_COMP(ep, EP);
      e = SACLIST_LELT(EH, m);
      e = DIPC_DIPEVL(e);
      e = MASNCC_EVINV(e, r, rp);
      e = DIPC_EVSUM(e, ep);
      pp = DIPC_DIPFMO(EINS, e);
      PP = DIPRN_DIRPSM(PP, pp);
      m = m + 1;
    }
    EP = MASSTOR_COMP(4711, EP);
    EP = MASSTOR_INV(EP);
    pp = MASSTOR_SIL;
    while (CL != MASSTOR_SIL) {
      DIPC_DIPMAD(CL, &a, &f, &CL);
      a = SACRN_RNNEG(a);
      e = DIPC_EVDOV(f);
      n = l - MASSTOR_FIRST(e) + 1;
      e = SACLIST_LELT(EP, n);
      pp = DIPC_DIPMCP(e, a, pp);
    }
    pp = MASSTOR_INV(pp);
    if (pp != MASSTOR_SIL) {
      pp = DIPRN_DIRPPR(p, pp);
      PP = DIPRN_DIRPSM(PP, pp);
    }
  }
  EP = MASSTOR_INV(EP);
  while (ES != MASSTOR_SIL) {
    MASSTOR_ADV(ES, &ep, &ES);
    EP = MASSTOR_COMP(ep, EP);
    e = SACLIST_LELT(EH, m);
    e = DIPC_DIPEVL(e);
    e = MASNCC_EVINV(e, r, rp);
    e = DIPC_EVSUM(e, ep);
    pp = DIPC_DIPFMO(EINS, e);
    PP = DIPRN_DIRPSM(PP, pp);
    m = m + 1;
  }
  EP = MASSTOR_INV(EP);
  return PP;
}

MASSTOR_LIST MASNCC_DINCCPpre
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST E)
# else
(T, E)
MASSTOR_LIST T, E;
# endif
{
  MASSTOR_LIST TP, pl, pr, pp, e, N, NP, C, Z, V, F, FP, FS, ES, EP, P, PP, PE, Q, QP, n, r, rp, one;

  PP = 0;
  if (E == MASSTOR_SIL) {
    return PP;
  }
  r = MASSTOR_LENGTH(MASSTOR_FIRST(E));
  EP = E;
  PE = MASNCC_EVLGTD(r, 2, MASSTOR_SIL);
  TP = T;
  FP = MASSTOR_SIL;
  while (TP != MASSTOR_SIL) {
    SACLIST_ADV3(TP, &pl, &pr, &pp, &TP);
    if (DIPC_DIPMRD(pp) != 0) {
      N = DIPC_EVLCM(DIPC_DIPEVL(pl), DIPC_DIPEVL(pr));
      FP = MASSTOR_COMP(N, FP);
    }
  }
  MASBIOS_SWRITE("FP: ", 4L);
  SACLIST_OWRITE(FP);
  MASBIOS_BLINES(0);
  FS = SACLIST_SECOND(PE);
  while (FS != MASSTOR_SIL) {
    MASSTOR_ADV(FS, &N, &FS);
    N = DIPC_EVSUM(N, N);
    FP = MASSTOR_COMP(N, FP);
  }
  F = SACLIST_THIRD(PE);
  F = SACSET_USDIFF(F, FP);
  MASBIOS_SWRITE("F: ", 3L);
  SACLIST_OWRITE(F);
  MASBIOS_BLINES(0);
  EP = E;
  PP = MASNCC_DINCCP(T, EP);
  if (PP == 0) {
    return PP;
  }
  rp = DIPC_DIPNOV(PP) - r;
  V = DIPC_STVL(rp);
  MASBIOS_SWRITE("Parameters: ", 12L);
  SACPOL_VLWRIT(V);
  MASBIOS_BLINES(1);
  V = SACLIST_CONC(V, DIPC_VALIS);
  MASBIOS_SWRITE("Center polynomial: ", 19L);
  MASBIOS_BLINES(0);
  DIPRN_DIRPWR(PP, V, -1);
  MASBIOS_BLINES(1);
  one = SACRN_RNINT(1);
  EP = MASNCC_EVLGTD(rp, 1, MASSTOR_SIL);
  EP = SACLIST_SECOND(EP);
  QP = MASSTOR_SIL;
  while (EP != MASSTOR_SIL) {
    MASSTOR_ADV(EP, &ES, &EP);
    P = PP;
    n = rp;
    while (ES != MASSTOR_SIL) {
      MASSTOR_ADV(ES, &e, &ES);
      if (e == 1) {
        P = DIPRN_DIRPEV(P, n, one);
      } else {
        P = DIPRN_DIRPEV(P, n, 0);
      }
      n = n - 1;
    }
    QP = MASSTOR_COMP(P, QP);
  }
  QP = MASSTOR_INV(QP);
  P = QP;
  MASBIOS_SWRITE("Specialized center polynomials: ", 32L);
  MASBIOS_BLINES(0);
  DIPRN_DIRLWR(P, DIPC_VALIS, -1);
  MASBIOS_BLINES(1);
  EP = MASNCC_EVLGTD(r, 1, MASSTOR_SIL);
  EP = SACLIST_SECOND(EP);
  EP = MASSTOR_INV(EP);
  EP = MASNCC_DILFEL(one, EP);
  while (EP != MASSTOR_SIL) {
    MASSTOR_ADV(EP, &Z, &EP);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &Q, &QP);
      C = MASNCC_DINCCO(T, Q, Z);
      if (C != 0) {
        MASBIOS_SWRITE("Commutator with: ", 17L);
        DIPRN_DIRPWR(Q, DIPC_VALIS, -1);
        MASBIOS_BLINES(0);
        DIPRN_DIRPWR(Z, DIPC_VALIS, -1);
        MASBIOS_BLINES(0);
        DIPRN_DIRPWR(C, DIPC_VALIS, -1);
        MASBIOS_BLINES(1);
      }
    }
  }
  return P;
}

MASSTOR_LIST MASNCC_DILFEL
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST E)
# else
(a, E)
MASSTOR_LIST a, E;
# endif
{
  MASSTOR_LIST EP, P, p, ep;

  P = MASSTOR_SIL;
  if (a == 0 || E == MASSTOR_SIL) {
    return P;
  }
  EP = E;
  while (EP != MASSTOR_SIL) {
    MASSTOR_ADV(EP, &ep, &EP);
    p = DIPC_DIPFMO(a, ep);
    P = MASSTOR_COMP(p, P);
  }
  P = MASSTOR_INV(P);
  return P;
}

BOOLEAN MASNCC_DINPTslT
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST g, g1, g2, e1, e2, C, P, Q1, Q2;
  BOOLEAN t;

  P = T;
  if (P == MASSTOR_SIL) {
    return TRUE;
  }
  do {
    SACLIST_ADV3(P, &Q1, &Q2, &C, &P);
    g = DIPC_DIPLBC(C);
    if (MASRN_RNONE(g) != 1) {
      return FALSE;
    }
    C = DIPC_DIPMRD(C);
    g1 = DIPTOO_DIPDEV(C);
    e1 = DIPC_EVDOV(g1);
    if (e1 == MASSTOR_SIL) {
      e1 = 0;
    } else {
      e1 = MASSTOR_FIRST(e1);
    }
    g2 = DIPC_DIPEVL(Q1);
    e2 = DIPC_EVDOV(g2);
    e2 = MASSTOR_FIRST(e2);
    if (e1 <= e2) {
      return FALSE;
    }
  } while (!(P == MASSTOR_SIL));
  return TRUE;
}

MASSTOR_LIST MASNCC_DINLMPG
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST i, MASSTOR_LIST F)
# else
(T, i, F)
MASSTOR_LIST T, i, F;
# endif
{
  MASSTOR_LIST C, c, CLP, CP, CS, EINS, e, J1Y, j, EVOREM, EVOCOR, l, n, P, p, PP, r, rs, t, X, XP, YP;
  BOOLEAN ec;

  if (F == MASSTOR_SIL) {
    PP = 0;
    return PP;
  }
  J1Y = MASSTOR_FIRST(F);
  r = DIPC_DIPNOV(J1Y);
  EINS = SACRN_RNINT(1);
  EVOREM = DIPC_EVORD;
  EVOCOR = DIPC_INVLEX;
  ec = EVOREM == EVOCOR;
  e = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = r;

    if (B_1 <= B_2)
      for (j = B_1;; j += 1) {
        e = MASSTOR_COMP(0, e);
        if (j >= B_2) break;
      }
  }
  X = DIPC_DIPFMO(EINS, e);
  l = 1;
  n = r + l;
  DIPC_PFDIP(X, &rs, &P);
  P = SACPOL_PINV(r, P, 1);
  P = DIPC_PMPV(n, P, l, 1);
  do {
    XP = DIPC_DIPMPV(X, i, l);
    l = l + 1;
    XP = MASNCGB_DINLNF(T, F, XP);
    if (!ec) {
      DIPC_EVORD = EVOCOR;
      DIPC_DIPBSO(XP);
    }
    DIPC_PFDIP(XP, &rs, &YP);
    YP = SACPOL_PINV(r, YP, l);
    n = r + l;
    YP = DIPC_PMPV(n, YP, l, 1);
    P = SACPOL_PINV(r, P, 1);
    P = SACRPOL_RPSUM(n, P, YP);
    CP = DIPC_PBCLI(r, P);
    C = DIPC_DILFPL(l, CP);
    CS = MASSTOR_SIL;
    while (C != MASSTOR_SIL) {
      MASSTOR_ADV(C, &c, &C);
      c = DIPRN_DIRPEM(c, EINS);
      CS = MASSTOR_COMP(c, CS);
    }
    C = MASSTOR_INV(CS);
    C = DIPRNGB_DIRLIS(C);
    t = DIPDIM_DIGBZT(C);
    if (!ec) {
      DIPC_EVORD = EVOREM;
    }
  } while (!(t == 0));
  l = l - 1;
  MASBIOS_SWRITE("C=", 2L);
  SACLIST_OWRITE(C);
  MASBIOS_BLINES(0);
  PP = SACPOL_PMON(EINS, l);
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &c, &C);
    e = DIPC_DIPEVL(c);
    n = l - MASSTOR_FIRST(DIPC_EVDOV(e));
    CLP = SACRN_RNNEG(DIPC_DIPTBC(c));
    p = SACPOL_PMON(CLP, n);
    PP = SACRPOL_RPSUM(1, PP, p);
  }
  PP = DIPC_DIPFP(1, PP);
  return PP;
}

MASSTOR_LIST MASNCC_DINLMPL
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST F)
# else
(T, F)
MASSTOR_LIST T, F;
# endif
{
  MASSTOR_LIST P, p, r, i, t;

  P = MASSTOR_SIL;
  if (F == MASSTOR_SIL) {
    return P;
  }
  r = DIPC_DIPNOV(MASSTOR_FIRST(F));
  t = DIPDIM_DIGBZT(F);
  if (t > 0) {
    return P;
  }
  if (!MASNCC_DINPTslT(T)) {
    return P;
  }
  i = 0;
  while (i < r) {
    i = i + 1;
    p = MASNCC_DINLMPG(T, i, F);
    P = MASSTOR_COMP(p, P);
  }
  P = MASSTOR_INV(P);
  return P;
}

MASSTOR_LIST MASNCC_EVGCD
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  if (U == MASSTOR_SIL) {
    return W;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL < VL) {
      WL = UL;
    } else {
      WL = VL;
    }
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST MASNCC_EVLGTD
# ifdef __STDC__
(MASSTOR_LIST r, MASSTOR_LIST d, MASSTOR_LIST L)
# else
(r, d, L)
MASSTOR_LIST r, d, L;
# endif
{
  MASSTOR_LIST LS, LP, D, DP, DPP, DPPP, DH, e, f, n, ep, m, l;

  LP = L;
  if (LP == MASSTOR_SIL) {
    e = MASSTOR_SIL;
    {
      LONGINT B_3 = 1, B_4 = r;

      if (B_3 <= B_4)
        for (n = B_3;; n += 1) {
          e = MASSTOR_COMP(0, e);
          if (n >= B_4) break;
        }
    }
    D = MASSTOR_LIST1(e);
    LP = MASSTOR_COMP(D, LP);
  }
  if (d == 0) {
    return LP;
  }
  LS = MASSTOR_RED(LP);
  if (LS == MASSTOR_SIL) {
    e = MASSTOR_FIRST(MASSTOR_FIRST(LP));
    D = MASSTOR_SIL;
    {
      LONGINT B_5 = 1, B_6 = r;

      if (B_5 <= B_6)
        for (n = B_5;; n += 1) {
          DIPC_EVCADD(e, n, 1, &ep, &f);
          D = MASSTOR_COMP(ep, D);
          if (n >= B_6) break;
        }
    }
    D = MASSTOR_INV(D);
    LS = MASSTOR_LIST1(D);
    LP = SACLIST_CCONC(LP, LS);
  }
  if (d == 1) {
    return LP;
  }
  MASSTOR_ADV(LS, &D, &LS);
  DP = D;
  m = 2;
  while (m <= d && LS != MASSTOR_SIL) {
    m = m + 1;
    MASSTOR_ADV(LS, &DP, &LS);
  }
  LS = MASSTOR_SIL;
  while (m <= d) {
    m = m + 1;
    DH = MASSTOR_SIL;
    {
      LONGINT B_7 = 1, B_8 = r;

      if (B_7 <= B_8)
        for (n = B_7;; n += 1) {
          DPP = DP;
          l = n - 1;
          do {
            DPPP = DPP;
            MASSTOR_ADV(DPP, &e, &DPP);
          } while (!MASNCC_EVTSZ(l, e));
          DPP = DPPP;
          DP = DPP;
          while (DPP != MASSTOR_SIL) {
            MASSTOR_ADV(DPP, &e, &DPP);
            DIPC_EVCADD(e, n, 1, &ep, &f);
            DH = MASSTOR_COMP(ep, DH);
          }
          if (n >= B_8) break;
        }
    }
    DH = MASSTOR_INV(DH);
    DP = DH;
    LS = MASSTOR_COMP(DH, LS);
  }
  if (LS != MASSTOR_SIL) {
    LS = MASSTOR_INV(LS);
    LP = SACLIST_CCONC(LP, LS);
  }
  return LP;
}

MASSTOR_LIST MASNCC_EVLGIL
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST U, LP, LPP, LS, DP, e, n;

  LP = MASSTOR_SIL;
  if (D == MASSTOR_SIL) {
    LP = MASSTOR_COMP(MASSTOR_SIL, LP);
    return LP;
  }
  MASSTOR_ADV(D, &e, &DP);
  if (DP == MASSTOR_SIL) {
    {
      LONGINT B_9 = 0, B_10 = e;

      if (B_9 <= B_10)
        for (n = B_9;; n += 1) {
          U = MASSTOR_LIST1(n);
          LP = MASSTOR_COMP(U, LP);
          if (n >= B_10) break;
        }
    }
    return LP;
  }
  LS = MASNCC_EVLGIL(DP);
  LS = MASSTOR_INV(LS);
  {
    LONGINT B_11 = 0, B_12 = e;

    if (B_11 <= B_12)
      for (n = B_11;; n += 1) {
        LPP = LS;
        while (LPP != MASSTOR_SIL) {
          MASSTOR_ADV(LPP, &U, &LPP);
          U = MASSTOR_COMP(n, U);
          LP = MASSTOR_COMP(U, LP);
        }
        if (n >= B_12) break;
      }
  }
  return LP;
}

MASSTOR_LIST MASNCC_EVLINV
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST i, MASSTOR_LIST k)
# else
(L, i, k)
MASSTOR_LIST L, i, k;
# endif
{
  MASSTOR_LIST M, LP, E, e;

  LP = L;
  if (L == MASSTOR_SIL || k == 0) {
    return LP;
  }
  M = L;
  LP = MASSTOR_SIL;
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &e, &M);
    e = MASNCC_EVINV(e, i, k);
    LP = MASSTOR_COMP(e, LP);
  }
  LP = MASSTOR_INV(LP);
  return LP;
}

BOOLEAN MASNCC_EVTSZ
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST U)
# else
(i, U)
MASSTOR_LIST i, U;
# endif
{
  MASSTOR_LIST e, n;

  {
    LONGINT B_13 = 1, B_14 = i;

    if (B_13 <= B_14)
      for (n = B_13;; n += 1) {
        MASSTOR_ADV(U, &e, &U);
        if (e != 0) {
          return FALSE;
        }
        if (n >= B_14) break;
      }
  }
  return TRUE;
}

MASSTOR_LIST MASNCC_EVINV
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST i, MASSTOR_LIST k)
# else
(U, i, k)
MASSTOR_LIST U, i, k;
# endif
{
  MASSTOR_LIST j, V, W, WS, e;

  V = MASSTOR_SIL;
  {
    LONGINT B_15 = 1, B_16 = i;

    if (B_15 <= B_16)
      for (j = B_15;; j += 1) {
        MASSTOR_ADV(U, &e, &U);
        V = MASSTOR_COMP(e, V);
        if (j >= B_16) break;
      }
  }
  W = U;
  {
    LONGINT B_17 = 1, B_18 = k;

    if (B_17 <= B_18)
      for (j = B_17;; j += 1) {
        W = MASSTOR_COMP(0, W);
        if (j >= B_18) break;
      }
  }
  if (V != MASSTOR_SIL) {
    WS = MASSTOR_INV(V);
    MASSTOR_SRED(V, W);
    W = WS;
  }
  return W;
}

void BEGIN_MASNCC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACSET();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_SACPOL();
    BEGIN_SACRPOL();
    BEGIN_DIPC();
    BEGIN_DIPTOO();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_DIPDIM();
    BEGIN_MASNC();
    BEGIN_MASNCGB();

  }
}
