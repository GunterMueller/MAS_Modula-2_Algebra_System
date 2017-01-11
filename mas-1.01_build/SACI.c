#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

CHAR SACI_rcsid [] = "$Id: SACI.md,v 1.2 1992/02/12 13:19:11 pesch Exp $";
CHAR SACI_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACI.mi,v 1.4 1995/11/05 08:44:29 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    MASSTOR_LIST A[30 - 1 + 1];
};


void SACI_AADV
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *LP)
# else
(L, AL, LP)
MASSTOR_LIST L;
MASSTOR_LIST *AL, *LP;
# endif
{
  if (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, AL, LP);
  } else {
    *AL = 0;
    *LP = MASSTOR_BETA;
  }
  return;
}

MASSTOR_LIST SACI_IABSF
# ifdef __STDC__
(MASSTOR_LIST C_77_A)
# else
(C_77_A)
MASSTOR_LIST C_77_A;
# endif
{
  MASSTOR_LIST B, SL;

  SL = SACI_ISIGNF(C_77_A);
  if (SL >= 0) {
    B = C_77_A;
  } else {
    B = SACI_INEG(C_77_A);
  }
  return B;
}

MASSTOR_LIST SACI_ICOMP
# ifdef __STDC__
(MASSTOR_LIST C_76_A, MASSTOR_LIST B)
# else
(C_76_A, B)
MASSTOR_LIST C_76_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, DL, J1Y, SL, UL, VL;

  if (C_76_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    J1Y = C_76_A - B;
    SL = MASELEM_MASSIGN(J1Y);
    return SL;
  }
  if (C_76_A < MASSTOR_BETA) {
    J1Y = SACI_ISIGNF(B);
    SL = -J1Y;
    return SL;
  }
  if (B < MASSTOR_BETA) {
    SL = SACI_ISIGNF(C_76_A);
    return SL;
  }
  SL = 0;
  AP = C_76_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    UL = MASELEM_MASSIGN(AL);
    VL = MASELEM_MASSIGN(BL);
    if (UL * VL == -1) {
      SL = UL;
      return SL;
    }
    DL = AL - BL;
    if (DL != 0) {
      SL = MASELEM_MASSIGN(DL);
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return SL;
  }
  if (AP == MASSTOR_SIL) {
    J1Y = SACI_ISIGNF(BP);
    SL = -J1Y;
  } else {
    SL = SACI_ISIGNF(AP);
  }
  return SL;
}

void SACI_IDEGCD
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *UL1, MASSTOR_LIST *VL1, MASSTOR_LIST *UL2, MASSTOR_LIST *VL2)
# else
(AL, BL, CL, UL1, VL1, UL2, VL2)
MASSTOR_LIST AL, BL;
MASSTOR_LIST *CL, *UL1, *VL1, *UL2, *VL2;
# endif
{
  MASSTOR_LIST J1Y;

  SACI_IEGCD(AL, BL, CL, UL1, VL1);
  if (*CL == 0) {
    *UL2 = 0;
    *VL2 = 0;
  } else {
    J1Y = SACI_IQ(BL, *CL);
    *UL2 = SACI_INEG(J1Y);
    *VL2 = SACI_IQ(AL, *CL);
  }
  return;
}

MASSTOR_LIST SACI_IDIF
# ifdef __STDC__
(MASSTOR_LIST C_75_A, MASSTOR_LIST B)
# else
(C_75_A, B)
MASSTOR_LIST C_75_A, B;
# endif
{
  MASSTOR_LIST BP, C;

  BP = SACI_INEG(B);
  C = SACI_ISUM(C_75_A, BP);
  return C;
}

