#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

#ifndef DEFINITION_MASAPF
#include "MASAPF.h"
#endif

#ifndef DEFINITION_DIPAGB
#include "DIPAGB.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DOMAPF
#include "DOMAPF.h"
#endif

MASADOM_Domain DOMAPF_DOMAPFD;
CHAR DOMAPF_rcsid [] = "$Id: DOMAPF.md,v 1.2 1992/02/12 17:31:26 pesch Exp $";
CHAR DOMAPF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DOMAPF.mi,v 1.6 1994/09/06 11:48:48 rose Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST DDIF ARGS((MASSTOR_LIST C_72_A, MASSTOR_LIST B));
static MASSTOR_LIST DEXP ARGS((MASSTOR_LIST C_71_A, MASSTOR_LIST NL));
static MASSTOR_LIST DFI ARGS((MASSTOR_LIST D, MASSTOR_LIST C_70_A));
static MASSTOR_LIST DFIP ARGS((MASSTOR_LIST D, MASSTOR_LIST C_69_A));
static MASSTOR_LIST DINV ARGS((MASSTOR_LIST C_68_A));
static MASSTOR_LIST DINVT ARGS((MASSTOR_LIST C_67_A));
static MASSTOR_LIST DNEG ARGS((MASSTOR_LIST C_66_A));
static MASSTOR_LIST DONE ARGS((MASSTOR_LIST C_65_A));
static MASSTOR_LIST DPNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPROD ARGS((MASSTOR_LIST C_64_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSP ARGS((MASSTOR_LIST C_63_A, MASSTOR_LIST B));
static MASSTOR_LIST DPSUGNF ARGS((MASSTOR_LIST G, MASSTOR_LIST P));
static MASSTOR_LIST DPSUGSP ARGS((MASSTOR_LIST C_62_A, MASSTOR_LIST B));
static MASSTOR_LIST DQUOT ARGS((MASSTOR_LIST C_61_A, MASSTOR_LIST B));
static MASSTOR_LIST DREAD ARGS((MASSTOR_LIST D));
static MASSTOR_LIST DSIGN ARGS((MASSTOR_LIST C_60_A));
static MASSTOR_LIST DSUM ARGS((MASSTOR_LIST C_59_A, MASSTOR_LIST B));
static void DWRIT ARGS((MASSTOR_LIST C_58_A));
static MASSTOR_LIST DDDRD ARGS(());
static void DDDWR ARGS((MASSTOR_LIST D));


static MASSTOR_LIST DDIF
# ifdef __STDC__
(MASSTOR_LIST C_72_A, MASSTOR_LIST B)
# else
(C_72_A, B)
MASSTOR_LIST C_72_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_72_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASAPF_APDIFF(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DEXP
# ifdef __STDC__
(MASSTOR_LIST C_71_A, MASSTOR_LIST NL)
# else
(C_71_A, NL)
MASSTOR_LIST C_71_A, NL;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_71_A, &AL, &AP);
  CL = MASAPF_APEXP(AL, NL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DFI
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_70_A)
# else
(D, C_70_A)
MASSTOR_LIST D, C_70_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = MASAPF_APFINT(C_70_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DFIP
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST C_69_A)
# else
(D, C_69_A)
MASSTOR_LIST D, C_69_A;
# endif
{
  MASSTOR_LIST C, CL;

  D = MASSTOR_RED(D);
  CL = MASAPF_APFINT(C_69_A);
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DINV
# ifdef __STDC__
(MASSTOR_LIST C_68_A)
# else
(C_68_A)
MASSTOR_LIST C_68_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_68_A, &AL, &AP);
  CL = MASAPF_APQ(MASAPF_APFINT(1), AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DINVT
# ifdef __STDC__
(MASSTOR_LIST C_67_A)
# else
(C_67_A)
MASSTOR_LIST C_67_A;
# endif
{
  MASSTOR_LIST AL, AP, TL;

  MASSTOR_ADV(C_67_A, &AL, &AP);
  TL = 1;
  if (MASAPF_APSIGN(AL) == 0) {
    TL = 0;
  }
  return TL;
}

static MASSTOR_LIST DNEG
# ifdef __STDC__
(MASSTOR_LIST C_66_A)
# else
(C_66_A)
MASSTOR_LIST C_66_A;
# endif
{
  MASSTOR_LIST AL, AP, C, CL;

  MASSTOR_ADV(C_66_A, &AL, &AP);
  CL = MASAPF_APNEG(AL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DONE
# ifdef __STDC__
(MASSTOR_LIST C_65_A)
# else
(C_65_A)
MASSTOR_LIST C_65_A;
# endif
{
  MASSTOR_LIST AL, AP, SL;

  MASSTOR_ADV(C_65_A, &AL, &AP);
  SL = MASAPF_APCMPR(MASAPF_APFINT(1), AL);
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
(MASSTOR_LIST C_64_A, MASSTOR_LIST B)
# else
(C_64_A, B)
MASSTOR_LIST C_64_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_64_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASAPF_APPROD(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static MASSTOR_LIST DPSP
# ifdef __STDC__
(MASSTOR_LIST C_63_A, MASSTOR_LIST B)
# else
(C_63_A, B)
MASSTOR_LIST C_63_A, B;
# endif
{
  return DIPGB_DIPSP(C_63_A, B);
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
(MASSTOR_LIST C_62_A, MASSTOR_LIST B)
# else
(C_62_A, B)
MASSTOR_LIST C_62_A, B;
# endif
{
  return DIPAGB_EDIPSUGSP(C_62_A, B);
}

static MASSTOR_LIST DQUOT
# ifdef __STDC__
(MASSTOR_LIST C_61_A, MASSTOR_LIST B)
# else
(C_61_A, B)
MASSTOR_LIST C_61_A, B;
# endif
{
  MASSTOR_LIST AL, AP, BL, BP, C, CL;

  MASSTOR_ADV(C_61_A, &AL, &AP);
  MASSTOR_ADV(B, &BL, &BP);
  CL = MASAPF_APQ(AL, BL);
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
  CL = MASAPF_APFRN(MASAPF_RNDRD());
  C = MASSTOR_COMP(CL, D);
  return C;
}

static MASSTOR_LIST DSIGN
# ifdef __STDC__
(MASSTOR_LIST C_60_A)
# else
(C_60_A)
MASSTOR_LIST C_60_A;
# endif
{
  MASSTOR_LIST AL, SL;

  AL = MASSTOR_FIRST(C_60_A);
  SL = MASAPF_APSIGN(AL);
  return SL;
}

static MASSTOR_LIST DSUM
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
  CL = MASAPF_APSUM(AL, BL);
  C = MASSTOR_COMP(CL, AP);
  return C;
}

static void DWRIT
# ifdef __STDC__
(MASSTOR_LIST C_58_A)
# else
(C_58_A)
MASSTOR_LIST C_58_A;
# endif
{
  MASSTOR_LIST AL, SL;

  SACLIST_FIRST2(C_58_A, &AL, &SL);
  MASAPF_APWRIT(AL);
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

  SL = 20;
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (MASBIOS_DIGIT(C)) {
    SL = SACLIST_AREAD();
  }
  MASAPF_APSPRE(SL);
  D = SACLIST_LIST2(MASAPF_APFINT(0), SL);
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

void DOMAPF_DomLoadAPF
# ifdef __STDC__
()
# else
()
# endif
{
  MASADOM_Domain d;

  d = MASADOM_NewDom("APF", 3L, "Arbitrary Precision Floating Point", 34L);
  DOMAPF_DOMAPFD = d;
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

void BEGIN_DOMAPF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASADOM();
    BEGIN_MASSTOR();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASAPF();
    BEGIN_DIPAGB();
    BEGIN_DIPGB();

  }
}
