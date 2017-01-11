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

CHAR NOETHER_rcsid [] = "$Id: NOETHER.md,v 1.1 1995/11/05 15:57:31 pesch Exp $";
CHAR NOETHER_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: NOETHER.mi,v 1.1 1995/11/05 15:57:33 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static MASSTOR_LIST NOEMLT ARGS((MASSTOR_LIST POL, MASSTOR_LIST HK, MASSTOR_LIST HT, MASSTOR_LIST TERM));
static void COMPARE ARGS((MASSTOR_LIST PG, MASSTOR_LIST SKL, MASSTOR_LIST SKP, MASSTOR_LIST TERM, MASSTOR_LIST *BASE, MASSTOR_LIST *POL));


void NOETHER_NOEINF
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Noether Polynomial System Package:", 34L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("----------------------------------", 34L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("    SK_Polynom := NOEL32(Number_of_Variables, Degree).", 54L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  SK_Power_Sum := NOEPOW(PG, Degree).", 37L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("NOENSP(PG).", 11L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("NOEINF().", 9L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("NOERED(PG, Polynom, Base, Base_Polynom, Remainder_Polynom).", 59L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("       Sum_Pol := NOEPSM(Polynom_1, Polynom_2).", 47L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("      Mult_Pol := NOEPPR(Polynom_1, Polynom_2, Term).", 53L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    Factor_Pol := NOEPIP(Polynom, Factor).", 42L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("    Remove_Pol := NOEPRM(Polynom, Term).", 40L);
  MASBIOS_BLINES(1);
}

void NOETHER_NOENSP
# ifdef __STDC__
(MASSTOR_LIST PG)
# else
(PG)
MASSTOR_LIST PG;
# endif
{
  MASSTOR_LIST SPG, ORBIT_SPG, ORBIT_PG, TERM;
  MASELEM_GAMMAINT I, N, EL, POS, ORDER, NR1, NR2;
  BOOLEAN FLAG;

  NR1 = 0;
  NR2 = 0;
  if (PG == MASSTOR_SIL) {
    return;
  }
  ORDER = GSYMFUIN_GSYORD(PG);
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PG));
  SPG = GSYMFUIN_GSYSPG(N);
  TERM = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = N;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        TERM = MASSTOR_COMP(0, TERM);
        if (I >= B_2) break;
      }
  }
  for (;;) {
    for (;;) {
      POS = 1;
      EL = SACLIST_LELT(TERM, POS);
      {
        LONGINT B_3 = 2, B_4 = N;

        if (B_3 <= B_4)
          for (I = B_3;; I += 1) {
            if (EL > SACLIST_LELT(TERM, I)) {
              POS = I;
              EL = SACLIST_LELT(TERM, POS);
            }
            if (I >= B_4) break;
          }
      }
      SACLIST_SLELT(TERM, POS, EL + 1);
      if (POS < N) {
        {
          LONGINT B_5 = POS + 1, B_6 = N;

          if (B_5 <= B_6)
            for (I = B_5;; I += 1) {
              SACLIST_SLELT(TERM, I, 0);
              if (I >= B_6) break;
            }
        }
      }
      if (DIPC_EVTDEG(TERM) <= ORDER || MASSTOR_FIRST(TERM) > ORDER) {
        goto EXIT_2;
      }
    } EXIT_2:;
    if (MASSTOR_FIRST(TERM) > ORDER) {
      goto EXIT_1;
    }
    I = 1;
    for (;;) {
      if (I + 1 > N) {
        goto EXIT_3;
      }
      if (SACLIST_LELT(TERM, I) - SACLIST_LELT(TERM, I + 1) > 1) {
        goto EXIT_3;
      }
      I = I + 1;
    } EXIT_3:;
    FLAG = I == N && SACLIST_LELT(TERM, N) == 0 || SACLIST_LELT(TERM, 1) == 1;
    ORBIT_SPG = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), TERM));
    while (ORBIT_SPG != 0) {
      NR1 = NR1 + 1;
      if (FLAG) {
        NR2 = NR2 + 1;
      }
      ORBIT_PG = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), MASSTOR_FIRST(ORBIT_SPG)));
      ORBIT_SPG = DIPRN_DIRPDF(ORBIT_SPG, ORBIT_PG);
    }
  } EXIT_1:;
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("There are ", 10L);
  SACLIST_OWRITE(NR2);
  MASBIOS_SWRITE(" special and altogether ", 24L);
  SACLIST_OWRITE(NR1);
  MASBIOS_SWRITE(" polynomial(s) with total degree <= ", 36L);
  SACLIST_OWRITE(ORDER);
  MASBIOS_SWRITE(".", 1L);
}

