#include "mpNumC.h"


#ifdef Use_Float2
#include "mpNum_Internal.h"
void T1()
{
    int n = 4;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Float_Init(&mPtr);
    EigenLib_Float_Init(&xPtr);
    EigenLib_Float_Init(&zPtr);

    SetSpecialValue_Float(n, 1, mp_FillLinear, xPtr);
    EigenLib_Float_Print("Here is the matrix x:", xPtr);
    boost_Float_ElementaryFunctions1(mp_const_Tgamma, zPtr, xPtr);
    EigenLib_Float_Print("Here is the matrix z:", zPtr);

//    SetSpecialValue_Float(n, n, mp_setRandom_nm, mPtr);
//    EigenLib_Float_Print("Here is the matrix m:", mPtr);
//    EigenLib_Float_Inverse(xPtr, mPtr, 0);
//    EigenLib_Float_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Float(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Float_Print("Here is the product m * x:", zPtr);

    EigenLib_Float_Clear(&mPtr);
    EigenLib_Float_Clear(&xPtr);
    EigenLib_Float_Clear(&zPtr);

}

void cplx_T1()
{
    int n = 14;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Float_Init(&mPtr);
    cplx_EigenLib_Float_Init(&xPtr);
    cplx_EigenLib_Float_Init(&zPtr);

    cplx_SetSpecialValue_Float(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Float_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Float_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Float_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Float(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Float_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Float_Clear(&mPtr);
    cplx_EigenLib_Float_Clear(&xPtr);
    cplx_EigenLib_Float_Clear(&zPtr);

}


#endif // Use_Float


#ifdef Use_Double2
#include "mpNum_Internal.h"
void T1()
{
    int n = 14;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Double_Init(&mPtr);
    EigenLib_Double_Init(&xPtr);
    EigenLib_Double_Init(&zPtr);

    SetSpecialValue_Double(n, 1, mp_FillLinear, xPtr);
    EigenLib_Double_Print("Here is the matrix x:", xPtr);
    boost_Double_ElementaryFunctions1(mp_const_Tgamma, zPtr, xPtr);
    EigenLib_Double_Print("Here is the matrix z:", zPtr);

//    SetSpecialValue_Double(n, n, mp_setRandom_nm, mPtr);
//    EigenLib_Double_Print("Here is the matrix :", mPtr);
//    EigenLib_Double_Inverse(xPtr, mPtr, 0);
//    EigenLib_Double_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Double(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Double_Print("Here is the product m * x:", zPtr);

    EigenLib_Double_Clear(&mPtr);
    EigenLib_Double_Clear(&xPtr);
    EigenLib_Double_Clear(&zPtr);

}


void cplx_T1()
{
    int n = 4;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Double_Init(&mPtr);
    cplx_EigenLib_Double_Init(&xPtr);
    cplx_EigenLib_Double_Init(&zPtr);

    cplx_SetSpecialValue_Double(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Double_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Double_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Double_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Double(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Double_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Double_Clear(&mPtr);
    cplx_EigenLib_Double_Clear(&xPtr);
    cplx_EigenLib_Double_Clear(&zPtr);

}



#endif // Use_Double

#ifdef Use_LongDouble2
#include "mpNum_Internal.h"
void T1()
{
    int n = 4;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_LongDouble_Init(&mPtr);
    EigenLib_LongDouble_Init(&xPtr);
    EigenLib_LongDouble_Init(&zPtr);

    SetSpecialValue_LongDouble(n, 1, mp_FillLinear, xPtr);
    EigenLib_LongDouble_Print("Here is the matrix x:", xPtr);
    boost_LongDouble_ElementaryFunctions1(mp_const_Tgamma, zPtr, xPtr);
    EigenLib_LongDouble_Print("Here is the matrix z:", zPtr);

//    SetSpecialValue_LongDouble(n, n, mp_setRandom_nm, mPtr);
//    EigenLib_LongDouble_Print("Here is the matrix m:", mPtr);
//    EigenLib_LongDouble_Inverse(xPtr, mPtr, 0);
//    EigenLib_LongDouble_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_LongDouble(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_LongDouble_Print("Here is the product m * x:", zPtr);

    EigenLib_LongDouble_Clear(&mPtr);
    EigenLib_LongDouble_Clear(&xPtr);
    EigenLib_LongDouble_Clear(&zPtr);

}


void cplx_T1()
{
    int n = 4;
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_LongDouble_Init(&mPtr);
    cplx_EigenLib_LongDouble_Init(&xPtr);
    cplx_EigenLib_LongDouble_Init(&zPtr);

    cplx_SetSpecialValue_LongDouble(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_LongDouble_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_LongDouble_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_LongDouble_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_LongDouble(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_LongDouble_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_LongDouble_Clear(&mPtr);
    cplx_EigenLib_LongDouble_Clear(&xPtr);
    cplx_EigenLib_LongDouble_Clear(&zPtr);
}

#endif // Use_LongDouble


#ifdef Use_Mpfr2
#include "mpNum_Internal.h"
void T1()
{
    int n = 14;
    EigenLib_Mpfr_SetPrecision(40);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Mpfr_Init(&mPtr);
    EigenLib_Mpfr_Init(&xPtr);
    EigenLib_Mpfr_Init(&zPtr);


    SetSpecialValue_Mpfr(n, 1, mp_FillLinear, xPtr);
    EigenLib_Mpfr_Print("Here is the matrix x:", xPtr);
    boost_Mpfr_ElementaryFunctions1(mp_const_Tgamma, zPtr, xPtr);
    EigenLib_Mpfr_Print("Here is the matrix z:", zPtr);


//    SetSpecialValue_Mpfr(n, n, mp_setRandom_nm, mPtr);
//    EigenLib_Mpfr_Print("Here is the matrix m:", mPtr);
//    EigenLib_Mpfr_Inverse(xPtr, mPtr, 0);
//    EigenLib_Mpfr_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Mpfr(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Mpfr_Print("Here is the product m * x:", zPtr);

    EigenLib_Mpfr_Clear(&mPtr);
    EigenLib_Mpfr_Clear(&xPtr);
    EigenLib_Mpfr_Clear(&zPtr);
}

void cplx_T1()
{
    int n = 4;
    EigenLib_Mpfr_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Mpfr_Init(&mPtr);
    cplx_EigenLib_Mpfr_Init(&xPtr);
    cplx_EigenLib_Mpfr_Init(&zPtr);

    cplx_SetSpecialValue_Mpfr(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Mpfr_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Mpfr_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Mpfr_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Mpfr(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Mpfr_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Mpfr_Clear(&mPtr);
    cplx_EigenLib_Mpfr_Clear(&xPtr);
    cplx_EigenLib_Mpfr_Clear(&zPtr);
}


#endif // Use_Mpfr





#ifdef Use_Mpfi2
#include "mpNum_Internal.h"
void T1()
{
    int n = 4;
    EigenLib_Mpfi_SetPrecision(10);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Mpfi_Init(&mPtr);
    EigenLib_Mpfi_Init(&xPtr);
    EigenLib_Mpfi_Init(&zPtr);

//    SetSpecialValue_Mpfi(n, 1, mp_FillLinear, xPtr);
//    EigenLib_Mpfi_Print("Here is the matrix x:", xPtr);
//    boost_Mpfi_ElementaryFunctions1(mp_const_Tgamma, zPtr, xPtr);
//    EigenLib_Mpfi_Print("Here is the matrix z:", zPtr);


    SetSpecialValue_Mpfi(n, n, mp_setRandom_nm, mPtr);
    EigenLib_Mpfi_Print("Here is the matrix m:", mPtr);
    EigenLib_Mpfi_Inverse(xPtr, mPtr, 0);
    EigenLib_Mpfi_Print("Here is the matrix x:", xPtr);
    BasicArithmetic_Mpfi(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    EigenLib_Mpfi_Print("Here is the product m * x:", zPtr);

    EigenLib_Mpfi_Clear(&mPtr);
    EigenLib_Mpfi_Clear(&xPtr);
    EigenLib_Mpfi_Clear(&zPtr);

}

void cplx_T1()
{
    int n = 14;
    EigenLib_Mpfi_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Mpfi_Init(&mPtr);
    cplx_EigenLib_Mpfi_Init(&xPtr);
    cplx_EigenLib_Mpfi_Init(&zPtr);

    cplx_SetSpecialValue_Mpfi(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Mpfi_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Mpfi_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Mpfi_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Mpfi(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Mpfi_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Mpfi_Clear(&mPtr);
    cplx_EigenLib_Mpfi_Clear(&xPtr);
    cplx_EigenLib_Mpfi_Clear(&zPtr);
}



#endif // Use_Mpfi



#ifdef Use_Mpdec2
#include "mpNum_Internal.h"
void T1()
{
    int n = 4;
    EigenLib_Mpdec_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Mpdec_Init(&mPtr);
    EigenLib_Mpdec_Init(&xPtr);
    EigenLib_Mpdec_Init(&zPtr);

    SetSpecialValue_Mpdec(n, n, mp_setRandom_nm, mPtr);
    EigenLib_Mpdec_Print("Here is the matrix m:", mPtr);
//    EigenLib_Mpdec_Inverse(xPtr, mPtr, 0);
//    EigenLib_Mpdec_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Mpdec(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Mpdec_Print("Here is the product m * x:", zPtr);

    EigenLib_Mpdec_Clear(&mPtr);
    EigenLib_Mpdec_Clear(&xPtr);
    EigenLib_Mpdec_Clear(&zPtr);

}


void cplx_T1()
{
    int n = 4;
    EigenLib_Mpdec_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Mpdec_Init(&mPtr);
    cplx_EigenLib_Mpdec_Init(&xPtr);
    cplx_EigenLib_Mpdec_Init(&zPtr);

    cplx_SetSpecialValue_Mpdec(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Mpdec_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Mpdec_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Mpdec_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Mpdec(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Mpdec_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Mpdec_Clear(&mPtr);
    cplx_EigenLib_Mpdec_Clear(&xPtr);
    cplx_EigenLib_Mpdec_Clear(&zPtr);
}


#endif // Use_Mpdec


#ifdef Use_Mpq2
#include "mpNum_Internal.h"
void T1()
{
    int n = 4;
    //EigenLib_Mpq_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    EigenLib_Mpq_Init(&mPtr);
    EigenLib_Mpq_Init(&xPtr);
    EigenLib_Mpq_Init(&zPtr);

    SetSpecialValue_Mpq(n, n, mp_setRandom_nm, mPtr);
    EigenLib_Mpq_Print("Here is the matrix m:", mPtr);
 //   EigenLib_Mpq_Inverse(xPtr, mPtr, 0);

     SetSpecialValue_Mpq(n, n, mp_setRandom_nm, xPtr);

    EigenLib_Mpq_Print("Here is the matrix x:", xPtr);
    BasicArithmetic_Mpq(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    EigenLib_Mpq_Print("Here is the product m * x:", zPtr);

    EigenLib_Mpq_Clear(&mPtr);
    EigenLib_Mpq_Clear(&xPtr);
    EigenLib_Mpq_Clear(&zPtr);

}


void cplx_T1()
{
    int n = 4;
    EigenLib_Mpq_SetPrecision(30);
    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;

    cplx_EigenLib_Mpq_Init(&mPtr);
    cplx_EigenLib_Mpq_Init(&xPtr);
    cplx_EigenLib_Mpq_Init(&zPtr);

    cplx_SetSpecialValue_Mpq(n, n, mp_setRandom_nm, mPtr);
    cplx_EigenLib_Mpq_Print("Here is the matrix m:", mPtr);
    cplx_EigenLib_Mpq_Inverse(xPtr, mPtr, 0);
    cplx_EigenLib_Mpq_Print("Here is the matrix x:", xPtr);
    cplx_BasicArithmetic_Mpq(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
    cplx_EigenLib_Mpq_Print("Here is the product m * x:", zPtr);

    cplx_EigenLib_Mpq_Clear(&mPtr);
    cplx_EigenLib_Mpq_Clear(&xPtr);
    cplx_EigenLib_Mpq_Clear(&zPtr);
}


#endif // Use_Mpq





//
//#ifdef Use_Fmpq2
//#include "mpNum_Internal.h"
//void T1()
//{
//    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;
//
//    EigenLib_Fmpq_Init(&mPtr);
//    EigenLib_Fmpq_Init(&xPtr);
//    EigenLib_Fmpq_Init(&zPtr);
//
//    SetSpecialValue_Fmpq(4, 4, mp_setRandom_nm, mPtr);
//    EigenLib_Fmpq_Print("Here is the matrix m:", mPtr);
//    EigenLib_Fmpq_Inverse(xPtr, mPtr, 0);
//    EigenLib_Fmpq_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Fmpq(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Fmpq_Print("Here is the product m * x:", zPtr);
//
//    EigenLib_Fmpq_Clear(&mPtr);
//    EigenLib_Fmpq_Clear(&xPtr);
//    EigenLib_Fmpq_Clear(&zPtr);
//
//}
//
//void cplx_T1()
//{
//    T1();
//}
//
//#endif // Use_Fmpq
//


//
//#ifdef Use_Fmpz2
//#include "mpNum_Internal.h"
//void T1()
//{
//    mpNumMatrixPtr mPtr=0, xPtr=0, zPtr=0;
//
//    EigenLib_Fmpz_Init(&mPtr);
//    EigenLib_Fmpz_Init(&xPtr);
//    EigenLib_Fmpz_Init(&zPtr);
//
//    SetSpecialValue_Fmpz(4, 4, mp_setRandom_nm, mPtr);
//    EigenLib_Fmpz_Print("Here is the matrix m:", mPtr);
//    EigenLib_Fmpz_Inverse(xPtr, mPtr, 0);
//    EigenLib_Fmpz_Print("Here is the matrix x:", xPtr);
//    BasicArithmetic_Fmpz(mp_const_MatrixProduct, mPtr, xPtr, zPtr);
//    EigenLib_Fmpz_Print("Here is the product m * x:", zPtr);
//
//    EigenLib_Fmpz_Clear(&mPtr);
//    EigenLib_Fmpz_Clear(&xPtr);
//    EigenLib_Fmpz_Clear(&zPtr);
//
//}
//
//void cplx_T1()
//{
//    T1();
//}
//
//#endif // Use_Fmpz




#ifdef Use_ALL
void T1()
{
    int n = 4;
    mpNum_SetPrecision(100);
    int mpNumType = -5;

    mpNum_t X, Y, Z;
    mpNum_Init(mpNumType, X);
    mpNum_Init(mpNumType, Y);
    mpNum_Init(mpNumType, Z);

    mpNum_SetSpecialValue(n, n, mp_setRandom_nm, X);
    mpNum_Print("Here is the matrix X:", X);
    mpNum_Inverse(Y, X, 0);
    mpNum_Print("Here is the matrix Y:", Y);
    mpNum_BasicArithmetic(mp_const_MatrixProduct, X, Y, Z);
    mpNum_Print("Here is the product Z = X * Y:", Z);

    mpNum_Clear(X);
    mpNum_Clear(Y);
    mpNum_Clear(Z);

}

void cplx_T1()
{
   // T1();
}

#endif // Use_ALL


int main(void)
{
     //   SomeFunction("World");
    T1();
 //   cplx_T1();
    return 0;
}
