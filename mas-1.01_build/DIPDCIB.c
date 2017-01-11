#include "SYSTEM_.h"

#ifndef DEFINITION_ADEXTRA
#include "ADEXTRA.h"
#endif

#ifndef DEFINITION_DIPADOM
#include "DIPADOM.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPCJ
#include "DIPCJ.h"
#endif

#ifndef DEFINITION_DIPIB
#include "DIPIB.h"
#endif

#ifndef DEFINITION_MASBIOS
#include "MASBIOS.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACI
#include "SACI.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_DIPDCIB
#include "DIPDCIB.h"
#endif

CHAR DIPDCIB_rcsidi [] = "$Id: DIPDCIB.md,v 1.1 1995/10/12 14:44:48 pesch Exp $";
CHAR DIPDCIB_copyrighti [] = "Copyright (c) 1995 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPDCIB.mi,v 1.1 1995/10/12 14:44:50 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static struct S_1 {
    INTEGER TraceLevel;
    MASLISPU_PROCF2 DecompProc;
    INTEGER VarOrdOpt;
    INTEGER depth;
} DCIBopt;
static MASSTOR_LIST RECIB1 ARGS((MASSTOR_LIST G, MASSTOR_LIST Fcmp));
static MASSTOR_LIST RECIB2 ARGS((MASSTOR_LIST G, MASSTOR_LIST Fcmp));
static MASSTOR_LIST newFactors ARGS((MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp, MASSTOR_LIST V));
static MASSTOR_LIST SortF ARGS((MASSTOR_LIST F));
static BOOLEAN ZeroPoly ARGS((MASSTOR_LIST G));

static MASSTOR_LIST *G_1_FNodes;
static MASSTOR_LIST *G_2_le;
static MASSTOR_LIST *G_3_VL;
static MASSTOR_LIST *G_4_counter;
static MASSTOR_LIST *G_5_t;
static MASSTOR_LIST *G_6_T;
static INTEGER *G_7_eqn;
static INTEGER *G_8_lc;
static INTEGER *G_9_depth;
static INTEGER *G_10_nocb;
static BOOLEAN *G_11_Factorisation;
static BOOLEAN *G_12_dummy;
static MASSTOR_LIST *G_13_V;

void DIPDCIB_SetDCIBopt
# ifdef __STDC__
(MASSTOR_LIST options)
# else
(options)
MASSTOR_LIST options;
# endif
{
  INTEGER opt;

  if (options != MASSTOR_SIL) {
    MASSTOR_ADV(options, &opt, &options);
    DIPDCIB_SetDCIBTraceLevel(opt);
    if (options != MASSTOR_SIL) {
      MASSTOR_ADV(options, &opt, &options);
      DIPDCIB_SetDCIBDecomp(opt);
      if (options != MASSTOR_SIL) {
        MASSTOR_ADV(options, &opt, &options);
        DIPDCIB_SetDCIBVarOrdOpt(opt);
        if (options != MASSTOR_SIL) {
          MASSTOR_ADV(options, &opt, &options);
          DIPDCIB_SetDCIBdepth(opt);
        }
      }
    }
  }
}

void DIPDCIB_SetDCIBTraceLevel
# ifdef __STDC__
(INTEGER TL)
# else
(TL)
INTEGER TL;
# endif
{
  DCIBopt.TraceLevel = TL;
}

void DIPDCIB_SetDCIBDecomp
# ifdef __STDC__
(INTEGER DCP)
# else
(DCP)
INTEGER DCP;
# endif
{
  switch (DCP) {
  case 1:;
    DCIBopt.DecompProc = DIPADOM_DIPFAC;
    break;
  case 2:;
    DCIBopt.DecompProc = DIPADOM_DIPSFF;
    break;
  default :
    MASERR_ERROR(MASERR_harmless, "SetDecompProc: unknown Decomp option", 36L);
    break;
  }
}

