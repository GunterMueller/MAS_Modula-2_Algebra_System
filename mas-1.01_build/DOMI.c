#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_MASPGCD
#include "MASPGCD.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DOMI
#include "DOMI.h"
#endif

MASADOM_Domain DOMI_DOMINT;
CHAR DOMI_rcsid [] = "$Id: DOMI.md,v 1.2 1992/02/12 17:31:27 pesch Exp $";
CHAR DOMI_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMI.mi,v 1.8 1994/11/28 20:56:29 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DABS ARGS((MASSTOR_LIST C_144_A));
static MASSTOR_LIST DCOMP ARGS((MASSTOR_LIST C_143_A, MASSTOR_LIST B));
static void DPCPP ARGS((MASSTOR_LIST P, MASSTOR_LIST *c, MASSTOR_LIST *pp));
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_142_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_141_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_140_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_139_A));
static MASSTOR_LIST DGCD ARGS((MASSTOR_LIST C_138_A, MASSTOR_LIST B));
static void DGCDE ARGS((MASSTOR_LIST C_137_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AS, MASSTOR_LIST *BS));
static void DGCDC ARGS((MASSTOR_LIST C_136_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AS, MASSTOR_LIST *BS));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_135_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_134_A));
static MASSTOR_LIST DLCM ARGS((MASSTOR_LIST C_133_A, MASSTOR_LIST B));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_132_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_131_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_130_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_129_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_128_A, MASSTOR_LIST B));
static void DQR ARGS((MASSTOR_LIST C_127_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_126_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DREM ARGS((MASSTOR_LIST C_125_A, MASSTOR_LIST B));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_124_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_123_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_122_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DPFAC ARGS((MASSTOR_LIST P));
static MASSTOR_LIST DPSFF ARGS((MASSTOR_LIST C_121_A));


static MASSTOR_LIST DABS
# ifdef __STDC__
(MASSTOR_LIST C_144_A)
# else
(C_144_A)
MASSTOR_LIST C_144_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_144_A, &AL, &AP);
  CL = SACI_IABSF(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DCOMP
# ifdef __STDC__
(MASSTOR_LIST C_143_A, MASSTOR_LIST B)
# else
(C_143_A, B)
MASSTOR_LIST C_143_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, SL;

  MASSTOR_ADV(C_143_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SL = SACI_ICOMP(AL, BL);
  return SL;
}

static void DPCPP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *c, MASSTOR_LIST *pp)
# else
(P, c, pp)
MASSTOR_LIST P;
MASSTOR_LIST *c, *pp;
# endif
{
  DIPTOOLS_DIPCPP(P, c, pp);
  return;
}

static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_142_A, MASSTOR_LIST B)
# else
(C_142_A, B)
MASSTOR_LIST C_142_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_142_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACI_IDIF(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_141_A, MASSTOR_LIST NL)
# else
(C_141_A, NL)
MASSTOR_LIST C_141_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_141_A, &AL, &AP);
  CL = SACI_IEXP(AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_140_A)
# else
(D, C_140_A)
MASSTOR_LIST D, C_140_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = C_140_A;
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_139_A)
# else
(D, C_139_A)
MASSTOR_LIST D, C_139_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = C_139_A;
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DGCD
# ifdef __STDC__
(MASSTOR_LIST C_138_A, MASSTOR_LIST B)
# else
(C_138_A, B)
MASSTOR_LIST C_138_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_138_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACI_IGCD(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DGCDE
# ifdef __STDC__
(MASSTOR_LIST C_137_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AS, MASSTOR_LIST *BS)
# else
(C_137_A, B, C, AS, BS)
MASSTOR_LIST C_137_A, B;
MASSTOR_LIST *C, *AS, *BS;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, ALS, BLS;

  MASSTOR_ADV(C_137_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACI_IEGCD(AL, BL, &CL, &ALS, &BLS);
  *C = MASSTOR_COMP(CL, AP);
  *AS = MASSTOR_COMP(ALS, AP);
  *BS = MASSTOR_COMP(BLS, AP);
}

static void DGCDC
# ifdef __STDC__
(MASSTOR_LIST C_136_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AS, MASSTOR_LIST *BS)
# else
(C_136_A, B, C, AS, BS)
MASSTOR_LIST C_136_A, B;
MASSTOR_LIST *C, *AS, *BS;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, ALS, BLS;

  MASSTOR_ADV(C_136_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACI_IGCDCF(AL, BL, &CL, &ALS, &BLS);
  *C = MASSTOR_COMP(CL, AP);
  *AS = MASSTOR_COMP(ALS, AP);
  *BS = MASSTOR_COMP(BLS, AP);
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_135_A)
# else
(C_135_A)
MASSTOR_LIST C_135_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, RL;

  MASSTOR_ADV(C_135_A, &AL, &AP);
  SACI_IQR(1, AL, &CL, &RL);
  if (RL != 0) {
    SACI_IWRITE(RL);
    MASERR_ERROR(MASERR_severe, "Remainder non zero in integer INV", 33L);
  }
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_134_A)
# else
(C_134_A)
MASSTOR_LIST C_134_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_134_A, &AL, &AP);
  TL = SACI_IABSF(AL);
  if (TL != 1) {
    TL = 0;
  }
  return TL;
}

