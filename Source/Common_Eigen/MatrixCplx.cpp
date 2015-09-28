
#include "libEigen.h"


void EigenLib_cplx_mpType_GetCoeff(cplx_mpType* Coeff, long row, long col, mpMatrixC *x)
{
    (*Coeff) = (*x).coeff(row,col);
}

void EigenLib_cplx_mpType_Init(mpCplxMatrixPtr* x)
{
    (*x) = new(mpMatrixC);
}

void EigenLib_cplx_mpType_Clear(mpCplxMatrixPtr x)
{
    delete (x);
}


void EigenLib_cplx_to_2reals_mpType(mpMatrix* RealDestMatrix, mpMatrix* ImagDestMatrix, mpCplxMatrixPtr CplxSourceMatrix)
{
    int mRows = CplxSourceMatrix->rows();
    int mCols = CplxSourceMatrix->cols();
    for (int i=0; i<mRows; i++)
    {
        for (int j=0; j<mCols; j++)
        {
            (*RealDestMatrix)(i,j) = real((*CplxSourceMatrix)(i,j)) ;
            (*ImagDestMatrix)(i,j) = imag((*CplxSourceMatrix)(i,j)) ;
        }
    }
}



void EigenLib_2reals_to_cplx_mpType(mpCplxMatrixPtr CplxDestMatrix, mpMatrix* RealSourceMatrix, mpMatrix* ImagSourceMatrix)
{
    int mRows = RealSourceMatrix->rows();
    int mCols = RealSourceMatrix->cols();
    for (int i=0; i<mRows; i++)
    {
        for (int j=0; j<mCols; j++)
        {
            (*CplxDestMatrix)(i,j) = std::complex<mpType> ((*RealSourceMatrix)(i,j), (*ImagSourceMatrix)(i,j));
        }
    }
}



void EigenLib_cplx_mpType_Print(const char * Title, mpCplxMatrixPtr xPtr)
{
    int mRows = xPtr->rows();
    int mCols = xPtr->cols();
    cplx_mpType x;
        printf ("\n");
    printf (Title);
        printf ("\n");
    #if defined (Use_Mpfi)
        mpfr_t real_fL;
        mpfr_init(real_fL);
        mpfr_t real_fR;
        mpfr_init(real_fR);

        mpfr_t imag_fL;
        mpfr_init(imag_fL);
        mpfr_t imag_fR;
        mpfr_init(imag_fR);
    #endif // defined (Use_Mpfi)

    for (int i=1; i<=mRows; i++)
    {
        for (int j=1; j<=mCols; j++)
        {
            EigenLib_cplx_mpType_GetCoeff(&x, i-1, j-1, xPtr);
            #if defined (Use_Float)
            __mingw_printf("(%.8E,%.8E) ", real(x), imag(x));
            #endif
            #if defined (Use_Double)
            __mingw_printf("(%.16E,%.16E) ", real(x), imag(x));
            #endif
            #if defined  (Use_LongDouble)
             __mingw_printf("(%.20LE,%.20LE) ", real(x), imag(x));
            #endif
            #if defined (Use_Mpfr)
                mpfr_printf("(%.RE,%.RE) ", real(x).mpfr_ptr(), imag(x).mpfr_ptr());
            #endif

            #if defined (Use_Mpfi)
                mpfi_get_left(real_fL, real(x).mpfi_ptr());
                mpfi_get_right(real_fR, real(x).mpfi_ptr());
                mpfi_get_left(imag_fL, imag(x).mpfi_ptr());
                mpfi_get_right(imag_fR, imag(x).mpfi_ptr());
                mpfr_printf("([%.RE,%.RE] [%.RE,%.RE]) ", real_fL, real_fR, imag_fL, imag_fR);
            #endif
            #if defined (Use_Mpdec)
                char *s1 = mpd_to_sci(real(x).mpd_ptr(), 1);
                char *s2 = mpd_to_sci(imag(x).mpd_ptr(), 1);
                printf("(%s,%s)", s1, s2);
                mpd_free(s1);
                mpd_free(s2);
            #endif
         }
         printf("\n");
    }
    #if defined (Use_Mpfi)
        mpfr_clear(real_fL);
        mpfr_clear(real_fR);
        mpfr_clear(imag_fL);
        mpfr_clear(imag_fR);
    #endif // defined (Use_Mpfi)

}






void SetSpecialValue_cplx_mpType(int32_t m, int32_t n, long what, mpMatrixC *x)
{
	switch (what) {
		case mp_setZero: (*x).setZero() ; break;
		case mp_setOnes: (*x).setOnes() ; break;
		case mp_setIdentity: (*x).setIdentity() ; break;
		case mp_setRandom: (*x).setRandom() ; break;
		case mp_transposeInPlace: (*x).transposeInPlace() ; break;
		case mp_reverseInPlace: (*x).reverseInPlace() ; break;
		case mp_Resize: (*x).resize(n, m); break;
		case mp_conservativeResize: (*x).conservativeResize(n, m); break;
		case mp_setRandom_nm: (*x) =  mpMatrixC::Random(n, m); break;
		case mp_FillLinear: {
			for (int j = 0; j < (*x).rows(); j++) {
				(*x)(j, 0) = (float) m + (j) * 1000;
				for (int i = 1; i < (*x).cols(); i++) { (*x)(j, i) = (*x)(j, i - 1) + (mpType) n;}}
			}
		break;
	}
}



void BasicArithmetic_cplx_mpType(long what, mpMatrixC *w, mpMatrixC *x, mpMatrixC *y)
{
	cplx_mpType f = (*x)(0,0);
//	cplx_mpType f1 = (1.0)/f;
	switch (what){
		case mp_const_plus: *y = (*w) + (*x); break;
		case mp_const_minus: *y = (*w) - (*x); break;
		case mp_const_cwiseProduct: *y = (*w).cwiseProduct(*x); break;
		case mp_const_cwiseQuotient: *y = (*w).cwiseQuotient(*x); break;
		case mp_const_MatrixProduct: (*y) = (*w) * (*x); break;
		case mp_const_DotProduct: (*y)(0,0) = (*w).col(0).dot(((*x).col(0))); break;
		case mp_const_plus_scalar: *y = f + (*w).array() ; break;
		case mp_const_minus_scalar: *y = -f + (*w).array() ; break;
		case mp_const_times_scalar: *y = f * (*w).array() ; break;
		case mp_const_div_scalar: *y = f * (*w).array()  ; break;
	}
}


