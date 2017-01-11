#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASERR
#include "MASERR.h"
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

#ifndef DEFINITION_SACM
#include "SACM.h"
#endif

#ifndef DEFINITION_SACPRIM
#include "SACPRIM.h"
#endif

#ifndef DEFINITION_MASI
#include "MASI.h"
#endif

#ifndef DEFINITION_SACPOL
#include "SACPOL.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPE
#include "DIPE.h"
#endif

CHAR DIPE_rcsid [] = "$Id: DIPE.md,v 1.2 1992/02/12 17:33:26 pesch Exp $";
CHAR DIPE_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPE.mi,v 1.3 1992/10/15 16:29:45 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPE_COPYOB
# ifdef __STDC__
(MASSTOR_LIST C_172_A)
# else
(C_172_A)
MASSTOR_LIST C_172_A;
# endif
{
  MASSTOR_LIST AL, AP, B, BL;

  if (C_172_A <= MASSTOR_BETA) {
    B = C_172_A;
    return B;
  }
  AP = C_172_A;
  B = MASSTOR_SIL;
  do {
    MASSTOR_ADV(AP, &AL, &AP);
    BL = DIPE_COPYOB(AL);
    B = MASSTOR_COMP(BL, B);
  } while (!(AP == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

void DIPE_EIMWRT
# ifdef __STDC__
(MASSTOR_LIST C_171_A)
# else
(C_171_A)
MASSTOR_LIST C_171_A;
# endif
{
  MASSTOR_LIST AL, AS;

  MASBIOS_SWRITE("(", 1L);
  AS = C_171_A;
  while (AS != MASSTOR_SIL) {
    MASSTOR_ADV(AS, &AL, &AS);
    MASBIOS_SWRITE(" ", 1L);
    DIPE_EIVWRT(AL);
    if (AS != MASSTOR_SIL) {
      MASBIOS_BLINES(1);
    }
  }
  MASBIOS_SWRITE(" )", 2L);
  return;
}

MASSTOR_LIST DIPE_EIVABS
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST SL, V;

  SL = DIPE_EIVSIG(U);
  if (SL < 0) {
    V = DIPE_EIVNEG(U);
  } else {
    V = U;
  }
  return V;
}

MASSTOR_LIST DIPE_EIVAPP
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST V, VL;

  DIPE_EIVCPP(U, &V, &VL);
  V = DIPE_EIVABS(V);
  return V;
}

void DIPE_EIVCPP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST *V, MASSTOR_LIST *VL)
# else
(U, V, VL)
MASSTOR_LIST U;
MASSTOR_LIST *V, *VL;
# endif
{
  MASSTOR_LIST IL, UL, US;

  if (U == MASSTOR_SIL) {
    *V = MASSTOR_SIL;
    *VL = 0;
    return;
  }
  SACLIST_ADV2(U, VL, &IL, &US);
  while (US != MASSTOR_SIL && *VL != 1) {
    SACLIST_ADV2(US, &UL, &IL, &US);
    *VL = SACI_IGCD(UL, *VL);
  }
  if (*VL == 1) {
    *V = U;
  } else {
    *V = DIPE_EIVIQ(U, *VL);
  }
  return;
}

MASSTOR_LIST DIPE_EIVEPR
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP, WS;

  if (U == MASSTOR_SIL || V == MASSTOR_SIL) {
    W = MASSTOR_SIL;
    return W;
  }
  US = SACLIST_CINV(U);
  VS = SACLIST_CINV(V);
  W = MASSTOR_SIL;
  do {
    SACLIST_ADV2(US, &IL, &KL, &US);
    VP = VS;
    W1 = MASSTOR_SIL;
    do {
      SACLIST_ADV2(VP, &JL, &ML, &VP);
      DIPE_ILEXPR(IL, JL, &LL, &SL);
      if (SL != 0) {
        if (SL < 0) {
          ML = SACI_INEG(ML);
        }
        NL = MASI_IPROD(KL, ML);
        W1 = SACLIST_COMP2(NL, LL, W1);
      }
    } while (!(VP == MASSTOR_SIL));
    if (W1 != MASSTOR_SIL) {
      W = MASSTOR_COMP(W1, W);
    }
  } while (!(US == MASSTOR_SIL));
  if (W == MASSTOR_SIL) {
    return W;
  }
  do {
    WP = MASSTOR_SIL;
    while (W != MASSTOR_SIL && MASSTOR_RED(W) != MASSTOR_SIL) {
      SACLIST_ADV2(W, &WL1, &WL2, &W);
      WS = DIPE_EIVSUM(WL1, WL2);
      WP = MASSTOR_COMP(WS, WP);
    }
    if (WP != MASSTOR_SIL) {
      WPP = MASSTOR_INV(WP);
      MASSTOR_SRED(WP, W);
      W = WPP;
    }
  } while (!(MASSTOR_RED(W) == MASSTOR_SIL));
  W = MASSTOR_FIRST(W);
  return W;
}

