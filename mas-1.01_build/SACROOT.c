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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACROOT
#include "SACROOT.h"
#endif

CHAR SACROOT_rcsid [] = "$Id: SACROOT.md,v 1.3 1993/05/11 10:51:44 kredel Exp $";
CHAR SACROOT_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACROOT.mi,v 1.4 1993/05/11 10:51:46 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACROOT_IIC
# ifdef __STDC__
(MASSTOR_LIST C_170_A, MASSTOR_LIST AP, MASSTOR_LIST I, MASSTOR_LIST L)
# else
(C_170_A, AP, I, L)
MASSTOR_LIST C_170_A, AP, I, L;
# endif
{
  MASSTOR_LIST AL1, AL2, BL1, BL2, CL, I1, I2, J1Y, LP, LS, SL, SL1;

  LP = SACLIST_CINV(L);
  LS = MASSTOR_BETA;
  for (;;) {
    for (;;) {
      for (;;) {
        if (LP == MASSTOR_SIL) {
          return LS;
        }
        MASSTOR_ADV(LP, &I2, &LP);
        SACLIST_FIRST2(I2, &AL2, &BL2);
        SL = SACRN_RNCOMP(AL2, BL2);
        if (SL == 0) {
          goto EXIT_3;
        }
        LS = MASSTOR_COMP(I2, LS);
      } EXIT_3:;
      if (LP == MASSTOR_SIL) {
        AL2 = MASSTOR_FIRST(I);
        J1Y = SACLIST_LIST2(AL2, BL2);
        LS = MASSTOR_COMP(J1Y, LS);
        return LS;
      }
      I1 = MASSTOR_FIRST(LP);
      SACLIST_FIRST2(I1, &AL1, &BL1);
      SL = SACRN_RNCOMP(BL1, AL2);
      if (SL == 0) {
        goto EXIT_2;
      }
      AL2 = BL1;
      J1Y = SACLIST_LIST2(AL2, BL2);
      LS = MASSTOR_COMP(J1Y, LS);
    } EXIT_2:;
    LP = MASSTOR_RED(LP);
    SL1 = SACIPOL_IUPBES(C_170_A, AL1);
    if (SL1 == 0) {
      SL1 = SACIPOL_IUPBES(AP, AL1);
    }
    CL = AL1;
    do {
      CL = SACROOT_RIB(CL, BL1);
      SL = SACIPOL_IUPBES(C_170_A, CL);
    } while (!(SL1 * SL <= 0));
    J1Y = SACLIST_LIST2(CL, BL1);
    LS = MASSTOR_COMP(J1Y, LS);
    J1Y = SACLIST_LIST2(AL1, CL);
    LS = MASSTOR_COMP(J1Y, LS);
  } EXIT_1:;
  return LS;
}

MASSTOR_LIST SACROOT_IPFSD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_169_A)
# else
(RL, C_169_A)
MASSTOR_LIST RL, C_169_A;
# endif
{
  MASSTOR_LIST B, B1, B2, BPP, C, L, NL, S;

  L = MASSTOR_BETA;
  S = MASSTOR_LIST1(C_169_A);
  do {
    MASSTOR_ADV(S, &B, &S);
    NL = MASSTOR_FIRST(B);
    if (NL <= 2) {
      L = MASSTOR_COMP(B, L);
    } else {
      BPP = SACIPOL_IPHDMV(RL, B, 2);
      SACPGCD_IPGCDC(RL, B, BPP, &C, &B1, &B2);
      if (SACIPOL_IPONE(RL, C) == 1) {
        L = MASSTOR_COMP(B, L);
      } else {
        S = SACLIST_COMP2(B1, C, S);
      }
    }
  } while (!(S == MASSTOR_SIL));
  return L;
}

