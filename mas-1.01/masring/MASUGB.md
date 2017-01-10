(* ----------------------------------------------------------------------------
 * $Id: MASUGB.md,v 1.2 1995/11/05 09:11:59 kredel Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1993 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASUGB.md,v $
 * Revision 1.2  1995/11/05 09:11:59  kredel
 * Improved error handling and cosmetic.
 *
 * Revision 1.1  1993/05/11  10:11:15  kredel
 * Initial Revision
 *
 * ----------------------------------------------------------------------------
 *)

DEFINITION MODULE MASUGB;

(* Universal Groebner Bases Definition Module. *)


(* Author: Belkahia, Uni Passau, 1992. *)


FROM MASSTOR IMPORT LIST; 


CONST rcsid = "$Id: MASUGB.md,v 1.2 1995/11/05 09:11:59 kredel Exp $";
CONST copyright = "Copyright (c) 1989 - 1993 Universitaet Passau";


PROCEDURE UGBBIN(); 
(*UGB input, execute and output. 
Diese hauptprozedur liest die eingabedatei ein (die
polynome, die variablen und ihre anzahl durch pread, den
parameter durch rdpar und die option durch execrd). Die
funktion exeugb wird anschliessend aufgerufen.
UGBBIN wird vom hauptprogramm main aufgerufen. *)


PROCEDURE EXEUGB(L,I,V,PAR,OPT: LIST); 
(*UGB execute. 
Diese prozedur ruft, abhaengig von der option opt  die 
prozeduren lf, plf, ugb und pugb. Diese prozeduren 
realisieren die verschiedenen optionen, die im abschnitt 
benutzerschnittstelle besprochen wurden.
Die prozedur wird von der hauptprozedur ugbbin aufgerufen. *)


PROCEDURE LF(L,I,V,PAR,OPT: LIST);  
(*UGB linear form. 
Die prozedur berechnet die linearformen nach der option
LF. Vergleiche benutzerschnittstelle und 5.1.6. 
Die prozedur wird von exeugb aufgerufen. *)


PROCEDURE PLF(L,I,V,PAR,OPT: LIST); 
(*UGB linear form with precomputed linear forms. 
Die prozedur berechnet die linearformen nach der option
plf. Vergleiche benutzerschnittstelle und 5.1.7.
Die prozedur wird von exeugb aufgerufen. *)


PROCEDURE UGB(L,I,V,PAR,OPT: LIST); 
(*Universal Groebner base. 
Die prozedur berechnet eine universelle groebner basis 
nach der option ugb. Vergleiche benutzerschnittstelle
und 5.2.4.
Die prozedur wird von exeugb aufgerufen. *)


PROCEDURE PUGB(L,I,V,PAR,OPT: LIST); 
(*Universal Groebner base with precomputed linear forms. 
Die prozedur berechnet eine universelle groebner basis 
nach der option pugb. Vergleiche benutzerschnittstelle 
und 5.2.5.
Die prozedur wird von exeugb aufgerufen. *)


PROCEDURE SUNIT1(I: LIST); 
(*UGB set input unit 1. 
Diese prozedur stellt bei der option plf die richtige
datei zum einlesen von linearformen bereit. I ist
die anzahl der variablen. Die vorberechneten lineraformen
sind je nach der anzahl der variablen in verschiedenen 
dateien gespeichert. Diese prozedur wird von der prozedur
plf aufgerufen. *)


PROCEDURE SUNIT2(I: LIST); 
(*UGB set input unit 2.
Diese prozedur stellt bei der option pugb die richtige 
datei zum einlesen von linearformen bereit. I ist
die anzahl der variablen. Die vorberechneten lineraformen
sind je nach der anzahl der variablen in verschiedenen 
dateien gespeichert. Diese prozedur wird von der prozedur
pugb aufgerufen. *)


PROCEDURE PREAD( VAR L,I,V: LIST);  
(*UGB polynomial read. 
Die polynome werden von der eingabedatei eingelesen.
Diese funktion wird von der hauptprozedur ugbbin
aufgerufen. *)


