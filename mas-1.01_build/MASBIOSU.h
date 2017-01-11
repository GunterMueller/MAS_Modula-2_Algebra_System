#define DEFINITION_MASBIOSU

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASBIOSU_rcsid[];
extern CHAR MASBIOSU_copyright[];
extern MASSTOR_LIST MASBIOSU_INP ARGS((MASSTOR_LIST C_1_A));
extern MASSTOR_LIST MASBIOSU_OUT ARGS((MASSTOR_LIST C_2_A));
extern MASSTOR_LIST MASBIOSU_SHUT ARGS((MASSTOR_LIST C_3_A));
extern MASSTOR_LIST MASBIOSU_EDIT ARGS((MASSTOR_LIST C_4_A));
extern MASSTOR_LIST MASBIOSU_DOS ARGS((MASSTOR_LIST C_5_A));
extern void MASBIOSU_CLTIS ARGS((MASSTOR_LIST C_6_A));
extern void BEGIN_MASBIOSU();