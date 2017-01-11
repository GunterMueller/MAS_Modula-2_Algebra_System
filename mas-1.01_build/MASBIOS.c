#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_IO
#include "IO.h"
#endif

#ifndef DEFINITION_Strings
#include "Strings.h"
#endif

#ifndef DEFINITION_Portab
#include "Portab.h"
#endif

#ifndef DEFINITION_massig
#include "massig.h"
#endif

#ifndef DEFINITION_maskpathsea
#include "maskpathsea.h"
#endif

#ifndef DEFINITION_masreadline
#include "masreadline.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

MASELEM_GAMMAINT MASBIOS_CHI;
CHAR MASBIOS_rcsid [] = "$Id: MASBIOS.md,v 1.6 1995/03/06 16:00:49 pesch Exp $";
CHAR MASBIOS_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define CCHI	150
#define ILEN	79
#define OLEN	79
#define itlen	255
#define islen	81
#define MAXFILE	29
#define undefstat	'U'
#define instat	'I'
#define outstat	'O'
#define clostat	'C'
#define anystat	'A'
typedef struct S_1 {
    CHAR stat;
    Strings_tString name;
    IO_tFile sysf;
    MASELEM_GAMMAINT sysq;
    INTEGER kind;
    INTEGER lmarg;
    INTEGER rmarg;
    INTEGER lpos;
    INTEGER llen;
    MASELEM_GAMMAINT ByteIO;
    MASELEM_GAMMAINT LineIO;
} FileDescriptor;
static struct S_2 {
    FileDescriptor A[MAXFILE - 1 + 1];
} stream;
static INTEGER Istream, Ostream, Estream;
static MASSTOR_LIST Istack, Ostack;
static struct S_3 {
    INTEGER A[CCHI - 1 + 1];
} ACODE, LCODE, SCODE;
static Strings_tString Sin;
static INTEGER again, itrace;
static struct S_4 {
    MASELEM_GAMMAINT A[itlen - 1 + 1];
} Tbuff;
static MASELEM_GAMMAINT blank;
static INTEGER ISIZE, ILMARG, IRMARG, IPOS, OSIZE, OLMARG, ORMARG, OPOS;
static MASELEM_GAMMAINT IBYTEIO, ILINEIO, OBYTEIO, OLINEIO;
static BOOLEAN INEWLINE, ONEWLINE, ECHO;
static CHAR rcsidi [] = "$Id: MASBIOS.mi,v 1.13 1996/06/08 18:26:51 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
struct S_14 {
    MASELEM_GAMMAINT A[20 - 1 + 1];
};
static void Hold ARGS(());
static void InitBIOS ARGS(());
static void INITCC ARGS(());
static void AddCode ARGS((CHAR S[], LONGCARD ));
static MASELEM_GAMMAINT input ARGS(());
static void output ARGS((MASELEM_GAMMAINT C));
static void Pause ARGS(());
static void ringclear ARGS(());
static MASELEM_GAMMAINT ringget ARGS(());
static void ringput ARGS((MASELEM_GAMMAINT I));
static void ringstring ARGS((Strings_tString S));
static void findslot ARGS((CHAR S[], LONGCARD , CHAR stat, INTEGER *old, INTEGER *slot));
static void saveold ARGS((INTEGER s));
static void storeold ARGS((INTEGER s));
static INTEGER detkind ARGS((CHAR S[], LONGCARD ));
static void popIstream ARGS(());
static void popOstream ARGS(());
static void pushstream ARGS((INTEGER s));
static MASELEM_GAMMAINT CioUNIT ARGS((INTEGER iold, INTEGER oold));
static void StWRITE ARGS((Strings_tString S));


void MASBIOS_BKSP
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (again < itlen) {
    again = again + 1;
    itrace = itrace - 1;
    if (itrace < 1) {
      itrace = itrace + itlen;
    }
  }
  m = sigsetmask(m);
}

void MASBIOS_BLINES
# ifdef __STDC__
(MASELEM_GAMMAINT N)
# else
(N)
MASELEM_GAMMAINT N;
# endif
{
  MASELEM_GAMMAINT i;
  INTEGER j;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  OPOS = ORMARG;
  i = 1;
  while (i <= N) {
    MASBIOS_CWRITE(blank);
    OPOS = ORMARG;
    i = i + 1;
  }
  m = sigsetmask(m);
}

MASELEM_GAMMAINT MASBIOS_CREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT C, D;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  IPOS = IPOS + 1;
  C = input();
  if (IPOS >= IRMARG) {
    IPOS = 0;
    INEWLINE = TRUE;
    ILINEIO = ILINEIO + 1;
    while (IPOS < ILMARG) {
      IPOS = IPOS + 1;
      D = input();
    }
  }
  m = sigsetmask(m);
  return C;
}

MASELEM_GAMMAINT MASBIOS_CREADB
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT C;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  do {
    C = MASBIOS_CREAD();
  } while (!(C != blank));
  m = sigsetmask(m);
  return C;
}

void MASBIOS_CWRITE
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  INTEGER i;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  OPOS = OPOS + 1;
  if (OPOS >= ORMARG) {
    OPOS = 0;
    ONEWLINE = TRUE;
    OLINEIO = OLINEIO + 1;
    while (OPOS < OLMARG) {
      OPOS = OPOS + 1;
      output(blank);
    }
  }
  output(C);
  m = sigsetmask(m);
}

void MASBIOS_DIBUFF
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i, j;
  MASELEM_GAMMAINT L;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Input buffer follows, last character read underscored.", 54L);
  MASBIOS_BLINES(0);
  j = itrace + itlen - 50;
  if (j > itlen) {
    j = j - itlen;
  }
  for (i = 1; i <= 50; i += 1) {
    j = j + 1;
    if (j > itlen) {
      j = j - itlen;
    }
    L = Tbuff.A[j - 1];
    MASBIOS_CWRITE(L);
  }
  MASBIOS_BLINES(0);
  for (i = 2; i <= 50 - 1; i += 1) {
    MASBIOS_CWRITE(blank);
  }
  MASBIOS_SWRITE("-", 1L);
  MASBIOS_BLINES(1);
  m = sigsetmask(m);
}

