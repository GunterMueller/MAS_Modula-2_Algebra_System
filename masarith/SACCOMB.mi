(* ----------------------------------------------------------------------------
 * $Id: SACCOMB.mi,v 1.3 1992/10/15 16:28:16 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACCOMB.mi,v $
 * Revision 1.3  1992/10/15  16:28:16  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:08  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:36  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACCOMB;

(* SAC Combinatorical System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT GAMMAINT, MASMIN, MASMAX, MASQREM, MASREM;

FROM MASSTOR IMPORT LIST, BETA, SIL, SFIRST, SRED,
                    FIRST, RED, ADV, LIST1, LENGTH, COMP, INV;

FROM SACLIST IMPORT SECOND, LSRCH, LINSRT, LELT, SLELT;

FROM SACSET IMPORT SUNION, SDIFF, LBIBMS;

FROM SACM IMPORT MDRAN;

FROM SACI IMPORT ISUM, IDPR, IDQ, IMP2;   

VAR BETA1: LIST;

CONST rcsidi = "$Id: SACCOMB.mi,v 1.3 1992/10/15 16:28:16 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ASSPR(A: LIST;  VAR PL,ML: LIST); 
(*Assignment problem.  A is a square matrix of beta-integers, say
n by n.  p is an n-permutation for which the sum on i of
A(i,p(i)) is maximal, and m is this maximal sum.  All matrix
elements A(i,j) must be less than beta in absolute value.*)
VAR  A1, AL11, AP, I, IL, IP, J, J1Y, JL, S, S1, SP, U, UL1, US, V,
     VL1, VS: LIST; 
BEGIN
(*1*) (*compute initial u and v.*) AP:=A; U:=BETA; V:=BETA; 
      REPEAT ADV(AP, A1,AP); ADV(A1, UL1,A1); 
             WHILE A1 <> SIL DO ADV(A1, AL11,A1); 
                   UL1:=MASMAX(UL1,AL11); END; 
             U:=COMP(UL1,U); V:=COMP(0,V); 
             UNTIL AP = SIL; 
      U:=INV(U); V:=INV(V); 
LOOP
(*2*) (*compute s.*) S:=BETA; AP:=A; US:=U; 
      REPEAT S1:=BETA; ADV(AP, A1,AP); ADV(US, UL1,US); VS:=V; JL:=1; 
             REPEAT ADV(VS, VL1,VS); ADV(A1, AL11,A1); 
                    IF UL1+VL1 = AL11 THEN S1:=COMP(JL,S1); END; 
                    JL:=JL+1; 
                    UNTIL VS = SIL; 
             S1:=INV(S1); S:=COMP(S1,S); 
             UNTIL AP = SIL; 
      S:=INV(S); 
(*3*) (*solve sdr problem.*) SDR(S, PL,I); 
(*4*) (*solution found, compute maximum.*) 
      IF PL <> SIL THEN ML:=0; US:=U; VS:=V; 
         REPEAT ADV(US, UL1,US); ADV(VS, VL1,VS); J1Y:=ML+UL1; 
                ML:=J1Y+VL1; 
                UNTIL US = SIL; 
         RETURN; END; 
(*5*) (*no solution, compute union.*) J:=BETA; SP:=S; IP:=I; IL:=1; 
      REPEAT ADV(SP, S1,SP); 
             IF (IP <> SIL) AND (FIRST(IP) = IL) THEN
                IP:=RED(IP); J:=SUNION(J,S1); END; 
             IL:=IL+1; 
             UNTIL IP = SIL; 
(*6*) (*compute new u and v.*) US:=U; IL:=1; 
      REPEAT IF (I <> SIL) AND (FIRST(I) = IL) THEN
                SFIRST(US,FIRST(US)-1); I:=RED(I); END; 
             US:=RED(US); IL:=IL+1; 
             UNTIL I = SIL; 
      VS:=V; JL:=1; 
      REPEAT IF (J <> SIL) AND (FIRST(J) = JL) THEN
                SFIRST(VS,FIRST(VS)+1); J:=RED(J); END; 
             VS:=RED(VS); JL:=JL+1; 
             UNTIL J = SIL; 
      END; (*go to 2;*)
(*9*) END ASSPR; 


PROCEDURE CSFPAR(L: LIST): LIST; 
(*Characteristic set from partition.  L is a list of non-negative beta-
integers (l sub 1, ...,l sub n).  C is a characteristic set, with j
belonging to C if and only if there is a subset I of the integers from
1 to n such that the sum of the l sub i with i in I=j.*)
VAR  C, D, LL, LP: LIST; 
BEGIN
(*1*) C:=1; LP:=L; 
      WHILE LP <> SIL DO ADV(LP, LL,LP); D:=IMP2(C,LL); 
            C:=CSUN(C,D); END; 
      RETURN(C); 
(*4*) END CSFPAR; 


PROCEDURE CSINT(A,B: LIST): LIST; 
(*Characteristic set intersection.  A and B are characteristic sets.
C is the intersection of A and B.*)
VAR  AL, AP, BL, BP, C, CP, J1Y: LIST; 
BEGIN
(*1*) (*a and b single-precision.*) 
      IF (A < BETA) AND (B < BETA) THEN C:=DAND(A,B); 
         RETURN(C); END; 
(*2*) (*a single-precision.*) 
      IF A < BETA THEN J1Y:=FIRST(B); C:=DAND(A,J1Y); RETURN(C); 
         END; 
(*3*) (*b single-precision.*) 
      IF B < BETA THEN J1Y:=FIRST(A); C:=DAND(J1Y,B); RETURN(C); 
         END; 
(*4*) (*general case.*) CP:=BETA; AP:=A; BP:=B; 
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP); J1Y:=DAND(AL,BL); 
             CP:=COMP(J1Y,CP); 
             UNTIL (AP = SIL) OR (BP = SIL); 
      WHILE (CP <> SIL) AND (FIRST(CP) = 0) DO CP:=RED(CP); 
      END; 
      C:=INV(CP); 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*7*) END CSINT; 


