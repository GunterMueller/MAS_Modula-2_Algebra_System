#include "SYSTEM_.h"

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_DOMIP
#include "DOMIP.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

CHAR MASADOM_rcsid [] = "$Id: MASADOM.md,v 1.12 1995/03/06 15:53:26 pesch Exp $";
CHAR MASADOM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define maxdom	30
typedef struct S_1 {
    MASADOM_PROCF1 A[maxdom - 1 + 1];
} funcf1;
typedef struct S_2 {
    MASSTOR_LIST name;
    MASSTOR_LIST Sym;
    MASADOM_PROCF1 AbsFunc;
    MASADOM_PROCF1B CnstFunc;
    funcf1 ConvFunc;
    MASADOM_PROCF2 CompFunc;
    MASADOM_PROCF2 DifFunc;
    MASADOM_PROCF2 ExpFunc;
    MASADOM_PROCF1 FactFunc;
    MASADOM_PROCF1 FactoFunc;
    MASADOM_PROCF2 FIntFunc;
    MASADOM_PROCF2 FIPolFunc;
    MASADOM_PROCF2 GcdFunc;
    MASADOM_PROCP2V3 GcdcFunc;
    MASADOM_PROCP2V3 GcdeFunc;
    MASADOM_PROCF1 InvFunc;
    MASADOM_PROCF1 InvTFunc;
    MASADOM_PROCF2 LcmFunc;
    MASADOM_PROCF1 NegFunc;
    MASADOM_PROCF1 OneFunc;
    MASADOM_PROCF2 ProdFunc;
    MASADOM_PROCF2 QuotFunc;
    MASADOM_PROCP2V2 QrFunc;
    MASADOM_PROCF1 ReadFunc;
    MASADOM_PROCF2 RemFunc;
    MASADOM_PROCF1 SignFunc;
    MASADOM_PROCF2 SumFunc;
    MASADOM_PROCF1V1 ToipFunc;
    MASADOM_PROCP1 WritFunc;
    MASADOM_PROCF1 VlddFunc;
    MASADOM_PROCF0 DdrdFunc;
    MASADOM_PROCP1 DdwrFunc;
} DomRec;
typedef struct S_3 {
    MASADOM_PROCF1 PFactFunc;
    MASADOM_PROCF2 PNormFunc;
    MASADOM_PROCF2 PSpolFunc;
    MASADOM_PROCF1 PSqfrFunc;
    MASADOM_PROCF2 PSugNormFunc;
    MASADOM_PROCF2 PSugSpolFunc;
    MASADOM_PROCP1V2 PCppFunc;
} DomPRec;
static struct S_4 {
    DomRec A[maxdom - 1 + 1];
} domain;
static struct S_5 {
    DomPRec A[maxdom - 1 + 1];
} Pdomain;
static INTEGER curdom;
static MASSTOR_LIST Dummy;
static CHAR rcsidi [] = "$Id: MASADOM.mi,v 1.15 1995/03/06 15:53:27 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST Dummyf0 ARGS(());
static void Dummyp1 ARGS((MASSTOR_LIST C_99_A));
static MASSTOR_LIST Dummyf1 ARGS((MASSTOR_LIST C_98_A));
static MASSTOR_LIST Dummyf2 ARGS((MASSTOR_LIST C_97_A, MASSTOR_LIST B));
static BOOLEAN Dummyf1b ARGS((MASSTOR_LIST C_96_A));
static MASSTOR_LIST Dummyf1v1 ARGS((MASSTOR_LIST C_95_A, MASSTOR_LIST *B));
static void Dummyp1v2 ARGS((MASSTOR_LIST C_94_A, MASSTOR_LIST *C, MASSTOR_LIST *D));
static void Dummyp2v2 ARGS((MASSTOR_LIST C_93_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D));
static void Dummyp2v3 ARGS((MASSTOR_LIST C_92_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D, MASSTOR_LIST *E));
static void InitADom ARGS(());
static void InitADomP ARGS(());


MASSTOR_LIST MASADOM_ADABSF
# ifdef __STDC__
(MASSTOR_LIST C_128_A)
# else
(C_128_A)
MASSTOR_LIST C_128_A;
# endif
{
  MASSTOR_LIST C, CP, AL, AP;

  MASSTOR_ADV(C_128_A, &AL, &AP);
  if ((ADDRESS)domain.A[(INTEGER)AL - 1].AbsFunc == (ADDRESS)Dummyf1) {
    if ((*domain.A[(INTEGER)AL - 1].SignFunc)(AP) == -1) {
      CP = (*domain.A[(INTEGER)AL - 1].NegFunc)(AP);
    } else {
      return C_128_A;
    }
  } else {
    CP = (*domain.A[(INTEGER)AL - 1].AbsFunc)(AP);
  }
  C = MASSTOR_COMP(AL, CP);
  return C;
}

BOOLEAN MASADOM_ADCNST
# ifdef __STDC__
(MASSTOR_LIST C_127_A)
# else
(C_127_A)
MASSTOR_LIST C_127_A;
# endif
{
  MASSTOR_LIST AL, AP;

  MASSTOR_ADV(C_127_A, &AL, &AP);
  return (*domain.A[(INTEGER)AL - 1].CnstFunc)(AP);
}

