(* ----------------------------------------------------------------------------
 * $Id: MASLISP.mi,v 1.4 1995/11/05 08:55:36 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLISP.mi,v $
 * Revision 1.4  1995/11/05 08:55:36  kredel
 * Support for small exit and corrections in terms of sorts.
 *
 * Revision 1.3  1992/10/15  16:27:47  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:22  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:17  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLISP;

(* MAS Lisp Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT BETA, SIL, LIST, LENGTH, LISTVAR,
                    LIST1, ADV, FIRST, RED, COMP, INV, SFIRST, SRED;

FROM MASERR IMPORT ERROR, severe, harmless, spotless;

FROM MASBIOS IMPORT GWRITE, LISTS, BLINES, SWRITE, CWRITE;

FROM MASBIOSU IMPORT CLTIS;

FROM SACLIST IMPORT EQUAL, RED2, CINV, CONC, CCONC,
                    FIRST3, LIST3, LIST4, FIRST4, SECOND, THIRD, RED3,
                    FIRST2, ADV2, LIST2, COMP2, COMP3;

FROM MASSYM2 IMPORT SYMBOL, ASSOC, ASSOCQ, GET, PUT, SUBLIS; 

FROM MASSYM IMPORT ATOM, ELEMP, UREAD, UWRITE, UWRIT1, 
                   NOSHOW, UNIFY, GENARRAY, ARRAYDEC;

FROM MASLISPU IMPORT EXTYP, ARITY, SUBR, EXPR, PROCP,
                     Declare, CallCompiled, Signature,
                     Compiledp0, Compiledf2;

VAR  unwind: BOOLEAN;
     goto: LIST;

VAR  PVAL, PDESC, PTYP: LIST; (*patterns *)
CONST rcsidi = "$Id: MASLISP.mi,v 1.4 1995/11/05 08:55:36 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE InitNames;
(*Initialize reserved names. *)
BEGIN
(*1*) (*indicators. *)
      Declare(ARROW,"ARROW");
(*2*) (*variables. *)
      Declare(ATM,"ATOM");        
      Declare(ANY,"ANY");         
      Declare(NULL,"NIL"); 
      Declare(WT,"T"); 
      Declare(PVAL,"VAL"); 
      Declare(PDESC,"DESC"); 
      Declare(PTYP,"TYPE"); 
      Declare(TDEF,"TYPEDEF"); 
      Declare(DEFAULT,"DEFAULT"); 
      Declare(LAMBDA,"LAMBDA");
      Declare(FLAMBDA,"FLAMBDA");
      Declare(MLAMBDA,"MLAMBDA");
      Declare(GLAMBDA,"GLAMBDA");
      Declare(RTN,"RETURN");
      Declare(FERx,"ForEachX");
      Declare(FELx,"ForEachY");
(*4*) (*internal fexpr functions. *)
      Declare(SCHLUSS,"EXIT");    PUT(SCHLUSS,EXTYP,FEXPR);
      Declare(schluss,"exit");    PUT(schluss,EXTYP,FEXPR);
      Declare(QUOTE,"QUOTE");     PUT(QUOTE,EXTYP,FEXPR);
      Declare(SETQ,"SETQ");       PUT(SETQ,EXTYP,FEXPR);
      Declare(SETAV,"SETAV");     PUT(SETAV,EXTYP,FEXPR);
      Declare(ASSIGN,"ASSIGN");   PUT(ASSIGN,EXTYP,FEXPR);
      Declare(COND,"COND");       PUT(COND,EXTYP,FEXPR);
      Declare(PROGN,"PROGN");     PUT(PROGN,EXTYP,FEXPR);
      Declare(PROGA,"PROGA");     PUT(PROGA,EXTYP,FEXPR);
      Declare(LBEL,"LABEL");      PUT(LBEL,EXTYP,FEXPR);
      Declare(LISTX,"LIST");      PUT(LISTX,EXTYP,FEXPR);
      Declare(DE,"DE");           PUT(DE,EXTYP,FEXPR);
      Declare(DF,"DF");           PUT(DF,EXTYP,FEXPR);
      Declare(DM,"DM");           PUT(DM,EXTYP,FEXPR);
      Declare(DG,"DG");           PUT(DG,EXTYP,FEXPR);
      Declare(IFS,"IF");          PUT(IFS,EXTYP,FEXPR);
      Declare(WHL,"WHILE");       PUT(WHL,EXTYP,FEXPR);
      Declare(RPT,"REPEAT");      PUT(RPT,EXTYP,FEXPR);
      Declare(STRNG,"STRING");    PUT(STRNG,EXTYP,FEXPR);
      Declare(VARS,"VAR");        PUT(VARS,EXTYP,FEXPR);
      Declare(TINFO,"TYPEINFO");  PUT(TINFO,EXTYP,FEXPR);
      Declare(ARY,"ARRAY");       PUT(ARY,EXTYP,FEXPR);
      Declare(SPEC,"SPEC");       PUT(SPEC,EXTYP,FEXPR);
      Declare(SORT,"SORT");       PUT(SORT,EXTYP,FEXPR);
      Declare(SIG,"SIG");         PUT(SIG,EXTYP,FEXPR);
      Declare(IMPRT,"IMPORT");    PUT(IMPRT,EXTYP,FEXPR);
      Declare(EXPOS,"EXPOSE");    PUT(EXPOS,EXTYP,FEXPR);
      Declare(UNIT,"UNIT");       PUT(UNIT,EXTYP,FEXPR);
      Declare(IMPL,"IMPLEMENTATION"); PUT(IMPL,EXTYP,FEXPR);
      Declare(MODEL,"MODEL");     PUT(MODEL,EXTYP,FEXPR);
      Declare(MAP,"MAP");         PUT(MAP,EXTYP,FEXPR);
      Declare(AXIOM,"AXIOMS");    PUT(AXIOM,EXTYP,FEXPR);
      Declare(RULE,"RULE");       PUT(RULE,EXTYP,FEXPR);
      Declare(WHEN,"WHEN");       PUT(WHEN,EXTYP,FEXPR);
      Declare(REP,"REP");         PUT(REP,EXTYP,FEXPR);
(*5*) (*internal expr functions. *)
      Declare(EQS,"EQ");          PUT(EQS,EXTYP,EXPR);
      Declare(NEQS,"NE");         PUT(NEQS,EXTYP,EXPR);
      Declare(GTS,"GT");          PUT(GTS,EXTYP,EXPR);
      Declare(LTS,"LT");          PUT(LTS,EXTYP,EXPR);
      Declare(LEQ,"LEQ");         PUT(LEQ,EXTYP,EXPR);
      Declare(GEQ,"GEQ");         PUT(GEQ,EXTYP,EXPR);
      Declare(UND,"AND");         PUT(UND,EXTYP,EXPR);
      Declare(ODER,"OR");         PUT(ODER,EXTYP,EXPR);
      Declare(NOTS,"NOT");        PUT(NOTS,EXTYP,EXPR);
      Declare(ADD,"ADD");         PUT(ADD,EXTYP,EXPR);
      Declare(SUB,"SUB");         PUT(SUB,EXTYP,EXPR);
      Declare(MUL,"MUL");         PUT(MUL,EXTYP,EXPR);
      Declare(QUOT,"QUOT");       PUT(QUOT,EXTYP,EXPR);
      Declare(REM,"REM");         PUT(REM,EXTYP,EXPR);
      Declare(RTN,"RETURN");      PUT(RTN,EXTYP,EXPR);
      Declare(GTO,"GOTO");        PUT(GTO,EXTYP,EXPR);
      Declare(FER,"ForEachinRep"); PUT(FER,EXTYP,EXPR);
      Declare(FEL,"ForEachinList"); PUT(FEL,EXTYP,EXPR);
      Declare(CONVVAL,"CONVVAL"); PUT(CONVVAL,EXTYP,EXPR);
      Declare(CONVDES,"CONVDES"); PUT(CONVDES,EXTYP,EXPR);
(*5*) (*internal gexpr functions. *)
      Declare(READ,"READ");         
      Declare(WRITE,"WRITE");       
      Declare(DECREAD,"DECREAD");   
      Declare(DECWRITE,"DECWRITE"); 
(*9*) END InitNames;


PROCEDURE InitLISP;
(*Initialize compiled procedures. *)
BEGIN
(*1*) InitNames;
(*2*) InitENV; 
(*3*) (*internal compiled procedures *)
      Compiledp0(InitENV,"NEW");
(*4*) (*external Compiled procedures *)
      Declare(POW,"POW");
(*9*) END InitLISP;


PROCEDURE InitENV;
(*Initialize environement. *)
BEGIN
(*1*) (*alist *) ENV:=SIL; LISTVAR(ENV); 
(*2*) (*special values *)
      ENV:=COMP2(NULL,SIL,ENV); 
(*3*) (*global variables *)
      unwind:=FALSE; 
      stricttyping:=FALSE;
      trace:=FALSE;
(*9*) END InitENV;


PROCEDURE ECENV(ENV: LIST): LIST;
(*Encode environment. The encoded environment E is returned. *)
BEGIN
(*0*) RETURN(LIST2(NOSHOW,ENV)) 
(*4*) END ECENV;


PROCEDURE DCENV(E: LIST): LIST;
(*Decode environment. The encoded environment E is decoded. *)
BEGIN
(*0*) RETURN(SECOND(E)) 
(*4*) END DCENV;


PROCEDURE SETV(V, A: LIST; VAR ENV: LIST);
(*Set variable. V is a symbol and A is an S-expression. 
A is associated to V in the environment ENV. *)
VAR   EP, Z, t, n: LIST;
BEGIN
(*1*) (*See if defined*) 
      IF NOT SYMBOL(V) THEN 
         UWRIT1(V); SWRITE(":="); UWRITE(A); 
         ERROR(severe,"SETV: invalid as variable."); 
         RETURN (*setv makes no sense in this case*) END;
      EP:=ASSOC(V,ENV);
(*2*) (*dont check for bound variable here*) 
      IF EP <> SIL THEN SFIRST(EP,A)
                   ELSE ENV:=COMP2(V,A,ENV) END; 
(*3*) END SETV;


PROCEDURE EXTENDENV(A, X: LIST; VAR ENV: LIST): BOOLEAN;
(*Extend environement. A is a list of symbols. X is a list 
of values. The environment ENV is extented by the bindings
of the symbols in A to the values in X. If the binding
is possible, then TRUE is returned else FALSE. *)
VAR XP, AP, Y, Z, B: LIST;
BEGIN
(*1*) (*initialize*) Z:=ENV; XP:=X; AP:=A;
(*2*) (*loop on lists. *)
      WHILE (AP <> SIL) AND (XP <> SIL) DO 
            ADV(AP,B,AP); ADV(XP,Y,XP); 
            Z:=COMP2(B,Y,Z) END;
(*3*) (*argument number mismatch. *)
      IF (AP <> SIL) OR (XP <> SIL) THEN UWRITE(AP); UWRITE(XP); 
         ERROR(severe,"EXTENDENV: argument number mismatch.");
         RETURN(FALSE) END;  
      ENV:=Z; RETURN(TRUE);
(*4*) END EXTENDENV;


PROCEDURE COPYTOENV(V, EP: LIST; VAR ENV: LIST);
(*Copy to environement. V is a list of symbols. EP is an
environment. The environment ENV is extented by the bindings
of the symbols in V to the values in EP. *)
VAR   D, v: LIST;
BEGIN
(*0*) IF trace THEN SWRITE("IMP/EXP:   "); UWRITE(V); 
                    SWRITE("COPYTOENV: ");END;
(*1*) WHILE V <> SIL DO ADV(V,v,V); 
            D:=ASSOC(v,EP);
            IF D <> SIL THEN D:=FIRST(D); 
               IF trace THEN UWRIT1(v); SWRITE(" "); END;
               SETV(v,D,ENV) END; (*copy *)
            END;
      IF trace THEN BLINES(0) END;
(*4*) END COPYTOENV;


PROCEDURE SPECIALFORM(S: LIST): BOOLEAN;
(*Test if expression S is a special form. *)
VAR t: BOOLEAN;
    F, Y: LIST;
BEGIN
(*1*) (*initialize*) t:=FALSE;
      IF ELEMP(S) THEN RETURN(t) END;
(*2*) (*test property of symbol. *)  
      IF SYMBOL(S) THEN Y:=GET(S,EXTYP);
         IF (Y = FEXPR) OR (Y = MACRO) THEN t:=TRUE END;
         RETURN(t) END;
(*3*) (*test property of function. *) F:=FIRST(S);   
      IF F = FLAMBDA THEN RETURN(TRUE) END;
      IF F = MLAMBDA THEN RETURN(TRUE) END;
      RETURN(t); 
(*4*) END SPECIALFORM;


PROCEDURE LAMBDAP(S: LIST): BOOLEAN;
(*Test if expression S is a lambda form. *)
VAR t: BOOLEAN;
BEGIN
(*1*) (*initialize*) t:=FALSE;
      IF ELEMP(S) THEN RETURN(FALSE) END;
(*2*) (*test property of symbol. *)  
      IF NOT SYMBOL(S) THEN RETURN(FALSE) END;
(*3*) (*test if name = .lambda. *) t:=TRUE;  
      IF S = LAMBDA THEN RETURN(t) END; 
      IF S = FLAMBDA THEN RETURN(t) END; 
      IF S = MLAMBDA THEN RETURN(t) END; 
      IF S = GLAMBDA THEN RETURN(t) END; 
      RETURN(FALSE);
(*4*) END LAMBDAP;


PROCEDURE SEXPRP(X: LIST): BOOLEAN;
(*Test if X is a S-expression function. *)
VAR   T, Y: LIST;
BEGIN
(*1*) (*elemp. *) IF ELEMP(X) THEN RETURN(FALSE) END; 
(*1*) (*symbol. *) Y:=FIRST(X); 
      IF SYMBOL(Y) THEN T:=GET(Y,EXTYP);
         IF T <> SIL THEN RETURN(TRUE) END;
         RETURN(FALSE) END; 
(*2*) (*lambda expression. *) 
      IF LAMBDAP(FIRST(Y)) THEN RETURN(TRUE) END;
      RETURN(FALSE);
(*4*) END SEXPRP;


PROCEDURE DEFE(X: LIST; VAR ENV: LIST): LIST;
(*Define expr function. X is a DE expression. A LAMBDA expression 
generated from X is associated to name(X) in the environment ENV. *)
VAR   XP, Y, Z: LIST;
BEGIN
(*0*) (*syntax check. *) Z:=X;
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*define name. *) ADV(X,Y,XP); 
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFE: invalid as function name."); 
         RETURN(SIL) END; 
      PUT(Y,EXTYP,EXPR); 
(*3*) (*generate lambda expression. *)
      Z:=COMP(LAMBDA,XP); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFE;


PROCEDURE DEFF(X: LIST; VAR ENV: LIST): LIST;
(*Define fexpr function. X is a DF expression. A FLAMBDA expression 
generated from X is associated to name(X) in the environment ENV.*)
VAR   XP, Y, Z: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*define name. *) ADV(X,Y,XP); 
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFF: invalid as function name."); 
         RETURN(SIL) END; 
      PUT(Y,EXTYP,EXPR); 
