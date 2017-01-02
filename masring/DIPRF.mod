(* ----------------------------------------------------------------------------
 * $Id: DIPRF.mi,v 1.4 1994/11/28 21:19:07 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRF.mi,v $
 * Revision 1.4  1994/11/28  21:19:07  dolzmann
 * Bug fix in RFSUM.
 *
 * Revision 1.3  1992/10/15  16:29:38  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:22  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:58  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPRF;

(* DIP Rational Function Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, FIRST, ADV, RED, COMP,
                    LENGTH, LIST1, SRED, SFIRST, INV;

FROM MASERR IMPORT severe, ERROR;

FROM MASBIOS IMPORT BLINES, SWRITE, CWRITE, CREAD, CREADB,
                    BKSP, MASORD, LETTER, DIGIT;

FROM SACLIST IMPORT EQUAL, SECOND, FIRST2, CINV, 
                    COMP2, FIRST3, LIST3, LIST2, ADV2, AWRITE;

FROM SACI IMPORT IREAD, IWRITE;

FROM SACPOL IMPORT PINV, VREAD, VLSRCH, VLWRIT;

FROM SACIPOL IMPORT IPSUM, IPQ, IPPROD, IPONE, IPSIGN, IPNEG;

FROM DIPC IMPORT PMPV, DIPFP, PFDIP, EPREAD;

FROM DIPI IMPORT DIIPSG, DIIPNG, DIIPWR, DIIPRD; 

FROM SACPGCD IMPORT IPGCDC;

CONST rcsidi = "$Id: DIPRF.mi,v 1.4 1994/11/28 21:19:07 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE IFWRIT(R,V: LIST); 
(*Integral function write. R is an integral function.  
R is the variable list. R is written in the output stream. *)
VAR  AL, RL, RP: LIST; 
BEGIN
(*1*) (*advance. *) FIRST2(R, RL,AL); 
      IF AL = 0 THEN AWRITE(AL); RETURN; END; 
(*2*) (*r non zero. *) AL:=DIPFP(RL,AL); 
      IF DIIPSG(AL) < 0 THEN SWRITE("-"); AL:=DIIPNG(AL); END; 
      DIIPWR(AL,V); 
(*5*) RETURN; END IFWRIT; 


PROCEDURE RFDEN(R: LIST): LIST; 
(*Rational function denominator.  R is a rational function.
BL is the denominator of R, a positive integral polynomial
in RL variables. *)
VAR  AL, BL, I, RL, RP: LIST; 
BEGIN
(*1*) (*advance. *) ADV2(R, RL,AL,RP); 
      IF AL <> 0 THEN BL:=FIRST(RP); RETURN(BL); END; 
      BL:=1; 
      FOR I:=1 TO RL DO BL:=LIST2(0,BL); END; 
(*4*) RETURN(BL); END RFDEN; 


PROCEDURE RFDIF(R,S: LIST): LIST; 
(*Rational function difference.  R and S are rational functions.
T=R-S. *)
VAR  SP, T: LIST; 
BEGIN
(*1*) (*negate and sum. *) SP:=RFNEG(S); T:=RFSUM(R,SP); 
(*4*) RETURN(T); END RFDIF; 


PROCEDURE RFEXP(A,NL: LIST): LIST; 
(*Rational function exponentiation.  A is a rational function,
n is a non-negative beta-integer.  B=A**n. *)
VAR  B, I, KL, RL: LIST; 
BEGIN
(*1*) (*nl less than or equal to 1. *) 
      IF NL = 0 THEN RL:=RFNOV(A); B:=1; 
         FOR I:=1 TO RL DO B:=LIST2(0,B); END; 
         B:=RFFIP(RL,B); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion. *) KL:=NL DIV 2; B:=RFEXP(A,KL); B:=RFPROD(B,B); 
      IF NL > 2*KL THEN B:=RFPROD(B,A); END; 
(*5*) RETURN(B); END RFEXP; 


PROCEDURE RFFIP(RL,A: LIST): LIST; 
(*Rational function from integral polynomial. A is an integral
polynomial in RL variables. R is the rational function A/1. *)
VAR  B, R: LIST; 
BEGIN
(*1*) (*a zero. *) 
      IF A = 0 THEN R:=LIST2(RL,A); RETURN(R); END; 
      B:=PINV(0,1,RL); R:=LIST3(RL,A,B); 
(*4*) RETURN(R); END RFFIP; 


PROCEDURE RFINV(R: LIST): LIST; 
(*Rational function inverse. R is a non-zero rational
function. S=1/R. *)
VAR  R1, R2, RL, RP, S, S1, S2: LIST; 
BEGIN
(*1*) (*advance. *) FIRST3(R, RL,R1,R2); 
      IF IPSIGN(RL,R1) > 0 THEN S1:=R2; S2:=R1; ELSE
         S1:=IPNEG(RL,R2); S2:=IPNEG(RL,R1); END; 
      S:=LIST3(RL,S1,S2); 
(*4*) RETURN(S); END RFINV; 


PROCEDURE RFNEG(R: LIST): LIST; 
(*Rational function negative. R is a rational function. S=-R. *)
VAR  R1, RL, RP, RP1, S: LIST; 
BEGIN
(*1*) (*advance. *) ADV2(R, RL,R1,RP); 
      IF R1 = 0 THEN S:=R; ELSE RP1:=IPNEG(RL,R1); 
         S:=COMP2(RL,RP1,RP); END; 
(*4*) RETURN(S); END RFNEG; 


PROCEDURE RFNOV(R: LIST): LIST; 
(*Rational function number of variables. R is a rational
function. RL is the number of variables of the numerator
and denumerator of R. *)
VAR  RL: LIST; 
BEGIN
(*1*) (*advance. *) RL:=FIRST(R); 
(*4*) RETURN(RL); END RFNOV; 


PROCEDURE RFNUM(R: LIST): LIST; 
(*Rational function numerator.  R is a rational function.
AL is the numerator of R, an integral polynomial. *)
VAR  AL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=SECOND(R); 
(*4*) RETURN(AL); END RFNUM; 


PROCEDURE RFONE(R: LIST): LIST; 
(*Rational function one.  R is a rational function.  s=1 if R=1,
s=0 else. *)
VAR  A, B, RL, RP, SL: LIST; 
BEGIN
(*1*) (*denominator=numerator. *) ADV2(R, RL,A,RP); SL:=0; 
      IF A = 0 THEN RETURN(SL); END; 
      B:=FIRST(RP); SL:=EQUAL(A,B); 
(*4*) RETURN(SL); END RFONE; 


PROCEDURE RFPROD(R,S: LIST): LIST; 
(*Rational function product.  R and S are rational functions.
T=R*S. *)
VAR  AL, BL, D1, D2, R1, R2, RB1, RB2, RL, RP, S1, S2, SB1, SB2, SP, T,
     T1, T2: LIST; 
BEGIN
(*1*) (*r=0 or s=0. *) ADV2(R, RL,R1,RP); ADV2(S, RL,S1,SP); 
      IF (R1 = 0) OR (S1 = 0) THEN T:=LIST2(RL,0); RETURN(T); 
         END; 
(*2*) (*obtain numerators and denominators. *) R2:=FIRST(RP); 
      S2:=FIRST(SP); AL:=IPONE(RL,R2); BL:=IPONE(RL,S2); 
(*3*) (*r and s integers. *) 
      IF (AL = 1) AND (BL = 1) THEN T1:=IPPROD(RL,R1,S1); 
         T:=LIST3(RL,T1,R2); RETURN(T); END; 
(*4*) (*r or s an integer. *) 
      IF AL = 1 THEN IPGCDC(RL,R1,S2, D1,RB1,SB2); 
         T1:=IPPROD(RL,RB1,S1); T:=LIST3(RL,T1,SB2); RETURN(T); END; 
      IF BL = 1 THEN IPGCDC(RL,S1,R2, D2,SB1,RB2); 
         T1:=IPPROD(RL,SB1,R1); T:=LIST3(RL,T1,RB2); RETURN(T); END; 
(*5*) (*general case. *) IPGCDC(RL,R1,S2, D1,RB1,SB2); IPGCDC(RL,S1,R2,
      D2,SB1,RB2); T1:=IPPROD(RL,RB1,SB1); T2:=IPPROD(RL,RB2,SB2); 
      T:=LIST3(RL,T1,T2); 
(*8*) RETURN(T); END RFPROD; 


PROCEDURE RFQ(R,S: LIST): LIST; 
(*Rational function quotient. R and S are rational functions,
S non-zero. T=R/S. *)
VAR  AL, SP, T: LIST; 
BEGIN
(*1*) (*r zero. *) AL:=RFNUM(R); 
      IF AL = 0 THEN T:=R; ELSE SP:=RFINV(S); T:=RFPROD(R,SP); END; 
(*4*) RETURN(T); END RFQ; 


PROCEDURE RFREAD(V: LIST): LIST; 
(*Rational function read. The rational function R is read
from the input stream. V is the variable list. any preceding
blanks are skipped. *)
VAR  C, EL, JL, R, R1, R2, RL, RLS, VL: LIST; 
BEGIN
LOOP
(*1*) (*read nominator. *) R:=LIST2(0,0); RL:=LENGTH(V); C:=CREADB(); 
      IF C = MASORD("/") THEN R1:=PINV(0,1,RL); 
         EXIT (*GO TO 2;*) END; 
      BKSP; 
      IF C = MASORD("(") THEN R1:=DIIPRD(V); PFDIP(R1, RLS,R1); 
         EXIT (*GO TO 2;*) END; 
      IF DIGIT(C) THEN R1:=IREAD(); R1:=PINV(0,R1,RL); 
         EXIT (*GO TO 2;*) END; 
      IF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); R1:=PINV(0,1,RL); 
         IF JL = 0 THEN R:=RFFIP(RL,R1); RETURN(R); END; 
         EL:=EPREAD(); R1:=PMPV(RL,R1,JL,EL); 
         EXIT (*GO TO 2;*) END; 
      (*GO TO 4;*) 
      ERROR(severe,"error found in RFREAD. "); RETURN(R); 
      END;
