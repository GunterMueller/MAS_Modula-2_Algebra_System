(* ----------------------------------------------------------------------------
 * $Id: ALDPARSE.mi,v 1.4 1992/10/15 16:27:45 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: ALDPARSE.mi,v $
 * Revision 1.4  1992/10/15  16:27:45  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/02/16  17:54:24  pesch
 * CONST-deviniton moved again.
 *
 * Revision 1.2  1992/02/12  17:32:19  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:15  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE ALDPARSE;

(* Aldes Parser Implementation Module. *)


(*************************************************************************)
(*                                                                       *)  
(* PROGRAMMIERPRAKTIKUM                                                  *)
(*                                                                       *)
(* Sommersemester 1990, Universitaet Passau.                             *)
(*                                                                       *)
(* von: Klaus Rieger                                                     *)
(*                                                                       *)
(*************************************************************************)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT BETA, SIL, LIST,
                    LENGTH, LISTVAR,
                    SRED, LIST1, ADV, FIRST, RED, COMP, INV;

FROM MASBIOS IMPORT DIBUFF, CREAD, CREADB, BKSP, LISTS, 
                    CWRITE, MASCHR, MASORD, BLINES, SWRITE;

FROM SACLIST IMPORT AWRITE, AREAD, LIST2, ADV2, FIRST2, 
                    CONC, LIST3, FIRST3, LIST4, LIST5, CLOUT;

FROM MASSYM2 IMPORT SYWRIT, SYMBOL, ENTER, SREAD, GET, PUT, GENSYM;

FROM MASSYM IMPORT ELEMP, MEMQ, UREAD, UWRITE, UWRIT1;

FROM MASLISPU IMPORT EXTYP, Compiledp0, Compiledp1, Declare;
                    
FROM MASLISP IMPORT EQS, NEQS, GTS, LTS, GEQ, LEQ, NOTS, UND, ODER,   
                    ADD, SUB, MUL, QUOT, REM, POW,
                    QUOTE, SETQ, STRNG, COND,  
                    PROGN, VARS, IFS, WHL, RPT, DE, DF, DM, DG,
                    PROGA, GTO, LBEL, ARY,
                    LAMBDA, MLAMBDA, FLAMBDA, GLAMBDA, SIG,
                    TDEF, DEFAULT, SETAV, TINFO, WRITE, WT,  
                    LISTX, ENV;

FROM MASSPEC IMPORT EVALUATE;

CONST rcsidi = "$Id: ALDPARSE.mi,v 1.4 1992/10/15 16:27:45 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

TYPE Token =  ( null, not, and, or, times, div, mod, plus, minus, power, 
                eql, neq, lss, leq, gtr, geq, sil,  
                comma, rparen, colon, lbrack, rbrack, rbrace, 
                becomes, then, else, to, To, of, do,
       (*expr*) lparen, dollar, quote, string, number, 
       (*stms*) ident, lbrace, label, procedure, return, 
                print, goto, go, if, case, semicolon,
                while, repeat, until, for, begald, begin,
       (*dcl*)  var, pragma, const, global, safe, array, intrinsic, 
       (*stp*)  period, end, eof);


VAR tok: Token;              (* last token type read *)
    tokval, zwischen: LIST;  (* last token read, intermediate token *)
    c, ch:   CHAR;           (* last character read *)
    ach:    LIST;            (* Aldes code of last character read*)
    KW:     LIST;            (* key word inicator *)
    noerr,isfunc:  BOOLEAN;  (* error during parsing, function found *)
    prnt, ret, any, prag: LIST; (* special ALDES symbols. *)
    blv: LIST;               (*block local variables. *)



PROCEDURE FIRST5(L: LIST; VAR AL1,AL2,AL3,AL4,AL5: LIST);
(* First 5.  L is a list of length 5 or more.  a1=FIRST(L),
   a2=SECOND(L), a3=THIRD(L) and a4=FOURTH(L) a5=FIFTH(L). *)
VAR  LP: LIST;
BEGIN
(*1*) ADV(L,AL1,LP); ADV(LP,AL2,LP); ADV(LP,AL3,LP);
      ADV(LP,AL4,LP); AL5:=FIRST(LP); RETURN;
(*2*) END FIRST5;


(**************************************************************************)
(*                                                                        *)
(*                        Error handling                                  *)
(*                                                                        *)
(**************************************************************************)     


PROCEDURE SyntaxWarning(n: LIST);
(* Report warning on syntax error with number n *)
VAR m: INTEGER;
BEGIN
  SWRITE("["); AWRITE(n); SWRITE("] ");
  m:=INTEGER(n); SWRITE("Syntax warning: ");
  CASE m OF
       2: SWRITE("intrinsic declaration") |
       3: SWRITE("pragma declaration") |
       6: SWRITE(". in header")|
       7: SWRITE("array as function") |
       8: SWRITE("global declaration in algorithm") |
       9: SWRITE("const declaration");
   ELSE SWRITE("???") END;
  SWRITE(" unsupported.");
  DIBUFF;
END SyntaxWarning;


PROCEDURE SyntaxError(n: LIST);
(* Report on syntax error with number n *)
VAR m: INTEGER;
BEGIN
  SWRITE("["); AWRITE(n); SWRITE("] ");
  m:=INTEGER(n); noerr:=FALSE;
  CASE m OF
         1: SWRITE("identifier") |
         2: SWRITE(")") |
         3: SWRITE("factor") |
         4: SWRITE("operator") (*unused*) |
         5: SWRITE(", or )") (*unused*) |
         6: SWRITE("variable") (*unused*) |
         7: SWRITE(", or ;") (*unused*) |
         8: SWRITE("declaration") |
         9: SWRITE("=") |
        10: SWRITE(", or .") |
        11: SWRITE("[") |
        12: SWRITE("]") |
        13: SWRITE("string") |
        14: SWRITE("number") |
        15: SWRITE("to") |
        16: SWRITE("then") |
        17: SWRITE("of") |
        18: SWRITE("{") |
        19: SWRITE("; or }") |
        20: SWRITE("do") |
        21: SWRITE(":=") (*unused*) |
        22: SWRITE(",...,") |
        23: SWRITE(", or ,...,") |
        24: SWRITE("(") |
        25: SWRITE("||") |
        26: SWRITE("statement") |
        27: SWRITE("}") |
        28: SWRITE("} or ;") (*unused*) |
        29: SWRITE("; or until") |
        30: SWRITE("and or or un-") |
        31: SWRITE("/ un-") |
        32: SWRITE("| un-") |
        33: SWRITE("= or :=") |
        34: SWRITE("expression") |
        35: SWRITE(", or identifier") |
        36: SWRITE("declaration or algorithm") |
        37: SWRITE(".") |
  ELSE SWRITE("don't know what is")
       END;
  SWRITE(" expected ");
  DIBUFF;
END SyntaxError;


PROCEDURE SyntaxTest(s: Token; n: LIST);
(*Test if curent token is expected. *)
VAR m: INTEGER;
BEGIN
(*1*) IF tok < s THEN SyntaxError(n);
         REPEAT GetTok UNTIL tok >= s;
         END;
(*9*) END SyntaxTest;


(**************************************************************************)
(*                                                                        *)
(*                             Scanner                                    *)
(*                                                                        *)
(**************************************************************************)


PROCEDURE KeyWord(s: Token; VAR S: ARRAY OF CHAR);
(* Declare key word *)
VAR   X, P: LIST;
BEGIN
  X:=ENTER(LISTS(S));
  P:=LIST(ORD(s));
  PUT(X,KW,P);
END KeyWord;   


PROCEDURE GetCh;
(* Get next character *)
BEGIN
  ach:=CREAD();
  ch:=MASCHR(ach);
END GetCh;


PROCEDURE GetString(): LIST;
(* Get String *)
VAR s: LIST;
BEGIN
  s:=SIL;
  LOOP GetCh;
       IF ch = '"' THEN GetCh;
          IF ch <> '"' THEN EXIT END;
          END;
       s:=COMP(ach,s);
       END;
  s:=INV(s);
  RETURN(s);
END GetString;


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

          
PROCEDURE Comment(): LIST;
(* Skip comment. Recursively nested comments are accepted *)
VAR   lev, L: LIST;
BEGIN L:=SIL;
  lev:=1; 
  REPEAT GetCh;  
         IF ch = ']' THEN GetCh; 
                          lev:=lev-1 END;
         IF ch = '[' THEN GetCh; 
                          lev:=lev+1 END;
         (* L:=COMP(ach,L); future extension *) 
  UNTIL lev = 0;
  (* L:=RED(L); L:=INV(L); future extension *)
  RETURN(L); 
END Comment;


PROCEDURE GetTok;
(* Get next token *)
BEGIN  
  WHILE ch = " " DO GetCh END;
  tokval:=SIL;
  CASE ch OF
         '"'  : tok:= string;
                tokval:= GetString() |
         "("  : GetCh; 
                IF ch = ")" THEN GetCh; tok:= sil
                            ELSE tok:= lparen
                                 END |
         ")"  : tok:= rparen; GetCh |
         "["  : IF tok # ident THEN tokval:=Comment(); GetTok; 
                   ELSE tok:= lbrack; GetCh END | 
         "]"  : tok:= rbrack; GetCh |
         "{"  : tok:= lbrace; GetCh |
         "}"  : tok:= rbrace; GetCh |
         "~"  : tok:= not; GetCh |
         "*"  : tok:= times; GetCh |
         "^"  : tok:= power; GetCh |
         "/"  : GetCh;
                IF ch = "\" THEN tok:= and; GetCh
                            ELSE tok:= div END |
         "\"  : GetCh;
                IF ch = "/" THEN tok:= or; GetCh; 
                            ELSE SyntaxError(31) END |
         "+"  : tok:= plus; GetCh |
         "-"  : tok:= minus; GetCh |
         "="  : tok:= eql; GetCh |
         "#"  : tok:= neq; GetCh |
         "<"  : GetCh;
                IF ch = "=" THEN GetCh; tok:= leq
                            ELSE tok:= lss END |
         ">"  : GetCh;
                IF ch = "=" THEN GetCh; tok:= geq
                            ELSE tok:= gtr END |
         ";"  : tok:= semicolon; GetCh |
         ","  : GetCh;
                IF ch = "." THEN GetCh;
                   IF ch = "." THEN GetCh;
                      IF ch = "." THEN GetCh;
                         IF ch = "," THEN GetCh; tok:= To END;
                         END; END
                   ELSE tok:= comma END |
         "'"  : tok:= quote; GetCh |
         "."  : tok:= period; GetCh |
         "$"  : tok:= dollar; GetCh |
         ":"  : GetCh;
                IF ch = "=" THEN GetCh; tok:= becomes
                            ELSE tok:=colon END |
      "0".."9": tok:= number; BKSP;
                tokval:= AREAD(); GetCh |
      "a".."z": tok:= ident;
                tokval:= GetIdent();
                GetCh |
      "A".."Z": tok:= ident;
                tokval:= GetIdent(); GetCh |
         "|"  : GetCh;
                IF ch = "|" THEN GetCh; tok:= end    
                            ELSE SyntaxError(32) END |
  ELSE tok:= null; GetCh
  END;
END GetTok; 


(**************************************************************************)
(*                                                                        *)
(*                             Parser                                     *)
(*                                                                        *)
(**************************************************************************)


PROCEDURE Aparse(): LIST;
(* Parse a set of ALDES-2 declarations and algorithms. *) 
VAR s: LIST;
BEGIN
  noerr:=TRUE; ch:=" ";
  GetTok;
  s:=Program();
  IF tok # end THEN SyntaxError(25) END;
  IF NOT noerr THEN s:= Generate(null,s) END;
  RETURN(s);
END Aparse; 


PROCEDURE Program(): LIST;
(* Parse "program" and generate code *)
VAR s,t: LIST;
BEGIN
  s:= SIL; t:= SIL;
  LOOP
         IF tok = end THEN EXIT 
      ELSIF (var <= tok) AND (tok <= intrinsic) THEN s:= Declaration(); 
                             t:= COMP(s,t); 
      ELSIF tok = ident THEN s:= Algorithm(); t:= COMP(s,t); 
       ELSE SyntaxTest(end,36) END;
      END;
  t:=INV(t);
  t:= Generate(begin,t);
  RETURN(t);
END Program;


PROCEDURE Algorithm(): LIST;
(* Parse Algorithm and generate code *)
VAR d, d1, s, s1, s2, t, t1, u, a, B, B1, B2, b: LIST;
    func:BOOLEAN;
BEGIN
(*1*) (*initialization. *)
      d:= SIL; t:= SIL; u:= SIL; s1:= SIL;
      isfunc:= FALSE;
      zwischen:= SIL;
      B:=blv;
(*2*) (* Header produces the two first arguments, which are needed
      by  Generate(procedure,t) *)
      t:= Header(func);
      IF func THEN FIRST2(t,zwischen,t1); 
                   isfunc:= TRUE; 
              ELSE t1:=t END;
(*3*) (*declarations. *)   
      WHILE (var <= tok) AND (tok <= intrinsic) DO 
            IF tok <= global THEN SyntaxWarning(8) END;
            d1:= Declaration(); 
            d:=COMP(d1,d);
            END; (* WHILE *)
      (* d= (VARn (...) any) ... (VAR1 (...) any) *)
      B1:=blv;
(*4*) (*labled statement sequences. *)
      a:=SIL;
      REPEAT s:=SIL; u:=SIL; (*get label*)
             IF tok = lparen THEN GetTok
                             ELSE SyntaxError(24) END;
             IF tok = number THEN u:= tokval; 
                                  GetTok
                             ELSE SyntaxError(14) END;
             IF tok = rparen THEN GetTok;
                                  u:= Generate(label,u); 
                             ELSE SyntaxError(2) END;
             IF u # SIL THEN a:= COMP(u,a) END; 
             LOOP (*get statements. *)
                  s1:= Statement();
                  s:= COMP(s1,s);  
                  IF tok = semicolon THEN GetTok;
                  ELSIF tok = period THEN GetTok; EXIT;
                  ELSIF tok = end THEN EXIT END;
                  END; 
             s:= INV(s);
             s:=Generate(begin,s); (* (PROGN ....)) *)
             IF s <> SIL THEN a:= COMP(s,a) END;
             UNTIL tok = end;
      a:= INV(a); (* a= ( (label u) (PROGN ....) ...) *)
      a:=Generate(begald,a); (* (PROGA ....)) *)
      d:=COMP(a,d);
