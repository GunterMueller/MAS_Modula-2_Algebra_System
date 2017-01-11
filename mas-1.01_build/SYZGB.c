#include "SYSTEM_.h"

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

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

#ifndef DEFINITION_SYZHLP
#include "SYZHLP.h"
#endif

#ifndef DEFINITION_SYZGB
#include "SYZGB.h"
#endif

CHAR SYZGB_rcsid [] = "$Id: SYZGB.md,v 1.3 1992/10/16 13:58:13 kredel Exp $";
CHAR SYZGB_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SYZGB.mi,v 1.4 1994/03/11 15:45:19 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SYZGB_MGB
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ)
# else
(PM, SANZ)
MASSTOR_LIST PM, SANZ;
# endif
{
  MASSTOR_LIST L, PL, GB;

  if (MASSTOR_LENGTH(PM) == 1) {
    return PM;
  }
  L = MASSTOR_LENGTH(MASSTOR_FIRST(PM));
  PL = SYZHLP_MTPLV(PM, &L);
  if (MASSTOR_LENGTH(PL) == 1) {
    PM = SYZHLP_PLVTM(PL, L);
    return PM;
  }
  SYZHLP_ALFA(L);
  GB = SYZGB_GBE(PL, SANZ, L);
  SYZHLP_ALFRA(L);
  PM = SYZHLP_PLVTM(GB, L);
  return PM;
}

MASSTOR_LIST SYZGB_NLMGB
# ifdef __STDC__
(MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST *T)
# else
(PM, SANZ, T)
MASSTOR_LIST PM, SANZ;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST L, PL, GB;

  if (MASSTOR_LENGTH(PM) == 1) {
    return PM;
  }
  L = MASSTOR_LENGTH(MASSTOR_FIRST(PM));
  PL = SYZHLP_MTPLV(PM, &L);
  if (MASSTOR_LENGTH(PL) == 1) {
    PM = SYZHLP_PLVTM(PL, L);
    return PM;
  }
  SYZHLP_ALFA(L);
  *T = SYZHLP_TA(L, *T);
  GB = SYZGB_NLGBE(PL, SANZ, L, T);
  *T = SYZHLP_TR(L, *T);
  SYZHLP_ALFRA(L);
  PM = SYZHLP_PLVTM(GB, L);
  return PM;
}

