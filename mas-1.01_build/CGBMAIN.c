#include "SYSTEM_.h"

#ifndef DEFINITION_CGBAPPL
#include "CGBAPPL.h"
#endif

#ifndef DEFINITION_CGBDSTR
#include "CGBDSTR.h"
#endif

#ifndef DEFINITION_CGBFUNC
#include "CGBFUNC.h"
#endif

#ifndef DEFINITION_CGBMISC
#include "CGBMISC.h"
#endif

#ifndef DEFINITION_CGBSYS
#include "CGBSYS.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
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

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
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

#ifndef DEFINITION_CGBMAIN
#include "CGBMAIN.h"
#endif

CHAR CGBMAIN_rcsid [] = "$Id: CGBMAIN.md,v 1.8 1996/04/24 12:09:59 pesch Exp $";
CHAR CGBMAIN_copyright [] = "Copyright (c) 1989 - 1996 Universitaet Passau";

#define CGBS	1
#define RCGB	2
#define CGBD	3
#define CGBQ	4
#define TEST	5
#define NF	6
#define GREEN	7
#define RGREEN	8
static CHAR rcsidi [] = "$Id: CGBMAIN.mip,v 1.14 1996/06/08 16:47:11 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1996 Universitaet Passau";


MASSTOR_LIST CGBMAIN_CDINIT
# ifdef __STDC__
(MASSTOR_LIST CD)
# else
(CD)
MASSTOR_LIST CD;
# endif
{
  MASSTOR_LIST RET, COND, CZ, CN, P;

  RET = MASSTOR_SIL;
  while (CD != MASSTOR_SIL) {
    MASSTOR_ADV(CD, &COND, &CD);
    CGBDSTR_CondParts(COND, &CZ, &CN);
    while (CZ != MASSTOR_SIL) {
      MASSTOR_ADV(CZ, &P, &CZ);
      RET = CGBMAIN_UPDCAS((*CGBMISC_PAR.Factorize)(P), RET, 0);
    }
    while (CN != MASSTOR_SIL) {
      MASSTOR_ADV(CN, &P, &CN);
      RET = CGBMAIN_UPDCAS((*CGBMISC_PAR.Factorize)(P), RET, 1);
    }
  }
  return RET;
}

MASSTOR_LIST CGBMAIN_GSYS
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  MASSTOR_LIST RET, CD;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_CdpVd(CDP)));
  DIPC_DILBSO(MASSTOR_FIRST(CGBDSTR_CdpPs(CDP)));
  CD = CGBMAIN_CDINIT(CGBDSTR_CdpCd(CDP));
  RET = CGBDSTR_GsCons(CGBSYS_GBSYS(CD, MASSTOR_FIRST(CGBDSTR_CdpPs(CDP))), CGBDSTR_CdpVd(CDP), CD);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return RET;
}

MASSTOR_LIST CGBMAIN_GSYSF
# ifdef __STDC__
(MASSTOR_LIST CDP)
# else
(CDP)
MASSTOR_LIST CDP;
# endif
{
  MASSTOR_LIST RET, CD;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_CdpVd(CDP)));
  DIPC_DILBSO(MASSTOR_FIRST(CGBDSTR_CdpPs(CDP)));
  CD = CGBMAIN_CDINIT(CGBDSTR_CdpCd(CDP));
  RET = CGBDSTR_GsCons(CGBSYS_GBSYSF(CD, MASSTOR_FIRST(CGBDSTR_CdpPs(CDP))), CGBDSTR_CdpVd(CDP), CD);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return RET;
}

MASSTOR_LIST CGBMAIN_GSYSDIM
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  MASSTOR_LIST CD, DL, S, VD, PD, CP, COND, PLIST, F, FVD, MAXVL;

  if (CGBDSTR_GsS(GS) == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBDSTR_GsParts(GS, &S, &VD, &CD);
  CGBMISC_ValisSet(CGBDSTR_VdV(VD));
  PD = MASSTOR_SIL;
  while (S != MASSTOR_SIL) {
    MASSTOR_ADV(S, &CP, &S);
    SACLIST_FIRST2(CP, &COND, &PLIST);
    DL = CGBMAIN_DIMIS(CGBFUNC_GREPOL(PLIST), CGBDSTR_VdV(VD), &MAXVL);
    F = CGBDSTR_FormFCond(COND, &FVD);
    PD = MASSTOR_COMP(CGBDSTR_FdCons(F, DL, MAXVL), PD);
  }
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return CGBDSTR_PdCons(PD, FVD);
}

MASSTOR_LIST CGBMAIN_DIMIS
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST VL, MASSTOR_LIST *MAXVL)
# else
(PL, VL, MAXVL)
MASSTOR_LIST PL, VL;
MASSTOR_LIST *MAXVL;
# endif
{
  MASSTOR_LIST DL, M, S, var;

  *MAXVL = VL;
  if (PL == MASSTOR_SIL) {
    return MASSTOR_LENGTH(VL);
  }
  DIPDIM_DILDIM(PL, &DL, &S, &M);
  if (DL != -1) {
    *MAXVL = DIPDIM_IXSUBS(VL, S);
  }
  return DL;
}

MASSTOR_LIST CGBMAIN_GSYSRED
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  MASSTOR_LIST S;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_GsVd(GS)));
  S = CGBSYS_GSRED(CGBDSTR_GsS(GS));
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return CGBDSTR_GsCons(S, CGBDSTR_GsVd(GS), CGBDSTR_GsCd(GS));
}

