(* ----------------------------------------------------------------------------
 * $Id: DINNGB.mi,v 1.1 1995/12/16 13:23:14 kredel Exp $
 * ----------------------------------------------------------------------------
 * Copyright (c) 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * $Log: DINNGB.mi,v $
 * Revision 1.1  1995/12/16 13:23:14  kredel
 * Moved from the masdom directory.
 *
 * Revision 1.1  1994/03/11  15:35:19  pesch
 * Groebner bases for non noetherian polynomial rings.
 * Diplomarbeit I. Bader.
 * Modified.
 * Does not give correct results. Do not use.
 * Should be rewritten.
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DINNGB;
(* DIP Groebner bases for non noetherian polynomial rings. *)

  (* Import lists and declarations. *)

  FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, SRED, SFIRST,
                      LISTVAR, TIME,COMP, INV, LENGTH, LIST1;
                    
  FROM SACLIST IMPORT AWRITE, COMP2, LIST2, LAST, EQUAL, SECOND, RED2,
                      OWRITE, ADV3, FIRST3, COMP3, CCONC, LIST3;
                     
  FROM SACPOL IMPORT PDEG;

  FROM MASBIOS IMPORT BLINES, SWRITE;

  FROM DIPRN IMPORT DIRPON, DIRPRP, DIRPSM, DIRPMC, DIRPDF, DIRPWR,
                    DIRLWR, DIRPNG, DIRPPR;

  FROM SACRN IMPORT RNCEIL, RNINT, RNPROD, RNQ;

  FROM DIPRNGB IMPORT DIGBC3, DIGBC4,EVPLSO, EVPLM, DIRPGB,DIRLIS,
                      DIRPSP, DIRPNF, DILCPL, DILUPL, DIGBMI, DIRGBA;

  FROM DIPC IMPORT DIPMAD, DIPFMO, EVILCP, EVSU, EVSUM,
                   EVDIF, DIPMCP, DIPEVL, DIPLBC, DIPLPM,
                   EVSIGN, DIPNOV, DIPDEG, VALIS;

  FROM SACI IMPORT  IQ, IREM, IMAX;

  FROM MASNC IMPORT EVZERO;

CONST rcsidi = "$Id: DINNGB.mi,v 1.1 1995/12/16 13:23:14 kredel Exp $";
CONST copyrighti = "Copyright (c) 1993 Universitaet Passau";


  PROCEDURE DINNCP(EL,A,B: LIST): LIST;
  (* distributive polynomial non-commutative product. e is a non-negative
     integer. A and B are distributive polynomials in 2 variables. C is the
      non-commutative product of A and B with respect to  Y * X = X**e Y. *)
  VAR AL, AP, BL, BP, C, CL, CP, CS, OL, UL, VL : LIST;
  BEGIN
  (*1*) (* trivial cases.*) C:=0;
        IF A = 0 THEN RETURN(C); END;
        IF B = 0 THEN  RETURN(C); END;
        IF DIRPON(A) = 1 THEN C:=B;  RETURN(C); END;
        IF DIRPON(B) = 1 THEN C:=A;  RETURN(C); END;
        OL:=RNINT(1);
  (*2*) (* loops on A and B. *)  AP:=A;
        REPEAT DIPMAD(AP, AL,UL,AP); BP:=B;
               REPEAT DIPMAD(BP, BL,VL,BP);
                         CP:=EVNNCP(EL,UL,VL); CS:=DIPFMO(OL,CP);
                         CL:=RNPROD(AL,BL); CS:=DIRPRP(CS,CL);
                         C:=DIRPSM(C,CS);
               UNTIL BP = SIL;
        UNTIL AP = SIL;
  (*3*) (* finish. *) RETURN(C);
        END DINNCP;


  PROCEDURE EVNNCP(EL,S,T: LIST): LIST;
  (* exponent vector non-commutative product. S and T are exponent vectors.
     of length 2. C is the non-commutative product S * T with respect
     to the relation Y * X = X**e Y. *)
   VAR C, M1, ML, MP, N, NL, NP, QL, QP, S1, S2,
       VL, T1, TP, TS, TT: LIST;
   BEGIN
   N:=LENGTH(S); VL:=EVZERO(N);
   TS:=EVILCP(S,VL); TT:=EVILCP(T,VL);
   EVSU(S,1,0, S1,NL); EVSU(S,2,0, S2,ML);
   EVSU(T,2,0, T1,MP); C:=SIL;
(*1*) (* trivil cases. *)
   IF TS=0 THEN C:=T; RETURN(C); END;
   IF TT=0 THEN C:=S; RETURN(C); END;
(*2*) (* commutative products. *)
     IF NL=0 THEN C:=EVSUM(S,T); RETURN(C); END;
     IF ( NL >=1 ) AND ( MP=0 )
              THEN C:=EVSUM(S,T); RETURN(C); END;
(*3*) (* non-commutative product. *)
     IF ( NL >= 1 ) AND ( MP > 0 )
              THEN QL:=IPOWER(EL,NL); QP:=MP*QL;
                   EVSU(T1,2,QP, TP,M1); C:=EVSUM(S,TP); END;
   RETURN(C); END EVNNCP;


  PROCEDURE EVNRDT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right division test. s and t are
     exponent vectors. C=1 if s rdiv t otherwise, C=0. *)
  VAR C, CL, KL, ML, NL, QL, RL : LIST;
  BEGIN
  EVSU(S,1,0, S,NL); EVSU(S,2,0, S,ML);
  EVSU(T,1,0, T,RL); EVSU(T,2,0, T,QL);
  IF NL <= RL THEN CL:=RL-NL; KL:=IPOWER(EL,CL); KL:=ML*KL;
                IF KL <= QL THEN C:=1; END;
        ELSE C:=0; END; RETURN(C);
  END EVNRDT;

  PROCEDURE EVNCRD(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right division. s and t a are
     exponent vectors, if s rdiv t then the output is t//s. *)
  VAR C, CL, HL, KL, ML, NL, QL, RL, S1, S2, SP, T1, T2 : LIST;
  BEGIN
  EVSU(S,1,0, S1,NL); EVSU(S,2,0, S2,ML);
  EVSU(T,1,0, T1,RL); EVSU(T,2,0, T2,QL);
  IF  NL <= RL THEN CL:=RL-NL; KL:=IPOWER(EL,CL); KL:=ML*KL;
                IF KL <= QL THEN EVSU(S2,2,KL, SP,RL);
                                 C:=EVDIF(T,SP); END; END;
  RETURN(C); END EVNCRD;

  PROCEDURE EVNLDT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative left division test. s and t are
     exponent vectors. C=1 if s ldiv t otherwise, C=0. *)

  VAR C, FL, KL, ML, NL, QL, RL : LIST;
  BEGIN
  EVSU(S,1,0, S,NL); EVSU(S,2,0, S,ML);
  EVSU(T,1,0, T,RL); EVSU(T,2,0, T,QL);
  IF (NL <= RL) AND (ML <= QL) THEN FL:=QL-ML; KL:=IPOWER(EL,NL);
                IF IREM(FL,KL)=0 THEN C:=1; END;
                                 ELSE C:=0; END;
  RETURN(C); END EVNLDT;

  PROCEDURE EVNCLD(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative left division. s and t a are
     exponent vectors. The output is s\\t if s ldiv t . *)
  VAR C, CL, CS, FL, KL, ML, NL, QL, RL, S1, S2, T1, T2 : LIST;
  BEGIN
  EVSU(S,1,0, S1,NL); EVSU(S,2,0, S2,ML);
  EVSU(T,1,0, T1,RL); EVSU(T,2,0, T2,QL);
  IF (NL <= RL) AND (ML <= QL) THEN FL:=QL-ML; KL:=IPOWER(EL,NL);
                IF IREM(FL,KL)=0 THEN C:=SIL; CL:=RL-NL;
                                      CS:=IQ(FL,KL); C:=COMP(CS,C);
                                      C:=COMP(CL,C) ; END; END;
  RETURN(C); END EVNCLD;

  PROCEDURE EVLLCM(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative least left common multiple. s and t are
     exponent vectors. C is the least left common multiple of s and t. *)
  VAR C, FL, GL, GP, HL, M1, M2, ML, MP, N1, N2, NL, NP, S1, S2, SP,
      T1, T2 : LIST;
  BEGIN
  EVSU(S,1,0, S1,N1); EVSU(S,2,0, S2,M1);
  EVSU(T,1,0, T1,N2); EVSU(T,2,0, T2,M2);
  (*1*) (* order the input vectors. *)
  IF N1 >= N2  THEN NL:=N1; ML:=M1;
                    NP:=N2; MP:=M2; SP:=S2;
               ELSE NL:=N2; ML:=M2;
                    NP:=N1; MP:=M1; SP:=T2; END;
  (*2*) (* compute the llcm. *)
  FL:=NL-NP; HL:=IPOWER(EL,FL); GL:=MP*HL;
  GP:=IMAX(ML,GL); EVSU(SP,2,GP, C,N1);
  RETURN(C); END EVLLCM;


  PROCEDURE EVLRCM(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative least right common multiple.
     s and t exponent vectors. C is the least right common multiple
     of s and t if it exists! *)
  VAR C, FL,FS, GL, GP, HL, HP, KL, M1, M2, MP, ML, MS,
       N1, N2, NP, NL,NN, RL, S1, S2, SP, T1, T2: LIST;
  BEGIN
  EVSU(S,1,0, S1,N1); EVSU(S,2,0, S2,M1);
  EVSU(T,1,0, T1,N2); EVSU(T,2,0, T2,M2);
  (*1*) (* order the input vectors. *)
  IF N1 >= N2 THEN NL:=N1; ML:=M1;
                   NP:=N2; MP:=M2; SP:=S2;
              ELSE NL:=N2; ML:=M2;
                   NP:=N1; MP:=M1; SP:=T2; END;
  (*2*) (* test for existence of lrcm. *)
    FL:=MP-ML; GP:=IPOWER(EL,NP);
    IF IREM(FL,GP)=0 THEN
  (*3*) (* compute the lrcm. *)
       IF ML >= MP THEN MS:=ML;
                   ELSE FS:=RNINT(FL); GP:=IPOWER(EL,NL); RL:=RNINT(GP);
                        HL:=RNQ(FS,RL); HL:=RNCEIL(HL);
                        MS:=(HL*GP)+ML; END;
                   EVSU(SP,2,MS, C,N1); END;
    RETURN(C); END EVLRCM;

  PROCEDURE EVRCMT(EL,S,T:LIST):LIST;
  (* exponent vectors non-commutative right multiple test.
     S and T are exponent vectors. C=1 if S and T have some right common
     multiple otherweise, C=0. *)
  VAR C, FS, GP, M1, M2, MP, ML, N1, N2, NP, NL: LIST;
  BEGIN
  EVSU(S,1,0, S,N1); EVSU(S,2,0, S,M1);
  EVSU(T,1,0, T,N2); EVSU(T,2,0, T,M2);
  IF N1 >= N2  THEN NL:=N1; ML:=M1;
                    NP:=N2; MP:=M2;
               ELSE NL:=N2; ML:=M2;
                    NP:=N1; MP:=M1;END;
  FS:=MP-ML; NP:=IPOWER(EL,NP);
  IF IREM(FS,NP)=0 THEN C:=1;
                   ELSE C:=0;END;
  RETURN(C); END EVRCMT;


  PROCEDURE DNNLNF(EL,P,S:LIST):LIST;
  (* distributive polynomials non-noetherian left normal form.
   P is a list of non zero polynomials in distributive rational representation.
   S is a distributive rational polynomial. R is a polynomial such that S is
   left reducible to R modulo P and R is in normal form with respect to P. *)

  VAR AP, APP, BL, FL, OL, PP, Q, QA, QE, QP, R, SL, SP, SPP, TA, TE : LIST;
  BEGIN

  (*1*) (* trivial case. *)
      IF ( S = 0 ) OR ( P = SIL ) THEN R:=S;  RETURN(R); END;
  (*2*) (* reduction. *)
      R:=SIL; SP:=S; OL:=RNINT(1);
      REPEAT DIPMAD(SP, TA,TE,SPP); PP:=P;
             REPEAT ADV(PP, Q,PP);
                    DIPMAD(Q, QA,QE,QP); SL:=EVNRDT(EL,QE,TE);
             UNTIL ( PP = SIL ) OR ( SL = 1 );
            IF SL=0 THEN R:=DIPMCP(TE,TA,R);
                         IF SPP=SIL THEN SP:=0 ELSE SP:=SPP;END;
                    ELSE FL:=EVNCRD(EL,QE,TE); AP:=DIPFMO(OL,FL);
                         APP:=DINNCP(EL,AP,Q); BL:=RNQ(TA,QA);
                         APP:=DIRPRP(APP,BL);
                         SP:=DIRPDF(SP,APP); END;
      UNTIL SP = 0;
