#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
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

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_DIPIDEAL
#include "DIPIDEAL.h"
#endif

#ifndef DEFINITION_DIPZ
#include "DIPZ.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

#ifndef DEFINITION_SACUPFAC
#include "SACUPFAC.h"
#endif

#ifndef DEFINITION_DIPDEC0
#include "DIPDEC0.h"
#endif

CHAR DIPDEC0_rcsid [] = "$Id: DIPDEC0.md,v 1.2 1992/02/12 17:34:14 pesch Exp $";
CHAR DIPDEC0_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPDEC0.mi,v 1.3 1992/10/15 16:29:31 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    MASSTOR_LIST A[200 - 1 + 1];
};


MASSTOR_LIST DIPDEC0_DIGFET
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST IL, MASSTOR_LIST JL)
# else
(P, IL, JL)
MASSTOR_LIST P, IL, JL;
# endif
{
  MASSTOR_LIST DL, EL, IP, IS1, IS2, J1Y, PL, PP, RL, TL;

  PP = P;
  J1Y = MASSTOR_FIRST(PP);
  J1Y = DIPC_DIPNOV(J1Y);
  RL = J1Y + 1;
  IS1 = RL - IL;
  IS2 = RL - JL;
  TL = 0;
  for (;;) {
    if (PP == MASSTOR_SIL) {
      goto EXIT_1;
    }
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    IP = DIPC_EVDOV(EL);
    if (MASSTOR_FIRST(IP) == IS1) {
      DL = DIPC_EVTDEG(EL);
      if (DL == 1) {
        goto EXIT_1;
      } else {
        return TL;
      }
    }
  } EXIT_1:;
  PP = P;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    IP = DIPC_EVDOV(EL);
    if (MASSTOR_FIRST(IP) == IS2) {
      DL = DIPC_EVTDEG(EL);
      if (DL == 1) {
        TL = 1;
      }
      return TL;
    }
  }
  return TL;
}

MASSTOR_LIST DIPDEC0_DIGISM
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST DL, EL, I, IP, IS, IS1, IS2, J1Y, PL, PP, RL, TL;

  PP = P;
  IP = MASSTOR_SIL;
  for (;;) {
    while (PP != MASSTOR_SIL) {
      MASSTOR_ADV(PP, &PL, &PP);
      EL = DIPTOO_DIPDEV(PL);
      TL = DIPC_EVTDEG(EL);
      IS = DIPC_EVDOV(EL);
      if (MASSTOR_LENGTH(IS) == 1 && TL >= 2) {
        if (IP == MASSTOR_SIL) {
          IP = IS;
        } else {
          IP = SACLIST_CONC(IS, IP);
          goto EXIT_2;
        }
      }
    }
    PP = P;
    while (PP != MASSTOR_SIL) {
      MASSTOR_ADV(PP, &PL, &PP);
      EL = DIPC_DIPEVL(PL);
      DL = DIPC_EVTDEG(EL);
      if (DL >= 2) {
        EL = DIPTOO_DIPDEV(PL);
        IP = DIPC_EVDOV(EL);
        if (MASSTOR_LENGTH(IP) >= 2) {
          goto EXIT_2;
        }
      }
    }
    I = MASSTOR_SIL;
    return I;
  } EXIT_2:;
  J1Y = MASSTOR_LENGTH(EL);
  RL = J1Y + 1;
  IP = MASSTOR_INV(IP);
  SACLIST_FIRST2(IP, &IS1, &IS2);
  IS1 = RL - IS1;
  IS2 = RL - IS2;
  I = SACLIST_LIST2(IS1, IS2);
  return I;
}

