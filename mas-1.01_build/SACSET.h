#define DEFINITION_SACSET

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACSET_rcsid[];
extern CHAR SACSET_copyright[];
extern MASSTOR_LIST SACSET_LBIBMS ARGS((MASSTOR_LIST L));
extern void SACSET_LBIBS ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACSET_LBIM ARGS((MASSTOR_LIST L1, MASSTOR_LIST L2));
extern MASSTOR_LIST SACSET_SCOMP ARGS((MASSTOR_LIST AL, MASSTOR_LIST L));
extern MASSTOR_LIST SACSET_SDIFF ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACSET_SINTER ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACSET_SUNION ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACSET_USCOMP ARGS((MASSTOR_LIST AL, MASSTOR_LIST L));
extern MASSTOR_LIST SACSET_USDIFF ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACSET_USINT ARGS((MASSTOR_LIST C_5_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACSET_USUN ARGS((MASSTOR_LIST C_6_A, MASSTOR_LIST B));
extern void BEGIN_SACSET();
