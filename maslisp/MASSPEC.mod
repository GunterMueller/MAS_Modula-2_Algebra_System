(* ----------------------------------------------------------------------------
 * $Id: MASSPEC.mi,v 1.4 1995/11/05 08:58:48 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSPEC.mi,v $
 * Revision 1.4  1995/11/05 08:58:48  kredel
 * Small letter exit, more trace infos and correction.
 *
 * Revision 1.3  1992/10/15  16:27:52  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:30  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:26  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSPEC;

(* MAS Specification Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT BETA, SIL, LIST, LENGTH, 
                    LIST1, ADV, FIRST, RED, COMP, INV, SFIRST, SRED;

FROM MASERR IMPORT ERROR, severe, harmless, spotless;

FROM MASBIOS IMPORT LISTS, BLINES, SWRITE;

FROM MASBIOSU IMPORT CLTIS;

FROM SACLIST IMPORT EQUAL, RED2, CINV, CONC, CCONC,
                    FIRST3, LIST3, LIST4, FIRST4, SECOND, THIRD, RED3,
                    FIRST2, ADV2, LIST2, COMP2, COMP3;

FROM MASSYM2 IMPORT SYMBOL, ASSOC, ASSOCQ, GET, PUT, SUBLIS; 

FROM MASSYM IMPORT ATOM, ELEMP, UWRITE, UWRIT1, 
                   UNIFY, GENARRAY, ARRAYDEC;

FROM MASLISPU IMPORT EXTYP, ARITY, SUBR, EXPR, PROCP,
                     CallCompiled, Signature;

FROM MASLISP IMPORT FEXPR, MACRO, GENERIC,
                    REP, FER, FERx, FEL, FELx,
                    CONVVAL, CONVDES, 
                    trace, stricttyping,
                    TDEF, DEFAULT, ARROW, (*indicators*)
                    ENV, (*global environement (alist)*)
                    NULL, WT, SCHLUSS, schluss, TINFO,   

                    EQS, NEQS, GTS, LTS, GEQ, LEQ, NOTS, UND, ODER,   
                    ADD, SUB, MUL, QUOT, REM, POW,

                    QUOTE, SETQ, COND, LISTX, 
                    ASSIGN, READ, WRITE, DECREAD, DECWRITE, 
    
                    PROGN, VARS, IFS, WHL, RPT, STRNG, DE, DF, DM, DG,  
                    PROGA, GTO, LBEL, ARY, SETAV, ATM, RTN, ANY,

                    UNIT, EXPOS, SPEC, SORT, SIG, IMPRT, IMPL, 
                    MODEL, MAP, AXIOM, RULE, WHEN, 
   
                    LAMBDA, FLAMBDA, MLAMBDA, GLAMBDA,
                    SPECIALFORM, LAMBDAP, SEXPRP,

                    SETV, EXTENDENV, COPYTOENV, 
                    DEFE, DEFF, DEFM, 
                    DEFMAP, DEFRULE, DEFPROC, DSPEC, DMIA, 

                    TYPEOF, TAG, VALOFTAG, DECOFTAG, TYPOFTAG,
                    ECENV, DCENV, GENPL, GENTE;


VAR  unwind: BOOLEAN;
     goto: LIST;

CONST rcsidi = "$Id: MASSPEC.mi,v 1.4 1995/11/05 08:58:48 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE APPLY(F, X: LIST; VAR ENV: LIST): LIST;
(*Apply function. F is a function symbol or lambda expression.
X is a list of un-evaluated arguments. F is applied to X. *)
VAR   XP, Y, Z, L, X1, X2, FP, A, B, EP, ES, I, O, OP: LIST;
      t: BOOLEAN;
BEGIN
(*1*) (*initialize*) Z:=SIL; 
      IF ELEMP(F) THEN UWRITE(F); 
         ERROR(severe,"APPLY: invalid function object."); 
         RETURN(Z) END; 
      IF trace THEN SWRITE("APPLY:  "); UWRITE(COMP(F,X)) END;
(*2*) (*branch on special function. *) 
      IF SYMBOL(F) THEN X:=EVLIS(X,ENV);
      IF F = ADD  THEN ADV(X,Z,XP);
                       WHILE XP <> SIL DO ADV(XP,X1,XP);
                             Z:=Z+X1 END; 
                       RETURN(Z) END;
      IF F = SUB  THEN ADV(X,Z,XP);
                       IF XP = SIL THEN Z:=-Z; RETURN(Z) END;
                       WHILE XP <> SIL DO ADV(XP,X1,XP);
                             Z:=Z-X1 END; 
                       RETURN(Z) END;
      IF F = NEQS THEN FIRST2(X,X1,X2); IF X1 <> X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = GTS  THEN FIRST2(X,X1,X2); IF X1 > X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = LTS  THEN FIRST2(X,X1,X2); IF X1 < X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = LEQ  THEN FIRST2(X,X1,X2); IF X1 <= X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = GEQ  THEN FIRST2(X,X1,X2); IF X1 >= X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = EQS  THEN FIRST2(X,X1,X2); IF X1 = X2 THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = MUL  THEN ADV(X,Z,XP);
                       WHILE XP <> SIL DO ADV(XP,X1,XP);
                             Z:=Z*X1 END; 
                       RETURN(Z) END;
      IF F = QUOT THEN ADV(X,Z,XP);
                       WHILE XP <> SIL DO ADV(XP,X1,XP);
                             Z:=Z DIV X1 END; 
                       RETURN(Z) END;
      IF F = REM  THEN ADV(X,Z,XP);
                       WHILE XP <> SIL DO ADV(XP,X1,XP);
                             Z:=Z MOD X1 END; 
                       RETURN(Z) END;
      IF F = NOTS THEN ADV(X,Z,XP);
                       IF Z = SIL THEN Z:=WT ELSE Z:=SIL END;
                       RETURN(Z) END;
      IF F = UND  THEN FIRST2(X,X1,X2); 
                       IF (X1 <> SIL) AND (X2 <> SIL) THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = ODER THEN FIRST2(X,X1,X2); 
                       IF (X1 <> SIL) OR (X2 <> SIL) THEN Z:=WT END; 
                       RETURN(Z) END;
      IF F = RTN  THEN Z:=FIRST(X);  
                       unwind:=TRUE; RETURN(Z) END;
      IF F = FEL  THEN EP:=LIST2(QUOTE,ENV); EP:=LIST1(EP);
                       X:=CCONC(X,EP); X:=COMP(FELx,X);
                       Z:=EVALUATE(X,ENV);    
                       RETURN(Z) END;
      IF F = FER  THEN EP:=LIST2(QUOTE,ENV); EP:=LIST1(EP);
                       X:=CCONC(X,EP); X:=COMP(FERx,X);
                       Z:=EVALUATE(X,ENV);    
                       RETURN(Z) END;
      IF F = CONVVAL THEN Z:=CONVvalue(X,ENV); RETURN(Z) END;
      IF F = CONVDES THEN Z:=CONVdesc(X,ENV); RETURN(Z) END;
      IF F = GTO  THEN Z:=FIRST(X); goto:=Z; 
                       unwind:=TRUE; RETURN(Z) END;
      (* UWRITE(F); ERROR(severe,"APPLY: invalid function object.");*)
      Z:=COMP(F,X); RETURN(Z); 
      END;
      ADV(F,L,FP); 
(*2*) (*typeinfo tag. *) 
      IF L = TINFO THEN Z:=COMP(F,X); (*reconstruct list*) 
         RETURN(Z) END;
(*3*) (*lambda expression. *)  
      IF L = LAMBDA THEN FIRST2(FP,A,B); FIRST2(A,I,O);
         EP:=ENV; t:=unwind; unwind:=FALSE;
         IF EXTENDVARENV(I,O,X,EP) THEN ES:=EP;
            Z:=EVALUATE(B,EP); 
            XP:=CINV(X); OP:=O; 
            WHILE OP <> SIL DO OP:=RED(OP); ADV(XP,X1,XP);
                  ES:=RED(ES); ADV(ES,X2,ES);
                  SETV(X1,X2,ENV) END;
            END; 
         unwind:=t;
         RETURN(Z) END;
(*4*) (*glambda expression. *)  
      IF L = GLAMBDA THEN X:=EVLIS(X,ENV); 
         Z:=EVGEN(FP,X,ENV); FIRST2(Z,XP,EP); EP:=DCENV(EP); 
         t:=unwind; unwind:=FALSE;
         Z:=EVALUATE(XP,EP);
         unwind:=t;
         RETURN(Z);
         END;
(*5*) (*not known.*)
      UWRITE(F); ERROR(severe,"APPLY: invalid function object.");
      RETURN(Z); 
(*6*) END APPLY;


PROCEDURE APPLYCOMP(F, A: LIST; VAR ENV: LIST): LIST;
(*Apply compiled function. F is a symbol of a compiled function.
X is a list of evaluated arguments. F is applied to X.*)
VAR   B, Z, I, O, PI, PO, V: LIST;
      b, c, v, i: LIST;
      def, fu: BOOLEAN;
BEGIN
(*1*) (*initialize*) Z:=SIL; 
      Signature(F,I,O,def);
      IF NOT def THEN UWRITE(F); 
         ERROR(severe,"APPLYCOMP: unbound compiled procedure."); 
         RETURN(Z) END;
      IF O < 0 THEN O:=0 END;
(*2*) (*prepare input parameters. *) 
      IF LENGTH(A) < I THEN UWRITE(F);
         ERROR(severe,"APPLYCOMP: too few input parameters."); 
         RETURN(Z) END;
      B:=A; PI:=SIL; i:=1;
      WHILE i <= I DO i:=i+1; ADV(B,b,B); 
            c:=EVALUATE(b,ENV);
            PI:=COMP(c,PI) END;
      PI:=INV(PI); V:=B;
(*3*) (*prepare output parameters. *) 
      IF LENGTH(B) < O THEN UWRITE(F);
         ERROR(severe,"APPLYCOMP: too few output parameters."); 
         RETURN(Z) END;
      PO:=SIL; i:=1;
      WHILE i <= O DO i:=i+1; ADV(B,b,B); 
            c:=ASSOC(b,ENV); IF c <> SIL THEN c:=FIRST(c) END;
            PO:=COMP(c,PO) END;
      PO:=INV(PO); 
      IF B <> SIL THEN UWRITE(F);
         ERROR(severe,"APPLYCOMP: too many parameters."); 
         RETURN(Z) END;
(*4*) (*call compiled procedure. *) 
      IF trace THEN SWRITE("EXTERN: "); UWRITE(COMP(F,CCONC(PI,PO))) END;
      CallCompiled(F,PI,PO,fu);
      IF fu THEN Z:=PO; RETURN(Z) END;
(*5*) (*prepare output parameters. *) 
      WHILE PO <> SIL DO ADV(PO,b,PO); ADV(V,v,V);
            SETV(v,b,ENV) END;
      RETURN(Z); 
(*4*) END APPLYCOMP;


PROCEDURE EVALUATE(X: LIST; VAR ENV: LIST): LIST;
(*Lisp evaluator. X is a S-expression. ENV is a 
binding environment. *)
VAR F, Y, Z: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL;
(*2*) (*atoms or symbols. *)
      IF ELEMP(X) THEN RETURN(X) END;
      IF SYMBOL(X) THEN Z:=ASSOC(X,ENV);
         IF Z = SIL THEN Z:=X 
                    ELSE ERROR(spotless,"s c"); (*stack check*)
                         Z:=FIRST(Z); Z:=EVALUATE(Z,ENV) END;
         RETURN(Z) END;
(*3*) (*S-expressions. *)
      IF X > BETA THEN ADV(X, F,Y);
         IF LAMBDAP(F) THEN RETURN(X) END; 
         ERROR(spotless,"s c"); (*stack check*)
         F:=EVALUATE(F,ENV);
         IF SPECIALFORM(F) 
            THEN Z:=COMP(F,Y); Z:=EVALSPFORM(Z,ENV);
            ELSE IF PROCP(F) THEN Z:=APPLYCOMP(F,Y,ENV) 
                             ELSE Z:=APPLY(F,Y,ENV) END; 
            END;
         RETURN(Z) END;
(*4*) (*not known.*) UWRITE(X);
      ERROR(severe,"EVALUATE: invalid form.");  
      RETURN(Z);
(*5*) END EVALUATE;


PROCEDURE EVALSPFORM(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate special form. X is an S-expression. *)
VAR M, XP, F, A, B, FP, Y, Z, EP, W, T, L: LIST;
    t: BOOLEAN;
BEGIN
(*1*) (*initialize*) Z:=SIL; ADV(X,F,XP);
      IF ELEMP(F) THEN UWRITE(F);  
         ERROR(severe,"EVALSPFORM: invalid as function object."); 
         RETURN(Z) END; 
      IF trace THEN SWRITE("SPFORM: "); UWRITE(X) END;
(*2*) (*branch on special function. *)  
      IF SYMBOL(F) THEN
      IF F = ASSIGN  THEN Z:=EVASS(XP,ENV); RETURN(Z) END;
      IF F = TINFO   THEN RETURN(X) END;
      IF F = PROGN   THEN Z:=EVPROGN(XP,ENV); RETURN(Z) END;
      IF F = IFS     THEN ADV(XP,Z,XP); ADV(XP,Y,XP); 
                          Z:=EVALUATE(Z,ENV);
                          IF Z = WT THEN Z:=EVALUATE(Y,ENV) 
                             ELSIF XP <> SIL THEN 
                                   Z:=EVALUATE(FIRST(XP),ENV) END;  
                          RETURN(Z) END;
      IF F = WHL     THEN Z:=EVWHL(XP,ENV); RETURN(Z) END;
      IF F = RPT     THEN Z:=EVRPT(XP,ENV); RETURN(Z) END;
      IF F = QUOTE   THEN Z:=FIRST(XP); RETURN(Z) END;
      IF F = STRNG   THEN Z:=XP; RETURN(Z) END;
      IF F = LISTX   THEN Z:=EVLIS(XP,ENV); RETURN(Z) END;
      IF F = SETQ    THEN ADV(XP,Y,XP); W:=FIRST(XP);
                          Z:=EVALUATE(W,ENV); SETV(Y,Z,ENV); 
                          RETURN(Z) END;
      IF F = SETAV   THEN ADV(XP,Y,XP); W:=FIRST(XP);
                          Z:=EVALUATE(W,ENV); SETaldesV(Y,Z,ENV); 
                          RETURN(Z) END;

      IF F = REP     THEN RETURN(X) END;
      IF F = VARS    THEN Z:=EVVAR(XP,ENV); RETURN(Z) END;
      IF F = DE      THEN Z:=DEFE(XP,ENV); RETURN(Z) END;
      IF F = DF      THEN Z:=DEFF(XP,ENV); RETURN(Z) END;
      IF F = DM      THEN Z:=DEFM(XP,ENV); RETURN(Z) END;
      IF F = ARY     THEN XP:=FIRST(XP); FIRST2(XP,Y,W); W:=EVLIS(W,ENV); 
                          XP:=LIST2(Y,W); Z:=GENARRAY(XP); 
                          Z:=EVALUATE(Z,ENV); RETURN(Z) END;

      IF F = SPEC    THEN Z:=DSPEC(XP,ENV); RETURN(Z) END;
      IF F = IMPL    THEN Z:=DMIA(X,ENV); RETURN(Z) END;
      IF F = MODEL   THEN Z:=DMIA(X,ENV); RETURN(Z) END;
      IF F = AXIOM   THEN Z:=DMIA(X,ENV); RETURN(Z) END;
      IF F = EXPOS   THEN Z:=EVUNIT(XP,ENV); RETURN(Z) END;
      IF F = UNIT    THEN RETURN(X) END;

      IF F = COND    THEN Z:=EVCOND(XP,ENV); RETURN(Z) END;
      IF F = PROGA   THEN Z:=EVPROGA(XP,ENV); RETURN(Z) END;
      IF F = LBEL    THEN Z:=FIRST(XP); RETURN(Z) END;
      IF (F = SCHLUSS) OR (F = schluss) THEN RETURN(F) END;
      (*UWRITE(F); ERROR(severe,"EVALSPFORM: unknown function.");*)
      Z:=X; RETURN(Z); 
      END;
      ADV(F,L,FP);
(*3*) (*mlambda expression. *)  
      IF L = MLAMBDA THEN FIRST2(FP,A,B); 
         XP:=LIST1(LIST2(QUOTE,X));
         EP:=ENV; t:=unwind; unwind:=FALSE;
         IF EXTENDENV(A,XP,EP) THEN Z:=EVALUATE(B,EP); 
            Z:=EVALUATE(Z,EP);
            END; 
         unwind:=t; RETURN(Z) END;
(*4*) (*flambda expression. *)  
      IF L = FLAMBDA THEN FIRST2(FP,A,B); 
         XP:=LIST1(LIST2(QUOTE,XP));
         EP:=ENV; t:=unwind; unwind:=FALSE; 
         IF EXTENDENV(A,XP,EP) THEN Z:=EVALUATE(B,EP) END; 
         unwind:=t; RETURN(Z) END;
(*5*) (*not known.*)
      UWRITE(F); ERROR(severe,"EVALSPFORM: unknown function."); 
      RETURN(Z); 
(*6*) END EVALSPFORM;


PROCEDURE EVCOND(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate condition. X is the reductum of a COND S-expression. *)
VAR XP, Y, Z, C, D: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; XP:=X;
(*2*) (*loop on list of pairs. *)
      WHILE XP <> SIL DO ADV(XP,Y,XP); ADV(Y,C,D);
            C:=EVALUATE(C,ENV);
            IF C <> SIL THEN Z:=EVPROGN(D,ENV); RETURN(Z) END;
            END;             
      RETURN(Z);
(*4*) END EVCOND;


PROCEDURE EVPROGN(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate statement sequence. X is the reductum of a 
PROGN S-expression. *)
VAR XP, Z, Y: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; XP:=X;
(*2*) (*loop on list. *)
      WHILE XP <> SIL DO ADV(XP,Y,XP); 
            Z:=EVALUATE(Y,ENV);
            IF unwind THEN RETURN(Z) END;
            END; 
      RETURN(Z);
(*4*) END EVPROGN;


PROCEDURE EVWHL(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate while. *)
VAR C, B, Z: LIST;
BEGIN
(*1*) (*initialize*) C:=FIRST(X); 
      B:=SECOND(X); Z:=SIL;
(*2*) (*loop if condition is true. *)
      WHILE EVALUATE(C,ENV) <> SIL DO
            Z:=EVALUATE(B,ENV);
            IF unwind THEN RETURN(Z) END;
            END; 
      RETURN(Z);
(*4*) END EVWHL;


PROCEDURE EVRPT(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate repeat. *)
VAR C, B, Z: LIST;
BEGIN
(*1*) (*initialize*) B:=FIRST(X); 
      C:=SECOND(X); 
(*2*) (*loop if condition is true. *)
      REPEAT Z:=EVALUATE(B,ENV);
             IF unwind THEN RETURN(Z) END;
             UNTIL EVALUATE(C,ENV) <> SIL;
      RETURN(Z);
(*4*) END EVRPT;


PROCEDURE EVLIS(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate list. *)
VAR XP, Y, Z: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; XP:=X; 
(*2*) (*loop on list. *)
      WHILE XP <> SIL DO ADV(XP,Y,XP);  
            Y:=EVALUATE(Y,ENV);
            Z:=COMP(Y,Z) END;
      Y:=INV(Z); 
      RETURN(Y);
(*4*) END EVLIS;


PROCEDURE EVASS(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate assignment statement. *)
VAR    XP, Z, Y, T, TP, W: LIST;
       nofu: BOOLEAN;
BEGIN
(*1*) (*initialize*) 
      ADV(X,Y,XP); W:=FIRST(XP); nofu:=TRUE;
(*2*) (*generic assignment ? *)
      IF NOT ATOM(W) THEN 
         IF FIRST(W) = STRNG THEN T:=GET(Y,TDEF); 
            IF T <> SIL THEN TP:=FIRST(T) ELSE TP:=SIL END; 
            IF (TP # SIL)   AND (TP # LISTX) AND 
               (TP # STRNG) AND (TP # ANY) THEN 
               Z:=CONVERT(T,READ,W,ENV);
               SETV(Y,Z,ENV); 
               RETURN(Z) END;
            ELSE nofu:=FALSE (*function calls are allowed*) END;
         END; 
      IF stricttyping AND nofu THEN UWRITE(Y);
         ERROR(severe,"EVASS: no type information available.");
         RETURN(SIL) END; 
(*3*) (*normal evaluate *)  
      Z:=EVALUATE(W,ENV); SETV(Y,Z,ENV); 
      RETURN(Z);
(*4*) END EVASS;


PROCEDURE CONVERT(T,P,S: LIST; VAR ENV: LIST): LIST;
(*Evaluate generic conversion. T is the type of the target 
of the conversion. S is the conversion string. P is the 
conversion generic procedure. *)
VAR   x, D, Z, TP, W, L, F, A, EP: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; F:=SIL; 
      IF ELEMP(T) THEN UWRITE(T); 
         ERROR(severe,"CONVERT: invalid as type."); 
         RETURN(Z) END; 
      TP:=TAG(SIL,T); TP:=LIST1(TP);
(*2*) (*get actual procedure *)
      L:=ASSOC(P,ENV);
      IF L <> SIL THEN L:=FIRST(L) END; (* (glambda n M I E) *)
      IF L <> SIL THEN L:=RED(L) END;
      W:=EVGEN(L,TP,ENV);     
      FIRST2(W,W,EP); EP:=DCENV(EP); 
      IF FIRST(W) = QUOTE THEN UWRITE(T);
         ERROR(severe,"CONVERT: unbound generic procedure for signature."); 
         RETURN(Z) END;
(*3*) (*generate actual call *) A:=S;
      IF FIRST(A) = STRNG THEN A:=RED(A) END; (* remove string inidicator *)
      A:=CCONC(A,LISTS(" ")); (* add terminator *)
      CLTIS(A);               (* put to input stream for read *)
(*4*) (*evaluate *)  
      Z:=EVALUATE(W,EP); 
      RETURN(Z);
(*5*) END CONVERT;


PROCEDURE CONVvalue(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate conversion parse. X=(T,S), T is the type of the target 
of the conversion. S is the conversion string. *)
VAR   TP, T, S: LIST; 
BEGIN
(*1*) IF X = SIL THEN RETURN(SIL) END; 
      FIRST2(X,T,S);
(*2*) TP:=CONVERT(T,READ,S,ENV);
      RETURN(TP);
(*5*) END CONVvalue;


PROCEDURE CONVdesc(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate conversion descriptor. X=(T,S), T is the type of the target 
of the conversion. S is the conversion string. *)
VAR   TP, T, S: LIST; 
BEGIN
(*1*) IF X = SIL THEN RETURN(SIL) END; 
      FIRST2(X,T,S);
(*2*) TP:=CONVERT(LIST2(T,SIL),DECREAD,S,ENV);
      TP:=VALOFTAG(TP); 
      RETURN(TP);
(*5*) END CONVdesc;


PROCEDURE EVVAR(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate var statement. *)
VAR   XP, XPP, Y, T, TS, S, V, v, vd, Z, n, i, s: LIST;
      t: BOOLEAN;
BEGIN
(*1*) (*initialize*) Z:=SIL;
      FIRST2(X, XP, T); 
      T:=EVALUATE(T,ENV); 
      TS:=T; IF NOT SYMBOL(TS) THEN TS:=FIRST(TS) END;
      V:=SIL; XPP:=SIL; v:=LIST2(DEFAULT,T);  v:=EVALUATE(v,ENV);
(*2*) (*loop on variable list. *)
      WHILE XP <> SIL DO ADV(XP,Y,XP); 
            IF NOT ATOM(Y) THEN  
                  IF SYMBOL(Y) THEN PUT(Y,TDEF,T);  
                                    V:=COMP(v,V); XPP:=COMP(Y,XPP); 
               ELSIF FIRST(Y) = ARY THEN Y:=SECOND(Y); FIRST2(Y,n,i); 
                     i:=EVLIS(i,ENV); s:=LIST2(n,i);
                     s:=ARRAYDEC(s);
                     WHILE s <> SIL DO ADV(s,Y,s);
                           PUT(Y,TDEF,T);  
                           V:=COMP(v,V); XPP:=COMP(Y,XPP);
                           END;
                ELSE UWRITE(T);
                     ERROR(severe,"EVVAR: invalid as variable."); 
                     END;    
               END;
            END; 
      V:=INV(V); XPP:=INV(XPP);
(*3*) (*put into environment as local(!!!) variables *)
      t:=EXTENDENV(XPP,V,ENV);
      RETURN(TS);
(*4*) END EVVAR;


PROCEDURE EVSORT(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate sort statement. *)
VAR   XP, Z, Y: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; XP:=X; 
(*2*) (*loop on sort list. *)
      WHILE XP <> SIL DO ADV(XP,Y,XP); 
            Y:=EVALUATE(Y,ENV);
            IF SYMBOL(Y) THEN 
               PUT(Y,SORT,WT); (* note sort indicator *) 
               ELSE UWRITE(Y);
                    ERROR(severe,"EVSORT: invalid as sort name."); 
                    END; 
            END; 
      RETURN(SIL);
(*4*) END EVSORT;


PROCEDURE EVIMPRT(X, SP, EP: LIST; VAR ENV: LIST): LIST;
(*Evaluate import statement. *)
VAR   P, F, FP, XP, Z, N, V, U, UP, D, S, ES: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*get specification. *) ADV(X,N,S); ADV(N,N,P); Z:=SIL;
      P:=FIRST(P); P:=EVLIS(P,ENV);
      IF S <> SIL THEN S:=FIRST(S) END;
      IF NOT SYMBOL(N) THEN UWRITE(N);
         ERROR(severe,"EVIMPRT: invalid as name."); 
         RETURN(SIL) END; 
      D:=EVALUATE(N,ENV);
      IF SYMBOL(D) THEN D:=EVALUATE(D,EP) END; (*search in global env *)
      IF D = SIL THEN UWRITE(N); UWRITE(D);
         ERROR(severe,"EVIMPRT: unknown unit."); 
         RETURN(SIL) END;  
      IF FIRST(D) <> UNIT THEN UWRITE(N); UWRITE(D);
         ERROR(severe,"EVIMPRT: unknown unit."); 
         RETURN(SIL) END;  
      D:=RED2(D); FIRST2(D,F,D); (*unit name parm spec ... *)
      ES:=ENV;
      IF EXTENDENV(F,P,ES) THEN (* ok *) END; (*parms for spec, global *)
(*2*) (*substitute renamings *) S:=CCONC(SP,S);
      IF S <> SIL THEN D:=SUBLIS(S,D) END;
      IF trace THEN SWRITE("SPEC: "); UWRITE(D) END;
      XP:=RED2(D); ADV(XP,FP,XP); (*spec name parm body *) 
      (* assert F = FP *) 
(*3*) (*evaluate specification *) 
      WHILE XP <> SIL DO ADV(XP,U,XP); 
            IF NOT ATOM(U) THEN ADV(U,UP,V); 
                  IF UP = IMPRT THEN V:=EVIMPRT(V,S,EP,ES); 
                                     Z:=CONC(CINV(V),Z); 
               ELSIF UP = SORT  THEN V:=EVSORT(V,ES); 
               ELSIF UP = SIG   THEN V:=EVSIG(V,ES); Z:=COMP(V,Z);
                ELSE UWRITE(UP);
                     ERROR(severe,"EVIMPRT: unknown function."); 
                     END; 
               ELSE UWRITE(U);
                    ERROR(severe,"EVIMPRT: atom invalid as function."); 
                    END;
            END;
      Z:=INV(Z); 
      RETURN(Z);
(*6*) END EVIMPRT;


PROCEDURE EVUNIT(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate and expose unit. *)
VAR   ZP, F, P, YP, EP, DS, D, XP, Z, Y, XPP, U, 
      UP, V, g, DP, n, d, dp, l: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*initialize*)  
      ADV(X, ZP, XP); ADV(ZP,Z,XP); P:=FIRST(XP); (* (name actual-parms) *) 
      P:=EVLIS(P,ENV);
      IF NOT SYMBOL(Z) THEN UWRITE(Z);
         ERROR(severe,"EVUNIT: invalid as unit name."); 
         RETURN(Z); END;
      YP:=ASSOC(Z,ENV);
      IF YP = SIL THEN UWRITE(Z);
         ERROR(severe,"EVUNIT: no unit defined."); 
         RETURN(Z); END;
      YP:=FIRST(YP); (*unit name formal-parms body *)
      IF FIRST(YP) <> UNIT THEN UWRITE(Z);
         ERROR(severe,"EVUNIT: no unit defined."); 
         RETURN(Z); END;
      XP:=RED2(YP); ADV(XP,F,XP); (*formal-parms *)  
(*3*) (*specification *) ADV(XP,U,XP);
      IF ATOM(U) THEN UWRITE(U);
         ERROR(severe,"EVUNIT: atom invalid as specification."); 
         RETURN(SIL) END;
      ADV(U,UP,V); 
      IF UP <> SPEC THEN UWRITE(UP);
         ERROR(severe,"EVUNIT: no specification defined."); 
         RETURN(SIL) END; 
      EP:=SIL; (*new scope block *)
      IF EXTENDENV(F,P,EP) THEN (* ok *) END; (*parms for spec *)
      D:=LIST2(ZP,SIL); 
      DP:=EVIMPRT(D,SIL,ENV,EP); (*own specification *)
      DS:=DP; COPYTOENV(DS,ENV,EP);
(*4*) (*prepare for global visiblity, loop on procedure names *) 
      g:=LIST3(SIL,SIL,SIL);
      WHILE DP <> SIL DO ADV(DP,n,DP); 
            d:=ASSOC(n,EP);
            IF d = SIL THEN l:=GET(n,EXTYP);
               IF (l = SIL) OR (l = GENERIC) THEN 
                  d:=COMP2(GLAMBDA,n,g); dp:=d; PUT(n,EXTYP,GENERIC);
                  END;
               ELSE dp:=FIRST(d) END; (* () <> SIL *)
            IF d <> SIL THEN SETV(n,dp,EP) END; (*to local env *)
            END; 
(*5*) (*loop on body *) 
      WHILE XP <> SIL DO ADV(XP,U,XP); 
            IF NOT ATOM(U) THEN ADV(U,UP,V); 
                  IF UP = MODEL THEN V:=EVMOD(V,ENV,EP) 
               ELSIF UP = IMPL  THEN V:=EVIMPL(V,ENV,EP)
               ELSIF UP = AXIOM THEN V:=EVAXIOM(V,ENV,EP)
                ELSE UWRITE(UP);
                     ERROR(severe,"EVUNIT: unknown function."); 
                     END; 
               ELSE UWRITE(U);
                    ERROR(severe,"EVUNIT: atom invalid as function."); 
                    END;
            END;
(*6*) (*copy to global env. *) 
      COPYTOENV(DS,EP,ENV);
      RETURN(Z);
(*7*) END EVUNIT;


PROCEDURE EVMOD(X, EP: LIST; VAR ENV: LIST): LIST;
(*Evaluate model statement. *)
VAR   D, XP, Z, Y, XPP, U, UP, V, g, DP, n, d, l: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*initialize*)  
      ADV(X, Z, XP); (*name parm body *) 
      IF NOT SYMBOL(Z) THEN UWRITE(Z);
         ERROR(severe,"EVMOD: invalid as model name."); 
         RETURN(Z); END;
      XP:=RED(XP); 
(*3*) (*loop on body *)
      WHILE XP <> SIL DO ADV(XP,U,XP); 
            IF NOT ATOM(U) THEN ADV(U,UP,V); 
                  IF UP = IMPRT THEN V:=EVIMPRT(V,SIL,EP,ENV); 
                                COPYTOENV(V,EP,ENV);
               ELSIF UP = SORT  THEN V:=EVSORT(V,ENV); 
               ELSIF UP = MAP   THEN V:=DEFMAP(V,ENV)
                ELSE UWRITE(UP);
                     ERROR(severe,"EVMOD: unknown function."); 
                     END; 
               ELSE UWRITE(U);
                    ERROR(severe,"EVMOD: atom invalid as function."); 
                    END;
            END;
      RETURN(Z);
(*6*) END EVMOD;


PROCEDURE EVAXIOM(X, EP: LIST; VAR ENV: LIST): LIST;
(*Evaluate axiom statement. *)
VAR   g, n, d, l, DP, D, XP, Z, Y, XPP, U, UP, V: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*initialize*)  
      ADV(X, Z, XP); (*name parms body *)
      IF NOT SYMBOL(Z) THEN UWRITE(Z);
         ERROR(severe,"EVMOD: invalid as axioms name."); 
         RETURN(Z); END;
      XP:=RED(XP);
