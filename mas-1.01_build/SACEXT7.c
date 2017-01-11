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

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACROOT
#include "SACROOT.h"
#endif

#ifndef DEFINITION_SACEXT2
#include "SACEXT2.h"
#endif

#ifndef DEFINITION_SACEXT4
#include "SACEXT4.h"
#endif

#ifndef DEFINITION_SACEXT7
#include "SACEXT7.h"
#endif

CHAR SACEXT7_rcsid [] = "$Id: SACEXT7.md,v 1.2 1992/02/12 17:34:53 pesch Exp $";
CHAR SACEXT7_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACEXT7.mi,v 1.3 1992/10/15 16:28:59 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACEXT7_IPRRRI
# ifdef __STDC__
(MASSTOR_LIST C_166_A, MASSTOR_LIST B, MASSTOR_LIST I, MASSTOR_LIST SL1, MASSTOR_LIST TL1)
# else
(C_166_A, B, I, SL1, TL1)
MASSTOR_LIST C_166_A, B, I, SL1, TL1;
# endif
{
  MASSTOR_LIST AL, ALS1, ALS2, IS, SL, TL, UL, VL;

  SACLIST_FIRST2(I, &ALS1, &ALS2);
  for (;;) {
    AL = SACROOT_RIB(ALS1, ALS2);
    SL = SACIPOL_IUPBES(C_166_A, AL);
    if (SL == 0) {
      SL = -SL1;
    }
    TL = SACIPOL_IUPBES(B, AL);
    if (TL == 0) {
      TL = -TL1;
    }
    UL = SL1 * SL;
    VL = TL1 * TL;
    if (UL > 0) {
      ALS1 = AL;
    } else {
      ALS2 = AL;
    }
    if (UL != VL) {
      goto EXIT_1;
    }
  } EXIT_1:;
  IS = SACLIST_LIST2(ALS1, ALS2);
  return IS;
}

MASSTOR_LIST SACEXT7_IPSIFI
# ifdef __STDC__
(MASSTOR_LIST C_165_A, MASSTOR_LIST I)
# else
(C_165_A, I)
MASSTOR_LIST C_165_A, I;
# endif
{
  MASSTOR_LIST AL, BL, CL, J, KL, ML, NL, SL, TL;

  SACLIST_FIRST2(I, &AL, &BL);
  TL = SACIPOL_IUPBES(C_165_A, BL);
  if (TL == 0) {
    J = SACLIST_LIST2(BL, BL);
    return J;
  }
  SACEXT2_RNBCR(AL, BL, &ML, &NL, &KL);
  for (;;) {
    CL = SACROOT_RIB(AL, BL);
    SL = SACIPOL_IUPBES(C_165_A, CL);
    if (SL == 0) {
      J = SACLIST_LIST2(CL, CL);
      return J;
    } else {
      if (SL * TL < 0) {
        AL = CL;
      } else {
        BL = CL;
        TL = SL;
      }
    }
    SACEXT2_RNBCR(AL, BL, &ML, &NL, &KL);
    if (SACI_IDIF(NL, ML) == 1) {
      J = SACLIST_LIST2(AL, BL);
      return J;
    }
  } EXIT_2:;
  return J;
}

MASSTOR_LIST SACEXT7_ISFPIR
# ifdef __STDC__
(MASSTOR_LIST C_164_A, MASSTOR_LIST I, MASSTOR_LIST KL)
# else
(C_164_A, I, KL)
MASSTOR_LIST C_164_A, I, KL;
# endif
{
  MASSTOR_LIST J, QL, RL, SLH, SLP, TL, UL, VL, WL, XL;

  RL = SACI_IEXP(10, KL);
  QL = SACLIST_LIST2(1, RL);
  SACLIST_FIRST2(I, &UL, &VL);
  SLP = SACIPOL_IUPBES(C_164_A, VL);
  XL = SACRN_RNDIF(VL, UL);
  TL = SACRN_RNCOMP(XL, QL);
  while (TL >= 0) {
    WL = SACROOT_RIB(UL, VL);
    SLH = SACIPOL_IUPBES(C_164_A, WL);
    if (SLP == 0 || SLH * SLP < 0) {
      UL = WL;
    } else {
      VL = WL;
      SLP = SLH;
    }
    XL = SACRN_RNDIF(VL, UL);
    TL = SACRN_RNCOMP(XL, QL);
  }
  J = SACLIST_LIST2(UL, VL);
  return J;
}

MASSTOR_LIST SACEXT7_IUPVOI
# ifdef __STDC__
(MASSTOR_LIST C_163_A, MASSTOR_LIST I)
# else
(C_163_A, I)
MASSTOR_LIST C_163_A, I;
# endif
{
  MASSTOR_LIST AL, B, BL, C, D, DL, KL, ML, NL, VL;

  SACLIST_FIRST2(I, &AL, &BL);
  SACEXT2_RNBCR(AL, BL, &ML, &NL, &KL);
  if (KL != 0) {
    B = SACIPOL_IUPBHT(C_163_A, KL);
  } else {
    B = C_163_A;
  }
  if (ML != 0) {
    C = SACIPOL_IUPTR(B, ML);
  } else {
    C = B;
  }
  DL = SACI_IDIF(NL, ML);
  D = SACEXT4_IUPIHT(C, DL);
  VL = SACROOT_IPVCHT(D);
  return VL;
}

void BEGIN_SACEXT7()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_MASBIOS();
    BEGIN_SACI();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACPGCD();
    BEGIN_SACROOT();
    BEGIN_SACEXT2();
    BEGIN_SACEXT4();

  }
}