(*5*) (*generate return. *)
      IF func THEN s1:= Generate(return,LIST1(zwischen));
                   d:= COMP(s1,d) END;
      d:= INV(d);
(*6*) (*analyse declarations. *) 
      B2:=blv;   
      IF B2 <> B1 THEN 
         WHILE RED(B2) <> B1 DO B2:=RED(B2) END;
         SRED(B2,SIL); b:=LIST2(blv,LISTX); (*trick*)
         b:=Generate(var,b); d:=COMP(b,d);
         SWRITE("Variable(s) declared: "); UWRITE(blv);
         END;
      blv:=B; 
      IF func THEN (*remove local variable from blv*)
         IF FIRST(blv) = zwischen THEN blv:=RED(blv) END;
         END;
(*7*) (*finalize. *)
      GetTok; (* || *) (*avoid reading next algorithm header until now*)
      d:= Generate(begin,d); 
      t:= COMP(d,t1); t:= INV(t);                
      b:=FIRST(t); (*add proc name to blv, since global*)
      IF NOT MEMQ(b,blv) THEN blv:=COMP(b,blv) END;
      t:= Generate(procedure,t);
      RETURN(t);
(*9*) END Algorithm; 


PROCEDURE Declaration(): LIST;
(* Parse declarations and generate code *)
VAR t: LIST;
BEGIN
  t:= SIL; 
  IF (tok = global) OR (tok = safe) THEN t:= GlobDec();
  ELSIF tok = intrinsic THEN t:= IntrinsicDec(); 
  ELSIF tok = const     THEN SyntaxWarning(9); 
                             t:= PrCoDec();
  ELSIF tok = pragma    THEN SyntaxWarning(3); 
                             t:= PrCoDec();
  ELSIF tok = array     THEN t:= ArrayDec();
                        ELSE SyntaxError(8) END; 
  IF tok = period THEN GetTok; 
                  ELSE SyntaxError(37) END; 
  RETURN(t);
