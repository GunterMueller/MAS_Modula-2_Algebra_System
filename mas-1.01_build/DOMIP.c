#include "SYSTEM_.h"

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPGCD
#include "DIPGCD.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DOMIP
#include "DOMIP.h"
#endif

MASADOM_Domain DOMIP_DOMIPD;
CHAR DOMIP_rcsid [] = "$Id: DOMIP.md,v 1.2 1992/02/12 17:31:29 pesch Exp $";
CHAR DOMIP_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMIP.mi,v 1.7 1995/03/06 15:53:23 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static BOOLEAN DCNST ARGS((MASSTOR_LIST C_247_A));
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_246_A, MASSTOR_LIST B));
static MASSTOR_LIST DFACT ARGS((MASSTOR_LIST C_245_A));
static MASSTOR_LIST DFACTO ARGS((MASSTOR_LIST C_243_A));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_242_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_241_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_240_A));
static MASSTOR_LIST DGCD ARGS((MASSTOR_LIST C_239_A, MASSTOR_LIST B));
static void DGCDC ARGS((MASSTOR_LIST C_238_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AA, MASSTOR_LIST *BB));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_237_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_236_A));
static MASSTOR_LIST DLCM ARGS((MASSTOR_LIST C_235_A, MASSTOR_LIST B));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_234_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_233_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_232_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_231_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_230_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_229_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_228_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_227_A, MASSTOR_LIST B));
static MASSTOR_LIST DTOIP ARGS((MASSTOR_LIST C_226_A, MASSTOR_LIST *LCM));
static void DWRIT ARGS((MASSTOR_LIST C_225_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DVLDD ARGS((MASSTOR_LIST D));


static BOOLEAN DCNST
# ifdef __STDC__
(MASSTOR_LIST C_247_A)
# else
(C_247_A)
MASSTOR_LIST C_247_A;
# endif
{
  MASSTOR_LIST AL, AP, t, r;

  MASSTOR_ADV(C_247_A, &AL, &AP);
  r = MASSTOR_FIRST(AP);
  t = SACEXT4_PCONST(r, AL);
  if (t == 1) {
    return TRUE;
  } else {
    return FALSE;
  }
}

static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_246_A, MASSTOR_LIST B)
# else
(C_246_A, B)
MASSTOR_LIST C_246_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, RL;

  MASSTOR_ADV(C_246_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACIPOL_IPDIF(RL, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFACT
# ifdef __STDC__
(MASSTOR_LIST C_245_A)
# else
(C_245_A)
MASSTOR_LIST C_245_A;
# endif
{
  MASSTOR_LIST AL, AP, r, P, SL, CL, L, LL, B, BL;

  MASSTOR_ADV(C_245_A, &AL, &AP);
  r = MASSTOR_FIRST(AP);
  P = SACIPOL_IPABS(r, AL);
  SACPFAC_IPFAC(r, P, &SL, &CL, &L);
  LL = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &BL, &L);
    BL = SACLIST_SECOND(BL);
    B = MASSTOR_COMP(BL, AP);
    LL = MASSTOR_COMP(B, LL);
  }
  LL = MASSTOR_INV(LL);
  return LL;
}

static MASSTOR_LIST DFACTO
# ifdef __STDC__
(MASSTOR_LIST C_243_A)
# else
(C_243_A)
MASSTOR_LIST C_243_A;
# endif
{
  MASSTOR_LIST AL, AP, r, P, SL, CL, L, LL, B, BL, PP, VP, PV, C_244_VAL;

  MASSTOR_ADV(C_243_A, &AL, &AP);
  r = MASSTOR_FIRST(AP);
  P = SACIPOL_IPABS(r, AL);
  DIPTOOLS_ValisPush(SACLIST_SECOND(AP));
  P = DIPC_DIPFP(r, P);
  DIPTOO_DIPVOPP(MASSTOR_LIST1(P), DIPC_VALIS, &PP, &VP, &PV);
  DIPTOOLS_ValisPush(VP);
  P = MASSTOR_FIRST(PP);
  DIPTOOLS_EvordPush(DIPC_INVLEX);
  DIPC_DIPBSO(P);
  DIPC_PFDIP(P, &r, &P);
  DIPTOOLS_EvordPop();
  SACPFAC_IPFAC(r, P, &SL, &CL, &L);
  PV = DIPTOO_INVPERM(PV);
  LL = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &BL, &L);
    BL = DIPC_DIPFP(r, SACLIST_SECOND(BL));
    BL = DIPC_DIPERM(BL, PV);
    DIPC_PFDIP(BL, &r, &BL);
    BL = MASSTOR_COMP(BL, AP);
    LL = MASSTOR_COMP(BL, LL);
  }
  DIPTOOLS_ValisPop();
  DIPTOOLS_ValisPop();
  LL = MASSTOR_INV(LL);
  return LL;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_242_A, MASSTOR_LIST NL)