MASSTOR_LIST SYZGB_GBE
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST TF, MASSTOR_LIST L)
# else
(P, TF, L)
MASSTOR_LIST P, TF, L;
# endif
{
  MASSTOR_LIST B, C, CPI, CPJ, CPP, CR, D, DL, EL, ELI, ELJ, H, IL, J1Y, K, PLI, PLIP, PLJ, PP, PPP, PPR, PS, Q, QP, RL, S, VL, RL1, SL, T, TR, X3, X4, XC, XH, XS, XT, YD, ZD;

  if (P == MASSTOR_SIL) {
    PP = P;
    return PP;
  }
  PS = P;
  PPR = MASSTOR_SIL;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &PLI, &PS);
    if (PLI != 0) {
      PLIP = DIPRN_DIRPMC(PLI);
      SL = DIPRN_DIRPON(PLIP);
      if (SL == 1) {
        PP = MASSTOR_LIST1(PLIP);
        return PP;
      }
      PPR = MASSTOR_COMP(PLIP, PPR);
    }
  }
  PP = MASSTOR_INV(PPR);
  if (PP == MASSTOR_SIL || MASSTOR_RED(PP) == MASSTOR_SIL) {
    return PP;
  }
  VL = DIPC_VALIS;
  if (VL == MASSTOR_SIL) {
    TF = 0;
  } else {
    RL = DIPC_DIPNOV(MASSTOR_FIRST(PP));
    RL1 = MASSTOR_LENGTH(VL);
    if (RL1 < RL) {
      VL = MASSTOR_INV(DIPC_STVL(RL - RL1));
      VL = SACLIST_CCONC(DIPC_VALIS, VL);
    }
  }
  T = MASSTOR_TIME();
  XH = 0;
  XS = 0;
  X3 = 0;
  X4 = 0;
  PPR = DIPC_DIPLPM(PP);
  PP = MASSTOR_INV(PPR);
  DIPRNGB_DILCPL(PP, &D, &B);
  YD = MASSTOR_LENGTH(D);
  for (;;) {
    if (D == MASSTOR_SIL) {
      goto EXIT_1;
    }
    YD = YD - 1;
    MASSTOR_ADV(D, &DL, &D);
    SACLIST_FIRST3(DL, &EL, &CPI, &CPJ);
    MASSTOR_ADV(CPI, &QP, &C);
    PLI = MASSTOR_FIRST(QP);
    J1Y = MASSTOR_RED(CPJ);
    PLJ = MASSTOR_FIRST(J1Y);
    J1Y = MASSTOR_RED(CPJ);
    CPP = MASSTOR_RED(J1Y);
    MASSTOR_SRED(CPJ, CPP);
    if (CPP == MASSTOR_SIL) {
      Q = SACLIST_LAST(QP);
      MASSTOR_SFIRST(C, Q);
    }
    for (;;) {
      if (SYZHLP_EVT(PLI, PLJ, L) != 1) {
        goto EXIT_2;
      }
      X3 = X3 + 1;
      SL = DIPRNGB_DIGBC3(B, PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_2;
      }
      X4 = X4 + 1;
      SL = DIPRNGB_DIGBC4(PLI, PLJ, EL);
      if (SL == 0) {
        goto EXIT_2;
      }
      XS = XS + 1;
      S = DIPRNGB_DIRPSP(PLI, PLJ);
      if (S == 0) {
        goto EXIT_2;
      }
      XH = XH + 1;
      H = DIPRNGB_DIRPNF(PP, S);
      if (H == 0) {
        goto EXIT_2;
      }
      H = DIPRN_DIRPMC(H);
      SL = DIPRN_DIRPON(H);
      if (SL == 1) {
        PP = MASSTOR_LIST1(H);
        return PP;
      }
      if (TF >= 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - T);
        MASBIOS_SWRITE(" S, ", 4L);
        SACLIST_AWRITE(XH);
        MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
        SACLIST_AWRITE(YD);
        MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
        MASBIOS_BLINES(0);
        MASBIOS_SWRITE("H=", 2L);
        DIPRN_DIRPWR(H, VL, -1);
        MASBIOS_BLINES(0);
      }
      if (TF >= 2) {
        SACLIST_AWRITE(X3);
        MASBIOS_SWRITE(" CRIT3,  ", 9L);
        SACLIST_AWRITE(X4);
        MASBIOS_SWRITE(" CRIT4,  ", 9L);
        SACLIST_AWRITE(XS);
        MASBIOS_SWRITE(" SPOLY,  ", 9L);
        MASBIOS_BLINES(1);
      }
      D = DIPRNGB_DILUPL(H, PP, D, B);
      YD = MASSTOR_LENGTH(D);
      goto EXIT_2;
    } EXIT_2:;
  } EXIT_1:;
  if (TF >= 1) {
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE(" S, ", 4L);
    SACLIST_AWRITE(XH);
    MASBIOS_SWRITE(" H-POLYNOMIALS, ", 16L);
    SACLIST_AWRITE(YD);
    MASBIOS_SWRITE(" PAIRS LEFT.", 12L);
    MASBIOS_BLINES(0);
  }
  if (TF >= 2) {
    SACLIST_AWRITE(X3);
    MASBIOS_SWRITE(" CRIT3,  ", 9L);
    SACLIST_AWRITE(X4);
    MASBIOS_SWRITE(" CRIT4,  ", 9L);
    SACLIST_AWRITE(XS);
    MASBIOS_SWRITE(" SPOLY,  ", 9L);
    MASBIOS_BLINES(1);
  }
  PP = DIPRNGB_DIGBMI(PP);
  return PP;
}

