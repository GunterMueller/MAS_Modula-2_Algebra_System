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

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
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

CHAR MASLISPU_rcsid [] = "$Id: MASLISPU.md,v 1.2 1992/02/12 17:32:23 pesch Exp $";
CHAR MASLISPU_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
MASSTOR_LIST MASLISPU_EXTYP, MASLISPU_ARITY, MASLISPU_SUBR;

#define PIND	0
#define FIND	-1
static CHAR rcsidi [] = "$Id: MASLISPU.mi,v 1.3 1992/10/15 16:27:48 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";
static void Compiled ARGS((ADDRESS P, MASSTOR_LIST T, CHAR S[], LONGCARD ));


void MASLISPU_CallCompiled
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST PI, MASSTOR_LIST *PO, BOOLEAN *fu)
# else
(F, PI, PO, fu)
MASSTOR_LIST F, PI;
MASSTOR_LIST *PO;
BOOLEAN *fu;
# endif
{
  MASSTOR_LIST L, PT, I, O, I1, I2, I3, I4, I5, O1, O2, O3, C;
  INTEGER i, o;
  ADDRESS P;
  MASLISPU_PROCF0 F0;
  MASLISPU_PROCF1 F1;
  MASLISPU_PROCF2 F2;
  MASLISPU_PROCF3 F3;
  MASLISPU_PROCF4 F4;
  MASLISPU_PROCF5 F5;
  MASLISPU_PROCP0 P0;
  MASLISPU_PROCP1 P1;
  MASLISPU_PROCP2 P2;
  MASLISPU_PROCP3 P3;
  MASLISPU_PROCP4 P4;
  MASLISPU_PROCP5 P5;
  MASLISPU_PROCP0V1 P0V1;
  MASLISPU_PROCP0V2 P0V2;
  MASLISPU_PROCP1V1 P1V1;
  MASLISPU_PROCP1V2 P1V2;
  MASLISPU_PROCP1V3 P1V3;
  MASLISPU_PROCP2V1 P2V1;
  MASLISPU_PROCP2V2 P2V2;
  MASLISPU_PROCP2V3 P2V3;
  MASLISPU_PROCP3V1 P3V1;
  MASLISPU_PROCP3V2 P3V2;
  MASLISPU_PROCP3V3 P3V3;

  *fu = FALSE;
  C = MASSYM2_GET(F, MASLISPU_ARITY);
  L = MASSYM2_GET(F, MASLISPU_SUBR);
  if (L == MASSTOR_SIL || C <= MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "CallCompiled: unbound compiled procedure ", 41L);
    MASSYM_UWRITE(F);
    return;
  }
  MASSTOR_ADV(L, &PT, &L);
  if (L == MASSTOR_SIL || PT != MASSYM_NOSHOW) {
    MASERR_ERROR(MASERR_severe, "CallCompiled: invalid code pointer ", 35L);
    MASSYM_UWRITE(F);
    return;
  }
  P = (ADDRESS)MASSTOR_FIRST(L);
  SACLIST_FIRST3(C, &PT, &I, &O);
  if (MASSTOR_LENGTH(PI) != I) {
    MASERR_ERROR(MASERR_severe, "CallCompiled: input parameter mismatch ", 39L);
    MASSYM_UWRITE(F);
    return;
  }
  if (MASSTOR_LENGTH(*PO) != O) {
    MASERR_ERROR(MASERR_severe, "CallCompiled: output parameter mismatch ", 40L);
    MASSYM_UWRITE(F);
    return;
  }
  i = (INTEGER)I;
  o = (INTEGER)O;
  if (PT == FIND) {
    switch (i) {
    case 0:;
      F0 = (MASLISPU_PROCF0)P;
      *PO = (*F0)();
      break;
    case 1:;
      F1 = (MASLISPU_PROCF1)P;
      I1 = MASSTOR_FIRST(PI);
      *PO = (*F1)(I1);
      break;
    case 2:;
      F2 = (MASLISPU_PROCF2)P;
      SACLIST_FIRST2(PI, &I1, &I2);
      *PO = (*F2)(I1, I2);
      break;
    case 3:;
      F3 = (MASLISPU_PROCF3)P;
      SACLIST_FIRST3(PI, &I1, &I2, &I3);
      *PO = (*F3)(I1, I2, I3);
      break;
    case 4:;
      F4 = (MASLISPU_PROCF4)P;
      SACLIST_FIRST4(PI, &I1, &I2, &I3, &I4);
      *PO = (*F4)(I1, I2, I3, I4);
      break;
    case 5:;
      F5 = (MASLISPU_PROCF5)P;
      MASSTOR_ADV(PI, &I1, &PI);
      SACLIST_FIRST4(PI, &I2, &I3, &I4, &I5);
      *PO = (*F5)(I1, I2, I3, I4, I5);
      break;
    default :
      MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
      MASSYM_UWRITE(F);
      break;
    }
    *fu = TRUE;
    return;
  }
  if (PT == PIND) {
    switch (i) {
    case 0:;
      switch (o) {
      case 0:;
        P0 = (MASLISPU_PROCP0)P;
        (*P0)();
        break;
      case 1:;
        P0V1 = (MASLISPU_PROCP0V1)P;
        O1 = MASSTOR_FIRST(*PO);
        (*P0V1)(&O1);
        *PO = MASSTOR_LIST1(O1);
        break;
      case 2:;
        P0V2 = (MASLISPU_PROCP0V2)P;
        SACLIST_FIRST2(*PO, &O1, &O2);
        (*P0V2)(&O1, &O2);
        *PO = SACLIST_LIST2(O1, O2);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    case 1:;
      switch (o) {
      case 0:;
        P1 = (MASLISPU_PROCP1)P;
        I1 = MASSTOR_FIRST(PI);
        (*P1)(I1);
        break;
      case 1:;
        P1V1 = (MASLISPU_PROCP1V1)P;
        I1 = MASSTOR_FIRST(PI);
        O1 = MASSTOR_FIRST(*PO);
        (*P1V1)(I1, &O1);
        *PO = MASSTOR_LIST1(O1);
        break;
      case 2:;
        P1V2 = (MASLISPU_PROCP1V2)P;
        I1 = MASSTOR_FIRST(PI);
        SACLIST_FIRST2(*PO, &O1, &O2);
        (*P1V2)(I1, &O1, &O2);
        *PO = SACLIST_LIST2(O1, O2);
        break;
      case 3:;
        P1V3 = (MASLISPU_PROCP1V3)P;
        I1 = MASSTOR_FIRST(PI);
        SACLIST_FIRST3(*PO, &O1, &O2, &O3);
        (*P1V3)(I1, &O1, &O2, &O3);
        *PO = SACLIST_LIST3(O1, O2, O3);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    case 2:;
      switch (o) {
      case 0:;
        P2 = (MASLISPU_PROCP2)P;
        SACLIST_FIRST2(PI, &I1, &I2);
        (*P2)(I1, I2);
        break;
      case 1:;
        P2V1 = (MASLISPU_PROCP2V1)P;
        SACLIST_FIRST2(PI, &I1, &I2);
        O1 = MASSTOR_FIRST(*PO);
        (*P2V1)(I1, I2, &O1);
        *PO = MASSTOR_LIST1(O1);
        break;
      case 2:;
        P2V2 = (MASLISPU_PROCP2V2)P;
        SACLIST_FIRST2(PI, &I1, &I2);
        SACLIST_FIRST2(*PO, &O1, &O2);
        (*P2V2)(I1, I2, &O1, &O2);
        *PO = SACLIST_LIST2(O1, O2);
        break;
      case 3:;
        P2V3 = (MASLISPU_PROCP2V3)P;
        SACLIST_FIRST2(PI, &I1, &I2);
        SACLIST_FIRST3(*PO, &O1, &O2, &O3);
        (*P2V3)(I1, I2, &O1, &O2, &O3);
        *PO = SACLIST_LIST3(O1, O2, O3);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    case 3:;
      switch (o) {
      case 0:;
        P3 = (MASLISPU_PROCP3)P;
        SACLIST_FIRST3(PI, &I1, &I2, &I3);
        (*P3)(I1, I2, I3);
        break;
      case 1:;
        P3V1 = (MASLISPU_PROCP3V1)P;
        SACLIST_FIRST3(PI, &I1, &I2, &I3);
        O1 = MASSTOR_FIRST(*PO);
        (*P3V1)(I1, I2, I3, &O1);
        *PO = MASSTOR_LIST1(O1);
        break;
      case 2:;
        P3V2 = (MASLISPU_PROCP3V2)P;
        SACLIST_FIRST3(PI, &I1, &I2, &I3);
        SACLIST_FIRST2(*PO, &O1, &O2);
        (*P3V2)(I1, I2, I3, &O1, &O2);
        *PO = SACLIST_LIST2(O1, O2);
        break;
      case 3:;
        P3V3 = (MASLISPU_PROCP3V3)P;
        SACLIST_FIRST3(PI, &I1, &I2, &I3);
        SACLIST_FIRST3(*PO, &O1, &O2, &O3);
        (*P3V3)(I1, I2, I3, &O1, &O2, &O3);
        *PO = SACLIST_LIST3(O1, O2, O3);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    case 4:;
      switch (o) {
      case 0:;
        P4 = (MASLISPU_PROCP4)P;
        SACLIST_FIRST4(PI, &I1, &I2, &I3, &I4);
        (*P4)(I1, I2, I3, I4);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    case 5:;
      switch (o) {
      case 0:;
        P5 = (MASLISPU_PROCP5)P;
        MASSTOR_ADV(PI, &I1, &PI);
        SACLIST_FIRST4(PI, &I2, &I3, &I4, &I5);
        (*P5)(I1, I2, I3, I4, I5);
        break;
      default :
        MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
        MASSYM_UWRITE(F);
        break;
      }
      break;
    default :
      MASERR_ERROR(MASERR_severe, "CallCompiled: unknown parameter number ", 39L);
      MASSYM_UWRITE(F);
      break;
    }
    return;
  }
  MASERR_ERROR(MASERR_severe, "CallCompiled: unknown procedure type ", 37L);
  MASSYM_UWRITE(F);
  return;
}

static void Compiled
# ifdef __STDC__
(ADDRESS P, MASSTOR_LIST T, CHAR S[], LONGCARD O_1)
# else
(P, T, S, O_1)
ADDRESS P;
MASSTOR_LIST T;
CHAR S[];
LONGCARD O_1;
# endif
{
  MASSTOR_LIST X, Y;
  MASELEM_GAMMAINT L;

  X = MASSYM2_ENTER(MASBIOS_LISTS(S, O_1));
  Y = MASSYM2_GET(X, MASLISPU_ARITY);
  if (Y != MASSTOR_SIL) {
    MASSYM_UWRITE(X);
    MASERR_ERROR(MASERR_harmless, "arity redefined", 15L);
  }
  MASSYM2_PUT(X, MASLISPU_ARITY, T);
  Y = MASSYM2_GET(X, MASLISPU_SUBR);
  if (Y != MASSTOR_SIL) {
    MASSYM_UWRITE(X);
    MASERR_ERROR(MASERR_harmless, "code pointer redefined", 22L);
  }
  L = SACLIST_LIST2(MASSYM_NOSHOW, (MASELEM_GAMMAINT)P);
  MASSYM2_PUT(X, MASLISPU_SUBR, L);
  MASSYM2_PUT(X, MASLISPU_EXTYP, MASLISPU_EXPR);
}

void MASLISPU_Compiledp0
# ifdef __STDC__
(MASLISPU_PROCP0 F, CHAR S[], LONGCARD O_2)
# else
(F, S, O_2)
MASLISPU_PROCP0 F;
CHAR S[];
LONGCARD O_2;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 0, 0);
  Compiled(P, TP, S, O_2);
}

void MASLISPU_Compiledp1
# ifdef __STDC__
(MASLISPU_PROCP1 F, CHAR S[], LONGCARD O_3)
# else
(F, S, O_3)
MASLISPU_PROCP1 F;
CHAR S[];
LONGCARD O_3;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 1, 0);
  Compiled(P, TP, S, O_3);
}

