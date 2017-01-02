(* ----------------------------------------------------------------------------
 * $Id: SACEXT1.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACEXT1.mi,v $
 * Revision 1.3  1992/10/15  16:28:54  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:46  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:15:52  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACEXT1;

(* SAC Extensions 1 Implementation Module. *)



(* Import lists and declarations. *) 

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    COMP, SRED, ADV, FIRST, RED;

FROM SACLIST IMPORT CONC, MEMBER, EQUAL, FIRST2, LAST;

FROM SACI IMPORT IDP2, IMP2, IORD2;

CONST rcsidi = "$Id: SACEXT1.mi,v 1.3 1992/10/15 16:28:54 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE LCONC(L: LIST): LIST; 
(*List concatenation.  L is a list (L sub 1 , ..., L sub n ),
n ge 0, such that each L sub i is a list.  M eq CONC(L sub 1 , ...,
L sub n ).  The lists L sub 1 , ..., L sub n are modified.*)
VAR  L1, L2, LP, LP1, M: LIST; 
BEGIN
(*1*) IF L = SIL THEN M:=BETA; RETURN(M); END; 
(*2*) LP:=L; 
      REPEAT ADV(LP, M,LP); 
             UNTIL (M <> SIL) OR (LP = SIL); 
      L1:=M; 
      WHILE LP <> SIL DO ADV(LP, L2,LP); 
            IF L2 <> SIL THEN LP1:=LAST(L1); SRED(LP1,L2); L1:=L2; 
               END; 
            END; 
      RETURN(M); 
(*5*) END LCONC; 


PROCEDURE LEQUAL(A,B: LIST): LIST; 
(*List equality.  A eq (A sub 1 , ..., A sub m ), m ge 0, and
B eq (B sub 1 , ..., B sub n ), n ge 0, are two lists.  b eq 1 if
for each a sub i there is at least one B sub j such that
A sub i eq B sub j, and for each B sub j there is at least
one A sub i with B sub j eq a sub i.  otherwise b eq 0.*)
VAR  A1, AP, B1, BL, BP: LIST; 
BEGIN
(*1*) BL:=1; AP:=A; 
      WHILE AP <> SIL DO ADV(AP, A1,AP); BL:=MEMBER(A1,B); 
            IF BL = 0 THEN RETURN(BL); END; 
            END; 
      BP:=B; 
      WHILE BP <> SIL DO ADV(BP, B1,BP); BL:=MEMBER(B1,A); 
            IF BL = 0 THEN RETURN(BL); END; 
            END; 
      RETURN(BL); 
(*4*) END LEQUAL; 


PROCEDURE LMERGE(A,B: LIST): LIST; 
(*List merge.  A and B are lists of objects.  C is the result of
merging A and B.*)
VAR  AL, AP, BL, BP, C, SL: LIST; 
BEGIN
(*1*) C:=A; BP:=B; 
      WHILE BP <> SIL DO ADV(BP, BL,BP); AP:=A; SL:=0; 
            WHILE (AP <> SIL) AND (SL = 0) DO ADV(AP, AL,AP); 
                  SL:=EQUAL(AL,BL); END; 
            IF SL = 0 THEN C:=COMP(BL,C); END; 
            END; 
      RETURN(C); 
(*4*) END LMERGE; 


END SACEXT1.

(* -EOF- *)
