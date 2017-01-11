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

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
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

MASSTOR_LIST SACPRIM_UZ210, SACPRIM_SMPRM;
CHAR SACPRIM_rcsid [] = "$Id: SACPRIM.md,v 1.2 1992/02/12 13:19:15 pesch Exp $";
CHAR SACPRIM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACPRIM.mi,v 1.4 1995/11/05 08:45:56 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    BOOLEAN A[1000 - 1 + 1];
};
struct S_2 {
    BOOLEAN A[1000 - 1 + 1];
};
static MASSTOR_LIST IL;


MASSTOR_LIST SACPRIM_DPGEN
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST K)
# else
(ML, K)
MASSTOR_LIST ML, K;
# endif
{
  struct S_1 P;
  MASSTOR_LIST L, PL, ML1, ML2, HL, DL, SL, QL, RL;
  INTEGER i, k;

  k = (INTEGER)K;
  if (k > 1000) {
    k = 1000;
    MASERR_ERROR(MASERR_severe, "in DPGEN, only 2*1000 numbers checked.", 38L);
  }
  if (MASELEM_MASEVEN(ML)) {
    ML1 = ML + 1;
  } else {
    ML1 = ML;
  }
  HL = (MASSTOR_LIST)(2 * k) - 2;
  ML2 = ML1 + HL;
  {
    LONGINT B_1 = 1, B_2 = k;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        P.A[i - 1] = TRUE;
        if (i >= B_2) break;
      }
  }
  DL = 3;
  SL = 0;
  for (;;) {
    QL = ML2 / DL;
    if (QL < DL) {
      goto EXIT_1;
    }
    RL = ML1 % DL;
    if (RL + HL >= DL || RL == 0) {
      if (RL == 0) {
        i = 1;
      } else {
        if (RL % 2 == 0) {
          i = (INTEGER)(DL - RL / 2 + 1);
        } else {
          i = (INTEGER)((DL - RL) / 2 + 1);
        }
      }
      if (ML1 <= DL) {
        i = i + (INTEGER)DL;
      }
      while (i <= k) {
        P.A[i - 1] = FALSE;
        i = i + (INTEGER)DL;
      }
    }
    if (SL == 1) {
      DL = DL + 4;
      SL = 2;
    } else {
      if (SL == 2) {
        DL = DL + 2;
        SL = 1;
      } else {
        DL = 5;
        SL = 2;
      }
    }
  } EXIT_1:;
  L = MASSTOR_SIL;
  PL = ML2;
  i = k;
  do {
    if (P.A[i - 1]) {
      L = MASSTOR_COMP(PL, L);
    }
    PL = PL - 2;
    i = i - 1;
  } while (!(i == 0));
  if (ML == 1) {
    MASSTOR_SFIRST(L, 2);
  }
  if (ML == 2) {
    L = MASSTOR_COMP(2, L);
  }
  return L;
}

void SACPRIM_FRESL
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST *ML, MASSTOR_LIST *L)
# else
(NL, ML, L)
MASSTOR_LIST NL;
MASSTOR_LIST *ML, *L;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, AL4, BL1, H, HL, J1Y, J2Y, KL, KL1, L1, M, ML1;

  AL1 = SACI_IDREM(NL, 32);
  AL2 = MASELEM_MASREM(AL1, 16);
  AL3 = MASELEM_MASREM(AL2, 8);
  AL4 = MASELEM_MASREM(AL3, 4);
  if (AL4 == 3) {
    *ML = 4;
    if (AL3 == 3) {
      BL1 = 2;
    } else {
      BL1 = 0;
    }
  } else {
    if (AL3 == 1) {
      *ML = 8;
      if (AL2 == 1) {
        BL1 = 1;
      } else {
        BL1 = 3;
      }
    } else {
      *ML = 16;
      switch ((INTEGER)(AL1 / 8)) {
      case 0:;
        BL1 = 3;
        break;
      case 1:;
        BL1 = 7;
        break;
      case 2:;
        BL1 = 5;
        break;
      case 3:;
        BL1 = 1;
        break;
      }
    }
  }
  if (*ML == 4) {
    *L = MASSTOR_LIST1(BL1);
  } else {
    J1Y = *ML - BL1;
    *L = SACLIST_LIST2(BL1, J1Y);
  }
  KL = MASSTOR_LENGTH(*L);
  AL1 = SACI_IDREM(NL, 27);
  AL2 = MASELEM_MASREM(AL1, 3);
  if (AL2 == 2) {
    ML1 = 3;
    KL1 = 1;
    L1 = MASSTOR_LIST1(0);
  } else {
    ML1 = 27;
    KL1 = 4;
    L1 = SACPRIM_FRLSM(ML1, AL1);
  }
  *L = SACM_MDLCRA(*ML, ML1, *L, L1);
  *ML = *ML * ML1;
  KL = KL * KL1;
  AL1 = SACI_IDREM(NL, 25);
  AL2 = MASELEM_MASREM(AL1, 5);
  if (AL2 == 2 || AL2 == 3) {
    ML1 = 5;
    J1Y = AL2 - 1;
    J2Y = 6 - AL2;
    L1 = SACLIST_LIST2(J1Y, J2Y);
    KL1 = 2;
  } else {
    ML1 = 25;
    L1 = SACPRIM_FRLSM(ML1, AL1);
    KL1 = 7;
  }
  if (ML1 >= MASSTOR_BETA / *ML) {
    return;
  }
  KL = KL * KL1;
  *L = SACM_MDLCRA(*ML, ML1, *L, L1);
  *ML = *ML * ML1;
  M = SACLIST_LIST3(7, 11, 13);
  H = SACLIST_LIST3(64, 48, 0);
  for (;;) {
    MASSTOR_ADV(M, &ML1, &M);
    if (ML1 >= MASSTOR_BETA / *ML) {
      return;
    }
    AL1 = SACI_IDREM(NL, ML1);
    L1 = SACPRIM_FRLSM(ML1, AL1);
    KL1 = MASSTOR_LENGTH(L1);
    *L = SACM_MDLCRA(*ML, ML1, *L, L1);
    *ML = *ML * ML1;
    KL = KL * KL1;
    MASSTOR_ADV(H, &HL, &H);
    if (KL > HL) {
      return;
    }
  } EXIT_2:;
  return;
}

