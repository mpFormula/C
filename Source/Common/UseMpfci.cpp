#include "mpNumC_Short.h"

#include <gmp.h>
#include <mpfr.h>
#include <mpfi.h>
#include <stdlib.h>

#include <string.h>




void Lib_Mpfci_Init(MpfiPtr* x_re, MpfiPtr* x_im)
{
    (*x_re) =  malloc (sizeof(__mpfi_struct));
    mpfi_init2( (mpfi_ptr) (*x_re), mpfr_get_default_prec());

    (*x_im) =  malloc (sizeof(__mpfi_struct));
    mpfi_init2( (mpfi_ptr) (*x_im), mpfr_get_default_prec());
}

void Lib_Mpfci_Clear(MpfiPtr x_re, MpfiPtr x_im)
{
    mpfi_clear( (mpfi_ptr) x_re);
    free(x_re);

    mpfi_clear( (mpfi_ptr) x_im);
    free(x_im);

}




void Lib_Mpfci_Set_Prec(MpfiPtr x_re, MpfiPtr x_im, int32_t prec)
{
    mpfi_set_prec( (mpfi_ptr) x_re, (mpfr_prec_t) prec);
    mpfi_set_prec( (mpfi_ptr) x_im, (mpfr_prec_t) prec);
}



int32_t Lib_Mpfci_Get_Prec(MpfiPtr x_re, MpfiPtr x_im)
{
    int32_t prec_re = (int32_t) mpfi_get_prec( (mpfi_ptr) x_re);
    int32_t prec_im = (int32_t) mpfi_get_prec( (mpfi_ptr) x_im);
    if ((prec_re != 0) && (prec_im != 0)  && (prec_im == prec_re))
        return prec_re;
    else
        return 0;
}


//**********************************************************



void Lib_Mpfci_Set(MpfiPtr res_re, MpfiPtr res_im,  MpfiPtr x_re, MpfiPtr x_im)
{
    mpfi_set((mpfi_ptr) res_re, (mpfi_ptr) x_re);
    mpfi_set((mpfi_ptr) res_im, (mpfi_ptr) x_im);
}


void Lib_Mpfci_Set_Si(MpfiPtr res_re, MpfiPtr res_im, int32_t x_re)
{
    mpfi_set_si( (mpfi_ptr) res_re, x_re);
    mpfi_set_si( (mpfi_ptr) res_im, 0);
}



void Lib_Mpfci_Set_Ui(MpfiPtr res_re, MpfiPtr res_im, uint32_t x_re)
{
    mpfi_set_ui( (mpfi_ptr) res_re, x_re);
    mpfi_set_ui( (mpfi_ptr) res_im, 0);
}



void Lib_Mpfci_Set_D(MpfiPtr res_re, MpfiPtr res_im, double x_re)
{
    mpfi_set_d( (mpfi_ptr) res_re, x_re);
    mpfi_set_d( (mpfi_ptr) res_im, 0);
}


int32_t Lib_Mpfci_Set_Str(MpfiPtr res_re, MpfiPtr res_im,  const char * x_re , int32_t base)
{
    int32_t rc_re = mpfi_set_str( (mpfi_ptr) res_re, x_re, base);
    int32_t rc_im = mpfi_set_str( (mpfi_ptr) res_im, "0", base);
    return rc_re + rc_im;
}



void Lib_Mpfci_Set_Si_Si(MpfiPtr res_re, MpfiPtr res_im, int32_t x_re, int32_t x_im)
{
    mpfi_set_si( (mpfi_ptr) res_re, x_re);
    mpfi_set_si( (mpfi_ptr) res_im, x_im);
}


void Lib_Mpfci_Set_Ui_Ui(MpfiPtr res_re, MpfiPtr res_im, uint32_t x_re, uint32_t x_im)
{
    mpfi_set_ui( (mpfi_ptr) res_re, x_re);
    mpfi_set_ui( (mpfi_ptr) res_im, x_im);
}



void Lib_Mpfci_Set_D_D(MpfiPtr res_re, MpfiPtr res_im, double x_re, double x_im)
{
    mpfi_set_d( (mpfi_ptr) res_re, x_re);
    mpfi_set_d( (mpfi_ptr) res_im, x_im);
}




int32_t Lib_Mpfci_Set_Str_Str(MpfiPtr res_re, MpfiPtr res_im, const char * x_re, const char * x_im, int32_t base)
{
    int32_t rc_re = mpfi_set_str( (mpfi_ptr) res_re, x_re, base);
    int32_t rc_im = mpfi_set_str( (mpfi_ptr) res_im, x_im, base);
    return rc_re + rc_im;
}


int32_t Lib_Mpfci_Cmp(MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    int32_t rc_re = mpfi_cmp((mpfi_ptr) x_re, (mpfi_ptr) y_re);
    int32_t rc_im = mpfi_cmp((mpfi_ptr) x_im, (mpfi_ptr) y_im);
    return (rc_re == 0) && (rc_im == 0);
}