PROCEDURE OPREAD( VAR PAR,OPT: LIST);  
(*UGB options and parameter read. 
Diese prozedur liest von der eingabedatei den parameter
par (zustaendig fuer zwischenausgaben) durch die prozedur
rdpar und die option opt (steht fuer lf, plf, ugb, pugb) 
durch die prozedur execrd.
Diese prozedur wird von der hauptprozedur ugbbin
aufgerufen. *)


PROCEDURE EXPTU(L: LIST): LIST; 
(*UGB extract exponent vector list from polynomial list. 
Aus den polynomen wird die liste der terme berechnet.
Da jeder term mit dem tupel seiner exponenten 
identifizert werden kann, wird die liste der
exponententupel ausgegeben. 
Diese funktion wird von den prozeduren mklist, newdif, 
isneu, ug, pug, lf, plf, ugb und pugb. *)


PROCEDURE MAKERN(Q: LIST): LIST;  
(*UGB rational exponent vector list from integer ev list. 
Makern transformiert die ganzzahlige struktur der 
exponententupel in eine rationalzahlige struktur
diese funktion wird von den funktionen mklist, neulf
und newdif aufgerufen. *)


PROCEDURE SCMULT(I,U: LIST): LIST; 
(*UGB rational exponent vector rational number product. 
Hilfsfunktion zur berechnung vom skalarprodukt zwischen 
rationalzahligen vektoren. 
Diese funktion wird von der funktion mkset aufgerufen. *)


PROCEDURE PDIF(R,S,DIFALT: LIST): LIST; 
(*UGB rational exponent vector list difference list, incremental. 
Berechnet (r-s) vereinigt mit (s-s).Diese prozedur ist
im hinblick auf die berechnung von universellen groebner
basen geschrieben. S entspricht der menge der neuen terme, 
die nach der reduktion entstehen. R enspricht der alten 
menge von termen. Da r-r in einem vorherigen schritt
schon berechnet wurde, berechnet die prozedur nur r-r 
vereinigt mit s-s.
Diese funktion wird von den funktionen projec, proj und 
newdif aufgerufen. *)


PROCEDURE MKSET(R: LIST;  VAR P2,P3,RR: LIST); 
(*UGB rational exponent vector list difference list. 
Berechnet die mengen p1, p2, p3 und die reduzierte menge
von p - p wie sie im theoretischen teil der diplomarbeit
beschrieben ist. Die eingabe ist r. P1 und p2 sind die
projektionen. P3 ist die vereinigung von p1 und p2.
Rr entspricht der reduzierten menge von p - p. 
Nur p2, p3 und rr werden zurueckgegeben. 
Diese funktion wird von den funktionen projec und proj
aufgerufen. *)


PROCEDURE PROJEC(R,S,DIFALT,OLDL,I,PAR: LIST): LIST; 
(*UGB projection to dimension 1. 
Berechnet die projektionen der eingabemenge r bis zur
dimension 1. Die ausgabe ist ein stapel der tupel der
form (p2,p) verschiedener dimensionen enthaelt.
P2 wird in jeder dimension zur berechnung der schnitte 
und p zum vergleich von ordnungen benutzt.
Diese prozedur ruft die prozeduren pdif und mkset auf. 
Die prozedur degre bestimmt fuer jede projektion den 
maximalen totalgrad der terme. 
Diese funktion wird von den funktionen lf, plf, ugb und
newdif aufgerufen. *)


PROCEDURE PROJ(R,S,DIFALT,OLDL,I: LIST;  VAR D,B,DEG: LIST); 
(*UGB projection, one dimension. 
Berechnet die projektion der eingabemenge r auf eine 
niedrigere dimension. Die ausgabe besteht aus b
(entspricht p2 in definition 2.2.1), d (entspricht der 
reduzierten differenz r - r), sowie deg.
Diese prozedur ruft die prozeduren pdif und mkset auf. 
Die prozedur degre bestimmt den maximalen totalgrad deg
der terme der projektion. 
Diese funktion wird von der funktion plf aufgerufen. *)


PROCEDURE DIFF(R: LIST): LIST; 
(*UGB difference set for rational exponent vector list. 
Diese prozedur berechnet fuer die eingabemenge von
tupel r die reduzierte menge r - r. das ergebnis wird 
in r zurueckgegeben.
diese funktion wird von den funktionen mklist und pdif
aufgerufen. *)


