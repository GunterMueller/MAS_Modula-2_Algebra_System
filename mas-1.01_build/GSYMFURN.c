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

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_GSYMFUIN
#include "GSYMFUIN.h"
#endif

#ifndef DEFINITION_GSYMFURN
#include "GSYMFURN.h"
#endif

CHAR GSYMFURN_rcsid [] = "$Id: GSYMFURN.md,v 1.1 1995/11/05 15:57:28 pesch Exp $";
CHAR GSYMFURN_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: GSYMFURN.mi,v 1.1 1995/11/05 15:57:30 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static void EXTRACT ARGS((MASSTOR_LIST PG, MASSTOR_LIST POL_1, MASSTOR_LIST POL_2, MASSTOR_LIST POL_3, MASSTOR_LIST *BASE, MASSTOR_LIST *POL));
static void MERGE ARGS((MASELEM_GAMMAINT K, MASSTOR_LIST BASE_1, MASSTOR_LIST POL_1, MASSTOR_LIST *BASE_2, MASSTOR_LIST *POL_2));
static void REDUCE ARGS((MASSTOR_LIST PG, MASSTOR_LIST ORBIT, MASSTOR_LIST *BASE, MASSTOR_LIST *POL));


MASSTOR_LIST GSYMFURN_GRNORP
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST MO)
# else
(PG, MO)
MASSTOR_LIST PG, MO;
# endif
{
  MASSTOR_LIST HK, HT, HTL, TERM, RES, NRES, NPG, XX, DUMMY;
  MASELEM_GAMMAINT I, N, L, NL;

  RES = 0;
  L = 0;
  if (PG == MASSTOR_SIL) {
    return RES;
  }
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PG));
  if (MO == 0) {
    return RES;
  }
  if (MASSTOR_LENGTH(MO) != 2) {
    return -1;
  }
  if (MASSTOR_LENGTH(MASSTOR_FIRST(MO)) != N) {
    return -1;
  }
  DIPC_DIPMAD(MO, &HK, &HT, &DUMMY);
  HTL = MASSTOR_SIL;
  HTL = MASSTOR_COMP(HT, HTL);
  while (HTL != MASSTOR_SIL) {
    MASSTOR_ADV(HTL, &HT, &HTL);
    NPG = PG;
    while (NPG != MASSTOR_SIL) {
      MASSTOR_ADV(NPG, &XX, &NPG);
      TERM = MASSTOR_INV(SACLIST_CINV(HT));
      {
        LONGINT B_1 = 1, B_2 = N;

        if (B_1 <= B_2)
          for (I = B_1;; I += 1) {
            SACLIST_SLELT(TERM, N + 1 - SACLIST_LELT(XX, I), SACLIST_LELT(HT, N + 1 - I));
            if (I >= B_2) break;
          }
      }
      NRES = DIPRN_DIRPSM(RES, DIPC_DIPFMO(HK, TERM));
      if (NRES != 0) {
        NL = MASSTOR_LENGTH(NRES);
      } else {
        NL = 0;
      }
      if (NL > L) {
        RES = NRES;
        L = NL;
        HTL = MASSTOR_COMP(TERM, HTL);
      }
    }
  }
  return RES;
}

MASSTOR_LIST GSYMFURN_GRNOPL
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST ML)
# else
(PG, ML)
MASSTOR_LIST PG, ML;
# endif
{
  MASSTOR_LIST HM, RES;

  RES = MASSTOR_SIL;
  while (ML != MASSTOR_SIL) {
    MASSTOR_ADV(ML, &HM, &ML);
    RES = MASSTOR_COMP(GSYMFURN_GRNORP(PG, HM), RES);
  }
  return MASSTOR_INV(RES);
}

void GSYMFURN_GRNCUT
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST POL, MASSTOR_LIST *POL1, MASSTOR_LIST *POL2)
# else
(PG, POL, POL1, POL2)
MASSTOR_LIST PG, POL;
MASSTOR_LIST *POL1, *POL2;
# endif
{
  MASSTOR_LIST ORBIT, HM, HT, HK, DUMMY;

  *POL1 = 0;
  *POL2 = 0;
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &DUMMY);
    HM = DIPC_DIPFMO(HK, HT);
    ORBIT = GSYMFURN_GRNORP(PG, HM);
    if (SACLIST_EQUAL(HT, MASSTOR_FIRST(ORBIT)) == 1) {
      *POL1 = DIPRN_DIRPSM(*POL1, ORBIT);
      POL = DIPRN_DIRPDF(POL, ORBIT);
    } else {
      *POL2 = DIPRN_DIRPSM(*POL2, HM);
      POL = DIPRN_DIRPDF(POL, HM);
    }
  }
}

MASSTOR_LIST GSYMFURN_GRNCHK
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST BASE, MASSTOR_LIST POL)
# else
(PG, BASE, POL)
MASSTOR_LIST PG, BASE, POL;
# endif
{
  MASSTOR_LIST RES, HK, HT, BASE_ORBIT, PROD;
  MASELEM_GAMMAINT I, N;

  RES = 0;
  if (POL == 0) {
    return RES;
  }
  N = MASSTOR_LENGTH(BASE);
  if (N == 0) {
    return RES;
  }
  BASE_ORBIT = GSYMFURN_GRNOPL(PG, BASE);
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    if (POL == MASSTOR_SIL) {
      POL = 0;
    }
    PROD = DIPRN_DIRPEX(SACLIST_LELT(BASE_ORBIT, 1), 0);
    {
      LONGINT B_3 = 1, B_4 = N;

      if (B_3 <= B_4)
        for (I = B_3;; I += 1) {
          PROD = DIPRN_DIRPPR(PROD, DIPRN_DIRPEX(SACLIST_LELT(BASE_ORBIT, I), SACLIST_LELT(HT, I)));
          if (I >= B_4) break;
        }
    }
    RES = DIPRN_DIRPSM(RES, DIPRN_DIRPRP(PROD, HK));
  }
  return RES;
}

