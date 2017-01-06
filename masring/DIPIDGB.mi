(* ----------------------------------------------------------------------------
 * $Id: DIPIDGB.mi,v 1.1 1993/05/11 10:13:21 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: DIPIDGB.mi,v $
 * Revision 1.1  1993/05/11  10:13:21  kredel
 * Initial Revision
 *
 * ----------------------------------------------------------------------------
 *)

IMPLEMENTATION MODULE DIPIDGB;

(* DIP Integral D-Groebner Bases Implementation Module. *)


(* Author: Mark, Uni Passau, 1992. *)


FROM MASSTOR IMPORT LIST, SIL, LENGTH, SFIRST, SRED,
                    FIRST, RED, COMP, INV, ADV, LIST1,
                    CELLS, TIME, BETA;
                    (* BETA = NIL im Interpreter = SIL bei MODULA2 *)

FROM SACLIST IMPORT FIRST3, LIST3, LIST2, CCONC, CONC, LAST, CINV,
                    SECOND, FIRST2,
                    OWRITE,THIRD,FIRST4, LIST4, EQUAL, RED2, AWRITE, 
                    COMP2, ADV2;

FROM MASBIOS IMPORT BLINES, SWRITE;

FROM SACI IMPORT    IPROD, ISUM, IABSF, INEG, ILCM, IQ, IQR, IEGCD,
                    IWRITE, ICOMP, IREM, ISIGNF, IDIF, IGCDCF;

FROM DIPC IMPORT    DIPFMO, DIPMAD, DIPEVL, DIPLBC,
                    VALIS, EVCOMP, EVDIF, EVLCM, EVMT, EVSUM,
                    EVSIGN, DIPLPM,DIPNOV,DIPMCP;

FROM DIPI IMPORT    DIIPDF, DIIPWR, DIIPPR, DIIPSM, DIILWR,
                    DIILRD, DIIPCP, DIIPON, DIIPIP;


CONST rcsidi = "$Id: DIPIDGB.mi,v 1.1 1993/05/11 10:13:21 kredel Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1993 Universitaet Passau";



PROCEDURE DIIPELIMDGB(P : LIST) : LIST;
(*Distributive integral polynomial eliminate D-groebner base.
P is a list of non zero polynomials in distributive
integral representation in r variables.
ELIMDGB eliminates the polynominials with respect
to the divisibility of the highest monominials. *)

VAR Pr, Pf, Qr, Qf, Q, Qv, Qd, HTPf, HTQf, HKPf, HKQf : LIST;

BEGIN
(*1*) Q:=SIL;
      IF P = SIL THEN RETURN(Q); END;
      IF RED(P) = SIL THEN RETURN(P); END;
(*2*) Pr:=P;
    LOOP
        ADV(Pr,Pf,Pr);
        IF Q = SIL
        THEN
            Q:=LIST1(Pf);
            IF Pr = SIL
            THEN RETURN(Q);
            END;
            ADV(Pr,Pf,Pr);
        END;
        HTPf:=DIPEVL(Pf);
        HKPf:=DIPLBC(Pf);
        Qr:=Q;
        LOOP
            Qv:=Qr;
            ADV(Qr,Qf,Qr);
            HTQf:=DIPEVL(Qf);
            HKQf:=DIPLBC(Qf);
            IF EVMT(HTPf,HTQf) = 1
               THEN
                   IF ISIGNF(IREM(HKPf,HKQf)) = 0
                      THEN EXIT;
                   END;
            END;
            IF EVMT(HTQf,HTPf) = 1
               THEN
               IF ISIGNF(IREM(HKQf,HKPf)) = 0
                  THEN
                    IF Q = Qv
                    THEN Q:=Qr;
                    ELSE
                        Qd:=Q;
                        WHILE RED(Qd) <> Qv DO
                            Qd:=RED(Qd);
                        END;
                        SRED(Qd,Qr);
                        Qv:=Qd;
                    END;
                END;
            END;
            IF Qr = SIL THEN Q:=COMP(Pf,Q); EXIT; END;
        END;
        IF Pr = SIL THEN EXIT; END;
    END;
(*9*) RETURN(Q); END DIIPELIMDGB;



PROCEDURE DIIPTDR(P, lcmHT, pair : LIST): LIST;
(*Distributive integral polynomial top-D-reduzibel. P is a list
of non zero polynomials in distributive integral
representation in r variables.
pair is a pair two integral polynomials in
distributive representation.
lcmHT is the lcm of the highest terms of the two
polynomials.
TDR is a boolean value which equals 1, if g is top-D-
reduzibel modulo P and 0 if not. *)

VAR  HKg1, HKg2, HKg, HTg, PP, g : LIST;

BEGIN
(*1*) (*s=0. *)
      IF P = SIL THEN RETURN(0); END;
(*2*) (*reduction step.*)
      HKg1:=DIPLBC(FIRST(pair));
      HKg2:=DIPLBC(SECOND(pair));
      PP:=P;
    REPEAT
           ADV(PP, g, PP);
           HTg:=DIPEVL(g);
           HKg:=DIPLBC(g);
           IF EVMT(lcmHT,HTg) = 1
        THEN
              IF (ISIGNF(IREM(HKg1,HKg)) = 0) AND (ISIGNF(IREM(HKg2,HKg)) = 0)
                 THEN RETURN(1);
              END;
        END;
    UNTIL PP = SIL;
(*3*) (*finish.*) RETURN(0);
(*6*) END DIIPTDR;



PROCEDURE DIIPCPLMS1(P : LIST) : LIST;
(*Distributive integral polynomial list construct pairs list merge sort.
P is a list of non zero polynomials in distributive
integral representation in r variables.
CPLMS1 sorts a constructed pairs list in the
following ascending order:
1. lcm of the highest terms
2. lcm of the highest coefficients
P will be changed. *)

