
#include "mpNumC_Short.h"

typedef void* FlintRandPtr;
typedef void* FmpzPtr;
typedef void* FmpqPtr;
typedef void* ArfPtr;
typedef void* ArbPtr;
typedef void* AcfPtr;
typedef void* AcbPtr;

typedef void* FmpzMatPtr;
typedef void* FmpqMatPtr;
typedef void* ArbMatPtr;
typedef void* AcbMatPtr;

#ifdef __cplusplus
extern "C"
{
#endif

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Rand_Init(FlintRandPtr* state);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Rand_Clear(FlintRandPtr state);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_RandM(FmpzPtr f, FlintRandPtr state, FmpzPtr m);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Printf(const char * Title);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Print(FmpzPtr xPtr);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Init(FmpzPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Clear(FmpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set(FmpzPtr res, FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Ui(FmpzPtr x, uint32_t u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Si(FmpzPtr x, int32_t u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Ui64(MpfcPtr x, uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Si64(MpfcPtr x, int64_t sint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_D(FmpzPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpz_Set_Str(FmpzPtr x, const char * str , int32_t b);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Fmpz_Get_Ui(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpz_Get_Si(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t   __cdecl Lib_Fmpz_Get_Ui64(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Fmpz_Get_Si64(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Fmpz_Get_D(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint32_t Lib_Fmpz_SizeInBase(FmpzPtr x, int32_t base);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Fmpz_Get_Str(char * str , int32_t b, FmpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpz_Cmp(FmpzPtr f, FmpzPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Neg(FmpzPtr f, FmpzPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add_Ui(FmpzPtr f, FmpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add_Si(FmpzPtr f, FmpzPtr g,  int32_t si);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add_Ui64(FmpzPtr f, FmpzPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add_Si64(FmpzPtr f, FmpzPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub(FmpzPtr res, FmpzPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Ui_Sub(FmpzPtr res,  uint32_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub_Ui(FmpzPtr res, FmpzPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Si_Sub(FmpzPtr res, int32_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub_Si(FmpzPtr res, FmpzPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Ui64_Sub(FmpzPtr res, uint64_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub_Ui64(FmpzPtr res, FmpzPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Si64_Sub(FmpzPtr res, int64_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub_Si64(FmpzPtr res, FmpzPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Ui(FmpzPtr f, FmpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Si(FmpzPtr f, FmpzPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Ui64(FmpzPtr f, FmpzPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Si64(FmpzPtr f, FmpzPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Ui_Tdiv_Q(FmpzPtr res,  uint32_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Ui(FmpzPtr res, FmpzPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Si_Tdiv_Q(FmpzPtr res,  int32_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Si(FmpzPtr res, FmpzPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Ui64_Tdiv_Q(FmpzPtr res, uint64_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Ui64(FmpzPtr res, FmpzPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Si64_Tdiv_Q(FmpzPtr res, int64_t x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Si64(FmpzPtr res, FmpzPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_2exp(FmpzPtr f, FmpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_2exp(FmpzPtr f, FmpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mod(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Pow_Ui(FmpzPtr f, FmpzPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Complement(FmpzPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_And(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_OR(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_XOR(FmpzPtr x, FmpzPtr y, FmpzPtr z);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Print_Pretty(FmpzMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Init(FmpzMatPtr* A, int32_t i, int32_t j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Clear(FmpzMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Mul(FmpzMatPtr X, FmpzMatPtr Y, FmpzMatPtr Z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Set_Ui(FmpzMatPtr A, int32_t i, int32_t j, int32_t u);







 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Print(FmpqPtr xPtr);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Init(FmpqPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Clear(FmpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set(FmpqPtr res, FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui(FmpqPtr x, uint32_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si(FmpqPtr x, int32_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui64(FmpqPtr x, uint64_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si64(FmpqPtr x, int64_t p);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui_Ui(FmpqPtr x, uint32_t p, uint32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui_Si(FmpqPtr x, uint32_t p, int32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si_Ui(FmpqPtr x, int32_t p, uint32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si_Si(FmpqPtr x, int32_t p, int32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui64_Ui64(FmpqPtr x, uint64_t p, uint64_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Ui64_Si64(FmpqPtr x, uint64_t  p, int64_t  q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si64_Ui64(FmpqPtr x, int64_t  p, uint64_t  q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si64_Si64(FmpqPtr x, int64_t  p, int64_t  q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Fmpz_Frac(FmpqPtr x, FmpzPtr p, FmpzPtr q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Fmpz(FmpqPtr x, FmpzPtr p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Num(FmpqPtr x, FmpzPtr p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Den(FmpqPtr x, FmpzPtr p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_D(FmpqPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpq_Set_Str(FmpqPtr x, const char * str , int32_t b);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Fmpq_Get_Ui(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpq_Get_Si(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t   __cdecl Lib_Fmpq_Get_Ui64(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Fmpq_Get_Si64(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Fmpq_Get_D(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Get_Fmpz(FmpzPtr res, FmpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Get_Num(FmpzPtr res, FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Get_Den(FmpzPtr res, FmpqPtr x);


 MPNUMC_DLL_IMPORTEXPORT uint32_t Lib_Fmpq_SizeInBase(FmpqPtr x, int32_t base);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Fmpq_Get_Str(char * str , int32_t b, FmpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpq_Cmp(FmpqPtr f, FmpqPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Neg(FmpqPtr f, FmpqPtr g);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Add(FmpqPtr x, FmpqPtr y, FmpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Add_Ui(FmpqPtr f, FmpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Add_Si(FmpqPtr f, FmpqPtr g,  int32_t si);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Add_Ui64(FmpqPtr f, FmpqPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Add_Si64(FmpqPtr f, FmpqPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Sub(FmpqPtr res, FmpqPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Ui_Sub(FmpqPtr res,  uint32_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Sub_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Si_Sub(FmpqPtr res, int32_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Sub_Si(FmpqPtr res, FmpqPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Ui64_Sub(FmpqPtr res, uint64_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Sub_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Si64_Sub(FmpqPtr res, int64_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Sub_Si64(FmpqPtr res, FmpqPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul(FmpqPtr x, FmpqPtr y, FmpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul_Ui(FmpqPtr f, FmpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul_Si(FmpqPtr f, FmpqPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul_Ui64(FmpqPtr f, FmpqPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul_Si64(FmpqPtr f, FmpqPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div(FmpqPtr x, FmpqPtr y, FmpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Ui_Div(FmpqPtr res,  uint32_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Si_Div(FmpqPtr res,  int32_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div_Si(FmpqPtr res, FmpqPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Ui64_Div(FmpqPtr res, uint64_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Si64_Div(FmpqPtr res, int64_t x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div_Si64(FmpqPtr res, FmpqPtr x,  int64_t y);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul_2exp(FmpqPtr f, FmpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Div_2exp(FmpqPtr f, FmpqPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fmpq_Mod_Fmpz( FmpqPtr f, FmpqPtr g, FmpzPtr h);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Pow_Si(FmpqPtr f, FmpqPtr g,  int32_t e);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Print_Pretty(FmpqMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Init(FmpqMatPtr* A, int32_t i, int32_t j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Clear(FmpqMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Mul(FmpqMatPtr X, FmpqMatPtr Y, FmpqMatPtr Z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Set_Si(FmpqMatPtr A, int32_t i, int32_t j, int32_t p, int32_t q);






 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Printd(ArbPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Init(ArbPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Clear(ArbPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Const_Pi(ArbPtr x, int32_t a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Set_Si(ArbPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Set_Ui(ArbPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Set_D(ArbPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arb_Set_Str(ArbPtr x, const char * str , int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Set_Mpfr(ArbPtr x, MpfrPtr a);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Arb_Get_Ui(ArbPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arb_Get_Si(ArbPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Arb_Get_D(ArbPtr x);


 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Arb_SizeInBase10(ArbPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Arb_Get_Str(char * dest , ArbPtr x, int32_t digits, uint32_t flags);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arb_Cmp(ArbPtr f, ArbPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Neg(ArbPtr f, ArbPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Add(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Add_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Sub(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Sub_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mul(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mul_Si(ArbPtr f, ArbPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mul_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Div(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Div_Si(ArbPtr f, ArbPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Div_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Div_Fmpz(ArbPtr f, ArbPtr g,  FmpzPtr z, int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mul_2exp(ArbPtr f, ArbPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Div_2exp(ArbPtr f, ArbPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Pow(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Pow_Si(ArbPtr f, ArbPtr g,  int32_t e, int32_t prec);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Print_Pretty(ArbMatPtr A, int32_t digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Init(ArbMatPtr* A, int32_t i, int32_t j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Clear(ArbMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Mul(ArbMatPtr X, ArbMatPtr Y, ArbMatPtr Z, int32_t digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Set_Ui(ArbMatPtr A, int32_t i, int32_t j, int32_t u);





 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Printd(AcbPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Init(AcbPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Clear(AcbPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Const_Pi(AcbPtr x, int32_t a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_Si(AcbPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_Ui(AcbPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_D(AcbPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_Mpfr(AcbPtr x, MpfrPtr a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_Arb(AcbPtr x, ArbPtr a);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acb_Set_Real_Str(AcbPtr x, const char * str , int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acb_Set_Imag_Str(AcbPtr x, const char * str , int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Acb_Real_SizeInBase10(AcbPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Acb_Get_Real_Str(char * dest , AcbPtr x, int32_t digits, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Acb_Imag_SizeInBase10(AcbPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Acb_Get_Imag_Str(char * dest , AcbPtr x, int32_t digits, uint32_t flags);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acb_Eq(AcbPtr f, AcbPtr g);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acb_Ne(AcbPtr f, AcbPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Neg(AcbPtr f, AcbPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Add(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Add_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Sub(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Sub_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mul(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mul_Si(AcbPtr f, AcbPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mul_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Div(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Div_Si(AcbPtr f, AcbPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Div_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Div_Fmpz(AcbPtr f, AcbPtr g,  FmpzPtr z, int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mul_2exp(AcbPtr f, AcbPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Div_2exp(AcbPtr f, AcbPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Pow(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Pow_Si(AcbPtr f, AcbPtr g,  int32_t e, int32_t prec);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Print_Pretty(AcbMatPtr A, int32_t digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Init(AcbMatPtr* A, int32_t i, int32_t j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Clear(AcbMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Mul(AcbMatPtr X, AcbMatPtr Y, AcbMatPtr Z, int32_t digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Set_Ui(AcbMatPtr A, int32_t i, int32_t j, int32_t u);



//************************************************************************************************
//***************Compatibility**************************************************************



 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Fmpz(MpfrPtr x, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Fmpq(MpfrPtr x, FmpqPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpz( FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpq( FmpqPtr q, MpfrPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpz_2exp( FmpzPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Fmpz(MpfrPtr x, MpfrPtr y, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Fmpq(MpfrPtr x, MpfrPtr y, FmpqPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpz_Sub(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpq_Sub(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Fmpz(MpfrPtr x, MpfrPtr y, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Fmpq(MpfrPtr x, MpfrPtr y, FmpqPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpz_Div(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpq_Div(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Z ( MpfrPtr f, MpfrPtr g, FmpzPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpz(MpfcPtr res, FmpzPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpq(MpfcPtr res, FmpqPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpz_Fmpz(MpfcPtr res, FmpzPtr x1, FmpzPtr x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpq_Fmpq(MpfcPtr res, FmpqPtr x1, FmpqPtr x2, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpz_Sub(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpq_Sub(MpfcPtr res, FmpqPtr x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpz_Div(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpq_Div(MpfcPtr res, FmpqPtr x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpz(MpfrPtr res, FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpq(MpfrPtr res, FmpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpz_Fmpz(MpfrPtr res, FmpzPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpq_Fmpq(MpfrPtr res, FmpqPtr x, FmpqPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Fmpz(FmpzPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Fmpq(FmpqPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpz_Sub(MpfiPtr res, FmpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpq_Sub(MpfiPtr res, FmpqPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpz_Div(MpfiPtr res, FmpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpq_Div(MpfiPtr res, FmpqPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Fmpq(MpfiPtr x, FmpqPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Fmpq(MpfiPtr x, FmpqPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Fmpq(MpfiPtr x, FmpqPtr y);







#ifdef __cplusplus
}
#endif


