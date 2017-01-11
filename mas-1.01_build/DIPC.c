#include "SYSTEM_.h"

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPIPOL
#include "DIPIPOL.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

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

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

MASSTOR_LIST DIPC_EVORD;
MASSTOR_LIST DIPC_VALIS;
CHAR DIPC_rcsid [] = "$Id: DIPC.md,v 1.7 1995/11/04 22:14:54 pesch Exp $";
CHAR DIPC_copyright [] = "Copyright (c) 1989 - 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPC.mi,v 1.10 1995/11/05 09:16:35 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1995 Universitaet Passau";
static void BEGIND ARGS(());


void DIPC_BACKUB
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C;

  do {
    MASBIOS_BKSP();
    MASBIOS_BKSP();
    C = MASBIOS_CREAD();
  } while (!(C == MASBIOS_MASORD(' ')));
}

static void BEGIND
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LISTVAR(&DIPC_VALIS);
  DIPC_VALIS = MASSTOR_SIL;
  DIPC_EVORD = DIPC_INVLEX;
  MASSTOR_LISTVAR(&DIPC_EVORD);
  return;
}

MASSTOR_LIST DIPC_CLIN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, IDUM, L, LL;

  L = MASSTOR_BETA;
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('$')) {
    MASBIOS_BKSP();
    return L;
  }
  C = MASBIOS_CREAD();
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    MASBIOS_BKSP();
    return L;
  }
  LL = 1;
  do {
    C = MASBIOS_CREAD();
    L = MASSTOR_COMP(C, L);
    if (C == MASBIOS_MASORD('(')) {
      LL = LL + 1;
    } else {
      if (C == MASBIOS_MASORD(')')) {
        LL = LL - 1;
      }
    }
  } while (!(LL == 0));
  L = MASSTOR_RED(L);
  L = MASSTOR_INV(L);
  return L;
}

void DIPC_DILBSO
# ifdef __STDC__
(MASSTOR_LIST C_163_A)
# else
(C_163_A)
MASSTOR_LIST C_163_A;
# endif
{
  MASSTOR_LIST AL, AP;

  AP = C_163_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPC_DIPBSO(AL);
  }
  return;
}