MASSTOR_LIST SACROOT_IPLRRI
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST A1, A2, B1, I1, I11, I21, J1Y, J2Y, LP, LPP, M, S, S1, S2, SL, SP, SPP, SS1, SS2, T, T1, T2;

  LP = L;
  S = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LP, &A1, &LP);
    S1 = SACROOT_IPRIM(A1);
    S = MASSTOR_COMP(S1, S);
  } while (!(LP == MASSTOR_SIL));
  S = MASSTOR_INV(S);
  LP = L;
  SP = S;
  while (MASSTOR_RED(LP) != MASSTOR_SIL) {
    A1 = MASSTOR_FIRST(LP);
    S1 = MASSTOR_FIRST(SP);
    LPP = MASSTOR_RED(LP);
    SPP = MASSTOR_RED(SP);
    do {
      A2 = MASSTOR_FIRST(LPP);
      S2 = MASSTOR_FIRST(SPP);
      SACROOT_IPRRLS(A1, A2, S1, S2, &SS1, &SS2);
      S1 = SS1;
      MASSTOR_SFIRST(SPP, SS2);
      LPP = MASSTOR_RED(LPP);
      SPP = MASSTOR_RED(SPP);
    } while (!(LPP == MASSTOR_SIL));
    MASSTOR_SFIRST(SP, S1);
    LP = MASSTOR_RED(LP);
    SP = MASSTOR_RED(SP);
  }
  LP = L;
  SP = S;
  T = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LP, &A1, &LP);
    MASSTOR_ADV(SP, &S1, &SP);
    T1 = MASSTOR_BETA;
    while (S1 != MASSTOR_SIL) {
      MASSTOR_ADV(S1, &I11, &S1);
      T1 = SACLIST_COMP2(A1, I11, T1);
    }
    J1Y = MASSTOR_INV(T1);
    T = MASSTOR_COMP(J1Y, T);
  } while (!(LP == MASSTOR_SIL));
  T = MASSTOR_INV(T);
  while (MASSTOR_RED(T) != MASSTOR_SIL) {
    S = MASSTOR_BETA;
    while (T != MASSTOR_SIL && MASSTOR_RED(T) != MASSTOR_SIL) {
      SACLIST_ADV2(T, &T1, &T2, &T);
      S1 = MASSTOR_BETA;
      while (T1 != MASSTOR_SIL && T2 != MASSTOR_SIL) {
        I11 = MASSTOR_FIRST(T1);
        I21 = MASSTOR_FIRST(T2);
        J1Y = MASSTOR_FIRST(I11);
        J2Y = MASSTOR_FIRST(I21);
        SL = SACRN_RNCOMP(J1Y, J2Y);
        if (SL < 0) {
          SACLIST_ADV2(T1, &I1, &B1, &T1);
        } else {
          SACLIST_ADV2(T2, &I1, &B1, &T2);
        }
        S1 = SACLIST_COMP2(B1, I1, S1);
      }
      if (T1 == MASSTOR_SIL) {
        T1 = T2;
      }
      J1Y = MASSTOR_INV(S1);
      S1 = SACLIST_CONC(J1Y, T1);
      S = MASSTOR_COMP(S1, S);
    }
    if (T != MASSTOR_SIL) {
      J1Y = MASSTOR_FIRST(T);
      S = MASSTOR_COMP(J1Y, S);
    }
    T = MASSTOR_INV(S);
  }
  M = MASSTOR_FIRST(T);
  return M;
}