MASSTOR_LIST NOETHER_NOEL32
# ifdef __STDC__
(MASELEM_GAMMAINT M, MASELEM_GAMMAINT K)
# else
(M, K)
MASELEM_GAMMAINT M, K;
# endif
{
  MASSTOR_LIST SPO, SL, SLEL, XSL, SR, SREL, XSR, POL, PP1, PP2, HK, HT, SHT, SPG, XLS, SIGN, DUMMY;
  MASELEM_GAMMAINT I, J, EL;

  SPO = 0;
  if (M == 0 || K == 0) {
    return SPO;
  }
  SPG = GSYMFUIN_GSYSPG(M);
  SL = MASSTOR_SIL;
  {
    LONGINT B_7 = 1, B_8 = M;

    if (B_7 <= B_8)
      for (I = B_7;; I += 1) {
        HT = MASSTOR_SIL;
        {
          LONGINT B_9 = 1, B_10 = M;

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
        SL = MASSTOR_COMP(DIPC_DIPFMO(SACRN_RNINT(1), HT), SL);
        if (I >= B_8) break;
      }
  }
  SL = MASSTOR_INV(SL);
  SR = MASSTOR_SIL;
  {
    LONGINT B_11 = 1, B_12 = M;

    if (B_11 <= B_12)
      for (I = B_11;; I += 1) {
        POL = SACLIST_LELT(SL, I);
        SIGN = SACRN_RNINT(1);
        for (J = I - 1; J >= 1; J += -1) {
          SIGN = SACRN_RNNEG(SIGN);
          POL = DIPRN_DIRPSM(POL, DIPRN_DIRPRQ(DIPRN_DIRPPR(SACLIST_LELT(SR, J), SACLIST_LELT(SL, J)), SIGN));
        }
        SR = MASSTOR_COMP(DIPRN_DIRPRQ(POL, SACRN_RNPROD(SIGN, SACRN_RNINT(I))), SR);
        if (I >= B_12) break;
      }
  }
  HT = MASSTOR_LIST1(K);
  {
    LONGINT B_13 = 1, B_14 = M - 1;

    if (B_13 <= B_14)
      for (I = B_13;; I += 1) {
        HT = MASSTOR_COMP(0, HT);
        if (I >= B_14) break;
      }
  }
  POL = GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), HT));
  SL = MASSTOR_SIL;
  {
    LONGINT B_15 = 1, B_16 = M;

    if (B_15 <= B_16)
      for (I = B_15;; I += 1) {
        HT = MASSTOR_SIL;
        {
          LONGINT B_17 = 1, B_18 = I;

          if (B_17 <= B_18)
            for (J = B_17;; J += 1) {
              HT = MASSTOR_COMP(1, HT);
              if (J >= B_18) break;
            }
        }
        {
          LONGINT B_19 = I + 1, B_20 = M;

          if (B_19 <= B_20)
            for (J = B_19;; J += 1) {
              HT = MASSTOR_COMP(0, HT);
              if (J >= B_20) break;
            }
        }
        SL = MASSTOR_COMP(GSYMFURN_GRNORP(SPG, DIPC_DIPFMO(SACRN_RNINT(1), HT)), SL);
        if (I >= B_16) break;
      }
  }
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &DUMMY);
    SHT = SACLIST_CINV(HT);
    SACSET_LBIBS(SHT);
    SHT = MASSTOR_COMP(0, SHT);
    XLS = MASSTOR_SIL;
    {
      LONGINT B_21 = 1, B_22 = M;

      if (B_21 <= B_22)
        for (I = B_21;; I += 1) {
          XLS = MASSTOR_COMP(SACLIST_LELT(SHT, I + 1) - SACLIST_LELT(SHT, I), XLS);
          if (I >= B_22) break;
        }
    }
    XLS = MASSTOR_INV(XLS);
    PP1 = MASSTOR_SIL;
    {
      LONGINT B_23 = 1, B_24 = M;

      if (B_23 <= B_24)
        for (I = B_23;; I += 1) {
          PP1 = MASSTOR_COMP(0, PP1);
          if (I >= B_24) break;
        }
    }
    PP1 = DIPC_DIPFMO(SACRN_RNINT(1), PP1);
    PP2 = MASSTOR_SIL;
    {
      LONGINT B_25 = 1, B_26 = M;

      if (B_25 <= B_26)
        for (I = B_25;; I += 1) {
          PP2 = MASSTOR_COMP(0, PP2);
          if (I >= B_26) break;
        }
    }
    PP2 = DIPC_DIPFMO(SACRN_RNINT(1), PP2);
    XSR = SR;
    XSL = SL;
    while (XLS != MASSTOR_SIL) {
      MASSTOR_ADV(XLS, &EL, &XLS);
      MASSTOR_ADV(XSL, &SLEL, &XSL);
      MASSTOR_ADV(XSR, &SREL, &XSR);
      PP1 = DIPRN_DIRPPR(PP1, DIPRN_DIRPEX(SLEL, EL));
      PP2 = DIPRN_DIRPPR(PP2, DIPRN_DIRPEX(SREL, EL));
    }
    POL = DIPRN_DIRPDF(POL, DIPRN_DIRPRP(PP1, HK));
    SPO = DIPRN_DIRPSM(SPO, DIPRN_DIRPRP(PP2, HK));
  }
  return SPO;
}

