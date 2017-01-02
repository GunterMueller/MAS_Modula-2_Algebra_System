(* ----------------------------------------------------------------------------
 * $Id: MASU.mi,v 1.8 1995/11/05 09:02:44 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASU.mi,v $
 * Revision 1.8  1995/11/05 09:02:44  kredel
 * Small exit, access to CREADB, UREAD and cosmetic.
 *
 * Revision 1.7  1995/09/12  17:24:40  pesch
 * Corrected to handle prompts other then "MAS:".
 *
 * Revision 1.6  1995/03/06  16:45:43  pesch
 * Modified to make use of GNU readline possible.
 *
 * Revision 1.5  1994/03/11  15:38:25  pesch
 * Corrected use of MEMBER.
 *
 * Revision 1.4  1993/05/11  10:57:56  kredel
 * Added help()
 *
 * Revision 1.3  1992/10/15  16:30:42  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:55  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:12:20  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASU;

(* MAS Utility Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT MASEXP;

FROM MASSTOR IMPORT BETA, SIL, LIST, LENGTH, 
                    LIST1, ADV, FIRST, RED, COMP, INV, SFIRST, SRED;

FROM MASBIOS IMPORT CREADB, GWRITE, LISTS, OStreamKind, BLINES, SWRITE, SOLINE,
                    SILINE, SLIST, StorSummary, Summary, termkind;

FROM MASBIOSU IMPORT INP, OUT, SHUT, EDIT, DOS, CLTIS;

FROM SACLIST IMPORT EQUAL, CLOUT, RED2, CINV, CONC, CCONC, SECOND, MEMBER, 
                    FIRST3, LIST3, ADV3, FIRST2, ADV2, LIST2, COMP2;

FROM MASSYM2 IMPORT SYWRIT, ACOMP, SYMBOL, SREAD, GET, PUT, 
                    EXPLOD, PACK, ENTER, ACOMP1,  
                    ASSOC, SYMTB, STWRT, STLST, SymSummary;

FROM MASSYM IMPORT NOSHOW, ATOM, ELEMP, UREAD, UWRITE, UWRIT1;

FROM MASLISPU IMPORT EXTYP, ARITY, SUBR, EXPR, 
                     Declare, CallCompiled, Signature,
                     Compiledp0, Compiledp1, Compiledp2, Compiledp3,
                     Compiledf0, Compiledf1, Compiledf2, Compiledf3,
                     Compiledp1v2, Compiledp2v2,
                     CompSummary, PROCP;

FROM MASLISP IMPORT TDEF, DEFAULT, ARROW, (*indicators*)
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
                    LAMBDA, FLAMBDA, MLAMBDA, GLAMBDA,
                    REP, FER, FERx, FEL, FELx, CONVVAL, CONVDES,
                    trace, stricttyping;

FROM MASSPEC IMPORT EVALUATE;

FROM MASREP IMPORT NewRep, FullRep, SetRep, GetRep, CopyRep, 
                   StepRep, ForEachinRep, ForEachinList;

FROM MASPARSE IMPORT Parse, SwitchParse;

FROM ALDPARSE IMPORT Aparse;


TYPE pragmas = ( mas, lisp, aldes, time, debug, 
                 Trace, fussy, sloppy, genparse );

VAR  M2S, LSP, ALD, TME, DBG, 
     SHOW, TRC, FUS, SLO, GENP: LIST;
     Parser: pragmas;
     genparsing: BOOLEAN;
     alls, modname, comment, loaded, listi: LIST; 

CONST PIND = 0; (*dirty, dirty. *)
      FIND = -1;
CONST rcsidi = "$Id: MASU.mi,v 1.8 1995/11/05 09:02:44 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



(* Procedure declarations. *)


PROCEDURE InitExternalsU();
(*Initialize external compiled utility procedures. *)
VAR   x, y, f: LIST; 
BEGIN 
(*1*) (*internal compiled procedures *)
      Compiledp0(DumpVars,"DUMPENV");
      Compiledp0(UnitDump,"DUMPUNIT");
      Compiledp0(SymSummary,"SYMTB");
      Compiledp0(StorSummary,"GCM");
      Compiledp0(Summary,"BIOS");
      Compiledp0(CompSummary,"EXTPROCS"); 
      Compiledp0(HELP,"HELP"); 
      Compiledp1(Help,"helpfx"); 
      Compiledp1(ProcMod,"procinmodx"); 
      Compiledp1(ProcSummary,"ProcSummary"); 
      Compiledp0(VarSummary,"VARS");
      Compiledp0(SortSummary,"SORTS");
      Compiledp0(UnitSummary,"UNITS");
      Compiledp0(ArrowSummary,"SIGS");
      Compiledp0(GenericSummary,"GENERICS");
      Compiledp0(ListVars,"LISTENV");
(*2*) (*Representations. *)
      Compiledf0(NewRep,"NewRep");
      Compiledf2(GetRep,"GetRep");
      Compiledp3(SetRep,"SetRep");
      Compiledf1(FullRep,"FullRep");
      Compiledf1(CopyRep,"CopyRep");
      Compiledf1(StepRep,"StepRep");
      Compiledf3(ForEachinRep,"ForEachX");
      Compiledf3(ForEachinList,"ForEachY");
(*3*) (*external Compiled procedures *)
      Compiledf1(INP,"IN");
      Compiledf1(OUT,"OUT");
      Compiledf1(SHUT,"SHUT");
      Compiledf1(EDIT,"EDIT");
      Compiledf1(DOS,"DOS");
      Compiledf1(LENGTH,"LENGTH");
      Compiledf1(FIRST,"FIRST");
      Compiledf1(FIRST,"CAR");
      Compiledf1(SECOND,"SECOND");
      Compiledf1(RED,"RED");
      Compiledf1(RED,"CDR");
      Compiledp2(SRED,"SRED");
      Compiledp2(SFIRST,"SFIRST");
      Compiledf1(INV,"INV");
      Compiledf1(CINV,"CINV");
      Compiledf1(CINV,"REVERSE");
      Compiledf0(CREADB,"CREADB");
      Compiledp1(BLINES,"BLINES");
      Compiledp1(CLOUT,"CLOUT");
      Compiledp1(CLOUT,"SWRITE");
      Compiledf2(COMP,"COMP");
      Compiledf2(COMP,"CONS");
      Compiledf2(CONC,"CONC");
      Compiledf2(CCONC,"CCONC");
      Compiledf2(CCONC,"JOIN");
      Compiledf2(EQUAL,"EQUAL");
      Compiledf2(MASEXP,"POW");
      Compiledp1v2(ADV,"ADV");
      Compiledp3(siline,"SILINE");
      Compiledp3(soline,"SOLINE");
(*      Compiledp0(SSYTBAL,"BALANCE");*)
      Compiledp1(MWRITE,"MWRITE");
      Compiledp1(UWRITE,"UWRITE");
      Compiledf0(UREAD,"UREAD");
(*4*) (*Initialize Pragmas. *)
      InitPragma;
      (*TEST   CompSummary;   TEST*)
(*5*) (*Variables. *)  
      Declare(alls,"all"); 
      Declare(modname,"ModulName"); 
      Declare(comment,"Comment"); 
      Declare(listi,"LIST"); 
      Declare(loaded,"Loaded"); 
(*6*) (* eval (DF help (x) (helpfx x)). *)
      Declare(f,"help");  Declare(x,"x"); Declare(y,"helpfx");  
      x:=LIST1(x); y:=COMP(y,x); y:=LIST1(y);  
      y:=COMP(x,y); y:=COMP(f,y);
      Declare(f,"DF"); y:=COMP(f,y);
      y:=EVALUATE(y,ENV);  
(*7*) (* eval (DF procinmod (x) (procinmodx x)). *)
      Declare(f,"procinmod");  Declare(x,"x"); Declare(y,"procinmodx");  
      x:=LIST1(x); y:=COMP(y,x); y:=LIST1(y);  
      y:=COMP(x,y); y:=COMP(f,y);
      Declare(f,"DF"); y:=COMP(f,y);
      y:=EVALUATE(y,ENV);  
(*9*) END InitExternalsU;


(*Display component. *)

PROCEDURE DumpVars;
(*Write out all variables with their current binding. *)
VAR   Y, X, V, W: LIST;
BEGIN
(*1*) (*initialize. *) X:=ENV; BLINES(0); 
(*2*) (*loop on alist. *) 
      WHILE X <> SIL DO ADV2(X,V,W,X);
            Y:=LIST3(SETQ,V,W); UWRITE(Y); 
            END;
(*9*) END DumpVars;


PROCEDURE UnitSummary;
(*Write out all variables with their current binding. *)
VAR   Y, X, V, W, WP: LIST;
BEGIN
(*1*) (*initialize. *) X:=ENV; BLINES(0); 
      SWRITE("List of all declared units: "); BLINES(1); 
(*2*) (*loop on alist. *) 
      WHILE X <> SIL DO ADV2(X,V,W,X);
            IF W > SIL THEN ADV(W,Y,WP);
               IF Y = UNIT THEN UWRIT1(V); SWRITE(", ");
                  END; 
               END;
            END;
      BLINES(1);
(*9*) END UnitSummary;


PROCEDURE UnitDump;
(*Write out all variables with their current binding. *)
VAR   Y, X, V, W, WP: LIST;
BEGIN
(*1*) (*initialize. *) X:=ENV; BLINES(1); 
      SWRITE(" PRAGMA(LISP). "); BLINES(1);
(*2*) (*loop on alist. *) 
      WHILE X <> SIL DO ADV2(X,V,W,X);
            IF W > SIL THEN ADV(W,Y,WP);
               IF Y = UNIT THEN Y:=LIST3(SETQ,V,W); UWRITE(Y); END; 
               END;
            END;
      BLINES(1);
      SWRITE(" (PRAGMA MODULA) "); BLINES(1);
(*9*) END UnitDump;


PROCEDURE VarSummary;
(*Write out all defined variables. *)
VAR a, X, V, W, WP, Z: LIST;
BEGIN
(*1*) (*initialize. *) a:=0;
      SWRITE("List of all declared variables: "); BLINES(1); 
      X:=STLST(SYMTB); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); W:=GET(V,TDEF);
            IF W <> SIL THEN a:=a+1;   
               SWRITE("VAR "); SYWRIT(V); SWRITE(": ");
               FIRST2(W,Z,WP); UWRIT1(Z); 
               IF WP <> SIL THEN 
                  Z:=COMP(DECWRITE,W);
                  SWRITE(' "');
                  Z:=EVALUATE(Z,ENV); (*write out*)
                  SWRITE('"');
                  END;
               SWRITE(".");
               BLINES(0); END;
            END;
(*3*) (*summary. *) BLINES(1);
      GWRITE(a); SWRITE(" declared variables."); 
      BLINES(0); 
(*9*) END VarSummary;


PROCEDURE SortSummary;
(*Write out all defined sorts. *)
VAR a, X, V, W, s, t, f: LIST;
BEGIN
(*1*) (*initialize. *) a:=0;
      SWRITE("List of all sorts: "); BLINES(1); 
      X:=STLST(SYMTB); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); W:=GET(V,SORT);
            IF W <> SIL THEN a:=a+1;   
               UWRIT1(V); SWRITE(", ");
               END;
            END;
