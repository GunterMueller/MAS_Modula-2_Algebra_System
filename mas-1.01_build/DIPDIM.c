#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_DIPDIM
#include "DIPDIM.h"
#endif

CHAR DIPDIM_rcsid [] = "$Id: DIPDIM.md,v 1.2 1992/02/12 17:34:16 pesch Exp $";
CHAR DIPDIM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPDIM.mi,v 1.4 1994/06/02 13:21:36 dolzmann Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPDIM_DIGBZT
# ifdef __STDC__
(MASSTOR_LIST S)
# else
(S)
MASSTOR_LIST S;
# endif
{
  MASSTOR_LIST EL, GP, J1Y, QL, RL, TL, V, VL, VS;

  TL = 1;
  if (S == MASSTOR_SIL) {
    return TL;
  }
  J1Y = MASSTOR_FIRST(S);
  RL = DIPC_DIPNOV(J1Y);
  if (RL == 0) {
    TL = -1;
    return TL;
  }
  MASSTOR_ADV(S, &QL, &GP);
  EL = DIPC_DIPEVL(QL);
  VL = DIPC_EVDOV(EL);
  VS = MASSTOR_BETA;
  if (VL == MASSTOR_SIL) {
    TL = -1;
    return TL;
  }
  if (MASSTOR_RED(VL) == MASSTOR_SIL) {
    V = 1;
  } else {
    V = 0;
  }
  while (GP != MASSTOR_SIL) {
    MASSTOR_ADV(GP, &QL, &GP);
    EL = DIPC_DIPEVL(QL);
    VL = DIPC_EVDOV(EL);
    if (VL != MASSTOR_SIL) {
      if (MASSTOR_RED(VL) == MASSTOR_SIL) {
        V = V + 1;
      }
    }
  }
  if (V == RL) {
    TL = 0;
  }
  return TL;
}

void DIPDIM_DILDIM
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST *DL, MASSTOR_LIST *S, MASSTOR_LIST *M)
# else
(G, DL, S, M)
MASSTOR_LIST G;
MASSTOR_LIST *DL, *S, *M;
# endif
{
  MASSTOR_LIST DLP, EL, I, J1Y, ML, MP, QL, RL, U, VL, VS;

  if (G == MASSTOR_SIL) {
    *DL = MASSTOR_LENGTH(DIPC_VALIS);
    return;
  }
  J1Y = MASSTOR_FIRST(G);
  RL = DIPC_DIPNOV(J1Y);
  if (RL == 0) {
    *DL = -1;
    return;
  }
  QL = MASSTOR_FIRST(G);
  EL = DIPC_DIPEVL(QL);
  VL = DIPC_EVDOV(EL);
  VS = MASSTOR_BETA;
  if (VL == MASSTOR_SIL) {
    *DL = -1;
    return;
  }
  *DL = 0;
  *S = MASSTOR_BETA;
  *M = MASSTOR_BETA;
  U = MASSTOR_BETA;
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        U = MASSTOR_COMP(I, U);
        if (I >= B_2) break;
      }
  }
  U = MASSTOR_INV(U);
  *M = DIPDIM_DIDIMS(G, *S, U, *M);
  *M = MASSTOR_INV(*M);
  MP = *M;
  while (MP != MASSTOR_SIL) {
    MASSTOR_ADV(MP, &ML, &MP);
    DLP = MASSTOR_LENGTH(ML);
    if (DLP > *DL) {
      *DL = DLP;
      *S = ML;
    }
  }
  return;
}

MASSTOR_LIST DIPDIM_DIDIMS
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST S, MASSTOR_LIST U, MASSTOR_LIST M)
# else
(G, S, U, M)
MASSTOR_LIST G, S, U, M;
# endif
{
  MASSTOR_LIST C_66_A, ML, MP, MS, SL, SP, TL, UL, UP;

  C_66_A = MASSTOR_BETA;
  UP = U;
  MP = M;
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &UL, &UP);
    SP = MASSTOR_LIST1(UL);
    SP = SACLIST_CCONC(S, SP);
    TL = DIPDIM_EVGBIT(SP, G);
    if (TL == 0) {
      MP = DIPDIM_DIDIMS(G, SP, UP, MP);
    }
  }
  MS = MP;
  SL = 0;
  while (MS != MASSTOR_SIL && SL == 0) {
    MASSTOR_ADV(MS, &ML, &MS);
    SL = DIPDIM_USETCT(S, ML);
  }
  if (SL == 0) {
    MP = MASSTOR_COMP(S, MP);
  }
  return MP;
}

