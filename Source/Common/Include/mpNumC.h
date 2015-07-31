#ifndef MPNUMC_H_INCLUDED
#define MPNUMC_H_INCLUDED

typedef void* FmpzPtr;
typedef void* FmpqPtr;
typedef void* ArbPtr;
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

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Flint_Printf(const char * Title);


 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Print(FmpzPtr xPtr);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Init(FmpzPtr* x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Clear(FmpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Ui(FmpzPtr x, unsigned int u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_Si(FmpzPtr x, int u);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Set_D(FmpzPtr x, double u);
 MPNUMC_DLL_IMPORTEXPORT int  __cdecl Lib_Fmpz_Set_Str(FmpzPtr x, const char * str , int b);

 MPNUMC_DLL_IMPORTEXPORT unsigned int   __cdecl Lib_Fmpz_Get_Ui(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT int  __cdecl Lib_Fmpz_Get_Si(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Lib_Fmpz_Get_D(FmpzPtr x);
 MPNUMC_DLL_IMPORTEXPORT char *  __cdecl Lib_Fmpz_Get_Str(char * str , int b, FmpzPtr x);

 MPNUMC_DLL_IMPORTEXPORT int  __cdecl Lib_Fmpz_Cmp(FmpzPtr f, FmpzPtr g);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Neg(FmpzPtr f, FmpzPtr g);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Add_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Sub_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Si(FmpzPtr f, FmpzPtr g, int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Si(FmpzPtr f, FmpzPtr g, int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mul_2exp(FmpzPtr f, FmpzPtr g,  unsigned int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Tdiv_Q_2exp(FmpzPtr f, FmpzPtr g,  unsigned int x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Mod(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Pow_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_Complement(FmpzPtr x, FmpzPtr y);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_And(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_OR(FmpzPtr x, FmpzPtr y, FmpzPtr z);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl Lib_Fmpz_XOR(FmpzPtr x, FmpzPtr y, FmpzPtr z);


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
