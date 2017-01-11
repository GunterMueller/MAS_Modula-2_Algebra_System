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

#ifndef DEFINITION_DIPTOOLS
#include "DIPTOOLS.h"
#endif

#ifndef DEFINITION_MASADOM
#include "MASADOM.h"
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

#ifndef DEFINITION_DIPIB
#include "DIPIB.h"
#endif

CHAR DIPIB_rcsid [] = "$Id: DIPIB.md,v 1.2 1995/12/16 12:21:53 kredel Exp $";
CHAR DIPIB_copyright [] = "Copyright (c) 1995 Universitaet Passau";

#define maxdom	30
typedef struct S_1 {
    MASLISPU_PROCP2V2 NFJ;
    MASLISPU_PROCP2V2 NFJ2;
    DIPIB_PROCP5V2 NFJ3;
} DomainRecord;
static struct S_2 {
    DomainRecord A[maxdom - 1 + 1];
} Jdomain;
static struct S_3 {
    INTEGER TraceLevel;
    MASLISPU_PROCP1V2 ISJ;
    MASLISPU_PROCP2V2 Select;
    MASLISPU_PROCF1 Cancel;
    BOOLEAN Crit;
} DIPIBOpt;
static MASLISPU_PROCP2V2 Select;
static CHAR rcsidi [] = "$Id: DIPIB.mi,v 1.1 1995/10/12 14:44:53 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1995 Universitaet Passau";
#define C_138_int	2
#define C_134_no	4
struct S_4 {
    MASSTOR_LIST A[C_134_no - 1 + 1];
};
#define no	4
struct S_5 {
    MASSTOR_LIST A[no - 1 + 1];
};


MASSTOR_LIST DIPIB_ADCAN
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  INTEGER dom;

  if (P == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  dom = DIPTOOLS_ADDNFDIP(P);
  if (dom == C_138_int) {
    P = ADEXTRA_ADPCP(P);
  } else {
    P = DIPADOM_DIPMOC(P);
  }
  return P;
}

void DIPIB_ADPNFJ
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(G, P, h, reduced)
MASSTOR_LIST G, P;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST DomNum;

  DomNum = DIPTOOLS_ADDNFDIP(P);
  if (DomNum == 0) {
    *h = 0;
    *reduced = FALSE;
  } else {
    (*Jdomain.A[(INTEGER)DomNum - 1].NFJ)(G, P, h, reduced);
  }
}

void DIPIB_DIPNFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(P, S, h, reduced)
MASSTOR_LIST P, S;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE;

  *reduced = FALSE;
  *h = 0;
  if (S == 0 || P == MASSTOR_SIL) {
    return;
  }
  R = MASSTOR_SIL;
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
      SL = DIPCJ_EVMTJ(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = MASADOM_ADQUOT(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPDIF(SP, APP);
        *reduced = TRUE;
      }
    }
  } while (!(SP == 0));
  if (R == MASSTOR_SIL) {
    *h = 0;
  } else {
    *h = MASSTOR_INV(R);
  }
}

void DIPIB_DIPINFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(P, S, h, reduced)
MASSTOR_LIST P, S;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE, AL, CL, RP, RS;

  *reduced = FALSE;
  *h = 0;
  if (S == 0 || P == MASSTOR_SIL) {
    return;
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
        MASADOM_ADGCDC(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPBCP(SP, BL);
        R = DIPADOM_DIPBCP(R, BL);
        SP = DIPADOM_DIPDIF(SP, APP);
        *reduced = TRUE;
      }
    }
  } while (!(SP == 0));
  *h = R;
}

void DIPIB_DILISJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *PP, BOOLEAN *reduced)
# else
(P, PP, reduced)
MASSTOR_LIST P;
MASSTOR_LIST *PP;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST IRR, LL, PL, PS, RP, T;

  T = MASSTOR_TIME();
  PS = SACLIST_CINV(P);
  RP = PS;
  *PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(*PP);
  IRR = 0;
  if (LL <= 1) {
    return;
  }
  if (DIPIBOpt.TraceLevel > 2) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("**irr: ", 7L);
  }
  do {
    MASSTOR_ADV(*PP, &PL, PP);
    DIPIB_ADPNFJ(*PP, PL, &PL, reduced);
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        return;
      }
    } else {
      if (!*reduced) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        PL = (*DIPIBOpt.Cancel)(PL);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
    if (DIPIBOpt.TraceLevel > 2) {
      SACLIST_AWRITE(IRR);
      MASBIOS_SWRITE(", ", 2L);
    }
  } while (!(IRR == LL));
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Janet-Reduction in ", 19L);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, with", 8L);
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(LL);
    MASBIOS_SWRITE(" irreducible polynomials", 24L);
  }
  return;
}

