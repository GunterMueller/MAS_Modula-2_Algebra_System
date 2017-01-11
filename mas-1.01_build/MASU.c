#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

#ifndef DEFINITION_MASREP
#include "MASREP.h"
#endif

#ifndef DEFINITION_MASPARSE
#include "MASPARSE.h"
#endif

#ifndef DEFINITION_ALDPARSE
#include "ALDPARSE.h"
#endif

#ifndef DEFINITION_MASU
#include "MASU.h"
#endif

BOOLEAN MASU_Time, MASU_Debug, MASU_PromptFirst;
INTEGER MASU_WroteChars, MASU_PromptType;
CHAR MASU_rcsid [] = "$Id: MASU.md,v 1.4 1995/09/12 17:24:39 pesch Exp $";
CHAR MASU_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

#define mas	0
#define lisp	1
#define aldes	2
#define time	3
#define debug	4
#define Trace	5
#define fussy	6
#define sloppy	7
#define genparse	8
typedef unsigned char pragmas;
static MASSTOR_LIST M2S, LSP, ALD, TME, DBG, SHOW, TRC, FUS, SLO, GENP;
static pragmas Parser;
static BOOLEAN genparsing;
static MASSTOR_LIST alls, modname, comment, loaded, listi;
#define PIND	0
#define FIND	-1
static CHAR rcsidi [] = "$Id: MASU.mi,v 1.8 1995/11/05 09:02:44 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void DumpVars ARGS(());
static void UnitSummary ARGS(());
static void UnitDump ARGS(());
static void VarSummary ARGS(());
static void SortSummary ARGS(());
static void ArrowSummary ARGS(());
static void GenericSummary ARGS(());
static void ListVars ARGS(());
static void ProcMod ARGS((MASSTOR_LIST t));
static void HELP ARGS(());
static void Help ARGS((MASSTOR_LIST t));
static void ModSummary ARGS((MASSTOR_LIST F));
static void ComSummary ARGS((MASSTOR_LIST F));
static MASSTOR_LIST Filter ARGS((MASSTOR_LIST L, MASSTOR_LIST f));
static void ProcSummary ARGS((MASSTOR_LIST F));
static void MWRIT2 ARGS((MASSTOR_LIST Y));
static void MWRIT3 ARGS((MASSTOR_LIST Y));
static void Pragma ARGS((MASSTOR_LIST a));
static void InitPragma ARGS(());
static void siline ARGS((MASSTOR_LIST s, MASSTOR_LIST l, MASSTOR_LIST r));
static void soline ARGS((MASSTOR_LIST s, MASSTOR_LIST l, MASSTOR_LIST r));


