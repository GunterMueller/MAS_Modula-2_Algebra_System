#define DEFINITION_MLDEMO

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

#ifndef DEFINITION_MASLISPU
#include "MASLISPU.h"
#endif

extern CHAR MLDEMO_rcsid[];
extern CHAR MLDEMO_copyright[];
extern MASSTOR_LIST MLDEMO_EQU, MLDEMO_NEQ;
extern MASSTOR_LIST MLDEMO_MLDMKATOM ARGS((MASSTOR_LIST rel, MASSTOR_LIST left, MASSTOR_LIST right));
extern MASSTOR_LIST MLDEMO_MLDTST ARGS((MASSTOR_LIST l));
extern MASSTOR_LIST MLDEMO_MLDMKPOS ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDMKPOS1 ARGS((MASSTOR_LIST phi, MASSTOR_LIST pref));
extern MASSTOR_LIST MLDEMO_MLDMKDNF ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDMKCNF ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDMKPRENEX ARGS((MASSTOR_LIST phi, MASSTOR_LIST pref));
extern MASSTOR_LIST MLDEMO_MLDSUBSTVAR ARGS((MASSTOR_LIST phi, MASSTOR_LIST old, MASSTOR_LIST new));
extern MASSTOR_LIST MLDEMO_MLDMKVD ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDSMPL ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDPREPQE ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDAPPLYAT ARGS((MASSTOR_LIST phi));
extern void MLDEMO_MLDPPRT ARGS((MASSTOR_LIST phi));
extern void MLDEMO_MLDTEXW ARGS((MASSTOR_LIST phi));
extern MASSTOR_LIST MLDEMO_MLDCONTVAR ARGS((MASSTOR_LIST phi, MASSTOR_LIST var));
extern MASSTOR_LIST MLDEMO_MLDCONTBDVAR ARGS((MASSTOR_LIST phi, MASSTOR_LIST var));
extern MASSTOR_LIST MLDEMO_MLDPREAD ARGS(());
extern MASSTOR_LIST MLDEMO_MLDIREAD ARGS(());
extern void BEGIN_MLDEMO();
