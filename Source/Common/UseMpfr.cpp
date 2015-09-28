
#include "mpNumC_Short.h"

#include <gmp.h>
#include <mpfr.h>
#include <stdlib.h>
#include <string.h>



void Lib_Mpfr_Urandomb(MpfrPtr res, GmpRandPtr state)
{
    mpfr_urandomb((mpfr_ptr) res,  (__gmp_randstate_struct*) state);
}


void Lib_Mpfr_Set_Default_Prec (int32_t prec)
{
    mpfr_set_default_prec ((mpfr_prec_t) prec);
}


int32_t Lib_Mpfr_Get_Default_Prec (void)
{
    return (int32_t) mpfr_get_default_prec ();
}


void Lib_Mpfr_Set_Default_Rounding_Mode (int32_t rnd)
{
    mpfr_set_default_rounding_mode ((mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Get_Default_Rounding_Mode (void)
{
    return (int32_t) mpfr_get_default_rounding_mode ();
}



void Lib_Mpfr_Init(MpfrPtr* x)
{
    (*x) =  malloc (sizeof(__mpfr_struct));
    mpfr_init( (mpfr_ptr) (*x));
}

void Lib_Mpfr_Clear(MpfrPtr x)
{
    mpfr_clear( (mpfr_ptr) x);
    free(x);
}




void Lib_Mpfr_Set_Prec(MpfrPtr x, int32_t prec)
{
    mpfr_set_prec( (mpfr_ptr) x, (mpfr_prec_t) prec);
}



int32_t Lib_Mpfr_Get_Prec(MpfrPtr x)
{
    return (int32_t) mpfr_get_prec( (mpfr_ptr) x);
}


//**********************************************************



int32_t Lib_Mpfr_Set(MpfrPtr x, MpfrPtr y, int32_t rnd)
{
    return mpfr_set( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_Ui(MpfrPtr x, uint32_t a, int32_t rnd)
{
    return mpfr_set_ui( (mpfr_ptr) x, a, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_Si(MpfrPtr x, int32_t a, int32_t rnd)
{
    return mpfr_set_si( (mpfr_ptr) x, a, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Set_Ui64(MpfrPtr x, uint64_t a, int32_t rnd)
{
    return mpfr_set_uj( (mpfr_ptr) x, a, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_Si64(MpfrPtr x, int64_t a, int32_t rnd)
{
    return mpfr_set_sj( (mpfr_ptr) x, a, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Set_Flt(MpfrPtr x, float d, int32_t rnd)
{
    return mpfr_set_flt( (mpfr_ptr) x, d, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_D(MpfrPtr x, double d, int32_t rnd)
{
    return mpfr_set_d( (mpfr_ptr) x, d, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_Ld(MpfrPtr x, long double d, int32_t rnd)
{
    return mpfr_set_ld( (mpfr_ptr) x, d, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Set_Mpz(MpfrPtr x, MpzPtr z, int32_t rnd)
{
    return mpfr_set_z( (mpfr_ptr) x, (mpz_ptr) z, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Set_Mpq(MpfrPtr x, MpqPtr q, int32_t rnd)
{
    return mpfr_set_q( (mpfr_ptr) x, (mpq_ptr) q, (mpfr_rnd_t) rnd);
}





int32_t Lib_Mpfr_Set_Str(MpfrPtr x, const char * str , int32_t base, int32_t rnd)
{
    return mpfr_set_str( (mpfr_ptr) x, str, base, (mpfr_rnd_t) rnd);
}


//**********************************************


void Lib_Mpfr_Set_Nan(MpfrPtr x)
{
    mpfr_set_nan( (mpfr_ptr) x);
}


void Lib_Mpfr_Set_Inf(MpfrPtr x, int32_t sign)
{
    mpfr_set_inf( (mpfr_ptr) x, sign);
}


void Lib_Mpfr_Set_Zero(MpfrPtr x, int32_t sign)
{
    mpfr_set_zero( (mpfr_ptr) x, sign);
}


void Lib_Mpfr_Swap(MpfrPtr x, MpfrPtr y)
{
    mpfr_swap( (mpfr_ptr) x,  (mpfr_ptr) y);
}


//**********************************************









uint32_t Lib_Mpfr_Get_Ui(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_ui( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Get_Si(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_si( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


uint64_t Lib_Mpfr_Get_Ui64(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_uj( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int64_t Lib_Mpfr_Get_Si64(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_sj( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



float Lib_Mpfr_Get_Flt(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_flt( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


double Lib_Mpfr_Get_D(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_d( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



long double Lib_Mpfr_Get_Ld(MpfrPtr x, int32_t rnd)
{
    return mpfr_get_ld( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Get_Mpz( MpzPtr x, MpfrPtr y, int32_t rnd)
{
    return mpfr_get_z (  (mpz_ptr) x, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Get_Mpq( MpqPtr q, MpfrPtr y, int32_t rnd)
{
    mpf_t t; mpf_init(t);
    int32_t res = mpfr_get_f(t, (mpfr_ptr) y,  (mpfr_rnd_t) rnd);
    mpq_set_f( (mpq_ptr) q, t);
    mpf_clear(t);
    return res;
}


//******************************************************


//double Lib_Mpfr_Get_D_2exp(int32_t *exp, MpfrPtr x, int32_t rnd)
//{
//    return mpfr_get_d_2exp(exp, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
//}


//int32_t double Lib_Mpfr_Get_Ld_2exp(int32_t *exp, MpfrPtr x, int32_t rnd)
//{
//    return mpfr_get_ld_2exp(exp, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
//}


int32_t Lib_Mpfr_Frexp(int32_t *exp, MpfrPtr y, MpfrPtr x, int32_t rnd)
{
    return mpfr_frexp( (mpfr_exp_t*) exp, (mpfr_ptr) y, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Get_Mpz_2exp( MpzPtr x, MpfrPtr y)
{
    mpfr_exp_t res = mpfr_get_z_exp( (mpz_ptr) x, (mpfr_ptr) y);
    return (int32_t) res;
}


int32_t Lib_Mpfr_Print( const char *template1, MpfrPtr x)
{
    return mpfr_printf(template1, (mpfr_ptr) x);
}


int32_t Lib_Mpfr_SnPrintf_SizeInBase10(const char *template1, MpfrPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, (mpfr_ptr) x);
}


int32_t Lib_Mpfr_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfrPtr x)
{
    return mpfr_snprintf(dest, digits, template1, (mpfr_ptr) x);
}



int32_t Lib_Mpfr_Cmp(MpfrPtr f, MpfrPtr g)
{
    return mpfr_cmp((mpfr_ptr) f, (mpfr_ptr) g);
}


int32_t Lib_Mpfr_Neg(MpfrPtr f, MpfrPtr g, int32_t rnd)
{
    return mpfr_neg( (mpfr_ptr) f,  (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


// ********* Basic Arithmetic Functions *******************



int32_t Lib_Mpfr_Add(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_add( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Add_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd)
{
    return mpfr_add_ui( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Add_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd)
{
    return mpfr_add_si( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Add_Ui64(MpfrPtr res, MpfrPtr x, uint64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, rnd);
    int32_t rc = mpfr_add( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Add_Si64(MpfrPtr res, MpfrPtr x, int64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, rnd);
    int32_t rc = mpfr_add( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Add_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd)
{
    return mpfr_add_d( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Add_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd)
{
    return mpfr_add_z( (mpfr_ptr) res,  (mpfr_ptr) x,  (mpz_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Add_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd)
{
    return mpfr_add_q( (mpfr_ptr) res,  (mpfr_ptr) x,  (mpq_ptr) y, (mpfr_rnd_t) rnd);
}







int32_t Lib_Mpfr_Sub(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_sub( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Ui_Sub(MpfrPtr f, uint32_t x,  MpfrPtr g, int32_t rnd)
{
    return mpfr_ui_sub( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sub_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd)
{
    return mpfr_sub_ui( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Si_Sub(MpfrPtr f,  int32_t x, MpfrPtr g,  int32_t rnd)
{
    return mpfr_si_sub( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sub_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd)
{
    return mpfr_sub_si( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Sub_Ui64(MpfrPtr res, MpfrPtr x, uint64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Ui64_Sub(MpfrPtr res, uint64_t x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res,  t, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Sub_Si64(MpfrPtr res, MpfrPtr x, int64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Si64_Sub(MpfrPtr res, int64_t x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res,  t, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_D_Sub(MpfrPtr f,  double x, MpfrPtr g,  int32_t rnd)
{
    return mpfr_d_sub( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sub_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd)
{
    return mpfr_sub_d( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Sub_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd)
{
    return mpfr_sub_z( (mpfr_ptr) res,  (mpfr_ptr) x, (mpz_ptr) y, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Mpz_Sub(MpfrPtr res, MpzPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Sub_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd)
{
    return mpfr_sub_q( (mpfr_ptr) res,  (mpfr_ptr) x, (mpq_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mpq_Sub(MpfrPtr res, MpqPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}





int32_t Lib_Mpfr_Mul(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_mul( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mul_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd)
{
    return mpfr_mul_ui( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mul_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd)
{
    return mpfr_mul_si( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}

int32_t Lib_Mpfr_Mul_Ui64(MpfrPtr f, MpfrPtr g, uint64_t x, int32_t rnd)
{
    mpfr_t z; mpfr_init(z); Lib_Mpfr_Set_Ui64(z, x, rnd);
    int32_t res = mpfr_mul( (mpfr_ptr) f,  (mpfr_ptr) g,  z, (mpfr_rnd_t) rnd);
    mpfr_clear(z);
    return res;
}


int32_t Lib_Mpfr_Mul_Si64(MpfrPtr f, MpfrPtr g, int64_t x, int32_t rnd)
{
    mpfr_t z; mpfr_init(z); Lib_Mpfr_Set_Si64(z, x, rnd);
    int32_t res = mpfr_mul( (mpfr_ptr) f,  (mpfr_ptr) g,  z, (mpfr_rnd_t) rnd);
    mpfr_clear(z);
    return res;
}


int32_t Lib_Mpfr_Mul_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd)
{
    return mpfr_mul_d( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mul_Mpz(MpfrPtr x, MpfrPtr y, MpzPtr z, int32_t rnd)
{
    return mpfr_mul_z( (mpfr_ptr) x,  (mpfr_ptr) y, (mpz_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mul_Mpq(MpfrPtr x, MpfrPtr y, MpqPtr q, int32_t rnd)
{
    return mpfr_mul_q( (mpfr_ptr) x,  (mpfr_ptr) y, (mpq_ptr) q, (mpfr_rnd_t) rnd);
}


//**************************************




int32_t Lib_Mpfr_Div(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_div( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Ui_Div(MpfrPtr f, uint32_t x,  MpfrPtr g, int32_t rnd)
{
    return mpfr_ui_div( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Div_Ui(MpfrPtr f, MpfrPtr g,  uint32_t x, int32_t rnd)
{
    return mpfr_div_ui( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Si_Div(MpfrPtr f,  int32_t x, MpfrPtr g,  int32_t rnd)
{
    return mpfr_si_div( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Div_Si(MpfrPtr f, MpfrPtr g,  int32_t x, int32_t rnd)
{
    return mpfr_div_si( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}




int32_t Lib_Mpfr_Div_Ui64(MpfrPtr res, MpfrPtr x, uint64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Ui64_Div(MpfrPtr res, uint64_t x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res,  t, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Div_Si64(MpfrPtr res, MpfrPtr x, int64_t y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res,  (mpfr_ptr) x,  t, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Si64_Div(MpfrPtr res, int64_t x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res,  t, (mpfr_ptr) x, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}








int32_t Lib_Mpfr_D_Div(MpfrPtr f,  double x, MpfrPtr g,  int32_t rnd)
{
    return mpfr_d_div( (mpfr_ptr) f, x, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Div_D(MpfrPtr f, MpfrPtr g,  double x, int32_t rnd)
{
    return mpfr_div_d( (mpfr_ptr) f,  (mpfr_ptr) g,  x, (mpfr_rnd_t) rnd);
}




int32_t Lib_Mpfr_Div_Mpz(MpfrPtr res, MpfrPtr x, MpzPtr y, int32_t rnd)
{
    return mpfr_div_z( (mpfr_ptr) res,  (mpfr_ptr) y, (mpz_ptr) y, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Mpz_Div(MpfrPtr res, MpzPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Div_Mpq(MpfrPtr res, MpfrPtr x, MpqPtr y, int32_t rnd)
{
    return mpfr_div_q( (mpfr_ptr) res,  (mpfr_ptr) y, (mpq_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mpq_Div(MpfrPtr res, MpqPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}








int32_t Lib_Mpfr_Pow(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_pow( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


 int32_t Lib_Mpfr_Pow_Ui ( MpfrPtr f, MpfrPtr g, uint32_t e, int32_t rnd)
{
    return mpfr_pow_ui( (mpfr_ptr) f,  (mpfr_ptr) g,  e, (mpfr_rnd_t) rnd);
}


 int32_t Lib_Mpfr_Pow_Si ( MpfrPtr f, MpfrPtr g, int32_t e, int32_t rnd)
{
    return mpfr_pow_si( (mpfr_ptr) f,  (mpfr_ptr) g,  e, (mpfr_rnd_t) rnd);
}



 int32_t Lib_Mpfr_Ui_Pow_Ui ( MpfrPtr f, uint32_t  g, uint32_t e, int32_t rnd)
{
    return mpfr_ui_pow_ui( (mpfr_ptr) f,  g,  e, (mpfr_rnd_t) rnd);
}


 int32_t Lib_Mpfr_Ui_Pow ( MpfrPtr f, uint32_t e, MpfrPtr g, int32_t rnd)
{
    return mpfr_ui_pow( (mpfr_ptr) f, e, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}






int32_t Lib_Mpfr_Mul_2si(MpfrPtr x, MpfrPtr y,  int32_t e, int32_t rnd)
{
    return mpfr_mul_2si(  (mpfr_ptr) x,  (mpfr_ptr) y,  e, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Mul_2ui(MpfrPtr x, MpfrPtr y,  int32_t e, int32_t rnd)
{
    return mpfr_mul_2ui(  (mpfr_ptr) x,  (mpfr_ptr) y,  e, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Div_2si(MpfrPtr x, MpfrPtr y,  int32_t e, int32_t rnd)
{
    return mpfr_div_2si(  (mpfr_ptr) x,  (mpfr_ptr) y,  e, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Div_2ui(MpfrPtr x, MpfrPtr y,  int32_t e, int32_t rnd)
{
    return mpfr_div_2ui(  (mpfr_ptr) x,  (mpfr_ptr) y,  e, (mpfr_rnd_t) rnd);
}



//********************* constants **************************

int32_t Lib_Mpfr_Const_Log2(MpfrPtr x, int32_t rnd)
{
    return mpfr_const_log2( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Const_Pi(MpfrPtr x, int32_t rnd)
{
    return mpfr_const_pi( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Const_Euler(MpfrPtr x, int32_t rnd)
{
    return mpfr_const_euler( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Const_Catalan(MpfrPtr x, int32_t rnd)
{
    return mpfr_const_catalan( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



//  Standard functions one argument

int32_t Lib_Mpfr_Sqr(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sqr( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}

int32_t Lib_Mpfr_Sqrt(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sqrt( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rec_Sqrt(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rec_sqrt( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Cbrt(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_cbrt( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Abs(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_abs( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Log(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_log( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Log2(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_log2( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Log10(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_log10( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Exp(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_exp( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Exp2(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_exp2( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Exp10(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_exp10( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Cos(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_cos( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sin(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sin( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Tan(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_tan( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sec(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sec( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Csc(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_csc( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Cot(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_cot( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Acos(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_acos( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Asin(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_asin( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Atan(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_atan( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


//******************************



int32_t Lib_Mpfr_Cosh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_cosh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sinh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sinh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Tanh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_tanh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sech(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_sech( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Csch(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_csch( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Coth(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_coth( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Acosh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_acosh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Asinh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_asinh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Atanh(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_atanh( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}




int32_t Lib_Mpfr_Log1p(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_log1p( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Expm1(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_expm1( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Eint(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_eint( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Li2(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_li2( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Gamma(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_gamma( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Lngamma(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_lngamma( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Digamma(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_digamma( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Zeta(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_zeta( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Erf(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_erf( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Erfc(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_erfc( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_J0(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_j0( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_J1(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_j1( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Y0(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_y0( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Y1(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_y1( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Ai(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_ai( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rint(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rint( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rint_Ceil(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rint_ceil( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rint_Floor(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rint_floor( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rint_Round(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rint_round( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Rint_Trunc(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_rint_trunc( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Frac(MpfrPtr x, MpfrPtr y,  int32_t rnd)
{
    return mpfr_frac( (mpfr_ptr) x,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


//****************************** 1 argument, no rounding ********************


int32_t Lib_Mpfr_Ceil(MpfrPtr x, MpfrPtr y)
{
    return mpfr_ceil( (mpfr_ptr) x,  (mpfr_ptr) y);
}


int32_t Lib_Mpfr_Floor(MpfrPtr x, MpfrPtr y)
{
    return mpfr_floor( (mpfr_ptr) x,  (mpfr_ptr) y);
}


int32_t Lib_Mpfr_Round(MpfrPtr x, MpfrPtr y)
{
    return mpfr_round( (mpfr_ptr) x,  (mpfr_ptr) y);
}


int32_t Lib_Mpfr_Trunc(MpfrPtr x, MpfrPtr y)
{
    return mpfr_trunc( (mpfr_ptr) x,  (mpfr_ptr) y);
}


//****************************** 1 argument, variable ********************


int32_t Lib_Mpfr_Sqrt_Ui(MpfrPtr x, uint32_t n,  int32_t rnd)
{
    return mpfr_sqrt_ui( (mpfr_ptr) x, n, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Fac_Ui(MpfrPtr x, uint32_t n,  int32_t rnd)
{
    return mpfr_fac_ui( (mpfr_ptr) x, n, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Zeta_Ui(MpfrPtr x, uint32_t n,  int32_t rnd)
{
    return mpfr_zeta_ui( (mpfr_ptr) x, n, (mpfr_rnd_t) rnd);
}


//****************************** 2 arguments, mpfr ********************



int32_t Lib_Mpfr_Dim(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_dim( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Sin_Cos(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_sin_cos( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Atan2(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_atan2( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}

int32_t Lib_Mpfr_Sinh_Cosh(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_sinh_cosh( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Agm(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_agm( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Hypot(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_hypot( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Modf(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_modf( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Fmod(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_fmod( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Remainder(MpfrPtr x, MpfrPtr y, MpfrPtr z, int32_t rnd)
{
    return mpfr_remainder( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_rnd_t) rnd);
}

//****************************** 2 arguments, variable ********************



 int32_t Lib_Mpfr_Root ( MpfrPtr f, MpfrPtr g, uint32_t k, int32_t rnd)
{
    return mpfr_root( (mpfr_ptr) f,  (mpfr_ptr) g,  k, (mpfr_rnd_t) rnd);
}



 int32_t Lib_Mpfr_Lgamma ( MpfrPtr f, int32_t *signp, MpfrPtr g, int32_t rnd)
{
    return mpfr_lgamma( (mpfr_ptr) f, signp, (mpfr_ptr) g, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Jn(MpfrPtr x, int32_t n, MpfrPtr y,  int32_t rnd)
{
    return mpfr_jn( (mpfr_ptr) x, n,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Yn(MpfrPtr x, int32_t n, MpfrPtr y,  int32_t rnd)
{
    return mpfr_yn( (mpfr_ptr) x, n,  (mpfr_ptr) y, (mpfr_rnd_t) rnd);
}




//****************************** 3 arguments, mpfr ********************



int32_t Lib_Mpfr_Fma(MpfrPtr x, MpfrPtr y, MpfrPtr z, MpfrPtr z2, int32_t rnd)
{
    return mpfr_fma( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_ptr) z2, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfr_Fms(MpfrPtr x, MpfrPtr y, MpfrPtr z, MpfrPtr z2, int32_t rnd)
{
    return mpfr_fms( (mpfr_ptr) x,  (mpfr_ptr) y,  (mpfr_ptr) z, (mpfr_ptr) z2, (mpfr_rnd_t) rnd);
}



//****************************** 3 arguments, variable ********************


//int32_t Lib_Mpfr_Remquo(MpfrPtr x, int32_t* q, MpfrPtr z, MpfrPtr z2, int32_t rnd)
//{
//    return mpfr_remquo( (mpfr_ptr) x, q, (mpfr_ptr) z, (mpfr_ptr) z2, (mpfr_rnd_t) rnd);
//}




//****************************** Properties ********************


int32_t Lib_Fits_Ulong_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_ulong_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Slong_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_slong_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Uint_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_uint_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Sint_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_sint_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Ushort_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_ushort_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Sshort_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_sshort_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Uintmax_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_uintmax_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Fits_Intmax_P(MpfrPtr x, int32_t rnd)
{
    return mpfr_fits_intmax_p( (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfr_Nan_P(MpfrPtr x)
{
    return mpfr_nan_p( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Inf_P(MpfrPtr x)
{
    return mpfr_inf_p( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Number_P(MpfrPtr x)
{
    return mpfr_number_p( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Zero_P(MpfrPtr x)
{
    return mpfr_zero_p( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Regular_P(MpfrPtr x)
{
    return mpfr_regular_p( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Unordered_P(MpfrPtr x)
{
    return mpfr_unordered_p( (mpfr_ptr) x, (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Sgn(MpfrPtr x)
{
    return mpfr_sgn( (mpfr_ptr) x);
}


int32_t Lib_Mpfr_Integer_P(MpfrPtr x)
{
    return mpfr_integer_p( (mpfr_ptr) x);
}







//***************************************************


//
//void Lib_Mpfr_Mat_Print_Pretty(MpfrMatPtr A, int32_t digits)
//{
//    mpfr_mat_printd( (mpfr_mat_struct*) A, digits);
//}
//
//
//void Lib_Mpfr_Mat_Init(MpfrMatPtr* A, int32_t i, int32_t j)
//{
//    (*A) =  malloc (sizeof(mpfr_mat_struct));
//    mpfr_mat_init( (mpfr_mat_struct*) (*A), i, j);
//}
//
//void Lib_Mpfr_Mat_Clear(MpfrMatPtr A)
//{
//    mpfr_mat_clear( (mpfr_mat_struct*) A);
//    free(A);
//}
//
//
//void Lib_Mpfr_Mat_Mul(MpfrMatPtr X, MpfrMatPtr Y, MpfrMatPtr Z, int32_t digits)
//{
//    mpfr_mat_mul( (mpfr_mat_struct*) X,  (mpfr_mat_struct*) Y,  (mpfr_mat_struct*) Z, digits);
//}
//
//
//
//void Lib_Mpfr_Mat_Set_Ui(MpfrMatPtr A, int32_t i, int32_t j, int32_t u)
//{
//    mpfr_set_ui ( mpfr_mat_entry ((mpfr_mat_struct*)A, i, j), u);
//}