MASSTOR_LIST MASADOM_ADCOMP
# ifdef __STDC__
(MASSTOR_LIST C_126_A, MASSTOR_LIST B)
# else
(C_126_A, B)
MASSTOR_LIST C_126_A, B;
# endif
{
  MASSTOR_LIST SL, AL, AP, BL, BP, CP;

  MASSTOR_ADV(C_126_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADCOMP: incompatible domains", 28L);
    return MASSTOR_SIL;
  }
  if ((ADDRESS)domain.A[(INTEGER)AL - 1].CompFunc == (ADDRESS)Dummyf2) {
    CP = (*domain.A[(INTEGER)AL - 1].DifFunc)(AP, BP);
    SL = (*domain.A[(INTEGER)AL - 1].SignFunc)(CP);
  } else {
    SL = (*domain.A[(INTEGER)AL - 1].CompFunc)(AP, BP);
  }
  return SL;
}

MASSTOR_LIST MASADOM_ADCONV
# ifdef __STDC__
(MASSTOR_LIST C_125_A, MASSTOR_LIST B)
# else
(C_125_A, B)
MASSTOR_LIST C_125_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_125_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CP = (*domain.A[(INTEGER)AL - 1].ConvFunc.A[(INTEGER)BL - 1])(BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADDIF
# ifdef __STDC__
(MASSTOR_LIST C_124_A, MASSTOR_LIST B)
# else
(C_124_A, B)
MASSTOR_LIST C_124_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_124_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADDIF: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].DifFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADEXP
# ifdef __STDC__
(MASSTOR_LIST C_123_A, MASSTOR_LIST NL)
# else
(C_123_A, NL)
MASSTOR_LIST C_123_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CP;

  MASSTOR_ADV(C_123_A, &AL, &AP);
  CP = (*domain.A[(INTEGER)AL - 1].ExpFunc)(AP, NL);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADFACT
# ifdef __STDC__
(MASSTOR_LIST C_122_A)
# else
(C_122_A)
MASSTOR_LIST C_122_A;
# endif
{
  MASSTOR_LIST AL, AP, FL, FL1, RET;

  MASSTOR_ADV(C_122_A, &AL, &AP);
  FL = (*domain.A[(INTEGER)AL - 1].FactFunc)(AP);
  RET = MASSTOR_SIL;
  while (FL != MASSTOR_SIL) {
    MASSTOR_ADV(FL, &FL1, &FL);
    RET = MASSTOR_COMP(MASSTOR_COMP(AL, FL1), RET);
  }
  return RET;
}

MASSTOR_LIST MASADOM_ADFACTO
# ifdef __STDC__
(MASSTOR_LIST C_121_A)
# else
(C_121_A)
MASSTOR_LIST C_121_A;
# endif
{
  MASSTOR_LIST AL, AP, FL, FL1, RET;

  MASSTOR_ADV(C_121_A, &AL, &AP);
  FL = (*domain.A[(INTEGER)AL - 1].FactoFunc)(AP);
  RET = MASSTOR_SIL;
  while (FL != MASSTOR_SIL) {
    MASSTOR_ADV(FL, &FL1, &FL);
    RET = MASSTOR_COMP(MASSTOR_COMP(AL, FL1), RET);
  }
  return RET;
}

MASSTOR_LIST MASADOM_ADFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_120_A)
# else
(D, C_120_A)
MASSTOR_LIST D, C_120_A;
# endif
{
  MASSTOR_LIST C, CP, DP, d;

  MASSTOR_ADV(D, &d, &DP);
  CP = (*domain.A[(INTEGER)d - 1].FIntFunc)(DP, C_120_A);
  C = MASSTOR_COMP(d, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_119_A)
# else
(D, C_119_A)
MASSTOR_LIST D, C_119_A;
# endif
{
  MASSTOR_LIST C, CP, DP, d;

  MASSTOR_ADV(D, &d, &DP);
  CP = (*domain.A[(INTEGER)d - 1].FIPolFunc)(DP, C_119_A);
  C = MASSTOR_COMP(d, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADGCD
# ifdef __STDC__
(MASSTOR_LIST C_118_A, MASSTOR_LIST B)
# else
(C_118_A, B)
MASSTOR_LIST C_118_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_118_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADGCD: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].GcdFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

void MASADOM_ADGCDC
# ifdef __STDC__
(MASSTOR_LIST C_117_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AA, MASSTOR_LIST *BB)
# else
(C_117_A, B, C, AA, BB)
MASSTOR_LIST C_117_A, B;
MASSTOR_LIST *C, *AA, *BB;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, AAP, BBP, CP;

  MASSTOR_ADV(C_117_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADGCDC: incompatible domains", 28L);
    *C = MASSTOR_SIL;
    *AA = MASSTOR_SIL;
    *BB = MASSTOR_SIL;
    return;
  }
  (*domain.A[(INTEGER)AL - 1].GcdcFunc)(AP, BP, &CP, &AAP, &BBP);
  *C = MASSTOR_COMP(AL, CP);
  *AA = MASSTOR_COMP(AL, AAP);
  *BB = MASSTOR_COMP(AL, BBP);
}

void MASADOM_ADGCDE
# ifdef __STDC__
(MASSTOR_LIST C_116_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AA, MASSTOR_LIST *BB)
# else
(C_116_A, B, C, AA, BB)
MASSTOR_LIST C_116_A, B;
MASSTOR_LIST *C, *AA, *BB;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, AAP, BBP, CP;

  MASSTOR_ADV(C_116_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADGCDE: incompatible domains", 28L);
    *C = MASSTOR_SIL;
    *AA = MASSTOR_SIL;
    *BB = MASSTOR_SIL;
    return;
  }
  (*domain.A[(INTEGER)AL - 1].GcdeFunc)(AP, BP, &CP, &AAP, &BBP);
  *C = MASSTOR_COMP(AL, CP);
  *AA = MASSTOR_COMP(AL, AAP);
  *BB = MASSTOR_COMP(AL, BBP);
}

