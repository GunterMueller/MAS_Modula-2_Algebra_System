#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASNC
#include "MASNC.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SYZHLP
#include "SYZHLP.h"
#endif

CHAR SYZHLP_rcsid [] = "$Id: SYZHLP.md,v 1.2 1992/02/12 17:33:18 pesch Exp $";
CHAR SYZHLP_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SYZHLP.mi,v 1.3 1992/10/15 16:29:22 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SYZHLP_ALFA
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST LF, G, P, G1, P1, C;

  if (DIPC_EVORD < MASSTOR_BETA) {
    return;
  }
  MASBIOS_SWRITE("ALFA", 4L);
  LF = DIPC_EVORD;
  G = 0;
  while (LF != MASSTOR_SIL) {
    MASSTOR_ADV(LF, &P, &LF);
    G1 = SACPOL_PDEG(P);
    if (G1 > G) {
      G = G1;
    }
  }
  C = 1;
  while (C <= L) {
    P1 = SACLIST_CCONC(MASSTOR_LIST1(G + C), MASSTOR_LIST1(1));
    DIPC_EVORD = SACLIST_CCONC(MASSTOR_LIST1(P1), DIPC_EVORD);
    C = C + 1;
  }
  return;
}

void SYZHLP_ALFRA
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  if (DIPC_EVORD < MASSTOR_BETA) {
    return;
  }
  while (L >= 1) {
    DIPC_EVORD = MASSTOR_RED(DIPC_EVORD);
    L = L - 1;
  }
  return;
}

MASSTOR_LIST SYZHLP_ADDPPOS
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST POS)
# else
(PL, P, POS)
MASSTOR_LIST PL, P, POS;
# endif
{
  MASSTOR_LIST PL1, C, P1, P2;

  PL1 = PL;
  PL = MASSTOR_SIL;
  {
    LONGINT B_1 = 1, B_2 = POS - 1;

    if (B_1 <= B_2)
      for (C = B_1;; C += 1) {
        MASSTOR_ADV(PL1, &P1, &PL1);
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P1));
        if (C >= B_2) break;
      }
  }
  MASSTOR_ADV(PL1, &P1, &PL1);
  P2 = DIPRN_DIRPSM(P1, P);
  PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P2));
  while (PL1 != MASSTOR_SIL) {
    MASSTOR_ADV(PL1, &P1, &PL1);
    PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P1));
  }
  return PL;
}

void SYZHLP_PLWR
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST VL)
# else
(PL, VL)
MASSTOR_LIST PL, VL;
# endif
{
  MASSTOR_LIST OS, LS, RS, P, P1;

  OS = -1;
  LS = 0;
  RS = 80;
  MASBIOS_SOLINE(&OS, &LS, &RS);
  if (PL == MASSTOR_SIL) {
    MASBIOS_SWRITE(" () ", 4L);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  while (MASSTOR_RED(PL) != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P, &PL);
    if (P == 0) {
      MASBIOS_SWRITE(" 0, ", 4L);
    } else {
      DIPRN_DIRPWR(P, VL, -1);
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  DIPRN_DIRPWR(MASSTOR_FIRST(PL), VL, -1);
  MASBIOS_SWRITE(")", 1L);
  return;
}

void SYZHLP_PMWR
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST VL)
# else
(PM, VL)
MASSTOR_LIST PM, VL;
# endif
{
  MASSTOR_LIST PL;

  if (PM == MASSTOR_SIL) {
    MASBIOS_SWRITE("()", 2L);
    return;
  }
  MASBIOS_SWRITE("(", 1L);
  MASBIOS_BLINES(0);
  while (MASSTOR_RED(PM) != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    SYZHLP_PLWR(PL, VL);
    MASBIOS_SWRITE(", ", 2L);
    MASBIOS_BLINES(0);
  }
  MASSTOR_ADV(PM, &PL, &PM);
  SYZHLP_PLWR(PL, VL);
  MASBIOS_BLINES(0);
  MASBIOS_SWRITE(")", 1L);
  return;
}

MASSTOR_LIST SYZHLP_APP0
# ifdef __STDC__
(MASSTOR_LIST PM)
# else
(PM)
MASSTOR_LIST PM;
# endif
{
  MASSTOR_LIST PM1, PL;

  PM1 = MASSTOR_SIL;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    PL = SACLIST_CCONC(PL, MASSTOR_LIST1(0));
    PM1 = SACLIST_CCONC(PM1, MASSTOR_LIST1(PL));
  }
  return PM1;
}

