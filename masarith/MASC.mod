(* ----------------------------------------------------------------------------
 * $Id: MASC.mi,v 1.3 1992/10/15 16:28:10 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASC.mi,v $
 * Revision 1.3  1992/10/15  16:28:10  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/09/28  18:34:51  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:29:12  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASC;

(* MAS Complex Number Implementation Module. *)


(* Import lists and declarations. *)

FROM MASBIOS IMPORT SWRITE, CWRITE, CREADB, MASORD, BKSP, BLINES;

FROM MASSTOR IMPORT LIST, ADV, COMP, FIRST, SIL; 

FROM MASERR IMPORT severe, ERROR;

FROM SACLIST IMPORT OWRITE, SECOND, FIRST2, LIST2, COMP2,  
                    AWRITE, EQUAL;

FROM SACRN IMPORT RNSUM, RNPROD, RNCOMP, RNNEG, RNDIF, 
                  RNQ, RNINT, RNREAD, RNWRIT, RNRAND;

FROM MASRN IMPORT RNDWR, RNDRD, RNONE;

CONST rcsidi = "$Id: MASC.mi,v 1.3 1992/10/15 16:28:10 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* Representation of a + i b, with a, b rational numbers, is 

                         0   if a=0 and b=0 
                     (a,b)   else   *)


