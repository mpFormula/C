
//#include "StdAfx.h"
#include "cxscmpfr.h"
#include "mpfrclass.hpp"
#include "mpfcclass.hpp"
#include "mpficlass.hpp"
#include "mpfciclass.hpp"

using namespace MPFR;
using namespace MPFI;


/////////////////////////////////////////////////////////
//// Mpfr
/////////////////////////////////////////////////////////


 void cxsc_mpfr_abs(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = abs(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqr(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqr(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_x2py2(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = x2py2(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_x2my2(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = x2my2(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_reci(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = reci(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_sqrt(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrt(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_sqrt_n(mpfr_t z, const unsigned long n)
{
	MpfrClass v = sqrt_n(n);
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_sqrt_r(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrt_r(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_cbrt(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = cbrt(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfr_nth_root(mpfr_t z, const mpfr_t& x, const int n)
{
	MpfrClass v = sqrt(MpfrClass(x), n);
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqrtp1m1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrtp1m1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqrt1px2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrt1px2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqrt1mx2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrt1mx2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqrtx2m1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sqrtx2m1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sqrtx2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& n)
{
	MpfrClass v = sqrtx2y2(MpfrClass(x), MpfrClass(n));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_exp(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = exp(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_exp2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = exp2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_exp10(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = exp10(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_expm1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = expm1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_expx2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = expx2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_expx2m1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = expx2m1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_expmx2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = expmx2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_expmx2m1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = expmx2m1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_ln(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = ln(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_log2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = log2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_log10(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = log10(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_lnp1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = lnp1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_agm(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = agm(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}

void cxsc_mpfr_ln_sin(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = ln_sin(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_ln_cos(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = ln_cos(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_ln_sqrtx2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = ln_sqrtx2y2(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_power(mpfr_t z, const mpfr_t& x, const int k)
{
	MpfrClass v = power(MpfrClass(x), k);
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_pow(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = pow(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sin(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sin(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_cos(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = cos(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_tan(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = tan(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_cot(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = cot(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_asin(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = asin(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_acos(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = acos(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_atan(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = atan(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_atan2(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = atan2(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_acot(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = acot(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_sinh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sinh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_cosh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = cosh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_tanh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = tanh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_coth(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = coth(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_asinh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = asinh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_acosh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = acosh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_acoshp1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = acoshp1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_atanh(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = atanh(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_acoth(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = acoth(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_csc(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = csc(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sec(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sec(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_csch(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = lnp1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_sech(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = sech(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_ln_sqrtxp1_2y2(mpfr_t z, const mpfr_t& x, const mpfr_t& y)
{
	MpfrClass v = ln_sqrtxp1_2y2(MpfrClass(x), MpfrClass(y));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}





// Functions of Mathematical Physics



void cxsc_mpfr_erf(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = erf(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_erfc(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = erfc(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_gamma(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = gamma(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_gamma_D(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = gamma(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_gamma_reci(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = gamma_reci(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_digamma(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = digamma(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_lngamma(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = lngamma(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_lgamma(mpfr_t z, const mpfr_t& x, int& k)
{
	MpfrClass v = lgamma(MpfrClass(x), k);
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_factorial(mpfr_t z, const unsigned long x)
{
	MpfrClass v = factorial(x);
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_zeta(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = zeta(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_Ei(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = Ei(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_Li2(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = Li2(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_Jn(mpfr_t z, const long n, const mpfr_t& x)
{
	MpfrClass v = Jn(n, MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_J0(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = J0(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_J1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = J1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_Yn(mpfr_t z, const long n, const mpfr_t& x)
{
	MpfrClass v = Yn(n, MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



void cxsc_mpfr_Y0(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = J0(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}


void cxsc_mpfr_Y1(mpfr_t z, const mpfr_t& x)
{
	MpfrClass v = J1(MpfrClass(x));
	mpfr_set(z, v.GetValue(), GMP_RNDN);
}



////////////////////////////////////////////////////
// MPFI functions
////////////////////////////////////////////////////


 void cxsc_mpfi_abs(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = abs(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqr(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqr(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


 void cxsc_mpfi_x2py2(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = x2py2(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}


 void cxsc_mpfi_x2my2(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = x2my2(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_reci(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = reci(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


 void cxsc_mpfi_sqrt(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqrt(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


// void cxsc_mpfi_sqrt_n(mpfi_t z, const unsigned long n)
//{
//	MpfiClass v = sqrt_n( n);
//	mpfi_set(z, v.GetValue());
//}

//
// void cxsc_mpfi_sqrt_r(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = sqrt_r(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}
//

 void cxsc_mpfi_cbrt(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = cbrt(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


 void cxsc_mpfi_nth_root(mpfi_t z, const mpfi_t& x, const unsigned long n)
{
	MpfiClass v = sqrt(MpfiClass(x), n);
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqrtp1m1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqrtp1m1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqrt1px2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqrt1px2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqrt1mx2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqrt1mx2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqrtx2m1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sqrtx2m1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sqrtx2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& n)
{
	MpfiClass v = sqrtx2y2(MpfiClass(x), MpfiClass(n));
	mpfi_set(z, v.GetValue());
}



void cxsc_mpfi_exp(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = exp(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_exp2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = exp2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_exp10(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = exp10(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_expm1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = expm1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_expx2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = expx2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_expx2m1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = expx2m1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_expmx2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = expmx2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_expmx2m1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = expmx2m1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_ln(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = ln(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_log2(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = log2(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_log10(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = log10(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_lnp1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = lnp1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_agm(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = agm(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}

void cxsc_mpfi_ln_sin(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = ln_sin(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_ln_cos(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = ln_cos(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}



void cxsc_mpfi_ln_sqrtx2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = ln_sqrtx2y2(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_power(mpfi_t z, const mpfi_t& x, const long k)
{
	MpfiClass v = power(MpfiClass(x), k);
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_pow(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = pow(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sin(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sin(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_cos(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = cos(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_tan(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = tan(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_cot(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = cot(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_asin(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = asin(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_acos(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = acos(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_atan(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = atan(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}



void cxsc_mpfi_atan2(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = atan2(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_acot(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = acot(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}

//////


void cxsc_mpfi_sinh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sinh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_cosh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = cosh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_tanh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = tanh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_coth(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = coth(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_asinh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = asinh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_acosh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = acosh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_acoshp1(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = acoshp1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_atanh(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = atanh(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_acoth(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = acoth(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_csc(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = csc(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sec(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sec(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_csch(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = lnp1(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_sech(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = sech(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}



void cxsc_mpfi_ln_sqrtxp1_2y2(mpfi_t z, const mpfi_t& x, const mpfi_t& y)
{
	MpfiClass v = ln_sqrtxp1_2y2(MpfiClass(x), MpfiClass(y));
	mpfi_set(z, v.GetValue());
}





//// Functions of Mathematical Physics



void cxsc_mpfi_erf(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = erf(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_erfc(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = erfc(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}

//
//void cxsc_mpfi_gamma(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = gamma(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}


void cxsc_mpfi_gamma_D(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = gamma_D(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}

//
//void cxsc_mpfi_gamma_reci(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = gamma_reci(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}


void cxsc_mpfi_digamma(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = digamma(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}

//
//void cxsc_mpfi_lngamma(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = lngamma(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}
//
//
//void cxsc_mpfi_lgamma(mpfi_t z, const mpfi_t& x, int& k)
//{
//	MpfiClass v = lgamma(MpfiClass(x),k);
//	mpfi_set(z, v.GetValue());
//}


void cxsc_mpfi_factorial(mpfi_t z, const unsigned long x)
{
	MpfiClass v = ifactorial(x);
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_zeta(mpfi_t z, const unsigned long x)
{
	MpfiClass v = izeta(x);
	mpfi_set(z, v.GetValue());
}


void cxsc_mpfi_Ei(mpfi_t z, const mpfi_t& x)
{
	MpfiClass v = Ei(MpfiClass(x));
	mpfi_set(z, v.GetValue());
}

//
//void cxsc_mpfi_Li2(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = Li2(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}

//
//void cxsc_mpfi_Jn(mpfi_t z, const long n, const mpfi_t& x)
//{
//	MpfiClass v = Jn(n, MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}

//
//void cxsc_mpfi_J0(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = J0(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}
//
//
//void cxsc_mpfi_J1(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = J1(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}

/*
void cxsc_mpfi_Yn(mpfi_t z, const long n, const mpfi_t& x)
{
	MpfiClass v = Yn(n, MpfiClass(x));
	mpfi_set(z, v.GetValue());
}*/

//
//void cxsc_mpfi_Y0(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = J0(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}
//
//
//void cxsc_mpfi_Y1(mpfi_t z, const mpfi_t& x)
//{
//	MpfiClass v = J1(MpfiClass(x));
//	mpfi_set(z, v.GetValue());
//}









//////////////////////////////////////////////////////////
/////   Mpfc
//////////////////////////////////////////////////////////


 void cxsc_mpfc_add(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im)
{
	MpfcClass v = MpfcClass(x_re, x_im) + MpfcClass(y_re, y_im);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_sub(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im)
{
	MpfcClass v = MpfcClass(x_re, x_im) - MpfcClass(y_re, y_im);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_mul(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im)
{
	MpfcClass v = MpfcClass(x_re, x_im) * MpfcClass(y_re, y_im);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_div(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& y_re, const mpfr_t& y_im)
{
	MpfcClass v = MpfcClass(x_re, x_im) / MpfcClass(y_re, y_im);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_neg(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = -(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_conj(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = conj(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
}


 void cxsc_mpfc_real(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im)
{
	mpfr_set(z_re, x_re, GMP_RNDN);
}


 void cxsc_mpfc_imag(mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	mpfr_set(z_im, x_im, GMP_RNDN);
}


 void cxsc_mpfc_abs(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfrClass v = abs(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfc_arg(mpfr_t z_re, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfrClass v = arg(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValue(), GMP_RNDN);
}


 void cxsc_mpfc_sqr(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = sqr(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_sqrt(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = sqrt(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }

//
// void cxsc_mpfc_sqrt_all(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
//{
//	MpfcClass v = sqrt_all(MpfcClass(x_re, x_im));
//	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
//	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
// }


 void cxsc_mpfc_nth_root(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const unsigned long n)
{
	MpfcClass v = sqrt(MpfcClass(x_re, x_im), n);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }

//
// void cxsc_mpfc_nth_root_all(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const unsigned long n)
//{
//	MpfcClass v = sqrt_all(MpfcClass(x_re, x_im, n));
//	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
//	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
// }


 void cxsc_mpfc_ln(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = ln(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_log2(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = log2(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_log10(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = log10(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_exp(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = exp(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_exp2(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = exp2(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_exp10(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = exp10(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_power(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const int& n)
{
	MpfcClass v = power(MpfcClass(x_re, x_im), n);
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_pow_r(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& n_re)
{
	MpfcClass v = pow(MpfcClass(x_re, x_im), MpfrClass(n_re));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_pow_c(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im, const mpfr_t& n_re, const mpfr_t& n_im)
{
	MpfcClass v = pow(MpfcClass(x_re, x_im), MpfcClass(n_re, n_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_sin(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = sin(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_cos(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = cos(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_tan(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = tan(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_cot(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = cot(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_asin(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = asin(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_acos(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = acos(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_atan(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = atan(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_acot(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = acot(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_sinh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = sinh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_cosh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = cosh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_tanh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = tanh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_coth(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = coth(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_asinh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = asinh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_acosh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = acosh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_atanh(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = atanh(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }


 void cxsc_mpfc_acoth(mpfr_t z_re, mpfr_t z_im, const mpfr_t& x_re, const mpfr_t& x_im)
{
	MpfcClass v = acoth(MpfcClass(x_re, x_im));
	mpfr_set(z_re, v.GetValueRe(), GMP_RNDN);
	mpfr_set(z_im, v.GetValueIm(), GMP_RNDN);
 }








//////////////////////////////////////////////////////////
/////   Mpfci
//////////////////////////////////////////////////////////



 void cxsc_mpfci_add(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im)
{
	MpfciClass v = MpfciClass(x_re, x_im) + MpfciClass(y_re, y_im);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_sub(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im)
{
	MpfciClass v = MpfciClass(x_re, x_im) - MpfciClass(y_re, y_im);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_mul(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im)
{
	MpfciClass v = MpfciClass(x_re, x_im) * MpfciClass(y_re, y_im);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_div(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& y_re, const mpfi_t& y_im)
{
	MpfciClass v = MpfciClass(x_re, x_im) / MpfciClass(y_re, y_im);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_neg(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = -(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_conj(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = conj(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
}


 void cxsc_mpfci_real(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im)
{
	mpfi_set(z_re, x_re);
}


 void cxsc_mpfci_imag(mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	mpfi_set(z_im, x_im);
}


 void cxsc_mpfci_abs(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfiClass v = abs(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValue());
}


 void cxsc_mpfci_arg(mpfi_t z_re, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfiClass v = arg(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValue());
}


 void cxsc_mpfci_sqr(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = sqr(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_sqrt(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = sqrt(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }

//
// void cxsc_mpfci_sqrt_all(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
//{
//	MpfciClass v = sqrt_all(MpfciClass(x_re, x_im));
//	mpfi_set(z_re, v.GetValueRe());
//	mpfi_set(z_im, v.GetValueIm());
// }


 void cxsc_mpfci_nth_root(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const unsigned long n)
{
	MpfciClass v = sqrt(MpfciClass(x_re, x_im), n);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }

//
// void cxsc_mpfci_nth_root_all(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const unsigned long n)
//{
//	MpfciClass v = sqrt_all(MpfciClass(x_re, x_im, n));
//	mpfi_set(z_re, v.GetValueRe());
//	mpfi_set(z_im, v.GetValueIm());
// }


 void cxsc_mpfci_ln(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = ln(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_log2(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = log2(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_log10(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = log10(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_exp(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = exp(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_exp2(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = exp2(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_exp10(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = exp10(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_power(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const int& n)
{
	MpfciClass v = power(MpfciClass(x_re, x_im), n);
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_pow_r(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& n_re)
{
	MpfciClass v = pow(MpfciClass(x_re, x_im), MpfiClass(n_re));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_pow_c(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im, const mpfi_t& n_re, const mpfi_t& n_im)
{
	MpfciClass v = pow(MpfciClass(x_re, x_im), MpfciClass(n_re, n_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_sin(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = sin(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_cos(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = cos(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_tan(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = tan(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_cot(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = cot(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_asin(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = asin(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_acos(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = acos(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_atan(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = atan(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_acot(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = acot(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_sinh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = sinh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_cosh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = cosh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_tanh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = tanh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_coth(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = coth(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_asinh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = asinh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_acosh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = acosh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_atanh(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = atanh(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


 void cxsc_mpfci_acoth(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
{
	MpfciClass v = acoth(MpfciClass(x_re, x_im));
	mpfi_set(z_re, v.GetValueRe());
	mpfi_set(z_im, v.GetValueIm());
 }


//
//
//
// void cxsc_mpfci_Sqrt(mpfi_t z_re, mpfi_t z_im, const mpfi_t& x_re, const mpfi_t& x_im)
//{
//	MpfciClass v = sqrt(MpfciClass(x_re, x_im));
//	mpfi_set(z_re, v.GetValueRe());
//	mpfi_set(z_im, v.GetValueIm());
	//mpfi_set(z_re, x_re);
	//mpfi_set(z_im, x_im);
 //}

