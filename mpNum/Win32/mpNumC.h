#ifndef MPNUMC_H_INCLUDED
#define MPNUMC_H_INCLUDED

#include <stdint.h>

typedef void* FlintRandPtr;
typedef void* GmpRandPtr;
typedef void* FmpzPtr;
typedef void* FmpqPtr;
typedef void* MpdPtr;
typedef void* MpdcPtr;
typedef void* MpfrPtr;
typedef void* MpfcPtr;
typedef void* MpfiPtr;

typedef void* MpfciPtr;
typedef void* ArfPtr;
typedef void* ArbPtr;
typedef void* AcfPtr;
typedef void* AcbPtr;

typedef void* FmpzMatPtr;
typedef void* FmpqMatPtr;
typedef void* ArbMatPtr;
typedef void* AcbMatPtr;


#define MPNUMC_DLL_IMPORTEXPORT

#if defined (BUILD_MPNUMC_DLL)
  #undef MPNUMC_DLL_IMPORTEXPORT
  #define MPNUMC_DLL_IMPORTEXPORT __declspec( dllexport )
#elif defined (USE_MPNUMC_DLL)
  #undef MPNUMC_DLL_IMPORTEXPORT
  #define MPNUMC_DLL_IMPORTEXPORT __declspec( dllimport )
#endif


