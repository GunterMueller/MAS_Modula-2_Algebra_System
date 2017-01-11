#include "SYSTEM_.h"

#ifndef DEFINITION_ADTOOLS
#include "ADTOOLS.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

CHAR DIPTOOLS_rcsid [] = "$Id: DIPTOOLS.md,v 1.5 1995/11/04 17:59:56 pesch Exp $";
CHAR DIPTOOLS_copyright [] = "Copyright (c) 1989 - 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPTOOLS.mi,v 1.5 1995/11/04 17:59:58 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1994 Universitaet Passau";
static MASSTOR_LIST EvordStack;
static MASSTOR_LIST ValisStack;


MASSTOR_LIST DIPTOOLS_VVECFVLIST
# ifdef __STDC__
(MASSTOR_LIST v1, MASSTOR_LIST v2)
# else
(v1, v2)
MASSTOR_LIST v1, v2;
# endif
{
  MASSTOR_LIST v, r;

  r = MASSTOR_SIL;
  while (v2 != MASSTOR_SIL) {
    MASSTOR_ADV(v2, &v, &v2);
    if (SACLIST_MEMBER(v, v1) == 1) {
      r = MASSTOR_COMP(1, r);
    } else {
      r = MASSTOR_COMP(0, r);
    }
  }
  return r;
}

MASSTOR_LIST DIPTOOLS_VVECC
# ifdef __STDC__
(MASSTOR_LIST v)
# else
(v)
MASSTOR_LIST v;
# endif
{
  MASSTOR_LIST u, r;

  r = MASSTOR_SIL;
  while (v != MASSTOR_SIL) {
    MASSTOR_ADV(v, &u, &v);
    if (u == 1) {
      r = MASSTOR_COMP(0, r);
    } else {
      r = MASSTOR_COMP(1, r);
    }
  }
  return MASSTOR_INV(r);
}

MASSTOR_LIST DIPTOOLS_DIPONE
# ifdef __STDC__
(MASSTOR_LIST d)
# else
(d)
MASSTOR_LIST d;
# endif
{
  INTEGER i;
  MASSTOR_LIST zev;

  zev = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = MASSTOR_LENGTH(DIPC_VALIS);

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        zev = MASSTOR_COMP(0, zev);
        if (i >= B_2) break;
      }
  }
  return DIPC_DIPFMO(MASADOM_ADFI(d, 1), zev);
}

MASSTOR_LIST DIPTOOLS_ADDDFDIP
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST coefficient, ev, C_120_dummy;

  if (p == 0) {
    return 0;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_120_dummy);
  return MASADOM_ADFI(coefficient, 0);
}

MASSTOR_LIST DIPTOOLS_ADDDFDIPD
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST d)
# else
(p, d)
MASSTOR_LIST p, d;
# endif
{
  MASSTOR_LIST coefficient, ev, C_119_dummy;

  if (p == 0) {
    return d;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_119_dummy);
  return MASADOM_ADFI(coefficient, 0);
}

MASSTOR_LIST DIPTOOLS_ADDDFDIL
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  MASSTOR_LIST p, coefficient, ev, C_118_dummy;

  if (l == MASSTOR_SIL) {
    return 0;
  }
  do {
    MASSTOR_ADV(l, &p, &l);
  } while (!(l == MASSTOR_SIL || p != 0));
  if (p == MASSTOR_SIL) {
    return 0;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_118_dummy);
  return MASADOM_ADFI(coefficient, 0);
}

MASSTOR_LIST DIPTOOLS_ADDDFDILD
# ifdef __STDC__
(MASSTOR_LIST l, MASSTOR_LIST d)
# else
(l, d)
MASSTOR_LIST l, d;
# endif
{
  MASSTOR_LIST p, coefficient, ev, C_117_dummy;

  if (l == MASSTOR_SIL) {
    return d;
  }
  do {
    MASSTOR_ADV(l, &p, &l);
  } while (!(l == MASSTOR_SIL || p != 0));
  if (p == MASSTOR_SIL) {
    return d;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_117_dummy);
  return MASADOM_ADFI(coefficient, 0);
}

MASSTOR_LIST DIPTOOLS_ADDNFDIP
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST coefficient, ev, C_116_dummy;

  if (p == 0) {
    return 0;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_116_dummy);
  return MASSTOR_FIRST(coefficient);
}

