#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASSPEC
#include "MASSPEC.h"
#endif

CHAR MASSPEC_rcsid [] = "$Id: MASSPEC.md,v 1.3 1992/10/16 13:53:40 kredel Exp $";
CHAR MASSPEC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static BOOLEAN unwind;
static MASSTOR_LIST C_26_goto;
static CHAR rcsidi [] = "$Id: MASSPEC.mi,v 1.4 1995/11/05 08:58:48 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static MASSTOR_LIST APPLY ARGS((MASSTOR_LIST F, MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST APPLYCOMP ARGS((MASSTOR_LIST F, MASSTOR_LIST C_32_A, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVALSPFORM ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVCOND ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVPROGN ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVWHL ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVRPT ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVLIS ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVASS ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST CONVERT ARGS((MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *ENV));
static MASSTOR_LIST CONVvalue ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST CONVdesc ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVVAR ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVSORT ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVIMPRT ARGS((MASSTOR_LIST X, MASSTOR_LIST SP, MASSTOR_LIST EP, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVUNIT ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVMOD ARGS((MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVAXIOM ARGS((MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVIMPL ARGS((MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVGEN ARGS((MASSTOR_LIST L, MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVSIG ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static BOOLEAN EXTENDVARENV ARGS((MASSTOR_LIST C_28_A, MASSTOR_LIST O, MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST EVPROGA ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static MASSTOR_LIST DEFA ARGS((MASSTOR_LIST X, MASSTOR_LIST *ENV));
static void SETaldesV ARGS((MASSTOR_LIST V, MASSTOR_LIST C_27_A, MASSTOR_LIST *ENV));


static MASSTOR_LIST APPLY
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(F, X, ENV)
MASSTOR_LIST F, X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Y, Z, L, X1, X2, FP, C_33_A, B, EP, ES, I, O, OP;
  BOOLEAN t;

  Z = MASSTOR_SIL;
  if (MASSYM_ELEMP(F)) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "APPLY: invalid function object.", 31L);
    return Z;
  }
  if (MASLISP_trace) {
    MASBIOS_SWRITE("APPLY:  ", 8L);
    MASSYM_UWRITE(MASSTOR_COMP(F, X));
  }
  if (MASSYM2_SYMBOL(F)) {
    X = EVLIS(X, ENV);
    if (F == MASLISP_ADD) {
      MASSTOR_ADV(X, &Z, &XP);
      while (XP != MASSTOR_SIL) {
        MASSTOR_ADV(XP, &X1, &XP);
        Z = Z + X1;
      }
      return Z;
    }
    if (F == MASLISP_SUB) {
      MASSTOR_ADV(X, &Z, &XP);
      if (XP == MASSTOR_SIL) {
        Z = -Z;
        return Z;
      }
      while (XP != MASSTOR_SIL) {
        MASSTOR_ADV(XP, &X1, &XP);
        Z = Z - X1;
      }
      return Z;
    }
    if (F == MASLISP_NEQS) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 != X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_GTS) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 > X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_LTS) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 < X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_LEQ) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 <= X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_GEQ) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 >= X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_EQS) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 == X2) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_MUL) {
      MASSTOR_ADV(X, &Z, &XP);
      while (XP != MASSTOR_SIL) {
        MASSTOR_ADV(XP, &X1, &XP);
        Z = Z * X1;
      }
      return Z;
    }
    if (F == MASLISP_QUOT) {
      MASSTOR_ADV(X, &Z, &XP);
      while (XP != MASSTOR_SIL) {
        MASSTOR_ADV(XP, &X1, &XP);
        Z = Z / X1;
      }
      return Z;
    }
    if (F == MASLISP_REM) {
      MASSTOR_ADV(X, &Z, &XP);
      while (XP != MASSTOR_SIL) {
        MASSTOR_ADV(XP, &X1, &XP);
        Z = Z % X1;
      }
      return Z;
    }
    if (F == MASLISP_NOTS) {
      MASSTOR_ADV(X, &Z, &XP);
      if (Z == MASSTOR_SIL) {
        Z = MASLISP_WT;
      } else {
        Z = MASSTOR_SIL;
      }
      return Z;
    }
    if (F == MASLISP_UND) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 != MASSTOR_SIL && X2 != MASSTOR_SIL) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_ODER) {
      SACLIST_FIRST2(X, &X1, &X2);
      if (X1 != MASSTOR_SIL || X2 != MASSTOR_SIL) {
        Z = MASLISP_WT;
      }
      return Z;
    }
    if (F == MASLISP_RTN) {
      Z = MASSTOR_FIRST(X);
      unwind = TRUE;
      return Z;
    }
    if (F == MASLISP_FEL) {
      EP = SACLIST_LIST2(MASLISP_QUOTE, *ENV);
      EP = MASSTOR_LIST1(EP);
      X = SACLIST_CCONC(X, EP);
      X = MASSTOR_COMP(MASLISP_FELx, X);
      Z = MASSPEC_EVALUATE(X, ENV);
      return Z;
    }
    if (F == MASLISP_FER) {
      EP = SACLIST_LIST2(MASLISP_QUOTE, *ENV);
      EP = MASSTOR_LIST1(EP);
      X = SACLIST_CCONC(X, EP);
      X = MASSTOR_COMP(MASLISP_FERx, X);
      Z = MASSPEC_EVALUATE(X, ENV);
      return Z;
    }
    if (F == MASLISP_CONVVAL) {
      Z = CONVvalue(X, ENV);
      return Z;
    }
    if (F == MASLISP_CONVDES) {
      Z = CONVdesc(X, ENV);
      return Z;
    }
    if (F == MASLISP_GTO) {
      Z = MASSTOR_FIRST(X);
      C_26_goto = Z;
      unwind = TRUE;
      return Z;
    }
    Z = MASSTOR_COMP(F, X);
    return Z;
  }
  MASSTOR_ADV(F, &L, &FP);
  if (L == MASLISP_TINFO) {
    Z = MASSTOR_COMP(F, X);
    return Z;
  }
  if (L == MASLISP_LAMBDA) {
    SACLIST_FIRST2(FP, &C_33_A, &B);
    SACLIST_FIRST2(C_33_A, &I, &O);
    EP = *ENV;
    t = unwind;
    unwind = FALSE;
    if (EXTENDVARENV(I, O, X, &EP)) {
      ES = EP;
      Z = MASSPEC_EVALUATE(B, &EP);
      XP = SACLIST_CINV(X);
      OP = O;
      while (OP != MASSTOR_SIL) {
        OP = MASSTOR_RED(OP);
        MASSTOR_ADV(XP, &X1, &XP);
        ES = MASSTOR_RED(ES);
        MASSTOR_ADV(ES, &X2, &ES);
        MASLISP_SETV(X1, X2, ENV);
      }
    }
    unwind = t;
    return Z;
  }
  if (L == MASLISP_GLAMBDA) {
    X = EVLIS(X, ENV);
    Z = EVGEN(FP, X, ENV);
    SACLIST_FIRST2(Z, &XP, &EP);
    EP = MASLISP_DCENV(EP);
    t = unwind;
    unwind = FALSE;
    Z = MASSPEC_EVALUATE(XP, &EP);
    unwind = t;
    return Z;
  }
  MASSYM_UWRITE(F);
  MASERR_ERROR(MASERR_severe, "APPLY: invalid function object.", 31L);
  return Z;
}

