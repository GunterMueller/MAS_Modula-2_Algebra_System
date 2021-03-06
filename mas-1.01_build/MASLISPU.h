#define DEFINITION_MASLISPU

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#define MASLISPU_EXPR	1
extern CHAR MASLISPU_rcsid[];
extern CHAR MASLISPU_copyright[];
typedef MASSTOR_LIST (*MASLISPU_PROCF0) ARGS(());
typedef MASSTOR_LIST (*MASLISPU_PROCF1) ARGS((MASSTOR_LIST));
typedef MASSTOR_LIST (*MASLISPU_PROCF2) ARGS((MASSTOR_LIST, MASSTOR_LIST));
typedef MASSTOR_LIST (*MASLISPU_PROCF3) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef MASSTOR_LIST (*MASLISPU_PROCF4) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef MASSTOR_LIST (*MASLISPU_PROCF5) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef void (*MASLISPU_PROCP0) ARGS(());
typedef void (*MASLISPU_PROCP1) ARGS((MASSTOR_LIST));
typedef void (*MASLISPU_PROCP2) ARGS((MASSTOR_LIST, MASSTOR_LIST));
typedef void (*MASLISPU_PROCP3) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef void (*MASLISPU_PROCP4) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef void (*MASLISPU_PROCP5) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST));
typedef void (*MASLISPU_PROCP0V1) ARGS((MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP0V2) ARGS((MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP1V1) ARGS((MASSTOR_LIST, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP1V2) ARGS((MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP1V3) ARGS((MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP2V1) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP2V2) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP2V3) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP3V1) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP3V2) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
typedef void (*MASLISPU_PROCP3V3) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *, MASSTOR_LIST *));
extern MASSTOR_LIST MASLISPU_EXTYP, MASLISPU_ARITY, MASLISPU_SUBR;
extern void MASLISPU_CallCompiled ARGS((MASSTOR_LIST F, MASSTOR_LIST PI, MASSTOR_LIST *PO, BOOLEAN *fu));
extern void MASLISPU_Compiledp0 ARGS((MASLISPU_PROCP0 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp1 ARGS((MASLISPU_PROCP1 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp2 ARGS((MASLISPU_PROCP2 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp3 ARGS((MASLISPU_PROCP3 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp4 ARGS((MASLISPU_PROCP4 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp5 ARGS((MASLISPU_PROCP5 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf0 ARGS((MASLISPU_PROCF0 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf1 ARGS((MASLISPU_PROCF1 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf2 ARGS((MASLISPU_PROCF2 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf3 ARGS((MASLISPU_PROCF3 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf4 ARGS((MASLISPU_PROCF4 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledf5 ARGS((MASLISPU_PROCF5 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp1v2 ARGS((MASLISPU_PROCP1V2 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp1v3 ARGS((MASLISPU_PROCP1V3 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp2v2 ARGS((MASLISPU_PROCP2V2 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp2v3 ARGS((MASLISPU_PROCP2V3 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp3v2 ARGS((MASLISPU_PROCP3V2 F, CHAR S[], LONGCARD ));
extern void MASLISPU_Compiledp3v3 ARGS((MASLISPU_PROCP3V3 F, CHAR S[], LONGCARD ));
extern void MASLISPU_CompSummary ARGS(());
extern void MASLISPU_Declare ARGS((MASSTOR_LIST *X, CHAR S[], LONGCARD ));
extern BOOLEAN MASLISPU_PROCP ARGS((MASSTOR_LIST X));
extern void MASLISPU_Signature ARGS((MASSTOR_LIST F, MASSTOR_LIST *PI, MASSTOR_LIST *PO, BOOLEAN *def));
extern void BEGIN_MASLISPU();