MASSTOR_LIST DIPE_EIVFUP
# ifdef __STDC__
(MASSTOR_LIST C_170_A, MASSTOR_LIST PL)
# else
(C_170_A, PL)
MASSTOR_LIST C_170_A, PL;
# endif
{
  MASSTOR_LIST AL, AS, B, EL, FL, GL;

  B = MASSTOR_SIL;
  if (C_170_A == 0) {
    return B;
  }
  AS = C_170_A;
  do {
    SACLIST_ADV2(AS, &EL, &AL, &AS);
    FL = EL + PL;
    GL = MASSTOR_LIST1(FL);
    B = SACLIST_COMP2(AL, GL, B);
  } while (!(AS == MASSTOR_SIL));
  return B;
}

MASSTOR_LIST DIPE_EIVILP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP, WS;

  if (U == MASSTOR_SIL || V == MASSTOR_SIL) {
    W = MASSTOR_SIL;
    return W;
  }
  US = U;
  VS = V;
  W = MASSTOR_SIL;
  do {
    SACLIST_ADV2(US, &KL, &IL, &US);
    VP = VS;
    W1 = MASSTOR_SIL;
    do {
      SACLIST_ADV2(VP, &ML, &JL, &VP);
      DIPE_ILINPR(IL, JL, &LL, &SL);
      if (SL != 0) {
        if (SL < 0) {
          ML = SACI_INEG(ML);
        }
        NL = MASI_IPROD(KL, ML);
        W1 = SACLIST_COMP2(NL, LL, W1);
      }
    } while (!(VP == MASSTOR_SIL));
    if (W1 != MASSTOR_SIL) {
      W = MASSTOR_COMP(W1, W);
    }
  } while (!(US == MASSTOR_SIL));
  if (W == MASSTOR_SIL) {
    return W;
  }
  do {
    WP = MASSTOR_SIL;
    while (W != MASSTOR_SIL && MASSTOR_RED(W) != MASSTOR_SIL) {
      SACLIST_ADV2(W, &WL1, &WL2, &W);
      WS = DIPE_EIVSUM(WL1, WL2);
      WP = MASSTOR_COMP(WS, WP);
    }
    if (WP != MASSTOR_SIL) {
      WPP = MASSTOR_INV(WP);
      MASSTOR_SRED(WP, W);
      W = WPP;
    }
  } while (!(MASSTOR_RED(W) == MASSTOR_SIL));
  W = MASSTOR_FIRST(W);
  return W;
}

MASSTOR_LIST DIPE_EIVIP
# ifdef __STDC__
(MASSTOR_LIST C_169_A, MASSTOR_LIST BL)
# else
(C_169_A, BL)
MASSTOR_LIST C_169_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, PL, RL;

  C = MASSTOR_SIL;
  if (C_169_A == MASSTOR_SIL || BL == 0) {
    return C;
  }
  AP = C_169_A;
  do {
    SACLIST_ADV2(AP, &AL, &EL, &AP);
    PL = MASI_IPROD(AL, BL);
    C = SACLIST_COMP2(EL, PL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPE_EIVIQ
# ifdef __STDC__
(MASSTOR_LIST C_168_A, MASSTOR_LIST BL)
# else
(C_168_A, BL)
MASSTOR_LIST C_168_A, BL;
# endif
{
  MASSTOR_LIST AL, AP, C, EL, QL, RL;

  C = MASSTOR_SIL;
  if (C_168_A == MASSTOR_SIL) {
    return C;
  }
  AP = C_168_A;
  do {
    SACLIST_ADV2(AP, &AL, &EL, &AP);
    SACI_IQR(AL, BL, &QL, &RL);
    C = SACLIST_COMP2(EL, QL, C);
  } while (!(AP == MASSTOR_SIL));
  C = MASSTOR_INV(C);
  return C;
}

MASSTOR_LIST DIPE_EIVIRP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP, WS;

  if (U == MASSTOR_SIL || V == MASSTOR_SIL) {
    W = MASSTOR_SIL;
    return W;
  }
  US = U;
  VS = V;
  W = MASSTOR_SIL;
  do {
    SACLIST_ADV2(US, &KL, &IL, &US);
    VP = VS;
    W1 = MASSTOR_SIL;
    do {
      SACLIST_ADV2(VP, &ML, &JL, &VP);
      DIPE_ILINPR(JL, IL, &LL, &SL);
      if (SL != 0) {
        if (SL < 0) {
          ML = SACI_INEG(ML);
        }
        NL = MASI_IPROD(KL, ML);
        W1 = SACLIST_COMP2(NL, LL, W1);
      }
    } while (!(VP == MASSTOR_SIL));
    if (W1 != MASSTOR_SIL) {
      W = MASSTOR_COMP(W1, W);
    }
  } while (!(US == MASSTOR_SIL));
  if (W == MASSTOR_SIL) {
    return W;
  }
  do {
    WP = MASSTOR_SIL;
    while (W != MASSTOR_SIL && MASSTOR_RED(W) != MASSTOR_SIL) {
      SACLIST_ADV2(W, &WL1, &WL2, &W);
      WS = DIPE_EIVSUM(WL1, WL2);
      WP = MASSTOR_COMP(WS, WP);
    }
    if (WP != MASSTOR_SIL) {
      WPP = MASSTOR_INV(WP);
      MASSTOR_SRED(WP, W);
      W = WPP;
    }
  } while (!(MASSTOR_RED(W) == MASSTOR_SIL));
  W = MASSTOR_FIRST(W);
  return W;
}

MASSTOR_LIST DIPE_EIVNEG
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST AL, BL, IL, US, V;

  V = MASSTOR_SIL;
  if (U == MASSTOR_SIL) {
    return V;
  }
  US = U;
  do {
    SACLIST_ADV2(US, &AL, &IL, &US);
    BL = SACI_INEG(AL);
    V = SACLIST_COMP2(IL, BL, V);
  } while (!(US == MASSTOR_SIL));
  V = MASSTOR_INV(V);
  return V;
}

