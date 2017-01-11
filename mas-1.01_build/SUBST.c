#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

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

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_GSYMFUIN
#include "GSYMFUIN.h"
#endif

#ifndef DEFINITION_GSYMFURN
#include "GSYMFURN.h"
#endif

#ifndef DEFINITION_NOETHER
#include "NOETHER.h"
#endif

#ifndef DEFINITION_SUBST
#include "SUBST.h"
#endif

CHAR SUBST_rcsid [] = "$Id: SUBST.md,v 1.1 1995/11/05 15:57:34 pesch Exp $";
CHAR SUBST_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SUBST.mi,v 1.1 1995/11/05 15:57:36 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static MASSTOR_LIST PERM ARGS((MASSTOR_LIST PI, MASSTOR_LIST POL));
static void COMPARE ARGS((MASSTOR_LIST SG, MASSTOR_LIST SKL, MASSTOR_LIST SKP, MASSTOR_LIST TERM, MASSTOR_LIST *BASE, MASSTOR_LIST *POL));
static void SUBBRM ARGS((MASSTOR_LIST SG, MASSTOR_LIST *BASE, MASSTOR_LIST *POL));


void SUBST_SUBINF
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Substitution Group Polynomial System Package:", 45L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("---------------------------------------------", 45L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("               SG := SUBSGR(Number_of_Variables).", 49L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("            Order := SUBORD(SG).", 32L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("            Orbit := SUBORP(SG, Polynom).", 41L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("           0_or_1 := SUBSYM(SG, Polynom).", 41L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("       Orbit_List := SUBOPL(SG, Monom_List).", 44L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("          Polynom := SUBCHK(SG, Base, Base_Polynom).", 52L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("     SK_Power_Sum := SUBPOW(SG, Degree).", 40L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("SUBRED(SG, Polynom, Base, Base_Polynom, Remainder_Polynom).", 59L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SUBINF().", 9L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SUBSGW(SG).", 11L);
}

MASSTOR_LIST SUBST_SUBSGR
# ifdef __STDC__
(MASELEM_GAMMAINT N)
# else
(N)
MASELEM_GAMMAINT N;
# endif
{
  MASSTOR_LIST SG, NSG, XSG, YSG, XX, YY, VEC, T;
  MASELEM_GAMMAINT I, K, C_100_N;

  SG = MASSTOR_SIL;
  NSG = MASSTOR_SIL;
  XSG = MASSTOR_SIL;
  XX = LINALGRN_RNMREAD();
  while (XX != MASSTOR_SIL) {
    if (MASSTOR_LENGTH(XX) != N) {
      MASBIOS_SWRITE("Length error, try again! ", 25L);
    } else {
      if (SACLIST_MEMBER(XX, XSG) == 0) {
        I = 1;
        YY = XX;
        for (;;) {
          if (YY == MASSTOR_SIL) {
            goto EXIT_1;
          }
          MASSTOR_ADV(YY, &VEC, &YY);
          if (MASSTOR_LENGTH(VEC) != N) {
            goto EXIT_1;
          }
          I = I + 1;
        } EXIT_1:;
        if (I >= N && LINALGRN_RNMDET(XX) != 0) {
          XSG = MASSTOR_COMP(XX, XSG);
        } else {
          MASBIOS_SWRITE("No substitution, try again! ", 28L);
        }
      }
    }
    XX = LINALGRN_RNMREAD();
  }
  SG = XSG;
  K = 0;
  MASBIOS_BLINES(0);
  do {
    K = K + 1;
    NSG = SG;
    N = MASSTOR_LENGTH(SG);
    while (NSG != MASSTOR_SIL) {
      MASSTOR_ADV(NSG, &XX, &NSG);
      YSG = XSG;
      while (YSG != MASSTOR_SIL) {
        MASSTOR_ADV(YSG, &YY, &YSG);
        T = LINALGRN_RNMPROD(XX, YY);
        if (SACLIST_MEMBER(T, SG) == 0) {
          SG = MASSTOR_COMP(T, SG);
          SACLIST_OWRITE(K);
          MASBIOS_SWRITE(" ", 1L);
        }
      }
    }
  } while (!(MASSTOR_LENGTH(SG) == N || K > 50));
  return SG;
}

