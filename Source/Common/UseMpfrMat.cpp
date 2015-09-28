
#if defined (USE_EIGEN)
#define Use_Mpfr

#include "mpNumC_Short.h"
#include "libEigen.h"
#include <mpc.h>

void Lib_Eigen_Mpfr_SetPrecision(int prec)
{
    EigenLib_mpfr_SetPrecision(prec * 3.34);
}



void Lib_Eigen_Mpfr_Print(const char * Title, mpNumMatrixPtr xPtr)
{
    EigenLib_mpType_Print(Title, (mpMatrixPtr) xPtr);
}

void Lib_Eigen_Mpfr_Init(mpNumMatrixPtr* x)
{
    EigenLib_mpType_Init((mpMatrixPtr*) x);
}

void Lib_Eigen_Mpfr_Clear(mpNumMatrixPtr x)
{
    EigenLib_mpType_Clear((mpMatrixPtr) x);
}


void Lib_Eigen_Mpfr_GetCoeff2(MpfrPtr res, long row, long col, mpNumMatrixPtr SourceMatrix)
{
    mpfr_set((mpfr_ptr)res, ((mpMatrixPtr) SourceMatrix)->coeff(row,col).mpfr_ptr(), mpfr_get_default_rounding_mode ());
}


void Lib_Eigen_Mpfr_SetCoeff2(MpfrPtr src, long row, long col, mpNumMatrixPtr DestMatrix)
{
     mpfr_set((mpfr_ptr)(((mpMatrixPtr) DestMatrix)->coeff(row,col).mpfr_ptr()), (mpfr_ptr)src, mpfr_get_default_rounding_mode ());
}


uint32_t Lib_Eigen_Mpfr_GetRows(mpNumMatrixPtr Matrix)
{
     return ((mpMatrixPtr) (Matrix))->rows();
}


uint32_t Lib_Eigen_Mpfr_GetCols(mpNumMatrixPtr Matrix)
{
     return ((mpMatrixPtr) (Matrix))->cols();
}


uint32_t Lib_Eigen_Mpfr_GetSize(mpNumMatrixPtr Matrix)
{
     return ((mpMatrixPtr) (Matrix))->size();
}

//
//void Lib_Eigen_Mpfr_SetItemIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, mpNumMatrixPtr SourceItem)
//{
//    EigenLib_mpType_SetItemIntoMatrix((mpMatrixPtr) DestMatrix, row, col, (mpMatrixPtr) SourceItem);
//}
//
//
//void Lib_Eigen_Mpfr_GetItemFromMatrix(mpNumMatrixPtr DestItem, long row, long col, mpNumMatrixPtr SourceMatrix)
//{
//    EigenLib_mpType_GetItemFromMatrix((mpMatrixPtr) DestItem, row, col, (mpMatrixPtr) SourceMatrix);
//}
//
//void Lib_Eigen_Mpfr_SetStringIntoMatrix(mpNumMatrixPtr DestMatrix, long row, long col, const char * SourceString)
//{
//    EigenLib_mpType_SetStringIntoMatrix((mpMatrixPtr) DestMatrix, row, col, SourceString);
//}



void Lib_Eigen_Mpfr_Get_Block(mpNumMatrixPtr result, long i, long j, long p, long q, mpNumMatrixPtr source)
{
    get_Block_mpType(i, j, p, q,  mp_const_block, (mpMatrixPtr) source, (mpMatrixPtr) result);
}


void Lib_Eigen_Mpfr_Put_Block(mpNumMatrixPtr source, long i, long j, long p, long q, mpNumMatrixPtr result)
{
    put_Block_mpType(i, j, p, q,  mp_const_block, (mpMatrixPtr) result, (mpMatrixPtr) source);
}



//*************************************************************************************



void Lib_Eigen_Mpfr_Resize(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_mpType(rows, cols, mp_Resize, (mpMatrixPtr) Res);
}



