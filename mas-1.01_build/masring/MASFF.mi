(* ----------------------------------------------------------------------------
 * $Id: MASFF.mi,v 1.2 1992/10/15 16:29:41 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASFF.mi,v $
 * Revision 1.2  1992/10/15  16:29:41  kredel
 * Changed rcsid variable
 *
 * Revision 1.1  1992/09/28  17:38:31  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASFF;

(* MAS Finite Field Implementation Module. *)


(* import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    EQUAL, RED2, SECOND, LIST2;

FROM SACM IMPORT MIHOM, MIINV;
FROM SACRN IMPORT RNRED;
FROM SACPOL IMPORT PLDCF, PDEG, PBIN, PINV;

FROM SACIPOL IMPORT IPONE;

FROM SACMPOL IMPORT MIPDIF, MIPSUM, MIPHOM, MIUPQR, MIPPR, MIPNEG, MIPRAN; 

FROM DIPC IMPORT PFDIP, DIPFP; 

FROM DIPI IMPORT DIIPWR, DIIPRD; 

(* 
FROM SACPGCD IMPORT IPPGSD, IPSRP;
*)

CONST rcsidi = "$Id: MASFF.mi,v 1.2 1992/10/15 16:29:41 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE FFCOMP(R,S: LIST): LIST;
(*Finite field comparison.  R and S are finite field elements.
t=0 if R=S, t=1 else. *)
VAR   t: LIST;
BEGIN
(*1*) t:=EQUAL(R,S); 
      IF t = 1 THEN t:=0 ELSE t:=1 END;  
      RETURN(t);
(*4*) END FFCOMP;


PROCEDURE FFDIF(p,M,AL,BL: LIST): LIST; 
(*Finite field difference.  AL and BL are elements of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial for alpha. CL=AL-BL.*)
VAR   CL: LIST; 
BEGIN
(*1*) CL:=MIPDIF(1,p,AL,BL); 
      RETURN(CL); 
(*4*) END FFDIF; 


PROCEDURE FFEXP(p,M,A,NL: LIST): LIST; 
(*Finite field exponentiation.  A is an element of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial for alpha.  nl is a non-negative beta-integer.  
B=A**nl.*)
VAR   B, KL: LIST; 
BEGIN
(*1*) (*nl less than or equal to 1.*) 
      IF NL = 0 THEN B:=FFFINT(p,M,1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=FFEXP(p,M,A,KL); 
      B:=FFPROD(p,M,B,B); 
      IF NL > 2*KL THEN B:=FFPROD(p,M,B,A); END; 
(*5*) RETURN(B); END FFEXP; 
 

PROCEDURE FFFINT(p,M,A: LIST): LIST; 
(*Finite field element from integer.  A is an integer. B is A 
converted to an element of F(p)(alpha), for some prime integer p and 
some algebraic number alpha. M is the minimal polynomial for alpha. *)
VAR   B, C, BL: LIST; 
BEGIN
(*1*) (*convert. *) BL:=MIHOM(p,A); B:=PINV(0,BL,1);  
(*5*) RETURN(B); END FFFINT; 


PROCEDURE FFHOM(p,M,A: LIST): LIST; 
(*Finite field homomorpism.  A is an univariate integral polynomial, 
B is A converted to an element of F(p)(alpha), for some prime integer p 
and some algebraic number alpha. M is the minimal polynomial for 
alpha. *)
VAR   B, C, D: LIST; 
BEGIN
(*1*) (*get remainder.*) B:=MIPHOM(1,p,A); 
      MIUPQR(p,B,M, C, D); 
(*5*) RETURN(D); END FFHOM; 


PROCEDURE FFINV(p,M,AL: LIST): LIST; 
(*Finite field inverse.  AL is a nonzero element of F(p)(alpha) 
for some prime integer p and some algebraic number alpha.  M is the
minimal polynomial for alpha.  BL=1/AL.*)
VAR   AL1, AL2, AL3, BL, CL, DL, EL, QL, RL, VL1, VL2, VL3: LIST; 
BEGIN
(*1*) AL1:=M; AL2:=AL; VL1:=0; RL:=1; VL2:=LIST2(0,RL); 
      LOOP DL:=PLDCF(AL2); CL:=MIINV(p,DL); CL:=LIST2(0,CL);
           VL2:=MIPPR(1,p,CL,VL2); 
           IF PDEG(AL2) = 0 THEN BL:=VL2; RETURN(BL); END; 
           AL2:=MIPPR(1,p,CL,AL2); MIUPQR(p,AL1,AL2, QL,AL3); 
           EL:=MIPPR(1,p,QL,VL2); VL3:=MIPDIF(1,p,VL1,EL); AL1:=AL2; 
           AL2:=AL3; VL1:=VL2; VL2:=VL3; 
           END; 
(*4*) RETURN(BL); END FFINV; 


PROCEDURE FFNEG(p,M,AL: LIST): LIST; 
(*Finite field negation.  AL is an element of F(p)(alpha) for some 
prime integer p and some algebraic number alpha. M is the minimal 
polynomial for alpha. BL= -AL.*)
VAR   BL: LIST; 
BEGIN
(*1*) BL:=MIPNEG(1,p,AL); 
      RETURN(BL); 
(*4*) END FFNEG; 


PROCEDURE FFONE(R: LIST): LIST; 
(*Finite field one.  R is a finite field element.  s=1 if R=1,
s=0 else. *)
VAR   t: LIST;
BEGIN
(*1*) t:=IPONE(1,R); RETURN(t);
(*4*) END FFONE;


PROCEDURE FFPROD(p,M,AL,BL: LIST): LIST; 
(*Finite field product.  AL and BL are elements of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial of alpha.  CL=AL+BL.*)
VAR   CL, CLP, QL: LIST; 
BEGIN
(*1*) CLP:=MIPPR(1,p,AL,BL); MIUPQR(p,CLP,M, QL,CL); 
(*4*) RETURN(CL); END FFPROD; 


PROCEDURE FFQ(p,M,AL,BL: LIST): LIST; 
(*Finite field quotient.  AL and BL, BL nonzero, are elements of 
F(p)(alpha) for some prime integer p and some algebraic number 
alpha. M is the minimal polynomial for alpha.  CL=AL/BL.*)
VAR   CL, DL: LIST; 
BEGIN
(*1*) IF AL = 0 THEN CL:=0; ELSE DL:=FFINV(p,M,BL); 
         CL:=FFPROD(p,M,AL,DL); END; 
      RETURN(CL); 
(*4*) END FFQ; 


PROCEDURE FFRAND(p,M,NL: LIST): LIST;
(*Finite field element, random.  n is a positive beta-integer le deg(M). 
A random finite field element R of F(p)(alpha) for some prime integer p 
and some algebraic number alpha.  M is the minimal polynomial for 
alpha. R is generated using MIPRAN(1,p,n/deg(M),(deg(M))). *) 
VAR   R, d, D, n, q: LIST;  
BEGIN
(*1*) d:=PDEG(M)-1; D:=LIST1(d); IF d <= 0 THEN d:=1 END; 
      n:=NL; IF n <= 0 THEN n:=1 END; IF n > d THEN n:=d END; 
      q:=RNRED(n,d); 
      R:=MIPRAN(1,p,q,D); RETURN(R); 
(*9*) END FFRAND; 


PROCEDURE FFREAD(V: LIST): LIST;
(*Finite field read.  The finite field element R is read from the input
stream.  V is the varaible list. Any preceding blanks are skipped. *)
VAR   CL, RL: LIST;
BEGIN
(*1*) CL:=DIIPRD(V); PFDIP(CL, RL,CL); 
      RETURN(CL); 
(*9*) END FFREAD; 


PROCEDURE FFSUM(p,M,AL,BL: LIST): LIST; 
(*Finite field sum.  AL and BL are elements of F(p)(alpha) for some 
prime integer p and some algebraic number alpha.  M is the minimal 
polynomial for alpha.  CL=AL+BL.*)
VAR   CL: LIST; 
BEGIN
(*1*) CL:=MIPSUM(1,p,AL,BL); RETURN(CL); 
(*4*) END FFSUM; 


PROCEDURE FFWRITE(R, V: LIST);
(*Finite field write. R is a finite field element. V is the varaible 
list. R is written to the output stream. *)
VAR   CL: LIST;
BEGIN
(*1*) CL:=DIPFP(1,R); DIIPWR(CL,V); 
(*9*) END FFWRITE; 


END MASFF.
(* -EOF- *)