MASSTOR_LIST DIPDIM_EVGBIT
# ifdef __STDC__
(MASSTOR_LIST S, MASSTOR_LIST G)
# else
(S, G)
MASSTOR_LIST S, G;
# endif
{
  MASSTOR_LIST EL, GP, J1Y, PL, RL, SL, SP, SPP, TL, V;

  GP = G;
  TL = 0;
  if (GP == MASSTOR_SIL) {
    return TL;
  }
  J1Y = MASSTOR_FIRST(GP);
  RL = DIPC_DIPNOV(J1Y);
  SP = S;
  SPP = MASSTOR_BETA;
  while (SP != MASSTOR_SIL) {
    MASSTOR_ADV(SP, &SL, &SP);
    J1Y = RL - SL;
    SL = J1Y + 1;
    SPP = MASSTOR_COMP(SL, SPP);
  }
  SPP = MASSTOR_INV(SPP);
  TL = 1;
  while (GP != MASSTOR_SIL) {
    MASSTOR_ADV(GP, &PL, &GP);
    EL = DIPC_DIPEVL(PL);
    V = DIPC_EVDOV(EL);
    SL = DIPDIM_USETCT(V, SPP);
    if (SL == 1) {
      return TL;
    }
  }
  TL = 0;
  return TL;
}

MASSTOR_LIST DIPDIM_USETCT
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, UP;

  UP = U;
  TL = 0;
  while (UP != MASSTOR_SIL) {
    MASSTOR_ADV(UP, &UL, &UP);
    if (!(SACLIST_MEMBER(UL, V) == 1)) {
      return TL;
    }
  }
  TL = 1;
  return TL;
}

MASSTOR_LIST DIPDIM_IXSUBS
# ifdef __STDC__
(MASSTOR_LIST V, MASSTOR_LIST I)
# else
(V, I)
MASSTOR_LIST V, I;
# endif
{
  MASSTOR_LIST IL, IP, VL, VP;

  IP = I;
  VP = MASSTOR_BETA;
  while (IP != MASSTOR_SIL) {
    MASSTOR_ADV(IP, &IL, &IP);
    VL = SACLIST_LELT(V, IL);
    VP = MASSTOR_COMP(VL, VP);
  }
  VP = MASSTOR_INV(VP);
  return VP;
}

void DIPDIM_DIDIMWR
# ifdef __STDC__
(MASSTOR_LIST DL, MASSTOR_LIST S, MASSTOR_LIST M, MASSTOR_LIST V)
# else
(DL, S, M, V)
MASSTOR_LIST DL, S, M, V;
# endif
{
  MASSTOR_LIST VV, ML;

  MASBIOS_BLINES(0);
  MASBIOS_SWRITE("Dimension = ", 12L);
  SACLIST_AWRITE(DL);
  MASBIOS_BLINES(1);
  VV = DIPDIM_IXSUBS(V, S);
  MASBIOS_SWRITE("Maximal independent set = ", 26L);
  SACPOL_VLWRIT(VV);
  MASBIOS_BLINES(1);
  MASBIOS_SWRITE("All maximal independent sets = ( ", 33L);
  while (M != MASSTOR_SIL) {
    MASSTOR_ADV(M, &ML, &M);
    VV = DIPDIM_IXSUBS(V, ML);
    SACPOL_VLWRIT(VV);
    if (M != MASSTOR_SIL) {
      MASBIOS_SWRITE(", ", 2L);
    }
  }
  MASBIOS_SWRITE(" )", 2L);
  MASBIOS_BLINES(1);
  return;
}

void BEGIN_DIPDIM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_DIPC();
    BEGIN_SACPOL();

  }
}
