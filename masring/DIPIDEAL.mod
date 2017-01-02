(* ----------------------------------------------------------------------------
 * $Id: DIPIDEAL.mi,v 1.4 1993/05/11 10:53:31 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIDEAL.mi,v $
 * Revision 1.4  1993/05/11  10:53:31  kredel
 * Spelling errors corr.
 *
 * Revision 1.3  1992/10/15  16:29:35  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:19  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:54  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIDEAL;

(* DIP Ideal System Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, BETA, SIL, LENGTH,
                    LIST1, ADV, FIRST, RED, SFIRST, SRED, COMP, INV;

FROM MASERR IMPORT ERROR, fatal, severe; 

FROM SACLIST IMPORT COMP2, LIST2, FIRST2, 
                    SECOND, RED2, CCONC, CINV, LELT, 
                    LIST4, MEMBER, CONC, ADV2;

FROM SACPOL IMPORT PDEG;

FROM DIPC IMPORT DIPNOV, DIPINV;

FROM DIPTOO IMPORT DIPLDM;

FROM DIPRN IMPORT DIRPPR;

FROM DIPRNGB IMPORT DIRPNF, DIRPGB, DIRGBA;

CONST rcsidi = "$Id: DIPIDEAL.mi,v 1.4 1993/05/11 10:53:31 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPLDV(A,V: LIST): LIST; 
(*Distributive polynomial list dependency on variables.
A is a list of distributive polynomials. V is the variable list.
U is the variable list of variables with positive exponents in A. *)
VAR  AL, AP, U, VL, VP, W, WL: LIST; 
BEGIN
(*1*) (*initialise. *) 
      IF A = SIL THEN VP:=V; RETURN(U); END; 
      W:=DIPLDM(A); 
(*2*) (*extract variables. *) VP:=CINV(V); U:=BETA; 
      WHILE VP <> SIL DO ADV(VP, VL,VP); ADV(W, WL,W); 
            IF PDEG(WL) <> 0 THEN U:=COMP(VL,U); END; 
            END; 
(*5*) RETURN(U); END DIPLDV; 


PROCEDURE DIRLCT(A,B: LIST): LIST; 
(*Distributive rational polynomial list ideal containment test.
A and B are lists of distributive rational polynomials representing 
groebner bases. t = 1 if ideal(A) is contained in ideal(B),
t = 0 else. *)
VAR  AL, AS, BL, TL: LIST; 
BEGIN
(*1*) (*a or b empty.*) 
      IF A = SIL THEN TL:=1; RETURN(TL); END; 
      IF B = SIL THEN TL:=0; RETURN(TL); END; 
(*2*) (*general case.*) AS:=A; TL:=0; 
      REPEAT ADV(AS, AL,AS); BL:=DIRPNF(B,AL); 
             IF BL <> 0 THEN RETURN(TL); END; 
             UNTIL AS = SIL; 
      TL:=1; 
(*5*) RETURN(TL); END DIRLCT; 


PROCEDURE DIRLIP(PL,A,B: LIST): LIST; 
(*Distributive rational polynomial list ideal product.
A and B are lists of distributive rational polynomials. 
C=GBASIS(p,A*B).*)
VAR  AL, AP, AS, BL, BS, C, CL: LIST; 
BEGIN
(*1*) (*a or b empty.*) 
      IF (A = SIL) OR (B = SIL) THEN C:=BETA; RETURN(C); END; 
(*2*) (*general case.*) AS:=A; BS:=B; C:=BETA; 
      REPEAT ADV(BS, BL,BS); AP:=AS; 
             REPEAT ADV(AP, AL,AP); CL:=DIRPPR(AL,BL); C:=COMP(CL,C); 
                    UNTIL AP = SIL; 
             UNTIL BS = SIL; 
(*3*) (*groebner basis. *) 
      IF PL <> 0 THEN C:=COMP(PL,C); END; 
      C:=DIRPGB(C,1); 
(*6*) RETURN(C); END DIRLIP; 


PROCEDURE DIRLPI(A,P,VP: LIST): LIST; 
(*Distributive rational polynomial list primary ideal.
A and P are non empty lists of distributive rational polynomials 
representing groebner bases. The polynomials in A have r variables.
ideal(P) is a prime ideal in at most r+1 variables. VP is the 
variable list for P. QP=(P,e,VP,Q) where Q = ideal(P**e,A) 
with A contained in Q and e maximal. *)
VAR  AL, AP, AS, EL, J1Y, PL, PP, Q, QP, QS, RL, RLP, TL: LIST; 
BEGIN
(*1*) (*initialise. *) EL:=0; PP:=P; PL:=0; QS:=PP; J1Y:=FIRST(A); 
      RL:=DIPNOV(J1Y); J1Y:=LENGTH(VP); RLP:=J1Y-RL; AP:=A; 
      IF RLP > 0 THEN AS:=BETA; ADV(PP, PL,PP); 
         WHILE AP <> SIL DO ADV(AP, AL,AP); AL:=DIPINV(AL,0,RLP); 
               AS:=COMP(AL,AS); END; 
         AP:=INV(AS); END; 
(*2*) (*check if a is contained in p**el. *) 
      REPEAT Q:=QS; EL:=EL+1; QS:=DIRLIP(PL,Q,PP); TL:=DIRLCT(AP,QS); 
             UNTIL TL = 0; 
(*3*) (*check if p**el is contained in (a,p**(el+1)). *) 
      REPEAT AS:=CCONC(AP,QS); AS:=DIRPGB(AS,1); TL:=DIRLCT(Q,AS); 
             IF TL <> 1 THEN Q:=QS; EL:=EL+1; QS:=DIRLIP(PL,Q,PP); 
                END; 
             UNTIL TL = 1; 
(*4*) (*finish. *) QP:=LIST4(P,EL,VP,AS); 
(*7*) RETURN(QP); END DIRLPI; 


END DIPIDEAL.


(* -EOF- *)
