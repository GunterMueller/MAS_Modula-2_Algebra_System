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

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_LINALG
#include "LINALG.h"
#endif

#ifndef DEFINITION_RRADOM
#include "RRADOM.h"
#endif

#ifndef DEFINITION_RRUADOM
#include "RRUADOM.h"
#endif

CHAR RRUADOM_rcsid [] = "$Id: RRUADOM.md,v 1.1 1994/03/11 15:21:51 pesch Exp $";
CHAR RRUADOM_copyright [] = "Copyright (c) 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: RRUADOM.mi,v 1.1 1994/03/11 15:21:52 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";


MASSTOR_LIST RRUADOM_RRUADPOLTOVEC
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST g, MASSTOR_LIST d)
# else
(D, g, d)
MASSTOR_LIST D, g, d;
# endif
{
  MASSTOR_LIST v, a, t;

  v = MASSTOR_SIL;
  d = d - 1;
  while (g != 0) {
    DIPC_DIPMAD(g, &a, &t, &g);
    if (g == MASSTOR_SIL) {
      g = 0;
    }
    while (d > MASSTOR_FIRST(t)) {
      v = MASSTOR_COMP(MASADOM_ADFI(D, 0), v);
      d = d - 1;
    }
    v = MASSTOR_COMP(a, v);
    d = d - 1;
  }
  while (d >= 0) {
    v = MASSTOR_COMP(MASADOM_ADFI(D, 0), v);
    d = d - 1;
  }
  return MASSTOR_INV(v);
}

MASSTOR_LIST RRUADOM_RRUADSTRCONST
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST f, MASSTOR_LIST h)
# else
(D, f, h)
MASSTOR_LIST D, f, h;
# endif
{
  MASSTOR_LIST beta, p, i, v, w, b, q, r;

  beta = MASSTOR_SIL;
  p = DIPC_DIPDEG(f);
  if (p <= 0) {
    return beta;
  }
  DIPADOM_DIPQR(h, f, &q, &r);
  v = RRUADOM_RRUADPOLTOVEC(D, DIPADOM_DIPNEG(DIPC_DIPMRD(f)), p);
  w = RRUADOM_RRUADPOLTOVEC(D, r, p);
  beta = MASSTOR_LIST1(SACLIST_CINV(w));
  {
    LONGINT B_1 = 1, B_2 = 3 * p - 3;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        MASSTOR_ADV(w, &b, &w);
        w = SACLIST_SUFFIX(w, MASADOM_ADFI(D, 0));
        if (MASADOM_ADSIGN(b) != 0) {
          w = LINALG_ADVVSUM(w, LINALG_ADVSVPROD(v, b));
        }
        beta = MASSTOR_COMP(SACLIST_CINV(w), beta);
        if (i >= B_2) break;
      }
  }
  beta = MASSTOR_INV(beta);
  return beta;
}

MASSTOR_LIST RRUADOM_RRUADQUADFORM
# ifdef __STDC__
(MASSTOR_LIST beta)
# else
(beta)
MASSTOR_LIST beta;
# endif
{
  MASSTOR_LIST Q, s, v, vs, w, x, y, i, p;

  Q = MASSTOR_SIL;
  s = MASSTOR_SIL;
  if (beta == MASSTOR_SIL) {
    return Q;
  }
  p = MASSTOR_LENGTH(MASSTOR_FIRST(beta));
  i = 0;
  vs = MASSTOR_SIL;
  while (beta != MASSTOR_SIL) {
    MASSTOR_ADV(beta, &w, &beta);
    i = i + 1;
    v = MASSTOR_INV(vs);
    if (i >= 2 * p) {
      w = SACLIST_REDUCT(w, i + 1 - 2 * p);
      vs = MASSTOR_SIL;
    } else {
      MASSTOR_ADV(w, &y, &w);
      vs = MASSTOR_LIST1(y);
    }
    while (v != MASSTOR_SIL) {
      MASSTOR_ADV(v, &x, &v);
      MASSTOR_ADV(w, &y, &w);
      vs = MASSTOR_COMP(MASADOM_ADSUM(x, y), vs);
    }
    if (i >= p) {
      MASSTOR_ADV(vs, &x, &vs);
      s = MASSTOR_COMP(x, s);
    }
  }
  v = MASSTOR_SIL;
  i = 0;
  while (s != MASSTOR_SIL) {
    MASSTOR_ADV(s, &x, &s);
    i = i + 1;
    vs = MASSTOR_SIL;
    while (v != MASSTOR_SIL) {
      MASSTOR_ADV(v, &y, &v);
      y = MASSTOR_COMP(x, y);
      vs = MASSTOR_COMP(y, vs);
    }
    if (i <= p) {
      vs = MASSTOR_COMP(MASSTOR_LIST1(x), vs);
    }
    v = MASSTOR_INV(vs);
    if (i >= p) {
      MASSTOR_ADV(v, &y, &v);
      Q = MASSTOR_COMP(y, Q);
    }
  }
  return Q;
}