MASSTOR_LIST SACROOT_IPRCH
# ifdef __STDC__
(MASSTOR_LIST C_168_A, MASSTOR_LIST I, MASSTOR_LIST KL)
# else
(C_168_A, I, KL)
MASSTOR_LIST C_168_A, I, KL;
# endif
{
  MASSTOR_LIST A1, AB, EL, J, L, L1, L2, P;

  AB = SACIPOL_IPABS(1, C_168_A);
  L1 = SACROOT_IPSFSD(1, AB);
  L = MASSTOR_BETA;
  do {
    MASSTOR_ADV(L1, &P, &L1);
    SACLIST_FIRST2(P, &EL, &A1);
    L2 = SACROOT_IPRCHS(A1, I, KL);
    while (L2 != MASSTOR_SIL) {
      MASSTOR_ADV(L2, &J, &L2);
      P = SACLIST_LIST2(EL, J);
      L = MASSTOR_COMP(P, L);
    }
  } while (!(L1 == MASSTOR_SIL));
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST SACROOT_IPRCHS
# ifdef __STDC__
(MASSTOR_LIST C_167_A, MASSTOR_LIST I, MASSTOR_LIST KL)
# else
(C_167_A, I, KL)
MASSTOR_LIST C_167_A, I, KL;
# endif
{
  MASSTOR_LIST BL, J, L, L1, SL, SLP, SLPP, TL;

  L = MASSTOR_BETA;
  L1 = SACROOT_IPSRM(C_167_A, I);
  if (L1 == MASSTOR_SIL) {
    return L;
  }
  do {
    MASSTOR_ADV(L1, &J, &L1);
    BL = SACLIST_SECOND(J);
    if (SACIPOL_IUPBRE(C_167_A, BL) == 0) {
      J = SACLIST_LIST2(BL, BL);
    } else {
      SACROOT_IPRCNP(C_167_A, J, &SLP, &SLPP, &J);
      TL = SACROOT_RILC(J, KL);
      if (TL == 0) {
        SL = SLP * SLPP;
        J = SACROOT_IPRCN1(C_167_A, J, SL, KL);
      }
    }
    L = MASSTOR_COMP(J, L);
  } while (!(L1 == MASSTOR_SIL));
  L = MASSTOR_INV(L);
  return L;
}

void SACROOT_IPRCNP
# ifdef __STDC__
(MASSTOR_LIST C_166_A, MASSTOR_LIST I, MASSTOR_LIST *SLP, MASSTOR_LIST *SLPP, MASSTOR_LIST *J)
# else
(C_166_A, I, SLP, SLPP, J)
MASSTOR_LIST C_166_A, I;
MASSTOR_LIST *SLP, *SLPP, *J;
# endif
{
  MASSTOR_LIST AP, BL, BL1, BL2, DL, DL1, DL2, FL, HL, J1Y, SL, TL;

  SACLIST_FIRST2(I, &BL1, &BL2);
  HL = SACLIST_LIST2(1, 2);
  *SLP = SACIPOL_IUPBES(C_166_A, BL2);
  AP = SACIPOL_IPDMV(1, C_166_A);
  DL1 = SACIPOL_IUPBRE(AP, BL1);
  DL2 = SACIPOL_IUPBRE(AP, BL2);
  DL = SACRN_RNDIF(DL2, DL1);
  *SLPP = SACRN_RNSIGN(DL);
  if (*SLP * *SLPP > 0) {
    J1Y = -3;
    FL = SACLIST_LIST2(J1Y, 4);
  } else {
    J1Y = -4;
    FL = SACLIST_LIST2(J1Y, 3);
  }
  for (;;) {
    DL = SACRN_RNPROD(FL, DL2);
    DL = SACRN_RNSUM(DL1, DL);
    TL = SACRN_RNSIGN(DL);
    if (*SLPP * TL >= 0) {
      goto EXIT_4;
    }
    BL = SACRN_RNSUM(BL1, BL2);
    BL = SACRN_RNPROD(BL, HL);
    SL = SACIPOL_IUPBES(C_166_A, BL);
    if (SL == 0) {
      BL1 = BL;
      BL2 = BL;
      goto EXIT_4;
    }
    DL = SACIPOL_IUPBRE(AP, BL);
    if (SL == *SLP) {
      BL2 = BL;
      DL2 = DL;
    } else {
      BL1 = BL;
      DL1 = DL;
    }
  } EXIT_4:;
  *J = SACLIST_LIST2(BL1, BL2);
  return;
}

MASSTOR_LIST SACROOT_IPRCN1
# ifdef __STDC__
(MASSTOR_LIST C_165_A, MASSTOR_LIST I, MASSTOR_LIST SL, MASSTOR_LIST KL)
# else
(C_165_A, I, SL, KL)
MASSTOR_LIST C_165_A, I, SL, KL;
# endif
{
  MASSTOR_LIST AP, BL, BL1, BL2, DL1, DL2, DLP, J, QL1, QL2;

  AP = SACIPOL_IPDMV(1, C_165_A);
  J = I;
  while (SACROOT_RILC(J, KL) == 0) {
    SACLIST_FIRST2(J, &BL1, &BL2);
    DL1 = SACIPOL_IUPBRE(C_165_A, BL1);
    DL2 = SACIPOL_IUPBRE(C_165_A, BL2);
    if (SL < 0) {
      BL = BL1;
    } else {
      BL = BL2;
    }
    DLP = SACIPOL_IUPBRE(AP, BL);
    QL1 = SACRN_RNQ(DL1, DLP);
    QL2 = SACRN_RNQ(DL2, DLP);
    BL1 = SACRN_RNDIF(BL1, QL1);
    BL2 = SACRN_RNDIF(BL2, QL2);
    J = SACLIST_LIST2(BL1, BL2);
    if (SACRN_RNCOMP(BL1, BL2) == 0) {
      return J;
    }
    J = SACROOT_RINT(J);
  }
  return J;
}

MASSTOR_LIST SACROOT_IPRIM
# ifdef __STDC__
(MASSTOR_LIST C_164_A)
# else
(C_164_A)
MASSTOR_LIST C_164_A;
# endif
{
  MASSTOR_LIST AB, AS, BL, BLS, HL, I, I1, I2, J1Y, KL, L, LP, LS, NL, SL;

  NL = SACPOL_PDEG(C_164_A);
  L = MASSTOR_BETA;
  if (NL == 0) {
    return L;
  }
  AB = SACPOL_PDBORD(C_164_A);
  BL = SACROOT_IUPRB(AB);
  SACRN_RNFCL2(BL, &HL, &KL);
  AS = SACIPOL_IUPBHT(AB, KL);
  LS = SACROOT_IPRIMU(AS);
  while (LS != MASSTOR_SIL) {
    MASSTOR_ADV(LS, &I, &LS);
    I = SACRN_RIRNP(I, BL);
    L = MASSTOR_COMP(I, L);
  }
  L = MASSTOR_INV(L);
  if (MASSTOR_FIRST(AB) < NL) {
    J1Y = SACLIST_LIST2(0, 0);
    L = MASSTOR_COMP(J1Y, L);
  }
  AS = SACIPOL_IUPNT(AS);
  LS = SACROOT_IPRIMU(AS);
  BLS = SACRN_RNNEG(BL);
  while (LS != MASSTOR_SIL) {
    MASSTOR_ADV(LS, &I, &LS);
    I = SACRN_RIRNP(I, BLS);
    L = MASSTOR_COMP(I, L);
  }
  LP = L;
  while (L != MASSTOR_SIL && MASSTOR_RED(LP) != MASSTOR_SIL) {
    I1 = MASSTOR_FIRST(LP);
    I2 = SACLIST_SECOND(LP);
    SACROOT_IPRRS(C_164_A, C_164_A, I1, I2, &I1, &I2, &SL);
    MASSTOR_SFIRST(LP, I1);
    LP = MASSTOR_RED(LP);
    MASSTOR_SFIRST(LP, I2);
  }
  return L;
}

MASSTOR_LIST SACROOT_IPRIMO
# ifdef __STDC__
(MASSTOR_LIST C_163_A, MASSTOR_LIST AP, MASSTOR_LIST I)
# else
(C_163_A, AP, I)
MASSTOR_LIST C_163_A, AP, I;
# endif
{
  MASSTOR_LIST BL, CL, J, L;

  L = SACROOT_IPRIMS(C_163_A, AP, I);
  if (L != MASSTOR_SIL) {
    L = MASSTOR_INV(L);
    J = MASSTOR_FIRST(L);
    BL = SACLIST_SECOND(I);
    CL = SACLIST_SECOND(J);
    if (SACRN_RNCOMP(BL, CL) == 0 && SACIPOL_IUPBES(C_163_A, BL) == 0) {
      L = MASSTOR_RED(L);
    }
    L = MASSTOR_INV(L);
  }
  return L;
}

MASSTOR_LIST SACROOT_IPRIMS
# ifdef __STDC__
(MASSTOR_LIST C_162_A, MASSTOR_LIST AP, MASSTOR_LIST I)
# else
(C_162_A, AP, I)
MASSTOR_LIST C_162_A, AP, I;
# endif
{
  MASSTOR_LIST A1, AL, AL1, ALP1, BL, BL1, BLP1, CL, HLP, HLS, I1, IP1, KL, KLP, L, L1, LP;

  if (SACPOL_PDEG(C_162_A) == 0) {
    L = MASSTOR_BETA;
    return L;
  }
  SACLIST_FIRST2(I, &AL, &BL);
  CL = SACRN_RNDIF(BL, AL);
  SACRN_RNFCL2(CL, &KL, &KLP);
  if (BL == 0) {
    HLP = 0;
  } else {
    HLS = SACRN_RNQ(BL, CL);
    HLP = MASSTOR_FIRST(HLS);
  }
  A1 = SACIPOL_IUPBHT(C_162_A, KL);
  A1 = SACIPOL_IUPTR(A1, HLP);
  A1 = SACIPOL_IUPNT(A1);
  L1 = SACROOT_IPRIMU(A1);
  LP = MASSTOR_BETA;
  while (L1 != MASSTOR_SIL) {
    MASSTOR_ADV(L1, &I1, &L1);
    SACLIST_FIRST2(I1, &AL1, &BL1);
    ALP1 = SACRN_RNPROD(AL1, CL);
    ALP1 = SACRN_RNDIF(BL, ALP1);
    BLP1 = SACRN_RNPROD(BL1, CL);
    BLP1 = SACRN_RNDIF(BL, BLP1);
    IP1 = SACLIST_LIST2(BLP1, ALP1);
    LP = MASSTOR_COMP(IP1, LP);
  }
  L = SACROOT_IIC(C_162_A, AP, I, LP);
  return L;
}

MASSTOR_LIST SACROOT_IPRIMU
# ifdef __STDC__
(MASSTOR_LIST C_161_A)
# else
(C_161_A)
MASSTOR_LIST C_161_A;
# endif
{
  MASSTOR_LIST AL, B, B1, BL, CL, EL, EL1, I, J1Y, L, S, TL, VL, VL1;

  L = MASSTOR_BETA;
  S = MASSTOR_BETA;
  B = C_161_A;
  AL = 0;
  BL = SACLIST_LIST2(1, 1);
  EL = SACPOL_PORD(C_161_A);
  VL = SACROOT_IPVCHT(B);
  TL = SACLIST_LIST2(1, 2);
  for (;;) {
    for (;;) {
      if (VL <= 1) {
        if (VL == 1) {
          I = SACLIST_LIST2(AL, BL);
          L = MASSTOR_COMP(I, L);
        }
        if (EL > 0) {
          I = SACLIST_LIST2(AL, AL);
          L = MASSTOR_COMP(I, L);
        }
        goto EXIT_6;
      }
      J1Y = -1;
      B1 = SACIPOL_IUPBHT(B, J1Y);
      B = SACIPOL_IUPTR1(B1);
      CL = SACRN_RNSUM(AL, BL);
      CL = SACRN_RNPROD(CL, TL);
      EL1 = EL;
      VL1 = SACROOT_IPVCHT(B1);
      EL = SACPOL_PORD(B);
      VL = SACROOT_IPVCHT(B);
      if (EL1 > 0 || VL1 > 0) {
        S = SACLIST_COMP2(AL, CL, S);
        S = SACLIST_COMP3(VL1, EL1, B1, S);
      }
      AL = CL;
    } EXIT_6:;
    if (S == MASSTOR_SIL) {
      return L;
    }
    SACLIST_ADV3(S, &VL, &EL, &B, &S);
    SACLIST_ADV2(S, &AL, &BL, &S);
  } EXIT_5:;
  return L;
}

MASSTOR_LIST SACROOT_IPRIU
# ifdef __STDC__
(MASSTOR_LIST C_160_A)
# else
(C_160_A)
MASSTOR_LIST C_160_A;
# endif
{
  MASSTOR_LIST AB, AS, I, L, LS, ML, NL, RL1, RL2, RLP1, RLP2;

  NL = MASSTOR_FIRST(C_160_A);
  AB = SACPOL_PDBORD(C_160_A);
  ML = MASSTOR_FIRST(AB);
  L = SACROOT_IPRIUP(AB);
  if (ML < NL) {
    I = SACLIST_LIST2(0, 0);
    L = MASSTOR_COMP(I, L);
  }
  AS = SACIPOL_IUPNT(AB);
  LS = SACROOT_IPRIUP(AS);
  while (LS != MASSTOR_SIL) {
    MASSTOR_ADV(LS, &I, &LS);
    SACLIST_ADV2(I, &RL1, &RL2, &I);
    RLP1 = SACRN_RNNEG(RL1);
    RLP2 = SACRN_RNNEG(RL2);
    I = SACLIST_LIST2(RLP2, RLP1);
    L = MASSTOR_COMP(I, L);
  }
  return L;
}

MASSTOR_LIST SACROOT_IPRIUP
# ifdef __STDC__
(MASSTOR_LIST C_159_A)
# else
(C_159_A)
MASSTOR_LIST C_159_A;
# endif
{
  MASSTOR_LIST AL, B, B1, B2, BL, CL, DL, EL, FL, HL, J1Y, L, RL, S, SL, TL, UL, VL, VL1, VL2;

  L = MASSTOR_BETA;
  S = MASSTOR_BETA;
  B = C_159_A;
  RL = SACLIST_LIST2(0, 1);
  SL = SACLIST_LIST2(1, 0);
  TL = 2;
  VL = SACROOT_IUPVAR(B);
  if (VL == 0) {
    return L;
  }
  for (;;) {
    if (VL <= 1) {
      if (MASSTOR_FIRST(RL) == 0) {
        RL = 0;
      }
      J1Y = SACLIST_LIST2(RL, SL);
      L = MASSTOR_COMP(J1Y, L);
    } else {
      for (;;) {
        B1 = SACIPOL_IUPTR1(B);
        J1Y = SACPOL_PRT(B);
        B2 = SACIPOL_IUPTR1(J1Y);
        SACLIST_FIRST2(RL, &AL, &CL);
        SACLIST_FIRST2(SL, &BL, &DL);
        EL = SACI_ISUM(AL, BL);
        FL = SACI_ISUM(CL, DL);
        HL = SACLIST_LIST2(EL, FL);
        if (TL == 2) {
          UL = B1;
          B1 = B2;
          B2 = UL;
        }
        VL1 = SACROOT_IUPVAR(B1);
        VL2 = SACROOT_IUPVAR(B2);
        if (VL1 != 0) {
          S = SACLIST_COMP4(B1, RL, HL, VL1, S);
        }
        if (SACPOL_PORD(B2) > 0) {
          J1Y = -1;
          S = SACLIST_COMP4(0, HL, HL, J1Y, S);
        }
        if (VL2 <= 1) {
          goto EXIT_8;
        }
        B = B2;
        RL = HL;
        VL = VL2;
        TL = 2;
      } EXIT_8:;
      if (VL2 == 1) {
        J1Y = SACLIST_LIST2(HL, SL);
        L = MASSTOR_COMP(J1Y, L);
      }
    }
    if (S == MASSTOR_SIL) {
      goto EXIT_7;
    }
    SACLIST_ADV4(S, &B, &RL, &SL, &VL, &S);
    TL = 1;
  } EXIT_7:;
  return L;
}

void SACROOT_IPRRLS
# ifdef __STDC__
(MASSTOR_LIST A1, MASSTOR_LIST A2, MASSTOR_LIST L1, MASSTOR_LIST L2, MASSTOR_LIST *LS1, MASSTOR_LIST *LS2)
# else
(A1, A2, L1, L2, LS1, LS2)
MASSTOR_LIST A1, A2, L1, L2;
MASSTOR_LIST *LS1, *LS2;
# endif
{
  MASSTOR_LIST I1, I2, LP1, LP2, SL;

  if (L1 == MASSTOR_SIL || L2 == MASSTOR_SIL) {
    *LS1 = L1;
    *LS2 = L2;
    return;
  }
  MASSTOR_ADV(L1, &I1, &LP1);
  *LS1 = MASSTOR_BETA;
  MASSTOR_ADV(L2, &I2, &LP2);
  *LS2 = MASSTOR_BETA;
  do {
    SACROOT_IPRRS(A1, A2, I1, I2, &I1, &I2, &SL);
    if (SL < 0) {
      *LS1 = MASSTOR_COMP(I1, *LS1);
      if (LP1 != MASSTOR_SIL) {
        MASSTOR_ADV(LP1, &I1, &LP1);
      } else {
        I1 = 0;
      }
    } else {
      *LS2 = MASSTOR_COMP(I2, *LS2);
      if (LP2 != MASSTOR_SIL) {
        MASSTOR_ADV(LP2, &I2, &LP2);
      } else {
        I2 = 0;
      }
    }
  } while (!(I1 == 0 || I2 == 0));
  if (I1 == 0) {
    *LS2 = MASSTOR_COMP(I2, *LS2);
    while (LP2 != MASSTOR_SIL) {
      MASSTOR_ADV(LP2, &I2, &LP2);
      *LS2 = MASSTOR_COMP(I2, *LS2);
    }
  } else {
    *LS1 = MASSTOR_COMP(I1, *LS1);
    while (LP1 != MASSTOR_SIL) {
      MASSTOR_ADV(LP1, &I1, &LP1);
      *LS1 = MASSTOR_COMP(I1, *LS1);
    }
  }
  *LS1 = MASSTOR_INV(*LS1);
  *LS2 = MASSTOR_INV(*LS2);
  return;
}

void SACROOT_IPRRS
# ifdef __STDC__
(MASSTOR_LIST A1, MASSTOR_LIST A2, MASSTOR_LIST I1, MASSTOR_LIST I2, MASSTOR_LIST *IS1, MASSTOR_LIST *IS2, MASSTOR_LIST *SL)
# else
(A1, A2, I1, I2, IS1, IS2, SL)
MASSTOR_LIST A1, A2, I1, I2;
MASSTOR_LIST *IS1, *IS2, *SL;
# endif
{
  MASSTOR_LIST AL1, AL2, BL1, BL2, CL, DL1, DL2, SL1l, SL1r, SL2l, SL2r, TL, UL, VL;

  SACLIST_FIRST2(I1, &AL1, &BL1);
  SACLIST_FIRST2(I2, &AL2, &BL2);
  if (SACRN_RNCOMP(BL1, AL2) < 0) {
    *IS1 = I1;
    *IS2 = I2;
    *SL = -1;
    return;
  }
  if (SACRN_RNCOMP(BL2, AL1) < 0) {
    *IS1 = I1;
    *IS2 = I2;
    *SL = 1;
    return;
  }
  DL1 = SACRN_RNDIF(BL1, AL1);
  DL2 = SACRN_RNDIF(BL2, AL2);
  SL1l = SACIPOL_IUPBES(A1, AL1);
  SL2l = SACIPOL_IUPBES(A2, AL2);
  SL1r = SACIPOL_IUPBES(A1, BL1);
  SL2r = SACIPOL_IUPBES(A2, BL2);
  for (;;) {
    TL = SACRN_RNCOMP(DL1, DL2);
    if (TL >= 0) {
      CL = SACROOT_RIB(AL1, BL1);
      UL = SACIPOL_IUPBES(A1, CL);
      if (SL1r == 0 || SL1r * UL < 0) {
        if (UL == 0 || SL1l * UL < 0) {
          BL1 = CL;
          SL1r = UL;
          VL = -1;
        } else {
          AL1 = CL;
          SL1l = UL;
          VL = 1;
        }
      } else {
        BL1 = CL;
        SL1r = UL;
        VL = -1;
      }
      DL1 = SACRN_RNDIF(BL1, AL1);
    }
    if (TL < 0) {
      CL = SACROOT_RIB(AL2, BL2);
      UL = SACIPOL_IUPBES(A2, CL);
      if (SL2r == 0 || SL2r * UL < 0) {
        if (UL == 0 || SL2l * UL < 0) {
          BL2 = CL;
          SL2r = UL;
          VL = -1;
        } else {
          AL2 = CL;
          SL2l = UL;
          VL = -1;
        }
      } else {
        BL2 = CL;
        SL2r = UL;
        VL = 1;
      }
      DL2 = SACRN_RNDIF(BL2, AL2);
    }
    if (VL < 0 && SACRN_RNCOMP(BL1, AL2) < 0) {
      *SL = -1;
      goto EXIT_9;
    } else {
      if (VL > 0 && SACRN_RNCOMP(BL2, AL1) < 0) {
        *SL = 1;
        goto EXIT_9;
      }
    }
  } EXIT_9:;
  *IS1 = SACLIST_LIST2(AL1, BL1);
  *IS2 = SACLIST_LIST2(AL2, BL2);
  return;
}

MASSTOR_LIST SACROOT_IPSFSD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_158_A)
# else
(RL, C_158_A)
MASSTOR_LIST RL, C_158_A;
# endif
{
  MASSTOR_LIST A1, AB, EL, L, L1, LB, P;

  AB = SACPGCD_IPPP(RL, C_158_A);
  LB = SACPGCD_IPSF(RL, AB);
  L = MASSTOR_BETA;
  LB = MASSTOR_INV(LB);
  do {
    MASSTOR_ADV(LB, &P, &LB);
    SACLIST_FIRST2(P, &EL, &A1);
    L1 = SACROOT_IPFSD(RL, A1);
    while (L1 != MASSTOR_SIL) {
      MASSTOR_ADV(L1, &A1, &L1);
      P = SACLIST_LIST2(EL, A1);
      L = MASSTOR_COMP(P, L);
    }
  } while (!(LB == MASSTOR_SIL));
  return L;
}

