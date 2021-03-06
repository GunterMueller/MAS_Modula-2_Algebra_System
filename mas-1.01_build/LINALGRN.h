#define DEFINITION_LINALGRN

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR LINALGRN_rcsid[];
extern CHAR LINALGRN_copyright[];
extern MASSTOR_LIST LINALGRN_MDIM ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_MGET ARGS((MASSTOR_LIST M, MASSTOR_LIST k, MASSTOR_LIST l));
extern MASSTOR_LIST LINALGRN_MSET ARGS((MASSTOR_LIST M, MASSTOR_LIST k, MASSTOR_LIST l, MASSTOR_LIST x));
extern MASSTOR_LIST LINALGRN_VDELEL ARGS((MASSTOR_LIST V, MASSTOR_LIST i));
extern MASSTOR_LIST LINALGRN_MDELCOL ARGS((MASSTOR_LIST M, MASSTOR_LIST i));
extern MASSTOR_LIST LINALGRN_MMINOR ARGS((MASSTOR_LIST M, MASSTOR_LIST i, MASSTOR_LIST j));
extern MASSTOR_LIST LINALGRN_MTRANS ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_VEL ARGS((MASSTOR_LIST a, MASSTOR_LIST n));
extern MASSTOR_LIST LINALGRN_MFILL ARGS((MASSTOR_LIST M, MASSTOR_LIST m, MASSTOR_LIST n));
extern MASSTOR_LIST LINALGRN_MRANG ARGS((MASSTOR_LIST U));
extern MASSTOR_LIST LINALGRN_RNMHILBERT ARGS((MASSTOR_LIST m, MASSTOR_LIST n));
extern MASSTOR_LIST LINALGRN_RNUM ARGS((MASSTOR_LIST m, MASSTOR_LIST n));
extern void LINALGRN_RNVWRITE ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST s));
extern MASSTOR_LIST LINALGRN_RNVREAD ARGS(());
extern void LINALGRN_RNMWRITE ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST s));
extern MASSTOR_LIST LINALGRN_RNMREAD ARGS(());
extern MASSTOR_LIST LINALGRN_RNVFIV ARGS((MASSTOR_LIST C_3_A));
extern MASSTOR_LIST LINALGRN_RNMFIM ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_RNVDIF ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVQ ARGS((MASSTOR_LIST C_5_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVQF ARGS((MASSTOR_LIST C_6_A));
extern MASSTOR_LIST LINALGRN_RNVVSUM ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVSVSUM ARGS((MASSTOR_LIST C_8_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVSSUM ARGS((MASSTOR_LIST C_9_A));
extern MASSTOR_LIST LINALGRN_RNVSVPROD ARGS((MASSTOR_LIST C_10_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVVPROD ARGS((MASSTOR_LIST C_11_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVSPROD ARGS((MASSTOR_LIST C_12_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNVMAX ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_RNVLC ARGS((MASSTOR_LIST a, MASSTOR_LIST C_13_A, MASSTOR_LIST b, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNSVPROD ARGS((MASSTOR_LIST a, MASSTOR_LIST C_14_A));
extern MASSTOR_LIST LINALGRN_RNMSUM ARGS((MASSTOR_LIST C_15_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNMDIF ARGS((MASSTOR_LIST C_16_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNMPROD ARGS((MASSTOR_LIST C_17_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNSMPROD ARGS((MASSTOR_LIST C_18_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGRN_RNMMAX ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_RNMGE ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_RNMDET ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGRN_RNMDETL ARGS((MASSTOR_LIST M));
extern void LINALGRN_RNMGELUD ARGS((MASSTOR_LIST M, MASSTOR_LIST *L, MASSTOR_LIST *U));
extern MASSTOR_LIST LINALGRN_RNMLT ARGS((MASSTOR_LIST L, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGRN_RNMUT ARGS((MASSTOR_LIST U, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGRN_RNMSDS ARGS((MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGRN_RNMINV ARGS((MASSTOR_LIST C_19_A));
extern MASSTOR_LIST LINALGRN_RNMUNS ARGS((MASSTOR_LIST U));
extern void BEGIN_LINALGRN();
