
#include "libEigen.h"
#include "libBoostMath.h"

#if defined (Use_Mpfr) || defined (Use_Mpfi) || defined (Use_Mpq) || defined (Use_Mpdec)
    #include "cxscmpfr.h"
#endif



#define MP_FUNCTION_INIT \
    (*y0).resizeLike(*x0); \
    int r = (long) (*x0).rows(); \
    int c = (long) (*x0).cols();


#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)

#define MP_DIST2_BODY(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { f(Target, &temp, (*x0)(i, j), (*x1)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#define MP_DIST3_BODY(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(Target, &temp, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#define MP_DIST4_BODY(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(Target, &temp, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j), (*x3)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#endif




#if defined (Use_Mpfi) || defined (Use_Mpq) || defined (Use_Mpdec)

#ifdef Use_Mpfi
    #define MP_PTR mpfi_ptr
#endif


#ifdef Use_Mpdec
    #define MP_PTR mpd_ptr
#endif


#ifdef Use_Mpq
    #define MP_PTR mpq_ptr
#endif


#define MP_DIST2_BODY(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR()); \
      f(Target, temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#define MP_DIST3_BODY(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR());  mpfr2::mpreal temp2(((*x2)(i, j)).MP_PTR()); \
      f(Target, temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr(), temp2.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#define MP_DIST4_BODY(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR());  mpfr2::mpreal temp2(((*x2)(i, j)).MP_PTR());  mpfr2::mpreal temp3(((*x3)(i, j)).MP_PTR()); \
      f(Target, temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr(), temp2.mpfr_ptr(), temp3.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#endif



#if defined (Use_Mpfr)
#define MP_PTR mpfr_ptr

#define MP_DIST2_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(Target, ((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR() );} }; break;

#define MP_DIST3_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(Target, ((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR(), ((*x2)(i, j)).MP_PTR() );} }; break;

#define MP_DIST4_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(Target, ((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR(), ((*x2)(i, j)).MP_PTR(), ((*x3)(i, j)).MP_PTR() );} }; break;

#endif


void boost_mpType_DistributionFunctions2(long Dist, long Target, mpMatrix *y0,  mpMatrix *x0,  mpMatrix *x1)
{
    MP_FUNCTION_INIT
    switch (Dist){
    case mp_const_Bernoullidist: { MP_DIST2_BODY(boost_bernoulli);}
    case mp_const_Cdist: { MP_DIST2_BODY(boost_cdist);}
    case mp_const_Exponentialdist: { MP_DIST2_BODY(boost_exponentialdist);}
    case mp_const_Poissondist: { MP_DIST2_BODY(boost_poissondist);}
    case mp_const_Raleighdist: { MP_DIST2_BODY(boost_rayleighdist);}
    case mp_const_Tdist: { MP_DIST2_BODY(boost_tdist);}
    }
}

void boost_mpType_DistributionFunctions3(long Dist, long Target, mpMatrix *y0,  mpMatrix *x0,  mpMatrix *x1,  mpMatrix *x2)
{
    MP_FUNCTION_INIT
    switch (Dist){
        case mp_const_Betadist: { MP_DIST3_BODY(boost_betadist);}
        case mp_const_Binomialdist: { MP_DIST3_BODY(boost_binomialdist);}
        case mp_const_Cauchydist: { MP_DIST3_BODY(boost_cauchydist);}
        case mp_const_Extreme_valuedist: { MP_DIST3_BODY(boost_extreme_valuedist);}
        case mp_const_Fdist: { MP_DIST3_BODY(boost_fdist);}
        case mp_const_Gammadist: { MP_DIST3_BODY(boost_gammadist);}
        case mp_const_Laplacedist: { MP_DIST3_BODY(boost_laplacedist);}
        case mp_const_Logisticdist: { MP_DIST3_BODY(boost_logisticdist);}
        case mp_const_Lognormaldist: { MP_DIST3_BODY(boost_lognormaldist);}
        case mp_const_Negative_binomialdist: { MP_DIST3_BODY(boost_negative_binomialdist);}
        case mp_const_Cdistn: { MP_DIST3_BODY(boost_cdistn);}
        case mp_const_Tdistn: { MP_DIST3_BODY(boost_tdistn);}
        case mp_const_Ndist: { MP_DIST3_BODY(boost_ndist);}
        case mp_const_Paretodist: { MP_DIST3_BODY(boost_paretodist);}
        case mp_const_Weibulldist: { MP_DIST3_BODY(boost_weibulldist);}
        case mp_const_Uniformdist: { MP_DIST3_BODY(boost_uniformdist);}
    }
}

void boost_mpType_DistributionFunctions4(long Dist, long Target, mpMatrix *y0,  mpMatrix *x0,  mpMatrix *x1,  mpMatrix *x2,  mpMatrix *x3)
{
    MP_FUNCTION_INIT
    switch (Dist){
        case mp_const_Hypergeometricdist:  { MP_DIST4_BODY(boost_hypergeometricdist);}
        case mp_const_Fdistn: { MP_DIST4_BODY(boost_fdistn);}
        case mp_const_Betadistn: { MP_DIST4_BODY(boost_betadistn);}
        case mp_const_Triangulardist: { MP_DIST4_BODY(boost_triangulardist);}
    }
}





#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)
#include <cmath>

#define MP_FUNCTION1_BODY_BOOST(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(&temp, (*x0)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;


#define MP_FUNCTION2_BODY_BOOST(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(&temp, (*x0)(i, j), (*x1)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#define MP_FUNCTION3_BODY_BOOST(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(&temp, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#define MP_FUNCTION4_BODY_BOOST(f) \
long double temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(&temp, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j), (*x3)(i, j)); (*y0)(i, j) = (mpType)temp; } }; break;

