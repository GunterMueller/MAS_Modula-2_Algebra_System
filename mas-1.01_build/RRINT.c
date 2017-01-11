#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_LINALGI
#include "LINALGI.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

#ifndef DEFINITION_RRADOM
#include "RRADOM.h"
#endif

#ifndef DEFINITION_RRINT
#include "RRINT.h"
#endif

CHAR RRINT_rcsid [] = "$Id: RRINT.md,v 1.1 1994/03/11 15:21:50 pesch Exp $";
CHAR RRINT_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: RRINT.mi,v 1.1 1994/03/11 15:21:51 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static void RRIUPDATE ARGS((MASSTOR_LIST i, MASSTOR_LIST M1, MASSTOR_LIST M2, MASSTOR_LIST *l, MASSTOR_LIST *ls));


void RRINT_RRIPIQ
# ifdef __STDC__
(MASSTOR_LIST c, MASSTOR_LIST *C_176_A, MASSTOR_LIST *a)
# else
(c, C_176_A, a)
MASSTOR_LIST c;
MASSTOR_LIST *C_176_A, *a;
# endif
{
  MASSTOR_LIST b, ct, pp, cts, cs;

  if (c != 1) {
    DIPI_DIIPCP(*C_176_A, &ct, &pp);
    SACI_IGCDCF(ct, c, &b, &cts, &cs);
    *C_176_A = DIPI_DIIPIP(pp, cts);
    *a = MASI_IPROD(*a, cs);
  }
}

void RRINT_RRIPQSUM
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST b, MASSTOR_LIST c, MASSTOR_LIST *C_175_A, MASSTOR_LIST *a)
# else
(B, b, c, C_175_A, a)
MASSTOR_LIST B, b, c;
MASSTOR_LIST *C_175_A, *a;
# endif
{
  MASSTOR_LIST as, bs, bss, cs, d, e, es, f, ct, cts, pp;

  if (B != 0) {
    if (*C_175_A == 0) {
      if (b == 1) {
        *C_175_A = DIPI_DIIPIP(B, c);
        *a = 1;
      } else {
        SACI_IGCDCF(b, c, &d, a, &cs);
        *C_175_A = DIPI_DIIPIP(B, cs);
      }
    } else if (*a == 1 && b == 1) {
      *C_175_A = DIPI_DIIPSM(*C_175_A, DIPI_DIIPIP(B, c));
    } else if (b == 1) {
      *C_175_A = DIPI_DIIPSM(*C_175_A, DIPI_DIIPIP(B, MASI_IPROD(*a, c)));
    } else if (*a == 1) {
      SACI_IGCDCF(b, c, &d, a, &cs);
      *C_175_A = DIPI_DIIPSM(DIPI_DIIPIP(*C_175_A, *a), DIPI_DIIPIP(B, cs));
    } else {
      SACI_IGCDCF(b, c, &d, &bs, &cs);
      SACI_IGCDCF(*a, bs, &e, &as, &bss);
      *C_175_A = DIPI_DIIPSM(DIPI_DIIPIP(*C_175_A, bss), DIPI_DIIPIP(B, MASI_IPROD(cs, as)));
      DIPI_DIIPCP(*C_175_A, &ct, &pp);
      SACI_IGCDCF(ct, e, &f, &cts, &es);
      *C_175_A = DIPI_DIIPIP(pp, cts);
      *a = MASI_IPROD(MASI_IPROD(as, es), bss);
    }
  }
}