MASSTOR_LIST SACPRIM_FRLSM
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL)
# else
(ML, AL)
MASSTOR_LIST ML, AL;
# endif
{
  MASSTOR_LIST IL, ILP, JL, L, MLP, S, SL, SLP, SP;

  MLP = ML / 2;
  S = MASSTOR_BETA;
  {
    LONGINT B_3 = 0, B_4 = MLP;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        SL = SACM_MDPROD(ML, IL, IL);
        S = MASSTOR_COMP(SL, S);
        if (IL >= B_4) break;
      }
  }
  L = MASSTOR_BETA;
  SP = S;
  for (IL = MLP; IL >= 0; IL += -1) {
    MASSTOR_ADV(SP, &SL, &SP);
    SLP = SACM_MDDIF(ML, SL, AL);
    JL = SACLIST_LSRCH(SLP, S);
    if (JL != 0) {
      L = MASSTOR_COMP(IL, L);
      ILP = SACM_MDNEG(ML, IL);
      if (ILP != IL) {
        L = MASSTOR_COMP(ILP, L);
      }
    }
  }
  return L;
}

MASSTOR_LIST SACPRIM_GDPGEN
# ifdef __STDC__
(MASSTOR_LIST ML, INTEGER KL)
# else
(ML, KL)
MASSTOR_LIST ML;
INTEGER KL;
# endif
{
  struct S_2 P;
  MASSTOR_LIST RL4, RL6, QLB, MLB, JL, MLS, L, PL, J1Y, ML1, ML2, HL, DL, SL, QL, RL;
  INTEGER i;

  RL = MASELEM_MASREM(ML, 4);
  J1Y = ML + 3;
  ML1 = J1Y - RL;
  J1Y = (MASSTOR_LIST)(4 * KL);
  J1Y = ML1 + J1Y;
  ML2 = J1Y - 4;
  if (KL > 1000) {
    KL = 1000;
    MASERR_ERROR(MASERR_severe, "in GDPGEN, only 4*1000 numbers checked.", 39L);
  }
  {
    LONGINT B_5 = 1, B_6 = KL;

    if (B_5 <= B_6)
      for (i = B_5;; i += 1) {
        P.A[i - 1] = TRUE;
        if (i >= B_6) break;
      }
  }
  DL = 3;
  RL4 = 3;
  RL6 = 3;
  for (;;) {
    QLB = ML2 / DL;
    if (DL > QLB) {
      goto EXIT_3;
    }
    MLB = QLB * DL;
    RL = MASELEM_MASREM(MLB, 4);
    if (RL == 3) {
      JL = 0;
    } else {
      if (RL4 == 1) {
        JL = RL + 1;
      } else {
        JL = 3 - RL;
      }
    }
    J1Y = JL * DL;
    MLS = MLB - J1Y;
    J1Y = MLS - ML1;
    J1Y = J1Y / 4;
    i = (INTEGER)J1Y + 1;
    QL = QLB - JL;
    while (i > 0 && QL > 1) {
      P.A[i - 1] = FALSE;
      i = i - (INTEGER)DL;
      QL = QL - 4;
    }
    if (RL6 == 1) {
      DL = DL + 4;
      RL6 = 5;
    } else {
      DL = DL + 2;
      if (RL4 == 3) {
        RL4 = 1;
      } else {
        RL4 = 3;
      }
      if (RL6 == 5) {
        RL6 = 1;
      } else {
        RL6 = RL6 + 2;
      }
    }
  } EXIT_3:;
  L = MASSTOR_SIL;
  PL = ML2;
  for (i = KL; i >= 1; i += -1) {
    if (P.A[i - 1]) {
      L = MASSTOR_COMP(PL, L);
    }
    PL = PL - 4;
  }
  return L;
}

