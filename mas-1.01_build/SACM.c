#include "SYSTEM_.h"

#ifndef DEFINITION_MASELEM
#include "MASELEM.h"
#endif

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
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

CHAR SACM_rcsid [] = "$Id: SACM.md,v 1.2 1992/02/12 13:19:14 pesch Exp $";
CHAR SACM_copyright [] = "Copyright (c) 1989 - 1992 Universitaet Passau";

static CHAR rcsidi [] = "$Id: SACM.mi,v 1.3 1992/10/15 16:28:19 kredel Exp $";
static CHAR copyrighti [] = "Copyright (c) 1989 - 1992 Universitaet Passau";


MASSTOR_LIST SACM_MDCRA
# ifdef __STDC__
(MASSTOR_LIST ML1, MASSTOR_LIST ML2, MASSTOR_LIST MLP1, MASSTOR_LIST AL1, MASSTOR_LIST AL2)
# else
(ML1, ML2, MLP1, AL1, AL2)
MASSTOR_LIST ML1, ML2, MLP1, AL1, AL2;
# endif
{
  MASSTOR_LIST AL, ALB, BL, DL, J1Y;

  ALB = MASELEM_MASREM(AL1, ML2);
  DL = SACM_MDDIF(ML2, AL2, ALB);
  if (DL == 0) {
    AL = AL1;
    return AL;
  }
  J1Y = DL * MLP1;
  BL = MASELEM_MASREM(J1Y, ML2);
  J1Y = ML1 * BL;
  AL = J1Y + AL1;
  return AL;
}

MASSTOR_LIST SACM_MDDIF
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(ML, AL, BL)
MASSTOR_LIST ML, AL, BL;
# endif
{
  MASSTOR_LIST CL;

  CL = AL - BL;
  if (CL < 0) {
    CL = CL + ML;
  }
  return CL;
}

MASSTOR_LIST SACM_MDEXP
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL, MASSTOR_LIST NL)
# else
(ML, AL, NL)
MASSTOR_LIST ML, AL, NL;
# endif
{
  MASSTOR_LIST BL, CL, NLP;

  if (AL == 0 && NL > 0) {
    BL = 0;
    return BL;
  }
  BL = 1;
  CL = AL;
  NLP = NL;
  while (NLP != 0) {
    if (ODD(NLP)) {
      BL = SACM_MDPROD(ML, BL, CL);
    }
    CL = SACM_MDPROD(ML, CL, CL);
    NLP = NLP / 2;
  }
  return BL;
}

MASSTOR_LIST SACM_MDHOM
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST C_55_A)
# else
(ML, C_55_A)
MASSTOR_LIST ML, C_55_A;
# endif
{
  MASSTOR_LIST BL, Q;

  SACI_IDQR(C_55_A, ML, &Q, &BL);
  if (BL < 0) {
    BL = BL + ML;
  }
  return BL;
}

MASSTOR_LIST SACM_MDINV
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL)
# else
(ML, AL)
MASSTOR_LIST ML, AL;
# endif
{
  MASSTOR_LIST AL1, AL2, AL3, BL, J1Y, QL, VL1, VL2, VL3;

  AL1 = ML;
  AL2 = AL;
  VL1 = 0;
  VL2 = 1;
  while (AL2 != 1) {
    QL = AL1 / AL2;
    J1Y = QL * AL2;
    AL3 = AL1 - J1Y;
    J1Y = QL * VL2;
    VL3 = VL1 - J1Y;
    AL1 = AL2;
    AL2 = AL3;
    VL1 = VL2;
    VL2 = VL3;
  }
  if (VL2 >= 0) {
    BL = VL2;
  } else {
    BL = VL2 + ML;
  }
  return BL;
}

MASSTOR_LIST SACM_MDLCRA
# ifdef __STDC__
(MASSTOR_LIST ML1, MASSTOR_LIST ML2, MASSTOR_LIST L1, MASSTOR_LIST L2)
# else
(ML1, ML2, L1, L2)
MASSTOR_LIST ML1, ML2, L1, L2;
# endif
{
  MASSTOR_LIST AL, AL1, AL2, L, LP1, LP2, MLP1;

  MLP1 = SACM_MDINV(ML2, ML1);
  L = MASSTOR_BETA;
  LP1 = L1;
  while (LP1 != MASSTOR_SIL) {
    MASSTOR_ADV(LP1, &AL1, &LP1);
    LP2 = L2;
    while (LP2 != MASSTOR_SIL) {
      MASSTOR_ADV(LP2, &AL2, &LP2);
      AL = SACM_MDCRA(ML1, ML2, MLP1, AL1, AL2);
      L = MASSTOR_COMP(AL, L);
    }
  }
  return L;
}

