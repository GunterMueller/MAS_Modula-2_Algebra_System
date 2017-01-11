#include "SYSTEM_.h"

#ifndef DEFINITION_clock
#include "clock.h"
#endif

#ifndef DEFINITION_MASCONF
#include "MASCONF.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASmtc
#include "MASmtc.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Times
#include "Times.h"
#endif

#ifndef DEFINITION_System
#include "System.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

MASSTOR_LIST MASSTOR_BETA, MASSTOR_BETA1, MASSTOR_SIL;
MASELEM_GAMMAINT MASSTOR_NU, MASSTOR_GCC, MASSTOR_GCCC, MASSTOR_GCM, MASSTOR_RHO, MASSTOR_TAU, MASSTOR_TAU0;
CHAR MASSTOR_rcsid [] = "$Id: MASSTOR.md,v 1.3 1995/12/16 14:51:35 kredel Exp $";
CHAR MASSTOR_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define maxerr	20
#define blocklen	(12 * 1024)
#define proclen	(12 * 1024)
#define sysres	(160 * 1024)
#define tomax	10
#define rhomin	500
#define stackOK	1024
static CHAR rcsidi [] = "$Id: MASSTOR.mip,v 1.6 1996/06/08 18:26:52 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1995 Universitaet Passau";
typedef LONGCARD *ADDRLW;
typedef void (*P1) ARGS((MASELEM_GAMMAINT));
typedef void (*PS) ARGS((struct S_1 {
    CHAR A[1];
}));
static MASELEM_GAMMAINT Csize, Lsize;
static MASELEM_GAMMAINT BETA2, NUP;
static MASSTOR_LIST AVAIL, Globalvars;
static MASELEM_GAMMAINT SPACEB, SPACEB1;
static MASELEM_GAMMAINT toview, eh, marks;
static ADDRESS SPACE, SPACEEND, STACK, STACKEND, Tstack;
static void ALLOCATESPACE ARGS((ADDRESS *S, LONGINT *AMNT));
static LONGINT GETLONGINT ARGS((LONGINT C_2_A));
static void GC ARGS(());
static void InitSTOR ARGS((MASELEM_GAMMAINT n));
struct S_3 {
    CHAR A[50 + 1];
};
static void Consistence ARGS(());
static void MARK ARGS((MASSTOR_LIST L));
static void MARKRANGE ARGS((MASSTOR_LIST B, MASSTOR_LIST E));
static void DumpStack ARGS(());
static void DumpObj ARGS((MASSTOR_LIST L));
static BOOLEAN SUBLIST ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST B));
static void SysInfo ARGS(());
static void WI ARGS((MASELEM_GAMMAINT a));
static void WH ARGS((MASELEM_GAMMAINT a));
static void WS ARGS((CHAR s[], LONGCARD ));
static void WL ARGS(());
static CHAR InChar ARGS(());
static void Escape ARGS(());
static void SetSTACKEND ARGS(());


MASSTOR_LIST MASSTOR_FIRST
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  ADDRLW s;

  if (L < MASSTOR_BETA || BETA2 <= L) {
    WL();
    WI(L);
    MASERR_ERROR(MASERR_severe, "FIRST address out of range, value = ", 36L);
    return 0;
  }
  s = (ADDRLW)(ADDRESS)(SPACEB1 + L);
  return (MASSTOR_LIST)(*s);
}

MASSTOR_LIST MASSTOR_RED
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  ADDRLW s;

  if (L < MASSTOR_BETA || BETA2 <= L) {
    WL();
    WI(L);
    MASERR_ERROR(MASERR_severe, "RED address out of range, value = ", 34L);
    return MASSTOR_SIL;
  }
  s = (ADDRLW)(ADDRESS)(SPACEB + L);
  return (MASSTOR_LIST)(*s);
}

void MASSTOR_SFIRST
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST a)
# else
(L, a)
MASSTOR_LIST L, a;
# endif
{
  ADDRLW s;

  if (L < MASSTOR_BETA || BETA2 <= L) {
    WL();
    WI(L);
    MASERR_ERROR(MASERR_severe, "SFIRST address out of range, value = ", 37L);
    return;
  }
  s = (ADDRLW)(ADDRESS)(SPACEB1 + L);
  *s = (LONGCARD)a;
  return;
}

void MASSTOR_SRED
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST LP)
# else
(L, LP)
MASSTOR_LIST L, LP;
# endif
{
  ADDRLW s;

  s = (ADDRLW)(ADDRESS)(SPACEB + L);
  *s = (LONGCARD)LP;
  return;
}

