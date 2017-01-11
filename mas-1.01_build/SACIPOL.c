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

CHAR SACIPOL_rcsid [] = "$Id: SACIPOL.md,v 1.2 1992/02/12 17:33:57 pesch Exp $";
CHAR SACIPOL_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACIPOL.mi,v 1.3 1992/10/15 16:28:40 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_1 {
    MASSTOR_LIST A[500 - 1 + 1];
};


MASSTOR_LIST SACIPOL_IPABS
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_153_A)
# else
(RL, C_153_A)
MASSTOR_LIST RL, C_153_A;
# endif
{
  MASSTOR_LIST B, SL;

  SL = SACIPOL_IPSIGN(RL, C_153_A);
  if (SL >= 0) {
    B = C_153_A;
  } else {
    B = SACIPOL_IPNEG(RL, C_153_A);
  }
  return B;
}

MASSTOR_LIST SACIPOL_IPCRA
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST ML, MASSTOR_LIST MLP, MASSTOR_LIST RL, MASSTOR_LIST C_152_A, MASSTOR_LIST AL)
# else
(M, ML, MLP, RL, C_152_A, AL)
MASSTOR_LIST M, ML, MLP, RL, C_152_A, AL;
# endif
{
  MASSTOR_LIST A1, AL1, ALP, AP, AS, AS1, E, EL, ES, RLP;

  if (RL == 0) {
    AS = SACM_MIDCRA(M, ML, MLP, C_152_A, AL);
    return AS;
  }
  if (C_152_A == 0) {
    AP = MASSTOR_BETA;
  } else {
    AP = C_152_A;
  }
  if (AL == 0) {
    ALP = MASSTOR_BETA;
  } else {
    ALP = AL;
  }
  RLP = RL - 1;
  AS = MASSTOR_BETA;
  while (AP != MASSTOR_SIL || ALP != MASSTOR_SIL) {
    if (AP == MASSTOR_SIL) {
      A1 = 0;
      SACLIST_ADV2(ALP, &ES, &AL1, &ALP);
    } else {
      if (ALP == MASSTOR_SIL) {
        AL1 = 0;
        SACLIST_ADV2(AP, &ES, &A1, &AP);
      } else {
        E = MASSTOR_FIRST(AP);
        EL = MASSTOR_FIRST(ALP);
        if (E > EL) {
          SACLIST_ADV2(AP, &ES, &A1, &AP);
          AL1 = 0;
        } else {
          if (E < EL) {
            SACLIST_ADV2(ALP, &ES, &AL1, &ALP);
            A1 = 0;
          } else {
            SACLIST_ADV2(AP, &ES, &A1, &AP);
            SACLIST_ADV2(ALP, &ES, &AL1, &ALP);
          }
        }
      }
    }
    if (RLP == 0) {
      AS1 = SACM_MIDCRA(M, ML, MLP, A1, AL1);
    } else {
      AS1 = SACIPOL_IPCRA(M, ML, MLP, RLP, A1, AL1);
    }
    AS = SACLIST_COMP2(AS1, ES, AS);
  }
  if (AS == MASSTOR_SIL) {
    AS = 0;
  } else {
    AS = MASSTOR_INV(AS);
  }
  return AS;
}

MASSTOR_LIST SACIPOL_IPDER
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_151_A, MASSTOR_LIST IL)
# else
(RL, C_151_A, IL)
MASSTOR_LIST RL, C_151_A, IL;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_151_A == 0) {
    B = 0;
    return B;
  }
  if (IL == RL) {
    B = SACIPOL_IPDMV(RL, C_151_A);
    return B;
  }
  AP = C_151_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    BL = SACIPOL_IPDER(RLP, AL, IL);
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

MASSTOR_LIST SACIPOL_IPDIF
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_150_A, MASSTOR_LIST B)
# else
(RL, C_150_A, B)
MASSTOR_LIST RL, C_150_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP;

  if (C_150_A == 0) {
    C = SACIPOL_IPNEG(RL, B);
    return C;
  }
  if (B == 0) {
    C = C_150_A;
    return C;
  }
  if (RL == 0) {
    C = SACI_IDIF(C_150_A, B);
    return C;
  }
  AP = C_150_A;
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
          CL = SACI_INEG(BL);
        } else {
          CL = SACIPOL_IPNEG(RLP, BL);
        }
        CP = SACLIST_COMP2(CL, FL, CP);
      } else {
        SACLIST_ADV2(AP, &EL, &AL, &AP);
        SACLIST_ADV2(BP, &FL, &BL, &BP);
        if (RLP == 0) {
          CL = SACI_IDIF(AL, BL);
        } else {
          CL = SACIPOL_IPDIF(RLP, AL, BL);
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
      CPP = SACIPOL_IPNEG(RL, BP);
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

MASSTOR_LIST SACIPOL_IPDMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_149_A)
# else
(RL, C_149_A)
MASSTOR_LIST RL, C_149_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, ELP, RLP;

  if (C_149_A == 0) {
    B = 0;
    return B;
  }
  AP = C_149_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACI_IPROD(EL, AL);
    } else {
      BL = SACIPOL_IPIP(RLP, EL, AL);
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

MASSTOR_LIST SACIPOL_IPEMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_148_A, MASSTOR_LIST AL)
# else
(RL, C_148_A, AL)
MASSTOR_LIST RL, C_148_A, AL;
# endif
{
  MASSTOR_LIST A2, AP, B, EL1, EL2, IL, RLP;

  if (C_148_A == 0) {
    B = 0;
    return B;
  }
  SACLIST_ADV2(C_148_A, &EL1, &B, &AP);
  RLP = RL - 1;
  while (AP != MASSTOR_SIL) {
    SACLIST_ADV2(AP, &EL2, &A2, &AP);
    {
      LONGINT B_1 = 1, B_2 = EL1 - EL2;

      if (B_1 <= B_2)
        for (IL = B_1;; IL += 1) {
          if (RLP == 0) {
            B = SACI_IPROD(AL, B);
          } else {
            B = SACIPOL_IPIP(RLP, AL, B);
          }
          if (IL >= B_2) break;
        }
    }
    if (RLP == 0) {
      B = SACI_ISUM(B, A2);
    } else {
      B = SACIPOL_IPSUM(RLP, B, A2);
    }
    EL1 = EL2;
  }
  {
    LONGINT B_3 = 1, B_4 = EL1;

    if (B_3 <= B_4)
      for (IL = B_3;; IL += 1) {
        if (RLP == 0) {
          B = SACI_IPROD(AL, B);
        } else {
          B = SACIPOL_IPIP(RLP, AL, B);
        }
        if (IL >= B_4) break;
      }
  }
  return B;
}

