#define DEFINITION_DIPADOM

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

extern CHAR DIPADOM_rcsid[];
extern CHAR DIPADOM_copyright[];
extern MASSTOR_LIST DIPADOM_DIPEXP ARGS((MASSTOR_LIST C_1_A, MASSTOR_LIST NL));
extern MASSTOR_LIST DIPADOM_DIFIP ARGS((MASSTOR_LIST C_2_A, MASSTOR_LIST D));
extern MASSTOR_LIST DIPADOM_DILRD ARGS((MASSTOR_LIST V, MASSTOR_LIST D));
extern MASSTOR_LIST DIPADOM_DILSUM ARGS((MASSTOR_LIST C_3_A));
extern void DIPADOM_DILWR ARGS((MASSTOR_LIST C_4_A, MASSTOR_LIST V));
extern MASSTOR_LIST DIPADOM_DIPBCP ARGS((MASSTOR_LIST C_5_A, MASSTOR_LIST BL));
extern MASSTOR_LIST DIPADOM_DIPDIF ARGS((MASSTOR_LIST C_6_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPADOM_DIPFAC ARGS((MASSTOR_LIST C_7_A, MASSTOR_LIST VOO));
extern void DIPADOM_DIPIRL ARGS((MASSTOR_LIST *P, BOOLEAN *CS));
extern MASSTOR_LIST DIPADOM_DIPLIR ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPADOM_DIPRLF ARGS((MASSTOR_LIST P, MASSTOR_LIST p));
extern MASSTOR_LIST DIPADOM_DIPMOC ARGS((MASSTOR_LIST C_8_A));
extern MASSTOR_LIST DIPADOM_DIPNEG ARGS((MASSTOR_LIST C_9_A));
extern MASSTOR_LIST DIPADOM_DIPNF ARGS((MASSTOR_LIST C_10_A, MASSTOR_LIST B));
extern void DIPADOM_DIPQR ARGS((MASSTOR_LIST C_11_A, MASSTOR_LIST B, MASSTOR_LIST *Q, MASSTOR_LIST *R));
extern MASSTOR_LIST DIPADOM_DIPROD ARGS((MASSTOR_LIST C_12_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPADOM_DIPS ARGS((MASSTOR_LIST C_13_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPADOM_DIPSFF ARGS((MASSTOR_LIST C_14_A, MASSTOR_LIST VOO));
extern MASSTOR_LIST DIPADOM_DIPSUM ARGS((MASSTOR_LIST C_15_A, MASSTOR_LIST B));
extern MASSTOR_LIST DIPADOM_DIREAD ARGS((MASSTOR_LIST V, MASSTOR_LIST D));
extern void DIPADOM_DIWRIT ARGS((MASSTOR_LIST C_16_A, MASSTOR_LIST V));
extern void BEGIN_DIPADOM();