void GSYMFURN_GRNCHKBAS
# ifdef __STDC__
(MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(BASE, POL)
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST NBASE, NPOL, HT, HK, POS, DUMMY;
  MASELEM_GAMMAINT I, J, N1, N2;

  if (*POL == 0) {
    *BASE = MASSTOR_SIL;
  }
  if (*BASE == MASSTOR_SIL) {
    return;
  }
  N1 = MASSTOR_LENGTH(*BASE);
  NBASE = *BASE;
  *BASE = MASSTOR_SIL;
  {
    LONGINT B_5 = 1, B_6 = N1;

    if (B_5 <= B_6)
      for (I = B_5;; I += 1) {
        NPOL = *POL;
        for (;;) {
          if (NPOL == MASSTOR_SIL) {
            goto EXIT_1;
          }
          DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
          if (SACLIST_LELT(HT, I) != 0) {
            *BASE = MASSTOR_COMP(SACLIST_LELT(NBASE, I), *BASE);
            goto EXIT_1;
          }
        } EXIT_1:;
        if (I >= B_6) break;
      }
  }
  *BASE = MASSTOR_INV(*BASE);
  N2 = MASSTOR_LENGTH(*BASE);
  if (N1 == N2) {
    return;
  }
  NPOL = *POL;
  *POL = 0;
  J = 1;
  POS = MASSTOR_SIL;
  {
    LONGINT B_7 = 1, B_8 = N1;

    if (B_7 <= B_8)
      for (I = B_7;; I += 1) {
        if (J <= N2 && SACLIST_EQUAL(SACLIST_LELT(NBASE, I), SACLIST_LELT(*BASE, J)) == 1) {
          J = J + 1;
        } else {
          POS = MASSTOR_COMP(I, POS);
        }
        if (I >= B_8) break;
      }
  }
  while (NPOL != MASSTOR_SIL) {
    DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
    {
      LONGINT B_9 = 1, B_10 = MASSTOR_LENGTH(POS);

      if (B_9 <= B_10)
        for (I = B_9;; I += 1) {
          DIPC_EVDEL(HT, SACLIST_LELT(POS, I), &HT, &DUMMY);
          if (I >= B_10) break;
        }
    }
    *POL = DIPRN_DIRPSM(*POL, DIPC_DIPFMO(HK, HT));
  }
}

static void EXTRACT
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST POL_1, MASSTOR_LIST POL_2, MASSTOR_LIST POL_3, MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(PG, POL_1, POL_2, POL_3, BASE, POL)
MASSTOR_LIST PG, POL_1, POL_2, POL_3;
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST NPOL, TERM, TERM1, HT, HK, HM, ORBIT, DUMMY;
  MASELEM_GAMMAINT POS, I, N, SIGN;

  *BASE = MASSTOR_SIL;
  *POL = MASSTOR_SIL;
  if (POL_1 != 0 && POL_2 != 0) {
    TERM = MASSTOR_FIRST(POL_1);
    TERM1 = MASSTOR_FIRST(POL_2);
    SIGN = GSYMFUIN_GSYTWG(TERM, TERM1);
    if (SIGN == 0) {
      *POL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_LIST1(2));
      *BASE = MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), TERM));
    } else {
      SIGN = SIGN + 1;
      if (SIGN == 2) {
        SIGN = 1;
      }
      *POL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_COMP(1, MASSTOR_LIST1(1)));
      *BASE = SACLIST_LEINST(MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), TERM)), SIGN, DIPC_DIPFMO(SACRN_RNINT(1), TERM1));
    }
  }
  while (POL_3 != 0) {
    DIPC_DIPMAD(POL_3, &HK, &HT, &DUMMY);
    HM = DIPC_DIPFMO(HK, HT);
    ORBIT = GSYMFURN_GRNORP(PG, HM);
    POL_3 = DIPRN_DIRPDF(POL_3, ORBIT);
    if (*BASE == MASSTOR_SIL) {
      *POL = DIPC_DIPFMO(HK, MASSTOR_LIST1(1));
      *BASE = MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), HT));
    } else {
      N = MASSTOR_LENGTH(*BASE);
      POS = 0;
      for (;;) {
        POS = POS + 1;
        if (POS > N) {
          goto EXIT_2;
        }
        HM = SACLIST_LELT(*BASE, POS);
        if (GSYMFUIN_GSYTWG(MASSTOR_FIRST(HM), HT) <= 0) {
          goto EXIT_2;
        }
      } EXIT_2:;
      POS = POS - 1;
      *BASE = SACLIST_LEINST(*BASE, POS, DIPC_DIPFMO(SACRN_RNINT(1), HT));
      NPOL = *POL;
      HT = MASSTOR_SIL;
      {
        LONGINT B_11 = 1, B_12 = N;

        if (B_11 <= B_12)
          for (I = B_11;; I += 1) {
            HT = MASSTOR_COMP(0, HT);
            if (I >= B_12) break;
          }
      }
      HT = SACLIST_LEINST(HT, POS, 1);
      *POL = DIPC_DIPFMO(HK, HT);
      while (NPOL != MASSTOR_SIL) {
        DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
        HT = SACLIST_LEINST(HT, POS, 0);
        *POL = DIPRN_DIRPSM(DIPC_DIPFMO(HK, HT), *POL);
      }
    }
  }
}

