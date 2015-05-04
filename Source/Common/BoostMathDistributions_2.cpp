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

//#ifdef Use_LongDouble
//    #define BOOST_RETURN *y = result;
//    typedef long double boost_mp_fixed;
//#endif // Use_LongDouble


#ifdef Use_Mpfr
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
    };  \
    BOOST_RETURN




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


 void boost_skewnormaldist(long Target, boost_mp_result y, boost_mp_input x, boost_mp_input mean, boost_mp_input scale, boost_mp_input shape)
 {
     boost_mp_fixed mean1 = boost_mp_fixed(mean);
     boost_mp_fixed shape1 = boost_mp_fixed(shape);
     boost_mp_fixed scale1 = boost_mp_fixed(scale);
     skew_normal_distribution<boost_mp_fixed>  dist(mean1, scale1, shape1); MP_DIST_RETURN}