BOOLEAN MASBIOS_DIGIT
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  BOOLEAN t;

  if (C <= 9) {
    t = TRUE;
  } else {
    t = FALSE;
  }
  return t;
}

MASELEM_GAMMAINT MASBIOS_GREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT a, C, S;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  S = 1;
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('+')) {
    C = MASBIOS_CREADB();
  } else {
    if (C == MASBIOS_MASORD('-')) {
      C = MASBIOS_CREADB();
      S = -1;
    }
  }
  if (!MASBIOS_DIGIT(C)) {
    MASERR_ERROR(MASERR_harmless, "GREAD: digit expected.", 22L);
    MASBIOS_DIBUFF();
    m = sigsetmask(m);
    return 0;
  }
  a = 0;
  do {
    a = 10 * a + C;
    C = MASBIOS_CREAD();
  } while (!!MASBIOS_DIGIT(C));
  MASBIOS_BKSP();
  a = S * a;
  m = sigsetmask(m);
  return a;
}

void MASBIOS_GWRITE
# ifdef __STDC__
(MASELEM_GAMMAINT a)
# else
(a)
MASELEM_GAMMAINT a;
# endif
{
  struct S_14 D;
  MASELEM_GAMMAINT ap, q;
  INTEGER N;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (a < 0) {
    ap = -a;
    MASBIOS_SWRITE("-", 1L);
  } else {
    ap = a;
  }
  N = 0;
  do {
    q = ap / 10;
    N = N + 1;
    if (N > 20) {
      MASERR_ERROR(MASERR_harmless, "GWRITE: not a gamma-integer.", 28L);
      m = sigsetmask(m);
      return;
    }
    D.A[N - 1] = ap - 10 * q;
    ap = q;
  } while (!(ap == 0));
  do {
    MASBIOS_CWRITE(D.A[N - 1]);
    N = N - 1;
  } while (!(N == 0));
  m = sigsetmask(m);
}

static void Hold
# ifdef __STDC__
()
# else
()
# endif
{
  CHAR C;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  C = (CHAR)0;
  if (ORD(C) > 0) {
    if (C == Portab_esc) {
      MASERR_ERROR(MASERR_severe, "ESC key pressed.", 16L);
    }
    Pause();
  }
  m = sigsetmask(m);
}

static void InitBIOS
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER C, D, I, J;
  MASELEM_GAMMAINT S, T, R;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  for (I = 1; I <= MAXFILE; I += 1) {
    stream.A[I - 1].stat = undefstat;
    Strings_AssignEmpty(&stream.A[I - 1].name);
    stream.A[I - 1].ByteIO = 0;
    stream.A[I - 1].LineIO = 0;
    stream.A[I - 1].lmarg = 0;
    stream.A[I - 1].rmarg = ILEN;
    stream.A[I - 1].llen = ILEN;
    stream.A[I - 1].lpos = 0;
    MASSTOR_LISTVAR(&stream.A[I - 1].sysq);
  }
  Istream = 0;
  Ostream = 0;
  again = 0;
  itrace = 1;
  MASSTOR_LISTVAR(&Istack);
  MASSTOR_LISTVAR(&Ostack);
  ECHO = FALSE;
  Istack = MASSTOR_SIL;
  R = MASBIOS_SIUNIT("CON:", 4L);
  Ostack = MASSTOR_SIL;
  R = MASBIOS_SOUNIT("CON:", 4L);
  INITCC();
  {
    LONGINT B_1 = 1, B_2 = (INTEGER)MASBIOS_CHI;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        SCODE.A[I - 1] = LCODE.A[I - 1];
        ACODE.A[I - 1] = I - 1;
        if (I >= B_2) break;
      }
  }
  for (J = (INTEGER)MASBIOS_CHI - 1; J >= 1; J += -1) {
    {
      LONGINT B_3 = 1, B_4 = J;

      if (B_3 <= B_4)
        for (I = B_3;; I += 1) {
          C = SCODE.A[I - 1];
          D = SCODE.A[I + 1 - 1];
          S = MASELEM_MASSIGN((MASELEM_GAMMAINT)C);
          T = MASELEM_MASSIGN((MASELEM_GAMMAINT)D);
          if (S > T || S == T && C > D) {
            SCODE.A[I - 1] = D;
            SCODE.A[I + 1 - 1] = C;
            C = ACODE.A[I - 1];
            ACODE.A[I - 1] = ACODE.A[I + 1 - 1];
            ACODE.A[I + 1 - 1] = C;
          }
          if (I >= B_4) break;
        }
    }
  }
  blank = MASBIOS_MASORD(' ');
  ringclear();
  m = sigsetmask(m);
}

void MASBIOS_CloseBIOS
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER I, k, j;
  CHAR c;
  MASELEM_GAMMAINT K;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  while (MASSTOR_RED(Istack) != MASSTOR_SIL) {
    I = (INTEGER)MASSTOR_FIRST(Istack);
    Istack = MASSTOR_RED(Istack);
    c = stream.A[I - 1].stat;
    j = -1;
    if (c == instat) {
      j = CioUNIT(I, 0);
    }
    if (c == outstat) {
      j = CioUNIT(0, I);
    }
    if (j == 0) {
      MASBIOS_SWRITE("Stream ", 7L);
      StWRITE(stream.A[I - 1].name);
      MASBIOS_SWRITE(" closed successfully.", 21L);
      MASBIOS_BLINES(1);
    }
  }
  while (MASSTOR_RED(Ostack) != MASSTOR_SIL) {
    I = (INTEGER)MASSTOR_FIRST(Ostack);
    Ostack = MASSTOR_RED(Ostack);
    c = stream.A[I - 1].stat;
    j = -1;
    if (c == instat) {
      j = CioUNIT(I, 0);
    }
    if (c == outstat) {
      j = CioUNIT(0, I);
    }
    if (j == 0) {
      MASBIOS_SWRITE("Stream ", 7L);
      StWRITE(stream.A[I - 1].name);
      MASBIOS_SWRITE(" closed successfully.", 21L);
      MASBIOS_BLINES(1);
    }
  }
  for (I = 1; I <= MAXFILE; I += 1) {
    if (I != Istream && I != Ostream) {
      c = stream.A[I - 1].stat;
      j = -1;
      if (c == instat) {
        j = CioUNIT(I, 0);
      }
      if (c == outstat) {
        j = CioUNIT(0, I);
      }
      if (j == 0) {
        MASBIOS_SWRITE("Stream ", 7L);
        StWRITE(stream.A[I - 1].name);
        MASBIOS_SWRITE(" closed successfully.", 21L);
        MASBIOS_BLINES(1);
      }
    }
  }
  IO_CloseIO();
  m = sigsetmask(m);
}

