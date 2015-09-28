
#define Use_Mpfr

#include "mpNum_Internal.h"
#include "libEigen.h"



void EigenLib_Mpfr_SetPrecision(int prec)
{
    EigenLib_mpfr_SetPrecision(prec * 3.34);
}



void EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr)
{
    EigenLib_mpType_Print(Title, (mpMatrixPtr) xPtr);
}

void EigenLib_Mpfr_Init(mpNumMatrixPtr* x)
{
    EigenLib_mpType_Init((mpMatrixPtr*) x);
}

void EigenLib_Mpfr_Clear(mpNumMatrixPtr* x)
{
    EigenLib_mpType_Clear((mpMatrixPtr*) x);
}

//void EigenLib_Mpfr_GetCoeff(double* Coeff, long row, long col, mpNumMatrixPtr SourceItem)
//{
//    EigenLib_mpType_GetCoeff(Coeff, row, col,  (mpMatrixPtr) SourceItem);
//}



void EigenLib_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem)
{
    EigenLib_mpType_SetItemIntoMatrix((mpMatrixPtr) DestMatrix, row, col, (mpMatrixPtr) SourceItem);
}


void EigenLib_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix)
{
    EigenLib_mpType_GetItemFromMatrix((mpMatrixPtr) DestItem, row, col, (mpMatrixPtr) SourceMatrix);
}

void EigenLib_Mpfr_SetStringIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, const char * SourceString)
{
    EigenLib_mpType_SetStringIntoMatrix((mpMatrixPtr) DestMatrix, row, col, SourceString);
}



void put_Block_Mpfr(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result)
{
    put_Block_mpType(i, j, p, q,  what, (mpMatrixPtr) x, (mpMatrixPtr) result);
}


void get_Block_Mpfr(long i, long j, long p, long q, long what, mpNumMatrixPtr x, mpNumMatrixPtr result)
{
    get_Block_mpType(i, j, p, q,  what, (mpMatrixPtr) x, (mpMatrixPtr) result);
}



void SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue_mpType(m, n, what, (mpMatrixPtr) xPtr);
}


void SetSpecialValue1_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue1_mpType(m, n, what, (mpMatrixPtr) xPtr);
}



void SetSpecialValue2_Mpfr(long Vertical, long Horizontal, long PartialMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr result)
{
    SetSpecialValue2_mpType(Vertical, Horizontal, PartialMode, what, (mpMatrixPtr) x, (mpMatrixPtr) result);
}




void Stats2_Mpfr(long what, long *IndexX, long *IndexY, mpNumMatrixPtr x1,  mpNumMatrixPtr y)
{
    Stats2_mpType(what, IndexX, IndexY, (mpMatrixPtr) x1, (mpMatrixPtr) y);
}



void Stats_Mpfr(long PartialMode, long what,  mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    Stats_mpType(PartialMode, what, (mpMatrixPtr) x, (mpMatrixPtr) y);
}



void Compare_Mpfr(long CmpMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr y, long* result)
{
    Compare_mpType(CmpMode, what, (mpMatrixPtr) x, (mpMatrixPtr) y, result);
}


void BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
{
    BasicArithmetic_mpType(what, (mpMatrixPtr) mPtr, (mpMatrixPtr) xPtr, (mpMatrixPtr) zPtr);
}


void BasicArithmetic_i_Mpfr(int32_t i, long what, mpMatrixPtr w, mpMatrixPtr y)
{
    BasicArithmetic_i_mpType(i, what, (mpMatrixPtr) w, (mpMatrixPtr) y);
}



void EigenLib_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition)
{
    EigenLib_mpType_Solve2((mpMatrixPtr) x, (mpMatrixPtr) A,  (mpMatrixPtr) b, Decomposition);
}



void EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
{
    EigenLib_mpType_Inverse((mpMatrixPtr) xPtr, (mpMatrixPtr) mPtr, Decomposition);
}


void EigenLib_Mpfr_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition)
{
    EigenLib_mpType_Det((mpMatrixPtr) x, (mpMatrixPtr) A, Decomposition);
}


void EigenLib_Mpfr_Rank(mpNumMatrixPtr A, long Decomposition, long* rank)
{
    EigenLib_mpType_Rank( (mpMatrixPtr) A, Decomposition, rank);
}



void EigenLib_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A)
{
    EigenLib_mpType_JacobiSVD_Full((mpMatrixPtr) s, (mpMatrixPtr) u,  (mpMatrixPtr) v, (mpMatrixPtr) A);
}


void EigenLib_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_mpType_SelfAdjointEigenValues((mpMatrixPtr) x, (mpMatrixPtr) A);
}


void EigenLib_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_mpType_SelfAdjointEigenSystem((mpMatrixPtr) x, (mpMatrixPtr) y,  (mpMatrixPtr) A);
}


