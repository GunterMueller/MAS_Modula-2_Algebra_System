#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
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

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACMPOL
#include "SACMPOL.h"
#endif

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACEXT2
#include "SACEXT2.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

#ifndef DEFINITION_SACEXT5
#include "SACEXT5.h"
#endif

#ifndef DEFINITION_SACEXT7
#include "SACEXT7.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACROOT
#include "SACROOT.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_SACANF
#include "SACANF.h"
#endif

#ifndef DEFINITION_SACUPFAC
#include "SACUPFAC.h"
#endif

#ifndef DEFINITION_SACEXT8
#include "SACEXT8.h"
#endif

CHAR SACEXT8_rcsid [] = "$Id: SACEXT8.md,v 1.3 1993/05/11 10:51:40 kredel Exp $";
CHAR SACEXT8_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT8.mi,v 1.4 1993/05/11 10:51:42 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT8_AFCOMP
# ifdef __STDC__
(MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(MB, I, AL, BL)
MASSTOR_LIST MB, I, AL, BL;
# endif
{
  MASSTOR_LIST CL, TL;

  CL = SACANF_AFDIF(AL, BL);
  TL = SACANF_AFSIGN(MB, I, CL);
  return TL;
}

MASSTOR_LIST SACEXT8_AFFINT
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST AL, R;

  R = SACRN_RNINT(M);
  AL = SACPOL_PMON(R, 0);
  return AL;
}

MASSTOR_LIST SACEXT8_AFFRN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST AL;

  AL = SACPOL_PMON(R, 0);
  return AL;
}

MASSTOR_LIST SACEXT8_AFPAFP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST B)
# else
(RL, M, AL, B)
MASSTOR_LIST RL, M, AL, B;
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
      CL = SACANF_AFPROD(M, AL, BL);
    } else {
      CL = SACEXT8_AFPAFP(RLP, M, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(BP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACEXT8_AFPAFQ
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_329_A, MASSTOR_LIST BL)
# else
(RL, M, C_329_A, BL)
MASSTOR_LIST RL, M, C_329_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, EL, RLP;

  if (C_329_A == 0) {
    C = 0;
    return C;
  }
  AP = C_329_A;
  RLP = RL - 1;
  C = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      CL = SACANF_AFQ(M, AL, BL);
    } else {
      CL = SACEXT8_AFPAFQ(RLP, M, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACEXT8_AFPDIF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_328_A, MASSTOR_LIST B)
# else
(RL, C_328_A, B)
MASSTOR_LIST RL, C_328_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP;

  if (C_328_A == 0) {
    C = SACEXT8_AFPNEG(RL, B);
    return C;
  }
  if (B == 0) {
    C = C_328_A;
    return C;
  }
  if (RL == 0) {
    C = SACANF_AFDIF(C_328_A, B);
    return C;
  }
  AP = C_328_A;
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
          CL = SACANF_AFNEG(BL);
        } else {
          CL = SACEXT8_AFPNEG(RLP, BL);
        }
        CP = SACLIST_COMP2(CL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACANF_AFDIF(AL, BL);
        } else {
          CL = SACEXT8_AFPDIF(RLP, AL, BL);
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
      CPP = SACEXT8_AFPNEG(RL, BP);
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

MASSTOR_LIST SACEXT8_AFPDMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_327_A)
# else
(RL, M, C_327_A)
MASSTOR_LIST RL, M, C_327_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, ELP, J1Y, RLP;

  if (C_327_A == 0) {
    B = 0;
    return B;
  }
  AP = C_327_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      J1Y = SACEXT8_AFFINT(EL);
      BL = SACANF_AFPROD(M, J1Y, AL);
    } else {
      J1Y = SACEXT8_AFFINT(EL);
      BL = SACEXT8_AFPAFP(RLP, M, J1Y, AL);
    }
    ELP = EL - 1;
    if (EL != 0) {
      B = SACLIST_COMP2(BL, ELP, B);
    }
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

MASSTOR_LIST SACEXT8_AFPEMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_326_A, MASSTOR_LIST AL)
# else
(RL, M, C_326_A, AL)
MASSTOR_LIST RL, M, C_326_A, AL;
# endif
{
  MASSTOR_LIST A2, AP, B, EL1, EL2, IL, RLP;

  if (C_326_A == 0) {
    B = 0;
    return B;
  }
  SACLIST_ADV2(C_326_A, &EL1, &B, &AP);
  RLP = RL - 1;
  while (AP != MASSTOR_SIL) {
    SACLIST_ADV2(AP, &EL2, &A2, &AP);
    {
      LONGINT B_1 = 1, B_2 = EL1 - EL2;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          if (RLP == 0) {
            B = SACANF_AFPROD(M, AL, B);
          } else {
            B = SACEXT8_AFPAFP(RLP, M, AL, B);
          }
          if (IL >= B_2) break;
        }
    }
    if (RLP == 0) {
      B = SACANF_AFSUM(B, A2);
    } else {
      B = SACEXT8_AFPSUM(RLP, B, A2);
    }
    EL1 = EL2;
  }
  {
    LONGINT B_3 = 1, B_4 = EL1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        if (RLP == 0) {
          B = SACANF_AFPROD(M, AL, B);
        } else {
          B = SACEXT8_AFPAFP(RLP, M, AL, B);
        }
        if (IL >= B_4) break;
      }
  }
  return B;
}