void Lib_Eigen_Mpfr_Conservative_Resize(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_mpType(rows, cols, mp_conservativeResize, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_SetRandom(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_mpType(rows, cols, mp_setRandom_nm, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_SetRandomSymmetric(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_mpType(rows, cols, mp_setRandomSymmetric, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_SetSpecialValue(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue_mpType(m, n, what, (mpMatrixPtr) xPtr);
}

//*************************************************************************************



void Lib_Eigen_Mpfr_SetSpecialValue1(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue1_mpType(m, n, what, (mpMatrixPtr) xPtr);
}



void Lib_Eigen_Mpfr_SetSpecialValue2(long Vertical, long Horizontal, long PartialMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr result)
{
    SetSpecialValue2_mpType(Vertical, Horizontal, PartialMode, what, (mpMatrixPtr) x, (mpMatrixPtr) result);
}




void Lib_Eigen_Mpfr_Stats2(long what, long *IndexX, long *IndexY, mpNumMatrixPtr x1,  mpNumMatrixPtr y)
{
    Stats2_mpType(what, IndexX, IndexY, (mpMatrixPtr) x1, (mpMatrixPtr) y);
}



void Lib_Eigen_Mpfr_Stats(long PartialMode, long what,  mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    Stats_mpType(PartialMode, what, (mpMatrixPtr) x, (mpMatrixPtr) y);
}


//*************************************************************************************




uint32_t Lib_Eigen_Mpfr_GT_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_GT, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}




uint32_t Lib_Eigen_Mpfr_LT_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_LT, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}



uint32_t Lib_Eigen_Mpfr_LE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_LE, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}



uint32_t Lib_Eigen_Mpfr_GE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_GE, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}



uint32_t Lib_Eigen_Mpfr_EQ_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_EQ, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}


uint32_t Lib_Eigen_Mpfr_NE_Count(mpNumMatrixPtr x, mpNumMatrixPtr y)
{
    long result;
    Compare_mpType(mp_const_Count, mp_const_NE, (mpMatrixPtr) x, (mpMatrixPtr) y, &result);
    return (uint32_t) result;
}


void Lib_Eigen_Mpfr_Compare(long CmpMode, long what, mpNumMatrixPtr x, mpNumMatrixPtr y, long* result)
{
    Compare_mpType(CmpMode, what, (mpMatrixPtr) x, (mpMatrixPtr) y, result);
}


//*************************************************************************************


void Lib_Eigen_Mpfr_MatAdd(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_plus, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_MatSub(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_minus, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_Mat_cwiseProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_cwiseProduct, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}


void Lib_Eigen_Mpfr_Mat_cwiseQuotient(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_cwiseQuotient, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}



void Lib_Eigen_Mpfr_MatMul(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_MatrixProduct, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}



void Lib_Eigen_Mpfr_MatDotProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_DotProduct, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}




void Lib_Eigen_Mpfr_Mat_Add_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_plus_scalar, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}

void Lib_Eigen_Mpfr_Mat_Sub_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_minus_scalar, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}

void Lib_Eigen_Mpfr_Mat_Mul_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_times_scalar, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}

void Lib_Eigen_Mpfr_Mat_Div_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_mpType(mp_const_div_scalar, (mpMatrixPtr) xPtr, (mpMatrixPtr) yPtr, (mpMatrixPtr) Res);
}






void Lib_Eigen_Mpfr_BasicArithmetic(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
{
    BasicArithmetic_mpType(what, (mpMatrixPtr) mPtr, (mpMatrixPtr) xPtr, (mpMatrixPtr) zPtr);
}



//*************************************************************************************



void Lib_Eigen_Mpfr_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition)
{
    EigenLib_mpType_Solve2((mpMatrixPtr) x, (mpMatrixPtr) A,  (mpMatrixPtr) b, Decomposition);
}



