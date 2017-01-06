(* ----------------------------------------------------------------------------
 * $Id: MASF.mi,v 1.4 1992/10/16 13:52:05 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASF.mi,v $
 * Revision 1.4  1992/10/16  13:52:05  kredel
 * Errors found by Mocka corrected
 *
 * Revision 1.3  1992/10/15  16:28:11  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:01  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:26  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASF;

(* MAS Floating Point Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT, MASQREM, MASEXP;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    ADV, FIRST, RED, 
                    LIST1;

FROM SACLIST IMPORT CINV, LIST2;

FROM SACI IMPORT IEXP, IPROD, ISUM;

FROM SACRN IMPORT RNDEN, RNNUM, RNRED, 
                  RNPROD;

FROM MathLib IMPORT entier, real, sqrt, 
                    sin, cos, arctan, exp, ln;
                    (* power, log, tan *)

(* 
FROM General IMPORT Exp2; 
*)

CONST rcsidi = "$Id: MASF.mi,v 1.4 1992/10/16 13:52:05 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE FFGI(N: GAMMAINT): MFLOAT;
(*Floating point from gamma integer.
The gamma integer N is converted to the floating point number A. *)
VAR   f: MFLOAT;
BEGIN 
(*1*) f:=real(N); RETURN(f);
(*2*) END FFGI;
 

PROCEDURE IFF(F: MFLOAT): LIST;
(*Integer from floating point.
The floating point number F is converted to the integer A. *)
VAR g, h: GAMMAINT;
    f: MFLOAT;
BEGIN
(*1*) (*normalize. *) 
      IF F >= 0.0 THEN f:=F; h:=1 ELSE f:=-F; h:=-1 END;
      WHILE f >= FBETA DO f:=f/FBETA; h:=IPROD(h,IBETA) END; 
(*2*) (*convert beta digit. *)
      g:=entier(f);
(*3*) (*combine. *)
      h:=IPROD(h,g); RETURN(h);
(*4*) END IFF;

 
PROCEDURE FEXP(F: MFLOAT; N: GAMMAINT): MFLOAT;
(*Floating point exponentiation.
The floating point number F raised to the n-th power. *)
VAR   i: INTEGER; 
      f: MFLOAT; 
BEGIN 
(*1*) IF F = 0.0 THEN RETURN(F) END; 
      f:=1.0; 
      IF N = 0 THEN RETURN(f) END; 
      IF N < 0 THEN N:=-N; f:=1.0/f END; 
      FOR i:=1 TO N DO f:=f*F END; 
      RETURN(f);
(*3*) END FEXP;

 
PROCEDURE FLOG10(F: MFLOAT): MFLOAT;
(*Floating point logarithm base 10.
The logarithm of the floating point number F with base 10 is returned. *)
BEGIN RETURN(ln(F)/ln(10.0));
(*1*) END FLOG10;


PROCEDURE FFINT(N: LIST): MFLOAT;
(*Floating point from integer.
The integer N is converted to the floating point number f. *)
VAR  A, a: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*n=0. *) f:=0.0;
      IF N = 0 THEN RETURN(f) END;
      A:=N; IF A < BETA THEN A:=LIST1(A) END;
(*2*) (*use horner scheme. *) A:=CINV(A);
      WHILE A <> SIL DO ADV(A,a,A);
            f:=f*FBETA+FFGI(a) END;
      RETURN(f);
(*3*) END FFINT;


PROCEDURE FFRN(A: LIST): MFLOAT;
(*Floating point from rational number.
The rational number A is converted to the floating point number f. *)
VAR  d, n: LIST;
     f, fd, fn: MFLOAT;
BEGIN
(*1*) (*a=0. *) f:=0.0;
      IF A = 0 THEN RETURN(f) END;
(*2*) (*convert numerator and denomiator. *) 
      d:=RNDEN(A); n:=RNNUM(A);
      fd:=FFINT(d); fn:=FFINT(n);
      f:=fn/fd; 
      RETURN(f);
(*3*) END FFRN;


PROCEDURE RNFF(F: MFLOAT): LIST;
(*Rational number from floating point.
The floating point number F is converted to the rational number R. *)
VAR  R, I, E: LIST;
     f, i, l: MFLOAT;
BEGIN
(*1*) (*compute logarithm. *) f:=F; 
      l:=FLOG10(f)+1.0; I:=IFF(l); 
      i:=FEXP(10.0,I); E:=IEXP(10,I); 
(*2*) (*shift and get numerator and denomiantor. *) 
      IF I >= 0 THEN f:=f/i; f:=f*FBETA; 
                     R:=IFF(f); 
                     R:=IPROD(R,E); R:=RNRED(R,IBETA)
                ELSE f:=f*i; f:=f*FBETA; 
                     R:=IFF(f); 
                     E:=IPROD(E,IBETA); R:=RNRED(R,E) END;
      RETURN(R);
(*3*) END RNFF;


PROCEDURE SIN(A: LIST): LIST;
(*Sinus. A is a rational number, the sinus of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute sinus. *) 
      f:=FFRN(A); f:=sin(f); R:=RNFF(f);
      RETURN(R);
(*3*) END SIN;


PROCEDURE COS(A: LIST): LIST;
(*Cosinus. A is a rational number, the cosinus of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute cosinus. *) 
      f:=FFRN(A); f:=cos(f); R:=RNFF(f);
      RETURN(R);
(*3*) END COS;


PROCEDURE TAN(A: LIST): LIST;
(*Tangens. A is a rational number, the tangens of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute tangens. *) 
      f:=FFRN(A); f:=cos(f);
      IF f <> 0.0 THEN f:=sin(f)/f; R:=RNFF(f);
         ELSE f:=sin(f); 
              IF f < 0.0 THEN R:=LIST2(-1,0); (* -1/0 *) 
                 ELSE R:=LIST2(1,0); (* 1/0 *) END;  
              END; 
      RETURN(R);
(*3*) END TAN;


PROCEDURE ARCTAN(A: LIST): LIST;
(*Arcus tangens. A is a rational number, the arctangens of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute arcus tangens. *) 
      f:=FFRN(A); f:=arctan(f); R:=RNFF(f);
      RETURN(R);
(*3*) END ARCTAN;


PROCEDURE EXPF(A: LIST): LIST;
(*Exponential. A is a rational number, the exponential of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute exp. *) 
      f:=FFRN(A); f:=exp(f); R:=RNFF(f);
      RETURN(R);
(*3*) END EXPF;


PROCEDURE LN(A: LIST): LIST;
(*Ln. A is a rational number, the natural logarithm of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute ln. *) 
      f:=FFRN(A); f:=ln(f); R:=RNFF(f);
      RETURN(R);
(*3*) END LN;


PROCEDURE LOG(A: LIST): LIST;
(*Log. A is a rational number, the logarithm base 10 of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute log. *) 
      f:=FFRN(A); f:=ln(f)/ln(10.0); R:=RNFF(f);
      RETURN(R);
(*3*) END LOG;


PROCEDURE SQRT(A: LIST): LIST;
(*Sqrt. A is a rational number, the square root of A is returned. *)  
VAR  R: LIST;
     f: MFLOAT;
BEGIN
(*1*) (*convert and compute sqrt. *) 
      f:=FFRN(A); f:=sqrt(f); R:=RNFF(f);
      RETURN(R);
(*3*) END SQRT;


PROCEDURE InitFLOAT;
(*Initialize floating point system. *)
BEGIN
(*1*) (*compute small beta. *)
      BETAH:=MASEXP(2,15); 
(*2*) (*compute floating beta. *) 
      FBETA:=FFGI(MASEXP(2,29)); 
      FBETAH:=FFGI(MASEXP(2,15)); 
(*3*) (*compute integer beta. *) 
      IBETA:=IEXP(2,29); 
(*4*) END InitFLOAT;


BEGIN 

InitFLOAT;

END MASF.

(* -EOF- *)