MASSTOR_LIST CGBMAIN_CGBFGSYS
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST CGB, I;

  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_GsVd(S)));
  CGBSYS_MKCGB(CGBDSTR_GsS(S), &CGB, &I);
  CGB = DIPC_DIPLPM(CGB);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return CGBDSTR_CgbCons(CGB, I, CGBDSTR_GsVd(S), CGBDSTR_GsCd(S));
}

MASSTOR_LIST CGBMAIN_CGBGLOBRED
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  MASSTOR_LIST COND, COL, NCO, PCO, PLIST, POL, QP, PL, C, P;

  if (CGBDSTR_CgbP(CGB) == MASSTOR_SIL) {
    return CGB;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_CgbVd(CGB)));
  P = CGBDSTR_CgbP(CGB);
  COND = CGBMAIN_CCOVER(CGBDSTR_CgbCd(CGB));
  PLIST = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &POL, &P);
    PLIST = MASSTOR_COMP(CGBDSTR_ColpConsCond(POL, COND), PLIST);
  } while (!(P == MASSTOR_SIL));
  PLIST = MASSTOR_INV(PLIST);
  PCO = CGBSYS_CHDEGL(PLIST);
  if (PCO != MASSTOR_SIL) {
    CGBMISC_EvordReset();
    CGBMISC_ValisReset();
    return CGBDSTR_CgbCons(MASSTOR_LIST1(MASSTOR_FIRST(PCO)), CGBDSTR_CgbI(CGB), CGBDSTR_CgbVd(CGB), CGBDSTR_CgbCd(CGB));
  }
  PLIST = CGBSYS_GLEXTP(CGBSYS_RMGRT(COND, PLIST));
  if (PLIST == MASSTOR_SIL) {
    CGBMISC_EvordReset();
    CGBMISC_ValisReset();
    return CGBDSTR_CgbCons(MASSTOR_SIL, CGBDSTR_CgbI(CGB), CGBDSTR_CgbVd(CGB), CGBDSTR_CgbCd(CGB));
  }
  if (MASSTOR_RED(PLIST) == MASSTOR_SIL) {
    CGBMISC_EvordReset();
    CGBMISC_ValisReset();
    return CGBDSTR_CgbCons(MASSTOR_LIST1(MASSTOR_FIRST(MASSTOR_FIRST(PLIST))), CGBDSTR_CgbI(CGB), CGBDSTR_CgbVd(CGB), CGBDSTR_CgbCd(CGB));
  }
  QP = PLIST;
  C = MASSTOR_SIL;
  while (PLIST != MASSTOR_SIL) {
    MASSTOR_ADV(PLIST, &PCO, &PLIST);
    CGBSYS_RDNORM(COND, PCO, QP, &NCO);
    CGBSYS_RDNORM(COND, NCO, C, &NCO);
    if (NCO != MASSTOR_SIL && CGBFUNC_WMEMB(MASSTOR_FIRST(NCO), C) == 0) {
      C = MASSTOR_COMP(NCO, C);
    }
  }
  C = CGBFUNC_CGBLPM(C);
  PL = MASSTOR_SIL;
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &POL, &C);
    PL = MASSTOR_COMP(MASSTOR_FIRST(POL), PL);
  }
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  return CGBDSTR_CgbCons(PL, CGBDSTR_CgbI(CGB), CGBDSTR_CgbVd(CGB), CGBDSTR_CgbCd(CGB));
}

void CGBMAIN_CGBQFWRITE
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  MASSTOR_LIST COND, PLIST, P, POL;

  if (MASSTOR_FIRST(CGB) == MASSTOR_SIL) {
    return;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(SACLIST_THIRD(CGB)));
  P = MASSTOR_FIRST(CGB);
  COND = CGBMAIN_CCOVER(SACLIST_FOURTH(CGB));
  PLIST = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &POL, &P);
    PLIST = MASSTOR_COMP(CGBDSTR_ColpConsCond(POL, COND), PLIST);
  } while (!(P == MASSTOR_SIL));
  CGBAPPL_CGBQUA(PLIST);
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
}

