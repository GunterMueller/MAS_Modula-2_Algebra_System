(* ----------------------------------------------------------------------------
 * $Id: DIPIB.mi,v 1.1 1995/10/12 14:44:53 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIB.mi,v $
 * Revision 1.1  1995/10/12 14:44:53  pesch
 * Diplomarbeit Rainer Grosse-Gehling.
 * Involutive Bases.
 * Slightly edited.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIB;
(* DIP Involutive Base Implementation Module. *)

(* Import lists and declarations. *)

FROM ADEXTRA 	IMPORT 	ADPCP;

FROM DIPADOM 	IMPORT 	DIPBCP, DIPDIF, DIPMOC, DIPROD;

FROM DIPC 	IMPORT 	DIPEVL, DIPFMO, DIPMAD, DIPMCP, EVTDEG, EVDIF,
			EVLCM, EVSUM; 

FROM DIPCJ 	IMPORT 	ADDTDG, ADVTDG, DILATDG, DILCAN, DILEP2P, DILPP, DILTDG,
			DIPFIRST, DIPNML, DIRPMV, DIPPGL, DIPPGL2, DIPVL, 
			DIPSSM, DIPPGL3, EVMTJ, DILBBS;

FROM DIPTOOLS 	IMPORT 	ADDNFDIP;

FROM MASADOM 	IMPORT 	ADGCDC, ADQUOT;

FROM MASBIOS 	IMPORT 	BLINES, SWRITE;

FROM MASERR 	IMPORT 	harmless, ERROR;

FROM MASLISPU 	IMPORT 	PROCF1, PROCF2, PROCP1V2, PROCP2V2;

FROM MASSTOR 	IMPORT 	ADV, COMP, FIRST, INV, LENGTH, LIST, LIST1, RED, SIL,
                        SRED, TIME, SFIRST;

FROM SACI 	IMPORT 	IWRITE;

FROM SACLIST 	IMPORT 	AWRITE, CCONC, CINV, CONC, EQUAL, LAST,
		        LIST2, LIST3, LIST4, LIST5, LWRITE, SECOND, THIRD;


CONST maxdom = 30;

TYPE DomainRecord = RECORD
               NFJ: PROCP2V2;
                    (* Normalform procedure which depends on the domain
                       of the coefficients *)
               NFJ2: PROCP2V2;
                    (* Normalform procedure which depends on the domain 
                       of the coefficients is used from the more efficient
                       algorithm DIPIB *)
               NFJ3: PROCP5V2;
                    (* Normalform procedure wicht depends on the domain of
                       the coeficients and is used from DIPIB4 *)
            END;

VAR Jdomain: ARRAY[1..maxdom] OF DomainRecord;

VAR DIPIBOpt: RECORD
                   TraceLevel: INTEGER;
                           (* Output during computation *)
                   ISJ: PROCP1V2;
                           (* Janet-Irreducible-Set algorithm *)
                   Select: PROCP2V2;
                           (* Strategy for selection of polynomials from
                              polynomlist. *)
                   Cancel: PROCF1;
                           (* Function to cancel down coefficients *)
                   Crit: BOOLEAN;
                           (* Decide wether to use criteria from Gerdt *)
              END;

    Select: PROCP2V2;

     
CONST rcsidi = "$Id: DIPIB.mi,v 1.1 1995/10/12 14:44:53 pesch Exp $";
CONST copyrighti = "Copyright (c) 1995 Universitaet Passau";      


PROCEDURE ADCAN(P: LIST): LIST;
(* Arbitrary Polynomial Cancel.
   P is an polynomial of arbitrary domain,
   P is canceled down with ADPCP iff the domain of P is INT and with
   DIPMOC else *)
CONST int = 2;
VAR dom: INTEGER;
BEGIN
  IF P=SIL THEN RETURN(SIL); END;
  dom:=ADDNFDIP(P);
  IF dom=int THEN P:=ADPCP(P) 
             ELSE P:=DIPMOC(P) END;
  RETURN(P);
END ADCAN;



(*****************************************************************************
 * The following two algorithms are from: Zharkov, Blinkov                   *
 *        Involutive Bases of Zero-Dimensional Ideals &                      *
 *        Involution approach to Solving Systems of Algebraic Equations      *
 *****************************************************************************)

PROCEDURE ADPNFJ(G,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain polynomial normalform in the sense of Janet.
   G is a list of polynomials in distributive representation over an arbitrary
   domain, P is a polynomial as above,
   returns a polynomial h such that P is Janet-reducible to h modulo G
   and h is in Janet-normalform w.r.t. G, the flag "reduced" is set TRUE iff
   a Janet-reduction took place *)
VAR DomNum: LIST;
BEGIN
  DomNum:=ADDNFDIP(P);
  IF DomNum=0 THEN h:=0; reduced:=FALSE; (* P is the zero polynom *)
              ELSE Jdomain[INTEGER(DomNum)].NFJ(G,P,h,reduced);
  END;
END ADPNFJ;


PROCEDURE DIPNFJ(P,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Distributive polynomial normal form in the sense of Janet. 
   P is a list of non zero polynomials in distributive
   representation in r variables. S is a distributive polynomial. 
   The result is a polynomial h such that S is reducible to h modulo P 
   in the sense of Janet and h is in Janet-normalform with respect to P,
   "reduced" is set TRUE iff a Janet-reduction took place. *)
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE: LIST; 
BEGIN 
      reduced:=FALSE; h:=0;
      IF (S = 0) OR (P = SIL) THEN RETURN; END; 
      R:=SIL; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP); 
                     SL:=EVMTJ(TE,QE); 
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   BL:=ADQUOT(TA,QA);  AP:=DIPFMO(BL,FL); 
                   APP:=DIPROD(QP,AP); SP:=DIPDIF(SP,APP);
                   reduced:=TRUE;
                END; 
             END; 
      UNTIL SP = 0;   
      IF R = SIL THEN h:=0; ELSE h:=INV(R); END; 
