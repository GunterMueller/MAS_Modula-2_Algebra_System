#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

#ifndef DEFINITION_DIPIDGB
#include "DIPIDGB.h"
#endif


static CHAR rcsidi [] = "$Id: DIPIDGB.mi,v 1.1 1993/05/11 10:13:21 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1993 Universitaet Passau";
static MASSTOR_LIST crit1 ARGS((MASSTOR_LIST pair));
static MASSTOR_LIST crit2 ARGS((MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK));
static MASSTOR_LIST crit3 ARGS((MASSTOR_LIST AL, MASSTOR_LIST pair, MASSTOR_LIST lcmHT, MASSTOR_LIST lcmHK));


MASSTOR_LIST DIPIDGB_DIIPELIMDGB
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
        if (SACI_ISIGNF(SACI_IREM(HKPf, HKQf)) == 0) {
          goto EXIT_2;
        }
      }
      if (DIPC_EVMT(HTQf, HTPf) == 1) {
        if (SACI_ISIGNF(SACI_IREM(HKQf, HKPf)) == 0) {
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

MASSTOR_LIST DIPIDGB_DIIPTDR
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
      if (SACI_ISIGNF(SACI_IREM(HKg1, HKg)) == 0 && SACI_ISIGNF(SACI_IREM(HKg2, HKg)) == 0) {
        return 1;
      }
    }
  } while (!(PP == MASSTOR_SIL));
  return 0;
}

MASSTOR_LIST DIPIDGB_DIIPCPLMS1
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
  onestep = DIPIDGB_DIIPCPLMS1(P);
  twostep = DIPIDGB_DIIPCPLMS1(twostep);
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
    icomp = SACI_ICOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
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
      icomp = SACI_ICOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
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

MASSTOR_LIST DIPIDGB_DIIPLM1
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
    icomp = SACI_ICOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
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
      icomp = SACI_ICOMP(SACLIST_SECOND(MASSTOR_FIRST(onestep)), SACLIST_SECOND(MASSTOR_FIRST(twostep)));
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

MASSTOR_LIST DIPIDGB_DIIPUCPL1
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
    lcmHK = SACI_ILCM(a1, a2);
    pair = SACLIST_LIST2(g, Pf);
    Upel = SACLIST_LIST3(lcmHT, lcmHK, pair);
    Up = MASSTOR_COMP(Upel, Up);
  } while (!(Pr == MASSTOR_SIL));
  Up = DIPIDGB_DIIPCPLMS1(Up);
  if (Old == MASSTOR_SIL) {
    return Up;
  }
  Update = DIPIDGB_DIIPLM1(Up, Old);
  return Update;
}

MASSTOR_LIST DIPIDGB_DIIPGPOL
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
  SACI_IEGCD(a1, a2, &gcdHK, &c1, &c2);
  if (SACI_ISIGNF(c1) == 0) {
    lcmHT = DIPC_EVLCM(t1, t2);
    s2 = DIPC_EVDIF(lcmHT, t2);
    g2rp = DIPC_DIPFMO(c2, s2);
    GPol = DIPI_DIIPPR(g2, g2rp);
    return GPol;
  }
  if (SACI_ISIGNF(c2) == 0) {
    lcmHT = DIPC_EVLCM(t1, t2);
    s1 = DIPC_EVDIF(lcmHT, t1);
    g1rp = DIPC_DIPFMO(c1, s1);
    GPol = DIPI_DIIPPR(g1, g1rp);
    return GPol;
  }
  lcmHT = DIPC_EVLCM(t1, t2);
  s1 = DIPC_EVDIF(lcmHT, t1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  g1rp = DIPC_DIPFMO(c1, s1);
  g2rp = DIPC_DIPFMO(c2, s2);
  g1rp = DIPI_DIIPPR(g1, g1rp);
  g2rp = DIPI_DIIPPR(g2, g2rp);
  GPol = DIPI_DIIPSM(g1rp, g2rp);
  return GPol;
}

