#include "SYSTEM_.h"

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_DOMRN
#include "DOMRN.h"
#endif

#ifndef DEFINITION_LISTTOOLS
#include "LISTTOOLS.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
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

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_PQBASE
#include "PQBASE.h"
#endif

CHAR PQBASE_rcsid [] = "$Id: PQBASE.md,v 1.1 1994/11/28 21:10:01 dolzmann Exp $";
CHAR PQBASE_copyright [] = "Copyright (c) 1994 Universitaet Passau";
MASSTOR_LIST PQBASE_EQU, PQBASE_NEQ, PQBASE_GRE, PQBASE_LES, PQBASE_GRQ, PQBASE_LSQ;
MASSTOR_LIST PQBASE_PQSAF;
MASSTOR_LIST PQBASE_DOMAIN;

static CHAR rcsidi [] = "$Id: PQBASE.mi,v 1.2 1996/05/19 07:53:50 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1993 Universitaet Passau";
static MASSTOR_LIST BbfParserSyms;
static INTEGER NewVariables;
static void DITEX ARGS((MASSTOR_LIST C_127_A, MASSTOR_LIST V));
static MASSTOR_LIST DIPINORM ARGS((MASSTOR_LIST p, MASSTOR_LIST *rel));
static MASSTOR_LIST negrel ARGS((MASSTOR_LIST rel));
static void EnterVariableNames ARGS((MASSTOR_LIST valis));
static MASSTOR_LIST pqlsvars ARGS((MASSTOR_LIST af));
static MASSTOR_LIST PqsafSubstvar ARGS((MASSTOR_LIST af, MASSTOR_LIST old, MASSTOR_LIST new));
static MASSTOR_LIST PqsafNormalizeAf ARGS((MASSTOR_LIST af));


MASSTOR_LIST PQBASE_pqmkaf
# ifdef __STDC__
(MASSTOR_LIST rel, MASSTOR_LIST pol)
# else
(rel, pol)
MASSTOR_LIST rel;
MASSTOR_LIST pol;
# endif
{
  return SACLIST_LIST2(rel, pol);
}

void PQBASE_pqpaf
# ifdef __STDC__
(MASSTOR_LIST af, MASSTOR_LIST *rel, MASSTOR_LIST *pol)
# else
(af, rel, pol)
MASSTOR_LIST af;
MASSTOR_LIST *rel, *pol;
# endif
{
  SACLIST_FIRST2(af, rel, pol);
}

MASSTOR_LIST PQBASE_pqgrel
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  return MASSTOR_FIRST(af);
}

MASSTOR_LIST PQBASE_pqgpol
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  return SACLIST_SECOND(af);
}

BOOLEAN PQBASE_pqatom
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST rel, id;

  if (phi == MASSTOR_SIL || MASSYM_ATOM(phi) || MASSYM2_SYMBOL(phi)) {
    return FALSE;
  }
  MASSTOR_ADV(phi, &rel, &phi);
  if (phi == MASSTOR_SIL || MASSTOR_RED(phi) != MASSTOR_SIL) {
    return FALSE;
  }
  return rel == PQBASE_EQU || rel == PQBASE_NEQ || rel == PQBASE_LES || rel == PQBASE_GRE || rel == PQBASE_GRQ || rel == PQBASE_LSQ;
}

void PQBASE_pqprtaf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, pol;

  SACLIST_ADV2(af, &rel, &pol, &af);
  MASBIOS_SWRITE("[", 1L);
  DIPADOM_DIWRIT(pol, DIPC_VALIS);
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
    MASERR_ERROR(MASERR_severe, "pqprtaf: unknown relation symbol", 32L);
  }
}

void PQBASE_pqtexwaf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, pol;

  SACLIST_ADV2(af, &rel, &pol, &af);
  MASBIOS_BLINES(0);
  DITEX(pol, DIPC_VALIS);
  if (rel == PQBASE_EQU) {
    MASBIOS_SWRITE("=0", 2L);
  } else if (rel == PQBASE_NEQ) {
    MASBIOS_SWRITE("\\neq 0", 6L);
  } else if (rel == PQBASE_LES) {
    MASBIOS_SWRITE("<0", 2L);
  } else if (rel == PQBASE_GRE) {
    MASBIOS_SWRITE(">0", 2L);
  } else if (rel == PQBASE_LSQ) {
    MASBIOS_SWRITE("\\leq 0", 6L);
  } else if (rel == PQBASE_GRQ) {
    MASBIOS_SWRITE("\\geq 0", 6L);
  } else {
    MASERR_ERROR(MASERR_severe, "pqtexwaf: unknown relation symbol", 33L);
  }
}

