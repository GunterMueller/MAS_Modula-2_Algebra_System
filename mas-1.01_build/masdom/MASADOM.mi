(* ----------------------------------------------------------------------------
 * $Id: MASADOM.mi,v 1.15 1995/03/06 15:53:27 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASADOM.mi,v $
 * Revision 1.15  1995/03/06  15:53:27  pesch
 * Added new domain function (FACTO): factorization with variable order
 * optimization.
 *
 * Revision 1.14  1994/11/28  20:56:32  dolzmann
 * New function for the computation of the content and the primitive part of a
 * polynomial.
 *
 * Revision 1.13  1994/11/03  14:42:18  pfeil
 * modified comment
 *
 * Revision 1.12  1994/09/07  12:10:52  rose
 * Error messages corrected.
 *
 * Revision 1.11  1994/09/06  19:06:56  rose
 * Error message in ADSUM corrected.
 *
 * Revision 1.10  1994/06/16  12:54:06  pfeil
 * changed number of parameters in procedure DIPSFF.
 * changed parameter type of procedures SetPFactFunc, SetPSqfrFunc.
 *
 * Revision 1.9  1994/06/10  12:06:53  pfeil
 * Minor changes.
 *
 * Revision 1.8  1994/06/09  14:51:42  pfeil
 * Added ADPFACT, ADPSFF, SetPFactFunc, SetPSqfrFunc for DIPDCGB.
 *
 * Revision 1.7  1994/05/19  10:43:19  rose
 * Added DomPRec, ADPNF, ADPSP, ADPSUGNF, ADPSUGSP, SetPNormFunc, SetPSpolFunc,
 * SetPSugNormFunc, SetPSugSpolFunc in connection with the new module DIPAGB
 *
 * Revision 1.6  1994/03/11  15:54:11  pesch
 * Minor corrections.
 *
 * Revision 1.5  1993/05/11  10:36:02  kredel
 * Added QR, REM, ... support
 *
 * Revision 1.4  1992/10/15  16:30:23  kredel
 * Changed rcsid variable
 *
 * Revision 1.3  1992/06/12  13:51:10  kredel
 * Added extended GCD support
 *
 * Revision 1.2  1992/02/12  17:31:37  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:09:55  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE MASADOM;

(* MAS Arbitrary Domain Implementation Module. *)



(* Import lists and declarations. *)

FROM DIPAGB   IMPORT ADDNFEDIP, EDIPSUGSP;

FROM DIPC     IMPORT DIP2AD, AD2DIP, DIPBSO, EVORD, VALIS, DIPERM;

FROM DIPTOO   IMPORT DIPVOPP, INVPERM;

FROM DIPTOOLS IMPORT ADDNFDIP;

FROM DOMIP    IMPORT DOMIPD;

FROM MASBIOS  IMPORT BLINES, SWRITE, LISTS;

FROM MASERR   IMPORT severe, fatal, ERROR;

FROM MASSTOR  IMPORT LIST, LIST1, ADV, FIRST, RED, SIL, COMP, LISTVAR, INV;

FROM MASSYM2  IMPORT SYWRIT, SREAD, ENTER; 

FROM SACLIST  IMPORT OWRITE, CLOUT, SECOND, FIRST2, LIST2;

FROM SYSTEM   IMPORT ADDRESS;


CONST maxdom = 30;

TYPE funcf1  = ARRAY [1..maxdom] OF PROCF1;

TYPE DomRec = RECORD
                name:      LIST;   (* full print name *)
                Sym:       LIST;   (* symbol identificator *)
                AbsFunc:   PROCF1;
                CnstFunc:  PROCF1B;
                ConvFunc:  funcf1;
                CompFunc:  PROCF2;
                DifFunc:   PROCF2;
                ExpFunc:   PROCF2;
                FactFunc:  PROCF1;
     	        FactoFunc: PROCF1;
                FIntFunc:  PROCF2;
                FIPolFunc: PROCF2;
                GcdFunc:   PROCF2;
                GcdcFunc:  PROCP2V3;
                GcdeFunc:  PROCP2V3;
                InvFunc:   PROCF1;
                InvTFunc:  PROCF1;
                LcmFunc:   PROCF2;
                NegFunc:   PROCF1;
                OneFunc:   PROCF1;
                ProdFunc:  PROCF2;
                QuotFunc:  PROCF2;
                QrFunc:    PROCP2V2;
                ReadFunc:  PROCF1;
                RemFunc:   PROCF2;
                SignFunc:  PROCF1;
                SumFunc:   PROCF2;
                ToipFunc:  PROCF1V1;
                WritFunc:  PROCP1;
                VlddFunc:  PROCF1;
                DdrdFunc:  PROCF0;
                DdwrFunc:  PROCP1;
              END;

TYPE DomPRec = RECORD
		 PFactFunc:	PROCF1;
		 PNormFunc:     PROCF2;
		 PSpolFunc:  	PROCF2;
		 PSqfrFunc:	PROCF1;
                 PSugNormFunc:  PROCF2;
                 PSugSpolFunc:  PROCF2;
                 PCppFunc:	PROCP1V2;
	       END;

VAR domain: ARRAY [1..maxdom] OF DomRec;

VAR Pdomain: ARRAY [1..maxdom] OF DomPRec;

VAR curdom : INTEGER;

VAR Dummy: LIST;

(* Domain:            (dom, val, rest ... )
   Domain descriptor: (rest ... )
   where   dom  = domain number
           val  = value
           rest = more information on domain
*)


CONST rcsidi = "$Id: MASADOM.mi,v 1.15 1995/03/06 15:53:27 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";


PROCEDURE ADABSF(A:LIST):LIST;
(*Arbitrary domain absolute value. *)
VAR   C, CP, AL, AP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *) 
      IF ADDRESS(domain[INTEGER(AL)].AbsFunc) = ADDRESS(Dummyf1)
         THEN IF domain[INTEGER(AL)].SignFunc(AP) = -1 
                 THEN CP:=domain[INTEGER(AL)].NegFunc(AP);
                 ELSE RETURN(A); END;
         ELSE CP:=domain[INTEGER(AL)].AbsFunc(AP); END;