PROCEDURE CSSUB(A,B: LIST): LIST; 
(*Characteristic set subset.  A and B are characteristic sets.  t=1 if
A is a subset of B and otherwise t=0.*)
VAR  AL, AP, BL, BP, CL, TL: LIST; 
BEGIN
(*1*) (*a single-precision.*) 
      IF A < BETA THEN
         IF B < BETA THEN BL:=B; ELSE BL:=FIRST(B); END; 
         CL:=DNIMP(A,BL); 
         IF CL = 0 THEN TL:=1; ELSE TL:=0; END; 
         RETURN(TL); END; 
(*2*) (*b single-precision.*) 
      IF B < BETA THEN TL:=0; RETURN(TL); END; 
(*3*) (*general case.*) AP:=A; BP:=B; 
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP); CL:=DNIMP(AL,BL); 
             IF CL <> 0 THEN TL:=0; RETURN(TL); END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
      IF AP <> SIL THEN TL:=0; ELSE TL:=1; END; 
      RETURN(TL); 
(*6*) END CSSUB; 


PROCEDURE CSUN(A,B: LIST): LIST; 
(*Characteristic set union.  A and B are characteristic sets.  C is the
union of A and B.*)
VAR  AL, AP, BL, BP, C, CP, J1Y: LIST; 
BEGIN
(*1*) (*a and b single-precision.*) 
      IF (A < BETA) AND (B < BETA) THEN C:=DOR(A,B); 
         RETURN(C); END; 
(*2*) (*a single-precision.*) 
      IF A < BETA THEN ADV(B, BL,BP); J1Y:=DOR(A,BL); 
         C:=COMP(J1Y,BP); RETURN(C); END; 
