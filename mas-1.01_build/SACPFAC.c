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

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
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

#ifndef DEFINITION_SACDPOL
#include "SACDPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACUPFAC
#include "SACUPFAC.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

CHAR SACPFAC_rcsid [] = "$Id: SACPFAC.md,v 1.2 1992/02/12 17:34:59 pesch Exp $";
CHAR SACPFAC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACPFAC.mi,v 1.3 1992/10/15 16:29:03 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SACPFAC_IPCEVP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_200_A, MASSTOR_LIST *B, MASSTOR_LIST *L)
# else
(RL, C_200_A, B, L)
MASSTOR_LIST RL, C_200_A;
MASSTOR_LIST *B, *L;
# endif
{
  MASSTOR_LIST AB, AL, ALT, AT, C, CP, D, E, EL, F, J1Y, LL, RLP;
  BOOLEAN fin;

  RLP = RL - 1;
  AT = C_200_A;
  *L = MASSTOR_BETA;
  for (;;) {
    if (RLP == 0) {
      *B = AT;
      return;
    }
    LL = 0;
    SACLIST_ADV2(AT, &EL, &ALT, &AB);
    do {
      fin = TRUE;
      AL = SACIPOL_IPEMV(RLP, ALT, LL);
      if (AL == 0) {
        if (LL > 0) {
          LL = -LL;
        } else {
          LL = 1 - LL;
        }
        fin = FALSE;
      } else {
        if (AB != MASSTOR_SIL) {
          J1Y = RLP + 1;
          C = SACIPOL_IPEVAL(J1Y, AB, RLP, LL);
        } else {
          C = 0;
        }
        if (C == 0) {
          C = MASSTOR_BETA;
        }
        C = SACLIST_COMP2(EL, AL, C);
        CP = SACIPOL_IPDMV(RLP, C);
        SACPGCD_IPGCDC(RLP, C, CP, &D, &E, &F);
        if (SACPOL_PDEG(D) > 0) {
          fin = FALSE;
          if (LL > 0) {
            LL = -LL;
          } else {
            LL = 1 - LL;
          }
        }
      }
    } while (!fin);
    *L = MASSTOR_COMP(LL, *L);
    RLP = RLP - 1;
    AT = C;
  } EXIT_1:;
  return;
}

void SACPFAC_IPFAC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_199_A, MASSTOR_LIST *SL, MASSTOR_LIST *CL, MASSTOR_LIST *L)
# else
(RL, C_199_A, SL, CL, L)
MASSTOR_LIST RL, C_199_A;
MASSTOR_LIST *SL, *CL, *L;
# endif
{
  MASSTOR_LIST A1, A1S, AB, AS, CLS, EL1, J1Y, L1, LB, LS, P, RLP, SLS;

  if (RL == 1) {
    SACUPFAC_IUPFAC(C_199_A, SL, CL, L);
    return;
  }
  *SL = SACIPOL_IPSIGN(RL, C_199_A);
  AS = SACIPOL_IPABS(RL, C_199_A);
  SACPGCD_IPCPP(RL, AS, &CLS, &AB);
  RLP = RL - 1;
  SACPFAC_IPFAC(RLP, CLS, &SLS, CL, &LS);
  if (SACPOL_PDEG(AB) == 0) {
    LB = MASSTOR_BETA;
  } else {
    LB = SACPGCD_IPSF(RL, AB);
  }
  LB = MASSTOR_INV(LB);
  *L = MASSTOR_BETA;
  while (LB != MASSTOR_SIL) {
    MASSTOR_ADV(LB, &P, &LB);
    SACLIST_FIRST2(P, &EL1, &A1);
    L1 = SACPFAC_ISFPF(RL, A1);
    do {
      MASSTOR_ADV(L1, &A1, &L1);
      J1Y = SACLIST_LIST2(EL1, A1);
      *L = MASSTOR_COMP(J1Y, *L);
    } while (!(L1 == MASSTOR_SIL));
  }
  LS = MASSTOR_INV(LS);
  while (LS != MASSTOR_SIL) {
    MASSTOR_ADV(LS, &P, &LS);
    SACLIST_FIRST2(P, &EL1, &A1S);
    A1 = SACLIST_LIST2(0, A1S);
    J1Y = SACLIST_LIST2(EL1, A1);
    *L = MASSTOR_COMP(J1Y, *L);
  }
  return;
}