MASSTOR_LIST SYZHLP_ADDLAST
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST PL)
# else
(P, PL)
MASSTOR_LIST P, PL;
# endif
{
  MASSTOR_LIST PL1, P1, P2;

  PL1 = MASSTOR_SIL;
  while (MASSTOR_RED(PL) != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P1, &PL);
    PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P1));
  }
  MASSTOR_ADV(PL, &P1, &PL);
  P2 = DIPRN_DIRPSM(P, P1);
  PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P2));
  return PL1;
}

MASSTOR_LIST SYZHLP_POS
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST PL)
# else
(P, PL)
MASSTOR_LIST P, PL;
# endif
{
  MASSTOR_LIST POS, P1;

  POS = 1;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P1, &PL);
    if (SACLIST_EQUAL(P1, P) == 1) {
      return POS;
    }
    POS = POS + 1;
  }
}

MASSTOR_LIST SYZHLP_POL
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST POS)
# else
(PL, POS)
MASSTOR_LIST PL, POS;
# endif
{
  MASSTOR_LIST C, P;

  {
    LONGINT B_3 = 1, B_4 = POS;

    if (B_3 <= B_4)
      for (C = B_3;; C += 1) {
        MASSTOR_ADV(PL, &P, &PL);
        if (C >= B_4) break;
      }
  }
  return P;
}

MASSTOR_LIST SYZHLP_GENPOSV
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST GBR)
# else
(GB, GBR)
MASSTOR_LIST GB, GBR;
# endif
{
  MASSTOR_LIST GB1, POS, P1, P2, POSV;

  POSV = MASNC_EVZERO(MASSTOR_LENGTH(GB));
  while (GBR != MASSTOR_SIL) {
    POS = 1;
    MASSTOR_ADV(GBR, &P1, &GBR);
    GB1 = GB;
    for (;;) {
      MASSTOR_ADV(GB1, &P2, &GB1);
      if (SACLIST_EQUAL(P1, P2) == 1) {
        POSV = SYZHLP_ADDPPOS(POSV, 1, POS);
        goto EXIT_1;
      }
      POS = POS + 1;
    } EXIT_1:;
  }
  return POSV;
}

MASSTOR_LIST SYZHLP_INSPOSV
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST POSV)
# else
(PM, POSV)
MASSTOR_LIST PM, POSV;
# endif
{
  MASSTOR_LIST PL, PL1, P, POSV1, TW, PM1;

  PM1 = MASSTOR_SIL;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    PL1 = MASSTOR_SIL;
    POSV1 = POSV;
    while (POSV1 != MASSTOR_SIL) {
      MASSTOR_ADV(POSV1, &TW, &POSV1);
      if (TW == 0) {
        PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(0));
      } else {
        MASSTOR_ADV(PL, &P, &PL);
        PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P));
      }
    }
    PM1 = SACLIST_CCONC(PM1, MASSTOR_LIST1(PL1));
  }
  return PM1;
}

MASSTOR_LIST SYZHLP_EXPPL
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST GB)
# else
(P, GB)
MASSTOR_LIST P, GB;
# endif
{
  MASSTOR_LIST GB1, P1;

  GB1 = MASSTOR_SIL;
  while (GB != MASSTOR_SIL) {
    MASSTOR_ADV(GB, &P1, &GB);
    if (SACLIST_EQUAL(P, P1) != 1) {
      GB1 = SACLIST_CCONC(GB1, MASSTOR_LIST1(P1));
    }
  }
  return GB1;
}

MASSTOR_LIST SYZHLP_EX0PL
# ifdef __STDC__
(MASSTOR_LIST PL)
# else
(PL)
MASSTOR_LIST PL;
# endif
{
  MASSTOR_LIST PL1, P;

  PL1 = MASSTOR_SIL;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P, &PL);
    if (P != 0) {
      PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P));
    }
  }
  return PL1;
}

MASSTOR_LIST SYZHLP_EVF
# ifdef __STDC__
(MASSTOR_LIST EV, MASSTOR_LIST L)
# else
(EV, L)
MASSTOR_LIST EV, L;
# endif
{
  MASSTOR_LIST EV1, EV11, C;

  EV1 = MASSTOR_SIL;
  C = 1;
  while (C <= L) {
    MASSTOR_ADV(EV, &EV11, &EV);
    EV1 = SACLIST_CCONC(EV1, MASSTOR_LIST1(EV11));
    C = C + 1;
  }
  return EV1;
}

