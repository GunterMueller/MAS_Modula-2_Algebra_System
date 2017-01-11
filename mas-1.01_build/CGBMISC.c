#include "SYSTEM_.h"

#ifndef DEFINITION_ADTOOLS
#include "ADTOOLS.h"
#endif

#ifndef DEFINITION_CGBAPPL
#include "CGBAPPL.h"
#endif

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

#ifndef DEFINITION_CGBSYS
#include "CGBSYS.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPIDGB
#include "DIPIDGB.h"
#endif

#ifndef DEFINITION_DIPIGB
#include "DIPIGB.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
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

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

CHAR CGBMISC_rcsid [] = "$Id: CGBMISC.md,v 1.6 1995/03/06 15:49:40 pesch Exp $";
CHAR CGBMISC_copyright [] = "Copyright (c) 1993 Universitaet Passau";
CGBMISC_CGBPAR CGBMISC_PAR;

static CHAR rcsidi [] = "$Id: CGBMISC.mip,v 1.10 1996/06/08 16:47:13 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1992-1996 Universitaet Passau";
static MASSTOR_LIST EVORDSTACK;
static MASSTOR_LIST VALISSTACK;
static CGBMISC_COLOUR CondEvalSim ARGS((MASSTOR_LIST Cond, MASSTOR_LIST COEF));
static CGBMISC_COLOUR CondEvalRed ARGS((MASSTOR_LIST Cond, MASSTOR_LIST COEF));
static CGBMISC_COLOUR CondEvalDred ARGS((MASSTOR_LIST Cond, MASSTOR_LIST COEF));
static CGBMISC_COLOUR CondEvalGb ARGS((MASSTOR_LIST Cond, MASSTOR_LIST COEF));
static void CondRamifSim ARGS((MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1));
static void CondRamifRed ARGS((MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1));
static void CondRamifDred ARGS((MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1));
static void CondRamifGb ARGS((MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1));
static CGBMISC_COLOUR CondEvalGen ARGS((MASSTOR_LIST Cond, MASSTOR_LIST COEF));
static void CondRamifGen ARGS((MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1));
static MASSTOR_LIST DIP2AD ARGS((MASSTOR_LIST P, MASSTOR_LIST d, MASSTOR_LIST rest));
static MASSTOR_LIST AD2DIP ARGS((MASSTOR_LIST P, MASSTOR_LIST *d, MASSTOR_LIST *rest));
static MASSTOR_LIST DIPPFACTAV ARGS((MASSTOR_LIST P));


void CGBMISC_EvordSet
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  EVORDSTACK = MASSTOR_COMP(DIPC_EVORD, EVORDSTACK);
  DIPC_EVORD = T;
}

void CGBMISC_EvordReset
# ifdef __STDC__
()
# else
()
# endif
{
  if (EVORDSTACK == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "Error in EvordReset. Stack empty.", 33L);
  } else {
    MASSTOR_ADV(EVORDSTACK, &DIPC_EVORD, &EVORDSTACK);
  }
}

void CGBMISC_ValisSet
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  VALISSTACK = MASSTOR_COMP(DIPC_VALIS, VALISSTACK);
  DIPC_VALIS = V;
}

void CGBMISC_ValisReset
# ifdef __STDC__
()
# else
()
# endif
{
  if (VALISSTACK == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "Error in ValisReset. Stack empty.", 33L);
  } else {
    MASSTOR_ADV(VALISSTACK, &DIPC_VALIS, &VALISSTACK);
  }
}

MASSTOR_LIST CGBMISC_SetInsert
# ifdef __STDC__
(MASSTOR_LIST e, MASSTOR_LIST C_178_A)
# else
(e, C_178_A)
MASSTOR_LIST e, C_178_A;
# endif
{
  if (SACLIST_MEMBER(e, C_178_A) == 1) {
    return C_178_A;
  }
  return MASSTOR_COMP(e, C_178_A);
}

MASSTOR_LIST CGBMISC_SetUnion
# ifdef __STDC__
(MASSTOR_LIST C_177_A, MASSTOR_LIST B)
# else
(C_177_A, B)
MASSTOR_LIST C_177_A, B;
# endif
{
  MASSTOR_LIST e;

  while (B != MASSTOR_SIL) {
    MASSTOR_ADV(B, &e, &B);
    C_177_A = CGBMISC_SetInsert(e, C_177_A);
  }
  return C_177_A;
}

