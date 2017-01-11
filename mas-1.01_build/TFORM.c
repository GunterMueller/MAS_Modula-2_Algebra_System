#include "SYSTEM_.h"

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASLOG
#include "MASLOG.h"
#endif

#ifndef DEFINITION_MASSET
#include "MASSET.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MLOGBASE
#include "MLOGBASE.h"
#endif

#ifndef DEFINITION_MLOGIO
#include "MLOGIO.h"
#endif

#ifndef DEFINITION_LISTTOOLS
#include "LISTTOOLS.h"
#endif

#ifndef DEFINITION_PQBASE
#include "PQBASE.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_TFORM
#include "TFORM.h"
#endif

CHAR TFORM_rcsid [] = "$Id: TFORM.md,v 1.2 1995/11/04 18:00:33 pesch Exp $";
CHAR TFORM_copyright [] = "Copyright (c) 1994 Universitaet Passau";

static CHAR rcsidi [] = "$Id: TFORM.mi,v 1.1 1994/11/28 21:10:08 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1994 Universitaet Passau";
static MASSTOR_LIST TfGood, TfBad, TfImpossible, TfDontCare;
static MASSTOR_LIST BbfParserSyms;
static MASLISPU_PROCF1 TypeFormulaProc;
static void tfprtaf ARGS((MASSTOR_LIST af));
static MASSTOR_LIST tfraf ARGS(());
static void InitBbfParser ARGS(());
static MASSTOR_LIST TfCtj1 ARGS((MASSTOR_LIST deg, MASSTOR_LIST end, MASSTOR_LIST c0, MASSTOR_LIST ci, MASSTOR_LIST length, MASSTOR_LIST zp, MASSTOR_LIST zm));
struct S_1 {
    MASSTOR_LIST A[TFORM_Tfimpossible + 1];
};


MASSTOR_LIST TFORM_tfmkaf
# ifdef __STDC__
(MASSTOR_LIST rel, MASSTOR_LIST idl)
# else
(rel, idl)
MASSTOR_LIST rel;
MASSTOR_LIST idl;
# endif
{
  return SACLIST_LIST2(rel, idl);
}

void TFORM_tfpaf
# ifdef __STDC__
(MASSTOR_LIST af, MASSTOR_LIST *rel, MASSTOR_LIST *idl)
# else
(af, rel, idl)
MASSTOR_LIST af;
MASSTOR_LIST *rel, *idl;
# endif
{
  SACLIST_FIRST2(af, rel, idl);
}

MASSTOR_LIST TFORM_tfgrel
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  return MASSTOR_FIRST(af);
}

static void tfprtaf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, idl, id;

  SACLIST_ADV2(af, &rel, &idl, &af);
  MASBIOS_SWRITE("[ (", 3L);
  MASSTOR_ADV(idl, &id, &idl);
  MASBIOS_SWRITE("a", 1L);
  SACLIST_AWRITE(id);
  while (idl != MASSTOR_SIL) {
    MASBIOS_SWRITE(" * ", 3L);
    MASSTOR_ADV(idl, &id, &idl);
    MASBIOS_SWRITE("a", 1L);
    SACLIST_AWRITE(id);
  }
  MASBIOS_SWRITE(")", 1L);
  if (rel == PQBASE_EQU) {
    MASBIOS_SWRITE(" = 0]", 5L);
  } else if (rel == PQBASE_NEQ) {
    MASBIOS_SWRITE(" <> 0]", 6L);
  } else if (rel == PQBASE_LES) {
    MASBIOS_SWRITE(" < 0]", 5L);
  } else if (rel == PQBASE_GRE) {
    MASBIOS_SWRITE(" > 0]", 5L);
  } else if (rel == PQBASE_LSQ) {
    MASBIOS_SWRITE(" <= 0]", 6L);
  } else if (rel == PQBASE_GRQ) {
    MASBIOS_SWRITE(" >= 0]", 6L);
  } else {
    MASERR_ERROR(MASERR_severe, "tfprtaf: unknown relation symbol", 32L);
  }
}

