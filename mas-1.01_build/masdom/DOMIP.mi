(* ----------------------------------------------------------------------------
 * $Id: DOMIP.mi,v 1.7 1995/03/06 15:53:23 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1992 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DOMIP.mi,v $
 * Revision 1.7  1995/03/06  15:53:23  pesch
 * Added new domain function (FACTO): factorization with variable order
 * optimization.
 *
 * Revision 1.6  1994/09/06  11:48:57  rose
 * modified comment
 *
 * Revision 1.5  1994/05/19  10:42:54  rose
 * Added DPNF, DPSP, DPSUGNF, DPSUGSP in connection with the new module DIPAGB
 *
 * Revision 1.4  1992/10/16  14:17:54  kredel
 * Errors found by Mocka corrected
 *
 * Revision 1.3  1992/10/15  16:30:16  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:29  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:45  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DOMIP;

(* MAS Domain Integral Polynomial Implementation Module. *)



(* Import lists and declarations. *)

FROM DIPTOO IMPORT DIPVOPP, INVPERM;

FROM DIPTOOLS IMPORT EvordPop, EvordPush, ValisPop, ValisPush;

FROM MASSTOR IMPORT LIST, LIST1, ADV, FIRST, RED, INV, SIL, COMP, LENGTH; 

FROM MASERR IMPORT severe, fatal, ERROR;

FROM MASADOM IMPORT Domain, NewDom, 
                    SetDifFunc, SetExpFunc, SetFIntFunc, SetFIPolFunc, 
                    SetCnstFunc, SetFactFunc, SetFactoFunc, SetGcdFunc,   
                    SetGcdcFunc, SetInvFunc, SetInvTFunc,   
                    SetLcmFunc, SetNegFunc, SetOneFunc, 
                    SetProdFunc, SetQuotFunc, SetReadFunc, 
                    SetSignFunc, SetSumFunc, SetToipFunc, SetWritFunc, 
                    SetVlddFunc, SetDdrdFunc, SetDdwrFunc, 
		    SetPNormFunc, SetPSpolFunc, SetPSugNormFunc,
                    SetPSugSpolFunc;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACLIST IMPORT LIST2, ADV2, SECOND, THIRD, LIST3, OWRITE;

FROM SACPOL IMPORT PINV, VLWRIT, VLREAD;

FROM SACIPOL IMPORT IPSUM, IPABS, IPSIGN, IPPROD, IPNEG, IPQR, 
                    IPONE, IPDIF, IPEXP;

FROM SACPGCD IMPORT IPGCDC;

FROM SACPFAC IMPORT IPFAC;

FROM SACEXT4 IMPORT PCONST;

FROM DIPC IMPORT DIPBSO, DIPERM, DIPFP, INVLEX, PFDIP, VALIS;

FROM DIPI IMPORT DIIPWR, DIIPRD;

FROM DIPGCD IMPORT IPLCM;

FROM DIPAGB IMPORT EDIIFSUGNF, EDIIFSUGSP;

FROM DIPGB IMPORT DIIFNF, DIIFSP;


(* Domain:            (dom, val, r, V) 
   Domain descriptor:           (r, V) 

   where: val = integral recursive polynomial 
          r   = number of variables, 
          V   = variable list
*)

CONST rcsidi = "$Id: DOMIP.mi,v 1.7 1995/03/06 15:53:23 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";



PROCEDURE DCNST(A: LIST): BOOLEAN; 
(*Domain constant test. Returns true iff A is a constant *)
VAR   AL, AP, t, r: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); r:=FIRST(AP); 
(*2*) (*compute. *) t:=PCONST(r,AL);
      IF t = 1 THEN RETURN(TRUE) ELSE RETURN(FALSE) END; 
(*7*) END DCNST; 


