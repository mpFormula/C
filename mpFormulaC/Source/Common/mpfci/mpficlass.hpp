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
/*  Datei:  mpficlass.hpp                    */
/*  Zweck:  C++-Wrapper-Klasse fuer          */
/*          die MPFI-Bibliothek              */
/*  Based on    mpfr-3.0.0, mpfi-1.5         */
/*********************************************/


#ifndef _CXSC_MPFICLASS_H_INCLUDED
#define _CXSC_MPFICLASS_H_INCLUDED

// #include <iostream>
// #include <sstream>
// #include <string>

// #include <cmath>
// #include <cstdlib>
// #include <cstdio>

// #include <gmp.h>
// #include <gmpxx.h>

// #include <mpfr.h>
// #include <mpf2mpfr.h>

// #include <mpfi.h>
// #include <mpfi_io.h>

//#include <interval.hpp>
#include "mpfrclass.hpp"
#include <stdlib.h>

namespace MPFI{

class MpfiClass
{
  protected:
    mpfi_t mpfi_rep;      // mpfi_t-variable

    static int base;

  public:

/*------------------------------------------------------*/
/*----------begin constructor and destructors-----------*/
/*------------------------------------------------------*/

    MpfiClass ();

    MpfiClass (const mpfi_t&,          PrecisionType = MPFR::MpfrClass::GetCurrPrecision() );

//    MpfiClass (const cxsc::interval&,  PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

//    MpfiClass (const cxsc::real&,      PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass (const double&,          PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass (int,                    PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass(const std::string&,      PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass (const mpfr_t&,          PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass (const MpfiClass&,       PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    explicit MpfiClass (const MPFR::MpfrClass&, PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfiClass (const MPFR::MpfrClass&, const MPFR::MpfrClass&,
                                       PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    ~MpfiClass ();

/*------------------------------------------------------*/
/*----------end constructor and destructors-------------*/
/*------------------------------------------------------*/

    // mpfi_rep-Wert auslesen
    mpfi_t& GetValue();
    void SetValue(const mpfi_t&);

    friend const mpfi_t& getvalue(const MpfiClass&);

    friend void swap(MpfiClass&, MpfiClass&);
    friend void swap(MpfiClass&, mpfi_t&);


    // Zuweisungsoperatoren
    MpfiClass& operator = (const MpfiClass&);
    MpfiClass& operator = (const MPFR::MpfrClass&);
    MpfiClass& operator = (const mpfi_t&);
    MpfiClass& operator = (const mpfr_t&);
    MpfiClass& operator = (const int&);
    MpfiClass& operator = (const double&);
    MpfiClass& operator = (const std::string&);
//    MpfiClass& operator = (const cxsc::interval&);                        // Blomquist 30.05.2010
//    MpfiClass& operator = (const cxsc::real&);                            // Blomquist 30.05.2010

/*------------------------------------------------------*/
/*----------------begin Precision Modes-----------------*/
/*------------------------------------------------------*/

    void SetPrecision (PrecisionType);
    void RoundPrecision(PrecisionType);
    static const PrecisionType GetCurrPrecision ();
    PrecisionType GetPrecision () const;
    static void SetCurrPrecision (PrecisionType);
    static void SetBase (int);
    static const int GetBase ();

/*------------------------------------------------------*/
/*----------------end Precision Modes-------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start comparison Functions -----------------*/
/*------------------------------------------------------*/

    friend bool isPos(const MpfiClass&);
    friend bool isStrictlyPos(const MpfiClass&);
    friend bool isNonNeg(const MpfiClass&);
    friend bool isNeg(const MpfiClass&);
    friend bool isStrictlyNeg(const MpfiClass&);
    friend bool isNonPos(const MpfiClass&);
    friend bool isZero(const MpfiClass&);
    friend bool hasZero(const MpfiClass&);
    friend bool isNan(const MpfiClass&);
    friend bool isInf(const MpfiClass&);
    friend bool isBounded(const MpfiClass&);
    friend bool isPoint(const MpfiClass&);

/*------------------------------------------------------*/
/*----------end comparison Functions -------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*-----start Constatnts (Pi, Euler, log2, Catalan)------*/
/*------------------------------------------------------*/