void CGBMISC_CGBOPT
# ifdef __STDC__
(MASSTOR_LIST O)
# else
(O)
MASSTOR_LIST O;
# endif
{
  MASSTOR_LIST C_176_dummy;

  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.outputlevel, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.factorize, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.normalform, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.compcond, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.C_0_char, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.TermOrderPol, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &CGBMISC_PAR.TermOrderCoef, &O);
  }
  if (O != MASSTOR_SIL) {
    MASSTOR_ADV(O, &C_176_dummy, &O);
    CGBMISC_PAR.genericOnly = C_176_dummy == 1;
  }
  switch (CGBMISC_PAR.factorize) {
  case 0:;
    CGBMISC_PAR.Factorize = CGBMISC_dummyfactorize;
    break;
  case 1:;
    CGBMISC_PAR.Factorize = MASADOM_ADFACT;
    break;
  case 2:;
    CGBMISC_PAR.Factorize = MASADOM_ADFACTO;
    break;
  }
  if (CGBMISC_PAR.normalform == 0) {
    CGBMISC_PAR.NormalForm = CGBSYS_NFTOP;
  } else {
    CGBMISC_PAR.NormalForm = CGBSYS_NFORM;
  }
  if (CGBMISC_PAR.genericOnly) {
    CGBMISC_PAR.CondEval = CondEvalGen;
    CGBMISC_PAR.CondRamif = CondRamifGen;
  } else {
    switch (CGBMISC_PAR.compcond) {
    case 0:;
      CGBMISC_PAR.CondEval = CondEvalSim;
      CGBMISC_PAR.CondRamif = CondRamifSim;
      break;
    case 1:;
      if (CGBMISC_PAR.C_0_char == 0) {
        CGBMISC_PAR.CondEval = CondEvalRed;
        CGBMISC_PAR.CondRamif = CondRamifRed;
      } else {
        CGBMISC_PAR.CondEval = CondEvalDred;
        CGBMISC_PAR.CondRamif = CondRamifDred;
      }
      break;
    case 2:;
      CGBMISC_PAR.CondEval = CondEvalGb;
      CGBMISC_PAR.CondRamif = CondRamifGb;
      break;
    }
  }
  if (CGBMISC_PAR.C_0_char == 0) {
    CGBMISC_PAR.IsCnst = MASADOM_ADCNST;
  } else {
    CGBMISC_PAR.IsCnst = CGBMISC_dummycnst;
  }
  CGBMISC_PAR.Factors = DIPPFACTAV;
}

void CGBMISC_CGBOPTWRITE
# ifdef __STDC__
()
# else
()
# endif
{
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Options for computation of Groebner systems are: ", 49L);
  MASBIOS_SWRITE("(", 1L);
  MASSYM2_UWRIT1(CGBMISC_PAR.outputlevel);
  MASBIOS_SWRITE(",", 1L);
  if (CGBMISC_PAR.factorize) {
    MASBIOS_SWRITE("1,", 2L);
  } else {
    MASBIOS_SWRITE("0,", 2L);
  }
  MASSYM2_UWRIT1(CGBMISC_PAR.normalform);
  MASBIOS_SWRITE(",", 1L);
  MASSYM2_UWRIT1(CGBMISC_PAR.compcond);
  MASBIOS_SWRITE(",", 1L);
  MASSYM2_UWRIT1(CGBMISC_PAR.C_0_char);
  MASBIOS_SWRITE(",", 1L);
  MASSYM2_UWRIT1(CGBMISC_PAR.TermOrderPol);
  MASBIOS_SWRITE(",", 1L);
  MASSYM2_UWRIT1(CGBMISC_PAR.TermOrderCoef);
  MASBIOS_SWRITE(",", 1L);
  if (CGBMISC_PAR.genericOnly) {
    MASBIOS_SWRITE("1", 1L);
  } else {
    MASBIOS_SWRITE("0", 1L);
  }
  MASBIOS_SWRITE(")", 1L);
  MASBIOS_BLINES(0);
  switch (CGBMISC_PAR.outputlevel) {
  case 0:;
    MASBIOS_SWRITE("No output.", 10L);
    break;
  case 1:;
    MASBIOS_SWRITE("Some output during computation.", 31L);
    break;
  }
  MASBIOS_BLINES(0);
  switch (CGBMISC_PAR.factorize) {
  case 0:;
    MASBIOS_SWRITE("Without factorization of coefficients.", 38L);
    break;
  case 1:;
    MASBIOS_SWRITE("With factorization of coefficients.", 35L);
    break;
  case 2:;
    MASBIOS_SWRITE("With factorization using variable order optimization of coefficients.", 69L);
    break;
  }
  MASBIOS_BLINES(0);
  if (CGBMISC_PAR.normalform == 0) {
    MASBIOS_SWRITE("Top-reduction only.", 19L);
  } else {
    MASBIOS_SWRITE("Normal reduction.", 17L);
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Conditions are evaluated ", 25L);
  switch (CGBMISC_PAR.compcond) {
  case 0:;
    MASBIOS_SWRITE("by comparing.", 13L);
    break;
  case 1:;
    MASBIOS_SWRITE("using reduced sets. ", 20L);
    MASBIOS_BLINES(0);
    break;
  case 2:;
    MASBIOS_SWRITE("using Groebner bases.", 21L);
    MASBIOS_BLINES(0);
    break;
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Characteristic is ", 18L);
  if (CGBMISC_PAR.C_0_char == 0) {
    MASBIOS_SWRITE("0.", 2L);
  } else {
    MASBIOS_SWRITE("arbitrary.", 10L);
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Term order: ", 12L);
  DIPC_EVOWRITE(CGBMISC_PAR.TermOrderPol);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Coefficient term order: ", 24L);
  DIPC_EVOWRITE(CGBMISC_PAR.TermOrderCoef);
  MASBIOS_BLINES(0);
  if (CGBMISC_PAR.genericOnly) {
    MASBIOS_SWRITE("Generic case only.", 18L);
  } else {
    MASBIOS_SWRITE("All cases are considered.", 25L);
  }
  MASBIOS_BLINES(0);
  MASBIOS_BLINES(1);
}

BOOLEAN CGBMISC_dummycnst
# ifdef __STDC__
(MASSTOR_LIST C_175_A)
# else
(C_175_A)
MASSTOR_LIST C_175_A;
# endif
{
  return FALSE;
}

MASSTOR_LIST CGBMISC_dummyfactorize
# ifdef __STDC__
(MASSTOR_LIST C_174_A)
# else
(C_174_A)
MASSTOR_LIST C_174_A;
# endif
{
  return MASSTOR_LIST1(C_174_A);
}

static CGBMISC_COLOUR CondEvalSim
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST COEF)
# else
(Cond, COEF)
MASSTOR_LIST Cond, COEF;
# endif
{
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondZero(Cond)) == 1) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1) {
    return CGBMISC_nzero;
  }
  return CGBMISC_unknown;
}