MASSTOR_LIST DIPTOOLS_ADDNFDIPD
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST d)
# else
(p, d)
MASSTOR_LIST p, d;
# endif
{
  MASSTOR_LIST coefficient, ev, C_115_dummy;

  if (p == 0) {
    return d;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_115_dummy);
  return MASSTOR_FIRST(coefficient);
}

MASSTOR_LIST DIPTOOLS_ADDNFDIL
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  MASSTOR_LIST p, coefficient, ev, C_114_dummy;

  if (l == MASSTOR_SIL) {
    return 0;
  }
  do {
    MASSTOR_ADV(l, &p, &l);
  } while (!(l == MASSTOR_SIL || p != 0));
  if (p == MASSTOR_SIL) {
    return 0;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_114_dummy);
  return MASSTOR_FIRST(coefficient);
}

MASSTOR_LIST DIPTOOLS_ADDNFDILD
# ifdef __STDC__
(MASSTOR_LIST l, MASSTOR_LIST d)
# else
(l, d)
MASSTOR_LIST l, d;
# endif
{
  MASSTOR_LIST p, coefficient, ev, C_113_dummy;

  if (l == MASSTOR_SIL) {
    return d;
  }
  do {
    MASSTOR_ADV(l, &p, &l);
  } while (!(l == MASSTOR_SIL || p != 0));
  if (p == MASSTOR_SIL) {
    return d;
  }
  DIPC_DIPMAD(p, &coefficient, &ev, &C_113_dummy);
  return MASSTOR_FIRST(coefficient);
}

MASSTOR_LIST DIPTOOLS_DIPPOWER
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST n)
# else
(p, n)
MASSTOR_LIST p, n;
# endif
{
  MASSTOR_LIST result, d;
  MASSTOR_LIST domain;

  if (p == 0) {
    return 0;
  }
  domain = DIPTOOLS_ADDDFDIP(p);
  result = DIPTOOLS_DIPONE(domain);
  d = p;
  while (n > 0) {
    while (n % 2 == 0) {
      d = DIPADOM_DIPROD(d, d);
      n = n / 2;
    }
    result = DIPADOM_DIPROD(result, d);
    n = n - 1;
  }
  return result;
}

MASSTOR_LIST DIPTOOLS_DILPROD
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST domain)
# else
(L, domain)
MASSTOR_LIST L;
MASSTOR_LIST domain;
# endif
{
  MASSTOR_LIST p, result;

  if (L == MASSTOR_SIL) {
    return DIPTOOLS_DIPONE(domain);
  }
  MASSTOR_ADV(L, &result, &L);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    if (p == 0) {
      return 0;
    }
    result = DIPADOM_DIPROD(result, p);
  }
  return result;
}

MASSTOR_LIST DIPTOOLS_DIPDEGI
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST i)
# else
(p, i)
MASSTOR_LIST p, i;
# endif
{
  MASSTOR_LIST result, c, e, md, pos, C_112_dummy;

  if (p == 0 || p == MASSTOR_SIL) {
    return 0;
  }
  DIPC_DIPMAD(p, &c, &e, &p);
  pos = MASSTOR_LENGTH(e) - i + 1;
  result = SACLIST_LELT(e, pos);
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &e, &p);
    md = SACLIST_LELT(e, pos);
    if (md > result) {
      result = md;
    }
  }
  return result;
}

MASSTOR_LIST DIPTOOLS_DILMOC
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST p, r;

  r = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    p = DIPADOM_DIPMOC(p);
    if (SACLIST_MEMBER(p, r) == 0) {
      r = MASSTOR_COMP(DIPADOM_DIPMOC(p), r);
    }
  }
  return MASSTOR_INV(r);
}

MASSTOR_LIST DIPTOOLS_DIPPAD
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST i)
# else
(p, i)
MASSTOR_LIST p, i;
# endif
{
  MASSTOR_LIST c, ev, m, result;

  if (p == 0) {
    return 0;
  }
  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &ev, &p);
    m = DIPTOOLS_DIMPAD(c, ev, i);
    if (m != 0) {
      result = DIPC_DIPMCP(SACLIST_SECOND(m), MASSTOR_FIRST(m), result);
    }
  }
  return DIPTOOLS_DIPIMO(result);
}

