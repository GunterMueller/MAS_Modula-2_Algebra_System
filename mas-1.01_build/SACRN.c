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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

CHAR SACRN_rcsid [] = "$Id: SACRN.md,v 1.2 1992/02/12 13:19:18 pesch Exp $";
CHAR SACRN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACRN.mi,v 1.3 1992/10/15 16:28:21 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACRN_RIRNP
# ifdef __STDC__
(MASSTOR_LIST I, MASSTOR_LIST CL)
# else
(I, CL)
MASSTOR_LIST I, CL;
# endif
{
  MASSTOR_LIST AL, ALP, BL, BLP, J;

  SACLIST_FIRST2(I, &AL, &BL);
  ALP = SACRN_RNPROD(AL, CL);
  BLP = SACRN_RNPROD(BL, CL);
  if (SACRN_RNSIGN(CL) >= 0) {
    J = SACLIST_LIST2(ALP, BLP);
  } else {
    J = SACLIST_LIST2(BLP, ALP);
  }
  return J;
}

MASSTOR_LIST SACRN_RNABS
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST S;

  if (SACRN_RNSIGN(R) >= 0) {
    S = R;
  } else {
    S = SACRN_RNNEG(R);
  }
  return S;
}

MASSTOR_LIST SACRN_RNCEIL
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST AL, BL, RL1, RL2, SL;

  if (RL == 0) {
    AL = 0;
    return AL;
  }
  SACLIST_FIRST2(RL, &RL1, &RL2);
  SACI_IQR(RL1, RL2, &AL, &BL);
  SL = SACI_ISIGNF(BL);
  if (SL > 0) {
    AL = SACI_ISUM(AL, SL);
  }
  return AL;
}

MASSTOR_LIST SACRN_RNCOMP
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST J1Y, J2Y, R1, R2, RL, S1, S2, SL, TL;

  if (R == 0) {
    J1Y = SACRN_RNSIGN(S);
    TL = -J1Y;
    return TL;
  }
  if (S == 0) {
    TL = SACRN_RNSIGN(R);
    return TL;
  }
  SACLIST_FIRST2(R, &R1, &R2);
  SACLIST_FIRST2(S, &S1, &S2);
  RL = SACI_ISIGNF(R1);
  SL = SACI_ISIGNF(S1);
  J1Y = RL - SL;
  TL = J1Y / 2;
  if (TL != 0) {
    return TL;
  }
  J1Y = SACI_IPROD(R1, S2);
  J2Y = SACI_IPROD(R2, S1);
  TL = SACI_ICOMP(J1Y, J2Y);
  return TL;
}

MASSTOR_LIST SACRN_RNDEN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST BL;

  if (R == 0) {
    BL = 1;
  } else {
    BL = SACLIST_SECOND(R);
  }
  return BL;
}

MASSTOR_LIST SACRN_RNDIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST J1Y, T;

  J1Y = SACRN_RNNEG(S);
  T = SACRN_RNSUM(R, J1Y);
  return T;
}

void SACRN_RNDWR
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST NL)
# else
(R, NL)
MASSTOR_LIST R, NL;
# endif
{
  MASSTOR_LIST C_48_A, B, D, DL, F, IL, M, SL, TL;

  if (R == 0) {
    C_48_A = 0;
    B = 1;
  } else {
    SACLIST_FIRST2(R, &C_48_A, &B);
  }
  SL = SACI_ISIGNF(C_48_A);
  if (SL < 0) {
    C_48_A = SACI_INEG(C_48_A);
  }
  M = SACI_IEXP(10, NL);
  C_48_A = SACI_IPROD(C_48_A, M);
  SACI_IQR(C_48_A, B, &D, &F);
  F = SACI_IDPR(F, 2);
  if (F == 0) {
    TL = 0;
  } else {
    TL = SACI_ICOMP(B, F);
    if (TL == 0) {
      TL = 1;
    } else {
      if (TL < 0) {
        D = SACI_ISUM(D, 1);
      }
    }
  }
  if (SL < 0) {
    MASBIOS_SWRITE("-", 1L);
  }
  SACI_IQR(D, M, &D, &F);
  SACI_IWRITE(D);
  MASBIOS_SWRITE(".", 1L);
  {
    LONGINT B_1 = 1, B_2 = NL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        F = SACI_IDPR(F, 10);
        SACI_IQR(F, M, &DL, &F);
        MASBIOS_CWRITE(DL);
        if (IL >= B_2) break;
      }
  }
  if (TL > 0) {
    MASBIOS_SWRITE("+", 1L);
  } else {
    if (TL < 0) {
      MASBIOS_SWRITE("-", 1L);
    }
  }
  return;
}

