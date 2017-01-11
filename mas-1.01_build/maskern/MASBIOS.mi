(* ----------------------------------------------------------------------------
 * $Id: MASBIOS.mi,v 1.13 1996/06/08 18:26:51 pesch Exp $
 * ----------------------------------------------------------------------------
 * This file is part of MAS.
 * ----------------------------------------------------------------------------
 * Copyright (c) 1989 - 1995 Universitaet Passau
 * ----------------------------------------------------------------------------
 * $Log: MASBIOS.mi,v $
 * Revision 1.13  1996/06/08 18:26:51  pesch
 * Removed unused code, minor corrections.
 *
 * Revision 1.12  1996/06/08 14:18:54  kredel
 * Changed Stream x closed successfully.
 *
 * Revision 1.11  1995/11/04  20:39:58  pesch
 * Renamed massignal.m? to massig.m? because of conflict with MASSIGNAL.m?
 * on certain OS.
 *
 * Revision 1.10  1995/10/13 16:02:04  pesch
 * Fixed error: sigsetmask() at wrong places caused SIGUSR1 to be blocked
 *              permanently.
 *
 * Revision 1.9  1995/09/12  17:22:48  pesch
 * Signal handling function are now declared in massignal.
 * Action has been changed according to ANSI C.
 * signal.* and massignal.* have been removed, the former because of
 * name clash with signal.h.
 *
 * Revision 1.8  1995/03/23  15:52:56  pesch
 * Improved error handling for ReadOpen and WriteOpen.
 * Reformatted import lists.
 *
 * Revision 1.7  1995/03/06  16:00:50  pesch
 * Added kpathsea and GNU readline support.
 * Added new procedures IStreamKind, OStreamKind, EStreamKind.
 *
 * Revision 1.6  1994/07/20  18:15:17  pesch
 * Made most functions atomic wrt. SIGUSR1, since they are not reentrant.
 *
 * Revision 1.5  1993/05/11  10:45:35  kredel
 * Uninitialized variable in input
 *
 * Revision 1.4  1992/10/16  13:47:49  kredel
 * Errors found by Mocka
 *
 * Revision 1.3  1992/10/15  16:24:53  kredel
 * Changed rcsid variable
 *
 * Revision 1.2  1992/02/12  17:31:49  pesch
 * Moved CONST definition to the right place
 *
 * Revision 1.1  1992/01/22  15:10:28  kredel
 * Initial revision
 *
 * ----------------------------------------------------------------------------
 *)
  
IMPLEMENTATION MODULE MASBIOS; 

(* MAS Basic I/O System Implementation Module. *)

 
(* Import lists and Definitions *) 
 
FROM MASELEM	IMPORT	GAMMAINT, MASMIN, MASSIGN; 
 
FROM MASSTOR	IMPORT	ADV, CELLS, CLOCK, COMP, DEQUE, EMPTYQUE, ENQUE,
			FIRST, GCC, GCCC, INV, LIST, LISTVAR, NEWQUE, NU,
			RED, SIL, TAU, TAU0, TIME;

FROM MASERR	IMPORT	ERROR, fatal, harmless, severe, spotless;

FROM IO		IMPORT	CloseIO, EndOfFile, EndOfLine, ReadC, ReadClose, ReadI,
			ReadNl, ReadS, StdError, StdInput, StdOutput, WriteC,
			WriteClose, WriteFlush, WriteI, WriteN, WriteNl,
			WriteOpen, WriteS, tFile;

FROM Strings	IMPORT	ArrayToString, AssignEmpty, Char, IsEqual, Length,
			ReadL, SubString, WriteL, tString;

FROM Portab	IMPORT	bs, cr, del, esc, ff, lf, nul; 

FROM massig	IMPORT	SIGUSR1, SigMask, sigblock, signal, sigsetmask;

FROM maskpathsea	IMPORT	masReadOpen;

FROM masreadline	IMPORT	masReadL;


CONST   CCHI = 150;      (* > 102 *) 
        ILEN = 79; 
        OLEN = 79; 
        itlen = 255; 
        islen = 81;     (* > ILEN *) 
        MAXFILE = 29; 
        undefstat = 'U'; 
        instat = 'I';
        outstat = 'O'; 
        clostat = 'C'; 
        anystat = 'A'; 
TYPE 
        FileDescriptor = 
          RECORD 
                stat : CHAR;       (* Unused, Input, Output, Closed. *) 
                name : tString;  
                sysf : tFile;      (* system dependent file handle etc. *) 
                sysq : GAMMAINT;   (* ram queue handle *) 
                kind : INTEGER; 
                lmarg : INTEGER; 
                rmarg : INTEGER; 
                lpos : INTEGER; 
                llen : INTEGER; 
                ByteIO : GAMMAINT; 
                LineIO : GAMMAINT; 
          END; 
 
VAR     stream : ARRAY [1..MAXFILE] OF FileDescriptor; 
        Istream, Ostream, Estream : INTEGER; 
        Istack, Ostack : LIST; 
        ACODE, LCODE, SCODE : ARRAY [1..CCHI] OF INTEGER; 
        Sin : tString; (*ARRAY [1..islen] OF CHAR;*) 
        again, itrace : INTEGER; 
        Tbuff : ARRAY [1..itlen] OF GAMMAINT; 
        blank : GAMMAINT; 
        ISIZE, ILMARG, IRMARG, IPOS, OSIZE, OLMARG, ORMARG, OPOS : INTEGER; 
        IBYTEIO, ILINEIO, OBYTEIO, OLINEIO : GAMMAINT; 
        INEWLINE, ONEWLINE, ECHO : BOOLEAN; 
 
CONST rcsidi = "$Id: MASBIOS.mi,v 1.13 1996/06/08 18:26:51 pesch Exp $";
CONST copyrighti = "Copyright (c) 1989 - 1992 Universitaet Passau";

 

PROCEDURE BKSP(); 
(*Backspace.  Reread the last character from the input stream. *) 
VAR   i : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1 *)
(*1*) IF again < itlen THEN again := again+1; 
         itrace := itrace-1; 
         IF itrace < 1 THEN itrace := itrace+itlen; END; 
         END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END BKSP; 
 
 
PROCEDURE BLINES(N : GAMMAINT); 
(* Blank lines.  N is a positive integer.  N records of blanks each 
are output. *) 
VAR   i : GAMMAINT; 
      j : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1 *)
(*1*) OPOS := ORMARG; i := 1; 
      WHILE i <= N DO CWRITE(blank); 
            OPOS := ORMARG; i := i+1; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END BLINES; 
 
 
PROCEDURE CREAD(): GAMMAINT; 
(*Character read.  Returns next character from the input stream. *) 
VAR   C, D : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) IPOS := IPOS+1; C := input(); 
      IF IPOS>=IRMARG THEN IPOS := 0; 
         INEWLINE := TRUE; 
         ILINEIO := ILINEIO+1; 
         WHILE IPOS<ILMARG DO 
               IPOS := IPOS+1; D := input(); 
               END; 
         END; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN (C); 
