(* ----------------------------------------------------------------------------
 * $Id: SACM.mi,v 1.3 1992/10/15 16:28:19 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACM.mi,v $
 * Revision 1.3  1992/10/15  16:28:19  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:14  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:42  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACM;

(* SAC Modular Digit and Integer Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASREM, MASABS;


FROM MASSTOR IMPORT BETA, SIL, LIST, 
                    COMP, ADV; 

FROM SACD IMPORT ZETA, DELTA,
                 DPR, DQR, DEGCD, DRAN;

 
FROM SACI IMPORT IDQR, IDPR, ISUM, IDIF, IRAND, ICOMP, INEG,
                 ISIGNF, IREM, IHEGCD, IPROD, ILOG2;


CONST rcsidi = "$Id: SACM.mi,v 1.3 1992/10/15 16:28:19 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE MDCRA(ML1,ML2,MLP1,AL1,AL2: LIST): LIST;
(*Modular digit difference.  m is a positive beta-integer.  a and b
belong to Z sub m.  c=a-b.*)
VAR  AL, ALB, BL, DL, J1Y: LIST;
BEGIN
(*1*) (*al=al1.*) ALB:=MASREM(AL1,ML2); DL:=MDDIF(ML2,AL2,ALB);
      IF DL = 0 THEN AL:=AL1; RETURN(AL); END;
(*2*) (*general case.*) J1Y:=DL*MLP1; BL:=MASREM(J1Y,ML2); J1Y:=ML1*BL;
      AL:=J1Y+AL1; RETURN(AL);
(*5*) END MDCRA;


PROCEDURE MDDIF(ML,AL,BL: LIST): LIST;
(*Modular digit difference.  m is a positive beta-integer.  a and b
belong to Z sub m.  c=a-b.*)
VAR  CL: LIST;
BEGIN
(*1*) CL:=AL-BL;
      IF CL < 0 THEN CL:=CL+ML; END;
      RETURN(CL);
(*4*) END MDDIF;


PROCEDURE MDEXP(ML,AL,NL: LIST): LIST;
(*Modular digit exponentiation.  m is a positive beta-integer.
a belongs to Z sub m.  n is a non-negative beta-integer.  b=a**n.*)
VAR  BL, CL, NLP: LIST;
BEGIN
(*1*) (*bl eq 0.*)
      IF (AL = 0) AND (NL > 0) THEN BL:=0; RETURN(BL); END;
(*2*) (*bl ne 0.*) BL:=1; CL:=AL; NLP:=NL;
      WHILE NLP <> 0 DO
            IF ODD(NLP) THEN BL:=MDPROD(ML,BL,CL); END;
            CL:=MDPROD(ML,CL,CL); NLP:=NLP DIV 2; END;
      RETURN(BL);
(*5*) END MDEXP;


PROCEDURE MDHOM(ML,A: LIST): LIST;
(*Modular digit homomorphism.  m is a positive beta-integer.  A is an
integer.  b is the image of A under the homomorphism H sub m.*)
VAR  BL, Q: LIST;
BEGIN
(*1*) IDQR(A,ML,Q,BL);
      IF BL < 0 THEN BL:=BL+ML; END;
      RETURN(BL);
(*4*) END MDHOM;


PROCEDURE MDINV(ML,AL: LIST): LIST;
(*Modular digit inverse.  m is a positive beta-integer.  a is a unit
of Z sub m.  b=a**-1.*)
VAR  AL1, AL2, AL3, BL, J1Y, QL, VL1, VL2, VL3: LIST;
BEGIN
(*1*) AL1:=ML; AL2:=AL; VL1:=0; VL2:=1;
      WHILE AL2 <> 1 DO QL:=AL1 DIV AL2; J1Y:=QL*AL2; AL3:=AL1-J1Y;
            J1Y:=QL*VL2; VL3:=VL1-J1Y; AL1:=AL2; AL2:=AL3; VL1:=VL2;
            VL2:=VL3; END;
      IF VL2 >= 0 THEN BL:=VL2; ELSE BL:=VL2+ML; END;
      RETURN(BL);
(*4*) END MDINV;


PROCEDURE MDLCRA(ML1,ML2,L1,L2: LIST): LIST;
(*Modular digit list chinese remainder algorithm.  m1 and m2 are
positive beta-integers, with GCD(m1,m2)=1 and m=m1*m2 less than
beta.  L1 and L2 are lists of elements of Z(m1) and Z(m2)
respectively.  L is a list of all a in Z(m) such that a is congruent
to a1 modulo m1 and a is congruent to a2 modulo m2 with a1 in L1
and a2 in L2.*)
VAR  AL, AL1, AL2, L, LP1, LP2, MLP1: LIST;
BEGIN
(*1*) MLP1:=MDINV(ML2,ML1); L:=BETA; LP1:=L1;
      WHILE LP1 <> SIL DO ADV(LP1,AL1,LP1); LP2:=L2;
            WHILE LP2 <> SIL DO ADV(LP2,AL2,LP2);
                  AL:=MDCRA(ML1,ML2,MLP1,AL1,AL2); L:=COMP(AL,L); END;
            END;
      RETURN(L);
(*4*) END MDLCRA;


PROCEDURE MDNEG(ML,AL: LIST): LIST;
(*Modular digit negative.  m is a positive beta-integer.  a belongs
to Z sub m.  b=-a.*)
VAR  BL: LIST;
BEGIN
(*1*) IF AL = 0 THEN BL:=0; ELSE BL:=ML-AL; END;
      RETURN(BL);
(*4*) END MDNEG;


PROCEDURE MDPROD(ML,AL,BL: LIST): LIST;
(*Modular digit product.  m is a positive beta-integer.  a and b
belong to Z sub m.  c=a*b.*)
VAR  CL, CL0, CL1, QL: LIST;
BEGIN
(*1*) DPR(AL,BL,CL1,CL0); DQR(CL1,CL0,ML,QL,CL); RETURN(CL);
(*4*) END MDPROD;


PROCEDURE MDQ(ML,AL,BL: LIST): LIST;
(*Modular digit quotient.  m is a positive beta-integer.  a and b
belong to Z sub m.  b is a unit.  c=a/b.*)
VAR  CL, J1Y: LIST;
BEGIN
(*1*) J1Y:=MDINV(ML,BL); CL:=MDPROD(ML,AL,J1Y); RETURN(CL);
(*4*) END MDQ;


PROCEDURE MDRAN(ML: LIST): LIST;
(*Modular digit, random.  m is a positive beta-digit.  a is a random
element of Z(m).*)
VAR  AL, AL1, AL2, DL1, DL2, IDUM, J1Y, TL: LIST;
BEGIN
(*1*) J1Y:=DRAN(); DL1:=MASABS(J1Y); DPR(DL1,ML,AL,TL);
      IF ML <= DELTA THEN RETURN(AL); END;
      AL1:=AL; J1Y:=DRAN(); DL2:=MASABS(J1Y); DPR(DL2,ML,AL,AL2);
      IF AL1+AL2 >= BETA THEN AL:=AL+1; END;
      RETURN(AL);
(*4*) END MDRAN;


PROCEDURE MDSUM(ML,AL,BL: LIST): LIST;
(*Modular digit sum.  m is a positive beta-integer.  a and b belong
to Z sub m.  c=a+b.*)
VAR  CL, CLP: LIST;
BEGIN
(*1*) CL:=AL+BL; CLP:=CL-ML;
      IF CLP >= 0 THEN CL:=CLP; END;
      RETURN(CL);
(*4*) END MDSUM;


PROCEDURE MIDCRA(M,ML,MLP,A,AL: LIST): LIST;
(*Modular integer digit chinese remainder algorithm.  M is a positive
integer.  m is an odd positive beta-integer.  GCD(M,m)=1.  mp is the
inverse of the image of M under the homomorphism H sub m.  A and a
are elements of Z prime sub M and Z sub m respectively.  AS is the
unique element of Z prime sub MS which is congruent to A modulo M and
congruent to a modulo m, where MS=M*m.*)
VAR  ALB, AS, BL, DL, J1Y: LIST;
BEGIN
(*1*) (*as=a.*) ALB:=MDHOM(ML,A); DL:=MDDIF(ML,AL,ALB);
      IF DL = 0 THEN AS:=A; RETURN(AS); END;
(*2*) (*general case.*) BL:=MDPROD(ML,DL,MLP);
      IF BL+BL > ML THEN BL:=BL-ML; END;
      J1Y:=IDPR(M,BL); AS:=ISUM(J1Y,A); RETURN(AS);
(*5*) END MIDCRA;


PROCEDURE MIDIF(M,A,B: LIST): LIST;
(*Modular integer difference.  M is a positive integer.  A and B
belong to Z sub M.  C=A-B.*)
VAR  C: LIST;
BEGIN
(*1*) C:=IDIF(A,B);
      IF ISIGNF(C) < 0 THEN C:=ISUM(M,C); END;
      RETURN(C);
(*4*) END MIDIF;


PROCEDURE MIEXP(M,A,N: LIST): LIST;
(*Modular integer exponentiation.  M is a positive integer.  A is an
element of Z(M).  N is a non-negative integer.  B=A**N in Z(M).*)
VAR  B, NP, TL: LIST;
BEGIN
(*1*) (*single precision.*)
      IF (M < BETA) AND (N < BETA) THEN B:=MDEXP(M,A,N); RETURN(B);
         END;
(*2*) (*n less than or equal to 1.*)
      IF N = 0 THEN B:=1; RETURN(B); END;
      IF N = 1 THEN B:=A; RETURN(B); END;
(*3*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*4*) (*recursion.*) IDQR(N,2,NP,TL); B:=MIEXP(M,A,NP);
      B:=MIPROD(M,B,B);
      IF TL = 1 THEN B:=MIPROD(M,B,A); END;
      RETURN(B);
(*7*) END MIEXP;


PROCEDURE MIHOM(M,A: LIST): LIST;
(*Modular integer homomorphism.  M is a positive integer.  A is an
integer.  AS=H sub M(A).*)
VAR  AS: LIST;
BEGIN
(*1*) AS:=IREM(A,M);
      IF ISIGNF(AS) < 0 THEN AS:=ISUM(M,AS); END;
      RETURN(AS);
(*4*) END MIHOM;


PROCEDURE MIINV(M,A: LIST): LIST;
(*Modular integer inverse.  M is a positive integer.  A is a unit of
Z sub M.  B=A**-1.*)
VAR  B, C, UL: LIST;
BEGIN
(*1*) IF M < BETA THEN DEGCD(M,A,C,UL,B); ELSE IHEGCD(M,A,C,B); END;
      IF ISIGNF(B) < 0 THEN B:=ISUM(M,B); END;
      RETURN(B);
(*4*) END MIINV;


PROCEDURE MINEG(M,A: LIST): LIST;
(*Modular integer negation.  M is a positive integer.  A belongs to
Z sub M.  B=-A.*)
VAR  B: LIST;
BEGIN
(*1*) IF A = 0 THEN B:=0; ELSE B:=IDIF(M,A); END;
      RETURN(B);
(*4*) END MINEG;


PROCEDURE MIPROD(M,A,B: LIST): LIST;
(*Modular integer product.  M is a positive integer.  A and B belong to
Z(M).  C=A*B in Z(M).*)
VAR  C, J1Y: LIST;
BEGIN
(*1*) J1Y:=IPROD(A,B); C:=IREM(J1Y,M); RETURN(C);
(*4*) END MIPROD;


PROCEDURE MIQ(M,A,B: LIST): LIST;
(*Modular integer quotient.  M is a positive integer.  A and B belong
to Z sub M.  B is a unit.  C=A/B.*)
VAR  C, J1Y: LIST;
BEGIN
(*1*) J1Y:=MIINV(M,B); C:=MIPROD(M,A,J1Y); RETURN(C);
(*4*) END MIQ;


PROCEDURE MIRAN(M: LIST): LIST;
(*Modular integer, random.  M is a positive integer.  R is a uniformly
distributed random element of Z sub M.*)
VAR  J1Y, R: LIST;
BEGIN
(*1*) J1Y:=ILOG2(M); J1Y:=J1Y+ZETA; J1Y:=IRAND(J1Y); R:=MIHOM(M,J1Y);
      RETURN(R);
(*4*) END MIRAN;


PROCEDURE MISUM(M,A,B: LIST): LIST;
(*Modular integer sum.  M is a positive integer.  A and B belong to
Z sub M.  C=A+B.*)
VAR  C, CP: LIST;
BEGIN
(*1*) C:=ISUM(A,B); CP:=IDIF(C,M);
      IF ISIGNF(CP) >= 0 THEN C:=CP; END;
      RETURN(C);
(*4*) END MISUM;


PROCEDURE SMFMI(M,A: LIST): LIST;
(*Symmetric modular from modular integer.  M is a positive integer.
A belongs to Z sub M.  B belongs to Z prime sub M with B=A(modulo M).*)
VAR  B: LIST;
BEGIN
(*1*) B:=IDIF(A,M);
      IF ICOMP(A,INEG(B)) <= 0 THEN B:=A; END;
      RETURN(B);
(*4*) END SMFMI;


END SACM.


(* -EOF- *)