void DIPDCIB_SetDCIBVarOrdOpt
# ifdef __STDC__
(INTEGER VOO)
# else
(VOO)
INTEGER VOO;
# endif
{
  if (VOO < 0 || VOO > 1) {
    MASERR_ERROR(MASERR_harmless, "SetVarOrdOpt: unknown VarOrdOpt option", 38L);
  } else {
    DCIBopt.VarOrdOpt = VOO;
  }
}

void DIPDCIB_SetDCIBdepth
# ifdef __STDC__
(INTEGER d)
# else
(d)
INTEGER d;
# endif
{
  if (d < 0) {
    DCIBopt.depth = -1;
  } else {
    DCIBopt.depth = d;
  }
}

static MASSTOR_LIST RECIB1
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST Fcmp)
# else
(G, Fcmp)
MASSTOR_LIST G, Fcmp;
# endif
{
  MASSTOR_LIST H, g, HTg, HTf, G1, F, IBList, IBL, IBLFirst, f, B;
  INTEGER c;

  H = MASSTOR_SIL;
  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (DIPC_DIPTDG(g) == 0) {
      if (DCIBopt.TraceLevel > 1) {
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("** branch w.o. zeros ", 21L);
        *G_10_nocb = *G_10_nocb + 1;
      }
      return MASSTOR_SIL;
    }
    G1 = SACLIST_CCONC(G, H);
    F = newFactors(G1, g, Fcmp, *G_13_V);
    if (F == MASSTOR_SIL) {
      if (DCIBopt.TraceLevel > 1) {
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("** cancel branch", 16L);
        *G_10_nocb = *G_10_nocb + 1;
      }
      return MASSTOR_SIL;
    }
    MASSTOR_ADV(F, &f, &F);
    if (F == MASSTOR_SIL) {
      HTg = DIPC_DIPEVL(g);
      HTf = DIPC_DIPEVL(f);
      if (SACLIST_EQUAL(HTg, HTf) == 1) {
        H = MASSTOR_COMP(f, H);
      } else {
        DIPIB_DILISJ(MASSTOR_COMP(f, G1), &G, G_12_dummy);
        H = MASSTOR_SIL;
      }
    } else {
      IBList = MASSTOR_SIL;
      IBLFirst = MASSTOR_SIL;
      DIPDCIB_IncCounter(G_4_counter, G_8_lc, 0);
      for (;;) {
        DIPIB_DILISJ(MASSTOR_COMP(f, G1), &G, G_12_dummy);
        if (DCIBopt.TraceLevel > 2) {
          DIPDCIB_IncCounter(G_4_counter, G_8_lc, 1);
          MASBIOS_BLINES(0);
          DIPDCIB_CounterWR(*G_4_counter);
          MASBIOS_SWRITE(" Factor: ", 9L);
          DIPADOM_DIWRIT(f, *G_13_V);
          MASBIOS_BLINES(0);
          DIPADOM_DILWR(G, *G_13_V);
        }
        if (*G_9_depth != *G_8_lc) {
          IBList = SACLIST_CONC(IBList, RECIB1(G, Fcmp));
        } else {
          if (DCIBopt.TraceLevel > 1) {
            MASBIOS_BLINES(0);
            MASBIOS_SWRITE("** depth maximum reached; cancel branch", 39L);
          }
        }
        if (F == MASSTOR_SIL) {
          goto EXIT_1;
        }
        Fcmp = MASSTOR_COMP(f, Fcmp);
        MASSTOR_ADV(F, &f, &F);
      } EXIT_1:;
      DIPDCIB_DecCounter(G_4_counter, G_8_lc);
      return IBList;
    }
  }
  return RECIB2(H, Fcmp);
}