MASSTOR_LIST MASADOM_ADINV
# ifdef __STDC__
(MASSTOR_LIST C_115_A)
# else
(C_115_A)
MASSTOR_LIST C_115_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CP;

  MASSTOR_ADV(C_115_A, &AL, &AP);
  CP = (*domain.A[(INTEGER)AL - 1].InvFunc)(AP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADINVT
# ifdef __STDC__
(MASSTOR_LIST C_114_A)
# else
(C_114_A)
MASSTOR_LIST C_114_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_114_A, &AL, &AP);
  TL = (*domain.A[(INTEGER)AL - 1].InvTFunc)(AP);
  return TL;
}

MASSTOR_LIST MASADOM_ADLCM
# ifdef __STDC__
(MASSTOR_LIST C_113_A, MASSTOR_LIST B)
# else
(C_113_A, B)
MASSTOR_LIST C_113_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_113_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADLCM: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].LcmFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADNEG
# ifdef __STDC__
(MASSTOR_LIST C_112_A)
# else
(C_112_A)
MASSTOR_LIST C_112_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CP;

  MASSTOR_ADV(C_112_A, &AL, &AP);
  CP = (*domain.A[(INTEGER)AL - 1].NegFunc)(AP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADONE
# ifdef __STDC__
(MASSTOR_LIST C_111_A)
# else
(C_111_A)
MASSTOR_LIST C_111_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_111_A, &AL, &AP);
  SL = (*domain.A[(INTEGER)AL - 1].OneFunc)(AP);
  return SL;
}

void MASADOM_ADPCPP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *c, MASSTOR_LIST *pp)
# else
(P, c, pp)
MASSTOR_LIST P;
MASSTOR_LIST *c, *pp;
# endif
{
  MASSTOR_LIST d;

  if (P == 0) {
    *c = 0;
    *pp = 0;
    return;
  }
  d = DIPTOOLS_ADDNFDIP(P);
  (*Pdomain.A[(INTEGER)d - 1].PCppFunc)(P, c, pp);
}

MASSTOR_LIST MASADOM_ADPFACT
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST VOO)
# else
(P, VOO)
MASSTOR_LIST P, VOO;
# endif
{
  MASSTOR_LIST coe, d, rest, F, F1, ExpPol, exp, pol, Tord, OVL, PV, IPV;

  if (P == MASSTOR_SIL) {
    return P;
  }
  coe = SACLIST_SECOND(P);
  MASSTOR_ADV(coe, &d, &coe);
  rest = MASSTOR_RED(coe);
  P = DIPC_AD2DIP(P);
  if (VOO == 1) {
    OVL = DIPC_VALIS;
    DIPTOO_DIPVOPP(MASSTOR_LIST1(P), OVL, &P, &DIPC_VALIS, &PV);
    P = MASSTOR_FIRST(P);
    IPV = DIPTOO_INVPERM(PV);
  }
  Tord = DIPC_EVORD;
  DIPC_EVORD = 2;
  if (Tord != 2) {
    DIPC_DIPBSO(P);
  }
  F = (*Pdomain.A[(INTEGER)d - 1].PFactFunc)(P);
  if (VOO == 1) {
    DIPC_VALIS = OVL;
  }
  if (Tord != 2) {
    DIPC_EVORD = Tord;
  }
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    if (VOO == 1) {
      pol = DIPC_DIPERM(pol, IPV);
    }
    if (Tord != 2) {
      DIPC_DIPBSO(pol);
    }
    pol = DIPC_DIP2AD(pol, d, rest);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

MASSTOR_LIST MASADOM_ADPNF
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P)
# else
(G, P)
MASSTOR_LIST G, P;
# endif
{
  MASSTOR_LIST DomNum;

  DomNum = DIPTOOLS_ADDNFDIP(P);
  if (DomNum == 0) {
    return 0;
  } else {
    return (*Pdomain.A[(INTEGER)DomNum - 1].PNormFunc)(G, P);
  }
}