MASSTOR_LIST DIPDEC0_DIGISR
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EL, I, IP, IS, IS1, IS2, J1Y, PL, PP, QL, RL;

  PP = P;
  I = MASSTOR_SIL;
  for (;;) {
    while (PP != MASSTOR_SIL) {
      MASSTOR_ADV(PP, &PL, &PP);
      EL = DIPC_DIPEVL(PL);
      IP = DIPC_EVDOV(EL);
      if (MASSTOR_LENGTH(IP) >= 2) {
        goto EXIT_3;
      }
      QL = DIPC_DIPMRD(PL);
      EL = DIPTOO_DIPDEV(QL);
      IS = DIPC_EVDOV(EL);
      IP = SACSET_USDIFF(IS, IP);
      if (MASSTOR_LENGTH(IP) >= 2) {
        goto EXIT_3;
      }
    }
    I = MASSTOR_SIL;
    return I;
  } EXIT_3:;
  J1Y = MASSTOR_LENGTH(EL);
  RL = J1Y + 1;
  IP = MASSTOR_INV(IP);
  SACLIST_FIRST2(IP, &IS1, &IS2);
  IS1 = RL - IS1;
  IS2 = RL - IS2;
  I = SACLIST_LIST2(IS1, IS2);
  return I;
}

MASSTOR_LIST DIPDEC0_DINTFE
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST IL, MASSTOR_LIST JL)
# else
(T, IL, JL)
MASSTOR_LIST T, IL, JL;
# endif
{
  MASSTOR_LIST AI, AIP, AJ, AP, AS, EINS, EL, ELS, FL, ILP, JLP, KL, N, PL, PP, PS, RL, T0, T0P, TB, TL, TP, VL, VL1, VL2, VP;

  TP = MASSTOR_SIL;
  SACLIST_ADV3(T, &FL, &VP, &PP, &TB);
  RL = MASSTOR_LENGTH(VP);
  VL1 = SACLIST_LELT(VP, IL);
  VL2 = SACLIST_LELT(VP, JL);
  VL = SACLIST_CCONC(VL1, VL2);
  VL = MASSTOR_COMP(MASBIOS_MASORD('e'), VL);
  MASBIOS_SWRITE("Introduction of the new variable ", 33L);
  SACLIST_CLOUT(VL);
  MASBIOS_BLINES(2);
  VP = MASSTOR_COMP(VL, VP);
  DIPC_VALIS = VP;
  ELS = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = RL + 1;

    if (B_1 <= B_2)
      for (KL = B_1;; KL += 1) {
        ELS = MASSTOR_COMP(0, ELS);
        if (KL >= B_2) break;
      }
  }
  ILP = IL + 1;
  JLP = JL + 1;
  EINS = SACRN_RNINT(1);
  AP = DIPC_DIPFMO(EINS, ELS);
  AI = DIPC_DIPMPV(AP, ILP, 1);
  AJ = DIPC_DIPMPV(AP, JLP, 1);
  AP = DIPC_DIPMPV(AP, 1, 1);
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    PL = DIPC_DIPINV(PL, 0, 1);
    PS = MASSTOR_COMP(PL, PS);
  }
  PP = MASSTOR_INV(PS);
  T0 = 0;
  do {
    T0 = T0 - 1;
    T0P = SACRN_RNINT(T0);
    AIP = DIPRN_DIRPRP(AI, T0P);
    AS = DIPRN_DIRPSM(AIP, AJ);
    AS = DIPRN_DIRPDF(AP, AS);
    PS = DIPRNGB_DIRGBA(AS, PP, 1);
    TL = DIPDEC0_DIGFET(PS, ILP, JLP);
  } while (!(TL == 1));
  N = DIPDEC0_DIRGZS(VP, PS, VP);
  TP = DIPDEC0_DINTZS(N);
  return TP;
}

MASSTOR_LIST DIPDEC0_DINTSR
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST FL, I, IL, JL, PP, TB, TL, TP, TS, VP;

  TP = MASSTOR_SIL;
  TB = T;
  do {
    MASSTOR_ADV(TB, &TL, &TB);
    SACLIST_FIRST3(TL, &FL, &VP, &PP);
    I = DIPDEC0_DIGISR(PP);
    if (I == MASSTOR_SIL) {
      TP = MASSTOR_COMP(TL, TP);
    } else {
      SACLIST_FIRST2(I, &IL, &JL);
      TS = DIPDEC0_DINTFE(TL, IL, JL);
      TB = SACLIST_CONC(TS, TB);
    }
  } while (!(TB == MASSTOR_SIL));
  TP = MASSTOR_INV(TP);
  return TP;
}