MASSTOR_LIST DIPE_EIVPP
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST V, VL;

  DIPE_EIVCPP(U, &V, &VL);
  return V;
}

MASSTOR_LIST DIPE_EIVSIG
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASSTOR_LIST J1Y, SL;

  if (U == MASSTOR_SIL) {
    SL = 0;
  } else {
    J1Y = MASSTOR_FIRST(U);
    SL = SACI_ISIGNF(J1Y);
  }
  return SL;
}

MASSTOR_LIST DIPE_EIVSUM
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST EL, FL, SL, UL, UP, VL, VP, W, WL, WP, WPP;

  if (U == MASSTOR_SIL) {
    W = V;
    return W;
  }
  if (V == MASSTOR_SIL) {
    W = U;
    return W;
  }
  UP = U;
  VP = V;
  WP = MASSTOR_SIL;
  do {
    EL = SACLIST_SECOND(UP);
    FL = SACLIST_SECOND(VP);
    SL = DIPE_ILWCMP(EL, FL);
    if (SL == 1) {
      SACLIST_ADV2(UP, &UL, &EL, &UP);
      WP = SACLIST_COMP2(EL, UL, WP);
    } else {
      if (SL == -1) {
        SACLIST_ADV2(VP, &VL, &FL, &VP);
        WP = SACLIST_COMP2(FL, VL, WP);
      } else {
        SACLIST_ADV2(UP, &UL, &EL, &UP);
        SACLIST_ADV2(VP, &VL, &FL, &VP);
        WL = SACI_ISUM(UL, VL);
        if (WL != 0) {
          WP = SACLIST_COMP2(EL, WL, WP);
        }
      }
    }
  } while (!(UP == MASSTOR_SIL || VP == MASSTOR_SIL));
  if (UP == MASSTOR_SIL) {
    UP = VP;
  }
  if (WP == MASSTOR_SIL) {
    W = UP;
  } else {
    WPP = WP;
    W = MASSTOR_INV(WP);
    MASSTOR_SRED(WPP, UP);
  }
  return W;
}

void DIPE_EIVWRT
# ifdef __STDC__
(MASSTOR_LIST C_167_A)
# else
(C_167_A)
MASSTOR_LIST C_167_A;
# endif
{
  MASSTOR_LIST AL, AS, IL;

  MASBIOS_SWRITE("(", 1L);
  AS = C_167_A;
  while (AS != MASSTOR_SIL) {
    SACLIST_ADV2(AS, &AL, &IL, &AS);
    MASBIOS_SWRITE(" ", 1L);
    if (SACI_ISIGNF(AL) == 1) {
      MASBIOS_SWRITE("+", 1L);
    }
    SACI_IWRITE(AL);
    DIPE_INLWRT(IL);
  }
  MASBIOS_SWRITE(" )", 2L);
  return;
}

MASSTOR_LIST DIPE_EXIDET
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST D, DL, EL, ML, MP;

  MASSTOR_ADV(M, &D, &MP);
  while (MP != MASSTOR_SIL && D != MASSTOR_SIL) {
    MASSTOR_ADV(MP, &ML, &MP);
    D = DIPE_EIVEPR(D, ML);
  }
  if (D == MASSTOR_SIL) {
    DL = 0;
    return DL;
  }
  SACLIST_ADV2(D, &DL, &EL, &D);
  if (D == MASSTOR_SIL) {
    return DL;
  }
  MASERR_ERROR(MASERR_severe, "IN EXIDET.", 10L);
  return DL;
}