(*3*) (*summary. *) BLINES(1);
      GWRITE(a); SWRITE(" sorts."); 
      BLINES(0); 
(*9*) END SortSummary;


PROCEDURE ArrowSummary;
(*Write out all defined arrows. *)
VAR a, X, V, W, s, t, f: LIST;
BEGIN
(*1*) (*initialize. *) a:=0;
      SWRITE("List of all signatures: "); BLINES(1); 
      X:=STLST(SYMTB); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); W:=GET(V,ARROW);
            IF W <> SIL THEN a:=a+1;   
               FIRST3(W, s,f,t); 
               SWRITE("SIGNATURE "); SYWRIT(f); 
               UWRIT1(s); 
               IF RED(t) = SIL THEN t:=FIRST(t) END; (*single value*)
               IF t <> SIL THEN SWRITE(": "); UWRIT1(t) END;
               SWRITE(".");
               BLINES(0); END;
            END;
(*3*) (*summary. *) BLINES(1);
      GWRITE(a); SWRITE(" signatures."); 
      BLINES(0); 
(*9*) END ArrowSummary;


PROCEDURE GenericSummary;
(*Write out all defined generic items. *)
VAR   M, I, E, a, X, V, W, Y, s, t, f: LIST;
BEGIN
(*1*) (*initialize. *) a:=0; 
      SWRITE("List of all generic items: "); BLINES(1); 
      X:=ENV; 