void MASU_InitExternalsU
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST x, y, f;

  MASLISPU_Compiledp0(DumpVars, "DUMPENV", 7L);
  MASLISPU_Compiledp0(UnitDump, "DUMPUNIT", 8L);
  MASLISPU_Compiledp0(MASSYM2_SymSummary, "SYMTB", 5L);
  MASLISPU_Compiledp0(MASBIOS_StorSummary, "GCM", 3L);
  MASLISPU_Compiledp0(MASBIOS_Summary, "BIOS", 4L);
  MASLISPU_Compiledp0(MASLISPU_CompSummary, "EXTPROCS", 8L);
  MASLISPU_Compiledp0(HELP, "HELP", 4L);
  MASLISPU_Compiledp1(Help, "helpfx", 6L);
  MASLISPU_Compiledp1(ProcMod, "procinmodx", 10L);
  MASLISPU_Compiledp1(ProcSummary, "ProcSummary", 11L);
  MASLISPU_Compiledp0(VarSummary, "VARS", 4L);
  MASLISPU_Compiledp0(SortSummary, "SORTS", 5L);
  MASLISPU_Compiledp0(UnitSummary, "UNITS", 5L);
  MASLISPU_Compiledp0(ArrowSummary, "SIGS", 4L);
  MASLISPU_Compiledp0(GenericSummary, "GENERICS", 8L);
  MASLISPU_Compiledp0(ListVars, "LISTENV", 7L);
  MASLISPU_Compiledf0(MASREP_NewRep, "NewRep", 6L);
  MASLISPU_Compiledf2(MASREP_GetRep, "GetRep", 6L);
  MASLISPU_Compiledp3(MASREP_SetRep, "SetRep", 6L);
  MASLISPU_Compiledf1(MASREP_FullRep, "FullRep", 7L);
  MASLISPU_Compiledf1(MASREP_CopyRep, "CopyRep", 7L);
  MASLISPU_Compiledf1(MASREP_StepRep, "StepRep", 7L);
  MASLISPU_Compiledf3(MASREP_ForEachinRep, "ForEachX", 8L);
  MASLISPU_Compiledf3(MASREP_ForEachinList, "ForEachY", 8L);
  MASLISPU_Compiledf1(MASBIOSU_INP, "IN", 2L);
  MASLISPU_Compiledf1(MASBIOSU_OUT, "OUT", 3L);
  MASLISPU_Compiledf1(MASBIOSU_SHUT, "SHUT", 4L);
  MASLISPU_Compiledf1(MASBIOSU_EDIT, "EDIT", 4L);
  MASLISPU_Compiledf1(MASBIOSU_DOS, "DOS", 3L);
  MASLISPU_Compiledf1(MASSTOR_LENGTH, "LENGTH", 6L);
  MASLISPU_Compiledf1(MASSTOR_FIRST, "FIRST", 5L);
  MASLISPU_Compiledf1(MASSTOR_FIRST, "CAR", 3L);
  MASLISPU_Compiledf1(SACLIST_SECOND, "SECOND", 6L);
  MASLISPU_Compiledf1(MASSTOR_RED, "RED", 3L);
  MASLISPU_Compiledf1(MASSTOR_RED, "CDR", 3L);
  MASLISPU_Compiledp2(MASSTOR_SRED, "SRED", 4L);
  MASLISPU_Compiledp2(MASSTOR_SFIRST, "SFIRST", 6L);
  MASLISPU_Compiledf1(MASSTOR_INV, "INV", 3L);
  MASLISPU_Compiledf1(SACLIST_CINV, "CINV", 4L);
  MASLISPU_Compiledf1(SACLIST_CINV, "REVERSE", 7L);
  MASLISPU_Compiledf0(MASBIOS_CREADB, "CREADB", 6L);
  MASLISPU_Compiledp1(MASBIOS_BLINES, "BLINES", 6L);
  MASLISPU_Compiledp1(SACLIST_CLOUT, "CLOUT", 5L);
  MASLISPU_Compiledp1(SACLIST_CLOUT, "SWRITE", 6L);
  MASLISPU_Compiledf2(MASSTOR_COMP, "COMP", 4L);
  MASLISPU_Compiledf2(MASSTOR_COMP, "CONS", 4L);
  MASLISPU_Compiledf2(SACLIST_CONC, "CONC", 4L);
  MASLISPU_Compiledf2(SACLIST_CCONC, "CCONC", 5L);
  MASLISPU_Compiledf2(SACLIST_CCONC, "JOIN", 4L);
  MASLISPU_Compiledf2(SACLIST_EQUAL, "EQUAL", 5L);
  MASLISPU_Compiledf2(MASELEM_MASEXP, "POW", 3L);
  MASLISPU_Compiledp1v2(MASSTOR_ADV, "ADV", 3L);
  MASLISPU_Compiledp3(siline, "SILINE", 6L);
  MASLISPU_Compiledp3(soline, "SOLINE", 6L);
  MASLISPU_Compiledp1(MASU_MWRITE, "MWRITE", 6L);
  MASLISPU_Compiledp1(MASSYM_UWRITE, "UWRITE", 6L);
  MASLISPU_Compiledf0(MASSYM_UREAD, "UREAD", 5L);
  InitPragma();
  MASLISPU_Declare(&alls, "all", 3L);
  MASLISPU_Declare(&modname, "ModulName", 9L);
  MASLISPU_Declare(&comment, "Comment", 7L);
  MASLISPU_Declare(&listi, "LIST", 4L);
  MASLISPU_Declare(&loaded, "Loaded", 6L);
  MASLISPU_Declare(&f, "help", 4L);
  MASLISPU_Declare(&x, "x", 1L);
  MASLISPU_Declare(&y, "helpfx", 6L);
  x = MASSTOR_LIST1(x);
  y = MASSTOR_COMP(y, x);
  y = MASSTOR_LIST1(y);
  y = MASSTOR_COMP(x, y);
  y = MASSTOR_COMP(f, y);
  MASLISPU_Declare(&f, "DF", 2L);
  y = MASSTOR_COMP(f, y);
  y = MASSPEC_EVALUATE(y, &MASLISP_ENV);
  MASLISPU_Declare(&f, "procinmod", 9L);
  MASLISPU_Declare(&x, "x", 1L);
  MASLISPU_Declare(&y, "procinmodx", 10L);
  x = MASSTOR_LIST1(x);
  y = MASSTOR_COMP(y, x);
  y = MASSTOR_LIST1(y);
  y = MASSTOR_COMP(x, y);
  y = MASSTOR_COMP(f, y);
  MASLISPU_Declare(&f, "DF", 2L);
  y = MASSTOR_COMP(f, y);
  y = MASSPEC_EVALUATE(y, &MASLISP_ENV);
}

static void DumpVars
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST Y, X, V, W;

  X = MASLISP_ENV;
  MASBIOS_BLINES(0);
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &V, &W, &X);
    Y = SACLIST_LIST3(MASLISP_SETQ, V, W);
    MASSYM_UWRITE(Y);
  }
}

static void UnitSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST Y, X, V, W, WP;

  X = MASLISP_ENV;
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("List of all declared units: ", 28L);
  MASBIOS_BLINES(1);
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &V, &W, &X);
    if (W > MASSTOR_SIL) {
      MASSTOR_ADV(W, &Y, &WP);
      if (Y == MASLISP_UNIT) {
        MASSYM_UWRIT1(V);
        MASBIOS_SWRITE(", ", 2L);
      }
    }
  }
  MASBIOS_BLINES(1);
}

static void UnitDump
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST Y, X, V, W, WP;

  X = MASLISP_ENV;
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE(" PRAGMA(LISP). ", 15L);
  MASBIOS_BLINES(1);
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &V, &W, &X);
    if (W > MASSTOR_SIL) {
      MASSTOR_ADV(W, &Y, &WP);
      if (Y == MASLISP_UNIT) {
        Y = SACLIST_LIST3(MASLISP_SETQ, V, W);
        MASSYM_UWRITE(Y);
      }
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE(" (PRAGMA MODULA) ", 17L);
  MASBIOS_BLINES(1);
}

