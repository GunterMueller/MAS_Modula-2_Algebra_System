#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

CHAR SACCOMB_rcsid [] = "$Id: SACCOMB.md,v 1.2 1992/02/12 13:19:07 pesch Exp $";
CHAR SACCOMB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static MASSTOR_LIST BETA1;
static CHAR rcsidi [] = "$Id: SACCOMB.mi,v 1.3 1992/10/15 16:28:16 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    INTEGER A[100 - 1 + 1];
};
struct S_2 {
    INTEGER A[100 - 1 + 1];
};


void SACCOMB_ASSPR
# ifdef __STDC__
(MASSTOR_LIST C_80_A, MASSTOR_LIST *PL, MASSTOR_LIST *ML)
# else
(C_80_A, PL, ML)
MASSTOR_LIST C_80_A;
MASSTOR_LIST *PL, *ML;
# endif
{
  MASSTOR_LIST A1, AL11, AP, I, IL, IP, J, J1Y, JL, S, S1, SP, U, UL1, US, V, VL1, VS;

  AP = C_80_A;
  U = MASSTOR_BETA;
  V = MASSTOR_BETA;
  do {
    MASSTOR_ADV(AP, &A1, &AP);
    MASSTOR_ADV(A1, &UL1, &A1);
    while (A1 != MASSTOR_SIL) {
      MASSTOR_ADV(A1, &AL11, &A1);
      UL1 = MASELEM_MASMAX(UL1, AL11);
    }
    U = MASSTOR_COMP(UL1, U);
    V = MASSTOR_COMP(0, V);
  } while (!(AP == MASSTOR_SIL));
  U = MASSTOR_INV(U);
  V = MASSTOR_INV(V);
  for (;;) {
    S = MASSTOR_BETA;
    AP = C_80_A;
    US = U;
    do {
      S1 = MASSTOR_BETA;
      MASSTOR_ADV(AP, &A1, &AP);
      MASSTOR_ADV(US, &UL1, &US);
      VS = V;
      JL = 1;
      do {
        MASSTOR_ADV(VS, &VL1, &VS);
        MASSTOR_ADV(A1, &AL11, &A1);
        if (UL1 + VL1 == AL11) {
          S1 = MASSTOR_COMP(JL, S1);
        }
        JL = JL + 1;
      } while (!(VS == MASSTOR_SIL));
      S1 = MASSTOR_INV(S1);
      S = MASSTOR_COMP(S1, S);
    } while (!(AP == MASSTOR_SIL));
    S = MASSTOR_INV(S);
    SACCOMB_SDR(S, PL, &I);
    if (*PL != MASSTOR_SIL) {
      *ML = 0;
      US = U;
      VS = V;
      do {
        MASSTOR_ADV(US, &UL1, &US);
        MASSTOR_ADV(VS, &VL1, &VS);
        J1Y = *ML + UL1;
        *ML = J1Y + VL1;
      } while (!(US == MASSTOR_SIL));
      return;
    }
    J = MASSTOR_BETA;
    SP = S;
    IP = I;
    IL = 1;
    do {
      MASSTOR_ADV(SP, &S1, &SP);
      if (IP != MASSTOR_SIL && MASSTOR_FIRST(IP) == IL) {
        IP = MASSTOR_RED(IP);
        J = SACSET_SUNION(J, S1);
      }
      IL = IL + 1;
    } while (!(IP == MASSTOR_SIL));
    US = U;
    IL = 1;
    do {
      if (I != MASSTOR_SIL && MASSTOR_FIRST(I) == IL) {
        MASSTOR_SFIRST(US, MASSTOR_FIRST(US) - 1);
        I = MASSTOR_RED(I);
      }
      US = MASSTOR_RED(US);
      IL = IL + 1;
    } while (!(I == MASSTOR_SIL));
    VS = V;
    JL = 1;
    do {
      if (J != MASSTOR_SIL && MASSTOR_FIRST(J) == JL) {
        MASSTOR_SFIRST(VS, MASSTOR_FIRST(VS) + 1);
        J = MASSTOR_RED(J);
      }
      VS = MASSTOR_RED(VS);
      JL = JL + 1;
    } while (!(J == MASSTOR_SIL));
  } EXIT_1:;
}

MASSTOR_LIST SACCOMB_CSFPAR
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C, D, LL, LP;

  C = 1;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &LL, &LP);
    D = SACI_IMP2(C, LL);
    C = SACCOMB_CSUN(C, D);
  }
  return C;
}