(*2*) (*loop on environment list. *) 
      WHILE X <> SIL DO ADV2(X, V,W,X); 
            IF W > SIL THEN Y:=FIRST(W) ELSE Y:=SIL END;
            IF Y = GLAMBDA THEN a:=a+1;   
               W:=RED2(W); FIRST3(W,M,I,E); 
               SYWRIT(V); SWRITE(":"); BLINES(0);
               WHILE M <> SIL DO ADV2(M, s,f,M);
                     f:=COMP2(MAP,s,f); MWRITE(f);
                     END;
               IF I <> SIL THEN f:=FIRST(I); f:=LIST3(SETQ,V,f);
                                MWRITE(f); END;
               WHILE E <> SIL DO ADV(E, s, E);
                     f:=COMP(RULE,s); MWRITE(f);
                     END;
               END;
            END;
(*3*) (*summary. *) BLINES(1);
      GWRITE(a); SWRITE(" generic items."); 
      BLINES(0); 
(*9*) END GenericSummary;


PROCEDURE ListVars;
(*Write out all variables with their current binding. *)
VAR   X, V, W, Y: LIST;
BEGIN
(*1*) (*initialize. *) X:=ENV; BLINES(0); 
(*2*) (*loop on alist. *) 
      WHILE X <> SIL DO ADV2(X,V,W,X); 
            Y:=LIST3(SETQ,V,W); MWRITE(Y);   
            END;
(*9*) END ListVars;


PROCEDURE ProcMod(t: LIST);
(*Procedure to Module Information. t = (M,P) is a list 
where M is a character string which indicates the module name 
and P is a list of procedure names in this module.  
For each procedure, the module name is stored under the ModName 
indicator in the symbol table. *)
VAR   M, p, P: LIST;
BEGIN
(*1*) IF t = SIL THEN RETURN END; 
      FIRST2(t, M, P); 
      IF P <> SIL THEN IF FIRST(P) = listi THEN P:=RED(P) END END;
      SWRITE("P ="); 
      WHILE P <> SIL DO ADV(P, p,P); 
            SWRITE(" "); UWRIT1(p); 
            PUT(p,modname,M);
            END; 
      BLINES(1); 
(*9*) END ProcMod;


PROCEDURE HELP();
(*Help processor compatibility interface. *)
BEGIN
(*1*) Help(SIL); 
(*9*) END HELP;