static MASSTOR_LIST APPLYCOMP
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST C_32_A, MASSTOR_LIST *ENV)
# else
(F, C_32_A, ENV)
MASSTOR_LIST F, C_32_A;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST B, Z, I, O, PI, PO, V;
  MASSTOR_LIST b, c, v, i;
  BOOLEAN def, fu;

  Z = MASSTOR_SIL;
  MASLISPU_Signature(F, &I, &O, &def);
  if (!def) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "APPLYCOMP: unbound compiled procedure.", 38L);
    return Z;
  }
  if (O < 0) {
    O = 0;
  }
  if (MASSTOR_LENGTH(C_32_A) < I) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "APPLYCOMP: too few input parameters.", 36L);
    return Z;
  }
  B = C_32_A;
  PI = MASSTOR_SIL;
  i = 1;
  while (i <= I) {
    i = i + 1;
    MASSTOR_ADV(B, &b, &B);
    c = MASSPEC_EVALUATE(b, ENV);
    PI = MASSTOR_COMP(c, PI);
  }
  PI = MASSTOR_INV(PI);
  V = B;
  if (MASSTOR_LENGTH(B) < O) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "APPLYCOMP: too few output parameters.", 37L);
    return Z;
  }
  PO = MASSTOR_SIL;
  i = 1;
  while (i <= O) {
    i = i + 1;
    MASSTOR_ADV(B, &b, &B);
    c = MASSYM2_ASSOC(b, *ENV);
    if (c != MASSTOR_SIL) {
      c = MASSTOR_FIRST(c);
    }
    PO = MASSTOR_COMP(c, PO);
  }
  PO = MASSTOR_INV(PO);
  if (B != MASSTOR_SIL) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "APPLYCOMP: too many parameters.", 31L);
    return Z;
  }
  if (MASLISP_trace) {
    MASBIOS_SWRITE("EXTERN: ", 8L);
    MASSYM_UWRITE(MASSTOR_COMP(F, SACLIST_CCONC(PI, PO)));
  }
  MASLISPU_CallCompiled(F, PI, &PO, &fu);
  if (fu) {
    Z = PO;
    return Z;
  }
  while (PO != MASSTOR_SIL) {
    MASSTOR_ADV(PO, &b, &PO);
    MASSTOR_ADV(V, &v, &V);
    MASLISP_SETV(v, b, ENV);
  }
  return Z;
}

MASSTOR_LIST MASSPEC_EVALUATE
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST F, Y, Z;

  Z = MASSTOR_SIL;
  if (MASSYM_ELEMP(X)) {
    return X;
  }
  if (MASSYM2_SYMBOL(X)) {
    Z = MASSYM2_ASSOC(X, *ENV);
    if (Z == MASSTOR_SIL) {
      Z = X;
    } else {
      MASERR_ERROR(MASERR_spotless, "s c", 3L);
      Z = MASSTOR_FIRST(Z);
      Z = MASSPEC_EVALUATE(Z, ENV);
    }
    return Z;
  }
  if (X > MASSTOR_BETA) {
    MASSTOR_ADV(X, &F, &Y);
    if (MASLISP_LAMBDAP(F)) {
      return X;
    }
    MASERR_ERROR(MASERR_spotless, "s c", 3L);
    F = MASSPEC_EVALUATE(F, ENV);
    if (MASLISP_SPECIALFORM(F)) {
      Z = MASSTOR_COMP(F, Y);
      Z = EVALSPFORM(Z, ENV);
    } else {
      if (MASLISPU_PROCP(F)) {
        Z = APPLYCOMP(F, Y, ENV);
      } else {
        Z = APPLY(F, Y, ENV);
      }
    }
    return Z;
  }
  MASSYM_UWRITE(X);
  MASERR_ERROR(MASERR_severe, "EVALUATE: invalid form.", 23L);
  return Z;
}