void NOETHER_MERGE
# ifdef __STDC__
(BOOLEAN FLAG, MASSTOR_LIST BASE1, MASSTOR_LIST POL1, MASSTOR_LIST *BASE2, MASSTOR_LIST *POL2)
# else
(FLAG, BASE1, POL1, BASE2, POL2)
BOOLEAN FLAG;
MASSTOR_LIST BASE1, POL1;
MASSTOR_LIST *BASE2, *POL2;
# endif
{
  MASSTOR_LIST XBASE, NPOL1, NPOL2, HK1, HT1, HM1, HK2, HT2, HM2, XX, POS1, POS2, DUMMY;
  MASELEM_GAMMAINT I, J, L1, L2, N, SIGN;

  L1 = MASSTOR_LENGTH(BASE1);
  L2 = MASSTOR_LENGTH(*BASE2);
  XBASE = MASSTOR_SIL;
  POS1 = MASSTOR_SIL;
  POS2 = MASSTOR_SIL;
  I = 0;
  J = 0;
  while (*BASE2 != MASSTOR_SIL) {
    MASSTOR_ADV(*BASE2, &HM2, BASE2);
    HT2 = MASSTOR_FIRST(HM2);
    for (;;) {
      if (BASE1 != MASSTOR_SIL) {
        MASSTOR_ADV(BASE1, &HM1, &DUMMY);
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
        XBASE = MASSTOR_COMP(HM2, XBASE);
        goto EXIT_4;
      }
      if (SIGN == 0) {
        if (I < L1) {
          I = I + 1;
        }
        if (J < L2) {
          J = J + 1;
        }
        XBASE = MASSTOR_COMP(HM2, XBASE);
        BASE1 = MASSTOR_RED(BASE1);
        goto EXIT_4;
      }
      if (SIGN == -1) {
        if (I < L1) {
          I = I + 1;
        }
        POS2 = MASSTOR_COMP(J, POS2);
        XBASE = MASSTOR_COMP(HM1, XBASE);
        BASE1 = MASSTOR_RED(BASE1);
      }
    } EXIT_4:;
  }
  while (BASE1 != MASSTOR_SIL) {
    MASSTOR_ADV(BASE1, &HM1, &BASE1);
    XBASE = MASSTOR_COMP(HM1, XBASE);
    POS2 = MASSTOR_COMP(J, POS2);
  }
  *BASE2 = MASSTOR_INV(XBASE);
  N = MASSTOR_LENGTH(*BASE2);
  NPOL1 = 0;
  if (POL1 == 0) {
    POL1 = MASSTOR_SIL;
  }
  while (POL1 != MASSTOR_SIL) {
    DIPC_DIPMAD(POL1, &HK1, &HT1, &POL1);
    XX = MASSTOR_INV(SACLIST_CINV(HT1));
    {
      LONGINT B_27 = 1, B_28 = MASSTOR_LENGTH(POS1);

      if (B_27 <= B_28)
        for (I = B_27;; I += 1) {
          XX = SACLIST_LEINST(XX, SACLIST_LELT(POS1, I), 0);
          if (I >= B_28) break;
        }
    }
    NPOL1 = DIPRN_DIRPSM(DIPC_DIPFMO(HK1, XX), NPOL1);
  }
  NPOL2 = 0;
  if (*POL2 == 0) {
    *POL2 = MASSTOR_SIL;
  }
  while (*POL2 != MASSTOR_SIL) {
    DIPC_DIPMAD(*POL2, &HK2, &HT2, POL2);
    XX = MASSTOR_INV(SACLIST_CINV(HT2));
    {
      LONGINT B_29 = 1, B_30 = MASSTOR_LENGTH(POS2);

      if (B_29 <= B_30)
        for (I = B_29;; I += 1) {
          XX = SACLIST_LEINST(XX, SACLIST_LELT(POS2, I), 0);
          if (I >= B_30) break;
        }
    }
    NPOL2 = DIPRN_DIRPSM(DIPC_DIPFMO(HK2, XX), NPOL2);
  }
  if (FLAG) {
    *POL2 = DIPRN_DIRPSM(NPOL1, NPOL2);
    return;
  }
  if (NPOL1 == 0) {
    *POL2 = NPOL2;
    return;
  }
  if (NPOL2 == 0) {
    *POL2 = NPOL1;
    return;
  }
  *POL2 = DIPRN_DIRPPR(NPOL1, NPOL2);
}

