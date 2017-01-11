#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPCJ
#include "DIPCJ.h"
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

#ifndef DEFINITION_DIPIIB
#include "DIPIIB.h"
#endif

CHAR DIPIIB_rcsid [] = "$Id: DIPIIB.md,v 1.1 1995/10/12 14:44:56 pesch Exp $";
CHAR DIPIIB_copyright [] = "Copyright (c) 1995 Universitaet Passau";

static struct S_1 {
    MASLISPU_PROCP2V2 Select;
} DIPIIBOpt;
static MASLISPU_PROCP2V2 Select;
static CHAR rcsidi [] = "$Id: DIPIIB.mi,v 1.1 1995/10/12 14:44:57 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
static void DIIPNFJ2 ARGS((MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, MASSTOR_LIST *c));
static MASSTOR_LIST DIILISJ2 ARGS((MASSTOR_LIST P));


MASSTOR_LIST DIPIIB_DIIPNFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST RPP, MASSTOR_LIST S)
# else
(P, RPP, S)
MASSTOR_LIST P, RPP, S;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, R, RP, RS, SL, SP, TA, TE, r;

  if (S == 0) {
    R = RPP;
    return R;
  }
  if (P == MASSTOR_SIL) {
    if (RPP == 0) {
      R = S;
    } else {
      R = SACLIST_CCONC(RPP, S);
    }
    return R;
  }
  SP = S;
  R = RPP;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPCJ_EVMTJ(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      RP = DIPC_DIPFMO(TA, TE);
      if (R == 0) {
        R = RP;
      } else {
        RS = SACLIST_LAST(R);
        MASSTOR_SRED(RS, RP);
      }
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        SACI_IGCDCF(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPI_DIIPPR(QP, AP);
        SP = DIPI_DIIPIP(SP, BL);
        R = DIPI_DIIPIP(R, BL);
        SP = DIPI_DIIPDF(SP, APP);
      }
    }
  } while (!(SP == 0));
  return R;
}

MASSTOR_LIST DIPIIB_DIILISJ
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, EL, FL, IRR, LL, PL, PP, PS, RP, SL;

  PP = P;
  PS = MASSTOR_SIL;
  while (PP != MASSTOR_SIL) {
    MASSTOR_ADV(PP, &PL, &PP);
    DIPI_DIIPCP(PL, &CL, &PL);
    if (PL != 0) {
      PS = MASSTOR_COMP(PL, PS);
    }
  }
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  if (LL <= 1) {
    return PP;
  }
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    EL = DIPC_DIPEVL(PL);
    PL = DIPIIB_DIIPNFJ(PP, 0, PL);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_1;
      }
    } else {
      FL = DIPC_DIPEVL(PL);
      SL = DIPC_EVSIGN(FL);
      if (SL == 0) {
        PP = MASSTOR_LIST1(PL);
        goto EXIT_1;
      }
      SL = SACLIST_EQUAL(EL, FL);
      if (SL == 1) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        DIPI_DIIPCP(PL, &CL, &PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_1;
    }
  } EXIT_1:;
  MASBIOS_BLINES(1);
  SACLIST_AWRITE(LL);
  MASBIOS_SWRITE("  irreducible polynomials.", 26L);
  MASBIOS_BLINES(1);
  return PP;
}