MASSTOR_LIST SACCOMB_CSINT
# ifdef __STDC__
(MASSTOR_LIST C_79_A, MASSTOR_LIST B)
# else
(C_79_A, B)
MASSTOR_LIST C_79_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP, J1Y;

  if (C_79_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    C = SACCOMB_DAND(C_79_A, B);
    return C;
  }
  if (C_79_A < MASSTOR_BETA) {
    J1Y = MASSTOR_FIRST(B);
    C = SACCOMB_DAND(C_79_A, J1Y);
    return C;
  }
  if (B < MASSTOR_BETA) {
    J1Y = MASSTOR_FIRST(C_79_A);
    C = SACCOMB_DAND(J1Y, B);
    return C;
  }
  CP = MASSTOR_BETA;
  AP = C_79_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    J1Y = SACCOMB_DAND(AL, BL);
    CP = MASSTOR_COMP(J1Y, CP);
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  while (CP != MASSTOR_SIL && MASSTOR_FIRST(CP) == 0) {
    CP = MASSTOR_RED(CP);
  }
  C = MASSTOR_INV(CP);
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACCOMB_CSSUB
# ifdef __STDC__
(MASSTOR_LIST C_78_A, MASSTOR_LIST B)
# else
(C_78_A, B)
MASSTOR_LIST C_78_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, TL;

  if (C_78_A < MASSTOR_BETA) {
    if (B < MASSTOR_BETA) {
      BL = B;
    } else {
      BL = MASSTOR_FIRST(B);
    }
    CL = SACCOMB_DNIMP(C_78_A, BL);
    if (CL == 0) {
      TL = 1;
    } else {
      TL = 0;
    }
    return TL;
  }
  if (B < MASSTOR_BETA) {
    TL = 0;
    return TL;
  }
  AP = C_78_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    CL = SACCOMB_DNIMP(AL, BL);
    if (CL != 0) {
      TL = 0;
      return TL;
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP != MASSTOR_SIL) {
    TL = 0;
  } else {
    TL = 1;
  }
  return TL;
}

MASSTOR_LIST SACCOMB_CSUN
# ifdef __STDC__
(MASSTOR_LIST C_77_A, MASSTOR_LIST B)
# else
(C_77_A, B)
MASSTOR_LIST C_77_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP, J1Y;

  if (C_77_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    C = SACCOMB_DOR(C_77_A, B);
    return C;
  }
  if (C_77_A < MASSTOR_BETA) {
    MASSTOR_ADV(B, &BL, &BP);
    J1Y = SACCOMB_DOR(C_77_A, BL);
    C = MASSTOR_COMP(J1Y, BP);
    return C;
  }
  if (B < MASSTOR_BETA) {
    MASSTOR_ADV(C_77_A, &AL, &AP);
    J1Y = SACCOMB_DOR(AL, B);
    C = MASSTOR_COMP(J1Y, AP);
    return C;
  }
  CP = MASSTOR_BETA;
  AP = C_77_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    J1Y = SACCOMB_DOR(AL, BL);
    CP = MASSTOR_COMP(J1Y, CP);
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    AP = BP;
  }
  C = MASSTOR_INV(CP);
  MASSTOR_SRED(CP, AP);
  return C;
}

MASSTOR_LIST SACCOMB_DAND
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST AL1, ALP, BL1, BLP, CL, CLP;

  if (AL == 0 || BL == 0) {
    CL = 0;
  } else {
    MASELEM_MASQREM(AL, 2, &ALP, &AL1);
    MASELEM_MASQREM(BL, 2, &BLP, &BL1);
    CLP = SACCOMB_DAND(ALP, BLP);
    CL = CLP + CLP;
    if (AL1 == 1 && BL1 == 1) {
      CL = CL + 1;
    }
  }
  return CL;
}

MASSTOR_LIST SACCOMB_DNIMP
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST AL1, ALP, BL1, BLP, CL, CLP;

  if (AL == 0) {
    CL = 0;
  } else {
    MASELEM_MASQREM(AL, 2, &ALP, &AL1);
    MASELEM_MASQREM(BL, 2, &BLP, &BL1);
    CLP = SACCOMB_DNIMP(ALP, BLP);
    CL = CLP + CLP;
    if (AL1 == 1 && BL1 == 0) {
      CL = CL + 1;
    }
  }
  return CL;
}

MASSTOR_LIST SACCOMB_DNOT
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST BL;

  BL = BETA1 - AL;
  return BL;
}