MASSTOR_LIST DIPTOOLS_DIMPAD
# ifdef __STDC__
(MASSTOR_LIST c, MASSTOR_LIST ev, MASSTOR_LIST i)
# else
(c, ev, i)
MASSTOR_LIST c, ev, i;
# endif
{
  MASSTOR_LIST e, ep, cp, j;

  ep = MASSTOR_SIL;
  ev = SACLIST_CINV(ev);
  {
    LONGINT B_3 = 1, B_4 = i - 1;

    if (B_3 <= B_4)
      for (j = B_3;; j += 1) {
        MASSTOR_ADV(ev, &e, &ev);
        ep = MASSTOR_COMP(e, ep);
        if (j >= B_4) break;
      }
  }
  MASSTOR_ADV(ev, &e, &ev);
  if (e > 0) {
    cp = MASADOM_ADPROD(c, MASADOM_ADFI(c, e));
    ep = MASSTOR_COMP(e - 1, ep);
  } else {
    return 0;
  }
  while (ev != MASSTOR_SIL) {
    MASSTOR_ADV(ev, &e, &ev);
    ep = MASSTOR_COMP(e, ep);
  }
  return SACLIST_LIST2(ep, cp);
}

void DIPTOOLS_DIPCPP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST *content, MASSTOR_LIST *ppt)
# else
(p, content, ppt)
MASSTOR_LIST p;
MASSTOR_LIST *content, *ppt;
# endif
{
  MASSTOR_LIST pp, q, c, e, revert, hcsign;

  if (p == 0) {
    *content = 0;
    *ppt = 0;
    return;
  }
  pp = p;
  DIPC_DIPMAD(pp, content, &e, &pp);
  hcsign = MASADOM_ADSIGN(*content);
  while (pp != MASSTOR_SIL && MASADOM_ADONE(*content) != 1) {
    DIPC_DIPMAD(pp, &c, &e, &pp);
    *content = MASADOM_ADGCD(*content, c);
  }
  if (MASADOM_ADSIGN(*content) != hcsign) {
    *content = MASADOM_ADNEG(*content);
  }
  if (MASADOM_ADONE(*content) == 1) {
    *ppt = p;
    return;
  }
  pp = p;
  q = MASSTOR_SIL;
  while (pp != MASSTOR_SIL) {
    DIPC_DIPMAD(pp, &c, &e, &pp);
    c = MASADOM_ADQUOT(c, *content);
    q = DIPC_DIPMCP(c, e, q);
  }
  *ppt = DIPTOOLS_DIPIMO(q);
  return;
}

void DIPTOOLS_DIPPCPP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST *content, MASSTOR_LIST *ppt)
# else
(p, content, ppt)
MASSTOR_LIST p;
MASSTOR_LIST *content, *ppt;
# endif
{
  MASSTOR_LIST pp, q, c, e, revert, hcsign;

  if (p == 0) {
    *content = 0;
    *ppt = 0;
    return;
  }
  pp = p;
  DIPC_DIPMAD(pp, content, &e, &pp);
  if (MASADOM_ADONE(*content) == 1) {
    *ppt = p;
    return;
  }
  pp = p;
  q = MASSTOR_SIL;
  while (pp != MASSTOR_SIL) {
    DIPC_DIPMAD(pp, &c, &e, &pp);
    c = MASADOM_ADQUOT(c, *content);
    q = DIPC_DIPMCP(c, e, q);
  }
  *ppt = DIPTOOLS_DIPIMO(q);
  return;
}

BOOLEAN DIPTOOLS_DIPCNST
# ifdef __STDC__
(MASSTOR_LIST dip)
# else
(dip)
MASSTOR_LIST dip;
# endif
{
  MASSTOR_LIST e, c, r;

  if (dip == 0) {
    return TRUE;
  }
  SACLIST_ADV2(dip, &e, &c, &r);
  if (r != MASSTOR_SIL) {
    return FALSE;
  }
  if (DIPC_EVSIGN(e) == 0) {
    return TRUE;
  }
  return FALSE;
}

BOOLEAN DIPTOOLS_DIPCNSTR
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST v)
# else
(p, v)
MASSTOR_LIST p, v;
# endif
{
  MASSTOR_LIST c, e, f, ei, vi, vp;

  if (p == 0) {
    return TRUE;
  }
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &e, &p);
    vp = v;
    while (e != MASSTOR_SIL) {
      MASSTOR_ADV(e, &ei, &e);
      MASSTOR_ADV(vp, &vi, &vp);
      if (vi == 1 && ei != 0) {
        return FALSE;
      }
    }
  }
  return TRUE;
}

