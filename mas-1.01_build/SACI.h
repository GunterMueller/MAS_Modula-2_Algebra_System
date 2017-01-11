#define DEFINITION_SACI

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR SACI_rcsid[];
extern CHAR SACI_copyright[];
extern void SACI_AADV ARGS((MASSTOR_LIST L, MASSTOR_LIST *AL, MASSTOR_LIST *LP));
extern MASSTOR_LIST SACI_IABSF ARGS((MASSTOR_LIST C_1_A));
extern MASSTOR_LIST SACI_ICOMP ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST B));
extern void SACI_IDEGCD ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *UL1, MASSTOR_LIST *VL1, MASSTOR_LIST *UL2, MASSTOR_LIST *VL2));
extern MASSTOR_LIST SACI_IDIF ARGS((MASSTOR_LIST C_3_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACI_IDIPR2 ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST B, MASSTOR_LIST AL, MASSTOR_LIST BL));
extern MASSTOR_LIST SACI_IDPR ARGS((MASSTOR_LIST C_5_A, MASSTOR_LIST BL));
extern MASSTOR_LIST SACI_IDP2 ARGS((MASSTOR_LIST C_6_A, MASSTOR_LIST KL));
extern MASSTOR_LIST SACI_IDQ ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST BL));
extern void SACI_IDQR ARGS((MASSTOR_LIST C_8_A, MASSTOR_LIST BL, MASSTOR_LIST *Q, MASSTOR_LIST *RL));
extern MASSTOR_LIST SACI_IDREM ARGS((MASSTOR_LIST C_9_A, MASSTOR_LIST BL));
extern void SACI_IEGCD ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL, MASSTOR_LIST *CL, MASSTOR_LIST *UL1, MASSTOR_LIST *VL1));
extern BOOLEAN SACI_IEVEN ARGS((MASSTOR_LIST C_10_A));
extern MASSTOR_LIST SACI_IEXP ARGS((MASSTOR_LIST C_11_A, MASSTOR_LIST NL));
extern void SACI_IFCL2 ARGS((MASSTOR_LIST AL, MASSTOR_LIST *ML, MASSTOR_LIST *NL));
extern MASSTOR_LIST SACI_IGCD ARGS((MASSTOR_LIST C_12_A, MASSTOR_LIST B));
extern void SACI_IGCDCF ARGS((MASSTOR_LIST C_13_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *AB, MASSTOR_LIST *BB));
extern void SACI_IHEGCD ARGS((MASSTOR_LIST C_14_A, MASSTOR_LIST B, MASSTOR_LIST *C, MASSTOR_LIST *V));
extern MASSTOR_LIST SACI_ILCM ARGS((MASSTOR_LIST C_15_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACI_ILCOMB ARGS((MASSTOR_LIST C_16_A, MASSTOR_LIST B, MASSTOR_LIST UL, MASSTOR_LIST VL));
extern MASSTOR_LIST SACI_ILOG2 ARGS((MASSTOR_LIST C_17_A));
extern void SACI_ILWRIT ARGS((MASSTOR_LIST L));
extern MASSTOR_LIST SACI_IMAX ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL));
extern MASSTOR_LIST SACI_IMIN ARGS((MASSTOR_LIST AL, MASSTOR_LIST BL));
extern MASSTOR_LIST SACI_IMP2 ARGS((MASSTOR_LIST C_18_A, MASSTOR_LIST HL));
extern MASSTOR_LIST SACI_INEG ARGS((MASSTOR_LIST C_19_A));
extern BOOLEAN SACI_IODD ARGS((MASSTOR_LIST C_20_A));
extern MASSTOR_LIST SACI_IORD2 ARGS((MASSTOR_LIST AL));
extern void SACI_IPOWER ARGS((MASSTOR_LIST C_21_A, MASSTOR_LIST L, MASSTOR_LIST *B, MASSTOR_LIST *NL));
extern MASSTOR_LIST SACI_IPROD ARGS((MASSTOR_LIST C_22_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACI_IPRODK ARGS((MASSTOR_LIST C_23_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACI_IQ ARGS((MASSTOR_LIST C_24_A, MASSTOR_LIST B));
extern void SACI_IQR ARGS((MASSTOR_LIST C_25_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R));
extern MASSTOR_LIST SACI_IRAND ARGS((MASSTOR_LIST NL));
extern MASSTOR_LIST SACI_IREAD ARGS(());
extern MASSTOR_LIST SACI_IREM ARGS((MASSTOR_LIST C_26_A, MASSTOR_LIST B));
extern void SACI_IROOT ARGS((MASSTOR_LIST C_27_A, MASSTOR_LIST NL, MASSTOR_LIST *B, MASSTOR_LIST *TL));
extern void SACI_ISEG ARGS((MASSTOR_LIST C_28_A, MASSTOR_LIST NL, MASSTOR_LIST *A1, MASSTOR_LIST *A0));
extern MASSTOR_LIST SACI_ISIGNF ARGS((MASSTOR_LIST C_29_A));
extern void SACI_ISQRT ARGS((MASSTOR_LIST C_30_A, MASSTOR_LIST *B, MASSTOR_LIST *TL));
extern MASSTOR_LIST SACI_ISSUM ARGS((MASSTOR_LIST NL, MASSTOR_LIST L));
extern MASSTOR_LIST SACI_ISUM ARGS((MASSTOR_LIST C_31_A, MASSTOR_LIST B));
extern MASSTOR_LIST SACI_ITRUNC ARGS((MASSTOR_LIST C_32_A, MASSTOR_LIST NL));
extern void SACI_IWRITE ARGS((MASSTOR_LIST C_33_A));
extern void BEGIN_SACI();
