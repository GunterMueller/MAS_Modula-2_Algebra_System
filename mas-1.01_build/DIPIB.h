#define DEFINITION_DIPIB

#ifndef DEFINITION_MASSTOR
#include "MASSTOR.h"
#endif

typedef void (*DIPIB_PROCP5V2) ARGS((MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST, MASSTOR_LIST *, MASSTOR_LIST *));
extern CHAR DIPIB_rcsid[];
extern CHAR DIPIB_copyright[];
extern MASSTOR_LIST DIPIB_ADCAN ARGS((MASSTOR_LIST P));
extern void DIPIB_ADPNFJ ARGS((MASSTOR_LIST G, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DIPNFJ ARGS((MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DIPINFJ ARGS((MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DILISJ ARGS((MASSTOR_LIST P, MASSTOR_LIST *PP, BOOLEAN *reduced));
extern void DIPIB_DIPIRLJ ARGS((MASSTOR_LIST P, MASSTOR_LIST *F, BOOLEAN *reduced));
extern MASSTOR_LIST DIPIB_DIPCOM ARGS((MASSTOR_LIST F));
extern MASSTOR_LIST DIPIB_DIPIB2 ARGS((MASSTOR_LIST F));
extern MASSTOR_LIST DIPIB_DIPIB3 ARGS((MASSTOR_LIST F));
extern void DIPIB_ADEPNFJ ARGS((MASSTOR_LIST G, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DIPENFJ ARGS((MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, BOOLEAN *c));
extern void DIPIB_DIPEINFJ ARGS((MASSTOR_LIST P, MASSTOR_LIST S, MASSTOR_LIST *R, BOOLEAN *c));
extern BOOLEAN DIPIB_IsInvolutive ARGS((MASSTOR_LIST G));
extern MASSTOR_LIST DIPIB_ADEPmark ARGS((MASSTOR_LIST g, MASSTOR_LIST G));
extern MASSTOR_LIST DIPIB_DILISJ2 ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPIB_ADEPtriple ARGS((MASSTOR_LIST PS, MASSTOR_LIST term));
extern MASSTOR_LIST DIPIB_ADEPuntriple ARGS((MASSTOR_LIST PS));
extern void DIPIB_ADEPCrumble ARGS((MASSTOR_LIST P, MASSTOR_LIST *deg, MASSTOR_LIST *pol, MASSTOR_LIST *ht));
extern MASSTOR_LIST DIPIB_ADEPCompose ARGS((MASSTOR_LIST deg, MASSTOR_LIST pol, MASSTOR_LIST ht));
extern MASSTOR_LIST DIPIB_ADEPdegree ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPIB_ADEPpolynomial ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPIB_ADEPheadterm ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPIB_ADEPleadingterm ARGS((MASSTOR_LIST P));
extern MASSTOR_LIST DIPIB_IBcrit ARGS((MASSTOR_LIST NM, MASSTOR_LIST G));
extern MASSTOR_LIST DIPIB_DIPIB ARGS((MASSTOR_LIST F));
extern void DIPIB_ADPNFJS ARGS((MASSTOR_LIST G1, MASSTOR_LIST G2, MASSTOR_LIST G3, MASSTOR_LIST G4, MASSTOR_LIST P, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DIPNFJS ARGS((MASSTOR_LIST P1, MASSTOR_LIST P2, MASSTOR_LIST P3, MASSTOR_LIST P4, MASSTOR_LIST S, MASSTOR_LIST *h, BOOLEAN *reduced));
extern void DIPIB_DIPINFJS ARGS(());
extern void DIPIB_DIPIRLJ2 ARGS((MASSTOR_LIST *P, MASSTOR_LIST *Q, BOOLEAN *reduced));
extern MASSTOR_LIST DIPIB_DIPIB4 ARGS((MASSTOR_LIST F));
extern void DIPIB_SetDIPIBopt ARGS((MASSTOR_LIST options));
extern void DIPIB_SetDIPIBTraceLevel ARGS((INTEGER level));
extern void DIPIB_SetDIPIBCancel ARGS((CARDINAL Canc));
extern void DIPIB_SetDIPIBSelect ARGS((INTEGER SEL));
extern void DIPIB_SetDIPIBISJ ARGS((INTEGER Sel));
extern void DIPIB_SetDIPIBCrit ARGS((INTEGER crit));
extern void DIPIB_SetDomainNFJ ARGS(());
extern void BEGIN_DIPIB();