MASSTOR_LIST MASADOM_ADPROD
# ifdef __STDC__
(MASSTOR_LIST C_110_A, MASSTOR_LIST B)
# else
(C_110_A, B)
MASSTOR_LIST C_110_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_110_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADPROD: incompatible domains", 28L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].ProdFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADPSFF
# ifdef __STDC__
(MASSTOR_LIST C_109_A, MASSTOR_LIST VOO)
# else
(C_109_A, VOO)
MASSTOR_LIST C_109_A, VOO;
# endif
{
  MASSTOR_LIST coe, d, rest, Tord, F, F1, ExpPol, exp, pol, OVL, PV, IPV;

  if (C_109_A == MASSTOR_SIL) {
    return C_109_A;
  }
  coe = SACLIST_SECOND(C_109_A);
  MASSTOR_ADV(coe, &d, &coe);
  rest = MASSTOR_RED(coe);
  C_109_A = DIPC_AD2DIP(C_109_A);
  if (VOO == 1) {
    OVL = DIPC_VALIS;
    DIPTOO_DIPVOPP(MASSTOR_LIST1(C_109_A), OVL, &C_109_A, &DIPC_VALIS, &PV);
    C_109_A = MASSTOR_FIRST(C_109_A);
    IPV = DIPTOO_INVPERM(PV);
  }
  Tord = DIPC_EVORD;
  DIPC_EVORD = 2;
  if (Tord != 2) {
    DIPC_DIPBSO(C_109_A);
  }
  F = (*Pdomain.A[(INTEGER)d - 1].PSqfrFunc)(C_109_A);
  if (VOO == 1) {
    DIPC_VALIS = OVL;
  }
  if (Tord != 2) {
    DIPC_EVORD = Tord;
  }
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    if (VOO == 1) {
      pol = DIPC_DIPERM(pol, IPV);
    }
    if (Tord != 2) {
      DIPC_DIPBSO(pol);
    }
    pol = DIPC_DIP2AD(pol, d, rest);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

MASSTOR_LIST MASADOM_ADPSP
# ifdef __STDC__
(MASSTOR_LIST C_108_A, MASSTOR_LIST B)
# else
(C_108_A, B)
MASSTOR_LIST C_108_A, B;
# endif
{
  MASSTOR_LIST DomNumA, DomNumB;

  DomNumA = DIPTOOLS_ADDNFDIP(C_108_A);
  DomNumB = DIPTOOLS_ADDNFDIP(B);
  if (DomNumA == 0 || DomNumB == 0) {
    return 0;
  }
  if (DomNumA == DomNumB) {
    return (*Pdomain.A[(INTEGER)DomNumA - 1].PSpolFunc)(C_108_A, B);
  } else {
    MASERR_ERROR(MASERR_fatal, "ADPSP: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
}

MASSTOR_LIST MASADOM_ADPSUGNF
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P)
# else
(G, P)
MASSTOR_LIST G, P;
# endif
{
  MASSTOR_LIST DomNum;

  DomNum = DIPAGB_ADDNFEDIP(P);
  if (DomNum == 0) {
    return P;
  } else {
    return (*Pdomain.A[(INTEGER)DomNum - 1].PSugNormFunc)(G, P);
  }
}

MASSTOR_LIST MASADOM_ADPSUGSP
# ifdef __STDC__
(MASSTOR_LIST C_107_A, MASSTOR_LIST B)
# else
(C_107_A, B)
MASSTOR_LIST C_107_A, B;
# endif
{
  MASSTOR_LIST DomNumA, DomNumB;

  DomNumA = DIPAGB_ADDNFEDIP(C_107_A);
  DomNumB = DIPAGB_ADDNFEDIP(B);
  if (DomNumA == 0 && DomNumB == 0) {
    return DIPAGB_EDIPSUGSP(C_107_A, B);
  }
  if (DomNumA == 0) {
    return (*Pdomain.A[(INTEGER)DomNumB - 1].PSugSpolFunc)(C_107_A, B);
  }
  if (DomNumB == 0) {
    return (*Pdomain.A[(INTEGER)DomNumA - 1].PSugSpolFunc)(C_107_A, B);
  }
  if (DomNumA == DomNumB) {
    return (*Pdomain.A[(INTEGER)DomNumA - 1].PSugSpolFunc)(C_107_A, B);
  } else {
    MASERR_ERROR(MASERR_fatal, "ADPSUGSP: incompatible domains", 30L);
    return MASSTOR_SIL;
  }
}

void MASADOM_ADQR
# ifdef __STDC__
(MASSTOR_LIST C_106_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(C_106_A, B, Q, R)
MASSTOR_LIST C_106_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, QP, RP;

  MASSTOR_ADV(C_106_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADQR: incompatible domains", 26L);
    *Q = MASSTOR_SIL;
    *R = MASSTOR_SIL;
    return;
  }
  (*domain.A[(INTEGER)AL - 1].QrFunc)(AP, BP, &QP, &RP);
  *Q = MASSTOR_COMP(AL, QP);
  *R = MASSTOR_COMP(AL, RP);
  return;
}

MASSTOR_LIST MASADOM_ADQUOT
# ifdef __STDC__
(MASSTOR_LIST C_105_A, MASSTOR_LIST B)
# else
(C_105_A, B)
MASSTOR_LIST C_105_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_105_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADQUOT: incompatible domains", 28L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].QuotFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADREAD
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST DL, DP, C, CP;

  MASSTOR_ADV(D, &DL, &DP);
  CP = (*domain.A[(INTEGER)DL - 1].ReadFunc)(DP);
  C = MASSTOR_COMP(DL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADREM
# ifdef __STDC__
(MASSTOR_LIST C_104_A, MASSTOR_LIST B)
# else
(C_104_A, B)
MASSTOR_LIST C_104_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, Q, QP, R, RP;

  MASSTOR_ADV(C_104_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADREM: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
  if ((ADDRESS)domain.A[(INTEGER)AL - 1].RemFunc == (ADDRESS)Dummyp2v2) {
    (*domain.A[(INTEGER)AL - 1].QrFunc)(AP, BP, &QP, &RP);
  } else {
    RP = (*domain.A[(INTEGER)AL - 1].RemFunc)(AP, BP);
  }
  R = MASSTOR_COMP(AL, RP);
  return R;
}

MASSTOR_LIST MASADOM_ADSIGN
# ifdef __STDC__
(MASSTOR_LIST C_103_A)
# else
(C_103_A)
MASSTOR_LIST C_103_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_103_A, &AL, &AP);
  SL = (*domain.A[(INTEGER)AL - 1].SignFunc)(AP);
  return SL;
}

MASSTOR_LIST MASADOM_ADSUM
# ifdef __STDC__
(MASSTOR_LIST C_102_A, MASSTOR_LIST B)
# else
(C_102_A, B)
MASSTOR_LIST C_102_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CP;

  MASSTOR_ADV(C_102_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  if (AL != BL) {
    MASERR_ERROR(MASERR_fatal, "ADSUM: incompatible domains", 27L);
    return MASSTOR_SIL;
  }
  CP = (*domain.A[(INTEGER)AL - 1].SumFunc)(AP, BP);
  C = MASSTOR_COMP(AL, CP);
  return C;
}

MASSTOR_LIST MASADOM_ADTOIP
# ifdef __STDC__
(MASSTOR_LIST C_101_A, MASSTOR_LIST *LCM)
# else
(C_101_A, LCM)
MASSTOR_LIST C_101_A;
MASSTOR_LIST *LCM;
# endif
{
  MASSTOR_LIST AL, AP, RET;

  MASSTOR_ADV(C_101_A, &AL, &AP);
  RET = MASSTOR_COMP(DOMIP_DOMIPD, (*domain.A[(INTEGER)AL - 1].ToipFunc)(AP, LCM));
  *LCM = MASSTOR_COMP(DOMIP_DOMIPD, *LCM);
  return RET;
}

void MASADOM_ADWRIT
# ifdef __STDC__
(MASSTOR_LIST C_100_A)
# else
(C_100_A)
MASSTOR_LIST C_100_A;
# endif
{
  MASSTOR_LIST AL, AP;

  MASSTOR_ADV(C_100_A, &AL, &AP);
  (*domain.A[(INTEGER)AL - 1].WritFunc)(AP);
  return;
}

MASSTOR_LIST MASADOM_ADDDREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST S, C, CP;
  INTEGER i;

  S = MASSYM2_SREAD();
  C = MASSTOR_SIL;
  i = 0;
  while (i < maxdom) {
    i = i + 1;
    if (domain.A[i - 1].Sym == S) {
      C = (*domain.A[i - 1].DdrdFunc)();
      C = MASSTOR_COMP((MASSTOR_LIST)i, C);
      return C;
    }
  }
  MASSYM2_SYWRIT(S);
  MASERR_ERROR(MASERR_severe, "ADDDREAD: undefined domain.", 27L);
  return C;
}

