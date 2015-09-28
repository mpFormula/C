
#include "mpNumC_Short.h"


#include <gmp.h>
#include <mpfr.h>
#include <mpfi.h>
#include <stdlib.h>
//#include <cxscmpfr.h>

#include <string.h>




void Lib_Mpfi_Init(MpfiPtr* x)
{
    (*x) =  malloc (sizeof(__mpfi_struct));
    mpfi_init2( (mpfi_ptr) (*x), mpfr_get_default_prec());
}

void Lib_Mpfi_Clear(MpfiPtr x)
{
    mpfi_clear( (mpfi_ptr) x);
    free(x);
}





void Lib_Mpfi_Set_Prec(MpfiPtr x, int32_t prec)
{
    mpfi_set_prec( (mpfi_ptr) x, (mpfr_prec_t) prec);
}



int32_t Lib_Mpfi_Get_Prec(MpfiPtr x)
{
    return (int32_t) mpfi_get_prec( (mpfi_ptr) x);
}


//**********************************************************




int32_t  Lib_Mpfi_Set(MpfiPtr res, MpfiPtr x)
{
    return mpfi_set( (mpfi_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Set_Ui(MpfiPtr res, uint32_t x)
{
    return mpfi_set_ui( (mpfi_ptr) res, x);
}


int32_t Lib_Mpfi_Set_Si(MpfiPtr res, int32_t x)
{
    return mpfi_set_si( (mpfi_ptr) res, x);
}


int32_t Lib_Mpfi_Set_Ui64(MpfiPtr res, uint64_t x)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_set_fr( (mpfi_ptr) res, t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Si64(MpfiPtr res, int64_t x)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_set_fr( (mpfi_ptr) res, t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Flt(MpfiPtr res, float x)
{
    return mpfi_set_d( (mpfi_ptr) res, (double) x);
}



int32_t Lib_Mpfi_Set_D(MpfiPtr res, double x)
{
    return mpfi_set_d( (mpfi_ptr) res, x);
}



int32_t Lib_Mpfi_Set_Ld(MpfrPtr res, long double x)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ld(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_set_fr( (mpfi_ptr) res, t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Mpz(MpfrPtr res, MpzPtr x)
{
    return mpfi_set_z( (mpfi_ptr) res, (mpz_ptr) x);
}


int32_t Lib_Mpfi_Set_Mpq(MpfrPtr res, MpqPtr x)
{
    return mpfi_set_q( (mpfi_ptr) res, (mpq_ptr) x);
}


int32_t Lib_Mpfi_Set_Mpfr(MpfiPtr res, MpfrPtr x)
{
    return mpfi_set_fr( (mpfi_ptr) res, (mpfr_ptr) x);
}


int32_t Lib_Mpfi_Set_Str(MpfiPtr x, const char * str , int32_t base)
{
    return mpfi_set_str( (mpfi_ptr) x, str, base);
}





int32_t Lib_Mpfi_Set_Ui_Ui(MpfiPtr res, uint32_t x, uint32_t y)
{
    return mpfi_interv_ui( (mpfi_ptr) res, x, y);
}


int32_t Lib_Mpfi_Set_Si_Si(MpfiPtr res, int32_t x, int32_t y)
{
    return mpfi_interv_si( (mpfi_ptr) res, x, y);
}


int32_t Lib_Mpfi_Set_UI64_Ui64(MpfiPtr res, uint64_t x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, mpfr_get_default_rounding_mode());
    mpfr_t u; mpfr_init(u); Lib_Mpfr_Set_Ui64(u, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_interv_fr( (mpfi_ptr) res, t, u);
    mpfr_clear(t); mpfr_clear(u);
    return rc;
}


int32_t Lib_Mpfi_Set_Si64_Si64(MpfiPtr res, int64_t x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, mpfr_get_default_rounding_mode());
    mpfr_t u; mpfr_init(u); Lib_Mpfr_Set_Si64(u, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_interv_fr( (mpfi_ptr) res, t, u);
    mpfr_clear(t); mpfr_clear(u);
    return rc;
}


int32_t Lib_Mpfi_Set_Flt_Flt(MpfiPtr res, float x, float y)
{
    return mpfi_interv_d( (mpfi_ptr) res, (double) x, (double) y);
}



int32_t Lib_Mpfi_Set_D_D(MpfiPtr res, double x, double y)
{
    return mpfi_interv_d( (mpfi_ptr) res, x, y);
}



int32_t Lib_Mpfi_Set_Ld_Ld(MpfrPtr res, long double x, long double y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ld(t, x, mpfr_get_default_rounding_mode());
    mpfr_t u; mpfr_init(u); Lib_Mpfr_Set_Ld(u, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_interv_fr( (mpfi_ptr) res, t, u);
    mpfr_clear(t); mpfr_clear(u);
    return rc;
}


int32_t Lib_Mpfi_Set_Mpz_Mpz(MpfrPtr res, MpzPtr x, MpzPtr y)
{
    return mpfi_interv_z( (mpfi_ptr) res, (mpz_ptr) x, (mpz_ptr) y);
}


int32_t Lib_Mpfi_Set_Mpq_Mpq(MpfrPtr res, MpqPtr x, MpqPtr y)
{
    return mpfi_interv_q( (mpfi_ptr) res, (mpq_ptr) x, (mpq_ptr) y);
}


int32_t Lib_Mpfi_Set_Mpfr_Mpfr(MpfiPtr res, MpfrPtr x, MpfrPtr y)
{
    return mpfi_interv_fr( (mpfi_ptr) res, (mpfr_ptr) x, (mpfr_ptr) y);
}





uint32_t Lib_Mpfi_Get_Ui(MpfiPtr x)
{
    return (uint32_t) mpfi_get_d( (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Get_Si(MpfiPtr x)
{
    return (int32_t) mpfi_get_d( (mpfi_ptr) x);
}


uint64_t Lib_Mpfi_Get_Ui64(MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    uint64_t res = Lib_Mpfr_Get_Ui64(t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return res;
}


int64_t Lib_Mpfi_Get_Si64(MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    int64_t res = Lib_Mpfr_Get_Si64(t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return res;
}


float Lib_Mpfi_Get_Flt(MpfiPtr x)
{
    return (float) mpfi_get_d( (mpfi_ptr) x);
}


double Lib_Mpfi_Get_D(MpfiPtr x)
{
    return mpfi_get_d( (mpfi_ptr) x);
}


long double Lib_Mpfi_Get_Ld(MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    long double res = Lib_Mpfr_Get_Ld(t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return res;
}




int32_t Lib_Mpfi_Get_Mpz(MpzPtr res, MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    int32_t rc = Lib_Mpfr_Get_Mpz((mpz_ptr) res, t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Get_Mpq(MpqPtr res, MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    int32_t rc = Lib_Mpfr_Get_Mpq((mpq_ptr) res, t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Get_Mpfr(MpfrPtr res, MpfiPtr x)
{
    mpfi_get_fr( (mpfr_ptr) res, (mpfi_ptr) x);
    return 0;
}




int32_t Lib_Mpfi_Get_Left(MpfrPtr res, MpfiPtr x)
{
    return mpfi_get_left( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Get_Right(MpfrPtr res, MpfiPtr x)
{
    return mpfi_get_right( (mpfr_ptr) res, (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Set_Left(MpfiPtr res, MpfrPtr x, int32_t rnd)
{
    return mpfr_set( &(((mpfi_ptr) res)->left), (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfi_Set_Right(MpfiPtr res, MpfrPtr x, int32_t rnd)
{
    return mpfr_set( &(((mpfi_ptr) res)->right), (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}






int32_t Lib_Mpfi_Diam_Abs(MpfrPtr res, MpfiPtr x)
{
    return mpfi_diam_abs( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Diam_Rel(MpfrPtr res, MpfiPtr x)
{
    return mpfi_diam_rel( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Diam(MpfrPtr res, MpfiPtr x)
{
    return mpfi_diam( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Mag(MpfrPtr res, MpfiPtr x)
{
    return mpfi_mag( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Mig(MpfrPtr res, MpfiPtr x)
{
    return mpfi_mig( (mpfr_ptr) res, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Mid(MpfrPtr res, MpfiPtr x)
{
    return mpfi_mid( (mpfr_ptr) res, (mpfi_ptr) x);
}


void Lib_Mpfi_Alea(MpfrPtr res, MpfiPtr x)
{
    mpfi_alea( (mpfr_ptr) res, (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Left_SnPrintf_SizeInBase10(const char *template1, MpfiPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, &(((mpfi_ptr) x)->left));
}


int32_t Lib_Mpfi_Left_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfiPtr x)
{
    return mpfr_snprintf(dest, digits, template1, &(((mpfi_ptr) x)->left));
}



int32_t Lib_Mpfi_Right_SnPrintf_SizeInBase10(const char *template1, MpfiPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, &(((mpfi_ptr) x)->right));
}


int32_t Lib_Mpfi_Right_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfiPtr x)
{
    return mpfr_snprintf(dest, digits, template1, &(((mpfi_ptr) x)->right));
}







int32_t Lib_Mpfi_Add(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_add( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Add_D(MpfiPtr res, MpfiPtr x,  double y)
{
    return mpfi_add_d( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}



int32_t Lib_Mpfi_Add_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y)
{
    return mpfi_add_ui( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Add_Si(MpfiPtr res, MpfiPtr x,  int32_t y)
{
    return mpfi_add_si( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}



int32_t Lib_Mpfi_Add_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_add_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Add_Si64(MpfiPtr res, MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_add_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Add_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y)
{
    return mpfi_add_z( (mpfi_ptr) res,  (mpfi_ptr) x, (mpz_ptr) y);
}



int32_t Lib_Mpfi_Add_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y)
{
    return mpfi_add_q( (mpfi_ptr) res,  (mpfi_ptr) x, (mpq_ptr) y);
}



int32_t Lib_Mpfi_Add_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y)
{
    return mpfi_add_fr((mpfi_ptr) res,  (mpfi_ptr) x,  (mpfr_ptr) y);
}









int32_t Lib_Mpfi_Sub(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_sub( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Sub_D(MpfiPtr res, MpfiPtr x,  double y)
{
    return mpfi_sub_d( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_D_Sub(MpfiPtr res, double y, MpfiPtr x)
{
    return mpfi_d_sub( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sub_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y)
{
    return mpfi_sub_ui( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Ui_Sub(MpfiPtr res, uint32_t y, MpfiPtr x)
{
    return mpfi_ui_sub( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sub_Si(MpfiPtr res, MpfiPtr x,  int32_t y)
{
    return mpfi_sub_si( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Si_Sub(MpfiPtr res, int32_t y, MpfiPtr x)
{
    return mpfi_si_sub( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sub_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_sub_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Ui64_Sub(MpfiPtr res, uint64_t x, MpfiPtr y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_fr_sub( (mpfi_ptr) res, t, (mpfi_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Sub_Si64(MpfiPtr res, MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_sub_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Si64_Sub(MpfiPtr res, int64_t x, MpfiPtr y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_fr_sub( (mpfi_ptr) res, t, (mpfi_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Sub_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y)
{
    return mpfi_sub_z( (mpfi_ptr) res,  (mpfi_ptr) x, (mpz_ptr) y);
}


int32_t Lib_Mpfi_Mpz_Sub(MpfiPtr res, MpzPtr x, MpfiPtr y)
{
    return mpfi_z_sub( (mpfi_ptr) res, (mpz_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Sub_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y)
{
    return mpfi_sub_q( (mpfi_ptr) res,  (mpfi_ptr) x, (mpq_ptr) y);
}


int32_t Lib_Mpfi_Mpq_Sub(MpfiPtr res, MpqPtr x, MpfiPtr y)
{
    return mpfi_q_sub( (mpfi_ptr) res, (mpq_ptr) x, (mpfi_ptr) y);
}




int32_t Lib_Mpfi_Sub_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y)
{
    return mpfi_sub_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfr_ptr) y);
}


int32_t Lib_Mpfi_Mpfr_Sub(MpfiPtr res, MpfrPtr x, MpfiPtr y)
{
    return mpfi_fr_sub( (mpfi_ptr) res,  (mpfr_ptr) x,  (mpfi_ptr) y);
}











int32_t Lib_Mpfi_Mul(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_mul( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Mul_D(MpfiPtr res, MpfiPtr x,  double y)
{
    return mpfi_mul_d( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}



int32_t Lib_Mpfi_Mul_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y)
{
    return mpfi_mul_ui( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Mul_Si(MpfiPtr res, MpfiPtr x,  int32_t y)
{
    return mpfi_mul_si( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}



int32_t Lib_Mpfi_Mul_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_mul_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Mul_Si64(MpfiPtr res, MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_mul_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Mul_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y)
{
    return mpfi_mul_z( (mpfi_ptr) res,  (mpfi_ptr) x, (mpz_ptr) y);
}



int32_t Lib_Mpfi_Mul_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y)
{
    return mpfi_mul_q( (mpfi_ptr) res,  (mpfi_ptr) x, (mpq_ptr) y);
}



int32_t Lib_Mpfi_Mul_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y)
{
    return mpfi_mul_fr((mpfi_ptr) res,  (mpfi_ptr) x,  (mpfr_ptr) y);
}










int32_t Lib_Mpfi_Div(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_div( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Div_D(MpfiPtr res, MpfiPtr x,  double y)
{
    return mpfi_div_d( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_D_Div(MpfiPtr res, double y, MpfiPtr x)
{
    return mpfi_d_div( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Div_Ui(MpfiPtr res, MpfiPtr x,  uint32_t y)
{
    return mpfi_div_ui( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Ui_Div(MpfiPtr res, uint32_t y, MpfiPtr x)
{
    return mpfi_ui_div( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Div_Si(MpfiPtr res, MpfiPtr x,  int32_t y)
{
    return mpfi_div_si( (mpfi_ptr) res,  (mpfi_ptr) x,  y);
}


int32_t Lib_Mpfi_Si_Div(MpfiPtr res, int32_t y, MpfiPtr x)
{
    return mpfi_si_div( (mpfi_ptr) res, y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Div_Ui64(MpfiPtr res, MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_div_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Ui64_Div(MpfiPtr res, uint64_t x, MpfiPtr y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_fr_div( (mpfi_ptr) res, t, (mpfi_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Div_Si64(MpfiPtr res, MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_div_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  t);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Si64_Div(MpfiPtr res, int64_t x, MpfiPtr y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, x, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_fr_div( (mpfi_ptr) res, t, (mpfi_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Div_Mpz(MpfiPtr res, MpfiPtr x, MpzPtr y)
{
    return mpfi_div_z( (mpfi_ptr) res,  (mpfi_ptr) x, (mpz_ptr) y);
}


int32_t Lib_Mpfi_Mpz_Div(MpfiPtr res, MpzPtr x, MpfiPtr y)
{
    return mpfi_z_div( (mpfi_ptr) res, (mpz_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Div_Mpq(MpfiPtr res, MpfiPtr x, MpqPtr y)
{
    return mpfi_div_q( (mpfi_ptr) res,  (mpfi_ptr) x, (mpq_ptr) y);
}


int32_t Lib_Mpfi_Mpq_Div(MpfiPtr res, MpqPtr x, MpfiPtr y)
{
    return mpfi_q_div( (mpfi_ptr) res, (mpq_ptr) x, (mpfi_ptr) y);
}




int32_t Lib_Mpfi_Div_Mpfr(MpfiPtr res, MpfiPtr x, MpfrPtr y)
{
    return mpfi_div_fr( (mpfi_ptr) res,  (mpfi_ptr) x,  (mpfr_ptr) y);
}


int32_t Lib_Mpfi_Mpfr_Div(MpfiPtr res, MpfrPtr x, MpfiPtr y)
{
    return mpfi_fr_div( (mpfi_ptr) res,  (mpfr_ptr) x,  (mpfi_ptr) y);
}


//*********************************************************




int32_t Lib_Mpfi_Neg(MpfiPtr res, MpfiPtr x)
{
    return mpfi_neg( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Sqr(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sqr( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Inv(MpfiPtr res, MpfiPtr x)
{
    return mpfi_inv( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sqrt(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sqrt( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Cbrt(MpfiPtr res, MpfiPtr x)
{
    return mpfi_cbrt( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Abs(MpfiPtr res, MpfiPtr x)
{
    return mpfi_abs( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Mul_2exp(MpfiPtr x, MpfiPtr y,  uint32_t e)
{
    return mpfi_mul_2exp(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}


int32_t Lib_Mpfi_Mul_2ui(MpfiPtr x, MpfiPtr y,  uint32_t e)
{
    return mpfi_mul_2ui(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}


int32_t Lib_Mpfi_Mul_2si(MpfiPtr x, MpfiPtr y,  int32_t e)
{
    return mpfi_mul_2si(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}



int32_t Lib_Mpfi_Div_2exp(MpfiPtr x, MpfiPtr y,  uint32_t e)
{
    return mpfi_div_2exp(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}


int32_t Lib_Mpfi_Div_2ui(MpfiPtr x, MpfiPtr y,  uint32_t e)
{
    return mpfi_div_2ui(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}


int32_t Lib_Mpfi_Div_2si(MpfiPtr x, MpfiPtr y,  int32_t e)
{
    return mpfi_div_2si(  (mpfi_ptr) x,  (mpfi_ptr) y,  e);
}



int32_t Lib_Mpfi_Log(MpfiPtr res, MpfiPtr x)
{
    return mpfi_log( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Exp(MpfiPtr res, MpfiPtr x)
{
    return mpfi_exp( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Exp2(MpfiPtr res, MpfiPtr x)
{
    return mpfi_exp2( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Cos(MpfiPtr res, MpfiPtr x)
{
    return mpfi_cos( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sin(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sin( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Tan(MpfiPtr res, MpfiPtr x)
{
    return mpfi_tan( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sec(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sec( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Csc(MpfiPtr res, MpfiPtr x)
{
    return mpfi_csc( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Cot(MpfiPtr res, MpfiPtr x)
{
    return mpfi_cot( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Acos(MpfiPtr res, MpfiPtr x)
{
    return mpfi_acos( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Asin(MpfiPtr res, MpfiPtr x)
{
    return mpfi_asin( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Atan(MpfiPtr res, MpfiPtr x)
{
    return mpfi_atan( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Cosh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_cosh( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Sinh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sinh( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Tanh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_tanh( (mpfi_ptr) res,  (mpfi_ptr) x);
}




int32_t Lib_Mpfi_Sech(MpfiPtr res, MpfiPtr x)
{
    return mpfi_sech( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Csch(MpfiPtr res, MpfiPtr x)
{
    return mpfi_csch( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Coth(MpfiPtr res, MpfiPtr x)
{
    return mpfi_coth( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Acosh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_acosh( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Asinh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_asinh( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Atanh(MpfiPtr res, MpfiPtr x)
{
    return mpfi_atanh( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Log1p(MpfiPtr res, MpfiPtr x)
{
    return mpfi_log1p( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Expm1(MpfiPtr res, MpfiPtr x)
{
    return mpfi_expm1( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Log2(MpfiPtr res, MpfiPtr x)
{
    return mpfi_log2( (mpfi_ptr) res,  (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Log10(MpfiPtr res, MpfiPtr x)
{
    return mpfi_log10( (mpfi_ptr) res,  (mpfi_ptr) x);
}



int32_t Lib_Mpfi_Atan2(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_atan2( (mpfi_ptr) res, (mpfi_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Hypot(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_hypot( (mpfi_ptr) res, (mpfi_ptr) x, (mpfi_ptr) y);
}



int32_t Lib_Mpfi_Const_Log2(MpfiPtr res)
{
    return mpfi_const_log2( (mpfi_ptr) res);
}



int32_t Lib_Mpfi_Const_Pi(MpfiPtr res)
{
    return mpfi_const_pi( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Const_Euler(MpfiPtr res)
{
    return mpfi_const_euler( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Const_Catalan(MpfiPtr res)
{
    return mpfi_const_catalan( (mpfi_ptr) res);
}





int32_t Lib_Mpfi_Cmp(MpfiPtr x, MpfiPtr y)
{
    return mpfi_cmp((mpfi_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Cmp_D(MpfiPtr x, double y)
{
    return mpfi_cmp_d((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Cmp_Ui(MpfiPtr x, uint32_t y)
{
    return mpfi_cmp_ui((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Cmp_Si(MpfiPtr x, int32_t y)
{
    return mpfi_cmp_si((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Cmp_Ui64(MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_cmp_fr((mpfi_ptr) x, (mpfr_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Cmp_Si64(MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_cmp_fr((mpfi_ptr) x, (mpfr_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Cmp_Mpz(MpfiPtr x, MpzPtr y)
{
    return mpfi_cmp_z((mpfi_ptr) x, (mpz_ptr) y);
}


int32_t Lib_Mpfi_Cmp_Mpq(MpfiPtr x, MpqPtr y)
{
    return mpfi_cmp_q((mpfi_ptr) x, (mpq_ptr) y);
}




int32_t Lib_Mpfi_Cmp_Mpfr(MpfiPtr x, MpfiPtr y)
{
    return mpfi_cmp_fr((mpfi_ptr) x, (mpfr_ptr) y);
}



int32_t Lib_Mpfi_Is_Pos(MpfiPtr res)
{
    return mpfi_is_pos( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Strictly_Pos(MpfiPtr res)
{
    return mpfi_is_strictly_pos( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Nonneg(MpfiPtr res)
{
    return mpfi_is_nonneg( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Neg(MpfiPtr res)
{
    return mpfi_is_neg( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Strictly_Neg(MpfiPtr res)
{
    return mpfi_is_strictly_neg( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Nonpos(MpfiPtr res)
{
    return mpfi_is_nonpos( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Zero(MpfiPtr res)
{
    return mpfi_is_zero( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Has_Zero(MpfiPtr res)
{
    return mpfi_has_zero( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Nan_P(MpfiPtr res)
{
    return mpfi_nan_p( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Inf_P(MpfiPtr res)
{
    return mpfi_inf_p( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Bounded_P(MpfiPtr res)
{
    return mpfi_bounded_p( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Is_Empty(MpfiPtr res)
{
    return mpfi_is_empty( (mpfi_ptr) res);
}


int32_t Lib_Mpfi_Revert_If_Needed(MpfiPtr res)
{
    return mpfi_revert_if_needed( (mpfi_ptr) res);
}




int32_t Lib_Mpfi_Put(MpfiPtr x, MpfiPtr y)
{
    return mpfi_put((mpfi_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Put_D(MpfiPtr x, double y)
{
    return mpfi_put_d((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Put_Ui(MpfiPtr x, uint32_t y)
{
    return mpfi_put_ui((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Put_Si(MpfiPtr x, int32_t y)
{
    return mpfi_put_si((mpfi_ptr) x, y);
}


int32_t Lib_Mpfi_Put_Ui64(MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_put_fr((mpfi_ptr) x, (mpfr_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Put_Si64(MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_put_fr((mpfi_ptr) x, (mpfr_ptr) y);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Put_Mpz(MpfiPtr x, MpzPtr y)
{
    return mpfi_put_z((mpfi_ptr) x, (mpz_ptr) y);
}


int32_t Lib_Mpfi_Put_Mpq(MpfiPtr x, MpqPtr y)
{
    return mpfi_put_q((mpfi_ptr) x, (mpq_ptr) y);
}


int32_t Lib_Mpfi_Put_Mpfr(MpfiPtr x, MpfiPtr y)
{
    return mpfi_put_fr((mpfi_ptr) x, (mpfr_ptr) y);
}






int32_t Lib_Mpfi_Strictly_Contains(MpfiPtr x, MpfiPtr y)
{
    return mpfi_is_strictly_inside((mpfi_ptr) y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains(MpfiPtr x, MpfiPtr y)
{
    return mpfi_is_inside((mpfi_ptr) y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_D(MpfiPtr x, double y)
{
    return mpfi_is_inside_d(y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_Ui(MpfiPtr x, uint32_t y)
{
    return mpfi_is_inside_ui(y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_Si(MpfiPtr x, int32_t y)
{
    return mpfi_is_inside_si(y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_Ui64(MpfiPtr x, uint64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Ui64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_is_inside_fr((mpfr_ptr) y, (mpfi_ptr) x);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Contains_Si64(MpfiPtr x, int64_t y)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Si64(t, y, mpfr_get_default_rounding_mode());
    int32_t rc = mpfi_is_inside_fr((mpfr_ptr) y, (mpfi_ptr) x);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Contains_Mpz(MpfiPtr x, MpzPtr y)
{
    return mpfi_is_inside_z((mpz_ptr) y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_Mpq(MpfiPtr x, MpqPtr y)
{
    return mpfi_is_inside_q((mpq_ptr) y, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Contains_Mpfr(MpfiPtr x, MpfrPtr y)
{
    return mpfi_is_inside_fr((mpfr_ptr) y, (mpfi_ptr) x);
}











int32_t Lib_Mpfi_Intersect(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_intersect((mpfi_ptr) res, (mpfi_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Union(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_union((mpfi_ptr) res, (mpfi_ptr) x, (mpfi_ptr) y);
}


int32_t Lib_Mpfi_Increase(MpfiPtr res, MpfrPtr x)
{
    return mpfi_increase((mpfi_ptr) res, (mpfr_ptr) x);
}


int32_t Lib_Mpfi_Bisect(MpfiPtr res1, MpfiPtr res2, MpfiPtr x)
{
    return mpfi_bisect((mpfi_ptr) res1, (mpfi_ptr) res2, (mpfi_ptr) x);
}


int32_t Lib_Mpfi_Blow(MpfiPtr res, MpfiPtr x, double y)
{
    return mpfi_blow((mpfi_ptr) res, (mpfi_ptr) x, y);
}


// very naive implementation
int32_t mpfi_pow(mpfi_t res, mpfi_t x, mpfi_t y)
{
    mpfi_t x1; mpfi_init(x1);
    mpfi_t x2; mpfi_init(x2);
    mpfi_log(x1, x);
    mpfi_mul(x2, x1, y);
    int32_t rc = mpfi_exp(res, x2);
    mpfi_clear(x2);
    mpfi_clear(x1);
    return rc;
}


int32_t Lib_Mpfi_Pow(MpfiPtr res, MpfiPtr x, MpfiPtr y)
{
    return mpfi_pow((mpfi_ptr) res, (mpfi_ptr) x, (mpfi_ptr) y);
}


 int32_t Lib_Mpfi_Pow_Si( MpfiPtr res, MpfiPtr x, int32_t y)
 {
    mpfi_t t; mpfi_init(t); mpfi_set_si( (mpfi_ptr) t, y);
    int32_t rc = mpfi_exp( (mpfi_ptr) res, t);
    mpfi_clear(t);
    return rc;
 }



//
//
// void Lib_Mpfi_Pow_Si ( MpfiPtr f, MpfiPtr g, int32_t e)
//{
////    mpfi_t f1; mpfi_init(f1);
//    mpfi_t g1; mpfi_init(g1); mpfi_set(g1, (mpfi_ptr) g);
//
////    cxsc_mpfi_power(f1,   g1,  e);
////    mpfi_set((mpfi_ptr) f, f1);
//
//    cxsc_mpfi_power((mpfi_ptr) f, g1, e);
//
//
////    mpfi_clear(f1);
//    mpfi_clear(g1);
//}
//
//
//void Lib_Mpfi_Pow(MpfiPtr x, MpfiPtr y, MpfiPtr z)
//{
////    mpfi_t x1; mpfi_init(x1);
//    mpfi_t y1; mpfi_init(y1); mpfi_set(y1, (mpfi_ptr) y);
//    mpfi_t z1; mpfi_init(z1); mpfi_set(z1, (mpfi_ptr) z);
//
////    cxsc_mpfi_pow(x1,   y1,  z1);
////    mpfi_set((mpfi_ptr) x, x1);
//
//    cxsc_mpfi_pow((mpfi_ptr) x, y1,  z1);
//
//
////    mpfi_clear(x1);
//    mpfi_clear(y1);
//    mpfi_clear(z1);
//}

