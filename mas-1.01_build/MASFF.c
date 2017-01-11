#include "SYSTEM_.h"

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_SACLIST
#include "SACLIST.h"
#endif

#ifndef DEFINITION_SACM
#include "SACM.h"
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

#ifndef DEFINITION_SACMPOL
#include "SACMPOL.h"
#endif

#ifndef DEFINITION_DIPC
#include "DIPC.h"
#endif

#ifndef DEFINITION_DIPI
#include "DIPI.h"
#endif

#ifndef DEFINITION_MASFF
#include "MASFF.h"
#endif

CHAR MASFF_rcsid [] = "$Id: MASFF.md,v 1.1 1992/09/28 17:38:29 kredel Exp $";
CHAR MASFF_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: MASFF.mi,v 1.2 1992/10/15 16:29:41 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST MASFF_FFCOMP
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST S)
# else
(R, S)
MASSTOR_LIST R, S;
# endif
{
  MASSTOR_LIST t;

  t = SACLIST_EQUAL(R, S);
  if (t == 1) {
    t = 0;
  } else {
    t = 1;
  }
  return t;
}

MASSTOR_LIST MASFF_FFDIF
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(p, M, AL, BL)
MASSTOR_LIST p, M, AL, BL;
# endif
{
  MASSTOR_LIST CL;

  CL = SACMPOL_MIPDIF(1, p, AL, BL);
  return CL;
}

MASSTOR_LIST MASFF_FFEXP
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST C_184_A, MASSTOR_LIST NL)
# else
(p, M, C_184_A, NL)
MASSTOR_LIST p, M, C_184_A, NL;
# endif
{
  MASSTOR_LIST B, KL;

  if (NL == 0) {
    B = MASFF_FFFINT(p, M, 1);
    return B;
  }
  if (NL == 1) {
    B = C_184_A;
    return B;
  }
  KL = NL / 2;
  B = MASFF_FFEXP(p, M, C_184_A, KL);
  B = MASFF_FFPROD(p, M, B, B);
  if (NL > 2 * KL) {
    B = MASFF_FFPROD(p, M, B, C_184_A);
  }
  return B;
}

MASSTOR_LIST MASFF_FFFINT
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST C_183_A)
# else
(p, M, C_183_A)
MASSTOR_LIST p, M, C_183_A;
# endif
{
  MASSTOR_LIST B, C, BL;

  BL = SACM_MIHOM(p, C_183_A);
  B = SACPOL_PINV(0, BL, 1);
  return B;
}

MASSTOR_LIST MASFF_FFHOM
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST C_182_A)
# else
(p, M, C_182_A)
MASSTOR_LIST p, M, C_182_A;
# endif
{
  MASSTOR_LIST B, C, D;

  B = SACMPOL_MIPHOM(1, p, C_182_A);
  SACMPOL_MIUPQR(p, B, M, &C, &D);
  return D;
}

MASSTOR_LIST MASFF_FFINV
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL)
# else
(p, M, AL)
MASSTOR_LIST p, M, AL;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, BL, CL, DL, EL, QL, RL, VL1, VL2, VL3;

  AL1 = M;
  AL2 = AL;
  VL1 = 0;
  RL = 1;
  VL2 = SACLIST_LIST2(0, RL);
  for (;;) {
    DL = SACPOL_PLDCF(AL2);
    CL = SACM_MIINV(p, DL);
    CL = SACLIST_LIST2(0, CL);
    VL2 = SACMPOL_MIPPR(1, p, CL, VL2);
    if (SACPOL_PDEG(AL2) == 0) {
      BL = VL2;
      return BL;
    }
    AL2 = SACMPOL_MIPPR(1, p, CL, AL2);
    SACMPOL_MIUPQR(p, AL1, AL2, &QL, &AL3);
    EL = SACMPOL_MIPPR(1, p, QL, VL2);
    VL3 = SACMPOL_MIPDIF(1, p, VL1, EL);
    AL1 = AL2;
    AL2 = AL3;
    VL1 = VL2;
    VL2 = VL3;
  } EXIT_1:;
  return BL;
}

MASSTOR_LIST MASFF_FFNEG
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL)
# else
(p, M, AL)
MASSTOR_LIST p, M, AL;
# endif
{
  MASSTOR_LIST BL;

  BL = SACMPOL_MIPNEG(1, p, AL);
  return BL;
}

MASSTOR_LIST MASFF_FFONE
# ifdef __STDC__
(MASSTOR_LIST R)
# else
(R)
MASSTOR_LIST R;
# endif
{
  MASSTOR_LIST t;

  t = SACIPOL_IPONE(1, R);
  return t;
}

MASSTOR_LIST MASFF_FFPROD
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(p, M, AL, BL)
MASSTOR_LIST p, M, AL, BL;
# endif
{
  MASSTOR_LIST CL, CLP, QL;

  CLP = SACMPOL_MIPPR(1, p, AL, BL);
  SACMPOL_MIUPQR(p, CLP, M, &QL, &CL);
  return CL;
}

MASSTOR_LIST MASFF_FFQ
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(p, M, AL, BL)
MASSTOR_LIST p, M, AL, BL;
# endif
{
  MASSTOR_LIST CL, DL;

  if (AL == 0) {
    CL = 0;
  } else {
    DL = MASFF_FFINV(p, M, BL);
    CL = MASFF_FFPROD(p, M, AL, DL);
  }
  return CL;
}

MASSTOR_LIST MASFF_FFRAND
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST NL)
# else
(p, M, NL)
MASSTOR_LIST p, M, NL;
# endif
{
  MASSTOR_LIST R, d, D, n, q;

  d = SACPOL_PDEG(M) - 1;
  D = MASSTOR_LIST1(d);
  if (d <= 0) {
    d = 1;
  }
  n = NL;
  if (n <= 0) {
    n = 1;
  }
  if (n > d) {
    n = d;
  }
  q = SACRN_RNRED(n, d);
  R = SACMPOL_MIPRAN(1, p, q, D);
  return R;
}

MASSTOR_LIST MASFF_FFREAD
# ifdef __STDC__
(MASSTOR_LIST V)
# else
(V)
MASSTOR_LIST V;
# endif
{
  MASSTOR_LIST CL, RL;

  CL = DIPI_DIIPRD(V);
  DIPC_PFDIP(CL, &RL, &CL);
  return CL;
}

MASSTOR_LIST MASFF_FFSUM
# ifdef __STDC__
(MASSTOR_LIST p, MASSTOR_LIST M, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(p, M, AL, BL)
MASSTOR_LIST p, M, AL, BL;
# endif
{
  MASSTOR_LIST CL;

  CL = SACMPOL_MIPSUM(1, p, AL, BL);
  return CL;
}

void MASFF_FFWRITE
# ifdef __STDC__
(MASSTOR_LIST R, MASSTOR_LIST V)
# else
(R, V)
MASSTOR_LIST R, V;
# endif
{
  MASSTOR_LIST CL;

  CL = DIPC_DIPFP(1, R);
  DIPI_DIIPWR(CL, V);
}

void BEGIN_MASFF()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASSTOR();
    BEGIN_SACLIST();
    BEGIN_SACM();
    BEGIN_SACRN();
    BEGIN_SACPOL();
    BEGIN_SACIPOL();
    BEGIN_SACMPOL();
    BEGIN_DIPC();
    BEGIN_DIPI();

  }
}
