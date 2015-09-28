
#define Use_mpfcr

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

//void Lib_Mpfcr_Printd(MpfcrPtr x, long int prec)
//{
//    mpc_printd( (mpc_ptr) x, prec);
//}




void Lib_Mpfcr_Init(MpfcrPtr* x)
{
    (*x) =  malloc (sizeof(__mpc_struct));
    mpc_init2( (mpc_ptr) (*x), mpfr_get_default_prec());
}

void Lib_Mpfcr_Clear(MpfcrPtr x)
{
    mpc_clear( (mpc_ptr) x);
    free(x);
}



void Lib_Mpfcr_Set_Si(MpfcrPtr x, long a, long rnd)
{
    mpc_set_si( (mpc_ptr) x, a, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Set_Ui(MpfcrPtr x, unsigned int a, long rnd)
{
    mpc_set_ui( (mpc_ptr) x, a, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Set_D(MpfcrPtr x, double d, long rnd)
{
    mpc_set_d( (mpc_ptr) x, d, (mpc_rnd_t) rnd);
}



int Lib_Mpfcr_Set_Str(MpfcrPtr x, const char * str , int base, long rnd)
{
    return mpc_set_str( (mpc_ptr) x, str, base, (mpc_rnd_t) rnd);
}




int Lib_Mpfcr_Real_SnPrintf_SizeInBase10(const char *template1, MpfcrPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_realref((mpc_ptr) x));
}


int Lib_Mpfcr_Real_SnPrintf(char * dest , unsigned int digits, const char *template1, MpfcrPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_realref((mpc_ptr) x));
}



int Lib_Mpfcr_Imag_SnPrintf_SizeInBase10(const char *template1, MpfcrPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_imagref((mpc_ptr) x));
}


int Lib_Mpfcr_Imag_SnPrintf(char * dest , unsigned int digits, const char *template1, MpfcrPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_imagref((mpc_ptr) x));
}



int Lib_Mpfcr_Cmp(MpfcrPtr f, MpfcrPtr g)
{
    return mpc_cmp((mpc_ptr) f, (mpc_ptr) g);
}


void Lib_Mpfcr_Neg(MpfcrPtr f, MpfcrPtr g, long rnd)
{
    mpc_neg( (mpc_ptr) f,  (mpc_ptr) g, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Add(MpfcrPtr f, MpfcrPtr g, MpfcrPtr h, long rnd)
{
    mpc_add( (mpc_ptr) f,  (mpc_ptr) g,  (mpc_ptr) h, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Add_Ui(MpfcrPtr f, MpfcrPtr g,  unsigned int x, long rnd)
{
    mpc_add_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Sub(MpfcrPtr f, MpfcrPtr g, MpfcrPtr h, long rnd)
{
    mpc_sub( (mpc_ptr) f,  (mpc_ptr) g,  (mpc_ptr) h, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Sub_Ui(MpfcrPtr f, MpfcrPtr g,  unsigned int x, long rnd)
{
    mpc_sub_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Mul(MpfcrPtr x, MpfcrPtr y, MpfcrPtr z, long rnd)
{
    mpc_mul( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Mul_Si(MpfcrPtr f, MpfcrPtr g,  int x, long rnd)
{
    mpc_mul_si( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Mul_Ui(MpfcrPtr f, MpfcrPtr g,  unsigned int x, long rnd)
{
    mpc_mul_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}



void Lib_Mpfcr_Div(MpfcrPtr x, MpfcrPtr y, MpfcrPtr z, long rnd)
{
    mpc_div( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}

// NEEDS SIGN CORRECTION
void Lib_Mpfcr_Div_Si(MpfcrPtr f, MpfcrPtr g,  int x, long rnd)
{
    mpc_div_ui( (mpc_ptr) f,  (mpc_ptr) g, (unsigned int) x, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Div_Ui(MpfcrPtr f, MpfcrPtr g,  unsigned int x, long rnd)
{
    mpc_div_ui( (mpc_ptr) f,  (mpc_ptr) g,  x, (mpc_rnd_t) rnd);
}



void Lib_Mpfcr_Mul_2exp(MpfcrPtr x, MpfcrPtr y,  int e, long rnd)
{
    mpc_mul_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Div_2exp(MpfcrPtr x, MpfcrPtr y,  int e, long rnd)
{
    mpc_div_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}



 void Lib_Mpfcr_Pow_Si ( MpfcrPtr f, MpfcrPtr g, int e, long rnd)
{
    mpc_pow_si( (mpc_ptr) f,  (mpc_ptr) g,  e, (mpc_rnd_t) rnd);
}


void Lib_Mpfcr_Pow(MpfcrPtr x, MpfcrPtr y, MpfcrPtr z, long rnd)
{
    mpc_pow( (mpc_ptr) x,  (mpc_ptr) y,  (mpc_ptr) z, (mpc_rnd_t) rnd);
}


























#undef  Use_mpfcr