(*3*) (*loop on body *)
      WHILE XP <> SIL DO ADV(XP,U,XP); 
            IF NOT ATOM(U) THEN ADV(U,UP,V); 
                  IF UP = IMPRT THEN V:=EVIMPRT(V,SIL,EP,ENV); 
                                COPYTOENV(V,EP,ENV);
               ELSIF UP = SORT  THEN V:=EVSORT(V,ENV); 
               ELSIF UP = RULE  THEN V:=DEFRULE(V,ENV)
                ELSE UWRITE(UP);
                     ERROR(severe,"EVAXIOM: unknown function."); 
                     END; 
               ELSE UWRITE(U);
                    ERROR(severe,"EVAXIOM: atom invalid as function."); 
                    END;
            END;
      RETURN(Z);
(*6*) END EVAXIOM;


PROCEDURE EVIMPL(X, EP: LIST; VAR ENV: LIST): LIST;
(*Evaluate implementation statement. *)
VAR   D, XP, Z, Y, XPP, U, UP, V, g, DP, n, d, l: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*initialize*)  
      ADV(X, Z, XP); (*name parm body. *)
      IF NOT SYMBOL(Z) THEN UWRITE(Z);
         ERROR(severe,"EVMOD: invalid as implementation name."); 
         RETURN(Z); END;
      XP:=RED(XP);