MASSTOR_LIST NOETHER_NOESRT
# ifdef __STDC__
(MASSTOR_LIST POL)
# else
(POL)
MASSTOR_LIST POL;
# endif
{
  MASSTOR_LIST RES, NPOL, HK, HK1, HT, HT1, DUMMY;

  RES = MASSTOR_SIL;
  if (POL == MASSTOR_SIL) {
    return RES;
  }
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    NPOL = RES;
    RES = MASSTOR_SIL;
    for (;;) {
      if (NPOL == MASSTOR_SIL) {
        goto EXIT_5;
      }
      DIPC_DIPMAD(NPOL, &HK1, &HT1, &DUMMY);
      if (GSYMFUIN_GSYTWG(HT1, HT) == 1) {
        RES = MASSTOR_COMP(HT1, MASSTOR_COMP(HK1, RES));
        DIPC_DIPMAD(NPOL, &HK1, &HT1, &NPOL);
      } else {
        goto EXIT_5;
      }
    } EXIT_5:;
    RES = MASSTOR_COMP(HT, MASSTOR_COMP(HK, RES));
    while (NPOL != MASSTOR_SIL) {
      DIPC_DIPMAD(NPOL, &HK1, &HT1, &NPOL);
      RES = MASSTOR_COMP(HT1, MASSTOR_COMP(HK1, RES));
    }
    NPOL = RES;
    RES = MASSTOR_SIL;
    while (NPOL != MASSTOR_SIL) {
      DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
      RES = MASSTOR_COMP(HT, MASSTOR_COMP(HK, RES));
    }
  }
  return RES;
}