MASSTOR_LIST DIPC_DILFPL
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_162_A)
# else
(RL, C_162_A)
MASSTOR_LIST RL, C_162_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL;

  AP = C_162_A;
  B = MASSTOR_BETA;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = DIPC_DIPFP(RL, AL);
    B = MASSTOR_COMP(BL, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DILPERM
# ifdef __STDC__
(MASSTOR_LIST dil, MASSTOR_LIST perm)
# else
(dil, perm)
MASSTOR_LIST dil, perm;
# endif
{
  MASSTOR_LIST dip, result;

  result = MASSTOR_SIL;
  while (dil != MASSTOR_SIL) {
    MASSTOR_ADV(dil, &dip, &dil);
    result = MASSTOR_COMP(DIPC_DIPERM(dip, perm), result);
  }
  return MASSTOR_INV(result);
}

void DIPC_DIPADM
# ifdef __STDC__
(MASSTOR_LIST C_161_A, MASSTOR_LIST *EL, MASSTOR_LIST *FL, MASSTOR_LIST *BL, MASSTOR_LIST *B)
# else
(C_161_A, EL, FL, BL, B)
MASSTOR_LIST C_161_A;
MASSTOR_LIST *EL, *FL, *BL, *B;
# endif
{
  MASSTOR_LIST CL, DL, J1Y;

  if (C_161_A == 0) {
    *EL = 0;
    *FL = 0;
    *BL = C_161_A;
    *B = 0;
    return;
  }
  *B = C_161_A;
  *BL = MASSTOR_BETA;
  J1Y = DIPC_DIPEVL(*B);
  *EL = MASSTOR_FIRST(J1Y);
  for (;;) {
    if (*B == MASSTOR_SIL) {
      goto EXIT_1;
    }
    CL = DIPC_DIPLBC(*B);
    DL = DIPC_DIPEVL(*B);
    MASSTOR_ADV(DL, FL, &DL);
    if (*EL == *FL) {
      *B = SACLIST_RED2(*B);
      *BL = DIPC_DIPMCP(DL, CL, *BL);
    } else {
      goto EXIT_1;
    }
  } EXIT_1:;
  *BL = MASSTOR_INV(*BL);
  if (*B == MASSTOR_SIL) {
    *B = 0;
    *FL = 0;
  }
  return;
}

void DIPC_DIPADS
# ifdef __STDC__
(MASSTOR_LIST C_160_A, MASSTOR_LIST IL, MASSTOR_LIST SL, MASSTOR_LIST *EL, MASSTOR_LIST *FL, MASSTOR_LIST *BL, MASSTOR_LIST *B)
# else
(C_160_A, IL, SL, EL, FL, BL, B)
MASSTOR_LIST C_160_A, IL, SL;
MASSTOR_LIST *EL, *FL, *BL, *B;
# endif
{
  MASSTOR_LIST CL, DL, DUMMY, E1, GL, J1Y, JL, RL;

  if (C_160_A == 0) {
    *EL = 0;
    *FL = 0;
    *BL = C_160_A;
    *B = 0;
    return;
  }
  RL = DIPC_DIPNOV(C_160_A);
  J1Y = RL - IL;
  JL = J1Y + 1;
  DIPC_DIPMAD(C_160_A, &CL, &E1, B);
  DIPC_EVSU(E1, JL, SL, &GL, EL);
  *BL = DIPC_DIPFMO(GL, CL);
  for (;;) {
    if (*B == MASSTOR_SIL) {
      goto EXIT_2;
    }
    DIPC_DIPMAD(*B, &CL, &DL, &DUMMY);
    DIPC_EVSU(DL, JL, SL, &GL, FL);
    if (*EL == *FL) {
      *B = SACLIST_RED2(*B);
      *BL = DIPC_DIPMCP(GL, CL, *BL);
    } else {
      goto EXIT_2;
    }
  } EXIT_2:;
  *BL = MASSTOR_INV(*BL);
  if (*B == MASSTOR_SIL) {
    *B = 0;
    *FL = 0;
  }
  return;
}

void DIPC_DIPADV
# ifdef __STDC__
(MASSTOR_LIST C_159_A, MASSTOR_LIST IL, MASSTOR_LIST *EL, MASSTOR_LIST *FL, MASSTOR_LIST *BL, MASSTOR_LIST *B)
# else
(C_159_A, IL, EL, FL, BL, B)
MASSTOR_LIST C_159_A, IL;
MASSTOR_LIST *EL, *FL, *BL, *B;
# endif
{
  MASSTOR_LIST CL, DL, DUMMY, E1, GL, J1Y, JL, RL;

  if (C_159_A == 0) {
    *EL = 0;
    *FL = 0;
    *BL = C_159_A;
    *B = 0;
    return;
  }
  RL = DIPC_DIPNOV(C_159_A);
  if (IL == RL) {
    DIPC_DIPADM(C_159_A, EL, FL, BL, B);
    return;
  }
  J1Y = RL - IL;
  JL = J1Y + 1;
  DIPC_DIPMAD(C_159_A, &CL, &E1, B);
  DIPC_EVDEL(E1, JL, &GL, EL);
  *BL = DIPC_DIPFMO(GL, CL);
  for (;;) {
    if (*B == MASSTOR_SIL) {
      goto EXIT_3;
    }
    DIPC_DIPMAD(*B, &CL, &DL, &DUMMY);
    DIPC_EVDEL(DL, JL, &GL, FL);
    if (*EL == *FL) {
      *B = SACLIST_RED2(*B);
      *BL = DIPC_DIPMCP(GL, CL, *BL);
    } else {
      goto EXIT_3;
    }
  } EXIT_3:;
  *BL = MASSTOR_INV(*BL);
  if (*B == MASSTOR_SIL) {
    *B = 0;
    *FL = 0;
  }
  return;
}

void DIPC_DIPBSO
# ifdef __STDC__
(MASSTOR_LIST C_158_A)
# else
(C_158_A)
MASSTOR_LIST C_158_A;
# endif
{
  MASSTOR_LIST ALP, ALPP, AP, APP, B, BP, DUMMY, ELP, ELPP, TL;

  if (C_158_A == 0) {
    return;
  }
  B = MASSTOR_BETA;
  do {
    AP = C_158_A;
    DIPC_DIPMAD(AP, &ALP, &ELP, &APP);
    BP = MASSTOR_BETA;
    while (APP != B) {
      DIPC_DIPMAD(APP, &ALPP, &ELPP, &DUMMY);
      TL = DIPC_EVCOMP(ELP, ELPP);
      if (TL == 0) {
        MASERR_ERROR(MASERR_harmless, "DIPBSO, equal exponents.", 24L);
        return;
      }
      if (TL < 0) {
        DIPC_DIPMST(AP, ALPP, ELPP);
        DIPC_DIPMST(APP, ALP, ELP);
        BP = APP;
      } else {
        ALP = ALPP;
        ELP = ELPP;
      }
      AP = APP;
      APP = SACLIST_RED2(AP);
    }
    B = BP;
  } while (!(B == MASSTOR_SIL));
  return;
}

MASSTOR_LIST DIPC_DIPCMP
# ifdef __STDC__
(MASSTOR_LIST EL, MASSTOR_LIST C_157_A)
# else
(EL, C_157_A)
MASSTOR_LIST EL, C_157_A;
# endif
{
  MASSTOR_LIST AS, B, CL, DL, DLP;

  if (C_157_A == 0) {
    B = C_157_A;
    return B;
  }
  AS = C_157_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &CL, &DL, &AS);
    DLP = MASSTOR_COMP(EL, DL);
    B = DIPC_DIPMCP(DLP, CL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DIPDEG
# ifdef __STDC__
(MASSTOR_LIST C_156_A)
# else
(C_156_A)
MASSTOR_LIST C_156_A;
# endif
{
  MASSTOR_LIST EL, NL;

  NL = 0;
  if (C_156_A == 0) {
    return NL;
  }
  EL = DIPC_DIPEVL(C_156_A);
  if (EL == MASSTOR_SIL) {
    return NL;
  }
  NL = MASSTOR_FIRST(EL);
  return NL;
}

MASSTOR_LIST DIPC_DIPDPV
# ifdef __STDC__
(MASSTOR_LIST C_155_A, MASSTOR_LIST SL, MASSTOR_LIST QL)
# else
(C_155_A, SL, QL)
MASSTOR_LIST C_155_A, SL, QL;
# endif
{
  MASSTOR_LIST AL, AS, EL, EL1, FL, J1Y, JL, Q, RL;

  if (C_155_A == 0 || QL == 0) {
    Q = C_155_A;
    return Q;
  }
  RL = DIPC_DIPNOV(C_155_A);
  J1Y = RL - SL;
  JL = J1Y + 1;
  AS = C_155_A;
  Q = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVCSUB(EL, JL, QL, &FL, &EL1);
    Q = DIPC_DIPMCP(FL, AL, Q);
  } while (!(AS == MASSTOR_SIL));
  Q = MASSTOR_INV(Q);
  return Q;
}

MASSTOR_LIST DIPC_DIPERM
# ifdef __STDC__
(MASSTOR_LIST C_154_A, MASSTOR_LIST P)
# else
(C_154_A, P)
MASSTOR_LIST C_154_A, P;
# endif
{
  MASSTOR_LIST AL, AP, B, DL, EL;

  if (C_154_A == 0) {
    B = 0;
    return B;
  }
  AP = C_154_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    DL = SACLIST_CINV(EL);
    DL = SACCOMB_LPERM(DL, P);
    DL = MASSTOR_INV(DL);
    B = DIPC_DIPMCP(DL, AL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  DIPC_DIPBSO(B);
  return B;
}

MASSTOR_LIST DIPC_DIPEVL
# ifdef __STDC__
(MASSTOR_LIST C_153_A)
# else
(C_153_A)
MASSTOR_LIST C_153_A;
# endif
{
  MASSTOR_LIST UL;

  UL = MASSTOR_BETA;
  if (C_153_A != 0) {
    UL = MASSTOR_FIRST(C_153_A);
  }
  return UL;
}

MASSTOR_LIST DIPC_DIPEVP
# ifdef __STDC__
(MASSTOR_LIST C_152_A, MASSTOR_LIST EL)
# else
(C_152_A, EL)
MASSTOR_LIST C_152_A, EL;
# endif
{
  MASSTOR_LIST AL, AP, C, FL, GL;

  if (C_152_A == 0 || DIPC_EVSIGN(EL) == 0) {
    C = C_152_A;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_152_A;
  do {
    DIPC_DIPMAD(AP, &AL, &FL, &AP);
    GL = DIPC_EVSUM(EL, FL);
    C = DIPC_DIPMCP(GL, AL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPC_DIPEXC
# ifdef __STDC__
(MASSTOR_LIST C_151_A, MASSTOR_LIST ILP, MASSTOR_LIST JLP)
# else
(C_151_A, ILP, JLP)
MASSTOR_LIST C_151_A, ILP, JLP;
# endif
{
  MASSTOR_LIST AL, AP, B, EL, FL, IL, J1Y, JL, RL, TL;

  if (C_151_A == 0 || ILP == JLP) {
    B = C_151_A;
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_151_A;
  RL = DIPC_DIPNOV(C_151_A);
  J1Y = RL + 1;
  JL = J1Y - JLP;
  J1Y = RL + 1;
  IL = J1Y - ILP;
  if (IL > JL) {
    TL = JL;
    JL = IL;
    IL = TL;
  }
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    FL = DIPC_EVEXC(EL, IL, JL);
    B = DIPC_DIPMCP(FL, AL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  DIPC_DIPBSO(B);
  return B;
}

MASSTOR_LIST DIPC_DIPFMO
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST EL)
# else
(AL, EL)
MASSTOR_LIST AL, EL;
# endif
{
  MASSTOR_LIST C_150_A;

  C_150_A = SACLIST_COMP2(EL, AL, MASSTOR_BETA);
  return C_150_A;
}

MASSTOR_LIST DIPC_DIPFP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_149_A)
# else
(RL, C_149_A)
MASSTOR_LIST RL, C_149_A;
# endif
{
  MASSTOR_LIST A1, AL1, AS, B, B1, BL1, E1, EL1, ELP, ELS, RLS;

  if (C_149_A == 0) {
    B = C_149_A;
    return B;
  }
  if (RL == 0) {
    B = DIPC_DIPFMO(C_149_A, MASSTOR_BETA);
    return B;
  }
  B = MASSTOR_BETA;
  AS = C_149_A;
  RLS = RL - 1;
  if (RLS == 0) {
    do {
      SACLIST_ADV2(AS, &EL1, &AL1, &AS);
      E1 = MASSTOR_LIST1(EL1);
      B = DIPC_DIPMCP(E1, AL1, B);
    } while (!(AS == MASSTOR_SIL));
    B = MASSTOR_INV(B);
    return B;
  }
  do {
    SACLIST_ADV2(AS, &ELP, &A1, &AS);
    B1 = DIPC_DIPFP(RLS, A1);
    do {
      DIPC_DIPMAD(B1, &BL1, &ELS, &B1);
      E1 = MASSTOR_COMP(ELP, ELS);
      B = DIPC_DIPMCP(E1, BL1, B);
    } while (!(B1 == MASSTOR_SIL));
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DIPINV
# ifdef __STDC__
(MASSTOR_LIST C_148_A, MASSTOR_LIST JL, MASSTOR_LIST KL)
# else
(C_148_A, JL, KL)
MASSTOR_LIST C_148_A, JL, KL;
# endif
{
  MASSTOR_LIST AS, B, CL, DL, EL, ELS, FL, GL, I, IL, J1Y;

  if (C_148_A == 0 || KL == 0) {
    B = C_148_A;
    return B;
  }
  AS = C_148_A;
  B = MASSTOR_BETA;
  J1Y = DIPC_DIPNOV(C_148_A);
  IL = J1Y - JL;
  do {
    DIPC_DIPMAD(AS, &CL, &DL, &AS);
    EL = MASSTOR_BETA;
    {
      LONGINT B_1 = 1, B_2 = IL;

      if (B_1 <= B_2)
        for (I = B_1;; I += 1) {
          MASSTOR_ADV(DL, &FL, &DL);
          EL = MASSTOR_COMP(FL, EL);
          if (I >= B_2) break;
        }
    }
    GL = DL;
    {
      LONGINT B_3 = 1, B_4 = KL;

      if (B_3 <= B_4)
        for (I = B_3;; I += 1) {
          GL = MASSTOR_COMP(0, GL);
          if (I >= B_4) break;
        }
    }
    if (EL == MASSTOR_SIL) {
      EL = GL;
    } else {
      ELS = MASSTOR_INV(EL);
      MASSTOR_SRED(EL, GL);
      EL = ELS;
    }
    B = DIPC_DIPMCP(EL, CL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DIPLBC
# ifdef __STDC__
(MASSTOR_LIST C_147_A)
# else
(C_147_A)
MASSTOR_LIST C_147_A;
# endif
{
  MASSTOR_LIST AL;

  AL = 0;
  if (C_147_A != 0) {
    AL = SACLIST_SECOND(C_147_A);
  }
  return AL;
}

MASSTOR_LIST DIPC_DIPLDC
# ifdef __STDC__
(MASSTOR_LIST C_146_A)
# else
(C_146_A)
MASSTOR_LIST C_146_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, FL;

  DIPC_DIPADM(C_146_A, &EL, &FL, &AL, &AS);
  return AL;
}

MASSTOR_LIST DIPC_DIPLM
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST AL1, AL2, EL1, EL2, L, LP, LP1, LP2, TL;
  BOOLEAN eoz;

  if (L1 == MASSTOR_SIL) {
    L = L2;
    return L;
  }
  if (L2 == MASSTOR_SIL) {
    L = L1;
    return L;
  }
  LP1 = L1;
  LP2 = L2;
  AL1 = MASSTOR_FIRST(L1);
  AL2 = MASSTOR_FIRST(L2);
  EL1 = DIPC_DIPEVL(AL1);
  EL2 = DIPC_DIPEVL(AL2);
  TL = DIPC_EVCOMP(EL1, EL2);
  if (TL > 0) {
    L = L2;
    LP = L2;
    LP2 = MASSTOR_RED(L2);
    eoz = FALSE;
  } else {
    L = L1;
    LP = L1;
    LP1 = MASSTOR_RED(L1);
    eoz = TRUE;
  }
  for (;;) {
    if (eoz) {
      if (LP1 == MASSTOR_SIL) {
        goto EXIT_4;
      }
      AL1 = MASSTOR_FIRST(LP1);
      EL1 = DIPC_DIPEVL(AL1);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        eoz = TRUE;
      } else {
        MASSTOR_SRED(LP, LP2);
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        eoz = FALSE;
      }
    } else {
      if (LP2 == MASSTOR_SIL) {
        goto EXIT_4;
      }
      AL2 = MASSTOR_FIRST(LP2);
      EL2 = DIPC_DIPEVL(AL2);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        MASSTOR_SRED(LP, LP1);
        LP = LP1;
        LP1 = MASSTOR_RED(LP1);
        eoz = TRUE;
      } else {
        LP = LP2;
        LP2 = MASSTOR_RED(LP2);
        eoz = FALSE;
      }
    }
  } EXIT_4:;
  if (LP1 == MASSTOR_SIL) {
    MASSTOR_SRED(LP, LP2);
  } else {
    MASSTOR_SRED(LP, LP1);
  }
  return L;
}

MASSTOR_LIST DIPC_DIPLPM
# ifdef __STDC__
(MASSTOR_LIST C_145_A)
# else
(C_145_A)
MASSTOR_LIST C_145_A;
# endif
{
  MASSTOR_LIST AL1, AL2, AP, APP, APPP, B, BP, BPP, C, CP, CPP, CS, EL1, EL2, TL;

  if (C_145_A == MASSTOR_SIL || MASSTOR_RED(C_145_A) == MASSTOR_SIL) {
    B = C_145_A;
    return B;
  }
  C = MASSTOR_LIST1(0);
  CS = C;
  AP = C_145_A;
  do {
    MASSTOR_ADV(AP, &AL1, &APP);
    if (APP == MASSTOR_SIL) {
      BP = AP;
    } else {
      MASSTOR_ADV(APP, &AL2, &APPP);
      EL1 = DIPC_DIPEVL(AL1);
      EL2 = DIPC_DIPEVL(AL2);
      TL = DIPC_EVCOMP(EL1, EL2);
      if (TL <= 0) {
        BP = AP;
        MASSTOR_SRED(APP, MASSTOR_SIL);
      } else {
        BP = APP;
        MASSTOR_SRED(APP, AP);
        MASSTOR_SRED(AP, MASSTOR_SIL);
      }
    }
    C = MASSTOR_COMP(BP, C);
    AP = APPP;
  } while (!(APP == MASSTOR_SIL || AP == MASSTOR_SIL));
  MASSTOR_ADV(C, &BP, &C);
  MASSTOR_SFIRST(CS, BP);
  MASSTOR_SRED(CS, C);
  MASSTOR_ADV(C, &B, &CP);
  while (C != CP) {
    MASSTOR_ADV(CP, &BP, &CPP);
    BPP = DIPC_DIPLM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

void DIPC_DIPLRS
# ifdef __STDC__
(MASSTOR_LIST C_144_A)
# else
(C_144_A)
MASSTOR_LIST C_144_A;
# endif
{
  MASSTOR_LIST AL, AP;

  if (C_144_A == MASSTOR_SIL) {
    return;
  }
  AP = C_144_A;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPC_DIPBSO(AL);
  } while (!(AP == MASSTOR_SIL));
  return;
}

void DIPC_DIPMAD
# ifdef __STDC__
(MASSTOR_LIST C_143_A, MASSTOR_LIST *AL, MASSTOR_LIST *EL, MASSTOR_LIST *AP)
# else
(C_143_A, AL, EL, AP)
MASSTOR_LIST C_143_A;
MASSTOR_LIST *AL, *EL, *AP;
# endif
{
  MASSTOR_ADV(C_143_A, EL, AP);
  MASSTOR_ADV(*AP, AL, AP);
}

MASSTOR_LIST DIPC_DIPMCP
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST EL, MASSTOR_LIST C_142_A)
# else
(AL, EL, C_142_A)
MASSTOR_LIST AL, EL, C_142_A;
# endif
{
  MASSTOR_LIST AP;

  AP = SACLIST_COMP2(EL, AL, C_142_A);
  return AP;
}

MASSTOR_LIST DIPC_DIPMPM
# ifdef __STDC__
(MASSTOR_LIST C_141_A, MASSTOR_LIST PL)
# else
(C_141_A, PL)
MASSTOR_LIST C_141_A, PL;
# endif
{
  MASSTOR_LIST AL, AS, B, EL, FL, GL;

  if (C_141_A == 0 || PL == 0) {
    B = C_141_A;
    return B;
  }
  AS = C_141_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    MASSTOR_ADV(EL, &FL, &GL);
    FL = FL + PL;
    GL = MASSTOR_COMP(FL, GL);
    B = DIPC_DIPMCP(GL, AL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DIPMPV
# ifdef __STDC__
(MASSTOR_LIST C_140_A, MASSTOR_LIST SL, MASSTOR_LIST PL)
# else
(C_140_A, SL, PL)
MASSTOR_LIST C_140_A, SL, PL;
# endif
{
  MASSTOR_LIST AL, AS, B, EL, EL1, FL, J1Y, JL, RL;

  if (C_140_A == 0 || PL == 0) {
    B = C_140_A;
    return B;
  }
  RL = DIPC_DIPNOV(C_140_A);
  J1Y = RL - SL;
  JL = J1Y + 1;
  AS = C_140_A;
  B = MASSTOR_BETA;
  while (AS != MASSTOR_SIL) {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    DIPC_EVCADD(EL, JL, PL, &FL, &EL1);
    B = DIPC_DIPMCP(FL, AL, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_DIPMRD
# ifdef __STDC__
(MASSTOR_LIST C_139_A)
# else
(C_139_A)
MASSTOR_LIST C_139_A;
# endif
{
  MASSTOR_LIST B;

  if (C_139_A == 0) {
    B = 0;
  } else {
    B = SACLIST_RED2(C_139_A);
    if (B == MASSTOR_SIL) {
      B = 0;
    }
  }
  return B;
}

void DIPC_DIPMST
# ifdef __STDC__
(MASSTOR_LIST C_138_A, MASSTOR_LIST AL, MASSTOR_LIST EL)
# else
(C_138_A, AL, EL)
MASSTOR_LIST C_138_A, AL, EL;
# endif
{
  MASSTOR_LIST AP;

  MASSTOR_SFIRST(C_138_A, EL);
  AP = MASSTOR_RED(C_138_A);
  MASSTOR_SFIRST(AP, AL);
}

MASSTOR_LIST DIPC_DIPNBC
# ifdef __STDC__
(MASSTOR_LIST C_137_A)
# else
(C_137_A)
MASSTOR_LIST C_137_A;
# endif
{
  MASSTOR_LIST LL;

  LL = 0;
  if (C_137_A == 0) {
    return LL;
  }
  LL = MASSTOR_LENGTH(C_137_A);
  LL = LL / 2;
  return LL;
}

MASELEM_GAMMAINT DIPC_DIPNOV
# ifdef __STDC__
(MASSTOR_LIST C_136_A)
# else
(C_136_A)
MASSTOR_LIST C_136_A;
# endif
{
  MASSTOR_LIST J1Y, RL;

  if (C_136_A == 0) {
    RL = 0;
  } else {
    J1Y = DIPC_DIPEVL(C_136_A);
    RL = MASSTOR_LENGTH(J1Y);
  }
  return RL;
}

MASSTOR_LIST DIPC_DIPRED
# ifdef __STDC__
(MASSTOR_LIST C_135_A)
# else
(C_135_A)
MASSTOR_LIST C_135_A;
# endif
{
  MASSTOR_LIST AL, B, EL, FL;

  DIPC_DIPADM(C_135_A, &EL, &FL, &AL, &B);
  return B;
}

MASSTOR_LIST DIPC_DIPTBC
# ifdef __STDC__
(MASSTOR_LIST C_134_A)
# else
(C_134_A)
MASSTOR_LIST C_134_A;
# endif
{
  MASSTOR_LIST AL, AP, AS, J1Y, SL;

  if (C_134_A == 0) {
    AL = 0;
    return AL;
  }
  AS = C_134_A;
  do {
    AP = AS;
    AS = SACLIST_RED2(AS);
  } while (!(AS == MASSTOR_SIL));
  J1Y = DIPC_DIPEVL(AP);
  SL = DIPC_EVSIGN(J1Y);
  if (SL == 0) {
    AL = DIPC_DIPLBC(AP);
  } else {
    AL = 0;
  }
  return AL;
}

MASSTOR_LIST DIPC_DIPTCF
# ifdef __STDC__
(MASSTOR_LIST C_133_A)
# else
(C_133_A)
MASSTOR_LIST C_133_A;
# endif
{
  MASSTOR_LIST A1, AL, AS, EL, J1Y;

  if (C_133_A == 0) {
    AL = 0;
    return AL;
  }
  AS = C_133_A;
  AL = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &A1, &EL, &AS);
    if (MASSTOR_FIRST(EL) == 0) {
      J1Y = MASSTOR_RED(EL);
      AL = DIPC_DIPMCP(J1Y, A1, AL);
    }
  } while (!(AS == MASSTOR_SIL));
  if (AL == MASSTOR_SIL) {
    AL = 0;
  } else {
    AL = MASSTOR_INV(AL);
  }
  return AL;
}

MASSTOR_LIST DIPC_DIPTCS
# ifdef __STDC__
(MASSTOR_LIST C_132_A, MASSTOR_LIST IL)
# else
(C_132_A, IL)
MASSTOR_LIST C_132_A, IL;
# endif
{
  MASSTOR_LIST A1, AL, AS, EL, EL1, FL, J1Y, JL, RL;

  if (C_132_A == 0) {
    AL = 0;
    return AL;
  }
  RL = DIPC_DIPNOV(C_132_A);
  if (RL == IL) {
    AL = DIPC_DIPTCF(C_132_A);
    return AL;
  }
  J1Y = RL - IL;
  JL = J1Y + 1;
  AS = C_132_A;
  AL = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &A1, &EL, &AS);
    DIPC_EVDEL(EL, JL, &FL, &EL1);
    if (EL1 == 0) {
      AL = DIPC_DIPMCP(FL, A1, AL);
    }
  } while (!(AS == MASSTOR_SIL));
  if (AL == MASSTOR_SIL) {
    AL = 0;
  } else {
    AL = MASSTOR_INV(AL);
  }
  return AL;
}

MASSTOR_LIST DIPC_DIPTDG
# ifdef __STDC__
(MASSTOR_LIST C_131_A)
# else
(C_131_A)
MASSTOR_LIST C_131_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, ML, NL;

  NL = 0;
  if (C_131_A == 0) {
    return NL;
  }
  if (DIPC_DIPNOV(C_131_A) <= 1) {
    NL = DIPC_DIPDEG(C_131_A);
    return NL;
  }
  AS = C_131_A;
  while (AS != MASSTOR_SIL) {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    ML = DIPC_EVTDEG(EL);
    NL = MASELEM_MASMAX(ML, NL);
  }
  return NL;
}

MASSTOR_LIST DIPC_DIPUNT
# ifdef __STDC__
(MASSTOR_LIST C_130_A)
# else
(C_130_A)
MASSTOR_LIST C_130_A;
# endif
{
  MASSTOR_LIST AL, AP, EL, RL, TL, V, V1;

  RL = DIPC_DIPNOV(C_130_A);
  if (RL <= 1) {
    TL = 1;
    return TL;
  }
  TL = 0;
  DIPC_DIPMAD(C_130_A, &AL, &EL, &AP);
  V = DIPC_EVDOV(EL);
  if (V == MASSTOR_SIL) {
    TL = 1;
    return TL;
  }
  if (MASSTOR_RED(V) != MASSTOR_SIL) {
    return TL;
  }
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    V1 = DIPC_EVDOV(EL);
    if (V1 != MASSTOR_SIL) {
      if (SACLIST_EQUAL(V, V1) == 0) {
        return TL;
      }
    }
  }
  TL = 1;
  return TL;
}

MASSTOR_LIST DIPC_DIPUV
# ifdef __STDC__
(MASSTOR_LIST C_129_A)
# else
(C_129_A)
MASSTOR_LIST C_129_A;
# endif
{
  MASSTOR_LIST AL, AP, EL, J1Y, J2Y, RL, TL, V, V1;

  RL = DIPC_DIPNOV(C_129_A);
  if (RL == 1) {
    TL = 1;
    return TL;
  }
  if (RL == 0) {
    TL = -1;
    return TL;
  }
  TL = 0;
  DIPC_DIPMAD(C_129_A, &AL, &EL, &AP);
  V = DIPC_EVDOV(EL);
  if (V == MASSTOR_SIL) {
    TL = -1;
    return TL;
  }
  if (MASSTOR_RED(V) != MASSTOR_SIL) {
    return TL;
  }
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    V1 = DIPC_EVDOV(EL);
    if (V1 != MASSTOR_SIL) {
      if (SACLIST_EQUAL(V, V1) == 0) {
        return TL;
      }
    }
  }
  J1Y = RL + 1;
  J2Y = MASSTOR_FIRST(V);
  TL = J1Y - J2Y;
  return TL;
}

MASSTOR_LIST DIPC_EPREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, EL, IDUM;

  EL = 1;
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('^')) {
    EL = SACLIST_AREAD();
    return EL;
  }
  if (C != MASBIOS_MASORD('*')) {
    MASBIOS_BKSP();
  } else {
    C = MASBIOS_CREAD();
    if (C != MASBIOS_MASORD('*')) {
      MASBIOS_BKSP();
      MASBIOS_BKSP();
    } else {
      EL = SACLIST_AREAD();
    }
  }
  return EL;
}

void DIPC_EVCADD
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST EL, MASSTOR_LIST *V, MASSTOR_LIST *FL)
# else
(U, IL, EL, V, FL)
MASSTOR_LIST U, IL, EL;
MASSTOR_LIST *V, *FL;
# endif
{
  MASSTOR_LIST GL, J, UP, UPS, VP;

  if (IL == 0 || U == MASSTOR_SIL) {
    *V = U;
    *FL = 0;
    return;
  }
  UP = U;
  VP = MASSTOR_BETA;
  {
    LONGINT B_5 = 1, B_6 = IL - 1;

    if (B_5 <= B_6)
      for (J = B_5;; J += 1) {
        MASSTOR_ADV(UP, &GL, &UP);
        VP = MASSTOR_COMP(GL, VP);
        if (J >= B_6) break;
      }
  }
  MASSTOR_ADV(UP, &GL, &UP);
  *FL = GL + EL;
  UPS = MASSTOR_COMP(*FL, UP);
  if (VP == MASSTOR_SIL) {
    *V = UPS;
  } else {
    *V = MASSTOR_INV(VP);
    MASSTOR_SRED(VP, UPS);
  }
  return;
}

MASSTOR_LIST DIPC_EVCOMP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL;

  if (DIPC_EVORD > MASSTOR_SIL) {
    TL = DIPC_EVLFCP(DIPC_EVORD, U, V);
    if (TL == 0) {
      if (SACLIST_EQUAL(U, V) == 0) {
        MASBIOS_SWRITE("LF =", 4L);
        SACLIST_OWRITE(DIPC_EVORD);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("U  =", 4L);
        SACLIST_OWRITE(U);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("V  =", 4L);
        SACLIST_OWRITE(V);
        MASBIOS_BLINES(0);
        MASERR_ERROR(MASERR_severe, "EVCOMP: Linear form not linear independent.", 43L);
      }
    }
    return TL;
  }
  switch ((INTEGER)DIPC_EVORD) {
  case DIPC_LEX:;
    TL = -DIPC_EVILCP(U, V);
    break;
  case DIPC_INVLEX:;
    TL = DIPC_EVILCP(U, V);
    break;
  case DIPC_GRLEX:;
    TL = -DIPC_EVIGLC(U, V);
    break;
  case DIPC_IGRLEX:;
    TL = DIPC_EVIGLC(U, V);
    break;
  case DIPC_REVLEX:;
    TL = -DIPC_EVILCI(U, V);
    break;
  case DIPC_REVILEX:;
    TL = DIPC_EVILCI(U, V);
    break;
  case DIPC_REVTDEG:;
    TL = -DIPC_EVITDC(U, V);
    break;
  case DIPC_REVITDG:;
    TL = DIPC_EVITDC(U, V);
    break;
  default :
    MASERR_ERROR(MASERR_severe, "EVCOMP, undefined term order.", 29L);
    break;
  }
  return TL;
}

void DIPC_EVCSUB
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST EL, MASSTOR_LIST *V, MASSTOR_LIST *FL)
# else
(U, IL, EL, V, FL)
MASSTOR_LIST U, IL, EL;
MASSTOR_LIST *V, *FL;
# endif
{
  MASSTOR_LIST GL, J, UP, UPS, VP;

  if (IL == 0 || U == MASSTOR_SIL) {
    *V = U;
    *FL = 0;
    return;
  }
  UP = U;
  VP = MASSTOR_BETA;
  {
    LONGINT B_7 = 1, B_8 = IL - 1;

    if (B_7 <= B_8)
      for (J = B_7;; J += 1) {
        MASSTOR_ADV(UP, FL, &UP);
        VP = MASSTOR_COMP(*FL, VP);
        if (J >= B_8) break;
      }
  }
  MASSTOR_ADV(UP, FL, &UP);
  GL = *FL - EL;
  UPS = MASSTOR_COMP(GL, UP);
  if (VP == MASSTOR_SIL) {
    *V = UPS;
  } else {
    *V = MASSTOR_INV(VP);
    MASSTOR_SRED(VP, UPS);
  }
  return;
}