PROCEDURE DDIF(A,B: LIST): LIST; 
(*Domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CL, RL:LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IPDIF(RL,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DDIF; 


PROCEDURE DFACT(A: LIST): LIST; 
(*Domain factorization.
A is an integral polynomial.
Returns a list of the prime factors of A *)
VAR   AL, AP, r, P, SL, CL, L, LL, B, BL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); r:=FIRST(AP); 
(*2*) (*compute. *) P:=IPABS(r,AL); (*get rid of negative sign ?? *)
      IPFAC(r,P, SL,CL,L); (*factorization. *)
(*3*) (*create. *) LL:=SIL; 
      WHILE L <> SIL DO ADV(L, BL,L); BL:=SECOND(BL); 
            B:=COMP(BL,AP); LL:=COMP(B,LL); 
            END; 
      LL:=INV(LL);  
(*7*) RETURN(LL); END DFACT; 


PROCEDURE DFACTO(A: LIST): LIST; 
(*Domain factorization with variable order optimization.
A is an integral polynomial.
Returns a list of the prime factors of A *)
VAR   AL, AP, r, P, SL, CL, L, LL, B, BL, PP, VP, PV, VAL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); r:=FIRST(AP); 
(*2*) (*compute. *) P:=IPABS(r,AL); (*get rid of negative sign ?? *)
      ValisPush(SECOND(AP));
      P:=DIPFP(r, P);
      DIPVOPP(LIST1(P),VALIS, PP,VP,PV);
      ValisPush(VP);
      P:=FIRST(PP);
      EvordPush(INVLEX);
      DIPBSO(P);
      PFDIP(P, r,P);
      EvordPop();
      IPFAC(r,P, SL,CL,L); (*factorization. *)
      PV:=INVPERM(PV);
      LL:=SIL;
      WHILE L<>SIL DO
     	  ADV(L, BL,L);
	  BL:=DIPFP(r,SECOND(BL));
     	  BL:=DIPERM(BL,PV); 
	  PFDIP(BL, r,BL);
     	  BL:=COMP(BL,AP);
     	  LL:=COMP(BL,LL);
     END;
     ValisPop();
     ValisPop();
     LL:=INV(LL);  
(*7*) RETURN(LL); END DFACTO; 


PROCEDURE DEXP(A,NL: LIST): LIST; 
(*Domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) CL:=IPEXP(RL,AL,NL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DEXP; 


PROCEDURE DFI(D, A: LIST): LIST; 
(*Domain from integer. D is a domain element with descriptor, 
A is an integer. *)
VAR   C, CL, RL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*compute. *) RL:=FIRST(D); CL:=PINV(0,A,RL); 
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFI; 


PROCEDURE DFIP(D, A: LIST): LIST; 
(*Domain from integral polynomial. D is a domain element with descriptor, 
A is an integral polynomial in #vldd(D) variables. *)
VAR   C, CL: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*compute. *) CL:=A;
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DFIP; 


PROCEDURE DGCD(A,B: LIST): LIST; 
(*Domain greatest common divisor. c=gcd(a,b). *)
VAR   AL, AP, BL, BP, C, CL, RL, C1, C2: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IPGCDC(RL,AL,BL, CL, C1, C2);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DGCD; 


PROCEDURE DGCDC(A,B: LIST; VAR C,AA,BB: LIST); 
(*Domain greatest common divisor and cofactors. c=gcd(a,b). 
C*AA=A, C*BB=B. *)
VAR   AL, AP, BL, BP, CL, RL, C1, C2: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IPGCDC(RL,AL,BL, CL, C1, C2);
(*3*) (*create. *) C:=COMP(CL,AP); AA:=COMP(C1,AP); BB:=COMP(C2,AP); 
(*7*) END DGCDC; 


PROCEDURE DINV(A: LIST): LIST; 
(*Domain inverse. c=1/a. *)
VAR   AL, AP, C, CL, QL, RL, EL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) EL:=PINV(0,1,RL); IPQR(RL,EL,AL, CL,QL); 
      IF QL <> 0 THEN  
         ERROR(severe,"Remainder non zero in integral polynomial INV"); 
         END; 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DINV; 


PROCEDURE DINVT(A: LIST): LIST; 
(*Domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP);
(*2*) (*compute. *) AL:=IPABS(RL,AL); TL:=IPONE(RL,AL);  
      IF TL <> 1 THEN TL:=0 END;
(*5*) RETURN(TL); END DINVT; 