MASSTOR_LIST NOETHER_NOEPOW
# ifdef __STDC__
(MASSTOR_LIST PG, MASELEM_GAMMAINT K)
# else
(PG, K)
MASSTOR_LIST PG;
MASELEM_GAMMAINT K;
# endif
{
  MASSTOR_LIST POL, XPOL, NPOL, HKPOL, HKBASE, XHK, XHT, HT1, HT2, HK, HT, NHT, MO, POS, EL, XX, DUMMY;
  MASELEM_GAMMAINT I, J, N;

  POL = 0;
  XPOL = 0;
  NPOL = 0;
  if (PG == MASSTOR_SIL) {
    return POL;
  }
  N = MASSTOR_LENGTH(MASSTOR_FIRST(PG));
  HT = MASSTOR_SIL;
  for (I = N; I >= 1; I += -1) {
    HT = MASSTOR_COMP(I, HT);
  }
  POL = GSYMFURN_GRNORP(PG, DIPC_DIPFMO(SACRN_RNINT(1), HT));
  if (POL == 0) {
    POL = MASSTOR_SIL;
  }
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    I = 0;
    XX = 0;
    while (HT != MASSTOR_SIL) {
      MASSTOR_ADV(HT, &POS, &HT);
      I = I + 1;
      NHT = MASSTOR_SIL;
      {
        LONGINT B_31 = 1, B_32 = N;

        if (B_31 <= B_32)
          for (J = B_31;; J += 1) {
            if (I == J) {
              NHT = MASSTOR_COMP(1, NHT);
            } else {
              NHT = MASSTOR_COMP(0, NHT);
            }
            if (J >= B_32) break;
          }
      }
      {
        LONGINT B_33 = 1, B_34 = N;

        if (B_33 <= B_34)
          for (J = B_33;; J += 1) {
            if (POS == J) {
              NHT = MASSTOR_COMP(1, NHT);
            } else {
              NHT = MASSTOR_COMP(0, NHT);
            }
            if (J >= B_34) break;
          }
      }
      XX = DIPRN_DIRPSM(XX, DIPC_DIPFMO(SACRN_RNINT(1), NHT));
    }
    NPOL = DIPRN_DIRPSM(NPOL, DIPRN_DIRPEX(XX, K));
  }
  POL = MASSTOR_SIL;
  if (NPOL == 0) {
    NPOL = MASSTOR_SIL;
  }
  while (NPOL != MASSTOR_SIL) {
    DIPC_DIPMAD(NPOL, &HK, &HT, &NPOL);
    HT = MASSTOR_INV(HT);
    HT1 = MASSTOR_SIL;
    HT2 = MASSTOR_SIL;
    {
      LONGINT B_35 = 1, B_36 = N;

      if (B_35 <= B_36)
        for (I = B_35;; I += 1) {
          MASSTOR_ADV(HT, &EL, &HT);
          HT1 = MASSTOR_COMP(EL, HT1);
          if (I >= B_36) break;
        }
    }
    {
      LONGINT B_37 = 1, B_38 = N;

      if (B_37 <= B_38)
        for (I = B_37;; I += 1) {
          MASSTOR_ADV(HT, &EL, &HT);
          HT2 = MASSTOR_COMP(EL, HT2);
          if (I >= B_38) break;
        }
    }
    MO = DIPC_DIPFMO(HK, HT2);
    XPOL = POL;
    POL = MASSTOR_SIL;
    while (XPOL != MASSTOR_SIL) {
      DIPC_DIPMAD(XPOL, &XHK, &XHT, &XPOL);
      if (SACLIST_EQUAL(XHT, HT1) == 1) {
        XHK = DIPRN_DIRPSM(XHK, MO);
        MO = MASSTOR_SIL;
      }
      POL = MASSTOR_COMP(XHT, MASSTOR_COMP(XHK, POL));
    }
    if (MO != MASSTOR_SIL) {
      XPOL = POL;
      POL = MASSTOR_SIL;
      for (;;) {
        if (XPOL == MASSTOR_SIL) {
          goto EXIT_6;
        }
        DIPC_DIPMAD(XPOL, &XHK, &XHT, &DUMMY);
        if (GSYMFUIN_GSYTWG(XHT, HT1) == 1) {
          POL = MASSTOR_COMP(XHT, MASSTOR_COMP(XHK, POL));
          DIPC_DIPMAD(XPOL, &XHK, &XHT, &XPOL);
        } else {
          goto EXIT_6;
        }
      } EXIT_6:;
      POL = MASSTOR_COMP(HT1, MASSTOR_COMP(MO, POL));
      while (XPOL != MASSTOR_SIL) {
        DIPC_DIPMAD(XPOL, &XHK, &XHT, &XPOL);
        POL = MASSTOR_COMP(XHT, MASSTOR_COMP(XHK, POL));
      }
    }
  }
  NPOL = POL;
  POL = MASSTOR_SIL;
  while (NPOL != MASSTOR_SIL) {
    DIPC_DIPMAD(NPOL, &XHK, &XHT, &NPOL);
    DIPC_DIPMAD(XHK, &HK, &HT, &DUMMY);
    HKPOL = DIPC_DIPFMO(HK, MASSTOR_LIST1(1));
    HKBASE = MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), HT));
    XHK = MASSTOR_SIL;
    XHK = MASSTOR_COMP(HKPOL, MASSTOR_COMP(HKBASE, XHK));
    POL = MASSTOR_COMP(XHT, MASSTOR_COMP(XHK, POL));
  }
  POL = NOETHER_NOESRT(POL);
  return POL;
}

