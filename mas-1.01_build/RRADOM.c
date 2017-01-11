#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

#ifndef DEFINITION_LINALGI
#include "LINALGI.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_RRADOM
#include "RRADOM.h"
#endif

CHAR RRADOM_rcsid [] = "$Id: RRADOM.md,v 1.1 1994/03/11 15:21:49 pesch Exp $";
CHAR RRADOM_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: RRADOM.mi,v 1.1 1994/03/11 15:21:49 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static void RRADUPDATE ARGS((MASSTOR_LIST D, MASSTOR_LIST i, MASSTOR_LIST M1, MASSTOR_LIST M2, MASSTOR_LIST *l, MASSTOR_LIST *ls));


MASSTOR_LIST RRADOM_EVUMSORT
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST L1, L2, s, x;

  if (L != MASSTOR_SIL && MASSTOR_RED(L) != MASSTOR_SIL) {
    L1 = MASSTOR_SIL;
    L2 = MASSTOR_SIL;
    s = 1;
    while (L != MASSTOR_SIL) {
      MASSTOR_ADV(L, &x, &L);
      if (s == 1) {
        L1 = MASSTOR_COMP(x, L1);
      } else {
        L2 = MASSTOR_COMP(x, L2);
      }
      s = -s;
    }
    L1 = RRADOM_EVUMSORT(L1);
    L2 = RRADOM_EVUMSORT(L2);
    while (L1 != MASSTOR_SIL && L2 != MASSTOR_SIL) {
      s = DIPC_EVCOMP(MASSTOR_FIRST(L1), MASSTOR_FIRST(L2));
      if (s != 1) {
        MASSTOR_ADV(L1, &x, &L1);
      }
      if (s != -1) {
        MASSTOR_ADV(L2, &x, &L2);
      }
      L = MASSTOR_COMP(x, L);
    }
    while (L1 != MASSTOR_SIL) {
      MASSTOR_ADV(L1, &x, &L1);
      L = MASSTOR_COMP(x, L);
    }
    while (L2 != MASSTOR_SIL) {
      MASSTOR_ADV(L2, &x, &L2);
      L = MASSTOR_COMP(x, L);
    }
    L = MASSTOR_INV(L);
  }
  return L;
}

MASSTOR_LIST RRADOM_EVSSPROD
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST U, V, v, t;

  U = MASSTOR_SIL;
  while (T != MASSTOR_SIL) {
    V = T;
    MASSTOR_ADV(T, &t, &T);
    while (V != MASSTOR_SIL) {
      MASSTOR_ADV(V, &v, &V);
      U = MASSTOR_COMP(DIPC_EVSUM(t, v), U);
    }
  }
  return RRADOM_EVUMSORT(U);
}

MASSTOR_LIST RRADOM_RRVTEXT
# ifdef __STDC__
(MASSTOR_LIST C_187_A, MASSTOR_LIST L)
# else
(C_187_A, L)
MASSTOR_LIST C_187_A, L;
# endif
{
  MASSTOR_LIST B, As, as, e;

  B = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &e, &L);
    As = C_187_A;
    while (As != MASSTOR_SIL) {
      MASSTOR_ADV(As, &as, &As);
      B = MASSTOR_COMP(MASSTOR_COMP(e, as), B);
    }
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST RRADOM_RRZDIM
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST n, g;

  n = MASSTOR_LENGTH(DIPC_DIPEVL(MASSTOR_FIRST(G)));
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (MASSTOR_LENGTH(DIPC_EVDOV(DIPC_DIPEVL(g))) == 1) {
      n = n - 1;
    }
  }
  if (n == 0) {
    return 1;
  } else {
    return 0;
  }
}

void RRADOM_RRREDTEST
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST t, MASSTOR_LIST *g, MASSTOR_LIST *s)
# else
(G, t, g, s)
MASSTOR_LIST G, t;
MASSTOR_LIST *g, *s;
# endif
{
  MASSTOR_LIST w;

  *s = -1;
  while (G != MASSTOR_SIL && *s == -1) {
    MASSTOR_ADV(G, g, &G);
    DIPC_EVDFSI(t, DIPC_DIPEVL(*g), &w, s);
  }
}

