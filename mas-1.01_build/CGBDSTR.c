#include "SYSTEM_.h"

#ifndef DEFINITION_CGBMAIN
#include "CGBMAIN.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASBIOSU
#include "MASBIOSU.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASSYM
#include "MASSYM.h"
#endif

#ifndef DEFINITION_MLOGBASE
#include "MLOGBASE.h"
#endif

#ifndef DEFINITION_PQBASE
#include "PQBASE.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

CHAR CGBDSTR_rcsid [] = "$Id: CGBDSTR.md,v 1.9 1996/06/08 16:47:06 pesch Exp $";
CHAR CGBDSTR_copyright [] = "Copyright (c) 1992-1996 Universitaet Passau";

static CHAR rcsidi [] = "$Id: CGBDSTR.mip,v 1.11 1996/06/08 16:47:07 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1992-1996 Universitaet Passau";


MASSTOR_LIST CGBDSTR_CondZero
# ifdef __STDC__
(MASSTOR_LIST Cond)
# else
(Cond)
MASSTOR_LIST Cond;
# endif
{
  return MASSTOR_FIRST(Cond);
}

MASSTOR_LIST CGBDSTR_CondNzero
# ifdef __STDC__
(MASSTOR_LIST Cond)
# else
(Cond)
MASSTOR_LIST Cond;
# endif
{
  return SACLIST_SECOND(Cond);
}

void CGBDSTR_CondParts
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST *C0, MASSTOR_LIST *C1)
# else
(Cond, C0, C1)
MASSTOR_LIST Cond;
MASSTOR_LIST *C0, *C1;
# endif
{
  SACLIST_FIRST2(Cond, C0, C1);
}

MASSTOR_LIST CGBDSTR_CondCons
# ifdef __STDC__
(MASSTOR_LIST C0, MASSTOR_LIST C1)
# else
(C0, C1)
MASSTOR_LIST C0, C1;
# endif
{
  return SACLIST_LIST2(C0, C1);
}

BOOLEAN CGBDSTR_CondIsEmpty
# ifdef __STDC__
(MASSTOR_LIST Cond)
# else
(Cond)
MASSTOR_LIST Cond;
# endif
{
  return CGBDSTR_CondZero(Cond) == MASSTOR_SIL && CGBDSTR_CondNzero(Cond) == MASSTOR_SIL;
}

MASSTOR_LIST CGBDSTR_CondEmpty
# ifdef __STDC__
()
# else
()
# endif
{
  return SACLIST_LIST2(MASSTOR_SIL, MASSTOR_SIL);
}

MASSTOR_LIST CGBDSTR_CondRead
# ifdef __STDC__
(MASSTOR_LIST VD)
# else
(VD)
MASSTOR_LIST VD;
# endif
{
  MASSTOR_LIST CD0, CD1;

  CD0 = CGBDSTR_CondPRead(VD, 0);
  CD1 = CGBDSTR_CondPRead(VD, 1);
  return CGBDSTR_CondCons(CD0, CD1);
}