MASSTOR_LIST SACI_IDIPR2
# ifdef __STDC__
(MASSTOR_LIST C_74_A, MASSTOR_LIST B, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(C_74_A, B, AL, BL)
MASSTOR_LIST C_74_A, B, AL, BL;
# endif
{
  MASSTOR_LIST C, J1Y, J2Y;

  J1Y = SACI_IDPR(C_74_A, AL);
  J2Y = SACI_IDPR(B, BL);
  C = SACI_ISUM(J1Y, J2Y);
  return C;
}

MASSTOR_LIST SACI_IDPR
# ifdef __STDC__
(MASSTOR_LIST C_73_A, MASSTOR_LIST BL)
# else
(C_73_A, BL)
MASSTOR_LIST C_73_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, CLP, EL, FL;

  if (C_73_A == 0 || BL == 0) {
    C = 0;
    return C;
  }
  if (C_73_A < MASSTOR_BETA) {
    SACD_DPR(C_73_A, BL, &EL, &FL);
    if (EL == 0) {
      C = FL;
    } else {
      C = SACLIST_LIST2(FL, EL);
    }
    return C;
  }
  AP = C_73_A;
  C = MASSTOR_BETA;
  CLP = 0;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    SACD_DPR(AL, BL, &EL, &FL);
    CL = FL + CLP;
    CLP = EL;
    if (CL >= MASSTOR_BETA) {
      CL = CL - MASSTOR_BETA;
      CLP = CLP + 1;
    } else {
      if (CL <= -MASSTOR_BETA) {
        CL = CL + MASSTOR_BETA;
        CLP = CLP - 1;
      }
    }
    C = MASSTOR_COMP(CL, C);
  } while (!(AP == MASSTOR_SIL));
  if (CLP != 0) {
    C = MASSTOR_COMP(CLP, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACI_IDP2
# ifdef __STDC__
(MASSTOR_LIST C_72_A, MASSTOR_LIST KL)
# else
(C_72_A, KL)
MASSTOR_LIST C_72_A, KL;
# endif
{
  MASSTOR_LIST B, J1Y, QL, RL;

  if (C_72_A == 0 || KL == 0) {
    B = C_72_A;
    return B;
  }
  QL = KL / SACD_ZETA;
  J1Y = QL * SACD_ZETA;
  RL = KL - J1Y;
  B = C_72_A;
  if (B < MASSTOR_BETA) {
    B = MASSTOR_LIST1(B);
  }
  while (QL > 0 && B != MASSTOR_SIL) {
    B = MASSTOR_RED(B);
    QL = QL - 1;
  }
  if (B == MASSTOR_SIL) {
    B = 0;
    return B;
  }
  if (MASSTOR_RED(B) == MASSTOR_SIL) {
    B = MASSTOR_FIRST(B);
  }
  B = SACI_IDQ(B, SACD_TABP2.A[(INTEGER)(RL + 1) - 1]);
  return B;
}

MASSTOR_LIST SACI_IDQ
# ifdef __STDC__
(MASSTOR_LIST C_71_A, MASSTOR_LIST BL)
# else
(C_71_A, BL)
MASSTOR_LIST C_71_A, BL;
# endif
{
  MASSTOR_LIST C, RL;

  SACI_IDQR(C_71_A, BL, &C, &RL);
  return C;
}

void SACI_IDQR
# ifdef __STDC__
(MASSTOR_LIST C_70_A, MASSTOR_LIST BL, MASSTOR_LIST *Q, MASSTOR_LIST *RL)
# else
(C_70_A, BL, Q, RL)
MASSTOR_LIST C_70_A, BL;
MASSTOR_LIST *Q, *RL;
# endif
{
  MASSTOR_LIST AL0, AP, J1Y, QL;

  if (C_70_A < MASSTOR_BETA) {
    *Q = C_70_A / BL;
    J1Y = BL * *Q;
    *RL = C_70_A - J1Y;
    return;
  }
  AP = SACLIST_CINV(C_70_A);
  *Q = MASSTOR_SIL;
  *RL = 0;
  do {
    MASSTOR_ADV(AP, &AL0, &AP);
    SACD_DQR(*RL, AL0, BL, &QL, RL);
    if (QL != 0 || *Q != MASSTOR_SIL) {
      *Q = MASSTOR_COMP(QL, *Q);
    }
  } while (!(AP == MASSTOR_SIL));
  if (MASSTOR_RED(*Q) == MASSTOR_SIL) {
    *Q = MASSTOR_FIRST(*Q);
  }
  return;
}

MASSTOR_LIST SACI_IDREM
# ifdef __STDC__
(MASSTOR_LIST C_69_A, MASSTOR_LIST BL)
# else
(C_69_A, BL)
MASSTOR_LIST C_69_A, BL;
# endif
{
  MASSTOR_LIST Q, RL;

  SACI_IDQR(C_69_A, BL, &Q, &RL);
  return RL;
}

void SACI_IEGCD
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *UL1, MASSTOR_LIST *VL1)
# else
(AL, BL, CL, UL1, VL1)
MASSTOR_LIST AL, BL;
MASSTOR_LIST *CL, *UL1, *VL1;
# endif
{
  MASSTOR_LIST J1Y;

  SACI_IHEGCD(AL, BL, CL, VL1);
  if (AL == 0) {
    *UL1 = 0;
  } else {
    J1Y = SACI_IPROD(BL, *VL1);
    J1Y = SACI_IDIF(*CL, J1Y);
    *UL1 = SACI_IQ(J1Y, AL);
  }
  return;
}

BOOLEAN SACI_IEVEN
# ifdef __STDC__
(MASSTOR_LIST C_68_A)
# else
(C_68_A)
MASSTOR_LIST C_68_A;
# endif
{
  MASSTOR_LIST J1Y;
  BOOLEAN TL;

  if (C_68_A < MASSTOR_BETA) {
    TL = MASELEM_MASEVEN(C_68_A);
  } else {
    J1Y = MASSTOR_FIRST(C_68_A);
    TL = MASELEM_MASEVEN(J1Y);
  }
  return TL;
}

MASSTOR_LIST SACI_IEXP
# ifdef __STDC__
(MASSTOR_LIST C_67_A, MASSTOR_LIST NL)
# else
(C_67_A, NL)
MASSTOR_LIST C_67_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = 1;
    return B;
  }
  if (NL == 1) {
    B = C_67_A;
    return B;
  }
  KL = NL / 2;
  B = SACI_IEXP(C_67_A, KL);
  B = SACI_IPROD(B, B);
  if (NL > 2 * KL) {
    B = SACI_IPROD(B, C_67_A);
  }
  return B;
}

void SACI_IFCL2
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST *ML, MASSTOR_LIST *NL)
# else
(AL, ML, NL)
MASSTOR_LIST AL;
MASSTOR_LIST *ML, *NL;
# endif
{
  MASSTOR_LIST AL1, ALP, RL, TL;

  TL = 0;
  if (AL < MASSTOR_BETA) {
    AL1 = AL;
    *ML = 0;
  } else {
    ALP = AL;
    *ML = -SACD_ZETA;
    do {
      MASSTOR_ADV(ALP, &AL1, &ALP);
      *ML = *ML + SACD_ZETA;
      if (ALP != MASSTOR_SIL && AL1 != 0) {
        TL = 1;
      }
    } while (!(ALP == MASSTOR_SIL));
  }
  if (AL1 < 0) {
    AL1 = -AL1;
  }
  while (AL1 != 1) {
    MASELEM_MASQREM(AL1, 2, &AL1, &RL);
    if (RL != 0) {
      TL = 1;
    }
    *ML = *ML + 1;
  }
  *NL = *ML + TL;
  return;
}

MASSTOR_LIST SACI_IGCD
# ifdef __STDC__
(MASSTOR_LIST C_66_A, MASSTOR_LIST B)
# else
(C_66_A, B)
MASSTOR_LIST C_66_A, B;
# endif
{
  MASSTOR_LIST A1, A2, A3, A4, AL, BL, C, HL, ML1, ML2, UL1, UL2, VL1, VL2;

  A1 = SACI_IABSF(C_66_A);
  A2 = SACI_IABSF(B);
  if (SACI_ICOMP(A1, A2) < 0) {
    A3 = A1;
    A1 = A2;
    A2 = A3;
  }
  while (A2 != 0) {
    if (A1 < MASSTOR_BETA) {
      C = SACD_DGCD(A1, A2);
      return C;
    }
    ML1 = SACI_ILOG2(A1);
    ML2 = SACI_ILOG2(A2);
    if (ML1 - ML2 >= SACD_ZETA / 2) {
      A4 = SACI_IREM(A1, A2);
      A3 = A2;
    } else {
      HL = ML1 - SACD_ZETA;
      AL = SACI_ITRUNC(A1, HL);
      BL = SACI_ITRUNC(A2, HL);
      SACD_DPCC(AL, BL, &UL1, &UL2, &VL1, &VL2);
      if (VL1 == 0) {
        A4 = SACI_IREM(A1, A2);
        A3 = A2;
      } else {
        A3 = SACI_ILCOMB(A1, A2, UL1, VL1);
        A4 = SACI_ILCOMB(A1, A2, UL2, VL2);
      }
    }
    A1 = A3;
    A2 = A4;
  }
  C = A1;
  return C;
}

