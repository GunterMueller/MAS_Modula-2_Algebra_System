#include "SYSTEM_.h"

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

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

CHAR DIPADOM_rcsid [] = "$Id: DIPADOM.md,v 1.7 1994/10/21 12:33:46 pfeil Exp $";
CHAR DIPADOM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPADOM.mi,v 1.9 1995/11/05 09:26:20 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPADOM_DIPEXP
# ifdef __STDC__
(MASSTOR_LIST C_128_A, MASSTOR_LIST NL)
# else
(C_128_A, NL)
MASSTOR_LIST C_128_A, NL;
# endif
{
  MASSTOR_LIST AL, B, BL, D, KL;

  if (NL == 0) {
    AL = DIPC_DIPLBC(C_128_A);
    D = MASSTOR_RED(AL);
    BL = MASADOM_ADFI(D, 1);
    B = DIPC_DIPFMO(BL, MASSTOR_BETA);
  }
  if (NL == 1) {
    B = C_128_A;
    return B;
  }
  KL = NL / 2;
  B = DIPADOM_DIPEXP(C_128_A, KL);
  B = DIPADOM_DIPROD(B, B);
  if (NL > 2 * KL) {
    B = DIPADOM_DIPROD(B, C_128_A);
  }
  return B;
}

MASSTOR_LIST DIPADOM_DIFIP
# ifdef __STDC__
(MASSTOR_LIST C_127_A, MASSTOR_LIST D)
# else
(C_127_A, D)
MASSTOR_LIST C_127_A, D;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, BLP, CL, EL, FL, v, MP, RL, RLS, RLP;

  if (C_127_A == 0) {
    B = 0;
    return B;
  }
  DIPC_PFDIP(C_127_A, &RL, &AP);
  v = MASADOM_ADVLDD(D);
  RLS = MASSTOR_LENGTH(v);
  RLP = RL - RLS;
  if (RLP < 0) {
    SACLIST_OWRITE(RLP);
    B = 0;
    MASERR_ERROR(MASERR_severe, "DIFIP: to few coefficient variables.", 36L);
    return B;
  }
  AP = DIPC_DIPFP(RLP, AP);
  B = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    BL = MASADOM_ADFIP(D, AL);
    if (MASADOM_ADSIGN(BL) != 0) {
      B = DIPC_DIPMCP(EL, BL, B);
    }
  } while (!(AP == MASSTOR_SIL));
  if (B == MASSTOR_SIL) {
    B = 0;
  } else {
    B = MASSTOR_INV(B);
  }
  return B;
}

MASSTOR_LIST DIPADOM_DILRD
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST D)
# else
(V, D)
MASSTOR_LIST V, D;
# endif
{
  MASSTOR_LIST C_126_A, AL, C;

  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('(')) {
    MASERR_ERROR(MASERR_severe, "ERROR FOUND BY DILRD.", 21L);
    return C_126_A;
  }
  C_126_A = MASSTOR_BETA;
  do {
    C = MASBIOS_CREADB();
    if (C == MASBIOS_MASORD(',')) {
      C = MASBIOS_CREADB();
    }
    if (C != MASBIOS_MASORD(')')) {
      MASBIOS_BKSP();
      AL = DIPADOM_DIREAD(V, D);
      C_126_A = MASSTOR_COMP(AL, C_126_A);
    }
  } while (!(C == MASBIOS_MASORD(')')));
  C_126_A = MASSTOR_INV(C_126_A);
  return C_126_A;
}

MASSTOR_LIST DIPADOM_DILSUM
# ifdef __STDC__
(MASSTOR_LIST C_125_A)
# else
(C_125_A)
MASSTOR_LIST C_125_A;
# endif
{
  MASSTOR_LIST B, BP, BPP, C, CP, CPP;

  if (C_125_A == MASSTOR_SIL) {
    B = 0;
    return B;
  }
  C = C_125_A;
  MASSTOR_ADV(C, &B, &CP);
  while (C != CP) {
    MASSTOR_ADV(CP, &BP, &CPP);
    BPP = DIPADOM_DIPSUM(B, BP);
    MASSTOR_SFIRST(C, BPP);
    MASSTOR_SRED(C, CPP);
    C = CPP;
    MASSTOR_ADV(C, &B, &CP);
  }
  return B;
}

