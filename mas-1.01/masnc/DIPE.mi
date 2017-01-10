(* ----------------------------------------------------------------------------
 * $Id: DIPE.mi,v 1.3 1992/10/15 16:29:45 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPE.mi,v $
 * Revision 1.3  1992/10/15  16:29:45  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:27  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:19  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPE;

(* DIP Exterior Algebra Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASREM, MASODD;

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, SRED, SFIRST,
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM MASERR IMPORT severe, ERROR;

FROM SACLIST IMPORT LIST4, LIST2, COMP2, ADV2, FIRST2, 
                    LWRITE, LIST3, AWRITE, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT CREAD, CREADB, CWRITE, 
                    SOLINE, LETTER, DIGIT, 
                    MASORD, BKSP, BLINES, SWRITE;

FROM SACD IMPORT DQR, DRANN;

FROM SACI IMPORT IDPR, IWRITE, IREAD, IRAND, IMAX, IABSF, 
                 IEXP, IDIF, IGCD, ISIGNF, ILCM, 
                 IDP2, IREM, IORD2, ISUM, INEG, IQ, IQR;
FROM SACM IMPORT MDHOM;

FROM SACPRIM IMPORT IFACT;

FROM MASI IMPORT IPROD;

FROM SACPOL IMPORT PBIN, PDEG;

FROM SACIPOL IMPORT IPPROD, IPQ;
 
FROM DIPI IMPORT DIIPIP;

CONST rcsidi = "$Id: DIPE.mi,v 1.3 1992/10/15 16:29:45 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE COPYOB(A: LIST): LIST; 
(*Copy object. A is an object. B is the copy of A.*)
VAR  AL, AP, B, BL: LIST; 
BEGIN
(*1*) (*a emty or atom. *) 
      IF A <= BETA THEN B:=A; RETURN(B); END; 
(*2*) (*copy.*) AP:=A; B:=SIL; 
      REPEAT ADV(AP, AL,AP); BL:=COPYOB(AL); B:=COMP(BL,B); 
             UNTIL AP = SIL; 
      B:=INV(B); 
(*5*) RETURN(B); END COPYOB; 


PROCEDURE EIMWRT(A: LIST); 
(*Exterior integral matrix write. A is an exterior
integral matrix. A is written in the output stream.*)
VAR  AL, AS: LIST; 
BEGIN
(*1*) (*write.*) SWRITE("("); AS:=A; 
      WHILE AS <> SIL DO ADV(AS, AL,AS); SWRITE(" "); EIVWRT(AL); 
            IF AS <> SIL THEN BLINES(1); END; 
            END; 
      SWRITE(" )"); 
(*4*) RETURN; END EIMWRT; 


PROCEDURE EIVABS(U: LIST): LIST; 
(*Exterior integral vector absolute value. U is an
exterior integral vector. V is the absolute value of U. *)
VAR  SL, V: LIST; 
BEGIN
(*1*) (*get sign of u.*) SL:=EIVSIG(U); 
      IF SL < 0 THEN V:=EIVNEG(U); ELSE V:=U; END; 
(*4*) RETURN(V); END EIVABS; 


PROCEDURE EIVAPP(U: LIST): LIST; 
(*Exterior integral vector absolute primitive part. U is an
exterior integral vector. V is the absolute primitive part of U. *)
VAR  V, VL: LIST; 
BEGIN
(*1*) (*call eivcpp and eivabs.*) EIVCPP(U, V,VL); V:=EIVABS(V); 
(*4*) RETURN(V); END EIVAPP; 


PROCEDURE EIVCPP(U: LIST;  VAR V,VL: LIST); 
(*Exterior integral vector content and primitive part.
U is an exterior integral vector. v is the content and
V is the primitive part of U. *)
VAR  IL, UL, US: LIST; 
BEGIN
(*1*) (*u emty.*) 
      IF U = SIL THEN V:=SIL; VL:=0; RETURN; END; 
(*2*) (*compute gct.*) ADV2(U, VL,IL,US); 
      WHILE (US <> SIL) AND (VL <> 1) DO ADV2(US, UL,IL,US); 
            VL:=IGCD(UL,VL); END; 
(*3*) (*divide.*) 
      IF VL = 1 THEN V:=U; ELSE V:=EIVIQ(U,VL); END; 
(*6*) RETURN; END EIVCPP; 


PROCEDURE EIVEPR(U,V: LIST): LIST; 
(*Exterior integral vector exterior product. U and V are exterior
integral vectors. W is the exterior product of U and V.*)
VAR  IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP,
     WS: LIST; 
BEGIN
(*1*) (*u or v emty.*) 
      IF (U = SIL) OR (V = SIL) THEN W:=SIL; RETURN(W); END; 
(*2*) (*general case.*) US:=CINV(U); VS:=CINV(V); W:=SIL; 
      REPEAT ADV2(US, IL,KL,US); VP:=VS; W1:=SIL; 
             REPEAT ADV2(VP,JL,ML,VP); ILEXPR(IL,JL, LL,SL); 
                    IF SL <> 0 THEN
                       IF SL < 0 THEN ML:=INEG(ML); END; 
                       NL:=IPROD(KL,ML); W1:=COMP2(NL,LL,W1); END; 
                    UNTIL VP = SIL; 
             IF W1 <> SIL THEN W:=COMP(W1,W); END; 
             UNTIL US = SIL; 
      IF W = SIL THEN RETURN(W); END; 
(*3*) (*summarize.*) 
      REPEAT WP:=SIL; 
             WHILE (W <> SIL) AND (RED(W) <> SIL) DO ADV2(W,
                   WL1,WL2,W); WS:=EIVSUM(WL1,WL2); WP:=COMP(WS,WP); 
             END; 
             IF WP <> SIL THEN WPP:=INV(WP); SRED(WP,W); W:=WPP; 
             END; 
             UNTIL RED(W) = SIL; 
      W:=FIRST(W); 
(*6*) RETURN(W); END EIVEPR; 


PROCEDURE EIVFUP(A,PL: LIST): LIST; 
(*Exterior integral vector from univariate integral polynomial
with multiplication by power of main variable. A is an
univariate integral polynomial. p is a beta-integer. B is the
exterior integral vector from A(x)*(x**p). *)
VAR  AL, AS, B, EL, FL, GL: LIST; 
BEGIN
(*1*) (*a=0. *) B:=SIL; 
      IF A = 0 THEN RETURN(B); END; 
(*2*) (*multiply terms and convert.*) AS:=A; 
      REPEAT ADV2(AS, EL,AL,AS); FL:=EL+PL; GL:=LIST1(FL); 
             B:=COMP2(AL,GL,B); 
             UNTIL AS = SIL; 
      RETURN(B); 
(*5*) END EIVFUP; 


PROCEDURE EIVILP(U,V: LIST): LIST; 
(*Exterior integral vector inner left product. U and V are
exterior integral vectors. W is the inner left
product of U and V.*)
VAR  IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP,
     WS: LIST; 
BEGIN
(*1*) (*u or v emty.*) 
      IF (U = SIL) OR (V = SIL) THEN W:=SIL; RETURN(W); END; 
(*2*) (*general case.*) US:=U; VS:=V; W:=SIL; 
      REPEAT ADV2(US, KL,IL,US); VP:=VS; W1:=SIL; 
             REPEAT ADV2(VP,ML,JL,VP); ILINPR(IL,JL, LL,SL); 
                    IF SL <> 0 THEN
                       IF SL < 0 THEN ML:=INEG(ML); END; 
                       NL:=IPROD(KL,ML); W1:=COMP2(NL,LL,W1); END; 
                    UNTIL VP = SIL; 
             IF W1 <> SIL THEN W:=COMP(W1,W); END; 
             UNTIL US = SIL; 
      IF W = SIL THEN RETURN(W); END; 
(*3*) (*summarize.*) 
      REPEAT WP:=SIL; 
             WHILE (W <> SIL) AND (RED(W) <> SIL) DO ADV2(W,
                   WL1,WL2,W); WS:=EIVSUM(WL1,WL2); WP:=COMP(WS,WP); 
             END; 
             IF WP <> SIL THEN WPP:=INV(WP); SRED(WP,W); W:=WPP; 
             END; 
             UNTIL RED(W) = SIL; 
      W:=FIRST(W); 
(*6*) RETURN(W); END EIVILP; 


PROCEDURE EIVIP(A,BL: LIST): LIST; 
(*Exterior integral vector integer product. A is an
exterior integral vector, b is an integer, C=A*b. *)
VAR  AL, AP, C, EL, PL, RL: LIST; 
BEGIN
(*1*) (*a emty.*) C:=SIL; 
      IF (A = SIL) OR (BL = 0) THEN RETURN(C); END; 
(*2*) (*multiply.*) AP:=A; 
      REPEAT ADV2(AP, AL,EL,AP); PL:=IPROD(AL,BL); C:=COMP2(EL,PL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END EIVIP; 


PROCEDURE EIVIQ(A,BL: LIST): LIST; 
(*Exterior integral vector integer quotient. A is an
exterior integral vector, b is a nonzero integer,
and b divides any coefficient of A. C=A/b.*)
VAR  AL, AP, C, EL, QL, RL: LIST; 
BEGIN
(*1*) (*a emty.*) C:=SIL; 
      IF A = SIL THEN RETURN(C); END; 
(*2*) (*divide.*) AP:=A; 
      REPEAT ADV2(AP, AL,EL,AP); IQR(AL,BL, QL,RL); C:=COMP2(EL,QL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END EIVIQ; 


PROCEDURE EIVIRP(U,V: LIST): LIST; 
(*Exterior integral vector inner right product. U and V are
exterior integral vectors. W is the inner right
product of U and V.*)
VAR  IL, JL, KL, LL, ML, NL, SL, US, VP, VS, W, W1, WL1, WL2, WP, WPP,
     WS: LIST; 
BEGIN
(*1*) (*u or v emty.*) 
      IF (U = SIL) OR (V = SIL) THEN W:=SIL; RETURN(W); END; 
(*2*) (*general case.*) US:=U; VS:=V; W:=SIL; 
      REPEAT ADV2(US, KL,IL,US); VP:=VS; W1:=SIL; 
             REPEAT ADV2(VP,ML,JL,VP); ILINPR(JL,IL, LL,SL); 
                    IF SL <> 0 THEN
                       IF SL < 0 THEN ML:=INEG(ML); END; 
                       NL:=IPROD(KL,ML); W1:=COMP2(NL,LL,W1); END; 
                    UNTIL VP = SIL; 
             IF W1 <> SIL THEN W:=COMP(W1,W); END; 
             UNTIL US = SIL; 
      IF W = SIL THEN RETURN(W); END; 
(*3*) (*summarize.*) 
      REPEAT WP:=SIL; 
             WHILE (W <> SIL) AND (RED(W) <> SIL) DO ADV2(W,
                   WL1,WL2,W); WS:=EIVSUM(WL1,WL2); WP:=COMP(WS,WP); 
             END; 
             IF WP <> SIL THEN WPP:=INV(WP); SRED(WP,W); W:=WPP; 
             END; 
             UNTIL RED(W) = SIL; 
      W:=FIRST(W); 
(*6*) RETURN(W); END EIVIRP; 


PROCEDURE EIVNEG(U: LIST): LIST; 
(*Exterior integral vector negative. U is an exterior
integral vector. V is the negative of U. *)
VAR  AL, BL, IL, US, V: LIST; 
BEGIN
(*1*) (*u emty.*) V:=SIL; 
      IF U = SIL THEN RETURN(V); END; 
(*2*) (*negate.*) US:=U; 
      REPEAT ADV2(US, AL,IL,US); BL:=INEG(AL); V:=COMP2(IL,BL,V); 
             UNTIL US = SIL; 
      V:=INV(V); 
(*5*) RETURN(V); END EIVNEG; 


PROCEDURE EIVPP(U: LIST): LIST; 
(*Exterior integral vector primitive part. U is an
exterior integral vector. V is the primitive part of U. *)
VAR  V, VL: LIST; 
BEGIN
(*1*) (*call eivcpp.*) EIVCPP(U, V,VL); 
(*4*) RETURN(V); END EIVPP; 


PROCEDURE EIVSIG(U: LIST): LIST; 
(*Exterior integral vector sign. U is an exterior
integral vector. s is the sign of U. *)
VAR  J1Y, SL: LIST; 
BEGIN
(*1*) IF U = SIL THEN SL:=0; ELSE J1Y:=FIRST(U); SL:=ISIGNF(J1Y); 
         END; 
(*4*) RETURN(SL); END EIVSIG; 


PROCEDURE EIVSUM(U,V: LIST): LIST; 
(*Exterior integral vector sum. U and V are exterior
integral vectors. W is the sum of U and V.*)
VAR  EL, FL, SL, UL, UP, VL, VP, W, WL, WP, WPP: LIST; 
BEGIN
(*1*) (*u or v emty.*) 
      IF U = SIL THEN W:=V; RETURN(W); END; 
      IF V = SIL THEN W:=U; RETURN(W); END; 
(*2*) (*match coefficients.*) UP:=U; VP:=V; WP:=SIL; 
      REPEAT EL:=SECOND(UP); FL:=SECOND(VP); SL:=ILWCMP(EL,FL); 
             IF SL = 1 THEN ADV2(UP, UL,EL,UP); 
                WP:=COMP2(EL,UL,WP); ELSE
                IF SL = -1 THEN ADV2(VP, VL,FL,VP); 
                   WP:=COMP2(FL,VL,WP); ELSE ADV2(UP, UL,EL,UP); 
                   ADV2(VP, VL,FL,VP); WL:=ISUM(UL,VL); 
                   IF WL <> 0 THEN WP:=COMP2(EL,WL,WP); END; 
                   END; 
                END; 
             UNTIL (UP = SIL) OR (VP = SIL); 
(*3*) (*finish.*) 
      IF UP = SIL THEN UP:=VP; END; 
      IF WP = SIL THEN W:=UP; ELSE WPP:=WP; W:=INV(WP); 
         SRED(WPP,UP); END; 
      RETURN(W); 
(*6*) END EIVSUM; 


PROCEDURE EIVWRT(A: LIST); 
(*Exterior integral vector write. A is an exterior
integral vector. A is written in the output stream.*)
VAR  AL, AS, IL: LIST; 
BEGIN
(*1*) (*write.*) SWRITE("("); AS:=A; 
      WHILE AS <> SIL DO ADV2(AS, AL,IL,AS); SWRITE(" "); 
            IF ISIGNF(AL) = 1 THEN SWRITE("+"); END; 
            IWRITE(AL); INLWRT(IL); END; 
      SWRITE(" )"); 
(*4*) RETURN; END EIVWRT; 


PROCEDURE EXIDET(M: LIST): LIST; 
(*Exterior integral matrix determinant. M is an exterior integral
matrix. d is the determinant of A.*)
VAR  D, DL, EL, ML, MP: LIST; 
BEGIN
(*1*) (*apply exterior multiplication to the rows of m.*) ADV(M, D,MP); 
      WHILE (MP <> SIL) AND (D <> SIL) DO ADV(MP, ML,MP); 
            D:=EIVEPR(D,ML); END; 
(*2*) (*finish.*) 
      IF D = SIL THEN DL:=0; RETURN(DL); END; 
      ADV2(D, DL,EL,D); 
      IF D = SIL THEN RETURN(DL); END; 
(*3*) (*error.*) ERROR(severe,"IN EXIDET."); 
(*6*) RETURN(DL); END EXIDET; 


PROCEDURE EXIDT2(M: LIST): LIST; 
(*Exterior integral matrix determinant 2. M is an exterior integral
matrix. d is the determinant of A.*)
VAR  D, DL, EL, ML1, ML2, MP, MPP, MPS: LIST; 
BEGIN
(*1*) (*m=(). *) DL:=0; 
      IF M = SIL THEN RETURN(DL); END; 
(*2*) (*apply exterior multiplication to the rows of m.*) MP:=M; 
      REPEAT MPS:=SIL; 
             WHILE (MP <> SIL) AND (RED(MP) <> SIL) DO ADV2(MP,
                   ML1,ML2,MP); D:=EIVEPR(ML1,ML2); 
                   IF D = SIL THEN RETURN(DL); END; 
                   MPS:=COMP(D,MPS); END; 
             IF MPS <> SIL THEN MPP:=INV(MPS); SRED(MPS,MP); 
                MP:=MPP; END; 
             UNTIL RED(MP) = SIL; 
(*3*) (*finish.*) ADV(MP, D,MP); 
      IF D = SIL THEN RETURN(DL); END; 
      ADV2(D, DL,EL,D); 
      IF D = SIL THEN RETURN(DL); END; 
(*4*) (*error.*) ERROR(severe,"IN EXIDT2."); 
(*7*) RETURN(DL); END EXIDT2; 


PROCEDURE EXMHOM(M: LIST): LIST; 
(*Exterior matrix homomorphism. M=(m1,... ,mn) is a
vector of integral vectors mi, 0 le i le n. MS is a
vector of exterior integral vectors, MS=(ms1,... ,msn).
were msi=EXVHOM(mi). *)
VAR  MP, MS, UL, VL: LIST; 
BEGIN
(*1*) (*call exvhom.*) MS:=SIL; MP:=M; 
      WHILE MP <> SIL DO ADV(MP, UL,MP); VL:=EXVHOM(UL,1); 
            MS:=COMP(VL,MS); END; 
      MS:=INV(MS); RETURN(MS); 
(*4*) END EXMHOM; 


PROCEDURE EXVHOM(U,SL: LIST): LIST; 
(*Exterior vector homomorphism. U=(u1,... ,un) is an
integral vector of n components, 0 le n. s is the
starting index for the exterior index list.
V=(u1,(s),... ,un,(s+n)).  *)
VAR  EL, NL, UL, US, V: LIST; 
BEGIN
(*1*) (*buildt lists.*) V:=SIL; US:=U; NL:=SL-1; 
      WHILE US <> SIL DO NL:=NL+1; ADV(US, UL,US); 
            IF UL <> 0 THEN EL:=LIST1(NL); V:=COMP2(EL,UL,V); END; 
            END; 
      V:=INV(V); RETURN(V); 
(*4*) END EXVHOM; 


PROCEDURE ITD(A: LIST): LIST; 
(*Integer trailing digit. A is an integer,
A = b mod beta.*)
VAR  BL: LIST; 
BEGIN
(*1*) IF A > BETA THEN BL:=FIRST(A); ELSE BL:=A; END; 
(*4*) END ITD; 


PROCEDURE IJACS(X,Y: LIST): LIST; 
(*Integer Jacobi symbol algorithm. Y is an odd
positive integer, X is an integer relatively prime
to Y. s=(X/Y). *)
VAR  A, B, BL0, EL, J1Y, ML, SL: LIST; 
BEGIN
(*1*) (*initialise.*) A:=X; B:=Y; SL:=1; 
(*2*) (*a lt 0.*) 
      IF ISIGNF(A) < 0 THEN A:=INEG(A); 
         IF MASREM(ITD(B),4) <> 1 THEN SL:=-1; END; 
         END; 
(*3*) (*jacobian sequence.*) 
      WHILE B <> 1 DO A:=IREM(A,B); EL:=IORD2(A); 
            IF EL > 0 THEN A:=IDP2(A,EL); 
               IF MASODD(EL) THEN J1Y:=ITD(B); BL0:=MASREM(J1Y,16); 
                  IF MASREM(BL0*BL0,16) <> 1 THEN SL:=-SL; END; 
                  END; 
               END; 
            ML:=A; A:=B; B:=ML; 
            IF (MASREM(ITD(A),4) <> 1) AND (MASREM(ITD(B),4) <> 1)
               THEN SL:=-SL; END; 
            END; 
(*6*) RETURN(SL); END IJACS; 


PROCEDURE ILADDC(U,CL: LIST): LIST; 
(*Index list addition of constant. U is an index list, c is
a beta-integer. V=(u1+c, ...,un+c) where U=(u1, ...,un). 
n ge 0. *)
VAR  UL, US, V, VL: LIST; 
BEGIN
(*1*) (*u=() or cl=0.*) 
      IF (U = SIL) OR (CL = 0) THEN V:=U; RETURN(V); END; 
(*2*) (*add in every component.*) V:=SIL; US:=U; 
      REPEAT ADV(US, UL,US); VL:=UL+CL; V:=COMP(VL,V); 
             UNTIL US = SIL; 
      V:=INV(V); RETURN(V); 
(*5*) END ILADDC; 


PROCEDURE ILEXPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list exterior product. U, V and W are index lists.
W is the exterior product of U and V. s is the sign
of the exterior product. If s = 0 then W = ().  *)
VAR  J1Y, ML, NL, UL, US, VL, VS, WS: LIST; 
BEGIN
(*1*) (*u or v emty.*) SL:=1; 
      IF U = SIL THEN W:=V; RETURN; END; 
      IF V = SIL THEN W:=U; RETURN; END; 
      US:=U; VS:=V; W:=SIL; ML:=0; NL:=0; WS:=SIL; 
(*2*) (*merge and upsate sign.*) 
      REPEAT UL:=FIRST(US); VL:=FIRST(VS); 
             IF UL = VL THEN SL:=0; RETURN; END; 
             IF UL < VL THEN WS:=COMP(UL,WS); ML:=ML+1; 
                US:=RED(US); ELSE WS:=COMP(VL,WS); VS:=RED(VS); 
                NL:=NL+1; 
                IF MASODD(ML) THEN SL:=-SL; END; 
                END; 
             UNTIL (US = SIL) OR (VS = SIL); 
(*3*) (*finish.*) 
      IF US = SIL THEN US:=VS; ELSE J1Y:=LENGTH(US); ML:=ML+J1Y; 
         END; 
      IF MASODD(ML) AND MASODD(NL) THEN SL:=-SL; END; 
      W:=INV(WS); SRED(WS,US); RETURN; 
(*6*) END ILEXPR; 


PROCEDURE ILILPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner left product. U, V and W are index lists.
W is the inner left product of U and V. s is the sign
of the inner left product. If s = 0 then W = ().  *)
VAR  ML, UL, US, VL, VS, WS: LIST; 
BEGIN
(*1*) (*u or v emmty.*) SL:=1; 
      IF U = SIL THEN W:=V; RETURN; END; 
      W:=SIL; 
      IF V = SIL THEN SL:=0; RETURN; END; 
      US:=V; VS:=U; ML:=0; WS:=SIL; 
(*2*) (*complement and update sign.*) 
      REPEAT UL:=FIRST(US); VL:=FIRST(VS); 
             IF UL < VL THEN SL:=0; RETURN; END; 
             IF UL = VL THEN US:=RED(US); VS:=RED(VS); 
                IF MASODD(ML) THEN SL:=-SL; END; 
                ELSE WS:=COMP(VL,WS); VS:=RED(VS); ML:=ML+1; END; 
             UNTIL (US = SIL) OR (VS = SIL); 
(*3*) (*finish.*) 
      IF US <> SIL THEN SL:=0; RETURN; END; 
      IF WS = SIL THEN W:=VS; ELSE W:=INV(WS); SRED(WS,VS); END; 
      RETURN; 
(*6*) END ILILPR; 


PROCEDURE ILINPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner product. U, V and W are index lists. W
is the inner product of U and V, i.e. if U is contained
in V then W is the complement of U in V, otherwise the sign
of the inner product is set to zero. s is the sign of
the inner product. *)
VAR  ML, UL, US, VL, VS, WS: LIST; 
BEGIN
(*1*) (*u or v emty.*) SL:=1; 
      IF U = SIL THEN W:=V; RETURN; END; 
      W:=SIL; 
      IF V = SIL THEN SL:=0; RETURN; END; 
      US:=U; VS:=V; ML:=0; WS:=SIL; 
(*2*) (*complement and update sign.*) 
      REPEAT UL:=FIRST(US); VL:=FIRST(VS); 
             IF UL < VL THEN SL:=0; RETURN; END; 
             IF UL = VL THEN US:=RED(US); VS:=RED(VS); 
                IF MASODD(ML) THEN SL:=-SL; END; 
                ELSE WS:=COMP(VL,WS); VS:=RED(VS); ML:=ML+1; END; 
             UNTIL (US = SIL) OR (VS = SIL); 
(*3*) (*finish.*) 
      IF US <> SIL THEN SL:=0; RETURN; END; 
      IF WS = SIL THEN W:=VS; ELSE W:=INV(WS); SRED(WS,VS); END; 
(*6*) RETURN; END ILINPR; 


PROCEDURE ILIRPR(U,V: LIST;  VAR W,SL: LIST); 
(*Index list inner right product. U, V and W are index lists.
W is the inner right product of U and V. s is the sign
of the inner right product. if s = 0 then W = ().  *)
VAR  ML, UL, US, VL, VS, WS: LIST; 
BEGIN
(*1*) (*u or v emmty.*) SL:=1; 
      IF U = SIL THEN W:=V; RETURN; END; 
      W:=SIL; 
      IF V = SIL THEN SL:=0; RETURN; END; 
      US:=U; VS:=V; ML:=0; WS:=SIL; 
(*2*) (*complement and update sign.*) 
      REPEAT UL:=FIRST(US); VL:=FIRST(VS); 
             IF UL < VL THEN SL:=0; RETURN; END; 
             IF UL = VL THEN US:=RED(US); VS:=RED(VS); 
                IF MASODD(ML) THEN SL:=-SL; END; 
                ELSE WS:=COMP(VL,WS); VS:=RED(VS); ML:=ML+1; END; 
             UNTIL (US = SIL) OR (VS = SIL); 
(*3*) (*finish.*) 
      IF US <> SIL THEN SL:=0; RETURN; END; 
      IF WS = SIL THEN W:=VS; ELSE W:=INV(WS); SRED(WS,VS); END; 
      RETURN; 
(*6*) END ILIRPR; 


PROCEDURE ILSCMP(U,V: LIST): LIST; 
(*Index list strong compare. U=(u1,... ,un), V=(v1,... vm)
are index lists with length n and m. t=1 if n gt m,
t=-1 if n lt m. If n=m then t=0 if U=V,
t=1 if U gt V, t=-1 if U lt V.*)
VAR  ML, NL, TL, UL, US, VL, VS: LIST; 
BEGIN
(*1*) (*initialise and compare.*) TL:=0; US:=U; VS:=V; 
      WHILE (US <> SIL) AND (VS <> SIL) AND (TL = 0) DO 
            ADV(US, UL,US); ADV(VS, VL,VS); 
            IF UL < VL THEN TL:=1; (*go to 4;*) END; 
            IF UL > VL THEN TL:=-1; (*go to 4;*) END; 
            END; 
(*3*) (*u or v emty.*) 
      IF TL = 0 THEN 
         IF (US = SIL) AND (VS = SIL) THEN RETURN(TL); END; 
         IF US = SIL THEN TL:=1; ELSE TL:=-1; END; 
         RETURN(TL) END; 
(*4*) (*compare length.*) ML:=LENGTH(US); NL:=LENGTH(VS); 
      IF ML = NL THEN RETURN(TL); END; 
      IF ML < NL THEN TL:=1; ELSE TL:=-1; END; 
      RETURN(TL); 
(*7*) END ILSCMP; 


PROCEDURE ILWCMP(U,V: LIST): LIST; 
(*Index list week compare. U=(u1,... ,un), V=(v1,... vm) are
index lists. t=0 if U=V, t=1 if U gt V, t=-1 if U lt V.*)
VAR  TL, UL, US, VL, VS: LIST; 
BEGIN
(*1*) (*initialise and compare.*) TL:=0; US:=U; VS:=V; 
      WHILE (US <> SIL) AND (VS <> SIL) DO ADV(US, UL,US); 
            ADV(VS, VL,VS); 
            IF UL < VL THEN TL:=1; RETURN(TL); END; 
            IF UL > VL THEN TL:=-1; RETURN(TL); END; 
            END; 
(*3*) (*u or v emty.*) 
      IF (US = SIL) AND (VS = SIL) THEN RETURN(TL); END; 
      IF US = SIL THEN TL:=1; ELSE TL:=-1; END; 
      RETURN(TL); 
(*6*) END ILWCMP; 


PROCEDURE INDLST(RL,SL: LIST): LIST; 
(*Index list. Starting with r and ending with s.*)
VAR  EL, IL: LIST; 
BEGIN
(*1*) (*rl gt sl.*) EL:=SIL; 
      IF RL > SL THEN RETURN(EL); END; 
(*2*) (*create list.*) 
      FOR IL:=SL TO RL BY -1 DO EL:=COMP(IL,EL); END; 
      RETURN(EL); 
(*5*) END INDLST; 


PROCEDURE INLWRT(U: LIST); 
(*Index list write. U is an exterior index list.
U is written in the output stream.*)
BEGIN
(*1*) (*write.*) SWRITE(" E"); LWRITE(U); 
(*4*) RETURN; END INLWRT; 


PROCEDURE IPSR(R: LIST): LIST; 
(*Integral polynomial specified roots. R is a list of integers.
A is an integral univariate polynomial with roots from R. *)
VAR  A, B, FL, J1Y, RS: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF R = SIL THEN A:=0; RETURN(A); END; 
(*2*) (*multiply factors.*) ADV(R, FL,RS); J1Y:=-FL; 
      A:=PBIN(1,1,J1Y,0); 
      WHILE RS <> SIL DO ADV(RS, FL,RS); J1Y:=-FL; 
            B:=PBIN(1,1,J1Y,0); A:=IPPROD(1,A,B); END; 
      RETURN(A); 
(*5*) END IPSR; 


PROCEDURE IVHOM(U,IL,JL: LIST): LIST; 
(*Integer vector homomorphism. U=(u1,(s),... ,un,(r))
is an exterior integral vector. i is the starting index
for the integral vector and j is its ending index.
V=(vi,... ,vj). *)
VAR  AL, KL, NL, SL, UL, US, V: LIST; 
BEGIN
(*1*) (*read index lists and skip zeros.*) V:=SIL; US:=U; NL:=IL; 
      WHILE US <> SIL DO ADV2(US, AL,UL,US); SL:=FIRST(UL); 
            FOR KL:=NL TO SL-1 DO V:=COMP(0,V); END; 
            V:=COMP(AL,V); NL:=KL+2; END; 
      FOR KL:=NL TO JL DO V:=COMP(0,V); END; 
      V:=INV(V); RETURN(V); 
(*4*) END IVHOM; 


PROCEDURE IVRAND(KL,QL,NL: LIST): LIST; 
(*Integer vector random. U is an random integer vector with
n components, 0 le n, and the absolut value of each
component is lt 2**k. q is a rational number qd/qn,
with 0 lt qd le qn lt beta. So q is the propability
that any particular component of V is not zero.*)
VAR  DL, I, QLD, QLN, QLS, TL, V, VL: LIST; 
BEGIN
(*1*) (*compute qls=int(ql*beta).*) FIRST2(QL, QLD,QLN); 
      DQR(QLD,0,QLN, QLS,TL); 
(*2*) (*randomize.*) V:=SIL; 
      FOR I:=1 TO NL DO DL:=DRANN(); 
          IF DL < QLS THEN VL:=IRAND(KL); ELSE VL:=0; END; 
          V:=COMP(VL,V); END; 
      RETURN(V); 
(*5*) END IVRAND; 


PROCEDURE KREISP(NL: LIST): LIST; 
(*Kreisteilungs polynom. n is a beta-integer gt 1.
A is an univariate integral polynomial. *)
VAR  A, B, IL, J1Y, NP, PL, PS: LIST; 
BEGIN
(*1*) (*nl=1 and prepare.*) 
      IF NL = 1 THEN J1Y:=-1; A:=LIST4(1,1,0,J1Y); RETURN(A); END; 
      NP:=IFACT(NL); A:=SIL; 
(*2*) (*nl prime.*) 
      IF RED(NP) = SIL THEN
         FOR IL:=0 TO NL-1 DO A:=COMP2(IL,1,A); END; 
         RETURN(A); END; 
(*3*) (*nl power of one prime.*) ADV(NP, PL,NP); PS:=1; 
      WHILE (NP <> SIL) AND (PL = FIRST(NP)) DO NP:=RED(NP); 
            PS:=PS*PL; END; 
      IF NP = SIL THEN
         FOR IL:=0 TO PL-1 DO J1Y:=IL*PS; A:=COMP2(J1Y,1,A); END; 
         RETURN(A); END; 
(*4*) (*nl composite.*) J1Y:=-1; A:=LIST4(NL,1,0,J1Y); IL:=1; 
      WHILE IL < NL DO
            IF MASREM(NL,IL) = 0 THEN B:=KREISP(IL); A:=IPQ(1,A,B); 
               END; 
            IL:=IL+1; END; 
      RETURN(A); 
(*7*) END KREISP; 


PROCEDURE MDVHOM(ML,U: LIST): LIST; 
(*Modular vector homomorphism. U is an integral vector.
V is a modular vector. m is a beta-integer.*)
VAR  UL, US, V, VL: LIST; 
BEGIN
(*1*) (*map components.*) US:=U; V:=SIL; 
      WHILE US <> SIL DO ADV(US, UL,US); VL:=MDHOM(ML,UL); 
            V:=COMP(VL,V); END; 
      V:=INV(V); RETURN(V); 
(*4*) END MDVHOM; 


PROCEDURE MIRAND(KL,QL,NL,ML: LIST): LIST; 
(*Matrix random. M is an integral matrix with n rows generated 
by IVRAND(k,q,m). *)
VAR  IL, M, V: LIST; 
BEGIN
(*1*) (*call ivrand.*) M:=SIL; 
      FOR IL:=1 TO NL DO V:=IVRAND(KL,QL,ML); M:=COMP(V,M); END; 
      M:=INV(M); RETURN(M); 
(*4*) END MIRAND; 


PROCEDURE POWSEV(PL,A: LIST): LIST; 
(*Power of variable symmetric product with exterior vector.
p is a beta-integer. A is an exterior vector. B is the
symmetric product of x**p and A.*)
VAR  AL, AS, B, IL, JL: LIST; 
BEGIN
(*1*) (*a=() or pl=0.*) 
      IF (PL = 0) OR (A = SIL) THEN B:=A; RETURN(B); END; 
(*2*) (*multiply.*) B:=SIL; AS:=A; 
      REPEAT ADV2(AS, AL,IL,AS); JL:=ILADDC(IL,PL); B:=COMP2(JL,AL,B); 
             UNTIL AS = SIL; 
      B:=INV(B); RETURN(B); 
(*5*) END POWSEV; 


PROCEDURE UIPRES(A,B: LIST;  VAR CL,KL: LIST); 
(*Univariate integral polynomials resultant. A and B are
univariate integral polynomials. c is the resultant of
A and B. k is the degree of the common factor. *)
VAR  AP, AS, BP, BS, C, D, DP, EL, IL, J1Y, LL, ML, NL, SL, TL:
     LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) CL:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN; END; 