void RRINT_RRINFORM
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST *a, MASSTOR_LIST *NF)
# else
(G, R, a, NF)
MASSTOR_LIST G, R;
MASSTOR_LIST *a, *NF;
# endif
{
  MASSTOR_LIST N, L, U, u, ut, ua, up, ups, v, vt, va, vas, vp, w, wt, wa, wp, c, t, x, tx, g, i, is;

  *a = 1;
  *NF = MASSTOR_SIL;
  U = RRADOM_EVSSPROD(R);
  while (U != MASSTOR_SIL) {
    MASSTOR_ADV(U, &u, &U);
    RRADOM_RRREDTEST(G, u, &g, &ut);
    if (ut == -1) {
      ua = 1;
      up = DIPC_DIPFMO(1, u);
    } else if (ut == 0) {
      ua = DIPC_DIPLBC(g);
      up = DIPI_DIIPNG(DIPC_DIPMRD(g));
    } else {
      ua = 1;
      up = 0;
      N = *NF;
      do {
        do {
          MASSTOR_ADV(N, &L, &N);
          SACLIST_FIRST4(L, &v, &vt, &va, &vp);
        } while (!(vt != -1));
        x = DIPC_EVDIF(u, v);
      } while (!(DIPC_EVSIGN(x) == 1 && DIPC_EVTDEG(x) == 1));
      N = *NF;
      while (vp != 0) {
        DIPC_DIPMAD(vp, &c, &t, &vp);
        if (vp == MASSTOR_SIL) {
          vp = 0;
        }
        tx = DIPC_EVSUM(t, x);
        do {
          MASSTOR_ADV(N, &L, &N);
          SACLIST_FIRST4(L, &w, &wt, &wa, &wp);
        } while (!(SACLIST_EQUAL(w, tx) == 1));
        RRINT_RRIPQSUM(wp, wa, c, &up, &ua);
      }
      RRINT_RRIPIQ(va, &up, &ua);
    }
    *a = SACI_ILCM(*a, ua);
    *NF = MASSTOR_COMP(SACLIST_LIST4(u, ut, ua, up), *NF);
  }
}

void RRINT_RRISTRCONST
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST *U, MASSTOR_LIST *a, MASSTOR_LIST *beta)
# else
(G, R, U, a, beta)
MASSTOR_LIST G, R;
MASSTOR_LIST *U, *a, *beta;
# endif
{
  MASSTOR_LIST NF, L, u, ut, ua, up, uv, c, k, t, V, v;

  *U = MASSTOR_SIL;
  *beta = MASSTOR_SIL;
  RRINT_RRINFORM(G, R, a, &NF);
  while (NF != MASSTOR_SIL) {
    MASSTOR_ADV(NF, &L, &NF);
    SACLIST_FIRST4(L, &u, &ut, &ua, &up);
    k = SACI_IQ(*a, ua);
    uv = MASSTOR_SIL;
    V = SACLIST_CINV(R);
    while (up != 0) {
      DIPC_DIPMAD(up, &c, &t, &up);
      if (up == MASSTOR_SIL) {
        up = 0;
      }
      MASSTOR_ADV(V, &v, &V);
      while (SACLIST_EQUAL(v, t) == 0) {
        MASSTOR_ADV(V, &v, &V);
        uv = MASSTOR_COMP(0, uv);
      }
      uv = MASSTOR_COMP(MASI_IPROD(k, c), uv);
    }
    while (V != MASSTOR_SIL) {
      MASSTOR_ADV(V, &v, &V);
      uv = MASSTOR_COMP(0, uv);
    }
    *U = MASSTOR_COMP(u, *U);
    *beta = MASSTOR_COMP(uv, *beta);
  }
}

void RRINT_RRIVARMATRICES
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta, MASSTOR_LIST *al, MASSTOR_LIST *L)
# else
(G, R, U, beta, al, L)
MASSTOR_LIST G, R, U, beta;
MASSTOR_LIST *al, *L;
# endif
{
  MASSTOR_LIST MXi, ai, i, j, n, s, c, t, f, g;

  *L = MASSTOR_SIL;
  *al = MASSTOR_SIL;
  n = MASSTOR_LENGTH(DIPC_DIPEVL(MASSTOR_FIRST(G)));
  for (i = n; i >= 1; i += -1) {
    DIPC_EVCADD(LINALGRN_VEL(0, n), i, 1, &t, &j);
    RRADOM_RRREDTEST(G, t, &g, &s);
    if (s == -1) {
      MXi = RRADOM_RRMMULT(t, R, U, beta);
      ai = 1;
    } else {
      MXi = MASSTOR_SIL;
      ai = DIPC_DIPLBC(g);
      f = DIPI_DIIPNG(DIPC_DIPMRD(g));
      while (f != 0) {
        DIPC_DIPMAD(f, &c, &t, &f);
        if (f == MASSTOR_SIL) {
          f = 0;
        }
        MXi = LINALGI_IMSUM(MXi, LINALGI_ISMPROD(RRADOM_RRMMULT(t, R, U, beta), c));
      }
    }
    *al = MASSTOR_COMP(ai, *al);
    *L = MASSTOR_COMP(SACLIST_LIST2(1, MXi), *L);
  }
}