MASSTOR_LIST SACROOT_IPSRM
# ifdef __STDC__
(MASSTOR_LIST C_157_A, MASSTOR_LIST I)
# else
(C_157_A, I)
MASSTOR_LIST C_157_A, I;
# endif
{
  MASSTOR_LIST AL, BL, I1, I2, L, L1, L2, NL;

  NL = SACPOL_PDEG(C_157_A);
  if (NL == 0) {
    L = MASSTOR_BETA;
    return L;
  }
  if (I == MASSTOR_SIL) {
    BL = SACROOT_IUPRB(C_157_A);
    AL = SACRN_RNNEG(BL);
    I1 = SACLIST_LIST2(AL, 0);
    I2 = SACLIST_LIST2(0, BL);
  } else {
    SACLIST_FIRST2(I, &AL, &BL);
    if (SACRN_RNSIGN(AL) >= 0) {
      I1 = MASSTOR_BETA;
      I2 = I;
    } else {
      if (SACRN_RNSIGN(BL) <= 0) {
        I1 = I;
        I2 = MASSTOR_BETA;
      } else {
        I1 = SACLIST_LIST2(AL, 0);
        I2 = SACLIST_LIST2(0, BL);
      }
    }
  }
  if (I1 != MASSTOR_SIL) {
    L1 = SACROOT_IPSRMS(C_157_A, I1);
  } else {
    L1 = MASSTOR_BETA;
  }
  if (I2 != MASSTOR_SIL) {
    L2 = SACROOT_IPSRMS(C_157_A, I2);
  } else {
    L2 = MASSTOR_BETA;
  }
  L = SACLIST_CONC(L1, L2);
  return L;
}