PROCEDURE Help(t: LIST);
(*Help processor. t is the topic for which help is requested. *)
VAR   f: LIST;
BEGIN
(*1*) (*check topic.*) 
      IF t <= SIL THEN 
         SWRITE("Enter 'help(name[,mod])' or 'help(start,end[,mod])'"); 
         SWRITE(" to get more help."); BLINES(0); 
         SWRITE("'Name' means the first characters of a range of names,");
         BLINES(0);
         SWRITE(" 'start,end' means a range of names."); BLINES(0); 
         SWRITE("'[,mod]' is optional and 'mod' can be "); BLINES(0); 
         SWRITE("'ModulName' = list module names of the procedures,"); 
         BLINES(0);
         SWRITE("'all' = list all loaded procedures, "); 
         BLINES(0);
         SWRITE("'Loaded' = list loaded procedures, "); 
         BLINES(0);
         SWRITE("'Comment' = list procedure comments "); 
         SWRITE("(default)."); 
         BLINES(1); RETURN END; 
      f:=t; 
      IF SYMBOL(t) THEN f:=LIST1(t) END; 
(*2*) (*module name*) 
      IF MEMBER(modname,f) = 1 THEN ModSummary(f); RETURN END;
(*3*) (*procedure summary*) 
      IF MEMBER(alls,f) = 1 THEN ProcSummary(f); RETURN; END;
      IF MEMBER(loaded,f) = 1 THEN ProcSummary(f); RETURN END; 
(*4*) (*comment*) (*default*) 
      ComSummary(f);
(*9*) END Help;


PROCEDURE ModSummary(F: LIST); 
(*Module summary. F is a filter expression. 
Write out module names for all functions from symbol table SYMTB, 
which meet the filter expression. *)
VAR   X, V, W: LIST;
BEGIN
(*1*) (*initialize. *) 
      SWRITE("Module Names: "); BLINES(1); 
      X:=STLST(SYMTB); X:=Filter(X,F); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); 
            W:=GET(V,modname); 
            IF W <> SIL THEN 
               UWRIT1(V); SWRITE(" is in: "); CLOUT(RED(W)); 
               SWRITE(". "); BLINES(0);
               END;
            END; 
      BLINES(1); 
(*9*) END ModSummary;


PROCEDURE ComSummary(F: LIST); 
(*Comment summary. F is a filter expression. 
Write out comments for all functions from symbol table SYMTB, 
which meet the filter expression. *)
VAR   X, V, W, awk, awk1, sys, n, m: LIST;
BEGIN
(*1*) (*initialize. *) 
      SWRITE("Comments: "); BLINES(1); 
      X:=STLST(SYMTB); X:=Filter(X,F); 
      awk1:=LISTS('awk "/RE ');  
      awk:=LISTS('/{pf=1} {if (pf==1) print} /\*\)/{pf=0}" '); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); 
            W:=GET(V,modname); 
            IF W <> SIL THEN n:=EXPLOD(V); m:=RED(W); 
               sys:=CCONC(m,LISTS(" ")); 
               sys:=CCONC(LISTS("help/"),sys); 
               sys:=CCONC(awk,sys); 
               sys:=CCONC(n,sys); 
               sys:=CCONC(awk1,sys); 
               (* CLOUT(sys); *) BLINES(1); 
               W:=DOS(sys); 
               END;
            END; 
(*9*) END ComSummary;


PROCEDURE Filter(L, f: LIST): LIST;
(*Filter a list of symbols. L is a list of symbols. 
f is a filtering expression. A sublist of L is returned. *)
VAR   LP, l, h, s: LIST;
BEGIN
(*1*) (*determine expression.*) IF f <= SIL THEN RETURN(L) END; 
      IF SYMBOL(f) THEN f:=LIST1(f) END; 
      ADV(f,l,f); IF l = alls THEN RETURN(L) END; 
      IF f = SIL THEN h:=EXPLOD(l); h:=CONC(h,LISTS("ZZZZZ"));
                      h:=ENTER(h); 
                 ELSE h:=FIRST(f); 
                      IF h = modname THEN h:=EXPLOD(l); 
                         h:=CONC(h,LISTS("ZZZZZ")); h:=ENTER(h); END;
                      IF h = comment THEN h:=EXPLOD(l); 
                         h:=CONC(h,LISTS("ZZZZZ")); h:=ENTER(h); END;
                      IF h = alls THEN h:=EXPLOD(l); 
                         h:=CONC(h,LISTS("ZZZZZ")); h:=ENTER(h); END;
                      IF h = loaded THEN h:=EXPLOD(l); 
                         h:=CONC(h,LISTS("ZZZZZ")); h:=ENTER(h); END;
                      END; 
(*2*) (*scan list*) LP:=SIL; 
      WHILE L <> SIL DO ADV(L, s,L);
            IF (ACOMP(l,s) <= 0) AND (ACOMP(s,h) <= 0) THEN
               LP:=COMP(s,LP); END; 
            END;
      LP:=INV(LP); RETURN(LP);  
(*9*) END Filter;