void DIPIB_DIPIRLJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *F, BOOLEAN *reduced)
# else
(P, F, reduced)
MASSTOR_LIST P;
MASSTOR_LIST *F;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST H, f, g, HTg, HTf, T, LL;
  BOOLEAN NewHT;

  *F = P;
  if (DIPIBOpt.TraceLevel > 2) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("**irr: ", 7L);
  }
  do {
    if (DIPIBOpt.TraceLevel > 2) {
      LL = MASSTOR_LENGTH(*F);
      SACLIST_AWRITE(LL);
      MASBIOS_SWRITE(", ", 2L);
    }
    H = MASSTOR_SIL;
    NewHT = FALSE;
    while (*F != MASSTOR_SIL) {
      MASSTOR_ADV(*F, &f, F);
      HTf = DIPC_DIPEVL(f);
      DIPIB_ADPNFJ(SACLIST_CCONC(*F, H), f, &g, reduced);
      if (g != 0) {
        g = (*DIPIBOpt.Cancel)(g);
        if (*reduced) {
          HTg = DIPC_DIPEVL(g);
          if (SACLIST_EQUAL(HTg, HTf) != 1) {
            NewHT = TRUE;
          }
        }
        H = MASSTOR_COMP(g, H);
      }
    }
    *F = H;
  } while (!!NewHT);
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Janet-Reduction in ", 19L);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, ", 4L);
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(MASSTOR_LENGTH(*F));
    MASBIOS_SWRITE(" irreducible polynoms ", 22L);
  }
}

MASSTOR_LIST DIPIB_DIPCOM
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, EL;
  BOOLEAN FLAG, reduced;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  (*DIPIBOpt.ISJ)(F, &G, &reduced);
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
          DIPIB_ADPNFJ(G, p, &f, &reduced);
          if (f != 0) {
            f = (*DIPIBOpt.Cancel)(f);
            (*DIPIBOpt.ISJ)(MASSTOR_COMP(f, G), &G, &reduced);
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPIB_DIPIB2
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST f, h, p, G, H, TDG, NM, nm, EL;
  BOOLEAN FLAG, reduced;

  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  EL = MASSTOR_SIL;
  F = DIPCJ_DILCAN(F, DIPIBOpt.Cancel);
  G = DIPIB_DIPCOM(F);
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
          DIPIB_ADPNFJ(G, p, &f, &reduced);
          if (f != 0) {
            f = (*DIPIBOpt.Cancel)(f);
            G = DIPIB_DIPCOM(MASSTOR_COMP(f, G));
            FLAG = FALSE;
          }
        }
      }
    }
  } while (!(H == MASSTOR_SIL && FLAG));
  return G;
}

MASSTOR_LIST DIPIB_DIPIB3
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, H, h, NM, nm, f, T, VL, le, C_137_T;
  BOOLEAN reduced;

  T = MASSTOR_TIME();
  G = MASSTOR_SIL;
  F = DIPCJ_DILCAN(F, DIPIBOpt.Cancel);
  VL = DIPCJ_DIPVL(MASSTOR_FIRST(F));
  le = MASSTOR_LENGTH(VL) + 1;
  while (F != MASSTOR_SIL) {
    (*DIPIBOpt.ISJ)(SACLIST_CONC(F, G), &G, &reduced);
    F = MASSTOR_SIL;
    H = G;
    while (H != MASSTOR_SIL) {
      if (DIPIBOpt.TraceLevel > 2) {
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(MASSTOR_LENGTH(H));
        MASBIOS_SWRITE(" polynomials to consider ", 25L);
      }
      (*DIPIBOpt.Select)(H, FALSE, &h, &H);
      NM = DIPCJ_DIPPGL3(h, VL, le);
      if (DIPIBOpt.TraceLevel > 2) {
        MASBIOS_BLINES(0);
        SACLIST_AWRITE(MASSTOR_LENGTH(NM));
        MASBIOS_SWRITE(" prolongations, ", 16L);
      }
      while (NM != MASSTOR_SIL) {
        MASSTOR_ADV(NM, &nm, &NM);
        DIPIB_ADPNFJ(G, nm, &f, &reduced);
        if (f != 0) {
          if (reduced) {
            f = (*DIPIBOpt.Cancel)(f);
          }
          F = MASSTOR_COMP(f, F);
        }
      }
    }
  }
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(1);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE(" ms ", 4L);
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Involutive Base with ", 21L);
    SACLIST_AWRITE(MASSTOR_LENGTH(G));
    MASBIOS_SWRITE(" polynomials", 12L);
  }
  return G;
}

