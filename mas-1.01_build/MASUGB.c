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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_MASRN
#include "MASRN.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACSET
#include "SACSET.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPRNGB
#include "DIPRNGB.h"
#endif

#ifndef DEFINITION_MASSYM2
#include "MASSYM2.h"
#endif

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASUGB
#include "MASUGB.h"
#endif

CHAR MASUGB_rcsid [] = "$Id: MASUGB.md,v 1.2 1995/11/05 09:11:59 kredel Exp $";
CHAR MASUGB_copyright [] = "Copyright (c) 1989 - 1993 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASUGB.mi,v 1.3 1995/11/05 09:12:10 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1993 Universitaet Passau";


void MASUGB_UGBBIN
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST I, L, OPT, PAR, V;

  MASUGB_PREAD(&L, &I, &V);
  MASUGB_OPREAD(&PAR, &OPT);
  MASUGB_EXEUGB(L, I, V, PAR, OPT);
  return;
}

void MASUGB_EXEUGB
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST OPT)
# else
(L, I, V, PAR, OPT)
MASSTOR_LIST L, I, V, PAR, OPT;
# endif
{
  if (SACLIST_MEMBER(1, OPT) == 1) {
    MASUGB_LF(L, I, V, PAR, OPT);
  } else {
    if (SACLIST_MEMBER(2, OPT) == 1) {
      MASUGB_PLF(L, I, V, PAR, OPT);
    } else {
      if (SACLIST_MEMBER(3, OPT) == 1) {
        MASUGB_UGB(L, I, V, PAR, OPT);
      } else {
        if (SACLIST_MEMBER(4, OPT) == 1) {
          MASUGB_PUGB(L, I, V, PAR, OPT);
        }
      }
    }
  }
  return;
}

void MASUGB_LF
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST OPT)
# else
(L, I, V, PAR, OPT)
MASSTOR_LIST L, I, V, PAR, OPT;
# endif
{
  MASSTOR_LIST DIFALT, KALT, NEUFLF, NURLF, OLDL, P, PALT, Q, STAKK;

  MASBIOS_SWRITE("Option ... LF", 13L);
  MASBIOS_BLINES(1);
  Q = MASUGB_EXPTU(L);
  if (PAR == 8) {
    MASBIOS_SWRITE("Die Liste der Terme als ganzzahlige Tupel ist ", 46L);
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(Q);
    MASBIOS_BLINES(1);
  }
  P = MASUGB_MAKERN(Q);
  PALT = MASSTOR_SIL;
  DIFALT = MASSTOR_SIL;
  OLDL = SACLIST_LIST3(MASSTOR_SIL, MASSTOR_SIL, MASSTOR_SIL);
  KALT = MASSTOR_SIL;
  STAKK = MASUGB_PROJEC(PALT, P, DIFALT, OLDL, I, PAR);
  MASUGB_ALLELN(STAKK, L, KALT, I, PAR, &NEUFLF, &NURLF);
  if (PAR == 8) {
    MASBIOS_SWRITE("Die Linearformen sind", 21L);
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(NEUFLF);
    MASBIOS_BLINES(2);
  }
  return;
}

void MASUGB_PLF
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST OPT)
# else
(L, I, V, PAR, OPT)
MASSTOR_LIST L, I, V, PAR, OPT;
# endif
{
  MASSTOR_LIST DEG, DIFALT, IP, KALT, LFP, LFQ, NEWLF, NP, OLDL, PALT, Q, Q2;

  MASBIOS_SWRITE("Option ... PLF", 14L);
  MASBIOS_BLINES(1);
  MASUGB_SUNIT1(I);
  IP = I;
  Q = MASUGB_EXPTU(L);
  if (PAR == 8) {
    MASBIOS_SWRITE("Die Liste der Terme als ganzzahlige Tupel ist ", 46L);
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(Q);
    MASBIOS_BLINES(1);
  }
  Q = MASUGB_MAKERN(Q);
  PALT = MASSTOR_SIL;
  DIFALT = MASSTOR_SIL;
  OLDL = SACLIST_LIST3(MASSTOR_SIL, MASSTOR_SIL, MASSTOR_SIL);
  KALT = MASSTOR_SIL;
  MASUGB_PROJ(PALT, Q, DIFALT, OLDL, I, &NP, &Q2, &DEG);
  if (PAR == 8) {
    MASBIOS_SWRITE("Gradschranke dieser Dimension ist ", 34L);
    SACLIST_OWRITE(2 * DEG);
    MASBIOS_BLINES(1);
  }
  MASBIOS_SWRITE("Datei einlesen ...", 18L);
  MASBIOS_BLINES(1);
  LFQ = SACLIST_OREAD();
  if (I != 3) {
    DEG = 2 * DEG;
  }
  LFP = MASUGB_LFGET(DEG, LFQ);
  IP = IP - 1;
  if (PAR == 8) {
    SACLIST_OWRITE(MASSTOR_LENGTH(LFP));
    MASBIOS_SWRITE(" eingelesene Linearformen  ", 27L);
    MASBIOS_BLINES(1);
  }
  MASBIOS_SWRITE("Berechnung der Linearformen ... ", 32L);
  MASBIOS_BLINES(1);
  NEWLF = MASUGB_MKLF1(LFP, Q2, NP, IP);
  MASBIOS_SWRITE("Die berechneten Linearformen sind   ", 36L);
  SACLIST_OWRITE(MASSTOR_LENGTH(NEWLF));
  MASBIOS_BLINES(1);
  if (PAR == 8) {
    MASBIOS_SWRITE("Die Linearformen sind", 21L);
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(NEWLF);
    MASBIOS_BLINES(2);
  }
  return;
}

void MASUGB_UGB
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST OPT)
# else
(L, I, V, PAR, OPT)
MASSTOR_LIST L, I, V, PAR, OPT;
# endif
{
  MASSTOR_LIST DIFALT, G, GB, KALT, NEUFLF, NURLF, OLDL, P, PALT, Q, STAKK, UL;

  MASBIOS_SWRITE("Option ... UGB", 14L);
  MASBIOS_BLINES(1);
  if (I == 1) {
    G = DIPRNGB_DIRPGB(L, 0);
    MASBIOS_SWRITE("*************************************.", 38L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("es gibt nur eine zulaessige Ordnung  .", 38L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("     die Linearform ist (1)          .", 38L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("*************************************.", 38L);
    MASBIOS_BLINES(1);
    MASUGB_WRUGB(G, V);
    return;
  }
  Q = MASUGB_EXPTU(L);
  if (PAR == 8) {
    MASBIOS_SWRITE("Die Liste der Terme als ganzzahlige Tupel ist ", 46L);
    MASBIOS_BLINES(1);
    SACLIST_OWRITE(Q);
    MASBIOS_BLINES(1);
  }
  P = MASUGB_MAKERN(Q);
  PALT = MASSTOR_SIL;
  DIFALT = MASSTOR_SIL;
  OLDL = SACLIST_LIST3(MASSTOR_SIL, MASSTOR_SIL, MASSTOR_SIL);
  KALT = MASSTOR_SIL;
  STAKK = MASUGB_PROJEC(PALT, P, DIFALT, OLDL, I, PAR);
  MASUGB_LFALL(STAKK, L, KALT, I, &NEUFLF, &NURLF);
  GB = MASUGB_UG(NEUFLF, I, V, STAKK, L, NURLF, PAR);
  UL = MASUGB_WRUGF(GB, V, PAR);
  MASBIOS_BLINES(2);
  MASUGB_WRUGB(UL, V);
  return;
}

void MASUGB_PUGB
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST OPT)
# else
(L, I, V, PAR, OPT)
MASSTOR_LIST L, I, V, PAR, OPT;
# endif
{
  MASSTOR_LIST DEG, GB, LF, LFLIST, LFQ, NURLF, R, UL;

  MASBIOS_SWRITE("Option ... PUGB", 15L);
  MASBIOS_BLINES(1);
  MASUGB_SUNIT2(I);
  DEG = MASUGB_LDEG(L);
  if (PAR == 8) {
    MASBIOS_SWRITE("Grad der Polynome ... ", 22L);
    SACLIST_OWRITE(DEG);
    MASBIOS_BLINES(1);
  }
  MASBIOS_SWRITE("Lese Linearfomen ... ", 21L);
  MASBIOS_BLINES(1);
  if (I == 2) {
    SACI_IQR(DEG, 2, &DEG, &R);
    if (R != 0) {
      DEG = DEG + 1;
    }
  }
  LFQ = SACLIST_OREAD();
  LF = MASUGB_LFGET(DEG, LFQ);
  LF = MASUGB_DO1(LF);
  if (PAR == 8) {
    SACLIST_OWRITE(MASSTOR_LENGTH(LF));
    MASBIOS_SWRITE(" eingelesene Linearformen", 25L);
    MASBIOS_BLINES(1);
  }
  MASUGB_MKLIST(LF, L, &LFLIST, &NURLF);
  GB = MASUGB_PUG(LFLIST, I, V, L, DEG, NURLF, PAR, LFQ);
  UL = MASUGB_WRUGF(GB, V, PAR);
  MASBIOS_BLINES(1);
  MASUGB_WRUGB(UL, V);
  return;
}

void MASUGB_SUNIT1
# ifdef __STDC__
(MASSTOR_LIST I)
# else
(I)
MASSTOR_LIST I;
# endif
{
  MASELEM_GAMMAINT r;

  r = 0;
  if (I == 1 || I == 2) {
    MASBIOS_SWRITE("Diese Option ist ab 3 Variablen sinnvoll.", 41L);
    MASBIOS_BLINES(1);
    return;
  } else {
    if (I == 3) {
      r = MASBIOS_SIUNIT("ugblade/linform.lade1", 21L);
    } else {
      if (I == 4) {
        r = MASBIOS_SIUNIT("ugblade/linform.lade2", 21L);
      } else {
        if (I == 5) {
          r = MASBIOS_SIUNIT("ugblade/linform.lade3", 21L);
        } else {
          if (I >= 6) {
            MASBIOS_SWRITE("Anzahl der Variablen zu hoch.", 29L);
            MASBIOS_BLINES(1);
            return;
          }
        }
      }
    }
  }
  if (r != 0) {
    MASERR_ERROR(MASERR_severe, "SUNIT1: Cannot open file.", 25L);
  }
  return;
}

void MASUGB_SUNIT2
# ifdef __STDC__
(MASSTOR_LIST I)
# else
(I)
MASSTOR_LIST I;
# endif
{
  MASELEM_GAMMAINT r;

  r = 0;
  if (I == 1) {
    MASBIOS_SWRITE("Diese Option ist ab 2 Variablen sinnvoll.", 41L);
    MASBIOS_BLINES(1);
    return;
  } else {
    if (I == 2) {
      r = MASBIOS_SIUNIT("ugblade/linform.lade1", 21L);
    } else {
      if (I == 3) {
        r = MASBIOS_SIUNIT("ugblade/linform.lade2", 21L);
      } else {
        if (I == 4) {
          r = MASBIOS_SIUNIT("ugblade/linform.lade3", 21L);
        } else {
          if (I == 5) {
            r = MASBIOS_SIUNIT("ugblade/linform.lade4", 21L);
          } else {
            if (I >= 6) {
              MASBIOS_SWRITE("Anzahl der Variablen zu hoch.", 29L);
              MASBIOS_BLINES(1);
              return;
            }
          }
        }
      }
    }
  }
  if (r != 0) {
    MASERR_ERROR(MASERR_severe, "SUNIT2: Cannot open file.", 25L);
  }
  return;
}

void MASUGB_PREAD
# ifdef __STDC__
(MASSTOR_LIST *L, MASSTOR_LIST *I, MASSTOR_LIST *V)
# else
(L, I, V)
MASSTOR_LIST *L, *I, *V;
# endif
{
  *V = SACPOL_VLREAD();
  *L = DIPRN_DIRLRD(*V);
  *I = MASSTOR_LENGTH(*V);
  MASBIOS_SWRITE("Die eingegebenen Polynome sind ", 31L);
  MASBIOS_BLINES(1);
  DIPRN_DIRLWR(*L, *V, -1);
  MASBIOS_BLINES(1);
  return;
}

void MASUGB_OPREAD
# ifdef __STDC__
(MASSTOR_LIST *PAR, MASSTOR_LIST *OPT)
# else
(PAR, OPT)
MASSTOR_LIST *PAR, *OPT;
# endif
{
  *PAR = MASUGB_RDPAR();
  if (*PAR == 8) {
    MASBIOS_SWRITE("Zwischenausgaben ... JA", 23L);
    MASBIOS_BLINES(1);
  } else {
    if (*PAR == 9) {
      MASBIOS_SWRITE("Zwischenausgaben ... NEIN", 25L);
      MASBIOS_BLINES(1);
    }
  }
  *OPT = MASUGB_EXECRD();
  return;
}

MASSTOR_LIST MASUGB_EXPTU
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C_201_A, B, E, J1Y, LP, Q;

  Q = MASSTOR_SIL;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &C_201_A, &LP);
    if (C_201_A != 0) {
      while (C_201_A != MASSTOR_SIL) {
        DIPC_DIPMAD(C_201_A, &B, &E, &C_201_A);
        J1Y = MASSTOR_LIST1(E);
        Q = SACSET_USUN(J1Y, Q);
      }
    }
  }
  Q = MASSTOR_INV(Q);
  return Q;
}