END Declaration;


PROCEDURE Header(VAR func: BOOLEAN): LIST;
(* parse "algorithm - header" and generate code *)
VAR s,u,up,v,a: LIST;
    zwischen: LIST;
BEGIN
  s:= SIL; u:= SIL; up:= SIL; v:= SIL; a:= SIL;
  func:= FALSE;
  IF tok = ident 
     THEN a:= tokval; GetTok;
     IF tok = period THEN SyntaxWarning(6); 
                          GetTok; 
                          func:= FALSE;
                          s:= COMP(a,s)
  ELSIF tok = lparen THEN s:= COMP(a,s); 
                          GetTok;
                          u:= IdentifierList(); 
                          IF tok = semicolon THEN GetTok;  
                             up:= IdentifierList(); END;
                          IF tok = rparen THEN GetTok
                                          ELSE SyntaxError(2) END;
                          u:=LIST2(u,up);
                          s:= COMP(u,s);
                          func:= FALSE;
  ELSIF tok = sil THEN s:= COMP(a,s);
                       u:= LIST2(SIL,SIL); 
                       s:= COMP(u,s);
                       func:= FALSE;
                       GetTok      
  ELSIF tok = becomes THEN zwischen:=a;  
                           GetTok;
                           IF tok = ident THEN a:= tokval;
                                               s:= COMP(a,s);
                                               GetTok
                               ELSE SyntaxError(1) END;
                           IF tok = lparen THEN GetTok;
                                                u:= IdentifierList();
                                                u:=LIST2(u,up);
                                                s:= COMP(u,s)
                        ELSIF tok = sil THEN u:=LIST2(SIL,SIL);
                                             s:=COMP(u,s)
                              ELSE  SyntaxError(24) END;
                           IF (tok = rparen) OR (tok = sil)
                              THEN GetTok;
                                   func:= TRUE;
                              ELSE SyntaxError(2) END; 
                           s:= LIST2(zwischen,s); 
                           END      
   ELSE SyntaxError(1); END; (* IF *)
  RETURN(s);
