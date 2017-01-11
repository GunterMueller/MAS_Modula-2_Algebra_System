(* ----------------------------------------------------------------------------
 * $Id: DIPIB.md,v 1.2 1995/12/16 12:21:53 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIB.md,v $
 * Revision 1.2  1995/12/16 12:21:53  kredel
 * Comments slightly changed.
 *
 * Revision 1.1  1995/10/12  14:44:52  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE DIPIB;

(* DIP Common Polynomial System Definition Module in the sense of Janet. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST;

TYPE PROCP5V2 = PROCEDURE(LIST, LIST, LIST, LIST, LIST, VAR LIST, VAR LIST);

CONST rcsid = "$Id: DIPIB.md,v 1.2 1995/12/16 12:21:53 kredel Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE ADCAN(P: LIST): LIST;
(* Arbitrary Polynomial Cancel.
   P is an polynomial of arbritrary domain,
   P is canceld down with ADPCP iff the domain of P is INT and with
   DIPMOC else *)

(*****************************************************************************
 * The following two algorithms are from: Zharkov, Blinkov                   *
 *        Involutive Bases of Zero-Dimensional Ideals and                    *
 *        Involution approach to Solving Systems of Algebraic Equations      *
 *****************************************************************************)

PROCEDURE ADPNFJ(G,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain polynomial normalform in the sense of Janet.
   G is a list of polynomials in distributive representation over an arbitrary
   domain, P is a polynomial as above,
   returns a polynomial h such that P is Janet-reducible to h modulo G
   and h is in Janet-normalform w.r.t. G, the flag "reduced" is set TRUE iff
   a Janet-reduction took place *)

PROCEDURE DIPNFJ(P,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Distributive polynomial normal form in the sense of Janet. 
   P is a list of non zero polynomials in distributive
   representation in r variables. S is a distributive polynomial. 
   The result is a polynomial h such that S is reducible to h modulo P 
   in the sense of Janet and h is in Janet-normalform with respect to P,
   "reduced" is set TRUE iff a Janet-reduction took place. *)

PROCEDURE DIPINFJ(P,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Integral Distributive polynomial normal form in the sense of Janet. 
   P is a list of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. h is a polynomial such that S is reducible to h
   modulo P in the sense of Janet and h is in normalform with respect to P,
   reduced is set TRUE iff a Janet-reduction took place. *)

PROCEDURE DILISJ(P: LIST; VAR PP: LIST; VAR reduced: BOOLEAN);
(* Distributive polynomial list irreducible set in the sense of Janet.
   P is a list of distributive polynomials,
   PP is the result of reducing each polynomial p in P modulo P-(p)
   in the sense of Janet until no further reductions are possible.
   reduced is set TRUE if a Janet-reduction took place. *)

PROCEDURE DIPIRLJ(P: LIST; VAR F: LIST; VAR reduced: BOOLEAN);
(* distributive polynomial interreduced list in the sense of Janet.
   P is a list of polynomials in distributive representation over an 
   arbitrary domain, 
   The result is a Janet-interreduced list of polynoms F,
   reduced is set TRUE iff a reduction took place. *)

(*** Algorithms from: Zharkov, Blinkov; 
                                Involutive Bases of zero-dimensional ideals ***)

PROCEDURE DIPCOM(F: LIST): LIST;
(* Distributive polynomial complete.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)

PROCEDURE DIPIB2(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)

(*** Algorithm from: Zharkov, Blinkov:
              Involution Approach to Solving Systems of Algebraic Equations ***)

PROCEDURE DIPIB3(F: LIST): LIST;
(* Distributive polynom involutive base.
   Algorithm for computing the involutive Base for a given polynomial list F.
   Input: Distributiv Polynomial List F.
   Output: Equivalent involutive system G.*)

(******************************************************************************
 *    Algorithm analog to: Zharkov, Blinkov:                                  * 
 *                              Solving zero-dimensional involutive systems,  * 
 *    an optional using of three criteria is possible. The three criteria are *
 *    from Gerdt, Blinkov: Involutive Polynomial Bases.                       * 
 *----------------------------------------------------------------------------*
 * This algorithm works with extended polynomial lists. An extended polynomial*
 * is a triple (deg, pol, ht) with:                                           * 
 *    deg - total degree of the leading term or 0 if the polynomial is already*
 *          prolongated.                                                      *
 *    pol - the polynomial                                                    *
 *    ht  - head term of the starting polynomial. ht must not be equal to the *
 *          head term of pol. ht is updated in the procedure IBcrit.          *
 *          For details see Gerdt, Blinkov: Involutive Polynomial Bases.      * 
 ******************************************************************************)

PROCEDURE ADEPNFJ(G,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain extended polynomial normalform in the sense of Janet.
   G is a list of polynomials in distributive representation over an arbitrary
   domain, P is a polynomial as above,
   returns a polynomial h such that P is Janet-reducible to h modulo G
   and h is in Janet-normalform w.r.t. G, the flag "reduced" is set True iff
   a Janet-reduction took place  *)

PROCEDURE DIPENFJ(P,S: LIST; VAR R: LIST; VAR c: BOOLEAN);
(* Distributive extended polynomial normal form in the sense of Janet. 
   P is a list of non zero extended polynomials in distributive
   representation in r variables. S is a distributive extended 
   polynomial. R is an extended polynomial such that S is reducible 
   to R modulo P in the sense of Janet and R is in normalform with 
   respect to P, c is set TRUE iff a Janet-reduction took place. *)

PROCEDURE DIPEINFJ(P,S: LIST; VAR R: LIST; VAR c: BOOLEAN);
(* Integral distributive extended polynomial normal form in the sense of Janet. 
   P is a list of non zero extended polynomials in distributive
   representation in r variables. S is a distributive extended
   polynomial. R is a polynomial such that S is reducible to R
   modulo P in the sense of Janet and R is in normalform with respect to P. *)

PROCEDURE IsInvolutive(G: LIST): BOOLEAN;
(* Is involutive.
   Test wether G is involutive,
   G is a list of distributive polynomials,
   Returns TRUE iff G is involutive, FALSE else *)

PROCEDURE ADEPmark(g, G: LIST): LIST;
(* Arbitrary domain extended polynomial mark.
   g is an extended polynomial, G is a list of extended polynomials;
   the first entry of g is set to 0 and G is set to G cup g *)

PROCEDURE DILISJ2(P: LIST): LIST;
(* Distributive polynomial list irreducible set.
   P is a list of distributive polynomials,
   PP is the result of reducing each p element of P modulo P-(p)
   in the sense of Janet until no further reductions are possible. *)

PROCEDURE ADEPtriple(PS, term: LIST): LIST;
(* Arbitrary domain extende polynomial triple.
   Input: PS - a list of polynomials, term - term to use as head term or SIL.
   Output: a list of extended polynomials *)

PROCEDURE ADEPuntriple(PS: LIST): LIST;
(* Arbitrary domain extended polynomial untriple.
   Input: PS - an extended polynomial list.
   Output: a polynomial list. *)

PROCEDURE ADEPCrumble(P: LIST; VAR deg, pol, ht: LIST);
(* Arbitrary domain extended polynomial crumble.
   Input: an arbritraty domain extended polynomial,
   Output: the components of the extended polynomial: deg - the total degree 
           of the leading term, pol - the polynomial and if exists ht - the
           head term of the polynomial and 0 else. *)

PROCEDURE ADEPCompose(deg, pol, ht: LIST): LIST;
(* Arbitrary domain extended polynomial compose.
   Input: the components to build an extended polynomial: deg - the total degree
	  of the polynomial, pol - the polynomial and ht - the head term of
          the polynomial or 0 if ht should not be element of the extended
          polynomial.
   Output: an extended polynomial. *)

PROCEDURE ADEPdegree(P: LIST): LIST;
(* Arbitrary domain extended polynomial degree.
   Input: P - an arbitrary domain extended polynomial.
   Ouput: the degree of the head term of P, that is the first entry from the
          extended polynomial *)

PROCEDURE ADEPpolynomial(P: LIST): LIST;
(* Arbitrary domain extended polynomial polynomial.
   Input: P - an arbitrary domain extended polynomial.
   Output: the polynomial entry of the extended polynomial, that is the second
           entry from the extended polynomial. *)

PROCEDURE ADEPheadterm(P: LIST): LIST;
(* Arbitrary domain extended plynomial head-term.
   Input: P - an arbitrary domain extended polynomial.
   Output: the head term entry of the extended polynomial. That is the third
           entry in the extended polynomial list. 
   The third list entry must not be equal to the head-term of the polynomial
   entry of the extended polynomial list. *)

PROCEDURE ADEPleadingterm(P: LIST): LIST;
(* Arbitrary polynomial leading term.
   Input: P - an arbitrary domain extended polynomial.
   Output: the head term of the polynomial in the extended polynomial list,
           that is the first element of the second list entry. *)

PROCEDURE IBcrit(NM, G: LIST): LIST;
(* Inovlutive Base criterium.
   Input: NM - a list of prolongated extended polynomials, G - a list of 
          extended polynomials.
   Output: NM minus the polynomials from NM which are reducible to 0 by
          one of the criteriums, or which are reducible to 0 modulo G. *)

PROCEDURE DIPIB(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Polynomial List F.
   Output: Equivalent involutive system G.*)

(*****************************************************************************
 *     algorithm analog to: Zharkov, Blinkov,                                * 
 *                         Solving zero-dimensional involutive systems       *
 *---------------------------------------------------------------------------*
 * This algorithm does not work with extended polynomial list and thus it    *
 * needs another Janet-interreducible algorithm.                             *
 * This algorithm does a Janet-reduction with two different input sets:      *
 *  the first set is a list of possible candidates for prolongations and     *
 *  the second set is a list of already condered polynomials                 *
 *****************************************************************************)

PROCEDURE ADPNFJS(G1,G2,G3,G4,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain polynomial normalform in the sense of Janet modulo a set
   of set of polynomials.
   G1-G4 are lists of polynomials in distributive representation over an
   arbitrary domain, P is a polynomial.
   The result is a polynomial h such that P is Janet-reducible to
   h modulo the union of G1-G4 and h is in Janet-Normalform w.r.t. G1-G4, 
   the flag "reduced" is set TRUE iff a Janet-reduction took place *)

PROCEDURE DIPNFJS(P1,P2,P3,P4,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Distributive polynomial normal form in the sense of Janet modulo a set of
   sets of polynomials. 
   P1-P4 are lists of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. R is a polynomial such that S is reducible to R modulo P 
   in the sense of Janet and R is in normalform with respect to P,
   reduced is set TRUE iff a reduction took place. *)

PROCEDURE DIPINFJS;
(* Integral Distributive polynomial normal form in the sense of Janet modulo a
   set of sets of polynomials. 
   P1-P4 are lists of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. h is a polynomial such that S is reducible to h
   modulo P in the sense of Janet and h is in normalform with respect to P,
   reduced is set TRUE iff a Janet-reduction took place. *)

PROCEDURE DIPIRLJ2(VAR P, Q: LIST; VAR reduced: BOOLEAN);
(* Distributive polynomial list interreduced list in the sense of Janet.
   P and Q are lists of polynomials in distributive representation over an 
   arbitrary domain,
   P and Q already initialised by the calling procedure.
   P contains polynomials which are possible candidates for prolongations,
   Q are already considered.
   Output is the list P of Janet-reduced polynomials from p plus Janet-reduced
   polynomials from Q. Q contains polynomials from input Q which are not
   Janet-reduced.
   reduced is set TRUE iff a reduction took place *)

PROCEDURE DIPIB4(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)

(******************************************************************************)

PROCEDURE SetDIPIBopt(options: LIST);
(* Set distributive polynomial involutive base options.
   Input: List of 4 options in the order Trace-Level, Cancel-Option, 
          Select-Option, ISJ-Algorithm.
   For details see the corresponding procedures *)

PROCEDURE SetDIPIBTraceLevel(level: INTEGER);
(* Set Trace Level.
   Input is the integer level. You get the following informatins:
   0: no information,
   1: computing time and number of polynomials of the computed involutive base,
   2: informations about each Janet-reduction,
   3: more detailed information of each Janet-reduction. *)

PROCEDURE SetDIPIBCancel(Canc: CARDINAL);
(* Set distributive polynomial involutive base cancel.
   Set the function to use to cancel down the coefficients in case of
   integer coefficients. Canc=1 means: use ADCAN, 2 means: use DIPMOC *)

PROCEDURE SetDIPIBSelect(SEL: INTEGER);
(* Set distributive polynomial involutive base select.
   Set polynomial selection strategy:
   1: DIPSSM, 2: DIPFIRST  *)

PROCEDURE SetDIPIBISJ(Sel: INTEGER);
(* Set distributive involutive base irreducible set in the sense of Janet.
   Set Janet-Irreducible-Set Algorithm, 1: DILISJ, 2: DIPIRLJ *)

PROCEDURE SetDIPIBCrit(crit: INTEGER);
(* Set distributive polynomial involutive base critera.
   Input: an integer crit.
   DIPIBOpt.Crit ::= TRUE iff cirt = 1 and FALSE else *)

PROCEDURE SetDomainNFJ;
(* Initialize Jdomain *)

END DIPIB.


(* -EOF- *)
