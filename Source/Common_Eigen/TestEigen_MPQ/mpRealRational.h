/*
    Multi-precision floating point number class for C++.
    Based on gmp library:    http://gmp.org

    Project homepage:    http://www.holoborodko.com/pavel/mpfr
    Contact e-mail:      pavel@holoborodko.com

    Copyright (c) 2008-2012 Pavel Holoborodko

    Contributors:
    Dmitriy Gubanov, Konstantin Holoborodko, Brian Gladman,
    Helmut Jarausch, Fokko Beekhof, Ulrich Mutze, Heinz van Saanen,
    Pere Constans, Peter van Hoof, Gael Guennebaud, Tsai Chia Cheng,
    Alexei Zubanov, Jauhien Piatlicki, Victor Berger, John Westwood.

    ****************************************************************************
    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA

    ****************************************************************************
    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
    notice, this list of conditions and the following disclaimer.

    2. Redistributions in binary form must reproduce the above copyright
    notice, this list of conditions and the following disclaimer in the
    documentation and/or other materials provided with the distribution.

    3. The name of the author may not be used to endorse or promote products
    derived from this software without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
*/

#ifndef __mpRealRational_H__
#define __mpRealRational_H__

#include <string>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <cfloat>
#include <cmath>
#include <limits>

// Options
#define mpRealRational_HAVE_INT64_SUPPORT               // Enable int64_t support if possible. Available only for MSVC 2010 & GCC.
#define mpRealRational_HAVE_MSVC_DEBUGVIEW              // Enable Debugger Visualizer for "Debug" builds in MSVC.

// Detect compiler using signatures from http://predef.sourceforge.net/
#if defined(__GNUC__) && defined(__INTEL_COMPILER)
    #define IsInf(x) isinf(x)                   // Intel ICC compiler on Linux

#elif defined(_MSC_VER)                         // Microsoft Visual C++
    #define IsInf(x) (!_finite(x))

#else
    #define IsInf(x) std::isinf(x)              // GNU C/C++ (and/or other compilers), just hope for C99 conformance
#endif

#if defined(mpRealRational_HAVE_INT64_SUPPORT)

    #define mpq_USE_INTMAX_T                   // Should be defined before mpfi.h

    #if defined(_MSC_VER)                       // MSVC + Windows
        #if (_MSC_VER >= 1600)
            #include <stdint.h>                 // <stdint.h> is available only in msvc2010!

        #else                                   // mpfi relies on intmax_t which is available only in msvc2010
            #undef mpRealRational_HAVE_INT64_SUPPORT    // Besides, mpfi & MPIR have to be compiled with msvc2010
            #undef mpq_USE_INTMAX_T            // Since we cannot detect this, disable x64 by default
                                                // Someone should change this manually if needed.
        #endif

    #elif defined (__GNUC__) && defined(__linux__)
        #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
            #undef mpRealRational_HAVE_INT64_SUPPORT    // Remove all shaman dances for x64 builds since
            #undef mpq_USE_INTMAX_T            // GCC already supports x64 as of "long int" is 64-bit integer, nothing left to do
        #else
            #include <stdint.h>                 // use int64_t, uint64_t otherwise
        #endif

    #else
        #include <stdint.h>                     // rely on int64_t, uint64_t in all other cases, Mac OSX, etc.
    #endif

#endif

#if defined(mpRealRational_HAVE_MSVC_DEBUGVIEW) && defined(_MSC_VER) && defined(_DEBUG)
#define mpRealRational_MSVC_DEBUGVIEW_CODE         DebugView = toString();
    #define mpRealRational_MSVC_DEBUGVIEW_DATA     std::string DebugView;
#else
    #define mpRealRational_MSVC_DEBUGVIEW_CODE
    #define mpRealRational_MSVC_DEBUGVIEW_DATA
#endif

#include <gmp.h>

//#if (MPFR_VERSION < MPFR_VERSION_NUM(3,0,0))
//    #include <cstdlib>                          // Needed for random()
//#endif

// Less important options
#define mpRealRational_DOUBLE_BITS_OVERFLOW -1          // Triggers overflow exception during conversion to double if mpRealRational
                                                // cannot fit in mpRealRational_DOUBLE_BITS_OVERFLOW bits
                                                // = -1 disables overflow checks (default)
#if defined(__GNUC__)
  #define mpRealRational_PERMISSIVE_EXPR __extension__
#else
  #define mpRealRational_PERMISSIVE_EXPR
#endif

namespace mpq {

class mpRealRational {
private:
    mpq_t mp;

public:

    // Get default rounding mode & precision
//    inline static mp_rnd_t   get_default_rnd()    {    return (mp_rnd_t)(mpfr_get_default_rounding_mode());       }
//    inline static mp_prec_t  get_default_prec()   {    return mpfr_get_default_prec();                            }

    // Constructors && type conversions
    mpRealRational();
    mpRealRational(const mpRealRational& u);
    mpRealRational(const mpq_t u);
/* Change DH */
 //   mpRealRational(const mpq_t u);

    mpRealRational(const mpz_t u             );
//    mpRealRational(const mpq_t u             );
    mpRealRational(const double u            );
/* Change DH
    mpRealRational(const long double u,       );
*/
    mpRealRational(const unsigned long int u );
    mpRealRational(const unsigned int u      );
    mpRealRational(const long int u          );
    mpRealRational(const int u               );

#if defined (mpRealRational_HAVE_INT64_SUPPORT)
    mpRealRational(const uint64_t u          );
    mpRealRational(const int64_t u           );
#endif

    mpRealRational(const char* s, int base=10);
    mpRealRational(const std::string& s, int base=10);

    ~mpRealRational();

    // Operations
    // =
    // +, -, *, /, ++, --, <<, >>
    // *=, +=, -=, /=,
    // <, >, ==, <=, >=

    // =
    mpRealRational& operator=(const mpRealRational& v);
//    mpRealRational& operator=(const mpfr_t v);
    mpRealRational& operator=(const mpz_t v);
    mpRealRational& operator=(const mpq_t v);
    mpRealRational& operator=(const long double v);
    mpRealRational& operator=(const double v);
    mpRealRational& operator=(const unsigned long int v);
    mpRealRational& operator=(const unsigned int v);
    mpRealRational& operator=(const long int v);
    mpRealRational& operator=(const int v);
    mpRealRational& operator=(const char* s);
    mpRealRational& operator=(const std::string& s);

    // +
    mpRealRational& operator+=(const mpRealRational& v);
//    mpRealRational& operator+=(const mpfr_t v);
    mpRealRational& operator+=(const mpz_t v);
    mpRealRational& operator+=(const mpq_t v);
    mpRealRational& operator+=(const long double u);
    mpRealRational& operator+=(const double u);
    mpRealRational& operator+=(const unsigned long int u);
    mpRealRational& operator+=(const unsigned int u);
    mpRealRational& operator+=(const long int u);
    mpRealRational& operator+=(const int u);

#if defined (mpRealRational_HAVE_INT64_SUPPORT)
    mpRealRational& operator+=(const int64_t  u);
    mpRealRational& operator+=(const uint64_t u);
    mpRealRational& operator-=(const int64_t  u);
    mpRealRational& operator-=(const uint64_t u);
    mpRealRational& operator*=(const int64_t  u);
    mpRealRational& operator*=(const uint64_t u);
    mpRealRational& operator/=(const int64_t  u);
    mpRealRational& operator/=(const uint64_t u);
#endif

    const mpRealRational operator+() const;
    mpRealRational& operator++ ();
    const mpRealRational  operator++ (int);

    // -
    mpRealRational& operator-=(const mpRealRational& v);
    mpRealRational& operator-=(const mpz_t v);
    mpRealRational& operator-=(const mpq_t v);
    mpRealRational& operator-=(const long double u);
    mpRealRational& operator-=(const double u);
    mpRealRational& operator-=(const unsigned long int u);
    mpRealRational& operator-=(const unsigned int u);
    mpRealRational& operator-=(const long int u);
    mpRealRational& operator-=(const int u);
    const mpRealRational operator-() const;
    friend const mpRealRational operator-(const unsigned long int b, const mpRealRational& a);
    friend const mpRealRational operator-(const unsigned int b,      const mpRealRational& a);
    friend const mpRealRational operator-(const long int b,          const mpRealRational& a);
    friend const mpRealRational operator-(const int b,               const mpRealRational& a);
    friend const mpRealRational operator-(const double b,            const mpRealRational& a);
    mpRealRational& operator-- ();
    const mpRealRational  operator-- (int);

    // *
    mpRealRational& operator*=(const mpRealRational& v);
    mpRealRational& operator*=(const mpz_t v);
    mpRealRational& operator*=(const mpq_t v);
    mpRealRational& operator*=(const long double v);
    mpRealRational& operator*=(const double v);
    mpRealRational& operator*=(const unsigned long int v);
    mpRealRational& operator*=(const unsigned int v);
    mpRealRational& operator*=(const long int v);
    mpRealRational& operator*=(const int v);

    // /
    mpRealRational& operator/=(const mpRealRational& v);
    mpRealRational& operator/=(const mpz_t v);
    mpRealRational& operator/=(const mpq_t v);
    mpRealRational& operator/=(const long double v);
    mpRealRational& operator/=(const double v);
    mpRealRational& operator/=(const unsigned long int v);
    mpRealRational& operator/=(const unsigned int v);
    mpRealRational& operator/=(const long int v);
    mpRealRational& operator/=(const int v);
    friend const mpRealRational operator/(const unsigned long int b, const mpRealRational& a);
    friend const mpRealRational operator/(const unsigned int b,      const mpRealRational& a);
    friend const mpRealRational operator/(const long int b,          const mpRealRational& a);
    friend const mpRealRational operator/(const int b,               const mpRealRational& a);
    friend const mpRealRational operator/(const double b,            const mpRealRational& a);

    //<<= Fast Multiplication by 2^u
    mpRealRational& operator<<=(const unsigned long int u);
    mpRealRational& operator<<=(const unsigned int u);
    mpRealRational& operator<<=(const long int u);
    mpRealRational& operator<<=(const int u);

    //>>= Fast Division by 2^u
    mpRealRational& operator>>=(const unsigned long int u);
    mpRealRational& operator>>=(const unsigned int u);
    mpRealRational& operator>>=(const long int u);
    mpRealRational& operator>>=(const int u);

