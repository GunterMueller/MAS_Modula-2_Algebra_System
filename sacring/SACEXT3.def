(* ----------------------------------------------------------------------------
 * $Id: SACEXT3.md,v 1.2 1992/02/12 17:34:48 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT3.md,v $
 * Revision 1.2  1992/02/12  17:34:48  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:28  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE SACEXT3;

(* SAC Extensions 3 Definition Module. *)



FROM MASSTOR IMPORT LIST;

CONST rcsid = "$Id: SACEXT3.md,v 1.2 1992/02/12 17:34:48 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE CPLEXN(L: LIST;  VAR I,M: LIST); 
(*Cartesian product, lexicographically next.  L eq (L sub 1 , L sub 2
, ..., L sub 2n ), n ge 1, is a list such that L sub 2i is a
non-null list, and L sub 2i-1 is a non-null reductum of L sub 2i,
for 1 le i le n.  I is the element (first(L sub 1 ), first(L sub 3 )
, ..., first(L sub 2n-1 )) of the cartesian product of L sub 2 ,
L sub 4 , ..., L sub 2n.  If I is not the last element
(in the inverse lexicographic ordering)
of this cartesian product, then M is a list (M sub 1 ,
M sub 2 , ..., M sub 2n ), with M sub 2i eq L sub 2i,
M sub 2i-1 a non-null reductum of M sub 2i, for 1 le i le n,
and (first(M sub 1 ), first(M sub 3 ) , ..., first(M sub 2n-1 ))
the lexicographically next element.  If I is the
last element, then M eq ().  the list L is modified.*)


PROCEDURE PERMCY(P: LIST): LIST; 
(*Permutation, cyclic.  P is a list (P sub 1 , P sub 2 , ...,
P sub n ), n ge 0.  PP eq (P sub 2 , P sub 3 , ..., P sub n ,
P sub 1 ).*)


END SACEXT3.

(* -EOF- *)
