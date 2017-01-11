#include "SYSTEM_.h"

#ifndef DEFINITION_MASmtc
#include "MASmtc.h"
#endif

#ifndef DEFINITION_setjmp
#include "setjmp.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_StdIO
#include "StdIO.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASCONF
#include "MASCONF.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

CHAR MASERR_rcsid [] = "$Id: MASERR.md,v 1.2 1992/02/12 17:31:55 pesch Exp $";
CHAR MASERR_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
MASERR_P0 MASERR_DebugProcessor;
MASELEM_GAMMAINT MASERR_history;

static CHAR rcsidi [] = "$Id: MASERR.mi,v 1.9 1995/11/05 08:50:56 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
#define maxerr	20
typedef void (*P1) ARGS((MASELEM_GAMMAINT));
typedef void (*PS) ARGS((struct S_1 {
    CHAR A[1];
}));
static MASELEM_GAMMAINT elevel;
static MASELEM_GAMMAINT fehler;
static BOOLEAN schluss, errhup;
static setjmp_jmp_buf errenv;
static MASELEM_GAMMAINT eh;
static ADDRESS STACK, STACKEND;
static INTEGER lasterr;
static void InitERR ARGS(());
static void DumpStack ARGS(());
static LONGINT GETLONGINT ARGS((LONGINT C_1_A));
static void Debug ARGS(());
static INTEGER runtime ARGS((INTEGER e));
struct S_4 {
    CHAR A[100 + 1];
};
static void WI ARGS((MASELEM_GAMMAINT a));
static void WH ARGS((MASELEM_GAMMAINT a));
static void WS ARGS((CHAR s[], LONGCARD ));
static void WL ARGS(());
static CHAR InChar ARGS(());
static void Escape ARGS(());
static void SysInfo ARGS(());


static void InitERR
# ifdef __STDC__
()
# else
()
# endif
{
  elevel = 0;
  lasterr = 0;
  STACKEND = (ADDRESS)0;
  schluss = FALSE;
  errhup = FALSE;
  MASERR_DebugProcessor = (MASERR_P0)NIL;
}

static void DumpStack
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT I, E, a;
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
    WH(a);
    WL();
    WS("(e)nd, <ENTER> ? ", 17L);
    c = InChar();
    if (c == 'e' || c == 'E') {
      return;
    }
    I = I + 1;
  }
}

static LONGINT GETLONGINT
# ifdef __STDC__
(LONGINT C_1_A)
# else
(C_1_A)
LONGINT C_1_A;
# endif
{
  LONGINT AL;
  BYTE *XP, *YP;
  ADDRESS EINZ;

  XP = (WORD *)ADR(AL);
  YP = (WORD *)(ADDRESS)C_1_A;
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

void MASERR_ERROR
# ifdef __STDC__
(MASELEM_GAMMAINT a, CHAR s[], LONGCARD O_1)
# else
(a, s, O_1)
MASELEM_GAMMAINT a;
CHAR s[];
LONGCARD O_1;
# endif
{
  INTEGER i;
  CHAR c;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_1, CHAR)
  if (a > MASERR_history) {
    MASERR_history = a;
  }
  if (a == MASERR_spotless && (O_1 - 1) < 5) {
    FREE_OPEN_ARRAYS
    return;
  }
  elevel = elevel + 1;
  WL();
  WS("** ", 3L);
  i = (INTEGER)a;
  switch (i) {
  case MASERR_spotless:;
    break;
  case MASERR_harmless:;
    WS("error: ", 7L);
    break;
  case MASERR_severe:;
    WS("severe error: ", 14L);
    break;
  case MASERR_fatal:;
    WS("fatal error: ", 13L);
    break;
  default :
    WS("(", 1L);
    WI(a);
    WS(") ", 2L);
    break;
  }
  WS(s, O_1);
  WS(" ", 1L);
  if (lasterr == massig_SIGTERM) {
    MASERR_history = MASERR_confusion;
    longjmp(&errenv, 1);
  }
  if (i > MASERR_harmless) {
    if (MASCONF_ExitOnError) {
      a = MASERR_confusion;
    } else {
      for (;;) {
        WL();
        WS("(a)bort, (b)reak, (c)ontinue, (d)ebug, <ENTER> ? ", 49L);
        c = InChar();
        if (c == 's' || c == 'S') {
          DumpStack();
        } else if (c == 'i' || c == 'I') {
          SysInfo();
        } else if (c == 'd' || c == 'D') {
          Debug();
        } else {
          goto EXIT_1;
        }
      } EXIT_1:;
      switch (c) {
      case 'a':;
      case 'A':;
        WS("abort", 5L);
        a = MASERR_confusion;
        break;
      case 'b':;
      case 'B':;
        WS("break", 5L);
        a = MASERR_fatal;
        break;
      case 'c':;
      case 'C':;
        WS("continue", 8L);
        a = MASERR_severe;
        break;
      default :
        WS("system", 6L);
        break;
      }
      WS(". ", 2L);
    }
  }
  if (a > MASERR_history) {
    MASERR_history = a;
  }
  elevel = elevel - 1;
  if (elevel > 0) {
    MASERR_history = MASERR_history + 1;
  }
  if (MASERR_history > MASERR_spotless) {
    fehler = fehler + 1;
  }
  if (fehler > maxerr) {
    MASERR_history = MASERR_history + 1;
  }
  if (MASERR_spotless <= MASERR_history && MASERR_history < MASERR_fatal) {
    FREE_OPEN_ARRAYS
    return;
  }
  if (MASERR_spotless <= a && a < MASERR_fatal) {
    FREE_OPEN_ARRAYS
    return;
  }
  if (!errhup) {
    exit(1);
  }
  if (MASERR_history > MASERR_confusion) {
    exit(1);
  }
  longjmp(&errenv, 2);
  FREE_OPEN_ARRAYS
}

