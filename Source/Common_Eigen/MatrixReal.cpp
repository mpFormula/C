
#include "libEigen.h"


void EigenLib_mpType_GetCoeff(mpType* Coeff, long row, long col, mpMatrix *x)
{
    (*Coeff) = (*x).coeff(row,col);
}



void EigenLib_mpType_GetCoeff2(mpType Coeff, long row, long col, mpMatrix *x)
{
    (Coeff) = (*x)(row,col);
}




void EigenLib_mpType_SetCoeff2(mpType Coeff, long row, long col, mpMatrix *DestMatrix)
{
    (*DestMatrix)(row,col) = Coeff ;
}


void EigenLib_mpType_SetItemIntoMatrix(mpMatrix *DestMatrix, long row, long col, mpMatrix *SourceItem)
{
    (*DestMatrix).block(row-1, col-1, 1, 1) = (*SourceItem).topLeftCorner(1, 1) ;
}

void EigenLib_mpType_GetItemFromMatrix(mpMatrix *DestItem, long row, long col, mpMatrix *SourceMatrix)
{
    (*DestItem).topLeftCorner(1, 1) = (*SourceMatrix).block(row-1, col-1, 1, 1);
}



void EigenLib_mpType_Init(mpMatrixPtr* x)
{
    (*x) = new(mpMatrix);
    (*(*x)).resize(1, 1);
    (*(*x)).setZero();
}

void EigenLib_mpType_Clear(mpMatrixPtr x)
{
    delete (x);
}




void EigenLib_mpType_SetStringIntoMatrix(mpMatrix *DestMatrix, long row, long col, const char * SourceString)
{
    mpType x;
#if defined (Use_Float) || defined (Use_Double) || defined (Use_LongDouble)

    x=atof(SourceString);
#endif

#if defined (Use_Mpfr) || defined (Use_Mpfi) || defined (Use_Mpdec) || defined (Use_Mpq)
    x=SourceString;
#endif
    (*DestMatrix)(0, 0) = x ;
}


void EigenLib_mpType_SetDoubleIntoMatrix(mpMatrix *DestMatrix, long row, long col, const double SourceDouble)
{
   char output[50];
   snprintf(output,50,"%f",SourceDouble);
   EigenLib_mpType_SetStringIntoMatrix(DestMatrix, row, col, output);
}




void EigenLib_mpType_Print(const char * Title, mpMatrixPtr xPtr)
{
    int mRows = xPtr->rows();
    int mCols = xPtr->cols();
    mpType x;
    printf ("\n");
    printf (Title);
    printf ("\n");
    #if defined (Use_Mpfi)
        mpfr_t fL;
        mpfr_init(fL);
        mpfr_t fR;
        mpfr_init(fR);
    #endif // defined (Use_Mpfi)
    for (int i=1; i<=mRows; i++)
    {
        for (int j=1; j<=mCols; j++)
        {
            EigenLib_mpType_GetCoeff(&x, i-1, j-1, xPtr);
            #if defined (Use_Float)
            __mingw_printf("%.8E ", x);
            #endif
            #if defined (Use_Double)
            __mingw_printf("%.16E ", x);
            #endif
            #if defined  (Use_LongDouble)
            __mingw_printf("%.20LE ", x); //  * expl(3000.0L)
            #endif
            #if defined (Use_Mpfr)
                mpfr_printf("%.RE ", x.mpfr_ptr());
            #endif
            #if defined (Use_Mpfi)
                mpfi_get_left(fL, x.mpfi_ptr());
                mpfi_get_right(fR, x.mpfi_ptr());
                mpfr_printf("[%.RE,%.RE] ", fL, fR);
            #endif
            #if defined (Use_Mpdec)
                char *s = mpd_to_sci(x.mpd_ptr(), 1);
                printf("%s ", s);
                mpd_free(s);
            #endif
            #if defined (Use_Mpq)
                gmp_printf("%Qd ", x.mpq_ptr());
                //mpq_out_str (NULL, 10, x.mpq_ptr());
            #endif
            #if defined (Use_Arb)
                arb_printd(x.arb_ptr(), 20);
                printf(",  ");
            #endif


        }
        printf("\n");
    }
    #if defined (Use_Mpfi)
        mpfr_clear(fL);
        mpfr_clear(fR);
    #endif // defined (Use_Mpfi)
}