MASSTOR_LIST SACM_MDNEG
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL)
# else
(ML, AL)
MASSTOR_LIST ML, AL;
# endif
{
  MASSTOR_LIST BL;

  if (AL == 0) {
    BL = 0;
  } else {
    BL = ML - AL;
  }
  return BL;
}

MASSTOR_LIST SACM_MDPROD
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(ML, AL, BL)
MASSTOR_LIST ML, AL, BL;
# endif
{
  MASSTOR_LIST CL, CL0, CL1, QL;

  SACD_DPR(AL, BL, &CL1, &CL0);
  SACD_DQR(CL1, CL0, ML, &QL, &CL);
  return CL;
}

MASSTOR_LIST SACM_MDQ
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(ML, AL, BL)
MASSTOR_LIST ML, AL, BL;
# endif
{
  MASSTOR_LIST CL, J1Y;

  J1Y = SACM_MDINV(ML, BL);
  CL = SACM_MDPROD(ML, AL, J1Y);
  return CL;
}

MASSTOR_LIST SACM_MDRAN
# ifdef __STDC__
(MASSTOR_LIST ML)
# else
(ML)
MASSTOR_LIST ML;
# endif
{
  MASSTOR_LIST AL, AL1, AL2, DL1, DL2, IDUM, J1Y, TL;

  J1Y = SACD_DRAN();
  DL1 = MASELEM_MASABS(J1Y);
  SACD_DPR(DL1, ML, &AL, &TL);
  if (ML <= SACD_DELTA) {
    return AL;
  }
  AL1 = AL;
  J1Y = SACD_DRAN();
  DL2 = MASELEM_MASABS(J1Y);
  SACD_DPR(DL2, ML, &AL, &AL2);
  if (AL1 + AL2 >= MASSTOR_BETA) {
    AL = AL + 1;
  }
  return AL;
}

MASSTOR_LIST SACM_MDSUM
# ifdef __STDC__
(MASSTOR_LIST ML, MASSTOR_LIST AL, MASSTOR_LIST BL)
# else
(ML, AL, BL)
MASSTOR_LIST ML, AL, BL;
# endif
{
  MASSTOR_LIST CL, CLP;

  CL = AL + BL;
  CLP = CL - ML;
  if (CLP >= 0) {
    CL = CLP;
  }
  return CL;
}

MASSTOR_LIST SACM_MIDCRA
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST ML, MASSTOR_LIST MLP, MASSTOR_LIST C_54_A, MASSTOR_LIST AL)
# else
(M, ML, MLP, C_54_A, AL)
MASSTOR_LIST M, ML, MLP, C_54_A, AL;
# endif
{
  MASSTOR_LIST ALB, AS, BL, DL, J1Y;

  ALB = SACM_MDHOM(ML, C_54_A);
  DL = SACM_MDDIF(ML, AL, ALB);
  if (DL == 0) {
    AS = C_54_A;
    return AS;
  }
  BL = SACM_MDPROD(ML, DL, MLP);
  if (BL + BL > ML) {
    BL = BL - ML;
  }
  J1Y = SACI_IDPR(M, BL);
  AS = SACI_ISUM(J1Y, C_54_A);
  return AS;
}

MASSTOR_LIST SACM_MIDIF
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_53_A, MASSTOR_LIST B)
# else
(M, C_53_A, B)
MASSTOR_LIST M, C_53_A, B;
# endif
{
  MASSTOR_LIST C;

  C = SACI_IDIF(C_53_A, B);
  if (SACI_ISIGNF(C) < 0) {
    C = SACI_ISUM(M, C);
  }
  return C;
}

