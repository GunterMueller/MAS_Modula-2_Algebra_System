(* ----------------------------------------------------------------------------
 * $Id: SACPRIM.mi,v 1.4 1995/11/05 08:45:56 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACPRIM.mi,v $
 * Revision 1.4  1995/11/05 08:45:56  kredel
 * Cosmetic Changes.
 *
 * Revision 1.2  1994/10/06  11:34:52  kredel
 * Cosmetic changes
 *
 * Revision 1.1.1.1  1993/06/11  12:54:12  kredel
 * Initial Version 0.7 of MAS from University of Passau
 *
 * Revision 1.3  1992/10/15  16:28:20  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:19:17  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:44  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACPRIM;

(* SAC Factorization and Prime Number Implementation Module. *)



(* Import Lists and Declarations. *)

FROM MASELEM IMPORT MASEVEN, MASREM, MASQREM;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM MASSTOR IMPORT LIST, SIL, BETA, LISTVAR,
                    COMP, SFIRST, LIST1, 
                    LENGTH, ADV, INV, FIRST, RED;

FROM MASERR IMPORT ERROR, severe;

FROM SACLIST IMPORT LIST2, LIST3, LSRCH;

FROM SACSET IMPORT LBIBMS;             

FROM SACD IMPORT DGCD;

FROM SACI IMPORT IDREM, ISQRT, IDQ, IMAX, ISUM, IDQR,
                 ICOMP, IDIF, IPROD, IQR, IQ;

FROM SACM IMPORT MDLCRA, MDPROD, MIEXP, MDEXP, MDDIF, MDNEG;

CONST rcsidi = "$Id: SACPRIM.mi,v 1.4 1995/11/05 08:45:56 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DPGEN(ML, K: LIST): LIST;
(*Digit prime generator. K and m are positive beta-integers.  
L is the list (p(1),...,p(r)) of all prime numbers p such that 
m le p lt m+2*K, with p(1) lt p(2) lt ... lt p(r).  
A local array is used.*)
VAR  P: ARRAY[1..1000] OF BOOLEAN;
     L, PL, ML1, ML2, HL, DL, SL, QL, RL: LIST;  
     i, k: INTEGER;
BEGIN
(*5*) (*initialize.*) k:=INTEGER(K); 
      IF k > 1000 THEN k:=1000;
         ERROR(severe,"in DPGEN, only 2*1000 numbers checked.");
         END;
      IF MASEVEN(ML) THEN ML1:=ML+1 ELSE ML1:=ML END; 
      HL:=LIST(2*k)-2; ML2:=ML1+HL;
      FOR i:=1 TO k DO P[i]:=TRUE END;
(*2*) (*mark proper odd multiples of dl for dl=3 and dl=6*nl+1 or
      dl=6*nl-1 with dl**2 le ml2.*) 
      DL:=3; SL:=0;
      LOOP   QL:=ML2 DIV DL;
             IF QL < DL THEN (*go to 3;*) EXIT; END;
             RL:=ML1 MOD DL;
             IF (RL+HL >= DL) OR (RL = 0) THEN
                IF RL = 0 THEN i:=1; ELSE
                   IF RL MOD 2 = 0  
                      THEN i:=INTEGER(DL-(RL DIV 2)+1); 
                      ELSE i:=INTEGER(((DL-RL) DIV 2)+1); END;
                   END;
                IF ML1 <= DL THEN i:=i+INTEGER(DL); END;
                WHILE i <= k DO P[i]:=FALSE; i:=i+INTEGER(DL); END;
                END;
             IF SL = 1 THEN DL:=DL+4; SL:=2; ELSE
                IF SL = 2 THEN DL:=DL+2; SL:=1; ELSE DL:=5; SL:=2;
                   END;
                END;
             END; (*loop*)
(*3*) (*construct prime list.*) L:=SIL; PL:=ML2; i:=k;
      REPEAT IF P[i] THEN L:=COMP(PL,L); END;
             PL:=PL-2; i:=i-1;
             UNTIL i = 0;
      IF ML = 1 THEN SFIRST(L,2); END;
      IF ML = 2 THEN L:=COMP(2,L); END;
      RETURN(L);
(*6*) END DPGEN;


PROCEDURE FRESL(NL: LIST; VAR ML,L: LIST);
(*Fermat residue list.  n is a positive integer with no prime divisors
less than 17.  m is a positive beta-integer and L is an ordered list
of the elements of Z(m) such that if x**2-n is a square then x is
congruent to a (modulo m) for some a in L.*)
VAR  AL1, AL2, AL3, AL4, BL1, H, HL, J1Y, J2Y, KL, KL1, L1, M, ML1:
     LIST;
BEGIN
(*1*) (*modulus 2**5.*) AL1:=IDREM(NL,32); AL2:=MASREM(AL1,16);
      AL3:=MASREM(AL2,8); AL4:=MASREM(AL3,4);
      IF AL4 = 3 THEN ML:=4;
         IF AL3 = 3 THEN BL1:=2; ELSE BL1:=0; END;
         ELSE
         IF AL3 = 1 THEN ML:=8;
            IF AL2 = 1 THEN BL1:=1; ELSE BL1:=3; END;
            ELSE ML:=16;  
            CASE INTEGER(AL1 DIV 8) OF
                 0 : BL1:=3; |
                 1 : BL1:=7; |
                 2 : BL1:=5; |
                 3 : BL1:=1; 
                 END;
            END;
         END;
      IF ML = 4 THEN L:=LIST1(BL1); ELSE J1Y:=ML-BL1;
         L:=LIST2(BL1,J1Y); END;
      KL:=LENGTH(L);
(*2*) (*modulus 3**3.*) AL1:=IDREM(NL,27); AL2:=MASREM(AL1,3);
      IF AL2 = 2 THEN ML1:=3; KL1:=1; L1:=LIST1(0); ELSE ML1:=27;
         KL1:=4; L1:=FRLSM(ML1,AL1); END;
(*3*) (*combine.*) L:=MDLCRA(ML,ML1,L,L1); ML:=ML*ML1; KL:=KL*KL1;
(*4*) (*modulus 5**2.*) AL1:=IDREM(NL,25); AL2:=MASREM(AL1,5);
      IF (AL2 = 2) OR (AL2 = 3) THEN ML1:=5; J1Y:=AL2-1; J2Y:=6-AL2;
         L1:=LIST2(J1Y,J2Y); KL1:=2; ELSE ML1:=25; L1:=FRLSM(ML1,AL1);
         KL1:=7; END;
(*5*) (*combine.*)
      IF ML1 >= (BETA DIV ML) THEN RETURN; END;
      KL:=KL*KL1; L:=MDLCRA(ML,ML1,L,L1); ML:=ML*ML1;
(*6*) (*moduli 7,11,13.*) M:=LIST3(7,11,13); H:=LIST3(64,48,0);
      LOOP   ADV(M,ML1,M);
             IF ML1 >= (BETA DIV ML) THEN RETURN; END;
             AL1:=IDREM(NL,ML1); L1:=FRLSM(ML1,AL1); KL1:=LENGTH(L1);
             L:=MDLCRA(ML,ML1,L,L1); ML:=ML*ML1; KL:=KL*KL1;
             ADV(H,HL,H);
             IF KL > HL THEN RETURN; END;
             END;
(*9*) RETURN; END FRESL;


PROCEDURE FRLSM(ML,AL: LIST): LIST;
(*Fermat residue list, single modulus.  m is a positive beta-integer.
a belongs to Z(m).  L is a list of the distinct b in Z(m) such
that b**2-a is a square in Z(m).*)
VAR  IL, ILP, JL, L, MLP, S, SL, SLP, SP: LIST;
BEGIN
(*1*) (*compute list of squares of z(ml).*) MLP:=ML DIV 2; S:=BETA;
      FOR IL:=0 TO MLP DO SL:=MDPROD(ML,IL,IL); S:=COMP(SL,S); END;
(*2*) (*compute l.*) L:=BETA; SP:=S;
      FOR IL:=MLP TO 0 BY -1 DO ADV(SP,SL,SP); SLP:=MDDIF(ML,SL,AL);
          JL:=LSRCH(SLP,S);
          IF JL <> 0 THEN L:=COMP(IL,L); ILP:=MDNEG(ML,IL);
             IF ILP <> IL THEN L:=COMP(ILP,L); END;
             END;
          END;
      RETURN(L);
(*5*) END FRLSM;


PROCEDURE GDPGEN(ML: LIST; KL: INTEGER): LIST;
(*Gaussian digit prime generator. m and k are positive beta-integers. 
L is the list (p(1),...,p(r)) of all prime numbers p such that m is 
less than or equal to p, p is less than m+4*k and p is congruent to 
3 mod 4, with p(1) lt p(2) lt ... lt p(r).  A local array is used.*)
VAR  P: ARRAY[1..1000] OF BOOLEAN;
     RL4, RL6, QLB, MLB, JL, MLS,  
     L, PL, J1Y, ML1, ML2, HL, DL, SL, QL, RL: LIST;  
     i: INTEGER;
BEGIN
(*5*) (*initialize.*) RL:=MASREM(ML,4); J1Y:=ML+3; ML1:=J1Y-RL; 
      J1Y:=LIST(4*KL);
      J1Y:=ML1+J1Y; ML2:=J1Y-4;
      IF KL > 1000 THEN KL:=1000;
         ERROR(severe,"in GDPGEN, only 4*1000 numbers checked.");
         END;
      FOR i:=1 TO KL DO P[i]:=TRUE; END;
(*2*) (*mark proper multiples of dl=3, dl=6*nl+1 and dl=6*nl-1 with
            dl**2 le ml2.*) DL:=3; RL4:=3; RL6:=3;
      LOOP   QLB:=ML2 DIV DL;
             IF DL > QLB THEN (*go to 3;*) EXIT; END;
             MLB:=QLB*DL; RL:=MASREM(MLB,4);
             IF RL = 3 THEN JL:=0; ELSE
                IF RL4 = 1 THEN JL:=RL+1; ELSE JL:=3-RL; END;
                END;
             J1Y:=JL*DL; MLS:=MLB-J1Y; J1Y:=MLS-ML1; J1Y:=J1Y DIV 4;
             i:=INTEGER(J1Y)+1; QL:=QLB-JL;
             WHILE (i > 0) AND (QL > 1) DO P[i]:=FALSE; i:=i-INTEGER(DL);
                   QL:=QL-4; END;
             IF RL6 = 1 THEN DL:=DL+4; RL6:=5; ELSE DL:=DL+2;
                IF RL4 = 3 THEN RL4:=1; ELSE RL4:=3; END;
                IF RL6 = 5 THEN RL6:=1; ELSE RL6:=RL6+2; END;
                END;
             END;
(*3*) (*construct prime list.*) L:=SIL; PL:=ML2;
      FOR i:=KL TO 1 BY -1 DO
          IF P[i] THEN L:=COMP(PL,L); END;
          PL:=PL-4; END;
      RETURN(L);
(*6*) END GDPGEN;


PROCEDURE IFACT(NL: LIST): LIST;
(*Integer factorization.  n is a positive integer. F is a list 
(q(1), q(2),...,q(h)) of the prime factors of n, q(1) le q(2) le ...
le q(h), with n equal to the product of the q(i).*)
VAR  AL, BL, CL, F, FP, J1Y, ML, MLP, PL, RL, SL, TL: LIST;
BEGIN
(*1*) (*find small factors of nl.*) ISPD(NL,F,ML);
      IF ML = 1 THEN RETURN(F); END;
      F:=INV(F); AL:=1000;
REPEAT
(*2*) (*test for primality.*)
      IF ML < BETA THEN MLP:=ML-1; RL:=MDEXP(ML,3,MLP); ELSE
         MLP:=IDIF(ML,1); RL:=MIEXP(ML,3,MLP); END;
      IF RL = 1 THEN (*go to 5;*) 
         (*5*) (*selfridge primality test.*) FP:=IFACT(MLP);
         SL:=ISPT(ML,MLP,FP);
         IF SL = 1 THEN F:=COMP(ML,F); F:=INV(F); RETURN(F); END;
         (*go to 3;*)         
         END;
(*3*) (*search for a medium divisor.*) ISQRT(ML,CL,TL); J1Y:=IDQ(CL,3);
      BL:=IMAX(5000,J1Y);
      IF ICOMP(AL,BL) > 0 THEN (*go to 4;*) PL:=1; 
         ELSE
         IMPDS(ML,AL,BL,PL,ML);
         IF PL <> 1 THEN AL:=PL; F:=COMP(PL,F); (*go to 2;*) END;
         END;
UNTIL PL = 1;
      AL:=BL;
(*4*) (*search for large divisor.*) BL:=CL; ILPDS(ML,AL,BL,PL,ML);
      IF PL <> 1 THEN F:=COMP(PL,F); END;
      F:=COMP(ML,F); F:=INV(F); RETURN(F);
(*8*) END IFACT;


PROCEDURE ILPDS(NL,AL,BL: LIST; VAR PL,NLP: LIST);
(*Integer large prime divisor search.  n is a positive integer with
no prime divisors less than 17.  1 le a le b le n.  A search is made
for a divisor p of the integer n, with a le p le b.  If such a p
is found then np=n/p, otherwise p=1 and np=n.  A modular version
of fermats method is used, and the search goes from a to b.*)
VAR  J1Y, L, LP, ML, QL, RL, RL1, RL2, SL, TL, XL, XL1, XL2, YL,
     YLP: LIST;
BEGIN
(*1*) (*compute boundary values of xl.*) IQR(NL,BL,QL,RL);
      XL1:=ISUM(BL,QL); IDQR(XL1,2,XL1,SL);
      IF (RL <> 0) OR (SL <> 0) THEN XL1:=ISUM(XL1,1); END;
      QL:=IQ(NL,AL); XL2:=ISUM(AL,QL); XL2:=IDQ(XL2,2);
(*2*) (*compute and sort residue list.*) FRESL(NL,ML,L); L:=LBIBMS(L);
      L:=INV(L);
(*3*) (*find starting residue.*) RL:=IDREM(XL2,ML); LP:=L;
      WHILE (LP <> SIL) AND (RL < FIRST(LP)) DO LP:=RED(LP); END;
      IF LP = SIL THEN LP:=L; SL:=ML; ELSE SL:=0; END;
      ADV(LP,RL1,LP); J1Y:=SL+RL; SL:=J1Y-RL1; XL:=IDIF(XL2,SL);
(*4*) (*test successive values of xl.*)
      WHILE ICOMP(XL,XL1) >= 0 DO J1Y:=IPROD(XL,XL);
            YLP:=IDIF(J1Y,NL); ISQRT(YLP,YL,TL);
            IF TL = 0 THEN PL:=IDIF(XL,YL); NLP:=ISUM(XL,YL); RETURN;
               END;
            IF LP <> SIL THEN ADV(LP,RL2,LP); SL:=RL1-RL2; ELSE
               ADV(L,RL2,LP); J1Y:=ML+RL1; SL:=J1Y-RL2; END;
            RL1:=RL2; XL:=IDIF(XL,SL); END;
(*5*) (*no divisor found.*) PL:=1; NLP:=NL; RETURN;
(*8*) END ILPDS;


PROCEDURE IMPDS(NL,AL,BL: LIST; VAR PL,QL: LIST);
(*Integer medium prime divisor search.  n, a and b are positive
integers such that a le b le n and n has no
positive divisors less than a.  If n has a prime
divisor in the closed interval from a to b then p is the least
such prime and q=n/p.  Otherwise p=1 and q=n.*)
VAR  J1Y, LP, PLP, RL, RL1, RL2: LIST;
BEGIN
(*1*) (*determine first divisor.*) RL:=IDREM(AL,210); LP:=UZ210;
      WHILE RL > FIRST(LP) DO LP:=RED(LP); END;
      RL1:=FIRST(LP); J1Y:=RL1-RL; PL:=ISUM(AL,J1Y);
(*2*) (*repeated trial division.*)
      WHILE ICOMP(PL,BL) <= 0 DO
            IF PL < BETA THEN IDQR(NL,PL,QL,RL); ELSE
               IQR(NL,PL,QL,RL); END;
            IF RL = 0 THEN RETURN; END;
            LP:=RED(LP);
            IF LP = SIL THEN LP:=UZ210; RL2:=RL1-210; ELSE
               RL2:=RL1; END;
            RL1:=FIRST(LP);
            IF PL < BETA THEN J1Y:=PL+RL1; PLP:=J1Y-RL2;
               IF PLP >= BETA THEN J1Y:=PLP-BETA; PL:=LIST2(J1Y,1);
                  ELSE PL:=PLP; END;
               ELSE J1Y:=RL1-RL2; PL:=ISUM(PL,J1Y); END;
            END;
(*3*) (*no divisors found.*) PL:=1; QL:=NL; RETURN;
(*6*) END IMPDS;


PROCEDURE ISPD(NL: LIST; VAR F,ML: LIST);
(*Integer small prime divisors.  n is a positive integer.
F is a list of primes (q(1),q(2),...,q(h)), h non-negative,
q(1) le q(2) le ... lt q(h), such that n is equal to m times the
product of the q(i) and m is not divisible by any prime in SMPRM.
Either m=1 or m gt 1,000,000.*)
VAR  LP, PL, QL, RL: LIST;
BEGIN
(*1*) F:=BETA; ML:=NL; LP:=SMPRM;
      REPEAT PL:=FIRST(LP);
             IF ML < BETA THEN MASQREM(ML,PL,QL,RL); ELSE
                IDQR(ML,PL,QL,RL); END;
             IF RL = 0 THEN F:=COMP(PL,F); ML:=QL; ELSE LP:=RED(LP);
                END;
             UNTIL (QL <= PL) OR (LP = SIL);
      IF (QL <= PL) AND (ML <> 1) THEN F:=COMP(ML,F); ML:=1; END;
      F:=INV(F); RETURN;
(*4*) END ISPD;


PROCEDURE ISPT(ML,MLP,F: LIST): LIST;
(*Integer selfridge primality test.  m is an integer greater than or
equal to 3.  mp=m-1.  F is a list (q(1),q(2),...,q(k)),
q(1) le q(2) le ... le q(k), of the prime factors of mp, with
mp equal to the product of the q(i). An attempt is made to find a 
root of unity modulo m of order m-1.  If the existence of such a root 
is discovered then m is prime and s=1.  If it is discovered that no such
root exists then m is not a prime and s=-1.  Otherwise the primality
of m remains uncertain and s=0.*)
VAR  AL, BL, FP, MLPP, PL, PL1, PP, QL, QL1, SL: LIST;
BEGIN
(*1*) (*initialize outer loop.*) FP:=F; QL1:=1; PL1:=1;
      LOOP
(*2*) (*get next divisor of mlp, if any.*)
      REPEAT IF FP = SIL THEN SL:=1; RETURN(SL); END;
             ADV(FP,QL,FP);
             UNTIL ICOMP(QL,QL1) > 0;
      QL1:=QL;
(*3*) (*try successive small primes.*) PP:=SMPRM;
      REPEAT IF PP = SIL THEN SL:=0; RETURN(SL); END;
             ADV(PP,PL,PP);
             IF PL > PL1 THEN PL1:=PL; AL:=MIEXP(ML,PL,MLP);
                IF AL <> 1 THEN SL:=-1; RETURN(SL); END;
                END;
             MLPP:=IQ(MLP,QL); BL:=MIEXP(ML,PL,MLPP);
             UNTIL BL <> 1;
(*4*) (*return for next divisor.*) (*go to 2;*)
      END;
(*7*) RETURN(SL); END ISPT;


(* initialization of SACPRIM *)

VAR IL: LIST;

BEGIN

LISTVAR(SMPRM); LISTVAR(UZ210);

(*compute small primes list.*) SMPRM:=DPGEN(1,500);

(*compute units of z sub 210.*) UZ210:=SIL;
FOR IL:=209 TO 1 BY -2 DO
    IF DGCD(210,IL) = 1 THEN
       UZ210:=COMP(IL,UZ210); END;
       END;

END SACPRIM.


(* -EOF- *)