MASSTOR_LIST DIPIIB_DIIPCOM
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, FLAG, EL;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  G = DIPIIB_DIILISJ(F);
  do {
    H = G;
    TDG = DIPCJ_DILTDG(H);
    FLAG = TRUE;
    while (H != MASSTOR_SIL && FLAG) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPNML(h);
      while (NM != MASSTOR_SIL && FLAG) {
        MASSTOR_ADV(NM, &nm, &NM);
        p = DIPCJ_DIRPMV(h, nm);
        if (DIPCJ_DILTDG(MASSTOR_COMP(p, EL)) <= TDG) {
          f = DIPIIB_DIIPNFJ(G, 0, p);
          if (f != 0) {
            G = DIPIIB_DIILISJ(MASSTOR_COMP(f, G));
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPIIB_DIIPIB2
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, EL;
  BOOLEAN FLAG;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  G = DIPIIB_DIIPCOM(F);
  do {
    H = G;
    TDG = DIPCJ_DILTDG(H);
    FLAG = TRUE;
    while (H != MASSTOR_SIL && FLAG) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPNML(h);
      while (NM != MASSTOR_SIL && FLAG) {
        MASSTOR_ADV(NM, &nm, &NM);
        p = DIPCJ_DIRPMV(h, nm);
        if (DIPCJ_DILTDG(MASSTOR_COMP(p, EL)) > TDG) {
          f = DIPIIB_DIIPNFJ(G, 0, p);
          if (f != 0) {
            G = DIPIIB_DIIPCOM(MASSTOR_COMP(f, G));
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPIIB_DIIPIB3
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, H, h, NM, nm, f, VL, le;

  G = MASSTOR_SIL;
  if (F == MASSTOR_SIL) {
    return G;
  }
  VL = DIPCJ_DIPVL(MASSTOR_FIRST(F));
  le = MASSTOR_LENGTH(VL) + 1;
  while (F != MASSTOR_SIL) {
    G = DIPIIB_DIILISJ(SACLIST_CONC(F, G));
    F = MASSTOR_SIL;
    H = G;
    while (H != MASSTOR_SIL) {
      MASSTOR_ADV(H, &h, &H);
      NM = DIPCJ_DIPPGL3(h, VL, le);
      while (NM != MASSTOR_SIL) {
        MASSTOR_ADV(NM, &nm, &NM);
        f = DIPIIB_DIIPNFJ(G, 0, nm);
        if (f != 0) {
          F = MASSTOR_COMP(f, F);
        }
      }
    }
  }
  return G;
}

MASSTOR_LIST DIPIIB_DIIPPR2
# ifdef __STDC__
(MASSTOR_LIST C_120_A, MASSTOR_LIST B)
# else
(C_120_A, B)
MASSTOR_LIST C_120_A, B;
# endif
{
  MASSTOR_LIST AL, AS, BL, BS, C, CL, EL, FL, GL;

  if (C_120_A == 0 || B == 0) {
    C = 0;
    return C;
  }
  AS = SACLIST_CINV(C_120_A);
  BS = B;
  C = MASSTOR_SIL;
  DIPC_DIPMAD(BS, &BL, &FL, &BS);
  do {
    DIPC_DIPMAD(AS, &EL, &AL, &AS);
    CL = SACI_IPROD(AL, BL);
    GL = DIPC_EVSUM(EL, FL);
    C = SACLIST_COMP2(GL, CL, C);
  } while (!(AS == MASSTOR_SIL));
  return C;
}

static void DIIPNFJ2
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, MASSTOR_LIST *c)
# else
(P, S, R, c)
MASSTOR_LIST P, S;
MASSTOR_LIST *R, *c;
# endif
{
  MASSTOR_LIST AL, AP, APP, BL, CL, FL, PP, Q, QA, QE, QP, RP, RS, SL, SP, TA, TE, r, deg, tdg;

  *R = 0;
  *c = 0;
  if (S != 0 && P != MASSTOR_SIL) {
    DIPCJ_ADVTDG(S, &deg, &SP);
    do {
      DIPC_DIPMAD(SP, &TA, &TE, &SP);
      if (SP == MASSTOR_SIL) {
        SP = 0;
      }
      PP = P;
      do {
        MASSTOR_ADV(PP, &Q, &PP);
        DIPCJ_ADVTDG(Q, &tdg, &Q);
        DIPC_DIPMAD(Q, &QA, &QE, &QP);
        SL = DIPCJ_EVMTJ(TE, QE);
      } while (!(PP == MASSTOR_SIL || SL == 1));
      if (SL == 0) {
        RP = DIPC_DIPFMO(TA, TE);
        if (*R == 0) {
          *R = RP;
        } else {
          RS = SACLIST_LAST(*R);
          MASSTOR_SRED(RS, RP);
        }
      } else {
        if (QP != MASSTOR_SIL) {
          FL = DIPCJ_EVDIF2(TE, QE);
          SACI_IGCDCF(TA, QA, &CL, &AL, &BL);
          if (FL != 0) {
            AP = DIPC_DIPFMO(AL, FL);
            APP = DIPIIB_DIIPPR2(QP, AP);
          } else {
            APP = DIPI_DIIPIP(QP, AL);
          }
          SP = DIPI_DIIPIP(SP, BL);
          *R = DIPI_DIIPIP(*R, BL);
          SP = DIPI_DIIPDF(SP, APP);
          *c = 1;
        }
      }
    } while (!(SP == 0));
  }
  if (*R != 0) {
    if (*c == 1) {
      *R = DIPCJ_ADDTDG(DIPC_EVTDEG(MASSTOR_FIRST(*R)), *R);
    } else {
      *R = DIPCJ_ADDTDG(deg, *R);
    }
  }
}

static MASSTOR_LIST DIILISJ2
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, IRR, LL, PL, pl, PP, PS, RP, SL, H;

  PS = SACLIST_CINV(P);
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  for (;;) {
    MASSTOR_ADV(PP, &PL, &PP);
    DIIPNFJ2(PP, PL, &PL, &SL);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        goto EXIT_2;
      }
    } else {
      if (SL == 0) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        DIPCJ_ADVTDG(PL, &pl, &PL);
        DIPI_DIIPCP(PL, &CL, &PL);
        PL = DIPCJ_ADDTDG(pl, PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (IRR == LL) {
      goto EXIT_2;
    }
  } EXIT_2:;
  return PP;
}

MASSTOR_LIST DIPIIB_DIIPIB
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, g, NM, nm, f, T, LL, VL, le, PL, CL, PS, r, tdg;

  G = MASSTOR_SIL;
  VL = DIPCJ_DIPVL(MASSTOR_FIRST(F));
  le = MASSTOR_LENGTH(VL) + 1;
  PS = DIPCJ_DIILPP(F);
  PS = DIPCJ_DILATDG(PS);
  F = PS;
  if (F == MASSTOR_SIL) {
    return G;
  }
  G = DIILISJ2(F);
  for (;;) {
    (*Select)(G, TRUE, &g, &G);
    if (MASSTOR_FIRST(g) == 0) {
      goto EXIT_3;
    }
    NM = DIPCJ_DIPPGL2(g, VL, le);
    DIPCJ_ADVTDG(g, &tdg, &g);
    g = MASSTOR_COMP(0, g);
    G = MASSTOR_COMP(g, G);
    if (NM != MASSTOR_SIL) {
      G = SACLIST_CONC(NM, G);
      G = DIILISJ2(G);
    }
  } EXIT_3:;
  G = MASSTOR_COMP(g, G);
  PS = DIPCJ_DILEP2P(G);
  return PS;
}

void DIPIIB_InitDIPIIB
# ifdef __STDC__
()
# else
()
# endif
{
  DIPIIB_SetDIPIIBSelect(1);
  Select = DIPCJ_DIPSSM;
}

void DIPIIB_SetDIPIIBSelect
# ifdef __STDC__
(INTEGER SEL)
# else
(SEL)
INTEGER SEL;
# endif
{
  switch (SEL) {
  case 1:;
    DIPIIBOpt.Select = DIPCJ_DIPSSM;
    break;
  default :
    MASERR_ERROR(MASERR_harmless, "DIPIIB.SetSelect: Unknown option number", 39L);
    break;
  }
}

void BEGIN_DIPIIB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPCJ();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_SACI();
    BEGIN_SACLIST();

    DIPIIB_InitDIPIIB();
  }
}