static void MERGE
# ifdef __STDC__
(MASELEM_GAMMAINT K, MASSTOR_LIST BASE_1, MASSTOR_LIST POL_1, MASSTOR_LIST *BASE_2, MASSTOR_LIST *POL_2)
# else
(K, BASE_1, POL_1, BASE_2, POL_2)
MASELEM_GAMMAINT K;
MASSTOR_LIST BASE_1, POL_1;
MASSTOR_LIST *BASE_2, *POL_2;
# endif
{
  MASSTOR_LIST XBASE, NPOL1, NPOL2, HK1, HT1, HM1, HK2, HT2, HM2, POS1, POS2, DUMMY;
  MASELEM_GAMMAINT I, J, L1, L2, N, EL, SIGN;

  L1 = MASSTOR_LENGTH(BASE_1);
  L2 = MASSTOR_LENGTH(*BASE_2);
  XBASE = MASSTOR_SIL;
  POS1 = MASSTOR_SIL;
  POS2 = MASSTOR_SIL;
  I = 0;
  J = 0;
  while (*BASE_2 != MASSTOR_SIL) {
    MASSTOR_ADV(*BASE_2, &HM2, BASE_2);
    HT2 = MASSTOR_FIRST(HM2);
    for (;;) {
      if (BASE_1 != MASSTOR_SIL) {
        MASSTOR_ADV(BASE_1, &HM1, &DUMMY);
        HT1 = MASSTOR_FIRST(HM1);
        SIGN = GSYMFUIN_GSYTWG(HT2, HT1);
      } else {
        SIGN = 1;
      }
      if (SIGN == 1) {
        if (J < L2) {
          J = J + 1;
        }
        POS1 = MASSTOR_COMP(I, POS1);
        if (J != K) {
          XBASE = MASSTOR_COMP(HM2, XBASE);
        }
        goto EXIT_3;
      }
      if (SIGN == 0) {
        if (I < L1) {
          I = I + 1;
        }
        if (J < L2) {
          J = J + 1;
        }
        XBASE = MASSTOR_COMP(HM2, XBASE);
        BASE_1 = MASSTOR_RED(BASE_1);
        goto EXIT_3;
      }
      if (SIGN == -1) {
        if (I < L1) {
          I = I + 1;
        }
        POS2 = MASSTOR_COMP(J, POS2);
        XBASE = MASSTOR_COMP(HM1, XBASE);
        BASE_1 = MASSTOR_RED(BASE_1);
      }
    } EXIT_3:;
  }
  while (BASE_1 != MASSTOR_SIL) {
    MASSTOR_ADV(BASE_1, &HM1, &BASE_1);
    XBASE = MASSTOR_COMP(HM1, XBASE);
    POS2 = MASSTOR_COMP(J, POS2);
  }
  *BASE_2 = MASSTOR_INV(XBASE);
  N = MASSTOR_LENGTH(*BASE_2);
  NPOL1 = 0;
  if (POL_1 == 0) {
    POL_1 = MASSTOR_SIL;
  }
  while (POL_1 != MASSTOR_SIL) {
    DIPC_DIPMAD(POL_1, &HK1, &HT1, &POL_1);
    {
      LONGINT B_13 = 1, B_14 = MASSTOR_LENGTH(POS1);

      if (B_13 <= B_14)
        for (I = B_13;; I += 1) {
          HT1 = SACLIST_LEINST(HT1, SACLIST_LELT(POS1, I), 0);
          if (I >= B_14) break;
        }
    }
    NPOL1 = DIPRN_DIRPSM(DIPC_DIPFMO(HK1, HT1), NPOL1);
  }
  NPOL2 = 0;
  if (*POL_2 == 0) {
    *POL_2 = MASSTOR_SIL;
  }
  while (*POL_2 != MASSTOR_SIL) {
    DIPC_DIPMAD(*POL_2, &HK2, &HT2, POL_2);
    {
      LONGINT B_15 = 1, B_16 = MASSTOR_LENGTH(POS2);

      if (B_15 <= B_16)
        for (I = B_15;; I += 1) {
          HT2 = SACLIST_LEINST(HT2, SACLIST_LELT(POS2, I), 0);
          if (I >= B_16) break;
        }
    }
    NPOL2 = DIPRN_DIRPSM(DIPC_DIPFMO(HK2, HT2), NPOL2);
  }
  if (K == 0) {
    *POL_2 = DIPRN_DIRPSM(NPOL1, NPOL2);
    return;
  }
  POL_1 = 0;
  if (NPOL1 == 0) {
    NPOL1 = MASSTOR_SIL;
  }
  while (NPOL1 != MASSTOR_SIL) {
    DIPC_DIPMAD(NPOL1, &HK1, &HT1, &NPOL1);
    DIPC_EVDEL(HT1, K, &HT1, &DUMMY);
    POL_1 = DIPRN_DIRPSM(POL_1, DIPC_DIPFMO(HK1, HT1));
  }
  *POL_2 = 0;
  if (NPOL2 == 0) {
    NPOL2 = MASSTOR_SIL;
  }
  while (NPOL2 != MASSTOR_SIL) {
    DIPC_DIPMAD(NPOL2, &HK2, &HT2, &NPOL2);
    DIPC_EVDEL(HT2, K, &HT2, &EL);
    *POL_2 = DIPRN_DIRPSM(*POL_2, DIPRN_DIRPPR(DIPRN_DIRPEX(POL_1, EL), DIPC_DIPFMO(HK2, HT2)));
  }
}