static void VarSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST a, X, V, W, WP, Z;

  a = 0;
  MASBIOS_SWRITE("List of all declared variables: ", 32L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, MASLISP_TDEF);
    if (W != MASSTOR_SIL) {
      a = a + 1;
      MASBIOS_SWRITE("VAR ", 4L);
      MASSYM2_SYWRIT(V);
      MASBIOS_SWRITE(": ", 2L);
      SACLIST_FIRST2(W, &Z, &WP);
      MASSYM_UWRIT1(Z);
      if (WP != MASSTOR_SIL) {
        Z = MASSTOR_COMP(MASLISP_DECWRITE, W);
        MASBIOS_SWRITE(" \"", 2L);
        Z = MASSPEC_EVALUATE(Z, &MASLISP_ENV);
        MASBIOS_SWRITE("\"", 1L);
      }
      MASBIOS_SWRITE(".", 1L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(a);
  MASBIOS_SWRITE(" declared variables.", 20L);
  MASBIOS_BLINES(0);
}

static void SortSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST a, X, V, W, s, t, f;

  a = 0;
  MASBIOS_SWRITE("List of all sorts: ", 19L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, MASLISP_SORT);
    if (W != MASSTOR_SIL) {
      a = a + 1;
      MASSYM_UWRIT1(V);
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(a);
  MASBIOS_SWRITE(" sorts.", 7L);
  MASBIOS_BLINES(0);
}

static void ArrowSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST a, X, V, W, s, t, f;

  a = 0;
  MASBIOS_SWRITE("List of all signatures: ", 24L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, MASLISP_ARROW);
    if (W != MASSTOR_SIL) {
      a = a + 1;
      SACLIST_FIRST3(W, &s, &f, &t);
      MASBIOS_SWRITE("SIGNATURE ", 10L);
      MASSYM2_SYWRIT(f);
      MASSYM_UWRIT1(s);
      if (MASSTOR_RED(t) == MASSTOR_SIL) {
        t = MASSTOR_FIRST(t);
      }
      if (t != MASSTOR_SIL) {
        MASBIOS_SWRITE(": ", 2L);
        MASSYM_UWRIT1(t);
      }
      MASBIOS_SWRITE(".", 1L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(a);
  MASBIOS_SWRITE(" signatures.", 12L);
  MASBIOS_BLINES(0);
}

static void GenericSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST M, I, E, a, X, V, W, Y, s, t, f;

  a = 0;
  MASBIOS_SWRITE("List of all generic items: ", 27L);
  MASBIOS_BLINES(1);
  X = MASLISP_ENV;
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &V, &W, &X);
    if (W > MASSTOR_SIL) {
      Y = MASSTOR_FIRST(W);
    } else {
      Y = MASSTOR_SIL;
    }
    if (Y == MASLISP_GLAMBDA) {
      a = a + 1;
      W = SACLIST_RED2(W);
      SACLIST_FIRST3(W, &M, &I, &E);
      MASSYM2_SYWRIT(V);
      MASBIOS_SWRITE(":", 1L);
      MASBIOS_BLINES(0);
      while (M != MASSTOR_SIL) {
        SACLIST_ADV2(M, &s, &f, &M);
        f = SACLIST_COMP2(MASLISP_MAP, s, f);
        MASU_MWRITE(f);
      }
      if (I != MASSTOR_SIL) {
        f = MASSTOR_FIRST(I);
        f = SACLIST_LIST3(MASLISP_SETQ, V, f);
        MASU_MWRITE(f);
      }
      while (E != MASSTOR_SIL) {
        MASSTOR_ADV(E, &s, &E);
        f = MASSTOR_COMP(MASLISP_RULE, s);
        MASU_MWRITE(f);
      }
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(a);
  MASBIOS_SWRITE(" generic items.", 15L);
  MASBIOS_BLINES(0);
}

static void ListVars
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST X, V, W, Y;

  X = MASLISP_ENV;
  MASBIOS_BLINES(0);
  while (X != MASSTOR_SIL) {
    SACLIST_ADV2(X, &V, &W, &X);
    Y = SACLIST_LIST3(MASLISP_SETQ, V, W);
    MASU_MWRITE(Y);
  }
}

static void ProcMod
# ifdef __STDC__
(MASSTOR_LIST t)
# else
(t)
MASSTOR_LIST t;
# endif
{
  MASSTOR_LIST M, p, P;

  if (t == MASSTOR_SIL) {
    return;
  }
  SACLIST_FIRST2(t, &M, &P);
  if (P != MASSTOR_SIL) {
    if (MASSTOR_FIRST(P) == listi) {
      P = MASSTOR_RED(P);
    }
  }
  MASBIOS_SWRITE("P =", 3L);
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &p, &P);
    MASBIOS_SWRITE(" ", 1L);
    MASSYM_UWRIT1(p);
    MASSYM2_PUT(p, modname, M);
  }
  MASBIOS_BLINES(1);
}

static void HELP
# ifdef __STDC__
()
# else
()
# endif
{
  Help(MASSTOR_SIL);
}

static void Help
# ifdef __STDC__
(MASSTOR_LIST t)
# else
(t)
MASSTOR_LIST t;
# endif
{
  MASSTOR_LIST f;

  if (t <= MASSTOR_SIL) {
    MASBIOS_SWRITE("Enter 'help(name[,mod])' or 'help(start,end[,mod])'", 51L);
    MASBIOS_SWRITE(" to get more help.", 18L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'Name' means the first characters of a range of names,", 54L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE(" 'start,end' means a range of names.", 36L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'[,mod]' is optional and 'mod' can be ", 38L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'ModulName' = list module names of the procedures,", 50L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'all' = list all loaded procedures, ", 36L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'Loaded' = list loaded procedures, ", 35L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("'Comment' = list procedure comments ", 36L);
    MASBIOS_SWRITE("(default).", 10L);
    MASBIOS_BLINES(1);
    return;
  }
  f = t;
  if (MASSYM2_SYMBOL(t)) {
    f = MASSTOR_LIST1(t);
  }
  if (SACLIST_MEMBER(modname, f) == 1) {
    ModSummary(f);
    return;
  }
  if (SACLIST_MEMBER(alls, f) == 1) {
    ProcSummary(f);
    return;
  }
  if (SACLIST_MEMBER(loaded, f) == 1) {
    ProcSummary(f);
    return;
  }
  ComSummary(f);
}

static void ModSummary
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST X, V, W;

  MASBIOS_SWRITE("Module Names: ", 14L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  X = Filter(X, F);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, modname);
    if (W != MASSTOR_SIL) {
      MASSYM_UWRIT1(V);
      MASBIOS_SWRITE(" is in: ", 8L);
      SACLIST_CLOUT(MASSTOR_RED(W));
      MASBIOS_SWRITE(". ", 2L);
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_BLINES(1);
}

static void ComSummary
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST X, V, W, awk, awk1, sys, n, m;

  MASBIOS_SWRITE("Comments: ", 10L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  X = Filter(X, F);
  awk1 = MASBIOS_LISTS("awk \"/RE ", 9L);
  awk = MASBIOS_LISTS("/{pf=1} {if (pf==1) print} /\\*\\)/{pf=0}\" ", 41L);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, modname);
    if (W != MASSTOR_SIL) {
      n = MASSYM2_EXPLOD(V);
      m = MASSTOR_RED(W);
      sys = SACLIST_CCONC(m, MASBIOS_LISTS(" ", 1L));
      sys = SACLIST_CCONC(MASBIOS_LISTS("help/", 5L), sys);
      sys = SACLIST_CCONC(awk, sys);
      sys = SACLIST_CCONC(n, sys);
      sys = SACLIST_CCONC(awk1, sys);
      MASBIOS_BLINES(1);
      W = MASBIOSU_DOS(sys);
    }
  }
}