MASSTOR_LIST SYZHLP_EVR
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST L)
# else
(PM, L)
MASSTOR_LIST PM, L;
# endif
{
  MASSTOR_LIST PM1, PL, PL1, P, P1, P2, KO, EV, C, H;

  PM1 = MASSTOR_SIL;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    PL1 = MASSTOR_SIL;
    while (PL != MASSTOR_SIL) {
      MASSTOR_ADV(PL, &P, &PL);
      if (P == 0) {
        PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P));
      } else {
        P1 = 0;
        while (P != MASSTOR_SIL) {
          DIPC_DIPMAD(P, &KO, &EV, &P);
          C = L;
          while (C != 0) {
            DIPC_EVDEL(EV, 1, &EV, &H);
            C = C - 1;
          }
          P2 = DIPC_DIPFMO(KO, EV);
          P1 = DIPRN_DIRPSM(P1, P2);
        }
        PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P1));
      }
    }
    PM1 = SACLIST_CCONC(PM1, MASSTOR_LIST1(PL1));
  }
  return PM1;
}

MASSTOR_LIST SYZHLP_MREAD
# ifdef __STDC__
(MASSTOR_LIST VL)
# else
(VL)
MASSTOR_LIST VL;
# endif
{
  MASSTOR_LIST PM, PL, CH;

  PM = MASSTOR_SIL;
  CH = MASBIOS_CREADB();
  if (CH != MASBIOS_MASORD('(')) {
    return PM;
  }
  do {
    CH = MASBIOS_CREADB();
    if (CH == MASBIOS_MASORD(',')) {
      CH = MASBIOS_CREADB();
    }
    if (CH != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      PL = DIPRN_DIRLRD(VL);
      PM = SACLIST_CCONC(PM, MASSTOR_LIST1(PL));
    }
  } while (!(CH == MASBIOS_MASORD(')')));
  return PM;
}

MASSTOR_LIST SYZHLP_NMREAD
# ifdef __STDC__
(MASSTOR_LIST VL, MASSTOR_LIST T)
# else
(VL, T)
MASSTOR_LIST VL, T;
# endif
{
  MASSTOR_LIST PM, PL, CH;

  PM = MASSTOR_SIL;
  CH = MASBIOS_CREADB();
  if (CH != MASBIOS_MASORD('(')) {
    return PM;
  }
  do {
    CH = MASBIOS_CREADB();
    if (CH == MASBIOS_MASORD(',')) {
      CH = MASBIOS_CREADB();
    }
    if (CH != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      PL = MASNC_DINLRD(VL, T);
      PM = SACLIST_CCONC(PM, MASSTOR_LIST1(PL));
    }
  } while (!(CH == MASBIOS_MASORD(')')));
  return PM;
}

MASSTOR_LIST SYZHLP_TA
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST T)
# else
(L, T)
MASSTOR_LIST L;
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST EV, L1, T1, P;

  EV = DIPC_DIPEVL(MASSTOR_FIRST(T));
  L1 = MASSTOR_LENGTH(EV) + L + 1;
  T1 = MASSTOR_SIL;
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &P, &T);
    P = DIPC_DIPINV(P, L1, L);
    T1 = SACLIST_CCONC(T1, MASSTOR_LIST1(P));
  }
  return T1;
}

MASSTOR_LIST SYZHLP_TR
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST T)
# else
(L, T)
MASSTOR_LIST L;
MASSTOR_LIST T;
# endif
{
  MASSTOR_LIST T1, P, P1, P2, KO, EV, C, H;

  T1 = MASSTOR_SIL;
  while (T != MASSTOR_SIL) {
    MASSTOR_ADV(T, &P, &T);
    P1 = 0;
    while (P != MASSTOR_SIL) {
      DIPC_DIPMAD(P, &KO, &EV, &P);
      C = 1;
      while (C <= L) {
        DIPC_EVDEL(EV, 1, &EV, &H);
        C = C + 1;
      }
      P2 = DIPC_DIPFMO(KO, EV);
      P1 = DIPRN_DIRPSM(P1, P2);
    }
    T1 = SACLIST_CCONC(T1, MASSTOR_LIST1(P1));
  }
  return T1;
}

