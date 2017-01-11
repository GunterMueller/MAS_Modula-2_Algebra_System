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

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DOMMD
#include "DOMMD.h"
#endif

MASADOM_Domain DOMMD_DOMMDD;
CHAR DOMMD_rcsid [] = "$Id: DOMMD.md,v 1.2 1992/02/12 17:31:30 pesch Exp $";
CHAR DOMMD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMMD.mi,v 1.5 1994/09/06 11:49:00 rose Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_99_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_98_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_97_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_96_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_95_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_94_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_93_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_92_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_91_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_90_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_89_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_88_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_87_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_86_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_85_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_99_A, MASSTOR_LIST B)
# else
(C_99_A, B)
MASSTOR_LIST C_99_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_99_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACM_MDDIF(M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_98_A, MASSTOR_LIST NL)
# else
(C_98_A, NL)
MASSTOR_LIST C_98_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_98_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  CL = SACM_MDEXP(M, AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_97_A)
# else
(D, C_97_A)
MASSTOR_LIST D, C_97_A;
# endif
{
  MASSTOR_LIST C, CL, M;

  D = MASSTOR_RED(D);
  M = MASSTOR_FIRST(D);
  CL = SACM_MDHOM(M, C_97_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_96_A)
# else
(D, C_96_A)
MASSTOR_LIST D, C_96_A;
# endif
{
  MASSTOR_LIST C, CL, M;

  D = MASSTOR_RED(D);
  M = MASSTOR_FIRST(D);
  CL = SACM_MDHOM(M, C_96_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_95_A)
# else
(C_95_A)
MASSTOR_LIST C_95_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_95_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  CL = SACM_MDINV(M, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_94_A)
# else
(C_94_A)
MASSTOR_LIST C_94_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_94_A, &AL, &AP);
  TL = 0;
  if (AL != 0) {
    TL = MASSTOR_FIRST(AP);
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_93_A)
# else
(C_93_A)
MASSTOR_LIST C_93_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL, M;

  MASSTOR_ADV(C_93_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  CL = SACM_MDNEG(M, AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_92_A)
# else
(C_92_A)
MASSTOR_LIST C_92_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_92_A, &AL, &AP);
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
  return DIPGB_DIPNOR(G, P);
}

static MASSTOR_LIST DPROD
# ifdef __STDC__
(MASSTOR_LIST C_91_A, MASSTOR_LIST B)
# else
(C_91_A, B)
MASSTOR_LIST C_91_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_91_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACM_MDPROD(M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_90_A, MASSTOR_LIST B)
# else
(C_90_A, B)
MASSTOR_LIST C_90_A, B;
# endif
{
  return DIPGB_DIPSP(C_90_A, B);
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
(MASSTOR_LIST C_89_A, MASSTOR_LIST B)
# else
(C_89_A, B)
MASSTOR_LIST C_89_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_89_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_88_A, MASSTOR_LIST B)
# else
(C_88_A, B)
MASSTOR_LIST C_88_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_88_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACM_MDQ(M, AL, BL);
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
  MASSTOR_LIST C, CL, M;

  D = MASSTOR_RED(D);
  M = MASSTOR_FIRST(D);
  CL = SACI_IREAD();
  CL = SACM_MDHOM(M, CL);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_87_A)
# else
(C_87_A)
MASSTOR_LIST C_87_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_87_A);
  SL = SACI_ISIGNF(AL);
  return SL;
}

static MASSTOR_LIST DSUM
# ifdef __STDC__
(MASSTOR_LIST C_86_A, MASSTOR_LIST B)
# else
(C_86_A, B)
MASSTOR_LIST C_86_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL, M;

  MASSTOR_ADV(C_86_A, &AL, &AP);
  M = MASSTOR_FIRST(AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = SACM_MDSUM(M, AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_85_A)
# else
(C_85_A)
MASSTOR_LIST C_85_A;
# endif
{
  MASSTOR_LIST AL;

  AL = MASSTOR_FIRST(C_85_A);
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
  MASSTOR_LIST M, D, PL, MP;

  M = SACI_IREAD();
  MP = SACPRIM_IFACT(M);
  PL = 1;
  if (MASSTOR_RED(MP) != MASSTOR_SIL) {
    SACLIST_OWRITE(MP);
    MASBIOS_BLINES(0);
    MASERR_ERROR(MASERR_harmless, "Warning: Modular digit not prime. ", 34L);
    PL = 0;
  }
  D = SACLIST_LIST3(0, M, PL);
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
  MASSTOR_LIST M, PL;

  SACLIST_FIRST2(MASSTOR_RED(D), &M, &PL);
  MASBIOS_SWRITE(" ", 1L);
  SACI_IWRITE(M);
  MASBIOS_SWRITE(" (*", 3L);
  if (PL != 1) {
    MASBIOS_SWRITE(" not", 4L);
  }
  MASBIOS_SWRITE(" prime. *)", 10L);
  return;
}

void DOMMD_DomLoadMD
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("MD", 2L, "Modular Digit", 13L);
  DOMMD_DOMMDD = d;
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

void BEGIN_DOMMD()
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
    BEGIN_SACM();
    BEGIN_SACPRIM();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();

  }
}
