#include "SYSTEM_.h"

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

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACANF
#include "SACANF.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNPOL
#include "DIPRNPOL.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_SACEXT8
#include "SACEXT8.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACUPFAC
#include "SACUPFAC.h"
#endif

#ifndef DEFINITION_DOMAF
#include "DOMAF.h"
#endif

MASADOM_Domain DOMAF_DOMAFD;
CHAR DOMAF_rcsid [] = "$Id: DOMAF.md,v 1.2 1992/02/12 17:31:24 pesch Exp $";
CHAR DOMAF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMAF.mi,v 1.5 1994/09/06 11:48:44 rose Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_264_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_263_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_262_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_261_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_260_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_259_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_258_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_257_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_256_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_255_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_254_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_253_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_252_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_251_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_250_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));
static MASSTOR_LIST AFEXP ARGS((MASSTOR_LIST MP, MASSTOR_LIST C_249_A, MASSTOR_LIST NL));
static MASSTOR_LIST AFHOM ARGS((MASSTOR_LIST MP, MASSTOR_LIST C_248_A));
static MASSTOR_LIST AFFINT ARGS((MASSTOR_LIST C_247_A));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_264_A, MASSTOR_LIST B)
# else
(C_264_A, B)
MASSTOR_LIST C_264_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_264_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACANF_AFDIF(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_263_A, MASSTOR_LIST NL)
# else
(C_263_A, NL)
MASSTOR_LIST C_263_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_263_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  CL = AFEXP(M, AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_262_A)
# else
(D, C_262_A)
MASSTOR_LIST D, C_262_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = AFFINT(C_262_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_261_A)
# else
(D, C_261_A)
MASSTOR_LIST D, C_261_A;
# endif
{
  MASSTOR_LIST C, CL, M, BL, DL;

  D = MASSTOR_RED(D);
  M = MASSTOR_FIRST(D);
  CL = SACRPOL_RPFIP(1, C_261_A);
  SACRPOL_RPQR(1, CL, M, &BL, &DL);
  C = MASSTOR_COMP(DL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_260_A)
# else
(C_260_A)
MASSTOR_LIST C_260_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_260_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  CL = SACANF_AFINV(M, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_259_A)
# else
(C_259_A)
MASSTOR_LIST C_259_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_259_A, &AL, &AP);
  AP = SACLIST_RED2(AP);
  TL = 0;
  if (AL != 0) {
    TL = MASSTOR_FIRST(AP);
    if (TL == 2) {
      TL = 0;
    }
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_258_A)
# else
(C_258_A)
MASSTOR_LIST C_258_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_258_A, &AL, &AP);
  CL = SACANF_AFNEG(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_257_A)
# else
(C_257_A)
MASSTOR_LIST C_257_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_257_A, &AL, &AP);
  SL = DIPRNPOL_RPONE(1, AL);
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
  return DIPGB_DIPNOR(G, P);
}

static MASSTOR_LIST DPROD
# ifdef __STDC__
(MASSTOR_LIST C_256_A, MASSTOR_LIST B)
# else
(C_256_A, B)
MASSTOR_LIST C_256_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_256_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACANF_AFPROD(M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_255_A, MASSTOR_LIST B)
# else
(C_255_A, B)
MASSTOR_LIST C_255_A, B;
# endif
{
  return DIPGB_DIPSP(C_255_A, B);
}

static MASSTOR_LIST DPSUGNF
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P)
# else
(G, P)
MASSTOR_LIST G, P;
# endif
{
  return DIPAGB_EDIPSUGNOR(G, P);
}

static MASSTOR_LIST DPSUGSP
# ifdef __STDC__
(MASSTOR_LIST C_254_A, MASSTOR_LIST B)
# else
(C_254_A, B)
MASSTOR_LIST C_254_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_254_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_253_A, MASSTOR_LIST B)
# else
(C_253_A, B)
MASSTOR_LIST C_253_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_253_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACANF_AFQ(M, AL, BL);
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
  MASSTOR_LIST C, CL, M, RL, V, BL, DL, DP;

  D = MASSTOR_RED(D);
  MASSTOR_ADV(D, &M, &DP);
  V = SACLIST_THIRD(DP);
  CL = DIPRN_DIRPRD(V);
  DIPC_PFDIP(CL, &RL, &CL);
  CL = AFHOM(M, CL);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_252_A)
# else
(C_252_A)
MASSTOR_LIST C_252_A;
# endif
{
  MASSTOR_LIST AL, SL, M, AP, PL, V, I, CL, MI;

  SACLIST_ADV3(C_252_A, &AL, &M, &MI, &AP);
  SACLIST_FIRST4(AP, &PL, &V, &I, &SL);
  if (SL >= 0 && I != MASSTOR_SIL) {
    CL = SACANF_AFSIGN(MI, I, AL);
  } else {
    CL = SACRN_RNSIGN(SACPOL_PLBCF(1, AL));
  }
  return CL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_251_A, MASSTOR_LIST B)
