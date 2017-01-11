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

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

#ifndef DEFINITION_SACEXT5
#include "SACEXT5.h"
#endif

CHAR SACEXT5_rcsid [] = "$Id: SACEXT5.md,v 1.2 1992/02/12 17:34:50 pesch Exp $";
CHAR SACEXT5_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT5.mi,v 1.3 1992/10/15 16:28:57 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT5_IPCSFB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_196_A)
# else
(RL, C_196_A)
MASSTOR_LIST RL, C_196_A;
# endif
{
  MASSTOR_LIST A1, AP, AP1, AS, B, L, L1;

  AS = MASSTOR_BETA;
  AP = C_196_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    L = SACPGCD_IPSF(RL, A1);
    do {
      MASSTOR_ADV(L, &L1, &L);
      AP1 = SACLIST_SECOND(L1);
      AS = MASSTOR_COMP(AP1, AS);
    } while (!(L == MASSTOR_SIL));
  }
  B = SACEXT5_ISPSFB(RL, AS);
  return B;
}

MASSTOR_LIST SACEXT5_IPDSCR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_195_A)
# else
(RL, C_195_A)
MASSTOR_LIST RL, C_195_A;
# endif
{
  MASSTOR_LIST AL, AP, B, NL, RLP;

  AP = SACIPOL_IPDMV(RL, C_195_A);
  B = SACPGCD_IPRES(RL, C_195_A, AP);
  AL = SACPOL_PLDCF(C_195_A);
  RLP = RL - 1;
  B = SACIPOL_IPQ(RLP, B, AL);
  NL = SACPOL_PDEG(C_195_A);
  if (MASELEM_MASREM(NL, 4) >= 2) {
    B = SACIPOL_IPNEG(RLP, B);
  }
  return B;
}

void SACEXT5_IPLCPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_194_A, MASSTOR_LIST *C, MASSTOR_LIST *P)
# else
(RL, C_194_A, C, P)
MASSTOR_LIST RL, C_194_A;
MASSTOR_LIST *C, *P;
# endif
{
  MASSTOR_LIST A1, AP, C1, P1, RLP, SL;

  *C = MASSTOR_BETA;
  *P = MASSTOR_BETA;
  AP = C_194_A;
  RLP = RL - 1;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    SACPGCD_IPSCPP(RL, A1, &SL, &C1, &P1);
    if (!(SACEXT4_PCONST(RLP, C1) == 1)) {
      *C = MASSTOR_COMP(C1, *C);
    }
    if (SACPOL_PDEG(P1) > 0) {
      *P = MASSTOR_COMP(P1, *P);
    }
  }
  *C = MASSTOR_INV(*C);
  *P = MASSTOR_INV(*P);
  return;
}

MASSTOR_LIST SACEXT5_IPPSC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_193_A, MASSTOR_LIST B)
# else
(RL, C_193_A, B)
MASSTOR_LIST RL, C_193_A, B;
# endif
{
  MASSTOR_LIST DL0, DL1, G1, G2, G3, GH3, GL1, HL0, HL1, HLS0, HLS1, IL, J1Y, NL1, NL2, NL3, P, RLP, TL;

  NL1 = SACPOL_PDEG(C_193_A);
  NL2 = SACPOL_PDEG(B);
  if (NL1 > NL2) {
    G1 = C_193_A;
    G2 = B;
  } else {
    G1 = B;
    G2 = C_193_A;
    TL = NL1;
    NL1 = NL2;
    NL2 = TL;
  }
  DL0 = 0;
  DL1 = NL1 - NL2;
  RLP = RL - 1;
  IL = 1;
  P = MASSTOR_BETA;
  for (;;) {
    if (G2 != 0) {
      GH3 = SACIPOL_IPPSR(RL, G1, G2);
      if (GH3 != 0) {
        if (MASELEM_MASEVEN(DL1)) {
          GH3 = SACIPOL_IPNEG(RL, GH3);
        }
        NL3 = SACPOL_PDEG(GH3);
      }
    }
    if (IL > 1) {
      GL1 = SACPOL_PLDCF(G1);
      HL1 = SACIPOL_IPEXP(RLP, GL1, DL0);
      if (IL > 2) {
        J1Y = DL0 - 1;
        HLS0 = SACIPOL_IPEXP(RLP, HL0, J1Y);
        HL1 = SACIPOL_IPQ(RLP, HL1, HLS0);
        P = MASSTOR_COMP(HL1, P);
        if (G2 == 0) {
          return P;
        }
      }
    }
    if (IL == 1 || GH3 == 0) {
      G3 = GH3;
    } else {
      HLS1 = SACIPOL_IPEXP(RLP, HL1, DL1);
      HLS1 = SACIPOL_IPPROD(RLP, GL1, HLS1);
      HLS1 = SACLIST_LIST2(0, HLS1);
      G3 = SACIPOL_IPQ(RL, GH3, HLS1);
    }
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
  } EXIT_1:;
  return P;
}

MASSTOR_LIST SACEXT5_IPSFBA
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_192_A, MASSTOR_LIST B)
# else
(RL, C_192_A, B)
MASSTOR_LIST RL, C_192_A, B;
# endif
{
  MASSTOR_LIST ABP, AP, B1, BB1, BP, BS, C;

  AP = C_192_A;
  BP = B;
  BS = MASSTOR_BETA;
  while (BP != MASSTOR_SIL && SACPOL_PDEG(AP) > 0) {
    MASSTOR_ADV(BP, &B1, &BP);
    SACPGCD_IPGCDC(RL, AP, B1, &C, &ABP, &BB1);
    if (SACPOL_PDEG(C) > 0) {
      BS = MASSTOR_COMP(C, BS);
    }
    if (SACPOL_PDEG(BB1) > 0) {
      BS = MASSTOR_COMP(BB1, BS);
    }
    AP = ABP;
  }
  if (SACPOL_PDEG(AP) > 0) {
    BS = MASSTOR_COMP(AP, BS);
  }
  while (BP != MASSTOR_SIL) {
    MASSTOR_ADV(BP, &B1, &BP);
    BS = MASSTOR_COMP(B1, BS);
  }
  return BS;
}