MASSTOR_LIST SACROOT_IPSRMS
# ifdef __STDC__
(MASSTOR_LIST C_156_A, MASSTOR_LIST I)
# else
(C_156_A, I)
MASSTOR_LIST C_156_A, I;
# endif
{
  MASSTOR_LIST AP, APP, APPS, APPSP, APS, APSP, L, LP, LPP;

  if (C_156_A == 0) {
    L = MASSTOR_BETA;
    return L;
  }
  AP = SACIPOL_IPDMV(1, C_156_A);
  L = SACROOT_IPRIMS(C_156_A, AP, I);
  APS = SACPGCD_IPPGSD(1, AP);
  APSP = SACIPOL_IPDMV(1, APS);
  LP = SACROOT_IPRIMS(APS, APSP, I);
  SACROOT_IPRRLS(C_156_A, APS, L, LP, &L, &LP);
  APP = SACIPOL_IPDMV(1, AP);
  APPS = SACPGCD_IPPGSD(1, APP);
  LPP = SACROOT_IPRIMS(APPS, APPSP, I);
  SACROOT_IPRRLS(C_156_A, APPS, L, LPP, &L, &LPP);
  return L;
}

MASSTOR_LIST SACROOT_IPVCHT
# ifdef __STDC__
(MASSTOR_LIST C_155_A)
# else
(C_155_A)
MASSTOR_LIST C_155_A;
# endif
{
  MASSTOR_LIST AP, B, KL;

  AP = SACPOL_PRT(C_155_A);
  B = SACIPOL_IUPTR1(AP);
  KL = SACROOT_IUPVAR(B);
  return KL;
}

