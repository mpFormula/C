/* libBoostMath.h: this file is part of the mpFormula Library
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




//Special Functions


#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)

//************************************************************************************
BOOST_DLL_IMPORTEXPORT void boost_tgamma(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_tgamma1pm1(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_lgamma(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_digamma(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_tgamma_ratio(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_tgamma_delta_ratio(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);

BOOST_DLL_IMPORTEXPORT void boost_gamma_p(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_gamma_q(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_tgamma_lower(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_tgamma_upper(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);

BOOST_DLL_IMPORTEXPORT void boost_gamma_p_inv(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_gamma_q_inv(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_gamma_p_inva(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_gamma_q_inva(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_gamma_p_derivative(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);

BOOST_DLL_IMPORTEXPORT void boost_factorial(boost_mp_result y, boost_mp_input i_);
BOOST_DLL_IMPORTEXPORT void boost_unchecked_factorial(boost_mp_result y,  boost_mp_input i_);
BOOST_DLL_IMPORTEXPORT void boost_double_factorial(boost_mp_result y,  boost_mp_input i_);
BOOST_DLL_IMPORTEXPORT void boost_rising_factorial(boost_mp_result y, boost_mp_input x, boost_mp_input i_);
BOOST_DLL_IMPORTEXPORT void boost_falling_factorial(boost_mp_result y, boost_mp_input x, boost_mp_input i_);
BOOST_DLL_IMPORTEXPORT void boost_binomial_coefficient(boost_mp_result y, boost_mp_input i_, boost_mp_input j_);

BOOST_DLL_IMPORTEXPORT void boost_beta(boost_mp_result y, boost_mp_input x0, boost_mp_input x1);
BOOST_DLL_IMPORTEXPORT void boost_ibeta(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x0);
BOOST_DLL_IMPORTEXPORT void boost_ibetac(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);


BOOST_DLL_IMPORTEXPORT void boost_ibetac(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibeta_non_normalized(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibetac_non_normalized(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);

BOOST_DLL_IMPORTEXPORT void boost_ibeta_inv(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibetac_inv(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
//BOOST_DLL_IMPORTEXPORT boost_mp_fixed boost_ibeta_inv2(boost_mp_fixed a, boost_mp_fixed b, boost_mp_fixed x, boost_mp_fixed *y);;
//BOOST_DLL_IMPORTEXPORT boost_mp_fixed boost_ibetac_inv2(boost_mp_fixed a, boost_mp_fixed b, boost_mp_fixed x, boost_mp_fixed *y);;

BOOST_DLL_IMPORTEXPORT void boost_ibeta_inva(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibetac_inva(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibeta_invb(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibetac_invb(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_ibeta_derivative(boost_mp_result y, boost_mp_input a, boost_mp_input b, boost_mp_input x);


// Error function

BOOST_DLL_IMPORTEXPORT void boost_erf(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_erfc(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_erf_inv(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_erfc_inv(boost_mp_result y, boost_mp_input x);


// Polynomials

BOOST_DLL_IMPORTEXPORT void boost_legendre_p(boost_mp_result y, boost_mp_input n_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_legendre_p_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_legendre_q(boost_mp_result y, boost_mp_input n_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_legendre_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Pl, boost_mp_input Plm1);
BOOST_DLL_IMPORTEXPORT void boost_legendre_next_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x, boost_mp_input Pl, boost_mp_input Plm1);

BOOST_DLL_IMPORTEXPORT void boost_laguerre(boost_mp_result y, boost_mp_input n_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_laguerre_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_laguerre_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Ln, boost_mp_input Lnm1);
BOOST_DLL_IMPORTEXPORT void boost_laguerre_next_m(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input x, boost_mp_input Ln, boost_mp_input Lnm1);

BOOST_DLL_IMPORTEXPORT void boost_hermite(boost_mp_result y, boost_mp_input n_, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_hermite_next(boost_mp_result y, boost_mp_input n_, boost_mp_input x, boost_mp_input Hn, boost_mp_input Hnm1);

BOOST_DLL_IMPORTEXPORT void boost_spherical_harmonic_r(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input theta, boost_mp_input phi);
BOOST_DLL_IMPORTEXPORT void boost_spherical_harmonic_i(boost_mp_result y, boost_mp_input n_, boost_mp_input m_, boost_mp_input theta, boost_mp_input phi);





//Bessel Functions


BOOST_DLL_IMPORTEXPORT void boost_cyl_bessel_j(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_cyl_neumann(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_cyl_bessel_i(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_cyl_bessel_k(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_sph_bessel(boost_mp_result y, boost_mp_input v_, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_sph_neumann(boost_mp_result y, boost_mp_input v_, boost_mp_input y0);


// Airy Functions
BOOST_DLL_IMPORTEXPORT void boost_airy_ai(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_airy_bi(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_airy_ai_prime(boost_mp_result y, boost_mp_input x);
BOOST_DLL_IMPORTEXPORT void boost_airy_bi_prime(boost_mp_result y, boost_mp_input x);


//Elliptic Integrals

BOOST_DLL_IMPORTEXPORT void boost_ellint_rf(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z0);
BOOST_DLL_IMPORTEXPORT void boost_ellint_rd(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z0);
BOOST_DLL_IMPORTEXPORT void boost_ellint_rj(boost_mp_result y, boost_mp_input x0, boost_mp_input y0, boost_mp_input z, boost_mp_input p);
BOOST_DLL_IMPORTEXPORT void boost_ellint_rc(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);

BOOST_DLL_IMPORTEXPORT void boost_ellint_1_F(boost_mp_result y, boost_mp_input k, boost_mp_input phi);
BOOST_DLL_IMPORTEXPORT void boost_ellint_1_K(boost_mp_result y, boost_mp_input k);
BOOST_DLL_IMPORTEXPORT void boost_ellint_2_F(boost_mp_result y, boost_mp_input k, boost_mp_input phi);
BOOST_DLL_IMPORTEXPORT void boost_ellint_2_K(boost_mp_result y, boost_mp_input k);
BOOST_DLL_IMPORTEXPORT void boost_ellint_3_F(boost_mp_result y, boost_mp_input k, boost_mp_input n, boost_mp_input phi);
BOOST_DLL_IMPORTEXPORT void boost_ellint_3_K(boost_mp_result y, boost_mp_input k, boost_mp_input n);



// Jacobi Elliptic Functions

BOOST_DLL_IMPORTEXPORT void boost_jacobi_cd(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_cn(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_cs(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_dc(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_dn(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_ds(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_nc(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_nd(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_ns(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_sc(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_sd(boost_mp_result y, boost_mp_input k, boost_mp_input u);
BOOST_DLL_IMPORTEXPORT void boost_jacobi_sn(boost_mp_result y, boost_mp_input k, boost_mp_input u);


// Zeta Function


BOOST_DLL_IMPORTEXPORT void boost_zeta(boost_mp_result y, boost_mp_input z);


// Exponential Integral

BOOST_DLL_IMPORTEXPORT void boost_expint_n(boost_mp_result y, boost_mp_input n_, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_expint_ei(boost_mp_result y, boost_mp_input z);


// Log and Exp
BOOST_DLL_IMPORTEXPORT void boost_sign(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_round(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_trunc(boost_mp_result y, boost_mp_input z);

BOOST_DLL_IMPORTEXPORT void boost_asinh(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_acosh(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_atanh(boost_mp_result y, boost_mp_input z);

BOOST_DLL_IMPORTEXPORT void boost_log1p(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_expm1(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_cbrt(boost_mp_result y, boost_mp_input z);

BOOST_DLL_IMPORTEXPORT void boost_log1p(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_expm1(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_cbrt(boost_mp_result y, boost_mp_input z);

BOOST_DLL_IMPORTEXPORT void boost_sqrt1pm1(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_powm1(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_hypot(boost_mp_result y, boost_mp_input x0, boost_mp_input y0);
BOOST_DLL_IMPORTEXPORT void boost_sinc_pi(boost_mp_result y, boost_mp_input z);
BOOST_DLL_IMPORTEXPORT void boost_sinhc_pi(boost_mp_result y, boost_mp_input z);




//Distribution Functions

BOOST_DLL_IMPORTEXPORT void boost_bernoulli(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input p);
BOOST_DLL_IMPORTEXPORT void boost_betadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input a, boost_mp_input b);
BOOST_DLL_IMPORTEXPORT void boost_binomialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input n, boost_mp_input p);
BOOST_DLL_IMPORTEXPORT void boost_cauchydist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_cdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu);
BOOST_DLL_IMPORTEXPORT void boost_exponentialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lambda);
BOOST_DLL_IMPORTEXPORT void boost_extreme_valuedist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_fdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mu, boost_mp_input nu);
BOOST_DLL_IMPORTEXPORT void boost_gammadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_hypergeometricdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input r_, boost_mp_input n_, boost_mp_input N_);
BOOST_DLL_IMPORTEXPORT void boost_inversechisquareddist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input df, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_inversegammadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_inversegaussiandist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_laplacedist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_logisticdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_lognormaldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_negative_binomialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input n, boost_mp_input p);
BOOST_DLL_IMPORTEXPORT void boost_ndist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input stdev);
BOOST_DLL_IMPORTEXPORT void boost_paretodist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_poissondist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu);
BOOST_DLL_IMPORTEXPORT void boost_rayleighdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu);
BOOST_DLL_IMPORTEXPORT void boost_tdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu);
BOOST_DLL_IMPORTEXPORT void boost_triangulardist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lower, boost_mp_input mode, boost_mp_input upper);
BOOST_DLL_IMPORTEXPORT void boost_weibulldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale);
BOOST_DLL_IMPORTEXPORT void boost_uniformdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lower, boost_mp_input upper);

#endif // UseLongDouble




BOOST_DLL_IMPORTEXPORT void boost_cdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu, boost_mp_input nc);
BOOST_DLL_IMPORTEXPORT void boost_tdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu, boost_mp_input nc);
BOOST_DLL_IMPORTEXPORT void boost_fdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mu, boost_mp_input nu, boost_mp_input nc);
BOOST_DLL_IMPORTEXPORT void boost_betadistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input a, boost_mp_input b, boost_mp_input nc);
BOOST_DLL_IMPORTEXPORT void boost_skewnormaldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input scale, boost_mp_input shape);


BOOST_DLL_IMPORTEXPORT void boost_owens_t(boost_mp_result y, boost_mp_input h, boost_mp_input a);


