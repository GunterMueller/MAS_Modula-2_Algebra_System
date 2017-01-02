(* ----------------------------------------------------------------------------
 * $Id: NOETHER.md,v 1.1 1995/11/05 15:57:31 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: NOETHER.md,v $
 * Revision 1.1  1995/11/05 15:57:31  pesch
 * Diplomarbeit Manfred Goebel, Reduktion G-symmetrischer Polynome fuer
 * beliebige Permutationsgruppen G, slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE NOETHER;
(* Noether Polynomial System Definition Module. *)

FROM MASSTOR	IMPORT	LIST;

FROM MASELEM	IMPORT	GAMMAINT;

CONST rcsid = "$Id: NOETHER.md,v 1.1 1995/11/05 15:57:31 pesch Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE NOEINF();
(*Noether Polynomial System Information.*)

PROCEDURE NOENSP(PG: LIST);
(*Noether Number of Noetherian Base Polynomials.
The number of noetherian base polynomials is computed.*)

PROCEDURE NOEL32(M, K: GAMMAINT): LIST;
(*Noether SK Polynomial Computation.
The result of the procedure is a respresentation of the polynomial S_K
w.r.t the polyomials S_M, ..., S_2, S_1 over the rational numbers.*)

PROCEDURE MERGE(FLAG: BOOLEAN; BASE1, POL1: LIST; VAR BASE2, POL2: LIST);
(*Noether Merge of Base Polynomials.
The procedure merges BASE1 and BASE2 into BASE2, makes an update of 
POL1 and POL2 with respect to the new base and return the sum 
(FLAG = TRUE) or the product (FLAG = FALSE) of POL1 and POL2.*)

PROCEDURE NOESRT(POL: LIST): LIST;
(*Noether Polynomial Sort.
The polynomial POL in noetherian representation is sorted with
respect to the lexicographical term order and the given term order.*)

PROCEDURE NOEPOW(PG: LIST; K: GAMMAINT): LIST;
(*Noether SK Power Sum Computation.
The result of the procedure is the list of orbit polynomials and
(z_1, z_2, ..., z_n)-terms of the polynomial S_K w.r.t. the
permutation group PG.*)

PROCEDURE NOEPSM(POL1, POL2: LIST): LIST;
(*Noether Polynomial Sum.
The sum of the polynomials POL1 and POL2 in noetherian representation
is computed.*)

PROCEDURE NOEPPR(POL1, POL2, TERM: LIST): LIST;
(*Noether Polynomial Product.
The product of the polynomials POL1 and POL2 in noetherian representation
is computed und every non necessary z-term is removed.*)

PROCEDURE NOEPIP(POL, FACT: LIST): LIST;
(*Noether Polynomial Factor Multiplication.
The product of the polynomial POL in noetherian representation
and the rational number FACT is computed.*)

PROCEDURE NOEPRM(POL, TERM: LIST): LIST;
(*Noether Remove.
All non necessary z-terms are removed from the polynomial POL.*)

PROCEDURE NOERED(PG, POL: LIST; VAR BASE, BASEPOL, REMPOL: LIST);
(*Noether G-Symmetric Polynomial Computation.
The PG-symmetric polynomial BASEPOL, which is the PG-symmetric
polynomial reconstruction w.r.t. the base polynomials BASE, and the
remainder polynomial REMPOL are computed from the polynomial POL w.r.t.
the permutation group over the rational numbers after the method of
E. Noether.*)

END NOETHER.
(* -EOF- *)
