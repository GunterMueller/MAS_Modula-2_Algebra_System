#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_SACD
#include "SACD.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACCOMB
#include "SACCOMB.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_SACDPOL
#include "SACDPOL.h"
#endif

#ifndef DEFINITION_LINALGRN
#include "LINALGRN.h"
#endif

#ifndef DEFINITION_DIPTOO
#include "DIPTOO.h"
#endif

CHAR DIPTOO_rcsid [] = "$Id: DIPTOO.md,v 1.4 1994/03/30 13:05:15 dolzmann Exp $";
CHAR DIPTOO_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPTOO.mi,v 1.7 1996/06/09 12:11:54 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPTOO_DIPDEM
# ifdef __STDC__
(MASSTOR_LIST C_225_A)
# else
(C_225_A)
MASSTOR_LIST C_225_A;
# endif
{
  MASSTOR_LIST AL, AP, B, EL, I, RL;

  B = MASSTOR_BETA;
  RL = DIPC_DIPNOV(C_225_A);
  if (RL == 0) {
    return B;
  }
  {
    LONGINT B_1 = 1, B_2 = RL;

    if (B_1 <= B_2)
      for (I = B_1;; I += 1) {
        B = MASSTOR_COMP(0, B);
        if (I >= B_2) break;
      }
  }
  AP = C_225_A;
  while (AP != MASSTOR_SIL) {
    DIPC_DIPMAD(AP, &AL, &EL, &AP);
    B = DIPTOO_DMEVAD(B, EL);
  }
  return B;
}

MASSTOR_LIST DIPTOO_DIPDEV
# ifdef __STDC__
(MASSTOR_LIST C_224_A)
# else
(C_224_A)
MASSTOR_LIST C_224_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, N, NL;

  N = MASSTOR_BETA;
  if (C_224_A == 0) {
    return N;
  }
  if (DIPC_DIPNOV(C_224_A) <= 1) {
    NL = DIPC_DIPDEG(C_224_A);
    N = MASSTOR_LIST1(NL);
    return N;
  }
  DIPC_DIPMAD(C_224_A, &AL, &N, &AS);
  while (AS != MASSTOR_SIL) {
    DIPC_DIPMAD(AS, &AL, &EL, &AS);
    N = DIPC_EVLCM(N, EL);
  }
  return N;
}

MASSTOR_LIST DIPTOO_DIPLDM
# ifdef __STDC__
(MASSTOR_LIST C_223_A)
# else
(C_223_A)
MASSTOR_LIST C_223_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, BP, C, CL;

  B = MASSTOR_BETA;
  if (C_223_A == MASSTOR_SIL) {
    return B;
  }
  AP = C_223_A;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
  } while (!(AL != 0 || AP == MASSTOR_SIL));
  if (AL == 0) {
    return B;
  }
  B = DIPTOO_DIPDEM(AL);
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    if (AL != 0) {
      BP = DIPTOO_DIPDEM(AL);
      C = MASSTOR_BETA;
      while (BP != MASSTOR_SIL) {
        MASSTOR_ADV(BP, &BL, &BP);
        MASSTOR_ADV(B, &CL, &B);
        CL = SACIPOL_IPSUM(1, BL, CL);
        C = MASSTOR_COMP(CL, C);
      }
      B = MASSTOR_INV(C);
    }
  }
  return B;
}

MASSTOR_LIST DIPTOO_DIPTRM
# ifdef __STDC__
(MASSTOR_LIST C_222_A)
# else
(C_222_A)
MASSTOR_LIST C_222_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, FL, L, RL, SL, T, TL;

  RL = DIPC_DIPNOV(C_222_A);
  if (RL == 0) {
    T = MASSTOR_BETA;
    return T;
  }
  if (RL == 1) {
    L = MASSTOR_LENGTH(C_222_A);
    L = L / 2;
    T = MASSTOR_LIST1(L);
    return T;
  }
  DIPC_DIPADM(C_222_A, &EL, &FL, &AL, &AS);
  L = 1;
  TL = DIPTOO_DIPTRM(AL);
  while (AS != 0) {
    DIPC_DIPADM(AS, &EL, &FL, &AL, &AS);
    SL = DIPTOO_DIPTRM(AL);
    L = L + 1;
    TL = DIPC_EVSUM(TL, SL);
  }
  T = MASSTOR_COMP(L, TL);
  return T;
}