MASSTOR_LIST SACCOMB_DOR
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST AL1, ALP, BL1, BLP, CL, CLP;

  if (AL == 0) {
    CL = BL;
  } else {
    if (BL == 0) {
      CL = AL;
    } else {
      MASELEM_MASQREM(AL, 2, &ALP, &AL1);
      MASELEM_MASQREM(BL, 2, &BLP, &BL1);
      CLP = SACCOMB_DOR(ALP, BLP);
      CL = CLP + CLP;
      if (AL1 > 0 || BL1 > 0) {
        CL = CL + 1;
      }
    }
  }
  return CL;
}

MASSTOR_LIST SACCOMB_IBCIND
# ifdef __STDC__
(MASSTOR_LIST C_76_A, MASSTOR_LIST NL, MASSTOR_LIST KL)
# else
(C_76_A, NL, KL)
MASSTOR_LIST C_76_A, NL, KL;
# endif
{
  MASSTOR_LIST B, J1Y, KLP, NLP;

  NLP = NL - KL;
  KLP = KL + 1;
  if (C_76_A < MASSTOR_BETA && NLP < MASSTOR_BETA / C_76_A) {
    J1Y = C_76_A * NLP;
    B = J1Y / KLP;
  } else {
    J1Y = SACI_IDPR(C_76_A, NLP);
    B = SACI_IDQ(J1Y, KLP);
  }
  return B;
}

MASSTOR_LIST SACCOMB_IBCOEF
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST KL)
# else
(NL, KL)
MASSTOR_LIST NL, KL;
# endif
{
  MASSTOR_LIST C_75_A, J1Y, JL, KLP;

  J1Y = NL - KL;
  KLP = MASELEM_MASMIN(KL, J1Y);
  C_75_A = 1;
  {
    LONGINT B_1 = 0, B_2 = KLP - 1;

    if (B_1 <= B_2)
      for (JL = B_1;; JL += 1) {
        C_75_A = SACCOMB_IBCIND(C_75_A, NL, JL);
        if (JL >= B_2) break;
      }
  }
  return C_75_A;
}

MASSTOR_LIST SACCOMB_IBCPS
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST KL)
# else
(NL, KL)
MASSTOR_LIST NL, KL;
# endif
{
  MASSTOR_LIST C_74_A, B, JL;

  C_74_A = 1;
  B = 1;
  {
    LONGINT B_3 = 0, B_4 = KL - 1;

    if (B_3 <= B_4)
      for (JL = B_3;; JL += 1) {
        B = SACCOMB_IBCIND(B, NL, JL);
        C_74_A = SACI_ISUM(C_74_A, B);
        if (JL >= B_4) break;
      }
  }
  return C_74_A;
}

MASSTOR_LIST SACCOMB_IFACTL
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST C_73_A, D, KL;

  C_73_A = 1;
  D = 1;
  {
    LONGINT B_5 = 2, B_6 = NL;

    if (B_5 <= B_6)
      for (KL = B_5;; KL += 1) {
        if (KL <= MASSTOR_BETA / D) {
          D = D * KL;
        } else {
          C_73_A = SACI_IDPR(C_73_A, D);
          D = KL;
        }
        if (KL >= B_6) break;
      }
  }
  if (C_73_A == 1) {
    C_73_A = D;
  } else {
    C_73_A = SACI_IDPR(C_73_A, D);
  }
  return C_73_A;
}

MASSTOR_LIST SACCOMB_LEXNEX
# ifdef __STDC__
(MASSTOR_LIST C_72_A)
# else
(C_72_A)
MASSTOR_LIST C_72_A;
# endif
{
  MASSTOR_LIST AL, B, BL, CL, IL, JL;

  MASSTOR_ADV(C_72_A, &BL, &B);
  CL = MASSTOR_RED(BL);
  if (CL != MASSTOR_SIL) {
    B = MASSTOR_COMP(CL, B);
    return B;
  }
  IL = 1;
  while (B != MASSTOR_SIL) {
    MASSTOR_ADV(B, &AL, &B);
    IL = IL + 1;
    CL = MASSTOR_RED(AL);
    if (CL != BL) {
      {
        LONGINT B_7 = 1, B_8 = IL;

        if (B_7 <= B_8)
          for (JL = B_7;; JL += 1) {
            B = MASSTOR_COMP(CL, B);
            CL = MASSTOR_RED(CL);
            if (JL >= B_8) break;
          }
      }
      return B;
    }
    BL = AL;
  }
  return B;
}

MASSTOR_LIST SACCOMB_LPERM
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST P)
# else
(L, P)
MASSTOR_LIST L, P;
# endif
{
  MASSTOR_LIST AL, LP, PL, PP;

  LP = MASSTOR_BETA;
  PP = P;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    AL = SACLIST_LELT(L, PL);
    LP = MASSTOR_COMP(AL, LP);
  }
  LP = MASSTOR_INV(LP);
  return LP;
}