(*3*) (*create. *) C:=COMP(AL,CP);
(*6*) RETURN(C); END ADABSF;


PROCEDURE ADCNST(A: LIST): BOOLEAN; 
(*Arbitrary domain constant test. Returns true iff A is a constant. *)
VAR   AL, AP: LIST; 
BEGIN
(*1*) (*Advance. *) ADV(A, AL,AP); 
(*2*) (*Select. *)
      RETURN(domain[INTEGER(AL)].CnstFunc(AP));
(*7*) END ADCNST;


PROCEDURE ADCOMP(A,B:LIST):LIST;
(*Arbitrary domain comparison. s=sign(a-b). *)
VAR   SL, AL, AP, BL, BP, CP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADCOMP: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      IF ADDRESS(domain[INTEGER(AL)].CompFunc) = ADDRESS(Dummyf2)
         THEN CP:=domain[INTEGER(AL)].DifFunc(AP,BP);
              SL:=domain[INTEGER(AL)].SignFunc(CP);  
         ELSE SL:=domain[INTEGER(AL)].CompFunc(AP,BP); END;
(*3*) RETURN(SL);  
(*2*) END ADCOMP;


PROCEDURE ADCONV(A,B: LIST): LIST;
(*Arbitrary domain conversion. c=b:domain(a). *)
VAR   AL, AP, BL, BP, C, CP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
(*2*) (*select. *)
      CP:=domain[INTEGER(AL)].ConvFunc[INTEGER(BL)](BP);
(*3*) (*create. *) C:=COMP(AL,CP);
(*6*) RETURN(C); END ADCONV; 


PROCEDURE ADDIF(A,B: LIST): LIST; 
(*Arbitrary domain difference. c=a-b. *)
VAR   AL, AP, BL, BP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADDIF: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].DifFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADDIF; 


PROCEDURE ADEXP(A,NL: LIST): LIST; 
(*Arbitrary domain exponentiation. c=a**nl. *)
VAR   AL, AP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);
(*2*) (*select. *)
      CP:=domain[INTEGER(AL)].ExpFunc(AP,NL);
(*3*) (*create. *) C:=COMP(AL,CP);
(*6*) RETURN(C); END ADEXP; 


PROCEDURE ADFACT(A: LIST): LIST; 
(*Arbitrary domain factorization. Returns a list containing
all prime factors of A.*)
VAR   AL, AP, FL, FL1, RET: LIST; 
BEGIN
(*1*) (*Advance. *) ADV(A, AL,AP);
(*2*) (*Select. *) 
      FL:=domain[INTEGER(AL)].FactFunc(AP);
(*3*) (*Create. (for every list-element add domain-descriptor) *)
      RET:=SIL;
      WHILE FL <> SIL DO ADV(FL, FL1,FL);
	    RET:=COMP(COMP(AL,FL1),RET);
            END;
      RETURN(RET);
(*7*) END ADFACT; 

PROCEDURE ADFACTO(A: LIST): LIST; 
(*Arbitrary domain factorization with variable order optimization.
A is an arbitrary domain polynomial.
Returns a list containing all prime factors of A.*)
VAR   AL, AP, FL, FL1, RET: LIST; 
BEGIN
(*1*) (*Advance. *) ADV(A, AL,AP);
(*2*) (*Select. *) 
      FL:=domain[INTEGER(AL)].FactoFunc(AP);
(*3*) (*Create. (for every list-element add domain-descriptor) *)
      RET:=SIL;
      WHILE FL <> SIL DO ADV(FL, FL1,FL);
	    RET:=COMP(COMP(AL,FL1),RET);
            END;
      RETURN(RET);
(*7*) END ADFACTO; 


PROCEDURE ADFI(D,A: LIST): LIST; 
(*Arbitrary domain from integer. D is a domain element and A is an 
integer. *)
VAR   C, CP, DP, d: LIST; 
BEGIN
(*1*) (*select. *) ADV(D,d,DP); (*DP:=RED(DP);*)
      CP:=domain[INTEGER(d)].FIntFunc(DP,A);
(*2*) (*create. *) C:=COMP(d,CP); 
(*5*) RETURN(C); END ADFI; 


PROCEDURE ADFIP(D,A: LIST): LIST; 
(*Arbitrary domain from integral polynomial. D is a domain element and A is 
an integral polynomial in #vldd(D) variables. *)
VAR   C, CP, DP, d: LIST;
BEGIN
(*1*) (*select. *) ADV(D,d,DP); (*DP:=RED(DP);*)
      CP:=domain[INTEGER(d)].FIPolFunc(DP,A);
(*2*) (*create. *) C:=COMP(d,CP);
(*5*) RETURN(C); END ADFIP; 


PROCEDURE ADGCD(A,B: LIST): LIST; 
(*Arbitrary domain greatest common divisor. c=gcd(a,b). *)
VAR   AL, AP, BL, BP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADGCD: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].GcdFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*7*) RETURN(C); END ADGCD; 


PROCEDURE ADGCDC(A,B: LIST; VAR C,AA,BB: LIST);
(*Arbitrary domain greatest common divisor and cofactors.
C=gcd(A,B), A=C*AA, B=C*BB, if C=0 then AA=BB=0
If gcd is undefined for the current domain C:=1, AA:=A, BB:=B. *)
VAR AL, AP, BL, BP, AAP, BBP, CP: LIST;
BEGIN 
(*1*) (*Advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal, "ADGCDC: incompatible domains");
         C:=SIL; AA:=SIL; BB:=SIL; RETURN; END;
