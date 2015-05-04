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



#include <boost/math/special_functions.hpp>

using namespace boost::math;



void boost_owens_t(boost_mp_result y, boost_mp_input h, boost_mp_input a)
{
    boost_mp_fixed result =  owens_t(boost_mp_fixed(h), boost_mp_fixed(a));
    BOOST_RETURN
}