#endif



#if defined (Use_Mpfr)

#define MP_PTR mpfr_ptr

#define MP_FUNCTION1_BODY_BOOST(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR());} }; break;

#define MP_FUNCTION2_BODY_BOOST(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {f(((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR());} }; break;

#define MP_FUNCTION3_BODY_BOOST(f) \
for (int i = 0; i < r; i++)  {for (int j = 0; j < c; j++) \
  {f(((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR(), ((*x2)(i, j)).MP_PTR());} }; break;

#define MP_FUNCTION4_BODY_BOOST(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)  \
  {f(((*y0)(i, j)).MP_PTR(), ((*x0)(i, j)).MP_PTR(), ((*x1)(i, j)).MP_PTR(), ((*x2)(i, j)).MP_PTR(), ((*x3)(i, j)).MP_PTR());} }; break;

#endif



#if defined (Use_Mpfi) || defined (Use_Mpq) || defined (Use_Mpdec)

#ifdef Use_Mpfi
    #define MP_PTR mpfi_ptr
#endif


#ifdef Use_Mpdec
    #define MP_PTR mpd_ptr
#endif


#ifdef Use_Mpq
    #define MP_PTR mpq_ptr
#endif


#define MP_FUNCTION1_BODY_BOOST(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR());; \
      f(temp.mpfr_ptr(), temp0.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;


#define MP_FUNCTION2_BODY_BOOST(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR()); \
      f(temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#define MP_FUNCTION3_BODY_BOOST(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR());  mpfr2::mpreal temp2(((*x2)(i, j)).MP_PTR()); \
      f(temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr(), temp2.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#define MP_FUNCTION4_BODY_BOOST(f) \
mpfr2::mpreal temp; for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  { mpfr2::mpreal temp0(((*x0)(i, j)).MP_PTR()); mpfr2::mpreal temp1(((*x1)(i, j)).MP_PTR());  mpfr2::mpreal temp2(((*x2)(i, j)).MP_PTR());  mpfr2::mpreal temp3(((*x3)(i, j)).MP_PTR()); \
      f(temp.mpfr_ptr(), temp0.mpfr_ptr(), temp1.mpfr_ptr(), temp2.mpfr_ptr(), temp3.mpfr_ptr()); ((*y0)(i, j)) = temp.mpfr_ptr(); } }; break;

#endif




void boost_mpType_ElementaryFunctions1(long what, mpMatrix *y0, mpMatrix *x0)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Sgn:       { MP_FUNCTION1_BODY_BOOST(boost_sign);}
        case mp_const_Trunc:     { MP_FUNCTION1_BODY_BOOST(boost_trunc);}
        case mp_const_Round:     { MP_FUNCTION1_BODY_BOOST(boost_round);}

        case mp_const_Log1p:     { MP_FUNCTION1_BODY_BOOST(boost_log1p);}
        case mp_const_Expm1:     { MP_FUNCTION1_BODY_BOOST(boost_expm1);}
        case mp_const_Cbrt:      { MP_FUNCTION1_BODY_BOOST(boost_cbrt);}
        case mp_const_Sqrt1pm1:  { MP_FUNCTION1_BODY_BOOST(boost_sqrt1pm1);}
        case mp_const_Sinc_pi:   { MP_FUNCTION1_BODY_BOOST(boost_sinc_pi);}
        case mp_const_Sinhc_pi:  { MP_FUNCTION1_BODY_BOOST(boost_sinhc_pi);}
        case mp_const_Erf:       { MP_FUNCTION1_BODY_BOOST(boost_erf);}
        case mp_const_Erf_inv:   { MP_FUNCTION1_BODY_BOOST(boost_erf_inv);}
        case mp_const_Erfc:      { MP_FUNCTION1_BODY_BOOST(boost_erfc);}
        case mp_const_Erfc_inv:  { MP_FUNCTION1_BODY_BOOST(boost_erfc_inv);}

        case mp_const_Tgamma:      { MP_FUNCTION1_BODY_BOOST(boost_tgamma);}
        case mp_const_LGamma:      { MP_FUNCTION1_BODY_BOOST(boost_lgamma);}
        case mp_const_Tgamma1pm1:  { MP_FUNCTION1_BODY_BOOST(boost_tgamma1pm1);}
        case mp_const_Digamma:     { MP_FUNCTION1_BODY_BOOST(boost_digamma);}
        case mp_const_Factorial:   { MP_FUNCTION1_BODY_BOOST(boost_factorial);}
        case mp_const_Unchecked_Factorial:  { MP_FUNCTION1_BODY_BOOST(boost_unchecked_factorial);}
        case mp_const_Expint_ei:   { MP_FUNCTION1_BODY_BOOST(boost_expint_ei);}
        case mp_const_Zeta:        { MP_FUNCTION1_BODY_BOOST(boost_zeta);}
        case mp_const_Ellint2:     { MP_FUNCTION1_BODY_BOOST(boost_ellint_2_K);}
        case mp_const_Ellint_1_K:  { MP_FUNCTION1_BODY_BOOST(boost_ellint_1_K);}
    }
}


void boost_mpType_ElementaryFunctions2(long what, mpMatrix *y0, mpMatrix *x0,  mpMatrix *x1)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Powm1:          { MP_FUNCTION2_BODY_BOOST(boost_powm1);}
        case mp_const_Hypot:          { MP_FUNCTION2_BODY_BOOST(boost_hypot);}
        case mp_const_Tgamma_ratio:   { MP_FUNCTION2_BODY_BOOST(boost_tgamma_ratio);}
        case mp_const_Tgamma_delta_ratio:     { MP_FUNCTION2_BODY_BOOST(boost_tgamma_delta_ratio);}
        case mp_const_Gamma_p:        { MP_FUNCTION2_BODY_BOOST(boost_gamma_p);}
        case mp_const_Gamma_q:        { MP_FUNCTION2_BODY_BOOST(boost_gamma_q);}
        case mp_const_Tgamma_lower:   { MP_FUNCTION2_BODY_BOOST(boost_tgamma_lower);}
        case mp_const_Tgamma_upper:   { MP_FUNCTION2_BODY_BOOST(boost_tgamma_upper);}
        case mp_const_Gamma_p_inv:    { MP_FUNCTION2_BODY_BOOST(boost_gamma_p_inv);}
        case mp_const_Gamma_q_inv:    { MP_FUNCTION2_BODY_BOOST(boost_gamma_q_inv);}
        case mp_const_Gamma_p_inva:   { MP_FUNCTION2_BODY_BOOST(boost_gamma_p_inva);}
        case mp_const_Gamma_q_inva:   { MP_FUNCTION2_BODY_BOOST(boost_gamma_q_inva);}
        case mp_const_Gamma_p_derivative:     { MP_FUNCTION2_BODY_BOOST(boost_gamma_p_derivative);}
        case mp_const_Legendre_q:     { MP_FUNCTION2_BODY_BOOST(boost_legendre_q);}
        case mp_const_Laguerre:       { MP_FUNCTION2_BODY_BOOST(boost_laguerre);}
        case mp_const_Hermite:        { MP_FUNCTION2_BODY_BOOST(boost_hermite);}
        case mp_const_Rising_Factorial:       { MP_FUNCTION2_BODY_BOOST(boost_rising_factorial);}
        case mp_const_Falling_Factorial:      { MP_FUNCTION2_BODY_BOOST(boost_falling_factorial);}
        case mp_const_Binomial_Coefficient:   { MP_FUNCTION2_BODY_BOOST(boost_binomial_coefficient);}

        case mp_const_Beta:           { MP_FUNCTION2_BODY_BOOST(boost_beta);}
        case mp_const_Expint_n:       { MP_FUNCTION2_BODY_BOOST(boost_expint_n);}
        case mp_const_Ellint_3_K:     { MP_FUNCTION2_BODY_BOOST(boost_ellint_3_K);}
        case mp_const_Ellint_2_F:     { MP_FUNCTION2_BODY_BOOST(boost_ellint_2_F);}
        case mp_const_Ellint_1_F:     { MP_FUNCTION2_BODY_BOOST(boost_ellint_1_F);}
        case mp_const_Ellint_rc:      { MP_FUNCTION2_BODY_BOOST(boost_ellint_rc);}
        case mp_const_Cyl_bessel_j:   { MP_FUNCTION2_BODY_BOOST(boost_cyl_bessel_j);}
        case mp_const_Cyl_neumann:    { MP_FUNCTION2_BODY_BOOST(boost_cyl_neumann);}
        case mp_const_Cyl_bessel_i:   { MP_FUNCTION2_BODY_BOOST(boost_cyl_bessel_i);}
        case mp_const_Cyl_bessel_k:   { MP_FUNCTION2_BODY_BOOST(boost_cyl_bessel_k);}
        case mp_const_Sph_bessel:     { MP_FUNCTION2_BODY_BOOST(boost_sph_bessel);}
        case mp_const_Sph_neumann:    { MP_FUNCTION2_BODY_BOOST(boost_sph_neumann);}
        case mp_const_Legendre_p:     { MP_FUNCTION2_BODY_BOOST(boost_legendre_p);}
    }
}


