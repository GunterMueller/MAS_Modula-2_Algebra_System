(* ----------------------------------------------------------------------------
 * $Id: MASSYM.mi,v 1.4 1996/06/19 20:59:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSYM.mi,v $
 * Revision 1.4  1996/06/19 20:59:57  kredel
 * Fixed recursion termination error.
 *
 * Revision 1.3  1992/10/15 16:27:53  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:32  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:28  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSYM;

(* MAS Symbol Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT SIL, LIST, BETA, 
                    LIST1, FIRST, COMP, INV, ADV;

FROM MASBIOS IMPORT BLINES, DIBUFF, BKSP, CREAD, CREADB, DIGIT, 
                    LISTS, LETTER, MASORD, SWRITE, CWRITE;

FROM SACLIST IMPORT AREAD, AWRITE, FIRST2, LIST2, CONC, CINV, COMP2;

FROM MASSYM2 (*SACSYM*) IMPORT SYMBOL, ENTER, EXPLOD, SREAD, SYWRIT, SUBLIS;

CONST rcsidi = "$Id: MASSYM.mi,v 1.4 1996/06/19 20:59:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE ATOM(X: LIST): BOOLEAN;
(*Atom. Test if X is an atom. *)
BEGIN
(*1*) (*test for beta integer. *) 
      IF (-BETA < X) AND (X < BETA) THEN RETURN(TRUE) END;
      RETURN(FALSE);
(*2*) END ATOM;


PROCEDURE ELEMP(X: LIST): BOOLEAN;
(*Elementary Pointer. Test if X is an elementary SAC-2 structure. *)
VAR   Y: LIST;
BEGIN
(*1*) (*atoms or () as first elements. *) Y:=X;
      WHILE Y > BETA DO Y:=FIRST(Y) END;
      IF (-BETA < Y) AND (Y <= BETA) THEN RETURN(TRUE) END;
      RETURN(FALSE);
(*2*) END ELEMP;


PROCEDURE MEMQ(AL,L: LIST): BOOLEAN;
(*Membership test equal pointers.  a is an object, L a list. t=1 if 
the pointer or atom a occurs in L and otherwise t=0.*)
VAR   AL1, LP: LIST;
BEGIN
(*1*) LP:=L;
      WHILE LP <> SIL DO ADV(LP,AL1,LP); 
            IF AL = AL1 THEN RETURN(TRUE) END;
            END;
      RETURN(FALSE);
(*4*) END MEMQ;


PROCEDURE OCCURQ(AL,L: LIST): BOOLEAN;
(*Occurs test equal pointers. a and L are objects. t=TRUE if 
the pointer or atom a occurs in L and otherwise t=FALSE. *)
VAR   C1, C2: LIST;
BEGIN
(*1*) (*basis.*) 
      IF AL = L THEN RETURN(TRUE) END;
      IF ATOM(L) OR SYMBOL(L) OR (L = SIL) THEN RETURN(FALSE); END;
(*2*) (*recursion.*) ADV(L, C1,C2); 
      IF OCCURQ(AL,C1) THEN RETURN(TRUE) END; 
      IF OCCURQ(AL,C2) THEN RETURN(TRUE) END; 
      RETURN(FALSE); 
(*5*) END OCCURQ;


PROCEDURE UREAD(): LIST;
(*Universal read. The next atom, symbol, string or list over atoms, 
strings and symbols is read and stored under L. Blanks may occur 
anywhere. Elements of a list may or may not be separated by a comma.*)
VAR   C, J1Y, L: LIST;
BEGIN
(*1*) (*BRANCH ON C.*) L:=SIL; C:=CREADB();
      IF DIGIT(C) OR (C = MASORD("-")) OR (C = MASORD("+")) THEN 
         BKSP; L:=AREAD(); RETURN(L) END;
      IF LETTER(C) THEN BKSP; L:=SREAD(); RETURN(L) END;
      IF C = MASORD('"') THEN 
         LOOP C:=CREAD();
              IF C = MASORD('"') THEN C:=CREAD();
                 IF C <> MASORD('"') THEN BKSP; EXIT END; 
                 END;
              L:=COMP(C,L);
              END;
         L:=INV(L); RETURN(L) END;
      IF C <> MASORD("(") THEN
         SWRITE("Atoms, strings, symbols, or lists expected by UREAD, ");
         CWRITE(C); SWRITE(" found."); DIBUFF; RETURN(0) END;
(*2*) (*READ LIST.*) C:=CREADB();
      IF C = MASORD(")") THEN RETURN(L); END;
      BKSP;
      LOOP J1Y:=UREAD(); L:=COMP(J1Y,L); C:=CREADB();
           IF C = MASORD(")") THEN L:=INV(L); RETURN(L) END; 
           IF C <> MASORD(",") THEN BKSP; END;
           END;
(*5*) END UREAD;


PROCEDURE UWRITE(L: LIST);
(*Universal write. L is an atom, symbol or a list over
atoms and symbols. L is written in the output stream,
followed by blines. *)
BEGIN
(*1*) UWRIT1(L); BLINES(0);
(*4*) END UWRITE;


PROCEDURE UWRIT1(L: LIST);
(*Universal write, 1. subalgorithm. L is an atom, a symbol
or a list over atoms or symbols. L is written in the output
stream. *)
VAR  AL, LP: LIST;
BEGIN
(*1*) (*ATOM OR SYMBOL.*)
      IF L < BETA THEN AWRITE(L); RETURN END; 
      IF SYMBOL(L) THEN SYWRIT(L); RETURN END; 
(*2*) (*LIST.*) SWRITE("("); LP:=L;
      WHILE LP <> SIL DO ADV(LP, AL,LP); UWRIT1(AL);
            IF AL = NOSHOW THEN SWRITE(" ..."); LP:=SIL END; 
            IF LP <> SIL THEN SWRITE(" ") END 
            END;
      SWRITE(")"); 
(*5*) END UWRIT1;


PROCEDURE UNIFY(A,B: LIST; VAR S: LIST): BOOLEAN;
(*Unification. A and B are objects. If there exists a 
most general unificator of A and B, then S is the list of 
substitutions. In this case TRUE is returned. If no unificator
exists, then FALSE is returned and S is undefined. *)
VAR   C1, C2, D1, D2: LIST;
BEGIN
(*1*) (*basis.*) IF A = B THEN RETURN(TRUE) END;
(*2*) IF SYMBOL(A) THEN 
         IF OCCURQ(A,B) THEN RETURN(FALSE) END;
         S:=COMP2(A,B,S); RETURN(TRUE);
         END;      
      IF SYMBOL(B) THEN 
         IF OCCURQ(B,A) THEN RETURN(FALSE) END;
         S:=COMP2(B,A,S); RETURN(TRUE);
         END;
      IF ATOM(A) OR ATOM(B) THEN RETURN(FALSE) END;
      IF (A = SIL) OR (B = SIL) THEN RETURN(FALSE) END;
(*3*) (*recursion.*) ADV(A, C1,C2); ADV(B, D1,D2); 
      IF C1 <> D1 THEN RETURN(FALSE) END; 
      WHILE (C2 <> SIL) AND (D2 <> SIL) DO 
            ADV(C2, C1,C2); ADV(D2, D1,D2);
            C1:=SUBLIS(S,C1); D1:=SUBLIS(S,D1);
            IF NOT UNIFY(C1,D1, S) THEN RETURN(FALSE) END; 
            END;
      IF (C2 <> SIL) OR (D2 <> SIL) THEN RETURN(FALSE) END;
      RETURN(TRUE);
(*5*) END UNIFY;


PROCEDURE GENARRAY(A: LIST): LIST;
(*Generate array reference symbol. S is a generated symbol. *)
VAR   J, Q, S, SP, n, I, i: LIST;
BEGIN
(*1*) (*initialize.*) S:=SIL; FIRST2(A,n,I);
      I:=CINV(I); 
(*2*) (*create character list.*) 
      WHILE I <> SIL DO ADV(I,i,I);
               IF i >= 0 THEN Q:=i ELSE Q:=-i END;
               REPEAT J:=Q MOD 10; S:=COMP(J,S); Q:=Q DIV 10;
                      UNTIL Q = 0;
               IF i < 0 THEN S:=COMP(MASORD("m"),S) END;
               IF I <> SIL THEN S:=COMP(MASORD("d"),S); END;
            END;
(*3*) (*enter in symbol table.*) SP:=EXPLOD(n);
      S:=CONC(SP,S); S:=ENTER(S);
(*6*) RETURN(S); END GENARRAY;


PROCEDURE GENINDEX(A: LIST): LIST;
(*Generate index set. I is an index set. *)
VAR   S, SP, i, j, I, s: LIST;
BEGIN
(*1*) (*initialize.*) S:=SIL;
      IF A = SIL THEN RETURN(LIST1(SIL)) END;
(*2*) ADV(A,i,A); j:=-1; SP:=GENINDEX(A);
      WHILE j < i DO j:=j+1; I:=SP;
            WHILE I <> SIL DO ADV(I,s,I); 
                  s:=COMP(j,s); S:=COMP(s,S);
                  END;
            END;
      S:=INV(S);
(*6*) RETURN(S); END GENINDEX;


PROCEDURE ARRAYDEC(A: LIST): LIST;
(*Generate array name declarations. A is an array reference. *)
VAR   S, SP, s, n, I: LIST;
BEGIN
(*1*) (*initialize.*) FIRST2(A,n,I); S:=SIL;
      SP:=GENINDEX(I); 
(*2*) WHILE SP <> SIL DO ADV(SP,s,SP); 
            s:=LIST2(n,s); s:=GENARRAY(s);
            S:=COMP(s,S);
            END;
      S:=INV(S);
(*6*) RETURN(S); END ARRAYDEC;


BEGIN 
  
    NOSHOW:=ENTER(LISTS("NOSHOW"));

END MASSYM.


(* -EOF- *)