static void DITEX
# ifdef __STDC__
(MASSTOR_LIST C_127_A, MASSTOR_LIST V)
# else
(C_127_A, V)
MASSTOR_LIST C_127_A, V;
# endif
{
  MASSTOR_LIST AL, AS, E, EL, FL, ES, LL, RL, SL, TL, VL, VS;

  if (C_127_A == 0) {
    SACLIST_AWRITE(C_127_A);
    return;
  }
  RL = DIPC_DIPNOV(C_127_A);
  if (RL == 0) {
    MASADOM_ADWRIT(DIPC_DIPLBC(C_127_A));
    return;
  }
  AS = C_127_A;
  FL = 0;
  do {
    DIPC_DIPMAD(AS, &AL, &E, &AS);
    MASBIOS_SWRITE(" ", 1L);
    SL = MASADOM_ADSIGN(AL);
    if (FL != 0) {
      if (SL > 0) {
        MASBIOS_SWRITE("+", 1L);
      }
      if (SL < 0) {
        MASBIOS_SWRITE("-", 1L);
        AL = MASADOM_ADNEG(AL);
      }
    }
    FL = 1;
    TL = DIPC_EVSIGN(E);
    if (TL == 0) {
      MASADOM_ADWRIT(AL);
    } else {
      SL = MASADOM_ADONE(AL);
      if (SL != 1) {
        MASADOM_ADWRIT(AL);
      }
      ES = SACLIST_CINV(E);
      VS = V;
      do {
        MASSTOR_ADV(ES, &EL, &ES);
        MASSTOR_ADV(VS, &VL, &VS);
        if (EL > 0) {
          MASBIOS_SWRITE(" ", 1L);
          SACLIST_CLOUT(VL);
          if (EL > 1) {
            MASBIOS_SWRITE("^{", 2L);
            SACLIST_AWRITE(EL);
            MASBIOS_SWRITE("}", 1L);
          }
        }
      } while (!(ES == MASSTOR_SIL));
    }
  } while (!(AS == MASSTOR_SIL));
  MASBIOS_SWRITE(" ", 1L);
  return;
}

MASSTOR_LIST PQBASE_pqnegaf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, pol;

  PQBASE_pqpaf(af, &rel, &pol);
  if (rel == PQBASE_EQU) {
    return PQBASE_pqmkaf(PQBASE_NEQ, pol);
  } else if (rel == PQBASE_NEQ) {
    return PQBASE_pqmkaf(PQBASE_EQU, pol);
  } else if (rel == PQBASE_GRE) {
    return PQBASE_pqmkaf(PQBASE_LSQ, pol);
  } else if (rel == PQBASE_LES) {
    return PQBASE_pqmkaf(PQBASE_GRQ, pol);
  } else if (rel == PQBASE_GRQ) {
    return PQBASE_pqmkaf(PQBASE_LES, pol);
  } else if (rel == PQBASE_LSQ) {
    return PQBASE_pqmkaf(PQBASE_GRE, pol);
  } else {
    MASERR_ERROR(MASERR_severe, "pqneqaf: unknown relation symbol in atomic formula.", 51L);
  }
}