END DIPNFJ; 


PROCEDURE DIPINFJ(P,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Integral Distributive polynomial normal form in the sense of Janet. 
   P is a list of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. h is a polynomial such that S is reducible to h
   modulo P in the sense of Janet and h is in normalform with respect to P,
   reduced is set TRUE iff a Janet-reduction took place. *)
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, R, SL, SP, TA, TE,
      AL, CL, RP, RS: LIST; 
BEGIN 
      reduced:=FALSE; h:=0;
      IF (S = 0) OR (P = SIL) THEN RETURN; END; 
      R:=0; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); DIPMAD(Q, QA,QE,QP);
                    SL:=EVMTJ(TE,QE);
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN RP:=DIPFMO(TA,TE);
                IF R = 0 THEN R:=RP; ELSE RS:=LAST(R); SRED(RS,RP); END;  
                       ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   ADGCDC(TA,QA,CL,AL,BL);
                   AP:=DIPFMO(AL,FL);
                   APP:=DIPROD(QP,AP); SP:= DIPBCP(SP,BL);
                   R:=DIPBCP(R,BL); SP:=DIPDIF(SP,APP); reduced:=TRUE;
                END; 
             END; 
      UNTIL SP = 0;   
      h:=R; 
END DIPINFJ; 


PROCEDURE DILISJ(P: LIST; VAR PP: LIST; VAR reduced: BOOLEAN);
(* Distributive polynomial list irreducible set in the sense of Janet.
   P is a list of distributive polynomials,
   PP is the result of reducing each polynomial p in P modulo P-(p)
   in the sense of Janet until no further reductions are possible.
   reduced is set TRUE if a Janet-reduction took place. *)
VAR   IRR, LL, PL, PS, RP,T	: LIST;
BEGIN
      T:=TIME();
      PS:=CINV(P); RP:=PS; PP:=INV(PS);  LL:=LENGTH(PP); IRR:=0;
      IF LL <= 1 THEN RETURN; END;
      IF DIPIBOpt.TraceLevel>2 THEN BLINES(0); SWRITE("**irr: "); END;
      (*reduce until all polynomials are irreducible. *)
      REPEAT ADV(PP, PL,PP); ADPNFJ(PP,PL,PL,reduced); 
             IF PL = 0 THEN LL:=LL-1;
                IF LL <= 1 THEN RETURN; END;
             ELSE 
                IF NOT(reduced) THEN IRR:=IRR+1; 
                   ELSE IRR:=0; PL:=DIPIBOpt.Cancel(PL); END;
                PS:=LIST1(PL); SRED(RP,PS); RP:=PS; 
             END;
             IF DIPIBOpt.TraceLevel>2 THEN AWRITE(IRR); SWRITE(", "); END;
      UNTIL IRR = LL;
      (*finish. *)  
      IF DIPIBOpt.TraceLevel>1 THEN
              BLINES(0); SWRITE("Janet-Reduction in "); 
              AWRITE(TIME()-T); SWRITE("ms, with");
              BLINES(0); AWRITE(LL); SWRITE(" irreducible polynomials"); 
      END;
      RETURN; 
END DILISJ;      


PROCEDURE DIPIRLJ(P: LIST; VAR F: LIST; VAR reduced: BOOLEAN);
(* distributive polynomial interreduced list in the sense of Janet.
   P is a list of polynomials in distributive representation over an 
   arbitrary domain, 
   The result is a Janet-interreduced list of polynoms F,
   reduced is set TRUE iff a reduction took place. *)
VAR H, f, g, HTg,HTf,T,LL	: LIST;
    NewHT			: BOOLEAN;
BEGIN 
   F:=P;
   IF DIPIBOpt.TraceLevel>2 THEN BLINES(0); SWRITE("**irr: "); END;
   REPEAT
         IF DIPIBOpt.TraceLevel>2 THEN 
                LL:=LENGTH(F); AWRITE(LL); SWRITE(", ");
         END;
         H:=SIL; NewHT:=FALSE;
         WHILE F<>SIL DO ADV(F,f,F); 
                  HTf:=DIPEVL(f);
                  ADPNFJ(CCONC(F,H),f,g,reduced);
                  IF g<>0 THEN
                     g:=DIPIBOpt.Cancel(g);
                     IF reduced THEN 
                        HTg:=DIPEVL(g);
                        IF EQUAL(HTg,HTf)<>1 THEN NewHT:=TRUE; END;
                     END;
                     H:=COMP(g,H);
                  END;      
         END;
         F:=H;
   UNTIL NOT(NewHT);
   IF DIPIBOpt.TraceLevel>1 THEN BLINES(0);
                         SWRITE("Janet-Reduction in "); 
                         AWRITE(TIME()-T); SWRITE("ms, "); BLINES(0);
                         AWRITE(LENGTH(F)); 
                         SWRITE(" irreducible polynoms "); 
   END;
END DIPIRLJ;


(*** Algorithms from: Zharkov, Blinkov; 
                                Involutive Bases of zero-dimensional ideals ***)