MASSTOR_LIST CGBDSTR_CondPRead
# ifdef __STDC__
(MASSTOR_LIST VD, MASSTOR_LIST B)
# else
(VD, B)
MASSTOR_LIST VD, B;
# endif
{
  MASSTOR_LIST C, C1, CP, V, D, C_127_A, AL, AE;

  CGBDSTR_VdParts(VD, &V, &D);
  C = MASBIOS_CREADB();
  if (MASBIOS_DIGIT(C)) {
    MASBIOS_BKSP();
    C = SACLIST_AREAD();
  }
  if (C != MASBIOS_MASORD('(') && C != B) {
    MASERR_ERROR(MASERR_harmless, "Error1 found by CondPRead.", 26L);
    return MASSTOR_SIL;
  }
  C1 = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('(') && C1 != MASBIOS_MASORD(')')) {
    MASERR_ERROR(MASERR_harmless, "Error2 found by CondPRead.", 26L);
    return MASSTOR_SIL;
  }
  if (C == B && C1 != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_harmless, "Error3 found by CondPRead.", 26L);
    return MASSTOR_SIL;
  }
  if (C == MASBIOS_MASORD('(') && C1 == MASBIOS_MASORD(')')) {
    return MASSTOR_SIL;
  }
  CP = MASSTOR_SIL;
  if ((C == MASBIOS_MASORD('0') || C == MASBIOS_MASORD('1')) && C1 == MASBIOS_MASORD('(')) {
    do {
      C = MASBIOS_CREADB();
      if (C == MASBIOS_MASORD(',')) {
        C = MASBIOS_CREADB();
      }
      if (C != MASBIOS_MASORD(')')) {
        MASBIOS_BKSP();
        C_127_A = DIPADOM_DIREAD(V, D);
        DIPC_DIPMAD(C_127_A, &AL, &AE, &C_127_A);
        CP = SACLIST_CONC(CP, MASSTOR_LIST1(AL));
      }
    } while (!(C == MASBIOS_MASORD(')')));
  }
  return CP;
}

void CGBDSTR_CondWrite
# ifdef __STDC__
(MASSTOR_LIST Cond)
# else
(Cond)
MASSTOR_LIST Cond;
# endif
{
  MASSTOR_LIST C_126_A, Cond0, Cond1;

  MASBIOS_SWRITE("Condition: ", 11L);
  if (CGBDSTR_CondIsEmpty(Cond)) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  MASBIOS_BLINES(0);
  CGBDSTR_CondParts(Cond, &Cond0, &Cond1);
  while (Cond0 != MASSTOR_SIL) {
    MASSTOR_ADV(Cond0, &C_126_A, &Cond0);
    CGBMISC_PFWRITE(C_126_A);
    MASBIOS_SWRITE("= 0", 3L);
    MASBIOS_BLINES(0);
  }
  while (Cond1 != MASSTOR_SIL) {
    MASSTOR_ADV(Cond1, &C_126_A, &Cond1);
    CGBMISC_PFWRITE(C_126_A);
    MASBIOS_SWRITE("<> 0", 4L);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(1);
  CGBMISC_EvordReset();
}

MASSTOR_LIST CGBDSTR_FormFCond
# ifdef __STDC__
(MASSTOR_LIST Cond, MASSTOR_LIST *VD)
# else
(Cond, VD)
MASSTOR_LIST Cond;
MASSTOR_LIST *VD;
# endif
{
  MASSTOR_LIST C0, C1, P, F, D, DOM, VARL;

  MASBIOSU_CLTIS(MASBIOS_LISTS("RN -1 ", 6L));
  D = MASADOM_ADDDREAD();
  *VD = CGBDSTR_VdCons(MASSTOR_SIL, D);
  if (CGBDSTR_CondIsEmpty(Cond)) {
    return MLOGBASE_VERUM;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  CGBDSTR_CondParts(Cond, &C0, &C1);
  F = MASSTOR_SIL;
  VARL = MASSTOR_SIL;
  while (C0 != MASSTOR_SIL) {
    MASSTOR_ADV(C0, &P, &C0);
    F = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, CGBMISC_DIFPF(P, D, &DOM, &VARL)), F);
  }
  while (C1 != MASSTOR_SIL) {
    MASSTOR_ADV(C1, &P, &C1);
    F = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_NEQ, CGBMISC_DIFPF(P, D, &DOM, &VARL)), F);
  }
  CGBMISC_EvordReset();
  *VD = CGBDSTR_VdCons(VARL, D);
  return MLOGBASE_FORMKFOR(MLOGBASE_ET, F);
}

MASSTOR_LIST CGBDSTR_ColRed
# ifdef __STDC__
(MASSTOR_LIST Col)
# else
(Col)
MASSTOR_LIST Col;
# endif
{
  return MASSTOR_FIRST(Col);
}

