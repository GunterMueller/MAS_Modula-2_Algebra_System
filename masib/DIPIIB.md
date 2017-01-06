(* ----------------------------------------------------------------------------
 * $Id: DIPIIB.md,v 1.1 1995/10/12 14:44:56 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIIB.md,v $
 * Revision 1.1  1995/10/12 14:44:56  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPIIB;

(* DIP Integral Polynomial System Definition Module in the sense of Janet. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: DIPIIB.md,v 1.1 1995/10/12 14:44:56 pesch Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE DIIPPR2(A,B: LIST): LIST;
(*Distributive integral polynomial product. 
  A and B are distributive integral polynomials.
  Unlike procedure DIIPPR (in modul DIPI) B consists of one monomial. 
  C=A*B.*)

PROCEDURE DIIPNFJ(P,RPP,S: LIST): LIST; 
(*Distributive integral polynomial normal form in the sense of Janet. 
  P is a list of non zero polynomials in distributive integral
  representation in r variables. RPP and S are distributive integral
  polynomials. R is a polynomial such that S is reducible to R
  modulo P and R is in normalform with respect to p. *)

PROCEDURE DIILISJ(P: LIST): LIST; 
(*Distributive integral polynomial list irreducible set.
  P is a list of distributive integral polynomials,
  The result is a set such that each p element of P modulo P-(p)
  is in Janet-normalform *)

PROCEDURE DIIPCOM(F: LIST): LIST;
(* Distributive integral polynomial complete system.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)

PROCEDURE DIIPIB3(F: LIST): LIST;
(* Distributive integral polynomial involutive base.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)

PROCEDURE DIIPIB2(F: LIST): LIST;
(* Distributive integral polynomial involutive base.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)

PROCEDURE DIIPIB(F: LIST): LIST;
(* Distributive integral involutive base.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)

(*** Initialization and setting of options **********************************)

PROCEDURE InitDIPIIB;
(* Init distributive integral involutive base. 
   Initialization of the DIPIIB options *)

PROCEDURE SetDIPIIBSelect(SEL: INTEGER);
(* Set Distributive integral polynomial Select. 
   Set polynom selection strategy *)

END DIPIIB.


(* -EOF- *)
