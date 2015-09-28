
#include "libEigen.h"


void EigenLib_mpType_Solve2(mpMatrix *x, mpMatrix *A, mpMatrix *b, long Decomposition)
{
	switch (Decomposition) {
		case 0: *x = (*A).fullPivLu().solve(*b); break;
		case 1: *x = (*A).ldlt().solve(*b); break;
    #if !defined (Use_Mpq)
    	case 2: *x = (*A).colPivHouseholderQr().solve(*b); break;
		case 3: *x = (*A).fullPivHouseholderQr().solve(*b); break;
		case 4: *x = (*A).jacobiSvd(ComputeThinU | ComputeThinV).solve(*b); break;
    #endif

	}
}



void EigenLib_mpType_Inverse(mpMatrix *x, mpMatrix *A, long Decomposition)
{
	switch (Decomposition) {
		case 0: *x = (*A).fullPivLu().inverse(); break;
//		case 1: *x = (*A).ldlt().inverse(); break;
    #if !defined (Use_Mpq)
    	case 2: *x = (*A).colPivHouseholderQr().inverse(); break;
		case 3: *x = (*A).fullPivHouseholderQr().inverse(); break;
//		case 4: *x = (*A).jacobiSvd(ComputeThinU | ComputeThinV).inverse(); break;
    #endif
//
//
//		case 0: *x = (*A).fullPivLu().inverse(); break;
//		case 1: *x = (*A).colPivHouseholderQr().inverse(); break;
//		case 2: *x = (*A).fullPivHouseholderQr().inverse(); break;

	}
}


void EigenLib_mpType_Det(mpMatrix *x, mpMatrix *A, long Decomposition)
{
	switch (Decomposition) {
		case 0: (*x)(0,0) = (*A).fullPivLu().determinant(); break;
	}
}


void EigenLib_mpType_Rank(mpMatrix *A, long Decomposition, long* rank)
{
	switch (Decomposition) {
		case 0: *rank = (*A).fullPivLu().rank(); break;
	}
}

//
//void EigenLib_mpType_JacobiSVD_Full(mpMatrix *s, mpMatrix *u, mpMatrix *v, mpMatrix *A)
//{
//    #if !defined (Use_Mpq)
//		JacobiSVD<mpMatrix> svd((*A), ComputeThinU| ComputeThinV);
//		*s = svd.singularValues();
//		*u = svd.matrixU();
//		*v = svd.matrixV();
//    #endif // defined
//}


void EigenLib_mpType_SelfAdjointEigenValues(mpMatrix *x, mpMatrix *A)
{
			SelfAdjointEigenSolver<mpMatrix> es((*A), EigenvaluesOnly);
			*x = es.eigenvalues();
}


void EigenLib_mpType_SelfAdjointEigenSystem(mpMatrix *x, mpMatrix *y, mpMatrix *A)
{
			SelfAdjointEigenSolver<mpMatrix> es((*A));
			*x = es.eigenvalues();
			*y = es.eigenvectors();
}

//
//void EigenLib_mpType_EigenValues(mpMatrixC *x, mpMatrix *A)
//{
//			EigenSolver<mpMatrix> es((*A), false);
//			*x = es.eigenvalues();
//}
//
//
//void EigenLib_mpType_EigenSystem(mpMatrixC *x, mpMatrixC *y, mpMatrix *A)
//{
//			EigenSolver<mpMatrix> es((*A), true);
//			*x = es.eigenvalues();
//			*y = es.eigenvectors();
//}