void Lib_Eigen_Mpfr_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
{
    EigenLib_mpType_Inverse((mpMatrixPtr) xPtr, (mpMatrixPtr) mPtr, Decomposition);
}


void Lib_Eigen_Mpfr_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition)
{
    EigenLib_mpType_Det((mpMatrixPtr) x, (mpMatrixPtr) A, Decomposition);
}


int32_t Lib_Eigen_Mpfr_Rank(mpNumMatrixPtr A, long Decomposition)
{
    long result;
    EigenLib_mpType_Rank( (mpMatrixPtr) A, Decomposition, &result);
    return result;
}


//
//void Lib_Eigen_Mpfr_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A)
//{
//    EigenLib_mpType_JacobiSVD_Full((mpMatrixPtr) s, (mpMatrixPtr) u,  (mpMatrixPtr) v, (mpMatrixPtr) A);
//}
//

void Lib_Eigen_Mpfr_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_mpType_SelfAdjointEigenValues((mpMatrixPtr) x, (mpMatrixPtr) A);
}


void Lib_Eigen_Mpfr_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_mpType_SelfAdjointEigenSystem((mpMatrixPtr) x, (mpMatrixPtr) y,  (mpMatrixPtr) A);
}

//
//void Lib_Eigen_Mpfr_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
//{
//    EigenLib_mpType_EigenValues((mpCplxMatrixPtr) x, (mpMatrixPtr) A);
//}
//
//
//void Lib_Eigen_Mpfr_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
//{
//    EigenLib_mpType_EigenSystem((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpMatrixPtr) A);
//}
//
//
//






//*************************************************************************************
//*************************************************************************************
//*************************************************************************************
//*************************************************************************************






void Lib_Eigen_Mpfc_Print(const char * Title, mpNumMatrixPtr xPtr)
{
    EigenLib_cplx_mpType_Print(Title, (mpCplxMatrixPtr) xPtr);
}

void Lib_Eigen_Mpfc_Init(mpNumMatrixPtr* x)
{
    EigenLib_cplx_mpType_Init((mpCplxMatrixPtr*) x);
}

void Lib_Eigen_Mpfc_Clear(mpNumMatrixPtr x)
{
    EigenLib_cplx_mpType_Clear((mpCplxMatrixPtr) x);
}



void Lib_Eigen_Complex_To_2Reals(mpNumMatrixPtr RealDestMatrix, mpNumMatrixPtr ImagDestMatrix, mpNumMatrixPtr CplxSourceMatrix)
{
    EigenLib_cplx_to_2reals_mpType( (mpMatrix*) RealDestMatrix, (mpMatrix*) ImagDestMatrix, (mpCplxMatrixPtr) CplxSourceMatrix);
}



void Lib_Eigen_2Reals_To_Complex(mpNumMatrixPtr CplxDestMatrix, mpNumMatrixPtr RealSourceMatrix, mpNumMatrixPtr ImagSourceMatrix)
{
    EigenLib_2reals_to_cplx_mpType( (mpCplxMatrixPtr) CplxDestMatrix, (mpMatrix*) RealSourceMatrix, (mpMatrix*) ImagSourceMatrix);
}









void Lib_Eigen_Mpfc_GetCoeff2a(MpfcPtr res, long row, long col, mpNumMatrixPtr SourceMatrix)
{
    int32_t rnd = mpfr_get_default_rounding_mode();
    mpfr_t Re; mpfr_init(Re);
    mpfr_t Im; mpfr_init(Im);

    mpfr_set(Re, real(((mpCplxMatrixPtr) SourceMatrix)->coeff(row,col)).mpfr_ptr(),(mpfr_rnd_t) rnd);
    mpfr_set(Im, imag(((mpCplxMatrixPtr) SourceMatrix)->coeff(row,col)).mpfr_ptr(), (mpfr_rnd_t)rnd);

    Lib_Mpfc_Set_Real(res, Re, (mpfr_rnd_t)rnd);
    Lib_Mpfc_Set_Imag(res, Im, (mpfr_rnd_t)rnd);

    mpfr_clear(Re);
    mpfr_clear(Im);
}