void DIPC_EVDEL
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST *V, MASSTOR_LIST *EL)
# else
(U, IL, V, EL)
MASSTOR_LIST U, IL;
MASSTOR_LIST *V, *EL;
# endif
{
  MASSTOR_LIST J, UP, VP;

  if (U == MASSTOR_SIL || IL == 0) {
    *V = U;
    *EL = 0;
    return;
  }
  UP = U;
  VP = MASSTOR_BETA;
  {
    LONGINT B_9 = 1, B_10 = IL - 1;

    if (B_9 <= B_10)
      for (J = B_9;; J += 1) {
        MASSTOR_ADV(UP, EL, &UP);
        VP = MASSTOR_COMP(*EL, VP);
        if (J >= B_10) break;
      }
  }
  MASSTOR_ADV(UP, EL, &UP);
  if (VP == MASSTOR_SIL) {
    *V = UP;
  } else {
    *V = MASSTOR_INV(VP);
    MASSTOR_SRED(VP, UP);
  }
  return;
}

void DIPC_EVDER
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST EL, MASSTOR_LIST *V, MASSTOR_LIST *FL)
# else
(U, IL, EL, V, FL)
MASSTOR_LIST U, IL, EL;
MASSTOR_LIST *V, *FL;
# endif
{
  MASSTOR_LIST DL, J, KL, UP, UPS, VP;

  *FL = 0;
  if (U == MASSTOR_SIL) {
    return;
  }
  UP = U;
  VP = MASSTOR_BETA;
  {
    LONGINT B_11 = 1, B_12 = IL - 1;

    if (B_11 <= B_12)
      for (J = B_11;; J += 1) {
        MASSTOR_ADV(UP, &DL, &UP);
        VP = MASSTOR_COMP(DL, VP);
        if (J >= B_12) break;
      }
  }
  MASSTOR_ADV(UP, &DL, &UP);
  if (EL > DL) {
    return;
  }
  *FL = DL;
  {
    LONGINT B_13 = DL - 1, B_14 = DL - EL + 1;

    if (B_13 >= B_14)
      for (KL = B_13;; KL += -1) {
        *FL = SACI_IPROD(*FL, KL);
        if (KL <= B_14) break;
      }
  }
  UPS = MASSTOR_COMP(KL, UP);
  if (VP == MASSTOR_SIL) {
    *V = UPS;
  } else {
    *V = MASSTOR_INV(VP);
    MASSTOR_SRED(VP, UPS);
  }
  return;
}