MASSTOR_LIST DIPE_EXIDT2
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST D, DL, EL, ML1, ML2, MP, MPP, MPS;

  DL = 0;
  if (M == MASSTOR_SIL) {
    return DL;
  }
  MP = M;
  do {
    MPS = MASSTOR_SIL;
    while (MP != MASSTOR_SIL && MASSTOR_RED(MP) != MASSTOR_SIL) {
      SACLIST_ADV2(MP, &ML1, &ML2, &MP);
      D = DIPE_EIVEPR(ML1, ML2);
      if (D == MASSTOR_SIL) {
        return DL;
      }
      MPS = MASSTOR_COMP(D, MPS);
    }
    if (MPS != MASSTOR_SIL) {
      MPP = MASSTOR_INV(MPS);
      MASSTOR_SRED(MPS, MP);
      MP = MPP;
    }
  } while (!(MASSTOR_RED(MP) == MASSTOR_SIL));
  MASSTOR_ADV(MP, &D, &MP);
  if (D == MASSTOR_SIL) {
    return DL;
  }
  SACLIST_ADV2(D, &DL, &EL, &D);
  if (D == MASSTOR_SIL) {
    return DL;
  }
  MASERR_ERROR(MASERR_severe, "IN EXIDT2.", 10L);
  return DL;
}

MASSTOR_LIST DIPE_EXMHOM
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST MP, MS, UL, VL;

  MS = MASSTOR_SIL;
  MP = M;
  while (MP != MASSTOR_SIL) {
    MASSTOR_ADV(MP, &UL, &MP);
    VL = DIPE_EXVHOM(UL, 1);
    MS = MASSTOR_COMP(VL, MS);
  }
  MS = MASSTOR_INV(MS);
  return MS;
}

MASSTOR_LIST DIPE_EXVHOM
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST SL)
# else
(U, SL)
MASSTOR_LIST U, SL;
# endif
{
  MASSTOR_LIST EL, NL, UL, US, V;

  V = MASSTOR_SIL;
  US = U;
  NL = SL - 1;
  while (US != MASSTOR_SIL) {
    NL = NL + 1;
    MASSTOR_ADV(US, &UL, &US);
    if (UL != 0) {
      EL = MASSTOR_LIST1(NL);
      V = SACLIST_COMP2(EL, UL, V);
    }
  }
  V = MASSTOR_INV(V);
  return V;
}

MASSTOR_LIST DIPE_ITD
# ifdef __STDC__
(MASSTOR_LIST C_166_A)
# else
(C_166_A)
MASSTOR_LIST C_166_A;
# endif
{
  MASSTOR_LIST BL;

  if (C_166_A > MASSTOR_BETA) {
    BL = MASSTOR_FIRST(C_166_A);
  } else {
    BL = C_166_A;
  }
}

MASSTOR_LIST DIPE_IJACS
# ifdef __STDC__
(MASSTOR_LIST X, MASSTOR_LIST Y)
# else
(X, Y)
MASSTOR_LIST X, Y;
# endif
{
  MASSTOR_LIST C_165_A, B, BL0, EL, J1Y, ML, SL;

  C_165_A = X;
  B = Y;
  SL = 1;
  if (SACI_ISIGNF(C_165_A) < 0) {
    C_165_A = SACI_INEG(C_165_A);
    if (MASELEM_MASREM(DIPE_ITD(B), 4) != 1) {
      SL = -1;
    }
  }
  while (B != 1) {
    C_165_A = SACI_IREM(C_165_A, B);
    EL = SACI_IORD2(C_165_A);
    if (EL > 0) {
      C_165_A = SACI_IDP2(C_165_A, EL);
      if (MASELEM_MASODD(EL)) {
        J1Y = DIPE_ITD(B);
        BL0 = MASELEM_MASREM(J1Y, 16);
        if (MASELEM_MASREM(BL0 * BL0, 16) != 1) {
          SL = -SL;
        }
      }
    }
    ML = C_165_A;
    C_165_A = B;
    B = ML;
    if (MASELEM_MASREM(DIPE_ITD(C_165_A), 4) != 1 && MASELEM_MASREM(DIPE_ITD(B), 4) != 1) {
      SL = -SL;
    }
  }
  return SL;
}

MASSTOR_LIST DIPE_ILADDC
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST CL)
# else
(U, CL)
MASSTOR_LIST U, CL;
# endif
{
  MASSTOR_LIST UL, US, V, VL;

  if (U == MASSTOR_SIL || CL == 0) {
    V = U;
    return V;
  }
  V = MASSTOR_SIL;
  US = U;
  do {
    MASSTOR_ADV(US, &UL, &US);
    VL = UL + CL;
    V = MASSTOR_COMP(VL, V);
  } while (!(US == MASSTOR_SIL));
  V = MASSTOR_INV(V);
  return V;
}

