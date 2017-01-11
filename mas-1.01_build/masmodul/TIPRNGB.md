(* ----------------------------------------------------------------------------
 * $Id: TIPRNGB.md,v 1.1 1995/11/05 15:57:37 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: TIPRNGB.md,v $
 * Revision 1.1  1995/11/05 15:57:37  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE TIPRNGB;

(* DIP Rational Extended Groebner Bases Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

CONST rcsid = "$Id: TIPRNGB.md,v 1.1 1995/11/05 15:57:37 pesch Exp $";
CONST copyright = "Copyright (c) 1995 Universitaet Passau";

PROCEDURE DIREGB(P, TF: LIST; VAR GB, GBM: LIST);
(*Distributive rational polynomials extended groebner basis. *)

END TIPRNGB.

(* -EOF- *)
