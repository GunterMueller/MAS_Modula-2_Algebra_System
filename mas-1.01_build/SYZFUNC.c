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

#ifndef DEFINITION_SACRN
#include "SACRN.h"
#endif

#ifndef DEFINITION_SYZHLP
#include "SYZHLP.h"
#endif

#ifndef DEFINITION_SYZFUNC
#include "SYZFUNC.h"
#endif

CHAR SYZFUNC_rcsid [] = "$Id: SYZFUNC.md,v 1.3 1995/11/04 18:00:50 pesch Exp $";
CHAR SYZFUNC_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SYZFUNC.mi,v 1.4 1995/11/04 18:00:51 pesch Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


void SYZFUNC_SPC
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST *SPFL, MASSTOR_LIST *SP)
# else
(P1, P2, SPFL, SP)
MASSTOR_LIST P1, P2;
MASSTOR_LIST *SPFL, *SP;
# endif
{
  MASSTOR_LIST SP1, SP2, KO1, KO2, EV1, EV2, H, EV3, EV31, EV32, SPF1, SPF2;

  DIPC_DIPMAD(P1, &KO1, &EV1, &H);
  DIPC_DIPMAD(P2, &KO2, &EV2, &H);
  EV3 = DIPC_EVLCM(EV1, EV2);
  EV31 = DIPC_EVDIF(EV3, EV1);
  EV32 = DIPC_EVDIF(EV3, EV2);
  SPF1 = DIPC_DIPFMO(KO2, EV31);
  SPF2 = DIPC_DIPFMO(KO1, EV32);
  *SPFL = SACLIST_CCONC(MASSTOR_LIST1(SPF1), MASSTOR_LIST1(SPF2));
  SP1 = DIPRN_DIRPPR(SPF1, P1);
  SP2 = DIPRN_DIRPPR(SPF2, P2);
  *SP = DIPRN_DIRPDF(SP1, SP2);
  return;
}

void SYZFUNC_NLSPC
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST *SPFL, MASSTOR_LIST *SP, MASSTOR_LIST *T)
# else
(P1, P2, SPFL, SP, T)
MASSTOR_LIST P1, P2;
MASSTOR_LIST *SPFL, *SP, *T;
# endif
{
  MASSTOR_LIST SP1, SP2, KO1, KO2, EV1, EV2, EV3, EV31, EV32, RZ, SPF1, SPF2;

  EV1 = DIPC_DIPEVL(P1);
  EV2 = DIPC_DIPEVL(P2);
  EV3 = DIPC_EVLCM(EV1, EV2);
  EV31 = DIPC_EVDIF(EV3, EV1);
  EV32 = DIPC_EVDIF(EV3, EV2);
  RZ = SACRN_RNINT(1);
  SPF1 = DIPC_DIPFMO(RZ, EV31);
  SPF2 = DIPC_DIPFMO(RZ, EV32);
  SP1 = MASNC_DINPPR(*T, SPF1, P1);
  SP2 = MASNC_DINPPR(*T, SPF2, P2);
  KO1 = DIPC_DIPLBC(SP1);
  KO2 = DIPC_DIPLBC(SP2);
  SP1 = DIPRN_DIRPRP(SP1, KO2);
  SP2 = DIPRN_DIRPRP(SP2, KO1);
  SPF1 = DIPRN_DIRPRP(SPF1, KO2);
  SPF2 = DIPRN_DIRPRP(SPF2, KO1);
  *SPFL = SACLIST_CCONC(MASSTOR_LIST1(SPF1), MASSTOR_LIST1(SPF2));
  *SP = DIPRN_DIRPDF(SP1, SP2);
  return;
}

void SYZFUNC_SPCGB
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST *SPFL, MASSTOR_LIST *SPL)
# else
(GB, SPFL, SPL)
MASSTOR_LIST GB;
MASSTOR_LIST *SPFL, *SPL;
# endif
{
  MASSTOR_LIST GB1, P1, P2, SPFL1, SP;

  *SPFL = MASSTOR_SIL;
  *SPL = MASSTOR_SIL;
  while (MASSTOR_RED(GB) != MASSTOR_SIL) {
    GB1 = MASSTOR_RED(GB);
    MASSTOR_ADV(GB, &P1, &GB);
    while (GB1 != MASSTOR_SIL) {
      MASSTOR_ADV(GB1, &P2, &GB1);
      SYZFUNC_SPC(P1, P2, &SPFL1, &SP);
      *SPFL = SACLIST_CCONC(*SPFL, SPFL1);
      *SPL = SACLIST_CCONC(*SPL, MASSTOR_LIST1(SP));
    }
  }
  return;
}