PROCEDURE DIFF1(R,S: LIST): LIST; 
(*UGB difference set for two rational exponent vector list. 
Berechnet fuer die eingabemengen r und s von exponeneten
tupel die reduzierte menge r - s. das ergebnis wird in
erg zurueckgegeben. 
diese funktion wird von der funktion pdif aufgerufen. *)


PROCEDURE RNVDIF(A,B: LIST): LIST; 
(*UGB rational exponent vector difference. 
Berechnet die komponentenweise differenz von zwei
rationalzahligen vektoren. die differenz von zwei
rationalzahlen wird durch die prozedur rndif berechnet.
diese funktion wird von den funktionen diff und diff1
aufgerufen. *)


PROCEDURE SCPROD(A,B: LIST): LIST; 
(*UGB rational exponent vector scalar product. 
Berechnet das skalarprodukt von zwei rationalzahligen
vektoren. die prozedur rnprod berechnet das produkt
zweier rationalzahlen. die prozedur rnsum berechnet die
summe von zwei rationalzahlen. das ergebnis wird in c
zurueckgegeben.
diese funktion wird von den funktionen cq2, cp2, pkegel
und cspur aufgerufen. *)


PROCEDURE SKPRO2(A,B: LIST): LIST; 
(*UGB rational exponent vector scalar product with integer ev. 
Diese funktion ist eine spezielle skalarprodukt-funktion.
da die ausgerechneten linearformen rationahlzahlig sind
und die exponententupel ganzzahlig sind, werden diese
zunaechst als rationahlzahlen dargestellt und dann das 
skalarprodukt gebildet. 
diese funktion wird von evlfcp aufgerufen. *) 


PROCEDURE LRNBMS(L: LIST): LIST;
(*List of rational numbers bubble-merge sort.  L is an arbitrary list of
rational numbers, possibly with repetitions.  M is the result of sorting
L into non-decreasing order.  A combination of bubble-sort and merge-
sort is used.  The list L is modified to produce M.*)


PROCEDURE LRNBS(L: LIST);
(*List of rational numbers bubble sort.  L is an arbitrary list of
rational numbers, with possible repetitions.  L is sorted into
non-decreasing order by the bubble-sort method.  The list L, though not
its location, is modified.*)


PROCEDURE LRNM(L1,L2: LIST): LIST;
(*List of rational numbers merge.  L1 and L2 are arbitrary lists of
rational numbers in non-decreasing order.  L is the merge of L1 and L2.
L1 and L2 are modified to produce L.*)


PROCEDURE COMPLF(C,D,KLIST,NP,JP,M: LIST; VAR LFORM,KLISTP,J: LIST); 
(*UGB compute linear form from difference set. 
Diese prozedur berechnet fuer die linearform c und die
menge der schnitte d die neuen linearformen. klist
enthaelt die spuren der schon berechneten linearformen
np entspricht der reduzierten menge  p - p und wird
dazu verwendet um die neuen spuren zu berechnen.
lform enthaelt als ausgabe alle bisher berechneten
linearformen. klistp die dazugehoerigen spuren. alle
spuren sind verschieden.
die funktion wird von der funktion mklf1 aufgerufen. *)


PROCEDURE CQ2(C,Q2,M: LIST): LIST; 
(*UGB linear form product with rational exponent vector list. 
Diese prozedur berechnet fuer eine linearform c und eine 
liste q2, beide der gleichen dimension, das produkt c * q2. 
die elemente von c * q2 bestehen aus dem skalarprodukt von
c mit den einzelnen elementen von q2. da diese menge dazu
verwendet wird, um die schnitte zu bilden, werden nur die
negativen elemente gespeichert.
die funktion wird von der funktion mklf1 aufgerufen. *)


PROCEDURE RNVABS(A: LIST): LIST;  
(*Rational number list absolute values. 
Diese prozedur berechnet fuer die liste a von rational- 
zahlen den absolutbetrag ihrer komponenten. die prozedur
rnabs berechnet den absolutbetrag einer rationalzahl. 
das ergebnis wird in der liste b zurueckgegeben.
die funktion wird von den funktionen mklf1, mklf2 und 
mklf3 aufgerufen. *)


