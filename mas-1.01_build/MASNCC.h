#define DEFINITION_MASNCC

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR MASNCC_rcsid[];
extern CHAR MASNCC_copyright[];
extern MASSTOR_LIST MASNCC_DINCCO ARGS((MASSTOR_LIST T, MASSTOR_LIST C_1_A, MASSTOR_LIST B));
extern MASSTOR_LIST MASNCC_DINCCP ARGS((MASSTOR_LIST T, MASSTOR_LIST E));
extern MASSTOR_LIST MASNCC_DINCCPpre ARGS((MASSTOR_LIST T, MASSTOR_LIST E));
extern MASSTOR_LIST MASNCC_DILFEL ARGS((MASSTOR_LIST a, MASSTOR_LIST E));
extern BOOLEAN MASNCC_DINPTslT ARGS((MASSTOR_LIST T));
extern MASSTOR_LIST MASNCC_DINLMPG ARGS((MASSTOR_LIST T, MASSTOR_LIST i, MASSTOR_LIST F));
extern MASSTOR_LIST MASNCC_DINLMPL ARGS((MASSTOR_LIST T, MASSTOR_LIST F));
extern MASSTOR_LIST MASNCC_EVGCD ARGS((MASSTOR_LIST U, MASSTOR_LIST V));
extern MASSTOR_LIST MASNCC_EVLGTD ARGS((MASSTOR_LIST r, MASSTOR_LIST d, MASSTOR_LIST L));
extern MASSTOR_LIST MASNCC_EVLGIL ARGS((MASSTOR_LIST D));
extern MASSTOR_LIST MASNCC_EVLINV ARGS((MASSTOR_LIST L, MASSTOR_LIST i, MASSTOR_LIST k));
extern BOOLEAN MASNCC_EVTSZ ARGS((MASSTOR_LIST i, MASSTOR_LIST U));
extern MASSTOR_LIST MASNCC_EVINV ARGS((MASSTOR_LIST U, MASSTOR_LIST i, MASSTOR_LIST k));
extern void BEGIN_MASNCC();