MASSTOR_LIST DIPIDGB_DIIPSPOL2
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
    b2 = SACI_IQ(lcmHK, a2);
    b2 = SACI_INEG(b2);
    g2rp = DIPC_DIPFMO(b2, s2);
    SPol = DIPI_DIIPPR(g2r, g2rp);
    return SPol;
  }
  if (g2r == MASSTOR_SIL) {
    s1 = DIPC_EVDIF(lcmHT, t1);
    b1 = SACI_IQ(lcmHK, a1);
    g1rp = DIPC_DIPFMO(b1, s1);
    SPol = DIPI_DIIPPR(g1r, g1rp);
    return SPol;
  }
  s1 = DIPC_EVDIF(lcmHT, t1);
  b1 = SACI_IQ(lcmHK, a1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  b2 = SACI_IQ(lcmHK, a2);
  g1rp = DIPC_DIPFMO(b1, s1);
  g2rp = DIPC_DIPFMO(b2, s2);
  g1rp = DIPI_DIIPPR(g1r, g1rp);
  g2rp = DIPI_DIIPPR(g2r, g2rp);
  SPol = DIPI_DIIPDF(g1rp, g2rp);
  return SPol;
}

MASSTOR_LIST DIPIDGB_DIIPLEXTAL
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

void DIPIDGB_DIIPLCPL4
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
    *AL = DIPIDGB_DIIPLEXTAL(*AL, Pf);
    t1 = DIPC_DIPEVL(Pf);
    a1 = DIPC_DIPLBC(Pf);
    Prp = Pr;
    do {
      MASSTOR_ADV(Prp, &Pfp, &Prp);
      t2 = DIPC_DIPEVL(Pfp);
      a2 = DIPC_DIPLBC(Pfp);
      lcmHT = DIPC_EVLCM(t1, t2);
      lcmHK = SACI_ILCM(a1, a2);
      CPLel = SACLIST_LIST3(lcmHT, lcmHK, SACLIST_LIST2(Pf, Pfp));
      *CPL = MASSTOR_COMP(CPLel, *CPL);
    } while (!(Prp == MASSTOR_SIL));
  } while (!(MASSTOR_RED(Pr) == MASSTOR_SIL));
  *AL = DIPIDGB_DIIPLEXTAL(*AL, MASSTOR_FIRST(Pr));
}