(*3*) (* finish.*)
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END;

      RETURN(R);
      END DNNLNF;

  PROCEDURE DNNLIS(EL,P: LIST): LIST;
  (* distributive polynomials non-noetherian left irreducible set.
     P is a list of distributive rational polynomials, PP is the
     result of left reducing each p element of P modulo P-(p)
     until no further reductions are possible. *)
  VAR IRR, LL, PL, PP, PS, RP, SL, UL, VL : LIST;
  BEGIN
  (*1*) (*initialise. *) PP:=P; PS:=SIL;
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIRPMC(PL);
            IF PL <> 0 THEN PS:=COMP(PL,PS); END;
            END;
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0;
      IF LL <= 1 THEN  RETURN(PP); END;
      SWRITE("***NF IRR= ");
  (*2*) (*reduce until all polynomials are irreducible. *)
      LOOP ADV(PP, PL,PP); UL:=DIPEVL(PL); PL:=DNNLNF(EL,PP,PL);
           AWRITE(IRR); SWRITE(", ");
           IF PL = 0 THEN LL:=LL-1;
              IF LL <= 1 THEN EXIT END;
              ELSE VL:=DIPEVL(PL); SL:=EVSIGN(VL);
              IF SL = 0 THEN PP:=LIST1(PL); EXIT END;
              SL:=EQUAL(UL,VL);
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0;
                 PL:=DIRPMC(PL); END;
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END;
           IF IRR = LL THEN EXIT END;
           END;
  (*3*) (*finish. *) BLINES(0);
  (*4*) RETURN(PP); END DNNLIS;

  PROCEDURE DNNLSP(EL,A,B:LIST):LIST;
  (* distributive polynomials non-noetherian left S-polynomial.
     A and B are polynomials in distributive rational representation
     in 2 variables. C is the left S-polynomial of A and B. *)
  VAR AL, AP, BL, BP, C, SL, FL, O, UL : LIST;
  BEGIN
  O:=RNINT(1);
  (*1*) (* trivial case. *) C:=0;
      IF ( A = 0 ) OR ( B = 0 ) THEN  RETURN(C); END;
      SL:=DIPEVL(A); FL:=DIPEVL(B);
  (*2*) (* left least common multiple and right divisions. *)
        UL:=EVLLCM(EL,SL,FL);
        AP:=EVNCRD(EL,SL,UL); BP:=EVNCRD(EL,FL,UL);
        AP:=DIPFMO(O,AP); BP:=DIPFMO(O,BP);
  (*3*) (* make monomials and compute non-commutative products. *)
        AP:=DINNCP(EL,AP,A); BP:=DINNCP(EL,BP,B);
  (*4*) (* adjust coefficients.*)
        AL:=DIPLBC(AP);  BL:=DIPLBC(BP);
        AP:=DIRPRP(AP,BL); BP:=DIRPRP(BP,AL);
  (*5*) (* difference. *)
        C:=DIRPDF(AP,BP);
        RETURN(C);
        END DNNLSP;