void DIPE_ILEXPR
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST *W, MASSTOR_LIST *SL)
# else
(U, V, W, SL)
MASSTOR_LIST U, V;
MASSTOR_LIST *W, *SL;
# endif
{
  MASSTOR_LIST J1Y, ML, NL, UL, US, VL, VS, WS;

  *SL = 1;
  if (U == MASSTOR_SIL) {
    *W = V;
    return;
  }
  if (V == MASSTOR_SIL) {
    *W = U;
    return;
  }
  US = U;
  VS = V;
  *W = MASSTOR_SIL;
  ML = 0;
  NL = 0;
  WS = MASSTOR_SIL;
  do {
    UL = MASSTOR_FIRST(US);
    VL = MASSTOR_FIRST(VS);
    if (UL == VL) {
      *SL = 0;
      return;
    }
    if (UL < VL) {
      WS = MASSTOR_COMP(UL, WS);
      ML = ML + 1;
      US = MASSTOR_RED(US);
    } else {
      WS = MASSTOR_COMP(VL, WS);
      VS = MASSTOR_RED(VS);
      NL = NL + 1;
      if (MASELEM_MASODD(ML)) {
        *SL = -*SL;
      }
    }
  } while (!(US == MASSTOR_SIL || VS == MASSTOR_SIL));
  if (US == MASSTOR_SIL) {
    US = VS;
  } else {
    J1Y = MASSTOR_LENGTH(US);
    ML = ML + J1Y;
  }
  if (MASELEM_MASODD(ML) && MASELEM_MASODD(NL)) {
    *SL = -*SL;
  }
  *W = MASSTOR_INV(WS);
  MASSTOR_SRED(WS, US);
  return;
}