//void Lib_Eigen_Mpfc_GetCoeff2(MpfrPtr res_re, MpfrPtr res_im, long row, long col, mpNumMatrixPtr SourceMatrix)
//{
//    mpfr_set((mpfr_ptr)res_re, real(((mpCplxMatrixPtr) SourceMatrix)->coeff(row,col)).mpfr_ptr(), mpfr_get_default_rounding_mode());
//    mpfr_set((mpfr_ptr)res_im, imag(((mpCplxMatrixPtr) SourceMatrix)->coeff(row,col)).mpfr_ptr(), mpfr_get_default_rounding_mode());
//}



void Lib_Eigen_Mpfc_SetCoeff2a(MpfcPtr src,  long row, long col, mpNumMatrixPtr DestMatrix)
{
    int32_t rnd = mpfr_get_default_rounding_mode();
    mpfr_t Re; mpfr_init(Re);
    mpfr_t Im; mpfr_init(Im);
//
//    Lib_Mpfc_Get_Real(Re, src, (mpfr_rnd_t)rnd);
//    Lib_Mpfc_Get_Imag(Im, src, (mpfr_rnd_t)rnd);


    mpfr_set_ui(Re, 9999,(mpfr_rnd_t) rnd);
    mpfr_set_ui(Im, 9999,(mpfr_rnd_t) rnd);


    mpfr_set((mpfr_ptr) (real(((mpCplxMatrixPtr) DestMatrix)->coeff(row,col)).mpfr_ptr()), Re, (mpfr_rnd_t) rnd);
    mpfr_set((mpfr_ptr) (imag(((mpCplxMatrixPtr) DestMatrix)->coeff(row,col)).mpfr_ptr()), Im, (mpfr_rnd_t) rnd);

    mpfr_clear(Re);
    mpfr_clear(Im);
}



//
//void Lib_Eigen_Mpfc_SetCoeff2(MpfrPtr src_re, MpfrPtr src_im, long row, long col, mpNumMatrixPtr DestMatrix)
//{
//    mpfr_set((mpfr_ptr) (real(((mpCplxMatrixPtr) DestMatrix)->coeff(row,col)).mpfr_ptr()), (mpfr_ptr)src_re, mpfr_get_default_rounding_mode ());
//    mpfr_set((mpfr_ptr) (imag(((mpCplxMatrixPtr) DestMatrix)->coeff(row,col)).mpfr_ptr()), (mpfr_ptr)src_im, mpfr_get_default_rounding_mode ());
//}



uint32_t Lib_Eigen_Mpfc_GetRows(mpNumMatrixPtr Matrix)
{
     return ((mpCplxMatrixPtr) (Matrix))->rows();
}


uint32_t Lib_Eigen_Mpfc_GetCols(mpNumMatrixPtr Matrix)
{
     return ((mpCplxMatrixPtr) (Matrix))->cols();
}


uint32_t Lib_Eigen_Mpfc_GetSize(mpNumMatrixPtr Matrix)
{
     return ((mpCplxMatrixPtr) (Matrix))->size();
}






//*************************************************************************************



void Lib_Eigen_Mpfc_Resize(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_cplx_mpType(rows, cols, mp_Resize, (mpCplxMatrixPtr) Res);
}



void Lib_Eigen_Mpfc_Conservative_Resize(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_cplx_mpType(rows, cols, mp_conservativeResize, (mpCplxMatrixPtr) Res);
}


void Lib_Eigen_Mpfc_SetRandom(mpNumMatrixPtr Res, long rows, long cols)
{
    SetSpecialValue_cplx_mpType(rows, cols, mp_setRandom_nm, (mpCplxMatrixPtr) Res);
}