void SYZHLP_NEXTPAIR
# ifdef __STDC__
(MASSTOR_LIST *P1, MASSTOR_LIST *P2, MASSTOR_LIST *PPL)
# else
(P1, P2, PPL)
MASSTOR_LIST *P1, *P2, *PPL;
# endif
{
  MASSTOR_LIST PP, PL1, PL2, PM1, PM2, PL, PM21, PM22, P;

  MASSTOR_ADV(*PPL, &PP, PPL);
  SACLIST_FIRST3(PP, &PL2, &PM1, &PM2);
  MASSTOR_ADV(PM1, &PL, &PL1);
  *P1 = MASSTOR_FIRST(PL);
  PM21 = MASSTOR_RED(PM2);
  *P2 = MASSTOR_FIRST(PM21);
  PM21 = MASSTOR_RED(PM2);
  PM22 = MASSTOR_RED(PM21);
  MASSTOR_SRED(PM2, PM22);
  if (PM22 == MASSTOR_SIL) {
    P = SACLIST_LAST(PL);
    MASSTOR_SFIRST(PL1, P);
  }
}

MASSTOR_LIST SYZHLP_EVT
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST L)
# else
(P1, P2, L)
MASSTOR_LIST P1, P2, L;
# endif
{
  MASSTOR_LIST EV1, EV2, EV11, EV21, LL, e1, e2;

  EV1 = DIPC_DIPEVL(P1);
  EV2 = DIPC_DIPEVL(P2);
  LL = 0;
  while (LL < L && EV1 != MASSTOR_SIL) {
    LL = LL + 1;
    MASSTOR_ADV(EV1, &e1, &EV1);
    MASSTOR_ADV(EV2, &e2, &EV2);
    if (e1 != e2) {
      return 0;
    }
  }
  return 1;
}

void SYZHLP_WRS1
# ifdef __STDC__
(MASSTOR_LIST SZ, MASSTOR_LIST C1, MASSTOR_LIST C2, MASSTOR_LIST C3)
# else
(SZ, C1, C2, C3)
MASSTOR_LIST SZ, C1, C2, C3;
# endif
{
  SACLIST_AWRITE(MASSTOR_TIME() - SZ);
  MASBIOS_SWRITE(" sec., ", 7L);
  MASBIOS_BLINES(0);
  if (C1 == 1) {
    SACLIST_AWRITE(C1);
    MASBIOS_SWRITE(" H-Polynom, ", 12L);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C1);
    MASBIOS_SWRITE(" H-Polynome, ", 13L);
    MASBIOS_BLINES(0);
  }
  if (C2 == 1) {
    SACLIST_AWRITE(C2);
    MASBIOS_SWRITE(" S-Polynom, ", 12L);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C2);
    MASBIOS_SWRITE(" S-Polynome, ", 13L);
    MASBIOS_BLINES(0);
  }
  if (C3 == 1) {
    SACLIST_AWRITE(C3);
    MASBIOS_SWRITE(" uebriges Paar. ", 16L);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C3);
    MASBIOS_SWRITE(" uebrige Paare. ", 16L);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(1);
  return;
}

void SYZHLP_WRS2
# ifdef __STDC__
(MASSTOR_LIST SZ, MASSTOR_LIST C1, MASSTOR_LIST TW1, MASSTOR_LIST C2, MASSTOR_LIST SPN, MASSTOR_LIST C3)
# else
(SZ, C1, TW1, C2, SPN, C3)
MASSTOR_LIST SZ, C1, TW1, C2, SPN, C3;
# endif
{
  SACLIST_AWRITE(MASSTOR_TIME() - SZ);
  MASBIOS_SWRITE(" sec., ", 7L);
  MASBIOS_BLINES(0);
  if (C1 == 1) {
    SACLIST_AWRITE(C1);
    MASBIOS_SWRITE(" H-Polynom, ", 12L);
    SYZHLP_PLWR(MASSTOR_LIST1(TW1), DIPC_VALIS);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C1);
    MASBIOS_SWRITE(" H-Polynome, ", 13L);
    SYZHLP_PLWR(MASSTOR_LIST1(TW1), DIPC_VALIS);
    MASBIOS_BLINES(0);
  }
  if (C2 == 1) {
    SACLIST_AWRITE(C2);
    MASBIOS_SWRITE(" S-Polynom, ", 12L);
    SYZHLP_PLWR(MASSTOR_LIST1(SPN), DIPC_VALIS);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C2);
    MASBIOS_SWRITE(" S-Polynome, ", 13L);
    SYZHLP_PLWR(MASSTOR_LIST1(SPN), DIPC_VALIS);
    MASBIOS_BLINES(0);
  }
  if (C3 == 1) {
    SACLIST_AWRITE(C3);
    MASBIOS_SWRITE(" uebriges Paar. ", 16L);
    MASBIOS_BLINES(0);
  } else {
    SACLIST_AWRITE(C3);
    MASBIOS_SWRITE(" uebrige Paare. ", 16L);
    MASBIOS_BLINES(0);
  }
  MASBIOS_BLINES(1);
  return;
}

