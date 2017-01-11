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

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPDDGB
#include "DIPDDGB.h"
#endif


static CHAR rcsidi [] = "$Id: DIPDDGB.mi,v 1.2 1994/03/11 15:54:04 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1993 Universitaet Passau";
static MASSTOR_LIST crit1 ARGS((MASSTOR_LIST pair));
static MASSTOR_LIST crit2 ARGS((MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK));
static MASSTOR_LIST crit3 ARGS((MASSTOR_LIST AL, MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK));


MASSTOR_LIST DIPDDGB_DIDPELIMDGB
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST Pr, Pf, Qr, Qf, Q, Qv, Qd, HTPf, HTQf, HKPf, HKQf;

  Q = MASSTOR_SIL;
  if (P == MASSTOR_SIL) {
    return Q;
  }
  if (MASSTOR_RED(P) == MASSTOR_SIL) {
    return P;
  }
  Pr = P;
  for (;;) {
    MASSTOR_ADV(Pr, &Pf, &Pr);
    if (Q == MASSTOR_SIL) {
      Q = MASSTOR_LIST1(Pf);
      if (Pr == MASSTOR_SIL) {
        return Q;
      }
      MASSTOR_ADV(Pr, &Pf, &Pr);
    }
    HTPf = DIPC_DIPEVL(Pf);
    HKPf = DIPC_DIPLBC(Pf);
    Qr = Q;
    for (;;) {
      Qv = Qr;
      MASSTOR_ADV(Qr, &Qf, &Qr);
      HTQf = DIPC_DIPEVL(Qf);
      HKQf = DIPC_DIPLBC(Qf);
      if (DIPC_EVMT(HTPf, HTQf) == 1) {
        if (MASADOM_ADSIGN(MASADOM_ADREM(HKPf, HKQf)) == 0) {
          goto EXIT_2;
        }
      }
      if (DIPC_EVMT(HTQf, HTPf) == 1) {
        if (MASADOM_ADSIGN(MASADOM_ADREM(HKQf, HKPf)) == 0) {
          if (Q == Qv) {
            Q = Qr;
          } else {
            Qd = Q;
            while (MASSTOR_RED(Qd) != Qv) {
              Qd = MASSTOR_RED(Qd);
            }
            MASSTOR_SRED(Qd, Qr);
            Qv = Qd;
          }
        }
      }
      if (Qr == MASSTOR_SIL) {
        Q = MASSTOR_COMP(Pf, Q);
        goto EXIT_2;
      }
    } EXIT_2:;
    if (Pr == MASSTOR_SIL) {
      goto EXIT_1;
    }
  } EXIT_1:;
  return Q;
}

MASSTOR_LIST DIPDDGB_DIDPTDR
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST lcmHT, MASSTOR_LIST pair)
# else
(P, lcmHT, pair)
MASSTOR_LIST P, lcmHT, pair;
# endif
{
  MASSTOR_LIST HKg1, HKg2, HKg, HTg, PP, g;

  if (P == MASSTOR_SIL) {
    return 0;
  }
  HKg1 = DIPC_DIPLBC(MASSTOR_FIRST(pair));
  HKg2 = DIPC_DIPLBC(SACLIST_SECOND(pair));
  PP = P;
  do {
    MASSTOR_ADV(PP, &g, &PP);
    HTg = DIPC_DIPEVL(g);
    HKg = DIPC_DIPLBC(g);
    if (DIPC_EVMT(lcmHT, HTg) == 1) {
      if (MASADOM_ADSIGN(MASADOM_ADREM(HKg1, HKg)) == 0 && MASADOM_ADSIGN(MASADOM_ADREM(HKg2, HKg)) == 0) {
        return 1;
      }
    }
  } while (!(PP == MASSTOR_SIL));
  return 0;
}

