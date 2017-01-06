(* ----------------------------------------------------------------------------
 * $Id: MASSYM2.mi,v 1.5 1993/05/11 10:48:59 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASSYM2.mi,v $
 * Revision 1.5  1993/05/11  10:48:59  kredel
 * Small changes in STINS
 *
 * Revision 1.4  1992/10/16  13:53:40  kredel
 * Errors found by Mocka corrected
 *
 * Revision 1.3  1992/10/15  16:27:54  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:32:33  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:11:30  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASSYM2;

(* MAS/SAC Symbol System Implementation module 2. *)


(* Version: HASH-TABLE with AVL-TREEs for Symboltable *)


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
                    SECOND, RED2, AWRITE, AREAD,  SLELT,ADV3;


CONST rcsidi = "$Id: MASSYM2.mi,v 1.5 1993/05/11 10:48:59 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

CONST ICOUNT = 1; (* ? *)

VAR NAM, SBASE: GAMMAINT;

VAR newIns: BOOLEAN;


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
(*3*) (*hiding type.*) NOSHOW:=ENTER(LISTS("NOSHOW"));
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
      IF A <> SIL THEN A:=FIRST(A) END;
(*4*) RETURN(A) END GET;


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
            IF AL = BL THEN SRED(L,RED(LP)); RETURN END;
            L:=LP; LP:=RED(LP) END;
(*5*) RETURN END REMPRP;


PROCEDURE SMEMB(S,L: LIST): LIST;
(*Symbol membership. S is a symbol, L a list containing possibly
also symbols. b=1 if S or a copy of S occurs in L, b=0 otherwise.*)
VAR  BL, LP, SP, SS: LIST;
BEGIN
(*1*) (*initilize.*) LP:=L; BL:=1; SP:=SECOND(S);
(*2*) (*search.*)
      WHILE LP <> SIL DO ADV(LP, SS,LP);
            IF SYMBOL(SS) AND (ACOMP1(NAME(SS),SP) = 0)
               THEN RETURN(BL) END;
            END;
(*3*) (*exit.*) BL:=0;
(*6*) RETURN(BL) END SMEMB;


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
      IF NOT LETTER(C) THEN SWRITE("No symbol found by SREAD1");
         DIBUFF; L:=LISTS("???"); RETURN(L) END;
(*2*) (*collect characters.*)
      REPEAT L:=COMP(C,L); C:=CREAD();
             UNTIL NOT DIGIT(C) AND NOT LETTER(C);
      BKSP; L:=INV(L);
(*5*) RETURN(L); END SREAD1;


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
VAR   P, S: LIST;
      i: CARDINAL;
BEGIN
(* 
(*0*) (*test.*) BLINES(2);
      SWRITE("SYMTBarr = "); BLINES(1); 
      FOR i:=0 TO maxtab DO 
          SWRITE("["); AWRITE(i); SWRITE("] = "); 
          UWRITE(SYMTBarr[i]); 
          IF SYMTBarr[i] < SIL THEN SYMTBarr[i]:=SIL END;  
          END;
      *)
(*1*) (*count symbols and their properties.*) BLINES(2);
      STCNT(SYMTB,S,P);                      (* SYMTB dummy ! *)
      AWRITE(S); SWRITE(" symbols and ");
      AWRITE(P); SWRITE(" properties."); BLINES(1);
      (*debug*)
      STWRT(SYMTB);                          (* SYMTB dummy ! *)
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
(*Universal read. The next atom, symbol, string or list over atoms, 
strings and symbols is read and stored under L. Blanks may occur 
anywhere. Elements of a list may or may not be separated by a comma.*)
VAR   C, J1Y, L: LIST;
BEGIN
(*1*) (*BRANCH ON C.*) L:=SIL; C:=CREADB();
      IF DIGIT(C) OR (C = MASORD("-")) OR (C = MASORD("+")) THEN 
         BKSP; L:=AREAD(); RETURN(L) END;
      IF LETTER(C) THEN BKSP; L:=SREAD(); RETURN(L) END;
      IF C = MASORD('"') THEN 
         LOOP C:=CREAD();
              IF C = MASORD('"') THEN C:=CREAD();
                 IF C <> MASORD('"') THEN BKSP; EXIT END; 
                 END;
              L:=COMP(C,L);
              END;
         L:=INV(L); RETURN(L) END;
      IF C <> MASORD("(") THEN
         SWRITE("Atoms, strings, symbols, or lists expected by UREAD, ");
         CWRITE(C); SWRITE(" found."); DIBUFF; RETURN(0) END;
(*2*) (*READ LIST.*) C:=CREADB();
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
stream. *)
VAR  AL, LP: LIST;
BEGIN
(*1*) (*ATOM OR SYMBOL.*)
      IF L < BETA THEN AWRITE(L); RETURN END; 
      IF SYMBOL(L) THEN SYWRIT(L); RETURN END; 