MASSTOR_LIST SYZHLP_EVL
# ifdef __STDC__
(MASSTOR_LIST PM)
# else
(PM)
MASSTOR_LIST PM;
# endif
{
  MASSTOR_LIST L, PL, P;

  L = 0;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL, &PM);
    while (PL != MASSTOR_SIL) {
      MASSTOR_ADV(PL, &P, &PL);
      if (P != 0) {
        L = MASSTOR_LENGTH(DIPC_DIPEVL(P));
        return L;
      }
    }
  }
  return L;
}

void SYZHLP_NORMF
# ifdef __STDC__
(MASSTOR_LIST *PL, MASSTOR_LIST *GBTM)
# else
(PL, GBTM)
MASSTOR_LIST *PL, *GBTM;
# endif
{
  MASSTOR_LIST PL1, PL2, POS, L, NV, P, PN, NF;

  PL1 = *PL;
  *PL = MASSTOR_SIL;
  *GBTM = MASSTOR_SIL;
  POS = 1;
  L = MASSTOR_LENGTH(PL1);
  NV = MASNC_EVZERO(L);
  while (PL1 != MASSTOR_SIL) {
    MASSTOR_ADV(PL1, &P, &PL1);
    PN = DIPRN_DIRPMC(P);
    NF = DIPRN_DIRPQ(PN, P);
    PL2 = SYZHLP_ADDPPOS(NV, NF, POS);
    *PL = SACLIST_CCONC(*PL, MASSTOR_LIST1(PN));
    *GBTM = SACLIST_CCONC(*GBTM, MASSTOR_LIST1(PL2));
    POS = POS + 1;
  }
  return;
}

MASSTOR_LIST SYZHLP_GBTMRED
# ifdef __STDC__
(MASSTOR_LIST GBTM, MASSTOR_LIST POSV)
# else
(GBTM, POSV)
MASSTOR_LIST GBTM, POSV;
# endif
{
  MASSTOR_LIST GBTM1, PL, PL1, P, TW, POSV1;

  GBTM1 = MASSTOR_SIL;
  while (GBTM != MASSTOR_SIL) {
    MASSTOR_ADV(GBTM, &PL, &GBTM);
    POSV1 = POSV;
    PL1 = MASSTOR_SIL;
    while (PL != MASSTOR_SIL) {
      MASSTOR_ADV(PL, &P, &PL);
      MASSTOR_ADV(POSV1, &TW, &POSV1);
      if (TW == 1) {
        PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P));
      }
    }
    GBTM1 = SACLIST_CCONC(GBTM1, MASSTOR_LIST1(PL1));
  }
  return GBTM1;
}

MASSTOR_LIST SYZHLP_MTPLV
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST *L)
# else
(PM, L)
MASSTOR_LIST PM;
MASSTOR_LIST *L;
# endif
{
  MASSTOR_LIST L1, L2, PL1, P, P1, PL, POS;

  *L = MASSTOR_LENGTH(MASSTOR_FIRST(PM));
  L1 = SYZHLP_EVL(PM);
  if (L1 == 0) {
    PL = MASSTOR_LIST1(0);
    return PL;
  }
  L1 = L1 + 1;
  L2 = L1 + *L;
  PL = MASSTOR_SIL;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL1, &PM);
    POS = 1;
    P = 0;
    while (PL1 != MASSTOR_SIL) {
      MASSTOR_ADV(PL1, &P1, &PL1);
      if (P1 != 0) {
        P1 = DIPC_DIPINV(P1, L1, *L);
        P1 = DIPC_DIPMPV(P1, L2 - POS, 1);
        P = DIPRN_DIRPSM(P1, P);
      }
      POS = POS + 1;
    }
    if (P != 0) {
      PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P));
    }
  }
  return PL;
}

