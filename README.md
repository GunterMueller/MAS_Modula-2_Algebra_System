# MAS_Modula-2_Algebra_System

Fork of
    MAS: Modula-2 Algebra System
Computer Algebra Group
University of Passau, Germany

Version 1.01, March 1998

Mannheim mirror

cag.fmi.uni-passau.de (went offline in 2009)


URL http://krum.rz.uni-mannheim.de/mas/


MAS: Modula-2 Algebra System
Computer Algebra Group
University of Passau, Germany

Version 1.01, March 1998

Mannheim mirror

cag.fmi.uni-passau.de (went offline in 2009)

Abstract
MAS (Modula-2 Algebra System) is an experimental computer algebra system, developed at the University of Passau. MAS combines imperative programming facilities with algebraic specification capabilities for design and study of algebraic algorithms. It contains a large library of implemented Groebner basis algorithms for nearly all algebraic structures where such methods exist. MAS further includes algorithms for real quantifier elimination, parametric real root counting, and for computing in (noncommutative) polynomial rings.
Distribution files
The distribution is by means of gnuzip'ed tar files. Form the distribution files you need at least an executable, the tutorial and the examples. The files can be found at alice.fmi.uni-passau.de (went offline in 2009) or from Mannheim mirror.

If you pick the source code we recommend to pick also the definition module and indexes document along with it. To compile the source code you will also need the Modula-2 to C translator "mtc", the "reuse" library, gnumake, and a C-compiler (preferably gcc). Further we recommend the GNU readline library and the kpathsea library.

The following files are available

- executables

  mas-hppa1.1-hp-hpux9.03-1.00.tar.gz     HP 9000, running HP-UX
  mas-i386-unknown-os2-1.00.tar.gz        Intel PC, running OS/2
  mas-i486-unknown-linux-1.00.tar.gz      Intel PC, running LINUX
  mas-mab-next-nextstep3-1.00.tar.gz      NextStep
  mas-rs6000-ibm-aix3.2.5-1.00.tar.gz     RS/6000, running AIX 3 
  mas-sparc-sun-sunos4.1.3C-1.00.tar.gz   Sun Sparc, running SunOS

- documentation:

  mastut.tar.gz   MAS tutorial and interactive users guide in LaTeX.
  mastut.ps.gz    as PostScript

  masdef.tar.gz   MAS Modula-2 definition modules, 3 indexes 
                  and specifications in LaTeX.
  masdef.ps.gz    as PostScript

- examples and test files:

  masexam.tar.gz  examples, help files, test files. 

- Modula-2 source code:

  massrc.tar.gz

Installation
Unpack
To install MAS unpack the respective files. E.g. with

   gnutar xfvz masexam.tar.gz 

or

   gzip -d -c masexam.tar.gz | tar -cvf -


in some directory. The files will unpack into the following subdirectories:

mas/doc 
       /mastut          Tutorial and Users Guide.
       /masdef          Definitions and indexes document.
       /massys          System document.
   /<machine>           Executables in respective machine directory 
       mas              Unix executable. 
       mas.exe          OS2 executable, requires /dll.
       emx.exe mas.out  DOS extender and executable. 
   /exam                Examples *.in
                        Copying information   
        .masrc          initialization file.
        mas.ini         initialization file.
        helpup.mas      Help initialization file.
        testall.mas     Driver file for /test directory.
        /help           Comments and module information.
        /spec           Example specifications.
        /test           Test files.
   /dll                 emx dyn. link libs for OS2.
   /src                 Modula-2 source code 
       /maskern         System dependent files, memory, IO, ... 
       /maslisp         LISP interpreter, parsers, ...
       /masmain         Main program, interfaces, ...
       /masarith        Basic Arithmetic, integer, rational, ...
       /maspoly         Polynomial systems, recursive, distributive, ...
       /masring         Ideals, Groebner bases, algeb. geometry, ...
       /masmodul        Linear algebra, diophantine equations, syzygies, ...
       /masnc           Non-commutative solvable polynomial rings, ...
       /sacring         Polynomial factorization, real roots, gcd, res, ...
       /masroot         Real root counting, ...
       /maslog          Logic formuals, Real Quantifier Elimination, ...  
       /masdom          Domain coefficients, comprehensive G bases, ...
       /masib           Involutive bases, ...