(*2*) (*Select. *)  
      domain[INTEGER(AL)].GcdcFunc(AP,BP,CP,AAP,BBP);
(*3*) (*Add domain-descriptor.*)
      C:=COMP(AL,CP); AA:=COMP(AL,AAP); BB:=COMP(AL,BBP);
(*7*) END ADGCDC; 


PROCEDURE ADGCDE(A,B: LIST; VAR C,AA,BB: LIST);
(*Arbitrary domain greatest common divisor and linear combination.
C=gcd(A,B), C=A*AA+B*BB. If gcd is undefined for the current domain 
C:=1, AA:=0, BB:=0. *)
VAR AL, AP, BL, BP, AAP, BBP, CP: LIST;
BEGIN 
(*1*) (*Advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal, "ADGCDE: incompatible domains");
          C:=SIL; AA:=SIL; BB:=SIL; RETURN; END;
(*2*) (*Select. *)  
      domain[INTEGER(AL)].GcdeFunc(AP,BP,CP,AAP,BBP);
(*3*) (*Add domain-descriptor.*)
      C:=COMP(AL,CP); AA:=COMP(AL,AAP); BB:=COMP(AL,BBP);
(*7*) END ADGCDE; 


PROCEDURE ADINV(A: LIST): LIST; 
(*Arbitrary domain inverse. c=1/a. *)
VAR   AL, AP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *)
      CP:=domain[INTEGER(AL)].InvFunc(AP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADINV; 


PROCEDURE ADINVT(A: LIST): LIST; 
(*Arbitrary domain inverse existence test.
tl=1 if a is invertible, tl=0 else. *)
VAR   AL, AP, TL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP);  
(*1*) (*select. *) 
      TL:=domain[INTEGER(AL)].InvTFunc(AP);
(*5*) RETURN(TL); END ADINVT; 


