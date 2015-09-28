
#include "mpNumC_Short.h"

#include <gmp.h>
#include <mpfr.h>
#include <mpc.h>
#include <inttypes.h>
#include <stdlib.h>


#include <string.h>

//void Lib_Mpfc_Printd(MpfcPtr x, int32_t int32_t prec)
//{
//    mpc_printd( (mpc_ptr) x, prec);
//}




void Lib_Mpfc_Init(MpfcPtr* x)
{
    (*x) =  malloc (sizeof(__mpc_struct));
    mpc_init2( (mpc_ptr) (*x), mpfr_get_default_prec());
}

void Lib_Mpfc_Clear(MpfcPtr x)
{
    mpc_clear( (mpc_ptr) x);
    free(x);
}




void Lib_Mpfc_Set_Prec(MpfcPtr x, int32_t prec)
{
    mpc_set_prec( (mpc_ptr) x, (mpfr_prec_t) prec);
}



int32_t Lib_Mpfc_Get_Prec(MpfcPtr x)
{
    return (int32_t) mpc_get_prec( (mpc_ptr) x);
}


//**********************************************************



void Lib_Mpfc_Set_Nan(MpfcPtr x)
{
    mpc_set_nan( (mpc_ptr) x);
}



void Lib_Mpfc_Swap(MpfrPtr x, MpfcPtr y)
{
    mpc_swap( (mpc_ptr) x,  (mpc_ptr) y);
}


//**********************************************




