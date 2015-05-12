/* BoostMathSpecialFunctions.cpp: this file is part of the mpFormula Library
 *
 * Copyright (C) 2008, 2009, 2010 Dietrich Hadler
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or (at
 * your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */


#ifdef Use_LongDouble
    #define BOOST_RETURN *y = result;
    typedef long double boost_mp_fixed;
#endif // Use_LongDouble



#ifdef Use_Mpfr_float_100
    #include <boost/multiprecision/mpfr.hpp>
    using namespace boost::multiprecision;
    #define BOOST_RETURN mpfr_set(y, result.backend().data(),mpfr_get_default_rounding_mode());
    #define boost_mp_fixed mpfr_float_100
#endif // Use_Mpfr_float_100







#include "libBoostMath.h"



#include <boost/math/special_functions.hpp>

using namespace boost::math;



void boost_tgamma(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  tgamma(boost_mp_fixed(x));
    BOOST_RETURN
}



void boost_tgamma1pm1(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  tgamma1pm1(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_lgamma(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  lgamma(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_digamma(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  digamma(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_tgamma_ratio(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  tgamma_ratio(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_tgamma_delta_ratio(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  tgamma_delta_ratio(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_p(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_p(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_q(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_q(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_tgamma_lower(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  tgamma_lower(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_tgamma_upper(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  tgamma(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_p_inv(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_p_inv(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_q_inv(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_q_inv(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_p_inva(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_p_inva(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_q_inva(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_q_inva(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_gamma_p_derivative(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  gamma_p_derivative(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_factorial(boost_mp_result y, boost_mp_input i_)
{
    unsigned int i = 10;
    boost_mp_fixed result =  factorial<boost_mp_fixed>(i);
    BOOST_RETURN
}


void boost_unchecked_factorial(boost_mp_result y,  boost_mp_input i_)
{
    unsigned int i = 10;
    boost_mp_fixed result =  unchecked_factorial<boost_mp_fixed>(i);
    BOOST_RETURN
}


void boost_double_factorial(boost_mp_result y,  boost_mp_input i_)
{
    unsigned int i = 10;
    boost_mp_fixed result =  double_factorial<boost_mp_fixed>(i);
    BOOST_RETURN
}


void boost_rising_factorial(boost_mp_result y, boost_mp_input x, boost_mp_input i_)
{
    int i = 10;
    boost_mp_fixed result =  rising_factorial(boost_mp_fixed(x), i);
    BOOST_RETURN
}


void boost_falling_factorial(boost_mp_result y, boost_mp_input x, boost_mp_input i_)
{
    int i = 10;
    boost_mp_fixed result =  falling_factorial(boost_mp_fixed(x), i);
    BOOST_RETURN
}


void boost_binomial_coefficient(boost_mp_result y, boost_mp_input i_, boost_mp_input j_)
{
    unsigned int i = 10;
    unsigned int j = 10;
    boost_mp_fixed result =  binomial_coefficient<boost_mp_fixed>(i, j);
    BOOST_RETURN
}



// Beta function

void boost_beta(boost_mp_result y, boost_mp_input x0, boost_mp_input x1)
{
    boost_mp_fixed result =  beta(boost_mp_fixed(x0), boost_mp_fixed(x1));
    BOOST_RETURN
}

void boost_ibeta(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x0)
{
    boost_mp_fixed result =  ibeta(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x0));
    BOOST_RETURN
}


void boost_ibetac(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibetac(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibeta_non_normalized(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  beta(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibetac_non_normalized(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  betac(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibeta_inv(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibeta_inv(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibetac_inv(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibetac_inv(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}

//
//void boost_ibeta_inv2(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x, boost_mp_result y1)
//{
//    boost_mp_fixed result =  ibeta_inv(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x), boost_mp_fixed(y));
//    BOOST_RETURN
//}
//
//
//void boost_ibetac_inv2(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x, boost_mp_result y1)
//{
//    boost_mp_fixed result =  ibetac_inv(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x), boost_mp_fixed(y));
//    BOOST_RETURN
//}



void boost_ibeta_inva(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibeta_inva(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibetac_inva(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibetac_inva(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibeta_invb(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibeta_invb(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibetac_invb(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibetac_invb(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_ibeta_derivative(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x)
{
    boost_mp_fixed result =  ibeta_derivative(boost_mp_fixed(a), boost_mp_fixed(b), boost_mp_fixed(x));
    BOOST_RETURN
}



void boost_erf(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  erf(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_erfc(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  erfc(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_erf_inv(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  erf_inv(boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_erfc_inv(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  erfc_inv(boost_mp_fixed(x));
    BOOST_RETURN
}


// Polynomials


void boost_legendre_p(boost_mp_result y, boost_mp_input n_, boost_mp_input x)
{
    int n = 10;
    boost_mp_fixed result =  legendre_p(n, boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_legendre_p_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  legendre_p(n, m, boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_legendre_q(boost_mp_result y, boost_mp_input n_, boost_mp_input x)
{
    int n = 10;
    boost_mp_fixed result =  legendre_q(n, boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_legendre_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Pl, boost_mp_input Plm1)
{
    int n = 10;
    boost_mp_fixed result =  legendre_next(n, boost_mp_fixed(x), boost_mp_fixed(Pl), boost_mp_fixed(Plm1));
    BOOST_RETURN
}


void boost_legendre_next_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x, boost_mp_input Pl, boost_mp_input Plm1)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  legendre_next(n, m, boost_mp_fixed(x), boost_mp_fixed(Pl), boost_mp_fixed(Plm1));
    BOOST_RETURN
}




void boost_laguerre(boost_mp_result y, boost_mp_input n_, boost_mp_input x)
{
    int n = 10;
    boost_mp_fixed result =  laguerre(n, boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_laguerre_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  laguerre(n, m, boost_mp_fixed(x));
    BOOST_RETURN
}


void boost_laguerre_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Ln, boost_mp_input Lnm1)
{
    int n = 10;
    boost_mp_fixed result =  laguerre_next(n, boost_mp_fixed(x), boost_mp_fixed(Ln), boost_mp_fixed(Lnm1));
    BOOST_RETURN
}


void boost_laguerre_next_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x, boost_mp_input Ln, boost_mp_input Lnm1)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  laguerre_next(n, m, boost_mp_fixed(x), boost_mp_fixed(Ln), boost_mp_fixed(Lnm1));
    BOOST_RETURN
}




void boost_hermite(boost_mp_result y, boost_mp_input n_, boost_mp_input x)
{
    int n = 10;
    boost_mp_fixed result =  hermite(n, boost_mp_fixed(x));
    BOOST_RETURN
}

void boost_hermite_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Hn, boost_mp_input Hnm1)
{
    int n = 10;
    boost_mp_fixed result =  hermite_next(n, boost_mp_fixed(x), boost_mp_fixed(Hn), boost_mp_fixed(Hnm1));
    BOOST_RETURN
}



void boost_spherical_harmonic_r(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input theta, boost_mp_input phi)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  spherical_harmonic_r(n, m, boost_mp_fixed(theta), boost_mp_fixed(phi));
    BOOST_RETURN
}


void boost_spherical_harmonic_i(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input theta, boost_mp_input phi)
{
    int n = 10;
    int m = 10;
    boost_mp_fixed result =  spherical_harmonic_i(n, m, boost_mp_fixed(theta), boost_mp_fixed(phi));
    BOOST_RETURN
}



//Bessel Functions


void boost_cyl_bessel_j(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  cyl_bessel_j(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_cyl_neumann(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  cyl_neumann(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_cyl_bessel_i(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  cyl_bessel_i(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_cyl_bessel_k(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  cyl_bessel_k(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_sph_bessel(boost_mp_result y, boost_mp_input v_, boost_mp_input y0)
{
    unsigned v = 10;
    boost_mp_fixed result =  sph_bessel(v, boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_sph_neumann(boost_mp_result y, boost_mp_input v_, boost_mp_input y0)
{
    unsigned v = 10;
    boost_mp_fixed result =  sph_neumann(v, boost_mp_fixed(y0));
    BOOST_RETURN
}

// Airy Functions

void boost_airy_ai(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  airy_ai(boost_mp_fixed(x));
    BOOST_RETURN
}

void boost_airy_bi(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  airy_bi(boost_mp_fixed(x));
    BOOST_RETURN
}

void boost_airy_ai_prime(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  airy_ai_prime(boost_mp_fixed(x));
    BOOST_RETURN
}

void boost_airy_bi_prime(boost_mp_result y, boost_mp_input x)
{
    boost_mp_fixed result =  airy_bi_prime(boost_mp_fixed(x));
    BOOST_RETURN
}



//Elliptic Integrals


void boost_ellint_rf(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z0)
{
    boost_mp_fixed result =  ellint_rf(boost_mp_fixed(x0), boost_mp_fixed(y0), boost_mp_fixed(z0));
    BOOST_RETURN
}


void boost_ellint_rd(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z0)
{
    boost_mp_fixed result =  ellint_rd(boost_mp_fixed(x0), boost_mp_fixed(y0), boost_mp_fixed(z0));
    BOOST_RETURN
}

void boost_ellint_rj(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z, boost_mp_input p)
{
    boost_mp_fixed result =  ellint_rj(boost_mp_fixed(x0), boost_mp_fixed(y0), boost_mp_fixed(z), boost_mp_fixed(p));
    BOOST_RETURN
}



void boost_ellint_rc(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  ellint_rc(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}



void boost_ellint_1_F(boost_mp_result y, boost_mp_input k, boost_mp_input phi)
{
    boost_mp_fixed result =  ellint_1(boost_mp_fixed(k), boost_mp_fixed(phi));
    BOOST_RETURN
}


void boost_ellint_1_K(boost_mp_result y, boost_mp_input k)
{
    boost_mp_fixed result =  ellint_1(boost_mp_fixed(k));
    BOOST_RETURN
}


void boost_ellint_2_F(boost_mp_result y, boost_mp_input k, boost_mp_input phi)
{
    boost_mp_fixed result =  ellint_2(boost_mp_fixed(k), boost_mp_fixed(phi));
    BOOST_RETURN
}


void boost_ellint_2_K(boost_mp_result y, boost_mp_input k)
{
    boost_mp_fixed result =  ellint_2(boost_mp_fixed(k));
    BOOST_RETURN
}


void boost_ellint_3_F(boost_mp_result y, boost_mp_input k, boost_mp_input n, boost_mp_input phi)
{
    boost_mp_fixed result =  ellint_3(boost_mp_fixed(k), boost_mp_fixed(n), boost_mp_fixed(phi));
    BOOST_RETURN
}


void boost_ellint_3_K(boost_mp_result y, boost_mp_input k, boost_mp_input n)
{
    boost_mp_fixed result =  ellint_3(boost_mp_fixed(k), boost_mp_fixed(n));
    BOOST_RETURN
}


// Jacobi Elliptic Functions

void boost_jacobi_cd(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_cd(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_cn(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_cn(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_cs(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_cs(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_dc(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_dc(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_dn(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_dn(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_ds(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_ds(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_nc(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_nc(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_nd(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_nd(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_ns(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_ns(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_sc(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_sc(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_sd(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_sd(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}

void boost_jacobi_sn(boost_mp_result y, boost_mp_input k, boost_mp_input u)
{
    boost_mp_fixed result =  jacobi_sn(boost_mp_fixed(k), boost_mp_fixed(u));
    BOOST_RETURN
}



// Zeta Function

void boost_zeta(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  zeta(boost_mp_fixed(z));
    BOOST_RETURN
}



// Exponential Integral

void boost_expint_n(boost_mp_result y, boost_mp_input n_, boost_mp_input z)
{
    unsigned n = 10;
    boost_mp_fixed result =  expint(n, boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_expint_ei(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  expint(boost_mp_fixed(z));
    BOOST_RETURN
}


// Log and Exp



void boost_sign(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  sign(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_round(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  round(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_trunc(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  trunc(boost_mp_fixed(z));
    BOOST_RETURN
}

void boost_asinh(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  asinh(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_acosh(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  acosh(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_atanh(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  atanh(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_log1p(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  log1p(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_expm1(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  expm1(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_cbrt(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result = cbrt(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_sqrt1pm1(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  sqrt1pm1(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_powm1(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result =  powm1(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_hypot(boost_mp_result y, boost_mp_input x0, boost_mp_input y0)
{
    boost_mp_fixed result = hypot(boost_mp_fixed(x0), boost_mp_fixed(y0));
    BOOST_RETURN
}


void boost_sinc_pi(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  sinc_pi(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_sinhc_pi(boost_mp_result y, boost_mp_input z)
{
    boost_mp_fixed result =  sinhc_pi(boost_mp_fixed(z));
    BOOST_RETURN
}


void boost_owens_t(boost_mp_result y, boost_mp_input h, boost_mp_input a)
{
    boost_mp_fixed result =  owens_t(boost_mp_fixed(h), boost_mp_fixed(a));
    BOOST_RETURN
}