(*9*) END CREAD; 
 
 
PROCEDURE CREADB(): GAMMAINT; 
(*Character read, skipping blanks. Returns next character from the 
input stream. *) 
VAR   C : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) REPEAT 
             C := CREAD(); 
             UNTIL C<>blank; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN (C); 
(*9*) END CREADB; 
 
 
PROCEDURE CWRITE(C : GAMMAINT); 
(*Character write. The character c is transmitted to the output 
stream. *) 
VAR   i : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) OPOS := OPOS+1; 
      IF OPOS >= ORMARG THEN 
         OPOS := 0; 
         ONEWLINE := TRUE; 
         OLINEIO := OLINEIO+1; 
         WHILE OPOS < OLMARG DO 
               OPOS := OPOS+1; 
               output(blank); 
               END; 
         END; 
      output(C); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END CWRITE; 
 
 
PROCEDURE DIBUFF(); 
(*Display input buffer.  The input buffer status is displayed.*) 
VAR   i, j : INTEGER; 
      L : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) BLINES(0); 
      SWRITE("Input buffer follows, last character read underscored."); 
      BLINES(0); 
      j := itrace+itlen-50; 
      IF j>itlen THEN j := j-itlen;  END; 
      FOR i := 1 TO 50 DO 
          j := j+1; 
          IF j>itlen THEN j := j-itlen; END; 
          L := Tbuff[j]; 
          CWRITE(L); 
          END; 
      BLINES(0); 
      FOR i := 2 TO 50-1 DO  CWRITE(blank); END; 
      SWRITE("-"); BLINES(1); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END DIBUFF; 
 
 
PROCEDURE DIGIT(C : GAMMAINT): BOOLEAN; 
(* Digit.  c is a character.  If c is a digit then TRUE is returned 
otherwise FALSE is returned. *) 
VAR   t : BOOLEAN; 
BEGIN 
(*1*) IF C <= 9 THEN t := TRUE; ELSE t := FALSE; END; 
      RETURN (t); 
(*9*) END DIGIT; 
 
 
PROCEDURE GREAD(): GAMMAINT; 
(* Gamma-integer read.  A gamma-integer is read from the input 
stream.  Any preceding blanks are skipped. *) 
VAR   a, C, S : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*Skip blanks and read sign, if any.*) 
      S := 1; 
      C := CREADB(); 
      IF C = MASORD('+') THEN C := CREADB(); 
         ELSE IF C = MASORD('-') THEN 
                 C := CREADB(); S := -1; 
                 END; 
         END; 
      IF NOT DIGIT(C) THEN 
         ERROR(harmless, "GREAD: digit expected."); 
         DIBUFF(); 
         m:=sigsetmask(m); (* restore old signal mask *)
         RETURN 0; 
         END; 
(*2*) (*read digits and convert.*) 
        a := 0; 
        REPEAT 
               a := 10*a+C; 
               C := CREAD(); 
                         (*teste ob a>10**delta*) 
               UNTIL NOT DIGIT(C); 
        BKSP(); a := S*a; 
	m:=sigsetmask(m); (* restore old signal mask *)
        RETURN (a); 
(*9*) END GREAD; 
 
 
PROCEDURE GWRITE(a : GAMMAINT); 
(* Gamma-integer write.  The gamma-integer a is written in the output 
stream.*) 
VAR   D : ARRAY [1..20] OF GAMMAINT; 
      ap, q : GAMMAINT; 
      N : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*5*) (*Write minus sign.*) 
      IF a < 0 THEN ap := -a; SWRITE("-"); 
               ELSE ap := a; END; 
(*2*) (*Convert to decimal.*) 
      N := 0; 
      REPEAT 
             q := ap DIV 10; 
             N := N+1; 
             IF N>20 THEN 
                     ERROR(harmless, "GWRITE: not a gamma-integer."); 
                     m:=sigsetmask(m); (* restore old signal mask *)
                     RETURN; 
                     END; 
             D[N] := ap-10*q; 
             ap := q; 
             UNTIL ap = 0; 
(*3*) (*Write digits.*) 
      REPEAT 
             CWRITE(D[N]); 
             N := N-1; 
             UNTIL N = 0; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*6*) END GWRITE; 
 
 
PROCEDURE Hold(); 
(* Hold. Pause programm if some key is pressed.*) 
VAR   C : CHAR; 
      m: INTEGER;
BEGIN   
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) C := CHAR(0); (*ReadC(StdInput);*) 
      IF ORD(C) > 0 THEN 
         IF C=esc THEN
            ERROR(severe, "ESC key pressed."); 
            END; 
         Pause(); 
         END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END Hold; 
 
 
PROCEDURE InitBIOS(); 
(*Initialize BIOS.  Initialize the basic input/output system.*) 
VAR   C, D, I, J : INTEGER; 
      S, T, R : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*Initialize file descriptors. *) 
      FOR I := 1 TO MAXFILE DO 
          stream[I].stat := undefstat; 
          AssignEmpty(stream[I].name); 
          stream[I].ByteIO := 0; 
          stream[I].LineIO := 0; 
          stream[I].lmarg := 0; 
          stream[I].rmarg := ILEN; 
          stream[I].llen := ILEN; 
          stream[I].lpos := 0; 
          LISTVAR(stream[I].sysq); 
          END; 
      Istream := 0; Ostream := 0; 
      again := 0; itrace := 1; 
      LISTVAR(Istack); LISTVAR(Ostack); 
(*2*) (*Set input globals.*) 
      ECHO := FALSE; Istack := SIL; 
      R := SIUNIT("CON:"); 
(*3*) (*Set output globals.*) 
      Ostack := SIL; 
      R := SOUNIT("CON:"); 
(*4*) (*Initialize code arrays.*) 
      INITCC(); 
      FOR I := 1 TO INTEGER(CHI) DO 
          SCODE[I] := LCODE[I]; 
          ACODE[I] := I-1; 
          END; 
      FOR J := INTEGER(CHI)-1 TO 1 BY -1 DO 
          FOR I := 1 TO J DO 
              C := SCODE[I]; 
              D := SCODE[I+1]; 
              S := MASSIGN(GAMMAINT(C)); 
              T := MASSIGN(GAMMAINT(D)); 
              IF (S>T) OR (S=T) AND (C>D) THEN 
                 SCODE[I] := D; SCODE[I+1] := C; C := ACODE[I]; 
                 ACODE[I] := ACODE[I+1]; 
                 ACODE[I+1] := C; 
                 END; 
              END; 
          END; 
      blank := MASORD(' ');     
      ringclear(); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*9*) END InitBIOS; 
 
  