void MASLISPU_Compiledp2
# ifdef __STDC__
(MASLISPU_PROCP2 F, CHAR S[], LONGCARD O_4)
# else
(F, S, O_4)
MASLISPU_PROCP2 F;
CHAR S[];
LONGCARD O_4;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 2, 0);
  Compiled(P, TP, S, O_4);
}

void MASLISPU_Compiledp3
# ifdef __STDC__
(MASLISPU_PROCP3 F, CHAR S[], LONGCARD O_5)
# else
(F, S, O_5)
MASLISPU_PROCP3 F;
CHAR S[];
LONGCARD O_5;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 3, 0);
  Compiled(P, TP, S, O_5);
}

void MASLISPU_Compiledp4
# ifdef __STDC__
(MASLISPU_PROCP4 F, CHAR S[], LONGCARD O_6)
# else
(F, S, O_6)
MASLISPU_PROCP4 F;
CHAR S[];
LONGCARD O_6;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 4, 0);
  Compiled(P, TP, S, O_6);
}

void MASLISPU_Compiledp5
# ifdef __STDC__
(MASLISPU_PROCP5 F, CHAR S[], LONGCARD O_7)
# else
(F, S, O_7)
MASLISPU_PROCP5 F;
CHAR S[];
LONGCARD O_7;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 5, 0);
  Compiled(P, TP, S, O_7);
}