static MASSTOR_LIST EVALSPFORM
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST M, XP, F, C_31_A, B, FP, Y, Z, EP, W, T, L;
  BOOLEAN t;

  Z = MASSTOR_SIL;
  MASSTOR_ADV(X, &F, &XP);
  if (MASSYM_ELEMP(F)) {
    MASSYM_UWRITE(F);
    MASERR_ERROR(MASERR_severe, "EVALSPFORM: invalid as function object.", 39L);
    return Z;
  }
  if (MASLISP_trace) {
    MASBIOS_SWRITE("SPFORM: ", 8L);
    MASSYM_UWRITE(X);
  }
  if (MASSYM2_SYMBOL(F)) {
    if (F == MASLISP_ASSIGN) {
      Z = EVASS(XP, ENV);
      return Z;
    }
    if (F == MASLISP_TINFO) {
      return X;
    }
    if (F == MASLISP_PROGN) {
      Z = EVPROGN(XP, ENV);
      return Z;
    }
    if (F == MASLISP_IFS) {
      MASSTOR_ADV(XP, &Z, &XP);
      MASSTOR_ADV(XP, &Y, &XP);
      Z = MASSPEC_EVALUATE(Z, ENV);
      if (Z == MASLISP_WT) {
        Z = MASSPEC_EVALUATE(Y, ENV);
      } else if (XP != MASSTOR_SIL) {
        Z = MASSPEC_EVALUATE(MASSTOR_FIRST(XP), ENV);
      }
      return Z;
    }
    if (F == MASLISP_WHL) {
      Z = EVWHL(XP, ENV);
      return Z;
    }
    if (F == MASLISP_RPT) {
      Z = EVRPT(XP, ENV);
      return Z;
    }
    if (F == MASLISP_QUOTE) {
      Z = MASSTOR_FIRST(XP);
      return Z;
    }
    if (F == MASLISP_STRNG) {
      Z = XP;
      return Z;
    }
    if (F == MASLISP_LISTX) {
      Z = EVLIS(XP, ENV);
      return Z;
    }
    if (F == MASLISP_SETQ) {
      MASSTOR_ADV(XP, &Y, &XP);
      W = MASSTOR_FIRST(XP);
      Z = MASSPEC_EVALUATE(W, ENV);
      MASLISP_SETV(Y, Z, ENV);
      return Z;
    }
    if (F == MASLISP_SETAV) {
      MASSTOR_ADV(XP, &Y, &XP);
      W = MASSTOR_FIRST(XP);
      Z = MASSPEC_EVALUATE(W, ENV);
      SETaldesV(Y, Z, ENV);
      return Z;
    }
    if (F == MASLISP_REP) {
      return X;
    }
    if (F == MASLISP_VARS) {
      Z = EVVAR(XP, ENV);
      return Z;
    }
    if (F == MASLISP_DE) {
      Z = MASLISP_DEFE(XP, ENV);
      return Z;
    }
    if (F == MASLISP_DF) {
      Z = MASLISP_DEFF(XP, ENV);
      return Z;
    }
    if (F == MASLISP_DM) {
      Z = MASLISP_DEFM(XP, ENV);
      return Z;
    }
    if (F == MASLISP_ARY) {
      XP = MASSTOR_FIRST(XP);
      SACLIST_FIRST2(XP, &Y, &W);
      W = EVLIS(W, ENV);
      XP = SACLIST_LIST2(Y, W);
      Z = MASSYM_GENARRAY(XP);
      Z = MASSPEC_EVALUATE(Z, ENV);
      return Z;
    }
    if (F == MASLISP_SPEC) {
      Z = MASLISP_DSPEC(XP, ENV);
      return Z;
    }
    if (F == MASLISP_IMPL) {
      Z = MASLISP_DMIA(X, ENV);
      return Z;
    }
    if (F == MASLISP_MODEL) {
      Z = MASLISP_DMIA(X, ENV);
      return Z;
    }
    if (F == MASLISP_AXIOM) {
      Z = MASLISP_DMIA(X, ENV);
      return Z;
    }
    if (F == MASLISP_EXPOS) {
      Z = EVUNIT(XP, ENV);
      return Z;
    }
    if (F == MASLISP_UNIT) {
      return X;
    }
    if (F == MASLISP_COND) {
      Z = EVCOND(XP, ENV);
      return Z;
    }
    if (F == MASLISP_PROGA) {
      Z = EVPROGA(XP, ENV);
      return Z;
    }
    if (F == MASLISP_LBEL) {
      Z = MASSTOR_FIRST(XP);
      return Z;
    }
    if (F == MASLISP_SCHLUSS || F == MASLISP_schluss) {
      return F;
    }
    Z = X;
    return Z;
  }
  MASSTOR_ADV(F, &L, &FP);
  if (L == MASLISP_MLAMBDA) {
    SACLIST_FIRST2(FP, &C_31_A, &B);
    XP = MASSTOR_LIST1(SACLIST_LIST2(MASLISP_QUOTE, X));
    EP = *ENV;
    t = unwind;
    unwind = FALSE;
    if (MASLISP_EXTENDENV(C_31_A, XP, &EP)) {
      Z = MASSPEC_EVALUATE(B, &EP);
      Z = MASSPEC_EVALUATE(Z, &EP);
    }
    unwind = t;
    return Z;
  }
  if (L == MASLISP_FLAMBDA) {
    SACLIST_FIRST2(FP, &C_31_A, &B);
    XP = MASSTOR_LIST1(SACLIST_LIST2(MASLISP_QUOTE, XP));
    EP = *ENV;
    t = unwind;
    unwind = FALSE;
    if (MASLISP_EXTENDENV(C_31_A, XP, &EP)) {
      Z = MASSPEC_EVALUATE(B, &EP);
    }
    unwind = t;
    return Z;
  }
  MASSYM_UWRITE(F);
  MASERR_ERROR(MASERR_severe, "EVALSPFORM: unknown function.", 29L);
  return Z;
}