static CGBMISC_COLOUR CondEvalRed
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST COEF)
# else
(Cond, COEF)
MASSTOR_LIST Cond, COEF;
# endif
{
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondZero(Cond)) == 1) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1) {
    return CGBMISC_nzero;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  COEF = CGBMISC_PFINOR(CGBDSTR_CondZero(Cond), COEF);
  CGBMISC_EvordReset();
  if (COEF == MASSTOR_SIL) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1 || (*CGBMISC_PAR.IsCnst)(COEF)) {
    return CGBMISC_nzero;
  }
  return CGBMISC_unknown;
}

static CGBMISC_COLOUR CondEvalDred
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST COEF)
# else
(Cond, COEF)
MASSTOR_LIST Cond, COEF;
# endif
{
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondZero(Cond)) == 1) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1) {
    return CGBMISC_nzero;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  COEF = CGBMISC_PFIDNOR(CGBDSTR_CondZero(Cond), COEF);
  CGBMISC_EvordReset();
  if (COEF == MASSTOR_SIL) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1) {
    return CGBMISC_nzero;
  }
  return CGBMISC_unknown;
}

static CGBMISC_COLOUR CondEvalGb
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST COEF)
# else
(Cond, COEF)
MASSTOR_LIST Cond, COEF;
# endif
{
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  COEF = CGBMISC_PFINOR(CGBDSTR_CondZero(Cond), COEF);
  CGBMISC_EvordReset();
  if (COEF == MASSTOR_SIL) {
    return CGBMISC_zero;
  }
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1 || (*CGBMISC_PAR.IsCnst)(COEF)) {
    return CGBMISC_nzero;
  }
  return CGBMISC_unknown;
}

static void CondRamifSim
# ifdef __STDC__
(MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1)
# else
(COEF, Cond, CD0, CD1)
MASSTOR_LIST COEF, Cond;
MASSTOR_LIST *CD0, *CD1;
# endif
{
  *CD0 = CGBDSTR_CondCons(MASSTOR_COMP(COEF, CGBDSTR_CondZero(Cond)), CGBDSTR_CondNzero(Cond));
  *CD1 = CGBDSTR_CondCons(CGBDSTR_CondZero(Cond), MASSTOR_COMP(COEF, CGBDSTR_CondNzero(Cond)));
}