MASSTOR_LIST PQBASE_pqsimplifyaf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, lhs, cnst, z, sgn, C_126_dummy;

  PQBASE_pqpaf(af, &rel, &lhs);
  if (lhs == 0 && (rel == PQBASE_EQU || rel == PQBASE_LSQ || rel == PQBASE_GRQ)) {
    return MLOGBASE_VERUM;
  } else if (lhs == 0 && (rel == PQBASE_NEQ || rel == PQBASE_LES || rel == PQBASE_GRE)) {
    return MLOGBASE_FALSUM;
  } else if (DIPTOOLS_DIPCNST(lhs)) {
    DIPC_DIPMAD(lhs, &cnst, &z, &C_126_dummy);
    sgn = MASADOM_ADSIGN(cnst);
    if (sgn == -1) {
      if (rel == PQBASE_LES || rel == PQBASE_LSQ || rel == PQBASE_NEQ) {
        return MLOGBASE_VERUM;
      } else {
        return MLOGBASE_FALSUM;
      }
    } else if (sgn == 0) {
      if (rel == PQBASE_EQU || rel == PQBASE_LSQ || rel == PQBASE_GRQ) {
        return MLOGBASE_VERUM;
      } else {
        return MLOGBASE_FALSUM;
      }
    } else if (sgn == 1) {
      if (rel == PQBASE_GRE || rel == PQBASE_GRQ || rel == PQBASE_NEQ) {
        return MLOGBASE_VERUM;
      } else {
        return MLOGBASE_FALSUM;
      }
    } else {
      MASERR_ERROR(MASERR_severe, "pqsimplifyaf: unknown ADSIGN value", 34L);
    }
  } else {
    lhs = DIPINORM(lhs, &rel);
    return PQBASE_pqmkaf(rel, lhs);
  }
}

static MASSTOR_LIST DIPINORM
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST *rel)
# else
(p, rel)
MASSTOR_LIST p;
MASSTOR_LIST *rel;
# endif
{
  MASSTOR_LIST content, ppt;

  MASADOM_ADPCPP(p, &content, &ppt);
  if (MASADOM_ADSIGN(content) == -1) {
    *rel = negrel(*rel);
  }
  return ppt;
}

static MASSTOR_LIST negrel
# ifdef __STDC__
(MASSTOR_LIST rel)
# else
(rel)
MASSTOR_LIST rel;
# endif
{
  if (rel == PQBASE_EQU) {
    return PQBASE_EQU;
  } else if (rel == PQBASE_NEQ) {
    return PQBASE_NEQ;
  } else if (rel == PQBASE_GRE) {
    return PQBASE_LES;
  } else if (rel == PQBASE_LES) {
    return PQBASE_GRE;
  } else if (rel == PQBASE_GRQ) {
    return PQBASE_LSQ;
  } else if (rel == PQBASE_LSQ) {
    return PQBASE_GRQ;
  } else {
    MASERR_ERROR(MASERR_severe, "negrel: unknown relation symbol in atomic formula.", 50L);
  }
}

MASSTOR_LIST PQBASE_pqreadaf
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST lhs, rhs, rel, sym;

  lhs = DIPADOM_DIREAD(DIPC_VALIS, PQBASE_DOMAIN);
  rel = MLOGIO_KEYREAD();
  sym = MASSYM2_ASSOCQ(rel, BbfParserSyms);
  if (sym == MASSTOR_SIL) {
    MASBIOS_DIBUFF();
    MASERR_ERROR(MASERR_severe, "pqreadaf: unknown relation symbol.", 34L);
    return PQBASE_pqmkaf(PQBASE_EQU, lhs);
  } else {
    rel = MASSTOR_FIRST(sym);
  }
  c = MASBIOS_CREADB();
  if (c == MASBIOS_MASORD(']')) {
    MASBIOS_BKSP();
    rhs = 0;
  } else {
    MASBIOS_BKSP();
    rhs = DIPADOM_DIREAD(DIPC_VALIS, PQBASE_DOMAIN);
    lhs = DIPADOM_DIPSUM(lhs, DIPADOM_DIPNEG(rhs));
  }
  return PQBASE_pqmkaf(rel, lhs);
}

void PQBASE_InitBbfParser
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
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("NEQ", 3L), PQBASE_NEQ, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("=", 1L), PQBASE_EQU, BbfParserSyms);
  BbfParserSyms = SACLIST_COMP2(MASBIOS_LISTS("!=", 2L), PQBASE_EQU, BbfParserSyms);
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

MASSTOR_LIST PQBASE_pqsmart
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST op, L, result;

  MLOGBASE_FORPFOR(phi, &op, &L);
  if (op == MLOGBASE_ET) {
    result = PQBASE_ContractEt(L);
  } else if (op == MLOGBASE_VEL) {
    result = PQBASE_ContractVel(L);
  } else {
    MASBIOS_BLINES(0);
    MASSYM2_UWRIT1(op);
    MASERR_ERROR(MASERR_spotless, "pqsmart: operator symbol not valid.", 35L);
    return phi;
  }
  if (result == MLOGBASE_VERUM || result == MLOGBASE_FALSUM) {
    return result;
  } else {
    return MLOGBASE_FORMKFOR(op, result);
  }
}