static void REDUCE
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST ORBIT, MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(PG, ORBIT, BASE, POL)
MASSTOR_LIST PG, ORBIT;
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST HK, HT, HM, RED_HT, BHM, BHT, PHM, PHK, PHT, TERM, XX, XHT, XHK, SIGMA, SIGMA_TL, BTL, NBTL, ORBIT_S, ORBIT_RED, OMEGA, PBASE, PPOL, SPG, PAIRS, MAT, NMAT, RS, ROW, NROW, SIGN, XLS, KOEFF, POS, LOWER, UPPER, SUM, DUMMY;
  MASELEM_GAMMAINT ACT, LOW, MINI, MAXI, I, J, L, N;
  BOOLEAN FLAG;

  *BASE = MASSTOR_SIL;
  *POL = 0;
  if (ORBIT == 0) {
    return;
  }
  DIPC_DIPMAD(ORBIT, &HK, &HT, &DUMMY);
  N = MASSTOR_LENGTH(HT);
  HM = DIPC_DIPFMO(HK, HT);
  SIGMA = MASSTOR_SIL;
  RED_HT = MASSTOR_SIL;
  if (DIPC_EVSIGN(HT) == 0) {
    EXTRACT(PG, 0, 0, ORBIT, BASE, POL);
    return;
  }
  MAXI = 0;
  MINI = 999999;
  {
    LONGINT B_17 = 1, B_18 = N;

    if (B_17 <= B_18)
      for (I = B_17;; I += 1) {
        ACT = SACLIST_LELT(HT, I);
        if (ACT > MAXI) {
          MAXI = ACT;
        }
        if (ACT < MINI) {
          MINI = ACT;
        }
        if (I >= B_18) break;
      }
  }
  LOW = MAXI;
  I = MAXI - 1;
  while (I >= MINI) {
    J = 1;
    while (J <= N && SACLIST_LELT(HT, J) != I) {
      J = J + 1;
    }
    if (J == N + 1) {
      I = -1;
    } else {
      LOW = I;
    }
    I = I - 1;
  }
  if (LOW != MINI || LOW != 0 && MAXI > 1) {
    for (I = N; I >= 1; I += -1) {
      ACT = SACLIST_LELT(HT, I);
      if (ACT >= LOW) {
        RED_HT = MASSTOR_COMP(ACT - 1, RED_HT);
      } else {
        RED_HT = MASSTOR_COMP(ACT, RED_HT);
      }
    }
    SIGMA = DIPC_EVDIF(HT, RED_HT);
    ORBIT_S = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), SIGMA));
    ORBIT_RED = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), RED_HT));
    OMEGA = DIPRN_DIRPDF(ORBIT, DIPRN_DIRPPR(ORBIT_RED, ORBIT_S));
    EXTRACT(PG, ORBIT_RED, ORBIT_S, OMEGA, BASE, POL);
    return;
  }
  if (MAXI > 1) {
    {
      LONGINT B_19 = 1, B_20 = MAXI;

      if (B_19 <= B_20)
        for (LOW = B_19;; LOW += 1) {
          RED_HT = MASSTOR_SIL;
          for (I = N; I >= 1; I += -1) {
            ACT = SACLIST_LELT(HT, I);
            if (ACT >= LOW) {
              RED_HT = MASSTOR_COMP(ACT - 1, RED_HT);
            } else {
              RED_HT = MASSTOR_COMP(ACT, RED_HT);
            }
          }
          SIGMA = DIPC_EVDIF(HT, RED_HT);
          ORBIT_S = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), SIGMA));
          ORBIT_RED = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), RED_HT));
          OMEGA = DIPRN_DIRPDF(ORBIT, DIPRN_DIRPPR(ORBIT_RED, ORBIT_S));
          EXTRACT(PG, ORBIT_RED, ORBIT_S, OMEGA, BASE, POL);
          if (GSYMFUIN_GSYTWG(HT, MASSTOR_FIRST(MASSTOR_FIRST(*BASE))) == 1) {
            return;
          }
          if (LOW >= B_20) break;
        }
    }
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("HT = ", 5L);
  SACLIST_OWRITE(HT);
  *BASE = MASSTOR_SIL;
  *POL = MASSTOR_SIL;
  SPG = GSYMFUIN_GSYSPG(N);
  BTL = MASSTOR_SIL;
  PAIRS = MASSTOR_SIL;
  MAT = MASSTOR_SIL;
  RS = MASSTOR_SIL;
  SIGMA_TL = GSYMFUIN_GSYMLT(N);
  while (SIGMA_TL != MASSTOR_SIL) {
    MASSTOR_ADV(SIGMA_TL, &SIGMA, &SIGMA_TL);
    RED_HT = DIPC_EVDIF(HT, SIGMA);
    if (DIPC_EVSIGN(RED_HT) > 0) {
      ORBIT_RED = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), RED_HT));
      XX = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), SIGMA));
    } else {
      XX = 0;
    }
    while (XX != 0) {
      DIPC_DIPMAD(XX, &XHK, &XHT, &DUMMY);
      XX = DIPRN_DIRPDF(XX, GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), XHT)));
      ORBIT_S = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), XHT));
      EXTRACT(PG, ORBIT_RED, ORBIT_S, 0, &PBASE, &DUMMY);
      FLAG = FALSE;
      if (SACLIST_MEMBER(PBASE, PAIRS) != 1) {
        PAIRS = MASSTOR_COMP(PBASE, PAIRS);
        PPOL = DIPRN_DIRPPR(ORBIT_RED, ORBIT_S);
        FLAG = TRUE;
      } else {
        PPOL = 0;
      }
      KOEFF = MASSTOR_SIL;
      PBASE = MASSTOR_SIL;
      while (PPOL != 0) {
        DIPC_DIPMAD(PPOL, &PHK, &PHT, &DUMMY);
        PPOL = DIPRN_DIRPDF(PPOL, GSYMFURN_GRNORP(PG, DIPC_DIPFMO(PHK, PHT)));
        L = MASSTOR_LENGTH(PBASE);
        I = 0;
        for (;;) {
          I = I + 1;
          if (I > L) {
            goto EXIT_4;
          }
          PHM = SACLIST_LELT(PBASE, I);
          if (GSYMFUIN_GSYTWG(MASSTOR_FIRST(PHM), PHT) <= 0) {
            goto EXIT_4;
          }
        } EXIT_4:;
        I = I - 1;
        PBASE = SACLIST_LEINST(PBASE, I, DIPC_DIPFMO(SACRN_RNINT(1), PHT));
        KOEFF = SACLIST_LEINST(KOEFF, I, PHK);
      }
      ROW = MASSTOR_SIL;
      POS = MASSTOR_SIL;
      L = MASSTOR_LENGTH(BTL);
      NBTL = MASSTOR_INV(BTL);
      BTL = MASSTOR_SIL;
      for (;;) {
        if (PBASE == MASSTOR_SIL) {
          goto EXIT_5;
        }
        MASSTOR_ADV(PBASE, &BHM, &PBASE);
        BHT = MASSTOR_FIRST(BHM);
        MASSTOR_ADV(KOEFF, &PHK, &KOEFF);
        if (GSYMFUIN_GSYTWG(BHT, HT) < 0) {
          goto EXIT_5;
        }
        for (;;) {
          if (NBTL != MASSTOR_SIL) {
            MASSTOR_ADV(NBTL, &TERM, &DUMMY);
            SIGN = GSYMFUIN_GSYTWG(TERM, BHT);
          } else {
            SIGN = -1;
          }
          if (SIGN == 1) {
            L = L - 1;
            BTL = MASSTOR_COMP(TERM, BTL);
            ROW = MASSTOR_COMP(SACRN_RNINT(0), ROW);
            NBTL = MASSTOR_RED(NBTL);
          }
          if (SIGN == 0) {
            L = L - 1;
            BTL = MASSTOR_COMP(TERM, BTL);
            ROW = MASSTOR_COMP(PHK, ROW);
            NBTL = MASSTOR_RED(NBTL);
            goto EXIT_6;
          }
          if (SIGN == -1) {
            POS = MASSTOR_COMP(L, POS);
            BTL = MASSTOR_COMP(BHT, BTL);
            ROW = MASSTOR_COMP(PHK, ROW);
            goto EXIT_6;
          }
        } EXIT_6:;
      } EXIT_5:;
      while (NBTL != MASSTOR_SIL) {
        MASSTOR_ADV(NBTL, &TERM, &NBTL);
        BTL = MASSTOR_COMP(TERM, BTL);
        ROW = MASSTOR_COMP(SACRN_RNINT(0), ROW);
      }
      POS = MASSTOR_INV(POS);
      NMAT = MASSTOR_INV(MAT);
      MAT = MASSTOR_SIL;
      while (NMAT != MASSTOR_SIL) {
        MASSTOR_ADV(NMAT, &NROW, &NMAT);
        {
          LONGINT B_21 = 1, B_22 = MASSTOR_LENGTH(POS);

          if (B_21 <= B_22)
            for (I = B_21;; I += 1) {
              NROW = SACLIST_LEINST(NROW, SACLIST_LELT(POS, I), 0);
              if (I >= B_22) break;
            }
        }
        MAT = MASSTOR_COMP(NROW, MAT);
      }
      SUM = SACRN_RNINT(0);
      {
        LONGINT B_23 = 1, B_24 = MASSTOR_LENGTH(ROW);

        if (B_23 <= B_24)
          for (I = B_23;; I += 1) {
            SUM = SACRN_RNSUM(SUM, SACLIST_LELT(ROW, I));
            if (I >= B_24) break;
          }
      }
      if (SACRN_RNSIGN(SUM) != 0) {
        MAT = MASSTOR_COMP(ROW, MAT);
      } else {
        if (FLAG) {
          PAIRS = MASSTOR_RED(PAIRS);
        }
      }
    }
  }
  XLS = MASSTOR_SIL;
  if (MAT != MASSTOR_SIL) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("C/R = ", 6L);
    SACLIST_OWRITE(MASSTOR_LENGTH(MAT));
    MASBIOS_SWRITE("/", 1L);
    SACLIST_OWRITE(MASSTOR_LENGTH(MASSTOR_FIRST(MAT)));
    {
      LONGINT B_25 = 1, B_26 = MASSTOR_LENGTH(MASSTOR_FIRST(MAT)) - 1;

      if (B_25 <= B_26)
        for (I = B_25;; I += 1) {
          RS = MASSTOR_COMP(SACRN_RNINT(0), RS);
          if (I >= B_26) break;
        }
    }
    RS = MASSTOR_COMP(SACRN_RNINT(1), RS);
    MAT = LINALGRN_MTRANS(MAT);
    LINALGRN_RNMGELUD(MAT, &LOWER, &UPPER);
    XLS = LINALGRN_RNMSDS(LOWER, UPPER, RS);
    MASBIOS_SWRITE(" XLS = ", 7L);
    SACLIST_OWRITE(XLS);
  }
  if (XLS != MASSTOR_SIL) {
    OMEGA = ORBIT;
    while (XLS != MASSTOR_SIL) {
      MASSTOR_ADV(XLS, &XHK, &XLS);
      MASSTOR_ADV(PAIRS, &PBASE, &PAIRS);
      if (XHK != 0) {
        if (MASSTOR_LENGTH(PBASE) == 1) {
          PPOL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_LIST1(2));
        } else {
          PPOL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_COMP(1, MASSTOR_LIST1(1)));
        }
        PPOL = DIPRN_DIRPRP(PPOL, XHK);
        OMEGA = DIPRN_DIRPDF(OMEGA, GSYMFURN_GRNCHK(PG, PBASE, PPOL));
        MERGE(0, PBASE, PPOL, BASE, POL);
      }
    }
    EXTRACT(PG, 0, 0, OMEGA, &PBASE, &PPOL);
    MERGE(0, PBASE, PPOL, BASE, POL);
    GSYMFURN_GRNCHKBAS(BASE, POL);
    return;
  }
  *BASE = MASSTOR_SIL;
  *POL = MASSTOR_SIL;
  SPG = GSYMFUIN_GSYSPG(N);
  BTL = MASSTOR_SIL;
  PAIRS = MASSTOR_SIL;
  MAT = MASSTOR_SIL;
  RS = MASSTOR_SIL;
  SIGMA_TL = GSYMFUIN_GSYMLT(N);
  while (SIGMA_TL != MASSTOR_SIL) {
    MASSTOR_ADV(SIGMA_TL, &SIGMA, &SIGMA_TL);
    RED_HT = DIPC_EVDIF(HT, SIGMA);
    if (DIPC_EVSIGN(RED_HT) > 0) {
      ORBIT_S = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), SIGMA));
      XX = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), RED_HT));
    } else {
      XX = 0;
    }
    while (XX != 0) {
      DIPC_DIPMAD(XX, &XHK, &XHT, &DUMMY);
      XX = DIPRN_DIRPDF(XX, GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), XHT)));
      ORBIT_RED = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), XHT));
      EXTRACT(PG, ORBIT_RED, ORBIT_S, 0, &PBASE, &DUMMY);
      FLAG = FALSE;
      if (SACLIST_MEMBER(PBASE, PAIRS) != 1) {
        PAIRS = MASSTOR_COMP(PBASE, PAIRS);
        PPOL = DIPRN_DIRPPR(ORBIT_RED, ORBIT_S);
        FLAG = TRUE;
      } else {
        PPOL = 0;
      }
      KOEFF = MASSTOR_SIL;
      PBASE = MASSTOR_SIL;
      while (PPOL != 0) {
        DIPC_DIPMAD(PPOL, &PHK, &PHT, &DUMMY);
        PPOL = DIPRN_DIRPDF(PPOL, GSYMFURN_GRNORP(PG, DIPC_DIPFMO(PHK, PHT)));
        L = MASSTOR_LENGTH(PBASE);
        I = 0;
        for (;;) {
          I = I + 1;
          if (I > L) {
            goto EXIT_7;
          }
          PHM = SACLIST_LELT(PBASE, I);
          if (GSYMFUIN_GSYTWG(MASSTOR_FIRST(PHM), PHT) <= 0) {
            goto EXIT_7;
          }
        } EXIT_7:;
        I = I - 1;
        PBASE = SACLIST_LEINST(PBASE, I, DIPC_DIPFMO(SACRN_RNINT(1), PHT));
        KOEFF = SACLIST_LEINST(KOEFF, I, PHK);
      }
      ROW = MASSTOR_SIL;
      POS = MASSTOR_SIL;
      L = MASSTOR_LENGTH(BTL);
      NBTL = MASSTOR_INV(BTL);
      BTL = MASSTOR_SIL;
      for (;;) {
        if (PBASE == MASSTOR_SIL) {
          goto EXIT_8;
        }
        MASSTOR_ADV(PBASE, &BHM, &PBASE);
        BHT = MASSTOR_FIRST(BHM);
        MASSTOR_ADV(KOEFF, &PHK, &KOEFF);
        if (GSYMFUIN_GSYTWG(BHT, HT) < 0) {
          goto EXIT_8;
        }
        for (;;) {
          if (NBTL != MASSTOR_SIL) {
            MASSTOR_ADV(NBTL, &TERM, &DUMMY);
            SIGN = GSYMFUIN_GSYTWG(TERM, BHT);
          } else {
            SIGN = -1;
          }
          if (SIGN == 1) {
            L = L - 1;
            BTL = MASSTOR_COMP(TERM, BTL);
            ROW = MASSTOR_COMP(SACRN_RNINT(0), ROW);
            NBTL = MASSTOR_RED(NBTL);
          }
          if (SIGN == 0) {
            L = L - 1;
            BTL = MASSTOR_COMP(TERM, BTL);
            ROW = MASSTOR_COMP(PHK, ROW);
            NBTL = MASSTOR_RED(NBTL);
            goto EXIT_9;
          }
          if (SIGN == -1) {
            POS = MASSTOR_COMP(L, POS);
            BTL = MASSTOR_COMP(BHT, BTL);
            ROW = MASSTOR_COMP(PHK, ROW);
            goto EXIT_9;
          }
        } EXIT_9:;
      } EXIT_8:;
      while (NBTL != MASSTOR_SIL) {
        MASSTOR_ADV(NBTL, &TERM, &NBTL);
        BTL = MASSTOR_COMP(TERM, BTL);
        ROW = MASSTOR_COMP(SACRN_RNINT(0), ROW);
      }
      POS = MASSTOR_INV(POS);
      NMAT = MASSTOR_INV(MAT);
      MAT = MASSTOR_SIL;
      while (NMAT != MASSTOR_SIL) {
        MASSTOR_ADV(NMAT, &NROW, &NMAT);
        {
          LONGINT B_27 = 1, B_28 = MASSTOR_LENGTH(POS);

          if (B_27 <= B_28)
            for (I = B_27;; I += 1) {
              NROW = SACLIST_LEINST(NROW, SACLIST_LELT(POS, I), 0);
              if (I >= B_28) break;
            }
        }
        MAT = MASSTOR_COMP(NROW, MAT);
      }
      SUM = SACRN_RNINT(0);
      {
        LONGINT B_29 = 1, B_30 = MASSTOR_LENGTH(ROW);

        if (B_29 <= B_30)
          for (I = B_29;; I += 1) {
            SUM = SACRN_RNSUM(SUM, SACLIST_LELT(ROW, I));
            if (I >= B_30) break;
          }
      }
      if (SACRN_RNSIGN(SUM) != 0) {
        MAT = MASSTOR_COMP(ROW, MAT);
      } else {
        if (FLAG) {
          PAIRS = MASSTOR_RED(PAIRS);
        }
      }
    }
  }
  XLS = MASSTOR_SIL;
  if (MAT != MASSTOR_SIL) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("C/R = ", 6L);
    SACLIST_OWRITE(MASSTOR_LENGTH(MAT));
    MASBIOS_SWRITE("/", 1L);
    SACLIST_OWRITE(MASSTOR_LENGTH(MASSTOR_FIRST(MAT)));
    {
      LONGINT B_31 = 1, B_32 = MASSTOR_LENGTH(MASSTOR_FIRST(MAT)) - 1;

      if (B_31 <= B_32)
        for (I = B_31;; I += 1) {
          RS = MASSTOR_COMP(SACRN_RNINT(0), RS);
          if (I >= B_32) break;
        }
    }
    RS = MASSTOR_COMP(SACRN_RNINT(1), RS);
    MAT = LINALGRN_MTRANS(MAT);
    LINALGRN_RNMGELUD(MAT, &LOWER, &UPPER);
    XLS = LINALGRN_RNMSDS(LOWER, UPPER, RS);
    MASBIOS_SWRITE(" XLS = ", 7L);
    SACLIST_OWRITE(XLS);
  }
  if (XLS == MASSTOR_SIL) {
    EXTRACT(PG, 0, 0, ORBIT, BASE, POL);
    return;
  }
  OMEGA = ORBIT;
  while (XLS != MASSTOR_SIL) {
    MASSTOR_ADV(XLS, &XHK, &XLS);
    MASSTOR_ADV(PAIRS, &PBASE, &PAIRS);
    if (XHK != 0) {
      if (MASSTOR_LENGTH(PBASE) == 1) {
        PPOL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_LIST1(2));
      } else {
        PPOL = DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_COMP(1, MASSTOR_LIST1(1)));
      }
      PPOL = DIPRN_DIRPRP(PPOL, XHK);
      OMEGA = DIPRN_DIRPDF(OMEGA, GSYMFURN_GRNCHK(PG, PBASE, PPOL));
      MERGE(0, PBASE, PPOL, BASE, POL);
    }
  }
  EXTRACT(PG, 0, 0, OMEGA, &PBASE, &PPOL);
  MERGE(0, PBASE, PPOL, BASE, POL);
  GSYMFURN_GRNCHKBAS(BASE, POL);
}