static void Debug
# ifdef __STDC__
()
# else
()
# endif
{
  if ((ADDRESS)MASERR_DebugProcessor == NIL) {
    WL();
    WS("No Debug Processor available.", 29L);
    WL();
    return;
  }
  WL();
  WS("Entering Debug Processor ...", 28L);
  WL();
  (*MASERR_DebugProcessor)();
  WL();
  WS("... Debug Processor exited.", 27L);
  WL();
}

MASELEM_GAMMAINT MASERR_ErrorHandler
# ifdef __STDC__
(MASERR_P0 a)
# else
(a)
MASERR_P0 a;
# endif
{
  INTEGER f, t;
  massig_Action oldsig;

  f = 0;
  oldsig = signal(massig_SIGINT, runtime);
  if (oldsig == massig_SIG_ERR) {
    WL();
    WS("Cannot install runtime signal handler.", 38L);
    WL();
  }
  do {
    f = f + 1;
    fehler = 0;
    MASERR_history = MASERR_spotless;
    t = setjmp(&errenv);
    errhup = TRUE;
    if (t == 0) {
      (*a)();
      schluss = TRUE;
    } else {
      if (MASERR_history >= MASERR_confusion) {
        schluss = TRUE;
      }
    }
    if (!schluss && MASERR_history > MASERR_harmless) {
      WL();
      WS("Trying to restart program ... ", 30L);
      WL();
    }
  } while (!(schluss || f > maxerr));
  oldsig = signal(massig_SIGINT, massig_SIG_DFL);
  errhup = FALSE;
  return MASERR_history;
}

static INTEGER runtime
# ifdef __STDC__
(INTEGER e)
# else
(e)
INTEGER e;
# endif
{
  struct S_4 s;
  BOOLEAN abort;
  MASELEM_GAMMAINT err;
  massig_Action oldsig;
  INTEGER x;

  abort = TRUE;
  WL();
  lasterr = e;
  err = MASERR_fatal;
  switch (e) {
  case massig_SIGINT:;
    (void)strncpy(s.A, " Interrupt. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_severe;
    break;
  case massig_SIGILL:;
    (void)strncpy(s.A, " Illegal Instruction. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_fatal;
    break;
  case massig_SIGFPE:;
    (void)strncpy(s.A, " Floating Point Error. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_fatal;
    break;
  case massig_SIGBUS:;
    (void)strncpy(s.A, " Bus Error. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_fatal;
    break;
  case massig_SIGSEGV:;
    (void)strncpy(s.A, " Segmentation Error. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_fatal;
    break;
  case massig_SIGTERM:;
    (void)strncpy(s.A, " Terminate. ", sizeof(s.A));
    abort = FALSE;
    err = MASERR_harmless;
    break;
  default :
    (void)strncpy(s.A, " Unknown Error. ", sizeof(s.A));
    abort = TRUE;
    err = MASERR_fatal;
    break;
  }
  WI((MASELEM_GAMMAINT)e);
  WS(s.A, 101L);
  if (abort) {
    x = raise(e);
    exit(1);
  }
  oldsig = signal(e, runtime);
  MASERR_ERROR(err, "Signal received.", 16L);
  return 0;
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
(CHAR s[], LONGCARD O_2)
# else
(s, O_2)
CHAR s[];
LONGCARD O_2;
# endif
{
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_2 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(s, O_2, CHAR)
  StdIO_WriteS(s, O_2);
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

static void SysInfo
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT a, b, bp, i, c;

  STACK = MASmtc_getstck();
  WS("STACK END    = ", 15L);
  WH((MASELEM_GAMMAINT)STACKEND);
  WL();
  WS("STACK A1     = ", 15L);
  WH((MASELEM_GAMMAINT)STACK);
  WL();
  a = (MASELEM_GAMMAINT)MASmtc_gettoc();
  WS("      A2     = ", 15L);
  WH(a);
  WL();
}

void BEGIN_MASERR()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_MASmtc();
    BEGIN_setjmp();
    BEGIN_massig();
    BEGIN_StdIO();
    BEGIN_MASELEM();
    BEGIN_MASCONF();

    STACKEND = MASmtc_getstck();
    InitERR();
  }
}