PROCEDURE DIPCOM(F: LIST): LIST;
(* Distributive polynomial complete.
   Subalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: complete system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,EL: LIST;
    FLAG,reduced          : BOOLEAN;
BEGIN
  IF F=SIL THEN RETURN(SIL); END;
  EL:=SIL; DIPIBOpt.ISJ(F,G,reduced); 
  REPEAT
        H:=G; TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) <= TDG THEN
                       ADPNFJ(G,p,f,reduced);
                       IF f<>0 THEN f:=DIPIBOpt.Cancel(f); 
                                    DIPIBOpt.ISJ(COMP(f,G),G,reduced);
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
   UNTIL (H = SIL) AND FLAG; 
   RETURN(G);        
END DIPCOM; 


PROCEDURE DIPIB2(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Mainalgorithm for computing Invbase.
   Input: Distributive polynomial list F.
   Output: G: involutive system, such that Ideal(G) = Ideal(F). *)
VAR f,h,p,G,H,TDG,NM,nm,EL: LIST;
    FLAG,reduced          : BOOLEAN;
BEGIN
  IF F=SIL THEN RETURN(SIL); END;
  EL:=SIL; F:=DILCAN(F, DIPIBOpt.Cancel); G:=DIPCOM(F); 
  REPEAT
        H:=G; TDG:=DILTDG(H); FLAG:=TRUE;
        WHILE (H<>SIL) AND FLAG DO 
              ADV(H,h,H); NM:=DIPNML(h);
              WHILE (NM<>SIL) AND FLAG DO
                    ADV(NM,nm,NM);
                    p:=DIRPMV(h,nm);
                    IF DILTDG(COMP(p,EL)) > TDG THEN
                       ADPNFJ(G,p,f,reduced);
                       IF f<>0 THEN f:=DIPIBOpt.Cancel(f); G:=DIPCOM(COMP(f,G));
                                    FLAG:=FALSE;
                       END; 
                    END; 
              END; 
        END; 
   UNTIL (H = SIL) AND FLAG; 
   RETURN(G);        
END DIPIB2;


(*** Algorithm from: Zharkov, Blinkov:
              Involution Approach to Solving Systems of Algebraic Equations ***)

PROCEDURE DIPIB3(F: LIST): LIST;
(* Distributive polynom involutive base.
   Algorithm for computing the involutive Base for a given polynomial list F.
   Input: Distributiv Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, H, h, NM, nm, f, T, VL, le, T	: LIST;
    reduced                      	: BOOLEAN;
BEGIN
  T:=TIME(); G:=SIL; F:=DILCAN(F, DIPIBOpt.Cancel); 
  VL:=DIPVL(FIRST(F)); le:=LENGTH(VL)+1;
  WHILE F<>SIL DO       
        DIPIBOpt.ISJ(CONC(F,G),G,reduced); 
        F:=SIL; H:=G;
        WHILE H<>SIL DO
              IF DIPIBOpt.TraceLevel>2 THEN BLINES(0); AWRITE(LENGTH(H));
                                            SWRITE(" polynomials to consider ");
              END;
              DIPIBOpt.Select(H,FALSE,h,H); 
              NM:=DIPPGL3(h, VL, le);
              IF DIPIBOpt.TraceLevel>2 THEN BLINES(0); AWRITE(LENGTH(NM));
                                   SWRITE(" prolongations, ");
              END; 
              WHILE NM<>SIL DO
                    ADV(NM,nm,NM); 
                    ADPNFJ(G,nm,f,reduced); 
                    IF f<>0 THEN 
                       IF reduced THEN f:=DIPIBOpt.Cancel(f); END;
                       F:=COMP(f,F) 
                    END; 
              END;
        END;
  END;
  IF DIPIBOpt.TraceLevel>1 THEN   
     BLINES(1); AWRITE(TIME() - T); SWRITE(" ms "); BLINES(0);
     SWRITE("Involutive Base with "); AWRITE(LENGTH(G)); SWRITE(" polynomials");
  END;
  RETURN(G);
END DIPIB3;


(******************************************************************************
 *    Algorithm analog to: Zharkov, Blinkov:                                  * 
 *                              Solving zero-dimensional involutive systems,  * 
 *    an optional using of three criteria is possible. The three criteria are *
 *    from Gerdt, Blinkov: Involutive Polynomial Bases.                       * 
 *----------------------------------------------------------------------------*
 * This algorithm works with extended polynomial lists. An extended polynomial*
 * is a triple (deg, pol, ht) if the DIPIB-option crit is used, or a tuple    *
 * (deg, pol) else.                                                           * 
 *    deg - total degree of the leading term or 0 if the polynomial is already*
 *          prolongated.                                                      *
 *    pol - the polynomial                                                    *
 *    ht  - head term of the starting polynomial. ht must not be equal to the *
 *          head term of pol. ht is updated in the procedure IBcrit.          *
 *          For details see Gerdt, Blinkov: Involutive Polynomial Bases.      * 
 ******************************************************************************)

PROCEDURE ADEPNFJ(G,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain extended polynomial normalform in the sense of Janet.
   G is a list of polynomials in distributive representation over an arbitrary
   domain, P is a polynomial as above,
   returns a polynomial h such that P is Janet-reducible to h modulo G
   and h is in Janet-normalform w.r.t. G, the flag "reduced" is set True iff
   a Janet-reduction took place  *)
VAR DomNum: LIST;
BEGIN
  IF P=SIL THEN DomNum:=0 ELSE
                DomNum:=ADDNFDIP(SECOND(P)); END; 
  IF DomNum=0 THEN h:=0; reduced:=FALSE; (* P is the zero polynom *)
              ELSE Jdomain[INTEGER(DomNum)].NFJ2(G,P,h,reduced);
  END;
END ADEPNFJ;


PROCEDURE DIPENFJ(P,S: LIST; VAR R: LIST; VAR c: BOOLEAN);
(* Distributive extended polynomial normal form in the sense of Janet. 
   P is a list of non zero extended polynomials in distributive
   representation in r variables. S is a distributive extended 
   polynomial. R is an extended polynomial such that S is reducible 
   to R modulo P in the sense of Janet and R is in normalform with 
   respect to P, c is set TRUE iff a Janet-reduction took place. *)
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, SL, SP, TA, TE, deg, tdg,
	term, HT : LIST;
BEGIN 
      c:=FALSE;
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN; END; 
      (*reduction step.*) R:=SIL; ADEPCrumble(S, deg, SP, term);
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP, Q,PP); Q:=ADEPpolynomial(Q); DIPMAD(Q, QA,QE,QP); 
                    SL:=EVMTJ(TE,QE); 
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE 
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   BL:=ADQUOT(TA,QA);  AP:=DIPFMO(BL,FL); 
                   APP:=DIPROD(QP,AP); SP:=DIPDIF(SP,APP); c:=TRUE; END; 
             END; 
      UNTIL SP = 0; 
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END; 
      IF R<>0 THEN 
              IF c THEN R:=ADEPCompose(EVTDEG(FIRST(R)),R,term);
                   ELSE R:=ADEPCompose(deg,R,term); END;
      END; 