VAR onestep, twostep, ret, end, icomp, evcomp : LIST;

BEGIN
(*1*) (* Wenn P leer sein sollte, dann fertig *)
      IF P = SIL THEN RETURN (P); END;
    (* Zuerst wird die Liste geteilt *)
    twostep:=RED(P);
    onestep:=P;
    LOOP
        IF twostep = SIL
        THEN EXIT;
        END;
        twostep:=RED(twostep);
        IF twostep = SIL
        THEN EXIT;
        END;
        twostep:=RED(twostep);
        onestep:=RED(onestep);
    END;
    IF RED(onestep) = SIL
    THEN RETURN (onestep);
    END;
    twostep:=RED(onestep);
        SRED(onestep,SIL);
        onestep:=DIIPCPLMS1(P);
        twostep:=DIIPCPLMS1(twostep);
    IF onestep = SIL
    THEN RETURN (twostep);
    ELSIF twostep = SIL
    THEN RETURN (onestep);
    END;
        evcomp:=EVCOMP(FIRST(FIRST(onestep)),FIRST(FIRST(twostep)));
    IF evcomp = -1
    THEN
                ret:=onestep;
        onestep:=RED(onestep);
    ELSIF evcomp = 1
    THEN
                ret:=twostep;
        twostep:=RED(twostep);
    ELSE
        icomp:=ICOMP(SECOND(FIRST(onestep)),SECOND(FIRST(twostep)));
        IF icomp = -1
        THEN
                        ret:=onestep;
            onestep:=RED(onestep);
        ELSIF icomp = 1
        THEN
                        ret:=twostep;
            twostep:=RED(twostep);

        ELSE
                        ret:=onestep;
            onestep:=RED(onestep);
        END;
    END;
    end:=ret;
    WHILE (onestep <> SIL) AND (twostep <> SIL) DO
        evcomp:=EVCOMP(FIRST(FIRST(onestep)),FIRST(FIRST(twostep)));
        IF evcomp = -1
        THEN
            SRED(end,onestep);
            onestep:=RED(onestep);
        ELSIF evcomp = 1
        THEN
            SRED(end,twostep);
            twostep:=RED(twostep);
        ELSE
        icomp:=ICOMP(SECOND(FIRST(onestep)),SECOND(FIRST(twostep)));
            IF icomp = -1
            THEN
                SRED(end,onestep);
                onestep:=RED(onestep);
            ELSIF icomp = 1
            THEN
                SRED(end,twostep);
                twostep:=RED(twostep);

            ELSE
                SRED(end,onestep);
                onestep:=RED(onestep);
            END;
        END;
        end:=RED(end);
    END;
    IF onestep = SIL
    THEN SRED(end,twostep);
    ELSE SRED(end,onestep);
    END;
(*9*) RETURN (ret); END DIIPCPLMS1;



PROCEDURE DIIPLM1(onestep, twostep : LIST) : LIST;
(*Distributive integral polynomial list merge sort.
P is a list of non zero polynomials in distributive
integral representation in r variables.
LM1 merges two (onestep, twostep) constructed
pairs lists in the same manner as DIIPLCPLMS1.
The lists onestep and twostep will be changed. *)

VAR ret, end, icomp, evcomp : LIST;

BEGIN
    IF onestep = SIL
    THEN RETURN(twostep)
    ELSIF twostep = SIL
    THEN RETURN(onestep)
    END;
    evcomp:=EVCOMP(FIRST(FIRST(onestep)),FIRST(FIRST(twostep)));
    IF evcomp = -1
    THEN
                ret:=onestep;
        onestep:=RED(onestep);
    ELSIF evcomp = 1
    THEN
                ret:=twostep;
        twostep:=RED(twostep);
    ELSE
        icomp:=ICOMP(SECOND(FIRST(onestep)),SECOND(FIRST(twostep)));
                IF icomp = -1
        THEN
                        ret:=onestep;
            onestep:=RED(onestep);
        ELSIF icomp = 1
        THEN
                        ret:=twostep;
            twostep:=RED(twostep);

        ELSE
                        ret:=onestep;
            onestep:=RED(onestep);
        END;
    END;
    end:=ret;
    WHILE (onestep <> SIL) AND (twostep <> SIL) DO
          evcomp:=EVCOMP(FIRST(FIRST(onestep)),FIRST(FIRST(twostep)));
        IF evcomp = -1
        THEN
            SRED(end,onestep);
            onestep:=RED(onestep);
        ELSIF evcomp = 1
        THEN
            SRED(end,twostep);
            twostep:=RED(twostep);
        ELSE
            icomp:=ICOMP(SECOND(FIRST(onestep)),SECOND(FIRST(twostep)));
            IF icomp = -1
            THEN
                SRED(end,onestep);
                onestep:=RED(onestep);
            ELSIF icomp = 1
            THEN
                SRED(end,twostep);
                twostep:=RED(twostep);

            ELSE
                SRED(end,onestep);
                onestep:=RED(onestep);
            END;
        END;
        end:=RED(end);
    END;
    IF onestep = SIL
    THEN SRED(end,twostep);
    ELSE SRED(end,onestep);
    END;
    RETURN (ret);
END DIIPLM1;



PROCEDURE DIIPUCPL1(P, g, Old : LIST) : LIST;
(*Distributive polynomial D-update constructed pairs list.
P is a list of integral polynomials in distributive
representation. g ist a polynomial in distributive
representation. Both are polynomials in r variables.
Old is the constructed and sorted pairs
list to be updated. *)

VAR Update, Up, Upel, Pr, Pf, pair, a1, a2, t1, t2, lcmHT, lcmHK : LIST;