void DIPIB_ADEPNFJ
# ifdef __STDC__
(MASSTOR_LIST G, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(G, P, h, reduced)
MASSTOR_LIST G, P;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST DomNum;

  if (P == MASSTOR_SIL) {
    DomNum = 0;
  } else {
    DomNum = DIPTOOLS_ADDNFDIP(SACLIST_SECOND(P));
  }
  if (DomNum == 0) {
    *h = 0;
    *reduced = FALSE;
  } else {
    (*Jdomain.A[(INTEGER)DomNum - 1].NFJ2)(G, P, h, reduced);
  }
}

void DIPIB_DIPENFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, BOOLEAN *c)
# else
(P, S, R, c)
MASSTOR_LIST P, S;
MASSTOR_LIST *R;
BOOLEAN *c;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, SL, SP, TA, TE, deg, tdg, term, HT;

  *c = FALSE;
  if (S == 0 || P == MASSTOR_SIL) {
    *R = S;
    return;
  }
  *R = MASSTOR_SIL;
  DIPIB_ADEPCrumble(S, &deg, &SP, &term);
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      Q = DIPIB_ADEPpolynomial(Q);
      DIPC_DIPMAD(Q, &QA, &QE, &QP);
      SL = DIPCJ_EVMTJ(TE, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 0) {
      *R = DIPC_DIPMCP(TE, TA, *R);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = MASADOM_ADQUOT(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPDIF(SP, APP);
        *c = TRUE;
      }
    }
  } while (!(SP == 0));
  if (*R == MASSTOR_SIL) {
    *R = 0;
  } else {
    *R = MASSTOR_INV(*R);
  }
  if (*R != 0) {
    if (*c) {
      *R = DIPIB_ADEPCompose(DIPC_EVTDEG(MASSTOR_FIRST(*R)), *R, term);
    } else {
      *R = DIPIB_ADEPCompose(deg, *R, term);
    }
  }
}

void DIPIB_DIPEINFJ
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, BOOLEAN *c)
# else
(P, S, R, c)
MASSTOR_LIST P, S;
MASSTOR_LIST *R;
BOOLEAN *c;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, PP, Q, QA, QE, QP, SL, SP, TA, TE, AL, CL, RP, RS, deg, term, HT;

  *c = FALSE;
  if (S == 0 || P == MASSTOR_SIL) {
    *R = S;
    return;
  }
  *R = 0;
  DIPIB_ADEPCrumble(S, &deg, &SP, &term);
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP = P;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      Q = DIPIB_ADEPpolynomial(Q);
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
        FL = DIPC_EVDIF(TE, QE);
        MASADOM_ADGCDC(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPBCP(SP, BL);
        *R = DIPADOM_DIPBCP(*R, BL);
        SP = DIPADOM_DIPDIF(SP, APP);
        *c = TRUE;
      }
    }
  } while (!(SP == 0));
  if (*R != 0) {
    if (*c) {
      *R = DIPIB_ADEPCompose(DIPC_EVTDEG(MASSTOR_FIRST(*R)), *R, term);
    } else {
      *R = DIPIB_ADEPCompose(deg, *R, term);
    }
  }
}

BOOLEAN DIPIB_IsInvolutive
# ifdef __STDC__
(MASSTOR_LIST G)
# else
(G)
MASSTOR_LIST G;
# endif
{
  return MASSTOR_FIRST(G) == 0;
}

MASSTOR_LIST DIPIB_ADEPmark
# ifdef __STDC__
(MASSTOR_LIST g, MASSTOR_LIST G)
# else
(g, G)
MASSTOR_LIST g, G;
# endif
{
  INTEGER tdg;

  DIPCJ_ADVTDG(g, &tdg, &g);
  g = MASSTOR_COMP(0, g);
  G = MASSTOR_COMP(g, G);
  return G;
}

