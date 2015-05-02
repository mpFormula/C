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
/*  Datei:  mpfrclass.cpp                    */
/*  Zweck:  C++-Wrapper-Klasse fuer          */
/*          die MPFR-Bibliothek              */
/*  Based on       mpfr-3.0.0                */
/*********************************************/


#include "mpfrclass.hpp"
#include "mpficlass.hpp"


namespace MPFR{

PrecisionType MpfrClass::CurrPrecision = mpfr_get_default_prec();
RoundingMode MpfrClass::CurrRndMode = mpfr_get_default_rounding_mode();
int MpfrClass::base = 10;


    /*Konstruktoren und Destruktoren*/

    MpfrClass::MpfrClass()
    {
        mpfr_init2(mpfr_rep, MpfrClass::CurrPrecision);
    }

    MpfrClass::MpfrClass (int x, RoundingMode rnd, PrecisionType prec)
    {
        mpfr_init2(mpfr_rep, prec);
        mpfr_set_si(mpfr_rep, (long int)x, rnd);
    }

    MpfrClass::MpfrClass (const double& d, RoundingMode rnd, PrecisionType prec)
    {
        mpfr_init2(mpfr_rep, prec);
        mpfr_set_d(mpfr_rep, d, rnd);
    }

    MpfrClass::MpfrClass (const mpfr_t& fr, RoundingMode rnd, PrecisionType prec)
    {
        mpfr_init2(mpfr_rep, prec);
        mpfr_set(mpfr_rep, fr, rnd);
    }

    MpfrClass::MpfrClass (const std::string& s, RoundingMode rnd, PrecisionType prec)
    {
      const char *ptr = s.c_str();
      mpfr_init2(mpfr_rep, prec);
      if ( mpfr_set_str(mpfr_rep, ptr, MpfrClass::GetBase(), rnd) )
      {
        std::cerr << "Input error: Wrong base or whitespace(s) at the end of the string?" << std::endl ;
        exit(1);
      }
    }

//    MpfrClass::MpfrClass (const cxsc::real& r, RoundingMode rnd, PrecisionType prec)
//    {
//      mpfr_init2(mpfr_rep, prec);
//      mpfr_set_d(mpfr_rep, _double(r), rnd);
//    }

    MpfrClass::MpfrClass (const MpfrClass& r, RoundingMode rnd, PrecisionType prec)
    {
      mpfr_init2(mpfr_rep, prec);
      mpfr_set(mpfr_rep, r.mpfr_rep, rnd);
    }

    MpfrClass::~MpfrClass()
    {
        mpfr_clear(mpfr_rep);
    }

    mpfr_t& MpfrClass::GetValue()
    // Memberfunktion: Liefert Referenz auf das Attribut mpfr_rep des aktuellen Objekts
    {
        return this->mpfr_rep;
    }

    const mpfr_t& getvalue(const MpfrClass& r)
    // friend-Funktion:
    // Liefert Referenz auf das Attribut mpfr_rep des konstanten Objekts r
    {
      return r.mpfr_rep;
    }

    // Setzten von mpfr_rep auf v;
    // mpfr_rep erhält die Präzision von v, d.h. der Wert von v bleibt erhalten
    void MpfrClass::SetValue(const mpfr_t& v)
    {
        mpfr_set_prec(mpfr_rep, mpfr_get_prec(v));
        mpfr_set(mpfr_rep, v, RoundNearest);
    }

    /* --------------------- Assignment Operators -------------------------------*/
    // The precision of the left operand gets the value of the Current-Precision,
    // independent of the precision of the right operand.
    // A necessary rounding is realized by the Default-Rounding-Mode.

    MpfrClass& MpfrClass::operator = (const MpfrClass& v)
    {
      // Abfrage ob es derselbe ist
      if (this == &v)
      {
        (*this).RoundPrecision(MpfrClass::GetCurrPrecision(), MpfrClass::GetCurrRndMode());
        return *this;
      }
      mpfr_clear(mpfr_rep);
      mpfr_init2(mpfr_rep, MpfrClass::GetCurrPrecision());
      mpfr_set(mpfr_rep, v.mpfr_rep, MpfrClass::GetCurrRndMode());
      return *this;
    }

    MpfrClass& MpfrClass::operator = (const mpfr_t& v)
    {
      mpfr_set_prec(mpfr_rep, GetCurrPrecision() );
      mpfr_set (mpfr_rep , v, MpfrClass::GetCurrRndMode());
      return *this;
    }

    MpfrClass& MpfrClass::operator = (const double& d)
    {
      mpfr_set_prec(mpfr_rep, GetCurrPrecision() );
      mpfr_set_d (mpfr_rep, d, MpfrClass::GetCurrRndMode());
      return *this;
    }

//    MpfrClass& MpfrClass::operator = (const cxsc::real& r)
//    {
//      mpfr_set_prec(mpfr_rep, GetCurrPrecision() );
//      mpfr_set_d (mpfr_rep, _double(r), MpfrClass::GetCurrRndMode());
//      return *this;
//    }

    MpfrClass& MpfrClass::operator = (const int& i)
    {
      mpfr_set_prec(mpfr_rep, GetCurrPrecision() );
      mpfr_set_si (mpfr_rep, (long int)i, MpfrClass::GetCurrRndMode());
      return *this;
    }

    /* Precision and Roundingmode Handling */

    // Setzten der Current-Precision
    void MpfrClass::SetCurrPrecision (PrecisionType newprec)
    {
        mpfr_set_default_prec(newprec);
        CurrPrecision = newprec;
    }

    // Setzten der Precision fuer das aktuelle Objekt, Wert wird geloescht
    void MpfrClass::SetPrecision (PrecisionType newprec)
    {
        mpfr_set_prec(mpfr_rep, newprec);
    }

    // Setzten der Präzision fuer das aktuelle Objekt, Wert bleibt erhalten
    // oder wird gerundet
    void MpfrClass::RoundPrecision(PrecisionType newprec, RoundingMode rnd)
    {
        mpfr_prec_round(mpfr_rep, newprec, rnd);
    }

    // Auslesen der Current-Precision
    const PrecisionType MpfrClass::GetCurrPrecision ()
    {
        return MpfrClass::CurrPrecision;
    }

    // Auslesen der Precision des aktuellen Objekts
    PrecisionType MpfrClass::GetPrecision () const
    {
        return mpfr_get_prec(mpfr_rep);
    }

    // Setzten der Basis (Wert zwischen 2-36)
    void MpfrClass::SetBase (int b)
    {
        base = b;
    }

    // Auslesen der aktuellen Basis
    const int MpfrClass::GetBase ()
    {
        return base;
    }

    // Rundungsmodus setzten
    void MpfrClass::SetCurrRndMode (RoundingMode newrndmode)
    {
        mpfr_set_default_rounding_mode(newrndmode);
        CurrRndMode = newrndmode;
    }

    // Auslesen des Aktuellen Rundungsmodus
    const RoundingMode MpfrClass::GetCurrRndMode ()
    {
        return CurrRndMode;
    }

    /* Setzen von NaN */
    void set_nan (MpfrClass& a)  // Blomquist, 28.04.2010
    {
       mpfr_set_nan(a.mpfr_rep);
    }

    /* Setzen von +Inf, -Inf */
    void set_inf (MpfrClass& a, int n)  // Blomquist 28.04.2010
    {  // n >= 0  ==> +Inf;  n < 0  ==>  -Inf;
       mpfr_set_inf (a.mpfr_rep, n);
    }

    void set_zero (MpfrClass& a, int n)
    {
      mpfr_set_zero (a.mpfr_rep, n);
    }

    /*Konstanten*/

    MpfrClass MpfrClass::Pi (RoundingMode rnd, PrecisionType prec)
    {
         MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
         mpfr_const_pi(res.mpfr_rep, rnd);

        return res;
    }

    MpfrClass MpfrClass::Ln2 (RoundingMode rnd, PrecisionType prec)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
        mpfr_const_log2(res.mpfr_rep, rnd);

