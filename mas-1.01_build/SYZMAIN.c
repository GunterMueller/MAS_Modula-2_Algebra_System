#include "SYSTEM_.h"

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_MASNCGB
#include "MASNCGB.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SYZFUNC
#include "SYZFUNC.h"
#endif

#ifndef DEFINITION_SYZGB
#include "SYZGB.h"
#endif

#ifndef DEFINITION_SYZHLP
#include "SYZHLP.h"
#endif

#ifndef DEFINITION_SYZMAIN
#include "SYZMAIN.h"
#endif

CHAR SYZMAIN_rcsid [] = "$Id: SYZMAIN.md,v 1.2 1992/02/12 17:33:20 pesch Exp $";
CHAR SYZMAIN_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SYZMAIN.mi,v 1.3 1992/10/15 16:29:23 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SYZMAIN_SYHC
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PM, SANZ, SRD)
MASSTOR_LIST PM, SANZ, SRD;
# endif
{
  MASSTOR_LIST SY, PL, L;

  L = MASSTOR_LENGTH(PM);
  if (L == 1) {
    PL = MASSTOR_FIRST(PM);
    SY = SYZMAIN_HEQ(PL, SANZ, SRD);
  } else {
    SY = SYZMAIN_HSEQ(PM, SANZ, SRD);
  }
  return SY;
}

MASSTOR_LIST SYZMAIN_HEQ
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PL, SANZ, SRD)
MASSTOR_LIST PL, SANZ, SRD;
# endif
{
  MASSTOR_LIST SY, SY1, SY2, GBTM, GB, GBR, POSV, SPFL, SPL, SPAK;

  GB = SYZGB_GBF(PL, SANZ, &GBTM);
  SY1 = MASSTOR_SIL;
  if (SRD == 1) {
    GBR = SYZFUNC_DGBRED(GB, GBTM, &SY1);
    if (MASSTOR_LENGTH(GBR) == 1) {
      return SY1;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SYZFUNC_SPCGB(GB, &SPFL, &SPL);
  SPAK = SYZFUNC_RCSP(GB, SPL);
  SY2 = SYZFUNC_SYGB(SPFL, SPAK);
  if (SRD == 1) {
    SY2 = SYZHLP_INSPOSV(SY2, POSV);
  }
  SY2 = SYZFUNC_MMULT(SY2, GBTM);
  SY2 = SACLIST_CCONC(SY1, SY2);
  if (SRD == 1) {
    SY2 = SYZGB_MGB(SY2, SANZ);
  }
  return SY2;
}

MASSTOR_LIST SYZMAIN_HSEQ
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PM, SANZ, SRD)
MASSTOR_LIST PM, SANZ, SRD;
# endif
{
  MASSTOR_LIST NV, L, GB, SPFL, SPAK, GBTM, SY, SY1, SY2, PL, SPL, POSV, PL1, TW1, TW2, GBR, POSV1;

  SY = MASSTOR_SIL;
  PL = SYZHLP_MTPLH(PM, &L);
  PL1 = SYZHLP_EX0PL(PL);
  POSV = SYZHLP_GENPOSV(PL, PL1);
  PL = PL1;
  SYZHLP_ALFA(L);
  GB = SYZGB_GBEF(PL, SANZ, L, &GBTM);
  if (SRD == 1) {
    GBR = SYZFUNC_DGBRED(GB, GBTM, &SY);
    SY = SYZHLP_EVR(SY, L);
    if (MASSTOR_LENGTH(GBR) == 1) {
      SYZHLP_ALFRA(L);
      return SY;
    }
    POSV1 = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SYZFUNC_SPCEGB(GB, L, &SPFL, &SPL);
  SPAK = SYZFUNC_RCSP(GB, SPL);
  SY1 = SYZFUNC_SYGBE(SPFL, SPAK);
  if (SRD == 1) {
    SY1 = SYZHLP_INSPOSV(SY1, POSV1);
  }
  SY2 = SYZFUNC_MMULT(SY1, GBTM);
  SY2 = SYZHLP_EVR(SY2, L);
  SY2 = SYZHLP_INSPOSV(SY2, POSV);
  SYZHLP_ALFRA(L);
  SY2 = SACLIST_CCONC(SY, SY2);
  if (SRD == 1) {
    SY2 = SYZGB_MGB(SY2, SANZ);
  }
  return SY2;
}

void SYZMAIN_SYTHC
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST VL)
# else
(SY, PM, VL)
MASSTOR_LIST SY, PM, VL;
# endif
{
  MASSTOR_LIST P, PL;

  SY = SYZHLP_VMADD(SY);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("VMADD:", 6L);
  MASBIOS_BLINES(0);
  SYZHLP_PLWR(SY, VL);
  MASBIOS_BLINES(1);
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    P = SYZFUNC_PLMULT(SY, PL);
    MASBIOS_SWRITE(" SYZYGIEN-TEST:  ", 17L);
    SYZHLP_PLWR(MASSTOR_LIST1(P), VL);
    MASBIOS_BLINES(0);
  }
}