void MASSTOR_ADV
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST *a, MASSTOR_LIST *LP)
# else
(L, a, LP)
MASSTOR_LIST L;
MASSTOR_LIST *a, *LP;
# endif
{
  *a = MASSTOR_FIRST(L);
  *LP = MASSTOR_RED(L);
  return;
}

static void ALLOCATESPACE
# ifdef __STDC__
(ADDRESS *S, LONGINT *AMNT)
# else
(S, AMNT)
ADDRESS *S;
LONGINT *AMNT;
# endif
{
  LONGCARD p2, d, amnt;
  CARDINAL a, i;
  ADDRESS SP;
  BOOLEAN t;

  amnt = 0;
  if (*AMNT > 0) {
    amnt = (LONGCARD)(*AMNT);
  }
  p2 = blocklen;
  d = amnt / p2 + 1;
  amnt = d * p2;
  *S = SysAlloc(amnt);
  *AMNT = (LONGINT)amnt;
}

MASELEM_GAMMAINT MASSTOR_CELLS
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT a, c;

  a = MASSTOR_NU - MASSTOR_LENGTH(AVAIL);
  c = MASSTOR_GCCC + a;
  return c;
}

MASELEM_GAMMAINT MASSTOR_CLOCK
# ifdef __STDC__
()
# else
()
# endif
{
  return (MASELEM_GAMMAINT)ClocK();
}

MASSTOR_LIST MASSTOR_COMP
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST L)
# else
(a, L)
MASSTOR_LIST a, L;
# endif
{
  MASSTOR_LIST M;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (AVAIL == MASSTOR_SIL) {
    GC();
  }
  M = AVAIL;
  AVAIL = MASSTOR_RED(M);
  MASSTOR_SFIRST(M, a);
  MASSTOR_SRED(M, L);
  m = sigsetmask(m);
  return M;
}

MASSTOR_LIST MASSTOR_DEQUE
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST a, M, MP;

  M = MASSTOR_RED(L);
  MASSTOR_ADV(M, &a, &MP);
  if (MP == MASSTOR_SIL) {
    MASSTOR_SFIRST(L, L);
  }
  MASSTOR_SRED(L, MP);
  return a;
}

void MASSTOR_ENQUE
# ifdef __STDC__
(MASSTOR_LIST a, MASSTOR_LIST L)
# else
(a, L)
MASSTOR_LIST a, L;
# endif
{
  MASSTOR_LIST M, MP;

  M = MASSTOR_COMP(a, MASSTOR_SIL);
  MP = MASSTOR_FIRST(L);
  MASSTOR_SRED(MP, M);
  MASSTOR_SFIRST(L, M);
}

MASSTOR_LIST MASSTOR_NEWQUE
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST M;

  M = MASSTOR_COMP(0, MASSTOR_SIL);
  MASSTOR_SFIRST(M, M);
  return M;
}

BOOLEAN MASSTOR_EMPTYQUE
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  BOOLEAN t;

  t = MASSTOR_RED(M) == MASSTOR_SIL;
  return t;
}

static LONGINT GETLONGINT
# ifdef __STDC__
(LONGINT C_2_A)
# else
(C_2_A)
LONGINT C_2_A;
# endif
{
  LONGINT AL;
  BYTE *XP, *YP;
  ADDRESS EINZ;

  XP = (WORD *)ADR(AL);
  YP = (WORD *)(ADDRESS)C_2_A;
  EINZ = (ADDRESS)1;
  *XP = *YP;
  XP = (WORD *)((ADDRESS)XP + (LONGCARD)EINZ);
  YP = (WORD *)((ADDRESS)YP + (LONGCARD)EINZ);
  *XP = *YP;
  XP = (WORD *)((ADDRESS)XP + (LONGCARD)EINZ);
  YP = (WORD *)((ADDRESS)YP + (LONGCARD)EINZ);
  *XP = *YP;
  XP = (WORD *)((ADDRESS)XP + (LONGCARD)EINZ);
  YP = (WORD *)((ADDRESS)YP + (LONGCARD)EINZ);
  *XP = *YP;
  return AL;
}