MASSTOR_LIST SACIPOL_IPEVAL
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_147_A, MASSTOR_LIST IL, MASSTOR_LIST AL)
# else
(RL, C_147_A, IL, AL)
MASSTOR_LIST RL, C_147_A, IL, AL;
# endif
{
  MASSTOR_LIST A1, AP, B, B1, EL1, RLP;

  if (C_147_A == 0) {
    B = 0;
    return B;
  }
  if (IL == RL) {
    B = SACIPOL_IPEMV(RL, C_147_A, AL);
    return B;
  }
  RLP = RL - 1;
  AP = C_147_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL1, &A1, &AP);
    B1 = SACIPOL_IPEVAL(RLP, A1, IL, AL);
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

MASSTOR_LIST SACIPOL_IPEXP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_146_A, MASSTOR_LIST NL)
# else
(RL, C_146_A, NL)
MASSTOR_LIST RL, C_146_A, NL;
# endif
{
  MASSTOR_LIST B, IL;

  if (NL == 0) {
    B = SACPOL_PINV(0, 1, RL);
    return B;
  }
  if (C_146_A == 0) {
    B = 0;
    return B;
  }
  B = C_146_A;
  {
    LONGINT B_5 = 1, B_6 = NL - 1;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        B = SACIPOL_IPPROD(RL, B, C_146_A);
        if (IL >= B_6) break;
      }
  }
  return B;
}

MASSTOR_LIST SACIPOL_IPFCB
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST BL, J1Y, NL, NL1, PL, VP;

  NL = 0;
  PL = 1;
  VP = V;
  do {
    MASSTOR_ADV(VP, &NL1, &VP);
    if (NL1 > 0) {
      J1Y = NL + NL1;
      J1Y = J1Y + NL1;
      NL = J1Y - 1;
      J1Y = NL1 + 1;
      PL = SACI_IPROD(PL, J1Y);
    }
  } while (!(VP == MASSTOR_SIL));
  J1Y = SACI_ILOG2(PL);
  NL = NL + J1Y;
  J1Y = NL + 1;
  BL = J1Y / 2;
  return BL;
}