MASSTOR_LIST MASUGB_MAKERN
# ifdef __STDC__
(MASSTOR_LIST Q)
# else
(Q)
MASSTOR_LIST Q;
# endif
{
  MASSTOR_LIST C_200_A, A1, B, C, L1, P, QP;

  QP = Q;
  P = MASSTOR_SIL;
  L1 = MASSTOR_SIL;
  while (QP != MASSTOR_SIL) {
    MASSTOR_ADV(QP, &C_200_A, &QP);
    A1 = MASSTOR_SIL;
    while (C_200_A != MASSTOR_SIL) {
      MASSTOR_ADV(C_200_A, &B, &C_200_A);
      C = SACRN_RNINT(B);
      A1 = MASSTOR_COMP(C, A1);
    }
    A1 = MASSTOR_INV(A1);
    L1 = MASSTOR_COMP(A1, L1);
  }
  P = MASSTOR_INV(L1);
  return P;
}

MASSTOR_LIST MASUGB_SCMULT
# ifdef __STDC__
(MASSTOR_LIST I, MASSTOR_LIST U)
# else
(I, U)
MASSTOR_LIST I, U;
# endif
{
  MASSTOR_LIST C_199_A, IP, SKTU, T, UP, V;

  UP = U;
  IP = I;
  V = MASSTOR_SIL;
  SKTU = MASSTOR_SIL;
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &C_199_A, &UP);
    T = SACRN_RNPROD(C_199_A, IP);
    V = MASSTOR_COMP(T, V);
  }
  SKTU = MASSTOR_INV(V);
  return SKTU;
}

MASSTOR_LIST MASUGB_PDIF
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S, MASSTOR_LIST DIFALT)
# else
(R, S, DIFALT)
MASSTOR_LIST R, S, DIFALT;
# endif
{
  MASSTOR_LIST B, C, C1, D, RP, SP;

  RP = R;
  SP = S;
  B = MASUGB_DIFF1(RP, SP);
  D = MASUGB_DIFF(SP);
  C1 = SACSET_USUN(B, D);
  C = SACSET_USUN(C1, DIFALT);
  return C;
}

void MASUGB_MKSET
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST *P2, MASSTOR_LIST *P3, MASSTOR_LIST *RR)
# else
(R, P2, P3, RR)
MASSTOR_LIST R;
MASSTOR_LIST *P2, *P3, *RR;
# endif
{
  MASSTOR_LIST C_198_A, B, C, EE, J1Y, P1, P1P, P2P, RP, XP;

  RP = R;
  *RR = MASSTOR_SIL;
  P1 = MASSTOR_SIL;
  *P2 = MASSTOR_SIL;
  *P3 = MASSTOR_SIL;
  while (RP != MASSTOR_SIL) {
    MASSTOR_ADV(RP, &C_198_A, &RP);
    XP = C_198_A;
    MASSTOR_ADV(C_198_A, &B, &C_198_A);
    if (MASUGB_NULRNV(C_198_A) != 1) {
      if (B == 0) {
        if (SACLIST_MEMBER(C_198_A, P1) != 1) {
          *RR = MASSTOR_COMP(XP, *RR);
          P1 = MASSTOR_COMP(C_198_A, P1);
        }
      } else {
        B = SACRN_RNINV(B);
        C = MASUGB_SCMULT(B, C_198_A);
        if (SACLIST_MEMBER(C, *P2) != 1) {
          *RR = MASSTOR_COMP(XP, *RR);
          *P2 = MASSTOR_COMP(C, *P2);
        }
      }
    }
  }
  P1P = P1;
  P2P = *P2;
  while (P1P != MASSTOR_SIL) {
    MASSTOR_ADV(P1P, &C_198_A, &P1P);
    J1Y = -1;
    J1Y = SACLIST_LIST2(J1Y, 1);
    EE = MASUGB_SCMULT(J1Y, C_198_A);
    if (SACLIST_MEMBER(EE, P2P) != 1 && SACLIST_MEMBER(C_198_A, P2P) != 1) {
      P2P = MASSTOR_COMP(C_198_A, P2P);
    }
  }
  *P3 = P2P;
  *P3 = SACLIST_CINV(*P3);
  return;
}

MASSTOR_LIST MASUGB_PROJEC
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S, MASSTOR_LIST DIFALT, MASSTOR_LIST OLDL, MASSTOR_LIST I, MASSTOR_LIST PAR)
# else
(R, S, DIFALT, OLDL, I, PAR)
MASSTOR_LIST R, S, DIFALT, OLDL, I, PAR;
# endif
{
  MASSTOR_LIST B, C, D, DEG, E, IP, M, RP, RS, SERIE, STAKK;

  MASBIOS_SWRITE("Projektionen ... ", 17L);
  MASBIOS_BLINES(1);
  RS = S;
  RP = R;
  STAKK = MASSTOR_SIL;
  SERIE = MASSTOR_SIL;
  IP = I;
  M = IP;
  while (M >= 2) {
    M = M - 1;
    if (PAR == 8) {
      MASBIOS_SWRITE("Dimension ... ", 14L);
      SACLIST_OWRITE(M);
      MASBIOS_BLINES(1);
    }
    MASUGB_EVLRNBSO(RS);
    D = MASUGB_PDIF(RP, RS, DIFALT);
    MASUGB_MKSET(D, &B, &C, &D);
    DEG = MASUGB_DEGRE(C);
    DEG = 2 * DEG;
    if (PAR == 8) {
      MASBIOS_SWRITE("Gradschranke dieser Dimension ist ", 34L);
      SACLIST_OWRITE(DEG);
      MASBIOS_BLINES(1);
    }
    E = SACLIST_LIST2(D, B);
    STAKK = MASSTOR_COMP(E, STAKK);
    RP = MASSTOR_SIL;
    RS = C;
  }
  return STAKK;
}

void MASUGB_PROJ
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S, MASSTOR_LIST DIFALT, MASSTOR_LIST OLDL, MASSTOR_LIST I, MASSTOR_LIST *D, MASSTOR_LIST *B, MASSTOR_LIST *DEG)
# else
(R, S, DIFALT, OLDL, I, D, B, DEG)
MASSTOR_LIST R, S, DIFALT, OLDL, I;
MASSTOR_LIST *D, *B, *DEG;
# endif
{
  MASSTOR_LIST C, IP, M, RP, RS, SERIE, STAKK;

  RS = S;
  RP = R;
  STAKK = MASSTOR_SIL;
  SERIE = MASSTOR_SIL;
  IP = I;
  M = IP;
  MASUGB_EVLRNBSO(RS);
  *D = MASUGB_PDIF(RP, RS, DIFALT);
  MASUGB_MKSET(*D, B, &C, D);
  *DEG = MASUGB_DEGRE(C);
  STAKK = SACLIST_COMP2(*D, *B, STAKK);
  return;
}

MASSTOR_LIST MASUGB_DIFF
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST C_197_A, AP, B, E, EE, ELT, ERG, RP, SP;

  RP = R;
  ERG = MASSTOR_SIL;
  if (RP == MASSTOR_SIL) {
    return ERG;
  }
  SP = MASSTOR_RED(R);
  ELT = MASSTOR_SIL;
  while (RP != MASSTOR_SIL) {
    MASSTOR_ADV(RP, &C_197_A, &RP);
    while (SP != MASSTOR_SIL) {
      AP = C_197_A;
      MASSTOR_ADV(SP, &B, &SP);
      E = MASUGB_RNVDIF(AP, B);
      EE = MASUGB_RNVDIF(B, AP);
      if (SACLIST_MEMBER(E, ERG) != 1 && SACLIST_MEMBER(EE, ERG) != 1) {
        ERG = MASSTOR_COMP(E, ERG);
      }
    }
    SP = MASSTOR_RED(RP);
  }
  return ERG;
}

MASSTOR_LIST MASUGB_DIFF1
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST C_196_A, AP, B, ELT, ERG, RP, SP;

  RP = R;
  SP = S;
  ELT = MASSTOR_SIL;
  ERG = MASSTOR_SIL;
  if (RP == MASSTOR_SIL || SP == MASSTOR_SIL) {
    return ERG;
  }
  while (RP != MASSTOR_SIL) {
    MASSTOR_ADV(RP, &C_196_A, &RP);
    SP = S;
    while (SP != MASSTOR_SIL) {
      AP = C_196_A;
      MASSTOR_ADV(SP, &B, &SP);
      ELT = MASUGB_RNVDIF(AP, B);
      if (SACLIST_MEMBER(ELT, ERG) != 1) {
        ERG = MASSTOR_COMP(ELT, ERG);
      }
    }
  }
  return ERG;
}

MASSTOR_LIST MASUGB_RNVDIF
# ifdef __STDC__
(MASSTOR_LIST C_195_A, MASSTOR_LIST B)
# else
(C_195_A, B)
MASSTOR_LIST C_195_A, B;
# endif
{
  MASSTOR_LIST AA, AQ, BB, BQ, C, CC;

  C = MASSTOR_SIL;
  AQ = C_195_A;
  BQ = B;
  while (AQ != MASSTOR_SIL) {
    MASSTOR_ADV(AQ, &AA, &AQ);
    MASSTOR_ADV(BQ, &BB, &BQ);
    CC = SACRN_RNDIF(AA, BB);
    C = MASSTOR_COMP(CC, C);
  }
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST MASUGB_SCPROD
# ifdef __STDC__
(MASSTOR_LIST C_194_A, MASSTOR_LIST B)
# else
(C_194_A, B)
MASSTOR_LIST C_194_A, B;
# endif
{
  MASSTOR_LIST AA, AP, BB, BP, C, CC;

  AP = C_194_A;
  BP = B;
  C = 0;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AA, &AP);
    MASSTOR_ADV(BP, &BB, &BP);
    CC = SACRN_RNPROD(AA, BB);
    C = SACRN_RNSUM(CC, C);
  }
  return C;
}

MASSTOR_LIST MASUGB_SKPRO2
# ifdef __STDC__
(MASSTOR_LIST C_193_A, MASSTOR_LIST B)
# else
(C_193_A, B)
MASSTOR_LIST C_193_A, B;
# endif
{
  MASSTOR_LIST AA, AP, BB, BP, C, CC;

  AP = C_193_A;
  BP = B;
  C = 0;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AA, &AP);
    MASSTOR_ADV(BP, &BB, &BP);
    BB = SACRN_RNINT(BB);
    CC = SACRN_RNPROD(AA, BB);
    C = SACRN_RNSUM(CC, C);
  }
  return C;
}

