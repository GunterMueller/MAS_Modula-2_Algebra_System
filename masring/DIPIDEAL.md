(* ----------------------------------------------------------------------------
 * $Id: DIPIDEAL.md,v 1.3 1993/05/11 10:53:31 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIDEAL.md,v $
 * Revision 1.3  1993/05/11  10:53:31  kredel
 * Spelling errors corr.
 *
 * Revision 1.2  1992/02/12  17:34:19  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:35  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPIDEAL;

(* DIP Ideal System Definition Module. *)


FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPIDEAL.md,v 1.3 1993/05/11 10:53:31 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPLDV(A,V: LIST): LIST; 
(*Distributive polynomial list dependency on variables.
A is a list of distributive polynomials. V is the variable list.
U is the variable list of variables with positive exponents in A. *)


PROCEDURE DIRLCT(A,B: LIST): LIST; 
(*Distributive rational polynomial list ideal containment test.
A and B are lists of distributive rational polynomials representing 
groebner bases. t = 1 if ideal(A) is contained in ideal(B),
t = 0 else. *)


PROCEDURE DIRLIP(PL,A,B: LIST): LIST; 
(*Distributive rational polynomial list ideal product.
A and B are lists of distributive rational polynomials. 
C=GBASIS(p,A*B).*)


PROCEDURE DIRLPI(A,P,VP: LIST): LIST; 
(*Distributive rational polynomial list primary ideal.
A and P are non empty lists of distributive rational polynomials 
representing groebner bases. The polynomials in A have r variables.
ideal(P) is a prime ideal in at most r+1 variables. VP is the 
variable list for P. QP=(P,e,VP,Q) where Q = ideal(P**e,A) 
with A contained in Q and e maximal. *)


END DIPIDEAL.



(* -EOF- *)