PROCEDURE CloseBIOS(); 
(*Close BIOS.  Close all streams and write summary. *) 
VAR   I, k, j: INTEGER; 
      c : CHAR; 
      K : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*Close streams on stacks. *) 
        WHILE RED(Istack)<>SIL DO 
              I := INTEGER(FIRST(Istack)); 
              Istack := RED(Istack); 
              c := stream[I].stat; j:=-1; 
              IF c=instat THEN j:=CioUNIT(I,0) END; 
              IF c=outstat THEN j:=CioUNIT(0,I) END; 
              IF j = 0 THEN 
                 SWRITE("Stream "); StWRITE(stream[I].name); 
                 SWRITE(" closed successfully."); BLINES(1); END; 
              END; 
        WHILE RED(Ostack)<>SIL DO 
              I := INTEGER(FIRST(Ostack)); 
              Ostack := RED(Ostack); 
              c := stream[I].stat; j:=-1;
              IF c=instat THEN j:=CioUNIT(I,0) END; 
              IF c=outstat THEN j:=CioUNIT(0,I) END; 
              IF j = 0 THEN 
                 SWRITE("Stream "); StWRITE(stream[I].name); 
                 SWRITE(" closed successfully."); BLINES(1); END; 
              END; 
(*2*) (*Close remaining streams, exept terminal/stdIO. *) 
        FOR I := 1 TO MAXFILE DO 
            IF (I<>Istream) AND (I<>Ostream) THEN
               c := stream[I].stat; j:=-1; 
               IF c=instat THEN j:=CioUNIT(I,0) END; 
               IF c=outstat THEN j:=CioUNIT(0,I) END; 
               IF j = 0 THEN 
                  SWRITE("Stream "); StWRITE(stream[I].name); 
                  SWRITE(" closed successfully."); BLINES(1); END; 
               END; 
            END; 
      (* Summary(); *) 
      CloseIO;  
      m:=sigsetmask(m); (* restore old signal mask *)
(*4*) END CloseBIOS; 
 
 
PROCEDURE INITCC(); 
(*Initialize the ALDES character codes in LCODE.*) 
VAR      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) CHI := 0;       (*DIGITS*) 
      AddCode("0123456789");    (*LETTERS*) 
      AddCode("aAbBcCdDeEfFgGhHiIjJkKlLmMnNoOpPqQrRsStTuUvVwWxXyYzZ");
             (*SPECIAL*) 
      AddCode(".,=+-*/$() !"); 
      AddCode('"'); (*"*)
      AddCode("#%&':;<>?@[\]^_`{}|~"); (*' fool cpp*)
      CHI := CHI+1; 
      LCODE[INTEGER(CHI)] := 254;       (* copyright ??*) 
      CHI := CHI+1; 
      LCODE[INTEGER(CHI)] := INTEGER(ORD(esc)); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END INITCC; 
 
 
PROCEDURE AddCode(S : ARRAY OF CHAR); 
(* Add Code. The characters of S are added to the LCODE array, 
CHI is advanced. *) 
VAR   K : INTEGER; 
      I : CARDINAL; 
BEGIN 
(*1*) K := CHI; 
      FOR I := 0 TO HIGH(S) DO K := K+1; 
          LCODE[K] := INTEGER(ORD(S[I])); END; 
      CHI := GAMMAINT(K); 
(*3*) END AddCode; 
 
 
PROCEDURE LETTER(C : GAMMAINT): BOOLEAN; 
(* Letter.  c is a character.  If c is a letter then TRUE is returned 
otherwise FALSE is returned. *) 
VAR   t : BOOLEAN; 
BEGIN 
(*1*) IF (C>=MASORD('a')) AND (C<=MASORD('Z')) 
         THEN t := TRUE; 
         ELSE t := FALSE END; 
      RETURN (t); 
(*3*) END LETTER; 
 
 
PROCEDURE input(): GAMMAINT; 
(* Input. The charcter C is recieved from the input stream and converted 
to aldes code. *) 
VAR   i, retry : INTEGER; 
      c : CHAR; 
      C, j : GAMMAINT; 
      ok : BOOLEAN; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*read from internal buffer, if not empty. *) 
        IF again > 0 THEN again := again-1; 
                IPOS := IPOS-1; C := ringget(); 
                RETURN (C); END; 
        retry := MAXFILE; 
        (* avoid endless retrys *) 
        REPEAT  c:=" ";
                i := stream[Istream].kind; 
        CASE i OF 
             | ramkind : ok := NOT EMPTYQUE(stream[Istream].sysq); 
                         IF ok THEN 
                            C := DEQUE(stream[Istream].sysq); 
                            ringput(C); END; 
            | termkind : ok := TRUE; 
                         masReadL(Sin);  
                         ringstring(Sin); 
                         C := ringget(); 
                         IF stream[Ostream].kind=termkind THEN 
                            WriteNl(StdOutput); WriteFlush(StdOutput) END; 
            | diskkind : REPEAT 
                               ok := NOT EndOfFile(stream[Istream].sysf);
                               IF ok THEN c:=ReadC(stream[Istream].sysf);  
                                          END;
                          UNTIL ( c >= " " ) OR NOT ok; 
                          IF ok THEN 
                                C := MASORD(c); 
                                ELSE 
                                C := blank; 
                                END; 
                          ringput(C); 
             | winkind : ok := FALSE; 
             | nulkind : ok := FALSE; 
                  ELSE   ok := FALSE; 
                         END; 
        IF NOT ok THEN 
           (*DEBUG 
           ERROR(spotless,"End of stream: "); 
           ERROR(spotless,stream[Istream].name); 
             GUBED*) 
           j := CioUNIT(Istream,0); 
           retry := retry-1; 
           IF retry<0 THEN c := esc; ok := TRUE END; 
           ringclear(); 
           END; 
        UNTIL ok; 
      IF c=esc THEN (* emergency exit *) 
         ERROR(severe, "INPUT: ESC key pressed.") END; 
      IBYTEIO := IBYTEIO+1; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN (C); 
(*9*) END input; 
 
 
PROCEDURE LISTS(S : ARRAY OF CHAR): LIST;   
(*List from string. S is a character string with respect to local 
character code. A list if the corresponding ALDES character codes 
is returned.*) 
VAR   I, J : INTEGER; 
      II : GAMMAINT; 
      L : LIST; 
BEGIN 
(*1*) J := INTEGER(HIGH(S)); I := 0; L := SIL; 
      WHILE ( I <= J ) AND (S[I] <> nul) DO        
            II := MASORD( S[I] ); L := COMP(II,L); 
            I := I+1; END; 
      L := INV(L); RETURN (L); 
(*9*) END LISTS; 
 
 
PROCEDURE SLIST(A : LIST; VAR S : ARRAY OF CHAR); 
(*String from list. A is a list of ALDES character codes. 
S is a the corresponding character string with respect to local 
character codes. *) 
VAR   I : GAMMAINT; 
      AP : LIST; 
      i : INTEGER;     
BEGIN 
(*1*) AP := A; S[0] := nul; i := -1; 
      WHILE AP <> SIL DO ADV(AP, I, AP); 
            IF I < SIL THEN i:=i+1; S[i] := MASCHR(I) END; 
            END; 
      S[i+1]:=nul;
(*2*) END SLIST; 
 
 
PROCEDURE MASCHR(C : GAMMAINT): CHAR; 
(*MAS char.  Returns the local character for the aldes character c. *) 
VAR   i : INTEGER; 
      c : CHAR; 
BEGIN 
(*1*) IF (0<=C) AND (C<=CHI) 
         THEN i := INTEGER(C); 
         ELSE ERROR(spotless, "Non-standard character to convert. "); 
              GWRITE(C); SWRITE(" "); 
              i := INTEGER(blank); END; 
      c := CHR(LCODE[i+1]); RETURN (c); 
(*2*) END MASCHR; 
 
 
PROCEDURE MASORD(C : CHAR): GAMMAINT; 
(*MAS order.  Returns the aldes code for the character c. *) 
VAR   D : GAMMAINT; 
BEGIN 
(*1*) D := GAMMAINT(ORD(C)); D := MASORDI(D); 
      RETURN (D); 
(*2*) END MASORD; 
 
 
PROCEDURE MASORDI(C : GAMMAINT): GAMMAINT; 
(*MAS order integer.  Returns the aldes code for the integer c.*) 
VAR   CC, D, J, L, M, U, KK : INTEGER; 
      K : GAMMAINT; 
BEGIN 
(*1*) CC := INTEGER(C); L := 1; U := INTEGER(CHI); 
      REPEAT 
             J := L+U; 
             M := J DIV 2; 
             D := SCODE[M]; 
             IF (CC<0) AND ((D>=0) OR (CC<=D)) OR (D>0) AND (CC<=D) 
                THEN U := M; 
                ELSE L := M+1; END; 
             UNTIL L=U; 
       IF CC = SCODE[L] 
          THEN KK := ACODE[L]; 
          ELSE ERROR(spotless, "Non-standard character to convert. "); 
               GWRITE(C); SWRITE(" "); 
               KK := INTEGER(blank); END; 
      K := GAMMAINT(KK); RETURN (K); 
(*9*) END MASORDI; 
 
 
PROCEDURE output(C : GAMMAINT); 
(* Output. The charcter C is converted to local code and transmitted 
to the output stream. *) 
VAR   i, retry : INTEGER; 
      c : CHAR; 
      ok : BOOLEAN; 
      j : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) retry := MAXFILE;      (* avoid endless retrys *) 
        REPEAT 
                i := stream[Ostream].kind; 
                CASE i OF 
                        | ramkind : 
                                ENQUE(C, stream[Ostream].sysq); 
                                ok := (NOT EMPTYQUE(stream[Ostream].sysq)); 
                        | termkind : 
                                IF ONEWLINE THEN 
                                   ONEWLINE := FALSE; 
                                   WriteNl(StdOutput); 
                                   WriteFlush(StdOutput);
                                   (* Hold(); *) 
                                END; 
                                c := MASCHR(C); 
                                WriteC(StdOutput,c); 
                                WriteFlush(StdOutput);
                                ok := TRUE; 
                        | diskkind : 
                                IF ONEWLINE THEN 
                                        ONEWLINE := FALSE; 
                                        WriteNl(stream[Ostream].sysf); 
                                END; 
                                c := MASCHR(C); 
                                WriteC(stream[Ostream].sysf, c);   
                                ok := TRUE;
                        | winkind : 
                                ok := TRUE; 
                        | nulkind : 
                                ok := TRUE; 
                        ELSE 
                                ok := FALSE; 
                END; 
                IF NOT ok THEN (*one cannot debug this case*) 
                        j := CioUNIT(0,Ostream); 
                        retry := retry-1; 
                        IF retry < 0 THEN 
                           ERROR(fatal, "No output possible."); 
                           END; (* no more output possible *) 
                END; 
        UNTIL ok; 
      OBYTEIO := OBYTEIO+1; 
      (*DEBUG   Hold;   GUBED*) 
      m:=sigsetmask(m); (* restore old signal mask *)