(*3*) (*b single-precision.*) 
      IF B < BETA THEN ADV(A, AL,AP); J1Y:=DOR(AL,B); 
         C:=COMP(J1Y,AP); RETURN(C); END; 
(*4*) (*general case.*) CP:=BETA; AP:=A; BP:=B; 
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP); J1Y:=DOR(AL,BL); 
             CP:=COMP(J1Y,CP); 
             UNTIL (AP = SIL) OR (BP = SIL); 
      IF AP = SIL THEN AP:=BP; END; 
      C:=INV(CP); SRED(CP,AP); RETURN(C); 
(*7*) END CSUN; 


PROCEDURE DAND(AL,BL: LIST): LIST; 
(*Digit and.  a and b are non-negative beta-digits.  c is the
bit-wise and of a and b.*)
VAR  AL1, ALP, BL1, BLP, CL, CLP: LIST; 
BEGIN
(*1*) IF (AL = 0) OR (BL = 0) THEN CL:=0; 
         ELSE MASQREM(AL,2, ALP,AL1); MASQREM(BL,2, BLP,BL1); 
         CLP:=DAND(ALP,BLP); CL:=CLP+CLP; 
         IF (AL1 = 1) AND (BL1 = 1) THEN CL:=CL+1; END; 
         END; 
      RETURN(CL); 
(*4*) END DAND; 


PROCEDURE DNIMP(AL,BL: LIST): LIST; 
(*Digit non-implication.  a and b are non-negative beta-digits.  c
is the bit-wise non-implication of a and b.*)
VAR  AL1, ALP, BL1, BLP, CL, CLP: LIST; 
BEGIN
(*1*) IF AL = 0 THEN CL:=0; ELSE MASQREM(AL,2, ALP,AL1); 
         MASQREM(BL,2, BLP,BL1); CLP:=DNIMP(ALP,BLP); CL:=CLP+CLP; 
         IF (AL1 = 1) AND (BL1 = 0) THEN CL:=CL+1; END; 
         END; 
      RETURN(CL); 
(*4*) END DNIMP; 


PROCEDURE DNOT(AL: LIST): LIST; 
(*Digit not.  a is a non-negative beta-digit.  b is the bit-wise
not of a.*)
VAR  BL: LIST; 
BEGIN
(*1*) BL:=BETA1-AL; RETURN(BL); 
(*4*) END DNOT; 


PROCEDURE DOR(AL,BL: LIST): LIST; 
(*Digit or.  a and b are non-negative beta-digits.  c is the
bit-wise or of a and b.*)
VAR  AL1, ALP, BL1, BLP, CL, CLP: LIST; 
BEGIN
(*1*) IF AL = 0 THEN CL:=BL; ELSE
         IF BL = 0 THEN CL:=AL; ELSE MASQREM(AL,2, ALP,AL1); 
            MASQREM(BL,2, BLP,BL1); CLP:=DOR(ALP,BLP); CL:=CLP+CLP; 
            IF (AL1 > 0) OR (BL1 > 0) THEN CL:=CL+1; END; 
            END; 
         END; 
      RETURN(CL); 
(*4*) END DOR; 


PROCEDURE IBCIND(A,NL,KL: LIST): LIST; 
(*Integer binomial coefficient induction.  n and k are beta-integers
with 0 less than or equal to k less than or equal to n.  A is the
binomial coefficient n over k.  B is the binomial coefficient n
over k+1.*)
VAR  B, J1Y, KLP, NLP: LIST; 
BEGIN
(*1*) NLP:=NL-KL; KLP:=KL+1; 
      IF (A < BETA) AND (NLP < BETA DIV A) THEN J1Y:=A*NLP; 
         B:=J1Y DIV KLP; ELSE J1Y:=IDPR(A,NLP); B:=IDQ(J1Y,KLP); END; 
      RETURN(B); 
(*4*) END IBCIND; 