void DIPC_EVDFSI
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST *W, MASSTOR_LIST *SL)
# else
(U, V, W, SL)
MASSTOR_LIST U, V;
MASSTOR_LIST *W, *SL;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, WL;

  *W = MASSTOR_BETA;
  *SL = 0;
  if (U == MASSTOR_SIL) {
    return;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = UL - VL;
    if (WL < 0) {
      *SL = -1;
      return;
    }
    if (WL > 0) {
      *SL = 1;
    }
    *W = MASSTOR_COMP(WL, *W);
  } while (!(US == MASSTOR_SIL));
  *W = MASSTOR_INV(*W);
  return;
}

MASSTOR_LIST DIPC_EVDIF
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  if (U == MASSTOR_SIL) {
    return W;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = UL - VL;
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST DIPC_EVDOV
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST JL, UL, US, V;

  V = MASSTOR_BETA;
  US = U;
  JL = 0;
  while (US != MASSTOR_SIL) {
    JL = JL + 1;
    MASSTOR_ADV(US, &UL, &US);
    if (UL != 0) {
      V = MASSTOR_COMP(JL, V);
    }
  }
  V = MASSTOR_INV(V);
  return V;
}

MASSTOR_LIST DIPC_EVEXC
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST JL)
# else
(U, IL, JL)
MASSTOR_LIST U, IL, JL;
# endif
{
  MASSTOR_LIST J, V, V1, VL, VL1, VL2, VP, VPS, VS1, VS2;

  VS1 = MASSTOR_BETA;
  VS2 = MASSTOR_BETA;
  VP = U;
  {
    LONGINT B_15 = 1, B_16 = IL - 1;

    if (B_15 <= B_16)
      for (J = B_15;; J += 1) {
        MASSTOR_ADV(VP, &VL, &VP);
        VS1 = MASSTOR_COMP(VL, VS1);
        if (J >= B_16) break;
      }
  }
  MASSTOR_ADV(VP, &VL1, &VP);
  {
    LONGINT B_17 = 1, B_18 = JL - IL - 1;

    if (B_17 <= B_18)
      for (J = B_17;; J += 1) {
        MASSTOR_ADV(VP, &VL, &VP);
        VS2 = MASSTOR_COMP(VL, VS2);
        if (J >= B_18) break;
      }
  }
  MASSTOR_ADV(VP, &VL2, &VP);
  VPS = MASSTOR_COMP(VL1, VP);
  if (VS2 == MASSTOR_SIL) {
    V1 = VPS;
  } else {
    V1 = MASSTOR_INV(VS2);
    MASSTOR_SRED(VS2, VPS);
  }
  V1 = MASSTOR_COMP(VL2, V1);
  if (VS1 == MASSTOR_SIL) {
    V = V1;
  } else {
    V = MASSTOR_INV(VS1);
    MASSTOR_SRED(VS1, V1);
  }
  return V;
}