MASSTOR_LIST RRADOM_RRREDTERMS
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST R, L, i, j, g, t, n, s;

  n = MASSTOR_LENGTH(DIPC_DIPEVL(MASSTOR_FIRST(G)));
  R = MASSTOR_LIST1(LINALGRN_VEL(0, n));
  {
    LONGINT B_1 = 1, B_2 = n;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        L = R;
        while (L != MASSTOR_SIL) {
          MASSTOR_ADV(L, &t, &L);
          DIPC_EVCADD(t, i, 1, &t, &j);
          RRADOM_RRREDTEST(G, t, &g, &s);
          while (s == -1) {
            R = MASSTOR_COMP(t, R);
            DIPC_EVCADD(t, i, 1, &t, &j);
            RRADOM_RRREDTEST(G, t, &g, &s);
          }
        }
        if (i >= B_2) break;
      }
  }
  return RRADOM_EVUMSORT(R);
}

MASSTOR_LIST RRADOM_RRADNFORM
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST G, MASSTOR_LIST R)
# else
(D, G, R)
MASSTOR_LIST D, G, R;
# endif
{
  MASSTOR_LIST NF, N, L, U, u, ut, up, v, vt, vp, w, wt, wp, a, t, x, tx, g;

  NF = MASSTOR_SIL;
  U = RRADOM_EVSSPROD(R);
  while (U != MASSTOR_SIL) {
    MASSTOR_ADV(U, &u, &U);
    RRADOM_RRREDTEST(G, u, &g, &ut);
    if (ut == -1) {
      up = DIPC_DIPFMO(MASADOM_ADFI(D, 1), u);
    } else if (ut == 0) {
      up = DIPADOM_DIPNEG(DIPC_DIPMRD(g));
    } else {
      up = 0;
      N = NF;
      do {
        do {
          MASSTOR_ADV(N, &L, &N);
          SACLIST_FIRST3(L, &v, &vt, &vp);
        } while (!(vt != -1));
        x = DIPC_EVDIF(u, v);
      } while (!(DIPC_EVSIGN(x) == 1 && DIPC_EVTDEG(x) == 1));
      N = NF;
      while (vp != 0) {
        DIPC_DIPMAD(vp, &a, &t, &vp);
        if (vp == MASSTOR_SIL) {
          vp = 0;
        }
        tx = DIPC_EVSUM(t, x);
        do {
          MASSTOR_ADV(N, &L, &N);
          SACLIST_FIRST3(L, &w, &wt, &wp);
        } while (!(SACLIST_EQUAL(w, tx) == 1));
        up = DIPADOM_DIPSUM(up, DIPADOM_DIPBCP(wp, a));
      }
    }
    NF = MASSTOR_COMP(SACLIST_LIST3(u, ut, up), NF);
  }
  return NF;
}

void RRADOM_RRADSTRCONST
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST *U, MASSTOR_LIST *beta)
# else
(D, G, R, U, beta)
MASSTOR_LIST D, G, R;
MASSTOR_LIST *U, *beta;
# endif
{
  MASSTOR_LIST NF, L, u, ut, up, uv, a, t, V, v;

  *U = MASSTOR_SIL;
  *beta = MASSTOR_SIL;
  NF = RRADOM_RRADNFORM(D, G, R);
  while (NF != MASSTOR_SIL) {
    MASSTOR_ADV(NF, &L, &NF);
    SACLIST_FIRST3(L, &u, &ut, &up);
    uv = MASSTOR_SIL;
    V = SACLIST_CINV(R);
    while (up != 0) {
      DIPC_DIPMAD(up, &a, &t, &up);
      if (up == MASSTOR_SIL) {
        up = 0;
      }
      MASSTOR_ADV(V, &v, &V);
      while (SACLIST_EQUAL(v, t) == 0) {
        MASSTOR_ADV(V, &v, &V);
        uv = MASSTOR_COMP(MASADOM_ADFI(D, 0), uv);
      }
      uv = MASSTOR_COMP(a, uv);
    }
    while (V != MASSTOR_SIL) {
      MASSTOR_ADV(V, &v, &V);
      uv = MASSTOR_COMP(MASADOM_ADFI(D, 0), uv);
    }
    *U = MASSTOR_COMP(u, *U);
    *beta = MASSTOR_COMP(uv, *beta);
  }
}

MASSTOR_LIST RRADOM_RRMMULT
# ifdef __STDC__
(MASSTOR_LIST w, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta)
# else
(w, R, U, beta)
MASSTOR_LIST w, R, U, beta;
# endif
{
  MASSTOR_LIST M, u, v, t, l;

  M = MASSTOR_SIL;
  while (R != MASSTOR_SIL) {
    MASSTOR_ADV(R, &v, &R);
    t = DIPC_EVSUM(w, v);
    do {
      MASSTOR_ADV(U, &u, &U);
      MASSTOR_ADV(beta, &l, &beta);
    } while (!(SACLIST_EQUAL(t, u) == 1));
    M = MASSTOR_COMP(l, M);
  }
  return MASSTOR_INV(M);
}

