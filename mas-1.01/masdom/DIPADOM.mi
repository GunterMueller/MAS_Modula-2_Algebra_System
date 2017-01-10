(* ----------------------------------------------------------------------------
 * $Id: DIPADOM.mi,v 1.9 1995/11/05 09:26:20 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPADOM.mi,v $
 * Revision 1.9  1995/11/05 09:26:20  kredel
 * Improved polynomial parsing.
 *
 * Revision 1.8  1994/10/21  12:33:50  pfeil
 * added procedure DIPLIR.
 *
 * Revision 1.7  1994/09/01  13:21:43  pfeil
 * modified comment
 *
 * Revision 1.6  1994/06/16  12:54:02  pfeil
 * changed number of parameters in procedure DIPSFF.
 * changed parameter type of procedures SetPFactFunc, SetPSqfrFunc.
 *
 * Revision 1.5  1994/06/10  12:07:00  pfeil
 * Minor changes.
 *
 * Revision 1.4  1994/06/09  14:48:27  pfeil
 * Added DIPFAC, DIPIRL, DIPNF, DIPRLF, DIPS, DIPSFF for DIPDCGB.
 *
 * Revision 1.3  1992/10/15  16:30:10  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:21  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:35  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
  
IMPLEMENTATION MODULE DIPADOM;

(* DIP Arbitrary Domain Implementation Module. *)



FROM MASSTOR IMPORT LIST, SIL, BETA, FIRST, ADV, RED, COMP,
                    LENGTH, LIST1, SRED, SFIRST, INV;

FROM MASERR IMPORT severe, ERROR;

FROM MASBIOS IMPORT BLINES, SWRITE, CWRITE, CREAD, CREADB, 
                    SOLINE, BKSP, MASORD, LETTER, DIGIT;

FROM SACLIST IMPORT EQUAL, FIRST2, SECOND, LIST2, CINV, CLOUT, 
                    OWRITE, AWRITE, CCONC;

FROM SACPOL IMPORT VREAD, VLSRCH, VLWRIT;
 
FROM DIPC    IMPORT DIPNBC, DIPADS, DIPADV, DIPEVL, DIPMAD, 
                    DIPMPM, DIPFMO, 
                    DIPMCP, DIPMRD, DIPCMP, DIPTCF, DIPTCS, 
                    DIPMPV, DIPLBC, DIPINV, DIPADM, DIPNOV,
                    STVL, BACKUB, PFDIP, DIPFP, 
                    EVRASP, EVRAND, EVDFSI, EVSUM, 
                    EPREAD, EVSIGN, EVDER, EVCOMP;

FROM MASADOM IMPORT ADDIF, ADEXP, ADFI, ADGCD, ADINV, ADINVT,
                    ADLCM, ADNEG, ADONE, ADPROD, ADQUOT, 
                    ADREAD, ADSIGN, ADSUM, ADWRIT, ADFIP, 
                    ADDDREAD, ADDDWRIT, ADVLDD,
		    ADPFACT, ADPNF, ADPSFF, ADPSP;

CONST rcsidi = "$Id: DIPADOM.mi,v 1.9 1995/11/05 09:26:20 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIPEXP(A,NL: LIST): LIST; 
(*Distributive polynomial exponentiation.  D is a non zero
distributive polynomial. n is a non-negative beta-integer.
B=A**n. If n=0 then a polynomial in zero variables is returned. *)
VAR  AL, B, BL, D, KL: LIST; 
BEGIN
(*1*) (*nl less than or equal to 1.*) 
      IF NL = 0 THEN AL:=DIPLBC(A); D:=RED(AL); BL:=ADFI(D,1); 
         B:=DIPFMO(BL,BETA); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=DIPEXP(A,KL); B:=DIPROD(B,B); 
      IF NL > 2*KL THEN B:=DIPROD(B,A); END; 
(*5*) RETURN(B); END DIPEXP; 


PROCEDURE DIFIP(A,D: LIST): LIST; 
(*Distributive polynomial from distributive integral polynomial.
A is a distributive integral polynomial with inverse
lexicographical term ordering. D is the domain
descriptor for the distributive polynomial B. *)
VAR   AL, AP, B, BL, BLP, CL, EL, FL, v, MP, RL, RLS, RLP: LIST; 
BEGIN
(*1*) (*a = 0. *) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*adjust structure. *) PFDIP(A, RL,AP); 
      v:=ADVLDD(D); RLS:=LENGTH(v); RLP:=RL-RLS; 
      IF RLP < 0 THEN OWRITE(RLP); B:=0;
         ERROR(severe,"DIFIP: to few coefficient variables.");
         RETURN(B) END;
      AP:=DIPFP(RLP,AP); 