MASSTOR_LIST DIPC_EVIGLC
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, ULP, US, VL, VLP, VS;

  TL = 0;
  US = U;
  VS = V;
  for (;;) {
    if (US == MASSTOR_SIL) {
      goto EXIT_5;
    }
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL > VL) {
      TL = 1;
      goto EXIT_5;
    } else {
      if (UL < VL) {
        TL = -1;
        goto EXIT_5;
      }
    }
  } EXIT_5:;
  if (TL == 0) {
    return TL;
  }
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &ULP, &US);
    MASSTOR_ADV(VS, &VLP, &VS);
    UL = UL + ULP;
    VL = VL + VLP;
  }
  if (UL > VL) {
    TL = 1;
  } else {
    if (UL < VL) {
      TL = -1;
    }
  }
  return TL;
}

MASSTOR_LIST DIPC_EVILCI
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UP, VP;

  UP = SACLIST_CINV(U);
  VP = SACLIST_CINV(V);
  TL = DIPC_EVILCP(UP, VP);
  return TL;
}

MASSTOR_LIST DIPC_EVILCP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, US, VL, VS;

  TL = 0;
  US = U;
  VS = V;
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL > VL) {
      TL = 1;
      return TL;
    }
    if (UL < VL) {
      TL = -1;
      return TL;
    }
  }
  return TL;
}

