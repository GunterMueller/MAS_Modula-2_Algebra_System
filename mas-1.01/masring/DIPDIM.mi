(* ----------------------------------------------------------------------------
 * $Id: DIPDIM.mi,v 1.4 1994/06/02 13:21:36 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPDIM.mi,v $
 * Revision 1.4  1994/06/02  13:21:36  dolzmann
 * Corrected comment of procedure DILDIM.
 *
 * Revision 1.3  1992/10/15  16:29:32  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:34:17  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:14:50  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPDIM;

(* DIP Dimension Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, SIL, BETA, 
                    LIST1, FIRST, RED, ADV, COMP, INV, LENGTH;

FROM SACLIST IMPORT LELT, CCONC, EQUAL, MEMBER, LIST2,  
                    ADV2, ADV4, ADV3, FIRST4, FIRST2, AWRITE;

FROM MASBIOS IMPORT SWRITE, BLINES; 

FROM DIPC IMPORT DIPEVL, DIPNOV, EVDOV, VALIS;

FROM SACPOL IMPORT VLWRIT;

CONST rcsidi = "$Id: DIPDIM.mi,v 1.4 1994/06/02 13:21:36 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DIGBZT(S: LIST): LIST; 
(*Distributive polynomial groebner base common zero test.
S is a groebner basis. t = -1 or 0 if DIMENSION(S) eq -1 or 0, t = 1
if DIMENSION(S) ge 1. *)
VAR   EL, GP, J1Y, QL, RL, TL, V, VL, VS: LIST; 
BEGIN
(*1*) (*number of variables. *) TL:=1; 
      IF S = SIL THEN RETURN(TL); END; 
      J1Y:=FIRST(S); RL:=DIPNOV(J1Y); 
      IF RL = 0 THEN TL:=-1; RETURN(TL); END; 
(*2*) (*dimension. *) ADV(S, QL,GP); EL:=DIPEVL(QL); VL:=EVDOV(EL); 
      VS:=BETA; 
      IF VL = SIL THEN TL:=-1; RETURN(TL); END; 
      IF RED(VL) = SIL THEN V:=1; ELSE V:=0; END; 
(*3*) (*check each polynomial. *) 
      WHILE GP <> SIL DO ADV(GP, QL,GP); EL:=DIPEVL(QL); 
            VL:=EVDOV(EL); 
            IF VL <> SIL THEN
               IF RED(VL) = SIL THEN V:=V+1; END; 
               END; 
            END; 
      IF V = RL THEN TL:=0; END; 
(*6*) RETURN(TL); END DIGBZT; 


PROCEDURE DILDIM(G: LIST;  VAR DL,S,M: LIST); 
(*Distributive polynomial list dimension.
G is a list of distributive polynomials, a groebner base.
d is the dimension of ideal(G). S is a maximal independend
set of variables. M is a set of maximal independent sets of
variables. *)
VAR   DLP, EL, I, J1Y, ML, MP, QL, RL, U, VL, VS: LIST; 
BEGIN
(*1*) (*initialise. *) 
      IF G = SIL THEN DL:=LENGTH(VALIS); RETURN; END; 
      J1Y:=FIRST(G); RL:=DIPNOV(J1Y); 
      IF RL = 0 THEN DL:=-1; RETURN; END; 
(*2*) (*dimension eq -1. *) QL:=FIRST(G); EL:=DIPEVL(QL); 
      VL:=EVDOV(EL); VS:=BETA; 
      IF VL = SIL THEN DL:=-1; RETURN; END; 
(*3*) (*prepare. *) DL:=0; S:=BETA; M:=BETA; U:=BETA; 
      FOR I:=1 TO RL DO U:=COMP(I,U); END; 
      U:=INV(U); 
(*4*) (*recursive call. *) M:=DIDIMS(G,S,U,M); 
(*5*) (*look for maximal independent set.*) M:=INV(M); MP:=M; 
      WHILE MP <> SIL DO ADV(MP, ML,MP); DLP:=LENGTH(ML); 
            IF DLP > DL THEN DL:=DLP; S:=ML; END; 
            END; 
(*5*) (*finish. *) 
(*8*) RETURN; END DILDIM; 


PROCEDURE DIDIMS(G,S,U,M: LIST): LIST; 
(*Distributive polynomial dimension maximal independent set.
G is a list of distributive rational polynomials, and a g-base.
S is a maximal independent set of variables.
U is a set of variables of unknown status.
M and MP are lists of maximal independent sets of variables.  *)
VAR   A, ML, MP, MS, SL, SP, TL, UL, UP: LIST; 
BEGIN
(*1*) (*initialise. *) A:=BETA; UP:=U; MP:=M; 
(*2*) (*loop on u. *) 
      WHILE UP <> SIL DO ADV(UP, UL,UP); SP:=LIST1(UL); 
            SP:=CCONC(S,SP); TL:=EVGBIT(SP,G); 
            IF TL = 0 THEN MP:=DIDIMS(G,SP,UP,MP); END; 
            END; 
(*3*) (*finish. *) MS:=MP; SL:=0; 
      WHILE (MS <> SIL) AND (SL = 0) DO ADV(MS, ML,MS); 
            SL:=USETCT(S,ML); END; 
      IF SL = 0 THEN MP:=COMP(S,MP); END; 
      RETURN(MP); 
(*6*) END DIDIMS; 


PROCEDURE EVGBIT(S,G: LIST): LIST; 
(*Exponent vector groebner base intersection test.
S is a set of variable indices. G is a groebner basis.
t = 0 if intersection = () else t = 1. *)
VAR   EL, GP, J1Y, PL, RL, SL, SP, SPP, TL, V: LIST; 
BEGIN
(*1*) (*initialise. *) GP:=G; TL:=0; 
      IF GP = SIL THEN RETURN(TL); END; 
      J1Y:=FIRST(GP); RL:=DIPNOV(J1Y); SP:=S; SPP:=BETA; 
      WHILE SP <> SIL DO ADV(SP, SL,SP); J1Y:=RL-SL; SL:=J1Y+1; 
            SPP:=COMP(SL,SPP); END; 
      SPP:=INV(SPP); 
(*2*) (*loop on polynomials. *) TL:=1; 
      WHILE GP <> SIL DO ADV(GP, PL,GP); EL:=DIPEVL(PL); 
            V:=EVDOV(EL); SL:=USETCT(V,SPP); 
            IF SL = 1 THEN RETURN(TL); END; 
            END; 
(*2*) (*finish. *) TL:=0; 
(*5*) RETURN(TL); END EVGBIT; 


PROCEDURE USETCT(U,V: LIST): LIST; 
(*Unordered set containment test. U and V are unordered sets.
t = 1 if U is contained in V else t = 0. *)
VAR   TL, UL, UP: LIST; 
BEGIN
(*1*) (*loop on u. *) UP:=U; TL:=0; 
      WHILE UP <> SIL DO ADV(UP, UL,UP); 
            IF  NOT (MEMBER(UL,V) = 1) THEN RETURN(TL); END; 
            END; 
(*2*) (*finish. *) TL:=1; 
(*5*) RETURN(TL); END USETCT; 


PROCEDURE IXSUBS(V,I: LIST): LIST; 
(*Indexed subset. V is a list.
I is an index list. The elements of V with index from I
are put to VP. *)
VAR   IL, IP, VL, VP: LIST; 
BEGIN
(*1*) (*initialize. *) IP:=I; VP:=BETA; 
(*2*) (*proccess elements of ip.*) 
      WHILE IP <> SIL DO ADV(IP, IL,IP); VL:=LELT(V,IL); 
            VP:=COMP(VL,VP); END; 
(*3*) (*finish. *) VP:=INV(VP); 
(*6*) RETURN(VP); END IXSUBS; 


PROCEDURE DIDIMWR(DL,S,M,V: LIST); 
(*Distributive polynomial dimension write.
d is the dimension of an ideal. M is a maximal independend
set of variables. S is a set of maximal independent sets of
variables. V is the variable list. *)
VAR   VV, ML: LIST; 
BEGIN
(*1*) (*write dimension. *) BLINES(0);  
      SWRITE("Dimension = "); AWRITE(DL); BLINES(1); 
(*2*) (*write maximal independent set. *) 
      VV:=IXSUBS(V,S); 
      SWRITE("Maximal independent set = "); VLWRIT(VV); BLINES(1); 
(*3*) (*write other maximal independent sets. *) 
      SWRITE("All maximal independent sets = ( "); 
      WHILE M <> SIL DO ADV(M, ML,M);       
            VV:=IXSUBS(V,ML); VLWRIT(VV); 
            IF M <> SIL THEN SWRITE(", "); END; 
            END;
      SWRITE(" )"); BLINES(1); 
(*8*) RETURN; END DIDIMWR; 


END DIPDIM.

(* -EOF- *)
