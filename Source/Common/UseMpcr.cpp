
#define Use_mpcr

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <mpc.h>

#include <flint.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"


#include <string.h>

//void Lib_Mpcr_Printd(MpcrPtr x, long int prec)
//{
//    mpc_printd( (mpc_ptr) x, prec);
//}




void Lib_Mpcr_Init(MpcrPtr* x)
{
    (*x) =  malloc (sizeof(__mpc_struct));
    mpc_init2( (mpc_ptr) (*x), mpfr_get_default_prec());
}

void Lib_Mpcr_Clear(MpcrPtr x)
{
    mpc_clear( (mpc_ptr) x);
    free(x);
}



void Lib_Mpcr_Set_Si(MpcrPtr x, long a, long rnd)
{
    mpc_set_si( (mpc_ptr) x, a, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Set_Ui(MpcrPtr x, unsigned int a, long rnd)
{
    mpc_set_ui( (mpc_ptr) x, a, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Set_D(MpcrPtr x, double d, long rnd)
{
    mpc_set_d( (mpc_ptr) x, d, (mpc_rnd_t) rnd);
}



int Lib_Mpcr_Set_Str(MpcrPtr x, const char * str , int base, long rnd)
{
    return mpc_set_str( (mpc_ptr) x, str, base, (mpc_rnd_t) rnd);
}




int Lib_Mpcr_Real_SnPrintf_SizeInBase10(const char *template1, MpcrPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_realref((mpc_ptr) x));
}


int Lib_Mpcr_Real_SnPrintf(char * dest , unsigned int digits, const char *template1, MpcrPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_realref((mpc_ptr) x));
}



int Lib_Mpcr_Imag_SnPrintf_SizeInBase10(const char *template1, MpcrPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_imagref((mpc_ptr) x));
}


int Lib_Mpcr_Imag_SnPrintf(char * dest , unsigned int digits, const char *template1, MpcrPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_imagref((mpc_ptr) x));
}



int Lib_Mpcr_Cmp(MpcrPtr f, MpcrPtr g)
{
    return mpc_cmp((mpc_ptr) f, (mpc_ptr) g);
}


void Lib_Mpcr_Neg(MpcrPtr f, MpcrPtr g, long rnd)
{
    mpc_neg( (mpc_ptr) f,  (mpc_ptr) g, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Add(MpcrPtr f, MpcrPtr g, MpcrPtr h, long rnd)
{
    mpc_add( (mpc_ptr) f,  (mpc_ptr) g,  (mpc_ptr) h, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Add_Ui(MpcrPtr f, MpcrPtr g,  unsigned int x, long rnd)
{
    mpc_add_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Sub(MpcrPtr f, MpcrPtr g, MpcrPtr h, long rnd)
{
    mpc_sub( (mpc_ptr) f,  (mpc_ptr) g,  (mpc_ptr) h, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Sub_Ui(MpcrPtr f, MpcrPtr g,  unsigned int x, long rnd)
{
    mpc_sub_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Mul(MpcrPtr x, MpcrPtr y, MpcrPtr z, long rnd)
{
    mpc_mul( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Mul_Si(MpcrPtr f, MpcrPtr g,  int x, long rnd)
{
    mpc_mul_si( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Mul_Ui(MpcrPtr f, MpcrPtr g,  unsigned int x, long rnd)
{
    mpc_mul_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}



void Lib_Mpcr_Div(MpcrPtr x, MpcrPtr y, MpcrPtr z, long rnd)
{
    mpc_div( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}

// NEEDS SIGN CORRECTION
void Lib_Mpcr_Div_Si(MpcrPtr f, MpcrPtr g,  int x, long rnd)
{
    mpc_div_ui( (mpc_ptr) f,  (mpc_ptr) g, (unsigned int) x, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Div_Ui(MpcrPtr f, MpcrPtr g,  unsigned int x, long rnd)
{
    mpc_div_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}



void Lib_Mpcr_Mul_2exp(MpcrPtr x, MpcrPtr y,  int e, long rnd)
{
    mpc_mul_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Div_2exp(MpcrPtr x, MpcrPtr y,  int e, long rnd)
{
    mpc_div_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}



 void Lib_Mpcr_Pow_Si ( MpcrPtr f, MpcrPtr g, int e, long rnd)
{
    mpc_pow_si( (mpc_ptr) f,  (mpc_ptr) g,  e, (mpc_rnd_t) rnd);
}


void Lib_Mpcr_Pow(MpcrPtr x, MpcrPtr y, MpcrPtr z, long rnd)
{
    mpc_pow( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}



























//***************************************************


//
//void Lib_Mpcr_Mat_Print_Pretty(MpfrMatPtr A, long digits)
//{
//    mpc_mat_printd( (mpc_mat_struct*) A, digits);
//}
//
//
//void Lib_Mpcr_Mat_Init(MpfrMatPtr* A, long i, long j)
//{
//    (*A) =  malloc (sizeof(mpc_mat_struct));
//    mpc_mat_init( (mpc_mat_struct*) (*A), i, j);
//}
//
//void Lib_Mpcr_Mat_Clear(MpfrMatPtr A)
//{
//    mpc_mat_clear( (mpc_mat_struct*) A);
//    free(A);
//}
//
//
//void Lib_Mpcr_Mat_Mul(MpfrMatPtr X, MpfrMatPtr Y, MpfrMatPtr Z, long digits)
//{
//    mpc_mat_mul( (mpc_mat_struct*) X,  (mpc_mat_struct*) Y,  (mpc_mat_struct*) Z, digits);
//}
//
//
//
//void Lib_Mpcr_Mat_Set_Ui(MpfrMatPtr A, long i, long j, long u)
//{
//    mpc_set_ui ( mpc_mat_entry ((mpc_mat_struct*)A, i, j), u);
//}



#undef  Use_mpcr
