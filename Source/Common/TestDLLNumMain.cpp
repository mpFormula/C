#include "mpNumC.h"
#include<stdio.h>

#ifdef __cplusplus
extern "C" {
#endif




void t2()
{
    FmpzPtr x, y;

    Lib_Fmpz_Init (&x);
    Lib_Fmpz_Init (&y);

    Lib_Fmpz_Set_Ui (x, 7);
    Lib_Fmpz_Mul (y, x, x);
    Lib_Fmpz_Print (x);
    Lib_Flint_Printf ("^2 = ");
    Lib_Fmpz_Print (y);
    Lib_Flint_Printf ("\n");

    Lib_Fmpz_Clear (x);
    Lib_Fmpz_Clear (y);

}



void t2a()
{
    FmpqPtr x, y;

    Lib_Fmpq_Init (&x);
    Lib_Fmpq_Init (&y);

    Lib_Fmpq_Set_Si_Si (x, 7, 5);
    Lib_Fmpq_Mul (y, x, x);
    Lib_Fmpq_Print (x);
    Lib_Flint_Printf ("^2 = ");
    Lib_Fmpq_Print (y);
    Lib_Flint_Printf ("\n");

    Lib_Fmpq_Clear (x);
    Lib_Fmpq_Clear (y);

}


void t3()
{
    ArbPtr x;
    Lib_Arb_Init(&x);
    Lib_Arb_Const_Pi(x, 50 * 3.33);
    Lib_Arb_Printd(x, 50); printf("\n");
    Lib_Arb_Clear(x);

}


void t3a()
{
    AcbPtr x;
    Lib_Acb_Init(&x);
    Lib_Acb_Const_Pi(x, 50 * 3.33);
    Lib_Acb_Printd(x, 50); printf("\n");
    Lib_Acb_Clear(x);

}


void t5()
{
    long i, j;
    FmpzMatPtr A;
    FmpzMatPtr B;
    Lib_Fmpz_Mat_Init (&A, 2, 2);
    Lib_Fmpz_Mat_Init (&B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    Lib_Fmpz_Mat_Set_Ui(A, i, j, 2*i+j);
    Lib_Fmpz_Mat_Mul (B, A, A);
    Lib_Flint_Printf ("A = \n");
    Lib_Fmpz_Mat_Print_Pretty (A);
    Lib_Flint_Printf ("\n");
    Lib_Flint_Printf ("A^2 = \n");
    Lib_Fmpz_Mat_Print_Pretty (B);
    Lib_Fmpz_Mat_Clear (A);
    Lib_Fmpz_Mat_Clear (B);
}



void t6()
{
    long i, j;
    FmpqMatPtr A;
    FmpqMatPtr B;
    Lib_Fmpq_Mat_Init (&A, 2, 2);
    Lib_Fmpq_Mat_Init (&B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    Lib_Fmpq_Mat_Set_Si(A, i, j, 2*i+j, 1);
    Lib_Fmpq_Mat_Mul (B, A, A);
    Lib_Flint_Printf ("A = \n");
    Lib_Fmpq_Mat_Print_Pretty (A);
    Lib_Flint_Printf ("\n");
    Lib_Flint_Printf ("A^2 = \n");
    Lib_Fmpq_Mat_Print_Pretty (B);
    Lib_Fmpq_Mat_Clear (A);
    Lib_Fmpq_Mat_Clear (B);
}


void t7()
{
    long digits = 20;
    long prec = 60;
    long i, j;
    ArbMatPtr A;
    ArbMatPtr B;
    Lib_Arb_Mat_Init (&A, 2, 2);
    Lib_Arb_Mat_Init (&B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    Lib_Arb_Mat_Set_Ui(A, i, j, 2*i+j);
    Lib_Arb_Mat_Mul (B, A, A, prec);
    Lib_Flint_Printf ("A = \n");
    Lib_Arb_Mat_Print_Pretty (A, digits);
    Lib_Flint_Printf ("A^2 = \n");
    Lib_Arb_Mat_Print_Pretty (B, digits);
    Lib_Arb_Mat_Clear (A);
    Lib_Arb_Mat_Clear (B);
}


void t8()
{
    long digits = 20;
    long prec = 60;
    long i, j;
    AcbMatPtr A;
    AcbMatPtr B;
    Lib_Acb_Mat_Init (&A, 2, 2);
    Lib_Acb_Mat_Init (&B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    Lib_Acb_Mat_Set_Ui(A, i, j, 2*i+j);
    Lib_Acb_Mat_Mul (B, A, A, prec);
    Lib_Flint_Printf ("A = \n");
    Lib_Acb_Mat_Print_Pretty (A, digits);
    Lib_Flint_Printf ("A^2 = \n");
    Lib_Acb_Mat_Print_Pretty (B, digits);
    Lib_Acb_Mat_Clear (A);
    Lib_Acb_Mat_Clear (B);
}



int main()
{
    t2();
//    T1MainNum();
//    MpMathToNative();
    return 0;
}


#ifdef __cplusplus
}
#endif