MASSTOR_LIST DIPDEC0_DINTSS
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST EL1, EL2, FL, FL1, I, IL, J1Y, JL, KL, PL, PL1, PP, PP1, PS, QL, RL, RLP, RLS, TB, TL, TLS, TP, VL1, VP, VP1;

  TP = MASSTOR_SIL;
  TB = T;
  if (TB == MASSTOR_SIL) {
    return TP;
  }
  J1Y = MASSTOR_FIRST(TB);
  J1Y = SACLIST_SECOND(J1Y);
  RL = MASSTOR_LENGTH(J1Y);
  do {
    MASSTOR_ADV(TB, &TL, &TB);
    SACLIST_FIRST3(TL, &FL, &VP, &PP);
    I = DIPDEC0_DIGISR(PP);
    if (I == MASSTOR_SIL) {
      I = DIPDEC0_DIGISM(PP);
    }
    if (I == MASSTOR_SIL) {
      TP = MASSTOR_COMP(TL, TP);
    } else {
      SACLIST_FIRST2(I, &IL, &JL);
      TLS = DIPDEC0_DINTFE(TL, IL, JL);
      TB = SACLIST_CONC(TLS, TB);
    }
  } while (!(TB == MASSTOR_SIL));
  TB = MASSTOR_INV(TP);
  TP = MASSTOR_SIL;
  do {
    MASSTOR_ADV(TB, &TLS, &TB);
    SACLIST_ADV3(TLS, &FL, &VP, &PP, &TLS);
    RLS = MASSTOR_LENGTH(VP);
    J1Y = RLS - RL;
    RLP = J1Y - 1;
    if (RLP >= 1) {
      SACLIST_ADV3(TLS, &FL1, &VP1, &PP1, &TLS);
      MASSTOR_ADV(VP, &VL1, &VP);
      MASSTOR_ADV(PP, &PL1, &PP);
      {
        LONGINT B_3 = 1, B_4 = RLP;

        if (B_3 <= B_4)
          for (KL = B_3;; KL += 1) {
            TLS = SACLIST_RED3(TLS);
            PP = MASSTOR_RED(PP);
            VP = MASSTOR_RED(VP);
            if (KL >= B_4) break;
          }
      }
      TLS = SACLIST_COMP3(FL1, VP1, PP1, TLS);
      VP = MASSTOR_COMP(VL1, VP);
      PP = MASSTOR_COMP(PL1, PP);
      PS = MASSTOR_SIL;
      while (PP != MASSTOR_SIL) {
        MASSTOR_ADV(PP, &PL, &PP);
        {
          LONGINT B_5 = 1, B_6 = RLP;

          if (B_5 <= B_6)
            for (KL = B_5;; KL += 1) {
              DIPC_DIPADV(PL, 2, &EL1, &EL2, &PL, &QL);
              if (KL >= B_6) break;
            }
        }
        PS = MASSTOR_COMP(PL, PS);
      }
      PP = MASSTOR_INV(PS);
    }
    TLS = SACLIST_COMP3(FL, VP, PP, TLS);
    TP = MASSTOR_COMP(TLS, TP);
  } while (!(TB == MASSTOR_SIL));
  TP = MASSTOR_INV(TP);
  return TP;
}

