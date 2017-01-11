(* ----------------------------------------------------------------------------
 * $Id: DIPRNIB.mi,v 1.1 1995/10/12 14:45:00 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPRNIB.mi,v $
 * Revision 1.1  1995/10/12 14:45:00  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPRNIB;
(* DIPRN Involutive Base Implementation Module. *)

(* Import lists and declarations. *)

FROM DIPC 	IMPORT 	DIPEVL, DIPFMO, DIPMCP, DIPMAD, EVDIF, EVSIGN;

FROM DIPCJ 	IMPORT 	DILTDG, DIPNML, DIRPMV, EVMTJ;

FROM DIPRN 	IMPORT 	DIRPDF, DIRPMC, DIRPPR;

FROM MASADOM 	IMPORT 	ADQUOT;

FROM MASBIOS 	IMPORT 	BLINES, SWRITE;

FROM MASSTOR 	IMPORT 	ADV, COMP, INV, LENGTH, LIST, LIST1, TIME, SIL, SRED;

FROM SACLIST 	IMPORT 	AWRITE, CONC, EQUAL;

FROM SACRN 	IMPORT 	RNQ;



CONST rcsidi = "$Id: DIPRNIB.mi,v 1.1 1995/10/12 14:45:00 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";      

(* This version is from:
    Zharkov Blinkov: Involutive Bases of Zero-Dimensional Ideals *)

PROCEDURE DIRPNFJ(P,S: LIST): LIST; 
(*Distributive rational polynomial normal form in the sense of Janet. 
  P is a list of non zero polynomials in distributive rational
  representation in r variables. S is a distributive rational
  polynomial. The result is a polynomial R such that S is reducible to R
  modulo P and R is in normalform with respect to P. *)
VAR  AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE: LIST; 
BEGIN
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN(R); END; 
      (*reduction step.*) R:=SIL; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE,SP); 
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); SL:=EVMTJ(TE,QE); 
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); BL:=RNQ(TA,QA); 
                   AP:=DIPFMO(BL,FL); APP:=DIRPPR(QP,AP); 
                   SP:=DIRPDF(SP,APP); END; 
                END; 
      UNTIL SP = 0; 
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END; 
      RETURN(R); 
END DIRPNFJ;

 
PROCEDURE DIRLISJ(P: LIST): LIST; 
(* Distributive rational polynomial list irreducible set in the sense of Janet.
   P is a list of distributive rational polynomials,
   The result is a set of polynomials, such that each polynomial p in P is
   in Janet-normalform modulo P-(p) *)
VAR  EL, FL, IRR, LL, PL, PP, PS, RL, RP, SL: LIST; 
BEGIN
      PP:=P; PS:=SIL;
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIRPMC(PL); 
            IF PL <> 0 THEN PS:=COMP(PL,PS); END; 
      END; 
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0; 
      IF LL <= 1 THEN RETURN(PP); END;  
      (*reduce until all polynomials are irreducible. *) 
      LOOP ADV(PP, PL,PP); EL:=DIPEVL(PL); PL:=DIRPNFJ(PP,PL); 
           IF PL = 0 THEN LL:=LL-1; 
              IF LL <= 1 THEN EXIT END; 
              ELSE FL:=DIPEVL(PL); SL:=EVSIGN(FL); 
              IF SL = 0 THEN PP:=LIST1(PL); EXIT END; 
              SL:=EQUAL(EL,FL); 
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0; 
                 PL:=DIRPMC(PL); END; 
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END; 
           IF IRR = LL THEN EXIT END;
      END; 
      BLINES(0); 
      RETURN(PP); 
END DIRLISJ; 

   

PROCEDURE DIRPCOM(F: LIST): LIST;
(* Distributive rational polynom complete system.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,EL: LIST;
    FLAG                  : BOOLEAN;
BEGIN
  IF F=SIL THEN RETURN(SIL) END;
  EL:=SIL; G:=DIRLISJ(F); 
  REPEAT
        H:=G;
        TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) <= TDG THEN
                       f:=DIRPNFJ(G,p);
                       IF f<>0 THEN G:=DIRLISJ(COMP(f,G));
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
  UNTIL (H = SIL) AND FLAG; 
  RETURN(G);        
END DIRPCOM; 


PROCEDURE DIRPIB2(F: LIST): LIST;
(* Distributive rational polynom involutive basis.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,EL: LIST;
    FLAG                  : BOOLEAN;
BEGIN
  IF F=SIL THEN RETURN(SIL); END;
  EL:=SIL; G:=DIRPCOM(F); 
  REPEAT
        H:=G; TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) > TDG THEN
                       f:=DIRPNFJ(G,p);
                       IF f<>0 THEN G:=DIRPCOM(COMP(f,G));
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
  UNTIL (H = SIL) AND FLAG; 
  RETURN(G);        
END DIRPIB2;

PROCEDURE DIRPIB(F: LIST): LIST;
(* Distributive rational polynom involutive basis.
   Second Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Rational Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, H, h, NM, nm, f, T: LIST;
BEGIN
  T:=TIME(); G:=SIL;
  WHILE F<>SIL DO
        G:=DIRLISJ(CONC(G, F));
        F:=SIL; H:=G;
        WHILE H<>SIL DO
              ADV(H,h,H); 
              NM:=DIPNML(h);
              WHILE NM<>SIL DO
                    ADV(NM,nm,NM);
                    f:=DIRPNFJ(G, DIRPMV(h,nm));
                    IF f<>0 THEN F:=COMP(f,F) END; 
              END;
        END;
  END;     
  BLINES(1); AWRITE(TIME() - T); SWRITE(" ms ");
  RETURN(G);
END DIRPIB;
 
END DIPRNIB.


(* -EOF- *)