MASSTOR_LIST MASUGB_LRNBMS
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST B, BP, C, IL, J1Y, JL, KL, L1, L2, LP, LPP, LPPP, M, ML, NL, QL, QLP, RL, TL;

  TL = 10;
  NL = MASSTOR_LENGTH(L);
  if (NL < TL) {
    MASUGB_LRNBS(L);
    M = L;
    return M;
  }
  KL = 0;
  ML = 1;
  QL = NL;
  do {
    KL = KL + 1;
    ML = ML + ML;
    QL = QL / 2;
  } while (!(QL < TL));
  J1Y = ML * QL;
  RL = NL - J1Y;
  B = MASSTOR_SIL;
  LP = L;
  {
    LONGINT B_1 = 1, B_2 = ML;

    if (B_1 <= B_2)
      for (IL = B_1;; IL += 1) {
        if (IL <= RL) {
          QLP = QL;
        } else {
          QLP = QL - 1;
        }
        LPP = LP;
        {
          LONGINT B_3 = 1, B_4 = QLP;

          if (B_3 <= B_4)
            for (JL = B_3;; JL += 1) {
              LPP = MASSTOR_RED(LPP);
              if (JL >= B_4) break;
            }
        }
        LPPP = MASSTOR_RED(LPP);
        MASSTOR_SRED(LPP, MASSTOR_SIL);
        MASUGB_LRNBS(LP);
        B = MASSTOR_COMP(LP, B);
        LP = LPPP;
        if (IL >= B_2) break;
      }
  }
  {
    LONGINT B_5 = 1, B_6 = KL;

    if (B_5 <= B_6)
      for (IL = B_5;; IL += 1) {
        C = MASSTOR_SIL;
        BP = B;
        do {
          SACLIST_ADV2(BP, &L1, &L2, &BP);
          L1 = MASUGB_LRNM(L1, L2);
          C = MASSTOR_COMP(L1, C);
        } while (!(BP == MASSTOR_SIL));
        B = C;
        if (IL >= B_6) break;
      }
  }
  M = MASSTOR_FIRST(B);
  return M;
}

void MASUGB_LRNBS
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST ALP, ALPP, LP, LPP, M, MP;

  if (L == MASSTOR_SIL) {
    return;
  }
  M = MASSTOR_SIL;
  do {
    LP = L;
    LPP = MASSTOR_RED(LP);
    ALP = MASSTOR_FIRST(LP);
    MP = MASSTOR_SIL;
    while (LPP != M) {
      ALPP = MASSTOR_FIRST(LPP);
      if (SACRN_RNCOMP(ALP, ALPP) > 0) {
        MASSTOR_SFIRST(LP, ALPP);
        MASSTOR_SFIRST(LPP, ALP);
        MP = LPP;
      } else {
        ALP = ALPP;
      }
      LP = LPP;
      LPP = MASSTOR_RED(LP);
    }
    M = MP;
  } while (!(M == MASSTOR_SIL));
  return;
}

MASSTOR_LIST MASUGB_LRNM
# ifdef __STDC__
(MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(L1, L2)
MASSTOR_LIST L1, L2;
# endif
{
  MASSTOR_LIST AL1, AL2, L, LP, LS, LP1, LP2, LPP1, LPP2;

  LP1 = L1;
  LP2 = L2;
  L = MASSTOR_SIL;
  LS = MASSTOR_SIL;
  while (LP1 != MASSTOR_SIL && LP2 != MASSTOR_SIL) {
    MASSTOR_ADV(LP1, &AL1, &LPP1);
    MASSTOR_ADV(LP2, &AL2, &LPP2);
    if (SACRN_RNCOMP(AL1, AL2) < 0) {
      LP = LP1;
      LP1 = LPP1;
    } else {
      LP = LP2;
      LP2 = LPP2;
    }
    if (LS == MASSTOR_SIL) {
      LS = LP;
      L = LP;
    } else {
      MASSTOR_SRED(LS, LP);
      LS = LP;
    }
  }
  if (LP2 != MASSTOR_SIL) {
    LP1 = LP2;
  }
  if (LS == MASSTOR_SIL) {
    L = LP;
  } else {
    MASSTOR_SRED(LS, LP1);
  }
  return L;
}

void MASUGB_COMPLF
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST D, MASSTOR_LIST KLIST, MASSTOR_LIST NP, MASSTOR_LIST JP, MASSTOR_LIST M, MASSTOR_LIST *LFORM, MASSTOR_LIST *KLISTP, MASSTOR_LIST *J)
# else
(C, D, KLIST, NP, JP, M, LFORM, KLISTP, J)
MASSTOR_LIST C, D, KLIST, NP, JP, M;
MASSTOR_LIST *LFORM, *KLISTP, *J;
# endif
{
  MASSTOR_LIST C_192_A, DP, K, KALT, KLISTH, U;

  DP = D;
  *LFORM = MASSTOR_SIL;
  *J = JP;
  *KLISTP = KLIST;
  KALT = MASSTOR_SIL;
  KLISTH = MASSTOR_SIL;
  while (DP != MASSTOR_SIL) {
    MASSTOR_ADV(DP, &C_192_A, &DP);
    if (M != 1) {
      C_192_A = MASSTOR_COMP(C_192_A, C);
      K = MASUGB_PKEGEL(C_192_A, NP, KALT);
      U = MASUGB_COMPA1(K, *KLISTP);
      if (U != 1) {
        KLISTH = MASSTOR_COMP(K, KLISTH);
        *LFORM = MASSTOR_COMP(C_192_A, *LFORM);
      }
    } else {
      C_192_A = MASSTOR_LIST1(C_192_A);
      *LFORM = MASSTOR_COMP(C_192_A, *LFORM);
    }
  }
  *KLISTP = SACLIST_CCONC(*KLISTP, KLISTH);
  return;
}

MASSTOR_LIST MASUGB_CQ2
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST Q2, MASSTOR_LIST M)
# else
(C, Q2, M)
MASSTOR_LIST C, Q2, M;
# endif
{
  MASSTOR_LIST C_191_A, AA, CP, J1Y, Q2P, TR;

  CP = C;
  Q2P = Q2;
  TR = MASSTOR_SIL;
  while (Q2P != MASSTOR_SIL) {
    MASSTOR_ADV(Q2P, &C_191_A, &Q2P);
    if (M != 1) {
      AA = MASUGB_SCPROD(C, C_191_A);
      J1Y = MASUGB_LASTEL(C_191_A);
      AA = SACRN_RNSUM(AA, J1Y);
    } else {
      AA = MASSTOR_FIRST(C_191_A);
    }
    if (SACRN_RNCOMP(AA, 0) <= -1 && SACLIST_MEMBER(AA, TR) != 1) {
      TR = MASSTOR_COMP(AA, TR);
    }
  }
  return TR;
}

MASSTOR_LIST MASUGB_RNVABS
# ifdef __STDC__
(MASSTOR_LIST C_190_A)
# else
(C_190_A)
MASSTOR_LIST C_190_A;
# endif
{
  MASSTOR_LIST AA, AP, B;

  AP = C_190_A;
  B = MASSTOR_SIL;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AA, &AP);
    AA = SACRN_RNABS(AA);
    B = MASSTOR_COMP(AA, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST MASUGB_CUT
# ifdef __STDC__
(MASSTOR_LIST TR)
# else
(TR)
MASSTOR_LIST TR;
# endif
{
  MASSTOR_LIST C_189_A, B, D, ERST, G, H, J, J1Y, J2Y, MITTE, ND, TRACEP, Z;

  TRACEP = TR;
  D = MASSTOR_SIL;
  G = MASSTOR_FIRST(TRACEP);
  J1Y = SACRN_RNINT(0);
  H = SACRN_RNSUM(G, J1Y);
  J = SACLIST_LAST(TRACEP);
  J = MASSTOR_FIRST(J);
  J1Y = SACRN_RNINT(2);
  ERST = SACRN_RNQ(H, J1Y);
  J1Y = SACRN_RNINT(1);
  ND = SACRN_RNSUM(J, J1Y);
  D = MASSTOR_COMP(ERST, D);
  Z = MASSTOR_LENGTH(TRACEP);
  while (Z >= 2) {
    C_189_A = MASSTOR_FIRST(TRACEP);
    B = SACLIST_SECOND(TRACEP);
    TRACEP = MASSTOR_RED(TRACEP);
    Z = MASSTOR_LENGTH(TRACEP);
    J1Y = SACRN_RNSUM(C_189_A, B);
    J2Y = SACRN_RNINT(2);
    MITTE = SACRN_RNQ(J1Y, J2Y);
    D = MASSTOR_COMP(MITTE, D);
  }
  D = MASSTOR_COMP(ND, D);
  return D;
}

void MASUGB_ALLELN
# ifdef __STDC__
(MASSTOR_LIST STAKK, MASSTOR_LIST L, MASSTOR_LIST KALT, MASSTOR_LIST I, MASSTOR_LIST PAR, MASSTOR_LIST *LF, MASSTOR_LIST *NURLF)
# else
(STAKK, L, KALT, I, PAR, LF, NURLF)
MASSTOR_LIST STAKK, L, KALT, I, PAR;
MASSTOR_LIST *LF, *NURLF;
# endif
{
  MASSTOR_LIST C_188_A, IP, J1Y, LFX, LY, M, N, NEWLF, Q2, STAKKP;

  MASBIOS_SWRITE("Rekursive Berechnung der Linearformen ... ", 42L);
  MASBIOS_BLINES(1);
  STAKKP = STAKK;
  M = 1;
  IP = I;
  J1Y = SACRN_RNINT(1);
  LFX = MASSTOR_LIST1(J1Y);
  LY = MASSTOR_SIL;
  *LF = MASSTOR_LIST1(LFX);
  IP = IP - 1;
  NEWLF = MASSTOR_SIL;
  while (M <= IP) {
    MASSTOR_ADV(STAKKP, &C_188_A, &STAKKP);
    N = MASSTOR_FIRST(C_188_A);
    Q2 = SACLIST_SECOND(C_188_A);
    if (PAR == 8) {
      MASBIOS_SWRITE("Dimension ...", 13L);
      SACLIST_OWRITE(M + 1);
      MASBIOS_BLINES(1);
      MASBIOS_SWRITE("Die Spur hat ", 13L);
      SACLIST_OWRITE(MASSTOR_LENGTH(N));
      MASBIOS_SWRITE(" Elemente", 9L);
      MASBIOS_BLINES(1);
    }
    *NURLF = MASUGB_MKLF1(*LF, Q2, N, M);
    if (PAR == 8 && M != IP) {
      MASBIOS_SWRITE("Die bisher rekursiv berechneten Linearformen sind ", 50L);
      SACLIST_OWRITE(MASSTOR_LENGTH(*NURLF));
      MASBIOS_SWRITE(" Linearformen  ", 15L);
      MASBIOS_BLINES(1);
    }
    M = M + 1;
    *LF = *NURLF;
  }
  MASBIOS_SWRITE("Die berechneten Linearformen sind ", 34L);
  SACLIST_OWRITE(MASSTOR_LENGTH(*LF));
  MASBIOS_SWRITE(" Linearformen  ", 15L);
  MASBIOS_BLINES(1);
  return;
}

MASSTOR_LIST MASUGB_MKLF1
# ifdef __STDC__
(MASSTOR_LIST LFP, MASSTOR_LIST Q2, MASSTOR_LIST NP, MASSTOR_LIST M)
# else
(LFP, Q2, NP, M)
MASSTOR_LIST LFP, Q2, NP, M;
# endif
{
  MASSTOR_LIST C_187_A, B, D, J, J1Y, KLIST, LF, NEWLF, TR;

  LF = LFP;
  NEWLF = MASSTOR_SIL;
  KLIST = MASSTOR_SIL;
  J = 0;
  while (LF != MASSTOR_SIL) {
    D = MASSTOR_SIL;
    MASSTOR_ADV(LF, &B, &LF);
    if (Q2 == MASSTOR_SIL) {
      J1Y = SACLIST_LIST2(1, 1);
      D = MASSTOR_LIST1(J1Y);
    } else {
      TR = MASUGB_CQ2(B, Q2, M);
      TR = MASUGB_RNVABS(TR);
      TR = MASUGB_LRNBMS(TR);
      D = MASUGB_CUT(TR);
    }
    MASUGB_COMPLF(B, D, KLIST, NP, J, M, &C_187_A, &KLIST, &J);
    NEWLF = SACSET_USUN(C_187_A, NEWLF);
  }
  return NEWLF;
}

MASSTOR_LIST MASUGB_NULRNV
# ifdef __STDC__
(MASSTOR_LIST C_186_A)
# else
(C_186_A)
MASSTOR_LIST C_186_A;
# endif
{
  MASSTOR_LIST AP, B, I;

  AP = C_186_A;
  I = 1;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &B, &AP);
    if (B != 0) {
      I = 0;
      return I;
    }
  }
  return I;
}