static MASSTOR_LIST Filter
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST f)
# else
(L, f)
MASSTOR_LIST L, f;
# endif
{
  MASSTOR_LIST LP, l, h, s;

  if (f <= MASSTOR_SIL) {
    return L;
  }
  if (MASSYM2_SYMBOL(f)) {
    f = MASSTOR_LIST1(f);
  }
  MASSTOR_ADV(f, &l, &f);
  if (l == alls) {
    return L;
  }
  if (f == MASSTOR_SIL) {
    h = MASSYM2_EXPLOD(l);
    h = SACLIST_CONC(h, MASBIOS_LISTS("ZZZZZ", 5L));
    h = MASSYM2_ENTER(h);
  } else {
    h = MASSTOR_FIRST(f);
    if (h == modname) {
      h = MASSYM2_EXPLOD(l);
      h = SACLIST_CONC(h, MASBIOS_LISTS("ZZZZZ", 5L));
      h = MASSYM2_ENTER(h);
    }
    if (h == comment) {
      h = MASSYM2_EXPLOD(l);
      h = SACLIST_CONC(h, MASBIOS_LISTS("ZZZZZ", 5L));
      h = MASSYM2_ENTER(h);
    }
    if (h == alls) {
      h = MASSYM2_EXPLOD(l);
      h = SACLIST_CONC(h, MASBIOS_LISTS("ZZZZZ", 5L));
      h = MASSYM2_ENTER(h);
    }
    if (h == loaded) {
      h = MASSYM2_EXPLOD(l);
      h = SACLIST_CONC(h, MASBIOS_LISTS("ZZZZZ", 5L));
      h = MASSYM2_ENTER(h);
    }
  }
  LP = MASSTOR_SIL;
  while (L != MASSTOR_SIL) {
    MASSTOR_ADV(L, &s, &L);
    if (MASSYM2_ACOMP(l, s) <= 0 && MASSYM2_ACOMP(s, h) <= 0) {
      LP = MASSTOR_COMP(s, LP);
    }
  }
  LP = MASSTOR_INV(LP);
  return LP;
}