MASSTOR_LIST DIPIB_DILISJ2
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST EL, FL, IRR, LL, PL, PP, PS, RP, pl, T, deg, pol, term;
  BOOLEAN reduced;

  T = MASSTOR_TIME();
  PS = SACLIST_CINV(P);
  RP = PS;
  PP = MASSTOR_INV(PS);
  LL = MASSTOR_LENGTH(PP);
  IRR = 0;
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("**irr: ", 7L);
  }
  if (LL <= 1) {
    return PP;
  }
  do {
    MASSTOR_ADV(PP, &PL, &PP);
    DIPIB_ADEPNFJ(PP, PL, &PL, &reduced);
    if (DIPIBOpt.TraceLevel > 2) {
      SACLIST_AWRITE(LL);
      MASBIOS_SWRITE(", ", 2L);
    }
    if (PL == 0) {
      LL = LL - 1;
      if (LL <= 1) {
        return PP;
      }
    } else {
      if (!reduced) {
        IRR = IRR + 1;
      } else {
        IRR = 0;
        DIPIB_ADEPCrumble(PL, &deg, &pol, &term);
        pol = (*DIPIBOpt.Cancel)(pol);
        PL = DIPIB_ADEPCompose(deg, pol, term);
      }
      PS = MASSTOR_LIST1(PL);
      MASSTOR_SRED(RP, PS);
      RP = PS;
    }
  } while (!(IRR == LL));
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    MASBIOS_SWRITE("Janet-Reduction in ", 19L);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, ", 4L);
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(LL);
    MASBIOS_SWRITE(" irreducible polynomials", 24L);
  }
  return PP;
}

MASSTOR_LIST DIPIB_ADEPtriple
# ifdef __STDC__
(MASSTOR_LIST PS, MASSTOR_LIST term)
# else
(PS, term)
MASSTOR_LIST PS, term;
# endif
{
  MASSTOR_LIST L, P, C_136_term, deg, triple, ht;

  L = MASSTOR_SIL;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &P, &PS);
    ht = MASSTOR_FIRST(P);
    deg = DIPC_EVTDEG(ht);
    if (term == MASSTOR_SIL) {
      triple = DIPIB_ADEPCompose(deg, P, ht);
    } else {
      triple = DIPIB_ADEPCompose(deg, P, term);
    }
    L = MASSTOR_COMP(triple, L);
  }
  return L;
}

MASSTOR_LIST DIPIB_ADEPuntriple
# ifdef __STDC__
(MASSTOR_LIST PS)
# else
(PS)
MASSTOR_LIST PS;
# endif
{
  MASSTOR_LIST L, P, pol;

  L = MASSTOR_SIL;
  while (PS != MASSTOR_SIL) {
    MASSTOR_ADV(PS, &P, &PS);
    pol = DIPIB_ADEPpolynomial(P);
    L = MASSTOR_COMP(pol, L);
  }
  return L;
}

void DIPIB_ADEPCrumble
# ifdef __STDC__
(MASSTOR_LIST P, MASSTOR_LIST *deg, MASSTOR_LIST *pol, MASSTOR_LIST *ht)
# else
(P, deg, pol, ht)
MASSTOR_LIST P;
MASSTOR_LIST *deg, *pol, *ht;
# endif
{
  *deg = 0;
  *pol = MASSTOR_SIL;
  *ht = MASSTOR_SIL;
  if (P != MASSTOR_SIL) {
    MASSTOR_ADV(P, deg, &P);
    if (P != MASSTOR_SIL) {
      MASSTOR_ADV(P, pol, &P);
      if (P != MASSTOR_SIL) {
        MASSTOR_ADV(P, ht, &P);
      }
    }
  }
}

MASSTOR_LIST DIPIB_ADEPCompose
# ifdef __STDC__
(MASSTOR_LIST deg, MASSTOR_LIST pol, MASSTOR_LIST ht)
# else
(deg, pol, ht)
MASSTOR_LIST deg, pol, ht;
# endif
{
  MASSTOR_LIST P;

  if (DIPIBOpt.Crit) {
    return SACLIST_LIST3(deg, pol, ht);
  } else {
    return SACLIST_LIST2(deg, pol);
  }
}

MASSTOR_LIST DIPIB_ADEPdegree
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  return MASSTOR_FIRST(P);
}

MASSTOR_LIST DIPIB_ADEPpolynomial
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  return SACLIST_SECOND(P);
}

MASSTOR_LIST DIPIB_ADEPheadterm
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  return SACLIST_THIRD(P);
}

MASSTOR_LIST DIPIB_ADEPleadingterm
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  return MASSTOR_FIRST(SACLIST_SECOND(P));
}