void SYZFUNC_NLSPCGB
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST *SPFL, MASSTOR_LIST *SPL, MASSTOR_LIST *T)
# else
(GB, SPFL, SPL, T)
MASSTOR_LIST GB;
MASSTOR_LIST *SPFL, *SPL, *T;
# endif
{
  MASSTOR_LIST GB1, P1, P2, SPFL1, SP;

  *SPFL = MASSTOR_SIL;
  *SPL = MASSTOR_SIL;
  while (MASSTOR_RED(GB) != MASSTOR_SIL) {
    GB1 = MASSTOR_RED(GB);
    MASSTOR_ADV(GB, &P1, &GB);
    while (GB1 != MASSTOR_SIL) {
      MASSTOR_ADV(GB1, &P2, &GB1);
      SYZFUNC_NLSPC(P1, P2, &SPFL1, &SP, T);
      *SPFL = SACLIST_CCONC(*SPFL, SPFL1);
      *SPL = SACLIST_CCONC(*SPL, MASSTOR_LIST1(SP));
    }
  }
  return;
}

void SYZFUNC_SPCEGB
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST L, MASSTOR_LIST *SPFL, MASSTOR_LIST *SPL)
# else
(GB, L, SPFL, SPL)
MASSTOR_LIST GB, L;
MASSTOR_LIST *SPFL, *SPL;
# endif
{
  MASSTOR_LIST GB1, P1, P2, SPFL1, SP;

  *SPFL = MASSTOR_SIL;
  *SPL = MASSTOR_SIL;
  while (MASSTOR_RED(GB) != MASSTOR_SIL) {
    GB1 = MASSTOR_RED(GB);
    MASSTOR_ADV(GB, &P1, &GB);
    while (GB1 != MASSTOR_SIL) {
      MASSTOR_ADV(GB1, &P2, &GB1);
      if (SYZHLP_EVT(P1, P2, L) == 1) {
        SYZFUNC_SPC(P1, P2, &SPFL1, &SP);
        *SPFL = SACLIST_CCONC(*SPFL, SPFL1);
        *SPL = SACLIST_CCONC(*SPL, MASSTOR_LIST1(SP));
      } else {
        *SPFL = SACLIST_CCONC(*SPFL, MASSTOR_LIST1(0));
      }
    }
  }
  return;
}

void SYZFUNC_NLSPCEGB
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST L, MASSTOR_LIST *SPFL, MASSTOR_LIST *SPL, MASSTOR_LIST *T)
# else
(GB, L, SPFL, SPL, T)
MASSTOR_LIST GB, L;
MASSTOR_LIST *SPFL, *SPL, *T;
# endif
{
  MASSTOR_LIST GB1, P1, P2, SPFL1, SP;

  *SPFL = MASSTOR_SIL;
  *SPL = MASSTOR_SIL;
  while (MASSTOR_RED(GB) != MASSTOR_SIL) {
    GB1 = MASSTOR_RED(GB);
    MASSTOR_ADV(GB, &P1, &GB);
    while (GB1 != MASSTOR_SIL) {
      MASSTOR_ADV(GB1, &P2, &GB1);
      if (SYZHLP_EVT(P1, P2, L) == 1) {
        SYZFUNC_NLSPC(P1, P2, &SPFL1, &SP, T);
        *SPFL = SACLIST_CCONC(*SPFL, SPFL1);
        *SPL = SACLIST_CCONC(*SPL, MASSTOR_LIST1(SP));
      } else {
        *SPFL = SACLIST_CCONC(*SPFL, MASSTOR_LIST1(0));
      }
    }
  }
  return;
}

