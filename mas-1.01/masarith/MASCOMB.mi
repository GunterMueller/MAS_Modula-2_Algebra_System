(* ----------------------------------------------------------------------------
 * $Id: MASCOMB.mi,v 1.1 1994/11/28 20:39:34 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1994 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: MASCOMB.mi,v $
 * Revision 1.1  1994/11/28  20:39:34  dolzmann
 * New modules MASCOMB.md, MASCOMB.mi, MASSET.md, and MASSET.mi.
 * Makefile adapted.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASCOMB; 
(* MAS Combinatorial System Implementation Module. *)

FROM MASSTOR	IMPORT	ADV, COMP, INV, LENGTH, LIST, LIST1, RED, SIL;
FROM SACLIST	IMPORT	SLELT;
FROM LISTTOOLS	IMPORT	LSRCHQ; 

CONST rcsidi = "$Id: MASCOMB.mi,v 1.1 1994/11/28 20:39:34 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1994 Universitaet Passau";

PROCEDURE INVPERM(perm: LIST):LIST;
(* inverse permutation. perm is a permutation. The inverse permutation
is returned, i.e. LPERM(LPERM(x,p),INVPERM(p))=x. *)
	VAR L, pos: LIST;
	VAR i, n: INTEGER;
BEGIN
(*1*)	(* initialization *)
	n:=LENGTH(perm);	
	L:=SIL;
(*2*)	(* construct a list L=(1,...,n) *)
	FOR i:=1 TO n DO L:=COMP(0,L); END;
(*3*)	(* construct the inverse permutation *)
	FOR i:=1 TO n DO
		ADV(perm,pos,perm);
		SLELT(L,pos,i);
	END;
(*9*)	RETURN L;
END INVPERM; 

PROCEDURE PVFLISTS(list1,list2:LIST):LIST;
(* permutation vector from lists.
list1 and list2 are lists of the same length.
A permutations vector P is returned, so that LPERM(list1,P)=list2 *)
	VAR a,P: LIST;
BEGIN
	P:=SIL;
	WHILE list2<>SIL DO
		ADV(list2,  a,list2);
		P:=COMP(LSRCHQ(a,list1),P);
	END;
	RETURN INV(P);
END PVFLISTS;

END MASCOMB.

(* -EOF- *)