void Lib_Mpfci_Neg(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mpfi_neg( (mpfi_ptr) res_re,  (mpfi_ptr) x_re);
    mpfi_neg( (mpfi_ptr) res_im,  (mpfi_ptr) x_im);
}


void Lib_Mpfci_Add(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    mpfi_add( (mpfi_ptr) res_re,  (mpfi_ptr) x_re,  (mpfi_ptr) y_re);
    mpfi_add( (mpfi_ptr) res_im,  (mpfi_ptr) x_im,  (mpfi_ptr) y_im);
}



void Lib_Mpfci_Sub(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    mpfi_sub( (mpfi_ptr) res_re,  (mpfi_ptr) x_re,  (mpfi_ptr) y_re);
    mpfi_sub( (mpfi_ptr) res_im,  (mpfi_ptr) x_im,  (mpfi_ptr) y_im);
}




void Lib_Mpfci_Mul(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t r1; mpfi_init2(r1, prec);
    mpfi_t r2; mpfi_init2(r2, prec);

    mpfi_mul( r1,  (mpfi_ptr) x_re,  (mpfi_ptr) y_re);
    mpfi_mul( r2,  (mpfi_ptr) x_im,  (mpfi_ptr) y_im);
    mpfi_sub( (mpfi_ptr) res_re, r1, r2);
    mpfi_clear(r1); mpfi_clear(r2);

    mpfi_t i1; mpfi_init2(i1, prec);
    mpfi_t i2; mpfi_init2(i2, prec);
    mpfi_mul( i1,  (mpfi_ptr) x_re,  (mpfi_ptr) y_im);
    mpfi_mul( i2,  (mpfi_ptr) x_im,  (mpfi_ptr) y_re);
    mpfi_add( (mpfi_ptr) res_im, i1, i2);
    mpfi_clear(i1); mpfi_clear(i2);
}




void Lib_Mpfci_Div(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    mp_prec_t prec = mpfr_get_default_prec();
    mpfi_t m1; mpfi_init2(m1, prec);
    mpfi_t m2; mpfi_init2(m2, prec);
    mpfi_t m; mpfi_init2(m, prec);
    mpfi_t r1; mpfi_init2(r1, prec);
    mpfi_t r2; mpfi_init2(r2, prec);
    mpfi_t i1; mpfi_init2(i1, prec);
    mpfi_t i2; mpfi_init2(i2,prec);
    mpfi_t re; mpfi_init2(re, prec);
    mpfi_t im; mpfi_init2(im,prec);

    mpfi_sqr( m1, (mpfi_ptr) y_re);
    mpfi_sqr( m2, (mpfi_ptr) y_im);
    mpfi_add( m, m1, m2);

    mpfi_mul( r1,  (mpfi_ptr) x_re,  (mpfi_ptr) y_re);
    mpfi_mul( r2,  (mpfi_ptr) x_im,  (mpfi_ptr) y_im);
    mpfi_add( re, r1, r2);

    mpfi_mul( i1,  (mpfi_ptr) x_re,  (mpfi_ptr) y_im);
    mpfi_mul( i2,  (mpfi_ptr) x_im,  (mpfi_ptr) y_re);
    mpfi_sub( im, i1, i2);

    mpfi_div( (mpfi_ptr) res_re, re, m);
    mpfi_div( (mpfi_ptr) res_im, im, m);

    mpfi_clear(m1);
    mpfi_clear(m2);
    mpfi_clear(m);
    mpfi_clear(r1);
    mpfi_clear(r2);
    mpfi_clear(i1);
    mpfi_clear(i2);
    mpfi_clear(re);
    mpfi_clear(im);
}




void Lib_Mpfci_Exp(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t r; mpfi_init2(r, prec);
    mpfi_t c; mpfi_init2(c, prec);
    mpfi_t s; mpfi_init2(s, prec);

    mpfi_exp(r, (mpfi_ptr) x_re);
    mpfi_cos(c, (mpfi_ptr) x_im);
    mpfi_sin(s, (mpfi_ptr) x_re);

    mpfi_mul( (mpfi_ptr) res_re, r, c);
    mpfi_mul( (mpfi_ptr) res_im, r, c);

    mpfi_clear(r);
    mpfi_clear(c);
    mpfi_clear(s);
}



void Lib_Mpfci_Cos(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t r; mpfi_init2(r, prec);
    mpfi_t c; mpfi_init2(c, prec);
    mpfi_t s; mpfi_init2(s, prec);
    mpfi_t ch; mpfi_init2(ch, prec);
    mpfi_t sh; mpfi_init2(sh, prec);
    mpfi_t t; mpfi_init2(t, prec);


    mpfi_exp(r, (mpfi_ptr) x_re);
    mpfi_cos(c, (mpfi_ptr) x_im);
    mpfi_sin(s, (mpfi_ptr) x_re);
    mpfi_cosh(ch, (mpfi_ptr) x_im);
    mpfi_sinh(sh, (mpfi_ptr) x_re);

    mpfi_mul( (mpfi_ptr) res_re, c, ch);
    mpfi_mul( t, s, sh);
    mpfi_neg( (mpfi_ptr) res_im, t);

    mpfi_clear(r);
    mpfi_clear(c);
    mpfi_clear(s);
    mpfi_clear(ch);
    mpfi_clear(sh);
    mpfi_clear(t);
}