MASSTOR_LIST MASUGB_PKEGEL
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST N, MASSTOR_LIST KALT)
# else
(C, N, KALT)
MASSTOR_LIST C, N, KALT;
# endif
{
  MASSTOR_LIST C_185_A, AA, B, B2, D, I, J1Y, K, NP;

  C_185_A = KALT;
  NP = N;
  K = MASSTOR_SIL;
  I = 0;
  B = 0;
  B2 = MASSTOR_BETA / 2;
  while (NP != MASSTOR_SIL) {
    MASSTOR_ADV(NP, &AA, &NP);
    D = MASUGB_SCPROD(C, AA);
    J1Y = MASUGB_LASTEL(AA);
    D = SACRN_RNSUM(D, J1Y);
    D = SACRN_RNSIGN(D);
    if (D == -1) {
      D = 0;
    }
    J1Y = 2 * B;
    B = J1Y + D;
    if (B >= B2) {
      K = MASSTOR_COMP(B, K);
      B = 0;
    }
  }
  if (B < B2) {
    K = MASSTOR_COMP(B, K);
  }
  return K;
}

MASSTOR_LIST MASUGB_COMPA1
# ifdef __STDC__
(MASSTOR_LIST K, MASSTOR_LIST KLIST)
# else
(K, KLIST)
MASSTOR_LIST K, KLIST;
# endif
{
  MASSTOR_LIST C_184_A, J, KLISTP;

  KLISTP = KLIST;
  J = 0;
  if (KLISTP == MASSTOR_SIL) {
    J = 0;
  } else {
    while (KLISTP != MASSTOR_SIL) {
      MASSTOR_ADV(KLISTP, &C_184_A, &KLISTP);
      J = MASUGB_COMPA2(K, C_184_A);
      if (J == 1) {
        return J;
      }
    }
  }
  return J;
}

MASSTOR_LIST MASUGB_COMPA2
# ifdef __STDC__
(MASSTOR_LIST K, MASSTOR_LIST C_183_A)
# else
(K, C_183_A)
MASSTOR_LIST K, C_183_A;
# endif
{
  MASSTOR_LIST AP, B, C, KP, U;

  KP = K;
  U = 1;
  AP = C_183_A;
  U = 1;
  while (KP != MASSTOR_SIL && AP != MASSTOR_SIL) {
    MASSTOR_ADV(KP, &B, &KP);
    MASSTOR_ADV(AP, &C, &AP);
    if (B != C) {
      U = 0;
      return U;
    }
  }
  if (KP != MASSTOR_SIL || AP != MASSTOR_SIL) {
    U = 0;
  }
  return U;
}

MASSTOR_LIST MASUGB_LASTEL
# ifdef __STDC__
(MASSTOR_LIST Y)
# else
(Y)
MASSTOR_LIST Y;
# endif
{
  MASSTOR_LIST X, YP;

  YP = SACLIST_LAST(Y);
  X = MASSTOR_FIRST(YP);
  return X;
}

void MASUGB_EVLRNBSO
# ifdef __STDC__
(MASSTOR_LIST C_182_A)
# else
(C_182_A)
MASSTOR_LIST C_182_A;
# endif
{
  MASSTOR_LIST AP, APP, B, BP, ELP, ELPP, TL, DUMMY, evo;

  if (C_182_A == 0) {
    return;
  }
  evo = DIPC_EVORD;
  DIPC_EVORD = DIPC_GRLEX;
  B = MASSTOR_SIL;
  do {
    AP = C_182_A;
    MASSTOR_ADV(AP, &ELP, &APP);
    BP = MASSTOR_SIL;
    while (APP != B) {
      MASSTOR_ADV(APP, &ELPP, &DUMMY);
      TL = MASUGB_EVRNC(ELP, ELPP);
      if (TL == 0) {
        MASERR_ERROR(MASERR_severe, "RNLBSO: To equal exponent vectors", 33L);
        DIPC_EVORD = evo;
        return;
      }
      if (TL > 0) {
        MASSTOR_SFIRST(AP, ELPP);
        MASSTOR_SFIRST(APP, ELP);
        BP = APP;
      } else {
        ELP = ELPP;
      }
      AP = APP;
      APP = MASSTOR_RED(AP);
    }
    B = BP;
  } while (!(B == MASSTOR_SIL));
  DIPC_EVORD = evo;
  return;
}

MASSTOR_LIST MASUGB_EVRNGL
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST SL, TL, UL, ULP, US, VL, VLP, VS;

  TL = 0;
  US = U;
  VS = V;
  for (;;) {
    if (US == MASSTOR_SIL) {
      goto EXIT_1;
    }
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    SL = SACRN_RNCOMP(UL, VL);
    if (SL > 0) {
      TL = 1;
      goto EXIT_1;
    } else {
      if (SL < 0) {
        TL = -1;
        goto EXIT_1;
      }
    }
  } EXIT_1:;
  if (TL == 0) {
    return TL;
  }
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &ULP, &US);
    MASSTOR_ADV(VS, &VLP, &VS);
    UL = SACRN_RNSUM(UL, ULP);
    VL = SACRN_RNSUM(VL, VLP);
  }
  SL = SACRN_RNCOMP(UL, VL);
  if (SL != 0) {
    TL = SL;
  }
  return TL;
}

MASSTOR_LIST MASUGB_EVRNC
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL;

  switch (DIPC_EVORD) {
  case DIPC_GRLEX:;
    TL = MASUGB_EVRNGL(U, V);
    TL = -TL;
    break;
  case DIPC_IGRLEX:;
    TL = MASUGB_EVRNGL(U, V);
    break;
  }
  return TL;
}

MASSTOR_LIST MASUGB_DEGRE
# ifdef __STDC__
(MASSTOR_LIST Q)
# else
(Q)
MASSTOR_LIST Q;
# endif
{
  MASSTOR_LIST C_181_A, B, D, D1, H, J1Y, Q1, Q1P, QP, T;

  D = 0;
  QP = Q;
  while (QP != MASSTOR_SIL) {
    H = 1;
    MASSTOR_ADV(QP, &Q1, &QP);
    Q1P = Q1;
    while (Q1 != MASSTOR_SIL) {
      MASSTOR_ADV(Q1, &C_181_A, &Q1);
      if (C_181_A != 0) {
        J1Y = SACLIST_SECOND(C_181_A);
        H = SACI_ILCM(H, J1Y);
      }
    }
    H = SACRN_RNINT(H);
    D1 = 0;
    while (Q1P != MASSTOR_SIL) {
      MASSTOR_ADV(Q1P, &B, &Q1P);
      T = SACRN_RNPROD(B, H);
      T = SACRN_RNABS(T);
      D1 = SACRN_RNSUM(T, D1);
    }
    D = MASRN_RNMAX(D1, D);
  }
  if (D != 0) {
    D = MASSTOR_FIRST(D);
  }
  return D;
}

MASSTOR_LIST MASUGB_RDPAR
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST PAR;

  PAR = MASBIOS_CREADB();
  if (PAR == MASBIOS_MASORD('Y')) {
    PAR = 8;
  } else {
    if (PAR == MASBIOS_MASORD('N')) {
      PAR = 9;
    } else {
      MASBIOS_SWRITE("***  Fehler bei Parameterangabe", 31L);
      MASBIOS_BLINES(1);
      MASBIOS_SWRITE("***  Bitte nur Y oder N angeben", 31L);
      MASBIOS_BLINES(1);
      PAR = 9;
    }
  }
  return PAR;
}

MASSTOR_LIST MASUGB_EXECRD
# ifdef __STDC__
()
# else
()
# endif
{
  MASSTOR_LIST C_180_A, C, NP, NR, NRLIST, S;

  C = MASBIOS_CREADB();
  if (C != MASBIOS_MASORD('.')) {
    MASERR_ERROR(MASERR_severe, "EXECRD: . expected.", 19L);
    return NRLIST;
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
          C_180_A = MASSYM2_SREAD1();
          MASUGB_SEENR(C_180_A, &NR);
          if (NR != MASSTOR_SIL) {
            NRLIST = MASSTOR_COMP(NR, NRLIST);
          }
        }
      } while (!(C == MASBIOS_MASORD('.')));
    } else {
      MASERR_ERROR(MASERR_severe, "EXECRD: EXEC expected.", 22L);
      return NRLIST;
    }
  }
  if (NRLIST == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "EXECRD: no options found.", 25L);
  }
  return NRLIST;
}

void MASUGB_SEENR
# ifdef __STDC__
(MASSTOR_LIST AC, MASSTOR_LIST *NR)
# else
(AC, NR)
MASSTOR_LIST AC;
MASSTOR_LIST *NR;
# endif
{
  MASSTOR_LIST NM;

  NM = MASBIOS_LISTS("LF", 2L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 1;
    return;
  }
  NM = MASBIOS_LISTS("PLF", 3L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 2;
    return;
  }
  NM = MASBIOS_LISTS("UGB", 3L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 3;
    return;
  }
  NM = MASBIOS_LISTS("PUGB", 4L);
  if (SACLIST_EQUAL(AC, NM) == 1) {
    *NR = 4;
    return;
  }
  MASERR_ERROR(MASERR_severe, "SEENR: unknown option.", 22L);
  return;
}

MASSTOR_LIST MASUGB_LFGET
# ifdef __STDC__
(MASSTOR_LIST DEG, MASSTOR_LIST LF)
# else
(DEG, LF)
MASSTOR_LIST DEG, LF;
# endif
{
  MASSTOR_LIST D, LFP, LFQ;

  LFP = LF;
  D = 0;
  if (DEG > MASSTOR_LENGTH(LF)) {
    MASBIOS_SWRITE("******************************", 30L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE(" Berechnung nicht Fortsetzbar ", 30L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("        Grad zu hoch          ", 30L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("******************************", 30L);
    MASBIOS_BLINES(1);
    return MASSTOR_SIL;
  }
  while (D < DEG) {
    MASSTOR_ADV(LFP, &LFQ, &LFP);
    D = D + 1;
  }
  return LFQ;
}

void MASUGB_MKLF2
# ifdef __STDC__
(MASSTOR_LIST LFP, MASSTOR_LIST Q2, MASSTOR_LIST NP, MASSTOR_LIST M, MASSTOR_LIST L, MASSTOR_LIST *NEWLF, MASSTOR_LIST *LISTLF)
# else
(LFP, Q2, NP, M, L, NEWLF, LISTLF)
MASSTOR_LIST LFP, Q2, NP, M, L;
MASSTOR_LIST *NEWLF, *LISTLF;
# endif
{
  MASSTOR_LIST C_179_A, AA, B, D, J, J1Y, KLIST, LF, TR;

  LF = LFP;
  *NEWLF = MASSTOR_SIL;
  KLIST = MASSTOR_SIL;
  J = 0;
  *LISTLF = MASSTOR_SIL;
  while (LF != MASSTOR_SIL) {
    D = MASSTOR_SIL;
    MASSTOR_ADV(LF, &B, &LF);
    if (Q2 == MASSTOR_SIL) {
      J1Y = SACLIST_LIST2(1, 1);
      D = MASSTOR_LIST1(J1Y);
    } else {
      TR = MASUGB_CP2(B, Q2);
      TR = MASUGB_RNVABS(TR);
      TR = MASUGB_LRNBMS(TR);
      D = MASUGB_CUT(TR);
    }
    MASUGB_CLF2(B, D, KLIST, NP, J, M, L, &C_179_A, &KLIST, &J, &AA);
    *NEWLF = SACSET_USUN(C_179_A, *NEWLF);
    *LISTLF = SACSET_USUN(AA, *LISTLF);
  }
  return;
}

void MASUGB_CLF2
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST D, MASSTOR_LIST KLIST, MASSTOR_LIST NP, MASSTOR_LIST JP, MASSTOR_LIST M, MASSTOR_LIST L, MASSTOR_LIST *LFORM, MASSTOR_LIST *KLISTP, MASSTOR_LIST *J, MASSTOR_LIST *RECLF)
# else
(C, D, KLIST, NP, JP, M, L, LFORM, KLISTP, J, RECLF)
MASSTOR_LIST C, D, KLIST, NP, JP, M, L;
MASSTOR_LIST *LFORM, *KLISTP, *J, *RECLF;
# endif
{
  MASSTOR_LIST C_178_A, DP, J1Y, K, KALT, KLISTH, U;

  DP = D;
  *LFORM = MASSTOR_SIL;
  *J = JP;
  *KLISTP = KLIST;
  KALT = MASSTOR_SIL;
  KLISTH = MASSTOR_SIL;
  *RECLF = MASSTOR_SIL;
  while (DP != MASSTOR_SIL) {
    MASSTOR_ADV(DP, &C_178_A, &DP);
    C_178_A = MASSTOR_COMP(C_178_A, C);
    K = MASUGB_CSPUR(C_178_A, NP, KALT);
    if (M != 1) {
      U = MASUGB_COMPA1(K, *KLISTP);
      if (U != 1) {
        KLISTH = MASSTOR_COMP(K, KLISTH);
        J1Y = SACLIST_LIST4(C_178_A, L, K, NP);
        *RECLF = MASSTOR_COMP(J1Y, *RECLF);
        *LFORM = MASSTOR_COMP(C_178_A, *LFORM);
      }
    } else {
      *LFORM = MASSTOR_COMP(C_178_A, *LFORM);
      J1Y = SACLIST_LIST4(C_178_A, L, K, NP);
      *RECLF = MASSTOR_COMP(J1Y, *RECLF);
    }
  }
  *KLISTP = SACLIST_CCONC(*KLISTP, KLISTH);
  return;
}

MASSTOR_LIST MASUGB_CP2
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST Q2)
# else
(C, Q2)
MASSTOR_LIST C, Q2;
# endif
{
  MASSTOR_LIST C_177_A, AA, CP, Q2P, TR;

  CP = C;
  Q2P = Q2;
  TR = MASSTOR_SIL;
  while (Q2P != MASSTOR_SIL) {
    MASSTOR_ADV(Q2P, &C_177_A, &Q2P);
    AA = MASUGB_SCPROD(C, C_177_A);
    if (SACRN_RNCOMP(AA, 0) <= -1 && SACLIST_MEMBER(AA, TR) != 1) {
      TR = MASSTOR_COMP(AA, TR);
    }
  }
  return TR;
}

MASSTOR_LIST MASUGB_CSPUR
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST N, MASSTOR_LIST KALT)
# else
(C, N, KALT)
MASSTOR_LIST C, N, KALT;
# endif
{
  MASSTOR_LIST C_176_A, AA, B, B2, D, I, J1Y, K, NP;

  C_176_A = KALT;
  NP = N;
  K = MASSTOR_SIL;
  I = 0;
  B = 0;
  B2 = MASSTOR_SIL / 2;
  while (NP != MASSTOR_SIL) {
    MASSTOR_ADV(NP, &AA, &NP);
    D = MASUGB_SCPROD(C, AA);
    D = SACRN_RNSIGN(D);
    if (D == -1) {
      D = 0;
    }
    J1Y = 2 * B;
    B = J1Y + D;
    if (B >= B2) {
      K = MASSTOR_COMP(B, K);
      B = 0;
    }
  }
  if (B < B2) {
    K = MASSTOR_COMP(B, K);
  }
  return K;
}

