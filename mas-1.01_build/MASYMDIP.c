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

#ifndef DEFINITION_SACSET
#include "SACSET.h"
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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASAPF
#include "MASAPF.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

#ifndef DEFINITION_MASYMDIP
#include "MASYMDIP.h"
#endif

CHAR MASYMDIP_rcsid [] = "$Id: MASYMDIP.md,v 1.3 1992/10/16 14:23:29 kredel Exp $";
CHAR MASYMDIP_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASYMDIP.mi,v 1.7 1995/11/04 22:14:42 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1995 Universitaet Passau";
static MASSTOR_LIST dirlwr ARGS((MASSTOR_LIST a, MASSTOR_LIST b, MASSTOR_LIST c));
static MASSTOR_LIST pdread ARGS(());
static MASSTOR_LIST preadd ARGS((MASSTOR_LIST D));
static MASSTOR_LIST pread ARGS(());
static MASSTOR_LIST preadi ARGS(());
static void pdwrite ARGS((MASSTOR_LIST D));
static void pwrite ARGS((MASSTOR_LIST P));
static void pwritei ARGS((MASSTOR_LIST P));
static void pwrited ARGS((MASSTOR_LIST D, MASSTOR_LIST P));
static MASSTOR_LIST TERM ARGS((MASSTOR_LIST P));
static void mkpoly ARGS(());


static MASSTOR_LIST dirlwr
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST b, MASSTOR_LIST c)
# else
(a, b, c)
MASSTOR_LIST a, b, c;
# endif
{
  DIPRN_DIRLWR(a, b, c);
  return c;
}

static MASSTOR_LIST pdread
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, T, V, E, Q, r, X;

  P = MASSTOR_SIL;
  do {
    V = SACPOL_VLREAD();
    MASBIOS_BLINES(1);
  } while (!(V != MASSTOR_SIL));
  DIPC_VALIS = V;
  do {
    E = MASBIOS_CREADB();
    MASBIOS_BLINES(1);
  } while (!(E == MASBIOS_MASORD('(') || E == MASBIOS_MASORD('L') || E == MASBIOS_MASORD('G')));
  if (E == MASBIOS_MASORD('L')) {
    DIPC_EVORD = DIPC_INVLEX;
  }
  if (E == MASBIOS_MASORD('G')) {
    DIPC_EVORD = DIPC_IGRLEX;
  }
  if (E == MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
    T = MASSTOR_LIST1(MASSTOR_LIST1(MASBIOS_MASORD('T')));
    X = DIPC_EVORD;
    DIPC_EVORD = DIPC_INVLEX;
    P = DIPRN_DIRLRD(T);
    P = DIPI_DIILFRCD(P);
    DIPC_PLFDIL(P, &r, &Q);
    DIPC_EVORD = X;
    if (MASSTOR_LENGTH(Q) != MASSTOR_LENGTH(V)) {
      MASBIOS_SWRITE("Wrong number of polynomials.", 28L);
      MASBIOS_BLINES(0);
    } else {
      if (DIPTOO_LFCHECK(Q, 1)) {
        DIPC_EVORD = MASSTOR_INV(Q);
      }
    }
  }
  return MASSTOR_COMP(V, MASSTOR_LIST1(DIPC_EVORD));
}

static MASSTOR_LIST preadd
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST P, V;

  P = MASSTOR_SIL;
  V = MASSTOR_FIRST(D);
  do {
    P = DIPRN_DIRLRD(V);
  } while (!(P != MASSTOR_SIL));
  return P;
}

static MASSTOR_LIST pread
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, V, X;

  P = MASSTOR_SIL;
  X = pdread();
  V = MASSTOR_FIRST(X);
  do {
    MASBIOS_SWRITE("Enter polynomial list: ", 23L);
    P = DIPRN_DIRLRD(V);
    MASBIOS_BLINES(0);
  } while (!(P != MASSTOR_SIL));
  return P;
}

static MASSTOR_LIST preadi
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST P, V, X;

  P = MASSTOR_SIL;
  X = pdread();
  V = MASSTOR_FIRST(X);
  do {
    MASBIOS_SWRITE("Enter polynomial list: ", 23L);
    P = DIPI_DIILRD(V);
    MASBIOS_BLINES(0);
  } while (!(P != MASSTOR_SIL));
  return P;
}