MASSTOR_LIST SACIPOL_IPFRP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_145_A)
# else
(RL, C_145_A)
MASSTOR_LIST RL, C_145_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL, RLP;

  if (C_145_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = MASSTOR_FIRST(C_145_A);
    return B;
  }
  AS = C_145_A;
  RLP = RL - 1;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AS, &EL, &AL, &AS);
    if (RLP == 0) {
      BL = MASSTOR_FIRST(AL);
    } else {
      BL = SACIPOL_IPFRP(RLP, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACIPOL_IPGSUB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_144_A, MASSTOR_LIST SL, MASSTOR_LIST L)
# else
(RL, C_144_A, SL, L)
MASSTOR_LIST RL, C_144_A, SL, L;
# endif
{
  MASSTOR_LIST B, C, J1Y, LP, TL;

  if (C_144_A == 0) {
    C = 0;
    return C;
  }
  C = SACPOL_PINV(RL, C_144_A, SL);
  LP = L;
  TL = RL + SL;
  do {
    MASSTOR_ADV(LP, &B, &LP);
    J1Y = SL + 1;
    C = SACIPOL_IPSUB(TL, C, J1Y, B);
    TL = TL - 1;
  } while (!(LP == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST SACIPOL_IPHDMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_143_A, MASSTOR_LIST KL)
# else
(RL, C_143_A, KL)
MASSTOR_LIST RL, C_143_A, KL;
# endif
{
  MASSTOR_LIST B, IL;

  B = C_143_A;
  IL = KL;
  while (IL > 0 && B != 0) {
    B = SACIPOL_IPDMV(RL, B);
    IL = IL - 1;
  }
  return B;
}

MASSTOR_LIST SACIPOL_IPIHOM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_142_A)
# else
(RL, D, C_142_A)
MASSTOR_LIST RL, D, C_142_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL, RLP;

  if (RL == 0 || C_142_A == 0) {
    B = C_142_A;
    return B;
  }
  RLP = RL - 1;
  B = MASSTOR_BETA;
  AS = SACLIST_CINV(C_142_A);
  while (AS != MASSTOR_SIL) {
    SACLIST_ADV2(AS, &AL, &EL, &AS);
    BL = SACIPOL_IPTRUN(RLP, D, AL);
    if (BL != 0) {
      B = SACLIST_COMP2(EL, BL, B);
    }
  }
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

MASSTOR_LIST SACIPOL_IPIP
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
  BP = B;
  C = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(BP, &EL, &BL, &BP);
    if (RLP == 0) {
      CL = SACI_IPROD(AL, BL);
    } else {
      CL = SACIPOL_IPIP(RLP, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(BP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACIPOL_IPIPR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_141_A, MASSTOR_LIST B)
# else
(RL, D, C_141_A, B)
MASSTOR_LIST RL, D, C_141_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP;

  if (C_141_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  AS = SACLIST_CINV(C_141_A);
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
        CL = SACI_IPROD(AL, BL);
      } else {
        CL = SACIPOL_IPTPR(RLP, D, AL, BL);
      }
      if (CL != 0) {
        J1Y = EL + FL;
        C1 = SACLIST_COMP2(J1Y, CL, C1);
      }
    } while (!(AP == MASSTOR_SIL));
    if (C1 != MASSTOR_SIL) {
      C = SACIPOL_IPSUM(RL, C, C1);
    }
  } while (!(BS == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST SACIPOL_IPIQ
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_140_A, MASSTOR_LIST BL)
# else
(RL, C_140_A, BL)
MASSTOR_LIST RL, C_140_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, EL, RLP;

  if (C_140_A == 0) {
    C = 0;
    return C;
  }
  AP = C_140_A;
  RLP = RL - 1;
  C = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      CL = SACI_IQ(AL, BL);
    } else {
      CL = SACIPOL_IPIQ(RLP, AL, BL);
    }
    C = SACLIST_COMP2(CL, EL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST SACIPOL_IPMAXN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_139_A)
# else
(RL, C_139_A)
MASSTOR_LIST RL, C_139_A;
# endif
{
  MASSTOR_LIST AL1, AP, BL, BL1, EL1, RLP;

  BL = 0;
  if (C_139_A == 0) {
    return BL;
  }
  AP = C_139_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL1, &AL1, &AP);
    if (RLP == 0) {
      BL1 = SACI_IABSF(AL1);
    } else {
      BL1 = SACIPOL_IPMAXN(RLP, AL1);
    }
    BL = SACI_IMAX(BL, BL1);
  } while (!(AP == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST SACIPOL_IPNEG
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_138_A)
# else
(RL, C_138_A)
MASSTOR_LIST RL, C_138_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, RLP;

  if (C_138_A == 0) {
    B = 0;
    return B;
  }
  if (RL == 0) {
    B = SACI_INEG(C_138_A);
    return B;
  }
  AP = C_138_A;
  B = MASSTOR_BETA;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (RLP == 0) {
      BL = SACI_INEG(AL);
    } else {
      BL = SACIPOL_IPNEG(RLP, AL);
    }
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACIPOL_IPONE
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_137_A)
# else
(RL, C_137_A)
MASSTOR_LIST RL, C_137_A;
# endif
{
  MASSTOR_LIST AL, IL, TL;

  TL = 0;
  if (C_137_A == 0) {
    return TL;
  }
  AL = C_137_A;
  {
    LONGINT B_7 = 1, B_8 = RL;

    if (B_7 <= B_8)
      for (IL = B_7;; IL += 1) {
        if (SACPOL_PDEG(AL) != 0) {
          return TL;
        }
        AL = SACPOL_PLDCF(AL);
        if (IL >= B_8) break;
      }
  }
  if (AL == 1) {
    TL = 1;
  }
  return TL;
}

MASSTOR_LIST SACIPOL_IPPROD
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_136_A, MASSTOR_LIST B)
# else
(RL, C_136_A, B)
MASSTOR_LIST RL, C_136_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP;

  if (C_136_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  if (RL == 0) {
    C = SACI_IPROD(C_136_A, B);
    return C;
  }
  AS = SACLIST_CINV(C_136_A);
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
        CL = SACI_IPROD(AL, BL);
      } else {
        CL = SACIPOL_IPPROD(RLP, AL, BL);
      }
      J1Y = EL + FL;
      C1 = SACLIST_COMP2(J1Y, CL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = SACIPOL_IPSUM(RL, C, C1);
  } while (!(BS == MASSTOR_SIL));
  return C;
}

MASSTOR_LIST SACIPOL_IPPSR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_135_A, MASSTOR_LIST B)
# else
(RL, C_135_A, B)
MASSTOR_LIST RL, C_135_A, B;
# endif
{
  MASSTOR_LIST B1, BB, BS, C, C1, CL, IL, J1Y, LL, ML, NL;

  NL = SACPOL_PDEG(B);
  if (NL == 0) {
    C = 0;
    return C;
  }
  ML = SACPOL_PDEG(C_135_A);
  C = C_135_A;
  BB = SACPOL_PRED(B);
  J1Y = SACPOL_PLDCF(B);
  B1 = SACLIST_LIST2(0, J1Y);
  {
    LONGINT B_9 = ML, B_10 = NL;

    if (B_9 >= B_10)
      for (IL = B_9;; IL += -1) {
        if (C == 0) {
          return C;
        }
        LL = SACPOL_PDEG(C);
        if (LL == IL) {
          CL = SACPOL_PLDCF(C);
          C = SACPOL_PRED(C);
          C = SACIPOL_IPPROD(RL, C, B1);
          J1Y = LL - NL;
          C1 = SACLIST_LIST2(J1Y, CL);
          BS = SACIPOL_IPPROD(RL, BB, C1);
          C = SACIPOL_IPDIF(RL, C, BS);
        } else {
          C = SACIPOL_IPPROD(RL, C, B1);
        }
        if (IL <= B_10) break;
      }
  }
  return C;
}

