#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
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

CHAR SACMPOL_rcsid [] = "$Id: SACMPOL.md,v 1.2 1992/02/12 17:33:59 pesch Exp $";
CHAR SACMPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACMPOL.mi,v 1.3 1992/10/15 16:28:42 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACMPOL_MIPDIF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_167_A, MASSTOR_LIST B)
# else
(RL, M, C_167_A, B)
MASSTOR_LIST RL, M, C_167_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP;

  if (C_167_A == 0) {
    C = SACMPOL_MIPNEG(RL, M, B);
    return C;
  }
  if (B == 0) {
    C = C_167_A;
    return C;
  }
  if (RL == 0) {
    C = SACM_MIDIF(M, C_167_A, B);
    return C;
  }
  AP = C_167_A;
  BP = B;
  CP = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    EL = MASSTOR_FIRST(AP);
    FL = MASSTOR_FIRST(BP);
    if (EL > FL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      CP = SACLIST_COMP2(AL, EL, CP);
    } else {
      if (EL < FL) {
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MINEG(M, BL);
        } else {
          CL = SACMPOL_MIPNEG(RLP, M, BL);
        }
        CP = SACLIST_COMP2(CL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MIDIF(M, AL, BL);
        } else {
          CL = SACMPOL_MIPDIF(RLP, M, AL, BL);
        }
        if (CL != 0) {
          CP = SACLIST_COMP2(CL, EL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    CPP = MASSTOR_BETA;
  } else {
    if (AP == MASSTOR_SIL) {
      CPP = SACMPOL_MIPNEG(RL, M, BP);
    } else {
      CPP = AP;
    }
  }
  C = MASSTOR_INV(CP);
  if (C == MASSTOR_SIL) {
    C = CPP;
  } else {
    MASSTOR_SRED(CP, CPP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACMPOL_MIPFSM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_166_A)
# else
(RL, M, C_166_A)
MASSTOR_LIST RL, M, C_166_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_166_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    if (SACI_ISIGNF(C_166_A) < 0) {
      B = SACI_ISUM(M, C_166_A);
    } else {
      B = C_166_A;
    }
    return B;
  }
  AP = C_166_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACMPOL_MIPFSM(RLP, M, AL);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACMPOL_MIPHOM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_165_A)
# else
(RL, M, C_165_A)
MASSTOR_LIST RL, M, C_165_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_165_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACM_MIHOM(M, C_165_A);
    return B;
  }
  AP = C_165_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACM_MIHOM(M, AL);
    } else {
      BL = SACMPOL_MIPHOM(RLP, M, AL);
    }
    if (BL != 0) {
      B = SACLIST_COMP2(BL, EL, B);
    }
  } while (!(AP == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACMPOL_MIPIPR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C_164_A, MASSTOR_LIST B)
# else
(RL, M, D, C_164_A, B)
MASSTOR_LIST RL, M, D, C_164_A, B;
# endif
{
  MASSTOR_LIST C, CP;

  CP = SACIPOL_IPIPR(RL, D, C_164_A, B);
  C = SACMPOL_MIPHOM(RL, M, CP);
  return C;
}

MASSTOR_LIST SACMPOL_MIPNEG
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_163_A)
# else
(RL, M, C_163_A)
MASSTOR_LIST RL, M, C_163_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_163_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACM_MINEG(M, C_163_A);
    return B;
  }
  AP = C_163_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACM_MINEG(M, AL);
    } else {
      BL = SACMPOL_MIPNEG(RLP, M, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACMPOL_MIPPR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_162_A, MASSTOR_LIST B)
# else
(RL, M, C_162_A, B)
MASSTOR_LIST RL, M, C_162_A, B;
# endif
{
  MASSTOR_LIST C, J1Y;

  J1Y = SACIPOL_IPPROD(RL, C_162_A, B);
  C = SACMPOL_MIPHOM(RL, M, J1Y);
  return C;
}

MASSTOR_LIST SACMPOL_MIPRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST QL, MASSTOR_LIST N)
# else
(RL, M, QL, N)
MASSTOR_LIST RL, M, QL, N;
# endif
{
  MASSTOR_LIST C_161_A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL;

  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLS, &TL);
  if (RL == 0) {
    DL = SACD_DRANN();
    if (DL < QLS) {
      C_161_A = SACM_MIRAN(M);
    } else {
      C_161_A = 0;
    }
    return C_161_A;
  }
  RLP = RL - 1;
  MASSTOR_ADV(N, &NL, &NP);
  C_161_A = MASSTOR_BETA;
  {
    LONGINT B_1 = 0, B_2 = NL;

    if (B_1 <= B_2)
      for (EL = B_1;; EL += 1) {
        if (RLP == 0) {
          DL = SACD_DRANN();
          if (DL < QLS) {
            AL = SACM_MIRAN(M);
          } else {
            AL = 0;
          }
        } else {
          AL = SACMPOL_MIPRAN(RLP, M, QL, NP);
        }
        if (AL != 0) {
          C_161_A = SACLIST_COMP2(EL, AL, C_161_A);
        }
        if (EL >= B_2) break;
      }
  }
  if (C_161_A == MASSTOR_SIL) {
    C_161_A = 0;
  }
  return C_161_A;
}

