
#define Use_acf

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"
#include "acb.h"
#include "acb_mat.h"

#include <string.h>

void Lib_Acf_Printd(AcfPtr x, int32_t prec)
{
    acb_printd( (acb_ptr) x, prec);
}


void Lib_Acf_Init(AcfPtr* x)
{
    (*x) =  malloc (sizeof(acb_struct));
    acb_init( (acb_ptr) (*x));
}

void Lib_Acf_Clear(AcfPtr x)
{
    acb_clear( (acb_ptr) x);
    free(x);
}


void Lib_Acf_Const_Pi(AcfPtr x, int32_t prec)
{
    acb_const_pi( (acb_ptr) x, prec);
}






void Lib_Acf_Set_Si(AcfPtr x, int32_t a)
{
    acb_set_si( (acb_ptr) x, a);
}


void Lib_Acf_Set_Ui(AcfPtr x, uint32_t a)
{
    acb_set_ui( (acb_ptr) x, a);
}


void Lib_Acf_Set_Arb(AcfPtr x, ArbPtr a)
{
    acb_set_arb( (acb_ptr) x, (arb_ptr) a);
}


void Lib_Acf_Set_Mpfr(AcfPtr x, mpfr_t a)
{
arb_t rop;
arb_init(rop);
Lib_Arb_Set_Mpfr(rop, a);
acb_set_arb((acb_ptr)x, rop);
arb_clear(rop);
}


void Lib_Acf_Set_D(AcfPtr x, double d)
{
arb_t rop;
arb_init(rop);
Lib_Arb_Set_D(rop, d);
acb_set_arb((acb_ptr)x, rop);
arb_clear(rop);
}


int32_t Lib_Acf_Set_Real_Str(AcfPtr x, const char * str , int32_t prec)
{
    return arb_set_str( acb_realref((acb_ptr) x), str, prec);
}


int32_t Lib_Acf_Set_Imag_Str(AcfPtr x, const char * str , int32_t prec)
{
    return arb_set_str( acb_imagref((acb_ptr) x), str, prec);
}



uint32_t Lib_Acf_Real_SizeInBase10(AcfPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_realref((acb_ptr) x), n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}

char * Lib_Acf_Get_Real_Str(char * dest , AcfPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_realref((acb_ptr) x), n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


uint32_t Lib_Acf_Imag_SizeInBase10(AcfPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_imagref((acb_ptr) x), n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}

char * Lib_Acf_Get_Imag_Str(char * dest , AcfPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_imagref((acb_ptr) x), n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


int32_t Lib_Acf_Eq(AcfPtr f, AcfPtr g)
{
    return acb_eq( (acb_ptr) f,  (acb_ptr) g);
}


int32_t Lib_Acf_Ne(AcfPtr f, AcfPtr g)
{
    return acb_ne( (acb_ptr) f,  (acb_ptr) g);
}


void Lib_Acf_Neg(AcfPtr f, AcfPtr g)
{
    acb_neg( (acb_ptr) f,  (acb_ptr) g);
}


void Lib_Acf_Add(AcfPtr f, AcfPtr g, AcfPtr h, int32_t prec)
{
    acb_add( (acb_ptr) f,  (acb_ptr) g,  (acb_ptr) h, prec);
}


void Lib_Acf_Add_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec)
{
    acb_add_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acf_Sub(AcfPtr f, AcfPtr g, AcfPtr h, int32_t prec)
{
    acb_sub( (acb_ptr) f,  (acb_ptr) g,  (acb_ptr) h, prec);
}


void Lib_Acf_Sub_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec)
{
    acb_sub_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acf_Mul(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec)
{
    acb_mul( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}


void Lib_Acf_Mul_Si(AcfPtr f, AcfPtr g,  int32_t x, int32_t prec)
{
    acb_mul_si( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acf_Mul_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec)
{
    acb_mul_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}



void Lib_Acf_Div(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec)
{
    acb_div( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}


void Lib_Acf_Div_Si(AcfPtr f, AcfPtr g,  int32_t x, int32_t prec)
{
    acb_div_si( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acf_Div_Ui(AcfPtr f, AcfPtr g,  uint32_t x, int32_t prec)
{
    acb_div_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}



void Lib_Acf_Mul_2exp(AcfPtr x, AcfPtr y,  int32_t e)
{
    acb_mul_2exp_si(  (acb_ptr) x,  (acb_ptr) y,  e);
}


void Lib_Acf_Div_2exp(AcfPtr x, AcfPtr y,  int32_t e)
{
    acb_mul_2exp_si(  (acb_ptr) x,  (acb_ptr) y,  -e);
}

void Lib_Acf_Div_Fmpz(AcfPtr x, AcfPtr y, FmpzPtr z, int32_t prec)
{
    acb_div_fmpz( (acb_ptr) x,  (acb_ptr) y,  (fmpz*) z, prec);
}



 void Lib_Acf_Pow_Si ( AcfPtr f, AcfPtr g, int32_t e, int32_t prec)
{
    acb_pow_si( (acb_ptr) f,  (acb_ptr) g,  e, prec);
}


void Lib_Acf_Pow(AcfPtr x, AcfPtr y, AcfPtr z, int32_t prec)
{
    acb_pow( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}












#undef  Use_acf
