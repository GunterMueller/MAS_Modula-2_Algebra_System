(* ----------------------------------------------------------------------------
 * $Id: DIPIPOL.md,v 1.2 1992/02/12 17:33:50 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIPOL.md,v $
 * Revision 1.2  1992/02/12  17:33:50  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:40  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPIPOL;


(* DIP Integer Polynomial Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPIPOL.md,v 1.2 1992/02/12 17:33:50 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE VIPIIP(RL,A,B: LIST): LIST;
(*Vector of integral polynomials with vector of integers inner product. 
A is a vector of integral polynomials in r variables, r non-negative.
B is a vector of integers. C is the inner product of A and B.*)


PROCEDURE HIPRAN(RL,KL,QL,NL: LIST): LIST; 
(*Homogeneous integral polynomial random.  k is a positive
beta-digit. q is a rational number q1/q2 with
0 lt q1 le q2 lt beta. n is a non-negative beta-digit
r ge 0.  A is a random homogeneous integral polynomial
in r variables with homogeneous degree n. max norm of
A lt 2**k and q is the probability that any
particular term of A has a non-zero coefficient.*)


PROCEDURE IPRAN(RL,KL,QL,N: LIST): LIST; 
(*Integral polynomial random.  k is a positive beta-digit.
q is a rational number q1/q2 with 0 lt q1 le q2 lt beta.
N is a list (n sub r, ...,n sub 1) of non-negative beta-digits
r ge 0.  A is a random integral polynomial in r variables
with deg sub i of a le n sub i + 1 for 1 le i le r.
Max norm of A lt 2**k and q is the probability that any
particular term of A has a non-zero coefficient. Modified
version, original version by G. E. Collins. *)
                                            

END DIPIPOL.


(* -EOF- *)