void MASLISPU_Compiledf0
# ifdef __STDC__
(MASLISPU_PROCF0 F, CHAR S[], LONGCARD O_8)
# else
(F, S, O_8)
MASLISPU_PROCF0 F;
CHAR S[];
LONGCARD O_8;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 0, 0);
  Compiled(P, TP, S, O_8);
}

void MASLISPU_Compiledf1
# ifdef __STDC__
(MASLISPU_PROCF1 F, CHAR S[], LONGCARD O_9)
# else
(F, S, O_9)
MASLISPU_PROCF1 F;
CHAR S[];
LONGCARD O_9;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 1, 0);
  Compiled(P, TP, S, O_9);
}

void MASLISPU_Compiledf2
# ifdef __STDC__
(MASLISPU_PROCF2 F, CHAR S[], LONGCARD O_10)
# else
(F, S, O_10)
MASLISPU_PROCF2 F;
CHAR S[];
LONGCARD O_10;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 2, 0);
  Compiled(P, TP, S, O_10);
}

void MASLISPU_Compiledf3
# ifdef __STDC__
(MASLISPU_PROCF3 F, CHAR S[], LONGCARD O_11)
# else
(F, S, O_11)
MASLISPU_PROCF3 F;
CHAR S[];
LONGCARD O_11;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 3, 0);
  Compiled(P, TP, S, O_11);
}