File naming conventions:

        *.md            Modula-2 definition modules.
        *.mi            Modula-2 implementation modules.
	*.mip		Modula-2 implementation modules with cpp-statements.
        *.h             C header files.
        *.c             C code files.
        *.o             object code files.
        *.a             library archives.

        *.ini           MAS initialization files (obsolete).
        *.hlp           MAS help information.
        *.in            MAS input files (obsolete).
        *.mas           MAS input files.
        *.out           MAS output files.


Test
Test the installation with the following command

             [path]mas -m 4000 -E -e -o test-all


from the /exam directory. This produces a file 'test-all.out' which you can compare to the supplied 'test-all.orig' file. The warnings are intentional and only lines with timings should "diff"er.
Start - Stop
Add the mas/bin directory to the PATH or use the complete pathname in the following examples.

   - start         'mas' or 'mas.exe' or 'emx mas.out'  

   - banner        'This is MAS the Modula-2 Algebra System, Version 1.xxx.'

   - system prompt 'MAS: ' 

   - system answer 'ANS: '

   - input (e.g.)  'a:=2*3.' A statement is terminated by period '.' 
 
   - help with     'help.' or 'help(name).' or 'help(name,Loaded).'
  
   - interupt      ^C     CNTRL-C 
 
   - leave with    'EXIT.' or 'exit.' or 'quit.'


Path and Compile
On all systems add the mas/<machine> directory to the PATH or use the complete pathname to call the MAS executables.

On OS2 systems also add the mas/dll directory to the LIBPATH and reboot or use your existing emx dlls.

To compile MAS unpack the source code and create a directory "<machine>" for your machine type. From the directory mas/<machine> execute ../configure to generate the Makefile, then execute gnumake to compile a mas executable.

Further details can be found in the readme file accompanying the source code.
Notes

    Some help facilities need an 'awk' program.
    The Makefiles for the source code may need an 'awk' or 'sed' program or other unix utilities. 

Release and Change Notes
Major mathematical library changes of the version 1.0 (Oktober 1996) are:

    arbitrary domain polynomial system extended to a generic Gröbner base package.
    added an optimized Gröbner base package (including the ``sugar''-method) by C. Rose,
    added a package to compute factorized Gröbner bases by J. Pfeil,
    Improved comprehensive Gröbner Basis algorithms using factorization, condition evaluation and case elimination by M. Pesch,
    a package for involutive bases by R. Grosse-Gehling,
    added a package for invariant polynomials by M. Goebel,
    added a package for counting real roots based on Hermites method by F. Lippold,
    added a logic formula representation with simplification package and real quantifier elimination package by A. Dolzmann,
    the linear algebra package of MAS has been improved. 

Major system changes of the current version 1.0 are:

    MAS language accepts small letter key words and braces {} to denote list expressions.
    Distribution now uses GNU autoconf for easy compilation.
    GNU readline for easier command line editing.
    Using Kpathsearch Library from K. Berry.
    Improved batch processing capabilities.
    Improved error handling and user signal processing to examine long running computations.
    Generic garbage collection support for most architectures. 

The major system changes between release 0.6 and 0.7 (April 1993) are:

    Distribution based on Modula-2 to C translator and a C distribution which will work on 'most' workstations.
    New support for PC 386 and higher (OS2 2.0 and higher) with emx dll runtime libraries.
    New support for PC 386 and higher (DOS 5.0) with emx DOS extender (10 times faster).
    Dropped support for the Atari, Amiga and PC XT up to 286 versions. That means, that we do no more distribute executables for these systems, but if you have the maskern(el) you can get the new source code (except maskern) and compile it on your system.
    The HELP and help command has been changed to provide name ranges and more information from the procedure comments. 


Major mathematical library changes between release 0.6 and 0.7 are:

    added comprehensive Groebner base package by E. Schoenfeld,
    arbitrary domain polynomial system implemented,
    added several new basic arithmetic packages: complex numbers, quaternion numbers, octonion numbers, finite fields,
    added package for computation in non-commutative polynomial rings of solvable type: *-product, left Groebner base, two-sided Groebner base, elements in the center,
    added a package for the computation of generators for the module of syzygies of systems of homogeneous polynomial equations and Groebner bases for modules over polynomial rings (also available for solvable polynomial rings) by J. Phillip,
    added universal Groebner base package by T. Belkahia,
    added d-Groebner base and e-Groebner base packages for Groebner bases over the integers and univariate rational polynomial rings by W. Mark. 