MASSTOR_LIST DIPDDGB_DIDPCPLMS1
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST onestep, twostep, ret, end, icomp, evcomp;

  if (P == MASSTOR_SIL) {
    return P;
  }
  twostep = MASSTOR_RED(P);
  onestep = P;
  for (;;) {
    if (twostep == MASSTOR_SIL) {
      goto EXIT_3;
    }
    twostep = MASSTOR_RED(twostep);
    if (twostep == MASSTOR_SIL) {
      goto EXIT_3;
    }
    twostep = MASSTOR_RED(twostep);
    onestep = MASSTOR_RED(onestep);
  } EXIT_3:;
  if (MASSTOR_RED(onestep) == MASSTOR_SIL) {
    return onestep;
  }
  twostep = MASSTOR_RED(onestep);
  MASSTOR_SRED(onestep, MASSTOR_SIL);
  onestep = DIPDDGB_DIDPCPLMS1(P);
  twostep = DIPDDGB_DIDPCPLMS1(twostep);
  if (onestep == MASSTOR_SIL) {
    return twostep;
  } else if (twostep == MASSTOR_SIL) {
    return onestep;
  }
  evcomp = DIPC_EVCOMP(MASSTOR_FIRST(MASSTOR_FIRST(onestep)), MASSTOR_FIRST(MASSTOR_FIRST(twostep)));
  if (evcomp == -1) {
    ret = onestep;
    onestep = MASSTOR_RED(onestep);
  } else if (evcomp == 1) {
    ret = twostep;
    twostep = MASSTOR_RED(twostep);
  } else {
    icomp = MASADOM_ADCOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
    if (icomp == -1) {
      ret = onestep;
      onestep = MASSTOR_RED(onestep);
    } else if (icomp == 1) {
      ret = twostep;
      twostep = MASSTOR_RED(twostep);
    } else {
      ret = onestep;
      onestep = MASSTOR_RED(onestep);
    }
  }
  end = ret;
  while (onestep != MASSTOR_SIL && twostep != MASSTOR_SIL) {
    evcomp = DIPC_EVCOMP(MASSTOR_FIRST(MASSTOR_FIRST(onestep)), MASSTOR_FIRST(MASSTOR_FIRST(twostep)));
    if (evcomp == -1) {
      MASSTOR_SRED(end, onestep);
      onestep = MASSTOR_RED(onestep);
    } else if (evcomp == 1) {
      MASSTOR_SRED(end, twostep);
      twostep = MASSTOR_RED(twostep);
    } else {
      icomp = MASADOM_ADCOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
      if (icomp == -1) {
        MASSTOR_SRED(end, onestep);
        onestep = MASSTOR_RED(onestep);
      } else if (icomp == 1) {
        MASSTOR_SRED(end, twostep);
        twostep = MASSTOR_RED(twostep);
      } else {
        MASSTOR_SRED(end, onestep);
        onestep = MASSTOR_RED(onestep);
      }
    }
    end = MASSTOR_RED(end);
  }
  if (onestep == MASSTOR_SIL) {
    MASSTOR_SRED(end, twostep);
  } else {
    MASSTOR_SRED(end, onestep);
  }
  return ret;
}

MASSTOR_LIST DIPDDGB_DIDPLM1
# ifdef __STDC__
(MASSTOR_LIST onestep, MASSTOR_LIST twostep)
# else
(onestep, twostep)
MASSTOR_LIST onestep, twostep;
# endif
{
  MASSTOR_LIST ret, end, icomp, evcomp;

  if (onestep == MASSTOR_SIL) {
    return twostep;
  } else if (twostep == MASSTOR_SIL) {
    return onestep;
  }
  evcomp = DIPC_EVCOMP(MASSTOR_FIRST(MASSTOR_FIRST(onestep)), MASSTOR_FIRST(MASSTOR_FIRST(twostep)));
  if (evcomp == -1) {
    ret = onestep;
    onestep = MASSTOR_RED(onestep);
  } else if (evcomp == 1) {
    ret = twostep;
    twostep = MASSTOR_RED(twostep);
  } else {
    icomp = MASADOM_ADCOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
    if (icomp == -1) {
      ret = onestep;
      onestep = MASSTOR_RED(onestep);
    } else if (icomp == 1) {
      ret = twostep;
      twostep = MASSTOR_RED(twostep);
    } else {
      ret = onestep;
      onestep = MASSTOR_RED(onestep);
    }
  }
  end = ret;
  while (onestep != MASSTOR_SIL && twostep != MASSTOR_SIL) {
    evcomp = DIPC_EVCOMP(MASSTOR_FIRST(MASSTOR_FIRST(onestep)), MASSTOR_FIRST(MASSTOR_FIRST(twostep)));
    if (evcomp == -1) {
      MASSTOR_SRED(end, onestep);
      onestep = MASSTOR_RED(onestep);
    } else if (evcomp == 1) {
      MASSTOR_SRED(end, twostep);
      twostep = MASSTOR_RED(twostep);
    } else {
      icomp = MASADOM_ADCOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
      if (icomp == -1) {
        MASSTOR_SRED(end, onestep);
        onestep = MASSTOR_RED(onestep);
      } else if (icomp == 1) {
        MASSTOR_SRED(end, twostep);
        twostep = MASSTOR_RED(twostep);
      } else {
        MASSTOR_SRED(end, onestep);
        onestep = MASSTOR_RED(onestep);
      }
    }
    end = MASSTOR_RED(end);
  }
  if (onestep == MASSTOR_SIL) {
    MASSTOR_SRED(end, twostep);
  } else {
    MASSTOR_SRED(end, onestep);
  }
  return ret;
}

MASSTOR_LIST DIPDDGB_DIDPUCPL1
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST g, MASSTOR_LIST Old)
# else
(P, g, Old)
MASSTOR_LIST P, g, Old;
# endif
{
  MASSTOR_LIST Update, Up, Upel, Pr, Pf, pair, a1, a2, t1, t2, lcmHT, lcmHK;

  if (P == MASSTOR_SIL) {
    return Old;
  }
  if (g == 0) {
    return Old;
  }
  Up = MASSTOR_SIL;
  t1 = DIPC_DIPEVL(g);
  a1 = DIPC_DIPLBC(g);
  Pr = P;
  do {
    MASSTOR_ADV(Pr, &Pf, &Pr);
    t2 = DIPC_DIPEVL(Pf);
    a2 = DIPC_DIPLBC(Pf);
    lcmHT = DIPC_EVLCM(t1, t2);
    lcmHK = MASADOM_ADLCM(a1, a2);
    pair = SACLIST_LIST2(g, Pf);
    Upel = SACLIST_LIST3(lcmHT, lcmHK, pair);
    Up = MASSTOR_COMP(Upel, Up);
  } while (!(Pr == MASSTOR_SIL));
  Up = DIPDDGB_DIDPCPLMS1(Up);
  if (Old == MASSTOR_SIL) {
    return Up;
  }
  Update = DIPDDGB_DIDPLM1(Up, Old);
  return Update;
}