void DIPE_ILILPR
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST *W, MASSTOR_LIST *SL)
# else
(U, V, W, SL)
MASSTOR_LIST U, V;
MASSTOR_LIST *W, *SL;
# endif
{
  MASSTOR_LIST ML, UL, US, VL, VS, WS;

  *SL = 1;
  if (U == MASSTOR_SIL) {
    *W = V;
    return;
  }
  *W = MASSTOR_SIL;
  if (V == MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  US = V;
  VS = U;
  ML = 0;
  WS = MASSTOR_SIL;
  do {
    UL = MASSTOR_FIRST(US);
    VL = MASSTOR_FIRST(VS);
    if (UL < VL) {
      *SL = 0;
      return;
    }
    if (UL == VL) {
      US = MASSTOR_RED(US);
      VS = MASSTOR_RED(VS);
      if (MASELEM_MASODD(ML)) {
        *SL = -*SL;
      }
    } else {
      WS = MASSTOR_COMP(VL, WS);
      VS = MASSTOR_RED(VS);
      ML = ML + 1;
    }
  } while (!(US == MASSTOR_SIL || VS == MASSTOR_SIL));
  if (US != MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  if (WS == MASSTOR_SIL) {
    *W = VS;
  } else {
    *W = MASSTOR_INV(WS);
    MASSTOR_SRED(WS, VS);
  }
  return;
}

void DIPE_ILINPR
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST *W, MASSTOR_LIST *SL)
# else
(U, V, W, SL)
MASSTOR_LIST U, V;
MASSTOR_LIST *W, *SL;
# endif
{
  MASSTOR_LIST ML, UL, US, VL, VS, WS;

  *SL = 1;
  if (U == MASSTOR_SIL) {
    *W = V;
    return;
  }
  *W = MASSTOR_SIL;
  if (V == MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  US = U;
  VS = V;
  ML = 0;
  WS = MASSTOR_SIL;
  do {
    UL = MASSTOR_FIRST(US);
    VL = MASSTOR_FIRST(VS);
    if (UL < VL) {
      *SL = 0;
      return;
    }
    if (UL == VL) {
      US = MASSTOR_RED(US);
      VS = MASSTOR_RED(VS);
      if (MASELEM_MASODD(ML)) {
        *SL = -*SL;
      }
    } else {
      WS = MASSTOR_COMP(VL, WS);
      VS = MASSTOR_RED(VS);
      ML = ML + 1;
    }
  } while (!(US == MASSTOR_SIL || VS == MASSTOR_SIL));
  if (US != MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  if (WS == MASSTOR_SIL) {
    *W = VS;
  } else {
    *W = MASSTOR_INV(WS);
    MASSTOR_SRED(WS, VS);
  }
  return;
}

void DIPE_ILIRPR
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V, MASSTOR_LIST *W, MASSTOR_LIST *SL)
# else
(U, V, W, SL)
MASSTOR_LIST U, V;
MASSTOR_LIST *W, *SL;
# endif
{
  MASSTOR_LIST ML, UL, US, VL, VS, WS;

  *SL = 1;
  if (U == MASSTOR_SIL) {
    *W = V;
    return;
  }
  *W = MASSTOR_SIL;
  if (V == MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  US = U;
  VS = V;
  ML = 0;
  WS = MASSTOR_SIL;
  do {
    UL = MASSTOR_FIRST(US);
    VL = MASSTOR_FIRST(VS);
    if (UL < VL) {
      *SL = 0;
      return;
    }
    if (UL == VL) {
      US = MASSTOR_RED(US);
      VS = MASSTOR_RED(VS);
      if (MASELEM_MASODD(ML)) {
        *SL = -*SL;
      }
    } else {
      WS = MASSTOR_COMP(VL, WS);
      VS = MASSTOR_RED(VS);
      ML = ML + 1;
    }
  } while (!(US == MASSTOR_SIL || VS == MASSTOR_SIL));
  if (US != MASSTOR_SIL) {
    *SL = 0;
    return;
  }
  if (WS == MASSTOR_SIL) {
    *W = VS;
  } else {
    *W = MASSTOR_INV(WS);
    MASSTOR_SRED(WS, VS);
  }
  return;
}

MASSTOR_LIST DIPE_ILSCMP
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST V)
# else
(U, V)
MASSTOR_LIST U, V;
# endif
{
  MASSTOR_LIST ML, NL, TL, UL, US, VL, VS;

  TL = 0;
  US = U;
  VS = V;
  while (US != MASSTOR_SIL && VS != MASSTOR_SIL && TL == 0) {
    MASSTOR_ADV(US, &UL, &US);
    MASSTOR_ADV(VS, &VL, &VS);
    if (UL < VL) {
      TL = 1;
    }
    if (UL > VL) {
      TL = -1;
    }
  }
  if (TL == 0) {
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
  ML = MASSTOR_LENGTH(US);
  NL = MASSTOR_LENGTH(VS);
  if (ML == NL) {
    return TL;
  }
  if (ML < NL) {
    TL = 1;
  } else {
    TL = -1;
  }
  return TL;
}

MASSTOR_LIST DIPE_ILWCMP
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
    if (UL < VL) {
      TL = 1;
      return TL;
    }
    if (UL > VL) {
      TL = -1;
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

MASSTOR_LIST DIPE_INDLST
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST SL)
# else
(RL, SL)
MASSTOR_LIST RL, SL;
# endif
{
  MASSTOR_LIST EL, IL;

  EL = MASSTOR_SIL;
  if (RL > SL) {
    return EL;
  }
  {
    LONGINT B_1 = SL, B_2 = RL;

    if (B_1 >= B_2)
      for (IL = B_1;; IL += -1) {
        EL = MASSTOR_COMP(IL, EL);
        if (IL <= B_2) break;
      }
  }
  return EL;
}

void DIPE_INLWRT
# ifdef __STDC__
(MASSTOR_LIST U)
# else
(U)
MASSTOR_LIST U;
# endif
{
  MASBIOS_SWRITE(" E", 2L);
  SACLIST_LWRITE(U);
  return;
}

MASSTOR_LIST DIPE_IPSR
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST C_164_A, B, FL, J1Y, RS;

  if (R == MASSTOR_SIL) {
    C_164_A = 0;
    return C_164_A;
  }
  MASSTOR_ADV(R, &FL, &RS);
  J1Y = -FL;
  C_164_A = SACPOL_PBIN(1, 1, J1Y, 0);
  while (RS != MASSTOR_SIL) {
    MASSTOR_ADV(RS, &FL, &RS);
    J1Y = -FL;
    B = SACPOL_PBIN(1, 1, J1Y, 0);
    C_164_A = SACIPOL_IPPROD(1, C_164_A, B);
  }
  return C_164_A;
}

MASSTOR_LIST DIPE_IVHOM
# ifdef __STDC__
(MASSTOR_LIST U, MASSTOR_LIST IL, MASSTOR_LIST JL)
# else
(U, IL, JL)
MASSTOR_LIST U, IL, JL;
# endif
{
  MASSTOR_LIST AL, KL, NL, SL, UL, US, V;

  V = MASSTOR_SIL;
  US = U;
  NL = IL;
  while (US != MASSTOR_SIL) {
    SACLIST_ADV2(US, &AL, &UL, &US);
    SL = MASSTOR_FIRST(UL);
    {
      LONGINT B_3 = NL, B_4 = SL - 1;

      if (B_3 <= B_4)
        for (KL = B_3;; KL += 1) {
          V = MASSTOR_COMP(0, V);
          if (KL >= B_4) break;
        }
    }
    V = MASSTOR_COMP(AL, V);
    NL = KL + 2;
  }
  {
    LONGINT B_5 = NL, B_6 = JL;

    if (B_5 <= B_6)
      for (KL = B_5;; KL += 1) {
        V = MASSTOR_COMP(0, V);
        if (KL >= B_6) break;
      }
  }
  V = MASSTOR_INV(V);
  return V;
}

MASSTOR_LIST DIPE_IVRAND
# ifdef __STDC__
(MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST NL)
# else
(KL, QL, NL)
MASSTOR_LIST KL, QL, NL;
# endif
{
  MASSTOR_LIST DL, I, QLD, QLN, QLS, TL, V, VL;

  SACLIST_FIRST2(QL, &QLD, &QLN);
  SACD_DQR(QLD, 0, QLN, &QLS, &TL);
  V = MASSTOR_SIL;
  {
    LONGINT B_7 = 1, B_8 = NL;

    if (B_7 <= B_8)
      for (I = B_7;; I += 1) {
        DL = SACD_DRANN();
        if (DL < QLS) {
          VL = SACI_IRAND(KL);
        } else {
          VL = 0;
        }
        V = MASSTOR_COMP(VL, V);
        if (I >= B_8) break;
      }
  }
  return V;
}

MASSTOR_LIST DIPE_KREISP
# ifdef __STDC__
(MASSTOR_LIST NL)
# else
(NL)
MASSTOR_LIST NL;
# endif
{
  MASSTOR_LIST C_163_A, B, IL, J1Y, NP, PL, PS;

  if (NL == 1) {
    J1Y = -1;
    C_163_A = SACLIST_LIST4(1, 1, 0, J1Y);
    return C_163_A;
  }
  NP = SACPRIM_IFACT(NL);
  C_163_A = MASSTOR_SIL;
  if (MASSTOR_RED(NP) == MASSTOR_SIL) {
    {
      LONGINT B_9 = 0, B_10 = NL - 1;

      if (B_9 <= B_10)
        for (IL = B_9;; IL += 1) {
          C_163_A = SACLIST_COMP2(IL, 1, C_163_A);
          if (IL >= B_10) break;
        }
    }
    return C_163_A;
  }
  MASSTOR_ADV(NP, &PL, &NP);
  PS = 1;
  while (NP != MASSTOR_SIL && PL == MASSTOR_FIRST(NP)) {
    NP = MASSTOR_RED(NP);
    PS = PS * PL;
  }
  if (NP == MASSTOR_SIL) {
    {
      LONGINT B_11 = 0, B_12 = PL - 1;

      if (B_11 <= B_12)
        for (IL = B_11;; IL += 1) {
          J1Y = IL * PS;
          C_163_A = SACLIST_COMP2(J1Y, 1, C_163_A);
          if (IL >= B_12) break;
        }
    }
    return C_163_A;
  }
  J1Y = -1;
  C_163_A = SACLIST_LIST4(NL, 1, 0, J1Y);
  IL = 1;
  while (IL < NL) {
    if (MASELEM_MASREM(NL, IL) == 0) {
      B = DIPE_KREISP(IL);
      C_163_A = SACIPOL_IPQ(1, C_163_A, B);
    }
    IL = IL + 1;
  }
  return C_163_A;
}

MASSTOR_LIST DIPE_MDVHOM
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST U)
# else
(ML, U)
MASSTOR_LIST ML, U;
# endif
{
  MASSTOR_LIST UL, US, V, VL;

  US = U;
  V = MASSTOR_SIL;
  while (US != MASSTOR_SIL) {
    MASSTOR_ADV(US, &UL, &US);
    VL = SACM_MDHOM(ML, UL);
    V = MASSTOR_COMP(VL, V);
  }
  V = MASSTOR_INV(V);
  return V;
}

MASSTOR_LIST DIPE_MIRAND
# ifdef __STDC__
(MASSTOR_LIST KL, MASSTOR_LIST QL, MASSTOR_LIST NL, MASSTOR_LIST ML)
# else
(KL, QL, NL, ML)
MASSTOR_LIST KL, QL, NL, ML;
# endif
{
  MASSTOR_LIST IL, M, V;

  M = MASSTOR_SIL;
  {
    LONGINT B_13 = 1, B_14 = NL;

    if (B_13 <= B_14)
      for (IL = B_13;; IL += 1) {
        V = DIPE_IVRAND(KL, QL, ML);
        M = MASSTOR_COMP(V, M);
        if (IL >= B_14) break;
      }
  }
  M = MASSTOR_INV(M);
  return M;
}

MASSTOR_LIST DIPE_POWSEV
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST C_162_A)
# else
(PL, C_162_A)
MASSTOR_LIST PL, C_162_A;
# endif
{
  MASSTOR_LIST AL, AS, B, IL, JL;

  if (PL == 0 || C_162_A == MASSTOR_SIL) {
    B = C_162_A;
    return B;
  }
  B = MASSTOR_SIL;
  AS = C_162_A;
  do {
    SACLIST_ADV2(AS, &AL, &IL, &AS);
    JL = DIPE_ILADDC(IL, PL);
    B = SACLIST_COMP2(JL, AL, B);
  } while (!(AS == MASSTOR_SIL));
  B = MASSTOR_INV(B);
  return B;
}