void MASLISPU_Compiledf4
# ifdef __STDC__
(MASLISPU_PROCF4 F, CHAR S[], LONGCARD O_12)
# else
(F, S, O_12)
MASLISPU_PROCF4 F;
CHAR S[];
LONGCARD O_12;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 4, 0);
  Compiled(P, TP, S, O_12);
}

void MASLISPU_Compiledf5
# ifdef __STDC__
(MASLISPU_PROCF5 F, CHAR S[], LONGCARD O_13)
# else
(F, S, O_13)
MASLISPU_PROCF5 F;
CHAR S[];
LONGCARD O_13;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(FIND, 5, 0);
  Compiled(P, TP, S, O_13);
}

void MASLISPU_Compiledp1v2
# ifdef __STDC__
(MASLISPU_PROCP1V2 F, CHAR S[], LONGCARD O_14)
# else
(F, S, O_14)
MASLISPU_PROCP1V2 F;
CHAR S[];
LONGCARD O_14;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 1, 2);
  Compiled(P, TP, S, O_14);
}

void MASLISPU_Compiledp1v3
# ifdef __STDC__
(MASLISPU_PROCP1V3 F, CHAR S[], LONGCARD O_15)
# else
(F, S, O_15)
MASLISPU_PROCP1V3 F;
CHAR S[];
LONGCARD O_15;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 1, 3);
  Compiled(P, TP, S, O_15);
}

void MASLISPU_Compiledp2v2
# ifdef __STDC__
(MASLISPU_PROCP2V2 F, CHAR S[], LONGCARD O_16)
# else
(F, S, O_16)
MASLISPU_PROCP2V2 F;
CHAR S[];
LONGCARD O_16;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 2, 2);
  Compiled(P, TP, S, O_16);
}