# else
(C_242_A, NL)
MASSTOR_LIST C_242_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, RL;

  MASSTOR_ADV(C_242_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  CL = SACIPOL_IPEXP(RL, AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_241_A)
# else
(D, C_241_A)
MASSTOR_LIST D, C_241_A;
# endif
{
  MASSTOR_LIST C, CL, RL;

  D = MASSTOR_RED(D);
  RL = MASSTOR_FIRST(D);
  CL = SACPOL_PINV(0, C_241_A, RL);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_240_A)
# else
(D, C_240_A)
MASSTOR_LIST D, C_240_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = C_240_A;
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DGCD
# ifdef __STDC__
(MASSTOR_LIST C_239_A, MASSTOR_LIST B)
# else
(C_239_A, B)
MASSTOR_LIST C_239_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, RL, C1, C2;

  MASSTOR_ADV(C_239_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACPGCD_IPGCDC(RL, AL, BL, &CL, &C1, &C2);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DGCDC
# ifdef __STDC__
(MASSTOR_LIST C_238_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AA, MASSTOR_LIST *BB)
# else
(C_238_A, B, C, AA, BB)
MASSTOR_LIST C_238_A, B;
MASSTOR_LIST *C, *AA, *BB;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, CL, RL, C1, C2;

  MASSTOR_ADV(C_238_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACPGCD_IPGCDC(RL, AL, BL, &CL, &C1, &C2);
  *C = MASSTOR_COMP(CL, AP);
  *AA = MASSTOR_COMP(C1, AP);
  *BB = MASSTOR_COMP(C2, AP);
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_237_A)
# else
(C_237_A)
MASSTOR_LIST C_237_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, QL, RL, EL;

  MASSTOR_ADV(C_237_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  EL = SACPOL_PINV(0, 1, RL);
  SACIPOL_IPQR(RL, EL, AL, &CL, &QL);
  if (QL != 0) {
    MASERR_ERROR(MASERR_severe, "Remainder non zero in integral polynomial INV", 45L);
  }
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_236_A)
# else
(C_236_A)
MASSTOR_LIST C_236_A;
# endif
{
  MASSTOR_LIST AL, AP, TL, RL;

  MASSTOR_ADV(C_236_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  AL = SACIPOL_IPABS(RL, AL);
  TL = SACIPOL_IPONE(RL, AL);
  if (TL != 1) {
    TL = 0;
  }
  return TL;
}

static MASSTOR_LIST DLCM
# ifdef __STDC__
(MASSTOR_LIST C_235_A, MASSTOR_LIST B)
# else
(C_235_A, B)
MASSTOR_LIST C_235_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, RL;

  MASSTOR_ADV(C_235_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = DIPGCD_IPLCM(RL, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_234_A)
# else
(C_234_A)
MASSTOR_LIST C_234_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, RL;

  MASSTOR_ADV(C_234_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  CL = SACIPOL_IPNEG(RL, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_233_A)
# else
(C_233_A)
MASSTOR_LIST C_233_A;
# endif
{
  MASSTOR_LIST AL, AP, SL, RL;

  MASSTOR_ADV(C_233_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  SL = SACIPOL_IPONE(RL, AL);
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
(MASSTOR_LIST C_232_A, MASSTOR_LIST B)
# else
(C_232_A, B)
MASSTOR_LIST C_232_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, RL;

  MASSTOR_ADV(C_232_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACIPOL_IPPROD(RL, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_231_A, MASSTOR_LIST B)
# else
(C_231_A, B)
MASSTOR_LIST C_231_A, B;
# endif
{
  return DIPGB_DIIFSP(C_231_A, B);
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
(MASSTOR_LIST C_230_A, MASSTOR_LIST B)
# else
(C_230_A, B)
MASSTOR_LIST C_230_A, B;
# endif
{
  return DIPAGB_EDIIFSUGSP(C_230_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_229_A, MASSTOR_LIST B)
# else
(C_229_A, B)
MASSTOR_LIST C_229_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, QL, RL;

  MASSTOR_ADV(C_229_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  SACIPOL_IPQR(RL, AL, BL, &CL, &QL);
  if (QL != 0) {
    MASERR_ERROR(MASERR_severe, "Remainder non zero in integral polynomial QUOT", 46L);
  }
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DREAD
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST C, CL, RL, V, DP;

  D = MASSTOR_RED(D);
  MASSTOR_ADV(D, &RL, &DP);
  V = MASSTOR_FIRST(DP);
  CL = DIPI_DIIPRD(V);
  DIPC_PFDIP(CL, &RL, &CL);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_228_A)
# else
(C_228_A)
MASSTOR_LIST C_228_A;
# endif
{
  MASSTOR_LIST AL, SL, RL, AP;

  MASSTOR_ADV(C_228_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  SL = SACIPOL_IPSIGN(RL, AL);
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_227_A, MASSTOR_LIST B)
# else
(C_227_A, B)
MASSTOR_LIST C_227_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, RL;

  MASSTOR_ADV(C_227_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACIPOL_IPSUM(RL, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DTOIP
# ifdef __STDC__
(MASSTOR_LIST C_226_A, MASSTOR_LIST *LCM)
# else
(C_226_A, LCM)
MASSTOR_LIST C_226_A;
MASSTOR_LIST *LCM;
# endif
{
  MASSTOR_LIST AL, AP, LL, RL;

  MASSTOR_ADV(C_226_A, &AL, &AP);
  RL = MASSTOR_FIRST(AP);
  LL = SACPOL_PINV(0, 1, RL);
  *LCM = MASSTOR_COMP(LL, AP);
  return C_226_A;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_225_A)
# else
(C_225_A)
MASSTOR_LIST C_225_A;
# endif
{
  MASSTOR_LIST AL, RL, V, AP;

  SACLIST_ADV2(C_225_A, &AL, &RL, &AP);
  V = MASSTOR_FIRST(AP);
  AL = DIPC_DIPFP(RL, AL);
  DIPI_DIIPWR(AL, V);
  return;
}

static MASSTOR_LIST DDDRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST V, RL, C;

  V = SACPOL_VLREAD();
  RL = MASSTOR_LENGTH(V);
  C = SACLIST_LIST3(0, RL, V);
  return C;
}

static void DDDWR
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST V;

  D = MASSTOR_RED(D);
  V = SACLIST_SECOND(D);
  SACPOL_VLWRIT(V);
  return;
}

static MASSTOR_LIST DVLDD
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST V;

  D = MASSTOR_RED(D);
  V = SACLIST_SECOND(D);
  return V;
}

void DOMIP_DomLoadIP
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("IP", 2L, "Integral Polynomial", 19L);
  DOMIP_DOMIPD = d;
  MASADOM_SetCnstFunc(d, DCNST);
  MASADOM_SetDifFunc(d, DDIF);
  MASADOM_SetExpFunc(d, DEXP);
  MASADOM_SetFactFunc(d, DFACT);
  MASADOM_SetFactoFunc(d, DFACTO);
  MASADOM_SetFIntFunc(d, DFI);
  MASADOM_SetFIPolFunc(d, DFIP);
  MASADOM_SetGcdFunc(d, DGCD);
  MASADOM_SetGcdcFunc(d, DGCDC);
  MASADOM_SetInvFunc(d, DINV);
  MASADOM_SetInvTFunc(d, DINVT);
  MASADOM_SetLcmFunc(d, DLCM);
  MASADOM_SetNegFunc(d, DNEG);
  MASADOM_SetOneFunc(d, DONE);
  MASADOM_SetProdFunc(d, DPROD);
  MASADOM_SetQuotFunc(d, DQUOT);
  MASADOM_SetReadFunc(d, DREAD);
  MASADOM_SetSignFunc(d, DSIGN);
  MASADOM_SetSumFunc(d, DSUM);
  MASADOM_SetToipFunc(d, DTOIP);
  MASADOM_SetWritFunc(d, DWRIT);
  MASADOM_SetDdrdFunc(d, DDDRD);
  MASADOM_SetDdwrFunc(d, DDDWR);
  MASADOM_SetVlddFunc(d, DVLDD);
  MASADOM_SetPNormFunc(d, DPNF);
  MASADOM_SetPSpolFunc(d, DPSP);
  MASADOM_SetPSugNormFunc(d, DPSUGNF);
  MASADOM_SetPSugSpolFunc(d, DPSUGSP);
}

void BEGIN_DOMIP()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASADOM();
    BEGIN_DIPTOO();
    BEGIN_DIPTOOLS();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACPGCD();
    BEGIN_SACPFAC();
    BEGIN_SACEXT4();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPGCD();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();

  }
}