void DIPE_UIPRES
# ifdef __STDC__
(MASSTOR_LIST C_161_A, MASSTOR_LIST B, MASSTOR_LIST *CL, MASSTOR_LIST *KL)
# else
(C_161_A, B, CL, KL)
MASSTOR_LIST C_161_A, B;
MASSTOR_LIST *CL, *KL;
# endif
{
  MASSTOR_LIST AP, AS, BP, BS, C, D, DP, EL, IL, J1Y, LL, ML, NL, SL, TL;

  *CL = 0;
  if (C_161_A == 0 || B == 0) {
    return;
  }
  NL = SACPOL_PDEG(C_161_A);
  ML = SACPOL_PDEG(B);
  if (NL >= ML) {
    AP = C_161_A;
    BP = B;
  } else {
    AP = B;
    BP = C_161_A;
    TL = NL;
    NL = ML;
    ML = TL;
  }
  LL = NL - ML;
  *KL = ML;
  if (LL == 0) {
    C = SACLIST_LIST2(1, MASSTOR_SIL);
  } else {
    if (LL == 1) {
      C = DIPE_EIVFUP(BP, 0);
    } else {
      J1Y = LL - 1;
      EL = DIPE_INDLST(0, J1Y);
      C = DIPE_UIPSIL(BP, EL);
    }
  }
  AS = DIPE_EIVFUP(AP, 0);
  BS = DIPE_EIVFUP(BP, LL);
  D = DIPE_EIVEPR(AS, BS);
  C = DIPE_EIVEPR(C, D);
  if (C == MASSTOR_SIL) {
    return;
  }
  {
    LONGINT B_15 = 1, B_16 = ML - 1;

    if (B_15 <= B_16)
      for (IL = B_15;; IL += 1) {
        DP = DIPE_POWSEV(IL, D);
        C = DIPE_EIVEPR(C, DP);
        *KL = *KL - 1;
        if (C == MASSTOR_SIL) {
          return;
        }
        if (IL >= B_16) break;
      }
  }
  *CL = MASSTOR_FIRST(C);
  *KL = 0;
  if (MASELEM_MASODD(LL * ML + ML - 1 * ML / 2)) {
    *CL = SACI_INEG(*CL);
  }
  return;
}

