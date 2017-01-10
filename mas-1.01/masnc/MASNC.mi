(* ----------------------------------------------------------------------------
 * $Id: MASNC.mi,v 1.3 1992/10/15 16:29:46 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASNC.mi,v $
 * Revision 1.3  1992/10/15  16:29:46  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:30  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:13:21  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASNC;

(* MAS Non-commutative Product Implementation Module. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, LENGTH, TIME,
                    SRED, SFIRST, FIRST, RED, COMP, INV, ADV, LIST1;

FROM MASERR IMPORT severe, harmless, ERROR;

FROM SACLIST IMPORT AWRITE, ADV3, COMP3, LIST2, COMP2, ADV2, FIRST3, 
                    OWRITE, LAST, CONC, CINV, RED2, SECOND, EQUAL;

FROM MASBIOS IMPORT CREAD, CREADB, 
                    DIBUFF, LETTER, DIGIT, 
                    MASORD, BKSP, BLINES, SWRITE;

FROM SACRN IMPORT RNINT, RNPROD, RNQ;

FROM SACPOL IMPORT VLSRCH, VREAD;

FROM DIPC IMPORT DIPMPV, DIPINV, DIPMAD, DIPNOV, DIPFMO, DIPEVL,
                 DIPLPM, DIPLBC, DIPMCP, 
                 VALIS, EVLCM, EVSIGN, EPREAD,
                 EVMT, EVDIF, EVDOV, EVSUM, (*EVZERO,*) EVCADD, EVSU; 

FROM MASRN IMPORT RNDRD, RNEXP;

FROM DIPRN IMPORT DIRLWR, DIRPMC, DIRPON, DIRPDF, 
                  DIRPNG, DIRPPR, DIRPRP, DIRPSM, DIRPWR; 

CONST rcsidi = "$Id: MASNC.mi,v 1.3 1992/10/15 16:29:46 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DINPPR(T,A,B: LIST): LIST; 
(*Distributive polynomial non-commutative product.
A and B are distributive polynomials. T is a table
of distributive polynomials specifying the non-commutative
relations. C=A*B, the non-commutative product of A and B.
The table T may be modified. *)
VAR  AL, AP, BL, BP, C, C1, C2, CL, CS, E1, E2, E3, E4, EL,
     EL1, EL1S, EP, F1, F2, F3, FL, FL1, FL1S, FP, FS, GL, J1Y, N, O,
     RL, XL, XL1, XL2: LIST; 
BEGIN
(*1*) (*trivial cases. *) C:=0; 
      IF A = 0 THEN RETURN(C); END; 
      IF B = 0 THEN RETURN(C); END; 
      IF DIRPON(A) = 1 THEN C:=B; RETURN(C); END; 
      IF DIRPON(B) = 1 THEN C:=A; RETURN(C); END; 
      O:=RNINT(1); RL:=DIPNOV(A); N:=EVZERO(RL); 
(*2*) (*loop on a and b. *) AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); BP:=B; 
             REPEAT DIPMAD(BP, BL,FL,BP); EP:=EVDOV(EL); EL1:=RL+1; 
                    IF EP <> SIL THEN EL1:=FIRST(EP); END; 
                    FP:=EVDOV(FL); FL1:=0; 
                    IF FP <> SIL THEN FS:=CINV(FP); FL1:=FIRST(FS); 
                       END; 
                    J1Y:=RL+1; FL1S:=J1Y-FL1; J1Y:=RL+1; EL1S:=J1Y-EL1; 
                    IF EL1S <= FL1S THEN GL:=EVSUM(EL,FL); 
                       CS:=DIPFMO(O,GL); 
                       ELSE (* e1 * e2 = el, f1 * f2 = fl.*) 
                       EVSU(EL,EL1,0, E1,XL1); EVSU(FL,FL1,0,F1,XL2); 
                       EVCADD(N,EL1,XL1, E2,XL); 
                       EVCADD(N,FL1,XL2, F2,XL); 
                       DINPTL(T,E2,F2,CS,E3,F3); 
                       IF F3 <> SIL THEN C2:=DIPFMO(O,F3); 
                          CS:=DINPPR(T,CS,C2); 
                          IF E3 = SIL THEN E4:=E2; ELSE
                             E4:=EVDIF(E2,E3); END; 
                          DINPTU(T,E4,F2,CS); END; 
                       IF E3 <> SIL THEN C1:=DIPFMO(O,E3); 
                          CS:=DINPPR(T,C1,CS); DINPTU(T,E2,F2,CS); END; 
                       C1:=DIPFMO(O,E1); C2:=DIPFMO(O,F1); 
                       CS:=DINPPR(T,CS,C2); CS:=DINPPR(T,C1,CS); END; 
                    CL:=RNPROD(AL,BL); CS:=DIRPRP(CS,CL); 
                    C:=DIRPSM(C,CS); 
                    UNTIL BP = SIL; 
             UNTIL AP = SIL; 
(*3*) (*finish. *) RETURN(C); 
(*6*) END DINPPR; 


PROCEDURE DINPTL(T,EL,FL: LIST;  VAR C,EP,FP: LIST); 
(*Distributive polynomial non-commutative product table lookup.
e and f are exponent vectors. T is a table
of distributive polynomials specifying the non-commutative
relations. C is the non-commutative product of x**es and x**fs.
ep and fp are exponent vectors with es+ep=e and fs+fp=f.
If e=es or f=fs then ep=() or fp=(). *)
VAR   GL, GL1, GL2, O, PP, Q1, Q2, SL, TL: LIST; 
BEGIN
(*1*) (*initialize.*) PP:=T; EP:=SIL; FP:=SIL; 
(*2*) (*search polynomials in pp. *) 
      WHILE PP <> SIL DO
            ADV3(PP, Q1,Q2,C,PP); GL1:=DIPEVL(Q1); GL2:=DIPEVL(Q2); 
            SL:=EVMT(EL,GL1); TL:=EVMT(FL,GL2); 
            IF (SL*TL = 1) THEN EP:=EVDIF(EL,GL1); 
               FP:=EVDIF(FL,GL2); 
               IF EVSIGN(EP) = 0 THEN EP:=BETA; END; 
               IF EVSIGN(FP) = 0 THEN FP:=BETA; END; 
               RETURN; END; 
            END; 
(*3*) (*not found, use symmetric product. *) GL:=EVSUM(EL,FL); 
      O:=RNINT(1); C:=DIPFMO(O,GL); RETURN; 
(*6*) END DINPTL; 


PROCEDURE DINPTU(T,EL,FL,C: LIST); 
(*Distributive polynomial non-commutative product table update.
e and f are exponent vectors. T is a table
of distributive polynomials specifying the non-commutative
relations. C is a distributive rational polynomial. The relation
e * f = C is added to T. T is modified. *)
VAR  C1, C2, GL1, GL2, O, PL, PP, Q1, Q2, SL, TL, TP, TS, V: LIST; 
BEGIN
(*1*) (*generate polynomials corresponding to el and fl.*) O:=RNINT(1); 
      C1:=DIPFMO(O,EL); C2:=DIPFMO(O,FL); 
(*2*) (*optional message. *) 
      IF VALIS <> SIL THEN V:=VALIS; SWRITE("NEW RELATION = "); 
         DIRPWR(C1,V,-1); SWRITE(" .*. "); DIRPWR(C2,V,-1); 
         SWRITE(" = "); DIRPWR(C,V,-1); BLINES(0); END; 
(*3*) (*search position in t. *) TS:=SIL; PP:=T; 
      WHILE PP <> SIL DO
            ADV2(PP, Q1,Q2,PP); PP:=RED(PP); GL1:=DIPEVL(Q1); 
            GL2:=DIPEVL(Q2); SL:=EVMT(GL1,EL); TL:=EVMT(GL2,FL); 
            IF (SL*TL = 1) THEN TS:=PP; END; 
            END; 
(*4*) (*update ts. *) 
      IF TS = SIL THEN TS:=T; END; 
      IF T = SIL THEN ERROR(severe,"DINPTU empty relation table"); 
         (*this case cannot happen. *) RETURN END;
      ADV(TS, PL,TP); TP:=COMP3(C2,C,PL,TP); SFIRST(TS,C1); SRED(TS,TP); 
      RETURN; 
(*7*) END DINPTU; 


PROCEDURE DINPEX(T,A,NL: LIST): LIST; 
(*Distributive non-commutative polynomial exponentiation. A is a
distributive rational polynomial, n is a non-negative beta-
integer. T is a table of non-commutative relations.
B=A**n. 0**0 is by definition a polynomial in zero variables. *)
VAR  B, BL, BLP, I, RL: LIST; 
BEGIN
(*1*) (*nl=0.*) 
      IF NL = 0 THEN RL:=DIPNOV(A); BLP:=RNINT(1); 
         BL:=DIPFMO(BLP,BETA); B:=DIPINV(BL,0,RL); RETURN(B); END; 
(*2*) (*a eq 0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*3*) (*general case.*) B:=A; 
      FOR I:=1 TO NL-1 DO B:=DINPPR(T,B,A); END; 
      RETURN(B); 
(*6*) END DINPEX; 


PROCEDURE DINLRD(V,T: LIST): LIST; 
(*Distributive non-commutative polynomial list read. V is a
variable list. T is a table of non-commutative relations.
A list of distributive non-commutative polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding A are skipped. *)
VAR  A, AL, C, IDUM: LIST; 
BEGIN
(*1*) (*no list. *) A:=BETA; C:=CREADB(); 
      IF C <> MASORD("(") THEN ERROR(harmless,"DINLRD, ( expected."); 
         RETURN(A); END; 
(*2*) (*read polynomials. *) 
      REPEAT C:=CREADB(); 
             IF C = MASORD(",") THEN C:=CREADB(); END; 
             IF C <> MASORD(")") THEN BKSP; AL:=DINPRD(V,T); 
                A:=COMP(AL,A); END; 
             UNTIL C = MASORD(")"); 
      A:=INV(A); 
(*5*) RETURN(A); END DINLRD; 


PROCEDURE DINPRD(V,T: LIST): LIST; 
(*Distributive non-commutative polynomial read. V is a variable list.
T is a table on non-commutative relations.
A distributive rational polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. Any
blanks preceding A are skipped. *)
VAR  A, A1, A2, AL, AP, C, EL, ES, FL, IL, J1Y, JL, RL, VL: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) A:=0; C:=CREADB(); 
      IF C = 0 THEN RETURN(A); END; 
      BKSP; 