MASSTOR_LIST DIPIB_IBcrit
# ifdef __STDC__
(MASSTOR_LIST NM, MASSTOR_LIST G)
# else
(NM, G)
MASSTOR_LIST NM, G;
# endif
{
  MASSTOR_LIST u, R, nm, deg, lm, PP, Q, QE, SL, v, lcm;
  BOOLEAN reduced;

  if (NM == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  u = DIPIB_ADEPheadterm(MASSTOR_FIRST(NM));
  R = MASSTOR_SIL;
  while (NM != MASSTOR_SIL) {
    MASSTOR_ADV(NM, &nm, &NM);
    deg = DIPIB_ADEPdegree(nm);
    lm = DIPIB_ADEPleadingterm(nm);
    PP = G;
    do {
      MASSTOR_ADV(PP, &Q, &PP);
      QE = DIPIB_ADEPleadingterm(Q);
      SL = DIPCJ_EVMTJ(lm, QE);
    } while (!(PP == MASSTOR_SIL || SL == 1));
    if (SL == 1) {
      v = DIPIB_ADEPheadterm(Q);
      if (!SACLIST_EQUAL(u, v)) {
        lcm = DIPC_EVLCM(u, v);
        if (!SACLIST_EQUAL(lcm, DIPC_EVSUM(u, v))) {
          if (DIPC_EVTDEG(lcm) >= deg) {
            DIPIB_ADEPNFJ(G, nm, &nm, &reduced);
            if (nm != 0) {
              DIPIB_ADEPCrumble(nm, &deg, &nm, &v);
              v = MASSTOR_FIRST(nm);
              nm = (*DIPIBOpt.Cancel)(nm);
              nm = DIPIB_ADEPCompose(deg, nm, v);
              R = MASSTOR_COMP(nm, R);
            }
          } else {
            if (DIPIBOpt.TraceLevel > 1) {
              MASBIOS_BLINES(0);
              MASBIOS_SWRITE("Criterium 3 used", 16L);
            }
          }
        } else {
          if (DIPIBOpt.TraceLevel > 1) {
            MASBIOS_BLINES(0);
            MASBIOS_SWRITE("Criterium 2 used", 16L);
          }
        }
      } else {
        if (DIPIBOpt.TraceLevel > 1) {
          MASBIOS_BLINES(0);
          MASBIOS_SWRITE("Criterium 1 used", 16L);
        }
      }
    } else {
      DIPIB_ADEPNFJ(G, nm, &nm, &reduced);
      if (nm != 0) {
        if (reduced) {
          DIPIB_ADEPCrumble(nm, &deg, &nm, &v);
          nm = (*DIPIBOpt.Cancel)(nm);
          nm = DIPIB_ADEPCompose(deg, nm, v);
        }
        R = MASSTOR_COMP(nm, R);
      }
    }
  }
  return R;
}

MASSTOR_LIST DIPIB_DIPIB
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, g, NM, nm, f, T, LL, VL, le, PL, CL, PS, r, C_135_T;
  BOOLEAN reduced;

  T = MASSTOR_TIME();
  G = MASSTOR_SIL;
  VL = DIPCJ_DIPVL(MASSTOR_FIRST(F));
  le = MASSTOR_LENGTH(VL) + 1;
  PS = DIPCJ_DILCAN(F, DIPIBOpt.Cancel);
  F = PS;
  if (F == MASSTOR_SIL) {
    return MASSTOR_SIL;
  }
  DIPIB_DILISJ(F, &G, &reduced);
  G = DIPIB_ADEPtriple(G, MASSTOR_SIL);
  for (;;) {
    (*Select)(G, TRUE, &g, &G);
    if (DIPIB_IsInvolutive(g)) {
      goto EXIT_1;
    }
    NM = DIPCJ_DIPPGL3(DIPIB_ADEPpolynomial(g), VL, le);
    G = DIPIB_ADEPmark(g, G);
    NM = DIPIB_ADEPtriple(NM, DIPIB_ADEPheadterm(g));
    if (DIPIBOpt.Crit) {
      NM = DIPIB_IBcrit(NM, G);
    }
    if (NM != MASSTOR_SIL) {
      G = SACLIST_CONC(NM, G);
      G = DIPIB_DILISJ2(G);
    }
  } EXIT_1:;
  G = MASSTOR_COMP(g, G);
  PS = DIPIB_ADEPuntriple(G);
  if (DIPIBOpt.TraceLevel > 0) {
    MASBIOS_BLINES(1);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, ", 4L);
    MASBIOS_SWRITE("involutive base with ", 21L);
    SACLIST_AWRITE(MASSTOR_LENGTH(PS));
    MASBIOS_SWRITE(" polynomials ", 13L);
  }
  return PS;
}