static MASSTOR_LIST tfraf
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  BOOLEAN ExpectOp;
  MASSTOR_LIST code, cl, ucl, rel, idl, sym, clp;

  idl = MASSTOR_SIL;
  ExpectOp = FALSE;
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD('(')) {
    MASBIOS_BKSP();
  }
  for (;;) {
    c = MASBIOS_CREADB();
    if (MASBIOS_DIGIT(c)) {
      MASBIOS_BKSP();
      code = SACLIST_AREAD();
      ExpectOp = TRUE;
      idl = MASSTOR_COMP(code, idl);
    } else if (c == MASBIOS_MASORD('*')) {
      if (!ExpectOp) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "tfraf: operator expected.", 25L);
      } else {
        ExpectOp = FALSE;
      }
    } else if (c == MASBIOS_MASORD(')')) {
      ucl = MLOGIO_KEYREAD();
      sym = MASSYM2_ASSOCQ(ucl, BbfParserSyms);
      if (sym == MASSTOR_SIL) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "tfraf: unknown relation symbol.", 31L);
      }
      goto EXIT_1;
    } else {
      MASBIOS_BKSP();
      if (MASBIOS_LETTER(c)) {
        cl = MASSYM2_SREAD1();
      } else {
        cl = MLOGIO_KEYREAD();
      }
      ucl = LISTTOOLS_UPCASE(cl);
      sym = MASSYM2_ASSOCQ(ucl, BbfParserSyms);
      if (sym != MASSTOR_SIL) {
        goto EXIT_1;
      }
      if (MASSTOR_FIRST(cl) > 9) {
        cl = MASSTOR_RED(cl);
      }
      code = 0;
      while (cl != MASSTOR_SIL) {
        MASSTOR_ADV(cl, &clp, &cl);
        code = code * 10 + clp;
      }
      ExpectOp = TRUE;
      idl = MASSTOR_COMP(code, idl);
    }
  } EXIT_1:;
  rel = MASSTOR_FIRST(sym);
  c = MASBIOS_CREADB();
  if (c != 0) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "tfraf: 0 expected.", 18L);
    if (c == MASBIOS_MASORD(']')) {
      MASBIOS_BKSP();
    }
  }
  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD(')')) {
    MASBIOS_BKSP();
  }
  return TFORM_tfmkaf(rel, SACSET_LBIBMS(idl));
}

static void InitBbfParser
# ifdef __STDC__
()
# else
()
# endif
{
  BbfParserSyms = MASSTOR_SIL;
  MASSTOR_LISTVAR(&BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<>", 2L), PQBASE_NEQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("#", 1L), PQBASE_NEQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("!=", 2L), PQBASE_NEQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("NEQ", 3L), PQBASE_NEQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("=", 1L), PQBASE_EQU, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("EQU", 3L), PQBASE_EQU, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS(">", 1L), PQBASE_GRE, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("GRE", 3L), PQBASE_GRE, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<", 1L), PQBASE_LES, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("LES", 3L), PQBASE_LES, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("<=", 2L), PQBASE_LSQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("LSQ", 3L), PQBASE_LSQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("LEQ", 3L), PQBASE_LSQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS(">=", 2L), PQBASE_GRQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("GRQ", 3L), PQBASE_GRQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("GEQ", 3L), PQBASE_GRQ, BbfParserSyms);
  return;
}

void TFORM_TFPPRT
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MLOGIO_FORPPRT(phi, tfprtaf);
}

MASSTOR_LIST TFORM_TFIREAD
# ifdef __STDC__
()
# else
()
# endif
{
  return MLOGIO_FORIREAD(tfraf);
}

void TFORM_TfUseDb
# ifdef __STDC__
()
# else
()
# endif
{
  TypeFormulaProc = TFORM_UseDb;
}

void TFORM_TfComputeTf
# ifdef __STDC__
()
# else
()
# endif
{
  TypeFormulaProc = TFORM_ComputeTypeFormula;
}

MASSTOR_LIST TFORM_TfTypeFormula
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  return (*TypeFormulaProc)(deg);
}