The major changes between release 0.3 and 0.6 (March 1991) are:

    added language extensions for specification capabilities,
    added a parser for the ALDES language and possibility for interpretation of ALDES programs,
    added a linear algebra package,
    added an interface between the MAS language and the distributive polynomial system,
    improved symbol handling by hash tables combined with balanced trees,
    EMS support for IBM PC implementations. 


The minor changes between release 0.3 and 0.6 are:

    PRAGMA construct for the state definition of the MAS executable.
    Overloading of MAS arithmetical operators by generic function names.
    Typed string constants in MAS expressions.
    VAR parameters in MAS procedure declarations in ALDES style.
    Static scope analysis by the parser.
    Explicit stack overflow check since not all compilers handled stack overflow correctly. 


Release notes for Version 0.3 (November 1989):

    The MAS parser has been changed for better Modula-2 compatibility.
    MAS LISP has been made more robust against incorrect user input.
    The MAS main program has been enhanced to recognize the following command line parameters:

                    -m number-of-KB     
                    -f data-set-name

        the memory option '-m' gives the number of Kilo-Byte storage, requested from the operating system.
        the file name option '-f' can be used to overwrite the default file name 'MAS.INI' during startup. With this option MAS can be run in batch mode if the EXIT statement is contained in the data set. 


Introduction to MAS
Starting point for the development of MAS was the requirement for a computer algebra system with an up to date language and design which makes the existing ALDES / SAC-2 algorithm libraries available. At this time there have been about 650 algorithms in ALDES / SAC-2 and in addition I had 450 algorithms developed on top of ALDES / SAC-2. The tension of reusing existing software in an interactive environment with specification capabilities contributes most to the evolution of MAS.

The resulting view of the software has many similarities with the model theoretic view of algebra. The abstract specification capabilities are realized in a way that an interpretation in an example structure (a model) can be denoted. This means that is is not only possible to compute in term models modulo some congruence relation, but it is moreover possible to exploit an fast interpretation in some optimized (or just existing) piece of software.
Overview
MAS is an experimental computer algebra system combining imperative programming facilities with algebraic specification capabilities for design and study of algebraic algorithms. The goal of the MAS system is to provide:

    an interactive computer algebra system
    comprehensive algorithm libraries, including the ALDES/SAC-2 system [Collins 82],
    a familiar program development system with an efficient compiler,
    an algebraic specification component for data structure and algorithm design
    algorithm documentation open to the users. 