    static MpfiClass Pi      (PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision());  // Blomquist 12.05.2010
    static MpfiClass Euler   (PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision());  // Blomquist 12.05.2010
    static MpfiClass Ln2     (PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision());  // Blomquist 12.05.2010
    static MpfiClass Catalan (PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision());  // Blomquist 12.05.2010

/*------------------------------------------------------*/
/*----------end Constatnts (Pi, Euler, log2)------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start + Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    friend MpfiClass operator + (const MpfiClass&, const MpfiClass&);
    friend MpfiClass operator + (const MpfiClass&, const double&);
//    friend MpfiClass operator + (const MpfiClass&, const cxsc::real&);
    friend MpfiClass operator + (const MpfiClass&, const int);
    friend MpfiClass operator + (const MpfiClass&, const mpfr_t&);
    friend MpfiClass operator + (const MpfiClass&, const MPFR::MpfrClass&);
    friend MpfiClass operator + (const MpfiClass&, const mpfi_t&);
    friend MpfiClass operator + (const double&, const MpfiClass&);
//    friend MpfiClass operator + (const cxsc::real&, const MpfiClass&);
    friend MpfiClass operator + (const int, const MpfiClass&);
    friend MpfiClass operator + (const mpfr_t&, const MpfiClass&);
    friend MpfiClass operator + (const MPFR::MpfrClass&, const MpfiClass&);
    friend MpfiClass operator + (const mpfi_t&, const MpfiClass&);

/*------------------------------------------------------*/
/*----------end + Arithmetic Functions------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start - Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    friend MpfiClass operator - (const MpfiClass&, const MpfiClass&);
    friend MpfiClass operator - (const MpfiClass&, const double&);
//    friend MpfiClass operator - (const MpfiClass&, const cxsc::real&);
    friend MpfiClass operator - (const MpfiClass&, const int);
    friend MpfiClass operator - (const MpfiClass&, const mpfr_t&);
    friend MpfiClass operator - (const MpfiClass&, const MPFR::MpfrClass&);
    friend MpfiClass operator - (const MpfiClass&, const mpfi_t&);
    friend MpfiClass operator - (const double&, const MpfiClass&);
//    friend MpfiClass operator - (const cxsc::real&, const MpfiClass&);
    friend MpfiClass operator - (const int, const MpfiClass&);
    friend MpfiClass operator - (const mpfr_t&, const MpfiClass&);
    friend MpfiClass operator - (const MPFR::MpfrClass&, const MpfiClass&);
    friend MpfiClass operator - (const mpfi_t&, const MpfiClass&);

    friend MpfiClass operator - (const MpfiClass&);
    friend MpfiClass operator + (const MpfiClass&);

/*------------------------------------------------------*/
/*----------end - Arithmetic Functions------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start * Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    friend MpfiClass operator * (const MpfiClass&, const MpfiClass&);
    friend MpfiClass operator * (const MpfiClass&, const double&);
//    friend MpfiClass operator * (const MpfiClass&, const cxsc::real&);
    friend MpfiClass operator * (const MpfiClass&, const int);
    friend MpfiClass operator * (const MpfiClass&, const mpfr_t&);
    friend MpfiClass operator * (const MpfiClass&, const MPFR::MpfrClass&);
    friend MpfiClass operator * (const MpfiClass&, const mpfi_t&);
    friend MpfiClass operator * (const double&, const MpfiClass&);
//    friend MpfiClass operator * (const cxsc::real&, const MpfiClass&);
    friend MpfiClass operator * (const int, const MpfiClass&);
    friend MpfiClass operator * (const mpfr_t&, const MpfiClass&);
    friend MpfiClass operator * (const MPFR::MpfrClass&, const MpfiClass&);
    friend MpfiClass operator * (const mpfi_t&, const MpfiClass&);

/*------------------------------------------------------*/
/*----------end * Arithmetic Functions------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start / Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    friend MpfiClass operator / (const MpfiClass&, const MpfiClass&);
    friend MpfiClass operator / (const MpfiClass&, const double&);
//    friend MpfiClass operator / (const MpfiClass&, const cxsc::real&);
    friend MpfiClass operator / (const MpfiClass&, const int);
    friend MpfiClass operator / (const MpfiClass&, const mpfr_t&);
    friend MpfiClass operator / (const MpfiClass&, const MPFR::MpfrClass&);
    friend MpfiClass operator / (const MpfiClass&, const mpfi_t&);
    friend MpfiClass operator / (const double&, const MpfiClass&);
//    friend MpfiClass operator / (const cxsc::real&, const MpfiClass&);
    friend MpfiClass operator / (const int, const MpfiClass&);
    friend MpfiClass operator / (const mpfr_t&, const MpfiClass&);
    friend MpfiClass operator / (const MPFR::MpfrClass&, const MpfiClass&);
    friend MpfiClass operator / (const mpfi_t&, const MpfiClass&);

/*------------------------------------------------------*/
/*----------end / Arithmetic Functions------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start extended Arithmetic Functions---------*/
/*------------------------------------------------------*/

    friend MpfiClass sqr(const MpfiClass&);
    friend MpfiClass reci(const MpfiClass&);
    friend MpfiClass sqrt(const MpfiClass&);
    friend MpfiClass sqrt_N(unsigned long int);                           // Blomquist 14.06.2010
    friend MpfiClass sqrt(const MpfiClass&, unsigned long int);           // Blomquist 19.05.2010
    friend MpfiClass cbrt(const MpfiClass&);
    friend MpfiClass sqrtx2y2(const MpfiClass&, const MpfiClass&);        // Blomquist 19.05.2010
    friend MpfiClass ln_sqrtx2y2(const MpfiClass&, const MpfiClass&);     // Blomquist 29.07.2010
    friend MpfiClass x_div_x2py2(const MpfiClass&, const MpfiClass&);     // Blomquist 10.10.2011
    friend MpfiClass sqrtp1m1(const MpfiClass&);                          // Blomquist 21.06.2010
    friend MpfiClass sqrtx2m1(const MpfiClass&);                          // Blomquist 25.06.2010
    friend MpfiClass sqrt1mx2(const MpfiClass&);                          // Blomquist 26.06.2010
    friend MpfiClass sqrt1px2(const MpfiClass&);                          // Blomquist 30.06.2010
    friend MpfiClass abs(const MpfiClass&, PrecisionType);
    friend MpfiClass x2my2(const MpfiClass&, const MpfiClass&);           // Blomquist 22.08.2010
    friend MpfiClass x2py2(const MpfiClass&, const MpfiClass&);           // Blomquist 22.08.2010
    friend MpfiClass agm  (const MpfiClass&, const MpfiClass&);

    friend MpfiClass power(const MpfiClass&, int);
    friend MpfiClass power(const MpfiClass&, long int n);
    friend MpfiClass pow(const MpfiClass&, const MpfiClass&);             // Blomquist 07.06.2010

    friend void times2pown (MpfiClass&, const long int);  // Blomquist 17.05.2010

/*------------------------------------------------------*/
/*----------end extended Arithmetic Functions-----------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start Special Functions --------------------*/
/*------------------------------------------------------*/

    friend MpfiClass ln(const MpfiClass&);
    friend MpfiClass exp(const MpfiClass&);
    friend MpfiClass exp2(const MpfiClass&);
    friend MpfiClass exp10(const MpfiClass&); // Blomquist 18.05.2010

    friend MpfiClass cos(const MpfiClass&);
    friend MpfiClass sin(const MpfiClass&);
    friend MpfiClass tan(const MpfiClass&);
    friend MpfiClass cot(const MpfiClass&);   // Blomquist 17.05.2010

    friend MpfiClass acos(const MpfiClass&);
    friend MpfiClass asin(const MpfiClass&);
    friend MpfiClass atan(const MpfiClass&);
    friend MpfiClass atan2(const MpfiClass&,
                           const MpfiClass&); // Blomquist 20.09.2010
    friend MpfiClass ATAN2(const MpfiClass&,
                           const MpfiClass&); // Blomquist 20.09.2010
    friend MpfiClass acot(const MpfiClass&);  // Blomquist 18.05.2010