MASSTOR_LIST TFORM_ComputeTypeFormula
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  MASSTOR_LIST result;

  if (deg <= 2) {
    result = TFORM_TfRecBasis(deg);
  } else if (deg <= 6 && deg % 2 == 0) {
    result = TFORM_TfTypeFormula(deg - 2);
    result = TFORM_TfShiftVars(result, 2);
    result = MLOGBASE_FORMKFOR(MLOGBASE_ET, SACLIST_LIST3(TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(0)), TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(1)), result));
    result = MLOGBASE_FORMKBINOP(MLOGBASE_VEL, result, TFORM_TfRecBasis(deg));
  } else if (deg % 2 == 1) {
    result = TFORM_TfTypeFormula(deg - 1);
    result = TFORM_TfShiftVars(result, 1);
    result = MLOGBASE_FORMKBINOP(MLOGBASE_ET, TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(0)), result);
  } else if (deg % 2 == 0) {
    result = TFORM_TfTypeFormula(deg - 2);
    result = TFORM_TfShiftVars(result, 2);
    result = MLOGBASE_FORMKFOR(MLOGBASE_ET, SACLIST_LIST3(TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(0)), TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(1)), result));
    result = MLOGBASE_FORMKBINOP(MLOGBASE_VEL, result, TFORM_TFGENJ(deg));
  }
  return result;
}

MASSTOR_LIST TFORM_UseDb
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  MASSTOR_LIST name, ret, phi;

  name = MASBIOS_LISTS("TF.", 3L);
  name = SACLIST_CONC(name, LISTTOOLS_CLISTFA(deg));
  name = SACLIST_CONC(name, MASBIOS_LISTS(".db", 3L));
  ret = MASBIOSU_INP(name);
  if (ret != 0) {
    phi = TFORM_ComputeTypeFormula(deg);
    ret = MASBIOSU_OUT(name);
    TFORM_TFPPRT(phi);
    MASBIOS_SWRITE(".", 1L);
    ret = MASBIOSU_SHUT(name);
  } else {
    phi = TFORM_TFIREAD();
    ret = MASBIOSU_SHUT(name);
  }
  return phi;
}

MASSTOR_LIST TFORM_TFGENJ
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  MASSTOR_LIST R, r, result;
  MASSTOR_LIST last;

  if (deg % 4 == 0) {
    last = TFORM_tfmkaf(PQBASE_GRE, MASSTOR_LIST1(0));
  } else if (deg % 4 == 2) {
    last = TFORM_tfmkaf(PQBASE_LES, MASSTOR_LIST1(0));
  } else {
    MASERR_ERROR(MASERR_severe, "TFGENJ: degree must be even.", 28L);
    return MLOGBASE_FALSUM;
  }
  result = MASSTOR_SIL;
  R = TFORM_TfCtj(deg);
  while (R != MASSTOR_SIL) {
    MASSTOR_ADV(R, &r, &R);
    result = MASSTOR_COMP(TFORM_TFFTUPLE(r), result);
  }
  return MLOGBASE_FORMKBINOP(MLOGBASE_ET, last, MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(result)));
}

MASSTOR_LIST TFORM_TfRecBasis
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  MASSTOR_LIST sp;

  switch ((INTEGER)deg) {
  case 1:;
    MASBIOSU_CLTIS(MASBIOS_LISTS("( [a0 = 0] ) . ", 15L));
    return TFORM_TFIREAD();
    break;
  case 2:;
    MASBIOSU_CLTIS(MASBIOS_LISTS("( [a1 = 0] \\/ [a0 < 0] ) . ", 27L));
    return TFORM_TFIREAD();
    break;
  case 4:;
    MASBIOSU_CLTIS(MASBIOS_LISTS("( [ a0 > 0 ] /\\ ( [a2 < 0] \\/ [a1 a3 < 0] )) . ", 47L));
    return TFORM_TFIREAD();
    break;
  case 6:;
    MASBIOSU_CLTIS(MASBIOS_LISTS("([a0<0]/\\((([a2>0]\\/[a3 a1<0])/\\([a4<0]\\/[a5 a3<0]))\\/([a5 a1>0]/\\[a4 a2<0]))) . ", 81L));
    return TFORM_TFIREAD();
    break;
  default :
    MASERR_ERROR(MASERR_severe, "TfRecBasis: possible values for deg: 1,2,4,6.", 45L);
    return MLOGBASE_FALSUM;
    break;
  }
}