MASSTOR_LIST DIPDEC0_DINTZS
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  struct S_1 TUP;
  MASSTOR_LIST FL, J, NP, PL, RL, T, T1, T2, TL, TP, TS, U, V, VL, VP, VS;
  INTEGER I;

  NP = N;
  if (NP == MASSTOR_SIL) {
    T = MASSTOR_SIL;
    return T;
  }
  T = DIPDEC0_DITFZS(N);
  VS = DIPC_VALIS;
  RL = MASSTOR_LENGTH(VS);
  if (RL > 200) {
    MASERR_ERROR(MASERR_fatal, "tup overflow in DINTZS", 22L);
    return T;
  }
  for (;;) {
    TP = MASSTOR_SIL;
    while (T != MASSTOR_SIL) {
      MASSTOR_ADV(T, &TL, &T);
      T1 = MASSTOR_SIL;
      TS = MASSTOR_SIL;
      {
        LONGINT B_7 = 1, B_8 = (INTEGER)RL;

        if (B_7 <= B_8)
          for (I = B_7;; I += 1) {
            TUP.A[I - 1] = MASSTOR_SIL;
            if (I >= B_8) break;
          }
      }
      while (TL != MASSTOR_SIL) {
        SACLIST_ADV3(TL, &FL, &V, &PL, &TL);
        switch ((INTEGER)FL) {
        case 1:;
          VL = MASSTOR_FIRST(V);
          I = (INTEGER)SACPOL_VLSRCH(VL, VS);
          if (TUP.A[I - 1] != MASSTOR_SIL) {
            goto EXIT_4;
          }
          TS = MASSTOR_COMP(VL, TS);
          TUP.A[I - 1] = SACLIST_LIST3(FL, V, PL);
          break;
        case 4:;
          T1 = T1;
          break;
        case 5:;
          if (TL == MASSTOR_SIL) {
            TS = MASSTOR_SIL;
          }
          break;
        case 6:;
          T1 = SACLIST_COMP3(FL, V, PL, T1);
          break;
        case 3:;
          while (V != MASSTOR_SIL) {
            MASSTOR_ADV(V, &VL, &V);
            VP = MASSTOR_LIST1(VL);
            I = (INTEGER)SACPOL_VLSRCH(VL, VS);
            if (TUP.A[I - 1] != MASSTOR_SIL) {
              goto EXIT_4;
            }
            TS = MASSTOR_COMP(VL, TS);
            TUP.A[I - 1] = SACLIST_LIST3(FL, VP, PL);
          }
          break;
        case 2:;
          T1 = SACLIST_COMP3(FL, V, PL, T1);
          U = DIPIDEAL_DIPLDV(PL, VS);
          TS = SACSET_USUN(TS, U);
          break;
        default :
          goto EXIT_4;
          break;
        }
      }
      if (TS != MASSTOR_SIL) {
        V = SACSET_USDIFF(VS, TS);
        while (V != MASSTOR_SIL) {
          MASSTOR_ADV(V, &VL, &V);
          VP = MASSTOR_LIST1(VL);
          I = (INTEGER)SACPOL_VLSRCH(VL, VS);
          if (TUP.A[I - 1] == MASSTOR_SIL) {
            TUP.A[I - 1] = SACLIST_LIST3(3, VP, 0);
          }
        }
        T2 = MASSTOR_SIL;
        for (I = (INTEGER)RL; I >= 1; I += -1) {
          T2 = SACLIST_CONC(TUP.A[I - 1], T2);
        }
        if (MASSTOR_FIRST(T1) == 6) {
          T1 = SACLIST_CONC(T1, T2);
        } else {
          T1 = SACLIST_CONC(T2, T1);
        }
        if (SACLIST_MEMBER(T1, TP) != 1) {
          TP = MASSTOR_COMP(T1, TP);
        }
      }
    }
    T = MASSTOR_INV(TP);
    return T;
  } EXIT_4:;
  MASBIOS_SWRITE("Tup non empty", 13L);
  MASBIOS_SWRITE("I=", 2L);
  SACLIST_OWRITE((MASSTOR_LIST)I);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("TUP[I]=", 7L);
  SACLIST_OWRITE(TUP.A[I - 1]);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("T1=", 3L);
  SACLIST_OWRITE(T1);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("T2=", 3L);
  SACLIST_OWRITE(T2);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("FL=", 3L);
  SACLIST_OWRITE(FL);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("V =", 3L);
  SACLIST_OWRITE(V);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("PL=", 3L);
  SACLIST_OWRITE(PL);
  MASBIOS_BLINES(2);
  {
    LONGINT B_9 = 1, B_10 = RL;

    if (B_9 <= B_10)
      for (J = B_9;; J += 1) {
        MASBIOS_SWRITE("TUP(J)=", 7L);
        SACLIST_OWRITE(TUP.A[(INTEGER)J - 1]);
        MASBIOS_BLINES(2);
        if (J >= B_10) break;
      }
  }
  return MASSTOR_SIL;
}