static void ProcSummary
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST X, V, W, k, i, o, p, WP, s, f, t, Y;
  MASSTOR_LIST cp, cf, cs, ce;

  cp = 0;
  cf = 0;
  cs = 0;
  ce = 0;
  MASBIOS_SWRITE("List of functions and procedures: ", 34L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  X = Filter(X, F);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    WP = MASSTOR_SIL;
    W = MASSYM2_GET(V, MASLISP_ARROW);
    if (W != MASSTOR_SIL) {
      cs = cs + 1;
      SACLIST_FIRST3(W, &s, &f, &t);
      MASBIOS_SWRITE("SIGNATURE ", 10L);
      MASSYM2_SYWRIT(f);
      if (MASSTOR_RED(t) == MASSTOR_SIL) {
        t = MASSTOR_FIRST(t);
      }
      MASSYM_UWRIT1(s);
      if (t != MASSTOR_SIL) {
        MASBIOS_SWRITE(": ", 2L);
        MASSYM_UWRIT1(t);
      }
      MASBIOS_SWRITE(" ", 1L);
      MASBIOS_BLINES(0);
    }
    WP = MASSTOR_SIL;
    W = MASSYM2_ASSOC(V, MASLISP_ENV);
    if (W != MASSTOR_SIL) {
      W = MASSTOR_FIRST(W);
    }
    if (W > MASSTOR_SIL) {
      MASSTOR_ADV(W, &WP, &W);
    }
    if (WP == MASLISP_LAMBDA) {
      ce = ce + 1;
      MASBIOS_SWRITE("PROCEDURE ", 10L);
      MASSYM2_SYWRIT(V);
      Y = MASSTOR_FIRST(W);
      SACLIST_FIRST2(Y, &i, &o);
      MASBIOS_SWRITE("(", 1L);
      while (i != MASSTOR_SIL) {
        MASSTOR_ADV(i, &p, &i);
        MASSYM2_SYWRIT(p);
        if (i != MASSTOR_SIL) {
          MASBIOS_SWRITE(", ", 2L);
        }
      }
      if (o != MASSTOR_SIL) {
        MASBIOS_SWRITE("; VAR ", 6L);
      }
      while (o != MASSTOR_SIL) {
        MASSTOR_ADV(o, &p, &o);
        MASSYM2_SYWRIT(p);
        if (o != MASSTOR_SIL) {
          MASBIOS_SWRITE(", ", 2L);
        }
      }
      MASBIOS_SWRITE(")", 1L);
      MASBIOS_BLINES(0);
    }
    if (WP == MASLISP_FLAMBDA) {
      ce = ce + 1;
      MASBIOS_SWRITE("FPROCEDURE ", 11L);
      MASSYM2_SYWRIT(V);
      Y = MASSTOR_FIRST(W);
      MASBIOS_SWRITE("(", 1L);
      while (Y != MASSTOR_SIL) {
        MASSTOR_ADV(Y, &p, &Y);
        MASSYM2_SYWRIT(p);
        if (Y != MASSTOR_SIL) {
          MASBIOS_SWRITE(", ", 2L);
        }
      }
      MASBIOS_SWRITE(")", 1L);
      MASBIOS_BLINES(0);
    }
    if (WP == MASLISP_MLAMBDA) {
      ce = ce + 1;
      MASBIOS_SWRITE("MACRO ", 6L);
      MASSYM2_SYWRIT(V);
      Y = MASSTOR_FIRST(W);
      MASBIOS_SWRITE("(", 1L);
      while (Y != MASSTOR_SIL) {
        MASSTOR_ADV(Y, &p, &Y);
        MASSYM2_SYWRIT(p);
        if (Y != MASSTOR_SIL) {
          MASBIOS_SWRITE(", ", 2L);
        }
      }
      MASBIOS_SWRITE(")", 1L);
      MASBIOS_BLINES(0);
    }
    if (WP == MASLISP_GLAMBDA) {
      ce = ce + 1;
      MASBIOS_SWRITE("GENERIC   ", 10L);
      MASSYM2_SYWRIT(V);
      MASBIOS_SWRITE(" ", 1L);
      MASBIOS_BLINES(0);
    }
    W = MASSYM2_GET(V, MASLISPU_ARITY);
    if (W != MASSTOR_SIL) {
      SACLIST_FIRST3(W, &k, &i, &o);
      if (k == PIND) {
        cp = cp + 1;
        MASBIOS_SWRITE("PROCEDURE ", 10L);
        MASSYM2_SYWRIT(V);
        if (i + o > 0) {
          MASBIOS_SWRITE("(", 1L);
          while (i > 0) {
            i = i - 1;
            MASBIOS_SWRITE("LIST", 4L);
            if (i > 0) {
              MASBIOS_SWRITE(",", 1L);
            }
          }
          if (o > 0) {
            MASBIOS_SWRITE("; ", 2L);
          }
          while (o > 0) {
            o = o - 1;
            MASBIOS_SWRITE("LIST", 4L);
            if (o > 0) {
              MASBIOS_SWRITE(",", 1L);
            }
          }
          MASBIOS_SWRITE(")", 1L);
        }
      } else if (k == FIND) {
        cf = cf + 1;
        MASBIOS_SWRITE("FUNCTION  ", 10L);
        MASSYM2_SYWRIT(V);
        MASBIOS_SWRITE("(", 1L);
        while (i > 0) {
          i = i - 1;
          MASBIOS_SWRITE("LIST", 4L);
          if (i > 0) {
            MASBIOS_SWRITE(",", 1L);
          }
        }
        if (o > 0) {
          MASBIOS_SWRITE("; ", 2L);
        }
        while (o > 0) {
          o = o - 1;
          MASBIOS_SWRITE("LIST", 4L);
          if (o > 0) {
            MASBIOS_SWRITE(",", 1L);
          }
        }
        MASBIOS_SWRITE("): LIST", 7L);
      } else {
        MASSYM_UWRIT1(W);
      }
      MASBIOS_BLINES(0);
    }
  }
  MASBIOS_BLINES(1);
  MASBIOS_GWRITE(cs);
  MASBIOS_SWRITE(" signatures, ", 13L);
  MASBIOS_BLINES(0);
  MASBIOS_GWRITE(ce);
  MASBIOS_SWRITE(" interpreter procedures, ", 25L);
  MASBIOS_BLINES(0);
  MASBIOS_GWRITE(cf);
  MASBIOS_SWRITE(" compiled functions, ", 21L);
  MASBIOS_BLINES(0);
  MASBIOS_GWRITE(cp);
  MASBIOS_SWRITE(" compiled procedures ", 21L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("accessible.", 11L);
  MASBIOS_BLINES(1);
}

void MASU_MWRITE
# ifdef __STDC__
(MASSTOR_LIST Y)
# else
(Y)
MASSTOR_LIST Y;
# endif
{
  if (MASSYM_ELEMP(Y)) {
    MASSYM_UWRITE(Y);
  } else {
    MASU_MWRIT1(Y, TRUE);
    MASBIOS_SWRITE(". ", 2L);
  }
  MASBIOS_BLINES(0);
}