static void GC
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT CSTACK, BS, ES;
  MASSTOR_LIST a, I, J, K, L, LP, T, N, T1, I1, I2, I3;
  INTEGER m;

  T1 = MASSTOR_CLOCK();
  m = sigblock(SigMask(massig_SIGUSR1));
  if (MASSTOR_GCM == 1) {
    MASERR_ERROR(MASERR_spotless, "Garbage collection ...", 22L);
  }
  BS = MASSTOR_SIL;
  ES = MASSTOR_SIL;
  AVAIL = MASSTOR_SIL;
  marks = 0;
  LP = Globalvars;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &I, &LP);
    a = GETLONGINT(I);
    MARK(a);
  }
  LP = Globalvars;
  if (LP != MASSTOR_SIL) {
    MARK(LP);
  }
  if (ADR(CSTACK) < STACKEND) {
    if (ADR(CSTACK) > ADR(m)) {
      CSTACK = (MASELEM_GAMMAINT)ADR(CSTACK) + 4;
    } else {
      CSTACK = (MASELEM_GAMMAINT)ADR(m) + 4;
    }
    MARKRANGE(CSTACK, (MASELEM_GAMMAINT)STACKEND);
  } else {
    if (ADR(CSTACK) < ADR(m)) {
      CSTACK = (MASELEM_GAMMAINT)ADR(CSTACK) - 4;
    } else {
      CSTACK = (MASELEM_GAMMAINT)ADR(m) - 4;
    }
    MARKRANGE((MASELEM_GAMMAINT)STACKEND, CSTACK);
  }
  N = 0;
  I = NUP - Csize;
  K = Csize;
  while (I >= K) {
    J = MASSTOR_BETA + I;
    LP = MASSTOR_RED(J);
    if (LP > 0) {
      MASSTOR_SRED(J, AVAIL);
      AVAIL = J;
      MASSTOR_SFIRST(J, 0);
      N = N + 1;
    } else {
      MASSTOR_SRED(J, -LP);
    }
    I = I - Csize;
  }
  T = MASSTOR_CLOCK() - T1;
  MASSTOR_TAU = MASSTOR_TAU + T;
  MASSTOR_GCC = MASSTOR_GCC + 1;
  MASSTOR_GCCC = MASSTOR_GCCC + N;
  if (MASSTOR_GCM == 1) {
    WS(" ", 1L);
    WI(N);
    WS(" cells, ", 8L);
    WI(T);
    WS(" milliseconds.", 14L);
    MASERR_ERROR(MASERR_spotless, "... GC completed.", 17L);
  }
  m = sigsetmask(m);
  if (N > MASSTOR_NU / MASSTOR_RHO) {
    toview = 0;
    return;
  }
  toview = toview + 1;
  if (toview > tomax || N < rhomin) {
    MASERR_ERROR(MASERR_confusion, "Garbage Collection: No free cells reclaimed.", 44L);
  } else {
    MASERR_ERROR(MASERR_fatal, "Garbage Collection: Too few cells reclaimed.", 44L);
  }
}

static void InitSTOR
# ifdef __STDC__
(MASELEM_GAMMAINT n)
# else
(n)
MASELEM_GAMMAINT n;
# endif
{
  MASELEM_GAMMAINT i, j, k;
  Strings_tString s, s1;
  struct S_3 sa;

  MASSTOR_RHO = 10;
  MASSTOR_TAU = 0;
  MASSTOR_GCC = 0;
  MASSTOR_GCCC = 0;
  MASSTOR_GCM = 1;
  if (MASSTOR_GCM == 1) {
    Strings_IntToString(n, &s);
    Strings_ArrayToString("Storage initalization (", 23L, &s1);
    Strings_Concatenate(&s1, &s);
    Strings_ArrayToString(" kB) ...", 8L, &s);
    Strings_Concatenate(&s1, &s);
    Strings_StringToArray(&s1, sa.A, 51L);
    MASERR_ERROR(MASERR_spotless, sa.A, 51L);
  }
  Lsize = sizeof(MASSTOR_LIST);
  Csize = 2 * Lsize;
  MASSTOR_BETA = MASELEM_MASEXP(2, 29);
  MASSTOR_BETA1 = MASSTOR_BETA - Lsize;
  MASSTOR_SIL = MASSTOR_BETA;
  MASSTOR_TAU0 = MASSTOR_CLOCK();
  toview = 0;
  n = n * 1024;
  MASSTOR_NU = n / Csize;
  NUP = MASSTOR_NU * Csize;
  ALLOCATESPACE(&SPACE, &NUP);
  if (SPACE == NIL) {
    AVAIL = MASSTOR_BETA;
    MASERR_ERROR(MASERR_confusion, "No Storage Available.", 21L);
    return;
  }
  SPACEEND = SPACE + (LONGCARD)(ADDRESS)NUP;
  MASSTOR_NU = NUP / Csize;
  if (MASSTOR_NU <= 0) {
    AVAIL = MASSTOR_BETA;
    MASERR_ERROR(MASERR_confusion, "No Storage Available.", 21L);
    return;
  }
  BETA2 = MASSTOR_BETA + NUP;
  SPACEB = (MASELEM_GAMMAINT)SPACE - MASSTOR_BETA;
  SPACEB1 = (MASELEM_GAMMAINT)SPACE - MASSTOR_BETA1;
  AVAIL = MASSTOR_BETA + Csize;
  i = Csize;
  k = NUP - Csize;
  while (i <= k) {
    j = MASSTOR_BETA + i;
    MASSTOR_SRED(j, j + Csize);
    MASSTOR_SFIRST(j, 0);
    i = i + Csize;
  }
  MASSTOR_SRED(j, MASSTOR_SIL);
  Globalvars = MASSTOR_SIL;
  Tstack = (ADDRESS)(STACKEND - proclen);
  Tstack = (ADDRESS)(Tstack + stackOK);
  if (MASSTOR_GCM == 1) {
    MASERR_ERROR(MASERR_spotless, "... completed.", 14L);
  }
}