static MASSTOR_LIST DLCM
# ifdef __STDC__
(MASSTOR_LIST C_133_A, MASSTOR_LIST B)
# else
(C_133_A, B)
MASSTOR_LIST C_133_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_133_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACI_ILCM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_132_A)
# else
(C_132_A)
MASSTOR_LIST C_132_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_132_A, &AL, &AP);
  CL = SACI_INEG(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_131_A)
# else
(C_131_A)
MASSTOR_LIST C_131_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_131_A, &AL, &AP);
  SL = AL;
  if (SL != 1) {
    SL = 0;
  }
  return SL;
}

static MASSTOR_LIST DPNF
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P)
# else
(G, P)
MASSTOR_LIST G, P;
# endif
{
  return DIPGB_DIIFNF(G, 0, P);
}

static MASSTOR_LIST DPROD
# ifdef __STDC__
(MASSTOR_LIST C_130_A, MASSTOR_LIST B)
# else
(C_130_A, B)
MASSTOR_LIST C_130_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_130_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACI_IPROD(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_129_A, MASSTOR_LIST B)
# else
(C_129_A, B)
MASSTOR_LIST C_129_A, B;
# endif
{
  return DIPGB_DIIFSP(C_129_A, B);
}

static MASSTOR_LIST DPSUGNF
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P)
# else
(G, P)
MASSTOR_LIST G, P;
# endif
{
  return DIPAGB_EDIIFSUGNF(G, P);
}

static MASSTOR_LIST DPSUGSP
# ifdef __STDC__
(MASSTOR_LIST C_128_A, MASSTOR_LIST B)
# else
(C_128_A, B)
MASSTOR_LIST C_128_A, B;
# endif
{
  return DIPAGB_EDIIFSUGSP(C_128_A, B);
}

static void DQR
# ifdef __STDC__
(MASSTOR_LIST C_127_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(C_127_A, B, Q, R)
MASSTOR_LIST C_127_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, QL, RL;

  MASSTOR_ADV(C_127_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACI_IQR(AL, BL, &QL, &RL);
  if (SACI_ISIGNF(RL) < 0) {
    if (SACI_ISIGNF(BL) > 0) {
      RL = SACI_ISUM(RL, BL);
      QL = SACI_ISUM(QL, -1);
    } else {
      RL = SACI_IDIF(RL, BL);
      QL = SACI_ISUM(QL, 1);
    }
  }
  *Q = MASSTOR_COMP(QL, AP);
  *R = MASSTOR_COMP(RL, AP);
  return;
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_126_A, MASSTOR_LIST B)
# else
(C_126_A, B)
MASSTOR_LIST C_126_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, Q, QL, RL;

  MASSTOR_ADV(C_126_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACI_IQR(AL, BL, &QL, &RL);
  if (SACI_ISIGNF(RL) < 0) {
    if (SACI_ISIGNF(BL) > 0) {
      QL = SACI_ISUM(QL, -1);
    } else {
      QL = SACI_ISUM(QL, 1);
    }
  }
  Q = MASSTOR_COMP(QL, AP);
  return Q;
}

static MASSTOR_LIST DREAD
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = SACI_IREAD();
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DREM
# ifdef __STDC__
(MASSTOR_LIST C_125_A, MASSTOR_LIST B)
# else
(C_125_A, B)
MASSTOR_LIST C_125_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, R, CL, RL;

  MASSTOR_ADV(C_125_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACI_IQR(AL, BL, &CL, &RL);
  if (SACI_ISIGNF(RL) < 0) {
    if (SACI_ISIGNF(BL) > 0) {
      RL = SACI_ISUM(RL, BL);
    } else {
      RL = SACI_IDIF(RL, BL);
    }
  }
  R = MASSTOR_COMP(RL, AP);
  return R;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_124_A)
# else
(C_124_A)
MASSTOR_LIST C_124_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_124_A);
  SL = SACI_ISIGNF(AL);
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_123_A, MASSTOR_LIST B)
# else
(C_123_A, B)
MASSTOR_LIST C_123_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_123_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACI_ISUM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_122_A)
# else
(C_122_A)
MASSTOR_LIST C_122_A;
# endif
{
  MASSTOR_LIST AL;

  AL = MASSTOR_FIRST(C_122_A);
  SACI_IWRITE(AL);
  return;
}