#ifdef Use_Mpfr
extern void EigenLib_mpfr_SetPrecision(int prec)
{
    mpfr_set_default_prec(prec);
}
#endif // Use_Mpfr




#ifdef Use_Mpfi
extern void EigenLib_mpfi_SetPrecision(int prec)
{
    mpfr_set_default_prec(prec);
}
#endif // Use_Mpfi


#ifdef Use_Mpdec
extern void EigenLib_mpdec_SetPrecision(int prec)
{
        switch (prec) {
 		case -1:
			{
				mpDec::set_decimal32();
			}
			break;
 		case -2:
			{
				mpDec::set_decimal64();
			}
			break;
 		case -3:
			{
				mpDec::set_decimal128();
			}
			break;
 		default:
			{
				mpDec::set_precision(prec);;
			}
			break;
    }
}
#endif // Use_Mpdec




void put_Block_mpType(long i, long j, long p, long q, long what, mpMatrix *x, mpMatrix *result)
{
	switch (what) {
		case mp_const_block: (*x).block(i, j, p, q) = (*result) ; break;
		case mp_const_topLeftCorner: (*x).topLeftCorner(p, q) = (*result) ; break;
		case mp_const_bottomLeftCorner: (*x).bottomLeftCorner(p, q) = (*result) ; break;
		case mp_const_topRightCorner: (*x).topRightCorner(p, q) = (*result) ; break;
		case mp_const_bottomRightCorner: (*x).bottomRightCorner(p, q) = (*result) ; break;
		case mp_const_topRows: (*x).topRows(q) = (*result) ; break;
		case mp_const_bottomRows: (*x).bottomRows(q) = (*result) ; break;
		case mp_const_leftCols: (*x).leftCols(q) = (*result) ; break;
		case mp_const_rightCols: (*x).rightCols(q) = (*result) ; break;
		case mp_const_diagonal: (*x).diagonal(q) = (*result) ; break;
		case mp_const_middleRows: (*x).middleRows(p, q) = (*result) ; break;
		case mp_const_middleCols: (*x).middleCols(p, q) = (*result) ; break;
		case mp_const_triangularView: {
			switch (q) {
				case mp_const_Upper: (*x).triangularView<Eigen::Upper>() = (*result) ; break;
				case mp_const_Lower: (*x).triangularView<Eigen::Lower>() = (*result) ; break;
				case mp_const_StrictlyUpper: (*x).triangularView<Eigen::StrictlyUpper>() = (*result) ; break;
				case mp_const_StrictlyLower: (*x).triangularView<Eigen::StrictlyLower>() = (*result) ; break;
				case mp_const_UnitUpper: (*x).triangularView<Eigen::UnitUpper>() = (*result) ; break;
				case mp_const_UnitLower: (*x).triangularView<Eigen::UnitLower>() = (*result) ; break;
			}
		}
	}
}



void get_Block_mpType(long i, long j, long p, long q, long what, mpMatrix *x, mpMatrix *result)
{
	switch (what) {
		case mp_const_block: (*result) = (*x).block(i, j, p, q); break;
		case mp_const_topLeftCorner: (*result) = (*x).topLeftCorner(p, q); break;
		case mp_const_bottomLeftCorner: (*result) = (*x).bottomLeftCorner(p, q); break;
		case mp_const_topRightCorner: (*result) = (*x).topRightCorner(p, q); break;
		case mp_const_bottomRightCorner: (*result) = (*x).bottomRightCorner(p, q); break;
		case mp_const_topRows: (*result) = (*x).topRows(q); break;
		case mp_const_bottomRows: (*result) = (*x).bottomRows(q); break;
		case mp_const_leftCols: (*result) = (*x).leftCols(q); break;
		case mp_const_rightCols: (*result) = (*x).rightCols(q); break;
		case mp_const_diagonal: (*result) = (*x).diagonal(q); break;
		case mp_const_middleRows: (*result) = (*x).middleRows(p, q); break;
		case mp_const_middleCols: (*result) = (*x).middleCols(p, q); break;
		case mp_const_triangularView: {
			switch (q) {
				case mp_const_Upper: (*result) = (*x).triangularView<Eigen::Upper>() ; break;
				case mp_const_Lower: (*result) = (*x).triangularView<Eigen::Lower>(); break;
				case mp_const_StrictlyUpper: (*result) = (*x).triangularView<Eigen::StrictlyUpper>(); break;
				case mp_const_StrictlyLower: (*result) = (*x).triangularView<Eigen::StrictlyLower>(); break;
				case mp_const_UnitUpper: (*result) = (*x).triangularView<Eigen::UnitUpper>(); break;
				case mp_const_UnitLower: (*result) = (*x).triangularView<Eigen::UnitLower>(); break;
			}
		}
	}
}