MASSTOR_LIST SACEXT8_AFPEV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_325_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(RL, M, C_325_A, IL, AL)
MASSTOR_LIST RL, M, C_325_A, IL, AL;
# endif
{
  MASSTOR_LIST A1, AP, B, B1, EL1, RLP;

  if (C_325_A == 0) {
    B = 0;
    return B;
  }
  if (IL == RL) {
    B = SACEXT8_AFPEMV(RL, M, C_325_A, AL);
    return B;
  }
  RLP = RL - 1;
  AP = C_325_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL1, &A1, &AP);
    B1 = SACEXT8_AFPEV(RLP, M, A1, IL, AL);
    if (B1 != 0) {
      B = SACLIST_COMP2(B1, EL1, B);
    }
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

MASSTOR_LIST SACEXT8_AFPFIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_324_A)
# else
(RL, C_324_A)
MASSTOR_LIST RL, C_324_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_324_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACEXT8_AFFINT(C_324_A);
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_324_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACEXT8_AFPFIP(RLP, AL);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT8_AFPFRP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_323_A)
# else
(RL, C_323_A)
MASSTOR_LIST RL, C_323_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_323_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACEXT8_AFFRN(C_323_A);
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_323_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACEXT8_AFPFRP(RLP, AL);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT8_AFPINT
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_322_A, MASSTOR_LIST BL)
# else
(RL, M, C_322_A, BL)
MASSTOR_LIST RL, M, C_322_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, B, CL, EL, J1Y, RLP;

  AP = C_322_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    EL = EL + 1;
    if (RL == 1) {
      J1Y = SACEXT8_AFFINT(EL);
      CL = SACANF_AFQ(M, AL, J1Y);
    } else {
      J1Y = SACEXT8_AFFINT(EL);
      CL = SACEXT8_AFPAFQ(RLP, M, AL, J1Y);
    }
    B = SACLIST_COMP2(CL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  if (BL != 0) {
    B = SACLIST_COMP2(BL, 0, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT8_AFPME
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_321_A, MASSTOR_LIST BL)
# else
(RL, M, C_321_A, BL)
MASSTOR_LIST RL, M, C_321_A, BL;
# endif
{
  MASSTOR_LIST B, BL1, BLP, IL, J1Y;

  IL = 0;
  BLP = BL;
  B = C_321_A;
  do {
    IL = IL + 1;
    MASSTOR_ADV(BLP, &BL1, &BLP);
    J1Y = RL - IL;
    J1Y = J1Y + 1;
    B = SACEXT8_AFPEV(J1Y, M, B, 1, BL1);
  } while (!(BLP == MASSTOR_SIL));
  return B;
}

MASSTOR_LIST SACEXT8_AFPMON
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_320_A)
# else
(RL, M, C_320_A)
MASSTOR_LIST RL, M, C_320_A;
# endif
{
  MASSTOR_LIST AL, ALP, AP;

  if (C_320_A == 0) {
    AP = 0;
    return AP;
  }
  AL = SACPOL_PLBCF(RL, C_320_A);
  ALP = SACANF_AFINV(M, AL);
  AP = SACEXT8_AFPAFP(RL, M, ALP, C_320_A);
  return AP;
}

void SACEXT8_AFPMPR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST B, MASSTOR_LIST J, MASSTOR_LIST L, MASSTOR_LIST *JS, MASSTOR_LIST *JL)
# else
(M, MB, I, B, J, L, JS, JL)
MASSTOR_LIST M, MB, I, B, J, L;
MASSTOR_LIST *JS, *JL;
# endif
{
  MASSTOR_LIST AL, BL, CL, JLP, L1, LP, SL, TL, VL, VLP;

  SACLIST_FIRST2(J, &AL, &BL);
  TL = SACEXT8_AFUPSR(M, MB, I, B, BL);
  for (;;) {
    if (TL == 0) {
      goto EXIT_1;
    }
    for (;;) {
      for (;;) {
        VL = 0;
        JLP = 0;
        LP = L;
        *JS = SACLIST_LIST2(AL, BL);
        do {
          MASSTOR_ADV(LP, &L1, &LP);
          JLP = JLP + 1;
          VLP = SACEXT7_IUPVOI(L1, *JS);
          if (VLP > 1) {
            goto EXIT_3;
          }
          if (VLP == 1) {
            if (VL == 1) {
              goto EXIT_3;
            } else {
              VL = 1;
              *JL = JLP;
            }
          }
        } while (!(LP == MASSTOR_SIL));
        return;
      } EXIT_3:;
      CL = SACROOT_RIB(AL, BL);
      SL = SACEXT8_AFUPSR(M, MB, I, B, CL);
      if (SL == 0) {
        BL = CL;
        goto EXIT_2;
      } else {
        if (SL * TL < 0) {
          AL = CL;
        } else {
          BL = CL;
          TL = SL;
        }
      }
    } EXIT_2:;
  } EXIT_1:;
  *JL = 0;
  *JS = SACLIST_LIST2(BL, BL);
  LP = L;
  do {
    MASSTOR_ADV(LP, &L1, &LP);
    *JL = *JL + 1;
    if (SACPOL_PDEG(L1) == 1) {
      if (SACIPOL_IUPBES(L1, BL) == 0) {
        return;
      }
    }
  } while (!FALSE);
}