MASSTOR_LIST SYZFUNC_RCSP
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST SPL)
# else
(GB, SPL)
MASSTOR_LIST GB, SPL;
# endif
{
  MASSTOR_LIST EV1, EV2, GB1, P1, P2, P3, NF, KO1, KO2, PL, NV, P, PR, H, POS, TW, SPAK;

  SPAK = MASSTOR_SIL;
  NV = MASNC_EVZERO(MASSTOR_LENGTH(GB));
  while (SPL != MASSTOR_SIL) {
    MASSTOR_ADV(SPL, &PR, &SPL);
    if (PR == 0) {
      SPAK = SACLIST_CCONC(SPAK, MASSTOR_LIST1(NV));
    } else {
      PL = NV;
      while (PR != 0) {
        GB1 = GB;
        POS = 0;
        while (GB1 != MASSTOR_SIL && PR != 0) {
          MASSTOR_ADV(GB1, &P, &GB1);
          POS = POS + 1;
          DIPC_DIPMAD(PR, &KO1, &EV1, &H);
          DIPC_DIPMAD(P, &KO2, &EV2, &H);
          TW = DIPC_EVMT(EV1, EV2);
          if (TW == 1) {
            P1 = DIPC_DIPFMO(KO1, EV1);
            P2 = DIPC_DIPFMO(KO2, EV2);
            NF = DIPRN_DIRPQ(P1, P2);
            P3 = DIPRN_DIRPPR(NF, P);
            PR = DIPRN_DIRPDF(PR, P3);
            PL = SYZHLP_ADDPPOS(PL, NF, POS);
          }
        }
      }
      SPAK = SACLIST_CCONC(SPAK, MASSTOR_LIST1(PL));
    }
  }
  return SPAK;
}

MASSTOR_LIST SYZFUNC_RCSPR
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST *SP)
# else
(PL, SP)
MASSTOR_LIST PL;
MASSTOR_LIST *SP;
# endif
{
  MASSTOR_LIST C, EV1, EV2, P1, P2, P3, NF, KO1, KO2, NV, P, PL1, H, POS, TW, SPAK;

  SPAK = MASNC_EVZERO(MASSTOR_LENGTH(PL));
  C = 1;
  while (*SP != 0 && C == 1) {
    PL1 = PL;
    POS = 0;
    C = 0;
    while (PL1 != MASSTOR_SIL && *SP != 0) {
      MASSTOR_ADV(PL1, &P, &PL1);
      POS = POS + 1;
      DIPC_DIPMAD(*SP, &KO1, &EV1, &H);
      DIPC_DIPMAD(P, &KO2, &EV2, &H);
      TW = DIPC_EVMT(EV1, EV2);
      if (TW == 1) {
        C = 1;
        P1 = DIPC_DIPFMO(KO1, EV1);
        P2 = DIPC_DIPFMO(KO2, EV2);
        NF = DIPRN_DIRPQ(P1, P2);
        P3 = DIPRN_DIRPPR(NF, P);
        *SP = DIPRN_DIRPDF(*SP, P3);
        SPAK = SYZHLP_ADDPPOS(SPAK, NF, POS);
      }
    }
  }
  return SPAK;
}

MASSTOR_LIST SYZFUNC_NLRCSPR
# ifdef __STDC__
(MASSTOR_LIST PL, MASSTOR_LIST *SP, MASSTOR_LIST *T)
# else
(PL, SP, T)
MASSTOR_LIST PL;
MASSTOR_LIST *SP, *T;
# endif
{
  MASSTOR_LIST C, EV1, EV2, P1, P2, P3, NF, KO, KO1, KO2, NV, P, PL1, H, POS, TW, SPAK;

  SPAK = MASNC_EVZERO(MASSTOR_LENGTH(PL));
  C = 1;
  while (*SP != 0 && C == 1) {
    PL1 = PL;
    POS = 0;
    C = 0;
    while (PL1 != MASSTOR_SIL && *SP != 0) {
      MASSTOR_ADV(PL1, &P, &PL1);
      POS = POS + 1;
      DIPC_DIPMAD(*SP, &KO1, &EV1, &H);
      DIPC_DIPMAD(P, &KO2, &EV2, &H);
      TW = DIPC_EVMT(EV1, EV2);
      if (TW == 1) {
        C = 1;
        NF = DIPC_EVDIF(EV1, EV2);
        P1 = DIPC_DIPFMO(SACRN_RNINT(1), NF);
        P2 = MASNC_DINPPR(*T, P1, P);
        KO = SACRN_RNQ(KO1, DIPC_DIPLBC(P2));
        P2 = DIPRN_DIRPRP(P2, KO);
        *SP = DIPRN_DIRPDF(*SP, P2);
        P1 = DIPRN_DIRPRP(P1, KO);
        SPAK = SYZHLP_ADDPPOS(SPAK, P1, POS);
      }
    }
  }
  return SPAK;
}