MASSTOR_LIST CGBMAIN_CGBQFF
# ifdef __STDC__
(MASSTOR_LIST CGB)
# else
(CGB)
MASSTOR_LIST CGB;
# endif
{
  MASSTOR_LIST COND, PLIST, P, POL, PHI, PHIL, B, COEF, COEFLI, LS, PA, PCO, QQ, RS, SL, TL, TT, V, DOM, VARL, var, PP, C, F, D;

  if (CGBDSTR_CgbP(CGB) == MASSTOR_SIL) {
    return MLOGBASE_VERUM;
  }
  CGBMISC_EvordSet(CGBMISC_PAR.TermOrderPol);
  CGBMISC_ValisSet(CGBDSTR_VdV(CGBDSTR_CgbVd(CGB)));
  P = CGBDSTR_CgbP(CGB);
  COND = CGBMAIN_CCOVER(CGBDSTR_CgbCd(CGB));
  PLIST = MASSTOR_SIL;
  do {
    MASSTOR_ADV(P, &POL, &P);
    PLIST = MASSTOR_COMP(CGBDSTR_ColpConsCond(POL, COND), PLIST);
  } while (!(P == MASSTOR_SIL));
  PP = PLIST;
  PCO = CGBSYS_CHDEGL(PP);
  if (PCO != MASSTOR_SIL) {
    CGBMISC_EvordReset();
    CGBMISC_ValisReset();
    return MLOGBASE_FALSUM;
  }
  P = PP;
  PHIL = MASSTOR_SIL;
  MASBIOSU_CLTIS(MASBIOS_LISTS("RN -1 ", 6L));
  D = MASADOM_ADDDREAD();
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &PCO, &P);
    CGBAPPL_MCOEF(PCO, &COEFLI, &COEF, &B);
    if (B == 1) {
      PHI = MLOGBASE_VERUM;
    } else {
      if (COEF == MASSTOR_SIL) {
        PHI = MLOGBASE_VERUM;
      } else {
        if (COEFLI == MASSTOR_SIL) {
          if (COEF != 0) {
            PHI = PQBASE_pqmkaf(PQBASE_EQU, CGBMISC_DIFPF(COEF, D, &DOM, &VARL));
          } else {
            CGBMISC_EvordReset();
            CGBMISC_ValisReset();
            return MLOGBASE_FALSUM;
          }
        } else {
          F = MASSTOR_SIL;
          do {
            MASSTOR_ADV(COEFLI, &C, &COEFLI);
            F = MASSTOR_COMP(PQBASE_pqmkaf(PQBASE_EQU, CGBMISC_DIFPF(C, D, &DOM, &VARL)), F);
          } while (!(COEFLI == MASSTOR_SIL));
          PHI = MLOGBASE_FORMKFOR(MLOGBASE_ET, F);
          if (COEF != 0) {
            PHI = MLOGBASE_FORMKBINOP(MLOGBASE_IMP, PHI, PQBASE_pqmkaf(PQBASE_EQU, CGBMISC_DIFPF(COEF, D, &DOM, &VARL)));
          } else {
            PHI = MLOGBASE_FORMKUNOP(MLOGBASE_NON, PHI);
          }
        }
      }
    }
    if (PHI != MLOGBASE_VERUM) {
      PHIL = MASSTOR_COMP(PHI, PHIL);
    }
  }
  CGBMISC_EvordReset();
  CGBMISC_ValisReset();
  if (PHIL == MASSTOR_SIL) {
    return MLOGBASE_VERUM;
  }
  return MLOGBASE_FORMKFOR(MLOGBASE_ET, PHIL);
}

void CGBMAIN_CGBIN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST AC, C, CONDS, NFS, NRLIST, PP, PPS, VD, V, D, OPT, PARX, TP, PR;

  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  while (C != MASBIOS_MASORD('.')) {
    VD = CGBMAIN_DVREAD();
    SACLIST_FIRST3(VD, &V, &D, &OPT);
    SACLIST_FIRST3(OPT, &PARX, &TP, &PR);
    CGBMISC_PAR.outputlevel = 1;
    if (PARX == 1) {
      CGBMISC_PAR.Factorize = MASADOM_ADFACT;
      CGBMISC_PAR.factorize = TRUE;
    } else {
      CGBMISC_PAR.Factorize = CGBMISC_dummyfactorize;
      CGBMISC_PAR.factorize = FALSE;
    }
    if (TP == 0) {
      CGBMISC_PAR.NormalForm = CGBSYS_NFTOP;
      CGBMISC_PAR.normalform = 0;
    } else {
      CGBMISC_PAR.NormalForm = CGBSYS_NFORM;
      CGBMISC_PAR.normalform = 1;
    }
    CONDS = CGBMAIN_CONINI(VD);
    PPS = CGBDSTR_RDSYS(VD);
    SACLIST_FIRST2(PPS, &PP, &NFS);
    CGBMAIN_CHDOM(CONDS, PP, &CONDS, &PP);
    CGBMAIN_CHDOM(CONDS, NFS, &CONDS, &NFS);
    PPS = SACLIST_LIST2(PP, NFS);
    NRLIST = CGBMAIN_EXECRD();
    AC = SACLIST_LIST4(CONDS, PPS, VD, NRLIST);
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    CGBMAIN_CGBOUT(AC);
  }
  return;
}