PROCEDURE DLCM(A,B: LIST): LIST; 
(*Domain least common multiple. c=lcm(a,b). *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IPLCM(RL,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*7*) RETURN(C); END DLCM; 


PROCEDURE DNEG(A: LIST): LIST; 
(*Domain negative. c=-a. *)
VAR   AL, AP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) CL:=IPNEG(RL,AL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DNEG; 


PROCEDURE DONE(A: LIST): LIST; 
(*Domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); 
(*2*) (*compute. *) SL:=IPONE(RL,AL); 
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
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IPPROD(RL, AL,BL);
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


PROCEDURE DQUOT(A,B: LIST): LIST; 
(*Domain quotient. c=a/b. *)
VAR   AL, AP, BL, BP, C, CL, QL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) IPQR(RL,AL,BL, CL,QL);      
      IF QL <> 0 THEN  
         ERROR(severe,"Remainder non zero in integral polynomial QUOT"); 
         END; 
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DQUOT; 


PROCEDURE DREAD(D: LIST): LIST; 
(*Domain read. d is a domain element with descriptor. *)
VAR   C, CL, RL, V, DP: LIST; 
BEGIN
(*1*) (*select. *) D:=RED(D);
(*2*) (*read. *) ADV(D,RL,DP); V:=FIRST(DP);
      CL:=DIIPRD(V); PFDIP(CL, RL,CL);  
(*3*) (*create. *) C:=COMP(CL,D); 
(*5*) RETURN(C); END DREAD; 


PROCEDURE DSIGN(A: LIST): LIST; 
(*Domain sign. cl=sign(a). *)
VAR   AL, SL, RL, AP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A,AL,AP); RL:=FIRST(AP);  
(*2*) (*compute. *) SL:=IPSIGN(RL,AL);
(*5*) RETURN(SL); END DSIGN; 


PROCEDURE DSUM(A,B: LIST): LIST; 
(*Domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CL, RL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); RL:=FIRST(AP); ADV(B, BL,BP); 
(*2*) (*compute. *) CL:=IPSUM(RL,AL,BL);
(*3*) (*create. *) C:=COMP(CL,AP); 
(*6*) RETURN(C); END DSUM; 


PROCEDURE DTOIP(A: LIST; VAR LCM: LIST): LIST; 
(*Domain to integral polynomial conversion. ???  *)
VAR   AL, AP, LL, RL: LIST; 
BEGIN
(*1*) (*select. *) ADV(A, AL,AP); RL:=FIRST(AP);  
(*2*) (*compute. *) LL:=PINV(0,1,RL); 
(*3*) (*create. *) LCM:=COMP(LL,AP); 
(*5*) RETURN(A); END DTOIP; 


PROCEDURE DWRIT(A: LIST); 
(*Domain write. *)
VAR   AL, RL, V, AP: LIST; 
BEGIN
(*1*) (*advance. *) ADV2(A,AL,RL,AP); V:=FIRST(AP); 
(*2*) (*write. *) AL:=DIPFP(RL,AL); DIIPWR(AL,V);
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


PROCEDURE DomLoadIP();
(*Domain load integral polynomials. *)
VAR   d: Domain;
BEGIN
(*1*) d:=NewDom("IP","Integral Polynomial"); DOMIPD:=d;
(*2*) SetCnstFunc(d,DCNST); 
      SetDifFunc(d,DDIF); 
      SetExpFunc(d,DEXP); 
      SetFactFunc(d,DFACT); 
      SetFactoFunc(d,DFACTO); 
      SetFIntFunc(d,DFI); 
      SetFIPolFunc(d,DFIP); 
      SetGcdFunc(d,DGCD); 
      SetGcdcFunc(d,DGCDC); 
      SetInvFunc(d,DINV); 
      SetInvTFunc(d,DINVT); 
      SetLcmFunc(d,DLCM); 
      SetNegFunc(d,DNEG); 
      SetOneFunc(d,DONE); 
      SetProdFunc(d,DPROD); 
      SetQuotFunc(d,DQUOT); 
      SetReadFunc(d,DREAD); 
      SetSignFunc(d,DSIGN); 
      SetSumFunc(d,DSUM); 
      SetToipFunc(d,DTOIP); 
      SetWritFunc(d,DWRIT); 
      SetDdrdFunc(d,DDDRD); 
      SetDdwrFunc(d,DDDWR); 
      SetVlddFunc(d,DVLDD); 
(*3*) SetPNormFunc(d,DPNF);
      SetPSpolFunc(d,DPSP);
      SetPSugNormFunc(d,DPSUGNF);
      SetPSugSpolFunc(d,DPSUGSP);
(*9*) END DomLoadIP;


END DOMIP.
(* -EOF- *)