static void CondRamifRed
# ifdef __STDC__
(MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1)
# else
(COEF, Cond, CD0, CD1)
MASSTOR_LIST COEF, Cond;
MASSTOR_LIST *CD0, *CD1;
# endif
{
  MASSTOR_LIST RED, RS;
  BOOLEAN ONE, ZERO;

  *CD0 = CGBDSTR_CondEmpty();
  *CD1 = CGBDSTR_CondEmpty();
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  RED = CGBMISC_PFILS(MASSTOR_COMP(COEF, CGBDSTR_CondZero(Cond)), &ONE);
  RS = CGBMISC_PFILNOR(RED, CGBDSTR_CondNzero(Cond), &ZERO);
  if (!(ONE || ZERO)) {
    *CD0 = CGBDSTR_CondCons(CGBMISC_SetInsert(COEF, CGBMISC_SetUnion(RED, CGBDSTR_CondZero(Cond))), CGBMISC_SetUnion(RS, CGBDSTR_CondNzero(Cond)));
  }
  RS = CGBMISC_PFILNOR(CGBDSTR_CondZero(Cond), MASSTOR_COMP(COEF, CGBDSTR_CondNzero(Cond)), &ZERO);
  if (!ZERO) {
    *CD1 = CGBDSTR_CondCons(CGBDSTR_CondZero(Cond), CGBMISC_SetUnion(RS, CGBDSTR_CondNzero(Cond)));
  }
  CGBMISC_EvordReset();
}

static void CondRamifDred
# ifdef __STDC__
(MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1)
# else
(COEF, Cond, CD0, CD1)
MASSTOR_LIST COEF, Cond;
MASSTOR_LIST *CD0, *CD1;
# endif
{
  MASSTOR_LIST RED, RS;
  BOOLEAN ONE, ZERO;

  *CD0 = CGBDSTR_CondEmpty();
  *CD1 = CGBDSTR_CondEmpty();
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  RED = CGBMISC_PFILDS(MASSTOR_COMP(COEF, CGBDSTR_CondZero(Cond)), &ONE);
  RS = CGBMISC_PFILDNOR(RED, CGBDSTR_CondNzero(Cond), &ZERO);
  if (!(ONE || ZERO)) {
    *CD0 = CGBDSTR_CondCons(CGBMISC_SetInsert(COEF, CGBMISC_SetUnion(RED, CGBDSTR_CondZero(Cond))), CGBMISC_SetUnion(RS, CGBDSTR_CondNzero(Cond)));
  }
  RS = CGBMISC_PFILDNOR(CGBDSTR_CondZero(Cond), MASSTOR_COMP(COEF, CGBDSTR_CondNzero(Cond)), &ZERO);
  if (!ZERO) {
    *CD1 = CGBDSTR_CondCons(CGBDSTR_CondZero(Cond), CGBMISC_SetUnion(RS, CGBDSTR_CondNzero(Cond)));
  }
  CGBMISC_EvordReset();
}

static void CondRamifGb
# ifdef __STDC__
(MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1)
# else
(COEF, Cond, CD0, CD1)
MASSTOR_LIST COEF, Cond;
MASSTOR_LIST *CD0, *CD1;
# endif
{
  MASSTOR_LIST GB, RS;
  BOOLEAN ONE, ZERO;

  *CD0 = CGBDSTR_CondEmpty();
  *CD1 = CGBDSTR_CondEmpty();
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  GB = CGBMISC_PFIGBA(CGBDSTR_CondZero(Cond), COEF, CGBMISC_PAR.outputlevel, &ONE);
  RS = CGBMISC_PFILNOR(GB, CGBDSTR_CondNzero(Cond), &ZERO);
  if (!(ONE || ZERO)) {
    *CD0 = CGBDSTR_CondCons(GB, RS);
  }
  RS = CGBMISC_PFILNOR(CGBDSTR_CondZero(Cond), MASSTOR_COMP(COEF, CGBDSTR_CondNzero(Cond)), &ZERO);
  if (!ZERO) {
    *CD1 = CGBDSTR_CondCons(CGBDSTR_CondZero(Cond), RS);
  }
  CGBMISC_EvordReset();
}

static CGBMISC_COLOUR CondEvalGen
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST COEF)
# else
(Cond, COEF)
MASSTOR_LIST Cond, COEF;
# endif
{
  if (SACLIST_MEMBER(COEF, CGBDSTR_CondNzero(Cond)) == 1) {
    return CGBMISC_nzero;
  }
  return CGBMISC_unknown;
}

static void CondRamifGen
# ifdef __STDC__
(MASSTOR_LIST COEF, MASSTOR_LIST Cond, MASSTOR_LIST *CD0, MASSTOR_LIST *CD1)
# else
(COEF, Cond, CD0, CD1)
MASSTOR_LIST COEF, Cond;
MASSTOR_LIST *CD0, *CD1;
# endif
{
  *CD0 = CGBDSTR_CondEmpty();
  *CD1 = CGBDSTR_CondCons(MASSTOR_SIL, MASSTOR_COMP(COEF, CGBDSTR_CondNzero(Cond)));
}