static void Consistence
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST n, I, J, K, L, LP;

  n = 0;
  WL();
  WS("Cell consistence check ...", 26L);
  WL();
  I = NUP - Csize;
  K = Csize;
  while (I >= K) {
    J = MASSTOR_BETA + I;
    LP = MASSTOR_RED(J);
    L = MASSTOR_FIRST(J);
    if (LP < MASSTOR_BETA || BETA2 <= LP) {
      n = n + 1;
      WS("invalid reductum at ", 20L);
      WI(J);
      WS(" contents ", 10L);
      WI(L);
      WS(" ", 1L);
      WI(LP);
      WL();
    }
    if (L < -MASSTOR_BETA || BETA2 <= L) {
      n = n + 1;
      WS("invalid first at ", 17L);
      WI(J);
      WS(" contents ", 10L);
      WI(L);
      WS(" ", 1L);
      WI(LP);
      WL();
    }
    I = I - Csize;
  }
  WI(n);
  WS(" invalid value(s).", 18L);
  WL();
}

MASSTOR_LIST MASSTOR_INV
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST M, MP, MPP;

  M = MASSTOR_BETA;
  MP = L;
  while (MP != MASSTOR_SIL) {
    MPP = MASSTOR_RED(MP);
    MASSTOR_SRED(MP, M);
    M = MP;
    MP = MPP;
  }
  return M;
}

MASELEM_GAMMAINT MASSTOR_LENGTH
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LP;
  MASELEM_GAMMAINT n;

  n = 0;
  LP = L;
  while (LP > MASSTOR_SIL) {
    LP = MASSTOR_RED(LP);
    n = n + 1;
  }
  return n;
}

MASSTOR_LIST MASSTOR_LIST1
# ifdef __STDC__
(MASSTOR_LIST a)
# else
(a)
MASSTOR_LIST a;
# endif
{
  MASSTOR_LIST L;

  L = MASSTOR_COMP(a, MASSTOR_SIL);
  return L;
}

void MASSTOR_LISTVAR
# ifdef __STDC__
(MASSTOR_LIST *L)
# else
(L)
MASSTOR_LIST *L;
# endif
{
  MASELEM_GAMMAINT s;

  s = (MASELEM_GAMMAINT)ADR(*L);
  Globalvars = MASSTOR_COMP(s, Globalvars);
}

static void MARK
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, LP, LS;

  if (L <= MASSTOR_BETA || BETA2 <= L || L % Csize != 0) {
    return;
  }
  LP = L;
  while (LP != MASSTOR_SIL) {
    LS = MASSTOR_RED(LP);
    if (LS < MASSTOR_BETA || BETA2 <= LS) {
      return;
    }
    MASSTOR_SRED(LP, -LS);
    AL = MASSTOR_FIRST(LP);
    MARK(AL);
    LP = LS;
  }
}

static void MARKRANGE
# ifdef __STDC__
(MASSTOR_LIST B, MASSTOR_LIST E)
# else
(B, E)
MASSTOR_LIST B, E;
# endif
{
  MASSTOR_LIST I, E1, a;

  I = B;
  E1 = E - Lsize;
  while (I <= E1) {
    a = GETLONGINT(I);
    MARK(a);
    I = I + 1;
  }
}

static void DumpStack
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST I, E, a;
  CHAR c;

  I = (MASELEM_GAMMAINT)MASmtc_getstck();
  E = I + 1000;
  WL();
  WS("Stack Dump: ", 12L);
  WL();
  while (I <= E) {
    a = GETLONGINT(I);
    WI(I);
    WS(" = ", 3L);
    DumpObj(a);
    WL();
    WS("(e)nd, <ENTER> ? ", 17L);
    c = InChar();
    if (c == 'e' || c == 'E') {
      return;
    }
    I = I + 1;
  }
}