MASSTOR_LIST SACPFAC_IPGFCB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_198_A)
# else
(RL, C_198_A)
MASSTOR_LIST RL, C_198_A;
# endif
{
  MASSTOR_LIST AL, HL, J1Y, NL, V;

  AL = SACIPOL_IPSUMN(RL, C_198_A);
  V = SACPOL_PDEGV(RL, C_198_A);
  HL = 0;
  do {
    MASSTOR_ADV(V, &NL, &V);
    J1Y = 2 * NL;
    J1Y = J1Y - 1;
    J1Y = MASELEM_MASMAX(0, J1Y);
    HL = HL + J1Y;
  } while (!(V == MASSTOR_SIL));
  J1Y = HL + 1;
  HL = J1Y / 2;
  AL = SACI_IMP2(AL, HL);
  return AL;
}

void SACPFAC_IPIQH
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST C, MASSTOR_LIST *C_197_A, MASSTOR_LIST *B)
# else
(RL, PL, D, AB, BB, SB, TB, M, C, C_197_A, B)
MASSTOR_LIST RL, PL, D, AB, BB, SB, TB, M, C;
MASSTOR_LIST *C_197_A, *B;
# endif
{
  MASSTOR_LIST AS, AT, BS, BT, CL, I, QL, QLS, QLT, R, RP, S, SS, ST, T, TS, TT, U, U1, UT, Y, Y1, Z, Z1;

  QL = PL;
  *C_197_A = AB;
  *B = BB;
  S = SB;
  T = TB;
  I = SACPOL_PINV(0, 1, RL);
  if (QL == M) {
    return;
  }
  for (;;) {
    R = SACMPOL_MIPIPR(RL, M, D, *C_197_A, *B);
    R = SACIPOL_IPDIF(RL, C, R);
    U = SACIPOL_IPIQ(RL, R, QL);
    QLS = SACI_IPROD(QL, QL);
    CL = SACI_ICOMP(QLS, M);
    if (CL > 0) {
      QLT = SACI_IQ(M, QL);
      AT = SACMPOL_MIPHOM(RL, QLT, *C_197_A);
      BT = SACMPOL_MIPHOM(RL, QLT, *B);
      ST = SACMPOL_MIPHOM(RL, QLT, S);
      TT = SACMPOL_MIPHOM(RL, QLT, T);
    } else {
      QLT = QL;
      AT = *C_197_A;
      BT = *B;
      ST = S;
      TT = T;
    }
    UT = SACMPOL_MIPHOM(RL, QLT, U);
    SACPFAC_MIPISE(RL, QLT, D, AT, BT, ST, TT, UT, &Y, &Z);
    R = SACIPOL_IPIP(RL, QL, Z);
    AS = SACIPOL_IPSUM(RL, *C_197_A, R);
    R = SACIPOL_IPIP(RL, QL, Y);
    BS = SACIPOL_IPSUM(RL, *B, R);
    if (CL >= 0) {
      *C_197_A = AS;
      *B = BS;
      return;
    }
    R = SACMPOL_MIPIPR(RL, QLS, D, AS, S);
    RP = SACMPOL_MIPIPR(RL, QLS, D, BS, T);
    R = SACMPOL_MIPSUM(RL, QLS, R, RP);
    R = SACMPOL_MIPDIF(RL, QLS, R, I);
    U1 = SACIPOL_IPIQ(RL, R, QL);
    SACPFAC_MIPISE(RL, QL, D, *C_197_A, *B, S, T, U1, &Y1, &Z1);
    R = SACIPOL_IPIP(RL, QL, Y1);
    SS = SACMPOL_MIPDIF(RL, QLS, S, R);
    R = SACIPOL_IPIP(RL, QL, Z1);
    TS = SACMPOL_MIPDIF(RL, QLS, T, R);
    QL = QLS;
    *C_197_A = AS;
    *B = BS;
    S = SS;
    T = TS;
  } EXIT_2:;
  return;
}