PROCEDURE ProcSummary(F: LIST); 
(*Procedure and function summary. F is a filter expression. 
Write out all functions with their signature from symbol 
table SYMTB and ENV, which meet the filter expression. *)
VAR   X, V, W, k, i, o, p, WP, s, f, t, Y: LIST;
      cp, cf, cs, ce: LIST;
BEGIN
(*1*) (*initialize. *) cp:=0; cf:=0; cs:=0; ce:=0;
      SWRITE("List of functions and procedures: "); BLINES(1); 
      X:=STLST(SYMTB); X:=Filter(X,F); 
(*2*) (*loop on symbol list. *) 
      WHILE X <> SIL DO ADV(X,V,X); 
(*2.1*)     (*Signatures . *) WP:=SIL;
            W:=GET(V,ARROW); 
            IF W <> SIL THEN cs:=cs+1;
               FIRST3(W, s,f,t); 
               SWRITE("SIGNATURE "); SYWRIT(f); 
               IF RED(t) = SIL THEN t:=FIRST(t) END; (*single value*)
               UWRIT1(s); 
               IF t <> SIL THEN SWRITE(": "); UWRIT1(t) END; 
               SWRITE(" "); BLINES(0); 
               END;
(*2.2*)     (*Interpreter procedures. *) WP:=SIL;
            W:=ASSOC(V,ENV); IF W <> SIL THEN W:=FIRST(W) END;
            IF W > SIL THEN ADV(W,WP,W) END;
            (* (xlamda parms body) *)    
            IF WP = LAMBDA THEN ce:=ce+1;
               SWRITE("PROCEDURE "); SYWRIT(V);
               Y:=FIRST(W); FIRST2(Y,i,o); SWRITE("("); 
               WHILE i <> SIL DO ADV(i,p,i); SYWRIT(p); 
                     IF i <> SIL THEN SWRITE(", ") END;
                     END;
               IF o <> SIL THEN SWRITE("; VAR ") END;
               WHILE o <> SIL DO ADV(o,p,o); SYWRIT(p); 
                     IF o <> SIL THEN SWRITE(", ") END;
                     END;
               SWRITE(")"); BLINES(0); END;
            IF WP = FLAMBDA THEN ce:=ce+1;
               SWRITE("FPROCEDURE "); SYWRIT(V);
               Y:=FIRST(W); SWRITE("("); 
               WHILE Y <> SIL DO ADV(Y,p,Y); SYWRIT(p); 
                     IF Y <> SIL THEN SWRITE(", ") END;
                     END;
               SWRITE(")"); BLINES(0); END;
            IF WP = MLAMBDA THEN ce:=ce+1;
               SWRITE("MACRO "); SYWRIT(V);
               Y:=FIRST(W); SWRITE("("); 
               WHILE Y <> SIL DO ADV(Y,p,Y); SYWRIT(p); 
                     IF Y <> SIL THEN SWRITE(", ") END;
                     END;
               SWRITE(")"); BLINES(0); END;
            IF WP = GLAMBDA THEN ce:=ce+1;
               SWRITE("GENERIC   "); SYWRIT(V);
               SWRITE(" "); BLINES(0); END;
(*2.3*)     (*Compiled procedures. *)
            W:=GET(V,ARITY);
            IF W <> SIL THEN    
               FIRST3(W, k,i,o); 
               IF k = PIND THEN cp:=cp+1; 
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
               ELSIF k = FIND THEN cf:=cf+1;
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
      GWRITE(cs); SWRITE(" signatures, "); BLINES(0); 
      GWRITE(ce); SWRITE(" interpreter procedures, "); BLINES(0); 
      GWRITE(cf); SWRITE(" compiled functions, "); BLINES(0); 
      GWRITE(cp); SWRITE(" compiled procedures "); BLINES(0);
      SWRITE("accessible."); BLINES(1); 
(*9*) END ProcSummary;


(*Pretty printer component. *)

PROCEDURE MWRITE(Y: LIST);
(*Output in modula like syntax. *)
BEGIN 
(*1*) IF ELEMP(Y) THEN UWRITE(Y)
         ELSE MWRIT1(Y,TRUE); SWRITE(". ") END; 
      BLINES(0);
(*9*) END MWRITE;

                       
PROCEDURE MWRIT1(Y: LIST; top: BOOLEAN);
(*Output in modula like syntax. *)
VAR   N, YP, A, B, C, D, F: LIST;
      parm: BOOLEAN;
