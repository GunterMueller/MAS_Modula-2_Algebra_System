(* ----------------------------------------------------------------------------
 * $Id: MASREP.mi,v 1.3 1992/10/15 16:27:51 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASREP.mi,v $
 * Revision 1.3  1992/10/15  16:27:51  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:29  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:24  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASREP;

(* MAS Representation Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT SIL, LIST, 
                    LIST1, ADV, FIRST, RED, COMP, INV, SFIRST, SRED;

FROM SACLIST IMPORT EQUAL, CINV, CONC, CCONC, SECOND, RED2,
                    FIRST3, LIST3, FIRST2, ADV2, LIST2, COMP2;

FROM MASSYM2 IMPORT PUT, SYMBOL, ASSOC, ASSOCQ; 

FROM MASLISPU IMPORT Declare, EXTYP;

FROM MASLISP IMPORT ENV, FEXPR;

FROM MASSPEC IMPORT EVALUATE;

VAR WT, RP: LIST;

CONST rcsidi = "$Id: MASREP.mi,v 1.3 1992/10/15 16:27:51 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE NewRep(): LIST;
(*New representation. A new representation is returned. *)
BEGIN RETURN(LIST3(RP,SIL,SIL))
(*9*) END NewRep;


PROCEDURE SetRep(n,e,r: LIST);
(*Set representation. r is a representation. n is a unique 
label, e is an expression. *)
VAR   x, y, z: LIST;
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN END;
      z:=RED(r); x:=ASSOCQ(n,FIRST(z));
(*2*) IF x <> SIL 
         THEN SFIRST(x,e) 
         ELSE x:=LIST1(e); y:=COMP(n,x);
              SRED(x,FIRST(z)); SFIRST(z,y);
         END;
(*9*) END SetRep;


PROCEDURE GetRep(n,r: LIST): LIST;
(*Get representation. r is a representation. n is a unique 
label, An expression e stored under n is returned. *)
VAR   e: LIST;
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN(SIL) END;
      e:=ASSOCQ(n,SECOND(r));
(*2*) IF e <> SIL THEN e:=FIRST(e) END;
      RETURN(e);
(*9*) END GetRep;


PROCEDURE CopyRep(r: LIST): LIST;
(*Copy representation. r is a representation. A copy of r is 
returned. Step counters are reset. *)
VAR   x: LIST;
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN(NewRep()) END;
(*2*) x:=SECOND(r); x:=INV(CINV(x));
      x:=LIST3(RP,x,SIL); RETURN(x);
(*9*) END CopyRep;


PROCEDURE StepRep(r: LIST): LIST;
(*Step through representation. r is a representation. 
The next expression e and its label n are returned as pair (n,e). 
If all pairs (n,e) of representation r have been processed, 
then NIL is returned. *)
VAR   x, y, n, e, p: LIST;
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN(SIL) END;
(*2*) (*next step. *) x:=RED2(r); 
      IF FIRST(x) <> SIL THEN y:=FIRST(x); y:=RED2(y);
         SFIRST(x,y); 
         IF y <> SIL THEN FIRST2(y,n,e); 
            y:=LIST2(n,e); RETURN(y) END;
         RETURN(SIL); END;
(*3*) (*restart. *) y:=SECOND(r);             
      IF y <> SIL THEN SFIRST(x,y); FIRST2(y,n,e); 
         y:=LIST2(n,e); RETURN(y) END;
      RETURN(SIL); 
(*9*) END StepRep;


PROCEDURE ForEachinRep(r, f, E: LIST): LIST;
(*For each pair (n,e) in r apply function f. r is a representation. 
(n, e) is a pair in r, where e is an expression and n is its label.
f is applied to (n, e) such that p = f(n,e) with p = (n', e') or p = NIL. 
If p <> NIL, then the pair (n', e') is added to the returned 
representation r' = { n' e' : f(n,e) <> NIL, n e in r }. E is a 
LISP environment, if E = NIL, then the top level environment is used. *)
VAR   x, y, n, e, p: LIST;
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN(SIL) END;
      IF E = SIL THEN E:=ENV END;
(*2*) (*assoc list. *) x:=SECOND(r); y:=SIL; 
      WHILE x <> SIL DO ADV2(x,n,e,x); 
            p:=LIST3(f,n,e); p:=EVALUATE(p,E);  
            IF p <> SIL THEN FIRST2(p,n,e); y:=COMP2(e,n,y); END;
            END;
      y:=INV(y); 
(*3*) (*new rep. *) r:=LIST3(RP,y,SIL);
      RETURN(r); 
(*9*) END ForEachinRep;


PROCEDURE FullRep(r: LIST): LIST;
(*Full representation. Test for non-empty representation.
r is a representation. *)
BEGIN 
(*1*) IF FIRST(r) <> RP THEN RETURN(SIL) END;
(*2*) IF r <> SIL THEN 
         IF SECOND(r) <> SIL THEN RETURN(WT) END;
         END;
      RETURN(SIL);
(*9*) END FullRep;


PROCEDURE ForEachinList(r, f, E: LIST): LIST;
(*For each element e in r apply function f. r is a list. e is an 
element in r. f is applied to e such that e' = f(e). 
E is a LISP environment, if E = NIL, then the top level environment 
is used. *)
VAR   x, y, e, p: LIST;
BEGIN 
(*1*) IF r = SIL THEN RETURN(SIL) END;
      IF E = SIL THEN E:=ENV END;
(*2*) (*run through list. *) x:=r; y:=SIL; 
      WHILE x <> SIL DO ADV(x,e,x); 
            p:=LIST2(f,e); p:=EVALUATE(p,E);  
            y:=COMP(p,y); END;
      y:=INV(y); 
(*3*) RETURN(y); 
(*9*) END ForEachinList;


BEGIN
 
      Declare(WT,"T");
      Declare(RP,"REP"); PUT(RP,EXTYP,FEXPR);

END MASREP.


(* -EOF- *)