MASSTOR_LIST SYZGB_GBF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST *GBTM)
# else
(PL, SANZ, GBTM)
MASSTOR_LIST PL, SANZ;
MASSTOR_LIST *GBTM;
# endif
{
  MASSTOR_LIST P1, P2, PPL, B, SP, SP1, SPAK, SPN, SPFL, SZ, C1, C2, C3, TW2;

  SYZHLP_NORMF(&PL, GBTM);
  DIPRNGB_DILCPL(PL, &PPL, &B);
  C3 = MASSTOR_LENGTH(PPL);
  SZ = MASSTOR_TIME();
  C2 = 0;
  C1 = 0;
  for (;;) {
    if (PPL == MASSTOR_SIL) {
      goto EXIT_3;
    }
    C3 = C3 - 1;
    SYZHLP_NEXTPAIR(&P1, &P2, &PPL);
    for (;;) {
      C2 = C2 + 1;
      SYZFUNC_SPC(P1, P2, &SPFL, &SP);
      SP1 = SP;
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0 ", 9L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_4;
      }
      C1 = C1 + 1;
      SPAK = SYZFUNC_RCSPR(PL, &SP);
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-Red ", 13L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_4;
      }
      SPN = DIPRN_DIRPMC(SP);
      TW2 = DIPRN_DIRPON(SPN);
      *GBTM = SYZFUNC_BGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, *GBTM);
      if (TW2 == 1) {
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(SPN));
        return PL;
      }
      if (SANZ == 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - SZ);
        MASBIOS_SWRITE(" sec.  Neu ", 11L);
        MASBIOS_BLINES(0);
      }
      if (SANZ == 2) {
        SYZHLP_WRS1(SZ, C1, C2, C3);
      }
      if (SANZ == 3) {
        SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
      }
      PPL = DIPRNGB_DILUPL(SPN, PL, PPL, B);
      C3 = MASSTOR_LENGTH(PPL);
      goto EXIT_4;
    } EXIT_4:;
  } EXIT_3:;
  if (SANZ == 2) {
    SYZHLP_WRS1(SZ, C1, C2, C3);
  }
  if (SANZ == 3) {
    SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
  }
  return PL;
}

MASSTOR_LIST SYZGB_GBEF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST L, MASSTOR_LIST *GBTM)
# else
(PL, SANZ, L, GBTM)
MASSTOR_LIST PL, SANZ, L;
MASSTOR_LIST *GBTM;
# endif
{
  MASSTOR_LIST P1, P2, PPL, B, SPFL, SP, SP1, SZ, C1, C2, C3, SPN, SPAK, TW2;

  SYZHLP_NORMF(&PL, GBTM);
  DIPRNGB_DILCPL(PL, &PPL, &B);
  C3 = MASSTOR_LENGTH(PPL);
  SZ = MASSTOR_TIME();
  C2 = 0;
  C1 = 0;
  for (;;) {
    if (PPL == MASSTOR_SIL) {
      goto EXIT_5;
    }
    C3 = C3 - 1;
    SYZHLP_NEXTPAIR(&P1, &P2, &PPL);
    for (;;) {
      if (SYZHLP_EVT(P1, P2, L) != 1) {
        goto EXIT_6;
      }
      C2 = C2 + 1;
      SYZFUNC_SPC(P1, P2, &SPFL, &SP);
      SP1 = SP;
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0 ", 9L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_6;
      }
      C1 = C1 + 1;
      SPAK = SYZFUNC_RCSPR(PL, &SP);
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-Red ", 13L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_6;
      }
      SPN = DIPRN_DIRPMC(SP);
      TW2 = DIPRN_DIRPON(SPN);
      *GBTM = SYZFUNC_BGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, *GBTM);
      if (TW2 == 1) {
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(SPN));
        return PL;
      }
      if (SANZ == 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - SZ);
        MASBIOS_SWRITE(" sec.  Neu ", 11L);
        MASBIOS_BLINES(0);
      }
      if (SANZ == 2) {
        SYZHLP_WRS1(SZ, C1, C2, C3);
      }
      if (SANZ == 3) {
        SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
      }
      PPL = DIPRNGB_DILUPL(SPN, PL, PPL, B);
      C3 = MASSTOR_LENGTH(PPL);
      goto EXIT_6;
    } EXIT_6:;
  } EXIT_5:;
  if (SANZ == 2) {
    SYZHLP_WRS1(SZ, C1, C2, C3);
  }
  if (SANZ == 3) {
    SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
  }
  return PL;
}

