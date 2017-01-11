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

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_MASFF
#include "MASFF.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_SACMUFAC
#include "SACMUFAC.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
#endif

#ifndef DEFINITION_DOMFF
#include "DOMFF.h"
#endif

CHAR DOMFF_rcsid [] = "$Id: DOMFF.md,v 1.1 1992/09/28 17:47:04 kredel Exp $";
CHAR DOMFF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
MASADOM_Domain DOMFF_DOMFFD;

static CHAR rcsidi [] = "$Id: DOMFF.mi,v 1.5 1995/11/05 09:29:05 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_213_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_212_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_211_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_210_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_209_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_208_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_207_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_206_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_205_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_204_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_203_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_202_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_201_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_200_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_199_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_213_A, MASSTOR_LIST B)
# else
(C_213_A, B)
MASSTOR_LIST C_213_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M, p;

  MASSTOR_ADV(C_213_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASFF_FFDIF(p, M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_212_A, MASSTOR_LIST NL)
# else
(C_212_A, NL)
MASSTOR_LIST C_212_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M, p;

  MASSTOR_ADV(C_212_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  CL = MASFF_FFEXP(p, M, AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_211_A)
# else
(D, C_211_A)
MASSTOR_LIST D, C_211_A;
# endif
{
  MASSTOR_LIST C, CL, p, M;

  D = MASSTOR_RED(D);
  SACLIST_FIRST2(D, &p, &M);
  CL = MASFF_FFFINT(p, M, C_211_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_210_A)
# else
(D, C_210_A)
MASSTOR_LIST D, C_210_A;
# endif
{
  MASSTOR_LIST C, CL, M, p, BL, DL;

  D = MASSTOR_RED(D);
  SACLIST_FIRST2(D, &p, &M);
  CL = MASFF_FFHOM(p, M, C_210_A);
  C = MASSTOR_COMP(DL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_209_A)
# else
(C_209_A)
MASSTOR_LIST C_209_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M, p;

  MASSTOR_ADV(C_209_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  CL = MASFF_FFINV(p, M, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_208_A)
# else
(C_208_A)
MASSTOR_LIST C_208_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_208_A, &AL, &AP);
  TL = 0;
  if (AL != 0) {
    TL = SACLIST_THIRD(AP);
    if (TL != 1) {
      TL = 0;
    }
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_207_A)
# else
(C_207_A)
MASSTOR_LIST C_207_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M, p;

  MASSTOR_ADV(C_207_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  CL = MASFF_FFNEG(p, M, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_206_A)
# else
(C_206_A)
MASSTOR_LIST C_206_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_206_A, &AL, &AP);
  SL = MASFF_FFONE(AL);
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
(MASSTOR_LIST C_205_A, MASSTOR_LIST B)
# else
(C_205_A, B)
MASSTOR_LIST C_205_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M, p;

  MASSTOR_ADV(C_205_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASFF_FFPROD(p, M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_204_A, MASSTOR_LIST B)
# else
(C_204_A, B)
MASSTOR_LIST C_204_A, B;
# endif
{
  return DIPGB_DIPSP(C_204_A, B);
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
(MASSTOR_LIST C_203_A, MASSTOR_LIST B)
# else
(C_203_A, B)
MASSTOR_LIST C_203_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_203_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_202_A, MASSTOR_LIST B)
# else
(C_202_A, B)
MASSTOR_LIST C_202_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M, p;

  MASSTOR_ADV(C_202_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASFF_FFQ(p, M, AL, BL);
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
  MASSTOR_LIST C, CL, M, p, RL, V, BL, DL, X;

  D = MASSTOR_RED(D);
  SACLIST_ADV2(D, &p, &M, &X);
  V = SACLIST_SECOND(X);
  CL = MASFF_FFREAD(V);
  DL = MASFF_FFHOM(p, M, CL);
  C = MASSTOR_COMP(DL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_201_A)
# else
(C_201_A)
MASSTOR_LIST C_201_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_201_A);
  if (AL == 0) {
    SL = 0;
  } else {
    SL = 1;
  }
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_200_A, MASSTOR_LIST B)
# else
(C_200_A, B)
MASSTOR_LIST C_200_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M, p;

  MASSTOR_ADV(C_200_A, &AL, &AP);
  SACLIST_FIRST2(AP, &p, &M);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASFF_FFSUM(p, M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_199_A)
# else
(C_199_A)
MASSTOR_LIST C_199_A;
# endif
{
  MASSTOR_LIST AL, AP, SL, M, p, I, PL, CL, N, J, V;

  MASSTOR_ADV(C_199_A, &AL, &AP);
  V = SACLIST_FOURTH(AP);
  MASFF_FFWRITE(AL, V);
  return;
}

static MASSTOR_LIST DDDRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST c, D, PL, pl, M, p, V, RL, L;

  p = 0;
  PL = 0;
  M = 0;
  V = MASSTOR_SIL;
  D = SACLIST_LIST4(p, M, PL, V);
  D = MASSTOR_COMP(0, D);
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "FF domain read: '(' expected.", 29L);
    return D;
  }
  c = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (!MASBIOS_DIGIT(c)) {
    MASERR_ERROR(MASERR_severe, "FF domain read: 'modulus' expected.", 35L);
    return D;
  }
  p = SACI_IREAD();
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(',')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "FF domain read: ',' expected.", 29L);
    return D;
  }
  c = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (!MASBIOS_LETTER(c)) {
    MASERR_ERROR(MASERR_severe, "FF domain read: 'variable' expected.", 36L);
    return D;
  }
  V = SACPOL_VREAD();
  V = MASSTOR_LIST1(V);
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(',')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "FF domain read: ',' expected.", 29L);
    return D;
  }
  M = DIPI_DIIPRD(V);
  DIPC_PFDIP(M, &RL, &M);
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(')')) {
    MASBIOS_BKSP();
    MASERR_ERROR(MASERR_severe, "FF domain read: ')' expected.", 29L);
    return D;
  }
  PL = 1;
  pl = 1;
  L = SACPRIM_IFACT(p);
  if (MASSTOR_RED(L) != MASSTOR_SIL) {
    SACLIST_OWRITE(L);
    MASBIOS_BLINES(0);
    MASERR_ERROR(MASERR_harmless, "Warning: .. not prime number. ", 30L);
    pl = 0;
  }
  L = SACPGCD_MUPSFF(p, M);
  if (MASSTOR_RED(L) != MASSTOR_SIL) {
    SACLIST_OWRITE(L);
    MASBIOS_BLINES(0);
    MASERR_ERROR(MASERR_harmless, "Warning: .. not squarefree. ", 28L);
    PL = 0;
  } else {
    L = SACMUFAC_MUPFBL(p, M);
    if (MASSTOR_RED(L) != MASSTOR_SIL) {
      SACLIST_OWRITE(L);
      MASBIOS_BLINES(0);
      MASERR_ERROR(MASERR_harmless, "Warning: .. not prime. ", 23L);
      PL = 2;
    } else {
      PL = 1;
    }
  }
  PL = PL * pl;
  D = SACLIST_LIST4(p, M, PL, V);
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
  MASSTOR_LIST AL, AP, M, p, PL, CL, V;

  MASSTOR_ADV(D, &AL, &AP);
  SACLIST_FIRST4(AP, &p, &M, &PL, &V);
  MASBIOS_SWRITE("( ", 2L);
  SACI_IWRITE(p);
  MASBIOS_SWRITE(", ", 2L);
  SACLIST_CLOUT(MASSTOR_FIRST(V));
  MASBIOS_SWRITE(", ", 2L);
  CL = DIPC_DIPFP(1, M);
  DIPI_DIIPWR(CL, V);
  MASBIOS_SWRITE(" )", 2L);
  MASBIOS_SWRITE(" (* ", 4L);
  if (PL != 1) {
    MASBIOS_SWRITE("not ", 4L);
  }
  MASBIOS_SWRITE(" prime. *) ", 11L);
  return;
}

void DOMFF_DomLoadFF
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("FF", 2L, "Finite Field", 12L);
  DOMFF_DOMFFD = d;
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

void BEGIN_DOMFF()
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
    BEGIN_SACI();
    BEGIN_SACPOL();
    BEGIN_MASFF();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();
    BEGIN_SACMUFAC();
    BEGIN_SACPGCD();
    BEGIN_SACPRIM();

  }
}