MASSTOR_LIST DIPC_EVITDC
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, ULP, US, VL, VLP, VS;

  TL = 0;
  US = SACLIST_CINV(U);
  VS = SACLIST_CINV(V);
  for (;;) {
    if (US == MASSTOR_SIL) {
      goto EXIT_6;
    }
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL < VL) {
      TL = 1;
      goto EXIT_6;
    } else {
      if (UL > VL) {
        TL = -1;
        goto EXIT_6;
      }
    }
  } EXIT_6:;
  if (TL == 0) {
    return TL;
  }
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &ULP, &US);
    MASSTOR_ADV(VS, &VLP, &VS);
    UL = UL + ULP;
    VL = VL + VLP;
  }
  if (UL > VL) {
    TL = 1;
  } else {
    if (UL < VL) {
      TL = -1;
    }
  }
  return TL;
}

MASSTOR_LIST DIPC_EVLFCP
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST V)
# else
(L, U, V)
MASSTOR_LIST L, U, V;
# endif
{
  MASSTOR_LIST SL, TL, EL, FL, UL, US, VL, VS;

  US = DIPIPOL_VIPIIP(1, L, U);
  VS = DIPIPOL_VIPIIP(1, L, V);
  TL = 0;
  while (US != 0 && VS != 0) {
    MASSTOR_ADV(US, &EL, &US);
    MASSTOR_ADV(VS, &FL, &VS);
    if (EL > FL) {
      TL = 1;
      return TL;
    }
    if (EL < FL) {
      TL = -1;
      return TL;
    }
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (US == MASSTOR_SIL) {
      US = 0;
    }
    if (VS == MASSTOR_SIL) {
      VS = 0;
    }
    SL = SACI_ICOMP(UL, VL);
    if (SL > 0) {
      TL = 1;
      return TL;
    }
    if (SL < 0) {
      TL = -1;
      return TL;
    }
  }
  if (US != 0) {
    TL = 1;
    return TL;
  }
  if (VS != 0) {
    TL = -1;
    return TL;
  }
  return TL;
}