Key attributes of the MAS system are:

    portability (it is portable to a computer during a student exercise `Praktikum'), machine dependencies isolated in a small kernel,
    extendability (it is possible to add and interface to external algorithm libraries), open system architecture, transparent low level facilities:
    storage management (garbage collection is provided without user cooperation), stable error handling (no system break down on misspelled expressions and runtime exceptions), input / output with streams (no changes are required to existing libraries to redirect I/O).
    effectivity (critical parts can be compiled and still be accessed interactively)
    expressiveness (possiblitity to specify abstract algebraic concepts like rings or fields) 

The goals and attributes have been achieved by the following main design concepts:

MAS replaces the ALDES language [Loos 76] and the FORTRAN implementation system of SAC-2 by the Modula-2 language [Wirth 85]. Modula-2 is well suited for the development of large program libraries; the language is powerful enough to implement all parts of a computer algebra system and the Modula-2 compilers have easy to use program development environments.

To provide an interactive calculation system a LISP interpreter is implemented in Modula-2 with full access to the library modules. For better usability a Modula-2 like imperative (interaction) language was defined, including a type system and function overloading capabilities. To increase expressiveness high-level specification language constructs have been included together with conditional term rewriting capabilities. They resemble facitilies known from algebraic specification languages like ASL [Wirsing 86].

Further design issues are:

MAS views mathematics in the sense of universal algebra and model theory and is in some parts influenced by category theory. In contrast to other computer algebra systems (like Scratchpad II [Jenks 85]), the MAS concept provides a clean seperation of computer science and mathematical concepts. The MAS language and its interpreter has no knowledge of mathematics and mathematical objects; however it is capable to describe (specify) and implement mathematical objects and to use libraries of implemented mathematical methods. Further the imperative programming, the conditional rewriting and function overloading concepts are seperated in a clean way.

MAS includes the capability to join specifications and to rename sorts and operations during import of specifications. This allows both the specification of abstract objects (rings, fields), concrete objects (integers, rational numbers) and concrete objects in terms of abstract objects (integers as a model of rings). Specifications can be parameterized in the sense of lambda-abstraction.

The semantics of a specification can be described either by implementations, axioms or models. The implementation part describes (imperative) procedures and data representations.

The axioms part describes conditional rewrite rules which define a reduction relation on the term algebra generated by the sorts and operations of the specification. The semantics is therefor the class of models of the term algebra modulo the (congruence) relation. Currently there are no facilities to solve conditional equations.

The model part describes the association between abstract specifications (like rings) and concrete specifications (like integers). The semantics is the interpretation of the (abstract) function in the model. Operations in models can be compiled functions, user defined imperative functions or term rewrite rules. The function overloading capabilities are realized by this concept. Dynamic abstract objects like finite fields can be handled by a descriptor concept.

Evaluation of functional terms is as follows: If there is a model in which the function has an interpretation and a condition on the parameters is fulfilled, then the interpretation of the function in this model is applied to the interpretation (values) of the arguments. If there is an imperative procedure, then the procedure body is evaluated in the procedure context. If the unification with the left hand side of a rewrite rule is possible and the associated condition evaluates to true, then the right hand side of the rewrite rule is evaluated. Otherwise the functional term is left unchanged.

In contrast to functional programming languages (like SML [Appel 88]) which implement typed lambda calculus the types of operations are not deduced from the program text but must be explicitly defined in the specification of an operation, in a variable declaration or in a typed string expression.

A weak point in the current MAS design is that the language is only interpreted. This is actualy not a handicap in execution speed since compiled libraries can be used, but in a too weak semantic analysis of the specifications. This means that certain errors in the specifications are only detected during actual evaluation of an expression.
Achievements and Current State
The steps towards the MAS system have been:

    definition of a syntax transformation scheme between ALDES and Modula-2; development of a translator and translation of most of the ALDES / SAC-2 libraries to Modula-2;
    development of a storage management system in Modula-2 with automatic garbage collection in an uncooperative environment; implementation of a input / output system in Modula-2 with streams;
    implementation of a LISP interpreter in Modula-2 with access to the compiled procedures (using Modula-2 procedure types and variables);
    definition of an imperative Modula-2 like interaction language;
    implementation of a parser for the interaction language and corresponding modifications to the LISP interpreter;
    design of high-level language constructs for algebraic specification and a type system with function overloading capabilities; modification of the language parser and the interpreter;
    design of specifications for relevant algebraic structures. 

Steps 1 and 2 were subject to the restriction that the interface had to be compatible with the existing ALDES / SAC-2 libraries. Steps 1 and 2 have been reported in [Kredel 88]. Reports on steps 3, 4, 5 and progress reports on step 6 have been given in [Kredel 90]. The state of step 6 has been reported in [Kredel 91].

Versions of the MAS system are running on Atari ST (TDI and SPC Modula-2 compilers), IBM PC/AT (M2SDS and Topspeed Modula-2 compilers) and Commodore Amiga (M2AMIGA compiler). The actual implementations run on UN*X workstations (e.g. IBM RS6000/AIX, HP 9000/HP-UX, NextStep, Sun Sparc with a Modula-2 to C translator) and PCs 386, 486, 586 (DOS, OS2 and Linux).

The ALDES/SAC-2 libraries have been implemented including the Polynomial Factorization System and the Real Root Isolation System. From the DIP system the Buchberger Algorithm System and the Ideal Decomposition and Ideal Real Root System have been implemented. Groebner Bases are also available for non-commutative polynomial rings of solvable type. The combination of the MAS programs with numerical Modula-2 libraries has been tested. The mathematical libraries have been enlarged by a package for linear algebra. Further new developments are syzygies, module Groebner bases, comprehensive Groebner bases, (parametric) real root counting, real quantifier elimination, involutive bases and invariant polynomials.

Some logic programming facilities have been incorporated by means of the conditional rewriting capabilities of the algebraic specification component. Further there is a parser for the ALDES language and the MAS interpreter is now able to evaluate ALDES statements (although with low performance). In the symbol table system the unbalanced symbol tree has been repaced by a hash table with balanced symbol tree entries.

The current development concentrates on filling some gaps in the ALDES / SAC-2 and DIP libraries, the design of suitable specifications for relevant algebraic structures and completing the system documentation.
Bibliography

[Appel 88]
    A. W. Appel, R. Milner, R. W. Harper, D. B. MacQueen, "Standard ML Reference Manual (preliminary draft)", University of Edinburgh, LFCS Report, 1988. 
[Collins 82]
    G.E. Collins, R. Loos, "ALDES/SAC-2 now available", SIGSAM Bulletin 1982, and several reports distributed with the ALDES/SAC-2 system. 
[Jenks 85]
    R. D. Jenks et al., "Scratchpad II Programming Language Manual", Computer Algebra Group, IBM, Yorktown Heights, NY, 1985. 
[Kredel 88]
    H. Kredel, "From SAC-2 to Modula-2", Proc. ISSAC'88 Rome, LNCS 358, pp 447-455, Springer, 1989. 
[Kredel 90]
    H. Kredel, "MAS Modula-2 Algebra System", Proc. DISCO 90 Capri, LNCS 429, pp 270-271, Springer, 1990. 
[Kredel 91]
    H. Kredel, "The MAS Specification Component", Proc. PLILP 91 Passau, LNCS 528, pp 39-50, Springer, 1991. 
[Loos 76]
    R. G. K. Loos. "The Algorithm Description Language ALDES (Report)", SIGSAM Bulletin 14/1, pp 15-39, 1976. 
[Wirsing 86]
    M. Wirsing, "Structured Algebraic Specifications: A Kernel Language", Theoretical Computer Science 42, pp 123-249, Elsevier Science Publishers B.V. (North-Holland) (1986). 
[Wirth 85]
    N. Wirth, "Programming in Modula-2", Springer, Berlin, Heidelberg, New York, 1985. 

Availability
MAS (0.3x, 0.6x, 0.7x and 1.0x) is available from: ftp://alice.fmi.uni-passau.de/pub/ComputerAlgebraSystems/mas (went offline in 2009) or from Mannheim mirror

You can get more information about MAS from: http://alice.fmi.uni-passau.de/mas.html (went offline in 2009) or from Mannheim mirror

Send bug-reports, questions, remarks to: mailto:mas@alice.fmi.uni-passau.de (offline since 2009)
Acknowledgements
Due to limited space we apologize for only global thanks to all who made contributions and influenced the project. Copyrights:

 MAS:         (c) 1989-1998, by H. Kredel, University Mannheim, 
                             M. Pesch, University Passau.
 ALDES/SAC-2: (c) 1982, by G.E.Collins, R.Loos.  

All Rights Reserved. Permission is granted for unrestricted noncommercial use and noncommercial redistribution if the copyright notice is retained when a copy is made. There are no known bugs, however we disclaim any usefulness and make no warranty on the correctness of the Modula-2 Algebra System. For certain machines and/or operating systems further copying restrictions apply, e.g. see the files

    copying.mas, copying.reuse, copying.mtc, 
    copying.emx, copying, copying.lib and copying.bsd

in the exam directory. The C code has been generated from the Modula-2 sources of MAS with the 'mtc' 'Modula-2 to C' translator by GMD Karlsruhe. Although it is not required, you should get a copy of it from some ftp site to have the sources of the used libraries. The executables for PC have been compiled using the GNU gcc compiler with the emx runtime system by Ernst Mattes. The latest versions and documentation of emx can also be found on ftp servers.

Heinz Kredel, University of Mannheim, L 15, 16, D-68131 Mannheim, Germany. Tel: +49/621/181-3171, E-mail: kredel@rz.uni-mannheim.de.


Last modification at 26. Oktober 2000. Links updated in April 2009. 