static MASSTOR_LIST RECIB2
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST Fcmp)
# else
(G, Fcmp)
MASSTOR_LIST G, Fcmp;
# endif
{
  MASSTOR_LIST S, h, F, f, H, B, K, g, GG;
  BOOLEAN red, reduced;

  K = MASSTOR_SIL;
  red = FALSE;
  if (*G_1_FNodes != MASSTOR_SIL && !*G_11_Factorisation) {
    *G_1_FNodes = MASSTOR_RED(*G_1_FNodes);
  }
  for (;;) {
    if (G == MASSTOR_SIL) {
      goto EXIT_2;
    }
    DIPCJ_DIPSSM(G, FALSE, &g, &G);
    K = MASSTOR_COMP(g, K);
    B = DIPCJ_DIPPGL3(g, *G_3_VL, *G_2_le);
    H = MASSTOR_SIL;
    while (B != MASSTOR_SIL) {
      MASSTOR_ADV(B, &S, &B);
      DIPIB_ADPNFJ(SACLIST_CCONC(G, K), S, &h, &reduced);
      if (h != 0) {
        red = red || reduced;
        if (DIPC_DIPTDG(h) == 0) {
          return MASSTOR_SIL;
        }
        H = MASSTOR_COMP(h, H);
      }
    }
    if (H != MASSTOR_SIL) {
      G = SACLIST_CONC(H, G);
      DIPIB_DIPIRLJ2(&G, &K, &reduced);
      red = red || reduced;
      if (DCIBopt.TraceLevel > 2) {
        MASBIOS_BLINES(0);
        DIPDCIB_CounterWR(*G_4_counter);
        MASBIOS_SWRITE(" Prolongation & Reduction", 25L);
        DIPADOM_DILWR(SACLIST_CCONC(G, K), *G_13_V);
      }
      if (*G_9_depth != *G_8_lc) {
        if (red) {
          GG = SACLIST_CCONC(G, K);
          if (!ADEXTRA_ADLGinH(*G_1_FNodes, GG)) {
            *G_1_FNodes = MASSTOR_COMP(GG, *G_1_FNodes);
            *G_11_Factorisation = FALSE;
            return RECIB1(GG, Fcmp);
            *G_1_FNodes = MASSTOR_RED(*G_1_FNodes);
            goto EXIT_2;
          } else {
            if (DCIBopt.TraceLevel > 1) {
              MASBIOS_BLINES(0);
              MASBIOS_SWRITE("** equal nodes found", 20L);
              *G_7_eqn = *G_7_eqn + 1;
            }
          }
        }
      } else {
        *G_10_nocb = *G_10_nocb + 1;
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("** depth maximum reached; cancel branch", 39L);
        return MASSTOR_SIL;
      }
    }
  } EXIT_2:;
  if (DCIBopt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("= involutive base =", 19L);
    MASBIOS_BLINES(0);
    if (DCIBopt.TraceLevel > 2) {
      *G_5_t = MASSTOR_TIME() - *G_6_T;
      MASBIOS_SWRITE("Time: ", 6L);
      SACI_IWRITE(*G_5_t);
      DIPADOM_DILWR(K, *G_13_V);
      MASBIOS_BLINES(0);
    }
  }
  return MASSTOR_LIST1(K);
}

static MASSTOR_LIST newFactors
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST h, MASSTOR_LIST Fcmp, MASSTOR_LIST V)
# else
(G, h, Fcmp, V)
MASSTOR_LIST G, h, Fcmp, V;
# endif
{
  MASSTOR_LIST Fnew, F, hi, FL, g, C_106_h, G1;
  BOOLEAN reduced;

  Fnew = MASSTOR_SIL;
  F = (*DCIBopt.DecompProc)(h, DCIBopt.VarOrdOpt);
  if (MASSTOR_LENGTH(F) > 1) {
    *G_11_Factorisation = TRUE;
  }
  F = SortF(F);
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &hi, &F);
    G1 = MASSTOR_COMP(hi, G);
    FL = Fcmp;
    for (;;) {
      if (FL == MASSTOR_SIL) {
        Fnew = MASSTOR_COMP(hi, Fnew);
        Fcmp = MASSTOR_COMP(hi, Fcmp);
        goto EXIT_3;
      }
      MASSTOR_ADV(FL, &g, &FL);
      DIPIB_ADPNFJ(G1, g, &h, &reduced);
      if (h == 0) {
        if (DCIBopt.TraceLevel > 1) {
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("** cancel factor ", 17L);
          DIPADOM_DIWRIT(g, V);
          *G_10_nocb = *G_10_nocb + 1;
        }
        goto EXIT_3;
      }
    } EXIT_3:;
  }
  return MASSTOR_INV(Fnew);
}