(*3*) END output; 
 
 
PROCEDURE Pause(); 
(*Pause. Delay programm until some key is pressed.*) 
VAR   C : CHAR; 
BEGIN 
(*1*) C:=ReadC(StdInput); 
(*2*) END Pause; 
 
 
PROCEDURE ringclear(); 
(*clear ring buffer. *) 
VAR   i : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) FOR i := 1 TO itlen DO Tbuff[i] := blank; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END ringclear; 
 
 
PROCEDURE ringget(): GAMMAINT; 
(*get gamma integer from ring buffer. *) 
VAR   I : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) I := Tbuff[itrace]; itrace := itrace+1; 
      IF itrace>itlen THEN itrace := itrace-itlen; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN (I); 
(*2*) END ringget; 
 
 
PROCEDURE ringput(I : GAMMAINT); 
(*put gamma integer in ring buffer. *) 
VAR      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) Tbuff[itrace] := I; itrace := itrace+1; 
      IF itrace>itlen THEN itrace := itrace-itlen; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END ringput; 
 
 
PROCEDURE ringstring(S : tString (*ARRAY OF CHAR*)); 
(*put string in ring buffer. *) 
VAR   i, k, l : INTEGER; 
      j : GAMMAINT;
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*prepare*) l := Length(S); 
      IF l > ISIZE THEN l := ISIZE; END; 
      (* ASSERT again = 0 *)
      again := again+ISIZE;  k := itrace; 
(*2*) (*insert string*) i := 1;            
      WHILE i <= l DO 
            IF Char(S,i) = bs THEN k := k-1; 
               IF k < 1 THEN k := k+itlen; END; 
         ELSIF Char(S,i) = del THEN i := i+1; 
          ELSE Tbuff[k] := MASORD(Char(S,i)); 
               k := k+1; END; 
            IF k > itlen THEN k := k-itlen; END; 
            i := i+1; END; 
(*3*) (*insert blanks*) 
      WHILE i < ISIZE DO Tbuff[k] := blank; 
            k := k+1; 
            IF k>itlen THEN k := k-itlen; END; 
            i := i+1; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*4*) END ringstring; 
 
 
