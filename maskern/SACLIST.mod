(* ----------------------------------------------------------------------------
 * $Id: SACLIST.mi,v 1.4 1992/10/16 13:47:57 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACLIST.mi,v $
 * Revision 1.4  1992/10/16  13:47:57  kredel
 * Errors found by Mocka
 *
 * Revision 1.3  1992/10/15  16:25:03  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:03  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACLIST;

(* List Processing Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT GAMMAINT, MASMAX, MASODD;


FROM MASBIOS IMPORT BKSP, CREAD, CREADB, CWRITE, BLINES,
                    DIGIT, DIBUFF, GWRITE,  
                    MASORD, SWRITE;


FROM MASSTOR IMPORT BETA, SIL, LIST, INV, LIST1,
                    ADV, FIRST, RED, COMP, SFIRST, SRED;

CONST rcsidi = "$Id: SACLIST.mi,v 1.4 1992/10/16 13:47:57 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ADV2(L: LIST; VAR AL,BL,LP: LIST);
(*Advance 2.  L is a list of length two or more.  a=FIRST(L),
b=SECOND(L) and LP=RED(RED(L)).*)
BEGIN
(*1*) ADV(L,AL,LP); ADV(LP,BL,LP); RETURN;
(*4*) END ADV2;


PROCEDURE ADV3(L: LIST; VAR AL1,AL2,AL3,LP: LIST);
(*Advance 3.  L is a list of length 3 or more.  a1, a2 and a3 are
the first three elements of L.  LP is the third reductum of L.*)
BEGIN
(*1*) ADV2(L,AL1,AL2,LP); ADV(LP,AL3,LP); RETURN;
(*4*) END ADV3;


PROCEDURE ADV4(L: LIST; VAR AL1,AL2,AL3,AL4,LP: LIST);
(*Advance 4.  L is a list of length 4 or more.  a1, a2, a3, and a4
are the first 4 elements of L.  LP is the fourth reductum of L.*)
BEGIN
(*1*) ADV(L,AL1,LP); ADV(LP,AL2,LP); ADV(LP,AL3,LP); ADV(LP,AL4,LP);
      RETURN;
(*4*) END ADV4;


PROCEDURE AREAD(): LIST;
(*Atom read.  An atom A is read from the input stream.  Any preceding
blanks are skipped.*)
VAR  A, C, I, J1Y, S: LIST;
BEGIN
(*1*) (*skip blanks and read sign, if any.*) S:=1; C:=CREADB();
      IF C = MASORD("+") THEN C:=CREAD(); ELSE
         IF C = MASORD("-") THEN C:=CREAD(); S:=-1; ELSE
            IF NOT DIGIT(C) THEN 
               (*go to 3*) 
               (*3*) (*error.*) SWRITE("ERROR FOUND BY AREAD.");
                     DIBUFF;
                     RETURN(0);
               END;
            END;
         END;
(*2*) (*read digits and convert.*) A:=0; I:=BETA DIV 10;
      REPEAT IF A > I THEN
                (*error.*) SWRITE("ERROR FOUND BY AREAD.");
                DIBUFF;
                RETURN(0);
                END;
             J1Y:=10*A; A:=J1Y+C;
             IF A >= BETA THEN 
                (*error.*) SWRITE("ERROR FOUND BY AREAD.");
                DIBUFF;
                RETURN(0);
                END;
             C:=CREAD();
             UNTIL NOT DIGIT(C);
      A:=S*A; BKSP; RETURN(A);
(*6*) END AREAD;


PROCEDURE AWRITE(A: LIST);
(*Atom write.  The atom A is written in the output stream.*)
VAR  D: ARRAY[1..20] OF LIST; 
     AP, Q, J1Y: LIST;
     N: INTEGER;
BEGIN
(*5*) (*write minus sign.*)
      IF A < 0 THEN AP:=-A; SWRITE("-"); ELSE AP:=A; END;
(*2*) (*convert to decimal.*) N:=0;
      REPEAT Q:=AP DIV 10; N:=N+1; J1Y:=10*Q; D[N]:=AP-J1Y; AP:=Q;
             UNTIL AP = 0;
(*3*) (*write digits.*)
      REPEAT CWRITE(D[N]); N:=N-1;
             UNTIL N = 0;
      RETURN;
(*6*) END AWRITE;


PROCEDURE CCONC(L1,L2: LIST): LIST;
(*Constructive concatenation.  L1 and L2 are lists.  L is the
concatenation of L1 and L2.  The list L is constructed.*)
VAR  L, LP1: LIST;
BEGIN
(*1*) (*is l1 or l2 null.*) L:=L2;
      IF L1 = SIL THEN RETURN(L); END;
      L:=L1;
      IF L2 = SIL THEN RETURN(L); END;
(*2*) (*concatenate copy of l1.*) LP1:=CINV(L1); L:=INV(LP1);
      SRED(LP1,L2); RETURN(L);
(*5*) END CCONC;


PROCEDURE CINV(L: LIST): LIST;
(*Constructive inverse.  L is a list.  M=INV(L).  M is constructed
using comp.*)
VAR  AL, LP, M: LIST;
BEGIN
(*1*) M:=BETA; LP:=L;
      WHILE LP <> SIL DO ADV(LP,AL,LP); M:=COMP(AL,M); END;
      RETURN(M);
(*4*) END CINV;


PROCEDURE CLOUT(L: LIST);
(*Character list out.  The input is a character list L=(C(1),C(2),...,
C(n)).  The C(i) are sequentially transmitted to the output stream 
using CWRITE.*)
VAR  C, LP: LIST;
BEGIN
(*1*) LP:=L;
      WHILE LP <> SIL DO ADV(LP,C,LP); 
            IF C < SIL THEN CWRITE(C) END END;
      RETURN;
(*4*) END CLOUT;


PROCEDURE COMP2(AL,BL,L: LIST): LIST;
(*Composition 2.  a and b are objects.  L is a list.
M=COMP(a,COMP(b,L)).*)
VAR  J1Y, M: LIST;
BEGIN
(*1*) J1Y:=COMP(BL,L); M:=COMP(AL,J1Y); RETURN(M);
(*4*) END COMP2;


PROCEDURE COMP3(AL1,AL2,AL3,L: LIST): LIST;
(*Composition 3.  a1, a2 and a3 are objects.  L is a list.
M=COMP(a1,COMP(a2,COMP(a3,L))).*)
VAR  J1Y, M: LIST;
BEGIN
(*1*) J1Y:=COMP(AL3,L); J1Y:=COMP(AL2,J1Y); M:=COMP(AL1,J1Y); RETURN(M);
(*4*) END COMP3;


PROCEDURE COMP4(AL1,AL2,AL3,AL4,L: LIST): LIST;
(*Composition 4.  a1, a2, a3 and a4 are objects.  L is a list.
M=COMP(a1,COMP(a2,COMP(a3,COMP(a4,l)))).*)
VAR  J1Y, M: LIST;
BEGIN
(*1*) J1Y:=COMP(AL4,L); J1Y:=COMP(AL3,J1Y); J1Y:=COMP(AL2,J1Y);
      M:=COMP(AL1,J1Y); RETURN(M);
(*4*) END COMP4;


PROCEDURE CONC(L1,L2: LIST): LIST;
(*Concatenation.  L1 and L2 are lists.  L=CONC(L1,L2).  The list L1 is
modified.*)
VAR  L, LP: LIST;
BEGIN
(*1*) (*l1 null.*) L:=L2;
      IF L1 = SIL THEN RETURN(L); END;
(*2*) (*l2 null.*) L:=L1;
      IF L2 = SIL THEN RETURN(L); END;
(*3*) (*l1 and l2 non-null.*) LP:=LAST(L1); SRED(LP,L2); RETURN(L);
(*6*) END CONC;


PROCEDURE EQUAL(AL,BL: LIST): LIST;
(*Equal.  a and b are objects.  t=1 if a and b are equal and
otherwise t=0.*)
VAR  AL1, ALP, BL1, BLP, TL: LIST;
BEGIN
(*1*) (*identical atoms or list representations.*) TL:=0;
      IF AL = BL THEN TL:=1; RETURN(TL); END;
(*2*) (*al or bl is an atom.*)
      IF (AL < BETA) OR (BL < BETA) THEN RETURN(TL); END;
(*3*) (*recursion.*) ALP:=AL; BLP:=BL;
      WHILE (ALP <> SIL) AND (BLP <> SIL) DO ADV(ALP,AL1,ALP);
            ADV(BLP,BL1,BLP);
            IF EQUAL(AL1,BL1) = 0 THEN RETURN(TL); END;
            IF ALP = BLP THEN TL:=1; RETURN(TL); END;
            END;
      RETURN(TL);
(*6*) END EQUAL;


PROCEDURE EXTENT(AL: LIST): LIST;
(*Extent.  a is an object.  n=EXTENT(a).*)
VAR  AL1, ALP, J1Y, NL: LIST;
BEGIN
(*1*) (*al an atom.*) NL:=0;
      IF AL < BETA THEN RETURN(NL); END;
(*2*) (*al a list.*) ALP:=AL;
      WHILE ALP <> SIL DO ADV(ALP,AL1,ALP); J1Y:=EXTENT(AL1);
            J1Y:=NL+J1Y; NL:=J1Y+1; END;
      RETURN(NL);
(*5*) END EXTENT;


PROCEDURE FIRST2(L: LIST; VAR AL,BL: LIST);
(*First 2.  L is a list of length 2 or more.  a=FIRST(L) and
b=SECOND(L).*)
VAR  LP: LIST;
BEGIN
(*1*) ADV(L,AL,LP); BL:=FIRST(LP); RETURN;
(*4*) END FIRST2;


PROCEDURE FIRST3(L: LIST; VAR AL1,AL2,AL3: LIST);
(*First 3.  L is a list of length 3 or more.  a1=FIRST(L),
a2=SECOND(L) and a3=THIRD(L).*)
VAR  LP: LIST;
BEGIN
(*1*) ADV2(L,AL1,AL2,LP); AL3:=FIRST(LP); RETURN;
(*4*) END FIRST3;


PROCEDURE FIRST4(L: LIST; VAR AL1,AL2,AL3,AL4: LIST);
(*First 4.  L is a list of length 4 or more.  a1=FIRST(L),
a2=SECOND(L), a3=THIRD(L) and a4=FOURTH(L).*)
VAR  LP: LIST;
BEGIN
(*1*) ADV(L,AL1,LP); ADV(LP,AL2,LP); ADV(LP,AL3,LP); AL4:=FIRST(LP);
      RETURN;
(*4*) END FIRST4;


PROCEDURE FOURTH(L: LIST): LIST;
(*Fourth.  L is a list of length 4 or more.  a is the fourth element
of L.*)
VAR  AL, J1Y: LIST;
BEGIN
(*1*) J1Y:=RED3(L); AL:=FIRST(J1Y); RETURN(AL);
(*4*) END FOURTH;


PROCEDURE LAST(L: LIST): LIST;
(*Last.  L is a non-null list.  LP is the location of the last cell
of L.*)
VAR  LP, LPP: LIST;
BEGIN
(*1*) LP:=L; LPP:=RED(LP);
      WHILE LPP <> SIL DO LP:=LPP; LPP:=RED(LP); END;
      RETURN(LP);
(*4*) END LAST; 


PROCEDURE LEINST(A,IL,AL: LIST): LIST;
(*List element insertion.  A is the list (a(1), ...,a(n)) of objects.
i is a beta-integer, 0 le i le n.  a is an object.  If i=0, then
L=(a,a(1), ...,a(n)).  If i=n, then L=(a(1), ...,a(n),a).
otherwise, L=(a(1), ...,a(i),a,a(i+1), ...,a(n)).  A is modified.*)
VAR  AP, APP, JL, L: LIST;
BEGIN
(*1*) (*il=0.*)
      IF IL = 0 THEN L:=COMP(AL,A); RETURN(L); END;
(*2*) (*il gt 0.*) L:=A; AP:=A;
      FOR JL:=2 TO IL DO AP:=RED(AP); END;
      APP:=RED(AP); APP:=COMP(AL,APP); SRED(AP,APP); RETURN(L);
(*5*) END LEINST;


PROCEDURE LELT(A,IL: LIST): LIST;
(*List element.  A is a list.  1 le i le LENGTH(A).  a is the i-th
element of A.*)
VAR  AL, AP, JL: LIST;
BEGIN
(*1*) AP:=A;
      FOR JL:=1 TO IL-1 DO AP:=RED(AP); END;
      AL:=FIRST(AP); RETURN(AL);
(*4*) END LELT;


PROCEDURE LEROT(L,IL,JL: LIST): LIST;
(*List element rotation.  L is a list (a(1), ...,a(n)) of objects, n
gt 0.  i and j, 1 le i le j le n, are beta-integers.  If i=j
then M=L.  Otherwise M=(a(1), ...,a(i-1),a(j),a(i), ...,a(j-1),
a(j+1), ...,a(n)).  L is modified.*)
VAR  AL, BL, KL, LP, LPP, M: LIST;
BEGIN
(*1*) (*il=jl.*) M:=L;
      IF IL = JL THEN RETURN(M); END;
(*2*) (*il lt jl.*) LP:=L;
      FOR KL:=1 TO IL-1 DO LP:=RED(LP); END;
      ADV(LP,AL,LPP);
      FOR KL:=IL TO JL-1 DO BL:=FIRST(LPP); SFIRST(LPP,AL); AL:=BL;
          LPP:=RED(LPP); END;
      SFIRST(LP,AL); RETURN(M);
(*5*) END LEROT;


PROCEDURE LINS(AL,L: LIST);
(*List insertion.  L is a non-null list (a(1), ...,a(n)).  a is an
object.  a is inserted in L after a(1) (suffixed to L if n=1),
producing a modified list L=(a(1),a,a(2), ...,a(n)).*)
VAR  A, J1Y: LIST;
BEGIN
(*1*) J1Y:=RED(L); A:=COMP(AL,J1Y); SRED(L,A); RETURN;
(*4*) END LINS;


PROCEDURE LINSRT(AL,A: LIST): LIST;
(*List insertion.  A is a list (a(1), ...,a(n)) of beta-integers,
n ge 0, with a(1) lt a(2) lt  ...lt a(n).  If n=0 then B=(a).
If a lt a(1) then B=(a,a(1), ...,a(n)).  If a ge a(n) then
B=(a(1), ...,a(n),a).  Otherwise B=(a(1), ...,a(i),a,a(i+1),
 ...,a(n)) where a(i) le a lt a(i+1).  The list A is modified
to produce B.*)
VAR  AP, APP, AS, B: LIST;
BEGIN
(*1*) (*nl=0.*)
      IF A = SIL THEN B:=LIST1(AL); RETURN(B); END;
(*2*) (*al lt al1.*)
      IF AL < FIRST(A) THEN B:=COMP(AL,A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; APP:=RED(AP);
      WHILE (APP <> SIL) AND (AL >= FIRST(APP)) DO AP:=APP;
            APP:=RED(AP); END;
      AS:=COMP(AL,APP); SRED(AP,AS); B:=A; RETURN(B);
(*6*) END LINSRT;


PROCEDURE LIST10(AL1,AL2,AL3,AL4,AL5,AL6,AL7,AL8,AL9,AL10: LIST): LIST;
(*List, 10 elements.  a1, a2, a3, a4, a5, a6, a7, a8, a9 and a10 are
objects.  L is the list (a1,a2,a3,a4,a5,a6,a7,a8,a9,a10).*)
VAR  J1Y, L: LIST;
BEGIN
(*1*) J1Y:=COMP(AL10,BETA); J1Y:=COMP(AL9,J1Y); J1Y:=COMP(AL8,J1Y);
      J1Y:=COMP(AL7,J1Y); J1Y:=COMP(AL6,J1Y); J1Y:=COMP(AL5,J1Y);
      J1Y:=COMP(AL4,J1Y); J1Y:=COMP(AL3,J1Y); J1Y:=COMP(AL2,J1Y);
      L:=COMP(AL1,J1Y); RETURN(L);
(*4*) END LIST10;


PROCEDURE LIST2(AL,BL: LIST): LIST;
(*List, 2 elements.  a and b are objects.  L is the list (a,b).*)
VAR  J1Y, L: LIST;
BEGIN
(*1*) J1Y:=COMP(BL,BETA); L:=COMP(AL,J1Y); RETURN(L);
(*4*) END LIST2;


PROCEDURE LIST3(AL1,AL2,AL3: LIST): LIST;
(*List, 3 elements.  a1, a2 and a3 are objects.  L=(a1,a2,a3).*)
VAR  J1Y, L: LIST;
BEGIN
(*1*) J1Y:=COMP(AL3,BETA); J1Y:=COMP(AL2,J1Y); L:=COMP(AL1,J1Y);
      RETURN(L);
(*4*) END LIST3;


PROCEDURE LIST4(AL1,AL2,AL3,AL4: LIST): LIST;
(*List, 4 elements.  a1, a2, a3 and a4 are objects.  L is the list
(a1,a2,a3,a4).*)
VAR  J1Y, L: LIST;
BEGIN
(*1*) J1Y:=COMP(AL4,BETA); J1Y:=COMP(AL3,J1Y); J1Y:=COMP(AL2,J1Y);
      L:=COMP(AL1,J1Y); RETURN(L);
(*4*) END LIST4;


PROCEDURE LIST5(AL1,AL2,AL3,AL4,AL5: LIST): LIST;
(*List, 5 elements.  a1,a2,a3,a4 and a5 are objects.  L is the list
(a1,a2,a3,a4,a5).*)
VAR  J1Y, L: LIST;
BEGIN
(*1*) J1Y:=COMP(AL5,BETA); J1Y:=COMP(AL4,J1Y); J1Y:=COMP(AL3,J1Y);
      J1Y:=COMP(AL2,J1Y); L:=COMP(AL1,J1Y); RETURN(L);
(*4*) END LIST5;


PROCEDURE LREAD(): LIST;
(*List read.  The list L is read from the input stream.  Any preceding
blanks are skipped.*)
VAR  C, IDUM, L, L1: LIST;
BEGIN
(*1*) (*read list elements.*) L:=BETA; C:=CREADB();
      IF C <> MASORD("(") THEN 
         SWRITE("ERROR FOUND BY LREAD."); DIBUFF;
         RETURN(L); END;
(*2*) LOOP C:=CREADB();
           IF C = MASORD(")") THEN L:=INV(L); RETURN(L); ELSE
              IF C = MASORD("(") THEN BKSP; L1:=LREAD(); ELSE
                 IF    (C = MASORD("+")) 
                    OR (C = MASORD("-")) 
                    OR DIGIT(C) 
                    THEN BKSP; L1:=AREAD(); 
                    ELSE SWRITE("ERROR FOUND BY LREAD."); DIBUFF;
                         L:=INV(L); RETURN(L) END;
                 END;
              END;
           L:=COMP(L1,L); C:=CREADB();
           IF C = MASORD(")") THEN BKSP; ELSE
              IF C <> MASORD(",") THEN  
                 SWRITE("ERROR FOUND BY LREAD."); DIBUFF;
                 L:=INV(L); RETURN(L) END;
              END;
           END 
(*5*) END LREAD;


PROCEDURE LSRCH(AL,A: LIST): LIST;
(*List search.  A is a list of beta-integers, (a(1), ...,a(n)),
n ge 0.  If there is a j such that a=a(j) then i is the least
such j.  Otherwise i=0.*)
VAR  AL1, AP, IL: LIST;
BEGIN
(*1*) AP:=A; IL:=1;
      WHILE AP <> SIL DO ADV(AP,AL1,AP);
            IF AL = AL1 THEN RETURN(IL); END;
            IL:=IL+1; END;
      IL:=0; RETURN(IL);
(*4*) END LSRCH;


PROCEDURE LWRITE(L: LIST);
(*List write.  The input list L is written in the output stream.*)
VAR  L1, LP: LIST;
BEGIN
(*1*) (*initialize.*) SWRITE("("); LP:=L;
(*2*) (*write list elements.*)
      WHILE LP <> SIL DO ADV(LP,L1,LP);
            IF L1 < BETA THEN AWRITE(L1); ELSE LWRITE(L1); END;
            IF LP <> BETA THEN SWRITE(","); END;
            END;
(*3*) (*finish.*) SWRITE(")"); RETURN;
(*6*) END LWRITE;


PROCEDURE MEMBER(AL,L: LIST): LIST;
(*Membership test.  a is an object, L a list.  t=1 if a is a
member of L and otherwise t=0.*)
VAR  AL1, LP, TL: LIST;
BEGIN
(*1*) TL:=0; LP:=L;
      WHILE LP <> SIL DO ADV(LP,AL1,LP); TL:=EQUAL(AL,AL1);
            IF TL = 1 THEN RETURN(TL); END;
            END;
      RETURN(TL);
(*4*) END MEMBER;


PROCEDURE ORDER(AL: LIST): LIST;
(*Order.  a is an object.  n=ORDER(a).*)
VAR  AL1, ALP, J1Y, NL: LIST;
BEGIN
(*1*) (*al an atom.*) NL:=0;
      IF AL < BETA THEN RETURN(NL); END;
(*2*) (*al a list.*) ALP:=AL;
      WHILE ALP <> SIL DO ADV(ALP,AL1,ALP); J1Y:=ORDER(AL1);
            NL:=MASMAX(NL,J1Y); END;
      NL:=NL+1; RETURN(NL);
(*5*) END ORDER;


PROCEDURE OREAD(): LIST;
(*Object read.  The object B is read from the input stream.  Any
preceding blanks are skipped.*)
VAR  B, C, IDUM: LIST;
BEGIN
(*1*) (*read list or atom.*) C:=CREADB(); BKSP;
      IF C = MASORD("(") THEN B:=LREAD(); ELSE B:=AREAD(); END;
      RETURN(B);
(*4*) END OREAD;


PROCEDURE OWRITE(B: LIST);
(*Object write.  The input object B is written in the output stream.*)
BEGIN
(*1*) IF B < BETA THEN AWRITE(B); ELSE LWRITE(B); END;
      RETURN;
(*4*) END OWRITE;


PROCEDURE PAIR(A,B: LIST): LIST;
(*Pair.  A=(a(1), ...,a(m)) and B=(b(1), ...,b(n)) are lists with
m and n non-negative.  C is the list (a(1),b(1), ...,a(r),b(r))
where r=MIN(m,n).*)
VAR  AL, AP, BL, BP, C: LIST;
BEGIN
(*1*) AP:=A; BP:=B; C:=BETA;
      WHILE (AP <> SIL) AND (BP <> SIL) DO ADV(AP,AL,AP);
            ADV(BP,BL,BP); C:=COMP2(BL,AL,C); END;
      C:=INV(C); RETURN(C);
(*4*) END PAIR;


PROCEDURE REDUCT(A,IL: LIST): LIST;
(*Reductum.  A is a list.  i is a non-negative beta-integer not less
than LENGTH(A).  B=A, if i=0.  Otherwise, B is the i-th reductum of
A.*)
VAR  B, JL: LIST;
BEGIN
(*1*) B:=A;
      FOR JL:=1 TO IL DO B:=RED(B); END;
      RETURN(B);
(*4*) END REDUCT;


PROCEDURE RED2(L: LIST): LIST;
(*Reductum 2.  L is a list of length 2 or more.  LP=RED(RED(L)).*)
VAR  J1Y, LP: LIST;
BEGIN
(*1*) J1Y:=RED(L); LP:=RED(J1Y); RETURN(LP);
(*4*) END RED2;


PROCEDURE RED3(L: LIST): LIST;
(*Reductum 3.  L is a list of length 3 or more.  M is the third
reductum of L.*)
VAR  J1Y, M: LIST;
BEGIN
(*1*) J1Y:=RED2(L); M:=RED(J1Y); RETURN(M);
(*4*) END RED3;


PROCEDURE RED4(L: LIST): LIST;
(*Reductum 4.  L is a list of length 4 or more.  M is the fourth
reductum of L.*)
VAR  J1Y, M: LIST;
BEGIN
(*1*) J1Y:=RED(L); J1Y:=RED(J1Y); J1Y:=RED(J1Y); M:=RED(J1Y); RETURN(M);
(*4*) END RED4;


PROCEDURE SECOND(L: LIST): LIST;
(*Second.  L is a list of length 2 or more.  a is the second element
of L.*)
VAR  AL, J1Y: LIST;
BEGIN
(*1*) J1Y:=RED(L); AL:=FIRST(J1Y); RETURN(AL);
(*4*) END SECOND;


PROCEDURE SLELT(A,IL,AL: LIST);
(*Set list element.  A is a list.  1 le i le LENGTH(A).  The i-th
element of A is changed to a.*)
VAR  AP, JL: LIST;
BEGIN
(*1*) AP:=A;
      FOR JL:=1 TO IL-1 DO AP:=RED(AP); END;
      SFIRST(AP,AL); RETURN;
(*4*) END SLELT;


PROCEDURE SUFFIX(L,BL: LIST): LIST;
(*Suffix.  L is a list (a(1), ..., a(n)), n non-negative.  b is an
object.  LP=(a(1), ..., a(n),b).  L is modified.*)
VAR  J1Y, LP: LIST;
BEGIN
(*1*) J1Y:=LIST1(BL); LP:=CONC(L,J1Y); RETURN(LP);
(*4*) END SUFFIX;


PROCEDURE THIRD(L: LIST): LIST;
(*Third.  L is a list of length 3 or more.  a is the third element
of L.*)
VAR  AL, J1Y: LIST;
BEGIN
(*1*) J1Y:=RED2(L); AL:=FIRST(J1Y); RETURN(AL);
(*4*) END THIRD;


END SACLIST.


(* -EOF- *)
