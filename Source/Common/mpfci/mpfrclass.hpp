/* Arbitrary precision arithmetics in C-XSC (MPFR-MPFI)
   ====================================================

Copyright (C) 2010-11 Wiss. Rechnen/Softwaretechnologie
                      Universitaet Wuppertal, Germany

**  This library is free software; you can redistribute it and/or
**  modify it under the terms of the GNU Library General Public
**  License as published by the Free Software Foundation; either
**  version 2 of the License, or (at your option) any later version.
**
**  This library is distributed in the hope that it will be useful,
**  but WITHOUT ANY WARRANTY; without even the implied warranty of
**  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
**  Library General Public License for more details.
**
**  You should have received a copy of the GNU Library General Public
**  License along with this library; if not, write to the Free
**  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

/*********************************************/
/*  Datei:  mpfrclass.hpp                    */
/*  Zweck:  C++-Wrapper-Klasse fuer          */
/*          die MPFR-Bibliothek              */
/*  Based on       mpfr-3.0.0                */
/*********************************************/


#ifndef _CXSC_MPFRCLASS_H_INCLUDED
#define _CXSC_MPFRCLASS_H_INCLUDED


#include <iostream>
#include <sstream>

//#include <real.hpp>   // Blomquist 04.05.2010
#include "mpfi_io.h"  // Blomquist 10.05.2010


#ifndef _TYPES_
#define _TYPES_

// Precision
typedef mpfr_prec_t PrecisionType;
// Rounding modes
typedef mpfr_rnd_t RoundingMode;

static const RoundingMode RoundNearest=mpfr_rnd_t(MPFR_RNDN);   // returns 0
static const RoundingMode RoundToZero=mpfr_rnd_t(MPFR_RNDZ);    // returns 1
static const RoundingMode RoundUp=mpfr_rnd_t(MPFR_RNDU);        // returns 2
static const RoundingMode RoundDown=mpfr_rnd_t(MPFR_RNDD);      // returns 3
static const RoundingMode RoundFromZero=mpfr_rnd_t(MPFR_RNDA);  // returns 4
#endif


namespace MPFR{

class MpfrClass{

protected:
    mpfr_t mpfr_rep;        // mpfr_rep: Variable vom Typ mpfr_t

    // Current precision
    static PrecisionType CurrPrecision;
    // Current rounding mode
    static RoundingMode CurrRndMode;
    static int base;

public:
    /*Konstruktoren und Destruktoren*/

    MpfrClass ();

    MpfrClass (const MpfrClass&,
              RoundingMode  = CurrRndMode,
              PrecisionType = CurrPrecision);

    MpfrClass (const mpfr_t&,
              RoundingMode  = CurrRndMode,
              PrecisionType = CurrPrecision);

//explicit    MpfrClass (const cxsc::real&,
//              RoundingMode  = CurrRndMode,
//              PrecisionType = CurrPrecision);

explicit    MpfrClass (const double&,
              RoundingMode  = CurrRndMode,
              PrecisionType = CurrPrecision);

explicit    MpfrClass (int,
              RoundingMode  = CurrRndMode,
              PrecisionType = CurrPrecision);

    MpfrClass (const std::string& s,
              RoundingMode  = CurrRndMode,
              PrecisionType = CurrPrecision);

    ~MpfrClass ();


    friend std::string to_string (const MpfrClass&, RoundingMode = CurrRndMode, PrecisionType = 0);
    friend std::string to_string (const mpfr_t&,    RoundingMode = CurrRndMode, PrecisionType = 0);

    /*Precision and Rounding Mode Handling*/
    void SetPrecision (PrecisionType);

    void RoundPrecision(PrecisionType, RoundingMode);

    static const PrecisionType GetCurrPrecision ();
    PrecisionType GetPrecision () const;
    static void SetCurrPrecision (PrecisionType);
    static void SetBase (int);
    static const int GetBase ();
    static void SetCurrRndMode (RoundingMode);
    static const RoundingMode GetCurrRndMode ();
    mpfr_t& GetValue();
    void SetValue(const mpfr_t&);

    friend const mpfr_t& getvalue(const MpfrClass&);

    // Conversion functions, exact converting to MPFR format:
    friend MpfrClass double2Mpfr (const double&);
//    friend MpfrClass real2Mpfr   (const cxsc::real&);
    friend MpfrClass int2Mpfr    (const int&);
    friend MpfrClass mpfr_t2Mpfr (const mpfr_t&);

