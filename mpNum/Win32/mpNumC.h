#ifndef MPNUMC_H_INCLUDED
#define MPNUMC_H_INCLUDED

#include <mp_Constants.h>

typedef void* mpNumMatrixPtr;
typedef void* FmpzPtr;
typedef void* FmpqPtr;
typedef void* ArbPtr;
typedef void* AcbPtr;

typedef void* FmpzMatPtr;
typedef void* FmpqMatPtr;
typedef void* ArbMatPtr;
typedef void* AcbMatPtr;



typedef struct {
  int NumType;
  mpNumMatrixPtr NumPtr;
}
__mpNum_struct;

typedef __mpNum_struct mpNum_t[1];

#define MPNUMC_DLL_IMPORTEXPORT

#if defined (BUILD_MPNUMC_DLL)
//#include <mpfr.h>
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

 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Std_Double_Sum(double x, double y);

//#if defined (BUILD_MPNUMC_DLL)
//MPNUMC_DLL_IMPORTEXPORT void  __cdecl cxsc_mpfr_reci(mpfr_t z, const mpfr_t& x);
//#endif

 MPNUMC_DLL_IMPORTEXPORT void   __cdecl mpNum_SetPrecision(int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Print(const char * Title, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Init(int NumType, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Clear(mpNum_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_GetItemFromMatrix(mpNum_t DestItem, long row, long col, mpNum_t SourceMatrix);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_SetItemIntoMatrix(mpNum_t DestMatrix, long row, long col, mpNum_t SourceItem);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_SetSpecialValue(long m, long n, long what, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Inverse(mpNum_t x, mpNum_t m, long Decomposition);

MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_cplx_Functions1(long what, mpNum_t y, mpNum_t x0);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_cplx_Functions2(long what, mpNum_t y, mpNum_t x0, mpNum_t x1);



MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions0(long what, mpNum_t y);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions1(long what, mpNum_t y, mpNum_t x0);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions2(long what, mpNum_t y, mpNum_t x0, mpNum_t x1);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions3(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions1_2Results(long what, mpNum_t y0, mpNum_t y1, mpNum_t x0);
MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Std_Functions2_2Results(long what, mpNum_t y0, mpNum_t y1, mpNum_t x0, mpNum_t x1);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_ElementaryFunctions1(long what, mpNum_t y, mpNum_t x0);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_ElementaryFunctions2(long what, mpNum_t y, mpNum_t x0, mpNum_t x1);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_ElementaryFunctions3(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_ElementaryFunctions4(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2, mpNum_t x3);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_DistributionFunctions2(long Dist, long Target, mpNum_t y, mpNum_t x0, mpNum_t x1);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_DistributionFunctions3(long Dist, long Target, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_DistributionFunctions4(long Dist, long Target, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2, mpNum_t x3);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_BasicArithmetic(long what, mpNum_t m, mpNum_t x, mpNum_t z);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Printf(const char * Title);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Print(FmpzPtr xPtr);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Init(FmpzPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Clear(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Ui(FmpzPtr x, long u);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Print_Pretty(FmpzMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Init(FmpzMatPtr* A, long i, long j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Clear(FmpzMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Mul(FmpzMatPtr X, FmpzMatPtr Y, FmpzMatPtr Z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mat_Set_Ui(FmpzMatPtr A, long i, long j, long u);




 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Print(FmpqPtr xPtr);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Init(FmpqPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Clear(FmpqPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mul(FmpqPtr x, FmpqPtr y, FmpqPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Set_Si(FmpqPtr x, long a, long b);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Print_Pretty(FmpqMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Init(FmpqMatPtr* A, long i, long j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Clear(FmpqMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Mul(FmpqMatPtr X, FmpqMatPtr Y, FmpqMatPtr Z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpq_Mat_Set_Si(FmpqMatPtr A, long i, long j, long p, long q);






 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Printd(ArbPtr x, long int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Init(ArbPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Clear(ArbPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mul(ArbPtr x, ArbPtr y, ArbPtr z, long int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Set_Si(ArbPtr x, long a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Const_Pi(ArbPtr x, long a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Print_Pretty(ArbMatPtr A, long digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Init(ArbMatPtr* A, long i, long j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Clear(ArbMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Mul(ArbMatPtr X, ArbMatPtr Y, ArbMatPtr Z, long digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Arb_Mat_Set_Ui(ArbMatPtr A, long i, long j, long u);





 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Printd(AcbPtr x, long int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Init(AcbPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Clear(AcbPtr x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mul(AcbPtr x, ArbPtr y, ArbPtr z, long int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Set_Si(AcbPtr x, long a);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Const_Pi(AcbPtr x, long a);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Print_Pretty(AcbMatPtr A, long digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Init(AcbMatPtr* A, long i, long j);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Clear(AcbMatPtr A);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Mul(AcbMatPtr X, AcbMatPtr Y, AcbMatPtr Z, long digits);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Acb_Mat_Set_Ui(AcbMatPtr A, long i, long j, long u);


#ifdef __cplusplus
}
#endif


#endif // MPNUM_H_INCLUDED