MASSTOR_LIST TFORM_TfCtj
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  if (deg % 2 == 1) {
    MASERR_ERROR(MASERR_severe, "TfCtj: deg must be even.", 24L);
    return MASSTOR_SIL;
  }
  if (deg % 4 == 2) {
    return TfCtj1(deg, MASSTOR_LIST1(1), -1, SACLIST_LIST2(-1, 1), 1, 0, 0);
  } else {
    return TfCtj1(deg, MASSTOR_LIST1(1), 1, SACLIST_LIST2(-1, 1), 1, 0, 0);
  }
}

static MASSTOR_LIST TfCtj1
# ifdef __STDC__
(MASSTOR_LIST deg, MASSTOR_LIST end, MASSTOR_LIST c0, MASSTOR_LIST ci, MASSTOR_LIST length, MASSTOR_LIST zp, MASSTOR_LIST zm)
# else
(deg, end, c0, ci, length, zp, zm)
MASSTOR_LIST deg, end, c0, ci, length, zp, zm;
# endif
{
  MASSTOR_LIST result, first, c, l;

  l = deg / 2;
  if (zm > l || zp > l) {
    return MASSTOR_SIL;
  }
  first = MASSTOR_FIRST(end);
  if (length == deg + 1) {
    if (zp + zm == deg && zp == zm) {
      return MASSTOR_LIST1(end);
    } else {
      return MASSTOR_SIL;
    }
  } else if (length == deg) {
    if (c0 * first == -1) {
      zp = zp + 1;
    } else {
      zm = zm + 1;
    }
    return TfCtj1(deg, MASSTOR_COMP(c0, end), c0, MASSTOR_SIL, length + 1, zp, zm);
  } else if (length == deg - 1) {
    if (c0 * first == -1) {
      return TfCtj1(deg, SACLIST_COMP2(c0, 2, end), c0, MASSTOR_SIL, length + 2, zp + 1, zm + 1);
    } else {
      result = MASSTOR_SIL;
      while (ci != MASSTOR_SIL) {
        MASSTOR_ADV(ci, &c, &ci);
        if (first * c == -1) {
          result = SACLIST_CONC(result, TfCtj1(deg, MASSTOR_COMP(c, end), c0, MASSTOR_SIL, length + 1, zp + 1, zm));
        } else {
          result = SACLIST_CONC(result, TfCtj1(deg, MASSTOR_COMP(c, end), c0, MASSTOR_SIL, length + 1, zp, zm + 1));
        }
      }
      return result;
    }
  } else {
    result = TfCtj1(deg, SACLIST_COMP2(-first, 2, end), c0, SACLIST_LIST2(-1, 1), length + 2, zp + 1, zm + 1);
    while (ci != MASSTOR_SIL) {
      MASSTOR_ADV(ci, &c, &ci);
      if (first * c == -1) {
        result = SACLIST_CONC(result, TfCtj1(deg, MASSTOR_COMP(c, end), c0, MASSTOR_LIST1(first), length + 1, zp + 1, zm));
      } else {
        result = SACLIST_CONC(result, TfCtj1(deg, MASSTOR_COMP(c, end), c0, MASSTOR_LIST1(first), length + 1, zp, zm + 1));
      }
    }
    return result;
  }
}

MASSTOR_LIST TFORM_TFFTUPLE
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  MASSTOR_LIST c, i, result;

  if (tup == MASSTOR_SIL) {
    return MLOGBASE_FALSUM;
  }
  i = 1;
  result = MASSTOR_SIL;
  MASSTOR_ADV(tup, &c, &tup);
  while (MASSTOR_RED(tup) != MASSTOR_SIL) {
    MASSTOR_ADV(tup, &c, &tup);
    switch ((INTEGER)c) {
    case -1:;
      result = MASSTOR_COMP(TFORM_tfmkaf(PQBASE_LES, MASSTOR_LIST1(i)), result);
      break;
    case 0:;
      result = MASSTOR_COMP(TFORM_tfmkaf(PQBASE_EQU, MASSTOR_LIST1(i)), result);
      break;
    case 1:;
      result = MASSTOR_COMP(TFORM_tfmkaf(PQBASE_GRE, MASSTOR_LIST1(i)), result);
      break;
    case 2:;
      break;
    }
    i = i + 1;
  }
  if (result == MASSTOR_SIL) {
    return MLOGBASE_VERUM;
  }
  return MLOGBASE_FORMKFOR(MLOGBASE_ET, MASSTOR_INV(result));
}