PROCEDURE CUT(TR: LIST): LIST; 
(*UGB set of cuts. 
Berechnet fuer die eingabemenge tr die menge der 
schnitte d. fuer die inneren punkte wird das
algebraische mittel gebildet. fuer die aeusseren punkte
wird 1 addiert beziehungsweise die zahl halbiert.
die funktion wird von den funktionen mklf1, mklf2 und
mklf3 aufgerufen. *)


PROCEDURE ALLELN(STAKK,L,KALT,I,PAR: LIST;  VAR LF,NURLF: LIST); 
(*UGB all linear forms from stack of projections. 
Diese funktion berechnet aus dem stapel der projektionen
stakk alle linearformen nurlf. die prozedur mklf1 wird 
aufgerufen.
diese funktion wird von der prozedur lf aufgerufen. *)


PROCEDURE MKLF1(LFP,Q2,NP,M: LIST): LIST;  
(*UGB make new linear forms 1. 
Diese prozedur berechnet fuer eine liste von linearformen
lfp die neuen linearformen newlf. die menge q2 wird dazu 
verwendet, die schnitte zu berechnen. die menge np 
dient dazu, die ueberfluessigen linearformen zu eliminieren.
diese funktion wird von der prozedur plf und alleln
aufgerufen. *)


PROCEDURE NULRNV(A: LIST): LIST;  
(*Rational number vector null test.  
Diese prozedur ueberprueft ob ein vektor a der nullvektor
ist. i ist 1 falls a der nullvektor ist ansonsten 0.
diese funktion wird von der funktion mkset aufgerufen. *)


PROCEDURE PKEGEL(C,N,KALT: LIST): LIST; 
(*UGB trace for linear form. 
Diese funktion berechnet die spur k bezueglich der linear-
form c und der menge n in kodierter form. die spur wird
nach der methode der wortkodierung (abschnitt 5.1.4)
gebildet. 
diese funktion wird von der funktion complf aufgerufen. *)


PROCEDURE COMPA1(K,KLIST: LIST): LIST;  
(*UGB trace member in trace list. 
Diese funktion stellt fest ob eine spur k in einer liste von
spuren vorhanden ist. j ist gleich 1 falls k in klist liegt,
ansonsten 0.
diese funktion wird von den funktionen complf, clf2, clf3
aufgerufen. *)


PROCEDURE COMPA2(K,A: LIST): LIST; 
(*UGB trace compare. 
Diese funktion ueberprueft zwei spuren k und a auf 
gleichheit. u ist gleich 1 falls a und k gleich sind,
ansonsten 0.
diese funktion wird von den funktionen compa1, dfp, dipmc2, 
zulfo und isneu aufgerufen. *)


PROCEDURE LASTEL(Y: LIST): LIST;  
(*Last element. 
X ist das letzte element der liste y. *)


PROCEDURE EVLRNBSO(A: LIST); 
(*Rational exponent vector list bubble sort. a is a list of
rational exponent vectors, a is sorted 
with respect to the termordering defined in EVORD 
by the bubble-sort method, two exponent vectors with equal
exponents will lead to an error. the
list a but not its location, is modified.*) 


PROCEDURE EVRNGL(U,V: LIST): LIST; 
(*Rational exponent vector inverse graded lexicographical compare.
u=(ul1, ..., ulrl), v=(vl1, ..., vlrl) are rational exponent vectors.
tl=0 if u eq v. tl=1 if u gt v. tl=-1 if u lt v. eq, gt, lt
with respect to the inverse graded lexicographical ordering
of the exponent vectors. rl is the length of u and v.*)


PROCEDURE EVRNC(U,V: LIST): LIST; 
(*Rational exponent vector compare. u=(ul1, ...,ulrl), v=(vl1, ...,vlrl)
are exponent vectors. rl is the length of u and v.
tl=0 if u eq v. tl=1 if u gt v. tl=-1 if u lt v. eq, gt, lt
with respect to the ordering of the exponent vectors specified
in the global variable EVORD. lexicographical, inverse
lexicographical, graded lexicograhpical, inverse graded
lexicographical orderings are possible. *)


PROCEDURE DEGRE(Q: LIST): LIST; 
(*UGB total degree of a list of rational exponent vectors. 
Q ist eine liste von rationalzahligen tupeln. der maximale
totalgrad der in q vorkommt wird berechnet.
diese prozedur wird von den funktionen projec und proj 
aufgerufen. *)


