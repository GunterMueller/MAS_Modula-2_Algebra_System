(* ----------------------------------------------------------------------------
 * $Id: DOMRP.mi,v 1.5 1994/06/06 16:06:55 rose Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMRP.mi,v $
 * Revision 1.5  1994/06/06  16:06:55  rose
 * Minor corrections.
 *
 * Revision 1.4  1994/05/19  10:43:13  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.3  1993/05/11  10:36:05  kredel
 * Added QR, REM, ... support
 *
 * Revision 1.2  1992/10/15  16:30:22  kredel
 * Changed rcsid variable
 *
 * Revision 1.1  1992/06/12  13:48:04  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMRP;

(* MAS Domain Integral Polynomial Implementation Module. *)


(* Import lists and declarations. *)

FROM MASSTOR IMPORT LIST, ADV, FIRST, RED, SIL, COMP, LENGTH;

FROM MASERR IMPORT  severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetGcdFunc, SetGcdeFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetWritFunc, 
                    SetQrFunc, SetRemFunc, SetCompFunc, SetAbsFunc, 
                    SetVlddFunc, SetDdrdFunc, SetDdwrFunc, 
		    SetPNormFunc, SetPSpolFunc, SetPSugNormFunc,
                    SetPSugSpolFunc;

FROM SACLIST IMPORT LIST2, ADV2, SECOND, LIST3;

FROM SACRN IMPORT RNINT;

FROM SACPOL IMPORT PINV, VLWRIT, VLREAD;

FROM SACRPOL IMPORT RPSUM, RPPROD, RPNEG, RPQR, RPDIF, RPFIP;

FROM DIPC IMPORT PFDIP, DIPFP; 

FROM DIPRN IMPORT DIRPWR, DIRPRD;

FROM DIPRNPOL IMPORT RPONE, RPEXP, RPCONST, RPSIGN, RPABS, 
              RUPGCD, RUPEGC, RUPLCM;

FROM DIPAGB IMPORT EDIIFSUGNF, EDIIFSUGSP;

FROM DIPGB IMPORT DIIFNF, DIIFSP;


CONST rcsidi = "$Id: DOMRP.mi,v 1.5 1994/06/06 16:06:55 rose Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


(* Domain:            (dom, val, r, V) 
   Domain descriptor:           (r, V) 

   where: val = rational recursive polynomial 
          r   = number of variables, 
          V   = variable list
*)

PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL, RL:LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RPDIF(RL,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) CL:=RPEXP(RL,AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL, RL, AL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); RL:=FIRST(D);
(*2*) (*compute. *) AL:=RNINT(A); CL:=PINV(0,AL,RL); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain element with descriptor, 
A is an integral polynomial in #vldd(D) variables. *)
VAR   C, CL, RL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D); RL:=FIRST(D);
(*2*) (*compute. *) CL:=RPFIP(RL,A);
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DGCD(A,B: LIST): LIST; 
(*Domain greatest common divisor. c=gcd(a,b). *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
      IF RL <> 1 THEN  
         ERROR(severe,"Only rational univariate polynomial in GCD"); 
         END; 
(*2*) (*compute. *) CL:=RUPGCD(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DGCD; 


PROCEDURE DGCDE(A,B: LIST; VAR C,U,V: LIST); 
(*Domain greatest common divisor and linear combination. c=gcd(a,b).
c=u*a+v*b.  *)
VAR   AL, AP, BL, BP, CL, RL, UL, VL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
      IF RL <> 1 THEN  
         ERROR(severe,"Only rational univariate polynomial in EGCD"); 
         END; 
(*2*) (*compute. *) RUPEGC(AL,BL, CL,UL,VL);
(*3*) (*create. *) C:=COMP(CL,AP); U:=COMP(UL,AP); V:=COMP(VL,AP); 
(*7*) END DGCDE; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, QL, RL, EL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) EL:=PINV(0,RNINT(1),RL); RPQR(RL,EL,AL, CL,QL); 
      IF QL <> 0 THEN  
         ERROR(severe,"Remainder non zero in rational polynomial INV"); 
         END; 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP);
