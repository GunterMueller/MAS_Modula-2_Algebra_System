#define DEFINITION_DIPIDEAL

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR DIPIDEAL_rcsid[];
extern CHAR DIPIDEAL_copyright[];
extern MASSTOR_LIST DIPIDEAL_DIPLDV ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST V));
extern MASSTOR_LIST DIPIDEAL_DIRLCT ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPIDEAL_DIRLIP ARGS((MASSTOR_LIST PL, MASSTOR_LIST C_3_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPIDEAL_DIRLPI ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST P, MASSTOR_LIST VP));
extern void BEGIN_DIPIDEAL();
