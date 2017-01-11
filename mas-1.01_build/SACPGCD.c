#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACMPOL
#include "SACMPOL.h"
#endif

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACDPOL
#include "SACDPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

CHAR SACPGCD_rcsid [] = "$Id: SACPGCD.md,v 1.2 1992/02/12 17:35:01 pesch Exp $";
CHAR SACPGCD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACPGCD.mi,v 1.3 1992/10/15 16:29:05 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACPGCD_IPC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_216_A)
# else
(RL, C_216_A)
MASSTOR_LIST RL, C_216_A;
# endif
{
  MASSTOR_LIST AP, C, C1, CP, CP1, RLP;

  if (C_216_A == 0) {
    C = 0;
    return C;
  }
  AP = MASSTOR_RED(C_216_A);
  MASSTOR_ADV(AP, &C, &AP);
  RLP = RL - 1;
  while (AP != MASSTOR_SIL) {
    AP = MASSTOR_RED(AP);
    MASSTOR_ADV(AP, &C1, &AP);
    SACPGCD_IPGCDC(RLP, C, C1, &C, &CP, &CP1);
    if (SACIPOL_IPONE(RLP, C) == 1) {
      return C;
    }
  }
  C = SACIPOL_IPABS(RLP, C);
  return C;
}

void SACPGCD_IPCPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_215_A, MASSTOR_LIST *C, MASSTOR_LIST *AB)
# else
(RL, C_215_A, C, AB)
MASSTOR_LIST RL, C_215_A;
MASSTOR_LIST *C, *AB;
# endif
{
  MASSTOR_LIST SL;

  SACPGCD_IPSCPP(RL, C_215_A, &SL, C, AB);
  return;
}

void SACPGCD_IPGCDC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_214_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AB, MASSTOR_LIST *BB)
# else
(RL, C_214_A, B, C, AB, BB)
MASSTOR_LIST RL, C_214_A, B;
MASSTOR_LIST *C, *AB, *BB;
# endif
{
  MASSTOR_LIST AH, AHS, AL, ALB, ALH, ALP, AP, AS, BH, BHS, BL, BLB, BLH, BLP, BP, BS, CHS, CL, CLH, CLHP, CLP, CLPP, CLS, CP, CS, DL, DLB, EL, ELB, FL, FLB, GL, GLB, GLH, J1Y, J2Y, P, PL, Q, QL, QLP, TL, U, US, V, VS, W, WL, WP, WS;

  if (C_214_A == 0 && B == 0) {
    *C = 0;
    *AB = 0;
    *BB = 0;
    return;
  }
  if (RL == 0) {
    *C = SACI_IGCD(C_214_A, B);
    *AB = SACI_IQ(C_214_A, *C);
    *BB = SACI_IQ(B, *C);
    return;
  }
  if (C_214_A == 0) {
    *C = SACIPOL_IPABS(RL, B);
    *AB = 0;
    J1Y = SACIPOL_IPSIGN(RL, B);
    *BB = SACPOL_PINV(0, J1Y, RL);
    return;
  }
  if (B == 0) {
    *C = SACIPOL_IPABS(RL, C_214_A);
    *BB = 0;
    J1Y = SACIPOL_IPSIGN(RL, C_214_A);
    *AB = SACPOL_PINV(0, J1Y, RL);
    return;
  }
  SACPGCD_IPICPP(RL, C_214_A, &AL, &AH);
  SACPGCD_IPICPP(RL, B, &BL, &BH);
  CL = SACI_IGCD(AL, BL);
  ALH = SACPOL_PLBCF(RL, AH);
  BLH = SACPOL_PLBCF(RL, BH);
  CLH = SACI_IGCD(ALH, BLH);
  DL = SACIPOL_IPMAXN(RL, AH);
  EL = SACIPOL_IPMAXN(RL, BH);
  FL = SACI_IMAX(DL, EL);
  J1Y = SACI_IPROD(2, CLH);
  GL = SACI_IPROD(J1Y, FL);
  U = SACPOL_PDEGV(RL, AH);
  V = SACPOL_PDEGV(RL, BH);
  J1Y = SACIPOL_IPFCB(U);
  DLB = SACI_IMP2(DL, J1Y);
  J1Y = SACIPOL_IPFCB(V);
  ELB = SACI_IMP2(EL, J1Y);
  FLB = SACI_IMAX(DLB, ELB);
  J1Y = SACI_IPROD(8, CLH);
  GLB = SACI_IPROD(J1Y, FLB);
  P = SACPOL_PRIME;
  J1Y = MASSTOR_FIRST(U);
  J1Y = J1Y + 1;
  J2Y = MASSTOR_RED(U);
  W = MASSTOR_COMP(J1Y, J2Y);
  do {
    do {
      do {
        do {
          do {
            do {
              if (P == MASSTOR_SIL) {
                MASERR_ERROR(MASERR_fatal, "PRIME LIST EXHAUSTED IN IPGCDC.", 31L);
                return;
              }
              MASSTOR_ADV(P, &PL, &P);
              CLS = SACM_MDHOM(PL, CLH);
            } while (!(CLS != 0));
            AS = SACMPOL_MPHOM(RL, PL, AH);
            US = SACPOL_PDEGV(RL, AS);
          } while (!(SACLIST_EQUAL(U, US) != 0));
          BS = SACMPOL_MPHOM(RL, PL, BH);
          VS = SACPOL_PDEGV(RL, BS);
        } while (!(SACLIST_EQUAL(V, VS) != 0));
        SACPGCD_MPGCDC(RL, PL, AS, BS, &CS, &AHS, &BHS);
        if (SACIPOL_IPONE(RL, CS) == 1) {
          *C = SACPOL_PINV(0, CL, RL);
          *AB = SACIPOL_IPIQ(RL, C_214_A, CL);
          *BB = SACIPOL_IPIQ(RL, B, CL);
          return;
        }
        WS = SACPOL_PDEGV(RL, CS);
        TL = SACPOL_VCOMP(W, WS);
        if (TL >= 2) {
          Q = 1;
          AP = 0;
          BP = 0;
          CP = 0;
          W = SACPOL_VMIN(W, WS);
          WP = W;
          GLH = GLB;
          do {
            MASSTOR_ADV(WP, &WL, &WP);
            J1Y = WL + 1;
            GLH = SACI_IPROD(GLH, J1Y);
          } while (!(WP == MASSTOR_SIL));
        }
      } while (!!(TL == 1 || TL == 3 || TL == 0 && SACI_ICOMP(Q, GLH) > 0));
      CHS = SACMPOL_MPMDP(RL, PL, CLS, CS);
      J1Y = SACM_MDHOM(PL, Q);
      QLP = SACM_MDINV(PL, J1Y);
      CP = SACIPOL_IPCRA(Q, PL, QLP, RL, CP, CHS);
      AP = SACIPOL_IPCRA(Q, PL, QLP, RL, AP, AHS);
      BP = SACIPOL_IPCRA(Q, PL, QLP, RL, BP, BHS);
      Q = SACI_IPROD(Q, PL);
    } while (!(SACI_ICOMP(Q, GL) > 0));
    QL = SACI_ILOG2(Q);
    J1Y = SACIPOL_IPSUMN(RL, CP);
    CLP = SACI_ILOG2(J1Y);
    J1Y = SACIPOL_IPMAXN(RL, AP);
    ALP = SACI_ILOG2(J1Y);
    J1Y = SACIPOL_IPMAXN(RL, BP);
    BLP = SACI_ILOG2(J1Y);
    CLPP = MASELEM_MASMAX(ALP, BLP);
  } while (!(QL >= CLP + CLPP + 2));
  SACPGCD_IPICPP(RL, CP, &CLP, C);
  CLHP = SACI_IQ(CLH, CLP);
  *AB = SACIPOL_IPIQ(RL, AP, CLHP);
  *BB = SACIPOL_IPIQ(RL, BP, CLHP);
  *C = SACIPOL_IPIP(RL, CL, *C);
  ALB = SACI_IQ(AL, CL);
  *AB = SACIPOL_IPIP(RL, ALB, *AB);
  BLB = SACI_IQ(BL, CL);
  *BB = SACIPOL_IPIP(RL, BLB, *BB);
  return;
}