(*2*) (*prepare.*) NL:=PDEG(A); ML:=PDEG(B); 
      IF NL >= ML THEN AP:=A; BP:=B; ELSE AP:=B; BP:=A; TL:=NL; 
         NL:=ML; ML:=TL; END; 
(*3*) (*initialise.*) LL:=NL-ML; KL:=ML; 
      IF LL = 0 THEN C:=LIST2(1,SIL); ELSE
         IF LL = 1 THEN C:=EIVFUP(BP,0); ELSE J1Y:=LL-1; 
            EL:=INDLST(0,J1Y); C:=UIPSIL(BP,EL); END; 
         END; 
      AS:=EIVFUP(AP,0); BS:=EIVFUP(BP,LL); D:=EIVEPR(AS,BS); 
(*4*) (*exterior multiplication loop.*) C:=EIVEPR(C,D); 
      IF C = SIL THEN RETURN; END; 
      FOR IL:=1 TO ML-1 DO DP:=POWSEV(IL,D); C:=EIVEPR(C,DP); KL:=KL-1; 
          IF C = SIL THEN RETURN; END; 
          END; 
(*5*) (*resultant not zero.*) CL:=FIRST(C); KL:=0; 
      IF MASODD(LL*ML+ML-1*ML DIV 2) THEN CL:=INEG(CL); END; 