(*2*) (*generate flambda expression. *)
      Z:=COMP(FLAMBDA,XP); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFF;


PROCEDURE DEFM(X: LIST; VAR ENV: LIST): LIST;
(*Define macro function. X is a DM expression. A MLAMBDA expression 
generated from X is associated to name(X) in the environment ENV.*)
VAR   XP, Y, Z: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*define name. *) ADV(X,Y,XP); 
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFM: invalid as function name."); 
         RETURN(SIL) END; 
      PUT(Y,EXTYP,MACRO); 
(*2*) (*generate mlambda expression. *)
      Z:=COMP(MLAMBDA,XP); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFM;


PROCEDURE DEFMAP(X: LIST; VAR ENV: LIST): LIST;
(*Define generic map function. X is a MAP expression. A 
GLAMBDA expression generated from X is associated to name(X) 
in the environment ENV. *)
VAR   MP, XP, Y, Z, L, R, M, I, IP, E, N: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*get name. *) ADV(X,L,XP); (* (name, (sig)), mod func, cond. *)
      ADV(L,Y,L); L:=FIRST(L); 
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFMAP: invalid as function name."); 
         RETURN(SIL) END; 
      IP:=SIL; 
      Z:=ASSOC(Y,ENV); (*get generic function list*)
      IF Z <> SIL THEN Z:=FIRST(Z);
         IF Z <> SIL THEN  
            IF FIRST(Z) = GLAMBDA THEN Z:=RED(Z) 
         ELSIF LAMBDAP(FIRST(Z)) THEN IP:=LIST2(Z,ECENV(ENV)); Z:=SIL;  
          ELSE Z:=SIL; UWRITE(Y);
               ERROR(severe,"DEFMAP: variable defined generic."); 
               END;
            END;
         END;
      (*decompose *)
      IF Z = SIL THEN N:=Y; M:=SIL; I:=IP; E:=SIL; PUT(Y,EXTYP,GENERIC); 
                 ELSE FIRST4(Z,N,M,I,E) END;