MASSTOR_LIST DIPDEC0_DIRGZS
# ifdef __STDC__
(MASSTOR_LIST VB, MASSTOR_LIST PB, MASSTOR_LIST W)
# else
(VB, PB, W)
MASSTOR_LIST VB, PB, W;
# endif
{
  MASSTOR_LIST CL, EL, IL, J1Y, J2Y, KL, LEN, LL, N, NP, P, PL, PLS, PP, PS, QL, QLP, QLS, QP, QPP, QS, RL, RLS, SL, TL, V, VL, VP, VS, WL;

  P = PB;
  V = VB;
  if (P == MASSTOR_SIL) {
    N = SACLIST_LIST4(3, V, 0, MASSTOR_SIL);
    return N;
  }
  TL = DIPDIM_DIGBZT(P);
  N = MASSTOR_SIL;
  J1Y = MASSTOR_FIRST(P);
  RL = DIPC_DIPNOV(J1Y);
  J1Y = RL + 1;
  J2Y = MASSTOR_LENGTH(V);
  IL = J1Y - J2Y;
  if (TL == -1) {
    N = SACLIST_LIST4(2, W, PB, MASSTOR_SIL);
    return N;
  }
  if (TL == 1) {
    N = SACLIST_LIST4(4, W, PB, MASSTOR_SIL);
    return N;
  }
  if (RL == 1) {
    PL = MASSTOR_FIRST(P);
    PL = DIPI_DIIFRP(PL);
    DIPC_PFDIP(PL, &RLS, &QL);
    SACUPFAC_IUPFAC(QL, &SL, &CL, &QP);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &QS, &QP);
      N = SACLIST_COMP4(1, V, QS, MASSTOR_SIL, N);
    }
    return N;
  }
  if (IL == RL) {
    PL = DIPZ_DIRMPG(IL, P);
    PL = DIPI_DIIFRP(PL);
    DIPC_PFDIP(PL, &RLS, &QL);
    SACUPFAC_IUPFAC(QL, &SL, &CL, &QP);
    LEN = MASSTOR_LENGTH(QL);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &QLS, &QP);
      SACLIST_FIRST2(QLS, &SL, &QL);
      if (LEN == 1 && SL == 1) {
        PP = P;
      } else {
        QL = DIPC_DIPFP(1, QL);
        QL = DIPRN_DIRFIP(QL);
        J1Y = IL - 1;
        SL = DIPC_DIPINV(QL, 0, J1Y);
        J1Y = RL - IL;
        SL = DIPC_DIPINV(SL, IL, J1Y);
        PP = DIPRNGB_DIRGBA(SL, P, 1);
      }
      NP = SACLIST_LIST4(6, W, PP, MASSTOR_SIL);
      N = SACLIST_COMP4(1, V, QLS, NP, N);
    }
    return N;
  }
  PL = DIPZ_DIRMPG(IL, P);
  PL = DIPI_DIIFRP(PL);
  DIPC_PFDIP(PL, &RLS, &QL);
  SACUPFAC_IUPFAC(QL, &SL, &CL, &QP);
  LEN = MASSTOR_LENGTH(QP);
  MASSTOR_ADV(V, &VL, &VP);
  VL = MASSTOR_LIST1(VL);
  while (QP != MASSTOR_SIL) {
    MASSTOR_ADV(QP, &QLS, &QP);
    SACLIST_FIRST2(QLS, &SL, &QL);
    if (LEN == 1 && SL == 1) {
      PP = P;
    } else {
      QL = DIPC_DIPFP(1, QL);
      QL = DIPRN_DIRFIP(QL);
      J1Y = IL - 1;
      SL = DIPC_DIPINV(QL, 0, J1Y);
      J1Y = RL - IL;
      SL = DIPC_DIPINV(SL, IL, J1Y);
      PP = DIPRNGB_DIRGBA(SL, P, 1);
    }
    NP = DIPDEC0_DIRGZS(VP, PP, W);
    N = SACLIST_COMP4(1, VL, QLS, NP, N);
  }
  return N;
}

