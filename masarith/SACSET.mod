(* ----------------------------------------------------------------------------
 * $Id: SACSET.mi,v 1.3 1992/10/15 16:28:22 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACSET.mi,v $
 * Revision 1.3  1992/10/15  16:28:22  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:20  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:48  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACSET;

(* SAC Set Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, BETA, SIL,
                    COMP, ADV, SRED, FIRST, SFIRST, RED, INV,
                    LENGTH; 

FROM SACLIST IMPORT CONC, ADV2, COMP2, 
                    EQUAL, MEMBER;

CONST rcsidi = "$Id: SACSET.mi,v 1.3 1992/10/15 16:28:22 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


  
PROCEDURE LBIBMS(L: LIST): LIST;
(*List of beta-integers bubble-merge sort.  L is an arbitrary list of
beta-integers, possibly with repetitions.  M is the result of sorting
L into non-decreasing order.  A combination of bubble-sort and merge-
sort is used.  The list L is modified to produce M.*)
VAR  B, BP, C, IL, J1Y, JL, KL, L1, L2, LP, LPP, LPPP, M, ML, NL, QL,
     QLP, RL, TL: LIST;
BEGIN
(*1*) (*short list.*) TL:=10; NL:=LENGTH(L);
      IF NL < TL THEN LBIBS(L); M:=L; RETURN(M); END;
(*2*) (*prepare for merge.*) KL:=0; ML:=1; QL:=NL;
      REPEAT KL:=KL+1; ML:=ML+ML; QL:=QL DIV 2;
             UNTIL QL < TL;
      J1Y:=ML*QL; RL:=NL-J1Y; B:=BETA; LP:=L;
      FOR IL:=1 TO ML DO
          IF IL <= RL THEN QLP:=QL; ELSE QLP:=QL-1; END;
          LPP:=LP;
          FOR JL:=1 TO QLP DO LPP:=RED(LPP); END;
          LPPP:=RED(LPP); SRED(LPP,SIL); LBIBS(LP); B:=COMP(LP,B);
          LP:=LPPP; END;
(*3*) (*merge.*)
      FOR IL:=1 TO KL DO C:=BETA; BP:=B;
          REPEAT ADV2(BP,L1,L2,BP); L1:=LBIM(L1,L2); C:=COMP(L1,C);
                 UNTIL BP = SIL;
          B:=C; END;
      M:=FIRST(B); RETURN(M);
(*6*) END LBIBMS;


PROCEDURE LBIBS(L: LIST);
(*List of beta-integers bubble sort.  L is an arbitrary list of
beta-integers, with possible repetitions.  L is sorted into
non-decreasing order by the bubble-sort method.  The list L, though not
its location, is modified.*)
VAR  ALP, ALPP, LP, LPP, M, MP: LIST;
BEGIN
(*1*) (*trivial case.*)
      IF L = SIL THEN RETURN; END;
(*2*) (*general case.*) M:=BETA;
      REPEAT LP:=L; LPP:=RED(LP); ALP:=FIRST(LP); MP:=BETA;
             WHILE LPP <> M DO ALPP:=FIRST(LPP);
                   IF ALP > ALPP THEN SFIRST(LP,ALPP);
                      SFIRST(LPP,ALP); MP:=LPP; ELSE ALP:=ALPP; END;
                   LP:=LPP; LPP:=RED(LP); END;
             M:=MP;
             UNTIL M = SIL;
      RETURN;
(*5*) END LBIBS;


PROCEDURE LBIM(L1,L2: LIST): LIST;
(*List of beta-integers merge.  L1 and L2 are arbitrary lists of
beta-integers in non-decreasing order.  L is the merge of L1 and L2.
L1 and L2 are modified to produce L.*)
(*goto-free version of LBIM from ,ALDES implementation guide,
by R. Loos. *) 
VAR  AL1, AL2, L, LP, LS, LP1, LP2, LPP1, LPP2: LIST;
BEGIN
(*1*) (*initialize. *) LP1:=L1; LP2:=L2; L:=SIL; LS:=SIL;
(*2*) (*merge l1 and l2. *) 
      WHILE (LP1 <> SIL) AND (LP2 <> SIL) DO 
            ADV(LP1,AL1,LPP1); ADV(LP2,AL2,LPP2);
            IF AL1 < AL2 THEN LP:=LP1; LP1:=LPP1;
                         ELSE LP:=LP2; LP2:=LPP2; END;
            IF LS = SIL THEN LS:=LP; L:=LP;
                        ELSE SRED(LS,LP); LS:=LP; END;
            END;
(*3*) (*finish. *) IF LP2 <> SIL THEN LP1:=LP2; END;
      IF LS = SIL THEN L:=LP;
                  ELSE SRED(LS,LP1); END;
      RETURN(L);
(*4*) END LBIM;                                                 


PROCEDURE SCOMP(AL,L: LIST): LIST;
(*Set composition. a is a beta-integer, L is a set of beta-integers.
LP is the union of SET(a) and L. *)
VAR LP, LS, LPP, BL: LIST;
BEGIN 
(*1*) (* initialize. *) LS:=L; LP:=SIL;
(*2*) (* search for insertion place. *)
      WHILE LS <> SIL DO 
            ADV(LS,BL,LS);
            IF AL = BL THEN LP:=L; RETURN(LP); END;
            IF AL > BL THEN LP:=COMP(BL,LP);
                       ELSE LPP:=COMP2(BL,AL,LP); LP:=INV(LP);
                            SRED(LPP,LS); RETURN(LP); END; 
            END;
(*3*) (*finish. *) LP:=COMP(AL,LP); LP:=INV(LP); RETURN(LP);
      END SCOMP;            


PROCEDURE SDIFF(A,B: LIST): LIST;
(*Set difference.  A and B are sets of beta-integers.  C=A-B.*)
VAR  AL, AP, BL, BP, C, CP: LIST;
BEGIN
(*1*) CP:=BETA; AP:=A; BP:=B;
      WHILE (AP <> SIL) AND (BP <> SIL) DO AL:=FIRST(AP);
            BL:=FIRST(BP);
            IF AL = BL THEN AP:=RED(AP); BP:=RED(BP); ELSE
               IF AL < BL THEN CP:=COMP(AL,CP); AP:=RED(AP); ELSE
                  BP:=RED(BP); END;
               END;
            END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      RETURN(C);
(*4*) END SDIFF;


PROCEDURE SINTER(A,B: LIST): LIST;
(*Set intersection.  A and B are sets of beta-integers.  C is the
intersection of A and B.*)
VAR  AL, AP, BL, BP, C, CP: LIST;
BEGIN
(*1*) CP:=BETA; AP:=A; BP:=B;
      WHILE (AP <> SIL) AND (BP <> SIL) DO AL:=FIRST(AP);
            BL:=FIRST(BP);
            IF AL = BL THEN CP:=COMP(AL,CP); AP:=RED(AP);
               BP:=RED(BP); ELSE
               IF AL < BL THEN AP:=RED(AP); ELSE BP:=RED(BP); END;
               END;
            END;
      C:=INV(CP); RETURN(C);
(*4*) END SINTER;


PROCEDURE SUNION(A,B: LIST): LIST;
(*Set union.  A and B are sets of beta-integers.  C is the union of
A and B.*)
VAR  AL, AP, BL, BP, C, CP: LIST;
BEGIN
(*1*) CP:=BETA; AP:=A; BP:=B;
      WHILE (AP <> SIL) AND (BP <> SIL) DO AL:=FIRST(AP);
            BL:=FIRST(BP);
            IF AL = BL THEN CP:=COMP(AL,CP); AP:=RED(AP);
               BP:=RED(BP); ELSE
               IF AL < BL THEN CP:=COMP(AL,CP); AP:=RED(AP); ELSE
                  CP:=COMP(BL,CP); BP:=RED(BP); END;
               END;
            END;
      IF AP = SIL THEN AP:=BP; END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      RETURN(C);
(*4*) END SUNION;


PROCEDURE USCOMP(AL,L: LIST): LIST;
(*Unordered set composition. a is an object, L is an unordered set.
LP is the union of SET(a) and L. *)
VAR LP: LIST;
BEGIN
(*1*) IF MEMBER(AL,L) = 1 THEN LP:=L; ELSE LP:=COMP(AL,L); END;
(*2*) RETURN(LP);
      END USCOMP;


PROCEDURE USDIFF(A,B: LIST): LIST;
(*Unordered set difference.  A and B are unordered sets.  C is the
difference A-B.*)
VAR  AL, AP, C: LIST;
BEGIN
(*1*) AP:=A; C:=BETA;
      WHILE AP <> SIL DO ADV(AP,AL,AP);
            IF MEMBER(AL,B) = 0 THEN C:=COMP(AL,C); END;
            END;
      RETURN(C);
(*4*) END USDIFF;


PROCEDURE USINT(A,B: LIST): LIST;
(*Unordered set intersection.  A and B are unordered sets.  C is the
intersection of A and B.*)
VAR  AL, AP, C: LIST;
BEGIN
(*1*) AP:=A; C:=BETA;
      WHILE AP <> SIL DO ADV(AP,AL,AP);
            IF MEMBER(AL,B) = 1 THEN C:=COMP(AL,C); END;
            END;
      RETURN(C);
(*4*) END USINT;


PROCEDURE USUN(A,B: LIST): LIST;
(*Unordered set union.  A and B are unordered sets.  C is the union
of A and B.*)
VAR  C, J1Y: LIST;
BEGIN
(*1*) J1Y:=USDIFF(A,B); C:=CONC(J1Y,B); RETURN(C);
(*4*) END USUN;


END SACSET.



(* -EOF- *)
