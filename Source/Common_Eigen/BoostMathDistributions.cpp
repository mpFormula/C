/* BoostMathDistributions.cpp: this file is part of the mpFormula Library
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

#pragma GCC diagnostic ignored "-Wmaybe-uninitialized" // Chi-Square and Beta


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
#include <boost/math/distributions.hpp>

using namespace boost::math;


#define MP_DIST_RETURN \
   boost_mp_fixed result = 0; \
    switch (Target){  \
        case mp_const_pdf: { result =  pdf(dist, boost_mp_fixed(x)); break;}  \
        case mp_const_cdf_P: { result =  cdf(dist, boost_mp_fixed(x)); break;}  \
        case mp_const_cdf_Q:  { result =   cdf(complement(dist, boost_mp_fixed(x))); break;}  \
        case mp_const_cdf_Pinv: {result =  quantile(dist, boost_mp_fixed(x)); break;}  \
        case mp_const_cdf_Qinv: {result =  quantile(complement(dist, boost_mp_fixed(x))); break;}  \
    };  \
    BOOST_RETURN



 void boost_bernoulli(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input p)
 {
    boost_mp_fixed p1 = boost_mp_fixed(p);
    bernoulli_distribution<boost_mp_fixed>  dist(p1); MP_DIST_RETURN }


 void boost_betadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input a, boost_mp_input b)
 {
     boost_mp_fixed a1 = boost_mp_fixed(a);
     boost_mp_fixed b1 = boost_mp_fixed(b);
     beta_distribution<boost_mp_fixed> dist(a1, b1); MP_DIST_RETURN}


 void boost_binomialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input n, boost_mp_input p)
 {
     boost_mp_fixed n1 = boost_mp_fixed(n);
     boost_mp_fixed p1 = boost_mp_fixed(p);
     binomial_distribution<boost_mp_fixed> dist(n1, p1); MP_DIST_RETURN}


 void boost_cauchydist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale)
 {
     boost_mp_fixed location1 = boost_mp_fixed(location);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     cauchy_distribution<boost_mp_fixed> dist(location1, scale1); MP_DIST_RETURN}


 void boost_cdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     chi_squared_distribution<boost_mp_fixed> dist(nu1); MP_DIST_RETURN}


 void boost_exponentialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lambda)
 {
     boost_mp_fixed lambda1 = boost_mp_fixed(lambda);
     exponential_distribution<boost_mp_fixed>  dist(lambda1); MP_DIST_RETURN}


 void boost_extreme_valuedist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale)
 {
     boost_mp_fixed location1 = boost_mp_fixed(location);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     extreme_value_distribution<boost_mp_fixed> dist(location1, scale1); MP_DIST_RETURN}


 void boost_fdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mu, boost_mp_input nu)
 {
     boost_mp_fixed mu1 = boost_mp_fixed(mu);
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     fisher_f_distribution<boost_mp_fixed> dist(mu1, nu1); MP_DIST_RETURN}


 void boost_gammadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale)
 {
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     gamma_distribution<boost_mp_fixed> dist(shape1, scale1); MP_DIST_RETURN}


 void boost_hypergeometricdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input r_, boost_mp_input n_, boost_mp_input N_)
 {
   unsigned r = 10;
   unsigned n = 10;
   unsigned N = 10;
   hypergeometric_distribution<boost_mp_fixed> dist(r, n, N); MP_DIST_RETURN}


 void boost_inversechisquareddist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input df, boost_mp_input scale)
 {
     boost_mp_fixed df1 = boost_mp_fixed(df);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     inverse_chi_squared_distribution<boost_mp_fixed> dist(df1, scale1); MP_DIST_RETURN}


 void boost_inversegammadist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale)
 {
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     inverse_gamma_distribution<boost_mp_fixed> dist(shape1, scale1); MP_DIST_RETURN}


 void boost_inversegaussiandist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input scale)
 {
     boost_mp_fixed mean1 = boost_mp_fixed(mean);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     inverse_gaussian_distribution<boost_mp_fixed>  dist(mean1, scale1); MP_DIST_RETURN}


 void boost_laplacedist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale)
 {
     boost_mp_fixed location1 = boost_mp_fixed(location);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     laplace_distribution<boost_mp_fixed> dist(location1, scale1); MP_DIST_RETURN}



 void boost_logisticdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale)
 {
     boost_mp_fixed location1 = boost_mp_fixed(location);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     logistic_distribution<boost_mp_fixed> dist(location1, scale1); MP_DIST_RETURN}


 void boost_lognormaldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input location, boost_mp_input scale)
 {
     boost_mp_fixed location1 = boost_mp_fixed(location);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     lognormal_distribution<boost_mp_fixed> dist(location1, scale1); MP_DIST_RETURN}



 void boost_negative_binomialdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input n, boost_mp_input p)
 {
     boost_mp_fixed n1 = boost_mp_fixed(n);
     boost_mp_fixed p1 = boost_mp_fixed(p);
     negative_binomial_distribution<boost_mp_fixed> dist(n1, p1); MP_DIST_RETURN}


 void boost_cdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu, boost_mp_input nc)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     boost_mp_fixed nc1 = boost_mp_fixed(nc);
     non_central_chi_squared_distribution<boost_mp_fixed> dist(nu1, nc1); MP_DIST_RETURN}


 void boost_tdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu, boost_mp_input nc)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     boost_mp_fixed nc1 = boost_mp_fixed(nc);
     non_central_t_distribution<boost_mp_fixed> dist(nu1, nc1); MP_DIST_RETURN}


 void boost_fdistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mu, boost_mp_input nu, boost_mp_input nc)
 {
     boost_mp_fixed mu1 = boost_mp_fixed(mu);
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     boost_mp_fixed nc1 = boost_mp_fixed(nc);
     non_central_f_distribution<boost_mp_fixed> dist(mu1, nu1, nc1); MP_DIST_RETURN}


 void boost_betadistn(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input a, boost_mp_input b, boost_mp_input nc)
 {
     boost_mp_fixed a1 = boost_mp_fixed(a);
     boost_mp_fixed b1 = boost_mp_fixed(b);
     boost_mp_fixed nc1 = boost_mp_fixed(nc);
     non_central_beta_distribution<boost_mp_fixed> dist(a1, b1, nc1); MP_DIST_RETURN}


 void boost_ndist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input stdev)
 {
     boost_mp_fixed mean1 = boost_mp_fixed(mean);
     boost_mp_fixed stdev1 = boost_mp_fixed(stdev);
     normal_distribution<boost_mp_fixed>  dist(mean1, stdev1); MP_DIST_RETURN}


 void boost_paretodist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale)
 {
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     pareto_distribution<boost_mp_fixed> dist(shape1, scale1); MP_DIST_RETURN}


 void boost_poissondist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     poisson_distribution<boost_mp_fixed> dist(nu1); MP_DIST_RETURN}


 void boost_rayleighdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     rayleigh_distribution<boost_mp_fixed> dist(nu1); MP_DIST_RETURN}


 void boost_skewnormaldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input scale, boost_mp_input shape)
 {
     boost_mp_fixed mean1 = boost_mp_fixed(mean);
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     skew_normal_distribution<boost_mp_fixed>  dist(mean1, scale1, shape1); MP_DIST_RETURN}


 void boost_tdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input nu)
 {
     boost_mp_fixed nu1 = boost_mp_fixed(nu);
     students_t_distribution<boost_mp_fixed> dist(nu1); MP_DIST_RETURN}


 void boost_triangulardist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lower, boost_mp_input mode, boost_mp_input upper)
 {
     boost_mp_fixed lower1 = boost_mp_fixed(lower);
     boost_mp_fixed mode1 = boost_mp_fixed(mode);
     boost_mp_fixed upper1 = boost_mp_fixed(upper);
     triangular_distribution<boost_mp_fixed> dist(lower1, mode1, upper1); MP_DIST_RETURN}


 void boost_weibulldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input shape, boost_mp_input scale)
 {
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     weibull_distribution<boost_mp_fixed> dist(shape1, scale1); MP_DIST_RETURN}


 void boost_uniformdist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input lower, boost_mp_input upper)
 {
     boost_mp_fixed lower1 = boost_mp_fixed(lower);
     boost_mp_fixed upper1 = boost_mp_fixed(upper);
     uniform_distribution<boost_mp_fixed> dist(lower1, upper1); MP_DIST_RETURN}

