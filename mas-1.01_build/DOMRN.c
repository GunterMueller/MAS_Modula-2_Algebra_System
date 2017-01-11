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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
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

#ifndef DEFINITION_DOMRN
#include "DOMRN.h"
#endif

MASADOM_Domain DOMRN_DOMRND;
CHAR DOMRN_rcsid [] = "$Id: DOMRN.md,v 1.3 1994/11/03 14:42:16 pfeil Exp $";
CHAR DOMRN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMRN.mi,v 1.5 1994/06/10 12:04:33 pfeil Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_170_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_169_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_168_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_167_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_166_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_165_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_164_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_163_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_162_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_161_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_160_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_159_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_158_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_157_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_156_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DPFAC ARGS((MASSTOR_LIST P));
static MASSTOR_LIST DPSFF ARGS((MASSTOR_LIST C_155_A));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_170_A, MASSTOR_LIST B)
# else
(C_170_A, B)
MASSTOR_LIST C_170_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_170_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACRN_RNDIF(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_169_A, MASSTOR_LIST NL)
# else
(C_169_A, NL)
MASSTOR_LIST C_169_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_169_A, &AL, &AP);
  CL = MASRN_RNEXP(AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_168_A)
# else
(D, C_168_A)
MASSTOR_LIST D, C_168_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = SACRN_RNINT(C_168_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_167_A)
# else
(D, C_167_A)
MASSTOR_LIST D, C_167_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = SACRN_RNINT(C_167_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_166_A)
# else
(C_166_A)
MASSTOR_LIST C_166_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_166_A, &AL, &AP);
  CL = SACRN_RNINV(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_165_A)
# else
(C_165_A)
MASSTOR_LIST C_165_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_165_A, &AL, &AP);
  TL = 1;
  if (AL == 0) {
    TL = 0;
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_164_A)
# else
(C_164_A)
MASSTOR_LIST C_164_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_164_A, &AL, &AP);
  CL = SACRN_RNNEG(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_163_A)
# else
(C_163_A)
MASSTOR_LIST C_163_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_163_A, &AL, &AP);
  SL = MASRN_RNONE(AL);
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
(MASSTOR_LIST C_162_A, MASSTOR_LIST B)
# else
(C_162_A, B)
MASSTOR_LIST C_162_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_162_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACRN_RNPROD(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_161_A, MASSTOR_LIST B)
# else
(C_161_A, B)
MASSTOR_LIST C_161_A, B;
# endif
{
  return DIPGB_DIPSP(C_161_A, B);
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
(MASSTOR_LIST C_160_A, MASSTOR_LIST B)
# else
(C_160_A, B)
MASSTOR_LIST C_160_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_160_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_159_A, MASSTOR_LIST B)
# else
(C_159_A, B)
MASSTOR_LIST C_159_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_159_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACRN_RNQ(AL, BL);
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
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = MASRN_RNDRD();
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_158_A)
# else
(C_158_A)
MASSTOR_LIST C_158_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_158_A);
  SL = SACRN_RNSIGN(AL);
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_157_A, MASSTOR_LIST B)
# else
(C_157_A, B)
MASSTOR_LIST C_157_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_157_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACRN_RNSUM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_156_A)
# else
(C_156_A)
MASSTOR_LIST C_156_A;
# endif
{
  MASSTOR_LIST AL, SL;

  SACLIST_FIRST2(C_156_A, &AL, &SL);
  if (SL < 0) {
    SACRN_RNWRIT(AL);
  } else {
    MASRN_RNDWR(AL, SL);
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
  MASSTOR_LIST D, C, SL;

  SL = -1;
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD('-') || MASBIOS_DIGIT(C)) {
    SL = SACLIST_AREAD();
  }
  D = SACLIST_LIST2(0, SL);
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
  MASSTOR_LIST SL;

  D = MASSTOR_RED(D);
  SL = MASSTOR_FIRST(D);
  MASBIOS_SWRITE(" ", 1L);
  SACLIST_AWRITE(SL);
  MASBIOS_SWRITE(" ", 1L);
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

  P = DIPI_DIIFRP(P);
  DIPC_PFDIP(P, &r, &P);
  SACPFAC_IPFAC(r, P, &S, &C, &F);
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    pol = DIPC_DIPFP(r, pol);
    pol = DIPRN_DIRFIP(pol);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

static MASSTOR_LIST DPSFF
# ifdef __STDC__
(MASSTOR_LIST C_155_A)
# else
(C_155_A)
MASSTOR_LIST C_155_A;
# endif
{
  MASSTOR_LIST r, F, F1, ExpPol, exp, pol;

  C_155_A = DIPI_DIIFRP(C_155_A);
  DIPC_PFDIP(C_155_A, &r, &C_155_A);
  F = MASPGCD_IPSFF(r, C_155_A);
  F1 = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    SACLIST_FIRST2(ExpPol, &exp, &pol);
    pol = DIPC_DIPFP(r, pol);
    pol = DIPRN_DIRFIP(pol);
    F1 = MASSTOR_COMP(SACLIST_LIST2(exp, pol), F1);
  }
  return MASSTOR_INV(F1);
}

void DOMRN_DomLoadRN
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("RN", 2L, "Rational Number", 15L);
  DOMRN_DOMRND = d;
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
  MASADOM_SetPFactFunc(d, DPFAC);
  MASADOM_SetPNormFunc(d, DPNF);
  MASADOM_SetPSqfrFunc(d, DPSFF);
  MASADOM_SetPSpolFunc(d, DPSP);
  MASADOM_SetPSugNormFunc(d, DPSUGNF);
  MASADOM_SetPSugSpolFunc(d, DPSUGSP);
}

void BEGIN_DOMRN()
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
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_DIPI();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_SACPFAC();
    BEGIN_MASPGCD();
    BEGIN_DIPGB();
    BEGIN_DIPAGB();

  }
}