PROCEDURE ADLCM(A,B: LIST): LIST; 
(*Arbitrary domain least common multiple. c=lcm(a,b). *)
VAR   AL, AP, BL, BP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP);
      IF AL <> BL THEN ERROR(fatal,"ADLCM: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].LcmFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*7*) RETURN(C); END ADLCM; 


PROCEDURE ADNEG(A: LIST): LIST; 
(*Arbitrary domain negative. c=-a. *)
VAR   AL, AP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].NegFunc(AP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADNEG; 


PROCEDURE ADONE(A: LIST): LIST; 
(*Arbitrary domain one. sl=1 if a=1, sl ne 1 else. *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *) 
      SL:=domain[INTEGER(AL)].OneFunc(AP);
(*5*) RETURN(SL); END ADONE; 


PROCEDURE ADPCPP(P: LIST; VAR c, pp: LIST);
(* Arbitrary domain polynomial content and primitive part. 
P is a distributive polynomial over an arbitrary domain.
The content of c and its primitive part is returned. 
It holds P=c * pp.
If the domain is a field then HC(pp)=1. 
If ADSIGN is defined in the domain, then ADSIGN(HC(p))>=0. *)
	VAR d: LIST;
BEGIN
	IF P=0 THEN c:=0; pp:=0; RETURN; END;
	d:=ADDNFDIP(P);
	Pdomain[INTEGER(d)].PCppFunc(P,c,pp);
END ADPCPP;


PROCEDURE ADPFACT(P,VOO: LIST): LIST; 
(* Arbitrary domain polynomial factorization.
   P is a polynomial in distributive representation
   over an arbitrary domain,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns the list ((e1,f1),...,(ek,fk)), ei positive integers,
   fi irreducible polynomials in distributive representation,
   where P = u * f1**e1 * ... * fk**ek and u unit. *)
(* the ordering of the factors is non-deterministic !! *)
VAR coe,d,rest,F,F1,ExpPol,exp,pol,Tord,
    OVL,PV,IPV: LIST; 
BEGIN
   IF P=SIL THEN RETURN(P); END;
   coe:=SECOND(P);	(* get coefficient *)
   ADV(coe,d,coe);	(* get domain number from coefficient *)
   rest:=RED(coe);	(* get domain descriptor from coeff. *)
   P:=AD2DIP(P);	(* remove domain numbers and descriptors *)
   IF VOO=1 THEN (* use variable order optimization *)
	OVL:=VALIS;
	DIPVOPP(LIST1(P),OVL,P,VALIS,PV);
	P:=FIRST(P);
	IPV:=INVPERM(PV);
   END; (* IF VOO... *)
   Tord:=EVORD;	EVORD:=2;	(* define term order L for factorization *)
   IF Tord<>2 THEN DIPBSO(P); END;	(* sort P w.r.t. L *)
   F:=Pdomain[INTEGER(d)].PFactFunc(P);	(* select function *)
   IF VOO=1 THEN VALIS:=OVL; END; (* use old variable list *)
   IF Tord<>2 THEN EVORD:=Tord; END;	(* old term order *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);	(* get next (ei,fi) *)
      FIRST2(ExpPol,exp,pol);	(* get polynomial factor fi *)
      IF VOO=1 THEN pol:=DIPERM(pol,IPV); END; (* sort pol w.r.t. old VO *)
      IF Tord<>2 THEN DIPBSO(pol); END;	(* sort pol w.r.t. Tord *)
      pol:=DIP2AD(pol,d,rest);	(* add domain number and descriptor *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END ADPFACT; 


PROCEDURE ADPNF(G,P: LIST): LIST;
(* Arbitrary domain polynomial normalform.
   G is a list of polynomials in distributive
   representation over an arbitrary domain,
   P is a polynomial as above,
   returns a polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

VAR DomNum: LIST;
BEGIN
   DomNum:=ADDNFDIP(P);
   IF DomNum=0
      THEN RETURN(0); (* P was the zero polynomial *)
      ELSE RETURN(Pdomain[INTEGER(DomNum)].PNormFunc(G,P));
   END;
END ADPNF;


PROCEDURE ADPROD(A,B: LIST): LIST; 
(*Arbitrary domain product. c=a*b. *)
VAR   AL, AP, BL, BP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADPROD: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].ProdFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADPROD; 


PROCEDURE ADPSFF(A,VOO: LIST): LIST;
(* Arbitrary domain polynomial squarefree factorization.
   A is a polynomial in distributive representation
   over an arbitrary domain,
   VOO is a flag, use variable order optimization iff VOO = 1,
   returns a list ((e1,p1),...,(ek,pk)), ei positive integers,
   pi squarefree polynomials in distributive representation,
   where A = u * p1**e1 * ... * pk**ek and u unit. *)
VAR coe,d,rest,Tord,F,F1,ExpPol,exp,pol,
    OVL,PV,IPV: LIST;
BEGIN
   IF A=SIL THEN RETURN(A); END;
   coe:=SECOND(A);	(* get coefficient *)
   ADV(coe,d,coe);	(* get domain number from coefficient *)
   rest:=RED(coe);	(* get domain descriptor from coeff. *)
   A:=AD2DIP(A);	(* remove domain numbers and descriptors *)
   IF VOO=1 THEN (* use variable ordering optimization *)
	OVL:=VALIS;
	DIPVOPP(LIST1(A),OVL,A,VALIS,PV);
	A:=FIRST(A);
	IPV:=INVPERM(PV);
   END; (* IF VOO... *)
   Tord:=EVORD;	EVORD:=2;	(* define term order L for factorization *)
   IF Tord<>2 THEN DIPBSO(A); END;	(* sort A w.r.t. L *)
   F:=Pdomain[INTEGER(d)].PSqfrFunc(A);	(* select function *)
   IF VOO=1 THEN VALIS:=OVL; END; (* use old variable list *)
   IF Tord<>2 THEN EVORD:=Tord; END;	(* old term order *)
   F1:=SIL;
   WHILE F<>SIL DO
      ADV(F,ExpPol,F);	(* get next (ei,fi) *)
      FIRST2(ExpPol,exp,pol);	(* get polynomial factor fi *)
      IF VOO=1 THEN pol:=DIPERM(pol,IPV); END; (* sort pol w.r.t. old VO *)
      IF Tord<>2 THEN DIPBSO(pol); END;	(* sort pol w.r.t. Tord *)
      pol:=DIP2AD(pol,d,rest);	(* add domain number and descriptor *)
      F1:=COMP(LIST2(exp,pol),F1);
   END; (* while... *)
   RETURN(INV(F1));
END ADPSFF;


PROCEDURE ADPSP(A,B: LIST): LIST;
(* Arbitrary domain polynomial S-polynomial.
   A and B are polynomials in distributive
   representation over an arbitrary domain,
   returns the S-polynomial of A and B *)

VAR DomNumA,DomNumB: LIST;
BEGIN
   DomNumA:=ADDNFDIP(A); DomNumB:=ADDNFDIP(B);
   IF (DomNumA=0) OR (DomNumB=0) THEN (* A=0 OR B=0 *) RETURN(0); END;
   IF DomNumA=DomNumB
      THEN RETURN(Pdomain[INTEGER(DomNumA)].PSpolFunc(A,B));
      ELSE ERROR(fatal,"ADPSP: incompatible domains"); RETURN(SIL);
   END;
END ADPSP;


PROCEDURE ADPSUGNF(G,P: LIST): LIST;
(* Arbitrary domain normal with sugar strategy polynomial normalform.
   G is a list of extended polynomials in distributive representation over an
   arbitrary domain,
   P is an extended polynomial as above,
   returns an extended polynomial h such that P is reducible to h
   modulo G and h is in normalform with respect to G *)

VAR DomNum: LIST;
BEGIN
   DomNum:=ADDNFEDIP(P);
   IF DomNum=0
      THEN RETURN(P); (* the unextended polynomial appropriate to P is 0 *)
      ELSE RETURN(Pdomain[INTEGER(DomNum)].PSugNormFunc(G,P));
   END;
END ADPSUGNF;


PROCEDURE ADPSUGSP(A,B: LIST): LIST;
(* Arbitrary domain normal with sugar strategy polynomial S-polynomial.
   A and B are extended polynomials in distributive
   representation over an arbitrary domain,
   returns the extended S-polynomial of A and B *)

VAR DomNumA,DomNumB: LIST;
BEGIN
   DomNumA:=ADDNFEDIP(A); DomNumB:=ADDNFEDIP(B);
   IF (DomNumA=0) AND (DomNumB=0)
      THEN (* The unextended polynomials appropriate to A,B are 0 *)
           RETURN(EDIPSUGSP(A,B));
   END;
   IF DomNumA=0
      THEN (* The unextended polynomial appropriate to A is 0 *)
           RETURN(Pdomain[INTEGER(DomNumB)].PSugSpolFunc(A,B));
   END;
   IF DomNumB=0
      THEN (* The unextended polynomial appropriate to B is 0 *)
           RETURN(Pdomain[INTEGER(DomNumA)].PSugSpolFunc(A,B));
   END;
   IF DomNumA=DomNumB
      THEN RETURN(Pdomain[INTEGER(DomNumA)].PSugSpolFunc(A,B));
      ELSE ERROR(fatal,"ADPSUGSP: incompatible domains"); RETURN(SIL);
   END;
END ADPSUGSP;


PROCEDURE ADQR(A,B:LIST; VAR Q,R:LIST);
(*Arbitrary domain quotient and remainder. q=a/b, r=a-(a/b)*b. *)
VAR   AL, AP, BL, BP, QP, RP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADQR: incompatible domains");
         Q:=SIL; R:=SIL; RETURN END;
(*2*) (*Select. *) 
      domain[INTEGER(AL)].QrFunc(AP,BP,QP,RP);
(*3*) (*Add domain-descriptor.*)
      Q:=COMP(AL,QP); R:=COMP(AL,RP);
      (*Q:=ADQUOT(A,B); R:=ADDIF(A,ADPROD(B,Q));*)
(*5*) RETURN; END ADQR;


PROCEDURE ADQUOT(A,B: LIST): LIST;
(*Arbitrary domain quotient. c=a/b. *)
VAR   AL, AP, BL, BP, C, CP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADQUOT: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].QuotFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADQUOT; 


PROCEDURE ADREAD(D: LIST): LIST; 
(*Arbitrary domain read. d is the domain descriptor. *)
VAR   DL, DP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(D, DL,DP); (*DP:=RED(DP);*)
(*2*) (*select. *) 
      CP:=domain[INTEGER(DL)].ReadFunc(DP);
(*3*) (*create. *) C:=COMP(DL,CP);
(*5*) RETURN(C); END ADREAD; 


PROCEDURE ADREM(A,B:LIST):LIST;
(*Arbitrary domain remainder. r=a-(a/b)*b. *)
VAR   AL, AP, BL, BP, Q, QP, R, RP: LIST;
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADREM: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      IF ADDRESS(domain[INTEGER(AL)].RemFunc) = ADDRESS(Dummyp2v2)
         THEN domain[INTEGER(AL)].QrFunc(AP,BP,QP,RP);
         ELSE RP:=domain[INTEGER(AL)].RemFunc(AP,BP); END;
(*3*) (*create. *) R:=COMP(AL,RP);
(*2*) RETURN(R); END ADREM;


PROCEDURE ADSIGN(A: LIST): LIST;
(*Arbitrary domain sign. cl=sign(a). *)
VAR   AL, AP, SL: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *) 
      SL:=domain[INTEGER(AL)].SignFunc(AP);