void SACI_IGCDCF
# ifdef __STDC__
(MASSTOR_LIST C_65_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AB, MASSTOR_LIST *BB)
# else
(C_65_A, B, C, AB, BB)
MASSTOR_LIST C_65_A, B;
MASSTOR_LIST *C, *AB, *BB;
# endif
{
  *C = SACI_IGCD(C_65_A, B);
  if (*C == 0 || *C == 1) {
    *AB = C_65_A;
    *BB = B;
  } else {
    *AB = SACI_IQ(C_65_A, *C);
    *BB = SACI_IQ(B, *C);
  }
  return;
}

void SACI_IHEGCD
# ifdef __STDC__
(MASSTOR_LIST C_64_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *V)
# else
(C_64_A, B, C, V)
MASSTOR_LIST C_64_A, B;
MASSTOR_LIST *C, *V;
# endif
{
  MASSTOR_LIST A1, A2, A3, A4, AL, BL, HL, J1Y, ML1, ML2, Q, SL, UL1, UL2, V1, V2, V3, V4, VL1, VL2;

  A1 = SACI_IABSF(C_64_A);
  SL = SACI_ISIGNF(B);
  if (SL < 0) {
    A2 = SACI_INEG(B);
  } else {
    A2 = B;
  }
  if (SACI_ICOMP(A1, A2) < 0) {
    A3 = A1;
    A1 = A2;
    A2 = A3;
    V1 = SL;
    V2 = 0;
  } else {
    V1 = 0;
    V2 = SL;
  }
  while (A2 != 0) {
    if (A1 <= MASSTOR_BETA) {
      SACD_DEGCD(A1, A2, C, &UL1, &VL1);
      *V = SACI_IDIPR2(V1, V2, UL1, VL1);
      return;
    }
    ML1 = SACI_ILOG2(A1);
    ML2 = SACI_ILOG2(A2);
    if (ML1 - ML2 >= SACD_ZETA / 2) {
      SACI_IQR(A1, A2, &Q, &A4);
      A3 = A2;
      V3 = V2;
      J1Y = SACI_IPROD(V2, Q);
      V4 = SACI_IDIF(V1, J1Y);
    } else {
      HL = ML1 - SACD_ZETA;
      AL = SACI_ITRUNC(A1, HL);
      BL = SACI_ITRUNC(A2, HL);
      SACD_DPCC(AL, BL, &UL1, &UL2, &VL1, &VL2);
      if (VL1 == 0) {
        SACI_IQR(A1, A2, &Q, &A4);
        A3 = A2;
        V3 = V2;
        J1Y = SACI_IPROD(V2, Q);
        V4 = SACI_IDIF(V1, J1Y);
      } else {
        A3 = SACI_ILCOMB(A1, A2, UL1, VL1);
        A4 = SACI_ILCOMB(A1, A2, UL2, VL2);
        V3 = SACI_IDIPR2(V1, V2, UL1, VL1);
        V4 = SACI_IDIPR2(V1, V2, UL2, VL2);
      }
    }
    A1 = A3;
    A2 = A4;
    V1 = V3;
    V2 = V4;
  }
  *C = A1;
  *V = V1;
  return;
}

MASSTOR_LIST SACI_ILCM
# ifdef __STDC__
(MASSTOR_LIST C_63_A, MASSTOR_LIST B)
# else
(C_63_A, B)
MASSTOR_LIST C_63_A, B;
# endif
{
  MASSTOR_LIST AP, APP, BP, C, CP;

  AP = SACI_IABSF(C_63_A);
  BP = SACI_IABSF(B);
  if (AP == 0) {
    C = BP;
    return C;
  } else {
    if (BP == 0) {
      C = AP;
      return C;
    }
  }
  CP = SACI_IGCD(AP, BP);
  APP = SACI_IQ(AP, CP);
  C = SACI_IPROD(APP, BP);
  return C;
}

MASSTOR_LIST SACI_ILCOMB
# ifdef __STDC__
(MASSTOR_LIST C_62_A, MASSTOR_LIST B, MASSTOR_LIST UL, MASSTOR_LIST VL)
# else
(C_62_A, B, UL, VL)
MASSTOR_LIST C_62_A, B, UL, VL;
# endif
{
  MASSTOR_LIST AB, AL, AL0, AL1, BB, BL, BL0, BL1, C, CL0, CL1;

  if (C_62_A > MASSTOR_BETA) {
    AB = C_62_A;
  } else {
    AB = MASSTOR_LIST1(C_62_A);
  }
  if (B > MASSTOR_BETA) {
    BB = B;
  } else {
    BB = MASSTOR_LIST1(B);
  }
  C = MASSTOR_BETA;
  CL1 = 0;
  do {
    SACI_AADV(AB, &AL, &AB);
    SACI_AADV(BB, &BL, &BB);
    SACD_DPR(AL, UL, &AL1, &AL0);
    SACD_DPR(BL, VL, &BL1, &BL0);
    CL0 = AL0 + BL0;
    CL0 = CL0 + CL1;
    CL1 = AL1 + BL1;
    while (CL0 < 0) {
      CL0 = CL0 + MASSTOR_BETA;
      CL1 = CL1 - 1;
    }
    if (CL0 >= MASSTOR_BETA) {
      CL0 = CL0 - MASSTOR_BETA;
      CL1 = CL1 + 1;
    }
    C = MASSTOR_COMP(CL0, C);
  } while (!(AB == MASSTOR_SIL && BB == MASSTOR_SIL));
  if (CL1 != 0) {
    C = MASSTOR_COMP(CL1, C);
  }
  while (C != MASSTOR_SIL && MASSTOR_FIRST(C) == 0) {
    C = MASSTOR_RED(C);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  } else {
    if (MASSTOR_RED(C) == MASSTOR_SIL) {
      C = MASSTOR_FIRST(C);
    } else {
      C = MASSTOR_INV(C);
    }
  }
  return C;
}

MASSTOR_LIST SACI_ILOG2
# ifdef __STDC__
(MASSTOR_LIST C_61_A)
# else
(C_61_A)
MASSTOR_LIST C_61_A;
# endif
{
  MASSTOR_LIST AP, J1Y, NL;

  if (C_61_A < MASSTOR_BETA) {
    NL = SACD_DLOG2(C_61_A);
    return NL;
  }
  AP = C_61_A;
  NL = 0;
  while (MASSTOR_RED(AP) != MASSTOR_SIL) {
    AP = MASSTOR_RED(AP);
    NL = NL + SACD_ZETA;
  }
  J1Y = MASSTOR_FIRST(AP);
  J1Y = SACD_DLOG2(J1Y);
  NL = NL + J1Y;
  return NL;
}