MASSTOR_LIST SACPGCD_IPIC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_213_A)
# else
(RL, C_213_A)
MASSTOR_LIST RL, C_213_A;
# endif
{
  MASSTOR_LIST CL;

  if (C_213_A == 0) {
    CL = 0;
  } else {
    CL = SACPGCD_IPICS(RL, C_213_A, 0);
  }
  return CL;
}

void SACPGCD_IPICPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_212_A, MASSTOR_LIST *AL, MASSTOR_LIST *AB)
# else
(RL, C_212_A, AL, AB)
MASSTOR_LIST RL, C_212_A;
MASSTOR_LIST *AL, *AB;
# endif
{
  if (C_212_A == 0) {
    *AL = 0;
    *AB = 0;
  } else {
    *AL = SACPGCD_IPIC(RL, C_212_A);
    *AB = SACIPOL_IPIQ(RL, C_212_A, *AL);
  }
  return;
}

MASSTOR_LIST SACPGCD_IPICS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_211_A, MASSTOR_LIST CL)
# else
(RL, C_211_A, CL)
MASSTOR_LIST RL, C_211_A, CL;
# endif
{
  MASSTOR_LIST AL, AP, DL, EL, RLP;

  AP = C_211_A;
  RLP = RL - 1;
  DL = CL;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      DL = SACI_IGCD(AL, DL);
    } else {
      DL = SACPGCD_IPICS(RLP, AL, DL);
    }
    if (DL == 1) {
      return DL;
    }
  } while (!(AP == MASSTOR_SIL));
  return DL;
}

MASSTOR_LIST SACPGCD_IPIPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_210_A)
# else
(RL, C_210_A)
MASSTOR_LIST RL, C_210_A;
# endif
{
  MASSTOR_LIST AB, AL;

  SACPGCD_IPICPP(RL, C_210_A, &AL, &AB);
  return AB;
}