(*3*) (*loop on body *)
      WHILE XP <> SIL DO ADV(XP,U,XP); 
            IF NOT ATOM(U) THEN ADV(U,UP,V); 
                  IF UP = IMPRT THEN V:=EVIMPRT(V,SIL,EP,ENV); 
                                COPYTOENV(V,EP,ENV);
               ELSIF UP = SORT  THEN V:=EVSORT(V,ENV); 
               ELSIF UP = VARS  THEN V:=EVVAR(V,ENV)
               ELSIF UP = DE    THEN V:=DEFPROC(V,ENV)
                ELSE V:=EVALUATE(U,ENV) END; 
               ELSE UWRITE(U);
                    ERROR(severe,"EVIMPL: atom invalid as function."); 
                    END;
            END;
      RETURN(Z);
(*6*) END EVIMPL;


PROCEDURE EVGEN(L, X: LIST; VAR ENV: LIST): LIST;
(*Evaluate generic function. L=(N, M,I,E), where N is the name of the 
generic function, M is a association list of signatures and function 
names. I is a closure, E is a set of rewrite rules. 
X is a list of actual parameters. *)
VAR   V, T, A, Y, Z, W, C, XS, XP, EP, D, N, M, I, E, LH, RH, S: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; FIRST4(L,N,M,I,E);   
(*2*) (*generic function defined ?. *)
      IF M <> SIL THEN 
            IF trace THEN SWRITE("parms: "); UWRITE(X); END;
         A:=TYPEOF(X); FIRST3(A,V,T,D); 
            IF trace THEN SWRITE("typeof: "); UWRITE(A); END;
         W:=ASSOCQ(T,M);
            IF trace THEN SWRITE("assoc: "); UWRITE(W); END;
         IF W <> SIL THEN W:=FIRST(W); (* (mod func, cond) *) 
            IF trace THEN SWRITE("MAP: "); UWRITE(W); END;
            ADV(W,W,C); Z:=WT;
            IF C <> SIL THEN C:=FIRST(C); 
               ADV(C,Y,XP); XP:=FIRST(XP); 
               XS:=GENPL(XP,V,T,D); (*combine descriptors and values*)
               Z:=COMP(Y,XS); (*real condition. *)
               Z:=EVALUATE(Z,ENV);
               END;
            IF Z <> SIL THEN 
               ADV(W,Y,XP); XP:=FIRST(XP); 
               XS:=GENPL(XP,V,T,D); (*combine descriptors and values*)
               Z:=COMP(Y,XS); (*real expression. *)  
               IF D <> SIL THEN D:=FIRST(D) END;
               Z:=GENTE(Z,Y,D); (*build new typed expression. *)
               Z:=LIST2(Z,ECENV(ENV)); RETURN(Z);
               END;
            END;
         END;