MASSTOR_LIST SYZGB_NLGBE
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST L, MASSTOR_LIST *T)
# else
(PL, SANZ, L, T)
MASSTOR_LIST PL, SANZ, L;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST P1, P2, PPL, B, SP, SPN, SZ, C1, C2, C3, TW1, TW2;

  DIPRNGB_DILCPL(PL, &PPL, &B);
  C3 = MASSTOR_LENGTH(PPL);
  SZ = MASSTOR_TIME();
  C2 = 0;
  C1 = 0;
  for (;;) {
    if (PPL == MASSTOR_SIL) {
      goto EXIT_7;
    }
    C3 = C3 - 1;
    SYZHLP_NEXTPAIR(&P1, &P2, &PPL);
    for (;;) {
      if (SYZHLP_EVT(P1, P2, L) != 1) {
        goto EXIT_8;
      }
      C2 = C2 + 1;
      SP = MASNCGB_DINLSP(*T, P1, P2);
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-MGB ", 13L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_8;
      }
      C1 = C1 + 1;
      SPN = MASNCGB_DINLNF(*T, PL, SP);
      if (SPN == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-RedMGB ", 16L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_8;
      }
      SPN = DIPRN_DIRPMC(SPN);
      TW2 = DIPRN_DIRPON(SPN);
      if (TW2 == 1) {
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(SPN));
        return PL;
      }
      if (SANZ == 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - SZ);
        MASBIOS_SWRITE(" sec.  Neu-MGB ", 15L);
        MASBIOS_BLINES(0);
      }
      if (SANZ == 2) {
        SYZHLP_WRS1(SZ, C1, C2, C3);
      }
      PPL = DIPRNGB_DILUPL(SPN, PL, PPL, B);
      C3 = MASSTOR_LENGTH(PPL);
      goto EXIT_8;
    } EXIT_8:;
  } EXIT_7:;
  if (SANZ == 2) {
    SYZHLP_WRS1(SZ, C1, C2, C3);
  }
  PL = MASNCGB_DINLIS(*T, PL);
  return PL;
}

MASSTOR_LIST SYZGB_NLGBF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST *GBTM, MASSTOR_LIST *T)
# else
(PL, SANZ, GBTM, T)
MASSTOR_LIST PL, SANZ;
MASSTOR_LIST *GBTM, *T;
# endif
{
  MASSTOR_LIST P1, P2, PPL, B, SPFL, SP, SP1, SPN, SZ, C1, C2, C3, TW1, TW2, SPAK;

  SYZHLP_NORMF(&PL, GBTM);
  DIPRNGB_DILCPL(PL, &PPL, &B);
  C3 = MASSTOR_LENGTH(PPL);
  SZ = MASSTOR_TIME();
  C2 = 0;
  C1 = 0;
  for (;;) {
    if (PPL == MASSTOR_SIL) {
      goto EXIT_9;
    }
    C3 = C3 - 1;
    SYZHLP_NEXTPAIR(&P1, &P2, &PPL);
    for (;;) {
      C2 = C2 + 1;
      SYZFUNC_NLSPC(P1, P2, &SPFL, &SP, T);
      SP1 = SP;
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0 ", 9L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_10;
      }
      C1 = C1 + 1;
      SPAK = SYZFUNC_NLRCSPR(PL, &SP, T);
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-Red ", 13L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_10;
      }
      SPN = DIPRN_DIRPMC(SP);
      TW2 = DIPRN_DIRPON(SPN);
      *GBTM = SYZFUNC_NLBGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, *GBTM, T);
      if (TW2 == 1) {
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(SPN));
        return PL;
      }
      if (SANZ == 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - SZ);
        MASBIOS_SWRITE(" sec.  Neu ", 11L);
        MASBIOS_BLINES(0);
      }
      if (SANZ == 2) {
        SYZHLP_WRS1(SZ, C1, C2, C3);
      }
      if (SANZ == 3) {
        SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
      }
      PPL = DIPRNGB_DILUPL(SPN, PL, PPL, B);
      C3 = MASSTOR_LENGTH(PPL);
      goto EXIT_10;
    } EXIT_10:;
  } EXIT_9:;
  if (SANZ == 2) {
    SYZHLP_WRS1(SZ, C1, C2, C3);
  }
  if (SANZ == 3) {
    SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
  }
  return PL;
}