void boost_mpType_ElementaryFunctions3(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1,  mpMatrix *x2)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Ibeta:            { MP_FUNCTION3_BODY_BOOST(boost_ibeta);}
        case mp_const_Ibetac:           { MP_FUNCTION3_BODY_BOOST(boost_ibetac);}
        case mp_const_IBeta_non_normalized:     { MP_FUNCTION3_BODY_BOOST(boost_ibeta_non_normalized);}
        case mp_const_IBetac_non_normalized:    { MP_FUNCTION3_BODY_BOOST(boost_ibetac_non_normalized);}
        case mp_const_Ibeta_inv:        { MP_FUNCTION3_BODY_BOOST(boost_ibeta_inv);}
        case mp_const_Ibetac_inv:       { MP_FUNCTION3_BODY_BOOST(boost_ibetac_inv);}
        case mp_const_Ibeta_inva:       { MP_FUNCTION3_BODY_BOOST(boost_ibeta_inva);}
        case mp_const_Ibetac_inva:      { MP_FUNCTION3_BODY_BOOST(boost_ibetac_inva);}
        case mp_const_Ibeta_invb:       { MP_FUNCTION3_BODY_BOOST(boost_ibeta_invb);}
        case mp_const_Ibetac_invb:      { MP_FUNCTION3_BODY_BOOST(boost_ibetac_invb);}
        case mp_const_IBeta_derivative: { MP_FUNCTION3_BODY_BOOST(boost_ibeta_derivative);}
        case mp_const_Legendre_p_m:     { MP_FUNCTION3_BODY_BOOST(boost_legendre_p_m);}
        case mp_const_Legendre_m:       { MP_FUNCTION3_BODY_BOOST(boost_laguerre_m);}
        case mp_const_Ellint_rf:        { MP_FUNCTION3_BODY_BOOST(boost_ellint_rf);}
        case mp_const_Ellint_rd:        { MP_FUNCTION3_BODY_BOOST(boost_ellint_rd);}
        case mp_const_Ellint_3_F:       { MP_FUNCTION3_BODY_BOOST(boost_ellint_3_F);}
    }
}



void boost_mpType_ElementaryFunctions4(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2,  mpMatrix *x3)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Ellint_rj:            { MP_FUNCTION4_BODY_BOOST(boost_ellint_rj);}
        case mp_const_Spherical_harmonic_r: { MP_FUNCTION4_BODY_BOOST(boost_spherical_harmonic_r);}
        case mp_const_Spherical_harmonic_i: { MP_FUNCTION4_BODY_BOOST(boost_spherical_harmonic_i);}
        case mp_const_Hermite_next:         { MP_FUNCTION4_BODY_BOOST(boost_hermite_next);}
        case mp_const_Laguerre_next:        { MP_FUNCTION4_BODY_BOOST(boost_laguerre_next);}
        case mp_const_Legendre_next:        { MP_FUNCTION4_BODY_BOOST(boost_legendre_next);}
    }
}