BEGIN
(*1*) (*primitive. *) IF ELEMP(Y) THEN UWRIT1(Y); RETURN END; 
(*2*) (*symbol. *) IF SYMBOL(Y) THEN SYWRIT(Y); RETURN END; 
(*3*) (*function or special. *) YP:=Y; parm:=FALSE;
      IF SYMBOL(FIRST(Y)) THEN ADV(Y, N, YP); 
            IF N = TINFO  THEN A:=LIST2(WRITE,Y); SWRITE('"');
                               B:=EVALUATE(A,ENV); SWRITE('"');
         ELSIF N = SETQ   THEN FIRST2(YP, A, B); C:=SIL;
                               IF B > SIL THEN C:=FIRST(B) END;
                               IF C = LAMBDA 
                                  THEN SWRITE("PROCEDURE ");
                                       MWRIT1(A,FALSE); MWRIT1(B,FALSE);
                                       SWRITE(" "); MWRIT1(A,FALSE); 
                                  ELSE MWRIT1(A,FALSE); 
                                       SWRITE(":="); MWRIT1(B,FALSE);
                                       END; 
         ELSIF N = ASSIGN THEN FIRST2(YP, A, B); MWRIT1(A,FALSE); 
                               SWRITE(":="); MWRIT1(B,FALSE); 
         ELSIF N = ADD    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE("+"); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = SUB    THEN ADV(YP, B,YP); SWRITE("(");
                               IF YP <> SIL THEN A:=FIRST(YP); 
                                  MWRIT1(B,FALSE); B:=A END; 
                               SWRITE("-"); MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = MUL    THEN FIRST2(YP, A, B); MWRIT1(A,FALSE); 
                               SWRITE("*"); MWRIT1(B,FALSE);
         ELSIF N = POW    THEN FIRST2(YP, A, B); MWRIT1(A,FALSE); 
                               SWRITE("^"); MWRIT1(B,FALSE);
         ELSIF N = QUOT   THEN FIRST2(YP, A, B); MWRIT1(A,FALSE); 
                               SWRITE("/"); MWRIT1(B,FALSE);
         ELSIF N = REM    THEN FIRST2(YP, A, B); MWRIT1(A,FALSE); 
                               SWRITE("%"); MWRIT1(B,FALSE);
         ELSIF N = EQS    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" = "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = NEQS   THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" <> "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = LEQ    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" <= "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = LTS    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" < "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = GEQ    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" >= "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = GTS    THEN FIRST2(YP, A, B); SWRITE("("); 
                               MWRIT1(A,FALSE); SWRITE(" > "); 
                               MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = UND    THEN FIRST2(YP, A, B); 
                               SWRITE("("); MWRIT1(A,FALSE);
                               SWRITE(" AND "); MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = ODER   THEN FIRST2(YP, A, B); 
                               SWRITE("("); MWRIT1(A,FALSE);
                               SWRITE(" OR "); MWRIT1(B,FALSE); SWRITE(")");
         ELSIF N = NOTS   THEN A:=FIRST(YP); 
                               SWRITE(" NOT "); MWRIT1(A,FALSE); SWRITE(")");
         ELSIF N = STRNG  THEN SWRITE('"'); CLOUT(YP); SWRITE('"');
         ELSIF N = IFS    THEN ADV2(YP, A, B,YP); BLINES(0); 
                               SWRITE("IF "); MWRIT1(A,FALSE);
                               SWRITE(" THEN "); MWRIT1(B,FALSE);
                               IF YP <> SIL THEN B:=FIRST(YP); BLINES(0); 
                                  SWRITE("   ELSE "); MWRIT1(B,FALSE) END; 
                               SWRITE(" END");  
         ELSIF N = WHL    THEN ADV2(YP, A, B,YP); BLINES(0);  
                               SWRITE("WHILE "); MWRIT1(A,FALSE);
                               SWRITE(" DO "); MWRIT1(B,FALSE);
                               SWRITE(" END"); 
         ELSIF N = RPT    THEN ADV2(YP, A, B,YP); BLINES(0); 
                               SWRITE("REPEAT "); MWRIT1(A,FALSE);
                               SWRITE(" UNTIL "); MWRIT1(B,FALSE);
         ELSIF N = VARS   THEN ADV2(YP, A, B,YP); BLINES(0); 
                               SWRITE("VAR "); MWRIT3(A);
                               SWRITE(": "); MWRIT1(B,FALSE);
         ELSIF N = SORT   THEN BLINES(0); 
                               SWRITE("SORT "); MWRIT3(YP);
         ELSIF N = LAMBDA THEN ADV2(YP, A, B,YP); FIRST2(A,C,D); 
                               (*SWRITE("LAMBDA "); done on SETQ*) 
                               SWRITE("("); MWRIT3(C); 
                               IF D <> SIL THEN SWRITE("; "); MWRIT3(D) END; 
                               SWRITE("); "); BLINES(0); MWRIT1(B,TRUE);
         ELSIF N = MLAMBDA THEN ADV2(YP, A, B,YP); 
                               SWRITE("MLAMBDA "); MWRIT2(A);
                               SWRITE("; "); BLINES(0); MWRIT1(B,TRUE);
         ELSIF N = FLAMBDA THEN ADV2(YP, A, B,YP); 
                               SWRITE("FLAMBDA "); MWRIT2(A);
                               SWRITE("; "); BLINES(0); MWRIT1(B,TRUE);
         ELSIF N = GLAMBDA THEN ADV(YP, A,YP); BLINES(0);
                               SWRITE("GLAMBDA "); MWRIT1(A,TRUE);
                               SWRITE(" "); FIRST3(YP,A,B,C);
                               SWRITE("MAPS "); MWRIT1(A,FALSE); 
                               BLINES(0);
                               SWRITE("PROCEDURE "); MWRIT1(B,FALSE); 
                               BLINES(0);
                               SWRITE("RULES "); MWRIT3(C); 
                               BLINES(0);
         ELSIF N = UNIT    THEN ADV2(YP, A, B, YP); BLINES(0);
                               SWRITE("UNIT "); MWRIT1(A,TRUE);
                               MWRIT2(B); SWRITE("; ");
                               WHILE YP <> SIL DO ADV(YP,B,YP);
                                     MWRIT1(B,FALSE); SWRITE("; "); 
                                     END;
                               SWRITE("END "); MWRIT1(A,FALSE);
                               SWRITE("; ");
         ELSIF N = DE     THEN FIRST3(YP, A,B,C); 
                               SWRITE("PROCEDURE "); 
                               IF SYMBOL(A) THEN SYWRIT(A);
                                  FIRST2(B,D,F); 
                                  SWRITE("("); MWRIT3(D); 
                                  IF F <> SIL THEN SWRITE("; "); 
                                     MWRIT3(F); END; 
                                  SWRITE("); "); BLINES(0);  
                                  MWRIT1(C,TRUE); 
                                  SWRITE(" "); SYWRIT(A);  
                                  END;
         ELSIF N = DF     THEN FIRST3(YP, A,B,C); 
                               SWRITE("FPROCEDURE "); 
                               IF SYMBOL(A) THEN SYWRIT(A);
                                  MWRIT2(B); SWRITE("; "); BLINES(0); 
                                  MWRIT1(C,TRUE); END;
         ELSIF N = DM     THEN FIRST3(YP, A,B,C); 
                               SWRITE("MPROCEDURE "); 
                               IF SYMBOL(A) THEN SYWRIT(A);
                                  MWRIT2(B); SWRITE("; "); BLINES(0); 
                                  MWRIT1(C,TRUE) END;
         ELSIF N = MAP    THEN ADV2(YP, A,B, YP); 
                               SWRITE("MAP "); UWRIT1(A); 
                               SWRITE(" -> "); FIRST2(B, A,B);
                               SYWRIT(A); MWRIT2(B);
                               IF YP <> SIL THEN FIRST2(FIRST(YP), A,B);
                                  SWRITE(" WHEN "); 
                                  SYWRIT(A); MWRIT2(B); END;
         ELSIF N = SIG    THEN ADV3(YP, A, B, C, YP); 
                               SWRITE("SIGNATURE "); SYWRIT(A);
                               SWRITE(" "); UWRIT1(B); 
                               IF C <> SIL THEN SWRITE(": "); UWRIT1(C) END; 
         ELSIF N = RULE   THEN ADV2(YP, A, B,YP); 
                               SWRITE("RULE "); MWRIT1(A,FALSE);
                               SWRITE(" => "); MWRIT1(B,FALSE); 
                               IF YP <> SIL THEN A:=FIRST(YP);
                                  SWRITE(" WHEN "); MWRIT1(A,FALSE); END;
         ELSIF N = REP    THEN SWRITE("REP <...>");
         ELSIF N = NOSHOW THEN SWRITE("NOSHOW(...)");
         ELSIF N = PROGN  THEN IF top THEN BLINES(0); SWRITE("BEGIN "); END;
                               WHILE YP <> SIL DO ADV(YP,A,YP);
                                     MWRIT1(A,FALSE);
                                     IF YP <> SIL THEN SWRITE("; ") END;
                                     END;
                               IF top THEN SWRITE(" END") END;
         ELSE  (*function*) SYWRIT(N); parm:=TRUE; 
               END;  
         IF NOT parm THEN RETURN END; 
         END; 