void CGBMAIN_CGBOUT
# ifdef __STDC__
(MASSTOR_LIST AC)
# else
(AC)
MASSTOR_LIST AC;
# endif
{
  MASSTOR_LIST C, CGB, CGB0, CGB1, CGBL, COND, D, DIML, GS, HCGB, I, NFS, NOUT, NRLIST, OPT, PARX, PP, PPS, PR, RCGBS, SL, TL, TP, V, VD, XT;

  SACLIST_FIRST4(AC, &C, &PPS, &VD, &NRLIST);
  SACLIST_FIRST2(PPS, &PP, &NFS);
  SACLIST_FIRST3(VD, &V, &D, &OPT);
  SACLIST_FIRST3(OPT, &PARX, &TP, &PR);
  MASBIOS_SWRITE("Comprehensive-Groebner-Basis System ", 36L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Domain: ", 8L);
  MASADOM_ADDDWRIT(D);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Ring: D", 7L);
  SACPOL_VLWRIT(V);
  MASBIOS_BLINES(1);
  DIPC_EVOWRITE(DIPC_EVORD);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Factorization: ", 15L);
  SACLIST_OWRITE(PARX);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Reduction Algorithm: ", 21L);
  if (TP == 0) {
    MASBIOS_SWRITE("NFTOP", 5L);
  } else {
    MASBIOS_SWRITE("NFORM", 5L);
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Starting with Case Distinction: ", 32L);
  CGBDSTR_CdWrite(C);
  if (PP == MASSTOR_SIL) {
    return;
  }
  MASBIOS_SWRITE("Polynomial System: ", 19L);
  PP = MASSTOR_INV(DIPC_DIPLPM(PP));
  DIPADOM_DILWR(PP, DIPC_VALIS);
  MASBIOS_BLINES(0);
  COND = CGBMAIN_CCOVER(C);
  SL = 0;
  TL = 0;
  XT = MASSTOR_TIME();
  if (SACLIST_MEMBER(CGBS, NRLIST) == 1) {
    GS = CGBSYS_GBSYS(C, PP);
    if (SACLIST_MEMBER(GREEN, NRLIST) == 1) {
      CGBMAIN_WRTITL(GREEN);
      CGBMAIN_GGREEN(GS);
    } else {
      CGBMAIN_WRTITL(CGBS);
      CGBMAIN_WRGBS(GS);
    }
    CGBSYS_MKCGB(GS, &CGB, &I);
    CGBL = CGBSYS_GLOBRE(COND, CGB);
    CGBMAIN_WRCGB(CGBL, I);
    SL = 1;
    TL = 1;
  }
  if (SACLIST_MEMBER(RCGB, NRLIST) == 1) {
    if (TL == 0) {
      GS = CGBSYS_GBSYS(C, PP);
    }
    GS = CGBSYS_GSRED(GS);
    if (SACLIST_MEMBER(GREEN, NRLIST) == 1) {
      CGBMAIN_WRTITL(RGREEN);
      CGBMAIN_GGREEN(GS);
    } else {
      CGBMAIN_WRTITL(RCGBS);
      CGBMAIN_WRGBS(GS);
    }
    CGBSYS_MKCGB(GS, &CGB, &I);
    CGBL = CGBSYS_GLOBRE(COND, CGB);
    CGBMAIN_WRRCGB(CGBL, I);
    SL = 1;
    TL = 1;
  }
  if (SACLIST_MEMBER(CGBQ, NRLIST) == 1) {
    if (TL == 0) {
      CGBL = CGBSYS_GLOBRE(COND, PP);
    }
    CGBMAIN_WRTITL(CGBQ);
    HCGB = CGBFUNC_GREPOL(CGBL);
    CGBAPPL_CGBQUA(CGBL);
    SL = 1;
  }
  if (SACLIST_MEMBER(CGBD, NRLIST) == 1) {
    if (TL == 0) {
      CGBFUNC_DET(C, PP, &D, &GS);
    }
    CGBMAIN_WRTITL(CGBD);
    DIML = CGBAPPL_DIMEXE(GS, V);
    CGBAPPL_WRDIMS(DIML);
    SL = 1;
  }
  if (SACLIST_MEMBER(TEST, NRLIST) == 1) {
    if (TL == 0) {
      CGB = PP;
    } else {
      CGB = CGBFUNC_CGBFRM(CGBL);
    }
    CGBMAIN_WRTITL(TEST);
    CGBAPPL_GTEST(C, CGB, &CGB0, &CGB1);
    CGBAPPL_WRTEST(C, CGB, CGB0, CGB1);
    SL = 1;
  }
  if (SACLIST_MEMBER(NF, NRLIST) == 1 && NFS != MASSTOR_SIL) {
    CGBMAIN_WRTITL(NF);
    MASBIOS_SWRITE("for the following polynomials: ", 31L);
    DIPADOM_DILWR(NFS, DIPC_VALIS);
    MASBIOS_BLINES(0);
    if (TL == 0) {
      CGB = PP;
    } else {
      CGB = CGBFUNC_CGBFRM(CGBL);
    }
    CGBAPPL_NFEXEC(C, NFS, CGB, &NOUT);
    CGBMAIN_NFWRIT(NOUT);
    SL = 1;
  }
  if (SL == 0) {
    MASERR_ERROR(MASERR_fatal, "Error in reading options ", 25L);
  }
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("******************************************************", 54L);
  MASBIOS_BLINES(0);
  SACLIST_AWRITE(MASSTOR_TIME() - XT);
  MASBIOS_SWRITE("ms.", 3L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("******************************************************", 54L);
  MASBIOS_BLINES(1);
  return;
}

MASSTOR_LIST CGBMAIN_DVREAD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C, CP, D, FAC, OPT, PR, TP, V, VD, XX;

  D = MASADOM_ADDDREAD();
  V = SACPOL_VLREAD();
  C = MASBIOS_CREADB();
  CP = DIPC_INVLEX;
  if (C != MASBIOS_MASORD('/')) {
    MASBIOS_BKSP();
  } else {
    C = MASBIOS_CREAD();
    XX = 0;
    if (C == MASBIOS_MASORD('L')) {
      XX = 1;
      CP = DIPC_INVLEX;
    } else if (C == MASBIOS_MASORD('B')) {
      XX = 1;
      CP = DIPC_REVTDEG;
    } else if (C == MASBIOS_MASORD('G')) {
      XX = 1;
      CP = DIPC_IGRLEX;
    } else if (C == MASBIOS_MASORD('S')) {
      XX = 1;
      CP = DIPC_REVILEX;
    }
    if (XX == 0) {
      MASBIOS_SWRITE("Error reading ordering", 22L);
    }
    C = MASBIOS_CREADB();
    if (C != MASBIOS_MASORD('/')) {
      MASBIOS_SWRITE("Error reading ordering", 22L);
    }
  }
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  FAC = 0;
  if (C == MASBIOS_MASORD('F')) {
    C = MASBIOS_CREADB();
    FAC = 1;
  }
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  TP = 0;
  if (C == MASBIOS_MASORD('N')) {
    C = MASBIOS_CREADB();
    TP = 1;
  }
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  PR = 0;
  if (C == MASBIOS_MASORD('P')) {
    C = MASBIOS_CREADB();
    PR = 1;
  }
  OPT = SACLIST_LIST3(FAC, TP, PR);
  DIPC_VALIS = V;
  DIPC_EVORD = CP;
  CGBMISC_PAR.TermOrderPol = CP;
  VD = SACLIST_LIST3(V, D, OPT);
  return VD;
}

MASSTOR_LIST CGBMAIN_CONINI
# ifdef __STDC__
(MASSTOR_LIST VD)
# else
(VD)
MASSTOR_LIST VD;
# endif
{
  MASSTOR_LIST C, CON, CONS, D, V, X;

  SACLIST_FIRST2(VD, &V, &D);
  CONS = MASSTOR_SIL;
  do {
    CON = MASSTOR_SIL;
    CGBMAIN_CONDRD(V, D, 0, CON, &CON);
    CGBMAIN_CONDRD(V, D, 1, CON, &CON);
    CONS = SACLIST_CONC(CONS, CON);
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
  } while (!(C == MASBIOS_MASORD('.')));
  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('.')) {
    MASERR_ERROR(MASERR_harmless, "Error1 found by CONINI.", 23L);
  }
  return CONS;
}

void CGBMAIN_CONDRD
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST D, MASSTOR_LIST B, MASSTOR_LIST DALT, MASSTOR_LIST *DNEU)
# else
(V, D, B, DALT, DNEU)
MASSTOR_LIST V, D, B, DALT;
MASSTOR_LIST *DNEU;
# endif
{
  MASSTOR_LIST C_130_A, AE, AL, ALIST, AS, C, C1;

  *DNEU = DALT;
  C = MASBIOS_CREADB();
  if (MASBIOS_DIGIT(C)) {
    MASBIOS_BKSP();
    C = SACLIST_AREAD();
  }
  if (C != MASBIOS_MASORD('(') && C != B) {
    MASERR_ERROR(MASERR_harmless, "Error1 found by CONDRD.", 23L);
    return;
  }
  C1 = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('(') && C1 != MASBIOS_MASORD(')')) {
    MASERR_ERROR(MASERR_harmless, "Error2 found by CONDRD.", 23L);
    return;
  }
  if (C == B && C1 != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_harmless, "Error3 found by CONDRD.", 23L);
    return;
  }
  if (C == MASBIOS_MASORD('(') && C1 == MASBIOS_MASORD(')')) {
    return;
  }
  if ((C == MASBIOS_MASORD('0') || C == MASBIOS_MASORD('1')) && C1 == MASBIOS_MASORD('(')) {
    do {
      C = MASBIOS_CREADB();
      if (C == MASBIOS_MASORD(',')) {
        C = MASBIOS_CREADB();
      }
      if (C != MASBIOS_MASORD(')')) {
        MASBIOS_BKSP();
        C_130_A = DIPADOM_DIREAD(V, D);
        CGBMAIN_CHDOM(*DNEU, MASSTOR_LIST1(C_130_A), DNEU, &AS);
        C_130_A = MASSTOR_FIRST(AS);
        DIPC_DIPMAD(C_130_A, &AL, &AE, &C_130_A);
        ALIST = (*CGBMISC_PAR.Factorize)(AL);
        *DNEU = CGBMAIN_UPDCAS(ALIST, *DNEU, B);
      }
    } while (!(C == MASBIOS_MASORD(')')));
  }
  return;
}

