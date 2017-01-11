#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPCJ
#include "DIPCJ.h"
#endif

#ifndef DEFINITION_DIPGB
#include "DIPGB.h"
#endif

#ifndef DEFINITION_DIPIB
#include "DIPIB.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_ADEXTRA
#include "ADEXTRA.h"
#endif

CHAR ADEXTRA_rcsid [] = "$Id: ADEXTRA.md,v 1.2 1995/12/16 12:07:19 kredel Exp $";
CHAR ADEXTRA_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: ADEXTRA.mi,v 1.1 1995/10/12 14:44:44 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";


MASSTOR_LIST ADEXTRA_ADPCP
# ifdef __STDC__
(MASSTOR_LIST C_89_A)
# else
(C_89_A)
MASSTOR_LIST C_89_A;
# endif
{
  MASSTOR_LIST AL, DL, EL, SL, AP, CL;

  if (C_89_A == 0) {
    return C_89_A;
  }
  DIPC_DIPMAD(C_89_A, &DL, &EL, &AP);
  SL = MASADOM_ADSIGN(DL);
  if (SL < 0) {
    DL = MASADOM_ADNEG(DL);
  }
  while (AP != MASSTOR_SIL && DL != 1) {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    DL = MASADOM_ADGCD(DL, AL);
  }
  CL = DL;
  AP = C_89_A;
  if (DL == 1) {
    if (SL < 0) {
      CL = -DL;
      AP = ADEXTRA_ADPNEG(C_89_A);
    }
  } else {
    if (SL < 0) {
      CL = MASADOM_ADNEG(DL);
    }
    AP = ADEXTRA_ADPIQ(C_89_A, CL);
  }
  return AP;
}

MASSTOR_LIST ADEXTRA_ADPNEG
# ifdef __STDC__
(MASSTOR_LIST C_88_A)
# else
(C_88_A)
MASSTOR_LIST C_88_A;
# endif
{
  MASSTOR_LIST AL, AS, B, BL, EL;

  if (C_88_A == 0) {
    B = 0;
    return B;
  }
  AS = C_88_A;
  B = MASSTOR_SIL;
  do {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    BL = MASADOM_ADNEG(AL);
    B = DIPC_DIPMCP(EL, BL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

MASSTOR_LIST ADEXTRA_ADPIQ
# ifdef __STDC__
(MASSTOR_LIST C_87_A, MASSTOR_LIST b)
# else
(C_87_A, b)
MASSTOR_LIST C_87_A, b;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, QL, RL;

  if (C_87_A == 0) {
    return 0;
  }
  C = MASSTOR_SIL;
  AP = C_87_A;
  do {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    MASADOM_ADQR(AL, b, &QL, &RL);
    C = DIPC_DIPMCP(EL, QL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

BOOLEAN ADEXTRA_ADLGinH
# ifdef __STDC__
(MASSTOR_LIST H, MASSTOR_LIST G)
# else
(H, G)
MASSTOR_LIST H, G;
# endif
{
  MASSTOR_LIST GG, h;

  if (H == MASSTOR_SIL) {
    return FALSE;
  }
  GG = G;
  DIPCJ_DILBBS(GG);
  while (H != MASSTOR_SIL) {
    MASSTOR_ADV(H, &h, &H);
    DIPCJ_DILBBS(h);
    if (ADEXTRA_ADLGeqH(h, GG)) {
      return TRUE;
    }
  }
  return FALSE;
}

BOOLEAN ADEXTRA_ADLGeqH
# ifdef __STDC__
(MASSTOR_LIST H, MASSTOR_LIST G)
# else
(H, G)
MASSTOR_LIST H, G;
# endif
{
  MASSTOR_LIST h, g;

  if (MASSTOR_LENGTH(H) != MASSTOR_LENGTH(G)) {
    return FALSE;
  }
  while (H != MASSTOR_SIL) {
    MASSTOR_ADV(H, &h, &H);
    MASSTOR_ADV(G, &g, &G);
    if (!ADEXTRA_ADPFeqG(h, g)) {
      return FALSE;
    }
  }
  return TRUE;
}

BOOLEAN ADEXTRA_ADPFeqG
# ifdef __STDC__
(MASSTOR_LIST F, MASSTOR_LIST G)
# else
(F, G)
MASSTOR_LIST F, G;
# endif
{
  MASSTOR_LIST f, g;

  if (MASSTOR_LENGTH(F) != MASSTOR_LENGTH(G)) {
    return FALSE;
  }
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &f, &F);
    MASSTOR_ADV(G, &g, &G);
    if (!SACLIST_EQUAL(f, g)) {
      return FALSE;
    }
  }
  return TRUE;
}

MASSTOR_LIST ADEXTRA_ADIredG
# ifdef __STDC__
(MASSTOR_LIST I, MASSTOR_LIST G)
# else
(I, G)
MASSTOR_LIST I, G;
# endif
{
  MASSTOR_LIST II, f, p;

  II = I;
  p = 0;
  while (II != MASSTOR_SIL) {
    MASSTOR_ADV(II, &f, &II);
    p = DIPGB_DIPNOR(G, f);
    if (p != 0) {
      return p;
    }
  }
  return 0;
}

MASSTOR_LIST ADEXTRA_ADGJredI
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST I)
# else
(G, I)
MASSTOR_LIST G, I;
# endif
{
  MASSTOR_LIST GG, f, p;
  BOOLEAN red;

  GG = G;
  p = 0;
  while (GG != MASSTOR_SIL) {
    MASSTOR_ADV(GG, &f, &GG);
    DIPIB_ADPNFJ(I, f, &p, &red);
    if (p != 0) {
      return p;
    }
  }
  return 0;
}

MASSTOR_LIST ADEXTRA_IBeqGB
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST I)
# else
(G, I)
MASSTOR_LIST G, I;
# endif
{
  MASSTOR_LIST i, g;

  i = ADEXTRA_ADIredG(I, G);
  if (i != 0) {
    return i;
  }
  g = ADEXTRA_ADGJredI(G, I);
  if (g != 0) {
    return g;
  } else {
    return 0;
  }
}

void BEGIN_ADEXTRA()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPCJ();
    BEGIN_DIPGB();
    BEGIN_DIPIB();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();

  }
}
