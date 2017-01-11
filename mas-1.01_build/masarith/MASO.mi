(* ----------------------------------------------------------------------------
 * $Id: MASO.mi,v 1.3 1992/10/15 16:28:13 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASO.mi,v $
 * Revision 1.3  1992/10/15  16:28:13  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/09/28  18:34:53  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:30:31  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASO;

(* MAS Octonion Number Implementation Module. *)


(* Import lists and declarations. *)

FROM MASBIOS IMPORT SWRITE, CWRITE, CREADB, MASORD, BKSP, BLINES;

FROM MASSTOR IMPORT LIST, ADV, COMP, FIRST, SIL, INV; 

FROM MASERR IMPORT severe, ERROR;

FROM SACLIST IMPORT OWRITE, SECOND, FIRST2, LIST2, COMP2,  
                    AWRITE, EQUAL;

FROM SACRN IMPORT RNSUM, RNQ;

FROM MASQ IMPORT QCON, QABS, QNEG, QINT, QRN, QONE, QRAND, 
                 QPROD, QDIF, QSUM, 
                 QDREAD, QDWRITE, QNREAD, QNWRITE;

CONST rcsidi = "$Id: MASO.mi,v 1.3 1992/10/15 16:28:13 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* Representation of ( a, b ), with a, b quaternion numbers, is 

                         0   if a=0 and b=0 
                     (a,b)   else   *)