void MASADOM_ADDDWRIT
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST DL, DP;

  MASSTOR_ADV(D, &DL, &DP);
  if ((ADDRESS)domain.A[(INTEGER)DL - 1].DdwrFunc == (ADDRESS)Dummyp1) {
    MASERR_ERROR(MASERR_fatal, "ADDDWRIT: undefined domain.", 27L);
    return;
  }
  MASSYM2_SYWRIT(domain.A[(INTEGER)DL - 1].Sym);
  (*domain.A[(INTEGER)DL - 1].DdwrFunc)(DP);
  MASBIOS_SWRITE(" (* ", 4L);
  SACLIST_CLOUT(domain.A[(INTEGER)DL - 1].name);
  MASBIOS_SWRITE(" *) ", 4L);
  return;
}

MASSTOR_LIST MASADOM_ADVLDD
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST DL, DP, V;

  MASSTOR_ADV(D, &DL, &DP);
  if ((ADDRESS)domain.A[(INTEGER)DL - 1].VlddFunc != (ADDRESS)Dummyf1) {
    V = (*domain.A[(INTEGER)DL - 1].VlddFunc)(DP);
  } else {
    V = MASSTOR_SIL;
  }
  return V;
}

void MASADOM_SetAbsFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetAbsFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].AbsFunc = f1;
}