void MASU_MWRIT1
# ifdef __STDC__
(MASSTOR_LIST Y, BOOLEAN top)
# else
(Y, top)
MASSTOR_LIST Y;
BOOLEAN top;
# endif
{
  MASSTOR_LIST N, YP, C_27_A, B, C, D, F;
  BOOLEAN parm;

  if (MASSYM_ELEMP(Y)) {
    MASSYM_UWRIT1(Y);
    return;
  }
  if (MASSYM2_SYMBOL(Y)) {
    MASSYM2_SYWRIT(Y);
    return;
  }
  YP = Y;
  parm = FALSE;
  if (MASSYM2_SYMBOL(MASSTOR_FIRST(Y))) {
    MASSTOR_ADV(Y, &N, &YP);
    if (N == MASLISP_TINFO) {
      C_27_A = SACLIST_LIST2(MASLISP_WRITE, Y);
      MASBIOS_SWRITE("\"", 1L);
      B = MASSPEC_EVALUATE(C_27_A, &MASLISP_ENV);
      MASBIOS_SWRITE("\"", 1L);
    } else if (N == MASLISP_SETQ) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      C = MASSTOR_SIL;
      if (B > MASSTOR_SIL) {
        C = MASSTOR_FIRST(B);
      }
      if (C == MASLISP_LAMBDA) {
        MASBIOS_SWRITE("PROCEDURE ", 10L);
        MASU_MWRIT1(C_27_A, FALSE);
        MASU_MWRIT1(B, FALSE);
        MASBIOS_SWRITE(" ", 1L);
        MASU_MWRIT1(C_27_A, FALSE);
      } else {
        MASU_MWRIT1(C_27_A, FALSE);
        MASBIOS_SWRITE(":=", 2L);
        MASU_MWRIT1(B, FALSE);
      }
    } else if (N == MASLISP_ASSIGN) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(":=", 2L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_ADD) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("+", 1L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_SUB) {
      MASSTOR_ADV(YP, &B, &YP);
      MASBIOS_SWRITE("(", 1L);
      if (YP != MASSTOR_SIL) {
        C_27_A = MASSTOR_FIRST(YP);
        MASU_MWRIT1(B, FALSE);
        B = C_27_A;
      }
      MASBIOS_SWRITE("-", 1L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_MUL) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("*", 1L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_POW) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("^", 1L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_QUOT) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("/", 1L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_REM) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("%", 1L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_EQS) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" = ", 3L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_NEQS) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" <> ", 4L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_LEQ) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" <= ", 4L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_LTS) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" < ", 3L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_GEQ) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" >= ", 4L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_GTS) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" > ", 3L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_UND) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" AND ", 5L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_ODER) {
      SACLIST_FIRST2(YP, &C_27_A, &B);
      MASBIOS_SWRITE("(", 1L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" OR ", 4L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_NOTS) {
      C_27_A = MASSTOR_FIRST(YP);
      MASBIOS_SWRITE(" NOT ", 5L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(")", 1L);
    } else if (N == MASLISP_STRNG) {
      MASBIOS_SWRITE("\"", 1L);
      SACLIST_CLOUT(YP);
      MASBIOS_SWRITE("\"", 1L);
    } else if (N == MASLISP_IFS) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("IF ", 3L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" THEN ", 6L);
      MASU_MWRIT1(B, FALSE);
      if (YP != MASSTOR_SIL) {
        B = MASSTOR_FIRST(YP);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("   ELSE ", 8L);
        MASU_MWRIT1(B, FALSE);
      }
      MASBIOS_SWRITE(" END", 4L);
    } else if (N == MASLISP_WHL) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("WHILE ", 6L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" DO ", 4L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_SWRITE(" END", 4L);
    } else if (N == MASLISP_RPT) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("REPEAT ", 7L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" UNTIL ", 7L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_VARS) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("VAR ", 4L);
      MWRIT3(C_27_A);
      MASBIOS_SWRITE(": ", 2L);
      MASU_MWRIT1(B, FALSE);
    } else if (N == MASLISP_SORT) {
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("SORT ", 5L);
      MWRIT3(YP);
    } else if (N == MASLISP_LAMBDA) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      SACLIST_FIRST2(C_27_A, &C, &D);
      MASBIOS_SWRITE("(", 1L);
      MWRIT3(C);
      if (D != MASSTOR_SIL) {
        MASBIOS_SWRITE("; ", 2L);
        MWRIT3(D);
      }
      MASBIOS_SWRITE("); ", 3L);
      MASBIOS_BLINES(0);
      MASU_MWRIT1(B, TRUE);
    } else if (N == MASLISP_MLAMBDA) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_SWRITE("MLAMBDA ", 8L);
      MWRIT2(C_27_A);
      MASBIOS_SWRITE("; ", 2L);
      MASBIOS_BLINES(0);
      MASU_MWRIT1(B, TRUE);
    } else if (N == MASLISP_FLAMBDA) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_SWRITE("FLAMBDA ", 8L);
      MWRIT2(C_27_A);
      MASBIOS_SWRITE("; ", 2L);
      MASBIOS_BLINES(0);
      MASU_MWRIT1(B, TRUE);
    } else if (N == MASLISP_GLAMBDA) {
      MASSTOR_ADV(YP, &C_27_A, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("GLAMBDA ", 8L);
      MASU_MWRIT1(C_27_A, TRUE);
      MASBIOS_SWRITE(" ", 1L);
      SACLIST_FIRST3(YP, &C_27_A, &B, &C);
      MASBIOS_SWRITE("MAPS ", 5L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("PROCEDURE ", 10L);
      MASU_MWRIT1(B, FALSE);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("RULES ", 6L);
      MWRIT3(C);
      MASBIOS_BLINES(0);
    } else if (N == MASLISP_UNIT) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("UNIT ", 5L);
      MASU_MWRIT1(C_27_A, TRUE);
      MWRIT2(B);
      MASBIOS_SWRITE("; ", 2L);
      while (YP != MASSTOR_SIL) {
        MASSTOR_ADV(YP, &B, &YP);
        MASU_MWRIT1(B, FALSE);
        MASBIOS_SWRITE("; ", 2L);
      }
      MASBIOS_SWRITE("END ", 4L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE("; ", 2L);
    } else if (N == MASLISP_DE) {
      SACLIST_FIRST3(YP, &C_27_A, &B, &C);
      MASBIOS_SWRITE("PROCEDURE ", 10L);
      if (MASSYM2_SYMBOL(C_27_A)) {
        MASSYM2_SYWRIT(C_27_A);
        SACLIST_FIRST2(B, &D, &F);
        MASBIOS_SWRITE("(", 1L);
        MWRIT3(D);
        if (F != MASSTOR_SIL) {
          MASBIOS_SWRITE("; ", 2L);
          MWRIT3(F);
        }
        MASBIOS_SWRITE("); ", 3L);
        MASBIOS_BLINES(0);
        MASU_MWRIT1(C, TRUE);
        MASBIOS_SWRITE(" ", 1L);
        MASSYM2_SYWRIT(C_27_A);
      }
    } else if (N == MASLISP_DF) {
      SACLIST_FIRST3(YP, &C_27_A, &B, &C);
      MASBIOS_SWRITE("FPROCEDURE ", 11L);
      if (MASSYM2_SYMBOL(C_27_A)) {
        MASSYM2_SYWRIT(C_27_A);
        MWRIT2(B);
        MASBIOS_SWRITE("; ", 2L);
        MASBIOS_BLINES(0);
        MASU_MWRIT1(C, TRUE);
      }
    } else if (N == MASLISP_DM) {
      SACLIST_FIRST3(YP, &C_27_A, &B, &C);
      MASBIOS_SWRITE("MPROCEDURE ", 11L);
      if (MASSYM2_SYMBOL(C_27_A)) {
        MASSYM2_SYWRIT(C_27_A);
        MWRIT2(B);
        MASBIOS_SWRITE("; ", 2L);
        MASBIOS_BLINES(0);
        MASU_MWRIT1(C, TRUE);
      }
    } else if (N == MASLISP_MAP) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_SWRITE("MAP ", 4L);
      MASSYM_UWRIT1(C_27_A);
      MASBIOS_SWRITE(" -> ", 4L);
      SACLIST_FIRST2(B, &C_27_A, &B);
      MASSYM2_SYWRIT(C_27_A);
      MWRIT2(B);
      if (YP != MASSTOR_SIL) {
        SACLIST_FIRST2(MASSTOR_FIRST(YP), &C_27_A, &B);
        MASBIOS_SWRITE(" WHEN ", 6L);
        MASSYM2_SYWRIT(C_27_A);
        MWRIT2(B);
      }
    } else if (N == MASLISP_SIG) {
      SACLIST_ADV3(YP, &C_27_A, &B, &C, &YP);
      MASBIOS_SWRITE("SIGNATURE ", 10L);
      MASSYM2_SYWRIT(C_27_A);
      MASBIOS_SWRITE(" ", 1L);
      MASSYM_UWRIT1(B);
      if (C != MASSTOR_SIL) {
        MASBIOS_SWRITE(": ", 2L);
        MASSYM_UWRIT1(C);
      }
    } else if (N == MASLISP_RULE) {
      SACLIST_ADV2(YP, &C_27_A, &B, &YP);
      MASBIOS_SWRITE("RULE ", 5L);
      MASU_MWRIT1(C_27_A, FALSE);
      MASBIOS_SWRITE(" => ", 4L);
      MASU_MWRIT1(B, FALSE);
      if (YP != MASSTOR_SIL) {
        C_27_A = MASSTOR_FIRST(YP);
        MASBIOS_SWRITE(" WHEN ", 6L);
        MASU_MWRIT1(C_27_A, FALSE);
      }
    } else if (N == MASLISP_REP) {
      MASBIOS_SWRITE("REP <...>", 9L);
    } else if (N == MASSYM_NOSHOW) {
      MASBIOS_SWRITE("NOSHOW(...)", 11L);
    } else if (N == MASLISP_PROGN) {
      if (top) {
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("BEGIN ", 6L);
      }
      while (YP != MASSTOR_SIL) {
        MASSTOR_ADV(YP, &C_27_A, &YP);
        MASU_MWRIT1(C_27_A, FALSE);
        if (YP != MASSTOR_SIL) {
          MASBIOS_SWRITE("; ", 2L);
        }
      }
      if (top) {
        MASBIOS_SWRITE(" END", 4L);
      }
    } else {
      MASSYM2_SYWRIT(N);
      parm = TRUE;
    }
    if (!parm) {
      return;
    }
  }
  MWRIT2(YP);
}

