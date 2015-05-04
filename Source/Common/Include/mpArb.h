/*
    Multi-precision floating point number class for C++.
    Based on mparb library:    http://mparb.org

    Project homepage:    http://www.holoborodko.com/pavel/mparb
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

#ifndef __arb_H__
#define __arb_H__

//#include <string>
//#include <iostream>
//#include <sstream>
#include <stdexcept>
#include <cfloat>
#include <cmath>
#include <limits>

// Options
#define arb_HAVE_INT64_SUPPORT               // Enable int64_t support if possible. Available only for MSVC 2010 & GCC.
#define arb_HAVE_MSVC_DEBUGVIEW              // Enable Debugger Visualizer for "Debug" builds in MSVC.

// Detect compiler using signatures from http://predef.sourceforge.net/
#if defined(__GNUC__) && defined(__INTEL_COMPILER)
    #define IsInf(x) isinf(x)                   // Intel ICC compiler on Linux

#elif defined(_MSC_VER)                         // Microsoft Visual C++
    #define IsInf(x) (!_finite(x))

#else
    #define IsInf(x) std::isinf(x)              // GNU C/C++ (and/or other compilers), just hope for C99 conformance
#endif

#if defined(arb_HAVE_INT64_SUPPORT)

    #define arb_USE_INTMAX_T                   // Should be defined before mparb.h

    #if defined(_MSC_VER)                       // MSVC + Windows
        #if (_MSC_VER >= 1600)
            #include <stdint.h>                 // <stdint.h> is available only in msvc2010!

        #else                                   // mparb relies on intmax_t which is available only in msvc2010
            #undef arb_HAVE_INT64_SUPPORT    // Besides, mparb & MPIR have to be compiled with msvc2010
            #undef arb_USE_INTMAX_T            // Since we cannot detect this, disable x64 by default
                                                // Someone should change this manually if needed.
        #endif

    #elif defined (__GNUC__) && defined(__linux__)
        #if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(__ia64) || defined(__itanium__) || defined(_M_IA64)
            #undef arb_HAVE_INT64_SUPPORT    // Remove all shaman dances for x64 builds since
            #undef arb_USE_INTMAX_T            // GCC already supports x64 as of "long int" is 64-bit integer, nothing left to do
        #else
            #include <stdint.h>                 // use int64_t, uint64_t otherwise
        #endif

    #else
        #include <stdint.h>                     // rely on int64_t, uint64_t in all other cases, Mac OSX, etc.
    #endif

#endif

#if defined(arb_HAVE_MSVC_DEBUGVIEW) && defined(_MSC_VER) && defined(_DEBUG)
#define arb_MSVC_DEBUGVIEW_CODE         DebugView = toString();
    #define arb_MSVC_DEBUGVIEW_DATA     std::string DebugView;
#else
    #define arb_MSVC_DEBUGVIEW_CODE
    #define arb_MSVC_DEBUGVIEW_DATA
#endif

#include <arb.h>

#if (MPFR_VERSION < MPFR_VERSION_NUM(3,0,0))
    #include <cstdlib>                          // Needed for random()
#endif

// Less important options
#define arb_DOUBLE_BITS_OVERFLOW -1          // Triggers overflow exception during conversion to double if mpArb
                                                // cannot fit in arb_DOUBLE_BITS_OVERFLOW bits
                                                // = -1 disables overflow checks (default)
#if defined(__GNUC__)
  #define arb_PERMISSIVE_EXPR __extension__
#else
  #define arb_PERMISSIVE_EXPR
#endif


namespace mparb {

class mpArb {
private:
    arb_t mp;
//    long prec;
public:

    // Get default rounding mode & precision
    inline static mp_rnd_t   get_default_rnd()    {    return (mp_rnd_t)(mpfr_get_default_rounding_mode());       }
    inline static mp_prec_t  get_default_prec()   {    return mpfr_get_default_prec();                            }

    // Constructors && type conversions
    mpArb();
    mpArb(const mpArb& u);
    mpArb(const arb_t u);
/* Change DH */
    mpArb(const mpfr_t u);

    mpArb(const fmpz_t u,             mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const fmpq_t u,             mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const double u,            mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());

    mpArb(const long double u,       mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const unsigned long int u, mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const unsigned int u,      mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const long int u,          mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const int u,               mp_prec_t prec = mpArb::get_default_prec(), mp_rnd_t mode = mpArb::get_default_rnd());

#if defined (arb_HAVE_INT64_SUPPORT)
    mpArb(const uint64_t u,          mp_prec_t prec = mpArb::get_default_prec(),  mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const int64_t u,           mp_prec_t prec = mpArb::get_default_prec(),  mp_rnd_t mode = mpArb::get_default_rnd());
#endif

    mpArb(const char* s,             mp_prec_t prec = mpArb::get_default_prec(), int base = 10, mp_rnd_t mode = mpArb::get_default_rnd());
    mpArb(const std::string& s,      mp_prec_t prec = mpArb::get_default_prec(), int base = 10, mp_rnd_t mode = mpArb::get_default_rnd());

    ~mpArb();

    // Operations
    // =
    // +, -, *, /, ++, --, <<, >>
    // *=, +=, -=, /=,
    // <, >, ==, <=, >=

    // =
    mpArb& operator=(const mpArb& v);
    mpArb& operator=(const mpfr_t v);
    mpArb& operator=(const fmpz_t v);
    mpArb& operator=(const fmpq_t v);
    mpArb& operator=(const long double v);
    mpArb& operator=(const double v);
    mpArb& operator=(const unsigned long int v);
    mpArb& operator=(const unsigned int v);
    mpArb& operator=(const long int v);
    mpArb& operator=(const int v);
    mpArb& operator=(const char* s);
    mpArb& operator=(const std::string& s);

    // +
    mpArb& operator+=(const mpArb& v);
    mpArb& operator+=(const mpfr_t v);
    mpArb& operator+=(const fmpz_t v);
//    mpArb& operator+=(const mpq_t v);
    mpArb& operator+=(const long double u);
    mpArb& operator+=(const double u);
    mpArb& operator+=(const unsigned long int u);
    mpArb& operator+=(const unsigned int u);
    mpArb& operator+=(const long int u);
    mpArb& operator+=(const int u);

#if defined (arb_HAVE_INT64_SUPPORT)
    mpArb& operator+=(const int64_t  u);
    mpArb& operator+=(const uint64_t u);
    mpArb& operator-=(const int64_t  u);
    mpArb& operator-=(const uint64_t u);
    mpArb& operator*=(const int64_t  u);
    mpArb& operator*=(const uint64_t u);
    mpArb& operator/=(const int64_t  u);
    mpArb& operator/=(const uint64_t u);
#endif

    const mpArb operator+() const;
    mpArb& operator++ ();
    const mpArb  operator++ (int);

    // -
    mpArb& operator-=(const mpArb& v);
    mpArb& operator-=(const fmpz_t v);
//    mpArb& operator-=(const mpq_t v);
    mpArb& operator-=(const long double u);
    mpArb& operator-=(const double u);
    mpArb& operator-=(const unsigned long int u);
    mpArb& operator-=(const unsigned int u);
    mpArb& operator-=(const long int u);
    mpArb& operator-=(const int u);
    const mpArb operator-() const;
    friend const mpArb operator-(const unsigned long int b, const mpArb& a);
    friend const mpArb operator-(const unsigned int b,      const mpArb& a);
    friend const mpArb operator-(const long int b,          const mpArb& a);
    friend const mpArb operator-(const int b,               const mpArb& a);
    friend const mpArb operator-(const double b,            const mpArb& a);
    mpArb& operator-- ();
    const mpArb  operator-- (int);

    // *
    mpArb& operator*=(const mpArb& v);
    mpArb& operator*=(const fmpz_t v);
//    mpArb& operator*=(const mpq_t v);
    mpArb& operator*=(const long double v);
    mpArb& operator*=(const double v);
    mpArb& operator*=(const unsigned long int v);
    mpArb& operator*=(const unsigned int v);
    mpArb& operator*=(const long int v);
    mpArb& operator*=(const int v);

    // /
    mpArb& operator/=(const mpArb& v);
    mpArb& operator/=(const fmpz_t v);
//    mpArb& operator/=(const mpq_t v);
    mpArb& operator/=(const long double v);
    mpArb& operator/=(const double v);
    mpArb& operator/=(const unsigned long int v);
    mpArb& operator/=(const unsigned int v);
    mpArb& operator/=(const long int v);
    mpArb& operator/=(const int v);
    friend const mpArb operator/(const unsigned long int b, const mpArb& a);
    friend const mpArb operator/(const unsigned int b,      const mpArb& a);
    friend const mpArb operator/(const long int b,          const mpArb& a);
    friend const mpArb operator/(const int b,               const mpArb& a);
    friend const mpArb operator/(const double b,            const mpArb& a);

//    //<<= Fast Multiplication by 2^u
//    mpArb& operator<<=(const unsigned long int u);
//    mpArb& operator<<=(const unsigned int u);
//    mpArb& operator<<=(const long int u);
//    mpArb& operator<<=(const int u);
//
//    //>>= Fast Division by 2^u
//    mpArb& operator>>=(const unsigned long int u);
//    mpArb& operator>>=(const unsigned int u);
//    mpArb& operator>>=(const long int u);
//    mpArb& operator>>=(const int u);

    // Boolean Operators
    friend bool operator >  (const mpArb& a, const mpArb& b);
    friend bool operator >= (const mpArb& a, const mpArb& b);
    friend bool operator <  (const mpArb& a, const mpArb& b);
    friend bool operator <= (const mpArb& a, const mpArb& b);
    friend bool operator == (const mpArb& a, const mpArb& b);
    friend bool operator != (const mpArb& a, const mpArb& b);

    // Optimized specializations for boolean operators
    friend bool operator == (const mpArb& a, const unsigned long int b);
    friend bool operator == (const mpArb& a, const unsigned int b);
    friend bool operator == (const mpArb& a, const long int b);
    friend bool operator == (const mpArb& a, const int b);
    friend bool operator == (const mpArb& a, const long double b);
    friend bool operator == (const mpArb& a, const double b);

    // Type Conversion operators
    long            toLong      (mp_rnd_t mode = GMP_RNDZ)    const;
    unsigned long   toULong     (mp_rnd_t mode = GMP_RNDZ)    const;
    double          toDouble    (mp_rnd_t mode = GMP_RNDN)    const;
    long double     toLDouble   (mp_rnd_t mode = GMP_RNDN)    const;

#if defined (arb_HAVE_INT64_SUPPORT)
    int64_t         toInt64     (mp_rnd_t mode = GMP_RNDZ)    const;
    uint64_t        toUInt64    (mp_rnd_t mode = GMP_RNDZ)    const;
#endif

    // Get raw pointers so that mpArb can be directly used in raw arb_* functions
    ::arb_ptr    arb_ptr();
    ::arb_srcptr arb_ptr()    const;
    ::arb_srcptr arb_srcptr() const;

    // Convert mpArb to string with n significant digits in base b
    // n = 0 -> convert with the maximum available digits
    std::string        toString(int n = 0, int b = 10, mp_rnd_t mode = mpArb::get_default_rnd()) const;