MASSTOR_LIST SACEXT5_ISPSFB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_191_A)
# else
(RL, C_191_A)
MASSTOR_LIST RL, C_191_A;
# endif
{
  MASSTOR_LIST A1, AP, B;

  B = MASSTOR_BETA;
  AP = C_191_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    B = SACEXT5_IPSFBA(RL, A1, B);
  }
  return B;
}

void SACEXT5_IUPRC
# ifdef __STDC__
(MASSTOR_LIST C_190_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *R)
# else
(C_190_A, B, C, R)
MASSTOR_LIST C_190_A, B;
MASSTOR_LIST *C, *R;
# endif
{
  MASSTOR_LIST AS, BS, CS, DL, EL, FL, I, J1Y, ML, NL, PL, Q, QL, RS;

  DL = SACIPOL_IPMAXN(1, C_190_A);
  EL = SACIPOL_IPMAXN(1, B);
  ML = SACPOL_PDEG(C_190_A);
  NL = SACPOL_PDEG(B);
  DL = SACI_IEXP(DL, NL);
  EL = SACI_IEXP(EL, ML);
  J1Y = ML + NL;
  FL = SACCOMB_IFACTL(J1Y);
  FL = SACI_IPROD(EL, FL);
  FL = SACI_IPROD(DL, FL);
  I = SACPOL_PRIME;
  Q = 1;
  *C = 0;
  *R = 0;
  while (I != MASSTOR_SIL) {
    MASSTOR_ADV(I, &PL, &I);
    AS = SACMPOL_MPHOM(1, PL, C_190_A);
    if (SACPOL_PDEG(AS) == ML) {
      BS = SACMPOL_MPHOM(1, PL, B);
      if (SACPOL_PDEG(BS) == NL) {
        SACEXT5_MUPRC(PL, AS, BS, &CS, &RS);
        QL = SACM_MDHOM(PL, Q);
        QL = SACM_MDINV(PL, QL);
        *C = SACIPOL_IPCRA(Q, PL, QL, 1, *C, CS);
        *R = SACIPOL_IPCRA(Q, PL, QL, 0, *R, RS);
        Q = SACI_IPROD(Q, PL);
        if (SACI_ICOMP(Q, FL) >= 0) {
          return;
        }
      }
    }
  }
  MASERR_ERROR(MASERR_fatal, "algorithm IUPRC fails", 21L);
  return;
}

void SACEXT5_MUPRC
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_189_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *RL)
# else
(PL, C_189_A, B, C, RL)
MASSTOR_LIST PL, C_189_A, B;
MASSTOR_LIST *C, *RL;
# endif
{
  MASSTOR_LIST A1, A2, A3, IL, J1Y, NL1, NL2, NL3, Q, RL2, SL, TL, VL1, VL2, VL3;

  *RL = 1;
  A1 = C_189_A;
  A2 = B;
  VL1 = 0;
  VL2 = SACPOL_PMON(1, 0);
  NL1 = SACPOL_PDEG(A1);
  NL2 = SACPOL_PDEG(A2);
  SL = 0;
  if (NL1 < NL2) {
    if (ODD(NL1) && ODD(NL2)) {
      SL = 1;
    }
    TL = A1;
    A1 = A2;
    A2 = TL;
    VL1 = VL2;
    VL2 = 0;
  }
  do {
    SACMPOL_MPQR(1, PL, A1, A2, &Q, &A3);
    J1Y = SACMPOL_MPPROD(1, PL, Q, VL2);
    VL3 = SACMPOL_MPDIF(1, PL, VL1, J1Y);
    if (A3 == 0) {
      *RL = 0;
      *C = VL3;
      return;
    }
    NL1 = SACPOL_PDEG(A1);
    NL2 = SACPOL_PDEG(A2);
    NL3 = SACPOL_PDEG(A3);
    if (MASELEM_MASODD(NL1) && MASELEM_MASODD(NL2)) {
      SL = 1 - SL;
    }
    RL2 = SACPOL_PLDCF(A2);
    {
      LONGINT B_1 = 1, B_2 = NL1 - NL3;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          *RL = SACM_MDPROD(PL, *RL, RL2);
          if (IL >= B_2) break;
        }
    }
    A1 = A2;
    A2 = A3;
    VL1 = VL2;
    VL2 = VL3;
  } while (!(NL3 == 0));
  RL2 = SACPOL_PLDCF(A2);
  {
    LONGINT B_3 = 1, B_4 = NL2 - 1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        *RL = SACM_MDPROD(PL, *RL, RL2);
        if (IL >= B_4) break;
      }
  }
  *C = SACMPOL_MPMDP(1, PL, *RL, VL2);
  *RL = SACM_MDPROD(PL, *RL, RL2);
  if (SL == 1) {
    *RL = PL - *RL;
  }
  return;
}

void BEGIN_SACEXT5()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACI();
    BEGIN_SACM();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();
    BEGIN_SACPGCD();
    BEGIN_SACEXT4();

  }
}