MASSTOR_LIST SACPGCD_IPPGSD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_209_A)
# else
(RL, C_209_A)
MASSTOR_LIST RL, C_209_A;
# endif
{
  MASSTOR_LIST B, BP, C, D;

  if (C_209_A == 0) {
    B = 0;
    return B;
  }
  B = SACPGCD_IPPP(RL, C_209_A);
  if (MASSTOR_FIRST(B) > 0) {
    BP = SACIPOL_IPDMV(RL, B);
    SACPGCD_IPGCDC(RL, B, BP, &C, &B, &D);
  }
  return B;
}

MASSTOR_LIST SACPGCD_IPPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_208_A)
# else
(RL, C_208_A)
MASSTOR_LIST RL, C_208_A;
# endif
{
  MASSTOR_LIST AB, C;

  SACPGCD_IPCPP(RL, C_208_A, &C, &AB);
  return AB;
}

MASSTOR_LIST SACPGCD_IPRES
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_207_A, MASSTOR_LIST B)
# else
(RL, C_207_A, B)
MASSTOR_LIST RL, C_207_A, B;
# endif
{
  MASSTOR_LIST AS, BS, C, CS, DL, EL, FL, I, J1Y, ML, NL, PL, Q, QL, RLP;

  DL = SACIPOL_IPMAXN(RL, C_207_A);
  EL = SACIPOL_IPMAXN(RL, B);
  ML = MASSTOR_FIRST(C_207_A);
  NL = MASSTOR_FIRST(B);
  DL = SACI_IEXP(DL, NL);
  EL = SACI_IEXP(EL, ML);
  J1Y = ML + NL;
  FL = SACCOMB_IFACTL(J1Y);
  FL = SACI_IPROD(EL, FL);
  FL = SACI_IPROD(DL, FL);
  I = SACPOL_PRIME;
  Q = 1;
  C = 0;
  RLP = RL - 1;
  while (I != MASSTOR_SIL) {
    MASSTOR_ADV(I, &PL, &I);
    AS = SACMPOL_MPHOM(RL, PL, C_207_A);
    if (SACPOL_PDEG(AS) == ML) {
      BS = SACMPOL_MPHOM(RL, PL, B);
      if (SACPOL_PDEG(BS) == NL) {
        CS = SACPGCD_MPRES(RL, PL, AS, BS);
        QL = SACM_MDHOM(PL, Q);
        QL = SACM_MDINV(PL, QL);
        C = SACIPOL_IPCRA(Q, PL, QL, RLP, C, CS);
        Q = SACI_IPROD(Q, PL);
        if (SACI_ICOMP(Q, FL) >= 0) {
          return C;
        }
      }
    }
  }
  MASERR_ERROR(MASERR_fatal, "ALGORITHM IPRES FAILS.", 22L);
  return C;
}

MASSTOR_LIST SACPGCD_IPRPRS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_206_A, MASSTOR_LIST B)
# else
(RL, C_206_A, B)
MASSTOR_LIST RL, C_206_A, B;
# endif
{
  MASSTOR_LIST A1, A2, A3, AL1, ALS1, DL, IL, J1Y, NL1, NL2, S;

  A1 = C_206_A;
  A2 = B;
  S = SACLIST_LIST2(A2, A1);
  DL = -1;
  for (;;) {
    A3 = SACIPOL_IPPSR(RL, A1, A2);
    if (A3 == 0) {
      S = MASSTOR_INV(S);
      return S;
    }
    if (DL >= 0) {
      AL1 = SACPOL_PLDCF(A1);
      ALS1 = AL1;
      {
        LONGINT B_1 = 1, B_2 = DL;

        if (B_1 <= B_2)
          for (IL = B_1;; IL += 1) {
            if (RL == 1) {
              ALS1 = SACI_IPROD(ALS1, AL1);
            } else {
              J1Y = RL - 1;
              ALS1 = SACIPOL_IPPROD(J1Y, ALS1, AL1);
            }
            if (IL >= B_2) break;
          }
      }
      ALS1 = SACLIST_LIST2(0, ALS1);
      A3 = SACIPOL_IPQ(RL, A3, ALS1);
    }
    S = MASSTOR_COMP(A3, S);
    NL1 = SACPOL_PDEG(A1);
    NL2 = SACPOL_PDEG(A2);
    DL = NL1 - NL2;
    A1 = A2;
    A2 = A3;
  } EXIT_1:;
  return S;
}

void SACPGCD_IPSCPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_205_A, MASSTOR_LIST *SL, MASSTOR_LIST *C, MASSTOR_LIST *AB)
# else
(RL, C_205_A, SL, C, AB)
MASSTOR_LIST RL, C_205_A;
MASSTOR_LIST *SL, *C, *AB;
# endif
{
  MASSTOR_LIST A1, AP, C1, EL, RLP;

  if (C_205_A == 0) {
    *SL = 0;
    *C = 0;
    *AB = 0;
    return;
  }
  *SL = SACIPOL_IPSIGN(RL, C_205_A);
  AP = SACIPOL_IPABS(RL, C_205_A);
  RLP = RL - 1;
  *C = SACPGCD_IPC(RL, AP);
  if (SACIPOL_IPONE(RLP, *C) == 1) {
    *AB = AP;
  } else {
    *AB = MASSTOR_BETA;
    do {
      SACLIST_ADV2(AP, &EL, &A1, &AP);
      C1 = SACIPOL_IPQ(RLP, A1, *C);
      *AB = SACLIST_COMP2(C1, EL, *AB);
    } while (!(AP == MASSTOR_SIL));
    *AB = MASSTOR_INV(*AB);
  }
  return;
}

