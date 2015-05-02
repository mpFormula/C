#include <mp_Constants.h>
#include <Eigen/Dense>
#include <Eigen/Eigenvalues>
#include "stdint.h"
#include <complex>


using namespace Eigen;
using namespace std;

#define EIGEN_DLL_IMPORTEXPORT

#if defined (BUILD_EIGEN_DLL)
  #undef EIGEN_DLL_IMPORTEXPORT
  #define EIGEN_DLL_IMPORTEXPORT __declspec( dllexport )
#elif defined (TEST_DLLEIGEN)
  #undef EIGEN_DLL_IMPORTEXPORT
  #define EIGEN_DLL_IMPORTEXPORT __declspec( dllimport )
#endif


#ifndef mpType
    #define mpType
#endif // mpType

#ifdef Use_Float
    #undef mpType
    #define mpType float
#endif // UseFloat


#ifdef Use_Double
    #undef mpType
    #define mpType double
#endif // Use_Double


#ifdef Use_LongDouble
    #undef mpType
    #define mpType long double
#endif // Use_LongDouble


#ifdef Use_Mpfr
    #include "mprealsupport.h"
    #undef mpType
    #define mpType mpfr2::mpreal
#endif // Use_Mpfr


#ifdef Use_Mpfi
    #include "mprealsupport.h"
    #include "mpRealIntervalSupport.h"
    #undef mpType
    #define mpType mpfi::mpRealInterval
#endif // Use_Mpfi



#ifdef Use_Mpdec
    #include "mprealsupport.h"
    #include "mpRealDecimalSupport.h"
    #undef mpType
    #define mpType mpDec::mpdec_class
#endif // Use_Mpdec



#ifdef Use_Mpq
    #include "mprealsupport.h"
    #include "mpRealRationalSupport.h"
    #undef mpType
    #define mpType mpq::mpRealRational
#endif // Use_Mpfi




typedef complex<mpType>  cplx_mpType ;
typedef Matrix<mpType,Dynamic,Dynamic>  mpMatrix;
typedef Matrix<complex<mpType>,Dynamic,Dynamic>  mpMatrixC;


typedef mpMatrix* mpMatrixPtr;
typedef mpMatrixC* mpCplxMatrixPtr;


EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Init(mpMatrixPtr* x);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Clear(mpMatrixPtr* x);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_GetCoeff(mpType* Coeff, long row, long col, mpMatrixPtr x);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_SetItemIntoMatrix(mpMatrix *DestMatrix, long row, long col, mpMatrix *SourceItem);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_GetItemFromMatrix(mpMatrix *DestItem, long row, long col, mpMatrix *SourceMatrix);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_SetStringIntoMatrix(mpMatrix *DestMatrix, long row, long col, const char * SourceString);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_SetDoubleIntoMatrix(mpMatrix *DestMatrix, long row, long col, const double SourceDouble);


EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Print(const char * Title, mpMatrixPtr xPtr);

#if defined (Use_Mpfr) || defined (Use_ALL)
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpfr_SetPrecision(int prec);
#endif




#if defined (Use_Mpfi) || defined (Use_ALL)
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpfi_SetPrecision(int prec);
#endif


#if defined (Use_Mpdec) || defined (Use_ALL)
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpdec_SetPrecision(int prec);
#endif



EIGEN_DLL_IMPORTEXPORT void put_Block_mpType(long i, long j, long p, long q, long what, mpMatrixPtr x, mpMatrixPtr result);
EIGEN_DLL_IMPORTEXPORT void get_Block_mpType(long i, long j, long p, long q, long what, mpMatrixPtr x, mpMatrixPtr result);
EIGEN_DLL_IMPORTEXPORT void SetSpecialValue_mpType(int32_t m, int32_t n, long what, mpMatrixPtr x);
EIGEN_DLL_IMPORTEXPORT void SetSpecialValue1_mpType(int32_t m, int32_t n, long what, mpMatrixPtr x);
EIGEN_DLL_IMPORTEXPORT void SetSpecialValue2_mpType(long Vertical, long Horizontal, long PartialMode, long what, mpMatrixPtr x, mpMatrixPtr result);
EIGEN_DLL_IMPORTEXPORT void Stats2_mpType(long what, long *IndexX, long *IndexY, mpMatrixPtr x1,  mpMatrixPtr y);
EIGEN_DLL_IMPORTEXPORT void Stats_mpType(long PartialMode, long what,  mpMatrixPtr x, mpMatrixPtr y);
EIGEN_DLL_IMPORTEXPORT void Compare_mpType(long CmpMode, long what, mpMatrixPtr w, mpMatrixPtr x, long* result);



EIGEN_DLL_IMPORTEXPORT void BasicArithmetic_mpType(long what, mpMatrixPtr w, mpMatrixPtr x, mpMatrixPtr y);
EIGEN_DLL_IMPORTEXPORT void BasicArithmetic_i_mpType(long i, long what, mpMatrixPtr w, mpMatrixPtr y);


//EIGEN_DLL_IMPORTEXPORT void  boost_mpType_IntegerFunctions1(long what, mpMatrixPtr d, MatrixXmpq *y);
//EIGEN_DLL_IMPORTEXPORT void  boost_mpType_IntegerFunctions2(long what, mpMatrixPtr x1, mpMatrixPtr x2, MatrixXmpq *y);
//EIGEN_DLL_IMPORTEXPORT void  boost_mpType_IntegerFunctions3(long what, mpMatrixPtr x1, mpMatrixPtr x2, mpMatrixPtr x3, MatrixXmpq *y);
//EIGEN_DLL_IMPORTEXPORT void  boost_mpType_IntegerFunctions4(long what, mpMatrixPtr x1, mpMatrixPtr x2, mpMatrixPtr x3, mpMatrixPtr x4, MatrixXmpq *y);