static void pdwrite
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST V, E, L, T, X;

  MASSTOR_ADV(D, &V, &E);
  E = MASSTOR_FIRST(E);
  MASBIOS_SWRITE("Polynomial in the variables: ", 29L);
  SACPOL_VLWRIT(V);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Term ordering: ", 15L);
  DIPC_EVOWRITE(E);
  MASBIOS_BLINES(1);
}

static void pwrite
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST D, L, T, X;

  D = MASSTOR_COMP(DIPC_VALIS, MASSTOR_LIST1(DIPC_EVORD));
  pdwrite(D);
  MASBIOS_SWRITE("Polynomial list: ", 17L);
  DIPRN_DIRLWR(P, DIPC_VALIS, -1);
  MASBIOS_BLINES(1);
}

static void pwritei
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST D, L, T, X;

  D = MASSTOR_COMP(DIPC_VALIS, MASSTOR_LIST1(DIPC_EVORD));
  pdwrite(D);
  MASBIOS_SWRITE("Polynomial list: ", 17L);
  DIPI_DIILWR(P, DIPC_VALIS);
  MASBIOS_BLINES(1);
}

static void pwrited
# ifdef __STDC__
(MASSTOR_LIST D, MASSTOR_LIST P)
# else
(D, P)
MASSTOR_LIST D, P;
# endif
{
  MASSTOR_LIST V;

  V = MASSTOR_FIRST(D);
  DIPRN_DIRLWR(P, V, -1);
  MASBIOS_BLINES(0);
}

MASSTOR_LIST MASYMDIP_DIPVDEF
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST VP, v;

  VP = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &v, &V);
    if (v != MASSTOR_SIL) {
      if (MASSTOR_FIRST(v) >= MASSTOR_SIL) {
        v = MASSTOR_RED(v);
      }
    }
    VP = MASSTOR_COMP(v, VP);
  }
  VP = MASSTOR_INV(VP);
  DIPC_VALIS = VP;
  return VP;
}

MASSTOR_LIST MASYMDIP_DIPTODEF
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST TP;

  TP = DIPC_EVORD;
  DIPC_EVORD = T;
  return TP;
}

MASSTOR_LIST MASYMDIP_SYM2DIP
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST D, DP, TP, VP, V, v, n;

  VP = MASYMDIP_TVARS(T);
  V = MASSTOR_SIL;
  while (VP != MASSTOR_SIL) {
    MASSTOR_ADV(VP, &v, &VP);
    n = MASSYM2_EXPLOD(v);
    V = MASSTOR_COMP(n, V);
  }
  V = MASSTOR_INV(V);
  V = SACSET_USDIFF(V, DIPC_VALIS);
  if (V != MASSTOR_SIL) {
    VP = V;
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Variable(s) added to VALIS: ", 28L);
    while (V != MASSTOR_SIL) {
      MASSTOR_ADV(V, &v, &V);
      SACLIST_CLOUT(v);
      if (V != MASSTOR_SIL) {
        MASBIOS_SWRITE(", ", 2L);
      }
    }
    MASBIOS_BLINES(0);
    DIPC_VALIS = SACLIST_CCONC(DIPC_VALIS, VP);
  }
  D = MASSTOR_SIL;
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &TP, &T);
    DP = MASYMDIP_DIRPFT(TP, DIPC_VALIS);
    D = MASSTOR_COMP(DP, D);
  }
  D = MASSTOR_INV(D);
  return D;
}

MASSTOR_LIST MASYMDIP_DIP2SYM
# ifdef __STDC__
(MASSTOR_LIST D)
# else
(D)
MASSTOR_LIST D;
# endif
{
  MASSTOR_LIST DP, TP, T, V, VP, v, n;

  V = DIPC_VALIS;
  VP = MASSTOR_SIL;
  while (V != MASSTOR_SIL) {
    MASSTOR_ADV(V, &n, &V);
    v = MASSYM2_ENTER(n);
    VP = MASSTOR_COMP(v, VP);
  }
  VP = MASSTOR_INV(VP);
  T = MASSTOR_SIL;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &DP, &D);
    TP = MASYMDIP_TFDIRP(DP, VP);
    T = MASSTOR_COMP(TP, T);
  }
  T = MASSTOR_INV(T);
  return T;
}