END DIPENFJ; 


PROCEDURE DIPEINFJ(P,S: LIST; VAR R: LIST; VAR c: BOOLEAN);
(* Integral distributive extended polynomial normal form in the sense of Janet. 
   P is a list of non zero extended polynomials in distributive
   representation in r variables. S is a distributive extended
   polynomial. R is a polynomial such that S is reducible to R
   modulo P in the sense of Janet and R is in normalform with respect to P. *)
VAR   AP, APP, BL, FL, PP, Q, QA, QE, QP, SL, SP, TA, TE,
      AL, CL, RP, RS, deg, term, HT: LIST; 
BEGIN  
      c:=FALSE;
      IF (S = 0) OR (P = SIL) THEN R:=S; RETURN; END; 
      R:=0; ADEPCrumble(S, deg, SP, term); 
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP = SIL THEN SP:=0; END; 
             PP:=P; 
             REPEAT ADV(PP,Q,PP); Q:=ADEPpolynomial(Q); DIPMAD(Q, QA,QE,QP);
                    SL:=EVMTJ(TE,QE);
             UNTIL (PP = SIL) OR (SL = 1); 
             IF SL = 0 THEN RP:=DIPFMO(TA,TE);
                IF R = 0 THEN R:=RP; ELSE RS:=LAST(R); SRED(RS,RP); END;  
                       ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   ADGCDC(TA,QA,CL,AL,BL);
                   AP:=DIPFMO(AL,FL);
                   APP:=DIPROD(QP,AP); SP:= DIPBCP(SP,BL);
                   R:=DIPBCP(R,BL); SP:=DIPDIF(SP,APP); c:=TRUE; END; 
             END; 
      UNTIL SP = 0;   
      IF R<>0 THEN 
              IF c THEN R:=ADEPCompose(EVTDEG(FIRST(R)),R,term); 
                   ELSE R:=ADEPCompose(deg,R,term); END;
      END; 
END DIPEINFJ; 


PROCEDURE IsInvolutive(G: LIST): BOOLEAN;
(* Is involutive.
   Test wether G is involutive. If G is involutive, then the first entry of G
   is 0. G is a list of distributive polynomials,
   Returns TRUE iff G is involutive, FALSE else *)
BEGIN
  RETURN(FIRST(G)=0);
END IsInvolutive;


PROCEDURE ADEPmark(g, G: LIST): LIST;
(* Arbitrary domain extended polynomial mark.
   g is an extended polynomial, G is a list of extended polynomials;
   the first entry of g is set to 0 and G is set to G cup g *)
VAR tdg: INTEGER;
BEGIN
  ADVTDG(g,tdg,g); g:=COMP(0,g); 
  G:=COMP(g,G); 
  RETURN(G);
END ADEPmark;


PROCEDURE DILISJ2(P: LIST): LIST;
(* Distributive polynomial list irreducible set.
   P is a list of distributive polynomials,
   PP is the result of reducing each p element of P modulo P-(p)
   in the sense of Janet until no further reductions are possible. *)
VAR EL, FL, IRR, LL, PL, PP, PS, RP, pl, T, deg, pol, term: LIST;
    reduced : BOOLEAN;
BEGIN
      T:=TIME();
      PS:=CINV(P); RP:=PS; PP:=INV(PS);  LL:=LENGTH(PP); IRR:=0;
      IF DIPIBOpt.TraceLevel>1 THEN BLINES(0); SWRITE("**irr: "); END;
      IF LL <= 1 THEN RETURN(PP); END;
      (*reduce until all polynomials are irreducible. *)
      REPEAT ADV(PP,PL,PP); 
             ADEPNFJ(PP,PL,PL,reduced); 
             IF DIPIBOpt.TraceLevel>2 THEN AWRITE(LL); SWRITE(", "); END;
             IF PL = 0 THEN LL:=LL-1; 
                IF LL <= 1 THEN RETURN(PP); END;
                ELSE IF NOT(reduced) THEN IRR:=IRR+1; ELSE IRR:=0; 
                    ADEPCrumble(PL, deg, pol, term);
                    pol:=DIPIBOpt.Cancel(pol); 
                    PL:=ADEPCompose(deg,pol,term); END; 
                    PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END;
      UNTIL IRR = LL;
      IF DIPIBOpt.TraceLevel>1 THEN  BLINES(0); 
                                     SWRITE("Janet-Reduction in ");
                                     AWRITE(TIME()-T); SWRITE("ms, ");
                                     BLINES(0); AWRITE(LL);
                                     SWRITE(" irreducible polynomials"); 
      END;
      RETURN(PP); 
