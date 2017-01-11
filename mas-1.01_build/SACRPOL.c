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

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

CHAR SACRPOL_rcsid [] = "$Id: SACRPOL.md,v 1.2 1992/02/12 17:34:04 pesch Exp $";
CHAR SACRPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACRPOL.mi,v 1.3 1992/10/15 16:28:44 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACRPOL_RPDIF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_81_A, MASSTOR_LIST B)
# else
(RL, C_81_A, B)
MASSTOR_LIST RL, C_81_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP;

  if (C_81_A == 0) {
    C = SACRPOL_RPNEG(RL, B);
    return C;
  }
  if (B == 0) {
    C = C_81_A;
    return C;
  }
  if (RL == 0) {
    C = SACRN_RNDIF(C_81_A, B);
    return C;
  }
  AP = C_81_A;
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
          CL = SACRN_RNNEG(BL);
        } else {
          CL = SACRPOL_RPNEG(RLP, BL);
        }
        CP = SACLIST_COMP2(CL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACRN_RNDIF(AL, BL);
        } else {
          CL = SACRPOL_RPDIF(RLP, AL, BL);
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
      CPP = SACRPOL_RPNEG(RL, BP);
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

MASSTOR_LIST SACRPOL_RPEMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_80_A, MASSTOR_LIST BL)
# else
(RL, C_80_A, BL)
MASSTOR_LIST RL, C_80_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, ELP, IL, RLP;

  if (C_80_A == 0) {
    C = 0;
    return C;
  }
  AP = C_80_A;
  C = 0;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (AP == MASSTOR_SIL) {
      ELP = 0;
    } else {
      ELP = MASSTOR_FIRST(AP);
    }
    C = SACRPOL_RPSUM(RLP, C, AL);
    {
      LONGINT B_1 = 1, B_2 = EL - ELP;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          C = SACRPOL_RPRNP(RLP, BL, C);
          if (IL >= B_2) break;
        }
    }
  } while (!(AP == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST SACRPOL_RPFIP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_79_A)
# else
(RL, C_79_A)
MASSTOR_LIST RL, C_79_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_79_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACRN_RNINT(C_79_A);
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_79_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACRPOL_RPFIP(RLP, AL);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACRPOL_RPIMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_78_A)
# else
(RL, C_78_A)
MASSTOR_LIST RL, C_78_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, ELP, ELS, RLP;

  if (C_78_A == 0) {
    B = 0;
    return B;
  }
  AP = C_78_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    ELP = EL + 1;
    ELS = SACLIST_LIST2(1, ELP);
    BL = SACRPOL_RPRNP(RLP, ELS, AL);
    B = SACLIST_COMP2(BL, ELP, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACRPOL_RPNEG
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_77_A)
# else
(RL, C_77_A)
MASSTOR_LIST RL, C_77_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_77_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACRN_RNNEG(C_77_A);
    return B;
  }
  AP = C_77_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACRN_RNNEG(AL);
    } else {
      BL = SACRPOL_RPNEG(RLP, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACRPOL_RPPROD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_76_A, MASSTOR_LIST B)
# else
(RL, C_76_A, B)
MASSTOR_LIST RL, C_76_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP;

  if (C_76_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACRN_RNPROD(C_76_A, B);
    return C;
  }
  AS = SACLIST_CINV(C_76_A);
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
        CL = SACRN_RNPROD(AL, BL);
      } else {
        CL = SACRPOL_RPPROD(RLP, AL, BL);
      }
      J1Y = EL + FL;
      C1 = SACLIST_COMP2(J1Y, CL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = SACRPOL_RPSUM(RL, C, C1);
  } while (!(BS == MASSTOR_SIL));
  return C;
}

void SACRPOL_RPQR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_75_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(RL, C_75_A, B, Q, R)
MASSTOR_LIST RL, C_75_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL;

  NL = SACPOL_PDEG(B);
  BL = SACPOL_PLDCF(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_75_A;
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
      QL = SACRN_RNQ(AL, BL);
      SL = 0;
    } else {
      SACRPOL_RPQR(RLP, AL, BL, &QL, &SL);
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
    QP = SACRPOL_RPPROD(RL, BP, Q1);
    *R = SACRPOL_RPDIF(RL, RP, QP);
  }
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