MASSTOR_LIST MASYMDIP_TVARS
# ifdef __STDC__
(MASSTOR_LIST T)
# else
(T)
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST V, v, t, TP;

  V = MASSTOR_SIL;
  if (T <= MASSTOR_BETA) {
    return V;
  }
  if (MASSYM2_SYMBOL(T)) {
    if (MASSYM2_GET(T, MASLISPU_EXTYP) != MASSTOR_SIL) {
      return V;
    }
    V = MASSTOR_LIST1(T);
    return V;
  }
  TP = T;
  while (TP != MASSTOR_SIL) {
    MASSTOR_ADV(TP, &t, &TP);
    v = MASYMDIP_TVARS(t);
    if (v != MASSTOR_SIL) {
      V = SACSET_USUN(v, V);
    }
  }
  return V;
}

MASSTOR_LIST MASYMDIP_DIRPFT
# ifdef __STDC__
(MASSTOR_LIST T, MASSTOR_LIST V)
# else
(T, V)
MASSTOR_LIST T, V;
# endif
{
  MASSTOR_LIST C_182_A, A1, AP, TP, t, tp, v, IL, JL, RL, ES;

  C_182_A = 0;
  if (T == 0) {
    return C_182_A;
  }
  RL = MASSTOR_LENGTH(V);
  ES = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        ES = MASSTOR_COMP(0, ES);
        if (IL >= B_2) break;
      }
  }
  if (MASSYM_ELEMP(T)) {
    C_182_A = DIPC_DIPFMO(SACRN_RNINT(T), ES);
    return C_182_A;
  }
  A1 = DIPC_DIPFMO(SACRN_RNINT(1), ES);
  if (MASSYM2_SYMBOL(T)) {
    v = MASSYM2_EXPLOD(T);
    JL = SACPOL_VLSRCH(v, V);
    if (JL == 0) {
      MASBIOS_SWRITE("variable: ", 10L);
      SACLIST_CLOUT(v);
      MASBIOS_BLINES(0);
      MASERR_ERROR(MASERR_severe, "DIRPFT variable not defined.", 28L);
    }
    C_182_A = DIPC_DIPMPV(A1, JL, 1);
    return C_182_A;
  }
  MASSTOR_ADV(T, &t, &TP);
  if (t == MASLISP_ADD) {
    C_182_A = 0;
    while (TP != MASSTOR_SIL) {
      MASSTOR_ADV(TP, &t, &TP);
      AP = MASYMDIP_DIRPFT(t, V);
      C_182_A = DIPRN_DIRPSM(C_182_A, AP);
    }
  } else if (t == MASLISP_SUB) {
    MASSTOR_ADV(TP, &t, &TP);
    AP = MASYMDIP_DIRPFT(t, V);
    if (TP == MASSTOR_SIL) {
      C_182_A = DIPRN_DIRPNG(AP);
    } else {
      C_182_A = AP;
      while (TP != MASSTOR_SIL) {
        MASSTOR_ADV(TP, &t, &TP);
        AP = MASYMDIP_DIRPFT(t, V);
        C_182_A = DIPRN_DIRPDF(C_182_A, AP);
      }
    }
  } else if (t == MASLISP_MUL) {
    C_182_A = A1;
    while (TP != MASSTOR_SIL) {
      MASSTOR_ADV(TP, &t, &TP);
      AP = MASYMDIP_DIRPFT(t, V);
      C_182_A = DIPRN_DIRPPR(C_182_A, AP);
    }
  } else if (t == MASLISP_QUOT) {
    MASSTOR_ADV(TP, &t, &TP);
    tp = MASSTOR_FIRST(TP);
    AP = SACRN_RNRED(t, tp);
    C_182_A = DIPC_DIPFMO(AP, ES);
  } else if (t == MASLISP_POW) {
    MASSTOR_ADV(TP, &t, &TP);
    C_182_A = MASYMDIP_DIRPFT(t, V);
    t = MASSTOR_FIRST(TP);
    C_182_A = DIPRN_DIRPEX(C_182_A, t);
  } else if (t == MASLISP_STRNG) {
    TP = SACLIST_CCONC(TP, MASBIOS_LISTS(" ", 1L));
    MASBIOSU_CLTIS(TP);
    AP = MASAPF_RNDRD();
    C_182_A = DIPC_DIPFMO(AP, ES);
  } else {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("name=", 5L);
    MASSYM_UWRITE(t);
    MASERR_ERROR(MASERR_severe, "DIRPFT, no allowed function.", 28L);
  }
  return C_182_A;
}