(*3*) (*closure defined ? *)
      IF I <> SIL THEN FIRST2(I,XP,EP);  
         Z:=COMP(XP,X); 
         Z:=LIST2(Z,EP); RETURN(Z);
         END;
(*4*) (*rewrite rule defined ? *)
      IF E <> SIL THEN Z:=COMP(N,X); 
         WHILE E <> SIL DO ADV(E,XP,E);
               ADV2(XP,LH,RH,XP); S:=SIL;
               IF UNIFY(Z,LH,S) THEN T:=WT;
                  IF trace THEN SWRITE("UNIFY: "); UWRITE(RH); END;
                  IF XP <> SIL THEN XP:=FIRST(XP); 
                     XP:=SUBLIS(S,XP); 
                     T:=EVALUATE(XP,ENV); END;
                  IF T <> SIL THEN 
                     Z:=SUBLIS(S,RH); 
                     Z:=LIST2(Z,ECENV(ENV)); RETURN(Z);
                     END;
                  END;
               END;             
         END;
(*8*) (* unbound generic procedure, return term *) 
      Z:=COMP(N,X); Z:=LIST2(QUOTE,Z); 
      Z:=LIST2(Z,ECENV(ENV)); RETURN(Z);
(*9*) END EVGEN;


PROCEDURE EVSIG(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate signature declaration. *)
VAR   XP, Y, S, T, YP: LIST;
BEGIN
(*1*) (*initialize. *) ADV2(X,Y,S,XP); T:=FIRST(XP);  
      (*evaluate Y once ! *)
      YP:=ASSOC(Y,ENV); IF YP <> SIL THEN YP:=FIRST(YP) END;
      IF SYMBOL(YP) THEN Y:=YP END;
      IF NOT SYMBOL(Y) THEN UWRITE(Y); 
         ERROR(severe,"EVSIG: invalid as function name."); 
         RETURN(SIL) END; 