MASSTOR_LIST MASUGB_MKNEWP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST POL, MASSTOR_LIST PRS)
# else
(P, POL, PRS)
MASSTOR_LIST P, POL, PRS;
# endif
{
  MASSTOR_LIST C, COL1, COL2, DL, EL, ELI, ELJ, PAIRS, PLI, PP, PPAIRS, SL;

  PP = P;
  PPAIRS = MASSTOR_SIL;
  PAIRS = PRS;
  COL1 = POL;
  ELI = DIPC_DIPEVL(COL1);
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PLI, &PP);
    COL2 = PLI;
    ELJ = DIPC_DIPEVL(COL2);
    EL = DIPC_EVLCM(ELI, ELJ);
    SL = DIPC_EVSUM(ELI, ELJ);
    C = SACLIST_EQUAL(EL, SL);
    if (C != 1) {
      DL = SACLIST_LIST3(EL, POL, PLI);
      PPAIRS = MASSTOR_COMP(DL, PPAIRS);
    }
  }
  PPAIRS = DIPRNGB_EVPLSO(PPAIRS);
  if (PAIRS != MASSTOR_SIL) {
    PAIRS = MASSTOR_INV(SACLIST_CINV(PAIRS));
    PPAIRS = DIPRNGB_EVPLM(PAIRS, PPAIRS);
  }
  return PPAIRS;
}

void MASUGB_MKPAIR
# ifdef __STDC__
(MASSTOR_LIST PP, MASSTOR_LIST *PAIRS)
# else
(PP, PAIRS)
MASSTOR_LIST PP;
MASSTOR_LIST *PAIRS;
# endif
{
  MASSTOR_LIST C, COL1, COL2, DL, EL, ELI, ELJ, PI, PJ, PSS, Q, QP, SL;

  *PAIRS = MASSTOR_SIL;
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return;
  }
  PSS = PP;
  do {
    MASSTOR_ADV(PSS, &PI, &QP);
    COL1 = PI;
    ELI = DIPC_DIPEVL(COL1);
    while (QP != MASSTOR_SIL) {
      MASSTOR_ADV(QP, &PJ, &QP);
      COL2 = PJ;
      ELJ = DIPC_DIPEVL(COL2);
      EL = DIPC_EVLCM(ELI, ELJ);
      SL = DIPC_EVSUM(ELI, ELJ);
      C = SACLIST_EQUAL(EL, SL);
      if (C != 1) {
        DL = SACLIST_LIST3(EL, PI, PJ);
        *PAIRS = MASSTOR_COMP(DL, *PAIRS);
        Q = MASSTOR_COMP(PJ, Q);
      }
    }
    PSS = MASSTOR_RED(PSS);
  } while (!(PSS == MASSTOR_SIL));
  if (*PAIRS != MASSTOR_SIL) {
    *PAIRS = DIPRNGB_EVPLSO(*PAIRS);
  }
  return;
}

void MASUGB_MKSP1
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST L, MASSTOR_LIST PAIRS, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST *D, MASSTOR_LIST *PAIRSP)
# else
(X, L, PAIRS, I, V, D, PAIRSP)
MASSTOR_LIST X, L, PAIRS, I, V;
MASSTOR_LIST *D, *PAIRSP;
# endif
{
  MASSTOR_LIST B, B1, B2, B3, C;

  *PAIRSP = PAIRS;
  *D = 0;
  while (*PAIRSP != MASSTOR_SIL && *D == 0) {
    MASSTOR_ADV(*PAIRSP, &B, PAIRSP);
    SACLIST_FIRST2(MASSTOR_RED(B), &B2, &B3);
    C = MASUGB_DIRPSP(B2, B3, X);
    *D = MASUGB_DIRRNF(L, C, X, V);
  }
  return;
}

MASSTOR_LIST MASUGB_GS1
# ifdef __STDC__
(MASSTOR_LIST LF, MASSTOR_LIST V, MASSTOR_LIST PAR)
# else
(LF, V, PAR)
MASSTOR_LIST LF, V, PAR;
# endif
{
  MASSTOR_LIST C_175_A, B, J1Y, J2Y, LFP, LP, PAIRS, STAK, X, evo;

  LFP = LF;
  STAK = MASSTOR_SIL;
  evo = DIPC_EVORD;
  if (PAR == 8) {
    MASBIOS_SWRITE("Ordne die Polynome nach den Linearformen", 40L);
    MASBIOS_BLINES(1);
  }
  while (LFP != MASSTOR_SIL) {
    MASSTOR_ADV(LFP, &C_175_A, &LFP);
    SACLIST_FIRST2(C_175_A, &B, &LP);
    DIPC_EVORD = B;
    LP = MASUGB_POLCOP(LP);
    DIPC_DILBSO(LP);
    MASUGB_MKPAIR(LP, &PAIRS);
    J1Y = SACLIST_THIRD(C_175_A);
    J2Y = SACLIST_FOURTH(C_175_A);
    X = SACLIST_LIST5(B, LP, J1Y, J2Y, PAIRS);
    J1Y = MASSTOR_LIST1(X);
    STAK = SACSET_USUN(J1Y, STAK);
  }
  DIPC_EVORD = evo;
  return STAK;
}

MASSTOR_LIST MASUGB_MERGE
# ifdef __STDC__
(MASSTOR_LIST STALT, MASSTOR_LIST STNEU)
# else
(STALT, STNEU)
MASSTOR_LIST STALT, STNEU;
# endif
{
  MASSTOR_LIST C_174_A, B, C, D, J1Y, J2Y, STAK, STALTP, STNEUP;

  STALTP = STALT;
  STNEUP = STNEU;
  STAK = MASSTOR_SIL;
  while (STALTP != MASSTOR_SIL) {
    MASSTOR_ADV(STALTP, &C_174_A, &STALTP);
    MASSTOR_ADV(STNEUP, &B, &STNEUP);
    J1Y = MASSTOR_FIRST(C_174_A);
    J2Y = MASSTOR_FIRST(B);
    D = SACSET_USUN(J1Y, J2Y);
    J1Y = SACLIST_SECOND(C_174_A);
    J2Y = SACLIST_SECOND(B);
    C = SACSET_USUN(J1Y, J2Y);
    J1Y = SACLIST_LIST2(D, C);
    STAK = MASSTOR_COMP(J1Y, STAK);
    STAK = MASSTOR_INV(STAK);
  }
  return STAK;
}

MASSTOR_LIST MASUGB_WRUGF
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST V, MASSTOR_LIST PAR)
# else
(X, V, PAR)
MASSTOR_LIST X, V, PAR;
# endif
{
  MASSTOR_LIST evo, C_173_A, L, LP, p, UL, XP;

  XP = X;
  UL = MASSTOR_SIL;
  if (PAR == 8) {
    MASBIOS_SWRITE("        ************************************", 44L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("             Universelle Groebnerfamilie", 40L);
    MASBIOS_BLINES(1);
    MASBIOS_SWRITE("        ************************************", 44L);
    MASBIOS_BLINES(2);
  }
  evo = DIPC_EVORD;
  DIPC_EVORD = DIPC_INVLEX;
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &C_173_A, &XP);
    if (PAR == 8) {
      MASBIOS_SWRITE("-----------------------------", 29L);
      MASBIOS_BLINES(1);
      SACLIST_OWRITE(MASSTOR_FIRST(C_173_A));
      MASBIOS_BLINES(1);
      MASBIOS_SWRITE("-----------------------------", 29L);
      MASBIOS_BLINES(1);
      DIPRN_DIRLWR(SACLIST_SECOND(C_173_A), V, -1);
      MASBIOS_BLINES(1);
    }
    L = SACLIST_SECOND(C_173_A);
    L = MASUGB_POLCOP(L);
    DIPC_DILBSO(L);
    LP = L;
    while (LP != MASSTOR_SIL) {
      p = DIPRN_DIRPMC(MASSTOR_FIRST(LP));
      MASSTOR_SFIRST(LP, p);
      LP = MASSTOR_RED(LP);
    }
    UL = SACSET_USUN(L, UL);
  }
  UL = DIPC_DIPLPM(UL);
  DIPC_EVORD = evo;
  return UL;
}

void MASUGB_WRUGB
# ifdef __STDC__
(MASSTOR_LIST UL, MASSTOR_LIST V)
# else
(UL, V)
MASSTOR_LIST UL, V;
# endif
{
  MASBIOS_SWRITE("       ************************************", 43L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("              Universelle Groebnerbasis", 39L);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("       ************************************", 43L);
  MASBIOS_BLINES(1);
  DIPRN_DIRLWR(UL, V, -1);
  return;
}

MASSTOR_LIST MASUGB_POLCOP
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST C_172_A, B, J1Y, LP, P;

  LP = L;
  P = MASSTOR_SIL;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &C_172_A, &LP);
    B = MASSTOR_INV(SACLIST_CINV(C_172_A));
    P = MASSTOR_COMP(B, P);
  }
  P = MASSTOR_INV(P);
  return P;
}

