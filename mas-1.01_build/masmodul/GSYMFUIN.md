(* ----------------------------------------------------------------------------
 * $Id: GSYMFUIN.md,v 1.1 1995/11/05 15:57:24 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: GSYMFUIN.md,v $
 * Revision 1.1  1995/11/05 15:57:24  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE GSYMFUIN;
(* G-Symmetric Integral Polynomial System Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

FROM MASELEM	IMPORT	GAMMAINT;

CONST rcsid = "$Id: GSYMFUIN.md,v 1.1 1995/11/05 15:57:24 pesch Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE GSYINF();
(*G-Symmetric Polynomial System Information. *)

PROCEDURE GSYPGR(M: GAMMAINT): LIST;
(*G-Symmetric Permutation Group Read.
Input of producing elements for a permutation group with M variables. *)

PROCEDURE GSYPGW(PG: LIST);
(*G-Symmetric Permutation Group Write.
Output of producing elements for the permutation group PG. *)

PROCEDURE GINORP(PG, MO: LIST): LIST;
(*G-Symmetric Integral Orbit Polynomial.
The PG-symmetric orbit polynomial of the monomial MO is computed
with respect to the permutation group PG. *)

PROCEDURE GSYORD(PG: LIST): GAMMAINT;
(*G-Symmetric Permutation Group Order.
The order of the permutation group PG is computed. *)

PROCEDURE GSYNSP(PG: LIST);
(*G-Symmetric Number of Special Polynomials.
The number of special polynomials is computed. *)

PROCEDURE GSYSPG(N: GAMMAINT): LIST;
(*Symmetric Permutation Group.
The symmetric permutation group is computed for N variables. *)

PROCEDURE GINOPL(PG, ML: LIST): LIST;
(*G-Symmetric Integral Orbit Polynomial List.
The PG-symmetric orbit polynomial list is calculated from the monomial
list ML and the permutation group PG. *)

PROCEDURE GINCUT(PG, POL: LIST; VAR POL_1, POL_2: LIST);
(*G-Symmetric Integral Polynomial Cut.
The Polynomial POL is splitted up into the G-symmetric polynomial POL_1
and the remainder polynomial POL_2 with respect to the permutation group PG
and the termorder. *)

PROCEDURE GINCHK(PG, BASE, POL: LIST): LIST;
(*G-Symmetric Integral Polynomial Check.
The original polynomial is computed from the polynomial POL and the
PG-symmetric base polynomials BASE with respect to the permutation group PG. *)

PROCEDURE GINCHKBAS(VAR BASE, POL: LIST);
(*G-Symmetric Integral Base Check.
The procedure removes not used base orbit polynomials from BASE and
make an update of POL. *)

PROCEDURE GSYTWG(TERM1, TERM2: LIST): GAMMAINT;
(*G-Symmetric Term Weight.
The weigth between TERM1 and TERM2 is computed w.r.t. the default term order.
The result is 1, if wg(TERM1) > wg(TERM2), and 0, if wg(TERM1) = wg(TERM2);
otherwise the result is -1. *)

PROCEDURE GSYMLT(N: GAMMAINT): GAMMAINT;
(*G-Symmetric Multilinear Terms.
The result of the preocedure ist a list off all multilinear terms in
N variables. *)

PROCEDURE GSYADD(TERM: LIST): LIST;
(*G-Symmetric Term Adder.
The result of the procedure is the next highest descend term after TERM. *)

PROCEDURE GINRED(PG, POL: LIST; VAR BASE, BASE_POL, REM_POL: LIST);
(*G-Symmetric Integral Polynomial Reduction.
The PG-symmetric polynomial BASE_POL, which is the PG-symmetric polynomial
reconstruction with respect to the base polynomials BASE, and the remainder
polynomial REM_POL are computed from the polynomial POL with respect to the
permutation group PG. *)

PROCEDURE GINBAS(PG: LIST): LIST;
(*G-Symmetric Integral Base Construction.
The PG-symmetric base polynomials for the permutation
group PG are computed. *)

END GSYMFUIN.
(* -EOF- *)
