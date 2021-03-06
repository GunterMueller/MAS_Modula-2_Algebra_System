#define DEFINITION_LINALGI

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR LINALGI_rcsid[];
extern CHAR LINALGI_copyright[];
extern MASSTOR_LIST LINALGI_IUM ARGS((MASSTOR_LIST m, MASSTOR_LIST n));
extern void LINALGI_IVWRITE ARGS((MASSTOR_LIST C_1_A));
extern void LINALGI_IMWRITE ARGS((MASSTOR_LIST C_2_A));
extern MASSTOR_LIST LINALGI_IVVDIF ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IKM ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVVSUM ARGS((MASSTOR_LIST C_5_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVSVSUM ARGS((MASSTOR_LIST C_6_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVSSUM ARGS((MASSTOR_LIST C_7_A));
extern MASSTOR_LIST LINALGI_IVSVPROD ARGS((MASSTOR_LIST C_8_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVVPROD ARGS((MASSTOR_LIST C_9_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVSPROD ARGS((MASSTOR_LIST C_10_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVMAX ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGI_IVLC ARGS((MASSTOR_LIST a, MASSTOR_LIST C_11_A, MASSTOR_LIST b, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IVSQ ARGS((MASSTOR_LIST a, MASSTOR_LIST C_12_A));
extern MASSTOR_LIST LINALGI_IVFRNV ARGS((MASSTOR_LIST C_13_A));
extern void LINALGI_IVFRNV1 ARGS((MASSTOR_LIST C_14_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D));
extern MASSTOR_LIST LINALGI_IMPROD ARGS((MASSTOR_LIST C_15_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IMSUM ARGS((MASSTOR_LIST C_16_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IMDIF ARGS((MASSTOR_LIST C_17_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_ISMPROD ARGS((MASSTOR_LIST C_18_A, MASSTOR_LIST B));
extern MASSTOR_LIST LINALGI_IMMAX ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGI_IMFRNM ARGS((MASSTOR_LIST C_19_A));
extern void LINALGI_IMFRNM1 ARGS((MASSTOR_LIST C_20_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *D));
extern void LINALGI_IMGELUD ARGS((MASSTOR_LIST M, MASSTOR_LIST *L, MASSTOR_LIST *U));
extern MASSTOR_LIST LINALGI_IMLT ARGS((MASSTOR_LIST L, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGI_IMUT ARGS((MASSTOR_LIST U, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGI_IMGE ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGI_IMSDS ARGS((MASSTOR_LIST L, MASSTOR_LIST U, MASSTOR_LIST b));
extern MASSTOR_LIST LINALGI_RNMINVI ARGS((MASSTOR_LIST C_21_A));
extern MASSTOR_LIST LINALGI_IMUNS ARGS((MASSTOR_LIST U));
extern MASSTOR_LIST LINALGI_IMDETL ARGS((MASSTOR_LIST M));
extern MASSTOR_LIST LINALGI_IMDET ARGS((MASSTOR_LIST M));
extern void BEGIN_LINALGI();