MASSTOR_LIST TFORM_TfShiftVars
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST offset)
# else
(phi, offset)
MASSTOR_LIST phi, offset;
# endif
{
  return MASLOG_FORAPPLYATF2(phi, offset, TFORM_tfshiftaf);
}

MASSTOR_LIST TFORM_tfshiftaf
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST offset)
# else
(phi, offset)
MASSTOR_LIST phi, offset;
# endif
{
  MASSTOR_LIST rel, idl, id, result;

  TFORM_tfpaf(phi, &rel, &idl);
  result = MASSTOR_SIL;
  while (idl != MASSTOR_SIL) {
    MASSTOR_ADV(idl, &id, &idl);
    result = MASSTOR_COMP(id + offset, result);
  }
  return TFORM_tfmkaf(rel, MASSTOR_INV(result));
}

MASSTOR_LIST TFORM_Class2Sym
# ifdef __STDC__
(TFORM_TfClass class)
# else
(class)
TFORM_TfClass class;
# endif
{
  if (class == TFORM_Tfgood) {
    return TfGood;
  } else if (class == TFORM_Tfbad) {
    return TfBad;
  } else if (class == TFORM_Tfdontcare) {
    return TfDontCare;
  } else if (class == TFORM_Tfimpossible) {
    return TfImpossible;
  } else {
    MASERR_ERROR(MASERR_severe, "Class2Sym: Unknown Classification:", 34L);
  }
}

TFORM_TfClass TFORM_Sym2Class
# ifdef __STDC__
(MASSTOR_LIST class)
# else
(class)
MASSTOR_LIST class;
# endif
{
  if (class == TfGood) {
    return TFORM_Tfgood;
  } else if (class == TfBad) {
    return TFORM_Tfbad;
  } else if (class == TfDontCare) {
    return TFORM_Tfdontcare;
  } else if (class == TfImpossible) {
    return TFORM_Tfimpossible;
  } else {
    MASERR_ERROR(MASERR_severe, "Sym2Class: Unknown Classification:", 34L);
  }
}

void TFORM_InitClassSyms
# ifdef __STDC__
()
# else
()
# endif
{
  MASLISPU_Declare(&TfGood, "TfGood", 6L);
  MASLISPU_Declare(&TfBad, "TfBad", 5L);
  MASLISPU_Declare(&TfImpossible, "TfImpossible", 12L);
  MASLISPU_Declare(&TfDontCare, "TfDontCare", 10L);
}

TFORM_TfClass TFORM_TfClassify
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  MASSTOR_LIST type, CZeroes, ZeroesM, Zeroes0, ZeroesP;

  TFORM_TfZeroes(tup, &CZeroes, &ZeroesM, &Zeroes0, &ZeroesP);
  if (CZeroes == MASSTOR_SIL) {
    return TFORM_Tfimpossible;
  }
  if (ZeroesM + Zeroes0 + ZeroesP != CZeroes) {
    return TFORM_Tfimpossible;
  }
  type = ZeroesP - ZeroesM;
  if (type > 0) {
    return TFORM_Tfbad;
  } else if (type == 0) {
    return TFORM_Tfgood;
  } else {
    return TFORM_Tfdontcare;
  }
}

MASSTOR_LIST TFORM_TfClassifyI
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  return TFORM_Class2Sym(TFORM_TfClassify(tup));
}

MASSTOR_LIST TFORM_TFGENI
# ifdef __STDC__
(MASSTOR_LIST deg, MASSTOR_LIST class)
# else
(deg, class)
MASSTOR_LIST deg;
MASSTOR_LIST class;
# endif
{
  return TFORM_TFGEN(deg, TFORM_Sym2Class(class));
}

MASSTOR_LIST TFORM_TFGEN
# ifdef __STDC__
(MASSTOR_LIST deg, TFORM_TfClass class)
# else
(deg, class)
MASSTOR_LIST deg;
TFORM_TfClass class;
# endif
{
  MASSTOR_LIST pattern, tup, res;
  TFORM_TfClass c;

  TFORM_PatternAStart(deg, &tup, &pattern);
  res = MASSTOR_SIL;
  do {
    c = TFORM_TfClassify(tup);
    if (c == class) {
      res = MASSTOR_COMP(TFORM_TFFTUPLE(tup), res);
    }
    tup = TFORM_TfNextTuple(tup, pattern);
  } while (!(tup == MASSTOR_SIL));
  return MLOGBASE_FORMKFOR(MLOGBASE_VEL, MASSTOR_INV(res));
}