MASSTOR_LIST SACEXT8_AFPNEG
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_319_A)
# else
(RL, C_319_A)
MASSTOR_LIST RL, C_319_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_319_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACANF_AFNEG(C_319_A);
    return B;
  }
  AP = C_319_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACANF_AFNEG(AL);
    } else {
      BL = SACEXT8_AFPNEG(RLP, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACEXT8_AFPNIP
# ifdef __STDC__
(MASSTOR_LIST MB, MASSTOR_LIST C_318_A)
# else
(MB, C_318_A)
MASSTOR_LIST MB, C_318_A;
# endif
{
  MASSTOR_LIST AP, C, CL, DL, J1Y, L, L1, LP, MP, SL;

  SACPGCD_IPSRP(2, C_318_A, &DL, &AP);
  J1Y = SACLIST_LIST2(2, 1);
  AP = DIPC_PPERMV(2, AP, J1Y);
  for (;;) {
    if (SACPOL_PDEG(AP) == 0) {
      C = SACPOL_PLDCF(AP);
      goto EXIT_4;
    }
    MP = SACPOL_PINV(1, MB, 1);
    C = SACPGCD_IPRES(2, AP, MP);
    goto EXIT_4;
  } EXIT_4:;
  SACPFAC_IPFAC(1, C, &SL, &CL, &LP);
  L = MASSTOR_BETA;
  do {
    MASSTOR_ADV(LP, &L1, &LP);
    J1Y = SACLIST_SECOND(L1);
    L = MASSTOR_COMP(J1Y, L);
  } while (!(LP == MASSTOR_SIL));
  L = MASSTOR_INV(L);
  return L;
}

MASSTOR_LIST SACEXT8_AFPPR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_317_A, MASSTOR_LIST B)
# else
(RL, M, C_317_A, B)
MASSTOR_LIST RL, M, C_317_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP;

  if (C_317_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACANF_AFPROD(M, C_317_A, B);
    return C;
  }
  AS = SACLIST_CINV(C_317_A);
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
        CL = SACANF_AFPROD(M, AL, BL);
      } else {
        CL = SACEXT8_AFPPR(RLP, M, AL, BL);
      }
      J1Y = EL + FL;
      C1 = SACLIST_COMP2(J1Y, CL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = SACEXT8_AFPSUM(RL, C, C1);
  } while (!(BS == MASSTOR_SIL));
  return C;
}

void SACEXT8_AFPQR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_316_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(RL, M, C_316_A, B, Q, R)
MASSTOR_LIST RL, M, C_316_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL;

  NL = SACPOL_PDEG(B);
  BL = SACPOL_PLDCF(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_316_A;
  RLP = RL - 1;
  for (;;) {
    while (*R != 0) {
      ML = SACPOL_PDEG(*R);
      DL = ML - NL;
      if (DL < 0) {
        goto EXIT_5;
      }
      AL = SACPOL_PLDCF(*R);
      if (RLP == 0) {
        QL = SACANF_AFQ(M, AL, BL);
        SL = 0;
      } else {
        SACEXT8_AFPQR(RLP, M, AL, BL, &QL, &SL);
      }
      if (SL != 0) {
        goto EXIT_5;
      }
      *Q = SACLIST_COMP2(QL, DL, *Q);
      Q1 = SACLIST_LIST2(DL, QL);
      RP = SACPOL_PRED(*R);
      QP = SACEXT8_AFPPR(RL, M, BP, Q1);
      *R = SACEXT8_AFPDIF(RL, RP, QP);
    }
    goto EXIT_5;
  } EXIT_5:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

void SACEXT8_AFPRLS
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST A1, MASSTOR_LIST A2, MASSTOR_LIST L1, MASSTOR_LIST L2, MASSTOR_LIST *LS1, MASSTOR_LIST *LS2)
# else
(M, MB, I, A1, A2, L1, L2, LS1, LS2)
MASSTOR_LIST M, MB, I, A1, A2, L1, L2;
MASSTOR_LIST *LS1, *LS2;
# endif
{
  MASSTOR_LIST I1, I2, LP1, LP2, ML1, ML2, SL;

  if (L1 == MASSTOR_SIL || L2 == MASSTOR_SIL) {
    *LS1 = L1;
    *LS2 = L2;
    return;
  }
  SACLIST_ADV2(L1, &I1, &ML1, &LP1);
  *LS1 = MASSTOR_BETA;
  SACLIST_ADV2(L2, &I2, &ML2, &LP2);
  *LS2 = MASSTOR_BETA;
  do {
    SACEXT8_AFPRRS(M, MB, I, A1, A2, I1, I2, &I1, &I2, &SL);
    if (SL < 0) {
      *LS1 = SACLIST_COMP2(ML1, I1, *LS1);
      if (LP1 != MASSTOR_SIL) {
        SACLIST_ADV2(LP1, &I1, &ML1, &LP1);
      } else {
        I1 = 0;
      }
    } else {
      *LS2 = SACLIST_COMP2(ML2, I2, *LS2);
      if (LP2 != MASSTOR_SIL) {
        SACLIST_ADV2(LP2, &I2, &ML2, &LP2);
      } else {
        I2 = 0;
      }
    }
  } while (!(I1 == 0 || I2 == 0));
  if (I1 == 0) {
    *LS2 = SACLIST_COMP2(ML2, I2, *LS2);
    while (LP2 != MASSTOR_SIL) {
      SACLIST_ADV2(LP2, &I2, &ML2, &LP2);
      *LS2 = SACLIST_COMP2(ML2, I2, *LS2);
    }
  } else {
    *LS1 = SACLIST_COMP2(ML1, I1, *LS1);
    while (LP1 != MASSTOR_SIL) {
      SACLIST_ADV2(LP1, &I1, &ML1, &LP1);
      *LS1 = SACLIST_COMP2(ML1, I1, *LS1);
    }
  }
  *LS1 = MASSTOR_INV(*LS1);
  *LS2 = MASSTOR_INV(*LS2);
  return;
}