PROCEDURE DNNLGB(EL,P,TF: LIST): LIST;
(* distributive non-noetherian polynomials left Groebner base.
P is a list of rational polynomials in distributive representation
in 2 variables. PP is the left Groebner base of P. t is the
trace flag. *)
VAR  B, C, CPI, CPJ, CPP, D, DL, H, IL, J1Y, PLI, PLIP, PLJ, PP,
      PPP, PPR, PS, Q, QP, S, SL, TL, TR, UL, V, XH : LIST;
BEGIN
(*1*) (*prepare input. *) TL:=TIME(); XH:=0;
      IF P = SIL THEN PP:=P;  RETURN(PP); END;
      PS:=P; PPR:=SIL;
      WHILE PS <> SIL DO ADV(PS, PLI,PS);
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP);
               IF SL = 1 THEN PP:=LIST1(PLIP);  RETURN(PP); END;
               PPR:=COMP(PLIP,PPR); END;
            END;
      PP:=INV(PPR); V:=VALIS;
      IF (PP = SIL) OR (RED(PP) = SIL) THEN  RETURN(PP); END;
(*2*) (*get irreducible base. construct b and d. *)
      IF TF < 0 THEN TF:=-TF; TR:=TIME(); PP:=DNNLIS(EL,PP);
         SWRITE("***IRR TIME="); AWRITE(TIME()-TR); BLINES(0); END;
      PPR:=DIPLPM(PP); PP:=INV(PPR); DNLCPL(EL,PP, D,B);
