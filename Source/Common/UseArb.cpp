
#define Use_arb

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"



void Lib_Arb_Printd(ArbPtr x, long int prec)
{
    arb_printd( (arb_ptr) x, prec);
}


void Lib_Arb_Init(ArbPtr* x)
{
    (*x) =  malloc (sizeof(arb_struct));
    arb_init( (arb_ptr) (*x));
}

void Lib_Arb_Clear(ArbPtr x)
{
    arb_clear( (arb_ptr) x);
    free(x);
}


void Lib_Arb_Mul(ArbPtr x, ArbPtr y, ArbPtr z, long int prec)
{
    arb_mul(  (arb_ptr) x,  (arb_ptr) y,  (arb_ptr) z, prec);
}


void Lib_Arb_Set_Si(ArbPtr x, long a)
{
    arb_set_si( (arb_ptr) x, a);
}


void Lib_Arb_Const_Pi(ArbPtr x, long int prec)
{
    arb_const_pi( (arb_ptr) x, prec);
}




//***************************************************



void Lib_Arb_Mat_Print_Pretty(ArbMatPtr A, long digits)
{
    arb_mat_printd( (arb_mat_struct*) A, digits);
}


void Lib_Arb_Mat_Init(ArbMatPtr* A, long i, long j)
{
    (*A) =  malloc (sizeof(arb_mat_struct));
    arb_mat_init( (arb_mat_struct*) (*A), i, j);
}

void Lib_Arb_Mat_Clear(ArbMatPtr A)
{
    arb_mat_clear( (arb_mat_struct*) A);
    free(A);
}


void Lib_Arb_Mat_Mul(ArbMatPtr X, ArbMatPtr Y, ArbMatPtr Z, long digits)
{
    arb_mat_mul( (arb_mat_struct*) X,  (arb_mat_struct*) Y,  (arb_mat_struct*) Z, digits);
}



void Lib_Arb_Mat_Set_Ui(ArbMatPtr A, long i, long j, long u)
{
    arb_set_ui ( arb_mat_entry ((arb_mat_struct*)A, i, j), u);
}



#undef  Use_arb