    /* Konstanten */
    static MpfrClass Pi(RoundingMode rnd = CurrRndMode,
                        PrecisionType prec = CurrPrecision);
    static MpfrClass Ln2(RoundingMode rnd = CurrRndMode,
                        PrecisionType prec = CurrPrecision);
    static MpfrClass Euler(RoundingMode rnd = CurrRndMode,
                        PrecisionType prec = CurrPrecision);
    static MpfrClass Catalan(RoundingMode rnd = CurrRndMode,
                        PrecisionType prec = CurrPrecision);

    /* Setzen von NaN , +Inf, -Inf*/

    friend void set_nan  (MpfrClass&);       // Blomquist 28.04.2010
    friend void set_inf  (MpfrClass&, int);  // Blomquist 28.04.2010
    friend void set_zero (MpfrClass&, int);  // Blomquist 18.07.2010

    /* Abfragen */

    friend bool isZero(const MpfrClass&);
    friend bool isInf(const MpfrClass&);
    friend bool isNan(const MpfrClass&);
    friend bool isNumber(const MpfrClass&);
    friend bool isNeg(const MpfrClass&);
    friend bool isPos(const MpfrClass&);     // Blomquist 25.04.2010
    friend bool isInteger(const MpfrClass&); // Blomquist 21.07.2010
    friend bool isEven(const MpfrClass&);    // Blomquist 21.07.2010
    friend bool isOdd (const MpfrClass&);    // Blomquist 23.07.2010

    /*Vergleichs Funktionen*/