MASSTOR_LIST SACEXT8_AFPRRI
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST C_315_A, MASSTOR_LIST B, MASSTOR_LIST J, MASSTOR_LIST SL1, MASSTOR_LIST TL1)
# else
(M, MB, I, C_315_A, B, J, SL1, TL1)
MASSTOR_LIST M, MB, I, C_315_A, B, J, SL1, TL1;
# endif
{
  MASSTOR_LIST AL, ALS1, ALS2, JS, SL, TL, UL, VL;

  SACLIST_FIRST2(J, &ALS1, &ALS2);
  for (;;) {
    AL = SACROOT_RIB(ALS1, ALS2);
    SL = SACEXT8_AFUPSR(M, MB, I, C_315_A, AL);
    if (SL == 0) {
      SL = -SL1;
    }
    TL = SACEXT8_AFUPSR(M, MB, I, B, AL);
    if (TL == 0) {
      TL = -TL1;
    }
    UL = SL1 * SL;
    VL = TL1 * TL;
    if (UL > 0) {
      ALS1 = AL;
    } else {
      ALS2 = AL;
    }
    if (UL != VL) {
      goto EXIT_6;
    }
  } EXIT_6:;
  JS = SACLIST_LIST2(ALS1, ALS2);
  return JS;
}

void SACEXT8_AFPRRS
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST A1, MASSTOR_LIST A2, MASSTOR_LIST I1, MASSTOR_LIST I2, MASSTOR_LIST *IS1, MASSTOR_LIST *IS2, MASSTOR_LIST *SL)
# else
(M, MB, I, A1, A2, I1, I2, IS1, IS2, SL)
MASSTOR_LIST M, MB, I, A1, A2, I1, I2;
MASSTOR_LIST *IS1, *IS2, *SL;
# endif
{
  MASSTOR_LIST AL1, AL2, BL1, BL2, CL, DL1, DL2, SL1, SL2, TL, UL, VL;

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
  SL1 = 2;
  SL2 = 2;
  for (;;) {
    TL = SACRN_RNCOMP(DL1, DL2);
    if (TL >= 0) {
      if (SL1 > 1) {
        SL1 = SACEXT8_AFUPSR(M, MB, I, A1, BL1);
      }
      CL = SACROOT_RIB(AL1, BL1);
      UL = SACEXT8_AFUPSR(M, MB, I, A1, CL);
      if (SL1 == 0 || SL1 * UL < 0) {
        AL1 = CL;
        VL = 1;
      } else {
        BL1 = CL;
        SL1 = UL;
        VL = -1;
      }
      DL1 = SACRN_RNDIF(BL1, AL1);
    }
    if (TL < 0) {
      if (SL2 > 1) {
        SL2 = SACEXT8_AFUPSR(M, MB, I, A2, BL2);
      }
      CL = SACROOT_RIB(AL2, BL2);
      UL = SACEXT8_AFUPSR(M, MB, I, A2, CL);
      if (SL2 == 0 || SL2 * UL < 0) {
        AL2 = CL;
        VL = -1;
      } else {
        BL2 = CL;
        SL2 = UL;
        VL = 1;
      }
      DL2 = SACRN_RNDIF(BL2, AL2);
    }
    if (VL < 0 && SACRN_RNCOMP(BL1, AL2) < 0) {
      *SL = -1;
      goto EXIT_7;
    } else {
      if (VL > 0 && SACRN_RNCOMP(BL2, AL1) < 0) {
        *SL = 1;
        goto EXIT_7;
      }
    }
  } EXIT_7:;
  *IS1 = SACLIST_LIST2(AL1, BL1);
  *IS2 = SACLIST_LIST2(AL2, BL2);
  return;
}

MASSTOR_LIST SACEXT8_AFPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_314_A, MASSTOR_LIST B)
# else
(RL, C_314_A, B)
MASSTOR_LIST RL, C_314_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, EL, FL, RLP;

  if (C_314_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_314_A;
    return C;
  }
  if (RL == 0) {
    C = SACANF_AFSUM(C_314_A, B);
    return C;
  }
  AP = C_314_A;
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
          CL = SACANF_AFSUM(AL, BL);
        } else {
          CL = SACEXT8_AFPSUM(RLP, AL, BL);
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

MASSTOR_LIST SACEXT8_AFSUPB
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_313_A)
# else
(M, C_313_A)
MASSTOR_LIST M, C_313_A;
# endif
{
  MASSTOR_LIST A1, AP, B;

  B = MASSTOR_BETA;
  AP = C_313_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    B = SACEXT8_AFUPBA(M, A1, B);
  }
  return B;
}