MASSTOR_LIST PQBASE_ContractVel
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  MASSTOR_LIST mem, atom, rel, term, rels, fpoint, result;

  mem = MASSTOR_SIL;
  while (l != MASSTOR_SIL) {
    MASSTOR_ADV(l, &atom, &l);
    PQBASE_pqpaf(atom, &rel, &term);
    fpoint = MASSYM2_ASSOCQ(term, mem);
    if (fpoint == MASSTOR_SIL) {
      mem = SACLIST_COMP2(term, rel, mem);
    } else {
      rels = MASSTOR_FIRST(fpoint);
      rels = PQBASE_PQCRELOR(rels, rel);
      MASSTOR_SFIRST(fpoint, rels);
      if (rels == MLOGBASE_VERUM) {
        return MLOGBASE_VERUM;
      }
    }
  }
  result = MASSTOR_SIL;
  while (mem != MASSTOR_SIL) {
    SACLIST_ADV2(mem, &term, &rel, &mem);
    result = MASSTOR_COMP(PQBASE_pqmkaf(rel, term), result);
  }
  return result;
}

MASSTOR_LIST PQBASE_PQCRELOR
# ifdef __STDC__
(MASSTOR_LIST left, MASSTOR_LIST right)
# else
(left, right)
MASSTOR_LIST left, right;
# endif
{
  if (left == MASSTOR_SIL) {
    return right;
  } else if (right == MASSTOR_SIL) {
    return left;
  } else if (left == MLOGBASE_FALSUM) {
    return right;
  } else if (right == MLOGBASE_FALSUM) {
    return left;
  } else if (left == MLOGBASE_VERUM || right == MLOGBASE_VERUM) {
    return MLOGBASE_VERUM;
  } else if (left == right) {
    return right;
  }
  if (left == PQBASE_LES) {
    if (right == PQBASE_LSQ) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_EQU) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_NEQ;
    } else if (right == PQBASE_GRQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRE) {
      return PQBASE_NEQ;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else if (left == PQBASE_LSQ) {
    if (right == PQBASE_LES) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_EQU) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_NEQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRE) {
      return MLOGBASE_VERUM;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else if (left == PQBASE_EQU) {
    if (right == PQBASE_LES) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_LSQ) {
      return PQBASE_LSQ;
    } else if (right == PQBASE_NEQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRQ) {
      return PQBASE_GRQ;
    } else if (right == PQBASE_GRE) {
      return PQBASE_GRQ;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else if (left == PQBASE_NEQ) {
    if (right == PQBASE_LES) {
      return PQBASE_NEQ;
    } else if (right == PQBASE_LSQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_EQU) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRE) {
      return PQBASE_NEQ;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else if (left == PQBASE_GRQ) {
    if (right == PQBASE_LES) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_LSQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_EQU) {
      return PQBASE_GRQ;
    } else if (right == PQBASE_NEQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_GRE) {
      return PQBASE_GRQ;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else if (left == PQBASE_GRE) {
    if (right == PQBASE_LES) {
      return PQBASE_NEQ;
    } else if (right == PQBASE_LSQ) {
      return MLOGBASE_VERUM;
    } else if (right == PQBASE_EQU) {
      return PQBASE_GRQ;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_NEQ;
    } else if (right == PQBASE_GRQ) {
      return PQBASE_GRQ;
    } else {
      MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
    }
  } else {
    MASERR_ERROR(MASERR_severe, "PQCRELOR: unknown relation symbol.", 34L);
  }
}

MASSTOR_LIST PQBASE_ContractEt
# ifdef __STDC__
(MASSTOR_LIST l)
# else
(l)
MASSTOR_LIST l;
# endif
{
  MASSTOR_LIST mem, atom, rel, term, rels, fpoint, result;

  mem = MASSTOR_SIL;
  while (l != MASSTOR_SIL) {
    MASSTOR_ADV(l, &atom, &l);
    PQBASE_pqpaf(atom, &rel, &term);
    fpoint = MASSYM2_ASSOCQ(term, mem);
    if (fpoint == MASSTOR_SIL) {
      mem = SACLIST_COMP2(term, rel, mem);
    } else {
      rels = MASSTOR_FIRST(fpoint);
      rels = PQBASE_PQCRELAND(rels, rel);
      MASSTOR_SFIRST(fpoint, rels);
      if (rels == MLOGBASE_FALSUM) {
        return MLOGBASE_FALSUM;
      }
    }
  }
  result = MASSTOR_SIL;
  while (mem != MASSTOR_SIL) {
    SACLIST_ADV2(mem, &term, &rel, &mem);
    result = MASSTOR_COMP(PQBASE_pqmkaf(rel, term), result);
  }
  return result;
}

MASSTOR_LIST PQBASE_PQCRELAND
# ifdef __STDC__
(MASSTOR_LIST left, MASSTOR_LIST right)
# else
(left, right)
MASSTOR_LIST left, right;
# endif
{
  if (left == MASSTOR_SIL) {
    return right;
  }
  if (left == right) {
    return right;
  }
  if (left == MLOGBASE_FALSUM) {
    return right;
  }
  if (left == PQBASE_LES) {
    if (right == PQBASE_LSQ) {
      return PQBASE_LES;
    } else if (right == PQBASE_EQU) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_LES;
    } else if (right == PQBASE_GRQ) {
      return MLOGBASE_FALSUM;
    } else {
      return MLOGBASE_FALSUM;
    }
  } else if (left == PQBASE_LSQ) {
    if (right == PQBASE_LES) {
      return PQBASE_LES;
    } else if (right == PQBASE_EQU) {
      return PQBASE_EQU;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_LES;
    } else if (right == PQBASE_GRQ) {
      return PQBASE_EQU;
    } else {
      return MLOGBASE_FALSUM;
    }
  } else if (left == PQBASE_EQU) {
    if (right == PQBASE_LES) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_LSQ) {
      return PQBASE_EQU;
    } else if (right == PQBASE_NEQ) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_GRQ) {
      return PQBASE_EQU;
    } else {
      return MLOGBASE_FALSUM;
    }
  } else if (left == PQBASE_NEQ) {
    if (right == PQBASE_LES) {
      return PQBASE_LES;
    } else if (right == PQBASE_LSQ) {
      return PQBASE_LES;
    } else if (right == PQBASE_EQU) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_GRQ) {
      return PQBASE_GRE;
    } else {
      return PQBASE_GRE;
    }
  } else if (left == PQBASE_GRQ) {
    if (right == PQBASE_LES) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_LSQ) {
      return PQBASE_EQU;
    } else if (right == PQBASE_EQU) {
      return PQBASE_EQU;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_GRE;
    } else {
      return PQBASE_GRE;
    }
  } else {
    if (right == PQBASE_LES) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_LSQ) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_EQU) {
      return MLOGBASE_FALSUM;
    } else if (right == PQBASE_NEQ) {
      return PQBASE_GRE;
    } else {
      return PQBASE_GRE;
    }
  }
}