MASSTOR_LIST SYZFUNC_NLRCSP
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST SPL, MASSTOR_LIST *T)
# else
(GB, SPL, T)
MASSTOR_LIST GB, SPL;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST EV1, EV2, GB1, P1, P2, P3, NF, KO, KO1, KO2, PL, NV, P, PR, H, POS, TW, SPAK;

  SPAK = MASSTOR_SIL;
  NV = MASNC_EVZERO(MASSTOR_LENGTH(GB));
  while (SPL != MASSTOR_SIL) {
    MASSTOR_ADV(SPL, &PR, &SPL);
    if (PR == 0) {
      SPAK = SACLIST_CCONC(SPAK, MASSTOR_LIST1(NV));
    } else {
      PL = NV;
      while (PR != 0) {
        GB1 = GB;
        POS = 0;
        while (GB1 != MASSTOR_SIL && PR != 0) {
          MASSTOR_ADV(GB1, &P, &GB1);
          POS = POS + 1;
          DIPC_DIPMAD(PR, &KO1, &EV1, &H);
          DIPC_DIPMAD(P, &KO2, &EV2, &H);
          TW = DIPC_EVMT(EV1, EV2);
          if (TW == 1) {
            NF = DIPC_EVDIF(EV1, EV2);
            P1 = DIPC_DIPFMO(SACRN_RNINT(1), NF);
            P2 = MASNC_DINPPR(*T, P1, P);
            KO = SACRN_RNQ(KO1, DIPC_DIPLBC(P2));
            P2 = DIPRN_DIRPRP(P2, KO);
            P1 = DIPRN_DIRPRP(P1, KO);
            PR = DIPRN_DIRPDF(PR, P2);
            PL = SYZHLP_ADDPPOS(PL, P1, POS);
          }
        }
      }
      SPAK = SACLIST_CCONC(SPAK, MASSTOR_LIST1(PL));
    }
  }
  return SPAK;
}

MASSTOR_LIST SYZFUNC_SYGB
# ifdef __STDC__
(MASSTOR_LIST SPFL, MASSTOR_LIST SPAK)
# else
(SPFL, SPAK)
MASSTOR_LIST SPFL, SPAK;
# endif
{
  MASSTOR_LIST C1, C2, C3, C4, PL, PL1, P, P1, SPF1, SPF2, SY1;

  SY1 = MASSTOR_SIL;
  C3 = MASSTOR_LENGTH(MASSTOR_FIRST(SPAK));
  {
    LONGINT B_1 = 1, B_2 = C3 - 1;

    if (B_1 <= B_2)
      for (C1 = B_1;; C1 += 1) {
        {
          LONGINT B_3 = C1 + 1, B_4 = C3;

          if (B_3 <= B_4)
            for (C2 = B_3;; C2 += 1) {
              SACLIST_ADV2(SPFL, &SPF1, &SPF2, &SPFL);
              MASSTOR_ADV(SPAK, &PL1, &SPAK);
              PL = MASSTOR_SIL;
              {
                LONGINT B_5 = 1, B_6 = C3;

                if (B_5 <= B_6)
                  for (C4 = B_5;; C4 += 1) {
                    MASSTOR_ADV(PL1, &P, &PL1);
                    if (C4 != C1 && C4 != C2) {
                      P1 = P;
                    } else if (C4 == C1) {
                      P1 = DIPRN_DIRPDF(P, SPF1);
                    } else if (C4 == C2) {
                      P1 = DIPRN_DIRPSM(P, SPF2);
                    }
                    PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P1));
                    if (C4 >= B_6) break;
                  }
              }
              SY1 = SACLIST_CCONC(SY1, MASSTOR_LIST1(PL));
              if (C2 >= B_4) break;
            }
        }
        if (C1 >= B_2) break;
      }
  }
  return SY1;
}