static void MWRIT2
# ifdef __STDC__
(MASSTOR_LIST Y)
# else
(Y)
MASSTOR_LIST Y;
# endif
{
  MASBIOS_SWRITE("(", 1L);
  MWRIT3(Y);
  MASBIOS_SWRITE(")", 1L);
}

static void MWRIT3
# ifdef __STDC__
(MASSTOR_LIST Y)
# else
(Y)
MASSTOR_LIST Y;
# endif
{
  MASSTOR_LIST YP, C_26_A;

  YP = Y;
  while (YP != MASSTOR_SIL) {
    MASSTOR_ADV(YP, &C_26_A, &YP);
    MASU_MWRIT1(C_26_A, FALSE);
    if (YP != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
    }
  }
}

static void Pragma
# ifdef __STDC__
(MASSTOR_LIST a)
# else
(a)
MASSTOR_LIST a;
# endif
{
  if (a == M2S) {
    Parser = mas;
  } else if (a == LSP) {
    Parser = lisp;
  } else if (a == ALD) {
    Parser = aldes;
  } else if (a == TME) {
    MASU_Time = !MASU_Time;
  } else if (a == DBG) {
    MASU_Debug = !MASU_Debug;
  } else if (a == TRC) {
    MASLISP_trace = !MASLISP_trace;
  } else if (a == FUS) {
    MASLISP_stricttyping = TRUE;
  } else if (a == SLO) {
    MASLISP_stricttyping = FALSE;
  } else if (a == GENP) {
    genparsing = !genparsing;
    MASPARSE_SwitchParse(genparsing);
  } else if (a == SHOW) {
    MASBIOS_SWRITE("Actual Pragmas: ", 16L);
    if (MASU_Time) {
      MASBIOS_SWRITE("TIME, ", 6L);
    } else {
      MASBIOS_SWRITE("NO TIME, ", 9L);
    }
    if (MASLISP_trace) {
      MASBIOS_SWRITE("TRACE, ", 7L);
    } else {
      MASBIOS_SWRITE("NO TRACE, ", 10L);
    }
    if (MASU_Debug) {
      MASBIOS_SWRITE("DEBUG, ", 7L);
    } else {
      MASBIOS_SWRITE("NO DEBUG, ", 10L);
    }
    if (MASLISP_stricttyping) {
      MASBIOS_SWRITE("FUSSY, ", 7L);
    } else {
      MASBIOS_SWRITE("SLOPPY, ", 8L);
    }
    if (genparsing) {
      MASBIOS_SWRITE("GENPARSE, ", 10L);
    } else {
      MASBIOS_SWRITE("NO GENPARSE, ", 13L);
    }
    MASBIOS_SWRITE("Parser: ", 8L);
    switch (Parser) {
    case mas:;
      MASBIOS_SWRITE("MODULA", 6L);
      break;
    case lisp:;
      MASBIOS_SWRITE("LISP", 4L);
      break;
    case aldes:;
      MASBIOS_SWRITE("ALDES", 5L);
      break;
    default :
      MASBIOS_SWRITE("none", 4L);
      break;
    }
    MASBIOS_SWRITE(".", 1L);
  } else {
    MASBIOS_SWRITE("Invalid Pragma: ", 16L);
    MASSYM_UWRITE(a);
    MASBIOS_SWRITE("Possible Pragmas: SHOW, TIME, DEBUG, TRACE, ", 44L);
    MASBIOS_SWRITE("SLOPPY, FUSSY, ", 15L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("MODULA, LISP, ALDES, GENPARSE.", 30L);
  }
}

MASSTOR_LIST MASU_DoParse
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST Y;

  switch (Parser) {
  case mas:;
    MASBIOS_SWRITE("MAS: ", 5L);
    if (MASBIOS_OStreamKind() == MASBIOS_termkind) {
      MASU_WroteChars = 5;
    }
    MASU_PromptFirst = TRUE;
    MASU_PromptType = 0;
    Y = MASPARSE_Parse();
    break;
  case lisp:;
    MASBIOS_SWRITE("LISP: ", 6L);
    if (MASBIOS_OStreamKind() == MASBIOS_termkind) {
      MASU_WroteChars = 6;
    }
    MASU_PromptFirst = TRUE;
    MASU_PromptType = 1;
    Y = MASSYM_UREAD();
    break;
  case aldes:;
    MASBIOS_SWRITE("ALD: ", 5L);
    if (MASBIOS_OStreamKind() == MASBIOS_termkind) {
      MASU_WroteChars = 5;
    }
    MASU_PromptFirst = TRUE;
    MASU_PromptType = 2;
    Y = ALDPARSE_Aparse();
    Parser = mas;
    break;
  default :
    MASBIOS_SWRITE("MAS: ", 5L);
    MASU_PromptType = 0;
    if (MASBIOS_OStreamKind() == MASBIOS_termkind) {
      MASU_WroteChars = 5;
    }
    MASU_PromptFirst = TRUE;
    Y = MASPARSE_Parse();
    Parser = mas;
    break;
  }
  if (MASU_Debug) {
    MASBIOS_SWRITE("Parse: ", 7L);
    MASSYM_UWRITE(Y);
  }
  return Y;
}

