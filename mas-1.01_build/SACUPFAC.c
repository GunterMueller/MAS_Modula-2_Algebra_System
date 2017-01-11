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

#ifndef DEFINITION_SACMUFAC
#include "SACMUFAC.h"
#endif

#ifndef DEFINITION_SACUPFAC
#include "SACUPFAC.h"
#endif

CHAR SACUPFAC_rcsid [] = "$Id: SACUPFAC.md,v 1.2 1992/02/12 17:35:06 pesch Exp $";
CHAR SACUPFAC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static MASSTOR_LIST NPFDS;
static CHAR rcsidi [] = "$Id: SACUPFAC.mi,v 1.3 1992/10/15 16:29:08 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void BEGIN4 ARGS(());


static void BEGIN4
# ifdef __STDC__
()
# else
()
# endif
{
  NPFDS = 10;
  return;
}

MASSTOR_LIST SACUPFAC_IPFLC
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST C_193_A, MASSTOR_LIST L, MASSTOR_LIST D)
# else
(RL, M, I, C_193_A, L, D)
MASSTOR_LIST RL, M, I, C_193_A, L, D;
# endif
{
  MASSTOR_LIST ALS, AS, BS, C, CL, CLB, CLS, CS, DL, DLS, IL, J1Y, KL, LB, LP, LS, P, PL, RLP, RS, S, SL, SS, XL;

  DL = 1;
  C = C_193_A;
  KL = MASSTOR_LENGTH(L);
  P = SACCOMB_PERMR(KL);
  LB = SACCOMB_LPERM(L, P);
  LP = MASSTOR_BETA;
  RLP = RL - 1;
  for (;;) {
    CL = SACPOL_PLDCF(C);
    CLS = SACPOL_PTBCF(RLP, CL);
    CL = SACLIST_LIST2(0, CL);
    CS = SACIPOL_IPPROD(RL, CL, C);
    CLB = SACPOL_PTBCF(RL, CS);
    CLS = SACM_MIHOM(M, CLS);
    for (;;) {
      if (DL > KL / 2) {
        LP = MASSTOR_COMP(C, LP);
        return LP;
      }
      LS = LB;
      S = MASSTOR_BETA;
      {
        LONGINT B_1 = 1, B_2 = DL;

        if (B_1 <= B_2)
          for (IL = B_1;; IL += 1) {
            S = MASSTOR_COMP(LS, S);
            LS = MASSTOR_RED(LS);
            if (IL >= B_2) break;
          }
      }
      do {
        SS = S;
        ALS = CLS;
        DLS = 0;
        while (SS != MASSTOR_SIL) {
          MASSTOR_ADV(SS, &SL, &SS);
          PL = MASSTOR_FIRST(SL);
          J1Y = SACPOL_PDEG(PL);
          DLS = DLS + J1Y;
          J1Y = SACPOL_PTBCF(RL, PL);
          ALS = SACM_MIPROD(M, ALS, J1Y);
        }
        ALS = SACM_SMFMI(M, ALS);
        if (!(ALS == 0 && CLB != 0)) {
          if ((D == 0 || SACI_IODD(SACI_IDP2(D, DLS))) && (CLB == 0 || SACI_IREM(CLB, ALS) == 0)) {
            SS = S;
            AS = CL;
            while (SS != MASSTOR_SIL) {
              MASSTOR_ADV(SS, &SL, &SS);
              PL = MASSTOR_FIRST(SL);
              AS = SACMPOL_MIPIPR(RL, M, I, AS, PL);
            }
            AS = SACMPOL_SMFMIP(RL, M, AS);
            SACIPOL_IPQR(RL, CS, AS, &BS, &RS);
            if (RS == 0) {
              goto EXIT_2;
            }
          }
        }
        S = SACCOMB_LEXNEX(S);
      } while (!(S == MASSTOR_SIL));
      DL = DL + 1;
    } EXIT_2:;
    AS = SACPGCD_IPPP(RL, AS);
    LP = MASSTOR_COMP(AS, LP);
    J1Y = SACPOL_PLDCF(AS);
    J1Y = SACLIST_LIST2(0, J1Y);
    C = SACIPOL_IPQ(RL, BS, J1Y);
    KL = KL - DL;
    do {
      MASSTOR_ADV(S, &SL, &S);
      if (SL == LB) {
        LB = MASSTOR_RED(LB);
      } else {
        XL = MASSTOR_RED(SL);
        LB = MASSTOR_INV(LB);
        SL = MASSTOR_RED(SL);
        LB = MASSTOR_INV(LB);
        MASSTOR_SRED(SL, XL);
      }
    } while (!(S == MASSTOR_SIL));
  } EXIT_1:;
  return LP;
}