MASSTOR_LIST DIPDEC0_DIRLPD
# ifdef __STDC__
(MASSTOR_LIST C_171_A, MASSTOR_LIST VP)
# else
(C_171_A, VP)
MASSTOR_LIST C_171_A, VP;
# endif
{
  MASSTOR_LIST DL, EL1, EL2, FL, FLP, IL, J1Y, L, N, P, PB, PL, PP, QL, QLS, RL, RLS, SL, T, T0, T0P, T1, TL, TLS, VL, VLP, VS;

  DL = DIPDIM_DIGBZT(C_171_A);
  L = MASSTOR_SIL;
  if (DL == -1) {
    return L;
  }
  N = DIPDEC0_DIRGZS(VP, C_171_A, VP);
  T = DIPDEC0_DINTZS(N);
  DIPDEC0_DITSPL(T, &T0, &T1);
  if (T0 == MASSTOR_SIL) {
    return L;
  }
  T0 = DIPDEC0_DINTSS(T0);
  T0P = MASSTOR_SIL;
  RL = MASSTOR_LENGTH(VP);
  RLS = RL + 1;
  VS = MASSTOR_LIST1(1);
  for (IL = RL + 1; IL >= 2; IL += -1) {
    VS = MASSTOR_COMP(IL, VS);
  }
  while (T0 != MASSTOR_SIL) {
    MASSTOR_ADV(T0, &TL, &T0);
    SACLIST_FIRST3(TL, &FL, &VL, &P);
    if (MASSTOR_LENGTH(VL) > RL) {
      TLS = SACLIST_RED3(TL);
      VL = SACCOMB_LPERM(VL, VS);
      DIPC_VALIS = VL;
      PP = MASSTOR_SIL;
      IL = 0;
      if (TLS != MASSTOR_SIL) {
        TLS = SACLIST_RED3(TLS);
      }
      while (TLS != MASSTOR_SIL) {
        SACLIST_ADV3(TLS, &FLP, &VLP, &QLS, &TLS);
        IL = IL + 1;
        SACLIST_FIRST2(QLS, &SL, &QL);
        QL = DIPC_DIPFP(1, QL);
        QL = DIPRN_DIRFIP(QL);
        J1Y = IL - 1;
        PL = DIPC_DIPINV(QL, 0, J1Y);
        J1Y = RLS - IL;
        PL = DIPC_DIPINV(PL, IL, J1Y);
        PP = MASSTOR_COMP(PL, PP);
      }
      if (P != MASSTOR_SIL) {
        P = MASSTOR_RED(P);
      }
      while (P != MASSTOR_SIL) {
        MASSTOR_ADV(P, &PL, &P);
        PL = DIPC_DIPERM(PL, VS);
        PP = MASSTOR_COMP(PL, PP);
      }
      PP = DIPRNGB_DIRPGB(PP, 1);
      VL = SACLIST_CINV(VL);
      VL = MASSTOR_RED(VL);
      VL = MASSTOR_INV(VL);
      DIPC_VALIS = VL;
      PP = SACLIST_CINV(PP);
      PP = MASSTOR_RED(PP);
      PP = MASSTOR_INV(PP);
      P = PP;
      PP = MASSTOR_SIL;
      while (P != MASSTOR_SIL) {
        MASSTOR_ADV(P, &PL, &P);
        DIPC_DIPADM(PL, &EL1, &EL2, &PL, &PB);
        PP = MASSTOR_COMP(PL, PP);
      }
      P = MASSTOR_INV(PP);
    }
    J1Y = SACLIST_LIST3(FL, VL, P);
    T0P = MASSTOR_COMP(J1Y, T0P);
  }
  T0 = MASSTOR_INV(T0P);
  L = MASSTOR_SIL;
  while (T0 != MASSTOR_SIL) {
    MASSTOR_ADV(T0, &TL, &T0);
    SACLIST_FIRST3(TL, &FL, &VL, &P);
    QL = DIPIDEAL_DIRLPI(C_171_A, P, VL);
    L = MASSTOR_COMP(QL, L);
  }
  L = MASSTOR_INV(L);
  return L;
}

void DIPDEC0_DIRLPW
# ifdef __STDC__
(MASSTOR_LIST C_170_A, MASSTOR_LIST V, MASSTOR_LIST L)
# else
(C_170_A, V, L)
MASSTOR_LIST C_170_A, V, L;
# endif
{
  MASSTOR_LIST EL, LP, LS, P, Q, VL;

  MASBIOS_SWRITE("The given ideal", 15L);
  DIPRN_DIRLWR(C_170_A, V, -1);
  MASBIOS_BLINES(1);
  LP = L;
  MASBIOS_SWRITE("The decomposition of the ideal", 30L);
  MASBIOS_BLINES(2);
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &LS, &LP);
    SACLIST_FIRST4(LS, &P, &EL, &VL, &Q);
    MASBIOS_SWRITE("The prime ideal", 15L);
    DIPRN_DIRLWR(P, VL, -1);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("The primary ideal", 17L);
    DIPRN_DIRLWR(Q, VL, -1);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("The exponent is ", 16L);
    SACLIST_AWRITE(EL);
    MASBIOS_BLINES(2);
  }
  return;
}