static MASSTOR_LIST EVCOND
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Y, Z, C, D;

  Z = MASSTOR_SIL;
  XP = X;
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &Y, &XP);
    MASSTOR_ADV(Y, &C, &D);
    C = MASSPEC_EVALUATE(C, ENV);
    if (C != MASSTOR_SIL) {
      Z = EVPROGN(D, ENV);
      return Z;
    }
  }
  return Z;
}

static MASSTOR_LIST EVPROGN
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Z, Y;

  Z = MASSTOR_SIL;
  XP = X;
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &Y, &XP);
    Z = MASSPEC_EVALUATE(Y, ENV);
    if (unwind) {
      return Z;
    }
  }
  return Z;
}

static MASSTOR_LIST EVWHL
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST C, B, Z;

  C = MASSTOR_FIRST(X);
  B = SACLIST_SECOND(X);
  Z = MASSTOR_SIL;
  while (MASSPEC_EVALUATE(C, ENV) != MASSTOR_SIL) {
    Z = MASSPEC_EVALUATE(B, ENV);
    if (unwind) {
      return Z;
    }
  }
  return Z;
}

static MASSTOR_LIST EVRPT
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST C, B, Z;

  B = MASSTOR_FIRST(X);
  C = SACLIST_SECOND(X);
  do {
    Z = MASSPEC_EVALUATE(B, ENV);
    if (unwind) {
      return Z;
    }
  } while (!(MASSPEC_EVALUATE(C, ENV) != MASSTOR_SIL));
  return Z;
}

static MASSTOR_LIST EVLIS
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Y, Z;

  Z = MASSTOR_SIL;
  XP = X;
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &Y, &XP);
    Y = MASSPEC_EVALUATE(Y, ENV);
    Z = MASSTOR_COMP(Y, Z);
  }
  Y = MASSTOR_INV(Z);
  return Y;
}

static MASSTOR_LIST EVASS
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Z, Y, T, TP, W;
  BOOLEAN nofu;

  MASSTOR_ADV(X, &Y, &XP);
  W = MASSTOR_FIRST(XP);
  nofu = TRUE;
  if (!MASSYM_ATOM(W)) {
    if (MASSTOR_FIRST(W) == MASLISP_STRNG) {
      T = MASSYM2_GET(Y, MASLISP_TDEF);
      if (T != MASSTOR_SIL) {
        TP = MASSTOR_FIRST(T);
      } else {
        TP = MASSTOR_SIL;
      }
      if (TP != MASSTOR_SIL && TP != MASLISP_LISTX && TP != MASLISP_STRNG && TP != MASLISP_ANY) {
        Z = CONVERT(T, MASLISP_READ, W, ENV);
        MASLISP_SETV(Y, Z, ENV);
        return Z;
      }
    } else {
      nofu = FALSE;
    }
  }
  if (MASLISP_stricttyping && nofu) {
    MASSYM_UWRITE(Y);
    MASERR_ERROR(MASERR_severe, "EVASS: no type information available.", 37L);
    return MASSTOR_SIL;
  }
  Z = MASSPEC_EVALUATE(W, ENV);
  MASLISP_SETV(Y, Z, ENV);
  return Z;
}

static MASSTOR_LIST CONVERT
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *ENV)
# else
(T, P, S, ENV)
MASSTOR_LIST T, P, S;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST x, D, Z, TP, W, L, F, C_30_A, EP;

  Z = MASSTOR_SIL;
  F = MASSTOR_SIL;
  if (MASSYM_ELEMP(T)) {
    MASSYM_UWRITE(T);
    MASERR_ERROR(MASERR_severe, "CONVERT: invalid as type.", 25L);
    return Z;
  }
  TP = MASLISP_TAG(MASSTOR_SIL, T);
  TP = MASSTOR_LIST1(TP);
  L = MASSYM2_ASSOC(P, *ENV);
  if (L != MASSTOR_SIL) {
    L = MASSTOR_FIRST(L);
  }
  if (L != MASSTOR_SIL) {
    L = MASSTOR_RED(L);
  }
  W = EVGEN(L, TP, ENV);
  SACLIST_FIRST2(W, &W, &EP);
  EP = MASLISP_DCENV(EP);
  if (MASSTOR_FIRST(W) == MASLISP_QUOTE) {
    MASSYM_UWRITE(T);
    MASERR_ERROR(MASERR_severe, "CONVERT: unbound generic procedure for signature.", 49L);
    return Z;
  }
  C_30_A = S;
  if (MASSTOR_FIRST(C_30_A) == MASLISP_STRNG) {
    C_30_A = MASSTOR_RED(C_30_A);
  }
  C_30_A = SACLIST_CCONC(C_30_A, MASBIOS_LISTS(" ", 1L));
  MASBIOSU_CLTIS(C_30_A);
  Z = MASSPEC_EVALUATE(W, &EP);
  return Z;
}

static MASSTOR_LIST CONVvalue
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST TP, T, S;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  SACLIST_FIRST2(X, &T, &S);
  TP = CONVERT(T, MASLISP_READ, S, ENV);
  return TP;
}

static MASSTOR_LIST CONVdesc
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST TP, T, S;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  SACLIST_FIRST2(X, &T, &S);
  TP = CONVERT(SACLIST_LIST2(T, MASSTOR_SIL), MASLISP_DECREAD, S, ENV);
  TP = MASLISP_VALOFTAG(TP);
  return TP;
}