#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    std::string        toString(const std::string& format) const;
#endif

    // Math Functions
    friend const mpArb sqr (const mpArb& v);
    friend const mpArb sqrt(const mpArb& v);
    friend const mpArb sqrt(const unsigned long int v);
    friend const mpArb cbrt(const mpArb& v);
    friend const mpArb root(const mpArb& v, unsigned long int k);
    friend const mpArb pow (const mpArb& a, const mpArb& b);
    friend const mpArb pow (const mpArb& a, const mpz_t b);
    friend const mpArb pow (const mpArb& a, const unsigned long int b);
    friend const mpArb pow (const mpArb& a, const long int b);
    friend const mpArb pow (const unsigned long int a, const mpArb& b);
    friend const mpArb pow (const unsigned long int a, const unsigned long int b);
    friend const mpArb fabs(const mpArb& v);

    friend const mpArb abs(const mpArb& v);
    friend const mpArb dim(const mpArb& a, const mpArb& b);
// Change DH Begin
    friend const mpArb fdim(const mpArb& a, const mpArb& b);
// Change DH End

    friend inline const mpArb mul_2ui(const mpArb& v, unsigned long int k);
    friend inline const mpArb mul_2si(const mpArb& v, long int k);
    friend inline const mpArb div_2ui(const mpArb& v, unsigned long int k);
    friend inline const mpArb div_2si(const mpArb& v, long int k);
    friend int cmpabs(const mpArb& a,const mpArb& b);

    friend const mpArb log  (const mpArb& v);
    friend const mpArb log2 (const mpArb& v);

 // Change DH Begin
     friend const mpArb logb (const mpArb& v);
// Change DH End


    friend const mpArb log10(const mpArb& v);
    friend const mpArb exp  (const mpArb& v);
    friend const mpArb exp2 (const mpArb& v);
    friend const mpArb exp10(const mpArb& v);
    friend const mpArb log1p(const mpArb& v);
    friend const mpArb expm1(const mpArb& v);

    friend const mpArb cos(const mpArb& v);
    friend const mpArb sin(const mpArb& v);
    friend const mpArb tan(const mpArb& v);
    friend const mpArb sec(const mpArb& v);
    friend const mpArb csc(const mpArb& v);
    friend const mpArb cot(const mpArb& v);
    friend int sin_cos(mpArb& s, mpArb& c, const mpArb& v);

    friend const mpArb acos  (const mpArb& v);
    friend const mpArb asin  (const mpArb& v);
    friend const mpArb atan  (const mpArb& v);
    friend const mpArb atan2 (const mpArb& y, const mpArb& x);
    friend const mpArb acot  (const mpArb& v);
    friend const mpArb asec  (const mpArb& v);
    friend const mpArb acsc  (const mpArb& v);

    friend const mpArb cosh  (const mpArb& v);
    friend const mpArb sinh  (const mpArb& v);
    friend const mpArb tanh  (const mpArb& v);
    friend const mpArb sech  (const mpArb& v);
    friend const mpArb csch  (const mpArb& v);
    friend const mpArb coth  (const mpArb& v);
    friend const mpArb acosh (const mpArb& v);
    friend const mpArb asinh (const mpArb& v);
    friend const mpArb atanh (const mpArb& v);
    friend const mpArb acoth (const mpArb& v);
//    friend const mpArb asech (const mpArb& v);
//    friend const mpArb acsch (const mpArb& v);

    friend const mpArb hypot (const mpArb& x, const mpArb& y);
// Change DH Begin
    friend const mpArb copysign (const mpArb& x, const mpArb& y);
// Change DH End

    friend const mpArb fac_ui (unsigned long int v,  mp_prec_t prec = mpArb::get_default_prec());
    friend const mpArb eint   (const mpArb& v);

    friend const mpArb gamma    (const mpArb& v);
 // Change DH Begin
    friend const mpArb tgamma    (const mpArb& v);
 // Change DH End

    friend const mpArb lngamma  (const mpArb& v);
    friend const mpArb lgamma   (const mpArb& v, int *signp = 0);
    friend const mpArb zeta     (const mpArb& v);
    friend const mpArb erf      (const mpArb& v);
    friend const mpArb erfc     (const mpArb& v);
    friend const mpArb besselj0 (const mpArb& v);
    friend const mpArb besselj1 (const mpArb& v);
    friend const mpArb besseljn (long n, const mpArb& v);
    friend const mpArb bessely0 (const mpArb& v);
    friend const mpArb bessely1 (const mpArb& v);
    friend const mpArb besselyn (long n, const mpArb& v);
    friend const mpArb fma      (const mpArb& v1, const mpArb& v2, const mpArb& v3);
    friend const mpArb fms      (const mpArb& v1, const mpArb& v2, const mpArb& v3);
    friend const mpArb agm      (const mpArb& v1, const mpArb& v2);
    friend const mpArb sum      (const mpArb tab[], unsigned long int n);
    friend int sgn(const mpArb& v); // returns -1 or +1

// mparb 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    friend int          sinh_cosh   (mpArb& s, mpArb& c, const mpArb& v);
    friend const mpArb li2         (const mpArb& v);
    friend const mpArb fmod        (const mpArb& x, const mpArb& y);
    friend const mpArb rec_sqrt    (const mpArb& v);

    // MATLAB's semantic equivalents
    friend const mpArb rem (const mpArb& x, const mpArb& y); // Remainder after division
    friend const mpArb mod (const mpArb& x, const mpArb& y); // Modulus after division
#endif

/*
// mparb 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend const mpArb digamma (const mpArb& v,        mp_rnd_t rnd_mode = mpArb::get_default_rnd());
    friend const mpArb ai      (const mpArb& v,        mp_rnd_t rnd_mode = mpArb::get_default_rnd());
    friend const mpArb urandom (gmp_randstate_t& state);     // use gmp_randinit_default() to init state, gmp_randclear() to clear
#endif
*/
    // Uniformly distributed random number generation in [0,1] using
    // Mersenne-Twister algorithm by default.
    // Use parameter to setup seed, e.g.: random((unsigned)time(NULL))
    // Check urandom() for more precise control.
    friend const mpArb random(unsigned int seed = 0);


    // Exponent and mantissa manipulation
    friend const mpArb frexp(const mpArb& v, mp_exp_t* exp);
// Change DH Begin
    friend const mpArb frexp(const mpArb& v, int* exp);

    friend const mpArb ilogb(const mpArb& v);
// Change DH End


    friend const mpArb ldexp(const mpArb& v, mp_exp_t exp);
// Change DH Begin
    friend const mpArb ldexp(const mpArb& v, const mpArb& e);
    friend const mpArb scalbn(const mpArb& v, const mpArb& e);
    friend const mpArb scalbln(const mpArb& v, const mpArb& e);
// Change DH End




    // Splits mpArb value into fractional and integer parts.
    // Returns fractional part and stores integer part in n.
    friend const mpArb modf(const mpArb& v, mpArb& n);



    // Constants
    // don't forget to call arb_free_cache() for every thread where you are using const-functions
    friend const mpArb const_log2      (mp_prec_t prec = mpArb::get_default_prec());
    friend const mpArb const_pi        (mp_prec_t prec = mpArb::get_default_prec());
    friend const mpArb const_euler     (mp_prec_t prec = mpArb::get_default_prec());
    friend const mpArb const_catalan   (mp_prec_t prec = mpArb::get_default_prec());

    friend const mpArb const_log2_a      (const mpArb& v);
    friend const mpArb const_pi_a      (const mpArb& v);
    friend const mpArb const_euler_gamma_a      (const mpArb& v);
    friend const mpArb const_catalan_a      (const mpArb& v);




    // returns +inf iff sign>=0 otherwise -inf
    friend const mpArb const_infinity(int sign = 1, mp_prec_t prec = mpArb::get_default_prec());

    // Output/ Input
    friend std::ostream& operator<<(std::ostream& os, const mpArb& v);
    friend std::istream& operator>>(std::istream& is, mpArb& v);

    // Integer Related Functions
    friend const mpArb rint (const mpArb& v);

// Change DH Begin
    friend const mpArb lrint (const mpArb& v);
    friend const mpArb llrint (const mpArb& v);
    friend const mpArb nearbyint (const mpArb& v);
// Change DH End

    friend const mpArb ceil (const mpArb& v);
    friend const mpArb floor(const mpArb& v);
    friend const mpArb round(const mpArb& v);

// Change DH Begin
    friend const mpArb lround(const mpArb& v);
    friend const mpArb llround(const mpArb& v);

    friend const mpArb sign (const mpArb& v);


// Change DH End



    friend const mpArb trunc(const mpArb& v);
    friend const mpArb rint_ceil   (const mpArb& v);
    friend const mpArb rint_floor  (const mpArb& v);
    friend const mpArb rint_round  (const mpArb& v);
    friend const mpArb rint_trunc  (const mpArb& v);
    friend const mpArb frac        (const mpArb& v);
    friend const mpArb remainder   (         const mpArb& x, const mpArb& y);
    friend const mpArb remquo      (long* q, const mpArb& x, const mpArb& y);

// Change DH Begin
    friend const mpArb remquo      (const mpArb& x, const mpArb& y, int* q);
// Change DH End



    // Miscellaneous Functions
    friend const mpArb nexttoward (const mpArb& x, const mpArb& y);
// Change DH Begin
    friend const mpArb nextafter (const mpArb& x, const mpArb& y);
// Change DH End


    friend const mpArb nextabove  (const mpArb& x);
    friend const mpArb nextbelow  (const mpArb& x);

    // use gmp_randinit_default() to init state, gmp_randclear() to clear
    friend const mpArb urandomb (gmp_randstate_t& state);

// mparb < 2.4.2 Specifics
#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
    friend const mpArb random2 (mp_size_t size, mp_exp_t exp);
#endif

    // Instance Checkers
    friend bool isnan    (const mpArb& v);
    friend bool isinf    (const mpArb& v);
    friend bool isfinite (const mpArb& v);

    friend bool isnum    (const mpArb& v);
    friend bool iszero   (const mpArb& v);
    friend bool isint    (const mpArb& v);

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend bool isregular(const mpArb& v);
#endif

    // Set/Get instance properties
    inline mp_prec_t    get_prec() const;
    inline void         set_prec(mp_prec_t prec = get_default_rnd());    // Change precision with rounding mode

    // Aliases for get_prec(), set_prec() - needed for compatibility with std::complex<mpArb> interface
    inline mpArb&      setPrecision(int Precision, mp_rnd_t RoundingMode = get_default_rnd());
    inline int          getPrecision() const;

    // Set mpArb to +/- inf, NaN, +/-0
    mpArb&        setInf  (int Sign = +1);
    mpArb&        setNan  ();
    mpArb&        setZero (int Sign = +1);
    mpArb&        setSign (int Sign, mp_rnd_t RoundingMode = get_default_rnd());

    //Exponent
    mp_exp_t get_exp();
    int set_exp(mp_exp_t e);
    int check_range  (int t = get_default_rnd());
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

    // Efficient swapping of two mpArb values - needed for std algorithms
    friend void swap(mpArb& x, mpArb& y);

    friend const mpArb fmax(const mpArb& x, const mpArb& y);
    friend const mpArb fmin(const mpArb& x, const mpArb& y);