(*2*) (*evaluate source and target. *)
      IF SYMBOL(S) THEN S:=LIST1(S) END; 
      S:=EVLIS(S,ENV); 
      IF SYMBOL(T) THEN T:=LIST1(T) END; 
      T:=EVLIS(T,ENV); 
      XP:=LIST3(S,Y,T);
(*3*) (*define arrow. *)
      PUT(Y,ARROW,XP); 
      RETURN(Y);
(*4*) END EVSIG;


PROCEDURE EXTENDVARENV(A, O, X: LIST; VAR ENV: LIST): BOOLEAN;
(*Extend var environement. A and O are lists of symbols. 
X is a list of values. The environment ENV is extented by the bindings
of the symbols in A and O to the values in X.
The values bound to elements of A are evaluated, 
the values bound to elements of O are not evaluated, 
If the binding is possible, then TRUE is returned else FALSE. *)
VAR   XP, AP, OP, Y, Z, B: LIST;
BEGIN
(*1*) (*initialize*) Z:=ENV; XP:=X; AP:=A; OP:=O;
(*2*) (*loop on input lists. *)
      WHILE (AP <> SIL) AND (XP <> SIL) DO 
            ADV(AP,B,AP); ADV(XP,Y,XP); Y:=EVALUATE(Y,ENV);
            Z:=COMP2(B,Y,Z) END;