(*4*) (*list. *) MWRIT2(YP);  
(*9*) END MWRIT1;

                       
PROCEDURE MWRIT2(Y: LIST);
(*List output with ( and ) in modula like syntax. *)
BEGIN
(*1*) (*list. *) SWRITE("("); MWRIT3(Y); SWRITE(")");
(*9*) END MWRIT2;

                       
PROCEDURE MWRIT3(Y: LIST);
(*List output in modula like syntax. *)
VAR   YP, A: LIST;
BEGIN
(*1*) (*list. *) YP:=Y; 
      WHILE YP <> SIL DO ADV(YP,A,YP);
            MWRIT1(A,FALSE);
            IF YP <> SIL THEN SWRITE(", ") END;
            END;
(*9*) END MWRIT3;


(*Pragma component. *)

PROCEDURE Pragma(a: LIST);
(*Pragma. Define Pragma a. *)
BEGIN 
(*1*)    IF a = M2S  THEN Parser:=mas
      ELSIF a = LSP  THEN Parser:=lisp
      ELSIF a = ALD  THEN Parser:=aldes
      ELSIF a = TME  THEN Time  := NOT Time
      ELSIF a = DBG  THEN Debug := NOT Debug
      ELSIF a = TRC  THEN trace := NOT trace
      ELSIF a = FUS  THEN stricttyping := TRUE
      ELSIF a = SLO  THEN stricttyping := FALSE
      ELSIF a = GENP THEN genparsing := NOT genparsing; 
                          SwitchParse(genparsing);
      ELSIF a = SHOW THEN 