static void RRIUPDATE
# ifdef __STDC__
(MASSTOR_LIST i, MASSTOR_LIST M1, MASSTOR_LIST M2, MASSTOR_LIST *l, MASSTOR_LIST *ls)
# else
(i, M1, M2, l, ls)
MASSTOR_LIST i, M1, M2;
MASSTOR_LIST *l, *ls;
# endif
{
  MASSTOR_LIST j, M;

  while (*l != MASSTOR_SIL && MASSTOR_FIRST(*l) < i) {
    SACLIST_ADV2(*l, &j, &M, l);
    *ls = SACLIST_COMP2(M, j, *ls);
  }
  if (*l == MASSTOR_SIL || MASSTOR_FIRST(*l) > i) {
    M = LINALGI_IMPROD(M1, M2);
    *l = SACLIST_COMP2(i, M, *l);
  }
}

void RRINT_RRIPOLMATRIX
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST h, MASSTOR_LIST f, MASSTOR_LIST fl, MASSTOR_LIST *Mh, MASSTOR_LIST *L)
# else
(R, h, f, fl, Mh, L)
MASSTOR_LIST R, h, f, fl;
MASSTOR_LIST *Mh, *L;
# endif
{
  MASSTOR_LIST Mt, Ls, l, ls, C_174_A, a, B, b, i, k, p, c, t, hs, d, dl, di, dls, fi, fls;

  *Mh = MASSTOR_SIL;
  if (h == 0) {
    return;
  }
  p = MASSTOR_LENGTH(R);
  hs = h;
  DIPC_DIPMAD(hs, &c, &dl, &hs);
  if (hs == MASSTOR_SIL) {
    hs = 0;
  }
  d = DIPC_EVTDEG(dl);
  while (hs != 0) {
    DIPC_DIPMAD(hs, &c, &t, &hs);
    if (hs == MASSTOR_SIL) {
      hs = 0;
    }
    dl = DIPC_EVLCM(dl, t);
    d = SACI_IMAX(d, DIPC_EVTDEG(t));
  }
  while (h != 0) {
    DIPC_DIPMAD(h, &c, &t, &h);
    if (h == MASSTOR_SIL) {
      h = 0;
    }
    if (f != 1) {
      c = MASI_IPROD(c, SACI_IEXP(f, d - DIPC_EVTDEG(t)));
    }
    Mt = LINALGI_IUM(p, p);
    Ls = MASSTOR_SIL;
    dls = dl;
    fls = fl;
    while (*L != MASSTOR_SIL) {
      MASSTOR_ADV(*L, &l, L);
      MASSTOR_ADV(t, &k, &t);
      MASSTOR_ADV(dls, &di, &dls);
      MASSTOR_ADV(fls, &fi, &fls);
      if (fi != 1) {
        c = MASI_IPROD(c, SACI_IEXP(fi, di - k));
      }
      if (k != 0) {
        ls = MASSTOR_SIL;
        a = 0;
        C_174_A = LINALGI_IUM(p, p);
        b = MASSTOR_FIRST(l);
        B = SACLIST_SECOND(l);
        while (k != 0) {
          while (MASELEM_MASEVEN(k)) {
            b = 2 * b;
            k = k / 2;
            RRIUPDATE(b, B, B, &l, &ls);
            B = SACLIST_SECOND(l);
          }
          a = a + b;
          k = k - 1;
          RRIUPDATE(a, C_174_A, B, &l, &ls);
          C_174_A = SACLIST_SECOND(l);
        }
        Mt = LINALGI_IMPROD(Mt, C_174_A);
        l = SACLIST_CONC(MASSTOR_INV(ls), l);
      }
      Ls = MASSTOR_COMP(l, Ls);
    }
    *Mh = LINALGI_IMSUM(*Mh, LINALGI_ISMPROD(Mt, c));
    *L = MASSTOR_INV(Ls);
  }
}