void SACI_ILWRIT
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, LP;

  LP = L;
  MASBIOS_SWRITE("(", 1L);
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &AL, &LP);
    SACI_IWRITE(AL);
    if (LP != MASSTOR_SIL) {
      MASBIOS_SWRITE(",", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  return;
}

MASSTOR_LIST SACI_IMAX
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST CL, SL;

  SL = SACI_ICOMP(AL, BL);
  if (SL >= 0) {
    CL = AL;
  } else {
    CL = BL;
  }
  return CL;
}

MASSTOR_LIST SACI_IMIN
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST CL, SL;

  SL = SACI_ICOMP(AL, BL);
  if (SL <= 0) {
    CL = AL;
  } else {
    CL = BL;
  }
  return CL;
}

MASSTOR_LIST SACI_IMP2
# ifdef __STDC__
(MASSTOR_LIST C_60_A, MASSTOR_LIST HL)
# else
(C_60_A, HL)
MASSTOR_LIST C_60_A, HL;
# endif
{
  MASSTOR_LIST B, IL, J1Y, QL, RL;

  if (C_60_A == 0 || HL == 0) {
    B = C_60_A;
    return B;
  }
  QL = HL / SACD_ZETA;
  J1Y = QL * SACD_ZETA;
  RL = HL - J1Y;
  B = SACI_IDPR(C_60_A, SACD_TABP2.A[(INTEGER)(RL + 1) - 1]);
  if (QL != 0) {
    if (B < MASSTOR_BETA) {
      B = MASSTOR_LIST1(B);
    }
    {
      LONGINT B_1 = 1, B_2 = QL;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          B = MASSTOR_COMP(0, B);
          if (IL >= B_2) break;
        }
    }
  }
  return B;
}

MASSTOR_LIST SACI_INEG
# ifdef __STDC__
(MASSTOR_LIST C_59_A)
# else
(C_59_A)
MASSTOR_LIST C_59_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL;

  if (C_59_A < MASSTOR_BETA) {
    B = -C_59_A;
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_59_A;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = -AL;
    B = MASSTOR_COMP(BL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

BOOLEAN SACI_IODD
# ifdef __STDC__
(MASSTOR_LIST C_58_A)
# else
(C_58_A)
MASSTOR_LIST C_58_A;
# endif
{
  MASSTOR_LIST J1Y;
  BOOLEAN TL;

  if (C_58_A < MASSTOR_BETA) {
    TL = MASELEM_MASODD(C_58_A);
  } else {
    J1Y = MASSTOR_FIRST(C_58_A);
    TL = MASELEM_MASODD(J1Y);
  }
  return TL;
}

MASSTOR_LIST SACI_IORD2
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST AL1, ALP, J1Y, NL, QL, RL;

  if (AL < MASSTOR_BETA) {
    NL = -1;
    AL1 = AL;
  } else {
    J1Y = -SACD_ZETA;
    NL = J1Y - 1;
    ALP = AL;
    do {
      MASSTOR_ADV(ALP, &AL1, &ALP);
      NL = NL + SACD_ZETA;
    } while (!(AL1 != 0));
  }
  do {
    MASELEM_MASQREM(AL1, 2, &QL, &RL);
    AL1 = QL;
    NL = NL + 1;
  } while (!(RL != 0));
  return NL;
}

void SACI_IPOWER
# ifdef __STDC__
(MASSTOR_LIST C_57_A, MASSTOR_LIST L, MASSTOR_LIST *B, MASSTOR_LIST *NL)
# else
(C_57_A, L, B, NL)
MASSTOR_LIST C_57_A, L;
MASSTOR_LIST *B, *NL;
# endif
{
  MASSTOR_LIST J1Y, LP, N, TL;

  N = SACI_ILOG2(C_57_A);
  J1Y = 7 * N;
  N = J1Y / 11;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, NL, &LP);
    if (*NL > N) {
      *B = 0;
      *NL = 0;
      return;
    }
    SACI_IROOT(C_57_A, *NL, B, &TL);
    if (TL == 0) {
      return;
    }
  }
  *B = 0;
  *NL = 0;
  return;
}

MASSTOR_LIST SACI_IPROD
# ifdef __STDC__
(MASSTOR_LIST C_56_A, MASSTOR_LIST B)
# else
(C_56_A, B)
MASSTOR_LIST C_56_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, C2, CL, CLP, CP, CPP, EL, FL, I, ML, NL, TL;

  if (C_56_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (C_56_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    SACD_DPR(C_56_A, B, &CLP, &CL);
    if (CLP == 0) {
      C = CL;
    } else {
      C = SACLIST_LIST2(CL, CLP);
    }
    return C;
  }
  if (C_56_A < MASSTOR_BETA) {
    C = SACI_IDPR(B, C_56_A);
    return C;
  }
  if (B < MASSTOR_BETA) {
    C = SACI_IDPR(C_56_A, B);
    return C;
  }
  ML = MASSTOR_LENGTH(C_56_A);
  NL = MASSTOR_LENGTH(B);
  if (ML >= NL) {
    AP = C_56_A;
    BP = B;
  } else {
    AP = B;
    BP = C_56_A;
  }
  C2 = SACLIST_LIST2(0, 0);
  C = C2;
  {
    LONGINT B_3 = 1, B_4 = ML + NL - 2;

    if (B_3 <= B_4)
      for (I = B_3;; I += 1) {
        C = MASSTOR_COMP(0, C);
        if (I >= B_4) break;
      }
  }
  CP = C;
  do {
    APP = AP;
    MASSTOR_ADV(BP, &BL, &BP);
    if (BL != 0) {
      CPP = CP;
      CLP = 0;
      do {
        MASSTOR_ADV(APP, &AL, &APP);
        SACD_DPR(AL, BL, &EL, &FL);
        CL = MASSTOR_FIRST(CPP);
        CL = CL + FL;
        CL = CL + CLP;
        CLP = CL / MASSTOR_BETA;
        TL = CLP * MASSTOR_BETA;
        CL = CL - TL;
        MASSTOR_SFIRST(CPP, CL);
        CLP = EL + CLP;
        CPP = MASSTOR_RED(CPP);
      } while (!(APP == MASSTOR_SIL));
      MASSTOR_SFIRST(CPP, CLP);
    }
    CP = MASSTOR_RED(CP);
  } while (!(BP == MASSTOR_SIL));
  if (CLP == 0) {
    MASSTOR_SRED(C2, MASSTOR_SIL);
  }
  return C;
}

