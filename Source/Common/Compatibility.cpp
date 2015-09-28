
#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <mpc.h>
#include <mpfi.h>
#include <flint.h>
#include <fmpz.h>
#include <fmpz_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"
#include <inttypes.h>


//***************Compatibility**************************************************************


int32_t Lib_Mpfr_Set_Fmpz(MpfrPtr x, FmpzPtr z, int32_t rnd)
{
    mpz_t z1; mpz_init(z1);
    fmpz_get_mpz ( z1, (fmpz*) z);
    int32_t rc = mpfr_set_z( (mpfr_ptr) x, z1, (mpfr_rnd_t) rnd);
    mpz_clear(z1);
    return rc;
}



int32_t Lib_Mpfr_Set_Fmpq(MpfrPtr x, FmpqPtr z, int32_t rnd)
{
    return fmpq_get_mpfr( (mpfr_ptr) x, (fmpq*) z, (mpfr_rnd_t) rnd);
}




int32_t Lib_Mpfr_Get_Fmpz( FmpzPtr x, MpfrPtr y, int32_t rnd)
{
    mpz_t x1;
    mpz_init(x1);
    int32_t rc = mpfr_get_z(x1, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    fmpz_set_mpz ( (fmpz*) x, x1);
    mpz_clear(x1);
    return rc;
}


int32_t Lib_Mpfr_Get_Fmpq( FmpqPtr q, MpfrPtr y, int32_t rnd)
{
    mpf_t y1;
    mpf_init(y1);
    int32_t res = mpfr_get_f(y1, (mpfr_ptr) y,  (mpfr_rnd_t) rnd);
    mpq_t q1;
    mpq_init(q1);
    mpq_set_f(q1, y1);
    fmpq_set_mpq ( (fmpq*) q, q1);
    mpq_clear(q1);
    mpf_clear(y1);
    return res;
}




int32_t Lib_Mpfr_Get_Fmpz_2exp( FmpzPtr x, MpfrPtr y)
{
    mpz_t x1;
    mpz_init(x1);
    mpfr_exp_t res = mpfr_get_z_exp(x1, (mpfr_ptr) y);
    fmpz_set_mpz ( (fmpz*) x, x1);
    mpz_clear(x1);
    return (int32_t) res;
}


int32_t Lib_Mpfr_Add_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) y);
    int32_t rc = mpfr_add_z( (mpfr_ptr) res,  (mpfr_ptr) x, t, (mpfr_rnd_t) rnd);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Add_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) y);
    int32_t rc = mpfr_add_q( (mpfr_ptr) res,  (mpfr_ptr) x, t, (mpfr_rnd_t) rnd);
    mpq_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Sub_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) y);
    int32_t rc = mpfr_sub_z( (mpfr_ptr) res,  (mpfr_ptr) y, t, (mpfr_rnd_t) rnd);
    mpz_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Fmpz_Sub(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Sub_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) y);
    int32_t rc = mpfr_sub_q( (mpfr_ptr) res,  (mpfr_ptr) x, t, (mpfr_rnd_t) rnd);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Fmpq_Sub(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpq(t, x, rnd);
    int32_t rc = mpfr_sub( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}




int32_t Lib_Mpfr_Mul_Fmpz(MpfrPtr x, MpfrPtr y, FmpzPtr z, int32_t rnd)
{
    mpz_t z1;
    mpz_init(z1);
    fmpz_get_mpz ( z1, (fmpz*) z);
    int32_t res = mpfr_mul_z( (mpfr_ptr) x,  (mpfr_ptr) y, z1, (mpfr_rnd_t) rnd);
    mpz_clear(z1);
    return res;
}


int32_t Lib_Mpfr_Mul_Fmpq(MpfrPtr x, MpfrPtr y, FmpqPtr z, int32_t rnd)
{
    mpq_t z1;
    mpq_init(z1);
    fmpq_get_mpq ( z1, (fmpq*) z);
    int32_t res = mpfr_mul_q( (mpfr_ptr) x,  (mpfr_ptr) y, z1, (mpfr_rnd_t) rnd);
    mpq_clear(z1);
    return res;
}



int32_t Lib_Mpfr_Div_Fmpz(MpfrPtr res, MpfrPtr x, FmpzPtr y, int32_t rnd)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) y);
    int32_t rc = mpfr_div_z( (mpfr_ptr) res,  (mpfr_ptr) y, t, (mpfr_rnd_t) rnd);
    mpz_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Fmpz_Div(MpfrPtr res, FmpzPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfr_Div_Fmpq(MpfrPtr res, MpfrPtr x, FmpqPtr y, int32_t rnd)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) y);
    int32_t rc = mpfr_div_q( (mpfr_ptr) res,  (mpfr_ptr) x, t, (mpfr_rnd_t) rnd);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfr_Fmpq_Div(MpfrPtr res, FmpqPtr x, MpfrPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpq(t, x, rnd);
    int32_t rc = mpfr_div( (mpfr_ptr) res, t, (mpfr_ptr) y, (mpfr_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



 int32_t Lib_Mpfr_Pow_Z ( MpfrPtr f, MpfrPtr g, FmpzPtr z, int32_t rnd)
{
    mpz_t z1;
    mpz_init(z1);
    fmpz_get_mpz ( z1, (fmpz*) z);
    int32_t res = mpfr_pow_z( (mpfr_ptr) f,  (mpfr_ptr) g, z1, (mpfr_rnd_t) rnd);
    mpz_clear(z1);
    return res;
}




int32_t Lib_Mpfc_Set_Fmpz(MpfcPtr res, FmpzPtr x, int32_t rnd)
{
    mpz_t z; mpz_init(z);
    fmpz_get_mpz ( z, (fmpz*) x);
    int32_t rc = mpc_set_z( (mpc_ptr) res, z, (mpc_rnd_t) rnd);
    mpz_clear(z);
    return rc;
}


int32_t Lib_Mpfc_Set_Fmpq(MpfcPtr res, FmpqPtr x, int32_t rnd)
{
    mpq_t q; mpq_init(q);
    fmpq_get_mpq ( q, (fmpq*) x);
    int32_t rc = mpc_set_q( (mpc_ptr) res, q, (mpc_rnd_t) rnd);
    mpq_clear(q);
    return rc;
}




int32_t Lib_Mpfc_Set_Fmpz_Fmpz(MpfcPtr res, FmpzPtr x1, FmpzPtr x2, int32_t rnd)
{
    mpz_t z1; mpz_init(z1);
    fmpz_get_mpz (z1, (fmpz*) x1);
    mpz_t z2; mpz_init(z2);
    fmpz_get_mpz (z2, (fmpz*) x2);
    int32_t rc = mpc_set_z_z( (mpc_ptr) res, z1, z2, (mpc_rnd_t) rnd);
    mpz_clear(z1);
    mpz_clear(z2);
    return rc;
}


int32_t Lib_Mpfc_Set_Fmpq_Fmpq(MpfcPtr res, FmpqPtr x1, FmpqPtr x2, int32_t rnd)
{
    mpq_t q1; mpq_init(q1);
    fmpq_get_mpq (q1, (fmpq*) x1);
    mpq_t q2; mpq_init(q2);
    fmpq_get_mpq (q2, (fmpq*) x2);
    int32_t rc = mpc_set_q_q( (mpc_ptr) res, q1, q2, (mpc_rnd_t) rnd);
    mpq_clear(q1);
    mpq_clear(q2);
    return rc;
}




int32_t  Lib_Mpfc_Add_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Fmpz(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Add_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Fmpq(t, y, rnd);
    int32_t rc = mpc_add( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}





int32_t Lib_Mpfc_Sub_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, y, rnd);
    int32_t rc = mpc_sub_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Fmpz_Sub(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, x, rnd);
    int32_t rc = mpc_fr_sub( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Sub_Fmpq(MpfcPtr res, MpfcPtr x, FmpqPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpq(t, y, rnd);
    int32_t rc = mpc_sub_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Fmpq_Sub(MpfcPtr res, FmpqPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpq(t, x, rnd);
    int32_t rc = mpc_fr_sub( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}




int32_t  Lib_Mpfc_Mul_Fmpz(MpfcPtr res, MpfcPtr x,  FmpzPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Fmpz(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}



int32_t  Lib_Mpfc_Mul_Fmpq(MpfcPtr res, MpfcPtr x,  FmpqPtr y, int32_t rnd)
{
    mpc_t t; mpc_init2(t, mpfr_get_default_prec()); Lib_Mpfc_Set_Fmpq(t, y, rnd);
    int32_t rc = mpc_mul( (mpc_ptr) res,  (mpc_ptr) x,  t, (mpc_rnd_t) rnd);
    mpc_clear(t);
    return rc;
}

//
//int32_t Lib_Mpfc_Div_D(MpfcPtr res, MpfcPtr x, double y, int32_t rnd)
//{
//    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, y, rnd);
//    int32_t rc = mpc_div_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
//    mpfr_clear(t);
//    return rc;
//}
//
//
//int32_t Lib_Mpfc_D_Div(MpfcPtr res, double x, MpfcPtr y, int32_t rnd)
//{
//    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_D(t, x, rnd);
//    int32_t rc = mpc_fr_div( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
//    mpfr_clear(t);
//    return rc;
//}



int32_t Lib_Mpfc_Div_Fmpz(MpfcPtr res, MpfcPtr x, FmpzPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, y, rnd);
    int32_t rc = mpc_div_fr( (mpc_ptr) res, (mpc_ptr) x, t, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfc_Fmpz_Div(MpfcPtr res, FmpzPtr x, MpfcPtr y, int32_t rnd)
{
    mpfr_t t; mpfr_init(t); Lib_Mpfr_Set_Fmpz(t, x, rnd);
    int32_t rc = mpc_fr_div( (mpc_ptr) res, t, (mpc_ptr) y, (mpc_rnd_t) rnd);
    mpfr_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Fmpz(MpfrPtr res, FmpzPtr x)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) x);
    int32_t rc = mpfi_set_z( (mpfi_ptr) res, t);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Fmpq(MpfrPtr res, FmpqPtr x)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) x);
    int32_t rc = mpfi_set_q( (mpfi_ptr) res, t);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Set_Fmpz_Fmpz(MpfrPtr res, FmpzPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) x);
    mpz_t u; mpz_init(t); fmpz_get_mpz ( u, (fmpz*) y);
    int32_t rc = mpfi_interv_z( (mpfi_ptr) res, t, u);
    mpz_clear(t); mpz_clear(u);
    return rc;
}


int32_t Lib_Mpfi_Set_Fmpq_Fmpq(MpfrPtr res, FmpqPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) x);
    mpq_t u; mpq_init(u); fmpq_get_mpq ( u, (fmpq*) y);
    int32_t rc = mpfi_interv_q( (mpfi_ptr) res, t, u);
    mpq_clear(t); mpq_clear(u);
    return rc;
}


int32_t Lib_Mpfi_Get_Fmpz(FmpzPtr res, MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    int32_t rc = Lib_Mpfr_Get_Fmpz((fmpz_t*) res, t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Get_Fmpq(FmpqPtr res, MpfiPtr x)
{
    mpfr_t t; mpfr_init(t);
    mpfi_get_fr( (mpfr_ptr) t, (mpfi_ptr) x);
    int32_t rc = Lib_Mpfr_Get_Fmpq((fmpq_t*) res, t, mpfr_get_default_rounding_mode());
    mpfr_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Add_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) y);
    int32_t rc = mpfi_add_z( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Add_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) y);
    int32_t rc = mpfi_add_q( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Sub_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) y);
    int32_t rc = mpfi_sub_z( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Fmpz_Sub(MpfiPtr res, FmpzPtr x, MpfiPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) x);
    int32_t rc = mpfi_z_sub( (mpfi_ptr) res, t, (mpfi_ptr) x);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Sub_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) y);
    int32_t rc = mpfi_sub_q( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Fmpq_Sub(MpfiPtr res, FmpqPtr x, MpfiPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) x);
    int32_t rc = mpfi_q_sub( (mpfi_ptr) res, t, (mpfi_ptr) x);
    mpq_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Mul_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) y);
    int32_t rc = mpfi_mul_z( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Mul_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) y);
    int32_t rc = mpfi_mul_q( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Div_Fmpz(MpfiPtr res, MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) y);
    int32_t rc = mpfi_div_z( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Fmpz_Div(MpfiPtr res, FmpzPtr x, MpfiPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz(t, (fmpz*) x);
    int32_t rc = mpfi_z_div( (mpfi_ptr) res, t, (mpfi_ptr) x);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Div_Fmpq(MpfiPtr res, MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) y);
    int32_t rc = mpfi_div_q( (mpfi_ptr) res,  (mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Fmpq_Div(MpfiPtr res, FmpqPtr x, MpfiPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq(t, (fmpq*) x);
    int32_t rc = mpfi_q_div( (mpfi_ptr) res, t, (mpfi_ptr) x);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Cmp_Fmpz(MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) y);
    int32_t rc = mpfi_cmp_z((mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Cmp_Fmpq(MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) y);
    int32_t rc = mpfi_cmp_q((mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}



int32_t Lib_Mpfi_Put_Fmpz(MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) y);
    int32_t rc = mpfi_put_z((mpfi_ptr) x, t);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Put_Fmpq(MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) y);
    int32_t rc = mpfi_put_q((mpfi_ptr) x, t);
    mpq_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Contains_Fmpz(MpfiPtr x, FmpzPtr y)
{
    mpz_t t; mpz_init(t); fmpz_get_mpz ( t, (fmpz*) y);
    int32_t rc = mpfi_is_inside_z(t, (mpfi_ptr) x);
    mpz_clear(t);
    return rc;
}


int32_t Lib_Mpfi_Contains_Fmpq(MpfiPtr x, FmpqPtr y)
{
    mpq_t t; mpq_init(t); fmpq_get_mpq ( t, (fmpq*) y);
    int32_t rc = mpfi_is_inside_q(t, (mpfi_ptr) x);
    mpq_clear(t);
    return rc;
}