BOOLEAN DIPTOOLS_EVCNSTR
# ifdef __STDC__
(MASSTOR_LIST ev, MASSTOR_LIST mvars)
# else
(ev, mvars)
MASSTOR_LIST ev, mvars;
# endif
{
  MASSTOR_LIST e, m;

  while (ev != MASSTOR_SIL) {
    MASSTOR_ADV(ev, &e, &ev);
    MASSTOR_ADV(mvars, &m, &mvars);
    if (mvars == 1 && e != 0) {
      return FALSE;
    }
  }
  return TRUE;
}

void DIPTOOLS_EvordPush
# ifdef __STDC__
(MASSTOR_LIST evord)
# else
(evord)
MASSTOR_LIST evord;
# endif
{
  EvordStack = MASSTOR_COMP(DIPC_EVORD, EvordStack);
  DIPC_EVORD = evord;
  return;
}

void DIPTOOLS_EvordPop
# ifdef __STDC__
()
# else
()
# endif
{
  if (EvordStack == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "EvordPop: pop to empty stack", 28L);
  } else {
    MASSTOR_ADV(EvordStack, &DIPC_EVORD, &EvordStack);
  }
}

void DIPTOOLS_ValisPush
# ifdef __STDC__
(MASSTOR_LIST valis)
# else
(valis)
MASSTOR_LIST valis;
# endif
{
  ValisStack = MASSTOR_COMP(DIPC_VALIS, ValisStack);
  DIPC_VALIS = valis;
  return;
}

void DIPTOOLS_ValisPop
# ifdef __STDC__
()
# else
()
# endif
{
  if (ValisStack == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "ValisPop: pop to empty stack", 28L);
  } else {
    MASSTOR_ADV(ValisStack, &DIPC_VALIS, &ValisStack);
  }
}

MASSTOR_LIST DIPTOOLS_DILINV
# ifdef __STDC__
(MASSTOR_LIST dil, MASSTOR_LIST j, MASSTOR_LIST k)
# else
(dil, j, k)
MASSTOR_LIST dil, j, k;
# endif
{
  MASSTOR_LIST dip, result;

  result = MASSTOR_SIL;
  while (dil != MASSTOR_SIL) {
    MASSTOR_ADV(dil, &dip, &dil);
    result = MASSTOR_COMP(DIPC_DIPINV(dip, j, k), result);
  }
  return MASSTOR_INV(result);
}

void DIPTOOLS_DIPFDIPP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST NewDd, MASSTOR_LIST *q, MASSTOR_LIST *vlist)
# else
(p, NewDd, q, vlist)
MASSTOR_LIST p, NewDd;
MASSTOR_LIST *q, *vlist;
# endif
{
  MASSTOR_LIST coeff, exp, C_111_dummy, pp, r, result;
  MASSTOR_LIST c, e;

  if (p == 0) {
    *q = 0;
    *vlist = MASSTOR_SIL;
    return;
  }
  DIPC_DIPMAD(p, &coeff, &exp, &C_111_dummy);
  *vlist = SACLIST_FOURTH(coeff);
  *vlist = SACLIST_CCONC(*vlist, MASSTOR_INV(SACLIST_CINV(DIPC_VALIS)));
  r = SACLIST_THIRD(coeff);
  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &exp, &p);
    coeff = DIPC_DIPFP(r, ADTOOLS_ADRMDD(coeff));
    DIPC_DIPBSO(coeff);
    pp = DIPTOOLS_EVEXT(coeff, exp);
    while (pp != MASSTOR_SIL) {
      DIPC_DIPMAD(pp, &c, &e, &pp);
      result = DIPC_DIPMCP(c, e, result);
    }
  }
  result = DIPTOOLS_ADPFDIP(result, NewDd);
  DIPC_DIPBSO(result);
  *q = result;
  return;
}

MASSTOR_LIST DIPTOOLS_EVEXT
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST evx)
# else
(p, evx)
MASSTOR_LIST p, evx;
# endif
{
  MASSTOR_LIST coeff, ev, result;

  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &ev, &p);
    result = DIPC_DIPMCP(coeff, SACLIST_CCONC(evx, ev), result);
  }
  DIPC_DIPBSO(result);
  return result;
}

MASSTOR_LIST DIPTOOLS_ADPFDIP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST dd)
# else
(p, dd)
MASSTOR_LIST p, dd;
# endif
{
  MASSTOR_LIST result, coeff, ev;

  if (p == 0) {
    return 0;
  }
  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &ev, &p);
    result = DIPC_DIPMCP(ADTOOLS_ADCAST(coeff, dd), ev, result);
  }
  return DIPTOOLS_DIPIMO(result);
}