MASSTOR_LIST SYZFUNC_SYGBE
# ifdef __STDC__
(MASSTOR_LIST SPFL, MASSTOR_LIST SPAK)
# else
(SPFL, SPAK)
MASSTOR_LIST SPFL, SPAK;
# endif
{
  MASSTOR_LIST C1, C2, C3, C4, PL, PL1, P, P1, SPF1, SPF2, SY1;

  SY1 = MASSTOR_SIL;
  C3 = MASSTOR_LENGTH(MASSTOR_FIRST(SPAK));
  {
    LONGINT B_7 = 1, B_8 = C3 - 1;

    if (B_7 <= B_8)
      for (C1 = B_7;; C1 += 1) {
        {
          LONGINT B_9 = C1 + 1, B_10 = C3;

          if (B_9 <= B_10)
            for (C2 = B_9;; C2 += 1) {
              MASSTOR_ADV(SPFL, &SPF1, &SPFL);
              if (SPF1 != 0) {
                MASSTOR_ADV(SPFL, &SPF2, &SPFL);
                MASSTOR_ADV(SPAK, &PL1, &SPAK);
                PL = MASSTOR_SIL;
                {
                  LONGINT B_11 = 1, B_12 = C3;

                  if (B_11 <= B_12)
                    for (C4 = B_11;; C4 += 1) {
                      MASSTOR_ADV(PL1, &P, &PL1);
                      if (C4 != C1 && C4 != C2) {
                        P1 = P;
                      } else if (C4 == C1) {
                        P1 = DIPRN_DIRPDF(P, SPF1);
                      } else if (C4 == C2) {
                        P1 = DIPRN_DIRPSM(P, SPF2);
                      }
                      PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P1));
                      if (C4 >= B_12) break;
                    }
                }
                SY1 = SACLIST_CCONC(SY1, MASSTOR_LIST1(PL));
              }
              if (C2 >= B_10) break;
            }
        }
        if (C1 >= B_8) break;
      }
  }
  return SY1;
}

MASSTOR_LIST SYZFUNC_MMULT
# ifdef __STDC__
(MASSTOR_LIST SY1, MASSTOR_LIST GBTM)
# else
(SY1, GBTM)
MASSTOR_LIST SY1, GBTM;
# endif
{
  MASSTOR_LIST PL, PL1, PL2, PL3, P1, P2, P3, P4, GBTM1, SY2;

  SY2 = MASSTOR_SIL;
  while (SY1 != MASSTOR_SIL) {
    MASSTOR_ADV(SY1, &PL, &SY1);
    PL2 = MASSTOR_SIL;
    GBTM1 = GBTM;
    while (GBTM1 != MASSTOR_SIL) {
      MASSTOR_ADV(GBTM1, &PL3, &GBTM1);
      PL1 = PL;
      P2 = 0;
      while (PL1 != MASSTOR_SIL) {
        MASSTOR_ADV(PL1, &P3, &PL1);
        MASSTOR_ADV(PL3, &P4, &PL3);
        P1 = DIPRN_DIRPPR(P3, P4);
        P2 = DIPRN_DIRPSM(P2, P1);
      }
      PL2 = SACLIST_CCONC(PL2, MASSTOR_LIST1(P2));
    }
    SY2 = SACLIST_CCONC(SY2, MASSTOR_LIST1(PL2));
  }
  return SY2;
}

MASSTOR_LIST SYZFUNC_NLMMULT
# ifdef __STDC__
(MASSTOR_LIST SY1, MASSTOR_LIST GBTM, MASSTOR_LIST *T)
# else
(SY1, GBTM, T)
MASSTOR_LIST SY1, GBTM;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST PL, PL1, PL2, PL3, P1, P2, P3, P4, GBTM1, SY2;

  SY2 = MASSTOR_SIL;
  while (SY1 != MASSTOR_SIL) {
    MASSTOR_ADV(SY1, &PL, &SY1);
    PL2 = MASSTOR_SIL;
    GBTM1 = GBTM;
    while (GBTM1 != MASSTOR_SIL) {
      MASSTOR_ADV(GBTM1, &PL3, &GBTM1);
      PL1 = PL;
      P2 = 0;
      while (PL1 != MASSTOR_SIL) {
        MASSTOR_ADV(PL1, &P3, &PL1);
        MASSTOR_ADV(PL3, &P4, &PL3);
        P1 = MASNC_DINPPR(*T, P3, P4);
        P2 = DIPRN_DIRPSM(P2, P1);
      }
      PL2 = SACLIST_CCONC(PL2, MASSTOR_LIST1(P2));
    }
    SY2 = SACLIST_CCONC(SY2, MASSTOR_LIST1(PL2));
  }
  return SY2;
}

