#ifndef MPNUMC_H_INCLUDED
#define MPNUMC_H_INCLUDED

typedef void* mpNumMatrixPtr;

//typedef struct {
//  int NumType;
//  mpNumMatrixPtr NumPtr;
//}
//__mpNum_struct;
//
//typedef __mpNum_struct mpNum_t[1];


#include <stdint.h>

typedef void* GmpRandPtr;
typedef void* MpzPtr;
typedef void* MpqPtr;
typedef void* MpfrPtr;
typedef void* MpfcPtr;
typedef void* MpfiPtr;
typedef void* MpfciPtr;
typedef void* MpdPtr;
typedef void* MpdcPtr;


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

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Init(MpzPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Clear(MpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set(MpzPtr res, MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set_Ui(MpzPtr x, uint32_t u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set_Si(MpzPtr x, int32_t u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set_Ui64(MpfcPtr x, uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set_Si64(MpfcPtr x, int64_t sint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Set_D(MpzPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpz_Set_Str(MpzPtr x, const char * str , int32_t b);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Mpz_Get_Ui(MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpz_Get_Si(MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t   __cdecl Lib_Mpz_Get_Ui64(MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Mpz_Get_Si64(MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpz_Get_D(MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint32_t Lib_Mpz_SizeInBase(MpzPtr x, int32_t base);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Mpz_Get_Str(char * str , int32_t b, MpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpz_Cmp(MpzPtr f, MpzPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Neg(MpzPtr f, MpzPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Add(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Add_Ui(MpzPtr f, MpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Add_Si(MpzPtr f, MpzPtr g,  int32_t si);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Add_Ui64(MpzPtr f, MpzPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Add_Si64(MpzPtr f, MpzPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Sub(MpzPtr res, MpzPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Ui_Sub(MpzPtr res,  uint32_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Sub_Ui(MpzPtr res, MpzPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Si_Sub(MpzPtr res, int32_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Sub_Si(MpzPtr res, MpzPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Ui64_Sub(MpzPtr res, uint64_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Sub_Ui64(MpzPtr res, MpzPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Si64_Sub(MpzPtr res, int64_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Sub_Si64(MpzPtr res, MpzPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul_Ui(MpzPtr f, MpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul_Si(MpzPtr f, MpzPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul_Ui64(MpzPtr f, MpzPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul_Si64(MpzPtr f, MpzPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Ui_Tdiv_Q(MpzPtr res,  uint32_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q_Ui(MpzPtr res, MpzPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Si_Tdiv_Q(MpzPtr res,  int32_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q_Si(MpzPtr res, MpzPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Ui64_Tdiv_Q(MpzPtr res, uint64_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q_Ui64(MpzPtr res, MpzPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Si64_Tdiv_Q(MpzPtr res, int64_t x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q_Si64(MpzPtr res, MpzPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mul_2exp(MpzPtr f, MpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Tdiv_Q_2exp(MpzPtr f, MpzPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Mod(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Pow_Ui(MpzPtr f, MpzPtr g,  uint32_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_Complement(MpzPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_And(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_OR(MpzPtr x, MpzPtr y, MpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpz_XOR(MpzPtr x, MpzPtr y, MpzPtr z);





 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Init(MpqPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Clear(MpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set(MpqPtr res, MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui(MpqPtr x, uint32_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si(MpqPtr x, int32_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui64(MpqPtr x, uint64_t p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si64(MpqPtr x, int64_t p);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui_Ui(MpqPtr x, uint32_t p, uint32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui_Si(MpqPtr x, uint32_t p, int32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si_Ui(MpqPtr x, int32_t p, uint32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si_Si(MpqPtr x, int32_t p, int32_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui64_Ui64(MpqPtr x, uint64_t p, uint64_t q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Ui64_Si64(MpqPtr x, uint64_t  p, int64_t  q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si64_Ui64(MpqPtr x, int64_t  p, uint64_t  q);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Si64_Si64(MpqPtr x, int64_t  p, int64_t  q);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Mpz(MpqPtr x, MpzPtr p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Num(MpqPtr x, MpzPtr p);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_Den(MpqPtr x, MpzPtr p);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Set_D(MpqPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpq_Set_Str(MpqPtr x, const char * str , int32_t b);

 MPNUMC_DLL_IMPORTEXPORT uint32_t   __cdecl Lib_Mpq_Get_Ui(MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpq_Get_Si(MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t   __cdecl Lib_Mpq_Get_Ui64(MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Mpq_Get_Si64(MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpq_Get_D(MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Get_Mpz(MpzPtr res, MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Get_Num(MpzPtr res, MpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Get_Den(MpzPtr res, MpqPtr x);


 MPNUMC_DLL_IMPORTEXPORT uint32_t Lib_Mpq_SizeInBase(MpqPtr x, int32_t base);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Mpq_Get_Str(char * str , int32_t b, MpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpq_Cmp(MpqPtr f, MpqPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Neg(MpqPtr f, MpqPtr g);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Add(MpqPtr x, MpqPtr y, MpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Add_Ui(MpqPtr f, MpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Add_Si(MpqPtr f, MpqPtr g,  int32_t si);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Add_Ui64(MpqPtr f, MpqPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Add_Si64(MpqPtr f, MpqPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Sub(MpqPtr res, MpqPtr x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Ui_Sub(MpqPtr res,  uint32_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Sub_Ui(MpqPtr res, MpqPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Si_Sub(MpqPtr res, int32_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Sub_Si(MpqPtr res, MpqPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Ui64_Sub(MpqPtr res, uint64_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Sub_Ui64(MpqPtr res, MpqPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Si64_Sub(MpqPtr res, int64_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Sub_Si64(MpqPtr res, MpqPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul(MpqPtr x, MpqPtr y, MpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul_Ui(MpqPtr f, MpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul_Si(MpqPtr f, MpqPtr g, int32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul_Ui64(MpqPtr f, MpqPtr g,  uint64_t uint64);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul_Si64(MpqPtr f, MpqPtr g,  int64_t sint64);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div(MpqPtr x, MpqPtr y, MpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Ui_Div(MpqPtr res,  uint32_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div_Ui(MpqPtr res, MpqPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Si_Div(MpqPtr res,  int32_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div_Si(MpqPtr res, MpqPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Ui64_Div(MpqPtr res, uint64_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div_Ui64(MpqPtr res, MpqPtr x,  uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Si64_Div(MpqPtr res, int64_t x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div_Si64(MpqPtr res, MpqPtr x,  int64_t y);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Mul_2exp(MpqPtr f, MpqPtr g,  uint32_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpq_Div_2exp(MpqPtr f, MpqPtr g,  uint32_t x);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfr_Urandomb(MpfrPtr res, GmpRandPtr state);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Mpz(MpfrPtr x, MpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Set_Mpq(MpfrPtr x, MpqPtr q, int32_t rnd);


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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Mpz( MpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Mpq( MpqPtr q, MpfrPtr y, int32_t rnd);



// The next 3 need to change
// MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpfr_Get_D_2exp(int32_t *exp, MpfrPtr x, int32_t rnd);
// MPNUMC_DLL_IMPORTEXPORT long double  __cdecl Lib_Mpfr_Get_Ld_2exp(int32_t *exp, MpfrPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Frexp(int32_t *exp, MpfrPtr y, MpfrPtr x, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Get_Mpz_2exp( MpzPtr x, MpfrPtr y);


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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Add_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd);


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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mpz_Sub(MpfrPtr res, MpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Sub_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mpq_Sub(MpfrPtr res, MpqPtr x, MpfrPtr y, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Si(MpfrPtr f, MpfrPtr g, int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Ui64(MpfrPtr f, MpfrPtr g, uint64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Si64(MpfrPtr f, MpfrPtr g, int64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Mpz(MpfrPtr x, MpfrPtr y, MpzPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mul_Mpq(MpfrPtr x, MpfrPtr y, MpqPtr q, int32_t rnd);


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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mpz_Div(MpfrPtr res, MpzPtr x, MpfrPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Div_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Mpq_Div(MpfrPtr res, MpqPtr x, MpfrPtr y, int32_t rnd);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Ui ( MpfrPtr f, MpfrPtr g,uint32_t e, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfr_Pow_Si(MpfrPtr f, MpfrPtr g,  int32_t e, int32_t rnd);

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




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Init(MpfcPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Clear(MpfcPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpfc_Set_Prec(MpfcPtr x, int32_t prec);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Get_Prec(MpfcPtr x);


 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set(MpfcPtr res, MpfcPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui(MpfcPtr res, uint32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si(MpfcPtr res, int32_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui64(MpfcPtr res, uint64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si64(MpfcPtr res, int64_t x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_D(MpfcPtr res, double x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ld(MpfcPtr res, long double x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpz(MpfcPtr res, MpzPtr x, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpq(MpfcPtr res, MpqPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpfr(MpfcPtr res, MpfrPtr x, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui_Ui(MpfcPtr res, uint32_t x1, uint32_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si_Si(MpfcPtr res, int32_t x1, int32_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ui64_Ui64(MpfcPtr res, uint64_t x1, uint64_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Si64_Si64(MpfcPtr res, int64_t x1, int64_t x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_D_D(MpfcPtr res, double x1, double x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Ld_Ld(MpfcPtr res, long double x1, long double x2, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpz_Mpz(MpfcPtr res, MpzPtr x1, MpzPtr x2, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Set_Mpq_Mpq(MpfcPtr res, MpqPtr x1, MpqPtr x2, int32_t rnd);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Mpz(MpfcPtr res, MpfcPtr x,  MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Add_Mpq(MpfcPtr res, MpfcPtr x,  MpqPtr y, int32_t rnd);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpz_Sub(MpfcPtr res, MpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpq_Sub(MpfcPtr res, MpqPtr x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Sub_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpfr_Sub(MpfcPtr res, MpfrPtr  x, MpfcPtr y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_D(MpfcPtr res, MpfcPtr x,  double y, int32_t rnd);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Mpz(MpfcPtr res, MpfcPtr x,  MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mul_Mpq(MpfcPtr res, MpfcPtr x,  MpqPtr y, int32_t rnd);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpz_Div(MpfcPtr res, MpzPtr x, MpfcPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Div_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Mpq_Div(MpfcPtr res, MpqPtr x, MpfcPtr y, int32_t rnd);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd);
 //MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfc_Pow_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpz(MpfrPtr res, MpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpq(MpfrPtr res, MpqPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpfr(MpfiPtr res, MpfrPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Str(MpfiPtr x, const char * str , int32_t base);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ui_Ui(MpfiPtr res, uint32_t x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si_Si(MpfiPtr res, int32_t x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_UI64_Ui64(MpfiPtr res, uint64_t x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Si64_Si64(MpfiPtr res, int64_t x, int64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Flt_Flt(MpfiPtr res, float x, float y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_D_D(MpfiPtr res, double x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Ld_Ld(MpfrPtr res, long double x, long double y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpz_Mpz(MpfrPtr res, MpzPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpq_Mpq(MpfrPtr res, MpqPtr x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Set_Mpfr_Mpfr(MpfiPtr res, MpfrPtr x, MpfrPtr y);


 MPNUMC_DLL_IMPORTEXPORT uint32_t  __cdecl Lib_Mpfi_Get_Ui(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Si(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT uint64_t  __cdecl Lib_Mpfi_Get_Ui64(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int64_t  __cdecl Lib_Mpfi_Get_Si64(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT float  __cdecl Lib_Mpfi_Get_Flt(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Mpfi_Get_D(MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT long double  __cdecl Lib_Mpfi_Get_Ld(MpfiPtr x);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Mpz(MpzPtr res, MpfiPtr x);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Get_Mpq(MpqPtr res, MpfiPtr x);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Add_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y);
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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpz_Sub(MpfiPtr res, MpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpq_Sub(MpfiPtr res, MpqPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Sub_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpfr_Sub(MpfiPtr res, MpfrPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul(MpfiPtr res, MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_D(MpfiPtr res, MpfiPtr x,  double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Si(MpfiPtr res, MpfiPtr x,  int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Si64(MpfiPtr res, MpfiPtr x, int64_t y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mul_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y);
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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpz_Div(MpfiPtr res, MpzPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Div_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Mpq_Div(MpfiPtr res, MpqPtr x, MpfiPtr y);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Mpz(MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Cmp_Mpq(MpfiPtr x, MpqPtr y);

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

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Mpz(MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Mpq(MpfiPtr x, MpqPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Put_Mpfr(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Strictly_Contains(MpfiPtr x, MpfiPtr y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains(MpfiPtr x, MpfiPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_D(MpfiPtr x, double y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Ui(MpfiPtr x, uint32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Si(MpfiPtr x, int32_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Ui64(MpfiPtr x, uint64_t y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Si64(MpfiPtr x, int64_t y);

 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Mpz(MpfiPtr x, MpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT int32_t  __cdecl Lib_Mpfi_Contains_Mpq(MpfiPtr x, MpqPtr y);
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

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Mpd_Pow(MpdPtr x, MpdPtr y, MpdPtr z);




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




//*************************************************************************************
//*************************************************************************************
//*************************************************************************************
//*************************************************************************************




MPNUMC_DLL_IMPORTEXPORT void __cdecl Lib_Eigen_Mpfr_SetPrecision(int prec);

MPNUMC_DLL_IMPORTEXPORT void __cdecl Lib_Eigen_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Init(mpNumMatrixPtr* x);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Clear(mpNumMatrixPtr x);
//MPNUMC_DLL_IMPORTEXPORT void Lib_Eigen_Mpfr_GetCoeff(double* Coeff, long row, long col, mpNumMatrixPtr SourceItem);

//MPNUMC_DLL_IMPORTEXPORT void Lib_Eigen_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
//MPNUMC_DLL_IMPORTEXPORT void Lib_Eigen_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
//MPNUMC_DLL_IMPORTEXPORT void Lib_Eigen_Mpfr_SetStringIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, const char * SourceString);





MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_GetCoeff2(MpfrPtr res, long row, long col, mpNumMatrixPtr SourceMatrix);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetCoeff2(MpfrPtr src, long row, long col, mpNumMatrixPtr DestMatrix);







MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_GetRows(mpNumMatrixPtr Matrix);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_GetCols(mpNumMatrixPtr Matrix);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_GetSize(mpNumMatrixPtr Matrix);


//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Resize(mpNumMatrixPtr Res, long rows, long cols);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Conservative_Resize(mpNumMatrixPtr Res, long rows, long cols);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetRandom(mpNumMatrixPtr Res, long rows, long cols);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetRandomSymmetric(mpNumMatrixPtr Res, long rows, long cols);


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetSpecialValue(long m, long n, long what, mpNumMatrixPtr xPtr);



//*************************************************************************************



MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Get_Block(mpNumMatrixPtr result, long i, long j, long p, long q,  mpNumMatrixPtr source);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Put_Block(mpNumMatrixPtr source, long i, long j, long p, long q,  mpNumMatrixPtr result);


//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetSpecialValue1(long m, long n, long what, mpNumMatrixPtr xPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SetSpecialValue2(long Vertical, long Horizontal, long PartialMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);

MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Stats2(long what, long *IndexX, long *IndexY, mpNumMatrixPtr x1,  mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Stats(long PartialMode, long what,  mpNumMatrixPtr x, mpNumMatrixPtr y);


//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_GT_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_LT_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_LE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_GE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_EQ_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfr_NE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y);



MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Compare(long CmpMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr y, long* result);


//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_MatAdd(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_MatSub(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_cwiseProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_cwiseQuotient(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_MatMul(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_MatDotProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);

MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_Add_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_Sub_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_Mul_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Mat_Div_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_BasicArithmetic(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);



//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition);
MPNUMC_DLL_IMPORTEXPORT int32_t __cdecl  Lib_Eigen_Mpfr_Rank(mpNumMatrixPtr A, long Decomposition);

//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);




//*************************************************************************************
//*************************************************************************************
//*************************************************************************************
//*************************************************************************************




MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Print(const char * Title, mpNumMatrixPtr xPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Init(mpNumMatrixPtr* x);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Clear(mpNumMatrixPtr x);


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Complex_To_2Reals(mpNumMatrixPtr RealDestMatrix, mpNumMatrixPtr ImagDestMatrix, mpNumMatrixPtr CplxSourceMatrix);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_2Reals_To_Complex(mpNumMatrixPtr CplxDestMatrix, mpNumMatrixPtr RealSourceMatrix, mpNumMatrixPtr ImagSourceMatrix);



MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_GetCoeff2a(MpfcPtr res, long row, long col, mpNumMatrixPtr SourceMatrix);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_SetCoeff2a(MpfcPtr src,  long row, long col, mpNumMatrixPtr DestMatrix);


MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfc_GetRows(mpNumMatrixPtr Matrix);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfc_GetCols(mpNumMatrixPtr Matrix);
MPNUMC_DLL_IMPORTEXPORT uint32_t __cdecl  Lib_Eigen_Mpfc_GetSize(mpNumMatrixPtr Matrix);




//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Resize(mpNumMatrixPtr Res, long rows, long cols);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Conservative_Resize(mpNumMatrixPtr Res, long rows, long cols);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_SetRandom(mpNumMatrixPtr Res, long rows, long cols);


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_SetSpecialValue(long m, long n, long what, mpNumMatrixPtr xPtr);


//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_MatAdd(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_MatSub(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_cwiseProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_cwiseQuotient(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_MatMul(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_MatDotProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);

MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_Add_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_Sub_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_Mul_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Mat_Div_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr);


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_BasicArithmetic(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);



//*************************************************************************************


MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);

MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition);


//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
//MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
MPNUMC_DLL_IMPORTEXPORT void __cdecl  Lib_Eigen_Mpfc_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);



#ifdef __cplusplus
}
#endif


#endif // MPNUM_H_INCLUDED
