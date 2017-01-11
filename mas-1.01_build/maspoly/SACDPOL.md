(* ----------------------------------------------------------------------------
 * $Id: SACDPOL.md,v 1.2 1992/02/12 17:33:56 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACDPOL.md,v $
 * Revision 1.2  1992/02/12  17:33:56  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACDPOL;

(* SAC Dense Polynomial Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACDPOL.md,v 1.2 1992/02/12 17:33:56 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE DMPPRD(RL,ML,A,B: LIST): LIST;
(*Dense modular polynomial product.  A and B are polynomials in r
variables over Z sub m, m a beta-integer, r ge 0.  C=A*B.*)


PROCEDURE DMPSUM(RL,ML,A,B: LIST): LIST;
(*Dense modular polynomial sum.  A and B are dense polynomials in r
variables over Z sub m, m a beta-integer.  C=A+B.*)


PROCEDURE DMUPNR(PL,A,B: LIST): LIST;
(*Dense modular univariate polynomial natural remainder.  A and B are
non-zero dense univariate polynomials over Z sub p, p a prime
beta-integer, with deg(A) ge deg(B).  C is the natural remainder of B.
The list for A is modified.*)


PROCEDURE DPFP(RL,A: LIST): LIST;
(*Dense polynomial from polynomial.  A is a polynomial in r
variables, r ge 0.  B is the result of converting A to dense
polynomial representation.*)


END SACDPOL.


(* -EOF- *)