void SUBST_SUBSGW
# ifdef __STDC__
(MASSTOR_LIST SG)
# else
(SG)
MASSTOR_LIST SG;
# endif
{
  MASSTOR_LIST PI;
  MASELEM_GAMMAINT I;

  I = 0;
  while (SG != MASSTOR_SIL) {
    MASSTOR_ADV(SG, &PI, &SG);
    I = I + 1;
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(I);
    MASBIOS_SWRITE(")  ", 3L);
    SACLIST_OWRITE(PI);
  }
}

MASELEM_GAMMAINT SUBST_SUBORD
# ifdef __STDC__
(MASSTOR_LIST SG)
# else
(SG)
MASSTOR_LIST SG;
# endif
{
  return MASSTOR_LENGTH(SG);
}

static MASSTOR_LIST PERM
# ifdef __STDC__
(MASSTOR_LIST PI, MASSTOR_LIST POL)
# else
(PI, POL)
MASSTOR_LIST PI, POL;
# endif
{
  MASSTOR_LIST RES, FF, XX, SUM, VEC, HK, HT, NFF, PROD;
  MASELEM_GAMMAINT I, J, N;

  RES = 0;
  if (PI == MASSTOR_SIL || POL == 0) {
    return RES;
  }
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PI));
  FF = MASSTOR_SIL;
  while (PI != MASSTOR_SIL) {
    MASSTOR_ADV(PI, &VEC, &PI);
    SUM = 0;
    {
      LONGINT B_1 = 1, B_2 = N;

      if (B_1 <= B_2)
        for (I = B_1;; I += 1) {
          if (SACLIST_LELT(VEC, I) != 0) {
            XX = MASSTOR_SIL;
            {
              LONGINT B_3 = 1, B_4 = N;

              if (B_3 <= B_4)
                for (J = B_3;; J += 1) {
                  if (I == J) {
                    XX = MASSTOR_COMP(1, XX);
                  } else {
                    XX = MASSTOR_COMP(0, XX);
                  }
                  if (J >= B_4) break;
                }
            }
            SUM = DIPRN_DIRPSM(SUM, DIPC_DIPFMO(SACLIST_LELT(VEC, I), XX));
          }
          if (I >= B_2) break;
        }
    }
    FF = MASSTOR_COMP(SUM, FF);
  }
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    PROD = DIPRN_DIRPEX(DIPC_DIPFMO(HK, HT), 0);
    NFF = FF;
    while (HT != MASSTOR_SIL) {
      MASSTOR_ADV(HT, &XX, &HT);
      MASSTOR_ADV(NFF, &SUM, &NFF);
      PROD = DIPRN_DIRPPR(PROD, DIPRN_DIRPEX(SUM, XX));
    }
    RES = DIPRN_DIRPSM(RES, DIPRN_DIRPRP(PROD, HK));
  }
  return RES;
}

MASSTOR_LIST SUBST_SUBORP
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST POL)
# else
(SG, POL)
MASSTOR_LIST SG, POL;
# endif
{
  MASSTOR_LIST RES, PI;
  MASELEM_GAMMAINT ORDER;

  RES = 0;
  if (SG == MASSTOR_SIL || POL == 0) {
    return RES;
  }
  ORDER = SUBST_SUBORD(SG);
  while (SG != MASSTOR_SIL) {
    MASSTOR_ADV(SG, &PI, &SG);
    RES = DIPRN_DIRPSM(RES, PERM(PI, POL));
  }
  RES = DIPRN_DIRPRQ(RES, SACRN_RNINT(ORDER));
  return RES;
}