MASSTOR_LIST SACEXT8_AFUPBA
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_312_A, MASSTOR_LIST B)
# else
(M, C_312_A, B)
MASSTOR_LIST M, C_312_A, B;
# endif
{
  MASSTOR_LIST ABP, AP, B1, BB1, BP, BS, C;

  AP = C_312_A;
  BP = B;
  BS = MASSTOR_BETA;
  while (BP != MASSTOR_SIL && SACPOL_PDEG(AP) > 0) {
    MASSTOR_ADV(BP, &B1, &BP);
    SACEXT8_AFUPGC(M, AP, B1, &C, &ABP, &BB1);
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

MASSTOR_LIST SACEXT8_AFUPCB
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_311_A)
# else
(M, C_311_A)
MASSTOR_LIST M, C_311_A;
# endif
{
  MASSTOR_LIST A1, AP, AP1, AS, B, L, L1;

  AS = MASSTOR_BETA;
  AP = C_311_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &A1, &AP);
    L = SACEXT8_AFUPSF(M, A1);
    do {
      MASSTOR_ADV(L, &L1, &L);
      AP1 = SACLIST_SECOND(L1);
      AS = MASSTOR_COMP(AP1, AS);
    } while (!(L == MASSTOR_SIL));
  }
  B = SACEXT8_AFSUPB(M, AS);
  return B;
}

void SACEXT8_AFUPGC
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_310_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AB, MASSTOR_LIST *BB)
# else
(M, C_310_A, B, C, AB, BB)
MASSTOR_LIST M, C_310_A, B;
MASSTOR_LIST *C, *AB, *BB;
# endif
{
  MASSTOR_LIST AP, J1Y, ML, NL, Q, R;

  if (C_310_A == 0 && B == 0) {
    *C = 0;
    *AB = 0;
    *BB = 0;
    return;
  }
  if (C_310_A == 0) {
    *C = SACEXT8_AFPMON(1, M, B);
    *AB = 0;
    J1Y = SACPOL_PLDCF(B);
    *BB = SACPOL_PINV(0, J1Y, 1);
    return;
  }
  if (B == 0) {
    *C = SACEXT8_AFPMON(1, M, C_310_A);
    *BB = 0;
    J1Y = SACPOL_PLDCF(C_310_A);
    *AB = SACPOL_PINV(0, J1Y, 1);
    return;
  }
  ML = SACPOL_PDEG(C_310_A);
  NL = SACPOL_PDEG(B);
  if (ML >= NL) {
    AP = C_310_A;
    *C = SACEXT8_AFPMON(1, M, B);
  } else {
    AP = B;
    *C = SACEXT8_AFPMON(1, M, C_310_A);
  }
  for (;;) {
    SACEXT8_AFPQR(1, M, AP, *C, &Q, &R);
    if (R == 0) {
      goto EXIT_8;
    } else {
      AP = *C;
      *C = SACEXT8_AFPMON(1, M, R);
    }
  } EXIT_8:;
  SACEXT8_AFPQR(1, M, C_310_A, *C, AB, &R);
  SACEXT8_AFPQR(1, M, B, *C, BB, &R);
  return;
}

MASSTOR_LIST SACEXT8_AFUPGS
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_309_A)
# else
(M, C_309_A)
MASSTOR_LIST M, C_309_A;
# endif
{
  MASSTOR_LIST B, BP, C, D;

  if (C_309_A == 0) {
    B = 0;
    return B;
  }
  B = SACEXT8_AFPMON(1, M, C_309_A);
  if (SACPOL_PDEG(B) > 0) {
    BP = SACEXT8_AFPDMV(1, M, B);
    SACEXT8_AFUPGC(M, B, BP, &C, &B, &D);
  }
  return B;
}

MASSTOR_LIST SACEXT8_AFUPRB
# ifdef __STDC__
(MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST C_308_A)
# else
(MB, I, C_308_A)
MASSTOR_LIST MB, I, C_308_A;
# endif
{
  MASSTOR_LIST AL, AL1, AP, BL, EL, HL, HL1, HL2, HLP, IL, J, J1Y, N, NL, NL1, QL, RL, TL, UL, VL;

  SACLIST_ADV2(C_308_A, &NL, &AL, &AP);
  for (;;) {
    if (AP == MASSTOR_SIL) {
      EL = -1;
      goto EXIT_9;
    }
    TL = 0;
    do {
      SACLIST_ADV2(AP, &NL1, &AL1, &AP);
      IL = NL - NL1;
      SACEXT8_ANFAF(MB, I, AL1, &N, &J);
      J = SACEXT7_ISFPIR(N, J, 0);
      SACLIST_FIRST2(J, &UL, &VL);
      if (UL == 0) {
        SACRN_RNFCL2(VL, &HLP, &HL);
      } else {
        if (VL == 0) {
          SACRN_RNFCL2(UL, &HLP, &HL);
        } else {
          SACRN_RNFCL2(UL, &HLP, &HL1);
          SACRN_RNFCL2(VL, &HLP, &HL2);
          HL = MASELEM_MASMAX(HL1, HL2);
        }
      }
      MASELEM_MASQREM(HL, IL, &QL, &RL);
      if (RL > 0) {
        QL = QL + 1;
      }
      if (TL == 0 || QL > EL) {
        EL = QL;
      }
      TL = 1;
    } while (!(AP == MASSTOR_SIL));
    goto EXIT_9;
  } EXIT_9:;
  J1Y = EL + 1;
  BL = SACRN_RNP2(J1Y);
  return BL;
}

