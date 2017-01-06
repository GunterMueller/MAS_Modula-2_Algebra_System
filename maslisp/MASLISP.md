(* ----------------------------------------------------------------------------
 * $Id: MASLISP.md,v 1.3 1995/11/05 08:54:09 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLISP.md,v $
 * Revision 1.3  1995/11/05 08:54:09  kredel
 * Support for small exit command.
 *
 * Revision 1.2  1992/02/12  17:32:21  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:57  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASLISP;

(* MAS Lisp Definition Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST; 

CONST FEXPR   = 2;
      MACRO   = 3;
      GENERIC = 4;


VAR TDEF, DEFAULT, ARROW, (*indicators*)

    ENV, (*global environement (alist)*)

    NULL, WT, SCHLUSS, schluss, TINFO,   

    EQS, NEQS, GTS, LTS, GEQ, LEQ, NOTS, UND, ODER,   

    ADD, SUB, MUL, QUOT, REM, POW,

    QUOTE, SETQ, COND, LISTX, 
    ASSIGN, READ, WRITE, DECREAD, DECWRITE, 
    
    PROGN, VARS, IFS, WHL, RPT, STRNG, DE, DF, DM, DG,  
    PROGA, GTO, LBEL, SETAV, ARY, ATM, RTN, ANY,

    UNIT, EXPOS, SPEC, SORT, SIG, IMPRT, IMPL, 
    MODEL, MAP, AXIOM, RULE, WHEN, 
   
    LAMBDA, FLAMBDA, MLAMBDA, GLAMBDA: LIST;

    trace:  BOOLEAN; (*flag, if tracing evaluation*)
    stricttyping: BOOLEAN; (*flag *)

    REP, FER, FERx, FEL, FELx, CONVVAL, CONVDES: LIST;

CONST rcsid = "$Id: MASLISP.md,v 1.3 1995/11/05 08:54:09 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ECENV(ENV: LIST): LIST;
(*Encode environment. The encoded environment E is returned. *)


PROCEDURE DCENV(E: LIST): LIST;
(*Decode environment. The encoded environment E is decoded. *)


PROCEDURE SETV(V, A: LIST; VAR ENV: LIST);
(*Set variable. V is a symbol and A is an S-expression. 
A is associated to V in the environment ENV. *)


PROCEDURE EXTENDENV(A, X: LIST; VAR ENV: LIST): BOOLEAN;
(*Extend environement. A is a list of symbols. X is a list 
of values. The environment ENV is extented by the bindings
of the symbols in A to the values in X. If the binding
is possible, then TRUE is returned else FALSE. *)


PROCEDURE COPYTOENV(V, EP: LIST; VAR ENV: LIST);
(*Copy to environement. V is a list of symbols. EP is an
environment. The environment ENV is extented by the bindings
of the symbols in V to the values in EP. *)


PROCEDURE SPECIALFORM(S: LIST): BOOLEAN;
(*Test if expression S is a special form. *)


PROCEDURE LAMBDAP(S: LIST): BOOLEAN;
(*Test if expression S is a lambda form. *)


PROCEDURE SEXPRP(X: LIST): BOOLEAN;
(*Test if X is a S-expression function. *)


PROCEDURE DEFE(X: LIST; VAR ENV: LIST): LIST;
(*Define expr function. X is a DE expression. A LAMBDA expression 
generated from X is associated to name(X) in the environment ENV. *)


PROCEDURE DEFF(X: LIST; VAR ENV: LIST): LIST;
(*Define fexpr function. X is a DF expression. A FLAMBDA expression 
generated from X is associated to name(X) in the environment ENV.*)


PROCEDURE DEFM(X: LIST; VAR ENV: LIST): LIST;
(*Define macro function. X is a DM expression. A MLAMBDA expression 
generated from X is associated to name(X) in the environment ENV.*)


PROCEDURE DEFMAP(X: LIST; VAR ENV: LIST): LIST;
(*Define generic map function. X is a MAP expression. A 
GLAMBDA expression generated from X is associated to name(X) 
in the environment ENV. *)


PROCEDURE DEFPROC(X: LIST; VAR ENV: LIST): LIST;
(*Define generic proc function. X is a DE expression. 
A GLAMBDA expression generated from X is associated to 
name(X) in the environment ENV.*)


PROCEDURE DEFRULE(X: LIST; VAR ENV: LIST): LIST;
(*Define generic rule function. X is a RULE expression. 
A GLAMBDA expression generated from X is associated to 
name(X) in the environment ENV.*)


PROCEDURE DSPEC(X: LIST; VAR ENV: LIST): LIST;
(*Define specification. X is a SPEC expression. An UNIT expression 
generated from X is associated to name(X) in the environment ENV.*)


PROCEDURE DMIA(X: LIST; VAR ENV: LIST): LIST;
(*Define model, implementation or axioms. X is a MODEL, 
IMPLEMENTATION or AXIOMS expression. An UNIT expression 
associated to name(X) is modified by a generated expression 
of X. *)


PROCEDURE TYPEOF(X: LIST): LIST;
(*Type of S-expression. X is an S-expression. A list of types, 
values and descriptors of X is returend. *)


PROCEDURE TAG(V,T: LIST): LIST;
(*Tag object. V is an S-expression, T is a type expression.
A tagged TYPEINFO S-expression is returned. *)


PROCEDURE VALOFTAG(L: LIST): LIST;
(*Value of tagged object. L is a tagged S-expression. 
The value component of L is returned. *)


PROCEDURE TYPOFTAG(L: LIST): LIST;
(*Type of tagged object. L is a tagged S-expression. 
The type component of L is returned.*)


PROCEDURE DECOFTAG(L: LIST): LIST;
(*Descriptor of tagged object. L is a tagged S-expression. 
The descriptor component of L is returned. *)


PROCEDURE GENPL(P,V,T,D: LIST): LIST;
(*Generate parameter list. P is a list of patterns. 
V is a list of values. T is a list of types and D is a 
list of descriptors. A parameter list is returned. *)


PROCEDURE GENTE(Z,N,D: LIST): LIST;
(*Generate typed expression. Z is an S-expression,
N is a function name, D is a descriptor. A typed S-expression 
for evaluation is returned. *)


END MASLISP.



(* -EOF- *)