MASSTOR_LIST SACPFAC_ISFPF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_196_A)
# else
(RL, C_196_A)
MASSTOR_LIST RL, C_196_A;
# endif
{
  MASSTOR_LIST A1P, A1S, ABP, ALP, AP, AS, B, BL, BP, C, D, DL, J1Y, KL, L, LP, LS, M, ML, NL, P, PL, T, TL, TP, V, VL;

  if (RL == 1) {
    L = SACUPFAC_IUSFPF(C_196_A);
    return L;
  }
  SACPFAC_IPCEVP(RL, C_196_A, &AS, &T);
  AS = SACIPOL_IPABS(1, AS);
  AS = SACPGCD_IPPP(1, AS);
  LS = SACUPFAC_IUSFPF(AS);
  if (MASSTOR_RED(LS) == MASSTOR_SIL) {
    L = MASSTOR_LIST1(C_196_A);
    return L;
  }
  J1Y = MASSTOR_INV(T);
  T = MASSTOR_COMP(0, J1Y);
  AP = SACIPOL_IPTRAN(RL, C_196_A, T);
  P = SACPOL_PRIME;
  NL = SACPOL_PDEG(AS);
  do {
    if (P == MASSTOR_SIL) {
      MASBIOS_SWRITE("PRIME LIST EXHAUSTED IN ISFPF", 29L);
    }
    MASSTOR_ADV(P, &PL, &P);
    B = SACMPOL_MPHOM(1, PL, AS);
    ML = SACPOL_PDEG(B);
    if (ML == NL) {
      BP = SACMPOL_MUPDER(PL, B);
      C = SACPGCD_MUPGCD(PL, B, BP);
      KL = SACPOL_PDEG(C);
    }
  } while (!(ML == NL && KL == 0));
  LP = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LS, &A1S, &LS);
    A1P = SACMPOL_MPHOM(1, PL, A1S);
    A1P = SACMPOL_MPMON(1, PL, A1P);
    LP = MASSTOR_COMP(A1P, LP);
  } while (!(LS == MASSTOR_SIL));
  ALP = SACPOL_PLDCF(AP);
  J1Y = SACLIST_LIST2(0, ALP);
  ABP = SACIPOL_IPPROD(RL, AP, J1Y);
  BL = SACPFAC_IPGFCB(RL, ABP);
  BL = SACI_IMP2(BL, 1);
  M = PL;
  while (SACI_ICOMP(M, BL) <= 0) {
    M = SACI_IDPR(M, PL);
  }
  V = SACPOL_PDEGV(RL, ABP);
  D = MASSTOR_BETA;
  V = MASSTOR_RED(V);
  do {
    MASSTOR_ADV(V, &VL, &V);
    DL = VL + 1;
    D = MASSTOR_COMP(DL, D);
  } while (!(V == MASSTOR_SIL));
  L = SACPFAC_MPIQHL(RL, PL, LP, M, D, AP);
  LP = SACUPFAC_IPFLC(RL, M, D, AP, L, 0);
  TP = MASSTOR_BETA;
  do {
    MASSTOR_ADV(T, &TL, &T);
    J1Y = SACI_INEG(TL);
    TP = MASSTOR_COMP(J1Y, TP);
  } while (!(T == MASSTOR_SIL));
  TP = MASSTOR_INV(TP);
  L = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LP, &A1P, &LP);
    J1Y = SACIPOL_IPTRAN(RL, A1P, TP);
    L = MASSTOR_COMP(J1Y, L);
  } while (!(LP == MASSTOR_SIL));
  return L;
}