MASSTOR_LIST SYZHLP_PLVTM
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST L)
# else
(PL, L)
MASSTOR_LIST PL, L;
# endif
{
  MASSTOR_LIST NV, PL1, P, POS, KO, EV, P1, P2, P3, EV1, EV2, C, H, PM;

  PM = MASSTOR_SIL;
  NV = MASNC_EVZERO(L);
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P, &PL);
    PL1 = MASSTOR_SIL;
    POS = 1;
    while (POS <= L) {
      P1 = P;
      EV2 = SYZHLP_ADDPPOS(NV, 1, POS);
      POS = POS + 1;
      P2 = 0;
      while (P1 != MASSTOR_SIL) {
        DIPC_DIPMAD(P1, &KO, &EV, &P1);
        EV1 = SYZHLP_EVF(EV, L);
        if (SACLIST_EQUAL(EV2, EV1) == 1) {
          C = 1;
          while (C <= L) {
            DIPC_EVDEL(EV, 1, &EV, &H);
            C = C + 1;
          }
          P3 = DIPC_DIPFMO(KO, EV);
          P2 = DIPRN_DIRPSM(P3, P2);
        }
      }
      PL1 = SACLIST_CCONC(PL1, MASSTOR_LIST1(P2));
    }
    PM = SACLIST_CCONC(PM, MASSTOR_LIST1(PL1));
  }
  return PM;
}

MASSTOR_LIST SYZHLP_MTPLH
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST *L)
# else
(PM, L)
MASSTOR_LIST PM;
MASSTOR_LIST *L;
# endif
{
  MASSTOR_LIST L1, L2, POS1, POS2, PL, PL1, P;

  *L = MASSTOR_LENGTH(PM);
  L1 = SYZHLP_EVL(PM);
  PL = MASNC_EVZERO(MASSTOR_LENGTH(MASSTOR_FIRST(PM)));
  L2 = L1 + *L + 1;
  POS1 = 0;
  while (PM != MASSTOR_SIL) {
    MASSTOR_ADV(PM, &PL1, &PM);
    POS1 = POS1 + 1;
    POS2 = 1;
    while (PL1 != MASSTOR_SIL) {
      MASSTOR_ADV(PL1, &P, &PL1);
      if (P != 0) {
        P = DIPC_DIPINV(P, L2, *L);
        P = DIPC_DIPMPV(P, L2 - POS1, 1);
        PL = SYZHLP_ADDPPOS(PL, P, POS2);
      }
      POS2 = POS2 + 1;
    }
  }
  return PL;
}

MASSTOR_LIST SYZHLP_PLHTP
# ifdef __STDC__
(MASSTOR_LIST PL)
# else
(PL)
MASSTOR_LIST PL;
# endif
{
  MASSTOR_LIST L1, L2, L3, POS, P, P1;

  P = 0;
  L1 = MASSTOR_LENGTH(PL);
  L2 = SYZHLP_EVL(MASSTOR_LIST1(PL));
  L3 = L2 + L1 + 1;
  POS = 0;
  while (PL != MASSTOR_SIL) {
    MASSTOR_ADV(PL, &P1, &PL);
    POS = POS + 1;
    if (P1 != 0) {
      P1 = DIPC_DIPINV(P1, L3, L1);
      P1 = DIPC_DIPMPV(P1, L3 - POS, 1);
      P = DIPRN_DIRPSM(P, P1);
    }
  }
  return P;
}

MASSTOR_LIST SYZHLP_VMADD
# ifdef __STDC__
(MASSTOR_LIST PM)
# else
(PM)
MASSTOR_LIST PM;
# endif
{
  MASSTOR_LIST PL, PL1, POS, P;

  PL = MASNC_EVZERO(MASSTOR_LENGTH(MASSTOR_FIRST(PM)));
  while (PM != MASSTOR_SIL) {
    POS = 0;
    MASSTOR_ADV(PM, &PL1, &PM);
    while (PL1 != MASSTOR_SIL) {
      MASSTOR_ADV(PL1, &P, &PL1);
      POS = POS + 1;
      PL = SYZHLP_ADDPPOS(PL, P, POS);
    }
  }
  return PL;
}

void BEGIN_SYZHLP()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_MASBIOS();
    BEGIN_MASNC();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACPOL();

  }
}