    friend MpfiClass cosh(const MpfiClass&);
    friend MpfiClass sinh(const MpfiClass&);
    friend MpfiClass tanh(const MpfiClass&);
    friend MpfiClass coth(const MpfiClass&);  // Blomquist 20.09.2010

    friend MpfiClass acosh  (const MpfiClass&);
    friend MpfiClass acoshp1(const MpfiClass&);
    friend MpfiClass asinh  (const MpfiClass&);
    friend MpfiClass atanh  (const MpfiClass&);
    friend MpfiClass acoth  (const MpfiClass&); // Blomquist 18.05.2010

    friend MpfiClass csc (const MpfiClass&);  // 1/sin
    friend MpfiClass sec (const MpfiClass&);  // 1/cos
    friend MpfiClass csch(const MpfiClass&);  // 1/sinh
    friend MpfiClass sech(const MpfiClass&);  // 1/cosh

    friend MpfiClass lnp1(const MpfiClass&);
    friend MpfiClass expm1(const MpfiClass&);
    friend MpfiClass expmx2(const MpfiClass&);   // exp(-x^2)
    friend MpfiClass expmx2m1(const MpfiClass&); // exp(-x^2) - 1;
    friend MpfiClass expx2(const MpfiClass&);    // exp(+x^2)
    friend MpfiClass expx2m1(const MpfiClass&);  // exp(+x^2) - 1;

    friend MpfiClass log2(const MpfiClass&);
    friend MpfiClass log10(const MpfiClass&);

    friend MpfiClass ln_cos(const MpfiClass&);
    friend MpfiClass ln_sin(const MpfiClass&);

    friend MpfiClass erf (const MpfiClass&);  // Blomquist 14.05.2010
    friend MpfiClass erfc(const MpfiClass&);  // Blomquist 14.05.2010

    friend MpfiClass digamma (const MpfiClass&);  // Blomquist 20.07.2010
    friend MpfiClass gamma_D (const MpfiClass&);  // Blomquist 21.07.2010

    friend MpfiClass Ei(const MpfiClass&);        // Blomquist 19.05.2010
    friend MpfiClass ifactorial (unsigned long int );  // Blomquist 19.05.2010
    friend MpfiClass izeta      (unsigned long int );  // Blomquist 14.06.2010

/*------------------------------------------------------*/
/*----------end Special Functions ----------------------*/
/*------------------------------------------------------*/

//    friend MpfiClass real2Mpfi(const cxsc::real&);                 // Blomquist 28.09.2010
    friend MpfiClass double2Mpfi(const double&);                   // Blomquist 28.09.2010
//    friend MpfiClass interval2Mpfi(const cxsc::interval&);         // Blomquist 03.10.2010
    friend MpfiClass int2Mpfi(const int);                          // Blomquist 28.09.2010
    friend MpfiClass MpfrClass2Mpfi(const MPFR::MpfrClass&);       // Blomquist 28.09.2010
    friend MpfiClass mpfr_t2Mpfi(const mpfr_t&);                   // Blomquist 28.09.2010
    friend MpfiClass mpfi_t2Mpfi(const mpfi_t&);                   // Blomquist 28.09.2010

//    friend cxsc::interval to_interval(const MpfiClass&);           // Blomquist 03.10.2010

/*------------------------------------------------------*/
/*----------start Interval Functions--------------------*/
/*------------------------------------------------------*/

    friend void diam( const MpfiClass&, mpfr_t&);
    friend void RelDiam( const MpfiClass&, mpfr_t&);
    friend void AbsMax( const MpfiClass&, mpfr_t&);
    friend void AbsMin( const MpfiClass&, mpfr_t&);
    friend void mid( const MpfiClass&, mpfr_t&);
    friend void random( const MpfiClass&, mpfr_t&);

    friend MPFR::MpfrClass diam(const MpfiClass&);
    friend MPFR::MpfrClass RelDiam(const MpfiClass&);
    friend MPFR::MpfrClass AbsMax(const MpfiClass&);
    friend MPFR::MpfrClass AbsMin(const MpfiClass&);
    friend MPFR::MpfrClass mid(const MpfiClass&);
    friend MPFR::MpfrClass random(const MpfiClass&);

    friend MpfiClass Blow(const MpfiClass&, const MPFR::MpfrClass&);      // Blomquist 03.07.2010

    friend MPFR::MpfrClass Inf(const MpfiClass&, PrecisionType);          // Blomquist 27.11.2010
    friend MPFR::MpfrClass Sup(const MpfiClass&, PrecisionType);          // Blomquist 27.11.2010

/*------------------------------------------------------*/
/*----------end Interval Functions----------------------*/
/*------------------------------------------------------*/



/*------------------------------------------------------*/
/*----------start Operating on Endpoint Functions ------*/
/*------------------------------------------------------*/

    void GetLeft (mpfr_t&);
    void GetRight(mpfr_t&);

    int swap_endpoints();

    // hull operator
    friend MpfiClass operator | ( const MpfiClass&, const MpfiClass& );
    friend MpfiClass operator | ( const double&, const MpfiClass& );
    friend MpfiClass operator | ( const MpfiClass&, const double& );
//    friend MpfiClass operator | ( const cxsc::real&, const MpfiClass& );
//    friend MpfiClass operator | ( const MpfiClass&, const cxsc::real& );
//    friend MpfiClass operator | ( const cxsc::interval&, const MpfiClass& );
//    friend MpfiClass operator | ( const MpfiClass&, const cxsc::interval& );
    friend MpfiClass operator | ( int , const MpfiClass& );
    friend MpfiClass operator | ( const MpfiClass&, int );
    friend MpfiClass operator | ( const MpfiClass&, const mpfr_t& );
    friend MpfiClass operator | ( const mpfr_t&, const MpfiClass& );
    friend MpfiClass operator | ( const MpfiClass&, const mpfi_t& );
    friend MpfiClass operator | ( const mpfi_t&, const MpfiClass& );
    friend MpfiClass operator | ( const MpfiClass&, const MPFR::MpfrClass& );
    friend MpfiClass operator | ( const MPFR::MpfrClass&, const MpfiClass& );