MASSTOR_LIST RRUADOM_RRUADCOUNT
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST f, MASSTOR_LIST H, MASSTOR_LIST v, MASSTOR_LIST tf)
# else
(D, f, H, v, tf)
MASSTOR_LIST D, f, H, v, tf;
# endif
{
  MASSTOR_LIST ZNL, e, S, S1, S2, g, g0, g1, g2, gd, q, h, N, C_109_A, W, s, i;

  e = DIPC_DIPFMO(MASADOM_ADFI(D, 1), MASSTOR_LIST1(0));
  s = LINALG_ADSIG(D, RRUADOM_RRUADQUADFORM(RRUADOM_RRUADSTRCONST(D, f, e)));
  if (s == 0) {
    return MASSTOR_SIL;
  }
  if (H == MASSTOR_SIL) {
    ZNL = MASSTOR_LIST1(SACLIST_LIST2(s, MASSTOR_SIL));
    return ZNL;
  }
  S = MASSTOR_LIST1(s);
  g = MASSTOR_LIST1(e);
  N = MASSTOR_LIST1(MASSTOR_SIL);
  C_109_A = MASSTOR_LIST1(MASSTOR_LIST1(1));
  W = SACLIST_LIST3(SACLIST_LIST3(1, 1, 1), SACLIST_LIST3(-1, 0, 1), SACLIST_LIST3(1, 0, 1));
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
    N = RRADOM_RRVTEXT(N, SACLIST_LIST3(-1, 0, 1));
    C_109_A = LINALG_IMRTPROD(W, C_109_A);
    S1 = MASSTOR_SIL;
    S2 = MASSTOR_SIL;
    g1 = MASSTOR_SIL;
    g2 = MASSTOR_SIL;
    g0 = g;
    while (g0 != MASSTOR_SIL) {
      MASSTOR_ADV(g0, &gd, &g0);
      DIPADOM_DIPQR(DIPADOM_DIPROD(gd, h), f, &q, &gd);
      g1 = MASSTOR_COMP(gd, g1);
      s = LINALG_ADSIG(D, RRUADOM_RRUADQUADFORM(RRUADOM_RRUADSTRCONST(D, f, gd)));
      S1 = MASSTOR_COMP(s, S1);
      DIPADOM_DIPQR(DIPADOM_DIPROD(gd, h), f, &q, &gd);
      g2 = MASSTOR_COMP(gd, g2);
      s = LINALG_ADSIG(D, RRUADOM_RRUADQUADFORM(RRUADOM_RRUADSTRCONST(D, f, gd)));
      S2 = MASSTOR_COMP(s, S2);
    }
    S = SACLIST_CONC(S, SACLIST_CONC(MASSTOR_INV(S1), MASSTOR_INV(S2)));
    g = SACLIST_CONC(g, SACLIST_CONC(MASSTOR_INV(g1), MASSTOR_INV(g2)));
    ZNL = RRADOM_RRCSR(i, v, tf, &C_109_A, &N, &S, &g);
  } while (!(ZNL == MASSTOR_SIL || H == MASSTOR_SIL));
  return ZNL;
}

void BEGIN_RRUADOM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_DIPC();
    BEGIN_DIPADOM();
    BEGIN_MASBIOS();
    BEGIN_MASADOM();
    BEGIN_LINALG();
    BEGIN_RRADOM();

  }
}
