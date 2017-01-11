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

#ifndef DEFINITION_SACD
#include "SACD.h"
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

#ifndef DEFINITION_SACLDIO
#include "SACLDIO.h"
#endif

CHAR SACLDIO_rcsid [] = "$Id: SACLDIO.md,v 1.2 1992/02/12 17:33:12 pesch Exp $";
CHAR SACLDIO_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACLDIO.mi,v 1.3 1992/10/15 16:29:18 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SACLDIO_LDSMKB
# ifdef __STDC__
(MASSTOR_LIST C_176_A, MASSTOR_LIST BL, MASSTOR_LIST *XLS, MASSTOR_LIST *N)
# else
(C_176_A, BL, XLS, N)
MASSTOR_LIST C_176_A, BL;
MASSTOR_LIST *XLS, *N;
# endif
{
  MASSTOR_LIST B, C, C1, CL, CP, CP1, CS, CS1, HL, IL, J1Y, JL, KL, ML, NL, R, RL, RP, T;

  NL = MASSTOR_LENGTH(C_176_A);
  C = SACLDIO_MIAIM(C_176_A);
  J1Y = SACLDIO_VINEG(BL);
  B = SACLDIO_VIAZ(J1Y, NL);
  ML = MASSTOR_LENGTH(BL);
  C1 = MASSTOR_FIRST(C);
  JL = 0;
  do {
    JL = JL + 1;
    MASSTOR_ADV(C1, &CL, &C1);
  } while (!(CL != 0));
  R = MASSTOR_LIST1(JL);
  if (JL <= ML) {
    RL = 1;
  } else {
    RL = 0;
  }
  KL = 1;
  while (KL < NL) {
    CS = SACLIST_REDUCT(C, KL);
    CS1 = MASSTOR_FIRST(CS);
    CP = C;
    RP = R;
    for (;;) {
      {
        LONGINT B_1 = 1, B_2 = KL + 1;

        if (B_1 <= B_2)
          for (HL = B_1;; HL += 1) {
            if (HL <= KL) {
              MASSTOR_ADV(RP, &IL, &RP);
            } else {
              J1Y = ML + NL;
              IL = J1Y + 1;
            }
            CP1 = CS1;
            JL = 0;
            do {
              JL = JL + 1;
              MASSTOR_ADV(CP1, &CL, &CP1);
            } while (!(CL != 0));
            if (JL >= IL) {
              if (JL == IL) {
                C1 = MASSTOR_FIRST(CP);
                SACLDIO_VIUT(C1, CS1, IL, &C1, &CS1);
                MASSTOR_SFIRST(CP, C1);
              }
              CP = MASSTOR_RED(CP);
            } else {
              MASSTOR_SFIRST(CS, CS1);
              J1Y = KL + 1;
              C = SACLIST_LEROT(C, HL, J1Y);
              J1Y = HL - 1;
              R = SACLIST_LEINST(R, J1Y, JL);
              if (JL <= ML) {
                RL = RL + 1;
              }
              goto EXIT_1;
            }
            if (HL >= B_2) break;
          }
      }
      goto EXIT_1;
    } EXIT_1:;
    for (JL = HL; JL >= 1; JL += -1) {
      J1Y = JL - 1;
      CS = SACLIST_REDUCT(C, J1Y);
      MASSTOR_ADV(CS, &T, &CP);
      RP = SACLIST_REDUCT(R, JL);
      while (RP != MASSTOR_SIL) {
        MASSTOR_ADV(CP, &CP1, &CP);
        MASSTOR_ADV(RP, &IL, &RP);
        T = SACLDIO_VIERED(T, CP1, IL);
      }
      MASSTOR_SFIRST(CS, T);
    }
    KL = KL + 1;
  }
  {
    LONGINT B_3 = 1, B_4 = RL;

    if (B_3 <= B_4)
      for (JL = B_3;; JL += 1) {
        MASSTOR_ADV(C, &T, &C);
        MASSTOR_ADV(R, &IL, &R);
        B = SACLDIO_VIERED(B, T, IL);
        if (JL >= B_4) break;
      }
  }
  JL = 0;
  do {
    JL = JL + 1;
    MASSTOR_ADV(B, &CL, &B);
  } while (!(JL == ML || CL != 0));
  if (CL == 0) {
    CP = C;
    while (CP != MASSTOR_SIL) {
      CP1 = MASSTOR_FIRST(CP);
      CP1 = SACLIST_REDUCT(CP1, ML);
      MASSTOR_SFIRST(CP, CP1);
      CP = MASSTOR_RED(CP);
    }
    *XLS = B;
    *N = C;
    return;
  }
  *XLS = MASSTOR_BETA;
  *N = MASSTOR_BETA;
  return;
}