MASSTOR_LIST SYZMAIN_SIC
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PM, PL, SANZ, SRD)
MASSTOR_LIST PM, PL, SANZ, SRD;
# endif
{
  MASSTOR_LIST SY, P, PL1, L;

  L = MASSTOR_LENGTH(PM);
  if (L == 1) {
    PL1 = MASSTOR_FIRST(PM);
    P = MASSTOR_FIRST(PL);
    SY = SYZMAIN_IEQ(PL1, P, SANZ, SRD);
  } else {
    SY = SYZMAIN_ISEQ(PM, PL, SANZ, SRD);
  }
  return SY;
}

MASSTOR_LIST SYZMAIN_IEQ
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PL, P, SANZ, SRD)
MASSTOR_LIST PL, P, SANZ, SRD;
# endif
{
  MASSTOR_LIST SY, TW1, H, L, TW2, GBTM, GB, GBR, POSV, SPAK;

  GB = SYZGB_GBF(PL, SANZ, &GBTM);
  TW2 = DIPRNGB_DIRPNF(GB, P);
  if (TW2 != 0) {
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("IEQ: Gleichung nicht loesbar! ", 30L);
    return MASSTOR_SIL;
  }
  if (SRD == 1) {
    GBR = SYZFUNC_DGBRED(GB, GBTM, &H);
    if (MASSTOR_LENGTH(GBR) == 1) {
      return MASSTOR_SIL;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SPAK = SYZFUNC_RCSP(GB, MASSTOR_LIST1(P));
  if (SRD == 1) {
    SPAK = SYZHLP_INSPOSV(SPAK, POSV);
  }
  SY = SYZFUNC_MMULT(SPAK, GBTM);
  SY = MASSTOR_FIRST(SY);
  return SY;
}

MASSTOR_LIST SYZMAIN_ISEQ
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD)
# else
(PM, PL, SANZ, SRD)
MASSTOR_LIST PM, PL, SANZ, SRD;
# endif
{
  MASSTOR_LIST L, GB, GBR, SPAK, GBTM, SY, H, POSV, POSV1, P, PL1, PL2, TW1, TW2, TW3, TW4;

  PL1 = SYZHLP_MTPLH(PM, &L);
  P = SYZHLP_PLHTP(PL);
  PL2 = SYZHLP_EX0PL(PL1);
  POSV1 = SYZHLP_GENPOSV(PL1, PL2);
  PL1 = PL2;
  SYZHLP_ALFA(L);
  GB = SYZGB_GBEF(PL1, SANZ, L, &GBTM);
  TW4 = DIPRNGB_DIRPNF(GB, P);
  if (TW4 != 0) {
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("ISEQ: Gleichungssystem nicht loesbar! ", 38L);
    SYZHLP_ALFRA(L);
    return MASSTOR_SIL;
  }
  if (SRD == 1) {
    GBR = SYZFUNC_DGBRED(GB, GBTM, &H);
    if (MASSTOR_LENGTH(GBR) == 1) {
      SYZHLP_ALFRA(L);
      return MASSTOR_SIL;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SPAK = SYZFUNC_RCSP(GB, MASSTOR_LIST1(P));
  if (SRD == 1) {
    SPAK = SYZHLP_INSPOSV(SPAK, POSV);
  }
  SY = SYZFUNC_MMULT(SPAK, GBTM);
  SY = SYZHLP_INSPOSV(SY, POSV1);
  SY = MASSTOR_FIRST(SYZHLP_EVR(SY, L));
  SYZHLP_ALFRA(L);
  return SY;
}

void SYZMAIN_STIC
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST VL)
# else
(SY, PM, PL, VL)
MASSTOR_LIST SY, PM, PL, VL;
# endif
{
  MASSTOR_LIST P1, P2, PL1;

  if (SY == MASSTOR_SIL) {
    return;
  }
  MASBIOS_BLINES(1);
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL1, &PM);
    MASSTOR_ADV(PL, &P1, &PL);
    P2 = SYZFUNC_PLMULT(SY, PL1);
    P2 = DIPRN_DIRPDF(P2, P1);
    MASBIOS_SWRITE(" GLEICHUNGS-TEST:  ", 19L);
    SYZHLP_PLWR(MASSTOR_LIST1(P2), VL);
    MASBIOS_BLINES(0);
  }
}