MASSTOR_LIST DIPTOO_DIPTYP
# ifdef __STDC__
(MASSTOR_LIST C_221_A)
# else
(C_221_A)
MASSTOR_LIST C_221_A;
# endif
{
  MASSTOR_LIST B, P, PL, RL, SL, TL;

  RL = DIPC_DIPNOV(C_221_A);
  if (RL <= 1) {
    TL = SACRN_RNRED(1, 1);
    return TL;
  }
  SL = DIPTOO_DIPTRM(C_221_A);
  P = 0;
  do {
    MASSTOR_ADV(SL, &PL, &SL);
    P = SACI_ISUM(P, PL);
  } while (!(SL == MASSTOR_SIL));
  B = SACI_IPROD(PL, RL);
  TL = SACRN_RNRED(P, B);
  return TL;
}

void DIPTOO_DIPVOP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST V, MASSTOR_LIST *PP, MASSTOR_LIST *VP)
# else
(P, V, PP, VP)
MASSTOR_LIST P, V;
MASSTOR_LIST *PP, *VP;
# endif
{
  MASSTOR_LIST M, ML, MP, PL, PS, PV, VB, VL, VS;

  M = DIPTOO_DIPLDM(P);
  PV = DIPTOO_PVDEMA(M);
  VS = SACLIST_CINV(V);
  *VP = SACCOMB_LPERM(V, PV);
  MP = M;
  MASBIOS_SWRITE("THE REDUCED POLYNOMIALS", 23L);
  MASBIOS_BLINES(2);
  while (MP != MASSTOR_SIL) {
    MASSTOR_ADV(MP, &ML, &MP);
    MASSTOR_ADV(VS, &VL, &VS);
    VB = MASSTOR_LIST1(VL);
    ML = DIPC_DIPFP(1, ML);
    DIPI_DIIPWR(ML, VB);
    MASBIOS_BLINES(2);
  }
  MASBIOS_SWRITE("THE PERMUTATION VECTOR ", 23L);
  SACLIST_OWRITE(PV);
  MASBIOS_BLINES(2);
  MASBIOS_SWRITE("THE NEW VARIABLE LIST   ", 24L);
  SACPOL_VLWRIT(*VP);
  MASBIOS_BLINES(4);
  *PP = MASSTOR_BETA;
  PS = P;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PL, &PS);
    PL = DIPC_DIPERM(PL, PV);
    *PP = MASSTOR_COMP(PL, *PP);
  }
  *PP = MASSTOR_INV(*PP);
  return;
}

void DIPTOO_DIPVOPP
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST V, MASSTOR_LIST *PP, MASSTOR_LIST *VP, MASSTOR_LIST *PV)
# else
(P, V, PP, VP, PV)
MASSTOR_LIST P, V;
MASSTOR_LIST *PP, *VP, *PV;
# endif
{
  *PV = DIPTOO_PVDEMA(DIPTOO_DIPLDM(P));
  *VP = SACCOMB_LPERM(V, *PV);
  *PP = DIPC_DILPERM(P, *PV);
  return;
}

MASSTOR_LIST DIPTOO_DMEVAD
# ifdef __STDC__
(MASSTOR_LIST C_220_A, MASSTOR_LIST E)
# else
(C_220_A, E)
MASSTOR_LIST C_220_A, E;
# endif
{
  MASSTOR_LIST AL, AP, B, BL, EL, EP, FL;

  AP = C_220_A;
  EP = E;
  B = MASSTOR_BETA;
  while (AP != MASSTOR_SIL) {
    MASSTOR_ADV(AP, &AL, &AP);
    MASSTOR_ADV(EP, &EL, &EP);
    FL = SACPOL_PMON(1, EL);
    BL = SACIPOL_IPSUM(1, AL, FL);
    B = MASSTOR_COMP(BL, B);
  }
  B = MASSTOR_INV(B);
  return B;
}