static void INITCC
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  MASBIOS_CHI = 0;
  AddCode("0123456789", 10L);
  AddCode("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ", 52L);
  AddCode(".,=+-*/$() !", 12L);
  AddCode("\"", 1L);
  AddCode("#%&':;<>?@[\\]^_`{}|~", 20L);
  MASBIOS_CHI = MASBIOS_CHI + 1;
  LCODE.A[(INTEGER)MASBIOS_CHI - 1] = 254;
  MASBIOS_CHI = MASBIOS_CHI + 1;
  LCODE.A[(INTEGER)MASBIOS_CHI - 1] = (INTEGER)ORD(Portab_esc);
  m = sigsetmask(m);
}

static void AddCode
# ifdef __STDC__
(CHAR S[], LONGCARD O_1)
# else
(S, O_1)
CHAR S[];
LONGCARD O_1;
# endif
{
  INTEGER K;
  CARDINAL I;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_1 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_1, CHAR)
  K = MASBIOS_CHI;
  {
    LONGCARD B_5 = 0, B_6 = (O_1 - 1);

    if (B_5 <= B_6)
      for (I = B_5;; I += 1) {
        K = K + 1;
        LCODE.A[K - 1] = (INTEGER)ORD(S[I]);
        if (I >= B_6) break;
      }
  }
  MASBIOS_CHI = (MASELEM_GAMMAINT)K;
  FREE_OPEN_ARRAYS
}

BOOLEAN MASBIOS_LETTER
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  BOOLEAN t;

  if (C >= MASBIOS_MASORD('a') && C <= MASBIOS_MASORD('Z')) {
    t = TRUE;
  } else {
    t = FALSE;
  }
  return t;
}

static MASELEM_GAMMAINT input
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i, retry;
  CHAR c;
  MASELEM_GAMMAINT C, j;
  BOOLEAN ok;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (again > 0) {
    again = again - 1;
    IPOS = IPOS - 1;
    C = ringget();
    return C;
  }
  retry = MAXFILE;
  do {
    c = ' ';
    i = stream.A[Istream - 1].kind;
    switch (i) {
    case MASBIOS_ramkind:;
      ok = !MASSTOR_EMPTYQUE(stream.A[Istream - 1].sysq);
      if (ok) {
        C = MASSTOR_DEQUE(stream.A[Istream - 1].sysq);
        ringput(C);
      }
      break;
    case MASBIOS_termkind:;
      ok = TRUE;
      masReadL(&Sin);
      ringstring(Sin);
      C = ringget();
      if (stream.A[Ostream - 1].kind == MASBIOS_termkind) {
        IO_WriteNl(IO_StdOutput);
        IO_WriteFlush(IO_StdOutput);
      }
      break;
    case MASBIOS_diskkind:;
      do {
        ok = !IO_EndOfFile(stream.A[Istream - 1].sysf);
        if (ok) {
          c = IO_ReadC(stream.A[Istream - 1].sysf);
        }
      } while (!(c >= ' ' || !ok));
      if (ok) {
        C = MASBIOS_MASORD(c);
      } else {
        C = blank;
      }
      ringput(C);
      break;
    case MASBIOS_winkind:;
      ok = FALSE;
      break;
    case MASBIOS_nulkind:;
      ok = FALSE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      j = CioUNIT(Istream, 0);
      retry = retry - 1;
      if (retry < 0) {
        c = Portab_esc;
        ok = TRUE;
      }
      ringclear();
    }
  } while (!ok);
  if (c == Portab_esc) {
    MASERR_ERROR(MASERR_severe, "INPUT: ESC key pressed.", 23L);
  }
  IBYTEIO = IBYTEIO + 1;
  m = sigsetmask(m);
  return C;
}

MASSTOR_LIST MASBIOS_LISTS
# ifdef __STDC__
(CHAR S[], LONGCARD O_2)
# else
(S, O_2)
CHAR S[];
LONGCARD O_2;
# endif
{
  INTEGER I, J;
  MASELEM_GAMMAINT II;
  MASSTOR_LIST L;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_2 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_2, CHAR)
  J = (INTEGER)(O_2 - 1);
  I = 0;
  L = MASSTOR_SIL;
  while (I <= J && S[I] != Portab_nul) {
    II = MASBIOS_MASORD(S[I]);
    L = MASSTOR_COMP(II, L);
    I = I + 1;
  }
  L = MASSTOR_INV(L);
  FREE_OPEN_ARRAYS
  return L;
}

void MASBIOS_SLIST
# ifdef __STDC__
(MASSTOR_LIST C_2_A, CHAR S[], LONGCARD O_3)
# else
(C_2_A, S, O_3)
MASSTOR_LIST C_2_A;
CHAR S[];
LONGCARD O_3;
# endif
{
  MASELEM_GAMMAINT I;
  MASSTOR_LIST AP;
  INTEGER i;

  AP = C_2_A;
  S[0] = Portab_nul;
  i = -1;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &I, &AP);
    if (I < MASSTOR_SIL) {
      i = i + 1;
      S[i] = MASBIOS_MASCHR(I);
    }
  }
  S[i + 1] = Portab_nul;
}

CHAR MASBIOS_MASCHR
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  INTEGER i;
  CHAR c;

  if (0 <= C && C <= MASBIOS_CHI) {
    i = (INTEGER)C;
  } else {
    MASERR_ERROR(MASERR_spotless, "Non-standard character to convert. ", 35L);
    MASBIOS_GWRITE(C);
    MASBIOS_SWRITE(" ", 1L);
    i = (INTEGER)blank;
  }
  c = CHR(LCODE.A[i + 1 - 1]);
  return c;
}