static MASSTOR_LIST DDDRD
# ifdef __STDC__
()
# else
()
# endif
{
  return MASSTOR_LIST1(0);
}

static void DDDWR
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  return;
}

static MASSTOR_LIST DPFAC
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST r, S, C, F, F1, ExpPol, exp, pol;

  DIPC_PFDIP(P, &r, &P);
  SACPFAC_IPFAC(r, P, &S, &C, &F);
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    pol = DIPC_DIPFP(r, pol);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

static MASSTOR_LIST DPSFF
# ifdef __STDC__
(MASSTOR_LIST C_121_A)
# else
(C_121_A)
MASSTOR_LIST C_121_A;
# endif
{
  MASSTOR_LIST r, F, F1, ExpPol, exp, pol;

  DIPC_PFDIP(C_121_A, &r, &C_121_A);
  F = MASPGCD_IPSFF(r, C_121_A);
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    pol = DIPC_DIPFP(r, pol);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

void DOMI_DomLoadI
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("INT", 3L, "Integer", 7L);
  DOMI_DOMINT = d;
  MASADOM_SetAbsFunc(d, DABS);
  MASADOM_SetCompFunc(d, DCOMP);
  MASADOM_SetDifFunc(d, DDIF);
  MASADOM_SetExpFunc(d, DEXP);
  MASADOM_SetFIntFunc(d, DFI);
  MASADOM_SetFIPolFunc(d, DFIP);
  MASADOM_SetGcdFunc(d, DGCD);
  MASADOM_SetGcdeFunc(d, DGCDE);
  MASADOM_SetGcdcFunc(d, DGCDC);
  MASADOM_SetInvFunc(d, DINV);
  MASADOM_SetInvTFunc(d, DINVT);
  MASADOM_SetLcmFunc(d, DLCM);
  MASADOM_SetNegFunc(d, DNEG);
  MASADOM_SetOneFunc(d, DONE);
  MASADOM_SetProdFunc(d, DPROD);
  MASADOM_SetQrFunc(d, DQR);
  MASADOM_SetQuotFunc(d, DQUOT);
  MASADOM_SetReadFunc(d, DREAD);
  MASADOM_SetRemFunc(d, DREM);
  MASADOM_SetSignFunc(d, DSIGN);
  MASADOM_SetSumFunc(d, DSUM);
  MASADOM_SetWritFunc(d, DWRIT);
  MASADOM_SetDdrdFunc(d, DDDRD);
  MASADOM_SetDdwrFunc(d, DDDWR);
  MASADOM_SetPNormFunc(d, DPNF);
  MASADOM_SetPFactFunc(d, DPFAC);
  MASADOM_SetPSpolFunc(d, DPSP);
  MASADOM_SetPSqfrFunc(d, DPSFF);
  MASADOM_SetPSugNormFunc(d, DPSUGNF);
  MASADOM_SetPSugSpolFunc(d, DPSUGSP);
  MASADOM_SetPCppFunc(d, DPCPP);
}

void BEGIN_DOMI()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASADOM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASADOM();
    BEGIN_SACI();
    BEGIN_SACLIST();
    BEGIN_DIPC();
    BEGIN_DIPTOOLS();
    BEGIN_SACPFAC();
    BEGIN_MASPGCD();
    BEGIN_DIPGB();
    BEGIN_DIPAGB();

  }
}