MASSTOR_LIST NOETHER_NOEPSM
# ifdef __STDC__
(MASSTOR_LIST POL1, MASSTOR_LIST POL2)
# else
(POL1, POL2)
MASSTOR_LIST POL1, POL2;
# endif
{
  MASSTOR_LIST RES, HK1, HT1, HK1POL, HK1BASE, HK2, HT2, HK2POL, HK2BASE, SIGN, DUMMY;

  RES = MASSTOR_SIL;
  if (POL2 == MASSTOR_SIL) {
    return POL1;
  }
  while (POL2 != MASSTOR_SIL) {
    DIPC_DIPMAD(POL2, &HK2, &HT2, &POL2);
    for (;;) {
      if (POL1 != MASSTOR_SIL) {
        DIPC_DIPMAD(POL1, &HK1, &HT1, &DUMMY);
        SIGN = GSYMFUIN_GSYTWG(HT2, HT1);
      } else {
        SIGN = 1;
      }
      if (SIGN == 1) {
        RES = MASSTOR_COMP(HT2, MASSTOR_COMP(HK2, RES));
        goto EXIT_7;
      }
      if (SIGN == 0) {
        DIPC_DIPMAD(HK1, &HK1BASE, &HK1POL, &DUMMY);
        DIPC_DIPMAD(HK2, &HK2BASE, &HK2POL, &DUMMY);
        NOETHER_MERGE(TRUE, HK1BASE, HK1POL, &HK2BASE, &HK2POL);
        HK2 = MASSTOR_SIL;
        HK2 = MASSTOR_COMP(HK2POL, MASSTOR_COMP(HK2BASE, HK2));
        RES = MASSTOR_COMP(HT2, MASSTOR_COMP(HK2, RES));
        DIPC_DIPMAD(POL1, &HK1, &HT1, &POL1);
        goto EXIT_7;
      }
      if (SIGN == -1) {
        RES = MASSTOR_COMP(HT1, MASSTOR_COMP(HK1, RES));
        DIPC_DIPMAD(POL1, &HK1, &HT1, &POL1);
      }
    } EXIT_7:;
  }
  while (POL1 != MASSTOR_SIL) {
    DIPC_DIPMAD(POL1, &HK1, &HT1, &POL1);
    RES = MASSTOR_COMP(HT1, MASSTOR_COMP(HK1, RES));
  }
  RES = NOETHER_NOESRT(RES);
  return RES;
}

