(* ----------------------------------------------------------------------------
 * $Id: DOMI.mi,v 1.8 1994/11/28 20:56:29 dolzmann Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMI.mi,v $
 * Revision 1.8  1994/11/28  20:56:29  dolzmann
 * New function for the computation of the content and the primitive part of a
 * polynomial.
 *
 * Revision 1.7  1994/06/10  12:04:29  pfeil
 * Added Procedures DPSFF, DPFAC for DIPDCGB
 *
 * Revision 1.6  1994/05/19  10:42:51  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.5  1993/05/11  10:36:04  kredel
 * Added QR, REM, ... support
 *
 * Revision 1.4  1992/10/15  16:30:15  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/06/12  13:39:37  kredel
 * Added extended GCD for integers.
 *
 * Revision 1.2  1992/02/12  17:31:28  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:43  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMI;

(* MAS Domain Integer Implementation Module. *)



(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, LIST1, BETA, INV; 

FROM MASBIOS IMPORT SWRITE, BLINES;

FROM MASERR IMPORT severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetGcdFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetWritFunc, 
                    SetGcdcFunc, SetGcdeFunc,
                    SetQrFunc, SetRemFunc, SetCompFunc, SetAbsFunc, 
                    (*SetVlddFunc,*) SetDdrdFunc, SetDdwrFunc,
		    SetPSqfrFunc, SetPFactFunc, SetPNormFunc,
		    SetPSpolFunc, SetPSugNormFunc, SetPSugSpolFunc,
		    SetPCppFunc;

FROM SACI IMPORT ISUM, ISIGNF, IABSF, IREAD, IWRITE, INEG, 
                 IGCD, ILCM, IQR, IEXP, IDIF, ICOMP, IPROD, 
                 IEGCD, IGCDCF;

FROM SACLIST IMPORT FIRST2, LIST2;

FROM DIPC IMPORT PFDIP, DIPFP;

FROM DIPTOOLS IMPORT DIPCPP; 

FROM SACPFAC IMPORT IPFAC;

FROM MASPGCD IMPORT IPSFF;

FROM DIPGB IMPORT DIIFNF, DIIFSP;

FROM DIPAGB IMPORT EDIIFSUGNF, EDIIFSUGSP;

(* Domain:            (dom, val) 
   Domain descriptor:          () 

   where: val = integer  
*)

CONST rcsidi = "$Id: DOMI.mi,v 1.8 1994/11/28 20:56:29 dolzmann Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE DABS(A: LIST): LIST; 
(*Domain absolute value. c=abs(a). *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) CL:=IABSF(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DABS; 


PROCEDURE DCOMP(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) SL:=ICOMP(AL,BL);
(*6*) RETURN(SL); END DCOMP; 


PROCEDURE DPCPP(P:LIST; VAR c,pp: LIST);
(* domain polynomial content and primitive part. *)
BEGIN
	DIPCPP(P,c,pp);
	RETURN;
END DPCPP;


PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IDIF(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) CL:=IEXP(AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);  
(*2*) (*compute. *) CL:=A;
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain element with descriptor, 
A is an integral polynomial in 0 variables, so it is an integer. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);  
(*2*) (*compute. *) CL:=A;
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DGCD(A,B: LIST): LIST; 
(*Domain greatest common divisor. c=gcd(a,b). *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IGCD(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DGCD; 


PROCEDURE DGCDE(A,B: LIST; VAR C,AS,BS: LIST); 
(*Domain extendend greatest common divisor. c=gcd(a,b). 
as=a/c, bs=b/c. *)
VAR   AL, AP, BL, BP, CL, ALS, BLS: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IEGCD(AL,BL, CL,ALS,BLS);
(*3*) (*create. *) C:=COMP(CL,AP); AS:=COMP(ALS,AP); BS:=COMP(BLS,AP); 
(*7*) END DGCDE; 


PROCEDURE DGCDC(A,B: LIST; VAR C,AS,BS: LIST); 
(*Domain greatest common divisor and cofactors. c=gcd(a,b). 
c=a*as+b*bs. *)
VAR   AL, AP, BL, BP, CL, ALS, BLS: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IGCDCF(AL,BL, CL,ALS,BLS);
(*3*) (*create. *) C:=COMP(CL,AP); AS:=COMP(ALS,AP); BS:=COMP(BLS,AP); 
(*7*) END DGCDC; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) IQR(1,AL, CL,RL); 
      IF RL <> 0 THEN IWRITE(RL); 
         ERROR(severe,"Remainder non zero in integer INV"); END; 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*2*) (*compute. *) TL:=IABSF(AL); 
      IF TL <> 1 THEN TL:=0 END;
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DLCM(A,B: LIST): LIST; 
(*Domain least common multiple. c=lcm(a,b). *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=ILCM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DLCM; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) CL:=INEG(AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*compute. *) SL:=AL; IF SL <> 1 THEN SL:=0  END;
(*5*) RETURN(SL); END DONE; 


PROCEDURE DPNF(G,P: LIST): LIST;
(* domain polynomial normalform.
   G is a list of polynomials in distributive
   representation with coefficients from the domain,
   P is a polynomial as above,
   returns a polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(DIIFNF(G,0,P));
END DPNF;


PROCEDURE DPROD(A,B: LIST): LIST; 
(*Domain product. c=a*b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IPROD(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DPROD; 


PROCEDURE DPSP(A,B: LIST): LIST;
(* domain polynomial S-polynomial.
   A and B are polynomials in distributive representation
   with coefficients from the domain,
   returns the S-polynomial of A and B *)

BEGIN
   RETURN(DIIFSP(A,B));
END DPSP;


PROCEDURE DPSUGNF(G,P: LIST): LIST;
(* domain polynomial normal with sugar strategy normalform.
   G is a list of extended polynomials in distributive
   representation with coefficients from the domain,
   P is an extended polynomial as above,
   returns an extended polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(EDIIFSUGNF(G,P));
END DPSUGNF;


PROCEDURE DPSUGSP(A,B: LIST): LIST;
(* domain polynomial normal with sugar strategy S-polynomial.
   A and B are extended polynomials in distributive representation
   with coefficients from the domain,
   returns the extended S-polynomial of A and B *)

BEGIN
   RETURN(EDIIFSUGSP(A,B));
END DPSUGSP;


PROCEDURE DQR(A,B: LIST; VAR Q,R:LIST); 
(*Domain quotient and remainder. q=a/b, r=a-b*(a/b), r nonnegative. *)
VAR   AL, AP, BL, BP, QL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IQR(AL,BL, QL,RL); 
      IF ISIGNF(RL) < 0 THEN 
         IF ISIGNF(BL) > 0  (* = 0 not possible *)
            THEN RL:=ISUM(RL,BL); QL:=ISUM(QL,-1); 
            ELSE RL:=IDIF(RL,BL); QL:=ISUM(QL,1); END;   
         END; 
(*3*) (*create. *) Q:=COMP(QL,AP); R:=COMP(RL,AP); 
(*6*) RETURN END DQR; 


PROCEDURE DQUOT(A,B: LIST): LIST; 
(*Domain quotient. c=a/b. *)
VAR   AL, AP, BL, BP, Q, QL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IQR(AL,BL, QL,RL); 
      IF ISIGNF(RL) < 0 THEN 
         IF ISIGNF(BL) > 0  (* = 0 not possible *)
            THEN QL:=ISUM(QL,-1); 
            ELSE QL:=ISUM(QL,1); END;   
         END; 
(*3*) (*create. *) Q:=COMP(QL,AP); 
(*6*) RETURN(Q); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is the domain element with descriptor. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);  
(*2*) (*read. *) CL:=IREAD(); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DREM(A,B: LIST): LIST; 
(*Domain remainder. r=a-b*(a/b), r nonnegative. *)
VAR   AL, AP, BL, BP, R, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IQR(AL,BL, CL,RL); 
      IF ISIGNF(RL) < 0 THEN 
         IF ISIGNF(BL) > 0  (* = 0 not possible *)
            THEN RL:=ISUM(RL,BL);  
            ELSE RL:=IDIF(RL,BL); END;   
         END; 
(*3*) (*create. *) R:=COMP(RL,AP); 
(*6*) RETURN(R); END DREM; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*compute. *) SL:=ISIGNF(AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=ISUM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL: LIST; 
BEGIN
(*1*) (*advance. *) AL:=FIRST(A); 
(*2*) (*write. *) IWRITE(AL);
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
BEGIN
(*5*) RETURN(LIST1(0)); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
BEGIN
(*5*) RETURN; END DDDWR; 


PROCEDURE DPFAC(P: LIST): LIST;
(* domain polynomial factorization.
   P is a polynomial in distributive representation
   with coefficients from the domain,
   returns a list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where P = u * f1**e1 * ... * fk**ek and u unit. *)
VAR r,S,C,F,F1,ExpPol,exp,pol: LIST;
BEGIN
   PFDIP(P,r,P);	(* distributive to recursive *)
   IPFAC(r,P,S,C,F);	(* factorization *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);
      FIRST2(ExpPol,exp,pol);
      pol:=DIPFP(r,pol);	(* recursive to distributive *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END DPFAC;


PROCEDURE DPSFF(A: LIST): LIST;
(* domain polynomial squarefree factorization.
   A is a polynomial in distributive representation
   with coefficients from the domain,
   returns a list ((e1,p1),...,(ek,pk)), ei positive integers,
   pi squarefree polynomials in distributive representation,
   where A = u * p1**e1 * ... * pk**ek and u unit. *)
VAR r,F,F1,ExpPol,exp,pol: LIST;
BEGIN
   PFDIP(A,r,A);	(* distributive to recursive *)
   F:=IPSFF(r,A);	(* squarefree factorization *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);
      FIRST2(ExpPol,exp,pol);
      pol:=DIPFP(r,pol);	(* recursive to distributive *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END DPSFF;


PROCEDURE DomLoadI();
(*Domain load integer. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("INT","Integer"); DOMINT:=d;
(*2*) SetAbsFunc(d,DABS); 
      SetCompFunc(d,DCOMP); 
      SetDifFunc(d,DDIF); 
      SetExpFunc(d,DEXP); 
      SetFIntFunc(d,DFI); 
      SetFIPolFunc(d,DFIP); 
      SetGcdFunc(d,DGCD); 
      SetGcdeFunc(d,DGCDE); 
      SetGcdcFunc(d,DGCDC); 
      SetInvFunc(d,DINV); 
      SetInvTFunc(d,DINVT); 
      SetLcmFunc(d,DLCM); 
      SetNegFunc(d,DNEG); 
      SetOneFunc(d,DONE); 
      SetProdFunc(d,DPROD); 
      SetQrFunc(d,DQR); 
      SetQuotFunc(d,DQUOT); 
      SetReadFunc(d,DREAD); 
      SetRemFunc(d,DREM); 
      SetSignFunc(d,DSIGN); 
      SetSumFunc(d,DSUM); 
      SetWritFunc(d,DWRIT); 
      SetDdrdFunc(d,DDDRD); 
      SetDdwrFunc(d,DDDWR); 
(*3*) SetPNormFunc(d,DPNF);
      SetPFactFunc(d,DPFAC);
      SetPSpolFunc(d,DPSP);
      SetPSqfrFunc(d,DPSFF);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
      SetPCppFunc(d,DPCPP);
(*9*) END DomLoadI;


END DOMI.
(* -EOF- *)