void CGBMISC_FLWRITE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST E;
  INTEGER I;

  if (L < MASSTOR_BETA) {
    SACLIST_AWRITE(L);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &E, &L);
    if (E < MASSTOR_BETA) {
      SACLIST_AWRITE(E);
    } else {
      CGBMISC_FILWRITE(E, 1);
    }
    if (L != MASSTOR_SIL) {
      MASBIOS_SWRITE(",", 1L);
    }
  }
  MASBIOS_SWRITE(")", 1L);
  return;
}

void CGBMISC_FILWRITE
# ifdef __STDC__
(MASSTOR_LIST L, INTEGER N)
# else
(L, N)
MASSTOR_LIST L;
INTEGER N;
# endif
{
  MASSTOR_LIST E;
  INTEGER I;
  BOOLEAN R;

  MASBIOS_BLINES(0);
  {
    LONGINT B_1 = 1, B_2 = N;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        MASBIOS_SWRITE(" ", 1L);
        if (I >= B_2) break;
      }
  }
  MASBIOS_SWRITE("(", 1L);
  R = FALSE;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &E, &L);
    if (E < MASSTOR_BETA) {
      SACLIST_AWRITE(E);
    } else {
      CGBMISC_FILWRITE(E, N + 1);
      R = TRUE;
    }
    if (L != MASSTOR_SIL) {
      MASBIOS_SWRITE(",", 1L);
    }
  }
  if (R) {
    MASBIOS_BLINES(0);
    {
      LONGINT B_3 = 1, B_4 = N;

      if (B_3 <= B_4)
        for (I = B_3;; I += 1) {
          MASBIOS_SWRITE(" ", 1L);
          if (I >= B_4) break;
        }
    }
  }
  MASBIOS_SWRITE(")", 1L);
}

MASSTOR_LIST CGBMISC_XPFDIP
# ifdef __STDC__
(MASSTOR_LIST DP, MASSTOR_LIST DOM, MASSTOR_LIST VARL)
# else
(DP, DOM, VARL)
MASSTOR_LIST DP, DOM, VARL;
# endif
{
  MASSTOR_LIST R, B, TEVORD;

  CGBMISC_EvordSet(DIPC_INVLEX);
  DIPC_DIPBSO(DP);
  DIPC_PFDIP(DP, &R, &B);
  CGBMISC_EvordReset();
  return SACLIST_LIST4(DOM, B, R, VARL);
}

MASSTOR_LIST CGBMISC_PFLDIPL
# ifdef __STDC__
(MASSTOR_LIST DIPL, MASSTOR_LIST DOM, MASSTOR_LIST VARL)
# else
(DIPL, DOM, VARL)
MASSTOR_LIST DIPL, DOM, VARL;
# endif
{
  MASSTOR_LIST RET, P, B;

  RET = MASSTOR_SIL;
  while (DIPL != MASSTOR_SIL) {
    MASSTOR_ADV(DIPL, &P, &DIPL);
    RET = MASSTOR_COMP(CGBMISC_XPFDIP(P, DOM, VARL), RET);
  }
  return MASSTOR_INV(RET);
}

MASSTOR_LIST CGBMISC_XDIPFPF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL)
# else
(P, DOM, VARL)
MASSTOR_LIST P;
MASSTOR_LIST *DOM, *VARL;
# endif
{
  MASSTOR_LIST B, R, DI;

  SACLIST_FIRST4(P, DOM, &B, &R, VARL);
  DI = DIPC_DIPFP(R, B);
  DIPC_DIPBSO(DI);
  return DI;
}

MASSTOR_LIST CGBMISC_DIPLFPFL
# ifdef __STDC__
(MASSTOR_LIST PFL, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL)
# else
(PFL, DOM, VARL)
MASSTOR_LIST PFL;
MASSTOR_LIST *DOM, *VARL;
# endif
{
  MASSTOR_LIST RET, P;

  RET = MASSTOR_SIL;
  while (PFL != MASSTOR_SIL) {
    MASSTOR_ADV(PFL, &P, &PFL);
    RET = MASSTOR_COMP(CGBMISC_XDIPFPF(P, DOM, VARL), RET);
  }
  return MASSTOR_INV(RET);
}