MASSTOR_LIST SACM_MIEXP
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_52_A, MASSTOR_LIST N)
# else
(M, C_52_A, N)
MASSTOR_LIST M, C_52_A, N;
# endif
{
  MASSTOR_LIST B, NP, TL;

  if (M < MASSTOR_BETA && N < MASSTOR_BETA) {
    B = SACM_MDEXP(M, C_52_A, N);
    return B;
  }
  if (N == 0) {
    B = 1;
    return B;
  }
  if (N == 1) {
    B = C_52_A;
    return B;
  }
  if (C_52_A == 0) {
    B = 0;
    return B;
  }
  SACI_IDQR(N, 2, &NP, &TL);
  B = SACM_MIEXP(M, C_52_A, NP);
  B = SACM_MIPROD(M, B, B);
  if (TL == 1) {
    B = SACM_MIPROD(M, B, C_52_A);
  }
  return B;
}

MASSTOR_LIST SACM_MIHOM
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_51_A)
# else
(M, C_51_A)
MASSTOR_LIST M, C_51_A;
# endif
{
  MASSTOR_LIST AS;

  AS = SACI_IREM(C_51_A, M);
  if (SACI_ISIGNF(AS) < 0) {
    AS = SACI_ISUM(M, AS);
  }
  return AS;
}

MASSTOR_LIST SACM_MIINV
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_50_A)
# else
(M, C_50_A)
MASSTOR_LIST M, C_50_A;
# endif
{
  MASSTOR_LIST B, C, UL;

  if (M < MASSTOR_BETA) {
    SACD_DEGCD(M, C_50_A, &C, &UL, &B);
  } else {
    SACI_IHEGCD(M, C_50_A, &C, &B);
  }
  if (SACI_ISIGNF(B) < 0) {
    B = SACI_ISUM(M, B);
  }
  return B;
}

MASSTOR_LIST SACM_MINEG
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_49_A)
# else
(M, C_49_A)
MASSTOR_LIST M, C_49_A;
# endif
{
  MASSTOR_LIST B;

  if (C_49_A == 0) {
    B = 0;
  } else {
    B = SACI_IDIF(M, C_49_A);
  }
  return B;
}

MASSTOR_LIST SACM_MIPROD
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_48_A, MASSTOR_LIST B)
# else
(M, C_48_A, B)
MASSTOR_LIST M, C_48_A, B;
# endif
{
  MASSTOR_LIST C, J1Y;

  J1Y = SACI_IPROD(C_48_A, B);
  C = SACI_IREM(J1Y, M);
  return C;
}

MASSTOR_LIST SACM_MIQ
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_47_A, MASSTOR_LIST B)
# else
(M, C_47_A, B)
MASSTOR_LIST M, C_47_A, B;
# endif
{
  MASSTOR_LIST C, J1Y;

  J1Y = SACM_MIINV(M, B);
  C = SACM_MIPROD(M, C_47_A, J1Y);
  return C;
}

MASSTOR_LIST SACM_MIRAN
# ifdef __STDC__
(MASSTOR_LIST M)
# else
(M)
MASSTOR_LIST M;
# endif
{
  MASSTOR_LIST J1Y, R;

  J1Y = SACI_ILOG2(M);
  J1Y = J1Y + SACD_ZETA;
  J1Y = SACI_IRAND(J1Y);
  R = SACM_MIHOM(M, J1Y);
  return R;
}

MASSTOR_LIST SACM_MISUM
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_46_A, MASSTOR_LIST B)
# else
(M, C_46_A, B)
MASSTOR_LIST M, C_46_A, B;
# endif
{
  MASSTOR_LIST C, CP;

  C = SACI_ISUM(C_46_A, B);
  CP = SACI_IDIF(C, M);
  if (SACI_ISIGNF(CP) >= 0) {
    C = CP;
  }
  return C;
}

MASSTOR_LIST SACM_SMFMI
# ifdef __STDC__
(MASSTOR_LIST M, MASSTOR_LIST C_45_A)
# else
(M, C_45_A)
MASSTOR_LIST M, C_45_A;
# endif
{
  MASSTOR_LIST B;

  B = SACI_IDIF(C_45_A, M);
  if (SACI_ICOMP(C_45_A, SACI_INEG(B)) <= 0) {
    B = C_45_A;
  }
  return B;
}

void BEGIN_SACM()
{
  static BOOLEAN has_been_called = FALSE;

  if (!has_been_called) {
    has_been_called = TRUE;

    BEGIN_MASSTOR();
    BEGIN_MASELEM();
    BEGIN_MASSTOR();
    BEGIN_SACD();
    BEGIN_SACI();

  }
}