MASSTOR_LIST SACPGCD_IPSF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_204_A)
# else
(RL, C_204_A)
MASSTOR_LIST RL, C_204_A;
# endif
{
  MASSTOR_LIST AP, B, BP, C, CP, D, J1Y, JL, L;

  L = MASSTOR_BETA;
  AP = SACIPOL_IPDMV(RL, C_204_A);
  SACPGCD_IPGCDC(RL, C_204_A, AP, &B, &C, &CP);
  JL = 1;
  while (SACPOL_PDEG(B) > 0) {
    SACPGCD_IPGCDC(RL, B, C, &D, &BP, &CP);
    if (SACPOL_PDEG(CP) > 0) {
      J1Y = SACLIST_LIST2(JL, CP);
      L = MASSTOR_COMP(J1Y, L);
    }
    B = BP;
    C = D;
    JL = JL + 1;
  }
  J1Y = SACLIST_LIST2(JL, C);
  L = MASSTOR_COMP(J1Y, L);
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST SACPGCD_IPSPRS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_203_A, MASSTOR_LIST B)
# else
(RL, C_203_A, B)
MASSTOR_LIST RL, C_203_A, B;
# endif
{
  MASSTOR_LIST DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y, NL1, NL2, NL3, RLP, S;

  G1 = C_203_A;
  G2 = B;
  S = SACLIST_LIST2(G2, G1);
  NL1 = SACPOL_PDEG(G1);
  NL2 = SACPOL_PDEG(G2);
  DL0 = 0;
  DL1 = NL1 - NL2;
  RLP = RL - 1;
  IL = 1;
  for (;;) {
    GH3 = SACIPOL_IPPSR(RL, G1, G2);
    if (GH3 == 0) {
      S = MASSTOR_INV(S);
      return S;
    }
    if (MASELEM_MASEVEN(DL1)) {
      GH3 = SACIPOL_IPNEG(RL, GH3);
    }
    NL3 = SACPOL_PDEG(GH3);
    if (IL > 1) {
      GL1 = SACPOL_PLDCF(G1);
      HL1 = SACIPOL_IPEXP(RLP, GL1, DL0);
      if (IL > 2) {
        J1Y = DL0 - 1;
        HLS0 = SACIPOL_IPEXP(RLP, HL0, J1Y);
        HL1 = SACIPOL_IPQ(RLP, HL1, HLS0);
        HLS0 = 0;
      }
    }
    if (IL == 1) {
      G3 = GH3;
    } else {
      HLS1 = SACIPOL_IPEXP(RLP, HL1, DL1);
      HLS1 = SACIPOL_IPPROD(RLP, GL1, HLS1);
      HLS1 = SACLIST_LIST2(0, HLS1);
      G3 = SACIPOL_IPQ(RL, GH3, HLS1);
      HLS1 = 0;
      GH3 = 0;
    }
    S = MASSTOR_COMP(G3, S);
    NL1 = NL2;
    NL2 = NL3;
    DL0 = DL1;
    DL1 = NL1 - NL2;
    G1 = G2;
    G2 = G3;
    if (IL > 1) {
      HL0 = HL1;
    }
    IL = IL + 1;
  } EXIT_2:;
  return S;
}

void SACPGCD_IPSRP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_202_A, MASSTOR_LIST *AL, MASSTOR_LIST *AB)
# else
(RL, C_202_A, AL, AB)
MASSTOR_LIST RL, C_202_A;
MASSTOR_LIST *AL, *AB;
# endif
{
  MASSTOR_LIST AS, SL, UL, ULP, VL;

  if (C_202_A == 0) {
    *AL = 0;
    *AB = 0;
    return;
  }
  SACPGCD_RPBLGS(RL, C_202_A, &UL, &VL, &SL);
  ULP = SACI_IDPR(UL, SL);
  *AL = SACLIST_LIST2(ULP, VL);
  AS = SACRPOL_RPRNP(RL, *AL, C_202_A);
  *AB = SACIPOL_IPFRP(RL, AS);
  return;
}

