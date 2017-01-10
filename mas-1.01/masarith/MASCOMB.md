(* ----------------------------------------------------------------------------
 * $Id: MASCOMB.md,v 1.1 1994/11/28 20:39:33 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASCOMB.md,v $
 * Revision 1.1  1994/11/28  20:39:33  dolzmann
 * New modules MASCOMB.md, MASCOMB.mi, MASSET.md, and MASSET.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASCOMB; 
(* MAS Combinatorial System Definition Module. *)

FROM MASSTOR	IMPORT	LIST; 

CONST rcsid = "$Id: MASCOMB.md,v 1.1 1994/11/28 20:39:33 dolzmann Exp $";
CONST copyright = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE INVPERM(perm: LIST):LIST;
(* inverse permutation. perm is a permutation. The inverse permutation
is returned, i.e. LPERM(LPERM(x,p),INVPERM(p))=x. *)

PROCEDURE PVFLISTS(list1,list2:LIST):LIST;
(* permutation vector from lists.
list1 and list2 are lists of the same length.
A permutations vector P is returned, so that LPERM(list1,P)=list2 *)

END MASCOMB.

(* -EOF- *)
