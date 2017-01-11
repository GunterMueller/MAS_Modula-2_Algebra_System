#define DEFINITION_MASNCGB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASNCGB_rcsid[];
extern CHAR MASNCGB_copyright[];
extern MASSTOR_LIST MASNCGB_DINLNF ARGS((MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST S));
extern MASSTOR_LIST MASNCGB_DINLIS ARGS((MASSTOR_LIST T, MASSTOR_LIST P));
extern MASSTOR_LIST MASNCGB_DINLSP ARGS((MASSTOR_LIST T, MASSTOR_LIST C_1_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASNCGB_DINLGB ARGS((MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF));
extern MASSTOR_LIST MASNCGB_DINLGM ARGS((MASSTOR_LIST T, MASSTOR_LIST P));
extern MASSTOR_LIST MASNCGB_DIN1GB ARGS((MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF));
extern MASSTOR_LIST MASNCGB_DINCGB ARGS((MASSTOR_LIST T, MASSTOR_LIST P, MASSTOR_LIST TF));
extern void BEGIN_MASNCGB();