MASSTOR_LIST DIPC_EVLCM
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  if (U == MASSTOR_SIL) {
    return W;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL > VL) {
      WL = UL;
    } else {
      WL = VL;
    }
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST DIPC_EVMT
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, US, VL, VS;

  TL = 1;
  if (U == MASSTOR_SIL) {
    return TL;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL < VL) {
      TL = 0;
      return TL;
    }
  } while (!(US == MASSTOR_SIL));
  return TL;
}

MASSTOR_LIST DIPC_EVNNZE
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST NL, UL, US;

  NL = 0;
  US = U;
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    if (UL != 0) {
      NL = NL + 1;
    }
  }
  return NL;
}

void DIPC_EVOWRITE
# ifdef __STDC__
(MASSTOR_LIST EVO)
# else
(EVO)
MASSTOR_LIST EVO;
# endif
{
  MASSTOR_LIST O;

  switch (EVO) {
  case DIPC_LEX:;
    MASBIOS_SWRITE("ascending inverse lexicographical order", 39L);
    break;
  case DIPC_INVLEX:;
    MASBIOS_SWRITE("inverse lexicographical term order", 34L);
    break;
  case DIPC_GRLEX:;
    MASBIOS_SWRITE("ascending graded (total degree) invers lexicographical order", 60L);
    break;
  case DIPC_IGRLEX:;
    MASBIOS_SWRITE("graded (total degree) invers lexicographical termorder", 54L);
    break;
  case DIPC_REVLEX:;
    MASBIOS_SWRITE("ascending lexicographical order", 31L);
    break;
  case DIPC_REVILEX:;
    MASBIOS_SWRITE("lexicographical term order", 26L);
    break;
  case DIPC_REVTDEG:;
    MASBIOS_SWRITE("ascending total degree Buchberger lexicographical order", 55L);
    break;
  case DIPC_REVITDG:;
    MASBIOS_SWRITE("total degree Buchberger lexicographical term order", 50L);
    break;
  default :
    if (EVO <= MASSTOR_SIL) {
      MASBIOS_SWRITE("garbage passed to EVOWRITE", 26L);
    } else {
      DIPTOOLS_EvordPush(DIPC_INVLEX);
      DIPI_DIILWR(MASSTOR_INV(DIPC_DILFPL(1, EVO)), MASSTOR_LIST1(MASSTOR_LIST1(MASBIOS_MASORD('T'))));
      DIPTOOLS_EvordPop();
    }
    break;
  }
}

void DIPC_EvordWrite
# ifdef __STDC__
()
# else
()
# endif
{
  DIPC_EVOWRITE(DIPC_EVORD);
}

MASSTOR_LIST DIPC_EVRAND
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL)
# else
(RL, KL)
MASSTOR_LIST RL, KL;
# endif
{
  MASSTOR_LIST DL, EL, FL, I, IDUM, U;

  if (KL <= 0) {
    FL = MASSTOR_BETA;
  } else {
    FL = MASSTOR_BETA / KL;
  }
  U = MASSTOR_BETA;
  {
    LONGINT B_19 = 1, B_20 = RL;

    if (B_19 <= B_20)
      for (I = B_19;; I += 1) {
        DL = SACD_DRANN();
        EL = DL / FL;
        U = MASSTOR_COMP(EL, U);
        if (I >= B_20) break;
      }
  }
  return U;
}

MASSTOR_LIST DIPC_EVRASP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST QL)
# else
(RL, KL, QL)
MASSTOR_LIST RL, KL, QL;
# endif
{
  MASSTOR_LIST DL, EL, FL, GL, I, IDUM, U;

  if (KL <= 0) {
    FL = MASSTOR_BETA;
  } else {
    FL = MASSTOR_BETA / KL;
  }
  U = MASSTOR_BETA;
  {
    LONGINT B_21 = 1, B_22 = RL;

    if (B_21 <= B_22)
      for (I = B_21;; I += 1) {
        GL = SACD_DRANN();
        if (GL < QL) {
          DL = SACD_DRANN();
          EL = DL / FL;
        } else {
          EL = 0;
        }
        U = MASSTOR_COMP(EL, U);
        if (I >= B_22) break;
      }
  }
  return U;
}

MASSTOR_LIST DIPC_EVSIGN
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST TL, UL, US;

  TL = 0;
  US = U;
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    if (UL < 0) {
      TL = -1;
      return TL;
    }
    if (UL > 0) {
      TL = 1;
    }
  }
  return TL;
}

void DIPC_EVSU
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST FL, MASSTOR_LIST *V, MASSTOR_LIST *EL)
# else
(U, IL, FL, V, EL)
MASSTOR_LIST U, IL, FL;
MASSTOR_LIST *V, *EL;
# endif
{
  MASSTOR_LIST J, UP, VP;

  if (U == MASSTOR_SIL || IL == 0) {
    *V = U;
    *EL = 0;
    return;
  }
  UP = U;
  VP = MASSTOR_BETA;
  {
    LONGINT B_23 = 1, B_24 = IL - 1;

    if (B_23 <= B_24)
      for (J = B_23;; J += 1) {
        MASSTOR_ADV(UP, EL, &UP);
        VP = MASSTOR_COMP(*EL, VP);
        if (J >= B_24) break;
      }
  }
  MASSTOR_ADV(UP, EL, &UP);
  VP = MASSTOR_COMP(FL, VP);
  *V = MASSTOR_INV(VP);
  MASSTOR_SRED(VP, UP);
  return;
}

