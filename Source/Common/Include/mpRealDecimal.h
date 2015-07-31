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

#ifndef __mpdec_class_H__
#define __mpdec_class_H__
#endif

//#include <string>
//#include <iostream>
//#include <sstream>
#include <stdexcept>
#include <cfloat>
#include <cmath>
#include <limits>

#include "mpdecimal.h"

#include "mpfr.h"

// Options
#define mpdec_class_HAVE_INT64_SUPPORT             // Enable int64_t support if possible. Available only for MSVC 2010 & GCC.
#define mpdec_class_HAVE_MSVC_DEBUGVIEW              // Enable Debugger Visualizer for "Debug" builds in MSVC.

// Detect compiler using signatures from http://predef.sourceforge.net/
#if defined(__GNUC__) && defined(__INTEL_COMPILER)
    #define IsInf(x) isinf(x)                   // Intel ICC compiler on Linux

#elif defined(_MSC_VER)                         // Microsoft Visual C++
    #define IsInf(x) (!_finite(x))

#else
    #define IsInf(x) std::isinf(x)              // GNU C/C++ (and/or other compilers), just hope for C99 conformance
#endif



#if defined(mpdec_class_HAVE_MSVC_DEBUGVIEW) && defined(_MSC_VER) && defined(_DEBUG)
#define mpdec_class_MSVC_DEBUGVIEW_CODE         DebugView = toString();
    #define mpdec_class_MSVC_DEBUGVIEW_DATA     std::string DebugView;
#else
    #define mpdec_class_MSVC_DEBUGVIEW_CODE
    #define mpdec_class_MSVC_DEBUGVIEW_DATA
#endif


// Less important options
#define mpdec_class_DOUBLE_BITS_OVERFLOW -1          // Triggers overflow exception during conversion to double if mpdec_class
                                                // cannot fit in mpdec_class_DOUBLE_BITS_OVERFLOW bits
//                                                 = -1 disables overflow checks (default)
#if defined(__GNUC__)
  #define mpdec_class_PERMISSIVE_EXPR __extension__
#else
  #define mpdec_class_PERMISSIVE_EXPR
#endif

namespace mpDec {

class mpdec_class {
private:
    mpd_t* mp;

public:
    // Get default rounding mode & precision
    inline static int   get_default_rnd()    {    return (int)(mpd_getround(GetContext()));       }
    inline static size_t  get_default_prec()   {    return mpd_getprec(GetContext());                            }

    // Get global context
    inline static mpd_context_t* GetContext()
    {
        static mpd_context_t* GlobalCtx = NULL;
        if (GlobalCtx == NULL)
        {
            GlobalCtx = (mpd_context_t*)malloc(sizeof(mpd_context_t));
            mpd_init(GlobalCtx, 34);
        }
        return GlobalCtx;
    }

    // Constructors && type conversions
    mpdec_class();
    mpdec_class(const mpdec_class& u);
    mpdec_class(const mpd_t* u);
    mpdec_class(const double u);
    mpdec_class(const long double u);
    mpdec_class(const mpfr_t u);

    mpdec_class(const int32_t u);
    mpdec_class(const int64_t u);
    mpdec_class(const uint32_t u);
    mpdec_class(const uint64_t u);
    mpdec_class(const char* s);
    mpdec_class(const std::string& s);


    ~mpdec_class();

    // Operations
    // =
    // +, -, *, /, ++, --, <<, >>
    // *=, +=, -=, /=,
    // <, >, ==, <=, >=

    // =
    mpdec_class& operator=(const mpdec_class& v);
    mpdec_class& operator=(const long double v);
    mpdec_class& operator=(const double v);
    mpdec_class& operator=(const int32_t v);
    mpdec_class& operator=(const int64_t v);
    mpdec_class& operator=(const uint32_t v);
    mpdec_class& operator=(const uint64_t v);
    mpdec_class& operator=(const char* s);
    mpdec_class& operator=(const std::string& s);

    // +
    mpdec_class& operator+=(const mpdec_class& v);
    mpdec_class& operator+=(const long double u);
    mpdec_class& operator+=(const double u);
    mpdec_class& operator+=(const int32_t v);
    mpdec_class& operator+=(const int64_t v);
    mpdec_class& operator+=(const uint32_t v);
    mpdec_class& operator+=(const uint64_t v);


    const mpdec_class operator+() const;
    mpdec_class& operator++ ();
    const mpdec_class  operator++ (int);

    // -
    mpdec_class& operator-=(const mpdec_class& v);
    mpdec_class& operator-=(const long double u);
    mpdec_class& operator-=(const double u);
    mpdec_class& operator-=(const int32_t v);
    mpdec_class& operator-=(const int64_t v);
    mpdec_class& operator-=(const uint32_t v);
    mpdec_class& operator-=(const uint64_t v);
    const mpdec_class operator-() const;
    friend const mpdec_class operator-(const int32_t b,		 const mpdec_class& a);
    friend const mpdec_class operator-(const int64_t b,    const mpdec_class& a);
    friend const mpdec_class operator-(const uint32_t b,   const mpdec_class& a);
    friend const mpdec_class operator-(const uint64_t b,   const mpdec_class& a);
    friend const mpdec_class operator-(const double b,     const mpdec_class& a);
    mpdec_class& operator-- ();
    const mpdec_class  operator-- (int);

    // *
    mpdec_class& operator*=(const mpdec_class& v);
    mpdec_class& operator*=(const long double v);
    mpdec_class& operator*=(const double v);
    mpdec_class& operator*=(const int32_t v);
    mpdec_class& operator*=(const int64_t v);
    mpdec_class& operator*=(const uint32_t v);
    mpdec_class& operator*=(const uint64_t v);

    // /
    mpdec_class& operator/=(const mpdec_class& v);
    mpdec_class& operator/=(const long double v);
    mpdec_class& operator/=(const double v);
    mpdec_class& operator/=(const int32_t v);
    mpdec_class& operator/=(const int64_t v);
    mpdec_class& operator/=(const uint32_t v);
    mpdec_class& operator/=(const uint64_t v);
    friend const mpdec_class operator/(const int32_t b,		 const mpdec_class& a);
    friend const mpdec_class operator/(const int64_t b,    const mpdec_class& a);
    friend const mpdec_class operator/(const uint32_t b,   const mpdec_class& a);
    friend const mpdec_class operator/(const uint64_t b,   const mpdec_class& a);
    friend const mpdec_class operator/(const double b,     const mpdec_class& a);

    ////<<= Fast Multiplication by 2^u
    //mpdec_class& operator<<=(const unsigned long int u);
    //mpdec_class& operator<<=(const unsigned int u);
    //mpdec_class& operator<<=(const long int u);
    //mpdec_class& operator<<=(const int u);

    ////>>= Fast Division by 2^u
    //mpdec_class& operator>>=(const unsigned long int u);
    //mpdec_class& operator>>=(const unsigned int u);
    //mpdec_class& operator>>=(const long int u);
    //mpdec_class& operator>>=(const int u);

    // Boolean Operators
    friend bool operator >  (const mpdec_class& a, const mpdec_class& b);
    friend bool operator >= (const mpdec_class& a, const mpdec_class& b);
    friend bool operator <  (const mpdec_class& a, const mpdec_class& b);
    friend bool operator <= (const mpdec_class& a, const mpdec_class& b);
    friend bool operator == (const mpdec_class& a, const mpdec_class& b);
    friend bool operator != (const mpdec_class& a, const mpdec_class& b);

    // Optimized specializations for boolean operators
    friend bool operator == (const mpdec_class& a, const int32_t b);
    friend bool operator == (const mpdec_class& a, const int64_t b);
    friend bool operator == (const mpdec_class& a, const uint32_t b);
    friend bool operator == (const mpdec_class& a, const uint64_t b);
    friend bool operator == (const mpdec_class& a, const long double b);
    friend bool operator == (const mpdec_class& a, const double b);

    // Type Conversion operators
    int32_t         toLong      ()    const;
    uint32_t			  toULong     ()    const;
    int64_t         toInt64     ()    const;
    uint64_t        toUInt64    ()    const;
    double          toDouble    ()    const;
    //long double     toLDouble   ()    const;
    // Convert mpdec_class to string with n significant digits in base b
    // n = 0 -> convert with the maximum available digits
		std::string        toString(int n = 0, int b = 10) const;
    std::string        toString(const std::string& format) const;

    // Get raw pointers so that mpdec_class can be directly used in raw mpd_* functions
    mpd_t* mpd_ptr();
//    mpd_ptr mpd_ptr()    const;
//    mpd_ptr mpd_srcptr() const;





    // Math Functions
    friend const mpdec_class sqr (const mpdec_class& v);

    friend const mpdec_class sqrt(const mpdec_class& v);


	friend const mpdec_class sqrt(const unsigned long int v);
    friend const mpdec_class cbrt(const mpdec_class& v);
    friend const mpdec_class root(const mpdec_class& v, unsigned long int k);

    friend const mpdec_class pow (const mpdec_class& a, const mpdec_class& b);

