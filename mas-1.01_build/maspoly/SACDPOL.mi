(* ----------------------------------------------------------------------------
 * $Id: SACDPOL.mi,v 1.3 1992/10/15 16:28:39 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACDPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:39  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:57  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:11  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACDPOL;

(* SAC Dense Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, SRED, SFIRST, 
                    FIRST, RED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT LIST2, COMP2, ADV2, FIRST2, 
                    CLOUT, CINV, RED2, SECOND, EQUAL;

FROM SACM    IMPORT MDDIF, MDINV, MDSUM, MDPROD;

FROM SACPOL  IMPORT PDEG;

CONST rcsidi = "$Id: SACDPOL.mi,v 1.3 1992/10/15 16:28:39 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE DMPPRD(RL,ML,A,B: LIST): LIST;
(*Dense modular polynomial product.  A and B are polynomials in r
variables over Z sub m, m a beta-integer, r ge 0.  C=A*B.*)
VAR  AL, AP, AS, BL, BP, BS, C, C1, CL, EL, FL, IL, JL, NL, RLP:
     LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=MDPROD(ML,A,B); RETURN(C); END;
(*3*) (*general case.*) ADV(A, EL,AP); ADV(B, FL,BP); AS:=CINV(AP);
      BS:=CINV(BP); C:=0; RLP:=RL-1;
      FOR IL:=0 TO FL DO C1:=BETA;
          FOR JL:=1 TO IL DO C1:=COMP(0,C1); END;
          AP:=AS; ADV(BS, BL,BS);
          FOR JL:=0 TO EL DO ADV(AP, AL,AP);
              IF RLP = 0 THEN CL:=MDPROD(ML,AL,BL); ELSE
                 CL:=DMPPRD(RLP,ML,AL,BL); END;
              C1:=COMP(CL,C1); END;
          NL:=EL+IL;
          WHILE (C1 <> SIL) AND (FIRST(C1) = 0) DO NL:=NL-1;
                C1:=RED(C1); END;
          IF C1 <> SIL THEN C1:=COMP(NL,C1); C:=DMPSUM(RL,ML,C1,C);
             END;
          END;
      RETURN(C);
(*6*) END DMPPRD;


PROCEDURE DMPSUM(RL,ML,A,B: LIST): LIST;
(*Dense modular polynomial sum.  A and B are dense polynomials in r
variables over Z sub m, m a beta-integer.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, EL, FL, IL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*general case.*) RLP:=RL-1;
      IF FIRST(A) >= FIRST(B) THEN ADV(A, EL,AP); ADV(B, FL,BP); ELSE
         ADV(B, EL,AP); ADV(A, FL,BP); END;
      C:=BETA;
      FOR IL:=1 TO EL-FL DO ADV(AP, AL,AP); C:=COMP(AL,C); END;
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP);
             IF RLP = 0 THEN CL:=MDSUM(ML,AL,BL); ELSE
                CL:=DMPSUM(RLP,ML,AL,BL); END;
             C:=COMP(CL,C);
             UNTIL AP = SIL;
(*3*) (*finish.*) C:=INV(C);
      WHILE (C <> SIL) AND (FIRST(C) = 0) DO C:=RED(C); EL:=EL-1;
      END;
      IF C = SIL THEN C:=0; ELSE C:=COMP(EL,C); END;
      RETURN(C);
(*6*) END DMPSUM;


PROCEDURE DMUPNR(PL,A,B: LIST): LIST;
(*Dense modular univariate polynomial natural remainder.  A and B are
non-zero dense univariate polynomials over Z sub p, p a prime
beta-integer, with deg(A) ge deg(B).  C is the natural remainder of B.
The list for A is modified.*)
VAR  AL, AP, APP, AS, BL, BLP, BP, BPP, BS, C, CL, KL, ML, NL:
     LIST;
BEGIN
(*1*) (*deg(b)=0.*) NL:=FIRST(B);
      IF NL = 0 THEN C:=0; RETURN(C); END;
(*2*) (*deg(b) positive.*) BP:=RED(B); ADV(BP, BL,BS);
      BLP:=MDINV(PL,BL); AS:=A;
      REPEAT ADV(AS, KL,AP); ML:=-1; ADV(AP, AL,APP);
             CL:=MDPROD(PL,AL,BLP); BPP:=BS;
             REPEAT ADV(BPP, BL,BPP); BL:=MDPROD(PL,BL,CL);
                    AL:=FIRST(APP); AL:=MDDIF(PL,AL,BL); KL:=KL-1;
                    IF (ML < 0) AND (AL <> 0) THEN ML:=KL; AS:=AP;
                       END;
                    SFIRST(APP,AL); AP:=APP; APP:=RED(AP);
                    UNTIL BPP = SIL;
             WHILE (ML < 0) AND (APP <> SIL) DO KL:=KL-1;
                   IF FIRST(APP) <> 0 THEN ML:=KL; AS:=AP; END;
                   AP:=APP; APP:=RED(AP); END;
             IF ML >= 0 THEN SFIRST(AS,ML); END;
             UNTIL ML < NL;
      IF ML >= 0 THEN C:=AS; ELSE C:=0; END;
      RETURN(C);
(*5*) END DMUPNR;


PROCEDURE DPFP(RL,A: LIST): LIST;
(*Dense polynomial from polynomial.  A is a polynomial in r
variables, r ge 0.  B is the result of converting A to dense
polynomial representation.*)
VAR  AP, B, BL, J1Y, KL, NL, RLP: LIST;
BEGIN
(*1*) IF (A = 0) OR (RL = 0) THEN B:=A; RETURN(B); END;
      NL:=PDEG(A); RLP:=RL-1; B:=BETA; AP:=A;
      FOR KL:=NL TO 0 BY -1 DO
          IF (AP = SIL) OR (FIRST(AP) < KL) THEN BL:=0; ELSE
             AP:=RED(AP); ADV(AP, BL,AP);
             IF RLP > 0 THEN BL:=DPFP(RLP,BL); END;
             END;
          B:=COMP(BL,B); END;
      J1Y:=INV(B); B:=COMP(NL,J1Y); RETURN(B);
(*4*) END DPFP;


END SACDPOL.

(* -EOF- *)
