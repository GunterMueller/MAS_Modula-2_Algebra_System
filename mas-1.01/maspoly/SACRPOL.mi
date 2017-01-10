(* ----------------------------------------------------------------------------
 * $Id: SACRPOL.mi,v 1.3 1992/10/15 16:28:44 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACRPOL.mi,v $
 * Revision 1.3  1992/10/15  16:28:44  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:05  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:20  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACRPOL;

(* SAC Rational Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASMIN, MASMAX;

FROM MASSTOR IMPORT LIST, SIL, BETA,
                    FIRST, RED, SRED, COMP, INV, ADV, LIST1;

FROM SACLIST IMPORT AREAD, LIST2, COMP2, ADV2, 
                    SUFFIX, CLOUT, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT CREAD, CREADB, CWRITE, 
                    BKSP, DIBUFF, LETTER, DIGIT, 
                    MASORD, BLINES, SWRITE;

FROM SACI    IMPORT IWRITE;

FROM SACRN   IMPORT RNWRIT, RNREAD, RNSUM, RNQ, RNPROD, 
                    RNSIGN, RNINT, RNDIF, RNNEG;

FROM SACPOL  IMPORT VREAD, PDEG, PLDCF, PRED; 

CONST rcsidi = "$Id: SACRPOL.mi,v 1.3 1992/10/15 16:28:44 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE RPDIF(RL,A,B: LIST): LIST;
(*Rational polynomial difference.  A and B are rational polynomials in
r variables, r ge 0.  C=A-B.*)
VAR  AL, AP, BL, BP, C, CL, CP, CPP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF A = 0 THEN C:=RPNEG(RL,B); RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=RNDIF(A,B); RETURN(C); END;
(*3*) (*general case.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=RNNEG(BL); ELSE
                      CL:=RPNEG(RLP,BL); END;
                   CP:=COMP2(CL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=RNDIF(AL,BL); ELSE
                      CL:=RPDIF(RLP,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF (AP = SIL) AND (BP = SIL) THEN CPP:=BETA; ELSE
         IF AP = SIL THEN CPP:=RPNEG(RL,BP); ELSE CPP:=AP; END;
         END;
      C:=INV(CP);
      IF C = SIL THEN C:=CPP; ELSE SRED(CP,CPP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END RPDIF;


PROCEDURE RPEMV(RL,A,BL: LIST): LIST;
(*Rational polynomial evaluation, main variable.  A is a rational
polynomial in r variables, r gt 0.  b is a rational number.
C(x(1), ...,x(r-1))=A(x(1), ...,x(r-1),b).*)
VAR  AL, AP, C, EL, ELP, IL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN C:=0; RETURN(C); END;
(*2*) (*horner method.*) AP:=A; C:=0; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF AP = SIL THEN ELP:=0; ELSE ELP:=FIRST(AP); END;
             C:=RPSUM(RLP,C,AL);
             FOR IL:=1 TO EL-ELP DO C:=RPRNP(RLP,BL,C); END;
             UNTIL AP = SIL;
      RETURN(C);
(*5*) END RPEMV;


PROCEDURE RPFIP(RL,A: LIST): LIST;
(*Rational polynomial from integral polynomial.  A is an integral
polynomial in r variables, r ge 0.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=RNINT(A); RETURN(B); END;
(*3*) (*recursion on rl.*) B:=BETA; AP:=A; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP); BL:=RPFIP(RLP,AL); B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END RPFIP;


PROCEDURE RPIMV(RL,A: LIST): LIST;
(*Rational polynomial integration, main variable.  A is a rational
polynomial in r variables, r gt 0.  B is the integral of A with
respect to its main variable.  The constant of integration is 0.*)
VAR  AL, AP, B, BL, EL, ELP, ELS, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*a ne 0.*) AP:=A; RLP:=RL-1; B:=BETA;
      REPEAT ADV2(AP, EL,AL,AP); ELP:=EL+1; ELS:=LIST2(1,ELP);
             BL:=RPRNP(RLP,ELS,AL); B:=COMP2(BL,ELP,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*5*) END RPIMV;


PROCEDURE RPNEG(RL,A: LIST): LIST;
(*Rational polynomial negative.  A is an rational polynomial in r
variables, r ge 0.  B=-A.*)
VAR  AL, AP, B, BL, EL, RLP: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=0; RETURN(B); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN B:=RNNEG(A); RETURN(B); END;
(*3*) (*general case.*) AP:=A; B:=BETA; RLP:=RL-1;
      REPEAT ADV2(AP, EL,AL,AP);
             IF RLP = 0 THEN BL:=RNNEG(AL); ELSE BL:=RPNEG(RLP,AL);
                END;
             B:=COMP2(BL,EL,B);
             UNTIL AP = SIL;
      B:=INV(B); RETURN(B);
(*6*) END RPNEG;


PROCEDURE RPPROD(RL,A,B: LIST): LIST;
(*Rational polynomial product.  A and B are rational polynomials in r
variables, r ge 0.  C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, EL, FL, J1Y, RLP: LIST;
BEGIN
(*1*) (*a or b zero.*)
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=RNPROD(A,B); RETURN(C); END;
(*3*) (*general case.*) AS:=CINV(A); BS:=CINV(B); C:=0; RLP:=RL-1;
      REPEAT ADV2(BS, BL,FL,BS); AP:=AS; C1:=BETA;
             REPEAT ADV2(AP, AL,EL,AP);
                    IF RLP = 0 THEN CL:=RNPROD(AL,BL); ELSE
                       CL:=RPPROD(RLP,AL,BL); END;
                    J1Y:=EL+FL; C1:=COMP2(J1Y,CL,C1);
                    UNTIL AP = SIL;
             C:=RPSUM(RL,C,C1);
             UNTIL BS = SIL;
      RETURN(C);
(*6*) END RPPROD;


PROCEDURE RPQR(RL,A,B: LIST;    VAR Q,R: LIST);
(*Rational polynomial quotient and remainder.  A and B are rational
polynomials in r variables with B non-zero.  Q and R are the unique
rational polynomials such that either B divides A, Q=A/B and R=0 or
else B does not divide A and A=BQ+R with DEG(R) minimal.*)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RLP, RP, SL: LIST;
BEGIN
(*1*) (*initialize.*) NL:=PDEG(B); BL:=PLDCF(B); BP:=PRED(B); Q:=BETA;
      R:=A; RLP:=RL-1;
(*2*) (*compute quotient terms.*)
      WHILE R <> 0 DO ML:=PDEG(R); DL:=ML-NL;
            IF DL < 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            AL:=PLDCF(R);
            IF RLP = 0 THEN QL:=RNQ(AL,BL); SL:=0; ELSE
               RPQR(RLP,AL,BL, QL,SL); END;
            IF SL <> 0 THEN (*go to 3;*)
               IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
               RETURN;
               END;
            Q:=COMP2(QL,DL,Q); Q1:=LIST2(DL,QL); RP:=PRED(R);
            QP:=RPPROD(RL,BP,Q1); R:=RPDIF(RL,RP,QP); END;
(*3*) (*finish.*)
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END;
      RETURN;
(*6*) END RPQR;


PROCEDURE RPREAD( VAR RL,A,V: LIST);
(*Rational polynomial read.  The rational polynomial A is read from the
input stream.  r ge 0 is the number of variables of A and V is the
variable list of A.  Any number of preceding blanks are skipped.*)
VAR  AL, C, EL, IDUM, RLP, VL: LIST;
BEGIN
(*1*) (*rl=0.*) C:=CREADB();
      IF C <> MASORD("(") THEN BKSP; A:=RNREAD(); RL:=0; V:=BETA; RETURN;
         END;
(*2*) (*rl gt 0.*) A:=BETA;
      LOOP C:=CREADB();
           IF C = MASORD(")") THEN (*go to 4;*) EXIT END;
           BKSP; RPREAD(RLP,AL,V); C:=CREADB();
           IF C <> MASORD("*") THEN (*go to 3;*)
              SWRITE("error found by RPREAD."); DIBUFF; EXIT END;
           VL:=VREAD(); C:=CREADB();
           IF C <> MASORD("*") THEN (*go to 3;*)
              SWRITE("error found by RPREAD."); DIBUFF; EXIT END;
           C:=CREAD();
           IF C <> MASORD("*") THEN (*go to 3;*)
              SWRITE("error found by RPREAD."); DIBUFF; EXIT END;
           EL:=AREAD(); A:=COMP2(AL,EL,A); C:=CREADB();
           IF C = MASORD(")") THEN (*go to 4;*) EXIT ELSE
              IF C = MASORD("-") THEN BKSP; ELSE
                 IF C <> MASORD("+") THEN (*go to 3;*)
                    SWRITE("error found by RPREAD."); DIBUFF; EXIT END;
                 END;
              END;
           END;
(*3   (*error.*) SWRITE("error found by RPREAD."); DIBUFF; *)
(*4*) (*finish.*) A:=INV(A); RL:=RLP+1; V:=SUFFIX(V,VL); RETURN;
(*7*) END RPREAD;


PROCEDURE RPRNP(RL,AL,B: LIST): LIST;
(*Rational polynomial rational number product.  B is a rational
polynomial in r variables, r ge 0.  a is a rational number.  C=a*B.*)
VAR  BL, BP, C, CL, EL, RLP: LIST;
BEGIN
(*1*) (*al=0 or b=0.*)
      IF (AL = 0) OR (B = 0) THEN C:=0; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=RNPROD(AL,B); RETURN(C); END;
(*3*) (*general case.*) C:=BETA; BP:=B; RLP:=RL-1;
      REPEAT ADV2(BP, EL,BL,BP); CL:=RPRNP(RLP,AL,BL);
             C:=COMP2(CL,EL,C);
             UNTIL BP = SIL;
      C:=INV(C); RETURN(C);
(*6*) END RPRNP;


PROCEDURE RPSUM(RL,A,B: LIST): LIST;
(*Rational polynomial sum.  A and B are rational polynomials in r
variables, r ge 0.  C=A+B.*)
VAR  AL, AP, BL, BP, C, CL, CP, EL, FL, RLP: LIST;
BEGIN
(*1*) (*a=0 or b=0.*)
      IF A = 0 THEN C:=B; RETURN(C); END;
      IF B = 0 THEN C:=A; RETURN(C); END;
(*2*) (*rl=0.*)
      IF RL = 0 THEN C:=RNSUM(A,B); RETURN(C); END;
(*3*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; RLP:=RL-1;
      REPEAT EL:=FIRST(AP); FL:=FIRST(BP);
             IF EL > FL THEN ADV2(AP, EL,AL,AP); CP:=COMP2(AL,EL,CP);
                ELSE
                IF EL < FL THEN ADV2(BP, FL,BL,BP);
                   CP:=COMP2(BL,FL,CP); ELSE ADV2(AP, EL,AL,AP);
                   ADV2(BP, FL,BL,BP);
                   IF RLP = 0 THEN CL:=RNSUM(AL,BL); ELSE
                      CL:=RPSUM(RLP,AL,BL); END;
                   IF CL <> 0 THEN CP:=COMP2(CL,EL,CP); END;
                   END;
                END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*4*) (*finish.*)
      IF AP = SIL THEN AP:=BP; END;
      IF CP = SIL THEN C:=AP; ELSE C:=INV(CP); SRED(CP,AP); END;
      IF C = SIL THEN C:=0; END;
      RETURN(C);
(*7*) END RPSUM;


PROCEDURE RPWRIT(RL,A,V: LIST);
(*Rational polynomial write.  A is a rational polynomial in r
variables, r ge 0.  V is a variable list for A.  A is written
in the output stream in external canonical form.*)
VAR  AL, AP, EL, IL, RLP, V1, VB, VP: LIST;
BEGIN
(*1*) (*rl=0 or a=0.*)
      IF (RL = 0) OR (A = 0) THEN IWRITE(A); RETURN; END;
(*2*) (*a ne 0.*) SWRITE("("); AP:=A; RLP:=RL-1; VB:=CINV(V);
      ADV(VB, V1,VP); VP:=INV(VP); IL:=0;
      REPEAT ADV2(AP, EL,AL,AP);
             IF (IL <> 0) AND ((RL > 1) OR (RNSIGN(AL) > 0)) THEN
                SWRITE("+"); END;
             IF RLP = 0 THEN RNWRIT(AL); ELSE RPWRIT(RLP,AL,VP); END;
             SWRITE("*"); CLOUT(V1); SWRITE("*"); SWRITE("*");
             IWRITE(EL); IL:=1;
             UNTIL AP = SIL;
      SWRITE(")"); RETURN;
(*5*) END RPWRIT;


END SACRPOL.
(* -EOF- *)