    friend MpfiClass & operator |= (MpfiClass&, const MpfiClass&);
    friend MpfiClass & operator |= (MpfiClass&, const double&);
//    friend MpfiClass & operator |= (MpfiClass&, const cxsc::real&);
//    friend MpfiClass & operator |= (MpfiClass&, const cxsc::interval&);
    friend MpfiClass & operator |= (MpfiClass&, int);
    friend MpfiClass & operator |= (MpfiClass&, const mpfr_t&);
    friend MpfiClass & operator |= (MpfiClass&, const mpfi_t&);
    friend MpfiClass & operator |= (MpfiClass&, const MPFR::MpfrClass&);

    // Intersection operator
    friend MpfiClass operator & ( const MpfiClass&, const MpfiClass& );
    friend MpfiClass operator & ( const MpfiClass&, const double& );
    friend MpfiClass operator & ( const double&, const MpfiClass& );
//    friend MpfiClass operator & ( const MpfiClass&, const cxsc::real& );
//    friend MpfiClass operator & ( const cxsc::real&, const MpfiClass& );
//    friend MpfiClass operator & ( const MpfiClass&, const cxsc::interval& );
//    friend MpfiClass operator & ( const cxsc::interval&, const MpfiClass& );
    friend MpfiClass operator & ( const MpfiClass&, int );
    friend MpfiClass operator & ( int, const MpfiClass& );
    friend MpfiClass operator & ( const MpfiClass&, const MPFR::MpfrClass& );
    friend MpfiClass operator & ( const MPFR::MpfrClass&, const MpfiClass& );
    friend MpfiClass operator & ( const MpfiClass&, const mpfr_t& );
    friend MpfiClass operator & ( const mpfr_t&, const MpfiClass& );
    friend MpfiClass operator & ( const MpfiClass&, const mpfi_t& );
    friend MpfiClass operator & ( const mpfi_t&, const MpfiClass& );

    friend MpfiClass & operator &= ( MpfiClass&, const MpfiClass& );
    friend MpfiClass & operator &= ( MpfiClass&, const double& );
//    friend MpfiClass & operator &= ( MpfiClass&, const cxsc::real& );
//    friend MpfiClass & operator &= ( MpfiClass&, const cxsc::interval& );
    friend MpfiClass & operator &= ( MpfiClass&, int );
    friend MpfiClass & operator &= ( MpfiClass&, const MPFR::MpfrClass& );
    friend MpfiClass & operator &= ( MpfiClass&, const mpfr_t& );
    friend MpfiClass & operator &= ( MpfiClass&, const mpfi_t& );

    void SetInterval(const double&, const double&);
//    void SetInterval(const cxsc::real&, const cxsc::real&);
    void SetInterval(const int&, const int&);
    void SetInterval(const mpfr_t&, const mpfr_t&);
    void SetInterval(const MPFR::MpfrClass&, const MPFR::MpfrClass&);

/*------------------------------------------------------*/
/*----------end Operating on Endpoint Functions---------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start Set Functions ------------------------*/
/*------------------------------------------------------*/

    bool isEmpty();

/*------------------------------------------------------*/
/*----------end Set Functions---------------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start Compare Functions --------------------*/
/*------------------------------------------------------*/

    friend bool compare_equal     (const MpfiClass&, const MpfiClass&);  // Blomquist 25.05.2010
    friend bool compare_less      (const MpfiClass&, const MpfiClass&);  // Blomquist 26.05.2010
    friend bool compare_lessequal (const MpfiClass&, const MpfiClass&);  // Blomquist 26.05.2010

/*------------------------------------------------------*/
/*----------end Compare Functions-----------------------*/
/*------------------------------------------------------*/

    friend int common_decimals(const MpfiClass&);

    // Ausgabe
    friend std::ostream& operator << (std::ostream&, const MpfiClass&);
    friend std::istream& operator>>(std::istream&, MpfiClass&);

    friend void print_binary(const MpfiClass&);
    friend void random(MpfiClass&, gmp_randstate_t);