MASSTOR_LIST SACIPOL_IPQ
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_134_A, MASSTOR_LIST B)
# else
(RL, C_134_A, B)
MASSTOR_LIST RL, C_134_A, B;
# endif
{
  MASSTOR_LIST C, R;

  if (RL == 0) {
    C = SACI_IQ(C_134_A, B);
  } else {
    SACIPOL_IPQR(RL, C_134_A, B, &C, &R);
  }
  return C;
}

void SACIPOL_IPQR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_133_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(RL, C_133_A, B, Q, R)
MASSTOR_LIST RL, C_133_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL;

  NL = SACPOL_PDEG(B);
  BL = SACPOL_PLDCF(B);
  BP = SACPOL_PRED(B);
  *Q = MASSTOR_BETA;
  *R = C_133_A;
  RLP = RL - 1;
  for (;;) {
    if (*R == 0) {
      goto EXIT_1;
    }
    ML = SACPOL_PDEG(*R);
    DL = ML - NL;
    if (DL < 0) {
      goto EXIT_1;
    }
    AL = SACPOL_PLDCF(*R);
    if (RLP == 0) {
      SACI_IQR(AL, BL, &QL, &SL);
    } else {
      SACIPOL_IPQR(RLP, AL, BL, &QL, &SL);
    }
    if (SL != 0) {
      goto EXIT_1;
    }
    *Q = SACLIST_COMP2(QL, DL, *Q);
    Q1 = SACLIST_LIST2(DL, QL);
    RP = SACPOL_PRED(*R);
    QP = SACIPOL_IPPROD(RL, BP, Q1);
    *R = SACIPOL_IPDIF(RL, RP, QP);
  } EXIT_1:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST SACIPOL_IPRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST N)
# else
(RL, KL, QL, N)
MASSTOR_LIST RL, KL, QL, N;
# endif
{
  MASSTOR_LIST C_132_A, AL, DL, EL, IDUM, NL, NP, QL1, QL2, QLS, RLP, TL;

  SACLIST_FIRST2(QL, &QL1, &QL2);
  SACD_DQR(QL1, 0, QL2, &QLS, &TL);
  if (RL == 0) {
    DL = SACD_DRANN();
    if (DL < QLS) {
      C_132_A = SACI_IRAND(KL);
    } else {
      C_132_A = 0;
    }
    return C_132_A;
  }
  RLP = RL - 1;
  MASSTOR_ADV(N, &NL, &NP);
  C_132_A = MASSTOR_BETA;
  {
    LONGINT B_11 = 0, B_12 = NL;

    if (B_11 <= B_12)
      for (EL = B_11;; EL += 1) {
        if (RLP == 0) {
          DL = SACD_DRANN();
          if (DL < QLS) {
            AL = SACI_IRAND(KL);
          } else {
            AL = 0;
          }
        } else {
          AL = SACIPOL_IPRAN(RLP, KL, QL, NP);
        }
        if (AL != 0) {
          C_132_A = SACLIST_COMP2(EL, AL, C_132_A);
        }
        if (EL >= B_12) break;
      }
  }
  if (C_132_A == MASSTOR_SIL) {
    C_132_A = 0;
  }
  return C_132_A;
}

void SACIPOL_IPREAD
# ifdef __STDC__
(MASSTOR_LIST *RL, MASSTOR_LIST *C_131_A, MASSTOR_LIST *V)
# else
(RL, C_131_A, V)
MASSTOR_LIST *RL, *C_131_A, *V;
# endif
{
  MASSTOR_LIST AL, C, EL, IDUM, RLP, VL;

  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    *C_131_A = SACI_IREAD();
    *RL = 0;
    *V = MASSTOR_BETA;
    return;
  }
  *C_131_A = MASSTOR_BETA;
  for (;;) {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      goto EXIT_2;
    }
    MASBIOS_BKSP();
    SACIPOL_IPREAD(&RLP, &AL, V);
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('*')) {
      goto EXIT_2;
    }
    VL = SACPOL_VREAD();
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('*')) {
      goto EXIT_2;
    }
    C = MASBIOS_CREAD();
    if (C != MASBIOS_MASORD('*')) {
      goto EXIT_2;
    }
    EL = SACLIST_AREAD();
    *C_131_A = SACLIST_COMP2(AL, EL, *C_131_A);
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(')')) {
      goto EXIT_2;
    } else {
      if (C == MASBIOS_MASORD('-')) {
        MASBIOS_BKSP();
      } else {
        if (C != MASBIOS_MASORD('+')) {
          goto EXIT_2;
        }
      }
    }
  } EXIT_2:;
  if (C != MASBIOS_MASORD(')')) {
    MASBIOS_SWRITE("error found by IPREAD.", 22L);
    MASBIOS_DIBUFF();
  }
  *C_131_A = MASSTOR_INV(*C_131_A);
  *RL = RLP + 1;
  *V = SACLIST_SUFFIX(*V, VL);
  return;
}