MASSTOR_LIST SYZFUNC_BGFUP
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST SP, MASSTOR_LIST SPN, MASSTOR_LIST SPFL, MASSTOR_LIST GB, MASSTOR_LIST SPAK, MASSTOR_LIST GBTM)
# else
(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM)
MASSTOR_LIST P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM;
# endif
{
  MASSTOR_LIST NF, P, P3, P4, P5, PL, PL1, H, GBTM1, SPF1, SPF2, POS1, POS2, POS3, SPAK1;

  GBTM = SYZHLP_APP0(GBTM);
  NF = DIPRN_DIRPQ(SPN, SP);
  POS1 = SYZHLP_POS(P1, GB);
  POS2 = SYZHLP_POS(P2, GB);
  SACLIST_ADV2(SPFL, &SPF1, &SPF2, &H);
  GBTM1 = GBTM;
  GBTM = MASSTOR_SIL;
  while (GBTM1 != MASSTOR_SIL) {
    POS3 = 0;
    SPAK1 = SPAK;
    MASSTOR_ADV(GBTM1, &PL, &GBTM1);
    PL1 = PL;
    while (MASSTOR_RED(PL1) != MASSTOR_SIL) {
      MASSTOR_ADV(PL1, &P, &PL1);
      MASSTOR_ADV(SPAK1, &P3, &SPAK1);
      POS3 = POS3 + 1;
      if (POS3 == POS1) {
        P4 = DIPRN_DIRPPR(DIPRN_DIRPDF(SPF1, P3), NF);
        P4 = DIPRN_DIRPPR(P4, P);
      } else if (POS3 == POS2) {
        P4 = DIPRN_DIRPDF(DIPRN_DIRPNG(SPF2), P3);
        P4 = DIPRN_DIRPPR(P4, NF);
        P4 = DIPRN_DIRPPR(P4, P);
      } else {
        P4 = DIPRN_DIRPPR(DIPRN_DIRPNG(P3), NF);
        P4 = DIPRN_DIRPPR(P4, P);
      }
      PL = SYZHLP_ADDLAST(P4, PL);
    }
    GBTM = SACLIST_CCONC(GBTM, MASSTOR_LIST1(PL));
  }
  return GBTM;
}

MASSTOR_LIST SYZFUNC_NLBGFUP
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST SP, MASSTOR_LIST SPN, MASSTOR_LIST SPFL, MASSTOR_LIST GB, MASSTOR_LIST SPAK, MASSTOR_LIST GBTM, MASSTOR_LIST *T)
# else
(P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM, T)
MASSTOR_LIST P1, P2, SP, SPN, SPFL, GB, SPAK, GBTM;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST NF, P, P3, P4, P5, PL, PL1, H, GBTM1, SPF1, SPF2, POS1, POS2, POS3, SPAK1;

  GBTM = SYZHLP_APP0(GBTM);
  NF = DIPRN_DIRPQ(SPN, SP);
  POS1 = SYZHLP_POS(P1, GB);
  POS2 = SYZHLP_POS(P2, GB);
  SACLIST_ADV2(SPFL, &SPF1, &SPF2, &H);
  GBTM1 = GBTM;
  GBTM = MASSTOR_SIL;
  while (GBTM1 != MASSTOR_SIL) {
    POS3 = 0;
    SPAK1 = SPAK;
    MASSTOR_ADV(GBTM1, &PL, &GBTM1);
    PL1 = PL;
    while (MASSTOR_RED(PL1) != MASSTOR_SIL) {
      MASSTOR_ADV(PL1, &P, &PL1);
      MASSTOR_ADV(SPAK1, &P3, &SPAK1);
      POS3 = POS3 + 1;
      if (POS3 == POS1) {
        P4 = MASNC_DINPPR(*T, NF, DIPRN_DIRPDF(SPF1, P3));
        P4 = MASNC_DINPPR(*T, P4, P);
      } else if (POS3 == POS2) {
        P4 = DIPRN_DIRPDF(DIPRN_DIRPNG(SPF2), P3);
        P4 = MASNC_DINPPR(*T, NF, P4);
        P4 = MASNC_DINPPR(*T, P4, P);
      } else {
        P4 = MASNC_DINPPR(*T, NF, DIPRN_DIRPNG(P3));
        P4 = MASNC_DINPPR(*T, P4, P);
      }
      PL = SYZHLP_ADDLAST(P4, PL);
    }
    GBTM = SACLIST_CCONC(GBTM, MASSTOR_LIST1(PL));
  }
  return GBTM;
}