static void EnterVariableNames
# ifdef __STDC__
(MASSTOR_LIST valis)
# else
(valis)
MASSTOR_LIST valis;
# endif
{
  MASSTOR_LIST var, C_125_dummy;

  while (valis != MASSTOR_SIL) {
    MASSTOR_ADV(valis, &var, &valis);
    C_125_dummy = MLOGBASE_FORVTENTER(var);
  }
}

static MASSTOR_LIST pqlsvars
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST rel, pol, var, result, valis, vv, v;

  pol = PQBASE_pqgpol(af);
  if (pol == 0) {
    return MASSTOR_SIL;
  }
  result = MASSTOR_SIL;
  vv = MASSTOR_INV(DIPTOOLS_DIPMVV(pol));
  valis = DIPC_VALIS;
  while (vv != MASSTOR_SIL) {
    MASSTOR_ADV(vv, &v, &vv);
    MASSTOR_ADV(valis, &var, &valis);
    if (v == 1) {
      result = MASSTOR_COMP(MLOGBASE_FORMKVAR(MLOGBASE_FORVTENTER(var), MLOGBASE_ANY), result);
    }
  }
  return result;
}

static MASSTOR_LIST PqsafSubstvar
# ifdef __STDC__
(MASSTOR_LIST af, MASSTOR_LIST old, MASSTOR_LIST new)
# else
(af, old, new)
MASSTOR_LIST af, old, new;
# endif
{
  MASSTOR_LIST oIndex, nIndex, name, type, n;

  MLOGBASE_FORPVAR(old, &name, &type);
  oIndex = LISTTOOLS_LSRCHQ(MLOGBASE_FORVTGET(name), DIPC_VALIS);
  MLOGBASE_FORPVAR(new, &name, &type);
  nIndex = LISTTOOLS_LSRCHQ(MLOGBASE_FORVTGET(name), DIPC_VALIS);
  if (nIndex == 0) {
    NewVariables = NewVariables + 1;
    DIPC_VALIS = SACLIST_SUFFIX(DIPC_VALIS, MLOGBASE_FORVTGET(name));
    nIndex = MASSTOR_LENGTH(DIPC_VALIS);
  }
  if (MLOGBASE_FORGOP(af) != PQBASE_PQSAF) {
    return SACLIST_LIST3(PQBASE_PQSAF, MASSTOR_LIST1(SACLIST_LIST2(oIndex, nIndex)), af);
  } else {
    return SACLIST_LIST3(PQBASE_PQSAF, MASSTOR_COMP(SACLIST_LIST2(oIndex, nIndex), SACLIST_SECOND(af)), SACLIST_THIRD(af));
  }
}

