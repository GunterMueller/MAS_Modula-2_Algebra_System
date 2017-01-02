(* ----------------------------------------------------------------------------
 * $Id: MASQ.mi,v 1.3 1992/10/15 16:28:14 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASQ.mi,v $
 * Revision 1.3  1992/10/15  16:28:14  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/09/28  18:34:55  kredel
 * Updated revision string.
 *
 * Revision 1.1  1992/09/28  17:29:13  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASQ;

(* MAS Quaternion Number Implementation Module. *)


(* Import lists and declarations. *)

FROM MASBIOS IMPORT SWRITE, CWRITE, CREADB, MASORD, BKSP, BLINES;

FROM MASSTOR IMPORT LIST, ADV, COMP, FIRST, SIL; 

FROM MASERR IMPORT severe, ERROR;

FROM SACLIST IMPORT OWRITE, SECOND, THIRD, FOURTH, FIRST4, LIST4, COMP4,  
                    AWRITE, EQUAL;

FROM SACRN IMPORT RNSUM, RNPROD, RNCOMP, RNNEG, RNDIF, 
                  RNQ, RNINT, RNREAD, RNWRIT, RNRAND;

FROM MASRN IMPORT RNDWR, RNDRD, RNONE;

CONST rcsidi = "$Id: MASQ.mi,v 1.3 1992/10/15 16:28:14 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* Representation of a + i b + j c + k d, with a, b, c, d rational numbers, 
   is 

                         0   if a=0 and b=0 and c=0 and d=0 
                 (a,b,c,d)   else   *)


PROCEDURE QABS(R: LIST): LIST;
(*Quaternion number absolute value.  R is a quaternion number.  S is the
absolute value of R, a rational number. *)
VAR   S, r, i, j, k: LIST;
BEGIN
(*1*) IF R = 0 THEN S:=R; RETURN(S) END;
(*2*) FIRST4(R,r,i,j,k); 
      S:=RNSUM(RNPROD(r,r),RNPROD(i,i));
      S:=RNSUM(S,RNPROD(j,j)); S:=RNSUM(S,RNPROD(k,k));
      RETURN(S);
(*4*) END QABS;


PROCEDURE QCON(R: LIST): LIST;
(*Quaternion number conjugate.  R is a quaternion number. S is the
quaternion conjugate of R. *)
VAR   S, r, i, j, k: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST4(R,r,i,j,k); 
      S:=COMP4(r,RNNEG(i),RNNEG(j),RNNEG(k),SIL);
      RETURN(S);
(*4*) END QCON;


PROCEDURE QCOMP(R,S: LIST): LIST;
(*Quaternion number comparison.  R and S are quaternion numbers.
t=0 if R=S, t=1 else. *)
VAR   t: LIST;
BEGIN
(*1*) t:=EQUAL(R,S); 
      IF t = 1 THEN t:=0 ELSE t:=1 END;  
      RETURN(t);
(*4*) END QCOMP;


PROCEDURE QDIF(R,S: LIST): LIST;
(*Quaternion number difference.  R and S are quaternion numbers.  T=R-S. *)
VAR   T, r1, i1, j1, k1, r2, i2, j2, k2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=QNEG(S); RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST4(R,r1,i1,j1,k1); FIRST4(S,r2,i2,j2,k2); 
      r1:=RNDIF(r1,r2); i1:=RNDIF(i1,i2); 
      j1:=RNDIF(j1,j2); k1:=RNDIF(k1,k2); 
      IF (r1 = 0) AND (i1 = 0) AND (j1 = 0) AND (k1 = 0) THEN RETURN(0) END;
      T:=COMP4(r1,i1,j1,k1,SIL);
      RETURN(T);
(*4*) END QDIF;