MASSTOR_LIST CGBDSTR_ColWhite
# ifdef __STDC__
(MASSTOR_LIST Col)
# else
(Col)
MASSTOR_LIST Col;
# endif
{
  return SACLIST_SECOND(Col);
}

void CGBDSTR_ColParts
# ifdef __STDC__
(MASSTOR_LIST Col, MASSTOR_LIST *R, MASSTOR_LIST *W)
# else
(Col, R, W)
MASSTOR_LIST Col;
MASSTOR_LIST *R, *W;
# endif
{
  SACLIST_FIRST2(Col, R, W);
}

MASSTOR_LIST CGBDSTR_ColCons
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST W)
# else
(R, W)
MASSTOR_LIST R, W;
# endif
{
  return SACLIST_LIST2(R, W);
}

MASSTOR_LIST CGBDSTR_ColConsCond
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST COND)
# else
(POL, COND)
MASSTOR_LIST POL, COND;
# endif
{
  MASSTOR_LIST F, PC, PCF, PE, R, W, WF;
  CGBMISC_COLOUR C;

  if (POL == MASSTOR_SIL) {
    return CGBDSTR_ColEmpty();
  }
  R = MASSTOR_SIL;
  W = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(POL, &PC, &PE, &POL);
    if ((*CGBMISC_PAR.IsCnst)(PC)) {
      R = MASSTOR_COMP(PE, R);
    } else {
      PCF = (*CGBMISC_PAR.Factorize)(PC);
      C = CGBMISC_nzero;
      WF = MASSTOR_SIL;
      do {
        MASSTOR_ADV(PCF, &F, &PCF);
        if (!(*CGBMISC_PAR.IsCnst)(F)) {
          C = (*CGBMISC_PAR.CondEval)(COND, F);
          if (C == CGBMISC_unknown) {
            WF = MASSTOR_COMP(F, WF);
          }
        }
      } while (!(C == CGBMISC_zero || PCF == MASSTOR_SIL));
      if (C != CGBMISC_zero) {
        if (WF == MASSTOR_SIL) {
          R = MASSTOR_COMP(PE, R);
        } else {
          W = MASSTOR_COMP(SACLIST_LIST2(PE, WF), W);
        }
      }
    }
  } while (!(POL == MASSTOR_SIL));
  if (R != MASSTOR_SIL) {
    R = MASSTOR_INV(R);
  }
  if (W != MASSTOR_SIL) {
    W = MASSTOR_INV(W);
  }
  return CGBDSTR_ColCons(R, W);
}

BOOLEAN CGBDSTR_ColIsEmpty
# ifdef __STDC__
(MASSTOR_LIST Col)
# else
(Col)
MASSTOR_LIST Col;
# endif
{
  return CGBDSTR_ColRed(Col) == MASSTOR_SIL && CGBDSTR_ColWhite(Col) == MASSTOR_SIL;
}

MASSTOR_LIST CGBDSTR_ColEmpty
# ifdef __STDC__
()
# else
()
# endif
{
  return SACLIST_LIST2(MASSTOR_SIL, MASSTOR_SIL);
}

MASSTOR_LIST CGBDSTR_ColHT
# ifdef __STDC__
(MASSTOR_LIST COL)
# else
(COL)
MASSTOR_LIST COL;
# endif
{
  MASSTOR_LIST R, W;

  if (CGBDSTR_ColIsEmpty(COL)) {
    return MASSTOR_SIL;
  }
  CGBDSTR_ColParts(COL, &R, &W);
  if (R == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  if (W == MASSTOR_SIL) {
    return MASSTOR_FIRST(R);
  }
  if (DIPC_EVCOMP(MASSTOR_FIRST(R), MASSTOR_FIRST(MASSTOR_FIRST(W))) <= 0) {
    return MASSTOR_SIL;
  }
  return MASSTOR_FIRST(R);
}

MASSTOR_LIST CGBDSTR_ColpCons
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST COL)
# else
(POL, COL)
MASSTOR_LIST POL, COL;
# endif
{
  return SACLIST_LIST2(POL, COL);
}