PROCEDURE findslot(S : ARRAY OF CHAR; stat : CHAR; VAR old, slot : INTEGER); 
(* Find slot.  The old or new slot for stream S for status 'stat' is 
searched in the file descriptor table. *) 
VAR   i : INTEGER; 
      da, gl : BOOLEAN; 
      sp: tString;
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* See if allready defined. *) 
        slot := 0; old := 0; 
        ArrayToString(S,sp);
        FOR i := 1 TO MAXFILE DO 
            IF stream[i].stat = undefstat THEN slot := i; END; 
            da := IsEqual(sp,stream[i].name); 
            IF stat=anystat THEN gl := TRUE; 
               ELSE gl := (stream[i].stat=stat) OR (stream[i].stat=clostat); 
                    END; 
            IF da AND gl THEN old := i; END; 
            END; 
        IF old>0 THEN slot := old; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*3*) END findslot; 
 
 
PROCEDURE saveold(s : INTEGER); 
(* The characteristics of the old stream are saved in the descriptor 
table. *) 
VAR   m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) IF (s<1) OR (s>MAXFILE) THEN       
         ERROR(severe, "saveold: stream out of range."); 
         RETURN; END; 
(*2*) (* input stream. *) 
        IF stream[s].stat=instat THEN 
           stream[s].lmarg := ILMARG; 
           stream[s].rmarg := IRMARG; 
           stream[s].llen := ISIZE; 
           stream[s].lpos := IPOS; 
           stream[s].ByteIO := IBYTEIO; 
           stream[s].LineIO := ILINEIO; 
           END; 
(*3*) (* output stream. *) 
        IF stream[s].stat=outstat THEN 
           stream[s].lmarg := OLMARG; 
           stream[s].rmarg := ORMARG; 
           stream[s].llen := OSIZE; 
           stream[s].lpos := OPOS; 
           stream[s].ByteIO := OBYTEIO; 
           stream[s].LineIO := OLINEIO; 
           END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*4*) END saveold; 
 
 
PROCEDURE storeold(s : INTEGER); 
(* The characteristics of the old stream are restored from the descriptor 
table. *) 
VAR      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) IF (s<1) OR (s>MAXFILE) THEN 
         ERROR(severe, "storeold: stream out of range."); 
	 m:=sigsetmask(m); (* restore old signal mask *)
         RETURN; END; 
(*2*) (* input stream. *) 
        IF stream[s].stat=instat THEN 
           ILMARG := stream[s].lmarg; 
           IRMARG := stream[s].rmarg; 
           ISIZE := stream[s].llen; 
           IPOS := stream[s].lpos; 
           IBYTEIO := stream[s].ByteIO; 
           ILINEIO := stream[s].LineIO; 
           END; 
(*3*) (* output stream. *) 
        IF stream[s].stat=outstat THEN 
           OLMARG := stream[s].lmarg; 
           ORMARG := stream[s].rmarg; 
           OSIZE := stream[s].llen; 
           OPOS := stream[s].lpos; 
           OBYTEIO := stream[s].ByteIO; 
           OLINEIO := stream[s].LineIO; 
           END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*4*) END storeold; 
 
 
PROCEDURE detkind(S : ARRAY OF CHAR): INTEGER; 
(*Determine the kind of the stream S. *) 
VAR   k : INTEGER; 
      w : CARDINAL;
      sp, sp1, pre : tString;  
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* identify prefix in character string. *) 
        k := diskkind; 
        ArrayToString(S,sp1); SubString(sp1,1,4,sp);  
        ArrayToString("CON:",pre); 
        IF IsEqual(sp,pre) THEN k := termkind; END; 
        ArrayToString("WIN:",pre); 
        IF IsEqual(sp,pre) THEN k := winkind; END; 
        ArrayToString("RAM:",pre); 
        IF IsEqual(sp,pre) THEN k := ramkind; END; 
        ArrayToString("NUL:",pre); 
        IF IsEqual(sp,pre) THEN k := nulkind; END; 
        ArrayToString("GRA:",pre); 
        IF IsEqual(sp,pre) THEN k := termkind; END; 
      m:=sigsetmask(m); (* restore old signal mask *)
        RETURN (k); 
(*2*) END detkind; 
 
 
PROCEDURE popIstream(); 
(* Pop input stream.  The most recently open input stream is popped from 
the open stream stack.  Popping continues until a non closed stream is 
found.  *) 
VAR   s, slot : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* Check if it is last on stack. *) 
        slot := INTEGER(FIRST(Istack)); 
        IF (RED(Istack)<>SIL) AND (slot=Istream) THEN 
           Istack := RED(Istack); 
           slot := INTEGER(FIRST(Istack)); 
           END; 
        s := Istream; 
        Istream := slot; 
(*2*) (*save and store. *) 
        saveold(s); 
        storeold(slot); 
(*3*) (*recursion*) 
        IF stream[slot].stat=clostat THEN popIstream(); END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*5*) END popIstream; 
 
 
PROCEDURE popOstream(); 
(* Pop output stream.  The most recently open output stream is popped from 
the open stream stack.  Popping continues until a non closed stream is 
found.  *) 
VAR   s, slot : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* Check if it is last on stack. *) 
        slot := INTEGER(FIRST(Ostack)); 
        IF (RED(Ostack)<>SIL) AND (slot=Ostream) THEN 
           Ostack := RED(Ostack); 
           slot := INTEGER(FIRST(Ostack)); 
           END; 
        s := Ostream; 
        Ostream := slot; 
(*2*) (*save and store. *) 
        saveold(s); 
        storeold(slot); 
(*3*) (*recursion*) 
        IF stream[slot].stat=clostat THEN popOstream(); END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*4*) END popOstream; 
 
 
PROCEDURE pushstream(s : INTEGER); 
(*Push stream.  The stream 'slot' is pushed to the open stream stack. *) 
VAR   i : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (*save old values. *) 
        CASE stream[s].stat OF 
                | outstat : 
                        IF Ostream>0 THEN 
                           saveold(Ostream); END; 
                        Ostack := COMP(GAMMAINT(s),Ostack); 
                        Ostream := s; 
                | instat : 
                        IF Istream>0 THEN saveold(Istream); END; 
                        Istack := COMP(GAMMAINT(s),Istack); 
                        Istream := s; 
                ELSE 
                END; 
(*2*) (*store old values. *) 
        storeold(s); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*3*) END pushstream; 
 
 
PROCEDURE CUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(* Close unit.  The unit S is closed, with S as the external name. 
CUNIT returns 0 on successful completion, ne 0 else.*) 
VAR     iold, oold, slot, k : INTEGER; 
        ok : BOOLEAN; 
        m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* See if open. *) 
        findslot(S, instat, iold, slot); 
        findslot(S, outstat, oold, slot); 
(*2*) (* Pop from open stream stacks. *) 
        IF Istream=iold THEN popIstream(); END; 
        IF Ostream=oold THEN popOstream(); END; 