BEGIN
(*1*) IF P = SIL THEN RETURN(Old); END;
      IF g = 0 THEN RETURN(Old); END;
      Up:=SIL;
      t1:=DIPEVL(g);
      a1:=DIPLBC(g);
    Pr:=P;
    REPEAT
        ADV(Pr,Pf,Pr);
        t2:=DIPEVL(Pf);
        a2:=DIPLBC(Pf);
                lcmHT:=EVLCM(t1,t2);
                lcmHK:=ILCM(a1,a2);
                pair:=LIST2(g,Pf);
                Upel:=LIST3(lcmHT,lcmHK,pair);
        Up:=COMP(Upel,Up);
    UNTIL (Pr = SIL);
      Up:=DIIPCPLMS1(Up);
      IF Old = SIL THEN RETURN(Up); END;
      Update:=DIIPLM1(Up,Old);
(*9*) RETURN(Update); END DIIPUCPL1;



PROCEDURE DIIPGPOL(g1,g2: LIST): LIST;
(*Distributive integral polynomial g polynomial. g1 and g2 are
integral polynomials in distributive representation. GPOL is
the G-polynomial of g1 and g2. *)

VAR   a1, g1r, g1rp, a2, g2r, g2rp, GPol,
          gcdHK, t1, s1, t2, s2, c1, c2, lcmHT: LIST;
BEGIN
(*1*) (*a=0 or b=0. *)
    GPol:=0;
    IF (g1 = 0) OR (g2 = 0) (* gcd(0,a) = a, lcm(0,a) = 0, *)
        THEN RETURN(GPol); END;
    DIPMAD(g1, a1,t1,g1r); (* a1 = HK(g1), t1 = HT(g2) *)
    DIPMAD(g2, a2,t2,g2r); (* a2 = HK(g2), t2 = HT(g2) *)
                           (* g1r = g1 - HM(g1) *)
                           (* g2r = g2 - HM(g2) *)
    IEGCD(a1,a2,gcdHK,c1,c2);
        IF ISIGNF(c1) = 0      (* GPol = c2*s2*g2 *)
    THEN
                lcmHT:=EVLCM(t1,t2);
                s2:=EVDIF(lcmHT,t2);
                g2rp:=DIPFMO(c2,s2);
                GPol:=DIIPPR(g2,g2rp);
        RETURN(GPol);
    END;
        IF ISIGNF(c2) = 0           (* GPol = c1*s1*g1 *)
    THEN
                lcmHT:=EVLCM(t1,t2);
                s1:=EVDIF(lcmHT,t1);
                g1rp:=DIPFMO(c1,s1);
                GPol:=DIIPPR(g1,g1rp);
        RETURN(GPol);
    END;
(*2*) (*general case. *)
      lcmHT:=EVLCM(t1,t2);
      s1:=EVDIF(lcmHT,t1);
      s2:=EVDIF(lcmHT,t2);
      g1rp:=DIPFMO(c1,s1);
      g2rp:=DIPFMO(c2,s2);
      g1rp:=DIIPPR(g1,g1rp);
      g2rp:=DIIPPR(g2,g2rp);
      GPol:=DIIPSM(g1rp,g2rp); (* GPol = c1*s1*g1 + c2*s2*g2 *)
(*6*) RETURN(GPol); END DIIPGPOL;



PROCEDURE DIIPSPOL2(g1, g2, lcmHT, lcmHK: LIST): LIST;
(*Distributive integral polynomial s polynomial. g1 and g2 are
integral polynomials in distributive representation.
lcmHT is the lcm of the highest terms of g1 and g2.
lcmHK is the lcm of the highest coefficients of g1 and g2.
polynomials in pair.
SPol is the S-polynomial of g1 and g2. *)

VAR   a1, b1, g1r, g1rp, a2, b2, g2r, g2rp, SPol,
      t1, s1, t2, s2 : LIST;
BEGIN
(*1*) (*a=0 or b=0. *) SPol:=0;
    IF (g1 = 0) OR (g2 = 0)
    THEN RETURN(SPol);          (* SPol = 0 *)
    END;
      DIPMAD(g1, a1,t1,g1r); (* a1 = HK(g1), t1 = HT(g2), a2 = HK(g2) *)
      DIPMAD(g2, a2,t2,g2r); (* t2 = HT(g2) g1r = g1 - HM(g1) *)
                             (* g2r = g2 - HM(g2) *)
    IF (g1r = SIL) AND (g2r = SIL)
    THEN RETURN(SPol);          (* SPol = 0 *)
    END;
(*2*) (* reduction. *)
        IF g1r = SIL
    THEN
        s2:=EVDIF(lcmHT,t2);    (* s2 = lcmHT/t2 *)
        b2:=IQ(lcmHK,a2);               (* b2 = lcmHK/a2 *)
        b2:=INEG(b2);           (* b2 = -b2 *)
        g2rp:=DIPFMO(b2,s2);    (* g2rp = -b2*s2 *)
        SPol:=DIIPPR(g2r,g2rp); (* SPol = -b2*s2*g2 *)
        RETURN(SPol);
    END;
        IF g2r = SIL
    THEN
        s1:=EVDIF(lcmHT,t1);
        b1:=IQ(lcmHK,a1);
        g1rp:=DIPFMO(b1,s1);
        SPol:=DIIPPR(g1r,g1rp);
        RETURN(SPol);
    END;
(*3*) (* general case. *)
      s1:=EVDIF(lcmHT,t1);
      b1:=IQ(lcmHK,a1);
      s2:=EVDIF(lcmHT,t2);
      b2:=IQ(lcmHK,a2);
      g1rp:=DIPFMO(b1,s1);
      g2rp:=DIPFMO(b2,s2);
      g1rp:=DIIPPR(g1r,g1rp);
      g2rp:=DIIPPR(g2r,g2rp);
      SPol:=DIIPDF(g1rp,g2rp);  (* SPol = b1*s1*g1 - b2*s2*g2 *)