static MASSTOR_LIST EVVAR
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, XPP, Y, T, TS, S, V, v, vd, Z, n, i, s;
  BOOLEAN t;

  Z = MASSTOR_SIL;
  SACLIST_FIRST2(X, &XP, &T);
  T = MASSPEC_EVALUATE(T, ENV);
  TS = T;
  if (!MASSYM2_SYMBOL(TS)) {
    TS = MASSTOR_FIRST(TS);
  }
  V = MASSTOR_SIL;
  XPP = MASSTOR_SIL;
  v = SACLIST_LIST2(MASLISP_DEFAULT, T);
  v = MASSPEC_EVALUATE(v, ENV);
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &Y, &XP);
    if (!MASSYM_ATOM(Y)) {
      if (MASSYM2_SYMBOL(Y)) {
        MASSYM2_PUT(Y, MASLISP_TDEF, T);
        V = MASSTOR_COMP(v, V);
        XPP = MASSTOR_COMP(Y, XPP);
      } else if (MASSTOR_FIRST(Y) == MASLISP_ARY) {
        Y = SACLIST_SECOND(Y);
        SACLIST_FIRST2(Y, &n, &i);
        i = EVLIS(i, ENV);
        s = SACLIST_LIST2(n, i);
        s = MASSYM_ARRAYDEC(s);
        while (s != MASSTOR_SIL) {
          MASSTOR_ADV(s, &Y, &s);
          MASSYM2_PUT(Y, MASLISP_TDEF, T);
          V = MASSTOR_COMP(v, V);
          XPP = MASSTOR_COMP(Y, XPP);
        }
      } else {
        MASSYM_UWRITE(T);
        MASERR_ERROR(MASERR_severe, "EVVAR: invalid as variable.", 27L);
      }
    }
  }
  V = MASSTOR_INV(V);
  XPP = MASSTOR_INV(XPP);
  t = MASLISP_EXTENDENV(XPP, V, ENV);
  return TS;
}

static MASSTOR_LIST EVSORT
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Z, Y;

  Z = MASSTOR_SIL;
  XP = X;
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &Y, &XP);
    Y = MASSPEC_EVALUATE(Y, ENV);
    if (MASSYM2_SYMBOL(Y)) {
      MASSYM2_PUT(Y, MASLISP_SORT, MASLISP_WT);
    } else {
      MASSYM_UWRITE(Y);
      MASERR_ERROR(MASERR_severe, "EVSORT: invalid as sort name.", 29L);
    }
  }
  return MASSTOR_SIL;
}

static MASSTOR_LIST EVIMPRT
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST SP, MASSTOR_LIST EP, MASSTOR_LIST *ENV)
# else
(X, SP, EP, ENV)
MASSTOR_LIST X, SP, EP;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST P, F, FP, XP, Z, N, V, U, UP, D, S, ES;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(X, &N, &S);
  MASSTOR_ADV(N, &N, &P);
  Z = MASSTOR_SIL;
  P = MASSTOR_FIRST(P);
  P = EVLIS(P, ENV);
  if (S != MASSTOR_SIL) {
    S = MASSTOR_FIRST(S);
  }
  if (!MASSYM2_SYMBOL(N)) {
    MASSYM_UWRITE(N);
    MASERR_ERROR(MASERR_severe, "EVIMPRT: invalid as name.", 25L);
    return MASSTOR_SIL;
  }
  D = MASSPEC_EVALUATE(N, ENV);
  if (MASSYM2_SYMBOL(D)) {
    D = MASSPEC_EVALUATE(D, &EP);
  }
  if (D == MASSTOR_SIL) {
    MASSYM_UWRITE(N);
    MASSYM_UWRITE(D);
    MASERR_ERROR(MASERR_severe, "EVIMPRT: unknown unit.", 22L);
    return MASSTOR_SIL;
  }
  if (MASSTOR_FIRST(D) != MASLISP_UNIT) {
    MASSYM_UWRITE(N);
    MASSYM_UWRITE(D);
    MASERR_ERROR(MASERR_severe, "EVIMPRT: unknown unit.", 22L);
    return MASSTOR_SIL;
  }
  D = SACLIST_RED2(D);
  SACLIST_FIRST2(D, &F, &D);
  ES = *ENV;
  if (MASLISP_EXTENDENV(F, P, &ES)) {
  }
  S = SACLIST_CCONC(SP, S);
  if (S != MASSTOR_SIL) {
    D = MASSYM2_SUBLIS(S, D);
  }
  if (MASLISP_trace) {
    MASBIOS_SWRITE("SPEC: ", 6L);
    MASSYM_UWRITE(D);
  }
  XP = SACLIST_RED2(D);
  MASSTOR_ADV(XP, &FP, &XP);
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &U, &XP);
    if (!MASSYM_ATOM(U)) {
      MASSTOR_ADV(U, &UP, &V);
      if (UP == MASLISP_IMPRT) {
        V = EVIMPRT(V, S, EP, &ES);
        Z = SACLIST_CONC(SACLIST_CINV(V), Z);
      } else if (UP == MASLISP_SORT) {
        V = EVSORT(V, &ES);
      } else if (UP == MASLISP_SIG) {
        V = EVSIG(V, &ES);
        Z = MASSTOR_COMP(V, Z);
      } else {
        MASSYM_UWRITE(UP);
        MASERR_ERROR(MASERR_severe, "EVIMPRT: unknown function.", 26L);
      }
    } else {
      MASSYM_UWRITE(U);
      MASERR_ERROR(MASERR_severe, "EVIMPRT: atom invalid as function.", 34L);
    }
  }
  Z = MASSTOR_INV(Z);
  return Z;
}