    friend int compare_equal        (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
    friend int compare_less         (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
    friend int compare_lessequal    (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
    friend int compare_greater      (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
    friend int compare_greaterequal (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010

    /* Arithmetische Operatoren*/
    // Addition
    MpfrClass operator + () const;

    friend MpfrClass operator + (const MpfrClass&, const MpfrClass&);
    friend MpfrClass operator + (const MpfrClass&, const double&);
//    friend MpfrClass operator + (const MpfrClass&, const cxsc::real&);
    friend MpfrClass operator + (const MpfrClass&, const int);
    friend MpfrClass operator + (const MpfrClass&, const mpfr_t&);
    friend MpfrClass operator + (const double&,           const MpfrClass&);
//    friend MpfrClass operator + (const cxsc::real&,       const MpfrClass&);
    friend MpfrClass operator + (const int,               const MpfrClass&);
    friend MpfrClass operator + (const mpfr_t&,           const MpfrClass&);

    // Subtraction
    MpfrClass operator - () const;

    friend MpfrClass operator - (const MpfrClass&, const MpfrClass&);
    friend MpfrClass operator - (const MpfrClass&, const double&);
//    friend MpfrClass operator - (const MpfrClass&, const cxsc::real&);
    friend MpfrClass operator - (const MpfrClass&, const int);
    friend MpfrClass operator - (const MpfrClass&, const mpfr_t&);
    friend MpfrClass operator - (const double&,           const MpfrClass&);
//    friend MpfrClass operator - (const cxsc::real&,       const MpfrClass&);
    friend MpfrClass operator - (const int,               const MpfrClass&);
    friend MpfrClass operator - (const mpfr_t&,           const MpfrClass&);

    // Multiplication
    friend MpfrClass operator * (const MpfrClass&, const MpfrClass&);
    friend MpfrClass operator * (const MpfrClass&, const double&);
//    friend MpfrClass operator * (const MpfrClass&, const cxsc::real&);
    friend MpfrClass operator * (const MpfrClass&, const int);
    friend MpfrClass operator * (const MpfrClass&, const mpfr_t&);
    friend MpfrClass operator * (const double&, const MpfrClass&);
//    friend MpfrClass operator * (const cxsc::real&, const MpfrClass&);
    friend MpfrClass operator * (const int, const MpfrClass&);
    friend MpfrClass operator * (const mpfr_t&, const MpfrClass&);

    // Division
    friend MpfrClass operator / (const MpfrClass&, const MpfrClass&);
    friend MpfrClass operator / (const MpfrClass&, const double&);
//    friend MpfrClass operator / (const MpfrClass&, const cxsc::real&);
    friend MpfrClass operator / (const MpfrClass&, const int);
    friend MpfrClass operator / (const MpfrClass&, const mpfr_t&);
    friend MpfrClass operator / (const double& , const MpfrClass&);
//    friend MpfrClass operator / (const cxsc::real&, const MpfrClass&);
    friend MpfrClass operator / (const int, const MpfrClass&);
    friend MpfrClass operator / (const mpfr_t&, const MpfrClass&);

    MpfrClass& operator = (const MpfrClass&);
    MpfrClass& operator = (const mpfr_t&);
    MpfrClass& operator = (const double&);
    MpfrClass& operator = (const int&);
//    MpfrClass& operator = (const cxsc::real&);


    /*Mathematische Funktionen*/
    friend void random (MpfrClass&, gmp_randstate_t);


    friend MpfrClass minfloat ( PrecisionType );
    friend MpfrClass MaxFloat ( PrecisionType );
    friend MpfrClass pred (const MpfrClass&);                                // Blomquist, 23.06.2010
    friend MpfrClass succ (const MpfrClass&);                                // Blomquist, 23.06.2010

    friend int sign(const MpfrClass&);                                       // Blomquist, 05.07.2010

    friend MpfrClass reci (const MpfrClass& , RoundingMode);                 // Blomquist, 02.05.2010
    friend void times2pown(MpfrClass&, const long int, RoundingMode);              // Blomquist, 02.05.2010

    friend MpfrClass abs (const MpfrClass&, RoundingMode, PrecisionType);
    friend MpfrClass agm (const MpfrClass&, const MpfrClass& , RoundingMode);
    friend MpfrClass sqr (const MpfrClass&, RoundingMode);
    friend MpfrClass sqrt (const MpfrClass&, RoundingMode);
    friend MpfrClass sqrt_n (unsigned long int, RoundingMode);   // sqrt(n);
    friend MpfrClass cbrt (const MpfrClass&, RoundingMode);     // sqrt3(x), -Infinity < x < +Infinity
    friend MpfrClass sqrt (const MpfrClass&, unsigned long int , RoundingMode);
    friend MpfrClass sqrt_r (const MpfrClass&, RoundingMode);   // 1/sqrt(x),   Blomquist 01.05.2010
    friend MpfrClass sqrtp1m1 (const MpfrClass&, RoundingMode); // sqrt(1+x)-1, Blomquist 15.06.2010
    friend MpfrClass sqrtx2m1 (const MpfrClass&, RoundingMode); // sqrt(x^2-1), Blomquist 25.06.2010
    friend MpfrClass sqrt1mx2 (const MpfrClass&, RoundingMode); // sqrt(1-x^2), Blomquist 26.06.2010
    friend MpfrClass sqrt1px2 (const MpfrClass&, RoundingMode); // sqrt(1+x^2), Blomquist 30.06.2010

    friend MpfrClass exp (const MpfrClass& ,   RoundingMode);    // exp(x)
    friend MpfrClass expm1 (const MpfrClass& , RoundingMode);    // exp(x) - 1;
    friend MpfrClass expmx2 (const MpfrClass& , RoundingMode);   // exp(-x^2);
    friend MpfrClass expmx2m1 (const MpfrClass& , RoundingMode); // exp(-x^2) - 1;
    friend MpfrClass expx2 (const MpfrClass& , RoundingMode);    // exp(+x^2);
    friend MpfrClass expx2m1 (const MpfrClass& , RoundingMode);  // exp(+x^2) - 1;
    friend MpfrClass exp2 (const MpfrClass& ,  RoundingMode);
    friend MpfrClass exp10 (const MpfrClass& , RoundingMode);             // Blomquist 25.04.2010
    friend MpfrClass ln (const MpfrClass& ,    RoundingMode);
    friend MpfrClass log2 (const MpfrClass& ,  RoundingMode);
    friend MpfrClass log10 (const MpfrClass& , RoundingMode);
    friend MpfrClass lnp1 (const MpfrClass& ,  RoundingMode);

    friend MpfrClass sin (const MpfrClass& , RoundingMode);
    friend MpfrClass cos (const MpfrClass& , RoundingMode);
    friend void sin_cos (MpfrClass& res_sin, MpfrClass& res_cos,
                          const MpfrClass& , RoundingMode);
    friend MpfrClass tan (const MpfrClass& , RoundingMode);
    friend MpfrClass cot (const MpfrClass& , RoundingMode);               // Blomquist 29.04.2010

    friend MpfrClass acos (const MpfrClass& , RoundingMode);
    friend MpfrClass asin (const MpfrClass& , RoundingMode);
    friend MpfrClass atan (const MpfrClass& , RoundingMode);
    friend MpfrClass atan2(const MpfrClass& ,
                           const MpfrClass& , RoundingMode);              // Blomquist 10.06.2010
    friend MpfrClass acot (const MpfrClass& , RoundingMode);              // Blomquist 29.04.2010

    friend MpfrClass cosh (const MpfrClass& , RoundingMode);
    friend MpfrClass sinh (const MpfrClass& , RoundingMode);
    friend MpfrClass tanh (const MpfrClass& , RoundingMode);
    friend MpfrClass coth (const MpfrClass& , RoundingMode);              // Blomquist 29.04.2010

    friend MpfrClass atanh   (const MpfrClass& , RoundingMode);
    friend MpfrClass acoth   (const MpfrClass& , RoundingMode);           // Blomquist 29.04.2010
    friend MpfrClass acosh   (const MpfrClass& , RoundingMode);
    friend MpfrClass acoshp1 (const MpfrClass& , RoundingMode);
    friend MpfrClass asinh   (const MpfrClass& , RoundingMode);

    friend MpfrClass csc   (const MpfrClass& , RoundingMode);             //  1/sin
    friend MpfrClass sec   (const MpfrClass& , RoundingMode);             //  1/cos
    friend MpfrClass sech  (const MpfrClass& , RoundingMode);             //  1/cosh
    friend MpfrClass csch  (const MpfrClass& , RoundingMode);             //  1/sinh

    friend MpfrClass power (const MpfrClass& ,const int , RoundingMode);
    friend MpfrClass power (const MpfrClass& , const long int, RoundingMode rnd);
    friend MpfrClass pow   (const MpfrClass& ,const double& , RoundingMode);
//    friend MpfrClass pow   (const MpfrClass& ,const cxsc::real& , RoundingMode);
    friend MpfrClass pow   (const MpfrClass& ,const MpfrClass& , RoundingMode);

    friend MpfrClass ln_cos (const MpfrClass&, RoundingMode);
    friend MpfrClass ln_sin (const MpfrClass&, RoundingMode);

    friend MpfrClass x2my2  (const MpfrClass&, const MpfrClass& , RoundingMode);
    friend MpfrClass x2py2  (const MpfrClass&, const MpfrClass& , RoundingMode);

    friend MpfrClass gamma (const MpfrClass& , RoundingMode);
    friend MpfrClass gamma_D (const MpfrClass&, RoundingMode);
    friend MpfrClass gamma_reci (const MpfrClass& , RoundingMode);
    friend MpfrClass gamma_reci_D (const MpfrClass& , RoundingMode);
    friend MpfrClass lngamma (const MpfrClass& , RoundingMode);           // Blomquist 25.04.2010
    friend MpfrClass lgamma (const MpfrClass& , int&, RoundingMode);      // Blomquist 25.07.2010
    friend MpfrClass digamma (const MpfrClass& , RoundingMode);           // Blomquist 19.07.2010
    friend MpfrClass erf  (const MpfrClass& , RoundingMode);
    friend MpfrClass erfc (const MpfrClass& , RoundingMode);              // Blomquist 25.04.2010
    friend MpfrClass factorial (const unsigned long int, RoundingMode);
    friend MpfrClass sqrtx2y2 (const MpfrClass& , const MpfrClass& , RoundingMode);
    friend MpfrClass ln_sqrtx2y2 (const MpfrClass& , const MpfrClass& , RoundingMode);
    friend void ln_sqrt_S1 (MpfrClass&, MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode);
    friend void ln_sqrt_S1 (MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode);
    friend void ln_sqrt_S2 (MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode);
    friend MpfrClass ln_sqrtxp1_2y2 (const MpfrClass& , const MpfrClass& , RoundingMode);
    friend MpfrClass zeta (const MpfrClass& , RoundingMode);
    friend MpfrClass zeta (unsigned long int& , RoundingMode);            // Blomquist 01.05.2010
    friend MpfrClass Ei (const MpfrClass& , RoundingMode);                // Blomquist 01.05.2010
    friend MpfrClass Li2 (const MpfrClass& , RoundingMode);               // Blomquist 29.04.2010
    friend MpfrClass J0 (const MpfrClass& , RoundingMode);                // Blomquist 29.04.2010
    friend MpfrClass J1 (const MpfrClass& , RoundingMode);                // Blomquist 29.04.2010
    friend MpfrClass Jn (long int, const MpfrClass& , RoundingMode);          // Blomquist 29.04.2010
    friend MpfrClass Y0 (const MpfrClass& , RoundingMode);                // Blomquist 29.04.2010
    friend MpfrClass Y1 (const MpfrClass& , RoundingMode);                // Blomquist 29.04.2010
    friend MpfrClass Yn (long int, const MpfrClass& , RoundingMode);          // Blomquist 29.04.2010
    friend MpfrClass plus_ab (const MpfrClass&, const MpfrClass&, const MpfrClass&,  RoundingMode);

    // The four rounding modes as in IEEE-754 arithmetic and the fractional part
    friend MpfrClass Round (const MpfrClass& );
    friend MpfrClass Floor (const MpfrClass& );
    friend MpfrClass Trunc (const MpfrClass& );
    friend MpfrClass Ceil  (const MpfrClass& );
    friend MpfrClass Frac  (const MpfrClass& );

    friend long int to_int (const MpfrClass& , RoundingMode);
    friend double to_double (const MpfrClass& , RoundingMode);
//    friend cxsc::real to_real (const MpfrClass& , RoundingMode);

    friend long int expo (const MpfrClass& );

    friend MpfrClass comp (const MpfrClass&, const long int);

    friend void scal_prod_k(MpfrClass&, long int&,
                           const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                           RoundingMode);
    friend void Scal_prod_k(MpfrClass&, long int&,
                           const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                           RoundingMode);
    friend void scal_prod(MpfrClass&,
                         const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                         RoundingMode);
    friend void prod_H1(MpfrClass&, long int&,
                                    const MpfrClass&, const MpfrClass&, RoundingMode);
    friend void Prod_H1(MpfrClass&, long int&,
                                    const MpfrClass&, const MpfrClass&, RoundingMode);
    friend void sum_k_H1(MpfrClass&, long int&,
                         const MpfrClass&, long int&,
                         const MpfrClass&, long int&, RoundingMode);

    friend MpfrClass Compl_Re (const MpfrClass&, const MpfrClass&,
                               const MpfrClass&, const MpfrClass&, RoundingMode);
    friend MpfrClass Compl_Im (const MpfrClass&, const MpfrClass&,
                               const MpfrClass&, const MpfrClass&, RoundingMode);

    friend MpfrClass string2Mpfr (const std::string&, RoundingMode = CurrRndMode, PrecisionType = CurrPrecision);

    friend void set_Mpfr (MpfrClass&, const MpfrClass&, RoundingMode  = CurrRndMode,
                                                        PrecisionType = CurrPrecision);

    /* Ein-Ausgabe-Operatoren */
    friend std::istream& operator >> (std::istream&, MpfrClass&);
    friend std::ostream& operator << (std::ostream&, const MpfrClass&);
    friend std::ostream& operator << (std::ostream&, const mpfr_t&);

    friend void swap(MpfrClass&, MpfrClass&);
    friend void swap(MpfrClass&, mpfr_t&);

    friend MpfrClass x_div_x2py2(const MpfrClass&, const MpfrClass&, RoundingMode = CurrRndMode);

}; // Class end

    const mpfr_t& getvalue(const MpfrClass&);

    /* Vergleichs Operatoren */
    bool operator == (const MpfrClass& , const MpfrClass& );
    bool operator == (const MpfrClass& , const double& );
    bool operator == (const MpfrClass& , const int );
//    bool operator == (const MpfrClass& , const cxsc::real& );
    bool operator == (const double& , const MpfrClass& );
    bool operator == (const int , const MpfrClass& );
//    bool operator == (const cxsc::real& , const MpfrClass& );

    bool operator != (const MpfrClass& , const MpfrClass& );
    bool operator != (const MpfrClass& , const double& );
    bool operator != (const MpfrClass& , const int );
//    bool operator != (const MpfrClass& , const cxsc::real& );
    bool operator != (const double& , const MpfrClass& );
    bool operator != (const int , const MpfrClass& );
//    bool operator != (const cxsc::real& , const MpfrClass& );

    bool operator <  (const MpfrClass& , const MpfrClass& );
    bool operator <  (const MpfrClass& , const double& );
//    bool operator <  (const MpfrClass& , const cxsc::real& );
    bool operator <  (const MpfrClass& , const int );
    bool operator <  (const double& , const MpfrClass& );
//    bool operator <  (const cxsc::real& , const MpfrClass& );
    bool operator <  (const int , const MpfrClass& );

    bool operator <= (const MpfrClass& , const MpfrClass& );
    bool operator <= (const MpfrClass& , const double& );
//    bool operator <= (const MpfrClass& , const cxsc::real& );
    bool operator <= (const MpfrClass& , const int );
    bool operator <= (const double& , const MpfrClass& );
//    bool operator <= (const cxsc::real& , const MpfrClass& );
    bool operator <= (const int , const MpfrClass& );

    bool operator >  (const MpfrClass& , const MpfrClass& );
    bool operator >  (const MpfrClass& , const double& );
//    bool operator >  (const MpfrClass& , const cxsc::real& );
    bool operator >  (const MpfrClass& , const int );
    bool operator >  (const double& , const MpfrClass& );
//    bool operator >  (const cxsc::real& , const MpfrClass& );
    bool operator >  (const int , const MpfrClass& );

    bool operator >= (const MpfrClass& , const MpfrClass& );
    bool operator >= (const MpfrClass& , const double& );
//    bool operator >= (const MpfrClass& , const cxsc::real& );
    bool operator >= (const MpfrClass& , const int );
    bool operator >= (const double& , const MpfrClass& );
//    bool operator >= (const cxsc::real& , const MpfrClass& );
    bool operator >= (const int , const MpfrClass& );

    MpfrClass min (const MpfrClass&, const MpfrClass&);
    MpfrClass max (const MpfrClass&, const MpfrClass&);

    void set_Mpfr (MpfrClass&, const MpfrClass&, RoundingMode, PrecisionType);

    /* String  --->  MpfrClass */
    MpfrClass string2Mpfr (const std::string&, RoundingMode, PrecisionType); // Blomquist 09.10.2010
    /* MpfrClass  --->  String */
    std::string to_string (const MpfrClass&, RoundingMode, PrecisionType);
    std::string to_string (const mpfr_t&,    RoundingMode, PrecisionType);

/*------------------------------------------------------*/
/*----------start C-XSC Functions-----------------------*/
/*------------------------------------------------------*/

   // Exact converting to MPFR format:
//   MpfrClass real2Mpfr   (const cxsc::real&);
   MpfrClass double2Mpfr (const double&);
   MpfrClass int2Mpfr    (const int&);
   MpfrClass mpfr_t2Mpfr (const mpfr_t&);

/*------------------------------------------------------*/
/*----------end C-XSC Functions-------------------------*/
/*------------------------------------------------------*/

// Weitere Deklaration von friend-Funktionen, die in der Klasse MpfrClass bereits deklariert sind:

   void set_nan  (MpfrClass&);
   void set_inf  (MpfrClass&, int);
   void set_zero (MpfrClass&, int);  // Blomquist 18.07.2010

   bool isZero(const MpfrClass&);
   bool isInf(const MpfrClass&);
   bool isNan(const MpfrClass&);
   bool isNumber(const MpfrClass&);
   bool isNeg(const MpfrClass&);
   bool isPos(const MpfrClass&);
   bool isInteger(const MpfrClass&);
   bool isEven(const MpfrClass&);    // Prueft, ob Argument ein gerader Integer-Wert ist
   bool isOdd (const MpfrClass&);    // Prueft, ob Argument ein ungerader Integer-Wert ist

   int compare_equal        (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
   int compare_less         (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
   int compare_lessequal    (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
   int compare_greater      (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010
   int compare_greaterequal (const MpfrClass&, const MpfrClass&);   // Blomquist 24.05.2010

   MpfrClass operator + (const MpfrClass&, const MpfrClass&);
   MpfrClass operator + (const MpfrClass&, const double&);
//   MpfrClass operator + (const MpfrClass&, const cxsc::real&);
   MpfrClass operator + (const MpfrClass&, const int);
   MpfrClass operator + (const MpfrClass&, const mpfr_t&);
   MpfrClass operator + (const double&,           const MpfrClass& );
//   MpfrClass operator + (const cxsc::real&,       const MpfrClass& );
   MpfrClass operator + (const int,               const MpfrClass& );
   MpfrClass operator + (const mpfr_t&,           const MpfrClass& );

   MpfrClass& operator += (MpfrClass&, const MpfrClass& );
   MpfrClass& operator += (MpfrClass&, const double&);
//   MpfrClass& operator += (MpfrClass&, const cxsc::real&);
   MpfrClass& operator += (MpfrClass&, const int);
   MpfrClass& operator += (MpfrClass&, const mpfr_t&);

   MpfrClass operator - (const MpfrClass&, const MpfrClass&);
   MpfrClass operator - (const MpfrClass&, const double&);
//   MpfrClass operator - (const MpfrClass&, const cxsc::real&);
   MpfrClass operator - (const MpfrClass&, const int);
   MpfrClass operator - (const MpfrClass&, const mpfr_t&);
   MpfrClass operator - (const double&,           const MpfrClass&);
//   MpfrClass operator - (const cxsc::real&,       const MpfrClass&);
   MpfrClass operator - (const int,               const MpfrClass&);
   MpfrClass operator - (const mpfr_t&,           const MpfrClass&);

   MpfrClass& operator -= (MpfrClass&, const MpfrClass&);
   MpfrClass& operator -= (MpfrClass&, const double&);
//   MpfrClass& operator -= (MpfrClass&, const cxsc::real&);
   MpfrClass& operator -= (MpfrClass&, const int);
   MpfrClass& operator -= (MpfrClass&, const mpfr_t&);

   MpfrClass operator * (const MpfrClass&, const MpfrClass&);
   MpfrClass operator * (const MpfrClass&, const double&);
//   MpfrClass operator * (const MpfrClass&, const cxsc::real&);
   MpfrClass operator * (const MpfrClass&, const int);
   MpfrClass operator * (const MpfrClass&, const mpfr_t&);
   MpfrClass operator * (const double&, const MpfrClass&);
//   MpfrClass operator * (const cxsc::real&, const MpfrClass&);
   MpfrClass operator * (const int, const MpfrClass&);
   MpfrClass operator * (const mpfr_t&, const MpfrClass&);

   MpfrClass& operator *= (MpfrClass&, const MpfrClass& );
   MpfrClass& operator *= (MpfrClass&, const double&);
//   MpfrClass& operator *= (MpfrClass&, const cxsc::real&);
   MpfrClass& operator *= (MpfrClass&, const int);
   MpfrClass& operator *= (MpfrClass&, const mpfr_t&);

   MpfrClass operator / (const MpfrClass&, const double&);
//   MpfrClass operator / (const MpfrClass&, const cxsc::real&);
   MpfrClass operator / (const MpfrClass&, const int);
   MpfrClass operator / (const MpfrClass&, const mpfr_t&);
   MpfrClass operator / (const double&, const MpfrClass&);
//   MpfrClass operator / (const cxsc::real&, const MpfrClass&);
   MpfrClass operator / (const int, const MpfrClass&);
   MpfrClass operator / (const mpfr_t&, const MpfrClass&);

   MpfrClass& operator /= (MpfrClass&, const MpfrClass& );
   MpfrClass& operator /= (MpfrClass&, const double&);
//   MpfrClass& operator /= (MpfrClass&, const cxsc::real&);
   MpfrClass& operator /= (MpfrClass&, const int);
   MpfrClass& operator /= (MpfrClass&, const mpfr_t&);

   void random (MpfrClass&, gmp_randstate_t);

   MpfrClass minfloat (PrecisionType prec = MpfrClass::CurrPrecision);    // Blomquist, 23.06.2010
   MpfrClass MaxFloat (PrecisionType prec = MpfrClass::CurrPrecision);    // Blomquist, 23.06.2010
   MpfrClass pred (const MpfrClass&);                                     // Blomquist, 23.06.2010
   MpfrClass succ (const MpfrClass&);                                     // Blomquist, 23.06.2010

   int sign(const MpfrClass&);                                            // Blomquist, 05.07.2010

   MpfrClass reci (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);                 // Blomquist, 02.05.2010

   void times2pown (MpfrClass&, const long int, RoundingMode  = MpfrClass::CurrRndMode);             // Blomquist, 02.05.2010
   MpfrClass abs (const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode,
                                    PrecisionType = MPFR::MpfrClass::CurrPrecision);
   MpfrClass agm (const MpfrClass& , const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass sqr (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass sqrt(const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass sqrt_n (unsigned long int, RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass cbrt (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);     // sqrt3(x), -Infinity < x < +Infinity
   MpfrClass sqrt (const MpfrClass& , unsigned long int , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass sqrt_r (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);   // 1/sqrt(x),   Blomquist 01.05.2010
   MpfrClass sqrtp1m1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // sqrt(1+x)-1, Blomquist 15.06.2010
   MpfrClass sqrtx2m1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // sqrt(x^2-1), Blomquist 25.06.2010
   MpfrClass sqrt1mx2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // sqrt(1-x^2), Blomquist 26.06.2010
   MpfrClass sqrt1px2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // sqrt(1+x^2), Blomquist 30.06.2010

   MpfrClass exp (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass expm1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass expmx2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass expmx2m1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass expx2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass expx2m1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass exp2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass exp10 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // Blomquist 25.04.2010
   MpfrClass ln (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass log2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass log10 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass lnp1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass sin (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass cos (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   void sin_cos (MpfrClass& res_sin, MpfrClass& res_cos,
                          const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass tan (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass cot (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass acos (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass asin (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass atan (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass atan2(const MpfrClass& ,
		   const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode); // Blomquist 10.06.2010
   MpfrClass acot (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass cosh (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass sinh (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass tanh (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass coth (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass atanh   (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass acoth   (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass acosh   (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass acoshp1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass asinh   (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass csc   (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);  //  1/sin
   MpfrClass sec   (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);  //  1/cos
   MpfrClass sech  (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);  //  1/cosh
   MpfrClass csch  (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);  //  1/sinh

   MpfrClass power (const MpfrClass& ,const int , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass power (const MpfrClass&, const long int, RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass pow (const MpfrClass& ,const double& ,RoundingMode  = MpfrClass::CurrRndMode);
//   MpfrClass pow (const MpfrClass& ,const cxsc::real& ,RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass pow (const MpfrClass& ,const MpfrClass& ,RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass ln_cos(const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass ln_sin(const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);

   MpfrClass x2my2 (const MpfrClass&, const MpfrClass& ,RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass x2py2 (const MpfrClass&, const MpfrClass& ,RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass gamma   (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass lngamma (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass lgamma  (const MpfrClass& , int&, RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass digamma (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass gamma_D (const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass gamma_reci (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass gamma_reci_D (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass erf     (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass erfc    (const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass factorial (const unsigned long int, RoundingMode = MpfrClass::CurrRndMode );
   MpfrClass sqrtx2y2 (const MpfrClass& , const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass ln_sqrtx2y2 (const MpfrClass& , const MpfrClass& ,    RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass ln_sqrtxp1_2y2 (const MpfrClass& , const MpfrClass& , RoundingMode = MpfrClass::CurrRndMode);
   void ln_sqrt_S1 (MpfrClass&, MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);
   void ln_sqrt_S1 (MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);
   void ln_sqrt_S2 (MpfrClass&, const MpfrClass&, const MpfrClass&, RoundingMode = MpfrClass::CurrRndMode);
   MpfrClass zeta (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass zeta (unsigned long int& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Ei (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Li2 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass J0 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass J1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Jn (long int, const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Y0 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Y1 (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Yn (long int, const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass plus_ab (const MpfrClass&, const MpfrClass&, const MpfrClass&,  RoundingMode = MpfrClass::CurrRndMode);

   MpfrClass Round (const MpfrClass& );
   MpfrClass Floor (const MpfrClass& );
   MpfrClass Trunc (const MpfrClass& );
   MpfrClass Ceil (const MpfrClass& );
   MpfrClass Frac (const MpfrClass& );

   long int to_int (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
   double to_double (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);
//   cxsc::real to_real (const MpfrClass& , RoundingMode  = MpfrClass::CurrRndMode);

   long int expo (const MpfrClass& );
   MpfrClass mant (const MpfrClass&);

   void scal_prod_k(MpfrClass&, long int&,
                   const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                   RoundingMode  = MpfrClass::CurrRndMode);
   void Scal_prod_k(MpfrClass&, long int&,
                   const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                   RoundingMode  = MpfrClass::CurrRndMode);
   void scal_prod(MpfrClass&,
                   const MpfrClass&, const MpfrClass&, const MpfrClass&, const MpfrClass&,
                   RoundingMode  = MpfrClass::CurrRndMode);
   void prod_H1(MpfrClass&, long int&,
                const MpfrClass&, const MpfrClass&, RoundingMode  = MpfrClass::CurrRndMode);
   void Prod_H1(MpfrClass&, long int&,
                const MpfrClass&, const MpfrClass&, RoundingMode  = MpfrClass::CurrRndMode);
   void sum_k_H1(MpfrClass&, long int&,
                 const MpfrClass&, long int&,
                 const MpfrClass&, long int&, RoundingMode  = MpfrClass::CurrRndMode);

   MpfrClass Compl_Re (const MpfrClass&, const MpfrClass&,
                       const MpfrClass&, const MpfrClass&, RoundingMode  = MpfrClass::CurrRndMode);
   MpfrClass Compl_Im (const MpfrClass&, const MpfrClass&,
                       const MpfrClass&, const MpfrClass&, RoundingMode  = MpfrClass::CurrRndMode);

   std::istream& operator >> (std::istream&, MpfrClass&);
   std::ostream& operator << (std::ostream&, const MpfrClass&);
   std::ostream& operator << (std::ostream&, const mpfr_t&);

    /*Potenz Operatoren*/
    inline MpfrClass operator^(const MpfrClass& r, const int e)
    {
        return pow(r,e);
    }

    inline MpfrClass operator^(const MpfrClass& r, const unsigned long int e)
    {
        return pow(r,e);
    }

    inline MpfrClass operator^(const MpfrClass& r, const long int e)
    {
        return pow(r,e);
    }

    inline MpfrClass operator^(const MpfrClass& r, const double e)
    {
        return pow(r,e);
    }

    inline MpfrClass operator^(const MpfrClass& r, const MpfrClass& e)
    {
        return pow(r,e);
    }

    void initialization (gmp_randstate_t);

    void swap(MpfrClass&, MpfrClass&);
    void swap(MpfrClass&, mpfr_t&);

    MpfrClass x_div_x2py2(const MpfrClass&, const MpfrClass&, RoundingMode);

}; // namespace MPFR

#endif