END DILISJ2;      


PROCEDURE ADEPtriple(PS, term: LIST): LIST;
(* Arbitrary domain extended polynomial triple.
   Input: PS - a list of polynomials, term - term to use as head-term or SIL.
   Output: a list of extended polynomials *)
VAR L, P, term, deg, triple, ht: LIST;
BEGIN
  L:=SIL;
  WHILE PS<>SIL DO ADV(PS,P,PS); ht:=FIRST(P); deg:=EVTDEG(ht);
        IF term=SIL THEN triple:=ADEPCompose(deg,P,ht); 
	            ELSE triple:=ADEPCompose(deg,P,term); END;
	L:=COMP(triple,L);
  END;
  RETURN(L);
END ADEPtriple;


PROCEDURE ADEPuntriple(PS: LIST): LIST;
(* Arbitrary domain extended polynomial untriple.
   Input: PS - an extended polynomial list.
   Output: a polynomial list. *)
VAR L, P, pol: LIST;
BEGIN
  L:=SIL;
  WHILE PS<>SIL DO ADV(PS,P,PS);
	pol:=ADEPpolynomial(P);
	L:=COMP(pol,L);
  END;
  RETURN(L);
END ADEPuntriple;


PROCEDURE ADEPCrumble(P: LIST; VAR deg, pol, ht: LIST);
(* Arbitrary domain extended polynomial crumble.
   Input: an arbritraty domain extended polynomial,
   Output: the components of the extended polynomial: deg - the total degree 
           of the leading term, pol - the polynomial and if exists ht - the
           head term of the polynomial and 0 else. *)
BEGIN
  deg:=0; pol:=SIL; ht:=SIL;  
  IF P<>SIL THEN ADV(P,deg,P);
     IF P<>SIL THEN ADV(P,pol,P);
        IF P<>SIL THEN ADV(P,ht,P);
        END;
     END;
  END;
END ADEPCrumble;


PROCEDURE ADEPCompose(deg, pol, ht: LIST): LIST;
(* Arbitrary domain extended polynomial compose.
   Input: the components to build an extended polynomial: deg - the total degree
	  of the polynomial, pol - the polynomial and ht - the head term of
          the polynomial or 0 if ht should not be element of the extended
          polynomial.
   Output: an extended polynomial. *)
VAR P: LIST;
BEGIN
   IF DIPIBOpt.Crit THEN RETURN(LIST3(deg,pol,ht)); 
                    ELSE RETURN(LIST2(deg,pol)); END;
END ADEPCompose;


PROCEDURE ADEPdegree(P: LIST): LIST;
(* Arbitrary domain extended polynomial degree.
   Input: P - an arbitrary domain extended polynomial.
   Ouput: the degree of the head term of P, that is the first entry from the
          extended polynomial *)
BEGIN
  RETURN(FIRST(P));
END ADEPdegree;


PROCEDURE ADEPpolynomial(P: LIST): LIST;
(* Arbitrary domain extended polynomial polynomial.
   Input: P - an arbitrary domain extended polynomial.
   Output: the polynomial entry of the extended polynomial, that is the second
           entry from the extended polynomial. *)
BEGIN
  RETURN(SECOND(P));
END ADEPpolynomial;


PROCEDURE ADEPheadterm(P: LIST): LIST;
(* Arbitrary domain extended plynomial head-term.
   Input: P - an arbitrary domain extended polynomial.
   Output: the head term entry of the extended polynomial. That is the third
           entry in the extended polynomial list. 
   The third list entry must not be equal to the head-term of the polynomial
   entry of the extended polynomial list. *)
BEGIN
  RETURN(THIRD(P));
END ADEPheadterm;


PROCEDURE ADEPleadingterm(P: LIST): LIST;
(* Arbitrary polynomial leading term.
   Input: P - an arbitrary domain extended polynomial.
   Output: the head term of the polynomial in the extended polynomial list,
           that is the first element of the second list entry. *)
BEGIN
  RETURN(FIRST(SECOND(P)));
END ADEPleadingterm;


PROCEDURE IBcrit(NM, G: LIST): LIST;
(* Inovlutive Base criterium.
   Input: NM - a list of prolongated extended polynomials, G - a list of 
          extended polynomials.
   Output: NM minus the polynomials from NM which are reducible to 0 by
          one of the criteriums, or which are reducible to 0 modulo G. *)
VAR u, R, nm, deg, lm, PP, Q, QE, SL, v, lcm : LIST;
    reduced: BOOLEAN;
BEGIN
    IF NM=SIL THEN RETURN(SIL) END;
    u:=ADEPheadterm(FIRST(NM)); R:=SIL; 
    WHILE NM<>SIL DO ADV(NM,nm,NM);
          deg:=ADEPdegree(nm); lm:=ADEPleadingterm(nm); PP:=G;
          REPEAT ADV(PP, Q,PP); QE:=ADEPleadingterm(Q);
                 SL:=EVMTJ(lm,QE); 
          UNTIL (PP = SIL) OR (SL = 1);
          IF SL=1 THEN v:=ADEPheadterm(Q); 