PROCEDURE QDREAD(): LIST; 
(*Quaternion number decimal read.  The quaternion number R is read
from the input stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, j, k, c: LIST;
BEGIN
(*1*) r:=RNDRD(); i:=0; 
      c:=CREADB(); 
      IF c = MASORD("i") THEN i:=RNDRD(); ELSE BKSP END;  
      c:=CREADB(); 
      IF c = MASORD("j") THEN j:=RNDRD(); ELSE BKSP END;  
      c:=CREADB(); 
      IF c = MASORD("k") THEN k:=RNDRD(); ELSE BKSP END;  
      IF (r = 0) AND (i = 0) AND (j = 0) AND (k = 0) THEN RETURN(0) END;
      R:=COMP4(r,i,j,k,SIL);
      RETURN(R);
(*4*) END QDREAD;


PROCEDURE QDWRITE(R,NL: LIST); 
(*Quaternion number decimal write.  R is a quaternion number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)
VAR   r, i, j, k: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST4(R,r,i,j,k); 
      RNDWR(r,NL); 
      IF i <> 0 THEN SWRITE(" i "); RNDWR(i,NL) END;  
      IF j <> 0 THEN SWRITE(" j "); RNDWR(j,NL) END;  
      IF k <> 0 THEN SWRITE(" k "); RNDWR(k,NL) END;  
(*4*) END QDWRITE;


PROCEDURE QEXP(A,NL: LIST): LIST; 
(*Quaternion number exponentiation.  A is a quaternion number,
n is a non-negative beta-integer.  B=A**n. *)
VAR   B, KL: LIST; 
BEGIN
(*1*) (*n less than or equal to 1.*) 
      IF NL = 0 THEN B:=QINT(1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=QEXP(A,KL); B:=QPROD(B,B); 
      IF NL > 2*KL THEN B:=QPROD(B,A); END; 
      RETURN(B); 
(*5*) END QEXP; 


PROCEDURE QIMi(R: LIST): LIST;
(*Quaternion number imaginary part i.  R is a quaternion number.  b is the
imaginary part i of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(SECOND(R));
(*4*) END QIMi;


PROCEDURE QIMj(R: LIST): LIST;
(*Quaternion number imaginary part j.  R is a quaternion number.  b is the
imaginary part j of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(THIRD(R));
(*4*) END QIMj;


PROCEDURE QIMk(R: LIST): LIST;
(*Quaternion number imaginary part k.  R is a quaternion number.  b is the
imaginary part k of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(FOURTH(R));
(*4*) END QIMk;


PROCEDURE QINT(A: LIST): LIST;
(*Quaternion number from integer.  A is an integer.  R is the quaternion
number with real part A/1 and imaginary part 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN R:=A; RETURN(R) END;
(*2*) R:=COMP4(RNINT(A),0,0,0,SIL); 
      RETURN(R);
(*4*) END QINT;


PROCEDURE QRE(R: LIST): LIST;
(*Quaternion number real part.  R is a quaternion number.  b is the
real part of R, a rational number. *)
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) RETURN(FIRST(R));
(*4*) END QRE;


PROCEDURE QRN(A: LIST): LIST;
(*Quaternion number from rational number.  A is a rational number.  
R is the quaternion number with real part A and imaginary part 0. *)
VAR   R: LIST;
BEGIN
(*1*) IF A = 0 THEN RETURN(0) END;
(*2*) R:=COMP4(A,0,0,0,SIL); 
      RETURN(R);
(*4*) END QRN;


PROCEDURE QRN4(A, B, C, D: LIST): LIST;
(*Quaternion number from 4-tuple of rational numbers.  A, B, C and D 
are rational numbers.  R is the quaternion number with real part A 
and imaginary part i B, imaginary part j C, imaginary part k D. *)
VAR   R: LIST;
BEGIN
(*1*) IF (A = 0) AND (B = 0) THEN RETURN(0) END;
(*2*) R:=COMP4(A,B,C,D,SIL); 
      RETURN(R);
(*4*) END QRN4;


PROCEDURE QINV(R: LIST): LIST;
(*Quaternion number inverse.  R is a non-zero quaternion number.  S R=1. *)
VAR   S, r, i, j, k, a: LIST;
BEGIN
(*1*) IF R = 0 THEN ERROR(severe,"QINV: division by zero."); END;
(*2*) FIRST4(R,r,i,j,k); 
      a:=RNSUM(RNPROD(r,r),RNPROD(i,i));
      a:=RNSUM(a,RNPROD(j,j));
      a:=RNSUM(a,RNPROD(k,k));
      r:=RNQ(r,a); i:=RNQ(RNNEG(i),a); 
      j:=RNQ(RNNEG(j),a); k:=RNQ(RNNEG(k),a); 
      S:=COMP4(r,i,j,k,SIL);
      RETURN(S);
(*4*) END QINV;


PROCEDURE QNEG(R: LIST): LIST;
(*Quaternion number negative.  R is a quaternion number.  S=-R. *)
VAR   S, r, i, j, k: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST4(R,r,i,j,k); 
      S:=COMP4(RNNEG(r),RNNEG(i),RNNEG(j),RNNEG(k),SIL);
      RETURN(S);
(*4*) END QNEG;


PROCEDURE QONE(R: LIST): LIST; 
(*Quaternion number one.  R is a quaternion number.  s=1 if R=1,
s=0 else. *)
VAR   r, i, j, k, t: LIST;
BEGIN
(*1*) IF R = 0 THEN RETURN(0) END;
(*2*) FIRST4(R,r,i,j,k); 
      IF (i <> 0) OR (j <> 0) OR (k <> 0) THEN RETURN(0) END;
      t:=RNONE(r); 
      RETURN(t);
(*4*) END QONE;


PROCEDURE QPROD(R,S: LIST): LIST;
(*Quaternion number product.  R and S are quaternion numbers.  T=R*S. *)
VAR   T, r1, i1, j1, k1, r2, i2, j2, k2, r, i, j, k: LIST;
BEGIN
(*1*) IF (R = 0) OR (S = 0) THEN RETURN(0) END;
(*2*) FIRST4(R,r1,i1,j1,k1); FIRST4(S,r2,i2,j2,k2); 
      r:=RNDIF(RNPROD(r1,r2),RNPROD(i1,i2)); 
      r:=RNDIF(r,RNPROD(j1,j2)); r:=RNDIF(r,RNPROD(k1,k2)); 
      i:=RNSUM(RNPROD(r1,i2),RNPROD(i1,r2)); 
      i:=RNSUM(i,RNPROD(j1,k2)); i:=RNDIF(i,RNPROD(k1,j2)); 
      j:=RNDIF(RNPROD(r1,j2),RNPROD(i1,k2)); 
      j:=RNSUM(j,RNPROD(j1,r2)); j:=RNSUM(j,RNPROD(k1,i2)); 
      k:=RNSUM(RNPROD(r1,k2),RNPROD(i1,j2)); 
      k:=RNDIF(k,RNPROD(j1,i2)); k:=RNSUM(k,RNPROD(k1,r2)); 
      IF (r = 0) AND (i = 0) AND (j = 0) AND (k = 0) THEN RETURN(0) END;
      T:=COMP4(r,i,j,k,SIL);
      RETURN(T);
(*4*) END QPROD;


PROCEDURE QQ(R,S: LIST): LIST;
(*Quaternion number quotient.  R and S are quaternion numbers, S non-zero.
T=R/S. *)
VAR   T: LIST;
BEGIN
(*1*) T:=QPROD(R,QINV(S)); 
      RETURN(T);
(*4*) END QQ;


PROCEDURE QRAND(NL: LIST): LIST;
(*Quaternion number, random.  n is a positive beta-integer.  Random 
rational numbers A and B are generated using RNRAND(n). Then 
R is the quaternion number with real part A and imaginary part B. *)
VAR   T, r, i, j, k: LIST;
BEGIN
(*1*) r:=RNRAND(NL); i:=RNRAND(NL); j:=RNRAND(NL); k:=RNRAND(NL); 
      IF (r = 0) AND (i = 0) AND (j = 0) AND (k = 0) THEN RETURN(0) END;
      T:=COMP4(r,i,j,k,SIL);
      RETURN(T);
(*4*) END QRAND;


PROCEDURE QNREAD(): LIST;
(*Quaternion number read.  The quaternion number R is read from the input
stream.  Any preceding blanks are skipped. *)
VAR   R, r, i, j, k, c: LIST;
BEGIN
(*1*) r:=RNREAD(); i:=0; j:=0; k:=0; 
      c:=CREADB(); 
      IF c = MASORD("i") THEN i:=RNREAD(); ELSE BKSP END;  
      c:=CREADB(); 
      IF c = MASORD("j") THEN j:=RNREAD(); ELSE BKSP END;  
      c:=CREADB(); 
      IF c = MASORD("k") THEN k:=RNREAD(); ELSE BKSP END;  
      IF (r = 0) AND (i = 0) AND (j = 0) AND (k = 0) THEN RETURN(0) END;
      R:=COMP4(r,i,j,k,SIL);
      RETURN(R);
(*4*) END QNREAD;


PROCEDURE QSUM(R,S: LIST): LIST;
(*Quaternion number sum.  R and S are quaternion numbers.  T=R+S. *)
VAR   T, r1, i1, j1, k1, r2, i2, j2, k2: LIST;
BEGIN
(*1*) IF R = 0 THEN T:=S; RETURN(T) END;
      IF S = 0 THEN T:=R; RETURN(T) END;
(*2*) FIRST4(R,r1,i1,j1,k1); FIRST4(S,r2,i2,j2,k2); 
      r1:=RNSUM(r1,r2); i1:=RNSUM(i1,i2); 
      j1:=RNSUM(j1,j2); k1:=RNSUM(k1,k2); 
      IF (r1 = 0) AND (i1 = 0) AND (j1 = 0) AND (k1 = 0) THEN RETURN(0) END;
      T:=COMP4(r1,i1,j1,k1,SIL);
      RETURN(T);
(*4*) END QSUM;


PROCEDURE QNWRITE(R: LIST);
(*Quaternion number write. R is a quaternion number.  R is converted 
to decimal and written in the output stream. *)
VAR   r, i, j, k: LIST;
BEGIN
(*1*) IF R = 0 THEN AWRITE(R); RETURN END;
(*2*) FIRST4(R,r,i,j,k); 
      RNWRIT(r); 
      IF i <> 0 THEN SWRITE(" i "); RNWRIT(i) END;  
      IF j <> 0 THEN SWRITE(" j "); RNWRIT(j) END;  
      IF k <> 0 THEN SWRITE(" k "); RNWRIT(k) END;  
(*4*) END QNWRITE;



END MASQ.




(* -EOF- *)