(*2*)       SWRITE("Actual Pragmas: "); 
            IF Time THEN SWRITE("TIME, ") 
                    ELSE SWRITE("NO TIME, "); END;
            IF trace THEN SWRITE("TRACE, ") 
                     ELSE SWRITE("NO TRACE, "); END;
            IF Debug THEN SWRITE("DEBUG, ") 
                     ELSE SWRITE("NO DEBUG, "); END;
            IF stricttyping THEN SWRITE("FUSSY, ") 
                            ELSE SWRITE("SLOPPY, "); END;
            IF genparsing THEN SWRITE("GENPARSE, ") 
                          ELSE SWRITE("NO GENPARSE, "); END;
            SWRITE("Parser: ");
            CASE Parser OF 
                   mas: SWRITE("MODULA");   |
                  lisp: SWRITE("LISP");  |
                 aldes: SWRITE("ALDES"); |
                   ELSE SWRITE("none");  END;
            SWRITE("."); 
(*3*)  ELSE SWRITE("Invalid Pragma: "); UWRITE(a);
            SWRITE("Possible Pragmas: SHOW, TIME, DEBUG, TRACE, ");
            SWRITE("SLOPPY, FUSSY, "); BLINES(0);
            SWRITE("MODULA, LISP, ALDES, GENPARSE.");
            END;
(*9*) END Pragma;


PROCEDURE DoParse(): LIST;
(*Do parse. Call specific Parser. *)
VAR   Y: LIST;
BEGIN 
(*1*) CASE Parser OF 
             mas: SWRITE("MAS: "); 
	          IF (OStreamKind()=termkind) THEN WroteChars:=5; END;
     	       	  PromptFirst:=TRUE; PromptType:=0;
		  Y:=Parse();  |
            lisp: SWRITE("LISP: "); 
	          IF (OStreamKind()=termkind) THEN WroteChars:=6; END;
     	       	  PromptFirst:=TRUE; PromptType:=1;
     	       	  Y:=UREAD(); |
           aldes: SWRITE("ALD: ");
	          IF (OStreamKind()=termkind) THEN WroteChars:=5; END;
     	       	  PromptFirst:=TRUE; PromptType:=2;
     	          Y:=Aparse(); Parser:=mas; |
             ELSE SWRITE("MAS: "); PromptType:=0;
	          IF (OStreamKind()=termkind) THEN WroteChars:=5; END;
     	       	  PromptFirst:=TRUE;
     	       	  Y:=Parse(); Parser:=mas;
                  END;
(*2*) IF Debug THEN SWRITE("Parse: "); UWRITE(Y) END; 
      RETURN(Y);
(*9*) END DoParse;


PROCEDURE DoWrite(Y: LIST);
(*Do Write. Write according to Parser. *)
BEGIN 
(*1*) CASE Parser OF 
             mas: SWRITE("ANS: "); MWRITE(Y); |
            lisp: SWRITE("ANS: "); UWRITE(Y); |
           aldes: SWRITE("ANS: "); MWRITE(Y); |
             ELSE SWRITE("ANS: "); UWRITE(Y);
                  END;
      BLINES(1); 
(*9*) END DoWrite;


PROCEDURE InitPragma;
(*Initialize pragmas. *)
BEGIN 
(*1*) Declare(M2S,"MODULA");
      Declare(LSP,"LISP");
      Declare(ALD,"ALDES");
      Declare(TME,"TIME");
      Declare(DBG,"DEBUG");
      Declare(TRC,"TRACE");
      Declare(FUS,"FUSSY");
      Declare(SLO,"SLOPPY");
      Declare(GENP,"GENPARSE");
      Declare(SHOW,"SHOW");
(*2*) Parser:=mas;
      Time:=FALSE;
      Debug:=FALSE;
      genparsing:=FALSE;
      trace:=FALSE;
      stricttyping:=FALSE;
(*3*) Compiledp1(Pragma,"PRAGMA");
(*9*) END InitPragma;


PROCEDURE siline(s,l,r: LIST);
(*Set input line. *)
BEGIN 
(*1*) SILINE(s, l, r); 
(*2*) SWRITE("Old input line size (size,left,right): ("); 
      GWRITE(s); SWRITE(", "); GWRITE(l); SWRITE(", "); 
      GWRITE(r); SWRITE(")."); 
      BLINES(0); 
(*9*) END siline;


PROCEDURE soline(s,l,r: LIST);
(*Set output line. *)
BEGIN 
(*1*) SOLINE(s, l, r); 
(*2*) SWRITE("Old output line size (size,left,right): ("); 
      GWRITE(s); SWRITE(", "); GWRITE(l); SWRITE(", "); 
      GWRITE(r); SWRITE(")."); 
      BLINES(0); 
(*9*) END soline;


(* Execution part. *)
BEGIN
     WroteChars:=0;
     PromptFirst:=FALSE;
     PromptType:=0;
END MASU.


(* -EOF- *)
