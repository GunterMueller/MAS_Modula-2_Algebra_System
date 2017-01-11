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

#ifndef DEFINITION_SACLDIO
#include "SACLDIO.h"
#endif

#ifndef DEFINITION_SACMUFAC
#include "SACMUFAC.h"
#endif

CHAR SACMUFAC_rcsid [] = "$Id: SACMUFAC.md,v 1.2 1992/02/12 17:34:58 pesch Exp $";
CHAR SACMUFAC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACMUFAC.mi,v 1.3 1992/10/15 16:29:02 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACMUFAC_MCPMV
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST L)
# else
(NL, L)
MASSTOR_LIST NL, L;
# endif
{
  MASSTOR_LIST IL, KL, LP, LP1, LS, M, MP, MS;

  LP = L;
  MP = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LP, &LS, &LP);
    LP1 = SACDPOL_DPFP(1, LS);
    MASSTOR_ADV(LP1, &KL, &LP1);
    {
      LONGINT B_1 = 1, B_2 = NL - KL - 1;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          LP1 = MASSTOR_COMP(0, LP1);
          if (IL >= B_2) break;
        }
    }
    MP = MASSTOR_COMP(LP1, MP);
  } while (!(LP == MASSTOR_SIL));
  M = MASSTOR_BETA;
  do {
    MS = MP;
    LP = MASSTOR_BETA;
    do {
      LS = MASSTOR_FIRST(MS);
      MASSTOR_SFIRST(MS, MASSTOR_RED(LS));
      MASSTOR_SRED(LS, LP);
      LP = LS;
      MS = MASSTOR_RED(MS);
    } while (!(MS == MASSTOR_SIL));
    M = MASSTOR_COMP(LP, M);
  } while (!(MASSTOR_FIRST(MP) == MASSTOR_SIL));
  return M;
}

void SACMUFAC_MIUPSE
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_203_A, MASSTOR_LIST B, MASSTOR_LIST S, MASSTOR_LIST T, MASSTOR_LIST C, MASSTOR_LIST *U, MASSTOR_LIST *V)
# else
(M, C_203_A, B, S, T, C, U, V)
MASSTOR_LIST M, C_203_A, B, S, T, C;
MASSTOR_LIST *U, *V;
# endif
{
  MASSTOR_LIST HL, J, J1Y, K, KL, L, ML, NL, Q, Y;

  NL = SACPOL_PDEG(C);
  HL = SACPOL_PDEG(C_203_A);
  KL = SACPOL_PDEG(B);
  J1Y = NL - HL;
  J1Y = J1Y + 1;
  ML = MASELEM_MASMAX(J1Y, KL);
  Y = SACMPOL_MIPPR(1, M, T, C);
  SACMPOL_MIUPQR(M, Y, C_203_A, &Q, V);
  J = SACIPOL_IUPTPR(ML, S, C);
  K = SACIPOL_IUPTPR(ML, B, Q);
  L = SACIPOL_IPSUM(1, J, K);
  *U = SACMPOL_MIPHOM(1, M, L);
  return;
}

MASSTOR_LIST SACMUFAC_MUPBQP
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_202_A)
# else
(PL, C_202_A)
MASSTOR_LIST PL, C_202_A;
# endif
{
  MASSTOR_LIST AP, B, C, IL, J1Y, KL, ML, NL, Q, X;

  KL = 2;
  while (KL <= PL) {
    KL = KL + KL;
  }
  KL = KL / 2;
  NL = MASSTOR_FIRST(C_202_A);
  AP = SACDPOL_DPFP(1, C_202_A);
  C = SACLIST_LIST2(0, 1);
  Q = MASSTOR_LIST1(C);
  X = SACLIST_LIST3(1, 1, 0);
  B = X;
  ML = PL - KL;
  do {
    B = SACDPOL_DMPPRD(1, PL, B, B);
    if (MASSTOR_FIRST(B) >= NL) {
      B = SACDPOL_DMUPNR(PL, B, AP);
    }
    KL = KL / 2;
    if (ML >= KL) {
      B = SACDPOL_DMPPRD(1, PL, X, B);
      if (MASSTOR_FIRST(B) >= NL) {
        B = SACDPOL_DMUPNR(PL, B, AP);
      }
      ML = ML - KL;
    }
  } while (!(KL == 1));
  J1Y = SACPOL_PFDP(1, B);
  Q = MASSTOR_COMP(J1Y, Q);
  C = B;
  {
    LONGINT B_3 = 2, B_4 = NL - 1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        C = SACDPOL_DMPPRD(1, PL, B, C);
        if (MASSTOR_FIRST(C) >= NL) {
          C = SACDPOL_DMUPNR(PL, C, AP);
        }
        J1Y = SACPOL_PFDP(1, C);
        Q = MASSTOR_COMP(J1Y, Q);
        if (IL >= B_4) break;
      }
  }
  Q = MASSTOR_INV(Q);
  return Q;
}