MASSTOR_LIST SACPRIM_IFACT
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST AL, BL, CL, F, FP, J1Y, ML, MLP, PL, RL, SL, TL;

  SACPRIM_ISPD(NL, &F, &ML);
  if (ML == 1) {
    return F;
  }
  F = MASSTOR_INV(F);
  AL = 1000;
  do {
    if (ML < MASSTOR_BETA) {
      MLP = ML - 1;
      RL = SACM_MDEXP(ML, 3, MLP);
    } else {
      MLP = SACI_IDIF(ML, 1);
      RL = SACM_MIEXP(ML, 3, MLP);
    }
    if (RL == 1) {
      FP = SACPRIM_IFACT(MLP);
      SL = SACPRIM_ISPT(ML, MLP, FP);
      if (SL == 1) {
        F = MASSTOR_COMP(ML, F);
        F = MASSTOR_INV(F);
        return F;
      }
    }
    SACI_ISQRT(ML, &CL, &TL);
    J1Y = SACI_IDQ(CL, 3);
    BL = SACI_IMAX(5000, J1Y);
    if (SACI_ICOMP(AL, BL) > 0) {
      PL = 1;
    } else {
      SACPRIM_IMPDS(ML, AL, BL, &PL, &ML);
      if (PL != 1) {
        AL = PL;
        F = MASSTOR_COMP(PL, F);
      }
    }
  } while (!(PL == 1));
  AL = BL;
  BL = CL;
  SACPRIM_ILPDS(ML, AL, BL, &PL, &ML);
  if (PL != 1) {
    F = MASSTOR_COMP(PL, F);
  }
  F = MASSTOR_COMP(ML, F);
  F = MASSTOR_INV(F);
  return F;
}

void SACPRIM_ILPDS
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *PL, MASSTOR_LIST *NLP)
# else
(NL, AL, BL, PL, NLP)
MASSTOR_LIST NL, AL, BL;
MASSTOR_LIST *PL, *NLP;
# endif
{
  MASSTOR_LIST J1Y, L, LP, ML, QL, RL, RL1, RL2, SL, TL, XL, XL1, XL2, YL, YLP;

  SACI_IQR(NL, BL, &QL, &RL);
  XL1 = SACI_ISUM(BL, QL);
  SACI_IDQR(XL1, 2, &XL1, &SL);
  if (RL != 0 || SL != 0) {
    XL1 = SACI_ISUM(XL1, 1);
  }
  QL = SACI_IQ(NL, AL);
  XL2 = SACI_ISUM(AL, QL);
  XL2 = SACI_IDQ(XL2, 2);
  SACPRIM_FRESL(NL, &ML, &L);
  L = SACSET_LBIBMS(L);
  L = MASSTOR_INV(L);
  RL = SACI_IDREM(XL2, ML);
  LP = L;
  while (LP != MASSTOR_SIL && RL < MASSTOR_FIRST(LP)) {
    LP = MASSTOR_RED(LP);
  }
  if (LP == MASSTOR_SIL) {
    LP = L;
    SL = ML;
  } else {
    SL = 0;
  }
  MASSTOR_ADV(LP, &RL1, &LP);
  J1Y = SL + RL;
  SL = J1Y - RL1;
  XL = SACI_IDIF(XL2, SL);
  while (SACI_ICOMP(XL, XL1) >= 0) {
    J1Y = SACI_IPROD(XL, XL);
    YLP = SACI_IDIF(J1Y, NL);
    SACI_ISQRT(YLP, &YL, &TL);
    if (TL == 0) {
      *PL = SACI_IDIF(XL, YL);
      *NLP = SACI_ISUM(XL, YL);
      return;
    }
    if (LP != MASSTOR_SIL) {
      MASSTOR_ADV(LP, &RL2, &LP);
      SL = RL1 - RL2;
    } else {
      MASSTOR_ADV(L, &RL2, &LP);
      J1Y = ML + RL1;
      SL = J1Y - RL2;
    }
    RL1 = RL2;
    XL = SACI_IDIF(XL, SL);
  }
  *PL = 1;
  *NLP = NL;
  return;
}