(*2*) (*initialise.*) C:=CREADB(); BKSP; 
      IF C = MASORD(",") THEN ERROR(harmless,"DINPRD, no , expected."); 
         RETURN(A); END; 
      FL:=0; 
      IF C = MASORD("(") THEN C:=CREADB(); FL:=1; END; 
      IF C = MASORD(")") THEN
         IF FL = 1 THEN RETURN(A); 
            ELSE ERROR(harmless,"DINLRD, no ) expected.");  RETURN(A); 
            END; 
         END; 
      RL:=LENGTH(V); ES:=BETA; 
      FOR IL:=1 TO RL DO ES:=COMP(0,ES); END; 
      J1Y:=RNINT(1); A1:=DIPFMO(J1Y,ES); AP:=A1; 
LOOP
(*3*) (*next input. determine next action. *) C:=CREADB(); 
      IF C = MASORD(")") THEN
         IF FL = 0 THEN BKSP; END; 
         RETURN(A); END; 
      IF C = MASORD(",") THEN BKSP; RETURN(A); END; 
      IF C = MASORD("-") THEN AP:=DIRPNG(AP); END; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) THEN C:=CREADB(); END; 
      BKSP; 
(*4*) (*read coefficient.*) 
      IF DIGIT(C) THEN AL:=RNDRD(); EL:=EPREAD(); 
         AL:=RNEXP(AL,EL); AP:=DIRPRP(AP,AL);  