(*2*) (*generate map match list. *) 
      MP:=ASSOCQ(L,M); (* avoid multiple entries *) 
      IF MP <> SIL THEN SFIRST(MP,XP)
                   ELSE XP:=LIST2(L,XP); (*sig, mod func *)
                        M:=CCONC(M,XP) END; 
(*3*) (*generate glambda expression. *) Z:=LIST4(N,M,I,E);
      Z:=COMP(GLAMBDA,Z); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFMAP;


PROCEDURE DEFPROC(X: LIST; VAR ENV: LIST): LIST;
(*Define generic proc function. X is a DE expression. 
A GLAMBDA expression generated from X is associated to 
name(X) in the environment ENV.*)
VAR   XP, Y, Z, M, I, IP, E, N: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*get name. *) ADV(X,Y,XP); (*name, parm, body. *)
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFPROC: invalid as function name."); 
         RETURN(SIL) END; 
      IP:=SIL;
      Z:=ASSOC(Y,ENV); (*get generic function list*)
      IF Z <> SIL THEN Z:=FIRST(Z);
         IF Z <> SIL THEN  
            IF FIRST(Z) = GLAMBDA THEN Z:=RED(Z) 
         ELSIF LAMBDAP(FIRST(Z)) THEN IP:=LIST2(Z,ECENV(ENV)); Z:=SIL;  
          ELSE Z:=SIL; UWRITE(Y);
               ERROR(severe,"DEFPROC: variable defined generic."); 
               END;
            END;
         END;
      (*decompose *)
      IF Z = SIL THEN N:=Y; M:=SIL; I:=IP; E:=SIL; PUT(Y,EXTYP,GENERIC); 
                 ELSE FIRST4(Z,N,M,I,E) END;