PROCEDURE RDPAR(): LIST; 
(*UGB read parameter. 
Diese funktion liest aus der eingabedatei den parameter
par. zulaessige werte sind y oder n. bei y werden zwischen
berechnungen ausgegeben, bei n nicht.
diese funktion wird von der prozedur opread aufgerufen. *)


PROCEDURE EXECRD(): LIST;  
(*UGB execution options read. 
Diese funktion liest aus der eingabedatei die 
auszufuehrende option. moegliche optionen sind lf  plf  ugb 
und pugb. vor der option muss das wort exec stehen. die
option ist mit einem punkt abzuschliessen.
beispiel  exec ugb.
diese funktion wurde mit geringfuegigen aenderungen aus
der aldes-bibliothek entnommen.
diese funktion wird von der hauptprozedur ugbbin aufgerufen. *)


PROCEDURE SEENR(AC: LIST;  VAR NR: LIST);  
(*UGB number of option. 
Diese funktion ermittelt fuer eine option ac eine
schluesselzahl nr. die funktion stammt bis auf einige
aenderungen aus der aldes-bibliothek.
diese funktion wird von der funktion execrd aufgerufen. *)


PROCEDURE LFGET(DEG,LF: LIST): LIST;  
(*UGB get linear form from list of linear forms. 
Diese funktion holt aus der liste lf der gespeicherten 
linearformen, abhaengig vom grad deg, die benoetigten
linearformen.
diese funktion wird von den funktionen plf, pugb und pug 
aufgerufen. *)


PROCEDURE MKLF2(LFP,Q2,NP,M,L: LIST;  VAR NEWLF,LISTLF: LIST); 
(*UGB make new linear forms 2. 
Diese funktion ist genau analog zu mklf1. die linear-
formen werden im gegensatz zu onenlf auch mit der zahl 1 
als letzte komponente der linearformen berechnet.
diese funktion wird von der funktion lfall aufgerufen. *)


PROCEDURE CLF2(C,D,KLIST,NP,JP,M,L: LIST; VAR LFORM,KLISTP,J,RECLF: LIST);  
(*UGB compute linear form from difference set 2.
Diese funktion funktionniert genauso wie complf, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von der funktion mklf2 aufgerufen. *)


PROCEDURE CP2(C,Q2: LIST): LIST;  
(*UGB linear form product with rational exponent vector list 2. 
Diese funktion funktionniert genauso wie cq2, mit dem
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von den funktionen mklf2 und mklf3 
aufgerufen. *)


PROCEDURE CSPUR(C,N,KALT: LIST): LIST;  
(*UGB trace for linear form 2. 
Diese funktion funktionniert genauso wie pkegel, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von den funktionen clf2, clf3 und zulfo 
aufgerufen. *)


PROCEDURE MKNEWP(P,POL,PRS: LIST): LIST; 
(*UGB make new critical pairs. 
Diese funktion aktualisiert die menge der paare prs der
polynomliste p um die paare der form (pol,f) wobei f aus 
p und pol ein polynom ist. das ergebnis ist ppairs.
das buchberger-kriterium ist implementiert.
diese funktion wird von der funktion gs2 aufgerufen. *)


PROCEDURE MKPAIR(PP: LIST;  VAR PAIRS: LIST);  
(*UGB make critical pairs for polynomial list. 
Diese funktion berechnet aus der liste pp von polynomen 
die menge der paare pairs. das buchberger-kriterium ist
implementiert. 
diese funktion wird von der funktion gs1 aufgerufen. *) 