MASSTOR_LIST MASUGB_DFP
# ifdef __STDC__
(MASSTOR_LIST C_171_A, MASSTOR_LIST B)
# else
(C_171_A, B)
MASSTOR_LIST C_171_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_171_A == 0) {
    C = DIPRN_DIRPNG(B);
    return C;
  }
  if (B == 0) {
    C = C_171_A;
    return C;
  }
  AP = C_171_A;
  BP = B;
  CP = MASSTOR_SIL;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = MASUGB_EVCOMP(EL, FL);
    if (SL == 0) {
      SL = DIPC_EVILCP(EL, FL);
    }
    if (SL == 1) {
      DIPC_DIPMAD(AP, &AL, &EL, &AP);
      CP = DIPC_DIPMCP(EL, AL, CP);
    } else {
      if (SL == -1) {
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACRN_RNNEG(BL);
        CP = DIPC_DIPMCP(FL, CL, CP);
      } else {
        DIPC_DIPMAD(AP, &AL, &EL, &AP);
        DIPC_DIPMAD(BP, &BL, &FL, &BP);
        CL = SACRN_RNDIF(AL, BL);
        if (CL != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  APP = AP;
  if (AP == MASSTOR_SIL) {
    if (BP != MASSTOR_SIL) {
      APP = DIPRN_DIRPNG(BP);
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

MASSTOR_LIST MASUGB_SFP
# ifdef __STDC__
(MASSTOR_LIST C_170_A, MASSTOR_LIST B)
# else
(C_170_A, B)
MASSTOR_LIST C_170_A, B;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL;

  if (C_170_A == 0) {
    C = B;
    return C;
  }
  if (B == 0) {
    C = C_170_A;
    return C;
  }
  AP = C_170_A;
  BP = B;
  CP = MASSTOR_SIL;
  do {
    EL = DIPC_DIPEVL(AP);
    FL = DIPC_DIPEVL(BP);
    SL = MASUGB_EVCOMP(EL, FL);
    if (SL == 0) {
      SL = DIPC_EVILCP(EL, FL);
    }
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
        CL = SACRN_RNSUM(AL, BL);
        if (CL != 0) {
          CP = DIPC_DIPMCP(EL, CL, CP);
        }
      }
    }
  } while (!(AP == MASSTOR_SIL || BP == MASSTOR_SIL));
  APP = AP;
  if (AP == MASSTOR_SIL) {
    if (BP != MASSTOR_SIL) {
      APP = BP;
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

MASSTOR_LIST MASUGB_EVLFCP
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST V)
# else
(L, U, V)
MASSTOR_LIST L, U, V;
# endif
{
  MASSTOR_LIST C_169_A, B, T;

  C_169_A = MASUGB_SKPRO2(L, U);
  B = MASUGB_SKPRO2(L, V);
  T = SACRN_RNCOMP(C_169_A, B);
  return T;
}

MASSTOR_LIST MASUGB_PCOMP
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST Y)
# else
(X, Y)
MASSTOR_LIST X, Y;
# endif
{
  MASSTOR_LIST C_168_A, C, XP, Z;

  XP = X;
  Z = Y;
  if (X == MASSTOR_SIL) {
    Z = Y;
    return Z;
  }
  if (Y == MASSTOR_SIL) {
    Z = X;
    return Z;
  }
  while (XP != MASSTOR_SIL) {
    DIPC_DIPMAD(XP, &C_168_A, &C, &XP);
    Z = DIPC_DIPMCP(C_168_A, C, Z);
  }
  return Z;
}

MASSTOR_LIST MASUGB_EVCOMP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL;

  if (DIPC_EVORD > MASSTOR_SIL) {
    TL = MASUGB_EVLFCP(DIPC_EVORD, U, V);
    return TL;
  }
  switch (DIPC_EVORD) {
  case DIPC_LEX:;
    TL = DIPC_EVILCP(U, V);
    TL = -TL;
    break;
  case DIPC_INVLEX:;
    TL = DIPC_EVILCP(U, V);
    break;
  case DIPC_GRLEX:;
    TL = DIPC_EVIGLC(U, V);
    TL = -TL;
    break;
  case DIPC_IGRLEX:;
    TL = DIPC_EVIGLC(U, V);
    break;
  }
  return TL;
}

MASSTOR_LIST MASUGB_DIPMC2
# ifdef __STDC__
(MASSTOR_LIST C_167_A, MASSTOR_LIST C, MASSTOR_LIST P)
# else
(C_167_A, C, P)
MASSTOR_LIST C_167_A, C, P;
# endif
{
  MASSTOR_LIST AA, AP, CC, DP, PP, U;

  PP = P;
  DP = MASSTOR_SIL;
  U = 0;
  AP = C_167_A;
  while (PP != MASSTOR_SIL && U != 1) {
    DIPC_DIPMAD(PP, &AA, &CC, &PP);
    U = MASUGB_COMPA2(CC, C);
    if (U == 1) {
      AP = SACRN_RNSUM(AP, AA);
    } else {
      DP = DIPC_DIPMCP(AA, CC, DP);
    }
  }
  DP = MASUGB_PCOMP(PP, DP);
  if (AP != 0) {
    DP = DIPC_DIPMCP(AP, C, DP);
  }
  return DP;
}

MASSTOR_LIST MASUGB_DIRRNF
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST X, MASSTOR_LIST V)
# else
(P, S, X, V)
MASSTOR_LIST P, S, X, V;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, R, RP, SL, SP, TA, TE;

  if (S == 0 || P == MASSTOR_SIL) {
    R = S;
    return R;
  }
  R = 0;
  SP = S;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPC_EVMT(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      RP = DIPC_DIPFMO(TA, TE);
      R = MASUGB_SFP(R, RP);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = SACRN_RNQ(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPRN_DIRPPR(QP, AP);
        SP = MASUGB_DFP(SP, APP);
      }
    }
  } while (!(SP == 0));
  return R;
}

MASSTOR_LIST MASUGB_DIRPSP
# ifdef __STDC__
(MASSTOR_LIST C_166_A, MASSTOR_LIST B, MASSTOR_LIST X)
# else
(C_166_A, B, X)
MASSTOR_LIST C_166_A, B, X;
# endif
{
  MASSTOR_LIST evo, AL, AP, APP, BL, BP, BPP, C, CL, EL, EL1, FL, FL1, GL;

  C = 0;
  if (C_166_A == 0 || B == 0) {
    return C;
  }
  DIPC_DIPMAD(C_166_A, &AL, &EL, &AP);
  DIPC_DIPMAD(B, &BL, &FL, &BP);
  if (AP == MASSTOR_SIL && BP == MASSTOR_SIL) {
    return C;
  }
  GL = DIPC_EVLCM(EL, FL);
  if (AP == MASSTOR_SIL) {
    FL1 = DIPC_EVDIF(GL, FL);
    CL = SACRN_RNNEG(AL);
    BPP = DIPC_DIPFMO(CL, FL1);
    C = DIPRN_DIRPPR(BP, BPP);
    return C;
  }
  if (BP == MASSTOR_SIL) {
    EL1 = DIPC_EVDIF(GL, EL);
    APP = DIPC_DIPFMO(BL, EL1);
    C = DIPRN_DIRPPR(AP, APP);
    return C;
  }
  evo = DIPC_EVORD;
  DIPC_EVORD = X;
  EL1 = DIPC_EVDIF(GL, EL);
  FL1 = DIPC_EVDIF(GL, FL);
  APP = DIPC_DIPFMO(BL, EL1);
  BPP = DIPC_DIPFMO(AL, FL1);
  APP = DIPRN_DIRPPR(AP, APP);
  BPP = DIPRN_DIRPPR(BP, BPP);
  C = MASUGB_DFP(APP, BPP);
  DIPC_EVORD = evo;
  return C;
}

MASSTOR_LIST MASUGB_UG
# ifdef __STDC__
(MASSTOR_LIST LF, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST STAP, MASSTOR_LIST P, MASSTOR_LIST NURLF, MASSTOR_LIST PAR)
# else
(LF, I, V, STAP, P, NURLF, PAR)
MASSTOR_LIST LF, I, V, STAP, P, NURLF, PAR;
# endif
{
  MASSTOR_LIST evo, D, DS, DSUM, FLAG, J1Y, J2Y, J3Y, L, LFALT, LFEND, LFNEU, LFP, LFTEMP, LNEU, LSUM, PAARE, PAIRS, SEMA, STAPP, U, UGF, X;
  BOOLEAN fin;

  UGF = MASSTOR_SIL;
  LFP = LF;
  STAPP = STAP;
  LFTEMP = MASSTOR_SIL;
  LFEND = MASSTOR_SIL;
  LFP = MASUGB_GS1(LFP, V, PAR);
  LSUM = MASUGB_EXPTU(P);
  DSUM = MASSTOR_SIL;
  LFALT = NURLF;
  if (PAR == 8) {
    MASBIOS_SWRITE("Reduktionsschritt", 17L);
    MASBIOS_BLINES(1);
  }
  evo = DIPC_EVORD;
  do {
    LSUM = SACSET_USUN(LSUM, DSUM);
    LFTEMP = MASSTOR_SIL;
    FLAG = 0;
    DSUM = MASSTOR_SIL;
    while (LFP != MASSTOR_SIL) {
      DS = MASSTOR_SIL;
      MASSTOR_ADV(LFP, &X, &LFP);
      DIPC_EVORD = MASSTOR_FIRST(X);
      L = SACLIST_SECOND(X);
      PAIRS = MASUGB_LASTEL(X);
      MASUGB_MKSP1(MASSTOR_FIRST(X), L, PAIRS, I, V, &D, &PAARE);
      if (D == 0) {
        UGF = MASSTOR_COMP(X, UGF);
        J1Y = MASSTOR_FIRST(X);
        LFEND = MASSTOR_COMP(J1Y, LFEND);
      } else {
        LNEU = MASSTOR_COMP(D, L);
        J1Y = MASSTOR_LIST1(D);
        DSUM = SACSET_USUN(J1Y, DSUM);
        J1Y = MASSTOR_FIRST(X);
        J2Y = SACLIST_THIRD(X);
        J3Y = SACLIST_FOURTH(X);
        J1Y = SACLIST_LIST5(J1Y, LNEU, J2Y, J3Y, PAARE);
        LFTEMP = MASSTOR_COMP(J1Y, LFTEMP);
        FLAG = 1;
      }
    }
    for (;;) {
      fin = FALSE;
      if (FLAG == 1) {
        MASUGB_ISNEU(DSUM, LSUM, PAR, &SEMA, &DSUM);
        if (SEMA == 1) {
          MASUGB_NEULF(STAPP, DSUM, LSUM, I, V, PAR, &LFNEU, &STAPP);
          U = MASUGB_ISNEUL(LFNEU, LFALT, PAR);
          LFALT = LFNEU;
          if (U == 0) {
            if (PAR == 8) {
              MASBIOS_SWRITE("Keine neuen Linearformen", 24L);
              MASBIOS_BLINES(1);
            }
            LFP = MASUGB_NONEWL(LFTEMP);
            LFP = MASUGB_GS2(LFP, V, PAR);
            MASBIOS_BLINES(1);
            goto EXIT_2;
          }
          if (U == 1) {
            if (PAR == 8) {
              MASBIOS_SWRITE("Neue Linearformen entstanden ", 29L);
              MASBIOS_BLINES(1);
            }
            LFP = MASUGB_NEWL(LFTEMP, LFNEU, LFEND);
            MASBIOS_BLINES(1);
            LFP = MASUGB_GS2(LFP, V, PAR);
            goto EXIT_2;
          }
        }
        if (SEMA == 0) {
          LFP = MASUGB_NONEWL(LFTEMP);
          LFP = MASUGB_GS2(LFP, V, PAR);
          MASBIOS_BLINES(1);
          goto EXIT_2;
        }
      }
      fin = TRUE;
      goto EXIT_2;
    } EXIT_2:;
  } while (!fin);
  DIPC_EVORD = evo;
  return UGF;
}