(*2*) (*generate proc closure. *) 
      XP:=COMP(LAMBDA,XP);
      I:=LIST2(XP,ECENV(ENV)); (*closure: lambda, env *)
(*3*) (*generate glambda expression. *) Z:=LIST4(N,M,I,E);
      Z:=COMP(GLAMBDA,Z); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFPROC;


PROCEDURE DEFRULE(X: LIST; VAR ENV: LIST): LIST;
(*Define generic rule function. X is a RULE expression. 
A GLAMBDA expression generated from X is associated to 
name(X) in the environment ENV.*)
VAR   XP, Y, Z, M, I, IP, E, N, L, R: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*get name. *) ADV(X,L,XP); (*lhs, rhs *)
      Y:=FIRST(L);
      IF ATOM(Y) THEN UWRITE(Y);
         ERROR(severe,"DEFRULE: atom invalid as function name."); 
         RETURN(SIL) END; 
      IP:=SIL;
      Z:=ASSOC(Y,ENV); (*get generic function list*)
      IF Z <> SIL THEN Z:=FIRST(Z);
         IF Z <> SIL THEN  
            IF FIRST(Z) = GLAMBDA THEN Z:=RED(Z) 
         ELSIF LAMBDAP(FIRST(Z)) THEN IP:=LIST2(Z,ECENV(ENV)); Z:=SIL;  
          ELSE Z:=SIL; UWRITE(Y);
               ERROR(severe,"DEFRULE: variable defined generic."); 
               END;
            END;
         END;
      (*decompose *)
      IF Z = SIL THEN N:=Y; M:=SIL; I:=IP; E:=SIL; PUT(Y,EXTYP,GENERIC); 
                 ELSE FIRST4(Z,N,M,I,E) END;
