(* ----------------------------------------------------------------------------
 * $Id: SACSYM2.mi,v 1.3 1992/10/15 16:27:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACSYM2.mi,v $
 * Revision 1.3  1992/10/15  16:27:57  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:37  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:34  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACSYM2;

(* SAC Symbol 2 Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT SIL, LIST, BETA, 
                    RED, FIRST, COMP, INV, ADV, SFIRST, SRED;

FROM MASERR IMPORT ERROR, severe;

FROM SACLIST IMPORT AWRITE, ADV2, CONC;

FROM SACSYM IMPORT SYMTB;

CONST rcsidi = "$Id: SACSYM2.mi,v 1.3 1992/10/15 16:27:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE STBAL(L,n: LIST): LIST;
(*Symbol tree balance. L is an alphabetical list of n symbol-tree 
nodes (n gt 0), out of which a balanced binary tree S is constructed. *)
VAR   LP: LIST;
      i, m: INTEGER;
      A: ARRAY [0..500] OF LIST;
BEGIN
(*1*) (*initialize.*) 
      IF n > 500 THEN ERROR(severe,"STBAL: array to small.");
                 RETURN(SIL) END;
(*2*) (*fill array.*) LP:=L; i:=-1;
      WHILE LP <> SIL DO i:=i+1; A[i]:=FIRST(LP); 
                      LP:=RED(LP) END;
(*3*) (*built new symbol tree.*)
      m:=STBALS(A,0,INTEGER(n-1)); 
      RETURN(A[m]);
(*4*) END STBAL;


PROCEDURE STBALS(VAR A: ARRAY OF LIST; l, r: INTEGER): INTEGER;
(*Symbol tree balance subroutine. The array A contains symbol-tree
nodes in alphabetical order. The binary tree of the symbols in
A[l..r] is constructed and A[m] is its root. *)
VAR   m, m1, m2: INTEGER;
      L: LIST;
BEGIN
(*1*) (*recursion basis.*) 
      IF l = r THEN m:=l; SFIRST(A[m],SIL); 
                    SRED(RED(A[m]),SIL); RETURN(m) END; 
(*2*) (*recursion.*) m:=(l+r) DIV 2; 
      IF l = m THEN SFIRST(A[m],SIL);
               ELSE m1:=STBALS(A,l,m-1); SFIRST(A[m],A[m1]) END;
      m2:=STBALS(A,m+1,r); SRED(RED(A[m]),A[m2]);
      RETURN(m); 
(*4*) END STBALS;


PROCEDURE STNLST(T: LIST; VAR L,n: LIST);
(*Symbol tree nodes list. T is a non-empty symbol tree.
L is the list of its nodes in alphabetical order of the 
corresponding symbols and n the number of nodes. This algorithm
is normally used for creating the data as required for STBAL. *)
VAR   l, r, lp, rp, S, n1, n2: LIST;
BEGIN
(*1*) (*initialize.*) ADV2(T, l,S,r); n1:=0; n2:=0;
      lp:=SIL; rp:=SIL;
(*2*) (*recursion on sub-trees.*) 
      IF l <> SIL THEN STNLST(l,lp,n1) END;
      IF r <> SIL THEN STNLST(r,rp,n2) END;
(*3*) (*combine lists.*)
      L:=CONC(lp,COMP(T,rp)); n:=n1+1+n2; 
      RETURN;
(*4*) END STNLST;


PROCEDURE SSYTBAL;
(*System symbol tree balance. SYMTB is balanced. *)
VAR   L, n: LIST;
BEGIN
(*1*) (*initialization.*) IF SYMTB = SIL THEN RETURN END; 
(*2*) (*list of nodes.*) STNLST(SYMTB,L,n);
(*3*) (*balance nodes.*) L:=STBAL(L,n);
      IF L <> SIL THEN SYMTB:=L END;
      RETURN;
(*4*) END SSYTBAL;


END SACSYM2.




(* -EOF- *)