void SACLDIO_LDSSBR
# ifdef __STDC__
(MASSTOR_LIST C_175_A, MASSTOR_LIST BL, MASSTOR_LIST *XLS, MASSTOR_LIST *N)
# else
(C_175_A, BL, XLS, N)
MASSTOR_LIST C_175_A, BL;
MASSTOR_LIST *XLS, *N;
# endif
{
  MASSTOR_LIST B, BL1, C, C1, C2, CP, J1Y, ML, NL, SL;

  NL = MASSTOR_LENGTH(C_175_A);
  ML = MASSTOR_LENGTH(BL);
  C = SACLDIO_MIAIM(C_175_A);
  J1Y = SACLDIO_VINEG(BL);
  B = SACLDIO_VIAZ(J1Y, NL);
  for (;;) {
    C = SACLDIO_MINNCT(C);
    C = SACLDIO_MICS(C);
    C1 = MASSTOR_FIRST(C);
    if (MASSTOR_FIRST(C1) != 0) {
      do {
        B = SACLDIO_VIERED(B, C1, 1);
        C = MASSTOR_RED(C);
        if (C == MASSTOR_SIL) {
          SL = 0;
        } else {
          C2 = MASSTOR_FIRST(C);
          SL = MASSTOR_FIRST(C2);
          if (SL != 0) {
            C1 = SACLDIO_VIERED(C1, C2, 1);
            C = SACLDIO_MICINS(C, C1);
            C1 = C2;
          }
        }
      } while (!(SL == 0));
      NL = NL - 1;
    }
    for (;;) {
      MASSTOR_ADV(B, &BL1, &B);
      if (BL1 != 0) {
        *XLS = MASSTOR_BETA;
        *N = MASSTOR_BETA;
        return;
      }
      CP = C;
      while (CP != MASSTOR_SIL) {
        C1 = MASSTOR_FIRST(CP);
        C1 = MASSTOR_RED(C1);
        MASSTOR_SFIRST(CP, C1);
        CP = MASSTOR_RED(CP);
      }
      ML = ML - 1;
      if (ML > 0) {
        if (NL > 0) {
          goto EXIT_3;
        }
      }
    } EXIT_3:;
    if (ML <= 0) {
      goto EXIT_2;
    }
  } EXIT_2:;
  *XLS = B;
  *N = C;
  return;
}

MASSTOR_LIST SACLDIO_MAIPDE
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M)
# else
(RL, M)
MASSTOR_LIST RL, M;
# endif
{
  MASSTOR_LIST D, IL, J1Y, J2Y, JL, M1, M2, MP1, P, R, R1, R2, RP, S, S1, S2, SS, SS2, TL;

  M1 = M;
  P = 0;
  TL = 1;
  for (;;) {
    if (MASSTOR_RED(M1) == MASSTOR_SIL) {
      J1Y = MASSTOR_FIRST(M1);
      D = MASSTOR_FIRST(J1Y);
      if (TL < 0) {
        D = SACIPOL_IPNEG(RL, D);
      }
      return D;
    }
    MP1 = M1;
    IL = 0;
    do {
      IL = IL + 1;
      MASSTOR_ADV(MP1, &R, &MP1);
    } while (!(MASSTOR_FIRST(R) != 0 || MP1 == MASSTOR_SIL));
    if (MASSTOR_FIRST(R) == 0) {
      D = 0;
      return D;
    }
    if (MASELEM_MASEVEN(IL)) {
      TL = -TL;
    }
    MASSTOR_ADV(R, &R1, &R);
    M2 = MASSTOR_BETA;
    JL = 0;
    do {
      JL = JL + 1;
      MASSTOR_ADV(M1, &S, &M1);
      if (JL != IL) {
        MASSTOR_ADV(S, &S1, &S);
        SS = MASSTOR_BETA;
        RP = R;
        do {
          MASSTOR_ADV(RP, &R2, &RP);
          MASSTOR_ADV(S, &S2, &S);
          J1Y = SACIPOL_IPPROD(RL, R1, S2);
          J2Y = SACIPOL_IPPROD(RL, S1, R2);
          SS2 = SACIPOL_IPDIF(RL, J1Y, J2Y);
          if (P != 0) {
            SS2 = SACIPOL_IPQ(RL, SS2, P);
          }
          SS = MASSTOR_COMP(SS2, SS);
        } while (!(RP == MASSTOR_SIL));
        M2 = MASSTOR_COMP(SS, M2);
      }
    } while (!(M1 == MASSTOR_SIL));
    P = R1;
    M1 = M2;
  } EXIT_4:;
  return D;
}