MASELEM_GAMMAINT SUBST_SUBSYM
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST POL)
# else
(SG, POL)
MASSTOR_LIST SG, POL;
# endif
{
  MASSTOR_LIST PI;

  while (SG != MASSTOR_SIL) {
    MASSTOR_ADV(SG, &PI, &SG);
    if (DIPRN_DIRPDF(POL, PERM(PI, POL)) != 0) {
      return 0;
    }
  }
  return 1;
}

MASSTOR_LIST SUBST_SUBOPL
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST ML)
# else
(SG, ML)
MASSTOR_LIST SG, ML;
# endif
{
  MASSTOR_LIST HM, RES;

  RES = MASSTOR_SIL;
  while (ML != MASSTOR_SIL) {
    MASSTOR_ADV(ML, &HM, &ML);
    RES = MASSTOR_COMP(SUBST_SUBORP(SG, HM), RES);
  }
  return MASSTOR_INV(RES);
}

MASSTOR_LIST SUBST_SUBCHK
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST BASE, MASSTOR_LIST POL)
# else
(SG, BASE, POL)
MASSTOR_LIST SG, BASE, POL;
# endif
{
  MASSTOR_LIST RES, HK, HT, BASEORBIT, PROD;
  MASELEM_GAMMAINT I, N;

  RES = 0;
  if (POL == 0) {
    return RES;
  }
  N = MASSTOR_LENGTH(BASE);
  if (N == 0) {
    return RES;
  }
  BASEORBIT = SUBST_SUBOPL(SG, BASE);
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    if (POL == MASSTOR_SIL) {
      POL = 0;
    }
    PROD = DIPRN_DIRPEX(SACLIST_LELT(BASEORBIT, 1), 0);
    {
      LONGINT B_5 = 1, B_6 = N;

      if (B_5 <= B_6)
        for (I = B_5;; I += 1) {
          PROD = DIPRN_DIRPPR(PROD, DIPRN_DIRPEX(SACLIST_LELT(BASEORBIT, I), SACLIST_LELT(HT, I)));
          if (I >= B_6) break;
        }
    }
    RES = DIPRN_DIRPSM(RES, DIPRN_DIRPRP(PROD, HK));
  }
  return RES;
}

MASSTOR_LIST SUBST_SUBPOW
# ifdef __STDC__
(MASSTOR_LIST SG, MASELEM_GAMMAINT K)
# else
(SG, K)
MASSTOR_LIST SG;
MASELEM_GAMMAINT K;
# endif
{
  MASSTOR_LIST POL, XPOL, HKPOL, HKBASE, XHK, HK, HT, XX;
  MASELEM_GAMMAINT I, J, N, ORDER;

  POL = 0;
  if (SG == MASSTOR_SIL) {
    return POL;
  }
  XPOL = 0;
  N = MASSTOR_LENGTH(MASSTOR_FIRST(MASSTOR_FIRST(SG)));
  ORDER = SUBST_SUBORD(SG);
  {
    LONGINT B_7 = 1, B_8 = N;

    if (B_7 <= B_8)
      for (I = B_7;; I += 1) {
        HT = MASSTOR_SIL;
        {
          LONGINT B_9 = 1, B_10 = N;

          if (B_9 <= B_10)
            for (J = B_9;; J += 1) {
              if (I == J) {
                HT = MASSTOR_COMP(1, HT);
              } else {
                HT = MASSTOR_COMP(0, HT);
              }
              if (J >= B_10) break;
            }
        }
        XPOL = DIPRN_DIRPSM(XPOL, DIPC_DIPFMO(SACRN_RNINT(1), HT));
        if (I >= B_8) break;
      }
  }
  XPOL = DIPRN_DIRPEX(XPOL, K);
  POL = MASSTOR_SIL;
  while (XPOL != MASSTOR_SIL) {
    DIPC_DIPMAD(XPOL, &HK, &HT, &XPOL);
    XX = DIPC_DIPFMO(SACRN_RNINT(1), HT);
    if (SUBST_SUBORP(SG, XX) != 0) {
      HKPOL = DIPRN_DIRPRP(DIPC_DIPFMO(SACRN_RNINT(ORDER), MASSTOR_LIST1(1)), HK);
      HKBASE = MASSTOR_LIST1(XX);
      XHK = MASSTOR_SIL;
      XHK = MASSTOR_COMP(HKPOL, MASSTOR_COMP(HKBASE, XHK));
      POL = MASSTOR_COMP(HT, MASSTOR_COMP(XHK, POL));
    }
  }
  POL = NOETHER_NOESRT(POL);
  return POL;
}