MASELEM_GAMMAINT MASBIOS_MASORD
# ifdef __STDC__
(CHAR C)
# else
(C)
CHAR C;
# endif
{
  MASELEM_GAMMAINT D;

  D = (MASELEM_GAMMAINT)ORD(C);
  D = MASBIOS_MASORDI(D);
  return D;
}

MASELEM_GAMMAINT MASBIOS_MASORDI
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  INTEGER CC, D, J, L, M, U, KK;
  MASELEM_GAMMAINT K;

  CC = (INTEGER)C;
  L = 1;
  U = (INTEGER)MASBIOS_CHI;
  do {
    J = L + U;
    M = J / 2;
    D = SCODE.A[M - 1];
    if (CC < 0 && (D >= 0 || CC <= D) || D > 0 && CC <= D) {
      U = M;
    } else {
      L = M + 1;
    }
  } while (!(L == U));
  if (CC == SCODE.A[L - 1]) {
    KK = ACODE.A[L - 1];
  } else {
    MASERR_ERROR(MASERR_spotless, "Non-standard character to convert. ", 35L);
    MASBIOS_GWRITE(C);
    MASBIOS_SWRITE(" ", 1L);
    KK = (INTEGER)blank;
  }
  K = (MASELEM_GAMMAINT)KK;
  return K;
}

static void output
# ifdef __STDC__
(MASELEM_GAMMAINT C)
# else
(C)
MASELEM_GAMMAINT C;
# endif
{
  INTEGER i, retry;
  CHAR c;
  BOOLEAN ok;
  MASELEM_GAMMAINT j;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  retry = MAXFILE;
  do {
    i = stream.A[Ostream - 1].kind;
    switch (i) {
    case MASBIOS_ramkind:;
      MASSTOR_ENQUE(C, stream.A[Ostream - 1].sysq);
      ok = !MASSTOR_EMPTYQUE(stream.A[Ostream - 1].sysq);
      break;
    case MASBIOS_termkind:;
      if (ONEWLINE) {
        ONEWLINE = FALSE;
        IO_WriteNl(IO_StdOutput);
        IO_WriteFlush(IO_StdOutput);
      }
      c = MASBIOS_MASCHR(C);
      IO_WriteC(IO_StdOutput, c);
      IO_WriteFlush(IO_StdOutput);
      ok = TRUE;
      break;
    case MASBIOS_diskkind:;
      if (ONEWLINE) {
        ONEWLINE = FALSE;
        IO_WriteNl(stream.A[Ostream - 1].sysf);
      }
      c = MASBIOS_MASCHR(C);
      IO_WriteC(stream.A[Ostream - 1].sysf, c);
      ok = TRUE;
      break;
    case MASBIOS_winkind:;
      ok = TRUE;
      break;
    case MASBIOS_nulkind:;
      ok = TRUE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      j = CioUNIT(0, Ostream);
      retry = retry - 1;
      if (retry < 0) {
        MASERR_ERROR(MASERR_fatal, "No output possible.", 19L);
      }
    }
  } while (!ok);
  OBYTEIO = OBYTEIO + 1;
  m = sigsetmask(m);
}

static void Pause
# ifdef __STDC__
()
# else
()
# endif
{
  CHAR C;

  C = IO_ReadC(IO_StdInput);
}

static void ringclear
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  for (i = 1; i <= itlen; i += 1) {
    Tbuff.A[i - 1] = blank;
  }
  m = sigsetmask(m);
}

static MASELEM_GAMMAINT ringget
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT I;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  I = Tbuff.A[itrace - 1];
  itrace = itrace + 1;
  if (itrace > itlen) {
    itrace = itrace - itlen;
  }
  m = sigsetmask(m);
  return I;
}

static void ringput
# ifdef __STDC__
(MASELEM_GAMMAINT I)
# else
(I)
MASELEM_GAMMAINT I;
# endif
{
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  Tbuff.A[itrace - 1] = I;
  itrace = itrace + 1;
  if (itrace > itlen) {
    itrace = itrace - itlen;
  }
  m = sigsetmask(m);
}

static void ringstring
# ifdef __STDC__
(Strings_tString S)
# else
(S)
Strings_tString S;
# endif
{
  INTEGER i, k, l;
  MASELEM_GAMMAINT j;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  l = Strings_Length(&S);
  if (l > ISIZE) {
    l = ISIZE;
  }
  again = again + ISIZE;
  k = itrace;
  i = 1;
  while (i <= l) {
    if (Strings_Char(&S, i) == Portab_bs) {
      k = k - 1;
      if (k < 1) {
        k = k + itlen;
      }
    } else if (Strings_Char(&S, i) == Portab_del) {
      i = i + 1;
    } else {
      Tbuff.A[k - 1] = MASBIOS_MASORD(Strings_Char(&S, i));
      k = k + 1;
    }
    if (k > itlen) {
      k = k - itlen;
    }
    i = i + 1;
  }
  while (i < ISIZE) {
    Tbuff.A[k - 1] = blank;
    k = k + 1;
    if (k > itlen) {
      k = k - itlen;
    }
    i = i + 1;
  }
  m = sigsetmask(m);
}

static void findslot
# ifdef __STDC__
(CHAR S[], LONGCARD O_4, CHAR stat, INTEGER *old, INTEGER *slot)
# else
(S, O_4, stat, old, slot)
CHAR S[];
LONGCARD O_4;
CHAR stat;
INTEGER *old, *slot;
# endif
{
  INTEGER i;
  BOOLEAN da, gl;
  Strings_tString sp;
  INTEGER m;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_4 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_4, CHAR)
  m = sigblock(SigMask(massig_SIGUSR1));
  *slot = 0;
  *old = 0;
  Strings_ArrayToString(S, O_4, &sp);
  for (i = 1; i <= MAXFILE; i += 1) {
    if (stream.A[i - 1].stat == undefstat) {
      *slot = i;
    }
    da = Strings_IsEqual(&sp, &stream.A[i - 1].name);
    if (stat == anystat) {
      gl = TRUE;
    } else {
      gl = stream.A[i - 1].stat == stat || stream.A[i - 1].stat == clostat;
    }
    if (da && gl) {
      *old = i;
    }
  }
  if (*old > 0) {
    *slot = *old;
  }
  m = sigsetmask(m);
  FREE_OPEN_ARRAYS
}