void EigenLib_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_mpType_EigenValues((mpCplxMatrixPtr) x, (mpMatrixPtr) A);
}


void EigenLib_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_mpType_EigenSystem((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpMatrixPtr) A);
}





void cplx_EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr)
{
    EigenLib_cplx_mpType_Print(Title, (mpCplxMatrixPtr) xPtr);
}

void cplx_EigenLib_Mpfr_Init(mpNumMatrixPtr* x)
{
    EigenLib_cplx_mpType_Init((mpCplxMatrixPtr*) x);
}

void cplx_EigenLib_Mpfr_Clear(mpNumMatrixPtr* x)
{
    EigenLib_cplx_mpType_Clear((mpCplxMatrixPtr*) x);
}

void cplx_SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue_cplx_mpType(m, n, what, (mpCplxMatrixPtr) xPtr);
}


void cplx_BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
{
    BasicArithmetic_cplx_mpType(what, (mpCplxMatrixPtr) mPtr, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) zPtr);
}




void cplx_EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
{
    EigenLib_cplx_mpType_Inverse((mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) mPtr, Decomposition);
}


void cplx_EigenLib_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition)
{
    EigenLib_cplx_mpType_Solve2((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) A, (mpCplxMatrixPtr) b, Decomposition);
}


void cplx_EigenLib_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_JacobiSVD_Full((mpMatrixPtr) s, (mpCplxMatrixPtr) u,  (mpCplxMatrixPtr) v, (mpCplxMatrixPtr) A);
}


void cplx_EigenLib_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_SelfAdjointEigenValues((mpMatrixPtr) x, (mpCplxMatrixPtr) A);
}


void cplx_EigenLib_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_SelfAdjointEigenSystem((mpMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpCplxMatrixPtr) A);
}


void cplx_EigenLib_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_EigenValues((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) A);
}


void cplx_EigenLib_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_EigenSystem((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpCplxMatrixPtr) A);
}










//
//
//void EigenLib_Mpfr_SetPrecision(int prec)
//{
//    EigenLib_mpfr_SetPrecision(prec * 3.34);
//}
//
//
//void EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr)
//{
//    EigenLib_mpType_Print(Title, (mpMatrixPtr) xPtr);
//}
//
//void EigenLib_Mpfr_Init(mpNumMatrixPtr* x)
//{
//    EigenLib_mpType_Init((mpMatrixPtr*) x);
//}
//
//void EigenLib_Mpfr_Clear(mpNumMatrixPtr* x)
//{
//    EigenLib_mpType_Clear((mpMatrixPtr*) x);
//}
//
//void SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr)
//{
//    SetSpecialValue_mpType(m, n, what, (mpMatrixPtr) xPtr);
//}
//
//
//
//void EigenLib_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem)
//{
//    EigenLib_mpType_SetItemIntoMatrix((mpMatrixPtr) DestMatrix, row, col, (mpMatrixPtr) SourceItem);
//}
//
//
//void EigenLib_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix)
//{
//    EigenLib_mpType_GetItemFromMatrix((mpMatrixPtr) DestItem, row, col, (mpMatrixPtr) SourceMatrix);
//}
//
//
//
//void EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
//{
//    EigenLib_mpType_Inverse((mpMatrixPtr) xPtr, (mpMatrixPtr) mPtr, Decomposition);
//}
//
//void BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
//{
//    BasicArithmetic_mpType(what, (mpMatrixPtr) mPtr, (mpMatrixPtr) xPtr, (mpMatrixPtr) zPtr);
//}
//
//
//
//
//void cplx_EigenLib_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr)
//{
//    EigenLib_cplx_mpType_Print(Title, (mpCplxMatrixPtr) xPtr);
//}
//
//void cplx_EigenLib_Mpfr_Init(mpNumMatrixPtr* x)
//{
//    EigenLib_cplx_mpType_Init((mpCplxMatrixPtr*) x);
//}
//
//void cplx_EigenLib_Mpfr_Clear(mpNumMatrixPtr* x)
//{
//    EigenLib_cplx_mpType_Clear((mpCplxMatrixPtr*) x);
//}
//
//void cplx_SetSpecialValue_Mpfr(long m, long n, long what, mpNumMatrixPtr xPtr)
//{
//    SetSpecialValue_cplx_mpType(m, n, what, (mpCplxMatrixPtr) xPtr);
//}
//
//
//
//void cplx_EigenLib_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
//{
//    EigenLib_cplx_mpType_Inverse((mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) mPtr, Decomposition);
//}
//
//void cplx_BasicArithmetic_Mpfr(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
//{
//    BasicArithmetic_cplx_mpType(what, (mpCplxMatrixPtr) mPtr, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) zPtr);
//}
//


#undef  Use_Mpfr