void SACRN_RNFCL2
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST *ML, MASSTOR_LIST *NL)
# else
(AL, ML, NL)
MASSTOR_LIST AL;
MASSTOR_LIST *ML, *NL;
# endif
{
  MASSTOR_LIST AL1, AL2, ALP1, CL, DL, J1Y, ML1, ML2, NL1, NL2, SL;

  SACLIST_FIRST2(AL, &AL1, &AL2);
  SACI_IFCL2(AL1, &ML1, &NL1);
  SACI_IFCL2(AL2, &ML2, &NL2);
  *ML = ML1 - NL2;
  *NL = NL1 - ML2;
  if (*NL <= *ML + 1) {
    return;
  }
  ALP1 = SACI_IABSF(AL1);
  if (*ML + 1 >= 0) {
    CL = ALP1;
    J1Y = *ML + 1;
    DL = SACI_IMP2(AL2, J1Y);
  } else {
    J1Y = -*ML;
    J1Y = J1Y - 1;
    CL = SACI_IMP2(ALP1, J1Y);
    DL = AL2;
  }
  SL = SACI_ICOMP(CL, DL);
  if (SL < 0) {
    *NL = *NL - 1;
  } else {
    *ML = *ML + 1;
  }
  return;
}

MASSTOR_LIST SACRN_RNFLOR
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST AL, BL, RL1, RL2, SL;

  if (RL == 0) {
    AL = 0;
    return AL;
  }
  SACLIST_FIRST2(RL, &RL1, &RL2);
  SACI_IQR(RL1, RL2, &AL, &BL);
  SL = SACI_ISIGNF(BL);
  if (SL < 0) {
    AL = SACI_ISUM(AL, SL);
  }
  return AL;
}

MASSTOR_LIST SACRN_RNINT
# ifdef __STDC__
(MASSTOR_LIST C_47_A)
# else
(C_47_A)
MASSTOR_LIST C_47_A;
# endif
{
  MASSTOR_LIST R;

  if (C_47_A == 0) {
    R = 0;
  } else {
    R = SACLIST_LIST2(C_47_A, 1);
  }
  return R;
}

MASSTOR_LIST SACRN_RNINV
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, R2, S, S1, S2;

  SACLIST_FIRST2(R, &R1, &R2);
  if (SACI_ISIGNF(R1) > 0) {
    S1 = R2;
    S2 = R1;
  } else {
    S1 = SACI_INEG(R2);
    S2 = SACI_INEG(R1);
  }
  S = SACLIST_LIST2(S1, S2);
  return S;
}

MASSTOR_LIST SACRN_RNNEG
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, RP, RP1, S;

  if (R == 0) {
    S = 0;
  } else {
    MASSTOR_ADV(R, &R1, &RP);
    RP1 = SACI_INEG(R1);
    S = MASSTOR_COMP(RP1, RP);
  }
  return S;
}

MASSTOR_LIST SACRN_RNNUM
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST AL;

  if (R == 0) {
    AL = 0;
  } else {
    AL = MASSTOR_FIRST(R);
  }
  return AL;
}

MASSTOR_LIST SACRN_RNPROD
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST D1, D2, R1, R2, RB1, RB2, S1, S2, SB1, SB2, T, T1, T2;

  if (R == 0 || S == 0) {
    T = 0;
    return T;
  }
  SACLIST_FIRST2(R, &R1, &R2);
  SACLIST_FIRST2(S, &S1, &S2);
  if (R2 == 1 && S2 == 1) {
    T1 = SACI_IPROD(R1, S1);
    T = SACLIST_LIST2(T1, 1);
    return T;
  }
  if (R2 == 1) {
    SACI_IGCDCF(R1, S2, &D1, &RB1, &SB2);
    T1 = SACI_IPROD(RB1, S1);
    T = SACLIST_LIST2(T1, SB2);
    return T;
  }
  if (S2 == 1) {
    SACI_IGCDCF(S1, R2, &D2, &SB1, &RB2);
    T1 = SACI_IPROD(SB1, R1);
    T = SACLIST_LIST2(T1, RB2);
    return T;
  }
  SACI_IGCDCF(R1, S2, &D1, &RB1, &SB2);
  SACI_IGCDCF(S1, R2, &D2, &SB1, &RB2);
  T1 = SACI_IPROD(RB1, SB1);
  T2 = SACI_IPROD(RB2, SB2);
  T = SACLIST_LIST2(T1, T2);
  return T;
}

