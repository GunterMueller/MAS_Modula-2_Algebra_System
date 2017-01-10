(* ----------------------------------------------------------------------------
 * $Id: SUBST.md,v 1.1 1995/11/05 15:57:34 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SUBST.md,v $
 * Revision 1.1  1995/11/05 15:57:34  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SUBST;
(* Substitution Group Polynomial System Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

FROM MASELEM	IMPORT	GAMMAINT;

CONST rcsid = "$Id: SUBST.md,v 1.1 1995/11/05 15:57:34 pesch Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE SUBINF();
(*Substitution Group Polynomial System Information. *) 

PROCEDURE SUBSGR(M: GAMMAINT): LIST;
(*Substitution Group Read.
Input of producing elements of a substitution group with M variables. *)

PROCEDURE SUBSGW(SG: LIST);
(*Substitution Group Write.
Output of the substitution group SG. *)

PROCEDURE SUBORD(SG: LIST): GAMMAINT;
(*Substitution Group Order.
The order of the substitution group SG is computed. *)

PROCEDURE SUBORP(SG, POL: LIST): LIST;
(*Substitution Group Orbit Polynomial.
The orbit polynomial of the polynom POL is computed with respect to the
substitution group SG. *)

PROCEDURE SUBSYM(SG, POL: LIST): GAMMAINT;
(*G-symmetric Polynomial Symmetric Check.
The Procedure returns 1, if POL is SG-symmetric. Otherwise 0. *)

PROCEDURE SUBOPL(SG, ML: LIST): LIST;
(*G-symmetric Orbit Polynomial List.
The SG-symmetric orbit polynomial list is calculated from the monomial 
list ML and the substitution group SG. *)

PROCEDURE SUBCHK(SG, BASE, POL: LIST): LIST;
(*G-Symmetric Polynomial Check.
The original polynomial is computed from the polynomial POL and the
SG-symmetric base polynomials BASE with respect to the 
substitution group PG. *)

PROCEDURE SUBPOW(SG: LIST; K: GAMMAINT): LIST;
(*Noether SK Power Sum Computation for Substitution Groups.
The result of the procedure is the list of orbit polynomials and
(z_1, z_2, ..., z_n)-terms of the polynomial S_K w.r.t. the
substitution group PG. *)

PROCEDURE SUBRED(SG, POL: LIST; VAR BASE, BASEPOL, REMPOL: LIST);
(*Noether G-Symmetric Polynomial Computation for Substitution Groups.
The SG-symmetric polynomial BASEPOL, which is the SG-symmetric
polynomial reconstruction w.r.t. the base polynomials BASE, and the
remainder polynomial REMPOL are computed from the polynomial POL w.r.t.
the substitution group SG over the rational numbers after the method of
E. Noether.*)

END SUBST.

(* -EOF- *)