static void saveold
# ifdef __STDC__
(INTEGER s)
# else
(s)
INTEGER s;
# endif
{
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (s < 1 || s > MAXFILE) {
    MASERR_ERROR(MASERR_severe, "saveold: stream out of range.", 29L);
    return;
  }
  if (stream.A[s - 1].stat == instat) {
    stream.A[s - 1].lmarg = ILMARG;
    stream.A[s - 1].rmarg = IRMARG;
    stream.A[s - 1].llen = ISIZE;
    stream.A[s - 1].lpos = IPOS;
    stream.A[s - 1].ByteIO = IBYTEIO;
    stream.A[s - 1].LineIO = ILINEIO;
  }
  if (stream.A[s - 1].stat == outstat) {
    stream.A[s - 1].lmarg = OLMARG;
    stream.A[s - 1].rmarg = ORMARG;
    stream.A[s - 1].llen = OSIZE;
    stream.A[s - 1].lpos = OPOS;
    stream.A[s - 1].ByteIO = OBYTEIO;
    stream.A[s - 1].LineIO = OLINEIO;
  }
  m = sigsetmask(m);
}

static void storeold
# ifdef __STDC__
(INTEGER s)
# else
(s)
INTEGER s;
# endif
{
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (s < 1 || s > MAXFILE) {
    MASERR_ERROR(MASERR_severe, "storeold: stream out of range.", 30L);
    m = sigsetmask(m);
    return;
  }
  if (stream.A[s - 1].stat == instat) {
    ILMARG = stream.A[s - 1].lmarg;
    IRMARG = stream.A[s - 1].rmarg;
    ISIZE = stream.A[s - 1].llen;
    IPOS = stream.A[s - 1].lpos;
    IBYTEIO = stream.A[s - 1].ByteIO;
    ILINEIO = stream.A[s - 1].LineIO;
  }
  if (stream.A[s - 1].stat == outstat) {
    OLMARG = stream.A[s - 1].lmarg;
    ORMARG = stream.A[s - 1].rmarg;
    OSIZE = stream.A[s - 1].llen;
    OPOS = stream.A[s - 1].lpos;
    OBYTEIO = stream.A[s - 1].ByteIO;
    OLINEIO = stream.A[s - 1].LineIO;
  }
  m = sigsetmask(m);
}

static INTEGER detkind
# ifdef __STDC__
(CHAR S[], LONGCARD O_5)
# else
(S, O_5)
CHAR S[];
LONGCARD O_5;
# endif
{
  INTEGER k;
  CARDINAL w;
  Strings_tString sp, sp1, pre;
  INTEGER m;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_5 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_5, CHAR)
  m = sigblock(SigMask(massig_SIGUSR1));
  k = MASBIOS_diskkind;
  Strings_ArrayToString(S, O_5, &sp1);
  Strings_SubString(&sp1, 1, 4, &sp);
  Strings_ArrayToString("CON:", 4L, &pre);
  if (Strings_IsEqual(&sp, &pre)) {
    k = MASBIOS_termkind;
  }
  Strings_ArrayToString("WIN:", 4L, &pre);
  if (Strings_IsEqual(&sp, &pre)) {
    k = MASBIOS_winkind;
  }
  Strings_ArrayToString("RAM:", 4L, &pre);
  if (Strings_IsEqual(&sp, &pre)) {
    k = MASBIOS_ramkind;
  }
  Strings_ArrayToString("NUL:", 4L, &pre);
  if (Strings_IsEqual(&sp, &pre)) {
    k = MASBIOS_nulkind;
  }
  Strings_ArrayToString("GRA:", 4L, &pre);
  if (Strings_IsEqual(&sp, &pre)) {
    k = MASBIOS_termkind;
  }
  m = sigsetmask(m);
  FREE_OPEN_ARRAYS
  return k;
}

static void popIstream
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER s, slot;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  slot = (INTEGER)MASSTOR_FIRST(Istack);
  if (MASSTOR_RED(Istack) != MASSTOR_SIL && slot == Istream) {
    Istack = MASSTOR_RED(Istack);
    slot = (INTEGER)MASSTOR_FIRST(Istack);
  }
  s = Istream;
  Istream = slot;
  saveold(s);
  storeold(slot);
  if (stream.A[slot - 1].stat == clostat) {
    popIstream();
  }
  m = sigsetmask(m);
}

static void popOstream
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER s, slot;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  slot = (INTEGER)MASSTOR_FIRST(Ostack);
  if (MASSTOR_RED(Ostack) != MASSTOR_SIL && slot == Ostream) {
    Ostack = MASSTOR_RED(Ostack);
    slot = (INTEGER)MASSTOR_FIRST(Ostack);
  }
  s = Ostream;
  Ostream = slot;
  saveold(s);
  storeold(slot);
  if (stream.A[slot - 1].stat == clostat) {
    popOstream();
  }
  m = sigsetmask(m);
}

static void pushstream
# ifdef __STDC__
(INTEGER s)
# else
(s)
INTEGER s;
# endif
{
  INTEGER i;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  switch (stream.A[s - 1].stat) {
  case outstat:;
    if (Ostream > 0) {
      saveold(Ostream);
    }
    Ostack = MASSTOR_COMP((MASELEM_GAMMAINT)s, Ostack);
    Ostream = s;
    break;
  case instat:;
    if (Istream > 0) {
      saveold(Istream);
    }
    Istack = MASSTOR_COMP((MASELEM_GAMMAINT)s, Istack);
    Istream = s;
    break;
  default :
    break;
  }
  storeold(s);
  m = sigsetmask(m);
}