void DIPTOOLS_DIPPFDIP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST r, MASSTOR_LIST NewDd, MASSTOR_LIST *q, MASSTOR_LIST *vlist)
# else
(p, r, NewDd, q, vlist)
MASSTOR_LIST p, r, NewDd;
MASSTOR_LIST *q, *vlist;
# endif
{
  MASSTOR_LIST result, cvlist, v, coeff, ev, RCpol, NewEv;
  INTEGER i;

  if (p == 0) {
    *q = 0;
    *vlist = MASSTOR_SIL;
    return;
  }
  *vlist = MASSTOR_INV(SACLIST_CINV(DIPC_VALIS));
  cvlist = MASSTOR_SIL;
  {
    LONGINT B_5 = 1, B_6 = r;

    if (B_5 <= B_6)
      for (i = B_5;; i += 1) {
        MASSTOR_ADV(*vlist, &v, vlist);
        cvlist = MASSTOR_COMP(v, cvlist);
        if (i >= B_6) break;
      }
  }
  cvlist = MASSTOR_INV(cvlist);
  r = MASSTOR_LENGTH(cvlist);
  result = MASSTOR_SIL;
  *q = 0;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &ev, &p);
    DIPTOOLS_MPPFMP(ADTOOLS_ADRMDD(coeff), ev, r, &RCpol, &NewEv);
    RCpol = ADTOOLS_ADCAST(RCpol, NewDd);
    result = MASSTOR_SIL;
    *q = DIPADOM_DIPSUM(*q, DIPC_DIPMCP(RCpol, NewEv, MASSTOR_SIL));
  }
  DIPC_DIPBSO(*q);
  return;
}

void DIPTOOLS_MPPFMP
# ifdef __STDC__
(MASSTOR_LIST Coeff, MASSTOR_LIST Ev, MASSTOR_LIST r, MASSTOR_LIST *RCpol, MASSTOR_LIST *NewEv)
# else
(Coeff, Ev, r, RCpol, NewEv)
MASSTOR_LIST Coeff, Ev, r;
MASSTOR_LIST *RCpol, *NewEv;
# endif
{
  MASSTOR_LIST CoeffEv, C_110_dummy, Cpol, e;
  INTEGER i;

  *NewEv = SACLIST_CINV(Ev);
  CoeffEv = MASSTOR_SIL;
  {
    LONGINT B_7 = 1, B_8 = r;

    if (B_7 <= B_8)
      for (i = B_7;; i += 1) {
        MASSTOR_ADV(*NewEv, &e, NewEv);
        CoeffEv = MASSTOR_COMP(e, CoeffEv);
        if (i >= B_8) break;
      }
  }
  *NewEv = MASSTOR_INV(*NewEv);
  Cpol = MASSTOR_SIL;
  Cpol = DIPC_DIPMCP(Coeff, CoeffEv, Cpol);
  DIPTOOLS_EvordPush(DIPC_INVLEX);
  DIPC_PFDIP(Cpol, &C_110_dummy, RCpol);
  DIPTOOLS_EvordPop();
  return;
}

MASSTOR_LIST DIPTOOLS_DIPCONV
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST E)
# else
(p, E)
MASSTOR_LIST p, E;
# endif
{
  MASSTOR_LIST coeff, exp, result;

  if (p == 0) {
    return 0;
  }
  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &exp, &p);
    coeff = MASADOM_ADCONV(E, coeff);
    result = DIPC_DIPMCP(coeff, exp, result);
  }
  return DIPTOOLS_DIPIMO(result);
}

MASSTOR_LIST DIPTOOLS_DILCONV
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST E)
# else
(P, E)
MASSTOR_LIST P, E;
# endif
{
  MASSTOR_LIST p, r;

  r = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    r = MASSTOR_COMP(DIPTOOLS_DIPCONV(p, E), r);
  }
  return MASSTOR_INV(r);
}

MASSTOR_LIST DIPTOOLS_DIPFADIP
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST d, q, qp, r, m, e, vl;

  ADTOOLS_IPDDADV(p, &q, &r, &vl);
  return DIPTOOLS_DIPFIP(q, r);
}

MASSTOR_LIST DIPTOOLS_DIPFIP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST r)
# else
(p, r)
MASSTOR_LIST p, r;
# endif
{
  MASSTOR_LIST d, qp, m, e, vl;

  p = DIPC_DIPFP(r, p);
  if (p == 0) {
    return 0;
  }
  qp = MASSTOR_SIL;
  d = ADTOOLS_INTDDCMP();
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &m, &e, &p);
    qp = DIPC_DIPMCP(MASADOM_ADFI(d, m), e, qp);
  }
  DIPC_DIPBSO(qp);
  return qp;
}

