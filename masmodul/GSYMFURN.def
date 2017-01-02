(* ----------------------------------------------------------------------------
 * $Id: GSYMFURN.md,v 1.1 1995/11/05 15:57:28 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: GSYMFURN.md,v $
 * Revision 1.1  1995/11/05 15:57:28  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE GSYMFURN;
(* G-Symmetric Rational Polynomial System Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

FROM MASELEM	IMPORT	GAMMAINT;

CONST rcsid = "$Id: GSYMFURN.md,v 1.1 1995/11/05 15:57:28 pesch Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE GRNORP(PG, MO: LIST): LIST;
(*G-Symmetric Rational Orbit Polynomial.
The PG-symmetric orbit polynomial of the monomial MO is computed
with respect to the permutation group PG. *)

PROCEDURE GRNOPL(PG, ML: LIST): LIST;
(*G-Symmetric Rational Orbit Polynomial List.
The PG-symmetric orbit polynomial list is calculated from the the
monomial list ML and the permutation group PG. *)

PROCEDURE GRNCUT(PG, POL: LIST; VAR POL_1, POL_2: LIST);
(*G-Symmetric Rational Polynomial Cut.
The Polynomial POL is splitted up into the G-symmetric polynomial POL_1
and the remainder polynomial POL_2 with respect to the permutation group PG
and the termorder. *)

PROCEDURE GRNCHK(PG, BASE, POL:LIST): LIST;
(*G-Symmetric Rational Polynomial Check.
The original polynomial is computed from the polynomial POL and the
PG-symmetric base polynomials BASE with respect to the permutation group PG. *)

PROCEDURE GRNCHKBAS(VAR BASE, POL: LIST);
(*G-Symmetric Rational Base Check.
The procedure removes not used base orbit polynomials from BASE and
make an update of POL. *)

PROCEDURE GRNRED(PG, POL: LIST; VAR BASE, BASE_POL, REM_POL: LIST);
(*G-Symmetric Rational Polynomial Reduction.
The PG-symmetric polynomial BASE_POL, which is the PG-symmetric polynomial
reconstruction with respect to the base polynomials BASE, and the remainder
polynomial REM_POL are computed from the polynomial POL with respect to the
permutation group PG. *)

PROCEDURE GRNBAS(PG: LIST): LIST;
(*G-Symmetric Rational Base Construction.
The PG-symmetric base polynomials for the permutation group PG are computed. *)

PROCEDURE GRNGGB(PG: LIST): LIST;
(*G-Symmetric Rational Base Construction (Buchberger-Algorithm).
The PG-symmetric base polynomials for the permutation group PG are computed
with the Buchberger-Algorithm. *)

END GSYMFURN.
(* -EOF- *)