void DIPIB_ADPNFJS
# ifdef __STDC__
(MASSTOR_LIST G1, MASSTOR_LIST G2, MASSTOR_LIST G3, MASSTOR_LIST G4, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(G1, G2, G3, G4, P, h, reduced)
MASSTOR_LIST G1, G2, G3, G4, P;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST DomNum;

  if (P == MASSTOR_SIL) {
    DomNum = 0;
  } else {
    DomNum = DIPTOOLS_ADDNFDIP(P);
  }
  if (DomNum == 0) {
    *reduced = FALSE;
    *h = 0;
  } else {
    (*Jdomain.A[(INTEGER)DomNum - 1].NFJ3)(G1, G2, G3, G4, P, h, reduced);
  }
}

void DIPIB_DIPNFJS
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST P3, MASSTOR_LIST P4, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(P1, P2, P3, P4, S, h, reduced)
MASSTOR_LIST P1, P2, P3, P4, S;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, Q, QA, QE, QP, R, SL, SP, TA, TE;
  struct S_4 PP;
  CARDINAL i;

  *reduced = FALSE;
  *h = 0;
  if (S == 0 || P1 == MASSTOR_SIL && P2 == MASSTOR_SIL && P3 == MASSTOR_SIL && P4 == MASSTOR_SIL) {
    return;
  }
  R = MASSTOR_SIL;
  SP = S;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP.A[1 - 1] = P1;
    PP.A[2 - 1] = P2;
    PP.A[3 - 1] = P3;
    PP.A[4 - 1] = P4;
    i = 1;
    SL = 0;
    do {
      while (i < C_134_no && PP.A[i - 1] == MASSTOR_SIL) {
        i = i + 1;
      }
      while (PP.A[i - 1] != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP.A[i - 1], &Q, &PP.A[i - 1]);
        DIPC_DIPMAD(Q, &QA, &QE, &QP);
        SL = DIPCJ_EVMTJ(TE, QE);
      }
    } while (!(i == C_134_no || SL == 1));
    if (SL == 0) {
      R = DIPC_DIPMCP(TE, TA, R);
    } else {
      if (QP != MASSTOR_SIL) {
        FL = DIPC_EVDIF(TE, QE);
        BL = MASADOM_ADQUOT(TA, QA);
        AP = DIPC_DIPFMO(BL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPDIF(SP, APP);
        *reduced = TRUE;
      }
    }
  } while (!(SP == 0));
  if (R == MASSTOR_SIL) {
    *h = 0;
  } else {
    *h = MASSTOR_INV(R);
  }
}

void DIPIB_DIPINFJS
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST P3, MASSTOR_LIST P4, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced)
# else
(P1, P2, P3, P4, S, h, reduced)
MASSTOR_LIST P1, P2, P3, P4, S;
MASSTOR_LIST *h;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST AP, APP, BL, FL, Q, QA, QE, QP, R, SL, SP, TA, TE, AL, CL, RP, RS;
  struct S_5 PP;
  CARDINAL i;

  *reduced = FALSE;
  *h = S;
  if (S == 0 || P1 == MASSTOR_SIL && P2 == MASSTOR_SIL && P3 == MASSTOR_SIL && P4 == MASSTOR_SIL) {
    return;
  }
  R = 0;
  SP = S;
  do {
    DIPC_DIPMAD(SP, &TA, &TE, &SP);
    if (SP == MASSTOR_SIL) {
      SP = 0;
    }
    PP.A[1 - 1] = P1;
    PP.A[2 - 1] = P2;
    PP.A[3 - 1] = P3;
    PP.A[4 - 1] = P4;
    i = 1;
    SL = 0;
    do {
      while (i < no && PP.A[i - 1] == MASSTOR_SIL) {
        i = i + 1;
      }
      while (PP.A[i - 1] != MASSTOR_SIL && SL == 0) {
        MASSTOR_ADV(PP.A[i - 1], &Q, &PP.A[i - 1]);
        DIPC_DIPMAD(Q, &QA, &QE, &QP);
        SL = DIPCJ_EVMTJ(TE, QE);
      }
    } while (!(i == no || SL == 1));
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
        MASADOM_ADGCDC(TA, QA, &CL, &AL, &BL);
        AP = DIPC_DIPFMO(AL, FL);
        APP = DIPADOM_DIPROD(QP, AP);
        SP = DIPADOM_DIPBCP(SP, BL);
        R = DIPADOM_DIPBCP(R, BL);
        SP = DIPADOM_DIPDIF(SP, APP);
        *reduced = TRUE;
      }
    }
  } while (!(SP == 0));
  *h = R;
}

