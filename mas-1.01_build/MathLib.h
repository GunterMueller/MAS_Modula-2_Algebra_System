#define DEFINITION_MathLib

extern CHAR MathLib_rcsid[];
extern CHAR MathLib_copyright[];
extern REAL MathLib_sqrt ARGS((REAL x));
extern LONGREAL MathLib_sqrtL ARGS((LONGREAL x));
extern REAL MathLib_exp ARGS((REAL x));
extern LONGREAL MathLib_expL ARGS((LONGREAL x));
extern REAL MathLib_ln ARGS((REAL x));
extern LONGREAL MathLib_lnL ARGS((LONGREAL x));
extern REAL MathLib_sin ARGS((REAL x));
extern LONGREAL MathLib_sinL ARGS((LONGREAL x));
extern REAL MathLib_cos ARGS((REAL x));
extern LONGREAL MathLib_cosL ARGS((LONGREAL x));
extern REAL MathLib_arctan ARGS((REAL x));
extern LONGREAL MathLib_arctanL ARGS((LONGREAL x));
extern REAL MathLib_real ARGS((INTEGER x));
extern LONGREAL MathLib_realL ARGS((INTEGER x));
extern INTEGER MathLib_entier ARGS((REAL x));
extern INTEGER MathLib_entierL ARGS((LONGREAL x));
extern void BEGIN_MathLib();