    // Boolean Operators
    friend bool operator >  (const mpRealRational& a, const mpRealRational& b);
    friend bool operator >= (const mpRealRational& a, const mpRealRational& b);
    friend bool operator <  (const mpRealRational& a, const mpRealRational& b);
    friend bool operator <= (const mpRealRational& a, const mpRealRational& b);
    friend bool operator == (const mpRealRational& a, const mpRealRational& b);
    friend bool operator != (const mpRealRational& a, const mpRealRational& b);

    // Optimized specializations for boolean operators
    friend bool operator == (const mpRealRational& a, const unsigned long int b);
    friend bool operator == (const mpRealRational& a, const unsigned int b);
    friend bool operator == (const mpRealRational& a, const long int b);
    friend bool operator == (const mpRealRational& a, const int b);
    friend bool operator == (const mpRealRational& a, const long double b);
    friend bool operator == (const mpRealRational& a, const double b);

    // Type Conversion operators
    long            toLong      ()    const;
    unsigned long   toULong     ()    const;
    double          toDouble    ()    const;
    long double     toLDouble   ()    const;

#if defined (mpRealRational_HAVE_INT64_SUPPORT)
    int64_t         toInt64     ()    const;
    uint64_t        toUInt64    ()    const;
#endif

    // Get raw pointers so that mpRealRational can be directly used in raw mpq_* functions
    ::mpq_ptr    mpq_ptr();
    ::mpq_srcptr mpq_ptr()    const;
    ::mpq_srcptr mpq_srcptr() const;

    // Convert mpRealRational to string with n significant digits in base b
    // n = 0 -> convert with the maximum available digits
    std::string        toString(int n = 0, int b = 10) const;

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    std::string        toString(const std::string& format) const;
//#endif

    // Math Functions
//    friend const mpRealRational sqr (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sqrt(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sqrt(const unsigned long int v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational cbrt(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational root(const mpRealRational& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const mpRealRational& a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const mpRealRational& a, const mpz_t b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const mpRealRational& a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const mpRealRational& a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const unsigned long int a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational pow (const unsigned long int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational fabs(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());