PROCEDURE OABS(R: LIST): LIST;
(*Octonion number absolute value.  R is a octonion number.  S is the
absolute value of R, a rational number. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN S:=R; RETURN(S) END;
(*2*) FIRST2(R,r,i); 
      S:=RNSUM(QABS(r),QABS(i));
      RETURN(S);
(*4*) END OABS;


PROCEDURE OCON(R: LIST): LIST;
(*Octonion number conjugate.  R is a octonion number. S is the
octonion conjugate of R. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      S:=COMP2(QCON(r),QNEG(i),SIL);
      RETURN(S);
(*4*) END OCON;


PROCEDURE OCOMP(R,S: LIST): LIST;
(*Octonion number comparison.  R and S are octonion numbers.
t=0 if R=S, t=1 else. *)
VAR   t: LIST;
BEGIN
(*1*) t:=EQUAL(R,S); 
      IF t = 1 THEN t:=0 ELSE t:=1 END;  
      RETURN(t);
(*4*) END OCOMP;


PROCEDURE ODIF(R,S: LIST): LIST;
(*Octonion number difference.  R and S are octonion numbers.  T=R-S. *)
VAR   T, r1, i1, r2, i2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=ONEG(S); RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r1:=QDIF(r1,r2); i1:=QDIF(i1,i2); 
      IF (r1 = 0) AND (i1 = 0) THEN T:=0; RETURN(T) END;
      T:=COMP2(r1,i1,SIL);
      RETURN(T);
(*4*) END ODIF;


PROCEDURE ODREAD(): LIST; 
(*Octonion number decimal read.  The octonion number R is read
from the input stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, c: LIST;
BEGIN
(*1*) r:=QDREAD(); i:=0; 
      c:=CREADB(); 
      IF c = MASORD("p") THEN i:=QDREAD(); ELSE BKSP; END;  
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      R:=COMP2(r,i,SIL);
      RETURN(R);
(*4*) END ODREAD;


PROCEDURE ODWRITE(R,NL: LIST); 
(*Octonion number decimal write.  R is a octonion number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)
VAR   r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST2(R,r,i); 
      QDWRITE(r,NL); 
      IF i <> 0 THEN SWRITE(" p "); QDWRITE(i,NL) END;  
(*4*) END ODWRITE;


PROCEDURE OEXP(A,NL: LIST): LIST; 
(*Octonion number exponentiation.  A is a octonion number,
n is a non-negative beta-integer.  B=A**n. *)
VAR   B, KL: LIST; 
BEGIN
(*1*) (*n less than or equal to 1.*) 
      IF NL = 0 THEN B:=OINT(1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=OEXP(A,KL); B:=OPROD(B,B); 
      IF NL > 2*KL THEN B:=OPROD(B,A); END; 
      RETURN(B); 
(*5*) END OEXP; 


PROCEDURE OIM(R: LIST): LIST;
(*Octonion number imaginary part p.  R is a octonion number.  b is the
imaginary part p of R, a quaternion number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(SECOND(R));
(*4*) END OIM;


PROCEDURE OINT(A: LIST): LIST;
(*Octonion number from integer.  A is an integer.  R is the octonion
number with real part equal to A/1 and imaginary part p equal to 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN R:=A; RETURN(R) END;
(*2*) R:=COMP2(QINT(A),0,SIL); 
      RETURN(R);
(*4*) END OINT;


PROCEDURE ORE(R: LIST): LIST;
(*Octonion number real part p.  R is a octonion number.  b is the
real part p of R, a quaternion number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(FIRST(R));
(*4*) END ORE;


PROCEDURE ORN(A: LIST): LIST;
(*Octonion number from rational number.  A is a rational number.  
R is the octonion number with real part equal to A and 
imaginary part p equal to 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN RETURN(0) END;
(*2*) R:=COMP2(QRN(A),0,SIL); 
      RETURN(R);
(*4*) END ORN;


PROCEDURE ORNP(A, B: LIST): LIST;
(*Octonion number from pair of quaternion numbers.  A and B are 
quaternion numbers.  R is the octonion number with real part equal 
to A and imaginary part p equal to B. *)
VAR   R: LIST;
BEGIN
(*1*) IF (A = 0) AND (B = 0) THEN RETURN(0) END;
(*2*) R:=COMP2(A,B,SIL); 
      RETURN(R);
(*4*) END ORNP;


PROCEDURE ONINV(R: LIST): LIST;
(*Octonion number inverse.  R is a non-zero octonion number.  S R=1. *)
VAR   S, t, r, i, r1, i1, a: LIST;
BEGIN
(*1*) IF R = 0 THEN ERROR(severe,"OINV: division by zero."); END;
(*2*) a:=OABS(R); S:=OCON(R); 
      FIRST2(S,r,i); r1:=0; i1:=0; 
      IF r <> 0 THEN r1:=SIL; 
         WHILE r <> SIL DO ADV(r,t,r); 
               t:=RNQ(t,a); r1:=COMP(t,r1); END; 
         r1:=INV(r1); END; 
      IF i <> 0 THEN i1:=SIL; 
         WHILE i <> SIL DO ADV(i,t,i); 
               t:=RNQ(t,a); i1:=COMP(t,i1); END; 
         i1:=INV(i1); END; 
      S:=COMP2(r1,i1,SIL); 
      RETURN(S);
(*4*) END ONINV;


PROCEDURE ONEG(R: LIST): LIST;
(*Octonion number negative.  R is a octonion number.  S=-R. *)
VAR   S, r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      S:=COMP2(QNEG(r),QNEG(i),SIL);
      RETURN(S);
(*4*) END ONEG;


PROCEDURE OONE(R: LIST): LIST; 
(*Octonion number one.  R is a octonion number.  s=1 if R=1,
s=0 else. *)
VAR   r, i, t: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST2(R,r,i); 
      IF i <> 0 THEN RETURN(0) END;
      t:=QONE(r); 
      RETURN(t);
(*4*) END OONE;


PROCEDURE OPROD(R,S: LIST): LIST;
(*Octonion number product.  R and S are octonion numbers.  T=R*S. *)
VAR   T, r1, i1, r2, i2, r, i: LIST;
BEGIN
(*1*) IF (R = 0) OR (S = 0) THEN RETURN(0) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r:=QDIF(QPROD(r1,r2),QPROD(QCON(i2),i1)); 
      i:=QSUM(QPROD(i1,QCON(r2)),QPROD(i2,r1)); 
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      T:=COMP2(r,i,SIL);
      RETURN(T);
(*4*) END OPROD;


PROCEDURE OQ(R,S: LIST): LIST;
(*Octonion number quotient.  R and S are octonion numbers, S non-zero.
T=R/S. *)
VAR   T: LIST;
BEGIN
(*1*) T:=OPROD(R,ONINV(S)); 
      RETURN(T);
(*4*) END OQ;


PROCEDURE ORAND(NL: LIST): LIST;
(*Octonion number, random.  n is a positive beta-integer.  Random 
quaternion numbers A and B are generated using QRAND(n). Then 
R is the octonion number with real part equal to A and 
imaginary part p equal to B. *)
VAR   T, r, i: LIST;
BEGIN
(*1*) r:=QRAND(NL); i:=QRAND(NL); 
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      T:=COMP2(r,i,SIL);
      RETURN(T);
(*4*) END ORAND;


PROCEDURE ONREAD(): LIST;
(*Octonion number read.  The octonion number R is read from the input
stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, c: LIST;
BEGIN
(*1*) r:=QNREAD(); i:=0; 
      c:=CREADB(); 
      IF c = MASORD("p") THEN i:=QNREAD(); ELSE BKSP; END;  
      IF (r = 0) AND (i = 0) THEN RETURN(0) END;
      R:=COMP2(r,i,SIL);
      RETURN(R);
(*4*) END ONREAD;


PROCEDURE OSUM(R,S: LIST): LIST;
(*Octonion number sum.  R and S are octonion numbers.  T=R+S. *)
VAR   T, r1, i1, r2, i2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=S; RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST2(R,r1,i1); FIRST2(S,r2,i2); 
      r1:=QSUM(r1,r2); i1:=QSUM(i1,i2); 
      IF (r1 = 0) AND (i1 = 0) THEN T:=0; RETURN(T) END;
      T:=COMP2(r1,i1,SIL);
      RETURN(T);
(*4*) END OSUM;


PROCEDURE ONWRITE(R: LIST);
(*Octonion number write. R is a octonion number.  R is converted 
to decimal and written in the output stream. *)
VAR   r, i: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST2(R,r,i); 
      QNWRITE(r);
      IF i <> 0 THEN SWRITE(" p "); QNWRITE(i) END;  
(*4*) END ONWRITE;



END MASO.




(* -EOF- *)