void SACPFAC_MIPISE
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C_195_A, MASSTOR_LIST B, MASSTOR_LIST S, MASSTOR_LIST T, MASSTOR_LIST C, MASSTOR_LIST *U, MASSTOR_LIST *V)
# else
(RL, M, D, C_195_A, B, S, T, C, U, V)
MASSTOR_LIST RL, M, D, C_195_A, B, S, T, C;
MASSTOR_LIST *U, *V;
# endif
{
  MASSTOR_LIST Q, W, Y, Z;

  W = SACMPOL_MIPIPR(RL, M, D, T, C);
  SACMPOL_MMPIQR(RL, M, D, W, C_195_A, &Q, V);
  Y = SACMPOL_MIPIPR(RL, M, D, S, C);
  Z = SACMPOL_MIPIPR(RL, M, D, B, Q);
  *U = SACMPOL_MIPSUM(RL, M, Y, Z);
  return;
}

void SACPFAC_MPIQH
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST DP, MASSTOR_LIST C, MASSTOR_LIST *C_194_A, MASSTOR_LIST *B)
# else
(RL, PL, D, AB, BB, SB, TB, M, DP, C, C_194_A, B)
MASSTOR_LIST RL, PL, D, AB, BB, SB, TB, M, DP, C;
MASSTOR_LIST *C_194_A, *B;
# endif
{
  MASSTOR_LIST AS, BS, CB, DH, DL, DPP, DS, IL, S, SS, T, TS;

  DH = D;
  *C_194_A = AB;
  *B = BB;
  S = SB;
  T = TB;
  DPP = SACLIST_CINV(DP);
  IL = RL - 1;
  CB = SACMPOL_MPHOM(RL, PL, C);
  while (IL > 0) {
    MASSTOR_ADV(DPP, &DL, &DPP);
    SACPFAC_MPIQHS(RL, PL, DH, *C_194_A, *B, S, T, IL, DL, CB, &AS, &BS, &SS, &TS, &DS);
    *C_194_A = AS;
    *B = BS;
    S = SS;
    T = TS;
    DH = DS;
    IL = IL - 1;
  }
  SACPFAC_IPIQH(RL, PL, DP, AS, BS, S, T, M, C, C_194_A, B);
  return;
}

MASSTOR_LIST SACPFAC_MPIQHL
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST F, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C)
# else
(RL, PL, F, M, D, C)
MASSTOR_LIST RL, PL, F, M, D, C;
# endif
{
  MASSTOR_LIST C_193_A, AB, B, BB, CB, CP, DP, FP, FS, IL, R, RLP, SB, TB;

  FP = MASSTOR_BETA;
  FS = F;
  CP = SACIPOL_IPIHOM(RL, D, C);
  CP = SACMPOL_MIPHOM(RL, M, CP);
  B = CP;
  RLP = RL - 1;
  DP = MASSTOR_BETA;
  {
    LONGINT B_1 = 1, B_2 = RLP;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        DP = MASSTOR_COMP(1, DP);
        if (IL >= B_2) break;
      }
  }
  while (FS != MASSTOR_SIL) {
    MASSTOR_ADV(FS, &AB, &FS);
    CB = SACPOL_PUFP(RL, CP);
    CB = SACMPOL_MIPHOM(1, PL, CB);
    BB = SACMPOL_MPQ(1, PL, CB, AB);
    SACPGCD_MUPEGC(PL, AB, BB, &R, &SB, &TB);
    AB = SACPOL_PINV(1, AB, RLP);
    BB = SACPOL_PINV(1, BB, RLP);
    SB = SACPOL_PINV(1, SB, RLP);
    TB = SACPOL_PINV(1, TB, RLP);
    SACPFAC_MPIQH(RL, PL, DP, AB, BB, SB, TB, M, D, CP, &C_193_A, &B);
    FP = MASSTOR_COMP(C_193_A, FP);
    if (FS != MASSTOR_SIL) {
      SACMPOL_MMPIQR(RL, M, D, CP, C_193_A, &CP, &R);
    }
  }
  FP = MASSTOR_INV(FP);
  return FP;
}