(*3*) (*loop until no more pairs left. *)
LOOP
      IF D = SIL THEN EXIT END;
      ADV(D, DL,D); FIRST3(DL, UL,CPI,CPJ); ADV(CPI, QP,C);
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ);
      CPP:=RED(J1Y); SRED(CPJ,CPP);
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END;
      IF TF >= 3 THEN SWRITE("UL="); OWRITE(UL); BLINES(0); END;
LOOP
(*4*) (*s-pol and reduction step. *) S:=DNNLSP(EL,PLI,PLJ);
      IF S = 0 THEN EXIT END;
      XH:=XH+1;
      IF TF >= 2 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         SWRITE("S="); DIRPWR(S,V,-1); BLINES(1); END;
      H:=DNNLNF(EL,PP,S);
      IF H = 0 THEN EXIT END;
      H:=DIRPMC(H); SL:=DIRPON(H);
      IF SL = 1 THEN PP:=LIST1(H);  RETURN(PP); END;
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); AWRITE(LENGTH(D));
         SWRITE(" PAIRS LEFT."); BLINES(0); SWRITE("H=");
         DIRPWR(H,V,-1); BLINES(1); END;
      D:=DNLUPL(EL,H,PP,D,B);
EXIT END;
END;
(*5*) (*finish. *)
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         AWRITE(XH); SWRITE(" H-POLYNOMIALS."); BLINES(0); END;
         PP:=DNNLIS(EL,PP);

(*6*) RETURN(PP); END DNNLGB;
 

  PROCEDURE DNNRNF(EL,P,S:LIST):LIST;
  (* distributive polynomials non-noetherian right normal form.
   P is a list of non zero polynomials in distributive rational representation.
   S is a distributive rational polynomial. R is a polynomial such that S is
   right reducible to R modulo P and R is in normal form with respect to P. *)

  VAR AP, APP, BL, OL, PP, Q, QA, QE, QP, R, SL,
      SP, SPP, TA, TE : LIST;
  BEGIN

(*1*) (* trivial case. *)
      IF ( S = 0 ) OR ( P = SIL ) THEN R:=S; RETURN(R); END;
(*2*) (* reduction. *)
      R:=SIL; SP:=S; OL:=RNINT(1);

      REPEAT   PP:=P;  DIPMAD(SP, TA,TE,SPP);
             REPEAT   ADV(PP, Q,PP);
                    DIPMAD(Q, QA,QE,QP); SL:=EVNLDT(EL,QE,TE);
             UNTIL ( SL = 1 ) OR ( PP = SIL ) ;
            IF SL=0 THEN R:=DIPMCP(TE,TA,R);
                         IF SPP=SIL THEN SP:=0 ELSE SP:=SPP;END;
                    ELSE AP:=EVNCLD(EL,QE,TE); AP:=DIPFMO(OL,AP);
                         APP:=DINNCP(EL,Q,AP); BL:=RNQ(TA,QA);
                         APP:=DIRPRP(APP,BL);
                         SP:=DIRPDF(SP,APP); END;
      UNTIL SP = 0;
(*3*) (* finish.*)
      IF R = SIL THEN R:=0; ELSE R:=INV(R); END;

      RETURN(R);
      END DNNRNF;

  PROCEDURE DNNRIS(EL,P: LIST): LIST;
  (* distributive polynomials non-noetherian right irreducible set.
     P is a list of distributive rational polynomials, PP is the
     result of right reducing each p element of P modulo P-(p)
     until no further reductions are possible. *)
  VAR  FL, IRR, LL, PL, PP, PS, RP, SL, UL: LIST;
  BEGIN

  (*1*) (*initialise. *) PP:=P; PS:=SIL;
      WHILE PP <> SIL DO ADV(PP, PL,PP); PL:=DIRPMC(PL);
            IF PL <> 0 THEN PS:=COMP(PL,PS); END;
            END;
      RP:=PS; PP:=INV(PS); LL:=LENGTH(PP); IRR:=0;
      IF LL <= 1 THEN  RETURN(PP); END;
      SWRITE("***NF IRR= ");
  (*2*) (*reduce until all polynomials are irreducible. *)
      LOOP ADV(PP, PL,PP); UL:=DIPEVL(PL); PL:=DNNRNF(EL,PP,PL);
           AWRITE(IRR); SWRITE(", ");
           IF PL = 0 THEN LL:=LL-1;
              IF LL <= 1 THEN EXIT END;
              ELSE FL:=DIPEVL(PL); SL:=EVSIGN(FL);
              IF SL = 0 THEN PP:=LIST1(PL); EXIT END;
              SL:=EQUAL(UL,FL);
              IF SL = 1 THEN IRR:=IRR+1; ELSE IRR:=0;
                 PL:=DIRPMC(PL); END;
              PS:=LIST1(PL); SRED(RP,PS); RP:=PS; END;
           IF IRR = LL THEN EXIT END;
           END;
  (*4*) RETURN(PP); END DNNRIS;


  PROCEDURE DNNRSP(EL,A,B:LIST):LIST;
  (* distributive polynomials non-noetherian right S-polynomial.
     A and B are polynomials in distributive rational representation.
     C is the right S-polynomial of A and B if it exists! *)
  VAR AL, AP, APP, BL, BP, BPP, C, NL, FL, OL, SL, UL, V: LIST;
  BEGIN OL:=RNINT(1);

  (*1*) (* trivial case. *) C:=0;
      IF ( A = 0 ) OR ( B = 0 ) THEN  RETURN(C); END;
      NL:=DIPEVL(A); FL:=DIPEVL(B);
  (*2*) (* right least common multiple and left divisions. *)
        SL:=EVRCMT(EL,NL,FL);
        IF SL=1 THEN UL:=EVLRCM(EL,NL,FL);
        APP:=EVNCLD(EL,NL,UL); BPP:=EVNCLD(EL,FL,UL);
        BP:=DIPFMO(OL,BPP); AP:=DIPFMO(OL,APP);
  (*3*) (* non-commutative products. *)
        AP:=DINNCP(EL,A,AP); BP:=DINNCP(EL,B,BP);
  (*4*) (* adjust coefficients.*)
        AL:=DIPLBC(AP); BL:=DIPLBC(BP);
        AP:=DIRPRP(AP,BL); BP:=DIRPRP(BP,AL);
  (*5*) (* difference. *)
        C:=DIRPDF(AP,BP); END;
        RETURN(C);
        END DNNRSP;

 PROCEDURE DNNRGB(EL,P,TF: LIST): LIST;
 (* distributive polynomials non-noetherian right Groebner base.
  P is a list of rational polynomials in distributive representation in 
  2 variables. PP is the right Groebner base of P. t is the trace flag. *)

  VAR B, C, CPI, CPJ, CPP, D, DL, ELI, ELJ, H, IL, J1Y, PLI, PLIP, PLJ, PP, 
      PPR, PS, Q, QP, S, SL, T, TL, TR, UL, XH : LIST;