    friend const mpdec_class pow (const mpdec_class& a, const mpz_t b);



    friend const mpdec_class pow (const mpdec_class& a, const uint64_t b);
    friend const mpdec_class pow (const mpdec_class& a, const int64_t b);
    friend const mpdec_class pow (const uint64_t a, const mpdec_class& b);
//    friend const mpdec_class pow (const unsigned long int a, const unsigned long int b);

	friend const mpdec_class fabs(const mpdec_class& v);


    friend const mpdec_class abs(const mpdec_class& v);


	friend const mpdec_class dim(const mpdec_class& a, const mpdec_class& b);
// Change DH Begin
    friend const mpdec_class fdim(const mpdec_class& a, const mpdec_class& b);
// Change DH End


    friend inline const mpdec_class mul_2ui(const mpdec_class& v, unsigned long int k);
    friend inline const mpdec_class mul_2si(const mpdec_class& v, long int k);
    friend inline const mpdec_class div_2ui(const mpdec_class& v, unsigned long int k);
    friend inline const mpdec_class div_2si(const mpdec_class& v, long int k);
    friend int cmpabs(const mpdec_class& a,const mpdec_class& b);

    friend const mpdec_class ln  (const mpdec_class& v);

    friend const mpdec_class log  (const mpdec_class& v);
    friend const mpdec_class ilogb(const mpdec_class& v);
    friend const mpdec_class logb(const mpdec_class& v);


	friend const mpdec_class log2 (const mpdec_class& v);

	friend const mpdec_class log10(const mpdec_class& v);

	friend const mpdec_class exp  (const mpdec_class& v);


	friend const mpdec_class exp2 (const mpdec_class& v);
    friend const mpdec_class exp10(const mpdec_class& v);
    friend const mpdec_class log1p(const mpdec_class& v);
    friend const mpdec_class expm1(const mpdec_class& v);

    friend const mpdec_class cos(const mpdec_class& v);
    friend const mpdec_class sin(const mpdec_class& v);
    friend const mpdec_class tan(const mpdec_class& v);
    friend const mpdec_class sec(const mpdec_class& v);
    friend const mpdec_class csc(const mpdec_class& v);
    friend const mpdec_class cot(const mpdec_class& v);
    friend int sin_cos(mpdec_class& s, mpdec_class& c, const mpdec_class& v);

    friend const mpdec_class acos  (const mpdec_class& v);
    friend const mpdec_class asin  (const mpdec_class& v);
    friend const mpdec_class atan  (const mpdec_class& v);
    friend const mpdec_class atan2 (const mpdec_class& y, const mpdec_class& x);
    friend const mpdec_class acot  (const mpdec_class& v);
    friend const mpdec_class asec  (const mpdec_class& v);
    friend const mpdec_class acsc  (const mpdec_class& v);

    friend const mpdec_class cosh  (const mpdec_class& v);
    friend const mpdec_class sinh  (const mpdec_class& v);
    friend const mpdec_class tanh  (const mpdec_class& v);
    friend const mpdec_class sech  (const mpdec_class& v);
    friend const mpdec_class csch  (const mpdec_class& v);
    friend const mpdec_class coth  (const mpdec_class& v);
    friend const mpdec_class acosh (const mpdec_class& v);
    friend const mpdec_class asinh (const mpdec_class& v);
    friend const mpdec_class atanh (const mpdec_class& v);
    friend const mpdec_class acoth (const mpdec_class& v);
    friend const mpdec_class asech (const mpdec_class& v);
    friend const mpdec_class acsch (const mpdec_class& v);

    friend const mpdec_class hypot (const mpdec_class& x, const mpdec_class& y);
// Change DH Begin
    friend const mpdec_class copysign (const mpdec_class& y, const mpdec_class& x);
// Change DH End

    friend const mpdec_class fac_ui (uint32_t v);
    friend const mpdec_class eint   (const mpdec_class& v);

    friend const mpdec_class gamma    (const mpdec_class& v);
    friend const mpdec_class tgamma    (const mpdec_class& v);

    friend const mpdec_class lngamma  (const mpdec_class& v);
    friend const mpdec_class lgamma   (const mpdec_class& v, int *signp = 0);
    friend const mpdec_class zeta     (const mpdec_class& v);
    friend const mpdec_class erf      (const mpdec_class& v);
    friend const mpdec_class erfc     (const mpdec_class& v);
    friend const mpdec_class besselj0 (const mpdec_class& v);
    friend const mpdec_class besselj1 (const mpdec_class& v);
    friend const mpdec_class besseljn (long n, const mpdec_class& v);
    friend const mpdec_class bessely0 (const mpdec_class& v);
    friend const mpdec_class bessely1 (const mpdec_class& v);
    friend const mpdec_class besselyn (long n, const mpdec_class& v);
    friend const mpdec_class fma      (const mpdec_class& v1, const mpdec_class& v2, const mpdec_class& v3);
    friend const mpdec_class fms      (const mpdec_class& v1, const mpdec_class& v2, const mpdec_class& v3);
    friend const mpdec_class agm      (const mpdec_class& v1, const mpdec_class& v2);
    friend const mpdec_class sum      (const mpdec_class tab[], unsigned long int n);

	friend int sgn(const mpdec_class& v); // returns -1 or +1



// mpfi 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))
    friend int          sinh_cosh   (mpdec_class& s, mpdec_class& c, const mpdec_class& v);
    friend const mpdec_class li2         (const mpdec_class& v);
    friend const mpdec_class fmod        (const mpdec_class& x, const mpdec_class& y);

    friend const mpdec_class rec_sqrt    (const mpdec_class& v);

    // MATLAB's semantic equivalents
    friend const mpdec_class rem (const mpdec_class& x, const mpdec_class& y); // Remainder after division
    friend const mpdec_class mod (const mpdec_class& x, const mpdec_class& y); // Modulus after division
#endif


// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend const mpdec_class digamma (const mpdec_class& v);
    friend const mpdec_class ai      (const mpdec_class& v);
    friend const mpdec_class urandom (gmp_randstate_t& state);     // use gmp_randinit_default() to init state, gmp_randclear() to clear
#endif


    // Uniformly distributed random number generation in [0,1] using
    // Mersenne-Twister algorithm by default.
    // Use parameter to setup seed, e.g.: random((unsigned)time(NULL))
    // Check urandom() for more precise control.
    friend const mpdec_class random(unsigned int seed = 0);


    // Exponent and mantissa manipulation
    friend const mpdec_class frexp(const mpdec_class& v, mp_exp_t* exp);
    friend const mpdec_class ldexp(const mpdec_class& v, mp_exp_t exp);


// Change DH Begin
    friend const mpdec_class ldexp(const mpdec_class& v, const mpdec_class& e);
    friend const mpdec_class scalbn(const mpdec_class& v, const mpdec_class& e);
    friend const mpdec_class scalbln(const mpdec_class& v, const mpdec_class& e);
// Change DH End


    // Splits mpdec_class value into fractional and integer parts.
    // Returns fractional part and stores integer part in n.
    friend const mpdec_class modf(const mpdec_class& v, mpdec_class& n);



    // Constants
    // don't forget to call mpfi_free_cache() for every thread where you are using const-functions
    friend const mpdec_class const_log2      ();
    friend const mpdec_class const_pi        ();
    friend const mpdec_class const_euler     ();
    friend const mpdec_class const_catalan   ();

    friend const mpdec_class const_log2_a      (const mpdec_class& v);
    friend const mpdec_class const_pi_a      (const mpdec_class& v);
    friend const mpdec_class const_euler_gamma_a      (const mpdec_class& v);
    friend const mpdec_class const_catalan_a      (const mpdec_class& v);



    // returns +inf iff sign>=0 otherwise -inf
    friend const mpdec_class const_infinity(int sign = 1);

    // Output/ Input
    friend std::ostream& operator<<(std::ostream& os, const mpdec_class& v);
    friend std::istream& operator>>(std::istream& is, mpdec_class& v);


    // Integer Related Functions
    friend const mpdec_class rint (const mpdec_class& v);

// Change DH Begin
    friend const mpdec_class lrint (const mpdec_class& v);
    friend const mpdec_class llrint (const mpdec_class& v);
    friend const mpdec_class nearbyint (const mpdec_class& v);
// Change DH End



    friend const mpdec_class ceil (const mpdec_class& v);
    friend const mpdec_class floor(const mpdec_class& v);
    friend const mpdec_class round(const mpdec_class& v);


// Change DH Begin
    friend const mpdec_class lround(const mpdec_class& v);
    friend const mpdec_class llround(const mpdec_class& v);

    friend const mpdec_class sign (const mpdec_class& v);

// Change DH End


    friend const mpdec_class trunc(const mpdec_class& v);