void DIPIB_DIPIRLJ2
# ifdef __STDC__
(MASSTOR_LIST *P, MASSTOR_LIST *Q, BOOLEAN *reduced)
# else
(P, Q, reduced)
MASSTOR_LIST *P, *Q;
BOOLEAN *reduced;
# endif
{
  MASSTOR_LIST F, G, H, I, f, g, HTg, HTf, T;
  BOOLEAN NewHT, FromG;

  T = MASSTOR_TIME();
  F = *P;
  G = *Q;
  do {
    H = MASSTOR_SIL;
    I = MASSTOR_SIL;
    NewHT = FALSE;
    while (F != MASSTOR_SIL || G != MASSTOR_SIL) {
      if (F != MASSTOR_SIL) {
        MASSTOR_ADV(F, &f, &F);
        FromG = FALSE;
      } else {
        MASSTOR_ADV(G, &f, &G);
        FromG = TRUE;
      }
      HTf = DIPC_DIPEVL(f);
      DIPIB_ADPNFJS(F, H, G, I, f, &g, reduced);
      if (g != 0) {
        if (*reduced) {
          HTg = DIPC_DIPEVL(g);
          g = (*DIPIBOpt.Cancel)(g);
          H = MASSTOR_COMP(g, H);
          if (SACLIST_EQUAL(HTg, HTf) != 1) {
            NewHT = TRUE;
          }
        } else {
          if (FromG) {
            I = MASSTOR_COMP(g, I);
          } else {
            H = MASSTOR_COMP(g, H);
          }
        }
      }
    }
    F = H;
    G = I;
  } while (!!NewHT);
  *Q = G;
  *P = F;
  if (DIPIBOpt.TraceLevel > 1) {
    MASBIOS_BLINES(0);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, ", 4L);
    SACLIST_AWRITE(MASSTOR_LENGTH(*Q) + MASSTOR_LENGTH(*P));
    MASBIOS_SWRITE(" irreducible polynoms ", 22L);
  }
}

MASSTOR_LIST DIPIB_DIPIB4
# ifdef __STDC__
(MASSTOR_LIST F)
# else
(F)
MASSTOR_LIST F;
# endif
{
  MASSTOR_LIST G, H, g, NM, VL, le, T;
  BOOLEAN reduced;

  T = MASSTOR_TIME();
  H = MASSTOR_SIL;
  g = MASSTOR_FIRST(F);
  VL = DIPCJ_DIPVL(g);
  le = MASSTOR_LENGTH(VL) + 1;
  F = DIPCJ_DILCAN(F, DIPIBOpt.Cancel);
  DIPIB_DIPIRLJ2(&F, &H, &reduced);
  G = F;
  for (;;) {
    if (G == MASSTOR_SIL) {
      goto EXIT_2;
    }
    (*DIPIBOpt.Select)(G, FALSE, &g, &G);
    H = MASSTOR_COMP(g, H);
    NM = DIPCJ_DIPPGL3(g, VL, le);
    if (NM != MASSTOR_SIL) {
      G = SACLIST_CONC(NM, G);
      DIPIB_DIPIRLJ2(&G, &H, &reduced);
    }
  } EXIT_2:;
  if (DIPIBOpt.TraceLevel > 0) {
    MASBIOS_BLINES(1);
    SACLIST_AWRITE(MASSTOR_TIME() - T);
    MASBIOS_SWRITE("ms, ", 4L);
    MASBIOS_SWRITE("involutive base with ", 21L);
    SACLIST_AWRITE(MASSTOR_LENGTH(H));
    MASBIOS_SWRITE(" polynomials.", 13L);
  }
  return H;
}

void DIPIB_SetDIPIBopt
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
    DIPIB_SetDIPIBTraceLevel(opt);
    if (options != MASSTOR_SIL) {
      MASSTOR_ADV(options, &opt, &options);
      DIPIB_SetDIPIBCancel(opt);
      if (options != MASSTOR_SIL) {
        MASSTOR_ADV(options, &opt, &options);
        DIPIB_SetDIPIBSelect(opt);
        if (options != MASSTOR_SIL) {
          MASSTOR_ADV(options, &opt, &options);
          DIPIB_SetDIPIBISJ(opt);
          if (options != MASSTOR_SIL) {
            MASSTOR_ADV(options, &opt, &options);
            DIPIB_SetDIPIBCrit(opt);
          }
        }
      }
    }
  }
}