void GSYMFURN_GRNRED
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST POL, MASSTOR_LIST *BASE, MASSTOR_LIST *BASE_POL, MASSTOR_LIST *REM_POL)
# else
(PG, POL, BASE, BASE_POL, REM_POL)
MASSTOR_LIST PG, POL;
MASSTOR_LIST *BASE, *BASE_POL, *REM_POL;
# endif
{
  MASSTOR_LIST HK, HT, HM, ORBIT, BASE_1, BASE_POL_1, DUMMY;
  MASELEM_GAMMAINT I;

  *BASE = MASSTOR_SIL;
  *BASE_POL = MASSTOR_SIL;
  *REM_POL = 0;
  if (POL == 0) {
    return;
  }
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &DUMMY);
    HM = DIPC_DIPFMO(HK, HT);
    ORBIT = GSYMFURN_GRNORP(PG, HM);
    if (SACLIST_EQUAL(HT, MASSTOR_FIRST(ORBIT)) == 1) {
      POL = DIPRN_DIRPDF(POL, ORBIT);
      EXTRACT(PG, 0, 0, ORBIT, &BASE_1, &BASE_POL_1);
      MERGE(0, BASE_1, BASE_POL_1, BASE, BASE_POL);
    } else {
      POL = DIPRN_DIRPDF(POL, HM);
      *REM_POL = DIPRN_DIRPSM(*REM_POL, HM);
    }
  }
  I = 1;
  while (I <= MASSTOR_LENGTH(*BASE)) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("GRNRED working... (BASE) ", 25L);
    SACLIST_OWRITE(*BASE);
    HM = SACLIST_LELT(*BASE, I);
    ORBIT = GSYMFURN_GRNORP(PG, HM);
    REDUCE(PG, ORBIT, &BASE_1, &BASE_POL_1);
    HT = MASSTOR_FIRST(HM);
    if (SACLIST_EQUAL(HT, MASSTOR_FIRST(MASSTOR_FIRST(BASE_1))) == 1) {
      I = I + 1;
    } else {
      MERGE(I, BASE_1, BASE_POL_1, BASE, BASE_POL);
    }
  }
  GSYMFURN_GRNCHKBAS(BASE, BASE_POL);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("GRNRED exit (BASE): ", 20L);
  SACLIST_OWRITE(*BASE);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("GRNRED exit (BASE_POL): ", 24L);
  SACLIST_OWRITE(*BASE_POL);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("GRNRED exit (REM_POL): ", 23L);
  SACLIST_OWRITE(*REM_POL);
}