(*6*) RETURN(SPol); END DIIPSPOL2;



PROCEDURE DIIPLEXTAL(AL, g : LIST) : LIST;
(*Distributive integral polynomial list extend array list.
AL is an array list.
g is a polynomial in distributive representation
in r variables.
Ag is the extended array list of AL.
The list AL is modified. *)

VAR i, j, nulll, gp, Ag : LIST;

BEGIN
(*1*) IF g = 0 THEN RETURN(AL); END;
        IF AL = SIL
    THEN
        Ag:=LIST1(LIST2(g,LIST1(1)));
        RETURN(Ag); (* hier steht die Laenge des Polynoms *)
    END;
    i:=FIRST(SECOND(FIRST(AL)));
    j:=0;
    nulll:=SIL;
    WHILE j < i DO
          nulll:=COMP(0,nulll);
          j:=j+1;
          END;
    gp:=LIST2(g,nulll);
    Ag:=AL;
    SRED(LAST(Ag),LIST1(gp));
    SFIRST(SECOND(FIRST(Ag)),i+1);
(*9*) RETURN(Ag); END DIIPLEXTAL;



PROCEDURE DIIPLCPL4(P : LIST; VAR CPL, AL : LIST);
(*Distributive integral polynomial list construct pair list.
P is a list of polynomials in distributive
representation in r variables.
CPL is the constructed pairs list, AL is the
Array list. *)

VAR CPLel, Pf, Pr , Pfp, Prp, t1, t2, lcmHT, a1, a2, lcmHK : LIST;

BEGIN
(*1*) IF P = SIL THEN RETURN; END;
      IF RED(P) = SIL THEN RETURN; END;
    Pr:=P;
    REPEAT
        ADV(Pr,Pf,Pr);
        AL:=DIIPLEXTAL(AL,Pf);
        t1:=DIPEVL(Pf);
        a1:=DIPLBC(Pf);
        Prp:=Pr;
            REPEAT
                ADV(Prp,Pfp,Prp);
                t2:=DIPEVL(Pfp);
                a2:=DIPLBC(Pfp);
                lcmHT:=EVLCM(t1,t2);
                lcmHK:=ILCM(a1,a2);
                CPLel:=LIST3(lcmHT,lcmHK,LIST2(Pf,Pfp));
                CPL:=COMP(CPLel,CPL);
            UNTIL Prp = SIL;
    UNTIL RED(Pr) = SIL;
      AL:=DIIPLEXTAL(AL,FIRST(Pr));
(*9*) END DIIPLCPL4;


PROCEDURE DIIPALCMPC(AL, g1, g2, flag : LIST) : LIST;
(*Distributive integral polynomial array list check and mark polynomials.
AL is an array list. g1, g2 are polynomials in
distributive representation in r variables.
flag determines whether the pair will be
marked as computed or only checked. 1 means to
mark 0 only to check.
The value 1 is returned if the pair (g1,g2) is
already computed otherwise 0 is returned. *)

VAR i, j , Ar, Af, Aff, Afr, nulll : LIST;

BEGIN
(*1*) IF AL = SIL THEN RETURN(0); END;
        IF (g1 = 0) OR (g2 = 0)
        THEN RETURN(0);
    END;
        IF g1 = g2
        THEN RETURN(0);
    END;
        Ar:=AL;
(*2*) i:=0; j:=0;
    LOOP
        i:=i+1;
        ADV(Ar,Af,Ar);
        FIRST2(Af,Aff,Afr);
        IF ((Aff = g1) OR (Aff = g2)) AND (j = 0)
        THEN
            j:=i;
            IF Ar = SIL
            THEN EXIT;
            END;
            ADV(Ar,Af,Ar);
            FIRST2(Af,Aff,Afr);
        END;
        IF ((Aff = g1) OR (Aff = g2)) AND (j <> 0)
        THEN
            nulll:=Afr;
            i:=1;
            WHILE (i < j) AND (nulll <> SIL) DO
                  nulll:=RED(nulll);
                  i:=i+1;
            END;
            IF nulll = SIL
               THEN RETURN(0);
            ELSE
                IF flag = 1
                THEN SFIRST(nulll,1);
                END;
                IF FIRST(nulll) = 1
                THEN RETURN(1);
                ELSE RETURN(0);
                END;
            END;
        END;
        IF Ar = SIL THEN EXIT; END;
    END;
(*9*) RETURN(0); END DIIPALCMPC;



PROCEDURE crit1(pair : LIST) : LIST;
(*Distributive polymomial criterion1.
pair is a pair two integral polynomials in
distributive representation.
criterion1 returns 1 if the highest coeffizients of
the two polynomials are divisible otherwise it
returns 0. *)

VAR HKQf, HKPf : LIST;

BEGIN
(*1*) IF pair = SIL THEN RETURN 0 END;
    HKQf:=DIPLBC(FIRST(pair));
    HKPf:=DIPLBC(SECOND(pair));
    IF ISIGNF(IREM(HKPf,HKQf)) = 0  (* HKQf teilt HKPf! *)
    THEN RETURN(1);
    END;
    IF ISIGNF(IREM(HKQf,HKPf)) = 0  (* HKPf teilt HKQf! *)
    THEN RETURN(1);
    END;
(*9*) RETURN(0); END crit1;



PROCEDURE crit2(pair, lcmHT, lcmHK : LIST) : LIST;
(*Distributive polymomial criterion2.
pair is a pair two integral polynomials in
distributive representation.
lcmHT is the lcm of the highest terms of the two
polynomials in pair.
lcmHK is the lcm of the highest coefficients of the two
polynomials in pair.
criterion2 returns 1 if the highest monomials of
the two polynomials are disjoint otherwise it
returns 0. *)