MASSTOR_LIST SACEXT8_AFUPRL
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_307_A)
# else
(M, C_307_A)
MASSTOR_LIST M, C_307_A;
# endif
{
  MASSTOR_LIST AL, CL, DL, J1Y, L;

  if (SACPOL_PRED(C_307_A) == 0) {
    AL = 0;
  } else {
    L = SACPOL_PCL(C_307_A);
    SACLIST_FIRST2(L, &CL, &DL);
    J1Y = SACANF_AFNEG(DL);
    AL = SACANF_AFQ(M, J1Y, CL);
    return AL;
  }
  return AL;
}

MASSTOR_LIST SACEXT8_AFUPSF
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_306_A)
# else
(M, C_306_A)
MASSTOR_LIST M, C_306_A;
# endif
{
  MASSTOR_LIST AP, B, BP, C, CP, D, J1Y, JL, L;

  L = MASSTOR_BETA;
  AP = SACEXT8_AFPDMV(1, M, C_306_A);
  SACEXT8_AFUPGC(M, C_306_A, AP, &B, &C, &CP);
  JL = 1;
  while (SACPOL_PDEG(B) > 0) {
    SACEXT8_AFUPGC(M, B, C, &D, &BP, &CP);
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

MASSTOR_LIST SACEXT8_AFUPSR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST C_305_A, MASSTOR_LIST CL)
# else
(M, MB, I, C_305_A, CL)
MASSTOR_LIST M, MB, I, C_305_A, CL;
# endif
{
  MASSTOR_LIST AL, BL, SL;

  AL = SACEXT8_AFFRN(CL);
  BL = SACEXT8_AFPEMV(1, M, C_305_A, AL);
  SL = SACANF_AFSIGN(MB, I, BL);
  return SL;
}

void SACEXT8_ANDWR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST NL)
# else
(M, I, NL)
MASSTOR_LIST M, I, NL;
# endif
{
  MASSTOR_LIST J, J1Y, R;

  if (SACPOL_PDEG(M) == 1) {
    R = SACROOT_IUPRLP(M);
  } else {
    J1Y = NL + 1;
    J = SACEXT7_ISFPIR(M, I, J1Y);
    R = MASSTOR_FIRST(J);
  }
  MASRN_RNDWRS(R, NL);
  return;
}

void SACEXT8_ANFAF
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST AL, MASSTOR_LIST *N, MASSTOR_LIST *J)
# else
(M, I, AL, N, J)
MASSTOR_LIST M, I, AL;
MASSTOR_LIST *N, *J;
# endif
{
  MASSTOR_LIST C_304_A, B, BL1, BL2, C, DL, J1Y, J2Y, L, SL1, SL2, UL1, UL2, VL1, VL2;

  if (AL == 0) {
    *N = SACPOL_PMON(1, 1);
    *J = SACLIST_LIST2(0, 0);
    return;
  }
  if (SACPOL_PDEG(AL) == 0) {
    J1Y = -1;
    J1Y = SACRN_RNINT(J1Y);
    J2Y = SACLIST_SECOND(AL);
    *N = SACPOL_PBIN(J1Y, 1, J2Y, 0);
    SACPGCD_IPSRP(1, *N, &DL, N);
    L = SACROOT_IPRIM(*N);
    *J = MASSTOR_FIRST(L);
    return;
  }
  J1Y = -1;
  J1Y = SACRN_RNINT(J1Y);
  J1Y = SACPOL_PMON(J1Y, 0);
  C_304_A = SACPOL_PBIN(J1Y, 1, AL, 0);
  SACPGCD_IPSRP(2, C_304_A, &DL, &C_304_A);
  J1Y = SACLIST_LIST2(2, 1);
  C_304_A = DIPC_PPERMV(2, C_304_A, J1Y);
  B = SACPOL_PINV(1, M, 1);
  C = SACPGCD_IPRES(2, C_304_A, B);
  *N = SACPGCD_IPPGSD(1, C);
  L = SACROOT_IPRIM(*N);
  do {
    MASSTOR_ADV(L, J, &L);
    SACLIST_FIRST2(*J, &UL1, &UL2);
    VL1 = SACPOL_PMON(UL1, 0);
    VL2 = SACPOL_PMON(UL2, 0);
    BL1 = SACANF_AFDIF(AL, VL1);
    BL2 = SACANF_AFDIF(AL, VL2);
    SL1 = SACANF_AFSIGN(M, I, BL1);
    SL2 = SACANF_AFSIGN(M, I, BL2);
    if (SL1 * SL2 == -1) {
      return;
    }
  } while (!FALSE);
  return;
}