void DIPTOO_HDIFDI
# ifdef __STDC__
(MASSTOR_LIST C_219_A, MASSTOR_LIST *B, MASSTOR_LIST *FL)
# else
(C_219_A, B, FL)
MASSTOR_LIST C_219_A;
MASSTOR_LIST *B, *FL;
# endif
{
  MASSTOR_LIST AL, AP, C, DL, E, EL, G, GL;

  *B = 0;
  *FL = 0;
  if (C_219_A == 0) {
    return;
  }
  AP = C_219_A;
  DL = DIPC_DIPTDG(C_219_A);
  C = MASSTOR_BETA;
  do {
    DIPC_DIPMAD(AP, &AL, &E, &AP);
    EL = DIPC_EVTDEG(E);
    GL = DL - EL;
    if (GL > 0) {
      *FL = 1;
    }
    G = SACLIST_CINV(E);
    G = MASSTOR_COMP(GL, G);
    G = MASSTOR_INV(G);
    C = DIPC_DIPMCP(G, AL, C);
  } while (!(AP == MASSTOR_SIL));
  *B = MASSTOR_INV(C);
  return;
}

MASSTOR_LIST DIPTOO_INVPERM
# ifdef __STDC__
(MASSTOR_LIST perm)
# else
(perm)
MASSTOR_LIST perm;
# endif
{
  MASSTOR_LIST L, pos;
  INTEGER i, n;

  n = MASSTOR_LENGTH(perm);
  L = MASSTOR_SIL;
  {
    LONGINT B_3 = 1, B_4 = n;

    if (B_3 <= B_4)
      for (i = B_3;; i += 1) {
        L = MASSTOR_COMP(0, L);
        if (i >= B_4) break;
      }
  }
  {
    LONGINT B_5 = 1, B_6 = n;

    if (B_5 <= B_6)
      for (i = B_5;; i += 1) {
        MASSTOR_ADV(perm, &pos, &perm);
        SACLIST_SLELT(L, pos, i);
        if (i >= B_6) break;
      }
  }
  return L;
}

MASSTOR_LIST DIPTOO_LBLXCO
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST TL, UL, US, VL, VS;

  TL = 0;
  US = U;
  VS = V;
  while (US != MASSTOR_SIL && VS != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL > VL) {
      TL = -1;
      return TL;
    }
    if (UL < VL) {
      TL = 1;
      return TL;
    }
  }
  if (US == MASSTOR_SIL && VS == MASSTOR_SIL) {
    return TL;
  }
  if (US == MASSTOR_SIL) {
    TL = 1;
  } else {
    TL = -1;
  }
  return TL;
}

BOOLEAN DIPTOO_LFCHECK
# ifdef __STDC__
(MASSTOR_LIST L, MASSTOR_LIST f)
# else
(L, f)
MASSTOR_LIST L, f;
# endif
{
  MASSTOR_LIST LP, LS, LL, LU, p, ps, d, dp;

  if (L == MASSTOR_SIL) {
    L = DIPC_EVORD;
  }
  if (L <= MASSTOR_SIL) {
    if (f > 0) {
      MASBIOS_SWRITE("Nothing to check.", 17L);
      MASBIOS_BLINES(0);
    }
    return TRUE;
  }
  d = 0;
  LS = MASSTOR_SIL;
  LP = L;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &p, &LP);
    ps = SACDPOL_DPFP(1, p);
    dp = SACPOL_PDEG(p);
    if (dp > d) {
      d = dp;
    }
    LS = MASSTOR_COMP(ps, LS);
  }
  LS = MASSTOR_INV(LS);
  LP = LS;
  LS = MASSTOR_SIL;
  while (LP != MASSTOR_SIL) {
    MASSTOR_ADV(LP, &p, &LP);
    MASSTOR_ADV(p, &dp, &ps);
    while (dp < d) {
      ps = MASSTOR_COMP(0, ps);
      dp = dp + 1;
    }
    LS = MASSTOR_COMP(ps, LS);
  }
  LS = MASSTOR_INV(LS);
  LS = LINALGRN_RNMFIM(LS);
  LINALGRN_RNMGELUD(LS, &LL, &LU);
  if (MASSTOR_LENGTH(LS) > MASSTOR_LENGTH(LU)) {
    if (f > 0) {
      MASBIOS_SWRITE("LFCHECK: LF linearly dependent.", 31L);
      MASBIOS_BLINES(0);
    }
    return FALSE;
  }
  if (f > 0) {
    MASBIOS_SWRITE("LFCHECK: LF linearly independent.", 33L);
    MASBIOS_BLINES(0);
  }
  return TRUE;
}