(*3*) (* determine stream kind and close streams. *) 
        IF iold>0 THEN 
           k := stream[iold].kind; 
                CASE k OF 
                        | termkind : ok := TRUE; 
                        | ramkind :  ok := TRUE; 
                        | winkind :  ok := TRUE; 
                        | nulkind :  ok := TRUE; 
                        | diskkind : ReadClose(stream[iold].sysf); 
                                     ok := TRUE; 
                     ELSE ok := FALSE; 
                          END; 
           IF NOT ok THEN 
              ERROR(harmless, "Cannot close requested stream. "); 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN (GAMMAINT(iold)); END; 
           stream[iold].stat := clostat; 
           END; 
        IF oold>0 THEN 
           k := stream[oold].kind; 
                CASE k OF 
                        | termkind : ok := TRUE; 
                        | ramkind :  ok := TRUE; 
                        | winkind :  ok := TRUE; 
                        | nulkind :  ok := TRUE; 
                        | diskkind : WriteClose(stream[oold].sysf); 
                                     ok := TRUE; 
                     ELSE ok := FALSE; 
                          END; 
           IF NOT ok THEN 
              ERROR(harmless, "Cannot close requested stream. "); 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN (GAMMAINT(oold)); 
              END; 
           stream[oold].stat := clostat; 
           END; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN 0; 
(*5*) END CUNIT; 

 
PROCEDURE CioUNIT(iold, oold : INTEGER): GAMMAINT; 
(* Close unit.  The unit in slot iold or oold is closed. 
CioUNIT returns 0 on successful completion, ne 0 else.*) 
VAR   slot, k : INTEGER; 
      ok : BOOLEAN; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* Pop from open stream stacks. *) 
      IF Istream=iold THEN popIstream(); END; 
      IF Ostream=oold THEN popOstream(); END; 
(*2*) (* determine stream kind and close streams. *) 
        IF iold>0 THEN 
           k := stream[iold].kind; 
                CASE k OF 
                        | termkind : ok := TRUE; 
                        | ramkind :  ok := TRUE; 
                        | winkind :  ok := TRUE; 
                        | nulkind :  ok := TRUE; 
                        | diskkind : ReadClose(stream[iold].sysf); 
                                     ok := TRUE; 
                     ELSE ok := FALSE; 
                          END; 
           IF NOT ok THEN 
              ERROR(harmless, "Cannot close requested stream. "); 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN (GAMMAINT(iold)); END; 
           stream[iold].stat := clostat; 
           END; 
        IF oold>0 THEN 
           k := stream[oold].kind; 
                CASE k OF 
                        | termkind : ok := TRUE; 
                        | ramkind :  ok := TRUE; 
                        | winkind :  ok := TRUE; 
                        | nulkind :  ok := TRUE; 
                        | diskkind : WriteClose(stream[oold].sysf); 
                                     ok := TRUE; 
                     ELSE ok := FALSE; 
                          END; 
           IF NOT ok THEN 
              ERROR(harmless, "Cannot close requested stream. "); 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN (GAMMAINT(oold)); 
              END; 
           stream[oold].stat := clostat; 
           END; 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN 0; 
(*5*) END CioUNIT; 
 
 
PROCEDURE SIUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(* Set input unit.  Input unit is set to S, with S as the external name. 
SIUNIT returns 0 on successful completion, ne 0 else.*) 
VAR   i, slot, old, sp, k : INTEGER; 
      INI : GAMMAINT; 
      ok : BOOLEAN; 
      m: INTEGER;

BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* See if allready defined. *) 
        findslot(S, instat, old, slot); 
        IF slot=0 THEN 
           ERROR(severe, "Maximal number of Files is allready in use. "); 
           m:=sigsetmask(m); (* restore old signal mask *)
           RETURN 1; END; 
(*2*) (* Save and set characteristics of old stream. *) 
        IF (old>0) THEN 
           saveold(Istream); 
           storeold(old); 
           Istream := old;
           IF stream[old].stat=instat THEN 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN 0; END; 
           END; 
(*3*) (* determine stream kind if new and open stream 'slot'. *) 
        IF (old=0) THEN 
           k := detkind(S); 
           stream[slot].kind := k; 
        ELSE  k := stream[slot].kind; 
        END; 
        CASE k OF 
                | termkind : ok := TRUE; ECHO := FALSE; 
                | ramkind : INI := NEWQUE(); 
                            findslot(S, anystat, old, sp); 
                            IF old>0 THEN 
                               INI := stream[old].sysq; END; 
                            stream[slot].sysq := INI; 
                            ok := TRUE; ECHO := FALSE; 
                | winkind : ok := TRUE; ECHO := FALSE; 
                | nulkind : ok := TRUE; ECHO := FALSE; 
                | diskkind : stream[slot].sysf := masReadOpen(S);
                             IF stream[slot].sysf < 0 THEN  
                                ERROR(harmless, S); 
                                ERROR(harmless, "Cannot open file. "); 
                                m:=sigsetmask(m); (* restore old signal mask *)
                                RETURN (GAMMAINT(slot)); END; 
                             ok := TRUE; ECHO := TRUE; 
            ELSE ok := FALSE; END; 
        IF NOT ok THEN 
           ERROR(harmless, "Cannot open requested stream. "); 
           m:=sigsetmask(m); (* restore old signal mask *)
           RETURN (GAMMAINT(slot)); 
           END; 
(*4*) (* initialize file descriptor and line characteristics. *) 
        IF (old=0) THEN 
           ArrayToString(S,stream[slot].name); END; 
        stream[slot].stat := instat; 
        INEWLINE := FALSE; 
        pushstream(slot); 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN 0; 
(*5*) END SIUNIT; 
 
 
PROCEDURE SOUNIT(S : ARRAY OF CHAR): GAMMAINT; 
(* Set output unit.  Output unit is set to stream S, with s as the 
external name.  SOUNIT returns 0 on successful completion, ne 0 else. *) 
VAR   i, slot, old, k, sp : INTEGER; 
      ok : BOOLEAN; 
      INI : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) (* See if allready defined. *) 
        findslot(S, outstat, old, slot); 
        IF slot=0 THEN 
           ERROR(severe, "Maximal number of Files is allready in use. "); 
           m:=sigsetmask(m); (* restore old signal mask *)
           RETURN 1; END; 
(*2*) (* Save and set characteristics of old stream. *) 
        IF old>0 THEN 
           saveold(Ostream); 
           storeold(old); 
           Ostream := old; 
           IF stream[old].stat=outstat THEN 
              m:=sigsetmask(m); (* restore old signal mask *)
              RETURN 0; END; 
           END; 