MASSTOR_LIST DIPDCIB_InvolutiveBases
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST V)
# else
(G, V)
MASSTOR_LIST G, V;
# endif
{
  MASSTOR_LIST IBList, T, t, Fcmp, counter, VL, le, FNodes;
  INTEGER nocb, depth, lc, eqn;
  BOOLEAN C_105_dummy, Factorisation;
  MASSTOR_LIST *L_1;
  MASSTOR_LIST *L_2;
  MASSTOR_LIST *L_3;
  MASSTOR_LIST *L_4;
  MASSTOR_LIST *L_5;
  MASSTOR_LIST *L_6;
  INTEGER *L_7;
  INTEGER *L_8;
  INTEGER *L_9;
  INTEGER *L_10;
  BOOLEAN *L_11;
  BOOLEAN *L_12;
  MASSTOR_LIST *L_13;

  L_1 = G_1_FNodes;
  G_1_FNodes = &FNodes;
  L_2 = G_2_le;
  G_2_le = &le;
  L_3 = G_3_VL;
  G_3_VL = &VL;
  L_4 = G_4_counter;
  G_4_counter = &counter;
  L_5 = G_5_t;
  G_5_t = &t;
  L_6 = G_6_T;
  G_6_T = &T;
  L_7 = G_7_eqn;
  G_7_eqn = &eqn;
  L_8 = G_8_lc;
  G_8_lc = &lc;
  L_9 = G_9_depth;
  G_9_depth = &depth;
  L_10 = G_10_nocb;
  G_10_nocb = &nocb;
  L_11 = G_11_Factorisation;
  G_11_Factorisation = &Factorisation;
  L_12 = G_12_dummy;
  G_12_dummy = &C_105_dummy;
  L_13 = G_13_V;
  G_13_V = &V;
  if (G == MASSTOR_SIL) {
    MASERR_ERROR(MASERR_severe, "IB1: undefined ideal", 20L);
  }
  if (ZeroPoly(G)) {
    MASERR_ERROR(MASERR_severe, "IB1: zero polynomial", 20L);
  }
  T = MASSTOR_TIME();
  DIPC_VALIS = V;
  Fcmp = MASSTOR_SIL;
  counter = MASSTOR_SIL;
  lc = 0;
  nocb = 0;
  eqn = 0;
  depth = DCIBopt.depth;
  DIPIB_DILISJ(G, &G, &C_105_dummy);
  VL = DIPCJ_DIPVL(MASSTOR_FIRST(G));
  le = MASSTOR_LENGTH(VL) + 1;
  FNodes = MASSTOR_SIL;
  Factorisation = FALSE;
  IBList = RECIB1(G, Fcmp);
  if (DCIBopt.TraceLevel > 0) {
    t = MASSTOR_TIME() - T;
    if (DCIBopt.TraceLevel > 1) {
      MASBIOS_BLINES(0);
      MASBIOS_SWRITE("Number of canceled branches/factors: ", 37L);
      SACI_IWRITE(nocb);
      MASBIOS_BLINES(0);
      SACI_IWRITE(eqn);
      MASBIOS_SWRITE(" equal nodes found.", 19L);
    }
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Time: ", 6L);
    SACI_IWRITE(t);
    MASBIOS_SWRITE("ms ", 3L);
    if (DCIBopt.TraceLevel > 2) {
      DIPDCIB_IBLWR(IBList, V);
    }
  }
  G_1_FNodes = L_1;
  G_2_le = L_2;
  G_3_VL = L_3;
  G_4_counter = L_4;
  G_5_t = L_5;
  G_6_T = L_6;
  G_7_eqn = L_7;
  G_8_lc = L_8;
  G_9_depth = L_9;
  G_10_nocb = L_10;
  G_11_Factorisation = L_11;
  G_12_dummy = L_12;
  G_13_V = L_13;
  return IBList;
}