MASSTOR_LIST SACLDIO_MAIPDM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M)
# else
(RL, M)
MASSTOR_LIST RL, M;
# endif
{
  MASSTOR_LIST BL, BLP, D, DS, J1Y, KL, M1, M11, MP, MS, N, N1, N11, NL, P, PL, PLP, Q, X;

  if (MASSTOR_RED(M) == MASSTOR_SIL) {
    J1Y = MASSTOR_FIRST(M);
    D = MASSTOR_FIRST(J1Y);
    return D;
  }
  MP = M;
  N = MASSTOR_BETA;
  do {
    MASSTOR_ADV(MP, &M1, &MP);
    N1 = MASSTOR_BETA;
    do {
      MASSTOR_ADV(M1, &M11, &M1);
      N11 = SACIPOL_IPSUMN(RL, M11);
      N11 = SACI_ILOG2(N11);
      N1 = MASSTOR_COMP(N11, N1);
    } while (!(M1 == MASSTOR_SIL));
    N = MASSTOR_COMP(N1, N);
  } while (!(MP == MASSTOR_SIL));
  SACCOMB_ASSPR(N, &X, &BL);
  NL = MASSTOR_LENGTH(M);
  KL = SACD_DLOG2(NL);
  J1Y = NL * KL;
  BL = J1Y + BL;
  P = SACPOL_PRIME;
  Q = 1;
  BLP = 0;
  D = 0;
  do {
    if (P == MASSTOR_SIL) {
      MASERR_ERROR(MASERR_severe, "prime list exhausted in MAIPDM.", 31L);
      return D;
    }
    MASSTOR_ADV(P, &PL, &P);
    MS = SACLDIO_MAIPHM(RL, PL, M);
    DS = SACLDIO_MMPDMA(RL, PL, MS);
    J1Y = SACM_MDHOM(PL, Q);
    PLP = SACM_MDINV(PL, J1Y);
    D = SACIPOL_IPCRA(Q, PL, PLP, RL, D, DS);
    Q = SACI_IDPR(Q, PL);
    J1Y = SACD_DLOG2(PL);
    BLP = BLP + J1Y;
  } while (!(BLP >= BL));
  return D;
}

