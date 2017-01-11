#include "SYSTEM_.h"

#ifndef DEFINITION_MASCONF
#include "MASCONF.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASLISP
#include "MASLISP.h"
#endif

#ifndef DEFINITION_MASSPEC
#include "MASSPEC.h"
#endif

#ifndef DEFINITION_MASLOAD
#include "MASLOAD.h"
#endif

#ifndef DEFINITION_MASU
#include "MASU.h"
#endif

static CHAR rcsidi [] = "$Id: MAS.mi,v 1.11 1995/11/05 09:01:14 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void CLTIS1 ARGS((MASSTOR_LIST C_9_A));
static void CLTIS2 ARGS((MASSTOR_LIST C_8_A));
static void INTERPRETE ARGS(());
static void REP ARGS(());
static void REPdebug ARGS(());


static void CLTIS1
# ifdef __STDC__
(MASSTOR_LIST C_9_A)
# else
(C_9_A)
MASSTOR_LIST C_9_A;
# endif
{
  MASSTOR_LIST AP, k, b;

  k = MASBIOS_CUNIT("RAM:internal1", 13L);
  k = MASBIOS_SOUNIT("RAM:internal1", 13L);
  AP = C_9_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &b, &AP);
    MASBIOS_CWRITE(b);
  }
  k = MASBIOS_CUNIT("RAM:internal1", 13L);
  k = MASBIOS_SIUNIT("RAM:internal1", 13L);
}

static void CLTIS2
# ifdef __STDC__
(MASSTOR_LIST C_8_A)
# else
(C_8_A)
MASSTOR_LIST C_8_A;
# endif
{
  MASSTOR_LIST AP, k, b;

  k = MASBIOS_CUNIT("RAM:internal2", 13L);
  k = MASBIOS_SOUNIT("RAM:internal2", 13L);
  AP = C_8_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &b, &AP);
    MASBIOS_CWRITE(b);
  }
  k = MASBIOS_CUNIT("RAM:internal2", 13L);
  k = MASBIOS_SIUNIT("RAM:internal2", 13L);
}

static void INTERPRETE
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST f;

  MASLOAD_InitExternals();
  MASU_InitExternalsU();
  if (MASCONF_OutFileName.A[0] != CHR(0)) {
    f = MASBIOS_SOUNIT(MASCONF_OutFileName.A, 256L);
  }
  if (MASCONF_ExitAfterFiles) {
    CLTIS1(MASBIOS_LISTS(".EXIT.", 6L));
  }
  if (MASCONF_FileName.A[0] != CHR(0)) {
    f = MASBIOS_SIUNIT(MASCONF_FileName.A, 256L);
  }
  if (MASCONF_InitialCommand.A[0] != CHR(0)) {
    CLTIS2(MASBIOS_LISTS(MASCONF_InitialCommand.A, 1003L));
  }
  if (MASCONF_InitName.A[0] != CHR(0)) {
    f = MASBIOS_SIUNIT(MASCONF_InitName.A, 256L);
  }
  f = MASERR_ErrorHandler(REP);
}

static void REP
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST S, Y, Z, T, r, e, p, t, c;
  BOOLEAN time;

  T = MASSTOR_TIME();
  r = T;
  e = T;
  p = T;
  c = 0;
  do {
    time = MASU_Time;
    if (time) {
      r = MASSTOR_TIME();
      c = MASSTOR_TAU;
    }
    Y = MASU_DoParse();
    if (time) {
      e = MASSTOR_TIME();
      r = e - r;
    }
    Z = MASSPEC_EVALUATE(Y, &MASLISP_ENV);
    MASBIOS_BLINES(0);
    if (time) {
      p = MASSTOR_TIME();
      e = p - e;
    }
    MASU_DoWrite(Z);
    if (time) {
      T = MASSTOR_TIME();
      p = T - p;
      c = MASSTOR_TAU - c;
      MASBIOS_SWRITE("Time: read = ", 13L);
      MASBIOS_GWRITE(r);
      MASBIOS_SWRITE(", eval = ", 9L);
      MASBIOS_GWRITE(e);
      MASBIOS_SWRITE(", print = ", 10L);
      MASBIOS_GWRITE(p);
      MASBIOS_SWRITE(", gc = ", 7L);
      MASBIOS_GWRITE(c);
      MASBIOS_SWRITE(".", 1L);
      MASBIOS_BLINES(0);
    }
  } while (!(Z == MASLISP_SCHLUSS || Z == MASLISP_schluss));
}

static void REPdebug
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST Y, Z, f;

  f = MASBIOS_SOUNIT("CON:debugO", 10L);
  f = MASBIOS_SIUNIT("CON:debugI", 10L);
  for (;;) {
    MASBIOS_SWRITE("DEBUG: ", 7L);
    Y = MASSYM_UREAD();
    Z = MASSPEC_EVALUATE(Y, &MASLISP_ENV);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("**ANS: ", 7L);
    MASSYM_UWRITE(Z);
    MASBIOS_BLINES(1);
    if (Z == MASLISP_SCHLUSS || Z == MASLISP_schluss) {
      goto EXIT_1;
    }
  } EXIT_1:;
  f = MASBIOS_CUNIT("CON:debugO", 10L);
  f = MASBIOS_CUNIT("CON:debugI", 10L);
}

void BEGIN_MODULE()
{
  BEGIN_MASCONF();
  BEGIN_MASSTOR();
  BEGIN_MASERR();
  BEGIN_MASBIOS();
  BEGIN_MASSYM();
  BEGIN_MASLISP();
  BEGIN_MASSPEC();
  BEGIN_MASLOAD();
  BEGIN_MASU();

  MASBIOS_BLINES(1);
  MASERR_DebugProcessor = REPdebug;
  INTERPRETE();
  MASBIOS_CloseBIOS();
}