PROCEDURE MKSP1(X,L,PAIRS,I,V: LIST;  VAR D,PAIRSP: LIST); 
(*UGB compute next non-zero reduced S-polynomial.  
Diese funktion bildet bezueglich der linearform x und der
polynommenge l aus der liste von paaren pairs solange
ein s-polynom (dirpsp) und fuehrt es zu normalform (dirrnf) 
bis das s-polynom d nicht null ist oder die liste der paare 
pairsp leer ist.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE GS1(LF,V,PAR: LIST): LIST;  
(*UGB generate stack of sorted polynomials and critical pairs 1. 
Lf ist ein tupel der form (a,l,k,n). dabei ist a eine linear-
form, l eine liste von polynomen, k die dazugehoerige
spur und n die reduzierte differenz p - p der 
entsprechenden menge von exponententupel. 
diese prozedur ordnet die polynome nach den linearformen 
und berechnet die menge der dazugehoerigen paare b.
die ausgabe stak besteht aus tupeln der form (a,l,k,n,b).
diese funktion wird von den funktionen ug und pug
aufgerufen. *) 


PROCEDURE MERGE(STALT,STNEU: LIST): LIST;  
(*UGB merge stacks. 
Diese funktion mischt die zwei stapel stalt und stneu zu 
einem stapel stak wie in 5.2.3 beschrieben ist. 
diese funktion wird von der funktion neulf aufgerufen. *)


PROCEDURE WRUGF(X,V,PAR: LIST): LIST; 
(*Write universal Groebner family. 
Diese funktion gibt eine berechnete universelle 
groebnerfamilie  auf dem ausgabegeraet aus. es wird
jeweils eine linearform und die dazugehoerige polynommenge
ausgegeben. 
diese funktion wird von den prozeduren ugb und pugb
aufgerufen. *)


PROCEDURE WRUGB(UL,V: LIST);  
(*Write universal Groebner base. 
Diese funktion gibt eine berechnete universelle 
groebnerbasis ul auf dem ausgabegeraet aus.
diese prozedur wird von den prozeduren ugb und pugb
aufgerufen. *)


PROCEDURE POLCOP(L: LIST): LIST;  
(*Two level list copy. 
Diese funktion macht eine kopie p der polynomliste l.
diese funktion wird von den funktionen gs1, gs2 und wrugf
aufgerufen. *)


PROCEDURE DFP(A,B: LIST): LIST; 
(*UGB distributive rational polynomial difference. 
Diese funktion bildet aus den beiden polynomen a und b 
die distributive differenz a - b. das ergebnis ist cp. 
diese funktion unterscheidet sich von der in der aldes 
bibliothek vorhandenen funktion. sie berechnet die 
differenz bezueglich der in der globalen variablen 
EVORD gesetzten ordnung.
diese funktion wird von den funktionen dirrnf und dirpsp 
aufgerufen. *)


PROCEDURE SFP(A,B: LIST): LIST; 
(*UGB distributive rational polynomial sum. 
Diese funktion bildet aus den beiden polynomen a und b 
die distributive summe a + b. das ergebnis ist cp. 
diese funktion unterscheidet sich von der in der aldes 
bibliothek vorhandenen funktion. sie berechnet die 
differenz bezueglich der in der globalen variablen 
EVORD gesetzten ordnung.
diese funktion wird von den funktionen dirrnf aufgerufen. *)


PROCEDURE EVLFCP(L,U,V: LIST): LIST;  
(*UGB exponent vector linear form compare. 
Diese funktion vergleicht die exponententupel u und v
zweier terme bezueglich der linearform l. das ergebnis 
t ist gleich 1 falls u groesser als v ist, 0 falls sie 
gleich sind  und -1 ansonsten.
diese funktion wird von der funktion evcomp aufgerufen. *)


PROCEDURE PCOMP(X,Y: LIST): LIST; 
(*UGB distributive polynomial composition. 
Diese funktion bildet aus den beiden polynomen x und y 
ein polynom z, sodass das polynom x der ersten teil, und 
y der zweite teil ist.
diese funktion wird von den funktionen dfp und dipmc2
aufgerufen. *)


PROCEDURE EVCOMP(U,V: LIST): LIST; 
(*UGB exponent vector compare. 
Diese funktion vergleicht die exponententupel u und v
zweier terme bezueglich der termordnung, die in der
globalen variable EVORD gespeichert ist. das ergebnis
tl ist gleich 1 falls u groesser als v ist, 0 falls sie
gleich sind  und -1 ansonsten. *)


PROCEDURE DIPMC2(A,C,P: LIST): LIST;  
(*UGB distributive polynomial composition 2. 
Diese funktion bildet aus dem koeffizient a, dem term c
und dem polynom p ein neues polynom dp.
diese funktion wird von der funktione dirrnf aufgerufen. *)


PROCEDURE DIRRNF(P,S,X,V: LIST): LIST;  
(*UGB distributive polynomial normalform. 
Diese funktion berechnet die normalform r eines polynoms 
s mit rationalen koeffizienten bezueglich der liste von
polynomen p und der ordnung, die von der linearform x
induziert wird.
diese funktion wird von der funktione mksp1 aufgerufen. *) 


PROCEDURE DIRPSP(A,B,X: LIST): LIST;  
(*UGB distributive polynomial S-polynomial. 
Diese funktion berechnet das s-polynom c der polynome a
und b bezueglich der ordnung, die von der linearform x 
induziert wird.
diese funktion wird von der funktion mksp1 aufgerufen. *) 


PROCEDURE UG(LF,I,V,STAP,P,NURLF,PAR: LIST): LIST;  
(*Universal Groebner base. 
Diese funktion berechnet eine universelle groebner-
familie ugf. lf sind tupel der form (a,l,k,n), wobei l 
die eingabemenge von polynomen, a eine von allen
dazugehoerigen linearformen, k die spur und n die
reduzierte differenz der eingabemenge der exponententupel
ist. die berechnung realisiert die option ugb.
diese funktion wird von der funktion ugb aufgerufen. *)


PROCEDURE PUG(LF,I,V,P,DEGP,NURLF,PAR,LFQ: LIST): LIST; 
(*Universal Groebner base using precomputation.
Diese funktion berechnet eine universelle groebner-
familie ugf. lf sind tupel der form (a,l,k,n), wobei l 
die eingabemenge von polynomen, a eine von allen
dazugehoerigen linearformen, k die spur und n die
reduzierte differenz der eingabemenge der exponententupel
ist.
die berechnung realisiert die option pugb.
diese funktion wird von der funktion pugb aufgerufen. *)


PROCEDURE NEWL(LFTEMP,LFNEU,LFEND: LIST): LIST;  
(*UGB update linear forms from new terms. 
Lfneu ist die menge der linearformen auf der neuen menge 
von termen. die funktion stellt fest welche von diesen 
linearformen die alten fortsetzen und aktualisiert 
das zwischenergebnis lftemp durch lfp. 
die funktion wird auch nur aufgerufen wenn neue 
linearformen enstanden sind.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE ZULFO(LFNEU,X,LL,LFEND: LIST;  VAR LFP,LF: LIST);  
(*UGB find admissible extensions of linear forms. 
Diese funktion stellt fest, welche linearformen aus lfneu
die linearform von x fortsetzen. diese linearformen mit
den aktualisierten daten (spur, paare) ersetzen dann x 
in ll. das ergebnis ist lfp.
diese funktion wird von der funktion newl aufgerufen. *)


PROCEDURE NONEWL(LFTEMP: LIST): LIST; 
(*UGB update linear forms without new terms. 
Diese funktion wird aufgerufen wenn keine linearformen 
entstanden sind. sie aktualisiert lftemp durch lfp.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE ISNEUL(LFALT,LFNEU,PAR: LIST): LIST; 
(*UGB new linear form test.
Lfalt ist die alte liste von linearformen, lfneu die
neue. diese funktion stellt fest ob neue linearformen
entstanden sind (u gleich 1) oder nicht (u gleich 0).
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE NEULF(STAP,DSUM,LSUM,I,V,PAR: LIST; VAR LFNEU,NEUST: LIST); 
(*UGB compute new linear forms from new terms. 
Diese funktion berechnet, nachdem neue terme entstanden
sind, die neuen linearformen. die berechnung basiert
auf die bereits beschriebenen funktionen und prozeduren
zur berechnung von linearformen. 
dsum ist die liste der neuen s-polynome, lsum die liste
der alten polynome, stap der alte stapel der projektionen.
das ergebnis ist die liste der neuen linearformen lfneu
und der neue stapel von projektionen neust.
diese funktion wird von der funktion ug aufgerufen. *)


PROCEDURE ISNEU(DSUM,LSUM,PAR: LIST;  VAR SEMA,DD: LIST); 
(*UGB new terms test. 
Diese funktion stellt fest, ob neue terme in dusm entstanden
sind. 
dsum ist die liste der neuen s-polynome in normalform, 
lsum die alte liste von polynomen. die ausgabe sema ist
gleich 1 falls neue terme entstanden sind. ansonsten 0.
dd ist die liste der neuen terme.
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE TCOMP(X,Y: LIST): LIST; 
(*UGB list constructive conc. ??CCONC??
X und y sind zwei listen. diese prozedur konkatiniert sie
zu einer liste z.
diese funktion wird von der funktion isneu aufgerufen. *)


PROCEDURE NEWDIF(L,D,DIFALT: LIST): LIST;  
(*UGB exponent vector list difference from polynomials. 
Diese funktion liest durch die funktion exptu die
exponententupel der terme von l und d und berechnet mit
hilfe der funktion pdif die differenz. fuer die 
berechnung der neuen differenz wird das schon berechnete 
ergebnis genutzt.
diese funktion wird von den funktionen zulfo und nonewl
aufgerufen. *) 


PROCEDURE GS2(LF,V,PAR: LIST): LIST;  
(*UGB generate stack of sorted polynomials and critical pairs 2.
Diese funktion funktioniert aehnlich zu gs1. sie ist wegen
der uebersichtlichkeit getrennt geschrieben. die funktion
aktualisiert die zwischenergebnisse lf (tupel der form 
(a,l,k,n,b) wie die ausgabe von gs1), d.h sie ordnet
die polynome neu und aktualisiert die mengen von paaren. 
diese funktion wird von den funktionen ug und pug
aufgerufen. *)


PROCEDURE ALLLF(STAKK,KALT,I: LIST): LIST; 
(*UGB all linear forms from stack of projections and print. 
Die funktion funktionniert genauso wie lfall. hier 
werden nur die linearformen berechnet und ausgegeben.
diese funktion wird von der funktion neulf aufgerufen. *)


PROCEDURE LFALL(STAKK,L,KALT,I: LIST; VAR LISTLF,NURLF: LIST); 
(*UGB all linear forms from stack of projections 1. 
Diese funktion funktionniert genauso wie alleln, mit dem 
unterschied, dass das element 1 als letzte komponente
der linearform gespeichert wird. 
diese funktion wird von der funktion ugb aufgerufen. *)


PROCEDURE MKLF3(LFP,Q2,NP,M: LIST): LIST;  
(*UGB make new linear forms 3.
Diese funktionniert genauso wie mklf2. hier werden nur 
die linearformen (newlf) berechnet und ausgegeben. 
diese funktion wird von der funktion alllf aufgerufen. *) 


PROCEDURE CLF3(C,D,KLIST,NP,JP,M: LIST;  VAR LFORM,KLISTP,J: LIST); 
(*UGB compute linear form from difference set 3.
Diese funktionniert genauso wie clf2. hier werden nur
die linearformen (lform) berechnet und ausgegeben. 
diese funktion wird von der funktion mklf3 aufgerufen. *) 


PROCEDURE DO1(LFP: LIST): LIST; 
(*UGB add last component to exponent vector. 
Um speicherplatz zu sparen wurden die linearformen ohne
das 1 element als letzte komponente gespeichert. diese 
funktion fuegt fuer die liste der linearformen lfp das 
element 1 ein. das ergebnis ist lf1. 
diese funktion wird von der funktion pugb aufgerufen. *)


PROCEDURE MKLIST(LF,L: LIST;  VAR LFLIST,NURLF: LIST);  
(*UGB make trace and cuts. 
Diese funktion wird aufgerufen bei der option pugb. die
liste der eingelesenen linearformen lf ist groesser als
noetig. diese funktion reduziert diese linearformen,
sodass bezueglich der menge p von polynomen verschiedene 
ordnungen ergeben. nurlf ist dann das ergebnis. listlf 
besteht aus tupel der form (a,l,k,n) wie das ergebnis von
lfall.
diese funktion wird von der funktion pugb aufgerufen. *)


PROCEDURE LDEG(L: LIST): LIST; 
(*Distributive polynomial list total degree. 
Diese funktion bestimmt fuer eine liste von polynomen l
den maximalen totalgrad, der darin auftaucht. 
diese funktion wird von den funktionen pug und pugb
aufgerufen. *)


END MASUGB.

