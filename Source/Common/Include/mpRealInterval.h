/*
    Multi-precision floating point number class for C++.
    Based on mpfi library:    http://mpfi.org

    Project homepage:    http://www.holoborodko.com/pavel/mpfi
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

#ifndef __mpRealInterval_H__
#define __mpRealInterval_H__

//#include <string>
//#include <iostream>
//#include <sstream>
#include <stdexcept>
#include <cfloat>
#include <cmath>
#include <limits>

// Options
#define mpRealInterval_HAVE_INT64_SUPPORT               // Enable int64_t support if possible. Available only for MSVC 2010 & GCC.
#define mpRealInterval_HAVE_MSVC_DEBUGVIEW              // Enable Debugger Visualizer for "Debug" builds in MSVC.

// Detect compiler using signatures from http://predef.sourceforge.net/
#if defined(__GNUC__) && defined(__INTEL_COMPILER)
    #define IsInf(x) isinf(x)                   // Intel ICC compiler on Linux

#elif defined(_MSC_VER)                         // Microsoft Visual C++
    #define IsInf(x) (!_finite(x))

#else
    #define IsInf(x) std::isinf(x)              // GNU C/C++ (and/or other compilers), just hope for C99 conformance
#endif

#if defined(mpRealInterval_HAVE_INT64_SUPPORT)

    #define mpfi_USE_INTMAX_T                   // Should be defined before mpfi.h

    #if defined(_MSC_VER)                       // MSVC + Windows
        #if (_MSC_VER >= 1600)
            #include <stdint.h>                 // <stdint.h> is available only in msvc2010!

        #else                                   // mpfi relies on intmax_t which is available only in msvc2010
            #undef mpRealInterval_HAVE_INT64_SUPPORT    // Besides, mpfi & MPIR have to be compiled with msvc2010
            #undef mpfi_USE_INTMAX_T            // Since we cannot detect this, disable x64 by default
                                                // Someone should change this manually if needed.
        #endif

    #elif defined (__GNUC__) && defined(__linux__)
        #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
            #undef mpRealInterval_HAVE_INT64_SUPPORT    // Remove all shaman dances for x64 builds since
            #undef mpfi_USE_INTMAX_T            // GCC already supports x64 as of "long int" is 64-bit integer, nothing left to do
        #else
            #include <stdint.h>                 // use int64_t, uint64_t otherwise
        #endif

    #else
        #include <stdint.h>                     // rely on int64_t, uint64_t in all other cases, Mac OSX, etc.
    #endif

#endif

#if defined(mpRealInterval_HAVE_MSVC_DEBUGVIEW) && defined(_MSC_VER) && defined(_DEBUG)
#define mpRealInterval_MSVC_DEBUGVIEW_CODE         DebugView = toString();
    #define mpRealInterval_MSVC_DEBUGVIEW_DATA     std::string DebugView;
#else
    #define mpRealInterval_MSVC_DEBUGVIEW_CODE
    #define mpRealInterval_MSVC_DEBUGVIEW_DATA
#endif

#include <mpfi.h>

#if (MPFR_VERSION < MPFR_VERSION_NUM(3,0,0))
    #include <cstdlib>                          // Needed for random()
#endif

// Less important options
#define mpRealInterval_DOUBLE_BITS_OVERFLOW -1          // Triggers overflow exception during conversion to double if mpRealInterval
                                                // cannot fit in mpRealInterval_DOUBLE_BITS_OVERFLOW bits
                                                // = -1 disables overflow checks (default)
#if defined(__GNUC__)
  #define mpRealInterval_PERMISSIVE_EXPR __extension__
#else
  #define mpRealInterval_PERMISSIVE_EXPR
#endif

namespace mpfi {

class mpRealInterval {
private:
    mpfi_t mp;

public:

    // Get default rounding mode & precision
    inline static mp_rnd_t   get_default_rnd()    {    return (mp_rnd_t)(mpfr_get_default_rounding_mode());       }
    inline static mp_prec_t  get_default_prec()   {    return mpfr_get_default_prec();                            }

    // Constructors && type conversions
    mpRealInterval();
    mpRealInterval(const mpRealInterval& u);
    mpRealInterval(const mpfi_t u);
/* Change DH */
    mpRealInterval(const mpfr_t u);

    mpRealInterval(const mpz_t u,             mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const mpq_t u,             mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const double u,            mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());

    mpRealInterval(const long double u,       mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const unsigned long int u, mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const unsigned int u,      mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const long int u,          mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const int u,               mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t mode = mpRealInterval::get_default_rnd());

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
    mpRealInterval(const uint64_t u,          mp_prec_t prec = mpRealInterval::get_default_prec(),  mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const int64_t u,           mp_prec_t prec = mpRealInterval::get_default_prec(),  mp_rnd_t mode = mpRealInterval::get_default_rnd());
#endif

    mpRealInterval(const char* s,             mp_prec_t prec = mpRealInterval::get_default_prec(), int base = 10, mp_rnd_t mode = mpRealInterval::get_default_rnd());
    mpRealInterval(const std::string& s,      mp_prec_t prec = mpRealInterval::get_default_prec(), int base = 10, mp_rnd_t mode = mpRealInterval::get_default_rnd());

    ~mpRealInterval();

    // Operations
    // =
    // +, -, *, /, ++, --, <<, >>
    // *=, +=, -=, /=,
    // <, >, ==, <=, >=

    // =
    mpRealInterval& operator=(const mpRealInterval& v);
    mpRealInterval& operator=(const mpfr_t v);
    mpRealInterval& operator=(const mpz_t v);
    mpRealInterval& operator=(const mpq_t v);
    mpRealInterval& operator=(const long double v);
    mpRealInterval& operator=(const double v);
    mpRealInterval& operator=(const unsigned long int v);
    mpRealInterval& operator=(const unsigned int v);
    mpRealInterval& operator=(const long int v);
    mpRealInterval& operator=(const int v);
    mpRealInterval& operator=(const char* s);
    mpRealInterval& operator=(const std::string& s);

    // +
    mpRealInterval& operator+=(const mpRealInterval& v);
    mpRealInterval& operator+=(const mpfr_t v);
    mpRealInterval& operator+=(const mpz_t v);
    mpRealInterval& operator+=(const mpq_t v);
    mpRealInterval& operator+=(const long double u);
    mpRealInterval& operator+=(const double u);
    mpRealInterval& operator+=(const unsigned long int u);
    mpRealInterval& operator+=(const unsigned int u);
    mpRealInterval& operator+=(const long int u);
    mpRealInterval& operator+=(const int u);

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
    mpRealInterval& operator+=(const int64_t  u);
    mpRealInterval& operator+=(const uint64_t u);
    mpRealInterval& operator-=(const int64_t  u);
    mpRealInterval& operator-=(const uint64_t u);
    mpRealInterval& operator*=(const int64_t  u);
    mpRealInterval& operator*=(const uint64_t u);
    mpRealInterval& operator/=(const int64_t  u);
    mpRealInterval& operator/=(const uint64_t u);
#endif

    const mpRealInterval operator+() const;
    mpRealInterval& operator++ ();
    const mpRealInterval  operator++ (int);

    // -
    mpRealInterval& operator-=(const mpRealInterval& v);
    mpRealInterval& operator-=(const mpz_t v);
    mpRealInterval& operator-=(const mpq_t v);
    mpRealInterval& operator-=(const long double u);
    mpRealInterval& operator-=(const double u);
    mpRealInterval& operator-=(const unsigned long int u);
    mpRealInterval& operator-=(const unsigned int u);
    mpRealInterval& operator-=(const long int u);
    mpRealInterval& operator-=(const int u);
    const mpRealInterval operator-() const;
    friend const mpRealInterval operator-(const unsigned long int b, const mpRealInterval& a);
    friend const mpRealInterval operator-(const unsigned int b,      const mpRealInterval& a);
    friend const mpRealInterval operator-(const long int b,          const mpRealInterval& a);
    friend const mpRealInterval operator-(const int b,               const mpRealInterval& a);
    friend const mpRealInterval operator-(const double b,            const mpRealInterval& a);
    mpRealInterval& operator-- ();
    const mpRealInterval  operator-- (int);

    // *
    mpRealInterval& operator*=(const mpRealInterval& v);
    mpRealInterval& operator*=(const mpz_t v);
    mpRealInterval& operator*=(const mpq_t v);
    mpRealInterval& operator*=(const long double v);
    mpRealInterval& operator*=(const double v);
    mpRealInterval& operator*=(const unsigned long int v);
    mpRealInterval& operator*=(const unsigned int v);
    mpRealInterval& operator*=(const long int v);
    mpRealInterval& operator*=(const int v);

    // /
    mpRealInterval& operator/=(const mpRealInterval& v);
    mpRealInterval& operator/=(const mpz_t v);
    mpRealInterval& operator/=(const mpq_t v);
    mpRealInterval& operator/=(const long double v);
    mpRealInterval& operator/=(const double v);
    mpRealInterval& operator/=(const unsigned long int v);
    mpRealInterval& operator/=(const unsigned int v);
    mpRealInterval& operator/=(const long int v);
    mpRealInterval& operator/=(const int v);
    friend const mpRealInterval operator/(const unsigned long int b, const mpRealInterval& a);
    friend const mpRealInterval operator/(const unsigned int b,      const mpRealInterval& a);
    friend const mpRealInterval operator/(const long int b,          const mpRealInterval& a);
    friend const mpRealInterval operator/(const int b,               const mpRealInterval& a);
    friend const mpRealInterval operator/(const double b,            const mpRealInterval& a);

    //<<= Fast Multiplication by 2^u
    mpRealInterval& operator<<=(const unsigned long int u);
    mpRealInterval& operator<<=(const unsigned int u);
    mpRealInterval& operator<<=(const long int u);
    mpRealInterval& operator<<=(const int u);

    //>>= Fast Division by 2^u
    mpRealInterval& operator>>=(const unsigned long int u);
    mpRealInterval& operator>>=(const unsigned int u);
    mpRealInterval& operator>>=(const long int u);
    mpRealInterval& operator>>=(const int u);

    // Boolean Operators
    friend bool operator >  (const mpRealInterval& a, const mpRealInterval& b);
    friend bool operator >= (const mpRealInterval& a, const mpRealInterval& b);
    friend bool operator <  (const mpRealInterval& a, const mpRealInterval& b);
    friend bool operator <= (const mpRealInterval& a, const mpRealInterval& b);
    friend bool operator == (const mpRealInterval& a, const mpRealInterval& b);
    friend bool operator != (const mpRealInterval& a, const mpRealInterval& b);

    // Optimized specializations for boolean operators
    friend bool operator == (const mpRealInterval& a, const unsigned long int b);
    friend bool operator == (const mpRealInterval& a, const unsigned int b);
    friend bool operator == (const mpRealInterval& a, const long int b);
    friend bool operator == (const mpRealInterval& a, const int b);
    friend bool operator == (const mpRealInterval& a, const long double b);
    friend bool operator == (const mpRealInterval& a, const double b);

    // Type Conversion operators
    long            toLong      (mp_rnd_t mode = GMP_RNDZ)    const;
    unsigned long   toULong     (mp_rnd_t mode = GMP_RNDZ)    const;
    double          toDouble    (mp_rnd_t mode = GMP_RNDN)    const;
    long double     toLDouble   (mp_rnd_t mode = GMP_RNDN)    const;

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
    int64_t         toInt64     (mp_rnd_t mode = GMP_RNDZ)    const;
    uint64_t        toUInt64    (mp_rnd_t mode = GMP_RNDZ)    const;
