(* ----------------------------------------------------------------------------
 * $Id: DOMAF.mi,v 1.5 1994/09/06 11:48:44 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMAF.mi,v $
 * Revision 1.5  1994/09/06  11:48:44  rose
 * modified comment
 *
 * Revision 1.4  1994/05/19  10:42:38  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1992/10/15  16:30:12  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:25  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:39  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMAF;

(* MAS Domain Modular Integer Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, LIST1;

FROM MASERR IMPORT harmless, severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetGcdFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetWritFunc, 
                    (*SetVlddFunc,*) SetDdrdFunc, SetDdwrFunc,
		    SetPNormFunc, SetPSpolFunc, SetPSugNormFunc,
		    SetPSugSpolFunc;

FROM MASBIOS IMPORT BLINES, SWRITE, CREADB, BKSP, DIGIT, LETTER, MASORD; 

FROM SACLIST IMPORT OWRITE, CLOUT, ADV2, THIRD, FIRST2, FIRST4, ADV3, 
                    LIST4, COMP2, RED2, LIST2, AREAD, AWRITE, LIST5, SECOND;

FROM SACPOL IMPORT PLBCF, VREAD, VLWRIT, PINV;

FROM SACRPOL IMPORT RPFIP, RPQR, RPRNP;

FROM SACANF IMPORT AFSUM, AFNEG, AFSIGN, AFINV, AFQ, AFDIF, AFPROD;

FROM DIPC IMPORT PFDIP, DIPFP; 

FROM DIPAGB IMPORT EDIPSUGNOR, EDIPSUGSP;

FROM DIPGB IMPORT DIPNOR, DIPSP;

FROM DIPI IMPORT DIIFRP; 

FROM DIPRN IMPORT DIRPRD, DIRPWR; 

FROM DIPRNPOL IMPORT RPONE; 

FROM SACRN IMPORT RNWRIT, RNSIGN, RNABS, RNINV, RNINT;

FROM MASRN IMPORT RNONE, RNDRD; 

FROM SACEXT8 IMPORT ANFAF, ANDWR; 

FROM SACPGCD IMPORT IPSF, IPSRP; 

FROM SACUPFAC IMPORT IUSFPF; 


(* Domain:            (dom, val, mod, modi, prime, V, iv, prec) 
   Domain descriptor:           (mod, modi, prime, V, iv, prec) 

   where: val   = algebraic number  
          mod   = modulus, univariate rational recursive polynomial  
          modi  = modulus  univariate integral recursive polynomial 
          prime = 1 if mod is prime, 2 if mod is squarefree, 0 else  
          V     = variable list
          iv    = intervall 
          prec  = write precision  
*)

CONST rcsidi = "$Id: DOMAF.mi,v 1.5 1994/09/06 11:48:44 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); (*M:=FIRST(AP);*) ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=AFDIF(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP);  
(*2*) (*compute. *) CL:=AFEXP(M,AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); 
(*2*) (*compute. *) CL:=AFFINT(A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain eleement with descriptor, 
A is an integral polynomial in 1 variables. *)
VAR   C, CL, M, BL, DL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); M:=FIRST(D); 
(*2*) (*compute. *) CL:=RPFIP(1,A); RPQR(1,CL,M, BL,DL); 
(*3*) (*create. *) C:=COMP(DL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); 
(*2*) (*compute. *) CL:=AFINV(M,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); AP:=RED2(AP);   
(*2*) (*compute. *) TL:=0; 
      IF AL <> 0 THEN TL:=FIRST(AP); (*=1 if prime*) 
         IF TL = 2 THEN TL:=0 END; 
         END; 
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); (*M:=FIRST(AP);*)
(*2*) (*compute. *) CL:=AFNEG(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=RPONE(1,AL); 
(*5*) RETURN(SL); END DONE; 


PROCEDURE DPNF(G,P: LIST): LIST;
(* domain polynomial normalform.
   G is a list of polynomials in distributive
   representation with coefficients from the domain,
   P is a polynomial as above,
   h is a polynomial such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(DIPNOR(G,P));
END DPNF;


PROCEDURE DPROD(A,B: LIST): LIST; 
(*Domain product. c=a*b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=AFPROD(M,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DPROD; 


PROCEDURE DPSP(A,B: LIST): LIST;
(* domain polynomial S-polynomial.
   A and B are polynomials in distributive representation
   with coefficients from the domain,
   S is the S-polynomial of A and B *)

BEGIN
   RETURN(DIPSP(A,B));
END DPSP;


PROCEDURE DPSUGNF(G,P: LIST): LIST;
(* domain polynomial normal with sugar strategy normalform.
   G is a list of extended polynomials in distributive
   representation with coefficients from the domain,
   P is an extended polynomial as above,
   h is an extended polynomial such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(EDIPSUGNOR(G,P));
END DPSUGNF;


PROCEDURE DPSUGSP(A,B: LIST): LIST;
(* domain polynomial normal with sugar strategy S-polynomial.
   A and B are extended polynomials in distributive representation
   with coefficients from the domain,
   S is the extended S-polynomial of A and B *)

BEGIN
   RETURN(EDIPSUGSP(A,B));
END DPSUGSP;


PROCEDURE DQUOT(A,B: LIST): LIST; 
(*Domain quotient. c=a/b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); M:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=AFQ(M,AL,BL); 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL, M, RL, V, BL, DL, DP: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); ADV(D, M,DP); V:=THIRD(DP);  
(*2*) (*read and convert. *) CL:=DIRPRD(V); 
      PFDIP(CL, RL,CL); CL:=AFHOM(M,CL);   
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL, M, AP, PL, V, I, CL, MI: LIST; 
BEGIN
(*1*) (*select. *) ADV3(A, AL,M,MI,AP); FIRST4(AP,PL,V,I,SL); 
(*2*) (*compute. *) 
      IF (SL >= 0) AND (I <> SIL) 
         THEN CL:=AFSIGN(MI,I,AL);    
         ELSE CL:=RNSIGN(PLBCF(1,AL)) END; 
(*5*) RETURN(CL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL, M: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); (* M:=FIRST(AP);*) ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=AFSUM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, AP, SL, M, I, PL, CL, N, J, V, MI: LIST; 
BEGIN
(*1*) (*advance. *) ADV3(A,AL,M,MI,AP); FIRST4(AP,PL,V,I,SL); 
(*2*) (*write. *) 
      IF SL < 0 THEN CL:=DIPFP(1,AL); DIRPWR(CL,V,-1); 
                ELSE ANFAF(MI,I,AL, N,J); ANDWR(N,J,SL); END;
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   c, R1, R2, MS, I, M, D, SL, PL, MP, V, RL, MI, WL: LIST;  
BEGIN
(*1*) (*initialization. *) M:=0; MI:=0; PL:=0; V:=SIL; I:=SIL; SL:=-1; 
      D:=COMP2(M,MI,LIST4(PL,V,I,SL)); D:=COMP(0,D); 
(*1*) (*read, syntax = (var, pol, (rn1, rn1) [,s]). *) 
      c:=CREADB(); 
      IF c <> MASORD("(") THEN BKSP; 
         ERROR(severe,"AF domain read: '(' expected."); RETURN(D) END; 
      c:=CREADB(); BKSP; 
      IF NOT LETTER(c) THEN 
         ERROR(severe,"AF domain read: 'variable' expected."); RETURN(D) END;
      V:=VREAD(); V:=LIST1(V); 
      c:=CREADB(); 
      IF c <> MASORD(",") THEN BKSP; 
         ERROR(severe,"AF domain read: ',' expected."); RETURN(D) END;
      MP:=DIRPRD(V); PFDIP(MP, RL,M); IPSRP(RL,M, WL,MI); 
      c:=CREADB(); BKSP; 
      IF c = MASORD(",") THEN c:=CREADB();  
         c:=CREADB(); 
         IF c <> MASORD("(") THEN BKSP; 
            ERROR(severe,"AF domain read: '(' expected."); RETURN(D) END;
         c:=CREADB(); 
         IF c <> MASORD(")") THEN BKSP;  
            IF NOT DIGIT(c) THEN 
               ERROR(severe,"AF domain read: 'number 1' expected."); 
               RETURN(D) END;
            R1:=RNDRD(); 
            c:=CREADB(); 
            IF c <> MASORD(",") THEN BKSP; 
               ERROR(severe,"AF domain read: ',' expected."); 
               RETURN(D) END;
            c:=CREADB(); BKSP;  
            IF NOT DIGIT(c) THEN 
               ERROR(severe,"AF domain read: 'number 2' expected."); 
               RETURN(D) END;
            R2:=RNDRD(); I:=LIST2(R1,R2); 
            c:=CREADB(); 
            IF c <> MASORD(")") THEN BKSP; 
               ERROR(severe,"AF domain read, 1: ')' expected."); 
               RETURN(D) END;
            END; 
         c:=CREADB(); BKSP; 
         IF c = MASORD(",") THEN 
            c:=CREADB(); c:=CREADB(); BKSP;  
            IF DIGIT(c) OR (c = MASORD("-")) OR (c = MASORD("+")) 
               THEN SL:=AREAD(); END; 
            END; 
         END; 
      c:=CREADB(); 
      IF c <> MASORD(")") THEN BKSP; 
         ERROR(severe,"AF domain read, 2: ')' expected."); RETURN(D) END;
(*2*) (*check for prime or squarefree. p = 0, 1, 2. *)  
      MS:=IPSF(RL,MI); 
      IF RED(MS) = SIL THEN MS:=IUSFPF(MI); PL:=1; 
         IF RED(MS) <> SIL THEN PL:=2; DIRPWR(MP,V,-1); BLINES(0); 
            ERROR(harmless,"Warning: alpha not prime. "); END; 
         ELSE DIRPWR(MP,V,-1); BLINES(0); 
              ERROR(harmless,"Warning: alpha not squarefree. "); END; 
      IF (I = SIL) OR (PL = 0) THEN SL:=-1; END; 
(*4*) (*construct descriptor. *) D:=COMP2(M,MI,LIST4(PL,V,I,SL)); 
      D:=COMP(0,D); 
(*5*) RETURN(D); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   AL, AP, SL, M, I, PL, CL, R1, R2, V, MI: LIST;
BEGIN
(*1*) (*select. *) ADV3(D,AL,M,MI,AP); FIRST4(AP,PL,V,I,SL); 
(*2*) (*write. *) SWRITE("( "); CLOUT(FIRST(V)); SWRITE(", "); 
      CL:=DIPFP(1,M); DIRPWR(CL,V,-1); 
      IF I <> SIL THEN FIRST2(I,R1,R2); 
         SWRITE(", ( "); RNWRIT(R1); SWRITE(", "); 
         RNWRIT(R2); SWRITE(" )"); 
         IF SL >= 0 THEN SWRITE(", "); AWRITE(SL); END; 
         END; 
      SWRITE(" ) (* "); 
      IF PL = 0 THEN SWRITE("reducible"); END; 
      IF PL = 1 THEN SWRITE("prime") END;
      IF PL = 2 THEN SWRITE("squarefree") END;
      SWRITE(" *) "); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DomLoadAF();
(*Domain load modular integer. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("AF","Algebraic Number"); DOMAFD:=d;
(*2*) SetDifFunc(d,DDIF); 
      SetExpFunc(d,DEXP); 
      SetFIntFunc(d,DFI); 
      SetFIPolFunc(d,DFIP); 
      SetInvFunc(d,DINV); 
      SetInvTFunc(d,DINVT); 
      SetNegFunc(d,DNEG); 
      SetOneFunc(d,DONE); 
      SetProdFunc(d,DPROD); 
      SetQuotFunc(d,DQUOT); 
      SetReadFunc(d,DREAD); 
      SetSignFunc(d,DSIGN); 
      SetSumFunc(d,DSUM); 
      SetWritFunc(d,DWRIT); 
      SetDdrdFunc(d,DDDRD); 
      SetDdwrFunc(d,DDDWR); 
(*3*) SetPNormFunc(d,DPNF);
      SetPSpolFunc(d,DPSP);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
(*9*) END DomLoadAF;



PROCEDURE AFEXP(MP,A,NL: LIST): LIST; 
(*algebraic number exponentiation.  a is an algebraic number,
nl is a non-negative beta-integer.  b=a**nl.*)
VAR  B, KL: LIST; 
BEGIN
(*1*) (*nl less than or equal to 1.*) 
      IF NL = 0 THEN B:=AFFINT(1); RETURN(B); END; 
      IF NL = 1 THEN B:=A; RETURN(B); END; 
(*2*) (*recursion.*) KL:=NL DIV 2; B:=AFEXP(MP,A,KL); 
      B:=AFPROD(MP,B,B); 
      IF NL > 2*KL THEN B:=AFPROD(MP,B,A); END; 
(*5*) RETURN(B); END AFEXP; 
 

PROCEDURE AFHOM(MP,A: LIST): LIST; 
(*Algebraic number homomorpism.  a is an univariate rational 
polynomial, b is a converted to an element of Q(alpha), for some 
algebraic number alpha. *)
VAR   B, C, BL: LIST; 
BEGIN
(*1*) (*get remainder.*) RPQR(1,A,MP, C, B); 
(*5*) RETURN(B); END AFHOM; 
 

PROCEDURE AFFINT(A: LIST): LIST; 
(*Algebraic number from integer.  a is an integer. 
b is a converted to an element of Q(alpha), for some 
algebraic number alpha. *)
VAR   B, C, BL: LIST; 
BEGIN
(*1*) (*convert. *) BL:=RNINT(A); B:=PINV(0,BL,1); 
(*5*) RETURN(B); END AFFINT; 


END DOMAF.

(* -EOF- *)