MASSTOR_LIST DIPDDGB_DIDPGPOL
# ifdef __STDC__
(MASSTOR_LIST g1, MASSTOR_LIST g2)
# else
(g1, g2)
MASSTOR_LIST g1, g2;
# endif
{
  MASSTOR_LIST a1, g1r, g1rp, a2, g2r, g2rp, GPol, gcdHK, t1, s1, t2, s2, c1, c2, lcmHT;

  GPol = 0;
  if (g1 == 0 || g2 == 0) {
    return GPol;
  }
  DIPC_DIPMAD(g1, &a1, &t1, &g1r);
  DIPC_DIPMAD(g2, &a2, &t2, &g2r);
  MASADOM_ADGCDE(a1, a2, &gcdHK, &c1, &c2);
  if (MASADOM_ADSIGN(c1) == 0) {
    lcmHT = DIPC_EVLCM(t1, t2);
    s2 = DIPC_EVDIF(lcmHT, t2);
    g2rp = DIPC_DIPFMO(c2, s2);
    GPol = DIPADOM_DIPROD(g2, g2rp);
    return GPol;
  }
  if (MASADOM_ADSIGN(c2) == 0) {
    lcmHT = DIPC_EVLCM(t1, t2);
    s1 = DIPC_EVDIF(lcmHT, t1);
    g1rp = DIPC_DIPFMO(c1, s1);
    GPol = DIPADOM_DIPROD(g1, g1rp);
    return GPol;
  }
  lcmHT = DIPC_EVLCM(t1, t2);
  s1 = DIPC_EVDIF(lcmHT, t1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  g1rp = DIPC_DIPFMO(c1, s1);
  g2rp = DIPC_DIPFMO(c2, s2);
  g1rp = DIPADOM_DIPROD(g1, g1rp);
  g2rp = DIPADOM_DIPROD(g2, g2rp);
  GPol = DIPADOM_DIPSUM(g1rp, g2rp);
  return GPol;
}

MASSTOR_LIST DIPDDGB_DIDPSPOL2
# ifdef __STDC__
(MASSTOR_LIST g1, MASSTOR_LIST g2, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK)
# else
(g1, g2, lcmHT, lcmHK)
MASSTOR_LIST g1, g2, lcmHT, lcmHK;
# endif
{
  MASSTOR_LIST a1, b1, g1r, g1rp, a2, b2, g2r, g2rp, SPol, t1, s1, t2, s2;

  SPol = 0;
  if (g1 == 0 || g2 == 0) {
    return SPol;
  }
  DIPC_DIPMAD(g1, &a1, &t1, &g1r);
  DIPC_DIPMAD(g2, &a2, &t2, &g2r);
  if (g1r == MASSTOR_SIL && g2r == MASSTOR_SIL) {
    return SPol;
  }
  if (g1r == MASSTOR_SIL) {
    s2 = DIPC_EVDIF(lcmHT, t2);
    b2 = MASADOM_ADQUOT(lcmHK, a2);
    b2 = MASADOM_ADNEG(b2);
    g2rp = DIPC_DIPFMO(b2, s2);
    SPol = DIPADOM_DIPROD(g2r, g2rp);
    return SPol;
  }
  if (g2r == MASSTOR_SIL) {
    s1 = DIPC_EVDIF(lcmHT, t1);
    b1 = MASADOM_ADQUOT(lcmHK, a1);
    g1rp = DIPC_DIPFMO(b1, s1);
    SPol = DIPADOM_DIPROD(g1r, g1rp);
    return SPol;
  }
  s1 = DIPC_EVDIF(lcmHT, t1);
  b1 = MASADOM_ADQUOT(lcmHK, a1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  b2 = MASADOM_ADQUOT(lcmHK, a2);
  g1rp = DIPC_DIPFMO(b1, s1);
  g2rp = DIPC_DIPFMO(b2, s2);
  g1rp = DIPADOM_DIPROD(g1r, g1rp);
  g2rp = DIPADOM_DIPROD(g2r, g2rp);
  SPol = DIPADOM_DIPDIF(g1rp, g2rp);
  return SPol;
}

MASSTOR_LIST DIPDDGB_DIDPLEXTAL
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST g)
# else
(AL, g)
MASSTOR_LIST AL, g;
# endif
{
  MASSTOR_LIST i, j, nulll, gp, Ag;

  if (g == 0) {
    return AL;
  }
  if (AL == MASSTOR_SIL) {
    Ag = MASSTOR_LIST1(SACLIST_LIST2(g, MASSTOR_LIST1(1)));
    return Ag;
  }
  i = MASSTOR_FIRST(SACLIST_SECOND(MASSTOR_FIRST(AL)));
  j = 0;
  nulll = MASSTOR_SIL;
  while (j < i) {
    nulll = MASSTOR_COMP(0, nulll);
    j = j + 1;
  }
  gp = SACLIST_LIST2(g, nulll);
  Ag = AL;
  MASSTOR_SRED(SACLIST_LAST(Ag), MASSTOR_LIST1(gp));
  MASSTOR_SFIRST(SACLIST_SECOND(MASSTOR_FIRST(Ag)), i + 1);
  return Ag;
}

void DIPDDGB_DIDPLCPL4
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *CPL, MASSTOR_LIST *AL)
# else
(P, CPL, AL)
MASSTOR_LIST P;
MASSTOR_LIST *CPL, *AL;
# endif
{
  MASSTOR_LIST CPLel, Pf, Pr, Pfp, Prp, t1, t2, lcmHT, a1, a2, lcmHK;

  if (P == MASSTOR_SIL) {
    return;
  }
  if (MASSTOR_RED(P) == MASSTOR_SIL) {
    return;
  }
  Pr = P;
  do {
    MASSTOR_ADV(Pr, &Pf, &Pr);
    *AL = DIPDDGB_DIDPLEXTAL(*AL, Pf);
    t1 = DIPC_DIPEVL(Pf);
    a1 = DIPC_DIPLBC(Pf);
    Prp = Pr;
    do {
      MASSTOR_ADV(Prp, &Pfp, &Prp);
      t2 = DIPC_DIPEVL(Pfp);
      a2 = DIPC_DIPLBC(Pfp);
      lcmHT = DIPC_EVLCM(t1, t2);
      lcmHK = MASADOM_ADLCM(a1, a2);
      CPLel = SACLIST_LIST3(lcmHT, lcmHK, SACLIST_LIST2(Pf, Pfp));
      *CPL = MASSTOR_COMP(CPLel, *CPL);
    } while (!(Prp == MASSTOR_SIL));
  } while (!(MASSTOR_RED(Pr) == MASSTOR_SIL));
  *AL = DIPDDGB_DIDPLEXTAL(*AL, MASSTOR_FIRST(Pr));
}