static MASSTOR_LIST PqsafNormalizeAf
# ifdef __STDC__
(MASSTOR_LIST af)
# else
(af)
MASSTOR_LIST af;
# endif
{
  MASSTOR_LIST op, pol, rel, subst, s, o, n, i, length, perm;

  op = MLOGBASE_FORGOP(af);
  if (op == MLOGBASE_VERUM || op == MLOGBASE_FALSUM) {
    return af;
  }
  if (op != PQBASE_PQSAF && NewVariables == 0) {
    return af;
  }
  if (op == PQBASE_PQSAF) {
    PQBASE_pqpaf(SACLIST_THIRD(af), &rel, &pol);
    subst = SACLIST_SECOND(af);
  } else {
    PQBASE_pqpaf(af, &rel, &pol);
    subst = MASSTOR_SIL;
  }
  length = MASSTOR_LENGTH(DIPC_VALIS);
  if (NewVariables > 0) {
    pol = DIPC_DIPINV(pol, length - NewVariables + 1, NewVariables);
  }
  perm = MASSTOR_SIL;
  for (i = length; i >= 1; i += -1) {
    perm = MASSTOR_COMP(i, perm);
  }
  while (subst != MASSTOR_SIL) {
    MASSTOR_ADV(subst, &s, &subst);
    SACLIST_FIRST2(s, &o, &n);
    SACLIST_SLELT(perm, n, o);
    SACLIST_SLELT(perm, o, n);
  }
  pol = DIPC_DIPERM(pol, perm);
  return PQBASE_pqmkaf(rel, pol);
}

MASSTOR_LIST PQBASE_PQMKVD
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MASSTOR_LIST psi;

  NewVariables = 0;
  EnterVariableNames(DIPC_VALIS);
  psi = MASLOG_FORMKVD(phi, PqsafSubstvar, pqlsvars);
  psi = MASLOG_FORAPPLYAT(psi, PqsafNormalizeAf);
  return psi;
}

MASSTOR_LIST PQBASE_vlistflvar
# ifdef __STDC__
(MASSTOR_LIST lvar)
# else
(lvar)
MASSTOR_LIST lvar;
# endif
{
  MASSTOR_LIST result, var, name, sort;

  lvar = MLOGBASE_FORGLVAR(lvar);
  result = MASSTOR_SIL;
  while (lvar != MASSTOR_SIL) {
    MASSTOR_ADV(lvar, &var, &lvar);
    MLOGBASE_FORPVAR(var, &name, &sort);
    result = MASSTOR_COMP(MLOGBASE_FORVTGET(name), result);
  }
  return MASSTOR_INV(result);
}