(*2*) (*generate match list. *) 
      E:=CCONC(E,LIST1(X)); (*add lhs = rhs *)
(*3*) (*generate glambda expression. *) Z:=LIST4(N,M,I,E);
      Z:=COMP(GLAMBDA,Z); SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DEFRULE;


PROCEDURE DSPEC(X: LIST; VAR ENV: LIST): LIST;
(*Define specification. X is a SPEC expression. An UNIT expression 
generated from X is associated to name(X) in the environment ENV.*)
VAR   XP, Y, Z: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*define name. *) ADV(X,Y,XP);   
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DSPEC: invalid as unit name."); 
         RETURN(SIL) END; 
      PUT(Y,EXTYP,FEXPR); 
(*2*) (*generate spec expression and set/reset unit. *)
      Z:=COMP2(SPEC,Y,XP); 
      Z:=LIST4(UNIT,Y,FIRST(XP),Z); (*unit name parms spec other *)
      SETV(Y,Z,ENV); 
      RETURN(Y);
(*4*) END DSPEC;


PROCEDURE DMIA(X: LIST; VAR ENV: LIST): LIST;
(*Define model, implementation or axioms. X is a MODEL, 
IMPLEMENTATION or AXIOMS expression. An UNIT expression 
associated to name(X) is modified by a generated expression 
of X. *)
VAR   XPP, XP, Y, Z, W, T: LIST;
BEGIN
(*0*) (*syntax check. *) 
      IF X = SIL THEN RETURN(SIL) END;