void SACPGCD_MPGCDC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_201_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AB, MASSTOR_LIST *BB)
# else
(RL, PL, C_201_A, B, C, AB, BB)
MASSTOR_LIST RL, PL, C_201_A, B;
MASSTOR_LIST *C, *AB, *BB;
# endif
{
  MASSTOR_LIST AH, AHS, AL, ALB, ALH, ALP, AP, AS, BH, BHS, BL, BLB, BLH, BLP, BP, BS, CHS, CL, CLH, CLHP, CLP, CLPP, CLS, CP, CS, DL, EL, FL, GL, J1Y, J2Y, Q, QLP, RLP, TL, U, US, V, VS, W, WS;

  if (C_201_A == 0 && B == 0) {
    *C = 0;
    *AB = 0;
    *BB = 0;
    return;
  }
  if (C_201_A == 0) {
    BL = SACPOL_PLBCF(RL, B);
    *C = SACMPOL_MPMON(RL, PL, B);
    *AB = 0;
    *BB = SACPOL_PINV(0, BL, RL);
    return;
  }
  if (B == 0) {
    AL = SACPOL_PLBCF(RL, C_201_A);
    *C = SACMPOL_MPMON(RL, PL, C_201_A);
    *BB = 0;
    *AB = SACPOL_PINV(0, AL, RL);
    return;
  }
  if (RL == 1) {
    *C = SACPGCD_MUPGCD(PL, C_201_A, B);
    *AB = SACMPOL_MPQ(RL, PL, C_201_A, *C);
    *BB = SACMPOL_MPQ(RL, PL, B, *C);
    return;
  }
  SACPGCD_MPUCPP(RL, PL, C_201_A, &AL, &AH);
  SACPGCD_MPUCPP(RL, PL, B, &BL, &BH);
  CL = SACPGCD_MUPGCD(PL, AL, BL);
  RLP = RL - 1;
  ALH = SACPOL_PLBCF(RLP, AH);
  BLH = SACPOL_PLBCF(RLP, BH);
  CLH = SACPGCD_MUPGCD(PL, ALH, BLH);
  U = SACPOL_PDEGV(RLP, AH);
  V = SACPOL_PDEGV(RLP, BH);
  EL = SACPOL_PDEGSV(RL, AH, 1);
  FL = SACPOL_PDEGSV(RL, BH, 1);
  J1Y = SACPOL_PDEG(CLH);
  J2Y = MASELEM_MASMAX(EL, FL);
  GL = J1Y + J2Y;
  DL = -1;
  J1Y = MASSTOR_FIRST(U);
  J1Y = J1Y + 1;
  J2Y = MASSTOR_RED(U);
  W = MASSTOR_COMP(J1Y, J2Y);
  do {
    do {
      do {
        do {
          do {
            do {
              DL = DL + 1;
              if (DL == PL) {
                MASERR_ERROR(MASERR_fatal, "ELEMENTS OF Z SUB P EXHAUSTED IN MPGCDC.", 40L);
                return;
              }
              CLS = SACMPOL_MPEMV(1, PL, CLH, DL);
            } while (!(CLS != 0));
            AS = SACMPOL_MPEVAL(RL, PL, AH, 1, DL);
            US = SACPOL_PDEGV(RLP, AS);
          } while (!(SACLIST_EQUAL(U, US) != 0));
          BS = SACMPOL_MPEVAL(RL, PL, BH, 1, DL);
          VS = SACPOL_PDEGV(RLP, BS);
        } while (!(SACLIST_EQUAL(V, VS) != 0));
        SACPGCD_MPGCDC(RLP, PL, AS, BS, &CS, &AHS, &BHS);
        if (SACIPOL_IPONE(RLP, CS) == 1) {
          *C = SACPOL_PINV(0, CL, RLP);
          *AB = SACMPOL_MPUQ(RL, PL, C_201_A, CL);
          *BB = SACMPOL_MPUQ(RL, PL, B, CL);
          return;
        }
        WS = SACPOL_PDEGV(RLP, CS);
        TL = SACPOL_VCOMP(W, WS);
        if (TL >= 2) {
          Q = SACLIST_LIST2(0, 1);
          AP = 0;
          BP = 0;
          CP = 0;
          W = SACPOL_VMIN(W, WS);
        }
      } while (!!(TL == 1 || TL == 3 || TL == 0 && SACPOL_PDEG(Q) > GL));
      CHS = SACMPOL_MPMDP(RLP, PL, CLS, CS);
      J1Y = SACMPOL_MPEMV(1, PL, Q, DL);
      QLP = SACM_MDINV(PL, J1Y);
      CP = SACMPOL_MPINT(PL, Q, DL, QLP, RL, CP, CHS);
      AP = SACMPOL_MPINT(PL, Q, DL, QLP, RL, AP, AHS);
      BP = SACMPOL_MPINT(PL, Q, DL, QLP, RL, BP, BHS);
      J1Y = SACM_MDNEG(PL, DL);
      J1Y = SACLIST_LIST4(1, 1, 0, J1Y);
      Q = SACMPOL_MPPROD(1, PL, Q, J1Y);
    } while (!(SACPOL_PDEG(Q) > GL));
    CLP = SACPOL_PDEGSV(RL, CP, 1);
    ALP = SACPOL_PDEGSV(RL, AP, 1);
    BLP = SACPOL_PDEGSV(RL, BP, 1);
    CLPP = MASELEM_MASMAX(ALP, BLP);
  } while (!(SACPOL_PDEG(Q) > CLP + CLPP));
  SACPGCD_MPUCPP(RL, PL, CP, &CLP, C);
  CLHP = SACMPOL_MPQ(1, PL, CLH, CLP);
  *AB = SACMPOL_MPUQ(RL, PL, AP, CLHP);
  *BB = SACMPOL_MPUQ(RL, PL, BP, CLHP);
  *C = SACMPOL_MPUP(RL, PL, CL, *C);
  ALB = SACMPOL_MPQ(1, PL, AL, CL);
  *AB = SACMPOL_MPUP(RL, PL, ALB, *AB);
  BLB = SACMPOL_MPQ(1, PL, BL, CL);
  *BB = SACMPOL_MPUP(RL, PL, BLB, *BB);
  return;
}