(* crit 1*)  IF NOT(EQUAL(u,v)) THEN lcm:=EVLCM(u,v);
(* crit 2*)     IF NOT(EQUAL(lcm, EVSUM(u,v))) THEN
(* crit 3*)	   IF EVTDEG(lcm)>=deg THEN 
                      ADEPNFJ(G,nm,nm,reduced);
                      IF nm<>0 THEN
                         ADEPCrumble(nm, deg, nm, v);
                         v:=FIRST(nm); nm:=DIPIBOpt.Cancel(nm);
                         nm:=ADEPCompose(deg,nm,v); R:=COMP(nm,R); END;
	            ELSE IF DIPIBOpt.TraceLevel>1 THEN 
                                 BLINES(0); SWRITE("Criterium 3 used"); END; 
                   END; 
                ELSE IF DIPIBOpt.TraceLevel>1 THEN 
                                 BLINES(0); SWRITE("Criterium 2 used"); END;
                END;
             ELSE IF DIPIBOpt.TraceLevel>1 THEN
                                 BLINES(0); SWRITE("Criterium 1 used"); END;
             END;
          ELSE ADEPNFJ(G,nm,nm,reduced);
               IF nm<>0 THEN 
                  IF reduced THEN ADEPCrumble(nm, deg, nm, v); 
                                  nm:=DIPIBOpt.Cancel(nm); 
                                  nm:=ADEPCompose(deg,nm,v); END;
                             R:=COMP(nm,R);
               END; 
          END;
    END;
    RETURN(R);
END IBcrit;


