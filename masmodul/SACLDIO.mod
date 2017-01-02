(* ----------------------------------------------------------------------------
 * $Id: SACLDIO.mi,v 1.3 1992/10/15 16:29:18 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACLDIO.mi,v $
 * Revision 1.3  1992/10/15  16:29:18  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:12  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:53  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACLDIO;

(* SAC Linear Diophantine Equation System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMAX, MASEVEN;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    LIST1, SFIRST, SRED, LENGTH, INV, 
                    FIRST, RED, COMP, ADV;

FROM MASERR IMPORT ERROR, severe; 

FROM MASBIOS IMPORT SWRITE;

FROM SACLIST IMPORT LIST3, CONC, CINV, ADV2, COMP2, FIRST2, 
                    LELT, LIST4, LEINST, LEROT, REDUCT,
                    EQUAL, RED2, SECOND, LIST2;

FROM SACD IMPORT DLOG2;

FROM SACI IMPORT ILOG2, IDEGCD, IODD, IREM, IDP2, ICOMP, IPROD, IQ, 
                 ISUM, ISIGNF, IDREM, IDPR, IDIF, IMP2, INEG;

FROM SACM IMPORT MDHOM, MDDIF, MDSUM, MDNEG, MDPROD, MDINV, MIHOM, 
                 MIPROD, SMFMI;

FROM SACPRIM IMPORT SMPRM;

FROM SACCOMB IMPORT ASSPR;

FROM SACPOL IMPORT PDEGSV, PINV, PDEG, PRIME;

FROM SACIPOL IMPORT IPSUM, IPDIF, IPNEG, 
                    IPPROD, IPQ, IPCRA, IPSUMN;

FROM SACMPOL IMPORT MPPROD, MPINT, VMPIP, MPEMV, MPHOM, MPEVAL;

CONST rcsidi = "$Id: SACLDIO.mi,v 1.3 1992/10/15 16:29:18 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE LDSMKB(A,BL: LIST;  VAR XLS,N: LIST); 
(*Linear diophantine system solution, modified Kannan and Bachem algorithm.  
A is an m by n integral matrix.  A is represented
column-wise.  b is an integral m-vector.  If the diophantine
system A*x=b is consistent, then xs is a particular
solution and N is a list of basis vectors of the solution
module of A*x=0.  Otherwise, xs and N are null lists.  A and b are
modified.*)
VAR  B, C, C1, CL, CP, CP1, CS, CS1, HL, IL, J1Y, JL, KL, ML, NL, R,
     RL, RP, T: LIST; 
BEGIN
(*1*) (*adjoin identity matrix to a and zero vector to -bl.*) 
      NL:=LENGTH(A); C:=MIAIM(A); J1Y:=VINEG(BL); B:=VIAZ(J1Y,NL); 
(*2*) (*initialize.*) ML:=LENGTH(BL); C1:=FIRST(C); JL:=0; 
      REPEAT JL:=JL+1; ADV(C1, CL,C1); 
             UNTIL CL <> 0; 
      R:=LIST1(JL); 
      IF JL <= ML THEN RL:=1; ELSE RL:=0; END; 
      KL:=1; 

WHILE KL < NL DO (*if nl = 1 then go to 5; end;*) 

(*3*) (*eliminate column kl+1 and augment row-sequence.*) 
      CS:=REDUCT(C,KL); CS1:=FIRST(CS); CP:=C; RP:=R; 
LOOP
      FOR HL:=1 TO KL+1 DO
          IF HL <= KL THEN ADV(RP, IL,RP); ELSE J1Y:=ML+NL; 
             IL:=J1Y+1; END; 
          CP1:=CS1; JL:=0; 
          REPEAT JL:=JL+1; ADV(CP1, CL,CP1); 
                 UNTIL CL <> 0; 
          IF JL >= IL THEN
             IF JL = IL THEN C1:=FIRST(CP); VIUT(C1,CS1,IL,
                C1,CS1); SFIRST(CP,C1); END; 
             CP:=RED(CP); ELSE SFIRST(CS,CS1); J1Y:=KL+1; 
             C:=LEROT(C,HL,J1Y); J1Y:=HL-1; R:=LEINST(R,J1Y,JL); 
             IF JL <= ML THEN RL:=RL+1; END; 
             EXIT (*go to 4;*) END; 
          END; 
      EXIT END;

(*4*) (*normalize off-diagonal elements.*) 
      FOR JL:=HL TO 1 BY -1 DO J1Y:=JL-1; CS:=REDUCT(C,J1Y); ADV(CS,
          T,CP); RP:=REDUCT(R,JL); 
          WHILE RP <> SIL DO ADV(CP, CP1,CP); ADV(RP, IL,RP); 
                T:=VIERED(T,CP1,IL); END; 
          SFIRST(CS,T); END; 
      KL:=KL+1; 
      END; (*if kl < nl then go to 3; end;*) 

(*5*) (*check consistency of the system.*) 
      FOR JL:=1 TO RL DO ADV(C, T,C); ADV(R, IL,R); B:=VIERED(B,T,IL); 
          END; 
      JL:=0; 
      REPEAT JL:=JL+1; ADV(B, CL,B); 
             UNTIL (JL = ML) OR (CL <> 0); 
(*6*) (*system consistent.*) 
      IF CL = 0 THEN CP:=C; 
         WHILE CP <> SIL DO CP1:=FIRST(CP); CP1:=REDUCT(CP1,ML); 
               SFIRST(CP,CP1); CP:=RED(CP); END; 
         XLS:=B; N:=C; RETURN; END; 
(*7*) (*system inconsistent.*) XLS:=BETA; N:=BETA; RETURN; 
(*10*) END LDSMKB; 


PROCEDURE LDSSBR(A,BL: LIST;  VAR XLS,N: LIST); 
(*Linear diophantine system solution, based on Rosser ideas.  A is an
m by n integral matrix.  A is represented column-wise.  b is
an integral m-vector.  If the diophantine system A*x=b
is consistent, then xs is a particular solution and N is
a list of basis vectors of the solution module of A*x=0.  Otherwise,
xs and N are null lists.  A and b are modified.*)
VAR  B, BL1, C, C1, C2, CP, J1Y, ML, NL, SL: LIST; 
BEGIN
(*1*) (*initialize.*) NL:=LENGTH(A); ML:=LENGTH(BL); 
(*2*) (*adjoin identity matrix to a and zero vector to -bl.*) 
      C:=MIAIM(A); J1Y:=VINEG(BL); B:=VIAZ(J1Y,NL); 
LOOP
(*3*) (*sort columns of c.*) C:=MINNCT(C); C:=MICS(C); 
(*4*) (*pivot row zero.*) C1:=FIRST(C); 
      IF FIRST(C1) <> 0 THEN (*= go to 6;*) 

(*5*) (*eliminate pivot row.*) 
      REPEAT B:=VIERED(B,C1,1); C:=RED(C); 
             IF C = SIL THEN SL:=0; ELSE C2:=FIRST(C); 
                SL:=FIRST(C2); 
                IF SL <> 0 THEN C1:=VIERED(C1,C2,1); 
                   C:=MICINS(C,C1); C1:=C2; END; 
                END; 
             UNTIL SL = 0; 
      NL:=NL-1; 

      END; 
LOOP
(*6*) (*system inconsistent.*) ADV(B, BL1,B); 
      IF BL1 <> 0 THEN XLS:=BETA; N:=BETA; RETURN; END; 

(*7*) (*remove pivot row.*) CP:=C; 
      WHILE CP <> SIL DO C1:=FIRST(CP); C1:=RED(C1); SFIRST(CP,C1); 
            CP:=RED(CP); END; 
      ML:=ML-1; 

(*8*) (*finished.*) 
      IF ML > 0 THEN
         IF NL > 0 THEN EXIT (*go to 3;*) (*else go to 6;*) END; 
         END; 

      END; (*go to 6*) 

      IF ML <= 0 THEN EXIT END;
      
      END; (*go to 3*)

      XLS:=B; N:=C; RETURN; 
(*9*) END LDSSBR; 


PROCEDURE MAIPDE(RL,M: LIST): LIST; 
(*Matrix of integral polynomials determinant, exact division algorithm.
M is a square matrix of integral polynomials in r variables, r ge 0,
represented as a list.  D is the determinant of M.*)
VAR  D, IL, J1Y, J2Y, JL, M1, M2, MP1, P, R, R1, R2, RP, S, S1, S2, SS,
     SS2, TL: LIST; 
BEGIN
(*1*) (*initialize.*) M1:=M; P:=0; TL:=1; 
LOOP
(*2*) (*order 1 matrix.*) 
      IF RED(M1) = SIL THEN J1Y:=FIRST(M1); D:=FIRST(J1Y); 
         IF TL < 0 THEN D:=IPNEG(RL,D); END; 
         RETURN(D); END; 
(*3*) (*find pivot row, if possible.*) MP1:=M1; IL:=0; 
      REPEAT IL:=IL+1; ADV(MP1, R,MP1); 
             UNTIL (FIRST(R) <> 0) OR (MP1 = SIL); 
(*4*) (*no pivot row.*) 
      IF FIRST(R) = 0 THEN D:=0; RETURN(D); END; 
(*5*) (*update sign.*) 
      IF MASEVEN(IL) THEN TL:=-TL; END; 
(*6*) (*compute m2.*) ADV(R, R1,R); M2:=BETA; JL:=0; 
      REPEAT JL:=JL+1; ADV(M1, S,M1); 
             IF JL <> IL THEN ADV(S, S1,S); SS:=BETA; RP:=R; 
                REPEAT ADV(RP, R2,RP); ADV(S, S2,S); 
                       J1Y:=IPPROD(RL,R1,S2); J2Y:=IPPROD(RL,S1,R2); 
                       SS2:=IPDIF(RL,J1Y,J2Y); 
                       IF P <> 0 THEN SS2:=IPQ(RL,SS2,P); END; 
                       SS:=COMP(SS2,SS); 
                       UNTIL RP = SIL; 
                M2:=COMP(SS,M2); END; 
             UNTIL M1 = SIL; 
(*7*) (*prepare for next pivot step.*) P:=R1; M1:=M2; 
      END; (*go to 2;*) 
(*9*) RETURN(D); END MAIPDE; 


PROCEDURE MAIPDM(RL,M: LIST): LIST; 
(*Matrix of integral polynomials determinant, modular algorithm.  M is
a square matrix of integral polynomials in r variables, r non-negative.
D is the determinant of M.*)
VAR  BL, BLP, D, DS, J1Y, KL, M1, M11, MP, MS, N, N1, N11, NL, P, PL,
     PLP, Q, X: LIST; 
BEGIN
(*1*) (*matrix of order 1.*) 
      IF RED(M) = SIL THEN J1Y:=FIRST(M); D:=FIRST(J1Y); RETURN(D); 
         END; 
(*2*) (*compute norm bound.*) MP:=M; N:=BETA; 
      REPEAT ADV(MP, M1,MP); N1:=BETA; 
             REPEAT ADV(M1, M11,M1); N11:=IPSUMN(RL,M11); 
                    N11:=ILOG2(N11); N1:=COMP(N11,N1); 
                    UNTIL M1 = SIL; 
             N:=COMP(N1,N); 
             UNTIL MP = SIL; 
      ASSPR(N, X,BL); NL:=LENGTH(M); KL:=DLOG2(NL); J1Y:=NL*KL; 
      BL:=J1Y+BL; 
(*3*) (*apply chinese remainder theorem.*) P:=PRIME; Q:=1; 
      BLP:=0; D:=0; 
      REPEAT IF P = SIL THEN
                ERROR(severe,"prime list exhausted in MAIPDM."); 
                RETURN(D) END; 
             ADV(P, PL,P); MS:=MAIPHM(RL,PL,M); DS:=MMPDMA(RL,PL,MS); 
             J1Y:=MDHOM(PL,Q); PLP:=MDINV(PL,J1Y); 
             D:=IPCRA(Q,PL,PLP,RL,D,DS); Q:=IDPR(Q,PL); J1Y:=DLOG2(PL); 
             BLP:=BLP+J1Y; 
             UNTIL BLP >= BL; 
      RETURN(D); 
(*6*) END MAIPDM; 


PROCEDURE MAIPHM(RL,ML,A: LIST): LIST; 
(*Matrix of integral polynomials homomorphism.  A is a matrix of
integral polynomials in r variables, r non-negative.  m is a
positive beta-integer.  B is the matrix B(i,j) of polynomials in r
variables  over Z sub m such that B(i,j)=H(m)(A(i,j)).*)
VAR  A1, A11, AP, B, B1, B11: LIST; 
BEGIN
(*1*) AP:=A; B:=BETA; 
      REPEAT ADV(AP, A1,AP); B1:=BETA; 
             REPEAT ADV(A1, A11,A1); B11:=MPHOM(RL,ML,A11); 
                    B1:=COMP(B11,B1); 
                    UNTIL A1 = SIL; 
             B1:=INV(B1); B:=COMP(B1,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*4*) END MAIPHM; 


PROCEDURE MAIPP(RL,A,B: LIST): LIST; 
(*Matrix of integral polynomials product.  A and B are matrices of
integral polynomials in r variables, r ge 0, for which the matrix
product A*B is defined.  C=A*B.*)
VAR  A1, A11, AP, AP1, B1, B11, BP, BS, C, C1, C11, J1Y: LIST; 
BEGIN
(*1*) C:=BETA; AP:=A; 
      REPEAT ADV(AP, A1,AP); BP:=B; C1:=BETA; 
             REPEAT C11:=0; BS:=BETA; AP1:=A1; 
                    REPEAT ADV(AP1, A11,AP1); ADV(BP, B1,BP); ADV(B1,
                           B11,B1); J1Y:=IPPROD(RL,A11,B11); 
                           C11:=IPSUM(RL,C11,J1Y); BS:=COMP(B1,BS); 
                           UNTIL BP = SIL; 
                    BP:=INV(BS); C1:=COMP(C11,C1); 
                    UNTIL FIRST(BP) = SIL; 
             C1:=INV(C1); C:=COMP(C1,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*4*) END MAIPP; 


PROCEDURE MIAIM(A: LIST): LIST; 
(*Matrix of integers, adjoin identity matrix,  A is an m by n matrix
of integers.  A is represented column-wise.  B is the matrix obtained
by adjoining an n by n identity matrix to the bottom of A.  A is
modified.*)
VAR  A1, AP, B, IL, JL, NL, T: LIST; 
BEGIN
(*1*) NL:=LENGTH(A); AP:=INV(A); B:=BETA; 
      FOR IL:=1 TO NL DO ADV(AP, A1,AP); T:=BETA; 
          FOR JL:=1 TO NL DO
              IF IL = JL THEN T:=COMP(1,T); ELSE T:=COMP(0,T); END; 
              END; 
          A1:=CONC(A1,T); B:=COMP(A1,B); END; 
      RETURN(B); 
(*4*) END MIAIM; 


PROCEDURE MICINS(A,V: LIST): LIST; 
(*Matrix of integers column insertion.  A is an m by n integral
matrix represented by the list (a(1),a(2), ...,a(n)), where a(i) is the
list (a(1,i), ...,a(m,i)) representing column i of A and a(1,1)
ge a(1,2) ge  ... ge a(1,m).  V=(v(1), ...,v(m)) is an integral
vector with v(1) lt a(1,1). Let i be the largest integer such that
a(1,i) ge v(1).  Then B is the matrix represented by the list (a(1), ...,
a(i),V,a(i+1), ...,a(n)).  A is modified.*)
VAR  AP, APP, B, VL: LIST; 
BEGIN
(*1*) (*initialize.*) AP:=A; APP:=RED(AP); VL:=FIRST(V); 
(*2*) (*loop.*) 
      WHILE (APP <> SIL) AND (ICOMP(FIRST(FIRST(APP)),VL) >= 0)
            DO AP:=APP; APP:=RED(APP); END; 
(*3*) (*finish.*) B:=COMP(V,APP); SRED(AP,B); B:=A; RETURN(B); 
(*6*) END MICINS; 


PROCEDURE MICS(A: LIST): LIST; 
(*Matrix of integers column sort.  A is an integral matrix with non-
negative elements in first row.  A is represented column-wise.  B is an
integral matrix obtained by sorting columns of A such that elements
of the first row are in descending order.  A is modified.*)
VAR  A1, A2, AL1, AL2, AP, APP, B, SL: LIST; 
BEGIN
(*1*) (*bubble sort columns.*) 
      REPEAT AP:=A; SL:=0; 
             WHILE RED(AP) <> SIL DO ADV(AP, A1,APP); 
                   A2:=FIRST(APP); AL1:=FIRST(A1); AL2:=FIRST(A2); 
                   IF ICOMP(AL1,AL2) < 0 THEN SFIRST(AP,A2); 
                      SFIRST(APP,A1); SL:=1; END; 
                   AP:=APP; END; 
             UNTIL SL = 0; 
      B:=A; RETURN(B); 
(*4*) END MICS; 


PROCEDURE MINNCT(A: LIST): LIST; 
(*Matrix of integers, non-negative column transformation.
A=(a(i,j)) is an m by n integral matrix.  A is represented
column-wise. B=(b(i,j)) is the m by n integral matrix
with b(i,j)=a(i,j) if a(1,j) ge 0 and b(i,j)=-a(i,j) if
a(1,j) lt 0.  A is modified.*)
VAR  A1, AL, AP, B: LIST; 
BEGIN
(*1*) B:=A; AP:=A; 
      REPEAT A1:=FIRST(AP); AL:=FIRST(A1); 
             IF ISIGNF(AL) < 0 THEN A1:=VINEG(A1); SFIRST(AP,A1); 
                END; 
             AP:=RED(AP); 
             UNTIL AP = SIL; 
      RETURN(B); 
(*4*) END MINNCT; 


PROCEDURE MMDDET(PL,M: LIST): LIST; 
(*Matrix of modular digits determinant.  p is a prime beta-integer.
M is a square matrix over GF(p), represented as a list.  d is the
determinant of M.*)
VAR  AL, ALP, DL, IL, J1Y, JL, M1, M2, MP1, R, R1, R2, RP, RS, S, S1,
     S2, SS: LIST; 
BEGIN
(*1*) (*initialize.*) M1:=M; DL:=1; 
LOOP
(*2*) (*order 1 matrix.*) 
      IF RED(M1) = SIL THEN J1Y:=FIRST(M1); AL:=FIRST(J1Y); 
         DL:=MDPROD(PL,DL,AL); RETURN(DL); END; 
(*3*) (*find pivot row, if possible.*) MP1:=M1; IL:=0; 
      REPEAT IL:=IL+1; ADV(MP1, R,MP1); 
             UNTIL (FIRST(R) <> 0) OR (MP1 = SIL); 
(*4*) (*no pivot row.*) 
      IF FIRST(R) = 0 THEN DL:=0; RETURN(DL); END; 
(*5*) (*transform pivot row.*) ADV(R, AL,R); DL:=MDPROD(PL,DL,AL); 
      IF MASEVEN(IL) THEN DL:=MDNEG(PL,DL); END; 
      ALP:=MDINV(PL,AL); RS:=BETA; 
      REPEAT ADV(R, R1,R); R1:=MDPROD(PL,R1,ALP); RS:=COMP(R1,RS); 
             UNTIL R = SIL; 
      R:=INV(RS); 
(*6*) (*compute m2.*) M2:=BETA; JL:=0; 
      REPEAT JL:=JL+1; ADV(M1, S,M1); 
             IF JL <> IL THEN ADV(S, S1,S); SS:=BETA; RP:=R; 
                REPEAT ADV(RP, R2,RP); ADV(S, S2,S); 
                       J1Y:=MDPROD(PL,S1,R2); S2:=MDDIF(PL,S2,J1Y); 
                       SS:=COMP(S2,SS); 
                       UNTIL RP = SIL; 
                M2:=COMP(SS,M2); END; 
             UNTIL M1 = SIL; 
(*7*) (*prepare for next pivot step.*) M1:=M2; 
      END; (*go to 2;*) 
(*9*) RETURN(DL); END MMDDET; 


PROCEDURE MMDNSB(PL,M: LIST): LIST; 
(*Matrix of modular digits null space basis.  p is a prime beta-
integer.  M is an m by n matrix over Z sub p.  B is a list (b(1), ...,
b(r)) representing a basis for the null space of M, consisting of all
x such that M*x=0.  r is the dimension of the null space.  B=() if
the null space of M is 0.  Each b(i) is a list representing an
m-vector.  M is modified.  Alternatively, if M represents a matrix by
columns, then B is a basis for the null space consisting of all x such
that x*M=0.*)
VAR  AL, B, C, CL, CP, IL, J1Y, KL, M1, M2, ML, MP1, MP2, V, VL, VP:
     LIST; 
BEGIN
(*1*) (*initialize.*) M1:=M; M2:=BETA; B:=BETA; KL:=1; J1Y:=FIRST(M); 
      ML:=LENGTH(J1Y); 
LOOP 
(*2*) (*search for a pivot column.*) MP1:=M1; M1:=BETA; AL:=0; 
      LOOP 
           IF MP1 = SIL THEN EXIT END; (*while mp1 <> sil do*) 
           ADV(MP1, C,MP1); ADV(C, AL,C); 
           IF AL <> 0 THEN EXIT (*go to 4;*) END; 
           M1:=COMP(C,M1);  
           END; 

IF (MP1 = SIL) AND (AL = 0) THEN  
(*3*) (*generate a basis vector.*) V:=BETA; 
      FOR IL:=1 TO ML-KL DO V:=COMP(0,V); END; 
      V:=COMP(1,V); MP2:=M2; 
      WHILE MP2 <> SIL DO ADV(MP2, C,MP2); AL:=VMPIP(0,PL,C,V); 
            V:=COMP(AL,V); END; 
      B:=COMP(V,B); M2:=COMP(0,M2); 

      (*go to 5;*) ELSE 
(*4*) (*perform pivot operations.*) M2:=COMP(C,M2); J1Y:=MDINV(PL,AL); 
      AL:=PL-J1Y; CP:=C; 
      WHILE CP <> SIL DO J1Y:=FIRST(CP); CL:=MDPROD(PL,J1Y,AL); 
            SFIRST(CP,CL); CP:=RED(CP); END; 
      WHILE MP1 <> SIL DO ADV(MP1, VP,MP1); ADV(VP, VL,VP); 
            M1:=COMP(VP,M1); 
            IF VL <> 0 THEN CP:=C; 
               WHILE CP <> SIL DO ADV(CP, CL,CP); 
                     AL:=MDPROD(PL,CL,VL); J1Y:=FIRST(VP); 
                     AL:=MDSUM(PL,J1Y,AL); SFIRST(VP,AL); VP:=RED(VP); 
                     END; 
               END; 
            END; 
END;
(*5*) (*finish.*) 
      IF KL >= ML THEN (*<*) EXIT END; 
      KL:=KL+1; 
      END; (*go to 2;*) (*else return(b); end;*) 

(*8*) RETURN(B); END MMDNSB; 


PROCEDURE MMPDMA(RL,PL,M: LIST): LIST; 
(*Matrix of modular polynomials determinant, modular algorithm.  M is a
square matrix of modular polynomials in r variables over Z sub p,
r non-negative, p a prime beta-integer.  D is the determinant of M.*)
VAR  AL, B, BL, BLP, D, DL, DS, J1Y, M1, M11, MP, MS, N, N1, N11, 
     RLP, X: LIST; 
BEGIN
(*1*) (*matrix of order 1.*) 
      IF RED(M) = SIL THEN J1Y:=FIRST(M); D:=FIRST(J1Y); RETURN(D); 
         END; 
(*2*) (*rl=0.*) 
      IF RL = 0 THEN D:=MMDDET(PL,M); RETURN(D); END; 
(*3*) (*compute degree bound.*) MP:=M; N:=BETA; 
      REPEAT ADV(MP, M1,MP); N1:=BETA; 
             REPEAT ADV(M1, M11,M1); N11:=PDEGSV(RL,M11,1); 
                    N1:=COMP(N11,N1); 
                    UNTIL M1 = SIL; 
             N:=COMP(N1,N); 
             UNTIL MP = SIL; 
      ASSPR(N, X,DL); 
(*4*) (*apply evaluation and interpolation.*) AL:=0; RLP:=RL-1; 
      B:=PINV(0,1,1); 
      REPEAT IF AL = PL THEN
                ERROR(severe,"elements of finite field exhausted in MMPDMA."); 
                RETURN(D); END; 
             MS:=MMPEV(RL,PL,M,1,AL); DS:=MMPDMA(RLP,PL,MS); 
             BL:=MPEMV(1,PL,B,AL); BLP:=MDINV(PL,BL); 
             D:=MPINT(PL,B,AL,BLP,RL,D,DS); J1Y:=MDNEG(PL,AL); 
             X:=LIST4(1,1,0,J1Y); B:=MPPROD(1,PL,B,X); AL:=AL+1; 
             UNTIL PDEG(B) > DL; 
      RETURN(D); 
(*7*) END MMPDMA; 


PROCEDURE MMPEV(RL,ML,A,KL,AL: LIST): LIST; 
(*Matrix of modular polynomials evaluation.  A is a matrix of
polynomials in r variables over Z sub m, m a positive beta-integer.
1 le k le r and a is an element of Z sub m.  B is the matrix of
polynomials b(i,j) where b(i,j)(x(1), ...,x(k-1),x(k+1), ...,x(r))=
a(i,j)(x(1), ...,x(k-1),a,x(k+1), ...,x(r)).*)
VAR  A1, A11, AP, B, B1, B11: LIST; 
BEGIN
(*1*) AP:=A; B:=BETA; 
      REPEAT ADV(AP, A1,AP); B1:=BETA; 
             REPEAT ADV(A1, A11,A1); B11:=MPEVAL(RL,ML,A11,KL,AL); 
                    B1:=COMP(B11,B1); 
                    UNTIL A1 = SIL; 
             B1:=INV(B1); B:=COMP(B1,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*4*) END MMPEV; 


PROCEDURE VIAZ(A,NL: LIST): LIST; 
(*Vector of integers, adjoin zeros.  A is the vector (a(1), ...,a(m)).
n is a non-negative beta-integer.  B is the vector (a(1), ...,a(m),
0, ...,0) of m+n components.  A is modified.*)
VAR  B, KL: LIST; 
BEGIN
(*1*) B:=BETA; 
      FOR KL:=1 TO NL DO B:=COMP(0,B); END; 
      B:=CONC(A,B); RETURN(B); 
(*4*) END VIAZ; 


PROCEDURE VIDIF(A,B: LIST): LIST; 
(*Vector of integers difference.  A and B are vectors in Z sup n.
C=A-B.*)
VAR  C, J1Y: LIST; 
BEGIN
(*1*) J1Y:=VINEG(B); C:=VISUM(A,J1Y); RETURN(C); 
(*4*) END VIDIF; 


PROCEDURE VIERED(U,V,IL: LIST): LIST; 
(*Vector of integers, element reduction.  U=(u(1), ...,u(n)) and
V=(v(1), ...,v(n)) are integral n-vectors.  1 le i le n.  v(i)
ne 0.  W=U-q*V, where q=INTEGER(u(i)/v(i)).*)
VAR  QL, UL, VL, W: LIST; 
BEGIN
(*1*) UL:=LELT(U,IL); VL:=LELT(V,IL); QL:=IQ(UL,VL); 
      IF QL = 0 THEN W:=U; ELSE QL:=INEG(QL); W:=VISPR(QL,V); 
         W:=VISUM(U,W); END; 
      RETURN(W); 
(*4*) END VIERED; 


PROCEDURE VILCOM(AL,BL,A,B: LIST): LIST; 
(*Vector of integers linear combination.  a and b are integers.  A
and B are integral vectors in Z sup n.  C=a*A+b*B.*)
VAR  C, S, T: LIST; 
BEGIN
(*1*) S:=VISPR(AL,A); T:=VISPR(BL,B); C:=VISUM(S,T); RETURN(C); 
(*4*) END VILCOM; 


PROCEDURE VINEG(A: LIST): LIST; 
(*Vector of integers negation.  A is an integral vector.  B=-A.*)
VAR  AL, AP, B, BL: LIST; 
BEGIN
(*1*) B:=BETA; AP:=A; 
      REPEAT ADV(AP, AL,AP); BL:=INEG(AL); B:=COMP(BL,B); 
             UNTIL AP = SIL; 
      B:=INV(B); RETURN(B); 
(*4*) END VINEG; 


PROCEDURE VISPR(AL,A: LIST): LIST; 
(*Vector of integers scalar product.  a is an integer.  A is an
integral vector.  C=a*A.*)
VAR  ALP, AP, C, CL, IL, NL: LIST; 
BEGIN
(*1*) (*al=0.*) 
      IF AL = 0 THEN NL:=LENGTH(A); C:=BETA; 
         FOR IL:=1 TO NL DO C:=COMP(0,C); END; 
         RETURN(C); END; 
(*2*) (*al=1.*) 
      IF AL = 1 THEN C:=A; RETURN(C); END; 
(*3*) (*al=-1.*) 
      IF AL = -1 THEN C:=VINEG(A); RETURN(C); END; 
(*4*) (*general case.*) C:=BETA; AP:=A; 
      REPEAT ADV(AP, ALP,AP); CL:=IPROD(AL,ALP); C:=COMP(CL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*7*) END VISPR; 


PROCEDURE VISUM(A,B: LIST): LIST; 
(*Vector of integers sum.  A and B are vectors in Z sup n.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) C:=BETA; AP:=A; BP:=B; 
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP); CL:=ISUM(AL,BL); 
             C:=COMP(CL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*4*) END VISUM; 


PROCEDURE VIUT(U,V,IL: LIST;  VAR UP,VP: LIST); 
(*Vector of integers, unimodular transformation.  U=(u(1), ...,u(n))
and V=(v(1), ...,v(n)) are vectors in Z sup n with u(i) ne 0.
(UP,VP)=(U,V)*K where K is a unimodular matrix, depending on u(i)
and v(i), whose elements are obtained from IDEGCD.*)
VAR  CL, PL, QL, RL, SL, UL, VL: LIST; 
BEGIN
(*1*) UL:=LELT(U,IL); VL:=LELT(V,IL); IDEGCD(UL,VL, CL,PL,QL,RL,SL); 
      UP:=VILCOM(PL,QL,U,V); VP:=VILCOM(RL,SL,U,V); RETURN; 
(*4*) END VIUT; 


END SACLDIO.
(* -EOF- *)