void MASLISPU_Compiledp2v3
# ifdef __STDC__
(MASLISPU_PROCP2V3 F, CHAR S[], LONGCARD O_17)
# else
(F, S, O_17)
MASLISPU_PROCP2V3 F;
CHAR S[];
LONGCARD O_17;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 2, 3);
  Compiled(P, TP, S, O_17);
}

void MASLISPU_Compiledp3v2
# ifdef __STDC__
(MASLISPU_PROCP3V2 F, CHAR S[], LONGCARD O_18)
# else
(F, S, O_18)
MASLISPU_PROCP3V2 F;
CHAR S[];
LONGCARD O_18;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 3, 2);
  Compiled(P, TP, S, O_18);
}

void MASLISPU_Compiledp3v3
# ifdef __STDC__
(MASLISPU_PROCP3V3 F, CHAR S[], LONGCARD O_19)
# else
(F, S, O_19)
MASLISPU_PROCP3V3 F;
CHAR S[];
LONGCARD O_19;
# endif
{
  MASSTOR_LIST TP;
  ADDRESS P;

  P = (ADDRESS)F;
  TP = SACLIST_LIST3(PIND, 3, 3);
  Compiled(P, TP, S, O_19);
}

void MASLISPU_CompSummary
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST X, V, W, k, i, o;
  INTEGER p, f;

  p = 0;
  f = 0;
  MASBIOS_SWRITE("List of all compiled functions and procedures: ", 47L);
  MASBIOS_BLINES(1);
  X = MASSYM2_STLST(MASSYM2_SYMTB);
  while (X != MASSTOR_SIL) {
    MASSTOR_ADV(X, &V, &X);
    W = MASSYM2_GET(V, MASLISPU_ARITY);
    if (W != MASSTOR_SIL) {
      SACLIST_FIRST3(W, &k, &i, &o);
      if (k == PIND) {
        p = p + 1;
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
        f = f + 1;
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
  MASBIOS_GWRITE((MASELEM_GAMMAINT)f);
  MASBIOS_SWRITE(" functions and ", 15L);
  MASBIOS_GWRITE((MASELEM_GAMMAINT)p);
  MASBIOS_SWRITE(" procedures accessible.", 23L);
  MASBIOS_BLINES(0);
}

void MASLISPU_Declare
# ifdef __STDC__
(MASSTOR_LIST *X, CHAR S[], LONGCARD O_20)
# else
(X, S, O_20)
MASSTOR_LIST *X;
CHAR S[];
LONGCARD O_20;
# endif
{
  *X = MASSYM2_ENTER(MASBIOS_LISTS(S, O_20));
}

BOOLEAN MASLISPU_PROCP
# ifdef __STDC__
(MASSTOR_LIST X)
# else
(X)
MASSTOR_LIST X;
# endif
{
  if (!MASSYM2_SYMBOL(X)) {
    return FALSE;
  }
  if (MASSYM2_GET(X, MASLISPU_ARITY) != MASSTOR_SIL) {
    return TRUE;
  }
  return FALSE;
}

void MASLISPU_Signature
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST *PI, MASSTOR_LIST *PO, BOOLEAN *def)
# else
(F, PI, PO, def)
MASSTOR_LIST F;
MASSTOR_LIST *PI, *PO;
BOOLEAN *def;
# endif
{
  MASSTOR_LIST L, C, PT;

  *PI = 0;
  *PO = 0;
  *def = FALSE;
  C = MASSYM2_GET(F, MASLISPU_ARITY);
  L = MASSYM2_GET(F, MASLISPU_SUBR);
  if (L == MASSTOR_SIL || C <= MASSTOR_SIL) {
    return;
  }
  *def = TRUE;
  SACLIST_FIRST3(C, &PT, PI, PO);
  if (PT == FIND) {
    *PO = -1;
  }
}

void BEGIN_MASLISPU()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_MASSYM2();
    BEGIN_MASSYM();

    MASLISPU_Declare(&MASLISPU_EXTYP, "EXTYP", 5L);
    MASLISPU_Declare(&MASLISPU_ARITY, "ARITY", 5L);
    MASLISPU_Declare(&MASLISPU_SUBR, "SUBR", 4L);
  }
}