MASSTOR_LIST RRADOM_RRADVARMATRICES
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta)
# else
(G, R, U, beta)
MASSTOR_LIST G, R, U, beta;
# endif
{
  MASSTOR_LIST L, MXi, i, j, n, s, a, t, f, g;

  L = MASSTOR_SIL;
  n = MASSTOR_LENGTH(DIPC_DIPEVL(MASSTOR_FIRST(G)));
  for (i = n; i >= 1; i += -1) {
    DIPC_EVCADD(LINALGRN_VEL(0, n), i, 1, &t, &j);
    RRADOM_RRREDTEST(G, t, &g, &s);
    if (s == -1) {
      MXi = RRADOM_RRMMULT(t, R, U, beta);
    } else {
      MXi = MASSTOR_SIL;
      f = DIPADOM_DIPNEG(DIPC_DIPMRD(g));
      while (f != 0) {
        DIPC_DIPMAD(f, &a, &t, &f);
        if (f == MASSTOR_SIL) {
          f = 0;
        }
        MXi = LINALG_ADMSUM(MXi, LINALG_ADSMPROD(RRADOM_RRMMULT(t, R, U, beta), a));
      }
    }
    L = MASSTOR_COMP(SACLIST_LIST2(1, MXi), L);
  }
  return L;
}

static void RRADUPDATE
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST i, MASSTOR_LIST M1, MASSTOR_LIST M2, MASSTOR_LIST *l, MASSTOR_LIST *ls)
# else
(D, i, M1, M2, l, ls)
MASSTOR_LIST D, i, M1, M2;
MASSTOR_LIST *l, *ls;
# endif
{
  MASSTOR_LIST j, M;

  while (*l != MASSTOR_SIL && MASSTOR_FIRST(*l) < i) {
    SACLIST_ADV2(*l, &j, &M, l);
    *ls = SACLIST_COMP2(M, j, *ls);
  }
  if (*l == MASSTOR_SIL || MASSTOR_FIRST(*l) > i) {
    M = LINALG_ADMPROD(D, M1, M2);
    *l = SACLIST_COMP2(i, M, *l);
  }
}

void RRADOM_RRADPOLMATRIX
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST R, MASSTOR_LIST h, MASSTOR_LIST *Mh, MASSTOR_LIST *L)
# else
(D, R, h, Mh, L)
MASSTOR_LIST D, R, h;
MASSTOR_LIST *Mh, *L;
# endif
{
  MASSTOR_LIST Mt, Ls, l, ls, C_186_A, a, B, b, k, p, c, t;

  p = MASSTOR_LENGTH(R);
  *Mh = MASSTOR_SIL;
  while (h != 0) {
    DIPC_DIPMAD(h, &c, &t, &h);
    if (h == MASSTOR_SIL) {
      h = 0;
    }
    Mt = LINALG_ADUM(D, p);
    Ls = MASSTOR_SIL;
    while (*L != MASSTOR_SIL) {
      MASSTOR_ADV(*L, &l, L);
      MASSTOR_ADV(t, &k, &t);
      if (k != 0) {
        ls = MASSTOR_SIL;
        a = 0;
        C_186_A = LINALG_ADUM(D, p);
        b = MASSTOR_FIRST(l);
        B = SACLIST_SECOND(l);
        while (k != 0) {
          while (MASELEM_MASEVEN(k)) {
            b = 2 * b;
            k = k / 2;
            RRADUPDATE(D, b, B, B, &l, &ls);
            B = SACLIST_SECOND(l);
          }
          a = a + b;
          k = k - 1;
          RRADUPDATE(D, a, C_186_A, B, &l, &ls);
          C_186_A = SACLIST_SECOND(l);
        }
        Mt = LINALG_ADMPROD(D, Mt, C_186_A);
        l = SACLIST_CONC(MASSTOR_INV(ls), l);
      }
      Ls = MASSTOR_COMP(l, Ls);
    }
    *Mh = LINALG_ADMSUM(*Mh, LINALG_ADSMPROD(Mt, c));
    *L = MASSTOR_INV(Ls);
  }
}