void SACUPFAC_IUPFAC
# ifdef __STDC__
(MASSTOR_LIST C_192_A, MASSTOR_LIST *SL, MASSTOR_LIST *CL, MASSTOR_LIST *L)
# else
(C_192_A, SL, CL, L)
MASSTOR_LIST C_192_A;
MASSTOR_LIST *SL, *CL, *L;
# endif
{
  MASSTOR_LIST A1, AB, EL1, J1Y, L1, P, S;

  SACPGCD_IPSCPP(1, C_192_A, SL, CL, &AB);
  if (SACPOL_PDEG(C_192_A) == 0) {
    *L = MASSTOR_BETA;
    return;
  }
  S = SACPGCD_IPSF(1, AB);
  S = MASSTOR_INV(S);
  *L = MASSTOR_BETA;
  do {
    MASSTOR_ADV(S, &P, &S);
    SACLIST_FIRST2(P, &EL1, &A1);
    L1 = SACUPFAC_IUSFPF(A1);
    do {
      MASSTOR_ADV(L1, &A1, &L1);
      J1Y = SACLIST_LIST2(EL1, A1);
      *L = MASSTOR_COMP(J1Y, *L);
    } while (!(L1 == MASSTOR_SIL));
  } while (!(S == MASSTOR_SIL));
  return;
}

void SACUPFAC_IUPFDS
# ifdef __STDC__
(MASSTOR_LIST C_191_A, MASSTOR_LIST *PL, MASSTOR_LIST *F, MASSTOR_LIST *C)
# else
(C_191_A, PL, F, C)
MASSTOR_LIST C_191_A;
MASSTOR_LIST *PL, *F, *C;
# endif
{
  MASSTOR_LIST AL, B, BL, BP, CL, D, FL, G, H, HL, I, IL, J, J1Y, JL, KL, L, NL, P, RL, SL;

  *PL = 0;
  P = SACPRIM_SMPRM;
  NL = SACPOL_PDEG(C_191_A);
  AL = SACPOL_PLDCF(C_191_A);
  IL = 0;
  J = SACLIST_LIST2(0, 1);
  J1Y = SACI_IMP2(1, NL);
  I = SACCOMB_CSUN(J1Y, 1);
  NL = NL + 1;
  J1Y = SACI_IMP2(1, NL);
  *C = SACI_IDIF(J1Y, 1);
  while (SACLIST_EQUAL(*C, I) == 0 && IL < NPFDS) {
    if (P == MASSTOR_SIL) {
      if (*PL != 0) {
        return;
      }
      MASERR_ERROR(MASERR_fatal, "prime list exhausted in IUPFDS.", 31L);
      return;
    }
    MASSTOR_ADV(P, &RL, &P);
    if (SACI_IDREM(AL, RL) != 0) {
      B = SACMPOL_MPHOM(1, RL, C_191_A);
      BP = SACMPOL_MUPDER(RL, B);
      if (SACLIST_EQUAL(SACPGCD_MUPGCD(RL, B, BP), J) == 1) {
        BP = SACMPOL_MPMON(1, RL, B);
        G = SACMUFAC_MUPDDF(RL, BP);
        H = G;
        L = MASSTOR_BETA;
        KL = 0;
        do {
          MASSTOR_ADV(H, &HL, &H);
          SACLIST_FIRST2(HL, &FL, &BL);
          CL = SACPOL_PDEG(BL);
          JL = CL / FL;
          KL = KL + JL;
          {
            LONGINT B_3 = 1, B_4 = JL;

            if (B_3 <= B_4)
              for (SL = B_3;; SL += 1) {
                L = MASSTOR_COMP(FL, L);
                if (SL >= B_4) break;
              }
          }
        } while (!(H == MASSTOR_SIL));
        if (KL < NL) {
          *PL = RL;
          NL = KL;
          *F = G;
        }
        D = SACCOMB_CSFPAR(L);
        *C = SACCOMB_CSINT(*C, D);
        IL = IL + 1;
      }
    }
  }
  if (SACLIST_EQUAL(*C, I) == 1) {
    *PL = 0;
    *F = MASSTOR_BETA;
  }
  return;
}