# else
(C_251_A, B)
MASSTOR_LIST C_251_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_251_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACANF_AFSUM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_250_A)
# else
(C_250_A)
MASSTOR_LIST C_250_A;
# endif
{
  MASSTOR_LIST AL, AP, SL, M, I, PL, CL, N, J, V, MI;

  SACLIST_ADV3(C_250_A, &AL, &M, &MI, &AP);
  SACLIST_FIRST4(AP, &PL, &V, &I, &SL);
  if (SL < 0) {
    CL = DIPC_DIPFP(1, AL);
    DIPRN_DIRPWR(CL, V, -1);
  } else {
    SACEXT8_ANFAF(MI, I, AL, &N, &J);
    SACEXT8_ANDWR(N, J, SL);
  }
  return;
}

static MASSTOR_LIST DDDRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST c, R1, R2, MS, I, M, D, SL, PL, MP, V, RL, MI, WL;

  M = 0;
  MI = 0;
  PL = 0;
  V = MASSTOR_SIL;
  I = MASSTOR_SIL;
  SL = -1;
  D = SACLIST_COMP2(M, MI, SACLIST_LIST4(PL, V, I, SL));
  D = MASSTOR_COMP(0, D);
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "AF domain read: '(' expected.", 29L);
    return D;
  }
  c = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (!MASBIOS_LETTER(c)) {
    MASERR_ERROR(MASERR_severe, "AF domain read: 'variable' expected.", 36L);
    return D;
  }
  V = SACPOL_VREAD();
  V = MASSTOR_LIST1(V);
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(',')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "AF domain read: ',' expected.", 29L);
    return D;
  }
  MP = DIPRN_DIRPRD(V);
  DIPC_PFDIP(MP, &RL, &M);
  SACPGCD_IPSRP(RL, M, &WL, &MI);
  c = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (c == MASBIOS_MASORD(',')) {
    c = MASBIOS_CREADB();
    c = MASBIOS_CREADB();
    if (c != MASBIOS_MASORD('(')) {
      MASBIOS_BKSP();
      MASERR_ERROR(MASERR_severe, "AF domain read: '(' expected.", 29L);
      return D;
    }
    c = MASBIOS_CREADB();
    if (c != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      if (!MASBIOS_DIGIT(c)) {
        MASERR_ERROR(MASERR_severe, "AF domain read: 'number 1' expected.", 36L);
        return D;
      }
      R1 = MASRN_RNDRD();
      c = MASBIOS_CREADB();
      if (c != MASBIOS_MASORD(',')) {
        MASBIOS_BKSP();
        MASERR_ERROR(MASERR_severe, "AF domain read: ',' expected.", 29L);
        return D;
      }
      c = MASBIOS_CREADB();
      MASBIOS_BKSP();
      if (!MASBIOS_DIGIT(c)) {
        MASERR_ERROR(MASERR_severe, "AF domain read: 'number 2' expected.", 36L);
        return D;
      }
      R2 = MASRN_RNDRD();
      I = SACLIST_LIST2(R1, R2);
      c = MASBIOS_CREADB();
      if (c != MASBIOS_MASORD(')')) {
        MASBIOS_BKSP();
        MASERR_ERROR(MASERR_severe, "AF domain read, 1: ')' expected.", 32L);
        return D;
      }
    }
    c = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (c == MASBIOS_MASORD(',')) {
      c = MASBIOS_CREADB();
      c = MASBIOS_CREADB();
      MASBIOS_BKSP();
      if (MASBIOS_DIGIT(c) || c == MASBIOS_MASORD('-') || c == MASBIOS_MASORD('+')) {
        SL = SACLIST_AREAD();
      }
    }
  }
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(')')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "AF domain read, 2: ')' expected.", 32L);
    return D;
  }
  MS = SACPGCD_IPSF(RL, MI);
  if (MASSTOR_RED(MS) == MASSTOR_SIL) {
    MS = SACUPFAC_IUSFPF(MI);
    PL = 1;
    if (MASSTOR_RED(MS) != MASSTOR_SIL) {
      PL = 2;
      DIPRN_DIRPWR(MP, V, -1);
      MASBIOS_BLINES(0);
      MASERR_ERROR(MASERR_harmless, "Warning: alpha not prime. ", 26L);
    }
  } else {
    DIPRN_DIRPWR(MP, V, -1);
    MASBIOS_BLINES(0);
    MASERR_ERROR(MASERR_harmless, "Warning: alpha not squarefree. ", 31L);
  }
  if (I == MASSTOR_SIL || PL == 0) {
    SL = -1;
  }
  D = SACLIST_COMP2(M, MI, SACLIST_LIST4(PL, V, I, SL));
  D = MASSTOR_COMP(0, D);
  return D;
}