MASSTOR_LIST SACMUFAC_MUPDDF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_201_A)
# else
(PL, C_201_A)
MASSTOR_LIST PL, C_201_A;
# endif
{
  MASSTOR_LIST B, BL, BP, C, D, EL, IL, J1Y, KL, L, L1, NL, Q, Q1, QP, W, X;

  Q = SACMUFAC_MUPBQP(PL, C_201_A);
  J1Y = MASSTOR_RED(Q);
  B = MASSTOR_FIRST(J1Y);
  C = C_201_A;
  L = MASSTOR_BETA;
  KL = 1;
  X = SACLIST_LIST2(1, 1);
  NL = MASSTOR_FIRST(C_201_A);
  for (;;) {
    W = SACMPOL_MPDIF(1, PL, B, X);
    D = SACPGCD_MUPGCD(PL, W, C);
    if (MASSTOR_FIRST(D) > 0) {
      L1 = SACLIST_LIST2(KL, D);
      L = MASSTOR_COMP(L1, L);
      C = SACMPOL_MPQ(1, PL, C, D);
    }
    KL = KL + 1;
    EL = MASSTOR_FIRST(C);
    if (EL >= 2 * KL) {
      if (KL == 2) {
        Q = SACMUFAC_MCPMV(NL, Q);
      }
      B = SACDPOL_DPFP(1, B);
      MASSTOR_ADV(B, &EL, &B);
      {
        LONGINT B_5 = 1, B_6 = NL - EL - 1;

        if (B_5 <= B_6)
          for (IL = B_5;; IL += 1) {
            B = MASSTOR_COMP(0, B);
            if (IL >= B_6) break;
          }
      }
      BP = MASSTOR_INV(B);
      B = MASSTOR_BETA;
      QP = Q;
      do {
        MASSTOR_ADV(QP, &Q1, &QP);
        BL = SACMPOL_VMPIP(0, PL, BP, Q1);
        B = MASSTOR_COMP(BL, B);
      } while (!(QP == MASSTOR_SIL));
      EL = NL - 1;
      while (MASSTOR_FIRST(B) == 0) {
        EL = EL - 1;
        B = MASSTOR_RED(B);
      }
      B = MASSTOR_COMP(EL, B);
      B = SACPOL_PFDP(1, B);
    } else {
      if (EL > 0) {
        L1 = SACLIST_LIST2(EL, C);
        L = MASSTOR_COMP(L1, L);
      }
      L = MASSTOR_INV(L);
      return L;
    }
  } EXIT_1:;
  return L;
}

MASSTOR_LIST SACMUFAC_MUPFBL
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_200_A)
# else
(PL, C_200_A)
MASSTOR_LIST PL, C_200_A;
# endif
{
  MASSTOR_LIST AL, B, B1, BS, IL, JL, L, NL, Q, Q1, QP;

  NL = MASSTOR_FIRST(C_200_A);
  Q = SACMUFAC_MUPBQP(PL, C_200_A);
  Q = SACMUFAC_MCPMV(NL, Q);
  QP = Q;
  {
    LONGINT B_7 = 0, B_8 = NL - 1;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        Q1 = MASSTOR_FIRST(QP);
        {
          LONGINT B_9 = 1, B_10 = IL;

          if (B_9 <= B_10)
            for (JL = B_9;; JL += 1) {
              Q1 = MASSTOR_RED(Q1);
              if (JL >= B_10) break;
            }
        }
        AL = MASSTOR_FIRST(Q1);
        AL = SACM_MDDIF(PL, AL, 1);
        MASSTOR_SFIRST(Q1, AL);
        QP = MASSTOR_RED(QP);
        if (IL >= B_8) break;
      }
  }
  BS = SACLDIO_MMDNSB(PL, Q);
  B = MASSTOR_BETA;
  do {
    MASSTOR_ADV(BS, &B1, &BS);
    B1 = MASSTOR_INV(B1);
    IL = NL - 1;
    while (MASSTOR_FIRST(B1) == 0) {
      IL = IL - 1;
      B1 = MASSTOR_RED(B1);
    }
    B1 = MASSTOR_COMP(IL, B1);
    B1 = SACPOL_PFDP(1, B1);
    B = MASSTOR_COMP(B1, B);
  } while (!(BS == MASSTOR_SIL));
  L = SACMUFAC_MUPFS(PL, C_200_A, B, 1);
  return L;
}

MASSTOR_LIST SACMUFAC_MUPFS
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_199_A, MASSTOR_LIST B, MASSTOR_LIST DL)
# else
(PL, C_199_A, B, DL)
MASSTOR_LIST PL, C_199_A, B, DL;
# endif
{
  MASSTOR_LIST A1, B1, BP, C, CL, EL, FL, IL, KL, L, LP, RL, SL;

  L = MASSTOR_LIST1(C_199_A);
  RL = MASSTOR_LENGTH(B);
  if (RL == 1) {
    return L;
  }
  BP = MASSTOR_RED(B);
  KL = 1;
  CL = SACLIST_LIST2(0, 1);
  for (;;) {
    LP = MASSTOR_BETA;
    MASSTOR_ADV(BP, &B1, &BP);
    do {
      MASSTOR_ADV(L, &A1, &L);
      EL = MASSTOR_FIRST(A1);
      if (EL > DL) {
        SL = 0;
        IL = 0;
        do {
          C = SACPGCD_MUPGCD(PL, A1, B1);
          FL = MASSTOR_FIRST(C);
          if (FL > 0) {
            if (FL == EL) {
              SL = 1;
            } else {
              LP = MASSTOR_COMP(C, LP);
              A1 = SACMPOL_MPQ(1, PL, A1, C);
              KL = KL + 1;
              if (KL == RL) {
                LP = MASSTOR_COMP(A1, LP);
                L = SACLIST_CONC(LP, L);
                return L;
              }
              EL = MASSTOR_FIRST(A1);
              if (EL == DL) {
                SL = 1;
              }
            }
          }
          B1 = SACMPOL_MPSUM(1, PL, CL, B1);
          IL = IL + 1;
        } while (!(IL == PL || SL == 1));
      }
      LP = MASSTOR_COMP(A1, LP);
    } while (!(L == MASSTOR_SIL));
    L = LP;
  } EXIT_2:;
  return L;
}

void BEGIN_SACMUFAC()
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
    BEGIN_SACLDIO();

  }
}