MASSTOR_LIST RRINT_RRIQUADFORM
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST U, MASSTOR_LIST beta, MASSTOR_LIST Mh)
# else
(R, U, beta, Mh)
MASSTOR_LIST R, U, beta, Mh;
# endif
{
  MASSTOR_LIST Q, V, v, W, w, tab, t, p, betah, Mhv, i, j, e, q, s, u;

  tab = MASSTOR_SIL;
  p = MASSTOR_LENGTH(R);
  Q = LINALGRN_VEL(LINALGRN_VEL(0, p), p);
  betah = LINALGI_IMPROD(beta, Mh);
  V = R;
  {
    LONGINT B_1 = 1, B_2 = p;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        W = V;
        MASSTOR_ADV(V, &v, &V);
        Mhv = RRADOM_RRMMULT(v, R, U, betah);
        {
          LONGINT B_3 = i, B_4 = p;

          if (B_3 <= B_4)
            for (j = B_3;; j += 1) {
              MASSTOR_ADV(W, &w, &W);
              u = DIPC_EVSUM(v, w);
              s = 0;
              t = tab;
              while (t != MASSTOR_SIL && s == 0) {
                SACLIST_ADV2(t, &e, &q, &t);
                s = SACLIST_EQUAL(u, e);
              }
              if (s == 0) {
                q = LINALG_IMPTRACE(Mhv, RRADOM_RRMMULT(w, R, U, beta));
                tab = SACLIST_COMP2(u, q, tab);
              }
              Q = LINALGRN_MSET(Q, i, j, q);
              if (j != i) {
                Q = LINALGRN_MSET(Q, j, i, q);
              }
              if (j >= B_4) break;
            }
        }
        if (i >= B_2) break;
      }
  }
  return Q;
}

MASSTOR_LIST RRINT_RRICOUNT
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST H, MASSTOR_LIST v, MASSTOR_LIST tf)
# else
(G, H, v, tf)
MASSTOR_LIST G, H, v, tf;
# endif
{
  MASSTOR_LIST ZNL, R, E, U, beta, s, S, S1, S2, m, m0, m1, m2, md, mh, h, N, C_173_A, W, L, a, al, p, i;

  R = RRADOM_RRREDTERMS(G);
  p = MASSTOR_LENGTH(R);
  E = LINALGI_IUM(p, p);
  RRINT_RRISTRCONST(G, R, &U, &a, &beta);
  s = LINALG_ISIG(RRINT_RRIQUADFORM(R, U, beta, E));
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
  C_173_A = MASSTOR_LIST1(MASSTOR_LIST1(1));
  W = SACLIST_LIST3(SACLIST_LIST3(1, 1, 1), SACLIST_LIST3(-1, 0, 1), SACLIST_LIST3(1, 0, 1));
  RRINT_RRIVARMATRICES(G, R, U, beta, &al, &L);
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
    RRINT_RRIPOLMATRIX(R, h, a, al, &mh, &L);
    N = RRADOM_RRVTEXT(N, SACLIST_LIST3(-1, 0, 1));
    C_173_A = LINALG_IMRTPROD(W, C_173_A);
    S1 = MASSTOR_SIL;
    S2 = MASSTOR_SIL;
    m1 = MASSTOR_SIL;
    m2 = MASSTOR_SIL;
    m0 = m;
    while (m0 != MASSTOR_SIL) {
      MASSTOR_ADV(m0, &md, &m0);
      md = LINALGI_IMPROD(md, mh);
      m1 = MASSTOR_COMP(md, m1);
      s = LINALG_ISIG(RRINT_RRIQUADFORM(R, U, beta, md));
      S1 = MASSTOR_COMP(s, S1);
      md = LINALGI_IMPROD(md, mh);
      m2 = MASSTOR_COMP(md, m2);
      s = LINALG_ISIG(RRINT_RRIQUADFORM(R, U, beta, md));
      S2 = MASSTOR_COMP(s, S2);
    }
    S = SACLIST_CONC(S, SACLIST_CONC(MASSTOR_INV(S1), MASSTOR_INV(S2)));
    m = SACLIST_CONC(m, SACLIST_CONC(MASSTOR_INV(m1), MASSTOR_INV(m2)));
    ZNL = RRADOM_RRCSR(i, v, tf, &C_173_A, &N, &S, &m);
  } while (!(ZNL == MASSTOR_SIL || H == MASSTOR_SIL));
  return ZNL;
}

void BEGIN_RRINT()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASI();
    BEGIN_SACI();
    BEGIN_DIPI();
    BEGIN_DIPC();
    BEGIN_LINALGI();
    BEGIN_LINALGRN();
    BEGIN_LINALG();
    BEGIN_RRADOM();

  }
}
