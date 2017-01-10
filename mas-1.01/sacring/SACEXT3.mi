(* ----------------------------------------------------------------------------
 * $Id: SACEXT3.mi,v 1.3 1992/10/15 16:28:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT3.mi,v $
 * Revision 1.3  1992/10/15  16:28:56  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:48  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:56  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT3;

(* SAC Extensions 3 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    INV, COMP, SRED, SFIRST, ADV, FIRST, RED;

FROM SACLIST IMPORT CONC, FIRST2, RED2, LAST;

CONST rcsidi = "$Id: SACEXT3.mi,v 1.3 1992/10/15 16:28:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



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
VAR  A, L1, L2, LP, TL: LIST; 
BEGIN
(*1*) TL:=1; I:=BETA; LP:=L; 
      REPEAT FIRST2(LP, L1,L2); 
             IF TL = 1 THEN ADV(L1, A,L1); 
                IF L1 <> SIL THEN SFIRST(LP,L1); TL:=0; ELSE
                   SFIRST(LP,L2); END; 
                ELSE A:=FIRST(L1); END; 
             I:=COMP(A,I); LP:=RED2(LP); 
             UNTIL (LP = SIL); 
      I:=INV(I); 
      IF TL = 0 THEN M:=L; ELSE M:=BETA; END; 
      RETURN; 
(*4*) END CPLEXN; 


PROCEDURE PERMCY(P: LIST): LIST; 
(*Permutation, cyclic.  P is a list (P sub 1 , P sub 2 , ...,
P sub n ), n ge 0.  PP eq (P sub 2 , P sub 3 , ..., P sub n ,
P sub 1 ).*)
VAR  PL, PL1, PP, PS: LIST; 
BEGIN
(*1*) PP:=BETA; 
      IF P = SIL THEN RETURN(PP); END; 
      ADV(P, PL1,PS); 
      WHILE PS <> SIL DO ADV(PS, PL,PS); PP:=COMP(PL,PP); END; 
      PP:=COMP(PL1,PP); PP:=INV(PP); RETURN(PP); 
(*4*) END PERMCY; 


END SACEXT3.
(* -EOF- *)
