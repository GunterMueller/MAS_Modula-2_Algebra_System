(* ----------------------------------------------------------------------------
 * $Id: DIPRNIB.md,v 1.1 1995/10/12 14:44:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNIB.md,v $
 * Revision 1.1  1995/10/12 14:44:59  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPRNIB;

(* DIP Rational Numbers Polynomial Definition Module in the sense of Janet. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPRNIB.md,v 1.1 1995/10/12 14:44:59 pesch Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE DIRPNFJ(P,S: LIST): LIST; 
(*Distributive rational polynomial normal form in the sense of Janet. 
  P is a list of non zero polynomials in distributive
  representation in r variables. S is a distributive
  polynomial. The result R is a polynomial such that S is reducible to R
  modulo P in the sense of Janet and R is in normalform with respect to P. *)

PROCEDURE DIRLISJ(P: LIST): LIST;
(*Distributive rational polynomial list irreducible set.
  P is a list of distributive polynomials,
  The result is a set of polynomials, such that each polynomial p is in
  Janet-normalform modulo P-(p) *)

PROCEDURE DIRPCOM(F: LIST): LIST;
(* Distributive rational polynom complete system.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)

PROCEDURE DIRPIB2(F: LIST): LIST;
(* Distributive rational polynom involutive basis.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)

PROCEDURE DIRPIB(F: LIST): LIST;
(* Second Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Rational Polynomial List F.
   Output: Equivalent involutive system G.*)

END DIPRNIB.


(* -EOF- *)