(*2*) (*LIST.*) SWRITE("("); LP:=L;
      WHILE LP <> SIL DO ADV(LP, AL,LP); UWRIT1(AL);
            IF AL = NOSHOW THEN SWRITE(" ..."); LP:=SIL END; 
            IF LP <> SIL THEN SWRITE(" ") END 
            END;
      SWRITE(")"); 
(*5*) END UWRIT1;


(*************************************************************************)
(*
MODULE SymbolTableAccess;
(* by Thomas Wollersberger December 1990, modified AVL-Version *)
(* Version HASH+AVL *)

IMPORT LIST,SIL,ADV2,COMP,ACOMP1,NAME,SYNEW,SRED,RED,SFIRST,
       UWRIT1,UWRITE,GET,ICOUNT,COUNT,LENGTH,TAB,BLINES,ADV,
       LISTVAR,SWRITE,CONC,ATTRIB,FIRST,ADV3,SLELT,RED2;
EXPORT STINS,STCNT,STLST,STLSTI,STSRCH,STWRT;
*)


CONST maxtab = 498; (* length of hashtable *)
                    (* good values: 112,192,!198!,210,222,306,!498!,996 *)
                    (* more symbols -> more tableplaces *)
 
CONST  maxtab1 = maxtab + 1;
 
VAR SYMTBarr : ARRAY [0..maxtab] OF LIST;