VAR prodHT, prodHK : LIST;

BEGIN
(*1*) IF pair = SIL THEN RETURN 0 END;
      prodHT:=EVSUM(DIPEVL(FIRST(pair)),DIPEVL(SECOND(pair)));
    IF EVCOMP(lcmHT,prodHT) = 0
    THEN
        prodHK:=IABSF(IPROD(DIPLBC(FIRST(pair)),DIPLBC(SECOND(pair))));
        IF ICOMP(lcmHK,prodHK) = 0
        THEN RETURN(1);
        END;
    END;
(*9*) RETURN(0); END crit2;




PROCEDURE crit3(AL, pair, lcmHT, lcmHK : LIST) : LIST;
(*Distributive polymomial criterion3.
pair is a pair two integral polynomials in
distributive representation.
AL is the constructed pairs list.
lcmHT is the lcm of the highest terms of the two
polynomials in pair.
lcmHK is the lcm of the highest coefficients of the two
polynomials in pair.
criterion3 returns 1 if (4) of the D-greobner base
algorithm is true otherwise it returns 0. *)

VAR p, Af, Ar, Aff, Afr, HTAf, HKAf : LIST;

BEGIN
(*1*) IF pair = SIL THEN RETURN 0 END;
      IF AL = SIL THEN RETURN(0); END;
      p:=0;
(*2*) Ar:=AL;
    LOOP
        ADV(Ar,Af,Ar);
        ADV(Af,Aff,Afr);
        HTAf:=DIPEVL(Aff);
        HKAf:=DIPLBC(Aff);
        IF EVMT(lcmHT,HTAf) = 1
           THEN
           IF ISIGNF(IREM(lcmHK,HKAf)) = 0
              THEN
              p:=Aff;
              EXIT;
           END;
        END;
        IF Ar = SIL THEN EXIT; END;
    END;
    IF p = 0 THEN RETURN(0); END;
    IF (DIIPALCMPC(AL,p,FIRST(pair),0) = 1) 
       AND (DIIPALCMPC(AL,p,SECOND(pair),0) = 1)
    THEN RETURN(1);
    ELSE RETURN(0);
    END;
(*9*) END crit3;


PROCEDURE DIIPENF(P,varl,g: LIST): LIST;
(*Distributive integral polynomial e-normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. g is a distributive
integral polynomial. ENF is a polynomial such that
g is e-reducible to ENF modulo P and ENF is in
E-normalform modulo P. *)

VAR q, ap, app, b, c, s, PP, p, pa, pt, pr, ENF, rp, rs, teilt, gr, ga,
      gt, gf, rest: LIST;
BEGIN
(*1*) (*s=0. *)
      IF g = 0 THEN ENF:=varl; RETURN(ENF); END;
        IF P = SIL
        THEN
                IF varl = 0
                THEN ENF:=g;
                ELSE ENF:=CCONC(varl,g);
                END;
                RETURN(ENF);
      END;
(*2*) (*reduction step.*) gf:=g; ENF:=varl;
    REPEAT
         DIPMAD(gf, ga,gt,gr); (* ga = HK(g), gt = HT(g), *)
                               (* gr = g - HM(g) *)
                IF gr = SIL THEN gr:=0; END;
        PP:=P;
        LOOP
            ADV(PP, p,PP);
            DIPMAD(p, pa,pt,pr); (* pa = HK(p), pt = HT(p), *)
                                 (* pr = p - HM(p) *)
            teilt:=EVMT(gt,pt);
            IF (teilt = 1)
            THEN
                IQR(ga,pa,q,rest); (* q = ga div pa, rest = ga-q*pa *)
                IF ISIGNF(rest) = 0
                THEN
                    IF pr <> SIL
                       THEN
                       s:=EVDIF(gt,pt);    (* s = gt div pt *)
                       ap:=DIPFMO(q,s);    (* ap = q*s *)
                       app:=DIIPPR(pr,ap); (* app = pr*ap *)
                       gr:=DIIPDF(gr,app); (* gr = gr-app *)
                       END;
                    gf:=gr;
                    EXIT;
                ELSE
                 IF ISIGNF(q) <> 0
                    THEN
                        s:=EVDIF(gt,pt); (* s = gt div pt *)
                        IF ISIGNF(ga) = -1 (*nur wegen eind. pos. rest*)
                        THEN
                            IF ISIGNF(q) = 1
                               THEN q:=ISUM(q,1);
                               ELSE q:=IDIF(q,1);
                            END;
                        END;
                        ap:=DIPFMO(q,s);     (* ap = q*s *)
                        app:=DIIPPR(p,ap);   (* app = ap*pr *)
                        gf:=DIIPDF(gf,app);
                        DIPMAD(gf, ga,gt,gr);
                        IF gr = SIL THEN gr:=0; END;
                    END;
                END;
            END;
            IF (PP = SIL)
            THEN
                rp:=DIPFMO(ga,gt);
                IF ENF = 0
                THEN ENF:=rp;
                ELSE ENF:=CONC(ENF,rp);
                END;
                gf:=gr;
                EXIT;
            END;
        END;
        UNTIL gr = 0;
(*3*) (*finish.*) RETURN(ENF);
(*6*) END DIIPENF;



PROCEDURE DIIPREDDGB(P : LIST) : LIST;
(*Distributive integral polynomial reduce D-groebner base.
P is a list of non zero polynomials in distributive
integral representation in r variables.
REDDGB reduces the polynominials.
It is nescessary that the highest monomials are
pairwise disjoint. *)

VAR Q, Qf, Qr, Qred, len, i : LIST;

BEGIN
(*1*) Q:=SIL; len:=LENGTH(P);
      IF len < 2 THEN RETURN(P); END;
      Q:=CINV(P);
      Qr:=Q;