    friend void set_Mpfi (MpfiClass&, const MpfiClass&, PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    friend void Interval_Scaling(MpfiClass&, long int&);
    friend void P_Interval_Scaling(MpfiClass&, long int&);

    friend int in (const double&, const MpfiClass&);
//    friend int in (const cxsc::real&, const MpfiClass&);
    friend int in (const MPFR::MpfrClass&, const MpfiClass&);
    friend int in (const mpfr_t&, const MpfiClass&);
    friend int in (const int&, const MpfiClass&);
    friend int in (const MpfiClass&, const MpfiClass&);
    friend int in (const mpfi_t&, const MpfiClass&);
//    friend int in (const cxsc::interval&, const MpfiClass&);

};  // Class end

/*------------------------------------------------------*/
/*----------start Comparison operators------------------*/
/*------------------------------------------------------*/

MpfiClass x_div_x2py2(const MpfiClass&, const MpfiClass&);

int in (const double&, const MpfiClass&);
//int in (const cxsc::real&, const MpfiClass&);
int in (const MPFR::MpfrClass&,  const MpfiClass&);
int in (const mpfr_t&, const MpfiClass&);
int in (const int&, const MpfiClass&);
int in (const MpfiClass&, const MpfiClass&);
int in (const mpfi_t&, const MpfiClass&);
//int in (const cxsc::interval&, const MpfiClass&);

const mpfi_t& getvalue(const MpfiClass&);

MpfiClass operator + (const MpfiClass&);
MpfiClass operator - (const MpfiClass&);

bool operator == (const MpfiClass&, const MpfiClass&);
bool operator == (const MpfiClass&, const double&);
bool operator == (const MpfiClass&, const int);
//bool operator == (const MpfiClass&, const cxsc::real&);
bool operator == (const double&, const MpfiClass&);
bool operator == (const int, const MpfiClass&);
//bool operator == (const cxsc::real& , const MpfiClass&);
bool operator == (const MpfiClass&, const mpfr_t&);
bool operator == (const MpfiClass&, const mpfi_t&);
bool operator == (const mpfr_t&, const MpfiClass&);
bool operator == (const mpfi_t&, const MpfiClass&);
bool operator == (const MpfiClass&, const MPFR::MpfrClass&);
bool operator == (const MPFR::MpfrClass&, const MpfiClass&);
//bool operator == (const cxsc::interval&, const MpfiClass&);
//bool operator == (const MpfiClass&, const cxsc::interval&);

bool operator != (const MpfiClass&, const MpfiClass&);
bool operator != (const MpfiClass&, const double&);
bool operator != (const MpfiClass&, const int);
//bool operator != (const MpfiClass&, const cxsc::real&);
bool operator != (const double&, const MpfiClass&);
bool operator != (const int, const MpfiClass&);
//bool operator != (const cxsc::real&, const MpfiClass&);
bool operator != (const MpfiClass&, const mpfr_t&);
bool operator != (const MpfiClass&, const mpfi_t&);
bool operator != (const mpfr_t&, const MpfiClass&);
bool operator != (const mpfi_t&, const MpfiClass&);
//bool operator != (const MpfiClass&, const cxsc::interval&);
//bool operator != (const cxsc::interval&, const MpfiClass&);
bool operator != (const MpfiClass&, const MPFR::MpfrClass&);
bool operator != (const MPFR::MpfrClass&, const MpfiClass&);

bool operator <  (const MpfiClass&, const MpfiClass&);
bool operator <  (const double&, const MpfiClass&);
bool operator <  (const int, const MpfiClass&);
//bool operator <  (const cxsc::real&, const MpfiClass&);
bool operator <  (const MpfiClass&, const mpfi_t&);
bool operator <  (const mpfr_t&, const MpfiClass&);
bool operator <  (const mpfi_t&, const MpfiClass&);
//bool operator <  (const MpfiClass&, const cxsc::interval&);
//bool operator <  (const cxsc::interval&, const MpfiClass&);
bool operator <  (const MPFR::MpfrClass&, const MpfiClass&);


bool operator <= (const MpfiClass&, const MpfiClass&);
bool operator <= (const MpfiClass&, const double&);
//bool operator <= (const MpfiClass&, const cxsc::real&);
bool operator <= (const MpfiClass&, const int);
bool operator <= (const double&, const MpfiClass&);
bool operator <= (const int, const MpfiClass&);
bool operator <= (const MpfiClass&, const mpfr_t&);
bool operator <= (const MpfiClass&, const mpfi_t&);
bool operator <= (const mpfr_t&, const MpfiClass&);
bool operator <= (const mpfi_t&, const MpfiClass&);
bool operator <= (const MpfiClass&, const MPFR::MpfrClass&);
bool operator <= (const MPFR::MpfrClass&, const MpfiClass&);
//bool operator <= (const cxsc::interval&, const MpfiClass&);
//bool operator <= (const cxsc::real&, const MpfiClass&);
//bool operator <= (const MpfiClass&, const cxsc::interval&);


bool operator >  (const MpfiClass&, const MpfiClass&);
bool operator >  (const MpfiClass&, const double&);
bool operator >  (const MpfiClass&, const int);
//bool operator >  (const MpfiClass&, const cxsc::real&);
bool operator >  (const MpfiClass&, const mpfr_t&);
bool operator >  (const MpfiClass&, const mpfi_t&);
bool operator >  (const mpfi_t&, const MpfiClass&);
bool operator >  (const MpfiClass&, const MPFR::MpfrClass&);
//bool operator >  (const MpfiClass&, const cxsc::interval&);
//bool operator >  (const cxsc::interval&, const MpfiClass&);


bool operator >= (const MpfiClass&, const MpfiClass&);
bool operator >= (const MpfiClass&, const double&);
bool operator >= (const MpfiClass&, const int);
//bool operator >= (const MpfiClass&, const cxsc::real&);
bool operator >= (const double&, const MpfiClass&);
bool operator >= (const int, const MpfiClass&);
bool operator >= (const MpfiClass&, const mpfr_t&);
bool operator >= (const MpfiClass&, const mpfi_t&);
bool operator >= (const mpfr_t&, const MpfiClass&);
bool operator >= (const mpfi_t&, const MpfiClass&);
bool operator >= (const MpfiClass&, const MPFR::MpfrClass&);
bool operator >= (const MPFR::MpfrClass&, const MpfiClass&);
//bool operator >= (const MpfiClass&, const cxsc::interval&);
//bool operator >= (const cxsc::interval&, const MpfiClass&);
//bool operator >= (const cxsc::real&, const MpfiClass&);

/*------------------------------------------------------*/
/*----------end Comparison operators--------------------*/
/*------------------------------------------------------*/

// Ausgabe Operator fuer mpfi_t Variablen
std::ostream& operator << (std::ostream& os, mpfi_t& v);


/*------------------------------------------------------*/
/*----------start C-XSC Functions-----------------------*/
/*------------------------------------------------------*/

//cxsc::interval to_interval(const MpfiClass&);
std::string to_string (const MpfiClass&, PrecisionType = 0);

MpfiClass string2Mpfi (const std::string&, const PrecisionType = MpfiClass::GetCurrPrecision());

int HexToDez(const char&);
std::string HexToBin(const char&);

std::string tobinaer(std::string, std::string);

/*------------------------------------------------------*/
/*----------end C-XSC Functions-------------------------*/
/*------------------------------------------------------*/

   void swap(MpfiClass&, MpfiClass&);
   void swap(MpfiClass&, mpfi_t&);

   bool isPos(const MpfiClass&);
   bool isStrictlyPos(const MpfiClass&);
   bool isNonNeg(const MpfiClass&);
   bool isNeg(const MpfiClass&);
   bool isStrictlyNeg(const MpfiClass&);
   bool isNonPos(const MpfiClass&);
   bool isZero(const MpfiClass&);
   bool hasZero(const MpfiClass&);
   bool isNan(const MpfiClass&);
   bool isInf(const MpfiClass&);
   bool isBounded(const MpfiClass&);
   bool isPoint(const MpfiClass&);
   bool Disjoint(const MpfiClass&, const MpfiClass&);

//   MpfiClass real2Mpfi(const cxsc::real&);           // Blomquist 28.09.2010
   MpfiClass double2Mpfi(const double&);             // Blomquist 28.09.2010
//   MpfiClass interval2Mpfi(const cxsc::interval&);   // Blomquist 03.10.2010
   MpfiClass int2Mpfi(const int);                    // Blomquist 28.09.2010
   MpfiClass MpfrClass2Mpfi(const MPFR::MpfrClass&); // Blomquist 28.09.2010
   MpfiClass mpfr_t2Mpfi(const mpfr_t&);             // Blomquist 28.09.2010
   MpfiClass mpfi_t2Mpfi(const mpfi_t&);             // Blomquist 28.09.2010