MASSTOR_LIST CGBDSTR_ColpConsCond
# ifdef __STDC__
(MASSTOR_LIST POL, MASSTOR_LIST COND)
# else
(POL, COND)
MASSTOR_LIST POL, COND;
# endif
{
  return CGBDSTR_ColpCons(POL, CGBDSTR_ColConsCond(POL, COND));
}

MASSTOR_LIST CGBDSTR_ColpPol
# ifdef __STDC__
(MASSTOR_LIST COLP)
# else
(COLP)
MASSTOR_LIST COLP;
# endif
{
  return MASSTOR_FIRST(COLP);
}

MASSTOR_LIST CGBDSTR_ColpCol
# ifdef __STDC__
(MASSTOR_LIST COLP)
# else
(COLP)
MASSTOR_LIST COLP;
# endif
{
  return SACLIST_SECOND(COLP);
}

void CGBDSTR_ColpParts
# ifdef __STDC__
(MASSTOR_LIST COLP, MASSTOR_LIST *POL, MASSTOR_LIST *COL)
# else
(COLP, POL, COL)
MASSTOR_LIST COLP;
MASSTOR_LIST *POL, *COL;
# endif
{
  SACLIST_FIRST2(COLP, POL, COL);
}

BOOLEAN CGBDSTR_ColpIsCnst
# ifdef __STDC__
(MASSTOR_LIST COLP)
# else
(COLP)
MASSTOR_LIST COLP;
# endif
{
  MASSTOR_LIST COL, R, W;

  COL = CGBDSTR_ColpCol(COLP);
  if (CGBDSTR_ColIsEmpty(COL)) {
    return FALSE;
  }
  CGBDSTR_ColParts(COL, &R, &W);
  if (R == MASSTOR_SIL || W != MASSTOR_SIL) {
    return FALSE;
  }
  if (DIPC_EVSIGN(MASSTOR_FIRST(R)) == 0) {
    return TRUE;
  }
  return FALSE;
}

MASSTOR_LIST CGBDSTR_ColpHT
# ifdef __STDC__
(MASSTOR_LIST COLP)
# else
(COLP)
MASSTOR_LIST COLP;
# endif
{
  MASSTOR_LIST COL, R, W;

  return CGBDSTR_ColHT(CGBDSTR_ColpCol(COLP));
}

BOOLEAN CGBDSTR_ColpIsZero
# ifdef __STDC__
(MASSTOR_LIST COLP)
# else
(COLP)
MASSTOR_LIST COLP;
# endif
{
  if (COLP == MASSTOR_SIL) {
    return TRUE;
  }
  return CGBDSTR_ColIsEmpty(CGBDSTR_ColpCol(COLP));
}

MASSTOR_LIST CGBDSTR_CdRead
# ifdef __STDC__
(MASSTOR_LIST VD)
# else
(VD)
MASSTOR_LIST VD;
# endif
{
  MASSTOR_LIST CD;

  CD = MASSTOR_SIL;
  do {
    CD = SACLIST_CONC(CD, MASSTOR_LIST1(CGBDSTR_CondRead(VD)));
  } while (!(MASBIOS_CREADB() == MASBIOS_MASORD('.')));
  return CD;
}

void CGBDSTR_CdWrite
# ifdef __STDC__
(MASSTOR_LIST CD)
# else
(CD)
MASSTOR_LIST CD;
# endif
{
  MASSTOR_LIST COND;

  if (CD == MASSTOR_SIL || CD == 0) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_BLINES(0);
  do {
    MASSTOR_ADV(CD, &COND, &CD);
    CGBDSTR_CondWrite(COND);
    MASBIOS_BLINES(0);
  } while (!(CD == MASSTOR_SIL));
}

MASSTOR_LIST CGBDSTR_CdpCons
# ifdef __STDC__
(MASSTOR_LIST CD, MASSTOR_LIST PL, MASSTOR_LIST VD)
# else
(CD, PL, VD)
MASSTOR_LIST CD, PL, VD;
# endif
{
  return SACLIST_LIST3(CD, PL, VD);
}