static MASSTOR_LIST SortF
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST Fnew, ExpPol;

  Fnew = MASSTOR_SIL;
  while (F != MASSTOR_SIL) {
    MASSTOR_ADV(F, &ExpPol, &F);
    Fnew = MASSTOR_COMP(SACLIST_SECOND(ExpPol), Fnew);
  }
  return MASSTOR_INV(DIPC_DIPLPM(Fnew));
}

static BOOLEAN ZeroPoly
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  MASSTOR_LIST g;

  while (G != MASSTOR_SIL) {
    MASSTOR_ADV(G, &g, &G);
    if (g == 0) {
      return TRUE;
    }
  }
  return FALSE;
}

void DIPDCIB_DecCounter
# ifdef __STDC__
(MASSTOR_LIST *counter, INTEGER *length_of_counter)
# else
(counter, length_of_counter)
MASSTOR_LIST *counter;
INTEGER *length_of_counter;
# endif
{
  if (*length_of_counter > 0) {
    *counter = MASSTOR_RED(*counter);
    *length_of_counter = *length_of_counter - 1;
  }
}

void DIPDCIB_IncCounter
# ifdef __STDC__
(MASSTOR_LIST *counter, INTEGER *loc, INTEGER add)
# else
(counter, loc, add)
MASSTOR_LIST *counter;
INTEGER *loc;
INTEGER add;
# endif
{
  INTEGER c;

  if (add == 0) {
    *counter = MASSTOR_COMP(0, *counter);
    *loc = *loc + 1;
  } else {
    MASSTOR_ADV(*counter, &c, counter);
    c = c + add;
    *counter = MASSTOR_COMP(c, *counter);
  }
}

void DIPDCIB_CounterWR
# ifdef __STDC__
(MASSTOR_LIST counter)
# else
(counter)
MASSTOR_LIST counter;
# endif
{
  MASSTOR_LIST C, c;

  if (counter != MASSTOR_SIL) {
    C = SACLIST_CINV(counter);
  } else {
    C = MASSTOR_SIL;
  }
  while (C != MASSTOR_SIL) {
    MASSTOR_ADV(C, &c, &C);
    SACI_IWRITE(c);
    if (C != MASSTOR_SIL) {
      MASBIOS_SWRITE(".", 1L);
    } else {
      MASBIOS_SWRITE(" ", 1L);
    }
  }
}

void DIPDCIB_IBLWR
# ifdef __STDC__
(MASSTOR_LIST PP, MASSTOR_LIST V)
# else
(PP, V)
MASSTOR_LIST PP, V;
# endif
{
  MASSTOR_LIST ib;
  INTEGER i, j;

  i = 0;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &ib, &PP);
    i = i + 1;
    j = MASSTOR_LENGTH(ib);
    MASBIOS_BLINES(0);
    SACI_IWRITE(i);
    MASBIOS_SWRITE(". IB with ", 10L);
    SACI_IWRITE(j);
    if (j > 1) {
      MASBIOS_SWRITE(" polynoms", 9L);
    } else {
      MASBIOS_SWRITE(" polynom", 8L);
    }
    DIPADOM_DILWR(ib, V);
  }
}

void BEGIN_DIPDCIB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_ADEXTRA();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPCJ();
    BEGIN_DIPIB();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_SACI();
    BEGIN_SACLIST();

    DIPDCIB_SetDCIBopt(SACLIST_LIST4(0, 1, 0, -1));
  }
}