MASELEM_GAMMAINT MASBIOS_CUNIT
# ifdef __STDC__
(CHAR S[], LONGCARD O_6)
# else
(S, O_6)
CHAR S[];
LONGCARD O_6;
# endif
{
  INTEGER iold, oold, slot, k;
  BOOLEAN ok;
  INTEGER m;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_6 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_6, CHAR)
  m = sigblock(SigMask(massig_SIGUSR1));
  findslot(S, O_6, instat, &iold, &slot);
  findslot(S, O_6, outstat, &oold, &slot);
  if (Istream == iold) {
    popIstream();
  }
  if (Ostream == oold) {
    popOstream();
  }
  if (iold > 0) {
    k = stream.A[iold - 1].kind;
    switch (k) {
    case MASBIOS_termkind:;
      ok = TRUE;
      break;
    case MASBIOS_ramkind:;
      ok = TRUE;
      break;
    case MASBIOS_winkind:;
      ok = TRUE;
      break;
    case MASBIOS_nulkind:;
      ok = TRUE;
      break;
    case MASBIOS_diskkind:;
      IO_ReadClose(stream.A[iold - 1].sysf);
      ok = TRUE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      MASERR_ERROR(MASERR_harmless, "Cannot close requested stream. ", 31L);
      m = sigsetmask(m);
      {
        LONGINT R_1 = (MASELEM_GAMMAINT)iold;

        FREE_OPEN_ARRAYS
        return R_1;
      }
    }
    stream.A[iold - 1].stat = clostat;
  }
  if (oold > 0) {
    k = stream.A[oold - 1].kind;
    switch (k) {
    case MASBIOS_termkind:;
      ok = TRUE;
      break;
    case MASBIOS_ramkind:;
      ok = TRUE;
      break;
    case MASBIOS_winkind:;
      ok = TRUE;
      break;
    case MASBIOS_nulkind:;
      ok = TRUE;
      break;
    case MASBIOS_diskkind:;
      IO_WriteClose(stream.A[oold - 1].sysf);
      ok = TRUE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      MASERR_ERROR(MASERR_harmless, "Cannot close requested stream. ", 31L);
      m = sigsetmask(m);
      {
        LONGINT R_2 = (MASELEM_GAMMAINT)oold;

        FREE_OPEN_ARRAYS
        return R_2;
      }
    }
    stream.A[oold - 1].stat = clostat;
  }
  m = sigsetmask(m);
  FREE_OPEN_ARRAYS
  return 0;
}

static MASELEM_GAMMAINT CioUNIT
# ifdef __STDC__
(INTEGER iold, INTEGER oold)
# else
(iold, oold)
INTEGER iold, oold;
# endif
{
  INTEGER slot, k;
  BOOLEAN ok;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  if (Istream == iold) {
    popIstream();
  }
  if (Ostream == oold) {
    popOstream();
  }
  if (iold > 0) {
    k = stream.A[iold - 1].kind;
    switch (k) {
    case MASBIOS_termkind:;
      ok = TRUE;
      break;
    case MASBIOS_ramkind:;
      ok = TRUE;
      break;
    case MASBIOS_winkind:;
      ok = TRUE;
      break;
    case MASBIOS_nulkind:;
      ok = TRUE;
      break;
    case MASBIOS_diskkind:;
      IO_ReadClose(stream.A[iold - 1].sysf);
      ok = TRUE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      MASERR_ERROR(MASERR_harmless, "Cannot close requested stream. ", 31L);
      m = sigsetmask(m);
      return (MASELEM_GAMMAINT)iold;
    }
    stream.A[iold - 1].stat = clostat;
  }
  if (oold > 0) {
    k = stream.A[oold - 1].kind;
    switch (k) {
    case MASBIOS_termkind:;
      ok = TRUE;
      break;
    case MASBIOS_ramkind:;
      ok = TRUE;
      break;
    case MASBIOS_winkind:;
      ok = TRUE;
      break;
    case MASBIOS_nulkind:;
      ok = TRUE;
      break;
    case MASBIOS_diskkind:;
      IO_WriteClose(stream.A[oold - 1].sysf);
      ok = TRUE;
      break;
    default :
      ok = FALSE;
      break;
    }
    if (!ok) {
      MASERR_ERROR(MASERR_harmless, "Cannot close requested stream. ", 31L);
      m = sigsetmask(m);
      return (MASELEM_GAMMAINT)oold;
    }
    stream.A[oold - 1].stat = clostat;
  }
  m = sigsetmask(m);
  return 0;
}

MASELEM_GAMMAINT MASBIOS_SIUNIT
# ifdef __STDC__
(CHAR S[], LONGCARD O_7)
# else
(S, O_7)
CHAR S[];
LONGCARD O_7;
# endif
{
  INTEGER i, slot, old, sp, k;
  MASELEM_GAMMAINT INI;
  BOOLEAN ok;
  INTEGER m;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_7 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_7, CHAR)
  m = sigblock(SigMask(massig_SIGUSR1));
  findslot(S, O_7, instat, &old, &slot);
  if (slot == 0) {
    MASERR_ERROR(MASERR_severe, "Maximal number of Files is allready in use. ", 44L);
    m = sigsetmask(m);
    FREE_OPEN_ARRAYS
    return 1;
  }
  if (old > 0) {
    saveold(Istream);
    storeold(old);
    Istream = old;
    if (stream.A[old - 1].stat == instat) {
      m = sigsetmask(m);
      FREE_OPEN_ARRAYS
      return 0;
    }
  }
  if (old == 0) {
    k = detkind(S, O_7);
    stream.A[slot - 1].kind = k;
  } else {
    k = stream.A[slot - 1].kind;
  }
  switch (k) {
  case MASBIOS_termkind:;
    ok = TRUE;
    ECHO = FALSE;
    break;
  case MASBIOS_ramkind:;
    INI = MASSTOR_NEWQUE();
    findslot(S, O_7, anystat, &old, &sp);
    if (old > 0) {
      INI = stream.A[old - 1].sysq;
    }
    stream.A[slot - 1].sysq = INI;
    ok = TRUE;
    ECHO = FALSE;
    break;
  case MASBIOS_winkind:;
    ok = TRUE;
    ECHO = FALSE;
    break;
  case MASBIOS_nulkind:;
    ok = TRUE;
    ECHO = FALSE;
    break;
  case MASBIOS_diskkind:;
    stream.A[slot - 1].sysf = masReadOpen(S, O_7);
    if (stream.A[slot - 1].sysf < 0) {
      MASERR_ERROR(MASERR_harmless, S, O_7);
      MASERR_ERROR(MASERR_harmless, "Cannot open file. ", 18L);
      m = sigsetmask(m);
      {
        LONGINT R_3 = (MASELEM_GAMMAINT)slot;

        FREE_OPEN_ARRAYS
        return R_3;
      }
    }
    ok = TRUE;
    ECHO = TRUE;
    break;
  default :
    ok = FALSE;
    break;
  }
  if (!ok) {
    MASERR_ERROR(MASERR_harmless, "Cannot open requested stream. ", 30L);
    m = sigsetmask(m);
    {
      LONGINT R_4 = (MASELEM_GAMMAINT)slot;

      FREE_OPEN_ARRAYS
      return R_4;
    }
  }
  if (old == 0) {
    Strings_ArrayToString(S, O_7, &stream.A[slot - 1].name);
  }
  stream.A[slot - 1].stat = instat;
  INEWLINE = FALSE;
  pushstream(slot);
  m = sigsetmask(m);
  FREE_OPEN_ARRAYS
  return 0;
}