(*1*) (*define name. *) ADV2(X,T,Y,XP);  
      IF NOT SYMBOL(Y) THEN UWRITE(Y);
         ERROR(severe,"DMIA: invalid as unit name."); 
         RETURN(SIL) END; 
      W:=ASSOC(Y,ENV);
      IF W = SIL THEN UWRITE(Y);
         ERROR(severe,"DMIA: no specification defined."); 
         RETURN(SIL) END; 
      W:=FIRST(W);
      IF FIRST(W) <> UNIT THEN UWRITE(Y);
         ERROR(severe,"DMIA: no unit defined."); 
         RETURN(SIL) END;
(*2*) (*generate m/i/a expression and add to unit. *)
      Z:=LIST1(X); Z:=CONC(W,Z);
      RETURN(Y);
(*4*) END DMIA;


PROCEDURE TYPEOF(X: LIST): LIST;
(*Type of S-expression. X is an S-expression. A list of types, 
values and descriptors of X is returend. *)
VAR   D, DS, XP, x, y, xs, d, XS, Y, YS, W, A: LIST;
BEGIN
(*1*) (*elementary. *) Y:=SIL; D:=SIL; 
      IF ATOM(X) THEN XS:=LIST1(X); Y:=ATM;
         RETURN(LIST3(XS,Y,D)) END; 
(*2*) (*symbol. *) 
      IF SYMBOL(X) THEN Y:=SIL; D:=SIL;         
         Y:=GET(X,SORT); 
         IF Y <> SIL THEN RETURN(LIST3(SIL,X,D)) END; 
         Y:=GET(X,TDEF); 
         IF (Y > SIL) AND NOT SYMBOL(Y) THEN FIRST2(Y,Y,D) END;  
         X:=LIST1(X); 
         IF Y <> SIL THEN Y:=LIST1(Y) END; 
         IF D <> SIL THEN D:=LIST1(D) END; 
         RETURN(LIST3(X,Y,D)) END; 
(*3*) (*with type info. *) 
      IF FIRST(X) = TINFO THEN XS:=VALOFTAG(X); 
         Y:=TYPOFTAG(X); D:=DECOFTAG(X);  
         XS:=LIST1(XS); 
         IF Y <> SIL THEN Y:=LIST1(Y) END; 
         IF D <> SIL THEN D:=LIST1(D) END; 
         RETURN(LIST3(XS,Y,D)) END; 
(*4*) (*term of sorts. *) (*problem*)
      IF GET(FIRST(X),SORT) <> SIL THEN FIRST2(X, X,D); 
         IF X <> SIL THEN X:=LIST1(X) END; 
         IF D <> SIL THEN D:=LIST1(D) END; 
         RETURN(LIST3(SIL,X,D)) END; 
(*5*) (*un-evaluated function term. *) 
      A:=GET(FIRST(X),ARROW);
      IF A <> SIL THEN  XS:=X; D:=SIL; 
         FIRST3(A,x,y,Y); IF Y <> SIL THEN Y:=FIRST(Y) END; 
         XS:=LIST1(XS); 
         IF Y <> SIL THEN Y:=LIST1(Y) END; 
         IF D <> SIL THEN D:=LIST1(D) END; 
         RETURN(LIST3(XS,Y,D)) END; 