PROCEDURE DIPIB(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, g, NM, nm, f, T, LL, VL, le, PL, CL, PS, r, T: LIST;
    reduced: BOOLEAN;
BEGIN
  T:=TIME(); G:=SIL;
  VL:=DIPVL(FIRST(F)); le:=LENGTH(VL)+1;
  PS:=DILCAN(F, DIPIBOpt.Cancel); (* PS:=ADEPtriple(PS,SIL); *)
  F:=PS; 
  IF F=SIL THEN RETURN(SIL) END; 
  DILISJ(F,G,reduced); G:=ADEPtriple(G,SIL);
  LOOP 
       Select(G,TRUE,g,G); (* never use DIPIBopt.Select because G must be sorted 
                              else IsInvolutive possibly returns a false result *)
       IF IsInvolutive(g) THEN EXIT END; 
       NM:=DIPPGL3(ADEPpolynomial(g),VL,le); 
       G:=ADEPmark(g,G); NM:=ADEPtriple(NM, ADEPheadterm(g));
       IF DIPIBOpt.Crit THEN NM:=IBcrit(NM,G); END;
       IF NM <> SIL THEN G:=CONC(NM,G); G:=DILISJ2(G); END; 
  END;
  G:=COMP(g,G); 
  PS:=ADEPuntriple(G);
  IF DIPIBOpt.TraceLevel>0 THEN BLINES(1);
                   AWRITE(TIME()-T); SWRITE("ms, "); 
                   SWRITE("involutive base with "); AWRITE(LENGTH(PS));
                   SWRITE(" polynomials ");
  END;
  RETURN(PS);
END DIPIB;


(*****************************************************************************
 *     algorithm analog to: Zharkov, Blinkov,                                * 
 *                         Solving zero-dimensional involutive systems       *
 *---------------------------------------------------------------------------*
 * This algorithm does not work with extended polynomial list and thus it    *
 * needs another Janet-interreducible algorithm.                             *
 * This algorithm does a Janet-reduction with two different input sets:      *
 *  the first set is a list of possible candidates for prolongations and     *
 *  the second set is a list of already condered polynomials                 *
 *****************************************************************************)

PROCEDURE ADPNFJS(G1,G2,G3,G4,P: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Arbitrary domain polynomial normalform in the sense of Janet modulo a set
   of set of polynomials.
   G1-G4 are lists of polynomials in distributive representation over an
   arbitrary domain, P is a polynomial.
   The result is a polynomial h such that P is Janet-reducible to
   h modulo the union of G1-G4 and h is in Janet-Normalform w.r.t. G1-G4, 
   the flag "reduced" is set TRUE iff a Janet-reduction took place *)
VAR DomNum: LIST;
BEGIN
  IF P=SIL THEN DomNum:=0 ELSE DomNum:=ADDNFDIP(P); END;
  IF DomNum=0 THEN reduced:=FALSE; h:=0;
              ELSE Jdomain[INTEGER(DomNum)].NFJ3(G1,G2,G3,G4,P,h,reduced);
  END;
END ADPNFJS;


PROCEDURE DIPNFJS(P1,P2,P3,P4,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN); 
(* Distributive polynomial normal form in the sense of Janet modulo a set of
   sets of polynomials. 
   P1-P4 are lists of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. R is a polynomial such that S is reducible to R modulo P 
   in the sense of Janet and R is in normalform with respect to P,
   reduced is set TRUE iff a reduction took place. *)
CONST no = 4;
VAR   AP, APP, BL, FL, Q, QA, QE, QP, R, SL, SP, TA, TE: LIST; 
      PP: ARRAY[1..no] OF LIST;
      i : CARDINAL;
BEGIN 
      reduced:=FALSE; h:=0;
      IF (S = 0) OR ((P1=SIL) AND (P2=SIL) AND (P3=SIL) AND (P4=SIL))
         THEN RETURN; END; 
      R:=SIL; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP = SIL THEN SP:=0; END; 
             PP[1]:=P1; PP[2]:=P2; PP[3]:=P3; PP[4]:=P4; i:=1; SL:=0;
             REPEAT
                   WHILE (i<no) AND (PP[i]=SIL) DO i:=i+1 END;
                   WHILE (PP[i]<>SIL) AND (SL=0) DO
                         ADV(PP[i],Q,PP[i]); DIPMAD(Q, QA,QE,QP); 
                         SL:=EVMTJ(TE,QE); 
                   END;
             UNTIL (i = no) OR (SL = 1);
             IF SL = 0 THEN R:=DIPMCP(TE,TA,R); ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   BL:=ADQUOT(TA,QA);  AP:=DIPFMO(BL,FL); 
                   APP:=DIPROD(QP,AP); SP:=DIPDIF(SP,APP);
                   reduced:=TRUE;
                END; 
             END; 
      UNTIL SP = 0;   
      IF R = SIL THEN h:=0; ELSE h:=INV(R); END;  
END DIPNFJS;


PROCEDURE DIPINFJS(P1,P2,P3,P4,S: LIST; VAR h: LIST; VAR reduced: BOOLEAN);
(* Integral Distributive polynomial normal form in the sense of Janet modulo a
   set of sets of polynomials. 
   P1-P4 are lists of non zero polynomials in distributive
   representation in r variables. S is a distributive
   polynomial. h is a polynomial such that S is reducible to h
   modulo P in the sense of Janet and h is in normalform with respect to P,
   reduced is set TRUE iff a Janet-reduction took place. *)
CONST no = 4;
VAR   AP, APP, BL, FL, Q, QA, QE, QP, R, SL, SP, TA, TE,
      AL, CL, RP, RS: LIST; 
      PP: ARRAY[1..no] OF LIST;
      i : CARDINAL;
BEGIN  
      reduced:=FALSE; h:=S;
      IF (S = 0) OR ((P1=SIL) AND (P2=SIL) AND (P3=SIL) AND (P4=SIL)) 
         THEN RETURN; END; 
      (*reduction step.*) R:=0; SP:=S; 
      REPEAT DIPMAD(SP, TA,TE, SP);
             IF SP=SIL THEN SP:=0; END; 
             PP[1]:=P1; PP[2]:=P2; PP[3]:=P3; PP[4]:=P4; i:=1; SL:=0;
             REPEAT
                   WHILE (i<no) AND (PP[i]=SIL) DO i:=i+1 END;
                   WHILE (PP[i]<>SIL) AND (SL=0) DO
                         ADV(PP[i],Q,PP[i]); DIPMAD(Q, QA,QE,QP); 
                         SL:=EVMTJ(TE,QE); 
                   END;
             UNTIL (i = no) OR (SL = 1);
             IF SL = 0 THEN RP:=DIPFMO(TA,TE);
                IF R = 0 THEN R:=RP; ELSE RS:=LAST(R); SRED(RS,RP); END;  
                       ELSE
                IF QP <> SIL THEN FL:=EVDIF(TE,QE); 
                   ADGCDC(TA,QA,CL,AL,BL);
                   AP:=DIPFMO(AL,FL);
                   APP:=DIPROD(QP,AP); SP:= DIPBCP(SP,BL);
                   R:=DIPBCP(R,BL); SP:=DIPDIF(SP,APP); reduced:=TRUE;
                END; 
             END; 
      UNTIL (SP = 0);   
      h:=R; 
END DIPINFJS;


PROCEDURE DIPIRLJ2(VAR P, Q: LIST; VAR reduced: BOOLEAN);
(* Distributive polynomial list interreduced list in the sense of Janet.
   P and Q are lists of polynomials in distributive representation over an 
   arbitrary domain,
   P and Q already initialised by the calling procedure.
   P contains polynomials which are possible candidates for prolongations,
   Q are already considered.
   Output is the list P of Janet-reduced polynomials from p plus Janet-reduced
   polynomials from Q. Q contains polynomials from input Q which are not
   Janet-reduced.
   reduced is set TRUE iff a reduction took place *)
VAR F,G,H,I,f,g,HTg,HTf,T 	: LIST;
    NewHT, FromG		: BOOLEAN;
BEGIN 
   T:=TIME(); F:=P; G:=Q;
   REPEAT
         H:=SIL; I:=SIL; NewHT:=FALSE;
         WHILE (F<>SIL) OR (G<>SIL) DO 
                  IF F<>SIL THEN ADV(F,f,F); FromG:=FALSE;
                            ELSE ADV(G,f,G); FromG:=TRUE; END;
                  HTf:=DIPEVL(f); 
                  ADPNFJS(F,H,G,I,f,g,reduced);
                  IF g<>0 THEN
                     IF reduced THEN 
                        HTg:=DIPEVL(g); g:=DIPIBOpt.Cancel(g); H:=COMP(g,H);
                        IF EQUAL(HTg,HTf)<>1 THEN NewHT:=TRUE;  END;
                     ELSE IF FromG THEN I:=COMP(g,I);
                                   ELSE H:=COMP(g,H); END;
                     END;
                  END;      
         END;
         F:=H; G:=I;
   UNTIL NOT(NewHT);
   Q:=G; P:=F;
   IF DIPIBOpt.TraceLevel>1 THEN BLINES(0); AWRITE(TIME()-T); SWRITE("ms, ");
                                AWRITE(LENGTH(Q)+LENGTH(P)); 
                                SWRITE(" irreducible polynoms ");
   END;
END DIPIRLJ2;


PROCEDURE DIPIB4(F: LIST): LIST;
(* Distributive polynomial involutive basis.
   Algorithm for computing the involutive Base for a given F.
   Input: Distributiv Integral Polynomial List F.
   Output: Equivalent involutive system G.*)
VAR G, H, g, NM, VL, le,T	: LIST;
    reduced			: BOOLEAN;
BEGIN
  T:=TIME(); H:=SIL;
  g:=FIRST(F); VL:=DIPVL(g); le:=LENGTH(VL)+1;
  F:=DILCAN(F, DIPIBOpt.Cancel);
  DIPIRLJ2(F,H,reduced); (* be carfull: don't change the order of F and H
                                without changing the order in DIPIRL2!        *)
  G:=F;
  LOOP 
       IF G=SIL THEN EXIT END;
       DIPIBOpt.Select(G,FALSE,g,G); H:=COMP(g,H);
       NM:=DIPPGL3(g,VL,le); 
       IF NM<>SIL THEN G:=CONC(NM,G); DIPIRLJ2(G,H,reduced); END; 
  END;
  IF DIPIBOpt.TraceLevel>0 THEN BLINES(1); AWRITE(TIME()-T); SWRITE("ms, ");
                                SWRITE("involutive base with ");
                                AWRITE(LENGTH(H)); SWRITE(" polynomials.");
  END;
  RETURN(H);
END DIPIB4;


(******************************************************************************)

PROCEDURE SetDIPIBopt(options: LIST);
(* Set distributive polynomial involutive base options.
   Input: List of 4 options in the order Trace-Level, Cancel-Option, 
          Select-Option, ISJ-Algorithm.
   For details see the corresponding procedures *)
VAR opt: INTEGER;
BEGIN
  IF options<>SIL THEN ADV(options,opt,options);
                       SetDIPIBTraceLevel(opt);
     IF options<>SIL THEN ADV(options,opt,options);
                          SetDIPIBCancel(opt);
        IF options<>SIL THEN ADV(options,opt,options);
                             SetDIPIBSelect(opt);
           IF options<> SIL THEN ADV(options,opt,options);
                                 SetDIPIBISJ(opt);
              IF options<>SIL THEN ADV(options,opt,options);
                                   SetDIPIBCrit(opt);
              END;
           END;
        END;
     END;
  END;
END SetDIPIBopt;


PROCEDURE SetDIPIBTraceLevel(level: INTEGER);
(* Set Trace Level.
   Input is the integer level. You get the following informatins:
   0: no information,
   1: computing time and number of polynomials of the computed involutive base,
   2: informations about each Janet-reduction,
   3: more detailed information of each Janet-reduction.
 *)
BEGIN
  DIPIBOpt.TraceLevel:=level;
END SetDIPIBTraceLevel;


PROCEDURE SetDIPIBCancel(Canc: CARDINAL);
(* Set distributive polynomial involutive base cancel.
   Set the function to use to cancel down the coefficients in case of
   integer coefficients. Canc=1 means: use ADCAN, 2 means: use DIPMOC *)
BEGIN
  CASE Canc OF
       1: DIPIBOpt.Cancel:=ADCAN |
       2: DIPIBOpt.Cancel:=DIPMOC |
       ELSE ERROR(harmless, "DIPIB.SetCancel: Illegal number");
  END;
END SetDIPIBCancel;


PROCEDURE SetDIPIBSelect(SEL: INTEGER);
(* Set distributive polynomial involutive base select.
   Set polynomial selection strategy:
   1: DIPSSM, 2: DIPFIRST  *)
BEGIN
  CASE SEL OF
       1: DIPIBOpt.Select := DIPSSM |
       2: DIPIBOpt.Select := DIPFIRST;
       ELSE ERROR(harmless, "DIPIBSetSelect: Illegal number");
  END;
END SetDIPIBSelect;


PROCEDURE SetDIPIBISJ(Sel: INTEGER);
(* Set distributive involutive base irreducible set in the sense of Janet.
   Set Janet-Irreducible-Set Algorithm, 1: DILISJ, 2: DIPIRLJ *)
BEGIN
  CASE Sel OF
       1: DIPIBOpt.ISJ:=DILISJ |
       2: DIPIBOpt.ISJ:=DIPIRLJ;
    ELSE ERROR(harmless, "DIPIBSetISJ: Illegal number ");
  END;
END SetDIPIBISJ;


PROCEDURE SetDIPIBCrit(crit: INTEGER);
(* Set distributive polynomial involutive base critera.
   Input: an integer crit.
   DIPIBOpt.Crit ::= TRUE iff cirt = 1 and FALSE else *)
BEGIN
  IF crit=1 THEN DIPIBOpt.Crit:=TRUE;
	    ELSE DIPIBOpt.Crit:=FALSE; END;
END SetDIPIBCrit;


PROCEDURE SetDomainNFJ;
(* Initialize Jdomain *)
VAR i: INTEGER;
BEGIN
  FOR i:=1 TO maxdom DO Jdomain[INTEGER(i)].NFJ:=DIPNFJ;
                        Jdomain[INTEGER(i)].NFJ2:=DIPENFJ;
                        Jdomain[INTEGER(i)].NFJ3:=DIPNFJS;
  END;
  Jdomain[INTEGER(2)].NFJ:=DIPINFJ;
  Jdomain[INTEGER(2)].NFJ2:=DIPEINFJ;
  Jdomain[INTEGER(2)].NFJ3:=DIPINFJS;
  Jdomain[INTEGER(3)].NFJ:=DIPINFJ;
  Jdomain[INTEGER(3)].NFJ2:=DIPEINFJ;
  Jdomain[INTEGER(3)].NFJ3:=DIPINFJS;
  Jdomain[INTEGER(12)].NFJ:=DIPINFJ;
  Jdomain[INTEGER(12)].NFJ2:=DIPEINFJ;
  Jdomain[INTEGER(12)].NFJ3:=DIPINFJS; 
END SetDomainNFJ;

BEGIN
  SetDomainNFJ;
  (* TraceLevel = 0, Cancel = ADPCP, Select = DIPSSM, ISJ = DILISJ,
     Criteria = TRUE *)
  SetDIPIBopt(LIST5(0,1,1,1,1));
  Select:=DIPSSM;
END DIPIB.
 

(* -EOF- *)