void SACEXT8_ANIIPE
# ifdef __STDC__
(MASSTOR_LIST MB, MASSTOR_LIST I, MASSTOR_LIST NB, MASSTOR_LIST J, MASSTOR_LIST TL, MASSTOR_LIST L, MASSTOR_LIST *S, MASSTOR_LIST *KL, MASSTOR_LIST *K)
# else
(MB, I, NB, J, TL, L, S, KL, K)
MASSTOR_LIST MB, I, NB, J, TL, L;
MASSTOR_LIST *S, *KL, *K;
# endif
{
  MASSTOR_LIST AL, BL, CL, CLS, DL, DLS, EL, J1Y, J2Y, JP, JS, KLP, L1, LP, ML, NL, SL1, SL2, SLP, TLP, VL, VLP;

  *KL = 1;
  ML = SACPOL_PDEG(MB);
  NL = SACPOL_PDEG(NB);
  if (ML == 1 && NL == 1) {
    *S = MASSTOR_FIRST(L);
    *K = SACROOT_IPRIM(*S);
    *K = MASSTOR_FIRST(*K);
    return;
  }
  if (ML == 1) {
    *S = NB;
    *K = J;
    return;
  }
  if (NL == 1) {
    *S = MB;
    *K = I;
    return;
  }
  SACLIST_FIRST2(I, &AL, &BL);
  SL1 = SACIPOL_IUPBES(MB, BL);
  JP = J;
  SACLIST_FIRST2(J, &CL, &DL);
  SL2 = SACIPOL_IUPBES(NB, DL);
  TLP = SACRN_RNINT(TL);
  for (;;) {
    JS = SACRN_RIRNP(JP, TLP);
    SACLIST_FIRST2(JS, &CLS, &DLS);
    J1Y = SACRN_RNSUM(AL, CLS);
    J2Y = SACRN_RNSUM(BL, DLS);
    *K = SACLIST_LIST2(J1Y, J2Y);
    for (;;) {
      VL = 0;
      KLP = 0;
      LP = L;
      do {
        MASSTOR_ADV(LP, &L1, &LP);
        KLP = KLP + 1;
        VLP = SACEXT7_IUPVOI(L1, *K);
        if (VLP > 1) {
          goto EXIT_11;
        }
        if (VLP == 1) {
          if (VL == 1) {
            goto EXIT_11;
          } else {
            VL = 1;
            *S = L1;
            *KL = KLP;
          }
        }
      } while (!(LP == MASSTOR_SIL));
      return;
    } EXIT_11:;
    EL = SACROOT_RIB(AL, BL);
    SLP = SACIPOL_IUPBES(MB, EL);
    if (SLP * SL1 < 0) {
      AL = EL;
    } else {
      BL = EL;
      SL1 = SLP;
    }
    EL = SACROOT_RIB(CL, DL);
    SLP = SACIPOL_IUPBES(NB, EL);
    if (SLP * SL2 < 0) {
      CL = EL;
    } else {
      DL = EL;
      SL2 = SLP;
    }
    JP = SACLIST_LIST2(CL, DL);
  } EXIT_10:;
}

void SACEXT8_ANPEDE
# ifdef __STDC__
(MASSTOR_LIST MB, MASSTOR_LIST NB, MASSTOR_LIST *TL, MASSTOR_LIST *S, MASSTOR_LIST *T)
# else
(MB, NB, TL, S, T)
MASSTOR_LIST MB, NB;
MASSTOR_LIST *TL, *S, *T;
# endif
{
  MASSTOR_LIST C, CL, J1Y, J2Y, ML, MP, MS, NL, NP, NS, P, R, RB, RBP, RP, S1, SL, SP, SP1;

  *TL = 1;
  ML = SACPOL_PDEG(MB);
  NL = SACPOL_PDEG(NB);
  if (ML == 1 && NL == 1) {
    J1Y = SACPOL_PMON(1, 1);
    *S = MASSTOR_LIST1(J1Y);
    MS = SACROOT_IUPRLP(MB);
    MS = SACEXT8_AFFRN(MS);
    NS = SACROOT_IUPRLP(NB);
    NS = SACEXT8_AFFRN(NS);
    *T = SACLIST_LIST2(MS, NS);
    return;
  }
  if (ML == 1) {
    *S = MASSTOR_LIST1(NB);
    MS = SACROOT_IUPRLP(MB);
    MS = SACEXT8_AFFRN(MS);
    J1Y = SACRN_RNINT(1);
    NS = SACPOL_PMON(J1Y, 1);
    *T = SACLIST_LIST2(MS, NS);
    return;
  }
  if (NL == 1) {
    *S = MASSTOR_LIST1(MB);
    J1Y = SACRN_RNINT(1);
    MS = SACPOL_PMON(J1Y, 1);
    NS = SACROOT_IUPRLP(NB);
    NS = SACEXT8_AFFRN(NS);
    *T = SACLIST_LIST2(MS, NS);
    return;
  }
  NP = SACPOL_PINV(1, NB, 1);
  for (;;) {
    J1Y = -*TL;
    J1Y = SACPOL_PMON(J1Y, 0);
    J2Y = SACPOL_PMON(1, 1);
    P = SACPOL_PBIN(J1Y, 1, J2Y, 0);
    J1Y = MASSTOR_LIST1(P);
    MP = SACIPOL_IPGSUB(1, MB, 2, J1Y);
    R = SACPGCD_IPRES(2, MP, NP);
    RP = SACIPOL_IPDMV(1, R);
    SACPGCD_IPGCDC(1, R, RP, &C, &RB, &RBP);
    if (SACPOL_PDEG(C) > 0) {
      if (*TL > 0) {
        *TL = -*TL;
      } else {
        J1Y = -*TL;
        *TL = J1Y + 1;
      }
    } else {
      goto EXIT_12;
    }
  } EXIT_12:;
  SACPGCD_IPSCPP(1, R, &SL, &CL, &R);
  *S = SACUPFAC_IUSFPF(R);
  SP = *S;
  *T = MASSTOR_BETA;
  do {
    MASSTOR_ADV(SP, &S1, &SP);
    SP1 = SACEXT4_RPMAIP(1, S1);
    NS = SACEXT8_ANREPE(SP1, S1, MP, NP);
    J1Y = SACEXT8_AFFINT(*TL);
    MS = SACANF_AFPROD(SP1, J1Y, NS);
    J1Y = SACRN_RNINT(1);
    J1Y = SACPOL_PMON(J1Y, 1);
    MS = SACANF_AFDIF(J1Y, MS);
    *T = SACLIST_COMP2(NS, MS, *T);
  } while (!(SP == MASSTOR_SIL));
  *T = MASSTOR_INV(*T);
  return;
}