END Header;


PROCEDURE Sequence(): LIST;
(* parse statement sequences and generate code *)
VAR s,t: LIST;
BEGIN
  s:= SIL; t:= SIL;
  IF tok # lbrace THEN t:= Statement() (* only one statement !! *)
     ELSE GetTok;
          LOOP s:= Statement(); 
               t:= COMP(s,t);
                  IF tok = semicolon THEN GetTok
               ELSIF tok = rbrace THEN GetTok; EXIT 
                ELSE SyntaxError(19); END;
               END;
          IF t # SIL THEN t:= INV(t); t:= Generate(begin,t) END;
     END;
  RETURN(t);
END Sequence;


PROCEDURE Statement(): LIST;
(* Parse Statement and generate code *)
VAR t: LIST;
BEGIN
  t:=SIL;
  SyntaxTest(ident,26);
  CASE tok OF
       print: t:=PrintStat(); |
       goto : t:=GotoStat(); |
       go   : t:=GoStat(); |
       if   : t:=IfStat(); |
       case : t:=CaseStat(); |                           
       while: t:=WhileStat(); |
      repeat: t:=RepeatStat(); |
         for: t:=ForStat(); |
      return: GetTok;
              IF isfunc THEN t:= Generate(return,LIST1(zwischen))
                        ELSE t:= Generate(return,SIL) END; |
      ident : t:=IdentStat(); 
         ELSE SyntaxTest(period,26) END; (* Case *)
  RETURN(t)      
END Statement;


PROCEDURE PrintStat(): LIST;
(* parse "print - staement" and generate code *)
VAR t: LIST;
BEGIN
  t:= SIL;
  GetTok;
  IF tok = string THEN t:= tokval;
                       GetTok;
                       t:=Generate(print,t) 
                  ELSE SyntaxError(13) END;
  RETURN(t)
END PrintStat;


PROCEDURE GotoStat(): LIST;
(* parse "goto - statement" and generate code *) 
VAR s,t: LIST;
BEGIN
  t:= SIL; GetTok;
  IF tok = lparen THEN GetTok;
     IF tok = number THEN s:= tokval; GetTok;
        IF tok = rparen THEN t:= Generate(goto,s); GetTok
                        ELSE SyntaxError(2) END
        ELSE SyntaxError(14) END
  ELSIF tok = number THEN s:= tokval;
                          t:= Generate(goto,s);
                          GetTok
        ELSE SyntaxError(14) END;
  RETURN(t);
END GotoStat;


PROCEDURE GoStat(): LIST;
(* parse "go to - statement" and generate code *)
VAR s,t: LIST;
BEGIN
  t:= SIL; GetTok;
  IF tok # to THEN SyntaxError(15)
     ELSE GetTok;
     IF tok = lparen THEN GetTok;
        IF tok = number THEN s:= tokval; GetTok;
           IF tok = rparen THEN t:= Generate(goto,s); GetTok
                           ELSE SyntaxError(2) END
           ELSE SyntaxError(14) END
     ELSIF tok = number THEN s:= tokval;
                             t:= Generate(goto,s);
                             GetTok
                        ELSE SyntaxError(14); END;
     END;
  RETURN(t);
END GoStat;


PROCEDURE IfStat(): LIST;
(* parse "if - statement" and generate code *)
VAR s,t: LIST;
BEGIN
  t:= SIL;
  GetTok;
  s:= CondSeq();
  t:= COMP(s,t);                
  IF tok = then THEN GetTok
                ELSE SyntaxError(16) END;
  s:= Sequence(); 
  t:= COMP(s,t);                 
  IF tok = else THEN GetTok;
                     s:= Sequence();
                     t:= COMP(s,t)   
  END;
  t:= INV(t);
  t:= Generate(if,t);
  RETURN(t)    
END IfStat;