MASSTOR_LIST CGBMAIN_UPDCAS
# ifdef __STDC__
(MASSTOR_LIST ALIST, MASSTOR_LIST DALT, MASSTOR_LIST B)
# else
(ALIST, DALT, B)
MASSTOR_LIST ALIST, DALT, B;
# endif
{
  MASSTOR_LIST C_129_A, CON, COND0, COND1, D, DNEU, HELP, SL, X, XCOND;

  if (ALIST == MASSTOR_SIL) {
    return DALT;
  }
  DNEU = MASSTOR_SIL;
  if (DALT == MASSTOR_SIL) {
    X = CGBFUNC_ADDCON(ALIST, CGBDSTR_CondEmpty());
    while (X != MASSTOR_SIL) {
      MASSTOR_ADV(X, &XCOND, &X);
      CGBDSTR_CondParts(XCOND, &COND0, &COND1);
      if (COND0 != MASSTOR_SIL && B == 0) {
        DNEU = MASSTOR_COMP(XCOND, DNEU);
      } else if (COND0 == MASSTOR_SIL && B == 1) {
        DNEU = MASSTOR_COMP(XCOND, DNEU);
      }
    }
    return DNEU;
  }
  D = DALT;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &CON, &D);
    X = CGBFUNC_ADDCON(ALIST, CON);
    while (X != MASSTOR_SIL) {
      MASSTOR_ADV(X, &XCOND, &X);
      SL = 0;
      HELP = ALIST;
      do {
        MASSTOR_ADV(HELP, &C_129_A, &HELP);
        if ((*CGBMISC_PAR.CondEval)(XCOND, C_129_A) == CGBMISC_zero) {
          SL = 1;
        }
      } while (!(SL == 1 || HELP == MASSTOR_SIL));
      if (SL == 1 && B == 0) {
        DNEU = MASSTOR_COMP(XCOND, DNEU);
      }
      if (SL == 0 && B == 1) {
        DNEU = MASSTOR_COMP(XCOND, DNEU);
      }
    }
  }
  if (DNEU == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "Error found by UPDCAS.", 22L);
  }
  return DNEU;
}