(*3*) (*convert ceofficients. *) B:=SIL; 
      REPEAT DIPMAD(AP, AL,EL,AP); 
             BL:=ADFIP(D,AL);  
             IF ADSIGN(BL) <> 0 THEN B:=DIPMCP(EL,BL,B) END; 
             UNTIL AP = SIL; 
(*4*) (*finish. *) 
      IF B = SIL THEN B:=0; ELSE B:=INV(B); END; 
(*5*) RETURN(B); END DIFIP; 


PROCEDURE DILRD(V,D: LIST): LIST; 
(*Distributive polynomial list read. V is a variable list. 
A list of distributive polynomials
in r variables, where r=length(V), r ge 0, is read from
the input stream. Any blanks preceding a are skipped. *)
VAR  A, AL, C: LIST; 
BEGIN
(*1*) (*no list. *) C:=CREADB(); 
      IF C <> MASORD("(") THEN ERROR(severe,"ERROR FOUND BY DILRD."); 
         RETURN(A); END; 
(*2*) (*read polynomials. *) A:=BETA; 
      REPEAT C:=CREADB(); 
             IF C = MASORD(",") THEN C:=CREADB(); END; 
             IF C <> MASORD(")") THEN BKSP; AL:=DIREAD(V,D); 
                A:=COMP(AL,A); END; 
             UNTIL C = MASORD(")"); 
      A:=INV(A); 
(*5*) RETURN(A); END DILRD; 


PROCEDURE DILSUM(A: LIST): LIST; 
(*Distributive polynomial list sum. D is a circular
list of distributive polynomials. B is the sum of all
polynomials in A. *)
VAR  B, BP, BPP, C, CP, CPP: LIST; 
BEGIN
(*1*) (*nothing to do. *) 
      IF A = SIL THEN B:=0; RETURN(B); END; 
(*2*) (*merge. *) C:=A; ADV(C, B,CP); 
      WHILE C <> CP DO ADV(CP, BP,CPP); BPP:=DIPSUM(B,BP); 
            SFIRST(C,BPP); SRED(C,CPP); C:=CPP; ADV(C, B,CP); END; 
(*5*) RETURN(B); END DILSUM; 


PROCEDURE DILWR(A,V: LIST); 
(*Distributive polynomial list write. V is a
variable list. A list of distributive polynomials
in r variables, where r=length(V), r ge 0, is written to
the output stream. *)
VAR  AL, AP, LS, RS: LIST; 
BEGIN
(*1*) (*format. *) BLINES(0); (*LS:=LMARG; RS:=RMARG; LMARG:=10; 
      RMARG:=60; BLINES(0); *)
(*2*) (*write polynomials. *) AP:=A; 
      WHILE AP <> SIL DO ADV(AP, AL,AP); DIWRIT(AL,V); BLINES(1); 
            END; 
      (*LMARG:=LS; RMARG:=RS;*) 
(*5*) RETURN; END DILWR; 


PROCEDURE DIPBCP(A,BL: LIST): LIST; 
(*Distributive polynomial base coefficient product. A is a
distributive polynomial, b is a base coefficient. C=A*b.*)
VAR  AL, AP, C, EL, PL: LIST; 
BEGIN
(*1*) (*a=0 or bl=0.*) 
      IF (A = 0) OR (ADSIGN(BL) = 0) THEN C:=0; RETURN(C); 
      END; 
(*2*) (*multiply.*) C:=BETA; AP:=A; 
      REPEAT DIPMAD(AP, AL,EL,AP); PL:=ADPROD(AL,BL); 
             C:=DIPMCP(EL,PL,C); 
             UNTIL AP = SIL; 
      C:=INV(C); RETURN(C); 