MASSTOR_LIST SACI_IPRODK
# ifdef __STDC__
(MASSTOR_LIST C_55_A, MASSTOR_LIST B)
# else
(C_55_A, B)
MASSTOR_LIST C_55_A, B;
# endif
{
  MASSTOR_LIST A0, A1, AP, AS, B0, B1, BP, BS, C, C0, C1, C2, CH, CS, KL, L, ML, NL, TL;

  if (C_55_A < MASSTOR_BETA || B < MASSTOR_BETA) {
    C = SACI_IPROD(C_55_A, B);
    return C;
  }
  ML = MASSTOR_LENGTH(C_55_A);
  NL = MASSTOR_LENGTH(B);
  if (ML >= NL) {
    AP = C_55_A;
    BP = B;
  } else {
    AP = B;
    BP = C_55_A;
    TL = ML;
    ML = NL;
    NL = TL;
  }
  if (NL < 16) {
    C = SACI_IPROD(AP, BP);
    return C;
  }
  if (ML >= 2 * NL) {
    L = MASSTOR_BETA;
    do {
      SACI_ISEG(AP, NL, &AP, &A0);
      C0 = SACI_IPRODK(A0, BP);
      L = MASSTOR_COMP(C0, L);
    } while (!(AP == 0));
    L = MASSTOR_INV(L);
    C = SACI_ISSUM(NL, L);
    return C;
  }
  KL = ML / 2;
  if (ML > KL + KL) {
    KL = KL + 1;
  }
  SACI_ISEG(AP, KL, &A1, &A0);
  SACI_ISEG(BP, KL, &B1, &B0);
  AS = SACI_ISUM(A1, A0);
  BS = SACI_ISUM(B1, B0);
  C2 = SACI_IPRODK(A1, B1);
  C0 = SACI_IPRODK(A0, B0);
  CS = SACI_IPRODK(AS, BS);
  CH = SACI_ISUM(C0, C2);
  C1 = SACI_IDIF(CS, CH);
  L = SACLIST_LIST3(C0, C1, C2);
  C = SACI_ISSUM(KL, L);
  return C;
}

MASSTOR_LIST SACI_IQ
# ifdef __STDC__
(MASSTOR_LIST C_54_A, MASSTOR_LIST B)
# else
(C_54_A, B)
MASSTOR_LIST C_54_A, B;
# endif
{
  MASSTOR_LIST C, R;

  SACI_IQR(C_54_A, B, &C, &R);
  return C;
}

void SACI_IQR
# ifdef __STDC__
(MASSTOR_LIST C_53_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(C_53_A, B, Q, R)
MASSTOR_LIST C_53_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AH, AL, AL0, AL1, AL2, AP, APP, APPP, AS, BL, BL0, BL1, BP, BPP, BS, CL, CL0, CL1, CL2, CLP1, DL, IL, J1Y, ML, NL, QL, RL, SL, T, TL, UL;

  if (B < MASSTOR_BETA) {
    SACI_IDQR(C_53_A, B, Q, R);
    return;
  }
  if (C_53_A < MASSTOR_BETA) {
    *Q = 0;
    *R = C_53_A;
    return;
  }
  ML = MASSTOR_LENGTH(C_53_A);
  NL = MASSTOR_LENGTH(B);
  if (ML < NL) {
    *Q = 0;
    *R = C_53_A;
    return;
  }
  SL = SACI_ISIGNF(C_53_A);
  T = SACLIST_LAST(B);
  BL = MASSTOR_FIRST(T);
  TL = MASELEM_MASSIGN(BL);
  BL = MASELEM_MASABS(BL);
  J1Y = BL + 1;
  DL = MASSTOR_BETA / J1Y;
  J1Y = SL * DL;
  AP = SACI_IDPR(C_53_A, J1Y);
  J1Y = TL * DL;
  BP = SACI_IDPR(B, J1Y);
  APP = AP;
  APPP = MASSTOR_BETA;
  {
    LONGINT B_5 = 1, B_6 = ML - NL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        MASSTOR_ADV(APP, &AL, &APP);
        APPP = MASSTOR_COMP(AL, APPP);
        if (IL >= B_6) break;
      }
  }
  BPP = BP;
  {
    LONGINT B_7 = 1, B_8 = NL - 2;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        BPP = MASSTOR_RED(BPP);
        if (IL >= B_8) break;
      }
  }
  SACLIST_ADV2(BPP, &BL0, &BL1, &BPP);
  *Q = MASSTOR_BETA;
  for (;;) {
    AS = APP;
    {
      LONGINT B_9 = 1, B_10 = NL - 2;

      if (B_9 <= B_10)
        for (IL = B_9;; IL += 1) {
          AS = MASSTOR_RED(AS);
          if (IL >= B_10) break;
        }
    }
    SACLIST_ADV2(AS, &AL0, &AL1, &AS);
    if (AS == MASSTOR_SIL) {
      AL2 = 0;
    } else {
      AL2 = MASSTOR_FIRST(AS);
    }
    if (AL2 == BL1) {
      QL = MASSTOR_BETA - 1;
    } else {
      SACD_DQR(AL2, AL1, BL1, &QL, &RL);
    }
    do {
      SACD_DPR(BL0, QL, &CL1, &CL0);
      SACD_DPR(BL1, QL, &CL2, &CLP1);
      CL1 = CL1 + CLP1;
      if (CL1 >= MASSTOR_BETA) {
        CL1 = CL1 - MASSTOR_BETA;
        CL2 = CL2 + 1;
      }
      UL = AL2 - CL2;
      if (UL == 0) {
        UL = AL1 - CL1;
      }
      if (UL == 0) {
        UL = AL0 - CL0;
      }
      QL = QL - 1;
    } while (!(UL >= 0));
    QL = QL + 1;
    for (;;) {
      AS = APP;
      BS = BP;
      AH = MASSTOR_BETA;
      CL = 0;
      {
        LONGINT B_11 = 1, B_12 = NL;

        if (B_11 <= B_12)
          for (IL = B_11;; IL += 1) {
            MASSTOR_ADV(BS, &BL, &BS);
            SACD_DPR(BL, QL, &CL2, &CL1);
            MASSTOR_ADV(AS, &AL, &AS);
            AL = AL - CL;
            AL = AL - CL1;
            CL = CL2;
            while (AL < 0) {
              AL = AL + MASSTOR_BETA;
              CL = CL + 1;
            }
            AH = MASSTOR_COMP(AL, AH);
            if (IL >= B_12) break;
          }
      }
      if (AS == MASSTOR_SIL) {
        AL = 0;
      } else {
        AL = MASSTOR_FIRST(AS);
      }
      AL = AL - CL;
      if (AL < 0) {
        QL = QL - 1;
      } else {
        APP = MASSTOR_INV(AH);
        goto EXIT_2;
      }
    } EXIT_2:;
    if (*Q != MASSTOR_SIL || QL != 0) {
      *Q = MASSTOR_COMP(QL, *Q);
    }
    if (APPP != MASSTOR_SIL) {
      MASSTOR_ADV(APPP, &AL, &APPP);
      APP = MASSTOR_COMP(AL, APP);
    } else {
      goto EXIT_1;
    }
  } EXIT_1:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    if (MASSTOR_RED(*Q) == MASSTOR_SIL) {
      *Q = MASSTOR_FIRST(*Q);
    }
  }
  T = 0;
  AS = APP;
  do {
    AL = MASSTOR_FIRST(AS);
    if (AL != 0) {
      T = AS;
    }
    AS = MASSTOR_RED(AS);
  } while (!(AS == MASSTOR_SIL));
  if (T == 0) {
    *R = 0;
  } else {
    MASSTOR_SRED(T, MASSTOR_SIL);
    *R = APP;
    if (MASSTOR_RED(*R) == MASSTOR_SIL) {
      *R = MASSTOR_FIRST(*R);
    }
  }
  if (SL * TL == -1) {
    *Q = SACI_INEG(*Q);
  }
  SACI_IDQR(*R, SL * DL, R, &T);
  return;
}