void SetSpecialValue_mpType(int32_t m, int32_t n, long what, mpMatrix *x)
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
		case mp_setRandom_nm: (*x) =  mpMatrix::Random(n, m); break;
		case mp_setRandomSymmetric:
		    {(*x) =  mpMatrix::Random(n, m);
		    mpMatrix y = (*x).transpose();
		    (*x) += y;} break;

//		case mp_FillLinear: {
//			(*x).resize(n, m);
//			for (int j = 0; j < (*x).rows(); j++) {
//				(*x)(j, 0) = (float) m + (j) * 1000;
//				for (int i = 1; i < (*x).cols(); i++) { (*x)(j, i) = (*x)(j, i - 1) + n;}}
//			}
//		case mp_setRandomSymmetric:

//		case mp_setRandom_nm:
//			{
//			    (*x) = mpMatrix::Random(n, m);
//			    (*x) += (*x).transpose();
//				(*x).resize(n, m);
//				(*x).setRandom();
//				(*x) += (*x).transpose();
//			}
//			break;



//		case mp_FillLinear: {
//			for (int j = 0; j < (*x).rows(); j++) {
//				(*x)(j, 0) = (float) m + (j) * 1000;
//				for (int i = 1; i < (*x).cols(); i++) { (*x)(j, i) = (*x)(j, i - 1) + n;}}
//			}
		break;
	}
}



void SetSpecialValue1_mpType(int32_t m, int32_t n, long what, mpMatrix *x)
{
	switch (what) {
		case mp_setZero: (*x).resize(n, m); (*x).setZero() ; break;
		case mp_setOnes: (*x).resize(n, m); (*x).setOnes() ; break;
		case mp_setIdentity: (*x).resize(n, m); (*x).setIdentity() ; break;
		case mp_setNan:
			{
				(*x).resize(n, m); (*x).setOnes() ;
			}
			 break;
		case mp_setInfinity:
			{
				(*x).resize(n, m); (*x).setOnes() ;
			}
			 break;
		case mp_setMinusInfinity:
			{
				(*x).resize(n, m); (*x).setOnes() ;
			}
			 break;
		case mp_setMinusZero:
			{
				(*x).resize(n, m); (*x).setOnes() ;
			}
			 break;
		case mp_setRandom: (*x).resize(n, m); (*x).setRandom() ; break;
		case mp_setRandomSymmetric:
			{
				(*x).resize(n, m);
				(*x).setRandom();
				(*x) += (*x).transpose();
			}
			break;

		case mp_FillLinear: {
			(*x).resize(n, m);
			for (int j = 0; j < (*x).rows(); j++) {
				(*x)(j, 0) = (float) m + (j) * 1000;
				for (int i = 1; i < (*x).cols(); i++) { (*x)(j, i) = (*x)(j, i - 1) + n;}}
			}
		break;
	}
}




void SetSpecialValue2_mpType(long Vertical, long Horizontal, long PartialMode, long what, mpMatrix *x, mpMatrix *result)
{
	switch (what) {
		case mp_asDiagonal: (*result) = (*x).col(0).asDiagonal(); break;
		case mp_adjoint: (*result) = (*x).col(0).adjoint(); break;
		case mp_conjugate: (*result) = (*x).col(0).conjugate(); break;
		case mp_transpose: (*result) = (*x).col(0).transpose(); break;
		case mp_reverse: {
			switch (PartialMode) {
				case mp_const_full_matrix: (*result) = (*x).reverse();break;
				case mp_const_rowwise: (*result) = (*x).rowwise().reverse();break;
				case mp_const_colwise: (*result) = (*x).colwise().reverse();break;
			}
		}
		break;
		case mp_replicate: {
			switch (PartialMode) {
				case mp_const_full_matrix: (*result) = (*x).replicate(Vertical, Horizontal);break;
				case mp_const_rowwise: (*result) = (*x).rowwise().replicate(Vertical);break;
				case mp_const_colwise: (*result) = (*x).colwise().replicate(Horizontal);break;
			}
		}
		case mp_ResizeLike: (*result).resizeLike(*x) ; break;
		break;
	}
}




