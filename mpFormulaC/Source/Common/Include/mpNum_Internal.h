#ifndef MPNUM_INTERNAL_H_INCLUDED
#define MPNUM_INTERNAL_H_INCLUDED

#include "mpNumC.h"

void EigenLib_Float_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Float_Init(mpNumMatrixPtr* x);
void EigenLib_Float_Clear(mpNumMatrixPtr* x);

void EigenLib_Float_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Float_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);


void SetSpecialValue_Float(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Float_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Float_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Float_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Float_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Float_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Float_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Float_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Float_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Float_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Float_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Float_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Float_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Float_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void EigenLib_Float_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Float(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

void cplx_EigenLib_Float_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Float_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Float_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Float(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Float_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Float_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_Float_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Float(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Float_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Float_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Float_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Float_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Float_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Float_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);


void EigenLib_Double_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Double_Init(mpNumMatrixPtr* x);
void EigenLib_Double_Clear(mpNumMatrixPtr* x);

void EigenLib_Double_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Double_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);


void SetSpecialValue_Double(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Double_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Double_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Double_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Double_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Double_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Double_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Double_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Double_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Double_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Double_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Double_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Double_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Double_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void EigenLib_Double_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Double(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Double_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Double_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Double_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Double_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Double_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Double_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);

void cplx_EigenLib_Double_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Double_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Double_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Double(long m, long n, long what, mpNumMatrixPtr xPtr);

void Std_Double_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Double_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);


void cplx_EigenLib_Double_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Double(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);



void EigenLib_LongDouble_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_LongDouble_Init(mpNumMatrixPtr* x);
void EigenLib_LongDouble_Clear(mpNumMatrixPtr* x);

void EigenLib_LongDouble_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_LongDouble_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);


void SetSpecialValue_LongDouble(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_LongDouble_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_LongDouble_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_LongDouble_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_LongDouble_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_LongDouble_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_LongDouble_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_LongDouble_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_LongDouble_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_LongDouble_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_LongDouble_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_LongDouble_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_LongDouble_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_LongDouble_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void EigenLib_LongDouble_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_LongDouble(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_LongDouble_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_LongDouble_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_LongDouble_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_LongDouble_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_LongDouble_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_LongDouble_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);



void cplx_EigenLib_LongDouble_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_LongDouble_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_LongDouble_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_LongDouble(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_LongDouble_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_LongDouble_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_LongDouble_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_LongDouble(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);


void EigenLib_Mpfr_SetPrecision(int prec);
void EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
void EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);

void EigenLib_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);


void SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpfr_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Mpfr_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpfr_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Mpfr_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Mpfr_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Mpfr_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfr_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Mpfr_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfr_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpfr_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Mpfr_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfr_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpfr_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Mpfr_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Mpfr_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Mpfr_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Mpfr_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Mpfr_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Mpfr_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);


void cplx_EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpfr_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpfr_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);


void EigenLib_Mpfi_SetPrecision(int prec);
void EigenLib_Mpfi_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpfi_Init(mpNumMatrixPtr* x);
void EigenLib_Mpfi_Clear(mpNumMatrixPtr* x);

void EigenLib_Mpfi_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpfi_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);


void SetSpecialValue_Mpfi(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpfi_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Mpfi_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpfi_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Mpfi_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Mpfi_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Mpfi_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfi_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Mpfi_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfi_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpfi_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Mpfi_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpfi_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpfi_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void EigenLib_Mpfi_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpfi(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Mpfi_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Mpfi_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Mpfi_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Mpfi_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Mpfi_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Mpfi_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);


void cplx_EigenLib_Mpfi_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpfi_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpfi_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpfi(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpfi_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpfi_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_Mpfi_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpfi(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);



void EigenLib_Mpdec_SetPrecision(int prec);
void EigenLib_Mpdec_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpdec_Init(mpNumMatrixPtr* x);
void EigenLib_Mpdec_Clear(mpNumMatrixPtr* x);

void EigenLib_Mpdec_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpdec_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Mpdec(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpdec_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Mpdec_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpdec_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Mpdec_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Mpdec_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Mpdec_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void EigenLib_Mpdec_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpdec(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

void boost_Mpdec_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Mpdec_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpdec_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpdec_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Mpdec_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpdec_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpdec_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
void cplx_EigenLib_Mpdec_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpdec_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpdec_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpdec(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpdec_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpdec(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Mpdec_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Mpdec_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Mpdec_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Mpdec_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Mpdec_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Mpdec_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);


void cplx_EigenLib_Mpdec_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpdec_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpdec_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpdec(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpdec_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpdec_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_Mpdec_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpdec(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);




void boost_Mpq_ElementaryFunctions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void boost_Mpq_ElementaryFunctions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpq_ElementaryFunctions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpq_ElementaryFunctions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x4Ptr);
void boost_Mpq_DistributionFunctions2(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void boost_Mpq_DistributionFunctions3(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void boost_Mpq_DistributionFunctions4(long Dist, long Target, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);


void EigenLib_Mpq_SetPrecision(int prec);
void EigenLib_Mpq_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpq_Init(mpNumMatrixPtr* x);
void EigenLib_Mpq_Clear(mpNumMatrixPtr* x);

void EigenLib_Mpq_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpq_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);

void Std_Mpq_Functions0(long what, mpNumMatrixPtr yPtr);
void Std_Mpq_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpq_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void Std_Mpq_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
void Std_Mpq_Functions1_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr);
void Std_Mpq_Functions2_2Results(long what, mpNumMatrixPtr y0Ptr, mpNumMatrixPtr y1Ptr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);


void SetSpecialValue_Mpq(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Mpq_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpq(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);





void cplx_EigenLib_Mpq_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpq_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpq_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpq(long m, long n, long what, mpNumMatrixPtr xPtr);

void cplx_EigenLib_Mpq_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpq(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

//void mpMath_Mpq_Functions0(long what, mpNumMatrixPtr yPtr);
//void mpMath_Mpq_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
//void mpMath_Mpq_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
//void mpMath_Mpq_Functions3(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr);
//void mpMath_Mpq_Functions4(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr);
//void mpMath_Mpq_Functions5(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr, mpNumMatrixPtr x2Ptr, mpNumMatrixPtr x3Ptr, mpNumMatrixPtr x4Ptr);


void cplx_EigenLib_Mpq_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpq_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpq_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpq(long m, long n, long what, mpNumMatrixPtr xPtr);
void Std_Mpq_cplx_Functions1(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr);
void Std_Mpq_cplx_Functions2(long what, mpNumMatrixPtr yPtr, mpNumMatrixPtr x0Ptr, mpNumMatrixPtr x1Ptr);
void cplx_EigenLib_Mpq_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpq(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);








#endif // MPNUM_INTERNAL_H_INCLUDED
