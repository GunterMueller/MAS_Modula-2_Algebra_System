(* ----------------------------------------------------------------------------
 * $Id: ADEXTRA.md,v 1.2 1995/12/16 12:07:19 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ADEXTRA.md,v $
 * Revision 1.2  1995/12/16 12:07:19  kredel
 * Comments slightly changed.
 *
 * Revision 1.1  1995/10/12  14:44:42  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE ADEXTRA;

(* Arbitrary domain extra definition module *)

FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: ADEXTRA.md,v 1.2 1995/12/16 12:07:19 kredel Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE ADPCP(A: LIST): LIST;
(*Arbitrary Domain polynomial content and primitive part.
  A is an arbitrary domain polynomial, 
  The result is the positive primitive part of A. *)

PROCEDURE ADPNEG(A: LIST): LIST;
(*Arbitrary domain polynomial negative. 
  Input: an arbritrary domain polynomial A,
  Output: -A *)

PROCEDURE ADPIQ(A,b: LIST): LIST;
(* Arbitrary domain polynomial integer quotient. 
   Input: A is an arbitrary domain polynomial, b is a nonzero integer,
          and b divides any coefficient of A. 
   Output: C=A/b.*)

PROCEDURE ADLGinH(H, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial list G in H.
   Input: H is a list of lists of arbitrary domain polynomials,
          G is a list of arbitrary domain polynomials.
   Output: TRUE iff ex. h in H s.t. G = h, FALSE else. *)

PROCEDURE ADLGeqH(H, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial list G equal H.
   Input: H and G are lists of arbitrary domain polynomials,
   Ouput: TRUE iff H=G, FALSE else. *)

PROCEDURE ADPFeqG(F, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial F equal G.
   Input: arbitrary domain polynomials F and G,
   Ouput: TRUE iff g = h, FALSE else. *)

PROCEDURE ADIredG(I,G: LIST): LIST;
(* Arbitrary domain polynomial set I reducible modulo G.
   Input: arbitrary domain polynomial sets I and G.
   Output: 0 iff all i in I are reducible modulo G to zero, 
           a reduced polynomial p else *)

PROCEDURE ADGJredI(G,I: LIST): LIST;
(* Arbitrary domain polynomial G Janet-reducible modulo I.
   Input: arbitrary domain polynomial sets G and I.
   Output: 0 iff all g in G are Janet-reducible modulo I to zero, 
           a reduced polynomial p else *)

PROCEDURE IBeqGB(G,I: LIST): LIST;
(* Inovlutive Base equal Groebner Base.
   Input: Groebner Base G and involutive Base I,
   Output: 0 iff Id(G) = Id(I), a reduced polynomial p else *)

END ADEXTRA.

(* -EOF- *)