MASSTOR_LIST SYZFUNC_DGBRED
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST GBTM, MASSTOR_LIST *SY)
# else
(GB, GBTM, SY)
MASSTOR_LIST GB, GBTM;
MASSTOR_LIST *SY;
# endif
{
  MASSTOR_LIST GB1, GB2, GB3, L1, L2, P, PL, P1, KO1, EV1, KO2, EV2, H, TW;

  GB1 = GB;
  GB2 = GB;
  GB = MASSTOR_SIL;
  while (GB1 != MASSTOR_SIL) {
    MASSTOR_ADV(GB1, &P, &GB1);
    GB3 = SYZHLP_EXPPL(P, GB2);
    TW = DIPRNGB_DIRPNF(GB3, P);
    if (TW != 0) {
      GB = SACLIST_CCONC(GB, MASSTOR_LIST1(P));
    }
  }
  *SY = SYZFUNC_SYONP(GB2, GB, GBTM);
  return GB;
}

MASSTOR_LIST SYZFUNC_NLDGBRED
# ifdef __STDC__
(MASSTOR_LIST GB, MASSTOR_LIST GBTM, MASSTOR_LIST *SY, MASSTOR_LIST *T)
# else
(GB, GBTM, SY, T)
MASSTOR_LIST GB, GBTM;
MASSTOR_LIST *SY, *T;
# endif
{
  MASSTOR_LIST GB1, GB2, GB3, L1, L2, P, TW;

  GB1 = GB;
  GB2 = GB;
  GB = MASSTOR_SIL;
  while (GB1 != MASSTOR_SIL) {
    MASSTOR_ADV(GB1, &P, &GB1);
    GB3 = SYZHLP_EXPPL(P, GB2);
    TW = MASNCGB_DINLNF(*T, GB3, P);
    if (TW != 0) {
      GB = SACLIST_CCONC(GB, MASSTOR_LIST1(P));
    }
  }
  *SY = SYZFUNC_NLSYONP(GB2, GB, GBTM, T);
  return GB;
}

MASSTOR_LIST SYZFUNC_SYONP
# ifdef __STDC__
(MASSTOR_LIST GB1, MASSTOR_LIST GB2, MASSTOR_LIST GBTM)
# else
(GB1, GB2, GBTM)
MASSTOR_LIST GB1, GB2, GBTM;
# endif
{
  MASSTOR_LIST POS1, POS2, PALT, PL, PL1, PL2, P, P1, P2, P3, P4, L, SY, GBTM1, GBTM2, POSV, GB3;

  POS1 = MASSTOR_LENGTH(GBTM);
  POS2 = 1;
  GBTM1 = GBTM;
  PALT = MASSTOR_SIL;
  GB3 = GB1;
  while (POS2 <= POS1) {
    MASSTOR_ADV(GB3, &P, &GB3);
    MASSTOR_ADV(GBTM1, &PL, &GBTM1);
    P1 = SYZHLP_POL(PL, POS2);
    PALT = SACLIST_CCONC(PALT, MASSTOR_LIST1(DIPRN_DIRPQ(P, P1)));
    POS2 = POS2 + 1;
  }
  POSV = SYZHLP_GENPOSV(GB1, GB2);
  GBTM1 = SYZHLP_GBTMRED(GBTM, POSV);
  GBTM2 = SYZFUNC_RCSP(GB2, PALT);
  SY = MASSTOR_SIL;
  L = SYZHLP_EVL(GBTM1);
  P3 = DIPC_DIPFMO(SACRN_RNINT(-1), MASNC_EVZERO(L));
  POS2 = 1;
  while (GBTM2 != MASSTOR_SIL) {
    GBTM = GBTM1;
    PL = MASSTOR_SIL;
    MASSTOR_ADV(GBTM2, &PL2, &GBTM2);
    while (GBTM != MASSTOR_SIL) {
      MASSTOR_ADV(GBTM, &PL1, &GBTM);
      P = SYZFUNC_PLMULT(PL2, PL1);
      PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P));
    }
    PL2 = SYZHLP_ADDPPOS(PL, P3, POS2);
    SY = SACLIST_CCONC(SY, MASSTOR_LIST1(PL2));
    POS2 = POS2 + 1;
  }
  return SY;
}