void MASADOM_SetCnstFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1B f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1B f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetCnstFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].CnstFunc = f1;
}

void MASADOM_SetCompFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetCompFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].CompFunc = f2;
}

void MASADOM_SetConvFunc
# ifdef __STDC__
(MASADOM_Domain d1, MASADOM_Domain d2, MASADOM_PROCF1 f1)
# else
(d1, d2, f1)
MASADOM_Domain d1, d2;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d1 || d1 > maxdom || 1 > d2 || d2 > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d1);
    SACLIST_OWRITE((MASSTOR_LIST)d2);
    MASERR_ERROR(MASERR_fatal, "SetConvFunc: No valid domains.", 30L);
    return;
  }
  domain.A[(INTEGER)d1 - 1].ConvFunc.A[(INTEGER)d2 - 1] = f1;
}

void MASADOM_SetDifFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetDifFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].DifFunc = f2;
}

void MASADOM_SetExpFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetExpFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].ExpFunc = f2;
}

void MASADOM_SetFactFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetFactFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].FactFunc = f1;
}

void MASADOM_SetFactoFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetFactoFunc: No valid domain.", 30L);
    return;
  }
  domain.A[(INTEGER)d - 1].FactoFunc = f1;
}

void MASADOM_SetFIntFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetFIntFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].FIntFunc = f2;
}

void MASADOM_SetFIPolFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetFIPolFunc: No valid domain.", 30L);
    return;
  }
  domain.A[(INTEGER)d - 1].FIPolFunc = f2;
}

void MASADOM_SetGcdFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetGcdFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].GcdFunc = f2;
}

void MASADOM_SetGcdcFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP2V3 p2v3)
# else
(d, p2v3)
MASADOM_Domain d;
MASADOM_PROCP2V3 p2v3;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetGcdcFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].GcdcFunc = p2v3;
}

void MASADOM_SetGcdeFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP2V3 p2v3)
# else
(d, p2v3)
MASADOM_Domain d;
MASADOM_PROCP2V3 p2v3;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetGcdeFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].GcdeFunc = p2v3;
}

void MASADOM_SetInvFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetInvFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].InvFunc = f1;
}

void MASADOM_SetInvTFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetInvTFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].InvTFunc = f1;
}

void MASADOM_SetLcmFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetLcmFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].LcmFunc = f2;
}

void MASADOM_SetNegFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetNegFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].NegFunc = f1;
}

void MASADOM_SetOneFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetOneFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].OneFunc = f1;
}

void MASADOM_SetPCppFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP1V2 p1v2)
# else
(d, p1v2)
MASADOM_Domain d;
MASADOM_PROCP1V2 p1v2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetCppFunc: No valid domain.", 28L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PCppFunc = p1v2;
}

void MASADOM_SetPFactFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPFactFunc: No valid domain.", 30L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PFactFunc = f1;
}

void MASADOM_SetPNormFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPNormFunc: No valid domain.", 30L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PNormFunc = f2;
}

void MASADOM_SetProdFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetProdFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].ProdFunc = f2;
}

void MASADOM_SetPSpolFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPSpolFunc: No valid domain.", 30L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PSpolFunc = f2;
}

void MASADOM_SetPSqfrFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPSqfrFunc: No valid domain.", 30L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PSqfrFunc = f1;
}

void MASADOM_SetPSugNormFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPSugNormFunc: No valid domain.", 33L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PSugNormFunc = f2;
}

void MASADOM_SetPSugSpolFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetPSugSpolFunc: No valid domain.", 33L);
    return;
  }
  Pdomain.A[(INTEGER)d - 1].PSugSpolFunc = f2;
}

void MASADOM_SetQrFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP2V2 p2v2)
# else
(d, p2v2)
MASADOM_Domain d;
MASADOM_PROCP2V2 p2v2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetQrFunc: No valid domain.", 27L);
    return;
  }
  domain.A[(INTEGER)d - 1].QrFunc = p2v2;
}

void MASADOM_SetQuotFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetQuotFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].QuotFunc = f2;
}

void MASADOM_SetReadFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetReadFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].ReadFunc = f1;
}

void MASADOM_SetRemFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetRemFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].RemFunc = f2;
}

void MASADOM_SetSignFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetSignFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].SignFunc = f1;
}

void MASADOM_SetSumFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF2 f2)
# else
(d, f2)
MASADOM_Domain d;
MASADOM_PROCF2 f2;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetSumFunc: No valid domain.", 28L);
    return;
  }
  domain.A[(INTEGER)d - 1].SumFunc = f2;
}

void MASADOM_SetToipFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1V1 f1v1)
# else
(d, f1v1)
MASADOM_Domain d;
MASADOM_PROCF1V1 f1v1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetToipFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].ToipFunc = f1v1;
}