MASSTOR_LIST SACPGCD_MPRES
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_200_A, MASSTOR_LIST B)
# else
(RL, PL, C_200_A, B)
MASSTOR_LIST RL, PL, C_200_A, B;
# endif
{
  MASSTOR_LIST AS, BL, BS, C, CS, D, DP, IL, J1Y, J2Y, KL, ML, ML1, NL, NL1, RLP;

  if (RL == 1) {
    C = SACPGCD_MUPRES(PL, C_200_A, B);
    return C;
  }
  ML = MASSTOR_FIRST(C_200_A);
  ML1 = SACPOL_PDEGSV(RL, C_200_A, 1);
  NL = MASSTOR_FIRST(B);
  NL1 = SACPOL_PDEGSV(RL, B, 1);
  J1Y = ML * NL1;
  J2Y = ML1 * NL;
  KL = J1Y + J2Y;
  RLP = RL - 1;
  C = 0;
  D = SACLIST_LIST2(0, 1);
  IL = 0;
  while (IL < PL) {
    AS = SACMPOL_MPEVAL(RL, PL, C_200_A, 1, IL);
    if (SACPOL_PDEG(AS) == ML) {
      BS = SACMPOL_MPEVAL(RL, PL, B, 1, IL);
      if (SACPOL_PDEG(BS) == NL) {
        CS = SACPGCD_MPRES(RLP, PL, AS, BS);
        BL = SACMPOL_MPEMV(1, PL, D, IL);
        BL = SACM_MDINV(PL, BL);
        C = SACMPOL_MPINT(PL, D, IL, BL, RLP, C, CS);
        J1Y = PL - IL;
        DP = SACLIST_LIST4(1, 1, 0, J1Y);
        D = SACMPOL_MPPROD(1, PL, D, DP);
        if (SACPOL_PDEG(D) > KL) {
          return C;
        }
      }
    }
    IL = IL + 1;
  }
  MASERR_ERROR(MASERR_fatal, "ALGORITHM MPRES FAILS.", 22L);
  return C;
}

MASSTOR_LIST SACPGCD_MPSPRS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_199_A, MASSTOR_LIST B)
# else
(RL, PL, C_199_A, B)
MASSTOR_LIST RL, PL, C_199_A, B;
# endif
{
  MASSTOR_LIST DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y, NL1, NL2, NL3, RLP, S;

  G1 = C_199_A;
  G2 = B;
  S = SACLIST_LIST2(G2, G1);
  NL1 = SACPOL_PDEG(G1);
  NL2 = SACPOL_PDEG(G2);
  DL0 = 0;
  DL1 = NL1 - NL2;
  RLP = RL - 1;
  IL = 1;
  for (;;) {
    GH3 = SACMPOL_MPPSR(RL, PL, G1, G2);
    if (GH3 == 0) {
      S = MASSTOR_INV(S);
      return S;
    }
    if (MASELEM_MASEVEN(DL1)) {
      GH3 = SACMPOL_MPNEG(RL, PL, GH3);
    }
    NL3 = SACPOL_PDEG(GH3);
    if (IL > 1) {
      GL1 = SACPOL_PLDCF(G1);
      HL1 = SACMPOL_MPEXP(RLP, PL, GL1, DL0);
      if (IL > 2) {
        J1Y = DL0 - 1;
        HLS0 = SACMPOL_MPEXP(RLP, PL, HL0, J1Y);
        HL1 = SACMPOL_MPQ(RLP, PL, HL1, HLS0);
        HLS0 = 0;
      }
    }
    if (IL == 1) {
      G3 = GH3;
    } else {
      HLS1 = SACMPOL_MPEXP(RLP, PL, HL1, DL1);
      HLS1 = SACMPOL_MPPROD(RLP, PL, GL1, HLS1);
      HLS1 = SACLIST_LIST2(0, HLS1);
      G3 = SACMPOL_MPQ(RL, PL, GH3, HLS1);
      HLS1 = 0;
      GH3 = 0;
    }
    S = MASSTOR_COMP(G3, S);
    NL1 = NL2;
    NL2 = NL3;
    DL0 = DL1;
    DL1 = NL1 - NL2;
    G1 = G2;
    G2 = G3;
    if (IL > 1) {
      HL0 = HL1;
    }
    IL = IL + 1;
  } EXIT_3:;
  return S;
}

MASSTOR_LIST SACPGCD_MPUC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_198_A)
# else
(RL, PL, C_198_A)
MASSTOR_LIST RL, PL, C_198_A;
# endif
{
  MASSTOR_LIST CL;

  if (C_198_A == 0) {
    CL = 0;
  } else {
    CL = SACPGCD_MPUCS(RL, PL, C_198_A, 0);
  }
  return CL;
}

void SACPGCD_MPUCPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_197_A, MASSTOR_LIST *AL, MASSTOR_LIST *AB)
# else
(RL, PL, C_197_A, AL, AB)
MASSTOR_LIST RL, PL, C_197_A;
MASSTOR_LIST *AL, *AB;
# endif
{
  if (C_197_A == 0) {
    *AL = 0;
    *AB = 0;
  } else {
    *AL = SACPGCD_MPUC(RL, PL, C_197_A);
    *AB = SACMPOL_MPUQ(RL, PL, C_197_A, *AL);
  }
  return;
}