LOOP
(*2*) (*read denominator. *) C:=CREADB(); 
      IF C <> MASORD("/") THEN BKSP; R2:=PINV(0,1,RL); 
         EXIT (*GO TO 3;*) END; 
      C:=CREADB(); BKSP; 
      IF C = MASORD("(") THEN R2:=DIIPRD(V); PFDIP(R2, RLS,R2); 
         EXIT (*GO TO 3;*) END; 
      IF DIGIT(C) THEN R2:=IREAD(); R2:=PINV(0,R2,RL); 
         EXIT (*GO TO 3;*) END; 
      IF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); 
         IF JL <> 0 THEN  
            R2:=PINV(0,1,RL); EL:=EPREAD(); R2:=PMPV(RL,R2,JL,EL); 
            EXIT (*GO TO 3;*) END;
         END; 
      (*GO TO 4;*) 
      ERROR(severe,"error found in RFREAD. "); RETURN(R); 
      END;

(*3*) (*reduction to lowest terms. *) R:=RFRED(RL,R1,R2); RETURN(R); 

(*4*) (*error. *) ERROR(severe,"error found in RFREAD. ");  
(*7*) END RFREAD; 


PROCEDURE RFRED(RL,A,B: LIST): LIST; 
(*Rational function reduction to lowest terms.  A and B are
integral polynomials in RL variables, B non-zero. R is the
rational function A/B in canonical form. *)
VAR  AP, BP, C, R, SL: LIST; 
BEGIN
(*1*) (*a zero. *) 
      IF A = 0 THEN R:=LIST2(RL,0); RETURN(R); END; 