(*3*) (* determine stream kind if new and open stream 'slot'. *) 
        IF (old=0) THEN 
           k := detkind(S); 
           stream[slot].kind := k; 
        ELSE  k := stream[slot].kind; END; 
        CASE k OF 
                | termkind : ok := TRUE; 
                | ramkind : INI := NEWQUE(); 
                            findslot(S, anystat, old, sp); 
                            IF old>0 THEN 
                               INI := stream[old].sysq; 
                               END; 
                            stream[slot].sysq := INI; 
                            ok := TRUE; 
                | winkind : ok := TRUE; 
                | nulkind : ok := TRUE; 
                | diskkind : stream[slot].sysf := WriteOpen(S); 
                             IF stream[slot].sysf < 0 THEN 
                                (* stream[slot].sysf := Create(S); *) 
     	       	    	       ok:=FALSE;
                                END; 
                             ok := TRUE; 
             ELSE ok := FALSE; END; 
        IF NOT ok THEN 
           ERROR(harmless, S); 
           ERROR(harmless, "Cannot open requested stream. "); 
           m:=sigsetmask(m); (* restore old signal mask *)
           RETURN (GAMMAINT(slot)); END; 
(*4*) (* initialize file descriptor and line characteristics. *) 
        IF (old=0) THEN 
           ArrayToString(S,stream[slot].name); END; 
        stream[slot].stat := outstat; 
        ONEWLINE := FALSE; 
        pushstream(slot); 
      m:=sigsetmask(m); (* restore old signal mask *)
      RETURN 0; 
(*5*) END SOUNIT; 
 
 
PROCEDURE SILINE(VAR S, L, R : GAMMAINT); 
(* Set input line.  The input line length is set to S, the left margin is 
set to L and the right margin is set to R. If any of the values of 
S, L or R is negative, then the corresponding value is left unchanged. 
The values in effect are returned. *) 
VAR   S1, L1, R1 : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) S1 := GAMMAINT(ISIZE); L1 := GAMMAINT(ILMARG); 
      R1 := GAMMAINT(IRMARG); 
      IF S>0 THEN ISIZE := INTEGER(S); END; 
      IF R>0 THEN IRMARG := INTEGER(R); END; 
      IF L>=0 THEN ILMARG := INTEGER(L); END; 
      IF IRMARG>ISIZE THEN IRMARG := ISIZE; END; 
      IF ILMARG>=IRMARG THEN ILMARG := IRMARG-1; END; 
      S := S1; L := L1; R := R1; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END SILINE; 
 
 
PROCEDURE SOLINE(VAR S, L, R : GAMMAINT); 
(* Set output line.  The output line length is set to S, the left margin is 
set to L and the right margin is set to R. If any of the values of 
S, L or R is negative, then the corresponding value is left unchanged. 
The values in effect are returned. *) 
VAR   S1, L1, R1 : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) S1 := GAMMAINT(OSIZE); L1 := GAMMAINT(OLMARG); 
      R1 := GAMMAINT(ORMARG); 
      IF S>0 THEN OSIZE := INTEGER(S); END; 
      IF R>0 THEN ORMARG := INTEGER(R); END; 
      IF L>=0 THEN OLMARG := INTEGER(L); END; 
      IF ORMARG>OSIZE THEN ORMARG := OSIZE; END; 
      IF OLMARG>=ORMARG THEN OLMARG := ORMARG-1; END; 
      S := S1; L := L1; R := R1; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END SOLINE; 
 
 
PROCEDURE Summary(); 
(*Summary of stream IO. *) 
VAR   i : INTEGER; 
      j : GAMMAINT; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) BLINES(1); SWRITE("Summary of stream IO "); BLINES(1); 
      j := 0; 
        FOR i := 1 TO MAXFILE DO 
                IF stream[i].stat<>undefstat THEN 
                        j := j+1; 
                        IF i=Istream THEN 
                                saveold(i); 
                        END; 
                        IF i=Ostream THEN 
                                saveold(i); 
                        END; 
                        SWRITE("Name     "); 
                        StWRITE(stream[i].name); 
                        SWRITE(", "); 
                        BLINES(0); 
                        CASE stream[i].stat OF 
                                | instat : 
                                        SWRITE("Input,   "); 
                                | outstat : 
                                        SWRITE("Output,  "); 
                                | clostat : 
                                        SWRITE("Closed,  "); 
                                ELSE 
                                        SWRITE("Unknown, "); 
                                END; 
                        SWRITE("Byte-IO "); 
                        GWRITE(stream[i].ByteIO); 
                        SWRITE(", Line-IO "); 
                        GWRITE(stream[i].LineIO); 
                        SWRITE(", Lmarg "); 
                        GWRITE(GAMMAINT(stream[i].lmarg)); 
                        SWRITE(", Rmarg "); 
                        GWRITE(GAMMAINT(stream[i].rmarg)); 
                        SWRITE(", Size "); 
                        GWRITE(GAMMAINT(stream[i].llen)); 
                        SWRITE(". "); 
                        BLINES(0); 
                END; 
        END; 
      BLINES(1); GWRITE(j); SWRITE(" Files used. "); 
      (*Hold();*) BLINES(1); 
      m:=sigsetmask(m); (* restore old signal mask *)
(*3*) END Summary; 
 
 
PROCEDURE StorSummary(); 
(*MASSTOR Summary. *) 
VAR   ML, NL, TL : LIST; 
BEGIN 
(*1*) BLINES(1); 
      ML := GCC; NL := GCCC; TL := TAU; 
      GWRITE(ML); SWRITE(" garbage collections, "); 
      GWRITE(NL); SWRITE(" cells reclaimed, in "); 
      GWRITE(TL); SWRITE(" milliseconds."); BLINES(0); 
      NL := CELLS(); TL := TIME()-TAU0; 
      GWRITE(NL); SWRITE(" cells used, in "); 
      GWRITE(TL); SWRITE(" milliseconds."); BLINES(0); 
      TL := CLOCK()-TAU0; 
      GWRITE(NU); SWRITE(" cells allocated. "); 
      SWRITE("Total time "); GWRITE(TL); SWRITE(" milliseconds."); 
      BLINES(0); 
(*2*) END StorSummary; 
 

PROCEDURE SWRITE(S : ARRAY OF CHAR); 
(* String write. S is a character string with respect to local 
character codes. The single characters are converted to ALDES codes 
and written to the output stream. *) 
VAR   i, l: CARDINAL; 
      C : GAMMAINT; 
BEGIN 
(*1*) i:=0; l:=HIGH(S); 
      REPEAT  
             IF S[i] <> nul THEN C := MASORD(S[i]); CWRITE(C);
                            ELSE RETURN END; 
             i:=i+1;
             UNTIL i > l; 
(*2*) END SWRITE; 


PROCEDURE StWRITE(S : tString); 
(* String write. S is a character string with respect to local 
character codes. The single characters are converted to ALDES codes 
and written to the output stream. *) 
VAR     i, l : CARDINAL; 
        C : GAMMAINT; 
BEGIN 
(*1*) l:=Length(S); i:=0;
      WHILE i < l DO i:=i+1; C := MASORD( Char(S,i) );
            CWRITE(C); END;