(*8*) RETURN; END UIPRES; 

(*
PROCEDURE UIPRES(A,B: LIST;  VAR CL,KL: LIST); 
(*Univariate integral polynomials resultant. A and B are
univariate integral polynomials. c is the resultant of
A and B. k is the degree of the common factor. *)
VAR  AP, AS, BP, BS, C, CP, D, DP, EL, IL, J1Y, LL, ML, NL, SL, TL:
     LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) CL:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN; END; 
(*2*) (*prepare.*) NL:=PDEG(A); ML:=PDEG(B); 
      IF NL >= ML THEN AP:=A; BP:=B; ELSE AP:=B; BP:=A; TL:=NL; 
         NL:=ML; ML:=TL; END; 
(*3*) (*initialise.*) LL:=NL-ML; SL:=1; KL:=ML; 
      IF LL = 0 THEN C:=LIST2(1,SIL); ELSE
         IF LL = 1 THEN C:=EIVFUP(BP,0); ELSE J1Y:=LL-1; 
            EL:=INDLST(0,J1Y); C:=UIPSIL(BP,EL); END; 
         END; 
      AS:=EIVFUP(AP,0); BS:=EIVFUP(BP,LL); D:=EIVEPR(AS,BS); 
(*4*) (*exterior multiplication loop.*) CP:=C; C:=EIVEPR(C,D); 
      IF MASODD(LL) THEN SL:=-SL; END; 
      IF C = SIL THEN GO TO 5; END; 
      FOR IL:=1 TO ML-1 DO
          IF MASODD(IL+LL) THEN SL:=-SL; END; 
          KL:=KL-1; CP:=C; DP:=POWSEV(IL,D); C:=EIVEPR(C,DP); 
          IF C = SIL THEN GO TO 5; END; 
          END; 