MASSTOR_LIST SACROOT_IUPRB
# ifdef __STDC__
(MASSTOR_LIST C_154_A)
# else
(C_154_A)
MASSTOR_LIST C_154_A;
# endif
{
  MASSTOR_LIST AL, AL1, ALB, ALB1, ALBP, AP, BL, DL, HL, HL1, J1Y, KL, ML, ML1, NL, NL1, QL, RL, SL, TL;

  SACLIST_ADV2(C_154_A, &NL, &AL, &AP);
  if (AP == MASSTOR_SIL) {
    HL = -1;
  } else {
    ALB = SACI_IABSF(AL);
    ML = SACI_ILOG2(ALB);
    TL = 0;
    do {
      SACLIST_ADV2(AP, &NL1, &AL1, &AP);
      KL = NL - NL1;
      ML1 = SACI_ILOG2(AL1);
      J1Y = ML1 - ML;
      DL = J1Y - 1;
      MASELEM_MASQREM(DL, KL, &QL, &RL);
      if (RL < 0) {
        RL = RL + KL;
        QL = QL - 1;
      }
      HL1 = QL + 1;
      if (RL == KL - 1) {
        ALB1 = SACI_IABSF(AL1);
        J1Y = HL1 * KL;
        J1Y = -J1Y;
        ALBP = SACI_ITRUNC(ALB, J1Y);
        SL = SACI_ICOMP(ALB1, ALBP);
        if (SL > 0) {
          HL1 = HL1 + 1;
        }
      }
      if (TL == 0 || HL1 > HL) {
        HL = HL1;
      }
      TL = 1;
    } while (!(AP == MASSTOR_SIL));
  }
  J1Y = HL + 1;
  BL = SACRN_RNP2(J1Y);
  return BL;
}