MASSTOR_LIST SYZGB_NLGBEF
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST L, MASSTOR_LIST *GBTM, MASSTOR_LIST *T)
# else
(PL, SANZ, L, GBTM, T)
MASSTOR_LIST PL, SANZ, L;
MASSTOR_LIST *GBTM, *T;
# endif
{
  MASSTOR_LIST P1, P2, PPL, B, SPFL, SP, SP1, SPN, SZ, C1, C2, C3, TW2, SPAK;

  SYZHLP_NORMF(&PL, GBTM);
  DIPRNGB_DILCPL(PL, &PPL, &B);
  C3 = MASSTOR_LENGTH(PPL);
  SZ = MASSTOR_TIME();
  C2 = 0;
  C1 = 0;
  for (;;) {
    if (PPL == MASSTOR_SIL) {
      goto EXIT_11;
    }
    C3 = C3 - 1;
    SYZHLP_NEXTPAIR(&P1, &P2, &PPL);
    for (;;) {
      if (SYZHLP_EVT(P1, P2, L) != 1) {
        goto EXIT_12;
      }
      C2 = C2 + 1;
      SYZFUNC_NLSPC(P1, P2, &SPFL, &SP, T);
      SP1 = SP;
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0 ", 9L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_12;
      }
      C1 = C1 + 1;
      SPAK = SYZFUNC_NLRCSPR(PL, &SP, T);
      if (SP == 0) {
        if (SANZ == 1) {
          SACLIST_AWRITE(MASSTOR_TIME() - SZ);
          MASBIOS_SWRITE(" sec.  0-Red ", 13L);
          MASBIOS_BLINES(0);
        }
        goto EXIT_12;
      }
      SPN = DIPRN_DIRPMC(SP);
      TW2 = DIPRN_DIRPON(SPN);
      *GBTM = SYZFUNC_NLBGFUP(P1, P2, SP, SPN, SPFL, PL, SPAK, *GBTM, T);
      if (TW2 == 1) {
        PL = SACLIST_CCONC(PL, MASSTOR_LIST1(SPN));
        return PL;
      }
      if (SANZ == 1) {
        SACLIST_AWRITE(MASSTOR_TIME() - SZ);
        MASBIOS_SWRITE(" sec.  Neu ", 11L);
        MASBIOS_BLINES(0);
      }
      if (SANZ == 2) {
        SYZHLP_WRS1(SZ, C1, C2, C3);
      }
      if (SANZ == 3) {
        SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
      }
      PPL = DIPRNGB_DILUPL(SPN, PL, PPL, B);
      C3 = MASSTOR_LENGTH(PPL);
      goto EXIT_12;
    } EXIT_12:;
  } EXIT_11:;
  if (SANZ == 2) {
    SYZHLP_WRS1(SZ, C1, C2, C3);
  }
  if (SANZ == 3) {
    SYZHLP_WRS2(SZ, C1, SPN, C2, SP1, C3);
  }
  return PL;
}

void BEGIN_SYZGB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_DIPC();
    BEGIN_DIPRN();
    BEGIN_DIPRNGB();
    BEGIN_MASBIOS();
    BEGIN_MASNC();
    BEGIN_MASNCGB();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SYZFUNC();
    BEGIN_SYZHLP();

  }
}