BEGIN

(*1*) (*prepare input. *) TL:=TIME(); XH:=0;
      IF P = SIL THEN PP:=P;  RETURN(PP); END;
      PS:=P; PPR:=SIL;
      WHILE PS <> SIL DO ADV(PS, PLI,PS);
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP);
               IF SL = 1 THEN PP:=LIST1(PLIP);  RETURN(PP); END;
               PPR:=COMP(PLIP,PPR); END;
            END;
      PP:=INV(PPR);
      IF (PP = SIL) OR (RED(PP) = SIL) THEN  RETURN(PP); END;
(*2*) (*get irreducible base. construct b and d. *)
      IF TF < 0 THEN TF:=-TF; TR:=TIME(); PP:=DNNRIS(EL,PP);
         SWRITE("***IRR TIME="); AWRITE(TIME()-TR); BLINES(0); END;
      PPR:=DIPLPM(PP); PP:=INV(PPR); DNRCPL(EL,PP, D,B);
(*3*) (*loop until no more pairs left. *)
LOOP
      IF D = SIL THEN EXIT END;
      ADV(D, DL,D); FIRST3(DL, UL,CPI,CPJ); ADV(CPI, QP,C);
      PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y); J1Y:=RED(CPJ);
      CPP:=RED(J1Y); SRED(CPJ,CPP);
      IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END;
      IF TF >= 3 THEN SWRITE("UL="); OWRITE(UL); BLINES(0); END;
LOOP
(*4*) (*test whether the s-pol exists. *)
      ELI:=DIPEVL(PLI); ELJ:=DIPEVL(PLJ); T:=EVRCMT(EL,ELI,ELJ);
      IF T = 0 THEN EXIT END;
(*5*) (*s-pol and reduction step. *)
      S:=DNNRSP(EL,PLI,PLJ);
      IF S = 0 THEN EXIT END;
      XH:=XH+1;
      IF TF >= 2 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         SWRITE("S="); DIRPWR(S,VALIS,-1); BLINES(1); END;
       H:=DNNRNF(EL,PP,S);
      IF H = 0 THEN EXIT END;
      H:=DIRPMC(H); SL:=DIRPON(H);
      IF SL = 1 THEN PP:=LIST1(H);  RETURN(PP); END;
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         AWRITE(XH); SWRITE(" H-POLYNOMIALS, "); AWRITE(LENGTH(D));
         SWRITE(" PAIRS LEFT."); BLINES(0); SWRITE("H=");
         DIRPWR(H,VALIS,-1); BLINES(1); END;
      D:=DNRUPL(EL,H,PP,D,B);
EXIT END;
END;
(*6*) (*finish. *)
      IF TF >= 1 THEN AWRITE(TIME()-TL); SWRITE(" S, ");
         AWRITE(XH); SWRITE(" H-POLYNOMIALS."); BLINES(0); END;
         PP:=DNNRIS(2,PP);

(*7*) RETURN(PP); END DNNRGB;


PROCEDURE DNLCPL(EL,P: LIST;  VAR D,B: LIST);
(* distributive polynomial non-noetherian left  construct pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and D is the pairs list. *)

VAR  BP, BR, DL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, UL, V: LIST;
BEGIN

(*1*) (*prepare input. *) D:=SIL; B:=SIL;
      IF P = SIL THEN  RETURN; END;
      PP:=P;
(*2*) (*construct b and d. *) BR:=SIL; PSS:=PP;
      REPEAT ADV(PSS, PI,QP); Q:=LIST1(PI); BP:=COMP(0,BR);
             ELI:=DIPEVL(PI);
             WHILE QP <> SIL DO ADV(QP, PJ,QP); ELJ:=DIPEVL(PJ);
                   UL:=EVLLCM(EL,ELI,ELJ); DL:=LIST3(UL,BP,Q);
                   D:=COMP(DL,D); Q:=COMP(PJ,Q); END;
             QP:=INV(Q); SFIRST(BP,QP); BR:=COMP(Q,BP); PSS:=RED(PSS);
             UNTIL PSS = SIL;
      D:=EVPLSO(D); B:=INV(BR);

(*6*) END DNLCPL;

PROCEDURE DNRCPL(EL,P: LIST;  VAR D,B: LIST);
(* distributive polynomial non-noetherian right construct pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and
D is the pairs list. *)
VAR  BP, BR, DL, ELI, ELJ, PI, PJ, PP, PSS, Q, QP, SL, UL, V: LIST;
BEGIN

