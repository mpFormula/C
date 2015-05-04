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


#define BOOST_DLL_IMPORTEXPORT

#if defined (BUILD_BOOST_DLL)
  #undef IMPORTEXPORT
  #define IMPORTEXPORT __declspec( dllexport )
#elif defined (USE_BOOST_DLL)
  #undef IMPORTEXPORT
  #define IMPORTEXPORT __declspec( dllimport )
#endif



#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)
    typedef  long double boost_mp_input;
    typedef  long double * boost_mp_result;
#endif // UseFloat



#if defined (Use_Mpfr) ||  defined (Use_Mpfi)  || defined (Use_Mpq)  || defined (Use_Mpdec) || defined (Use_Arb)

#include "mpfr.h"
    #define boost_mp_input mpfr_t
    #define boost_mp_result mpfr_t
#endif // Use_Mpfr_float_100



#include "mp_constants.h"
#include "libBoostMath_Internal.h"