void SACPRIM_IMPDS
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *PL, MASSTOR_LIST *QL)
# else
(NL, AL, BL, PL, QL)
MASSTOR_LIST NL, AL, BL;
MASSTOR_LIST *PL, *QL;
# endif
{
  MASSTOR_LIST J1Y, LP, PLP, RL, RL1, RL2;

  RL = SACI_IDREM(AL, 210);
  LP = SACPRIM_UZ210;
  while (RL > MASSTOR_FIRST(LP)) {
    LP = MASSTOR_RED(LP);
  }
  RL1 = MASSTOR_FIRST(LP);
  J1Y = RL1 - RL;
  *PL = SACI_ISUM(AL, J1Y);
  while (SACI_ICOMP(*PL, BL) <= 0) {
    if (*PL < MASSTOR_BETA) {
      SACI_IDQR(NL, *PL, QL, &RL);
    } else {
      SACI_IQR(NL, *PL, QL, &RL);
    }
    if (RL == 0) {
      return;
    }
    LP = MASSTOR_RED(LP);
    if (LP == MASSTOR_SIL) {
      LP = SACPRIM_UZ210;
      RL2 = RL1 - 210;
    } else {
      RL2 = RL1;
    }
    RL1 = MASSTOR_FIRST(LP);
    if (*PL < MASSTOR_BETA) {
      J1Y = *PL + RL1;
      PLP = J1Y - RL2;
      if (PLP >= MASSTOR_BETA) {
        J1Y = PLP - MASSTOR_BETA;
        *PL = SACLIST_LIST2(J1Y, 1);
      } else {
        *PL = PLP;
      }
    } else {
      J1Y = RL1 - RL2;
      *PL = SACI_ISUM(*PL, J1Y);
    }
  }
  *PL = 1;
  *QL = NL;
  return;
}

void SACPRIM_ISPD
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST *F, MASSTOR_LIST *ML)
# else
(NL, F, ML)
MASSTOR_LIST NL;
MASSTOR_LIST *F, *ML;
# endif
{
  MASSTOR_LIST LP, PL, QL, RL;

  *F = MASSTOR_BETA;
  *ML = NL;
  LP = SACPRIM_SMPRM;
  do {
    PL = MASSTOR_FIRST(LP);
    if (*ML < MASSTOR_BETA) {
      MASELEM_MASQREM(*ML, PL, &QL, &RL);
    } else {
      SACI_IDQR(*ML, PL, &QL, &RL);
    }
    if (RL == 0) {
      *F = MASSTOR_COMP(PL, *F);
      *ML = QL;
    } else {
      LP = MASSTOR_RED(LP);
    }
  } while (!(QL <= PL || LP == MASSTOR_SIL));
  if (QL <= PL && *ML != 1) {
    *F = MASSTOR_COMP(*ML, *F);
    *ML = 1;
  }
  *F = MASSTOR_INV(*F);
  return;
}

MASSTOR_LIST SACPRIM_ISPT
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST MLP, MASSTOR_LIST F)
# else
(ML, MLP, F)
MASSTOR_LIST ML, MLP, F;
# endif
{
  MASSTOR_LIST AL, BL, FP, MLPP, PL, PL1, PP, QL, QL1, SL;

  FP = F;
  QL1 = 1;
  PL1 = 1;
  for (;;) {
    do {
      if (FP == MASSTOR_SIL) {
        SL = 1;
        return SL;
      }
      MASSTOR_ADV(FP, &QL, &FP);
    } while (!(SACI_ICOMP(QL, QL1) > 0));
    QL1 = QL;
    PP = SACPRIM_SMPRM;
    do {
      if (PP == MASSTOR_SIL) {
        SL = 0;
        return SL;
      }
      MASSTOR_ADV(PP, &PL, &PP);
      if (PL > PL1) {
        PL1 = PL;
        AL = SACM_MIEXP(ML, PL, MLP);
        if (AL != 1) {
          SL = -1;
          return SL;
        }
      }
      MLPP = SACI_IQ(MLP, QL);
      BL = SACM_MIEXP(ML, PL, MLPP);
    } while (!(BL != 1));
  } EXIT_4:;
  return SL;
}

void BEGIN_SACPRIM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_SACSET();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACM();

    MASSTOR_LISTVAR(&SACPRIM_SMPRM);
    MASSTOR_LISTVAR(&SACPRIM_UZ210);
    SACPRIM_SMPRM = SACPRIM_DPGEN(1, 500);
    SACPRIM_UZ210 = MASSTOR_SIL;
    for (IL = 209; IL >= 1; IL += -2) {
      if (SACD_DGCD(210, IL) == 1) {
        SACPRIM_UZ210 = MASSTOR_COMP(IL, SACPRIM_UZ210);
      }
    }
  }
}