(*6*) (*list. *) XP:=X; XS:=SIL; 
      WHILE XP <> SIL DO ADV(XP,x,XP); W:=TYPEOF(x);
            FIRST3(W,xs,y,d);
            XS:=CCONC(XS,xs); Y:=CCONC(Y,y); D:=CCONC(D,d) END;
      RETURN(LIST3(XS,Y,D)) 
(*9*) END TYPEOF;


PROCEDURE TAG(V,T: LIST): LIST;
(*Tag object. V is an S-expression, T is a type expression.
A tagged TYPEINFO S-expression is returned. *)
VAR   O: LIST;
BEGIN
(*1*) (*check type indicator *)
      IF ELEMP(T) THEN UWRITE(T); 
         ERROR(severe,"TAG: invalid as type indicator."); 
         RETURN(SIL) END; 
(*2*) (*construct list *)
      O:=LIST3(TINFO,V,T);
      RETURN(O); 
(*3*) END TAG;


PROCEDURE VALOFTAG(L: LIST): LIST;
(*Value of tagged object. L is a tagged S-expression. 
The value component of L is returned. *)
BEGIN
(*1*) (*check tag *)
      IF ATOM(L) THEN RETURN(L) END; 
      IF FIRST(L) <> TINFO THEN RETURN(L) END; 
      RETURN(SECOND(L)); 
(*3*) END VALOFTAG;


PROCEDURE TYPOFTAG(L: LIST): LIST;
(*Type of tagged object. L is a tagged S-expression. 
The type component of L is returned.*)
VAR   T: LIST;
BEGIN
(*1*) (*check tag *)
      IF ATOM(L) THEN RETURN(SIL) END; 
      IF FIRST(L) <> TINFO THEN RETURN(SIL) END; 
      T:=THIRD(L); (*tinfo val type*)
      T:=FIRST(T);
      RETURN(T); 
(*3*) END TYPOFTAG;


PROCEDURE DECOFTAG(L: LIST): LIST;
(*Descriptor of tagged object. L is a tagged S-expression. 
The descriptor component of L is returned. *)
VAR   D, T: LIST;
BEGIN
(*1*) (*check tag *) 
      IF ATOM(L) THEN RETURN(SIL) END; 
      IF FIRST(L) <> TINFO THEN RETURN(SIL) END; 
      T:=THIRD(L); (*tinfo val type*)
      T:=RED(T);
      IF T <> SIL THEN D:=FIRST(T) ELSE D:=SIL END;
      RETURN(D); 
(*3*) END DECOFTAG;


PROCEDURE GENPL(P,V,T,D: LIST): LIST;
(*Generate parameter list. P is a list of patterns. 
V is a list of values. T is a list of types and D is a 
list of descriptors. A parameter list is returned. *)
VAR   L, p, x: LIST;
BEGIN
(*1*) (*check patterns. *) L:=SIL;
      WHILE P <> SIL DO ADV(P,p,P); 
            IF p = PVAL  THEN ADV(V,x,V); L:=COMP(x,L);
         ELSIF p = PDESC THEN ADV(D,x,D); L:=COMP(x,L);
         ELSIF p = PTYP  THEN ADV(T,x,T); L:=COMP(x,L);
          ELSE UWRITE(p);
               ERROR(severe,"GENPL: invalid pattern skipped."); 
               END;
            END;
      L:=INV(L); RETURN(L);
(*4*) END GENPL;


PROCEDURE GENTE(Z,N,D: LIST): LIST;
(*Generate typed expression. Z is an S-expression,
N is a function name, D is a descriptor. A typed S-expression 
for evaluation is returned. *)
VAR   A: LIST;
BEGIN
(*1*) (*get arrow *)
      A:=GET(N,ARROW); 
      IF A = SIL THEN UWRITE(N);
         ERROR(severe,"GENTE: no signature defined."); 
         RETURN(Z) END; 
(*2*) (*get target *)
      A:=THIRD(A); 
      IF A = SIL THEN RETURN(Z) END; 
      IF RED(A) = SIL THEN A:=FIRST(A) END; (*single value*)  
      IF A = SIL THEN RETURN(Z) END; 
(*3*) (*combine *)
      A:=LIST2(A,D);
      Z:=TAG(Z,A); Z:=COMP(LISTX,Z);          
      RETURN(Z);
(*4*) END GENTE;


(* Execution part. *)
BEGIN

InitLISP;

END MASLISP.


(* -EOF- *)