void CGBDSTR_CdpParts
# ifdef __STDC__
(MASSTOR_LIST CDP, MASSTOR_LIST *CD, MASSTOR_LIST *PL, MASSTOR_LIST *VD)
# else
(CDP, CD, PL, VD)
MASSTOR_LIST CDP;
MASSTOR_LIST *CD, *PL, *VD;
# endif
{
  SACLIST_FIRST3(CDP, CD, PL, VD);
}

MASSTOR_LIST CGBDSTR_CdpCd
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  return MASSTOR_FIRST(CDP);
}

MASSTOR_LIST CGBDSTR_CdpPs
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  return SACLIST_SECOND(CDP);
}

MASSTOR_LIST CGBDSTR_CdpVd
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  return SACLIST_THIRD(CDP);
}

MASSTOR_LIST CGBDSTR_CdpRead
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, CD, NRLIST, VD, SYS, S, RET;

  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  VD = CGBDSTR_VdRead();
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(VD));
  CD = CGBDSTR_CdRead(VD);
  SYS = CGBDSTR_RDSYS(VD);
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  RET = CGBDSTR_CdpCons(CD, SACLIST_LIST2(MASSTOR_INV(DIPC_DIPLPM(MASSTOR_FIRST(SYS))), SACLIST_SECOND(SYS)), VD);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return RET;
}

void CGBDSTR_CdpWrite
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  MASSTOR_LIST C, CONDS, NRLIST, VD, SYS;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(MASSTOR_FIRST(SACLIST_THIRD(CDP)));
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Case distinction: ", 18L);
  CGBDSTR_CdWrite(MASSTOR_FIRST(CDP));
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Polynomial set:", 15L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Ring: ", 6L);
  MASADOM_ADDDWRIT(SACLIST_SECOND(SACLIST_THIRD(CDP)));
  SACPOL_VLWRIT(MASSTOR_FIRST(SACLIST_THIRD(CDP)));
  MASBIOS_BLINES(0);
  DIPC_DILBSO(MASSTOR_FIRST(SACLIST_SECOND(CDP)));
  DIPADOM_DILWR(MASSTOR_FIRST(SACLIST_SECOND(CDP)), MASSTOR_FIRST(SACLIST_THIRD(CDP)));
  MASBIOS_BLINES(1);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
}

MASSTOR_LIST CGBDSTR_RDSYS
# ifdef __STDC__
(MASSTOR_LIST VD)
# else
(VD)
MASSTOR_LIST VD;
# endif
{
  MASSTOR_LIST C_125_A, C, D, NF, V;

  CGBDSTR_VdParts(VD, &V, &D);
  C_125_A = DIPADOM_DILRD(V, D);
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C != MASBIOS_MASORD('(')) {
    return SACLIST_LIST2(C_125_A, MASSTOR_SIL);
  }
  NF = DIPADOM_DILRD(V, D);
  return SACLIST_LIST2(C_125_A, NF);
}

MASSTOR_LIST CGBDSTR_GsCons
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST VD, MASSTOR_LIST CD)
# else
(S, VD, CD)
MASSTOR_LIST S, VD, CD;
# endif
{
  return SACLIST_LIST3(S, VD, CD);
}

MASSTOR_LIST CGBDSTR_GsS
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  return MASSTOR_FIRST(GS);
}

MASSTOR_LIST CGBDSTR_GsVd
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  return SACLIST_SECOND(GS);
}

MASSTOR_LIST CGBDSTR_GsCd
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  return SACLIST_THIRD(GS);
}

void CGBDSTR_GsParts
# ifdef __STDC__
(MASSTOR_LIST GS, MASSTOR_LIST *S, MASSTOR_LIST *VD, MASSTOR_LIST *CD)
# else
(GS, S, VD, CD)
MASSTOR_LIST GS;
MASSTOR_LIST *S, *VD, *CD;
# endif
{
  SACLIST_FIRST3(GS, S, VD, CD);
}

