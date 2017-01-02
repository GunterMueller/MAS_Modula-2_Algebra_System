(* ----------------------------------------------------------------------------
 * $Id: SACANF.md,v 1.2 1992/02/12 17:34:44 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACANF.md,v $
 * Revision 1.2  1992/02/12  17:34:44  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:22  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACANF;

(* SAC Algebraic Number Field Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACANF.md,v 1.2 1992/02/12 17:34:44 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE AFDIF(AL,BL: LIST): LIST; 
(*Algebraic number field element difference.  AL and BL are elements
of Q(alpha) for some algebraic number alpha.  CL=AL-BL.*)


PROCEDURE AFINV(M,AL: LIST): LIST; 
(*Algebraic number field inverse.  AL is a nonzero
element of Q(alpha) for some algebraic number alpha.  M is the
rational minimal polynomial for alpha.  BL=1/AL.*)


PROCEDURE AFNEG(AL: LIST): LIST; 
(*Algebraic number field element negation.  AL is an element of
Q(alpha) for some algebraic number alpha.  BL= -AL.*)


PROCEDURE AFPROD(M,AL,BL: LIST): LIST; 
(*Algebraic number field element product.  AL and BL are elements of
Q(alpha) for some algebraic number alpha.  M is the minimal polynomial
of alpha.  CL=AL+BL.*)


PROCEDURE AFQ(M,AL,BL: LIST): LIST; 
(*Algebraic number field quotient.  AL and BL are
elements of Q(alpha) for some algebraic number alpha with BL
nonzero.  M is the minimal polynomial for alpha.  CL=AL/BL.*)


PROCEDURE AFSIGN(M,I,AL: LIST): LIST; 
(*Algebraic number field sign.  M is the integral minimal polynomial
of a real algebraic number alpha.  I is an acceptable isolating
interval for alpha.  AL is an element of Q(alpha).  SL=SIGN(AL).*)


PROCEDURE AFSUM(AL,BL: LIST): LIST; 
(*Algebraic number field element sum.  AL and BL are elements of
Q(alpha) for some algebraic number alpha.  CL=AL+BL.*)


PROCEDURE RUPMRN(R: LIST): LIST; 
(*Rational univariate polynomial minimal polynomial of a rational number.  
R is a rational number.  M is the rational minimal polynomial of R.*)


END SACANF.
(* -EOF- *)