MASSTOR_LIST GSYMFURN_GRNBAS
# ifdef __STDC__
(MASSTOR_LIST PG)
# else
(PG)
MASSTOR_LIST PG;
# endif
{
  MASSTOR_LIST BASE, XBASE, SPG, ORBIT_SPG, ORBIT_PG, POL, TERM, HK, HT;
  MASELEM_GAMMAINT I, N, MAX, NR1, NR2;

  NR1 = 0;
  NR2 = 0;
  XBASE = 0;
  BASE = MASSTOR_SIL;
  if (PG == MASSTOR_SIL) {
    return BASE;
  }
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PG));
  SPG = GSYMFUIN_GSYSPG(N);
  if (N <= 2) {
    MAX = 1;
  }
  if (N > 2) {
    MAX = N - 1;
  }
  TERM = MASSTOR_SIL;
  {
    LONGINT B_33 = 1, B_34 = N;

    if (B_33 <= B_34)
      for (I = B_33;; I += 1) {
        TERM = MASSTOR_COMP(0, TERM);
        if (I >= B_34) break;
      }
  }
  for (;;) {
    TERM = GSYMFUIN_GSYADD(TERM);
    if (MASSTOR_FIRST(TERM) > MAX) {
      goto EXIT_10;
    }
    ORBIT_SPG = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), TERM));
    while (ORBIT_SPG != 0) {
      NR1 = NR1 + 1;
      HT = MASSTOR_FIRST(ORBIT_SPG);
      ORBIT_PG = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), HT));
      ORBIT_SPG = DIPRN_DIRPDF(ORBIT_SPG, ORBIT_PG);
      REDUCE(PG, ORBIT_PG, &BASE, &POL);
      if (SACLIST_EQUAL(HT, MASSTOR_FIRST(MASSTOR_FIRST(BASE))) == 1) {
        NR2 = NR2 + 1;
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("GRNBAS working... (Term ", 24L);
        SACLIST_OWRITE(NR1);
        MASBIOS_SWRITE("/", 1L);
        SACLIST_OWRITE(NR2);
        MASBIOS_SWRITE("): ", 3L);
        SACLIST_OWRITE(HT);
        XBASE = DIPRN_DIRPSM(XBASE, DIPC_DIPFMO(SACRN_RNINT(1), HT));
      }
    }
  } EXIT_10:;
  BASE = MASSTOR_SIL;
  if (XBASE == 0) {
    XBASE = MASSTOR_SIL;
  }
  while (XBASE != MASSTOR_SIL) {
    DIPC_DIPMAD(XBASE, &HK, &HT, &XBASE);
    BASE = MASSTOR_COMP(DIPC_DIPFMO(SACRN_RNINT(1), HT), BASE);
  }
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("GRNBAS exit (BASE): ", 20L);
  SACLIST_OWRITE(BASE);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Number of special polynomials: ", 31L);
  SACLIST_OWRITE(NR1);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Number of base polynomials:    ", 31L);
  SACLIST_OWRITE(NR2);
  return BASE;
}