(*2*) (*greatest common divisor. *) IPGCDC(RL,A,B, C,AP,BP); 
      SL:=IPSIGN(RL,BP); 
      IF SL < 0 THEN AP:=IPNEG(RL,AP); BP:=IPNEG(RL,BP); END; 
      R:=LIST3(RL,AP,BP); 
(*5*) RETURN(R); END RFRED; 


PROCEDURE RFSIGN(R: LIST): LIST; 
(*Rational function sign.  R is a rational function.  s=sign(R). *)
VAR  A, RL, SL: LIST; 
BEGIN
(*1*) (*sign of numerator. *) FIRST2(R, RL,A); SL:=IPSIGN(RL,A); 
(*4*) RETURN(SL); END RFSIGN; 


PROCEDURE RFSUM(R,S: LIST): LIST; 
(*Rational function sum.  R and S are rational functions.  T=R+S. *)
VAR  AL, BL, D, DP, E, R1, R2, RB2, RL, RP, S1, S2, SB2, SP, T, T1,
     T2: LIST; 
BEGIN
(*1*) (*r=0 or s=0. *) ADV2(R, RL,R1,RP); ADV2(S, RL,S1,SP); 
      IF R1 = 0 THEN T:=S; RETURN(T); END; 
      IF S1 = 0 THEN T:=R; RETURN(T); END; 