MASSTOR_LIST DIPDDGB_DIDPALCMPC
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST g1, MASSTOR_LIST g2, MASSTOR_LIST flag)
# else
(AL, g1, g2, flag)
MASSTOR_LIST AL, g1, g2, flag;
# endif
{
  MASSTOR_LIST i, j, Ar, Af, Aff, Afr, nulll;

  if (AL == MASSTOR_SIL) {
    return 0;
  }
  if (g1 == 0 || g2 == 0) {
    return 0;
  }
  if (g1 == g2) {
    return 0;
  }
  Ar = AL;
  i = 0;
  j = 0;
  for (;;) {
    i = i + 1;
    MASSTOR_ADV(Ar, &Af, &Ar);
    SACLIST_FIRST2(Af, &Aff, &Afr);
    if ((Aff == g1 || Aff == g2) && j == 0) {
      j = i;
      if (Ar == MASSTOR_SIL) {
        goto EXIT_4;
      }
      MASSTOR_ADV(Ar, &Af, &Ar);
      SACLIST_FIRST2(Af, &Aff, &Afr);
    }
    if ((Aff == g1 || Aff == g2) && j != 0) {
      nulll = Afr;
      i = 1;
      while (i < j && nulll != MASSTOR_SIL) {
        nulll = MASSTOR_RED(nulll);
        i = i + 1;
      }
      if (nulll == MASSTOR_SIL) {
        return 0;
      } else {
        if (flag == 1) {
          MASSTOR_SFIRST(nulll, 1);
        }
        if (MASSTOR_FIRST(nulll) == 1) {
          return 1;
        } else {
          return 0;
        }
      }
    }
    if (Ar == MASSTOR_SIL) {
      goto EXIT_4;
    }
  } EXIT_4:;
  return 0;
}

static MASSTOR_LIST crit1
# ifdef __STDC__
(MASSTOR_LIST pair)
# else
(pair)
MASSTOR_LIST pair;
# endif
{
  MASSTOR_LIST HKQf, HKPf;

  if (pair == MASSTOR_SIL) {
    return 0;
  }
  HKQf = DIPC_DIPLBC(MASSTOR_FIRST(pair));
  HKPf = DIPC_DIPLBC(SACLIST_SECOND(pair));
  if (MASADOM_ADSIGN(MASADOM_ADREM(HKPf, HKQf)) == 0) {
    return 1;
  }
  if (MASADOM_ADSIGN(MASADOM_ADREM(HKQf, HKPf)) == 0) {
    return 1;
  }
  return 0;
}

static MASSTOR_LIST crit2
# ifdef __STDC__
(MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK)
# else
(pair, lcmHT, lcmHK)
MASSTOR_LIST pair, lcmHT, lcmHK;
# endif
{
  MASSTOR_LIST prodHT, prodHK;

  if (pair == MASSTOR_SIL) {
    return 0;
  }
  prodHT = DIPC_EVSUM(DIPC_DIPEVL(MASSTOR_FIRST(pair)), DIPC_DIPEVL(SACLIST_SECOND(pair)));
  if (DIPC_EVCOMP(lcmHT, prodHT) == 0) {
    prodHK = MASADOM_ADABSF(MASADOM_ADPROD(DIPC_DIPLBC(MASSTOR_FIRST(pair)), DIPC_DIPLBC(SACLIST_SECOND(pair))));
    if (MASADOM_ADCOMP(lcmHK, prodHK) == 0) {
      return 1;
    }
  }
  return 0;
}