MASSTOR_LIST MASUGB_PUG
# ifdef __STDC__
(MASSTOR_LIST LF, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST P, MASSTOR_LIST DEGP, MASSTOR_LIST NURLF, MASSTOR_LIST PAR, MASSTOR_LIST LFQ)
# else
(LF, I, V, P, DEGP, NURLF, PAR, LFQ)
MASSTOR_LIST LF, I, V, P, DEGP, NURLF, PAR, LFQ;
# endif
{
  MASSTOR_LIST evo, D, DEG, DEG1, DS, DSUM, DSUM1, FLAG, J1Y, J2Y, J3Y, L, LFALT, LFEND, LFNEU, LFP, LFTEMP, LNEU, LSUM, PAARE, PAIRS, R, SEMA, U, UGF, X;
  BOOLEAN fin;

  UGF = MASSTOR_SIL;
  LFP = LF;
  LFTEMP = MASSTOR_SIL;
  LFEND = MASSTOR_SIL;
  DEG = DEGP;
  LFP = MASUGB_GS1(LFP, V, PAR);
  LSUM = MASUGB_EXPTU(P);
  DSUM = MASSTOR_SIL;
  LFALT = NURLF;
  if (PAR == 8) {
    MASBIOS_SWRITE("Reduktionsschritt", 17L);
    MASBIOS_BLINES(1);
  }
  evo = DIPC_EVORD;
  do {
    LSUM = SACSET_USUN(LSUM, DSUM);
    LFTEMP = MASSTOR_SIL;
    FLAG = 0;
    DSUM = MASSTOR_SIL;
    while (LFP != MASSTOR_SIL) {
      DS = MASSTOR_SIL;
      MASSTOR_ADV(LFP, &X, &LFP);
      DIPC_EVORD = MASSTOR_FIRST(X);
      L = SACLIST_SECOND(X);
      PAIRS = MASUGB_LASTEL(X);
      MASUGB_MKSP1(MASSTOR_FIRST(X), L, PAIRS, I, V, &D, &PAARE);
      if (D == 0) {
        UGF = MASSTOR_COMP(X, UGF);
        J1Y = MASSTOR_FIRST(X);
        LFEND = MASSTOR_COMP(J1Y, LFEND);
      } else {
        LNEU = MASSTOR_COMP(D, L);
        J1Y = MASSTOR_LIST1(D);
        DSUM = SACSET_USUN(J1Y, DSUM);
        J1Y = MASSTOR_FIRST(X);
        J2Y = SACLIST_THIRD(X);
        J3Y = SACLIST_FOURTH(X);
        J1Y = SACLIST_LIST5(J1Y, LNEU, J2Y, J3Y, PAARE);
        LFTEMP = MASSTOR_COMP(J1Y, LFTEMP);
        FLAG = 1;
      }
    }
    for (;;) {
      fin = FALSE;
      if (FLAG == 1) {
        DSUM1 = DSUM;
        MASUGB_ISNEU(DSUM, LSUM, PAR, &SEMA, &DSUM);
        if (SEMA == 1) {
          DEG1 = MASUGB_LDEG(DSUM1);
          if (PAR == 8) {
            MASBIOS_SWRITE("Grad der Polynome  ", 19L);
            SACLIST_OWRITE(DEG1);
            MASBIOS_BLINES(1);
          }
          if (DEG1 > DEG) {
            MASBIOS_SWRITE("Lese Linearfomen ... ", 21L);
            if (I == 2) {
              SACI_IQR(DEG1, 2, &DEG1, &R);
              if (R != 0) {
                DEG1 = DEG1 + 1;
              }
            }
            if (PAR == 8) {
              MASBIOS_BLINES(1);
            }
            LFNEU = MASUGB_LFGET(DEG1, LFQ);
            LFNEU = MASUGB_DO1(LFNEU);
            U = MASUGB_ISNEUL(LFNEU, LFALT, PAR);
            DEG = DEG1;
          } else {
            U = 0;
            LFNEU = LFALT;
          }
          LFALT = LFNEU;
          if (U == 0) {
            if (PAR == 8) {
              MASBIOS_SWRITE("Keine neuen Linearformen", 24L);
              MASBIOS_BLINES(1);
            }
            LFP = MASUGB_NONEWL(LFTEMP);
            LFP = MASUGB_GS2(LFP, V, PAR);
            MASBIOS_BLINES(1);
            goto EXIT_3;
          }
          if (U == 1) {
            if (PAR == 8) {
              MASBIOS_SWRITE("Neue linearformen entstanden ", 29L);
              MASBIOS_BLINES(1);
            }
            LFP = MASUGB_NEWL(LFTEMP, LFNEU, LFEND);
            MASBIOS_BLINES(1);
            LFP = MASUGB_GS2(LFP, V, PAR);
            goto EXIT_3;
          }
        }
        if (SEMA == 0) {
          LFNEU = LFALT;
          LFP = MASUGB_NONEWL(LFTEMP);
          MASBIOS_BLINES(1);
          LFP = MASUGB_GS2(LFP, V, PAR);
          MASBIOS_BLINES(1);
          goto EXIT_3;
        }
      }
      fin = TRUE;
      goto EXIT_3;
    } EXIT_3:;
  } while (!fin);
  DIPC_EVORD = evo;
  return UGF;
}

MASSTOR_LIST MASUGB_NEWL
# ifdef __STDC__
(MASSTOR_LIST LFTEMP, MASSTOR_LIST LFNEU, MASSTOR_LIST LFEND)
# else
(LFTEMP, LFNEU, LFEND)
MASSTOR_LIST LFTEMP, LFNEU, LFEND;
# endif
{
  MASSTOR_LIST LF, LFNEUP, LFP, LL, SP, X;

  SP = LFTEMP;
  LFNEUP = LFNEU;
  LL = MASSTOR_SIL;
  while (SP != MASSTOR_SIL) {
    MASSTOR_ADV(SP, &X, &SP);
    MASUGB_ZULFO(LFNEUP, X, LL, LFEND, &LFP, &LF);
    LFNEUP = LF;
    LL = LFP;
  }
  return LFP;
}

void MASUGB_ZULFO
# ifdef __STDC__
(MASSTOR_LIST LFNEU, MASSTOR_LIST X, MASSTOR_LIST LL, MASSTOR_LIST LFEND, MASSTOR_LIST *LFP, MASSTOR_LIST *LF)
# else
(LFNEU, X, LL, LFEND, LFP, LF)
MASSTOR_LIST LFNEU, X, LL, LFEND;
MASSTOR_LIST *LFP, *LF;
# endif
{
  MASSTOR_LIST C_165_A, D, DIFNEU, J1Y, K1, KALT, L, LFNEU1, LFNEUP, LNEU, NEWKEG, U;

  LFNEUP = LFNEU;
  KALT = MASSTOR_SIL;
  LFNEU1 = MASSTOR_SIL;
  *LFP = LL;
  while (LFNEUP != MASSTOR_SIL) {
    MASSTOR_ADV(LFNEUP, &C_165_A, &LFNEUP);
    J1Y = SACLIST_FOURTH(X);
    K1 = MASUGB_CSPUR(C_165_A, J1Y, KALT);
    J1Y = SACLIST_THIRD(X);
    U = MASUGB_COMPA2(J1Y, K1);
    if (U == 1) {
      LNEU = SACLIST_SECOND(X);
      MASSTOR_ADV(LNEU, &D, &L);
      J1Y = SACLIST_FOURTH(X);
      DIFNEU = MASUGB_NEWDIF(L, D, J1Y);
      NEWKEG = MASUGB_CSPUR(C_165_A, DIFNEU, KALT);
      J1Y = MASUGB_LASTEL(X);
      J1Y = SACLIST_LIST5(C_165_A, LNEU, NEWKEG, DIFNEU, J1Y);
      *LFP = MASSTOR_COMP(J1Y, *LFP);
    } else {
      LFNEU1 = MASSTOR_COMP(C_165_A, LFNEU1);
    }
  }
  *LF = LFNEU1;
  return;
}

MASSTOR_LIST MASUGB_NONEWL
# ifdef __STDC__
(MASSTOR_LIST LFTEMP)
# else
(LFTEMP)
MASSTOR_LIST LFTEMP;
# endif
{
  MASSTOR_LIST D, DIFNEU, J1Y, J2Y, KALT, L, LFP, LFTEP, LNEU, NEWKEG, X;

  LFTEP = LFTEMP;
  KALT = MASSTOR_SIL;
  LFP = MASSTOR_SIL;
  while (LFTEP != MASSTOR_SIL) {
    MASSTOR_ADV(LFTEP, &X, &LFTEP);
    LNEU = SACLIST_SECOND(X);
    MASSTOR_ADV(LNEU, &D, &L);
    J1Y = SACLIST_FOURTH(X);
    DIFNEU = MASUGB_NEWDIF(L, D, J1Y);
    J1Y = MASSTOR_FIRST(X);
    NEWKEG = MASUGB_CSPUR(J1Y, DIFNEU, KALT);
    J1Y = MASSTOR_FIRST(X);
    J2Y = MASUGB_LASTEL(X);
    J1Y = SACLIST_LIST5(J1Y, LNEU, NEWKEG, DIFNEU, J2Y);
    LFP = MASSTOR_COMP(J1Y, LFP);
  }
  return LFP;
}

MASSTOR_LIST MASUGB_ISNEUL
# ifdef __STDC__
(MASSTOR_LIST LFALT, MASSTOR_LIST LFNEU, MASSTOR_LIST PAR)
# else
(LFALT, LFNEU, PAR)
MASSTOR_LIST LFALT, LFNEU, PAR;
# endif
{
  MASSTOR_LIST I, J, U;

  I = MASSTOR_LENGTH(LFALT);
  J = MASSTOR_LENGTH(LFNEU);
  if (I == J) {
    U = 0;
  } else {
    U = 1;
  }
  return U;
}

void MASUGB_NEULF
# ifdef __STDC__
(MASSTOR_LIST STAP, MASSTOR_LIST DSUM, MASSTOR_LIST LSUM, MASSTOR_LIST I, MASSTOR_LIST V, MASSTOR_LIST PAR, MASSTOR_LIST *LFNEU, MASSTOR_LIST *NEUST)
# else
(STAP, DSUM, LSUM, I, V, PAR, LFNEU, NEUST)
MASSTOR_LIST STAP, DSUM, LSUM, I, V, PAR;
MASSTOR_LIST *LFNEU, *NEUST;
# endif
{
  MASSTOR_LIST DIFALT, E, KALT, OLDL, PSUM;

  E = DSUM;
  E = MASUGB_MAKERN(E);
  DIFALT = MASSTOR_SIL;
  OLDL = MASSTOR_SIL;
  KALT = MASSTOR_SIL;
  PSUM = LSUM;
  PSUM = MASUGB_MAKERN(PSUM);
  *NEUST = MASSTOR_SIL;
  OLDL = SACLIST_LIST3(MASSTOR_SIL, MASSTOR_SIL, MASSTOR_SIL);
  *NEUST = MASUGB_PROJEC(PSUM, E, DIFALT, OLDL, I, PAR);
  *NEUST = MASUGB_MERGE(STAP, *NEUST);
  *LFNEU = MASUGB_ALLLF(*NEUST, KALT, I);
  return;
}

void MASUGB_ISNEU
# ifdef __STDC__
(MASSTOR_LIST DSUM, MASSTOR_LIST LSUM, MASSTOR_LIST PAR, MASSTOR_LIST *SEMA, MASSTOR_LIST *DD)
# else
(DSUM, LSUM, PAR, SEMA, DD)
MASSTOR_LIST DSUM, LSUM, PAR;
MASSTOR_LIST *SEMA, *DD;
# endif
{
  MASSTOR_LIST C_164_A, B, D, LP, TEMP, U, COUNT;

  LP = LSUM;
  D = MASUGB_EXPTU(DSUM);
  COUNT = 0;
  *DD = MASSTOR_SIL;
  while (D != MASSTOR_SIL) {
    MASSTOR_ADV(D, &C_164_A, &D);
    TEMP = MASSTOR_SIL;
    U = 0;
    while (LP != MASSTOR_SIL && U != 1) {
      MASSTOR_ADV(LP, &B, &LP);
      U = MASUGB_COMPA2(C_164_A, B);
      if (U != 1) {
        TEMP = MASSTOR_COMP(B, TEMP);
      }
    }
    LP = MASUGB_TCOMP(TEMP, LP);
    if (U != 1) {
      COUNT = COUNT + 1;
      *DD = MASSTOR_COMP(C_164_A, *DD);
    }
  }
  if (COUNT > 0) {
    *SEMA = 1;
    if (COUNT == 1 && PAR == 8) {
      MASBIOS_SWRITE("Es ist nur ein neuer Term entstanden", 36L);
      MASBIOS_BLINES(1);
    }
    if (COUNT >= 2 && PAR == 8) {
      MASBIOS_SWRITE("es sind ", 8L);
      SACLIST_OWRITE(COUNT);
      MASBIOS_SWRITE(" neue Terme entstanden", 22L);
      MASBIOS_BLINES(1);
    }
  }
  if (COUNT == 0) {
    *SEMA = 0;
    if (PAR == 8) {
      MASBIOS_SWRITE("es ist kein neuer Term entstanden", 33L);
      MASBIOS_BLINES(1);
    }
  }
  return;
}