MASSTOR_LIST SACEXT8_ANREPE
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST MB, MASSTOR_LIST C_303_A, MASSTOR_LIST B)
# else
(M, MB, C_303_A, B)
MASSTOR_LIST M, MB, C_303_A, B;
# endif
{
  MASSTOR_LIST AL, BL, C0, C1, D, EL0, EL1, QL, R, RL, S, S1, T;

  if (SACPOL_PDEG(C_303_A) > SACPOL_PDEG(B)) {
    S = SACPGCD_IPSPRS(2, C_303_A, B);
  } else {
    S = SACPGCD_IPSPRS(2, B, C_303_A);
  }
  S = MASSTOR_INV(S);
  S1 = SACLIST_SECOND(S);
  SACLIST_FIRST4(S1, &EL1, &C1, &EL0, &C0);
  C1 = SACRPOL_RPFIP(1, C1);
  C0 = SACRPOL_RPFIP(1, C0);
  SACRPOL_RPQR(1, C1, M, &QL, &C1);
  SACRPOL_RPQR(1, C0, M, &QL, &C0);
  SACPGCD_IPSRP(1, C1, &AL, &C1);
  C0 = SACRPOL_RPRNP(1, AL, C0);
  SACEXT5_IUPRC(MB, C1, &T, &RL);
  R = SACRN_RNRED(1, RL);
  R = SACRN_RNNEG(R);
  T = SACRPOL_RPFIP(1, T);
  D = SACANF_AFPROD(M, T, C0);
  BL = SACRPOL_RPRNP(1, R, D);
  return BL;
}

void SACEXT8_APDWR
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST BL, MASSTOR_LIST NL)
# else
(M, I, BL, NL)
MASSTOR_LIST M, I, BL, NL;
# endif
{
  MASSTOR_LIST BL1, BLP, J, N;

  BLP = BL;
  MASBIOS_SWRITE("( ", 2L);
  while (BLP != MASSTOR_SIL) {
    MASSTOR_ADV(BLP, &BL1, &BLP);
    SACEXT8_ANFAF(M, I, BL1, &N, &J);
    SACEXT8_ANDWR(N, J, NL);
    if (BLP != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  MASBIOS_SWRITE(" )", 2L);
  return;
}

MASSTOR_LIST SACEXT8_IPAFME
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_302_A, MASSTOR_LIST BL)
# else
(RL, M, C_302_A, BL)
MASSTOR_LIST RL, M, C_302_A, BL;
# endif
{
  MASSTOR_LIST AP, B;

  AP = SACEXT8_AFPFIP(RL, C_302_A);
  B = SACEXT8_AFPME(RL, M, AP, BL);
  return B;
}

MASSTOR_LIST SACEXT8_IUPMRN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST J1Y, M, R1, R2;

  if (R == 0) {
    M = SACPOL_PMON(1, 1);
  } else {
    SACLIST_FIRST2(R, &R1, &R2);
    J1Y = SACI_INEG(R1);
    M = SACPOL_PBIN(R2, 1, J1Y, 0);
  }
  return M;
}

MASSTOR_LIST SACEXT8_RPAFME
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST M, MASSTOR_LIST C_301_A, MASSTOR_LIST BL)
# else
(RL, M, C_301_A, BL)
MASSTOR_LIST RL, M, C_301_A, BL;
# endif
{
  MASSTOR_LIST AP, B;

  AP = SACEXT8_AFPFRP(RL, C_301_A);
  B = SACEXT8_AFPME(RL, M, AP, BL);
  return B;
}

void BEGIN_SACEXT8()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_SACM();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACRPOL();
    BEGIN_SACMPOL();
    BEGIN_SACRPOL();
    BEGIN_SACEXT2();
    BEGIN_SACEXT4();
    BEGIN_SACEXT5();
    BEGIN_SACEXT7();
    BEGIN_MASRN();
    BEGIN_DIPC();
    BEGIN_SACPGCD();
    BEGIN_SACROOT();
    BEGIN_SACPFAC();
    BEGIN_SACANF();
    BEGIN_SACUPFAC();

  }
}