MASSTOR_LIST SACIPOL_IPSIGN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_130_A)
# else
(RL, C_130_A)
MASSTOR_LIST RL, C_130_A;
# endif
{
  MASSTOR_LIST J1Y, SL;

  J1Y = SACPOL_PLBCF(RL, C_130_A);
  SL = SACI_ISIGNF(J1Y);
  return SL;
}

MASSTOR_LIST SACIPOL_IPSMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_129_A, MASSTOR_LIST B)
# else
(RL, C_129_A, B)
MASSTOR_LIST RL, C_129_A, B;
# endif
{
  MASSTOR_LIST A2, AP, C, EL1, EL2, IL, RLP;

  if (C_129_A == 0) {
    C = 0;
    return C;
  }
  if (RL == 1) {
    C = SACIPOL_IPEMV(RL, C_129_A, B);
    return C;
  }
  RLP = RL - 1;
  SACLIST_ADV2(C_129_A, &EL1, &C, &AP);
  while (AP != MASSTOR_SIL) {
    SACLIST_ADV2(AP, &EL2, &A2, &AP);
    {
      LONGINT B_13 = 1, B_14 = EL1 - EL2;

      if (B_13 <= B_14)
        for (IL = B_13;; IL += 1) {
          C = SACIPOL_IPPROD(RLP, C, B);
          if (IL >= B_14) break;
        }
    }
    C = SACIPOL_IPSUM(RLP, C, A2);
    EL1 = EL2;
  }
  {
    LONGINT B_15 = 1, B_16 = EL1;

    if (B_15 <= B_16)
      for (IL = B_15;; IL += 1) {
        C = SACIPOL_IPPROD(RLP, C, B);
        if (IL >= B_16) break;
      }
  }
  return C;
}

MASSTOR_LIST SACIPOL_IPSUB
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_128_A, MASSTOR_LIST IL, MASSTOR_LIST B)
# else
(RL, C_128_A, IL, B)
MASSTOR_LIST RL, C_128_A, IL, B;
# endif
{
  MASSTOR_LIST A1, AP, C, C1, EL1, RLP;

  if (C_128_A == 0) {
    C = 0;
    return C;
  }
  if (IL == RL) {
    C = SACIPOL_IPSMV(RL, C_128_A, B);
    return C;
  }
  RLP = RL - 1;
  AP = C_128_A;
  C = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL1, &A1, &AP);
    C1 = SACIPOL_IPSUB(RLP, A1, IL, B);
    if (C1 != 0) {
      C = SACLIST_COMP2(C1, EL1, C);
    }
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST SACIPOL_IPSUM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_127_A, MASSTOR_LIST B)
# else
(RL, C_127_A, B)
MASSTOR_LIST RL, C_127_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, CP, EL, FL, RLP;

  if (C_127_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_127_A;
    return C;
  }
  if (RL == 0) {
    C = SACI_ISUM(C_127_A, B);
    return C;
  }
  AP = C_127_A;
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
          CL = SACI_ISUM(AL, BL);
        } else {
          CL = SACIPOL_IPSUM(RLP, AL, BL);
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

MASSTOR_LIST SACIPOL_IPSUMN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_126_A)
# else
(RL, C_126_A)
MASSTOR_LIST RL, C_126_A;
# endif
{
  MASSTOR_LIST AL1, AP, BL, BL1, EL1, RLP;

  if (RL == 0) {
    BL = SACI_IABSF(C_126_A);
    return BL;
  }
  BL = 0;
  if (C_126_A == 0) {
    return BL;
  }
  AP = C_126_A;
  RLP = RL - 1;
  do {
    SACLIST_ADV2(AP, &EL1, &AL1, &AP);
    if (RLP == 0) {
      BL1 = SACI_IABSF(AL1);
    } else {
      BL1 = SACIPOL_IPSUMN(RLP, AL1);
    }
    BL = SACI_ISUM(BL, BL1);
  } while (!(AP == MASSTOR_SIL));
  return BL;
}

MASSTOR_LIST SACIPOL_IPTPR
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_125_A, MASSTOR_LIST B)
# else
(RL, D, C_125_A, B)
MASSTOR_LIST RL, D, C_125_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, CL, CP, DP, EL, FL, J1Y, NL, RLP;

  if (C_125_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  DP = SACLIST_CINV(D);
  MASSTOR_ADV(DP, &NL, &DP);
  DP = MASSTOR_INV(DP);
  C = 0;
  if (NL == 0) {
    return C;
  }
  AS = SACLIST_CINV(C_125_A);
  BS = SACLIST_CINV(B);
  RLP = RL - 1;
  while (BS != MASSTOR_SIL && SACLIST_SECOND(BS) < NL) {
    SACLIST_ADV2(BS, &BL, &FL, &BS);
    AP = AS;
    CP = MASSTOR_BETA;
    while (AP != MASSTOR_SIL && SACLIST_SECOND(AP) < NL - FL) {
      SACLIST_ADV2(AP, &AL, &EL, &AP);
      if (RLP == 0) {
        CL = SACI_IPROD(AL, BL);
      } else {
        CL = SACIPOL_IPTPR(RLP, DP, AL, BL);
      }
      if (CL != 0) {
        J1Y = EL + FL;
        CP = SACLIST_COMP2(J1Y, CL, CP);
      }
    }
    if (CP != MASSTOR_SIL) {
      C = SACIPOL_IPSUM(RL, C, CP);
    }
  }
  return C;
}