void Lib_Eigen_Mpfc_SetSpecialValue(long m, long n, long what, mpNumMatrixPtr xPtr)
{
    SetSpecialValue_cplx_mpType(m, n, what, (mpCplxMatrixPtr) xPtr);
}

//*************************************************************************************




//*************************************************************************************


void Lib_Eigen_Mpfc_MatAdd(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_plus, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}


void Lib_Eigen_Mpfc_MatSub(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_minus, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}


void Lib_Eigen_Mpfc_Mat_cwiseProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_cwiseProduct, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}


void Lib_Eigen_Mpfc_Mat_cwiseQuotient(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_cwiseQuotient, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}



void Lib_Eigen_Mpfc_MatMul(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_MatrixProduct, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}



void Lib_Eigen_Mpfc_MatDotProduct(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_DotProduct, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}




void Lib_Eigen_Mpfc_Mat_Add_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_plus_scalar, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}

void Lib_Eigen_Mpfc_Mat_Sub_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_minus_scalar, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}

void Lib_Eigen_Mpfc_Mat_Mul_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_times_scalar, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}

void Lib_Eigen_Mpfc_Mat_Div_Scalar(mpNumMatrixPtr Res, mpNumMatrixPtr xPtr, mpNumMatrixPtr yPtr)
{
    BasicArithmetic_cplx_mpType(mp_const_div_scalar, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) yPtr, (mpCplxMatrixPtr) Res);
}






void Lib_Eigen_Mpfc_BasicArithmetic(long what, mpNumMatrixPtr mPtr, mpNumMatrixPtr xPtr, mpNumMatrixPtr zPtr)
{
    BasicArithmetic_cplx_mpType(what, (mpCplxMatrixPtr) mPtr, (mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) zPtr);
}



//*************************************************************************************











void Lib_Eigen_Mpfc_Inverse(mpNumMatrixPtr xPtr, mpNumMatrixPtr mPtr, long Decomposition)
{
    EigenLib_cplx_mpType_Inverse((mpCplxMatrixPtr) xPtr, (mpCplxMatrixPtr) mPtr, Decomposition);
}


void Lib_Eigen_Mpfc_Det(mpNumMatrixPtr x, mpNumMatrixPtr A, long Decomposition)
{
    EigenLib_cplx_mpType_Det((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) A, Decomposition);
}



//
//void Lib_Eigen_Mpfc_Solve2(mpNumMatrixPtr x, mpNumMatrixPtr A, mpNumMatrixPtr b, long Decomposition)
//{
//    EigenLib_cplx_mpType_Solve2((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) A, (mpCplxMatrixPtr) b, Decomposition);
//}
//

void Lib_Eigen_Mpfc_JacobiSVD_Full(mpNumMatrixPtr s, mpNumMatrixPtr u, mpNumMatrixPtr v, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_JacobiSVD_Full((mpMatrixPtr) s, (mpCplxMatrixPtr) u,  (mpCplxMatrixPtr) v, (mpCplxMatrixPtr) A);
}

//
//void Lib_Eigen_Mpfc_SelfAdjointEigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
//{
//    EigenLib_cplx_mpType_SelfAdjointEigenValues((mpMatrixPtr) x, (mpCplxMatrixPtr) A);
//}
//
//
//void Lib_Eigen_Mpfc_SelfAdjointEigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
//{
//    EigenLib_cplx_mpType_SelfAdjointEigenSystem((mpMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpCplxMatrixPtr) A);
//}


void Lib_Eigen_Mpfc_EigenValues(mpNumMatrixPtr x, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_EigenValues((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) A);
}


void Lib_Eigen_Mpfc_EigenSystem(mpNumMatrixPtr x, mpNumMatrixPtr y, mpNumMatrixPtr A)
{
    EigenLib_cplx_mpType_EigenSystem((mpCplxMatrixPtr) x, (mpCplxMatrixPtr) y,  (mpCplxMatrixPtr) A);
}


#undef  Use_Mpfr
#endif