MASSTOR_LIST CGBMAIN_CCOVER
# ifdef __STDC__
(MASSTOR_LIST CONS)
# else
(CONS)
MASSTOR_LIST CONS;
# endif
{
  MASSTOR_LIST C, C0, C1, COND, COND0, COND1;

  if (CONS == MASSTOR_SIL) {
    return CGBDSTR_CondEmpty();
  }
  MASSTOR_ADV(CONS, &COND, &CONS);
  if (CONS == MASSTOR_SIL) {
    return COND;
  }
  SACLIST_FIRST2(COND, &COND0, &COND1);
  return SACLIST_LIST2(CGBMAIN_SCOV(COND0, CONS, 0), CGBMAIN_SCOV(COND1, CONS, 1));
}

MASSTOR_LIST CGBMAIN_SCOV
# ifdef __STDC__
(MASSTOR_LIST CONDA, MASSTOR_LIST CONS, MASSTOR_LIST B)
# else
(CONDA, CONS, B)
MASSTOR_LIST CONDA, CONS, B;
# endif
{
  MASSTOR_LIST C_128_A, CC, COND, CONDS, COND0, COND1, SL;

  if (CONS == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  CC = MASSTOR_SIL;
  while (CONDA != MASSTOR_SIL) {
    MASSTOR_ADV(CONDA, &C_128_A, &CONDA);
    CONDS = CONS;
    do {
      MASSTOR_ADV(CONDS, &COND, &CONDS);
      CGBDSTR_CondParts(COND, &COND0, &COND1);
      if (B == 0) {
        SL = SACLIST_MEMBER(C_128_A, COND0);
      } else {
        SL = SACLIST_MEMBER(C_128_A, COND1);
      }
    } while (!(SL == 0 || CONDS == MASSTOR_SIL));
    if (SL == 1) {
      CC = MASSTOR_COMP(C_128_A, CC);
    }
  }
  return CC;
}

void CGBMAIN_CHDOM
# ifdef __STDC__
(MASSTOR_LIST CONDS, MASSTOR_LIST PPS, MASSTOR_LIST *CONS, MASSTOR_LIST *PP)
# else
(CONDS, PPS, CONS, PP)
MASSTOR_LIST CONDS, PPS;
MASSTOR_LIST *CONS, *PP;
# endif
{
  MASSTOR_LIST BA, POL;

  *CONS = CONDS;
  *PP = MASSTOR_SIL;
  *PP = PPS;
  return;
  if (PPS == MASSTOR_SIL) {
    return;
  }
  while (PPS != MASSTOR_SIL) {
    MASSTOR_ADV(PPS, &POL, &PPS);
    *PP = MASSTOR_COMP(MASADOM_ADTOIP(POL, &BA), *PP);
    if (!MASADOM_ADCNST(BA)) {
      *CONS = CGBMAIN_UPDCAS(MASADOM_ADFACT(BA), *CONS, 1);
    }
  }
}

MASSTOR_LIST CGBMAIN_EXECRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_127_A, C, NP, NR, NRLIST, S;

  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('.')) {
    MASERR_ERROR(MASERR_harmless, "Error found by EXECRD.", 22L);
    return MASSTOR_SIL;
  }
  NRLIST = MASSTOR_SIL;
  C = MASBIOS_CREADB();
  NP = MASSTOR_SIL;
  if (MASBIOS_LETTER(C)) {
    MASBIOS_BKSP();
    S = MASSYM2_SREAD1();
    if (SACLIST_EQUAL(S, MASBIOS_LISTS("EXEC", 4L)) == 1) {
      do {
        C = MASBIOS_CREADB();
        if (C != MASBIOS_MASORD('.')) {
          MASBIOS_BKSP();
          C_127_A = MASSYM2_SREAD1();
          CGBMAIN_SEENR(C_127_A, &NR);
          if (NR != MASSTOR_SIL) {
            NRLIST = MASSTOR_COMP(NR, NRLIST);
          }
        }
      } while (!(C == MASBIOS_MASORD('.')));
    } else {
      MASERR_ERROR(MASERR_harmless, "Error found by EXECRD.", 22L);
      return NRLIST;
    }
  }
  if (NRLIST == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_harmless, "Error found by EXECRD.", 22L);
  }
  return NRLIST;
}

void CGBMAIN_SEENR
# ifdef __STDC__
(MASSTOR_LIST AC, MASSTOR_LIST *NR)
# else
(AC, NR)
MASSTOR_LIST AC;
MASSTOR_LIST *NR;
# endif
{
  MASSTOR_LIST NM, SL;

  if (SACLIST_EQUAL(AC, MASBIOS_LISTS("CGB", 3L)) == 1) {
    SL = 1;
  }
  NM = MASBIOS_LISTS("CGB", 3L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 1;
    return;
  }
  NM = MASBIOS_LISTS("RCGB", 4L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 2;
    return;
  }
  NM = MASBIOS_LISTS("CGBD", 4L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 3;
    return;
  }
  NM = MASBIOS_LISTS("CGBQ", 4L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 4;
    return;
  }
  NM = MASBIOS_LISTS("TEST", 4L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 5;
    return;
  }
  NM = MASBIOS_LISTS("NF", 2L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 6;
    return;
  }
  NM = MASBIOS_LISTS("GREEN", 5L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 7;
    return;
  }
  MASERR_ERROR(MASERR_harmless, "Error found by SEENR.", 21L);
  return;
}

