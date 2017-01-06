(* ----------------------------------------------------------------------------
 * $Id: SACRN.mi,v 1.3 1992/10/15 16:28:21 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACRN.mi,v $
 * Revision 1.3  1992/10/15  16:28:21  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:18  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:46  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACRN;

(* SAC Rational Number Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASABS;

FROM MASBIOS IMPORT SWRITE, CWRITE, CREADB, MASORD, BKSP, BLINES;

FROM MASSTOR IMPORT LIST, ADV, COMP, FIRST;

FROM SACLIST IMPORT OWRITE, SECOND, FIRST2, LIST2, AWRITE;

FROM SACI IMPORT IQR, ISIGNF, ISUM, IPROD, ICOMP, INEG, 
                 IEXP, IDPR, IWRITE, IREAD, IFCL2, IABSF,
                 IGCDCF, IRAND, IGCD, IQ, IMP2;

CONST rcsidi = "$Id: SACRN.mi,v 1.3 1992/10/15 16:28:21 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RIRNP(I,CL: LIST): LIST;
(*Rational interval rational number product.  I is an interval with
rational endpoints.  c is a rational number.  J is the interval I*c.*)
VAR  AL, ALP, BL, BLP, J: LIST;
BEGIN
(*1*) FIRST2(I,AL,BL); ALP:=RNPROD(AL,CL); BLP:=RNPROD(BL,CL);
      IF RNSIGN(CL) >= 0 THEN J:=LIST2(ALP,BLP); ELSE
         J:=LIST2(BLP,ALP); END;
      RETURN(J);
(*4*) END RIRNP;


PROCEDURE RNABS(R: LIST): LIST;
(*Rational number absolute value.  R is a rational number.  S is the
absolute value of R.*)
VAR  S: LIST;
BEGIN
(*1*) IF RNSIGN(R) >= 0 THEN S:=R; ELSE S:=RNNEG(R); END;
      RETURN(S);
(*4*) END RNABS;


PROCEDURE RNCEIL(RL: LIST): LIST;
(*Rational number, ceiling of.  r is a rational number.  a=CEILING(r), 
an integer.*)
VAR  AL, BL, RL1, RL2, SL: LIST;
BEGIN
(*1*) (*rl=0.*)
      IF RL = 0 THEN AL:=0; RETURN(AL); END;
(*2*) (*rl ne 0.*) FIRST2(RL,RL1,RL2); IQR(RL1,RL2,AL,BL);
      SL:=ISIGNF(BL);
      IF SL > 0 THEN AL:=ISUM(AL,SL); END;
      RETURN(AL);
(*5*) END RNCEIL;


PROCEDURE RNCOMP(R,S: LIST): LIST;
(*Rational number comparison.  R and S are rational numbers.
t=SIGN(R-S).*)
VAR  J1Y, J2Y, R1, R2, RL, S1, S2, SL, TL: LIST;
BEGIN
(*1*) (*r or s zero.*)
      IF R = 0 THEN J1Y:=RNSIGN(S); TL:=-J1Y; RETURN(TL); END;
      IF S = 0 THEN TL:=RNSIGN(R); RETURN(TL); END;
(*2*) (*opposite signs.*) FIRST2(R,R1,R2); FIRST2(S,S1,S2);
      RL:=ISIGNF(R1); SL:=ISIGNF(S1); J1Y:=RL-SL; TL:=J1Y DIV 2;
      IF TL <> 0 THEN RETURN(TL); END;
(*3*) (*same sign.*) J1Y:=IPROD(R1,S2); J2Y:=IPROD(R2,S1);
      TL:=ICOMP(J1Y,J2Y); RETURN(TL);
(*6*) END RNCOMP;


PROCEDURE RNDEN(R: LIST): LIST;
(*Rational number denominator.  R is a rational number.  b is the
denominator of R, a positive integer.*)
VAR  BL: LIST;
BEGIN
(*1*) IF R = 0 THEN BL:=1; ELSE BL:=SECOND(R); END;
      RETURN(BL);
(*4*) END RNDEN;


PROCEDURE RNDIF(R,S: LIST): LIST;
(*Rational number difference.  R and S are rational numbers.  T=R-S.*)
VAR  J1Y, T: LIST;
BEGIN
(*1*) J1Y:=RNNEG(S); T:=RNSUM(R,J1Y); RETURN(T);
(*4*) END RNDIF;


PROCEDURE RNDWR(R,NL: LIST);
(*Rational number decimal write.  R is a rational number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n.  If ABS(D) is greater than ABS(R) then the last digit is
followed by a minus sign, if ABS(D) is less than ABS(R) then by a
plus sign.*)
VAR  A, B, D, DL, F, IL, M, SL, TL: LIST;
BEGIN
(*1*) (*compute approximation.*)
      IF R = 0 THEN A:=0; B:=1; ELSE FIRST2(R,A,B); END;
      SL:=ISIGNF(A);
      IF SL < 0 THEN A:=INEG(A); END;
      M:=IEXP(10,NL); A:=IPROD(A,M); IQR(A,B,D,F); F:=IDPR(F,2);
      IF F = 0 THEN TL:=0; ELSE TL:=ICOMP(B,F);
         IF TL = 0 THEN TL:=1; ELSE
            IF TL < 0 THEN D:=ISUM(D,1); END;
            END;
         END;
(*2*) (*convert and write.*)
      IF SL < 0 THEN SWRITE("-"); END;
      IQR(D,M,D,F); IWRITE(D); SWRITE(".");
      FOR IL:=1 TO NL DO F:=IDPR(F,10); IQR(F,M,DL,F); CWRITE(DL); END;
      IF TL > 0 THEN SWRITE("+"); ELSE
         IF TL < 0 THEN SWRITE("-"); END;
         END;
      RETURN;
(*5*) END RNDWR;


PROCEDURE RNFCL2(AL: LIST; VAR ML,NL: LIST);
(*Rational number floor and ceiling of logarithm, base 2.  a is a non-
zero rational number.  m=FLOOR(LOG2(ABS(a))) and n=CEILING(LOG2(ABS(a))) 
are gamma-integers.*)
VAR  AL1, AL2, ALP1, CL, DL, J1Y, ML1, ML2, NL1, NL2, SL: LIST;
BEGIN
(*1*) (*apply ifcl2 to numerator and denominator.*) FIRST2(AL,AL1,AL2);
      IFCL2(AL1,ML1,NL1); IFCL2(AL2,ML2,NL2); ML:=ML1-NL2; NL:=NL1-ML2;
(*2*) (*nl le ml+1.*)
      IF NL <= ML+1 THEN RETURN; END;
(*3*) (*resolve uncertainty.*) ALP1:=IABSF(AL1);
      IF ML+1 >= 0 THEN CL:=ALP1; J1Y:=ML+1; DL:=IMP2(AL2,J1Y); ELSE
         J1Y:=-ML; J1Y:=J1Y-1; CL:=IMP2(ALP1,J1Y); DL:=AL2; END;
      SL:=ICOMP(CL,DL);
      IF SL < 0 THEN NL:=NL-1; ELSE ML:=ML+1; END;
      RETURN;
(*6*) END RNFCL2;


PROCEDURE RNFLOR(RL: LIST): LIST;
(*Rational number, floor of.  r is a rational number.  a=FLOOR(r),
an integer.*)
VAR  AL, BL, RL1, RL2, SL: LIST;
BEGIN
(*1*) (*rl=0.*)
      IF RL = 0 THEN AL:=0; RETURN(AL); END;
(*2*) (*rl ne 0.*) FIRST2(RL,RL1,RL2); IQR(RL1,RL2,AL,BL);
      SL:=ISIGNF(BL);
      IF SL < 0 THEN AL:=ISUM(AL,SL); END;
      RETURN(AL);
(*5*) END RNFLOR;


PROCEDURE RNINT(A: LIST): LIST;
(*Rational number from integer.  A is an integer.  R is the rational
number A/1.*)
VAR  R: LIST;
BEGIN
(*1*) IF A = 0 THEN R:=0; ELSE R:=LIST2(A,1); END;
      RETURN(R);
(*4*) END RNINT;


PROCEDURE RNINV(R: LIST): LIST;
(*Rational number inverse.  R is a non-zero rational number.  S=1/R.*)
VAR  R1, R2, S, S1, S2: LIST;
BEGIN
(*1*) FIRST2(R,R1,R2);
      IF ISIGNF(R1) > 0 THEN S1:=R2; S2:=R1; ELSE S1:=INEG(R2);
         S2:=INEG(R1); END;
      S:=LIST2(S1,S2); RETURN(S);
(*4*) END RNINV;


PROCEDURE RNNEG(R: LIST): LIST;
(*Rational number negative.  R is a rational number.  S=-R.*)
VAR  R1, RP, RP1, S: LIST;
BEGIN
(*1*) IF R = 0 THEN S:=0; ELSE ADV(R,R1,RP); RP1:=INEG(R1);
         S:=COMP(RP1,RP); END;
      RETURN(S);
(*4*) END RNNEG;


PROCEDURE RNNUM(R: LIST): LIST;
(*Rational number numerator.  R is a rational number.  a is the
numerator of R, an integer.*)
VAR  AL: LIST;
BEGIN
(*1*) IF R = 0 THEN AL:=0; ELSE AL:=FIRST(R); END;
      RETURN(AL);
(*4*) END RNNUM;


PROCEDURE RNPROD(R,S: LIST): LIST;
(*Rational number product.  R and S are rational numbers.  T=R*S.*)
VAR  D1, D2, R1, R2, RB1, RB2, S1, S2, SB1, SB2, T, T1, T2: LIST;
BEGIN
(*1*) (*r=0 or s=0.*)
      IF (R = 0) OR (S = 0) THEN T:=0; RETURN(T); END;
(*2*) (*obtain numerators and denominators.*) FIRST2(R,R1,R2);
      FIRST2(S,S1,S2);
(*3*) (*r and s integers.*)
      IF (R2 = 1) AND (S2 = 1) THEN T1:=IPROD(R1,S1);
         T:=LIST2(T1,1); RETURN(T); END;
(*4*) (*r or s an integer.*)
      IF R2 = 1 THEN IGCDCF(R1,S2,D1,RB1,SB2); T1:=IPROD(RB1,S1);
         T:=LIST2(T1,SB2); RETURN(T); END;
      IF S2 = 1 THEN IGCDCF(S1,R2,D2,SB1,RB2); T1:=IPROD(SB1,R1);
         T:=LIST2(T1,RB2); RETURN(T); END;
(*5*) (*general case.*) IGCDCF(R1,S2,D1,RB1,SB2);
      IGCDCF(S1,R2,D2,SB1,RB2); T1:=IPROD(RB1,SB1); T2:=IPROD(RB2,SB2);
      T:=LIST2(T1,T2); RETURN(T);
(*8*) END RNPROD;


PROCEDURE RNP2(KL: LIST): LIST;
(*Rational number power of 2.  k is a gamma-integer.  r=2**k, a
rational number.*)
VAR  AL, HL, RL: LIST;
BEGIN
(*1*) HL:=MASABS(KL); AL:=IMP2(1,HL);
      IF KL >= 0 THEN RL:=LIST2(AL,1); ELSE RL:=LIST2(1,AL); END;
      RETURN(RL);
(*4*) END RNP2;


PROCEDURE RNQ(R,S: LIST): LIST;
(*Rational number quotient.  R and S are rational numbers, S non-zero.
T=R/S.*)
VAR  J1Y, T: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=0; ELSE J1Y:=RNINV(S); T:=RNPROD(R,J1Y); END;
      RETURN(T);
(*4*) END RNQ;


PROCEDURE RNRAND(NL: LIST): LIST;
(*Rational number, random.  n is a positive beta-integer.  Random
integers A and B are generated using IRAND(n).  Then R=A/(ABS(B)+1),
reduced to lowest terms.*)
VAR  A, B, R: LIST;
BEGIN
(*1*) A:=IRAND(NL); B:=IRAND(NL); B:=IABSF(B); B:=ISUM(B,1);
      R:=RNRED(A,B); RETURN(R);
(*4*) END RNRAND;


PROCEDURE RNREAD(): LIST;
(*Rational number read.  The rational number R is read from the input
stream.  Any preceding blanks are skipped.*)
VAR  C, IDUM, R, R1, R2: LIST;
BEGIN
(*1*) R1:=IREAD(); C:=CREADB();
      IF C = MASORD("/") THEN R2:=IREAD(); ELSE R2:=1; BKSP; END;
      IF R1 = 0 THEN R:=0; ELSE R:=LIST2(R1,R2); END;
      RETURN(R);
(*4*) END RNREAD;


PROCEDURE RNRED(A,B: LIST): LIST;
(*Rational number reduction to lowest terms.  A and B are integers,
B non-zero.  R is the rational number A/B in canonical form.*)
VAR  AB, BB, C, R: LIST;
BEGIN
(*1*) IF A = 0 THEN R:=0; RETURN(R); END;
      C:=IGCD(A,B); AB:=IQ(A,C); BB:=IQ(B,C);
      IF ISIGNF(B) < 0 THEN AB:=INEG(AB); BB:=INEG(BB); END;
      R:=LIST2(AB,BB); RETURN(R);
(*4*) END RNRED;


PROCEDURE RNSIGN(R: LIST): LIST;
(*Rational number sign.  R is a rational number.  s=SIGN(R).*)
VAR  J1Y, SL: LIST;
BEGIN
(*1*) IF R = 0 THEN SL:=0; ELSE J1Y:=FIRST(R); SL:=ISIGNF(J1Y); END;
      RETURN(SL);
(*4*) END RNSIGN;


PROCEDURE RNSUM(R,S: LIST): LIST;
(*Rational number sum.  R and S are rational numbers.  T=R+S.*)
VAR  D, E, J1Y, J2Y, R1, R2, RB2, S1, S2, SB2, T, T1, T2: LIST;
BEGIN
(*1*) (*r=0 or s=0.*)
      IF R = 0 THEN T:=S; RETURN(T); END;
      IF S = 0 THEN T:=R; RETURN(T); END;
(*2*) (*obtain numerators and denominators.*) FIRST2(R,R1,R2);
      FIRST2(S,S1,S2);
(*3*) (*r and s integers.*)
      IF (R2 = 1) AND (S2 = 1) THEN T1:=ISUM(R1,S1);
         IF T1 = 0 THEN T:=0; ELSE T:=LIST2(T1,1); END;
         RETURN(T); END;
(*4*) (*r or s an integer.*)
      IF R2 = 1 THEN T1:=IPROD(R1,S2); T1:=ISUM(T1,S1);
         T:=LIST2(T1,S2); RETURN(T); END;
      IF S2 = 1 THEN T1:=IPROD(R2,S1); T1:=ISUM(T1,R1);
         T:=LIST2(T1,R2); RETURN(T); END;
(*5*) (*general case.*) IGCDCF(R2,S2,D,RB2,SB2); J1Y:=IPROD(R1,SB2);
      J2Y:=IPROD(RB2,S1); T1:=ISUM(J1Y,J2Y);
      IF T1 = 0 THEN T:=0; RETURN(T); END;
      IF D <> 1 THEN E:=IGCD(T1,D);
         IF E <> 1 THEN T1:=IQ(T1,E); R2:=IQ(R2,E); END;
         END;
      T2:=IPROD(R2,SB2); T:=LIST2(T1,T2); RETURN(T);
(*8*) END RNSUM;


PROCEDURE RNWRIT(R: LIST);
(*Rational number write. R is a rational number.  R is converted 
to decimal and written in the output stream.*)
VAR  R1, R2: LIST;
BEGIN 
(*1*) IF R = 0 THEN AWRITE(R); ELSE FIRST2(R,R1,R2); IWRITE(R1);
         IF R2 <> 1 THEN SWRITE("/"); IWRITE(R2); END;
         END;
      RETURN;
(*4*) END RNWRIT;


END SACRN.


(* -EOF- *)