MASSTOR_LIST SACCOMB_PARTN
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST P)
# else
(NL, P)
MASSTOR_LIST NL, P;
# endif
{
  MASSTOR_LIST AL, ALP, BL, IL, J1Y, PP, Q, QL, RL;

  RL = MASSTOR_LENGTH(P);
  if (RL == 1) {
    Q = MASSTOR_BETA;
    return Q;
  }
  Q = MASSTOR_BETA;
  PP = P;
  {
    LONGINT B_9 = 1, B_10 = RL - 2;

    if (B_9 <= B_10)
      for (IL = B_9;; IL += 1) {
        MASSTOR_ADV(PP, &AL, &PP);
        Q = MASSTOR_COMP(AL, Q);
        if (IL >= B_10) break;
      }
  }
  AL = MASSTOR_FIRST(PP);
  BL = SACLIST_SECOND(PP);
  ALP = AL + 1;
  MASELEM_MASQREM(AL + BL, ALP, &QL, &RL);
  {
    LONGINT B_11 = 1, B_12 = QL - 1;

    if (B_11 <= B_12)
      for (IL = B_11;; IL += 1) {
        Q = MASSTOR_COMP(ALP, Q);
        if (IL >= B_12) break;
      }
  }
  J1Y = ALP + RL;
  Q = MASSTOR_COMP(J1Y, Q);
  Q = MASSTOR_INV(Q);
  return Q;
}

MASSTOR_LIST SACCOMB_PARTR
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  struct S_1 C_71_A;
  MASSTOR_LIST P;
  INTEGER n, HL, IL, J1Y, JL, KL;

  n = (INTEGER)NL;
  {
    LONGINT B_13 = 1, B_14 = n;

    if (B_13 <= B_14)
      for (IL = B_13;; IL += 1) {
        C_71_A.A[IL - 1] = IL;
        if (IL >= B_14) break;
      }
  }
  for (JL = n; JL >= 2; JL += -1) {
    J1Y = (INTEGER)SACM_MDRAN((MASELEM_GAMMAINT)JL);
    IL = J1Y + 1;
    KL = C_71_A.A[IL - 1];
    C_71_A.A[IL - 1] = C_71_A.A[JL - 1];
    C_71_A.A[JL - 1] = KL;
  }
  P = MASSTOR_BETA;
  IL = 1;
  do {
    HL = 0;
    JL = IL;
    do {
      KL = C_71_A.A[JL - 1];
      C_71_A.A[JL - 1] = -JL;
      JL = KL;
      HL = HL + 1;
    } while (!(C_71_A.A[JL - 1] < 0));
    P = MASSTOR_COMP((MASELEM_GAMMAINT)HL, P);
    do {
      IL = IL + 1;
    } while (!(IL > n || C_71_A.A[IL - 1] > 0));
  } while (!(IL > n));
  P = SACSET_LBIBMS(P);
  return P;
}

MASSTOR_LIST SACCOMB_PARTSS
# ifdef __STDC__
(MASSTOR_LIST PL)
# else
(PL)
MASSTOR_LIST PL;
# endif
{
  MASSTOR_LIST C_70_A, AL, B, PLP;

  C_70_A = 1;
  PLP = PL;
  while (PLP != MASSTOR_SIL) {
    MASSTOR_ADV(PLP, &AL, &PLP);
    B = SACI_IMP2(C_70_A, AL);
    C_70_A = SACCOMB_CSUN(C_70_A, B);
  }
  return C_70_A;
}

MASSTOR_LIST SACCOMB_PERMR
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  struct S_2 C_69_A;
  MASSTOR_LIST L;
  INTEGER n, IL, J1Y, JL, TL;

  n = (INTEGER)NL;
  {
    LONGINT B_15 = 1, B_16 = n;

    if (B_15 <= B_16)
      for (IL = B_15;; IL += 1) {
        C_69_A.A[IL - 1] = IL;
        if (IL >= B_16) break;
      }
  }
  for (JL = n; JL >= 1; JL += -1) {
    J1Y = (INTEGER)SACM_MDRAN((MASELEM_GAMMAINT)JL);
    IL = J1Y + 1;
    TL = C_69_A.A[IL - 1];
    C_69_A.A[IL - 1] = C_69_A.A[JL - 1];
    C_69_A.A[JL - 1] = TL;
  }
  L = MASSTOR_BETA;
  {
    LONGINT B_17 = 1, B_18 = n;

    if (B_17 <= B_18)
      for (IL = B_17;; IL += 1) {
        L = MASSTOR_COMP((MASELEM_GAMMAINT)C_69_A.A[IL - 1], L);
        if (IL >= B_18) break;
      }
  }
  return L;
}

