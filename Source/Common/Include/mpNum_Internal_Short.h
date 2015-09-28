#ifndef MPNUM_INTERNAL_H_INCLUDED
#define MPNUM_INTERNAL_H_INCLUDED

#include "mpNumC_Short.h"


void EigenLib_Mpfr_SetPrecision(int prec);

void EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
void EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);
void EigenLib_Mpfr_GetCoeff(double* Coeff, long row, long col, mpNumMatrixPtr SourceItem);

void EigenLib_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void EigenLib_Mpfr_SetStringIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, const char * SourceString);

void put_Block_Mpfr(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);
void get_Block_Mpfr(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);

void SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
void SetSpecialValue1_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
void SetSpecialValue2_Mpfr(long Vertical, long Horizontal, long PartialMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);

void Stats2_Mpfr(long what, long *IndexX, long *IndexY, mpNumMatrixPtr x1,  mpNumMatrixPtr y);
void Stats_Mpfr(long PartialMode, long what,  mpNumMatrixPtr x, mpNumMatrixPtr y);
void Compare_Mpfr(long CmpMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr y, long* result);

void BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void BasicArithmetic_i_Mpfr(long i, long what, mpNumMatrixPtr w, mpNumMatrixPtr y);

void EigenLib_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
void EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void EigenLib_Mpfr_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition);
void EigenLib_Mpfr_Rank(mpNumMatrixPtr A, long Decomposition, long* rank);

void EigenLib_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
void EigenLib_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void EigenLib_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
void EigenLib_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void EigenLib_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);


void cplx_EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

void cplx_EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_EigenLib_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
void cplx_EigenLib_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
void cplx_EigenLib_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void cplx_EigenLib_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
void cplx_EigenLib_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void cplx_EigenLib_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);





#endif // MPNUM_INTERNAL_H_INCLUDED