MASSTOR_LIST RRADOM_RRADQUADFORM
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta, MASSTOR_LIST Mh)
# else
(D, R, U, beta, Mh)
MASSTOR_LIST D, R, U, beta, Mh;
# endif
{
  MASSTOR_LIST Q, V, v, W, w, tab, t, p, betah, Mhv, i, j, e, q, s, u;

  tab = MASSTOR_SIL;
  p = MASSTOR_LENGTH(R);
  Q = LINALGRN_VEL(LINALGRN_VEL(0, p), p);
  betah = LINALG_ADMPROD(D, beta, Mh);
  V = R;
  {
    LONGINT B_3 = 1, B_4 = p;

    if (B_3 <= B_4)
      for (i = B_3;; i += 1) {
        W = V;
        MASSTOR_ADV(V, &v, &V);
        Mhv = RRADOM_RRMMULT(v, R, U, betah);
        {
          LONGINT B_5 = i, B_6 = p;

          if (B_5 <= B_6)
            for (j = B_5;; j += 1) {
              MASSTOR_ADV(W, &w, &W);
              u = DIPC_EVSUM(v, w);
              s = 0;
              t = tab;
              while (t != MASSTOR_SIL && s == 0) {
                SACLIST_ADV2(t, &e, &q, &t);
                s = SACLIST_EQUAL(u, e);
              }
              if (s == 0) {
                q = LINALG_ADMPTRACE(D, Mhv, RRADOM_RRMMULT(w, R, U, beta));
                tab = SACLIST_COMP2(u, q, tab);
              }
              Q = LINALGRN_MSET(Q, i, j, q);
              if (j != i) {
                Q = LINALGRN_MSET(Q, j, i, q);
              }
              if (j >= B_6) break;
            }
        }
        if (i >= B_4) break;
      }
  }
  return Q;
}

MASSTOR_LIST RRADOM_RRCSR
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST v, MASSTOR_LIST tf, MASSTOR_LIST *C_185_A, MASSTOR_LIST *N, MASSTOR_LIST *S, MASSTOR_LIST *L)
# else
(i, v, tf, C_185_A, N, S, L)
MASSTOR_LIST i, v, tf;
MASSTOR_LIST *C_185_A, *N, *S, *L;
# endif
{
  MASSTOR_LIST ZNL, Z, z, zi, AL, AU, As, a, au, Ns, n, ni, Ss, s, Ls, l, k;

  LINALGI_IMGELUD(*C_185_A, &AL, &AU);
  Z = LINALGI_IMSDS(AL, AU, *S);
  *C_185_A = LINALGRN_MTRANS(*C_185_A);
  Ns = MASSTOR_SIL;
  As = MASSTOR_SIL;
  ZNL = MASSTOR_SIL;
  while (Z != MASSTOR_SIL) {
    MASSTOR_ADV(Z, &z, &Z);
    MASSTOR_ADV(*N, &n, N);
    MASSTOR_ADV(*C_185_A, &a, C_185_A);
    if (z != 0) {
      zi = SACRN_RNNUM(z);
      ni = SACLIST_CINV(n);
      if (tf == 1) {
        MASBIOS_SWRITE("Sign-Condition: ", 16L);
        SACLIST_OWRITE(ni);
        MASBIOS_SWRITE("  Real Zeroes: ", 15L);
        SACLIST_OWRITE(zi);
        MASBIOS_BLINES(0);
      }
      ZNL = MASSTOR_COMP(SACLIST_LIST2(zi, ni), ZNL);
      Ns = MASSTOR_COMP(n, Ns);
      As = MASSTOR_COMP(a, As);
    }
  }
  *N = MASSTOR_INV(Ns);
  *C_185_A = MASSTOR_INV(As);
  ZNL = MASSTOR_INV(ZNL);
  if (MASSTOR_LENGTH(v) >= i && SACLIST_MEMBER(SACLIST_REDUCT(SACLIST_CINV(v), MASSTOR_LENGTH(v) - i), *N) == 0) {
    return MASSTOR_SIL;
  }
  k = MASSTOR_LENGTH(MASSTOR_FIRST(*C_185_A));
  LINALGI_IMGELUD(*C_185_A, &AL, &AU);
  *C_185_A = LINALGRN_MTRANS(*C_185_A);
  As = MASSTOR_SIL;
  Ss = MASSTOR_SIL;
  Ls = MASSTOR_SIL;
  while (AU != MASSTOR_SIL) {
    MASSTOR_ADV(AU, &au, &AU);
    i = MASSTOR_LENGTH(au);
    MASSTOR_ADV(*C_185_A, &a, C_185_A);
    MASSTOR_ADV(*S, &s, S);
    MASSTOR_ADV(*L, &l, L);
    while (i < k) {
      MASSTOR_ADV(*C_185_A, &a, C_185_A);
      MASSTOR_ADV(*S, &s, S);
      MASSTOR_ADV(*L, &l, L);
      k = k - 1;
    }
    As = MASSTOR_COMP(a, As);
    Ss = MASSTOR_COMP(s, Ss);
    Ls = MASSTOR_COMP(l, Ls);
    k = k - 1;
  }
  *C_185_A = MASSTOR_INV(As);
  *S = MASSTOR_INV(Ss);
  *L = MASSTOR_INV(Ls);
  return ZNL;
}