static MASSTOR_LIST EVUNIT
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST ZP, F, P, YP, EP, DS, D, XP, Z, Y, XPP, U, UP, V, g, DP, n, d, dp, l;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(X, &ZP, &XP);
  MASSTOR_ADV(ZP, &Z, &XP);
  P = MASSTOR_FIRST(XP);
  P = EVLIS(P, ENV);
  if (!MASSYM2_SYMBOL(Z)) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVUNIT: invalid as unit name.", 29L);
    return Z;
  }
  YP = MASSYM2_ASSOC(Z, *ENV);
  if (YP == MASSTOR_SIL) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVUNIT: no unit defined.", 24L);
    return Z;
  }
  YP = MASSTOR_FIRST(YP);
  if (MASSTOR_FIRST(YP) != MASLISP_UNIT) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVUNIT: no unit defined.", 24L);
    return Z;
  }
  XP = SACLIST_RED2(YP);
  MASSTOR_ADV(XP, &F, &XP);
  MASSTOR_ADV(XP, &U, &XP);
  if (MASSYM_ATOM(U)) {
    MASSYM_UWRITE(U);
    MASERR_ERROR(MASERR_severe, "EVUNIT: atom invalid as specification.", 38L);
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(U, &UP, &V);
  if (UP != MASLISP_SPEC) {
    MASSYM_UWRITE(UP);
    MASERR_ERROR(MASERR_severe, "EVUNIT: no specification defined.", 33L);
    return MASSTOR_SIL;
  }
  EP = MASSTOR_SIL;
  if (MASLISP_EXTENDENV(F, P, &EP)) {
  }
  D = SACLIST_LIST2(ZP, MASSTOR_SIL);
  DP = EVIMPRT(D, MASSTOR_SIL, *ENV, &EP);
  DS = DP;
  MASLISP_COPYTOENV(DS, *ENV, &EP);
  g = SACLIST_LIST3(MASSTOR_SIL, MASSTOR_SIL, MASSTOR_SIL);
  while (DP != MASSTOR_SIL) {
    MASSTOR_ADV(DP, &n, &DP);
    d = MASSYM2_ASSOC(n, EP);
    if (d == MASSTOR_SIL) {
      l = MASSYM2_GET(n, MASLISPU_EXTYP);
      if (l == MASSTOR_SIL || l == MASLISP_GENERIC) {
        d = SACLIST_COMP2(MASLISP_GLAMBDA, n, g);
        dp = d;
        MASSYM2_PUT(n, MASLISPU_EXTYP, MASLISP_GENERIC);
      }
    } else {
      dp = MASSTOR_FIRST(d);
    }
    if (d != MASSTOR_SIL) {
      MASLISP_SETV(n, dp, &EP);
    }
  }
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &U, &XP);
    if (!MASSYM_ATOM(U)) {
      MASSTOR_ADV(U, &UP, &V);
      if (UP == MASLISP_MODEL) {
        V = EVMOD(V, *ENV, &EP);
      } else if (UP == MASLISP_IMPL) {
        V = EVIMPL(V, *ENV, &EP);
      } else if (UP == MASLISP_AXIOM) {
        V = EVAXIOM(V, *ENV, &EP);
      } else {
        MASSYM_UWRITE(UP);
        MASERR_ERROR(MASERR_severe, "EVUNIT: unknown function.", 25L);
      }
    } else {
      MASSYM_UWRITE(U);
      MASERR_ERROR(MASERR_severe, "EVUNIT: atom invalid as function.", 33L);
    }
  }
  MASLISP_COPYTOENV(DS, EP, ENV);
  return Z;
}

static MASSTOR_LIST EVMOD
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV)
# else
(X, EP, ENV)
MASSTOR_LIST X, EP;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST D, XP, Z, Y, XPP, U, UP, V, g, DP, n, d, l;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(X, &Z, &XP);
  if (!MASSYM2_SYMBOL(Z)) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVMOD: invalid as model name.", 29L);
    return Z;
  }
  XP = MASSTOR_RED(XP);
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &U, &XP);
    if (!MASSYM_ATOM(U)) {
      MASSTOR_ADV(U, &UP, &V);
      if (UP == MASLISP_IMPRT) {
        V = EVIMPRT(V, MASSTOR_SIL, EP, ENV);
        MASLISP_COPYTOENV(V, EP, ENV);
      } else if (UP == MASLISP_SORT) {
        V = EVSORT(V, ENV);
      } else if (UP == MASLISP_MAP) {
        V = MASLISP_DEFMAP(V, ENV);
      } else {
        MASSYM_UWRITE(UP);
        MASERR_ERROR(MASERR_severe, "EVMOD: unknown function.", 24L);
      }
    } else {
      MASSYM_UWRITE(U);
      MASERR_ERROR(MASERR_severe, "EVMOD: atom invalid as function.", 32L);
    }
  }
  return Z;
}