(*5*) RETURN(SL); END ADSIGN; 


PROCEDURE ADSUM(A,B: LIST): LIST; 
(*Arbitrary domain sum. c=a+b. *)
VAR   AL, AP, BL, BP, C, CP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); ADV(B, BL,BP); 
      IF AL <> BL THEN ERROR(fatal,"ADSUM: incompatible domains");
         RETURN(SIL) END;
(*2*) (*select. *) 
      CP:=domain[INTEGER(AL)].SumFunc(AP,BP);
(*3*) (*create. *) C:=COMP(AL,CP); 
(*6*) RETURN(C); END ADSUM;


PROCEDURE ADTOIP(A: LIST; VAR LCM: LIST): LIST;
(*Arbitrary domain to integral polynomial conversion.
LCM is the lcm of coefficient-denominators *)
VAR   AL, AP, RET: LIST; 
BEGIN
(*1*) (*Advance. *) ADV(A, AL,AP);
      RET:=COMP(DOMIPD, domain[INTEGER(AL)].ToipFunc(AP, LCM));
      LCM:=COMP(DOMIPD, LCM);
      RETURN(RET);
(*7*) END ADTOIP; 


PROCEDURE ADWRIT(A: LIST); 
(*Arbitrary domain write. *)
VAR   AL, AP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(A, AL,AP); 
(*2*) (*select. *) 
      domain[INTEGER(AL)].WritFunc(AP);
(*5*) RETURN; END ADWRIT; 


PROCEDURE ADDDREAD(): LIST; 
(*Arbitrary domain, domain descriptor read. A domain element with 
descriptor D is read from the input stream. *)
VAR   S, C, CP: LIST;
      i: INTEGER; 
BEGIN
(*1*) S:=SREAD(); C:=SIL; 
(*2*) (*select. *) i:=0;
      WHILE i < maxdom DO i:=i+1; 
            IF domain[i].Sym = S THEN
               C:=domain[i].DdrdFunc();
               (* C:=COMP(SIL,C); *)
               C:=COMP(LIST(i),C); 
               RETURN(C); END;
            END;
(*3*) (*undefined. *) SYWRIT(S); 
      ERROR(severe,"ADDDREAD: undefined domain.");
(*5*) RETURN(C); END ADDDREAD; 


PROCEDURE ADDDWRIT(D: LIST); 
(*Arbitrary domain, domain descriptor write. d is a domain element with 
descriptor. d is written to the output stream. *)
VAR   DL, DP: LIST; 
BEGIN
(*1*) (*advance. *) ADV(D, DL,DP); (*DP:=RED(DP);*) 
      IF ADDRESS(domain[INTEGER(DL)].DdwrFunc) = ADDRESS(Dummyp1)
         THEN ERROR(fatal,"ADDDWRIT: undefined domain.");
         RETURN END;
(*2*) (*select and write. *)
      SYWRIT(domain[INTEGER(DL)].Sym); 
      domain[INTEGER(DL)].DdwrFunc(DP);
      SWRITE(" (* "); 
      CLOUT(domain[INTEGER(DL)].name);
      SWRITE(" *) "); 
(*5*) RETURN; END ADDDWRIT; 


PROCEDURE ADVLDD(D: LIST): LIST; 
(*variable list from domain descriptor. d is a domain element with 
descriptor. if the domain depends on some variables, then
the related variable list is returned, otherwise the empty
list is returned. *)
VAR   DL, DP, V: LIST; 
BEGIN
(*1*) (*advance. *) ADV(D, DL,DP); (*DP:=RED(DP);*) 
(*2*) (*select. *) 
      IF ADDRESS(domain[INTEGER(DL)].VlddFunc) <> ADDRESS(Dummyf1)
         THEN V:=domain[INTEGER(DL)].VlddFunc(DP);
         ELSE V:=SIL END;