(*5*) (*read polynomial.*) 
   ELSIF C = MASORD("(") THEN AL:=DINPRD(V,T); EL:=EPREAD(); 
         AL:=DINPEX(T,AL,EL); AP:=DINPPR(T,AP,AL);  
(*6*) (*read monic monomial.*) 
   ELSIF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); 
         IF JL = 0 THEN ERROR(harmless,"DINLRD, unknown variable."); 
            RETURN(A); END; 
         EL:=EPREAD(); A2:=DIPMPV(A1,JL,EL); AP:=DINPPR(T,AP,A2);
    END; 
(*8*) (*complete polynomial.*) C:=CREADB(); BKSP; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) OR (C = MASORD(")"))
      OR (C = MASORD(",")) THEN A:=DIRPSM(A,AP); AP:=A1; END; 
END; 
(*11*) END DINPRD; 


PROCEDURE EVZERO(RL: LIST): LIST; 
(*Exponent vector zero. U is an exponent vector of length r,
r ge 0 with all components zero. *)
VAR  IL, U: LIST; 
BEGIN
(*1*) (*initialize. *) U:=BETA; 
(*2*) (*fill vector. *) 
      FOR IL:=1 TO RL DO U:=COMP(0,U); END; 
(*3*) (*finish. *) RETURN(U); 
(*6*) END EVZERO; 


END MASNC.


(* -EOF- *)