void BasicArithmetic_mpType(long what, mpMatrix *w, mpMatrix *x, mpMatrix *y)
{
	mpType f = (*x)(0,0);
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
		case mp_const_div_scalar: *y = (1/f) * (*w).array() ; break;
	}
}


void BasicArithmetic_i_mpType(int32_t i, long what, mpMatrix *w, mpMatrix *y)
{
	mpType f = (mpType) i;
	switch (what){
		case mp_const_plus_i: *y = (*w).array() + f; break;
		case mp_const_minus_i: *y = (*w).array() - f; break;
		case mp_const_minus_i_neg: *y = f - (*w).array(); break;
		case mp_const_times_i: *y = (*w).array() * f; break;
		case mp_const_div_i: *y = (*w).array() / f; break;
		case mp_const_div_i_inv: *y =  f * (*w).array().cwiseInverse(); break;
	}
}


void Compare_mpType(long CmpMode, long what, mpMatrix *w, mpMatrix *x, long* result)
{
	switch (what) {
		case mp_const_GT:  // >
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  >   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  >   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  >   (*x)(0,0)).count(); break;
			} break;
		case mp_const_LT:  // <
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  <   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  <   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  <   (*x)(0,0)).count(); break;
			} break;
		case mp_const_LE:  // <=
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  <=   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  <=   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  <=   (*x)(0,0)).count(); break;
			} break;
		case mp_const_GE:  // >=
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  >=   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  >=   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  >=   (*x)(0,0)).count(); break;
			} break;
		case mp_const_EQ:  // ==
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  ==   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  ==   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  ==   (*x)(0,0)).count(); break;
			} break;
		case mp_const_NE:  // !=
			switch (CmpMode) {
				case mp_const_All: *result = ((*w).array()  !=   (*x)(0,0)).all(); break;
				case mp_const_Any: *result = ((*w).array()  !=   (*x)(0,0)).any(); break;
				case mp_const_Count: *result = (long) ((*w).array()  !=   (*x)(0,0)).count(); break;
			} break;
	}
}




void Stats2_mpType(long what, long *IndexX, long *IndexY, mpMatrix *x1,  mpMatrix *y)
{
	mpMatrix::Index mRow=0, mCol=0;
	switch (what){
		case mp_const_minCoeff_Index: (*y)(0,0) = (*x1).minCoeff(&mRow, &mCol); break;
		case mp_const_maxCoeff_Index: (*y)(0,0) = (*x1).maxCoeff(&mRow, &mCol); break;
	}
	*IndexX = long(mRow); *IndexY = long(mCol);
}


void Stats_mpType(long PartialMode, long what,  mpMatrix *x, mpMatrix *y)
{
	switch (what){
		case mp_const_sum:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).sum(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().sum(); break;
			case mp_const_colwise: (*y) = (*x).colwise().sum(); break;
		}
		break;
		case mp_const_prod:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).prod(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().prod(); break;
			case mp_const_colwise: (*y) = (*x).colwise().prod(); break;
		}
		break;
		case mp_const_mean:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).mean(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().mean(); break;
			case mp_const_colwise: (*y) = (*x).colwise().mean(); break;
		}
		break;
		case mp_const_minCoeff:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).minCoeff(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().minCoeff(); break;
			case mp_const_colwise: (*y) = (*x).colwise().minCoeff(); break;
		}
		break;
		case mp_const_maxCoeff:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).maxCoeff(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().maxCoeff(); break;
			case mp_const_colwise: (*y) = (*x).colwise().maxCoeff(); break;
		}
		break;
		case mp_const_squaredNorm:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).squaredNorm(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().squaredNorm(); break;
			case mp_const_colwise: (*y) = (*x).colwise().squaredNorm(); break;
		}
		break;
		case mp_const_Norm:
		switch (PartialMode){
			case mp_const_full_matrix: (*y)(0,0) = (*x).norm(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().norm(); break;
			case mp_const_colwise: (*y) = (*x).colwise().norm(); break;
		}
		break;
		case mp_const_stableNorm:
		switch (PartialMode){
			//case mp_const_full_matrix: (*y)(0,0) = (*x).stableNorm(); break;
			case mp_const_rowwise: (*y) = (*x).rowwise().stableNorm(); break;
			case mp_const_colwise: (*y) = (*x).colwise().stableNorm(); break;
		}
		break;
	}
}
