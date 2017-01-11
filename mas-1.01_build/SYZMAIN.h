#define DEFINITION_SYZMAIN

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SYZMAIN_rcsid[];
extern CHAR SYZMAIN_copyright[];
extern MASSTOR_LIST SYZMAIN_SYHC ARGS((MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern MASSTOR_LIST SYZMAIN_HEQ ARGS((MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern MASSTOR_LIST SYZMAIN_HSEQ ARGS((MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern void SYZMAIN_SYTHC ARGS((MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST VL));
extern MASSTOR_LIST SYZMAIN_SIC ARGS((MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern MASSTOR_LIST SYZMAIN_IEQ ARGS((MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern MASSTOR_LIST SYZMAIN_ISEQ ARGS((MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD));
extern void SYZMAIN_STIC ARGS((MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST VL));
extern MASSTOR_LIST SYZMAIN_SYHNL ARGS((MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern MASSTOR_LIST SYZMAIN_NLHEQ ARGS((MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern MASSTOR_LIST SYZMAIN_NLHSEQ ARGS((MASSTOR_LIST PM, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern void SYZMAIN_SYTHNL ARGS((MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST VL, MASSTOR_LIST T));
extern MASSTOR_LIST SYZMAIN_SINL ARGS((MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern MASSTOR_LIST SYZMAIN_NLIEQ ARGS((MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern MASSTOR_LIST SYZMAIN_NLISEQ ARGS((MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST SANZ, MASSTOR_LIST SRD, MASSTOR_LIST T));
extern void SYZMAIN_STINL ARGS((MASSTOR_LIST SY, MASSTOR_LIST PM, MASSTOR_LIST PL, MASSTOR_LIST VL, MASSTOR_LIST T));
extern void SYZMAIN_OREC ARGS((MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST *P3, MASSTOR_LIST *P4, MASSTOR_LIST *T));
extern void BEGIN_SYZMAIN();