(*5*) (*finish.*) 
      IF C <> SIL THEN CL:=FIRST(C); KL:=0; 
         IF SL < 0 THEN CL:=INEG(CL); END; 
         END; 
      RETURN; 
(*8*) END UIPRES; 
*)
(*
PROCEDURE UIPRES(A,B: LIST;  VAR CL,KL: LIST); 
(*Univariate integral polynomials resultant. A and B are
univariate integral polynomials. c is the resultant of
A and B. k is the degree of the common factor. *)
VAR  AP, BP, C, C1, C2, CP, EL, IL, J1Y, LL, ML, NL, SL, TL: LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) CL:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN; END; 
(*2*) (*prepare.*) NL:=PDEG(A); ML:=PDEG(B); 
      IF NL >= ML THEN AP:=A; BP:=B; ELSE AP:=B; BP:=A; TL:=NL; 
         NL:=ML; ML:=TL; END; 
(*3*) (*initialise.*) LL:=NL-ML; SL:=1; KL:=ML+1; 
      IF LL = 0 THEN C:=LIST2(1,SIL); ELSE
         IF LL = 1 THEN C:=EIVFUP(BP,0); ELSE J1Y:=LL-1; 
            EL:=INDLST(0,J1Y); C:=UIPSIL(BP,EL); END; 
         END; 