(*2*) i:=0;
      WHILE i < len DO ADV(Qr,Qf,Qr); Qred:=DIIPENF(Qr,0,Qf);
            IF Qred <> 0 THEN Qr:=CONC(Qr,LIST1(Qred));
                         ELSE len:=len-1; END;
            i:=i+1; END;
      Q:=INV(Qr);
(*9*) RETURN(Q); END DIIPREDDGB;



PROCEDURE DIIPSPOL(g1,g2: LIST): LIST;
(*Distributive integral polynomial s polynomial. g1 and g2 are
integral polynomials in distributive representation.
SPol is the S-polynomial of g1 and g2. *)

VAR   a1, b1, g1r, g1rp, a2, b2, g2r, g2rp, SPol,
          lcmHK, t1, s1, t2, s2, lcmHT: LIST;
BEGIN
(*1*) (*a=0 or b=0. *) SPol:=0;
    IF (g1 = 0) OR (g2 = 0)
    THEN RETURN(SPol);         (* SPol = 0 *)
    END;
        DIPMAD(g1, a1,t1,g1r); (* a1 = HK(g1), t1 = HT(g2), a2 = HK(g2) *)
        DIPMAD(g2, a2,t2,g2r); (* t2 = HT(g2) g1r = g1 - HM(g1) *)
                               (* g2r = g2 - HM(g2) *)
    IF (g1r = SIL) AND (g2r = SIL)
    THEN RETURN(SPol);         (* SPol = 0 *)
    END;
(*2*) (* reduction. *)
      lcmHT:=EVLCM(t1,t2);   (* lcmHT = lcm of the highest terms *)
      lcmHK:=ILCM(a1,a2);    (* lcmHK = lcm of the highest coeffic. *)
      IF g1r = SIL
    THEN
        s2:=EVDIF(lcmHT,t2);    (* s2 = lcmHT/t2 *)
        b2:=IQ(lcmHK,a2);       (* b2 = lcmHK/a2 *)
        b2:=INEG(b2);           (* b2 = -b2 *)
        g2rp:=DIPFMO(b2,s2);    (* g2rp = -b2*s2 *)
        SPol:=DIIPPR(g2r,g2rp); (* SPol = -b2*s2*g2 *)
        RETURN(SPol);
    END;
        IF g2r = SIL
    THEN
        s1:=EVDIF(lcmHT,t1);
        b1:=IQ(lcmHK,a1);
        g1rp:=DIPFMO(b1,s1);
        SPol:=DIIPPR(g1r,g1rp);
        RETURN(SPol);
    END;
(*3*) (* general case. *)
      s1:=EVDIF(lcmHT,t1);
      b1:=IQ(lcmHK,a1);
      s2:=EVDIF(lcmHT,t2);
      b2:=IQ(lcmHK,a2);
      g1rp:=DIPFMO(b1,s1);
      g2rp:=DIPFMO(b2,s2);
      g1rp:=DIIPPR(g1r,g1rp);
      g2rp:=DIIPPR(g2r,g2rp);
      SPol:=DIIPDF(g1rp,g2rp); (* SPol = b1*s1*g1 - b2*s2*g2 *)
(*6*) RETURN(SPol);
END DIIPSPOL;



PROCEDURE DIIPDNF(P,varl,g: LIST): LIST;
(*Distributive integral polynomial normal form. P is a list
of non zero polynomials in distributive integral
representation in r variables. g is a distributive
integral polynomial. NF is a polynomial such that
g is reducible to NF modulo P and NF is in
D-normalform modulo P. *)

VAR a, ap, app, b, c, f, PP, q, qa, qt, qr, NF, rp, rs, teilt, gr, ga,
      gt, rest: LIST;
BEGIN
(*1*) (*s=0. *)
      IF g = 0 THEN NF:=varl; RETURN(NF); END;
      IF P = SIL THEN
         IF varl = 0
            THEN NF:=g;
            ELSE NF:=CCONC(varl,g); END;
         RETURN(NF); END;
(*2*) (*reduction step.*) gr:=g; NF:=varl;
    REPEAT
        DIPMAD(gr, ga,gt,gr); (* ga = HK(g), gt = HT(g), *)
                              (* gr = g - HM(g) *)
                              (* Das Nullpolynom ist nicht die *)
        IF gr = SIL THEN gr:=0; END;
        PP:=P;
        REPEAT
                ADV(PP, q,PP);
                DIPMAD(q, qa,qt,qr); (* qa = HK(q), qt = HT(q), *)
                                     (* qr = q - HM(q) *)
                teilt:=EVMT(gt,qt);
                IQR(ga,qa,a,rest);
                UNTIL (PP = SIL) OR ((teilt = 1) AND (ISIGNF(rest) = 0));
                IF (teilt = 1) AND (ISIGNF(rest) = 0)
        THEN
                        IF qr <> SIL
                        THEN
                            f:=EVDIF(gt,qt);
                            ap:=DIPFMO(a,f);
                            app:=DIIPPR(qr,ap);
                            gr:=DIIPDF(gr,app);
                        END;
                ELSE
                        rp:=DIPFMO(ga,gt);
                        IF NF = 0
                        THEN NF:=rp;
                        ELSE NF:= CONC(NF,rp);
                        END;
        END;
                UNTIL gr = 0;
(*3*) (*finish.*) RETURN(NF);
(*6*) END DIIPDNF;



PROCEDURE DIIPDGB(F, TF : LIST): LIST;
(*Distributive integral polynomial D-groebner basis. F is a
list of integral polynomials in distributive representation
in r variables. G is the groebner basis of F. TF the trace flag. *)

VAR G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol,
    pair, h, hp, AL, dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2,
    NSPolkr3, NGPoltr : LIST;

