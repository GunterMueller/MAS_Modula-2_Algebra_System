#define DEFINITION_DINNGB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR DINNGB_rcsid[];
extern CHAR DINNGB_copyright[];
extern MASSTOR_LIST DINNGB_DINNCP ARGS((MASSTOR_LIST EL, MASSTOR_LIST C_1_A, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_EVNNCP ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVNRDT ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVNCRD ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVNLDT ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVNCLD ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVLLCM ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVLRCM ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_EVRCMT ARGS((MASSTOR_LIST EL, MASSTOR_LIST S, MASSTOR_LIST T));
extern MASSTOR_LIST DINNGB_DNNLNF ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST S));
extern MASSTOR_LIST DINNGB_DNNLIS ARGS((MASSTOR_LIST EL, MASSTOR_LIST P));
extern MASSTOR_LIST DINNGB_DNNLSP ARGS((MASSTOR_LIST EL, MASSTOR_LIST C_2_A, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_DNNLGB ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF));
extern MASSTOR_LIST DINNGB_DNNRNF ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST S));
extern MASSTOR_LIST DINNGB_DNNRIS ARGS((MASSTOR_LIST EL, MASSTOR_LIST P));
extern MASSTOR_LIST DINNGB_DNNRSP ARGS((MASSTOR_LIST EL, MASSTOR_LIST C_3_A, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_DNNRGB ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF));
extern void DINNGB_DNLCPL ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B));
extern void DINNGB_DNRCPL ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST *D, MASSTOR_LIST *B));
extern MASSTOR_LIST DINNGB_DNLUPL ARGS((MASSTOR_LIST EL, MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_DNRUPL ARGS((MASSTOR_LIST EL, MASSTOR_LIST PL, MASSTOR_LIST P, MASSTOR_LIST D, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_DNN2GB ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF));
extern MASSTOR_LIST DINNGB_DNNTGB ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST TF));
extern MASSTOR_LIST DINNGB_DNNLES ARGS((MASSTOR_LIST EL, MASSTOR_LIST P));
extern MASSTOR_LIST DINNGB_DNNRES ARGS((MASSTOR_LIST EL, MASSTOR_LIST P, MASSTOR_LIST DL, MASSTOR_LIST DP));
extern MASSTOR_LIST DINNGB_DIPSPS ARGS((MASSTOR_LIST D, MASSTOR_LIST B));
extern MASSTOR_LIST DINNGB_DIPLMD ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DINNGB_IPOWER ARGS((MASSTOR_LIST EL, MASSTOR_LIST AL));
extern void BEGIN_DINNGB();