MASSTOR_LIST SACPGCD_MPUCS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_196_A, MASSTOR_LIST CL)
# else
(RL, PL, C_196_A, CL)
MASSTOR_LIST RL, PL, C_196_A, CL;
# endif
{
  MASSTOR_LIST AL, AP, DL, EL, RLP;

  AP = C_196_A;
  RLP = RL - 1;
  DL = CL;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 1) {
      DL = SACPGCD_MUPGCD(PL, AL, DL);
    } else {
      DL = SACPGCD_MPUCS(RLP, PL, AL, DL);
    }
  } while (!(AP == MASSTOR_SIL || SACPOL_PDEG(DL) == 0));
  return DL;
}

MASSTOR_LIST SACPGCD_MPUPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_195_A)
# else
(RL, PL, C_195_A)
MASSTOR_LIST RL, PL, C_195_A;
# endif
{
  MASSTOR_LIST AB, AL;

  SACPGCD_MPUCPP(RL, PL, C_195_A, &AL, &AB);
  return AB;
}

void SACPGCD_MUPEGC
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_194_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *U, MASSTOR_LIST *V)
# else
(PL, C_194_A, B, C, U, V)
MASSTOR_LIST PL, C_194_A, B;
MASSTOR_LIST *C, *U, *V;
# endif
{
  MASSTOR_LIST D;

  SACPGCD_MUPHEG(PL, C_194_A, B, C, V);
  if (C_194_A == 0) {
    *U = 0;
  } else {
    D = SACMPOL_MPPROD(1, PL, B, *V);
    D = SACMPOL_MPDIF(1, PL, *C, D);
    *U = SACMPOL_MPQ(1, PL, D, C_194_A);
  }
  return;
}

MASSTOR_LIST SACPGCD_MUPGCD
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_193_A, MASSTOR_LIST B)
# else
(PL, C_193_A, B)
MASSTOR_LIST PL, C_193_A, B;
# endif
{
  MASSTOR_LIST A1, A2, A3, C, ML, NL;

  if (C_193_A == 0) {
    C = SACMPOL_MPMON(1, PL, B);
    return C;
  }
  if (B == 0) {
    C = SACMPOL_MPMON(1, PL, C_193_A);
    return C;
  }
  ML = SACPOL_PDEG(C_193_A);
  NL = SACPOL_PDEG(B);
  if (ML >= NL) {
    A1 = C_193_A;
    A2 = B;
  } else {
    A1 = B;
    A2 = C_193_A;
  }
  A1 = SACDPOL_DPFP(1, A1);
  A2 = SACDPOL_DPFP(1, A2);
  do {
    A3 = SACDPOL_DMUPNR(PL, A1, A2);
    A1 = A2;
    A2 = A3;
  } while (!(A2 == 0));
  A1 = SACPOL_PFDP(1, A1);
  C = SACMPOL_MPMON(1, PL, A1);
  return C;
}

void SACPGCD_MUPHEG
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_192_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *V)
# else
(PL, C_192_A, B, C, V)
MASSTOR_LIST PL, C_192_A, B;
MASSTOR_LIST *C, *V;
# endif
{
  MASSTOR_LIST A1, A2, A3, AL, ALP, J1Y, Q, V1, V2, V3;

  V1 = 0;
  V2 = SACLIST_LIST2(0, 1);
  A1 = C_192_A;
  A2 = B;
  while (A2 != 0) {
    SACMPOL_MPQR(1, PL, A1, A2, &Q, &A3);
    J1Y = SACMPOL_MPPROD(1, PL, Q, V2);
    V3 = SACMPOL_MPDIF(1, PL, V1, J1Y);
    A1 = A2;
    A2 = A3;
    V1 = V2;
    V2 = V3;
  }
  if (A1 == 0) {
    *C = 0;
    *V = 0;
    return;
  }
  AL = SACPOL_PLDCF(A1);
  ALP = SACM_MDINV(PL, AL);
  *C = SACMPOL_MPMDP(1, PL, ALP, A1);
  *V = SACMPOL_MPMDP(1, PL, ALP, V1);
  return;
}

MASSTOR_LIST SACPGCD_MUPRES
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_191_A, MASSTOR_LIST B)
# else
(PL, C_191_A, B)
MASSTOR_LIST PL, C_191_A, B;
# endif
{
  MASSTOR_LIST A1, A2, A3, CL, CL2, IL, NL1, NL2, NL3, SL, TL;

  CL = 1;
  A1 = SACDPOL_DPFP(1, C_191_A);
  A2 = SACDPOL_DPFP(1, B);
  NL1 = MASSTOR_FIRST(A1);
  NL2 = MASSTOR_FIRST(A2);
  SL = 0;
  if (NL1 < NL2) {
    if (MASELEM_MASODD(NL1) && MASELEM_MASODD(NL2)) {
      SL = 1;
    }
    TL = A1;
    A1 = A2;
    A2 = TL;
  }
  do {
    A3 = SACDPOL_DMUPNR(PL, A1, A2);
    if (A3 == 0) {
      CL = 0;
      return CL;
    }
    NL1 = MASSTOR_FIRST(A1);
    NL2 = MASSTOR_FIRST(A2);
    NL3 = MASSTOR_FIRST(A3);
    if (MASELEM_MASODD(NL1) && MASELEM_MASODD(NL2)) {
      SL = 1 - SL;
    }
    CL2 = SACLIST_SECOND(A2);
    {
      LONGINT B_3 = 1, B_4 = NL1 - NL3;

      if (B_3 <= B_4)
        for (IL = B_3;; IL += 1) {
          CL = SACM_MDPROD(PL, CL, CL2);
          if (IL >= B_4) break;
        }
    }
    A1 = A2;
    A2 = A3;
  } while (!(NL3 == 0));
  CL2 = SACLIST_SECOND(A2);
  {
    LONGINT B_5 = 1, B_6 = NL2;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        CL = SACM_MDPROD(PL, CL, CL2);
        if (IL >= B_6) break;
      }
  }
  if (SL == 1) {
    CL = PL - CL;
  }
  return CL;
}