void MASADOM_SetWritFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP1 p1)
# else
(d, p1)
MASADOM_Domain d;
MASADOM_PROCP1 p1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetWritFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].WritFunc = p1;
}

void MASADOM_SetVlddFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF1 f1)
# else
(d, f1)
MASADOM_Domain d;
MASADOM_PROCF1 f1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetVlddFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].VlddFunc = f1;
}

void MASADOM_SetDdrdFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCF0 f0)
# else
(d, f0)
MASADOM_Domain d;
MASADOM_PROCF0 f0;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetDdrdFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].DdrdFunc = f0;
}

void MASADOM_SetDdwrFunc
# ifdef __STDC__
(MASADOM_Domain d, MASADOM_PROCP1 p1)
# else
(d, p1)
MASADOM_Domain d;
MASADOM_PROCP1 p1;
# endif
{
  if (1 > d || d > maxdom) {
    SACLIST_OWRITE((MASSTOR_LIST)d);
    MASERR_ERROR(MASERR_fatal, "SetDdwrFunc: No valid domain.", 29L);
    return;
  }
  domain.A[(INTEGER)d - 1].DdwrFunc = p1;
}

MASADOM_Domain MASADOM_NewDom
# ifdef __STDC__
(CHAR S[], LONGCARD O_2, CHAR s[], LONGCARD O_1)
# else
(S, O_2, s, O_1)
CHAR S[];
LONGCARD O_2;
CHAR s[];
LONGCARD O_1;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR) + O_2 * sizeof(CHAR), 2)
  COPY_OPEN_ARRAY(s, O_1, CHAR)
  COPY_OPEN_ARRAY(S, O_2, CHAR)
  if (curdom >= maxdom) {
    MASERR_ERROR(MASERR_fatal, "NewDom: No space for new domains.", 33L);
    FREE_OPEN_ARRAYS
    return 0;
  }
  curdom = curdom + 1;
  domain.A[curdom - 1].name = MASBIOS_LISTS(s, O_1);
  domain.A[curdom - 1].Sym = MASSYM2_ENTER(MASBIOS_LISTS(S, O_2));
  {
    LONGINT R_1 = (MASADOM_Domain)curdom;

    FREE_OPEN_ARRAYS
    return R_1;
  }
}

void MASADOM_DomSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST l;
  INTEGER i;

  MASBIOS_SWRITE("List of all defined domains", 27L);
  MASBIOS_BLINES(1);
  i = 0;
  l = 0;
  while (i < maxdom) {
    i = i + 1;
    if (domain.A[i - 1].Sym != Dummy) {
      l = l + 1;
      MASSYM2_SYWRIT(domain.A[i - 1].Sym);
      MASBIOS_SWRITE(" ", 1L);
      SACLIST_CLOUT(domain.A[i - 1].name);
      MASBIOS_BLINES(0);
    }
  }
  if (l > 0) {
    MASBIOS_BLINES(1);
  }
  SACLIST_OWRITE(l);
  MASBIOS_SWRITE(" defined domains.", 17L);
  MASBIOS_BLINES(1);
}

static MASSTOR_LIST Dummyf0
# ifdef __STDC__
()
# else
()
# endif
{
  MASERR_ERROR(MASERR_fatal, "Dummyf0: Undefined function.", 28L);
  return MASSTOR_SIL;
}

static void Dummyp1
# ifdef __STDC__
(MASSTOR_LIST C_99_A)
# else
(C_99_A)
MASSTOR_LIST C_99_A;
# endif
{
  SACLIST_OWRITE(C_99_A);
  MASERR_ERROR(MASERR_fatal, "Dummyp1: Undefined procedure.", 29L);
  return;
}

static MASSTOR_LIST Dummyf1
# ifdef __STDC__
(MASSTOR_LIST C_98_A)
# else
(C_98_A)
MASSTOR_LIST C_98_A;
# endif
{
  SACLIST_OWRITE(C_98_A);
  MASERR_ERROR(MASERR_fatal, "Dummyf1: Undefined function.", 28L);
  return MASSTOR_SIL;
}

static MASSTOR_LIST Dummyf2
# ifdef __STDC__
(MASSTOR_LIST C_97_A, MASSTOR_LIST B)
# else
(C_97_A, B)
MASSTOR_LIST C_97_A, B;
# endif
{
  SACLIST_OWRITE(C_97_A);
  SACLIST_OWRITE(B);
  MASERR_ERROR(MASERR_fatal, "Dummyf2: Undefined function.", 28L);
  return MASSTOR_SIL;
}

static BOOLEAN Dummyf1b
# ifdef __STDC__
(MASSTOR_LIST C_96_A)
# else
(C_96_A)
MASSTOR_LIST C_96_A;
# endif
{
  SACLIST_OWRITE(C_96_A);
  MASERR_ERROR(MASERR_fatal, "Dummyf1b: Undefined function.", 29L);
  return FALSE;
}