static MASSTOR_LIST EVAXIOM
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV)
# else
(X, EP, ENV)
MASSTOR_LIST X, EP;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST g, n, d, l, DP, D, XP, Z, Y, XPP, U, UP, V;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(X, &Z, &XP);
  if (!MASSYM2_SYMBOL(Z)) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVMOD: invalid as axioms name.", 30L);
    return Z;
  }
  XP = MASSTOR_RED(XP);
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &U, &XP);
    if (!MASSYM_ATOM(U)) {
      MASSTOR_ADV(U, &UP, &V);
      if (UP == MASLISP_IMPRT) {
        V = EVIMPRT(V, MASSTOR_SIL, EP, ENV);
        MASLISP_COPYTOENV(V, EP, ENV);
      } else if (UP == MASLISP_SORT) {
        V = EVSORT(V, ENV);
      } else if (UP == MASLISP_RULE) {
        V = MASLISP_DEFRULE(V, ENV);
      } else {
        MASSYM_UWRITE(UP);
        MASERR_ERROR(MASERR_severe, "EVAXIOM: unknown function.", 26L);
      }
    } else {
      MASSYM_UWRITE(U);
      MASERR_ERROR(MASERR_severe, "EVAXIOM: atom invalid as function.", 34L);
    }
  }
  return Z;
}

static MASSTOR_LIST EVIMPL
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST EP, MASSTOR_LIST *ENV)
# else
(X, EP, ENV)
MASSTOR_LIST X, EP;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST D, XP, Z, Y, XPP, U, UP, V, g, DP, n, d, l;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  MASSTOR_ADV(X, &Z, &XP);
  if (!MASSYM2_SYMBOL(Z)) {
    MASSYM_UWRITE(Z);
    MASERR_ERROR(MASERR_severe, "EVMOD: invalid as implementation name.", 38L);
    return Z;
  }
  XP = MASSTOR_RED(XP);
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &U, &XP);
    if (!MASSYM_ATOM(U)) {
      MASSTOR_ADV(U, &UP, &V);
      if (UP == MASLISP_IMPRT) {
        V = EVIMPRT(V, MASSTOR_SIL, EP, ENV);
        MASLISP_COPYTOENV(V, EP, ENV);
      } else if (UP == MASLISP_SORT) {
        V = EVSORT(V, ENV);
      } else if (UP == MASLISP_VARS) {
        V = EVVAR(V, ENV);
      } else if (UP == MASLISP_DE) {
        V = MASLISP_DEFPROC(V, ENV);
      } else {
        V = MASSPEC_EVALUATE(U, ENV);
      }
    } else {
      MASSYM_UWRITE(U);
      MASERR_ERROR(MASERR_severe, "EVIMPL: atom invalid as function.", 33L);
    }
  }
  return Z;
}

static MASSTOR_LIST EVGEN
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(L, X, ENV)
MASSTOR_LIST L, X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST V, T, C_29_A, Y, Z, W, C, XS, XP, EP, D, N, M, I, E, LH, RH, S;

  Z = MASSTOR_SIL;
  SACLIST_FIRST4(L, &N, &M, &I, &E);
  if (M != MASSTOR_SIL) {
    if (MASLISP_trace) {
      MASBIOS_SWRITE("parms: ", 7L);
      MASSYM_UWRITE(X);
    }
    C_29_A = MASLISP_TYPEOF(X);
    SACLIST_FIRST3(C_29_A, &V, &T, &D);
    if (MASLISP_trace) {
      MASBIOS_SWRITE("typeof: ", 8L);
      MASSYM_UWRITE(C_29_A);
    }
    W = MASSYM2_ASSOCQ(T, M);
    if (MASLISP_trace) {
      MASBIOS_SWRITE("assoc: ", 7L);
      MASSYM_UWRITE(W);
    }
    if (W != MASSTOR_SIL) {
      W = MASSTOR_FIRST(W);
      if (MASLISP_trace) {
        MASBIOS_SWRITE("MAP: ", 5L);
        MASSYM_UWRITE(W);
      }
      MASSTOR_ADV(W, &W, &C);
      Z = MASLISP_WT;
      if (C != MASSTOR_SIL) {
        C = MASSTOR_FIRST(C);
        MASSTOR_ADV(C, &Y, &XP);
        XP = MASSTOR_FIRST(XP);
        XS = MASLISP_GENPL(XP, V, T, D);
        Z = MASSTOR_COMP(Y, XS);
        Z = MASSPEC_EVALUATE(Z, ENV);
      }
      if (Z != MASSTOR_SIL) {
        MASSTOR_ADV(W, &Y, &XP);
        XP = MASSTOR_FIRST(XP);
        XS = MASLISP_GENPL(XP, V, T, D);
        Z = MASSTOR_COMP(Y, XS);
        if (D != MASSTOR_SIL) {
          D = MASSTOR_FIRST(D);
        }
        Z = MASLISP_GENTE(Z, Y, D);
        Z = SACLIST_LIST2(Z, MASLISP_ECENV(*ENV));
        return Z;
      }
    }
  }
  if (I != MASSTOR_SIL) {
    SACLIST_FIRST2(I, &XP, &EP);
    Z = MASSTOR_COMP(XP, X);
    Z = SACLIST_LIST2(Z, EP);
    return Z;
  }
  if (E != MASSTOR_SIL) {
    Z = MASSTOR_COMP(N, X);
    while (E != MASSTOR_SIL) {
      MASSTOR_ADV(E, &XP, &E);
      SACLIST_ADV2(XP, &LH, &RH, &XP);
      S = MASSTOR_SIL;
      if (MASSYM_UNIFY(Z, LH, &S)) {
        T = MASLISP_WT;
        if (MASLISP_trace) {
          MASBIOS_SWRITE("UNIFY: ", 7L);
          MASSYM_UWRITE(RH);
        }
        if (XP != MASSTOR_SIL) {
          XP = MASSTOR_FIRST(XP);
          XP = MASSYM2_SUBLIS(S, XP);
          T = MASSPEC_EVALUATE(XP, ENV);
        }
        if (T != MASSTOR_SIL) {
          Z = MASSYM2_SUBLIS(S, RH);
          Z = SACLIST_LIST2(Z, MASLISP_ECENV(*ENV));
          return Z;
        }
      }
    }
  }
  Z = MASSTOR_COMP(N, X);
  Z = SACLIST_LIST2(MASLISP_QUOTE, Z);
  Z = SACLIST_LIST2(Z, MASLISP_ECENV(*ENV));
  return Z;
}

