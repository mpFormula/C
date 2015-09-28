#ifndef MPNUM_INTERNAL_H_INCLUDED
#define MPNUM_INTERNAL_H_INCLUDED

#include "mpNumC.h"

void EigenLib_Float_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Float_Init(mpNumMatrixPtr* x);
void EigenLib_Float_Clear(mpNumMatrixPtr* x);
void EigenLib_Float_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Float_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Float(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Float_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Float(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_Float_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Float_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Float_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Float(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Float_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Float(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);






void EigenLib_Double_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Double_Init(mpNumMatrixPtr* x);
void EigenLib_Double_Clear(mpNumMatrixPtr* x);
void EigenLib_Double_GetCoeff(double* Coeff, long row, long col, mpNumMatrixPtr SourceItem);

void EigenLib_Double_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Double_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void EigenLib_Double_SetStringIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, const char * SourceString);

void put_Block_Double(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);
void get_Block_Double(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);

void SetSpecialValue_Double(long m, long n, long what, mpNumMatrixPtr xPtr);
void SetSpecialValue1_Double(long m, long n, long what, mpNumMatrixPtr xPtr);
void SetSpecialValue2_Double(long Vertical, long Horizontal, long PartialMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr result);

void Stats2_Double(long what, long *IndexX, long *IndexY, mpNumMatrixPtr x1,  mpNumMatrixPtr y);
void Stats_Double(long PartialMode, long what,  mpNumMatrixPtr x, mpNumMatrixPtr y);
void Compare_Double(long CmpMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr y, long* result);

void BasicArithmetic_Double(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void BasicArithmetic_i_Double(long i, long what, mpNumMatrixPtr w, mpNumMatrixPtr y);

void EigenLib_Double_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
void EigenLib_Double_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void EigenLib_Double_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition);
void EigenLib_Double_Rank(mpNumMatrixPtr A, long Decomposition, long* rank);

void EigenLib_Double_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
void EigenLib_Double_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void EigenLib_Double_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
void EigenLib_Double_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void EigenLib_Double_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);


void cplx_EigenLib_Double_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Double_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Double_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Double(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_BasicArithmetic_Double(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);

void cplx_EigenLib_Double_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_EigenLib_Double_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition);
void cplx_EigenLib_Double_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A);
void cplx_EigenLib_Double_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void cplx_EigenLib_Double_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);
void cplx_EigenLib_Double_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A);
void cplx_EigenLib_Double_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A);




















void EigenLib_LongDouble_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_LongDouble_Init(mpNumMatrixPtr* x);
void EigenLib_LongDouble_Clear(mpNumMatrixPtr* x);
void EigenLib_LongDouble_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_LongDouble_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_LongDouble(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_LongDouble_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_LongDouble(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_LongDouble_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_LongDouble_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_LongDouble_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_LongDouble(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_LongDouble_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_LongDouble(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);




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



















//void EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
//void EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
//void EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);
//void EigenLib_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
//void EigenLib_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
//void SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
//void EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
//void BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
//void cplx_EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr);
//void cplx_EigenLib_Mpfr_Init(mpNumMatrixPtr* x);
//void cplx_EigenLib_Mpfr_Clear(mpNumMatrixPtr* x);
//void cplx_SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr);
//void cplx_EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
//void cplx_BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);











void EigenLib_Mpfi_SetPrecision(int prec);
void EigenLib_Mpfi_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpfi_Init(mpNumMatrixPtr* x);
void EigenLib_Mpfi_Clear(mpNumMatrixPtr* x);
void EigenLib_Mpfi_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpfi_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Mpfi(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Mpfi_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpfi(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_Mpfi_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpfi_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpfi_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpfi(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpfi_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpfi(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);



void EigenLib_Mpdec_SetPrecision(int prec);
void EigenLib_Mpdec_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpdec_Init(mpNumMatrixPtr* x);
void EigenLib_Mpdec_Clear(mpNumMatrixPtr* x);
void EigenLib_Mpdec_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpdec_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Mpdec(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Mpdec_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpdec(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_Mpdec_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpdec_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpdec_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpdec(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpdec_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpdec(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);





void EigenLib_Mpq_SetPrecision(int prec);
void EigenLib_Mpq_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Mpq_Init(mpNumMatrixPtr* x);
void EigenLib_Mpq_Clear(mpNumMatrixPtr* x);
void EigenLib_Mpq_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Mpq_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Mpq(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Mpq_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Mpq(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_Mpq_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpq_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Mpq_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Mpq(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Mpq_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Mpq(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);




void EigenLib_Arb_SetPrecision(int prec);
void EigenLib_Arb_Print(const char * Title, mpNumMatrixPtr xPtr);
void EigenLib_Arb_Init(mpNumMatrixPtr* x);
void EigenLib_Arb_Clear(mpNumMatrixPtr* x);
void EigenLib_Arb_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem);
void EigenLib_Arb_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix);
void SetSpecialValue_Arb(long m, long n, long what, mpNumMatrixPtr xPtr);
void EigenLib_Arb_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void BasicArithmetic_Arb(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);
void cplx_EigenLib_Arb_Print(const char * Title, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Arb_Init(mpNumMatrixPtr* x);
void cplx_EigenLib_Arb_Clear(mpNumMatrixPtr* x);
void cplx_SetSpecialValue_Arb(long m, long n, long what, mpNumMatrixPtr xPtr);
void cplx_EigenLib_Arb_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition);
void cplx_BasicArithmetic_Arb(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr);




#endif // MPNUM_INTERNAL_H_INCLUDED