void SACRPOL_RPREAD
# ifdef __STDC__
(MASSTOR_LIST *RL, MASSTOR_LIST *C_74_A, MASSTOR_LIST *V)
# else
(RL, C_74_A, V)
MASSTOR_LIST *RL, *C_74_A, *V;
# endif
{
  MASSTOR_LIST AL, C, EL, IDUM, RLP, VL;

  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    *C_74_A = SACRN_RNREAD();
    *RL = 0;
    *V = MASSTOR_BETA;
    return;
  }
  *C_74_A = MASSTOR_BETA;
  for (;;) {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      goto EXIT_1;
    }
    MASBIOS_BKSP();
    SACRPOL_RPREAD(&RLP, &AL, V);
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('*')) {
      MASBIOS_SWRITE("error found by RPREAD.", 22L);
      MASBIOS_DIBUFF();
      goto EXIT_1;
    }
    VL = SACPOL_VREAD();
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('*')) {
      MASBIOS_SWRITE("error found by RPREAD.", 22L);
      MASBIOS_DIBUFF();
      goto EXIT_1;
    }
    C = MASBIOS_CREAD();
    if (C != MASBIOS_MASORD('*')) {
      MASBIOS_SWRITE("error found by RPREAD.", 22L);
      MASBIOS_DIBUFF();
      goto EXIT_1;
    }
    EL = SACLIST_AREAD();
    *C_74_A = SACLIST_COMP2(AL, EL, *C_74_A);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      goto EXIT_1;
    } else {
      if (C == MASBIOS_MASORD('-')) {
        MASBIOS_BKSP();
      } else {
        if (C != MASBIOS_MASORD('+')) {
          MASBIOS_SWRITE("error found by RPREAD.", 22L);
          MASBIOS_DIBUFF();
          goto EXIT_1;
        }
      }
    }
  } EXIT_1:;
  *C_74_A = MASSTOR_INV(*C_74_A);
  *RL = RLP + 1;
  *V = SACLIST_SUFFIX(*V, VL);
  return;
}

MASSTOR_LIST SACRPOL_RPRNP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST AL, MASSTOR_LIST B)
# else
(RL, AL, B)
MASSTOR_LIST RL, AL, B;
# endif
{
  MASSTOR_LIST BL, BP, C, CL, EL, RLP;

  if (AL == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACRN_RNPROD(AL, B);
    return C;
  }
  C = MASSTOR_BETA;
  BP = B;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(BP, &EL, &BL, &BP);
    CL = SACRPOL_RPRNP(RLP, AL, BL);
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(BP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACRPOL_RPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_73_A, MASSTOR_LIST B)
# else
(RL, C_73_A, B)
MASSTOR_LIST RL, C_73_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, EL, FL, RLP;

  if (C_73_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_73_A;
    return C;
  }
  if (RL == 0) {
    C = SACRN_RNSUM(C_73_A, B);
    return C;
  }
  AP = C_73_A;
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
          CL = SACRN_RNSUM(AL, BL);
        } else {
          CL = SACRPOL_RPSUM(RLP, AL, BL);
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

void SACRPOL_RPWRIT
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_72_A, MASSTOR_LIST V)
# else
(RL, C_72_A, V)
MASSTOR_LIST RL, C_72_A, V;
# endif
{
  MASSTOR_LIST AL, AP, EL, IL, RLP, V1, VB, VP;

  if (RL == 0 || C_72_A == 0) {
    SACI_IWRITE(C_72_A);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  AP = C_72_A;
  RLP = RL - 1;
  VB = SACLIST_CINV(V);
  MASSTOR_ADV(VB, &V1, &VP);
  VP = MASSTOR_INV(VP);
  IL = 0;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL != 0 && (RL > 1 || SACRN_RNSIGN(AL) > 0)) {
      MASBIOS_SWRITE("+", 1L);
    }
    if (RLP == 0) {
      SACRN_RNWRIT(AL);
    } else {
      SACRPOL_RPWRIT(RLP, AL, VP);
    }
    MASBIOS_SWRITE("*", 1L);
    SACLIST_CLOUT(V1);
    MASBIOS_SWRITE("*", 1L);
    MASBIOS_SWRITE("*", 1L);
    SACI_IWRITE(EL);
    IL = 1;
  } while (!(AP == MASSTOR_SIL));
  MASBIOS_SWRITE(")", 1L);
  return;
}

void BEGIN_SACRPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();

  }
}