static void COMPARE
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST SKL, MASSTOR_LIST SKP, MASSTOR_LIST TERM, MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(SG, SKL, SKP, TERM, BASE, POL)
MASSTOR_LIST SG, SKL, SKP, TERM;
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST HK, HT, XHK, XHT, XX, YY, PROD, RES, NSKL, DUMMY;
  MASELEM_GAMMAINT I, J, N, ORDER;

  *BASE = MASSTOR_SIL;
  *POL = 0;
  if (SG == MASSTOR_SIL) {
    return;
  }
  YY = SUBST_SUBORP(SG, DIPC_DIPFMO(SACRN_RNINT(1), TERM));
  if (YY == 0) {
    return;
  }
  ORDER = SUBST_SUBORD(SG);
  if (SKP == 0) {
    return;
  }
  N = MASSTOR_LENGTH(SKL);
  if (N == 0) {
    return;
  }
  NSKL = MASSTOR_SIL;
  for (I = N; I >= 1; I += -1) {
    NSKL = MASSTOR_COMP(NOETHER_NOEPRM(SACLIST_LELT(SKL, I), TERM), NSKL);
  }
  RES = MASSTOR_SIL;
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SKP ", 4L);
  SACLIST_OWRITE(SKP);
  while (SKP != MASSTOR_SIL) {
    DIPC_DIPMAD(SKP, &HK, &HT, &SKP);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("HT = ", 5L);
    SACLIST_OWRITE(HT);
    PROD = MASSTOR_SIL;
    {
      LONGINT B_11 = 1, B_12 = N;

      if (B_11 <= B_12)
        for (I = B_11;; I += 1) {
          {
            LONGINT B_13 = 1, B_14 = SACLIST_LELT(HT, I);

            if (B_13 <= B_14)
              for (J = B_13;; J += 1) {
                PROD = NOETHER_NOEPPR(PROD, SACLIST_LELT(NSKL, I), TERM);
                if (J >= B_14) break;
              }
          }
          if (I >= B_12) break;
        }
    }
    RES = NOETHER_NOEPSM(RES, NOETHER_NOEPIP(PROD, HK));
  }
  for (;;) {
    if (RES == MASSTOR_SIL) {
      return;
    }
    DIPC_DIPMAD(RES, &XHK, &XHT, &RES);
    if (SACLIST_EQUAL(XHT, TERM) == 1) {
      DIPC_DIPMAD(XHK, BASE, POL, &DUMMY);
      goto EXIT_2;
    }
  } EXIT_2:;
  XX = SUBST_SUBCHK(SG, *BASE, *POL);
  if (XX == 0) {
    return;
  }
  DIPC_DIPMAD(XX, &HK, &HT, &DUMMY);
  *POL = DIPRN_DIRPRQ(*POL, HK);
  DIPC_DIPMAD(YY, &HK, &HT, &DUMMY);
  *POL = DIPRN_DIRPRP(*POL, HK);
}