void DIPADOM_DILWR
# ifdef __STDC__
(MASSTOR_LIST C_124_A, MASSTOR_LIST V)
# else
(C_124_A, V)
MASSTOR_LIST C_124_A, V;
# endif
{
  MASSTOR_LIST AL, AP, LS, RS;

  MASBIOS_BLINES(0);
  AP = C_124_A;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    DIPADOM_DIWRIT(AL, V);
    MASBIOS_BLINES(1);
  }
  return;
}

MASSTOR_LIST DIPADOM_DIPBCP
# ifdef __STDC__
(MASSTOR_LIST C_123_A, MASSTOR_LIST BL)
# else
(C_123_A, BL)
MASSTOR_LIST C_123_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, PL;

  if (C_123_A == 0 || MASADOM_ADSIGN(BL) == 0) {
    C = 0;
    return C;
  }
  C = MASSTOR_BETA;
  AP = C_123_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    PL = MASADOM_ADPROD(AL, BL);
    C = DIPC_DIPMCP(EL, PL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPADOM_DIPDIF
# ifdef __STDC__
(MASSTOR_LIST C_122_A, MASSTOR_LIST B)
# else
(C_122_A, B)
MASSTOR_LIST C_122_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_122_A == 0) {
    C = DIPADOM_DIPNEG(B);
    return C;
  }
  if (B == 0) {
    C = C_122_A;
    return C;
  }
  AP = C_122_A;
  BP = B;
  CP = MASSTOR_BETA;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = DIPC_EVCOMP(EL, FL);
    if (SL == 1) {
      DIPC_DIPMAD(AP, &AL, &EL, &AP);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else {
      if (SL == -1) {
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = MASADOM_ADNEG(BL);
        CP = DIPC_DIPMCP(FL, CL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = MASADOM_ADDIF(AL, BL);
        if (MASADOM_ADSIGN(CL) != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  APP = AP;
  if (AP == MASSTOR_SIL) {
    if (BP != MASSTOR_SIL) {
      APP = DIPADOM_DIPNEG(BP);
    }
  }
  if (CP == MASSTOR_SIL) {
    C = APP;
  } else {
    CPP = CP;
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CPP, APP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DIPADOM_DIPFAC
# ifdef __STDC__
(MASSTOR_LIST C_121_A, MASSTOR_LIST VOO)
# else
(C_121_A, VOO)
MASSTOR_LIST C_121_A, VOO;
# endif
{
  if (C_121_A == 0) {
    return MASSTOR_SIL;
  }
  return MASADOM_ADPFACT(C_121_A, VOO);
}

void DIPADOM_DIPIRL
# ifdef __STDC__
(MASSTOR_LIST *P, BOOLEAN *CS)
# else
(P, CS)
MASSTOR_LIST *P;
BOOLEAN *CS;
# endif
{
  MASSTOR_LIST H, f, HTf, HTg, g;
  BOOLEAN NewHT;

  *CS = FALSE;
  do {
    H = MASSTOR_SIL;
    NewHT = FALSE;
    while (*P != MASSTOR_SIL) {
      MASSTOR_ADV(*P, &f, P);
      HTf = DIPC_DIPEVL(f);
      g = DIPADOM_DIPNF(SACLIST_CCONC(*P, H), f);
      if (g != 0) {
        HTg = DIPC_DIPEVL(g);
        if (SACLIST_EQUAL(HTf, HTg) == 1) {
          if (SACLIST_EQUAL(f, g) != 1) {
            *CS = TRUE;
          }
        } else {
          NewHT = TRUE;
          *CS = TRUE;
        }
        H = MASSTOR_COMP(g, H);
      }
    }
    *P = H;
  } while (!!NewHT);
}

MASSTOR_LIST DIPADOM_DIPLIR
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST H, f, HTf, HTg, g;
  BOOLEAN NewHT;

  do {
    H = MASSTOR_SIL;
    NewHT = FALSE;
    while (P != MASSTOR_SIL) {
      MASSTOR_ADV(P, &f, &P);
      HTf = DIPC_DIPEVL(f);
      g = DIPADOM_DIPNF(SACLIST_CCONC(P, H), f);
      if (g != 0) {
        HTg = DIPC_DIPEVL(g);
        if (SACLIST_EQUAL(HTf, HTg) != 1) {
          NewHT = TRUE;
        }
        H = MASSTOR_COMP(g, H);
      }
    }
    P = H;
  } while (!!NewHT);
  return P;
}

MASSTOR_LIST DIPADOM_DIPRLF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST p)
# else
(P, p)
MASSTOR_LIST P, p;
# endif
{
  MASSTOR_LIST H, f, g;

  H = MASSTOR_SIL;
  while (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, &f, &P);
    g = DIPADOM_DIPNF(MASSTOR_LIST1(p), f);
    if (g != 0) {
      H = MASSTOR_COMP(g, H);
    }
  }
  return H;
}

MASSTOR_LIST DIPADOM_DIPMOC
# ifdef __STDC__
(MASSTOR_LIST C_120_A)
# else
(C_120_A)
MASSTOR_LIST C_120_A;
# endif
{
  MASSTOR_LIST BL, C, CL, SL;

  C = C_120_A;
  if (C_120_A == 0) {
    return C;
  }
  BL = DIPC_DIPLBC(C_120_A);
  SL = MASADOM_ADONE(BL);
  if (SL == 1) {
    return C;
  }
  SL = MASADOM_ADINVT(BL);
  if (SL != 1) {
    return C;
  }
  CL = MASADOM_ADINV(BL);
  C = DIPADOM_DIPBCP(C_120_A, CL);
  return C;
}

MASSTOR_LIST DIPADOM_DIPNEG
# ifdef __STDC__
(MASSTOR_LIST C_119_A)
# else
(C_119_A)
MASSTOR_LIST C_119_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL;

  if (C_119_A == 0) {
    B = 0;
    return B;
  }
  AS = C_119_A;
  B = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    BL = MASADOM_ADNEG(AL);
    B = DIPC_DIPMCP(EL, BL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST DIPADOM_DIPNF
# ifdef __STDC__
(MASSTOR_LIST C_118_A, MASSTOR_LIST B)
# else
(C_118_A, B)
MASSTOR_LIST C_118_A, B;
# endif
{
  return MASADOM_ADPNF(C_118_A, B);
}

void DIPADOM_DIPQR
# ifdef __STDC__
(MASSTOR_LIST C_117_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R)
# else
(C_117_A, B, Q, R)
MASSTOR_LIST C_117_A, B;
MASSTOR_LIST *Q, *R;
# endif
{
  MASSTOR_LIST AL, BL, BP, DL, ML, NL, Q1, QL, QP, RP, SL, TL;

  DIPC_DIPMAD(B, &BL, &NL, &BP);
  if (BP == MASSTOR_SIL) {
    BP = 0;
  }
  *Q = MASSTOR_BETA;
  *R = C_117_A;
  for (;;) {
    while (*R != 0) {
      ML = DIPC_DIPEVL(*R);
      DIPC_EVDFSI(ML, NL, &DL, &TL);
      if (TL < 0) {
        goto EXIT_1;
      }
      AL = DIPC_DIPLBC(*R);
      QL = MASADOM_ADQUOT(AL, BL);
      *Q = DIPC_DIPMCP(DL, QL, *Q);
      Q1 = DIPC_DIPFMO(QL, DL);
      RP = DIPC_DIPMRD(*R);
      QP = DIPADOM_DIPROD(BP, Q1);
      *R = DIPADOM_DIPDIF(RP, QP);
    }
    goto EXIT_1;
  } EXIT_1:;
  if (*Q == MASSTOR_SIL) {
    *Q = 0;
  } else {
    *Q = MASSTOR_INV(*Q);
  }
  return;
}

MASSTOR_LIST DIPADOM_DIPROD
# ifdef __STDC__
(MASSTOR_LIST C_116_A, MASSTOR_LIST B)
# else
(C_116_A, B)
MASSTOR_LIST C_116_A, B;
# endif
{
  MASSTOR_LIST AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL;

  if (C_116_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  AS = SACLIST_CINV(C_116_A);
  BS = B;
  C = MASSTOR_LIST1(0);
  CS = C;
  do {
    DIPC_DIPMAD(BS, &BL, &FL, &BS);
    AP = AS;
    C1 = MASSTOR_BETA;
    do {
      DIPC_DIPMAD(AP, &EL, &AL, &AP);
      CL = MASADOM_ADPROD(AL, BL);
      GL = DIPC_EVSUM(EL, FL);
      C1 = DIPC_DIPMCP(CL, GL, C1);
    } while (!(AP == MASSTOR_SIL));
    C = MASSTOR_COMP(C1, C);
  } while (!(BS == MASSTOR_SIL));
  MASSTOR_ADV(C, &C1, &C);
  MASSTOR_SFIRST(CS, C1);
  MASSTOR_SRED(CS, C);
  C = DIPADOM_DILSUM(C);
  return C;
}

MASSTOR_LIST DIPADOM_DIPS
# ifdef __STDC__
(MASSTOR_LIST C_115_A, MASSTOR_LIST B)
# else
(C_115_A, B)
MASSTOR_LIST C_115_A, B;
# endif
{
  return MASADOM_ADPSP(C_115_A, B);
}

MASSTOR_LIST DIPADOM_DIPSFF
# ifdef __STDC__
(MASSTOR_LIST C_114_A, MASSTOR_LIST VOO)
# else
(C_114_A, VOO)
MASSTOR_LIST C_114_A, VOO;
# endif
{
  if (C_114_A == 0) {
    return MASSTOR_SIL;
  }
  return MASADOM_ADPSFF(C_114_A, VOO);
}

MASSTOR_LIST DIPADOM_DIPSUM
# ifdef __STDC__
(MASSTOR_LIST C_113_A, MASSTOR_LIST B)
# else
(C_113_A, B)
MASSTOR_LIST C_113_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_113_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_113_A;
    return C;
  }
  AP = C_113_A;
  BP = B;
  CP = MASSTOR_BETA;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = DIPC_EVCOMP(EL, FL);
    if (SL == 1) {
      DIPC_DIPMAD(AP, &AL, &EL, &AP);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else {
      if (SL == -1) {
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CP = DIPC_DIPMCP(FL, BL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = MASADOM_ADSUM(AL, BL);
        if (MASADOM_ADSIGN(CL) != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  if (AP == MASSTOR_SIL) {
    APP = BP;
  } else {
    APP = AP;
  }
  if (CP == MASSTOR_SIL) {
    C = APP;
  } else {
    CPP = CP;
    C = MASSTOR_INV(CP);
    MASSTOR_SRED(CPP, APP);
  }
  if (C == MASSTOR_SIL) {
    C = 0;
  }
  return C;
}

MASSTOR_LIST DIPADOM_DIREAD
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST D)
# else
(V, D)
MASSTOR_LIST V, D;
# endif
{
  MASSTOR_LIST C_112_A, A1, AL, AP, C, EL, ES, FL, IL, JL, RL, VL;

  C_112_A = 0;
  C = MASBIOS_CREADB();
  if (C == MASBIOS_MASORD('0')) {
    return C_112_A;
  }
  MASBIOS_BKSP();
  C = MASBIOS_CREADB();
  MASBIOS_BKSP();
  if (C == MASBIOS_MASORD(',')) {
    MASERR_ERROR(MASERR_severe, "ERROR FOUND BY DIREAD.", 22L);
    return C_112_A;
  }
  FL = 0;
  if (C == MASBIOS_MASORD('(')) {
    C = MASBIOS_CREADB();
    FL = 1;
  }
  if (C == MASBIOS_MASORD(')')) {
    if (FL == 1) {
      return C_112_A;
    }
    MASERR_ERROR(MASERR_severe, "ERROR FOUND BY DIREAD.", 22L);
    return C_112_A;
  }
  RL = MASSTOR_LENGTH(V);
  ES = MASSTOR_BETA;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        ES = MASSTOR_COMP(0, ES);
        if (IL >= B_2) break;
      }
  }
  AL = MASADOM_ADFI(D, 1);
  A1 = DIPC_DIPFMO(AL, ES);
  AP = A1;
  for (;;) {
    for (;;) {
      C = MASBIOS_CREADB();
      if (C == MASBIOS_MASORD(')')) {
        if (FL == 0) {
          MASBIOS_BKSP();
        }
        return C_112_A;
      }
      if (C == MASBIOS_MASORD(',')) {
        MASBIOS_BKSP();
        return C_112_A;
      }
      if (C == MASBIOS_MASORD('-')) {
        AP = DIPADOM_DIPNEG(AP);
      }
      if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-')) {
        C = MASBIOS_CREADB();
      }
      if (C == MASBIOS_MASORD('*')) {
        C = MASBIOS_CREADB();
      }
      MASBIOS_BKSP();
      if (MASBIOS_DIGIT(C) || C == MASBIOS_MASORD('(')) {
        AL = MASADOM_ADREAD(D);
        EL = DIPC_EPREAD();
        if (MASADOM_ADSIGN(AL) == 0) {
          AP = 0;
        } else {
          AL = MASADOM_ADEXP(AL, EL);
          AP = DIPADOM_DIPBCP(AP, AL);
        }
        goto EXIT_3;
      }
      if (MASBIOS_LETTER(C)) {
        VL = SACPOL_VREAD();
        JL = SACPOL_VLSRCH(VL, V);
        if (JL == 0) {
          DIPC_BACKUB();
          AL = MASADOM_ADREAD(D);
          if (MASADOM_ADONE(AL) == 1) {
            MASERR_ERROR(MASERR_severe, "ERROR FOUND BY DIREAD.", 22L);
            return C_112_A;
          }
          EL = DIPC_EPREAD();
          if (MASADOM_ADSIGN(AL) == 0) {
            AP = 0;
          } else {
            AL = MASADOM_ADEXP(AL, EL);
            AP = DIPADOM_DIPBCP(AP, AL);
          }
        } else {
          EL = DIPC_EPREAD();
          AP = DIPC_DIPMPV(AP, JL, EL);
        }
        goto EXIT_3;
      }
    } EXIT_3:;
    C = MASBIOS_CREADB();
    MASBIOS_BKSP();
    if (C == MASBIOS_MASORD('+') || C == MASBIOS_MASORD('-') || C == MASBIOS_MASORD(')') || C == MASBIOS_MASORD(',')) {
      C_112_A = DIPADOM_DIPSUM(C_112_A, AP);
      AP = A1;
    }
  } EXIT_2:;
}

void DIPADOM_DIWRIT
# ifdef __STDC__
(MASSTOR_LIST C_111_A, MASSTOR_LIST V)
# else
(C_111_A, V)
MASSTOR_LIST C_111_A, V;
# endif
{
  MASSTOR_LIST AL, AS, E, EL, FL, ES, LL, RL, SL, TL, VL, VS;

  if (C_111_A == 0) {
    SACLIST_AWRITE(C_111_A);
    return;
  }
  RL = DIPC_DIPNOV(C_111_A);
  if (RL == 0) {
    MASADOM_ADWRIT(DIPC_DIPLBC(C_111_A));
    return;
  }
  AS = C_111_A;
  FL = 0;
  LL = DIPC_DIPNBC(C_111_A);
  if (LL > 1) {
    MASBIOS_SWRITE("(", 1L);
  }
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
            MASBIOS_SWRITE("**", 2L);
            SACLIST_AWRITE(EL);
          }
        }
      } while (!(ES == MASSTOR_SIL));
    }
  } while (!(AS == MASSTOR_SIL));
  MASBIOS_SWRITE(" ", 1L);
  if (LL > 1) {
    MASBIOS_SWRITE(")", 1L);
  }
  return;
}

void BEGIN_DIPADOM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACPOL();
    BEGIN_DIPC();
    BEGIN_MASADOM();

  }
}
