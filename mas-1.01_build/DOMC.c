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

#ifndef DEFINITION_MASC
#include "MASC.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DOMC
#include "DOMC.h"
#endif

CHAR DOMC_rcsid [] = "$Id: DOMC.md,v 1.1 1992/09/28 17:47:02 kredel Exp $";
CHAR DOMC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
MASADOM_Domain DOMC_DOMCD;

static CHAR rcsidi [] = "$Id: DOMC.mi,v 1.5 1994/09/06 11:48:51 rose Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_59_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_58_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_57_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_56_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_55_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_54_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_53_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_52_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_51_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_50_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_49_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_48_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_47_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_46_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_45_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_59_A, MASSTOR_LIST B)
# else
(C_59_A, B)
MASSTOR_LIST C_59_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_59_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASC_CDIF(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_58_A, MASSTOR_LIST NL)
# else
(C_58_A, NL)
MASSTOR_LIST C_58_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_58_A, &AL, &AP);
  CL = MASC_CEXP(AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_57_A)
# else
(D, C_57_A)
MASSTOR_LIST D, C_57_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = MASC_CINT(C_57_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_56_A)
# else
(D, C_56_A)
MASSTOR_LIST D, C_56_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = MASC_CINT(C_56_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_55_A)
# else
(C_55_A)
MASSTOR_LIST C_55_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_55_A, &AL, &AP);
  CL = MASC_CNINV(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_54_A)
# else
(C_54_A)
MASSTOR_LIST C_54_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_54_A, &AL, &AP);
  TL = 1;
  if (AL == 0) {
    TL = 0;
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_53_A)
# else
(C_53_A)
MASSTOR_LIST C_53_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_53_A, &AL, &AP);
  CL = MASC_CNEG(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_52_A)
# else
(C_52_A)
MASSTOR_LIST C_52_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_52_A, &AL, &AP);
  SL = MASC_CONE(AL);
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
(MASSTOR_LIST C_51_A, MASSTOR_LIST B)
# else
(C_51_A, B)
MASSTOR_LIST C_51_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_51_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASC_CPROD(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_50_A, MASSTOR_LIST B)
# else
(C_50_A, B)
MASSTOR_LIST C_50_A, B;
# endif
{
  return DIPGB_DIPSP(C_50_A, B);
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
(MASSTOR_LIST C_49_A, MASSTOR_LIST B)
# else
(C_49_A, B)
MASSTOR_LIST C_49_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_49_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_48_A, MASSTOR_LIST B)
# else
(C_48_A, B)
MASSTOR_LIST C_48_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_48_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASC_CQ(AL, BL);
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
  CL = MASC_CDREAD();
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_47_A)
# else
(C_47_A)
MASSTOR_LIST C_47_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_47_A);
  if (AL == 0) {
    SL = 0;
  } else {
    SL = 1;
  }
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_46_A, MASSTOR_LIST B)
# else
(C_46_A, B)
MASSTOR_LIST C_46_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_46_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASC_CSUM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_45_A)
# else
(C_45_A)
MASSTOR_LIST C_45_A;
# endif
{
  MASSTOR_LIST AL, SL;

  SACLIST_FIRST2(C_45_A, &AL, &SL);
  if (SL < 0) {
    MASC_CNWRITE(AL);
  } else {
    MASC_CDWRITE(AL, SL);
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

void DOMC_DomLoadC
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("C", 1L, "Complex Number", 14L);
  DOMC_DOMCD = d;
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

void BEGIN_DOMC()
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
    BEGIN_MASC();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();

  }
}
