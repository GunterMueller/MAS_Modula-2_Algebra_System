(* ----------------------------------------------------------------------------
 * $Id: MASAPF.mi,v 1.4 1998/01/05 13:03:59 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASAPF.mi,v $
 * Revision 1.4  1998/01/05 13:03:59  pesch
 * Fixed bug found by Hermann Rufenacht: FL was used instead of EL in APWRIT
 *
 * Revision 1.3  1992/10/15  16:28:09  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  13:18:59  pesch
 * Moved CONST Definition to the right place.
 *
 * Revision 1.1  1992/01/22  15:08:24  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASAPF;

(* MAS Arbitrary Precision Floating Point Implementation Module. *)



(* Import lists and Definitions *) 

FROM MASELEM IMPORT MASQREM;


FROM MASBIOS IMPORT CREAD, CREADB, GWRITE, 
                    MASORD, DIGIT, BKSP, 
                    SWRITE, BLINES;


FROM MASSTOR IMPORT LIST, SIL, BETA,
                    ADV, FIRST, RED, 
                    INV, LIST1, COMP;

FROM MASERR IMPORT ERROR, harmless, severe, fatal;


FROM SACLIST IMPORT SECOND, LIST2, CINV;


FROM SACD IMPORT ETA, THETA, ZETA;


FROM SACI IMPORT IWRITE, IDQR, IABSF, ILOG2, IEXP,
                 IDP2, IMP2, ISUM, IPROD, IPRODK, INEG,
                 ICOMP, ISIGNF, IQ, IMIN, IDPR,
                 IDIF, IREAD;
                 

FROM SACRN IMPORT RNDEN, RNNUM, RNRED, RNDIF, 
                  RNINT, RNPROD, RNSUM;
                  
 
VAR APPR2, APP10: LIST;
    msg: BOOLEAN;


CONST rcsidi = "$Id: MASAPF.mi,v 1.4 1998/01/05 13:03:59 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE APCOMP(ML,EL: LIST): LIST;
(*Arbitrary precision floating point composition. e is the
exponent, m is the mantissa of the arbitrary precision
floating point number A.*)
BEGIN
(*1*) RETURN( COMP(EL, COMP(ML,SIL) ) );
(*9*) END APCOMP; 


PROCEDURE APMANT(A: LIST): LIST;
(*Arbitrary precision floating point mantissa. m is the mantissa 
of the arbitrary precision floating point number A.*)
BEGIN
(*1*) RETURN( FIRST(RED(A)) );
(*9*) END APMANT;
      

PROCEDURE APEXPT(A: LIST): LIST;
(*Arbitrary precision floating point exponent. e is the
exponent of the arbitrary precision floating point number A.*)
BEGIN
(*1*) RETURN( FIRST(A) );
(*9*) END APEXPT; 


PROCEDURE ILOG10(N: LIST): LIST;
(*Integer logarithm base 10.
N is an integer, l is a beta integer. l=LOG10(ABS(N)).*)
VAR  L, R, S: LIST;
BEGIN
(*1*) (*n=0 or 1.*) L:=0;
      IF N = 0 THEN RETURN(L); END;
      S:=IABSF(N);
      IF S = 1 THEN RETURN(L); END;
(*2*) (*divide.*)
      REPEAT IDQR(S,THETA,S,R); L:=L+ETA;
             UNTIL S = 0;
      L:=L-ETA; S:=R;
      REPEAT MASQREM(S,10,S,R); L:=L+1;
             UNTIL S = 0;
      L:=L-1;
      IF R <> 0 THEN L:=L+1; END;
(*3*) (*finish.*) RETURN(L);
(*6*) END ILOG10;


PROCEDURE APSPRE(N: LIST);
(*Arbitrary precision floating point set precision.
N is the desired precision of the floating point numbers.*)
VAR  J1Y, L, M, QL, RL: LIST;
BEGIN
(*1*) (*set precision.*) M:=IEXP(10,N); L:=ILOG2(M)+1; 
      MASQREM(L,ZETA,QL,RL);
      IF RL <> 0 THEN L:=L+ZETA-RL; END;
      L:=L-1; APPR2:=L; APP10:=N;
(*2*) (*generate message.*)
      IF msg THEN
         SWRITE("Floating point precision set to "); IWRITE(N);
         SWRITE(" digits = "); IWRITE(L); SWRITE(" bits. "); BLINES(0);
         END;
(*3*) (*finish.*) RETURN;
(*6*) END APSPRE;


PROCEDURE APFINT(N: LIST): LIST;
(*Arbitrary precision floating point from integer.
The integer N is converted to the arbitrary precision
floating point number A.*)
VAR  A, EL, FL, ML: LIST;
BEGIN
(*1*) (*n=0.*)
      IF N = 0 THEN A:=APCOMP(0,0); RETURN(A); END;
(*2*) (*normalize.*) EL:=ILOG2(N); FL:=EL-1-APPR2; (*1=log2(2).*)
      IF FL >= 0 
         THEN ML:=IDP2(N,FL); (*truncate*)   
         ELSE ML:=IMP2(N,-FL); (*fill up*) END; 
(*3*) (*round.*) ML:=ISUM(ML,1); 
      ML:=IDP2(ML,1);
(*4*) (*finish.*) A:=APCOMP(ML,EL); RETURN(A);
(*6*) END APFINT;



PROCEDURE APSHFT(B,EL: LIST): LIST;
(*Arbitrary precision floating point shift.
The arbitrary precision floating point number B is multiplied by 2**e.
A is an arbitrary precision floating point number.*)
VAR  A, FL, J1Y, J2Y, ML: LIST;
BEGIN
(*1*) (*b=0.*) ML:=APMANT(B);
      IF ML = 0 THEN A:=APCOMP(0,0); RETURN(A); END;
(*2*) (*shift and check.*) FL:=APEXPT(B)+EL; 
      IF FL >= BETA THEN
         ERROR(severe,"arbitrary precision floating point OVERFLOW");
         BLINES(1); SWRITE("Mantissa="); IWRITE(ML); BLINES(1);
         SWRITE("Exponent="); GWRITE(APEXPT(B)); BLINES(1);
         SWRITE("EL       ="); GWRITE(EL); BLINES(1);
         SWRITE("FL       ="); GWRITE(FL); BLINES(2); J1Y:=APPR2+1;
         J1Y:=IMP2(1,J1Y); J2Y:=-1; ML:=ISUM(J1Y,J2Y); FL:=BETA-1; END;
      IF FL <= -BETA THEN
         ERROR(severe,"arbitrary precision floating point UNDERFLOW");
         BLINES(1); SWRITE("Mantissa="); IWRITE(ML); BLINES(1);
         SWRITE("Exponent="); GWRITE(APEXPT(B)); BLINES(1);
         SWRITE("EL       ="); GWRITE(EL); BLINES(1);
         SWRITE("FL       ="); GWRITE(FL); BLINES(2); ML:=0; FL:=0; END;
(*3*) (*finish.*) A:=APCOMP(ML,FL); RETURN(A);
(*6*) END APSHFT;


PROCEDURE APSIGN(A: LIST): LIST;
(*Arbitrary precision floating point sign. A is an arbitrary precision 
floating point number, s is the sign of A.*)
VAR  ML, SL: LIST;
BEGIN
(*1*) (*get mantissa.*) ML:=APMANT(A);
(*2*) (*integer sign.*) SL:=ISIGNF(ML);
(*3*) (*finish.*) RETURN(SL);
      END APSIGN;


PROCEDURE APWRIT(A: LIST);
(*Arbitrary precision floating point write.
The arbitrary precision floating point number A is written to
the output stream.*)
VAR  AP, SL, B, EL, GL, J1Y, ML, Z: LIST;
BEGIN
(*1*) (*a=0.*) ML:=APMANT(A);
      IF ML = 0 THEN SWRITE("0.0"); RETURN; END;
(*2*) (*multiply by 10**(-log10(a)). *) SL:=APSIGN(A); AP:=APABS(A);
      ML:=APMANT(AP); 
      Z:=APFINT(10); EL:=APLG10(AP); 
      IF EL > 0 
         THEN J1Y:=APEXP(Z,EL);  B:=APQ(AP,J1Y); 
         ELSE J1Y:=APEXP(Z,-EL); B:=APPROD(AP,J1Y); END;
(*3*) (*convert to ml*10**el.*) 
      ML:=APMANT(B); GL:=APEXPT(B); (* now: 0 <= gl <= 3 *)
      IF GL > 0 THEN ML:=IMP2(ML,GL); ML:=ISUM(ML,1); 
         EL:=EL+1; END;
      J1Y:=IEXP(10,APP10); 
      ML:=IPROD(ML,J1Y);
      ML:=IDP2(ML,APPR2);
(*4*) (*write.*) IF SL < 0 THEN SWRITE("-"); END; 
      SWRITE("0."); IWRITE(ML); 
      SWRITE("E");IWRITE(EL);
(*5*) (*finish.*) RETURN;
(*8*) END APWRIT;


PROCEDURE APNEG(A: LIST): LIST;
(*Arbitrary precision floating point negative.
The arbitrary precision floating point number A is negated.
B= -A.*)
VAR  B, EL, ML: LIST;
BEGIN
(*1*) (*negate.*) ML:=APMANT(A); ML:=INEG(ML); EL:=APEXPT(A);
      B:=APCOMP(ML,EL);
(*2*) (*finish.*) RETURN(B);
(*5*) END APNEG;


PROCEDURE APABS(A: LIST): LIST;
(*Arbitrary precision floating point absolute value.
A is a arbitrary precision floating point number.
B is the absolute value of A.*)
VAR  B, EL, ML: LIST;
BEGIN
(*1*) (*absolute value.*) ML:=APMANT(A); ML:=IABSF(ML); EL:=APEXPT(A);
      B:=APCOMP(ML,EL);
(*2*) (*finish.*) RETURN(B);
(*5*) END APABS;


PROCEDURE APCMPR(A,B: LIST): LIST;
(*Arbitrary precision floating point compare.
A and B are arbitrary precision floating point numbers.
s is the sign of the difference of A and B. s=SIGN(A-B).*)
VAR  EL1, EL2, ML1, ML2, SL, SL1, SL2: LIST;
BEGIN
(*1*) (*compare signs.*) ML1:=APMANT(A); ML2:=APMANT(B);
      SL1:=ISIGNF(ML1); SL2:=ISIGNF(ML2); SL:=ICOMP(SL1,SL2);
      IF SL <> 0 THEN RETURN(SL); END;
(*2*) (*equal signs.*) EL1:=APEXPT(A); EL2:=APEXPT(B);
      SL:=ICOMP(EL1,EL2);
      IF SL = 0 THEN SL:=ICOMP(ML1,ML2); END;
(*3*) (*finish.*) SL:=SL*SL1; RETURN(SL);
(*6*) END APCMPR;


PROCEDURE APNELD(A,B: LIST): LIST;
(*Arbitrary precision floating point number of equal leading digits.
A and B are arbitrary precision floating point numbers.
l is the number of equal leading digits of A and B.*)
VAR  EL1, EL2, J1Y, LL, ML1, ML2, NL1, NL2, PL, PL1, PL2, SL, SL1,
     SL2: LIST;
BEGIN
(*1*) (*compare signs.*) LL:=0; ML1:=APMANT(A); ML2:=APMANT(B);
      SL1:=ISIGNF(ML1); SL2:=ISIGNF(ML2); SL:=ICOMP(SL1,SL2);
      IF SL <> 0 THEN RETURN(LL); END;
(*2*) (*compare exponents.*) EL1:=APEXPT(A); EL2:=APEXPT(B);
      SL:=ICOMP(EL1,EL2);
      IF SL <> 0 THEN RETURN(LL); END;
(*3*) (*compare digits. ml1 and ml2 have same length.*)
      IF ML1 < BETA THEN ML1:=LIST1(ML1); END;
      IF ML2 < BETA THEN ML2:=LIST1(ML2); END;
      NL1:=CINV(ML1); NL2:=CINV(ML2);
      REPEAT ADV(NL1,PL1,NL1); ADV(NL2,PL2,NL2);
             IF PL1 = PL2 THEN LL:=LL+ZETA; ELSE PL:=PL1-PL2;
                J1Y:=ILOG2(PL); J1Y:=ZETA-J1Y; LL:=LL+J1Y; RETURN(LL);
                END;
             UNTIL NL1 = SIL;
(*4*) (*finish.*) RETURN(LL);
(*7*) END APNELD;


PROCEDURE APPROD(A,B: LIST): LIST;
(*Arbitrary precision floating point product.
A, B and C are arbitrary precision floating point numbers.
C is the product of A and B. C=A*B.*)
VAR  C, EL, EL1, EL2, J1Y, ML, ML1, ML2: LIST;
BEGIN
(*1*) (*multiply mantisa and normalise.*) ML1:=APMANT(A);
      ML2:=APMANT(B); ML:=IPRODK(ML1,ML2); C:=APFINT(ML);
(*2*) (*add exponents and shift.*) EL1:=APEXPT(A); EL2:=APEXPT(B);
      J1Y:=EL1+EL2; J1Y:=J1Y-APPR2; EL:=J1Y-APPR2; C:=APSHFT(C,EL);
(*3*) (*finish.*) RETURN(C);
(*6*) END APPROD;


PROCEDURE APQ(A,B: LIST): LIST;
(*Arbitrary precision floating point quotient.
A, B and C are arbitrary precision floating point numbers.
C is the quotient of A and B. C=A/B.*)
VAR  C, EL, EL1, EL2, ML, ML1, ML2, MR, MQ: LIST;
BEGIN
(*1*) (*divide mantisa and normalise.*) ML1:=APMANT(A);
      ML2:=APMANT(B); ML:=IMP2(ML1,APPR2+1); 
      ML:=IQ(ML,ML2);  C:=APFINT(ML);
(*2*) (*subtract exponents and shift.*) EL1:=APEXPT(A);
      EL2:=APEXPT(B); EL:=EL1-APPR2-1-EL2;
      C:=APSHFT(C,EL);
(*3*) (*finish.*) RETURN(C);
(*6*) END APQ;


PROCEDURE APSUM(A,B: LIST): LIST;
(*Arbitrary precision floating point sum.
A, B and C are arbitrary precision floating point numbers.
C is the sum of A and B. C=A+B.*)
VAR  C, EL, EL1, EL2, J1Y, ML, ML1, ML2: LIST;
BEGIN
(*1*) (*normalize mantisa and add.*) EL1:=APEXPT(A); EL2:=APEXPT(B);
      EL:=IMIN(EL1,EL2); ML1:=APMANT(A); ML2:=APMANT(B); J1Y:=EL1-EL;
      ML1:=IMP2(ML1,J1Y); J1Y:=EL2-EL; ML2:=IMP2(ML2,J1Y);
      ML:=ISUM(ML1,ML2); C:=APFINT(ML);
(*2*) (*shift.*) EL:=EL-APPR2; C:=APSHFT(C,EL);
(*3*) (*finish.*) RETURN(C);
(*6*) END APSUM;


PROCEDURE APDIFF(A,B: LIST): LIST;
(*Arbitrary precision floating point difference.
A, B and C are arbitrary precision floating point numbers.
C is the difference of A and B. C=A-B.*)
VAR  C, XL: LIST;
BEGIN
(*1*) (*add negative.*) C:=APNEG(B); C:=APSUM(A,C);
(*2*) (*finish.*) RETURN(C);
(*5*) END APDIFF;


PROCEDURE APLG10(A: LIST): LIST;
(*Arbitrary precision floating point logarithm base 10.
A is an arbitrary precision floating point number,
l is a beta integer, l=LOG10(ABS(A)). *)
VAR  EL, FL, J1Y, L, S, XL, Z: LIST;
BEGIN
(*1*) (*initialize.*) L:=0;
      IF APMANT(A) = 0 THEN 
         ERROR(fatal,"APLG10, logarithm of 0 undefined"); RETURN(L); END;
      S:=APABS(A);
(*2*) (*divide and multiply by theta.*) J1Y:=APEXPT(S);
      FL:=IABSF(J1Y); XL:=ILOG2(THETA);
      IF FL > XL THEN
         IF FL > 50*XL THEN ERROR(severe,"APLG10 is not efficient") END;
         Z:=APFINT(THETA); EL:=APEXPT(Z);
         WHILE APEXPT(S) >= EL DO S:=APQ(S,Z); L:=L+ETA; END;
         WHILE APEXPT(S) <  0  DO S:=APPROD(S,Z); L:=L-ETA; END;
         END;
(*3*) (*divide and multiply by 10.*) Z:=APFINT(10); EL:=APEXPT(Z);
      WHILE APEXPT(S) >= EL DO S:=APQ(S,Z); L:=L+1; END;
      WHILE APEXPT(S) <  0  DO S:=APPROD(S,Z); L:=L-1; END;
(*4*) (*finish.*) RETURN(L);
(*7*) END APLG10;


PROCEDURE APEXP(A,NL: LIST): LIST;
(*Arbitrary precision floating point exponentiation.
A and B are arbitrary precision floating point numbers.
n is a beta-integer.  B=A**n.*)
VAR  B, J1Y, KL, XL: LIST;
BEGIN
(*1*) (*trivial cases.*)
      IF NL = 0 THEN B:=APFINT(1); RETURN(B); END;
      IF NL = 1 THEN B:=A; RETURN(B); END;
(*2*) (*nl negative.*)
      IF NL < 0 THEN J1Y:=-NL; B:=APEXP(A,J1Y); J1Y:=APFINT(1);
         B:=APQ(J1Y,B); RETURN(B); END;
(*3*) (*recursion.*) KL:=NL DIV 2; B:=APEXP(A,KL); B:=APPROD(B,B);
      IF NL > KL*2 THEN B:=APPROD(B,A); END;
(*4*) (*finish.*) RETURN(B);
(*7*) END APEXP;


PROCEDURE APFRN(A: LIST): LIST;
(*Arbitrary precision floating point from rational number.
B is an arbitrary precision floating point number.
A is a rational number.*)
VAR  A1, A2, B, B1, B2, XL: LIST;
BEGIN
(*1*) (*a=0.*)
      IF A = 0 THEN B:=APFINT(0); RETURN(B); END;
(*2*) (*convert numerator and denomiator.*) A1:=RNNUM(A);
      A2:=RNDEN(A); B1:=APFINT(A1); B2:=APFINT(A2);
(*3*) (*divide.*) B:=APQ(B1,B2);
(*4*) (*finish.*) RETURN(B);
(*7*) END APFRN;


PROCEDURE RNFAP(A: LIST): LIST;
(*Rational number from arbitrary precision floating point.
A is an arbitrary precision floating point number.
B is a rational number.*)
VAR  B, B1, B2, EL, J1Y, ML, XL: LIST;
BEGIN
(*1*) (*a=0.*) ML:=APMANT(A);
      IF ML = 0 THEN B:=0; RETURN(B); END;
      EL:=APEXPT(A);
(*2*) (*convert mantisa and exponent.*) B1:=ML; B2:=IMP2(1,APPR2);
      IF EL >= 0 THEN B1:=IMP2(B1,EL); ELSE J1Y:=-EL;
         B2:=IMP2(B2,J1Y); END;
(*3*) (*reduce to lowest terms.*) B:=RNRED(B1,B2);
(*4*) (*finish.*) RETURN(B);
(*7*) END RNFAP;


PROCEDURE RNDRD(): LIST;
(*Rational number decimal read.  The rational number R is read
from the input stream.  Any preceding blanks are skipped.*)
VAR  A, B, BL, BLP, C, EL, IL, J1Y, JL, R, R1, R2, RP, s: LIST;
BEGIN
(*1*) (*rational number read.*) C:=CREADB(); BKSP; 
      IF C = MASORD("-") THEN s:=-1 ELSE s:=1 END; 
      R1:=IREAD(); C:=CREAD();
      IF C <> MASORD(".") THEN
         IF C = MASORD("/") THEN R2:=IREAD(); ELSE R2:=1; BKSP; END;
         R:=RNRED(R1,R2); RETURN(R); END;
(*2*) (*read decimal fraction.*) JL:=-1;
      REPEAT C:=CREAD(); JL:=JL+1;
             UNTIL C <> 0;
(*3*) (*fraction=0.*)
      IF NOT DIGIT(C) THEN BKSP; 
         IF C <> MASORD("E") THEN R:=RNINT(R1); RETURN(R)
                             ELSE C:=0 END;
         END;
      A:=0;
(*4*) (*compute theta-digits.*) B:=SIL; BL:=0; IL:=0;
      REPEAT J1Y:=10*BL; BL:=J1Y+C; IL:=IL+1;
             IF IL = ETA THEN B:=COMP(BL,B); BL:=0; IL:=0; END;
             JL:=JL+1; C:=CREAD();
             UNTIL NOT DIGIT(C);
      BKSP;
(*5*) (*convert to base beta.*) B:=INV(B);
      WHILE B <> SIL DO A:=IDPR(A,THETA); ADV(B,BLP,B);
            A:=ISUM(A,BLP); END;
      IF A <> 0 THEN J1Y:=IEXP(10,IL); A:=IDPR(A,J1Y); END;
      A:=ISUM(A,BL); R2:=IEXP(10,JL); R:=RNRED(A,R2); 
      RP:=RNINT(R1);
      IF s < 0 THEN R:=RNDIF(RP,R); ELSE R:=RNSUM(RP,R) END;
(*6*) (*read floating point exponent.*) C:=CREAD(); 
      IF C <> MASORD("E") THEN BKSP; RETURN(R); END;
      EL:=IREAD();
      IF EL >= 0 
         THEN J1Y:=IEXP(10,EL);  RP:=RNRED(J1Y,1); 
         ELSE J1Y:=IEXP(10,-EL); RP:=RNRED(1,J1Y); END;
      R:=RNPROD(R,RP); RETURN(R);
(*9*) END RNDRD;


PROCEDURE APROOT(A,NL: LIST): LIST;
(*Arbitrary precision floating point n-th root.
A and B are arbitrary precision floating point numbers.
B is the n-th root of A.*)
VAR   B, KL, KL1, NL1, PR, SL, W, WH, WP, WS: LIST;
BEGIN
(*1*) (*initialize.*) PR:=(APPR2 DIV 2)+4; WP:=APFINT(1);
      IF NL = 0 THEN B:=WP; RETURN(B); END;
(*2*) (*square root only.*)
      IF NL = 2 THEN 
         REPEAT WS:=WP; W:=APQ(A,WS); W:=APSUM(WS,W); 
                WP:=APSHFT(W,-1); (*/2*) SL:=APNELD(WP,WS);
                UNTIL SL >= PR;
         B:=WP; RETURN(B);
         END;
(*3*) (*newtons loop for n-th root.*) KL:=APFINT(NL);
      NL1:=NL-1; KL1:=APFINT(NL1); 
      REPEAT WS:=WP; W:=APEXP(WS,NL1); W:=APQ(A,W); WH:=APPROD(WS,KL1);
             W:=APSUM(WH,W); WP:=APQ(W,KL); SL:=APNELD(WP,WS);
             UNTIL SL >= PR;
      B:=WP;
(*3*) (*finish.*) RETURN(B);
(*6*) END APROOT;


PROCEDURE APPI(): LIST;
(*Arbitrary precision floating point pi.
pi is an arbitrary precision floating point number. *)
VAR   A, B, C, D, EINS, F, J, P, PI, PR, S, SL, XL, ZWEI:
      LIST;
BEGIN
(*1*) (*set precision and initialize.*) PR:=(APPR2 DIV 2)+4;
      EINS:=APFINT(1); ZWEI:=APFINT(2); 
      A:=EINS; J:=APROOT(ZWEI,2); B:=APQ(EINS,J); C:=B;
      S:=APFINT(0); P:=1;
(*2*) (*arithmetic geometric mean loop.*) 
      REPEAT F:=A; J:=APSUM(F,B); A:=APSHFT(J,-1); (*/2*)
             J:=APDIFF(F,B); C:=APSHFT(J,-1); (*/2*) J:=APPROD(F,B);
             B:=APROOT(J,2); P:=P+1; J:=APSHFT(C,P); (* *2**P *)
             J:=APPROD(C,J); S:=APSUM(J,S); SL:=APNELD(A,B);
             UNTIL SL >= PR;
(*3*) (*compute pi.*) D:=APDIFF(EINS,S); J:=APSHFT(B,2); (* *4 *)
      J:=APPROD(A,J); PI:=APQ(J,D);
(*4*) (*finish.*) RETURN(PI);
(*7*) END APPI;


BEGIN 
(* Initialization. *)

msg:=FALSE;
APSPRE(20);
msg:=TRUE;

END MASAPF.


(* -EOF- *)