void CGBDSTR_GsWrite
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_GsVd(GS)));
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Groebner system:", 16L);
  MASBIOS_BLINES(0);
  CGBMAIN_WRGBS(CGBDSTR_GsS(GS));
  MASBIOS_BLINES(0);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
}

MASSTOR_LIST CGBDSTR_CgbCons
# ifdef __STDC__
(MASSTOR_LIST CGB, MASSTOR_LIST I, MASSTOR_LIST VD, MASSTOR_LIST CD)
# else
(CGB, I, VD, CD)
MASSTOR_LIST CGB, I, VD, CD;
# endif
{
  return SACLIST_LIST4(CGB, I, VD, CD);
}

MASSTOR_LIST CGBDSTR_CgbP
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  return MASSTOR_FIRST(CGB);
}

MASSTOR_LIST CGBDSTR_CgbI
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  return SACLIST_SECOND(CGB);
}

MASSTOR_LIST CGBDSTR_CgbVd
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  return SACLIST_THIRD(CGB);
}

MASSTOR_LIST CGBDSTR_CgbCd
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  return SACLIST_FOURTH(CGB);
}

void CGBDSTR_CgbParts
# ifdef __STDC__
(MASSTOR_LIST CGB, MASSTOR_LIST *P, MASSTOR_LIST *I, MASSTOR_LIST *VD, MASSTOR_LIST *CD)
# else
(CGB, P, I, VD, CD)
MASSTOR_LIST CGB;
MASSTOR_LIST *P, *I, *VD, *CD;
# endif
{
  SACLIST_FIRST4(CGB, P, I, VD, CD);
}

void CGBDSTR_CgbWrite
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  MASBIOS_BLINES(1);
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_CgbVd(CGB)));
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Comprehensive-Groebner-Basis: ", 30L);
  MASBIOS_BLINES(0);
  if (MASSTOR_FIRST(CGB) == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
  } else {
    DIPADOM_DILWR(CGBDSTR_CgbP(CGB), CGBDSTR_VdV(CGBDSTR_CgbVd(CGB)));
  }
  SACLIST_OWRITE(CGBDSTR_CgbI(CGB));
  if (CGBDSTR_CgbI(CGB) == 1) {
    MASBIOS_SWRITE(" Condition.", 11L);
  } else {
    MASBIOS_SWRITE(" Conditions.", 12L);
  }
  MASBIOS_BLINES(1);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  MASBIOS_BLINES(1);
}

MASSTOR_LIST CGBDSTR_FdCons
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST D, MASSTOR_LIST V)
# else
(F, D, V)
MASSTOR_LIST F, D, V;
# endif
{
  return SACLIST_LIST3(D, F, V);
}

void CGBDSTR_FdParts
# ifdef __STDC__
(MASSTOR_LIST FD, MASSTOR_LIST *F, MASSTOR_LIST *D, MASSTOR_LIST *V)
# else
(FD, F, D, V)
MASSTOR_LIST FD;
MASSTOR_LIST *F, *D, *V;
# endif
{
  SACLIST_FIRST3(FD, D, F, V);
}

MASSTOR_LIST CGBDSTR_FdF
# ifdef __STDC__
(MASSTOR_LIST FD)
# else
(FD)
MASSTOR_LIST FD;
# endif
{
  return SACLIST_SECOND(FD);
}

MASSTOR_LIST CGBDSTR_FdD
# ifdef __STDC__
(MASSTOR_LIST FD)
# else
(FD)
MASSTOR_LIST FD;
# endif
{
  return MASSTOR_FIRST(FD);
}

MASSTOR_LIST CGBDSTR_FdV
# ifdef __STDC__
(MASSTOR_LIST FD)
# else
(FD)
MASSTOR_LIST FD;
# endif
{
  return SACLIST_THIRD(FD);
}