    friend const mpRealRational abs(const mpRealRational& v);
//    friend const mpRealRational dim(const mpRealRational& a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend inline const mpRealRational mul_2ui(const mpRealRational& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend inline const mpRealRational mul_2si(const mpRealRational& v, long int k, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend inline const mpRealRational div_2ui(const mpRealRational& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend inline const mpRealRational div_2si(const mpRealRational& v, long int k, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend int cmpabs(const mpRealRational& a,const mpRealRational& b);

//    friend const mpRealRational log  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational log2 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational log10(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational exp  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational exp2 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational exp10(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational log1p(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational expm1(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational cos(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sin(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational tan(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sec(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational csc(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational cot(const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend int sin_cos(mpRealRational& s, mpRealRational& c, const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational acos  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational asin  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational atan  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational atan2 (const mpRealRational& y, const mpRealRational& x, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational acot  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational asec  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational acsc  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational cosh  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sinh  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational tanh  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sech  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational csch  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational coth  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational acosh (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational asinh (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational atanh (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational acoth (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational asech (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational acsch (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational hypot (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational fac_ui (unsigned long int v,  mp_prec_t prec = mpRealRational::get_default_prec(), mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational eint   (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    friend const mpRealRational gamma    (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational lngamma  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational lgamma   (const mpRealRational& v, int *signp = 0, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational zeta     (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational erf      (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational erfc     (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational besselj0 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational besselj1 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational besseljn (long n, const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational bessely0 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational bessely1 (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational besselyn (long n, const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational fma      (const mpRealRational& v1, const mpRealRational& v2, const mpRealRational& v3, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational fms      (const mpRealRational& v1, const mpRealRational& v2, const mpRealRational& v3, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational agm      (const mpRealRational& v1, const mpRealRational& v2, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational sum      (const mpRealRational tab[], unsigned long int n, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
    friend int sgn(const mpRealRational& v); // returns -1 or +1

// mpfi 2.4.0 Specifics
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    friend int          sinh_cosh   (mpRealRational& s, mpRealRational& c, const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational li2         (const mpRealRational& v,                       mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational fmod        (const mpRealRational& x, const mpRealRational& y,      mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational rec_sqrt    (const mpRealRational& v,                       mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//    // MATLAB's semantic equivalents
//    friend const mpRealRational rem (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd()); // Remainder after division
//    friend const mpRealRational mod (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd()); // Modulus after division
//#endif

/*
// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend const mpRealRational digamma (const mpRealRational& v,        mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
    friend const mpRealRational ai      (const mpRealRational& v,        mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
    friend const mpRealRational urandom (gmp_randstate_t& state, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());     // use gmp_randinit_default() to init state, gmp_randclear() to clear
#endif
*/
    // Uniformly distributed random number generation in [0,1] using
    // Mersenne-Twister algorithm by default.
    // Use parameter to setup seed, e.g.: random((unsigned)time(NULL))
    // Check urandom() for more precise control.
    friend const mpRealRational random(unsigned int seed = 0);

/*
    // Exponent and mantissa manipulation
    friend const mpRealRational frexp(const mpRealRational& v, mp_exp_t* exp);
    friend const mpRealRational ldexp(const mpRealRational& v, mp_exp_t exp);

    // Splits mpRealRational value into fractional and integer parts.
    // Returns fractional part and stores integer part in n.
    friend const mpRealRational modf(const mpRealRational& v, mpRealRational& n);
*/


    // Constants
    // don't forget to call mpq_free_cache() for every thread where you are using const-functions
//    friend const mpRealRational const_log2      (mp_prec_t prec = mpRealRational::get_default_prec(), mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational const_pi        (mp_prec_t prec = mpRealRational::get_default_prec(), mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational const_euler     (mp_prec_t prec = mpRealRational::get_default_prec(), mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational const_catalan   (mp_prec_t prec = mpRealRational::get_default_prec(), mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());

    // returns +inf iff sign>=0 otherwise -inf
    friend const mpRealRational const_infinity(int sign = 1);

    // Output/ Input
    friend std::ostream& operator<<(std::ostream& os, const mpRealRational& v);
    friend std::istream& operator>>(std::istream& is, mpRealRational& v);

    // Integer Related Functions
//    friend const mpRealRational rint (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational ceil (const mpRealRational& v);
//    friend const mpRealRational floor(const mpRealRational& v);
//    friend const mpRealRational round(const mpRealRational& v);
//    friend const mpRealRational trunc(const mpRealRational& v);
//    friend const mpRealRational rint_ceil   (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational rint_floor  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational rint_round  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational rint_trunc  (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational frac        (const mpRealRational& v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational remainder   (         const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//    friend const mpRealRational remquo      (long* q, const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());

    // Miscellaneous Functions
//    friend const mpRealRational nexttoward (const mpRealRational& x, const mpRealRational& y);
//    friend const mpRealRational nextabove  (const mpRealRational& x);
//    friend const mpRealRational nextbelow  (const mpRealRational& x);

    // use gmp_randinit_default() to init state, gmp_randclear() to clear
    friend const mpRealRational urandomb (gmp_randstate_t& state);

// mpfi < 2.4.2 Specifics
//#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
//    friend const mpRealRational random2 (mp_size_t size, mp_exp_t exp);
//#endif

    // Instance Checkers
    friend bool isnan    (const mpRealRational& v);
    friend bool isinf    (const mpRealRational& v);
    friend bool isfinite (const mpRealRational& v);

    friend bool isnum    (const mpRealRational& v);
    friend bool iszero   (const mpRealRational& v);
    friend bool isint    (const mpRealRational& v);

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
//    friend bool isregular(const mpRealRational& v);
//#endif

    // Set/Get instance properties
//    inline mp_prec_t    get_prec() const;
//    inline void         set_prec(mp_prec_t prec, mp_rnd_t rnd_mode = get_default_rnd());    // Change precision with rounding mode

    // Aliases for get_prec(), set_prec() - needed for compatibility with std::complex<mpRealRational> interface
//    inline mpRealRational&      setPrecision(int Precision, mp_rnd_t RoundingMode = get_default_rnd());
//    inline int          getPrecision() const;

    // Set mpRealRational to +/- inf, NaN, +/-0
    mpRealRational&        setInf  (int Sign = +1);
    mpRealRational&        setNan  ();
    mpRealRational&        setZero (int Sign = +1);
    mpRealRational&        setSign (int Sign);

    //Exponent
//    mp_exp_t get_exp();
//    int set_exp(mp_exp_t e);
//    int check_range  (int t, mp_rnd_t rnd_mode = get_default_rnd());
//    int subnormalize (int t,mp_rnd_t rnd_mode = get_default_rnd());

    // Inexact conversion from float
//    inline bool fits_in_bits(double x, int n);

    // Set/Get global properties
//    static void            set_default_prec(mp_prec_t prec);
//    static void            set_default_rnd(mp_rnd_t rnd_mode);
//
//    static mp_exp_t  get_emin (void);
//    static mp_exp_t  get_emax (void);
//    static mp_exp_t  get_emin_min (void);
//    static mp_exp_t  get_emin_max (void);
//    static mp_exp_t  get_emax_min (void);
//    static mp_exp_t  get_emax_max (void);
//    static int       set_emin (mp_exp_t exp);
//    static int       set_emax (mp_exp_t exp);

    // Efficient swapping of two mpRealRational values - needed for std algorithms
    friend void swap(mpRealRational& x, mpRealRational& y);

    friend const mpRealRational fmax(const mpRealRational& x, const mpRealRational& y);
    friend const mpRealRational fmin(const mpRealRational& x, const mpRealRational& y);

private:
    // Human friendly Debug Preview in Visual Studio.
    // Put one of these lines:
    //
    // mpq::mpRealRational=<DebugView>                                ; Show value only
    // mpq::mpRealRational=<DebugView>, <mp[0]._mpq_prec,u>bits    ; Show value & precision
    //
    // at the beginning of
    // [Visual Studio Installation Folder]\Common7\Packages\Debugger\autoexp.dat
    mpRealRational_MSVC_DEBUGVIEW_DATA
};

//////////////////////////////////////////////////////////////////////////
// Exceptions
class conversion_overflow : public std::exception {
public:
    std::string why() { return "inexact conversion from floating point"; }
};

//////////////////////////////////////////////////////////////////////////
// Constructors & converters
// Default constructor: creates mp number and initializes it to 0.
inline mpRealRational::mpRealRational()
{
    mpq_init(mp);
    mpq_set_ui(mp, 0, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const mpRealRational& u)
{
    mpq_init(mp);
    mpq_set(mp,u.mp);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const mpq_t u)
{
    mpq_init(mp);
    mpq_set(mp,u);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

/* Change DH */
//inline mpRealRational::mpRealRational(const mpfr_t u)
//{
//    mpq_init2(mp,(mp_prec_t) mpfr_get_prec(u)); // (gmp: mp_bitcnt_t) unsigned long -> long (mpfi: mp_prec_t)
//    mpq_set_fr(mp,u);
//
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//}
/* End Change DH */

inline mpRealRational::mpRealRational(const mpz_t u)
{
    mpq_init(mp);
    mpq_set_z(mp,u);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

//inline mpRealRational::mpRealRational(const mpq_t u)
//{
//    mpq_init(mp);
//    mpq_set_q(mp,u);
//
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//}

inline mpRealRational::mpRealRational(const double u)
{
    mpq_init(mp);

//#if (mpRealRational_DOUBLE_BITS_OVERFLOW > -1)
//	if(fits_in_bits(u, mpRealRational_DOUBLE_BITS_OVERFLOW))
//	{
//		mpq_set_d(mp, u);
//	}else
//		throw conversion_overflow();
//#else
	mpq_set_d(mp, u);
//#endif

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

/* Change DH
inline mpRealRational::mpRealRational(const long double u, mp_prec_t prec, mp_rnd_t mode)
{
    mpq_init2(mp,prec);
    mpq_set_ld(mp,u,mode);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}
*/

inline mpRealRational::mpRealRational(const unsigned long int u)
{
    mpq_init(mp);
    mpq_set_ui(mp, u, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const unsigned int u)
{
    mpq_init(mp);
    mpq_set_ui(mp, u, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const long int u)
{
    mpq_init(mp);
    mpq_set_si(mp,u, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const int u)
{
    mpq_init(mp);
    mpq_set_si(mp,u,1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

//#if defined (mpRealRational_HAVE_INT64_SUPPORT)
//inline mpRealRational::mpRealRational(const uint64_t u, mp_prec_t prec, mp_rnd_t mode)
//{
// /* modified by DH */
//    mpfr_t x;
//
//    mpfr_init2(x,prec);
//    mpfr_set_uj(x, u, mode);
//
//
//    mpq_init2(mp,prec);
//    mpq_set_fr(mp, x);
//
//    mpfr_clear(x);
//
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//}

//inline mpRealRational::mpRealRational(const int64_t u, mp_prec_t prec, mp_rnd_t mode)
//{
//    /* modified by DH */
//    mpfr_t x;
//
//    mpfr_init2(x,prec);
//    mpfr_set_sj(x, u, mode);
//
//
//    mpq_init2(mp,prec);
//    mpq_set_fr(mp, x);
//
//    mpfr_clear(x);
//
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//}
//#endif

inline mpRealRational::mpRealRational(const char* s, int base)
{
    mpq_init(mp);
    mpq_set_str(mp, s, base);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::mpRealRational(const std::string& s, int base)
{
    mpq_init(mp);
    mpq_set_str(mp, s.c_str(), base);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
}

inline mpRealRational::~mpRealRational()
{
    mpq_clear(mp);
}

// internal namespace needed for template magic
namespace internal{

    // Use SFINAE to restrict arithmetic operations instantiation only for numeric types
    // This is needed for smooth integration with libraries based on expression templates, like Eigen.
    // TODO: Do the same for boolean operators.
    template <typename ArgumentType> struct result_type {};

    template <> struct result_type<mpRealRational>              {typedef mpRealRational type;};
    template <> struct result_type<mpz_t>               {typedef mpRealRational type;};
    template <> struct result_type<mpq_t>               {typedef mpRealRational type;};
    template <> struct result_type<long double>         {typedef mpRealRational type;};
    template <> struct result_type<double>              {typedef mpRealRational type;};
    template <> struct result_type<unsigned long int>   {typedef mpRealRational type;};
    template <> struct result_type<unsigned int>        {typedef mpRealRational type;};
    template <> struct result_type<long int>            {typedef mpRealRational type;};
    template <> struct result_type<int>                 {typedef mpRealRational type;};

#if defined (mpRealRational_HAVE_INT64_SUPPORT)
    template <> struct result_type<int64_t  >           {typedef mpRealRational type;};
    template <> struct result_type<uint64_t >           {typedef mpRealRational type;};
#endif
}

// + Addition
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator+(const mpRealRational& lhs, const Rhs& rhs){ return mpRealRational(lhs) += rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator+(const Lhs& lhs, const mpRealRational& rhs){ return mpRealRational(rhs) += lhs;    }

// - Subtraction
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator-(const mpRealRational& lhs, const Rhs& rhs){ return mpRealRational(lhs) -= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator-(const Lhs& lhs, const mpRealRational& rhs){ return mpRealRational(lhs) -= rhs;    }

// * Multiplication
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator*(const mpRealRational& lhs, const Rhs& rhs){ return mpRealRational(lhs) *= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator*(const Lhs& lhs, const mpRealRational& rhs){ return mpRealRational(rhs) *= lhs;    }

// / Division
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator/(const mpRealRational& lhs, const Rhs& rhs){ return mpRealRational(lhs) /= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator/(const Lhs& lhs, const mpRealRational& rhs){ return mpRealRational(lhs) /= rhs;    }

//////////////////////////////////////////////////////////////////////////
// sqrt
//const mpRealRational sqrt(const unsigned int v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational sqrt(const long int v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational sqrt(const int v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational sqrt(const long double v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational sqrt(const double v, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());

//////////////////////////////////////////////////////////////////////////
// pow
//const mpRealRational pow(const mpRealRational& a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const mpRealRational& a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const mpRealRational& a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const mpRealRational& a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const unsigned int a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long double a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const double a, const mpRealRational& b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const unsigned long int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned long int a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned long int a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned long int a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned long int a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const unsigned int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned int a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned int a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned int a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const unsigned int a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const long int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long int a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const int a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const long double a, const long double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long double a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long double a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long double a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const long double a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//
//const mpRealRational pow(const double a, const double b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const double a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const double a, const unsigned int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const double a, const long int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());
//const mpRealRational pow(const double a, const int b, mp_rnd_t rnd_mode = mpRealRational::get_default_rnd());

//////////////////////////////////////////////////////////////////////////
// Estimate machine epsilon for the given precision
// Returns smallest eps such that 1.0 + eps != 1.0
inline mpRealRational machine_epsilon();

// Returns smallest eps such that x + eps != x (relative machine epsilon)
inline mpRealRational machine_epsilon(const mpRealRational& x);

// Gives max & min values for the required precision,
// minval is 'safe' meaning 1 / minval does not overflow
// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpRealRational minval();
inline mpRealRational maxval();

// 'Dirty' equality check 1: |a-b| < min{|a|,|b|} * eps
inline bool isEqualFuzzy(const mpRealRational& a, const mpRealRational& b, const mpRealRational& eps);

// 'Dirty' equality check 2: |a-b| < min{|a|,|b|} * eps( min{|a|,|b|} )
inline bool isEqualFuzzy(const mpRealRational& a, const mpRealRational& b);

// 'Bitwise' equality check
//  maxUlps - a and b can be apart by maxUlps binary numbers.
inline bool isEqualUlps(const mpRealRational& a, const mpRealRational& b, int maxUlps);

//////////////////////////////////////////////////////////////////////////
//     Convert precision in 'bits' to decimal digits and vice versa.
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

//inline mp_prec_t digits2bits(int d);
//inline int       bits2digits(mp_prec_t b);

//////////////////////////////////////////////////////////////////////////
// min, max
const mpRealRational (max)(const mpRealRational& x, const mpRealRational& y);
const mpRealRational (min)(const mpRealRational& x, const mpRealRational& y);

//////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Operators - Assignment
inline mpRealRational& mpRealRational::operator=(const mpRealRational& v)
{
    if (this != &v)
    {
//		mp_prec_t tp = mpq_get_prec(mp);
//		mp_prec_t vp = mpq_get_prec(v.mp);
//
//		if(tp != vp){
//			mpq_clear(mp);
//			mpq_init2(mp, vp);
//		}

        mpq_set(mp, v.mp);

        mpRealRational_MSVC_DEBUGVIEW_CODE;
    }
    return *this;
}

//inline mpRealRational& mpRealRational::operator=(const mpfr_t v)
//{
//    mpq_set_fr(mp, v);
//
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::operator=(const mpz_t v)
{
    mpq_set_z(mp, v);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const mpq_t v)
{
    mpq_set(mp, v);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

/* Change DH
inline mpRealRational& mpRealRational::operator=(const long double v)
{
    mpq_set_ld(mp, v);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}
*/

inline mpRealRational& mpRealRational::operator=(const double v)
{
#if (mpRealRational_DOUBLE_BITS_OVERFLOW > -1)
	if(fits_in_bits(v, mpRealRational_DOUBLE_BITS_OVERFLOW))
	{
		mpq_set_d(mp,v);
	}else
		throw conversion_overflow();
#else
	mpq_set_d(mp,v);
#endif

	mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const unsigned long int v)
{
    mpq_set_ui(mp, v, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const unsigned int v)
{
    mpq_set_ui(mp, v, 1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const long int v)
{
    mpq_set_si(mp, v,1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const int v)
{
    mpq_set_si(mp, v,1);

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const char* s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpRealRational(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpRealRational(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.

    mpq_t t;

    mpq_init(t);

    if(0 == mpq_set_str(t, s, 10))
    {
        mpq_set(mp, t);
        mpRealRational_MSVC_DEBUGVIEW_CODE;
    }

    mpq_clear(t);
    return *this;
}

inline mpRealRational& mpRealRational::operator=(const std::string& s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpRealRational(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpRealRational(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.

    mpq_t t;

    mpq_init(t);

    if(0 == mpq_set_str(t, s.c_str(), 10))
    {
        mpq_set(mp, t);
        mpRealRational_MSVC_DEBUGVIEW_CODE;
    }

    mpq_clear(t);
    return *this;
}


//////////////////////////////////////////////////////////////////////////
// + Addition
inline mpRealRational& mpRealRational::operator+=(const mpRealRational& v)
{
    mpq_add(mp,mp,v.mp);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpRealRational& mpRealRational::operator+=(const mpfr_t u)
//{
//    *this += mpRealRational(u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

//inline mpRealRational& mpRealRational::operator+=(const mpz_t u)
//{
//    mpq_add_z(mp,mp,u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::operator+=(const mpq_t u)
{
    mpq_add(mp,mp,u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

/* Change DH
inline mpRealRational& mpRealRational::operator+= (const long double u)
{
    *this += mpRealRational(u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}
*/

inline mpRealRational& mpRealRational::operator+= (const double u)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpq_add_d(mp,mp,u);
//#else
    *this += mpRealRational(u);
//#endif

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator+=(const unsigned long int u)
{
    *this += mpRealRational(u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator+=(const unsigned int u)
{
    *this += mpRealRational(u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator+=(const long int u)
{
    *this += mpRealRational(u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator+=(const int u)
{
    *this += mpRealRational(u);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

#if defined (mpRealRational_HAVE_INT64_SUPPORT)
inline mpRealRational& mpRealRational::operator+=(const int64_t  u){    *this += mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator+=(const uint64_t u){    *this += mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator-=(const int64_t  u){    *this -= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator-=(const uint64_t u){    *this -= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator*=(const int64_t  u){    *this *= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator*=(const uint64_t u){    *this *= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator/=(const int64_t  u){    *this /= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealRational& mpRealRational::operator/=(const uint64_t u){    *this /= mpRealRational(u); mpRealRational_MSVC_DEBUGVIEW_CODE; return *this;    }
#endif

inline const mpRealRational mpRealRational::operator+()const    {    return mpRealRational(*this); }

inline const mpRealRational operator+(const mpRealRational& a, const mpRealRational& b)
{
	mpRealRational c(0);
	mpq_add(c.mpq_ptr(), a.mpq_srcptr(), b.mpq_srcptr());
	return c;
}

inline mpRealRational& mpRealRational::operator++()
{
    return *this += 1;
}

inline const mpRealRational mpRealRational::operator++ (int)
{
    mpRealRational x(*this);
    *this += 1;
    return x;
}

inline mpRealRational& mpRealRational::operator--()
{
    return *this -= 1;
}

inline const mpRealRational mpRealRational::operator-- (int)
{
    mpRealRational x(*this);
    *this -= 1;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// - Subtraction
inline mpRealRational& mpRealRational::operator-=(const mpRealRational& v)
{
    mpq_sub(mp,mp,v.mp);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpRealRational& mpRealRational::operator-=(const mpz_t v)
//{
//    mpq_sub_z(mp,mp,v);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::operator-=(const mpq_t v)
{
    mpq_sub(mp,mp,v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

/* Change DH
inline mpRealRational& mpRealRational::operator-=(const long double v)
{
    *this -= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}
*/

inline mpRealRational& mpRealRational::operator-=(const double v)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpq_sub_d(mp,mp,v);
//#else
    *this -= mpRealRational(v);
//#endif

    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator-=(const unsigned long int v)
{
    *this -= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator-=(const unsigned int v)
{
    *this -= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator-=(const long int v)
{
    *this -= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator-=(const int v)
{
    *this -= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealRational mpRealRational::operator-()const
{
    mpRealRational u(*this);
    mpq_neg(u.mp,u.mp);
    return u;
}

inline const mpRealRational operator-(const mpRealRational& a, const mpRealRational& b)
{
	mpRealRational c(0);
	mpq_sub(c.mpq_ptr(), a.mpq_srcptr(), b.mpq_srcptr());
	return c;
}

inline const mpRealRational operator-(const double  b, const mpRealRational& a)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpRealRational x(0, mpq_get_prec(a.mpq_ptr()));
//    mpq_d_sub(x.mpq_ptr(), b, a.mpq_srcptr());
//    return x;
//#else
    mpRealRational x(b);
    x -= a;
    return x;
//#endif
}

inline const mpRealRational operator-(const unsigned long int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x -= a;
    return x;
}

inline const mpRealRational operator-(const unsigned int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x -= a;
    return x;
}

inline const mpRealRational operator-(const long int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x -= a;
    return x;
}

inline const mpRealRational operator-(const int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x -= a;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// * Multiplication
inline mpRealRational& mpRealRational::operator*= (const mpRealRational& v)
{
    mpq_mul(mp,mp,v.mp);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpRealRational& mpRealRational::operator*=(const mpz_t v)
//{
//    mpq_mul_z(mp,mp,v);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::operator*=(const mpq_t v)
{
    mpq_mul(mp,mp,v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

/* Change DH
inline mpRealRational& mpRealRational::operator*=(const long double v)
{
    *this *= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}
*/

inline mpRealRational& mpRealRational::operator*=(const double v)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpq_mul_d(mp,mp,v);
//#else
    *this *= mpRealRational(v);
//#endif
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator*=(const unsigned long int v)
{
    *this *= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator*=(const unsigned int v)
{
    *this *= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator*=(const long int v)
{
    *this *= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator*=(const int v)
{
    *this *= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealRational operator*(const mpRealRational& a, const mpRealRational& b)
{
	mpRealRational c(0);
	mpq_mul(c.mpq_ptr(), a.mpq_srcptr(), b.mpq_srcptr());
	return c;
}

//////////////////////////////////////////////////////////////////////////
// / Division
inline mpRealRational& mpRealRational::operator/=(const mpRealRational& v)
{
    mpq_div(mp,mp,v.mp);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpRealRational& mpRealRational::operator/=(const mpz_t v)
//{
//    mpq_div_z(mp,mp,v);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::operator/=(const mpq_t v)
{
    mpq_div(mp,mp,v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

/* Change DH
inline mpRealRational& mpRealRational::operator/=(const long double v)
{
    *this /= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}
*/

inline mpRealRational& mpRealRational::operator/=(const double v)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpq_div_d(mp,mp,v);
//#else
    *this /= mpRealRational(v);
//#endif
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator/=(const unsigned long int v)
{
    *this /= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator/=(const unsigned int v)
{
    *this /= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator/=(const long int v)
{
    *this /= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::operator/=(const int v)
{
    *this /= mpRealRational(v);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealRational operator/(const mpRealRational& a, const mpRealRational& b)
{
	mpRealRational c(0);
	mpq_div(c.mpq_ptr(), a.mpq_srcptr(), b.mpq_srcptr());
	return c;
}

inline const mpRealRational operator/(const unsigned long int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x /= a;
    return x;
}

inline const mpRealRational operator/(const unsigned int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x /= a;
    return x;
}

inline const mpRealRational operator/(const long int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x /= a;
    return x;
}

inline const mpRealRational operator/(const int b, const mpRealRational& a)
{
    mpRealRational x(b);
    x /= a;
    return x;
}

inline const mpRealRational operator/(const double  b, const mpRealRational& a)
{
//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//    mpRealRational x(0, mpq_get_prec(a.mpq_ptr()));
//    mpq_d_div(x.mpq_ptr(), b, a.mpq_srcptr());
//    return x;
//#else
    mpRealRational x(b);
    x /= a;
    return x;
//#endif
}

//////////////////////////////////////////////////////////////////////////
// Shifts operators - Multiplication/Division by power of 2
//inline mpRealRational& mpRealRational::operator<<=(const unsigned long int u)
//{
//    mpq_mul_2ui(mp,mp,u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator<<=(const unsigned int u)
//{
//    mpq_mul_2ui(mp,mp,static_cast<unsigned long int>(u));
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator<<=(const long int u)
//{
//    mpq_mul_2si(mp,mp,u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator<<=(const int u)
//{
//    mpq_mul_2si(mp,mp,static_cast<long int>(u));
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator>>=(const unsigned long int u)
//{
//    mpq_div_2ui(mp,mp,u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator>>=(const unsigned int u)
//{
//    mpq_div_2ui(mp,mp,static_cast<unsigned long int>(u));
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator>>=(const long int u)
//{
//    mpq_div_2si(mp,mp,u);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpRealRational& mpRealRational::operator>>=(const int u)
//{
//    mpq_div_2si(mp,mp,static_cast<long int>(u));
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline const mpRealRational operator<<(const mpRealRational& v, const unsigned long int k)
//{
//    return mul_2ui(v,k);
//}
//
//inline const mpRealRational operator<<(const mpRealRational& v, const unsigned int k)
//{
//    return mul_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpRealRational operator<<(const mpRealRational& v, const long int k)
//{
//    return mul_2si(v,k);
//}
//
//inline const mpRealRational operator<<(const mpRealRational& v, const int k)
//{
//    return mul_2si(v,static_cast<long int>(k));
//}
//
//inline const mpRealRational operator>>(const mpRealRational& v, const unsigned long int k)
//{
//    return div_2ui(v,k);
//}
//
//inline const mpRealRational operator>>(const mpRealRational& v, const long int k)
//{
//    return div_2si(v,k);
//}
//
//inline const mpRealRational operator>>(const mpRealRational& v, const unsigned int k)
//{
//    return div_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpRealRational operator>>(const mpRealRational& v, const int k)
//{
//    return div_2si(v,static_cast<long int>(k));
//}

// mul_2ui
//inline const mpRealRational mul_2ui(const mpRealRational& v, unsigned long int k, mp_rnd_t rnd_mode)
//{
//    mpRealRational x(v);
//    mpq_mul_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//// mul_2si
//inline const mpRealRational mul_2si(const mpRealRational& v, long int k, mp_rnd_t rnd_mode)
//{
//    mpRealRational x(v);
//    mpq_mul_2si(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpRealRational div_2ui(const mpRealRational& v, unsigned long int k, mp_rnd_t rnd_mode)
//{
//    mpRealRational x(v);
//    mpq_div_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpRealRational div_2si(const mpRealRational& v, long int k, mp_rnd_t rnd_mode)
//{
//    mpRealRational x(v);
//    mpq_div_2si(x.mp,v.mp,k);
//    return x;
//}

//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////
//Boolean operators
inline bool operator >  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) > 0);
    return result;
}

inline bool operator >=  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) >= 0);
    return result;
}


inline bool operator <  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) < 0);
    return result;
}



inline bool operator <=  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) <= 0);
    return result;
}


inline bool operator ==  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) == 0);
    return result;
}


inline bool operator !=  (const mpRealRational& a, const mpRealRational& b)
{
    bool result = (mpq_cmp(a.mpq_srcptr(), b.mpq_srcptr()) != 0);
    return result;
}



//inline bool operator != (const mpRealRational& a, const mpRealRational& b){    return (mpq_lessgreater_p(a.mp,b.mp)  !=0);    }




inline bool operator == (const mpRealRational& a, const unsigned long int b ){    return (mpq_cmp_ui(a.mp, b, 1) == 0);    }
inline bool operator == (const mpRealRational& a, const unsigned int b      ){    return (mpq_cmp_ui(a.mp,b, 1) == 0);    }
inline bool operator == (const mpRealRational& a, const long int b          ){    return (mpq_cmp_si(a.mp,b, 1) == 0);    }
inline bool operator == (const mpRealRational& a, const int b               ){    return (mpq_cmp_si(a.mp,b, 1) == 0);    }
/* Change DH
inline bool operator == (const mpRealRational& a, const long double b       ){    return (mpq_cmp_ld(a.mp,b) == 0);    }
*/
//inline bool operator == (const mpRealRational& a, const double b            ){    return (mpq_cmp_d(a.mp,b)  == 0);    }
//
//
//inline bool isnan    (const mpRealRational& v){    return (mpq_nan_p(v.mp)     != 0);    }
//inline bool isinf    (const mpRealRational& v){    return (mpq_inf_p(v.mp)     != 0);    }
//inline bool isfinite (const mpRealRational& v){    return (mpq_bounded_p(v.mp)  != 0);    }
//inline bool iszero   (const mpRealRational& v){    return (mpq_is_zero(v.mp)    != 0);    }
/* Change DH
inline bool isint    (const mpRealRational& v){    return (mpq_integer_p(v.mp) != 0);    }
*/

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
/* Change DH
inline bool isregular(const mpRealRational& v){    return (mpq_regular_p(v.mp));}
*/
//#endif

//////////////////////////////////////////////////////////////////////////
// Type Converters
/* Change DH */
//inline long             mpRealRational::toLong   (mp_rnd_t mode)  const    {    return mpq_get_si(mp, mode);    }
//inline unsigned long    mpRealRational::toULong  (mp_rnd_t mode)  const    {    return mpq_get_ui(mp, mode);    }

inline long             mpRealRational::toLong   ()  const    {    return (long) mpq_get_d(mp);    }
inline unsigned long    mpRealRational::toULong  ()  const    {    return (unsigned long) mpq_get_d(mp);    }

inline double           mpRealRational::toDouble ()  const    {    return mpq_get_d (mp);    }
//inline long double      mpRealRational::toLDouble(mp_rnd_t mode)  const    {    return mpq_get_ld(mp);    }
inline long double      mpRealRational::toLDouble()  const    {    return mpq_get_d(mp);    }


#if defined (mpRealRational_HAVE_INT64_SUPPORT)
//inline int64_t      mpRealRational::toInt64 (mp_rnd_t mode)    const{    return mpq_get_sj(mp, mode);    }
//inline uint64_t     mpRealRational::toUInt64(mp_rnd_t mode)    const{    return mpq_get_uj(mp, mode);    }

//inline int64_t      mpRealRational::toInt64 (mp_rnd_t mode)    const{    return (int64_t) mpq_get_d(mp);    }
//inline uint64_t     mpRealRational::toUInt64(mp_rnd_t mode)    const{    return (uint64_t) mpq_get_d(mp);    }

#endif

inline ::mpq_ptr     mpRealRational::mpq_ptr()             { return mp; }
inline ::mpq_srcptr  mpRealRational::mpq_ptr()    const    { return mp; }
inline ::mpq_srcptr  mpRealRational::mpq_srcptr() const    { return mp; }

template <class T>
inline std::string toString(T t, std::ios_base & (*f)(std::ios_base&))
{
    std::ostringstream oss;
    oss << f << t;
    return oss.str();
}

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline std::string mpRealRational::toString(const std::string& format) const
{
    char *sL = NULL;
    std::string outL;
    mpz_t fL;
    mpz_init(fL);
    mpq_get_num(fL, mp);
    if( !format.empty() )
    {
        if(!(gmp_asprintf(&sL,format.c_str(),fL) < 0))
        {
            outL = std::string(sL);

 //           mpfr_free_str(sL);
        }
    }
    char *sR = NULL;
    std::string outR;
    mpz_t fR;
    mpz_init(fR);
    mpq_get_den(fR, mp);
    if( !format.empty() )
    {
        if(!(gmp_asprintf(&sR,format.c_str(),fR) < 0))
        {
            outR = std::string(sR);

 //           mpfr_free_str(sR);
        }
    }
    std::string out = "[" + outL + "/" + outR + "]";
    return out;
}

//#endif

inline std::string mpRealRational::toString(int n, int b) const
{
    (void)b;
//    (void)mode;

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
//
    // Use mpfi native function for output
    char format[128];
    int digits;

//    digits = n > 0 ? n : bits2digits();

    digits = n ;

//    sprintf(format,"%%.%dRNg",digits);        // Default format
    sprintf(format,"%Zd", digits);        // Default format

    return toString(std::string(format));

//#else
//
//    char *s, *ns = NULL;
//    size_t slen, nslen;
//    mp_exp_t exp;
//    std::string out;
//
//    if(mpq_inf_p(mp))
//    {
//        if(mpq_sgn(mp)>0) return "+Inf";
//        else               return "-Inf";
//    }
//
//    if(mpq_zero_p(mp)) return "0";
//    if(mpq_nan_p(mp))  return "NaN";
//
//    s  = mpq_get_str(NULL,&exp,b,0,mp,mode);
//    ns = mpq_get_str(NULL,&exp,b,n,mp,mode);
//
//    if(s!=NULL && ns!=NULL)
//    {
//        slen  = strlen(s);
//        nslen = strlen(ns);
//        if(nslen<=slen)
//        {
//            mpq_free_str(s);
//            s = ns;
//            slen = nslen;
//        }
//        else {
//            mpq_free_str(ns);
//        }
//
//        // Make human eye-friendly formatting if possible
//        if (exp>0 && static_cast<size_t>(exp)<slen)
//        {
//            if(s[0]=='-')
//            {
//                // Remove zeros starting from right end
//                char* ptr = s+slen-1;
//                while (*ptr=='0' && ptr>s+exp) ptr--;
//
//                if(ptr==s+exp) out = std::string(s,exp+1);
//                else           out = std::string(s,exp+1)+'.'+std::string(s+exp+1,ptr-(s+exp+1)+1);
//
//                //out = string(s,exp+1)+'.'+string(s+exp+1);
//            }
//            else
//            {
//                // Remove zeros starting from right end
//                char* ptr = s+slen-1;
//                while (*ptr=='0' && ptr>s+exp-1) ptr--;
//
//                if(ptr==s+exp-1) out = std::string(s,exp);
//                else             out = std::string(s,exp)+'.'+std::string(s+exp,ptr-(s+exp)+1);
//
//                //out = string(s,exp)+'.'+string(s+exp);
//            }
//
//        }else{ // exp<0 || exp>slen
//            if(s[0]=='-')
//            {
//                // Remove zeros starting from right end
//                char* ptr = s+slen-1;
//                while (*ptr=='0' && ptr>s+1) ptr--;
//
//                if(ptr==s+1) out = std::string(s,2);
//                else         out = std::string(s,2)+'.'+std::string(s+2,ptr-(s+2)+1);
//
//                //out = string(s,2)+'.'+string(s+2);
//            }
//            else
//            {
//                // Remove zeros starting from right end
//                char* ptr = s+slen-1;
//                while (*ptr=='0' && ptr>s) ptr--;
//
//                if(ptr==s) out = std::string(s,1);
//                else       out = std::string(s,1)+'.'+std::string(s+1,ptr-(s+1)+1);
//
//                //out = string(s,1)+'.'+string(s+1);
//            }
//
//            // Make final string
//            if(--exp)
//            {
//                if(exp>0) out += "e+"+mpq::toString<mp_exp_t>(exp,std::dec);
//                else       out += "e"+mpq::toString<mp_exp_t>(exp,std::dec);
//            }
//        }
//
//        mpq_free_str(s);
//        return out;
//    }else{
//        return "conversion error!";
//    }
//#endif
}


//////////////////////////////////////////////////////////////////////////
// I/O
inline std::ostream& operator<<(std::ostream& os, const mpRealRational& v)
{
    return os<<v.toString(static_cast<int>(os.precision()));
}

inline std::istream& operator>>(std::istream &is, mpRealRational& v)
{
    // ToDo, use cout::hexfloat and other flags to setup base
    std::string tmp;
    is >> tmp;
    mpq_set_str(v.mp, tmp.c_str(), 10);
    return is;
}

//////////////////////////////////////////////////////////////////////////
//     Bits - decimal digits relation
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

//inline mp_prec_t digits2bits(int d)
//{
//    const double LOG2_10 = 3.3219280948873624;
//
//    return (mp_prec_t) std::ceil( d * LOG2_10 );
//}
//
//inline int bits2digits(mp_prec_t b)
//{
//    const double LOG10_2 = 0.30102999566398119;
//
//    return (int) std::floor( b * LOG10_2 );
//}

//////////////////////////////////////////////////////////////////////////
// Set/Get number properties
//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////

inline int sgn(const mpRealRational& v)
{
    return mpq_sgn(v.mpq_srcptr());
}

inline mpRealRational& mpRealRational::setSign(int sign)
{
    /* Change DH
    mpq_setsign(mp,mp,(sign < 0 ? 1 : 0),RoundingMode);
    */
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline int mpRealRational::getPrecision() const
//{
//    return mpq_get_prec(mp);
//}
//
//inline mpRealRational& mpRealRational::setPrecision(int Precision, mp_rnd_t RoundingMode)
//{
//    /* Change DH
//    mpq_prec_round(mp, Precision, RoundingMode);
//    */
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpRealRational& mpRealRational::setInf(int sign)
{
    /* Change DH
    mpq_set_inf(mp,sign);
    */
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational& mpRealRational::setNan()
{
    /* Change DH
    mpq_set_nan(mp);
    */
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealRational&    mpRealRational::setZero(int sign)
{
    /* Change DH
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    mpq_set_zero(mp, sign);
#else
    mpq_set_si(mp, 0, (mpq_get_default_rounding_mode)());
    setSign(sign);
#endif
*/
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mp_prec_t mpRealRational::get_prec() const
//{
//    return mpq_get_prec(mp);
//}
//
//inline void mpRealRational::set_prec(mp_prec_t prec, mp_rnd_t rnd_mode)
//{
//    /* Change DH */
//    mpq_set_prec(mp,prec);
//    mpRealRational_MSVC_DEBUGVIEW_CODE;
//}

/* Change DH
inline mp_exp_t mpRealRational::get_exp ()
{
    return mpq_get_exp(mp);
}

inline int mpRealRational::set_exp (mp_exp_t e)
{
    int x = mpq_set_exp(mp, e);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return x;
}

inline const mpRealRational frexp(const mpRealRational& v, mp_exp_t* exp)
{
    mpRealRational x(v);
    *exp = x.get_exp();
    x.set_exp(0);
    return x;
}

inline const mpRealRational ldexp(const mpRealRational& v, mp_exp_t exp)
{
    mpRealRational x(v);

    // rounding is not important since we just increasing the exponent
    mpq_mul_2si(x.mp,x.mp,exp);
    return x;
}
*/

inline mpRealRational machine_epsilon()
{
    /* the smallest eps such that 1 + eps != 1 */
    return mpRealRational("1.0E-1000");
}

inline mpRealRational machine_epsilon(const mpRealRational& x)
{
    /* the smallest eps such that x + eps != x */
    return mpRealRational("1.0E-1000");
}


// minval is 'safe' meaning 1 / minval does not overflow
inline mpRealRational minval()
{
    /* min = 1/2 * 2^emin = 2^(emin - 1) */
    //return mpRealRational(1, prec) << mpRealRational::get_emin()-1;
    return mpRealRational("1.0E-1000");
}

// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpRealRational maxval()
{
    /* max = (1 - eps) * 2^emax, eps is machine epsilon */
    //return (mpRealRational(1, prec) - machine_epsilon(prec)) << mpRealRational::get_emax();
    return mpRealRational("1.0E+1000");
}

inline bool isEqualUlps(const mpRealRational& a, const mpRealRational& b, int maxUlps)
{
  return abs(a - b) <= machine_epsilon((max)(abs(a), abs(b))) * maxUlps;
}

inline bool isEqualFuzzy(const mpRealRational& a, const mpRealRational& b, const mpRealRational& eps)
{
    return abs(a - b) <= (min)(abs(a), abs(b)) * eps;
}

inline bool isEqualFuzzy(const mpRealRational& a, const mpRealRational& b)
{
    return isEqualFuzzy(a, b, machine_epsilon((min)(abs(a), abs(b))));
}

/*
inline const mpRealRational modf(const mpRealRational& v, mpRealRational& n)
{
    mpRealRational frac(v);

    // rounding is not important since we are using the same number
    mpq_frac(frac.mp,frac.mp);
    mpq_trunc(n.mp,v.mp);
    return frac;
}

inline int mpRealRational::check_range (int t, mp_rnd_t rnd_mode)
{
    return mpq_check_range(mp,t,rnd_mode);
}

inline int mpRealRational::subnormalize (int t,mp_rnd_t rnd_mode)
{
    int r = mpq_subnormalize(mp,t,rnd_mode);
    mpRealRational_MSVC_DEBUGVIEW_CODE;
    return r;
}

inline mp_exp_t mpRealRational::get_emin (void)
{
    return mpq_get_emin();
}

inline int mpRealRational::set_emin (mp_exp_t exp)
{
    return mpq_set_emin(exp);
}

inline mp_exp_t mpRealRational::get_emax (void)
{
    return mpq_get_emax();
}

inline int mpRealRational::set_emax (mp_exp_t exp)
{
    return mpq_set_emax(exp);
}

inline mp_exp_t mpRealRational::get_emin_min (void)
{
    return mpq_get_emin_min();
}

inline mp_exp_t mpRealRational::get_emin_max (void)
{
    return mpq_get_emin_max();
}

inline mp_exp_t mpRealRational::get_emax_min (void)
{
    return mpq_get_emax_min();
}

inline mp_exp_t mpRealRational::get_emax_max (void)
{
    return mpq_get_emax_max();
}
*/
//////////////////////////////////////////////////////////////////////////
// Mathematical Functions
//////////////////////////////////////////////////////////////////////////

/* DH Change
#define mpRealRational_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpRealRational y(0, mpq_get_prec(x.mpq_srcptr()));          \
        mpq_##f(y.mpq_ptr(), x.mpq_srcptr(), r);           \
        return y;
*/
#define mpRealRational_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpRealRational y(0);          \
        mpq_##f(y.mpq_ptr(), x.mpq_srcptr());           \
        return y;


//inline const mpRealRational sqr  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sqr );    }
//inline const mpRealRational sqrt (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sqrt);    }

/* DH Change
inline const mpRealRational sqrt(const unsigned long int x, mp_rnd_t r)
{
    mpRealRational y;
    mpq_sqrt_ui(y.mpq_ptr(), x, r);
    return y;
}


inline const mpRealRational sqrt(const unsigned int v, mp_rnd_t rnd_mode)
{
    return sqrt(static_cast<unsigned long int>(v),rnd_mode);
}

inline const mpRealRational sqrt(const long int v, mp_rnd_t rnd_mode)
{
    if (v>=0)   return sqrt(static_cast<unsigned long int>(v),rnd_mode);
    else        return mpRealRational().setNan(); // NaN
}

inline const mpRealRational sqrt(const int v, mp_rnd_t rnd_mode)
{
    if (v>=0)   return sqrt(static_cast<unsigned long int>(v),rnd_mode);
    else        return mpRealRational().setNan(); // NaN
}


inline const mpRealRational root(const mpRealRational& x, unsigned long int k, mp_rnd_t r)
{
    mpRealRational y(0, mpq_get_prec(x.mpq_srcptr()));
    mpq_root(y.mpq_ptr(), x.mpq_srcptr(), k, r);
    return y;
}

inline const mpRealRational dim(const mpRealRational& a, const mpRealRational& b, mp_rnd_t r)
{
    mpRealRational y(0, mpq_get_prec(a.mpq_srcptr()));
    mpq_dim(y.mpq_ptr(), a.mpq_srcptr(), b.mpq_srcptr(), r);
    return y;
}



inline int cmpabs(const mpRealRational& a,const mpRealRational& b)
{
    return mpq_cmpabs(a.mp,b.mp);
}

inline int sin_cos(mpRealRational& s, mpRealRational& c, const mpRealRational& v, mp_rnd_t rnd_mode)
{
    return mpq_sin_cos(s.mp,c.mp,v.mp,rnd_mode);
}

inline const mpRealRational sqrt  (const long double v, mp_rnd_t rnd_mode)    {   return sqrt(mpRealRational(v),rnd_mode);    }
inline const mpRealRational sqrt  (const double v, mp_rnd_t rnd_mode)         {   return sqrt(mpRealRational(v),rnd_mode);    }
*/

//inline const mpRealRational cbrt  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(cbrt );    }
//inline const mpRealRational fabs  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(abs  );    }
inline const mpRealRational abs   (const mpRealRational& x) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(abs  );    }
//inline const mpRealRational log   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(log  );    }
//inline const mpRealRational log2  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(log2 );    }
//inline const mpRealRational log10 (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(log10);    }
//inline const mpRealRational exp   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(exp  );    }
//inline const mpRealRational exp2  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(exp2 );    }
//inline const mpRealRational exp10 (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(exp10);    }
//inline const mpRealRational cos   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(cos  );    }
//inline const mpRealRational sin   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sin  );    }
//inline const mpRealRational tan   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(tan  );    }
//inline const mpRealRational sec   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sec  );    }
//inline const mpRealRational csc   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(csc  );    }
//inline const mpRealRational cot   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(cot  );    }
//inline const mpRealRational acos  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(acos);     }
//inline const mpRealRational asin  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(asin);     }
//inline const mpRealRational atan  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(atan);     }
//
//inline const mpRealRational acot  (const mpRealRational& v, mp_rnd_t r) {   return atan (1/v, r);                      }
//inline const mpRealRational asec  (const mpRealRational& v, mp_rnd_t r) {   return acos (1/v, r);                      }
//inline const mpRealRational acsc  (const mpRealRational& v, mp_rnd_t r) {   return asin (1/v, r);                      }
//inline const mpRealRational acoth (const mpRealRational& v, mp_rnd_t r) {   return atanh(1/v, r);                      }
//inline const mpRealRational asech (const mpRealRational& v, mp_rnd_t r) {   return acosh(1/v, r);                      }
//inline const mpRealRational acsch (const mpRealRational& v, mp_rnd_t r) {   return asinh(1/v, r);                      }
//
//inline const mpRealRational cosh  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(cosh );    }
//inline const mpRealRational sinh  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sinh );    }
//inline const mpRealRational tanh  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(tanh );    }
//inline const mpRealRational sech  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(sech );    }
//inline const mpRealRational csch  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(csch );    }
//inline const mpRealRational coth  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(coth );    }
//inline const mpRealRational acosh (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(acosh);    }
//inline const mpRealRational asinh (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(asinh);    }
//inline const mpRealRational atanh (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(atanh);    }
//
//inline const mpRealRational log1p   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(log1p  );    }
//inline const mpRealRational expm1   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(expm1  );    }
/* Change DH
inline const mpRealRational eint    (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(eint   );    }
inline const mpRealRational gamma   (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(gamma  );    }
inline const mpRealRational lngamma (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(lngamma);    }
inline const mpRealRational zeta    (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(zeta   );    }
inline const mpRealRational erf     (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(erf    );    }
inline const mpRealRational erfc    (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(erfc   );    }
inline const mpRealRational besselj0(const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(j0     );    }
inline const mpRealRational besselj1(const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(j1     );    }
inline const mpRealRational bessely0(const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(y0     );    }
inline const mpRealRational bessely1(const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(y1     );    }
*/
//inline const mpRealRational atan2 (const mpRealRational& y, const mpRealRational& x, mp_rnd_t rnd_mode)
//{
//    mpRealRational a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    mpq_atan2(a.mp, y.mp, x.mp);
//
//    return a;
//}
//
//inline const mpRealRational hypot (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
//{
//    mpRealRational a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    mpq_hypot(a.mp, x.mp, y.mp);
//
//    return a;
//}
//
/* Change DH
inline const mpRealRational remainder (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpq_remainder(a.mp, x.mp, y.mp, rnd_mode);

    return a;
}

inline const mpRealRational remquo (long* q, const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpq_remquo(a.mp,q, x.mp, y.mp, rnd_mode);

    return a;
}

inline const mpRealRational fac_ui (unsigned long int v, mp_prec_t prec, mp_rnd_t rnd_mode)
{
    mpRealRational x(0, prec);
    mpq_fac_ui(x.mp,v,rnd_mode);
    return x;
}


inline const mpRealRational lgamma (const mpRealRational& v, int *signp, mp_rnd_t rnd_mode)
{
    mpRealRational x(v);
    int tsignp;

    if(signp)   mpq_lgamma(x.mp,signp,v.mp,rnd_mode);
    else        mpq_lgamma(x.mp,&tsignp,v.mp,rnd_mode);

    return x;
}


inline const mpRealRational besseljn (long n, const mpRealRational& x, mp_rnd_t r)
{
    mpRealRational  y(0, mpq_get_prec(x.mpq_srcptr()));
    mpq_jn(y.mpq_ptr(), n, x.mpq_srcptr(), r);
    return y;
}

inline const mpRealRational besselyn (long n, const mpRealRational& x, mp_rnd_t r)
{
    mpRealRational  y(0, mpq_get_prec(x.mpq_srcptr()));
    mpq_yn(y.mpq_ptr(), n, x.mpq_srcptr(), r);
    return y;
}

inline const mpRealRational fma (const mpRealRational& v1, const mpRealRational& v2, const mpRealRational& v3, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t p1, p2, p3;

    p1 = v1.get_prec();
    p2 = v2.get_prec();
    p3 = v3.get_prec();

    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));

    mpq_fma(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
    return a;
}

inline const mpRealRational fms (const mpRealRational& v1, const mpRealRational& v2, const mpRealRational& v3, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t p1, p2, p3;

    p1 = v1.get_prec();
    p2 = v2.get_prec();
    p3 = v3.get_prec();

    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));

    mpq_fms(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
    return a;
}

inline const mpRealRational agm (const mpRealRational& v1, const mpRealRational& v2, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t p1, p2;

    p1 = v1.get_prec();
    p2 = v2.get_prec();

    a.set_prec(p1>p2?p1:p2);

    mpq_agm(a.mp, v1.mp, v2.mp, rnd_mode);

    return a;
}

inline const mpRealRational sum (const mpRealRational tab[], unsigned long int n, mp_rnd_t rnd_mode)
{
    mpRealRational x;
    mpq_ptr* t;
    unsigned long int i;

    t = new mpq_ptr[n];
    for (i=0;i<n;i++) t[i] = (mpq_ptr)tab[i].mp;
    mpq_sum(x.mp,t,n,rnd_mode);
    delete[] t;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// mpfi 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline int sinh_cosh(mpRealRational& s, mpRealRational& c, const mpRealRational& v, mp_rnd_t rnd_mode)
{
    return mpq_sinh_cosh(s.mp,c.mp,v.mp,rnd_mode);
}

inline const mpRealRational li2 (const mpRealRational& x, mp_rnd_t r)
{
    mpRealRational_UNARY_MATH_FUNCTION_BODY(li2);
}


inline const mpRealRational rem (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    //  R = rem(X,Y) if Y != 0, returns X - n * Y where n = trunc(X/Y).
    return fmod(x, y, rnd_mode);
}

inline const mpRealRational mod (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    (void)rnd_mode;



//    m = mod(x,y) if y != 0, returns x - n*y where n = floor(x/y)
//
//    The following are true by convention:
//    - mod(x,0) is x
//    - mod(x,x) is 0
//    - mod(x,y) for x != y and y != 0 has the same sign as y.



    if(iszero(y)) return x;
    if(x == y) return 0;

    mpRealRational m = x - floor(x / y) * y;

    m.setSign(sgn(y)); // make sure result has the same sign as Y

    return m;
}

inline const mpRealRational fmod (const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpq_fmod(a.mp, x.mp, y.mp, rnd_mode);

    return a;
}

inline const mpRealRational rec_sqrt(const mpRealRational& v, mp_rnd_t rnd_mode)
{
    mpRealRational x(v);
    mpq_rec_sqrt(x.mp,v.mp,rnd_mode);
    return x;
}
#endif //  mpfi 2.4.0 Specifics



//////////////////////////////////////////////////////////////////////////
// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
inline const mpRealRational digamma (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(digamma);     }
inline const mpRealRational ai      (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(ai);          }
#endif // mpfi 3.0.0 Specifics

//////////////////////////////////////////////////////////////////////////


*/

// Constants
//inline const mpRealRational const_log2 (mp_prec_t p, mp_rnd_t r)
//{
//    mpRealRational x(0, p);
//    mpq_const_log2(x.mpq_ptr());
//    return x;
//}
//
//inline const mpRealRational const_pi (mp_prec_t p, mp_rnd_t r)
//{
//    mpRealRational x(0, p);
//    mpq_const_pi(x.mpq_ptr());
//    return x;
//}
//
//inline const mpRealRational const_euler (mp_prec_t p, mp_rnd_t r)
//{
//    mpRealRational x(0, p);
//    mpq_const_euler(x.mpq_ptr());
//    return x;
//}
//
//inline const mpRealRational const_catalan (mp_prec_t p, mp_rnd_t r)
//{
//    mpRealRational x(0, p);
//    mpq_const_catalan(x.mpq_ptr());
//    return x;
//}
//
///* Change DH */
//inline const mpRealRational const_infinity (int sign, mp_prec_t p, mp_rnd_t)
//{
//    mpRealRational x(0, p);
//    mpfr_t f;
//    mpfr_init(f);
//    mpfr_set_inf(f, sign);
//    mpq_set_fr(x.mpq_ptr(), f);
//    mpfr_clear(f);
//    return x;
//}

/* Change DH
//////////////////////////////////////////////////////////////////////////
// Integer Related Functions
inline const mpRealRational ceil(const mpRealRational& v)
{
    mpRealRational x(v);
    mpq_ceil(x.mp,v.mp);
    return x;
}

inline const mpRealRational floor(const mpRealRational& v)
{
    mpRealRational x(v);
    mpq_floor(x.mp,v.mp);
    return x;
}

inline const mpRealRational round(const mpRealRational& v)
{
    mpRealRational x(v);
    mpq_round(x.mp,v.mp);
    return x;
}

inline const mpRealRational trunc(const mpRealRational& v)
{
    mpRealRational x(v);
    mpq_trunc(x.mp,v.mp);
    return x;
}

inline const mpRealRational rint       (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(rint      );     }
inline const mpRealRational rint_ceil  (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(rint_ceil );     }
inline const mpRealRational rint_floor (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(rint_floor);     }
inline const mpRealRational rint_round (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(rint_round);     }
inline const mpRealRational rint_trunc (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(rint_trunc);     }
inline const mpRealRational frac       (const mpRealRational& x, mp_rnd_t r) {   mpRealRational_UNARY_MATH_FUNCTION_BODY(frac      );     }

//////////////////////////////////////////////////////////////////////////
// Miscellaneous Functions
inline void         swap (mpRealRational& a, mpRealRational& b)            {    mpq_swap(a.mp,b.mp);   }
inline const mpRealRational (max)(const mpRealRational& x, const mpRealRational& y){    return (x>y?x:y);       }
inline const mpRealRational (min)(const mpRealRational& x, const mpRealRational& y){    return (x<y?x:y);       }

inline const mpRealRational fmax(const mpRealRational& x, const mpRealRational& y, mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mpq_max(a.mp,x.mp,y.mp,rnd_mode);
    return a;
}

inline const mpRealRational fmin(const mpRealRational& x, const mpRealRational& y,  mp_rnd_t rnd_mode)
{
    mpRealRational a;
    mpq_min(a.mp,x.mp,y.mp,rnd_mode);
    return a;
}

inline const mpRealRational nexttoward (const mpRealRational& x, const mpRealRational& y)
{
    mpRealRational a(x);
    mpq_nexttoward(a.mp,y.mp);
    return a;
}

inline const mpRealRational nextabove  (const mpRealRational& x)
{
    mpRealRational a(x);
    mpq_nextabove(a.mp);
    return a;
}

inline const mpRealRational nextbelow  (const mpRealRational& x)
{
    mpRealRational a(x);
    mpq_nextbelow(a.mp);
    return a;
}

*/
inline const mpRealRational urandomb (gmp_randstate_t& state)
{
    mpRealRational x;
    mpz_t f;
    mpz_init(f);
    mpz_urandomb(f,state, 100);
    x = f;
    mpz_clear(f);
    return x;
}

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
// use gmp_randinit_default() to init state, gmp_randclear() to clear
inline const mpRealRational urandom (gmp_randstate_t& state)
{
    mpRealRational x;
    mpz_t f;
    mpz_init(f);
    mpz_rrandomb(f,state,100);
    x = f;
    mpz_clear(f);
    return x;
}
//#endif

//#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
//inline const mpRealRational random2 (mp_size_t size, mp_exp_t exp)
//{
//    mpRealRational x;
//    mpq_random2(x.mp,size,exp);
//    return x;
//}
//#endif

// Uniformly distributed random number generation
// a = random(seed); <- initialization & first random number generation
// a = random();     <- next random numbers generation
// seed != 0
inline const mpRealRational random(unsigned int seed)
{

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    static gmp_randstate_t state;
    static bool isFirstTime = true;

    if(isFirstTime)
    {
        gmp_randinit_default(state);
        gmp_randseed_ui(state,0);
        isFirstTime = false;
    }

    if(seed != 0)    gmp_randseed_ui(state,seed);

    return mpq::urandom(state);
//#else
//    if(seed != 0)    std::srand(seed);
//    return mpq::mpRealRational(std::rand()/(double)RAND_MAX);
//#endif

}
/*


//////////////////////////////////////////////////////////////////////////
// Set/Get global properties
inline void mpRealRational::set_default_prec(mp_prec_t prec)
{
    mpfr_set_default_prec(prec);
}

inline void mpRealRational::set_default_rnd(mp_rnd_t rnd_mode)
{
    mpfr_set_default_rounding_mode(rnd_mode);
}

inline bool mpRealRational::fits_in_bits(double x, int n)
{
    int i;
    double t;
    return IsInf(x) || (std::modf ( std::ldexp ( std::frexp ( x, &i ), n ), &t ) == 0.0);
}
*/
//inline const mpRealRational pow(const mpRealRational& a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    /*Change DH */
//    mpRealRational x(a);
////    mpq_pow(x.mp,x.mp,b.mp,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const mpRealRational& a, const mpz_t b, mp_rnd_t rnd_mode)
//{
//    /*Change DH */
//    mpRealRational x(a);
////    mpq_pow(x.mp,x.mp,b.mp,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const mpRealRational& a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//       /*Change DH */
//    mpRealRational x(a);
////    mpq_pow_ui(x.mp,x.mp,b,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const mpRealRational& a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    return pow(a,static_cast<unsigned long int>(b),rnd_mode);
//}
//
//inline const mpRealRational pow(const mpRealRational& a, const long int b, mp_rnd_t rnd_mode)
//{
//       /*Change DH */
//    mpRealRational x(a);
////    mpq_pow_si(x.mp,x.mp,b,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const mpRealRational& a, const int b, mp_rnd_t rnd_mode)
//{
//    return pow(a,static_cast<long int>(b),rnd_mode);
//}
//
///*Change DH
//inline const mpRealRational pow(const mpRealRational& a, const long double b, mp_rnd_t rnd_mode)
//{
//    return pow(a,mpRealRational(b),rnd_mode);
//}
//*/
//
//
//inline const mpRealRational pow(const mpRealRational& a, const double b, mp_rnd_t rnd_mode)
//{
//    return pow(a,mpRealRational(b),rnd_mode);
//}
//
//inline const mpRealRational pow(const unsigned long int a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//       /*Change DH */
//    mpRealRational x(a);
////    mpq_ui_pow(x.mp,a,b.mp,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const unsigned int a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    return pow(static_cast<unsigned long int>(a),b,rnd_mode);
//}
//
//inline const mpRealRational pow(const long int a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)     return pow(static_cast<unsigned long int>(a),b,rnd_mode);
//    else        return pow(mpRealRational(a),b,rnd_mode);
//}
//
//inline const mpRealRational pow(const int a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)     return pow(static_cast<unsigned long int>(a),b,rnd_mode);
//    else        return pow(mpRealRational(a),b,rnd_mode);
//}
//
///*Change DH
//inline const mpRealRational pow(const long double a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode);
//}
//*/
//
//
//inline const mpRealRational pow(const double a, const mpRealRational& b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode);
//}
//
//// pow unsigned long int
//inline const mpRealRational pow(const unsigned long int a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//       /*Change DH */
//    mpRealRational x(a);
////    mpq_ui_pow_ui(x.mp,a,b,rnd_mode);
//    x = exp(a * log(b));
//    return x;
//}
//
//inline const mpRealRational pow(const unsigned long int a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//}
//
//inline const mpRealRational pow(const unsigned long int a, const long int b, mp_rnd_t rnd_mode)
//{
//    if(b>0)    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//    else    return pow(a,mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
//inline const mpRealRational pow(const unsigned long int a, const int b, mp_rnd_t rnd_mode)
//{
//    if(b>0)    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//    else    return pow(a,mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
///* Change DH
//inline const mpRealRational pow(const unsigned long int a, const long double b, mp_rnd_t rnd_mode)
//{
//    return pow(a,mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//*/
//
//inline const mpRealRational pow(const unsigned long int a, const double b, mp_rnd_t rnd_mode)
//{
//    return pow(a,mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
//// pow unsigned int
//inline const mpRealRational pow(const unsigned int a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//    return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpq_ui_pow_ui
//}
//
//inline const mpRealRational pow(const unsigned int a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//}
//
//inline const mpRealRational pow(const unsigned int a, const long int b, mp_rnd_t rnd_mode)
//{
//    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//    else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
//inline const mpRealRational pow(const unsigned int a, const int b, mp_rnd_t rnd_mode)
//{
//    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//    else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
///*
//inline const mpRealRational pow(const unsigned int a, const long double b, mp_rnd_t rnd_mode)
//{
//    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//*/
//
//inline const mpRealRational pow(const unsigned int a, const double b, mp_rnd_t rnd_mode)
//{
//    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//}
//
//// pow long int
//inline const mpRealRational pow(const long int a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//    if (a>0) return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpq_ui_pow_ui
//    else     return pow(mpRealRational(a),b,rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const long int a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode);  //mpq_ui_pow_ui
//    else     return pow(mpRealRational(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const long int a, const long int b, mp_rnd_t rnd_mode)
//{
//    if (a>0)
//    {
//        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//        else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    }else{
//        return pow(mpRealRational(a),b,rnd_mode); // mpq_pow_si
//    }
//}
//
//inline const mpRealRational pow(const long int a, const int b, mp_rnd_t rnd_mode)
//{
//    if (a>0)
//    {
//        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//        else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    }else{
//        return pow(mpRealRational(a),static_cast<long int>(b),rnd_mode); // mpq_pow_si
//    }
//}
//
///* Change DH
//inline const mpRealRational pow(const long int a, const long double b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    else        return pow(mpRealRational(a),mpRealRational(b),rnd_mode); //mpq_pow
//}
//*/
//
//inline const mpRealRational pow(const long int a, const double b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    else        return pow(mpRealRational(a),mpRealRational(b),rnd_mode); //mpq_pow
//}
//
//// pow int
//inline const mpRealRational pow(const int a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//    if (a>0) return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpq_ui_pow_ui
//    else     return pow(mpRealRational(a),b,rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const int a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode);  //mpq_ui_pow_ui
//    else     return pow(mpRealRational(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const int a, const long int b, mp_rnd_t rnd_mode)
//{
//    if (a>0)
//    {
//        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//        else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    }else{
//        return pow(mpRealRational(a),b,rnd_mode); // mpq_pow_si
//    }
//}
//
//inline const mpRealRational pow(const int a, const int b, mp_rnd_t rnd_mode)
//{
//    if (a>0)
//    {
//        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_ui_pow_ui
//        else    return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    }else{
//        return pow(mpRealRational(a),static_cast<long int>(b),rnd_mode); // mpq_pow_si
//    }
//}
//
///*
//inline const mpRealRational pow(const int a, const long double b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    else        return pow(mpRealRational(a),mpRealRational(b),rnd_mode); //mpq_pow
//}
//*/
//
//inline const mpRealRational pow(const int a, const double b, mp_rnd_t rnd_mode)
//{
//    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealRational(b),rnd_mode); //mpq_ui_pow
//    else        return pow(mpRealRational(a),mpRealRational(b),rnd_mode); //mpq_pow
//}
//
//// pow long double
///*
//inline const mpRealRational pow(const long double a, const long double b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),mpRealRational(b),rnd_mode);
//}
//
//
//inline const mpRealRational pow(const long double a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const long double a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),static_cast<unsigned long int>(b),rnd_mode); //mpq_pow_ui
//}
//
//inline const mpRealRational pow(const long double a, const long int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode); // mpq_pow_si
//}
//
//inline const mpRealRational pow(const long double a, const int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),static_cast<long int>(b),rnd_mode); // mpq_pow_si
//}
//*/
//
//
//inline const mpRealRational pow(const double a, const double b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),mpRealRational(b),rnd_mode);
//}
//
//inline const mpRealRational pow(const double a, const unsigned long int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode); // mpq_pow_ui
//}
//
//inline const mpRealRational pow(const double a, const unsigned int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),static_cast<unsigned long int>(b),rnd_mode); // mpq_pow_ui
//}
//
//inline const mpRealRational pow(const double a, const long int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),b,rnd_mode); // mpq_pow_si
//}
//
//inline const mpRealRational pow(const double a, const int b, mp_rnd_t rnd_mode)
//{
//    return pow(mpRealRational(a),static_cast<long int>(b),rnd_mode); // mpq_pow_si
//}
} // End of mpfi namespace



// Explicit specialization of std::swap for mpRealRational numbers
// Thus standard algorithms will use efficient version of swap (due to Koenig lookup)
// Non-throwing swap C++ idiom: http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-throwing_swap
namespace std
{
	// only allowed to extend namespace std with specializations
//    template <>
//    inline void swap(mpq::mpRealRational& x, mpq::mpRealRational& y)
//    {
//        return mpq_swap(x.mp, y.mp);
//    }

    template<>
    class numeric_limits<mpq::mpRealRational>
    {
    public:
        static const bool is_specialized    = true;
        static const bool is_signed         = true;
        static const bool is_integer        = false;
        static const bool is_exact          = true;
        static const int  radix             = 2;

        static const bool has_infinity      = true;
        static const bool has_quiet_NaN     = true;
        static const bool has_signaling_NaN = true;

        static const bool is_iec559         = true;        // = IEEE 754
        static const bool is_bounded        = true;
        static const bool is_modulo         = false;
        static const bool traps             = true;
        static const bool tinyness_before   = true;

        static const float_denorm_style has_denorm  = denorm_absent;

        inline static float_round_style round_style() {return round_indeterminate;}
//        {
//            mp_rnd_t r = mpq::mpRealRational::get_default_rnd();
//
//            switch (r)
//            {
//                case MPFR_RNDN: return round_to_nearest;
//                case MPFR_RNDZ: return round_toward_zero;
//                case MPFR_RNDU: return round_toward_infinity;
//                case MPFR_RNDD: return round_toward_neg_infinity;
//                default: return round_indeterminate;
//            }
//        }

        inline static mpq::mpRealRational (min)    () {  return  mpq::minval();  }
        inline static mpq::mpRealRational (max)    () {  return  mpq::maxval();  }
        inline static mpq::mpRealRational lowest   () {  return -mpq::maxval();  }

        // Returns smallest eps such that 1 + eps != 1 (classic machine epsilon)
        inline static mpq::mpRealRational epsilon() {  return  mpq::machine_epsilon(); }

        // Returns smallest eps such that x + eps != x (relative machine epsilon)
        inline static mpq::mpRealRational epsilon(const mpq::mpRealRational& x) {  return mpq::machine_epsilon(x);  }

//        inline static mpq::mpRealRational round_error()
//        {
//            mp_rnd_t r = mpq::mpRealRational::get_default_rnd();
//
//            if(r == MPFR_RNDN) return mpq::mpRealRational(0.5);
//            else               return mpq::mpRealRational(1.0);
//        }

//        inline static const mpq::mpRealRational infinity()         { return mpq::const_infinity();     }
//        inline static const mpq::mpRealRational quiet_NaN()        { return mpq::mpRealRational().setNan();    }
//        inline static const mpq::mpRealRational signaling_NaN()    { return mpq::mpRealRational().setNan();    }
//        inline static const mpq::mpRealRational denorm_min()       { return (min)();                    }

        // Please note, exponent range is not fixed in mpfi
//        static const int min_exponent = MPFR_EMIN_DEFAULT;
//        static const int max_exponent = MPFR_EMAX_DEFAULT;
//        mpRealRational_PERMISSIVE_EXPR static const int min_exponent10 = (int) (MPFR_EMIN_DEFAULT * 0.3010299956639811);
//        mpRealRational_PERMISSIVE_EXPR static const int max_exponent10 = (int) (MPFR_EMAX_DEFAULT * 0.3010299956639811);

        // Should be constant according to standard, but 'digits' depends on precision in mpfi

//        inline static int digits()                        {    return mpq::mpRealRational::get_default_prec();    }
//        inline static int digits(const mpq::mpRealRational& x)   {    return x.getPrecision();                    }
//
//        inline static int digits10()
//        {
//            return mpq::bits2digits(precision);
//        }
//
//        inline static int digits10(const mpq::mpRealRational& x)
//        {
//            return mpq::bits2digits(x.getPrecision());
//        }
//
//        inline static int max_digits10()
//        {
//            return digits10(precision);
//        }
    };

}

#endif /* __mpRealRational_H__ */