MASSTOR_LIST CGBMISC_DIFPF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL)
# else
(P, D, DOM, VARL)
MASSTOR_LIST P, D;
MASSTOR_LIST *DOM, *VARL;
# endif
{
  MASSTOR_LIST AL, EL, B, BL;

  P = CGBMISC_XDIPFPF(P, DOM, VARL);
  if (P == 0) {
    return 0;
  }
  CGBMISC_ValisSet(*VARL);
  B = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    DIPC_DIPMAD(P, &AL, &EL, &P);
    BL = MASADOM_ADFI(D, AL);
    if (MASADOM_ADSIGN(BL) != 0) {
      B = DIPC_DIPMCP(EL, BL, B);
    }
  }
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
    DIPC_DIPBSO(B);
  }
  CGBMISC_ValisReset();
  return B;
}

MASSTOR_LIST CGBMISC_DILFPFL
# ifdef __STDC__
(MASSTOR_LIST PFL, MASSTOR_LIST D, MASSTOR_LIST *DOM, MASSTOR_LIST *VARL)
# else
(PFL, D, DOM, VARL)
MASSTOR_LIST PFL, D;
MASSTOR_LIST *DOM, *VARL;
# endif
{
  MASSTOR_LIST RET, P;

  RET = MASSTOR_SIL;
  while (PFL != MASSTOR_SIL) {
    MASSTOR_ADV(PFL, &P, &PFL);
    RET = MASSTOR_COMP(CGBMISC_DIFPF(P, D, DOM, VARL), RET);
  }
  return MASSTOR_INV(RET);
}

MASSTOR_LIST CGBMISC_PFIGB
# ifdef __STDC__
(MASSTOR_LIST PFL, MASSTOR_LIST TF, BOOLEAN *ONE)
# else
(PFL, TF, ONE)
MASSTOR_LIST PFL, TF;
BOOLEAN *ONE;
# endif
{
  MASSTOR_LIST GB, DOM, VARL;

  *ONE = FALSE;
  PFL = CGBMISC_DIPLFPFL(PFL, &DOM, &VARL);
  DIPC_DILBSO(PFL);
  CGBMISC_ValisSet(VARL);
  GB = DIPIGB_DIIPGB(PFL, TF);
  if (GB != MASSTOR_SIL) {
    if (DIPI_DIIPON(MASSTOR_FIRST(GB)) == 1) {
      *ONE = TRUE;
    }
  }
  CGBMISC_ValisReset();
  return CGBMISC_PFLDIPL(GB, DOM, VARL);
}

MASSTOR_LIST CGBMISC_PFIGBA
# ifdef __STDC__
(MASSTOR_LIST PFL, MASSTOR_LIST P, MASSTOR_LIST TF, BOOLEAN *ONE)
# else
(PFL, P, TF, ONE)
MASSTOR_LIST PFL, P, TF;
BOOLEAN *ONE;
# endif
{
  MASSTOR_LIST GB, DOM, VARL;

  *ONE = FALSE;
  P = CGBMISC_XDIPFPF(P, &DOM, &VARL);
  PFL = CGBMISC_DIPLFPFL(PFL, &DOM, &VARL);
  CGBMISC_ValisSet(VARL);
  GB = DIPIGB_DIIGBA(P, PFL, TF);
  CGBMISC_ValisReset();
  if (GB != MASSTOR_SIL) {
    if (DIPI_DIIPON(MASSTOR_FIRST(GB)) == 1) {
      *ONE = TRUE;
    }
  }
  return CGBMISC_PFLDIPL(GB, DOM, VARL);
}

MASSTOR_LIST CGBMISC_PFILS
# ifdef __STDC__
(MASSTOR_LIST B, BOOLEAN *ONE)
# else
(B, ONE)
MASSTOR_LIST B;
BOOLEAN *ONE;
# endif
{
  MASSTOR_LIST DOM, VARL;

  *ONE = FALSE;
  B = CGBMISC_DIPLFPFL(B, &DOM, &VARL);
  CGBMISC_ValisSet(VARL);
  B = CGBMISC_DIILIS(B);
  if (B != MASSTOR_SIL) {
    if (DIPI_DIIPON(MASSTOR_FIRST(B)) == 1) {
      *ONE = TRUE;
    }
  }
  CGBMISC_ValisReset();
  return CGBMISC_PFLDIPL(B, DOM, VARL);
}

MASSTOR_LIST CGBMISC_DIILIS
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL;

  PP = P;
  PS = MASSTOR_BETA;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    DIPI_DIIPCP(PL, &CL, &PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  if (LL <= 1) {
    return PP;
  }
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPIGB_DIIPNF(PP, 0, PL);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_1;
      }
    } else {
      PL = CGBMISC_DIIPNORM(PL);
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_1;
      }
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        DIPI_DIIPCP(PL, &CL, &PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_1;
    }
  } EXIT_1:;
  return PP;
}