MASSTOR_LIST SACIPOL_IPTRAN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_124_A, MASSTOR_LIST T)
# else
(RL, C_124_A, T)
MASSTOR_LIST RL, C_124_A, T;
# endif
{
  MASSTOR_LIST B, BL, BLP, BP, EL, RLP, TL, TP;

  MASSTOR_ADV(T, &TL, &TP);
  B = SACIPOL_IPTRMV(RL, C_124_A, TL);
  RLP = RL - 1;
  if (RLP == 0 || B == 0) {
    return B;
  }
  BP = B;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(BP, &EL, &BLP, &BP);
    BL = SACIPOL_IPTRAN(RLP, BLP, TP);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(BP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACIPOL_IPTRMV
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_123_A, MASSTOR_LIST HL)
# else
(RL, C_123_A, HL)
MASSTOR_LIST RL, C_123_A, HL;
# endif
{
  MASSTOR_LIST AL, ALB, AP, B, B1, B2, EL, ELP, IL;

  if (C_123_A == 0 || HL == 0) {
    B = C_123_A;
    return B;
  }
  SACLIST_ADV2(C_123_A, &EL, &AL, &AP);
  B = SACLIST_LIST2(0, AL);
  for (;;) {
    if (AP == MASSTOR_SIL) {
      ELP = 0;
    } else {
      ELP = MASSTOR_FIRST(AP);
    }
    {
      LONGINT B_17 = 1, B_18 = EL - ELP;

      if (B_17 <= B_18)
        for (IL = B_17;; IL += 1) {
          B1 = SACPOL_PMPMV(B, 1);
          B2 = SACIPOL_IPIP(RL, HL, B);
          B = SACIPOL_IPSUM(RL, B1, B2);
          if (IL >= B_18) break;
        }
    }
    if (AP == MASSTOR_SIL) {
      return B;
    }
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    ALB = SACLIST_LIST2(0, AL);
    B = SACIPOL_IPSUM(RL, B, ALB);
  } EXIT_3:;
}

MASSTOR_LIST SACIPOL_IPTRUN
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST D, MASSTOR_LIST C_122_A)
# else
(RL, D, C_122_A)
MASSTOR_LIST RL, D, C_122_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, DL, DP, EL, RLP;

  if (RL == 0 || C_122_A == 0) {
    B = C_122_A;
    return B;
  }
  RLP = RL - 1;
  AS = SACLIST_CINV(C_122_A);
  B = MASSTOR_BETA;
  DP = SACLIST_CINV(D);
  MASSTOR_ADV(DP, &DL, &DP);
  DP = MASSTOR_INV(DP);
  while (AS != MASSTOR_SIL && SACLIST_SECOND(AS) < DL) {
    SACLIST_ADV2(AS, &AL, &EL, &AS);
    if (RLP == 0) {
      BL = AL;
    } else {
      BL = SACIPOL_IPTRUN(RLP, DP, AL);
    }
    if (BL != 0) {
      B = SACLIST_COMP2(EL, BL, B);
    }
  }
  if (B == MASSTOR_SIL) {
    B = 0;
  }
  return B;
}