void TFORM_PatternAStart
# ifdef __STDC__
(MASSTOR_LIST deg, MASSTOR_LIST *start, MASSTOR_LIST *pattern)
# else
(deg, start, pattern)
MASSTOR_LIST deg;
MASSTOR_LIST *start, *pattern;
# endif
{
  MASSTOR_LIST i;

  if (deg <= 0) {
    *start = MASSTOR_SIL;
    *pattern = MASSTOR_SIL;
    return;
  }
  *start = MASSTOR_LIST1(1);
  *pattern = MASSTOR_LIST1(0);
  {
    LONGINT B_1 = 1, B_2 = deg - 2;

    if (B_1 <= B_2)
      for (i = B_1;; i += 1) {
        *start = MASSTOR_COMP(-1, *start);
        *pattern = MASSTOR_COMP(1, *pattern);
        if (i >= B_2) break;
      }
  }
  switch ((INTEGER)deg % 4) {
  case 0:;
    *start = SACLIST_COMP2(1, -1, *start);
    *pattern = SACLIST_COMP2(0, 1, *pattern);
    break;
  case 1:;
    *start = SACLIST_COMP2(0, 1, *start);
    *pattern = SACLIST_COMP2(0, 0, *pattern);
    break;
  case 2:;
    *start = SACLIST_COMP2(-1, -1, *start);
    *pattern = SACLIST_COMP2(0, 1, *pattern);
    break;
  case 3:;
    *start = SACLIST_COMP2(0, -1, *start);
    *pattern = SACLIST_COMP2(0, 0, *pattern);
    break;
  }
  return;
}

MASSTOR_LIST TFORM_TfNextTuple
# ifdef __STDC__
(MASSTOR_LIST last, MASSTOR_LIST pattern)
# else
(last, pattern)
MASSTOR_LIST last, pattern;
# endif
{
  MASSTOR_LIST lp, lpp, rel, modflag;

  if (last == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  lp = last;
  do {
    MASSTOR_ADV(lp, &rel, &lpp);
    MASSTOR_ADV(pattern, &modflag, &pattern);
    if (modflag == 1) {
      MASSTOR_SFIRST(lp, TFORM_NextRel(rel));
    }
    lp = lpp;
  } while (!(lp == MASSTOR_SIL || rel != 1 && modflag == 1));
  if (lp == MASSTOR_SIL && (rel == 1 || modflag == 0)) {
    return MASSTOR_SIL;
  } else {
    return last;
  }
}

MASSTOR_LIST TFORM_NextRel
# ifdef __STDC__
(MASSTOR_LIST e)
# else
(e)
MASSTOR_LIST e;
# endif
{
  switch ((INTEGER)e) {
  case -1:;
    return 0;
    break;
  case 0:;
    return 1;
    break;
  case 1:;
    return -1;
    break;
  default :
    MASERR_ERROR(MASERR_severe, "NextRel: unknown relation", 25L);
    break;
  }
}

MASSTOR_LIST TFORM_TfCount
# ifdef __STDC__
(MASSTOR_LIST deg)
# else
(deg)
MASSTOR_LIST deg;
# endif
{
  MASSTOR_LIST start, pattern;

  TFORM_PatternAStart(deg, &start, &pattern);
  return TFORM_TfCount1(start, pattern);
}

MASSTOR_LIST TFORM_TfCount1
# ifdef __STDC__
(MASSTOR_LIST start, MASSTOR_LIST pattern)
# else
(start, pattern)
MASSTOR_LIST start, pattern;
# endif
{
  TFORM_TfClass c;
  struct S_1 table;
  MASSTOR_LIST res, tup;

  tup = start;
  for (c = TFORM_Tfgood; c <= TFORM_Tfimpossible; c += 1) {
    table.A[c] = 0;
  }
  do {
    c = TFORM_TfClassify(tup);
    table.A[c] = table.A[c] + 1;
    tup = TFORM_TfNextTuple(tup, pattern);
  } while (!(tup == MASSTOR_SIL));
  res = MASSTOR_SIL;
  {
    TFORM_TfClass B_3 = TFORM_Tfimpossible, B_4 = TFORM_Tfgood;

    if (B_3 >= B_4)
      for (c = B_3;; c += -1) {
        res = MASSTOR_COMP(table.A[c], res);
        if (c <= B_4) break;
      }
  }
  return res;
}

MASSTOR_LIST TFORM_TfZeroes0
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  MASSTOR_LIST result, c;

  if (tup == MASSTOR_SIL) {
    return 0;
  }
  result = 0;
  do {
    MASSTOR_ADV(tup, &c, &tup);
    if (c != 0) {
      return result;
    } else {
      result = result + 1;
    }
  } while (!(tup == MASSTOR_SIL));
  return MASSTOR_SIL;
}

