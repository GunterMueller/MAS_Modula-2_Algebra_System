#define DEFINITION_MASAPF

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASAPF_rcsid[];
extern CHAR MASAPF_copyright[];
extern MASSTOR_LIST MASAPF_APCOMP ARGS((MASSTOR_LIST ML, MASSTOR_LIST EL));
extern MASSTOR_LIST MASAPF_APMANT ARGS((MASSTOR_LIST C_1_A));
extern MASSTOR_LIST MASAPF_APEXPT ARGS((MASSTOR_LIST C_2_A));
extern MASSTOR_LIST MASAPF_ILOG10 ARGS((MASSTOR_LIST N));
extern void MASAPF_APSPRE ARGS((MASSTOR_LIST N));
extern MASSTOR_LIST MASAPF_APFINT ARGS((MASSTOR_LIST N));
extern MASSTOR_LIST MASAPF_APSHFT ARGS((MASSTOR_LIST B, MASSTOR_LIST EL));
extern MASSTOR_LIST MASAPF_APSIGN ARGS((MASSTOR_LIST C_3_A));
extern void MASAPF_APWRIT ARGS((MASSTOR_LIST C_4_A));
extern MASSTOR_LIST MASAPF_APNEG ARGS((MASSTOR_LIST C_5_A));
extern MASSTOR_LIST MASAPF_APABS ARGS((MASSTOR_LIST C_6_A));
extern MASSTOR_LIST MASAPF_APCMPR ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APNELD ARGS((MASSTOR_LIST C_8_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APPROD ARGS((MASSTOR_LIST C_9_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APQ ARGS((MASSTOR_LIST C_10_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APSUM ARGS((MASSTOR_LIST C_11_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APDIFF ARGS((MASSTOR_LIST C_12_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASAPF_APLG10 ARGS((MASSTOR_LIST C_13_A));
extern MASSTOR_LIST MASAPF_APEXP ARGS((MASSTOR_LIST C_14_A, MASSTOR_LIST NL));
extern MASSTOR_LIST MASAPF_APFRN ARGS((MASSTOR_LIST C_15_A));
extern MASSTOR_LIST MASAPF_RNFAP ARGS((MASSTOR_LIST C_16_A));
extern MASSTOR_LIST MASAPF_RNDRD ARGS(());
extern MASSTOR_LIST MASAPF_APROOT ARGS((MASSTOR_LIST C_17_A, MASSTOR_LIST NL));
extern MASSTOR_LIST MASAPF_APPI ARGS(());
extern void BEGIN_MASAPF();