MASSTOR_LIST DIPE_UIPRS1
# ifdef __STDC__
(MASSTOR_LIST C_160_A, MASSTOR_LIST B)
# else
(C_160_A, B)
MASSTOR_LIST C_160_A, B;
# endif
{
  MASSTOR_LIST C, C1, C2, CL, EM, EN, J1Y, ML, NL;

  CL = 0;
  if (C_160_A == 0 || B == 0) {
    return CL;
  }
  ML = SACPOL_PDEG(B);
  NL = SACPOL_PDEG(C_160_A);
  J1Y = ML - 1;
  EM = DIPE_INDLST(0, J1Y);
  J1Y = NL - 1;
  EN = DIPE_INDLST(0, J1Y);
  C1 = DIPE_UIPSIL(C_160_A, EM);
  C2 = DIPE_UIPSIL(B, EN);
  C = DIPE_EIVEPR(C1, C2);
  if (C == MASSTOR_SIL) {
    return CL;
  }
  MASSTOR_ADV(C, &CL, &C);
  return CL;
}

MASSTOR_LIST DIPE_UIPSIL
# ifdef __STDC__
(MASSTOR_LIST C_159_A, MASSTOR_LIST EL)
# else
(C_159_A, EL)
MASSTOR_LIST C_159_A, EL;
# endif
{
  MASSTOR_LIST B, BP, FL, PL;

  if (C_159_A == 0 || EL == MASSTOR_SIL) {
    B = MASSTOR_SIL;
    return B;
  }
  MASSTOR_ADV(EL, &PL, &FL);
  B = DIPE_EIVFUP(C_159_A, PL);
  while (FL != MASSTOR_SIL) {
    MASSTOR_ADV(FL, &PL, &FL);
    BP = DIPE_EIVFUP(C_159_A, PL);
    B = DIPE_EIVEPR(B, BP);
    if (B == MASSTOR_SIL) {
      return B;
    }
  }
  return B;
}

MASSTOR_LIST DIPE_UIPSIV
# ifdef __STDC__
(MASSTOR_LIST C_158_A, MASSTOR_LIST B)
# else
(C_158_A, B)
MASSTOR_LIST C_158_A, B;
# endif
{
  MASSTOR_LIST AL, BS, C, C1, EL;

  C = MASSTOR_SIL;
  if (C_158_A == 0 || B == MASSTOR_SIL) {
    return C;
  }
  BS = B;
  do {
    SACLIST_ADV2(BS, &AL, &EL, &BS);
    C1 = DIPE_UIPSIL(C_158_A, EL);
    if (C1 != MASSTOR_SIL) {
      C1 = DIPI_DIIPIP(C1, AL);
      C = DIPE_EIVSUM(C, C1);
    }
  } while (!(BS == MASSTOR_SIL));
  return C;
}

void BEGIN_DIPE()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_MASERR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACD();
    BEGIN_SACI();
    BEGIN_SACM();
    BEGIN_SACPRIM();
    BEGIN_MASI();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_DIPI();

  }
}