BEGIN
(*1*) G:=F;
      IF G = SIL THEN RETURN(G); END;
      IF RED(G) = SIL THEN RETURN(G); END;
      B:=SIL;
      AL:=SIL;
      DIIPLCPL4(G,B,AL);      (* list construction *)
      B:=DIIPCPLMS1(B);       (* list sort *)
      D:=SIL;
      B1:=CINV(B);
      C:=INV(B1);
      infoSPol:=1;            (* info in G-loop *)
      infoGPol:=1;            (* info in S-loop *)
      AGPol:=0;
      NGPolkr1:=0;
      NGPoltr:=0;
      ASPol:=0;
      NSPolkr2:=0;
      NSPolkr3:=0;
      SPol:=0;
      GPol:=0;
    WHILE B <> SIL DO
        WHILE C <> SIL DO
            ADV(C,Cf,C);
            AGPol:=AGPol+1;
            FIRST3(Cf,lcmHT,lcmHK,pair);
            IF crit1(pair) = 1
            THEN
                hp:=0;
                NGPolkr1:=NGPolkr1+1;
                ELSIF DIIPTDR(G, lcmHT, pair) = 1
            THEN
                hp:=0;
                NGPoltr:=NGPoltr+1;
            ELSE
                h:=DIIPGPOL(FIRST(pair),SECOND(pair));
                hp:=DIIPDNF(G,0,h);
            END;
            IF hp <> 0
            THEN
                AL:=DIIPLEXTAL(AL,hp);
                D:=DIIPUCPL1(G,hp,D);
                G:=COMP(hp,G);
                GPol:=GPol+1;
            END;
            IF TF <> 0
            THEN
                IF infoGPol = TF
                THEN
                SWRITE("Number of computed G-polynomials: ");
                IWRITE(AGPol);BLINES(0);
                SWRITE("Cancelled due to criterion 1: ");
                IWRITE(NGPolkr1);BLINES(0);
                SWRITE("Cancelled due to top-D-reducibility: ");
                IWRITE(NGPoltr);BLINES(0);
                SWRITE("New polynomials added to G: ");
                IWRITE(GPol);BLINES(0);
                SWRITE("Number of critical pairs in D: ");
                IWRITE(LENGTH(D));BLINES(0);
                SWRITE("Number of critical pairs in C: ");
                IWRITE(LENGTH(C));BLINES(1);
                infoGPol:=1;
                ELSE infoGPol:=infoGPol+1;
                END;
            END;
        END;
        ADV(B,Bf,B);
        ASPol:=ASPol+1;
        FIRST3(Bf,lcmHT,lcmHK,pair);
        IF crit2(pair, lcmHT, lcmHK) = 1
        THEN
            hp:=0;
            NSPolkr2:=NSPolkr2+1;
            ELSIF crit3(AL, pair, lcmHT, lcmHK) = 1
        THEN
            hp:=0;
            NSPolkr3:=NSPolkr3+1;
        ELSE
                h:=DIIPSPOL2(FIRST(pair),SECOND(pair),lcmHT,lcmHK);
                hp:=DIIPDNF(G,0,h);
                END;
                dummy:=DIIPALCMPC(AL,FIRST(pair),SECOND(pair),1);
        IF hp <> 0
        THEN
            AL:=DIIPLEXTAL(AL,hp);
            D:=DIIPUCPL1(G,hp,D);
            G:=COMP(hp,G);
            SPol:=SPol+1;
        END;
        D1:=CINV(D);
        C:=INV(D1);
        B:=DIIPLM1(B,D);
        D:=SIL;
        IF TF <> 0
        THEN
            IF infoSPol = TF
            THEN
            SWRITE("Number of computed S-polynomials: ");
            IWRITE(ASPol);BLINES(0);
            SWRITE("Cancelled due to criterion 2: ");
            IWRITE(NSPolkr2);BLINES(0);
            SWRITE("Cancelled due to criterion 3: ");
            IWRITE(NSPolkr3);BLINES(0);
            SWRITE("New polynomials added to G: ");
            IWRITE(SPol);BLINES(0);
            SWRITE("Number of critical pairs in B: ");
            IWRITE(LENGTH(B));BLINES(0);
            SWRITE("Number of critical pairs in C: ");
            IWRITE(LENGTH(C));BLINES(1);
            infoSPol:=1;
            ELSE infoSPol:=infoSPol+1;
            END;
        END;
    END;
    IF TF <> 0
    THEN
        SWRITE("Number of computed G-polynomials: ");
        IWRITE(AGPol);BLINES(0);
        SWRITE("Cancelled due to criterion 1: ");
        IWRITE(NGPolkr1);BLINES(0);
        SWRITE("Cancelled due to top-D-reducibility: ");
        IWRITE(NGPoltr);BLINES(0);
        SWRITE("Number of computed S-polynomials: ");
        IWRITE(ASPol);BLINES(0);
        SWRITE("Cancelled due to criterion 2: ");
        IWRITE(NSPolkr2);BLINES(0);
        SWRITE("Cancelled due to criterion 3: ");
        IWRITE(NSPolkr3);BLINES(1);
        SWRITE("Number of polynomials in G before reduction: ");
        IWRITE(LENGTH(G));
        BLINES(0);
    END;
    G:=DIIPELIMDGB(G);
    IF TF <> 0
    THEN
        SWRITE("Number of polynomials in G after reduction: ");
        IWRITE(LENGTH(G));
        BLINES(1);
    END;
      G:=DIIPREDDGB(G);
(*9*) RETURN(G); END DIIPDGB;



PROCEDURE DIIPEGB(F, TF : LIST): LIST;
(*Distributive integral polynomial E-groebner basis. F is a
list of integral polynomials in distributive representation
in r variables. G is the groebner basis of F. TF the trace flag. *)

