(* ----------------------------------------------------------------------------
 * $Id: MASLISPU.mi,v 1.3 1992/10/15 16:27:48 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLISPU.mi,v $
 * Revision 1.3  1992/10/15  16:27:48  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:24  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:20  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASLISPU;

(* MAS LISP Utility Implementation Module. *)


(* Import lists and declarations. *)

FROM SYSTEM IMPORT ADDRESS, ADR;

FROM MASELEM IMPORT GAMMAINT;

FROM MASSTOR IMPORT BETA, SIL, LIST,
                    LENGTH, LIST1, ADV, FIRST;

FROM MASERR IMPORT ERROR, harmless, severe;

FROM MASBIOS IMPORT GWRITE, LISTS, BLINES, SWRITE;

FROM SACLIST IMPORT FIRST3, LIST3, FIRST4, FIRST2, LIST2;

FROM MASSYM2 IMPORT SYMBOL, ENTER, GET, PUT, 
                   SYMTB, STLST, SYWRIT;

FROM MASSYM IMPORT UWRITE, UWRIT1, NOSHOW;


CONST PIND = 0;
      FIND = -1;

CONST rcsidi = "$Id: MASLISPU.mi,v 1.3 1992/10/15 16:27:48 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)

PROCEDURE CallCompiled(F, PI: LIST; VAR PO: LIST; VAR fu: BOOLEAN);
(*Call compiled function or procedure. F is a function or procedure 
symbol. PI is the list of input parameters. fu is TRUE if F is a 
function and FALSE if F is a procedure. PO is a list of output 
parameters if F is a procedure and PO is the output parameter if 
F is a function. *)
VAR   L, PT, I, O, I1, I2, I3, I4, I5, O1, O2, O3, C: LIST;
      i, o: INTEGER;
      P: ADDRESS;
      F0: PROCF0;  F1: PROCF1; F2: PROCF2; F3: PROCF3; F4: PROCF4; F5: PROCF5;
      P0: PROCP0;  P1: PROCP1; P2: PROCP2; P3: PROCP3; P4: PROCP4; P5: PROCP5;
      P0V1: PROCP0V1; P0V2: PROCP0V2;
      P1V1: PROCP1V1; P1V2: PROCP1V2; P1V3: PROCP1V3;
      P2V1: PROCP2V1; P2V2: PROCP2V2; P2V3: PROCP2V3;
      P3V1: PROCP3V1; P3V2: PROCP3V2; P3V3: PROCP3V3;
BEGIN
(*1*) (*initialize*) fu:=FALSE; 
      C:=GET(F,ARITY); L:=GET(F,SUBR);
      IF (L = SIL) OR (C <= SIL) THEN  
         ERROR(severe,"CallCompiled: unbound compiled procedure "); 
         UWRITE(F); RETURN END;
      ADV(L, PT,L); 
      IF (L = SIL) OR (PT <> NOSHOW) THEN  
         ERROR(severe,"CallCompiled: invalid code pointer "); 
         UWRITE(F); RETURN END;
(*2*) (*prepare parameters*)  P:=ADDRESS(FIRST(L)); FIRST3(C,PT,I,O); 
      IF LENGTH(PI) <> I THEN
         ERROR(severe,"CallCompiled: input parameter mismatch ");
         UWRITE(F); RETURN END;
      IF LENGTH(PO) <> O THEN
         ERROR(severe,"CallCompiled: output parameter mismatch ");
         UWRITE(F); RETURN END;
      i:=INTEGER(I); o:=INTEGER(O);
(*3*) (*function case. *) 
      IF PT = FIND THEN 
      CASE i  OF 
           0: F0:=PROCF0(P); PO:=F0(); |
           1: F1:=PROCF1(P); I1:=FIRST(PI); PO:=F1(I1); |
           2: F2:=PROCF2(P); FIRST2(PI,I1,I2); PO:=F2(I1,I2); |
           3: F3:=PROCF3(P); FIRST3(PI,I1,I2,I3); PO:=F3(I1,I2,I3); |
           4: F4:=PROCF4(P); FIRST4(PI,I1,I2,I3,I4); PO:=F4(I1,I2,I3,I4); |
           5: F5:=PROCF5(P); ADV(PI, I1, PI); FIRST4(PI,I2,I3,I4,I5); 
              PO:=F5(I1,I2,I3,I4,I5); |
         ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
              UWRITE(F) 
              END;
      fu:=TRUE; RETURN END;
(*4*) (*procedure case. *) 
      IF PT = PIND THEN 
      CASE i  OF 
           0: CASE o  OF 
                   0: P0:=PROCP0(P); P0; |
                   1: P0V1:=PROCP0V1(P); O1:=FIRST(PO); 
                      P0V1(O1); PO:=LIST1(O1) |                      
                   2: P0V2:=PROCP0V2(P); FIRST2(PO,O1,O2); 
                      P0V2(O1,O2); PO:=LIST2(O1,O2) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
              |
           1: CASE o  OF 
                   0: P1:=PROCP1(P); I1:=FIRST(PI);  
                      P1(I1); |
                   1: P1V1:=PROCP1V1(P); I1:=FIRST(PI); O1:=FIRST(PO);  
                      P1V1(I1,O1); PO:=LIST1(O1) |
                   2: P1V2:=PROCP1V2(P); I1:=FIRST(PI); FIRST2(PO,O1,O2); 
                      P1V2(I1,O1,O2);  PO:=LIST2(O1,O2) |
                   3: P1V3:=PROCP1V3(P); I1:=FIRST(PI); FIRST3(PO,O1,O2,O3); 
                      P1V3(I1,O1,O2,O3);  PO:=LIST3(O1,O2,O3) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
              |
           2: CASE o  OF 
                   0: P2:=PROCP2(P); FIRST2(PI,I1,I2); 
                      P2(I1,I2) |
                   1: P2V1:=PROCP2V1(P); FIRST2(PI,I1,I2); O1:=FIRST(PO); 
                      P2V1(I1,I2,O1); PO:=LIST1(O1) |
                   2: P2V2:=PROCP2V2(P); FIRST2(PI,I1,I2); 
                      FIRST2(PO,O1,O2);
                      P2V2(I1,I2,O1,O2); PO:=LIST2(O1,O2) |
                   3: P2V3:=PROCP2V3(P); FIRST2(PI,I1,I2); 
                      FIRST3(PO,O1,O2,O3);
                      P2V3(I1,I2,O1,O2,O3); PO:=LIST3(O1,O2,O3) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
              |
           3: CASE o  OF 
                   0: P3:=PROCP3(P); FIRST3(PI,I1,I2,I3); 
                      P3(I1,I2,I3) |
                   1: P3V1:=PROCP3V1(P); FIRST3(PI,I1,I2,I3); O1:=FIRST(PO); 
                      P3V1(I1,I2,I3,O1); PO:=LIST1(O1) |
                   2: P3V2:=PROCP3V2(P); FIRST3(PI,I1,I2,I3); 
                      FIRST2(PO,O1,O2);
                      P3V2(I1,I2,I3,O1,O2); PO:=LIST2(O1,O2) |
                   3: P3V3:=PROCP3V3(P); FIRST3(PI,I1,I2,I3); 
                      FIRST3(PO,O1,O2,O3);
                      P3V3(I1,I2,I3,O1,O2,O3); PO:=LIST3(O1,O2,O3) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
              |
           4: CASE o  OF 
                   0: P4:=PROCP4(P); FIRST4(PI,I1,I2,I3,I4); 
                      P4(I1,I2,I3,I4) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
              |
           5: CASE o  OF 
                   0: P5:=PROCP5(P); ADV(PI,I1,PI); FIRST4(PI,I2,I3,I4,I5); 
                      P5(I1,I2,I3,I4,I5) |
                 ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
                      UWRITE(F) 
                      END;
         ELSE ERROR(severe,"CallCompiled: unknown parameter number "); 
              UWRITE(F) 
              END;
      RETURN END;
(*5*) (*not known.*)
      ERROR(severe,"CallCompiled: unknown procedure type "); 
      UWRITE(F); RETURN; 
(*6*) END CallCompiled;


PROCEDURE Compiled(P: ADDRESS; T: LIST; VAR S: ARRAY OF CHAR);
(*Compiled function declaration. P is the code address of a compiled
function or procedure. T is the signature of P and S is the print 
name of P. A symbol with name S is entered into the symbol table. *)
VAR   X, Y: LIST;
      L: GAMMAINT;
BEGIN
(*1*) (*intern. *) X:=ENTER(LISTS(S)); 
(*2*) (*arity. *) Y:=GET(X,ARITY);
      IF Y <> SIL THEN UWRITE(X);
         ERROR(harmless,"arity redefined");
         END;  
      PUT(X,ARITY,T); 
(*3*) (*function pointer, entry address. *) Y:=GET(X,SUBR);
      IF Y <> SIL THEN UWRITE(X);
         ERROR(harmless,"code pointer redefined");
         END; 
      L:=LIST2(NOSHOW,GAMMAINT(P)); PUT(X,SUBR,L); PUT(X,EXTYP,EXPR);
(*4*) END Compiled;


PROCEDURE Compiledp0(F: PROCP0; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p0. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,0,0); Compiled(P,TP,S);
(*4*) END Compiledp0;


PROCEDURE Compiledp1(F: PROCP1; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,1,0); Compiled(P,TP,S);
(*4*) END Compiledp1;


PROCEDURE Compiledp2(F: PROCP2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,2,0); Compiled(P,TP,S);
(*4*) END Compiledp2;


PROCEDURE Compiledp3(F: PROCP3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,3,0); Compiled(P,TP,S);
(*4*) END Compiledp3;


PROCEDURE Compiledp4(F: PROCP4; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p4. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,4,0); Compiled(P,TP,S);
(*4*) END Compiledp4;


PROCEDURE Compiledp5(F: PROCP5; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p5. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,5,0); Compiled(P,TP,S);
(*4*) END Compiledp5;


PROCEDURE Compiledf0(F: PROCF0; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f0. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,0,0); Compiled(P,TP,S);
(*4*) END Compiledf0;


PROCEDURE Compiledf1(F: PROCF1; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f1. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,1,0); Compiled(P,TP,S);
(*4*) END Compiledf1;
                       

PROCEDURE Compiledf2(F: PROCF2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f2. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,2,0); Compiled(P,TP,S);
(*4*) END Compiledf2;
                       

PROCEDURE Compiledf3(F: PROCF3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f3. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,3,0); Compiled(P,TP,S);
(*4*) END Compiledf3;
                       

PROCEDURE Compiledf4(F: PROCF4; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f4. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,4,0); Compiled(P,TP,S);
(*4*) END Compiledf4;
                       

PROCEDURE Compiledf5(F: PROCF5; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f5. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(FIND,5,0); Compiled(P,TP,S);
(*4*) END Compiledf5;
                       

PROCEDURE Compiledp1v2(F: PROCP1V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1v2. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,1,2); Compiled(P,TP,S);
(*4*) END Compiledp1v2;
                       

PROCEDURE Compiledp1v3(F: PROCP1V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1v3. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,1,3); Compiled(P,TP,S);
(*4*) END Compiledp1v3;
                       

PROCEDURE Compiledp2v2(F: PROCP2V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2v2. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,2,2); Compiled(P,TP,S);
(*4*) END Compiledp2v2;
                       

PROCEDURE Compiledp2v3(F: PROCP2V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2v3. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,2,3); Compiled(P,TP,S);
(*4*) END Compiledp2v3;
                       

PROCEDURE Compiledp3v2(F: PROCP3V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3v2. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,3,2); Compiled(P,TP,S);
(*4*) END Compiledp3v2;
                       

PROCEDURE Compiledp3v3(F: PROCP3V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3v3. F is a Modula-2 procedure, S is 
the print name of F. *)
VAR   TP: LIST;
      P: ADDRESS;
BEGIN
(*1*) (*function pointer. *) P:=ADDRESS(F); 
(*2*) (*declare. *) TP:=LIST3(PIND,3,3); Compiled(P,TP,S);
(*4*) END Compiledp3v3;


PROCEDURE CompSummary;
(*Compiled function and procedure summary. Write out all 
compiled functions with their signature from symbol table SYMTB. *)
VAR   X, V, W, k, i, o: LIST;
      p, f: INTEGER;
BEGIN
(*1*) (*initialize. *) p:=0; f:=0;
      SWRITE("List of all compiled functions and procedures: "); BLINES(1); 
      X:=STLST(SYMTB); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); W:=GET(V,ARITY);
            IF W <> SIL THEN    
               FIRST3(W, k,i,o); 
               IF k = PIND THEN p:=p+1; 
                  SWRITE("PROCEDURE "); SYWRIT(V);
                  IF i + o > 0 THEN SWRITE("(");
                     WHILE i > 0 DO i:=i-1; SWRITE("LIST");
                           IF i > 0 THEN SWRITE(",") END;
                           END;
                     IF o > 0 THEN SWRITE("; ") END;
                     WHILE o > 0 DO o:=o-1; SWRITE("LIST");
                           IF o > 0 THEN SWRITE(",") END;
                           END;
                     SWRITE(")") END
               ELSIF k = FIND THEN f:=f+1;
                     SWRITE("FUNCTION  "); SYWRIT(V);
                     SWRITE("(");
                     WHILE i > 0 DO i:=i-1; SWRITE("LIST");
                           IF i > 0 THEN SWRITE(",") END;
                           END;
                     IF o > 0 THEN SWRITE("; ") END;
                     WHILE o > 0 DO o:=o-1; SWRITE("LIST");
                           IF o > 0 THEN SWRITE(",") END;
                           END;
                     SWRITE("): LIST") 
               ELSE UWRIT1(W) END;
               BLINES(0); END;
            END;
(*3*) (*summary. *) BLINES(1);
      GWRITE(GAMMAINT(f)); SWRITE(" functions and "); 
      GWRITE(GAMMAINT(p)); SWRITE(" procedures accessible."); 
      BLINES(0); 
(*9*) END CompSummary;


PROCEDURE Declare(VAR X: LIST; VAR S: ARRAY OF CHAR);
(*Declare. X is declared as symbol with print name S. *)
BEGIN
(*1*) (*intern. *) X:=ENTER(LISTS(S));
(*2*) END Declare;


PROCEDURE PROCP(X: LIST): BOOLEAN;
(*Procedure Pointer. Test if the symbol X is a compiled function. *)
BEGIN
(*1*) (*symbol. *) IF NOT SYMBOL(X) THEN RETURN(FALSE) END; 
(*2*) (*function pointer, entry address. *) 
      IF GET(X,ARITY) <> SIL THEN RETURN(TRUE) END;
      RETURN(FALSE);
(*4*) END PROCP;


PROCEDURE Signature(F: LIST; VAR PI, PO: LIST; VAR def: BOOLEAN);
(*Signature of a compiled function or procedure. F is a function or 
procedure symbol. PI is the number of input parameters. def is TRUE if 
F is defined as compiled function or procedure else def is FALSE. 
PO is the number of output parameters if F is a procedure, 
PO = -1 if F is a function. *)
VAR   L, C, PT: LIST;
BEGIN
(*1*) (*initialize*) PI:=0; PO:=0; def:=FALSE; 
      C:=GET(F,ARITY); L:=GET(F,SUBR);
      IF (L = SIL) OR (C <= SIL) THEN RETURN END;
      def:=TRUE;
(*2*) (*prepare parameters*)  FIRST3(C,PT,PI,PO); 
      IF PT = FIND THEN PO:=-1 END;
(*3*) END Signature;


(* Execution part. *)
BEGIN
      Declare(EXTYP,"EXTYP");
      Declare(ARITY,"ARITY");
      Declare(SUBR,"SUBR");

END MASLISPU.


(* -EOF- *)