static MASSTOR_LIST crit3
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK)
# else
(AL, pair, lcmHT, lcmHK)
MASSTOR_LIST AL, pair, lcmHT, lcmHK;
# endif
{
  MASSTOR_LIST p, Af, Ar, Aff, Afr, HTAf, HKAf;

  if (pair == MASSTOR_SIL) {
    return 0;
  }
  if (AL == MASSTOR_SIL) {
    return 0;
  }
  p = 0;
  Ar = AL;
  for (;;) {
    MASSTOR_ADV(Ar, &Af, &Ar);
    MASSTOR_ADV(Af, &Aff, &Afr);
    HTAf = DIPC_DIPEVL(Aff);
    HKAf = DIPC_DIPLBC(Aff);
    if (DIPC_EVMT(lcmHT, HTAf) == 1) {
      if (MASADOM_ADSIGN(MASADOM_ADREM(lcmHK, HKAf)) == 0) {
        p = Aff;
        goto EXIT_5;
      }
    }
    if (Ar == MASSTOR_SIL) {
      goto EXIT_5;
    }
  } EXIT_5:;
  if (p == 0) {
    return 0;
  }
  if (DIPDDGB_DIDPALCMPC(AL, p, MASSTOR_FIRST(pair), 0) == 1 && DIPDDGB_DIDPALCMPC(AL, p, SACLIST_SECOND(pair), 0) == 1) {
    return 1;
  } else {
    return 0;
  }
}

MASSTOR_LIST DIPDDGB_DIDPENF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST varl, MASSTOR_LIST g)
# else
(P, varl, g)
MASSTOR_LIST P, varl, g;
# endif
{
  MASSTOR_LIST a, ap, app, b, c, f, PP, q, qa, qt, qr, ENF, rp, rs, teilt, gr, ga, gt, gf, rest;

  if (g == 0) {
    ENF = varl;
    return ENF;
  }
  if (P == MASSTOR_SIL) {
    if (varl == 0) {
      ENF = g;
    } else {
      ENF = SACLIST_CCONC(varl, g);
    }
    return ENF;
  }
  gf = g;
  ENF = varl;
  do {
    DIPC_DIPMAD(gf, &ga, &gt, &gr);
    if (gr == MASSTOR_SIL) {
      gr = 0;
    }
    PP = P;
    for (;;) {
      MASSTOR_ADV(PP, &q, &PP);
      DIPC_DIPMAD(q, &qa, &qt, &qr);
      teilt = DIPC_EVMT(gt, qt);
      if (teilt == 1) {
        MASADOM_ADQR(ga, qa, &a, &rest);
        if (MASADOM_ADSIGN(rest) == 0) {
          if (qr != MASSTOR_SIL) {
            f = DIPC_EVDIF(gt, qt);
            ap = DIPC_DIPFMO(a, f);
            app = DIPADOM_DIPROD(qr, ap);
            gr = DIPADOM_DIPDIF(gr, app);
          }
          gf = gr;
          goto EXIT_6;
        } else {
          if (MASADOM_ADSIGN(a) != 0) {
            f = DIPC_EVDIF(gt, qt);
            ap = DIPC_DIPFMO(a, f);
            app = DIPADOM_DIPROD(q, ap);
            gf = DIPADOM_DIPDIF(gf, app);
            DIPC_DIPMAD(gf, &ga, &gt, &gr);
            if (gr == MASSTOR_SIL) {
              gr = 0;
            }
          }
        }
      }
      if (PP == MASSTOR_SIL) {
        rp = DIPC_DIPFMO(ga, gt);
        if (ENF == 0) {
          ENF = rp;
        } else {
          ENF = SACLIST_CONC(ENF, rp);
        }
        gf = gr;
        goto EXIT_6;
      }
    } EXIT_6:;
  } while (!(gr == 0));
  return ENF;
}

MASSTOR_LIST DIPDDGB_DIDPREDDGB
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST Q, Qf, Qr, Qred, len, i;

  Q = MASSTOR_SIL;
  len = MASSTOR_LENGTH(P);
  if (len < 2) {
    return P;
  }
  Q = SACLIST_CINV(P);
  Qr = Q;
  i = 0;
  while (i < len) {
    MASSTOR_ADV(Qr, &Qf, &Qr);
    Qred = DIPDDGB_DIDPENF(Qr, 0, Qf);
    if (Qred != 0) {
      Qr = SACLIST_CONC(Qr, MASSTOR_LIST1(Qred));
    } else {
      len = len - 1;
    }
    i = i + 1;
  }
  Q = MASSTOR_INV(Qr);
  return Q;
}