#ifdef __cplusplus
extern "C"
{
#endif

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Gmp_Rand_Init(GmpRandPtr* state);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Gmp_Rand_Clear(GmpRandPtr state);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Rand_Init(FlintRandPtr* state);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Rand_Clear(FlintRandPtr state);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_RandM(FmpzPtr f, FlintRandPtr state, FmpzPtr m);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Urandomb(MpfrPtr res, FlintRandPtr state);


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







 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Default_Prec (int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Default_Prec (void);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Default_Rounding_Mode (int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Default_Rounding_Mode (void);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Init(MpfrPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Clear(MpfrPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Prec(MpfrPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Prec(MpfrPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set(MpfrPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Ui(MpfrPtr x, uint32_t a, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Si(MpfrPtr x, int32_t a, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Ui64(MpfrPtr x, uint64_t uint64, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Si64(MpfrPtr x, int64_t sint64, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Ui64a(MpfrPtr x, uint64_t uint64, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Si64a(MpfrPtr x, int64_t sint64, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Flt(MpfrPtr x, float d, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_D(MpfrPtr x, double u, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Ld(MpfrPtr x, long double d, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Fmpz(MpfrPtr x, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Fmpq(MpfrPtr x, FmpqPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Str(MpfrPtr x, const char * str , int32_t base, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Nan(MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Inf(MpfrPtr x, int32_t sign);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Set_Zero(MpfrPtr x, int32_t sign);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Swap(MpfrPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Mpfr_Get_Ui(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Si(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT uint64_t  __cdecl Lib_Mpfr_Get_Ui64(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Mpfr_Get_Si64(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT float  __cdecl Lib_Mpfr_Get_Flt(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpfr_Get_D(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT long double  __cdecl Lib_Mpfr_Get_Ld(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpz( FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpq( FmpqPtr q, MpfrPtr y, int32_t rnd);

// The next 3 need to change
// MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpfr_Get_D_2exp(int32_t *exp, MpfrPtr x, int32_t rnd);
// MPNUMC_DLL_IMPORTEXPORT long double  __cdecl Lib_Mpfr_Get_Ld_2exp(int32_t *exp, MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Frexp(int32_t *exp, MpfrPtr y, MpfrPtr x, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Fmpz_2exp( FmpzPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Print( const char *template1, MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_SnPrintf_SizeInBase10(const char *template1, MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfrPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Cmp(MpfrPtr f, MpfrPtr g);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Neg(MpfrPtr f, MpfrPtr g, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Ui64(MpfrPtr f, MpfrPtr g, uint64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Si64(MpfrPtr f, MpfrPtr g, int64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Fmpz(MpfrPtr x, MpfrPtr y, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Fmpq(MpfrPtr x, MpfrPtr y, FmpqPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui_Sub(MpfrPtr f, uint32_t x,  MpfrPtr g, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Si_Sub(MpfrPtr f,  int32_t x, MpfrPtr g,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Ui64(MpfrPtr res, MpfrPtr x, uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui64_Sub(MpfrPtr res, uint64_t x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Si64(MpfrPtr res, MpfrPtr x, int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Si64_Sub(MpfrPtr res, int64_t x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_D_Sub(MpfrPtr f,  double x, MpfrPtr g,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpz_Sub(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpq_Sub(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Si(MpfrPtr f, MpfrPtr g, int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Ui64(MpfrPtr f, MpfrPtr g, uint64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Si64(MpfrPtr f, MpfrPtr g, int64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Fmpz(MpfrPtr x, MpfrPtr y, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Fmpq(MpfrPtr x, MpfrPtr y, FmpqPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui_Div(MpfrPtr f, uint32_t x,  MpfrPtr g, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Si_Div(MpfrPtr f,  int32_t x, MpfrPtr g,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Si(MpfrPtr f, MpfrPtr g, int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Ui64(MpfrPtr res, MpfrPtr x, uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui64_Div(MpfrPtr res, uint64_t x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Si64(MpfrPtr res, MpfrPtr x, int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Si64_Div(MpfrPtr res, int64_t x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_D_Div(MpfrPtr f,  double x, MpfrPtr g,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpz_Div(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmpq_Div(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd);



 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Ui ( MpfrPtr f, MpfrPtr g,uint32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Si(MpfrPtr f, MpfrPtr g,  int32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Z ( MpfrPtr f, MpfrPtr g, FmpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui_Pow_Ui ( MpfrPtr f, uint32_t  g, uint32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ui_Pow ( MpfrPtr f, uint32_t e, MpfrPtr g, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_2si(MpfrPtr f, MpfrPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_2ui(MpfrPtr f, MpfrPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_2si(MpfrPtr f, MpfrPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_2ui(MpfrPtr f, MpfrPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Const_Log2(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Const_Pi(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Const_Euler(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Const_Catalan(MpfrPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sqr(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sqrt(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rec_Sqrt(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Cbrt(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Abs(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Log(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Log2(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Log10(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Exp(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Exp2(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Exp10(MpfrPtr x, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Cos(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sin(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Tan(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sec(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Csc(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Cot(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Acos(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Asin(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Atan(MpfrPtr x, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Cosh(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sinh(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Tanh(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sech(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Csch(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Coth(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Acosh(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Asinh(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Atanh(MpfrPtr x, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Log1p(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Expm1(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Eint(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Li2(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Gamma(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Lngamma(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Digamma(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Zeta(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Erf(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Erfc(MpfrPtr x, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_J0(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_J1(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Y0(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Y1(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ai(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rint(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rint_Ceil(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rint_Floor(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rint_Round(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Rint_Trunc(MpfrPtr x, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Frac(MpfrPtr x, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Ceil(MpfrPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Floor(MpfrPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Round(MpfrPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Trunc(MpfrPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sqrt_Ui(MpfrPtr x, uint32_t n,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fac_Ui(MpfrPtr x, uint32_t n,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Zeta_Ui(MpfrPtr x, uint32_t n,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Dim(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sin_Cos(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Atan2(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sinh_Cosh(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Agm(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Hypot(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Modf(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fmod(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Remainder(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Root ( MpfrPtr f, MpfrPtr g, uint32_t k, int32_t rnd);

 // needs change
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Lgamma ( MpfrPtr f, int32_t *signp, MpfrPtr g, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Jn(MpfrPtr x, int32_t n, MpfrPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Yn(MpfrPtr x, int32_t n, MpfrPtr y,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fma(MpfrPtr x, MpfrPtr y, MpfrPtr z, MpfrPtr z2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Fms(MpfrPtr x, MpfrPtr y, MpfrPtr z, MpfrPtr z2, int32_t rnd);

 // needs change
// MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Remquo(MpfrPtr x, int32_t* q, MpfrPtr z, MpfrPtr z2, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Ulong_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Slong_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Uint_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Sint_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Ushort_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Sshort_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Uintmax_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Fits_Intmax_P(MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Inf_P(MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Number_P(MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Zero_P(MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Regular_P(MpfrPtr x);

 // needs second argument
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Unordered_P(MpfrPtr x);

 // needs public function
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sgn(MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Integer_P(MpfrPtr x);






 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Init(MpfiPtr* x_re, MpfiPtr* x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Clear(MpfiPtr x_re, MpfiPtr x_im);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Set_Prec(MpfcPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Get_Prec(MpfcPtr x);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui(MpfcPtr res, uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si(MpfcPtr res, int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui64(MpfcPtr res, uint64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si64(MpfcPtr res, int64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_D(MpfcPtr res, double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ld(MpfcPtr res, long double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpz(MpfcPtr res, FmpzPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpq(MpfcPtr res, FmpqPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpfr(MpfcPtr res, MpfrPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui_Ui(MpfcPtr res, uint32_t x1, uint32_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si_Si(MpfcPtr res, int32_t x1, int32_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui64_Ui64(MpfcPtr res, uint64_t x1, uint64_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si64_Si64(MpfcPtr res, int64_t x1, int64_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_D_D(MpfcPtr res, double x1, double x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ld_Ld(MpfcPtr res, long double x1, long double x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpz_Fmpz(MpfcPtr res, FmpzPtr x1, FmpzPtr x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Fmpq_Fmpq(MpfcPtr res, FmpqPtr x1, FmpqPtr x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpfr_Mpfr(MpfcPtr res, MpfrPtr x1, MpfrPtr x2, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Arg(MpfrPtr res, MpfcPtr x,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Abs(MpfrPtr res, MpfcPtr x,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Norm(MpfrPtr res, MpfcPtr x,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Get_Real(MpfrPtr res, MpfcPtr x,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Get_Imag(MpfrPtr res, MpfcPtr x,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Real(MpfcPtr res, MpfrPtr x,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Imag(MpfcPtr res, MpfrPtr x,  int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Set_Nan(MpfcPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Swap(MpfrPtr x, MpfcPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Str(MpfcPtr x, const char * str , int32_t base, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Real_SnPrintf_SizeInBase10(const char *template1, MpfcPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Real_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfcPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Imag_SnPrintf_SizeInBase10(const char *template1, MpfcPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Imag_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfcPtr x);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Cmp(MpfcPtr x, MpfcPtr y);
  MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Neg(MpfcPtr res, MpfcPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_D(MpfcPtr res, MpfcPtr x,  double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Ui_Sub(MpfcPtr res, uint32_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Si_Sub(MpfcPtr res, int32_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Ui64_Sub(MpfcPtr res, uint64_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Si64_Sub(MpfcPtr res, int64_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_D(MpfcPtr res, MpfcPtr x, double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_D_Sub(MpfcPtr res, double x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpz_Sub(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpq_Sub(MpfcPtr res, FmpqPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpfr_Sub(MpfcPtr res, MpfrPtr  x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_D(MpfcPtr res, MpfcPtr x,  double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Ui_Div(MpfcPtr res, uint32_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Si_Div(MpfcPtr res, int32_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Ui64_Div(MpfcPtr res, uint64_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Si64_Div(MpfcPtr res, int64_t x, MpfcPtr y,  int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_D(MpfcPtr res, MpfcPtr x, double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_D_Div(MpfcPtr res, double x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpz_Div(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Fmpq_Div(MpfcPtr res, FmpqPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpfr_Div(MpfcPtr res, MpfrPtr  x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_2exp_Ui(MpfcPtr x, MpfcPtr y,  uint32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_2exp_Si(MpfcPtr x, MpfcPtr y,  int32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_2exp_Ui(MpfcPtr x, MpfcPtr y,  uint32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_2exp_Si(MpfcPtr x, MpfcPtr y,  int32_t e, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_D( MpfcPtr res, MpfcPtr x, double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Ld( MpfcPtr res, MpfcPtr x, double y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Si( MpfcPtr res, MpfcPtr x, int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Ui( MpfcPtr res, MpfcPtr x, uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Mpfr(MpfcPtr res, MpfcPtr x, MpfrPtr y, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Proj(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Conj(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sqr(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sqrt(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Exp(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Log(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Log10(MpfcPtr res, MpfcPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sin(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Cos(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Tan(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sinh(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Cosh(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Tanh(MpfcPtr res, MpfcPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Asin(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Acos(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Atan(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Asinh(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Acosh(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Atanh(MpfcPtr res, MpfcPtr x, int32_t rnd);






 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfi_Init(MpfiPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfi_Clear(MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfi_Set_Prec(MpfiPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Prec(MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ui(MpfiPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si(MpfiPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ui64(MpfiPtr res, uint64_t x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si64(MpfiPtr res, int64_t x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Flt(MpfiPtr res, float x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_D(MpfiPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ld(MpfrPtr res, long double x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpz(MpfrPtr res, FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpq(MpfrPtr res, FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpfr(MpfiPtr res, MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Str(MpfiPtr x, const char * str , int32_t base);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ui_Ui(MpfiPtr res, uint32_t x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si_Si(MpfiPtr res, int32_t x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_UI64_Ui64(MpfiPtr res, uint64_t x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si64_Si64(MpfiPtr res, int64_t x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Flt_Flt(MpfiPtr res, float x, float y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_D_D(MpfiPtr res, double x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ld_Ld(MpfrPtr res, long double x, long double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpz_Fmpz(MpfrPtr res, FmpzPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Fmpq_Fmpq(MpfrPtr res, FmpqPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpfr_Mpfr(MpfiPtr res, MpfrPtr x, MpfrPtr y);


 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Mpfi_Get_Ui(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Si(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t  __cdecl Lib_Mpfi_Get_Ui64(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Mpfi_Get_Si64(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT float  __cdecl Lib_Mpfi_Get_Flt(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpfi_Get_D(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT long double  __cdecl Lib_Mpfi_Get_Ld(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Fmpz(FmpzPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Fmpq(FmpqPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Mpfr(MpfrPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Left(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Right(MpfrPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Diam_Abs(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Diam_Rel(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Diam(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mag(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mig(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mid(MpfrPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfi_Alea(MpfrPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Left(MpfiPtr res, MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Right(MpfiPtr res, MpfrPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Left_SnPrintf_SizeInBase10(const char *template1, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Left_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Right_SnPrintf_SizeInBase10(const char *template1, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Right_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_D(MpfiPtr res, MpfiPtr x,  double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Si(MpfiPtr res, MpfiPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Si64(MpfiPtr res, MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_D(MpfiPtr res, MpfiPtr x,  double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_D_Sub(MpfiPtr res, double y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Ui_Sub(MpfiPtr res, uint32_t y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Si(MpfiPtr res, MpfiPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Si_Sub(MpfiPtr res, int32_t y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Ui64_Sub(MpfiPtr res, uint64_t x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Si64(MpfiPtr res, MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Si64_Sub(MpfiPtr res, int64_t x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpz_Sub(MpfiPtr res, FmpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpq_Sub(MpfiPtr res, FmpqPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpfr_Sub(MpfiPtr res, MpfrPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_D(MpfiPtr res, MpfiPtr x,  double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Si(MpfiPtr res, MpfiPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Si64(MpfiPtr res, MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_D(MpfiPtr res, MpfiPtr x,  double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_D_Div(MpfiPtr res, double y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Ui_Div(MpfiPtr res, uint32_t y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Si(MpfiPtr res, MpfiPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Si_Div(MpfiPtr res, int32_t y, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Ui64_Div(MpfiPtr res, uint64_t x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Si64(MpfiPtr res, MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Si64_Div(MpfiPtr res, int64_t x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpz_Div(MpfiPtr res, FmpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Fmpq_Div(MpfiPtr res, FmpqPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpfr_Div(MpfiPtr res, MpfrPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Neg(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sqr(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Inv(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sqrt(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cbrt(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Abs(MpfiPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_2exp(MpfiPtr res, MpfiPtr x,  uint32_t e);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_2ui(MpfiPtr res, MpfiPtr x,  uint32_t e);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_2si(MpfiPtr res, MpfiPtr x,  int32_t e);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_2exp(MpfiPtr res, MpfiPtr x,  uint32_t e);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_2ui(MpfiPtr res, MpfiPtr x,  uint32_t e);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_2si(MpfiPtr res, MpfiPtr x,  int32_t e);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Log(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Exp(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Exp2(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cos(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sin(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Tan(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sec(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Csc(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cot(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Acos(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Asin(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Atan(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cosh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sinh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Tanh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sech(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Csch(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Coth(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Acosh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Asinh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Atanh(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Log1p(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Log2(MpfiPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Log10(MpfiPtr res, MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Atan2(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Hypot(MpfiPtr res, MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Const_Log2(MpfiPtr res);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Const_Pi(MpfiPtr res);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Const_Euler(MpfiPtr res);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Const_Catalan(MpfiPtr res);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp(MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_D(MpfiPtr x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Ui(MpfiPtr x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Si(MpfiPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Ui64(MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Si64(MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Fmpq(MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Mpfr(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Pos(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Strictly_Pos(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Nonneg(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Neg(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Strictly_Neg(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Nonpos(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Zero(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Has_Zero(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Nan_P(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Inf_P(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Bounded_P(MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Is_Empty(MpfiPtr res);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Revert_If_Needed(MpfiPtr res);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put(MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_D(MpfiPtr x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Ui(MpfiPtr x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Si(MpfiPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Ui64(MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Si64(MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Fmpq(MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Mpfr(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Strictly_Contains(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains(MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_D(MpfiPtr x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Ui(MpfiPtr x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Si(MpfiPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Ui64(MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Si64(MpfiPtr x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Fmpz(MpfiPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Fmpq(MpfiPtr x, FmpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Mpfr(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Intersect(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Union(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Increase(MpfiPtr res, MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Bisect(MpfiPtr res1, MpfiPtr res2, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Blow(MpfiPtr res, MpfiPtr x, double y);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Pow(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Pow_Si( MpfiPtr res, MpfiPtr x, int32_t y);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Init(MpfiPtr* x_re, MpfiPtr* x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Clear(MpfiPtr x_re, MpfiPtr x_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_Prec(MpfiPtr x_re, MpfiPtr x_im, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfci_Get_Prec(MpfiPtr x_re, MpfiPtr x_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set(MpfiPtr res_re, MpfiPtr res_im,  MpfiPtr x_re, MpfiPtr x_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_Si(MpfiPtr res_re, MpfiPtr res_im, int32_t x_re);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_Ui(MpfiPtr res_re, MpfiPtr res_im, uint32_t x_re);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_D(MpfiPtr res_re, MpfiPtr res_im, double x_re);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfci_Set_Str(MpfiPtr res_re, MpfiPtr res_im,  const char * x_re , int32_t base);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_Si_Si(MpfiPtr res_re, MpfiPtr res_im, int32_t x_re, int32_t x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_Ui_Ui(MpfiPtr res_re, MpfiPtr res_im, uint32_t x_re, uint32_t x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Set_D_D(MpfiPtr res_re, MpfiPtr res_im, double x_re, double x_im);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfci_Set_Str_Str(MpfiPtr res_re, MpfiPtr res_im, const char * x_re, const char * x_im, int32_t base);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfci_Cmp(MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Neg(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Add(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Sub(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Mul(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Div(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Pow(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Sqr(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Log(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Exp(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Cos(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Sin(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Abs(MpfiPtr res, MpfiPtr x_re, MpfiPtr x_im);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfci_Arg(MpfiPtr res, MpfiPtr x_re, MpfiPtr x_im);





 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Printd(ArfPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Init(ArfPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Clear(ArfPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Const_Pi(ArfPtr x, int32_t a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Set_Si(ArfPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Set_Ui(ArfPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Set_D(ArfPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arf_Set_Str(ArfPtr x, const char * str , int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Set_Mpfr(ArfPtr x, MpfrPtr a);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Arf_Get_Ui(ArfPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arf_Get_Si(ArfPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Arf_Get_D(ArfPtr x);


 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Arf_SizeInBase10(ArfPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Arf_Get_Str(char * dest , ArfPtr x, int32_t digits, uint32_t flags);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Arf_Cmp(ArfPtr f, ArfPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Neg(ArfPtr f, ArfPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Add(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Add_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Sub(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Sub_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Mul(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Mul_Si(ArfPtr f, ArfPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Mul_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Div(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Div_Si(ArfPtr f, ArfPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Div_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Div_Fmpz(ArfPtr f, ArfPtr g,  FmpzPtr z, int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Mul_2exp(ArfPtr f, ArfPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Div_2exp(ArfPtr f, ArfPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Pow(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arf_Pow_Si(ArfPtr f, ArfPtr g,  int32_t e, int32_t prec);





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



 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Printd(AcfPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Init(AcfPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Clear(AcfPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Const_Pi(AcfPtr x, int32_t a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Set_Si(AcfPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Set_Ui(AcfPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Set_D(AcfPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Set_Mpfr(AcfPtr x, MpfrPtr a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Set_Arb(AcfPtr x, ArbPtr a);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acf_Set_Real_Str(AcfPtr x, const char * str , int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acf_Set_Imag_Str(AcfPtr x, const char * str , int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Acf_Real_SizeInBase10(AcfPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Acf_Get_Real_Str(char * dest , AcfPtr x, int32_t digits, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Acf_Imag_SizeInBase10(AcfPtr x, int32_t n, uint32_t flags);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Acf_Get_Imag_Str(char * dest , AcfPtr x, int32_t digits, uint32_t flags);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acf_Eq(AcfPtr f, AcfPtr g);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Acf_Ne(AcfPtr f, AcfPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Neg(AcfPtr f, AcfPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Add(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Add_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Sub(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Sub_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Mul(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Mul_Si(AcfPtr f, AcfPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Mul_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Div(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Div_Si(AcfPtr f, AcfPtr g, int32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Div_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Div_Fmpz(AcfPtr f, AcfPtr g,  FmpzPtr z, int32_t prec);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Mul_2exp(AcfPtr f, AcfPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Div_2exp(AcfPtr f, AcfPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Pow(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acf_Pow_Si(AcfPtr f, AcfPtr g,  int32_t e, int32_t prec);




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






 MPNUMC_DLL_IMPORTEXPORT void*  __cdecl GetMpdContext();
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Printd(MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Init(MpdPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Clear(MpdPtr x);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Set_Si(MpdPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Set_Ui(MpdPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Set_D(MpdPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Set_Str(MpdPtr x, const char * str);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Mpd_Get_Ui(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpd_Get_Si(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpd_Get_D(MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Mpd_SizeInBase10(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Mpd_Get_Str(char * dest , MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpd_Cmp(MpdPtr f, MpdPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Neg(MpdPtr f, MpdPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Add(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Add_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Sub(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Sub_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Mul(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Mul_Si(MpdPtr f, MpdPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Mul_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Div(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Div_Si(MpdPtr f, MpdPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Div_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Div_Fmpz(MpdPtr f, MpdPtr g,  FmpzPtr z);

// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Mul_2exp(MpdPtr f, MpdPtr g,  uint32_t x);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Div_2exp(MpdPtr f, MpdPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Pow(MpdPtr x, MpdPtr y, MpdPtr z);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Pow_Si(MpdPtr f, MpdPtr g,  int32_t e);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Printd(MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Init(MpdPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Clear(MpdPtr x);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Set_Si(MpdPtr x, int32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Set_Ui(MpdPtr x, uint32_t a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Set_D(MpdPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Set_Str(MpdPtr x, const char * str);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Mpdc_Get_Ui(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpdc_Get_Si(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpdc_Get_D(MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Mpdc_SizeInBase10(MpdPtr x);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Mpdc_Get_Str(char * dest , MpdPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpdc_Cmp(MpdPtr f, MpdPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Neg(MpdPtr f, MpdPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Add(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Add_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Sub(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Sub_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Mul(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Mul_Si(MpdPtr f, MpdPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Mul_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Div(MpdPtr x, MpdPtr y, MpdPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Div_Si(MpdPtr f, MpdPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Div_Ui(MpdPtr f, MpdPtr g,  uint32_t x);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Div_Fmpz(MpdPtr f, MpdPtr g,  FmpzPtr z);

// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Mul_2exp(MpdPtr f, MpdPtr g,  uint32_t x);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Div_2exp(MpdPtr f, MpdPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Pow(MpdPtr x, MpdPtr y, MpdPtr z);
// MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpdc_Pow_Si(MpdPtr f, MpdPtr g,  int32_t e);



#ifdef __cplusplus
}
#endif


#endif // MPNUM_H_INCLUDED
