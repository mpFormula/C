
#define Use_arb

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"

#include <string.h>

void Lib_Arb_Printd(ArbPtr x, int32_t prec)
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


void Lib_Arb_Const_Pi(ArbPtr x, int32_t prec)
{
    arb_const_pi( (arb_ptr) x, prec);
}



void Lib_Arb_Set_Si(ArbPtr x, int32_t a)
{
    arb_set_si( (arb_ptr) x, a);
}


void Lib_Arb_Set_Ui(ArbPtr x, uint32_t a)
{
    arb_set_ui( (arb_ptr) x, a);
}


void Lib_Arb_Set_Mpfr(ArbPtr x, MpfrPtr a)
{
arf_t rop;
arf_init(rop);
arf_set_mpfr(rop, (mpfr_ptr) a);
arb_set_arf((arb_ptr) x,  rop);
arf_clear(rop);
}


void Lib_Arb_Set_D(ArbPtr x, double d)
{
arf_t rop;
arf_init(rop);
arf_set_d(rop, d);
arb_set_arf((arb_ptr)x, rop);
arf_clear(rop);
}


int32_t Lib_Arb_Set_Str(ArbPtr x, const char * str , int32_t prec)
{
    return arb_set_str( (arb_ptr) x, str, prec);
}


double Lib_Arb_Get_D(ArbPtr x)
{
    return arf_get_d( arb_midref((arb_ptr) x), ARF_RND_DOWN);
}


uint32_t Lib_Arb_Get_Ui(ArbPtr x)
{
    return (uint32_t ) arf_get_si( arb_midref((arb_ptr) x), ARF_RND_DOWN);
}


int32_t Lib_Arb_Get_Si(ArbPtr x)
{
    return arf_get_si( arb_midref((arb_ptr) x), ARF_RND_DOWN);
}



uint32_t Lib_Arb_SizeInBase10(ArbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str((arb_ptr) x, n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}




char * Lib_Arb_Get_Str(char * dest , ArbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str((arb_ptr) x, n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


int32_t Lib_Arb_Cmp(ArbPtr f, ArbPtr g)
{
    return arf_cmp( arb_midref((arb_ptr) f),  arb_midref((arb_ptr) g));
}


void Lib_Arb_Neg(ArbPtr f, ArbPtr g)
{
    arb_neg( (arb_ptr) f,  (arb_ptr) g);
}


void Lib_Arb_Add(ArbPtr f, ArbPtr g, ArbPtr h, int32_t prec)
{
    arb_add( (arb_ptr) f,  (arb_ptr) g,  (arb_ptr) h, prec);
}


void Lib_Arb_Add_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec)
{
    arb_add_ui( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}


void Lib_Arb_Sub(ArbPtr f, ArbPtr g, ArbPtr h, int32_t prec)
{
    arb_sub( (arb_ptr) f,  (arb_ptr) g,  (arb_ptr) h, prec);
}


void Lib_Arb_Sub_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec)
{
    arb_sub_ui( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}


void Lib_Arb_Mul(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec)
{
    arb_mul( (arb_ptr) x,  (arb_ptr) y,  (arb_ptr) z, prec);
}


void Lib_Arb_Mul_Si(ArbPtr f, ArbPtr g,  int32_t x, int32_t prec)
{
    arb_mul_si( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}


void Lib_Arb_Mul_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec)
{
    arb_mul_ui( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}



void Lib_Arb_Div(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec)
{
    arb_div( (arb_ptr) x,  (arb_ptr) y,  (arb_ptr) z, prec);
}


void Lib_Arb_Div_Si(ArbPtr f, ArbPtr g,  int32_t x, int32_t prec)
{
    arb_div_si( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}


void Lib_Arb_Div_Ui(ArbPtr f, ArbPtr g,  uint32_t x, int32_t prec)
{
    arb_div_ui( (arb_ptr) f,  (arb_ptr) g,  x, prec);
}



void Lib_Arb_Mul_2exp(ArbPtr x, ArbPtr y,  int32_t e)
{
    arb_mul_2exp_si(  (arb_ptr) x,  (arb_ptr) y,  e);
}


void Lib_Arb_Div_2exp(ArbPtr x, ArbPtr y,  int32_t e)
{
    arb_mul_2exp_si(  (arb_ptr) x,  (arb_ptr) y,  -e);
}

void Lib_Arb_Div_Fmpz(ArbPtr x, ArbPtr y, FmpzPtr z, int32_t prec)
{
    arb_div_fmpz( (arb_ptr) x,  (arb_ptr) y,  (fmpz*) z, prec);
}

//
// int32_t Lib_Arb_Mod_Fmpz ( ArbPtr f, ArbPtr g, FmpzPtr h)
//{
//    return arb_mod_fmpz (  (fmpz*) f,  (arb_ptr) g, (fmpz*) h);
//}


 void Lib_Arb_Pow_Ui ( ArbPtr f, ArbPtr g, int32_t e, int32_t prec)
{
    arb_pow_ui( (arb_ptr) f,  (arb_ptr) g,  e, prec);
}


void Lib_Arb_Pow(ArbPtr x, ArbPtr y, ArbPtr z, int32_t prec)
{
    arb_pow( (arb_ptr) x,  (arb_ptr) y,  (arb_ptr) z, prec);
}



























//***************************************************



void Lib_Arb_Mat_Print_Pretty(ArbMatPtr A, int32_t digits)
{
    arb_mat_printd( (arb_mat_struct*) A, digits);
}


void Lib_Arb_Mat_Init(ArbMatPtr* A, int32_t i, int32_t j)
{
    (*A) =  malloc (sizeof(arb_mat_struct));
    arb_mat_init( (arb_mat_struct*) (*A), i, j);
}

void Lib_Arb_Mat_Clear(ArbMatPtr A)
{
    arb_mat_clear( (arb_mat_struct*) A);
    free(A);
}


void Lib_Arb_Mat_Mul(ArbMatPtr X, ArbMatPtr Y, ArbMatPtr Z, int32_t digits)
{
    arb_mat_mul( (arb_mat_struct*) X,  (arb_mat_struct*) Y,  (arb_mat_struct*) Z, digits);
}



void Lib_Arb_Mat_Set_Ui(ArbMatPtr A, int32_t i, int32_t j, int32_t u)
{
    arb_set_ui ( arb_mat_entry ((arb_mat_struct*)A, i, j), u);
}



#undef  Use_arb