   MpfiClass operator + (const MpfiClass&, const MpfiClass&);
   MpfiClass operator + (const MpfiClass&, const double&);
//   MpfiClass operator + (const MpfiClass&, const cxsc::real&);
//   MpfiClass operator + (const MpfiClass&, const cxsc::interval&);
   MpfiClass operator + (const MpfiClass&, const int);
   MpfiClass operator + (const MpfiClass&, const mpfr_t&);
   MpfiClass operator + (const MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass operator + (const MpfiClass&, const mpfi_t&);
   MpfiClass operator + (const double&, const MpfiClass&);
//   MpfiClass operator + (const cxsc::real&, const MpfiClass&);
//   MpfiClass operator + (const cxsc::interval&, const MpfiClass&);
   MpfiClass operator + (const int, const MpfiClass&);
   MpfiClass operator + (const mpfr_t&, const MpfiClass&);
   MpfiClass operator + (const MPFR::MpfrClass&, const MpfiClass&);
   MpfiClass operator + (const mpfi_t&, const MpfiClass&);

   MpfiClass& operator += (MpfiClass&, const MpfiClass&);
   MpfiClass& operator += (MpfiClass&, const double&);
//   MpfiClass& operator += (MpfiClass&, const cxsc::real&);
//   MpfiClass& operator += (MpfiClass&, const cxsc::interval&);
   MpfiClass& operator += (MpfiClass&, const int);
   MpfiClass& operator += (MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass& operator += (MpfiClass&, const mpfr_t&);
   MpfiClass& operator += (MpfiClass&, const mpfi_t&);

   MpfiClass operator - (const MpfiClass&, const MpfiClass&);
   MpfiClass operator - (const MpfiClass&, const double&);
//   MpfiClass operator - (const MpfiClass&, const cxsc::real&);
//   MpfiClass operator - (const MpfiClass&, const cxsc::interval&);
   MpfiClass operator - (const MpfiClass&, const int);
   MpfiClass operator - (const MpfiClass&, const mpfr_t&);
   MpfiClass operator - (const MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass operator - (const MpfiClass&, const mpfi_t&);
   MpfiClass operator - (const double&, const MpfiClass&);
//   MpfiClass operator - (const cxsc::real&, const MpfiClass&);
//   MpfiClass operator - (const cxsc::interval&, const MpfiClass&);
   MpfiClass operator - (const int, const MpfiClass&);
   MpfiClass operator - (const mpfr_t&, const MpfiClass&);
   MpfiClass operator - (const MPFR::MpfrClass&, const MpfiClass&);
   MpfiClass operator - (const mpfi_t&, const MpfiClass&);

   MpfiClass& operator -= (MpfiClass&, const MpfiClass&);
   MpfiClass& operator -= (MpfiClass&, const double&);
//   MpfiClass& operator -= (MpfiClass&, const cxsc::real&);
//   MpfiClass& operator -= (MpfiClass&, const cxsc::interval&);
   MpfiClass& operator -= (MpfiClass&, const int);
   MpfiClass& operator -= (MpfiClass&, const mpfr_t&);
   MpfiClass& operator -= (MpfiClass&, const mpfi_t&);
   MpfiClass& operator -= (MpfiClass&, const MPFR::MpfrClass&);

   MpfiClass operator * (const MpfiClass&, const MpfiClass&);
   MpfiClass operator * (const MpfiClass&, const double&);
//   MpfiClass operator * (const MpfiClass&, const cxsc::real&);
//   MpfiClass operator * (const MpfiClass&, const cxsc::interval&);
   MpfiClass operator * (const MpfiClass&, const int);
   MpfiClass operator * (const MpfiClass&, const mpfr_t&);
   MpfiClass operator * (const MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass operator * (const MpfiClass&, const mpfi_t&);
   MpfiClass operator * (const double&, const MpfiClass&);
//   MpfiClass operator * (const cxsc::real&, const MpfiClass&);
//   MpfiClass operator * (const cxsc::interval&, const MpfiClass&);
   MpfiClass operator * (const int, const MpfiClass&);
   MpfiClass operator * (const mpfr_t&, const MpfiClass&);
   MpfiClass operator * (const MPFR::MpfrClass&, const MpfiClass&);
   MpfiClass operator * (const mpfi_t&, const MpfiClass&);

   MpfiClass& operator *= (MpfiClass&, const MpfiClass&);
   MpfiClass& operator *= (MpfiClass&, const double&);
//   MpfiClass& operator *= (MpfiClass&, const cxsc::real&);
//   MpfiClass& operator *= (MpfiClass&, const cxsc::interval&);
   MpfiClass& operator *= (MpfiClass&, const int);
   MpfiClass& operator *= (MpfiClass&, const mpfr_t&);
   MpfiClass& operator *= (MpfiClass&, const mpfi_t&);
   MpfiClass& operator *= (MpfiClass&, const MPFR::MpfrClass&);

   MpfiClass operator / (const MpfiClass&, const MpfiClass&);
   MpfiClass operator / (const MpfiClass&, const double&);
//   MpfiClass operator / (const MpfiClass&, const cxsc::real&);
//   MpfiClass operator / (const MpfiClass&, const cxsc::interval&);
   MpfiClass operator / (const MpfiClass&, const int);
   MpfiClass operator / (const MpfiClass&, const mpfr_t&);
   MpfiClass operator / (const MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass operator / (const MpfiClass&, const mpfi_t&);
   MpfiClass operator / (const double&, const MpfiClass&);
//   MpfiClass operator / (const cxsc::real&, const MpfiClass&);
//   MpfiClass operator / (const cxsc::interval&, const MpfiClass&);
   MpfiClass operator / (const int, const MpfiClass&);
   MpfiClass operator / (const mpfr_t&, const MpfiClass&);
   MpfiClass operator / (const MPFR::MpfrClass&, const MpfiClass&);
   MpfiClass operator / (const mpfi_t&, const MpfiClass&);

   MpfiClass& operator /= (MpfiClass&, const MpfiClass&);
   MpfiClass& operator /= (MpfiClass&, const double&);
//   MpfiClass& operator /= (MpfiClass&, const cxsc::real&);
//   MpfiClass& operator /= (MpfiClass&, const cxsc::interval&);
   MpfiClass& operator /= (MpfiClass&, const int);
   MpfiClass& operator /= (MpfiClass&, const mpfr_t&);
   MpfiClass& operator /= (MpfiClass&, const mpfi_t&);
   MpfiClass& operator /= (MpfiClass&, const MPFR::MpfrClass&);

   // Convex hull,  Blomquist 01.06.2010
   MpfiClass operator | ( const MpfiClass&, const MpfiClass& );
   MpfiClass operator | ( const double&, const MpfiClass& );
   MpfiClass operator | ( const MpfiClass&, const double& );
//   MpfiClass operator | ( const cxsc::real&, const MpfiClass& );
//   MpfiClass operator | ( const MpfiClass&, const cxsc::real& );
//   MpfiClass operator | ( const cxsc::interval&, const MpfiClass& );
//   MpfiClass operator | ( const MpfiClass&, const cxsc::interval& );
   MpfiClass operator | ( int , const MpfiClass& );
   MpfiClass operator | ( const MpfiClass&, int );
   MpfiClass operator | ( const MpfiClass&, const mpfr_t& );
   MpfiClass operator | ( const mpfr_t&, const MpfiClass& );
   MpfiClass operator | ( const MpfiClass&, const mpfi_t& );
   MpfiClass operator | ( const mpfi_t&, const MpfiClass& );
   MpfiClass operator | ( const MpfiClass&, const MPFR::MpfrClass& );
   MpfiClass operator | ( const MPFR::MpfrClass&, const MpfiClass& );

   MpfiClass & operator |= (MpfiClass&, const MpfiClass&);
   MpfiClass & operator |= (MpfiClass&, const double&);
//   MpfiClass & operator |= (MpfiClass&, const cxsc::real&);
//   MpfiClass & operator |= (MpfiClass&, const cxsc::interval&);
   MpfiClass & operator |= (MpfiClass&, int);
   MpfiClass & operator |= (MpfiClass&, const mpfr_t&);
   MpfiClass & operator |= (MpfiClass&, const mpfi_t&);
   MpfiClass & operator |= (MpfiClass&, const MPFR::MpfrClass&);

   // Intersection,  Blomquist 01.06.2010
   MpfiClass operator & ( const MpfiClass&, const MpfiClass& );
   MpfiClass operator & ( const MpfiClass&, const double& );
   MpfiClass operator & ( const double&, const MpfiClass& );
//   MpfiClass operator & ( const MpfiClass&, const cxsc::real& );
//   MpfiClass operator & ( const cxsc::real&, const MpfiClass& );
//   MpfiClass operator & ( const MpfiClass&, const cxsc::interval& );
//   MpfiClass operator & ( const cxsc::interval&, const MpfiClass& );
   MpfiClass operator & ( const MpfiClass&, int );
   MpfiClass operator & ( int, const MpfiClass& );
   MpfiClass operator & ( const MpfiClass&, const MPFR::MpfrClass& );
   MpfiClass operator & ( const MPFR::MpfrClass&, const MpfiClass& );
   MpfiClass operator & ( const MpfiClass&, const mpfr_t& );
   MpfiClass operator & ( const mpfr_t&, const MpfiClass& );
   MpfiClass operator & ( const MpfiClass&, const mpfi_t& );
   MpfiClass operator & ( const mpfi_t&, const MpfiClass& );

   MpfiClass & operator &= ( MpfiClass&, const MpfiClass& );
   MpfiClass & operator &= ( MpfiClass&, const double& );
//   MpfiClass & operator &= ( MpfiClass&, const cxsc::real& );
//   MpfiClass & operator &= ( MpfiClass&, const cxsc::interval& );
   MpfiClass & operator &= ( MpfiClass&, int );
   MpfiClass & operator &= ( MpfiClass&, const MPFR::MpfrClass& );
   MpfiClass & operator &= ( MpfiClass&, const mpfr_t& );
   MpfiClass & operator &= ( MpfiClass&, const mpfi_t& );

   MpfiClass sqr(const MpfiClass&);
   MpfiClass reci(const MpfiClass&);
   MpfiClass sqrt(const MpfiClass&);
   MpfiClass sqrtp1m1(const MpfiClass&);                                  // Blomquist 21.06.2010
   MpfiClass sqrtx2m1(const MpfiClass&);                                  // Blomquist 25.06.2010
   MpfiClass sqrt1mx2(const MpfiClass&);                                  // Blomquist 26.06.2010
   MpfiClass sqrt1px2(const MpfiClass&);                                  // Blomquist 30.06.2010
   MpfiClass sqrt_N(unsigned long int);                                   // Blomquist 14.06.2010
   MpfiClass sqrt(const MpfiClass&, unsigned long int);                   // Blomquist 19.05.2010
   MpfiClass cbrt(const MpfiClass&);
   MpfiClass sqrtx2y2(const MpfiClass&, const MpfiClass&);                // Blomquist 19.05.2010
   MpfiClass ln_sqrtx2y2(const MpfiClass&, const MpfiClass&);             // Blomquist 29.05.2010
   MpfiClass ln_sqrtxp1_2y2(const MpfiClass&, const MpfiClass&);          // Blomquist 07.05.2011
   MpfiClass abs(const MpfiClass&, PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
   MpfiClass x2my2(const MpfiClass& ,const MpfiClass&);
   MpfiClass x2py2(const MpfiClass& ,const MpfiClass&);
   MpfiClass agm  (const MpfiClass&, const MpfiClass&);

   MpfiClass power(const MpfiClass&, int);                                // Blomquist 03.06.2010
   MpfiClass power(const MpfiClass&, long int n);
   MpfiClass pow(const MpfiClass&, const MpfiClass&);
//   MpfiClass pow(const MpfiClass&, const cxsc::interval&);
//   MpfiClass pow(const MpfiClass&, const cxsc::real&);
   MpfiClass pow(const MpfiClass&, const MPFR::MpfrClass&);
   MpfiClass pow(const MpfiClass&, const double&);

   void times2pown (MpfiClass&, const long int);                                // Blomquist 17.05.2010

   MpfiClass ln(const MpfiClass&);
   MpfiClass exp(const MpfiClass&);
   MpfiClass exp2(const MpfiClass&);
   MpfiClass exp10(const MpfiClass&);                                     // Blomquist 18.05.2010

   MpfiClass cos(const MpfiClass&);
   MpfiClass sin(const MpfiClass&);
   MpfiClass tan(const MpfiClass&);
   MpfiClass cot(const MpfiClass&);                                       // Blomquist 17.05.2010

   MpfiClass acos(const MpfiClass&);
   MpfiClass asin(const MpfiClass&);
   MpfiClass atan(const MpfiClass&);
   MpfiClass atan2(const MpfiClass&, const MpfiClass&);                   // Blomquist 20.09.2010
   MpfiClass ATAN2(const MpfiClass&, const MpfiClass&);                   // Blomquist 20.09.2010

   MpfiClass acot(const MpfiClass&);                                      // Blomquist 18.05.2010

   MpfiClass cosh(const MpfiClass&);
   MpfiClass sinh(const MpfiClass&);
   MpfiClass tanh(const MpfiClass&);
   MpfiClass coth(const MpfiClass&);                                      // Blomquist 20.09.2010

   MpfiClass acosh  (const MpfiClass&);
   MpfiClass acoshp1(const MpfiClass&);
   MpfiClass asinh  (const MpfiClass&);
   MpfiClass atanh  (const MpfiClass&);
   MpfiClass acoth  (const MpfiClass&);                                   // Blomquist 18.05.2010

   MpfiClass csc (const MpfiClass&);  // 1/sin
   MpfiClass sec (const MpfiClass&);  // 1/cos
   MpfiClass csch(const MpfiClass&);  // 1/sinh
   MpfiClass sech(const MpfiClass&);  // 1/cosh

   MpfiClass lnp1(const MpfiClass&);
   MpfiClass expm1(const MpfiClass&);
   MpfiClass expmx2(const MpfiClass&);
   MpfiClass expmx2m1(const MpfiClass&);
   MpfiClass expx2(const MpfiClass&);
   MpfiClass expx2m1(const MpfiClass&);

   MpfiClass log2(const MpfiClass&);
   MpfiClass log10(const MpfiClass&);

   MpfiClass ln_cos(const MpfiClass&);
   MpfiClass ln_sin(const MpfiClass&);

   MpfiClass erf (const MpfiClass&);                                      // Blomquist 14.05.2010
   MpfiClass erfc(const MpfiClass&);                                      // Blomquist 14.05.2010

   MpfiClass digamma (const MpfiClass&);                                  // Blomquist 20.07.2010
   MpfiClass gamma_D (const MpfiClass&);                                  // Blomquist 21.07.2010

   MpfiClass Ei(const MpfiClass&);                                        // Blomquist 19.05.2010
   MpfiClass ifactorial (unsigned long int );                             // Blomquist 19.05.2010
   MpfiClass izeta      (unsigned long int );                             // Blomquist 14.06.2010

   void diam( const MpfiClass&, mpfr_t&);
   void RelDiam( const MpfiClass&, mpfr_t&);
   void AbsMax( const MpfiClass&, mpfr_t&);
   void AbsMin( const MpfiClass&, mpfr_t&);
   void mid( const MpfiClass&, mpfr_t&);
   void random( const MpfiClass&, mpfr_t&);

   MPFR::MpfrClass diam(const MpfiClass&);
   MPFR::MpfrClass RelDiam(const MpfiClass&);
   MPFR::MpfrClass AbsMax(const MpfiClass&);
   MPFR::MpfrClass AbsMin(const MpfiClass&);
   MPFR::MpfrClass mid(const MpfiClass&);
   MPFR::MpfrClass random(const MpfiClass&);

   MPFR::MpfrClass Inf(const MpfiClass&, PrecisionType = MPFR::MpfrClass::GetCurrPrecision()); // Blomquist 27.11.2010
   MPFR::MpfrClass Sup(const MpfiClass&, PrecisionType = MPFR::MpfrClass::GetCurrPrecision()); // Blomquist 27.11.2010

   MpfiClass Blow(const MpfiClass&, const MPFR::MpfrClass&);              // Blomquist 03.07.2010

   std::ostream& operator << (std::ostream&, const MpfiClass&);
   std::istream& operator >> (std::istream&, MpfiClass&);

   int common_decimals(const MpfiClass&);

   void print_binary(const MpfiClass&);
   void random(MpfiClass&, gmp_randstate_t);

   void set_nan  (MpfiClass&);                                            // Blomquist, 25.05.2010
   void set_inf  (MpfiClass&);                                            // Blomquist, 25.05.2010
   void set_zero (MpfiClass&);                                            // Blomquist, 19.07.2010

   bool compare_equal     (const MpfiClass&, const MpfiClass&);           // Blomquist 25.05.2010
   bool compare_less      (const MpfiClass&, const MpfiClass&);           // Blomquist 26.05.2010
   bool compare_lessequal (const MpfiClass&, const MpfiClass&);           // Blomquist 26.05.2010

   void set_Mpfi (MpfiClass&, const MpfiClass&, PrecisionType);

   void Interval_Scaling(MpfiClass&, long int&);
   MpfiClass scal_prod(const MpfiClass&, const MpfiClass&,
                       const MpfiClass&, const MpfiClass&);

   void P_Interval_Scaling(MpfiClass&, long int&);

}

#endif