(*4*) (*exterior multiplication loop.*) 
      FOR IL:=0 TO ML-1 DO
          IF MASODD(IL) THEN SL:=-SL; END; 
          KL:=KL-1; CP:=C; C1:=EIVFUP(AP,IL); J1Y:=IL+LL; 
          C2:=EIVFUP(BP,J1Y); C:=EIVEPR(C1,C); C:=EIVEPR(C,C2); 
          IF C = SIL THEN GO TO 5; END; 
          END; 
(*5*) (*finish.*) 
      IF C <> SIL THEN CL:=FIRST(C); 
         IF SL < 0 THEN CL:=INEG(CL); END; 
         END; 
      RETURN; 
(*8*) END UIPRES; 
*)

PROCEDURE UIPRS1(A,B: LIST): LIST; 
(*Univariate integral polynomials resultant 1. A and B are
univariate integral polynomials. c is the resultant of
A and B. *)
VAR  C, C1, C2, CL, EM, EN, J1Y, ML, NL: LIST; 
BEGIN
(*1*) (*a=0 or b=0.*) CL:=0; 
      IF (A = 0) OR (B = 0) THEN RETURN(CL); END; 
(*2*) (*call exterior algorithms.*) ML:=PDEG(B); NL:=PDEG(A); 
      J1Y:=ML-1; EM:=INDLST(0,J1Y); J1Y:=NL-1; EN:=INDLST(0,J1Y); 
      C1:=UIPSIL(A,EM); C2:=UIPSIL(B,EN); C:=EIVEPR(C1,C2); 
      IF C = SIL THEN RETURN(CL); END; 
      ADV(C, CL,C); RETURN(CL); 