void Lib_Mpfci_Sin(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t r; mpfi_init2(r, prec);
    mpfi_t c; mpfi_init2(c, prec);
    mpfi_t s; mpfi_init2(s, prec);
    mpfi_t ch; mpfi_init2(ch, prec);
    mpfi_t sh; mpfi_init2(sh, prec);


    mpfi_exp(r, (mpfi_ptr) x_re);
    mpfi_cos(c, (mpfi_ptr) x_im);
    mpfi_sin(s, (mpfi_ptr) x_re);
    mpfi_cosh(ch, (mpfi_ptr) x_im);
    mpfi_sinh(sh, (mpfi_ptr) x_re);

    mpfi_mul( (mpfi_ptr) res_re, s, ch);
    mpfi_mul( (mpfi_ptr) res_im, c, sh);

    mpfi_clear(r);
    mpfi_clear(c);
    mpfi_clear(s);
    mpfi_clear(ch);
    mpfi_clear(sh);
}


void Lib_Mpfci_Abs(MpfiPtr res, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t a; mpfi_init2(a, prec);
    mpfi_t b; mpfi_init2(b, prec);
    mpfi_t t; mpfi_init2(t, prec);

    mpfi_sqr(a, (mpfi_ptr) x_re);
    mpfi_sqr(b, (mpfi_ptr) x_im);
    mpfi_add(t, a, b);
    mpfi_sqrt((mpfi_ptr) res, t);

    mpfi_clear(a);
    mpfi_clear(b);
    mpfi_clear(t);
}



void Lib_Mpfci_Arg(MpfiPtr res, MpfiPtr x_re, MpfiPtr x_im)
{
    mpfi_atan2((mpfi_ptr) res, (mpfi_ptr) x_im, (mpfi_ptr) x_re);
}


void Lib_Mpfci_Log(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();
    mpfi_t a; mpfi_init2(a, prec);

    Lib_Mpfci_Abs(a, (mpfi_ptr) x_re, (mpfi_ptr) x_im);
    mpfi_log((mpfi_ptr) res_re, a);
    Lib_Mpfci_Arg((mpfi_ptr) res_re, (mpfi_ptr) x_re, (mpfi_ptr) x_im);

    mpfi_clear(a);
}



void Lib_Mpfci_Pow(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im, MpfiPtr y_re, MpfiPtr y_im)
{
    mp_prec_t prec = mpfr_get_default_prec();

    mpfi_t a; mpfi_init2(a, prec);
    mpfi_t t_re; mpfi_init2(t_re, prec);
    mpfi_t t_im; mpfi_init2(t_im, prec);
    mpfi_t u_re; mpfi_init2(u_re, prec);
    mpfi_t u_im; mpfi_init2(u_im, prec);

    Lib_Mpfci_Log((mpfi_ptr) t_re, (mpfi_ptr) t_im, (mpfi_ptr) x_re, (mpfi_ptr) x_im);
    Lib_Mpfci_Mul((mpfi_ptr) u_re, (mpfi_ptr) u_im, (mpfi_ptr) t_re, (mpfi_ptr) t_im, (mpfi_ptr) y_re, (mpfi_ptr) y_im);
    Lib_Mpfci_Exp((mpfi_ptr) res_re, (mpfi_ptr) res_im, (mpfi_ptr) u_re, (mpfi_ptr) u_im);

    mpfi_clear(a);
    mpfi_clear(t_re);
    mpfi_clear(t_im);
    mpfi_clear(u_re);
    mpfi_clear(u_im);
}



void Lib_Mpfci_Sqr(MpfiPtr res_re, MpfiPtr res_im, MpfiPtr x_re, MpfiPtr x_im)
{
    mp_prec_t prec = mpfr_get_default_prec();
    mpfi_t m1; mpfi_init2(m1, prec);
    mpfi_t m2; mpfi_init2(m2, prec);
    mpfi_t im; mpfi_init2(im,prec);

    mpfi_sqr( m1, (mpfi_ptr) x_re);
    mpfi_sqr( m2, (mpfi_ptr) x_im);
    mpfi_sub( (mpfi_ptr) res_re, m1, m2);

    mpfi_mul( im,  (mpfi_ptr) x_re,  (mpfi_ptr) x_im);
    mpfi_mul_si( (mpfi_ptr) res_im, im, 2);

    mpfi_clear(m1);
    mpfi_clear(m2);
    mpfi_clear(im);
}