MASSTOR_LIST SACI_IRAND
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST C_52_A, AL, IDUM, IL, J1Y, QL, RL, SL;

  MASELEM_MASQREM(NL, SACD_ZETA, &QL, &RL);
  if (RL == 0) {
    QL = QL - 1;
    RL = SACD_ZETA;
  }
  AL = SACD_DRAN();
  SL = MASELEM_MASSIGN(AL);
  J1Y = SACD_ZETA - RL;
  J1Y = J1Y + 1;
  AL = AL / SACD_TABP2.A[(INTEGER)J1Y - 1];
  if (QL == 0) {
    C_52_A = AL;
    return C_52_A;
  }
  C_52_A = MASSTOR_BETA;
  if (AL != 0) {
    C_52_A = MASSTOR_COMP(AL, C_52_A);
  }
  {
    LONGINT B_13 = 1, B_14 = QL;

    if (B_13 <= B_14)
      for (IL = B_13;; IL += 1) {
        J1Y = SACD_DRAN();
        AL = MASELEM_MASABS(J1Y);
        if (SL < 0) {
          AL = -AL;
        }
        if (AL != 0 || C_52_A != MASSTOR_SIL) {
          C_52_A = MASSTOR_COMP(AL, C_52_A);
        }
        if (IL >= B_14) break;
      }
  }
  if (C_52_A == MASSTOR_SIL) {
    C_52_A = 0;
  } else {
    if (MASSTOR_RED(C_52_A) == MASSTOR_SIL) {
      C_52_A = MASSTOR_FIRST(C_52_A);
    }
  }
  return C_52_A;
}

MASSTOR_LIST SACI_IREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_51_A, B, BL, BLP, C, IDUM, IL, J1Y, SL;

  SL = 1;
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('-')) {
    SL = -1;
  }
  if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-')) {
    C = MASBIOS_CREAD();
  }
  if (!MASBIOS_DIGIT(C)) {
    MASBIOS_SWRITE("ERROR FOUND BY IREAD.", 21L);
    MASBIOS_DIBUFF();
    C_51_A = 0;
    return C_51_A;
  }
  while (C == 0) {
    C = MASBIOS_CREAD();
  }
  C_51_A = 0;
  if (!MASBIOS_DIGIT(C)) {
    MASBIOS_BKSP();
    return C_51_A;
  }
  B = MASSTOR_SIL;
  BL = 0;
  IL = 0;
  do {
    BL = 10 * BL + C;
    IL = IL + 1;
    if (IL == SACD_ETA) {
      B = MASSTOR_COMP(BL, B);
      BL = 0;
      IL = 0;
    }
    C = MASBIOS_CREAD();
  } while (!!MASBIOS_DIGIT(C));
  B = MASSTOR_INV(B);
  while (B != MASSTOR_SIL) {
    C_51_A = SACI_IDPR(C_51_A, SACD_THETA);
    MASSTOR_ADV(B, &BLP, &B);
    C_51_A = SACI_ISUM(C_51_A, BLP);
  }
  if (C_51_A != 0) {
    C_51_A = SACI_IDPR(C_51_A, MASELEM_MASEXP(10, IL));
  }
  C_51_A = SACI_ISUM(C_51_A, BL);
  if (SL < 0) {
    C_51_A = SACI_INEG(C_51_A);
  }
  MASBIOS_BKSP();
  return C_51_A;
  MASBIOS_SWRITE("ERROR FOUND BY IREAD.", 21L);
  MASBIOS_DIBUFF();
}

MASSTOR_LIST SACI_IREM
# ifdef __STDC__
(MASSTOR_LIST C_50_A, MASSTOR_LIST B)
# else
(C_50_A, B)
MASSTOR_LIST C_50_A, B;
# endif
{
  MASSTOR_LIST C, Q;

  SACI_IQR(C_50_A, B, &Q, &C);
  return C;
}

void SACI_IROOT
# ifdef __STDC__
(MASSTOR_LIST C_49_A, MASSTOR_LIST NL, MASSTOR_LIST *B, MASSTOR_LIST *TL)
# else
(C_49_A, NL, B, TL)
MASSTOR_LIST C_49_A, NL;
MASSTOR_LIST *B, *TL;
# endif
{
  MASSTOR_LIST AP, BP, C, D, E, F, HL, J1Y, J2Y, KL, NLP, R, RL, SL, UL;

  KL = SACI_ILOG2(C_49_A);
  NLP = NL - 1;
  HL = KL / NL;
  J1Y = HL * NL;
  RL = KL - J1Y;
  J1Y = 4 * RL;
  UL = J1Y / NL;
  if (HL >= 2) {
    J1Y = UL + 5;
    J2Y = HL - 2;
    *B = SACI_IMP2(J1Y, J2Y);
  } else {
    *B = 4;
  }
  for (;;) {
    C = SACI_IEXP(*B, NLP);
    SACI_IQR(C_49_A, C, &D, &R);
    SL = SACI_ICOMP(*B, D);
    if (SL <= 0) {
      goto EXIT_3;
    } else {
      E = SACI_IDPR(*B, NLP);
      F = SACI_ISUM(E, D);
      *B = SACI_IDQ(F, NL);
    }
  } EXIT_3:;
  if (SL == 0) {
    *TL = SACI_ISIGNF(R);
  } else {
    BP = SACI_ISUM(*B, 1);
    AP = SACI_IEXP(BP, NL);
    *TL = SACI_ICOMP(C_49_A, AP);
    if (*TL >= 0) {
      *B = BP;
    } else {
      *TL = 1;
    }
  }
  return;
}