MASSTOR_LIST SACLDIO_MAIPHM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_174_A)
# else
(RL, ML, C_174_A)
MASSTOR_LIST RL, ML, C_174_A;
# endif
{
  MASSTOR_LIST A1, A11, AP, B, B1, B11;

  AP = C_174_A;
  B = MASSTOR_BETA;
  do {
    MASSTOR_ADV(AP, &A1, &AP);
    B1 = MASSTOR_BETA;
    do {
      MASSTOR_ADV(A1, &A11, &A1);
      B11 = SACMPOL_MPHOM(RL, ML, A11);
      B1 = MASSTOR_COMP(B11, B1);
    } while (!(A1 == MASSTOR_SIL));
    B1 = MASSTOR_INV(B1);
    B = MASSTOR_COMP(B1, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACLDIO_MAIPP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_173_A, MASSTOR_LIST B)
# else
(RL, C_173_A, B)
MASSTOR_LIST RL, C_173_A, B;
# endif
{
  MASSTOR_LIST A1, A11, AP, AP1, B1, B11, BP, BS, C, C1, C11, J1Y;

  C = MASSTOR_BETA;
  AP = C_173_A;
  do {
    MASSTOR_ADV(AP, &A1, &AP);
    BP = B;
    C1 = MASSTOR_BETA;
    do {
      C11 = 0;
      BS = MASSTOR_BETA;
      AP1 = A1;
      do {
        MASSTOR_ADV(AP1, &A11, &AP1);
        MASSTOR_ADV(BP, &B1, &BP);
        MASSTOR_ADV(B1, &B11, &B1);
        J1Y = SACIPOL_IPPROD(RL, A11, B11);
        C11 = SACIPOL_IPSUM(RL, C11, J1Y);
        BS = MASSTOR_COMP(B1, BS);
      } while (!(BP == MASSTOR_SIL));
      BP = MASSTOR_INV(BS);
      C1 = MASSTOR_COMP(C11, C1);
    } while (!(MASSTOR_FIRST(BP) == MASSTOR_SIL));
    C1 = MASSTOR_INV(C1);
    C = MASSTOR_COMP(C1, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACLDIO_MIAIM
# ifdef __STDC__
(MASSTOR_LIST C_172_A)
# else
(C_172_A)
MASSTOR_LIST C_172_A;
# endif
{
  MASSTOR_LIST A1, AP, B, IL, JL, NL, T;

  NL = MASSTOR_LENGTH(C_172_A);
  AP = MASSTOR_INV(C_172_A);
  B = MASSTOR_BETA;
  {
    LONGINT B_5 = 1, B_6 = NL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        MASSTOR_ADV(AP, &A1, &AP);
        T = MASSTOR_BETA;
        {
          LONGINT B_7 = 1, B_8 = NL;

          if (B_7 <= B_8)
            for (JL = B_7;; JL += 1) {
              if (IL == JL) {
                T = MASSTOR_COMP(1, T);
              } else {
                T = MASSTOR_COMP(0, T);
              }
              if (JL >= B_8) break;
            }
        }
        A1 = SACLIST_CONC(A1, T);
        B = MASSTOR_COMP(A1, B);
        if (IL >= B_6) break;
      }
  }
  return B;
}

MASSTOR_LIST SACLDIO_MICINS
# ifdef __STDC__
(MASSTOR_LIST C_171_A, MASSTOR_LIST V)
# else
(C_171_A, V)
MASSTOR_LIST C_171_A, V;
# endif
{
  MASSTOR_LIST AP, APP, B, VL;

  AP = C_171_A;
  APP = MASSTOR_RED(AP);
  VL = MASSTOR_FIRST(V);
  while (APP != MASSTOR_SIL && SACI_ICOMP(MASSTOR_FIRST(MASSTOR_FIRST(APP)), VL) >= 0) {
    AP = APP;
    APP = MASSTOR_RED(APP);
  }
  B = MASSTOR_COMP(V, APP);
  MASSTOR_SRED(AP, B);
  B = C_171_A;
  return B;
}

MASSTOR_LIST SACLDIO_MICS
# ifdef __STDC__
(MASSTOR_LIST C_170_A)
# else
(C_170_A)
MASSTOR_LIST C_170_A;
# endif
{
  MASSTOR_LIST A1, A2, AL1, AL2, AP, APP, B, SL;

  do {
    AP = C_170_A;
    SL = 0;
    while (MASSTOR_RED(AP) != MASSTOR_SIL) {
      MASSTOR_ADV(AP, &A1, &APP);
      A2 = MASSTOR_FIRST(APP);
      AL1 = MASSTOR_FIRST(A1);
      AL2 = MASSTOR_FIRST(A2);
      if (SACI_ICOMP(AL1, AL2) < 0) {
        MASSTOR_SFIRST(AP, A2);
        MASSTOR_SFIRST(APP, A1);
        SL = 1;
      }
      AP = APP;
    }
  } while (!(SL == 0));
  B = C_170_A;
  return B;
}

MASSTOR_LIST SACLDIO_MINNCT
# ifdef __STDC__
(MASSTOR_LIST C_169_A)
# else
(C_169_A)
MASSTOR_LIST C_169_A;
# endif
{
  MASSTOR_LIST A1, AL, AP, B;

  B = C_169_A;
  AP = C_169_A;
  do {
    A1 = MASSTOR_FIRST(AP);
    AL = MASSTOR_FIRST(A1);
    if (SACI_ISIGNF(AL) < 0) {
      A1 = SACLDIO_VINEG(A1);
      MASSTOR_SFIRST(AP, A1);
    }
    AP = MASSTOR_RED(AP);
  } while (!(AP == MASSTOR_SIL));
  return B;
}

MASSTOR_LIST SACLDIO_MMDDET
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST M)
# else
(PL, M)
MASSTOR_LIST PL, M;
# endif
{
  MASSTOR_LIST AL, ALP, DL, IL, J1Y, JL, M1, M2, MP1, R, R1, R2, RP, RS, S, S1, S2, SS;

  M1 = M;
  DL = 1;
  for (;;) {
    if (MASSTOR_RED(M1) == MASSTOR_SIL) {
      J1Y = MASSTOR_FIRST(M1);
      AL = MASSTOR_FIRST(J1Y);
      DL = SACM_MDPROD(PL, DL, AL);
      return DL;
    }
    MP1 = M1;
    IL = 0;
    do {
      IL = IL + 1;
      MASSTOR_ADV(MP1, &R, &MP1);
    } while (!(MASSTOR_FIRST(R) != 0 || MP1 == MASSTOR_SIL));
    if (MASSTOR_FIRST(R) == 0) {
      DL = 0;
      return DL;
    }
    MASSTOR_ADV(R, &AL, &R);
    DL = SACM_MDPROD(PL, DL, AL);
    if (MASELEM_MASEVEN(IL)) {
      DL = SACM_MDNEG(PL, DL);
    }
    ALP = SACM_MDINV(PL, AL);
    RS = MASSTOR_BETA;
    do {
      MASSTOR_ADV(R, &R1, &R);
      R1 = SACM_MDPROD(PL, R1, ALP);
      RS = MASSTOR_COMP(R1, RS);
    } while (!(R == MASSTOR_SIL));
    R = MASSTOR_INV(RS);
    M2 = MASSTOR_BETA;
    JL = 0;
    do {
      JL = JL + 1;
      MASSTOR_ADV(M1, &S, &M1);
      if (JL != IL) {
        MASSTOR_ADV(S, &S1, &S);
        SS = MASSTOR_BETA;
        RP = R;
        do {
          MASSTOR_ADV(RP, &R2, &RP);
          MASSTOR_ADV(S, &S2, &S);
          J1Y = SACM_MDPROD(PL, S1, R2);
          S2 = SACM_MDDIF(PL, S2, J1Y);
          SS = MASSTOR_COMP(S2, SS);
        } while (!(RP == MASSTOR_SIL));
        M2 = MASSTOR_COMP(SS, M2);
      }
    } while (!(M1 == MASSTOR_SIL));
    M1 = M2;
  } EXIT_5:;
  return DL;
}

MASSTOR_LIST SACLDIO_MMDNSB
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST M)
# else
(PL, M)
MASSTOR_LIST PL, M;
# endif
{
  MASSTOR_LIST AL, B, C, CL, CP, IL, J1Y, KL, M1, M2, ML, MP1, MP2, V, VL, VP;

  M1 = M;
  M2 = MASSTOR_BETA;
  B = MASSTOR_BETA;
  KL = 1;
  J1Y = MASSTOR_FIRST(M);
  ML = MASSTOR_LENGTH(J1Y);
  for (;;) {
    MP1 = M1;
    M1 = MASSTOR_BETA;
    AL = 0;
    for (;;) {
      if (MP1 == MASSTOR_SIL) {
        goto EXIT_7;
      }
      MASSTOR_ADV(MP1, &C, &MP1);
      MASSTOR_ADV(C, &AL, &C);
      if (AL != 0) {
        goto EXIT_7;
      }
      M1 = MASSTOR_COMP(C, M1);
    } EXIT_7:;
    if (MP1 == MASSTOR_SIL && AL == 0) {
      V = MASSTOR_BETA;
      {
        LONGINT B_9 = 1, B_10 = ML - KL;

        if (B_9 <= B_10)
          for (IL = B_9;; IL += 1) {
            V = MASSTOR_COMP(0, V);
            if (IL >= B_10) break;
          }
      }
      V = MASSTOR_COMP(1, V);
      MP2 = M2;
      while (MP2 != MASSTOR_SIL) {
        MASSTOR_ADV(MP2, &C, &MP2);
        AL = SACMPOL_VMPIP(0, PL, C, V);
        V = MASSTOR_COMP(AL, V);
      }
      B = MASSTOR_COMP(V, B);
      M2 = MASSTOR_COMP(0, M2);
    } else {
      M2 = MASSTOR_COMP(C, M2);
      J1Y = SACM_MDINV(PL, AL);
      AL = PL - J1Y;
      CP = C;
      while (CP != MASSTOR_SIL) {
        J1Y = MASSTOR_FIRST(CP);
        CL = SACM_MDPROD(PL, J1Y, AL);
        MASSTOR_SFIRST(CP, CL);
        CP = MASSTOR_RED(CP);
      }
      while (MP1 != MASSTOR_SIL) {
        MASSTOR_ADV(MP1, &VP, &MP1);
        MASSTOR_ADV(VP, &VL, &VP);
        M1 = MASSTOR_COMP(VP, M1);
        if (VL != 0) {
          CP = C;
          while (CP != MASSTOR_SIL) {
            MASSTOR_ADV(CP, &CL, &CP);
            AL = SACM_MDPROD(PL, CL, VL);
            J1Y = MASSTOR_FIRST(VP);
            AL = SACM_MDSUM(PL, J1Y, AL);
            MASSTOR_SFIRST(VP, AL);
            VP = MASSTOR_RED(VP);
          }
        }
      }
    }
    if (KL >= ML) {
      goto EXIT_6;
    }
    KL = KL + 1;
  } EXIT_6:;
  return B;
}

MASSTOR_LIST SACLDIO_MMPDMA
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST M)
# else
(RL, PL, M)
MASSTOR_LIST RL, PL, M;
# endif
{
  MASSTOR_LIST AL, B, BL, BLP, D, DL, DS, J1Y, M1, M11, MP, MS, N, N1, N11, RLP, X;

  if (MASSTOR_RED(M) == MASSTOR_SIL) {
    J1Y = MASSTOR_FIRST(M);
    D = MASSTOR_FIRST(J1Y);
    return D;
  }
  if (RL == 0) {
    D = SACLDIO_MMDDET(PL, M);
    return D;
  }
  MP = M;
  N = MASSTOR_BETA;
  do {
    MASSTOR_ADV(MP, &M1, &MP);
    N1 = MASSTOR_BETA;
    do {
      MASSTOR_ADV(M1, &M11, &M1);
      N11 = SACPOL_PDEGSV(RL, M11, 1);
      N1 = MASSTOR_COMP(N11, N1);
    } while (!(M1 == MASSTOR_SIL));
    N = MASSTOR_COMP(N1, N);
  } while (!(MP == MASSTOR_SIL));
  SACCOMB_ASSPR(N, &X, &DL);
  AL = 0;
  RLP = RL - 1;
  B = SACPOL_PINV(0, 1, 1);
  do {
    if (AL == PL) {
      MASERR_ERROR(MASERR_severe, "elements of finite field exhausted in MMPDMA.", 45L);
      return D;
    }
    MS = SACLDIO_MMPEV(RL, PL, M, 1, AL);
    DS = SACLDIO_MMPDMA(RLP, PL, MS);
    BL = SACMPOL_MPEMV(1, PL, B, AL);
    BLP = SACM_MDINV(PL, BL);
    D = SACMPOL_MPINT(PL, B, AL, BLP, RL, D, DS);
    J1Y = SACM_MDNEG(PL, AL);
    X = SACLIST_LIST4(1, 1, 0, J1Y);
    B = SACMPOL_MPPROD(1, PL, B, X);
    AL = AL + 1;
  } while (!(SACPOL_PDEG(B) > DL));
  return D;
}

MASSTOR_LIST SACLDIO_MMPEV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_168_A, MASSTOR_LIST KL, MASSTOR_LIST AL)
# else
(RL, ML, C_168_A, KL, AL)
MASSTOR_LIST RL, ML, C_168_A, KL, AL;
# endif
{
  MASSTOR_LIST A1, A11, AP, B, B1, B11;

  AP = C_168_A;
  B = MASSTOR_BETA;
  do {
    MASSTOR_ADV(AP, &A1, &AP);
    B1 = MASSTOR_BETA;
    do {
      MASSTOR_ADV(A1, &A11, &A1);
      B11 = SACMPOL_MPEVAL(RL, ML, A11, KL, AL);
      B1 = MASSTOR_COMP(B11, B1);
    } while (!(A1 == MASSTOR_SIL));
    B1 = MASSTOR_INV(B1);
    B = MASSTOR_COMP(B1, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACLDIO_VIAZ
# ifdef __STDC__
(MASSTOR_LIST C_167_A, MASSTOR_LIST NL)
# else
(C_167_A, NL)
MASSTOR_LIST C_167_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  B = MASSTOR_BETA;
  {
    LONGINT B_11 = 1, B_12 = NL;

    if (B_11 <= B_12)
      for (KL = B_11;; KL += 1) {
        B = MASSTOR_COMP(0, B);
        if (KL >= B_12) break;
      }
  }
  B = SACLIST_CONC(C_167_A, B);
  return B;
}

MASSTOR_LIST SACLDIO_VIDIF
# ifdef __STDC__
(MASSTOR_LIST C_166_A, MASSTOR_LIST B)
# else
(C_166_A, B)
MASSTOR_LIST C_166_A, B;
# endif
{
  MASSTOR_LIST C, J1Y;

  J1Y = SACLDIO_VINEG(B);
  C = SACLDIO_VISUM(C_166_A, J1Y);
  return C;
}

MASSTOR_LIST SACLDIO_VIERED
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST IL)
# else
(U, V, IL)
MASSTOR_LIST U, V, IL;
# endif
{
  MASSTOR_LIST QL, UL, VL, W;

  UL = SACLIST_LELT(U, IL);
  VL = SACLIST_LELT(V, IL);
  QL = SACI_IQ(UL, VL);
  if (QL == 0) {
    W = U;
  } else {
    QL = SACI_INEG(QL);
    W = SACLDIO_VISPR(QL, V);
    W = SACLDIO_VISUM(U, W);
  }
  return W;
}

MASSTOR_LIST SACLDIO_VILCOM
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST C_165_A, MASSTOR_LIST B)
# else
(AL, BL, C_165_A, B)
MASSTOR_LIST AL, BL, C_165_A, B;
# endif
{
  MASSTOR_LIST C, S, T;

  S = SACLDIO_VISPR(AL, C_165_A);
  T = SACLDIO_VISPR(BL, B);
  C = SACLDIO_VISUM(S, T);
  return C;
}