MASSTOR_LIST SYZFUNC_NLSYONP
# ifdef __STDC__
(MASSTOR_LIST GB1, MASSTOR_LIST GB2, MASSTOR_LIST GBTM, MASSTOR_LIST *T)
# else
(GB1, GB2, GBTM, T)
MASSTOR_LIST GB1, GB2, GBTM;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST POS1, POS2, PALT, PL, PL1, PL2, P, P1, P2, P3, P4, L, SY, GBTM1, GBTM2, POSV, GB3;

  POS1 = MASSTOR_LENGTH(GBTM);
  POS2 = 1;
  GBTM1 = GBTM;
  PALT = MASSTOR_SIL;
  GB3 = GB1;
  while (POS2 <= POS1) {
    MASSTOR_ADV(GB3, &P, &GB3);
    MASSTOR_ADV(GBTM1, &PL, &GBTM1);
    P1 = SYZHLP_POL(PL, POS2);
    PALT = SACLIST_CCONC(PALT, MASSTOR_LIST1(SYZFUNC_DINPQ(P, P1, T)));
    POS2 = POS2 + 1;
  }
  POSV = SYZHLP_GENPOSV(GB1, GB2);
  GBTM1 = SYZHLP_GBTMRED(GBTM, POSV);
  GBTM2 = SYZFUNC_NLRCSP(GB2, PALT, T);
  SY = MASSTOR_SIL;
  L = SYZHLP_EVL(GBTM1);
  P3 = DIPC_DIPFMO(SACRN_RNINT(-1), MASNC_EVZERO(L));
  POS2 = 1;
  while (GBTM2 != MASSTOR_SIL) {
    GBTM = GBTM1;
    PL = MASSTOR_SIL;
    MASSTOR_ADV(GBTM2, &PL2, &GBTM2);
    while (GBTM != MASSTOR_SIL) {
      MASSTOR_ADV(GBTM, &PL1, &GBTM);
      P = SYZFUNC_NLPLMULT(PL2, PL1, T);
      PL = SACLIST_CCONC(PL, MASSTOR_LIST1(P));
    }
    PL2 = SYZHLP_ADDPPOS(PL, P3, POS2);
    SY = SACLIST_CCONC(SY, MASSTOR_LIST1(PL2));
    POS2 = POS2 + 1;
  }
  return SY;
  return SY;
}

MASSTOR_LIST SYZFUNC_DINPQ
# ifdef __STDC__
(MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST *T)
# else
(P1, P2, T)
MASSTOR_LIST P1, P2;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST P;

  P = SYZFUNC_NLRCSPR(MASSTOR_LIST1(P2), &P1, T);
  P = MASSTOR_FIRST(P);
  if (P1 == 0) {
    return P;
  } else {
    return MASSTOR_SIL;
  }
}

MASSTOR_LIST SYZFUNC_PLMULT
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PL)
# else
(SY, PL)
MASSTOR_LIST SY, PL;
# endif
{
  MASSTOR_LIST P, P1, P2;

  P = 0;
  while (SY != MASSTOR_SIL) {
    MASSTOR_ADV(SY, &P1, &SY);
    MASSTOR_ADV(PL, &P2, &PL);
    P2 = DIPRN_DIRPPR(P1, P2);
    P = DIPRN_DIRPSM(P, P2);
  }
  return P;
}

MASSTOR_LIST SYZFUNC_NLPLMULT
# ifdef __STDC__
(MASSTOR_LIST SY, MASSTOR_LIST PL, MASSTOR_LIST *T)
# else
(SY, PL, T)
MASSTOR_LIST SY, PL;
MASSTOR_LIST *T;
# endif
{
  MASSTOR_LIST P, P1, P2;

  P = 0;
  while (SY != MASSTOR_SIL) {
    MASSTOR_ADV(SY, &P1, &SY);
    MASSTOR_ADV(PL, &P2, &PL);
    P2 = MASNC_DINPPR(*T, P1, P2);
    P = DIPRN_DIRPSM(P, P2);
  }
  return P;
}

void BEGIN_SYZFUNC()
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
    BEGIN_SACRN();
    BEGIN_SYZHLP();

  }
}