MASSTOR_LIST CGBMISC_PFINOR
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST P)
# else
(B, P)
MASSTOR_LIST B, P;
# endif
{
  MASSTOR_LIST NF, DOM, VARL;

  B = CGBMISC_DIPLFPFL(B, &DOM, &VARL);
  CGBMISC_ValisSet(VARL);
  NF = DIPIGB_DIIPNF(B, 0, CGBMISC_XDIPFPF(P, &DOM, &VARL));
  if (NF == 0) {
    CGBMISC_ValisReset();
    return MASSTOR_SIL;
  }
  NF = CGBMISC_DIIPNORM(NF);
  CGBMISC_ValisReset();
  return CGBMISC_XPFDIP(NF, DOM, VARL);
}

MASSTOR_LIST CGBMISC_PFILNOR
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST P, BOOLEAN *ZERO)
# else
(B, P, ZERO)
MASSTOR_LIST B, P;
BOOLEAN *ZERO;
# endif
{
  MASSTOR_LIST RET, NF, p;

  RET = MASSTOR_SIL;
  *ZERO = FALSE;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    NF = CGBMISC_PFINOR(B, p);
    if (NF != MASSTOR_SIL) {
      if (SACLIST_MEMBER(NF, RET) == 0 && !(*CGBMISC_PAR.IsCnst)(NF)) {
        RET = MASSTOR_COMP(NF, RET);
      }
    } else {
      *ZERO = TRUE;
    }
  }
  return MASSTOR_INV(RET);
}

MASSTOR_LIST CGBMISC_PFILDS
# ifdef __STDC__
(MASSTOR_LIST B, BOOLEAN *ONE)
# else
(B, ONE)
MASSTOR_LIST B;
BOOLEAN *ONE;
# endif
{
  MASSTOR_LIST DOM, VARL, L, P, NP, HC, HT, NHC, NHT, C_173_dummy;
  INTEGER I;

  *ONE = FALSE;
  if (B == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  B = CGBMISC_DIPLFPFL(B, &DOM, &VARL);
  L = MASSTOR_LENGTH(B);
  I = 0;
  for (;;) {
    MASSTOR_ADV(B, &P, &B);
    NP = DIPIDGB_DIIPDNF(B, 0, P);
    if (NP == 0) {
      L = L - 1;
    } else {
      NP = DIPI_DIIPAB(NP);
      DIPC_DIPMAD(P, &HC, &HT, &C_173_dummy);
      DIPC_DIPMAD(NP, &NHC, &NHT, &C_173_dummy);
      if (SACLIST_EQUAL(HC, NHC) == 1 && SACLIST_EQUAL(HT, NHT) == 1) {
        if (I > 0) {
          I = I + 1;
        } else {
          I = 1;
        }
      } else {
        I = 0;
      }
      B = SACLIST_CONC(B, MASSTOR_LIST1(NP));
    }
    if (I >= L) {
      goto EXIT_2;
    }
  } EXIT_2:;
  return CGBMISC_PFLDIPL(B, DOM, VARL);
}

MASSTOR_LIST CGBMISC_PFIDNOR
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST P)
# else
(B, P)
MASSTOR_LIST B, P;
# endif
{
  MASSTOR_LIST NF, DOM, VARL;

  B = CGBMISC_DIPLFPFL(B, &DOM, &VARL);
  CGBMISC_ValisSet(VARL);
  NF = DIPIDGB_DIIPDNF(B, 0, CGBMISC_XDIPFPF(P, &DOM, &VARL));
  if (NF == 0) {
    CGBMISC_ValisReset();
    return MASSTOR_SIL;
  }
  NF = DIPI_DIIPAB(NF);
  CGBMISC_ValisReset();
  return CGBMISC_XPFDIP(NF, DOM, VARL);
}

MASSTOR_LIST CGBMISC_PFILDNOR
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST P, BOOLEAN *ZERO)
# else
(B, P, ZERO)
MASSTOR_LIST B, P;
BOOLEAN *ZERO;
# endif
{
  MASSTOR_LIST RET, NF, p;

  RET = MASSTOR_SIL;
  *ZERO = FALSE;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    NF = CGBMISC_PFIDNOR(B, p);
    if (NF != MASSTOR_SIL) {
      if (SACLIST_MEMBER(NF, RET) == 0) {
        RET = MASSTOR_COMP(NF, RET);
      }
    } else {
      *ZERO = TRUE;
    }
  }
  return MASSTOR_INV(RET);
}