MASSTOR_LIST MASUGB_TCOMP
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST Y)
# else
(X, Y)
MASSTOR_LIST X, Y;
# endif
{
  MASSTOR_LIST C_163_A, XP, Z;

  XP = X;
  Z = Y;
  if (X == MASSTOR_SIL) {
    Z = Y;
    return Z;
  }
  if (Y == MASSTOR_SIL) {
    Z = X;
    return Z;
  }
  while (XP != MASSTOR_SIL) {
    MASSTOR_ADV(XP, &C_163_A, &XP);
    Z = MASSTOR_COMP(C_163_A, Z);
  }
  return Z;
}

MASSTOR_LIST MASUGB_NEWDIF
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST D, MASSTOR_LIST DIFALT)
# else
(L, D, DIFALT)
MASSTOR_LIST L, D, DIFALT;
# endif
{
  MASSTOR_LIST D1, D2, DIFALP, DIFNEU, J1Y, L1, L2;

  L2 = MASUGB_EXPTU(L);
  L1 = MASUGB_MAKERN(L2);
  J1Y = MASSTOR_LIST1(D);
  D2 = MASUGB_EXPTU(J1Y);
  D1 = MASUGB_MAKERN(D2);
  DIFALP = DIFALT;
  DIFNEU = MASUGB_PDIF(L1, D1, DIFALP);
  return DIFNEU;
}

MASSTOR_LIST MASUGB_GS2
# ifdef __STDC__
(MASSTOR_LIST LF, MASSTOR_LIST V, MASSTOR_LIST PAR)
# else
(LF, V, PAR)
MASSTOR_LIST LF, V, PAR;
# endif
{
  MASSTOR_LIST evo, C_162_A, B, J1Y, J2Y, J3Y, LFP, LP, LP1, PAIRS, STAK, X;

  LFP = LF;
  STAK = MASSTOR_SIL;
  evo = DIPC_EVORD;
  if (PAR == 8) {
    MASBIOS_SWRITE("Ordne die Polynome nach den neuen Linearformen", 46L);
    MASBIOS_BLINES(1);
  }
  while (LFP != MASSTOR_SIL) {
    MASSTOR_ADV(LFP, &C_162_A, &LFP);
    B = MASSTOR_FIRST(C_162_A);
    LP = SACLIST_SECOND(C_162_A);
    DIPC_EVORD = B;
    LP = MASUGB_POLCOP(LP);
    DIPC_DILBSO(LP);
    LP1 = LP;
    J1Y = MASSTOR_RED(LP);
    J2Y = MASSTOR_FIRST(LP);
    J3Y = MASUGB_LASTEL(C_162_A);
    PAIRS = MASUGB_MKNEWP(J1Y, J2Y, J3Y);
    J1Y = SACLIST_THIRD(C_162_A);
    J2Y = SACLIST_FOURTH(C_162_A);
    X = SACLIST_LIST5(B, LP1, J1Y, J2Y, PAIRS);
    J1Y = MASSTOR_LIST1(X);
    STAK = SACSET_USUN(J1Y, STAK);
  }
  DIPC_EVORD = evo;
  return STAK;
}

MASSTOR_LIST MASUGB_ALLLF
# ifdef __STDC__
(MASSTOR_LIST STAKK, MASSTOR_LIST KALT, MASSTOR_LIST I)
# else
(STAKK, KALT, I)
MASSTOR_LIST STAKK, KALT, I;
# endif
{
  MASSTOR_LIST C_161_A, IP, J1Y, LENG, LF, LFX, LISTLF, LY, M, N, NEWLF, NURLF, Q2, STAKKP;

  STAKKP = STAKK;
  M = 1;
  IP = I;
  LISTLF = MASSTOR_SIL;
  J1Y = SACRN_RNINT(1);
  LFX = MASSTOR_LIST1(J1Y);
  LY = MASSTOR_SIL;
  LF = MASSTOR_LIST1(LFX);
  IP = IP - 1;
  NEWLF = MASSTOR_SIL;
  while (M <= IP) {
    MASSTOR_ADV(STAKKP, &C_161_A, &STAKKP);
    N = MASSTOR_FIRST(C_161_A);
    Q2 = SACLIST_SECOND(C_161_A);
    NURLF = MASUGB_MKLF3(LF, Q2, N, M);
    M = M + 1;
    LF = NURLF;
  }
  MASBIOS_SWRITE("Die disjunkten Linearformen sind ", 33L);
  SACLIST_OWRITE(MASSTOR_LENGTH(NURLF));
  MASBIOS_SWRITE(" Linearformen  ", 15L);
  MASBIOS_BLINES(1);
  NURLF = LF;
  return NURLF;
}

void MASUGB_LFALL
# ifdef __STDC__
(MASSTOR_LIST STAKK, MASSTOR_LIST L, MASSTOR_LIST KALT, MASSTOR_LIST I, MASSTOR_LIST *LISTLF, MASSTOR_LIST *NURLF)
# else
(STAKK, L, KALT, I, LISTLF, NURLF)
MASSTOR_LIST STAKK, L, KALT, I;
MASSTOR_LIST *LISTLF, *NURLF;
# endif
{
  MASSTOR_LIST C_160_A, IP, J1Y, LF, LFX, LY, M, N, NEWLF, Q2, STAKKP;

  STAKKP = STAKK;
  M = 1;
  IP = I;
  *LISTLF = MASSTOR_SIL;
  J1Y = SACRN_RNINT(1);
  LFX = MASSTOR_LIST1(J1Y);
  LY = MASSTOR_SIL;
  LF = MASSTOR_LIST1(LFX);
  IP = IP - 1;
  NEWLF = MASSTOR_SIL;
  while (M <= IP) {
    MASSTOR_ADV(STAKKP, &C_160_A, &STAKKP);
    N = MASSTOR_FIRST(C_160_A);
    Q2 = SACLIST_SECOND(C_160_A);
    MASUGB_MKLF2(LF, Q2, N, M, L, NURLF, LISTLF);
    M = M + 1;
    LF = *NURLF;
  }
  *NURLF = LF;
  MASBIOS_SWRITE("Die berechneten Linearformen sind ", 34L);
  SACLIST_OWRITE(MASSTOR_LENGTH(*NURLF));
  MASBIOS_BLINES(1);
  return;
}

MASSTOR_LIST MASUGB_MKLF3
# ifdef __STDC__
(MASSTOR_LIST LFP, MASSTOR_LIST Q2, MASSTOR_LIST NP, MASSTOR_LIST M)
# else
(LFP, Q2, NP, M)
MASSTOR_LIST LFP, Q2, NP, M;
# endif
{
  MASSTOR_LIST C_159_A, B, D, J, J1Y, KLIST, LF, LISTLF, NEWLF, TR;

  LF = LFP;
  NEWLF = MASSTOR_SIL;
  KLIST = MASSTOR_SIL;
  J = 0;
  LISTLF = MASSTOR_SIL;
  while (LF != MASSTOR_SIL) {
    D = MASSTOR_SIL;
    MASSTOR_ADV(LF, &B, &LF);
    if (Q2 == MASSTOR_SIL) {
      J1Y = SACLIST_LIST2(1, 1);
      D = MASSTOR_LIST1(J1Y);
    } else {
      TR = MASUGB_CP2(B, Q2);
      TR = MASUGB_RNVABS(TR);
      TR = MASUGB_LRNBMS(TR);
      D = MASUGB_CUT(TR);
    }
    MASUGB_CLF3(B, D, KLIST, NP, J, M, &C_159_A, &KLIST, &J);
    NEWLF = SACSET_USUN(C_159_A, NEWLF);
  }
  return NEWLF;
}

void MASUGB_CLF3
# ifdef __STDC__
(MASSTOR_LIST C, MASSTOR_LIST D, MASSTOR_LIST KLIST, MASSTOR_LIST NP, MASSTOR_LIST JP, MASSTOR_LIST M, MASSTOR_LIST *LFORM, MASSTOR_LIST *KLISTP, MASSTOR_LIST *J)
# else
(C, D, KLIST, NP, JP, M, LFORM, KLISTP, J)
MASSTOR_LIST C, D, KLIST, NP, JP, M;
MASSTOR_LIST *LFORM, *KLISTP, *J;
# endif
{
  MASSTOR_LIST C_158_A, DP, K, KALT, KLISTH, U;

  DP = D;
  *LFORM = MASSTOR_SIL;
  *J = JP;
  *KLISTP = KLIST;
  KALT = MASSTOR_SIL;
  KLISTH = MASSTOR_SIL;
  while (DP != MASSTOR_SIL) {
    MASSTOR_ADV(DP, &C_158_A, &DP);
    C_158_A = MASSTOR_COMP(C_158_A, C);
    K = MASUGB_CSPUR(C_158_A, NP, KALT);
    if (M != 1) {
      U = MASUGB_COMPA1(K, *KLISTP);
      if (U != 1) {
        KLISTH = MASSTOR_COMP(K, KLISTH);
        *LFORM = MASSTOR_COMP(C_158_A, *LFORM);
      }
    } else {
      *LFORM = MASSTOR_COMP(C_158_A, *LFORM);
    }
  }
  *KLISTP = SACLIST_CCONC(*KLISTP, KLISTH);
  return;
}

MASSTOR_LIST MASUGB_DO1
# ifdef __STDC__
(MASSTOR_LIST LFP)
# else
(LFP)
MASSTOR_LIST LFP;
# endif
{
  MASSTOR_LIST C_157_A, LF, LF1, E;

  LF = LFP;
  LF1 = MASSTOR_SIL;
  E = MASSTOR_LIST1(SACRN_RNINT(1));
  while (LF != MASSTOR_SIL) {
    MASSTOR_ADV(LF, &C_157_A, &LF);
    C_157_A = SACLIST_CCONC(C_157_A, E);
    LF1 = MASSTOR_COMP(C_157_A, LF1);
  }
  LF1 = MASSTOR_INV(LF1);
  return LF1;
}

void MASUGB_MKLIST
# ifdef __STDC__
(MASSTOR_LIST LF, MASSTOR_LIST L, MASSTOR_LIST *LFLIST, MASSTOR_LIST *NURLF)
# else
(LF, L, LFLIST, NURLF)
MASSTOR_LIST LF, L;
MASSTOR_LIST *LFLIST, *NURLF;
# endif
{
  MASSTOR_LIST C_156_A, J1Y, K, KALT, KLIST, LFP, P, Q;

  LFP = LF;
  KALT = MASSTOR_SIL;
  KLIST = MASSTOR_SIL;
  *NURLF = MASSTOR_SIL;
  *LFLIST = MASSTOR_SIL;
  Q = MASUGB_EXPTU(L);
  P = MASUGB_MAKERN(Q);
  P = MASUGB_DIFF(P);
  while (LFP != MASSTOR_SIL) {
    MASSTOR_ADV(LFP, &C_156_A, &LFP);
    K = MASUGB_CSPUR(C_156_A, P, KALT);
    *NURLF = MASSTOR_COMP(C_156_A, *NURLF);
    J1Y = SACLIST_LIST4(C_156_A, L, K, P);
    *LFLIST = MASSTOR_COMP(J1Y, *LFLIST);
  }
  return;
}

MASSTOR_LIST MASUGB_LDEG
# ifdef __STDC__
(MASSTOR_LIST L)
# else
(L)
MASSTOR_LIST L;
# endif
{
  MASSTOR_LIST DEG, DEG1, L1, LP;

  LP = L;
  DEG = 0;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &L1, &LP);
    DEG1 = DIPC_DIPTDG(L1);
    DEG = SACI_IMAX(DEG, DEG1);
  }
  return DEG;
}

void BEGIN_MASUGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_MASBIOS();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_MASRN();
    BEGIN_SACI();
    BEGIN_SACPOL();
    BEGIN_SACSET();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_MASSYM2();
    BEGIN_MASELEM();

  }
}