void DIPIB_SetDIPIBTraceLevel
# ifdef __STDC__
(INTEGER level)
# else
(level)
INTEGER level;
# endif
{
  DIPIBOpt.TraceLevel = level;
}

void DIPIB_SetDIPIBCancel
# ifdef __STDC__
(CARDINAL Canc)
# else
(Canc)
CARDINAL Canc;
# endif
{
  switch (Canc) {
  case 1:;
    DIPIBOpt.Cancel = DIPIB_ADCAN;
    break;
  case 2:;
    DIPIBOpt.Cancel = DIPADOM_DIPMOC;
    break;
  default :
    MASERR_ERROR(MASERR_harmless, "DIPIB.SetCancel: Illegal number", 31L);
    break;
  }
}

void DIPIB_SetDIPIBSelect
# ifdef __STDC__
(INTEGER SEL)
# else
(SEL)
INTEGER SEL;
# endif
{
  switch (SEL) {
  case 1:;
    DIPIBOpt.Select = DIPCJ_DIPSSM;
    break;
  case 2:;
    DIPIBOpt.Select = DIPCJ_DIPFIRST;
    break;
  default :
    MASERR_ERROR(MASERR_harmless, "DIPIBSetSelect: Illegal number", 30L);
    break;
  }
}

void DIPIB_SetDIPIBISJ
# ifdef __STDC__
(INTEGER Sel)
# else
(Sel)
INTEGER Sel;
# endif
{
  switch (Sel) {
  case 1:;
    DIPIBOpt.ISJ = DIPIB_DILISJ;
    break;
  case 2:;
    DIPIBOpt.ISJ = DIPIB_DIPIRLJ;
    break;
  default :
    MASERR_ERROR(MASERR_harmless, "DIPIBSetISJ: Illegal number ", 28L);
    break;
  }
}

void DIPIB_SetDIPIBCrit
# ifdef __STDC__
(INTEGER crit)
# else
(crit)
INTEGER crit;
# endif
{
  if (crit == 1) {
    DIPIBOpt.Crit = TRUE;
  } else {
    DIPIBOpt.Crit = FALSE;
  }
}

void DIPIB_SetDomainNFJ
# ifdef __STDC__
()
# else
()
# endif
{
  INTEGER i;

  for (i = 1; i <= maxdom; i += 1) {
    Jdomain.A[(INTEGER)i - 1].NFJ = DIPIB_DIPNFJ;
    Jdomain.A[(INTEGER)i - 1].NFJ2 = DIPIB_DIPENFJ;
    Jdomain.A[(INTEGER)i - 1].NFJ3 = DIPIB_DIPNFJS;
  }
  Jdomain.A[(INTEGER)2 - 1].NFJ = DIPIB_DIPINFJ;
  Jdomain.A[(INTEGER)2 - 1].NFJ2 = DIPIB_DIPEINFJ;
  Jdomain.A[(INTEGER)2 - 1].NFJ3 = DIPIB_DIPINFJS;
  Jdomain.A[(INTEGER)3 - 1].NFJ = DIPIB_DIPINFJ;
  Jdomain.A[(INTEGER)3 - 1].NFJ2 = DIPIB_DIPEINFJ;
  Jdomain.A[(INTEGER)3 - 1].NFJ3 = DIPIB_DIPINFJS;
  Jdomain.A[(INTEGER)12 - 1].NFJ = DIPIB_DIPINFJ;
  Jdomain.A[(INTEGER)12 - 1].NFJ2 = DIPIB_DIPEINFJ;
  Jdomain.A[(INTEGER)12 - 1].NFJ3 = DIPIB_DIPINFJS;
}

void BEGIN_DIPIB()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_ADEXTRA();
    BEGIN_DIPADOM();
    BEGIN_DIPC();
    BEGIN_DIPCJ();
    BEGIN_DIPTOOLS();
    BEGIN_MASADOM();
    BEGIN_MASBIOS();
    BEGIN_MASERR();
    BEGIN_MASLISPU();
    BEGIN_MASSTOR();
    BEGIN_SACI();
    BEGIN_SACLIST();

    DIPIB_SetDomainNFJ();
    DIPIB_SetDIPIBopt(SACLIST_LIST5(0, 1, 1, 1, 1));
    Select = DIPCJ_DIPSSM;
  }
}