void SACUPFAC_IUPQH
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST AB, MASSTOR_LIST BB, MASSTOR_LIST SB, MASSTOR_LIST TB, MASSTOR_LIST M, MASSTOR_LIST C, MASSTOR_LIST *C_190_A, MASSTOR_LIST *B)
# else
(PL, AB, BB, SB, TB, M, C, C_190_A, B)
MASSTOR_LIST PL, AB, BB, SB, TB, M, C;
MASSTOR_LIST *C_190_A, *B;
# endif
{
  MASSTOR_LIST AS, AT, BS, BT, CL, I, QL, QLS, QLT, R, RP, S, SS, ST, T, TS, TT, U, U1, Y, Y1, Z, Z1;

  QL = PL;
  *C_190_A = AB;
  *B = BB;
  S = SB;
  T = TB;
  I = SACLIST_LIST2(0, 1);
  if (QL == M) {
    return;
  }
  for (;;) {
    R = SACIPOL_IPPROD(1, *C_190_A, *B);
    R = SACIPOL_IPDIF(1, C, R);
    U = SACIPOL_IPIQ(1, R, QL);
    QLS = SACI_IPROD(QL, QL);
    CL = SACI_ICOMP(QLS, M);
    if (CL > 0) {
      QLT = SACI_IQ(M, QL);
      AT = SACMPOL_MIPHOM(1, QLT, *C_190_A);
      BT = SACMPOL_MIPHOM(1, QLT, *B);
      ST = SACMPOL_MIPHOM(1, QLT, S);
      TT = SACMPOL_MIPHOM(1, QLT, T);
    } else {
      QLT = QL;
      AT = *C_190_A;
      BT = *B;
      ST = S;
      TT = T;
    }
    SACMUFAC_MIUPSE(QLT, AT, BT, ST, TT, U, &Y, &Z);
    R = SACIPOL_IPIP(1, QL, Z);
    AS = SACIPOL_IPSUM(1, *C_190_A, R);
    R = SACIPOL_IPIP(1, QL, Y);
    BS = SACIPOL_IPSUM(1, *B, R);
    if (CL >= 0) {
      *C_190_A = AS;
      *B = BS;
      return;
    }
    R = SACIPOL_IPPROD(1, AS, S);
    RP = SACIPOL_IPPROD(1, BS, T);
    R = SACIPOL_IPSUM(1, R, RP);
    R = SACIPOL_IPDIF(1, R, I);
    U1 = SACIPOL_IPIQ(1, R, QL);
    SACMUFAC_MIUPSE(QL, *C_190_A, *B, S, T, U1, &Y1, &Z1);
    R = SACIPOL_IPIP(1, QL, Y1);
    SS = SACMPOL_MIPDIF(1, QLS, S, R);
    R = SACIPOL_IPIP(1, QL, Z1);
    TS = SACMPOL_MIPDIF(1, QLS, T, R);
    QL = QLS;
    *C_190_A = AS;
    *B = BS;
    S = SS;
    T = TS;
  } EXIT_3:;
  return;
}

MASSTOR_LIST SACUPFAC_IUPQHL
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST F, MASSTOR_LIST M, MASSTOR_LIST C)
# else
(PL, F, M, C)
MASSTOR_LIST PL, F, M, C;
# endif
{
  MASSTOR_LIST C_189_A, AB, B, BB, CB, CP, FP, FS, Q, R, SB, TB;

  FP = MASSTOR_BETA;
  FS = F;
  CP = SACMPOL_MIPHOM(1, M, C);
  B = CP;
  while (MASSTOR_RED(FS) != MASSTOR_SIL) {
    MASSTOR_ADV(FS, &AB, &FS);
    CB = SACMPOL_MIPHOM(1, PL, CP);
    BB = SACMPOL_MPQ(1, PL, CB, AB);
    SACPGCD_MUPEGC(PL, AB, BB, &R, &SB, &TB);
    SACUPFAC_IUPQH(PL, AB, BB, SB, TB, M, CP, &C_189_A, &B);
    FP = MASSTOR_COMP(C_189_A, FP);
    if (MASSTOR_RED(FS) != MASSTOR_SIL) {
      SACMPOL_MIUPQR(M, CP, C_189_A, &CP, &R);
    }
  }
  SACMPOL_MIUPQR(M, B, SACLIST_LIST2(0, SACPOL_PLDCF(B)), &Q, &R);
  FP = MASSTOR_COMP(Q, FP);
  FP = MASSTOR_INV(FP);
  return FP;
}

MASSTOR_LIST SACUPFAC_IUSFPF
# ifdef __STDC__
(MASSTOR_LIST C_188_A)
# else
(C_188_A)
MASSTOR_LIST C_188_A;
# endif
{
  MASSTOR_LIST A1, AL, BL, C, F, G, G1, GS, HL, L, M, ML1, NL, NL1, P, PL;

  SACUPFAC_IUPFDS(C_188_A, &PL, &F, &C);
  if (PL == 0) {
    L = MASSTOR_LIST1(C_188_A);
    return L;
  }
  G = MASSTOR_BETA;
  do {
    MASSTOR_ADV(F, &P, &F);
    SACLIST_FIRST2(P, &NL1, &A1);
    ML1 = SACPOL_PDEG(A1);
    if (NL1 == ML1) {
      G = MASSTOR_COMP(A1, G);
    } else {
      G1 = SACMUFAC_MUPFBL(PL, A1);
      G = SACLIST_CONC(G1, G);
    }
  } while (!(F == MASSTOR_SIL));
  AL = SACPOL_PLDCF(C_188_A);
  HL = SACIPOL_IPSUMN(1, C_188_A);
  NL = SACPOL_PDEG(C_188_A);
  BL = SACI_IPROD(AL, HL);
  BL = SACI_IMP2(BL, NL);
  M = PL;
  while (SACI_ICOMP(M, BL) <= 0) {
    M = SACI_IDPR(M, PL);
  }
  GS = SACUPFAC_IUPQHL(PL, G, M, C_188_A);
  L = SACUPFAC_IPFLC(1, M, MASSTOR_BETA, C_188_A, GS, C);
  return L;
}

void BEGIN_SACUPFAC()
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
    BEGIN_SACPRIM();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();
    BEGIN_SACDPOL();
    BEGIN_SACPGCD();
    BEGIN_SACMUFAC();

    BEGIN4();
  }
}