MASSTOR_LIST SYZMAIN_SYHNL
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PM, SANZ, SRD, T)
MASSTOR_LIST PM, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST SY, L, PL;

  L = MASSTOR_LENGTH(PM);
  if (L == 1) {
    PL = MASSTOR_FIRST(PM);
    SY = SYZMAIN_NLHEQ(PL, SANZ, SRD, T);
  } else {
    SY = SYZMAIN_NLHSEQ(PM, SANZ, SRD, T);
  }
  return SY;
}

MASSTOR_LIST SYZMAIN_NLHEQ
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PL, SANZ, SRD, T)
MASSTOR_LIST PL, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST NV, SY, SY1, SY2, L, TW, GBTM, GB, GBR, POSV, SPFL, SPL, SPAK;

  SY1 = MASSTOR_SIL;
  GB = SYZGB_NLGBF(PL, SANZ, &GBTM, &T);
  if (SRD == 1) {
    GBR = SYZFUNC_NLDGBRED(GB, GBTM, &SY1, &T);
    if (MASSTOR_LENGTH(GBR) == 1) {
      return SY1;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SYZFUNC_NLSPCGB(GB, &SPFL, &SPL, &T);
  SPAK = SYZFUNC_NLRCSP(GB, SPL, &T);
  SY2 = SYZFUNC_SYGB(SPFL, SPAK);
  if (SRD == 1) {
    SY2 = SYZHLP_INSPOSV(SY2, POSV);
  }
  SY2 = SYZFUNC_NLMMULT(SY2, GBTM, &T);
  SY2 = SACLIST_CCONC(SY1, SY2);
  if (SRD == 1) {
    SY2 = SYZGB_NLMGB(SY2, SANZ, &T);
  }
  return SY2;
}

MASSTOR_LIST SYZMAIN_NLHSEQ
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PM, SANZ, SRD, T)
MASSTOR_LIST PM, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST L1, L2, GB, GBR, SPFL, SPAK, GBTM, SY, SY1, SY2, PL, PL1, POSV, POSV1, SPL, TW1, TW2;

  SY1 = MASSTOR_SIL;
  PL = SYZHLP_MTPLH(PM, &L1);
  PL1 = SYZHLP_EX0PL(PL);
  POSV = SYZHLP_GENPOSV(PL, PL1);
  PL = PL1;
  SYZHLP_ALFA(L1);
  T = SYZHLP_TA(L1, T);
  GB = SYZGB_NLGBEF(PL, SANZ, L1, &GBTM, &T);
  if (SRD == 1) {
    GBR = SYZFUNC_NLDGBRED(GB, GBTM, &SY1, &T);
    SY1 = SYZHLP_EVR(SY1, L1);
    if (MASSTOR_LENGTH(GBR) == 1) {
      T = SYZHLP_TR(L1, T);
      SYZHLP_ALFRA(L1);
      return SY1;
    }
    POSV1 = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SYZFUNC_NLSPCEGB(GB, L1, &SPFL, &SPL, &T);
  SPAK = SYZFUNC_NLRCSP(GB, SPL, &T);
  SY2 = SYZFUNC_SYGBE(SPFL, SPAK);
  if (SRD == 1) {
    SY2 = SYZHLP_INSPOSV(SY2, POSV1);
  }
  SY2 = SYZFUNC_NLMMULT(SY2, GBTM, &T);
  SY2 = SYZHLP_EVR(SY2, L1);
  SY2 = SYZHLP_INSPOSV(SY2, POSV);
  SYZHLP_ALFRA(L1);
  T = SYZHLP_TR(L1, T);
  SY2 = SACLIST_CCONC(SY1, SY2);
  if (SRD == 1) {
    SY2 = SYZGB_NLMGB(SY2, SANZ, &T);
  }
  return SY2;
}