MASSTOR_LIST GSYMFURN_GRNGGB
# ifdef __STDC__
(MASSTOR_LIST PG)
# else
(PG)
MASSTOR_LIST PG;
# endif
{
  MASSTOR_LIST BASE, GB, SPG, ORBIT_SPG, ORBIT_PG, TERM, POL, HT, XX;
  MASELEM_GAMMAINT I, N, MAX, NR1, NR2;

  NR1 = 0;
  NR2 = 0;
  GB = MASSTOR_SIL;
  BASE = MASSTOR_SIL;
  if (PG == MASSTOR_SIL) {
    return BASE;
  }
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PG));
  SPG = GSYMFUIN_GSYSPG(N);
  if (N <= 2) {
    MAX = 1;
  }
  if (N > 2) {
    MAX = N - 1;
  }
  TERM = MASSTOR_SIL;
  {
    LONGINT B_35 = 1, B_36 = N;

    if (B_35 <= B_36)
      for (I = B_35;; I += 1) {
        TERM = MASSTOR_COMP(0, TERM);
        if (I >= B_36) break;
      }
  }
  for (;;) {
    TERM = GSYMFUIN_GSYADD(TERM);
    if (MASSTOR_FIRST(TERM) > MAX) {
      goto EXIT_11;
    }
    ORBIT_SPG = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), TERM));
    XX = MASSTOR_SIL;
    while (ORBIT_SPG != 0) {
      ORBIT_PG = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_FIRST(ORBIT_SPG)));
      ORBIT_SPG = DIPRN_DIRPDF(ORBIT_SPG, ORBIT_PG);
      XX = MASSTOR_COMP(ORBIT_PG, XX);
    }
    while (XX != MASSTOR_SIL) {
      NR1 = NR1 + 1;
      MASSTOR_ADV(XX, &ORBIT_PG, &XX);
      HT = MASSTOR_FIRST(ORBIT_PG);
      POL = DIPRNGB_DIRPNF(GB, ORBIT_PG);
      if (POL != 0) {
        NR2 = NR2 + 1;
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("GRNGGB working... (Term ", 24L);
        SACLIST_OWRITE(NR1);
        MASBIOS_SWRITE("/", 1L);
        SACLIST_OWRITE(NR2);
        MASBIOS_SWRITE("): ", 3L);
        SACLIST_OWRITE(HT);
        BASE = MASSTOR_COMP(DIPC_DIPFMO(SACRN_RNINT(1), HT), BASE);
        GB = DIPRNGB_DIRGBA(POL, GB, 0);
      }
    }
  } EXIT_11:;
  BASE = MASSTOR_INV(BASE);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("GRNGGB exit (BASE): ", 20L);
  SACLIST_OWRITE(BASE);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Number of special polynomials: ", 31L);
  SACLIST_OWRITE(NR1);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Number of base polynomials:    ", 31L);
  SACLIST_OWRITE(NR2);
  return BASE;
}

void BEGIN_GSYMFURN()
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
    BEGIN_SACSET();
    BEGIN_SACRN();
    BEGIN_LINALGRN();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_GSYMFUIN();

  }
}