MASSTOR_LIST PQBASE_lvarfvlist
# ifdef __STDC__
(MASSTOR_LIST vlist)
# else
(vlist)
MASSTOR_LIST vlist;
# endif
{
  MASSTOR_LIST result, v;

  result = MASSTOR_SIL;
  while (vlist != MASSTOR_SIL) {
    MASSTOR_ADV(vlist, &v, &vlist);
    result = MASSTOR_COMP(MLOGBASE_FORMKVAR(MLOGBASE_FORVTENTER(v), MLOGBASE_ANY), result);
  }
  return MLOGBASE_FORMKLVAR(MASSTOR_INV(result));
}

MASSTOR_LIST PQBASE_PQMKDNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKDNF(phi, PQBASE_pqnegaf);
}

MASSTOR_LIST PQBASE_PQMKCNF
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKCNF(phi, PQBASE_pqnegaf);
}

MASSTOR_LIST PQBASE_PQSMPL
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORSMPL(phi, PQBASE_pqsimplifyaf, PQBASE_pqnegaf);
}

MASSTOR_LIST PQBASE_PQSIMPLIFY
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORSIMPLIFY(phi, PQBASE_pqsmart, PQBASE_pqsimplifyaf, PQBASE_pqnegaf);
}

MASSTOR_LIST PQBASE_PQSIMPLIFYP
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST maxlevel)
# else
(phi, maxlevel)
MASSTOR_LIST phi, maxlevel;
# endif
{
  return MASLOG_FORSIMPLIFYP(phi, maxlevel, PQBASE_pqsmart, PQBASE_pqsimplifyaf, PQBASE_pqnegaf);
}

MASSTOR_LIST PQBASE_PQMKPOS
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORMKPOS(phi, MLOGBASE_ET, PQBASE_pqnegaf);
}

void PQBASE_PQPPRT
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MLOGIO_FORPPRT(phi, PQBASE_pqprtaf);
}

void PQBASE_PQTEXW
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  MLOGIO_FORTEXW(phi, PQBASE_pqtexwaf);
}

MASSTOR_LIST PQBASE_PQPREAD
# ifdef __STDC__
()
# else
()
# endif
{
  return MLOGIO_FORPREAD(PQBASE_pqreadaf);
}

MASSTOR_LIST PQBASE_PQIREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASELEM_GAMMAINT c;
  MASSTOR_LIST keyword, value;

  c = MASBIOS_CREADB();
  if (c != MASBIOS_MASORD('{')) {
    MASBIOS_BKSP();
  } else {
    do {
      keyword = MASSYM2_SREAD1();
      c = MASBIOS_CREADB();
      if (c != MASBIOS_MASORD('=')) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "PQIREAD: = expected", 19L);
      }
      if (SACLIST_EQUAL(keyword, MASBIOS_LISTS("DOMAIN", 6L)) == 1) {
        PQBASE_DOMAIN = MASADOM_ADDDREAD();
      } else if (SACLIST_EQUAL(keyword, MASBIOS_LISTS("VALIS", 5L)) == 1) {
        DIPC_VALIS = SACPOL_VLREAD();
      } else if (SACLIST_EQUAL(keyword, MASBIOS_LISTS("EVORD", 5L)) == 1) {
        DIPC_EVORD = MASSYM2_UREAD();
      }
      c = MASBIOS_CREADB();
      if (c != MASBIOS_MASORD(',') && c != MASBIOS_MASORD('}')) {
        MASBIOS_DIBUFF();
        MASERR_ERROR(MASERR_severe, "PQIREAD: , or = expected", 24L);
      }
    } while (!(c == MASBIOS_MASORD('}')));
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("DOMAIN: ", 8L);
    MASADOM_ADDDWRIT(PQBASE_DOMAIN);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("VALIS:  ", 8L);
    SACPOL_VLWRIT(DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("EVORD:  ", 8L);
    MASSYM2_UWRITE(DIPC_EVORD);
    MASBIOS_BLINES(1);
  }
  return MLOGIO_FORIREAD(PQBASE_pqreadaf);
}

MASSTOR_LIST PQBASE_PQELIMXOPS
# ifdef __STDC__
(MASSTOR_LIST phi)
# else
(phi)
MASSTOR_LIST phi;
# endif
{
  return MASLOG_FORELIMXOPS(phi, MLOGBASE_ET);
}