(*5*) END DIPBCP; 


PROCEDURE DIPDIF(A,B: LIST): LIST; 
(*Distributive polynomial difference. A and B are
distributive polynomials. C=A-B.*)
VAR  AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=DIPNEG(B); RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); SL:=EVCOMP(EL,FL); 
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CL:=ADNEG(BL); CP:=DIPMCP(FL,CL,CP); ELSE DIPMAD(AP,
                   AL,EL,AP); DIPMAD(BP, BL,FL,BP); CL:=ADDIF(AL,BL); 
                   IF ADSIGN(CL) <> 0 THEN CP:=DIPMCP(EL,CL,CP); 
                   END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) APP:=AP; 
      IF AP = SIL THEN
         IF BP <> SIL THEN APP:=DIPNEG(BP); END; 
         END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*6*) END DIPDIF; 


PROCEDURE DIPFAC(A,VOO: LIST): LIST;
(* distributive polynomial factorization.
   A is a polynomial in distributive representation,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where A = u * f1**e1 * ... * fk**ek and u unit.
   The ordering of the factors is non-deterministic !! *)
BEGIN
   IF A=0 THEN RETURN(SIL); END;
   RETURN(ADPFACT(A,VOO));
END DIPFAC;


PROCEDURE DIPIRL(VAR P: LIST; VAR CS: BOOLEAN);
(* distributive polynomials interreduced list of polynomials.
   P is a list of polynomials in distributive representation
   over an arbitrary domain,
   CS is a flag, CS = TRUE iff P is changed,
   returns a interreduced list of polynomials R=(p1,...,pk),
   R is the result of reducing each pi modulo R-(pi)
   until no further reductions are possible. *)
VAR H,f,HTf,HTg,g: LIST;
    NewHT: BOOLEAN;
BEGIN
   CS:=FALSE;
   REPEAT
      H:=SIL; NewHT:=FALSE;
      WHILE P<>SIL DO
	 ADV(P,f,P);
	 HTf:=DIPEVL(f);
	 g:=DIPNF(CCONC(P,H),f);
	 IF g<>0 THEN
	    HTg:=DIPEVL(g);
            IF EQUAL(HTf,HTg)=1 THEN
               IF EQUAL(f,g)<>1 THEN CS:=TRUE; END; 
            ELSE
	       NewHT:=TRUE; CS:=TRUE;
            END; (* IF EQUAL... *)
	    H:=COMP(g,H);
	 END; (* IF g<>0... *)
      END; (* WHILE ... *)
      P:=H;
   UNTIL NOT(NewHT);
END DIPIRL;


PROCEDURE DIPLIR(P: LIST): LIST;
(* distributive polynomial list interreduce.
   P is a list of polynomials in distributive representation
   over an arbitrary domain,
   returns a interreduced list of polynomials R=(p1,...,pk),
   R is the result of reducing each pi modulo R-(pi)
   until no further reductions are possible. *)
VAR H,f,HTf,HTg,g: LIST;
    NewHT: BOOLEAN;
BEGIN
   REPEAT
      H:=SIL; NewHT:=FALSE;
      WHILE P<>SIL DO
	 ADV(P,f,P);
	 HTf:=DIPEVL(f);
	 g:=DIPNF(CCONC(P,H),f);
	 IF g<>0 THEN
	    HTg:=DIPEVL(g);
            IF EQUAL(HTf,HTg)<>1 THEN NewHT:=TRUE; END;
	    H:=COMP(g,H);
	 END; (* IF g<>0... *)
      END; (* WHILE ... *)
      P:=H;
   UNTIL NOT(NewHT);
   RETURN(P);
END DIPLIR;


PROCEDURE DIPRLF(P,p: LIST): LIST;
(* distributive polynomials reduce list of polynomials with factor.
   P is a list of polynomials in distributive representation
   over an arbitrary domain, p is a polynomial of same kind,
   returns a list of reduced polynomials R=(p1,...,pk),
   R is the result of reducing each polynomial of P  modulo (p) *)