void TFORM_TfZeroes
# ifdef __STDC__
(MASSTOR_LIST tup, MASSTOR_LIST *CZeroes, MASSTOR_LIST *ZeroesM, MASSTOR_LIST *Zeroes0, MASSTOR_LIST *ZeroesP)
# else
(tup, CZeroes, ZeroesM, Zeroes0, ZeroesP)
MASSTOR_LIST tup;
MASSTOR_LIST *CZeroes, *ZeroesM, *Zeroes0, *ZeroesP;
# endif
{
  BOOLEAN even, lzero;
  MASSTOR_LIST lastp, lastm, cp, cm;

  even = FALSE;
  lzero = TRUE;
  *Zeroes0 = 0;
  *ZeroesM = 0;
  *ZeroesP = 0;
  *CZeroes = 0;
  if (tup == MASSTOR_SIL) {
    return;
  }
  MASSTOR_ADV(tup, &lastp, &tup);
  lastm = lastp;
  if (lastp == 0) {
    *Zeroes0 = 1;
  } else {
    lzero = FALSE;
  }
  while (tup != MASSTOR_SIL) {
    MASSTOR_ADV(tup, &cp, &tup);
    *CZeroes = *CZeroes + 1;
    if (even) {
      cm = cp;
    } else {
      cm = -cp;
    }
    if (cp == 0 && lzero) {
      *Zeroes0 = *Zeroes0 + 1;
    } else if (cp != 0) {
      lzero = FALSE;
      if (lastp + cp == 0) {
        *ZeroesP = *ZeroesP + 1;
      }
      if (lastm + cm == 0) {
        *ZeroesM = *ZeroesM + 1;
      }
      lastp = cp;
      lastm = cm;
    }
    even = !even;
  }
  if (lzero) {
    *CZeroes = MASSTOR_SIL;
  }
}

MASSTOR_LIST TFORM_TfZeroesI
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  MASSTOR_LIST c, m, z, p;

  TFORM_TfZeroes(tup, &c, &m, &z, &p);
  return SACLIST_LIST4(c, m, z, p);
}

MASSTOR_LIST TFORM_TfSignChs
# ifdef __STDC__
(MASSTOR_LIST tup)
# else
(tup)
MASSTOR_LIST tup;
# endif
{
  MASSTOR_LIST last, coeff, result;

  if (tup == MASSTOR_SIL) {
    return 0;
  }
  result = 0;
  MASSTOR_ADV(tup, &last, &tup);
  while (tup != MASSTOR_SIL) {
    MASSTOR_ADV(tup, &coeff, &tup);
    if (coeff != 0) {
      if (coeff + last == 0) {
        result = result + 1;
      }
      last = coeff;
    }
  }
  return result;
}

void BEGIN_TFORM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_MASELEM();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASLOG();
    BEGIN_MASSET();
    BEGIN_MASSTOR();
    BEGIN_MASSYM();
    BEGIN_MASSYM2();
    BEGIN_MLOGBASE();
    BEGIN_MLOGIO();
    BEGIN_LISTTOOLS();
    BEGIN_PQBASE();
    BEGIN_SACLIST();
    BEGIN_SACSET();

    TFORM_InitClassSyms();
    InitBbfParser();
    TypeFormulaProc = TFORM_ComputeTypeFormula;
  }
}