void SACCOMB_SDR
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST *C_68_A, MASSTOR_LIST *I)
# else
(S, C_68_A, I)
MASSTOR_LIST S;
MASSTOR_LIST *C_68_A, *I;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, IL, J1Y, JL, KL, RL, S1, S2, SP, T, T1, T2, TP1, TS1;

  *C_68_A = MASSTOR_BETA;
  AS = MASSTOR_BETA;
  SP = S;
  RL = 0;
  for (;;) {
    do {
      if (SP == MASSTOR_SIL) {
        *C_68_A = MASSTOR_INV(*C_68_A);
        *I = MASSTOR_BETA;
        return;
      }
      MASSTOR_ADV(SP, &S1, &SP);
      B = SACSET_SDIFF(S1, AS);
      if (B != MASSTOR_SIL) {
        AL = MASSTOR_FIRST(B);
        *C_68_A = MASSTOR_COMP(AL, *C_68_A);
        AS = SACLIST_LINSRT(AL, AS);
        RL = RL + 1;
      }
    } while (!(B == MASSTOR_SIL));
    T1 = S1;
    TS1 = T1;
    T = MASSTOR_BETA;
    do {
      if (T1 == MASSTOR_SIL) {
        goto EXIT_2;
      }
      T2 = MASSTOR_BETA;
      TP1 = T1;
      do {
        MASSTOR_ADV(TP1, &AL, &TP1);
        IL = SACLIST_LSRCH(AL, *C_68_A);
        J1Y = RL - IL;
        JL = J1Y + 1;
        S2 = SACLIST_LELT(S, JL);
        T2 = SACSET_SUNION(T2, S2);
      } while (!(TP1 == MASSTOR_SIL));
      T2 = SACSET_SDIFF(T2, TS1);
      TS1 = SACSET_SUNION(TS1, T2);
      B = SACSET_SDIFF(T2, AS);
      T = MASSTOR_COMP(T1, T);
      T1 = T2;
    } while (!(B != MASSTOR_SIL));
    BL = MASSTOR_FIRST(B);
    AS = SACLIST_LINSRT(BL, AS);
    do {
      MASSTOR_ADV(T, &T1, &T);
      do {
        MASSTOR_ADV(T1, &AL, &T1);
        IL = SACLIST_LSRCH(AL, *C_68_A);
        J1Y = RL - IL;
        JL = J1Y + 1;
        S1 = SACLIST_LELT(S, JL);
        KL = SACLIST_LSRCH(BL, S1);
      } while (!(KL != 0));
      SACLIST_SLELT(*C_68_A, IL, BL);
      BL = AL;
    } while (!(T == MASSTOR_SIL));
    *C_68_A = MASSTOR_COMP(BL, *C_68_A);
    RL = RL + 1;
  } EXIT_2:;
  J1Y = RL + 1;
  *I = MASSTOR_LIST1(J1Y);
  while (TS1 != MASSTOR_SIL) {
    MASSTOR_ADV(TS1, &AL, &TS1);
    IL = SACLIST_LSRCH(AL, *C_68_A);
    J1Y = RL - IL;
    JL = J1Y + 1;
    *I = SACLIST_LINSRT(JL, *I);
  }
  *C_68_A = MASSTOR_BETA;
  return;
}

MASSTOR_LIST SACCOMB_SFCS
# ifdef __STDC__
(MASSTOR_LIST C_67_A)
# else
(C_67_A)
MASSTOR_LIST C_67_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, NL, RL;

  if (C_67_A == 0) {
    B = MASSTOR_BETA;
    return B;
  }
  if (C_67_A < MASSTOR_BETA) {
    AP = MASSTOR_LIST1(C_67_A);
  } else {
    AP = C_67_A;
  }
  NL = 0;
  B = MASSTOR_BETA;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = 1;
    do {
      RL = MASELEM_MASREM(AL, 2);
      AL = AL / 2;
      if (RL != 0) {
        B = MASSTOR_COMP(NL, B);
      }
      NL = NL + 1;
      BL = BL + BL;
    } while (!(BL == MASSTOR_BETA));
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

void BEGIN_SACCOMB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACSET();
    BEGIN_SACM();
    BEGIN_SACI();

    BETA1 = MASSTOR_BETA - 1;
  }
}