MASELEM_GAMMAINT MASBIOS_SOUNIT
# ifdef __STDC__
(CHAR S[], LONGCARD O_8)
# else
(S, O_8)
CHAR S[];
LONGCARD O_8;
# endif
{
  INTEGER i, slot, old, k, sp;
  BOOLEAN ok;
  MASELEM_GAMMAINT INI;
  INTEGER m;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_8 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_8, CHAR)
  m = sigblock(SigMask(massig_SIGUSR1));
  findslot(S, O_8, outstat, &old, &slot);
  if (slot == 0) {
    MASERR_ERROR(MASERR_severe, "Maximal number of Files is allready in use. ", 44L);
    m = sigsetmask(m);
    FREE_OPEN_ARRAYS
    return 1;
  }
  if (old > 0) {
    saveold(Ostream);
    storeold(old);
    Ostream = old;
    if (stream.A[old - 1].stat == outstat) {
      m = sigsetmask(m);
      FREE_OPEN_ARRAYS
      return 0;
    }
  }
  if (old == 0) {
    k = detkind(S, O_8);
    stream.A[slot - 1].kind = k;
  } else {
    k = stream.A[slot - 1].kind;
  }
  switch (k) {
  case MASBIOS_termkind:;
    ok = TRUE;
    break;
  case MASBIOS_ramkind:;
    INI = MASSTOR_NEWQUE();
    findslot(S, O_8, anystat, &old, &sp);
    if (old > 0) {
      INI = stream.A[old - 1].sysq;
    }
    stream.A[slot - 1].sysq = INI;
    ok = TRUE;
    break;
  case MASBIOS_winkind:;
    ok = TRUE;
    break;
  case MASBIOS_nulkind:;
    ok = TRUE;
    break;
  case MASBIOS_diskkind:;
    stream.A[slot - 1].sysf = IO_WriteOpen(S, O_8);
    if (stream.A[slot - 1].sysf < 0) {
      ok = FALSE;
    }
    ok = TRUE;
    break;
  default :
    ok = FALSE;
    break;
  }
  if (!ok) {
    MASERR_ERROR(MASERR_harmless, S, O_8);
    MASERR_ERROR(MASERR_harmless, "Cannot open requested stream. ", 30L);
    m = sigsetmask(m);
    {
      LONGINT R_5 = (MASELEM_GAMMAINT)slot;

      FREE_OPEN_ARRAYS
      return R_5;
    }
  }
  if (old == 0) {
    Strings_ArrayToString(S, O_8, &stream.A[slot - 1].name);
  }
  stream.A[slot - 1].stat = outstat;
  ONEWLINE = FALSE;
  pushstream(slot);
  m = sigsetmask(m);
  FREE_OPEN_ARRAYS
  return 0;
}

void MASBIOS_SILINE
# ifdef __STDC__
(MASELEM_GAMMAINT *S, MASELEM_GAMMAINT *L, MASELEM_GAMMAINT *R)
# else
(S, L, R)
MASELEM_GAMMAINT *S, *L, *R;
# endif
{
  MASELEM_GAMMAINT S1, L1, R1;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  S1 = (MASELEM_GAMMAINT)ISIZE;
  L1 = (MASELEM_GAMMAINT)ILMARG;
  R1 = (MASELEM_GAMMAINT)IRMARG;
  if (*S > 0) {
    ISIZE = (INTEGER)(*S);
  }
  if (*R > 0) {
    IRMARG = (INTEGER)(*R);
  }
  if (*L >= 0) {
    ILMARG = (INTEGER)(*L);
  }
  if (IRMARG > ISIZE) {
    IRMARG = ISIZE;
  }
  if (ILMARG >= IRMARG) {
    ILMARG = IRMARG - 1;
  }
  *S = S1;
  *L = L1;
  *R = R1;
  m = sigsetmask(m);
}

void MASBIOS_SOLINE
# ifdef __STDC__
(MASELEM_GAMMAINT *S, MASELEM_GAMMAINT *L, MASELEM_GAMMAINT *R)
# else
(S, L, R)
MASELEM_GAMMAINT *S, *L, *R;
# endif
{
  MASELEM_GAMMAINT S1, L1, R1;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  S1 = (MASELEM_GAMMAINT)OSIZE;
  L1 = (MASELEM_GAMMAINT)OLMARG;
  R1 = (MASELEM_GAMMAINT)ORMARG;
  if (*S > 0) {
    OSIZE = (INTEGER)(*S);
  }
  if (*R > 0) {
    ORMARG = (INTEGER)(*R);
  }
  if (*L >= 0) {
    OLMARG = (INTEGER)(*L);
  }
  if (ORMARG > OSIZE) {
    ORMARG = OSIZE;
  }
  if (OLMARG >= ORMARG) {
    OLMARG = ORMARG - 1;
  }
  *S = S1;
  *L = L1;
  *R = R1;
  m = sigsetmask(m);
}