VAR G, B, B1, Bf, D, D1, C, Cf, lcmHT, lcmHK, egcdHK, infoSPol, infoGPol,
    pair, h, hp, AL, dummy, AGPol, ASPol, GPol, SPol, NGPolkr1, NSPolkr2,
    NSPolkr3, NGPoltr : LIST;

BEGIN
(*1*) G:=F;
      IF G = SIL THEN RETURN(G); END;
      IF RED(G) = SIL THEN RETURN(G); END;
      B:=SIL;
      AL:=SIL;
      DIIPLCPL4(G,B,AL);
      B:=DIIPCPLMS1(B);
      D:=SIL;
      B1:=CINV(B);
      C:=INV(B1);
      infoSPol:=1;
      infoGPol:=1;
      AGPol:=0;
      NGPolkr1:=0;
      NGPoltr:=0;
      ASPol:=0;
      NSPolkr2:=0;
      NSPolkr3:=0;
      SPol:=0;
      GPol:=0;
    WHILE B <> SIL DO
        WHILE C <> SIL DO
            ADV(C,Cf,C);
            AGPol:=AGPol+1;
            FIRST3(Cf,lcmHT,lcmHK,pair);
            IF crit1(pair) = 1
            THEN
                hp:=0;
                NGPolkr1:=NGPolkr1+1;
                        ELSIF DIIPTDR(G, lcmHT, pair) = 1
            THEN
                hp:=0;
                NGPoltr:=NGPoltr+1;
            ELSE
                h:=DIIPGPOL(FIRST(pair),SECOND(pair));
                hp:=DIIPENF(G,0,h);
            END;
            IF hp <> 0
            THEN
                AL:=DIIPLEXTAL(AL,hp);
                D:=DIIPUCPL1(G,hp,D);
                G:=COMP(hp,G);
                GPol:=GPol+1;
                (*SRED(LAST(G),LIST1(hp));*)
            END;
            IF TF <> 0
            THEN
                IF infoGPol = TF
                THEN
                    SWRITE("Number of computed G-polynomials: ");
                    IWRITE(AGPol);BLINES(0);
                    SWRITE("Cancelled due to criterion 1: ");
                    IWRITE(NGPolkr1);BLINES(0);
                    SWRITE("Cancelled due to top-D-reducibility: ");
                    IWRITE(NGPoltr);BLINES(0);
                    SWRITE("New polynomials added to G: ");
                    IWRITE(GPol);BLINES(0);
                    SWRITE("Number of critical pairs in D: ");
                    IWRITE(LENGTH(D));BLINES(0);
                    SWRITE("Number of critical pairs in C: ");
                    IWRITE(LENGTH(C));BLINES(1);
                    infoGPol:=1;
                ELSE infoGPol:=infoGPol+1;
                END;
            END;
        END;
        ADV(B,Bf,B);
        ASPol:=ASPol+1;
        FIRST3(Bf,lcmHT,lcmHK,pair);
        IF crit2(pair, lcmHT, lcmHK) = 1
        THEN
            hp:=0;
            NSPolkr2:=NSPolkr2+1;
        ELSIF crit3(AL, pair, lcmHT, lcmHK) = 1
        THEN
            hp:=0;
            NSPolkr3:=NSPolkr3+1;
        ELSE
            h:=DIIPSPOL2(FIRST(pair),SECOND(pair),lcmHT,lcmHK);
            hp:=DIIPENF(G,0,h);
            END;
        dummy:=DIIPALCMPC(AL,FIRST(pair),SECOND(pair),1);
        IF hp <> 0
        THEN
            AL:=DIIPLEXTAL(AL,hp);
            D:=DIIPUCPL1(G,hp,D);
            G:=COMP(hp,G);
            SPol:=SPol+1;
        END;
        D1:=CINV(D);
        C:=INV(D1);
        B:=DIIPLM1(B,D);
        D:=SIL;
        IF TF <> 0
        THEN
            IF infoSPol = TF
            THEN
                SWRITE("Number of computed S-polynomials: ");
                IWRITE(ASPol);BLINES(0);
                SWRITE("Cancelled due to criterion 2: ");
                IWRITE(NSPolkr2);BLINES(0);
                SWRITE("Cancelled due to criterion 3: ");
                IWRITE(NSPolkr3);BLINES(0);
                SWRITE("New polynomials added to G: ");
                IWRITE(SPol);BLINES(0);
                SWRITE("Number of critical pairs in B: ");
                IWRITE(LENGTH(B));BLINES(0);
                SWRITE("Number of critical pairs in C: ");
                IWRITE(LENGTH(C));BLINES(1);
                infoSPol:=1;
            ELSE infoSPol:=infoSPol+1;
            END;
        END;
    END;
    IF TF <> 0
    THEN
        SWRITE("Number of computed G-polynomials: ");
        IWRITE(AGPol);BLINES(0);
        SWRITE("Cancelled due to criterion 1: ");
        IWRITE(NGPolkr1);BLINES(0);
        SWRITE("Cancelled due to top-D-reducibility: ");
        IWRITE(NGPoltr);BLINES(0);
        SWRITE("Number of computed S-polynomials: ");
        IWRITE(ASPol);BLINES(0);
        SWRITE("Cancelled due to criterion 2: ");
        IWRITE(NSPolkr2);BLINES(0);
        SWRITE("Cancelled due to criterion 3: ");
        IWRITE(NSPolkr3);BLINES(1);
        SWRITE("Number of polynomials in G before reduction: ");
        IWRITE(LENGTH(G));
        BLINES(0);
    END;
    G:=DIIPELIMDGB(G);
    IF TF <> 0
    THEN
        SWRITE("Number of polynomials in G after reduction: ");
        IWRITE(LENGTH(G));
        BLINES(1);
    END;
      G:=DIIPREDDGB(G);
(*9*) RETURN(G); END DIIPEGB;


END DIPIDGB.