MASSTOR_LIST SACRN_RNP2
# ifdef __STDC__
(MASSTOR_LIST KL)
# else
(KL)
MASSTOR_LIST KL;
# endif
{
  MASSTOR_LIST AL, HL, RL;

  HL = MASELEM_MASABS(KL);
  AL = SACI_IMP2(1, HL);
  if (KL >= 0) {
    RL = SACLIST_LIST2(AL, 1);
  } else {
    RL = SACLIST_LIST2(1, AL);
  }
  return RL;
}

MASSTOR_LIST SACRN_RNQ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST J1Y, T;

  if (R == 0) {
    T = 0;
  } else {
    J1Y = SACRN_RNINV(S);
    T = SACRN_RNPROD(R, J1Y);
  }
  return T;
}

MASSTOR_LIST SACRN_RNRAND
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST C_46_A, B, R;

  C_46_A = SACI_IRAND(NL);
  B = SACI_IRAND(NL);
  B = SACI_IABSF(B);
  B = SACI_ISUM(B, 1);
  R = SACRN_RNRED(C_46_A, B);
  return R;
}

MASSTOR_LIST SACRN_RNREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, IDUM, R, R1, R2;

  R1 = SACI_IREAD();
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('/')) {
    R2 = SACI_IREAD();
  } else {
    R2 = 1;
    MASBIOS_BKSP();
  }
  if (R1 == 0) {
    R = 0;
  } else {
    R = SACLIST_LIST2(R1, R2);
  }
  return R;
}

MASSTOR_LIST SACRN_RNRED
# ifdef __STDC__
(MASSTOR_LIST C_45_A, MASSTOR_LIST B)
# else
(C_45_A, B)
MASSTOR_LIST C_45_A, B;
# endif
{
  MASSTOR_LIST AB, BB, C, R;

  if (C_45_A == 0) {
    R = 0;
    return R;
  }
  C = SACI_IGCD(C_45_A, B);
  AB = SACI_IQ(C_45_A, C);
  BB = SACI_IQ(B, C);
  if (SACI_ISIGNF(B) < 0) {
    AB = SACI_INEG(AB);
    BB = SACI_INEG(BB);
  }
  R = SACLIST_LIST2(AB, BB);
  return R;
}

MASSTOR_LIST SACRN_RNSIGN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST J1Y, SL;

  if (R == 0) {
    SL = 0;
  } else {
    J1Y = MASSTOR_FIRST(R);
    SL = SACI_ISIGNF(J1Y);
  }
  return SL;
}

MASSTOR_LIST SACRN_RNSUM
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST D, E, J1Y, J2Y, R1, R2, RB2, S1, S2, SB2, T, T1, T2;

  if (R == 0) {
    T = S;
    return T;
  }
  if (S == 0) {
    T = R;
    return T;
  }
  SACLIST_FIRST2(R, &R1, &R2);
  SACLIST_FIRST2(S, &S1, &S2);
  if (R2 == 1 && S2 == 1) {
    T1 = SACI_ISUM(R1, S1);
    if (T1 == 0) {
      T = 0;
    } else {
      T = SACLIST_LIST2(T1, 1);
    }
    return T;
  }
  if (R2 == 1) {
    T1 = SACI_IPROD(R1, S2);
    T1 = SACI_ISUM(T1, S1);
    T = SACLIST_LIST2(T1, S2);
    return T;
  }
  if (S2 == 1) {
    T1 = SACI_IPROD(R2, S1);
    T1 = SACI_ISUM(T1, R1);
    T = SACLIST_LIST2(T1, R2);
    return T;
  }
  SACI_IGCDCF(R2, S2, &D, &RB2, &SB2);
  J1Y = SACI_IPROD(R1, SB2);
  J2Y = SACI_IPROD(RB2, S1);
  T1 = SACI_ISUM(J1Y, J2Y);
  if (T1 == 0) {
    T = 0;
    return T;
  }
  if (D != 1) {
    E = SACI_IGCD(T1, D);
    if (E != 1) {
      T1 = SACI_IQ(T1, E);
      R2 = SACI_IQ(R2, E);
    }
  }
  T2 = SACI_IPROD(R2, SB2);
  T = SACLIST_LIST2(T1, T2);
  return T;
}

void SACRN_RNWRIT
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST R1, R2;

  if (R == 0) {
    SACLIST_AWRITE(R);
  } else {
    SACLIST_FIRST2(R, &R1, &R2);
    SACI_IWRITE(R1);
    if (R2 != 1) {
      MASBIOS_SWRITE("/", 1L);
      SACI_IWRITE(R2);
    }
  }
  return;
}

void BEGIN_SACRN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACI();

  }
}
