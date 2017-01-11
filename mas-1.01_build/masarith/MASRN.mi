(* ----------------------------------------------------------------------------
 * $Id: MASRN.mi,v 1.3 1992/10/15 16:28:15 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASRN.mi,v $
 * Revision 1.3  1992/10/15  16:28:15  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:05  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:32  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASRN;

(* MAS Rational Number Implemantation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASEXP;

FROM MASSTOR IMPORT LIST, SIL, FIRST, RED, ADV, INV,
                    COMP, BETA, LENGTH;

FROM MASBIOS IMPORT CWRITE, DIGIT, BKSP, BLINES, 
                    SOLINE,
                    MASORD, CREAD, CREADB, SWRITE;

FROM SACLIST IMPORT EQUAL, CINV, ADV2, FIRST2, CLOUT;

FROM SACD IMPORT ETA, THETA;

FROM SACI IMPORT ICOMP, IQR, IPROD, INEG, ISIGNF, IEXP, 
                 ISUM, IDPR, IWRITE, IREAD;

FROM SACRN IMPORT RNSIGN, RNPROD, RNCOMP, RNSUM, RNINT, RNRED, 
                  RNDIF, RNWRIT;

CONST rcsidi = "$Id: MASRN.mi,v 1.3 1992/10/15 16:28:15 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE RNDRD(): LIST; 
(*Rational number decimal read.  The rational number R is read
from the input stream.  Any preceding blanks are skipped.*)
VAR   A, B, BL, BLP, C, IL, J1Y, JL, R, R1, R2, RP, s: LIST; 
BEGIN
(*1*) (*rational  number read. *) C:=CREADB(); BKSP; 
      IF C = MASORD("-") THEN s:=-1 ELSE s:=1 END; 
      R1:=IREAD(); C:=CREADB(); 
      IF C <> MASORD(".") THEN
         IF C = MASORD("/") THEN R2:=IREAD(); ELSE R2:=1; BKSP; END; 
         R:=RNRED(R1,R2); RETURN(R); END; 
(*2*) (*read decimal fraction. *) JL:=-1; 
      REPEAT C:=CREADB(); JL:=JL+1; 
             UNTIL C <> 0; 
(*3*) (*fraction=0.*) 
      IF NOT DIGIT(C) THEN BKSP; R:=RNINT(R1); RETURN(R); END; 
      A:=0; 
(*4*) (*compute theta-digits.*) B:=BETA; BL:=0; IL:=0; 
      REPEAT J1Y:=10*BL; BL:=J1Y+C; IL:=IL+1; 
             IF IL = ETA THEN B:=COMP(BL,B); BL:=0; IL:=0; END; 
             JL:=JL+1; C:=CREAD(); 
             UNTIL NOT DIGIT(C);
      BKSP;  
(*5*) (*convert to base beta.*) B:=INV(B); 
      WHILE B <> SIL DO A:=IDPR(A,THETA); ADV(B, BLP,B); 
            A:=ISUM(A,BLP); END; 
      IF A <> 0 THEN J1Y:=MASEXP(10,IL); A:=IDPR(A,J1Y); END; 
      A:=ISUM(A,BL); R2:=IEXP(10,JL); R:=RNRED(A,R2); 
      RP:=RNINT(R1);
      IF s < 0 THEN R:=RNDIF(RP,R) ELSE R:=RNSUM(RP,R) END;  
      RETURN(R); 
(*8*) END RNDRD; 


PROCEDURE RNDWR(R,NL: LIST); 
(*Rational number decimal write.  R is a rational number.  n is a
non-negative integer.  R is approximated by a decimal fraction D with
n decimal digits following the decimal point and D is written in the
output stream.  The inaccuracy of the approximation is at most
(1/2)*10**-n. *)
VAR  A, B, D, DL, F, IL, M, SL, TL: LIST; 
BEGIN
(*1*) (*compute approximation.*) 
      IF R = 0 THEN A:=0; B:=1; ELSE FIRST2(R, A,B); END; 
      SL:=ISIGNF(A); 
      IF SL < 0 THEN A:=INEG(A); END; 
      M:=IEXP(10,NL); A:=IPROD(A,M); IQR(A,B, D,F); F:=IDPR(F,2); 
      IF F = 0 THEN TL:=0; ELSE TL:=ICOMP(B,F); 
         IF TL = 0 THEN TL:=1; ELSE
            IF TL < 0 THEN D:=ISUM(D,1); END; 
            END; 
         END; 
(*2*) (*convert and write.*) 
      IF SL < 0 THEN SWRITE("-"); END; 
      IQR(D,M, D,F); IWRITE(D); SWRITE("."); 
      FOR IL:=1 TO NL DO F:=IDPR(F,10); IQR(F,M, DL,F); CWRITE(DL); END; 
      RETURN; 
(*5*) END RNDWR; 


PROCEDURE RNDWRS(A,S: LIST); 
(*Rational number decimal write special.
Call RNDWR. *)
BEGIN
(*1*) RNDWR(A,S); RETURN; 
(*4*) END RNDWRS; 


PROCEDURE RNEXP(A,NL: LIST): LIST; 
(*Rational number exponentiation.  A is a rational number,
n is a non-negative beta-integer.  B=A**n.*)
VAR  B, KL: LIST; 
BEGIN
(*1*) (*nl less than or equal to 1.*) 
      IF NL = 0 THEN B:=RNINT(1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=RNEXP(A,KL); B:=RNPROD(B,B); 
      IF NL > 2*KL THEN B:=RNPROD(B,A); END; 
      RETURN(B); 
(*5*) END RNEXP; 


PROCEDURE RNMAX(AL,BL: LIST): LIST; 
(*Rational number maximum.  a and b are rational numbers.
c is the maximum of a and b.*)
VAR  CL, SL: LIST; 
BEGIN
(*1*) SL:=RNCOMP(AL,BL); 
      IF SL >= 0 THEN CL:=AL; ELSE CL:=BL; END; 
      RETURN(CL); 
(*4*) END RNMAX; 


PROCEDURE RNONE(R: LIST): LIST; 
(*Rational number one.  R is a rational number.  s=1 if R=1,
s=0 else. *)
VAR  R1, R2, SL: LIST; 
BEGIN
(*1*) (*denominator=numerator. *) SL:=0; 
      IF R = 0 THEN RETURN(SL); END; 
      FIRST2(R, R1,R2); SL:=EQUAL(R1,R2); 
(*4*) RETURN(SL); END RNONE; 


END MASRN.


(* -EOF- *)