VAR H,f,g: LIST;
BEGIN
   H:=SIL;
   WHILE P<>SIL DO
      ADV(P,f,P);
      g:=DIPNF(LIST1(p),f);
      IF g<>0 THEN H:=COMP(g,H); END;
   END; (* WHILE P... *)
   RETURN(H);
END DIPRLF;


PROCEDURE DIPMOC(A: LIST): LIST; 
(*Distributive polynomial monic. A and A are
distributive polynomials, C=A/lbc(A) if A ne 0
C=0 if A eq 0. *)
VAR  BL, C, CL, SL: LIST; 
BEGIN
(*1*) (*a=0.*) C:=A; 
      IF A = 0 THEN RETURN(C); END; 
(*2*) (*multiply.*) BL:=DIPLBC(A); SL:=ADONE(BL); 
      IF SL = 1 THEN RETURN(C); END; 
      SL:=ADINVT(BL); 
      IF SL <> 1 THEN RETURN(C); END; 
      CL:=ADINV(BL); C:=DIPBCP(A,CL); 
(*5*) RETURN(C); END DIPMOC; 


PROCEDURE DIPNEG(A: LIST): LIST; 
(*Distributive polynomial negative. B= -A.*)
VAR  AL, AS, B, BL, EL: LIST; 
BEGIN
(*1*) (*a=0.*) 
      IF A = 0 THEN B:=0; RETURN(B); END; 
(*2*) (*general case.*) AS:=A; B:=BETA; 
      REPEAT DIPMAD(AS, AL,EL,AS); BL:=ADNEG(AL); B:=DIPMCP(EL,BL,B); 
             UNTIL AS = SIL; 
      B:=INV(B); RETURN(B); 
(*5*) END DIPNEG; 


PROCEDURE DIPNF(A,B: LIST): LIST;
(* distributive polynomial normalform.
   A is a list of polynomials in distributive representation,
   B is a polynomial as above,
   returns a polynomial h such that B is reducible to h
   modulo A and h is in normalform with respect to A *)
BEGIN
   RETURN(ADPNF(A,B));
END DIPNF;


PROCEDURE DIPQR(A,B: LIST;  VAR Q,R: LIST); 
(*Distributive polynomial quotient and remainder.
A and B are distributive polynomials with B ne 0.
Q and R are unique distributive rational polynomials such
that either B divides A, so Q=A/B and R=0  or B does not
divide A, so A=B*Q+R with deg(R) lt deg(B). *)
VAR  AL, BL, BP, DL, ML, NL, Q1, QL, QP, RP, SL, TL: LIST; 
BEGIN
(*1*) (*initialise.*) DIPMAD(B, BL,NL,BP); 
      IF BP = SIL THEN BP:=0; END; 
      Q:=BETA; R:=A; 
(*2*) (*compute quotient terms.*) 
LOOP
      WHILE R <> 0 DO ML:=DIPEVL(R); EVDFSI(ML,NL, DL,TL); 
            IF TL < 0 THEN EXIT (*GO TO 3;*) END; 
            AL:=DIPLBC(R); QL:=ADQUOT(AL,BL); Q:=DIPMCP(DL,QL,Q); 
            Q1:=DIPFMO(QL,DL); RP:=DIPMRD(R); QP:=DIPROD(BP,Q1); 
            R:=DIPDIF(RP,QP); END; 
      EXIT; END;
(*3*) (*finish.*) 
      IF Q = SIL THEN Q:=0; ELSE Q:=INV(Q); END; 
      RETURN; 
(*6*) END DIPQR; 


PROCEDURE DIPROD(A,B: LIST): LIST; 
(*Distributive polynomial product. A and B are
distributive polynomials. C=A*B.*)
VAR  AL, AP, AS, BL, BS, C, C1, CL, CS, EL, FL, GL: LIST; 
BEGIN
(*1*) (*a or b zero.*) 
      IF (A = 0) OR (B = 0) THEN C:=0; RETURN(C); END; 
