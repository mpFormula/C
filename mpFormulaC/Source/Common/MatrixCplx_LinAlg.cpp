
#include "libEigen.h"



void EigenLib_cplx_mpType_Inverse(mpMatrixC *x, mpMatrixC *A, long Decomposition)
{
	switch (Decomposition) {
		case 0: *x = (*A).fullPivLu().inverse(); break;
		case 1: *x = (*A).colPivHouseholderQr().inverse(); break;
		case 2: *x = (*A).fullPivHouseholderQr().inverse(); break;

	}
}




void EigenLib_cplx_mpType_Solve(mpMatrixC *x, mpMatrixC *A, mpMatrixC *b, long Decomposition)
{
	switch (Decomposition) {
		case 0: *x = (*A).lu().solve(*b); break;
		case 1: *x = (*A).partialPivLu().solve(*b); break;
		case 2: *x = (*A).fullPivLu().solve(*b); break;
		case 3: *x = (*A).householderQr().solve(*b); break;
		case 4: *x = (*A).colPivHouseholderQr().solve(*b); break;
		case 5: *x = (*A).fullPivHouseholderQr().solve(*b); break;

    #if !defined(Use_Mpfr) && !defined(Use_Mpfi)  && !defined(Use_Mpdec)  && !defined(Use_Mpq)
		case 6: *x = (*A).llt().solve(*b); break;
    #endif
		case 7: *x = (*A).ldlt().solve(*b); break;
	}
}


void EigenLib_cplx_mpType_Solve2(mpMatrixC *x, mpMatrixC *A, mpMatrixC *b, long Decomposition)
{
	switch (Decomposition) {
		case 0: *x = (*A).fullPivLu().solve(*b); break;
		case 1: *x = (*A).fullPivHouseholderQr().solve(*b); break;
		case 2: *x = (*A).ldlt().solve(*b); break;
	}
}



void EigenLib_cplx_mpType_JacobiSVD_Full(mpMatrix *s, mpMatrixC *u, mpMatrixC *v, mpMatrixC *A)
{
    #if !defined(Use_Mpq)
		JacobiSVD<mpMatrixC> svd((*A), ComputeThinU| ComputeThinV);
		*s = svd.singularValues();
		*u = svd.matrixU();
		*v = svd.matrixV();
    #endif
}


void EigenLib_cplx_mpType_SelfAdjointEigenValues(mpMatrix *x, mpMatrixC *A)
{
    #if !defined(Use_Mpfr) && !defined(Use_Mpfi)  && !defined(Use_Mpdec) && !defined(Use_Mpq)
			SelfAdjointEigenSolver<mpMatrixC> es((*A), EigenvaluesOnly);
			*x = es.eigenvalues();
    #endif
}


void EigenLib_cplx_mpType_SelfAdjointEigenSystem(mpMatrix *x, mpMatrixC *y, mpMatrixC *A)
{
    #if !defined(Use_Mpfr) && !defined(Use_Mpfi)  && !defined(Use_Mpdec) && !defined(Use_Mpq)
			SelfAdjointEigenSolver<mpMatrixC> es((*A));
			*x = es.eigenvalues();
    #endif
}


void EigenLib_cplx_mpType_EigenValues(mpMatrixC *x, mpMatrixC *A)
{
			ComplexEigenSolver<mpMatrixC> es((*A), false);
			*x = es.eigenvalues();
}



void EigenLib_cplx_mpType_EigenSystem(mpMatrixC *x, mpMatrixC *y, mpMatrixC *A)
{
			ComplexEigenSolver<mpMatrixC> es((*A), true);
			*x = es.eigenvalues();
			*y = es.eigenvectors();
}