        return res;
    }

    MpfrClass MpfrClass::Euler (RoundingMode rnd, PrecisionType prec)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
        mpfr_const_euler(res.mpfr_rep, rnd);

        return res;
    }

    MpfrClass MpfrClass::Catalan (RoundingMode rnd, PrecisionType prec)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
        mpfr_const_catalan(res.mpfr_rep, rnd);

        return res;
    }


    /* Arithmetic Operators */

    // Addition-----------------------------------------------------
    MpfrClass MpfrClass::operator + () const
    {
        MpfrClass res(0.0, MpfrClass::CurrRndMode, this->GetPrecision());
        mpfr_set(res.mpfr_rep, mpfr_rep, MpfrClass::CurrRndMode);

        return res;
    }
    // Dyadic operators: The result precision is always the Current-Precision !
    MpfrClass operator + (const MpfrClass& a, const MpfrClass& b)
    {
      MpfrClass v(0); // v mit 0 initialisieren und seine Praezision auf Curren-Precision setzrn
      mpfr_add(v.mpfr_rep, a.mpfr_rep, b.mpfr_rep, MpfrClass::GetCurrRndMode());
      return v;
    }

    MpfrClass operator + (const MpfrClass& a, const double& b)             // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_add_d(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator + (const MpfrClass& a, const cxsc::real& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_add_d(v.mpfr_rep, a.mpfr_rep, _double(b), MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator + (const MpfrClass& a, const int b)                // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_add_si(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator + (const MpfrClass& a, const mpfr_t& b)            // Blomquist 23.05.2010
    {
       MpfrClass v(0, MpfrClass::GetCurrRndMode(),MpfrClass::GetCurrPrecision() );
       mpfr_add(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator + (const double& a, const MpfrClass& b)             // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_add_d(v.mpfr_rep, b.mpfr_rep, a, MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator + (const cxsc::real& a, const MpfrClass& b)        // Blomquist 23.05.2010
//    {
//       MpfrClass v;
//       v = b + a;
//       return v;
//    }

    MpfrClass operator + (const int a, const MpfrClass& b)                // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_add_si(v.mpfr_rep, b.mpfr_rep, a, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator + (const mpfr_t& a, const MpfrClass& b)            // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_add(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }


    MpfrClass& operator += (MpfrClass& a, const MpfrClass& b)
    {
      a = a + b;
      return a;
    }

    MpfrClass& operator += (MpfrClass& a, const double& b)                    // Blomquist 23.05.2010
    {
      a = a + b;
      return a;
    }

//    MpfrClass& operator += (MpfrClass& a, const cxsc::real& b)                // Blomquist 23.05.2010
//    {
//      a = a + b;
//      return a;
//    }

    MpfrClass& operator += (MpfrClass& a, const int b)              // Blomquist 23.05.2010
    {
      a = a + b;
      return a;
    }

    MpfrClass& operator += (MpfrClass& a, const mpfr_t& b)     // Blomquist 23.05.2010
    {
      a = a + b;
      return a;
    }


    // Subtraction --------------------------------------------------------
        MpfrClass MpfrClass::operator - () const
    {
        MpfrClass res(0.0, MpfrClass::CurrRndMode, this->GetPrecision());
        mpfr_neg(res.mpfr_rep, mpfr_rep, MpfrClass::CurrRndMode);

        return res;
    }

    MpfrClass operator - (const MpfrClass& a, const MpfrClass& b)  // Versuch
    {
      MpfrClass v(0);
      mpfr_sub(v.mpfr_rep, a.mpfr_rep, b.mpfr_rep, MpfrClass::GetCurrRndMode());
      return v;
    }

    MpfrClass operator - (const MpfrClass& a, const double& b)             // Blomquist 23.05.2010
    {
       MpfrClass v(0);
       mpfr_sub_d(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator - (const MpfrClass& a, const cxsc::real& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_sub_d(v.mpfr_rep, a.mpfr_rep, _double(b), MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator - (const MpfrClass &a, const int b)                // Blomquist 24.05.2010
    {
       MpfrClass v(0);
       mpfr_sub_si(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator - (const MpfrClass& a, const mpfr_t& b)            // Blomquist 24.05.2010
    {
       MpfrClass v(0);
       mpfr_sub(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator - (const double& a, const MpfrClass&  b)            // Blomquist 24.05.2010
    {
       MpfrClass v(0);
       mpfr_d_sub(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator - (const cxsc::real& a, const MpfrClass& b)        // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_d_sub(v.mpfr_rep, _double(a), b.mpfr_rep, MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator - (const int a, const MpfrClass&  b)               // Blomquist 24.05.2010
    {
       MpfrClass v(0);
       mpfr_si_sub(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator - (const mpfr_t& a, const MpfrClass& b)
    {
       MpfrClass v(0);
       mpfr_sub(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }



    MpfrClass& operator -= (MpfrClass& a, const MpfrClass& b)
    {
      a = a - b;
      return a;
    }

    MpfrClass& operator -= (MpfrClass& a, const double& b)                    // Blomquist 23.05.2010
    {
      a = a - b;
      return a;
    }

//    MpfrClass& operator -= (MpfrClass& a, const cxsc::real& b)            // Blomquist 23.05.2010
//    {
//      a = a - b;
//      return a;
//    }

    MpfrClass& operator -= (MpfrClass& a, const int b)                    // Blomquist 23.05.2010
    {
      a = a - b;
      return a;
    }

    MpfrClass& operator -= (MpfrClass& a, const mpfr_t& b)     // Blomquist 23.05.2010
    {
      a = a - b;
      return a;
    }


    // Multiplication  -----------------------------------------------

    MpfrClass operator * (const MpfrClass& a, const MpfrClass& b)
    {
      MpfrClass v(0);
      mpfr_mul(v.mpfr_rep, a.mpfr_rep, b.mpfr_rep, MpfrClass::GetCurrRndMode());
      return v;
    }

    MpfrClass operator * (const MpfrClass& a, const double& b)             // Blomquist 21.05.2010
    {
       MpfrClass v(0);
       mpfr_mul_d(v.mpfr_rep, a.mpfr_rep, b , MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator * (const MpfrClass& a, const cxsc::real& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_mul_d(v.mpfr_rep, a.mpfr_rep, _double(b), MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator * (const MpfrClass& a, const int b)                // Blomquist 21.05.2010
    {
       MpfrClass v(0);
       mpfr_mul_si(v.mpfr_rep, a.mpfr_rep, b , MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator * (const MpfrClass& a, const mpfr_t& b)
    {
       MpfrClass v(0);
       mpfr_mul(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator * (const double& a, const MpfrClass& b)             // Blomquist 21.05.2010
    {
       MpfrClass v(0);
       mpfr_mul_d(v.mpfr_rep, b.mpfr_rep, a , MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator * (const cxsc::real& a, const MpfrClass& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_mul_d(v.mpfr_rep, b.mpfr_rep, _double(a), MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator * (const int a, const MpfrClass& b)                // Blomquist 21.05.2010
    {
       MpfrClass v(0);
       mpfr_mul_si(v.mpfr_rep, b.mpfr_rep, a , MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator * (const mpfr_t& a, const MpfrClass& b)            // Blomquist 21.05.2010
    {
       MpfrClass v(0);
       mpfr_mul(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }


    MpfrClass& operator *= (MpfrClass& a, const MpfrClass& b)
    {
      a = a * b;
      return a;
    }

    MpfrClass& operator *= (MpfrClass& a, const double& b)                    // Blomquist 23.05.2010
    {
      a = a * b;
      return a;
    }

//    MpfrClass& operator *= (MpfrClass& a, const cxsc::real& b)                // Blomquist 23.05.2010
//    {
//      a = a * b;
//      return a;
//    }

    MpfrClass& operator *= (MpfrClass& a, const int b)              // Blomquist 23.05.2010
    {
      a = a * b;
      return a;
    }

    MpfrClass& operator *= (MpfrClass& a, const mpfr_t& b)     // Blomquist 23.05.2010
    {
      a = a * b;
      return a;
    }

    // Division
    MpfrClass operator / (const MpfrClass& a, const MpfrClass& b)
    {
      MpfrClass v(0);
      mpfr_div(v.mpfr_rep, a.mpfr_rep, b.mpfr_rep, MpfrClass::GetCurrRndMode());
      return v;
    }

    MpfrClass operator / (const MpfrClass& a, const double& b)             // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_div_d(v.mpfr_rep, a.mpfr_rep, b , MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator / (const MpfrClass& a, const cxsc::real& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_div_d(v.mpfr_rep, a.mpfr_rep, _double(b), MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator / (const MpfrClass& a, const int b)                // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_div_si(v.mpfr_rep, a.mpfr_rep, b , MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator / (const MpfrClass& a, const mpfr_t& b)            // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_div(v.mpfr_rep, a.mpfr_rep, b, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator / (const double& a, const MpfrClass& b)             // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_d_div(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }

//    MpfrClass operator / (const cxsc::real& a, const MpfrClass& b)             // Blomquist 23.05.2010
//    {
//       MpfrClass v(0);
//       mpfr_d_div(v.mpfr_rep, _double(a), b.mpfr_rep, MpfrClass::GetCurrRndMode());
//       return v;
//    }

    MpfrClass operator / (const int a, const MpfrClass& b)                // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_si_div(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }

    MpfrClass operator / (const mpfr_t& a, const MpfrClass& b)            // Blomquist 22.05.2010
    {
       MpfrClass v(0);
       mpfr_div(v.mpfr_rep, a, b.mpfr_rep, MpfrClass::GetCurrRndMode());
       return v;
    }


    MpfrClass& operator /=(MpfrClass& a, const MpfrClass& b)
    {
      a = a / b;
      return a;
    }

    MpfrClass& operator /=(MpfrClass& a, const double& b)                    // Blomquist 23.05.2010
    {
      a = a / b;
      return a;
    }

//    MpfrClass& operator /=(MpfrClass& a, const cxsc::real& b)                // Blomquist 23.05.2010
//    {
//      a = a / b;
//      return a;
//    }

    MpfrClass& operator /=(MpfrClass& a, const int b)              // Blomquist 23.05.2010
    {
      a = a / b;
      return a;
    }

    MpfrClass& operator /=(MpfrClass& a, const mpfr_t& b)     // Blomquist 23.05.2010
    {
      a = a / b;
      return a;
    }


    /* Abfragen */

    bool isZero(const MpfrClass& r){
        return (mpfr_zero_p(r.mpfr_rep) != 0);  // Blomquist 21.05.2010
    }

    bool isInf(const MpfrClass& r){
        return (mpfr_inf_p(r.mpfr_rep) != 0);
    }

    bool isNan(const MpfrClass& r){
        return (mpfr_nan_p(r.mpfr_rep) != 0);
    }

    bool isNumber(const MpfrClass& r){
        return (mpfr_number_p(r.mpfr_rep) != 0);
    }

    bool isNeg(const MpfrClass& r){
        return (mpfr_sgn(r.mpfr_rep) < 0);
    }

    bool isPos(const MpfrClass& r)  // Blomquist 25.04.2010
    {  // Blomquist 25.04.2010
        return (mpfr_sgn(r.mpfr_rep) > 0);
    }

    bool isInteger(const MpfrClass& r)  // Blomquist 21.07.2010
    {
        return (mpfr_integer_p(r.mpfr_rep) != 0);
    }

    bool isEven(const MpfrClass& r)     // Blomquist 22.07.2010
    // Prueft, ob r ein gerader Integer-Wert ist
    {
      MpfrClass x(r), y(r);

      times2pown(x,-1,RoundUp); // Division durch 2 mit Aufrundung
      times2pown(y,-1,RoundDown); // Division durch 2 mit Abrundung

      return (x == y && isInteger(x) );
    }

    bool isOdd (const MpfrClass& r)
    // Prueft, ob r ein ungerader Integer-Wert ist
    {
      return ( isInteger(r) && !isEven(r) );
    }

    /*Vergleichs Funktionen*/

    int compare_equal (const MpfrClass& v, const MpfrClass& w)            // Blomquist 24.05.2010
    {
      return mpfr_equal_p(v.mpfr_rep, w.mpfr_rep);
    }

    int compare_less (const MpfrClass& v, const MpfrClass& w)             // Blomquist 24.05.2010
    {
      return mpfr_less_p(v.mpfr_rep, w.mpfr_rep);
    }

    int compare_lessequal (const MpfrClass& v, const MpfrClass& w)        // Blomquist 24.05.2010
    {
      return mpfr_lessequal_p(v.mpfr_rep, w.mpfr_rep);
    }

    int compare_greater (const MpfrClass& v, const MpfrClass& w)          // Blomquist 24.05.2010
    {
      return mpfr_greater_p(v.mpfr_rep, w.mpfr_rep);
    }

    int compare_greaterequal (const MpfrClass& v, const MpfrClass& w)     // Blomquist 24.05.2010
    {
      return mpfr_greaterequal_p(v.mpfr_rep, w.mpfr_rep);
    }

    bool operator == (const MpfrClass& v, const MpfrClass& w)             // Blomquist, 24.05.2010
    {
      return (compare_equal(v,w) != 0);
    }

    bool operator == (const double& x, const MpfrClass& w)                // blomquist 24.05.2010
    {
      return (compare_equal(double2Mpfr(x),w) != 0); // Funktioniert und vermeidet v = double2Mpfr(x);
    }

//    bool operator == (const cxsc::real& x, const MpfrClass& w)            // blomquist 24.05.2010
//    {
//      return (compare_equal(real2Mpfr(x),w) != 0);
//    }

    bool operator == (const int x, const MpfrClass& w)
    {
      return (compare_equal(int2Mpfr(x),w) != 0);
    }

    bool operator == (const MpfrClass& v, const double& x) // Blomquist 24.09.2010
    {
      return (compare_equal(v,double2Mpfr(x)) != 0);
    }

//    bool operator == (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_equal(v,real2Mpfr(x)) != 0);
//    }

    bool operator == (const MpfrClass& v, const int x)
    {
      return (compare_equal(v,int2Mpfr(x)) != 0);
    }

    bool operator != (const MpfrClass& v, const MpfrClass& w)   // Blomquist, 24.05.2010
    {
      return (compare_equal(v,w) == 0);
    }

    bool operator != (const double& x, const MpfrClass& w)
    {
      return (compare_equal(double2Mpfr(x),w) == 0);
    }

//    bool operator != (const cxsc::real& x, const MpfrClass& w)
//    {
//      return (compare_equal(real2Mpfr(x),w) == 0);
//    }

    bool operator != (const int x, const MpfrClass& w)
    {
      return (compare_equal(int2Mpfr(x),w) == 0);
    }

    bool operator != (const MpfrClass& v, const double& x)
    {
      return (compare_equal(v,double2Mpfr(x)) == 0);
    }

//    bool operator != (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_equal(v,real2Mpfr(x)) == 0);
//    }

    bool operator != (const MpfrClass& v, const int x)
    {
      return (compare_equal(v,int2Mpfr(x)) == 0);
    }

    bool operator < (const MpfrClass& v, const MpfrClass& w)             // Blomquist 24.05.2010
    {
      return (compare_less(v,w) != 0);
    }

    bool operator < (const double& x, const MpfrClass& w)
    {
      return (compare_less(double2Mpfr(x),w) != 0);
    }

//    bool operator < (const cxsc::real& x, const MpfrClass& w)
//    {
//      return (compare_less(real2Mpfr(x),w) != 0);
//    }

    bool operator <  (const int x, const MpfrClass& w)
    {
      return (compare_less(int2Mpfr(x),w) != 0);
    }

    bool operator <  (const MpfrClass& v, const double& x)
    {
      return (compare_less(v,double2Mpfr(x)) != 0);
    }

//    bool operator <  (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_less(v,real2Mpfr(x)) != 0);
//    }

    bool operator <  (const MpfrClass& v, const int x)
    {
      return (compare_less(v,int2Mpfr(x)) != 0);
    }

    bool operator <= (const MpfrClass& v, const MpfrClass& w)
    {
      return (compare_lessequal(v,w) != 0);
    }

    bool operator <= (const double& x, const MpfrClass& w)
    {
      return (compare_lessequal(double2Mpfr(x),w) != 0);
    }

//    bool operator <= (const cxsc::real& x, const MpfrClass& w)
//    {
//      return (compare_lessequal(real2Mpfr(x),w) != 0);
//    }

    bool operator <= (const int x, const MpfrClass& w)
    {
      return (compare_lessequal(int2Mpfr(x),w) != 0);
    }

    bool operator <= (const MpfrClass& v, const double& x)
    {
      return (compare_lessequal(v,double2Mpfr(x)) != 0);
    }

//    bool operator <= (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_lessequal(v,real2Mpfr(x)) != 0);
//    }

    bool operator <= (const MpfrClass& v, const int x)
    {
      return (compare_lessequal(v,int2Mpfr(x)) != 0);
    }

    bool operator >  (const MpfrClass& v, const MpfrClass& w)
    {
      return (compare_greater(v,w) != 0);
    }

    bool operator >  (const double& x, const MpfrClass& w)
    {
      return (compare_greater(double2Mpfr(x),w) != 0);
    }

//    bool operator >  (const cxsc::real& x, const MpfrClass& w)
//    {
//      return (compare_greater(real2Mpfr(x),w) != 0);
//    }

    bool operator >  (const int x, const MpfrClass& w)
    {
      return (compare_greater(int2Mpfr(x),w) != 0);
    }

    bool operator >  (const MpfrClass& v, const double& x)
    {
      return (compare_greater(v,double2Mpfr(x)) != 0);
    }

//    bool operator >  (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_greater(v,real2Mpfr(x)) != 0);
//    }

    bool operator >  (const MpfrClass& v, const int x)
    {
      return (compare_greater(v,int2Mpfr(x)) != 0);
    }

    bool operator >= (const MpfrClass& v, const MpfrClass& w)
    {
      return (compare_greaterequal(v,w) != 0);
    }

    bool operator >= (const double& x, const MpfrClass& w)
    {
      return (compare_greaterequal(double2Mpfr(x),w) != 0);
    }

//    bool operator >= (const cxsc::real& x, const MpfrClass& w)
//    {
//      return (compare_greaterequal(real2Mpfr(x),w) != 0);
//    }

    bool operator >= (const int x, const MpfrClass& w)
    {
      return (compare_greaterequal(int2Mpfr(x),w) != 0);
    }

    bool operator >= (const MpfrClass& v, const double& x)
    {
      return (compare_greaterequal(v,double2Mpfr(x)) != 0);
    }

//    bool operator >= (const MpfrClass& v, const cxsc::real& x)
//    {
//      return (compare_greaterequal(v,real2Mpfr(x)) != 0);
//    }

    bool operator >= (const MpfrClass& v, const int x)
    {
      return (compare_greaterequal(v,int2Mpfr(x)) != 0);
    }

    MpfrClass min (const MpfrClass& a, const MpfrClass& b)
    // Die Praezision des min-Ergebnisses ist die Praezision des
    // zurückgegebenen kleinsten Operanden, wobei sich diese Praezision
    // von der Current-Precision durchaus unterscheiden kann!
    // Das Minimum wird also rundungsfehlerfrei zurückgegebenen.
    {
      return (a <= b)? a : b;
    }

    MpfrClass max (const MpfrClass& a, const MpfrClass& b)
    // Die Praezision des max-Ergebnisses ist die Praezision des
    // zurückgegebenen groessten Operanden, wobei sich diese Praezision
    // von der Current-Precision durchaus unterscheiden kann!
    // Das Maximum wird also rundungsfehlerfrei zurückgegebenen.
    {
      return (a >= b)? a : b;
    }

    MpfrClass minfloat (PrecisionType prec)
    {
      long int emin = mpfr_get_emin ();
      MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
      mpfr_t x;
      mpfr_init2(x,prec);
      // Berechnung der kleinsten positiven mpfr-Zahl,
      // definiert durch 0.5*2^ (emin) = 0.5 * 2^( -1073741823);
      mpfr_set_d (x, 0.5, RoundNearest);  // x = 0.5
      mpfr_mul_2si (res.mpfr_rep, x, emin, RoundNearest);
      mpfr_clear(x);

      return res;
    }

    MpfrClass MaxFloat (PrecisionType prec)
    {
      long int emax = mpfr_get_emax ();
      MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), prec);
      mpfr_t x;
      mpfr_init2(x,prec);
      // Berechnung der groessten (positiven) mpfr-Zahl,
      // definiert durch (1-epsilon) * 2^( +1073741823);
      mpfr_set_d (x, 1.0, RoundNearest);
      mpfr_nextbelow (x); // x = 1-epsilon(prec);
      mpfr_mul_2si (res.mpfr_rep, x, emax, RoundNearest);
      mpfr_clear(x);

      return res;
    }

    MpfrClass pred (const MpfrClass& x)
    {
      MpfrClass res(x, RoundNearest, x.GetPrecision());  // res = x, EXAKT!
      mpfr_nextbelow (res.mpfr_rep);
      return res;
    }

    MpfrClass succ (const MpfrClass& x)
    // Liefert den Nachfolger von x in gleicher Praezision
    {
      MpfrClass res(x, RoundNearest, x.GetPrecision());  // res = x, EXAKT!
      mpfr_nextabove (res.mpfr_rep);
      return res;
    }

    MpfrClass reci (const MpfrClass& r, RoundingMode rnd)  // Blomquist, 02.05.2010
    // Calculating 1/r;
    {
      MpfrClass res(0);
      mpfr_ui_div(res.mpfr_rep, 1, r.mpfr_rep, rnd);

      return res;
    }

    void times2pown (MpfrClass& r, const long int n, RoundingMode rnd)          // Blomquist, 02.05.2010
    // Multiplication of r with 2^n, without changing the precision of r;
    {
      mpfr_mul_2si (r.mpfr_rep, r.mpfr_rep, n, rnd);
    }

    MpfrClass string2Mpfr (const std::string& v, RoundingMode rnd, PrecisionType prec)
    {
       MpfrClass res(v, rnd, prec);
       return res;
    }

    void initialization (gmp_randstate_t state)
    {
      mpz_t zseed;
      const char seed[] = "SPMf2e3u9rfwFzXtHhmM45nNPej1dGbpsKmpsFzs2TLZ4XvJur4ITPIOgCn8rRKkEKvVKCJRorbTVIeq3N3jBqrvfsTB67MK";

      gmp_randinit_default(state);
      mpz_init(zseed);
      mpz_set_str (zseed, seed, 62);
      gmp_randseed(state, zseed);
      srand(mpz_get_ui(zseed));
      mpz_clear(zseed);
    }

    // The function void random(...) delivers a MpfrClass random number r in [0,1]
    // by the following instructions inside a function, for example in: int main(void);
    // 1.   gmp_randstate_t state;  (Declaration of variable state)
    // 2.   initialization (state); (Initialization of state)
    // 3.   MpfrClass r;            (Declaration of class object r)
    // 4.   random (r, state);      (Function call delivers the first random number r)
    // 5.   random (r, state);      (Function call delivers the second random number r) ...
    void random (MpfrClass& r, gmp_randstate_t state)
    {
      mpfr_urandomb (r.mpfr_rep, state);
    }

    MpfrClass abs (const MpfrClass& r, RoundingMode rnd, PrecisionType prec)
    {
      MpfrClass res(0, MpfrClass::GetCurrRndMode(), prec);
      mpfr_abs (res.mpfr_rep, r.mpfr_rep, rnd);
      return res;
    }

    MpfrClass agm (const MpfrClass& r1, const MpfrClass& r2, RoundingMode rnd)
    {
        MpfrClass res(0); // res mit Current-Precision
        mpfr_agm(res.mpfr_rep, r1.mpfr_rep, r2.mpfr_rep, rnd);
        return res;
    }

    MpfrClass sqr (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_sqr(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass sqrt (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_sqrt(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass mant (const MpfrClass& r)
    // Calculating the exact mantissa of r with the precision of r;
    // r = 0 ---> 0;  NaN ---> NaN;  +Inf ---> +Inf;  -Inf ---> -Inf,
    // otherwise it holds:    0.5 <= |mantissa(r)| < 1;
    {
      MpfrClass res(r, RoundNearest, r.GetPrecision());
      if (isNumber(r) && r != 0)
        times2pown(res, -expo(r));
      return res;
    }

    long int expo (const MpfrClass& x)
    // Calculating the exponent to base 2, assuming the mantissa
    // in [0.5,+1). The calculated exponent is printed in decimals.
    // expo(0)    = -9223372036854775807
    // expo(NaN)  = -9223372036854775806
    // expo(+inf) = -9223372036854775805
    // expo(-inf) = -9223372036854775805
    {
      long int k;
      k = mpfr_get_exp(x.mpfr_rep);
      return k;
    }

    MpfrClass comp (const MpfrClass& x, const long int k)
    {
//      int p;

      MpfrClass res(x, RoundNearest, x.GetPrecision());
      if (isNumber(x))
      {
        if (mant(x)!=x)
          set_nan(res);
        else
        {
          if (!isZero(res))
          {
            if (mpfr_set_exp(res.GetValue(), k) != 0)
              set_nan(res);
          }
        }
      }
      else set_nan(res);
      return res;
    }

    int sign(const MpfrClass& x)                                          // Blomquist 05.07.2010
    {
      // sign(+1)  = +1;  sign(-1)   = -1;   sign(0)    =  0;
      // sign(NaN) = 0;   sign(+inf) = +1;   sign(-inf) = -1;
      return mpfr_sgn(x.mpfr_rep);
    }

    void prod_H1(MpfrClass& r, long int& k,
                 const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
    // r*2^k = x*y;  |r| in [0.5,2);
    // r = 0, r = NaN, r = +inf,  r = -inf  --->   k = 0;
    {
      k = 0;
      if ( isNumber(x) && isNumber(y) )
        if ( sign(x)*sign(y) != 0)
           k = expo(x) + expo(y) -1;
      r.SetPrecision( MpfrClass::GetCurrPrecision() );
      mpfr_mul(r.mpfr_rep, mant(x).mpfr_rep, mant(y).mpfr_rep, rnd);
      times2pown(r, 1, rnd);  // 2
      // Es gilt:  |r| in [0.5,2)
    }

    void Prod_H1(MpfrClass& r, long int& k,
                 const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
    // r*2^k = x*y;  MaxFloat()/32 <= |r| < MaxFloat()/8;
    // r = 0, r = NaN, r = +inf,  r = -inf  --->   k = 0;
    {
      const long int p = 1073741820;
      k = 0;
      if ( isNumber(x) && isNumber(y) )
        if ( sign(x)*sign(y) != 0)
           k = expo(x) + expo(y) - p;
      r.SetPrecision( MpfrClass::GetCurrPrecision() ); // Setzt die Praezision von r auf die Current-Precision
      mpfr_mul(r.mpfr_rep, mant(x).mpfr_rep, mant(y).mpfr_rep, rnd);
      times2pown(r, p, rnd);
    }

    void sum_k_H1(MpfrClass& r, long int& k,
                  const MpfrClass& x, long int& k_x,
                  const MpfrClass& y, long int& k_y, RoundingMode rnd)
    // r*2^k = x*2^k_x + y*2^k_y;
    // Voraussetzung: k_x >= k_y, falls:  x,y != 0 and isNumber(x,y) = True;
    {
      PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision();
      if (x.GetPrecision() >= y.GetPrecision())
        prec =  x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);

      MpfrClass Y(y);  // Y = y, EXAKT!  Y wird auf die neue Current-Precision gesetzt;
      r = 0;  // r wird dadurch auf die neue Current-Precision gesetzt;
      if ( isNumber(x) && isNumber(y) )
      {
         if (sign(x) == 0)
         {
            r = y;
            k = k_y;
         }
         else
           if (sign(y) == 0)
           {
              r = x;
              k = k_x;
           }
           else // x,y != 0
           // Jetzt Skalierung von y = Y:
           {
             k = k_x;
             times2pown(Y, k_y-k_x, rnd); // Hier kann wegen (k_y-k_x < 0) eine echte Rundung auftreten!
             mpfr_add(r.mpfr_rep, x.mpfr_rep, Y.mpfr_rep, rnd);
           }
      }
      else
      {
        k = 0;
        mpfr_add(r.mpfr_rep, x.mpfr_rep, y.mpfr_rep, rnd);
      }
      r.RoundPrecision(prec_old, rnd);       // (Moegliche zweite) Rundung zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
    } // sum_k_H1

    void scal_prod_k(MpfrClass& r, long int& k,
                    const MpfrClass& a, const MpfrClass& b,
                    const MpfrClass& c, const MpfrClass& d, RoundingMode rnd)
    // r*2^k = a*b + c*d;                                                 Blomquist 06.07.2010
    // Rechnung in einfacher Genauigkeit, z.B fuer x^2 + y^2, wo keine Auslöschung auftritt!
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "scal_prod_k(...), Error: RoundToZero and RoundFromZero not implemented yet." << std::endl;
        exit (1);
      }
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = a.GetPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      if (c.GetPrecision() > prec) prec = c.GetPrecision();
      if (d.GetPrecision() > prec) prec = d.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);

      MpfrClass ab(0), cd(0);
      long int k_ab, k_cd;

      prod_H1(ab, k_ab, a, b, rnd);
      prod_H1(cd, k_cd, c, d, rnd);

      if (k_cd > k_ab)
      {
        mpfr_swap (ab.mpfr_rep, cd.mpfr_rep);
        k = k_ab;  k_ab = k_cd;  k_cd = k;
      }

      sum_k_H1(r, k, ab, k_ab, cd, k_cd, rnd);
      r.RoundPrecision(prec_old, rnd);        // Rundet r auf die alte Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);  // Alte Current-Precision wiederherstellen
    } // scal_prod_k

    void Scal_prod_k(MpfrClass& r, long int& k,
                    const MpfrClass& a, const MpfrClass& b,
                    const MpfrClass& c, const MpfrClass& d, RoundingMode rnd)
    // r*2^k = a*b + c*d;                               Blomquist 06.07.2010
    // Rechnung in mehr als doppelter Genauigkeit, um Auslöschung möglichst zu vermeiden
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "Scal_prod_k(...), Error: RoundToZero and RoundFromZero not yet implemented!" << std::endl;
        exit (1);
      }
      PrecisionType prec     = a.GetPrecision(),
                    prec_old = MpfrClass::GetCurrPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      if (c.GetPrecision() > prec) prec = c.GetPrecision();
      if (d.GetPrecision() > prec) prec = d.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      prec = 2*prec + 15;
      MpfrClass::SetCurrPrecision(prec); // Setzt die neue Current-Precision auf mehr
      // als die doppelte maximale Operanden-Praezision, um Ausloeschung zu verhindern.

      MpfrClass ab(0), cd(0);  // Initialisiert mit neuer Current-Precision
      long int k_ab, k_cd;

      Prod_H1(ab, k_ab, a, b, rnd); // Beide Produkte |ab| und |cd| liegen
      Prod_H1(cd, k_cd, c, d, rnd); // nur knapp unter MaxFloat() !
      if (k_cd > k_ab)
      {
        mpfr_swap (ab.mpfr_rep, cd.mpfr_rep);
        k = k_ab;  k_ab = k_cd;  k_cd = k;
      }  // Es gilt:  k_ab >= k_cd, wie in sum_k_H1(...);  vorausgesetzt
      sum_k_H1(r, k, ab, k_ab, cd, k_cd, rnd); // Setzt r auf die neue Current-Precision
      r.RoundPrecision(prec_old, rnd);         // Rundet r auf die alte Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);   // Alte Current-Precision wiederherstellen
    }

    void scal_prod(MpfrClass& r,
                  const MpfrClass& a, const MpfrClass& b,
                  const MpfrClass& c, const MpfrClass& d, RoundingMode rnd)
    // r = a*b + c*d;  Without any internal over- and underflow
    // RoundToZero and RoundFromZero is not implemented and causes an exit(1).
    {
       long int k;
       Scal_prod_k(r, k, a, b, c, d, rnd);  // r*2^k = a*b + c*d;
       // Without cancellation effects |r| lies near MaxFloat.
       // With cancellation effects |r| is proportionately smaller.
       // Precision of r is set to the Current-Precision
       times2pown(r, k, rnd); // Only here over- or underflow can be generated!
    }

   MpfrClass Compl_Re (const MpfrClass& a, const MpfrClass& b,
                       const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
   // Calculating the real part of (a+ib) / (x+iy)
   {
      long int k_Z, k_N;
      RoundingMode RND;
      PrecisionType prec     = a.GetPrecision(),
                    prec_old = MpfrClass::GetCurrPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      if (x.GetPrecision() > prec) prec = x.GetPrecision();
      if (y.GetPrecision() > prec) prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);

      MpfrClass Zae(0), Nen(0);
      Scal_prod_k (Zae, k_Z, a, x, b, y, rnd);

      if (rnd == RoundUp)
      {
         if (sign(Zae) >= 0)
           RND = RoundDown;
         else RND = RoundUp;
         scal_prod_k (Nen, k_N, x, x, y, y, RND);
      }
      else
      {
        if (rnd == RoundDown)
        {
           if (sign(Zae) >= 0)
             RND = RoundUp;
           else RND = RoundDown;
           scal_prod_k (Nen, k_N, x, x, y, y, RND);
        }
        else scal_prod_k (Nen, k_N, x, x, y, y, rnd);
      }
      // Jetzt folgt die Division:  Zae / Nen
      mpfr_div(Zae.mpfr_rep, Zae.mpfr_rep, Nen.mpfr_rep, rnd);
      times2pown(Zae, k_Z-k_N, rnd);
      Zae.RoundPrecision(prec_old, rnd);      // Rundet Zae auf die alte Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);  // Alte Current-Precision wiederherstellen
      return Zae;
   }

   MpfrClass Compl_Im (const MpfrClass& a, const MpfrClass& b,
                       const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
   // Calculating the imaginary part of (a+ib) / (x+iy)
   {
      long int k_Z, k_N;
      RoundingMode RND;
      PrecisionType prec     = a.GetPrecision(),
                    prec_old = MpfrClass::GetCurrPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      if (x.GetPrecision() > prec) prec = x.GetPrecision();
      if (y.GetPrecision() > prec) prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass Zae(0), Nen(0);

      Scal_prod_k (Zae, k_Z, b, x, -a, y, rnd);
      if (rnd == RoundUp)
      {
         if (sign(Zae) >= 0)
           RND = RoundDown;
         else RND = RoundUp;
         scal_prod_k (Nen, k_N, x, x, y, y, RND);
      }
      else
      {
        if (rnd == RoundDown)
        {
           if (sign(Zae) >= 0)
             RND = RoundUp;
           else RND = RoundDown;
           scal_prod_k (Nen, k_N, x, x, y, y, RND);
        }
        else scal_prod_k (Nen, k_N, x, x, y, y, rnd);
      }
      // Jetzt folgt die Division:  Zae / Nen
      mpfr_div(Zae.mpfr_rep, Zae.mpfr_rep, Nen.mpfr_rep, rnd);
      times2pown(Zae, k_Z-k_N, rnd);
      Zae.RoundPrecision(prec_old, rnd);      // Rundet Zae auf die alte Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);  // Alte Current-Precision wiederherstellen
      return Zae;
   }

  MpfrClass x2my2 (const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
  // Calculating x^2 - y^2 = (|x|-|y|)*(|x|+|y|);
  {
    if (rnd == RoundToZero || rnd == RoundFromZero)
    {
      std::cerr << "Error in x2my2():  RoundToZero and RoundFromZero are not yet implemented!" << std::endl;
      exit(1);
    }

    PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision();
    if (x.GetPrecision() >= y.GetPrecision())
      prec = x.GetPrecision();
    else prec = y.GetPrecision();
    if (prec < prec_old) prec = prec_old;
    MpfrClass::SetCurrPrecision(prec);

    bool scaled = false;
    MpfrClass X(0.0, rnd, x.GetPrecision()),
              Y(0.0, rnd, y.GetPrecision()), d(0), s(0);
    mpfr_abs (X.mpfr_rep, x.mpfr_rep, RoundNearest);  // X = |x|
    mpfr_abs (Y.mpfr_rep, y.mpfr_rep, RoundNearest);  // Y = |y|

    if (rnd == RoundUp)
    {
      mpfr_sub(d.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, rnd); // d = |x| - |y| = X - Y;
      if (d<0)
      {
        if (expo(X) >= expo(MaxFloat())-2)
        {
          scaled = true;
          times2pown(X,-2, RoundDown);
          times2pown(Y,-2, RoundDown);
        }
        mpfr_add(s.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, RoundDown);
      }
      else // d>=0
      {
        if (expo(X) >= expo(MaxFloat())-2)
        {
          scaled = true;
          times2pown(X,-2, RoundUp);
          times2pown(Y,-2, RoundUp);
        }
        mpfr_add(s.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, RoundUp);
      }
      mpfr_mul(s.mpfr_rep, d.mpfr_rep, s.mpfr_rep, rnd);
    }
    else
    {
      if (rnd == RoundDown)
      {
        mpfr_sub(d.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, rnd); // d = |x| - |y| = X - Y;
        if (d<0)
        {
          if (expo(X) >= expo(MaxFloat())-2)
          {
            scaled = true;
            times2pown(X,-2, RoundUp);
            times2pown(Y,-2, RoundUp);
          }
          mpfr_add(s.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, RoundUp);
        }
        else // d>=0
        {
          if (expo(X) >= expo(MaxFloat())-2)
          {
            scaled = true;
            times2pown(X,-2, RoundDown);
            times2pown(Y,-2, RoundDown);
          }
          mpfr_add(s.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, RoundDown);
        }
        mpfr_mul(s.mpfr_rep, d.mpfr_rep, s.mpfr_rep, rnd);
      }
      else // rnd = RoundNearest
      {
        mpfr_sub(d.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, rnd); // d = |x| - |y| = X - Y;
        if (expo(X) >= expo(MaxFloat())-2)
        {
          scaled = true;
          times2pown(X,-2, rnd);
          times2pown(Y,-2, rnd);
        }
        mpfr_add(s.mpfr_rep, X.mpfr_rep, Y.mpfr_rep, rnd);
        mpfr_mul(s.mpfr_rep, d.mpfr_rep, s.mpfr_rep, rnd);
      }
    }
    if (scaled)
      times2pown(s,2,rnd);
    s.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
    MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
    return s;
  }

  MpfrClass x2py2 (const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
  // Calculating x^2 + y^2;
  {
    PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision();
    if (x.GetPrecision() >= y.GetPrecision())
      prec =  x.GetPrecision();
    else prec = y.GetPrecision();
    if (prec < prec_old) prec = prec_old;
    MpfrClass::SetCurrPrecision(prec);

    MpfrClass x2(0);
    mpfr_sqr(x2.mpfr_rep, x.mpfr_rep, rnd);
    MpfrClass y2(0);
    mpfr_sqr(y2.mpfr_rep, y.mpfr_rep, rnd);
    mpfr_add(x2.mpfr_rep, x2.mpfr_rep, y2.mpfr_rep, rnd);
    x2.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
    MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
    return x2;
  }

  MpfrClass ln_cos (const MpfrClass& x, RoundingMode rnd)
  // Calculating ln( cos(x) ) = 0.5*ln( 1-sin^2(x) ), if cos(x)>0;
  {
    if (rnd == RoundToZero || rnd == RoundFromZero)
    {
      std::cerr << "Error in ln(cos(x)):  RoundToZero and RoundFromZero are not yet implemented!" << std::endl;
      exit(1);
    }
    PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                  prec     = x.MpfrClass::GetPrecision();
    if (prec < prec_old) prec = prec_old;
    MpfrClass::SetCurrPrecision(prec);
    MpfrClass res(0);
    mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundFromZero);
    if (res <= 0) // cos(x) <= 0:
    {
      set_nan(res);
      return res;
    }  // Fuer den exakten Funktionswert gilt jetzt:  cos(x) > 0:
    mpfr_cos(res.mpfr_rep, x.mpfr_rep, rnd);
    if (res<0.5) // cos(x) < 0.5
      mpfr_log(res.mpfr_rep, res.mpfr_rep, rnd);
    else
    { // cos(x) >= 0.5;  ln(cos(x)) = 0.5 * ln(1 + sin^2(x));
      mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundFromZero);
      if (rnd==RoundUp)
      {
        if (res < 0)
          mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundUp);
        else
          mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundDown);
        mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundDown);
      }
      else
      {
        if (rnd==RoundDown)
        {
          if (res < 0)
            mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundDown);
          else
            mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundUp);
          mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundUp);
        }
        else // RoundToNearest:
        {
          mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundNearest);
          mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundNearest);
        }
      }
      res = -res;
      mpfr_log1p(res.mpfr_rep, res.mpfr_rep, rnd);
      times2pown(res,-1, rnd);
    }
    res.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
    MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
    return res;
  }

  MpfrClass ln_sin (const MpfrClass& x, RoundingMode rnd)
  // Calculating ln( sin(x) ) = 0.5*ln( 1-cos^2(x) ), if sin(x)>0;
  {
    if (rnd == RoundToZero || rnd == RoundFromZero)
    {
      std::cerr << "Error in ln(sin(x)):  RoundToZero and RoundFromZero are not yet implemented!" << std::endl;
      exit(1);
    }
    PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                  prec     = x.MpfrClass::GetPrecision();
    if (prec < prec_old) prec = prec_old;
    MpfrClass::SetCurrPrecision(prec);
    MpfrClass res(0);
    mpfr_sin(res.mpfr_rep, x.mpfr_rep, RoundFromZero);
    // res: sin(x), gerundet weg von der Null;
    if (res <= 0) // sin(x) <= 0:
    {
      set_nan(res);
      return res;
    } // Fuer den exakten Funktionswert gilt jetzt:  sin(x) > 0:
    mpfr_sin(res.mpfr_rep, x.mpfr_rep, rnd);  // Neu
    if (res < 0.5)
      mpfr_log(res.mpfr_rep, res.mpfr_rep, rnd);
    else
    { // sin(x) >= 0.5;  ln(sin(x)) = 0.5 * ln(1 + cos^2(x));
      mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundFromZero); // res = cos(x)
      if (rnd==RoundUp)
      {
        if (res < 0)
          mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundUp);
        else
          mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundDown);
        mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundDown);
      }
      else
      {
        if (rnd==RoundDown) // rounding down
        {
          if (res<0)
            mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundDown);
          else
            mpfr_cos(res.mpfr_rep, x.mpfr_rep, RoundUp);
          mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundUp);
        }
        else // RoundToNearest:
        {
          mpfr_cos(res.mpfr_rep, x.mpfr_rep,   RoundNearest);
          mpfr_sqr(res.mpfr_rep, res.mpfr_rep, RoundNearest);
        }
      }
      res = -res;
      mpfr_log1p(res.mpfr_rep, res.mpfr_rep, rnd);
      times2pown(res,-1, rnd);
    }
    res.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
    MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
    return res;
  }

    MpfrClass sqrtp1m1 (const MpfrClass& x, RoundingMode rnd)
    // Calculating f(x) := sqrt(1+x)-1;  x >= -1;
    {
        long int One = 1;
        PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                      prec     = x.MpfrClass::GetPrecision();
        if (prec < prec_old) prec = prec_old;
        MpfrClass::SetCurrPrecision(prec);
        MpfrClass res(0);

        if (x < 1.0)
        { // f(x) = x / ( sqrt(1+x) + 1 )
	  if (x >= 0)
	  {
	    if (rnd == RoundUp)
	    {
	      mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, RoundDown);    // x+1
              mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, RoundDown);         // sqrt(x+1)
              mpfr_add_si(res.mpfr_rep, res.mpfr_rep, One, RoundDown);  // sqrt(x+1) + 1;
	    };

	    if (rnd == RoundDown || rnd == RoundToZero)
	    {
	      mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, RoundUp);    // x+1
              mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, RoundUp);         // sqrt(x+1)
              mpfr_add_si(res.mpfr_rep, res.mpfr_rep, One, RoundUp);  // sqrt(x+1) + 1;
	    };

	    if (rnd == RoundNearest)  // RoundNearest
	    {
	      mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, rnd);    // x+1
              mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, rnd);         // sqrt(x+1)
              mpfr_add_si(res.mpfr_rep, res.mpfr_rep, One, rnd);  // sqrt(x+1) + 1;
	    }
	  }
	  else
	  {  // x < 0 :
	      if (rnd == RoundToZero)
	      {
		mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, RoundUp);    // x+1
                mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, RoundUp);         // sqrt(x+1)
                mpfr_add_si(res.mpfr_rep, res.mpfr_rep, One, RoundUp);  // sqrt(x+1) + 1;
	      }
	      else
	      {
	        mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, rnd);    // x+1
                mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, rnd);         // sqrt(x+1)
                mpfr_add_si(res.mpfr_rep, res.mpfr_rep, One, rnd);  // sqrt(x+1) + 1;
	      }
	  }
	  mpfr_div(res.mpfr_rep, x.mpfr_rep, res.mpfr_rep, rnd);
        }
        else  // f(x) = sqrt(1+x) - 1;   x >= 1;
        {
	  if (rnd == RoundToZero)
	  {
	    mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, RoundDown);    // x+1
            mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, RoundDown);         // sqrt(x+1)
            mpfr_sub_si(res.mpfr_rep, res.mpfr_rep, One, RoundDown);  // sqrt(x+1) - 1;
	  }
	  else
	  {
            mpfr_add_si(res.mpfr_rep, x.mpfr_rep, One, rnd);    // x+1
            mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, rnd);         // sqrt(x+1)
            mpfr_sub_si(res.mpfr_rep, res.mpfr_rep, One, rnd);  // sqrt(x+1) - 1;
	    MpfrClass infinity(0.0);
	    set_inf(infinity,+1);      // infinity = +Intinity
	    if (res == infinity && x != infinity)         // it holds: sqrt(1+x)-1 < sqrt(x)
	      mpfr_sqrt(res.mpfr_rep, x.mpfr_rep, rnd);   // res = sqrt(x)
	  }
        }
        res.RoundPrecision(prec_old, rnd);      // Runden zur alten Current-Precision
        MpfrClass::SetCurrPrecision(prec_old);  // Wiederherstellen der alten Current-Precision
        return res;
    }

    MpfrClass sqrtx2m1 (const MpfrClass& x, RoundingMode rnd)  // Blomquist 25.06.2010
    // Calculating f(x) := sqrt(x^2 - 1);  |x| >= 1;
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      long int ex = expo(x), emax = mpfr_get_emax();
      MpfrClass absx(0); // OK
      mpfr_abs (absx.mpfr_rep, x.mpfr_rep, rnd);  // absx = |x|

      if (ex > emax/2 - 10)
      // |x| - 0.5 / (|x|-1/|x|) < sqrt(x^2 - 1) < |x| - 0.5/|x|;
      {
        if (rnd == RoundUp || rnd == RoundNearest || rnd == RoundFromZero)
        {
          mpfr_d_div(res.mpfr_rep, 0.5, absx.mpfr_rep, RoundDown);       // res = 0.5/|x|
          mpfr_sub(res.mpfr_rep, absx.mpfr_rep, res.mpfr_rep, RoundUp);  // res = |x| - 0.5/|x|
        }
        else // (rnd == RoundDown || rnd == RoundToZero)
        {
          mpfr_si_div(res.mpfr_rep, 1, absx.mpfr_rep, RoundUp);           // res = 1/|x| (roundup)
          mpfr_sub(res.mpfr_rep, absx.mpfr_rep, res.mpfr_rep, RoundDown); // res = |x| - 1/|x|;
          mpfr_d_div(res.mpfr_rep, 0.5, res.mpfr_rep, RoundUp);           // res = 0.5 / (|x| - 1/|x|);
          mpfr_sub(res.mpfr_rep, absx.mpfr_rep, res.mpfr_rep, RoundDown); // res = |x| - 0.5 / (|x| - 1/|x|);
        }
      }
      else // Normal calculation
      {
        mpfr_add_si(res.mpfr_rep, absx.mpfr_rep, 1, rnd);  // res  = |x|+1
        mpfr_sub_si(absx.mpfr_rep, absx.mpfr_rep, 1, rnd); // absx = |x|-1;
        mpfr_mul(res.mpfr_rep, res.mpfr_rep, absx.mpfr_rep, rnd); // res = (|x|+1)*(|x|-1)
        mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, rnd);
      }
      res.RoundPrecision(prec_old, rnd);      // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);  // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass sqrt1mx2 (const MpfrClass& x, RoundingMode rnd)             // Blomquist 26.06.2010
    // Calculating f(x) := sqrt(1-x^2) = sqrt( (1-x)(1+x) );  |x| <= 1;
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0), tmp(0);

      mpfr_si_sub(res.mpfr_rep, 1, x.mpfr_rep, rnd);            // res = 1-x >= 0;
      mpfr_add_si(tmp.mpfr_rep, x.mpfr_rep, 1, rnd);            // tmp = 1+x >= 0;
      mpfr_mul(res.mpfr_rep, res.mpfr_rep, tmp.mpfr_rep, rnd);  // res = (1-x)(1+x);
      mpfr_sqrt(res.mpfr_rep, res.mpfr_rep, rnd);               // res = sqrt( (1-x)(1+x) );
      if (res>1) res = 1;
      res.RoundPrecision(prec_old, rnd);      // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);  // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass sqrt1px2 (const MpfrClass& x , RoundingMode rnd)
    // Calculating sqrt(1+x^2);
    // The precision of res is the precision of x.
    {
      MpfrClass res(0);
      mpfr_t One;
      mpfr_init_set_d (One, 1.0, RoundNearest);

      mpfr_hypot(res.mpfr_rep, One, x.mpfr_rep, rnd);
      mpfr_clear(One);

      return res;
    }

    MpfrClass sqrt_n (unsigned long int n, RoundingMode rnd)
    // Calculating sqrt(n); n = 0,1,2, ....
    // The precision of res is the actual Current-Precision.
    {
        MpfrClass res(0);
        mpfr_sqrt_ui(res.mpfr_rep, n, rnd);

        return res;
    }

    MpfrClass cbrt (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_cbrt(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass sqrt (const MpfrClass& r, unsigned long int k, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_root(res.mpfr_rep, r.mpfr_rep, k, rnd);

        return res;
    }

    MpfrClass sqrt_r (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_rec_sqrt(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass exp (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_exp(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass expm1 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_expm1(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass expmx2 (const MpfrClass& x, RoundingMode rnd)
    // exp(-x^2)
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      if (rnd == RoundUp || rnd == RoundFromZero)
        mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundDown);
      else
      {
        if (rnd == RoundDown || rnd == RoundToZero)
          mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundUp);
        else mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundNearest);    // res = x^2
      }
      mpfr_neg(res.mpfr_rep, res.mpfr_rep, RoundNearest);         // res = -x^2
      mpfr_exp(res.mpfr_rep, res.mpfr_rep, rnd);
      res.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass expmx2m1 (const MpfrClass& x, RoundingMode rnd)
    // exp(-x^2) - 1;
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      if (rnd == RoundUp || rnd == RoundFromZero)
        mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundDown);
      else
      {
        if (rnd == RoundDown || rnd == RoundToZero)
          mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundUp);
        else mpfr_sqr(res.mpfr_rep, x.mpfr_rep, RoundNearest);    // res = x^2
      }
      mpfr_neg(res.mpfr_rep, res.mpfr_rep, RoundNearest);         // res = -x^2
      mpfr_expm1(res.mpfr_rep, res.mpfr_rep, rnd);
      res.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass expx2 (const MpfrClass& x, RoundingMode rnd)
    // exp(+x^2);
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      mpfr_sqr(res.mpfr_rep, x.mpfr_rep, rnd);    // res = x^2
      mpfr_exp(res.mpfr_rep, res.mpfr_rep, rnd);
      res.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass expx2m1 (const MpfrClass& x, RoundingMode rnd)
    // exp(+x^2) - 1;
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      mpfr_sqr(res.mpfr_rep, x.mpfr_rep, rnd);    // res = x^2
      mpfr_expm1(res.mpfr_rep, res.mpfr_rep, rnd);

      return res;
    }

    MpfrClass ln (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_log(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass log2 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_log2(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass log10 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_log10(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass lnp1 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_log1p(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass sin (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_sin(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass cos (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_cos(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    void sin_cos (MpfrClass& res_sin, MpfrClass& res_cos, const MpfrClass& r, RoundingMode rnd)
    {
        PrecisionType prec = MpfrClass::GetCurrPrecision();

        mpfr_init2(res_sin.mpfr_rep, prec);
        mpfr_init2(res_cos.mpfr_rep, prec);

        mpfr_sin_cos(res_sin.mpfr_rep, res_cos.mpfr_rep, r.mpfr_rep, rnd);
     }

    MpfrClass tan (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_tan(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass cot (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_cot(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass acos (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_acos(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass asin (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_asin(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }


    MpfrClass atan (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_atan(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass atan2 (const MpfrClass& y, const MpfrClass& x, RoundingMode rnd) // Blomquist 10.06.2010
    // atan2(y,x) = atan(y/x), falls x>0 und y,x endlich.
    // atan2(y,x) = sign(y) * (Pi - atan(|y/x|), falls x<0 und y,x endlich.
    //
    // atan2(0,0)       = 0;  Vorsicht!!
    // atan2(+1,0)      = Pi/2;
    // atan2(+Inf,0)    = Pi/2;
    // atan2(-1,0)      = -Pi/2;
    // atan2(-Inf,0)    = -Pi/2;
    // atan2(0,+1)      = 0;
    // atan2(0,+Inf)    = 0;
    // atan2(-1,+Inf)   = -0;
    // atan2(+1,+Inf)   = 0;
    // atan2(0,-1)      = Pi;
    // atan2(0,-Inf)    = Pi;
    // atan2(-1,-Inf)   = -Pi;
    // atan2(+1,-Inf)   = Pi;
    // atan2(+Inf,+Inf) = Pi/4;
    // atan2(-Inf,+Inf) = -Pi/4;
    // atan2(+Inf,-Inf) = 3*Pi/4;
    // atan2(-Inf,-Inf) = -3*Pi/4;
    // Ist y oder x NaN, so liefert atan2(y,x) stets NaN.
    // atan2(y,x) ist damit zur Implementierung der komplexen
    // Argumentfunktion für Intervallargumente des Real- und
    // Imaginär-Teils besonders geeignet, da die atan2(y,x)-Funktionswerte
    // je nach Bedarf mit rnd auf- oder abgerundet werden koennen.
    {
        MpfrClass res(0);
        mpfr_atan2(res.mpfr_rep, y.mpfr_rep, x.mpfr_rep, rnd);
        return res;
    }

    MpfrClass acot (const MpfrClass& x, RoundingMode rnd)
    {
      MpfrClass res(0), One(1);
      mpfr_atan2(res.mpfr_rep, One.mpfr_rep, x.mpfr_rep, rnd);

      return res;
    }

    MpfrClass cosh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_cosh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass sinh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_sinh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass tanh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_tanh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass coth (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_coth(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }


    MpfrClass asinh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_asinh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }


    MpfrClass acosh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_acosh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass acoshp1 (const MpfrClass& x , RoundingMode rnd)
    // ArcCosh(1+x);
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      if (x<0)
      {
        std::cerr << "Error in MpfrClass acoshp1(const MpfrClass& x, RoundingMode rnd): x >= 0 !" << std::endl;
        exit(1);
      }
      MpfrClass tmp1(0), tmp2(0);

      if (expo(x) >= 536870911)
      // ArcCosh(1+x) = ln(x) + ln( 1 + 1/x + sqrt(1+2/x) );
      {
        mpfr_ui_div (tmp1.mpfr_rep, 1, x.mpfr_rep, rnd);  // tmp1 = 1/x;
        tmp2 = tmp1; // tmp2 = 1/x;
        times2pown(tmp1, rnd);  // tmp1 = 2/x;
        mpfr_add_ui(tmp1.mpfr_rep, tmp1.mpfr_rep, 1, rnd); // tmp1 = 1+2/x
        mpfr_sqrt(tmp1.mpfr_rep, tmp1.mpfr_rep, rnd);      // tmp1 = sqrt( 1+2/x );
        mpfr_add(tmp1.mpfr_rep, tmp1.mpfr_rep, tmp2.mpfr_rep, rnd); // tmp1 = 1/x + sqrt( 1+2/x );
        mpfr_log1p(tmp1.mpfr_rep, tmp1.mpfr_rep, rnd);     // tmp1 = ln( 1 + 1/x + sqrt(1+2/x)
        mpfr_log(tmp2.mpfr_rep, x.mpfr_rep, rnd);          // tmp2 = ln(x);
        mpfr_add(tmp1.mpfr_rep, tmp1.mpfr_rep, tmp2.mpfr_rep, rnd); // tmp1 = ln(x) + ln( 1 + 1/x + sqrt(1+2/x) );
      }
      else
      // ArcCosh(1+x) = ln( 1 + x + sqrt( x*(2+x) ) );
      {
        mpfr_add_ui(tmp1.mpfr_rep, x.mpfr_rep, 2, rnd); // tmp1 = 2+x;
        mpfr_mul(tmp1.mpfr_rep, x.mpfr_rep, tmp1.mpfr_rep, rnd); // tmp1 = x*(2+x);
        mpfr_sqrt(tmp1.mpfr_rep, tmp1.mpfr_rep, rnd);   // tmp1 = sqrt( x*(2+x) );
        mpfr_add(tmp1.mpfr_rep, tmp1.mpfr_rep, x.mpfr_rep, rnd); // tmp1 = x + sqrt( x*(2+x) );
        mpfr_log1p(tmp1.mpfr_rep, tmp1.mpfr_rep, rnd);  // tmp1 = ln( 1 + x + sqrt( x*(2+x) ) );
      }
      tmp1.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
      return tmp1;
    }

    MpfrClass atanh (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_atanh(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass acoth (const MpfrClass& x, RoundingMode rnd)
    // acoth(x) = atanh( 1/x ); Blomquist 29.04.2010;
    {
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = x.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass y(0); // Initialisiert y mit 0 in der neuen Current-Precision prec;
      if ( abs(x)<1 ) set_nan(y);
      else y = atanh(reci(x,rnd),rnd);       // Beachte: atanh(t) ist monoton wachsend für: -1<t<+1;

      y.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
      return y;
    }

   MpfrClass csc (const MpfrClass& x, RoundingMode rnd)  //  1/sin
   {
     MpfrClass res(0);
     mpfr_csc(res.mpfr_rep, x.mpfr_rep, rnd);
     return res;
   }

   MpfrClass sec (const MpfrClass& x, RoundingMode rnd)  //  1/cos
   {
     MpfrClass res(0);
     mpfr_sec(res.mpfr_rep, x.mpfr_rep, rnd);
     return res;
   }

   MpfrClass sech (const MpfrClass& x, RoundingMode rnd)  //  1/cosh
   {
     MpfrClass res(0);
     mpfr_sech(res.mpfr_rep, x.mpfr_rep, rnd);
     return res;
   }

   MpfrClass csch (const MpfrClass& x, RoundingMode rnd)  //  1/sinh
   {
     MpfrClass res(0);
     mpfr_csch(res.mpfr_rep, x.mpfr_rep, rnd);
     return res;
   }

    MpfrClass power (const MpfrClass& r, const int e, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_pow_si(res.mpfr_rep, r.mpfr_rep, (long int)e, rnd);

        return res;
    }

    MpfrClass power (const MpfrClass& r, const long int e, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_pow_si(res.mpfr_rep, r.mpfr_rep, e, rnd);

        return res;
    }

    MpfrClass pow (const MpfrClass& r, const double& e, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_pow(res.mpfr_rep, r.mpfr_rep, (double2Mpfr(e)).mpfr_rep, rnd);

        return res;
    }

//    MpfrClass pow (const MpfrClass& r, const cxsc::real& e, RoundingMode rnd)
//    {
//        MpfrClass res(0);
//        mpfr_pow(res.mpfr_rep, r.mpfr_rep, (real2Mpfr(e)).mpfr_rep, rnd);
//
//        return res;
//    }

    MpfrClass pow (const MpfrClass& r, const MpfrClass& e, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_pow(res.mpfr_rep, r.mpfr_rep, e.mpfr_rep, rnd);

        return res;
    }

    MpfrClass exp2 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_exp2(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass exp10 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_exp10(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass gamma (const MpfrClass& r, RoundingMode rnd)
    {
      if (isInteger(r) && r<=0)
      {
        std::cerr << "Error in MpfrClass gamma(const MpfrClass& r, RoundingMode rnd): r is a pole!" << std::endl;
        exit(1);
      }
      MpfrClass res(0);
      mpfr_gamma(res.mpfr_rep, r.mpfr_rep, rnd);

      return res;
    }

    MpfrClass gamma_D (const MpfrClass& r, RoundingMode rnd)
    // Gamma'(x) = digamma(x) * gamma(x);
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "Error in gamma_D: Only RoundUp, RoundDown, RoundNearest are implemented" << std::endl;
        exit(1);
      }
      PrecisionType prec_old   = MpfrClass::GetCurrPrecision(),
                    prec       = r.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MPFI::MpfiClass u(0);
      MpfrClass L(0), res(0);

      L = digamma(r, RoundDown);
      u = MPFI::MpfiClass(L, succ(L));
      L = gamma(r, RoundDown);
      u = u * MPFI::MpfiClass(L, succ(L));

      if (rnd == RoundUp)
        res = Sup(u);
      else
        if (rnd == RoundDown)
          res = Inf(u);
        else
          res = mid(u);

      res.RoundPrecision(prec_old, rnd);             // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);         // Wiederherstellen der alten Current-Precision
      return res;
    }


    MpfrClass gamma_reci (const MpfrClass& r , RoundingMode rnd)           // Blomquist 23.07.2010
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "Error in gamma_reci: RoundToZero and RoundFromZero are not implemented!" << std::endl;
        exit(1);
      }
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = r.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MpfrClass res(0);
      if ( !(isInteger(r) && r<0) )
      {
        if (rnd==RoundUp)
          mpfr_gamma(res.mpfr_rep, r.mpfr_rep, RoundDown);
        else
        {
          if (rnd==RoundDown)
            mpfr_gamma(res.mpfr_rep, r.mpfr_rep, RoundUp);
          else // rnd == RoundNearest
            mpfr_gamma(res.mpfr_rep, r.mpfr_rep, rnd);
        }

        mpfr_si_div (res.mpfr_rep, 1, res.mpfr_rep, rnd);
      }
      res.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
      return res;
    }

    MPFI::MpfiClass reci_DH (const MpfrClass& r)
    // Berechnet Einschliessung von  -digamma(r)/gamma(r)  fuer
    // x <> 0, -1, -2, ...;
    {
      PrecisionType prec_old   = MpfrClass::GetCurrPrecision(),
                    prec_old_i = MPFI::MpfiClass::GetCurrPrecision(),
                    prec     = r.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      MPFI::MpfiClass::SetCurrPrecision(prec); // Realisiert auch Intervall-Rechnung mit Praezision prec

      MPFI::MpfiClass res(0), u(0);
      MpfrClass L, R;
      MpfrClass tmp(0.0), Null(0);
      if (abs(r) <= 2*succ(Null))
      // Der folgende Algorithmus verhindert vorzeitigen Überlauf bei
      // der digamma- und gamma-Funktion in der Umgebung von 0:
      {
        if (r == succ(Null) || r == 2*succ(Null))
        {
          tmp = 3*succ(Null);
          u = MPFI::MpfiClass(digamma(tmp, RoundDown));
          u = -u / MPFI::MpfiClass(gamma(tmp, RoundDown));
          L = 1;  R = Sup(u);
        }
        else // r = pred(0) oder r = 2*pred(0):
        {
          tmp = 3*pred(Null);
          u = MPFI::MpfiClass(digamma(tmp, RoundDown));
          u = -u / MPFI::MpfiClass(gamma(tmp,RoundDown));
          L = Inf(u);  R = 1;
        }
        res.SetInterval(L,R);
      }
      else // Normale Rechnung, d.h. kein Überlauf bei der digamma- und gamma-Funktion::
      {
        L = digamma(r,RoundDown);
        R = succ(L);
        u = MPFI::MpfiClass(L,R);
        L = gamma(r,RoundDown);
        R = succ(L);
        res = -u / MPFI::MpfiClass(L,R);
      }
      res.RoundPrecision(prec_old);                  // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);         // Wiederherstellen der alten Current-Precision
      MPFI::MpfiClass::SetCurrPrecision(prec_old_i); // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass gamma_reci_D (const MpfrClass& r , RoundingMode rnd)
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "Error in gamma_reci_D: RoundToZero and RoundFromZero are not implemented!" << std::endl;
        exit(1);
      }
      PrecisionType prec_old = MpfrClass::GetCurrPrecision(),
                    prec     = r.MpfrClass::GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);

      MpfrClass res(0);
      MPFI::MpfiClass u;
      if (isInteger(r) && r<=0)
      {
	int k;
        k = -mpfr_get_si (r.mpfr_rep, RoundNearest);
        if (-r != k)
        {
          std::cerr << "Error in gamma_reci_D(x): |x| too great!" << std::endl;
          exit(1);
        }
        u = MPFI::ifactorial((unsigned long int)k);
        if (isOdd(r)) u = -u;
      }
      else
        u = reci_DH (r);

      if (rnd == RoundNearest)
        res = mid(u);
      else
      {
        if (rnd == RoundUp)
          res = Sup(u);
        else res = Inf(u);
      }
      res.RoundPrecision(prec_old, rnd);       // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfrClass lngamma (const MpfrClass& r, RoundingMode rnd)
    {
      if (isInteger(r) && r<=0)
      {
        std::cerr << "Error in lngamma(const MpfrClass& r, RoundingMode rnd): r is a pole!" << std::endl;
        exit(1);
      }
      MpfrClass res(0);
      mpfr_lngamma(res.mpfr_rep, r.mpfr_rep, rnd);

      return res;
    }

    MpfrClass lgamma (const MpfrClass& r, int& k, RoundingMode rnd)
    // Calculating ln( |gamma(r)| );
    // An error is generated if r is a pole;
    // If gamma(r)>0  -->  k=+1;
    // If gamma(r)<0  -->  k=-1;
    {
      if (isInteger(r) && r<=0)
      {
        std::cerr << "Error in lgamma(const MpfrClass& r, int& k, RoundingMode rnd): r is a pole!" << std::endl;
        exit(1);
      }
      MpfrClass res(0);
      mpfr_lgamma (res.mpfr_rep, &k, r.mpfr_rep, rnd);

      return res;
    }

    MpfrClass digamma (const MpfrClass& r, RoundingMode rnd)
    {
      if (isInteger(r) && r<=0)
      {
        std::cerr << "Error in digamma(const MpfrClass& r, RoundingMode rnd): r is a pole!" << std::endl;
        exit(1);
      }
      MpfrClass res(0);
      mpfr_digamma(res.mpfr_rep, r.mpfr_rep, rnd);
      return res;
    }

    MpfrClass erf (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_erf(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass erfc (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_erfc(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }


    MpfrClass factorial (const unsigned long int n, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_fac_ui(res.mpfr_rep, n, rnd);

        return res;
    }

    MpfrClass sqrtx2y2 (const MpfrClass& r1, const MpfrClass& r2, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_hypot(res.mpfr_rep, r1.mpfr_rep, r2.mpfr_rep, rnd);

        return res;
    }


    MpfrClass ln_sqrtx2y2 (const MpfrClass& r1 , const MpfrClass& r2, RoundingMode rnd)
    // Calculating ln( sqrt(r1^2 + r2^2) );
    // r1=r2=0  --->   Error message
    {
      PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision();

      if (r1.GetPrecision() >= r2.GetPrecision())
        prec =  r1.GetPrecision();
      else prec = r2.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);

      MpfrClass res(0), ar1(0), ar2(0);
      long int ex1, ex2, k;

      ar1 = abs(r1);  ar2 = abs(r2);
      ex1 = expo(ar1);  ex2 = expo(ar2);
      if ( isZero(r1) && isZero(r2) )
      {
        std::cerr << "Error: MpfrClass ln_sqrtx2y2(x,y): x = y = 0" << std::endl;
        exit(1);
      }
      if (ex2>ex1)
      {
        k = ex1;  ex1 = ex2;  ex2 = k;
        res = ar1;  ar1 = ar2;  ar2 = res;
      }
      // |ar1| >= |ar2|
      if (ex1 > 1073741800)
      {
        mpfr_div (res.mpfr_rep, ar2.mpfr_rep, ar1.mpfr_rep, rnd);
        mpfr_sqr (res.mpfr_rep, res.mpfr_rep, rnd);   // res = (ar2/ar1)^2
        mpfr_log1p (res.mpfr_rep, res.mpfr_rep, rnd); // res = ln[1+(ar2/ar1)^2]
        times2pown(res,-1,rnd); // res = 0.5 * ln[1+(ar2/ar1)^2]
        mpfr_log(ar2.mpfr_rep, ar1.mpfr_rep, rnd); // ar2 = ln( ar1 )
        mpfr_add(res.mpfr_rep, ar2.mpfr_rep, res.mpfr_rep, rnd);
      }
      else
        res = ln( sqrtx2y2(ar1,ar2,rnd), rnd );

      res.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
      MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
      return res;
    }

    void ln_sqrt_S2 (MpfrClass& s, const MpfrClass& x , const MpfrClass& y , RoundingMode rnd)
    // Berechnet (1+x)^2 + y^2;
    {
      MpfrClass t;
      s = sqr(y,rnd); // res = y^2;
      if (rnd == RoundUp)
        if (x>=-1) // x+1 >= 0
	  mpfr_add_ui(t.mpfr_rep, x.mpfr_rep, 1, rnd); // t = 1+x;
	else // x+1 < 0
	  mpfr_add_ui(t.mpfr_rep, x.mpfr_rep, 1, RoundDown); // t = 1+x;
      else
      {
	if (rnd == RoundDown)
	  if (x>=-1) // x+1 >= 0
	    mpfr_add_ui(t.mpfr_rep, x.mpfr_rep, 1, rnd); // t = 1+x;
	  else // x+1 < 0
	    mpfr_add_ui(t.mpfr_rep, x.mpfr_rep, 1, RoundUp); // t = 1+x;
	else // rnd = RoundNearest
	  mpfr_add_ui(t.mpfr_rep, x.mpfr_rep, 1, rnd); // t = 1+x;
      }
      t = sqr(t,rnd); // t = (1+x)^2;
      mpfr_add(s.mpfr_rep, t.mpfr_rep, s.mpfr_rep, rnd); // res = (1+x)^2 + y^2
    }

    void ln_sqrt_S1 (MpfrClass& y2, MpfrClass& s, const MpfrClass& x , const MpfrClass& y , RoundingMode rnd)
    // Berechnet wird:  y2 = y^2  und  s = x*(2+x) + y^2
    {
      const long int k = -510000000;
      MpfrClass t;
      y2 = sqr(y,rnd);
      if ( expo(x)<k && expo(y)<k )
      {
	MPFI::MpfiClass z(y);
	z = (z/x)*z + x;
	z = (z+2)*x; // z: Inclusion of x*(2+x+(y/x)*y)
	if (rnd == RoundUp)
	  s = Sup(z);
	else
	{
	  if (rnd == RoundDown)
	    s = Inf(z);
	  else s = mid(z);
	}
      }
      else
      {
        if (rnd == RoundUp)
          mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, RoundDown);  // t = 2+x;
        else
        {
	  if (rnd == RoundDown)
	    mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, RoundUp);  // t = 2+x;
	  else // rnd = RoundNearest
	    mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, rnd);  // t = 2+x;
        }
        mpfr_mul(t.mpfr_rep, t.mpfr_rep, x.mpfr_rep,  rnd); // t = x*(2+x);
        mpfr_add(s.mpfr_rep, t.mpfr_rep, y2.mpfr_rep, rnd); // res = x*(2+x) + y^2
      }
    }

    void ln_sqrt_S1 (MpfrClass& s, const MpfrClass& x , const MpfrClass& y , RoundingMode rnd)
    // Berechnet wird:  s = x*(2+x) + y^2;
    {
      MpfrClass t;
      if (rnd == RoundUp)
        mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, RoundDown);  // t = 2+x;
      else
      {
	if (rnd == RoundDown)
	  mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, RoundUp);  // t = 2+x;
	else // rnd = RoundNearest
	  mpfr_add_si(t.mpfr_rep, x.mpfr_rep, 2, rnd);  // t = 2+x;
      }
      mpfr_mul(t.mpfr_rep, t.mpfr_rep, x.mpfr_rep, rnd); // t = x*(2+x);
      s = sqr(y,rnd);
      mpfr_add(s.mpfr_rep, t.mpfr_rep, s.mpfr_rep, rnd); // res = x*(2+x) + y^2
    }

    MpfrClass ln_sqrtxp1_2y2 (const MpfrClass& x , const MpfrClass& y ,RoundingMode rnd)
    // Calculating ln( sqrt( (x+1)^2 + y^2) );
    // x=-1 und y=0  ---->   res = -infinity
    {
      if (rnd == RoundToZero || rnd == RoundFromZero)
      {
        std::cerr << "ln_sqrtxp1_2y2(...), Error: RoundToZero and RoundFromZero not yet implemented!" << std::endl;
        exit (1);
      }

      PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision(), prec_OLD;

      if (x.GetPrecision() >= y.GetPrecision())
        prec =  x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfrClass::SetCurrPrecision(prec);
      prec_OLD = prec;

      const long int k1 = 536870909;
      const int k = 536870915;
      MpfrClass res(0), t(0);

      if (expo(x)>=k1 || expo(y)>=k1)
      // Nur hier kann Ueberlauf auftreten!
      {
      // u(x,y) = k*ln(2) + ln[(2^(-k) + 2^(-k)*x)^2 + (2^(-k)*y)^2]/2;
      // (2^(-k) + 2^(-k)*x)^2 wird intervallmaessig ausgewertet:
        MPFI::MpfiClass v(x);
	times2pown(v,-(long)k);  // v: Inclusion of 2^(-k)*x;
	v = sqr( v + exp2(-MPFI::MpfiClass(k)) );
	// v: Inclusion of (2^(-k) + 2^(-k)*x)^2;
	res = abs(y,rnd);
	times2pown(res,-k,rnd);
	res = sqr(res,rnd); // res: aufgerundeter Wert von (2^(-k)*|y|)^2

	if (rnd == RoundUp)
	  mpfr_add(res.mpfr_rep, res.mpfr_rep, (Sup(v)).mpfr_rep, rnd);
	else
	{
	  if (rnd == RoundDown)
	    mpfr_add(res.mpfr_rep, res.mpfr_rep, (Inf(v)).mpfr_rep, rnd);
	  else // rnd = RoundNearest
	    mpfr_add(res.mpfr_rep, res.mpfr_rep, (mid(v)).mpfr_rep, rnd);
	}
	res = ln(res,rnd);
	times2pown(res,-1,rnd); // res: ln[(2^(-k) + 2^(-k)*x)^2 + (2^(-k)*y)^2]/2;
	t = MPFR::MpfrClass::Ln2(rnd);
	mpfr_mul_si(t.mpfr_rep, t.mpfr_rep, (long)k, rnd); // t = k*ln(2);
	mpfr_add(res.mpfr_rep, t.mpfr_rep, res.mpfr_rep, rnd); // res = u(x,y);
      }
      else
      // Ein Ueberlauf kann bei [1+x*(2+x)+y^2] nicht auftreten!
      {
	if (abs(1+x)<0.125 && abs(y)<0.125) // Gruener Bereich
	{
	  if (x == -1)  // u(x,y) = ln(|y|);
	    mpfr_log(res.mpfr_rep, abs(y).mpfr_rep, rnd);
	  else
	  // ln( (1+x)^2+y^2 )/2 = ln(|1+x|) + ln( 1 + (y/(1+x))^2 )
	  // In  -1.25 <= x <= -0.75  the sum (1+x) is exactly evaluated!
	  {
	    MPFI::MpfiClass q(y);
	    MpfrClass xp1(1);
	    xp1 = abs(xp1+x);       // xp1 = |1+x| (exact !!)
	    q = sqr( q/xp1 );       // q: Inclusion of (y/(1+x))^2
	    mpfr_log(t.mpfr_rep, xp1.mpfr_rep, rnd);   // t   = ln(|1+x|);
	    if (rnd == RoundUp)
	      mpfr_log1p(res.mpfr_rep, Sup(q).mpfr_rep, rnd);  // res = ln(1+(y/(1+x))^2);
	    else
	    {
	      if (rnd == RoundDown)
	        mpfr_log1p(res.mpfr_rep, Inf(q).mpfr_rep, rnd); // res = ln(1+(y/(1+x))^2);
	      else
	        mpfr_log1p(res.mpfr_rep, mid(q).mpfr_rep, rnd); // res = ln(1+(y/(1+x))^2);
	    }
	    times2pown(res,-1,rnd);
	    mpfr_add(res.mpfr_rep, t.mpfr_rep, res.mpfr_rep, rnd);
	  }
	}
	else
	{
	  if (x>=-2.125 && x<=0.125 && abs(y)<=1.125)
	  {
	    if (isPos(x)) // Red subset on the right
	    { // Auswertung von ln[ 1 + {x(2+x)+y^2} ]/2  fuer 0 < x <=0.125 und |y|<=1.125
              const long int k = -510000000;
              if ( expo(x)<k && expo(y)<k )
              {
	        MPFI::MpfiClass z(y);
	        z = (z/x)*z + x;
	        z = (z+2)*x; // z: Inclusion of x*(2+x+(y/x)*y)
	        if (rnd == RoundUp)
	          res = Sup(z);
	        else
	        {
	          if (rnd == RoundDown)
	            res = Inf(z);
	          else res = mid(z);
	        }
              }
	      else
	      {
    	        t = sqr(y,rnd);
	        mpfr_add_ui(res.mpfr_rep, x.mpfr_rep, 2, rnd);  // res = 2+x;
	        mpfr_mul(res.mpfr_rep, res.mpfr_rep, x.mpfr_rep, rnd); // res = x(2+x);
	        mpfr_add(res.mpfr_rep, res.mpfr_rep, t.mpfr_rep, rnd); // res = x(2+x) + y^2
	      }
	      mpfr_log1p(res.mpfr_rep, res.mpfr_rep, rnd);
	      times2pown(res, -1, rnd);
	    }
	    else
	    {
	      if (x<-2) // Red subset on the left: -2.125 <= x < -2  und  abs(y)<=1.125
	      {
		ln_sqrt_S1 (res, x, y, rnd); // res = x(2+x) + y^2
		mpfr_log1p(res.mpfr_rep, res.mpfr_rep, rnd);
	        times2pown(res, -1, rnd);
	      }
	      else
	      {
		if (isZero(x))
		{
		  t = sqr(y,rnd);
		  mpfr_log1p(res.mpfr_rep, t.mpfr_rep, rnd);
		}
		else
		{
	          // Nur hier kann bei der Auswertung von x*(2+x)+y^2 Ausloeschung auftreten!
	          // Es gilt:  -2 <= x < 0  &&  |y|<=1.125
	          long int exs, exs_old, exy2;
	          ln_sqrt_S1 (t, res, x, y, rnd);  // t = y^2; res = x*(2+x)+y^2 = x*(2+x+(y/x)*y)
	          exs = expo(res); exy2 = expo(t);
	          if (exs-exy2 < -1)
	          // Ausloeschung ist jetzt moeglich:
	          {
	            int k=0, fac=2;
	            do
	            {
	              k++;
	              if (k==6)  fac = 4;
		      if (k==10) fac = 8;
	              prec = fac*prec;
	              MPFR::MpfrClass::SetCurrPrecision(prec);
	              exs_old = exs;
	              ln_sqrt_S1(t, res, x, y, rnd);
	              exs = expo(res);
	            } while (exs_old != exs);
	            MPFR::MpfrClass::SetCurrPrecision(2*prec);
	            ln_sqrt_S1(t, res, x, y, rnd); // res = x*(2+x)+y^2;
	            res.RoundPrecision(prec_OLD, rnd); // Runden zur alten Current-Precision
                    MpfrClass::SetCurrPrecision(prec_OLD);
	          }
	          mpfr_log1p(res.mpfr_rep, res.mpfr_rep, rnd); // res = ln[ 1 + x*(2+x) + y^2 ]
		}
		times2pown(res, -1, rnd);
	      }
	    }
	  }
	  else // Normale Auswertung von ln[ (1+x)^2 + y^2 ]/2
	  {
            ln_sqrt_S2(res, x, y, rnd);                // res = (1+x)^2 + y^2
	    mpfr_log(res.mpfr_rep, res.mpfr_rep, rnd); // res = ln[ (1+x)^2 + y^2 ]
	    times2pown(res, -1, rnd);                  // res = ln[(1+x)^2 + y^2]/2;
	  }
        }
        res.RoundPrecision(prec_old, rnd);     // Runden zur alten Current-Precision
        MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
        return res;
      }
    }  // ln_sqrtxp1_2y2 = ln[ (1+x)^2 + y^2 ]

    MpfrClass zeta (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_zeta(res.mpfr_rep, r.mpfr_rep, rnd);
        return res;
    }

    MpfrClass zeta (unsigned long int& n, RoundingMode rnd)
    {
      MpfrClass res(0);
      mpfr_zeta_ui(res.mpfr_rep, n, rnd);

      return res;
    }

    MpfrClass Li2 (const MpfrClass& r, RoundingMode rnd){  // Blomquist 29.04.2010

        MpfrClass res(0);
        mpfr_li2(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass Ei (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_eint(res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass J0 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_j0( res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass J1 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_j1( res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass Jn (long int n, const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_jn( res.mpfr_rep, n, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass Y0 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_y0( res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass Y1 (const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_y1( res.mpfr_rep, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass Yn (long int n, const MpfrClass& r, RoundingMode rnd)
    {
        MpfrClass res(0);
        mpfr_yn( res.mpfr_rep, n, r.mpfr_rep, rnd);

        return res;
    }

    MpfrClass plus_ab (const MpfrClass& x, const MpfrClass& a, const MpfrClass& b, RoundingMode rnd)
    // Returns  x + a*b, roundet with rnd to the Current-Precision;
    // Without rnd the rounding is done with the Current-Roundingmodus to the Current-Precision;
    {
        MpfrClass res(0);
        mpfr_fma (res.mpfr_rep, a.mpfr_rep, b.mpfr_rep, x.mpfr_rep, rnd);
        return res;
    }

    MpfrClass Round (const MpfrClass& r)
    // Der ganzzahlige Rueckgabewert hat stets die gleiche Praezision wie r;
    // Liegt r genau zwischen zwei benachbarten ganzzahligen Werten, so
    // wird von der Null weggerundet
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), r.GetPrecision());  // Urspruenglich!
        mpfr_round(res.mpfr_rep, r.mpfr_rep);

        return res;
    }

    MpfrClass Floor (const MpfrClass& r)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), r.GetPrecision());
        mpfr_floor(res.mpfr_rep, r.mpfr_rep);

        return res;
    }

    MpfrClass Trunc (const MpfrClass& r)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), r.GetPrecision());
        mpfr_trunc(res.mpfr_rep, r.mpfr_rep);

        return res;
    }

    MpfrClass Ceil (const MpfrClass& r)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), r.GetPrecision());
        mpfr_ceil(res.mpfr_rep, r.mpfr_rep);

        return res;
    }

    MpfrClass Frac (const MpfrClass& r)
    {
        MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), r.GetPrecision());
        mpfr_frac(res.mpfr_rep, r.mpfr_rep, MpfrClass::CurrRndMode);

        return res;
    }

    long int to_int (const MpfrClass& r, RoundingMode rnd)
    {
        return mpfr_get_si(r.mpfr_rep,rnd);
    }

    double to_double (const MpfrClass& r, RoundingMode rnd)
    {
        return mpfr_get_d(r.mpfr_rep,rnd);
    }

//    cxsc::real to_real (const MpfrClass& r, RoundingMode rnd)
//    {
//      double d;
//      d = mpfr_get_d(r.mpfr_rep,rnd);
//      return cxsc::_real(d);
//    }


    /*Ein-/Ausgabe Operatoren */

    std::ostream& operator << (std::ostream& os, const MpfrClass& v)
    {
        mpfr_out_str (stdout , MpfrClass::GetBase(), std::cout.precision() , v.mpfr_rep, MpfrClass::CurrRndMode);
        return os;
    }

    // Ausgabe Operator fuer mpfr_t Variablen
    std::ostream& operator << (std::ostream& os, const mpfr_t& v)
    {
        mpfr_out_str (stdout , MpfrClass::GetBase(), std::cout.precision() , v, MpfrClass::CurrRndMode);
        return os;
    }

    std::istream& operator >> (std::istream& is, MpfrClass& v)
    {
      is >> std::ws;

      bool hilf = true;
      char c;
      std::string input;

        // Solange einlesen, bis eof oder ein Leerzeichen erreicht ist:
        while(hilf)
        {
            is.get(c);
            if (is.eof())
            {
                hilf=false;
            }
            else
              if (isspace(c))
              {
                hilf=false;
                is.putback(c);
              }
              else
              {
                input += c;
              }
        }


      input += "\0";

      PrecisionType prec  =  v.GetPrecision();

      if ( mpfr_set_str( v.GetValue(), const_cast<char *>(input.c_str()), MpfrClass::GetBase(), MpfrClass::GetCurrRndMode() ) )
      {
         std::cerr << "Error by data input, wrong base?" << std::endl;
         exit(1);
      }

      v.RoundPrecision(prec, MpfrClass::GetCurrRndMode());

      return is;
    }

  MpfrClass double2Mpfr (const double& dbl)
  // Speichert dbl exakt in res;
  {
    const int k = 53;
    MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), k);
    mpfr_set_d(res.mpfr_rep, dbl, RoundNearest);
    return res;
  }

//  MpfrClass real2Mpfr (const cxsc::real& x)
//  // Speichert x exakt in res;
//  {
//    const int k = 53;
//    MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), k);
//    mpfr_set_d(res.mpfr_rep, _double(x), RoundNearest);
//    return res;
//  }

  MpfrClass int2Mpfr (const int& x)
  // Speichert x exakt in res;
  {
    const int k = 64;
    MpfrClass res(0.0, MpfrClass::GetCurrRndMode(), k);
    mpfr_set_si(res.mpfr_rep, (long int)x, RoundNearest);
    return res;
  }

  MpfrClass mpfr_t2Mpfr (const mpfr_t& x)
  // Speichert x exakt in res;
  {
    MpfrClass res(0, RoundNearest, mpfr_get_prec(x));
    mpfr_set(res.mpfr_rep, x, RoundNearest);
    return res;
  }

  std::string to_string(const mpfr_t& t, RoundingMode rnd, PrecisionType prec)  // Blomquist 09.10.2010
  // Diese Funktion liefert einen string von t in Gleitpunktdarstellung.
  // Gerundet wird bez. des Rundungsmodus rnd.
  // Der string wird mit prec Dezimalstellen generiert, wenn base = 10 ist.
  // Mit prec=0 erhaelt der string mindestens so viele Dezimalstellen (bei base=10),
  // wie es der Praezision von t entspricht.
  // Mit hinreichend grossem prec ist der string-Wert gleich dem exakten t-Wert.
  {
    std::stringstream res_str;
    // Pruefen ob Vorzeichen von t negativ ist:
    bool neg = mpfr_signbit(t);

    // Wenn t unendlich ist:
    if (mpfr_inf_p(t) != 0)
    {
      if ( neg )
        res_str << "-Inf";
      else
        res_str << "Inf";
    }
    // Wenn t NaN ist
    if (mpfr_nan_p(t) != 0)
    {
      res_str << "NaN";
    }
    // Wenn t eine Zahl ist
    if(mpfr_number_p(t) != 0)
    {
      // Pruefe ob t = 0 ist
      if ( mpfr_zero_p(t) != 0)
      {
        if ( neg )
          res_str << "-0.0";
        else
          res_str << "0.0";
      }
      else  //  t ist nicht 0, nicht Nan und nicht (+,-)Inf:
      {
        char *s;
        mpfr_exp_t e;
        int size_s;
        // Lese die Zeichenkette von t aus, mit prec Stellen. (alle wenn prec = 0 ist);
        // Im Fall prec=0 wird die string-Laenge so gewaehlt, dass bez. der Praezision
        // von t ausreichend viele Stellen in den Sting geschrieben werden.
        // Der Exponent wird in e gespeichert

        s = mpfr_get_str(NULL, &e, MpfrClass::GetBase(), prec, t, rnd);
        // Aus s und e wird jetzt die floating-point Zahl gebildet:
        size_s = strlen(s)-1;
        // Wenn das Vorzeichen negativ ist:
        if (s[0] == '-')
        {
          res_str << "-";
          res_str << s[1];
          // Fuege dann den Punkt '.' ein und die restliche Zeichen
          res_str << ".";
          for (int i =2; i<= size_s; i++)
            res_str << s[i];
        }
        else
        {
          // Das Vorzeichen ist positiv:
          // Fuege das 1. Zeichen ein
          res_str << s[0];
          // Fuege dann den Punkt '.' ein und die restliche Zeichen
          res_str << ".";
          for (int i =1; i<= size_s; i++)
            res_str << s[i];
        }
        // Fuege das Exponenten-Zeichen e an:
        res_str << "e";
	// und den Exponenten - 1 = e-1
        res_str << e-1;
      }
    }
    return res_str.str();
  }

  std::string to_string (const MpfrClass& t, RoundingMode rnd, PrecisionType prec)
  // Diese Funktion liefert einen string von t in Gleitpunktdarstellung.
  // Gerundet wird bez. des Rundungsmodus rnd.
  // Der string wird mit prec Dezimalstellen generiert, wenn base = 10 ist.
  // Mit prec=0 erhaelt der string mindestens so viele Dezimalstellen (bei base=10),
  // wie es der Praezision von t entspricht.
  // Mit hinreichend grossem prec ist der string-Wert gleich dem exakten t-Wert.
  {
    return to_string(t.mpfr_rep, rnd, prec);
  }

  // op erhält die Praezision prec und den Wert von op1, wobei bez. rnd gerundet wird.
  // Ohne prec erhält op die Current-Precision, und ohne rnd wird mit dem Current-Rundungsmodus gerundet.
  void set_Mpfr (MpfrClass& op, const MpfrClass& op1, RoundingMode rnd, PrecisionType prec)
  {
    op.SetPrecision(prec);
    mpfr_set(op.mpfr_rep, op1.mpfr_rep, rnd);
  }

  // Wert von A und B Tauschen
  void swap(MpfrClass& A, MpfrClass& B)
  {
    mpfr_swap(A.mpfr_rep, B.mpfr_rep);
  }

  // Wert von A und B Tauschen
  void swap(MpfrClass& A, mpfr_t& B)
  {
    mpfr_swap(A.mpfr_rep, B);
  }

  MpfrClass x_div_x2py2(const MpfrClass& x, const MpfrClass& y, RoundingMode rnd)
  // Calculating x/(x^2+y^2)
  {
    const int c1 = 536870910, c2 = -536870911;
//    long ex_x, ex_y, ex_m, ex_s;
    long ex_x, ex_y, ex_m;
    long ex_s = 0;

    bool x_zero(isZero(x)), y_zero(isZero(y)), overfl(false), underfl(false);

    if (x_zero && y_zero)
    {
      std::cerr << "x_div_x2py2(...), Error: x=0 and y=0" << std::endl;
      exit (1);
    }
    if (rnd == RoundToZero || rnd == RoundFromZero)
    {
      std::cerr << "x_div_x2py2(...), Error: RoundToZero and RoundFromZero not yet implemented!" << std::endl;
      exit (1);
    }

    PrecisionType prec, prec_old = MpfrClass::GetCurrPrecision();
    if (x.GetPrecision() >= y.GetPrecision())
      prec =  x.GetPrecision();
    else prec = y.GetPrecision();
    if (prec < prec_old) prec = prec_old;
    MpfrClass::SetCurrPrecision(prec);

    MpfrClass res(0);

    if (!x_zero)
    {
      if (y_zero)
      {
	res = reci(x,rnd); // res = 1/x, rounded with respect to rnd;
      }
      else // x<>0 and y<>0 :
      {
	ex_x = expo(x);  ex_y = expo(y);
	MpfrClass xs(abs(x)), ys(abs(y)), xz(x);
	if (ex_x>c1 || ex_y>c1)
	{
	  overfl = true;
	  ex_m = ex_x;
	  if (ex_y>ex_m) ex_m = ex_y; // ex_m = Max(ex_x,ex_y);
          ex_s = c1 - ex_m;  // ex_s < 0
	}
	if (ex_x<c2 && ex_y<c2)
	{
	  underfl = true;
	  ex_m = ex_x;
	  if (ex_y<ex_m) ex_m = ex_y; // ex_m = Min(ex_x,ex_y);
          ex_s = c2 + 1 - ex_m;  // ex_s < 0
	}

	if (rnd==RoundUp)
	{
	  if (overfl || underfl)
	  {
	    times2pown(xz, 2*ex_s, rnd);
	    if (isPos(x))
	    {
	      times2pown(xs, ex_s, RoundDown);
	      times2pown(ys, ex_s, RoundDown);
	      xs = x2py2(xs, ys, RoundDown);   // xs = xs^2 + ys^2;
	    }
	    else // x<0:
	    {
	      times2pown(xs, ex_s, rnd);
	      times2pown(ys, ex_s, rnd);
	      xs = x2py2(xs, ys, rnd);   // xs = xs^2 + ys^2;
	    }
	  }
	  else // Normal calculation without overflow or underflow:
	  {
	    if (isPos(x))
	      xs = x2py2(xs, ys, RoundDown);   // xs = xs^2 + ys^2;
	    else // x<0:
	      xs = x2py2(xs, ys, rnd);   // xs = xs^2 + ys^2;
	  }
	}
	else
	{
	  if (rnd==RoundDown)
	  {
	    if (overfl || underfl)
	    {
	      times2pown(xz, 2*ex_s, rnd);
	      if (isPos(x))
	      {
	        times2pown(xs, ex_s, RoundUp);
	        times2pown(ys, ex_s, RoundUp);
	        xs = x2py2(xs, ys, RoundUp);   // xs = xs^2 + ys^2;
	      }
	      else // x<0:
	      {
	        times2pown(xs, ex_s, rnd);
	        times2pown(ys, ex_s, rnd);
	        xs = x2py2(xs, ys, rnd);   // xs = xs^2 + ys^2;
	      }
	    }
	    else // Normal calculation without overflow or underflow:
	    {
	      if (isPos(x))
	        xs = x2py2(xs, ys, RoundUp);   // xs = xs^2 + ys^2;
	      else // x<0:
	        xs = x2py2(xs, ys, rnd);       // xs = xs^2 + ys^2;
	    }
	  }
	  else // RoundNearest
	  {
	    if (overfl || underfl)
	    {
	      times2pown(xz, 2*ex_s, rnd);
	      times2pown(xs, ex_s, rnd);
	      times2pown(ys, ex_s, rnd);
	      xs = x2py2(xs, ys, rnd);   // xs = xs^2 + ys^2;
	    }
	    else // Normal calculation without overflow or underflow:
	      xs = x2py2(xs, ys, rnd);   // xs = xs^2 + ys^2;
	  }
	}
	mpfr_div(res.GetValue(), xz.GetValue(), xs.GetValue(), rnd);
      }
    }

    res.RoundPrecision(prec_old, rnd);       // Rundung zur alten Current-Precision
    MpfrClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision

    return res;
  }

}; // namespace MPFR