MASSTOR_LIST DIPTOO_PTERM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_218_A)
# else
(RL, C_218_A)
MASSTOR_LIST RL, C_218_A;
# endif
{
  MASSTOR_LIST AL, AS, EL, L, RLS, SL, T, TL;

  if (C_218_A == 0 || RL == 0) {
    T = MASSTOR_BETA;
    return T;
  }
  if (RL == 1) {
    L = MASSTOR_LENGTH(C_218_A);
    L = L / 2;
    T = MASSTOR_LIST1(L);
    return T;
  }
  RLS = RL - 1;
  SACLIST_ADV2(C_218_A, &EL, &AL, &AS);
  L = 1;
  TL = DIPTOO_PTERM(RLS, AL);
  while (AS != MASSTOR_SIL) {
    SACLIST_ADV2(AS, &EL, &AL, &AS);
    SL = DIPTOO_PTERM(RLS, AL);
    L = L + 1;
    TL = DIPC_EVSUM(TL, SL);
  }
  T = MASSTOR_COMP(L, TL);
  return T;
}

MASSTOR_LIST DIPTOO_PTYP
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_217_A)
# else
(RL, C_217_A)
MASSTOR_LIST RL, C_217_A;
# endif
{
  MASSTOR_LIST B, P, PL, SL, TL;

  if (C_217_A == 0 || RL <= 1) {
    TL = SACLIST_LIST2(1, 1);
    return TL;
  }
  SL = DIPTOO_PTERM(RL, C_217_A);
  P = 0;
  do {
    MASSTOR_ADV(SL, &PL, &SL);
    P = SACI_ISUM(P, PL);
  } while (!(SL == MASSTOR_SIL));
  B = SACI_IPROD(PL, RL);
  TL = SACRN_RNRED(P, B);
  return TL;
}

MASSTOR_LIST DIPTOO_PVDEMA
# ifdef __STDC__
(MASSTOR_LIST C_216_A)
# else
(C_216_A)
MASSTOR_LIST C_216_A;
# endif
{
  MASSTOR_LIST AP, B, BL, BP, BPP, F, G, I, J, K, P, RL, TL;

  RL = MASSTOR_LENGTH(C_216_A);
  P = MASSTOR_BETA;
  if (RL == 0) {
    return P;
  }
  G = MASSTOR_LIST1(MASSTOR_BETA);
  AP = SACLIST_CINV(C_216_A);
  {
    LONGINT B_7 = 1, B_8 = RL;

    if (B_7 <= B_8)
      for (I = B_7;; I += 1) {
        K = 0;
        B = MASSTOR_BETA;
        F = G;
        BP = AP;
        {
          LONGINT B_9 = 1, B_10 = RL;

          if (B_9 <= B_10)
            for (J = B_9;; J += 1) {
              MASSTOR_ADV(BP, &BL, &BPP);
              TL = DIPTOO_LBLXCO(F, BL);
              if (TL < 0) {
                K = J;
                B = BP;
                F = BL;
              }
              BP = BPP;
              if (J >= B_10) break;
            }
        }
        P = MASSTOR_COMP(K, P);
        MASSTOR_SFIRST(B, G);
        if (I >= B_8) break;
      }
  }
  return P;
}

void BEGIN_DIPTOO()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACCOMB();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_SACDPOL();
    BEGIN_LINALGRN();

  }
}