void SYZMAIN_SYTHNL
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST VL, MASSTOR_LIST T)
# else
(SY, PM, VL, T)
MASSTOR_LIST SY, PM, VL, T;
# endif
{
  MASSTOR_LIST P, PL;

  SY = SYZHLP_VMADD(SY);
  MASBIOS_BLINES(1);
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    P = SYZFUNC_NLPLMULT(SY, PL, &T);
    MASBIOS_SWRITE(" N-SYZYGIEN-TEST:  ", 19L);
    SYZHLP_PLWR(MASSTOR_LIST1(P), VL);
    MASBIOS_BLINES(0);
  }
}

MASSTOR_LIST SYZMAIN_SINL
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PM, PL, SANZ, SRD, T)
MASSTOR_LIST PM, PL, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST SY, PL1, P, L;

  L = MASSTOR_LENGTH(PM);
  if (L == 1) {
    PL1 = MASSTOR_FIRST(PM);
    P = MASSTOR_FIRST(PL);
    SY = SYZMAIN_NLIEQ(PL1, P, SANZ, SRD, T);
  } else {
    SY = SYZMAIN_NLISEQ(PM, PL, SANZ, SRD, T);
  }
  return SY;
}

MASSTOR_LIST SYZMAIN_NLIEQ
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PL, P, SANZ, SRD, T)
MASSTOR_LIST PL, P, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST SY, L, H, TW1, TW2, GBTM, GB, GBR, POSV, SPAK;

  GB = SYZGB_NLGBF(PL, SANZ, &GBTM, &T);
  TW2 = MASNCGB_DINLNF(T, GB, P);
  if (TW2 != 0) {
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("INLEQ: Gleichung nicht loesbar! ", 32L);
    return MASSTOR_SIL;
  }
  if (SRD == 1) {
    GBR = SYZFUNC_NLDGBRED(GB, GBTM, &H, &T);
    if (MASSTOR_LENGTH(GBR) == 1) {
      return MASSTOR_SIL;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SPAK = SYZFUNC_NLRCSP(GB, MASSTOR_LIST1(P), &T);
  if (SRD == 1) {
    SPAK = SYZHLP_INSPOSV(SPAK, POSV);
  }
  SY = SYZFUNC_NLMMULT(SPAK, GBTM, &T);
  return MASSTOR_FIRST(SY);
}

MASSTOR_LIST SYZMAIN_NLISEQ
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T)
# else
(PM, PL, SANZ, SRD, T)
MASSTOR_LIST PM, PL, SANZ, SRD, T;
# endif
{
  MASSTOR_LIST L, H, GB, GBR, SPAK, GBTM, SY, PL1, PL2, TW1, TW2, TW3, TW4, POSV, POSV1, P;

  PL1 = SYZHLP_MTPLH(PM, &L);
  P = SYZHLP_PLHTP(PL);
  PL2 = SYZHLP_EX0PL(PL1);
  POSV1 = SYZHLP_GENPOSV(PL1, PL2);
  PL1 = PL2;
  SYZHLP_ALFA(L);
  T = SYZHLP_TA(L, T);
  GB = SYZGB_NLGBEF(PL1, SANZ, L, &GBTM, &T);
  TW4 = MASNCGB_DINLNF(T, GB, P);
  if (TW4 != 0) {
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("INLSEQ: Gleichungssystem nicht loesbar! ", 40L);
    SYZHLP_ALFRA(L);
    T = SYZHLP_TR(L, T);
    return MASSTOR_SIL;
  }
  if (SRD == 1) {
    GBR = SYZFUNC_NLDGBRED(GB, GBTM, &H, &T);
    if (MASSTOR_LENGTH(GBR) == 1) {
      SYZHLP_ALFRA(L);
      T = SYZHLP_TR(L, T);
      return MASSTOR_SIL;
    }
    POSV = SYZHLP_GENPOSV(GB, GBR);
    GB = GBR;
  }
  SPAK = SYZFUNC_NLRCSP(GB, MASSTOR_LIST1(P), &T);
  if (SRD == 1) {
    SPAK = SYZHLP_INSPOSV(SPAK, POSV);
  }
  SY = SYZFUNC_NLMMULT(SPAK, GBTM, &T);
  SY = SYZHLP_INSPOSV(SY, POSV1);
  SY = MASSTOR_FIRST(SYZHLP_EVR(SY, L));
  SYZHLP_ALFRA(L);
  T = SYZHLP_TR(L, T);
  return SY;
}

