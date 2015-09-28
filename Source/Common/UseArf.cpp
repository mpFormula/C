
#define Use_arf

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"

#include <string.h>

void Lib_Arf_Printd(ArfPtr x, int32_t prec)
{
    arf_printd( (arf_ptr) x, prec);
}


void Lib_Arf_Init(ArfPtr* x)
{
    (*x) =  malloc (sizeof(arf_struct));
    arf_init( (arf_ptr) (*x));
}

void Lib_Arf_Clear(ArfPtr x)
{
    arf_clear( (arf_ptr) x);
    free(x);
}



void Lib_Arf_Set_Si(ArfPtr x, int32_t a)
{
    arf_set_si( (arf_ptr) x, a);
}


void Lib_Arf_Set_Ui(ArfPtr x, uint32_t a)
{
    arf_set_ui( (arf_ptr) x, a);
}


void Lib_Arf_Set_Mpfr(ArfPtr x, MpfrPtr a)
{
    arf_set_mpfr((arf_ptr) x, (mpfr_ptr) a);
}


void Lib_Arf_Set_D(ArfPtr x, double d)
{
    arf_set_d((arf_ptr)x, d);
}


int32_t Lib_Arf_Set_Str(ArfPtr x, const char * str , int32_t prec)
{
    arb_t xrop; arb_init(xrop); arb_set_arf(xrop, (arf_ptr) x);
    int32_t res = arb_set_str( xrop, str, prec);
    arb_clear(xrop);
    return res;
}


double Lib_Arf_Get_D(ArfPtr x)
{
    return arf_get_d( (arf_ptr) x, ARF_RND_DOWN);
}


uint32_t Lib_Arf_Get_Ui(ArfPtr x)
{
    return (uint32_t ) arf_get_si((arf_ptr) x, ARF_RND_DOWN);
}


int32_t Lib_Arf_Get_Si(ArfPtr x)
{
    return arf_get_si((arf_ptr) x, ARF_RND_DOWN);
}



uint32_t Lib_Arf_SizeInBase10(ArfPtr x, int32_t n, uint32_t flags)
{
    arb_t xrop; arb_init(xrop); arb_set_arf(xrop, (arf_ptr) x);
    char * src = arb_get_str(xrop, n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    arb_clear(xrop);
    return res;
}




char * Lib_Arf_Get_Str(char * dest , ArfPtr x, int32_t n, uint32_t flags)
{
    arb_t xrop; arb_init(xrop); arb_set_arf(xrop, (arf_ptr) x);
    char * src = arb_get_str(xrop, n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    arb_clear(xrop);
    return res;
}


int32_t Lib_Arf_Cmp(ArfPtr f, ArfPtr g)
{
    return arf_cmp( (arf_ptr) f, (arf_ptr) g);
}


void Lib_Arf_Neg(ArfPtr f, ArfPtr g)
{
    arf_neg( (arf_ptr) f,  (arf_ptr) g);
}


void Lib_Arf_Add(ArfPtr f, ArfPtr g, ArfPtr h, int32_t prec)
{
    arf_add( (arf_ptr) f,  (arf_ptr) g,  (arf_ptr) h, prec, ARF_RND_DOWN);
}


void Lib_Arf_Add_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec)
{
    arf_add_ui( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}


void Lib_Arf_Sub(ArfPtr f, ArfPtr g, ArfPtr h, int32_t prec)
{
    arf_sub( (arf_ptr) f,  (arf_ptr) g,  (arf_ptr) h, prec, ARF_RND_DOWN);
}


void Lib_Arf_Sub_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec)
{
    arf_sub_ui( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}


void Lib_Arf_Mul(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec, arf_rnd_t rnd)
{
    arf_mul( (arf_ptr) x,  (arf_ptr) y,  (arf_ptr) z, prec, rnd);
}


void Lib_Arf_Mul_Si(ArfPtr f, ArfPtr g,  int32_t x, int32_t prec)
{
    arf_mul_si( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}


void Lib_Arf_Mul_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec)
{
    arf_mul_ui( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}



void Lib_Arf_Div(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec)
{
    arf_div( (arf_ptr) x,  (arf_ptr) y,  (arf_ptr) z, prec, ARF_RND_DOWN);
}


void Lib_Arf_Div_Si(ArfPtr f, ArfPtr g,  int32_t x, int32_t prec)
{
    arf_div_si( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}


void Lib_Arf_Div_Ui(ArfPtr f, ArfPtr g,  uint32_t x, int32_t prec)
{
    arf_div_ui( (arf_ptr) f,  (arf_ptr) g,  x, prec, ARF_RND_DOWN);
}



void Lib_Arf_Mul_2exp(ArfPtr x, ArfPtr y,  int32_t e)
{
    arf_mul_2exp_si(  (arf_ptr) x,  (arf_ptr) y,  e);
}


void Lib_Arf_Div_2exp(ArfPtr x, ArfPtr y,  int32_t e)
{
    arf_mul_2exp_si(  (arf_ptr) x,  (arf_ptr) y,  -e);
}

void Lib_Arf_Div_Fmpz(ArfPtr x, ArfPtr y, FmpzPtr z, int32_t prec)
{
    arf_div_fmpz( (arf_ptr) x,  (arf_ptr) y,  (fmpz*) z, prec, ARF_RND_DOWN);
}



 void Lib_Arf_Pow_Si ( ArfPtr f, ArfPtr g, int32_t e, int32_t prec)
{
    arf_t xrop; arf_init(xrop); arf_set_si(xrop, e);
    Lib_Arf_Pow( f,  g, xrop, prec);
    arf_clear(xrop);
}


void Lib_Arf_Pow(ArfPtr x, ArfPtr y, ArfPtr z, int32_t prec)
{
    arb_t xrop; arb_init(xrop); arb_set_arf(xrop, (arf_ptr) x);
    arb_t yrop; arb_init(yrop); arb_set_arf(yrop, (arf_ptr) y);
    arb_t zrop; arb_init(zrop);

    arb_pow( xrop, yrop, zrop, prec);
    arf_set( (arf_ptr) x, arb_midref(xrop));

    arb_clear(xrop);
    arb_clear(yrop);
    arb_clear(zrop);
}






#undef  Use_arf
