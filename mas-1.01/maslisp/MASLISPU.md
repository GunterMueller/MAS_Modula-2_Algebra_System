(* ----------------------------------------------------------------------------
 * $Id: MASLISPU.md,v 1.2 1992/02/12 17:32:23 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASLISPU.md,v $
 * Revision 1.2  1992/02/12  17:32:23  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:59  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASLISPU;

(* MAS Lisp Utility Definition Module. *)



(* Import lists and declarations. *)


FROM MASSTOR IMPORT LIST; 


CONST EXPR = 1;


(* Types, S-Expresion Types and Indicators. *)
CONST rcsid = "$Id: MASLISPU.md,v 1.2 1992/02/12 17:32:23 pesch Exp $";
CONST copyright = "Copyright (c) 1989 - 1992 Universitaet Passau";



TYPE PROCF0 = PROCEDURE():LIST;
TYPE PROCF1 = PROCEDURE(LIST):LIST;
TYPE PROCF2 = PROCEDURE(LIST, LIST):LIST;
TYPE PROCF3 = PROCEDURE(LIST, LIST, LIST):LIST;
TYPE PROCF4 = PROCEDURE(LIST, LIST, LIST, LIST):LIST;
TYPE PROCF5 = PROCEDURE(LIST, LIST, LIST, LIST, LIST):LIST;

TYPE PROCP0 = PROCEDURE();
TYPE PROCP1 = PROCEDURE(LIST);
TYPE PROCP2 = PROCEDURE(LIST, LIST);
TYPE PROCP3 = PROCEDURE(LIST, LIST, LIST);
TYPE PROCP4 = PROCEDURE(LIST, LIST, LIST, LIST);
TYPE PROCP5 = PROCEDURE(LIST, LIST, LIST, LIST, LIST);

TYPE PROCP0V1 = PROCEDURE(VAR LIST);
TYPE PROCP0V2 = PROCEDURE(VAR LIST, VAR LIST);

TYPE PROCP1V1 = PROCEDURE(LIST, VAR LIST);
TYPE PROCP1V2 = PROCEDURE(LIST, VAR LIST, VAR LIST);
TYPE PROCP1V3 = PROCEDURE(LIST, VAR LIST, VAR LIST, VAR LIST);

TYPE PROCP2V1 = PROCEDURE(LIST, LIST, VAR LIST);
TYPE PROCP2V2 = PROCEDURE(LIST, LIST, VAR LIST, VAR LIST);
TYPE PROCP2V3 = PROCEDURE(LIST, LIST, VAR LIST, VAR LIST, VAR LIST);

TYPE PROCP3V1 = PROCEDURE(LIST, LIST, LIST, VAR LIST);
TYPE PROCP3V2 = PROCEDURE(LIST, LIST, LIST, VAR LIST, VAR LIST);
TYPE PROCP3V3 = PROCEDURE(LIST, LIST, LIST, VAR LIST, VAR LIST, VAR LIST);


VAR EXTYP, ARITY, SUBR: LIST; (*indicators*)


(* Procedure declarations. *)

PROCEDURE CallCompiled(F, PI: LIST; VAR PO: LIST; VAR fu: BOOLEAN);
(*Call compiled function or procedure. F is a function or procedure 
symbol. PI is the list of input parameters. fu is TRUE if F is a 
function and FALSE if F is a procedure. PO is a list of output 
parameters if F is a procedure and PO is the output parameter if 
F is a function. *)


PROCEDURE Compiledp0(F: PROCP0; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p0. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledp1(F: PROCP1; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledp2(F: PROCP2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledp3(F: PROCP3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledp4(F: PROCP4; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p4. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledp5(F: PROCP5; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p5. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledf0(F: PROCF0; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f0. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE Compiledf1(F: PROCF1; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f1. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledf2(F: PROCF2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f2. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledf3(F: PROCF3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f3. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledf4(F: PROCF4; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f4. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledf5(F: PROCF5; VAR S: ARRAY OF CHAR);
(*Compiled function declaration f5. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp1v2(F: PROCP1V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1v2. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp1v3(F: PROCP1V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p1v3. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp2v2(F: PROCP2V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2v2. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp2v3(F: PROCP2V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p2v3. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp3v2(F: PROCP3V2; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3v2. F is a Modula-2 procedure, S is 
the print name of F. *)
                       

PROCEDURE Compiledp3v3(F: PROCP3V3; VAR S: ARRAY OF CHAR);
(*Compiled function declaration p3v3. F is a Modula-2 procedure, S is 
the print name of F. *)


PROCEDURE CompSummary;
(*Compiled function and procedure summary. Write out all 
compiled functions with their signature from symbol table SYMTB. *)


PROCEDURE Declare(VAR X: LIST; VAR S: ARRAY OF CHAR);
(*Declare. X is declared as symbol with print name S. *)


PROCEDURE PROCP(X: LIST): BOOLEAN;
(*Procedure Pointer. Test if the symbol X is a compiled function. *)


PROCEDURE Signature(F: LIST; VAR PI, PO: LIST; VAR def: BOOLEAN);
(*Signature of a compiled function or procedure. F is a function or 
procedure symbol. PI is the number of input parameters. def is TRUE if 
F is defined as compiled function or procedure else def is FALSE. 
PO is the number of output parameters if F is a procedure, 
PO = -1 if F is a function. *)


END MASLISPU.



(* -EOF- *)