MASSTOR_LIST RRADOM_RRADCOUNT
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST G, MASSTOR_LIST H, MASSTOR_LIST v, MASSTOR_LIST tf)
# else
(D, G, H, v, tf)
MASSTOR_LIST D, G, H, v, tf;
# endif
{
  MASSTOR_LIST ZNL, R, E, U, beta, s, S, m, N, C_184_A, W, L, i, h, S1, S2, m0, m1, m2, md, mh;

  R = RRADOM_RRREDTERMS(G);
  E = LINALG_ADUM(D, MASSTOR_LENGTH(R));
  RRADOM_RRADSTRCONST(D, G, R, &U, &beta);
  s = LINALG_ADSIG(D, RRADOM_RRADQUADFORM(D, R, U, beta, E));
  if (s == 0) {
    return MASSTOR_SIL;
  }
  if (H == MASSTOR_SIL) {
    ZNL = MASSTOR_LIST1(SACLIST_LIST2(s, MASSTOR_SIL));
    return ZNL;
  }
  S = MASSTOR_LIST1(s);
  m = MASSTOR_LIST1(E);
  N = MASSTOR_LIST1(MASSTOR_SIL);
  C_184_A = MASSTOR_LIST1(MASSTOR_LIST1(1));
  W = SACLIST_LIST3(SACLIST_LIST3(1, 1, 1), SACLIST_LIST3(-1, 0, 1), SACLIST_LIST3(1, 0, 1));
  L = RRADOM_RRADVARMATRICES(G, R, U, beta);
  i = 0;
  do {
    MASSTOR_ADV(H, &h, &H);
    i = i + 1;
    if (tf == 1) {
      MASBIOS_BLINES(1);
      MASBIOS_SWRITE("Condition No. ", 14L);
      SACLIST_OWRITE(i);
      MASBIOS_BLINES(0);
    }
    RRADOM_RRADPOLMATRIX(D, R, h, &mh, &L);
    N = RRADOM_RRVTEXT(N, SACLIST_LIST3(-1, 0, 1));
    C_184_A = LINALG_IMRTPROD(W, C_184_A);
    S1 = MASSTOR_SIL;
    S2 = MASSTOR_SIL;
    m1 = MASSTOR_SIL;
    m2 = MASSTOR_SIL;
    m0 = m;
    while (m0 != MASSTOR_SIL) {
      MASSTOR_ADV(m0, &md, &m0);
      md = LINALG_ADMPROD(D, md, mh);
      m1 = MASSTOR_COMP(md, m1);
      s = LINALG_ADSIG(D, RRADOM_RRADQUADFORM(D, R, U, beta, md));
      S1 = MASSTOR_COMP(s, S1);
      md = LINALG_ADMPROD(D, md, mh);
      m2 = MASSTOR_COMP(md, m2);
      s = LINALG_ADSIG(D, RRADOM_RRADQUADFORM(D, R, U, beta, md));
      S2 = MASSTOR_COMP(s, S2);
    }
    S = SACLIST_CONC(S, SACLIST_CONC(MASSTOR_INV(S1), MASSTOR_INV(S2)));
    m = SACLIST_CONC(m, SACLIST_CONC(MASSTOR_INV(m1), MASSTOR_INV(m2)));
    ZNL = RRADOM_RRCSR(i, v, tf, &C_184_A, &N, &S, &m);
  } while (!(ZNL == MASSTOR_SIL || H == MASSTOR_SIL));
  return ZNL;
}

void BEGIN_RRADOM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_DIPC();
    BEGIN_DIPADOM();
    BEGIN_MASADOM();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_LINALG();
    BEGIN_LINALGI();
    BEGIN_LINALGRN();

  }
}