(*1*) (*prepare input. *) D:=SIL; B:=SIL;
      IF P = SIL THEN  RETURN; END;
      PP:=P;
(*2*) (*construct b and d. *) BR:=SIL; PSS:=PP;
      REPEAT ADV(PSS, PI,QP); Q:=LIST1(PI); BP:=COMP(0,BR);
             ELI:=DIPEVL(PI);
             WHILE QP <> SIL DO ADV(QP, PJ,QP); ELJ:=DIPEVL(PJ);
(*3*) (* does the lrcm exist ? *)
                   SL:=EVRCMT(EL,ELI,ELJ);
                   IF SL=1 THEN
                   UL:=EVLRCM(EL,ELI,ELJ); DL:=LIST3(UL,BP,Q);
                   D:=COMP(DL,D); END; Q:=COMP(PJ,Q); END;
             QP:=INV(Q); SFIRST(BP,QP); BR:=COMP(Q,BP); PSS:=RED(PSS);
             UNTIL PSS = SIL;
      D:=EVPLSO(D); B:=INV(BR);

(*6*) END DNRCPL;

PROCEDURE DNLUPL(EL,PL,P,D,B: LIST): LIST;
(* distributive polynomial non-noetherian left update pair list.
P is list of polynomials in distributive representation in 2 variables.
B is the polynomials pairs list and D is the pairs list. p is a non zero 
polynomial in distributive representation. D, P and B are modified.
DP is the updated pairs list. *)
VAR  BP, BPP, BPPP, BR, DL, DP, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP,
     PPR, PS, Q, QS, SL, TL, TF, UL, V: LIST;
BEGIN

(*1*) (*prepare input, update p. *) BP:=B; DP:=SIL;
 PP:=P; H:=PL; PS:=LIST1(H); PPR:=LAST(PP); SRED(PPR,PS);
(*2*) (*update b and d. *) ELJ:=DIPEVL(H);
      WHILE BP <> SIL DO ADV(BP, QS,BPP); ADV(BPP, Q,BPPP);
            PLI:=FIRST(QS); ELI:=DIPEVL(PLI); UL:=EVLLCM(EL,ELI,ELJ);
            DL:=LIST3(UL,BP,Q); DP:=COMP(DL,DP); PS:=LIST1(H);
            SRED(Q,PS); SFIRST(BPP,PS); BP:=BPPP; END;
      DP:=EVPLSO(DP); DP:=EVPLM(D,DP); PS:=LIST1(H); PB:=LIST2(PS,PS);
      BR:=LAST(B); SRED(BR,PB);

(*6*) RETURN(DP); END DNLUPL;


 PROCEDURE DNRUPL(EL,PL,P,D,B: LIST): LIST;
 (* distributive polynomial non-noetherian right update pair list.
 P is list of polynomials in distributive representation in 2 variables.
 B is the polynomials pairs list and
 D is the pairs list. p is a non zero polynomial in
distributive representation. D, P and B are modified.
DP is the updated pairs list. *)
VAR  BP, BPP, BPPP, BR, DL, DP, ELI, ELJ, H, PB, PLI, PLJ, PP, PPP,
     PPR, PS, Q, QS, SL, TL, TF, UL, V: LIST;
BEGIN

(*1*) (*prepare input, update p. *) BP:=B; DP:=SIL;
PP:=P; H:=PL; PS:=LIST1(H); PPR:=LAST(PP); SRED(PPR,PS);
(*2*) (*update b and d. *) ELJ:=DIPEVL(H);
      WHILE BP <> SIL DO ADV(BP, QS,BPP); ADV(BPP, Q,BPPP);
            PLI:=FIRST(QS); ELI:=DIPEVL(PLI);
            TL:=EVRCMT(EL,ELI,ELJ);
            IF TL=1 THEN
               UL:=EVLRCM(EL,ELI,ELJ);
               DL:=LIST3(UL,BP,Q); DP:=COMP(DL,DP);END; PS:=LIST1(H);
               SRED(Q,PS); SFIRST(BPP,PS); BP:=BPPP;  END;
      DP:=EVPLSO(DP); DP:=EVPLM(D,DP); PS:=LIST1(H); PB:=LIST2(PS,PS);
      BR:=LAST(B); SRED(BR,PB);

(*6*) RETURN(DP); END DNRUPL;


PROCEDURE DNN2GB(EL,P,TF: LIST): LIST;
(* distributive polynomials non-noetherian 2-sided Groebner base.
P is a list of rational polynomials in distributive representation
in 2 variables. PP is the Groebner base of P. t is the trace flag.*)

VAR  DL, F, FL, G, GL, GS, H, HL, HS, IL, J1Y,  N, NL, O, PL, PLI, PLIP, 
     PP, PPR, PS, Q, QL, RL, S, SL, TL, V, XH, XI, XL, XS, Y, YL: LIST;

 BEGIN

(*1*) (*prepare input. *) TL:=TIME(); XH:=0;
      IF P = SIL THEN PP:=P;  RETURN(PP); END;
      PS:=P; PPR:=SIL;
      WHILE PS <> SIL DO ADV(PS, PLI,PS);
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP);
               IF SL = 1 THEN PP:=LIST1(PLIP);  RETURN(PP); END;
               PPR:=COMP(PLIP,PPR); END;
            END;
      PP:=INV(PPR);
      IF PP = SIL THEN  RETURN(PP); END;
      J1Y:=FIRST(PP); RL:=DIPNOV(J1Y);
      IF RL = 0 THEN   RETURN(PP); END;
      N:=EVZERO(2); O:=RNINT(1);
      EVSU(N,1,1, FL,YL); Y:=DIPFMO(O,FL);
      V:=VALIS;