MASSTOR_LIST SACROOT_IUPRLP
# ifdef __STDC__
(MASSTOR_LIST C_153_A)
# else
(C_153_A)
MASSTOR_LIST C_153_A;
# endif
{
  MASSTOR_LIST AL, BL, J1Y, L, RL;

  if (SACPOL_PRED(C_153_A) == 0) {
    RL = 0;
  } else {
    L = SACPOL_PCL(C_153_A);
    SACLIST_FIRST2(L, &AL, &BL);
    J1Y = SACI_INEG(BL);
    RL = SACRN_RNRED(J1Y, AL);
    return RL;
  }
  return RL;
}

MASSTOR_LIST SACROOT_IUPVAR
# ifdef __STDC__
(MASSTOR_LIST C_152_A)
# else
(C_152_A)
MASSTOR_LIST C_152_A;
# endif
{
  MASSTOR_LIST AL, AP, EL, NL, SL, TL;

  NL = 0;
  AP = C_152_A;
  SACLIST_ADV2(AP, &EL, &AL, &AP);
  SL = SACI_ISIGNF(AL);
  while (AP != MASSTOR_SIL) {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    TL = SACI_ISIGNF(AL);
    if (SL != TL) {
      NL = NL + 1;
      SL = TL;
    }
  }
  return NL;
}