private:
    // Human friendly Debug Preview in Visual Studio.
    // Put one of these lines:
    //
    // mparb::mpArb=<DebugView>                                ; Show value only
    // mparb::mpArb=<DebugView>, <mp[0]._arb_prec,u>bits    ; Show value & precision
    //
    // at the beginning of
    // [Visual Studio Installation Folder]\Common7\Packages\Debugger\autoexp.dat
    arb_MSVC_DEBUGVIEW_DATA
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
inline mpArb::mpArb()
{
    arb_init(mp);
    arb_set_ui(mp,0);
//    prec = get_default_prec();

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const mpArb& u)
{
    arb_init(mp);
//    arb_init2(mp,arb_get_prec(u.mp));
    arb_set(mp,u.mp);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const arb_t u)
{
    arb_init(mp);
    arb_set(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

/* Change DH */
inline mpArb::mpArb(const mpfr_t u)
{
    arb_init(mp);
    arb_set_interval_mpfr(mp, u, u, get_default_prec());

    arb_MSVC_DEBUGVIEW_CODE;
}
/* End Change DH */

inline mpArb::mpArb(const fmpz_t u, mp_prec_t prec, mp_rnd_t mode)
{
//    arb_init2(mp,prec);

    arb_init(mp);
    arb_set_round_fmpz(mp, u, prec);

//    arb_set_z(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const fmpq_t u, mp_prec_t prec, mp_rnd_t mode)
{
    arb_init(mp);

    arb_set_fmpq(mp,u, prec);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const double u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_d(x, u, mode);

    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);


    arb_MSVC_DEBUGVIEW_CODE;
}

/* modified by DH */
inline mpArb::mpArb(const long double u, mp_prec_t prec, mp_rnd_t mode)
{
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_ld(x, u, mode);

    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);

    arb_MSVC_DEBUGVIEW_CODE;
}


inline mpArb::mpArb(const unsigned long int u, mp_prec_t prec, mp_rnd_t mode)
{
    arb_init(mp);
//    arb_init2(mp,prec);
    arb_set_ui(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const unsigned int u, mp_prec_t prec, mp_rnd_t mode)
{
    arb_init(mp);
    arb_set_ui(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const long int u, mp_prec_t prec, mp_rnd_t mode)
{
    arb_init(mp);
    arb_set_si(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const int u, mp_prec_t prec, mp_rnd_t mode)
{
    arb_init(mp);
    arb_set_si(mp,u);

    arb_MSVC_DEBUGVIEW_CODE;
}

#if defined (arb_HAVE_INT64_SUPPORT)
inline mpArb::mpArb(const uint64_t u, mp_prec_t prec, mp_rnd_t mode)
{
/* modified by DH */
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_uj(x, u, mode);


    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const int64_t u, mp_prec_t prec, mp_rnd_t mode)
{
    /* modified by DH */
    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_sj(x, u, mode);


    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);

    arb_MSVC_DEBUGVIEW_CODE;
}
#endif

inline mpArb::mpArb(const char* s, mp_prec_t prec, int base, mp_rnd_t mode)
{

    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_str(x, s, base, mode);


    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);


    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::mpArb(const std::string& s, mp_prec_t prec, int base, mp_rnd_t mode)
{


    mpfr_t x;

    mpfr_init2(x,prec);
    mpfr_set_str(x, s.c_str(), base, mode);


    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);


//    arb_init2(mp, prec);
//    arb_set_str(mp, s.c_str(), base);

    arb_MSVC_DEBUGVIEW_CODE;
}

inline mpArb::~mpArb()
{
    arb_clear(mp);
}

// internal namespace needed for template magic
namespace internal{

    // Use SFINAE to restrict arithmetic operations instantiation only for numeric types
    // This is needed for smooth integration with libraries based on expression templates, like Eigen.
    // TODO: Do the same for boolean operators.
    template <typename ArgumentType> struct result_type {};

    template <> struct result_type<mpArb>              {typedef mpArb type;};
    template <> struct result_type<mpz_t>               {typedef mpArb type;};
    template <> struct result_type<mpq_t>               {typedef mpArb type;};
    template <> struct result_type<long double>         {typedef mpArb type;};
    template <> struct result_type<double>              {typedef mpArb type;};
    template <> struct result_type<unsigned long int>   {typedef mpArb type;};
    template <> struct result_type<unsigned int>        {typedef mpArb type;};
    template <> struct result_type<long int>            {typedef mpArb type;};
    template <> struct result_type<int>                 {typedef mpArb type;};

#if defined (arb_HAVE_INT64_SUPPORT)
    template <> struct result_type<int64_t  >           {typedef mpArb type;};
    template <> struct result_type<uint64_t >           {typedef mpArb type;};
#endif
}

// + Addition
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator+(const mpArb& lhs, const Rhs& rhs){ return mpArb(lhs) += rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator+(const Lhs& lhs, const mpArb& rhs){ return mpArb(rhs) += lhs;    }

// - Subtraction
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator-(const mpArb& lhs, const Rhs& rhs){ return mpArb(lhs) -= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator-(const Lhs& lhs, const mpArb& rhs){ return mpArb(lhs) -= rhs;    }

// * Multiplication
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator*(const mpArb& lhs, const Rhs& rhs){ return mpArb(lhs) *= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator*(const Lhs& lhs, const mpArb& rhs){ return mpArb(rhs) *= lhs;    }

// / Division
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator/(const mpArb& lhs, const Rhs& rhs){ return mpArb(lhs) /= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator/(const Lhs& lhs, const mpArb& rhs){ return mpArb(lhs) /= rhs;    }

//////////////////////////////////////////////////////////////////////////
// sqrt
const mpArb sqrt(const unsigned int v);
const mpArb sqrt(const long int v);
const mpArb sqrt(const int v);
const mpArb sqrt(const long double v);
const mpArb sqrt(const double v);

//////////////////////////////////////////////////////////////////////////
// pow
const mpArb pow(const mpArb& a, const unsigned int b);
const mpArb pow(const mpArb& a, const int b);
const mpArb pow(const mpArb& a, const long double b);
const mpArb pow(const mpArb& a, const double b);

const mpArb pow(const unsigned int a, const mpArb& b);
const mpArb pow(const long int a, const mpArb& b);
const mpArb pow(const int a, const mpArb& b);
const mpArb pow(const long double a, const mpArb& b);
const mpArb pow(const double a, const mpArb& b);

const mpArb pow(const unsigned long int a, const unsigned int b);
const mpArb pow(const unsigned long int a, const long int b);
const mpArb pow(const unsigned long int a, const int b);
const mpArb pow(const unsigned long int a, const long double b);
const mpArb pow(const unsigned long int a, const double b);

const mpArb pow(const unsigned int a, const unsigned long int b);
const mpArb pow(const unsigned int a, const unsigned int b);
const mpArb pow(const unsigned int a, const long int b);
const mpArb pow(const unsigned int a, const int b);
const mpArb pow(const unsigned int a, const long double b);
const mpArb pow(const unsigned int a, const double b);

const mpArb pow(const long int a, const unsigned long int b);
const mpArb pow(const long int a, const unsigned int b);
const mpArb pow(const long int a, const long int b);
const mpArb pow(const long int a, const int b);
const mpArb pow(const long int a, const long double b);
const mpArb pow(const long int a, const double b);

const mpArb pow(const int a, const unsigned long int b);
const mpArb pow(const int a, const unsigned int b);
const mpArb pow(const int a, const long int b);
const mpArb pow(const int a, const int b);
const mpArb pow(const int a, const long double b);
const mpArb pow(const int a, const double b);

const mpArb pow(const long double a, const long double b);
const mpArb pow(const long double a, const unsigned long int b);
const mpArb pow(const long double a, const unsigned int b);
const mpArb pow(const long double a, const long int b);
const mpArb pow(const long double a, const int b);

const mpArb pow(const double a, const double b);
const mpArb pow(const double a, const unsigned long int b);
const mpArb pow(const double a, const unsigned int b);
const mpArb pow(const double a, const long int b);
const mpArb pow(const double a, const int b);

//////////////////////////////////////////////////////////////////////////
// Estimate machine epsilon for the given precision
// Returns smallest eps such that 1.0 + eps != 1.0
inline mpArb machine_epsilon(mp_prec_t prec = mpArb::get_default_prec());

// Returns smallest eps such that x + eps != x (relative machine epsilon)
inline mpArb machine_epsilon(const mpArb& x);

// Gives max & min values for the required precision,
// minval is 'safe' meaning 1 / minval does not overflow
// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpArb minval(mp_prec_t prec = mpArb::get_default_prec());
inline mpArb maxval(mp_prec_t prec = mpArb::get_default_prec());

// 'Dirty' equality check 1: |a-b| < min{|a|,|b|} * eps
inline bool isEqualFuzzy(const mpArb& a, const mpArb& b, const mpArb& eps);

// 'Dirty' equality check 2: |a-b| < min{|a|,|b|} * eps( min{|a|,|b|} )
inline bool isEqualFuzzy(const mpArb& a, const mpArb& b);

// 'Bitwise' equality check
//  maxUlps - a and b can be apart by maxUlps binary numbers.
inline bool isEqualUlps(const mpArb& a, const mpArb& b, int maxUlps);

//////////////////////////////////////////////////////////////////////////
//     Convert precision in 'bits' to decimal digits and vice versa.
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

inline mp_prec_t digits2bits(int d);
inline int       bits2digits(mp_prec_t b);

//////////////////////////////////////////////////////////////////////////
// min, max
const mpArb (max)(const mpArb& x, const mpArb& y);
const mpArb (min)(const mpArb& x, const mpArb& y);

//////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Operators - Assignment
inline mpArb& mpArb::operator=(const mpArb& v)
{
    if (this != &v)
    {
//		mp_prec_t tp = arb_get_prec(mp);
//		mp_prec_t vp = arb_get_prec(v.mp);
//
//		if(tp != vp){
//			arb_clear(mp);
//			arb_init2(mp, vp);
//		}

        arb_set(mp, v.mp);

        arb_MSVC_DEBUGVIEW_CODE;
    }
    return *this;
}

inline mpArb& mpArb::operator=(const mpfr_t v)
{

    arb_set_interval_mpfr(mp, v, v, get_default_prec());

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const fmpz_t v)
{
    arb_set_round_fmpz(mp, v, get_default_prec());

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const fmpq_t v)
{
    arb_set_fmpq(mp,v, get_default_prec());

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}


/* modified by DH */
inline mpArb& mpArb::operator=(const long double v)
{
    mpfr_t x;

    mpfr_init2(x,64);
    mpfr_set_ld(x, v, mpfr_get_default_rounding_mode());

    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpArb& mpArb::operator=(const double v)
{
    mpfr_t x;

    mpfr_init2(x,64);
    mpfr_set_d(x, v, mpfr_get_default_rounding_mode());

    arb_init(mp);
    arb_set_interval_mpfr(mp, x, x, get_default_prec());

    mpfr_clear(x);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;




}

inline mpArb& mpArb::operator=(const unsigned long int v)
{
    arb_set_ui(mp, v);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const unsigned int v)
{
    arb_set_ui(mp, v);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const long int v)
{
    arb_set_si(mp, v);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const int v)
{
    arb_set_si(mp, v);

    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator=(const char* s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpArb(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpArb(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.



    mpfr_t x;

    mpfr_init2(x,get_default_prec());
    if(0 == (mpfr_set_str(x, s, 10, MPFR_RNDN)))
    {
         arb_set_interval_mpfr(mp, x, x, get_default_prec());
    }
    mpfr_clear(x);
    return *this;
}

inline mpArb& mpArb::operator=(const std::string& s)
{
    // Use other converters for more precise control on base & precision & rounding:
    //
    //        mpArb(const char* s,        mp_prec_t prec, int base, mp_rnd_t mode)
    //        mpArb(const std::string& s,mp_prec_t prec, int base, mp_rnd_t mode)
    //
    // Here we assume base = 10 and we use precision of target variable.

    mpfr_t x;

    mpfr_init2(x,get_default_prec());
    if(0 == (mpfr_set_str(x, s.c_str(), 10, MPFR_RNDN)))
    {
         arb_set_interval_mpfr(mp, x, x, get_default_prec());
    }
    mpfr_clear(x);
    return *this;

}


//////////////////////////////////////////////////////////////////////////
// + Addition
inline mpArb& mpArb::operator+=(const mpArb& v)
{
    arb_add(mp, mp, v.mp, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const mpfr_t u)
{
    *this += mpArb(u);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const fmpz_t u)
{
    arb_add_fmpz(mp, mp,u, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpArb& mpArb::operator+=(const fmpq_t u)
//{
//    arb_add_q(mp,mp,u);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}

inline mpArb& mpArb::operator+= (const long double u)
{
    *this += mpArb(u);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpArb& mpArb::operator+= (const double u)
{
    *this += mpArb(u);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const unsigned long int u)
{
    arb_add_ui(mp,mp,u, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const unsigned int u)
{
    arb_add_ui(mp,mp,u, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const long int u)
{
    arb_add_si(mp,mp,u, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator+=(const int u)
{
    arb_add_si(mp,mp,u, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

#if defined (arb_HAVE_INT64_SUPPORT)
inline mpArb& mpArb::operator+=(const int64_t  u){    *this += mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator+=(const uint64_t u){    *this += mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator-=(const int64_t  u){    *this -= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator-=(const uint64_t u){    *this -= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator*=(const int64_t  u){    *this *= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator*=(const uint64_t u){    *this *= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator/=(const int64_t  u){    *this /= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
inline mpArb& mpArb::operator/=(const uint64_t u){    *this /= mpArb(u); arb_MSVC_DEBUGVIEW_CODE; return *this;    }
#endif

inline const mpArb mpArb::operator+()const    {    return mpArb(*this); }

inline const mpArb operator+(const mpArb& a, const mpArb& b)
{
    mpArb x;
//	mpArb c(0, (std::max)(arb_get_prec(a.arb_ptr()), arb_get_prec(b.arb_ptr())));
	arb_add(x.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), x.get_default_prec());
	return x;
}

inline mpArb& mpArb::operator++()
{
    return *this += 1;
}

inline const mpArb mpArb::operator++ (int)
{
    mpArb x(*this);
    *this += 1;
    return x;
}

inline mpArb& mpArb::operator--()
{
    return *this -= 1;
}

inline const mpArb mpArb::operator-- (int)
{
    mpArb x(*this);
    *this -= 1;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// - Subtraction
inline mpArb& mpArb::operator-=(const mpArb& v)
{
    arb_sub(mp,mp,v.mp, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator-=(const fmpz_t v)
{
    arb_sub_fmpz(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpArb& mpArb::operator-=(const mpq_t v)
//{
//    arb_sub_q(mp,mp,v);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}


inline mpArb& mpArb::operator-=(const long double v)
{
    *this -= mpArb(v);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpArb& mpArb::operator-=(const double v)
{
    *this -= mpArb(v);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator-=(const unsigned long int v)
{
    arb_sub_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator-=(const unsigned int v)
{
    arb_sub_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator-=(const long int v)
{
    arb_sub_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator-=(const int v)
{
    arb_sub_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpArb mpArb::operator-()const
{
    mpArb u(*this);
    arb_neg(u.mp,u.mp);
    return u;
}

inline const mpArb operator-(const mpArb& a, const mpArb& b)
{
	mpArb c;
	arb_sub(c.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), c.get_default_prec());
	return c;
}

inline const mpArb operator-(const double  b, const mpArb& a)
{
    mpArb x(b);
    x -= a;
    return x;
}

inline const mpArb operator-(const unsigned long int b, const mpArb& a)
{
    mpArb x;
    arb_sub_ui(x.arb_ptr(), a.arb_srcptr(), b, x.get_default_prec());
    return -x;
}

inline const mpArb operator-(const unsigned int b, const mpArb& a)
{
    mpArb x;
    arb_sub_ui(x.arb_ptr(), a.arb_srcptr(), b, x.get_default_prec());
    return -x;
}

inline const mpArb operator-(const long int b, const mpArb& a)
{
    mpArb x;
    arb_sub_ui(x.arb_ptr(), a.arb_srcptr(), b, x.get_default_prec());
    return -x;
}

inline const mpArb operator-(const int b, const mpArb& a)
{
    mpArb x;
    arb_sub_ui(x.arb_ptr(), a.arb_srcptr(), b, x.get_default_prec());
    return -x;
}

//////////////////////////////////////////////////////////////////////////
// * Multiplication
inline mpArb& mpArb::operator*= (const mpArb& v)
{
    arb_mul(mp,mp,v.mp, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator*=(const fmpz_t v)
{
    arb_mul_fmpz(mp,mp, v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpArb& mpArb::operator*=(const mpq_t v)
//{
//    arb_mul_q(mp,mp, get_default_prec());
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}


inline mpArb& mpArb::operator*=(const long double v)
{
    *this *= mpArb(v);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator*=(const double v)
{
    *this *= mpArb(v);
    return *this;
}

inline mpArb& mpArb::operator*=(const unsigned long int v)
{
    arb_mul_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator*=(const unsigned int v)
{
    arb_mul_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator*=(const long int v)
{
    arb_mul_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator*=(const int v)
{
    arb_mul_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpArb operator*(const mpArb& a, const mpArb& b)
{
	mpArb c;
	arb_mul(c.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), c.get_default_prec());
	return c;
}

//////////////////////////////////////////////////////////////////////////
// / Division
inline mpArb& mpArb::operator/=(const mpArb& v)
{
    arb_div(mp,mp,v.mp, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator/=(const fmpz_t v)
{
    arb_div_fmpz(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

//inline mpArb& mpArb::operator/=(const mpq_t v)
//{
//    arb_div_q(mp,mp,v);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}


inline mpArb& mpArb::operator/=(const long double v)
{
    *this /= mpArb(v);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpArb& mpArb::operator/=(const double v)
{
    *this /= mpArb(v);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator/=(const unsigned long int v)
{
    arb_div_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator/=(const unsigned int v)
{
    arb_div_ui(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator/=(const long int v)
{
    arb_div_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::operator/=(const int v)
{
    arb_div_si(mp,mp,v, get_default_prec());
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpArb operator/(const mpArb& a, const mpArb& b)
{
	mpArb c;
	arb_div(c.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), c.get_default_prec());
	return c;
}

inline const mpArb operator/(const unsigned long int b, const mpArb& a)
{
    mpArb x;
    arb_ui_div(x.arb_ptr(), b, a.arb_srcptr(), x.get_default_prec());
    return x;
}

inline const mpArb operator/(const unsigned int b, const mpArb& a)
{
    mpArb x;
    arb_ui_div(x.arb_ptr(), b, a.arb_srcptr(), x.get_default_prec());
    return x;
}

inline const mpArb operator/(const long int b, const mpArb& a)
{
    mpArb x;
    arb_ui_div(x.arb_ptr(), b, a.arb_srcptr(), x.get_default_prec());
    if (b<0) x=-x;
    return x;
}

inline const mpArb operator/(const int b, const mpArb& a)
{
    mpArb x;
    arb_ui_div(x.arb_ptr(), b, a.arb_srcptr(), x.get_default_prec());
    if (b<0) x=-x;
    return x;
}

inline const mpArb operator/(const double  b, const mpArb& a)
{
    mpArb x;
    x /= a;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// Shifts operators - Multiplication/Division by power of 2
//inline mpArb& mpArb::operator<<=(const unsigned long int u)
//{
//    arb_mul_2ui(mp,mp,u);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator<<=(const unsigned int u)
//{
//    arb_mul_2ui(mp,mp,static_cast<unsigned long int>(u));
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator<<=(const long int u)
//{
//    arb_mul_2si(mp,mp,u);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator<<=(const int u)
//{
//    arb_mul_2si(mp,mp,static_cast<long int>(u));
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator>>=(const unsigned long int u)
//{
//    arb_div_2ui(mp,mp,u);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator>>=(const unsigned int u)
//{
//    arb_div_2ui(mp,mp,static_cast<unsigned long int>(u));
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator>>=(const long int u)
//{
//    arb_div_2si(mp,mp,u);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpArb& mpArb::operator>>=(const int u)
//{
//    arb_div_2si(mp,mp,static_cast<long int>(u));
//    arb_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline const mpArb operator<<(const mpArb& v, const unsigned long int k)
//{
//    return mul_2ui(v,k);
//}
//
//inline const mpArb operator<<(const mpArb& v, const unsigned int k)
//{
//    return mul_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpArb operator<<(const mpArb& v, const long int k)
//{
//    return mul_2si(v,k);
//}
//
//inline const mpArb operator<<(const mpArb& v, const int k)
//{
//    return mul_2si(v,static_cast<long int>(k));
//}
//
//inline const mpArb operator>>(const mpArb& v, const unsigned long int k)
//{
//    return div_2ui(v,k);
//}
//
//inline const mpArb operator>>(const mpArb& v, const long int k)
//{
//    return div_2si(v,k);
//}
//
//inline const mpArb operator>>(const mpArb& v, const unsigned int k)
//{
//    return div_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpArb operator>>(const mpArb& v, const int k)
//{
//    return div_2si(v,static_cast<long int>(k));
//}
//
//// mul_2ui
//inline const mpArb mul_2ui(const mpArb& v, unsigned long int k)
//{
//    mpArb x(v);
//    arb_mul_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//// mul_2si
//inline const mpArb mul_2si(const mpArb& v, long int k)
//{
//    mpArb x(v);
//    arb_mul_2si(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpArb div_2ui(const mpArb& v, unsigned long int k)
//{
//    mpArb x(v);
//    arb_div_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpArb div_2si(const mpArb& v, long int k)
//{
//    mpArb x(v);
//    arb_div_2si(x.mp,v.mp,k);
//    return x;
//}

//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////
//Boolean operators
inline bool operator >  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) > 0);
    return result;
}

inline bool operator >=  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) >= 0);
    return result;
}


inline bool operator <  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) < 0);
    return result;
}



inline bool operator <=  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) <= 0);
    return result;
}


inline bool operator ==  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) == 0);
    return result;
}


inline bool operator !=  (const mpArb& a, const mpArb& b)
{
    bool result = (arf_cmp(arb_midref(a.mp), arb_midref(b.mp)) != 0);
    return result;
}



//inline bool operator != (const mpArb& a, const mpArb& b){    return (arb_lessgreater_p(a.mp,b.mp)  !=0);    }




inline bool operator == (const mpArb& a, const unsigned long int b ){    return (a == mpArb(b));    }
inline bool operator == (const mpArb& a, const unsigned int b      ){    return (a == mpArb(b));    }
inline bool operator == (const mpArb& a, const long int b          ){    return (a == mpArb(b));    }
inline bool operator == (const mpArb& a, const int b               ){    return (a == mpArb(b));    }

inline bool operator == (const mpArb& a, const long double b       ){    return (a == mpArb(b));    }

inline bool operator == (const mpArb& a, const double b            ){    return (a == mpArb(b));    }


inline bool isnan    (const mpArb& v){    return (arb_is_zero(v.mp)     != 0);    }
inline bool isinf    (const mpArb& v){    return (arb_is_finite(v.mp)     == 0);    }
inline bool isfinite (const mpArb& v){    return (arb_is_finite(v.mp)  != 0);    }
inline bool iszero   (const mpArb& v){    return (arb_is_zero(v.mp)    != 0);    }
/* Change DH
inline bool isint    (const mpArb& v){    return (arb_integer_p(v.mp) != 0);    }
*/

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
/* Change DH
inline bool isregular(const mpArb& v){    return (arb_regular_p(v.mp));}
*/
#endif

//////////////////////////////////////////////////////////////////////////
// Type Converters
/* Change DH */
//inline long             mpArb::toLong   (mp_rnd_t mode)  const    {    return arb_get_si(mp, mode);    }
//inline unsigned long    mpArb::toULong  (mp_rnd_t mode)  const    {    return arb_get_ui(mp, mode);    }

//inline long             mpArb::toLong   (mp_rnd_t mode)  const    {    return (long) arb_get_d(mp);    }
//inline unsigned long    mpArb::toULong  (mp_rnd_t mode)  const    {    return (unsigned long) arb_get_d(mp);    }
//
//inline double           mpArb::toDouble (mp_rnd_t mode)  const    {    return arb_get_d (mp);    }
////inline long double      mpArb::toLDouble(mp_rnd_t mode)  const    {    return arb_get_ld(mp);    }
//inline long double      mpArb::toLDouble(mp_rnd_t mode)  const    {    return arb_get_d(mp);    }
//
//
//#if defined (arb_HAVE_INT64_SUPPORT)
////inline int64_t      mpArb::toInt64 (mp_rnd_t mode)    const{    return arb_get_sj(mp, mode);    }
////inline uint64_t     mpArb::toUInt64(mp_rnd_t mode)    const{    return arb_get_uj(mp, mode);    }
//
//inline int64_t      mpArb::toInt64 (mp_rnd_t mode)    const{    return (int64_t) arb_get_d(mp);    }
//inline uint64_t     mpArb::toUInt64(mp_rnd_t mode)    const{    return (uint64_t) arb_get_d(mp);    }
//
//#endif

inline ::arb_ptr     mpArb::arb_ptr()             { return mp; }
inline ::arb_srcptr  mpArb::arb_ptr()    const    { return mp; }
inline ::arb_srcptr  mpArb::arb_srcptr() const    { return mp; }

template <class T>
inline std::string toString(T t, std::ios_base & (*f)(std::ios_base&))
{
    std::ostringstream oss;
    oss << f << t;
    return oss.str();
}

#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline std::string mpArb::toString(const std::string& format) const
{
    char *sL = NULL;
    std::string outL;
    mpfr_t fL;
    mpfr_init2(fL, get_default_prec());
    mpfr_t fR;
    mpfr_init2(fR, get_default_prec());


    arb_get_interval_mpfr(fL, fR, mp);

//    arb_get_left(fL, mp);
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
//    arb_get_right(fR, mp);
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

inline std::string mpArb::toString(int n, int b, mp_rnd_t mode) const
{
    (void)b;
    (void)mode;

//#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

    // Use mparb native function for output
    char format[128];
    int digits;

    digits = n > 0 ? n : bits2digits(get_default_prec());

    sprintf(format,"%%.%dRNg",digits);        // Default format

    return toString(std::string(format));

//#else
//
//    char *s, *ns = NULL;
//    size_t slen, nslen;
//    mp_exp_t exp;
//    std::string out;
//
//    if(arb_inf_p(mp))
//    {
//        if(arb_sgn(mp)>0) return "+Inf";
//        else               return "-Inf";
//    }
//
//    if(arb_zero_p(mp)) return "0";
//    if(arb_nan_p(mp))  return "NaN";
//
//    s  = arb_get_str(NULL,&exp,b,0,mp,mode);
//    ns = arb_get_str(NULL,&exp,b,n,mp,mode);
//
//    if(s!=NULL && ns!=NULL)
//    {
//        slen  = strlen(s);
//        nslen = strlen(ns);
//        if(nslen<=slen)
//        {
//            arb_free_str(s);
//            s = ns;
//            slen = nslen;
//        }
//        else {
//            arb_free_str(ns);
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
//                if(exp>0) out += "e+"+mparb::toString<mp_exp_t>(exp,std::dec);
//                else       out += "e"+mparb::toString<mp_exp_t>(exp,std::dec);
//            }
//        }
//
//        arb_free_str(s);
//        return out;
//    }else{
//        return "conversion error!";
//    }
//#endif
}


//////////////////////////////////////////////////////////////////////////
// I/O
inline std::ostream& operator<<(std::ostream& os, const mpArb& v)
{
    return os<<v.toString(static_cast<int>(os.precision()));
}

inline std::istream& operator>>(std::istream &is, mpArb& v)
{
    // ToDo, use cout::hexfloat and other flags to setup base
    std::string tmp;
    is >> tmp;


   mpfr_t x;

    mpfr_init2(x,mpfr_get_default_prec());
    mpfr_set_str(x, tmp.c_str(), 10, MPFR_RNDN);


//    arb_init(mp);
    arb_set_interval_mpfr(v.mp, x, x, mpfr_get_default_prec());

    mpfr_clear(x);




//    arb_set_str(v.mp, tmp.c_str(), 10);
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

inline int sgn(const mpArb& v)
{
//    mpfr_t ar;
//    mpfr_init2(ar, mpArb::get_default_prec());
//    arb_mid (ar, v.mp);
    int r = arf_sgn(arb_midref(v.mp));
//    mpfr_clear(ar);
    return r;
}

inline mpArb& mpArb::setSign(int sign, mp_rnd_t RoundingMode)
{
    /* Change DH
    arb_setsign(mp,mp,(sign < 0 ? 1 : 0),RoundingMode);
    */
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline int mpArb::getPrecision() const
{
    return mpfr_get_default_prec();
}

inline mpArb& mpArb::setPrecision(int Precision, mp_rnd_t RoundingMode)
{
    /* Change DH
    arb_prec_round(mp, Precision, RoundingMode);
    */
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::setInf(int sign)
{
    /* Change DH
    arb_set_inf(mp,sign);
    */
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb& mpArb::setNan()
{
    /* Change DH
    arb_set_nan(mp);
    */
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpArb&    mpArb::setZero(int sign)
{
    arb_set_si(mp, 0);
    arb_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mp_prec_t mpArb::get_prec() const
{
    return mpfr_get_default_prec();
}

inline void mpArb::set_prec(mp_prec_t prec)
{
    /* Change DH */
//    arb_set_prec(mp,prec);
    arb_MSVC_DEBUGVIEW_CODE;
}



// modified by DH
//inline mp_exp_t mpArb::get_exp ()
//{
//    mpfr_t ar;
//    mpfr_init2(ar, mpArb::get_default_prec());
//    arb_mid (ar, mp);
//    mp_exp_t e = mpfr_get_exp(ar);
//    mpfr_clear(ar);
//    return e;
//}
//
//inline int mpArb::set_exp (mp_exp_t e)
//{
//    mpfr_t ar;
//    mpfr_init2(ar, mpArb::get_default_prec());
//    arb_mid (ar, mp);
//    int x = mpfr_set_exp(ar, e);
//    arb_set_fr(mp, ar)
//    arb_MSVC_DEBUGVIEW_CODE;
//    return x;
//}
//
//inline const mpArb frexp(const mpArb& v, mp_exp_t* exp)
//{
//    mpArb x(v);
//    *exp = x.get_exp();
//    x.set_exp(0);
//    return x;
//}


//Change DH Begin

inline const mpArb frexp(const mpArb& v, int* exp)
{
    mpArb x(v);
//    *exp = x.get_exp();
//    x.set_exp(0);
    return x;
}


inline const mpArb ilogb(const mpArb& v)
{
    mpArb x(v);
//    mp_exp_t exp = x.get_exp();
//    mpArb y(exp - 1);
    return x;
}

////Change DH End



inline const mpArb ldexp(const mpArb& v, mp_exp_t exp)
{
    mpArb x(v);

    // rounding is not important since we just increasing the exponent
//    arb_mul_2si(x.mp,x.mp,exp);
    return x;
}


////Change DH Begin

inline const mpArb ldexp(const mpArb& v, const mpArb& e)
{
    mpArb x(v);
//    mp_exp_t exp = arb_get_d(x.mp);
//
//    // rounding is not important since we just increasing the exponent
//    arb_mul_2si(x.mp,x.mp,exp);
    return x;
}

////Change DH End
//
//
////Change DH Begin

inline const mpArb scalbn(const mpArb& v, const mpArb& e)
{
    return ldexp(v,e);
}

inline const mpArb scalbln(const mpArb& v, const mpArb& e)
{
    return ldexp(v,e);
}

////Change DH End
//
//




inline mpArb machine_epsilon(mp_prec_t prec)
{
    /* the smallest eps such that 1 + eps != 1 */
    return machine_epsilon(mpArb(1, prec));
}

inline mpArb machine_epsilon(const mpArb& x)
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
inline mpArb minval(mp_prec_t prec)
{
    /* min = 1/2 * 2^emin = 2^(emin - 1) */
//    return mpArb(1, prec) << mpArb::get_emin()-1;
    return mpArb("1E-10000");
}

// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpArb maxval(mp_prec_t prec)
{
    /* max = (1 - eps) * 2^emax, eps is machine epsilon */
//    return (mpArb(1, prec) - machine_epsilon(prec)) << mpArb::get_emax();
    return mpArb("1E+10000");

}

inline bool isEqualUlps(const mpArb& a, const mpArb& b, int maxUlps)
{
  return abs(a - b) <= machine_epsilon((max)(abs(a), abs(b))) * maxUlps;
}

inline bool isEqualFuzzy(const mpArb& a, const mpArb& b, const mpArb& eps)
{
    return abs(a - b) <= (min)(abs(a), abs(b)) * eps;
}

inline bool isEqualFuzzy(const mpArb& a, const mpArb& b)
{
    return isEqualFuzzy(a, b, machine_epsilon((min)(abs(a), abs(b))));
}


inline const mpArb modf(const mpArb& v, mpArb& n)
{
//    mpArb frac(v);
//
//    // rounding is not important since we are using the same number
//    arb_frac(frac.mp,frac.mp);
//    arb_trunc(n.mp,v.mp);
//    return frac;
    return mpArb("999.999");
}

inline int mpArb::check_range (int t)
{
 //   return arb_check_range(mp,t,rnd_mode);
    return 999;
}

inline int mpArb::subnormalize (int t,mp_rnd_t rnd_mode)
{
//    int r = arb_subnormalize(mp,t,rnd_mode);
//    arb_MSVC_DEBUGVIEW_CODE;
//    return r;
    return 999999;
}





inline mp_exp_t mpArb::get_emin (void)
{
    return mpfr_get_emin();
}

inline int mpArb::set_emin (mp_exp_t exp)
{
    return mpfr_set_emin(exp);
}

inline mp_exp_t mpArb::get_emax (void)
{
    return mpfr_get_emax();
}

inline int mpArb::set_emax (mp_exp_t exp)
{
    return mpfr_set_emax(exp);
}

inline mp_exp_t mpArb::get_emin_min (void)
{
    return mpfr_get_emin_min();
}

inline mp_exp_t mpArb::get_emin_max (void)
{
    return mpfr_get_emin_max();
}

inline mp_exp_t mpArb::get_emax_min (void)
{
    return mpfr_get_emax_min();
}

inline mp_exp_t mpArb::get_emax_max (void)
{
    return mpfr_get_emax_max();
}

//////////////////////////////////////////////////////////////////////////
// Mathematical Functions
//////////////////////////////////////////////////////////////////////////

/* DH Change
#define arb_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpArb y(0, arb_get_prec(x.arb_srcptr()));          \
        arb_##f(y.arb_ptr(), x.arb_srcptr(), r);           \
        return y;
*/
#define arb_UNARY_MATH_FUNCTION_BODY0(f)                    \
        mpArb y;          \
        arb_##f(y.arb_ptr(), x.arb_srcptr());           \
        return y;


#define arb_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpArb y;          \
        arb_##f(y.arb_ptr(), x.arb_srcptr(), mpfr_get_default_prec());           \
        return y;


//inline const mpArb sqr  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(sqr );    }
inline const mpArb sqrt (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(sqrt);    }


inline const mpArb sqrt(const unsigned long int x)
{
//    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
//    return y;
    return sqrt(static_cast<unsigned long int>(x));
}

//    friend const mpArb erf      (const mpArb& v);
//    friend const mpArb erfc     (const mpArb& v);
//    friend const mpArb besselj0 (const mpArb& v);
//    friend const mpArb besselj1 (const mpArb& v);
//    friend const mpArb besseljn (long n, const mpArb& v);
//    friend const mpArb bessely0 (const mpArb& v);
//    friend const mpArb bessely1 (const mpArb& v);
//    friend const mpArb besselyn (long n, const mpArb& v);


inline const mpArb lgamma(const mpArb& v, int* s)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb lngamma(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb tgamma(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb erf(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb asinh(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb acosh(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb atanh(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb erfc(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb cbrt(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb log1p(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}



inline const mpArb exp10(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb exp2(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}


inline const mpArb log2(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb log10(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}

inline const mpArb logb(const mpArb& v)
{
    mpArb y;
//    arb_sqrt_ui(y.arb_ptr(), x, r);
    return y;
}





inline const mpArb sqrt(const unsigned int v)
{
    return sqrt(static_cast<unsigned long int>(v));
}

inline const mpArb sqrt(const long int v)
{
//    if (v>=0)   return sqrt(static_cast<unsigned long int>(v),rnd_mode);
//    else        return mpArb().setNan(); // NaN
    return mpArb("999.999");

}

inline const mpArb sqrt(const int v)
{
    if (v>=0)   return sqrt(static_cast<unsigned long int>(v));
    else        return mpArb().setNan(); // NaN
}


inline const mpArb root(const mpArb& x, unsigned long int k)
{
//    mpArb y(0, arb_get_prec(x.arb_srcptr()));
//    arb_root(y.arb_ptr(), x.arb_srcptr(), k, r);
//    return y;
    return mpArb("999.999");

}

inline const mpArb dim(const mpArb& a, const mpArb& b)
{
//    mpArb y(0, arb_get_prec(a.arb_srcptr()));
//    arb_dim(y.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), r);
//    return y;
    return mpArb("999.999");

}


inline const mpArb fdim(const mpArb& a, const mpArb& b)
{
//    mpArb y(0, arb_get_prec(a.arb_srcptr()));
//    arb_dim(y.arb_ptr(), a.arb_srcptr(), b.arb_srcptr(), r);
//    return y;
    return mpArb("999.999");

}


inline int cmpabs(const mpArb& a,const mpArb& b)
{
//    return arb_cmpabs(a.mp,b.mp);
    return 999999;

}

inline int sin_cos(mpArb& s, mpArb& c, const mpArb& v)
{
 //   return arb_sin_cos(s.mp,c.mp,v.mp,rnd_mode);
     return 999999;

}

inline const mpArb sqrt  (const long double v)    {   return sqrt(mpArb(v));    }
inline const mpArb sqrt  (const double v)         {   return sqrt(mpArb(v));    }




//inline const mpArb cbrt  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(cbrt );    }
inline const mpArb fabs  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs  );    }
inline const mpArb abs   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs  );    }
inline const mpArb log   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(log  );    }
//inline const mpArb log2  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(log2 );    }
// Change DH Begin
//inline const mpArb logb  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(log2 );    }
// Change DH End
//inline const mpArb log10 (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(log10);    }
inline const mpArb exp   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(exp  );    }
//inline const mpArb exp2  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(exp2 );    }
//inline const mpArb exp10 (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs);    }
inline const mpArb cos   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(cos  );    }
inline const mpArb sin   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(sin  );    }
inline const mpArb tan   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(tan  );    }
//inline const mpArb sec   (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(sec  );    }
//inline const mpArb csc   (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(csc  );    }
inline const mpArb cot   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(cot  );    }
inline const mpArb acos  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(acos);     }
inline const mpArb asin  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(asin);     }
inline const mpArb atan  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(atan);     }

//inline const mpArb acot  (const mpArb& v, mp_rnd_t r) {   return atan (1/v, r);                      }
//inline const mpArb asec  (const mpArb& v, mp_rnd_t r) {   return acos (1/v, r);                      }
//inline const mpArb acsc  (const mpArb& v, mp_rnd_t r) {   return asin (1/v, r);                      }
//inline const mpArb acoth (const mpArb& v, mp_rnd_t r) {   return atanh(1/v, r);                      }
//inline const mpArb asech (const mpArb& v, mp_rnd_t r) {   return acosh(1/v, r);                      }
//inline const mpArb acsch (const mpArb& v, mp_rnd_t r) {   return asinh(1/v, r);                      }

inline const mpArb cosh  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(cosh );    }
inline const mpArb sinh  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(sinh );    }
inline const mpArb tanh  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(tanh );    }
//inline const mpArb sech  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(sech );    }
//inline const mpArb csch  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(csch );    }
inline const mpArb coth  (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(coth );    }
//inline const mpArb acosh (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(acosh);    }
//inline const mpArb asinh (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(asinh);    }
//inline const mpArb atanh (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(atanh);    }

//inline const mpArb log1p   (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(log1p  );    }
inline const mpArb expm1   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(expm1  );    }

//inline const mpArb eint    (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs   );    }
inline const mpArb gamma   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(gamma  );    }
// Change DH Begin
//inline const mpArb tgamma   (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(abs  );    }
// Change DH End


//inline const mpArb lgamma (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(lgamma);    }
inline const mpArb zeta    (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY(zeta   );    }
//inline const mpArb erf     (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs    );    }
//inline const mpArb erfc    (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs   );    }
//inline const mpArb besselj0(const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs     );    }
//inline const mpArb besselj1(const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs     );    }
//inline const mpArb bessely0(const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs     );    }
//inline const mpArb bessely1(const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs     );    }



inline const mpArb sign (const mpArb& v)
{
    int s = 1;
    mpArb x(s);
    return x;
}

inline const mpArb sqr (const mpArb& v)
{
    return v*v;
}


inline const mpArb atan2 (const mpArb& y, const mpArb& x)
{
    mpArb a;
    mp_prec_t yp, xp;

    yp = y.get_prec();
    xp = x.get_prec();

    a.set_prec(yp>xp?yp:xp);

    arb_atan2(a.mp, y.mp, x.mp, a.get_default_prec());

    return a;
}


inline const mpArb hypot (const mpArb& x, const mpArb& y)
{
    mpArb a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);

    arb_hypot(a.mp, x.mp, y.mp, a.get_default_prec());

    return a;
}


inline const mpArb copysign (const mpArb& x, const mpArb& y)
{
    mpArb a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);

    arb_hypot(a.mp, x.mp, y.mp, a.get_default_prec());

    return a;
}



inline const mpArb remainder (const mpArb& x, const mpArb& y)
{
//    mpArb a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    arb_remainder(a.mp, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpArb("999.999");

}

inline const mpArb remquo (long* q, const mpArb& x, const mpArb& y)
{
//    mpArb a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    arb_remquo(a.mp,q, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpArb("999.999");

}

// Change DH Begin
inline const mpArb remquo (const mpArb& x, const mpArb& y, int* q)
{
    return mpArb("999.999");
}
// Change DH End





inline const mpArb fac_ui (unsigned long int v, mp_prec_t prec)
{
//    mpArb x(0, prec);
//    arb_fac_ui(x.mp,v,rnd_mode);
//    return x;
    return mpArb("999.999");

}


//inline const mpArb lgamma (const mpArb& v, int *signp)
//{
////    mpArb x(v);
////    int tsignp;
////
////    if(signp)   arb_lgamma(x.mp,signp,v.mp,rnd_mode);
////    else        arb_lgamma(x.mp,&tsignp,v.mp,rnd_mode);
////
////    return x;
//    return mpArb("999.999");

//}


inline const mpArb besseljn (long n, const mpArb& x, mp_rnd_t r)
{
//    mpArb  y(0, arb_get_prec(x.arb_srcptr()));
//    arb_jn(y.arb_ptr(), n, x.arb_srcptr(), r);
//    return y;
    return mpArb("999.999");

}

inline const mpArb besselyn (long n, const mpArb& x, mp_rnd_t r)
{
//    mpArb  y(0, arb_get_prec(x.arb_srcptr()));
//    arb_yn(y.arb_ptr(), n, x.arb_srcptr(), r);
//    return y;
    return mpArb("999.999");

}

inline const mpArb fma (const mpArb& v1, const mpArb& v2, const mpArb& v3)
{
//    mpArb a;
//    mp_prec_t p1, p2, p3;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//    p3 = v3.get_prec();
//
//    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));
//
//    arb_fma(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
//    return a;
    return mpArb("999.999");

}

inline const mpArb fms (const mpArb& v1, const mpArb& v2, const mpArb& v3)
{
//    mpArb a;
//    mp_prec_t p1, p2, p3;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//    p3 = v3.get_prec();
//
//    a.set_prec(p3>p2?(p3>p1?p3:p1):(p2>p1?p2:p1));
//
//    arb_fms(a.mp,v1.mp,v2.mp,v3.mp,rnd_mode);
//    return a;
    return mpArb("999.999");

}

inline const mpArb agm (const mpArb& v1, const mpArb& v2)
{
//    mpArb a;
//    mp_prec_t p1, p2;
//
//    p1 = v1.get_prec();
//    p2 = v2.get_prec();
//
//    a.set_prec(p1>p2?p1:p2);
//
//    arb_agm(a.mp, v1.mp, v2.mp, rnd_mode);
//
//    return a;
    return mpArb("999.999");

}

inline const mpArb sum (const mpArb tab[], unsigned long int n)
{
//    mpArb x;
//    arb_ptr* t;
//    unsigned long int i;
//
//    t = new arb_ptr[n];
//    for (i=0;i<n;i++) t[i] = (arb_ptr)tab[i].mp;
//    arb_sum(x.mp,t,n,rnd_mode);
//    delete[] t;
//    return x;
    return mpArb("999.999");

}

//////////////////////////////////////////////////////////////////////////
// mparb 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline int sinh_cosh(mpArb& s, mpArb& c, const mpArb& v)
{
  //  return arb_sinh_cosh(s.mp,c.mp,v.mp,rnd_mode);
      return 999;

}

inline const mpArb li2 (const mpArb& x, mp_rnd_t r)
{
  //  arb_UNARY_MATH_FUNCTION_BODY(li2);
      return mpArb("999.999");

}


inline const mpArb rem (const mpArb& x, const mpArb& y)
{
    //  R = rem(X,Y) if Y != 0, returns X - n * Y where n = trunc(X/Y).
   // return fmod(x, y, rnd_mode);
       return mpArb("999.999");

}

inline const mpArb mod (const mpArb& x, const mpArb& y)
{
//    (void)rnd_mode;



//    m = mod(x,y) if y != 0, returns x - n*y where n = floor(x/y)
//
//    The following are true by convention:
//    - mod(x,0) is x
//    - mod(x,x) is 0
//    - mod(x,y) for x != y and y != 0 has the same sign as y.



//    if(iszero(y)) return x;
//    if(x == y) return 0;
//
//    mpArb m = x - floor(x / y) * y;
//
//    m.setSign(sgn(y)); // make sure result has the same sign as Y
//
//    return m;
    return mpArb("999.999");

}

inline const mpArb fmod (const mpArb& x, const mpArb& y)
{
//    mpArb a;
//    mp_prec_t yp, xp;
//
//    yp = y.get_prec();
//    xp = x.get_prec();
//
//    a.set_prec(yp>xp?yp:xp);
//
//    arb_fmod(a.mp, x.mp, y.mp, rnd_mode);
//
//    return a;
    return mpArb("999.999");

}

inline const mpArb rec_sqrt(const mpArb& v)
{
//    mpArb x(v);
//    arb_rec_sqrt(x.mp,v.mp,rnd_mode);
//    return x;
    return mpArb("999.999");

}
#endif //  mparb 2.4.0 Specifics



//////////////////////////////////////////////////////////////////////////
// mparb 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
//inline const mpArb digamma (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(digamma);     }
//inline const mpArb ai      (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(ai);          }

inline const mpArb digamma (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(digamma);     }
//inline const mpArb ai      (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(abs);          }

#endif // mparb 3.0.0 Specifics

//////////////////////////////////////////////////////////////////////////







// Constants
inline const mpArb const_log2 (mp_prec_t p)
{
    mpArb x(0, p);
    arb_const_log2(x.arb_ptr(),x.get_default_prec());
    return x;
}

inline const mpArb const_pi (mp_prec_t p)
{
    mpArb x(0, p);
    arb_const_pi(x.arb_ptr(),x.get_default_prec());
    return x;
}

inline const mpArb const_euler (mp_prec_t p)
{
    mpArb x(0, p);
    arb_const_euler(x.arb_ptr(),x.get_default_prec());
    return x;
}

inline const mpArb const_catalan (mp_prec_t p)
{
    mpArb x(0, p);
    arb_const_catalan(x.arb_ptr(),x.get_default_prec());
    return x;
}


// Change DH
inline const mpArb const_log2_a (const mpArb& temp)
{
    mpArb x(0, mpArb::get_default_prec());
    arb_const_log2(x.arb_ptr(), x.get_default_prec());
    return x;
}

inline const mpArb const_pi_a (const mpArb& temp)
{
    mpArb x(0, mpArb::get_default_prec());
    arb_const_pi(x.arb_ptr(), x.get_default_prec());
    return x;
}

inline const mpArb const_euler_gamma_a (const mpArb& temp)
{
    mpArb x(0, mpArb::get_default_prec());
    arb_const_euler(x.arb_ptr(), x.get_default_prec());
    return x;
}

inline const mpArb const_catalan_a (const mpArb& temp)
{
    mpArb x(0, mpArb::get_default_prec());
    arb_const_catalan(x.arb_ptr(), x.get_default_prec());
    return x;
}

// End Change DH








/* Change DH */
inline const mpArb const_infinity (int sign, mp_prec_t p)
{
    mpArb x;
    arb_zero_pm_inf(x.arb_ptr());
    return x;
}


//////////////////////////////////////////////////////////////////////////
// Integer Related Functions
inline const mpArb ceil(const mpArb& v)
{
    mpArb x;
    arb_ceil(x.mp, v.mp, x.get_default_prec());
    return x;
}

inline const mpArb floor(const mpArb& v)
{
    mpArb x;
    arb_floor(x.mp, v.mp, x.get_default_prec());
    return x;
}


inline const mpArb round(const mpArb& v)
{
//    mpArb x(v);
//    arb_round(x.mp,v.mp);
//    return x;
    return mpArb("999.999");
}

// Change DH Begin
inline const mpArb lround(const mpArb& v)
{
    return round(v);
}

inline const mpArb llround(const mpArb& v)
{
    return round(v);
}
// Change DH End



inline const mpArb trunc(const mpArb& v)
{
//    mpArb x(v);
//    arb_trunc(x.mp,v.mp);
//    return x;
    return mpArb("999.999");
}

//inline const mpArb rint       (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(rint      );     }
//inline const mpArb rint_ceil  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(rint_ceil );     }
//inline const mpArb rint_floor (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(rint_floor);     }
//inline const mpArb rint_round (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(rint_round);     }
//inline const mpArb rint_trunc (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(rint_trunc);     }
//inline const mpArb frac       (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY(frac      );     }

inline const mpArb rint       (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs      );     }

// Change DH Begin
inline const mpArb lrint       (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs      );     }
inline const mpArb llrint       (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs      );     }
inline const mpArb nearbyint       (const mpArb& x) {   arb_UNARY_MATH_FUNCTION_BODY0(abs      );     }
// Change DH End


inline const mpArb rint_ceil  (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY0(abs );     }
inline const mpArb rint_floor (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY0(abs);     }
inline const mpArb rint_round (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY0(abs);     }
inline const mpArb rint_trunc (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY0(abs);     }
inline const mpArb frac       (const mpArb& x, mp_rnd_t r) {   arb_UNARY_MATH_FUNCTION_BODY0(abs      );     }


//////////////////////////////////////////////////////////////////////////
// Miscellaneous Functions
inline void         swap (mpArb& a, mpArb& b)            {    arb_swap(a.mp,b.mp);   }
inline const mpArb (max)(const mpArb& x, const mpArb& y){    return (x>y?x:y);       }
inline const mpArb (min)(const mpArb& x, const mpArb& y){    return (x<y?x:y);       }

inline const mpArb fmax(const mpArb& x, const mpArb& y)
{
//    mpArb a;
//    arb_max(a.mp,x.mp,y.mp,rnd_mode);
//    return a;
    return mpArb("999.999");
}

inline const mpArb fmin(const mpArb& x, const mpArb& y)
{
//    mpArb a;
//    arb_min(a.mp,x.mp,y.mp,rnd_mode);
//    return a;
    return mpArb("999.999");
}

inline const mpArb nexttoward (const mpArb& x, const mpArb& y)
{
//    mpArb a(x);
//    arb_nexttoward(a.mp,y.mp);
//    return a;
    return mpArb("999.999");
}

inline const mpArb nextafter (const mpArb& x, const mpArb& y)
{
//    mpArb a(x);
//    arb_nexttoward(a.mp,y.mp);
//    return a;
    return mpArb("999.999");
}



inline const mpArb nextabove  (const mpArb& x)
{
//    mpArb a(x);
//    arb_nextabove(a.mp);
//    return a;
    return mpArb("999.999");
}

inline const mpArb nextbelow  (const mpArb& x)
{
//    mpArb a(x);
//    arb_nextbelow(a.mp);
//    return a;
    return mpArb("999.999");
}





inline const mpArb urandomb (gmp_randstate_t& state)
{
    mpArb x;
    mpfr_t f;
    mpfr_init(f);
    mpfr_urandomb(f,state);
    x = f;
    mpfr_clear(f);
    return x;
}

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
// use gmp_randinit_default() to init state, gmp_randclear() to clear
inline const mpArb urandom (gmp_randstate_t& state)
{
    mpArb x;
    mpfr_t f;
    mpfr_init(f);
    mpfr_urandom(f,state,MPFR_RNDN);
    x = f;
    mpfr_clear(f);
    return x;
}
#endif

#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
inline const mpArb random2 (mp_size_t size, mp_exp_t exp)
{
//    mpArb x;
//    arb_random2(x.mp,size,exp);
//    return x;
    return mpArb("999.999");
}
#endif

// Uniformly distributed random number generation
// a = random(seed); <- initialization & first random number generation
// a = random();     <- next random numbers generation
// seed != 0
inline const mpArb random(unsigned int seed)
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

    return mparb::urandom(state);
#else
    if(seed != 0)    std::srand(seed);
    return mparb::mpArb(std::rand()/(double)RAND_MAX);
#endif

}



//////////////////////////////////////////////////////////////////////////
// Set/Get global properties
inline void mpArb::set_default_prec(mp_prec_t prec)
{
    //mpfr_set_default_prec(prec);
}

inline void mpArb::set_default_rnd(mp_rnd_t rnd_mode)
{
    //mpfr_set_default_rounding_mode(rnd_mode);
}

inline bool mpArb::fits_in_bits(double x, int n)
{
    int i;
    double t;
    return IsInf(x) || (std::modf ( std::ldexp ( std::frexp ( x, &i ), n ), &t ) == 0.0);
}

inline const mpArb pow(const mpArb& a, const mpArb& b)
{
    /*Change DH */
    mpArb x;
    arb_pow(x.mp, a.mp, b.mp, x.get_default_prec());
    return x;
}

inline const mpArb pow(const mpArb& a, const fmpz_t b)
{
    /*Change DH */
    mpArb x;
//    arb_pow_fmpz(
//                 x.mp,
//                 a.mp,
//                 b, x.get_default_prec());
    return x;
}

inline const mpArb pow(const mpArb& a, const unsigned long int b)
{
       /*Change DH */
    mpArb x(a);
//    arb_pow_ui(x.mp,x.mp,b,rnd_mode);
//    x = exp(a * log(b));
    return x;
}

inline const mpArb pow(const mpArb& a, const unsigned int b)
{
    return pow(a,static_cast<unsigned long int>(b));
}

inline const mpArb pow(const mpArb& a, const long int b)
{
       /*Change DH */
    mpArb x(a);
//    arb_pow_si(x.mp,x.mp,b,rnd_mode);
//    x = exp(a * log(b));
    return x;
}

inline const mpArb pow(const mpArb& a, const int b)
{
    return pow(a,static_cast<long int>(b));
}


inline const mpArb pow(const mpArb& a, const long double b)
{
   // return pow(a,mpArb(b),rnd_mode);
       return mpArb("999.999");
}



inline const mpArb pow(const mpArb& a, const double b)
{
    return pow(a,mpArb(b));
}

inline const mpArb pow(const unsigned long int a, const mpArb& b)
{
       /*Change DH */
    mpArb x(a);
//    arb_ui_pow(x.mp,a,b.mp,rnd_mode);
//    x = exp(a * log(b));
    return x;
}

inline const mpArb pow(const unsigned int a, const mpArb& b)
{
    return pow(static_cast<unsigned long int>(a),b);
}

inline const mpArb pow(const long int a, const mpArb& b)
{
    if (a>=0)     return pow(static_cast<unsigned long int>(a),b);
    else        return pow(mpArb(a),b);
}

inline const mpArb pow(const int a, const mpArb& b)
{
    if (a>=0)     return pow(static_cast<unsigned long int>(a),b);
    else        return pow(mpArb(a),b);
}


inline const mpArb pow(const long double a, const mpArb& b)
{
    return pow(mpArb(a),b);
}


inline const mpArb pow(const double a, const mpArb& b)
{
    return pow(mpArb(a),b);
}

// pow unsigned long int
inline const mpArb pow(const unsigned long int a, const unsigned long int b)
{
       /*Change DH */
    mpArb x(a);
//    arb_ui_pow_ui(x.mp,a,b,rnd_mode);
//    x = exp(a * log(b));
    return x;
}

inline const mpArb pow(const unsigned long int a, const unsigned int b)
{
    return pow(a,static_cast<unsigned long int>(b)); //arb_ui_pow_ui
}

inline const mpArb pow(const unsigned long int a, const long int b)
{
    if(b>0)    return pow(a,static_cast<unsigned long int>(b)); //arb_ui_pow_ui
    else    return pow(a,mpArb(b)); //arb_ui_pow
}

inline const mpArb pow(const unsigned long int a, const int b)
{
    if(b>0)    return pow(a,static_cast<unsigned long int>(b)); //arb_ui_pow_ui
    else    return pow(a,mpArb(b)); //arb_ui_pow
}


inline const mpArb pow(const unsigned long int a, const long double b)
{
    return pow(a,mpArb(b)); //arb_ui_pow
}


inline const mpArb pow(const unsigned long int a, const double b)
{
    return pow(a,mpArb(b)); //arb_ui_pow
}

// pow unsigned int
inline const mpArb pow(const unsigned int a, const unsigned long int b)
{
    return pow(static_cast<unsigned long int>(a),b); //arb_ui_pow_ui
}

inline const mpArb pow(const unsigned int a, const unsigned int b)
{
    return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
}

inline const mpArb pow(const unsigned int a, const long int b)
{
    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
    else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
}

inline const mpArb pow(const unsigned int a, const int b)
{
    if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
    else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
}


inline const mpArb pow(const unsigned int a, const long double b)
{
    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
}

inline const mpArb pow(const unsigned int a, const double b)
{
    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
}

// pow long int
inline const mpArb pow(const long int a, const unsigned long int b)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),b); //arb_ui_pow_ui
    else     return pow(mpArb(a),b); //arb_pow_ui
}

inline const mpArb pow(const long int a, const unsigned int b)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b));  //arb_ui_pow_ui
    else     return pow(mpArb(a),static_cast<unsigned long int>(b)); //arb_pow_ui
}

inline const mpArb pow(const long int a, const long int b)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    }else{
        return pow(mpArb(a),b); // arb_pow_si
    }
}

inline const mpArb pow(const long int a, const int b)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    }else{
        return pow(mpArb(a),static_cast<long int>(b)); // arb_pow_si
    }
}


inline const mpArb pow(const long int a, const long double b)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    else        return pow(mpArb(a),mpArb(b)); //arb_pow
}

inline const mpArb pow(const long int a, const double b)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    else        return pow(mpArb(a),mpArb(b)); //arb_pow
}

// pow int
inline const mpArb pow(const int a, const unsigned long int b)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),b); //arb_ui_pow_ui
    else     return pow(mpArb(a),b); //arb_pow_ui
}

inline const mpArb pow(const int a, const unsigned int b)
{
    if (a>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b));  //arb_ui_pow_ui
    else     return pow(mpArb(a),static_cast<unsigned long int>(b)); //arb_pow_ui
}

inline const mpArb pow(const int a, const long int b)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    }else{
        return pow(mpArb(a),b); // arb_pow_si
    }
}

inline const mpArb pow(const int a, const int b)
{
    if (a>0)
    {
        if(b>0) return pow(static_cast<unsigned long int>(a),static_cast<unsigned long int>(b)); //arb_ui_pow_ui
        else    return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    }else{
        return pow(mpArb(a),static_cast<long int>(b)); // arb_pow_si
    }
}


inline const mpArb pow(const int a, const long double b)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    else        return pow(mpArb(a),mpArb(b)); //arb_pow
}


inline const mpArb pow(const int a, const double b)
{
    if (a>=0)   return pow(static_cast<unsigned long int>(a),mpArb(b)); //arb_ui_pow
    else        return pow(mpArb(a),mpArb(b)); //arb_pow
}

// pow long double

inline const mpArb pow(const long double a, const long double b)
{
    return pow(mpArb(a),mpArb(b));
}


inline const mpArb pow(const long double a, const unsigned long int b)
{
    return pow(mpArb(a),b); //arb_pow_ui
}

inline const mpArb pow(const long double a, const unsigned int b)
{
    return pow(mpArb(a),static_cast<unsigned long int>(b)); //arb_pow_ui
}

inline const mpArb pow(const long double a, const long int b)
{
    return pow(mpArb(a),b); // arb_pow_si
}

inline const mpArb pow(const long double a, const int b)
{
    return pow(mpArb(a),static_cast<long int>(b)); // arb_pow_si
}



inline const mpArb pow(const double a, const double b)
{
    return pow(mpArb(a),mpArb(b));
}

inline const mpArb pow(const double a, const unsigned long int b)
{
    return pow(mpArb(a),b); // arb_pow_ui
}

inline const mpArb pow(const double a, const unsigned int b)
{
    return pow(mpArb(a),static_cast<unsigned long int>(b)); // arb_pow_ui
}

inline const mpArb pow(const double a, const long int b)
{
    return pow(mpArb(a),b); // arb_pow_si
}

inline const mpArb pow(const double a, const int b)
{
    return pow(mpArb(a),static_cast<long int>(b)); // arb_pow_si
}
} // End of mparb namespace


// Explicit specialization of std::swap for mpArb numbers
// Thus standard algorithms will use efficient version of swap (due to Koenig lookup)
// Non-throwing swap C++ idiom: http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-throwing_swap
namespace std
{
//	 only allowed to extend namespace std with specializations
//    template <>
//    inline void swap(mparb::mpArb& x, mparb::mpArb& y)
//    {
//        return arb_swap(x.mp, y.mp);
//    }

    template<>
    class numeric_limits<mparb::mpArb>
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
            mp_rnd_t r = mparb::mpArb::get_default_rnd();

            switch (r)
            {
                case MPFR_RNDN: return round_to_nearest;
                case MPFR_RNDZ: return round_toward_zero;
                case MPFR_RNDU: return round_toward_infinity;
                case MPFR_RNDD: return round_toward_neg_infinity;
                default: return round_indeterminate;
            }
        }

        inline static mparb::mpArb (min)    (mp_prec_t precision = mparb::mpArb::get_default_prec()) {  return  mparb::minval(precision);  }
        inline static mparb::mpArb (max)    (mp_prec_t precision = mparb::mpArb::get_default_prec()) {  return  mparb::maxval(precision);  }
        inline static mparb::mpArb lowest   (mp_prec_t precision = mparb::mpArb::get_default_prec()) {  return -mparb::maxval(precision);  }

        // Returns smallest eps such that 1 + eps != 1 (classic machine epsilon)
        inline static mparb::mpArb epsilon(mp_prec_t precision = mparb::mpArb::get_default_prec()) {  return  mparb::machine_epsilon(precision); }

        // Returns smallest eps such that x + eps != x (relative machine epsilon)
        inline static mparb::mpArb epsilon(const mparb::mpArb& x) {  return mparb::machine_epsilon(x);  }

        inline static mparb::mpArb round_error(mp_prec_t precision = mparb::mpArb::get_default_prec())
        {
            mp_rnd_t r = mparb::mpArb::get_default_rnd();

            if(r == MPFR_RNDN) return mparb::mpArb(0.5, precision);
            else               return mparb::mpArb(1.0, precision);
        }

        inline static const mparb::mpArb infinity()         { return mparb::const_infinity();     }
        inline static const mparb::mpArb quiet_NaN()        { return mparb::mpArb().setNan();    }
        inline static const mparb::mpArb signaling_NaN()    { return mparb::mpArb().setNan();    }
        inline static const mparb::mpArb denorm_min()       { return (min)();                    }

        // Please note, exponent range is not fixed in mparb
        static const int min_exponent = MPFR_EMIN_DEFAULT;
        static const int max_exponent = MPFR_EMAX_DEFAULT;
        arb_PERMISSIVE_EXPR static const int min_exponent10 = (int) (MPFR_EMIN_DEFAULT * 0.3010299956639811);
        arb_PERMISSIVE_EXPR static const int max_exponent10 = (int) (MPFR_EMAX_DEFAULT * 0.3010299956639811);

        // Should be constant according to standard, but 'digits' depends on precision in mparb

        inline static int digits()                        {    return mparb::mpArb::get_default_prec();    }
        inline static int digits(const mparb::mpArb& x)   {    return x.getPrecision();                    }

        inline static int digits10(mp_prec_t precision = mparb::mpArb::get_default_prec())
        {
            return mparb::bits2digits(precision);
        }

        inline static int digits10(const mparb::mpArb& x)
        {
            return mparb::bits2digits(x.getPrecision());
        }

        inline static int max_digits10(mp_prec_t precision = mparb::mpArb::get_default_prec())
        {
            return digits10(precision);
        }
    };

}

#endif /* __arb_H__ */
