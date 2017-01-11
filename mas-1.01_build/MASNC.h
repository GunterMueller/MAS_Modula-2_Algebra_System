#define DEFINITION_MASNC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASNC_rcsid[];
extern CHAR MASNC_copyright[];
extern MASSTOR_LIST MASNC_DINPPR ARGS((MASSTOR_LIST T, MASSTOR_LIST C_1_A, MASSTOR_LIST B));
extern void MASNC_DINPTL ARGS((MASSTOR_LIST T, MASSTOR_LIST EL, MASSTOR_LIST FL, MASSTOR_LIST *C, MASSTOR_LIST *EP, MASSTOR_LIST *FP));
extern void MASNC_DINPTU ARGS((MASSTOR_LIST T, MASSTOR_LIST EL, MASSTOR_LIST FL, MASSTOR_LIST C));
extern MASSTOR_LIST MASNC_DINPEX ARGS((MASSTOR_LIST T, MASSTOR_LIST C_2_A, MASSTOR_LIST NL));
extern MASSTOR_LIST MASNC_DINLRD ARGS((MASSTOR_LIST V, MASSTOR_LIST T));
extern MASSTOR_LIST MASNC_DINPRD ARGS((MASSTOR_LIST V, MASSTOR_LIST T));
extern MASSTOR_LIST MASNC_EVZERO ARGS((MASSTOR_LIST RL));
extern void BEGIN_MASNC();