MASSTOR_LIST SACROOT_IUPVSI
# ifdef __STDC__
(MASSTOR_LIST C_151_A, MASSTOR_LIST I)
# else
(C_151_A, I)
MASSTOR_LIST C_151_A, I;
# endif
{
  MASSTOR_LIST AL, B, BL, C, DL, HL, KL, KLP, VL;

  SACLIST_FIRST2(I, &AL, &BL);
  DL = SACRN_RNDIF(BL, AL);
  SACRN_RNFCL2(DL, &KL, &KLP);
  if (AL != 0) {
    HL = SACRN_RNQ(AL, DL);
    HL = MASSTOR_FIRST(HL);
  } else {
    HL = 0;
  }
  if (KL != 0) {
    B = SACIPOL_IUPBHT(C_151_A, KL);
  } else {
    B = C_151_A;
  }
  if (HL != 0) {
    C = SACIPOL_IUPTR(B, HL);
  } else {
    C = B;
  }
  VL = SACROOT_IPVCHT(C);
  return VL;
}

MASSTOR_LIST SACROOT_RIB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST SL)
# else
(RL, SL)
MASSTOR_LIST RL, SL;
# endif
{
  MASSTOR_LIST CL, DL, EL, H, HL, HLP, NL, QL, TL;

  DL = SACRN_RNDIF(RL, SL);
  SACRN_RNFCL2(DL, &HL, &NL);
  HLP = SACRN_RNP2(HL);
  QL = SACRN_RNQ(RL, HLP);
  CL = SACRN_RNCEIL(QL);
  CL = SACRN_RNINT(CL);
  TL = SACRN_RNPROD(CL, HLP);
  EL = SACRN_RNCOMP(TL, RL);
  if (EL == 0) {
    TL = SACRN_RNSUM(TL, HLP);
  }
  EL = SACRN_RNCOMP(TL, SL);
  if (EL >= 0) {
    H = SACLIST_LIST2(1, 2);
    HLP = SACRN_RNPROD(HLP, H);
    TL = SACRN_RNDIF(TL, HLP);
  }
  return TL;
}

MASSTOR_LIST SACROOT_RILC
# ifdef __STDC__
(MASSTOR_LIST I, MASSTOR_LIST KL)
# else
(I, KL)
MASSTOR_LIST I, KL;
# endif
{
  MASSTOR_LIST AL, BL, DL, ML, NL, TL;

  SACLIST_FIRST2(I, &AL, &BL);
  DL = SACRN_RNDIF(BL, AL);
  TL = 1;
  if (DL != 0) {
    SACRN_RNFCL2(DL, &ML, &NL);
    if (NL > KL) {
      TL = 0;
    }
  }
  return TL;
}

MASSTOR_LIST SACROOT_RINT
# ifdef __STDC__
(MASSTOR_LIST I)
# else
(I)
MASSTOR_LIST I;
# endif
{
  MASSTOR_LIST DL, HL, IS, J1Y, KL, KLP, RL, RLS, SL, SLS, TL;

  SACLIST_FIRST2(I, &RL, &SL);
  DL = SACRN_RNDIF(SL, RL);
  SACRN_RNFCL2(DL, &KL, &KLP);
  HL = KL - 1;
  TL = SACRN_RNP2(HL);
  J1Y = SACRN_RNQ(RL, TL);
  RLS = SACRN_RNFLOR(J1Y);
  if (RLS != 0) {
    RLS = SACLIST_LIST2(RLS, 1);
    RLS = SACRN_RNPROD(RLS, TL);
  }
  J1Y = SACRN_RNQ(SL, TL);
  SLS = SACRN_RNCEIL(J1Y);
  if (SLS != 0) {
    SLS = SACLIST_LIST2(SLS, 1);
    SLS = SACRN_RNPROD(SLS, TL);
  }
  IS = SACLIST_LIST2(RLS, SLS);
  return IS;
}

void BEGIN_SACROOT()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACPGCD();

  }
}