static void DumpObj
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST AL, LP, LS, i;

  if (L <= MASSTOR_BETA || BETA2 <= L) {
    WI(L);
    return;
  }
  if (L % Csize != 0) {
    WI(L);
    return;
  }
  LP = L;
  i = 0;
  WS("(", 1L);
  while (LP != MASSTOR_SIL) {
    LS = MASSTOR_RED(LP);
    if (LS < MASSTOR_BETA || BETA2 <= LS) {
      return;
    }
    AL = MASSTOR_FIRST(LP);
    i = i + 1;
    if (i >= 5) {
      i = 0;
      WL();
    }
    DumpObj(AL);
    if (LS != MASSTOR_SIL) {
      WS(", ", 2L);
    }
    LP = LS;
  }
  WS(")", 1L);
}

static BOOLEAN SUBLIST
# ifdef __STDC__
(MASSTOR_LIST C_1_A, MASSTOR_LIST B)
# else
(C_1_A, B)
MASSTOR_LIST C_1_A, B;
# endif
{
  MASSTOR_LIST BP;
  BOOLEAN t;

  BP = B;
  t = FALSE;
  while (BP != MASSTOR_SIL) {
    if (C_1_A == BP) {
      t = TRUE;
      return t;
    }
    BP = MASSTOR_RED(BP);
  }
  return t;
}

MASELEM_GAMMAINT MASSTOR_TIME
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT T;

  T = MASSTOR_CLOCK();
  T = T - MASSTOR_TAU;
  return T;
}

static void SysInfo
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT a, b, bp, i, c;

  WI(MASSTOR_NU);
  WS(" CELLS IN SPACE.", 16L);
  WL();
  WS("NUMBER OF BYTES ALLOCATED = ", 28L);
  WH(NUP);
  WL();
  WS("ADDRESS OF ALLOCATED AREA = ", 28L);
  WH((MASELEM_GAMMAINT)SPACE);
  WL();
  WS("BETA         = ", 15L);
  WH(MASSTOR_BETA);
  WL();
  WS("BETA2        = ", 15L);
  WH(BETA2);
  WL();
  WS("SPACE BEGIN  = ", 15L);
  WH((MASELEM_GAMMAINT)SPACE);
  WL();
  WS("SPACE END    = ", 15L);
  WH((MASELEM_GAMMAINT)SPACEEND);
  WL();
  STACK = (ADDRESS)MASmtc_getstck();
  WS("STACK END    = ", 15L);
  WH((MASELEM_GAMMAINT)STACKEND);
  WL();
  WS("STACK A1     = ", 15L);
  WH((MASELEM_GAMMAINT)STACK);
  WL();
  a = (MASELEM_GAMMAINT)MASmtc_gettoc();
  WS("TOC   A2     = ", 15L);
  WH(a);
  WL();
}

static void WI
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  StdIO_WriteI(a, 1);
}

static void WH
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  StdIO_WriteI(a, 1);
  StdIO_WriteS("  ", 2L);
  StdIO_WriteN(a, 1, 16);
}

static void WS
# ifdef __STDC__
(CHAR s[], LONGCARD O_1)
# else
(s, O_1)
CHAR s[];
LONGCARD O_1;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_1, CHAR)
  StdIO_WriteS(s, O_1);
  StdIO_WriteFlush();
  FREE_OPEN_ARRAYS
}

static void WL
# ifdef __STDC__
()
# else
()
# endif
{
  StdIO_WriteNl();
  StdIO_WriteFlush();
}

static CHAR InChar
# ifdef __STDC__
()
# else
()
# endif
{
  CHAR c;

  c = StdIO_ReadC();
  if (ORD(c) <= 10) {
    c = StdIO_ReadC();
  }
  return c;
}

static void Escape
# ifdef __STDC__
()
# else
()
# endif
{
  CHAR c;

  c = StdIO_ReadC();
  if (ORD(c) <= 10) {
    c = StdIO_ReadC();
  }
  if (ORD(c) == 27) {
    MASERR_ERROR(MASERR_severe, "ESC key pressed.", 16L);
  }
}

static void SetSTACKEND
# ifdef __STDC__
()
# else
()
# endif
{
  ADDRESS s;

  s = ADR(s);
  STACKEND = s;
}

void BEGIN_MASSTOR()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_clock();
    BEGIN_MASCONF();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASmtc();
    BEGIN_massig();
    BEGIN_StdIO();
    BEGIN_Strings();
    BEGIN_Times();
    BEGIN_System();

    SetSTACKEND();
    InitSTOR(MASCONF_KBCell);
  }
}