(*4*) RETURN(V); END ADVLDD; 


(* -------------- *)


PROCEDURE SetAbsFunc(d: Domain; f1: PROCF1);
(*Set absolute value function in domain. d is a domain 
and f1 is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetAbsFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].AbsFunc:=f1;
(*9*) END SetAbsFunc;


PROCEDURE SetCnstFunc(d: Domain; f1: PROCF1B);
(*Set constant test function in domain. d is a domain 
and f1 is a boolean-function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetCnstFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].CnstFunc:=f1;
(*9*) END SetCnstFunc;


PROCEDURE SetCompFunc(d: Domain; f2: PROCF2);
(*Set comparison function in domain. d is a domain 
and f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetCompFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].CompFunc:=f2;
(*9*) END SetCompFunc;


PROCEDURE SetConvFunc(d1, d2: Domain; f1: PROCF1);
(*Set conversion function in domain. d1 and d2 are domains and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d1) OR (d1 > maxdom) OR
         (1 > d2) OR (d2 > maxdom) 
         THEN OWRITE(LIST(d1)); OWRITE(LIST(d2));
              ERROR(fatal,"SetConvFunc: No valid domains.");
              RETURN END;
(*2*) domain[INTEGER(d1)].ConvFunc[INTEGER(d2)]:=f1;
(*9*) END SetConvFunc;


PROCEDURE SetDifFunc(d: Domain; f2: PROCF2);
(*Set difference function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetDifFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].DifFunc:=f2;
(*9*) END SetDifFunc;


PROCEDURE SetExpFunc(d: Domain; f2: PROCF2);
(*Set exponential function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetExpFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].ExpFunc:=f2;
(*9*) END SetExpFunc;


PROCEDURE SetFactFunc(d: Domain; f1: PROCF1);
(*Set factorization function in domain. d is a domain
and f1 is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetFactFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].FactFunc:=f1;
(*9*) END SetFactFunc;


PROCEDURE SetFactoFunc(d: Domain; f1: PROCF1);
(*Set factorization with variable order optimization function in domain. 
d is a domain and f1 is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetFactoFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].FactoFunc:=f1;
(*9*) END SetFactoFunc;


PROCEDURE SetFIntFunc(d: Domain; f2: PROCF2);
(*Set from integer function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetFIntFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].FIntFunc:=f2;
(*9*) END SetFIntFunc;


PROCEDURE SetFIPolFunc(d: Domain; f2: PROCF2);
(*Set from integral polynomial function in domain. d is a domain 
and f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetFIPolFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].FIPolFunc:=f2;
(*9*) END SetFIPolFunc;


PROCEDURE SetGcdFunc(d: Domain; f2: PROCF2);
(*Set gcd function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetGcdFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].GcdFunc:=f2;
(*9*) END SetGcdFunc;


PROCEDURE SetGcdcFunc(d: Domain; p2v3: PROCP2V3);
(*Set gcd-and-cofactors function in domain. d is a domain
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetGcdcFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].GcdcFunc:=p2v3;
(*9*) END SetGcdcFunc;


PROCEDURE SetGcdeFunc(d: Domain; p2v3: PROCP2V3);
(*Set gcd-and-lin-combination function in domain. d is a domain
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetGcdeFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].GcdeFunc:=p2v3;
(*9*) END SetGcdeFunc;


PROCEDURE SetInvFunc(d: Domain; f1: PROCF1);
(*Set inversion function in domain. d is a domain and 
f is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetInvFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].InvFunc:=f1;
(*9*) END SetInvFunc;


PROCEDURE SetInvTFunc(d: Domain; f1: PROCF1);
(*Set inversion test function in domain. d is a domain and 
f is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetInvTFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].InvTFunc:=f1;
(*9*) END SetInvTFunc;


PROCEDURE SetLcmFunc(d: Domain; f2: PROCF2);
(*Set lcm function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetLcmFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].LcmFunc:=f2;
(*9*) END SetLcmFunc;


PROCEDURE SetNegFunc(d: Domain; f1: PROCF1);
(*Set negation function in domain. d is a domain and 
f is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetNegFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].NegFunc:=f1;
(*9*) END SetNegFunc;


PROCEDURE SetOneFunc(d: Domain; f1: PROCF1);
(*Set one test function in domain. d is a domain and 
f is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetOneFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].OneFunc:=f1;
(*9*) END SetOneFunc;


PROCEDURE SetPCppFunc(d:Domain; p1v2: PROCP1V2);
(* Set Content and primitive part function. d is a domain and
and p2v3 is a procedure of 2 LIST and 3 VAR LIST arguments.*)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetCppFunc: No valid domain.");
              RETURN END;
(*2*) Pdomain[INTEGER(d)].PCppFunc:=p1v2;
(*9*) END SetPCppFunc;