PROCEDURE IBCOEF(NL,KL: LIST): LIST; 
(*Integer binomial coefficient.  n and k are beta-integers with
0 less than or equal to k less than or equal to n.  A is the binomial
coefficient n over k.*)
VAR  A, J1Y, JL, KLP: LIST; 
BEGIN
(*1*) J1Y:=NL-KL; KLP:=MASMIN(KL,J1Y); A:=1; 
      FOR JL:=0 TO KLP-1 DO A:=IBCIND(A,NL,JL); END; 
      RETURN(A); 
(*4*) END IBCOEF; 


PROCEDURE IBCPS(NL,KL: LIST): LIST; 
(*Integer binomial coefficient partial sum.  n and k are
beta integers, 0 le k le n.  A is the sum on i, from 0 to k, of the
binomial coefficient n over i.*)
VAR  A, B, JL: LIST; 
BEGIN
(*1*) A:=1; B:=1; 
      FOR JL:=0 TO KL-1 DO B:=IBCIND(B,NL,JL); A:=ISUM(A,B); END; 
      RETURN(A); 
(*4*) END IBCPS; 


PROCEDURE IFACTL(NL: LIST): LIST; 
(*Integer factorial.  n is a non-negative beta-integer.  A is
n factorial.*)
VAR  A, D, KL: LIST; 
BEGIN
(*1*) A:=1; D:=1; 
      FOR KL:=2 TO NL DO
          IF KL <= BETA DIV D THEN D:=D*KL; ELSE A:=IDPR(A,D); 
             D:=KL; END; 
          END; 
      IF A = 1 THEN A:=D; ELSE A:=IDPR(A,D); END; 
      RETURN(A); 
(*4*) END IFACTL; 


PROCEDURE LEXNEX(A: LIST): LIST; 
(*Lexicographically next.  A is a non-null list (a sub 1, ...,a sub m) 
such that a sub i is a non-null reductant of a sub i+1 for each
1 le i lt m.  B is the lexicographically next such list of the same
length, if one exists, and is () otherwise.*)
VAR  AL, B, BL, CL, IL, JL: LIST; 
BEGIN
(*1*) (*step first element.*) ADV(A, BL,B); CL:=RED(BL); 
      IF CL <> SIL THEN B:=COMP(CL,B); RETURN(B); END; 
      IL:=1; 
(*2*) (*find an element to step.*) 
      WHILE B <> SIL DO ADV(B, AL,B); IL:=IL+1; CL:=RED(AL); 
            IF CL <> BL THEN (*go to 3;*)
               (*3*) (*found one.*) 
               FOR JL:=1 TO IL DO B:=COMP(CL,B); CL:=RED(CL); END; 
               RETURN(B); 
               END; 
            BL:=AL; END; 
      RETURN(B); 
(*6*) END LEXNEX; 


PROCEDURE LPERM(L,P: LIST): LIST; 
(*List permute.  L is a list (a sub 1, ...,a sub n).  P is a list
(p sub 1, ...,p sub n) of integers in the range 1, ...,n.  LP is the
list (a sub p sub 1, ...,a sub p sub n).*)
VAR  AL, LP, PL, PP: LIST; 
BEGIN
(*1*) LP:=BETA; PP:=P; 
      WHILE PP <> SIL DO ADV(PP, PL,PP); AL:=LELT(L,PL); 
            LP:=COMP(AL,LP); END; 
      LP:=INV(LP); RETURN(LP); 
(*4*) END LPERM; 


PROCEDURE PARTN(NL,P: LIST): LIST; 
(*Partition, next.  n is a positive beta-integer.  P is a partition of
n.  Q is the next partition of n after P in lexicographical order,
if any.  Otherwise Q=().*)
VAR  AL, ALP, BL, IL, J1Y, PP, Q, QL, RL: LIST; 
BEGIN
(*1*) (*rl=1.*) RL:=LENGTH(P); 
      IF RL = 1 THEN Q:=BETA; RETURN(Q); END; 