(* Remark : All procedures have access to the same symboltable,
            here implemented as an Hash-table with AVL-trees for
            collision resolution. The varible SYMTB
            of type LIST defined in the definition-module is
            never used (It's only history !). The procedures
            parametrisized with a Symboltable will only use the
            Hash-table defined in this local module (incidentally
            it is named SYMTBarr, too !). You can use the outer SYMTB
            as a dummy-variable.   Th.W. *)


PROCEDURE hash(name:LIST): CARDINAL;
(* computes a number (0..maxtab) from the packed character list name.
   The numbers should be distributed very uniform, but that depends on
   the average structure of the names. Three possiblities are tested : *)

  (* 1. Simply take 16 Bits of the Coding of the first characters ! *)
  (* fastest version *)
  (*
  VAR f:LIST;
  BEGIN
  f:=FIRST(name); (*Assert f >= 0 *)
  RETURN(CARDINAL(f) MOD maxtab1)      
  *)

  (* 2. Simply take the Coding of the first characters ! *)
  
  VAR f:LIST;
  BEGIN
  f:=FIRST(name); (*Assert f >= 0 *)
  RETURN(CARDINAL(f MOD maxtab1))      
  

  (* 3. Sum up over all characters ! *)
  (*
  VAR s:CARDINAL;
      f:LIST;
  BEGIN
  s:=0;
  WHILE name # SIL DO
    ADV(name, f,name);
    s:=(s+CARDINAL(f MOD maxtab1)) MOD maxtab1
  END;
  RETURN(s)
  *)

END hash;


  PROCEDURE SearchInsertAVL (B, t:LIST; 
            VAR S: LIST; VAR HeightChanged:BOOLEAN): LIST;
  (* For further documentation see any book on AVL-trees ! *)
  VAR  lt,bal,elem,rt: LIST;
       tt, lth,balh,rth,lth1,rth1: LIST;
    BEGIN     tt:=t; 
    IF t=SIL  (* empty tree *)
      THEN S:=SYNEW(B);
           tt:=COMP(SIL,COMP(0,COMP(S,SIL)));
           HeightChanged:=TRUE;
           newIns:=TRUE

      ELSE ADV3(t, lt,bal,elem,rt);
           CASE INTEGER(ACOMP1(B,NAME(elem))) OF

            -1: (* search/insert left *)
                lt:=SearchInsertAVL(B, lt, S,HeightChanged);
                IF newIns THEN SFIRST(t,lt); newIns:=FALSE END;
                IF HeightChanged  (* reset balance *)
                  THEN CASE INTEGER(bal) OF
                        -1: ADV3(lt, lth,balh,elem,rth);
                            IF balh=-1
                              THEN (* LL-Rotation *)
                                   SFIRST(t,rth);
                                   SRED(RED2(lt),t); SLELT(t,2,0);
                                   tt:=lt; newIns:=TRUE
                              ELSE (* LR-Rotation *)
                                   ADV3(rth, lth1,balh,elem,rth1);
                                   SRED(RED2(lt),lth1);
                                   SFIRST(rth,lt);
                                   SFIRST(t,rth1);
                                   SRED(RED2(rth),t);
                                   IF balh=-1
                                     THEN SLELT(t,2,1) ELSE SLELT(t,2,0)
                                   END;
                                   IF balh=1
                                     THEN SLELT(lt,2,-1) ELSE SLELT(lt,2,0)
                                   END;
                                   tt:=rth; newIns:=TRUE
                            END;
                            SLELT(t,2,0); HeightChanged:=FALSE |

                         0: SLELT(t,2,-1) |

                         1: SLELT(t,2,0); HeightChanged:=FALSE
                       END
                END (* IF HeightChanged *) |

             0: (* Symbol found *)
                S:=elem; HeightChanged:=FALSE |

             1: (* search/insert right *)
                rt:=SearchInsertAVL(B, rt, S,HeightChanged);
                IF newIns THEN SRED(RED2(t),rt); newIns:=FALSE END;
                IF HeightChanged  (* reset balance *)
                  THEN CASE INTEGER(bal) OF
                        -1: SLELT(t,2,0); HeightChanged:=FALSE |

                         0: SLELT(t,2,1) |

                         1: ADV3(rt, lth,balh,elem,rth);
                            IF balh=1
                              THEN (* RR-Rotation *)
                                   SRED(RED2(t),lth);
                                   SFIRST(rt,t); SLELT(t,2,0);
                                   tt:=rt; newIns:=TRUE;
                              ELSE (* RL-Rotation *)
                                   ADV3(lth, lth1,balh,elem,rth1);
                                   SFIRST(rt,rth1);
                                   SRED(RED2(lth),rt);
                                   SRED(RED2(t),lth1);
                                   SFIRST(lth,t);
                                   IF balh=1
                                     THEN SLELT(t,2,-1) ELSE SLELT(t,2,0)
                                   END;
                                   IF balh=-1
                                     THEN SLELT(rt,2,1) ELSE SLELT(rt,2,0)
                                   END;
                                   tt:=lth; newIns:=TRUE
                            END;
                            SLELT(t,2,0); HeightChanged:=FALSE
                       END
                END (* IF HeightChanged *)

           END (* CASE *)
    END; (* IF *)
  RETURN(tt); 
  END SearchInsertAVL;


PROCEDURE STINS(B: LIST): LIST;
(* Symbol table insertion. B is a packed list of characters. S is a
pointer to the corresponding symbol in the symbol table. If
it is not yet in, a new node is created. *)
VAR h: BOOLEAN;
    S: LIST; 
    n: CARDINAL;
  BEGIN
  newIns:=FALSE; h:=FALSE; S:=SIL; 
  n:=hash(B);
  SYMTBarr[n]:=SearchInsertAVL( B, SYMTBarr[n], S, h ); 
  (* computes symbol S for name B *)
  RETURN(S)
END STINS;


PROCEDURE STCNT(T: LIST; VAR S,P: LIST);
(* Symbol table count. T is a dummy list, S is the number of
symbols in T, P the number of properties of all symbols of
the tree. Since every symbol has a name property, P ge S. *)
VAR bal: LIST;

  PROCEDURE STCNTrec(T: LIST; VAR S,P: LIST);

    VAR  J1Y,K,L,PP,R,SP: LIST;

    BEGIN
    IF T = SIL
      THEN S:=0; P:=0
      ELSE ADV3(T, L,bal,K,R);
           STCNTrec(L, S,P); (* left branch *)
           S:=S+1; J1Y:=LENGTH(K); J1Y:=J1Y DIV 2;
           P:=P+J1Y;
           IF (COUNT >= 1) AND (GET(K,ICOUNT) <> SIL)
             THEN UWRIT1(K); TAB(8); UWRITE(GET(K,ICOUNT)) END;
           STCNTrec(R, SP,PP); (* right branch *)
          S:=S+SP; P:=P+PP
    END
  END STCNTrec;

  VAR s1,p1:LIST;
      i: CARDINAL;

  BEGIN
  S:=0; P:=0;
  FOR i:=0 TO maxtab DO
    STCNTrec(SYMTBarr[i], s1,p1);
    S:=S+s1; P:=P+p1  (* sum up over array *)
  END

END STCNT;


PROCEDURE STLST(T: LIST): LIST;
(* Symbol table list. T is a dummy list. L is the list of
its symbols in alphabetic order. *)
VAR bal,J1Y: LIST;

  PROCEDURE STLST1tree(T: LIST): LIST; (* inorder list *)

    VAR  LL,RL,SL: LIST;

    BEGIN
    IF T = SIL THEN RETURN(SIL) END;
    ADV2(T, LL,SL,RL);  (* left tree,symbol,right tree *)
    IF LL <> SIL THEN LL:=STLST1tree(LL) END;
    IF RL <> SIL THEN RL:=STLST1tree(RL) END;
    J1Y:=COMP(SL,RL);
    RETURN( CONC(LL,J1Y) )

  END STLST1tree;


  VAR AuxTree:LIST;

  PROCEDURE WalkThroughTreeAndInsertIntoAuxtree(T:LIST);

    (* Elements of AVL-tree T are inserted into normal binary tree *)

    PROCEDURE insert(sym:LIST); (* local proc. for inserting into AuxTree *)
      VAR h,l,m,r:LIST;
      BEGIN
      IF AuxTree=SIL
        THEN (* new root *)
          AuxTree:=COMP(SIL,COMP(sym,SIL))
        ELSE (* scan tree *)
          h:=AuxTree;
          LOOP (* trace one path until one fitting empty leave is found *)
            ADV2(h, l,m,r);
            CASE INTEGER(ACOMP1(NAME(m),NAME(sym))) OF
             -1: IF r=SIL
                   THEN SRED(RED(h),COMP(SIL,COMP(sym,SIL))); EXIT
                   ELSE h:=r
                 END |
              1: IF l=SIL
                   THEN SFIRST(h,COMP(SIL,COMP(sym,SIL))); EXIT
                   ELSE h:=l
                 END
            END (* CASE *)
          END (* LOOP *)
      END (* IF *)
    END insert;

    VAR L,M,R:LIST;

    BEGIN
    IF T # SIL
      THEN ADV3(T, L,bal,M,R); (* cut from tree T and insert into AuxTree *)
           insert(M);
           (* I take preorder, because I expect in-(~alphabetic-)order
           to produce very unbalanced trees ! *)
           WalkThroughTreeAndInsertIntoAuxtree(L);
           WalkThroughTreeAndInsertIntoAuxtree(R)
    END

  END WalkThroughTreeAndInsertIntoAuxtree;


  VAR i:CARDINAL;

  BEGIN
  (* insert all elements of the table into an auxiliary binary tree *)
  AuxTree:=SIL;
  FOR i:=0 TO maxtab DO
    WalkThroughTreeAndInsertIntoAuxtree(SYMTBarr[i])
  END;
  RETURN( STLST1tree(AuxTree) ) (* inorder-traverse AuxTree *)

END STLST;


PROCEDURE STLSTI(T: LIST): LIST;
(* Symbol table list, internal-order (quick to compute).
T is a dummy list, L is the list of the symbols. *)
VAR bal,J1Y: LIST;

  PROCEDURE STLSTIrec(T: LIST): LIST;  (* preorder list *)

    VAR LL,RL,SL: LIST;

    BEGIN
    IF T = SIL THEN RETURN(SIL) END;
    ADV3(T, LL,bal,SL,RL);
    IF LL <> SIL THEN LL:=STLSTIrec(LL) END;
    IF RL <> SIL THEN RL:=STLSTIrec(RL) END;
    J1Y:=CONC(LL,RL);
    RETURN( COMP(SL,J1Y) )
  END STLSTIrec;


  VAR L:LIST;
      i:CARDINAL;

  BEGIN (* compute a list from every tree, concatenate them all. *)
  L:=SIL;
  FOR i:=0 TO maxtab DO
    L:=CONC(L, STLSTIrec(SYMTBarr[i]) )
  END;
  RETURN(L)

END STLSTI;


PROCEDURE STSRCH(T,AP: LIST): LIST;
(* Symbol table search. T is a dummy list, AP is a packed list of
characters. If the symbol with the name AP occurs already in the
symbol table T then S points to the entry and otherwise S=(). *)
VAR  l,b,m,r: LIST;

  BEGIN
  T:=SYMTBarr[hash(AP)]; (* hash the fitting tree *)
  WHILE T # SIL DO (* walk through until you find or not. *)
    ADV3(T, l,b,m,r);
    CASE INTEGER(ACOMP1(NAME(m),AP)) OF
     -1: T:=r |
      0: RETURN(m) | (* found *)
      1: T:=l
    END
  END;
  RETURN(SIL) (* not found *)

END STSRCH;


PROCEDURE STWRT(T: LIST);
(*Symbol table write. T is a dummy list. The symbols followed
by their properties are printed in alphabetic order. *)
VAR a,M,ML:LIST;

  BEGIN
  T:=STLST(T); (* Now T is a list of the symbols in alphabetical order *)

  WHILE T # SIL DO (* Walk through list *)
    ADV(T, a,T); 
    UWRIT1(a); SWRITE(": ");
    M:=ATTRIB(a);
    WHILE M <> SIL DO ADV(M, ML,M); UWRIT1(ML); SWRITE(" ") END;
    BLINES(0)
  END

END STWRT;


(* Initialisation of Hash-table of AVL-trees : *)

VAR i:CARDINAL;

BEGIN

FOR i:=0 TO maxtab DO LISTVAR(SYMTBarr[i]); SYMTBarr[i]:=SIL END;

(*
END SymbolTableAccess;
(*************************************************************************)
(* Initialization. *)
BEGIN
*)

LISTVAR(SYMTB); (* SYMTB is Dummy-Variable here !! *)

BEGINU;

END MASSYM2.

(* -EOF- *)
