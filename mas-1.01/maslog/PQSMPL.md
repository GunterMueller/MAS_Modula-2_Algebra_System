(* ----------------------------------------------------------------------------
 * $Id: PQSMPL.md,v 1.4 1995/12/16 11:34:34 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: PQSMPL.md,v $
 * Revision 1.4  1995/12/16 11:34:34  kredel
 * Changed comments to documentation rules.
 *
 * Revision 1.3  1995/11/04  18:00:26  pesch
 * Changed comments violating documentation rules. Should be rewritten.
 *
 * Revision 1.2  1994/11/28  21:12:07  dolzmann
 * Moved procedures from PQSMPL into PQBASE.
 *
 * Revision 1.1  1993/12/18  20:12:17  dolzmann
 * System for the simplification of boolean combinations of polynomial 
 * equations.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE PQSMPL;
(* Polynomial Equation Simplification Definition Module. *)

(******************************************************************************
*    P O L Y N O M I A L   E Q U A T I O N   S I M P L I F I C A T I O N      *
*-----------------------------------------------------------------------------*
* Author:   Andreas Dolzmann                                                  *
* Language: Modula II                                                         *
* System:   This program is written for the computer algebra system MAS by    *
*           Heinz Kredel.                                                     *
* Remark:   Libraries maskern, maslisp and maslog, masdom, maspoly, ...       *
*           are used.                                                         *
* Abstract: A program for simplification of polynomial equations and          *
*           inequations in the field of the complex numbers.                  *
******************************************************************************)

FROM MASSTOR 	IMPORT LIST;
FROM MASLISPU 	IMPORT PROCF1, PROCP1, PROCF3;

CONST rcsid = "$Id: PQSMPL.md,v 1.4 1995/12/16 11:34:34 kredel Exp $";
CONST copyright = "Copyright (c) 1993 Universitaet Passau";


(******************************************************************************
*                         S I M P L I F I C A T I O N                         *
******************************************************************************)

PROCEDURE PQSCNF(phi: LIST):LIST;
(* polynomial equation simplification normal form. phi is an arbitrary 
quantifier-free formula. A equivalent formula in SCNF is returned. *)

PROCEDURE PQSDNF(phi: LIST):LIST;
(* polynomial equation simplification normal form. phi is an arbitrary 
quantifier-free formula. A equivalent formula in SDNF is returned. *)

PROCEDURE PQCnfSimplify(nu:LIST):LIST;
(* polynomial equation cnf based simplification. nu is an quantifier free
formula. The formula nu is simplified. Consult the documentation for a 
description of the rules which are applied *)

PROCEDURE PQDnfSimplify(nu:LIST):LIST;
(* polynomial equation dnf based simplification. nu is an quantifier free
formula. The formula nu is simplified. Consult the documentation for a 
description of the rules which are applied *)

PROCEDURE SimplifyNf(nf: LIST):LIST;
(* simplify normal form. nf is a formula in disjunctive normal form or
conjunctive normal form. A simplification of nf is returned.
Following rules are applied: Equal literals in clauses are contracted,
atomic formulas with identical polynomials are contracted to TRUE or FALSE. 
Note: identical clauses are not contracted. This happens in the
GetDataXXX Procedures. In this procedure equal implications are contracted. *)


(******************************************************************************
*                       I D E A L   P R O C E D U R E S                       *
******************************************************************************)

PROCEDURE IdealMember(G,p:LIST):BOOLEAN;
(* ideal membership test. G is groebner basis. Iff p in ID(g) then 1 
is returned otherwise 0. *)

PROCEDURE RadicalMember(G,p:LIST):BOOLEAN;
(* radical membership test. G is a groebner basis. Iff p in RAD(G) then 1 is
returned otherwise 0. The new variable Rw is introduced. *)


(******************************************************************************
*                       D I P A D - P R O C E D U R E S                       *
******************************************************************************)

PROCEDURE DIPADGB(P:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis. P is a list of
polynomials (over the ring of integers). A groebner basis of P is returned.
This procedure is at moment only a dummy procedure. It should
calculate a groebner basis in respect to the coefficient ring of the
polynomials. *)

PROCEDURE DIPADNF(P,S:LIST):LIST;
(* distributive polynomial arbitrary domain normal form. P is a list of
polynomials. The normal form of the polynomial
S w.r.t. P is returned. This procedure is at moment only a dummy. Is should
work on Polynomials over arbitrary fields and rings. *)

PROCEDURE DILADNF(P,S:LIST):LIST;
(* distributive polynomial list arbitrary domain normal form. P is a list of
polynomials. S is a list of polynomials.
The list of normal forms of the polynomials of 
S w.r.t. P is returned. This procedure is at moment only a dummy. Is should
work on Polynomials over arbitrary fields and rings. *)

PROCEDURE DIPADGBext(gb,pols:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis extension.
gb is a groebner basis, pols is a list of polynomials.
A groebner basis of the ideal basis gb join pols is calculated and
returned. This procedure is at moment only a dummy. *)

PROCEDURE DIPADGBunion(gb1,gb2:LIST):LIST;
(* distributive polynomial arbitrary domain groebner basis union. gb1 and
gb2 are groebner basis. A groebner basis of the ideal basis gb1 join gb2
is calculated and returned. This procedure is at moment only a dummy. *)

PROCEDURE DIPADIRSET(P:LIST):LIST;
(* distributive polynomial arbitrary domain irreducible set. P is a list
of polynomials. A set PP of polynomials is returned. PP is the result of 
reducing each element p modulo P - {p} until no further reductions are 
possible. *)

PROCEDURE DIPADGBRED(gb: LIST):LIST;
(* distributive polynomial groebner basis reduction. gb is a groebner basis
of distributive polynomials over an arbitrary domain. 
The unique reduced and ordered groebner basis to gp is returned. *)

(******************************************************************************
*                                O P T I O N S                                *
******************************************************************************)
			
PROCEDURE PQOPT(O:LIST):LIST;
(* polynomial equation options. The options of the PQ-System are set.
The list O is of the following format: The first entry
is the trace level of the system, the second entry determines the method for 
the radical member ship test, the third entry is a list of powers for the 
pseudo radical member ship test, the fourth entry controls the replacement
of the premises of the implications, and the fifth entry controls the 
You can omit an entry of O 
by writing a -1 on the place of the entry. You need not specify all entries.
The old parameters are returned. *)

PROCEDURE PQOPTWR();
(* polynomial options write. The options of the PQ-System are printed in the
output stream. *)

PROCEDURE PQDEMO();
(* Demonstration for this package. *)

PROCEDURE DLSWRITE(S:ARRAY OF CHAR;b:LIST);
(* debug level SWRITE. The string S is in dependency of the debug level
written to the output stream. In contrast to MAS a blank line is added.
(analogous to UWRITE and UWRIT1) *)

PROCEDURE SETADD(a,b:LIST):LIST;
(* set add element. If the element elem is not in the set set, then
{elem} join set is returned else set is returned. *)

PROCEDURE rabinowitsch(p:LIST):LIST;
(* rabinowitsch. p is a non zero polynomial.
The polynomial 1-Zp is returned. Z denotes the variable with the exponent
vector (0,...,0,1). *)

END PQSMPL.

(* -EOF- *)