PROCEDURE SetPFactFunc(d: Domain; f1: PROCF1);
(* Set factorization function in domain.
   d is a domain and f1 is a function of one LIST argument. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPFactFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PFactFunc:=f1;
END SetPFactFunc;


PROCEDURE SetPNormFunc(d: Domain; f2: PROCF2);
(* Set polynomial normalform function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPNormFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PNormFunc:=f2;
END SetPNormFunc;


PROCEDURE SetProdFunc(d: Domain; f2: PROCF2);
(*Set product function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetProdFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].ProdFunc:=f2;
(*9*) END SetProdFunc;


PROCEDURE SetPSpolFunc(d: Domain; f2: PROCF2);
(* Set polynomial S-polynomial function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPSpolFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PSpolFunc:=f2;
END SetPSpolFunc;


PROCEDURE SetPSqfrFunc(d: Domain; f1: PROCF1);
(* Set polynomial squarefree factorization function in domain.
   d is a domain and f1 is a function of one LIST argument. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPSqfrFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PSqfrFunc:=f1;
END SetPSqfrFunc;


PROCEDURE SetPSugNormFunc(d: Domain; f2: PROCF2);
(* Set polynomial normal with sugar strategy normalform function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPSugNormFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PSugNormFunc:=f2;
END SetPSugNormFunc;


PROCEDURE SetPSugSpolFunc(d: Domain; f2: PROCF2);
(* Set polynomial normal with sugar strategy S-polynomial function in domain.
   d is a domain and f2 is a function of two LIST arguments. *)
BEGIN
   IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
      ERROR(fatal,"SetPSugSpolFunc: No valid domain.");
      RETURN;
   END;
   Pdomain[INTEGER(d)].PSugSpolFunc:=f2;
END SetPSugSpolFunc;


PROCEDURE SetQrFunc(d: Domain; p2v2: PROCP2V2);
(*Set quotient and remainder function in domain. d is a domain 
and p2v2 is a procedure of 2 LIST and 2 var LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetQrFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].QrFunc:=p2v2;
(*9*) END SetQrFunc;


PROCEDURE SetQuotFunc(d: Domain; f2: PROCF2);
(*Set quotient function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetQuotFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].QuotFunc:=f2;
(*9*) END SetQuotFunc;


PROCEDURE SetReadFunc(d: Domain; f1: PROCF1);
(*Set read function in domain. d is a domain and 
f1 is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetReadFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].ReadFunc:=f1;
(*9*) END SetReadFunc;


PROCEDURE SetRemFunc(d: Domain; f2: PROCF2);
(*Set remainder function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetRemFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].RemFunc:=f2;
(*9*) END SetRemFunc;


PROCEDURE SetSignFunc(d: Domain; f1: PROCF1);
(*Set sign function in domain. d is a domain and 
f1 is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetSignFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].SignFunc:=f1;
(*9*) END SetSignFunc;


PROCEDURE SetSumFunc(d: Domain; f2: PROCF2);
(*Set sum function in domain. d is a domain and 
f2 is a function of two LIST arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetSumFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].SumFunc:=f2;
(*9*) END SetSumFunc;
 

PROCEDURE SetToipFunc(d: Domain; f1v1: PROCF1V1);
(*Set conversion-to-integer-polynomial function in domain. d is a domain 
and f1v1 is a function of one LIST and one VAR LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetToipFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].ToipFunc:=f1v1;
(*9*) END SetToipFunc;


PROCEDURE SetWritFunc(d: Domain; p1: PROCP1);
(*Set write function in domain. d is a domain and 
p1 is a procedure of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetWritFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].WritFunc:=p1;
(*9*) END SetWritFunc;


PROCEDURE SetVlddFunc(d: Domain; f1: PROCF1);
(*Set variable list from domain descriptor function in domain. 
d is a domain and f is a function of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetVlddFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].VlddFunc:=f1;
(*9*) END SetVlddFunc;


PROCEDURE SetDdrdFunc(d: Domain; f0: PROCF0);
(*Set domain descriptor read function in domain. d is a domain 
and f0 is a function with no arguments. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d));
              ERROR(fatal,"SetDdrdFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].DdrdFunc:=f0;
(*9*) END SetDdrdFunc;


PROCEDURE SetDdwrFunc(d: Domain; p1: PROCP1);
(*Set domain descriptor write function in domain. d is a domain 
and p1 is a procedure of one LIST argument. *)
BEGIN
(*1*) IF (1 > d) OR (d > maxdom) THEN OWRITE(LIST(d)); 
              ERROR(fatal,"SetDdwrFunc: No valid domain.");
              RETURN END;
(*2*) domain[INTEGER(d)].DdwrFunc:=p1;
(*9*) END SetDdwrFunc;


PROCEDURE NewDom(S, s: ARRAY OF CHAR): Domain;
(*New domain. S is a domain identificator and s is a domain name.
A new domain is returned. *)
BEGIN
(*1*) IF curdom >= maxdom THEN
         ERROR(fatal,"NewDom: No space for new domains.");
         RETURN(0) END;
(*2*) curdom:=curdom+1; domain[curdom].name:=LISTS(s);
      domain[curdom].Sym:=ENTER(LISTS(S));
      RETURN(Domain(curdom));
(*9*) END NewDom;


PROCEDURE DomSummary(); 
(*Arbitrary domain summary. A summary of all defined domains 
is written to the output stream. *)
VAR   l: LIST;
      i: INTEGER; 
BEGIN
(*1*) SWRITE("List of all defined domains"); BLINES(1);
(*2*) (*loop on domain array. *) i:=0; l:=0; 
      WHILE i < maxdom DO i:=i+1; 
            IF domain[i].Sym <> Dummy THEN l:=l+1; 
               SYWRIT(domain[i].Sym); SWRITE(" "); 
               CLOUT(domain[i].name); BLINES(0);
               END;
            END;
(*3*) (*summary. *)
      IF l > 0 THEN BLINES(1) END;
      OWRITE(l); SWRITE(" defined domains."); BLINES(1);
(*5*) END DomSummary;


PROCEDURE Dummyf0(): LIST;
(*Dummy function 0. An ERROR occurs if this function is called. *)
BEGIN
(*1*) ERROR(fatal,"Dummyf0: Undefined function.");
      RETURN(SIL);
(*9*) END Dummyf0;


PROCEDURE Dummyp1(A: LIST);
(*Dummy procedure 1. An ERROR occurs if this procedure is called. *)
BEGIN
(*1*) OWRITE(A);
      ERROR(fatal,"Dummyp1: Undefined procedure.");
      RETURN;
(*9*) END Dummyp1;


PROCEDURE Dummyf1(A: LIST): LIST;
(*Dummy function 1. An ERROR occurs if this function is called. *)
BEGIN
(*1*) OWRITE(A);
      ERROR(fatal,"Dummyf1: Undefined function.");
      RETURN(SIL);
(*9*) END Dummyf1;


PROCEDURE Dummyf2(A, B: LIST): LIST;
(*Dummy function 2. An ERROR occurs if this function is called. *)
BEGIN
(*1*) OWRITE(A); OWRITE(B);
      ERROR(fatal,"Dummyf2: Undefined function.");
      RETURN(SIL);
(*9*) END Dummyf2;


PROCEDURE Dummyf1b(A: LIST): BOOLEAN;
(*Dummy boolean function 1. An ERROR occurs if this function is called. *)
BEGIN
(*1*) OWRITE(A);
      ERROR(fatal,"Dummyf1b: Undefined function.");
      RETURN(FALSE);
(*9*) END Dummyf1b;


PROCEDURE Dummyf1v1(A: LIST; VAR B: LIST): LIST;
(*Dummy function 1v1. An ERROR occurs if this function is called. *)
BEGIN
(*1*) OWRITE(A); OWRITE(B); (* Contents of B will usually be undefined *)
      ERROR(fatal,"Dummyf1v1: Undefined function.");
      RETURN(SIL); 
(*9*) END Dummyf1v1;


PROCEDURE Dummyp1v2(A: LIST; VAR C, D: LIST);
(*Dummy procedure 2v2. An ERROR occurs if this procedure is called. *) 
BEGIN 
(*1*) OWRITE(A);  (* Contents of C, D will usually be undefined *)
      ERROR(fatal,"Dummyp1v2: Undefined procedure.");
      RETURN; 
(*9*) END Dummyp1v2;


PROCEDURE Dummyp2v2(A, B: LIST; VAR C, D: LIST);
(*Dummy procedure 2v2. An ERROR occurs if this procedure is called. *) 
BEGIN 
(*1*) OWRITE(A); OWRITE(B); (* Contents of C, D will usually be undefined *)
      ERROR(fatal,"Dummyp2v2: Undefined procedure.");
      RETURN; 
(*9*) END Dummyp2v2;


PROCEDURE Dummyp2v3(A, B: LIST; VAR C, D, E: LIST);
(*Dummy procedure 2v3. An ERROR occurs if this procedure is called. *) 
BEGIN 
(*1*) OWRITE(A); OWRITE(B); (* Contents of C, D, E will usually be undefined *)
      ERROR(fatal,"Dummyp2v3: Undefined procedure.");
      RETURN; 
(*9*) END Dummyp2v3;


PROCEDURE InitADom();
(*Initialize arbitrary domains. *)
VAR   i, j: INTEGER;
      u: LIST;
BEGIN
(*1*) curdom:=0; Dummy:=ENTER(LISTS("Dummy"));
      u:=LISTS("Undefined");
(*2*) i:=0; 
      WHILE i < maxdom DO i:=i+1;
            domain[i].name:=u; LISTVAR(domain[i].name); 
            domain[i].Sym:=Dummy;
            domain[i].AbsFunc:=Dummyf1;
            domain[i].CnstFunc:=Dummyf1b;
            domain[i].CompFunc:=Dummyf2;
            j:=0;
            WHILE j < maxdom DO j:=j+1;
                  domain[i].ConvFunc[j]:=Dummyf1;
                  END;
            domain[i].DifFunc:=Dummyf2;
            domain[i].ExpFunc:=Dummyf2;
            domain[i].FactFunc:=Dummyf1;
            domain[i].FactoFunc:=Dummyf1;
            domain[i].FIntFunc:=Dummyf2;
            domain[i].FIPolFunc:=Dummyf2;
            domain[i].GcdFunc:=Dummyf2;
            domain[i].GcdcFunc:=Dummyp2v3;
            domain[i].GcdeFunc:=Dummyp2v3;
            domain[i].InvFunc:=Dummyf1;
            domain[i].InvTFunc:=Dummyf1;
            domain[i].ProdFunc:=Dummyf2;
            domain[i].QrFunc:=Dummyp2v2;
            domain[i].QuotFunc:=Dummyf2;
            domain[i].ReadFunc:=Dummyf1;
            domain[i].QuotFunc:=Dummyf2;
            domain[i].RemFunc:=Dummyf2;
            domain[i].SignFunc:=Dummyf1;
            domain[i].SumFunc:=Dummyf2;
            domain[i].ToipFunc:=Dummyf1v1;
            domain[i].WritFunc:=Dummyp1;
            domain[i].VlddFunc:=Dummyf1;
            domain[i].DdrdFunc:=Dummyf0;
            domain[i].DdwrFunc:=Dummyp1;
            END;
(*9*) END InitADom;


PROCEDURE InitADomP();
(* Initialize arbitrary domains polynomial. *)
VAR   i: INTEGER;
BEGIN
   FOR i:=1 TO maxdom DO
      Pdomain[i].PFactFunc   :=Dummyf1;
      Pdomain[i].PNormFunc   :=Dummyf2;
      Pdomain[i].PSpolFunc   :=Dummyf2;
      Pdomain[i].PSqfrFunc   :=Dummyf1;
      Pdomain[i].PSugNormFunc:=Dummyf2;
      Pdomain[i].PSugSpolFunc:=Dummyf2;
      Pdomain[i].PCppFunc    :=Dummyp1v2;
   END;
END InitADomP;


BEGIN 

     InitADom;
     InitADomP;

END MASADOM.
(* -EOF- *)