MASSTOR_LIST SACMPOL_MIPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_160_A, MASSTOR_LIST B)
# else
(RL, M, C_160_A, B)
MASSTOR_LIST RL, M, C_160_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, EL, FL, RLP;

  if (C_160_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_160_A;
    return C;
  }
  if (RL == 0) {
    C = SACM_MISUM(M, C_160_A, B);
    return C;
  }
  AP = C_160_A;
  BP = B;
  CP = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    EL = MASSTOR_FIRST(AP);
    FL = MASSTOR_FIRST(BP);
    if (EL > FL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      CP = SACLIST_COMP2(AL, EL, CP);
    } else {
      if (EL < FL) {
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        CP = SACLIST_COMP2(BL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MISUM(M, AL, BL);
        } else {
          CL = SACMPOL_MIPSUM(RLP, M, AL, BL);
        }
        if (CL != 0) {
          CP = SACLIST_COMP2(CL, EL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    AP = BP;
  }
  if (CP == MASSTOR_SIL) {
    C = AP;
  } else {
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CP, AP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

void SACMPOL_MIUPQR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_159_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(M, C_159_A, B, Q, R)
MASSTOR_LIST M, C_159_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BLP, BP, DL, ML, NL, Q1, QL, QP, RP;

  NL = SACPOL_PDEG(B);
  BL = SACPOL_PLDCF(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_159_A;
  BLP = SACM_MIINV(M, BL);
  while (*R != 0) {
    ML = SACPOL_PDEG(*R);
    DL = ML - NL;
    if (DL < 0) {
      if (*Q == MASSTOR_SIL) {
        *Q = 0;
      } else {
        *Q = MASSTOR_INV(*Q);
      }
      return;
    }
    AL = SACPOL_PLDCF(*R);
    QL = SACM_MIPROD(M, AL, BLP);
    *Q = SACLIST_COMP2(QL, DL, *Q);
    Q1 = SACLIST_LIST2(DL, QL);
    RP = SACPOL_PRED(*R);
    QP = SACMPOL_MIPPR(1, M, BP, Q1);
    *R = SACMPOL_MIPDIF(1, M, RP, QP);
  }
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

void SACMPOL_MMPIQR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST D, MASSTOR_LIST C_158_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(RL, M, D, C_158_A, B, Q, R)
MASSTOR_LIST RL, M, D, C_158_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BP, DL, ML, NL, Q1, QP, RP;

  NL = SACPOL_PDEG(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_158_A;
  while (*R != 0) {
    ML = SACPOL_PDEG(*R);
    DL = ML - NL;
    if (DL < 0) {
      if (*Q == MASSTOR_SIL) {
        *Q = 0;
      } else {
        *Q = MASSTOR_INV(*Q);
      }
      return;
    }
    AL = SACPOL_PLDCF(*R);
    *Q = SACLIST_COMP2(AL, DL, *Q);
    Q1 = SACLIST_LIST2(DL, AL);
    RP = SACPOL_PRED(*R);
    QP = SACMPOL_MIPIPR(RL, M, D, BP, Q1);
    *R = SACMPOL_MIPDIF(RL, M, RP, QP);
  }
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST SACMPOL_MPDIF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_157_A, MASSTOR_LIST B)
# else
(RL, ML, C_157_A, B)
MASSTOR_LIST RL, ML, C_157_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP;

  if (C_157_A == 0) {
    C = SACMPOL_MPNEG(RL, ML, B);
    return C;
  }
  if (B == 0) {
    C = C_157_A;
    return C;
  }
  AP = C_157_A;
  BP = B;
  CP = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    EL = MASSTOR_FIRST(AP);
    FL = MASSTOR_FIRST(BP);
    if (EL > FL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      CP = SACLIST_COMP2(AL, EL, CP);
    } else {
      if (EL < FL) {
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MDNEG(ML, BL);
        } else {
          CL = SACMPOL_MPNEG(RLP, ML, BL);
        }
        CP = SACLIST_COMP2(CL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MDDIF(ML, AL, BL);
        } else {
          CL = SACMPOL_MPDIF(RLP, ML, AL, BL);
        }
        if (CL != 0) {
          CP = SACLIST_COMP2(CL, EL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    CPP = MASSTOR_BETA;
  } else {
    if (AP == MASSTOR_SIL) {
      CPP = SACMPOL_MPNEG(RL, ML, BP);
    } else {
      CPP = AP;
    }
  }
  C = MASSTOR_INV(CP);
  if (C == MASSTOR_SIL) {
    C = CPP;
  } else {
    MASSTOR_SRED(CP, CPP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACMPOL_MPEMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_156_A, MASSTOR_LIST AL)
# else
(RL, ML, C_156_A, AL)
MASSTOR_LIST RL, ML, C_156_A, AL;
# endif
{
  MASSTOR_LIST AL1, AP, B, EL1, EL2, IL, RLP;

  if (C_156_A == 0) {
    B = 0;
    return B;
  }
  MASSTOR_ADV(C_156_A, &EL1, &AP);
  B = 0;
  RLP = RL - 1;
  do {
    MASSTOR_ADV(AP, &AL1, &AP);
    if (RLP == 0) {
      B = SACM_MDSUM(ML, B, AL1);
    } else {
      B = SACMPOL_MPSUM(RLP, ML, B, AL1);
    }
    if (AP != MASSTOR_SIL) {
      MASSTOR_ADV(AP, &EL2, &AP);
    } else {
      EL2 = 0;
    }
    {
      LONGINT B_3 = 1, B_4 = EL1 - EL2;

      if (B_3 <= B_4)
        for (IL = B_3;; IL += 1) {
          if (RLP == 0) {
            B = SACM_MDPROD(ML, AL, B);
          } else {
            B = SACMPOL_MPMDP(RLP, ML, AL, B);
          }
          if (IL >= B_4) break;
        }
    }
    EL1 = EL2;
  } while (!(AP == MASSTOR_SIL));
  return B;
}

MASSTOR_LIST SACMPOL_MPEVAL
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_155_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(RL, ML, C_155_A, IL, AL)
MASSTOR_LIST RL, ML, C_155_A, IL, AL;
# endif
{
  MASSTOR_LIST A1, AP, B, B1, EL1, RLP;

  if (C_155_A == 0) {
    B = 0;
    return B;
  }
  if (IL == RL) {
    B = SACMPOL_MPEMV(RL, ML, C_155_A, AL);
    return B;
  }
  RLP = RL - 1;
  AP = C_155_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL1, &A1, &AP);
    B1 = SACMPOL_MPEVAL(RLP, ML, A1, IL, AL);
    if (B1 != 0) {
      B = SACLIST_COMP2(B1, EL1, B);
    }
  } while (!(AP == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACMPOL_MPEXP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_154_A, MASSTOR_LIST NL)
# else
(RL, ML, C_154_A, NL)
MASSTOR_LIST RL, ML, C_154_A, NL;
# endif
{
  MASSTOR_LIST B, IL;

  if (NL == 0) {
    B = SACPOL_PINV(0, 1, RL);
    return B;
  }
  if (C_154_A == 0) {
    B = 0;
    return B;
  }
  B = C_154_A;
  {
    LONGINT B_5 = 1, B_6 = NL - 1;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        B = SACMPOL_MPPROD(RL, ML, B, C_154_A);
        if (IL >= B_6) break;
      }
  }
  return B;
}

MASSTOR_LIST SACMPOL_MPHOM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_153_A)
# else
(RL, ML, C_153_A)
MASSTOR_LIST RL, ML, C_153_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_153_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACM_MDHOM(ML, C_153_A);
    return B;
  }
  RLP = RL - 1;
  AP = C_153_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACM_MDHOM(ML, AL);
    } else {
      BL = SACMPOL_MPHOM(RLP, ML, AL);
    }
    if (BL != 0) {
      B = SACLIST_COMP2(BL, EL, B);
    }
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

MASSTOR_LIST SACMPOL_MPINT
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST B, MASSTOR_LIST BL, MASSTOR_LIST BLP, MASSTOR_LIST RL, MASSTOR_LIST C_152_A, MASSTOR_LIST A1)
# else
(PL, B, BL, BLP, RL, C_152_A, A1)
MASSTOR_LIST PL, B, BL, BLP, RL, C_152_A, A1;
# endif
{
  MASSTOR_LIST AL, AL1, ALS, AP, AP1, AS, CL, DL, EL, EL1, ELS, J1Y, NL, RLP;

  NL = SACPOL_PDEG(B);
  if (NL == 0) {
    J1Y = RL - 1;
    AS = SACPOL_PINV(J1Y, A1, 1);
    return AS;
  }
  if (RL == 1) {
    AL = SACMPOL_MPEMV(1, PL, C_152_A, BL);
    DL = SACM_MDDIF(PL, A1, AL);
    if (DL == 0) {
      AS = C_152_A;
    } else {
      CL = SACM_MDPROD(PL, DL, BLP);
      J1Y = SACMPOL_MPMDP(1, PL, CL, B);
      AS = SACMPOL_MPSUM(1, PL, J1Y, C_152_A);
    }
    return AS;
  }
  AS = MASSTOR_BETA;
  RLP = RL - 1;
  if (C_152_A == 0) {
    AP = MASSTOR_BETA;
  } else {
    AP = C_152_A;
  }
  if (A1 == 0) {
    AP1 = MASSTOR_BETA;
  } else {
    AP1 = A1;
  }
  while (AP != MASSTOR_SIL || AP1 != MASSTOR_SIL) {
    if (AP == MASSTOR_SIL) {
      AL = 0;
      SACLIST_ADV2(AP1, &ELS, &AL1, &AP1);
    } else {
      if (AP1 == MASSTOR_SIL) {
        AL1 = 0;
        SACLIST_ADV2(AP, &ELS, &AL, &AP);
      } else {
        EL = MASSTOR_FIRST(AP);
        EL1 = MASSTOR_FIRST(AP1);
        ELS = MASELEM_MASMAX(EL, EL1);
        AL = 0;
        AL1 = 0;
        if (EL == ELS) {
          SACLIST_ADV2(AP, &EL, &AL, &AP);
        }
        if (EL1 == ELS) {
          SACLIST_ADV2(AP1, &EL1, &AL1, &AP1);
        }
      }
    }
    ALS = SACMPOL_MPINT(PL, B, BL, BLP, RLP, AL, AL1);
    AS = SACLIST_COMP2(ALS, ELS, AS);
  }
  if (AS == MASSTOR_SIL) {
    AS = 0;
  } else {
    AS = MASSTOR_INV(AS);
  }
  return AS;
}

MASSTOR_LIST SACMPOL_MPMDP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST AL, MASSTOR_LIST B)
# else
(RL, PL, AL, B)
MASSTOR_LIST RL, PL, AL, B;
# endif
{
  MASSTOR_LIST BL, BP, C, CL, EL, RLP;

  if (AL == 0 || B == 0) {
    C = 0;
    return C;
  }
  BP = B;
  C = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(BP, &EL, &BL, &BP);
    if (RLP == 0) {
      CL = SACM_MDPROD(PL, AL, BL);
    } else {
      CL = SACMPOL_MPMDP(RLP, PL, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(BP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACMPOL_MPMON
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_151_A)
# else
(RL, PL, C_151_A)
MASSTOR_LIST RL, PL, C_151_A;
# endif
{
  MASSTOR_LIST AL, ALP, AP;

  if (C_151_A == 0) {
    AP = 0;
    return AP;
  }
  AL = SACPOL_PLBCF(RL, C_151_A);
  ALP = SACM_MDINV(PL, AL);
  AP = SACMPOL_MPMDP(RL, PL, ALP, C_151_A);
  return AP;
}

MASSTOR_LIST SACMPOL_MPNEG
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_150_A)
# else
(RL, ML, C_150_A)
MASSTOR_LIST RL, ML, C_150_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_150_A == 0) {
    B = 0;
    return B;
  }
  AP = C_150_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACM_MDNEG(ML, AL);
    } else {
      BL = SACMPOL_MPNEG(RLP, ML, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACMPOL_MPPROD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_149_A, MASSTOR_LIST B)
# else
(RL, ML, C_149_A, B)
MASSTOR_LIST RL, ML, C_149_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP;

  if (C_149_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACM_MDPROD(ML, C_149_A, B);
    return C;
  }
  AS = SACLIST_CINV(C_149_A);
  BS = SACLIST_CINV(B);
  C = 0;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(BS, &BL, &FL, &BS);
    AP = AS;
    C1 = MASSTOR_BETA;
    do {
      SACLIST_ADV2(AP, &AL, &EL, &AP);
      if (RLP == 0) {
        CL = SACM_MDPROD(ML, AL, BL);
      } else {
        CL = SACMPOL_MPPROD(RLP, ML, AL, BL);
      }
      if (CL != 0) {
        J1Y = EL + FL;
        C1 = SACLIST_COMP2(J1Y, CL, C1);
      }
    } while (!(AP == MASSTOR_SIL));
    if (C1 != MASSTOR_SIL) {
      C = SACMPOL_MPSUM(RL, ML, C, C1);
    }
  } while (!(BS == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST SACMPOL_MPPSR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_148_A, MASSTOR_LIST B)
# else
(RL, PL, C_148_A, B)
MASSTOR_LIST RL, PL, C_148_A, B;
# endif
{
  MASSTOR_LIST B1, BB, BS, C, C1, CL, IL, J1Y, LL, ML, NL;

  NL = SACPOL_PDEG(B);
  if (NL == 0) {
    C = 0;
    return C;
  }
  ML = SACPOL_PDEG(C_148_A);
  C = C_148_A;
  BB = SACPOL_PRED(B);
  J1Y = SACPOL_PLDCF(B);
  B1 = SACLIST_LIST2(0, J1Y);
  {
    LONGINT B_7 = ML, B_8 = NL;

    if (B_7 >= B_8)
      for (IL = B_7;; IL += -1) {
        if (C == 0) {
          return C;
        }
        LL = SACPOL_PDEG(C);
        if (LL == IL) {
          CL = SACPOL_PLDCF(C);
          C = SACPOL_PRED(C);
          C = SACMPOL_MPPROD(RL, PL, C, B1);
          J1Y = LL - NL;
          C1 = SACLIST_LIST2(J1Y, CL);
          BS = SACMPOL_MPPROD(RL, PL, BB, C1);
          C = SACMPOL_MPDIF(RL, PL, C, BS);
        } else {
          C = SACMPOL_MPPROD(RL, PL, C, B1);
        }
        if (IL <= B_8) break;
      }
  }
  return C;
}

MASSTOR_LIST SACMPOL_MPQ
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_147_A, MASSTOR_LIST B)
# else
(RL, PL, C_147_A, B)
MASSTOR_LIST RL, PL, C_147_A, B;
# endif
{
  MASSTOR_LIST C, R;

  if (RL == 0) {
    C = SACM_MDQ(PL, C_147_A, B);
  } else {
    SACMPOL_MPQR(RL, PL, C_147_A, B, &C, &R);
  }
  return C;
}

void SACMPOL_MPQR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_146_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(RL, PL, C_146_A, B, Q, R)
MASSTOR_LIST RL, PL, C_146_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL;

  NL = SACPOL_PDEG(B);
  BL = SACPOL_PLDCF(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_146_A;
  RLP = RL - 1;
  while (*R != 0) {
    ML = SACPOL_PDEG(*R);
    DL = ML - NL;
    if (DL < 0) {
      if (*Q == MASSTOR_SIL) {
        *Q = 0;
      } else {
        *Q = MASSTOR_INV(*Q);
      }
      return;
    }
    AL = SACPOL_PLDCF(*R);
    if (RLP == 0) {
      QL = SACM_MDQ(PL, AL, BL);
      SL = 0;
    } else {
      SACMPOL_MPQR(RLP, PL, AL, BL, &QL, &SL);
    }
    if (SL != 0) {
      if (*Q == MASSTOR_SIL) {
        *Q = 0;
      } else {
        *Q = MASSTOR_INV(*Q);
      }
      return;
    }
    *Q = SACLIST_COMP2(QL, DL, *Q);
    Q1 = SACLIST_LIST2(DL, QL);
    RP = SACPOL_PRED(*R);
    QP = SACMPOL_MPPROD(RL, PL, BP, Q1);
    *R = SACMPOL_MPDIF(RL, PL, RP, QP);
  }
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST SACMPOL_MPRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST QL, MASSTOR_LIST N)
# else
(RL, ML, QL, N)
MASSTOR_LIST RL, ML, QL, N;
# endif
{
  MASSTOR_LIST C_145_A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL;

  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLS, &TL);
  if (RL == 0) {
    DL = SACD_DRANN();
    if (DL < QLS) {
      C_145_A = SACM_MDRAN(ML);
    } else {
      C_145_A = 0;
    }
    return C_145_A;
  }
  RLP = RL - 1;
  MASSTOR_ADV(N, &NL, &NP);
  C_145_A = MASSTOR_BETA;
  {
    LONGINT B_9 = 0, B_10 = NL;

    if (B_9 <= B_10)
      for (EL = B_9;; EL += 1) {
        if (RLP == 0) {
          DL = SACD_DRANN();
          if (DL < QLS) {
            AL = SACM_MDRAN(ML);
          } else {
            AL = 0;
          }
        } else {
          AL = SACMPOL_MPRAN(RLP, ML, QL, NP);
        }
        if (AL != 0) {
          C_145_A = SACLIST_COMP2(EL, AL, C_145_A);
        }
        if (EL >= B_10) break;
      }
  }
  if (C_145_A == MASSTOR_SIL) {
    C_145_A = 0;
  }
  return C_145_A;
}

MASSTOR_LIST SACMPOL_MPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_144_A, MASSTOR_LIST B)
# else
(RL, ML, C_144_A, B)
MASSTOR_LIST RL, ML, C_144_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, EL, FL, RLP;

  if (C_144_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_144_A;
    return C;
  }
  AP = C_144_A;
  BP = B;
  CP = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    EL = MASSTOR_FIRST(AP);
    FL = MASSTOR_FIRST(BP);
    if (EL > FL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      CP = SACLIST_COMP2(AL, EL, CP);
    } else {
      if (EL < FL) {
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        CP = SACLIST_COMP2(BL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACM_MDSUM(ML, AL, BL);
        } else {
          CL = SACMPOL_MPSUM(RLP, ML, AL, BL);
        }
        if (CL != 0) {
          CP = SACLIST_COMP2(CL, EL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    AP = BP;
  }
  if (CP == MASSTOR_SIL) {
    C = AP;
  } else {
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CP, AP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACMPOL_MPUP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST CL, MASSTOR_LIST C_143_A)
# else
(RL, ML, CL, C_143_A)
MASSTOR_LIST RL, ML, CL, C_143_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (CL == 0 || C_143_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 1) {
    B = SACMPOL_MPPROD(RL, ML, CL, C_143_A);
    return B;
  }
  RLP = RL - 1;
  AP = C_143_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACMPOL_MPUP(RLP, ML, CL, AL);
    if (BL != 0) {
      B = SACLIST_COMP2(BL, EL, B);
    }
  } while (!(AP == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACMPOL_MPUQ
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST PL, MASSTOR_LIST C_142_A, MASSTOR_LIST BL)
# else
(RL, PL, C_142_A, BL)
MASSTOR_LIST RL, PL, C_142_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, EL, RLP;

  if (C_142_A == 0) {
    C = 0;
    return C;
  }
  AP = C_142_A;
  RLP = RL - 1;
  C = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 1) {
      CL = SACMPOL_MPQ(RLP, PL, AL, BL);
    } else {
      CL = SACMPOL_MPUQ(RLP, PL, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACMPOL_MUPDER
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST C_141_A)
# else
(ML, C_141_A)
MASSTOR_LIST ML, C_141_A;
# endif
{
  MASSTOR_LIST AL, AP, B, EL;

  if (C_141_A == 0) {
    B = 0;
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_141_A;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    AL = SACM_MDPROD(ML, EL, AL);
    if (AL != 0) {
      EL = EL - 1;
      B = SACLIST_COMP2(AL, EL, B);
    }
  } while (!(AP == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST SACMPOL_MUPRAN
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST NL)
# else
(PL, NL)
MASSTOR_LIST PL, NL;
# endif
{
  MASSTOR_LIST C_140_A, AL, IL, J1Y;

  C_140_A = MASSTOR_BETA;
  {
    LONGINT B_11 = 0, B_12 = NL - 1;

    if (B_11 <= B_12)
      for (IL = B_11;; IL += 1) {
        AL = SACM_MDRAN(PL);
        if (AL != 0) {
          C_140_A = SACLIST_COMP2(IL, AL, C_140_A);
        }
        if (IL >= B_12) break;
      }
  }
  J1Y = PL - 1;
  J1Y = SACM_MDRAN(J1Y);
  AL = J1Y + 1;
  C_140_A = SACLIST_COMP2(NL, AL, C_140_A);
  return C_140_A;
}

MASSTOR_LIST SACMPOL_SMFMIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_139_A)
# else
(RL, M, C_139_A)
MASSTOR_LIST RL, M, C_139_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_139_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACM_SMFMI(M, C_139_A);
    return B;
  }
  AP = C_139_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACM_SMFMI(M, AL);
    } else {
      BL = SACMPOL_SMFMIP(RLP, M, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACMPOL_VMPIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST ML, MASSTOR_LIST C_138_A, MASSTOR_LIST B)
# else
(RL, ML, C_138_A, B)
MASSTOR_LIST RL, ML, C_138_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, J1Y;

  CL = 0;
  if (C_138_A == 0 || B == 0) {
    return CL;
  }
  AP = C_138_A;
  BP = B;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(BP, &BL, &BP);
    if (RL == 0) {
      J1Y = SACM_MDPROD(ML, AL, BL);
      CL = SACM_MDSUM(ML, CL, J1Y);
    } else {
      J1Y = SACMPOL_MPPROD(RL, ML, AL, BL);
      CL = SACMPOL_MPSUM(RL, ML, CL, J1Y);
    }
  } while (!(AP == MASSTOR_SIL));
  return CL;
}

void BEGIN_SACMPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACD();
    BEGIN_SACM();
    BEGIN_SACI();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();

  }
}
