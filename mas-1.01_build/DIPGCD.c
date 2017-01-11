#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACIPOL
#include "SACIPOL.h"
#endif

#ifndef DEFINITION_SACPGCD
#include "SACPGCD.h"
#endif

#ifndef DEFINITION_SACPFAC
#include "SACPFAC.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_DIPRN
#include "DIPRN.h"
#endif

#ifndef DEFINITION_DIPGCD
#include "DIPGCD.h"
#endif

CHAR DIPGCD_rcsid [] = "$Id: DIPGCD.md,v 1.2 1992/02/12 17:34:17 pesch Exp $";
CHAR DIPGCD_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: DIPGCD.mi,v 1.3 1992/10/15 16:29:34 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST DIPGCD_DIRFAC
# ifdef __STDC__
(MASSTOR_LIST P)
# else
(P)
MASSTOR_LIST P;
# endif
{
  MASSTOR_LIST CL, EL, PL, PLP, PP, Q, QL, QLP, QLS, RL, SL;

  PP = MASSTOR_BETA;
  if (P == 0) {
    return PP;
  }
  PL = DIPI_DIIFRP(P);
  DIPC_PFDIP(PL, &RL, &PL);
  SACPFAC_IPFAC(RL, PL, &SL, &CL, &Q);
  while (Q != MASSTOR_SIL) {
    MASSTOR_ADV(Q, &QLS, &Q);
    SACLIST_FIRST2(QLS, &EL, &QLP);
    PLP = DIPC_DIPFP(RL, QLP);
    PLP = DIPRN_DIRFIP(PLP);
    QL = SACLIST_LIST2(EL, PLP);
    PP = MASSTOR_COMP(QL, PP);
  }
  PP = MASSTOR_INV(PP);
  return PP;
}

MASSTOR_LIST DIPGCD_IPLCM
# ifdef __STDC__
(MASSTOR_LIST RL, MASSTOR_LIST C_189_A, MASSTOR_LIST B)
# else
(RL, C_189_A, B)
MASSTOR_LIST RL, C_189_A, B;
# endif
{
  MASSTOR_LIST AP, APP, BP, BPP, C, CP;

  AP = SACIPOL_IPABS(RL, C_189_A);
  BP = SACIPOL_IPABS(RL, B);
  if (AP == 0) {
    C = BP;
    return C;
  }
  if (BP == 0) {
    C = AP;
    return C;
  }
  SACPGCD_IPGCDC(RL, AP, BP, &CP, &APP, &BPP);
  C = SACIPOL_IPPROD(RL, APP, BP);
  return C;
}

void BEGIN_DIPGCD()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACIPOL();
    BEGIN_SACPGCD();
    BEGIN_SACPFAC();
    BEGIN_DIPC();
    BEGIN_DIPI();
    BEGIN_DIPRN();

  }
}