(*2*) (*general case.*) AS:=CINV(A); BS:=B; C:=LIST1(0); CS:=C; 
      REPEAT DIPMAD(BS, BL,FL,BS); AP:=AS; C1:=BETA; 
             REPEAT DIPMAD(AP, EL,AL,AP); CL:=ADPROD(AL,BL); 
                    GL:=EVSUM(EL,FL); C1:=DIPMCP(CL,GL,C1); 
                    UNTIL AP = SIL; 
             C:=COMP(C1,C); 
             UNTIL BS = SIL; 
      ADV(C, C1,C); SFIRST(CS,C1); SRED(CS,C); C:=DILSUM(C); 
(*5*) RETURN(C); END DIPROD; 


PROCEDURE DIPS(A,B: LIST): LIST;
(* distributive polynomial S-polynomial.
   A and B are polynomials in distributive representation,
   returns the S-polynomial of A and B *)
BEGIN
   RETURN(ADPSP(A,B));
END DIPS;


PROCEDURE DIPSFF(A,VOO: LIST): LIST;
(* distributive polynomial squarefree factorization.
   A is a polynomial in distributive representation,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,p1),...,(ek,pk)), ei positive integers,
   pi squarefree polynomials in distributive representation,
   where A = u * p1**e1 * ... * pk**ek and u unit. *)
BEGIN
   IF A=0 THEN RETURN(SIL); END;
   RETURN(ADPSFF(A,VOO));
END DIPSFF;


PROCEDURE DIPSUM(A,B: LIST): LIST; 
(*Distributive polynomial sum. A and B are
distributive polynomials. C=A+B. *)
VAR  AL, AP, APP, BL, BP, C, CL, CP, CPP, EL, FL, SL: LIST; 
BEGIN
(*1*) (* a or b zero.*) 
      IF A = 0 THEN C:=B; RETURN(C); END; 
      IF B = 0 THEN C:=A; RETURN(C); END; 
(*2*) (*match coefficients.*) AP:=A; BP:=B; CP:=BETA; 
      REPEAT EL:=DIPEVL(AP); FL:=DIPEVL(BP); SL:=EVCOMP(EL,FL); 
             IF SL = 1 THEN DIPMAD(AP, AL,EL,AP); 
                CP:=DIPMCP(EL,AL,CP); ELSE
                IF SL = -1 THEN DIPMAD(BP, BL,FL,BP); 
                   CP:=DIPMCP(FL,BL,CP); ELSE DIPMAD(AP, AL,EL,AP); 
                   DIPMAD(BP, BL,FL,BP); CL:=ADSUM(AL,BL); 
                   IF ADSIGN(CL) <> 0 THEN CP:=DIPMCP(EL,CL,CP); 
                   END; 
                   END; 
                END; 
             UNTIL (AP = SIL) OR (BP = SIL); 
(*3*) (*finish.*) 
      IF AP = SIL THEN APP:=BP; ELSE APP:=AP; END; 
      IF CP = SIL THEN C:=APP; ELSE CPP:=CP; C:=INV(CP); 
         SRED(CPP,APP); END; 
      IF C = SIL THEN C:=0; END; 
      RETURN(C); 
(*6*) END DIPSUM; 


PROCEDURE DIREAD(V,D: LIST): LIST; 
(*Distributive polynomial read. V is a variable list.
a distributive polynomial A in r variables, where
r=length(V), r ge 0, is read from the input stream. any
blanks preceding A are skipped. *)
VAR  A, A1, AL, AP, C, EL, ES, FL, IL, JL, RL, VL: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) A:=0; C:=CREADB(); 
      IF C = MASORD("0") THEN RETURN(A); END; 
      BKSP; 
(*2*) (*initialise.*) C:=CREADB(); BKSP; 
      IF C = MASORD(",") THEN (*GO TO 7;*) 
         ERROR(severe,"ERROR FOUND BY DIREAD.");  
         RETURN(A); END; 
      FL:=0; 
      IF C = MASORD("(") THEN C:=CREADB(); FL:=1; END; 
      IF C = MASORD(")") THEN
         IF FL = 1 THEN RETURN(A); END; 
         (*GO TO 7;*) ERROR(severe,"ERROR FOUND BY DIREAD.");  
         RETURN(A); END; 
      RL:=LENGTH(V); ES:=BETA; 
      FOR IL:=1 TO RL DO ES:=COMP(0,ES); END; 
      AL:=ADFI(D,1); A1:=DIPFMO(AL,ES); AP:=A1; 