PROCEDURE CABS(R: LIST): LIST;
(*Complex number absolute value.  R is a complex number.  S is the
absolute value of R, a rational number. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN S:=R; RETURN(S) END;
(*2*) FIRST2(R,r,i); 
      S:=RNSUM(RNPROD(r,r),RNPROD(i,i));
      RETURN(S);
(*4*) END CABS;


PROCEDURE CCON(R: LIST): LIST;
(*Complex number conjugate.  R is a complex number. S is the
complex conjugate of R. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      S:=COMP2(r,RNNEG(i),SIL);
      RETURN(S);
(*4*) END CCON;


PROCEDURE CCOMP(R,S: LIST): LIST;
(*Complex number comparison.  R and S are complex numbers.
t=0 if R=S, t=1 else. *)
VAR   t: LIST;
BEGIN
(*1*) t:=EQUAL(R,S); 
      IF t = 1 THEN t:=0 ELSE t:=1 END;  
      RETURN(t);
(*4*) END CCOMP;


PROCEDURE CDIF(R,S: LIST): LIST;
(*Complex number difference.  R and S are complex numbers.  T=R-S. *)
VAR   T, r1, i1, r2, i2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=CNEG(S); RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r1:=RNDIF(r1,r2); i1:=RNDIF(i1,i2); 
      IF (r1 = 0) AND (i1 = 0) THEN T:=0; RETURN(T) END;
      T:=COMP2(r1,i1,SIL);
      RETURN(T);
(*4*) END CDIF;


PROCEDURE CDREAD(): LIST; 
(*Complex number decimal read.  The complex number R is read
from the input stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, c: LIST;
BEGIN
(*1*) r:=RNDRD(); i:=0; 
      c:=CREADB(); 
      IF c = MASORD("i") THEN i:=RNDRD(); ELSE BKSP; END;  
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      R:=COMP2(r,i,SIL);
      RETURN(R);
(*4*) END CDREAD;


PROCEDURE CDWRITE(R,NL: LIST); 
(*Complex number decimal write.  R is a complex number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)
VAR   r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST2(R,r,i); 
      RNDWR(r,NL); 
      IF i <> 0 THEN SWRITE(" i "); RNDWR(i,NL) END;  
(*4*) END CDWRITE;


PROCEDURE CEXP(A,NL: LIST): LIST; 
(*Complex number exponentiation.  A is a complex number,
n is a non-negative beta-integer.  B=A**n. *)
VAR   B, KL: LIST; 
BEGIN
(*1*) (*n less than or equal to 1.*) 
      IF NL = 0 THEN B:=CINT(1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=CEXP(A,KL); B:=CPROD(B,B); 
      IF NL > 2*KL THEN B:=CPROD(B,A); END; 
      RETURN(B); 
(*5*) END CEXP; 


PROCEDURE CIM(R: LIST): LIST;
(*Complex number imaginary part.  R is a complex number.  b is the
imaginary part of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(SECOND(R));
(*4*) END CIM;


PROCEDURE CINT(A: LIST): LIST;
(*Complex number from integer.  A is an integer.  R is the complex
number with real part A/1 and imaginary part 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN R:=A; RETURN(R) END;
(*2*) R:=COMP2(RNINT(A),0,SIL); 
      RETURN(R);
(*4*) END CINT;


PROCEDURE CRE(R: LIST): LIST;
(*Complex number real part.  R is a complex number.  b is the
real part of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(FIRST(R));
(*4*) END CRE;


PROCEDURE CRN(A: LIST): LIST;
(*Complex number from rational number.  A is a rational number.  
R is the complex number with real part A and imaginary part 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN RETURN(0) END;
(*2*) R:=COMP2(A,0,SIL); 
      RETURN(R);
(*4*) END CRN;


PROCEDURE CRNP(A, B: LIST): LIST;
(*Complex number from pair of rational numbers.  A and B are 
rational numbers.  R is the complex number with real part A 
and imaginary part B. *)
VAR   R: LIST;
BEGIN
(*1*) IF (A = 0) AND (B = 0) THEN RETURN(0) END;
(*2*) R:=COMP2(A,B,SIL); 
      RETURN(R);
(*4*) END CRNP;


PROCEDURE CNINV(R: LIST): LIST;
(*Complex number inverse.  R is a non-zero complex number.  S R=1. *)
VAR   S, r, i, a: LIST;
BEGIN
(*1*) IF R = 0 THEN ERROR(severe,"CINV: division by zero."); END;
(*2*) FIRST2(R,r,i); 
      a:=RNSUM(RNPROD(r,r),RNPROD(i,i));
      r:=RNQ(r,a); i:=RNQ(RNNEG(i),a); 
      S:=COMP2(r,i,SIL);
      RETURN(S);
(*4*) END CNINV;


PROCEDURE CNEG(R: LIST): LIST;
(*Complex number negative.  R is a complex number.  S=-R. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      S:=COMP2(RNNEG(r),RNNEG(i),SIL);
      RETURN(S);
(*4*) END CNEG;


PROCEDURE CONE(R: LIST): LIST; 
(*Complex number one.  R is a complex number.  s=1 if R=1,
s=0 else. *)
VAR   r, i, t: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      IF i <> 0 THEN RETURN(0) END;
      t:=RNONE(r); 
      RETURN(t);
(*4*) END CONE;


PROCEDURE CPROD(R,S: LIST): LIST;
(*Complex number product.  R and S are complex numbers.  T=R*S. *)
VAR   T, r1, i1, r2, i2, r, i: LIST;
BEGIN
(*1*) IF (R = 0) OR (S = 0) THEN RETURN(0) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r:=RNDIF(RNPROD(r1,r2),RNPROD(i1,i2)); 
      i:=RNSUM(RNPROD(r1,i2),RNPROD(i1,r2)); 
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      T:=COMP2(r,i,SIL);
      RETURN(T);
(*4*) END CPROD;


PROCEDURE CQ(R,S: LIST): LIST;
(*Complex number quotient.  R and S are complex numbers, S non-zero.
T=R/S. *)
VAR   T: LIST;
BEGIN
(*1*) T:=CPROD(R,CNINV(S)); 
      RETURN(T);
(*4*) END CQ;


PROCEDURE CRAND(NL: LIST): LIST;
(*Complex number, random.  n is a positive beta-integer.  Random 
rational numbers A and B are generated using RNRAND(n). Then 
R is the complex number with real part A and imaginary part B. *)
VAR   T, r, i: LIST;
BEGIN
(*1*) r:=RNRAND(NL); i:=RNRAND(NL); 
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      T:=COMP2(r,i,SIL);
      RETURN(T);
(*4*) END CRAND;


PROCEDURE CNREAD(): LIST;
(*Complex number read.  The complex number R is read from the input
stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, c: LIST;
BEGIN
(*1*) r:=RNREAD(); i:=0; 
      c:=CREADB(); 
      IF c = MASORD("i") THEN i:=RNREAD(); ELSE BKSP; END;  
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      R:=COMP2(r,i,SIL);
      RETURN(R);
(*4*) END CNREAD;


PROCEDURE CSUM(R,S: LIST): LIST;
(*Complex number sum.  R and S are complex numbers.  T=R+S. *)
VAR   T, r1, i1, r2, i2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=S; RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r1:=RNSUM(r1,r2); i1:=RNSUM(i1,i2); 
      IF (r1 = 0) AND (i1 = 0) THEN T:=0; RETURN(T) END;
      T:=COMP2(r1,i1,SIL);
      RETURN(T);
(*4*) END CSUM;


PROCEDURE CNWRITE(R: LIST);
(*Complex number write. R is a complex number.  R is converted 
to decimal and written in the output stream. *)
VAR   r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST2(R,r,i); 
      RNWRIT(r); 
      IF i <> 0 THEN SWRITE(" i "); RNWRIT(i) END;  
(*4*) END CNWRITE;



END MASC.




(* -EOF- *)
