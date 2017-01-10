(* ----------------------------------------------------------------------------
 * $Id: SACSYM.mi,v 1.3 1992/10/15 16:27:55 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: SACSYM.mi,v $
 * Revision 1.3  1992/10/15  16:27:55  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:35  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:32  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE SACSYM;

(* SAC Symbol System Implementation module. *)



(* Import lists and declarations. *)

FROM MASELEM IMPORT GAMMAINT, MASEXP, MASQREM, MASREM;

FROM MASSTOR IMPORT BETA, SIL, LIST, LISTVAR, 
                    LENGTH, SFIRST, SRED,
                    LIST1, INV, ADV, FIRST, RED, COMP;

FROM MASBIOS IMPORT BLINES, CREAD, CWRITE, CREADB,
                    DIGIT, LETTER, LISTS,
                    MASORD, GWRITE, DIBUFF,
                    CHI, BKSP, SWRITE, TAB;

FROM SACLIST IMPORT CLOUT, ADV2, CONC, COMP2, EQUAL, 
                    SECOND, RED2, AWRITE, AREAD;


CONST ICOUNT = 1; (* ? *)

VAR NAM, SBASE: GAMMAINT;

CONST rcsidi = "$Id: SACSYM.mi,v 1.3 1992/10/15 16:27:55 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE ACOMP(A,B: LIST): LIST;
(*Alphabetic comparison. A and B are symbols. t=+1,0,-1 according
to whether A preceds, is equal, or follows B alphabetically.*)
VAR  TL: LIST;
BEGIN
(*1*) TL:=ACOMP1(NAME(A),NAME(B));
(*4*) RETURN(TL); END ACOMP;


PROCEDURE ACOMP1(A,B: LIST): LIST;
(*Alphabetic comparison, 1. subalgorithm. A and B are packed strings.
s=-1,0,1 according to whether a preceds, is equal, or succeeds B
alphabetically.*)
VAR  AL, AP, BL, BP, SL: LIST;
BEGIN
(*1*) (*initialize.*) AP:=A; BP:=B; SL:=0;
(*2*) (*compare.*)
      REPEAT ADV(AP, AL,AP); ADV(BP, BL,BP);
             IF AL > BL THEN SL:=1; ELSE
                IF AL < BL THEN SL:=-1; END;
                END;
             IF SL <> 0 THEN RETURN(SL); END;
             UNTIL (AP = SIL) OR (BP = SIL);
(*3*) (*end.*)
      IF BP <> SIL THEN SL:=-1; ELSE
         IF AP <> SIL THEN SL:=1; END;
         END;
      RETURN(SL);
(*6*) END ACOMP1;


PROCEDURE ASSOC(AL,L: LIST): LIST;
(*Associate. L=(a1 b1, a2 b2, ...,a sub n b sub n), n ge 0,
a is an object. If there is an i such that a=a sub i then
P=(b sub i, ...,a sub n b sub n), otherwise P=().*)
VAR  ALP, P: LIST;
BEGIN
(*1*) (*initialize.*) P:=L;
(*2*) (*search.*)
      WHILE P <> SIL DO ADV(P, ALP,P);
            IF AL = ALP THEN RETURN(P); END;
            ADV(P, ALP,P); END;
(*5*) RETURN(P); END ASSOC;


PROCEDURE ASSOCQ(AL,L: LIST): LIST;
(*Associate equal. L=(a1 b1, a2 b2, ...,a sub n b sub n), n ge 0,
a is an object. If there is an i such that a is equal to a sub i then
P=(b sub i, ...,a sub n b sub n), otherwise P=().*)
VAR  ALP, P: LIST;
BEGIN
(*1*) (*initialize.*) P:=L;
(*2*) (*search.*)
      WHILE P <> SIL DO ADV(P, ALP,P);
            IF EQUAL(AL,ALP) = 1 THEN RETURN(P); END;
            ADV(P, ALP,P); END;
(*5*) RETURN(P); END ASSOCQ;


PROCEDURE ATTRIB(L: LIST): LIST;
(*Attribute. L is a symbol. Returns the attributes of L.*)
VAR  LP: LIST;
BEGIN
(*1*) (*initialize.*) LP:=SIL;
(*2*) (*symbol.*) IF SYMBOL(L) THEN LP:=RED2(L) END;
(*5*) RETURN(LP); END ATTRIB;


PROCEDURE BEGINU();
(*Begin, universal. The symbolic system is initialized without
initializing any subsystems. It is assumed, that at least BEGIN1
was called previously.*)
VAR  CL, NL, TL: LIST;
BEGIN
(*1*) (*initialize symbolic globals.*) SYMTB:=SIL; 
      NL:=0; CL:=CHI+1; TL:=BETA DIV CL;
      REPEAT TL:=TL DIV CL; NL:=NL+1;
             UNTIL TL = 0;
      SBASE:=MASEXP(CL,NL);
(*2*) (*translator options.*) TRMAX:=10; COUNT:=0; NAM:=0;
(*5*) RETURN; END BEGINU;


PROCEDURE EXPLOD(S: LIST): LIST;
(*Explode symbol. S is a symbol, L its character list.*)
VAR  A, AP, CL, DL, J1Y, L, LP, Q: LIST;
BEGIN
(*1*) (*get packed character list.*) LP:=NAME(S); L:=SIL; CL:=CHI+1;
(*2*) (*unpack characters.*)
      REPEAT DL:=SBASE DIV CL; ADV(LP, A,LP);
             REPEAT MASQREM(A,DL, Q,AP); A:=AP; J1Y:=Q-1; 
                    L:=COMP(J1Y,L); DL:=DL DIV CL;
                    UNTIL A = 0;
             UNTIL LP = SIL;
(*3*) (*exit*) L:=INV(L);
(*6*) RETURN(L); END EXPLOD;


PROCEDURE ENTER(L: LIST): LIST;
(*Enter into symbol table. L is a character list, S the pointer
to the corresponding symbol. If the symbol is not yet in the
symbol table SYMTB, then a new node is created.*)
VAR  J1Y, S: LIST;
BEGIN
(*1*) J1Y:=PACK(L); S:=STINS(J1Y);
(*4*) RETURN(S); END ENTER;


PROCEDURE GENSYM(): LIST;
(*Generate symbol. S is a newly generated symbol. NAM is advanced.*)
VAR  J1Y, Q, S: LIST;
BEGIN
(*1*) (*increase counter.*) NAM:=NAM+1;
(*2*) (*create character list.*) S:=LIST1(MASORD("Y")); Q:=NAM;
      REPEAT J1Y:=MASREM(Q,10); S:=COMP(J1Y,S); Q:=Q DIV 10;
             UNTIL Q = 0;
(*3*) (*enter in symbol table.*) J1Y:=COMP(MASORD("J"),S);
      S:=ENTER(J1Y);
(*6*) RETURN(S); END GENSYM;


PROCEDURE GET(S,AL: LIST): LIST;
(*Get property. The property list of the symbol S is searched
under indicator a. A is the property under a, if any, otherwise
A is set to beta.*)
VAR  A: LIST;
BEGIN
(*1*) A:=ASSOC(AL,ATTRIB(S));
      IF A <> SIL THEN A:=FIRST(A); END;
(*4*) RETURN(A); END GET;


PROCEDURE NAME(L: LIST): LIST;
(*Name. L is a symbol. Returns the name of L.*)
VAR  LP: LIST;
BEGIN
(*1*) (*initialize.*) LP:=SIL;
(*2*) (*symbol.*) IF SYMBOL(L) THEN LP:=SECOND(L) END;
(*5*) RETURN(LP); END NAME;


PROCEDURE PACK(L: LIST): LIST;
(*Pack character list. L is a non-empty character list. B is the
packed list.*)
VAR  A, B, BL, CL, DL, J1Y, LP: LIST;
BEGIN
(*1*) (*initialize.*) LP:=L; B:=SIL; BL:=CHI+1; A:=0; DL:=1;
(*2*) (*process characters.*)
      REPEAT ADV(LP, CL,LP);
             IF DL = SBASE THEN B:=COMP(A,B); A:=0; DL:=1; END;
             DL:=DL*BL; J1Y:=A*BL; J1Y:=J1Y+CL; A:=J1Y+1;
             UNTIL LP = SIL;
(*3*) (*shift left and invert.*)
      WHILE DL < SBASE DO DL:=DL*BL; A:=A*BL; END;
      J1Y:=COMP(A,B); B:=INV(J1Y);
(*6*) RETURN(B); END PACK;


PROCEDURE PUT(S,AL,A: LIST);
(*Put. The property A is stored on the property list of
the symbol S under the indicator a.*)
VAR  L: LIST;
BEGIN
(*1*) (*already there.*) L:=ASSOC(AL,ATTRIB(S));
      IF L <> SIL THEN SFIRST(L,A); RETURN; END;
(*2*) (*new entry.*) SRED(RED(S),COMP2(AL,A,ATTRIB(S)));
(*5*) RETURN; END PUT;


PROCEDURE REMPRP(S,AL: LIST);
(*Remove property. Under indicator a on the property list of
symbol S the property is removed.*)
VAR  BL, L, LP: LIST;
BEGIN
(*1*) (*initialize.*) L:=RED(S); LP:=RED(L);
(*2*) (*search and remove.*)
      WHILE LP <> SIL DO ADV(LP, BL,LP);
            IF AL = BL THEN SRED(L,RED(LP)); RETURN; END;
            L:=LP; LP:=RED(LP); END;
(*5*) RETURN; END REMPRP;


PROCEDURE SMEMB(S,L: LIST): LIST;
(*Symbol membership. S is a symbol, L a list containing possibly
also symbols. b=1 if S or a copy of S occurs in L, b=0 otherwise.*)
VAR  BL, LP, SP, SS: LIST;
BEGIN
(*1*) (*initilize.*) LP:=L; BL:=1; SP:=SECOND(S);
(*2*) (*search.*)
      WHILE LP <> SIL DO ADV(LP, SS,LP); 
            IF SYMBOL(SS) AND (ACOMP1(NAME(SS),SP) = 0)
               THEN RETURN(BL); END;
            END;
(*3*) (*exit.*) BL:=0;
(*6*) RETURN(BL); END SMEMB;


PROCEDURE SREAD(): LIST;
(*Symbol read. The next symbol is read from input. S is the symbol in
the symbol table SYMTB.*)
VAR  J1Y, S: LIST;
BEGIN
(*1*) J1Y:=SREAD1(); S:=ENTER(J1Y);
(*4*) RETURN(S); END SREAD;


PROCEDURE SREAD1(): LIST;
(*Symbol read, 1. The first non-alphanumeric character of the
input stream terminates the symbol.  L is the character list of 
the symbol, which is not entered in the symbol table.*)
VAR  C, L: LIST;
BEGIN
(*1*) (*skip leading blanks.*) L:=SIL; C:=CREADB();
      IF NOT LETTER(C) THEN SWRITE("NO SYMBOL FOUND BY SREAD1");
         DIBUFF; L:=LISTS("???"); RETURN(L) END;
(*2*) (*collect characters.*) 
      REPEAT L:=COMP(C,L); C:=CREAD();
             UNTIL NOT DIGIT(C) AND NOT LETTER(C);
      BKSP; L:=INV(L);
(*5*) RETURN(L); END SREAD1;


PROCEDURE STCNT(T: LIST;    VAR S,P: LIST);
(*Symbol table tree count. T is a symbol tree, S is the number
of symbols in T, P the number of properties of all symbols of the tree.
Since every symbol has a name property, P ge S.*)
VAR  J1Y, K, L, PP, R, SP: LIST;
BEGIN
(*1*) (*basis.*)
      IF T = SIL THEN S:=0; P:=0; RETURN; END;
(*2*) (*left branch.*) ADV2(T, L,K,R); STCNT(L, S,P);
(*3*) (*process symbol.*) S:=S+1; J1Y:=LENGTH(K); J1Y:=J1Y DIV 2;
      P:=P+J1Y;
      IF (COUNT >= 1) AND (GET(K,ICOUNT) <> SIL) THEN UWRIT1(K);
         TAB(8); UWRITE(GET(K,ICOUNT)); END;
(*4*) (*right branch.*) STCNT(R, SP,PP); S:=S+SP; P:=P+PP;
(*7*) RETURN; END STCNT;


PROCEDURE STINS(B: LIST): LIST;
(*Symbol tree insertion. B is a packed list of characters. S is a
pointer to the corresponding symbol in the symbol table. If
it is not yet in, a new node is created.*)
VAR  L, N, R, S, SP, T, TP: LIST;
     s: INTEGER;
BEGIN
(*1*) (*symbol table.*) T:=SYMTB;
(*2*) (*binary search.*)
      WHILE T <> SIL DO ADV2(T, L,SP,R); s:=INTEGER(ACOMP1(NAME(SP),B));
            CASE s OF
                 -1 : TP:=T; T:=R; |
                 0 : S:=SP; RETURN(S); |
                 1 : TP:=T; T:=L; END;
            END;
(*3*) (*insert new node.*) S:=SYNEW(B); N:=STNEW(S);
      IF SYMTB = SIL THEN SYMTB:=N; ELSE
         IF s = -1 THEN SRED(RED(TP),N); ELSE SFIRST(TP,N); END;
         END;
(*6*) RETURN(S); END STINS;


PROCEDURE STLST(T: LIST): LIST;
(*Symbol tree list. T is a symbol tree, L is the list of its symbols
in alphabetic order.*)
VAR  J1Y, L, LL, RL, SL: LIST;
BEGIN
(*1*) (*basis.*)
      IF T = SIL THEN L:=SIL; RETURN(L); END;
(*2*) (*recursion.*) ADV2(T, LL,SL,RL);
      IF LL <> SIL THEN LL:=STLST(LL); END;
      IF RL <> SIL THEN RL:=STLST(RL); END;
      J1Y:=COMP(SL,RL); L:=CONC(LL,J1Y);
(*5*) RETURN(L); END STLST;


PROCEDURE STLSTI(T: LIST): LIST;
(*Symbol tree list, in-order. T is a binary tree of symbols, L is a
list of its symbols, with the root symbol appearing first.*)
VAR  J1Y, L, LL, RL, SL: LIST;
BEGIN
(*1*) (*basis.*)
      IF T = SIL THEN L:=SIL; RETURN(L); END;
(*2*) (*recursion.*) ADV2(T, LL,SL,RL);
      IF LL <> SIL THEN LL:=STLSTI(LL); END;
      IF RL <> SIL THEN RL:=STLSTI(RL); END;
      J1Y:=CONC(LL,RL); L:=COMP(SL,J1Y);
(*5*) RETURN(L); END STLSTI;


PROCEDURE STNEW(L: LIST): LIST;
(*Symbol tree new. L is symbol.*)
VAR  S: LIST;
BEGIN
(*1*) S:=COMP(SIL,COMP(L,SIL));
(*4*) RETURN(S); END STNEW;


PROCEDURE STSRCH(T,AP: LIST): LIST;
(*Symbol tree search. T is a binary tree of symbols, AP is a packed
list of characters. If the symbol with the name AP occurs already
in the symbol table T then S=() and otherwise S points to the entry.*)
VAR  K, L, R, S, TP, TPP: LIST;
     s: INTEGER;
BEGIN
(*1*) (*initialize.*) S:=SIL; TPP:=T;
(*2*) (*binary search.*)
      IF TPP <> SIL THEN
         REPEAT TP:=TPP; ADV2(TP, L,K,R); 
                s:=INTEGER(ACOMP1(NAME(K),AP));
                CASE s OF
                     -1 : TPP:=R; |
                     0 : S:=K; RETURN(S); |
                     1 : TPP:=L; | END;
                UNTIL TPP = SIL;
         END;
(*5*) RETURN(S); END STSRCH;


PROCEDURE STWRT(T: LIST);
(*Symbol tree write. T is a binary tree of symbols. The symbols
followed by their properties are printed in alphabetic order.*)
VAR  K, L, M, ML, R, TP: LIST;
BEGIN
(*1*) TP:=T;
      WHILE TP <> SIL DO ADV2(TP, L,K,R); STWRT(L); 
            UWRIT1(K); SWRITE(": ");
            M:=ATTRIB(K);
            WHILE M <> SIL DO ADV(M, ML,M); 
                  UWRIT1(ML); SWRITE(" ") END;
            BLINES(0); TP:=R; END;
(*4*) RETURN; END STWRT;


PROCEDURE SYMBOL(AP: LIST): BOOLEAN;
(*Symbol. AP is an object. Returns true if it is a symbol and 
false else.*)
VAR  BL: BOOLEAN;
BEGIN
(*1*) BL:=FALSE;
      IF AP > BETA THEN 
         IF FIRST(AP) = -BETA THEN BL:=TRUE END 
         END;
(*4*) RETURN(BL); END SYMBOL;


PROCEDURE SYNEW(L: LIST): LIST;
(*Symbol new. L is a packed character list.*)
VAR  S: LIST;
BEGIN
(*1*) S:=COMP(-BETA,COMP(L,SIL));
(*4*) RETURN(S); END SYNEW;


PROCEDURE SymSummary();
(*Summary of symbol system. The number of symbols in SYMTB and
the number of their properties is written.*)
VAR  P, S: LIST;
BEGIN
(*1*) (*count symbols and their properties.*) BLINES(2); 
      STCNT(SYMTB,S,P); 
      AWRITE(S); SWRITE(" SYMBOLS AND "); 
      AWRITE(P); SWRITE(" PROPERTIES."); BLINES(1);
      (*debug*) 
      STWRT(SYMTB);
      (*gubed*)
(*5*) END SymSummary;


PROCEDURE SYWRIT(S: LIST);
(*Symbol write. The symbol S is written in the output stream.*)
VAR  N, L: LIST;
BEGIN 
(*1*) (*get unpacked name.*) N:=EXPLOD(S); 
(*2*) (*transmit.*) CLOUT(N);
(*5*) END SYWRIT;


PROCEDURE SUBLIS(L,A: LIST): LIST;
(*Substitution with list. L=(x1 e1, ...,x sub n e sub n),
a and e sub i are objects. The x sub i are beta-digits
or pointers to uniquely stored lists like symbols. B is A
with the x sub i substituted by the e sub i.*)
VAR  B, C1, C2, J1Y, J2Y: LIST;
BEGIN
(*1*) (*basis.*) B:=ASSOC(A,L);
      IF B <> SIL THEN B:=FIRST(B); RETURN(B); END;
      IF (A <= BETA) OR SYMBOL(A) THEN B:=A; RETURN(B); END;
(*2*) (*recursion.*) ADV(A, C1,C2); J1Y:=SUBLIS(L,C1);
      J2Y:=SUBLIS(L,C2); B:=COMP(J1Y,J2Y);
(*5*) RETURN(B); END SUBLIS;


PROCEDURE UREAD(): LIST;
(*Universal read. The next atom, symbol or list over atoms
and symbols is read and stored under L. Blanks may occur anywhere,
elements of a list may or may not be separated by a comma.*)
VAR  C, J1Y, L: LIST;
BEGIN
(*1*) (*branch on c.*) L:=SIL; C:=CREADB();
      IF DIGIT(C) OR (C = MASORD("-")) OR (C = MASORD("+")) THEN 
         BKSP; L:=AREAD(); RETURN(L) END;
      IF LETTER(C) THEN BKSP; L:=SREAD(); RETURN(L) END;
      IF C <> MASORD("(") THEN
         SWRITE("ATOMS, SYMBOLS, OR LISTS EXPECTED BY UREAD, ");
         CWRITE(C); SWRITE(" FOUND"); DIBUFF; RETURN(0) END;
(*2*) (*read list.*) C:=CREADB();
      IF C = MASORD(")") THEN RETURN(L); END;
      BKSP;
      LOOP J1Y:=UREAD(); L:=COMP(J1Y,L); C:=CREADB();
           IF C = MASORD(")") THEN L:=INV(L); RETURN(L) END; 
           IF C <> MASORD(",") THEN BKSP; END;
           END;
(*5*) END UREAD;


PROCEDURE UWRITE(L: LIST);
(*Universal write. L is an atom, symbol or a list over
atoms and symbols. L is written in the output stream,
followed by BLINES(0). *)
BEGIN
(*1*) UWRIT1(L); BLINES(0);
(*4*) RETURN; END UWRITE;


PROCEDURE UWRIT1(L: LIST);
(*Universal write, 1. subalgorithm. L is an atom, a symbol
or a list over atoms or symbols. L is written in the output
stream followed by a blank character, but not by BLINES. *)
VAR  AL, LP: LIST;
BEGIN
(*1*) (*atom or symbol.*)
      IF L < BETA THEN AWRITE(L); RETURN END; 
      IF SYMBOL(L) THEN SYWRIT(L); RETURN END; 
(*2*) (*list.*) SWRITE("("); LP:=L;
      WHILE LP <> SIL DO ADV(LP, AL,LP); UWRIT1(AL); 
            IF LP <> SIL THEN SWRITE(" ") END 
            END;
      SWRITE(")"); 
(*5*) END UWRIT1;


PROCEDURE TRC(VAR SP: ARRAY OF CHAR; 
          AL1,AL2,AL3,AL4,AL5,AL6,AL7,AL8,AL9,AL10,AL11,AL12,AL13: LIST);
(*Trace input or output. The first argument is the characters of an
algorithm name, followed by +i for input tracing and by -i for
output tracing. The following arguments are input or output parameters.
*)
VAR  A: ARRAY[1..13] OF LIST;
VAR  BL, CL, J1Y, JL, S: LIST;
     IL: INTEGER;
BEGIN
(*1*) (*load.*) A[1]:=AL1; A[2]:=AL2; A[3]:=AL3; A[4]:=AL4; A[5]:=AL5;
      A[6]:=AL6; A[7]:=AL7; A[8]:=AL8; A[9]:=AL9; A[10]:=AL10;
      A[11]:=AL11; A[12]:=AL12; A[13]:=AL13;
(*2*) (*form algorithm name.*) S:=ENTER(LISTS(SP));
(*3*) (*count.*) CL:=GET(S,ICOUNT);
      IF CL = SIL THEN CL:=0; END;
      IF A[1] < 0 THEN CL:=CL+1; PUT(S,ICOUNT,CL); END;
      IF (CL > TRMAX) OR (COUNT >= 1) THEN RETURN; END;
(*4*) (*input.*)
      IF A[1] < 0 THEN (*indent*)
         SWRITE("+"); UWRIT1(S);
         FOR IL:=2 TO INTEGER(A[1]) DO GWRITE(GAMMAINT(IL-1)); SWRITE(".");
             UWRIT1(A[IL]); END;
         BLINES(0); RETURN; END;
(*5*) (*output trace.*) 
      SWRITE("-"); UWRIT1(S);
      FOR IL:=2 TO INTEGER(-A[1]) DO GWRITE(GAMMAINT(IL-1)); SWRITE(".");
          UWRIT1(A[IL]); END;
      IF CL > 0 THEN (*undent*) END;
      BLINES(0);
(*8*) RETURN; END TRC;


(* Initialization. *)

BEGIN 

LISTVAR(SYMTB);

BEGINU; 

END SACSYM.


(* -EOF- *)
