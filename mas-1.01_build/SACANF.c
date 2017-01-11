#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
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

#ifndef DEFINITION_SACRPOL
#include "SACRPOL.h"
#endif

#ifndef DEFINITION_SACROOT
#include "SACROOT.h"
#endif

#ifndef DEFINITION_SACANF
#include "SACANF.h"
#endif

CHAR SACANF_rcsid [] = "$Id: SACANF.md,v 1.2 1992/02/12 17:34:44 pesch Exp $";
CHAR SACANF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACANF.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACANF_AFDIF
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST CL;

  CL = SACRPOL_RPDIF(1, AL, BL);
  return CL;
}

MASSTOR_LIST SACANF_AFINV
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST AL)
# else
(M, AL)
MASSTOR_LIST M, AL;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, BL, CL, J1Y, QL, RL, VL1, VL2, VL3;

  AL1 = M;
  AL2 = AL;
  VL1 = 0;
  RL = SACRN_RNINT(1);
  VL2 = SACLIST_LIST2(0, RL);
  for (;;) {
    J1Y = SACPOL_PLDCF(AL2);
    CL = SACRN_RNINV(J1Y);
    VL2 = SACRPOL_RPRNP(1, CL, VL2);
    if (SACPOL_PDEG(AL2) == 0) {
      BL = VL2;
      return BL;
    }
    AL2 = SACRPOL_RPRNP(1, CL, AL2);
    SACRPOL_RPQR(1, AL1, AL2, &QL, &AL3);
    J1Y = SACRPOL_RPPROD(1, QL, VL2);
    VL3 = SACRPOL_RPDIF(1, VL1, J1Y);
    AL1 = AL2;
    AL2 = AL3;
    VL1 = VL2;
    VL2 = VL3;
  } EXIT_1:;
  return BL;
}

MASSTOR_LIST SACANF_AFNEG
# ifdef __STDC__
(MASSTOR_LIST AL)
# else
(AL)
MASSTOR_LIST AL;
# endif
{
  MASSTOR_LIST BL;

  BL = SACRPOL_RPNEG(1, AL);
  return BL;
}

MASSTOR_LIST SACANF_AFPROD
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(M, AL, BL)
MASSTOR_LIST M, AL, BL;
# endif
{
  MASSTOR_LIST CL, CLP, QL;

  CLP = SACRPOL_RPPROD(1, AL, BL);
  SACRPOL_RPQR(1, CLP, M, &QL, &CL);
  return CL;
}

MASSTOR_LIST SACANF_AFQ
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(M, AL, BL)
MASSTOR_LIST M, AL, BL;
# endif
{
  MASSTOR_LIST CL, J1Y;

  if (AL == 0) {
    CL = 0;
  } else {
    J1Y = SACANF_AFINV(M, BL);
    CL = SACANF_AFPROD(M, AL, J1Y);
  }
  return CL;
}

MASSTOR_LIST SACANF_AFSIGN
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST I, MASSTOR_LIST AL)
# else
(M, I, AL)
MASSTOR_LIST M, I, AL;
# endif
{
  MASSTOR_LIST ALP, ALS, IS, J1Y, NL, RL, SL, SLH, SLP, SLS, UL, VL, WL;

  if (AL == 0) {
    SL = 0;
    return SL;
  }
  if (SACPOL_PDEG(AL) == 0) {
    J1Y = SACLIST_SECOND(AL);
    SL = SACRN_RNSIGN(J1Y);
    return SL;
  }
  SACPGCD_IPSRP(1, AL, &RL, &ALP);
  SLS = SACRN_RNSIGN(RL);
  ALS = SACPGCD_IPPGSD(1, ALP);
  IS = I;
  SACLIST_FIRST2(IS, &UL, &VL);
  SLP = 0;
  for (;;) {
    NL = SACROOT_IUPVSI(ALS, IS);
    WL = SACROOT_RIB(UL, VL);
    if (NL == 0) {
      SL = SACIPOL_IUPBES(ALP, WL);
      SL = SLS * SL;
      return SL;
    }
    if (SLP == 0) {
      SLP = SACIPOL_IUPBES(M, VL);
    }
    SLH = SACIPOL_IUPBES(M, WL);
    if (SLH != SLP) {
      UL = WL;
    } else {
      VL = WL;
      SLP = SLH;
    }
    IS = SACLIST_LIST2(UL, VL);
  } EXIT_2:;
  return SL;
}

MASSTOR_LIST SACANF_AFSUM
# ifdef __STDC__
(MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(AL, BL)
MASSTOR_LIST AL, BL;
# endif
{
  MASSTOR_LIST CL;

  CL = SACRPOL_RPSUM(1, AL, BL);
  return CL;
}

MASSTOR_LIST SACANF_RUPMRN
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST J1Y, J2Y, M;

  J1Y = SACRN_RNINT(1);
  J2Y = SACRN_RNNEG(R);
  M = SACPOL_PBIN(J1Y, 1, J2Y, 0);
  return M;
}

void BEGIN_SACANF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACPGCD();
    BEGIN_SACRPOL();
    BEGIN_SACROOT();

  }
}