static MASSTOR_LIST Dummyf1v1
# ifdef __STDC__
(MASSTOR_LIST C_95_A, MASSTOR_LIST *B)
# else
(C_95_A, B)
MASSTOR_LIST C_95_A;
MASSTOR_LIST *B;
# endif
{
  SACLIST_OWRITE(C_95_A);
  SACLIST_OWRITE(*B);
  MASERR_ERROR(MASERR_fatal, "Dummyf1v1: Undefined function.", 30L);
  return MASSTOR_SIL;
}

static void Dummyp1v2
# ifdef __STDC__
(MASSTOR_LIST C_94_A, MASSTOR_LIST *C, MASSTOR_LIST *D)
# else
(C_94_A, C, D)
MASSTOR_LIST C_94_A;
MASSTOR_LIST *C, *D;
# endif
{
  SACLIST_OWRITE(C_94_A);
  MASERR_ERROR(MASERR_fatal, "Dummyp1v2: Undefined procedure.", 31L);
  return;
}

static void Dummyp2v2
# ifdef __STDC__
(MASSTOR_LIST C_93_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D)
# else
(C_93_A, B, C, D)
MASSTOR_LIST C_93_A, B;
MASSTOR_LIST *C, *D;
# endif
{
  SACLIST_OWRITE(C_93_A);
  SACLIST_OWRITE(B);
  MASERR_ERROR(MASERR_fatal, "Dummyp2v2: Undefined procedure.", 31L);
  return;
}

static void Dummyp2v3
# ifdef __STDC__
(MASSTOR_LIST C_92_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D, MASSTOR_LIST *E)
# else
(C_92_A, B, C, D, E)
MASSTOR_LIST C_92_A, B;
MASSTOR_LIST *C, *D, *E;
# endif
{
  SACLIST_OWRITE(C_92_A);
  SACLIST_OWRITE(B);
  MASERR_ERROR(MASERR_fatal, "Dummyp2v3: Undefined procedure.", 31L);
  return;
}

static void InitADom
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i, j;
  MASSTOR_LIST u;

  curdom = 0;
  Dummy = MASSYM2_ENTER(MASBIOS_LISTS("Dummy", 5L));
  u = MASBIOS_LISTS("Undefined", 9L);
  i = 0;
  while (i < maxdom) {
    i = i + 1;
    domain.A[i - 1].name = u;
    MASSTOR_LISTVAR(&domain.A[i - 1].name);
    domain.A[i - 1].Sym = Dummy;
    domain.A[i - 1].AbsFunc = Dummyf1;
    domain.A[i - 1].CnstFunc = Dummyf1b;
    domain.A[i - 1].CompFunc = Dummyf2;
    j = 0;
    while (j < maxdom) {
      j = j + 1;
      domain.A[i - 1].ConvFunc.A[j - 1] = Dummyf1;
    }
    domain.A[i - 1].DifFunc = Dummyf2;
    domain.A[i - 1].ExpFunc = Dummyf2;
    domain.A[i - 1].FactFunc = Dummyf1;
    domain.A[i - 1].FactoFunc = Dummyf1;
    domain.A[i - 1].FIntFunc = Dummyf2;
    domain.A[i - 1].FIPolFunc = Dummyf2;
    domain.A[i - 1].GcdFunc = Dummyf2;
    domain.A[i - 1].GcdcFunc = Dummyp2v3;
    domain.A[i - 1].GcdeFunc = Dummyp2v3;
    domain.A[i - 1].InvFunc = Dummyf1;
    domain.A[i - 1].InvTFunc = Dummyf1;
    domain.A[i - 1].ProdFunc = Dummyf2;
    domain.A[i - 1].QrFunc = Dummyp2v2;
    domain.A[i - 1].QuotFunc = Dummyf2;
    domain.A[i - 1].ReadFunc = Dummyf1;
    domain.A[i - 1].QuotFunc = Dummyf2;
    domain.A[i - 1].RemFunc = Dummyf2;
    domain.A[i - 1].SignFunc = Dummyf1;
    domain.A[i - 1].SumFunc = Dummyf2;
    domain.A[i - 1].ToipFunc = Dummyf1v1;
    domain.A[i - 1].WritFunc = Dummyp1;
    domain.A[i - 1].VlddFunc = Dummyf1;
    domain.A[i - 1].DdrdFunc = Dummyf0;
    domain.A[i - 1].DdwrFunc = Dummyp1;
  }
}

static void InitADomP
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i;

  for (i = 1; i <= maxdom; i += 1) {
    Pdomain.A[i - 1].PFactFunc = Dummyf1;
    Pdomain.A[i - 1].PNormFunc = Dummyf2;
    Pdomain.A[i - 1].PSpolFunc = Dummyf2;
    Pdomain.A[i - 1].PSqfrFunc = Dummyf1;
    Pdomain.A[i - 1].PSugNormFunc = Dummyf2;
    Pdomain.A[i - 1].PSugSpolFunc = Dummyf2;
    Pdomain.A[i - 1].PCppFunc = Dummyp1v2;
  }
}

void BEGIN_MASADOM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPAGB();
    BEGIN_DIPC();
    BEGIN_DIPTOO();
    BEGIN_DIPTOOLS();
    BEGIN_DOMIP();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();

    InitADom();
    InitADomP();
  }
}