int32_t Lib_Mpfc_Set(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_set( (mpc_ptr) res, (mpc_ptr) x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Ui(MpfcPtr res, uint32_t x, int32_t rnd)
{
    return mpc_set_ui( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Si(MpfcPtr res, int32_t x, int32_t rnd)
{
    return mpc_set_si( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Ui64(MpfcPtr res, uint64_t x, int32_t rnd)
{
    return mpc_set_uj( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Si64(MpfcPtr res, int64_t x, int32_t rnd)
{
    return mpc_set_sj( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_D(MpfcPtr res, double x, int32_t rnd)
{
    return mpc_set_d( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Ld(MpfcPtr res, long double x, int32_t rnd)
{
    return mpc_set_ld( (mpc_ptr) res, x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpz(MpfcPtr res, MpzPtr x, int32_t rnd)
{
    return mpc_set_z( (mpc_ptr) res, (mpz_ptr) x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpq(MpfcPtr res, MpqPtr x, int32_t rnd)
{
    return mpc_set_q( (mpc_ptr) res, (mpq_ptr) x, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpfr(MpfcPtr res, MpfrPtr x, int32_t rnd)
{
    return mpc_set_fr( (mpc_ptr) res,( mpfr_ptr) x, (mpc_rnd_t) rnd);
}






int32_t Lib_Mpfc_Set_Ui_Ui(MpfcPtr res, uint32_t x1, uint32_t x2, int32_t rnd)
{
    return mpc_set_ui_ui( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Si_Si(MpfcPtr res, int32_t x1, int32_t x2, int32_t rnd)
{
    return mpc_set_si_si( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Ui64_Ui64(MpfcPtr res, uint64_t x1, uint64_t x2, int32_t rnd)
{
    return mpc_set_uj_uj( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Si64_Si64(MpfcPtr res, int64_t x1, int64_t x2, int32_t rnd)
{
    return mpc_set_sj_sj( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_D_D(MpfcPtr res, double x1, double x2, int32_t rnd)
{
    return mpc_set_d_d( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Ld_Ld(MpfcPtr res, long double x1, long double x2, int32_t rnd)
{
    return mpc_set_ld_ld( (mpc_ptr) res, x1, x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpz_Mpz(MpfcPtr res, MpzPtr x1, MpzPtr x2, int32_t rnd)
{
    return mpc_set_z_z( (mpc_ptr) res, (mpz_ptr) x1, (mpz_ptr) x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpq_Mpq(MpfcPtr res, MpqPtr x1, MpqPtr x2, int32_t rnd)
{
    return mpc_set_q_q( (mpc_ptr) res, (mpq_ptr) x1, (mpq_ptr) x2, (mpc_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Mpfr_Mpfr(MpfcPtr res, MpfrPtr x1, MpfrPtr x2, int32_t rnd)
{
    return mpc_set_fr_fr( (mpc_ptr) res, (mpfr_ptr) x1, (mpfr_ptr) x2, (mpc_rnd_t) rnd);
}













int32_t Lib_Mpfc_Arg(MpfrPtr res, MpfcPtr x,  int32_t rnd)
{
    return mpc_arg( (mpfr_ptr) res, (mpc_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfc_Abs(MpfrPtr res, MpfcPtr x,  int32_t rnd)
{
    return mpc_abs( (mpfr_ptr) res, (mpc_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfc_Norm(MpfrPtr res, MpfcPtr x,  int32_t rnd)
{
    return mpc_norm( (mpfr_ptr) res, (mpc_ptr) x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfc_Get_Real(MpfrPtr res, MpfcPtr x,  int32_t rnd)
{
    return mpc_real( (mpfr_ptr) res, (mpc_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfc_Get_Imag(MpfrPtr res, MpfcPtr x,  int32_t rnd)
{
    return mpc_imag( (mpfr_ptr) res, (mpc_ptr) x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfc_Set_Real(MpfcPtr res, MpfrPtr x,  int32_t rnd)
{
    return mpfr_set( mpc_realref((mpc_ptr) res), (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}


int32_t Lib_Mpfc_Set_Imag(MpfcPtr res, MpfrPtr x,  int32_t rnd)
{
    return mpfr_set( mpc_imagref((mpc_ptr) res), (mpfr_ptr) x, (mpfr_rnd_t) rnd);
}



int32_t Lib_Mpfc_Set_Str(MpfcPtr x, const char * str , int32_t base, int32_t rnd)
{
    return mpc_set_str( (mpc_ptr) x, str, base, (mpc_rnd_t) rnd);
}




int32_t Lib_Mpfc_Real_SnPrintf_SizeInBase10(const char *template1, MpfcPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_realref((mpc_ptr) x));
}


int32_t Lib_Mpfc_Real_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfcPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_realref((mpc_ptr) x));
}



int32_t Lib_Mpfc_Imag_SnPrintf_SizeInBase10(const char *template1, MpfcPtr x)
{
    return mpfr_snprintf(NULL, 0, template1, mpc_imagref((mpc_ptr) x));
}


int32_t Lib_Mpfc_Imag_SnPrintf(char * dest , uint32_t digits, const char *template1, MpfcPtr x)
{
    return mpfr_snprintf(dest, digits, template1, mpc_imagref((mpc_ptr) x));
}



int32_t Lib_Mpfc_Cmp(MpfcPtr x, MpfcPtr y)
{
    return mpc_cmp((mpc_ptr) x, (mpc_ptr) y);
}


int32_t Lib_Mpfc_Neg(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_neg( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}






int32_t  Lib_Mpfc_Add(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd)
{
    return mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  (mpc_ptr) y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Add_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd)
{
    return mpc_add_ui( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}



// Check sign correction
int32_t  Lib_Mpfc_Add_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd)
{
    uint32_t t = (uint32_t) y;
    if (y > 0)
        return mpc_add_ui( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    else
        return mpc_sub_ui( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Add_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Add_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Add_D(MpfcPtr res, MpfcPtr x,  double y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_D(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Add_Mpz(MpfcPtr res, MpfcPtr x,  MpzPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Mpz(t, y, rnd);
    int32_t rc =  mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Add_Mpq(MpfcPtr res, MpfcPtr x,  MpqPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Mpq(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Add_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd)
{
    return mpc_add_fr( (mpc_ptr) res,  (mpc_ptr) x, (mpfr_ptr) y, (mpc_rnd_t) rnd);
}




int32_t  Lib_Mpfc_Sub(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd)
{
    return mpc_sub( (mpc_ptr) res,  (mpc_ptr) x,  (mpc_ptr) y, (mpc_rnd_t) rnd);
}




int32_t  Lib_Mpfc_Sub_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd)
{
    return mpc_sub_ui( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Ui_Sub(MpfcPtr res, uint32_t x, MpfcPtr y,  int32_t rnd)
{
    return mpc_ui_sub( (mpc_ptr) res, x, (mpc_ptr) y, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Sub_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si(t, y, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Si_Sub(MpfcPtr res, int32_t x, MpfcPtr y,  int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si(t, x, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res, t, (mpc_ptr) x,  (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}




int32_t  Lib_Mpfc_Sub_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, y, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Ui64_Sub(MpfcPtr res, uint64_t x, MpfcPtr y,  int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, x, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res, t, (mpc_ptr) x,  (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Sub_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, y, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Si64_Sub(MpfcPtr res, int64_t x, MpfcPtr y,  int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, x, rnd);
    int32_t rc = mpc_sub( (mpc_ptr) res, t, (mpc_ptr) x,  (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Sub_D(MpfcPtr res, MpfcPtr x, double y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, y, rnd);
    int32_t rc = mpc_sub_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfc_D_Sub(MpfcPtr res, double x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, x, rnd);
    int32_t rc = mpc_fr_sub( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Sub_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, y, rnd);
    int32_t rc = mpc_sub_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Mpz_Sub(MpfcPtr res, MpzPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, x, rnd);
    int32_t rc = mpc_fr_sub( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Sub_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, y, rnd);
    int32_t rc = mpc_sub_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Mpq_Sub(MpfcPtr res, MpqPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, x, rnd);
    int32_t rc = mpc_fr_sub( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}





int32_t  Lib_Mpfc_Sub_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd)
{
    return mpc_sub_fr( (mpc_ptr) res,  (mpc_ptr) x, (mpfr_ptr) y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Mpfr_Sub(MpfcPtr res, MpfrPtr  x, MpfcPtr y, int32_t rnd)
{
    return mpc_fr_sub( (mpc_ptr) res, (mpfr_ptr) x, (mpc_ptr) y,(mpc_rnd_t) rnd);
}








int32_t  Lib_Mpfc_Mul(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd)
{
    return mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  (mpc_ptr) y, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Mul_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd)
{
    return mpc_mul_ui( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Mul_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd)
{
    return mpc_mul_si( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Mul_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Mul_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Mul_D(MpfcPtr res, MpfcPtr x,  double y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_D(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Mul_Mpz(MpfcPtr res, MpfcPtr x,  MpzPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Mpz(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Mul_Mpq(MpfcPtr res, MpfcPtr x,  MpqPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Mpq(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Mul_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd)
{
    return mpc_mul_fr( (mpc_ptr) res,  (mpc_ptr) x, (mpfr_ptr) y, (mpc_rnd_t) rnd);
}






int32_t  Lib_Mpfc_Div(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd)
{
    return mpc_div( (mpc_ptr) res,  (mpc_ptr) x,  (mpc_ptr) y, (mpc_rnd_t) rnd);
}

int32_t  Lib_Mpfc_Div_Ui(MpfcPtr res, MpfcPtr x,  uint32_t y, int32_t rnd)
{
    return mpc_div_ui( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}

int32_t  Lib_Mpfc_Ui_Div(MpfcPtr res,  uint32_t x, MpfcPtr y,  int32_t rnd)
{
    return mpc_ui_div( (mpc_ptr) res, x, (mpc_ptr) y, (mpc_rnd_t) rnd);
}


// CHECK SIGN CORRECTION
int32_t  Lib_Mpfc_Div_Si(MpfcPtr res, MpfcPtr x,  int32_t y, int32_t rnd)
{
    int32_t rc = mpc_div_ui( (mpc_ptr) res,  (mpc_ptr) x, (uint32_t) y, (mpc_rnd_t) rnd);
    if (y < 0) mpc_neg( (mpc_ptr) res, (mpc_ptr) res, (mpc_rnd_t) rnd);
    return rc;
}

// CHECK SIGN CORRECTION
int32_t  Lib_Mpfc_Si_Div(MpfcPtr res,  int32_t x, MpfcPtr y,  int32_t rnd)
{
    int32_t rc = mpc_ui_div( (mpc_ptr) res, x, (mpc_ptr) y, (mpc_rnd_t) rnd);
    if (x < 0) mpc_neg( (mpc_ptr) res, (mpc_ptr) res, (mpc_rnd_t) rnd);
    return rc;
}









int32_t  Lib_Mpfc_Div_Ui64(MpfcPtr res, MpfcPtr x,  uint64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, y, rnd);
    int32_t rc = mpc_div( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Ui64_Div(MpfcPtr res, uint64_t x, MpfcPtr y,  int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Ui64(t, x, rnd);
    int32_t rc = mpc_div( (mpc_ptr) res, t, (mpc_ptr) x,  (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Div_Si64(MpfcPtr res, MpfcPtr x,  int64_t y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, y, rnd);
    int32_t rc = mpc_div( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}


int32_t  Lib_Mpfc_Si64_Div(MpfcPtr res, int64_t x, MpfcPtr y,  int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Si64(t, x, rnd);
    int32_t rc = mpc_div( (mpc_ptr) res, t, (mpc_ptr) x,  (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Div_D(MpfcPtr res, MpfcPtr x, double y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, y, rnd);
    int32_t rc = mpc_div_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfc_D_Div(MpfcPtr res, double x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, x, rnd);
    int32_t rc = mpc_fr_div( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Div_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, y, rnd);
    int32_t rc = mpc_div_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Mpz_Div(MpfcPtr res, MpzPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpz(t, x, rnd);
    int32_t rc = mpc_fr_div( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Div_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, y, rnd);
    int32_t rc = mpc_div_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Mpq_Div(MpfcPtr res, MpqPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Mpq(t, x, rnd);
    int32_t rc = mpc_fr_div( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


















int32_t  Lib_Mpfc_Div_Mpfr(MpfcPtr res, MpfcPtr x,  MpfrPtr  y, int32_t rnd)
{
    return mpc_div_fr( (mpc_ptr) res,  (mpc_ptr) x, (mpfr_ptr) y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Mpfr_Div(MpfcPtr res, MpfrPtr  x, MpfcPtr y, int32_t rnd)
{
    return mpc_fr_div( (mpc_ptr) res, (mpfr_ptr) x, (mpc_ptr) y,(mpc_rnd_t) rnd);
}





int32_t  Lib_Mpfc_Mul_2exp_Ui(MpfcPtr x, MpfcPtr y,  uint32_t e, int32_t rnd)
{
    return mpc_mul_2ui(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Mul_2exp_Si(MpfcPtr x, MpfcPtr y,  int32_t e, int32_t rnd)
{
    return mpc_mul_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Div_2exp_Ui(MpfcPtr x, MpfcPtr y,  uint32_t e, int32_t rnd)
{
    return mpc_div_2ui(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Div_2exp_Si(MpfcPtr x, MpfcPtr y,  int32_t e, int32_t rnd)
{
    return mpc_div_2si(  (mpc_ptr) x,  (mpc_ptr) y,  e, (mpc_rnd_t) rnd);
}






int32_t  Lib_Mpfc_Pow(MpfcPtr res, MpfcPtr x, MpfcPtr y, int32_t rnd)
{
    return mpc_pow( (mpc_ptr) res,  (mpc_ptr) x,  (mpc_ptr) y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Pow_D( MpfcPtr res, MpfcPtr x, double y, int32_t rnd)
{
    return mpc_pow_d( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Pow_Ld(MpfcPtr res, MpfcPtr x, double y, int32_t rnd)
{
    return mpc_pow_ld( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Pow_Si( MpfcPtr res, MpfcPtr x, int32_t y, int32_t rnd)
{
    return mpc_pow_si( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}


int32_t  Lib_Mpfc_Pow_Ui( MpfcPtr res, MpfcPtr x, uint32_t y, int32_t rnd)
{
    return mpc_pow_si( (mpc_ptr) res,  (mpc_ptr) x,  y, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Pow_Mpz(MpfcPtr res, MpfcPtr x, MpzPtr y, int32_t rnd)
{
    return mpc_pow_z( (mpc_ptr) res,  (mpc_ptr) x, (mpz_ptr) y, (mpc_rnd_t) rnd);
}


//int32_t  Lib_Mpfc_Pow_Mpq(MpfcPtr res, MpfcPtr x, MpqPtr y, int32_t rnd)
//{
//    mpfr_t z1; mpfr_init(z1);
//    fmpq_get_mpfr ( z1, (fmpq*) y, (mpfr_rnd_t) rnd);
//    int32_t rc = mpc_pow_fr( (mpc_ptr) res,  (mpc_ptr) x,  z1, (mpc_rnd_t) rnd);
//    mpfr_clear(z1);
//    return rc;
//}

//
//int32_t  Lib_Mpfc_Pow_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd)
//{
//    mpz_t z1; mpz_init(z1);
//    fmpz_get_mpz ( z1, (fmpz*) y);
//    int32_t rc = mpc_pow_z( (mpc_ptr) res,  (mpc_ptr) x,  z1, (mpc_rnd_t) rnd);
//    mpz_clear(z1);
//    return rc;
//}
//
//
//int32_t  Lib_Mpfc_Pow_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd)
//{
//    mpfr_t z1; mpfr_init(z1);
//    fmpq_get_mpfr ( z1, (fmpq*) y, (mpfr_rnd_t) rnd);
//    int32_t rc = mpc_pow_fr( (mpc_ptr) res,  (mpc_ptr) x,  z1, (mpc_rnd_t) rnd);
//    mpfr_clear(z1);
//    return rc;
//}




int32_t  Lib_Mpfc_Pow_Mpfr(MpfcPtr res, MpfcPtr x, MpfrPtr y, int32_t rnd)
{
    return mpc_pow_fr( (mpc_ptr) res,  (mpc_ptr) x,  (mpfr_ptr) y, (mpc_rnd_t) rnd);
}



// Standard Functions


int32_t  Lib_Mpfc_Proj(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_proj( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Conj(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_conj( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Sqr(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_sqr( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Sqrt(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_sqrt( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Exp(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_exp( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Log(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_log( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Log10(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_log10( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Sin(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_sin( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Cos(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_cos( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Tan(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_tan( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Sinh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_sinh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Cosh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_cosh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Tanh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_tanh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}

//*************




int32_t  Lib_Mpfc_Asin(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_asin( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Acos(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_acos( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Atan(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_atan( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Asinh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_asinh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Acosh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_acosh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}



int32_t  Lib_Mpfc_Atanh(MpfcPtr res, MpfcPtr x, int32_t rnd)
{
    return mpc_atanh( (mpc_ptr) res,  (mpc_ptr) x, (mpc_rnd_t) rnd);
}