LOOP LOOP
(*3*) (*next input. determine next action. *) C:=CREADB(); 
      IF C = MASORD(")") THEN
         IF FL = 0 THEN BKSP; END; 
         RETURN(A); END; 
      IF C = MASORD(",") THEN BKSP; RETURN(A); END; 
      IF C = MASORD("-") THEN AP:=DIPNEG(AP); END; 
      IF (C = MASORD("+")) OR (C = MASORD("-")) THEN C:=CREADB(); END; 
      IF C = MASORD("*") THEN C:=CREADB(); END; 
      BKSP; 
(*4*) (*read coefficient.*) 
      IF DIGIT(C) OR (C = MASORD("(")) THEN AL:=ADREAD(D); 
         EL:=EPREAD(); 
         IF ADSIGN(AL) = 0 THEN AP:=0; ELSE AL:=ADEXP(AL,EL); 
            AP:=DIPBCP(AP,AL); END; 
         EXIT; (*GO TO 8;*) END; 
(*6*) (*read monic monomial.*) 
      IF LETTER(C) THEN VL:=VREAD(); JL:=VLSRCH(VL,V); 
         IF JL = 0 THEN BACKUB; AL:=ADREAD(D); 
            IF ADONE(AL) = 1 THEN (*GO TO 7;*)
               ERROR(severe,"ERROR FOUND BY DIREAD.");  
               RETURN(A); END; 
            EL:=EPREAD(); 
            IF ADSIGN(AL) = 0 THEN AP:=0; ELSE AL:=ADEXP(AL,EL); 
               AP:=DIPBCP(AP,AL); END; 
            ELSE EL:=EPREAD(); AP:=DIPMPV(AP,JL,EL); END; 
         EXIT; (*GO TO 8;*) END; 
      END;
(*7*) (*error.*)  
(*8*) (*complete polynomial.*) C:=CREADB(); BKSP; 
      IF (((C = MASORD("+")) OR (C = MASORD("-"))) OR (C = MASORD(")")))
      OR (C = MASORD(",")) THEN A:=DIPSUM(A,AP); AP:=A1; END; 
      END; (*GO TO 3;*) 
(*11*) END DIREAD; 


PROCEDURE DIWRIT(A,V: LIST); 
(*Distributive polynomial write. A is a distributive
polynomial in r variables, r ge 0. V is a variable list
for A. A is written in the output stream. *)
VAR   AL, AS, E, EL, FL, ES, LL, RL, SL, TL, VL, VS: LIST; 
BEGIN
(*1*) (*rl=0 or a=0.*) 
      IF A = 0 THEN AWRITE(A); RETURN; END; 
      RL:=DIPNOV(A); 
      IF RL = 0 THEN ADWRIT(DIPLBC(A)); RETURN; END; 
(*2*) (*general case.*) AS:=A; FL:=0; LL:=DIPNBC(A); 
      IF LL > 1 THEN SWRITE("("); END; 
      REPEAT DIPMAD(AS, AL,E,AS); SWRITE(" "); SL:=ADSIGN(AL); 
             IF FL <> 0 THEN 
                IF SL > 0 THEN SWRITE("+"); END; 
                IF SL < 0 THEN SWRITE("-"); AL:=ADNEG(AL); END; 
                END;
             FL:=1; TL:=EVSIGN(E); 
             IF TL = 0 THEN ADWRIT(AL); 
                ELSE SL:=ADONE(AL); 
                IF SL <> 1 THEN ADWRIT(AL); END; 
                ES:=CINV(E); VS:=V; 
                REPEAT ADV(ES, EL,ES); ADV(VS, VL,VS); 
                       IF EL > 0 THEN SWRITE(" "); CLOUT(VL); 
                          IF EL > 1 THEN SWRITE("**"); 
                             AWRITE(EL); END; 
                          END; 
                       UNTIL ES = SIL; 
                END; 
             UNTIL AS = SIL; 
      SWRITE(" "); 
      IF LL > 1 THEN SWRITE(")"); END; 
(*5*) RETURN; END DIWRIT; 


END DIPADOM.
(* -EOF- *)
