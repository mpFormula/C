#include "mpNumC.h"
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif



void T1MainNum()
{
    int n = 14;
    mpNum_SetPrecision(60);

    // 1 = single, 2 = double, 3 = long double, 4 = MPFR, 5 = MPFI, 6 = MPDEC, 7 = MPQ, 8 = ARB
    int mpNumType = 5;

 //   double Result = Std_Double_Sum(4.0, 5.0);
//    printf("Result of call: %e\n", Result);

    mpNum_t X, Y, Z, p;
    mpNum_Init(mpNumType, X);
    mpNum_Init(mpNumType, Y);
    mpNum_Init(mpNumType, Z);
    mpNum_Init(mpNumType, p);

    mpNum_Print("Here is the Item p = 0:", p);

    mpNum_SetSpecialValue(n, n, mp_setRandom_nm, X);
    mpNum_Print("Here is the matrix X:", X);

    mpNum_Inverse(Y, X, 0);

    //mpNum_SetSpecialValue(n, n, mp_setRandom_nm, Y);

    mpNum_Print("Here is the matrix Y:", Y);
    mpNum_BasicArithmetic(mp_const_MatrixProduct, X, Y, Z);
    mpNum_Print("Here is the product Z = X * Y:", Z);



    mpNum_SetItemIntoMatrix(Z,1,1,X);
    mpNum_Print("Here is the product Z after insertion at(1,1)", Z);

    mpNum_GetItemFromMatrix(p,1,1,Z);
    mpNum_Print("Here is the Item p = Z(1,1):", p);


    mpNum_Clear(X);
    mpNum_Clear(Y);
    mpNum_Clear(Z);
    mpNum_Clear(p);
}



int main()
{
    T1MainNum();
//    MpMathToNative();
    return 0;
}


#ifdef __cplusplus
}
#endif