void CGBMISC_PFWRITE
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST DOM, VARL;

  P = CGBMISC_XDIPFPF(P, &DOM, &VARL);
  CGBMISC_ValisSet(VARL);
  DIPI_DIIPWR(P, VARL);
  CGBMISC_ValisReset();
}

MASSTOR_LIST CGBMISC_DIIPNORM
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST C, DUMMY;

  DIPI_DIIPCP(P, &C, &DUMMY);
  P = DIPI_DIIPIQ(P, C);
  if (DIPI_DIIPSG(P) == -1) {
    return DIPI_DIIPNG(P);
  } else {
    return P;
  }
}

static MASSTOR_LIST DIP2AD
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST d, MASSTOR_LIST rest)
# else
(P, d, rest)
MASSTOR_LIST P, d, rest;
# endif
{
  MASSTOR_LIST P1, exp, coe;

  P1 = MASSTOR_BETA;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &exp, &P);
    P1 = MASSTOR_COMP(exp, P1);
    MASSTOR_ADV(P, &coe, &P);
    coe = MASSTOR_COMP(d, MASSTOR_COMP(coe, rest));
    P1 = MASSTOR_COMP(coe, P1);
  }
  P1 = MASSTOR_INV(P1);
  return P1;
}

static MASSTOR_LIST AD2DIP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *d, MASSTOR_LIST *rest)
# else
(P, d, rest)
MASSTOR_LIST P;
MASSTOR_LIST *d, *rest;
# endif
{
  MASSTOR_LIST P1, exp, coe, val;

  P1 = MASSTOR_BETA;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &exp, &P);
    P1 = MASSTOR_COMP(exp, P1);
    MASSTOR_ADV(P, &coe, &P);
    SACLIST_ADV2(coe, d, &val, rest);
    P1 = MASSTOR_COMP(val, P1);
  }
  P1 = MASSTOR_INV(P1);
  return P1;
}

static MASSTOR_LIST DIPPFACTAV
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST c, d, dd, ExpPol, f, pol, PP, PV, q, r, VP, rest, RET, s, vlist;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  dd = DIPTOOLS_ADDDFDIP(P);
  if (dd == 0) {
    return MASSTOR_SIL;
  }
  DIPTOOLS_DIPFDIPP(P, ADTOOLS_ADDDFSTR("INT ", 4L), &q, &vlist);
  CGBMISC_ValisSet(vlist);
  q = AD2DIP(q, &d, &rest);
  DIPTOO_DIPVOPP(MASSTOR_LIST1(q), DIPC_VALIS, &PP, &VP, &PV);
  CGBMISC_ValisSet(VP);
  q = MASSTOR_FIRST(PP);
  CGBMISC_EvordSet(DIPC_INVLEX);
  DIPC_DIPBSO(q);
  DIPC_PFDIP(q, &r, &q);
  CGBMISC_EvordReset();
  SACPFAC_IPFAC(r, q, &s, &c, &f);
  RET = MASSTOR_SIL;
  PV = DIPTOO_INVPERM(PV);
  while (f != MASSTOR_SIL) {
    MASSTOR_ADV(f, &ExpPol, &f);
    pol = DIPC_DIPFP(r, SACLIST_SECOND(ExpPol));
    pol = DIPC_DIPERM(pol, PV);
    pol = DIP2AD(pol, d, rest);
    DIPTOOLS_DIPPFDIP(pol, SACLIST_THIRD(dd), dd, &pol, &vlist);
    RET = MASSTOR_COMP(pol, RET);
  }
  CGBMISC_ValisReset();
  CGBMISC_ValisReset();
  return RET;
}

void BEGIN_CGBMISC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_ADTOOLS();
    BEGIN_CGBAPPL();
    BEGIN_CGBDSTR();
    BEGIN_CGBFUNC();
    BEGIN_CGBSYS();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPIDGB();
    BEGIN_DIPIGB();
    BEGIN_DIPTOO();
    BEGIN_DIPTOOLS();
    BEGIN_IO();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_SACLIST();
    BEGIN_SACPFAC();
    BEGIN_SACPOL();

    EVORDSTACK = MASSTOR_SIL;
    MASSTOR_LISTVAR(&EVORDSTACK);
    VALISSTACK = MASSTOR_SIL;
    MASSTOR_LISTVAR(&VALISSTACK);
    MASSTOR_LISTVAR(&CGBMISC_PAR.TermOrderPol);
    MASSTOR_LISTVAR(&CGBMISC_PAR.TermOrderCoef);
    CGBMISC_CGBOPT(SACLIST_CONC(SACLIST_LIST5(1, 1, 0, 0, 0), SACLIST_LIST3(DIPC_IGRLEX, DIPC_IGRLEX, 0)));
  }
}