    friend const mpdec_class rint_ceil   (const mpdec_class& v);
    friend const mpdec_class rint_floor  (const mpdec_class& v);
    friend const mpdec_class rint_round  (const mpdec_class& v);
    friend const mpdec_class rint_trunc  (const mpdec_class& v);
    friend const mpdec_class frac        (const mpdec_class& v);
    friend const mpdec_class remainder   (         const mpdec_class& x, const mpdec_class& y);
    friend const mpdec_class remquo      (long* q, const mpdec_class& x, const mpdec_class& y);
// Change DH Begin
    friend const mpdec_class remquo      (const mpdec_class& x, const mpdec_class& y, int* q);
// Change DH End

    // Miscellaneous Functions
    friend const mpdec_class nexttoward (const mpdec_class& x, const mpdec_class& y);
// Change DH Begin
    friend const mpdec_class nextafter (const mpdec_class& x, const mpdec_class& y);
// Change DH End



    friend const mpdec_class nextabove  (const mpdec_class& x);
    friend const mpdec_class nextbelow  (const mpdec_class& x);

    // use gmp_randinit_default() to init state, gmp_randclear() to clear
    friend const mpdec_class urandomb (gmp_randstate_t& state);

// mpfi < 2.4.2 Specifics
#if (MPFR_VERSION <= MPFR_VERSION_NUM(2,4,2))
    friend const mpdec_class random2 (mp_size_t size, mp_exp_t exp);
#endif

   //  Instance Checkers
 //   inline bool isnan    (const mpdec_class& v);
    friend bool isnan    (const mpdec_class& v);
    friend bool isinf    (const mpdec_class& v);
    friend bool isfinite (const mpdec_class& v);

    friend bool isnum    (const mpdec_class& v);
    friend bool iszero   (const mpdec_class& v);
    friend bool isint    (const mpdec_class& v);


#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
    friend bool isregular(const mpdec_class& v);
#endif


    // Set/Get instance properties
    inline size_t    get_prec() const;
    inline void         set_prec(mpd_ssize_t prec);    // Change precision with rounding mode

    // Aliases for get_prec(), set_prec() - needed for compatibility with std::complex<mpdec_class> interface
    inline mpdec_class&      setPrecision(mpd_ssize_t Precision);
    inline size_t          getPrecision() const;

    // Set mpdec_class to +/- inf, NaN, +/-0
    mpdec_class&        setInf  (int Sign = +1);
    mpdec_class&        setNan  ();
    mpdec_class&        setZero (int Sign = +1);
    mpdec_class&        setSign (int Sign);


    //Exponent
    int get_exp();
    int set_exp(int e);
    int check_range  (int t);
    int subnormalize (int t);

    // Inexact conversion from float
    inline bool fits_in_bits(double x, int n);

    // Set/Get global properties
    static void            set_default_prec(mpd_ssize_t prec);
    static void            set_default_rnd(int rnd_mode);

		static void set_precision(int prec);
		static void set_decimal32();
		static void set_decimal64();
		static void set_decimal128();

    static mpd_ssize_t  get_emin (void);
    static mpd_ssize_t  get_emax (void);

    static mpd_ssize_t  get_emin_min (void);
    static mpd_ssize_t  get_emin_max (void);
    static mpd_ssize_t  get_emax_min (void);
    static mpd_ssize_t  get_emax_max (void);

    static int       set_emin (mpd_ssize_t exp);
    static int       set_emax (mpd_ssize_t exp);

    // Efficient swapping of two mpdec_class values - needed for std algorithms

    friend void swap(mpdec_class& x, mpdec_class& y);