void CGBDSTR_FdWrite
# ifdef __STDC__
(MASSTOR_LIST FD)
# else
(FD)
MASSTOR_LIST FD;
# endif
{
  MASSTOR_LIST D;

  PQBASE_PQPPRT(CGBDSTR_FdF(FD));
  MASBIOS_SWRITE(": ", 2L);
  SACLIST_OWRITE(CGBDSTR_FdD(FD));
  if (CGBDSTR_FdD(FD) != -1) {
    MASBIOS_SWRITE(": ", 2L);
    SACPOL_VLWRIT(CGBDSTR_FdV(FD));
  }
  MASBIOS_BLINES(0);
}

MASSTOR_LIST CGBDSTR_PdCons
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST VD)
# else
(F, VD)
MASSTOR_LIST F, VD;
# endif
{
  return SACLIST_LIST2(F, VD);
}

void CGBDSTR_PdParts
# ifdef __STDC__
(MASSTOR_LIST PD, MASSTOR_LIST *F, MASSTOR_LIST *VD)
# else
(PD, F, VD)
MASSTOR_LIST PD;
MASSTOR_LIST *F, *VD;
# endif
{
  SACLIST_FIRST2(PD, F, VD);
}

MASSTOR_LIST CGBDSTR_PdF
# ifdef __STDC__
(MASSTOR_LIST PD)
# else
(PD)
MASSTOR_LIST PD;
# endif
{
  return MASSTOR_FIRST(PD);
}

MASSTOR_LIST CGBDSTR_PdVd
# ifdef __STDC__
(MASSTOR_LIST PD)
# else
(PD)
MASSTOR_LIST PD;
# endif
{
  return SACLIST_SECOND(PD);
}

void CGBDSTR_PdWrite
# ifdef __STDC__
(MASSTOR_LIST PD)
# else
(PD)
MASSTOR_LIST PD;
# endif
{
  MASSTOR_LIST FD, F, D, L;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderCoef);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_PdVd(PD)));
  L = PQBASE_PQPRING(MASSTOR_LIST1(CGBDSTR_VdD(CGBDSTR_PdVd(PD))));
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Parametric dimension and maximal independent sets:", 50L);
  MASBIOS_BLINES(0);
  F = CGBDSTR_PdF(PD);
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &FD, &F);
    CGBDSTR_FdWrite(FD);
  }
  L = PQBASE_PQPRING(L);
  CGBMISC_ValisReset();
  CGBMISC_EvordReset();
}

MASSTOR_LIST CGBDSTR_VdCons
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST D)
# else
(V, D)
MASSTOR_LIST V, D;
# endif
{
  return SACLIST_LIST2(V, D);
}

MASSTOR_LIST CGBDSTR_VdV
# ifdef __STDC__
(MASSTOR_LIST Vd)
# else
(Vd)
MASSTOR_LIST Vd;
# endif
{
  return MASSTOR_FIRST(Vd);
}

MASSTOR_LIST CGBDSTR_VdD
# ifdef __STDC__
(MASSTOR_LIST Vd)
# else
(Vd)
MASSTOR_LIST Vd;
# endif
{
  return SACLIST_SECOND(Vd);
}

void CGBDSTR_VdParts
# ifdef __STDC__
(MASSTOR_LIST Vd, MASSTOR_LIST *V, MASSTOR_LIST *D)
# else
(Vd, V, D)
MASSTOR_LIST Vd;
MASSTOR_LIST *V, *D;
# endif
{
  SACLIST_FIRST2(Vd, V, D);
}

MASSTOR_LIST CGBDSTR_VdRead
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST D, V;

  D = MASADOM_ADDDREAD();
  V = SACPOL_VLREAD();
  return CGBDSTR_VdCons(V, D);
}

void BEGIN_CGBDSTR()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_CGBMAIN();
    BEGIN_CGBMISC();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_MASERR();
    BEGIN_MASSTOR();
    BEGIN_MASSYM();
    BEGIN_MLOGBASE();
    BEGIN_PQBASE();
    BEGIN_SACLIST();
    BEGIN_SACPOL();

  }
}
