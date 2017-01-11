(* ----------------------------------------------------------------------------
 * $Id: MASFF.md,v 1.1 1992/09/28 17:38:29 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASFF.md,v $
 * Revision 1.1  1992/09/28  17:38:29  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASFF;

(* MAS Finite Field Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: MASFF.md,v 1.1 1992/09/28 17:38:29 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE FFCOMP(R,S: LIST): LIST;
(*Finite field comparison.  R and S are finite field elements.
t=0 if R=S, t=1 else. *)


PROCEDURE FFDIF(p,M,AL,BL: LIST): LIST; 
(*Finite field difference.  AL and BL are elements of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial for alpha. CL=AL-BL.*)


PROCEDURE FFEXP(p,M,A,NL: LIST): LIST; 
(*Finite field exponentiation.  A is an element of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial for alpha.  nl is a non-negative beta-integer.  
B=A**nl.*)
 

PROCEDURE FFFINT(p,M,A: LIST): LIST; 
(*Finite field element from integer.  A is an integer. B is A 
converted to an element of F(p)(alpha), for some prime integer p and 
some algebraic number alpha. M is the minimal polynomial for alpha. *)


PROCEDURE FFHOM(p,M,A: LIST): LIST; 
(*Finite field homomorpism.  A is an univariate integral polynomial, 
B is A converted to an element of F(p)(alpha), for some prime integer p 
and some algebraic number alpha. M is the minimal polynomial for 
alpha. *)


PROCEDURE FFINV(p,M,AL: LIST): LIST; 
(*Finite field inverse.  AL is a nonzero element of F(p)(alpha) 
for some prime integer p and some algebraic number alpha.  M is the
minimal polynomial for alpha.  BL=1/AL.*)


PROCEDURE FFNEG(p,M,AL: LIST): LIST; 
(*Finite field negation.  AL is an element of F(p)(alpha) for some 
prime integer p and some algebraic number alpha. M is the minimal 
polynomial for alpha. BL= -AL.*)


PROCEDURE FFONE(R: LIST): LIST; 
(*Finite field one.  R is a finite field element.  s=1 if R=1,
s=0 else. *)


PROCEDURE FFPROD(p,M,AL,BL: LIST): LIST; 
(*Finite field product.  AL and BL are elements of F(p)(alpha) for 
some prime integer p and some algebraic number alpha.  M is the 
minimal polynomial of alpha.  CL=AL+BL.*)


PROCEDURE FFQ(p,M,AL,BL: LIST): LIST; 
(*Finite field quotient.  AL and BL, BL nonzero, are elements of 
F(p)(alpha) for some prime integer p and some algebraic number 
alpha. M is the minimal polynomial for alpha.  CL=AL/BL.*)


PROCEDURE FFRAND(p,M,NL: LIST): LIST;
(*Finite field element, random.  n is a positive beta-integer. A 
random finite field element R of F(p)(alpha) for some prime integer p 
and some algebraic number alpha.  M is the minimal polynomial for 
alpha. R is generated using IRAND(n). *) 


PROCEDURE FFREAD(V: LIST): LIST;
(*Finite field read.  The finite field element R is read from the input
stream. V is the varaible list. Any preceding blanks are skipped. *)


PROCEDURE FFSUM(p,M,AL,BL: LIST): LIST; 
(*Finite field sum.  AL and BL are elements of F(p)(alpha) for some 
prime integer p and some algebraic number alpha.  M is the minimal 
polynomial for alpha.  CL=AL+BL.*)


PROCEDURE FFWRITE(R, V: LIST);
(*Finite field write. R is a finite field element. V is the varaible 
list. R is written to the output stream. *)


END MASFF.
(* -EOF- *)