MASSTOR_LIST DIPDEC0_DIRPDA
# ifdef __STDC__
(MASSTOR_LIST C_169_A, MASSTOR_LIST VP)
# else
(C_169_A, VP)
MASSTOR_LIST C_169_A, VP;
# endif
{
  MASSTOR_LIST DL, FL, L, N, P, QL, T, T0, T1, TL, TP, VL;

  DL = DIPDIM_DIGBZT(C_169_A);
  L = MASSTOR_SIL;
  if (DL == -1) {
    return L;
  }
  N = DIPDEC0_DIRGZS(VP, C_169_A, VP);
  T = DIPDEC0_DINTZS(N);
  DIPDEC0_DITSPL(T, &T0, &T1);
  if (T0 == MASSTOR_SIL) {
    return L;
  }
  T0 = DIPDEC0_DINTSS(T0);
  L = MASSTOR_SIL;
  while (T0 != MASSTOR_SIL) {
    MASSTOR_ADV(T0, &TL, &T0);
    SACLIST_FIRST3(TL, &FL, &VL, &P);
    QL = DIPIDEAL_DIRLPI(C_169_A, P, VL);
    L = MASSTOR_COMP(QL, L);
  }
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST DIPDEC0_DITFZS
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST EPS, FL, M, NP, PL, T, TL, TP, V;

  T = MASSTOR_SIL;
  NP = N;
  if (NP == MASSTOR_SIL) {
    T = MASSTOR_COMP(MASSTOR_SIL, T);
    return T;
  }
  while (NP != MASSTOR_SIL) {
    SACLIST_ADV4(NP, &FL, &V, &PL, &M, &NP);
    TP = DIPDEC0_DITFZS(M);
    while (TP != MASSTOR_SIL) {
      MASSTOR_ADV(TP, &TL, &TP);
      TL = SACLIST_COMP3(FL, V, PL, TL);
      T = MASSTOR_COMP(TL, T);
    }
  }
  return T;
}

void DIPDEC0_DITSPL
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST *T0, MASSTOR_LIST *T1)
# else
(T, T0, T1)
MASSTOR_LIST T;
MASSTOR_LIST *T0, *T1;
# endif
{
  MASSTOR_LIST FL, IL, J1Y, PL, RL, TL, TLP, TP, V;

  *T0 = MASSTOR_SIL;
  *T1 = MASSTOR_SIL;
  TP = T;
  if (T == MASSTOR_SIL) {
    return;
  }
  do {
    MASSTOR_ADV(TP, &TL, &TP);
    TLP = TL;
    IL = 0;
    RL = -1;
    while (TL != MASSTOR_SIL) {
      SACLIST_ADV3(TL, &FL, &V, &PL, &TL);
      switch ((INTEGER)FL) {
      case 1:;
        IL = IL + 1;
        break;
      case 2:;
        IL = IL;
        break;
      case 3:;
        IL = IL;
        break;
      case 4:;
        IL = IL;
        break;
      case 5:;
        IL = IL;
        break;
      case 6:;
        J1Y = MASSTOR_FIRST(PL);
        RL = DIPC_DIPNOV(J1Y);
        break;
      }
    }
    if (IL == RL) {
      *T0 = MASSTOR_COMP(TLP, *T0);
    } else {
      *T1 = MASSTOR_COMP(TLP, *T1);
    }
  } while (!(TP == MASSTOR_SIL));
  *T0 = MASSTOR_INV(*T0);
  *T1 = MASSTOR_INV(*T1);
}

void BEGIN_DIPDEC0()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACSET();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACRN();
    BEGIN_DIPC();
    BEGIN_DIPTOO();
    BEGIN_DIPI();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_DIPIDEAL();
    BEGIN_DIPZ();
    BEGIN_DIPDIM();
    BEGIN_SACUPFAC();

  }
}