MASSTOR_LIST DIPTOOLS_DILPFDIL
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST r, MASSTOR_LIST newdd)
# else
(L, r, newdd)
MASSTOR_LIST L, r, newdd;
# endif
{
  MASSTOR_LIST p, vl, res;

  res = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    DIPTOOLS_DIPPFDIP(p, r, newdd, &p, &vl);
    res = MASSTOR_COMP(p, res);
  }
  return MASSTOR_INV(res);
}

MASSTOR_LIST DIPTOOLS_DILFDILP
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST NewDd)
# else
(L, NewDd)
MASSTOR_LIST L, NewDd;
# endif
{
  MASSTOR_LIST vl, q, p, result;

  result = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &p, &L);
    DIPTOOLS_DIPFDIPP(p, NewDd, &q, &vl);
    result = MASSTOR_COMP(q, result);
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST DIPTOOLS_DIPCT
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST C_108_A, i, j, coeff, exp, C_109_dummy, deg, perm, zero;

  if (p == 0) {
    return MASSTOR_SIL;
  }
  DIPC_DIPMAD(p, &coeff, &exp, &C_109_dummy);
  deg = MASSTOR_FIRST(exp);
  zero = MASADOM_ADFI(coeff, 0);
  C_108_A = MASSTOR_SIL;
  i = deg;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &coeff, &exp, &p);
    exp = MASSTOR_FIRST(exp);
    while (exp < i) {
      i = i - 1;
      C_108_A = MASSTOR_COMP(zero, C_108_A);
    }
    C_108_A = MASSTOR_COMP(coeff, C_108_A);
    i = i - 1;
  }
  for (j = i; j >= 0; j += -1) {
    C_108_A = MASSTOR_COMP(zero, C_108_A);
  }
  return C_108_A;
}

MASSTOR_LIST DIPTOOLS_DIPIMO
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST r, h;

  if (p == 0) {
    return 0;
  }
  r = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    h = SACLIST_RED2(p);
    MASSTOR_SRED(MASSTOR_RED(p), r);
    r = p;
    p = h;
  }
  return r;
}

MASSTOR_LIST DIPTOOLS_DILIMO
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST p, r;

  r = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    r = MASSTOR_COMP(p, r);
  }
  return MASSTOR_INV(r);
}

MASSTOR_LIST DIPTOOLS_DIPXCM
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST mvars)
# else
(p, mvars)
MASSTOR_LIST p, mvars;
# endif
{
  MASSTOR_LIST result, c, e;

  if (p == 0) {
    return 0;
  }
  result = MASSTOR_SIL;
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &e, &p);
    if (DIPTOOLS_EVCNSTR(e, mvars)) {
      result = DIPC_DIPMCP(result, c, e);
    }
  }
  return DIPTOOLS_DIPIMO(result);
}

MASSTOR_LIST DIPTOOLS_DIPMVV
# ifdef __STDC__
(MASSTOR_LIST p)
# else
(p)
MASSTOR_LIST p;
# endif
{
  MASSTOR_LIST c, e, ev, v, vv, i, result;

  if (p == 0) {
    return MASSTOR_SIL;
  }
  result = MASSTOR_SIL;
  {
    LONGINT B_9 = 1, B_10 = DIPC_DIPNOV(p);

    if (B_9 <= B_10)
      for (i = B_9;; i += 1) {
        result = MASSTOR_COMP(0, result);
        if (i >= B_10) break;
      }
  }
  while (p != MASSTOR_SIL) {
    DIPC_DIPMAD(p, &c, &ev, &p);
    i = 0;
    vv = result;
    while (ev != MASSTOR_SIL) {
      i = i + 1;
      MASSTOR_ADV(vv, &v, &vv);
      MASSTOR_ADV(ev, &e, &ev);
      if (e != 0 && v != 1) {
        SACLIST_SLELT(result, i, 1);
      }
    }
  }
  return result;
}

void BEGIN_DIPTOOLS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_ADTOOLS();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();

    MASSTOR_LISTVAR(&ValisStack);
    ValisStack = MASSTOR_SIL;
    MASSTOR_LISTVAR(&EvordStack);
    EvordStack = MASSTOR_SIL;
  }
}
