#define DEFINITION_MASC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASC_rcsid[];
extern CHAR MASC_copyright[];
extern MASSTOR_LIST MASC_CABS ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CCON ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CCOMP ARGS((MASSTOR_LIST R, MASSTOR_LIST S));
extern MASSTOR_LIST MASC_CDIF ARGS((MASSTOR_LIST R, MASSTOR_LIST S));
extern MASSTOR_LIST MASC_CDREAD ARGS(());
extern void MASC_CDWRITE ARGS((MASSTOR_LIST R, MASSTOR_LIST NL));
extern MASSTOR_LIST MASC_CEXP ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST NL));
extern MASSTOR_LIST MASC_CIM ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CINT ARGS((MASSTOR_LIST C_2_A));
extern MASSTOR_LIST MASC_CRE ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CRN ARGS((MASSTOR_LIST C_3_A));
extern MASSTOR_LIST MASC_CRNP ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASC_CNINV ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CNEG ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CONE ARGS((MASSTOR_LIST R));
extern MASSTOR_LIST MASC_CPROD ARGS((MASSTOR_LIST R, MASSTOR_LIST S));
extern MASSTOR_LIST MASC_CQ ARGS((MASSTOR_LIST R, MASSTOR_LIST S));
extern MASSTOR_LIST MASC_CRAND ARGS((MASSTOR_LIST NL));
extern MASSTOR_LIST MASC_CNREAD ARGS(());
extern MASSTOR_LIST MASC_CSUM ARGS((MASSTOR_LIST R, MASSTOR_LIST S));
extern void MASC_CNWRITE ARGS((MASSTOR_LIST R));
extern void BEGIN_MASC();