static void SUBBRM
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(SG, BASE, POL)
MASSTOR_LIST SG;
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST XBASE, NBASE, NPOL, NHT, HT, HK, XX, YY, EL, DUMMY;
  MASELEM_GAMMAINT I, K, N;

  if (*POL == 0) {
    *BASE = MASSTOR_SIL;
  }
  if (*BASE == MASSTOR_SIL) {
    return;
  }
  NBASE = *BASE;
  *BASE = MASSTOR_SIL;
  N = 0;
  while (NBASE != MASSTOR_SIL) {
    MASSTOR_ADV(NBASE, &XX, &NBASE);
    *BASE = MASSTOR_COMP(XX, *BASE);
    N = N + 1;
    XBASE = MASSTOR_SIL;
    K = 0;
    {
      LONGINT B_15 = 1, B_16 = MASSTOR_LENGTH(NBASE);

      if (B_15 <= B_16)
        for (I = B_15;; I += 1) {
          YY = SACLIST_LELT(NBASE, I);
          if (DIPRN_DIRPDF(SUBST_SUBORP(SG, XX), SUBST_SUBORP(SG, YY)) == 0) {
            NPOL = *POL;
            *POL = 0;
            while (NPOL != MASSTOR_SIL) {
              DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
              DIPC_EVDEL(HT, N + I - K, &NHT, &EL);
              DIPC_EVCADD(NHT, N, EL, &HT, &DUMMY);
              *POL = DIPRN_DIRPSM(*POL, DIPC_DIPFMO(HK, HT));
            }
            K = K + 1;
          } else {
            XBASE = MASSTOR_COMP(YY, XBASE);
          }
          if (I >= B_16) break;
        }
    }
    NBASE = MASSTOR_INV(XBASE);
  }
  *BASE = MASSTOR_INV(*BASE);
}

void SUBST_SUBRED
# ifdef __STDC__
(MASSTOR_LIST SG, MASSTOR_LIST POL, MASSTOR_LIST *BASE, MASSTOR_LIST *BASEPOL, MASSTOR_LIST *REMPOL)
# else
(SG, POL, BASE, BASEPOL, REMPOL)
MASSTOR_LIST SG, POL;
MASSTOR_LIST *BASE, *BASEPOL, *REMPOL;
# endif
{
  MASSTOR_LIST HK, HT, SKL, SKP, PSM, BASE1, BASEPOL1, XX, DUMMY;
  MASELEM_GAMMAINT ORDER, DEGREE, KK, I;

  *BASE = MASSTOR_SIL;
  *BASEPOL = MASSTOR_SIL;
  *REMPOL = 0;
  if (POL == 0 || SG == MASSTOR_SIL) {
    return;
  }
  ORDER = MASSTOR_LENGTH(SG);
  if (SUBST_SUBSYM(SG, POL) != 1) {
    *REMPOL = POL;
  } else {
    SKL = MASSTOR_SIL;
    {
      LONGINT B_17 = 1, B_18 = ORDER;

      if (B_17 <= B_18)
        for (I = B_17;; I += 1) {
          SKL = MASSTOR_COMP(SUBST_SUBPOW(SG, I), SKL);
          if (I >= B_18) break;
        }
    }
    while (POL != MASSTOR_SIL) {
      DIPC_DIPMAD(POL, &HK, &HT, &POL);
      DEGREE = DIPC_EVTDEG(HT);
      if (DEGREE <= ORDER) {
        BASE1 = MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), HT));
        BASEPOL1 = DIPC_DIPFMO(HK, MASSTOR_LIST1(1));
      } else {
        SKP = NOETHER_NOEL32(ORDER, DEGREE);
        COMPARE(SG, SKL, SKP, HT, &BASE1, &BASEPOL1);
        BASEPOL1 = DIPRN_DIRPRP(BASEPOL1, HK);
      }
      NOETHER_MERGE(TRUE, BASE1, BASEPOL1, BASE, BASEPOL);
    }
  }
  SUBBRM(SG, BASE, BASEPOL);
  GSYMFURN_GRNCHKBAS(BASE, BASEPOL);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("SUBRED exit (BASE): ", 20L);
  SACLIST_OWRITE(*BASE);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SUBRED exit (BASEPOL): ", 23L);
  SACLIST_OWRITE(*BASEPOL);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("SUBRED exit (REMPOL): ", 22L);
  SACLIST_OWRITE(*REMPOL);
}

void BEGIN_SUBST()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_LINALGRN();
    BEGIN_DIPRN();
    BEGIN_DIPC();
    BEGIN_GSYMFUIN();
    BEGIN_GSYMFURN();
    BEGIN_NOETHER();

  }
}