(*2*) (*compute. *) AL:=RPABS(RL,AL); TL:=RPCONST(RL,AL);  
      IF TL <> 1 THEN TL:=0 END;
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DLCM(A,B: LIST): LIST; 
(*Domain least common multiple. c=lcm(a,b). *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
      IF RL <> 1 THEN  
         ERROR(severe,"Only rational univariate polynomial in LCM"); 
         END; 
(*2*) (*compute. *) CL:=RUPLCM(AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DLCM; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) CL:=RPNEG(RL,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) SL:=RPONE(RL,AL); 
(*5*) RETURN(SL); END DONE; 


PROCEDURE DPNF(G,P: LIST): LIST;
(* domain polynomial normalform.
   G is a list of polynomials in distributive
   representation with coefficients from the domain,
   P is a polynomial as above,
   h is a polynomial such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

BEGIN
   RETURN(DIIFNF(G,0,P));
END DPNF;


PROCEDURE DPROD(A,B: LIST): LIST; 
(*Domain product. c=a*b. *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RPPROD(RL, AL,BL);
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
(*Domain quotient and remander. *)
VAR   AL, AP, BL, BP, QL, RL, CL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) RPQR(RL,AL,BL, QL,CL);      
(*3*) (*create. *) Q:=COMP(QL,AP); R:=COMP(CL,AP); 
(*6*) RETURN END DQR; 


PROCEDURE DQUOT(A,B: LIST): LIST; 
(*Domain quotient. *)
VAR   AL, AP, BL, BP, C, CL, QL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) RPQR(RL,AL,BL, CL,QL);      
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is a domain element with descriptor. *)
VAR   C, CL, RL, V, DP: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*read. *) ADV(D,RL,DP); V:=FIRST(DP);
      CL:=DIRPRD(V); PFDIP(CL, RL,CL);  
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DREM(A,B: LIST): LIST; 
(*Domain remainder. *)
VAR   AL, AP, BL, BP, QL, CL, RL, R: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) RPQR(RL,AL,BL, QL,CL);      
(*3*) (*create. *) R:=COMP(CL,AP); 
(*6*) RETURN(R); END DREM; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL, RL, AP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A,AL,AP); RL:=FIRST(AP);  
(*2*) (*compute. *) SL:=RPSIGN(RL,AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=RPSUM(RL,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, RL, V, AP: LIST; 
BEGIN
(*1*) (*advance. *) ADV2(A,AL,RL,AP); V:=FIRST(AP); 
(*2*) (*write. *) AL:=DIPFP(RL,AL); DIRPWR(AL,V,-1);
(*5*) RETURN; END DWRIT; 


PROCEDURE DDDRD(): LIST; 
(*Domain, domain descriptor read. A domain element with descriptor
D is read from the input stream. *)
VAR   V, RL, C: LIST;
BEGIN
(*1*) (*read. *) V:=VLREAD(); RL:=LENGTH(V); 
(*3*) (*create. *) C:=LIST3(0,RL,V); 
(*5*) RETURN(C); END DDDRD; 


PROCEDURE DDDWR(D: LIST); 
(*Domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   V: LIST;
BEGIN
(*1*) (*advance. *) D:=RED(D); V:=SECOND(D); 
(*2*) (*write. *) VLWRIT(V); 
(*5*) RETURN; END DDDWR; 


PROCEDURE DVLDD(D: LIST): LIST; 
(*Domain, variable list from domain descriptor. d is a domain element 
with descriptor. The variable list from d is returned. *)
VAR   V: LIST;
BEGIN
(*1*) (*advance. *) D:=RED(D); V:=SECOND(D); 
(*5*) RETURN(V); END DVLDD; 


PROCEDURE DomLoadRP();
(*Domain load rational polynomials. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("RP","Rational Polynomial"); DOMRPD:=d;
(*2*) SetDifFunc(d,DDIF); 
      SetExpFunc(d,DEXP); 
      SetFIntFunc(d,DFI); 
      SetFIPolFunc(d,DFIP); 
      SetGcdFunc(d,DGCD); 
      SetGcdeFunc(d,DGCDE); 
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
      SetVlddFunc(d,DVLDD); 
(*3*) SetPNormFunc(d,DPNF);
      SetPSpolFunc(d,DPSP);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
(*9*) END DomLoadRP;


END DOMRP.

(* -EOF- *)
