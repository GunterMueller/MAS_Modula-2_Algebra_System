(* ----------------------------------------------------------------------------
 * $Id: SYMMFU.mi,v 1.3 1992/10/15 16:29:19 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SYMMFU.mi,v $
 * Revision 1.3  1992/10/15  16:29:19  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:33:14  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:55  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SYMMFU;

(* Symmetric Functions Implementation Module. *)



FROM MASSTOR IMPORT LIST, SIL, BETA, 
                    ADV, RED, INV, COMP, LENGTH;

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM SACLIST IMPORT ADV2, COMP2;

FROM SACRN IMPORT RNINT, RNRED;

FROM DIPC IMPORT DIPFMO, DIPMAD, DIPADM, DIPMCP, DIPMRD, DIPBSO, EVCADD;

FROM DIPRN IMPORT DIRPAB, DIRPDF, DIRPPR, DIRPRP, DIRPEX; 


CONST rcsidi = "$Id: SYMMFU.mi,v 1.3 1992/10/15 16:29:19 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIRPSR(Q,PL: LIST;  VAR P1,P2: LIST); 
(*Distributive rational polynomial symmetric function reduction. 
Q is a list of the rl elementary symmetric functions in rl 
variables. pl is reduced modulo Q to p2, the reduction relation 
is p1. *)
VAR   FL, P3, P4, TA, TE, TL, X: LIST; 
BEGIN
(*1*) (*initialize. *) P1:=0; P2:=PL; 
      IF P2 = 0 THEN RETURN; END; 
(*2*) (*reduce monomials. *) P3:=SIL; P1:=SIL; 
      REPEAT DIPMAD(P2, TA,TE,P2); 
             IF P2 = SIL THEN P2:=0; END; 
             TL:=EVASC(TE); 
             IF TL = 1 THEN DIRPSE(Q,TE, P4,FL); P4:=DIRPRP(P4,TA); 
                P4:=DIPMRD(P4); 
                IF P4 <> SIL THEN P2:=DIRPDF(P2,P4); END; 
                P1:=DIPMCP(FL,TA,P1); ELSE P3:=DIPMCP(TE,TA,P3); END; 
             UNTIL P2 = 0; 
      IF P3 = SIL THEN P2:=0; ELSE P2:=INV(P3); END; 
      IF P1 = SIL THEN P1:=0; ELSE P1:=INV(P1); END; 
(*8*) (*finish. *) RETURN; 
(*9*) END DIRPSR; 


PROCEDURE DIRPSE(Q,U: LIST;  VAR PL,V: LIST); 
(*Distributive rational polynomial symm. function exponent reduction.
Q is a list of the rl elementary symmetric functions in rl 
variables. pl is a product of elemenatry symmetric polynomials such 
that head term pl = u. v is the exponent vector of the product. *)
VAR  E, EL1, ELS, O, QL, QP, RL, SL, UP, X: LIST; 
BEGIN
(*1*) (*initialize. *) V:=SIL; RL:=LENGTH(U); E:=EVZERO(RL); 
      O:=RNINT(1); PL:=DIPFMO(O,E); 
      IF U = SIL THEN RETURN; END; 
      UP:=U; QP:=Q; SL:=0; 
(*2*) (*reduce exponent vector. *) 
      REPEAT (*len(q)=len(up). *) ADV(QP, QL,QP); ADV(UP, EL1,UP); 
             IF EL1 > SL THEN ELS:=EL1-SL; SL:=EL1; V:=COMP(ELS,V); 
                QL:=DIRPEX(QL,ELS); PL:=DIRPPR(PL,QL); ELSE
                V:=COMP(0,V); END; 
             UNTIL UP = SIL; 
      V:=INV(V); 
(*8*) (*finish. *) RETURN; 
(*9*) END DIRPSE; 


PROCEDURE DIRPES(RL: LIST): LIST; 
(*Distributive rational polynomial elementary symmetric functions.
Q is a list of the rl elementary symmetric functions in rl 
variables. *)
VAR  E, EL, FL, GL, IL, J1Y, O, ORD, P, PL, Q, T, TL, X,
     XL: LIST; 
BEGIN
(*1*) (*initialize. *) Q:=SIL; 
      IF RL < 1 THEN RETURN(Q); END; 
      J1Y:=RL+1; E:=EVZERO(J1Y); O:=RNRED(1,1); EVCADD(E,1,1, TL,XL); 
      T:=DIPFMO(O,TL); P:=DIPFMO(O,E); 
(*2*) (*product (t-xi). *) (*ORD:=EVOVAL(); EVOSET(LIST2(2,0));*) 
      FOR IL:=1 TO RL DO EVCADD(E,IL+1,1, EL,XL); PL:=DIPFMO(O,EL); 
          PL:=DIRPDF(PL,T); P:=DIRPPR(P,PL); END; 
      (*EVOSET(ORD);*) 
(*3*) (*coefficients of p. *) 
      REPEAT DIPADM(P, FL,GL,PL,P); PL:=DIRPAB(PL); DIPBSO(PL); 
             Q:=COMP(PL,Q); 
             UNTIL P = 0; 
      Q:=INV(Q); Q:=RED(Q); Q:=INV(Q); 
(*8*) (*finish*) RETURN(Q); 
(*9*) END DIRPES; 


PROCEDURE EVASC(U: LIST): LIST; 
(*Exponent vector ascending. U is an exponent vector of length rl,
U=(u1, ...  ,url).  tl = 1 if u1 le ...  le url, else tl = 0. *)
VAR  EL, FL, TL, UP: LIST; 
BEGIN
(*1*) (*initialize. *) TL:=0; 
      IF U = SIL THEN RETURN(TL); END; 
      ADV(U, EL,UP); 
(*2*) (*compare exponents. *) 
      WHILE UP <> SIL DO ADV(UP, FL,UP); 
            IF EL > FL THEN RETURN(TL); END; 
            EL:=FL; END; 
(*8*) (*finish*) TL:=1; RETURN(TL); 
(*9*) END EVASC; 


PROCEDURE EVZERO(RL: LIST): LIST; 
(*Exponent vector zero. U is an exponent vector of length rl,
rl ge 0 with all components zero. *)
VAR  IL, U: LIST; 
BEGIN
(*1*) (*initialize. *) U:=SIL; 
(*2*) (*fill vector. *) 
      FOR IL:=1 TO RL DO U:=COMP(0,U); END; 
(*3*) (*finish. *) RETURN(U); 
(*6*) END EVZERO; 

(*
(* alt, aus ALDES, in MAS anders. *)
PROCEDURE EVOSET(O: LIST); 
(*Evord set. Set the global variables evord etc. according to o.*)
VAR   CP, CPL, EVIX, EVOR1, EVORD, OLP: LIST; 
BEGIN
(*1*) (*decompose o.*) 
      IF (O = SIL) OR (O < BETA) THEN
         SWRITE(''ERROR IN EVOSET''); RETURN; END; 
      ADV2(O, CP,CPL,OLP); 
(*2*) (*set evord.*) EVORD:=CP; EVIX:=0; EVOR1:=0; 
      IF OLP <> SIL THEN EVIX:=CPL; EVOR1:=FIRST(OLP); END; 
      IF EVORD >= 5 THEN EVIX:=0; EVOR1:=0; END; 
      IF EVOR1 >= 5 THEN EVIX:=0; EVOR1:=0; END; 
(*5*) RETURN; END EVOSET; 


PROCEDURE EVOVAL(): LIST; 
(*Evord value. Read the global variables evord etc. into o.*)
VAR  CP, CPL, CPS, EVIX, EVOR1, EVORD, O: LIST; 
BEGIN
(*1*) (*read evord.*) CP:=EVORD; CPL:=EVIX; CPS:=EVOR1; O:=SIL; 
      IF CPL <> 0 THEN O:=COMP(CPS,O); END; 
      O:=COMP2(CP,CPL,O); 
(*4*) RETURN(O); END EVOVAL; 
*)

END SYMMFU.

(* -EOF- *)