(*2*) (*obtain numerators and denominators. *) R2:=FIRST(RP); 
      S2:=FIRST(SP); AL:=IPONE(RL,R2); BL:=IPONE(RL,S2); 
(*3*) (*r and s integers. *) 
      IF (AL = 1) AND (BL = 1) THEN T1:=IPSUM(RL,R1,S1); 
(* ADo *) IF T1=0 THEN RETURN LIST2(RL,T1); END; (* oDA *)      
         T:=LIST3(RL,T1,R2); RETURN(T); END; 
(*4*) (*r or s an integer. *) 
      IF AL = 1 THEN T1:=IPPROD(RL,R1,S2); T1:=IPSUM(RL,T1,S1); 
         T:=LIST3(RL,T1,S2); RETURN(T); END; 
      IF BL = 1 THEN T1:=IPPROD(RL,R2,S1); T1:=IPSUM(RL,T1,R1); 
         T:=LIST3(RL,T1,R2); RETURN(T); END; 
(*5*) (*general case. *) IPGCDC(RL,R2,S2, D,RB2,SB2); 
      T1:=IPPROD(RL,R1,SB2); T2:=IPPROD(RL,RB2,S1); T1:=IPSUM(RL,T1,T2); 
      IF T1 = 0 THEN T:=LIST2(RL,0); RETURN(T); END; 
      IF IPONE(RL,D) <> 1 THEN IPGCDC(RL,T1,D, E,T1,DP); 
         IF IPONE(RL,E) <> 1 THEN R2:=IPQ(RL,R2,E); END; 
         END; 
      T2:=IPPROD(RL,R2,SB2); T:=LIST3(RL,T1,T2); 
(*8*) RETURN(T); END RFSUM; 


PROCEDURE RFWRIT(R,V: LIST); 
(*Rational function write. R is a rational function.  V is the 
variable list. R is written in the output stream. *)
VAR  AL, BL, RL, RP: LIST; 
BEGIN
(*1*) (*advance. *) ADV2(R, RL,AL,RP); 
      IF AL = 0 THEN AWRITE(AL); RETURN; END; 
(*2*) (*r non zero. *) AL:=DIPFP(RL,AL); 
      IF DIIPSG(AL) < 0 THEN SWRITE("-"); AL:=DIIPNG(AL); END; 
      DIIPWR(AL,V); BL:=FIRST(RP); 
      IF IPONE(RL,BL) <> 1 THEN SWRITE("/"); BL:=DIPFP(RL,BL); 
         DIIPWR(BL,V); END; 
(*5*) RETURN; END RFWRIT; 


END DIPRF.
(* -EOF- *)
