
#define Use_acb

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"
#include "acb.h"
#include "acb_mat.h"



void Lib_Acb_Printd(AcbPtr x, long int prec)
{
    acb_printd( (acb_ptr) x, prec);
}


void Lib_Acb_Init(AcbPtr* x)
{
    (*x) =  malloc (sizeof(acb_struct));
    acb_init( (acb_ptr) (*x));
}

void Lib_Acb_Clear(AcbPtr x)
{
    acb_clear( (acb_ptr) x);
    free(x);
}


void Lib_Acb_Mul(AcbPtr x, AcbPtr y, AcbPtr z, long int prec)
{
    acb_mul(  (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}


void Lib_Acb_Set_Si(AcbPtr x, long a)
{
    acb_set_si( (acb_ptr) x, a);
}


void Lib_Acb_Set_Arb(AcbPtr x, ArbPtr y)
{
    acb_set_arb( (acb_ptr) x, (arb_ptr) y);
}


void Lib_Acb_Const_Pi(AcbPtr x, long int prec)
{
    acb_const_pi( (acb_ptr) x, prec);
}



//***************************************************



void Lib_Acb_Mat_Print_Pretty(AcbMatPtr A, long digits)
{
    acb_mat_printd( (acb_mat_struct*) A, digits);
}


void Lib_Acb_Mat_Init(AcbMatPtr* A, long i, long j)
{
    (*A) =  malloc (sizeof(acb_mat_struct));
    acb_mat_init( (acb_mat_struct*) (*A), i, j);
}

void Lib_Acb_Mat_Clear(AcbMatPtr A)
{
    acb_mat_clear( (acb_mat_struct*) A);
    free(A);
}


void Lib_Acb_Mat_Mul(AcbMatPtr X, AcbMatPtr Y, AcbMatPtr Z, long digits)
{
    acb_mat_mul( (acb_mat_struct*) X,  (acb_mat_struct*) Y,  (acb_mat_struct*) Z, digits);
}



void Lib_Acb_Mat_Set_Ui(AcbMatPtr A, long i, long j, long u)
{
    acb_set_ui ( acb_mat_entry ((acb_mat_struct*)A, i, j), u);
}




#undef  Use_acb
