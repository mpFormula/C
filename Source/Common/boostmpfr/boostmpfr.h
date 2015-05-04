
#pragma once
#include <mpfr.h>
//#include <EigenLib.h>
//#include <EigenLibMpfr.h>

// Gamma function

void boost_mpfr_tgamma(mpfr_t z, mpfr_t x);
void boost_mpfr_tgamma1pm1(mpfr_t z, mpfr_t x);
void boost_mpfr_lgamma(mpfr_t z, mpfr_t x);
void boost_mpfr_digamma(mpfr_t z, mpfr_t x);
void boost_mpfr_tgamma_ratio(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_tgamma_delta_ratio(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_p(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_q(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_tgamma_lower(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_tgamma_upper(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_p_inv(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_q_inv(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_p_inva(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_q_inva(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_gamma_p_derivative(mpfr_t z, mpfr_t x, mpfr_t y);


// Factorial

void boost_mpfr_factorial(mpfr_t z, unsigned int i);
void boost_mpfr_unchecked_factorial(mpfr_t z, unsigned int i);
void boost_mpfr_double_factorial(mpfr_t z, unsigned int i);
void boost_mpfr_rising_factorial(mpfr_t z, mpfr_t x, unsigned int i);
void boost_mpfr_falling_factorial(mpfr_t z, mpfr_t x, unsigned int i);
void boost_mpfr_binomial_coefficien(mpfr_t z,  unsigned int i, unsigned int j);



// Beta function

void boost_mpfr_beta(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_ibeta(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibetac(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibeta_non_normalized(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibetac_non_normalized(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibeta_inv(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibetac_inv(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibeta_inv2(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x, mpfr_t y);
void boost_mpfr_ibetac_inv2(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x, mpfr_t y);
void boost_mpfr_ibeta_inva(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibetac_inva(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibeta_invb(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibetac_invb(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);
void boost_mpfr_ibeta_derivative(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x);



// Error function
void boost_mpfr_erf(mpfr_t z, mpfr_t x);
void boost_mpfr_erfc(mpfr_t z, mpfr_t x);
void boost_mpfr_erf_inv(mpfr_t z, mpfr_t x);
void boost_mpfr_erfc_inv(mpfr_t z, mpfr_t x);


// Polynomials
void boost_mpfr_legendre_p(mpfr_t z, int n, mpfr_t x);
void boost_mpfr_legendre_p_m(mpfr_t z, int n, int m, mpfr_t x);
void boost_mpfr_legendre_q(mpfr_t z, int n, mpfr_t x);
void boost_mpfr_legendre_next(mpfr_t z, int n, mpfr_t x, mpfr_t Pl, mpfr_t Plm1);
void boost_mpfr_legendre_next_m1(mpfr_t z, int n, int m, mpfr_t x, mpfr_t Pl, mpfr_t Plm1);

void boost_mpfr_laguerre(mpfr_t z, int n, mpfr_t x);
void boost_mpfr_laguerre_m(mpfr_t z, int n, int m, mpfr_t x);
void boost_mpfr_laguerre_next(mpfr_t z, int n, mpfr_t x, mpfr_t Ln, mpfr_t Lnm1);
void boost_mpfr_laguerre_next_m1(mpfr_t z, int n, int m, mpfr_t x, mpfr_t Ln, mpfr_t Lnm1);

void boost_mpfr_hermite(mpfr_t z, int n, mpfr_t x);
void boost_mpfr_hermite_next_m1(mpfr_t z, int n, mpfr_t x, mpfr_t Hn, mpfr_t Hnm1);

void boost_mpfr_spherical_harmonic_r(mpfr_t z, int n, int m, mpfr_t theta, mpfr_t phi);
void boost_mpfr_spherical_harmonic_i(mpfr_t z, int n, int m, mpfr_t theta, mpfr_t phi);



//Bessel Functions
void boost_mpfr_cyl_bessel_j(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_cyl_neumann(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_cyl_bessel_i(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_cyl_bessel_k(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_sph_bessel(mpfr_t z, unsigned nu,  mpfr_t y);
void boost_mpfr_sph_neumann(mpfr_t z, unsigned nu,  mpfr_t y);


//Elliptic Integrals
void boost_mpfr_ellint_rf(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1);
void boost_mpfr_ellint_rd(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1);
void boost_mpfr_ellint_rj(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1, mpfr_t p);
void boost_mpfr_ellint_rc(mpfr_t z, mpfr_t x, mpfr_t y);

void boost_mpfr_ellint_1_F(mpfr_t z, mpfr_t k, mpfr_t phi);
void boost_mpfr_ellint_1_K(mpfr_t z, mpfr_t k);
void boost_mpfr_ellint_2_F(mpfr_t z, mpfr_t k, mpfr_t phi);
void boost_mpfr_ellint_2_K(mpfr_t z, mpfr_t k);
void boost_mpfr_ellint_3_F(mpfr_t z, mpfr_t k, mpfr_t n, mpfr_t phi);
void boost_mpfr_ellint_3_K(mpfr_t z, mpfr_t k, mpfr_t n);


// Zeta Function
void boost_mpfr_zeta(mpfr_t z, mpfr_t x);


// Exponential Integral
void boost_mpfr_expint_n(mpfr_t z, unsigned n, mpfr_t x);
void boost_mpfr_expint_ei(mpfr_t z, mpfr_t x);


// Log and Exp
void boost_mpfr_log1p(mpfr_t z, mpfr_t x);
void boost_mpfr_expm1(mpfr_t z, mpfr_t x);
void boost_mpfr_cbrt(mpfr_t z, mpfr_t x);
void boost_mpfr_sqrt1pm1(mpfr_t z, mpfr_t x);
void boost_mpfr_powm1(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_hypot(mpfr_t z, mpfr_t x, mpfr_t y);
void boost_mpfr_sinc_pi(mpfr_t z, mpfr_t x);
void boost_mpfr_sinhc_pi(mpfr_t z, mpfr_t x);



//Distribution Functions

void boost_mpfr_pdf_bernoulli (mpfr_t z, mpfr_t x, mpfr_t p); 
void boost_mpfr_cdf_bernoulli_P (mpfr_t z, mpfr_t x, mpfr_t p); 
void boost_mpfr_cdf_bernoulli_Q (mpfr_t z, mpfr_t x, mpfr_t p);
void boost_mpfr_cdf_bernoulli_Pinv (mpfr_t z, mpfr_t P, mpfr_t p); 
void boost_mpfr_cdf_bernoulli_Qinv (mpfr_t z, mpfr_t Q, mpfr_t p); 


void boost_mpfr_pdf_betadist (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b) ;
void boost_mpfr_cdf_betadist_P (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b) ;
void boost_mpfr_cdf_betadist_Q (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b) ;
void boost_mpfr_cdf_betadist_Pinv (mpfr_t z, mpfr_t P, mpfr_t a, mpfr_t b) ;
void boost_mpfr_cdf_betadist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t a, mpfr_t b) ;


void boost_mpfr_pdf_binomialdist (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p);
void boost_mpfr_cdf_binomialdist_P (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p) ;
void boost_mpfr_cdf_binomialdist_Q (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p) ;
void boost_mpfr_cdf_binomialdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t n, mpfr_t p) ;
void boost_mpfr_cdf_binomialdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t n, mpfr_t p) ;


void boost_mpfr_pdf_cauchydist (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
void boost_mpfr_cdf_cauchydist_P (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
void boost_mpfr_cdf_cauchydist_Q (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
void boost_mpfr_cdf_cauchydist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale) ;
void boost_mpfr_cdf_cauchydist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale) ;

 
 void boost_mpfr_pdf_cdist (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_cdist_P (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_cdist_Q (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_cdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t p) ;
 void boost_mpfr_cdf_cdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t p) ;


 void boost_mpfr_pdf_exponentialdist (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_exponentialdist_P (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_exponentialdist_Q (mpfr_t z, mpfr_t x, mpfr_t p) ;
 void boost_mpfr_cdf_exponentialdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t p) ;
 void boost_mpfr_cdf_exponentialdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t p) ;


 void boost_mpfr_pdf_extreme_valuedist (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_extreme_valuedist_P (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_extreme_valuedist_Q (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_extreme_valuedist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_extreme_valuedist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale) ;


 void boost_mpfr_pdf_fdist (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu) ;
 void boost_mpfr_cdf_fdist_P (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu) ;
 void boost_mpfr_cdf_fdist_Q (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu) ;
 void boost_mpfr_cdf_fdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu) ;
 void boost_mpfr_cdf_fdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu) ;


 void boost_mpfr_pdf_gammadist (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_gammadist_P (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_gammadist_Q (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_gammadist_Pinv (mpfr_t z, mpfr_t P, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_gammadist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t shape, mpfr_t scale) ;


 void boost_mpfr_pdf_hypergeometricdist (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N) ;
 void boost_mpfr_cdf_hypergeometricdist_P (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N);
 void boost_mpfr_cdf_hypergeometricdist_Q (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N) ;
 void boost_mpfr_cdf_hypergeometricdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t r, mpfr_t n, mpfr_t N) ;
 void boost_mpfr_cdf_hypergeometricdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t r, mpfr_t n, mpfr_t N) ;
 

 void boost_mpfr_pdf_laplacedist (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale);
 void boost_mpfr_cdf_laplacedist_P (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_laplacedist_Q (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_laplacedist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_laplacedist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale) ;


 void boost_mpfr_pdf_logisticdist (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_logisticdist_P (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_logisticdist_Q (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_logisticdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale);
 void boost_mpfr_cdf_logisticdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale) ;


 void boost_mpfr_pdf_lognormaldist (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_lognormaldist_P (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_lognormaldist_Q (mpfr_t z, mpfr_t x, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_lognormaldist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale) ;
 void boost_mpfr_cdf_lognormaldist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale) ;


 void boost_mpfr_pdf_negative_binomialdist (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p) ;
 void boost_mpfr_cdf_negative_binomialdist_P (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p) ;
 void boost_mpfr_cdf_negative_binomialdist_Q (mpfr_t z, mpfr_t x, mpfr_t n, mpfr_t p) ;
 void boost_mpfr_cdf_negative_binomialdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t n, mpfr_t p) ;
 void boost_mpfr_cdf_negative_binomialdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t n, mpfr_t p) ;


 void boost_mpfr_pdf_cdistn (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_cdistn_P (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_cdistn_Q (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_cdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_cdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu, mpfr_t nc) ;


 void boost_mpfr_pdf_tdistn (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_tdistn_P (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_tdistn_Q (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_tdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_tdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu, mpfr_t nc) ;


 void boost_mpfr_pdf_fdistn (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_fdistn_P (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_fdistn_Q (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_fdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_fdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;


 void boost_mpfr_pdf_betadistn (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_betadistn_P (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_betadistn_Q (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_betadistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_betadistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu, mpfr_t nc) ;


 void boost_mpfr_pdf_ndist (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_ndist_P (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_ndist_Q (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_ndist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu, mpfr_t nc) ;
 void boost_mpfr_cdf_ndist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu, mpfr_t nc) ;


 void boost_mpfr_pdf_paretodist (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_paretodist_P (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_paretodist_Q (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_paretodist_Pinv (mpfr_t z, mpfr_t P, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_paretodist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t shape, mpfr_t scale) ;

 
 void boost_mpfr_pdf_poissondist (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_poissondist_P (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_poissondist_Q (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_poissondist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu) ;
 void boost_mpfr_cdf_poissondist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu) ;
 
 
 void boost_mpfr_pdf_rayleighdist (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_rayleighdist_P (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_rayleighdist_Q (mpfr_t z, mpfr_t x, mpfr_t nu);
 void boost_mpfr_cdf_rayleighdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu) ;
 void boost_mpfr_cdf_rayleighdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu) ;


 void boost_mpfr_pdf_tdist (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_tdist_P (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_tdist_Q (mpfr_t z, mpfr_t x, mpfr_t nu) ;
 void boost_mpfr_cdf_tdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu);
 void boost_mpfr_cdf_tdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu) ;


 void boost_mpfr_pdf_triangulardist (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper) ;
 void boost_mpfr_cdf_triangulardist_P (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper) ;
 void boost_mpfr_cdf_triangulardist_Q (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper);
 void boost_mpfr_cdf_triangulardist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lower, mpfr_t mode, mpfr_t upper) ;
 void boost_mpfr_cdf_triangulardist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lower, mpfr_t mode, mpfr_t upper) ;


 void boost_mpfr_pdf_weibulldist (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_weibulldist_P (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_weibulldist_Q (mpfr_t z, mpfr_t x, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_weibulldist_Pinv (mpfr_t z, mpfr_t P, mpfr_t shape, mpfr_t scale) ;
 void boost_mpfr_cdf_weibulldist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t shape, mpfr_t scale) ;


 void boost_mpfr_pdf_uniformdist (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t upper) ;
 void boost_mpfr_cdf_uniformdist_P (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t upper) ;
 void boost_mpfr_cdf_uniformdist_Q (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t upper) ;
 void boost_mpfr_cdf_uniformdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lower, mpfr_t upper) ;
 void boost_mpfr_cdf_uniformdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lower, mpfr_t upper) ;