static MASSTOR_LIST NOEMLT
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST HK, MASSTOR_LIST HT, MASSTOR_LIST TERM)
# else
(POL, HK, HT, TERM)
MASSTOR_LIST POL, HK, HT, TERM;
# endif
{
  MASSTOR_LIST RES, HKPOL, HKBASE, HK1, HT1, HK1POL, HK1BASE, XHT, DUMMY;

  RES = MASSTOR_SIL;
  if (POL == MASSTOR_SIL) {
    return RES;
  }
  DIPC_DIPMAD(HK, &HKBASE, &HKPOL, &DUMMY);
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK1, &HT1, &POL);
    XHT = DIPC_EVSUM(HT, HT1);
    if (DIPC_EVSIGN(DIPC_EVDIF(TERM, XHT)) >= 0) {
      DIPC_DIPMAD(HK1, &HK1BASE, &HK1POL, &DUMMY);
      NOETHER_MERGE(FALSE, HKBASE, HKPOL, &HK1BASE, &HK1POL);
      HK1 = MASSTOR_SIL;
      HK1 = MASSTOR_COMP(HK1POL, MASSTOR_COMP(HK1BASE, HK1));
      RES = MASSTOR_COMP(XHT, MASSTOR_COMP(HK1, RES));
    }
  }
  RES = NOETHER_NOESRT(RES);
  return RES;
}

MASSTOR_LIST NOETHER_NOEPPR
# ifdef __STDC__
(MASSTOR_LIST POL1, MASSTOR_LIST POL2, MASSTOR_LIST TERM)
# else
(POL1, POL2, TERM)
MASSTOR_LIST POL1, POL2, TERM;
# endif
{
  MASSTOR_LIST POL, HK2, HT2, RES;

  RES = MASSTOR_SIL;
  if (POL1 == MASSTOR_SIL) {
    return POL2;
  }
  if (POL2 == MASSTOR_SIL) {
    return POL1;
  }
  while (POL2 != MASSTOR_SIL) {
    DIPC_DIPMAD(POL2, &HK2, &HT2, &POL2);
    RES = NOETHER_NOEPSM(RES, NOEMLT(POL1, HK2, HT2, TERM));
  }
  return RES;
}

MASSTOR_LIST NOETHER_NOEPIP
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST FACT)
# else
(POL, FACT)
MASSTOR_LIST POL, FACT;
# endif
{
  MASSTOR_LIST RES, HK, HT, HKBASE, HKPOL, DUMMY;

  RES = MASSTOR_SIL;
  if (FACT == 0) {
    return RES;
  }
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    DIPC_DIPMAD(HK, &HKBASE, &HKPOL, &DUMMY);
    HKPOL = DIPRN_DIRPRP(HKPOL, FACT);
    HK = MASSTOR_SIL;
    HK = MASSTOR_COMP(HKPOL, MASSTOR_COMP(HKBASE, HK));
    RES = MASSTOR_COMP(HT, MASSTOR_COMP(HK, RES));
  }
  RES = NOETHER_NOESRT(RES);
  return RES;
}

MASSTOR_LIST NOETHER_NOEPRM
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST TERM)
# else
(POL, TERM)
MASSTOR_LIST POL, TERM;
# endif
{
  MASSTOR_LIST RES, HK, HT;

  RES = MASSTOR_SIL;
  if (TERM == MASSTOR_SIL) {
    return POL;
  }
  while (POL != MASSTOR_SIL) {
    DIPC_DIPMAD(POL, &HK, &HT, &POL);
    if (DIPC_EVSIGN(DIPC_EVDIF(TERM, HT)) >= 0) {
      RES = MASSTOR_COMP(HT, MASSTOR_COMP(HK, RES));
    }
  }
  RES = NOETHER_NOESRT(RES);
  return RES;
}