MASSTOR_LIST SACPGCD_MUPSFF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_190_A)
# else
(PL, C_190_A)
MASSTOR_LIST PL, C_190_A;
# endif
{
  MASSTOR_LIST A1, AP, B, BP, C, D, EL, J1Y, JL, L, L1, LP, M, M1, MP;

  LP = MASSTOR_SIL;
  AP = SACMPOL_MUPDER(PL, C_190_A);
  if (AP == 0) {
    B = C_190_A;
  } else {
    B = SACPGCD_MUPGCD(PL, C_190_A, AP);
    C = SACMPOL_MPQ(1, PL, C_190_A, B);
    JL = 1;
    do {
      D = SACPGCD_MUPGCD(PL, B, C);
      A1 = SACMPOL_MPQ(1, PL, C, D);
      if (MASSTOR_FIRST(A1) > 0) {
        J1Y = SACLIST_LIST2(JL, A1);
        LP = MASSTOR_COMP(J1Y, LP);
      }
      if (MASSTOR_FIRST(D) > 0) {
        C = D;
        B = SACMPOL_MPQ(1, PL, B, C);
        JL = JL + 1;
      }
    } while (!(MASSTOR_FIRST(D) == 0));
  }
  if (MASSTOR_FIRST(B) == 0) {
    L = MASSTOR_INV(LP);
    return L;
  }
  BP = MASSTOR_BETA;
  do {
    SACLIST_ADV2(B, &EL, &A1, &B);
    EL = EL / PL;
    BP = SACLIST_COMP2(A1, EL, BP);
  } while (!(B == MASSTOR_SIL));
  B = MASSTOR_INV(BP);
  M = SACPGCD_MUPSFF(PL, B);
  MP = M;
  do {
    MASSTOR_ADV(MP, &M1, &MP);
    J1Y = MASSTOR_FIRST(M1);
    EL = PL * J1Y;
    MASSTOR_SFIRST(M1, EL);
  } while (!(MP == MASSTOR_SIL));
  M = MASSTOR_INV(M);
  L = MASSTOR_SIL;
  while (LP != MASSTOR_SIL && M != MASSTOR_SIL) {
    if (MASSTOR_FIRST(MASSTOR_FIRST(LP)) > MASSTOR_FIRST(MASSTOR_FIRST(M))) {
      MASSTOR_ADV(LP, &L1, &LP);
    } else {
      MASSTOR_ADV(M, &L1, &M);
    }
    L = MASSTOR_COMP(L1, L);
  }
  if (M == MASSTOR_SIL) {
    LP = MASSTOR_INV(LP);
  } else {
    LP = MASSTOR_INV(M);
  }
  L = SACLIST_CONC(LP, L);
  return L;
}

void SACPGCD_RPBLGS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_189_A, MASSTOR_LIST *AL, MASSTOR_LIST *BL, MASSTOR_LIST *SL)
# else
(RL, C_189_A, AL, BL, SL)
MASSTOR_LIST RL, C_189_A;
MASSTOR_LIST *AL, *BL, *SL;
# endif
{
  MASSTOR_LIST ALP, AS, BLP, CL, EL, RLP, SLP;

  if (C_189_A == 0) {
    *AL = 0;
    *BL = 0;
    *SL = 0;
    return;
  }
  if (RL == 0) {
    BLP = MASSTOR_FIRST(C_189_A);
    *SL = SACI_ISIGNF(BLP);
    *BL = SACI_IABSF(BLP);
    *AL = SACLIST_SECOND(C_189_A);
    return;
  }
  RLP = RL - 1;
  SACLIST_ADV2(C_189_A, &EL, &CL, &AS);
  SACPGCD_RPBLGS(RLP, CL, AL, BL, SL);
  while (AS != MASSTOR_SIL) {
    SACLIST_ADV2(AS, &EL, &CL, &AS);
    if (RLP == 0) {
      SACLIST_FIRST2(CL, &BLP, &ALP);
    } else {
      SACPGCD_RPBLGS(RLP, CL, &ALP, &BLP, &SLP);
    }
    *AL = SACI_ILCM(*AL, ALP);
    if (*BL != 1) {
      *BL = SACI_IGCD(*BL, BLP);
    }
  }
  return;
}

void BEGIN_SACPGCD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACM();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();
    BEGIN_SACRPOL();
    BEGIN_SACDPOL();

  }
}