MASSTOR_LIST DIPC_EVSUM
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST UL, US, VL, VS, W, WL;

  W = MASSTOR_BETA;
  if (U == MASSTOR_SIL) {
    return W;
  }
  US = U;
  VS = V;
  do {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    WL = UL + VL;
    W = MASSTOR_COMP(WL, W);
  } while (!(US == MASSTOR_SIL));
  W = MASSTOR_INV(W);
  return W;
}

MASSTOR_LIST DIPC_EVTDEG
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST NL, UL, US;

  NL = 0;
  US = U;
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    NL = NL + UL;
  }
  return NL;
}

MASSTOR_LIST DIPC_PBCLI
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_128_A)
# else
(RL, C_128_A)
MASSTOR_LIST RL, C_128_A;
# endif
{
  MASSTOR_LIST AL, ALS, AP, AS, B, BL, BP, BS, EL, ELS, RLP;

  if (C_128_A == 0 || RL == 0) {
    B = MASSTOR_LIST1(C_128_A);
    return B;
  }
  if (RL == 1) {
    AS = C_128_A;
    B = MASSTOR_BETA;
    do {
      SACLIST_ADV2(AS, &ELS, &ALS, &AS);
      B = MASSTOR_COMP(ALS, B);
    } while (!(AS == MASSTOR_SIL));
    B = MASSTOR_INV(B);
    return B;
  }
  AP = C_128_A;
  B = MASSTOR_LIST1(0);
  BP = B;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = DIPC_PBCLI(RLP, AL);
    BS = SACLIST_LAST(BL);
    MASSTOR_SRED(BP, BL);
    BP = BS;
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_RED(B);
  return B;
}

void DIPC_PFDIP
# ifdef __STDC__
(MASSTOR_LIST C_127_A, MASSTOR_LIST *RL, MASSTOR_LIST *B)
# else
(C_127_A, RL, B)
MASSTOR_LIST C_127_A;
MASSTOR_LIST *RL, *B;
# endif
{
  MASSTOR_LIST A1, AL1, AS, B1, E1, EL, EL1, FL, RLS, SL;

  if (C_127_A == 0) {
    *RL = 0;
    *B = 0;
    return;
  }
  *RL = DIPC_DIPNOV(C_127_A);
  if (*RL == 0) {
    *B = DIPC_DIPLBC(C_127_A);
    return;
  }
  *B = MASSTOR_BETA;
  AS = C_127_A;
  RLS = *RL - 1;
  if (RLS == 0) {
    do {
      DIPC_DIPMAD(AS, &AL1, &E1, &AS);
      EL1 = MASSTOR_FIRST(E1);
      *B = SACLIST_COMP2(AL1, EL1, *B);
    } while (!(AS == MASSTOR_SIL));
    *B = MASSTOR_INV(*B);
    return;
  }
  do {
    DIPC_DIPADM(AS, &EL, &FL, &A1, &AS);
    DIPC_PFDIP(A1, &SL, &B1);
    *B = SACLIST_COMP2(B1, EL, *B);
  } while (!(AS == 0));
  *B = MASSTOR_INV(*B);
  return;
}

void DIPC_PLFDIL
# ifdef __STDC__
(MASSTOR_LIST C_126_A, MASSTOR_LIST *RL, MASSTOR_LIST *B)
# else
(C_126_A, RL, B)
MASSTOR_LIST C_126_A;
MASSTOR_LIST *RL, *B;
# endif
{
  MASSTOR_LIST AL, AP, BL;

  AP = C_126_A;
  *B = MASSTOR_BETA;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPC_PFDIP(AL, RL, &BL);
    *B = MASSTOR_COMP(BL, *B);
  }
  *B = MASSTOR_INV(*B);
  return;
}

MASSTOR_LIST DIPC_PMPV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_125_A, MASSTOR_LIST IL, MASSTOR_LIST NL)
# else
(RL, C_125_A, IL, NL)
MASSTOR_LIST RL, C_125_A, IL, NL;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, FL, RLP;

  if (C_125_A == 0 || NL == 0) {
    B = C_125_A;
    return B;
  }
  AP = C_125_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL == RL) {
      BL = AL;
      FL = EL + NL;
    } else {
      BL = DIPC_PMPV(RLP, AL, IL, NL);
      FL = EL;
    }
    B = SACLIST_COMP2(BL, FL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPC_PPERMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_124_A, MASSTOR_LIST P)
# else
(RL, C_124_A, P)
MASSTOR_LIST RL, C_124_A, P;
# endif
{
  MASSTOR_LIST AP, B, BP, RLS;

  if (C_124_A == 0) {
    B = 0;
    return B;
  }
  AP = DIPC_DIPFP(RL, C_124_A);
  BP = DIPC_DIPERM(AP, P);
  DIPC_PFDIP(BP, &RLS, &B);
  return B;
}

MASSTOR_LIST DIPC_STVL
# ifdef __STDC__
(MASSTOR_LIST RL)
# else
(RL)
MASSTOR_LIST RL;
# endif
{
  MASSTOR_LIST K, KL, R, V, VL, X;

  V = MASSTOR_BETA;
  X = MASBIOS_MASORD('X');
  for (K = RL; K >= 1; K += -1) {
    KL = K;
    VL = MASSTOR_BETA;
    while (KL > 9) {
      SACD_DQR(0, KL, 10, &KL, &R);
      VL = MASSTOR_COMP(R, VL);
    }
    VL = SACLIST_COMP2(X, KL, VL);
    V = MASSTOR_COMP(VL, V);
  }
  return V;
}

MASSTOR_LIST DIPC_DIP2AD
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST d, MASSTOR_LIST rest)
# else
(P, d, rest)
MASSTOR_LIST P, d, rest;
# endif
{
  MASSTOR_LIST P1, exp, coe;

  P1 = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &exp, &P);
    P1 = MASSTOR_COMP(exp, P1);
    MASSTOR_ADV(P, &coe, &P);
    P1 = MASSTOR_COMP(MASSTOR_COMP(d, MASSTOR_COMP(coe, rest)), P1);
  }
  P1 = MASSTOR_INV(P1);
  return P1;
}

MASSTOR_LIST DIPC_AD2DIP
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST P1, exp, coe, val;

  P1 = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &exp, &P);
    P1 = MASSTOR_COMP(exp, P1);
    MASSTOR_ADV(P, &coe, &P);
    P1 = MASSTOR_COMP(SACLIST_SECOND(coe), P1);
  }
  P1 = MASSTOR_INV(P1);
  return P1;
}

void BEGIN_DIPC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPI();
    BEGIN_DIPIPOL();
    BEGIN_DIPTOOLS();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACCOMB();
    BEGIN_SACD();
    BEGIN_SACI();

    BEGIND();
  }
}