static MASSTOR_LIST EVSIG
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Y, S, T, YP;

  SACLIST_ADV2(X, &Y, &S, &XP);
  T = MASSTOR_FIRST(XP);
  YP = MASSYM2_ASSOC(Y, *ENV);
  if (YP != MASSTOR_SIL) {
    YP = MASSTOR_FIRST(YP);
  }
  if (MASSYM2_SYMBOL(YP)) {
    Y = YP;
  }
  if (!MASSYM2_SYMBOL(Y)) {
    MASSYM_UWRITE(Y);
    MASERR_ERROR(MASERR_severe, "EVSIG: invalid as function name.", 32L);
    return MASSTOR_SIL;
  }
  if (MASSYM2_SYMBOL(S)) {
    S = MASSTOR_LIST1(S);
  }
  S = EVLIS(S, ENV);
  if (MASSYM2_SYMBOL(T)) {
    T = MASSTOR_LIST1(T);
  }
  T = EVLIS(T, ENV);
  XP = SACLIST_LIST3(S, Y, T);
  MASSYM2_PUT(Y, MASLISP_ARROW, XP);
  return Y;
}

static BOOLEAN EXTENDVARENV
# ifdef __STDC__
(MASSTOR_LIST C_28_A, MASSTOR_LIST O, MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(C_28_A, O, X, ENV)
MASSTOR_LIST C_28_A, O, X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, AP, OP, Y, Z, B;

  Z = *ENV;
  XP = X;
  AP = C_28_A;
  OP = O;
  while (AP != MASSTOR_SIL && XP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &B, &AP);
    MASSTOR_ADV(XP, &Y, &XP);
    Y = MASSPEC_EVALUATE(Y, ENV);
    Z = SACLIST_COMP2(B, Y, Z);
  }
  while (OP != MASSTOR_SIL && XP != MASSTOR_SIL) {
    MASSTOR_ADV(OP, &B, &OP);
    MASSTOR_ADV(XP, &Y, &XP);
    Z = SACLIST_COMP2(B, Y, Z);
  }
  if (AP != MASSTOR_SIL || OP != MASSTOR_SIL || XP != MASSTOR_SIL) {
    MASSYM_UWRITE(AP);
    MASSYM_UWRITE(OP);
    MASSYM_UWRITE(XP);
    MASERR_ERROR(MASERR_severe, "EXTENDVARENV: argument number mismatch.", 39L);
    return FALSE;
  }
  *ENV = Z;
  return TRUE;
}

static MASSTOR_LIST EVPROGA
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST XP, Z, L;

  Z = MASSTOR_SIL;
  XP = X;
  for (;;) {
    C_26_goto = MASSTOR_SIL;
    Z = EVPROGN(XP, ENV);
    if (C_26_goto == MASSTOR_SIL) {
      return Z;
    }
    unwind = FALSE;
    XP = X;
    for (;;) {
      if (XP == MASSTOR_SIL) {
        goto EXIT_2;
      }
      MASSTOR_ADV(XP, &L, &XP);
      if (!MASSYM_ATOM(L)) {
        if (MASSTOR_FIRST(L) == MASLISP_LBEL) {
          if (SACLIST_SECOND(L) == C_26_goto) {
            goto EXIT_2;
          }
        }
      }
    } EXIT_2:;
    if (XP == MASSTOR_SIL) {
      MASBIOS_SWRITE("Goto ", 5L);
      MASSYM_UWRITE(C_26_goto);
      MASBIOS_BLINES(0);
      MASERR_ERROR(MASERR_severe, "Undefined step number.", 22L);
      goto EXIT_1;
    }
  } EXIT_1:;
  return Z;
}

static MASSTOR_LIST DEFA
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST *ENV)
# else
(X, ENV)
MASSTOR_LIST X;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST x, s, a, n, i, Y;

  if (X == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  a = MASSTOR_LIST1(MASLISP_ANY);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &x, &X);
    SACLIST_FIRST2(x, &n, &i);
    i = EVLIS(i, ENV);
    x = SACLIST_LIST2(n, i);
    s = MASSYM_ARRAYDEC(x);
    s = MASSTOR_COMP(s, a);
    Y = EVVAR(s, ENV);
  }
  return Y;
}

static void SETaldesV
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST C_27_A, MASSTOR_LIST *ENV)
# else
(V, C_27_A, ENV)
MASSTOR_LIST V, C_27_A;
MASSTOR_LIST *ENV;
# endif
{
  MASSTOR_LIST EP, Z, t, n;

  if (!MASSYM2_SYMBOL(V)) {
    if (!MASSYM_ATOM(V)) {
      if (MASSTOR_FIRST(V) == MASLISP_ARY) {
        SACLIST_FIRST2(SACLIST_SECOND(V), &n, &t);
        t = EVLIS(t, ENV);
        t = SACLIST_LIST2(n, t);
        V = MASSYM_GENARRAY(t);
      }
    }
    if (!MASSYM2_SYMBOL(V)) {
      MASSYM_UWRIT1(V);
      MASBIOS_SWRITE(":=", 2L);
      MASSYM_UWRITE(C_27_A);
      MASERR_ERROR(MASERR_severe, "SETV: invalid as variable.", 26L);
      return;
    }
  }
  MASLISP_SETV(V, C_27_A, ENV);
}

void BEGIN_MASSPEC()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();

  }
}