MASSTOR_LIST DIPDDGB_DIDPSPOL
# ifdef __STDC__
(MASSTOR_LIST g1, MASSTOR_LIST g2)
# else
(g1, g2)
MASSTOR_LIST g1, g2;
# endif
{
  MASSTOR_LIST a1, b1, g1r, g1rp, a2, b2, g2r, g2rp, SPol, lcmHK, t1, s1, t2, s2, lcmHT;

  SPol = 0;
  if (g1 == 0 || g2 == 0) {
    return SPol;
  }
  DIPC_DIPMAD(g1, &a1, &t1, &g1r);
  DIPC_DIPMAD(g2, &a2, &t2, &g2r);
  if (g1r == MASSTOR_SIL && g2r == MASSTOR_SIL) {
    return SPol;
  }
  lcmHT = DIPC_EVLCM(t1, t2);
  lcmHK = MASADOM_ADLCM(a1, a2);
  if (g1r == MASSTOR_SIL) {
    s2 = DIPC_EVDIF(lcmHT, t2);
    b2 = MASADOM_ADQUOT(lcmHK, a2);
    b2 = MASADOM_ADNEG(b2);
    g2rp = DIPC_DIPFMO(b2, s2);
    SPol = DIPADOM_DIPROD(g2r, g2rp);
    return SPol;
  }
  if (g2r == MASSTOR_SIL) {
    s1 = DIPC_EVDIF(lcmHT, t1);
    b1 = MASADOM_ADQUOT(lcmHK, a1);
    g1rp = DIPC_DIPFMO(b1, s1);
    SPol = DIPADOM_DIPROD(g1r, g1rp);
    return SPol;
  }
  s1 = DIPC_EVDIF(lcmHT, t1);
  b1 = MASADOM_ADQUOT(lcmHK, a1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  b2 = MASADOM_ADQUOT(lcmHK, a2);
  g1rp = DIPC_DIPFMO(b1, s1);
  g2rp = DIPC_DIPFMO(b2, s2);
  g1rp = DIPADOM_DIPROD(g1r, g1rp);
  g2rp = DIPADOM_DIPROD(g2r, g2rp);
  SPol = DIPADOM_DIPDIF(g1rp, g2rp);
  return SPol;
}

MASSTOR_LIST DIPDDGB_DIDPDNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST varl, MASSTOR_LIST g)
# else
(P, varl, g)
MASSTOR_LIST P, varl, g;
# endif
{
  MASSTOR_LIST a, ap, app, b, c, f, PP, q, qa, qt, qr, NF, rp, rs, teilt, gr, ga, gt, rest;

  if (g == 0) {
    NF = varl;
    return NF;
  }
  if (P == MASSTOR_SIL) {
    if (varl == 0) {
      NF = g;
    } else {
      NF = SACLIST_CCONC(varl, g);
    }
    return NF;
  }
  gr = g;
  NF = varl;
  do {
    DIPC_DIPMAD(gr, &ga, &gt, &gr);
    if (gr == MASSTOR_SIL) {
      gr = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &q, &PP);
      DIPC_DIPMAD(q, &qa, &qt, &qr);
      teilt = DIPC_EVMT(gt, qt);
      MASADOM_ADQR(ga, qa, &a, &rest);
    } while (!(PP == MASSTOR_SIL || teilt == 1 && MASADOM_ADSIGN(rest) == 0));
    if (teilt == 1 && MASADOM_ADSIGN(rest) == 0) {
      if (qr != MASSTOR_SIL) {
        f = DIPC_EVDIF(gt, qt);
        ap = DIPC_DIPFMO(a, f);
        app = DIPADOM_DIPROD(qr, ap);
        gr = DIPADOM_DIPDIF(gr, app);
      }
    } else {
      rp = DIPC_DIPFMO(ga, gt);
      if (NF == 0) {
        NF = rp;
      } else {
        NF = SACLIST_CONC(NF, rp);
      }
    }
  } while (!(gr == 0));
  return NF;
}