#endif

    // Get raw pointers so that mpRealInterval can be directly used in raw mpfi_* functions
    ::mpfi_ptr    mpfi_ptr();
    ::mpfi_srcptr mpfi_ptr()    const;
    ::mpfi_srcptr mpfi_srcptr() const;

    // Convert mpRealInterval to string with n significant digits in base b
    // n = 0 -> convert with the maximum available digits
    std::string        toString(int n = 0, int b = 10, mp_rnd_t mode = mpRealInterval::get_default_rnd()) const;

#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    std::string        toString(const std::string& format) const;
#endif

    // Math Functions
    friend const mpRealInterval sqr (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sqrt(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sqrt(const unsigned long int v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval cbrt(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval root(const mpRealInterval& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const mpRealInterval& a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const mpRealInterval& a, const mpz_t b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const mpRealInterval& a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const mpRealInterval& a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const unsigned long int a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval pow (const unsigned long int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval fabs(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval abs(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval dim(const mpRealInterval& a, const mpRealInterval& b);
// Change DH Begin
    friend const mpRealInterval fdim(const mpRealInterval& a, const mpRealInterval& b);
// Change DH End

    friend inline const mpRealInterval mul_2ui(const mpRealInterval& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend inline const mpRealInterval mul_2si(const mpRealInterval& v, long int k, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend inline const mpRealInterval div_2ui(const mpRealInterval& v, unsigned long int k, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend inline const mpRealInterval div_2si(const mpRealInterval& v, long int k, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend int cmpabs(const mpRealInterval& a,const mpRealInterval& b);

    friend const mpRealInterval log  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval log2 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

 // Change DH Begin
     friend const mpRealInterval logb (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
// Change DH End


    friend const mpRealInterval log10(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval exp  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval exp2 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval exp10(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval log1p(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval expm1(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval cos(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sin(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval tan(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sec(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval csc(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval cot(const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend int sin_cos(mpRealInterval& s, mpRealInterval& c, const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval acos  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval asin  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval atan  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval atan2 (const mpRealInterval& y, const mpRealInterval& x, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval acot  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval asec  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval acsc  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval cosh  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sinh  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval tanh  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sech  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval csch  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval coth  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval acosh (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval asinh (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval atanh (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval acoth (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval asech (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval acsch (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval hypot (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
// Change DH Begin
    friend const mpRealInterval copysign (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
// Change DH End

    friend const mpRealInterval fac_ui (unsigned long int v,  mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval eint   (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval gamma    (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
 // Change DH Begin
    friend const mpRealInterval tgamma    (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
 // Change DH End

    friend const mpRealInterval lngamma  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval lgamma   (const mpRealInterval& v, int *signp = 0, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval zeta     (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval erf      (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval erfc     (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval besselj0 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval besselj1 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval besseljn (long n, const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval bessely0 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval bessely1 (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval besselyn (long n, const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval fma      (const mpRealInterval& v1, const mpRealInterval& v2, const mpRealInterval& v3, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval fms      (const mpRealInterval& v1, const mpRealInterval& v2, const mpRealInterval& v3, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval agm      (const mpRealInterval& v1, const mpRealInterval& v2, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval sum      (const mpRealInterval tab[], unsigned long int n, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend int sgn(const mpRealInterval& v); // returns -1 or +1

// mpfi 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    friend int          sinh_cosh   (mpRealInterval& s, mpRealInterval& c, const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval li2         (const mpRealInterval& v,                       mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval fmod        (const mpRealInterval& x, const mpRealInterval& y,      mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval rec_sqrt    (const mpRealInterval& v,                       mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    // MATLAB's semantic equivalents
    friend const mpRealInterval rem (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd()); // Remainder after division
    friend const mpRealInterval mod (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd()); // Modulus after division
#endif

/*
// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend const mpRealInterval digamma (const mpRealInterval& v,        mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval ai      (const mpRealInterval& v,        mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval urandom (gmp_randstate_t& state, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());     // use gmp_randinit_default() to init state, gmp_randclear() to clear
#endif
*/
    // Uniformly distributed random number generation in [0,1] using
    // Mersenne-Twister algorithm by default.
    // Use parameter to setup seed, e.g.: random((unsigned)time(NULL))
    // Check urandom() for more precise control.
    friend const mpRealInterval random(unsigned int seed = 0);


    // Exponent and mantissa manipulation
    friend const mpRealInterval frexp(const mpRealInterval& v, mp_exp_t* exp);
// Change DH Begin
    friend const mpRealInterval frexp(const mpRealInterval& v, int* exp);

    friend const mpRealInterval ilogb(const mpRealInterval& v);
// Change DH End


    friend const mpRealInterval ldexp(const mpRealInterval& v, mp_exp_t exp);
// Change DH Begin
    friend const mpRealInterval ldexp(const mpRealInterval& v, const mpRealInterval& e);
    friend const mpRealInterval scalbn(const mpRealInterval& v, const mpRealInterval& e);
    friend const mpRealInterval scalbln(const mpRealInterval& v, const mpRealInterval& e);
// Change DH End




    // Splits mpRealInterval value into fractional and integer parts.
    // Returns fractional part and stores integer part in n.
    friend const mpRealInterval modf(const mpRealInterval& v, mpRealInterval& n);



    // Constants
    // don't forget to call mpfi_free_cache() for every thread where you are using const-functions
    friend const mpRealInterval const_log2      (mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval const_pi        (mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval const_euler     (mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval const_catalan   (mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    friend const mpRealInterval const_log2_a      (const mpRealInterval& v);
    friend const mpRealInterval const_pi_a      (const mpRealInterval& v);
    friend const mpRealInterval const_euler_gamma_a      (const mpRealInterval& v);
    friend const mpRealInterval const_catalan_a      (const mpRealInterval& v);




    // returns +inf iff sign>=0 otherwise -inf
    friend const mpRealInterval const_infinity(int sign = 1, mp_prec_t prec = mpRealInterval::get_default_prec(), mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

    // Output/ Input
    friend std::ostream& operator<<(std::ostream& os, const mpRealInterval& v);
    friend std::istream& operator>>(std::istream& is, mpRealInterval& v);

    // Integer Related Functions
    friend const mpRealInterval rint (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

// Change DH Begin
    friend const mpRealInterval lrint (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval llrint (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval nearbyint (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
// Change DH End

    friend const mpRealInterval ceil (const mpRealInterval& v);
    friend const mpRealInterval floor(const mpRealInterval& v);
    friend const mpRealInterval round(const mpRealInterval& v);

// Change DH Begin
    friend const mpRealInterval lround(const mpRealInterval& v);
    friend const mpRealInterval llround(const mpRealInterval& v);

    friend const mpRealInterval sign (const mpRealInterval& v);

// Change DH End



    friend const mpRealInterval trunc(const mpRealInterval& v);
    friend const mpRealInterval rint_ceil   (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval rint_floor  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval rint_round  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval rint_trunc  (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval frac        (const mpRealInterval& v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval remainder   (         const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval remquo      (long* q, const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

// Change DH Begin
    friend const mpRealInterval remquo      (const mpRealInterval& x, const mpRealInterval& y, int* q, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
// Change DH End



    // Miscellaneous Functions
    friend const mpRealInterval nexttoward (const mpRealInterval& x, const mpRealInterval& y);
// Change DH Begin
    friend const mpRealInterval nextafter (const mpRealInterval& x, const mpRealInterval& y);
// Change DH End


    friend const mpRealInterval nextabove  (const mpRealInterval& x);
    friend const mpRealInterval nextbelow  (const mpRealInterval& x);

    // use gmp_randinit_default() to init state, gmp_randclear() to clear
    friend const mpRealInterval urandomb (gmp_randstate_t& state);

// mpfi < 2.4.2 Specifics
#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
    friend const mpRealInterval random2 (mp_size_t size, mp_exp_t exp);
#endif

    // Instance Checkers
    friend bool isnan    (const mpRealInterval& v);
    friend bool isinf    (const mpRealInterval& v);
    friend bool isfinite (const mpRealInterval& v);

    friend bool isnum    (const mpRealInterval& v);
    friend bool iszero   (const mpRealInterval& v);
    friend bool isint    (const mpRealInterval& v);

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend bool isregular(const mpRealInterval& v);
#endif

    // Set/Get instance properties
    inline mp_prec_t    get_prec() const;
    inline void         set_prec(mp_prec_t prec, mp_rnd_t rnd_mode = get_default_rnd());    // Change precision with rounding mode

    // Aliases for get_prec(), set_prec() - needed for compatibility with std::complex<mpRealInterval> interface
    inline mpRealInterval&      setPrecision(int Precision, mp_rnd_t RoundingMode = get_default_rnd());
    inline int          getPrecision() const;

    // Set mpRealInterval to +/- inf, NaN, +/-0
    mpRealInterval&        setInf  (int Sign = +1);
    mpRealInterval&        setNan  ();
    mpRealInterval&        setZero (int Sign = +1);
    mpRealInterval&        setSign (int Sign, mp_rnd_t RoundingMode = get_default_rnd());

    //Exponent
    mp_exp_t get_exp();
    int set_exp(mp_exp_t e);
    int check_range  (int t, mp_rnd_t rnd_mode = get_default_rnd());
    int subnormalize (int t,mp_rnd_t rnd_mode = get_default_rnd());

    // Inexact conversion from float
    inline bool fits_in_bits(double x, int n);

    // Set/Get global properties
    static void            set_default_prec(mp_prec_t prec);
    static void            set_default_rnd(mp_rnd_t rnd_mode);

    static mp_exp_t  get_emin (void);
    static mp_exp_t  get_emax (void);
    static mp_exp_t  get_emin_min (void);
    static mp_exp_t  get_emin_max (void);
    static mp_exp_t  get_emax_min (void);
    static mp_exp_t  get_emax_max (void);
    static int       set_emin (mp_exp_t exp);
    static int       set_emax (mp_exp_t exp);

    // Efficient swapping of two mpRealInterval values - needed for std algorithms
    friend void swap(mpRealInterval& x, mpRealInterval& y);

    friend const mpRealInterval fmax(const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
    friend const mpRealInterval fmin(const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

private:
    // Human friendly Debug Preview in Visual Studio.
    // Put one of these lines:
    //
    // mpfi::mpRealInterval=<DebugView>                                ; Show value only
    // mpfi::mpRealInterval=<DebugView>, <mp[0]._mpfi_prec,u>bits    ; Show value & precision
    //
    // at the beginning of
    // [Visual Studio Installation Folder]\Common7\Packages\Debugger\autoexp.dat
    mpRealInterval_MSVC_DEBUGVIEW_DATA
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
inline mpRealInterval::mpRealInterval()
{
    mpfi_init2(mp,mpRealInterval::get_default_prec());
    mpfi_set_ui(mp,0);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const mpRealInterval& u)
{
    mpfi_init2(mp,mpfi_get_prec(u.mp));
    mpfi_set(mp,u.mp);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const mpfi_t u)
{
    mpfi_init2(mp,mpfi_get_prec(u));
    mpfi_set(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

/* Change DH */
inline mpRealInterval::mpRealInterval(const mpfr_t u)
{
    mpfi_init2(mp,(mp_prec_t) mpfr_get_prec(u)); // (gmp: mp_bitcnt_t) unsigned long -> long (mpfi: mp_prec_t)
    mpfi_set_fr(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}
/* End Change DH */

inline mpRealInterval::mpRealInterval(const mpz_t u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_z(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const mpq_t u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_q(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const double u, mp_prec_t prec, mp_rnd_t mode)
{
     mpfi_init2(mp, prec);

#if (mpRealInterval_DOUBLE_BITS_OVERFLOW > -1)
	if(fits_in_bits(u, mpRealInterval_DOUBLE_BITS_OVERFLOW))
	{
		mpfi_set_d(mp, u);
	}else
		throw conversion_overflow();
#else
	mpfi_set_d(mp, u);
#endif

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

/* modified by DH */
inline mpRealInterval::mpRealInterval(const long double u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_ld(x, u, mode);

    mpfi_init2(mp,prec);
    mpfi_set_fr(mp, x);

    mpfr_clear(x);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}


inline mpRealInterval::mpRealInterval(const unsigned long int u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_ui(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const unsigned int u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_ui(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const long int u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_si(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const int u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfi_init2(mp,prec);
    mpfi_set_si(mp,u);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
inline mpRealInterval::mpRealInterval(const uint64_t u, mp_prec_t prec, mp_rnd_t mode)
{
/* modified by DH */
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_uj(x, u, mode);


    mpfi_init2(mp,prec);
    mpfi_set_fr(mp, x);

    mpfr_clear(x);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const int64_t u, mp_prec_t prec, mp_rnd_t mode)
{
    /* modified by DH */
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_sj(x, u, mode);


    mpfi_init2(mp,prec);
    mpfi_set_fr(mp, x);

    mpfr_clear(x);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}
#endif

inline mpRealInterval::mpRealInterval(const char* s, mp_prec_t prec, int base, mp_rnd_t mode)
{
    mpfi_init2(mp, prec);
    mpfi_set_str(mp, s, base);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::mpRealInterval(const std::string& s, mp_prec_t prec, int base, mp_rnd_t mode)
{
    mpfi_init2(mp, prec);
    mpfi_set_str(mp, s.c_str(), base);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}

inline mpRealInterval::~mpRealInterval()
{
    mpfi_clear(mp);
}

// internal namespace needed for template magic
namespace internal{

    // Use SFINAE to restrict arithmetic operations instantiation only for numeric types
    // This is needed for smooth integration with libraries based on expression templates, like Eigen.
    // TODO: Do the same for boolean operators.
    template <typename ArgumentType> struct result_type {};

    template <> struct result_type<mpRealInterval>              {typedef mpRealInterval type;};
    template <> struct result_type<mpz_t>               {typedef mpRealInterval type;};
    template <> struct result_type<mpq_t>               {typedef mpRealInterval type;};
    template <> struct result_type<long double>         {typedef mpRealInterval type;};
    template <> struct result_type<double>              {typedef mpRealInterval type;};
    template <> struct result_type<unsigned long int>   {typedef mpRealInterval type;};
    template <> struct result_type<unsigned int>        {typedef mpRealInterval type;};
    template <> struct result_type<long int>            {typedef mpRealInterval type;};
    template <> struct result_type<int>                 {typedef mpRealInterval type;};

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
    template <> struct result_type<int64_t  >           {typedef mpRealInterval type;};
    template <> struct result_type<uint64_t >           {typedef mpRealInterval type;};
#endif
}

// + Addition
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator+(const mpRealInterval& lhs, const Rhs& rhs){ return mpRealInterval(lhs) += rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator+(const Lhs& lhs, const mpRealInterval& rhs){ return mpRealInterval(rhs) += lhs;    }

// - Subtraction
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator-(const mpRealInterval& lhs, const Rhs& rhs){ return mpRealInterval(lhs) -= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator-(const Lhs& lhs, const mpRealInterval& rhs){ return mpRealInterval(lhs) -= rhs;    }

// * Multiplication
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator*(const mpRealInterval& lhs, const Rhs& rhs){ return mpRealInterval(lhs) *= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator*(const Lhs& lhs, const mpRealInterval& rhs){ return mpRealInterval(rhs) *= lhs;    }

// / Division
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator/(const mpRealInterval& lhs, const Rhs& rhs){ return mpRealInterval(lhs) /= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator/(const Lhs& lhs, const mpRealInterval& rhs){ return mpRealInterval(lhs) /= rhs;    }

//////////////////////////////////////////////////////////////////////////
// sqrt
const mpRealInterval sqrt(const unsigned int v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval sqrt(const long int v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval sqrt(const int v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval sqrt(const long double v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval sqrt(const double v, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

//////////////////////////////////////////////////////////////////////////
// pow
const mpRealInterval pow(const mpRealInterval& a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const mpRealInterval& a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const mpRealInterval& a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const mpRealInterval& a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const unsigned int a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long double a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const double a, const mpRealInterval& b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const unsigned long int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned long int a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned long int a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned long int a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned long int a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const unsigned int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned int a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned int a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned int a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const unsigned int a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const long int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long int a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const int a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const int a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const long double a, const long double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long double a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long double a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long double a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const long double a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

const mpRealInterval pow(const double a, const double b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const double a, const unsigned long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const double a, const unsigned int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const double a, const long int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());
const mpRealInterval pow(const double a, const int b, mp_rnd_t rnd_mode = mpRealInterval::get_default_rnd());

//////////////////////////////////////////////////////////////////////////
// Estimate machine epsilon for the given precision
// Returns smallest eps such that 1.0 + eps != 1.0
inline mpRealInterval machine_epsilon(mp_prec_t prec = mpRealInterval::get_default_prec());

// Returns smallest eps such that x + eps != x (relative machine epsilon)
inline mpRealInterval machine_epsilon(const mpRealInterval& x);

// Gives max & min values for the required precision,
// minval is 'safe' meaning 1 / minval does not overflow
// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpRealInterval minval(mp_prec_t prec = mpRealInterval::get_default_prec());
inline mpRealInterval maxval(mp_prec_t prec = mpRealInterval::get_default_prec());

// 'Dirty' equality check 1: |a-b| < min{|a|,|b|} * eps
inline bool isEqualFuzzy(const mpRealInterval& a, const mpRealInterval& b, const mpRealInterval& eps);

// 'Dirty' equality check 2: |a-b| < min{|a|,|b|} * eps( min{|a|,|b|} )
inline bool isEqualFuzzy(const mpRealInterval& a, const mpRealInterval& b);

// 'Bitwise' equality check
//  maxUlps - a and b can be apart by maxUlps binary numbers.
inline bool isEqualUlps(const mpRealInterval& a, const mpRealInterval& b, int maxUlps);

//////////////////////////////////////////////////////////////////////////
//     Convert precision in 'bits' to decimal digits and vice versa.
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

inline mp_prec_t digits2bits(int d);
inline int       bits2digits(mp_prec_t b);

//////////////////////////////////////////////////////////////////////////
// min, max
const mpRealInterval (max)(const mpRealInterval& x, const mpRealInterval& y);
const mpRealInterval (min)(const mpRealInterval& x, const mpRealInterval& y);

//////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Operators - Assignment
inline mpRealInterval& mpRealInterval::operator=(const mpRealInterval& v)
{
    if (this != &v)
    {
		mp_prec_t tp = mpfi_get_prec(mp);
		mp_prec_t vp = mpfi_get_prec(v.mp);

		if(tp != vp){
			mpfi_clear(mp);
			mpfi_init2(mp, vp);
		}

        mpfi_set(mp, v.mp);

        mpRealInterval_MSVC_DEBUGVIEW_CODE;
    }
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const mpfr_t v)
{
    mpfi_set_fr(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const mpz_t v)
{
    mpfi_set_z(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const mpq_t v)
{
    mpfi_set_q(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


/* modified by DH */
inline mpRealInterval& mpRealInterval::operator=(const long double v)
{
    mpfr_t x;

    mpfr_init2(x,64);
    mpfr_set_ld(x, v, mpfr_get_default_rounding_mode());

    mpfi_init2(mp,64);
    mpfi_set_fr(mp, x);

    mpfr_clear(x);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator=(const double v)
{
#if (mpRealInterval_DOUBLE_BITS_OVERFLOW > -1)
	if(fits_in_bits(v, mpRealInterval_DOUBLE_BITS_OVERFLOW))
	{
		mpfi_set_d(mp,v);
	}else
		throw conversion_overflow();
#else
	mpfi_set_d(mp,v);
#endif

	mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const unsigned long int v)
{
    mpfi_set_ui(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const unsigned int v)
{
    mpfi_set_ui(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const long int v)
{
    mpfi_set_si(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const int v)
{
    mpfi_set_si(mp, v);

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const char* s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpRealInterval(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpRealInterval(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.

    mpfi_t t;

    mpfi_init2(t, mpfi_get_prec(mp));

    if(0 == mpfi_set_str(t, s, 10))
    {
        mpfi_set(mp, t);
        mpRealInterval_MSVC_DEBUGVIEW_CODE;
    }

    mpfi_clear(t);
    return *this;
}

inline mpRealInterval& mpRealInterval::operator=(const std::string& s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpRealInterval(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpRealInterval(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.

    mpfi_t t;

    mpfi_init2(t, mpfi_get_prec(mp));

    if(0 == mpfi_set_str(t, s.c_str(), 10))
    {
        mpfi_set(mp, t);
        mpRealInterval_MSVC_DEBUGVIEW_CODE;
    }

    mpfi_clear(t);
    return *this;
}


//////////////////////////////////////////////////////////////////////////
// + Addition
inline mpRealInterval& mpRealInterval::operator+=(const mpRealInterval& v)
{
    mpfi_add(mp,mp,v.mp);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const mpfr_t u)
{
    *this += mpRealInterval(u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const mpz_t u)
{
    mpfi_add_z(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const mpq_t u)
{
    mpfi_add_q(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+= (const long double u)
{
    *this += mpRealInterval(u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator+= (const double u)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpfi_add_d(mp,mp,u);
#else
    *this += mpRealInterval(u);
#endif

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const unsigned long int u)
{
    mpfi_add_ui(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const unsigned int u)
{
    mpfi_add_ui(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const long int u)
{
    mpfi_add_si(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator+=(const int u)
{
    mpfi_add_si(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
inline mpRealInterval& mpRealInterval::operator+=(const int64_t  u){    *this += mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator+=(const uint64_t u){    *this += mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator-=(const int64_t  u){    *this -= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator-=(const uint64_t u){    *this -= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator*=(const int64_t  u){    *this *= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator*=(const uint64_t u){    *this *= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator/=(const int64_t  u){    *this /= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpRealInterval& mpRealInterval::operator/=(const uint64_t u){    *this /= mpRealInterval(u); mpRealInterval_MSVC_DEBUGVIEW_CODE; return *this;    }
#endif

inline const mpRealInterval mpRealInterval::operator+()const    {    return mpRealInterval(*this); }

inline const mpRealInterval operator+(const mpRealInterval& a, const mpRealInterval& b)
{
	mpRealInterval c(0, (std::max)(mpfi_get_prec(a.mpfi_ptr()), mpfi_get_prec(b.mpfi_ptr())));
	mpfi_add(c.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr());
	return c;
}

inline mpRealInterval& mpRealInterval::operator++()
{
    return *this += 1;
}

inline const mpRealInterval mpRealInterval::operator++ (int)
{
    mpRealInterval x(*this);
    *this += 1;
    return x;
}

inline mpRealInterval& mpRealInterval::operator--()
{
    return *this -= 1;
}

inline const mpRealInterval mpRealInterval::operator-- (int)
{
    mpRealInterval x(*this);
    *this -= 1;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// - Subtraction
inline mpRealInterval& mpRealInterval::operator-=(const mpRealInterval& v)
{
    mpfi_sub(mp,mp,v.mp);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const mpz_t v)
{
    mpfi_sub_z(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const mpq_t v)
{
    mpfi_sub_q(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator-=(const long double v)
{
    *this -= mpRealInterval(v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator-=(const double v)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpfi_sub_d(mp,mp,v);
#else
    *this -= mpRealInterval(v);
#endif

    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const unsigned long int v)
{
    mpfi_sub_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const unsigned int v)
{
    mpfi_sub_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const long int v)
{
    mpfi_sub_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator-=(const int v)
{
    mpfi_sub_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealInterval mpRealInterval::operator-()const
{
    mpRealInterval u(*this);
    mpfi_neg(u.mp,u.mp);
    return u;
}

inline const mpRealInterval operator-(const mpRealInterval& a, const mpRealInterval& b)
{
	mpRealInterval c(0, (std::max)(mpfi_get_prec(a.mpfi_ptr()), mpfi_get_prec(b.mpfi_ptr())));
	mpfi_sub(c.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr());
	return c;
}

inline const mpRealInterval operator-(const double  b, const mpRealInterval& a)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_d_sub(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
#else
    mpRealInterval x(b, mpfi_get_prec(a.mpfi_ptr()));
    x -= a;
    return x;
#endif
}

inline const mpRealInterval operator-(const unsigned long int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_ui_sub(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator-(const unsigned int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_ui_sub(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator-(const long int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_si_sub(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator-(const int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_si_sub(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

//////////////////////////////////////////////////////////////////////////
// * Multiplication
inline mpRealInterval& mpRealInterval::operator*= (const mpRealInterval& v)
{
    mpfi_mul(mp,mp,v.mp);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const mpz_t v)
{
    mpfi_mul_z(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const mpq_t v)
{
    mpfi_mul_q(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator*=(const long double v)
{
    *this *= mpRealInterval(v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const double v)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpfi_mul_d(mp,mp,v);
#else
    *this *= mpRealInterval(v);
#endif
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const unsigned long int v)
{
    mpfi_mul_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const unsigned int v)
{
    mpfi_mul_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const long int v)
{
    mpfi_mul_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator*=(const int v)
{
    mpfi_mul_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealInterval operator*(const mpRealInterval& a, const mpRealInterval& b)
{
	mpRealInterval c(0, (std::max)(mpfi_get_prec(a.mpfi_ptr()), mpfi_get_prec(b.mpfi_ptr())));
	mpfi_mul(c.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr());
	return c;
}

//////////////////////////////////////////////////////////////////////////
// / Division
inline mpRealInterval& mpRealInterval::operator/=(const mpRealInterval& v)
{
    mpfi_div(mp,mp,v.mp);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const mpz_t v)
{
    mpfi_div_z(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const mpq_t v)
{
    mpfi_div_q(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator/=(const long double v)
{
    *this /= mpRealInterval(v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpRealInterval& mpRealInterval::operator/=(const double v)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpfi_div_d(mp,mp,v);
#else
    *this /= mpRealInterval(v);
#endif
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const unsigned long int v)
{
    mpfi_div_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const unsigned int v)
{
    mpfi_div_ui(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const long int v)
{
    mpfi_div_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator/=(const int v)
{
    mpfi_div_si(mp,mp,v);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealInterval operator/(const mpRealInterval& a, const mpRealInterval& b)
{
	mpRealInterval c(0, (std::max)(mpfi_get_prec(a.mpfi_ptr()), mpfi_get_prec(b.mpfi_ptr())));
	mpfi_div(c.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr());
	return c;
}

inline const mpRealInterval operator/(const unsigned long int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_ui_div(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator/(const unsigned int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_ui_div(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator/(const long int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_si_div(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator/(const int b, const mpRealInterval& a)
{
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_si_div(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
}

inline const mpRealInterval operator/(const double  b, const mpRealInterval& a)
{
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    mpfi_d_div(x.mpfi_ptr(), b, a.mpfi_srcptr());
    return x;
#else
    mpRealInterval x(0, mpfi_get_prec(a.mpfi_ptr()));
    x /= a;
    return x;
#endif
}

//////////////////////////////////////////////////////////////////////////
// Shifts operators - Multiplication/Division by power of 2
inline mpRealInterval& mpRealInterval::operator<<=(const unsigned long int u)
{
    mpfi_mul_2ui(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator<<=(const unsigned int u)
{
    mpfi_mul_2ui(mp,mp,static_cast<unsigned long int>(u));
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator<<=(const long int u)
{
    mpfi_mul_2si(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator<<=(const int u)
{
    mpfi_mul_2si(mp,mp,static_cast<long int>(u));
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator>>=(const unsigned long int u)
{
    mpfi_div_2ui(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator>>=(const unsigned int u)
{
    mpfi_div_2ui(mp,mp,static_cast<unsigned long int>(u));
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator>>=(const long int u)
{
    mpfi_div_2si(mp,mp,u);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::operator>>=(const int u)
{
    mpfi_div_2si(mp,mp,static_cast<long int>(u));
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpRealInterval operator<<(const mpRealInterval& v, const unsigned long int k)
{
    return mul_2ui(v,k);
}

inline const mpRealInterval operator<<(const mpRealInterval& v, const unsigned int k)
{
    return mul_2ui(v,static_cast<unsigned long int>(k));
}

inline const mpRealInterval operator<<(const mpRealInterval& v, const long int k)
{
    return mul_2si(v,k);
}

inline const mpRealInterval operator<<(const mpRealInterval& v, const int k)
{
    return mul_2si(v,static_cast<long int>(k));
}

inline const mpRealInterval operator>>(const mpRealInterval& v, const unsigned long int k)
{
    return div_2ui(v,k);
}

inline const mpRealInterval operator>>(const mpRealInterval& v, const long int k)
{
    return div_2si(v,k);
}

inline const mpRealInterval operator>>(const mpRealInterval& v, const unsigned int k)
{
    return div_2ui(v,static_cast<unsigned long int>(k));
}

inline const mpRealInterval operator>>(const mpRealInterval& v, const int k)
{
    return div_2si(v,static_cast<long int>(k));
}

// mul_2ui
inline const mpRealInterval mul_2ui(const mpRealInterval& v, unsigned long int k, mp_rnd_t rnd_mode)
{
    mpRealInterval x(v);
    mpfi_mul_2ui(x.mp,v.mp,k);
    return x;
}

// mul_2si
inline const mpRealInterval mul_2si(const mpRealInterval& v, long int k, mp_rnd_t rnd_mode)
{
    mpRealInterval x(v);
    mpfi_mul_2si(x.mp,v.mp,k);
    return x;
}

inline const mpRealInterval div_2ui(const mpRealInterval& v, unsigned long int k, mp_rnd_t rnd_mode)
{
    mpRealInterval x(v);
    mpfi_div_2ui(x.mp,v.mp,k);
    return x;
}

inline const mpRealInterval div_2si(const mpRealInterval& v, long int k, mp_rnd_t rnd_mode)
{
    mpRealInterval x(v);
    mpfi_div_2si(x.mp,v.mp,k);
    return x;
}

//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////
//Boolean operators
inline bool operator >  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_greater_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}

inline bool operator >=  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_greaterequal_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}


inline bool operator <  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_less_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}



inline bool operator <=  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_lessequal_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}


inline bool operator ==  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_equal_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}


inline bool operator !=  (const mpRealInterval& a, const mpRealInterval& b)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, a.mp);
    mpfi_mid (br, b.mp);
    bool result = (mpfr_lessgreater_p(ar,br) !=0);
    mpfr_clear(ar);
    mpfr_clear(br);
    return result;
}



//inline bool operator != (const mpRealInterval& a, const mpRealInterval& b){    return (mpfi_lessgreater_p(a.mp,b.mp)  !=0);    }




inline bool operator == (const mpRealInterval& a, const unsigned long int b ){    return (mpfi_cmp_ui(a.mp,b) == 0);    }
inline bool operator == (const mpRealInterval& a, const unsigned int b      ){    return (mpfi_cmp_ui(a.mp,b) == 0);    }
inline bool operator == (const mpRealInterval& a, const long int b          ){    return (mpfi_cmp_si(a.mp,b) == 0);    }
inline bool operator == (const mpRealInterval& a, const int b               ){    return (mpfi_cmp_si(a.mp,b) == 0);    }
/* Change DH
inline bool operator == (const mpRealInterval& a, const long double b       ){    return (mpfi_cmp_ld(a.mp,b) == 0);    }
*/
inline bool operator == (const mpRealInterval& a, const double b            ){    return (mpfi_cmp_d(a.mp,b)  == 0);    }


inline bool isnan    (const mpRealInterval& v){    return (mpfi_nan_p(v.mp)     != 0);    }
inline bool isinf    (const mpRealInterval& v){    return (mpfi_inf_p(v.mp)     != 0);    }
inline bool isfinite (const mpRealInterval& v){    return (mpfi_bounded_p(v.mp)  != 0);    }
inline bool iszero   (const mpRealInterval& v){    return (mpfi_is_zero(v.mp)    != 0);    }
/* Change DH
inline bool isint    (const mpRealInterval& v){    return (mpfi_integer_p(v.mp) != 0);    }
*/

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
/* Change DH
inline bool isregular(const mpRealInterval& v){    return (mpfi_regular_p(v.mp));}
*/
#endif

//////////////////////////////////////////////////////////////////////////
// Type Converters
/* Change DH */
//inline long             mpRealInterval::toLong   (mp_rnd_t mode)  const    {    return mpfi_get_si(mp, mode);    }
//inline unsigned long    mpRealInterval::toULong  (mp_rnd_t mode)  const    {    return mpfi_get_ui(mp, mode);    }

inline long             mpRealInterval::toLong   (mp_rnd_t mode)  const    {    return (long) mpfi_get_d(mp);    }
inline unsigned long    mpRealInterval::toULong  (mp_rnd_t mode)  const    {    return (unsigned long) mpfi_get_d(mp);    }

inline double           mpRealInterval::toDouble (mp_rnd_t mode)  const    {    return mpfi_get_d (mp);    }
//inline long double      mpRealInterval::toLDouble(mp_rnd_t mode)  const    {    return mpfi_get_ld(mp);    }
inline long double      mpRealInterval::toLDouble(mp_rnd_t mode)  const    {    return mpfi_get_d(mp);    }


#if defined (mpRealInterval_HAVE_INT64_SUPPORT)
//inline int64_t      mpRealInterval::toInt64 (mp_rnd_t mode)    const{    return mpfi_get_sj(mp, mode);    }
//inline uint64_t     mpRealInterval::toUInt64(mp_rnd_t mode)    const{    return mpfi_get_uj(mp, mode);    }

inline int64_t      mpRealInterval::toInt64 (mp_rnd_t mode)    const{    return (int64_t) mpfi_get_d(mp);    }
inline uint64_t     mpRealInterval::toUInt64(mp_rnd_t mode)    const{    return (uint64_t) mpfi_get_d(mp);    }

#endif

inline ::mpfi_ptr     mpRealInterval::mpfi_ptr()             { return mp; }
inline ::mpfi_srcptr  mpRealInterval::mpfi_ptr()    const    { return mp; }
inline ::mpfi_srcptr  mpRealInterval::mpfi_srcptr() const    { return mp; }

template <class T>
inline std::string toString(T t, std::ios_base & (*f)(std::ios_base&))
{
    std::ostringstream oss;
    oss << f << t;
    return oss.str();
}

#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline std::string mpRealInterval::toString(const std::string& format) const
{
    char *sL = NULL;
    std::string outL;
    mpfr_t fL;
    mpfr_init(fL);
    mpfi_get_left(fL, mp);
    if( !format.empty() )
    {
        if(!(mpfr_asprintf(&sL,format.c_str(),fL) < 0))
        {
            outL = std::string(sL);

            mpfr_free_str(sL);
        }
    }
    char *sR = NULL;
    std::string outR;
    mpfr_t fR;
    mpfr_init(fR);
    mpfi_get_right(fR, mp);
    if( !format.empty() )
    {
        if(!(mpfr_asprintf(&sR,format.c_str(),fR) < 0))
        {
            outR = std::string(sR);

            mpfr_free_str(sR);
        }
    }
    std::string out = "[" + outL + ", " + outR + "]";
    return out;
}

#endif

inline std::string mpRealInterval::toString(int n, int b, mp_rnd_t mode) const
{
    (void)b;
    (void)mode;

#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

    // Use mpfi native function for output
    char format[128];
    int digits;

    digits = n > 0 ? n : bits2digits(mpfi_get_prec(mp));

    sprintf(format,"%%.%dRNg",digits);        // Default format

    return toString(std::string(format));

#else

    char *s, *ns = NULL;
    size_t slen, nslen;
    mp_exp_t exp;
    std::string out;

    if(mpfi_inf_p(mp))
    {
        if(mpfi_sgn(mp)>0) return "+Inf";
        else               return "-Inf";
    }

    if(mpfi_zero_p(mp)) return "0";
    if(mpfi_nan_p(mp))  return "NaN";

    s  = mpfi_get_str(NULL,&exp,b,0,mp,mode);
    ns = mpfi_get_str(NULL,&exp,b,n,mp,mode);

    if(s!=NULL && ns!=NULL)
    {
        slen  = strlen(s);
        nslen = strlen(ns);
        if(nslen<=slen)
        {
            mpfi_free_str(s);
            s = ns;
            slen = nslen;
        }
        else {
            mpfi_free_str(ns);
        }

        // Make human eye-friendly formatting if possible
        if (exp>0 && static_cast<size_t>(exp)<slen)
        {
            if(s[0]=='-')
            {
                // Remove zeros starting from right end
                char* ptr = s+slen-1;
                while (*ptr=='0' && ptr>s+exp) ptr--;

                if(ptr==s+exp) out = std::string(s,exp+1);
                else           out = std::string(s,exp+1)+'.'+std::string(s+exp+1,ptr-(s+exp+1)+1);

                //out = string(s,exp+1)+'.'+string(s+exp+1);
            }
            else
            {
                // Remove zeros starting from right end
                char* ptr = s+slen-1;
                while (*ptr=='0' && ptr>s+exp-1) ptr--;

                if(ptr==s+exp-1) out = std::string(s,exp);
                else             out = std::string(s,exp)+'.'+std::string(s+exp,ptr-(s+exp)+1);

                //out = string(s,exp)+'.'+string(s+exp);
            }

        }else{ // exp<0 || exp>slen
            if(s[0]=='-')
            {
                // Remove zeros starting from right end
                char* ptr = s+slen-1;
                while (*ptr=='0' && ptr>s+1) ptr--;

                if(ptr==s+1) out = std::string(s,2);
                else         out = std::string(s,2)+'.'+std::string(s+2,ptr-(s+2)+1);

                //out = string(s,2)+'.'+string(s+2);
            }
            else
            {
                // Remove zeros starting from right end
                char* ptr = s+slen-1;
                while (*ptr=='0' && ptr>s) ptr--;

                if(ptr==s) out = std::string(s,1);
                else       out = std::string(s,1)+'.'+std::string(s+1,ptr-(s+1)+1);

                //out = string(s,1)+'.'+string(s+1);
            }

            // Make final string
            if(--exp)
            {
                if(exp>0) out += "e+"+mpfi::toString<mp_exp_t>(exp,std::dec);
                else       out += "e"+mpfi::toString<mp_exp_t>(exp,std::dec);
            }
        }

        mpfi_free_str(s);
        return out;
    }else{
        return "conversion error!";
    }
#endif
}


//////////////////////////////////////////////////////////////////////////
// I/O
inline std::ostream& operator<<(std::ostream& os, const mpRealInterval& v)
{
    return os<<v.toString(static_cast<int>(os.precision()));
}

inline std::istream& operator>>(std::istream &is, mpRealInterval& v)
{
    // ToDo, use cout::hexfloat and other flags to setup base
    std::string tmp;
    is >> tmp;
    mpfi_set_str(v.mp, tmp.c_str(), 10);
    return is;
}

//////////////////////////////////////////////////////////////////////////
//     Bits - decimal digits relation
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

inline mp_prec_t digits2bits(int d)
{
    const double LOG2_10 = 3.3219280948873624;

    return (mp_prec_t) std::ceil( d * LOG2_10 );
}

inline int bits2digits(mp_prec_t b)
{
    const double LOG10_2 = 0.30102999566398119;

    return (int) std::floor( b * LOG10_2 );
}

//////////////////////////////////////////////////////////////////////////
// Set/Get number properties
//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////

inline int sgn(const mpRealInterval& v)
{
    mpfr_t ar;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfi_mid (ar, v.mp);
    int r = mpfr_sgn(ar);
    mpfr_clear(ar);
    return r;
}

inline mpRealInterval& mpRealInterval::setSign(int sign, mp_rnd_t RoundingMode)
{
    /* Change DH
    mpfi_setsign(mp,mp,(sign < 0 ? 1 : 0),RoundingMode);
    */
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline int mpRealInterval::getPrecision() const
{
    return mpfi_get_prec(mp);
}

inline mpRealInterval& mpRealInterval::setPrecision(int Precision, mp_rnd_t RoundingMode)
{
    /* Change DH
    mpfi_prec_round(mp, Precision, RoundingMode);
    */
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::setInf(int sign)
{
    /* Change DH
    mpfi_set_inf(mp,sign);
    */
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval& mpRealInterval::setNan()
{
    /* Change DH
    mpfi_set_nan(mp);
    */
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpRealInterval&    mpRealInterval::setZero(int sign)
{
    mpfi_set_si(mp, 0);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mp_prec_t mpRealInterval::get_prec() const
{
    return mpfi_get_prec(mp);
}

inline void mpRealInterval::set_prec(mp_prec_t prec, mp_rnd_t rnd_mode)
{
    /* Change DH */
    mpfi_set_prec(mp,prec);
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
}



// modified by DH
inline mp_exp_t mpRealInterval::get_exp ()
{
    mpfr_t ar;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfi_mid (ar, mp);
    mp_exp_t e = mpfr_get_exp(ar);
    mpfr_clear(ar);
    return e;
}

inline int mpRealInterval::set_exp (mp_exp_t e)
{
    mpfr_t ar;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfi_mid (ar, mp);
    int x = mpfr_set_exp(ar, e);
    mpfi_set_fr(mp, ar)
    mpRealInterval_MSVC_DEBUGVIEW_CODE;
    return x;
}

inline const mpRealInterval frexp(const mpRealInterval& v, mp_exp_t* exp)
{
    mpRealInterval x(v);
    *exp = x.get_exp();
    x.set_exp(0);
    return x;
}


//Change DH Begin

inline const mpRealInterval frexp(const mpRealInterval& v, int* exp)
{
    mpRealInterval x(v);
    *exp = x.get_exp();
    x.set_exp(0);
    return x;
}


inline const mpRealInterval ilogb(const mpRealInterval& v)
{
    mpRealInterval x(v);
    mp_exp_t exp = x.get_exp();
    mpRealInterval y(exp - 1);
    return y;
}

//Change DH End



inline const mpRealInterval ldexp(const mpRealInterval& v, mp_exp_t exp)
{
    mpRealInterval x(v);

    // rounding is not important since we just increasing the exponent
    mpfi_mul_2si(x.mp,x.mp,exp);
    return x;
}


//Change DH Begin

inline const mpRealInterval ldexp(const mpRealInterval& v, const mpRealInterval& e)
{
    mpRealInterval x(v);
    mp_exp_t exp = mpfi_get_d(x.mp);

    // rounding is not important since we just increasing the exponent
    mpfi_mul_2si(x.mp,x.mp,exp);
    return x;
}

//Change DH End


//Change DH Begin

inline const mpRealInterval scalbn(const mpRealInterval& v, const mpRealInterval& e)
{
    return ldexp(v,e);
}

inline const mpRealInterval scalbln(const mpRealInterval& v, const mpRealInterval& e)
{
    return ldexp(v,e);
}

//Change DH End






inline mpRealInterval machine_epsilon(mp_prec_t prec)
{
    /* the smallest eps such that 1 + eps != 1 */
    return machine_epsilon(mpRealInterval(1, prec));
}

inline mpRealInterval machine_epsilon(const mpRealInterval& x)
{
    /* the smallest eps such that x + eps != x */
    return 1E-30;
//    if( x < 0)
//    {
//        return nextabove(-x)+x;
//    }else{
//        return nextabove(x)-x;
//    }
}

// minval is 'safe' meaning 1 / minval does not overflow
inline mpRealInterval minval(mp_prec_t prec)
{
    /* min = 1/2 * 2^emin = 2^(emin - 1) */
    return mpRealInterval(1, prec) << mpRealInterval::get_emin()-1;
}

// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpRealInterval maxval(mp_prec_t prec)
{
    /* max = (1 - eps) * 2^emax, eps is machine epsilon */
    return (mpRealInterval(1, prec) - machine_epsilon(prec)) << mpRealInterval::get_emax();
}

inline bool isEqualUlps(const mpRealInterval& a, const mpRealInterval& b, int maxUlps)
{
  return abs(a - b) <= machine_epsilon((max)(abs(a), abs(b))) * maxUlps;
}

inline bool isEqualFuzzy(const mpRealInterval& a, const mpRealInterval& b, const mpRealInterval& eps)
{
    return abs(a - b) <= (min)(abs(a), abs(b)) * eps;
}

inline bool isEqualFuzzy(const mpRealInterval& a, const mpRealInterval& b)
{
    return isEqualFuzzy(a, b, machine_epsilon((min)(abs(a), abs(b))));
}


inline const mpRealInterval modf(const mpRealInterval& v, mpRealInterval& n)
{
//    mpRealInterval frac(v);
//
//    // rounding is not important since we are using the same number
//    mpfi_frac(frac.mp,frac.mp);
//    mpfi_trunc(n.mp,v.mp);
//    return frac;
    return mpRealInterval("999.999");
}

inline int mpRealInterval::check_range (int t, mp_rnd_t rnd_mode)
{
 //   return mpfi_check_range(mp,t,rnd_mode);
    return 999;
}

inline int mpRealInterval::subnormalize (int t,mp_rnd_t rnd_mode)
{
//    int r = mpfi_subnormalize(mp,t,rnd_mode);
//    mpRealInterval_MSVC_DEBUGVIEW_CODE;
//    return r;
    return 999999;
}





inline mp_exp_t mpRealInterval::get_emin (void)
{
    return mpfr_get_emin();
}

inline int mpRealInterval::set_emin (mp_exp_t exp)
{
    return mpfr_set_emin(exp);
}

inline mp_exp_t mpRealInterval::get_emax (void)
{
    return mpfr_get_emax();
}

inline int mpRealInterval::set_emax (mp_exp_t exp)
{
    return mpfr_set_emax(exp);
}

inline mp_exp_t mpRealInterval::get_emin_min (void)
{
    return mpfr_get_emin_min();
}

inline mp_exp_t mpRealInterval::get_emin_max (void)
{
    return mpfr_get_emin_max();
}

inline mp_exp_t mpRealInterval::get_emax_min (void)
{
    return mpfr_get_emax_min();
}

inline mp_exp_t mpRealInterval::get_emax_max (void)
{
    return mpfr_get_emax_max();
}

//////////////////////////////////////////////////////////////////////////
// Mathematical Functions
//////////////////////////////////////////////////////////////////////////

/* DH Change
#define mpRealInterval_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpRealInterval y(0, mpfi_get_prec(x.mpfi_srcptr()));          \
        mpfi_##f(y.mpfi_ptr(), x.mpfi_srcptr(), r);           \
        return y;
*/
#define mpRealInterval_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpRealInterval y(0, mpfi_get_prec(x.mpfi_srcptr()));          \
        mpfi_##f(y.mpfi_ptr(), x.mpfi_srcptr());           \
        return y;


inline const mpRealInterval sqr  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sqr );    }
inline const mpRealInterval sqrt (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sqrt);    }


inline const mpRealInterval sqrt(const unsigned long int x, mp_rnd_t r)
{
//    mpRealInterval y;
//    mpfi_sqrt_ui(y.mpfi_ptr(), x, r);
//    return y;
    return sqrt(static_cast<unsigned long int>(x));
}


inline const mpRealInterval sqrt(const unsigned int v, mp_rnd_t rnd_mode)
{
    return sqrt(static_cast<unsigned long int>(v));
}

inline const mpRealInterval sqrt(const long int v, mp_rnd_t rnd_mode)
{
//    if (v>=0)   return sqrt(static_cast<unsigned long int>(v),rnd_mode);
//    else        return mpRealInterval().setNan(); // NaN
    return mpRealInterval("999.999");

}

inline const mpRealInterval sqrt(const int v)
{
    if (v>=0)   return sqrt(static_cast<unsigned long int>(v));
    else        return mpRealInterval().setNan(); // NaN
}


inline const mpRealInterval root(const mpRealInterval& x, unsigned long int k)
{
//    mpRealInterval y(0, mpfi_get_prec(x.mpfi_srcptr()));
//    mpfi_root(y.mpfi_ptr(), x.mpfi_srcptr(), k, r);
//    return y;
    return mpRealInterval("999.999");

}

inline const mpRealInterval dim(const mpRealInterval& a, const mpRealInterval& b)
{
//    mpRealInterval y(0, mpfi_get_prec(a.mpfi_srcptr()));
//    mpfi_dim(y.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr(), r);
//    return y;
    return mpRealInterval("999.999");

}


inline const mpRealInterval fdim(const mpRealInterval& a, const mpRealInterval& b)
{
//    mpRealInterval y(0, mpfi_get_prec(a.mpfi_srcptr()));
//    mpfi_dim(y.mpfi_ptr(), a.mpfi_srcptr(), b.mpfi_srcptr(), r);
//    return y;
    return mpRealInterval("999.999");

}


inline int cmpabs(const mpRealInterval& a,const mpRealInterval& b)
{
//    return mpfi_cmpabs(a.mp,b.mp);
    return 999999;

}

inline int sin_cos(mpRealInterval& s, mpRealInterval& c, const mpRealInterval& v, mp_rnd_t rnd_mode)
{
 //   return mpfi_sin_cos(s.mp,c.mp,v.mp,rnd_mode);
     return 999999;

}

inline const mpRealInterval sqrt  (const long double v, mp_rnd_t rnd_mode)    {   return sqrt(mpRealInterval(v),rnd_mode);    }
inline const mpRealInterval sqrt  (const double v, mp_rnd_t rnd_mode)         {   return sqrt(mpRealInterval(v),rnd_mode);    }




inline const mpRealInterval cbrt  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(cbrt );    }
inline const mpRealInterval fabs  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs  );    }
inline const mpRealInterval abs   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs  );    }
inline const mpRealInterval log   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(log  );    }
inline const mpRealInterval log2  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(log2 );    }
// Change DH Begin
inline const mpRealInterval logb  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(log2 );    }
// Change DH End
inline const mpRealInterval log10 (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(log10);    }
inline const mpRealInterval exp   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(exp  );    }
inline const mpRealInterval exp2  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(exp2 );    }
inline const mpRealInterval exp10 (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);    }
inline const mpRealInterval cos   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(cos  );    }
inline const mpRealInterval sin   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sin  );    }
inline const mpRealInterval tan   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(tan  );    }
inline const mpRealInterval sec   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sec  );    }
inline const mpRealInterval csc   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(csc  );    }
inline const mpRealInterval cot   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(cot  );    }
inline const mpRealInterval acos  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(acos);     }
inline const mpRealInterval asin  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(asin);     }
inline const mpRealInterval atan  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(atan);     }

inline const mpRealInterval acot  (const mpRealInterval& v, mp_rnd_t r) {   return atan (1/v, r);                      }
inline const mpRealInterval asec  (const mpRealInterval& v, mp_rnd_t r) {   return acos (1/v, r);                      }
inline const mpRealInterval acsc  (const mpRealInterval& v, mp_rnd_t r) {   return asin (1/v, r);                      }
inline const mpRealInterval acoth (const mpRealInterval& v, mp_rnd_t r) {   return atanh(1/v, r);                      }
inline const mpRealInterval asech (const mpRealInterval& v, mp_rnd_t r) {   return acosh(1/v, r);                      }
inline const mpRealInterval acsch (const mpRealInterval& v, mp_rnd_t r) {   return asinh(1/v, r);                      }

inline const mpRealInterval cosh  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(cosh );    }
inline const mpRealInterval sinh  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sinh );    }
inline const mpRealInterval tanh  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(tanh );    }
inline const mpRealInterval sech  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(sech );    }
inline const mpRealInterval csch  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(csch );    }
inline const mpRealInterval coth  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(coth );    }
inline const mpRealInterval acosh (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(acosh);    }
inline const mpRealInterval asinh (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(asinh);    }
inline const mpRealInterval atanh (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(atanh);    }

inline const mpRealInterval log1p   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(log1p  );    }
inline const mpRealInterval expm1   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(expm1  );    }

inline const mpRealInterval eint    (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs   );    }
inline const mpRealInterval gamma   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs  );    }
// Change DH Begin
inline const mpRealInterval tgamma   (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs  );    }
// Change DH End


inline const mpRealInterval lngamma (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);    }
inline const mpRealInterval zeta    (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs   );    }
inline const mpRealInterval erf     (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs    );    }
inline const mpRealInterval erfc    (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs   );    }
inline const mpRealInterval besselj0(const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs     );    }
inline const mpRealInterval besselj1(const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs     );    }
inline const mpRealInterval bessely0(const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs     );    }
inline const mpRealInterval bessely1(const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs     );    }


inline const mpRealInterval sign (const mpRealInterval& v)
{
//    int s = mpfr_sgn(v.mp);
    mpRealInterval x(1);
    return x;
}


inline const mpRealInterval atan2 (const mpRealInterval& y, const mpRealInterval& x, mp_rnd_t rnd_mode)
{
    mpRealInterval a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpfi_atan2(a.mp, y.mp, x.mp);

    return a;
}


inline const mpRealInterval hypot (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
    mpRealInterval a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpfi_hypot(a.mp, x.mp, y.mp);

    return a;
}


inline const mpRealInterval copysign (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
    mpRealInterval a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    mpfi_hypot(a.mp, x.mp, y.mp);

    return a;
}



inline const mpRealInterval remainder (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    mpfi_remainder(a.mp, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpRealInterval("999.999");

}

inline const mpRealInterval remquo (long* q, const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    mpfi_remquo(a.mp,q, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpRealInterval("999.999");

}

// Change DH Begin
inline const mpRealInterval remquo (const mpRealInterval& x, const mpRealInterval& y, int* q, mp_rnd_t rnd_mode)
{
    return mpRealInterval("999.999");
}
// Change DH End





inline const mpRealInterval fac_ui (unsigned long int v, mp_prec_t prec, mp_rnd_t rnd_mode)
{
//    mpRealInterval x(0, prec);
//    mpfi_fac_ui(x.mp,v,rnd_mode);
//    return x;
    return mpRealInterval("999.999");

}


inline const mpRealInterval lgamma (const mpRealInterval& v, int *signp, mp_rnd_t rnd_mode)
{
//    mpRealInterval x(v);
//    int tsignp;
//
//    if(signp)   mpfi_lgamma(x.mp,signp,v.mp,rnd_mode);
//    else        mpfi_lgamma(x.mp,&tsignp,v.mp,rnd_mode);
//
//    return x;
    return mpRealInterval("999.999");

}


inline const mpRealInterval besseljn (long n, const mpRealInterval& x, mp_rnd_t r)
{
//    mpRealInterval  y(0, mpfi_get_prec(x.mpfi_srcptr()));
//    mpfi_jn(y.mpfi_ptr(), n, x.mpfi_srcptr(), r);
//    return y;
    return mpRealInterval("999.999");

}

inline const mpRealInterval besselyn (long n, const mpRealInterval& x, mp_rnd_t r)
{
//    mpRealInterval  y(0, mpfi_get_prec(x.mpfi_srcptr()));
//    mpfi_yn(y.mpfi_ptr(), n, x.mpfi_srcptr(), r);
//    return y;
    return mpRealInterval("999.999");

}

inline const mpRealInterval fma (const mpRealInterval& v1, const mpRealInterval& v2, const mpRealInterval& v3, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t p1, p2, p3;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//    p3 = v3.get_prec();
//
//    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));
//
//    mpfi_fma(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
//    return a;
    return mpRealInterval("999.999");

}

inline const mpRealInterval fms (const mpRealInterval& v1, const mpRealInterval& v2, const mpRealInterval& v3, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t p1, p2, p3;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//    p3 = v3.get_prec();
//
//    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));
//
//    mpfi_fms(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
//    return a;
    return mpRealInterval("999.999");

}

inline const mpRealInterval agm (const mpRealInterval& v1, const mpRealInterval& v2, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t p1, p2;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//
//    a.set_prec(p1>p2?p1:p2);
//
//    mpfi_agm(a.mp, v1.mp, v2.mp, rnd_mode);
//
//    return a;
    return mpRealInterval("999.999");

}

inline const mpRealInterval sum (const mpRealInterval tab[], unsigned long int n, mp_rnd_t rnd_mode)
{
//    mpRealInterval x;
//    mpfi_ptr* t;
//    unsigned long int i;
//
//    t = new mpfi_ptr[n];
//    for (i=0;i<n;i++) t[i] = (mpfi_ptr)tab[i].mp;
//    mpfi_sum(x.mp,t,n,rnd_mode);
//    delete[] t;
//    return x;
    return mpRealInterval("999.999");

}

//////////////////////////////////////////////////////////////////////////
// mpfi 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline int sinh_cosh(mpRealInterval& s, mpRealInterval& c, const mpRealInterval& v, mp_rnd_t rnd_mode)
{
  //  return mpfi_sinh_cosh(s.mp,c.mp,v.mp,rnd_mode);
      return 999;

}

inline const mpRealInterval li2 (const mpRealInterval& x, mp_rnd_t r)
{
  //  mpRealInterval_UNARY_MATH_FUNCTION_BODY(li2);
      return mpRealInterval("999.999");

}


inline const mpRealInterval rem (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
    //  R = rem(X,Y) if Y != 0, returns X - n * Y where n = trunc(X/Y).
   // return fmod(x, y, rnd_mode);
       return mpRealInterval("999.999");

}

inline const mpRealInterval mod (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
    (void)rnd_mode;



//    m = mod(x,y) if y != 0, returns x - n*y where n = floor(x/y)
//
//    The following are true by convention:
//    - mod(x,0) is x
//    - mod(x,x) is 0
//    - mod(x,y) for x != y and y != 0 has the same sign as y.



//    if(iszero(y)) return x;
//    if(x == y) return 0;
//
//    mpRealInterval m = x - floor(x / y) * y;
//
//    m.setSign(sgn(y)); // make sure result has the same sign as Y
//
//    return m;
    return mpRealInterval("999.999");

}

inline const mpRealInterval fmod (const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    mpfi_fmod(a.mp, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpRealInterval("999.999");

}

inline const mpRealInterval rec_sqrt(const mpRealInterval& v, mp_rnd_t rnd_mode)
{
//    mpRealInterval x(v);
//    mpfi_rec_sqrt(x.mp,v.mp,rnd_mode);
//    return x;
    return mpRealInterval("999.999");

}
#endif //  mpfi 2.4.0 Specifics



//////////////////////////////////////////////////////////////////////////
// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
//inline const mpRealInterval digamma (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(digamma);     }
//inline const mpRealInterval ai      (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(ai);          }

inline const mpRealInterval digamma (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);     }
inline const mpRealInterval ai      (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);          }

#endif // mpfi 3.0.0 Specifics

//////////////////////////////////////////////////////////////////////////







// Constants
inline const mpRealInterval const_log2 (mp_prec_t p, mp_rnd_t r)
{
    mpRealInterval x(0, p);
    mpfi_const_log2(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_pi (mp_prec_t p, mp_rnd_t r)
{
    mpRealInterval x(0, p);
    mpfi_const_pi(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_euler (mp_prec_t p, mp_rnd_t r)
{
    mpRealInterval x(0, p);
    mpfi_const_euler(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_catalan (mp_prec_t p, mp_rnd_t r)
{
    mpRealInterval x(0, p);
    mpfi_const_catalan(x.mpfi_ptr());
    return x;
}


// Change DH
inline const mpRealInterval const_log2_a (const mpRealInterval& temp)
{
    mpRealInterval x(0, mpRealInterval::get_default_prec());
    mpfi_const_log2(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_pi_a (const mpRealInterval& temp)
{
    mpRealInterval x(0, mpRealInterval::get_default_prec());
    mpfi_const_pi(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_euler_gamma_a (const mpRealInterval& temp)
{
    mpRealInterval x(0, mpRealInterval::get_default_prec());
    mpfi_const_euler(x.mpfi_ptr());
    return x;
}

inline const mpRealInterval const_catalan_a (const mpRealInterval& temp)
{
    mpRealInterval x(0, mpRealInterval::get_default_prec());
    mpfi_const_catalan(x.mpfi_ptr());
    return x;
}

// End Change DH






/* Change DH */
inline const mpRealInterval const_infinity (int sign, mp_prec_t p, mp_rnd_t)
{
    mpRealInterval x(0, p);
    mpfr_t f;
    mpfr_init(f);
    mpfr_set_inf(f, sign);
    mpfi_set_fr(x.mpfi_ptr(), f);
    mpfr_clear(f);
    return x;
}


//////////////////////////////////////////////////////////////////////////
// Integer Related Functions
inline const mpRealInterval ceil(const mpRealInterval& v)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, v.mp);
    mpfr_ceil(br, ar);
    mpRealInterval x(br);
    return x;
}

inline const mpRealInterval floor(const mpRealInterval& v)
{
    mpfr_t ar, br;
    mpfr_init2(ar, mpRealInterval::get_default_prec());
    mpfr_init2(br, mpRealInterval::get_default_prec());
    mpfi_mid (ar, v.mp);
    mpfr_floor(br, ar);
    mpRealInterval x(br);
    return x;
}


inline const mpRealInterval round(const mpRealInterval& v)
{
//    mpRealInterval x(v);
//    mpfi_round(x.mp,v.mp);
//    return x;
    return mpRealInterval("999.999");
}

// Change DH Begin
inline const mpRealInterval lround(const mpRealInterval& v)
{
    return round(v);
}

inline const mpRealInterval llround(const mpRealInterval& v)
{
    return round(v);
}
// Change DH End



inline const mpRealInterval trunc(const mpRealInterval& v)
{
//    mpRealInterval x(v);
//    mpfi_trunc(x.mp,v.mp);
//    return x;
    return mpRealInterval("999.999");
}

//inline const mpRealInterval rint       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(rint      );     }
//inline const mpRealInterval rint_ceil  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(rint_ceil );     }
//inline const mpRealInterval rint_floor (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(rint_floor);     }
//inline const mpRealInterval rint_round (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(rint_round);     }
//inline const mpRealInterval rint_trunc (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(rint_trunc);     }
//inline const mpRealInterval frac       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(frac      );     }

inline const mpRealInterval rint       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs      );     }

// Change DH Begin
inline const mpRealInterval lrint       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs      );     }
inline const mpRealInterval llrint       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs      );     }
inline const mpRealInterval nearbyint       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs      );     }
// Change DH End


inline const mpRealInterval rint_ceil  (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs );     }
inline const mpRealInterval rint_floor (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);     }
inline const mpRealInterval rint_round (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);     }
inline const mpRealInterval rint_trunc (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs);     }
inline const mpRealInterval frac       (const mpRealInterval& x, mp_rnd_t r) {   mpRealInterval_UNARY_MATH_FUNCTION_BODY(abs      );     }


//////////////////////////////////////////////////////////////////////////
// Miscellaneous Functions
inline void         swap (mpRealInterval& a, mpRealInterval& b)            {    mpfi_swap(a.mp,b.mp);   }
inline const mpRealInterval (max)(const mpRealInterval& x, const mpRealInterval& y){    return (x>y?x:y);       }
inline const mpRealInterval (min)(const mpRealInterval& x, const mpRealInterval& y){    return (x<y?x:y);       }

inline const mpRealInterval fmax(const mpRealInterval& x, const mpRealInterval& y, mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mpfi_max(a.mp,x.mp,y.mp,rnd_mode);
//    return a;
    return mpRealInterval("999.999");
}

inline const mpRealInterval fmin(const mpRealInterval& x, const mpRealInterval& y,  mp_rnd_t rnd_mode)
{
//    mpRealInterval a;
//    mpfi_min(a.mp,x.mp,y.mp,rnd_mode);
//    return a;
    return mpRealInterval("999.999");
}

inline const mpRealInterval nexttoward (const mpRealInterval& x, const mpRealInterval& y)
{
//    mpRealInterval a(x);
//    mpfi_nexttoward(a.mp,y.mp);
//    return a;
    return mpRealInterval("999.999");
}

inline const mpRealInterval nextafter (const mpRealInterval& x, const mpRealInterval& y)
{
//    mpRealInterval a(x);
//    mpfi_nexttoward(a.mp,y.mp);
//    return a;
    return mpRealInterval("999.999");
}



inline const mpRealInterval nextabove  (const mpRealInterval& x)
{
//    mpRealInterval a(x);
//    mpfi_nextabove(a.mp);
//    return a;
    return mpRealInterval("999.999");
}

inline const mpRealInterval nextbelow  (const mpRealInterval& x)
{
//    mpRealInterval a(x);
//    mpfi_nextbelow(a.mp);
//    return a;
    return mpRealInterval("999.999");
}





inline const mpRealInterval urandomb (gmp_randstate_t& state)
{
    mpRealInterval x;
    mpfr_t f;
    mpfr_init(f);
    mpfr_urandomb(f,state);
    x = f;
    mpfr_clear(f);
    return x;
}

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
// use gmp_randinit_default() to init state, gmp_randclear() to clear
inline const mpRealInterval urandom (gmp_randstate_t& state, mp_rnd_t rnd_mode)
{
    mpRealInterval x;
    mpfr_t f;
    mpfr_init(f);
    mpfr_urandom(f,state,rnd_mode);
    x = f;
    mpfr_clear(f);
    return x;
}
#endif

#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
inline const mpRealInterval random2 (mp_size_t size, mp_exp_t exp)
{
//    mpRealInterval x;
//    mpfi_random2(x.mp,size,exp);
//    return x;
    return mpRealInterval("999.999");
}
#endif

// Uniformly distributed random number generation
// a = random(seed); <- initialization & first random number generation
// a = random();     <- next random numbers generation
// seed != 0
inline const mpRealInterval random(unsigned int seed)
{

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    static gmp_randstate_t state;
    static bool isFirstTime = true;

    if(isFirstTime)
    {
        gmp_randinit_default(state);
        gmp_randseed_ui(state,0);
        isFirstTime = false;
    }

    if(seed != 0)    gmp_randseed_ui(state,seed);

    return mpfi::urandom(state, mpRealInterval::get_default_rnd());
#else
    if(seed != 0)    std::srand(seed);
    return mpfi::mpRealInterval(std::rand()/(double)RAND_MAX);
#endif

}



//////////////////////////////////////////////////////////////////////////
// Set/Get global properties
inline void mpRealInterval::set_default_prec(mp_prec_t prec)
{
    //mpfr_set_default_prec(prec);
}

inline void mpRealInterval::set_default_rnd(mp_rnd_t rnd_mode)
{
    //mpfr_set_default_rounding_mode(rnd_mode);
}

inline bool mpRealInterval::fits_in_bits(double x, int n)
{
    int i;
    double t;
    return IsInf(x) || (std::modf ( std::ldexp ( std::frexp ( x, &i ), n ), &t ) == 0.0);
}

inline const mpRealInterval pow(const mpRealInterval& a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    /*Change DH */
    mpRealInterval x(a);
//    mpfi_pow(x.mp,x.mp,b.mp,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const mpRealInterval& a, const mpz_t b, mp_rnd_t rnd_mode)
{
    /*Change DH */
    mpRealInterval x(a);
//    mpfi_pow(x.mp,x.mp,b.mp,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const mpRealInterval& a, const unsigned long int b, mp_rnd_t rnd_mode)
{
       /*Change DH */
    mpRealInterval x(a);
//    mpfi_pow_ui(x.mp,x.mp,b,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const mpRealInterval& a, const unsigned int b, mp_rnd_t rnd_mode)
{
    return pow(a,static_cast<unsigned long int>(b),rnd_mode);
}

inline const mpRealInterval pow(const mpRealInterval& a, const long int b, mp_rnd_t rnd_mode)
{
       /*Change DH */
    mpRealInterval x(a);
//    mpfi_pow_si(x.mp,x.mp,b,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const mpRealInterval& a, const int b, mp_rnd_t rnd_mode)
{
    return pow(a,static_cast<long int>(b),rnd_mode);
}


inline const mpRealInterval pow(const mpRealInterval& a, const long double b, mp_rnd_t rnd_mode)
{
   // return pow(a,mpRealInterval(b),rnd_mode);
       return mpRealInterval("999.999");
}



inline const mpRealInterval pow(const mpRealInterval& a, const double b, mp_rnd_t rnd_mode)
{
    return pow(a,mpRealInterval(b),rnd_mode);
}

inline const mpRealInterval pow(const unsigned long int a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
       /*Change DH */
    mpRealInterval x(a);
//    mpfi_ui_pow(x.mp,a,b.mp,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const unsigned int a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    return pow(static_cast<unsigned long int>(a),b,rnd_mode);
}

inline const mpRealInterval pow(const long int a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    if (a>=0)     return pow(static_cast<unsigned long int>(a),b,rnd_mode);
    else        return pow(mpRealInterval(a),b,rnd_mode);
}

inline const mpRealInterval pow(const int a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    if (a>=0)     return pow(static_cast<unsigned long int>(a),b,rnd_mode);
    else        return pow(mpRealInterval(a),b,rnd_mode);
}


inline const mpRealInterval pow(const long double a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode);
}


inline const mpRealInterval pow(const double a, const mpRealInterval& b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode);
}

// pow unsigned long int
inline const mpRealInterval pow(const unsigned long int a, const unsigned long int b, mp_rnd_t rnd_mode)
{
       /*Change DH */
    mpRealInterval x(a);
//    mpfi_ui_pow_ui(x.mp,a,b,rnd_mode);
    x = exp(a * log(b));
    return x;
}

inline const mpRealInterval pow(const unsigned long int a, const unsigned int b, mp_rnd_t rnd_mode)
{
    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
}

inline const mpRealInterval pow(const unsigned long int a, const long int b, mp_rnd_t rnd_mode)
{
    if(b>0)    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
    else    return pow(a,mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}

inline const mpRealInterval pow(const unsigned long int a, const int b, mp_rnd_t rnd_mode)
{
    if(b>0)    return pow(a,static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
    else    return pow(a,mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}


inline const mpRealInterval pow(const unsigned long int a, const long double b, mp_rnd_t rnd_mode)
{
    return pow(a,mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}


inline const mpRealInterval pow(const unsigned long int a, const double b, mp_rnd_t rnd_mode)
{
    return pow(a,mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}

// pow unsigned int
inline const mpRealInterval pow(const unsigned int a, const unsigned long int b, mp_rnd_t rnd_mode)
{
    return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpfi_ui_pow_ui
}

inline const mpRealInterval pow(const unsigned int a, const unsigned int b, mp_rnd_t rnd_mode)
{
    return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
}

inline const mpRealInterval pow(const unsigned int a, const long int b, mp_rnd_t rnd_mode)
{
    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
    else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}

inline const mpRealInterval pow(const unsigned int a, const int b, mp_rnd_t rnd_mode)
{
    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
    else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}


inline const mpRealInterval pow(const unsigned int a, const long double b, mp_rnd_t rnd_mode)
{
    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}

inline const mpRealInterval pow(const unsigned int a, const double b, mp_rnd_t rnd_mode)
{
    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
}

// pow long int
inline const mpRealInterval pow(const long int a, const unsigned long int b, mp_rnd_t rnd_mode)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpfi_ui_pow_ui
    else     return pow(mpRealInterval(a),b,rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const long int a, const unsigned int b, mp_rnd_t rnd_mode)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode);  //mpfi_ui_pow_ui
    else     return pow(mpRealInterval(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const long int a, const long int b, mp_rnd_t rnd_mode)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    }else{
        return pow(mpRealInterval(a),b,rnd_mode); // mpfi_pow_si
    }
}

inline const mpRealInterval pow(const long int a, const int b, mp_rnd_t rnd_mode)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    }else{
        return pow(mpRealInterval(a),static_cast<long int>(b),rnd_mode); // mpfi_pow_si
    }
}


inline const mpRealInterval pow(const long int a, const long double b, mp_rnd_t rnd_mode)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    else        return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode); //mpfi_pow
}

inline const mpRealInterval pow(const long int a, const double b, mp_rnd_t rnd_mode)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    else        return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode); //mpfi_pow
}

// pow int
inline const mpRealInterval pow(const int a, const unsigned long int b, mp_rnd_t rnd_mode)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),b,rnd_mode); //mpfi_ui_pow_ui
    else     return pow(mpRealInterval(a),b,rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const int a, const unsigned int b, mp_rnd_t rnd_mode)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode);  //mpfi_ui_pow_ui
    else     return pow(mpRealInterval(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const int a, const long int b, mp_rnd_t rnd_mode)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    }else{
        return pow(mpRealInterval(a),b,rnd_mode); // mpfi_pow_si
    }
}

inline const mpRealInterval pow(const int a, const int b, mp_rnd_t rnd_mode)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    }else{
        return pow(mpRealInterval(a),static_cast<long int>(b),rnd_mode); // mpfi_pow_si
    }
}


inline const mpRealInterval pow(const int a, const long double b, mp_rnd_t rnd_mode)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    else        return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode); //mpfi_pow
}


inline const mpRealInterval pow(const int a, const double b, mp_rnd_t rnd_mode)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpRealInterval(b),rnd_mode); //mpfi_ui_pow
    else        return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode); //mpfi_pow
}

// pow long double

inline const mpRealInterval pow(const long double a, const long double b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode);
}


inline const mpRealInterval pow(const long double a, const unsigned long int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const long double a, const unsigned int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),static_cast<unsigned long int>(b),rnd_mode); //mpfi_pow_ui
}

inline const mpRealInterval pow(const long double a, const long int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode); // mpfi_pow_si
}

inline const mpRealInterval pow(const long double a, const int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),static_cast<long int>(b),rnd_mode); // mpfi_pow_si
}



inline const mpRealInterval pow(const double a, const double b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),mpRealInterval(b),rnd_mode);
}

inline const mpRealInterval pow(const double a, const unsigned long int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode); // mpfi_pow_ui
}

inline const mpRealInterval pow(const double a, const unsigned int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),static_cast<unsigned long int>(b),rnd_mode); // mpfi_pow_ui
}

inline const mpRealInterval pow(const double a, const long int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),b,rnd_mode); // mpfi_pow_si
}

inline const mpRealInterval pow(const double a, const int b, mp_rnd_t rnd_mode)
{
    return pow(mpRealInterval(a),static_cast<long int>(b),rnd_mode); // mpfi_pow_si
}
} // End of mpfi namespace


// Explicit specialization of std::swap for mpRealInterval numbers
// Thus standard algorithms will use efficient version of swap (due to Koenig lookup)
// Non-throwing swap C++ idiom: http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-throwing_swap
namespace std
{
//	 only allowed to extend namespace std with specializations
//    template <>
//    inline void swap(mpfi::mpRealInterval& x, mpfi::mpRealInterval& y)
//    {
//        return mpfi_swap(x.mp, y.mp);
//    }

    template<>
    class numeric_limits<mpfi::mpRealInterval>
    {
    public:
        static const bool is_specialized    = true;
        static const bool is_signed         = true;
        static const bool is_integer        = false;
        static const bool is_exact          = false;
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

        inline static float_round_style round_style()
        {
            mp_rnd_t r = mpfi::mpRealInterval::get_default_rnd();

            switch (r)
            {
                case MPFR_RNDN: return round_to_nearest;
                case MPFR_RNDZ: return round_toward_zero;
                case MPFR_RNDU: return round_toward_infinity;
                case MPFR_RNDD: return round_toward_neg_infinity;
                default: return round_indeterminate;
            }
        }

        inline static mpfi::mpRealInterval (min)    (mp_prec_t precision = mpfi::mpRealInterval::get_default_prec()) {  return  mpfi::minval(precision);  }
        inline static mpfi::mpRealInterval (max)    (mp_prec_t precision = mpfi::mpRealInterval::get_default_prec()) {  return  mpfi::maxval(precision);  }
        inline static mpfi::mpRealInterval lowest   (mp_prec_t precision = mpfi::mpRealInterval::get_default_prec()) {  return -mpfi::maxval(precision);  }

        // Returns smallest eps such that 1 + eps != 1 (classic machine epsilon)
        inline static mpfi::mpRealInterval epsilon(mp_prec_t precision = mpfi::mpRealInterval::get_default_prec()) {  return  mpfi::machine_epsilon(precision); }

        // Returns smallest eps such that x + eps != x (relative machine epsilon)
        inline static mpfi::mpRealInterval epsilon(const mpfi::mpRealInterval& x) {  return mpfi::machine_epsilon(x);  }

        inline static mpfi::mpRealInterval round_error(mp_prec_t precision = mpfi::mpRealInterval::get_default_prec())
        {
            mp_rnd_t r = mpfi::mpRealInterval::get_default_rnd();

            if(r == MPFR_RNDN) return mpfi::mpRealInterval(0.5, precision);
            else               return mpfi::mpRealInterval(1.0, precision);
        }

        inline static const mpfi::mpRealInterval infinity()         { return mpfi::const_infinity();     }
        inline static const mpfi::mpRealInterval quiet_NaN()        { return mpfi::mpRealInterval().setNan();    }
        inline static const mpfi::mpRealInterval signaling_NaN()    { return mpfi::mpRealInterval().setNan();    }
        inline static const mpfi::mpRealInterval denorm_min()       { return (min)();                    }

        // Please note, exponent range is not fixed in mpfi
        static const int min_exponent = MPFR_EMIN_DEFAULT;
        static const int max_exponent = MPFR_EMAX_DEFAULT;
        mpRealInterval_PERMISSIVE_EXPR static const int min_exponent10 = (int) (MPFR_EMIN_DEFAULT * 0.3010299956639811);
        mpRealInterval_PERMISSIVE_EXPR static const int max_exponent10 = (int) (MPFR_EMAX_DEFAULT * 0.3010299956639811);

        // Should be constant according to standard, but 'digits' depends on precision in mpfi

        inline static int digits()                        {    return mpfi::mpRealInterval::get_default_prec();    }
        inline static int digits(const mpfi::mpRealInterval& x)   {    return x.getPrecision();                    }

        inline static int digits10(mp_prec_t precision = mpfi::mpRealInterval::get_default_prec())
        {
            return mpfi::bits2digits(precision);
        }

        inline static int digits10(const mpfi::mpRealInterval& x)
        {
            return mpfi::bits2digits(x.getPrecision());
        }

        inline static int max_digits10(mp_prec_t precision = mpfi::mpRealInterval::get_default_prec())
        {
            return digits10(precision);
        }
    };

}

#endif /* __mpRealInterval_H__ */