void SACIPOL_IPWRIT
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_121_A, MASSTOR_LIST V)
# else
(RL, C_121_A, V)
MASSTOR_LIST RL, C_121_A, V;
# endif
{
  MASSTOR_LIST AL, AP, EL, IL, RLP, V1, VB, VP;

  if (RL == 0 || C_121_A == 0) {
    SACI_IWRITE(C_121_A);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  AP = C_121_A;
  RLP = RL - 1;
  VB = SACLIST_CINV(V);
  MASSTOR_ADV(VB, &V1, &VP);
  VP = MASSTOR_INV(VP);
  IL = 0;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (IL != 0 && (RL > 1 || SACI_ISIGNF(AL) > 0)) {
      MASBIOS_SWRITE("+", 1L);
    }
    if (RLP == 0) {
      SACI_IWRITE(AL);
    } else {
      SACIPOL_IPWRIT(RLP, AL, VP);
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

MASSTOR_LIST SACIPOL_IUPBEI
# ifdef __STDC__
(MASSTOR_LIST C_120_A, MASSTOR_LIST CL, MASSTOR_LIST ML)
# else
(C_120_A, CL, ML)
MASSTOR_LIST C_120_A, CL, ML;
# endif
{
  MASSTOR_LIST AL, ALP, AP, BL, EL, J1Y, KL, NL;

  if (C_120_A == 0) {
    BL = 0;
    return BL;
  }
  SACLIST_ADV2(C_120_A, &NL, &BL, &AP);
  KL = 1;
  while (KL <= NL) {
    BL = SACI_IPROD(BL, CL);
    if (AP != MASSTOR_SIL && MASSTOR_FIRST(AP) == NL - KL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
      J1Y = ML * KL;
      J1Y = -J1Y;
      ALP = SACI_ITRUNC(AL, J1Y);
      BL = SACI_ISUM(BL, ALP);
    }
    KL = KL + 1;
  }
  return BL;
}

MASSTOR_LIST SACIPOL_IUPBES
# ifdef __STDC__
(MASSTOR_LIST C_119_A, MASSTOR_LIST AL)
# else
(C_119_A, AL)
MASSTOR_LIST C_119_A, AL;
# endif
{
  MASSTOR_LIST BL, CL, DL, ML, SL;

  if (C_119_A == 0) {
    SL = 0;
  } else {
    if (AL == 0) {
      CL = 0;
      ML = 0;
    } else {
      SACLIST_FIRST2(AL, &CL, &DL);
      ML = SACI_IORD2(DL);
    }
    BL = SACIPOL_IUPBEI(C_119_A, CL, ML);
    SL = SACI_ISIGNF(BL);
  }
  return SL;
}

MASSTOR_LIST SACIPOL_IUPBHT
# ifdef __STDC__
(MASSTOR_LIST C_118_A, MASSTOR_LIST KL)
# else
(C_118_A, KL)
MASSTOR_LIST C_118_A, KL;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, HL, J1Y, ML, NL;

  AP = C_118_A;
  HL = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    ML = SACI_IORD2(AL);
    J1Y = KL * EL;
    NL = J1Y + ML;
    if (NL < HL) {
      HL = NL;
    }
  } while (!(AP == MASSTOR_SIL));
  AP = C_118_A;
  B = MASSTOR_BETA;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    J1Y = KL * EL;
    J1Y = HL - J1Y;
    BL = SACI_ITRUNC(AL, J1Y);
    B = SACLIST_COMP2(BL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACIPOL_IUPBRE
# ifdef __STDC__
(MASSTOR_LIST C_117_A, MASSTOR_LIST AL)
# else
(C_117_A, AL)
MASSTOR_LIST C_117_A, AL;
# endif
{
  MASSTOR_LIST BL, BL1, BL2, CL, DL, HL, KL, ML, NL;

  BL = 0;
  if (C_117_A == 0) {
    return BL;
  }
  if (AL == 0) {
    CL = 0;
    ML = 0;
  } else {
    SACLIST_FIRST2(AL, &CL, &DL);
    ML = SACI_IORD2(DL);
  }
  BL1 = SACIPOL_IUPBEI(C_117_A, CL, ML);
  if (BL1 == 0) {
    return BL;
  }
  KL = SACI_IORD2(BL1);
  NL = MASSTOR_FIRST(C_117_A);
  HL = ML * NL;
  if (KL >= HL) {
    BL1 = SACI_ITRUNC(BL1, HL);
    BL2 = 1;
  } else {
    BL1 = SACI_ITRUNC(BL1, KL);
    HL = HL - KL;
    BL2 = SACI_IMP2(1, HL);
  }
  BL = SACLIST_LIST2(BL1, BL2);
  return BL;
}

MASSTOR_LIST SACIPOL_IUPCHT
# ifdef __STDC__
(MASSTOR_LIST C_116_A)
# else
(C_116_A)
MASSTOR_LIST C_116_A;
# endif
{
  MASSTOR_LIST AP, B;

  AP = SACPOL_PRT(C_116_A);
  B = SACIPOL_IUPTR1(AP);
  return B;
}

MASSTOR_LIST SACIPOL_IUPNT
# ifdef __STDC__
(MASSTOR_LIST C_115_A)
# else
(C_115_A)
MASSTOR_LIST C_115_A;
# endif
{
  MASSTOR_LIST AL, AP, B, EL;

  if (C_115_A == 0) {
    B = 0;
    return B;
  }
  B = MASSTOR_BETA;
  AP = C_115_A;
  do {
    SACLIST_ADV2(AP, &EL, &AL, &AP);
    if (MASELEM_MASODD(EL)) {
      AL = SACI_INEG(AL);
    }
    B = SACLIST_COMP2(AL, EL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST SACIPOL_IUPTPR
# ifdef __STDC__
(MASSTOR_LIST NL, MASSTOR_LIST C_114_A, MASSTOR_LIST B)
# else
(NL, C_114_A, B)
MASSTOR_LIST NL, C_114_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, CL, CP, EL, FL, J1Y;

  C = 0;
  if (NL == 0 || C_114_A == 0 || B == 0) {
    return C;
  }
  AS = SACLIST_CINV(C_114_A);
  BS = SACLIST_CINV(B);
  while (BS != MASSTOR_SIL && SACLIST_SECOND(BS) < NL) {
    SACLIST_ADV2(BS, &BL, &FL, &BS);
    AP = AS;
    CP = MASSTOR_BETA;
    while (AP != MASSTOR_SIL && SACLIST_SECOND(AP) < NL - FL) {
      SACLIST_ADV2(AP, &AL, &EL, &AP);
      CL = SACI_IPROD(AL, BL);
      J1Y = EL + FL;
      CP = SACLIST_COMP2(J1Y, CL, CP);
    }
    if (CP != MASSTOR_SIL) {
      C = SACIPOL_IPSUM(1, C, CP);
    }
  }
  return C;
}

MASSTOR_LIST SACIPOL_IUPTR
# ifdef __STDC__
(MASSTOR_LIST C_113_A, MASSTOR_LIST HL)
# else
(C_113_A, HL)
MASSTOR_LIST C_113_A, HL;
# endif
{
  MASSTOR_LIST AL, B, BL, IL, JL, L, LP, NL;

  NL = SACPOL_PDEG(C_113_A);
  if (NL == 0) {
    B = C_113_A;
    return B;
  }
  L = SACPOL_PCL(C_113_A);
  for (IL = NL; IL >= 1; IL += -1) {
    MASSTOR_ADV(L, &AL, &LP);
    {
      LONGINT B_19 = 1, B_20 = IL;

      if (B_19 <= B_20)
        for (JL = B_19;; JL += 1) {
          BL = MASSTOR_FIRST(LP);
          AL = SACI_IPROD(AL, HL);
          AL = SACI_ISUM(AL, BL);
          MASSTOR_SFIRST(LP, AL);
          LP = MASSTOR_RED(LP);
          if (JL >= B_20) break;
        }
    }
  }
  B = MASSTOR_BETA;
  L = MASSTOR_INV(L);
  {
    LONGINT B_21 = 0, B_22 = NL;

    if (B_21 <= B_22)
      for (IL = B_21;; IL += 1) {
        MASSTOR_ADV(L, &AL, &L);
        if (AL != 0) {
          B = SACLIST_COMP2(IL, AL, B);
        }
        if (IL >= B_22) break;
      }
  }
  return B;
}

MASSTOR_LIST SACIPOL_IUPTR1
# ifdef __STDC__
(MASSTOR_LIST C_112_A)
# else
(C_112_A)
MASSTOR_LIST C_112_A;
# endif
{
  struct S_1 PAD;
  MASSTOR_LIST AL, AL1, ALP, AP, B, CL, EL, FL, FLB, J1Y, J2Y, NL, SL;
  INTEGER ML, JL, HL, IL, KL, TL;

  NL = SACPOL_PDEG(C_112_A);
  if (NL == 0) {
    B = C_112_A;
    return B;
  }
  FLB = 0;
  AP = C_112_A;
  do {
    AP = MASSTOR_RED(AP);
    MASSTOR_ADV(AP, &AL, &AP);
    FL = SACI_ILOG2(AL);
    if (FL > FLB) {
      FLB = FL;
    }
  } while (!(AP == MASSTOR_SIL));
  KL = (INTEGER)((FLB + NL + SACD_ZETA - 1) / SACD_ZETA);
  ML = KL * ((INTEGER)NL + 1);
  if (ML > 500) {
    MASBIOS_SWRITE("array PAD too small for IUPTR1", 30L);
    return 0;
  }
  AP = C_112_A;
  IL = 1;
  for (HL = (INTEGER)NL; HL >= 0; HL += -1) {
    if (AP == MASSTOR_SIL) {
      EL = -1;
    } else {
      EL = MASSTOR_FIRST(AP);
    }
    if ((INTEGER)EL == HL) {
      SACLIST_ADV2(AP, &EL, &AL, &AP);
    } else {
      AL = 0;
    }
    ALP = AL;
    if (ALP < MASSTOR_BETA) {
      ALP = MASSTOR_LIST1(ALP);
    }
    {
      LONGINT B_23 = 1, B_24 = KL;

      if (B_23 <= B_24)
        for (JL = B_23;; JL += 1) {
          if (ALP != MASSTOR_SIL) {
            MASSTOR_ADV(ALP, &AL1, &ALP);
          } else {
            AL1 = 0;
          }
          PAD.A[IL - 1] = AL1;
          IL = IL + 1;
          if (JL >= B_24) break;
        }
    }
  }
  for (HL = (INTEGER)NL; HL >= 1; HL += -1) {
    CL = 0;
    ML = ML - KL;
    {
      LONGINT B_25 = 1, B_26 = ML;

      if (B_25 <= B_26)
        for (IL = B_25;; IL += 1) {
          SL = PAD.A[IL - 1] + PAD.A[IL + KL - 1] + CL;
          CL = 0;
          if (SL >= MASSTOR_BETA) {
            SL = SL - MASSTOR_BETA;
            CL = 1;
          } else {
            if (SL <= -MASSTOR_BETA) {
              SL = SL + MASSTOR_BETA;
              CL = -1;
            }
          }
          PAD.A[IL + KL - 1] = SL;
          if (IL >= B_26) break;
        }
    }
  }
  B = MASSTOR_SIL;
  EL = 0;
  IL = KL * (INTEGER)NL;
  do {
    AL = MASSTOR_BETA;
    JL = KL;
    do {
      SL = PAD.A[IL + JL - 1];
      JL = JL - 1;
    } while (!(SL != 0 || JL == 0));
    if (SL != 0) {
      CL = 0;
      HL = IL + 1;
      JL = JL + 1;
      {
        LONGINT B_27 = 1, B_28 = JL;

        if (B_27 <= B_28)
          for (TL = B_27;; TL += 1) {
            AL1 = PAD.A[HL - 1] + CL;
            CL = 0;
            if (SL > 0 && AL1 < 0) {
              AL1 = AL1 + MASSTOR_BETA;
              CL = -1;
            }
            if (SL < 0 && AL1 > 0) {
              AL1 = AL1 - MASSTOR_BETA;
              CL = 1;
            }
            AL = MASSTOR_COMP(AL1, AL);
            HL = HL + 1;
            if (TL >= B_28) break;
          }
      }
      while (MASSTOR_FIRST(AL) == 0) {
        AL = MASSTOR_RED(AL);
      }
      if (MASSTOR_RED(AL) == MASSTOR_SIL) {
        AL = MASSTOR_FIRST(AL);
      } else {
        AL = MASSTOR_INV(AL);
      }
      B = SACLIST_COMP2(EL, AL, B);
    }
    EL = EL + 1;
    IL = IL - KL;
  } while (!(EL > NL));
  return B;
}

void BEGIN_SACIPOL()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACD();
    BEGIN_SACM();
    BEGIN_SACI();
    BEGIN_SACPOL();

  }
}