(*5*) END UIPRS1; 


PROCEDURE UIPSIL(A,EL: LIST): LIST; 
(*Univariate integral polynomial symmetric product with exterior index list. 
A is an univariate integral polynomial. e is an exterior index 
list. B is the symmetric product of A and e.*)
VAR  B, BP, FL, PL: LIST; 
BEGIN
(*1*) (*a=0 or el=(). *) 
      IF (A = 0) OR (EL = SIL) THEN B:=SIL; RETURN(B); END; 
(*2*) (*symmetic and antisymmetric multiplication.*) ADV(EL, PL,FL); 
      B:=EIVFUP(A,PL); 
      WHILE FL <> SIL DO ADV(FL, PL,FL); BP:=EIVFUP(A,PL); 
            B:=EIVEPR(B,BP); 
            IF B = SIL THEN RETURN(B); END; 
            END; 
      RETURN(B); 
(*5*) END UIPSIL; 


PROCEDURE UIPSIV(A,B: LIST): LIST; 
(*Univariate integral polynomial symmetric product with exterior integral vector. 
A is an univariate integral polynomial. B is an exterior integral 
vector. C is the symmetric product of A and B.*)
VAR  AL, BS, C, C1, EL: LIST; 
BEGIN
(*1*) (*a=0 or b=().*) C:=SIL; 
      IF (A = 0) OR (B = SIL) THEN RETURN(C); END; 
(*2*) (*multiply.*) BS:=B; 
      REPEAT ADV2(BS, AL,EL,BS); C1:=UIPSIL(A,EL); 
             IF C1 <> SIL THEN C1:=DIIPIP(C1,AL); C:=EIVSUM(C,C1); 
                END; 
             UNTIL BS = SIL; 
      RETURN(C); 
(*5*) END UIPSIV; 


END DIPE.
(* -EOF- *)