void SACPFAC_MPIQHS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST SL, MASSTOR_LIST NL, MASSTOR_LIST C, MASSTOR_LIST *C_192_A, MASSTOR_LIST *B, MASSTOR_LIST *S, MASSTOR_LIST *T, MASSTOR_LIST *DP)
# else
(RL, M, D, AB, BB, SB, TB, SL, NL, C, C_192_A, B, S, T, DP)
MASSTOR_LIST RL, M, D, AB, BB, SB, TB, SL, NL, C;
MASSTOR_LIST *C_192_A, *B, *S, *T, *DP;
# endif
{
  MASSTOR_LIST AS, BS, DB, DH, DL, DS, DT, I, IL, J1Y, SS, TS, U, U1, V, VP, VPP, Y, Y1, YB, Z, Z1, ZB;

  *C_192_A = AB;
  *B = BB;
  *S = SB;
  *T = TB;
  I = SACLIST_LIST2(0, 1);
  J1Y = RL - 1;
  I = SACPOL_PINV(1, I, J1Y);
  DB = D;
  DS = D;
  DH = MASSTOR_BETA;
  {
    LONGINT B_3 = 1, B_4 = SL - 1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        MASSTOR_ADV(DS, &DL, &DS);
        DH = MASSTOR_COMP(DL, DH);
        if (IL >= B_4) break;
      }
  }
  MASSTOR_ADV(DS, &DL, &DS);
  DT = MASSTOR_COMP(NL, DS);
  *DP = SACLIST_CINV(DH);
  *DP = SACLIST_CONC(*DP, DT);
  for (;;) {
    if (DL > NL) {
      *C_192_A = SACIPOL_IPIHOM(RL, *DP, *C_192_A);
      *B = SACIPOL_IPIHOM(RL, *DP, *B);
      *S = SACIPOL_IPIHOM(RL, *DP, *S);
      *T = SACIPOL_IPIHOM(RL, *DP, *T);
    }
    if (DL >= NL) {
      return;
    }
    V = SACMPOL_MIPIPR(RL, M, *DP, *C_192_A, *B);
    VP = SACMPOL_MIPDIF(RL, M, C, V);
    U = SACPOL_PDPV(RL, VP, SL, DL);
    SACPFAC_MIPISE(RL, M, DB, *C_192_A, *B, *S, *T, U, &Y, &Z);
    J1Y = -DL;
    YB = SACPOL_PDPV(RL, Y, SL, J1Y);
    J1Y = -DL;
    ZB = SACPOL_PDPV(RL, Z, SL, J1Y);
    AS = SACMPOL_MIPSUM(RL, M, *C_192_A, ZB);
    BS = SACMPOL_MIPSUM(RL, M, *B, YB);
    V = SACMPOL_MIPIPR(RL, M, *DP, AS, *S);
    VP = SACMPOL_MIPIPR(RL, M, *DP, BS, *T);
    VPP = SACMPOL_MIPSUM(RL, M, V, VP);
    V = SACMPOL_MIPDIF(RL, M, VPP, I);
    U1 = SACPOL_PDPV(RL, V, SL, DL);
    SACPFAC_MIPISE(RL, M, DB, *C_192_A, *B, *S, *T, U1, &Y1, &Z1);
    J1Y = -DL;
    YB = SACPOL_PDPV(RL, Y1, SL, J1Y);
    J1Y = -DL;
    ZB = SACPOL_PDPV(RL, Z1, SL, J1Y);
    SS = SACMPOL_MIPDIF(RL, M, *S, YB);
    TS = SACMPOL_MIPDIF(RL, M, *T, ZB);
    DL = DL + DL;
    DT = MASSTOR_COMP(DL, DS);
    DB = SACLIST_CINV(DH);
    DB = SACLIST_CONC(DB, DT);
    *C_192_A = AS;
    *B = BS;
    *S = SS;
    *T = TS;
  } EXIT_3:;
  return;
}

void BEGIN_SACPFAC()
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
    BEGIN_SACM();
    BEGIN_SACPRIM();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();
    BEGIN_SACDPOL();
    BEGIN_SACPGCD();
    BEGIN_SACUPFAC();

  }
}