MASSTOR_LIST PQBASE_PQELIMXOPS1
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  return MASLOG_FORELIMXOPS(phi, pref);
}

MASSTOR_LIST PQBASE_PQMKPRENEX
# ifdef __STDC__
(MASSTOR_LIST phi, MASSTOR_LIST pref)
# else
(phi, pref)
MASSTOR_LIST phi, pref;
# endif
{
  return MASLOG_FORMKPRENEX(phi, pref);
}

MASSTOR_LIST PQBASE_PQPRING
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST old;

  old = SACLIST_LIST3(PQBASE_DOMAIN, DIPC_VALIS, DIPC_EVORD);
  if (R != MASSTOR_SIL) {
    if (MASSTOR_FIRST(R) != -1) {
      MASSTOR_ADV(R, &PQBASE_DOMAIN, &R);
    } else {
      R = MASSTOR_RED(R);
    }
  }
  if (R != MASSTOR_SIL) {
    if (MASSTOR_FIRST(R) != -1) {
      MASSTOR_ADV(R, &DIPC_VALIS, &R);
    } else {
      R = MASSTOR_RED(R);
    }
  }
  if (R != MASSTOR_SIL) {
    if (MASSTOR_FIRST(R) != -1) {
      MASSTOR_ADV(R, &DIPC_EVORD, &R);
    } else {
      R = MASSTOR_RED(R);
    }
  }
  return old;
}

void PQBASE_PQPRINGWR
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST variable, varlist;

  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Specification of the polynomial ring:", 37L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  The domain: ", 14L);
  MASADOM_ADDDWRIT(PQBASE_DOMAIN);
  MASBIOS_BLINES(0);
  if (DIPC_VALIS == MASSTOR_SIL) {
    MASBIOS_SWRITE("No list of variables specified!", 31L);
  } else {
    MASBIOS_SWRITE("  The list of variables: ", 25L);
    SACPOL_VLWRIT(DIPC_VALIS);
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("  The term order of the polynomial ring: ", 41L);
  if (DIPC_EVORD > MASSTOR_SIL) {
    MASBIOS_SWRITE("user defined term order:", 24L);
    MASSYM2_UWRIT1(DIPC_EVORD);
  } else {
    switch ((INTEGER)DIPC_EVORD) {
    case DIPC_LEX:;
      MASBIOS_SWRITE("LEX", 3L);
      break;
    case DIPC_INVLEX:;
      MASBIOS_SWRITE("INVLEX", 6L);
      break;
    case DIPC_GRLEX:;
      MASBIOS_SWRITE("GRLEX", 5L);
      break;
    case DIPC_IGRLEX:;
      MASBIOS_SWRITE("IGRLEX", 6L);
      break;
    case DIPC_REVLEX:;
      MASBIOS_SWRITE("REVLEX", 6L);
      break;
    case DIPC_REVILEX:;
      MASBIOS_SWRITE("REVILEX", 7L);
      break;
    case DIPC_REVTDEG:;
      MASBIOS_SWRITE("REVTDEG", 7L);
      break;
    case DIPC_REVITDG:;
      MASBIOS_SWRITE("REVITDG", 7L);
      break;
    default :
      MASBIOS_SWRITE("WARNING: unknown term order indicator.", 38L);
      break;
    }
  }
  MASBIOS_BLINES(1);
}

void BEGIN_PQBASE()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPTOOLS();
    BEGIN_DOMRN();
    BEGIN_LISTTOOLS();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
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
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_SACSET();

    MASLISPU_Declare(&PQBASE_EQU, "EQU", 3L);
    MASLISPU_Declare(&PQBASE_NEQ, "NEQ", 3L);
    MASLISPU_Declare(&PQBASE_LES, "LES", 3L);
    MASLISPU_Declare(&PQBASE_LSQ, "LSQ", 3L);
    MASLISPU_Declare(&PQBASE_GRQ, "GRQ", 3L);
    MASLISPU_Declare(&PQBASE_GRE, "GRE", 3L);
    MASLISPU_Declare(&PQBASE_PQSAF, "PQSAF", 5L);
    MASSTOR_LISTVAR(&PQBASE_DOMAIN);
    PQBASE_InitBbfParser();
    PQBASE_DOMAIN = SACLIST_LIST3(8, 0, -1);
  }
}