PROCEDURE CaseStat(): LIST;
(* parse "case - statement and generate code *) 
VAR a,c,s,t,v: LIST;
BEGIN
  v:=SIL; t:=SIL; 
  GetTok;
  a:= Expression();
  IF tok = of THEN GetTok
              ELSE SyntaxError(17) END;
  IF tok = lbrace THEN GetTok
                   ELSE SyntaxError(18) END;
  REPEAT
     c:= TermList();    (*  (c1 c2 ... cn)  *)
     IF tok = do THEN GetTok
                 ELSE SyntaxError(20) END;
     s:= Sequence();
     IF tok = semicolon THEN GetTok 
     ELSIF tok # rbrace THEN SyntaxError(27) END;
          
     (* list preparation and call of procedure CaseLabel *)

     v:= SIL;
     v:= LIST3(a,c,s);
     v:= CaseLabel(v);
     t:= COMP(v,t)                
  UNTIL tok = rbrace;
  GetTok;       
  t:= INV(t);          
  t:= Generate(case,t);
  RETURN(t)  
END CaseStat;


PROCEDURE WhileStat(): LIST;
(* parse "while - statement" and generate code *)
VAR t,s: LIST;
BEGIN
  t:=SIL;
  GetTok;  
  s:= CondSeq();
  IF tok = do THEN GetTok
              ELSE SyntaxError(20) END;
  t:= Sequence(); 
  t:=LIST1(t);      
  t:= COMP(s,t);  
  t:= Generate(while,t);
  RETURN(t)
END WhileStat;


PROCEDURE RepeatStat(): LIST;
(* parse "repeat - statement" and generate code *)
VAR t,s: LIST;
BEGIN  
  t:=SIL;s:=SIL;
  GetTok;
  IF tok = lbrace THEN t:= Sequence(); (* PROGN (s1..sn) *) 
     IF tok = until THEN GetTok;
                         s:= CondSeq();
                         s:= LIST1(s); 
                         s:= COMP(t,s); (* PROG(s,..sn) Cond *)
                         t:= Generate(repeat,s);
                    ELSE 
         (* repeat - statement without until ----> Condition() = TRUE *)  
                         s:= WT; 
                         s:= LIST1(s);  
                         t:=COMP(t,s);
                         t:= Generate(repeat,t);
                         END (* IF *)
     ELSE (* tok # "{" *)
          LOOP s:= Statement(); 
               t:= COMP(s,t);
               IF tok = semicolon THEN GetTok 
               ELSIF tok = until THEN GetTok; EXIT 
                ELSE SyntaxError(29) END;  
               END;
          IF t # SIL THEN t:= INV(t) END;
          t:= Generate(begin,t);
          s:= CondSeq();
          s:= LIST1(s);   
          s:= COMP(t,s);
          t:= Generate(repeat,s);
          END; (* IF *)
 RETURN(t); 
END RepeatStat;


PROCEDURE ForStat(): LIST;
(* parse "for - statement" and generate code *) 
VAR i,s,t,t1,t2,t3,v: LIST;
BEGIN
  t:= SIL; s:= SIL;
  GetTok;
  IF tok = ident THEN i:= tokval; GetTok
                 ELSE SyntaxError(1) END;
     IF tok = eql THEN GetTok
  ELSIF tok = becomes THEN GetTok
   ELSE SyntaxError(33) END;
  t1:= Expression(); 
  IF tok = To THEN GetTok; 
                   t2:= SIL; 
                   t3:= Expression()
  ELSIF tok = comma THEN GetTok;
                         t2:= Expression();
                         IF tok = To THEN GetTok; 
                                          t3:= Expression()
                                     ELSE SyntaxError(22) END
        ELSE SyntaxError(23) END; (* IF *)
  IF tok = do THEN GetTok; s:=Sequence();
     ELSE SyntaxError(20) END;
  t:= LIST5(i,t1,t2,t3,s);
  t:= Generate(for,t);
  RETURN(t)
END ForStat;


PROCEDURE IdentStat(): LIST;
(* parse "identifier - statement" and generate code *)
VAR s,t,u,v: LIST;
BEGIN
(*1*) t:= SIL; u:=SIL; v:=SIL;
      s:= Variable();
(*2*) IF tok = becomes THEN GetTok; u:= Expression();
                       t:= LIST2(s,u); t:= Generate(becomes,t);
   ELSIF tok = sil THEN u:= SIL; 
         IF NOT SYMBOL(s) THEN SyntaxWarning(7) END;
         t:= COMP(s,u); GetTok;
   ELSIF tok = lparen THEN GetTok; u:= TermList(); 
                           IF tok = semicolon THEN GetTok;
                              v:=TermList();
                              IF tok = rparen THEN GetTok;
                                              ELSE SyntaxError(2) END;
                              ELSE
                              IF tok = rparen THEN GetTok;
                                              ELSE SyntaxError(2) END;
                              END; 
                           IF NOT SYMBOL(s) THEN SyntaxWarning(7) END;
                           t:= CONC(u,v); t:=COMP(s,t); (*call*)
    ELSE t:= LIST1(s); (*call*) END; 
      RETURN(t); 
(*3*) END IdentStat;


PROCEDURE GlobDec(): LIST;
(* parse global or safe declarations and generate code *)
VAR   s, t, u, v: LIST;
BEGIN
(*1*) s:= SIL; t:= SIL; 
      GetTok;
(*2*) LOOP s:=Variable();
           t:=COMP(s,t); 
              IF tok = comma THEN GetTok
           ELSIF tok = period THEN EXIT
            ELSE SyntaxError(8); EXIT END; (* IF *)
           END; 
(*3*) t:=INV(t); t:=LIST2(t,any); t:=Generate(var,t);
      RETURN(t);
(*9*) END GlobDec;


PROCEDURE IntrinsicDec(): LIST;
(* parse intrinsic declarations and generate code *)
VAR s,t: LIST;
BEGIN
(*1*) s:= SIL; t:= SIL; 
      SyntaxWarning(2);
      GetTok;
(*2*) s:=IdentifierList();
      IF tok # period THEN SyntaxError(8) END; 
(*3*) t:=LIST2(s,any);
      t:= Generate(var,t);
      RETURN(t);
(*9*) END IntrinsicDec;  


PROCEDURE PrCoDec(): LIST;
(* parse pragma or const declarations and generate code *)
VAR   s, t, u, x, y: LIST;
BEGIN
(*1*) GetTok; x:= SIL; y:= SIL;
(*2*) REPEAT u:= SIL; 
             s:=Variable(); x:=COMP(s,x);
             IF tok = eql THEN GetTok; u:= Expression()
                          ELSE SyntaxError(9) END;
             u:=LIST2(s,u); u:=Generate(becomes,u);
             y:=COMP(u,y);
             IF tok = comma THEN GetTok
             ELSIF tok # period THEN SyntaxError(10) END
             UNTIL tok = period;
(*3*) x:=INV(x); y:=INV(y);
      x:=LIST2(x,any); x:=Generate(var,x);
      y:=COMP(x,y);
      y:= Generate(begin,y);
      RETURN(y);
(*4*) END PrCoDec;


PROCEDURE ArrayDec(): LIST;
(* parse array declarations and generate code *)
VAR   s, t, u: LIST;
BEGIN
(*1*) s:= SIL; u:= SIL;
      GetTok;
(*2*) REPEAT
             IF tok = ident THEN s:= tokval; 
                                 GetTok; 
                            ELSE SyntaxError(1) END;
             IF tok = lbrack THEN GetTok
                             ELSE SyntaxError(11) END;
             t:=TermList(); 
             t:=LIST2(s,t); t:=Generate(array,t);
             u:=COMP(t,u);
             IF tok = rbrack THEN GetTok;
                             ELSE SyntaxError(12) END;
             IF tok = comma THEN GetTok
                ELSIF tok # period THEN SyntaxError(10) END;
             UNTIL tok = period; 
(*3*) u:= INV(u); u:=LIST2(u,any);
      t:= Generate(var,u);
      RETURN(t);
(*9*) END ArrayDec;


PROCEDURE CondSeq(): LIST;
(* parse codition sequences and generate code *)
VAR c,cl,t: LIST;
   oper: Token;
BEGIN
  t:= SIL;
  cl:= SIL;
  c:= Condition();
  cl:= COMP(c,cl);
  IF tok = and THEN oper:= tok;
                    GetTok;
                    REPEAT
                      c:= Condition();
                      cl:= COMP(c,cl);
                      IF tok = and THEN GetTok END;
                      IF tok = or THEN SyntaxError(30) END;
                    UNTIL (tok = then) OR (tok = until) OR (tok = do) 
                           OR (tok = period) OR (tok = end) OR (tok = rparen)
                           OR (tok = semicolon) OR (tok = rbrace) 
                           OR (tok = or);
                    IF cl # SIL THEN cl:= INV(cl) END;
                    t:= Generate(oper,cl);    
  ELSIF tok = or THEN oper:= tok;
                      GetTok;
                      REPEAT
                        c:= Condition();
                        cl:= COMP(c,cl);
                        IF tok = or THEN GetTok END;
                        IF tok = and THEN SyntaxError(30) END;
                      UNTIL (tok = then) OR (tok = until) OR (tok = do) 
                            OR (tok = period) OR (tok = end) OR (tok = rparen)
                            OR (tok = semicolon) OR (tok = rbrace) 
                            OR (tok = and);
                      IF cl # SIL THEN cl:= INV(cl) END;
                      t:= Generate(oper,cl);
  ELSE t:=c
  END;
  RETURN(t);
END CondSeq;


PROCEDURE Condition():LIST;
(* parse condition and generate code *)
VAR s,t,u: LIST;
    oper: Token;
BEGIN
  t:= SIL;
  IF tok = not THEN GetTok;
                    t:= Condition();
                    t:= Generate(not,LIST1(t))
  ELSIF tok = lparen THEN GetTok;
                          t:= CondSeq();
                          IF tok = rparen THEN GetTok
                                          ELSE SyntaxError(2)
                          END
  ELSE u:= Expression(); 
       IF (eql <= tok) AND (tok <= geq) THEN oper:= tok; GetTok;
                                             s:= Expression();
                                             t:= LIST2(u,s);
                                             t:= Generate(oper,t);
                                         ELSE SyntaxError(11) 
       END; 
  END; 
  RETURN(t);                 
END Condition;             
    

PROCEDURE IdentifierList(): LIST;
(* parse identifierlist; result is a inverted list *)
VAR s,t: LIST;
BEGIN
  s:=SIL;
  LOOP IF tok = ident THEN s:=COMP(tokval,s); GetTok
                      ELSE SyntaxError(1) END;
       IF tok = comma THEN GetTok  
       ELSIF tok = semicolon THEN EXIT;
       ELSIF tok = rparen THEN EXIT
       ELSIF tok = period THEN EXIT
       ELSE SyntaxError(35); EXIT 
            END;
       END;
  s:=INV(s);
  RETURN(s);
END IdentifierList;  


PROCEDURE TermList(): LIST;
(* parse termlist *)
VAR s,t: LIST;
BEGIN
  s:= SIL; t:= SIL;
  REPEAT
    s:= Expression(); 
    t:= COMP(s,t); 
    IF tok = comma THEN GetTok END;
  UNTIL (tok = do) OR (tok = semicolon) OR (tok = rparen) OR (tok = rbrack);
  t:= INV(t);
  RETURN(t);
END TermList;


PROCEDURE Expression(): LIST;
(* parse expressions and generate code *)
VAR s,t,u: LIST;
    oper: Token;
BEGIN
  s:= SIL; t:= SIL; u:= SIL;
  IF (plus <= tok) AND (tok <= minus) THEN oper:= tok;
     GetTok; s:= Term();
     IF oper = minus THEN s:= Generate(oper,LIST1(s)) END
  ELSE s:= Term() END; 
  WHILE (plus <= tok) AND (tok <= minus) DO
    oper:= tok; GetTok;
    u:= Term(); t:= LIST2(s,u);
    s:= Generate(oper,t);
  END; 
  RETURN(s);
END Expression;


PROCEDURE Term(): LIST;
(*Parse term and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
  s:=Factor();
  WHILE (times <= tok) AND (tok <= mod) DO
    oper:=tok; 
    GetTok; 
    u:=Factor(); 
    t:=LIST2(s,u); 
    s:=Generate(oper,t); 
  END;
  RETURN(s);
END Term;


PROCEDURE Factor(): LIST;
(*Parse factor and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
  s:=Potency();
  WHILE tok = power DO
    oper:=tok; 
    GetTok; 
    u:=Potency(); 
    t:=LIST2(s,u); 
    s:=Generate(oper,t); 
  END;
  RETURN(s);
END Factor;


PROCEDURE Potency(): LIST;
(*Parse potency and generate code. *)
VAR s, t, u: LIST;
    oper: Token;
BEGIN 
  t:=SIL; s:= SIL; u:= SIL;
  SyntaxTest(lparen,34);
  IF tok = ident THEN t:=tokval; GetTok;
                      IF tok = lparen THEN GetTok;
                                       u:= TermList();
                                       GetTok; 
                                       t:=COMP(t,u); 
                                       (* generate function call *)
                       ELSIF tok = sil THEN u:= SIL;
                                            GetTok;
                                            t:= COMP(t,LIST1(u))
                       ELSIF tok = lbrack THEN GetTok;
                                            s:= TermList();
                                            t:= LIST2(t,s);
                                            t:= Generate(array,t);
                                            IF tok = rbrack THEN GetTok
                                               ELSE SyntaxError(12);
                                            END
                        END;
  ELSIF tok = number THEN t:= tokval; 
                          GetTok
  ELSIF tok = string THEN t:=tokval; 
                          t:=Generate(string,t); 
                          GetTok; 
  ELSIF tok = lparen THEN GetTok; 
                          t:=Expression(); (*already code*)
                          IF tok = rparen THEN GetTok ELSE SyntaxError(2) END
  ELSIF tok = sil THEN t:= SIL; 
                       GetTok
  ELSE SyntaxError(3); GetTok END;
  RETURN(t);
END Potency;


PROCEDURE Variable(): LIST;
(* parse variable. identifier or array *)
VAR   s, t: LIST;
BEGIN
(*1*) t:= SIL; s:=SIL;
(*2*) IF tok = ident THEN s:= tokval; GetTok; 
                     ELSE SyntaxError(1) END;
(*3*) IF tok = lbrack THEN GetTok; t:= TermList();
         s:=LIST2(s,t); s:=Generate(array,s); 
         IF tok = rbrack THEN GetTok; 
                         ELSE SyntaxError(2) END;
         END;
      RETURN(s) 
(*9*) END Variable;


(**************************************************************************)
(*                                                                        *)
(*                       Code generation                                  *)
(*                                                                        *)
(**************************************************************************)


PROCEDURE Generate(s: Token; t: LIST): LIST;
(* Generate code for token s *)
VAR code: LIST;

BEGIN 
  CASE s OF 
       power  : code:=COMP(POW,t) |
       times  : code:=COMP(MUL,t) |
       plus   : code:=COMP(ADD,t) |
       minus  : code:=COMP(SUB,t) |
       div    : code:=COMP(QUOT,t) |
       mod    : code:=COMP(REM,t) | 
       neq    : code:=COMP(NEQS,t) |
       eql    : code:=COMP(EQS,t) |
       lss    : code:=COMP(LTS,t) |
       leq    : code:=COMP(LEQ,t) |
       gtr    : code:=COMP(GTS,t) |
       geq    : code:=COMP(GEQ,t) |
       and    : code:=COMP(UND,t) |
       or     : code:=COMP(ODER,t) |
     becomes  : code:=COMP(SETAV,t) |
       if     : code:=COMP(IFS,t) |
       case   : code:=COMP(COND,t) |
       not    : code:=COMP(NOTS,t) |
       var    : code:=COMP(VARS,t) |
       array  : code:=COMP(ARY,LIST1(t)) |
       pragma : code:=COMP(prag,t) |
       begin  : IF t = SIL THEN code:=t
                   ELSIF RED(t) = SIL THEN code:=FIRST(t)
                   ELSE code:=COMP(PROGN,t) END |
       while  : code:=COMP(WHL,t) |
       begald : code:=COMP(PROGA,t) |
       repeat : code:=COMP(RPT,t) |
          for : code:=Genfor(t) |
        print : code:=COMP(prnt,LIST1(t)) |
         goto : code:=COMP(GTO,LIST1(t)) | 
        label : code:=COMP(LBEL,LIST1(t))  |
        ident : IF RED(t) = SIL THEN code:=FIRST(t)
                                ELSE code:= COMP(DE,t)
                END  |
          sil : code:=t |
    procedure : code:=COMP(DE,t) | 
       return : code:=COMP(ret,t) |
       string : code:=COMP(STRNG,t) 
         ELSE   code:=LIST2(QUOTE,t); 
  END;
  RETURN(code);
END Generate;


PROCEDURE Genfor(t: LIST): LIST;
(* generate code for "for - statement" *)
VAR h1,h2,h3,h4,i,t1,t2,t3,s,w,v: LIST;
BEGIN
(*0*) FIRST5(t,i,t1,t2,t3,s);
(*1*) (*start and step size *)
      h1:= LIST2(i,t1);
      h1:= Generate(becomes,h1);        (* (Assign i t1) *)
      h1:= LIST1(h1);
      IF t2 # SIL THEN w:= GENSYM();
         h2:= LIST2(t2,t1);
         h2:= Generate(minus,h2);  (* (sub t2 t1) *)
         h2:= LIST2(w,h2);
         h2:= Generate(becomes,h2); (* (Assign w (sub t2 t1)) *)
         h1:= COMP(h2,h1);   (* (Assign ...)  (Assign i t1) *)
         END;
(*2*) (*step direction *) 
      IF t2 # SIL THEN 
         v:=  GENSYM();  
         h2:= LIST2(v,-1);
         h2:= Generate(becomes,h2);   (* (Assign v -1) *)
         h2:= LIST1(h2); 
         h3:= LIST2(v,1);
         h3:= Generate(becomes,h3);   (* (Assign v +1) *)
         h2:= COMP(h3,h2);            (* (Assign v +1) (Assign v -1) *)
         h3:= LIST2(0,w);
         h3:= Generate(leq,h3);   (* (LE 0 w) *)
         h2:= COMP(h3,h2);        (* (LE 0 w) (Assign v +1) (Assign v -1) *)
         h2:= Generate(if,h2); (* (IFS (LE 0 w) ... (Assign v -1) *)
         h1:= COMP(h2,h1);   (* (IFS ... ) (Gensym()) ... (Assign i t1) *)
         END;
(*3*) (*loop condition *)
      IF t2 = SIL THEN h2:=LIST2(i,t3)  (* (LE i t3) *)
         ELSE h2:= LIST2(t3,i);
         h2:= Generate(minus,h2);      (* (sub t3 i) *)
         h2:= LIST2(v,h2);
         h2:= Generate(times,h2);      (* (mul v (sub t3 i)) *)
         h2:= LIST2(0,h2);
         END;
      h2:= Generate(leq,h2);        (* (LE 0 (mul v (sub t3 i))) *)
(*4*) (*loop body with increment *)
      IF t2 = SIL THEN h3:= LIST2(i,1)
                  ELSE h3:= LIST2(i,w) END;

      h3:= Generate(plus,h3);   (* (Add i w) *)
      h3:= LIST2(i,h3);
      h3:= Generate(becomes,h3);    (* (Assign i (Add i w)) *)
      h3:= LIST2(s,h3);             (* (s (Assign i (Add i w))) *)
      h3:= Generate(begin,h3);      (* (PROGN s (Assign i...)))) *)   
(*5*) (*initialization and while *)
      h3:= LIST1(h3);    
      h2:= COMP(h2,h3);             (* (LE 0 ... ))) (PROGN ...    )))) *)
      h2:= Generate(while,h2);      (* (WHL (LE ...))) (PROGN ... ))))) *)
      h1:= COMP(h2,h1);             (* (WHL ... ) ....  (Assign i t1) *)
      h1:= INV(h1);
      h1:= Generate(begin,h1);      (* (PROGN (WHL ... )... (Assign i t1)) *)
      RETURN(h1);