void SACI_ISEG
# ifdef __STDC__
(MASSTOR_LIST C_48_A, MASSTOR_LIST NL, MASSTOR_LIST *A1, MASSTOR_LIST *A0)
# else
(C_48_A, NL, A1, A0)
MASSTOR_LIST C_48_A, NL;
MASSTOR_LIST *A1, *A0;
# endif
{
  MASSTOR_LIST AL, IL;

  if (C_48_A < MASSTOR_BETA) {
    *A1 = 0;
    *A0 = C_48_A;
    return;
  }
  *A1 = C_48_A;
  *A0 = MASSTOR_BETA;
  IL = 0;
  do {
    IL = IL + 1;
    MASSTOR_ADV(*A1, &AL, A1);
    *A0 = MASSTOR_COMP(AL, *A0);
  } while (!(IL == NL || *A1 == MASSTOR_SIL));
  if (*A1 == MASSTOR_SIL) {
    *A1 = 0;
  } else {
    if (MASSTOR_RED(*A1) == MASSTOR_SIL) {
      *A1 = MASSTOR_FIRST(*A1);
    }
  }
  while (*A0 != MASSTOR_SIL && MASSTOR_FIRST(*A0) == 0) {
    *A0 = MASSTOR_RED(*A0);
  }
  *A0 = MASSTOR_INV(*A0);
  if (*A0 == MASSTOR_SIL) {
    *A0 = 0;
  } else {
    if (MASSTOR_RED(*A0) == MASSTOR_SIL) {
      *A0 = MASSTOR_FIRST(*A0);
    }
  }
  return;
}

MASSTOR_LIST SACI_ISIGNF
# ifdef __STDC__
(MASSTOR_LIST C_47_A)
# else
(C_47_A)
MASSTOR_LIST C_47_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  if (C_47_A < MASSTOR_BETA) {
    SL = MASELEM_MASSIGN(C_47_A);
    return SL;
  }
  AP = C_47_A;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
  } while (!(AL != 0));
  SL = MASELEM_MASSIGN(AL);
  return SL;
}

void SACI_ISQRT
# ifdef __STDC__
(MASSTOR_LIST C_46_A, MASSTOR_LIST *B, MASSTOR_LIST *TL)
# else
(C_46_A, B, TL)
MASSTOR_LIST C_46_A;
MASSTOR_LIST *B, *TL;
# endif
{
  MASSTOR_LIST AL, BL, C, D, HL, J1Y, KL, R, SL;

  if (C_46_A < MASSTOR_BETA) {
    SACD_DSQRTF(C_46_A, B, TL);
    return;
  }
  KL = SACI_ILOG2(C_46_A);
  HL = KL - SACD_ZETA;
  if (MASELEM_MASODD(HL)) {
    HL = HL + 1;
  }
  AL = SACI_IDP2(C_46_A, HL);
  SACD_DSQRTF(AL, &BL, TL);
  BL = BL + 1;
  J1Y = HL / 2;
  *B = SACI_IMP2(BL, J1Y);
  for (;;) {
    SACI_IQR(C_46_A, *B, &C, &R);
    SL = SACI_ICOMP(*B, C);
    if (SL <= 0) {
      goto EXIT_4;
    }
    D = SACI_ISUM(*B, C);
    *B = SACI_IDQ(D, 2);
  } EXIT_4:;
  J1Y = SACI_IPROD(*B, *B);
  *TL = SACI_ICOMP(C_46_A, J1Y);
  return;
}

MASSTOR_LIST SACI_ISSUM
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST L)
# else
(NL, L)
MASSTOR_LIST NL, L;
# endif
{
  MASSTOR_LIST AL, AL0, AL1, C, C0, C1, CL, CLP, IL, J1Y, LP;

  C = MASSTOR_BETA;
  CL = 0;
  MASSTOR_ADV(L, &C0, &LP);
  if (C0 < MASSTOR_BETA) {
    C0 = MASSTOR_LIST1(C0);
  }
  {
    LONGINT B_15 = 1, B_16 = NL;

    if (B_15 <= B_16)
      for (IL = B_15;; IL += 1) {
        SACI_AADV(C0, &AL0, &C0);
        C = MASSTOR_COMP(AL0, C);
        if (IL >= B_16) break;
      }
  }
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &C1, &LP);
    if (C1 < MASSTOR_BETA) {
      C1 = MASSTOR_LIST1(C1);
    }
    {
      LONGINT B_17 = 1, B_18 = NL;

      if (B_17 <= B_18)
        for (IL = B_17;; IL += 1) {
          SACI_AADV(C0, &AL0, &C0);
          SACI_AADV(C1, &AL1, &C1);
          AL = AL0 + AL1;
          AL = AL + CL;
          CL = AL / MASSTOR_BETA;
          CLP = CL * MASSTOR_BETA;
          AL = AL - CLP;
          C = MASSTOR_COMP(AL, C);
          if (IL >= B_18) break;
        }
    }
    if (C0 != MASSTOR_SIL) {
      J1Y = MASSTOR_FIRST(C0);
      CL = CL + J1Y;
    }
    C0 = C1;
  }
  while (C0 != MASSTOR_SIL || CL != 0) {
    SACI_AADV(C0, &AL0, &C0);
    AL = AL0 + CL;
    CL = 0;
    if (AL >= MASSTOR_BETA) {
      AL = AL - MASSTOR_BETA;
      CL = 1;
    } else {
      if (AL <= -MASSTOR_BETA) {
        AL = AL + MASSTOR_BETA;
        CL = -1;
      }
    }
    C = MASSTOR_COMP(AL, C);
  }
  while (C != MASSTOR_SIL && MASSTOR_FIRST(C) == 0) {
    C = MASSTOR_RED(C);
  }
  C = MASSTOR_INV(C);
  if (C == MASSTOR_SIL) {
    C = 0;
  } else {
    if (MASSTOR_RED(C) == MASSTOR_SIL) {
      C = MASSTOR_FIRST(C);
    }
  }
  return C;
}