(*3*) (*loop on output lists. *)
      WHILE (OP <> SIL) AND (XP <> SIL) DO 
            ADV(OP,B,OP); ADV(XP,Y,XP); 
            Z:=COMP2(B,Y,Z) END;
(*4*) (*argument number mismatch. *)
      IF (AP <> SIL) OR (OP <> SIL) OR (XP <> SIL) THEN 
         UWRITE(AP); UWRITE(OP); UWRITE(XP); 
         ERROR(severe,"EXTENDVARENV: argument number mismatch.");
         RETURN(FALSE) END;  
      ENV:=Z; RETURN(TRUE);
(*5*) END EXTENDVARENV;


(*Special part for ALDES. *)

PROCEDURE EVPROGA(X: LIST; VAR ENV: LIST): LIST;
(*Evaluate aldes statement sequence. X is the reductum of a 
PROGA S-expression. *)
VAR   XP, Z, L: LIST;
BEGIN
(*1*) (*initialize*) Z:=SIL; XP:=X;
(*2*) (*loop on list. *)
      LOOP goto:=SIL;
           Z:=EVPROGN(XP,ENV);
           IF goto = SIL THEN RETURN(Z) END;
           unwind:=FALSE;
           XP:=X;
           LOOP 
                IF XP = SIL THEN EXIT END;
                ADV(XP,L,XP);
                IF NOT ATOM(L) THEN
                   IF FIRST(L) = LBEL THEN 
                      IF SECOND(L) = goto THEN EXIT END;
                      END;
                   END;
                END;
           IF XP = SIL THEN 
              SWRITE("Goto "); UWRITE(goto); BLINES(0);
              ERROR(severe,"Undefined step number.");
              EXIT END; 
           END;
      RETURN(Z);