(*2*) (*rl greater than or equal to 2.*) Q:=BETA; PP:=P; 
      FOR IL:=1 TO RL-2 DO ADV(PP, AL,PP); Q:=COMP(AL,Q); END; 
      AL:=FIRST(PP); BL:=SECOND(PP); ALP:=AL+1; MASQREM(AL+BL,ALP, QL,RL); 
      FOR IL:=1 TO QL-1 DO Q:=COMP(ALP,Q); END; 
      J1Y:=ALP+RL; Q:=COMP(J1Y,Q); Q:=INV(Q); RETURN(Q); 
(*5*) END PARTN; 


PROCEDURE PARTR(NL: LIST): LIST; 
(*Partition, random.  n is a positive beta-integer, n less than or
equal to 100.  P is a partition of n whose elements are the cycle
lengths of a random n-permutation.*)
VAR  A: ARRAY[1..100] OF INTEGER; 
VAR  P: LIST; 
     n, HL, IL, J1Y, JL, KL: INTEGER;
BEGIN
(*1*) (*generate random permutation.*) n:=INTEGER(NL); 
      FOR IL:=1 TO n DO A[IL]:=IL; END; 
      FOR JL:=n TO 2 BY -1 DO J1Y:=INTEGER(MDRAN(GAMMAINT(JL))); 
          IL:=J1Y+1; KL:=A[IL]; 
          A[IL]:=A[JL]; A[JL]:=KL; END; 
(*2*) (*obtain cycle lengths.*) P:=BETA; IL:=1; 
      REPEAT HL:=0; JL:=IL; 
             REPEAT KL:=A[JL]; A[JL]:=-JL; JL:=KL; HL:=HL+1; 
                    UNTIL A[JL] < 0; 
             P:=COMP(GAMMAINT(HL),P); 
             REPEAT IL:=IL+1; 
                    UNTIL (IL > n) OR (A[IL] > 0); 
             UNTIL IL > n; 
(*3*) (*sort.*) P:=LBIBMS(P); RETURN(P); 
(*6*) END PARTR; 


PROCEDURE PARTSS(PL: LIST): LIST; 
(*Partition sumset.  p is a partition.  A is the sum set of p,
a characteristic set.*)
VAR  A, AL, B, PLP: LIST; 
BEGIN
(*1*) A:=1; PLP:=PL; 
      WHILE PLP <> SIL DO ADV(PLP, AL,PLP); B:=IMP2(A,AL); 
            A:=CSUN(A,B); END; 
      RETURN(A); 
(*4*) END PARTSS; 


PROCEDURE PERMR(NL: LIST): LIST; 
(*Permutation, random.  n is a positive integer, n le 100.  L is a
list of the first n positive integers in random order.*)
VAR  A: ARRAY[1..100] OF INTEGER; 
VAR  L: LIST;
     n, IL, J1Y, JL, TL: INTEGER; 
BEGIN
(*1*) (*initialize array.*) n:=INTEGER(NL); 
      FOR IL:=1 TO n DO A[IL]:=IL; END; 
(*2*) (*random interchanges.*) 
      FOR JL:=n TO 1 BY -1 DO J1Y:=INTEGER(MDRAN(GAMMAINT(JL))); 
          IL:=J1Y+1; TL:=A[IL]; 
          A[IL]:=A[JL]; A[JL]:=TL; END; 
(*3*) (*form list.*) L:=BETA; 
      FOR IL:=1 TO n DO L:=COMP(GAMMAINT(A[IL]),L); END; 
      RETURN(L); 
(*6*) END PERMR; 


PROCEDURE SDR(S: LIST;  VAR A,I: LIST); 
(*System of distinct representatives.  S is a list (s(1), ...,s(n)),
n ge 1, where each s(i) is a set of beta-integers represented as a
list.  Either A is a list (a(1), ...,a(n)) of distinct
representatives for (s(1), ...,s(n)) and I=(), or else A=() and
I=(i(1), ...,i(k)) is a subsequence of (1, ...,n) such that
(s(i(1)), ...,s(i(k))) has no system of distinct representatives.*)
VAR  AL, AS, B, BL, IL, J1Y, JL, KL, RL, S1, S2, SP, T, T1, T2, TP1,
     TS1: LIST; 