void MASBIOS_Summary
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i;
  MASELEM_GAMMAINT j;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Summary of stream IO ", 21L);
  MASBIOS_BLINES(1);
  j = 0;
  for (i = 1; i <= MAXFILE; i += 1) {
    if (stream.A[i - 1].stat != undefstat) {
      j = j + 1;
      if (i == Istream) {
        saveold(i);
      }
      if (i == Ostream) {
        saveold(i);
      }
      MASBIOS_SWRITE("Name     ", 9L);
      StWRITE(stream.A[i - 1].name);
      MASBIOS_SWRITE(", ", 2L);
      MASBIOS_BLINES(0);
      switch (stream.A[i - 1].stat) {
      case instat:;
        MASBIOS_SWRITE("Input,   ", 9L);
        break;
      case outstat:;
        MASBIOS_SWRITE("Output,  ", 9L);
        break;
      case clostat:;
        MASBIOS_SWRITE("Closed,  ", 9L);
        break;
      default :
        MASBIOS_SWRITE("Unknown, ", 9L);
        break;
      }
      MASBIOS_SWRITE("Byte-IO ", 8L);
      MASBIOS_GWRITE(stream.A[i - 1].ByteIO);
      MASBIOS_SWRITE(", Line-IO ", 10L);
      MASBIOS_GWRITE(stream.A[i - 1].LineIO);
      MASBIOS_SWRITE(", Lmarg ", 8L);
      MASBIOS_GWRITE((MASELEM_GAMMAINT)stream.A[i - 1].lmarg);
      MASBIOS_SWRITE(", Rmarg ", 8L);
      MASBIOS_GWRITE((MASELEM_GAMMAINT)stream.A[i - 1].rmarg);
      MASBIOS_SWRITE(", Size ", 7L);
      MASBIOS_GWRITE((MASELEM_GAMMAINT)stream.A[i - 1].llen);
      MASBIOS_SWRITE(". ", 2L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(j);
  MASBIOS_SWRITE(" Files used. ", 13L);
  MASBIOS_BLINES(1);
  m = sigsetmask(m);
}

void MASBIOS_StorSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST ML, NL, TL;

  MASBIOS_BLINES(1);
  ML = MASSTOR_GCC;
  NL = MASSTOR_GCCC;
  TL = MASSTOR_TAU;
  MASBIOS_GWRITE(ML);
  MASBIOS_SWRITE(" garbage collections, ", 22L);
  MASBIOS_GWRITE(NL);
  MASBIOS_SWRITE(" cells reclaimed, in ", 21L);
  MASBIOS_GWRITE(TL);
  MASBIOS_SWRITE(" milliseconds.", 14L);
  MASBIOS_BLINES(0);
  NL = MASSTOR_CELLS();
  TL = MASSTOR_TIME() - MASSTOR_TAU0;
  MASBIOS_GWRITE(NL);
  MASBIOS_SWRITE(" cells used, in ", 16L);
  MASBIOS_GWRITE(TL);
  MASBIOS_SWRITE(" milliseconds.", 14L);
  MASBIOS_BLINES(0);
  TL = MASSTOR_CLOCK() - MASSTOR_TAU0;
  MASBIOS_GWRITE(MASSTOR_NU);
  MASBIOS_SWRITE(" cells allocated. ", 18L);
  MASBIOS_SWRITE("Total time ", 11L);
  MASBIOS_GWRITE(TL);
  MASBIOS_SWRITE(" milliseconds.", 14L);
  MASBIOS_BLINES(0);
}

void MASBIOS_SWRITE
# ifdef __STDC__
(CHAR S[], LONGCARD O_9)
# else
(S, O_9)
CHAR S[];
LONGCARD O_9;
# endif
{
  CARDINAL i, l;
  MASELEM_GAMMAINT C;
  OPEN_ARRAY_LOCALS

  ALLOC_OPEN_ARRAYS(O_9 * sizeof(CHAR), 1)
  COPY_OPEN_ARRAY(S, O_9, CHAR)
  i = 0;
  l = (O_9 - 1);
  do {
    if (S[i] != Portab_nul) {
      C = MASBIOS_MASORD(S[i]);
      MASBIOS_CWRITE(C);
    } else {
      FREE_OPEN_ARRAYS
      return;
    }
    i = i + 1;
  } while (!(i > l));
  FREE_OPEN_ARRAYS
}

static void StWRITE
# ifdef __STDC__
(Strings_tString S)
# else
(S)
Strings_tString S;
# endif
{
  CARDINAL i, l;
  MASELEM_GAMMAINT C;

  l = Strings_Length(&S);
  i = 0;
  while (i < l) {
    i = i + 1;
    C = MASBIOS_MASORD(Strings_Char(&S, i));
    MASBIOS_CWRITE(C);
  }
}

void MASBIOS_TAB
# ifdef __STDC__
(MASELEM_GAMMAINT N)
# else
(N)
MASELEM_GAMMAINT N;
# endif
{
  INTEGER n;
  INTEGER m;

  m = sigblock(SigMask(massig_SIGUSR1));
  n = (INTEGER)N;
  if (OLMARG < n && n <= ORMARG) {
    while (OPOS < n) {
      MASBIOS_CWRITE(blank);
    }
  }
  m = sigsetmask(m);
}

INTEGER MASBIOS_IStreamKind
# ifdef __STDC__
()
# else
()
# endif
{
  return stream.A[Istream - 1].kind;
}

INTEGER MASBIOS_OStreamKind
# ifdef __STDC__
()
# else
()
# endif
{
  return stream.A[Ostream - 1].kind;
}

INTEGER MASBIOS_EStreamKind
# ifdef __STDC__
()
# else
()
# endif
{
  return stream.A[Estream - 1].kind;
}

void BEGIN_MASBIOS()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_IO();
    BEGIN_Strings();
    BEGIN_Portab();
    BEGIN_massig();
    BEGIN_maskpathsea();
    BEGIN_masreadline();

    InitBIOS();
  }
}