MASSTOR_LIST DIPIDGB_DIIPALCMPC
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
  if (SACI_ISIGNF(SACI_IREM(HKPf, HKQf)) == 0) {
    return 1;
  }
  if (SACI_ISIGNF(SACI_IREM(HKQf, HKPf)) == 0) {
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
    prodHK = SACI_IABSF(SACI_IPROD(DIPC_DIPLBC(MASSTOR_FIRST(pair)), DIPC_DIPLBC(SACLIST_SECOND(pair))));
    if (SACI_ICOMP(lcmHK, prodHK) == 0) {
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
      if (SACI_ISIGNF(SACI_IREM(lcmHK, HKAf)) == 0) {
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
  if (DIPIDGB_DIIPALCMPC(AL, p, MASSTOR_FIRST(pair), 0) == 1 && DIPIDGB_DIIPALCMPC(AL, p, SACLIST_SECOND(pair), 0) == 1) {
    return 1;
  } else {
    return 0;
  }
}

MASSTOR_LIST DIPIDGB_DIIPENF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST varl, MASSTOR_LIST g)
# else
(P, varl, g)
MASSTOR_LIST P, varl, g;
# endif
{
  MASSTOR_LIST q, ap, app, b, c, s, PP, p, pa, pt, pr, ENF, rp, rs, teilt, gr, ga, gt, gf, rest;

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
      MASSTOR_ADV(PP, &p, &PP);
      DIPC_DIPMAD(p, &pa, &pt, &pr);
      teilt = DIPC_EVMT(gt, pt);
      if (teilt == 1) {
        SACI_IQR(ga, pa, &q, &rest);
        if (SACI_ISIGNF(rest) == 0) {
          if (pr != MASSTOR_SIL) {
            s = DIPC_EVDIF(gt, pt);
            ap = DIPC_DIPFMO(q, s);
            app = DIPI_DIIPPR(pr, ap);
            gr = DIPI_DIIPDF(gr, app);
          }
          gf = gr;
          goto EXIT_6;
        } else {
          if (SACI_ISIGNF(q) != 0) {
            s = DIPC_EVDIF(gt, pt);
            if (SACI_ISIGNF(ga) == -1) {
              if (SACI_ISIGNF(q) == 1) {
                q = SACI_ISUM(q, 1);
              } else {
                q = SACI_IDIF(q, 1);
              }
            }
            ap = DIPC_DIPFMO(q, s);
            app = DIPI_DIIPPR(p, ap);
            gf = DIPI_DIIPDF(gf, app);
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

MASSTOR_LIST DIPIDGB_DIIPREDDGB
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
    Qred = DIPIDGB_DIIPENF(Qr, 0, Qf);
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

MASSTOR_LIST DIPIDGB_DIIPSPOL
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
  lcmHK = SACI_ILCM(a1, a2);
  if (g1r == MASSTOR_SIL) {
    s2 = DIPC_EVDIF(lcmHT, t2);
    b2 = SACI_IQ(lcmHK, a2);
    b2 = SACI_INEG(b2);
    g2rp = DIPC_DIPFMO(b2, s2);
    SPol = DIPI_DIIPPR(g2r, g2rp);
    return SPol;
  }
  if (g2r == MASSTOR_SIL) {
    s1 = DIPC_EVDIF(lcmHT, t1);
    b1 = SACI_IQ(lcmHK, a1);
    g1rp = DIPC_DIPFMO(b1, s1);
    SPol = DIPI_DIIPPR(g1r, g1rp);
    return SPol;
  }
  s1 = DIPC_EVDIF(lcmHT, t1);
  b1 = SACI_IQ(lcmHK, a1);
  s2 = DIPC_EVDIF(lcmHT, t2);
  b2 = SACI_IQ(lcmHK, a2);
  g1rp = DIPC_DIPFMO(b1, s1);
  g2rp = DIPC_DIPFMO(b2, s2);
  g1rp = DIPI_DIIPPR(g1r, g1rp);
  g2rp = DIPI_DIIPPR(g2r, g2rp);
  SPol = DIPI_DIIPDF(g1rp, g2rp);
  return SPol;
}

MASSTOR_LIST DIPIDGB_DIIPDNF
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
      SACI_IQR(ga, qa, &a, &rest);
    } while (!(PP == MASSTOR_SIL || teilt == 1 && SACI_ISIGNF(rest) == 0));
    if (teilt == 1 && SACI_ISIGNF(rest) == 0) {
      if (qr != MASSTOR_SIL) {
        f = DIPC_EVDIF(gt, qt);
        ap = DIPC_DIPFMO(a, f);
        app = DIPI_DIIPPR(qr, ap);
        gr = DIPI_DIIPDF(gr, app);
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

MASSTOR_LIST DIPIDGB_DIIPDGB
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST TF)
# else
(F, TF)
MASSTOR_LIST F, TF;
# endif
{
  MASSTOR_LIST G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol, pair, h, hp, AL, C_116_dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2, NSPolkr3, NGPoltr;

  G = F;
  if (G == MASSTOR_SIL) {
    return G;
  }
  if (MASSTOR_RED(G) == MASSTOR_SIL) {
    return G;
  }
  B = MASSTOR_SIL;
  AL = MASSTOR_SIL;
  DIPIDGB_DIIPLCPL4(G, &B, &AL);
  B = DIPIDGB_DIIPCPLMS1(B);
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
      } else if (DIPIDGB_DIIPTDR(G, lcmHT, pair) == 1) {
        hp = 0;
        NGPoltr = NGPoltr + 1;
      } else {
        h = DIPIDGB_DIIPGPOL(MASSTOR_FIRST(pair), SACLIST_SECOND(pair));
        hp = DIPIDGB_DIIPDNF(G, 0, h);
      }
      if (hp != 0) {
        AL = DIPIDGB_DIIPLEXTAL(AL, hp);
        D = DIPIDGB_DIIPUCPL1(G, hp, D);
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
      h = DIPIDGB_DIIPSPOL2(MASSTOR_FIRST(pair), SACLIST_SECOND(pair), lcmHT, lcmHK);
      hp = DIPIDGB_DIIPDNF(G, 0, h);
    }
    C_116_dummy = DIPIDGB_DIIPALCMPC(AL, MASSTOR_FIRST(pair), SACLIST_SECOND(pair), 1);
    if (hp != 0) {
      AL = DIPIDGB_DIIPLEXTAL(AL, hp);
      D = DIPIDGB_DIIPUCPL1(G, hp, D);
      G = MASSTOR_COMP(hp, G);
      SPol = SPol + 1;
    }
    D1 = SACLIST_CINV(D);
    C = MASSTOR_INV(D1);
    B = DIPIDGB_DIIPLM1(B, D);
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
  G = DIPIDGB_DIIPELIMDGB(G);
  if (TF != 0) {
    MASBIOS_SWRITE("Number of polynomials in G after reduction: ", 44L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(1);
  }
  G = DIPIDGB_DIIPREDDGB(G);
  return G;
}

MASSTOR_LIST DIPIDGB_DIIPEGB
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST TF)
# else
(F, TF)
MASSTOR_LIST F, TF;
# endif
{
  MASSTOR_LIST G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol, pair, h, hp, AL, C_115_dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2, NSPolkr3, NGPoltr;

  G = F;
  if (G == MASSTOR_SIL) {
    return G;
  }
  if (MASSTOR_RED(G) == MASSTOR_SIL) {
    return G;
  }
  B = MASSTOR_SIL;
  AL = MASSTOR_SIL;
  DIPIDGB_DIIPLCPL4(G, &B, &AL);
  B = DIPIDGB_DIIPCPLMS1(B);
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
      } else if (DIPIDGB_DIIPTDR(G, lcmHT, pair) == 1) {
        hp = 0;
        NGPoltr = NGPoltr + 1;
      } else {
        h = DIPIDGB_DIIPGPOL(MASSTOR_FIRST(pair), SACLIST_SECOND(pair));
        hp = DIPIDGB_DIIPENF(G, 0, h);
      }
      if (hp != 0) {
        AL = DIPIDGB_DIIPLEXTAL(AL, hp);
        D = DIPIDGB_DIIPUCPL1(G, hp, D);
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
      h = DIPIDGB_DIIPSPOL2(MASSTOR_FIRST(pair), SACLIST_SECOND(pair), lcmHT, lcmHK);
      hp = DIPIDGB_DIIPENF(G, 0, h);
    }
    C_115_dummy = DIPIDGB_DIIPALCMPC(AL, MASSTOR_FIRST(pair), SACLIST_SECOND(pair), 1);
    if (hp != 0) {
      AL = DIPIDGB_DIIPLEXTAL(AL, hp);
      D = DIPIDGB_DIIPUCPL1(G, hp, D);
      G = MASSTOR_COMP(hp, G);
      SPol = SPol + 1;
    }
    D1 = SACLIST_CINV(D);
    C = MASSTOR_INV(D1);
    B = DIPIDGB_DIIPLM1(B, D);
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
  G = DIPIDGB_DIIPELIMDGB(G);
  if (TF != 0) {
    MASBIOS_SWRITE("Number of polynomials in G after reduction: ", 44L);
    SACI_IWRITE(MASSTOR_LENGTH(G));
    MASBIOS_BLINES(1);
  }
  G = DIPIDGB_DIIPREDDGB(G);
  return G;
}

void BEGIN_DIPIDGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_DIPC();
    BEGIN_DIPI();

  }
}