(*2*) (* compute the commutative Groebner base. *)
      G:=DIRPGB(PP,TF); F:=G;
(*3*) (*add right und left multiples of polynomials. *)
       REPEAT ADV(F, PL,F);
                  QL:=DINNCP(EL,Y,PL);
                  QL:=DIRPNF(G,QL); QL:=DIRPMC(QL); SL:=DIRPON(QL);
                  IF SL = 1 THEN G:=LIST1(QL);  RETURN(G); END;
(*4*) (* add the left multiple and augment G. *)
                  IF QL <> 0 THEN
                             G:=DIRGBA(QL,G,TF); END;
(*5*) (* add multiples and augment G. *)
                  DL:=DIPLMD(G); IL:=0;
                  WHILE IL <= DL DO XS:=IPOWER(EL,IL); EVSU(N,2,XS, GL,XL);
                       IL:=IL+1; XI:=DIPFMO(O,GL); HL:=DINNCP(EL,PL,XI);
                       HS:=DIRPNF(G,HL); HS:=DIRPMC(HS); SL:=DIRPON(HS);
                       IF SL=1 THEN G:=LIST1(HS);  RETURN(G); END;
                       IF HS <> 0 THEN G:=DIRGBA(HS,G,TF); END;
                       END;
             UNTIL F = SIL;
(*6*)    IF TF < 0 THEN G:=DIRLIS(G); END;

         RETURN(G); END DNN2GB;




  PROCEDURE DNNTGB(EL,P,TF:LIST):LIST;
  (* distributive polynomials non-noetherian two-sided Groebner base. P is
     a list of rational polynomials in distributive representation in 2
     variables. PP is the two-sided Groebner base of P. t is the trace
     flag. The non-commutative produkt is computed w.r.t Y*X=X**eY. *)

VAR  B, B1, C, D, D1, DL, DP, FS,G, GL, GP, GR, GLE, GRE, GRS, QL, QLS,
     H, HG, HL, HS, IL, N, O, PL, PLI, PLIP, PP, PPR, PS, PSS, Q,
     S, SL, TL,V, FS1: LIST;

BEGIN
(*1*) (*prepare input. *) TL:=TIME();
     IF P = SIL THEN PP:=P; RETURN(PP); END;
      PS:=P; PPR:=SIL;
      WHILE PS <> SIL DO ADV(PS, PLI,PS);
            IF PLI <> 0 THEN PLIP:=DIRPMC(PLI); SL:=DIRPON(PLIP);
               IF SL = 1 THEN PP:=LIST1(PLIP); RETURN(PP); END;
               PPR:=COMP(PLIP,PPR); END;
            END;
      PP:=INV(PPR);
      IF PP = SIL THEN RETURN(PP); END;
      V:=VALIS;
(*2*) (*add S-polynomials, right and left multiples sets. *)
      G:=PP; DL:=DIPLMD(G);
      IF  TF >= 2 THEN SWRITE("The maximum Y-degree is:");
                       OWRITE(DL); BLINES(0); END;
      PPR:=DIPLPM(G); G:=INV(PPR);
      SWRITE("G:"); DIRLWR(PP,V,-1); BLINES(0);
      DILCPL(G, D,B); FS:=DIPSPS(D,B);
      IF  TF >= 2 THEN SWRITE("The set of S-polynomials added is:");
                       DIRLWR(FS,V,-1); BLINES(0); END;
      GP:=CCONC(FS,G);
      GRE:=DNNRES(EL,G,0,DL);
      IF  TF >= 2 THEN SWRITE("The set of right multiples added is:");
                       DIRLWR(GRE,V,-1); BLINES(0); END;
      GP:=CCONC(GRE,GP);
      GLE:=DNNLES(EL,PP);
      IF  TF >= 2 THEN SWRITE("The set left multiples added is:");
                       DIRLWR(GLE,V,-1); BLINES(0); END;
      GP:=CCONC(GLE,GP);