static void COMPARE
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST SKL, MASSTOR_LIST SKP, MASSTOR_LIST TERM, MASSTOR_LIST *BASE, MASSTOR_LIST *POL)
# else
(PG, SKL, SKP, TERM, BASE, POL)
MASSTOR_LIST PG, SKL, SKP, TERM;
MASSTOR_LIST *BASE, *POL;
# endif
{
  MASSTOR_LIST HK, HT, XHK, XHT, PROD, RES, NSKL, XX, DUMMY;
  MASELEM_GAMMAINT I, J, N;

  *BASE = MASSTOR_SIL;
  *POL = 0;
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
      LONGINT B_39 = 1, B_40 = N;

      if (B_39 <= B_40)
        for (I = B_39;; I += 1) {
          {
            LONGINT B_41 = 1, B_42 = SACLIST_LELT(HT, I);

            if (B_41 <= B_42)
              for (J = B_41;; J += 1) {
                PROD = NOETHER_NOEPPR(PROD, SACLIST_LELT(NSKL, I), TERM);
                if (J >= B_42) break;
              }
          }
          if (I >= B_40) break;
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
      goto EXIT_8;
    }
  } EXIT_8:;
  XX = GSYMFURN_GRNCHK(PG, *BASE, *POL);
  if (XX == 0) {
    return;
  }
  DIPC_DIPMAD(XX, &HK, &HT, &DUMMY);
  *POL = DIPRN_DIRPRQ(*POL, HK);
}

void NOETHER_NOERED
# ifdef __STDC__
(MASSTOR_LIST PG, MASSTOR_LIST POL, MASSTOR_LIST *BASE, MASSTOR_LIST *BASEPOL, MASSTOR_LIST *REMPOL)
# else
(PG, POL, BASE, BASEPOL, REMPOL)
MASSTOR_LIST PG, POL;
MASSTOR_LIST *BASE, *BASEPOL, *REMPOL;
# endif
{
  MASSTOR_LIST HK, HT, HM, ORBIT, SKL, SKP, PSM, BASE1, BASEPOL1, XX, DUMMY;
  MASELEM_GAMMAINT ORDER, DEGREE, KK, I;

  *BASE = MASSTOR_SIL;
  *BASEPOL = MASSTOR_SIL;
  *REMPOL = 0;
  if (POL == 0 || PG == MASSTOR_SIL) {
    return;
  }
  ORDER = GSYMFUIN_GSYORD(PG);
  SKL = MASSTOR_SIL;
  {
    LONGINT B_43 = 1, B_44 = ORDER;

    if (B_43 <= B_44)
      for (I = B_43;; I += 1) {
        SKL = MASSTOR_COMP(NOETHER_NOEPOW(PG, I), SKL);
        if (I >= B_44) break;
      }
  }
  while (POL != 0) {
    DIPC_DIPMAD(POL, &HK, &HT, &DUMMY);
    HM = DIPC_DIPFMO(HK, HT);
    ORBIT = GSYMFURN_GRNORP(PG, HM);
    if (SACLIST_EQUAL(HT, MASSTOR_FIRST(ORBIT)) == 1) {
      POL = DIPRN_DIRPDF(POL, ORBIT);
      DEGREE = DIPC_EVTDEG(HT);
      if (DEGREE <= ORDER) {
        BASE1 = MASSTOR_LIST1(DIPC_DIPFMO(SACRN_RNINT(1), HT));
        BASEPOL1 = DIPC_DIPFMO(HK, MASSTOR_LIST1(1));
      } else {
        SKP = NOETHER_NOEL32(ORDER, DEGREE);
        COMPARE(PG, SKL, SKP, HT, &BASE1, &BASEPOL1);
        BASEPOL1 = DIPRN_DIRPRP(BASEPOL1, HK);
      }
      NOETHER_MERGE(TRUE, BASE1, BASEPOL1, BASE, BASEPOL);
    } else {
      POL = DIPRN_DIRPDF(POL, HM);
      *REMPOL = DIPRN_DIRPSM(*REMPOL, HM);
    }
  }
  GSYMFURN_GRNCHKBAS(BASE, BASEPOL);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("NOERED exit (BASE): ", 20L);
  SACLIST_OWRITE(*BASE);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("NOERED exit (BASEPOL): ", 23L);
  SACLIST_OWRITE(*BASEPOL);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("NOERED exit (REMPOL): ", 22L);
  SACLIST_OWRITE(*REMPOL);
}

void BEGIN_NOETHER()
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
    BEGIN_DIPRN();
    BEGIN_DIPC();
    BEGIN_GSYMFUIN();
    BEGIN_GSYMFURN();

  }
}