(*4*) END EVPROGA;


PROCEDURE DEFA(X: LIST; VAR ENV: LIST): LIST;
(*Define array. *)
VAR   x, s, a, n, i, Y: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
      a:=LIST1(ANY);
(*1*) (*generate names and define names. *) 
      WHILE X <> SIL DO ADV(X,x,X); FIRST2(x,n,i); 
            i:=EVLIS(i,ENV); x:=LIST2(n,i);
            s:=ARRAYDEC(x); s:=COMP(s,a);
            Y:=EVVAR(s,ENV);      
            END;
      RETURN(Y);
(*4*) END DEFA;


PROCEDURE SETaldesV(V, A: LIST; VAR ENV: LIST);
(*Set ALDES variable. *)
VAR   EP, Z, t, n: LIST;
BEGIN
(*1*) (*See if defined*) 
      IF NOT SYMBOL(V) THEN 
         IF NOT ATOM(V) THEN 
            IF FIRST(V) = ARY THEN FIRST2(SECOND(V),n,t); 
               t:=EVLIS(t,ENV); t:=LIST2(n,t); 
               V:=GENARRAY(t) END; 
            END;
         IF NOT SYMBOL(V) THEN 
            UWRIT1(V); SWRITE(":="); UWRITE(A); 
            ERROR(severe,"SETV: invalid as variable."); 
            RETURN (*setv makes no sense in this case*) END 
         END; 
(*2*) SETV(V,A,ENV);
(*3*) END SETaldesV;


END MASSPEC.


(* -EOF- *)