void CGBMAIN_WRTITL
# ifdef __STDC__
(MASSTOR_LIST NR)
# else
(NR)
MASSTOR_LIST NR;
# endif
{
  if (NR <= 0 || NR >= 8) {
    return;
  }
  MASBIOS_SWRITE("***********************************************", 47L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("**                                           **", 47L);
  MASBIOS_BLINES(0);
  switch ((INTEGER)NR) {
  case 1:;
    MASBIOS_SWRITE("**              Groebner-System              **", 47L);
    break;
  case 2:;
    MASBIOS_SWRITE("**          Reduced groebner-system          **", 47L);
    break;
  case 3:;
    MASBIOS_SWRITE("**           Parametric dimension            **", 47L);
    break;
  case 4:;
    MASBIOS_SWRITE("**          Quantifier free formula          **", 47L);
    break;
  case 5:;
    MASBIOS_SWRITE("**               Groebner test               **", 47L);
    break;
  case 6:;
    MASBIOS_SWRITE("**    Testing parametric ideal membership    **", 47L);
    break;
  case 7:;
    MASBIOS_SWRITE("**    Groebner-System without green terms    **", 47L);
    break;
  case 8:;
    MASBIOS_SWRITE("**          Reduced groebner-system          **", 47L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("**            without green terms            **", 47L);
    break;
  }
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("**                                           **", 47L);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("***********************************************", 47L);
  MASBIOS_BLINES(0);
  return;
}

void CGBMAIN_WRGBS
# ifdef __STDC__
(MASSTOR_LIST PLS)
# else
(PLS)
MASSTOR_LIST PLS;
# endif
{
  MASSTOR_LIST COND, HELEM, HLIST, HPP, I, J, PELEM, PLIST;

  if (PLS == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_BLINES(0);
  I = 0;
  J = 0;
  while (PLS != MASSTOR_SIL) {
    MASSTOR_ADV(PLS, &PELEM, &PLS);
    SACLIST_FIRST2(PELEM, &COND, &PLIST);
    CGBDSTR_CondWrite(COND);
    I = 1;
    HPP = PLS;
    PLS = MASSTOR_SIL;
    while (HPP != MASSTOR_SIL) {
      MASSTOR_ADV(HPP, &HELEM, &HPP);
      HLIST = SACLIST_SECOND(HELEM);
      if (CGBFUNC_EQPLCL(PLIST, HLIST) == 1) {
        CGBDSTR_CondWrite(MASSTOR_FIRST(HELEM));
        I = I + 1;
      } else {
        PLS = MASSTOR_COMP(HELEM, PLS);
      }
    }
    PLS = MASSTOR_INV(PLS);
    J = J + I;
    SACLIST_OWRITE(I);
    if (I == 1) {
      MASBIOS_SWRITE(" Condition.", 11L);
    } else {
      MASBIOS_SWRITE(" Conditions.", 12L);
    }
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("Basis: ", 7L);
    CGBFUNC_DCLWR(PLIST, 0);
  }
  return;
}

void CGBMAIN_WRCGB
# ifdef __STDC__
(MASSTOR_LIST CGB, MASSTOR_LIST I)
# else
(CGB, I)
MASSTOR_LIST CGB, I;
# endif
{
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Comprehensive-Groebner-Basis: ", 30L);
  MASBIOS_BLINES(0);
  if (CGB == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
  } else {
    CGBFUNC_DCLWR(CGB, 0);
  }
  SACLIST_OWRITE(I);
  if (I == 1) {
    MASBIOS_SWRITE(" Condition.", 11L);
  } else {
    MASBIOS_SWRITE(" Conditions.", 12L);
  }
  MASBIOS_BLINES(1);
  return;
}

void CGBMAIN_WRRCGB
# ifdef __STDC__
(MASSTOR_LIST CGB, MASSTOR_LIST I)
# else
(CGB, I)
MASSTOR_LIST CGB, I;
# endif
{
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("Reduced Comprehensive-Groebner-Basis: ", 38L);
  MASBIOS_BLINES(0);
  if (CGB == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
  } else {
    CGBFUNC_DCLWR(CGB, 0);
  }
  SACLIST_OWRITE(I);
  if (I == 1) {
    MASBIOS_SWRITE(" Condition.", 11L);
  } else {
    MASBIOS_SWRITE(" Conditions.", 12L);
  }
  MASBIOS_BLINES(1);
  return;
}

void CGBMAIN_GGREEN
# ifdef __STDC__
(MASSTOR_LIST GS)
# else
(GS)
MASSTOR_LIST GS;
# endif
{
  MASSTOR_LIST COND, P, PLIST, XELEM;

  if (GS == MASSTOR_SIL) {
    return;
  }
  MASBIOS_BLINES(1);
  do {
    MASSTOR_ADV(GS, &XELEM, &GS);
    SACLIST_FIRST2(XELEM, &COND, &PLIST);
    MASBIOS_SWRITE("Groebner-Basis: ", 16L);
    CGBDSTR_CondWrite(COND);
    if (PLIST == MASSTOR_SIL) {
      MASBIOS_SWRITE("Empty.", 6L);
      MASBIOS_BLINES(0);
    } else {
      CGBFUNC_DCLWR(PLIST, 0);
      P = CGBFUNC_CGBCOL(COND, PLIST);
    }
  } while (!(GS == MASSTOR_SIL));
  return;
}

void CGBMAIN_NWRIT0
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST C, COND, PCO;

  MASBIOS_BLINES(1);
  if (N == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_SWRITE("Polynomial completely reduced wrt ", 34L);
  MASBIOS_SWRITE("the following conditions: ", 26L);
  MASBIOS_BLINES(0);
  do {
    SACLIST_ADV3(N, &COND, &PCO, &C, &N);
    CGBDSTR_CondWrite(COND);
    MASBIOS_SWRITE("Factor: ", 8L);
    MASADOM_ADWRIT(C);
    MASBIOS_BLINES(0);
  } while (!(N == MASSTOR_SIL));
  return;
}

void CGBMAIN_NWRIT1
# ifdef __STDC__
(MASSTOR_LIST N)
# else
(N)
MASSTOR_LIST N;
# endif
{
  MASSTOR_LIST C, COL, COND, PCO, POL;

  MASBIOS_BLINES(1);
  if (N == MASSTOR_SIL) {
    MASBIOS_SWRITE("Empty.", 6L);
    MASBIOS_BLINES(0);
    return;
  }
  MASBIOS_SWRITE("Polynomial not completely reduced wrt ", 38L);
  MASBIOS_SWRITE("the following conditions: ", 26L);
  MASBIOS_BLINES(0);
  do {
    SACLIST_ADV3(N, &COND, &PCO, &C, &N);
    CGBDSTR_CondWrite(COND);
    SACLIST_FIRST2(PCO, &POL, &COL);
    MASBIOS_SWRITE("Reduced to: ", 12L);
    MASBIOS_BLINES(0);
    DIPADOM_DILWR(MASSTOR_LIST1(POL), DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Factor: ", 8L);
    MASADOM_ADWRIT(C);
    MASBIOS_BLINES(0);
  } while (!(N == MASSTOR_SIL));
  return;
}

void CGBMAIN_WPAIRS
# ifdef __STDC__
(MASSTOR_LIST PS)
# else
(PS)
MASSTOR_LIST PS;
# endif
{
  MASSTOR_LIST EL, F, F1, FCOL, G, G1, GCOL, PAIR;

  MASBIOS_SWRITE("Pairs: ", 7L);
  MASBIOS_BLINES(0);
  if (PS == MASSTOR_SIL) {
    SACLIST_OWRITE(MASSTOR_SIL);
    MASBIOS_BLINES(0);
    return;
  }
  do {
    MASSTOR_ADV(PS, &PAIR, &PS);
    SACLIST_FIRST3(PAIR, &EL, &F1, &G1);
    SACLIST_FIRST2(F1, &F, &FCOL);
    SACLIST_FIRST2(G1, &G, &GCOL);
    MASBIOS_SWRITE("POL1: ", 6L);
    DIPADOM_DILWR(MASSTOR_LIST1(F), DIPC_VALIS);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("POL2: ", 6L);
    DIPADOM_DILWR(MASSTOR_LIST1(G), DIPC_VALIS);
    MASBIOS_BLINES(0);
  } while (!(PS == MASSTOR_SIL));
  MASBIOS_BLINES(1);
  return;
}

void CGBMAIN_WPLIST
# ifdef __STDC__
(MASSTOR_LIST PL)
# else
(PL)
MASSTOR_LIST PL;
# endif
{
  MASSTOR_LIST COND, PAIRS, PP;

  MASBIOS_SWRITE("Pairslist: ", 11L);
  MASBIOS_BLINES(0);
  if (PL == MASSTOR_SIL) {
    SACLIST_OWRITE(PL);
    MASBIOS_BLINES(0);
    return;
  }
  do {
    SACLIST_ADV3(PL, &COND, &PP, &PAIRS, &PL);
    CGBDSTR_CondWrite(COND);
    MASBIOS_SWRITE("Basis: ", 7L);
    MASBIOS_BLINES(0);
    CGBFUNC_DCLWR(PP, 0);
    MASBIOS_BLINES(0);
    CGBMAIN_WPAIRS(PAIRS);
  } while (!(PL == MASSTOR_SIL));
  return;
}

void CGBMAIN_NFWRIT
# ifdef __STDC__
(MASSTOR_LIST NOUT)
# else
(NOUT)
MASSTOR_LIST NOUT;
# endif
{
  MASSTOR_LIST NN0, NN1, POL;

  while (NOUT != MASSTOR_SIL) {
    SACLIST_ADV3(NOUT, &POL, &NN0, &NN1, &NOUT);
    MASBIOS_SWRITE("Tested polynomial: ", 19L);
    DIPADOM_DILWR(MASSTOR_LIST1(POL), DIPC_VALIS);
    if (NN0 != MASSTOR_SIL) {
      CGBMAIN_NWRIT0(NN0);
    }
    if (NN1 != MASSTOR_SIL) {
      CGBMAIN_NWRIT1(NN1);
    }
    CGBAPPL_WRQFN0(NN0);
    MASBIOS_BLINES(0);
  }
  return;
}

void BEGIN_CGBMAIN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_CGBAPPL();
    BEGIN_CGBDSTR();
    BEGIN_CGBFUNC();
    BEGIN_CGBMISC();
    BEGIN_CGBSYS();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPDIM();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASBIOSU();
    BEGIN_MASERR();
    BEGIN_MASSTOR();
    BEGIN_MASSYM2();
    BEGIN_MLOGBASE();
    BEGIN_PQBASE();
    BEGIN_SACLIST();
    BEGIN_SACPOL();

  }
}