static void DDDWR
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST AL, AP, SL, M, I, PL, CL, R1, R2, V, MI;

  SACLIST_ADV3(D, &AL, &M, &MI, &AP);
  SACLIST_FIRST4(AP, &PL, &V, &I, &SL);
  MASBIOS_SWRITE("( ", 2L);
  SACLIST_CLOUT(MASSTOR_FIRST(V));
  MASBIOS_SWRITE(", ", 2L);
  CL = DIPC_DIPFP(1, M);
  DIPRN_DIRPWR(CL, V, -1);
  if (I != MASSTOR_SIL) {
    SACLIST_FIRST2(I, &R1, &R2);
    MASBIOS_SWRITE(", ( ", 4L);
    SACRN_RNWRIT(R1);
    MASBIOS_SWRITE(", ", 2L);
    SACRN_RNWRIT(R2);
    MASBIOS_SWRITE(" )", 2L);
    if (SL >= 0) {
      MASBIOS_SWRITE(", ", 2L);
      SACLIST_AWRITE(SL);
    }
  }
  MASBIOS_SWRITE(" ) (* ", 6L);
  if (PL == 0) {
    MASBIOS_SWRITE("reducible", 9L);
  }
  if (PL == 1) {
    MASBIOS_SWRITE("prime", 5L);
  }
  if (PL == 2) {
    MASBIOS_SWRITE("squarefree", 10L);
  }
  MASBIOS_SWRITE(" *) ", 4L);
  return;
}

void DOMAF_DomLoadAF
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("AF", 2L, "Algebraic Number", 16L);
  DOMAF_DOMAFD = d;
  MASADOM_SetDifFunc(d, DDIF);
  MASADOM_SetExpFunc(d, DEXP);
  MASADOM_SetFIntFunc(d, DFI);
  MASADOM_SetFIPolFunc(d, DFIP);
  MASADOM_SetInvFunc(d, DINV);
  MASADOM_SetInvTFunc(d, DINVT);
  MASADOM_SetNegFunc(d, DNEG);
  MASADOM_SetOneFunc(d, DONE);
  MASADOM_SetProdFunc(d, DPROD);
  MASADOM_SetQuotFunc(d, DQUOT);
  MASADOM_SetReadFunc(d, DREAD);
  MASADOM_SetSignFunc(d, DSIGN);
  MASADOM_SetSumFunc(d, DSUM);
  MASADOM_SetWritFunc(d, DWRIT);
  MASADOM_SetDdrdFunc(d, DDDRD);
  MASADOM_SetDdwrFunc(d, DDDWR);
  MASADOM_SetPNormFunc(d, DPNF);
  MASADOM_SetPSpolFunc(d, DPSP);
  MASADOM_SetPSugNormFunc(d, DPSUGNF);
  MASADOM_SetPSugSpolFunc(d, DPSUGSP);
}

static MASSTOR_LIST AFEXP
# ifdef __STDC__
(MASSTOR_LIST MP, MASSTOR_LIST C_249_A, MASSTOR_LIST NL)
# else
(MP, C_249_A, NL)
MASSTOR_LIST MP, C_249_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = AFFINT(1);
    return B;
  }
  if (NL == 1) {
    B = C_249_A;
    return B;
  }
  KL = NL / 2;
  B = AFEXP(MP, C_249_A, KL);
  B = SACANF_AFPROD(MP, B, B);
  if (NL > 2 * KL) {
    B = SACANF_AFPROD(MP, B, C_249_A);
  }
  return B;
}

static MASSTOR_LIST AFHOM
# ifdef __STDC__
(MASSTOR_LIST MP, MASSTOR_LIST C_248_A)
# else
(MP, C_248_A)
MASSTOR_LIST MP, C_248_A;
# endif
{
  MASSTOR_LIST B, C, BL;

  SACRPOL_RPQR(1, C_248_A, MP, &C, &B);
  return B;
}

static MASSTOR_LIST AFFINT
# ifdef __STDC__
(MASSTOR_LIST C_247_A)
# else
(C_247_A)
MASSTOR_LIST C_247_A;
# endif
{
  MASSTOR_LIST B, C, BL;

  BL = SACRN_RNINT(C_247_A);
  B = SACPOL_PINV(0, BL, 1);
  return B;
}

void BEGIN_DOMAF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASADOM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_SACRPOL();
    BEGIN_SACANF();
    BEGIN_DIPC();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();
    BEGIN_DIPI();
    BEGIN_DIPRN();
    BEGIN_DIPRNPOL();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_SACEXT8();
    BEGIN_SACPGCD();
    BEGIN_SACUPFAC();

  }
}
