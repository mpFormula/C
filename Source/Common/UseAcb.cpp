
#define Use_acb

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include "arb.h"
#include "arb_mat.h"
#include "acb.h"
#include "acb_mat.h"

#include <string.h>

void Lib_Acb_Printd(AcbPtr x, int32_t prec)
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


void Lib_Acb_Const_Pi(AcbPtr x, int32_t prec)
{
    acb_const_pi( (acb_ptr) x, prec);
}






void Lib_Acb_Set_Si(AcbPtr x, int32_t a)
{
    acb_set_si( (acb_ptr) x, a);
}


void Lib_Acb_Set_Ui(AcbPtr x, uint32_t a)
{
    acb_set_ui( (acb_ptr) x, a);
}


void Lib_Acb_Set_Arb(AcbPtr x, ArbPtr a)
{
    acb_set_arb( (acb_ptr) x, (arb_ptr) a);
}


void Lib_Acb_Set_Mpfr(AcbPtr x, mpfr_t a)
{
arb_t rop;
arb_init(rop);
Lib_Arb_Set_Mpfr(rop, a);
acb_set_arb((acb_ptr)x, rop);
arb_clear(rop);
}


void Lib_Acb_Set_D(AcbPtr x, double d)
{
arb_t rop;
arb_init(rop);
Lib_Arb_Set_D(rop, d);
acb_set_arb((acb_ptr)x, rop);
arb_clear(rop);
}


int32_t Lib_Acb_Set_Real_Str(AcbPtr x, const char * str , int32_t prec)
{
    return arb_set_str( acb_realref((acb_ptr) x), str, prec);
}


int32_t Lib_Acb_Set_Imag_Str(AcbPtr x, const char * str , int32_t prec)
{
    return arb_set_str( acb_imagref((acb_ptr) x), str, prec);
}



uint32_t Lib_Acb_Real_SizeInBase10(AcbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_realref((acb_ptr) x), n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}

char * Lib_Acb_Get_Real_Str(char * dest , AcbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_realref((acb_ptr) x), n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


uint32_t Lib_Acb_Imag_SizeInBase10(AcbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_imagref((acb_ptr) x), n, flags);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}

char * Lib_Acb_Get_Imag_Str(char * dest , AcbPtr x, int32_t n, uint32_t flags)
{
    char * src = arb_get_str( acb_imagref((acb_ptr) x), n, flags);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


int32_t Lib_Acb_Eq(AcbPtr f, AcbPtr g)
{
    return acb_eq( (acb_ptr) f,  (acb_ptr) g);
}


int32_t Lib_Acb_Ne(AcbPtr f, AcbPtr g)
{
    return acb_ne( (acb_ptr) f,  (acb_ptr) g);
}


void Lib_Acb_Neg(AcbPtr f, AcbPtr g)
{
    acb_neg( (acb_ptr) f,  (acb_ptr) g);
}


void Lib_Acb_Add(AcbPtr f, AcbPtr g, AcbPtr h, int32_t prec)
{
    acb_add( (acb_ptr) f,  (acb_ptr) g,  (acb_ptr) h, prec);
}


void Lib_Acb_Add_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec)
{
    acb_add_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acb_Sub(AcbPtr f, AcbPtr g, AcbPtr h, int32_t prec)
{
    acb_sub( (acb_ptr) f,  (acb_ptr) g,  (acb_ptr) h, prec);
}


void Lib_Acb_Sub_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec)
{
    acb_sub_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acb_Mul(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec)
{
    acb_mul( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}


void Lib_Acb_Mul_Si(AcbPtr f, AcbPtr g,  int32_t x, int32_t prec)
{
    acb_mul_si( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acb_Mul_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec)
{
    acb_mul_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}



void Lib_Acb_Div(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec)
{
    acb_div( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}


void Lib_Acb_Div_Si(AcbPtr f, AcbPtr g,  int32_t x, int32_t prec)
{
    acb_div_si( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}


void Lib_Acb_Div_Ui(AcbPtr f, AcbPtr g,  uint32_t x, int32_t prec)
{
    acb_div_ui( (acb_ptr) f,  (acb_ptr) g,  x, prec);
}



void Lib_Acb_Mul_2exp(AcbPtr x, AcbPtr y,  int32_t e)
{
    acb_mul_2exp_si(  (acb_ptr) x,  (acb_ptr) y,  e);
}


void Lib_Acb_Div_2exp(AcbPtr x, AcbPtr y,  int32_t e)
{
    acb_mul_2exp_si(  (acb_ptr) x,  (acb_ptr) y,  -e);
}

void Lib_Acb_Div_Fmpz(AcbPtr x, AcbPtr y, FmpzPtr z, int32_t prec)
{
    acb_div_fmpz( (acb_ptr) x,  (acb_ptr) y,  (fmpz*) z, prec);
}

//
// int32_t Lib_Acb_Mod_Fmpz ( AcbPtr f, AcbPtr g, FmpzPtr h)
//{
//    return acb_mod_fmpz (  (fmpz*) f,  (acb_ptr) g, (fmpz*) h);
//}


 void Lib_Acb_Pow_Si ( AcbPtr f, AcbPtr g, int32_t e, int32_t prec)
{
    acb_pow_si( (acb_ptr) f,  (acb_ptr) g,  e, prec);
}


void Lib_Acb_Pow(AcbPtr x, AcbPtr y, AcbPtr z, int32_t prec)
{
    acb_pow( (acb_ptr) x,  (acb_ptr) y,  (acb_ptr) z, prec);
}













//***************************************************



void Lib_Acb_Mat_Print_Pretty(AcbMatPtr A, int32_t digits)
{
    acb_mat_printd( (acb_mat_struct*) A, digits);
}


void Lib_Acb_Mat_Init(AcbMatPtr* A, int32_t i, int32_t j)
{
    (*A) =  malloc (sizeof(acb_mat_struct));
    acb_mat_init( (acb_mat_struct*) (*A), i, j);
}

void Lib_Acb_Mat_Clear(AcbMatPtr A)
{
    acb_mat_clear( (acb_mat_struct*) A);
    free(A);
}


void Lib_Acb_Mat_Mul(AcbMatPtr X, AcbMatPtr Y, AcbMatPtr Z, int32_t digits)
{
    acb_mat_mul( (acb_mat_struct*) X,  (acb_mat_struct*) Y,  (acb_mat_struct*) Z, digits);
}



void Lib_Acb_Mat_Set_Ui(AcbMatPtr A, int32_t i, int32_t j, int32_t u)
{
    acb_set_ui ( acb_mat_entry ((acb_mat_struct*)A, i, j), u);
}




#undef  Use_acb
