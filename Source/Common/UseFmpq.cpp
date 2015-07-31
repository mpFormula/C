
#define Use_fmpq

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"



void Lib_Fmpq_Print(FmpqPtr x)
{
    fmpq_print( (fmpq*) x);
}


void Lib_Fmpq_Init(FmpqPtr* x)
{
    (*x) =  malloc (sizeof(fmpq));
    fmpq_init( (fmpq*) (*x));
}

void Lib_Fmpq_Clear(FmpqPtr x)
{
    fmpq_clear( (fmpq*) x);
    free(x);
}


void Lib_Fmpq_Mul(FmpqPtr x, FmpqPtr y, FmpqPtr z)
{
    fmpq_mul( (fmpq*) x,  (fmpq*) y,  (fmpq*) z);
}


void Lib_Fmpq_Set_Si(FmpqPtr x, long a, long b)
{
    fmpq_set_si( (fmpq*) x, a, b);
}




//***************************************************



void Lib_Fmpq_Mat_Print_Pretty(FmpqMatPtr A)
{
    fmpq_mat_print( (fmpq_mat_struct*) A);
}


void Lib_Fmpq_Mat_Init(FmpqMatPtr* A, long i, long j)
{
    (*A) =  malloc (sizeof(fmpq_mat_struct));
    fmpq_mat_init( (fmpq_mat_struct*) (*A), i, j);
}

void Lib_Fmpq_Mat_Clear(FmpqMatPtr A)
{
    fmpq_mat_clear( (fmpq_mat_struct*) A);
    free(A);
}


void Lib_Fmpq_Mat_Mul(FmpqMatPtr X, FmpqMatPtr Y, FmpqMatPtr Z)
{
    fmpq_mat_mul( (fmpq_mat_struct*) X,  (fmpq_mat_struct*) Y,  (fmpq_mat_struct*) Z);
}



void Lib_Fmpq_Mat_Set_Si(FmpqMatPtr A, long i, long j, long p, long q)
{
    fmpq_set_si ( fmpq_mat_entry ((fmpq_mat_struct*)A, i, j), p, q);
}






#undef  Use_fmpq