MASSTOR_LIST SACLDIO_VINEG
# ifdef __STDC__
(MASSTOR_LIST C_164_A)
# else
(C_164_A)
MASSTOR_LIST C_164_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL;

  B = MASSTOR_BETA;
  AP = C_164_A;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = SACI_INEG(AL);
    B = MASSTOR_COMP(BL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACLDIO_VISPR
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST C_163_A)
# else
(AL, C_163_A)
MASSTOR_LIST AL, C_163_A;
# endif
{
  MASSTOR_LIST ALP, AP, C, CL, IL, NL;

  if (AL == 0) {
    NL = MASSTOR_LENGTH(C_163_A);
    C = MASSTOR_BETA;
    {
      LONGINT B_13 = 1, B_14 = NL;

      if (B_13 <= B_14)
        for (IL = B_13;; IL += 1) {
          C = MASSTOR_COMP(0, C);
          if (IL >= B_14) break;
        }
    }
    return C;
  }
  if (AL == 1) {
    C = C_163_A;
    return C;
  }
  if (AL == -1) {
    C = SACLDIO_VINEG(C_163_A);
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_163_A;
  do {
    MASSTOR_ADV(AP, &ALP, &AP);
    CL = SACI_IPROD(AL, ALP);
    C = MASSTOR_COMP(CL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACLDIO_VISUM
# ifdef __STDC__
(MASSTOR_LIST C_162_A, MASSTOR_LIST B)
# else
(C_162_A, B)
MASSTOR_LIST C_162_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  C = MASSTOR_BETA;
  AP = C_162_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    CL = SACI_ISUM(AL, BL);
    C = MASSTOR_COMP(CL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

void SACLDIO_VIUT
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST IL, MASSTOR_LIST *UP, MASSTOR_LIST *VP)
# else
(U, V, IL, UP, VP)
MASSTOR_LIST U, V, IL;
MASSTOR_LIST *UP, *VP;
# endif
{
  MASSTOR_LIST CL, PL, QL, RL, SL, UL, VL;

  UL = SACLIST_LELT(U, IL);
  VL = SACLIST_LELT(V, IL);
  SACI_IDEGCD(UL, VL, &CL, &PL, &QL, &RL, &SL);
  *UP = SACLDIO_VILCOM(PL, QL, U, V);
  *VP = SACLDIO_VILCOM(RL, SL, U, V);
  return;
}

void BEGIN_SACLDIO()
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
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACM();
    BEGIN_SACPRIM();
    BEGIN_SACCOMB();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();

  }
}