MASSTOR_LIST DIPDDGB_DIDPDGB
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST TF)
# else
(F, TF)
MASSTOR_LIST F, TF;
# endif
{
  MASSTOR_LIST G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol, pair, h, hp, AL, C_161_dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2, NSPolkr3, NGPoltr;

  G = F;
  if (G == MASSTOR_SIL) {
    return G;
  }
  if (MASSTOR_RED(G) == MASSTOR_SIL) {
    return G;
  }
  B = MASSTOR_SIL;
  AL = MASSTOR_SIL;
  DIPDDGB_DIDPLCPL4(G, &B, &AL);
  B = DIPDDGB_DIDPCPLMS1(B);
  D = MASSTOR_SIL;
  B1 = SACLIST_CINV(B);
  C = MASSTOR_INV(B1);
  infoSPol = 1;
  infoGPol = 1;
  AGPol = 0;
  NGPolkr1 = 0;
  NGPoltr = 0;
  ASPol = 0;
  NSPolkr2 = 0;
  NSPolkr3 = 0;
  SPol = 0;
  GPol = 0;
  while (B != MASSTOR_SIL) {
    while (C != MASSTOR_SIL) {
      MASSTOR_ADV(C, &Cf, &C);
      AGPol = AGPol + 1;
      SACLIST_FIRST3(Cf, &lcmHT, &lcmHK, &pair);
      if (crit1(pair) == 1) {
        hp = 0;
        NGPolkr1 = NGPolkr1 + 1;
      } else if (DIPDDGB_DIDPTDR(G, lcmHT, pair) == 1) {
        hp = 0;
        NGPoltr = NGPoltr + 1;
      } else {
        h = DIPDDGB_DIDPGPOL(MASSTOR_FIRST(pair), SACLIST_SECOND(pair));
        hp = DIPDDGB_DIDPDNF(G, 0, h);
      }
      if (hp != 0) {
        AL = DIPDDGB_DIDPLEXTAL(AL, hp);
        D = DIPDDGB_DIDPUCPL1(G, hp, D);
        G = MASSTOR_COMP(hp, G);
        GPol = GPol + 1;
      }
      if (TF != 0) {
        if (infoGPol == TF) {
          MASBIOS_SWRITE("Number of computed G-polynomials: ", 34L);
          SACI_IWRITE(AGPol);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Cancelled due to criterion 1: ", 30L);
          SACI_IWRITE(NGPolkr1);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Cancelled due to top-D-reducibility: ", 37L);
          SACI_IWRITE(NGPoltr);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("New polynomials added to G: ", 28L);
          SACI_IWRITE(GPol);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Number of critical pairs in D: ", 31L);
          SACI_IWRITE(MASSTOR_LENGTH(D));
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Number of critical pairs in C: ", 31L);
          SACI_IWRITE(MASSTOR_LENGTH(C));
          MASBIOS_BLINES(1);
          infoGPol = 1;
        } else {
          infoGPol = infoGPol + 1;
        }
      }
    }
    MASSTOR_ADV(B, &Bf, &B);
    ASPol = ASPol + 1;
    SACLIST_FIRST3(Bf, &lcmHT, &lcmHK, &pair);
    if (crit2(pair, lcmHT, lcmHK) == 1) {
      hp = 0;
      NSPolkr2 = NSPolkr2 + 1;
    } else if (crit3(AL, pair, lcmHT, lcmHK) == 1) {
      hp = 0;
      NSPolkr3 = NSPolkr3 + 1;
    } else {
      h = DIPDDGB_DIDPSPOL2(MASSTOR_FIRST(pair), SACLIST_SECOND(pair), lcmHT, lcmHK);
      hp = DIPDDGB_DIDPDNF(G, 0, h);
    }
    C_161_dummy = DIPDDGB_DIDPALCMPC(AL, MASSTOR_FIRST(pair), SACLIST_SECOND(pair), 1);
    if (hp != 0) {
      AL = DIPDDGB_DIDPLEXTAL(AL, hp);
      D = DIPDDGB_DIDPUCPL1(G, hp, D);
      G = MASSTOR_COMP(hp, G);
      SPol = SPol + 1;
    }
    D1 = SACLIST_CINV(D);
    C = MASSTOR_INV(D1);
    B = DIPDDGB_DIDPLM1(B, D);
    D = MASSTOR_SIL;
    if (TF != 0) {
      if (infoSPol == TF) {
        MASBIOS_SWRITE("Number of computed S-polynomials: ", 34L);
        SACI_IWRITE(ASPol);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Cancelled due to criterion 2: ", 30L);
        SACI_IWRITE(NSPolkr2);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Cancelled due to criterion 3: ", 30L);
        SACI_IWRITE(NSPolkr3);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("New polynomials added to G: ", 28L);
        SACI_IWRITE(SPol);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Number of critical pairs in B: ", 31L);
        SACI_IWRITE(MASSTOR_LENGTH(B));
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Number of critical pairs in C: ", 31L);
        SACI_IWRITE(MASSTOR_LENGTH(C));
        MASBIOS_BLINES(1);
        infoSPol = 1;
      } else {
        infoSPol = infoSPol + 1;
      }
    }
  }
  if (TF != 0) {
    MASBIOS_SWRITE("Number of computed G-polynomials: ", 34L);
    SACI_IWRITE(AGPol);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 1: ", 30L);
    SACI_IWRITE(NGPolkr1);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to top-D-reducibility: ", 37L);
    SACI_IWRITE(NGPoltr);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Number of computed S-polynomials: ", 34L);
    SACI_IWRITE(ASPol);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 2: ", 30L);
    SACI_IWRITE(NSPolkr2);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 3: ", 30L);
    SACI_IWRITE(NSPolkr3);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Number of polynomials in G before reduction: ", 45L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(0);
  }
  G = DIPDDGB_DIDPELIMDGB(G);
  if (TF != 0) {
    MASBIOS_SWRITE("Number of polynomials in G after reduction: ", 44L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(1);
  }
  G = DIPDDGB_DIDPREDDGB(G);
  return G;
}

MASSTOR_LIST DIPDDGB_DIDPEGB
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST DP, MASSTOR_LIST TF)
# else
(F, DP, TF)
MASSTOR_LIST F, DP, TF;
# endif
{
  MASSTOR_LIST G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol, pair, h, hp, AL, C_160_dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2, NSPolkr3, NGPoltr, DL;

  G = F;
  if (G == MASSTOR_SIL) {
    return G;
  }
  if (MASSTOR_RED(G) == MASSTOR_SIL) {
    return G;
  }
  B = MASSTOR_SIL;
  AL = MASSTOR_SIL;
  DIPDDGB_DIDPLCPL4(G, &B, &AL);
  B = DIPDDGB_DIDPCPLMS1(B);
  D = MASSTOR_SIL;
  B1 = SACLIST_CINV(B);
  C = MASSTOR_INV(B1);
  infoSPol = 1;
  infoGPol = 1;
  AGPol = 0;
  NGPolkr1 = 0;
  NGPoltr = 0;
  ASPol = 0;
  NSPolkr2 = 0;
  NSPolkr3 = 0;
  SPol = 0;
  GPol = 0;
  while (B != MASSTOR_SIL) {
    while (C != MASSTOR_SIL) {
      MASSTOR_ADV(C, &Cf, &C);
      AGPol = AGPol + 1;
      SACLIST_FIRST3(Cf, &lcmHT, &lcmHK, &pair);
      if (crit1(pair) == 1) {
        hp = 0;
        NGPolkr1 = NGPolkr1 + 1;
      } else if (DIPDDGB_DIDPTDR(G, lcmHT, pair) == 1) {
        hp = 0;
        NGPoltr = NGPoltr + 1;
      } else {
        h = DIPDDGB_DIDPGPOL(MASSTOR_FIRST(pair), SACLIST_SECOND(pair));
        hp = DIPDDGB_DIDPENF(G, 0, h);
      }
      if (hp != 0) {
        AL = DIPDDGB_DIDPLEXTAL(AL, hp);
        D = DIPDDGB_DIDPUCPL1(G, hp, D);
        G = MASSTOR_COMP(hp, G);
        GPol = GPol + 1;
      }
      if (TF != 0) {
        if (infoGPol == TF) {
          MASBIOS_SWRITE("Number of computed G-polynomials: ", 34L);
          SACI_IWRITE(AGPol);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Cancelled due to criterion 1: ", 30L);
          SACI_IWRITE(NGPolkr1);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Cancelled due to top-D-reducibility: ", 37L);
          SACI_IWRITE(NGPoltr);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("New polynomials added to G: ", 28L);
          SACI_IWRITE(GPol);
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Number of critical pairs in D: ", 31L);
          SACI_IWRITE(MASSTOR_LENGTH(D));
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Number of critical pairs in C: ", 31L);
          SACI_IWRITE(MASSTOR_LENGTH(C));
          MASBIOS_BLINES(1);
          infoGPol = 1;
        } else {
          infoGPol = infoGPol + 1;
        }
      }
    }
    MASSTOR_ADV(B, &Bf, &B);
    ASPol = ASPol + 1;
    SACLIST_FIRST3(Bf, &lcmHT, &lcmHK, &pair);
    if (crit2(pair, lcmHT, lcmHK) == 1) {
      hp = 0;
      NSPolkr2 = NSPolkr2 + 1;
    } else if (crit3(AL, pair, lcmHT, lcmHK) == 1) {
      hp = 0;
      NSPolkr3 = NSPolkr3 + 1;
    } else {
      h = DIPDDGB_DIDPSPOL2(MASSTOR_FIRST(pair), SACLIST_SECOND(pair), lcmHT, lcmHK);
      hp = DIPDDGB_DIDPENF(G, 0, h);
    }
    C_160_dummy = DIPDDGB_DIDPALCMPC(AL, MASSTOR_FIRST(pair), SACLIST_SECOND(pair), 1);
    if (hp != 0) {
      AL = DIPDDGB_DIDPLEXTAL(AL, hp);
      D = DIPDDGB_DIDPUCPL1(G, hp, D);
      G = MASSTOR_COMP(hp, G);
      SPol = SPol + 1;
    }
    D1 = SACLIST_CINV(D);
    C = MASSTOR_INV(D1);
    B = DIPDDGB_DIDPLM1(B, D);
    D = MASSTOR_SIL;
    if (TF != 0) {
      if (infoSPol == TF) {
        MASBIOS_SWRITE("Number of computed S-polynomials: ", 34L);
        SACI_IWRITE(ASPol);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Cancelled due to criterion 2: ", 30L);
        SACI_IWRITE(NSPolkr2);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Cancelled due to criterion 3: ", 30L);
        SACI_IWRITE(NSPolkr3);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("New polynomials added to G: ", 28L);
        SACI_IWRITE(SPol);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Number of critical pairs in B: ", 31L);
        SACI_IWRITE(MASSTOR_LENGTH(B));
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("Number of critical pairs in C: ", 31L);
        SACI_IWRITE(MASSTOR_LENGTH(C));
        MASBIOS_BLINES(1);
        infoSPol = 1;
      } else {
        infoSPol = infoSPol + 1;
      }
    }
  }
  if (TF != 0) {
    MASBIOS_SWRITE("Number of computed G-polynomials: ", 34L);
    SACI_IWRITE(AGPol);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 1: ", 30L);
    SACI_IWRITE(NGPolkr1);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to top-D-reducibility: ", 37L);
    SACI_IWRITE(NGPoltr);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Number of computed S-polynomials: ", 34L);
    SACI_IWRITE(ASPol);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 2: ", 30L);
    SACI_IWRITE(NSPolkr2);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Cancelled due to criterion 3: ", 30L);
    SACI_IWRITE(NSPolkr3);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Number of polynomials in G before reduction: ", 45L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(0);
  }
  G = DIPDDGB_DIDPELIMDGB(G);
  if (TF != 0) {
    MASBIOS_SWRITE("Number of polynomials in G after reduction: ", 44L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(1);
  }
  G = DIPDDGB_DIDPREDDGB(G);
  return G;
}

void BEGIN_DIPDDGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_MASADOM();
    BEGIN_DIPADOM();

  }
}
