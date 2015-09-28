#include <mpfr.h>
#include <mpfi.h>

#define CXSC_MPFR_API

#if defined (BUILD_CXSC_MPFR_DLL)
  #undef CXSC_MPFR_API
  #define CXSC_MPFR_API __declspec( dllexport )
#elif defined (TEST_CXSC_MPFR_DLL)
  #undef CXSC_MPFR_API
  #define CXSC_MPFR_API __declspec( dllimport )
#endif


#ifdef __cplusplus
extern "C"
{
#endif


/////////////////////////////////////////////////////////
//// Mpfr
/////////////////////////////////////////////////////////


CXSC_MPFR_API void cxsc_mpfr_abs(mpfr_t z, const mpfr_t x);
CXSC_MPFR_API void cxsc_mpfr_sqr(mpfr_t z, const mpfr_t& x);

CXSC_MPFR_API void cxsc_mpfr_x2py2(mpfr_t z, const mpfr_t& x, const mpfr_t& y);
CXSC_MPFR_API void cxsc_mpfr_x2my2(mpfr_t z, const mpfr_t& x, const mpfr_t& y);

CXSC_MPFR_API void cxsc_mpfr_reci(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrt(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrt_n(mpfr_t z, const unsigned long n);
CXSC_MPFR_API void cxsc_mpfr_sqrt_r(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_cbrt(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_nth_root(mpfr_t z, const mpfr_t& x, const int n);

CXSC_MPFR_API void cxsc_mpfr_sqrtp1m1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrt1px2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrt1mx2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrtx2m1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sqrtx2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& n);

CXSC_MPFR_API void cxsc_mpfr_exp(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_exp2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_exp10(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_expm1(mpfr_t z, const mpfr_t& x);

CXSC_MPFR_API void cxsc_mpfr_expx2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_expx2m1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_expmx2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_expmx2m1(mpfr_t z, const mpfr_t& x);

CXSC_MPFR_API void cxsc_mpfr_ln(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_log2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_log10(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_lnp1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_agm(mpfr_t z, const mpfr_t& x, const mpfr_t& y);

CXSC_MPFR_API void cxsc_mpfr_ln_sin(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_ln_cos(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_ln_sqrtx2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& y);

CXSC_MPFR_API void cxsc_mpfr_power(mpfr_t z, const mpfr_t& x, const int k);
CXSC_MPFR_API void cxsc_mpfr_pow(mpfr_t z, const mpfr_t& x, const mpfr_t& y);
CXSC_MPFR_API void cxsc_mpfr_sin(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_cos(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_tan(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_cot(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_asin(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_acos(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_atan(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_atan2(mpfr_t z, const mpfr_t& x, const mpfr_t& y);
CXSC_MPFR_API void cxsc_mpfr_acot(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sinh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_cosh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_tanh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_coth(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_asinh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_acosh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_acoshp1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_atanh(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_acoth(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_csc(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sec(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_csch(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_sech(mpfr_t z, const mpfr_t& x);

CXSC_MPFR_API void cxsc_mpfr_ln_sqrtxp1_2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& y);

// Functions of Mathematical Physics

CXSC_MPFR_API void cxsc_mpfr_erf(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_erfc(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_gamma(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_gamma_D(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_gamma_reci(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_digamma(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_lngamma(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_lgamma(mpfr_t z, const mpfr_t& x, int& k);
CXSC_MPFR_API void cxsc_mpfr_factorial(mpfr_t z, const unsigned long x);
CXSC_MPFR_API void cxsc_mpfr_zeta(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Ei(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Li2(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Jn(mpfr_t z, const long n, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_J0(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_J1(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Yn(mpfr_t z, const long n, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Y0(mpfr_t z, const mpfr_t& x);
CXSC_MPFR_API void cxsc_mpfr_Y1(mpfr_t z, const mpfr_t& x);



////////////////////////////////////////////////////
// MPFI functions
////////////////////////////////////////////////////


CXSC_MPFR_API void cxsc_mpfi_abs(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqr(mpfi_t z, const mpfi_t& x);

CXSC_MPFR_API void cxsc_mpfi_x2py2(mpfi_t z, const mpfi_t& x, const mpfi_t& y);
CXSC_MPFR_API void cxsc_mpfi_x2my2(mpfi_t z, const mpfi_t& x, const mpfi_t& y);

CXSC_MPFR_API void cxsc_mpfi_reci(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrt(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrt_n(mpfi_t z, const unsigned long n);
CXSC_MPFR_API void cxsc_mpfi_sqrt_r(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_cbrt(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_nth_root(mpfi_t z, const mpfi_t& x, const unsigned long n);

CXSC_MPFR_API void cxsc_mpfi_sqrtp1m1(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrt1px2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrt1mx2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrtx2m1(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sqrtx2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& n);

CXSC_MPFR_API void cxsc_mpfi_exp(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_exp2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_exp10(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_expm1(mpfi_t z, const mpfi_t& x);

CXSC_MPFR_API void cxsc_mpfi_expx2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_expx2m1(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_expmx2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_expmx2m1(mpfi_t z, const mpfi_t& x);

CXSC_MPFR_API void cxsc_mpfi_ln(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_log2(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_log10(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_lnp1(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_agm(mpfi_t z, const mpfi_t& x, const mpfi_t& y);

CXSC_MPFR_API void cxsc_mpfi_ln_sin(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_ln_cos(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_ln_sqrtx2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& y);

CXSC_MPFR_API void cxsc_mpfi_power(mpfi_t z, const mpfi_t& x,  const long k);
CXSC_MPFR_API void cxsc_mpfi_pow(mpfi_t z, const mpfi_t& x, const mpfi_t& y);
CXSC_MPFR_API void cxsc_mpfi_sin(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_cos(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_tan(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_cot(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_asin(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_acos(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_atan(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_atan2(mpfi_t z, const mpfi_t& x, const mpfi_t& y);
CXSC_MPFR_API void cxsc_mpfi_acot(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sinh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_cosh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_tanh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_coth(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_asinh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_acosh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_acoshp1(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_atanh(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_acoth(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_csc(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sec(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_csch(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_sech(mpfi_t z, const mpfi_t& x);

CXSC_MPFR_API void cxsc_mpfi_ln_sqrtxp1_2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& y);

// Functions of Mathematical Physics

CXSC_MPFR_API void cxsc_mpfi_erf(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_erfc(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_gamma_D(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_digamma(mpfi_t z, const mpfi_t& x);
CXSC_MPFR_API void cxsc_mpfi_factorial(mpfi_t z, const unsigned long x);
CXSC_MPFR_API void cxsc_mpfi_zeta(mpfi_t z, const unsigned long x);
CXSC_MPFR_API void cxsc_mpfi_Ei(mpfi_t z, const mpfi_t& x);



//////////////////////////////////////////////////////////
/////   Mpfc
//////////////////////////////////////////////////////////

CXSC_MPFR_API void cxsc_mpfc_add(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im);
CXSC_MPFR_API void cxsc_mpfc_sub(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im);
CXSC_MPFR_API void cxsc_mpfc_mul(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im);
CXSC_MPFR_API void cxsc_mpfc_div(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im);

CXSC_MPFR_API void cxsc_mpfc_neg(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_conj(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_real(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_imag(mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_abs(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_arg(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_sqr(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_sqrt(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
// CXSC_MPFR_API void cxsc_mpfc_sqrt_all(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_nth_root(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const unsigned long n);
// CXSC_MPFR_API void cxsc_mpfc_nth_root_all(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const unsigned long n);
CXSC_MPFR_API void cxsc_mpfc_ln(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_log2(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_log10(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_exp(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_exp2(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_exp10(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_power(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const int& n);
CXSC_MPFR_API void cxsc_mpfc_pow_r(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& n_re);
CXSC_MPFR_API void cxsc_mpfc_pow_c(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& n_re, const mpfr_t& n_im);
CXSC_MPFR_API void cxsc_mpfc_sin(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_cos(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_tan(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_cot(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_asin(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_acos(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_atan(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_acot(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_sinh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_cosh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_tanh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_coth(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_asinh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_acosh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_atanh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
CXSC_MPFR_API void cxsc_mpfc_acoth(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);




//////////////////////////////////////////////////////////
/////   Mpfci
//////////////////////////////////////////////////////////

CXSC_MPFR_API void cxsc_mpfci_add(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im);
CXSC_MPFR_API void cxsc_mpfci_sub(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im);
CXSC_MPFR_API void cxsc_mpfci_mul(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im);
CXSC_MPFR_API void cxsc_mpfci_div(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im);

CXSC_MPFR_API void cxsc_mpfci_neg(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_conj(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_real(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_imag(mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_abs(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_arg(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_sqr(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_sqrt(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
// CXSC_MPFR_API void cxsc_mpfci_sqrt_all(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_nth_root(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const unsigned long n);
// CXSC_MPFR_API void cxsc_mpfci_nth_root_all(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const unsigned long n);
CXSC_MPFR_API void cxsc_mpfci_ln(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_log2(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_log10(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_exp(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_exp2(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_exp10(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_power(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const int& n);
CXSC_MPFR_API void cxsc_mpfci_pow_r(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& n_re);
CXSC_MPFR_API void cxsc_mpfci_pow_c(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& n_re, const mpfi_t& n_im);
CXSC_MPFR_API void cxsc_mpfci_sin(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_cos(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_tan(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_cot(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_asin(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_acos(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_atan(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_acot(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_sinh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_cosh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_tanh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_coth(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_asinh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_acosh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_atanh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
CXSC_MPFR_API void cxsc_mpfci_acoth(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);


#ifdef __cplusplus
}
#endif
















































































//
//CXSC_MPFR_API void cxsc_mpfr_sqrt(mpfr_t z, const mpfr_t& x);
//
//CXSC_MPFR_API void cxsc_mpfc_Sqrt(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im);
//
//CXSC_MPFR_API void cxsc_mpfi_Sqrt(mpfi_t z, const mpfi_t& x);
//
//CXSC_MPFR_API void cxsc_mpfci_Sqrt(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im);
//