(*6*) END Genfor;
          

PROCEDURE CaseLabel(v: LIST): LIST;
(* generate code for "case - statement" *)
VAR   h1,a,c,C,s,L: LIST;
BEGIN
(*1*) FIRST3(v,a,C,s);
      L:= SIL;
(*2*) WHILE C # SIL DO ADV(C,c,C);
            h1:= LIST2(a,c);
            h1:= Generate(eql,h1);            (* (EQ a ci) *)
            IF L = SIL THEN L:=h1             (* (EQ a c1) *)
                       ELSE L:=LIST2(L,h1);   (* (OR L (EQ a ci)) *)
                            L:=Generate(or,L) END;
            END;  (* WHILE *)
(*3*) L:= LIST2(L,s);  (* (cond,s) *)
      RETURN(L);
(*4*) END CaseLabel;


(**************************************************************************)
(*                                                                        *)
(*       Initialization of Scanner and Parser                             *)  
(*                                                                        *)
(**************************************************************************)


PROCEDURE InitAscanner;
(*Initialize scanner procedures. *)
BEGIN
  Declare(KW,"AldesKeyWord");
  (* Enter key words *)
  KeyWord(do,"do");
  KeyWord(if,"if");
  KeyWord(case,"case");
  KeyWord(of,"of");
  KeyWord(then,"then");
  KeyWord(else,"else");
  KeyWord(while,"while");
  KeyWord(for,"for");
  KeyWord(until,"until");
  KeyWord(repeat,"repeat");
  KeyWord(safe,"safe");
  KeyWord(global,"global");
  KeyWord(intrinsic,"intrinsic");
  KeyWord(pragma,"pragma");
  KeyWord(const,"const");
  KeyWord(array,"array");
  KeyWord(To,",...,");
  KeyWord(goto,"goto");
  KeyWord(go,"go");
  KeyWord(to,"to");
  KeyWord(print,"print");
  KeyWord(return,"return")
END InitAscanner;


PROCEDURE InitAparser;
(*Initialize parser and scanner procedures. *)
VAR   X, s, v: LIST;
BEGIN
  InitAscanner; 
  Compiledp1(CLOUT,"PRINT"); 
  Declare(prnt,"PRINT"); 
  Declare(any,"ANY");
  Declare(ret,"RETURN");
  Declare(prag,"PRAGMA");
(*3*) blv:=SIL; LISTVAR(blv); 
      X:=ENV; 
      WHILE X <> SIL DO ADV2(X,s,v,X);
            IF NOT MEMQ(s,blv) THEN blv:=COMP(s,blv) END;
            END;
END InitAparser;


BEGIN
      InitAparser;
END ALDPARSE.            
(* -EOF- *)