void MASU_DoWrite
# ifdef __STDC__
(MASSTOR_LIST Y)
# else
(Y)
MASSTOR_LIST Y;
# endif
{
  switch (Parser) {
  case mas:;
    MASBIOS_SWRITE("ANS: ", 5L);
    MASU_MWRITE(Y);
    break;
  case lisp:;
    MASBIOS_SWRITE("ANS: ", 5L);
    MASSYM_UWRITE(Y);
    break;
  case aldes:;
    MASBIOS_SWRITE("ANS: ", 5L);
    MASU_MWRITE(Y);
    break;
  default :
    MASBIOS_SWRITE("ANS: ", 5L);
    MASSYM_UWRITE(Y);
    break;
  }
  MASBIOS_BLINES(1);
}

static void InitPragma
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Declare(&M2S, "MODULA", 6L);
  MASLISPU_Declare(&LSP, "LISP", 4L);
  MASLISPU_Declare(&ALD, "ALDES", 5L);
  MASLISPU_Declare(&TME, "TIME", 4L);
  MASLISPU_Declare(&DBG, "DEBUG", 5L);
  MASLISPU_Declare(&TRC, "TRACE", 5L);
  MASLISPU_Declare(&FUS, "FUSSY", 5L);
  MASLISPU_Declare(&SLO, "SLOPPY", 6L);
  MASLISPU_Declare(&GENP, "GENPARSE", 8L);
  MASLISPU_Declare(&SHOW, "SHOW", 4L);
  Parser = mas;
  MASU_Time = FALSE;
  MASU_Debug = FALSE;
  genparsing = FALSE;
  MASLISP_trace = FALSE;
  MASLISP_stricttyping = FALSE;
  MASLISPU_Compiledp1(Pragma, "PRAGMA", 6L);
}

static void siline
# ifdef __STDC__
(MASSTOR_LIST s, MASSTOR_LIST l, MASSTOR_LIST r)
# else
(s, l, r)
MASSTOR_LIST s, l, r;
# endif
{
  MASBIOS_SILINE(&s, &l, &r);
  MASBIOS_SWRITE("Old input line size (size,left,right): (", 40L);
  MASBIOS_GWRITE(s);
  MASBIOS_SWRITE(", ", 2L);
  MASBIOS_GWRITE(l);
  MASBIOS_SWRITE(", ", 2L);
  MASBIOS_GWRITE(r);
  MASBIOS_SWRITE(").", 2L);
  MASBIOS_BLINES(0);
}

static void soline
# ifdef __STDC__
(MASSTOR_LIST s, MASSTOR_LIST l, MASSTOR_LIST r)
# else
(s, l, r)
MASSTOR_LIST s, l, r;
# endif
{
  MASBIOS_SOLINE(&s, &l, &r);
  MASBIOS_SWRITE("Old output line size (size,left,right): (", 41L);
  MASBIOS_GWRITE(s);
  MASBIOS_SWRITE(", ", 2L);
  MASBIOS_GWRITE(l);
  MASBIOS_SWRITE(", ", 2L);
  MASBIOS_GWRITE(r);
  MASBIOS_SWRITE(").", 2L);
  MASBIOS_BLINES(0);
}

void BEGIN_MASU()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();
    BEGIN_MASLISPU();
    BEGIN_MASLISP();
    BEGIN_MASSPEC();
    BEGIN_MASREP();
    BEGIN_MASPARSE();
    BEGIN_ALDPARSE();

    MASU_WroteChars = 0;
    MASU_PromptFirst = FALSE;
    MASU_PromptType = 0;
  }
}