EIGEN_DLL_IMPORTEXPORT void  boost_mpType_Functions1Bool(long what, mpMatrixPtr x, long * result);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_Functions2Bool(long what, mpMatrixPtr x, mpMatrixPtr y, long * result);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_Functions3Bool(long what, mpMatrixPtr x, mpMatrixPtr y, mpMatrixPtr z, long * result);

EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions0(long what, mpMatrixPtr y0);
EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions1(long what, mpMatrixPtr y0, mpMatrixPtr x0);
EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions2(long what, mpMatrix *y0, mpMatrix *x0,  mpMatrix *x1);
EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions3(long what, mpMatrix *y0, mpMatrix *x0,  mpMatrix *x1,  mpMatrix *x2);
EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions_2Results(long what, mpMatrix *y0, mpMatrix *y1,  mpMatrix *x0);
EIGEN_DLL_IMPORTEXPORT void  Std_mpType_Functions2_2Results(long what, mpMatrix *y0, mpMatrix *y1,  mpMatrix *x0,  mpMatrix *x1);



EIGEN_DLL_IMPORTEXPORT void  boost_mpType_ElementaryFunctions1(long what, mpMatrixPtr y, mpMatrixPtr x0);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_ElementaryFunctions2(long what, mpMatrixPtr y, mpMatrixPtr x0, mpMatrixPtr x1);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_ElementaryFunctions3(long what, mpMatrixPtr y, mpMatrixPtr x0, mpMatrixPtr x1, mpMatrixPtr x2);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_ElementaryFunctions4(long what, mpMatrixPtr y, mpMatrixPtr x0, mpMatrixPtr x1, mpMatrixPtr x2,  mpMatrixPtr x3);

EIGEN_DLL_IMPORTEXPORT void  boost_mpType_DistributionFunctions2(long Dist, long Target, mpMatrixPtr y,  mpMatrixPtr x0,  mpMatrixPtr x1);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_DistributionFunctions3(long Dist, long Target, mpMatrixPtr y,  mpMatrixPtr x0,  mpMatrixPtr x1,  mpMatrixPtr x2);
EIGEN_DLL_IMPORTEXPORT void  boost_mpType_DistributionFunctions4(long Dist, long Target, mpMatrixPtr y,  mpMatrixPtr x0,  mpMatrixPtr x1,  mpMatrixPtr x2,  mpMatrixPtr x3);


EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Solve(mpMatrixPtr x, mpMatrixPtr A, mpMatrixPtr b, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Solve2(mpMatrixPtr x, mpMatrixPtr A, mpMatrixPtr b, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Inverse(mpMatrixPtr x, mpMatrixPtr A, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Det(mpMatrixPtr x, mpMatrixPtr A, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_Rank(mpMatrixPtr A, long Decomposition, long* rank);

EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_JacobiSVD_Full(mpMatrixPtr s, mpMatrixPtr u, mpMatrixPtr v, mpMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_SelfAdjointEigenValues(mpMatrixPtr x, mpMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_SelfAdjointEigenSystem(mpMatrixPtr x, mpMatrixPtr y, mpMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_EigenValues(mpCplxMatrixPtr x, mpMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_mpType_EigenSystem(mpCplxMatrixPtr x, mpCplxMatrixPtr y, mpMatrixPtr A);




//EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_GetCoeff(cplx_mpType* Coeff, long row, long col, mpMatrixC *x);

EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Init(mpCplxMatrixPtr* x);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Clear(mpCplxMatrixPtr* x);

EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Print(const char * Title, mpCplxMatrixPtr xPtr);

EIGEN_DLL_IMPORTEXPORT void SetSpecialValue_cplx_mpType(int32_t m, int32_t n, long what, mpMatrixC *x);
EIGEN_DLL_IMPORTEXPORT void BasicArithmetic_cplx_mpType(long what, mpMatrixC *w, mpMatrixC *x, mpMatrixC *y);

EIGEN_DLL_IMPORTEXPORT void Std_mpType_cplx_Functions1(long what, mpMatrixC *y0, mpMatrixC *x0);
EIGEN_DLL_IMPORTEXPORT void Std_mpType_cplx_Functions2(long what, mpMatrixC *y0, mpMatrixC *x0,  mpMatrixC *x1);





EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Inverse(mpMatrixC *x, mpMatrixC *A, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Solve(mpCplxMatrixPtr x, mpCplxMatrixPtr A, mpCplxMatrixPtr b, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_Solve2(mpCplxMatrixPtr x, mpCplxMatrixPtr A, mpCplxMatrixPtr b, long Decomposition);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_JacobiSVD_Full(mpMatrixPtr s, mpCplxMatrixPtr u, mpCplxMatrixPtr v, mpCplxMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_SelfAdjointEigenValues(mpMatrixPtr x, mpCplxMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_SelfAdjointEigenSystem(mpMatrixPtr x, mpCplxMatrixPtr y, mpCplxMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_EigenValues(mpCplxMatrixPtr x, mpCplxMatrixPtr A);
EIGEN_DLL_IMPORTEXPORT void EigenLib_cplx_mpType_EigenSystem(mpCplxMatrixPtr x, mpCplxMatrixPtr y, mpCplxMatrixPtr A);

