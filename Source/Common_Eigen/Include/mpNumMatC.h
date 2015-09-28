#ifndef MPNUMC_H_INCLUDED
#define MPNUMC_H_INCLUDED

#include <mp_Constants.h>

typedef void* mpNumMatrixPtr;

typedef struct {
  int NumType;
  mpNumMatrixPtr NumPtr;
}
__mpNum_struct;

typedef __mpNum_struct mpNum_t[1];

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

 MPNUMC_DLL_IMPORTEXPORT double  __cdecl Std_Double_Sum(double x, double y);

 MPNUMC_DLL_IMPORTEXPORT void   __cdecl mpNum_SetPrecision(int prec);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Print(const char * Title, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Init(int NumType, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Clear(mpNum_t x);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_GetItemFromMatrix(mpNum_t DestItem, long row, long col, mpNum_t SourceMatrix);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_SetItemIntoMatrix(mpNum_t DestMatrix, long row, long col, mpNum_t SourceItem);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_SetSpecialValue(long m, long n, long what, mpNum_t x);
 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_Inverse(mpNum_t x, mpNum_t m, long Decomposition);

 MPNUMC_DLL_IMPORTEXPORT void  __cdecl mpNum_BasicArithmetic(long what, mpNum_t m, mpNum_t x, mpNum_t z);


#ifdef __cplusplus
}
#endif


#endif // MPNUM_H_INCLUDED
