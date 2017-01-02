(* ----------------------------------------------------------------------------
 * $Id: MASYMDIP.mi,v 1.7 1995/11/04 22:14:42 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASYMDIP.mi,v $
 * Revision 1.7  1995/11/04 22:14:42  pesch
 * New procedures EVOWRITE and EvordWrite.
 *
 * Revision 1.6  1993/05/11  10:56:36  kredel
 * Added modules MASUGB DIPIDGB DIPDDGB
 *
 * Revision 1.5  1993/03/23  12:13:51  kredel
 * Improved linear form processing
 *
 * Revision 1.4  1992/10/16  14:23:30  kredel
 * Change in DIPVDEF
 *
 * Revision 1.3  1992/10/15  16:30:44  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:57  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:23  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASYMDIP;
 
(* MAS Symbol to DIP Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR	IMPORT	ADV, BETA, COMP, FIRST, INV, LENGTH, LIST, LIST1,
			RED, SIL;

FROM MASERR	IMPORT	ERROR, severe;


FROM MASBIOS	IMPORT	BKSP, BLINES, CREADB, LISTS, MASORD, SWRITE;

FROM MASBIOSU	IMPORT	CLTIS;

FROM SACLIST	IMPORT	CCONC, CINV, CLOUT, COMP2, LIST2, LIST3;

FROM SACSET	IMPORT	USDIFF, USUN;

FROM MASSYM2	IMPORT	ENTER, EXPLOD, GET, PUT, SYMBOL;

FROM MASSYM	IMPORT	ELEMP, UWRITE;

FROM MASLISPU	IMPORT	Compiledf0, Compiledf1, Compiledf2, Compiledp0,
			Compiledp1, Compiledp2, Declare, EXPR, EXTYP;

FROM MASLISP	IMPORT	ADD, DF, ENV, MUL, POW, QUOT, QUOTE, STRNG, SUB;

FROM MASSPEC	IMPORT	EVALUATE;

FROM SACRN	IMPORT	RNCOMP, RNDEN, RNINT, RNNEG, RNNUM, RNRED;

FROM MASAPF	IMPORT	RNDRD;

FROM SACPOL	IMPORT	PFDP, VLREAD, VLSRCH, VLWRIT;

FROM DIPC	IMPORT	DILFPL, DIPFMO, DIPFP, DIPMAD, DIPMPV, EVORD,
			EVOWRITE, IGRLEX, INVLEX, PFDIP, PLFDIL, VALIS;

FROM DIPI	IMPORT	DIIFRP, DIILFR, DIILFRCD, DIILRD, DIILWR;

FROM DIPRN	IMPORT	DIRFIP, DIRLRD, DIRLWR, DIRPDF, DIRPEX, DIRPNG,
			DIRPPR, DIRPSM;

FROM DIPTOO	IMPORT	LFCHECK;



CONST rcsidi = "$Id: MASYMDIP.mi,v 1.7 1995/11/04 22:14:42 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1995 Universitaet Passau";



(* Procedure declarations. *)

(* --- bios - dip interface --- *)

PROCEDURE dirlwr(a, b, c: LIST): LIST;
(*write polynomial list. *)
BEGIN 
(*1*) DIRLWR(a,b,c); 
      RETURN(c);  
(*2*) END dirlwr;


PROCEDURE pdread(): LIST;
(*read polynomial descriptor, i.e. variable list and term order. *)
VAR   P, T, V, E, Q, r, X: LIST;
BEGIN P:=SIL;
(*1*) REPEAT V:=VLREAD(); BLINES(1);
             UNTIL V <> SIL;
      VALIS:=V;
(*2*) REPEAT E:=CREADB(); BLINES(1);
             UNTIL    (E = MASORD("(")) 
                   OR (E = MASORD("L")) 
                   OR (E = MASORD("G"));
      IF E = MASORD("L") THEN EVORD:=INVLEX END;
      IF E = MASORD("G") THEN EVORD:=IGRLEX END;
      IF E = MASORD("(") THEN BKSP; T:=LIST1(LIST1(MASORD("T"))); 
         X:=EVORD; EVORD:=INVLEX;
         P:=DIRLRD(T); 
         P:=DIILFRCD(P); (* jetzt richtig, ist auf hauptnenner *)
         PLFDIL(P, r,Q); 
         EVORD:=X;
         IF LENGTH(Q) <> LENGTH(V) THEN 
            SWRITE("Wrong number of polynomials."); BLINES(0);
            ELSE IF LFCHECK(Q,1) THEN EVORD:=INV(Q) END
                 END;
         END;
       RETURN(COMP(V,LIST1(EVORD)))
(*3*) END pdread;


PROCEDURE preadd(D: LIST): LIST;
(*read polynomial list, for given variable list and term order. *)
VAR   P, V: LIST;
BEGIN P:=SIL;
(*1*) V:=FIRST(D);
(*3*) REPEAT P:=DIRLRD(V); 
             UNTIL P <> SIL;
      RETURN(P)
(*9*) END preadd;


PROCEDURE pread(): LIST;
(*read polynomial list, including variable list and term order. *)
VAR   P, V, X: LIST;
BEGIN P:=SIL;
(*1*) X:=pdread(); V:=FIRST(X);
(*3*) REPEAT SWRITE("Enter polynomial list: "); P:=DIRLRD(V); BLINES(0);
             UNTIL P <> SIL;
      RETURN(P)
(*9*) END pread;


PROCEDURE preadi(): LIST;
(*read polynomial list, including variable list and term order. *)
VAR   P, V, X: LIST;
BEGIN P:=SIL;
(*1*) X:=pdread(); V:=FIRST(X);
(*3*) REPEAT SWRITE("Enter polynomial list: "); P:=DIILRD(V); BLINES(0);
             UNTIL P <> SIL;
      RETURN(P)
(*9*) END preadi;


PROCEDURE pdwrite(D: LIST);
(*write polynomial descriptor, i.e. variable list and term order. *)
VAR   V, E, L, T, X: LIST;
BEGIN ADV(D, V, E); E:=FIRST(E);
(*1*) SWRITE("Polynomial in the variables: "); VLWRIT(V); BLINES(1);
(*2*) SWRITE("Term ordering: "); 
      EVOWRITE(E);
      BLINES(1);
(*3*) END pdwrite;


PROCEDURE pwrite(P: LIST);
(*write polynomial list, including variable list and term order. *)
VAR   D, L, T, X: LIST;
BEGIN 
(*1*) D:=COMP(VALIS,LIST1(EVORD)); pdwrite(D);
(*3*) SWRITE("Polynomial list: "); DIRLWR(P,VALIS,-1); BLINES(1);
(*9*) END pwrite;


PROCEDURE pwritei(P: LIST);
(*write polynomial list, including variable list and term order. *)
VAR   D, L, T, X: LIST;
BEGIN 
(*1*) D:=COMP(VALIS,LIST1(EVORD)); pdwrite(D);
(*3*) SWRITE("Polynomial list: "); DIILWR(P,VALIS); BLINES(1);
(*9*) END pwritei;


PROCEDURE pwrited(D, P: LIST);
(*write polynomial list, not including variable list and term order. *)
VAR   V: LIST;
BEGIN 
(*1*) V:=FIRST(D);
(*3*) DIRLWR(P,V,-1); BLINES(0);
(*9*) END pwrited;


(* --- sym - dip interface --- *)

PROCEDURE DIPVDEF(V: LIST): LIST;
(*DIP define distributive polynomial variable list. 
V is a variable list. The new variable list is returned. *)
VAR   VP, v: LIST;
BEGIN 
(*1*) VP:=SIL;
      WHILE V <> SIL DO ADV(V, v, V);
            IF v <> SIL THEN (*remove STRING tag *) 
               IF FIRST(v) >= SIL THEN v:=RED(v) END; 
               END;
            VP:=COMP(v,VP); END;  
      VP:=INV(VP); 
      VALIS:=VP; RETURN(VP);
(*9*) END DIPVDEF;


PROCEDURE DIPTODEF(T: LIST): LIST;
(*DIP define distributive polynomial term order. 
V is a term order indicator. The old term order indicator 
is returned. *)
VAR   TP: LIST;
BEGIN 
(*1*) TP:=EVORD; EVORD:=T;
      RETURN(TP);
(*9*) END DIPTODEF;


PROCEDURE SYM2DIP(T: LIST): LIST;
(*Symbol term list to distributive rational polynomial list. *)
VAR   D, DP, TP, VP, V, v, n: LIST;
BEGIN 
(*1*) VP:=TVARS(T); V:=SIL;
      WHILE VP <> SIL DO ADV(VP,v,VP);
            n:=EXPLOD(v);
            V:=COMP(n,V); 
            END;
      V:=INV(V); 
      V:=USDIFF(V,VALIS);
      IF V <> SIL THEN VP:=V;
         BLINES(0); SWRITE("Variable(s) added to VALIS: "); 
         WHILE V <> SIL DO ADV(V,v,V); CLOUT(v);
               IF V <> SIL THEN SWRITE(", ") END;
               END;
         BLINES(0); VALIS:=CCONC(VALIS,VP);
         END;
(*2*) D:=SIL;
      WHILE T <> SIL DO ADV(T,TP,T);
            DP:=DIRPFT(TP,VALIS); D:=COMP(DP,D); 
            END;
      D:=INV(D); RETURN(D);
(*9*) END SYM2DIP;


PROCEDURE DIP2SYM(D: LIST): LIST;
(*Distributive rational polynomial list to symbol term list. *)
VAR   DP, TP, T, V, VP, v, n: LIST;
BEGIN 
(*1*) V:=VALIS; VP:=SIL;
      WHILE V <> SIL DO ADV(V,n,V);
            v:=ENTER(n);
            VP:=COMP(v,VP); 
            END;
      VP:=INV(VP);
(*2*) T:=SIL;
      WHILE D <> SIL DO ADV(D,DP,D);
            TP:=TFDIRP(DP,VP); T:=COMP(TP,T); 
            END;
      T:=INV(T);  
      RETURN(T);
(*9*) END DIP2SYM;


PROCEDURE TVARS(T: LIST): LIST;
(*Term variables. T is a term. The list of variables 
occuring in T is returned. *)
VAR   V, v, t, TP: LIST;
BEGIN 
(*1*) (*recursion base. *) V:=SIL; 
      IF T <= BETA THEN RETURN(V) END;
      IF SYMBOL(T) THEN 
         IF GET(T,EXTYP) <> SIL THEN RETURN(V) END; 
         V:=LIST1(T); RETURN(V) END;
(*2*) (*list. *) TP:=T;
      WHILE TP <> SIL DO ADV(TP,t,TP);
            v:=TVARS(t); 
            IF v <> SIL THEN V:=USUN(v,V) END;
            END;
      RETURN(V);
(*9*) END TVARS;


PROCEDURE DIRPFT(T, V: LIST): LIST; 
(*Distributive rational polynomial from term. T is a term,
V is a variable list. A distributive rational polynomial 
A in r variables, where r=length(V), r ge 0, is formed 
from term T. *)
VAR   A, A1, AP, TP, t, tp, v, IL, JL, RL, ES: LIST; 
BEGIN
(*1*) (*r=0 or a=0.*) A:=0;  
      IF T = 0 THEN RETURN(A); END; 
(*2*) (*initialise.*)  
      RL:=LENGTH(V); ES:=SIL; 
      FOR IL:=1 TO RL DO ES:=COMP(0,ES); END; 
(*3*) (*base.*)  
      IF ELEMP(T) THEN A:=DIPFMO(RNINT(T),ES); RETURN(A) END;
      A1:=DIPFMO(RNINT(1),ES); 
      IF SYMBOL(T) THEN v:=EXPLOD(T); JL:=VLSRCH(v,V);
         IF JL = 0 THEN SWRITE("variable: "); CLOUT(v); BLINES(0);
            ERROR(severe,"DIRPFT variable not defined.") END;
         A:=DIPMPV(A1,JL,1); RETURN(A) END;
(*4*) (*functional term. determine next action. *) ADV(T,t,TP); 
      IF    t = ADD THEN A:=0;
                    WHILE TP <> SIL DO ADV(TP,t,TP); 
                          AP:=DIRPFT(t,V); A:=DIRPSM(A,AP);
                          END;
      ELSIF t = SUB THEN ADV(TP,t,TP); AP:=DIRPFT(t,V);
                    IF TP = SIL 
                       THEN A:=DIRPNG(AP);
                       ELSE A:=AP;
                       WHILE TP <> SIL DO ADV(TP,t,TP); 
                             AP:=DIRPFT(t,V); A:=DIRPDF(A,AP);
                            END;
                       END;
      ELSIF t = MUL THEN A:=A1;
                    WHILE TP <> SIL DO ADV(TP,t,TP); 
                          AP:=DIRPFT(t,V); A:=DIRPPR(A,AP);
                          END;
      ELSIF t = QUOT THEN ADV(TP,t,TP); tp:=FIRST(TP);
                          AP:=RNRED(t,tp); A:=DIPFMO(AP,ES);
      ELSIF t = POW THEN ADV(TP,t,TP); A:=DIRPFT(t,V);
                    t:=FIRST(TP); A:=DIRPEX(A,t);
      ELSIF t = STRNG THEN TP:=CCONC(TP,LISTS(" ")); 
                      CLTIS(TP); AP:=RNDRD();
                      A:=DIPFMO(AP,ES);
       ELSE BLINES(0); SWRITE("name="); UWRITE(t); 
            ERROR(severe,"DIRPFT, no allowed function.");
            END;
      RETURN(A); 
(*9*) END DIRPFT; 


PROCEDURE TFDIRP(A, V: LIST): LIST; 
(*Term from distributive rational polynomial. A is a distributive 
rational polynomial in r variables, where r=length(V), r ge 0,
V is a symbol list. A term T is formed from A. *)
VAR   T, AP, TP, t, tp, VP, v, a, E, EP, e, s: LIST; 
BEGIN
(*1*) IF A = 0 THEN RETURN(0) END;
(*2*) AP:=A; T:=SIL;
      REPEAT DIPMAD(AP,a,E,AP); t:=SIL;
             s:=RNCOMP(a,0);
             IF s < 0 THEN a:=RNNEG(a) END; 
             IF RNDEN(a) <> 1 THEN t:=LIST3(QUOT,RNNUM(a),RNDEN(a))
                              ELSE a:=RNNUM(a);
                                   IF (a <> 1) OR (s < 0) THEN t:=a END; 
                                   END;
             IF s < 0 THEN t:=LIST2(SUB,t) END;
             EP:=CINV(E); VP:=V;
             WHILE EP <> SIL DO ADV(EP,e,EP); ADV(VP,v,VP);
                   IF e > 0 THEN
                      IF e > 1 THEN tp:=LIST3(POW,v,e)
                               ELSE tp:=v END;
                      IF t = SIL THEN t:=tp
                                 ELSE t:=LIST3(MUL,t,tp) END;
                      END;
                   END;
             IF t = SIL THEN t:=1 END;
             IF T = SIL THEN T:=t
                        ELSE T:=LIST3(ADD,T,t) END;
             UNTIL AP = SIL;
      RETURN(T); 
(*9*) END TFDIRP; 


PROCEDURE TERM(P: LIST): LIST;
(*Return quoted term from DIP2SYM. *)
VAR   X: LIST;
BEGIN 
(*1*) X:=DIP2SYM(P);
      X:=LIST2(QUOTE,X); RETURN(X);
(*9*) END TERM;


PROCEDURE mkpoly;
(*Make POLY F-expression. 
(DF POLY (X) (SYM2DIP X)). *)
VAR   X, f, Y, Z: LIST;
BEGIN 
(*1*) Declare(X,"X"); Declare(f,"SYM2DIP");
      Z:=LIST1(X); Y:=COMP(f,Z); 
      Y:=LIST2(Z,Y);
(*2*) Declare(f,"POLY");
      Y:=COMP2(DF,f,Y); 
(*3*) Y:=EVALUATE(Y,ENV);
(*9*) END mkpoly;


PROCEDURE InitExternalsI;
(*Initialize external compiled interface procedures. *)
BEGIN 
(*1*) (*from symbol interface. *)
      Compiledf1(TVARS,"TVARS");
      Compiledf1(DIPVDEF,"DIPVDEF");
      Compiledf1(DIPTODEF,"DIPTODEF");
      Compiledf2(DIRPFT,"DIRPFT");
      Compiledf2(TFDIRP,"TFDIRP");
      Compiledf1(SYM2DIP,"SYM2DIP");
      Compiledf1(DIP2SYM,"DIP2SYM");
      Compiledf1(TERM,"TERM");
      mkpoly;
(*8*) (*from bios interface. *)
      Compiledf0(pread,"PREAD");
      Compiledp1(pwrite,"PWRITE");
      Compiledf0(preadi,"PREADI");
      Compiledp1(pwritei,"PWRITEI");
      Compiledf0(pdread,"PDREAD");
      Compiledp1(pdwrite,"PDWRITE");
      Compiledf1(preadd,"PREADD");
      Compiledp2(pwrited,"PWRITED");
(*9*) END InitExternalsI;


END MASYMDIP.



(* -EOF- *)
