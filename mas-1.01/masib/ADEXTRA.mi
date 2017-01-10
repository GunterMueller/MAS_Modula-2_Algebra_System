(* ----------------------------------------------------------------------------
 * $Id: ADEXTRA.mi,v 1.1 1995/10/12 14:44:44 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ADEXTRA.mi,v $
 * Revision 1.1  1995/10/12 14:44:44  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE ADEXTRA;
(* Arbitrary Domain Extra Tools*)
              
FROM DIPC 	IMPORT 	DIPMAD, DIPMCP;

FROM DIPCJ 	IMPORT 	DILBBS;

FROM DIPGB 	IMPORT 	DIPNOR;

FROM DIPIB	IMPORT	ADPNFJ;

FROM MASADOM 	IMPORT 	ADGCD, ADNEG, ADQR, ADSIGN;

FROM MASBIOS 	IMPORT 	SWRITE;

FROM MASSTOR 	IMPORT 	ADV, INV, LENGTH, LIST, SIL;

FROM SACLIST 	IMPORT 	EQUAL;


CONST rcsidi = "$Id: ADEXTRA.mi,v 1.1 1995/10/12 14:44:44 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";      


PROCEDURE ADPCP(A: LIST): LIST;
(*Arbitrary Domain polynomial content and primitive part.
  A is an arbitrary domain polynomial, 
  The result is the positive primitive part of A. *)
VAR  AL, DL, EL, SL, AP, CL: LIST;
BEGIN
      IF A = 0 THEN RETURN(A); END;
      DIPMAD(A, DL,EL,AP); SL:=ADSIGN(DL); 
      IF SL < 0 THEN DL:=ADNEG(DL); END;
      WHILE (AP <> SIL) AND (DL <> 1) DO 
            DIPMAD(AP, AL,EL,AP); DL:=ADGCD(DL,AL); 
      END;
      CL:=DL; AP:=A;
      IF DL = 1 THEN IF SL < 0 THEN CL:=-DL; AP:=ADPNEG(A); END;
                ELSE IF SL < 0 THEN CL:=ADNEG(DL); END;
                     AP:=ADPIQ(A,CL); 
      END;
      RETURN(AP); 
END ADPCP; 


PROCEDURE ADPNEG(A: LIST): LIST;
(*Arbitrary domain polynomial negative. 
  Input: an arbritrary domain polynomial A,
  Output: -A *)
VAR  AL, AS, B, BL, EL: LIST;
BEGIN
      IF A = 0 THEN B:=0; RETURN(B); END;
      AS:=A; B:=SIL;
      REPEAT DIPMAD(AS, AL,EL,AS); BL:=ADNEG(AL); B:=DIPMCP(EL,BL,B);
             UNTIL AS = SIL;
      B:=INV(B); RETURN(B);
END ADPNEG;   


PROCEDURE ADPIQ(A,b: LIST): LIST;
(* Arbitrary domain polynomial integer quotient. 
   Input: A is an arbitrary domain polynomial, b is a nonzero integer,
          and b divides any coefficient of A. 
   Output: C=A/b.*)
VAR  AL, AP, C, EL, QL, RL: LIST;
BEGIN
      IF A = 0 THEN RETURN(0); END;
      C:=SIL; AP:=A;
      REPEAT DIPMAD(AP, AL,EL,AP); ADQR(AL,b, QL,RL);
             C:=DIPMCP(EL,QL,C);
      UNTIL AP = SIL;
      C:=INV(C); RETURN(C);
END ADPIQ;  


PROCEDURE ADLGinH(H, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial list G in H.
   Input: H is a list of lists of arbitrary domain polynomials,
          G is a list of arbitrary domain polynomials.
   Output: TRUE iff ex. h in H s.t. G = h, FALSE else. *)
VAR GG, h: LIST;
BEGIN 
  IF H = SIL THEN RETURN(FALSE); END;
  GG:=G; DILBBS(GG);
  WHILE (H<>SIL) DO
        ADV(H,h,H); DILBBS(h);
        IF ADLGeqH(h,GG) THEN RETURN(TRUE); END; 
  END;
  RETURN(FALSE);
END ADLGinH;


PROCEDURE ADLGeqH(H, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial list G equal H.
   Input: H and G are lists of arbitrary domain polynomials,
   Ouput: TRUE iff H=G, FALSE else. *)
VAR h,g: LIST;
BEGIN 
  IF LENGTH(H) <> LENGTH(G) THEN RETURN(FALSE); END;
  WHILE H <> SIL DO
        ADV(H,h,H); ADV(G,g,G);
        IF NOT(ADPFeqG(h,g)) THEN RETURN(FALSE) END;
  END;
  RETURN(TRUE);
END ADLGeqH;


PROCEDURE ADPFeqG(F, G: LIST): BOOLEAN;
(* Arbitrary domain polynomial F equal G.
   Input: arbitrary domain polynomials F and G,
   Ouput: TRUE iff g = h, FALSE else. *)
VAR f,g: LIST;
BEGIN 
  IF LENGTH(F)<>LENGTH(G) THEN RETURN(FALSE); END;
  WHILE F<>SIL DO
        ADV(F,f,F); ADV(G,g,G);
        IF NOT(EQUAL(f,g)) THEN RETURN(FALSE); END;
  END;
  RETURN(TRUE);
END ADPFeqG;


PROCEDURE ADIredG(I,G: LIST): LIST;
(* Arbitrary domain polynomial set I reducible modulo G.
   Input: arbitrary domain polynomial sets I & G.
   Output: 0 iff all i in I are reducible modulo G to zero, 
           a reduced polynomial p else *)
VAR II,f,p: LIST;
BEGIN
  II:=I; p:=0;
  WHILE II<>SIL DO ADV(II,f,II);
                  p:=DIPNOR(G,f);
                  IF p<>0 THEN RETURN(p) END;
  END;
  RETURN(0);
END ADIredG;


PROCEDURE ADGJredI(G,I: LIST): LIST;
(* Arbitrary domain polynomial G Janet-reducible modulo I.
   Input: arbitrary domain polynomial sets G & I.
   Output: 0 iff all g in G are Janet-reducible modulo I to zero, 
           a reduced polynomial p else *)
VAR GG,f,p: LIST;
    red   : BOOLEAN;		
BEGIN
  GG:=G; p:=0;
  WHILE GG<>SIL DO ADV(GG,f,GG);
                   ADPNFJ(I,f,p,red);
                   IF p<>0 THEN RETURN(p) END;
  END;
  RETURN(0);
END ADGJredI;               


PROCEDURE IBeqGB(G,I: LIST): LIST;
(* Inovlutive Base equal Groebner Base.
   Input: Groebner Base G and involutive Base I,
   Output: 0 iff Id(G) = Id(I), a reduced polynomial p else *)
VAR i,g: LIST;
BEGIN
  i:=ADIredG(I,G);
  IF i<>0 THEN RETURN(i) END;
  g:=ADGJredI(G,I);
  IF g<>0 THEN RETURN(g) ELSE RETURN(0); END;
END IBeqGB;

END ADEXTRA.

(* -EOF- *)