(*3*) (*loop until G' is empty. *)
    REPEAT ADV(GP, GL,GP); G:=DIPLPM(G); G:=INV(G);
           GP:=DIPLPM(GP); GP:=DIRLIS(GP);
           HL:=DIRPNF(G,GL);
       IF HL <> 0 THEN PSS:=G; G:=DIPLPM(G);
HL:=DIRPNF(G,HL); HL:=DIRPMC(HL); SL:=DIRPON(HL);
                  IF SL = 1 THEN G:=LIST1(HL);  RETURN(G); END;
          IF  TF >= 2 THEN SWRITE("HL="); DIRPWR(HL,V,-1); BLINES(0); END;
(*4*) (*construct the new b and d. *)
               D1:=SIL; B1:=SIL; PSS:=G;
               WHILE PSS <> SIL DO ADV(PSS, QL,PSS); QLS:=LIST1(QL);
                           B1:=COMP2(QLS,QLS,B1); END;
 (*5*) (* update G'. *)
               B1:=INV(B1); SWRITE("update pairs:");BLINES(0);
               D1:=DILUPL(HL,G,D1,B1);
               FS1:=DIPSPS(D1,B1);
             IF  TF >= 2 THEN SWRITE("The set of new S-polynomials added is:");
                         DIRLWR(FS1,V,-1); BLINES(0); END;
              GP:=CCONC(FS1,GP);
              HS:=LIST1(HL); GR:=DNNRES(EL,HS,0,DL);
            IF TF >= 2 THEN SWRITE("The set of new right multiples added is:");
                           DIRLWR(GR,V,-1); BLINES(0); END;
              GP:=CCONC(GR,GP); HG:=DNNLES(EL,HS);
          IF  TF >= 2 THEN SWRITE("The set of new left multiples added is:");
                           DIRLWR(HG,V,-1); BLINES(0); END;
           GP:=CCONC(HG,GP);
           DP:=DIPLMD(G);
           IF DP > DL THEN
          IF  TF >= 2 THEN SWRITE("The Y-dergree increased from "); OWRITE(DL);
                           SWRITE(" to "); OWRITE(DP); BLINES(0); END;
                           DL:=DL+1; GRS:=DNNRES(EL,G,DL,DP);
          IF  TF >= 2 THEN
          SWRITE("The set of right multiples added due to change of Y-degree:");
                                   DIRLWR(GRS,V,-1); BLINES(0); END;
                          GP:=CCONC(GRS,GP); DL:=DP; END; END;
   UNTIL GP = SIL;
(*6*) G:=DIRLIS(G);
(*7*) RETURN(G);
  END DNNTGB;



  PROCEDURE DNNLES(EL,P:LIST):LIST;
  (* distributive polynomials non-noetherian left exponents set.
     P is a list of polinomials in distributive representation. PP is the
     the list which is result of *-multiplication of each polynomial of P
     from the left with the main variable. The non-commutative
     multiplication is computed w.r.t the relation Y * X = X**e Y. *)

   VAR F, FL, GL, QL, N, O, PL, PP, RL, UL, Y, YL : LIST;
      BEGIN
      FL:=FIRST(P); RL:=DIPNOV(FL);
      IF RL = 0 THEN  RETURN(P); END;
      N:=EVZERO(2); O:=RNINT(1);
      EVSU(N,1,1, UL,YL); Y:=DIPFMO(O,UL);
           F:=P; PP:=SIL;
           REPEAT ADV(F, PL,F);
                  QL:=DINNCP(EL,Y,PL);
                  IF QL <> 0 THEN PP:=COMP(QL,PP); END;
            UNTIL F = SIL;
      PP:=INV(PP);

      RETURN(PP);
      END DNNLES;


  PROCEDURE DNNRES(EL,P,DL,DP:LIST):LIST;
  (* distributive polynomials non-noetherian right exponents set. P is a
    list of polynomials in distributive representation, d and d'are non-
    negative integers with  d' >= d. PP is the is result of *-multiplication
    of each polynomial of P from the right with exponents (e**i) of the
    first variable in the variable list, where i ranges from d to d'.
    The *-multiplication is computed w.r.t the relation Y * X = X**e Y. *)
    VAR F, FL, GL, HS, QL, IL, N, O, PL, PP, RL, UL, X, XI, XL, XS : LIST;
      BEGIN
      FL:=FIRST(P); RL:=DIPNOV(FL);
      IF RL = 0 THEN  RETURN(P); END;
      N:=EVZERO(2); O:=RNINT(1);
           F:=P; PP:=SIL;
           REPEAT ADV(F, PL,F);
                  IL:=DL;
                  WHILE IL <= DP DO XS:=IPOWER(EL,IL); EVSU(N,2,XS, GL,XL);
                       XI:=DIPFMO(O,GL); HS:=DINNCP(EL,PL,XI);
                       IF HS <> 0 THEN  PP:=COMP(HS,PP); END;
                       IL:=IL+1; END;
            UNTIL F = SIL;

      RETURN(PP);
      END DNNRES;

  PROCEDURE DIPSPS(D,B:LIST):LIST;
  (* distibutive polynomials S-polynomials set.
     D is the pairs list and B is the polynomials pairs list.
     D and B are modified. H is the set of all non-zero S-polynomials. *)
 VAR C, CPI, CPJ, CPP, DL, H, S, SL, J1Y, N, NL, O, PL, PLI, PLJ, Q,
      QP, SL3, SL4, SP, UL : LIST;

   BEGIN
   H:=SIL;
   IF D = SIL THEN  RETURN(H); END;
   (*3*) (*loop on pair list. *)
       REPEAT ADV(D, DL,D);
             FIRST3(DL, UL,CPI,CPJ); ADV(CPI, QP,C);
             PLI:=FIRST(QP); J1Y:=RED(CPJ); PLJ:=FIRST(J1Y);
             J1Y:=RED(CPJ); CPP:=RED(J1Y); SRED(CPJ,CPP);
             IF CPP = SIL THEN Q:=LAST(QP); SFIRST(C,Q); END;
   (*4*) (*use criterions to chek if the S-polynomial is necessary. *)
             SL3:=DIGBC3(B,PLI,PLJ,UL);
             SL4:=DIGBC4(PLI,PLJ,UL);
   (*5*) (*compute the S-polynomial. *)
             IF (SL3 <> 0) AND (SL3 <> 0) THEN
                        S:=DIRPSP(PLI,PLJ);
                        IF S <> 0 THEN
                           S:=DIRPMC(S); SL:=DIRPON(S);
                           IF SL = 1 THEN H:=LIST1(S); RETURN(H); END;
                           H:=COMP(S,H); END; END;
       UNTIL D = SIL;

   RETURN(H);
   END DIPSPS;

PROCEDURE DIPLMD(P:LIST):LIST;
 (* distributive polynomial list maximum degree.
    P is a non-empty list of polynomials in distributive form in r variables.
    d is the maximum degree of all polynomials of P w.r.t the main variable .*)
  VAR DL, NL, PL: LIST;
  BEGIN
  DL:=0;
  REPEAT ADV(P, PL,P); NL:=DIPDEG(PL);
  IF NL >= DL THEN DL:=NL; END;
  UNTIL P=SIL;
  RETURN(DL);
  END DIPLMD;

  PROCEDURE IPOWER(EL,AL:LIST):LIST;
  (* integer power. e and a are positve integers. C=e**a. *)
  VAR C: LIST;
  BEGIN C:=1;

 IF AL=0 THEN  RETURN(C); END;
  WHILE AL >= 1 DO
    C:=EL*C; AL:=AL-1; END;
  RETURN(C);
  END IPOWER;

END DINNGB.

(* -EOF- *)