(*2*) END StWRITE; 
 
 
(* 
PROCEDURE testBIOS(); 
(* Test BASBIOS. Some tests are performed to check correct 
implementation. *) 
VAR   i, j, k : GAMMAINT; 
      L, M : LIST; 
      ii : INTEGER; 
BEGIN 
(*1*) (*see if initialization was ok. *) 
      Summary(); 
(*2*) (*write character code card to terminal. *) 
        FOR ii := 0 TO CHI DO 
            CWRITE(ii); CWRITE(blank); END; 
        BLINES(1); 
        i := 1; 
        IF i=1 THEN 
           (*test terminal input. *) 
           REPEAT 
                  BLINES(0); 
                  SWRITE("Bitte Zahlen eingeben (0 = ende) "); 
                  i := GREAD(); BLINES(0); 
                  SWRITE("Eingegeben "); GWRITE(i); BLINES(1); 
                  UNTIL i = 0; 
           BLINES(1); 
           SWRITE("MASBIOS 1. test finished. "); BLINES(1); 
           Summary(); 
           (*test write to ram stream. *) 
           k := SOUNIT("RAM:1"); 
           IF k<>0 THEN 
              SWRITE("Open RAM:1 for output not successful. "); 
              BLINES(1); END; 
           FOR ii := 1 TO 1000 DO 
               GWRITE(GAMMAINT(ii)); CWRITE(blank); END; 
           k := CUNIT("RAM:1"); 
           IF k<>0 THEN 
              SWRITE("Close RAM:1: not successful. "); 
              BLINES(1); END; 
           (*test read from ram stream. *) 
           k := SIUNIT("RAM:1"); 
           IF k<>0 THEN 
              SWRITE("Open RAM:1 for input not successful. "); 
              BLINES(1); END; 
           i := 0; 
           REPEAT 
                  i := i+1; 
                  j := GREAD(); 
                  IF i<>j THEN SWRITE("wrong ");
                     GWRITE(i); CWRITE(blank); 
                     GWRITE(j); BLINES(0); 
                     END; 
                  UNTIL i>=10; 
            k := CUNIT("RAM:1"); 
            IF k<>0 THEN 
               SWRITE("Close RAM:1: not successful. "); 
               BLINES(1); END; 
            BLINES(1); 
            SWRITE("MASBIOS 2. test finished. "); BLINES(1); 
            Summary(); 
            (*test write to disk stream. *) 
            k := SOUNIT("TEST.TXT"); 
            IF k<>0 THEN 
               SWRITE("Open TEST.TXT for output not successful. "); 
               BLINES(1); END; 
            FOR ii := 1 TO 1000 DO GWRITE(GAMMAINT(ii)); 
                CWRITE(blank); END; 
            k := CUNIT("TEST.TXT"); 
            IF k<>0 THEN 
               SWRITE("Close TEST.TXT not successful. "); 
               BLINES(1); END; 
            BLINES(1); 
            SWRITE("MASBIOS 3. test finished. "); BLINES(1); 
            (*test read from disk stream. *) 
            k := SIUNIT("TEST.TXT"); 
            IF k<>0 THEN 
               SWRITE("Open TEST.TXT for input not successful. "); 
               BLINES(1); END; 
            i := 1; 
            REPEAT 
                   j := GREAD(); 
                   IF i<>j THEN SWRITE("wrong ");
                                GWRITE(i); 
                                SWRITE(" - "); 
                                GWRITE(j); 
                                BLINES(0); 
                      END; 
                   i := i+1; 
                   UNTIL i>=100; 
            k := CUNIT("TEST.TXT"); 
            IF k<>0 THEN 
               SWRITE("Close TEST.TXT not successful. "); 
               BLINES(1); END; 
            BLINES(1); 
            SWRITE("MASBIOS 4. test finished. "); BLINES(1); 
            Summary(); 
            (*open several files at a time. *) 
            k := SIUNIT("RAM:1"); 
            IF k<>0 THEN 
               SWRITE("Open RAM:1 for input not successful. "); 
               BLINES(1); END; 
            k := SIUNIT("TEST.TXT"); 
            IF k<>0 THEN 
               SWRITE("Open TEST.TXT for input not successful. "); 
               BLINES(1); END; 
            REPEAT 
                   j := GREAD(); 
                   UNTIL j>999;   
            BLINES(1); 
            SWRITE("MASBIOS 5. test finished. "); BLINES(1); 
            Summary(); 
        END; 
        (*read from file and write to screen. *) 
        k := SIUNIT("LISP.INI"); 
        IF k<>0 THEN 
           SWRITE("Open LISP.INI for input not successful. ");
           BLINES(1); END; 
        k := MASORD("a"); 
        i := 0; 
        REPEAT 
               j := CREAD(); 
               CWRITE(j); 
               i := i+1; 
               IF i>=40 THEN 
                  BLINES(1); 
                  i := 0; 
                  END; 
               UNTIL j>=k; 
        BLINES(1); 
        SWRITE("MASBIOS 6. test finished. "); BLINES(1); 
        Summary(); 
(*9*) END testBIOS; 
*) 
 
PROCEDURE TAB(N : GAMMAINT); 
(* Tabulate.  n is a positive integer.  If lmarg lt n le rmarg then 
blanks are transmitted to the output stream until opos eq n.*) 
VAR   n : INTEGER; 
      m: INTEGER;
BEGIN 
      m:=sigblock(SigMask(SIGUSR1)); (* block SIGUSR1*)
(*1*) n := INTEGER(N); 
      IF (OLMARG<n) AND (n<=ORMARG) THEN 
         WHILE OPOS<n DO CWRITE(blank); END; 
         END; 
      m:=sigsetmask(m); (* restore old signal mask *)
(*2*) END TAB; 
 
PROCEDURE IStreamKind(): INTEGER;
(* Input stream kind. The kind of the current input stream is returned. *)
BEGIN
     RETURN stream[Istream].kind; 
END IStreamKind;

PROCEDURE OStreamKind(): INTEGER;
(* Output stream kind. The kind of the current output stream is returned. *)
BEGIN
     RETURN stream[Ostream].kind; 
END OStreamKind;

PROCEDURE EStreamKind(): INTEGER;
(* Error stream kind. The kind of the current error stream is returned. *) 
BEGIN
     RETURN stream[Estream].kind; 
END EStreamKind;


 
(* MASBIOS initialization *) 
BEGIN 
(*1*) InitBIOS(); 
(*2*) (*DEBUG   
        SWRITE("Module MASBIOS initialized."); 
        BLINES(1); 
        testBIOS(); 
        CloseBIOS(); 
        StorSummary(); 
        SWRITE("Test MASBIOS ready.");  BLINES(1);
        CloseIO;
          GUBED*) 
(*3*) END MASBIOS. 
 
(* -EOF- *)