BEGIN
(*1*) (*initialize.*) A:=BETA; AS:=BETA; SP:=S; RL:=0; 

LOOP
(*2*) (*test for completion.*) 
      REPEAT
             IF SP = SIL THEN A:=INV(A); I:=BETA; RETURN; END; 

(*3*) (*direct extension.*) ADV(SP, S1,SP); B:=SDIFF(S1,AS); 
             IF B <> SIL THEN AL:=FIRST(B); A:=COMP(AL,A); 
                AS:=LINSRT(AL,AS); RL:=RL+1; (*go to 2;*) END;
             UNTIL B = SIL; 

(*4*) (*initialize indirect extension.*) T1:=S1; TS1:=T1; T:=BETA; 

(*5*) (*test for non-extensibility.*) 
REPEAT
      IF T1 = SIL THEN (*go to 9;*) EXIT END; 
(*6*) (*compute next t(il).*) T2:=BETA; TP1:=T1; 
      REPEAT ADV(TP1, AL,TP1); IL:=LSRCH(AL,A); J1Y:=RL-IL; JL:=J1Y+1; 
             S2:=LELT(S,JL); T2:=SUNION(T2,S2); 
             UNTIL TP1 = SIL; 
      T2:=SDIFF(T2,TS1); TS1:=SUNION(TS1,T2); 
(*7*) (*prepare for next t(il).*) B:=SDIFF(T2,AS); T:=COMP(T1,T); 
      T1:=T2; 
      UNTIL B <> SIL; (*if b = sil then go to 5; end; *)

(*8*) (*substitute in a.*) BL:=FIRST(B); AS:=LINSRT(BL,AS); 
      REPEAT ADV(T, T1,T); 
             REPEAT ADV(T1, AL,T1); IL:=LSRCH(AL,A); J1Y:=RL-IL; 
                    JL:=J1Y+1; S1:=LELT(S,JL); KL:=LSRCH(BL,S1); 
                    UNTIL KL <> 0; 
             SLELT(A,IL,BL); BL:=AL; 
             UNTIL T = SIL; 
      A:=COMP(BL,A); RL:=RL+1; 
      END; (*go to 2;*) 

(*9*) (*compute i.*) J1Y:=RL+1; I:=LIST1(J1Y); 
      WHILE TS1 <> SIL DO ADV(TS1, AL,TS1); IL:=LSRCH(AL,A); 
            J1Y:=RL-IL; JL:=J1Y+1; I:=LINSRT(JL,I); END; 
      A:=BETA; RETURN; 
(*12*) END SDR; 


PROCEDURE SFCS(A: LIST): LIST; 
(*Set from characteristic set.  A is a characteristic set.  B is the
same set represented as an increasing list of beta-integers.*)
VAR  AL, AP, B, BL, NL, RL: LIST; 
BEGIN
(*1*) (*a empty.*) 
      IF A = 0 THEN B:=BETA; RETURN(B); END; 
(*2*) (*a single-precision.*) 
      IF A < BETA THEN AP:=LIST1(A); ELSE AP:=A; END; 
(*3*) (*general case.*) NL:=0; B:=BETA; 
      REPEAT ADV(AP, AL,AP); BL:=1; 
             REPEAT RL:=MASREM(AL,2); AL:=AL DIV 2; 
                    IF RL <> 0 THEN B:=COMP(NL,B); END; 
                    NL:=NL+1; BL:=BL+BL; 
                    UNTIL BL = BETA; 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*6*) END SFCS; 


BEGIN

BETA1:=BETA-1;

END SACCOMB.

(* -EOF- *)
