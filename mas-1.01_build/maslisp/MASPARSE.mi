(* ----------------------------------------------------------------------------
 * $Id: MASPARSE.mi,v 1.5 1995/11/05 08:57:07 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASPARSE.mi,v $
 * Revision 1.5  1995/11/05 08:57:07  kredel
 * List expressions and small letter key words.
 *
 * Revision 1.2  1994/10/06  12:00:01  kredel
 * Added support for parallel language constructs: CON, CONFOR, ATOMIC, semaphore
 *
 * Revision 1.1.1.1  1993/06/11  12:55:08  kredel
 * Initial Version 0.7 of MAS from University of Passau
 *
 * Revision 1.4  1992/10/15  16:27:50  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/02/16  17:54:29  pesch
 * CONST-deviniton moved again.
 *
 * Revision 1.2  1992/02/12  17:32:27  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:22  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASPARSE;

(* MAS Parser Implementation Module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT GAMMAINT;

FROM MASSTOR IMPORT BETA, SIL, LIST,
                    LENGTH, SRED, LISTVAR,
                    LIST1, ADV, FIRST, RED, COMP, INV;

FROM MASBIOS IMPORT DIBUFF, CREAD, CREADB, BKSP, LISTS, 
                    CWRITE, MASCHR, MASORD, BLINES, SWRITE;

FROM SACLIST IMPORT AWRITE, AREAD, LIST2, ADV2, FIRST2, ADV3,
                    CCONC, CINV, COMP2, LIST3, FIRST3, CLOUT;

FROM MASSYM2 IMPORT SYWRIT, SYMBOL, ENTER, SREAD, GET, PUT;

FROM MASSYM IMPORT ELEMP, MEMQ, UREAD, UWRITE, UWRIT1, NOSHOW;

FROM MASLISPU IMPORT EXTYP, Declare;
                    
FROM MASLISP IMPORT EQS, NEQS, GTS, LTS, GEQ, LEQ, NOTS, UND, ODER,   
                    ADD, SUB, MUL, QUOT, REM, POW,
                    QUOTE, SETQ, STRNG, LISTX, 
                    PROGN, VARS, IFS, WHL, RPT, DE, 
                    CONVVAL, CONVDES,
                    EXPOS, SPEC, SORT, SIG, IMPRT, IMPL, 
                    UNIT, MODEL, MAP, AXIOM, RULE, WHEN,
                    DEFAULT, ASSIGN, TINFO, ENV;

CONST rcsidi = "$Id: MASPARSE.mi,v 1.5 1995/11/05 08:57:07 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(*generic function names. *)

VAR SUM, DIF, PROD, Q, REMAIN, EXP: LIST;

(*parse names. *)
 
VAR sum, dif, prod, quot, remain, exp: LIST;


(* scanner/parser definitions. *)
TYPE Token    = ( null, not, and, or, times, div, mod, plus, minus, power, 
                  eql, neq, lss, leq, gtr, geq, 
                  when, equiv, arrow, tinfo, listex, 
                  comma, rparen, rbrace, rbrack, lparen, lbrace, lbrack,
                  until, else, then, do, to, 
                  becomes, string, number, colon, ident, semicolon,
                  end, if, repeat, while, begin, 
                  map, rule, sig, var, sort, import, procedure, 
                  expose, spec, model, impl, axiom, 
                  period, eof );
 
VAR tok: Token;      (*last token type read*)
    tokval: LIST;    (*last token read*)
    ch:   CHAR;      (*last character read*)
    ach:  LIST;      (*ALDES code of last character read*)
    KW:   LIST;      (*key word inicator*)
    noerr: BOOLEAN;  (*error during parsing*)
    blv: LIST;       (*block local variables. *)
    genpars: BOOLEAN; (*flag, if generic/non generic parsing. *)


(* Scanner and Parser. *) 

PROCEDURE SyntaxErr(n: GAMMAINT);
(*Report on syntax error with number n. *)
VAR   m: INTEGER; c: LIST;
BEGIN
(*1*) SWRITE("["); AWRITE(n); SWRITE("] ");
      m:=INTEGER(n); noerr:=FALSE;
(*2*) CASE m OF 
           1  : SWRITE("=") | 
           2  : SWRITE("identifier or , or ;") | 
           4  : SWRITE("identifier") | 
           5  : SWRITE("; or ,") | 
           6  : SWRITE("expression") | 
           7  : SWRITE(")") | 
           8  : SWRITE("factor") | 
           9  : SWRITE(".") | 
          10  : SWRITE("assignment") | 
          13  : SWRITE(":= or (") | 
          14  : SWRITE("statement") | 
          15  : SWRITE(":") | 
          16  : SWRITE("then") | 
          17  : SWRITE("; or end") | 
          18  : SWRITE("do") | 
          20  : SWRITE("relation") | 
          21  : SWRITE(", or )") |
          22  : SWRITE("->") |
          23  : SWRITE("( or ident") |
          24  : SWRITE("(") |
          25  : SWRITE("condition") |
          26  : SWRITE("number")  |
          27  : SWRITE(", or ) or ;") |
          28  : SWRITE(";") |
          29  : SWRITE("end or ;") |
          30  : SWRITE(", or ]") |
          31  : SWRITE("/") |
          32  : SWRITE("==") |
          33  : SWRITE("end or ; or begin") |
          34  : SWRITE(", or }") |
          35  : SWRITE("to") |
           ELSE SWRITE("don't know what is") 
                END;
      SWRITE(" expected ");
(*3*) BKSP; DIBUFF; c:=CREAD();  
(*9*) END SyntaxErr;


PROCEDURE SyntaxWrn(n: GAMMAINT);
(*Report warning on syntax error with number n. *)
VAR m: INTEGER;
BEGIN
(*1*) SWRITE("["); AWRITE(n); SWRITE("] ");
      m:=INTEGER(n); 
(*2*) CASE m OF 
           1  : SWRITE("identifier") | 
           2  : SWRITE("algorithm name")  
           ELSE SWRITE("don't know what is") 
                END;
      SWRITE(" expected ");   
(*9*) END SyntaxWrn;


PROCEDURE SyntaxTest(s: Token; n: GAMMAINT);
(*Test if curent token is expected. *)
VAR m: INTEGER;
BEGIN
(*1*) IF tok < s THEN SyntaxErr(n);
         REPEAT GetToken UNTIL tok >= s;
         END;
(*9*) END SyntaxTest;


PROCEDURE KeyWord(s: Token; VAR S: ARRAY OF CHAR);
(*Declare key word. *)
VAR X: LIST;
    P: GAMMAINT;
BEGIN
(*1*) (*intern. *) X:=ENTER(LISTS(S));
(*2*) (*key word property. *) P:=GAMMAINT(ORD(s));
      PUT(X,KW,P);
(*3*) END KeyWord;


PROCEDURE GetCh;
(*Get next character. *)
BEGIN
(*1*) ach:=CREAD();
      ch:=MASCHR(ach);
(*3*) (*3*) END GetCh;


PROCEDURE Comment;
(*Skip comment. Recursively nested comments are accepted. *)
VAR   lev: LIST;
BEGIN
(*1*) lev:=1; 
(*2*) REPEAT GetCh; 
             IF ch = '*' THEN GetCh;  
                IF ch = ')' THEN GetCh; lev:=lev-1 END;
                END;
             IF ch = '(' THEN GetCh;  
                IF ch = '*' THEN GetCh; lev:=lev+1 END;
                END;
             UNTIL lev = 0;
(*3*) END Comment;


PROCEDURE GetString(c: CHAR): LIST;
(*Get String. *)
VAR s: LIST;
BEGIN
(*1*) s:=SIL;
(*2*) LOOP GetCh;
           IF ch = c THEN GetCh;
              IF ch <> c THEN EXIT END;
              END;
           s:=COMP(ach,s);
           END;
      s:=INV(s);
      RETURN(s);
(*3*) END GetString;


PROCEDURE GetIdent(): LIST;
(*Get Identifier. *)
VAR s, p: LIST;
BEGIN
(*1*) BKSP; s:=SREAD();
(*2*) p:=GET(s,KW);
      IF p <> SIL 
         THEN tok:=VAL(Token,CARDINAL(p)) 
         ELSE p:=GET(s,EXTYP); 
              IF p = SIL THEN 
                 IF NOT MEMQ(s,blv) THEN blv:=COMP(s,blv) END;
                 END; 
              END;
      RETURN(s);
(*3*) END GetIdent;


PROCEDURE GetToken;
(*Get next token. *)
BEGIN
(*1*) WHILE ch = " " DO GetCh END;
      tokval:=SIL;
(*2*) CASE ch OF 
          '"'  : tok:=string;  
                 tokval:=GetString('"') |
          "'"  : tok:=string;  
                 tokval:=GetString("'") |
          "#"  : tok:=neq; GetCh |
          "("  : GetCh;
                 IF ch = "*" THEN Comment; GetToken;
                             ELSE tok:=lparen END |
          ")"  : tok:=rparen; GetCh |
          "["  : tok:=lbrack; GetCh |
          "]"  : tok:=rbrack; GetCh |
          "{"  : tok:=lbrace; GetCh |
          "}"  : tok:=rbrace; GetCh |
          "^"  : tok:=power; GetCh |
          "*"  : GetCh;
                 IF ch = "*" THEN GetCh; tok:=power;
                             ELSE tok:=times END |
          "+"  : tok:=plus; GetCh |
          ","  : tok:=comma; GetCh |
          "-"  : GetCh; 
                 IF ch = ">" THEN GetCh; tok:=arrow;
                             ELSE tok:=minus END |
          "."  : tok:=period; ch:='.' |
          "/"  : tok:=div; GetCh |
          "%"  : tok:=mod; GetCh |
     "0".."9"  : tok:=number; BKSP; 
                 tokval:=AREAD(); GetCh |
          ":"  : GetCh;
                 IF ch = "=" THEN GetCh; tok:=becomes;
                             ELSE tok:=colon END |
          ";"  : tok:=semicolon; GetCh |
          "<"  : GetCh;
                    IF ch = "=" THEN GetCh; tok:=leq;
                 ELSIF ch = ">" THEN GetCh; tok:=neq;
                                ELSE tok:=lss END |
          "="  : GetCh;
                    IF ch = "=" THEN GetCh; tok:=equiv;
                 ELSIF ch = ">" THEN GetCh; tok:=rule;
                                ELSE tok:=eql END |
          ">"  : GetCh;
                 IF ch = "=" THEN GetCh; tok:=geq;
                             ELSE tok:=gtr END |
     "A".."Z"  : tok:=ident;  
                 tokval:=GetIdent(); GetCh |
     "a".."z"  : tok:=ident;  
                 tokval:=GetIdent(); GetCh 
            ELSE tok:=null; GetCh
                 END;
(*3*) END GetToken;


PROCEDURE PutToken;
(*Put current token. *)
BEGIN
(*1*) BLINES(0); SWRITE("Token: ");
(*2*) CASE tok OF 
          times  : SWRITE("times") |
          power  : SWRITE("power") |
          plus   : SWRITE("plus") |
          minus  : SWRITE("minus") |
          div    : SWRITE("div") |
          mod    : SWRITE("mod") |
      semicolon  : SWRITE("semicolon") |
          colon  : SWRITE("colon") |
          eof    : SWRITE("eof") |
          neq    : SWRITE("neq") |
          eql    : SWRITE("eql") |
          lss    : SWRITE("lss") |
          leq    : SWRITE("leq") |
          gtr    : SWRITE("gtr") |
          geq    : SWRITE("geq") |
          and    : SWRITE("and") |
          or     : SWRITE("or") |
          equiv  : SWRITE("equiv") |
          rule   : SWRITE("rule") |
          arrow  : SWRITE("arrow") |
          comma  : SWRITE("comma") |
        becomes  : SWRITE("becomes") |
          lparen : SWRITE("lparen") |
          rparen : SWRITE("rparen") |
          rbrack : SWRITE("rbrack") |
          lbrack : SWRITE("lbrack") |
          rbrace : SWRITE("rbrace") |
          lbrace : SWRITE("lbrace") |
          period : SWRITE("period") |
          do     : SWRITE("do") |
          if     : SWRITE("if") |
          end    : SWRITE("end") |
          not    : SWRITE("not") |
          var    : SWRITE("var") |
          expose : SWRITE("expose") |
          spec   : SWRITE("spec") |
          impl   : SWRITE("impl") |
          model  : SWRITE("model") |
          axiom  : SWRITE("axiom") |
          sig    : SWRITE("sig") |
          map    : SWRITE("map") |
          then   : SWRITE("then") |
          else   : SWRITE("else") |
          begin  : SWRITE("begin") |
          while  : SWRITE("while") |
          repeat : SWRITE("repeat") |
          until  : SWRITE("until") |
       procedure : SWRITE("procedure") |
          number : SWRITE("number "); AWRITE(tokval) |
          ident  : SWRITE("ident "); SYWRIT(tokval) | 
          string : SWRITE("string "); CLOUT(tokval) 
            ELSE SWRITE("null")
                 END;
      BLINES(0);
(*3*) END PutToken;


PROCEDURE Generate(s: Token; t: LIST): LIST;
(*Generate code for token s. *)
VAR code: LIST;
BEGIN
(*1*) CASE s OF 
       times  : code:=COMP(prod,t) |
       power  : code:=COMP(exp,t) |
       plus   : code:=COMP(sum,t) |
       minus  : code:=COMP(dif,t) |
       div    : code:=COMP(quot,t) |
       mod    : code:=COMP(remain,t) |
       neq    : code:=COMP(NEQS,t) |
       eql    : code:=COMP(EQS,t) |
       lss    : code:=COMP(LTS,t) |
       leq    : code:=COMP(LEQ,t) |
       gtr    : code:=COMP(GTS,t) |
       geq    : code:=COMP(GEQ,t) |
       and    : code:=COMP(UND,t) |
       or     : code:=COMP(ODER,t) |
       not    : code:=COMP(NOTS,t) |
       listex : code:=COMP(LISTX,t) |
     becomes  : code:=COMP(ASSIGN,t) |
       if     : code:=COMP(IFS,t) |
       var    : code:=COMP(VARS,t) |
       sort   : code:=COMP(SORT,t) |
       expose : code:=COMP(EXPOS,t) |
       tinfo  : code:=COMP2(LISTX,TINFO,t) |
       import : code:=COMP(IMPRT,t) |
       sig    : code:=COMP(SIG,t) |
       map    : code:=COMP(MAP,t) |
       rule   : code:=COMP(RULE,t) |
       begin  : IF t = SIL THEN code:=t
                   ELSIF RED(t) = SIL THEN code:=FIRST(t)
                   ELSE code:=COMP(PROGN,t) END |
       while  : code:=COMP(WHL,t) |
       repeat : code:=COMP(RPT,t) |
    procedure : code:=COMP(DE,t) |
       spec   : code:=COMP(SPEC,t) |
       model  : code:=COMP(MODEL,t) |
       impl   : code:=COMP(IMPL,t) |
       axiom  : code:=COMP(AXIOM,t) |
       string : code:=COMP(STRNG,t) 
         ELSE   code:=LIST2(QUOTE,t); 
                END;
      RETURN(code);
(*3*) END Generate;


PROCEDURE Parse(): LIST;
(*Parse program and generate code. *)
VAR s: LIST;
BEGIN
(*1*) noerr:=TRUE; ch:=" ";
(*2*) GetToken; s:=TopBlock(); 
      IF tok <> period THEN SyntaxErr(9) END;
      IF NOT noerr THEN s:=Generate(null,s) END; (*don't execute*)
      RETURN(s);
(*3*) END Parse;


PROCEDURE TopBlock(): LIST;
(*Parse top level block and generate code. *)
VAR   t, u, d: LIST;
BEGIN
(*1*) t:=SIL; 
(*2*) LOOP    IF tok = spec      THEN GetToken;
                                 u:=SpecDec(); t:=COMP(u,t) 
           ELSIF tok = impl      THEN GetToken;
                                 u:=ImplDec(); t:=COMP(u,t) 
           ELSIF tok = model     THEN GetToken;
                                 u:=ModDec(); t:=COMP(u,t) 
           ELSIF tok = axiom     THEN GetToken;
                                 u:=AxiomDec(); t:=COMP(u,t) 
           ELSIF tok = sort      THEN GetToken; u:=SortDec(); 
                                 t:=COMP(u,t); 
           ELSIF tok = var       THEN GetToken;
                                 u:=VarDec(); t:=COMP(u,t) 
           ELSIF tok = procedure THEN GetToken;
                                 u:=ProcDec(); t:=COMP(u,t) 
           ELSIF tok = expose    THEN GetToken;
                                 u:=ImportDec(expose); t:=COMP(u,t) 
            ELSE EXIT END; 
           IF tok = semicolon THEN GetToken 
                              ELSE EXIT END;
           END;
(*3*) u:=Statement(); IF u <> SIL THEN t:=COMP(u,t) END;
      t:=INV(t);
      t:=Generate(begin,t);
      RETURN(t);
(*5*) END TopBlock;


PROCEDURE Block(): LIST;
(*Parse inner block and generate code. *)
VAR   t, u, B, B1, B2, d: LIST;
BEGIN
(*1*) t:=SIL; B:=blv;
(*2*) LOOP    IF tok = var       THEN GetToken;
                                 u:=VarDec(); t:=COMP(u,t) 
           ELSIF tok = procedure THEN GetToken;
                                 u:=ProcDec(); t:=COMP(u,t) 
            ELSE EXIT END; 
           IF tok = semicolon THEN GetToken 
                              ELSE EXIT END;
           END;
(*3*) B1:=blv;
      u:=Statement(); IF u <> SIL THEN t:=COMP(u,t) END;
      t:=INV(t);
(*4*) (*analyse declarations. *) 
      B2:=blv;
      IF B2 <> B1 THEN 
         WHILE RED(B2) <> B1 DO B2:=RED(B2) END;
         SRED(B2,SIL); 
         SWRITE("Variable(s) declared: "); UWRITE(blv);
         d:=LIST2(blv,LISTX);
         d:=Generate(var,d); t:=COMP(d,t);
         END;
      blv:=B;     
      t:=Generate(begin,t);
      RETURN(t);
(*5*) END Block;


PROCEDURE SpecDec(): LIST;
(*Parse specification declaration and generate code. *)
VAR   s, u, n, B: LIST;
BEGIN
(*1*) B:=blv; s:=SIL; u:=SIL; n:=SIL;
(*2*) IF tok = ident THEN n:=tokval; s:=HeadDec(); 
                          u:=CINV(s); 
         ELSE SyntaxErr(4) END;
      IF tok = semicolon THEN GetToken; 
                         ELSE SyntaxErr(28) END;
(*3*) LOOP IF tok = sort THEN GetToken; s:=SortDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = sig THEN GetToken; s:=SigDec(); 
                             u:=COMP(s,u);
        ELSIF tok = import THEN GetToken; s:=ImportDec(import); 
                                u:=COMP(s,u);
        ELSIF tok = end THEN GetToken; EXIT 
        ELSIF tok = semicolon THEN GetToken;
         ELSE SyntaxErr(29); EXIT END;
           END;
(*5*) IF tok = ident THEN 
         IF tokval <> n THEN SyntaxWrn(2); END;
         GetToken;
         ELSE SyntaxWrn(1); END;
(*6*) (*blv:=B; need this to parse mod, impl and axiom *)
      u:=INV(u); u:=Generate(spec,u); 
      RETURN(u);
(*9*) END SpecDec;


PROCEDURE ImplDec(): LIST;
(*Parse implementation declaration and generate code. *)
VAR   s, u, n, B: LIST;
BEGIN
(*1*) B:=blv; s:=SIL; u:=SIL; n:=SIL;
(*2*) IF tok = ident THEN n:=tokval; s:=HeadDec(); 
                          u:=CINV(s); 
         ELSE SyntaxErr(4) END;
      IF tok = semicolon THEN GetToken; 
                         ELSE SyntaxErr(28) END;
(*3*) LOOP IF tok = var THEN GetToken; s:=VarDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = sort THEN GetToken; s:=SortDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = procedure THEN GetToken; s:=ProcDec(); 
                             u:=COMP(s,u);
        ELSIF tok = import THEN GetToken; s:=ImportDec(import); 
                                u:=COMP(s,u);
        ELSIF tok = begin THEN EXIT 
        ELSIF tok = end THEN EXIT 
        ELSIF tok = semicolon THEN GetToken;
         ELSE SyntaxErr(33); EXIT END;
           END;
      IF tok = end THEN GetToken 
         ELSIF tok = begin THEN s:=Statement(); u:=COMP(s,u); 
         ELSE SyntaxErr(33) END; 
(*4*) IF tok = ident THEN 
         IF tokval <> n THEN SyntaxWrn(2); END;
         GetToken;
         ELSE SyntaxWrn(1); END;
(*5*) blv:=B;
      u:=INV(u); u:=Generate(impl,u); 
      RETURN(u);
(*9*) END ImplDec;


PROCEDURE ModDec(): LIST;
(*Parse model declaration and generate code. *)
VAR   s, u, n, B: LIST;
BEGIN
(*1*) B:=blv; s:=SIL; u:=SIL; 
(*2*) IF tok = ident THEN n:=tokval; s:=HeadDec(); 
                          u:=CINV(s); 
         ELSE SyntaxErr(4) END;
      IF tok = semicolon THEN GetToken; 
                         ELSE SyntaxErr(28) END;
(*3*) LOOP IF tok = map THEN GetToken; s:=MapDec(); 
                             u:=COMP(s,u);
        ELSIF tok = sort THEN GetToken; s:=SortDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = import THEN GetToken; s:=ImportDec(import); 
                                u:=COMP(s,u);
        ELSIF tok = semicolon THEN GetToken   
        ELSIF tok = end THEN GetToken; EXIT   
         ELSE SyntaxErr(29); EXIT END;
           END;
(*4*) IF tok = ident THEN 
         IF tokval <> n THEN SyntaxWrn(2); END;
         GetToken;
         ELSE SyntaxWrn(1); END;
(*5*) blv:=B; 
      u:=INV(u); u:=Generate(model,u); 
      RETURN(u);
(*6*) END ModDec;


PROCEDURE AxiomDec(): LIST;
(*Parse axioms declaration and generate code. *)
VAR   s, u, n, B: LIST;
BEGIN
(*1*) B:=blv; s:=SIL; u:=SIL; n:=SIL;
(*2*) IF tok = ident THEN n:=tokval; s:=HeadDec(); 
                          u:=CINV(s); 
         ELSE SyntaxErr(4) END;
      IF tok = semicolon THEN GetToken; 
                         ELSE SyntaxErr(28) END;
(*3*) LOOP IF tok = rule   THEN GetToken; s:=RuleDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = sort THEN GetToken; s:=SortDec(); 
                              u:=COMP(s,u); 
        ELSIF tok = import THEN GetToken; s:=ImportDec(import); 
                                u:=COMP(s,u);
        ELSIF tok = end THEN GetToken; EXIT 
        ELSIF tok = semicolon THEN GetToken;
         ELSE SyntaxErr(29); EXIT END;
           END;
(*4*) IF tok = ident THEN 
         IF tokval <> n THEN SyntaxWrn(2); END;
         GetToken;
         ELSE SyntaxWrn(1); END;
(*5*) blv:=B; 
      u:=INV(u); u:=Generate(axiom,u); 
      RETURN(u);
(*9*) END AxiomDec;


PROCEDURE ImportDec(t: Token): LIST;
(*Parse import declaration and generate code. *)
VAR   s, u, e: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL; e:=SIL;  
      IF tok = ident THEN s:=HeadDec(); u:=COMP(s,u);  
         ELSE SyntaxErr(4) END;
(*3*) IF tok = lbrack THEN GetToken; s:=SIL;
         LOOP IF tok = ident THEN e:=tokval; GetToken;
                 IF tok = div THEN GetToken
                              ELSE SyntaxErr(31) END;
                 IF tok = ident THEN s:=COMP(tokval,s); s:=COMP(e,s);
                                     GetToken
                                ELSE SyntaxErr(4) END;
                 END; 
              IF tok = comma THEN GetToken
           ELSIF tok = rbrack THEN GetToken; EXIT
            ELSE SyntaxErr(30); EXIT END;
              END;
         s:=INV(s); u:=COMP(s,u); 
         END;
      u:=INV(u); u:=Generate(t,u); (*import or expose *) 
      RETURN(u);
(*3*) END ImportDec;


PROCEDURE MapDec(): LIST;
(*Parse generic map declaration and generate code. *)
VAR   s, u, t: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL; t:=SIL; 
(*2*) IF tok = ident THEN u:=HeadDec(); t:=COMP(u,t); 
                     ELSE SyntaxErr(4) END;
      IF tok = arrow THEN GetToken; 
                     ELSE SyntaxErr(22) END;
(*3*) IF tok = ident THEN s:=HeadDec(); t:=COMP(s,t);
                     ELSE SyntaxErr(4) END;
(*4*) IF tok = when THEN GetToken; 
         IF tok = ident THEN s:=HeadDec(); t:=COMP(s,t);
                        ELSE SyntaxErr(4) END;
         END;
(*5*) t:=INV(t); 
      t:=Generate(map,t); 
      RETURN(t);
(*6*) END MapDec;


PROCEDURE RuleDec(): LIST;
(*Parse rule declaration and generate code. *)
VAR   s, u, t: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL; 
(*2*) u:=Expression(); t:=LIST1(u);
      IF tok = rule THEN GetToken; 
                    ELSE SyntaxErr(32) END;
      s:=Expression(); t:=COMP(s,t);
(*3*) IF tok = when THEN GetToken; 
         s:=Condition(); t:=COMP(s,t) END;
(*4*) t:=INV(t);
      t:=Generate(rule,t); 
      RETURN(t);
(*5*) END RuleDec;


PROCEDURE VarDec(): LIST;
(*Parse variable declaration and generate code. *)
VAR s, u: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL;  
(*2*) (*list of identifiers. *)
      LOOP IF tok = ident THEN s:=COMP(tokval,s); GetToken
                           ELSE SyntaxErr(4) END;
           IF tok = comma THEN GetToken
              ELSIF tok = colon THEN EXIT  
              ELSIF tok = ident THEN SyntaxErr(5)
              ELSE SyntaxErr(15); EXIT END;
           END;
       s:=INV(s); u:=COMP(s,u); 
(*3*) (*type info. *)
      IF tok = colon THEN GetToken; 
         s:=TypeExpression(); u:=COMP(s,u);  
         END;
      u:=INV(u); u:=Generate(var,u); 
      RETURN(u);
(*4*) END VarDec;


PROCEDURE SortDec(): LIST;
(*Parse sort declaration and generate code. *)
VAR   s: LIST;
BEGIN
(*1*) s:=SIL;   
      LOOP IF tok = ident THEN s:=COMP(tokval,s); GetToken
                          ELSE SyntaxErr(4) END;
           IF tok = comma THEN GetToken
              ELSIF tok = semicolon THEN EXIT  
              ELSE SyntaxErr(2); EXIT END;
           END;
(*2*) s:=INV(s); s:=Generate(sort,s); 
      RETURN(s);
(*3*) END SortDec;


PROCEDURE SigDec(): LIST;
(*Parse signature declaration and generate code. *)
VAR s, u: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL;
(*2*) IF tok = ident THEN s:=COMP(tokval,s); GetToken
                     ELSE SyntaxErr(4) END;
(*4*) IF tok = lparen THEN GetToken; u:=IdentList(); 
                           IF tok = rparen THEN GetToken 
                              ELSE SyntaxErr(5) END;
                      ELSE SyntaxErr(23) END;
      s:=COMP(u,s); u:=SIL;
      IF tok = colon THEN GetToken;
         IF tok = ident THEN u:=LIST1(tokval); GetToken; 
                        ELSE SyntaxErr(23) END;
         END;
      s:=COMP(u,s); 
(*5*) s:=INV(s);
      s:=Generate(sig,s);
      RETURN(s);
(*6*) END SigDec;


PROCEDURE ProcDec(): LIST;
(*Parse procedure declaration and generate code. *)
VAR   t, s, u, a, up: LIST;
      ip: BOOLEAN;
BEGIN
(*1*) s:=SIL; u:=SIL; up:=SIL; a:=SIL; 
(*2*) IF tok = ident THEN a:=tokval; s:=COMP(a,s); GetToken
                     ELSE SyntaxErr(4) END;
(*3*) IF tok = lparen THEN GetToken;
         u:=IdentList(); 
         IF tok = semicolon THEN GetToken;
            IF tok = var THEN GetToken END;
            up:=IdentList(); END;
         IF tok = rparen THEN GetToken 
                         ELSE SyntaxErr(5) END;
         END;
      u:=LIST2(u,up);
      s:=COMP(u,s);
      IF tok = colon THEN GetToken;  
         IF tok = ident THEN t:=tokval; GetToken 
                             (* t is not used further *)
                        ELSE SyntaxErr(4) END
         END; 
      IF tok = semicolon THEN GetToken 
                         ELSE SyntaxErr(5) END; 
(*4*) u:=Block(); 
      s:=COMP(u,s); s:=INV(s); 
      s:=Generate(procedure,s);
      IF tok = ident THEN IF a <> tokval THEN SyntaxWrn(2) END; 
                          GetToken
                     ELSE SyntaxWrn(1) END;
      RETURN(s);
(*9*) END ProcDec;


PROCEDURE HeadDec(): LIST;
(*Parse header declaration and generate code. *)
VAR   s, u, a: LIST;
BEGIN
(*1*) s:=SIL; u:=SIL; a:=SIL; 
(*2*) IF tok = ident THEN a:=tokval; s:=COMP(a,s); GetToken
                     ELSE SyntaxErr(4) END;
(*3*) IF tok = lparen THEN GetToken;
         u:=IdentList(); 
         IF tok = rparen THEN GetToken 
                         ELSE SyntaxErr(24) END;
         END;
(*4*) s:=COMP(u,s); s:=INV(s); RETURN(s);
(*9*) END HeadDec;


PROCEDURE StatSeq(): LIST;
(*Parse statement sequence and generate code. *)
VAR s, t: LIST;
BEGIN
(*1*) t:=SIL;
      LOOP IF tok = semicolon THEN GetToken END;
           IF tok = end THEN GetToken; EXIT  
              ELSIF tok = else THEN EXIT 
              ELSIF tok = period THEN EXIT 
              ELSIF tok = until THEN GetToken; EXIT
                    END; 
           s:=Statement(); t:=COMP(s,t); 
           END; 
      IF t <> SIL THEN t:=INV(t); t:=Generate(begin,t) END;
      RETURN(t);
(*3*) END StatSeq;


PROCEDURE Statement(): LIST;
(*Parse statement and generate code. *)
VAR s, t, u: LIST;
BEGIN
(*1*) t:=SIL;
      SyntaxTest(ident,14);
(*2*) IF tok = ident THEN s:=tokval; GetToken; 
         IF tok = becomes THEN GetToken;
            u:=ListExpr(); 
            t:=LIST2(s,u); t:=Generate(becomes,t); 
            RETURN(t) 
         ELSIF tok = lparen THEN GetToken;  
            u:=ActParms(); 
            t:=COMP(s,u); (*=generate procedure call*)
            RETURN(t); 
            END;
         t:=LIST1(s); (*=generate procedure call*)
         RETURN(t); 
         END;
(*3*) IF tok = begin THEN GetToken; t:=StatSeq(); 
         RETURN(t);
         END;
(*4*) IF tok = if THEN GetToken; 
         s:=Condition(); t:=COMP(s,t);
         IF tok = then THEN GetToken;
                       ELSE SyntaxErr(16) END;
         s:=StatSeq(); t:=COMP(s,t);
         IF tok = else THEN GetToken;
            s:=StatSeq(); t:=COMP(s,t);
            END;
         t:=INV(t); t:=Generate(if,t);
         RETURN(t);
         END;
(*5*) IF tok = while THEN GetToken; 
         s:=Condition(); t:=COMP(s,t);
         IF tok = do THEN GetToken;
                     ELSE SyntaxErr(18) END;
         s:=StatSeq(); t:=COMP(s,t);
         t:=INV(t); t:=Generate(while,t);
         RETURN(t);
         END;
(*6*) IF tok = repeat THEN GetToken; 
         s:=StatSeq(); t:=COMP(s,t);
         s:=Condition(); t:=COMP(s,t);
         t:=INV(t); t:=Generate(repeat,t);
         RETURN(t);
         END;
(*7*) IF tok <> period THEN PutToken;  
         SyntaxTest(period,9) END;
      RETURN(t);
(*8*) END Statement;
 

PROCEDURE IdentList(): LIST;
(*Parse identifier list and generate code. *)
VAR s, u: LIST;
BEGIN 
(*1*) u:=SIL;
      IF (tok = rparen) OR (tok = semicolon) THEN RETURN(u) END;
(*2*) LOOP IF tok = ident THEN u:=COMP(tokval,u); GetToken
              ELSE SyntaxErr(4) END; 
           IF tok = comma THEN GetToken
              ELSIF (tok = rparen) OR (tok = semicolon) THEN EXIT
              ELSE SyntaxErr(27); EXIT END;
           END;
      u:=INV(u);
      RETURN(u);
(*3*) END IdentList;
 

PROCEDURE ActParms(): LIST;
(*Parse actual parameters and generate code. *)
VAR s, u: LIST;
BEGIN 
(*1*) u:=SIL;
(*2*) LOOP IF tok = rparen THEN GetToken; EXIT END;
           s:=ListExpr(); u:=COMP(s,u); 
           IF tok = comma THEN GetToken
              ELSIF tok = rparen THEN GetToken; EXIT
              ELSE SyntaxErr(21); EXIT END;
           END;
      u:=INV(u);
      RETURN(u);
(*3*) END ActParms;
 

PROCEDURE ListExpr(): LIST;
(*Parse list expression and generate code. *)
VAR s, u: LIST;
BEGIN 
(*1*) IF tok = lbrace THEN GetToken; 
         ELSE u:=Expression(); RETURN(u); END; 
      u:=SIL;
(*2*) LOOP IF tok = rbrace THEN GetToken; EXIT END;
           s:=Expression(); u:=COMP(s,u); 
           IF tok = comma THEN GetToken
              ELSIF tok = rbrace THEN GetToken; EXIT
              ELSE SyntaxErr(34); EXIT END;
           END;
      u:=INV(u); u:=Generate(listex,u); 
      RETURN(u);
(*3*) END ListExpr;


PROCEDURE Expression(): LIST;
(*Parse expression and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
(*1*) IF (plus <= tok) AND (tok <= minus) THEN
         oper:=tok; GetToken; s:=Term(); 
         IF oper = minus THEN s:=Generate(oper,LIST1(s)) END; 
         ELSE s:=Term(); 
         END;
(*2*) WHILE (plus <= tok) AND (tok <= minus) DO
            oper:=tok; GetToken; u:=Term(); 
            t:=LIST2(s,u); s:=Generate(oper,t); 
            END;
      RETURN(s);
(*3*) END Expression;


PROCEDURE Condition(): LIST;
(*Parse condition and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
(*1*) t:=SIL;
      IF tok = not THEN GetToken;
         t:=Condition(); t:=Generate(not,LIST1(t)) 
   ELSIF tok = lparen THEN GetToken;
         u:=Condition(); 
         IF tok = rparen THEN GetToken
                         ELSE SyntaxErr(7) END;
         IF (and <= tok) AND (tok <= or) THEN
            oper:=tok; GetToken; 
            IF tok = lparen THEN GetToken
                            ELSE SyntaxErr(24) END;
            s:=Condition();
            IF tok = rparen THEN GetToken
                            ELSE SyntaxErr(7) END;
            t:=LIST2(u,s); t:=Generate(oper,t)
            ELSE SyntaxErr(25) END
    ELSE u:=Expression(); 
         IF (eql <= tok) AND (tok <= geq) THEN
            oper:=tok; GetToken; s:=Expression();
            t:=LIST2(u,s); t:=Generate(oper,t)
            ELSE SyntaxErr(20) END; 
         END;
      RETURN(t);
(*3*) END Condition;


PROCEDURE Term(): LIST;
(*Parse term and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
(*1*) s:=Power();
      WHILE (times <= tok) AND (tok <= mod) DO
            oper:=tok; GetToken; u:=Power(); 
            t:=LIST2(s,u); s:=Generate(oper,t); 
            END;
      RETURN(s);
(*3*) END Term;


PROCEDURE Power(): LIST;
(*Parse power and generate code. *)
VAR   t, u, s: LIST;
BEGIN 
(*1*) t:=SIL; s:=1; t:=Factor();
      IF tok = power THEN GetToken;
         IF tok = minus THEN s:=-s; GetToken; END;
         IF tok = number THEN u:=tokval; GetToken;
            IF s < 0 THEN u:=-u END; 
            t:=LIST2(t,u); t:=Generate(power,t);
            ELSE SyntaxErr(26) END;
         END;
      RETURN(t);
(*3*) END Power;


PROCEDURE Factor(): LIST;
(*Parse factor and generate code. *)
VAR   s, t, u: LIST;
BEGIN 
(*1*) t:=SIL; 
      SyntaxTest(lparen,6);
      IF tok = ident THEN t:=tokval; GetToken; (*stands for itself*)
         IF tok = lparen THEN GetToken;
            u:=ActParms(); 
            t:=COMP(t,u); (*generate function call*)
            END;
         ELSIF tok = number THEN
               t:=tokval; GetToken; (*numbers stand for themselfs*)
         ELSIF tok = string THEN
               t:=tokval; t:=Generate(string,t); GetToken;
               IF tok = colon THEN GetToken; s:=TypeExpression();
                  t:=LIST3(CONVVAL,s,t); 
                  (*t:=LIST2(t,s); t:=Generate(tinfo,t);*)
                  END; 
         ELSIF tok = lparen THEN 
               GetToken; t:=Expression(); (*already code*)
               IF tok = rparen THEN GetToken ELSE SyntaxErr(7) END;
         ELSE SyntaxErr(8) END;
      RETURN(t);
(*3*) END Factor;


PROCEDURE TypeExpression(): LIST;
(*Parse type expression and generate code. *)
VAR   s, t, u: LIST;
BEGIN 
(*1*) t:=SIL; u:=SIL; s:=SIL;
      IF tok = ident THEN t:=tokval; GetToken; (*stands for itself*)
         IF tok = lparen THEN GetToken;
            u:=ActParms(); 
            t:=COMP(t,u); (*generate type term*)
            END;
         ELSE SyntaxErr(4) END;
      IF tok = string THEN s:=tokval; GetToken;
         s:=Generate(string,s); 
         s:=LIST3(CONVDES,t,s);
         END;
      t:=LIST3(LISTX,t,s);
      RETURN(t);
(*3*) END TypeExpression;


PROCEDURE InitScanner;
(*Initialize scanner procedures. *)
BEGIN
(*1*) Declare(KW,"KeyWord");
(*2*) (*Enter key words. *)
      KeyWord(do,"DO");
      KeyWord(to,"TO");
      KeyWord(if,"IF");
      KeyWord(end,"END");
      KeyWord(not,"NOT");
      KeyWord(and,"AND");
      KeyWord(or,"OR"); 
      KeyWord(var,"VAR");
      KeyWord(then,"THEN");
      KeyWord(else,"ELSE");
      KeyWord(begin,"BEGIN");
      KeyWord(sig,"SIGNATURE");
      KeyWord(while,"WHILE");
      KeyWord(until,"UNTIL");
      KeyWord(repeat,"REPEAT");
      KeyWord(procedure,"PROCEDURE");
      KeyWord(spec,"SPECIFICATION");
      KeyWord(model,"MODEL");
      KeyWord(import,"IMPORT");
      KeyWord(impl,"IMPLEMENTATION");
      KeyWord(axiom,"AXIOMS");
      KeyWord(map,"MAP");
      KeyWord(sort,"SORT");
      KeyWord(rule,"RULE");
      KeyWord(when,"WHEN");
      KeyWord(expose,"EXPOSE");
(*2*) (*Enter key words in lower case. *)
      KeyWord(do,"do");
      KeyWord(to,"to");
      KeyWord(if,"if");
      KeyWord(end,"end");
      KeyWord(not,"not");
      KeyWord(and,"and");
      KeyWord(or,"or"); 
      KeyWord(var,"var");
      KeyWord(then,"then");
      KeyWord(else,"else");
      KeyWord(begin,"begin");
      KeyWord(sig,"signature");
      KeyWord(while,"while");
      KeyWord(until,"until");
      KeyWord(repeat,"repeat");
      KeyWord(procedure,"procedure");
      KeyWord(spec,"specification");
      KeyWord(model,"model");
      KeyWord(import,"import");
      KeyWord(impl,"implementation");
      KeyWord(axiom,"axioms");
      KeyWord(map,"map");
      KeyWord(sort,"sort");
      KeyWord(rule,"rule");
      KeyWord(when,"when");
      KeyWord(expose,"expose");
(*9*) END InitScanner;


PROCEDURE InitParser;
(*Initialize parser and scanner procedures. *)
VAR   X, s, v: LIST;
BEGIN
(*1*) InitScanner; 
(*    Declare(CONVPARS,"CONVPARS"); (* access LISP convert. *)
      Declare(CONVDESC,"CONVDESC"); (* access LISP convert. *)
      Declare(REP,"REP");           (* representation tag. *)
*)
(*2*) Declare(SUM,"SUM");
      Declare(DIF,"DIF");
      Declare(PROD,"PROD");
      Declare(Q,"Q");
      Declare(REMAIN,"REMAIN");
      Declare(EXP,"EXP");
      SwitchParse(FALSE); 
(*3*) blv:=SIL; LISTVAR(blv); 
      X:=ENV; 
      WHILE X <> SIL DO ADV2(X,s,v,X);
            IF NOT MEMQ(s,blv) THEN blv:=COMP(s,blv) END;
            END;
(*9*) END InitParser;


PROCEDURE SwitchParse(g: BOOLEAN);
(*Switch parsing between generic / non-generic parse. 
If g = TRUE then the parser generates code for generic names, 
if g = FALSE then the parser generates code for the builtin LISP 
arithmetic functions. *)
BEGIN 
(*1*) (*to non-generic parsing. *)
      IF NOT g THEN genpars:=FALSE;
         sum:=ADD; dif:=SUB; prod:=MUL; quot:=QUOT; 
         remain:=REM; exp:=POW; 
         RETURN END; 
(*2*) (*to generic parsing. *)
      IF g THEN genpars:=TRUE;
         sum:=SUM; dif:=DIF; prod:=PROD; quot:=Q; 
         remain:=REMAIN; exp:=EXP; 
         RETURN END; 
(*9*) END SwitchParse;


(* Execution part. *)
BEGIN
 
InitParser;

END MASPARSE.



(* -EOF- *)