MASSTOR_LIST MASYMDIP_TFDIRP
# ifdef __STDC__
(MASSTOR_LIST C_181_A, MASSTOR_LIST V)
# else
(C_181_A, V)
MASSTOR_LIST C_181_A, V;
# endif
{
  MASSTOR_LIST T, AP, TP, t, tp, VP, v, a, E, EP, e, s;

  if (C_181_A == 0) {
    return 0;
  }
  AP = C_181_A;
  T = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(AP, &a, &E, &AP);
    t = MASSTOR_SIL;
    s = SACRN_RNCOMP(a, 0);
    if (s < 0) {
      a = SACRN_RNNEG(a);
    }
    if (SACRN_RNDEN(a) != 1) {
      t = SACLIST_LIST3(MASLISP_QUOT, SACRN_RNNUM(a), SACRN_RNDEN(a));
    } else {
      a = SACRN_RNNUM(a);
      if (a != 1 || s < 0) {
        t = a;
      }
    }
    if (s < 0) {
      t = SACLIST_LIST2(MASLISP_SUB, t);
    }
    EP = SACLIST_CINV(E);
    VP = V;
    while (EP != MASSTOR_SIL) {
      MASSTOR_ADV(EP, &e, &EP);
      MASSTOR_ADV(VP, &v, &VP);
      if (e > 0) {
        if (e > 1) {
          tp = SACLIST_LIST3(MASLISP_POW, v, e);
        } else {
          tp = v;
        }
        if (t == MASSTOR_SIL) {
          t = tp;
        } else {
          t = SACLIST_LIST3(MASLISP_MUL, t, tp);
        }
      }
    }
    if (t == MASSTOR_SIL) {
      t = 1;
    }
    if (T == MASSTOR_SIL) {
      T = t;
    } else {
      T = SACLIST_LIST3(MASLISP_ADD, T, t);
    }
  } while (!(AP == MASSTOR_SIL));
  return T;
}

static MASSTOR_LIST TERM
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST X;

  X = MASYMDIP_DIP2SYM(P);
  X = SACLIST_LIST2(MASLISP_QUOTE, X);
  return X;
}

static void mkpoly
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST X, f, Y, Z;

  MASLISPU_Declare(&X, "X", 1L);
  MASLISPU_Declare(&f, "SYM2DIP", 7L);
  Z = MASSTOR_LIST1(X);
  Y = MASSTOR_COMP(f, Z);
  Y = SACLIST_LIST2(Z, Y);
  MASLISPU_Declare(&f, "POLY", 4L);
  Y = SACLIST_COMP2(MASLISP_DF, f, Y);
  Y = MASSPEC_EVALUATE(Y, &MASLISP_ENV);
}

void MASYMDIP_InitExternalsI
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Compiledf1(MASYMDIP_TVARS, "TVARS", 5L);
  MASLISPU_Compiledf1(MASYMDIP_DIPVDEF, "DIPVDEF", 7L);
  MASLISPU_Compiledf1(MASYMDIP_DIPTODEF, "DIPTODEF", 8L);
  MASLISPU_Compiledf2(MASYMDIP_DIRPFT, "DIRPFT", 6L);
  MASLISPU_Compiledf2(MASYMDIP_TFDIRP, "TFDIRP", 6L);
  MASLISPU_Compiledf1(MASYMDIP_SYM2DIP, "SYM2DIP", 7L);
  MASLISPU_Compiledf1(MASYMDIP_DIP2SYM, "DIP2SYM", 7L);
  MASLISPU_Compiledf1(TERM, "TERM", 4L);
  mkpoly();
  MASLISPU_Compiledf0(pread, "PREAD", 5L);
  MASLISPU_Compiledp1(pwrite, "PWRITE", 6L);
  MASLISPU_Compiledf0(preadi, "PREADI", 6L);
  MASLISPU_Compiledp1(pwritei, "PWRITEI", 7L);
  MASLISPU_Compiledf0(pdread, "PDREAD", 6L);
  MASLISPU_Compiledp1(pdwrite, "PDWRITE", 7L);
  MASLISPU_Compiledf1(preadd, "PREADD", 6L);
  MASLISPU_Compiledp2(pwrited, "PWRITED", 7L);
}

void BEGIN_MASYMDIP()
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
    BEGIN_SACSET();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();
    BEGIN_MASSPEC();
    BEGIN_SACRN();
    BEGIN_MASAPF();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPRN();
    BEGIN_DIPTOO();

  }
}