    friend const mpdec_class fmax(const mpdec_class& x, const mpdec_class& y);
    friend const mpdec_class fmin(const mpdec_class& x, const mpdec_class& y);



private:
    // Human friendly Debug Preview in Visual Studio.
    // Put one of these lines:
    //
    // mpfi::mpdec_class=<DebugView>                                ; Show value only
    // mpfi::mpdec_class=<DebugView>, <mp[0]._mpfi_prec,u>bits    ; Show value & precision
    //
    // at the beginning of
    // [Visual Studio Installation Folder]\Common7\Packages\Debugger\autoexp.dat
    mpdec_class_MSVC_DEBUGVIEW_DATA
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
inline mpdec_class::mpdec_class()
{
		mp = mpd_new(GetContext());
		mpd_set_i32(mp, 0, GetContext());

	  mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const mpdec_class& u)
{
		mp = mpd_new(GetContext());
		mpd_copy(mp, u.mp, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const double u)
{
	mp = mpd_new(GetContext());
    char my_string[26];   //To hold . and null
    sprintf(my_string,"%.15E",u);
	mpd_set_string(mp, my_string, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}


inline mpdec_class::mpdec_class(const long double u)
{
	mp = mpd_new(GetContext());
    char my_string[30];   //To hold . and null
    sprintf(my_string,"%.19LE",u);
	mpd_set_string(mp, my_string, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}


inline mpdec_class::mpdec_class(const mpfr_t u)
{
	mp = mpd_new(GetContext());
	long double x = mpfr_get_ld (u, mpfr_get_default_rounding_mode());
    char my_string[30];   //To hold . and null
    sprintf(my_string,"%.19LE",x);
	mpd_set_string(mp, my_string, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}



inline mpdec_class::mpdec_class(const int32_t u)
{
	mp = mpd_new(GetContext());
	mpd_set_i32(mp, u, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const int64_t u)
{
	mp = mpd_new(GetContext());
	mpd_set_i64(mp, u, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const uint32_t u)
{
	mp = mpd_new(GetContext());
	mpd_set_u32(mp, u, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const uint64_t u)
{
	mp = mpd_new(GetContext());
	mpd_set_u64(mp, u, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const char* s)
{
	mp = mpd_new(GetContext());
  mpd_set_string(mp, s, GetContext());


    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::mpdec_class(const std::string& s)
{
	mp = mpd_new(GetContext());
  mpd_set_string(mp, s.c_str(), GetContext());


    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

inline mpdec_class::~mpdec_class()
{
    mpd_del(mp);
}

// internal namespace needed for template magic
namespace internal{

    // Use SFINAE to restrict arithmetic operations instantiation only for numeric types
    // This is needed for smooth integration with libraries based on expression templates, like Eigen.
    // TODO: Do the same for boolean operators.
    template <typename ArgumentType> struct result_type {};

    template <> struct result_type<mpdec_class>         {typedef mpdec_class type;};
    template <> struct result_type<long double>         {typedef mpdec_class type;};
    template <> struct result_type<double>              {typedef mpdec_class type;};
    template <> struct result_type<unsigned long int>   {typedef mpdec_class type;};
    template <> struct result_type<unsigned int>        {typedef mpdec_class type;};
    template <> struct result_type<long int>            {typedef mpdec_class type;};
    template <> struct result_type<int>                 {typedef mpdec_class type;};

//#if defined (mpdec_class_HAVE_INT64_SUPPORT)
    template <> struct result_type<int64_t  >           {typedef mpdec_class type;};
    template <> struct result_type<uint64_t >           {typedef mpdec_class type;};
//#endif
}

// + Addition
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator+(const mpdec_class& lhs, const Rhs& rhs){ return mpdec_class(lhs) += rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator+(const Lhs& lhs, const mpdec_class& rhs){ return mpdec_class(rhs) += lhs;    }

// - Subtraction
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator-(const mpdec_class& lhs, const Rhs& rhs){ return mpdec_class(lhs) -= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator-(const Lhs& lhs, const mpdec_class& rhs){ return mpdec_class(lhs) -= rhs;    }

// * Multiplication
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator*(const mpdec_class& lhs, const Rhs& rhs){ return mpdec_class(lhs) *= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator*(const Lhs& lhs, const mpdec_class& rhs){ return mpdec_class(rhs) *= lhs;    }

// / Division
template <typename Rhs>
inline const typename internal::result_type<Rhs>::type
    operator/(const mpdec_class& lhs, const Rhs& rhs){ return mpdec_class(lhs) /= rhs;    }

template <typename Lhs>
inline const typename internal::result_type<Lhs>::type
    operator/(const Lhs& lhs, const mpdec_class& rhs){ return mpdec_class(lhs) /= rhs;    }

////////////////////////////////////////////////////////////////////////
// sqrt
const mpdec_class sqrt(const unsigned int v);
const mpdec_class sqrt(const long int v);
const mpdec_class sqrt(const int v);
const mpdec_class sqrt(const long double v);
const mpdec_class sqrt(const double v);

////////////////////////////////////////////////////////////////////////
// pow



const mpdec_class pow(const mpdec_class& a, const uint32_t b);
const mpdec_class pow(const mpdec_class& a, const int32_t b);
const mpdec_class pow(const mpdec_class& a, const long double b);
const mpdec_class pow(const mpdec_class& a, const double b);

const mpdec_class pow(const uint32_t a, const mpdec_class& b);
const mpdec_class pow(const int64_t a, const mpdec_class& b);
const mpdec_class pow(const int32_t a, const mpdec_class& b);
const mpdec_class pow(const long double a, const mpdec_class& b);
const mpdec_class pow(const double a, const mpdec_class& b);
//
//const mpdec_class pow(const unsigned long int a, const unsigned int b);
//const mpdec_class pow(const unsigned long int a, const long int b);
//const mpdec_class pow(const unsigned long int a, const int b);
//const mpdec_class pow(const unsigned long int a, const long double b);
//const mpdec_class pow(const unsigned long int a, const double b);
//
//const mpdec_class pow(const unsigned int a, const unsigned long int b);
//const mpdec_class pow(const unsigned int a, const unsigned int b);
//const mpdec_class pow(const unsigned int a, const long int b);
//const mpdec_class pow(const unsigned int a, const int b);
//const mpdec_class pow(const unsigned int a, const long double b);
//const mpdec_class pow(const unsigned int a, const double b);
//
//const mpdec_class pow(const long int a, const unsigned long int b);
//const mpdec_class pow(const long int a, const unsigned int b);
//const mpdec_class pow(const long int a, const long int b);
//const mpdec_class pow(const long int a, const int b);
//const mpdec_class pow(const long int a, const long double b);
//const mpdec_class pow(const long int a, const double b);
//
//const mpdec_class pow(const int a, const unsigned long int b);
//const mpdec_class pow(const int a, const unsigned int b);
//const mpdec_class pow(const int a, const long int b);
//const mpdec_class pow(const int a, const int b);
//const mpdec_class pow(const int a, const long double b);
//const mpdec_class pow(const int a, const double b);
//
//const mpdec_class pow(const long double a, const long double b);
//const mpdec_class pow(const long double a, const unsigned long int b);
//const mpdec_class pow(const long double a, const unsigned int b);
//const mpdec_class pow(const long double a, const long int b);
//const mpdec_class pow(const long double a, const int b);
//
//const mpdec_class pow(const double a, const double b);
//const mpdec_class pow(const double a, const unsigned long int b);
//const mpdec_class pow(const double a, const unsigned int b);
//const mpdec_class pow(const double a, const long int b);
//const mpdec_class pow(const double a, const int b);

////////////////////////////////////////////////////////////////////////
// Estimate machine epsilon for the given precision
// Returns smallest eps such that 1.0 + eps != 1.0
inline mpdec_class machine_epsilon();

// Returns smallest eps such that x + eps != x (relative machine epsilon)
inline mpdec_class machine_epsilon(const mpdec_class& x);

inline mpdec_class machine_epsilon(const size_t prec);

// Gives max & min values for the required precision,
// minval is 'safe' meaning 1 / minval does not overflow
// maxval is 'safe' meaning 1 / maxval does not underflow
mpdec_class minval(int prec = mpDec::mpdec_class::get_default_prec());
//inline mpdec_class minval(int prec = mpDec::mpdec_class::get_default_prec());

mpdec_class maxval(int prec = mpDec::mpdec_class::get_default_prec());
//inline mpdec_class maxval(int prec = mpDec::mpdec_class::get_default_prec());



// 'Dirty' equality check 1: |a-b| < min{|a|,|b|} * eps
inline bool isEqualFuzzy(const mpdec_class& a, const mpdec_class& b, const mpdec_class& eps);

// 'Dirty' equality check 2: |a-b| < min{|a|,|b|} * eps( min{|a|,|b|} )
inline bool isEqualFuzzy(const mpdec_class& a, const mpdec_class& b);

// 'Bitwise' equality check
//  maxUlps - a and b can be apart by maxUlps binary numbers.
inline bool isEqualUlps(const mpdec_class& a, const mpdec_class& b, int maxUlps);

//////////////////////////////////////////////////////////////////////////
//     Convert precision in 'bits' to decimal digits and vice versa.
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

inline size_t digits2bits(int d);
inline int       bits2digits(size_t b);

//////////////////////////////////////////////////////////////////////////
// min, max
const mpdec_class (max)(const mpdec_class& x, const mpdec_class& y);
const mpdec_class (min)(const mpdec_class& x, const mpdec_class& y);

//////////////////////////////////////////////////////////////////////////
// Implementation
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Operators - Assignment
inline mpdec_class& mpdec_class::operator=(const mpdec_class& v)
{
		mpd_copy(mp, v.mp, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

// Change DH
inline mpdec_class& mpdec_class::operator=(const long double v)
{
    double d = v;
    char my_string[36];   //To hold . and null
    sprintf(my_string,"%.15E",d);
    mpd_set_string(mp, my_string, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}
// End Change DH


inline mpdec_class& mpdec_class::operator=(const double v)
{
    char my_string[26];   //To hold . and null
    sprintf(my_string,"%.15E",v);
    mpd_set_string(mp, my_string, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator=(const int32_t v)
{
   mpd_set_i32(mp, v, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator=(const int64_t v)
{
   mpd_set_i64(mp, v, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator=(const uint32_t v)
{
    mpd_set_u32(mp, v, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator=(const uint64_t v)
{
    mpd_set_i64(mp, v, GetContext());

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator=(const char* s)
{
    // Use other converters for more precise control on base & precision & rounding:
    // Here we assume base = 10 and we use precision of target variable.
		mpd_t *t;
		t = mpd_new(GetContext());
		mpd_set_string(t, s, GetContext());
		mpd_copy(mp, t, GetContext());
		mpd_del(t);

		return *this;
}

inline mpdec_class& mpdec_class::operator=(const std::string& s)
{
    // Use other converters for more precise control on base & precision & rounding:
    // Here we assume base = 10 and we use precision of target variable.
		mpd_t *t;
		t = mpd_new(GetContext());
		mpd_set_string(t, s.c_str(), GetContext());
		mpd_copy(mp, t, GetContext());
		mpd_del(t);

    return *this;
}


//////////////////////////////////////////////////////////////////////////
// + Addition
inline mpdec_class& mpdec_class::operator+=(const mpdec_class& v)
{
    mpd_add(mp, mp, v.mp, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

// Change DH
inline mpdec_class& mpdec_class::operator+= (const long double u)
{
    *this += mpdec_class(u);
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}
// End Change DH

inline mpdec_class& mpdec_class::operator+= (const double u)
{
    *this += mpdec_class(u);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpdec_class& mpdec_class::operator+=(const int32_t u)
{
    mpd_add_i32(mp, mp, u, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator+=(const int64_t u)
{
    mpd_add_i64(mp, mp, u, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}


inline mpdec_class& mpdec_class::operator+=(const uint32_t u)
{
    mpd_add_u32(mp, mp, u, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator+=(const uint64_t u)
{
    mpd_add_u64(mp, mp, u, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

#if defined (mpdec_class_HAVE_INT64_SUPPORT)
//inline mpdec_class& mpdec_class::operator+=(const int64_t  u){    *this += mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator+=(const uint64_t u){    *this += mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator-=(const int64_t  u){    *this -= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator-=(const uint64_t u){    *this -= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator*=(const int64_t  u){    *this *= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator*=(const uint64_t u){    *this *= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator/=(const int64_t  u){    *this /= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
//inline mpdec_class& mpdec_class::operator/=(const uint64_t u){    *this /= mpdec_class(u); mpdec_class_MSVC_DEBUGVIEW_CODE; return *this;    }
#endif

inline const mpdec_class mpdec_class::operator+()const    {    return mpdec_class(*this); }

inline const mpdec_class operator+(const mpdec_class& a, const mpdec_class& b)
{
	return mpdec_class(b) += a;
}

inline mpdec_class& mpdec_class::operator++()
{
    return *this += 1;
}

inline const mpdec_class mpdec_class::operator++ (int)
{
    mpdec_class x(*this);
    *this += 1;
    return x;
}

inline mpdec_class& mpdec_class::operator--()
{
    return *this -= 1;
}

inline const mpdec_class mpdec_class::operator-- (int)
{
    mpdec_class x(*this);
    *this -= 1;
    return x;
}

//////////////////////////////////////////////////////////////////////////
// - Subtraction
inline mpdec_class& mpdec_class::operator-=(const mpdec_class& v)
{
    mpd_sub(mp, mp, v.mp, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

// Change DH
inline mpdec_class& mpdec_class::operator-=(const long double v)
{
    *this -= mpdec_class(v);
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}
// End Change DH

inline mpdec_class& mpdec_class::operator-=(const double v)
{
    *this -= mpdec_class(v);

	mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator-=(const int32_t v)
{
    mpd_sub_i32(mp, mp, v, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator-=(const int64_t v)
{
    mpd_sub_i64(mp, mp, v, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator-=(const uint32_t v)
{
    mpd_sub_u32(mp, mp, v, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator-=(const uint64_t v)
{
    mpd_sub_u64(mp, mp, v, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpdec_class mpdec_class::operator-()const
{
		mpdec_class u(*this);

		mpd_minus(u.mp, u.mp, GetContext());
    return u;
}

inline const mpdec_class operator-(const mpdec_class& a, const mpdec_class& b)
{
	return -(mpdec_class(b) -= a);
}

inline const mpdec_class operator-(const double  b, const mpdec_class& a)
{
		return -(mpdec_class(a) -= b);
}

inline const mpdec_class operator-(const int32_t b, const mpdec_class& a)
{
    return -(mpdec_class(a) -= b);
}

inline const mpdec_class operator-(const int64_t b, const mpdec_class& a)
{
    return -(mpdec_class(a) -= b);
}

inline const mpdec_class operator-(const uint32_t b, const mpdec_class& a)
{
    return -(mpdec_class(a) -= b);
}

inline const mpdec_class operator-(const uint64_t b, const mpdec_class& a)
{
    return -(mpdec_class(a) -= b);
}

//////////////////////////////////////////////////////////////////////////
// * Multiplication
inline mpdec_class& mpdec_class::operator*= (const mpdec_class& v)
{
    mpd_mul(mp, mp, v.mp, GetContext());

		mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

// Change DH
inline mpdec_class& mpdec_class::operator*=(const long double v)
{
    *this *= mpdec_class(v);
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}
// End Change DH

inline mpdec_class& mpdec_class::operator*=(const double v)
{

		return *this *= mpdec_class(v);
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator*=(const int32_t v)
{
    mpd_mul_i32(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator*=(const int64_t v)
{
    mpd_mul_i64(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator*=(const uint32_t v)
{
    mpd_mul_u32(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator*=(const uint64_t v)
{
    mpd_mul_u64(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpdec_class operator*(const mpdec_class& a, const mpdec_class& b)
{
	return   mpdec_class(b) *= a;
}

//////////////////////////////////////////////////////////////////////////
// / Division
inline mpdec_class& mpdec_class::operator/=(const mpdec_class& v)
{
    mpd_div(mp, mp, v.mp, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

// Change DH
inline mpdec_class& mpdec_class::operator/=(const long double v)
{
    return *this /= mpdec_class(v);
}
// End Change DH

inline mpdec_class& mpdec_class::operator/=(const double v)
{

	return *this /= mpdec_class(v);
}

inline mpdec_class& mpdec_class::operator/=(const int32_t v)
{
    mpd_div_i32(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator/=(const int64_t v)
{
    mpd_div_i64(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator/=(const uint32_t v)
{
    mpd_div_u32(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::operator/=(const uint64_t v)
{
   mpd_div_u64(mp, mp, v, GetContext());
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline const mpdec_class operator/(const mpdec_class& a, const mpdec_class& b)
{
	return mpdec_class(a) /= b;
}

inline const mpdec_class operator/(const int32_t b, const mpdec_class& a)
{
	mpdec_class x(b);
	return x/a;
}

inline const mpdec_class operator/(const int64_t b, const mpdec_class& a)
{
	mpdec_class x(b);
	return x/a;
}

inline const mpdec_class operator/(const uint32_t b, const mpdec_class& a)
{
	mpdec_class x(b);
	return x/a;
}

inline const mpdec_class operator/(const uint64_t b, const mpdec_class& a)
{
	mpdec_class x(b);
	return x/a;
}

inline const mpdec_class operator/(const double  b, const mpdec_class& a)
{
	mpdec_class x(b);
	return x/a;
}

//////////////////////////////////////////////////////////////////////////
// Shifts operators - Multiplication/Division by power of 2
//inline mpdec_class& mpdec_class::operator<<=(const unsigned long int u)
//{
//    mpfi_mul_2ui(mp,mp,u);
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator<<=(const unsigned int u)
//{
//    mpfi_mul_2ui(mp,mp,static_cast<unsigned long int>(u));
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator<<=(const long int u)
//{
//    mpfi_mul_2si(mp,mp,u);
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator<<=(const int u)
//{
//    mpfi_mul_2si(mp,mp,static_cast<long int>(u));
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator>>=(const unsigned long int u)
//{
//    mpfi_div_2ui(mp,mp,u);
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator>>=(const unsigned int u)
//{
//    mpfi_div_2ui(mp,mp,static_cast<unsigned long int>(u));
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator>>=(const long int u)
//{
//    mpfi_div_2si(mp,mp,u);
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline mpdec_class& mpdec_class::operator>>=(const int u)
//{
//    mpfi_div_2si(mp,mp,static_cast<long int>(u));
//    mpdec_class_MSVC_DEBUGVIEW_CODE;
//    return *this;
//}
//
//inline const mpdec_class operator<<(const mpdec_class& v, const unsigned long int k)
//{
//    return mul_2ui(v,k);
//}
//
//inline const mpdec_class operator<<(const mpdec_class& v, const unsigned int k)
//{
//    return mul_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpdec_class operator<<(const mpdec_class& v, const long int k)
//{
//    return mul_2si(v,k);
//}
//
//inline const mpdec_class operator<<(const mpdec_class& v, const int k)
//{
//    return mul_2si(v,static_cast<long int>(k));
//}
//
//inline const mpdec_class operator>>(const mpdec_class& v, const unsigned long int k)
//{
//    return div_2ui(v,k);
//}
//
//inline const mpdec_class operator>>(const mpdec_class& v, const long int k)
//{
//    return div_2si(v,k);
//}
//
//inline const mpdec_class operator>>(const mpdec_class& v, const unsigned int k)
//{
//    return div_2ui(v,static_cast<unsigned long int>(k));
//}
//
//inline const mpdec_class operator>>(const mpdec_class& v, const int k)
//{
//    return div_2si(v,static_cast<long int>(k));
//}
//
//// mul_2ui
//inline const mpdec_class mul_2ui(const mpdec_class& v, unsigned long int k, mp_rnd_t rnd_mode)
//{
//    mpdec_class x(v);
//    mpfi_mul_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//// mul_2si
//inline const mpdec_class mul_2si(const mpdec_class& v, long int k, mp_rnd_t rnd_mode)
//{
//    mpdec_class x(v);
//    mpfi_mul_2si(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpdec_class div_2ui(const mpdec_class& v, unsigned long int k, mp_rnd_t rnd_mode)
//{
//    mpdec_class x(v);
//    mpfi_div_2ui(x.mp,v.mp,k);
//    return x;
//}
//
//inline const mpdec_class div_2si(const mpdec_class& v, long int k, mp_rnd_t rnd_mode)
//{
//    mpdec_class x(v);
//    mpfi_div_2si(x.mp,v.mp,k);
//    return x;
//}


//////////////////////////////////////////////////////////////////////////
//Boolean operators
inline bool operator >  (const mpdec_class& a, const mpdec_class& b)
{
	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp > 0)!=0);
}

inline bool operator >=  (const mpdec_class& a, const mpdec_class& b)
{
 	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp >= 0)!=0);
}


inline bool operator <  (const mpdec_class& a, const mpdec_class& b)
{
 	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp < 0)!=0);
}



inline bool operator <=  (const mpdec_class& a, const mpdec_class& b)
{
 	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp <= 0)!=0);
}


inline bool operator ==  (const mpdec_class& a, const mpdec_class& b)
{
  	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp == 0)!=0);
}


inline bool operator !=  (const mpdec_class& a, const mpdec_class& b)
{
 	int cmp = mpd_cmp(a.mp, b.mp, mpdec_class::GetContext());
	return ((cmp != 0)!=0);
}


inline bool operator == (const mpdec_class& a, const int32_t b ){    return (a == mpdec_class(b));    }
inline bool operator == (const mpdec_class& a, const int64_t b ){    return (a == mpdec_class(b));    }
inline bool operator == (const mpdec_class& a, const uint32_t b ){    return (a == mpdec_class(b));    }
inline bool operator == (const mpdec_class& a, const uint64_t b ){    return (a == mpdec_class(b));    }
// Change DH
inline bool operator == (const mpdec_class& a, const long double b ){    return (a == mpdec_class(b));    }
//
inline bool operator == (const mpdec_class& a, const double b ){    return (a == mpdec_class(b));    }

inline bool isnan    (const mpdec_class& v){    return (mpd_isnan(v.mp)     != 0);    }
inline bool isinf    (const mpdec_class& v){    return (mpd_isinfinite(v.mp)     != 0);    }
inline bool isfinite (const mpdec_class& v){    return (mpd_isfinite(v.mp)  != 0);    }
inline bool iszero   (const mpdec_class& v){    return (mpd_iszero(v.mp)    != 0);    }

inline bool isint    (const mpdec_class& v){    return (mpd_isinteger(v.mp)    != 0);    }


//#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
// Change DH
inline bool isregular(const mpdec_class& v){    return (true);}
// End Change DH
//#endif

//////////////////////////////////////////////////////////////////////////
// Type Converters
/* Change DH */
inline int32_t     mpdec_class::toLong()	const    {    return mpd_get_i32(mp, GetContext());    }
inline uint32_t    mpdec_class::toULong()	const    {    return mpd_get_u32(mp, GetContext());    }
inline int64_t     mpdec_class::toInt64()   const    {    return mpd_get_i64(mp, GetContext());    }
inline uint64_t    mpdec_class::toUInt64()  const    {    return mpd_get_u64(mp, GetContext());    }
inline double      mpdec_class::toDouble()  const    {    char *s = mpd_to_sci(mp, 1);	return atof(s);	  }

inline mpd_t*     mpdec_class::mpd_ptr()             { return mp; }




template <class T>
inline std::string toString(T t, std::ios_base & (*f)(std::ios_base&))
{
    std::ostringstream oss;
    oss << f << t;
    return oss.str();
}


inline std::string mpdec_class::toString(const std::string& format) const
{
	//char *s = NULL;
	//std::string out;

	//s  = mpd_format(mp, format.c_str(),GetContext());
	//out = std::string(s);
	//return out;
	char *s = NULL;
	std::string out;

	s  = mpd_to_sci(mp, 1);
	out = std::string(s);
	return out;

}


inline std::string mpdec_class::toString(int n, int b) const
{
//    (void)b;
	char *s = NULL;
	std::string out;

	s  = mpd_to_sci(mp, 1);
	out = std::string(s);
	return out;

}


//////////////////////////////////////////////////////////////////////////
// I/O
inline std::ostream& operator<<(std::ostream& os, const mpdec_class& v)
{
    return os<<v.toString(static_cast<int>(os.precision()));
}

inline std::istream& operator>>(std::istream &is, mpdec_class& v)
{
    // ToDo, use cout::hexfloat and other flags to setup base
    std::string tmp;
    is >> tmp;
    mpd_set_string(v.mp, tmp.c_str(), mpdec_class::GetContext());
    return is;
}

//////////////////////////////////////////////////////////////////////////
//     Bits - decimal digits relation
//        bits   = ceil(digits*log[2](10))
//        digits = floor(bits*log[10](2))

inline size_t digits2bits(int d)
{
    const double LOG2_10 = 3.3219280948873624;

    return (size_t) std::ceil( d * LOG2_10 );
}

inline int bits2digits(size_t b)
{
    const double LOG10_2 = 0.30102999566398119;

    return (int) std::floor( b * LOG10_2 );
}

//////////////////////////////////////////////////////////////////////////
// Set/Get number properties
//////////////////////////////////////////////////////////////////////////

/* Change DH: Radical redefinitions !!!! */

//////////////////////////////////////////////////////////////////////////

inline int sgn(const mpdec_class& v)
{
	return mpd_arith_sign(v.mp);

}

inline mpdec_class& mpdec_class::setSign(int sign)
{
    mpd_set_sign(mp,sign);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline size_t mpdec_class::getPrecision() const
{
    return mpd_getprec(GetContext());
}

inline mpdec_class& mpdec_class::setPrecision(mpd_ssize_t Precision)
{
		mpd_qsetprec(GetContext(), Precision);
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::setInf(int sign)
{
    mpd_setspecial(mp,sign, MPD_INF);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class& mpdec_class::setNan()
{
    mpd_setspecial(mp,MPD_POS, MPD_NAN);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline mpdec_class&    mpdec_class::setZero(int sign)
{
    mpd_zerocoeff(mp);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return *this;
}

inline size_t mpdec_class::get_prec() const
{
    return mpd_getprec(GetContext());
}

inline void mpdec_class::set_prec(mpd_ssize_t prec)
{
 		mpd_qsetprec(GetContext(), prec);

    mpdec_class_MSVC_DEBUGVIEW_CODE;
}

// Change DH
inline int mpdec_class::get_exp ()
{
    return 0;
}

inline int mpdec_class::set_exp (int e)
{
    return 0;
}

inline const mpdec_class frexp(const mpdec_class& v, int* exp)
{
    mpdec_class x(v);
    *exp = x.get_exp();
    x.set_exp(0);
    return x;
}

inline const mpdec_class ldexp(const mpdec_class& v, int exp)
{
    mpdec_class x(v);

    // rounding is not important since we just increasing the exponent
    //mpfi_mul_2si(x.mp,x.mp,exp);
    return x;
}



//Change DH Begin

inline const mpdec_class ldexp(const mpdec_class& v, const mpdec_class& e)
{
    mpdec_class x(v);
//    mp_exp_t exp = mpfr_get_si(x.mp, mpreal::get_default_rnd());

    // rounding is not important since we just increasing the exponent
//    mpfr_mul_2si(x.mp,x.mp,exp,mpreal::get_default_rnd());
    return x;
}

//Change DH End


//Change DH Begin

inline const mpdec_class scalbn(const mpdec_class& v, const mpdec_class& e)
{
    return ldexp(v,e);
}

inline const mpdec_class scalbln(const mpdec_class& v, const mpdec_class& e)
{
    return ldexp(v,e);
}

//Change DH End



inline mpdec_class machine_epsilon()
{
    /* the smallest eps such that 1 + eps != 1 */
    return machine_epsilon(mpdec_class("1E-300"));
}

inline mpdec_class machine_epsilon(const mpdec_class& x)
{
    /* the smallest eps such that x + eps != x */
    if( x < 0)
    {
        return nextabove(-x)+x;
    }else{
        return nextabove(x)-x;
    }
}


inline mpdec_class machine_epsilon(const size_t prec)
{
    /* the smallest eps such that x + eps != x */
     return machine_epsilon(mpdec_class("1E-300"));
}


// minval is 'safe' meaning 1 / minval does not overflow
inline mpdec_class minval(int Precision)
{
    /* min = 1/2 * 2^emin = 2^(emin - 1) */
		//return mpdec_class(1) << mpdec_class::get_emin()-1;

	/* min = 1/2 * 10^emin = 10^(emin - 1) */
	mpdec_class x;
	mpd_ssize_t emin =  mpdec_class::get_emin()-1;
	x = pow(mpdec_class(10), mpdec_class(emin));
	return x;
}

// maxval is 'safe' meaning 1 / maxval does not underflow
inline mpdec_class maxval(int Precision)
{
    /* max = (1 - eps) * 2^emax, eps is machine epsilon */
    //return (mpdec_class(1) - machine_epsilon()) << mpdec_class::get_emax();

	 /* max = (1 - eps) * 10^emax, eps is machine epsilon */
	mpdec_class x;
	mpd_ssize_t emax = mpdec_class::get_emax()-1;
	x = pow(mpdec_class(10), mpdec_class(emax));
	return x;
}

inline bool isEqualUlps(const mpdec_class& a, const mpdec_class& b, int maxUlps)
{
  return abs(a - b) <= machine_epsilon((max)(abs(a), abs(b))) * maxUlps;
}

inline bool isEqualFuzzy(const mpdec_class& a, const mpdec_class& b, const mpdec_class& eps)
{
    return abs(a - b) <= (min)(abs(a), abs(b)) * eps;
}

inline bool isEqualFuzzy(const mpdec_class& a, const mpdec_class& b)
{
    return isEqualFuzzy(a, b, machine_epsilon((min)(abs(a), abs(b))));
}


inline const mpdec_class modf(const mpdec_class& v, mpdec_class& n)
{
    mpdec_class frac(v);

    // rounding is not important since we are using the same number
    // mpfi_frac(frac.mp,frac.mp);
    // mpfi_trunc(n.mp,v.mp);
    return frac;
}

inline int mpdec_class::check_range (int t)
{
    return 0;
}

inline int mpdec_class::subnormalize (int t)
{
    int r = 0;
    mpdec_class_MSVC_DEBUGVIEW_CODE;
    return r;
}

inline mpd_ssize_t mpdec_class::get_emin (void)
{
    return mpd_getemin(GetContext());
}

inline int mpdec_class::set_emin (mpd_ssize_t emin)
{
    return mpd_qsetemin(GetContext(), emin);
}

inline mpd_ssize_t mpdec_class::get_emax (void)
{
    return mpd_getemax(GetContext());
}

inline int mpdec_class::set_emax (mpd_ssize_t emax)
{
    return mpd_qsetemax(GetContext(), emax);
}


inline mpd_ssize_t mpdec_class::get_emin_min (void)
{
    return 0;
}

inline mpd_ssize_t mpdec_class::get_emin_max (void)
{
    return 0;
}

inline mpd_ssize_t mpdec_class::get_emax_min (void)
{
    return 0;
}

inline mpd_ssize_t mpdec_class::get_emax_max (void)
{
    return 0;
}

//////////////////////////////////////////////////////////////////////////
// Mathematical Functions
//////////////////////////////////////////////////////////////////////////

#define mpdec_class_UNARY_MATH_FUNCTION_BODY(f)                    \
        mpdec_class y(0);          \
        mpd_sqrt(y.mp, x.mp, mpdec_class::GetContext());           \
        return y;

inline const mpdec_class sqr (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sqrt);    }
inline const mpdec_class sqrt (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sqrt);    }



inline const mpdec_class root(const mpdec_class& x, unsigned long int k)
{
    mpdec_class y(x);
    return y;
}

inline const mpdec_class dim(const mpdec_class& a, const mpdec_class& b)
{
    mpdec_class y(a);
    return y;
}


inline const mpdec_class fdim(const mpdec_class& a, const mpdec_class& b)
{
    mpdec_class y(a);
    return y;
}


inline int cmpabs(const mpdec_class& a,const mpdec_class& b)
{
    return 0;
}

inline int sin_cos(mpdec_class& s, mpdec_class& c, const mpdec_class& v, mp_rnd_t rnd_mode)
{
    return 0;
}



inline const mpdec_class cbrt  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(cbrt );    }
inline const mpdec_class fabs  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(abs  );    }


inline const mpdec_class abs   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(abs );    }
inline const mpdec_class ln   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(ln );    }
inline const mpdec_class log   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log );    }
inline const mpdec_class ilogb   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log );    }
inline const mpdec_class logb   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log );    }


inline const mpdec_class log2  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log2 );    }


inline const mpdec_class log10 (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log10);    }

inline const mpdec_class exp   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(exp  );    }


inline const mpdec_class exp2  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(exp2 );    }
inline const mpdec_class exp10 (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(exp10);    }
inline const mpdec_class cos   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(cos  );    }
inline const mpdec_class sin   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sin  );    }
inline const mpdec_class tan   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(tan  );    }
inline const mpdec_class sec   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sec  );    }
inline const mpdec_class csc   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(csc  );    }
inline const mpdec_class cot   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(cot  );    }
inline const mpdec_class acos  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(acos);     }
inline const mpdec_class asin  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(asin);     }
inline const mpdec_class atan  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(atan);     }

inline const mpdec_class acot  (const mpdec_class& v) {   return atan (1/v);                      }
inline const mpdec_class asec  (const mpdec_class& v) {   return acos (1/v);                      }
inline const mpdec_class acsc  (const mpdec_class& v) {   return asin (1/v);                      }
inline const mpdec_class acoth (const mpdec_class& v) {   return atanh(1/v);                      }
inline const mpdec_class asech (const mpdec_class& v) {   return acosh(1/v);                      }
inline const mpdec_class acsch (const mpdec_class& v) {   return asinh(1/v);                      }

inline const mpdec_class cosh  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(cosh );    }
inline const mpdec_class sinh  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sinh );    }
inline const mpdec_class tanh  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(tanh );    }
inline const mpdec_class sech  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(sech );    }
inline const mpdec_class csch  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(csch );    }
inline const mpdec_class coth  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(coth );    }
inline const mpdec_class acosh (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(acosh);    }
inline const mpdec_class asinh (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(asinh);    }
inline const mpdec_class atanh (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(atanh);    }

inline const mpdec_class log1p   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(log1p  );    }
inline const mpdec_class expm1   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(expm1  );    }

// Change DH
inline const mpdec_class eint    (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(eint   );    }
inline const mpdec_class gamma   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(gamma  );    }
inline const mpdec_class tgamma   (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(gamma  );    }

inline const mpdec_class lngamma (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(lngamma);    }
inline const mpdec_class zeta    (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(zeta   );    }
inline const mpdec_class erf     (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(erf    );    }
inline const mpdec_class erfc    (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(erfc   );    }
inline const mpdec_class besselj0(const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(j0     );    }
inline const mpdec_class besselj1(const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(j1     );    }
inline const mpdec_class bessely0(const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(y0     );    }
inline const mpdec_class bessely1(const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(y1     );    }
// End Change DH


inline const mpdec_class sign (const mpdec_class& v)
{
    uint32_t s = 0;
    mpdec_class x(s);
    return x;
}


inline const mpdec_class atan2 (const mpdec_class& y, const mpdec_class& x)
{
    mpdec_class a(x);
    return a;
}

inline const mpdec_class hypot (const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a(x);
    return a;
}


inline const mpdec_class copysign (const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a(x);
    return a;
}




// Change DH
inline const mpdec_class remainder (const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a(x);
    return a;
}

inline const mpdec_class remquo (long* q, const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a(x);
    return a;
}


inline const mpdec_class remquo (const mpdec_class& x, const mpdec_class& y, int* q)
{
    mpdec_class a(x);
    return a;
}



inline const mpdec_class fac_ui (uint32_t v)
{
    mpdec_class x(v);
    return x;
}


inline const mpdec_class lgamma (const mpdec_class& v, int *signp)
{
    mpdec_class x(v);
    return x;
}


inline const mpdec_class besseljn (long n, const mpdec_class& x)
{
    mpdec_class  y(x);
    return y;
}

inline const mpdec_class besselyn (long n, const mpdec_class& x)
{
    mpdec_class  y(x);
    return y;
}

inline const mpdec_class fma (const mpdec_class& v1, const mpdec_class& v2, const mpdec_class& v3)
{
    mpdec_class a(v1);
    return a;
}

inline const mpdec_class fms (const mpdec_class& v1, const mpdec_class& v2, const mpdec_class& v3)
{
    mpdec_class a(v1);
    return a;
}

inline const mpdec_class agm (const mpdec_class& v1, const mpdec_class& v2)
{
    mpdec_class a(v1);
    return a;
}


//////////////////////////////////////////////////////////////////////////
// mpfi 2.4.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(2,4,0))

inline int sinh_cosh(mpdec_class& s, mpdec_class& c, const mpdec_class& v)
{
    return 0;
}

inline const mpdec_class li2 (const mpdec_class& x)
{
    mpdec_class_UNARY_MATH_FUNCTION_BODY(li2);
}


inline const mpdec_class rem (const mpdec_class& x, const mpdec_class& y)
{
    //  R = rem(X,Y) if Y != 0, returns X - n * Y where n = trunc(X/Y).
    return fmod(x, y);
}

inline const mpdec_class mod (const mpdec_class& x, const mpdec_class& y)
{
//    m = mod(x,y) if y != 0, returns x - n*y where n = floor(x/y)
//
//    The following are true by convention:
//    - mod(x,0) is x
//    - mod(x,x) is 0
//    - mod(x,y) for x != y and y != 0 has the same sign as y.

    if(iszero(y)) return x;
    if(x == y) return 0;

    mpdec_class m = x - floor(x / y) * y;

    m.setSign(sgn(y)); // make sure result has the same sign as Y

    return m;
}

inline const mpdec_class fmod (const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a;
    return a;
}
// End Change DH


inline const mpdec_class rec_sqrt(const mpdec_class& v)
{
    mpdec_class x(v);
    mpd_invroot(x.mp,v.mp, mpdec_class::GetContext());
    return x;
}

/*
#endif //  mpfi 2.4.0 Specifics



//////////////////////////////////////////////////////////////////////////
// mpfi 3.0.0 Specifics
#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
inline const mpdec_class digamma (const mpdec_class& x, mp_rnd_t r) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(digamma);     }
inline const mpdec_class ai      (const mpdec_class& x, mp_rnd_t r) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(ai);          }
#endif // mpfi 3.0.0 Specifics

//////////////////////////////////////////////////////////////////////////


*/

// Constants
inline const mpdec_class const_log2 ()
{
    mpdec_class x("0.69314718055994530941723212145818");
    return x;
}

inline const mpdec_class const_pi ()
{
    mpdec_class x("3.1415926535897932384626433832795");
    return x;
}

inline const mpdec_class const_euler ()
{
    mpdec_class x("0.57721566490153286060651209008240243104215933593992");
    return x;
}

inline const mpdec_class const_catalan ()
{
    mpdec_class x("0.91596559417721901505460351493238411077");
    return x;
}

// Change DH
inline const mpdec_class const_log2_a (const mpdec_class& v)
{
    mpdec_class x("0.69314718055994530941723212145818");
    return x;
}

inline const mpdec_class const_pi_a (const mpdec_class& v)
{
    mpdec_class x("3.1415926535897932384626433832795");
    return x;
}

inline const mpdec_class const_euler_gamma_a (const mpdec_class& v)
{
    mpdec_class x("0.57721566490153286060651209008240243104215933593992");
    return x;
}

inline const mpdec_class const_catalan_a (const mpdec_class& v)
{
    mpdec_class x("0.91596559417721901505460351493238411077");
    return x;
}
// End Change DH



/* Change DH */
inline const mpdec_class const_infinity (int sign)
{
    mpdec_class x(0);
    return x;
}


//////////////////////////////////////////////////////////////////////////
// Integer Related Functions
inline const mpdec_class ceil(const mpdec_class& v)
{
    mpdec_class x(v);
    mpd_ceil(x.mp,v.mp, mpdec_class::GetContext());
    return x;
}

inline const mpdec_class floor(const mpdec_class& v)
{
    mpdec_class x(v);
    mpd_floor(x.mp,v.mp, mpdec_class::GetContext());
    return x;
}

inline const mpdec_class round(const mpdec_class& v)
{
    mpdec_class x(v);
    mpd_round_to_int(x.mp,v.mp, mpdec_class::GetContext());
    return x;
}



// Change DH Begin
inline const mpdec_class lround(const mpdec_class& v)
{
    return round(v);
}

inline const mpdec_class llround(const mpdec_class& v)
{
    return round(v);
}
// Change DH End



inline const mpdec_class trunc(const mpdec_class& v)
{
    mpdec_class x(v);
    mpd_trunc(x.mp,v.mp, mpdec_class::GetContext());
    return x;
}
// Change DH
inline const mpdec_class rint       (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint      );     }

// Change DH Begin
inline const mpdec_class lrint       (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint      );     }
inline const mpdec_class llrint       (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint      );     }
inline const mpdec_class nearbyint       (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint      );     }
// Change DH End


inline const mpdec_class rint_ceil  (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint_ceil );     }
inline const mpdec_class rint_floor (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint_floor);     }
inline const mpdec_class rint_round (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint_round);     }
inline const mpdec_class rint_trunc (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(rint_trunc);     }
inline const mpdec_class frac       (const mpdec_class& x) {   mpdec_class_UNARY_MATH_FUNCTION_BODY(frac      );     }

//////////////////////////////////////////////////////////////////////////
// Miscellaneous Functions
inline void         swap (mpdec_class& a, mpdec_class& b)            {       }
// End change DH

inline const mpdec_class (max)(const mpdec_class& x, const mpdec_class& y){    return (x>y?x:y);       }
inline const mpdec_class (min)(const mpdec_class& x, const mpdec_class& y){    return (x<y?x:y);       }



inline const mpdec_class fmax(const mpdec_class& x, const mpdec_class& y)
{
    return (x>y?x:y);
}

inline const mpdec_class fmin(const mpdec_class& x, const mpdec_class& y)
{
    return (x<y?x:y);
}

inline const mpdec_class nexttoward (const mpdec_class& x, const mpdec_class& y)
{
    mpdec_class a(x);
    mpd_next_toward(a.mp,x.mp,y.mp,mpdec_class::GetContext());
		return a;
}


inline const mpdec_class nextafter (const mpdec_class& x, const mpdec_class& y)
{
    return nexttoward(x, y);
}


inline const mpdec_class nextabove  (const mpdec_class& x)
{
    mpdec_class a(x);
    mpd_next_plus(a.mp,x.mp,mpdec_class::GetContext());
    return a;
}

inline const mpdec_class nextbelow  (const mpdec_class& x)
{
    mpdec_class a(x);
    mpd_next_minus(a.mp,x.mp,mpdec_class::GetContext());
    return a;
}

inline const mpdec_class urandomb (gmp_randstate_t& state)
{
    mpdec_class x(0);
    return x;
}

#if (MPFR_VERSION >= MPFR_VERSION_NUM(3,0,0))
// use gmp_randinit_default() to init state, gmp_randclear() to clear
inline const mpdec_class urandom (gmp_randstate_t& state)
{
    mpdec_class x;
    return x;
}
#endif



// Uniformly distributed random number generation
// a = random(seed); <- initialization & first random number generation
// a = random();     <- next random numbers generation
// seed != 0
inline const mpdec_class random(unsigned int seed)
{
//    if(seed != 0)    std::srand(seed);
//    return mpDec::mpdec_class(std::rand()/(double)RAND_MAX);

    if(seed != 0)    std::srand(seed);
    return mpDec::mpdec_class(std::rand()/(double)RAND_MAX);


}



//////////////////////////////////////////////////////////////////////////
// Set/Get global properties
inline void mpdec_class::set_default_prec(mpd_ssize_t prec)
{
    mpd_qsetprec(mpdec_class::GetContext(), prec);
}

inline void mpdec_class::set_default_rnd(int rnd_mode)
{
    mpd_qsetprec(mpdec_class::GetContext(), rnd_mode);
}


inline void set_precision(int prec)
{
		mpd_defaultcontext(mpdec_class::GetContext());
		if (!mpd_qsetprec(mpdec_class::GetContext(), prec))
		{mpd_addstatus_raise(mpdec_class::GetContext(), MPD_Invalid_context); return; }
}


inline void set_decimal32()
{
    mpd_ieee_context(mpdec_class::GetContext(), MPD_DECIMAL32);
}


inline void set_decimal64()
{
    mpd_ieee_context(mpdec_class::GetContext(), MPD_DECIMAL64);
}


inline void set_decimal128()
{
    mpd_ieee_context(mpdec_class::GetContext(), MPD_DECIMAL128);
}



inline bool mpdec_class::fits_in_bits(double x, int n)
{
    return true;
}

inline const mpdec_class pow(const mpdec_class& a, const mpdec_class& b)
{
    mpdec_class x(a);
    mpd_pow(x.mp,a.mp,b.mp,mpdec_class::GetContext());
    return x;
}

inline const mpdec_class pow(const mpdec_class& a, const mpz_t b)
{
    return a;
}



inline const mpdec_class pow(const mpdec_class& a, const uint64_t b)
{
    return pow(a,mpdec_class(b));
}

inline const mpdec_class pow(const mpdec_class& a, const uint32_t b)
{
    return pow(a,mpdec_class(b));
}

inline const mpdec_class pow(const mpdec_class& a, const int64_t b)
{
    return pow(a,mpdec_class(b));
}

inline const mpdec_class pow(const mpdec_class& a, const int32_t b)
{
    return pow(a,mpdec_class(b));
}


inline const mpdec_class pow(const mpdec_class& a, const long double b)
{
    return pow(a,mpdec_class(b));
}



inline const mpdec_class pow(const mpdec_class& a, const double b)
{
    return pow(a,mpdec_class(b));
}


//    mpdec_class(const int32_t u);
//    mpdec_class(const int64_t u);
//    mpdec_class(const uint32_t u);
//    mpdec_class(const uint64_t u);


inline const mpdec_class pow(const uint64_t a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}

inline const mpdec_class pow(const uint32_t a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}

inline const mpdec_class pow(const int64_t a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}

inline const mpdec_class pow(const int32_t a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}


inline const mpdec_class pow(const long double a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}



inline const mpdec_class pow(const double a, const mpdec_class& b)
{
    mpdec_class x(a);
    return pow(x, mpdec_class(b));
}


} // End of mpfi namespace







// Explicit specialization of std::swap for mpdec_class numbers
// Thus standard algorithms will use efficient version of swap (due to Koenig lookup)
// Non-throwing swap C++ idiom: http://en.wikibooks.org/wiki/More_C%2B%2B_Idioms/Non-throwing_swap
namespace std
{
	// only allowed to extend namespace std with specializations
//    template <>
//    inline void swap(mpfi::mpdec_class& x, mpfi::mpdec_class& y)
//    {
//        return mpfi_swap(x.mp, y.mp);
//    }

    template<>
    class numeric_limits<mpDec::mpdec_class>
    {
    public:
        static const bool is_specialized    = true;
        static const bool is_signed         = true;
        static const bool is_integer        = false;
        static const bool is_exact          = false;
        static const int  radix             = 10;

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
            int r = mpDec::mpdec_class::get_default_rnd();

            switch (r)
            {
                case MPD_ROUND_HALF_UP: return round_to_nearest;
                case MPD_ROUND_DOWN: return round_toward_zero;
                case MPD_ROUND_CEILING: return round_toward_infinity;
                case MPD_ROUND_FLOOR: return round_toward_neg_infinity;
                default: return round_indeterminate;
            }
        }

        inline static mpDec::mpdec_class (min)    () {  return  mpDec::minval();  }
        inline static mpDec::mpdec_class (max)    () {  return  mpDec::maxval();  }
        inline static mpDec::mpdec_class lowest   () {  return -mpDec::maxval();  }

        // Returns smallest eps such that 1 + eps != 1 (classic machine epsilon)
        inline static mpDec::mpdec_class epsilon() {  return  mpDec::machine_epsilon(); }

        // Returns smallest eps such that x + eps != x (relative machine epsilon)
        inline static mpDec::mpdec_class epsilon(const mpDec::mpdec_class& x) {  return mpDec::machine_epsilon(x);  }

        inline static mpDec::mpdec_class round_error()
        {
          /*  mp_rnd_t r = mpDec::mpdec_class::get_default_rnd();

            if(r == MPFR_RNDN) return mpDec::mpdec_class(0.5, precision);
            else               return mpDec::mpdec_class(1.0, precision);*/
						return mpDec::mpdec_class(0.5);
        }

 //       inline static const mpDec::mpdec_class infinity()         { return mpDec::const_infinity();     }
        inline static const mpDec::mpdec_class quiet_NaN()        { return mpDec::mpdec_class().setNan();    }
        inline static const mpDec::mpdec_class signaling_NaN()    { return mpDec::mpdec_class().setNan();    }
        inline static const mpDec::mpdec_class denorm_min()       { return (min)();                    }

        // Please note, exponent range is not fixed in mpDec
        static const int min_exponent = 10000000;
        static const int max_exponent = 10000000;
        mpdec_class_PERMISSIVE_EXPR static const int min_exponent10 = (int) 10000000;
        mpdec_class_PERMISSIVE_EXPR static const int max_exponent10 = (int) 10000000;

        // Should be constant according to standard, but 'digits' depends on precision in mpDec

        inline static size_t digits()                        {    return mpDec::mpdec_class::get_default_prec();    }
        inline static size_t digits(const mpDec::mpdec_class& x)   {    return x.getPrecision();                    }

        inline static size_t digits10()
        {
            return mpDec::mpdec_class::get_default_prec();
        }

        inline static size_t digits10(const mpDec::mpdec_class& x)
        {
            return x.getPrecision();
        }

        inline static size_t max_digits10()
        {
            return digits10();
        }
    };

}

#endif /* __mpdec_class_H__ */