MASSTOR_LIST SACI_ISUM
# ifdef __STDC__
(MASSTOR_LIST C_45_A, MASSTOR_LIST B)
# else
(C_45_A, B)
MASSTOR_LIST C_45_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CLP, CP, CPP, CS, J1Y, J2Y, SL, TL, UL;

  if (C_45_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_45_A;
    return C;
  }
  if (C_45_A < MASSTOR_BETA && B < MASSTOR_BETA) {
    CL = C_45_A + B;
    if (CL >= MASSTOR_BETA) {
      J1Y = CL - MASSTOR_BETA;
      C = SACLIST_LIST2(J1Y, 1);
    } else {
      if (CL <= -MASSTOR_BETA) {
        J1Y = CL + MASSTOR_BETA;
        J2Y = -1;
        C = SACLIST_LIST2(J1Y, J2Y);
      } else {
        C = CL;
      }
    }
    return C;
  }
  SL = SACI_ISIGNF(C_45_A);
  TL = SACI_ISIGNF(B);
  C = MASSTOR_BETA;
  if (C_45_A < MASSTOR_BETA) {
    AP = MASSTOR_LIST1(C_45_A);
  } else {
    AP = C_45_A;
  }
  if (B < MASSTOR_BETA) {
    BP = MASSTOR_LIST1(B);
  } else {
    BP = B;
  }
  if (SL == TL) {
    CLP = 0;
    do {
      if (AP != MASSTOR_SIL) {
        MASSTOR_ADV(AP, &AL, &AP);
      } else {
        AL = 0;
      }
      if (BP != MASSTOR_SIL) {
        MASSTOR_ADV(BP, &BL, &BP);
      } else {
        BL = 0;
      }
      CL = AL + BL;
      CL = CL + CLP;
      CLP = 0;
      if (CL >= MASSTOR_BETA) {
        CL = CL - MASSTOR_BETA;
        CLP = 1;
      } else {
        if (CL <= -MASSTOR_BETA) {
          CL = CL + MASSTOR_BETA;
          CLP = -1;
        }
      }
      C = MASSTOR_COMP(CL, C);
    } while (!(CLP == 0 && (AP == MASSTOR_SIL || BP == MASSTOR_SIL)));
    if (AP == MASSTOR_SIL) {
      AP = BP;
    }
    CP = MASSTOR_INV(C);
    MASSTOR_SRED(C, AP);
    C = CP;
    return C;
  }
  UL = 0;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    CL = AL + BL;
    if (CL != 0) {
      UL = CL;
    }
    C = MASSTOR_COMP(CL, C);
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    AP = BP;
    SL = TL;
  }
  if (UL == 0 && AP == MASSTOR_SIL) {
    C = 0;
    return C;
  }
  if (UL == 0 || AP != MASSTOR_SIL && SL != MASELEM_MASSIGN(UL)) {
    do {
      MASSTOR_ADV(AP, &AL, &AP);
      C = MASSTOR_COMP(AL, C);
      UL = AL;
    } while (!(AL != 0));
  }
  CP = MASSTOR_INV(C);
  CPP = CP;
  CLP = 0;
  do {
    CL = MASSTOR_FIRST(CPP);
    CL = CL + CLP;
    CLP = 0;
    if (UL > 0 && CL < 0) {
      CL = CL + MASSTOR_BETA;
      CLP = -1;
    } else {
      if (UL < 0 && CL > 0) {
        CL = CL - MASSTOR_BETA;
        CLP = 1;
      }
    }
    if (CL != 0) {
      CS = CPP;
    }
    MASSTOR_SFIRST(CPP, CL);
    CPP = MASSTOR_RED(CPP);
  } while (!(CPP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    MASSTOR_SRED(CS, MASSTOR_SIL);
  } else {
    MASSTOR_SRED(C, AP);
  }
  C = CP;
  if (MASSTOR_RED(C) == MASSTOR_SIL) {
    C = MASSTOR_FIRST(C);
  }
  return C;
}

MASSTOR_LIST SACI_ITRUNC
# ifdef __STDC__
(MASSTOR_LIST C_44_A, MASSTOR_LIST NL)
# else
(C_44_A, NL)
MASSTOR_LIST C_44_A, NL;
# endif
{
  MASSTOR_LIST AL, B, IL, J1Y, ML, QL, RL;

  B = C_44_A;
  if (C_44_A == 0 || NL == 0) {
    return B;
  }
  ML = MASELEM_MASABS(NL);
  QL = ML / SACD_ZETA;
  J1Y = QL * SACD_ZETA;
  RL = ML - J1Y;
  AL = SACD_TABP2.A[(INTEGER)(RL + 1) - 1];
  if (NL > 0) {
    IL = 0;
    if (B < MASSTOR_BETA) {
      B = MASSTOR_LIST1(B);
    }
    while (B != MASSTOR_SIL && IL != QL) {
      B = MASSTOR_RED(B);
      IL = IL + 1;
    }
    if (B == MASSTOR_SIL) {
      B = 0;
      return B;
    }
    if (MASSTOR_RED(B) == MASSTOR_SIL) {
      B = MASSTOR_FIRST(B);
    }
    if (RL != 0) {
      SACI_IDQR(B, AL, &B, &RL);
    }
    return B;
  }
  if (RL != 0) {
    B = SACI_IDPR(B, AL);
  }
  if (QL == 0) {
    return B;
  }
  if (B < MASSTOR_BETA) {
    B = MASSTOR_LIST1(B);
  }
  {
    LONGINT B_19 = 1, B_20 = QL;

    if (B_19 <= B_20)
      for (IL = B_19;; IL += 1) {
        B = MASSTOR_COMP(0, B);
        if (IL >= B_20) break;
      }
  }
  return B;
}

void SACI_IWRITE
# ifdef __STDC__
(MASSTOR_LIST C_43_A)
# else
(C_43_A)
MASSTOR_LIST C_43_A;
# endif
{
  struct S_1 B;
  INTEGER IL;
  MASSTOR_LIST HL, J1Y, H, AP, QL;

  if (C_43_A < MASSTOR_BETA) {
    SACLIST_AWRITE(C_43_A);
    return;
  }
  AP = C_43_A;
  H = MASSTOR_BETA;
  do {
    SACI_IDQR(AP, SACD_THETA, &AP, &HL);
    H = MASSTOR_COMP(HL, H);
  } while (!(AP == 0));
  MASSTOR_ADV(H, &HL, &H);
  SACLIST_AWRITE(HL);
  while (H != MASSTOR_SIL) {
    MASSTOR_ADV(H, &HL, &H);
    HL = MASELEM_MASABS(HL);
    {
      LONGINT B_21 = 1, B_22 = (INTEGER)SACD_ETA;

      if (B_21 <= B_22)
        for (IL = B_21;; IL += 1) {
          QL = HL / 10;
          J1Y = 10 * QL;
          B.A[IL - 1] = HL - J1Y;
          HL = QL;
          if (IL >= B_22) break;
        }
    }
    for (IL = (INTEGER)SACD_ETA; IL >= 1; IL += -1) {
      MASBIOS_CWRITE(B.A[IL - 1]);
    }
  }
  return;
}

void BEGIN_SACI()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACD();

  }
}
