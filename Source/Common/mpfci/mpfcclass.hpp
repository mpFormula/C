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
/*  Datei:  mpfcclass.hpp                    */
/*  Zweck:  C++-Wrapper-Klasse fuer die      */
/*          komplexe MPFR-Bibliothek         */
/*  Based on       mpfr-3.0.0                */
/*********************************************/


#ifndef _CXSC_MPFCCLASS_H_INCLUDED
#define _CXSC_MPFCCLASS_H_INCLUDED

// #include <iostream>
// #include <sstream>
// #include <string>
// #include <stdio.h>
// #include <gmp.h>
// #include <mpfr.h>
// #include <mpfi_io.h>

#include "mpfrclass.hpp"
#include <stdlib.h>
#include <list>

//#include <complex.hpp>

namespace MPFR{

class MpfcClass{

protected:
    mpfr_t mpfr_re;        // mpfr_re: Variable of type mpfr_t for the real part
    mpfr_t mpfr_im;        // mpfr_im: Variable of type mpfr_t for the imaginary part

    static int base;

public:
    // Constructors and destructors

    MpfcClass ();

explicit      MpfcClass (int, int,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfcClass (const mpfr_t&, const mpfr_t&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

explicit      MpfcClass (const double&, const double&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

//explicit      MpfcClass (const cxsc::real&, const cxsc::real&,
//              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
//              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

//explicit      MpfcClass (const cxsc::complex&,
//              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
//              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

explicit      MpfcClass (const MpfrClass&, const MpfrClass&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

//explicit      MpfcClass (const cxsc::real&,
//              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
//              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfcClass (const mpfr_t&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

explicit      MpfcClass (const MpfrClass&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

explicit      MpfcClass (const double&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

explicit      MpfcClass (int,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfcClass (const std::string&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    MpfcClass (const MpfcClass&,
              RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
              PrecisionType = MPFR::MpfrClass::GetCurrPrecision());

    ~MpfcClass ();


    mpfr_t& GetValueRe();
    mpfr_t& GetValueIm();

    friend const mpfr_t& getvalueRe(const MpfcClass&);
    friend const mpfr_t& getvalueIm(const MpfcClass&);

    void SetValueRe(const mpfr_t&);
    void SetValueIm(const mpfr_t&);
    void SetValue(const mpfr_t&, const mpfr_t&);

    // ----------------- Precision Handling ---------------------------------
    static void SetCurrPrecision (PrecisionType);
    static const PrecisionType GetCurrPrecision ();

    void SetPrecision (PrecisionType);
    PrecisionType GetPrecision () const;

    // The following function rounds the actual object to the new precision
    void RoundPrecision(PrecisionType, RoundingMode);

    // ----------------- Rounding-Mode Handling ------------------------------
    static void SetCurrRndMode (RoundingMode);
    static const RoundingMode GetCurrRndMode ();

    // ----------------- Base Handling ---------------------------------------
    static void SetBase (int);
    static const int GetBase ();


    // ------------------- Assignment-Operators ------------------------------
    MpfcClass& operator = (const MpfcClass&);
    MpfcClass& operator = (const MpfrClass&);
    MpfcClass& operator = (const double&);
//    MpfcClass& operator = (const cxsc::real&);
    MpfcClass& operator = (const int);
//    MpfcClass& operator = (const cxsc::complex&);
    MpfcClass& operator = (const std::string&);


    // --------------------Friend-Functions ---------------------------------
//    friend cxsc::complex to_complex(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfrClass Re(const MpfcClass&);
    friend MpfrClass Im(const MpfcClass&);
    friend MpfcClass conj(const MpfcClass&);
    friend MpfrClass abs (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode(),
			                    PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
    friend MpfrClass arg (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode(),
			                    PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
    friend MpfcClass ln   (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass lnp1 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass exp  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass expm1(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sqr  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sqrt (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sqrtp1m1 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass cos  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sin  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass tan  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass cot  (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass asin (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sinh (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass cosh (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass tanh (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass coth (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass reci (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
    friend MpfcClass sqrt1px2 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());

    // -------------------- friend functions only for the internal use: ---------------------------------
    friend MpfrClass Re_cot (const MpfcClass&, RoundingMode);
    friend MpfrClass Im_cot (const MpfcClass&, RoundingMode);
    friend MpfrClass Re_asin(const MpfcClass&, RoundingMode);
    friend MpfrClass Im_asin(const MpfcClass&, RoundingMode);
    // -------------------- friend functions only for the internal use, end ------------------------------

    friend bool isNan    (const MpfcClass&);
    friend bool isInf    (const MpfcClass&);
    friend bool isNumber (const MpfcClass&);
    friend bool isZero   (const MpfcClass&);

    friend void times2pown (MpfcClass&, const long int, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());

    /* Arithmetic Operators*/
    // Addition
    MpfcClass operator + () const;
    friend MpfcClass operator + (const MpfcClass&, const MpfcClass&);
    friend MpfcClass operator + (const MpfcClass&, const double&);
    friend MpfcClass operator + (const MpfcClass&, const int);
//    friend MpfcClass operator + (const MpfcClass&, const cxsc::real&);
    friend MpfcClass operator + (const MpfcClass&, const MpfrClass&);
    friend MpfcClass operator + (const MpfcClass&, const mpfr_t&);
//    friend MpfcClass operator + (const MpfcClass&, const cxsc::complex&);

    // Subtraction
    MpfcClass operator - () const;
    friend MpfcClass operator - (const MpfcClass&, const MpfcClass&);
    friend MpfcClass operator - (const MpfcClass&, const double&);
    friend MpfcClass operator - (const MpfcClass&, const int);
//    friend MpfcClass operator - (const MpfcClass&, const cxsc::real&);
    friend MpfcClass operator - (const MpfcClass&, const MpfrClass&);
    friend MpfcClass operator - (const MpfcClass&, const mpfr_t&);
//    friend MpfcClass operator - (const MpfcClass&, const cxsc::complex&);
    friend MpfcClass operator - (const double&, const MpfcClass&);
    friend MpfcClass operator - (const int, const MpfcClass&);
//    friend MpfcClass operator - (const cxsc::real&, const MpfcClass&);
//    friend MpfcClass operator - (const cxsc::complex&, const MpfcClass&);
    friend MpfcClass operator - (const MpfrClass&, const MpfcClass&);
    friend MpfcClass operator - (const mpfr_t&, const MpfcClass&);

    // ----------------- Multiplication ---------------------------------------
    friend MpfcClass operator * (const MpfcClass&, const MpfcClass&);
    friend MpfcClass operator * (const MpfcClass&, const double&);
//    friend MpfcClass operator * (const MpfcClass&, const cxsc::real&);
    friend MpfcClass operator * (const MpfcClass&, const int);
    friend MpfcClass operator * (const MpfcClass&, const MpfrClass&);
    friend MpfcClass operator * (const MpfcClass&, const mpfr_t&);
//    friend MpfcClass operator * (const MpfcClass&, const cxsc::complex&);

    // ----------------- Division ----       -----------------------------------
    friend MpfcClass operator / (const double&, const MpfcClass&);
    friend MpfcClass operator / (const int,               const MpfcClass&);
//    friend MpfcClass operator / (const cxsc::real&,       const MpfcClass&);
//    friend MpfcClass operator / (const cxsc::complex&,    const MpfcClass&);
    friend MpfcClass operator / (const mpfr_t&,           const MpfcClass&);
    friend MpfcClass operator / (const MpfrClass&,        const MpfcClass&);

    friend MpfcClass operator / (const MpfcClass&, const MpfcClass&);
    friend MpfcClass operator / (const MpfcClass&, const MpfrClass&);
    friend MpfcClass operator / (const MpfcClass&, const mpfr_t&);
    friend MpfcClass operator / (const MpfcClass&, const double&);
    friend MpfcClass operator / (const MpfcClass&, const int);
//    friend MpfcClass operator / (const MpfcClass&, const cxsc::real&);
//    friend MpfcClass operator / (const MpfcClass&, const cxsc::complex&);

    friend bool operator == (const MpfcClass&, const MpfcClass&);
    friend bool operator == (const MpfcClass&, const MpfrClass&);
    friend bool operator == (const MpfcClass&, const mpfr_t&);
    friend bool operator == (const MpfcClass&, const double&);
    friend bool operator == (const MpfcClass&, const int);
//    friend bool operator == (const MpfcClass&, const cxsc::real&);
//    friend bool operator == (const MpfcClass&, const cxsc::complex&);

    friend bool operator != (const MpfcClass&, const MpfcClass&);
    friend bool operator != (const MpfcClass&, const MpfrClass&);
    friend bool operator != (const MpfcClass&, const mpfr_t&);
    friend bool operator != (const MpfcClass&, const double&);
    friend bool operator != (const MpfcClass&, const int);
//    friend bool operator != (const MpfcClass&, const cxsc::real&);
//    friend bool operator != (const MpfcClass&, const cxsc::complex&);

    friend std::string to_string(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode(), PrecisionType = 0);
    friend MpfcClass string2Mpfc (const std::string&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode(),
                                                      PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
    // --------------- Input-Output-Operators ---------------------------------
    friend std::istream& operator >> (std::istream&, MpfcClass&);
    friend std::ostream& operator << (std::ostream&, const MpfcClass&);

    friend void set_Mpfc (MpfcClass&, const MpfcClass&, RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
                                                        PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
//    friend MpfcClass real2Mpfc(const cxsc::real&);
    friend MpfcClass double2Mpfc(const double&);
    friend MpfcClass int2Mpfc (const int& x);
    friend MpfcClass MpfrClass2Mpfc(const MpfrClass&);
    friend MpfcClass mpfr_t2Mpfc(const mpfr_t&);

}; // Class end

  std::string to_string(const MpfcClass&, RoundingMode, PrecisionType);
  MpfcClass string2Mpfc (const std::string&, RoundingMode rnd, PrecisionType prec);

//  MpfcClass complex2Mpfc(const cxsc::complex&);

  // Declaration of all friend functions outside the class:
//  MpfcClass real2Mpfc(const cxsc::real&);
  MpfcClass double2Mpfc(const double&);
  MpfcClass MpfrClass2Mpfc(const MpfrClass&);
  MpfcClass mpfr_t2Mpfc(const mpfr_t&);
  MpfcClass int2Mpfc (const int& x);

  void times2pown (MpfcClass&, const long int, RoundingMode);

  const mpfr_t& getvalueRe(const MpfcClass&);
  const mpfr_t& getvalueIm(const MpfcClass&);

//  cxsc::complex to_complex (const MpfcClass& , RoundingMode);
  MpfrClass Re  (const MpfcClass&);
  MpfrClass Im  (const MpfcClass&);
  MpfcClass conj(const MpfcClass&);
  MpfrClass abs (const MpfcClass&, RoundingMode, PrecisionType);
  MpfrClass arg (const MpfcClass&, RoundingMode, PrecisionType);
  MpfrClass argp1 (const MpfcClass&, RoundingMode  = MPFR::MpfrClass::GetCurrRndMode(),
		                     PrecisionType = MPFR::MpfrClass::GetCurrPrecision());
  MpfcClass ln   (const MpfcClass&, RoundingMode);
  MpfcClass lnp1 (const MpfcClass&, RoundingMode);
  MpfcClass exp  (const MpfcClass&, RoundingMode);
  MpfcClass expm1(const MpfcClass&, RoundingMode);
  MpfcClass sqr  (const MpfcClass&, RoundingMode);
  MpfcClass sqrt (const MpfcClass&, RoundingMode);
  MpfcClass sqrtp1m1 (const MpfcClass&, RoundingMode);
  MpfrClass Re_sqrtp1m1(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfrClass Im_sqrtp1m1(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfrClass Re_sqrt1px2(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfrClass Im_sqrt1px2(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfrClass Re_sqrtx2m1(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfrClass Im_sqrtx2m1(const MpfrClass&, const MpfrClass&, RoundingMode);
  MpfcClass sqrt1px2 (const MpfcClass&, RoundingMode);
  MpfcClass sqrt1mx2 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass sqrtmx2m1(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass sqrtx2m1 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass cos  (const MpfcClass&, RoundingMode);
  MpfcClass sin  (const MpfcClass&, RoundingMode);
  MpfcClass tan  (const MpfcClass&, RoundingMode);
  MpfcClass cot  (const MpfcClass&, RoundingMode);
  MpfcClass sinh (const MpfcClass&, RoundingMode);
  MpfcClass cosh (const MpfcClass&, RoundingMode);
  MpfcClass tanh (const MpfcClass&, RoundingMode);
  MpfcClass coth (const MpfcClass&, RoundingMode);
  MpfcClass reci (const MpfcClass&, RoundingMode);
  MpfcClass asin (const MpfcClass&, RoundingMode);
  MpfcClass acos (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass atan (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass acot (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass asinh(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass acosh(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass atanh(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass acoth(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass sqrt (const MpfcClass&, int n, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  std::list<MpfcClass> sqrt_all(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  std::list<MpfcClass> sqrt_all(const MpfcClass&, int, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass exp2 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass exp10(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass power(const MpfcClass&, int, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass pow  (const MpfcClass&, const MPFR::MpfrClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass pow  (const MpfcClass&, const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass log2 (const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());
  MpfcClass log10(const MpfcClass&, RoundingMode = MPFR::MpfrClass::GetCurrRndMode());

  MpfrClass Re_cot (const MpfcClass&, RoundingMode);
  MpfrClass Im_cot (const MpfcClass&, RoundingMode);
  MpfrClass Re_asin(const MpfcClass&, RoundingMode);
  MpfrClass Im_asin(const MpfcClass&, RoundingMode);

  bool isNan   (const MpfcClass&);
  bool isInf   (const MpfcClass&);
  bool isNumber(const MpfcClass&);
  bool isZero  (const MpfcClass&);

  // ---------------------- friend-Operators -----------------------------------
  MpfcClass operator + (const MpfcClass&, const MpfcClass&);
  MpfcClass operator + (const MpfcClass&, const double&);
  MpfcClass operator + (const MpfcClass&, const int);
//  MpfcClass operator + (const MpfcClass&, const cxsc::real&);
  MpfcClass operator + (const MpfcClass&, const MpfrClass&);
  MpfcClass operator + (const MpfcClass&, const mpfr_t&);
//  MpfcClass operator + (const MpfcClass&, const cxsc::complex&);

  MpfcClass operator - (const MpfcClass&, const MpfcClass&);
  MpfcClass operator - (const MpfcClass&, const double&);
  MpfcClass operator - (const MpfcClass&, const int);
//  MpfcClass operator - (const MpfcClass&, const cxsc::real&);
  MpfcClass operator - (const MpfcClass&, const MpfrClass&);
  MpfcClass operator - (const MpfcClass&, const mpfr_t&);
//  MpfcClass operator - (const MpfcClass&, const cxsc::complex&);
  MpfcClass operator - (const double&,           const MpfcClass&);
  MpfcClass operator - (const int,               const MpfcClass&);
//  MpfcClass operator - (const cxsc::real&,       const MpfcClass&);
//  MpfcClass operator - (const cxsc::complex&,    const MpfcClass&);
  MpfcClass operator - (const MpfrClass&,        const MpfcClass&);
  MpfcClass operator - (const mpfr_t&,           const MpfcClass&);

  MpfcClass operator * (const MpfcClass&, const MpfcClass&);
  MpfcClass operator * (const MpfcClass&, const double&);
  MpfcClass operator * (const MpfcClass&, const int);
  MpfcClass operator * (const MpfcClass&, const MpfrClass&);
  MpfcClass operator * (const MpfcClass&, const mpfr_t&);
//  MpfcClass operator * (const MpfcClass&, const cxsc::complex&);

  MpfcClass operator / (const MpfcClass&, const MpfcClass&);
  MpfcClass operator / (const double&, const MpfcClass&);
  MpfcClass operator / (const int,               const MpfcClass&);
//  MpfcClass operator / (const cxsc::real&,       const MpfcClass&);
//  MpfcClass operator / (const cxsc::complex&,    const MpfcClass&);
  MpfcClass operator / (const mpfr_t&,           const MpfcClass&);
  MpfcClass operator / (const MpfrClass&,        const MpfcClass&);
  MpfcClass operator / (const MpfcClass&, const MpfrClass&);
  MpfcClass operator / (const MpfcClass&, const mpfr_t&);
  MpfcClass operator / (const MpfcClass&, const double&);
  MpfcClass operator / (const MpfcClass&, const int);
//  MpfcClass operator / (const MpfcClass&, const cxsc::real&);
//  MpfcClass operator / (const MpfcClass&, const cxsc::complex&);

  bool operator == (const MpfcClass&, const MpfcClass&);

  bool operator == (const MpfcClass&, const MpfrClass&);
  bool operator == (const MpfcClass&, const mpfr_t&);
  bool operator == (const MpfcClass&, const double&);
  bool operator == (const MpfcClass&, const int);
//  bool operator == (const MpfcClass&, const cxsc::real&);
//  bool operator == (const MpfcClass&, const cxsc::complex&);

  bool operator != (const MpfcClass&, const MpfcClass&);
  bool operator != (const MpfcClass&, const MpfrClass&);
  bool operator != (const MpfcClass&, const mpfr_t&);
  bool operator != (const MpfcClass&, const double&);
  bool operator != (const MpfcClass&, const int);
//  bool operator != (const MpfcClass&, const cxsc::real&);
//  bool operator != (const MpfcClass&, const cxsc::complex&);
  // ---------------------- friend-Operatoren Ende ---------------------------------

  // ------------ Die folgenden Operatoren sind keine friend-Operatoren ------------
  MpfcClass operator + (const double&,           const MpfcClass&);
  MpfcClass operator + (const int,               const MpfcClass&);
//  MpfcClass operator + (const cxsc::real&,       const MpfcClass&);
  MpfcClass operator + (const MpfrClass&,        const MpfcClass&);
  MpfcClass operator + (const mpfr_t&,           const MpfcClass&);
//  MpfcClass operator + (const cxsc::complex&,    const MpfcClass&);

  MpfcClass& operator += (MpfcClass&, const MpfcClass&);
  MpfcClass& operator += (MpfcClass&, const double&);
  MpfcClass& operator += (MpfcClass&, const int);
//  MpfcClass& operator += (MpfcClass&, const cxsc::real&);
  MpfcClass& operator += (MpfcClass&, const MpfrClass&);
  MpfcClass& operator += (MpfcClass&, const mpfr_t&);
//  MpfcClass& operator += (MpfcClass&, const cxsc::complex&);

  MpfcClass& operator -= (MpfcClass&, const MpfcClass&);
  MpfcClass& operator -= (MpfcClass&, const double&);
  MpfcClass& operator -= (MpfcClass&, const int);
//  MpfcClass& operator -= (MpfcClass&, const cxsc::real&);
//  MpfcClass& operator -= (MpfcClass&, const cxsc::complex&);
  MpfcClass& operator -= (MpfcClass&, const MpfrClass&);
  MpfcClass& operator -= (MpfcClass&, const mpfr_t&);

//  MpfcClass operator * (const MpfcClass&, const cxsc::real&);

  MpfcClass operator * (const double&,           const MpfcClass&);
  MpfcClass operator * (const int,               const MpfcClass&);
//  MpfcClass operator * (const cxsc::real&,       const MpfcClass&);
//  MpfcClass operator * (const cxsc::complex&,    const MpfcClass&);
  MpfcClass operator * (const MpfrClass&,        const MpfcClass&);
  MpfcClass operator * (const mpfr_t&,           const MpfcClass&);

  MpfcClass& operator *= (MpfcClass&, const MpfcClass&);
  MpfcClass& operator *= (MpfcClass&, const double&);
  MpfcClass& operator *= (MpfcClass&, const int);
//  MpfcClass& operator *= (MpfcClass&, const cxsc::real&);
//  MpfcClass& operator *= (MpfcClass&, const cxsc::complex&);
  MpfcClass& operator *= (MpfcClass&, const MpfrClass&);
  MpfcClass& operator *= (MpfcClass&, const mpfr_t&);

  MpfcClass& operator /= (MpfcClass&, const MpfcClass&);
  MpfcClass& operator /= (MpfcClass&, const double&);
  MpfcClass& operator /= (MpfcClass&, const int);
//  MpfcClass& operator /= (MpfcClass&, const cxsc::real&);
//  MpfcClass& operator /= (MpfcClass&, const cxsc::complex&);
  MpfcClass& operator /= (MpfcClass&, const MpfrClass&);
  MpfcClass& operator /= (MpfcClass&, const mpfr_t&);

  bool operator == (const MpfrClass&,        const MpfcClass&);
  bool operator == (const mpfr_t&,           const MpfcClass&);
  bool operator == (const double&,           const MpfcClass&);
  bool operator == (const int,               const MpfcClass&);
//  bool operator == (const cxsc::real&,       const MpfcClass&);
//  bool operator == (const cxsc::complex&,    const MpfcClass&);

  bool operator != (const MpfrClass&,        const MpfcClass&);
  bool operator != (const mpfr_t&,           const MpfcClass&);
  bool operator != (const double&,           const MpfcClass&);
  bool operator != (const int,               const MpfcClass&);
//  bool operator != (const cxsc::real&,       const MpfcClass&);
//  bool operator != (const cxsc::complex&,    const MpfcClass&);

  void set_nan  (MpfcClass&);
  void set_inf  (MpfcClass&, const int);
  void set_zero (MpfcClass&);

  MpfrClass x2my2p1(const MpfrClass&, const MpfrClass&, RoundingMode);        // Spaeter loeschen !!!!!!!!!!!!!
  MpfrClass sqrt1px2_alpha(const MpfrClass&, const MpfrClass&, RoundingMode); // Spaeter loeschen !!!!!!!!!!!!!

  // ---------------------------- Input|Output -------------------------------------
  std::istream& operator >> (std::istream&, MpfcClass&);
  std::ostream& operator << (std::ostream&, const MpfcClass&);

  void set_Mpfc (MpfcClass&, const MpfcClass&, RoundingMode, PrecisionType);

}; // namespace MPFR

#endif