void SYZMAIN_STINL
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST VL, MASSTOR_LIST T)
# else
(SY, PM, PL, VL, T)
MASSTOR_LIST SY, PM, PL, VL, T;
# endif
{
  MASSTOR_LIST P1, PL1, P;

  if (SY == MASSTOR_SIL) {
    return;
  }
  MASBIOS_BLINES(1);
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL1, &PM);
    MASSTOR_ADV(PL, &P, &PL);
    P1 = SYZFUNC_NLPLMULT(SY, PL1, &T);
    P1 = DIPRN_DIRPDF(P1, P);
    MASBIOS_SWRITE(" N-GLEICHUNGS-TEST:  ", 21L);
    SYZHLP_PLWR(MASSTOR_LIST1(P1), VL);
    MASBIOS_BLINES(0);
  }
}

void SYZMAIN_OREC
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST *P3, MASSTOR_LIST *P4, MASSTOR_LIST *T)
# else
(P1, P2, P3, P4, T)
MASSTOR_LIST P1, P2;
MASSTOR_LIST *P3, *P4, *T;
# endif
{
  MASSTOR_LIST PL1, PL2, SY;

  P2 = DIPRN_DIRPNG(P2);
  PL1 = SACLIST_CCONC(MASSTOR_LIST1(P1), MASSTOR_LIST1(P2));
  SY = SYZMAIN_NLHEQ(PL1, 1, 0, *T);
  PL2 = SYZHLP_VMADD(SY);
  *P3 = MASSTOR_FIRST(PL2);
  *P4 = DIPRN_DIRPNG(MASSTOR_FIRST(MASSTOR_RED(PL2)));
  return;
}

void BEGIN_SYZMAIN()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_MASBIOS();
    BEGIN_MASNC();
    BEGIN_MASNCGB();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SYZFUNC();
    BEGIN_SYZGB();
    BEGIN_SYZHLP();

  }
}