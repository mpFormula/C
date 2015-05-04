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
/*  Datei:  mpfciclass.cpp                   */
/*  Zweck:  C++-Wrapper-Klasse fuer          */
/*          die MPFI-Bibliothek              */
/*  Based on    mpfr-3.0.0, mpfi-1.5         */
/*********************************************/


#include "mpfciclass.hpp"

namespace MPFI {

int MpfciClass::base = 10;

//---------------------------------------------------------
//----------begin constructors and destructors-------------
//---------------------------------------------------------

    // Initialisieren mit NaN und Current-Precision
    MpfciClass::MpfciClass()
    {
      mpfi_init2(mpfi_re, MPFR::MpfrClass::GetCurrPrecision());
      mpfi_init2(mpfi_im, MPFR::MpfrClass::GetCurrPrecision());
    }

    // Initialisieren mit Wert von mpfi und Precision prec.
    MpfciClass::MpfciClass (const mpfi_t& x, const mpfi_t& y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set(mpfi_im, y);
    }

    MpfciClass::MpfciClass (const mpfi_t& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

    MpfciClass::MpfciClass (const MpfiClass& x, const MpfiClass& y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set(mpfi_re, getvalue(x));

      mpfi_init2(mpfi_im, prec);
      mpfi_set(mpfi_im, getvalue(y));
    }

    MpfciClass::MpfciClass (const MpfiClass& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set(mpfi_re, getvalue(x));

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

//    MpfciClass::MpfciClass (const cxsc::interval& x, const cxsc::interval& y, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_interv_d(mpfi_re, _double(Inf(x)), _double(Sup(x)));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_interv_d(mpfi_im, _double(Inf(y)), _double(Sup(y)));
//    }

    MpfciClass::MpfciClass (const MPFR::MpfcClass& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_interv_fr(mpfi_re, getvalueRe(x), getvalueRe(x));

      mpfi_init2(mpfi_im, prec);
      mpfi_interv_fr(mpfi_im, getvalueIm(x), getvalueIm(x));
    }

//    MpfciClass::MpfciClass (const cxsc::complex& x, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_interv_d(mpfi_re, _double(Re(x)), _double(Re(x)));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_interv_d(mpfi_im, _double(Im(x)), _double(Im(x)));
//    }


//    MpfciClass::MpfciClass (const cxsc::interval& x, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_interv_d(mpfi_re, _double(Inf(x)), _double(Sup(x)));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_set_si(mpfi_im, 0);
//    }

//    MpfciClass::MpfciClass (const cxsc::cinterval& z, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_interv_d(mpfi_re, _double(Inf(Re(z))), _double(Sup(Re(z))));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_interv_d(mpfi_im, _double(Inf(Im(z))), _double(Sup(Im(z))));
//    }

    MpfciClass::MpfciClass (const mpfr_t& x, const mpfr_t& y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_fr(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_fr(mpfi_im, y);
    }

    MpfciClass::MpfciClass (const mpfr_t& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_fr(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

    MpfciClass::MpfciClass (const MPFR::MpfrClass& x, const MPFR::MpfrClass& y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_fr(mpfi_re, getvalue(x));

      mpfi_init2(mpfi_im, prec);
      mpfi_set_fr(mpfi_im, getvalue(y));
    }

    MpfciClass::MpfciClass (const MPFR::MpfrClass& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_fr(mpfi_re, getvalue(x));

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

    MpfciClass::MpfciClass (const double& x, const double& y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_d(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_d(mpfi_im, y);
    }

    MpfciClass::MpfciClass (const double& x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_d(mpfi_re, x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

//    MpfciClass::MpfciClass (const cxsc::real& x, const cxsc::real& y, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_set_d(mpfi_re, _double(x));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_set_d(mpfi_im, _double(y));
//    }

//    MpfciClass::MpfciClass (const cxsc::real& x, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_re, prec);
//      mpfi_set_d(mpfi_re, _double(x));
//
//      mpfi_init2(mpfi_im, prec);
//      mpfi_set_si(mpfi_im, 0);
//    }

    MpfciClass::MpfciClass (const int x, const int y, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_si(mpfi_re, (long int)x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, (long int)y);
    }

    MpfciClass::MpfciClass (const int x, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set_si(mpfi_re, (long int)x);

      mpfi_init2(mpfi_im, prec);
      mpfi_set_si(mpfi_im, 0);
    }

    MpfciClass::MpfciClass (const MpfciClass& z, PrecisionType prec)
    {
      mpfi_init2(mpfi_re, prec);
      mpfi_set(mpfi_re, z.mpfi_re);

      mpfi_init2(mpfi_im, prec);
      mpfi_set(mpfi_im, z.mpfi_im);
    }

  MpfciClass::MpfciClass (const std::string& s, PrecisionType prec)
  {
    std::string str;
    int i, ik, ie, iv;

    i  = s.find("(",0);
    iv = s.find(",");
    ik = s.find(",",iv+1);
    ie = s.find(")");

    if (i<0 || ik<0 || ie<0)
    {
      std::cerr << "Error: Format ([Number,Number],[Number,Number]) is required!" << std::endl;
//      exit(1);
    }
    str = s.substr (i+1,ik-i-1);
    MpfiClass Re(str, prec);
    mpfi_init2(mpfi_re, prec);
    mpfi_set(mpfi_re, Re.GetValue());

    str = s.substr (ik+1,ie-ik-1);
    MpfiClass Im(str, prec);
    mpfi_init2(mpfi_im, prec);
    mpfi_set(mpfi_im, Im.GetValue());
  }

    // Freigabe des Speichers fuer mpfi_re und mpfi_im
    MpfciClass::~MpfciClass ()
    {
      mpfi_clear(mpfi_re);
      mpfi_clear(mpfi_im);
    }

//--------------------------------------------------------
//----------end constructor and destructors---------------
//--------------------------------------------------------

  void times2pown (MpfciClass& r, const long int n)
  // Calculating r*2^n without changing the precision of r
  {
    mpfi_mul_2si(r.mpfi_re, r.mpfi_re, (long int)n);
    mpfi_mul_2si(r.mpfi_im, r.mpfi_im, (long int)n);
  }

// ------------------------------------------------------------------------------------
// ----------------------------- Precision Handling -----------------------------------
// ------------------------------------------------------------------------------------

// Setzten der gleichen Current-Precision fuer die Klassen MpfciClass, MpfcClass, MpfrClass, MpfiClass:
  void MpfciClass::SetCurrPrecision (PrecisionType newprec)
  {
     MPFR::MpfrClass::SetCurrPrecision(newprec);
  }

  // Auslesen der Current-Precision
  const PrecisionType MpfciClass::GetCurrPrecision ()
  {
     return MPFR::MpfrClass::GetCurrPrecision();
  }

  // Auslesen der Precision des aktuellen Objekts;
  // Wenn Realteil u. Imaginaerteil verschiedene Praezisionen
  // besitzen, so wird die maximale Präzision zurückgegeben.
  PrecisionType MpfciClass::GetPrecision () const
  {
    PrecisionType prec_re, prec;
    prec_re = mpfi_get_prec(mpfi_re);
    prec    = mpfi_get_prec(mpfi_im);

    if (prec_re > prec)
      prec = prec_re;

    return prec;
  }

  // Setzten der Precision fuer das aktuelle Objekt, Wert wird geloescht
  void MpfciClass::SetPrecision (PrecisionType newprec)
  {
     mpfi_set_prec(mpfi_re, newprec);
     mpfi_set_prec(mpfi_im, newprec);
  }

  // Schliesst das aktuelle Objekt (Real- u. Imaginaerteil-Intervall) mit
  // der neuen Precision newprec ein;
  void MpfciClass::RoundPrecision(PrecisionType newprec)
  {
     mpfi_round_prec(mpfi_re, newprec);  // Including the interval of the real part
     mpfi_round_prec(mpfi_im, newprec);  // Including the interval of the imaginary part
  }

// ---------------------------------------------------------------------------------------
// ----------------------------- Eingabe|Ausgabe-Operatoren ------------------------------
// ---------------------------------------------------------------------------------------

  std::ostream& operator << (std::ostream& os, const MpfciClass& z)
  {
    std::cout << "(";
    mpfi_out_str (stdout , MpfiClass::GetBase(), std::cout.precision() , z.mpfi_re);
    std::cout << ", ";
    mpfi_out_str (stdout , MpfiClass::GetBase(), std::cout.precision() , z.mpfi_im);
    std::cout << ")";
    return os;
  }

  std::istream& operator >> (std::istream& is, MpfciClass& v)
  {
    std::string str;
    is >> str;
    v = str;

    return is;
  }

// ---------------------------------------------------------------------------------------
// -------------------------- Ende: Eingabe|Ausgabe-Operatoren ---------------------------
// ---------------------------------------------------------------------------------------


//--------------------------------------------------------
//----------begin Assignment operators -------------------
//--------------------------------------------------------

  // Die linken Real- und Imaginaerteil-Intervalle erhalten die Current-Precision
  // und schliessen die entsprechenden Intervalle des rechten Operanden optimal ein.
  MpfciClass& MpfciClass::operator = (const MpfciClass& v)
  {
    if (this == &v)
    {
      (*this).RoundPrecision(GetCurrPrecision());
      return *this;
    }

    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set(mpfi_re, v.mpfi_re);

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set(mpfi_im, v.mpfi_im);

    return *this;
  }

//  MpfciClass& MpfciClass::operator = (const cxsc::cinterval& v)
//  {
//    mpfi_set_prec(mpfi_re, GetCurrPrecision());
//    mpfi_interv_d (mpfi_re, _double(Inf(Re(v))), _double(Sup(Re(v))));
//
//    mpfi_set_prec(mpfi_im, GetCurrPrecision());
//    mpfi_interv_d (mpfi_im, _double(Inf(Im(v))), _double(Sup(Im(v))));
//
//    return *this;
//  }

  MpfciClass& MpfciClass::operator = (const MPFR::MpfcClass& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_interv_fr ( mpfi_re, getvalueRe(v), getvalueRe(v) );

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_interv_fr ( mpfi_im, getvalueIm(v), getvalueIm(v) );

    return *this;
  }

//  MpfciClass& MpfciClass::operator = (const cxsc::complex& v)
//  {
//    mpfi_set_prec(mpfi_re, GetCurrPrecision());
//    mpfi_interv_d (mpfi_re, _double(Re(v)), _double(Re(v)));
//
//    mpfi_set_prec(mpfi_im, GetCurrPrecision());
//    mpfi_interv_d (mpfi_im, _double(Im(v)), _double(Im(v)));
//
//    return *this;
//  }

  MpfciClass& MpfciClass::operator = (const mpfi_t& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set(mpfi_re, v);

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

  MpfciClass& MpfciClass::operator = (const MpfiClass& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set(mpfi_re, getvalue(v));

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

//  MpfciClass& MpfciClass::operator = (const cxsc::interval& v)
//  {
//    mpfi_set_prec(mpfi_re, GetCurrPrecision());
//    mpfi_interv_d(mpfi_re, _double(Inf(v)), _double(Sup(v)));
//
//    mpfi_set_prec(mpfi_im, GetCurrPrecision());
//    mpfi_set_si(mpfi_im, 0);
//
//    return *this;
//  }

  MpfciClass& MpfciClass::operator = (const mpfr_t& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set_fr(mpfi_re, v);

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

  MpfciClass& MpfciClass::operator = (const MPFR::MpfrClass& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set_fr(mpfi_re, getvalue(v));

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

  MpfciClass& MpfciClass::operator = (const double& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set_d(mpfi_re, v);

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

//  MpfciClass& MpfciClass::operator = (const cxsc::real& v)
//  {
//    mpfi_set_prec(mpfi_re, GetCurrPrecision());
//    mpfi_set_d(mpfi_re, _double(v));
//
//    mpfi_set_prec(mpfi_im, GetCurrPrecision());
//    mpfi_set_si(mpfi_im, 0);
//
//    return *this;
//  }

  MpfciClass& MpfciClass::operator = (const int& v)
  {
    mpfi_set_prec(mpfi_re, GetCurrPrecision());
    mpfi_set_si(mpfi_re, v);

    mpfi_set_prec(mpfi_im, GetCurrPrecision());
    mpfi_set_si(mpfi_im, 0);

    return *this;
  }

  MpfciClass& MpfciClass::operator = (const std::string& s)
  {
    PrecisionType prec = GetCurrPrecision();
    std::string str;
    int i, ik, ie, iv;

    i  = s.find("(",0);
    iv = s.find(",");
    ik = s.find(",",iv+1);
    ie = s.find(")");

    if (i<0 || ik<0 || ie<0)
    {
      std::cerr << "Error: Format ([Number,Number],[Number,Number]) is required!" << std::endl;
//      exit(1);
    }
    str = s.substr (i+1,ik-i-1);
    MpfiClass Re(str);
    mpfi_init2(mpfi_re, prec);
    mpfi_set(mpfi_re, Re.GetValue());

    str = s.substr (ik+1,ie-ik-1);
    MpfiClass Im(str);
    mpfi_init2(mpfi_im, prec);
    mpfi_set(mpfi_im, Im.GetValue());

    return *this;
  }

  // --------------------------------------------------------------
  // ----------------- end Assignment operators -------------------
  // --------------------------------------------------------------

  // Setzten der Basis fuer Ein- und Ausgabe, (Wert zwischen 2-36)
  void MpfciClass::SetBase (int b)
  {
    base = b;
  }

  // Auslesen der aktuellen Basis
  const int MpfciClass::GetBase ()
  {
    return base;
  }

  MpfiClass Re(const MpfciClass& z)
  // Calculating Re(z) without rounding and with the
  // actual precision of z;
  {
     MpfiClass r(z.mpfi_re, z.GetPrecision());
     return r;
  }

  MpfiClass Im(const MpfciClass& z)
  // See the comment of Re(...) !
  {
     MpfiClass r(z.mpfi_im, z.GetPrecision());
     return r;
  }

  std::string to_string (const MpfciClass& z, PrecisionType prec)
  {
    return "(" + to_string(Re(z), prec) + "," + to_string(Im(z), prec) + ")";
  }

//  cxsc::cinterval to_cinterval(const MpfciClass& z)
//  {
//    return cxsc::cinterval(to_interval(Re(z)), to_interval(Im(z)));
//  }

// -----------------------------------------------------------------------
// -------------------------- MPFCI --> mpfi -----------------------------

  mpfi_t& MpfciClass::GetValueRe()
  {
    return this->mpfi_re;
  }

  mpfi_t& MpfciClass::GetValueIm()
  {
    return this->mpfi_im;
  }

  void MpfciClass::SetValueRe(const mpfi_t& v)
  // Das Realteilintervall des aktuellen Objekts wird exakt auf v gesetzt.
  // Das Imaginaerteilintervall des aktuellen Objekts bleibt erhalten.
  // Die Praezision des aktuellen Objekts wird gesetzt auf das
  // Maximum der Praezisionen von v und mpfi_im, d.h. die
  // Praezisionen von Real- und Imaginaerteil-Intervall sind GLEICH!
  {
    PrecisionType precim = mpfi_get_prec(mpfi_im),
                  prec   = mpfi_get_prec(v);
    if (precim<prec)
      mpfi_round_prec(mpfi_im, prec);
    else
      prec = precim;
    mpfi_set_prec(mpfi_re, prec);
    mpfi_set(mpfi_re, v);
  }

  void MpfciClass::SetValueIm(const mpfi_t& v)
  // Das Imaginaerteilintervall des aktuellen Objekts wird exakt auf v gesetzt.
  // Das RealteilIntervall des aktuellen Objekts bleibt erhalten.
  // Die Praezision des aktuellen Objekts wird gesetzt auf das
  // Maximum der Praezisionen von v und mpfi_re, d.h. die
  // Praezisionen von Real- und Imaginaerteilintervall sind GLEICH!
  {
    PrecisionType precre = mpfi_get_prec(mpfi_re),
                  prec   = mpfi_get_prec(v);
    if (precre<prec)
      mpfi_round_prec(mpfi_re, prec);
    else
      prec = precre;
    mpfi_set_prec(mpfi_im, prec);
    mpfi_set(mpfi_im, v);
  }

  void MpfciClass::SetValue(const mpfi_t& re, const mpfi_t& im)
  // Das Real- und Imaginaerteilintervall des aktuellen Objekts wird
  // ohne Rundung neu gesetzt auf re bzw. auf im.
  // Das aktuelle Objekt erhaelt als Praezision das Maximum der
  // Praezisionen von re und im, d.h. die Praezisionen von Real-
  // und Imaginaerteilintervall werden auf den gleichen Wert gesetzt!
  {
    PrecisionType precre = mpfi_get_prec(re),
                  prec   = mpfi_get_prec(im);
    if (precre>prec) prec = precre;

    mpfi_set_prec(mpfi_re, prec);
    mpfi_set(mpfi_re, re);
    mpfi_set_prec(mpfi_im, prec);
    mpfi_set(mpfi_im, im);
  }

  // op erhält die Praezision prec und schliesst die Real- u. Imaginaerteilintervalle von op1 ein.
  // Ohne prec erhält op die Current-Precision.
  void set_Mpfci (MpfciClass& op, const MpfciClass& op1, PrecisionType prec)
  {
    op.SetPrecision(prec);
    mpfi_set(op.mpfi_re, op1.mpfi_re);
    mpfi_set(op.mpfi_im, op1.mpfi_im);
  }

  MPFR::MpfcClass Inf(const MpfciClass& zi, PrecisionType prec)
  {
    MPFR::MpfcClass res( Inf(Re(zi),prec), Inf(Im(zi),prec) );
    return res;
  }

  MPFR::MpfcClass Sup(const MpfciClass& zi, PrecisionType prec)
  {
    MPFR::MpfcClass res( Sup(Re(zi),prec), Sup(Im(zi),prec) );
    return res;
  }

  MPFR::MpfcClass mid(const MpfciClass& zi)
  {
    MPFR::MpfcClass res( mid(Re(zi)), mid(Im(zi)) );
    return res;
  }

  MpfciClass Blow(const MpfciClass& z, const MPFR::MpfrClass eps)
  {
    return MpfciClass( Blow(Re(z),eps), Blow(Im(z),eps), z.GetPrecision() );
  }

  // --------------------------------------------------------------------------

  int in (const MpfciClass& x, const MpfciClass& y)
  {
    return ( in(Re(x),Re(y)) && in(Im(x),Im(y)) );
  }

//  int in (const cxsc::cinterval& x, const MpfciClass& y)
//  {
//    return ( in(Re(x),Re(y)) && in(Im(x),Im(y)) );
//  }

  int in (const MpfiClass& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

  int in (const mpfi_t& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

//  int in (const cxsc::interval& x, const MpfciClass& y)
//  {
//    return ( in(x,Re(y)) && in(0,Im(y)) );
//  }

  int in (const mpfr_t& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

  int in (const MPFR::MpfrClass& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

  int in (const double& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

//  int in (const cxsc::real& x, const MpfciClass& y)
//  {
//    return ( in(x,Re(y)) && in(0,Im(y)) );
//  }

  int in (const int& x, const MpfciClass& y)
  {
    return ( in(x,Re(y)) && in(0,Im(y)) );
  }

  int in (const MPFR::MpfcClass& x, const MpfciClass& y)
  {
    return ( in(Re(x),Re(y)) && in(Im(x),Im(y)) );
  }

//  int in (const cxsc::complex& x, const MpfciClass& y)
//  {
//    return ( in(Re(x),Re(y)) && in(Im(x),Im(y)) );
//  }

  // ----------- friend-Funktionen ---------------------------
  const mpfi_t& getvalueRe(const MpfciClass& v)
  {
      return v.mpfi_re;
  }

  const mpfi_t& getvalueIm(const MpfciClass& v)
  {
      return v.mpfi_im;
  }

  bool isNan(const MpfciClass& v)
  {
    return ( mpfi_nan_p(v.mpfi_re)!=0 || mpfi_nan_p(v.mpfi_im)!=0 );
  }

  bool isZero(const MpfciClass& v)
  {
    return ( mpfi_is_zero(v.mpfi_re)>0 && mpfi_is_zero(v.mpfi_im)>0 );
  }

  bool isInf(const MpfciClass& v)
  {
    return ( mpfi_inf_p(v.mpfi_re)!=0 || mpfi_inf_p(v.mpfi_im)!=0 );
  }

  bool isBounded(const MpfciClass& v)
  {
    return ( mpfi_bounded_p(v.mpfi_re)!=0 && mpfi_bounded_p(v.mpfi_im)!=0 );
  }

  bool isPoint (const MpfciClass& v)
  {
    return (isPoint(Re(v)) && isPoint(Im(v)));
  }

//--------------------------------------------------------
//----------start Comparison operators--------------------
//--------------------------------------------------------

  bool operator == (const MpfciClass& x, const MpfciClass& y)
  {
    return (Re(x)==Re(y) && Im(x)==Im(y));
  }

//  bool operator == (const MpfciClass& x, const cxsc::cinterval& y)
//  {
//    return (Re(x)==Re(y) && Im(x)==Im(y));
//  }

  bool operator == (const MpfciClass& x, const MPFR::MpfcClass& y)
  {
    return (Re(x)==Re(y) && Im(x)==Im(y));
  }

//  bool operator == (const MpfciClass& x, const cxsc::complex& y)
//  {
//    return (Re(x)==Re(y) && Im(x)==Im(y));
//  }

  bool operator == (const MpfciClass& x, const mpfi_t& y)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const MpfciClass& x, const MpfiClass& y)
  {
    return (Re(x)==y && Im(x)==0);
  }

//  bool operator == (const MpfciClass& x, const cxsc::interval& y)
//  {
//    return (Re(x)==y && Im(x)==0);
//  }

  bool operator == (const MpfciClass& x, const mpfr_t& y)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const MpfciClass& x, const MPFR::MpfrClass& y)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const MpfciClass& x, const double& y)
  {
    return (Re(x)==y && Im(x)==0);
  }

//  bool operator == (const MpfciClass& x, const cxsc::real& y)
//  {
//    return (Re(x)==y && Im(x)==0);
//  }

  bool operator == (const MpfciClass& x, const int y)
  {
    return (Re(x)==y && Im(x)==0);
  }

//  bool operator == (const cxsc::cinterval& y, const MpfciClass& x)
//  {
//    return (Re(x)==Re(y) && Im(x)==Im(y));
//  }

  bool operator == (const MPFR::MpfcClass& y, const MpfciClass& x)
  {
    return (Re(x)==Re(y) && Im(x)==Im(y));
  }

//  bool operator == (const cxsc::complex& y, const MpfciClass& x)
//  {
//    return (Re(x)==Re(y) && Im(x)==Im(y));
//  }

  bool operator == (const mpfi_t& y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const MpfiClass& y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

//  bool operator == (const cxsc::interval& y,  const MpfciClass& x)
//  {
//    return (Re(x)==y && Im(x)==0);
//  }

  bool operator == (const mpfr_t& y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const MPFR::MpfrClass& y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

  bool operator == (const double& y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

//  bool operator == (const cxsc::real& y, const MpfciClass& x)
//  {
//    return (Re(x)==y && Im(x)==0);
//  }

  bool operator == (const int y, const MpfciClass& x)
  {
    return (Re(x)==y && Im(x)==0);
  }

// --------------------------------------------------------------------

  bool operator != (const MpfciClass& x, const MpfciClass& y)
  {
    return (Re(x)!=Re(y) || Im(x)!=Im(y));
  }

//  bool operator != (const MpfciClass& x, const cxsc::cinterval& y)
//  {
//    return (Re(x)!=Re(y) || Im(x)!=Im(y));
//  }

  bool operator != (const MpfciClass& x, const MPFR::MpfcClass& y)
  {
    return (Re(x)!=Re(y) || Im(x)!=Im(y));
  }

//  bool operator != (const MpfciClass& x, const cxsc::complex& y)
//  {
//    return (Re(x)!=Re(y) || Im(x)!=Im(y));
//  }

  bool operator != (const MpfciClass& x, const mpfi_t& y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const MpfciClass& x, const MpfiClass& y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

//  bool operator != (const MpfciClass& x, const cxsc::interval& y)
//  {
//    return (Re(x)!=y || Im(x)!=0);
//  }

  bool operator != (const MpfciClass& x, const mpfr_t& y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const MpfciClass& x, const MPFR::MpfrClass& y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const MpfciClass& x, const double& y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

//  bool operator != (const MpfciClass& x, const cxsc::real& y)
//  {
//    return (Re(x)!=y || Im(x)!=0);
//  }

  bool operator != (const MpfciClass& x, const int y)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

//  bool operator != (const cxsc::cinterval& y, const MpfciClass& x)
//  {
//    return (Re(x)!=Re(y) || Im(x)!=Im(y));
//  }

  bool operator != (const MPFR::MpfcClass& y, const MpfciClass& x)
  {
    return (Re(x)!=Re(y) || Im(x)!=Im(y));
  }

//  bool operator != (const cxsc::complex& y, const MpfciClass& x)
//  {
//    return (Re(x)!=Re(y) || Im(x)!=Im(y));
//  }

  bool operator != (const mpfi_t& y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const MpfiClass& y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

//  bool operator != (const cxsc::interval& y,  const MpfciClass& x)
//  {
//    return (Re(x)!=y || Im(x)!=0);
//  }

  bool operator != (const mpfr_t& y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const MPFR::MpfrClass& y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  bool operator != (const double& y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

//  bool operator != (const cxsc::real& y, const MpfciClass& x)
//  {
//    return (Re(x)!=y || Im(x)!=0);
//  }

  bool operator != (const int y, const MpfciClass& x)
  {
    return (Re(x)!=y || Im(x)!=0);
  }

  void set_nan (MpfciClass& a)
  {
    MpfiClass x(0, a.GetPrecision());
    set_nan(x);
    MpfciClass tmp(x, x, a.GetPrecision() );
    set_Mpfci(a, tmp, a.GetPrecision());
  }

  void set_inf (MpfciClass& a)
  {
    MpfiClass x(0, a.GetPrecision());
    set_inf(x);
    MpfciClass tmp(x, x, a.GetPrecision() );
    set_Mpfci(a, tmp, a.GetPrecision());
  }

  void set_zero (MpfciClass& a)
  {
    MpfiClass x(0, a.GetPrecision());
    set_zero(x);
    MpfciClass tmp(x, x, a.GetPrecision() );
    set_Mpfci(a, tmp, a.GetPrecision());
  }

// -----------------------------------------------------------------------------------
// --------  Operators for calculating the intersection of a and b  ------------------
// --------       if (a & b) is empty [@NaN,@NaN] is returned       ------------------
// -- The precision of the returned interval is the maximum of the precision of a,b --
// -----------------------------------------------------------------------------------

  MpfciClass operator & (const MpfciClass& a, const MpfciClass& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= b.GetPrecision())
      prec = a.GetPrecision();
    else prec = b.GetPrecision();
    MpfciClass res(0.0, prec);

    if ( mpfi_cmp (a.mpfi_re, b.mpfi_re)==0 && mpfi_cmp (a.mpfi_im, b.mpfi_im)==0) // Intersection is not empty
    {
      mpfi_intersect (res.mpfi_re, a.mpfi_re, b.mpfi_re);
      mpfi_intersect (res.mpfi_im, a.mpfi_im, b.mpfi_im);
    }
    else set_nan (res);
    return res;
  }

//  MpfciClass operator & (const MpfciClass& a, const cxsc::cinterval& b)
//  {
//    MpfciClass tmp(b, 53);
//    return (a & tmp);
//  }

  MpfciClass operator & (const MpfciClass& a, const MPFR::MpfcClass& b)
  {
    MpfciClass tmp(b, b.GetPrecision());
    return (a & tmp);
  }

//  MpfciClass operator & (const MpfciClass& a, const cxsc::complex& b)
//  {
//    MpfciClass tmp(b, 53);
//    return (a & tmp);
//  }

  MpfciClass operator & (const MpfciClass& a, const mpfi_t& b)
  {
    MpfciClass tmp(b, mpfi_get_prec(b));
    return (a & tmp);
  }

  MpfciClass operator & (const MpfciClass& a, const MpfiClass& b)
  {
    MpfciClass tmp(b, b.GetPrecision());
    return (a & tmp);
  }

//  MpfciClass operator & (const MpfciClass& a, const cxsc::interval& b)
//  {
//    MpfciClass tmp(b, 53);
//    return (a & tmp);
//  }

  MpfciClass operator & (const MpfciClass& a, const mpfr_t& b)
  {
    MpfciClass tmp(b, mpfr_get_prec(b));
    return (a & tmp);
  }

  MpfciClass operator & (const MpfciClass& a, const MPFR::MpfrClass& b)
  {
    MpfciClass tmp(b, b.GetPrecision());
    return (a & tmp);
  }

  MpfciClass operator & (const MpfciClass& a, const double& b)
  {
    PrecisionType prec=53;
    MpfciClass tmp(b, prec);
    return (a & tmp);
  }

//  MpfciClass operator & (const MpfciClass& a, const cxsc::real& b)
//  {
//    PrecisionType prec=53;
//    MpfciClass tmp(b, prec);
//    return (a & tmp);
//  }

  MpfciClass operator & (const MpfciClass& a, const int b)
  {
    PrecisionType prec=64;
    MpfciClass tmp(b, prec);
    return (a & tmp);
  }

//  MpfciClass operator & (const cxsc::cinterval& b, const MpfciClass& a)
//  {
//    return (a & b);
//  }

  MpfciClass operator & (const MPFR::MpfcClass& b, const MpfciClass& a)
  {
    return (a & b);
  }

//  MpfciClass operator & (const cxsc::complex& b, const MpfciClass& a)
//  {
//    return (a & b);
//  }

  MpfciClass operator & (const mpfi_t& b, const MpfciClass& a)
  {
    return (a & b);
  }

  MpfciClass operator & (const MpfiClass& b, const MpfciClass& a)
  {
    return (a & b);
  }

//  MpfciClass operator & (const cxsc::interval& b, const MpfciClass& a)
//  {
//    return (a & b);
//  }

  MpfciClass operator & (const mpfr_t& b, const MpfciClass& a)
  {
    return (a & b);
  }

  MpfciClass operator & (const MPFR::MpfrClass& b, const MpfciClass& a)
  {
    return (a & b);
  }

  MpfciClass operator & (const double& b, const MpfciClass& a)
  {
    return (a & b);
  }

//  MpfciClass operator & (const cxsc::real& b, const MpfciClass& a)
//  {
//    return (a & b);
//  }

  MpfciClass operator & (const int b, const MpfciClass& a)
  {
    return (a & b);
  }

// --------------------------------------------------------------------------

  MpfciClass & operator &= ( MpfciClass& a, const MpfciClass& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a&b, prec);
    return a;
  }

//  MpfciClass & operator &= ( MpfciClass& a, const cxsc::cinterval& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a&b, prec);
//    return a;
//  }

  MpfciClass & operator &= (MpfciClass& a, const MPFR::MpfcClass& b)
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a&b, prec);
    return a;
  }

//  MpfciClass & operator &= ( MpfciClass& a, const cxsc::complex& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a&b, prec);
//    return a;
//  }

  MpfciClass & operator &= ( MpfciClass& a, const mpfi_t& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (mpfi_get_prec(b) > prec) prec = mpfi_get_prec(b);
    set_Mpfci(a, a&b, prec);
    return a;
  }

  MpfciClass & operator &= ( MpfciClass& a, const MpfiClass& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a&b, prec);
    return a;
  }

//  MpfciClass & operator &= ( MpfciClass& a, const cxsc::interval& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a&b, prec);
//    return a;
//  }

  MpfciClass & operator &= ( MpfciClass& a, const mpfr_t& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (mpfr_get_prec(b) > prec) prec = mpfr_get_prec(b);
    set_Mpfci(a, a&b, prec);
    return a;
  }

  MpfciClass & operator &= ( MpfciClass& a, const MPFR::MpfrClass& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a&b, prec);
    return a;
  }

  MpfciClass & operator &= ( MpfciClass& a, const double& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (53 > prec) prec = 53;
    set_Mpfci(a, a&b, prec);
    return a;
  }

//  MpfciClass & operator &= ( MpfciClass& a, const cxsc::real& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a&b, prec);
//    return a;
//  }

  MpfciClass & operator &= ( MpfciClass& a, const int b )
  {
    PrecisionType prec = a.GetPrecision();
    if (64 > prec) prec = 64;
    set_Mpfci(a, a&b, prec);
    return a;
  }

// ----------------------------------------------------------------------------------
// --------  Operators for calculating the convex hull of a and b  ------------------
// ----------------------------------------------------------------------------------

  MpfciClass operator | (const MpfciClass& a, const MpfciClass& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= b.GetPrecision())
         prec = a.GetPrecision();
    else prec = b.GetPrecision();

    MpfciClass res( Re(a)|Re(b), Im(a)|Im(b), prec);
    return res;
  }

//  MpfciClass operator | (const MpfciClass& a, const cxsc::cinterval& b)
//  {
//    PrecisionType prec;
//    if(a.GetPrecision() >= 53)
//         prec = a.GetPrecision();
//    else prec = 53;
//
//    MpfciClass res( Re(a)|Re(b), Im(a)|Im(b), prec);
//    return res;
//  }

  MpfciClass operator | (const MpfciClass& a, const MPFR::MpfcClass& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= b.GetPrecision())
         prec = a.GetPrecision();
    else prec = b.GetPrecision();

    MpfciClass res( Re(a)|Re(b), Im(a)|Im(b), prec);
    return res;
  }

//  MpfciClass operator | (const MpfciClass& a, const cxsc::complex& b)
//  {
//    PrecisionType prec;
//    if(a.GetPrecision() >= 53)
//         prec = a.GetPrecision();
//    else prec = 53;
//
//    MpfciClass res( Re(a)|Re(b), Im(a)|Im(b), prec);
//    return res;
//  }

  MpfciClass operator | (const MpfciClass& a, const mpfi_t& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= mpfi_get_prec(b))
         prec = a.GetPrecision();
    else prec = mpfi_get_prec(b);

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

  MpfciClass operator | (const MpfciClass& a, const MpfiClass& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= b.GetPrecision())
         prec = a.GetPrecision();
    else prec = b.GetPrecision();

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

//  MpfciClass operator | (const MpfciClass& a, const cxsc::interval& b)
//  {
//    PrecisionType prec;
//    if(a.GetPrecision() >= 53)
//         prec = a.GetPrecision();
//    else prec = 53;
//
//    MpfciClass res( Re(a)|b, Im(a)|0, prec);
//    return res;
//  }

  MpfciClass operator | (const MpfciClass& a, const mpfr_t& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= mpfr_get_prec(b))
         prec = a.GetPrecision();
    else prec = mpfr_get_prec(b);

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

  MpfciClass operator | (const MpfciClass& a, const MPFR::MpfrClass& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= b.GetPrecision())
         prec = a.GetPrecision();
    else prec = b.GetPrecision();

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

  MpfciClass operator | (const MpfciClass& a, const double& b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= 53)
         prec = a.GetPrecision();
    else prec = 53;

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

//  MpfciClass operator | (const MpfciClass& a, const cxsc::real& b)
//  {
//    PrecisionType prec;
//    if(a.GetPrecision() >= 53)
//         prec = a.GetPrecision();
//    else prec = 53;
//
//    MpfciClass res( Re(a)|b, Im(a)|0, prec);
//    return res;
//  }

  MpfciClass operator | (const MpfciClass& a, const int b)
  {
    PrecisionType prec;
    if(a.GetPrecision() >= 64)
         prec = a.GetPrecision();
    else prec = 64;

    MpfciClass res( Re(a)|b, Im(a)|0, prec);
    return res;
  }

  // -----------------------------------------------------------------------------

//  MpfciClass operator | (const cxsc::cinterval& b, const MpfciClass& a)
//  {
//    return (a|b);
//  }

  MpfciClass operator | (const MPFR::MpfcClass& b, const MpfciClass& a)
  {
    return (a|b);
  }

//  MpfciClass operator | (const cxsc::complex& b, const MpfciClass& a)
//  {
//    return (a|b);
//  }

  MpfciClass operator | (const mpfi_t& b, const MpfciClass& a)
  {
    return (a|b);
  }

  MpfciClass operator | (const MpfiClass& b, const MpfciClass& a)
  {
    return (a|b);
  }

//  MpfciClass operator | (const cxsc::interval& b, const MpfciClass& a)
//  {
//    return (a|b);
//  }

  MpfciClass operator | (const mpfr_t& b, const MpfciClass& a)
  {
    return (a|b);
  }

  MpfciClass operator | (const MPFR::MpfrClass& b, const MpfciClass& a)
  {
    return (a|b);
  }

  MpfciClass operator | (const double& b, const MpfciClass& a)
  {
    return (a|b);
  }

//  MpfciClass operator | (const cxsc::real& b, const MpfciClass& a)
//  {
//    return (a|b);
//  }

    MpfciClass operator | (const int b, const MpfciClass& a)
  {
    return (a|b);
  }

  MpfciClass & operator |= (MpfciClass& a, const MpfciClass& b)
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a|b, prec);
    return a;
  }

//  MpfciClass & operator |= ( MpfciClass& a, const cxsc::cinterval& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a|b, prec);
//    return a;
//  }

  MpfciClass & operator |= (MpfciClass& a, const MPFR::MpfcClass& b)
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = a.GetPrecision();
    set_Mpfci(a, a|b, prec);
    return a;
  }

//  MpfciClass & operator |= ( MpfciClass& a, const cxsc::complex& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a|b, prec);
//    return a;
//  }

  MpfciClass & operator |= ( MpfciClass& a, const mpfi_t& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (mpfi_get_prec(b) > prec) prec = mpfi_get_prec(b);
    set_Mpfci(a, a|b, prec);
    return a;
  }

  MpfciClass & operator |= ( MpfciClass& a, const MpfiClass& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a|b, prec);
    return a;
  }

//  MpfciClass & operator |= ( MpfciClass& a, const cxsc::interval& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a|b, prec);
//    return a;
//  }

  MpfciClass & operator |= ( MpfciClass& a, const mpfr_t& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (mpfr_get_prec(b) > prec) prec = mpfr_get_prec(b);
    set_Mpfci(a, a|b, prec);
    return a;
  }

  MpfciClass & operator |= ( MpfciClass& a, const MPFR::MpfrClass& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    set_Mpfci(a, a|b, prec);
    return a;
  }

  MpfciClass & operator |= ( MpfciClass& a, const double& b )
  {
    PrecisionType prec = a.GetPrecision();
    if (53 > prec) prec = 53;
    set_Mpfci(a, a|b, prec);
    return a;
  }

//  MpfciClass & operator |= ( MpfciClass& a, const cxsc::real& b )
//  {
//    PrecisionType prec = a.GetPrecision();
//    if (53 > prec) prec = 53;
//    set_Mpfci(a, a|b, prec);
//    return a;
//  }

  MpfciClass & operator |= ( MpfciClass& a, const int b )
  {
    PrecisionType prec = a.GetPrecision();
    if (64 > prec) prec = 64;
    set_Mpfci(a, a|b, prec);
    return a;
  }

// ------------------------------------------------------------------
// --------------------- Arithmetic Operators -----------------------
// ------------------------------------------------------------------

// ---------------------- Monadic Operators -------------------------

  MpfciClass operator - (const MpfciClass& z)
  {
    MpfciClass val(0, z.GetPrecision());
    mpfi_neg(val.mpfi_re, z.mpfi_re);
    mpfi_neg(val.mpfi_im, z.mpfi_im);
    return val;
  }

  MpfciClass operator + (const MpfciClass& z)
  {
    return z;
  }

// ---------------------- Dyadic Operators -------------------------

// ------------------------------------------------------------------
// ------------------------- Addition -------------------------------
// ------------------------------------------------------------------

  MpfciClass operator + (const MpfciClass& z, const MpfciClass& w)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add(res.mpfi_re, z.mpfi_re, w.mpfi_re);
    mpfi_add(res.mpfi_im, z.mpfi_im, w.mpfi_im);
    return res;
  }

//  MpfciClass operator + (const MpfciClass& z, const cxsc::cinterval& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfciClass tmp(x, 53);
//    mpfi_add(res.mpfi_re, z.mpfi_re, tmp.mpfi_re);
//    mpfi_add(res.mpfi_im, z.mpfi_im, tmp.mpfi_im);
//    return res;
//  }

  MpfciClass operator + (const MpfciClass& z, const MPFR::MpfcClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add_fr(res.mpfi_re, z.mpfi_re, getvalueRe(x));
    mpfi_add_fr(res.mpfi_im, z.mpfi_im, getvalueIm(x));
    return res;
  }

//  MpfciClass operator + (const MpfciClass& z, const cxsc::complex& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_add_d(res.mpfi_re, z.mpfi_re, _double(Re(x)));
//    mpfi_add_d(res.mpfi_im, z.mpfi_im, _double(Im(x)));
//    return res;
//  }

  MpfciClass operator + (const MpfciClass& z, const mpfi_t& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator + (const MpfciClass& z, const MpfiClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator + (const MpfciClass& z, const cxsc::interval& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfiClass tmp(x, 53);
//    mpfi_add(res.mpfi_re, z.mpfi_re, tmp.GetValue());
//    mpfi_set(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator + (const MpfciClass& z, const mpfr_t& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add_fr(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator + (const MpfciClass& z, const MPFR::MpfrClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add_fr(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator + (const MpfciClass& z, const double& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add_d(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator + (const MpfciClass& z, const cxsc::real& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_add_d(res.mpfi_re, z.mpfi_re, _double(x));
//    mpfi_set(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator + (const MpfciClass& z, const int x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_add_si(res.mpfi_re, z.mpfi_re, (long int)x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator + (const cxsc::cinterval& x, const MpfciClass& z)
//  {
//    return (z+x);
//  }

  MpfciClass operator + (const MPFR::MpfcClass& x, const MpfciClass& z)
  {
    return (z+x);
  }

//  MpfciClass operator + (const cxsc::complex& x,   const MpfciClass& z)
//  {
//    return (z+x);
//  }

  MpfciClass operator + (const mpfi_t& x,          const MpfciClass& z)
  {
    return (z+x);
  }

  MpfciClass operator + (const MpfiClass& x,       const MpfciClass& z)
  {
    return (z+x);
  }

//  MpfciClass operator + (const cxsc::interval& x,  const MpfciClass& z)
//  {
//    return (z+x);
//  }

  MpfciClass operator + (const mpfr_t& x,          const MpfciClass& z)
  {
    return (z+x);
  }

  MpfciClass operator + (const MPFR::MpfrClass& x, const MpfciClass& z)
  {
    return (z+x);
  }

  MpfciClass operator + (const double& x,          const MpfciClass& z)
  {
    return (z+x);
  }

//  MpfciClass operator + (const cxsc::real& x,      const MpfciClass& z)
//  {
//    return (z+x);
//  }

  MpfciClass operator + (const int x,              const MpfciClass& z)
  {
    return (z+x);
  }


  MpfciClass& operator += (MpfciClass& z, const MpfciClass& x)
  {
    z = z + x;
    return z;
  }

//  MpfciClass& operator += (MpfciClass& z, const cxsc::cinterval& x)
//  {
//    z = z + x;
//    return z;
//  }

  MpfciClass& operator += (MpfciClass& z, const MPFR::MpfcClass& x)
  {
    z = z + x;
    return z;
  }

//  MpfciClass& operator += (MpfciClass& z, const cxsc::complex& x)
//  {
//    z = z + x;
//    return z;
//  }

  MpfciClass& operator += (MpfciClass& z, const mpfi_t& x)
  {
    z = z + x;
    return z;
  }

  MpfciClass& operator += (MpfciClass& z, const MpfiClass& x)
  {
    z = z + x;
    return z;
  }

//  MpfciClass& operator += (MpfciClass& z, const cxsc::interval& x)
//  {
//    z = z + x;
//    return z;
//  }

  MpfciClass& operator += (MpfciClass& z, const mpfr_t& x)
  {
    z = z + x;
    return z;
  }

  MpfciClass& operator += (MpfciClass& z, const MPFR::MpfrClass& x)
  {
    z = z + x;
    return z;
  }

  MpfciClass& operator += (MpfciClass& z, const double& x)
  {
    z = z + x;
    return z;
  }

//  MpfciClass& operator += (MpfciClass& z, const cxsc::real& x)
//  {
//    z = z + x;
//    return z;
//  }

  MpfciClass& operator += (MpfciClass& z, const int x)
  {
    z = z + x;
    return z;
  }

// ------------------------------------------------------------------
// ------------------------- Subtraktion ----------------------------
// ------------------------------------------------------------------

  MpfciClass operator - (const MpfciClass& z, const MpfciClass& w)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub(res.mpfi_re, z.mpfi_re, w.mpfi_re);
    mpfi_sub(res.mpfi_im, z.mpfi_im, w.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const MpfciClass& z, const cxsc::cinterval& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfciClass tmp(x, 53);
//    mpfi_sub(res.mpfi_re, z.mpfi_re, tmp.mpfi_re);
//    mpfi_sub(res.mpfi_im, z.mpfi_im, tmp.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const MpfciClass& z, const MPFR::MpfcClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub_fr(res.mpfi_re, z.mpfi_re, getvalueRe(x));
    mpfi_sub_fr(res.mpfi_im, z.mpfi_im, getvalueIm(x));
    return res;
  }


//  MpfciClass operator - (const MpfciClass& z, const cxsc::complex& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_sub_d(res.mpfi_re, z.mpfi_re, _double(Re(x)));
//    mpfi_sub_d(res.mpfi_im, z.mpfi_im, _double(Im(x)));
//    return res;
//  }

  MpfciClass operator - (const MpfciClass& z, const mpfi_t& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const MpfciClass& z, const MpfiClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const MpfciClass& z, const cxsc::interval& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfiClass tmp(x, 53);
//    mpfi_sub(res.mpfi_re, z.mpfi_re, tmp.GetValue());
//    mpfi_set(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const MpfciClass& z, const mpfr_t& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub_fr(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const MpfciClass& z, const MPFR::MpfrClass& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub_fr(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const MpfciClass& z, const double& x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub_d(res.mpfi_re, z.mpfi_re, x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const MpfciClass& z, const cxsc::real& x)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_sub_d(res.mpfi_re, z.mpfi_re, _double(x));
//    mpfi_set(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const MpfciClass& z, const int x)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub_si(res.mpfi_re, z.mpfi_re, (long int)x);
    mpfi_set(res.mpfi_im, z.mpfi_im);
    return res;
  }

// --------------------------------------------------------------------------

//  MpfciClass operator - (const cxsc::cinterval& x, const MpfciClass& z)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfciClass tmp(x, 53);
//    mpfi_sub(res.mpfi_re, tmp.mpfi_re, z.mpfi_re);
//    mpfi_sub(res.mpfi_im, tmp.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const MPFR::MpfcClass& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_fr_sub(res.mpfi_re, getvalueRe(x), z.mpfi_re);
    mpfi_fr_sub(res.mpfi_im, getvalueIm(x), z.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const cxsc::complex& x, const MpfciClass& z)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_d_sub(res.mpfi_re, _double(Re(x)), z.mpfi_re);
//    mpfi_d_sub(res.mpfi_im, _double(Im(x)), z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const mpfi_t& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub(res.mpfi_re, x, z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const MpfiClass& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_sub(res.mpfi_re, getvalue(x), z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const cxsc::interval& x, const MpfciClass& z)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    MpfiClass tmp(x, 53);
//    mpfi_sub(res.mpfi_re, tmp.GetValue(), z.mpfi_re);
//    mpfi_neg(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const mpfr_t& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_fr_sub(res.mpfi_re, x, z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const MPFR::MpfrClass& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_fr_sub(res.mpfi_re, getvalue(x), z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

  MpfciClass operator - (const double& x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_d_sub(res.mpfi_re, x, z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

//  MpfciClass operator - (const cxsc::real& x, const MpfciClass& z)
//  {
//    MpfciClass res(0);  // v with Current-Precision
//    mpfi_d_sub(res.mpfi_re, _double(x), z.mpfi_re);
//    mpfi_neg(res.mpfi_im, z.mpfi_im);
//    return res;
//  }

  MpfciClass operator - (const int x, const MpfciClass& z)
  {
    MpfciClass res(0);  // v with Current-Precision
    mpfi_si_sub(res.mpfi_re, (long int)x, z.mpfi_re);
    mpfi_neg(res.mpfi_im, z.mpfi_im);
    return res;
  }

// --------------------------------------------------------------------------------

  MpfciClass& operator -= (MpfciClass& z, const MpfciClass& x)
  {
    z = z - x;
    return z;
  }

//  MpfciClass& operator -= (MpfciClass& z, const cxsc::cinterval& x)
//  {
//    z = z - x;
//    return z;
//  }

  MpfciClass& operator -= (MpfciClass& z, const MPFR::MpfcClass& x)
  {
    z = z - x;
    return z;
  }

//  MpfciClass& operator -= (MpfciClass& z, const cxsc::complex& x)
//  {
//    z = z - x;
//    return z;
//  }

  MpfciClass& operator -= (MpfciClass& z, const mpfi_t& x)
  {
    z = z - x;
    return z;
  }

  MpfciClass& operator -= (MpfciClass& z, const MpfiClass& x)
  {
    z = z - x;
    return z;
  }

//  MpfciClass& operator -= (MpfciClass& z, const cxsc::interval& x)
//  {
//    z = z - x;
//    return z;
//  }

  MpfciClass& operator -= (MpfciClass& z, const mpfr_t& x)
  {
    z = z - x;
    return z;
  }

  MpfciClass& operator -= (MpfciClass& z, const MPFR::MpfrClass& x)
  {
    z = z - x;
    return z;
  }

  MpfciClass& operator -= (MpfciClass& z, const double& x)
  {
    z = z - x;
    return z;
  }

//  MpfciClass& operator -= (MpfciClass& z, const cxsc::real& x)
//  {
//    z = z - x;
//    return z;
//  }

  MpfciClass& operator -= (MpfciClass& z, const int x)
  {
    z = z - x;
    return z;
  }

// ------------------------------------------------------------------
// ------------------------- Multiplication -------------------------
// ------------------------------------------------------------------

  MpfciClass operator * (const MpfciClass& z, const MpfciClass& w)
  {
    MpfciClass res(scal_prod(Re(z), Re(w), -Im(z), Im(w)),
                   scal_prod(Re(z), Im(w), Im(z), Re(w)));
    return res;
  }

//  MpfciClass operator * (const MpfciClass& z, const cxsc::cinterval& x)
//  {
//    MpfciClass res(scal_prod(Re(z), Re(x), -Im(z), Im(x)),
//                   scal_prod(Re(z), Im(x), Im(z), Re(x)));
//    return res;
//  }

  MpfciClass operator * (const MpfciClass& z, const MPFR::MpfcClass& x)
  {
    MpfciClass w(x, x.GetPrecision());
    MpfciClass res(scal_prod(Re(z), Re(w), -Im(z), Im(w)),
                   scal_prod(Re(z), Im(w),  Im(z), Re(w)));
    return res;
  }

//  MpfciClass operator * (const MpfciClass& z, const cxsc::complex& x)
//  {
//    cxsc::cinterval w(x);
//    MpfciClass res(scal_prod(Re(z), Re(w), -Im(z), Im(w)),
//                   scal_prod(Re(z), Im(w),  Im(z), Re(w)));
//    return res;
//  }

  MpfciClass operator * (const MpfciClass& z, const mpfi_t& x)
  {
    MpfciClass res(0);
    mpfi_mul(res.mpfi_re, z.mpfi_re, x);
    mpfi_mul(res.mpfi_im, z.mpfi_im, x);
    return res;
  }

  MpfciClass operator * (const MpfciClass& z, const MpfiClass& x)
  {
    MpfciClass res(0);
    mpfi_mul(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_mul(res.mpfi_im, z.mpfi_im, getvalue(x));
    return res;
  }

//  MpfciClass operator * (const MpfciClass& z, const cxsc::interval& x)
//  {
//    MpfciClass res(0);
//    MpfiClass tmp(x, 53);
//    mpfi_mul(res.mpfi_re, z.mpfi_re, tmp.GetValue());
//    mpfi_mul(res.mpfi_im, z.mpfi_im, tmp.GetValue());
//    return res;
//  }

  MpfciClass operator * (const MpfciClass& z, const mpfr_t& x)
  {
    MpfciClass res(0);
    mpfi_mul_fr(res.mpfi_re, z.mpfi_re, x);
    mpfi_mul_fr(res.mpfi_im, z.mpfi_im, x);
    return res;
  }

  MpfciClass operator * (const MpfciClass& z, const MPFR::MpfrClass& x)
  {
    MpfciClass res(0);
    mpfi_mul_fr(res.mpfi_re, z.mpfi_re, getvalue(x));
    mpfi_mul_fr(res.mpfi_im, z.mpfi_im, getvalue(x));
    return res;
  }

  MpfciClass operator * (const MpfciClass& z, const double& x)
  {
    MpfciClass res(0);
    mpfi_mul_d(res.mpfi_re, z.mpfi_re, x);
    mpfi_mul_d(res.mpfi_im, z.mpfi_im, x);
    return res;
  }

//  MpfciClass operator * (const MpfciClass& z, const cxsc::real& x)
//  {
//    MpfciClass res(0);
//    mpfi_mul_d(res.mpfi_re, z.mpfi_re, _double(x));
//    mpfi_mul_d(res.mpfi_im, z.mpfi_im, _double(x));
//    return res;
//  }

  MpfciClass operator * (const MpfciClass& z, const int x)
  {
    MpfciClass res(0);
    mpfi_mul_si(res.mpfi_re, z.mpfi_re, (long int)x);
    mpfi_mul_si(res.mpfi_im, z.mpfi_im, (long int)x);
    return res;
  }

//  MpfciClass operator * (const cxsc::cinterval& x, const MpfciClass& z)
//  {
//    return (z*x);
//  }

  MpfciClass operator * (const MPFR::MpfcClass& x, const MpfciClass& z)
  {
    return (z*x);
  }

//  MpfciClass operator * (const cxsc::complex& x,   const MpfciClass& z)
//  {
//    return (z*x);
//  }

  MpfciClass operator * (const mpfi_t& x,          const MpfciClass& z)
  {
    return (z*x);
  }

  MpfciClass operator * (const MpfiClass& x,       const MpfciClass& z)
  {
    return (z*x);
  }

//  MpfciClass operator * (const cxsc::interval& x,  const MpfciClass& z)
//  {
//    return (z*x);
//  }

  MpfciClass operator * (const mpfr_t& x,          const MpfciClass& z)
  {
    return (z*x);
  }

  MpfciClass operator * (const MPFR::MpfrClass& x, const MpfciClass& z)
  {
    return (z*x);
  }

  MpfciClass operator * (const double& x,          const MpfciClass& z)
  {
    return (z*x);
  }

//  MpfciClass operator * (const cxsc::real& x,      const MpfciClass& z)
//  {
//    return (z*x);
//  }

  MpfciClass operator * (const int x,              const MpfciClass& z)
  {
    return (z*x);
  }

  MpfciClass& operator *= (MpfciClass& z, const MpfciClass& x)
  {
    z = z * x;
    return z;
  }

//  MpfciClass& operator *= (MpfciClass& z, const cxsc::cinterval& x)
//  {
//    z = z * x;
//    return z;
//  }

  MpfciClass& operator *= (MpfciClass& z, const MPFR::MpfcClass& x)
  {
    z = z * x;
    return z;
  }

//  MpfciClass& operator *= (MpfciClass& z, const cxsc::complex& x)
//  {
//    z = z * x;
//    return z;
//  }

  MpfciClass& operator *= (MpfciClass& z, const mpfi_t& x)
  {
    z = z * x;
    return z;
  }

  MpfciClass& operator *= (MpfciClass& z, const MpfiClass& x)
  {
    z = z * x;
    return z;
  }

//  MpfciClass& operator *= (MpfciClass& z, const cxsc::interval& x)
//  {
//    z = z * x;
//    return z;
//  }

  MpfciClass& operator *= (MpfciClass& z, const mpfr_t& x)
  {
    z = z * x;
    return z;
  }

  MpfciClass& operator *= (MpfciClass& z, const MPFR::MpfrClass& x)
  {
    z = z * x;
    return z;
  }

  MpfciClass& operator *= (MpfciClass& z, const double& x)
  {
    z = z * x;
    return z;
  }

//  MpfciClass& operator *= (MpfciClass& z, const cxsc::real& x)
//  {
//    z = z * x;
//    return z;
//  }

  MpfciClass& operator *= (MpfciClass& z, const int x)
  {
    z = z * x;
    return z;
  }

// ------------------------------------------------------------------------------------
// ------------------ Help functions for complex interval division --------------------
// ------------------------------------------------------------------------------------

// -------------- product() and quotient() are defined in mpficlass.cpp ---------------
  MpfiClass product (const MPFR::MpfrClass&, const MPFR::MpfrClass&,
                     const MPFR::MpfrClass&, const MPFR::MpfrClass&,
                     long int&);
  MPFR::MpfrClass quotient (const MpfiClass&, const long int,
                                       const MpfiClass&, const long int, const int);
// -------------------------------------------------------------------------------------

  MPFR::MpfrClass complex_division_f(
        MPFR::MpfrClass a, MPFR::MpfrClass b,
        MPFR::MpfrClass c, MPFR::MpfrClass d, const int rnd)
  {
    // Berechnet wird der mit rnd gerundete Wert von f:=(a*c+b*d)/(c*c+d*d) in der
    // Current-Praezision.
    // rnd = -1 --> abrunden;    rnd = 0 ---> ToNearest;    rnd = +1 ---> aufrunden;
    // Ist a oder b oder c oder d ein NaN oder +-Inf ---> NaN wird furueckgegeben.
    PrecisionType prec_old = MPFI::MpfiClass::GetCurrPrecision(),
                  prec = a.GetPrecision();
    if (b.GetPrecision()>prec) prec = b.GetPrecision();
    if (c.GetPrecision()>prec) prec = c.GetPrecision();
    if (d.GetPrecision()>prec) prec = d.GetPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(2*prec);
    // Ab jetzt Rechnung in doppelter Praezision:
    long int kz, kn;
    MpfiClass z, n;

    z = product( a,c,b,d, kz );
    n = product( c,c,d,d, kn );
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return quotient( z,kz, n,kn, rnd );
  } // complex_division_f

  bool MPFCI_complex_division_p[5];

  static const int max_expo = 1073741819;

  MPFR::MpfrClass minmax (int minimum, MPFR::MpfrClass a,  MPFR::MpfrClass b,
                                                  MPFR::MpfrClass y0, MpfiClass x, int i, int j)
  // Calculates the inner minimum or maximum of f = (ac+bd)/(cc+dd)
  // on the interval x = [c.inf,c.sup] ( a,b,d=y0 fixated ).
  // If minimum = true the minimum will be calculated, otherwise the maximum.
  {
    MPFR::MpfrClass ay0, MiMa;
    MpfiClass t,q,x0,two_Da(1);
    long int Da(0);

    if (minimum) MiMa = MPFR::MaxFloat();
    else MiMa = -MPFR::MaxFloat();

    if (Inf(x) == Sup(x))
    {
      if (MPFCI_complex_division_p[i] && MPFCI_complex_division_p[j])
        MiMa = complex_division_f (a, b, Inf(x), y0, 1-2*minimum);

      MPFCI_complex_division_p[i] = false;
      MPFCI_complex_division_p[j] = false;
    }
    else // x ist jetzt echtes Intervall
    if (a==0)
    {
      if ( b==0 || y0==0 )
      {
        MiMa = 0;
        MPFCI_complex_division_p[i] = false;
        MPFCI_complex_division_p[j] = false;
      }
      else // b*y0 != 0
      {
        if (0<x)
        {
          if ( minimum && sign(b) != sign(y0) )
          {
            MiMa = Inf( MpfiClass(b)/y0 );
            MPFCI_complex_division_p[i] = false;
            MPFCI_complex_division_p[j] = false;
          }
          else
            if ( !minimum && sign(b) == sign(y0) )
            {
              MiMa = Sup(MpfiClass(b)/y0);
              MPFCI_complex_division_p[i] = false;
              MPFCI_complex_division_p[j] = false;
            }
        }
      }
    }
    else // a != 0
    {
      if ( y0 == 0 )
      {
        if (minimum)
          MiMa = (a>0)? Inf( MpfiClass(a)/Sup(x) ) : Inf( MpfiClass(a)/Inf(x) );
        else
          MiMa = (a>0)? Sup( MpfiClass(a)/Inf(x) ) : Sup( MpfiClass(a)/Sup(x) );
        MPFCI_complex_division_p[i] = false;
        MPFCI_complex_division_p[j] = false;
      }
      else
      {
        // a  != 0.0 and y0 != 0.0,
        // Calculation of extrema points and minimum|maximum values;
        //  Calculation an inclusion t of: sign(a) * ( |b/a| + sqrt( 1+|b/a|^2 ) )

        MPFR::MpfrClass invf2(1.0);
        MpfiClass a_skal;
        // We first calculate:   t = |b/a| + sqrt( 1+|b/a|^2 );
        if ( sign(b) == 0 ) t = 1.0;
        else // a != 0  &&  b != 0
             // To avoid overflow by calculating an inclusion of
             // |b/a| + sqrt( 1+|b/a|^2 ) we must multiply a with 2^Da:
        {
 //         long int expo_diff = expo(b)-expo(a), ex;
          long int expo_diff = expo(b)-expo(a);

          a_skal = a;

          if (expo_diff > max_expo)
          {
            Da = expo_diff - max_expo; // Da > 0;
            // a must be multiplied by 2^Da to avoid overflow by calculating
            // an inclusion t of |b/a| + sqrt( 1+|b/a|^2 );
            times2pown (a_skal, Da);

            // Now calculating an inclusion two_Da of 2^(-Da):
            times2pown(two_Da, -Da);
          }
          q = MpfiClass(b) / a_skal;
          if (sign(b)*sign(a)<0) q = -q;
          // q: Inclusion of  |b/(a*2^Da)|;
          t = (Da>0)? q + sqrtx2y2(two_Da,q) : q + sqrt1px2(q);
        }

        if (sign(a)<0) t = -t; // Wegen SIGN(a)*{...} !

// if (Da > 0) the value t from the last line must additionally be
// multiplied with 2^Da, to get an inclusion of the expression:
//               sign(a) * ( |b/a| + sqrt( 1+|b/a|^2 ) );

// Now to a fall differentiation for min-,max- calculation:
// First we will calculate an inclusion x0 of the point of the
// relative minimum or maximum:

        ay0 = abs(y0);

        if ( (sign(b)==sign(y0)) == minimum )
        {
          x0 = ay0 * t;
          if (Da>0) times2pown(x0, Da);
          if (!isBounded(x0)) goto Ende;
        }
        else
        {
          x0 = ay0 / t;
          if (Da>0) times2pown(x0, -Da);
          if (!isBounded(x0)) goto Ende;
        }

        if (minimum)  x0 = -x0;

        if (x0<x)
        {
          q = a/x0;
          times2pown(q,-1);

          if (minimum) MiMa = Inf(q);
          else MiMa = Sup(q);

          MPFCI_complex_division_p[i] = false;
          MPFCI_complex_division_p[j] = false;
        }
      Ende:;
      } // y0 != 0
    }
    return MiMa;
  } // minmax()

MpfciClass cidiv(const MpfciClass& A, const MpfciClass& B)
{
   MPFR::MpfrClass realteilINF, realteilSUP,
                              imagteilINF, imagteilSUP;
   // da sonst eventuell zwischendurch illegale Intervalle entstehen
   MPFR::MpfrClass a0, b0;
   bool     a_repeat,b_repeat;
   int      i, rep, j;
   MPFR::MpfrClass AREINF, ARESUP, AIMINF, AIMSUP,
                              BREINF, BRESUP, BIMINF, BIMSUP;
   MpfiClass ARE, AIM, BRE, BIM;

   //  *** Berechnung des Realteils ***

   AREINF = Inf(Re(A));
   ARESUP = Sup(Re(A));
   AIMINF = Inf(Im(A));
   AIMSUP = Sup(Im(A));
   BREINF = Inf(Re(B));
   BRESUP = Sup(Re(B));
   BIMINF = Inf(Im(B));
   BIMSUP = Sup(Im(B));
   ARE    = Re(A);
   AIM    = Im(A);
   BRE    = Re(B);
   BIM    = Im(B);

   a_repeat = ( BREINF < 0) && ( 0 < BRESUP );
   b_repeat = ( BIMINF < 0) && ( 0 < BIMSUP );

   if (a_repeat || b_repeat)
      rep = 2;
   else
      rep = 1;

   if ( sign(BREINF) >= 0.0 )
      a0 = ARESUP;
   else
      a0 = AREINF;

   if ( sign(BIMINF) >= 0.0 )
      b0 = AIMSUP;
   else
      b0 = AIMINF;

   realteilSUP = -MPFR::MaxFloat();

   for (j=1; j<=rep; j++)
   {
      for (i=1; i<=4; MPFCI_complex_division_p[i++] = true);

      realteilSUP =
             MPFR::max( realteilSUP,
                   MPFR::max( MPFR::max( minmax( false, a0, b0, BIMINF, BRE, 1,2 ),
                                         minmax( false, a0, b0, BIMSUP, BRE, 3,4 ) ),
                        MPFR::max( minmax( false, b0, a0, BREINF, BIM, 1,3 ),
                                   minmax( false, b0, a0, BRESUP, BIM, 2,4 ) ) )
                );

      if (MPFCI_complex_division_p[1])
         realteilSUP = MPFR::max( realteilSUP, complex_division_f( a0, b0, BREINF, BIMINF, +1 ) );
      if (MPFCI_complex_division_p[2])
         realteilSUP = MPFR::max( realteilSUP, complex_division_f( a0, b0, BRESUP, BIMINF, +1 ) );
      if (MPFCI_complex_division_p[3])
         realteilSUP = MPFR::max( realteilSUP, complex_division_f( a0, b0, BREINF, BIMSUP, +1 ) );
      if (MPFCI_complex_division_p[4])
         realteilSUP = MPFR::max( realteilSUP, complex_division_f( a0, b0, BRESUP, BIMSUP, +1 ) );

      if (a_repeat)
         a0 = ARESUP;
      else if (b_repeat)
         b0 = AIMSUP;
   }

   if (sign(BREINF) >= 0.0)
      a0 = AREINF;
   else
      a0 = ARESUP;
   if (sign(BIMINF) >= 0.0)
      b0 = AIMINF;
   else
      b0 = AIMSUP;

   realteilINF = MPFR::MaxFloat();

   for (j=1; j<=rep; j++)
   {
      for (i=1; i<=4; MPFCI_complex_division_p[i++] = true);

      realteilINF =
              MPFR::min( realteilINF,
                   MPFR::min( MPFR::min( minmax( true, a0, b0, BIMINF, BRE, 1,2 ),
                             minmax( true, a0, b0, BIMSUP, BRE, 3,4 ) ),
                        MPFR::min( minmax( true, b0, a0, BREINF, BIM, 1,3 ),
                             minmax( true, b0, a0, BRESUP, BIM, 2,4 ) ) )
                 );

      if (MPFCI_complex_division_p[1])
         realteilINF = MPFR::min( realteilINF, complex_division_f( a0, b0, BREINF, BIMINF, -1 ) );
      if (MPFCI_complex_division_p[2])
         realteilINF = MPFR::min( realteilINF, complex_division_f( a0, b0, BRESUP, BIMINF, -1 ) );
      if (MPFCI_complex_division_p[3])
         realteilINF = MPFR::min( realteilINF, complex_division_f( a0, b0, BREINF, BIMSUP, -1 ) );
      if (MPFCI_complex_division_p[4])
         realteilINF = MPFR::min( realteilINF, complex_division_f( a0, b0, BRESUP, BIMSUP, -1 ) );

      if (a_repeat)
         a0 = AREINF;
      else if (b_repeat)
         b0 = AIMINF;
   }


   //  Calculation of the img. part:
   //  g(a, b, c, d) = complex_division_f(b, -a, c, d)

   a_repeat = ( BIMINF < 0 ) && ( 0 < BIMSUP );
   b_repeat = ( BREINF < 0 ) && ( 0 < BRESUP );

   //  IF a_repeat OR b_repeat THEN rep:= 2 ELSE rep:= 1;

   if (sign(BREINF) >= 0.0)
      b0 = AIMSUP;
   else
      b0 = AIMINF;

   if (sign(BIMINF) >= 0.0)
      a0 = AREINF;
   else
      a0 = ARESUP;

   imagteilSUP = -MPFR::MaxFloat();

   for (j=1; j<=rep; j++)
   {
      for (i=1; i<=4; MPFCI_complex_division_p[i++] = true) ;

      imagteilSUP =
              MPFR::max( imagteilSUP,
                   MPFR::max( MPFR::max( minmax( false,  b0, -a0, BIMINF, BRE, 1,2 ),
                                         minmax( false,  b0, -a0, BIMSUP, BRE, 3,4 ) ),
                        MPFR::max( minmax( false, -a0,  b0, BREINF, BIM, 1,3 ),
                                   minmax( false, -a0,  b0, BRESUP, BIM, 2,4 ) ) )
                 );

      if (MPFCI_complex_division_p[1])
         imagteilSUP = MPFR::max( imagteilSUP, complex_division_f( b0, -a0, BREINF, BIMINF, +1 ) );
      if (MPFCI_complex_division_p[2])
         imagteilSUP = MPFR::max( imagteilSUP, complex_division_f( b0, -a0, BRESUP, BIMINF, +1 ) );
      if (MPFCI_complex_division_p[3])
         imagteilSUP = MPFR::max( imagteilSUP, complex_division_f( b0, -a0, BREINF, BIMSUP, +1 ) );
      if (MPFCI_complex_division_p[4])
         imagteilSUP = MPFR::max( imagteilSUP, complex_division_f( b0, -a0, BRESUP, BIMSUP, +1 ) );

      if (b_repeat)
         b0 = AIMSUP;
      else if (a_repeat)
         a0 = AREINF  ;
   }

   if (sign(BREINF) >= 0.0)
      b0 = AIMINF;
   else
      b0 = AIMSUP;

   if (sign(BIMINF) >= 0.0)
      a0 = ARESUP;
   else
      a0 = AREINF;

   imagteilINF = MPFR::MaxFloat();

   for (j=1; j<=rep; j++)
   {
      for (i=1; i<=4; MPFCI_complex_division_p[i++] = true) ;

      imagteilINF =
              MPFR::min( imagteilINF,
                   MPFR::min( MPFR::min( minmax( true,  b0, -a0, BIMINF, BRE, 1,2 ),
                                         minmax( true,  b0, -a0, BIMSUP, BRE, 3,4 ) ),
                        MPFR::min( minmax( true, -a0,  b0, BREINF, BIM, 1,3 ),
                                   minmax( true, -a0,  b0, BRESUP, BIM, 2,4 ) ) )
                 );

      if (MPFCI_complex_division_p[1])
         imagteilINF = MPFR::min( imagteilINF, complex_division_f( b0, -a0, BREINF, BIMINF, -1 ) );
      if (MPFCI_complex_division_p[2])
         imagteilINF = MPFR::min( imagteilINF, complex_division_f( b0, -a0, BRESUP, BIMINF, -1 ) );
      if (MPFCI_complex_division_p[3])
         imagteilINF = MPFR::min( imagteilINF, complex_division_f( b0, -a0, BREINF, BIMSUP, -1 ) );
      if (MPFCI_complex_division_p[4])
         imagteilINF = MPFR::min( imagteilINF, complex_division_f( b0, -a0, BRESUP, BIMSUP, -1 ) );

      if (b_repeat)
         b0 = AIMINF;
      else if (a_repeat)
         a0 = ARESUP;
   }

   return MpfciClass(MpfiClass(realteilINF, realteilSUP),
                     MpfiClass(imagteilINF, imagteilSUP));

}  // cidiv

  MpfciClass P_cidiv(const MpfciClass& A, const MpfciClass& B)
  // A,B must be complex point intervals, this is not checked here !!
  // Only for the internal use!
  {
    MpfiClass re(complex_division_f( Inf(Re(A)), Inf(Im(A)), Inf(Re(B)), Inf(Im(B)), -1 ),
                 complex_division_f( Inf(Re(A)), Inf(Im(A)), Inf(Re(B)), Inf(Im(B)), 1  ));
    MpfiClass im(complex_division_f( Inf(Im(A)), -Inf(Re(A)), Inf(Re(B)), Inf(Im(B)), -1 ),
                 complex_division_f( Inf(Im(A)), -Inf(Re(A)), Inf(Re(B)), Inf(Im(B)), 1  ));

    return MpfciClass (re,im);
  } // P_cidiv

// ------------------------------------------------------------------
// ---------------------------- Division ----------------------------
// ------------------------------------------------------------------

  MpfciClass operator / (const MpfciClass& z, const MpfciClass& w)
  {
    MpfciClass res;
    if (0<=w)
    {
      set_nan(res);
      return res;
    }
    PrecisionType prec = z.GetPrecision(),
                  prec_old = MPFI::MpfiClass::GetCurrPrecision();
    if (prec<w.GetPrecision()) prec = w.GetPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    if ( isPoint(z) && isPoint(w) )
    // z,w sind beide komplexwertige Punktintervalle:
    {
      res = P_cidiv(z,w);
    }
    else
      res = cidiv(z,w);

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return res;
  }

//  MpfciClass operator / (const MpfciClass& z, const cxsc::cinterval& x)
//  {
//    return z / MpfciClass(x, 53);
//  }

  MpfciClass operator / (const MpfciClass& z, const MPFR::MpfcClass& x)
  {
    return z / MpfciClass(x, x.GetPrecision());
  }

//  MpfciClass operator / (const MpfciClass& z, const cxsc::complex& x)
//  {
//    return z / MpfciClass(x, 53);
//  }

  MpfciClass operator / (const MpfciClass& z, const mpfi_t& x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }

  MpfciClass operator / (const MpfciClass& z, const MpfiClass& x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }

//  MpfciClass operator / (const MpfciClass& z, const cxsc::interval& x)
//  {
//    return MpfciClass(Re(z)/x, Im(z)/x);
//  }

  MpfciClass operator / (const MpfciClass& z, const mpfr_t& x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }

  MpfciClass operator / (const MpfciClass& z, const MPFR::MpfrClass& x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }

  MpfciClass operator / (const MpfciClass& z, const double& x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }

//  MpfciClass operator / (const MpfciClass& z, const cxsc::real& x)
//  {
//    return MpfciClass(Re(z)/x, Im(z)/x);
//  }

  MpfciClass operator / (const MpfciClass& z, const int x)
  {
    return MpfciClass(Re(z)/x, Im(z)/x);
  }


//  MpfciClass operator / (const cxsc::cinterval& x, const MpfciClass& z)
//  {
//    return MpfciClass(x, 53)/z;
//  }

  MpfciClass operator / (const MPFR::MpfcClass& x, const MpfciClass& z)
  {
    return MpfciClass(x, x.GetPrecision())/z;
  }

//  MpfciClass operator / (const cxsc::complex& x, const MpfciClass& z)
//  {
//    return MpfciClass(x, 53)/z;
//  }

  MpfciClass operator / (const mpfi_t& x, const MpfciClass& z)
  {
    return MpfciClass(x, mpfi_get_prec(x))/z;
  }

  MpfciClass operator / (const MpfiClass& x, const MpfciClass& z)
  {
    return MpfciClass(x, x.GetPrecision())/z;
  }

//  MpfciClass operator / (const cxsc::interval& x, const MpfciClass& z)
//  {
//    return MpfciClass(x, 53)/z;
//  }

  MpfciClass operator / (const mpfr_t& x, const MpfciClass& z)
  {
    return MpfciClass(x, mpfr_get_prec(x))/z;
  }

  MpfciClass operator / (const MPFR::MpfrClass& x, const MpfciClass& z)
  {
    return MpfciClass(x, x.GetPrecision())/z;
  }

  MpfciClass operator / (const double& x, const MpfciClass& z)
  {
    PrecisionType prec = 53;
    return MpfciClass(x, prec)/z;
  }

//  MpfciClass operator / (const cxsc::real& x, const MpfciClass& z)
//  {
//    PrecisionType prec = 53;
//    return MpfciClass(x, 53)/z;
//  }

  MpfciClass operator / (const int x, const MpfciClass& z)
  {
    PrecisionType prec = 64;
    return MpfciClass(x, prec)/z;
  }

  MpfciClass& operator /= (MpfciClass& z, const MpfciClass& x)
  {
    z = z / x;
    return z;
  }

//  MpfciClass& operator /= (MpfciClass& z, const cxsc::cinterval& x)
//  {
//    z = z / x;
//    return z;
//  }

  MpfciClass& operator /= (MpfciClass& z, const MPFR::MpfcClass& x)
  {
    z = z / x;
    return z;
  }

//  MpfciClass& operator /= (MpfciClass& z, const cxsc::complex& x)
//  {
//    z = z / x;
//    return z;
//  }

  MpfciClass& operator /= (MpfciClass& z, const mpfi_t& x)
  {
    z = z / x;
    return z;
  }

  MpfciClass& operator /= (MpfciClass& z, const MpfiClass& x)
  {
    z = z / x;
    return z;
  }

//  MpfciClass& operator /= (MpfciClass& z, const cxsc::interval& x)
//  {
//    z = z / x;
//    return z;
//  }

  MpfciClass& operator /= (MpfciClass& z, const mpfr_t& x)
  {
    z = z / x;
    return z;
  }

  MpfciClass& operator /= (MpfciClass& z, const MPFR::MpfrClass& x)
  {
    z = z / x;
    return z;
  }

  MpfciClass& operator /= (MpfciClass& z, const double& x)
  {
    z = z / x;
    return z;
  }

//  MpfciClass& operator /= (MpfciClass& z, const cxsc::real& x)
//  {
//    z = z / x;
//    return z;
//  }

  MpfciClass& operator /= (MpfciClass& z, const int x)
  {
    z = z / x;
    return z;
  }


// ------------------------------------------------------------------
// -------------------- Vergleiche: < -------------------------------
// ------------------------------------------------------------------

  bool operator < (const MpfciClass& v, const MpfciClass& w)
  {
    return ( Re(v)<Re(w) && Im(v)<Im(w) );
  }

//  bool operator < (const MpfciClass& v, const cxsc::cinterval& w)
//  {
//    return ( Re(v)<Re(w) && Im(v)<Im(w) );
//  }

  bool operator < (const MpfciClass& v, const mpfi_t& w)
  {
    return ( Re(v)<w && isZero(Im(v)) );
  }

  bool operator < (const MpfciClass& v, const MpfiClass& w)
  {
    return ( Re(v)<w && isZero(Im(v)) );
  }

//  bool operator < (const MpfciClass& v, const cxsc::interval& w)
//  {
//    return ( Re(v)<w && isZero(Im(v)) );
//  }

//  bool operator < (const cxsc::cinterval& w, const MpfciClass& v)
//  {
//    return ( Re(w)<Re(v) && Im(w)<Im(v) );
//  }

  bool operator < (const mpfi_t& w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

  bool operator < (const MpfiClass& w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

//  bool operator < (const cxsc::interval& w, const MpfciClass& v)
//  {
//    return ( w<Re(v) && 0<Im(v) );
//  }

  bool operator < (const MPFR::MpfcClass& w, const MpfciClass& v)
  {
    return ( Re(w)<Re(v) && Im(w)<Im(v) );
  }

//  bool operator < (const cxsc::complex& w, const MpfciClass& v)
//  {
//    return ( Re(w)<Re(v) && Im(w)<Im(v) );
//  }

  bool operator < (const mpfr_t& w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

  bool operator < (const MPFR::MpfrClass& w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

  bool operator < (const double& w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

//  bool operator < (const cxsc::real& w, const MpfciClass& v)
//  {
//    return ( w<Re(v) && 0<Im(v) );
//  }

  bool operator < (const int w, const MpfciClass& v)
  {
    return ( w<Re(v) && 0<Im(v) );
  }

  bool operator <= (const MpfciClass& x, const MpfciClass& y)
  {
    return ( Re(x)<=Re(y) && Im(x)<=Im(y) );
  }

//  bool operator <= (const MpfciClass& x, const cxsc::cinterval& y)
//  {
//    return ( Re(x)<=Re(y) && Im(x)<=Im(y) );
//  }

  bool operator <= (const MpfciClass& x, const mpfi_t& y)
  {
    return ( Re(x)<=y && isZero(Im(x)) );
  }

  bool operator <= (const MpfciClass& x, const MpfiClass& y)
  {
    return ( Re(x)<=y && isZero(Im(x)) );
  }

//  bool operator <= (const MpfciClass& x, const cxsc::interval& y)
//  {
//    return ( Re(x)<=y && isZero(Im(x)) );
//  }

//  bool operator <= (const cxsc::cinterval& x, const MpfciClass& y)
//  {
//    return ( Re(x)<=Re(y) && Im(x)<=Im(y) );
//  }

  bool operator <= (const mpfi_t& x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

  bool operator <= (const MpfiClass& x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

//  bool operator <= (const cxsc::interval& x, const MpfciClass& y)
//  {
//    return ( x<=Re(y) && 0<=Im(y) );
//  }

  bool operator <= (const MPFR::MpfcClass& x, const MpfciClass& y)
  {
    return ( Re(x)<=Re(y) && Im(x)<=Im(y) );
  }

//  bool operator <= (const cxsc::complex& x, const MpfciClass& y)
//  {
//    return ( Re(x)<=Re(y) && Im(x)<=Im(y) );
//  }

  bool operator <= (const mpfr_t& x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

  bool operator <= (const MPFR::MpfrClass& x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

  bool operator <= (const double& x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

//  bool operator <= (const cxsc::real& x, const MpfciClass& y)
//  {
//    return ( x<=Re(y) && 0<=Im(y) );
//  }

  bool operator <= (const int x, const MpfciClass& y)
  {
    return ( x<=Re(y) && 0<=Im(y) );
  }

// ----------------------------------------------------------------------------------

  bool operator > (const MpfciClass& x, const MpfciClass& y)
  {
    return ( Re(x)>Re(y) && Im(x)>Im(y) );
  }

//  bool operator > (const MpfciClass& x, const cxsc::cinterval& y)
//  {
//    return ( Re(x)>Re(y) && Im(x)>Im(y) );
//  }

  bool operator > (const MpfciClass& x, const mpfi_t& y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

  bool operator > (const MpfciClass& x, const MpfiClass& y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

//  bool operator > (const MpfciClass& x, const cxsc::interval& y)
//  {
//    return ( Re(x)>y && 0<Im(x) );
//  }

//  bool operator > (const cxsc::cinterval& x, const MpfciClass& y)
//  {
//    return ( Re(x)>Re(y) && Im(x)>Im(y) );
//  }

  bool operator > (const mpfi_t& x, const MpfciClass& y)
  {
    return ( x>Re(y) && isZero(Im(y)) );
  }

  bool operator > (const MpfiClass& x, const MpfciClass& y)
  {
    return ( x>Re(y) && isZero(Im(y)) );
  }

//  bool operator > (const cxsc::interval& x, const MpfciClass& y)
//  {
//    return ( x>Re(y) && isZero(Im(y)) );
//  }

  bool operator > (const MpfciClass& x, const MPFR::MpfcClass& y)
  {
    return ( Re(x)>Re(y) && Im(x)>Im(y) );
  }

//  bool operator > (const MpfciClass& x, const cxsc::complex& y)
//  {
//    return ( Re(x)>Re(y) && Im(x)>Im(y) );
//  }

  bool operator > (const MpfciClass& x, const mpfr_t& y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

  bool operator > (const MpfciClass& x, const MPFR::MpfrClass& y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

  bool operator > (const MpfciClass& x, const double& y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

//  bool operator > (const MpfciClass& x, const cxsc::real& y)
//  {
//    return ( Re(x)>y && 0<Im(x) );
//  }

  bool operator > (const MpfciClass& x, const int y)
  {
    return ( Re(x)>y && 0<Im(x) );
  }

  bool operator >= (const MpfciClass& x, const MpfciClass& y)
  {
    return ( Re(x)>=Re(y) && Im(x)>=Im(y) );
  }

//  bool operator >= (const MpfciClass& x, const cxsc::cinterval& y)
//  {
//    return ( Re(x)>=Re(y) && Im(x)>=Im(y) );
//  }

  bool operator >= (const MpfciClass& x, const mpfi_t& y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }

  bool operator >= (const MpfciClass& x, const MpfiClass& y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }

//  bool operator >= (const MpfciClass& x, const cxsc::interval& y)
//  {
//    return ( Re(x)>=y && 0<=Im(x) );
//  }

//  bool operator >= (const cxsc::cinterval& x, const MpfciClass& y)
//  {
//    return ( Re(x)>=Re(y) && Im(x)>=Im(y) );
//  }

  bool operator >= (const mpfi_t& x, const MpfciClass& y)
  {
    return ( x>=Re(y) && isZero(Im(y)) );
  }

  bool operator >= (const MpfiClass& x, const MpfciClass& y)
  {
    return ( x>=Re(y) && isZero(Im(y)) );
  }

//  bool operator >= (const cxsc::interval& x, const MpfciClass& y)
//  {
//    return ( x>=Re(y) && isZero(Im(y)) );
//  }

  bool operator >= (const MpfciClass& x, const MPFR::MpfcClass& y)
  {
    return ( Re(x)>=Re(y) && Im(x)>=Im(y) );
  }

//  bool operator >= (const MpfciClass& x, const cxsc::complex& y)
//  {
//    return ( Re(x)>=Re(y) && Im(x)>=Im(y) );
//  }

  bool operator >= (const MpfciClass& x, const mpfr_t& y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }

  bool operator >= (const MpfciClass& x, const MPFR::MpfrClass& y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }

  bool operator >= (const MpfciClass& x, const double& y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }

//  bool operator >= (const MpfciClass& x, const cxsc::real& y)
//  {
//    return ( Re(x)>=y && 0<=Im(x) );
//  }

  bool operator >= (const MpfciClass& x, const int y)
  {
    return ( Re(x)>=y && 0<=Im(x) );
  }
//--------------------------------------------------------
//----------end Comparison operators----------------------
//--------------------------------------------------------


//--------------------------------------------------------
//----------start C-XSC Functions-------------------------
//--------------------------------------------------------

//  MpfciClass cinterval2Mpfci(const cxsc::cinterval& v)
//  {
//    MpfciClass res(v, 53);
//    return res;
//  }

  MpfciClass mpfi_t2Mpfci(const mpfi_t& v)
  {
    MpfciClass res(0, mpfi_get_prec(v));
    mpfi_set(res.mpfi_re, v);
    return res;
  }

  MpfciClass MpfiClass2Mpfci(const MpfiClass& v)
  {
    MpfciClass res(0, v.GetPrecision());
    mpfi_set(res.mpfi_re, getvalue(v));
    return res;
  }

//  MpfciClass interval2Mpfci(const cxsc::interval& v)
//  {
//    MpfciClass res(v, 53);
//    return res;
//  }

  MpfciClass mpfr_t2Mpfci(const mpfr_t& v)
  {
    MpfciClass res(0, mpfr_get_prec(v));
    mpfi_set_fr(res.mpfi_re, v);
    return res;
  }

  MpfciClass MpfrClass2Mpfci(const MPFR::MpfrClass& v)
  {
    MpfciClass res(0, v.GetPrecision());
    mpfi_set_fr(res.mpfi_re, getvalue(v));
    return res;
  }

//  MpfciClass real2Mpfci(const cxsc::real& v)
//  {
//    MpfciClass res(0, 53);
//    mpfi_set_d(res.mpfi_re, _double(v));
//    return res;
//  }

  MpfciClass double2Mpfci(const double& v)
  {
    MpfciClass res(0, 53);
    mpfi_set_d(res.mpfi_re, v);
    return res;
  }

  MpfciClass int2Mpfci(const int& v)
  {
    MpfciClass res(0, 64);
    mpfi_set_si(res.mpfi_re, v);
    return res;
  }

  MpfciClass string2Mpfci (const std::string& s, const PrecisionType prec)
  {
    MpfciClass res(s, prec);
    return res;
  }


// ---------------------------------------------------------------------
// ------------------ Mathematical Functions ---------------------------
// ---------------------------------------------------------------------

  MpfciClass conj(const MpfciClass& z)
  {
    MpfciClass res(z, z.GetPrecision());
    mpfi_neg (res.mpfi_im, res.mpfi_im);
    return res;
  }

  MpfiClass abs(const MpfciClass& z, PrecisionType prec)
  // Liefert |z| in der Praezision prec.
  // Ist prec nicht gesetzt, so wird |z| in der Current-Precision zurückgegeben.
  {
    MpfiClass val(0, prec);
    mpfi_hypot(val.GetValue(), z.mpfi_re, z.mpfi_im);
    return val;
  }

//---------------- Arg(Z): analytic argument function --------------------------------
//
//  (i)   Arg(Z) subset (-pi,pi);  Z in IC;
//  (ii)  Arg([0,0]) = 0.
//  (iii) Arg(Z) is undefined if Z contains negative real numbers.
//  (iv)  Otherwise, Arg(Z) is the interval hull of { Arg(z) | z in Z, z<>0 }.
//
  MpfiClass Arg(const MpfciClass& z, PrecisionType prec)
  // Liefert Arg in der Praezision prec.
  // Ist prec nicht gesetzt, so wird Arg in der Current-Precision zurückgegeben.
  {
    PrecisionType prec_new = z.GetPrecision(),
                  prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec_new<prec) prec_new = prec;
    if (prec_new<prec_old) prec_new = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec_new);
    MpfiClass res(0);

    MPFR::MpfrClass
      srez = Sup( Re(z) ),
      irez = Inf( Re(z) ),
      simz = Sup( Im(z) ),
      iimz = Inf( Im(z) );
    MpfiClass
      hxl(irez), hxu(srez), hyl(iimz), hyu(simz);
    MPFR::MpfrClass resl, resu;
    if (!isBounded(z))
    {
      MPFI::set_nan(res);
      goto Ende;
    }
    if (sign(iimz)>0)
    //  case I: Im(z) > 0
    {
      resl = ( sign(srez)>0? Inf( atan2(hyl,hxu)) :
             (sign(srez)<0? Inf( atan2(hyu,hxu) ) : Inf(MPFI::MpfiClass::Pi()/2)) );
      resu = ( sign(irez)>0? Sup( atan2(hyu,hxl)) :
             (sign(irez)<0? Sup( atan2(hyl,hxl) ) : Sup(MPFI::MpfiClass::Pi()/2)) );
      res = MpfiClass(resl, resu);
    }
    else
    {
      if (sign(simz)<0)
      // case II: Im(z) < 0
      {
        resl = ( sign(irez)<0? Inf(atan2(hyu,hxl)) :
               ( sign(irez)>0? Inf(atan2(hyl,hxl)) : -Sup(MPFI::MpfiClass::Pi()/2) ));
        resu = ( sign(srez)<0? Inf(atan2(hyl,hxu)) :
               ( sign(srez)>0? Inf(atan2(hyu,hxu)) : -Inf(MPFI::MpfiClass::Pi()/2) ));
        res = MpfiClass(resl, resu);
      }
      else // 0 in Im(z)
      {
        if (sign(irez)>0)
        // case III: Re(z) > 0
        {
          resl = ( sign(iimz)<0 ? Inf(atan2(hyl,hxl)) : MPFR::MpfrClass(0) );
          res  = MpfiClass(resl, Sup(atan2(hyu,hxl)));
        }
        else
        // z contains nonpositive real numbers
        {
          if (sign(irez)<0)
          // case IV: z contains negative real numbers
          {
            std::cerr << "Arg(z), z contains negative real numbers" << std::endl;
//            exit(1);
          }
          else // case V: 0 in z, but z doesn't contain negative real numbers
          {
            if (sign(srez)>0)
            // diam(Re(z)) > 0
            {
              resl = ( sign(iimz)<0 ? -Sup(MPFI::MpfiClass::Pi()/2) : MPFR::MpfrClass(0) );
              resu = ( sign(simz)>0 ?  Sup(MPFI::MpfiClass::Pi()/2) : MPFR::MpfrClass(0) );
              res = MpfiClass(resl, resu);
            }
            else // Re(z) == 0
            {
              if (iimz==0 && simz==0)
                res = MpfiClass(0);
              else
              {
                resl = ( sign(iimz)<0? -Sup(MPFI::MpfiClass::Pi()/2) :  Inf(MPFI::MpfiClass::Pi()/2) );
                resu = ( sign(simz)>0?  Sup(MPFI::MpfiClass::Pi()/2) : -Inf(MPFI::MpfiClass::Pi()/2) );
                res = MpfiClass(resl, resu);
              }
            }
          }
        }
      }
    }
    Ende:;
    res.RoundPrecision(prec);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  } // Arg()

  MpfiClass argp1(const MpfciClass& z, PrecisionType prec)
  // Liefert arg(1+Z) in der Praezision prec.
  // Ist prec nicht gesetzt, so wird arg(1+Z) in der Current-Precision zurückgegeben.
  {
    PrecisionType prec_new = z.GetPrecision(),
                  prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec_new<prec) prec_new = prec;
    MPFI::MpfiClass::SetCurrPrecision(prec_new);
    MpfiClass res;

    res = arg(1+z, prec);

    res.RoundPrecision(prec);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  } // argp1(z);


//-- arg: non-analytic argument function ------------------------------
//
//  (i)   arg(z) is defined for all z in IC.
//  (ii)  arg(z) subset [-pi,3*pi/2].
//  (iii) arg(z) == Arg(z) if Arg(z) is well-defined.
//
//  atan is the inverse function of tan(t), t in (-pi/2,pi/2).
//
  MpfiClass arg(const MpfciClass& z, PrecisionType prec)
  // Liefert arg in der Praezision prec.
  // Ist prec nicht gesetzt, so wird arg in der Current-Precision zurückgegeben.
  {
    PrecisionType prec_new = z.GetPrecision(),
                  prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec_new<prec) prec_new = prec;
    MPFI::MpfiClass::SetCurrPrecision(prec_new);
    MpfiClass res(0);

    MPFR::MpfrClass
      srez = Sup( Re(z) ),
      irez = Inf( Re(z) ),
      simz = Sup( Im(z) ),
      iimz = Inf( Im(z) );
    MPFR::MpfrClass resl, resu;

    if (!isBounded(z))
    {
      MPFI::set_nan(res);
      goto Ende;
    }

    if (sign(irez)<0 && sign(iimz)<=0 && sign(simz)>=0 )
    // z contains negative real values
    {
      if (sign(srez)>0)
      // 0 in z and 0 interior point of Re(z)
      {
        resl = ( sign(iimz)<0 ? -Sup(MPFI::MpfiClass::Pi()) : MPFR::MpfrClass(0));
        resu = ( ( sign(iimz)<0 && sign(simz)==0 ) ? MPFR::MpfrClass(0) : Sup(MPFI::MpfiClass::Pi()) );
        res = MpfiClass(resl, resu);
      }
      else
      // srez <= 0
      {
        if (iimz == simz)
          res = MPFI::MpfiClass::Pi();
        else
        // Sup( Re(z) ) <= 0, diam( Im(z) ) > 0
        {
          if (sign(srez)==0)
          {
            resl = ( sign(simz)>0 ? Inf(MPFI::MpfiClass::Pi()/2) : -Sup(MPFI::MpfiClass::Pi()) );
            resu = ( sign(iimz)<0 ? ( sign(simz)>0 ? Sup(1.5*MPFI::MpfiClass::Pi()) : -Inf(MPFI::MpfiClass::Pi()/2))
                                    : Sup( MPFI::MpfiClass::Pi() ) );
            res = MpfiClass(resl, resu);
          }
          else // Sup( Re(z) ) < 0  and  diam( Im(z) ) > 0
          {
            MpfiClass hyl(iimz), hyu(simz);
            resl = ( sign(simz)>0 ? Inf( atan2(hyu,MpfiClass(srez)) ) : -Sup( MPFI::MpfiClass::Pi() ) );
            resu = ( sign(iimz)<0 ? (sign(simz)>0 ? Sup( atan2(hyl,MpfiClass(srez)) + 2*MPFI::MpfiClass::Pi() ) :
                                                    Sup( atan2(hyl,MpfiClass(srez)) ) ) :
                                                    Sup(MPFI::MpfiClass::Pi()) );
            res = MpfiClass(resl, resu);
          }
        }
      }
    }
    else
    {
      res = Arg( z );
    }
    Ende:;
    res.RoundPrecision(prec);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  } // arg()


  MpfciClass sqr (const MpfciClass& z)
  {
    PrecisionType prec = z.GetPrecision(),
                  prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfiClass aRez(abs(Re(z))), aImz(abs(Im(z)));
    MPFR::MpfrClass resl, resr;

    resl = x2my2(Inf(aRez), Sup(aImz), RoundDown);
    resr = x2my2(Sup(aRez), Inf(aImz), RoundUp  );

    // Imaginaerteil: Die folgende Rechnung vermeidet einen vorzeitigen Unterlauf!
    mpfi_mul_si(aRez.GetValue(), getvalueRe(z), 2);
    if (!isBounded(aRez))
    {
      mpfi_mul_si(aRez.GetValue(), getvalueIm(z), 2);
      mpfi_mul(aRez.GetValue(), aRez.GetValue(), getvalueRe(z));
    }
    else
      mpfi_mul(aRez.GetValue(), aRez.GetValue(), getvalueIm(z));

    MpfciClass res( MpfiClass(resl, resr), aRez );
    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  }

//-----------------------------------------------------------------------------
//
//  Section 2: Logarithms
//
//-----------------------------------------------------------------------------

//-- Ln: analytic natural logarithm -------------------------------------------
//
//  Ln(z) is undefined if z contains zero; z must not touch the negative real
//  axis from below;
//
MpfciClass Ln( const MpfciClass& z )
{
  if (0<=z)
  {
    std::cerr << "MpfciClass Ln(const MpfciClass& z); z contains 0" << std::endl;
//    exit (1);
  }
  if ( Sup(Re(z))<0 && Inf(Im(z))<0 && Sup(Im(z))>=0 )
  {
    std::cerr << "MpfciClass Ln(const MpfciClass& z); z not allowed" << std::endl;
//    exit (1);
  }
  return MpfciClass( ln_sqrtx2y2(Re(z),Im(z)), arg(z) );
}
//
//-- end Ln -------------------------------------------------------------------


//-- Lnp1: analytic natural logarithm of 1+z ----------------------------------
//
//  Lnp1(z) is undefined if z contains -1;
//  If Sup(Re(z))<-1 z must not touch the negative real
//  axis from below;
//
MpfciClass Lnp1 (const MpfciClass& z)
{
  if (-1<=z)
  {
    std::cerr << "MpfciClass Lnp1(const MpfciClass& z); z contains -1" << std::endl;
//    exit (1);
  }
  if ( Sup(Re(z))<-1 && Inf(Im(z))<0 && Sup(Im(z))>=0 )
  {
    std::cerr << "MpfciClass Lnp1(const MpfciClass& z); z not allowed" << std::endl;
//    exit (1);
  }

  return MpfciClass( ln_sqrtxp1_2y2(Re(z),Im(z)), argp1(z) );
}


//-- lnp1: non-analytic natural logarithm with argument 1+z ------------------
//
//  lnp1(z) is undefined if z contains -1.
//
MpfciClass lnp1( const MpfciClass& z )
{
  if ( -1 <= z )
  {
    std::cerr << "MpfciClass lnp1( const MpfciClass& z ); z contains -1" << std::endl;
    return MpfciClass(0);
//    exit(1);
  }
  else
    return MpfciClass( ln_sqrtxp1_2y2(Re(z),Im(z)), argp1(z) );
}

//-- ln: non-analytic natural logarithm ---------------------------------------
//
//  ln(z) is undefined if z contains zero.
//
MpfciClass ln( const MpfciClass& z )
{
  if ( 0 <= z )
  {
    std::cerr << "MpfciClass ln( const MpfciClass& z ); z contains 0" << std::endl;
    return MpfciClass(0);
//    exit(1);
  }
  else
    return MpfciClass( ln_sqrtx2y2(Re(z),Im(z)), arg(z) );
}
//
//-- end ln -------------------------------------------------------------------

MpfciClass log2( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;

  res = Ln(z)/MpfiClass::Ln2();

  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}

MpfciClass log10( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;

  MpfiClass ten(MPFR::MpfrClass(10));
  res = Ln(z)/ln(ten);

  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}


//-----------------------------------------------------------------------------
//
//  Section 3: Root functions
//
//-----------------------------------------------------------------------------

MpfiClass Sqrt_zpx( const MpfiClass& x, const MpfiClass& y )
// Calculating sqrt(|z|+|x|) without any internal overflow;
// Notice:  |z| = sqrt(x^2+y^2);   sqrt(|z|+|x|) < MaxFloat()
{
  const int c1 = expo(MPFR::MaxFloat()) - 4,
             k = 4;
  MPFR::MpfrClass Infx(Inf(x)), Infy(Inf(y));
  int ex_x(expo(Infx)), ex_y(expo(Infy));
  MpfiClass xc(abs(x)), yc(y), res;
  bool yeq0(Infy==0);

  if ((ex_x>=c1) || (ex_y>=c1))
  {  // To avoid overflow, scaling is necessary:
    times2pown(xc,-k);
    if (yeq0)
    {
      times2pown(xc,1);
      res = sqrt(xc);
    }
    else
    {
      times2pown(yc,-k);
      res = sqrt( sqrtx2y2(xc,yc)+xc);
    }
    times2pown(res,2);  // Backscaling
  }
  else // Normal calculation without scaling:
    if (yeq0)
    {
      times2pown(xc,1);
      res = sqrt(xc);
    }
    else
      res = sqrt( sqrtx2y2(xc,yc)+xc);

    return res;
}

MpfiClass Re_Sqrt_point( const MpfiClass& rez, const MpfiClass& imz )
//
//  Real part of analytic square root of A POINT INTERVAL ONLY.
//  Do not use this as a general function
//  - it's only a subroutine for sqrt and sqrt_all.
//  The calculation is void if (rez+I*imz) is not a complex number.
//
{
  MPFR::MpfrClass
    irez = Inf( rez ),
    iimz = Inf( imz );

  if( sign(iimz) == 0 )
  {
    if( sign(irez) >= 0 )
      return sqrt( rez );
    else
      return MpfiClass(0);
  }
  else
  { // iimz <> 0
    if (sign(irez) >= 0)
      return Sqrt_zpx(rez,imz) / sqrt(MpfiClass(2));
    else
     return ( abs(iimz) / Sqrt_zpx(rez,imz) ) / sqrt(MpfiClass(2));
  }
}

MpfiClass Im_Sqrt_point( const MpfiClass& rez, const MpfiClass& imz )
//
//  Imaginary part of analytic square root of A POINT INTERVAL ONLY
//  Do not use this as a general function
//  - it's only a subroutine for sqrt and sqrt_all
//  The calculation is void if (rez+I*imz) is not a complex number
//
{
  MPFR::MpfrClass
    irez = Inf( rez ),
    iimz = Inf( imz );

  if ( sign(iimz) == 0 )
  {
    if( sign(irez) >= 0 )
      return MpfiClass(0);
    else
      return sqrt( -rez );
  }
  else
  {
    if( Inf( rez ) >= 0.0 )
      return ( iimz / sqrt(MpfiClass(2)) ) / Sqrt_zpx(rez,imz);
    else
    {
      if( sign(iimz) > 0 )
        return Sqrt_zpx(rez,imz) / sqrt(MpfiClass(2));
      else
        return -Sqrt_zpx(rez,imz) / sqrt(MpfiClass(2));
    }
  }
}

MpfciClass sqrt( const MpfciClass& z )
//
//  Analytic square root function with z in the principal branch.
//  The branch cut is the negative real axis. On the branch cut
//  the function values are defined by comming from the II quadrant.
//  Blomquist, 23.06.2005;
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MPFR::MpfrClass
    irez = Inf( Re(z) ),
    srez = Sup( Re(z) ),
    iimz = Inf( Im(z) ),
    simz = Sup( Im(z) );
  MpfiClass
    hxl( irez ), hxu( srez ), hyl( iimz ), hyu( simz );
  MPFR::MpfrClass
    resxl,  resxu, resyl, resyu;
  MpfciClass res;

  if( sign(irez) < 0 && sign(iimz) < 0 && sign(simz) >= 0 )
  //  if z is not in the principal branch then the inclusion monotony is violated!
  {
    std::cerr << "MpfciClass sqrt(const MpfciClass& z); z not in the principal branch." << std::endl;
//    exit(1);
  }

  if (sign(iimz) >= 0)
  {
      resxl = Inf( Re_Sqrt_point( hxl,hyl ) );
      resxu = Sup( Re_Sqrt_point( hxu,hyu ) );

      resyl = Inf( Im_Sqrt_point( hxu,hyl ) );
      resyu = Sup( Im_Sqrt_point( hxl,hyu ) );
  }
  else
    if (sign(simz) <= 0)
    {
      resxl = Inf( Re_Sqrt_point( hxl,hyu ) );
      resxu = Sup( Re_Sqrt_point( hxu,hyl ) );

      resyl = Inf( Im_Sqrt_point( hxl,hyl ) );
      resyu = Sup( Im_Sqrt_point( hxu,hyu ) );
    }
    else
    {
      resxl = Inf( sqrt( hxl ) );
      resxu = ( -iimz > simz ? Sup( Re_Sqrt_point( hxu, hyl ) ) :
                               Sup( Re_Sqrt_point( hxu, hyu ) ) );
      resyl = Inf( Im_Sqrt_point( hxl,hyl ) );
      resyu = Sup( Im_Sqrt_point( hxl,hyu ) );
    }

  res = MpfciClass( MpfiClass( resxl,resxu ), MpfiClass( resyl,resyu ) );

  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}

MpfciClass sqrtp1m1( const MpfciClass& z )
//
//  Analytic function f(z) = sqrt(z+1)-1 with z=x+i*y in the principal branch.
//  The branch cut is the set {x|-1nfty<x<-1}. On the branch cut
//  the function values are defined by comming from the II quadrant.
//  Blomquist, 19.08.2011;
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MPFR::MpfrClass
    irez = Inf( Re(z) ),
    srez = Sup( Re(z) ),
    iimz = Inf( Im(z) ),
    simz = Sup( Im(z) );
  MPFR::MpfrClass
    resxl,  resxu, resyl, resyu;
  MpfciClass res;

  if ( irez < -1 && sign(iimz) < 0 && sign(simz) >= 0 )
  //  if z is not in the principal branch then the inclusion monotony is violated!
  {
    std::cerr << "MpfciClass sqrtp1m1(const MpfciClass& z); z not in the principal branch." << std::endl;
//    exit(1);
  }

  if (sign(iimz) >= 0)
  {
      resxl = Re_sqrtp1m1(irez, iimz, RoundDown);  // Inf( Re_Sqrt_point( hxl,hyl ) );
      resxu = Re_sqrtp1m1(srez, simz, RoundUp);    // Sup( Re_Sqrt_point( hxu,hyu ) );

      resyl = Im_sqrtp1m1(srez, iimz, RoundDown);  // Inf( Im_Sqrt_point( hxu,hyl ) );
      resyu = Im_sqrtp1m1(irez, simz, RoundUp);    // Sup( Im_Sqrt_point( hxl,hyu ) );
  }
  else
    if (sign(simz) <= 0)
    {
      resxl = Re_sqrtp1m1(irez, simz, RoundDown);  // Inf( Re_Sqrt_point( hxl,hyu ) );
      resxu = Re_sqrtp1m1(srez, iimz, RoundUp);    // Sup( Re_Sqrt_point( hxu,hyl ) );

      resyl = Im_sqrtp1m1(irez, iimz, RoundDown);  // Inf( Im_Sqrt_point( hxl,hyl ) );
      resyu = Im_sqrtp1m1(srez, simz, RoundUp);    // Sup( Im_Sqrt_point( hxu,hyu ) );
    }
    else
    {
      resxl = sqrtp1m1(irez, RoundDown);  // Inf( sqrt( hxl ) );
      resxu = ( -iimz > simz ? Re_sqrtp1m1(srez, iimz, RoundUp) :   // Sup( Re_Sqrt_point( hxu, hyl ) ) :
                               Re_sqrtp1m1(srez, simz, RoundUp) );  // Sup( Re_Sqrt_point( hxu, hyu ) ) );
      resyl = Im_sqrtp1m1(irez, iimz, RoundDown);  // Inf( Im_Sqrt_point( hxl,hyl ) );
      resyu = Im_sqrtp1m1(irez, simz, RoundUp);    // Sup( Im_Sqrt_point( hxl,hyu ) );
    }

  res = MpfciClass( MpfiClass( resxl,resxu ), MpfiClass( resyl,resyu ) );

  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}



//
//  sqrt_all(z) computes a list of 2 intervals containing all square roots of z
//
std::list<MpfciClass> sqrt_all( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MPFR::MpfrClass
    irez = Inf( Re(z) ),
    srez = Sup( Re(z) ),
    iimz = Inf( Im(z) ),
    simz = Sup( Im(z) );
  MpfiClass
    hxl( irez ), hxu( srez ), hyl( iimz ), hyu( simz );
  MPFR::MpfrClass
    resxl,  resxu, resyl, resyu;
  MpfciClass w;

  if( sign(irez) < 0 && sign(iimz) <= 0 && sign(simz) >= 0 )
  //  z contains negative real values
  {
    if( sign(iimz) == 0 )
    //  z in upper half plane
    //  principal values can be used
    {
      //  min( Re ( sqrt( z ) ) ) in lower left  corner
      //  max( Re ( sqrt( z ) ) ) in upper right corner
      resxl = Inf( Re_Sqrt_point( hxl, hyl ) );
      resxu = Sup( Re_Sqrt_point( hxu, hyu ) );
      //  min( Im ( sqrt( z ) ) ) in lower right corner
      //  max( Im ( sqrt( z ) ) ) in upper left  corner
      resyl = Inf( Im_Sqrt_point( hxu, hyl ) );
      resyu = Sup( Im_Sqrt_point( hxl, hyu ) );
    }
    else
    {
      if( sign(simz) == 0 )
      //  z in lower half plane
      //  principal values can be used in lower corners
      {
        //  z in lower half plane
        //  min( Re ( sqrt( z ) ) ) in upper left  corner
        //  max( Re ( sqrt( z ) ) ) in lower right corner
        resxl = 0;                              ;
        resxu = Sup( Re_Sqrt_point( hxu, hyl ) );
        //  min( Im ( sqrt( z ) ) ) in lower left  corner
        //  max( Im ( sqrt( z ) ) ) in upper right corner
        resyl = Inf( Im_Sqrt_point( hxl, hyl ) );
        resyu = ( sign(srez) > 0 ? MPFR::MpfrClass(0) : -Inf( sqrt( -hxu ) ) );
      }
      else
      //  0 is interior point of Im( z )
      {
        if( sign(srez) <= 0 )
        {
        //  0 is no interior point of Re (z )
        //  in quadrant III,    Re( z ) = Im_Sqrt_point(|x|,y),
        //                      Im( z ) = Re_Sqrt_point(|x|,y)
        //  min( Re ( sqrt( z ) ) ) in lower right corner = quadrant II/III
        //  max( Re ( sqrt( z ) ) ) in upper right corner = quadrant II
        resxl = Inf( Im_Sqrt_point( -hxu, hyl ) );
        resxu = Sup( Re_Sqrt_point( hxu, hyu ) );
        //  min( Im ( sqrt( z ) ) ) on real line
        //  max( Im ( sqrt( z ) ) ) in lower or upper left corner
        resyl = Inf( sqrt( -hxu ) );
        resyu = ( -iimz > simz ? Sup( Re_Sqrt_point( -hxl, hyl ) ) : Sup( Im_Sqrt_point( hxl, hyu ) ) );
        }
        else
        //  0 is interior point of z
        //  here, the principal values apply in all corner points
        {
          resxl = 0;
          //  max( Re ( sqrt( z ) ) ) in lower or upper right corner
          resxu = ( -iimz > simz ? Sup( Re_Sqrt_point( hxu, hyl ) ) : Sup( Re_Sqrt_point( hxu, hyu ) ) );
          //  min( Im ( sqrt( z ) ) ) in lower left corner
          //  max( Im ( sqrt( z ) ) ) in upper left corner
          resyl = Inf( Im_Sqrt_point( hxl, hyl ) );
          resyu = Sup( Im_Sqrt_point( hxl, hyu ) );
        }
      }
    }
    w = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
  }
  else
  //  sqrt( z ) is well-defined
  w = sqrt( z );
  w.RoundPrecision(prec_old);

  std::list<MpfciClass> res;
  res.push_back( w );
  res.push_back( -w );

  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}
//
//-- end sqrt_all -------------------------------------------------------------

//-- sqrt(z,n): analytic n-th root --------------------------------------------
//
MpfiClass Re_Sqrt_point( const MpfiClass& rez, const MpfiClass& imz,
                         int n ) // before: unsigned int n  ---------- 040624 --
//
//  Real part of analytic n-th root.
//  Do not use this as a general function
//  - it's only a subroutine for sqrt(z,n) and sqrt_all(z,n).
//  The calculation is validated but largely overestimating
//  if (rez+I*imz) is not a complex number.
//
{
  MpfiClass abs_z_2 = sqr( rez ) + sqr( imz );
  if( Sup( abs_z_2 ) == 0.0 )
    //  z == 0
    return MpfiClass(0);
  else
    return sqrt( abs_z_2, 2 * n ) * cos( Arg( MpfciClass( rez, imz ) ) / n );
}

MpfiClass Im_Sqrt_point( const MpfiClass& rez, const MpfiClass& imz,
                         int n ) // before: unsigned int n  --- 040624 --
//
//  Imaginary part of analytic n-th root.
//  Do not use this as a general function
//  - it's only a subroutine for sqrt(z,n) and sqrt_all(z,n).
//  The calculation is validated but largely overestimating
//  if (rez+I*imz) is not a complex number.
//
{
  MpfiClass abs_z_2 = sqr( rez ) + sqr( imz );
  if( Sup( abs_z_2 ) == 0.0 )
    //  z == 0
    return MpfiClass(0);
  else
    return sqrt( abs_z_2, 2 * n ) * sin( Arg( MpfciClass( rez, imz ) ) / n );
}

MpfciClass sqrt( const MpfciClass& z, int n )
//
//  Analytic n-th root function
//  sqrt(z,n) is undefined if z contains negative real numbers.
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  if( n == 0 )
    return MpfciClass( 1.0 );
  if( n == 1 )
    return z;
  if( n == 2 )
    return sqrt( z );
  else
    {
      MPFR::MpfrClass
        irez = Inf( Re(z) ),
        srez = Sup( Re(z) ),
        iimz = Inf( Im(z) ),
        simz = Sup( Im(z) );
      MpfiClass
        hxl( irez ), hxu( srez ), hyl( iimz ), hyu( simz );
      MPFR::MpfrClass
        resxl,  resxu, resyl, resyu;

      if( sign(irez) < 0 && sign(iimz) <= 0 &&  sign(simz) >= 0 )
      {
         //  z contains negative real values
         std::cerr << "MpfciClass sqrt(const MpfciClass& z, const int n ); z contains negative real values." << std::endl;
         exit(1);
      }
      else
      {
        if( sign(simz) < 0 )
        {
         //  z in lower half plane
          MpfciClass hres = sqrt( MpfciClass( Re(z), -Im(z) ), n );
          return MpfciClass( Re(hres), -Im(hres) );
        }
        else
        {
          if( sign(iimz) > 0 )
          {
           //  z in upper half plane
           MpfiClass tangle = tan( ( MPFI::MpfiClass::Pi() *n ) / ( 2 * ( n-1 ) ) );
           MPFR::MpfrClass tanglel = Inf( tangle ),
                                      tangleu = Sup( tangle );
          //
          //  min( Re( Root( z ) ) )
          //
          if ( sign(irez) >= 0  ||  Sup( hyl / irez ) <= tanglel )
          //  lower boundary right of phi = n*Pi/(2n-2)
          //  min( Re( Root( z ) ) ) in lower left corner
            resxl = Inf( Re_Sqrt_point( hxl, hyl, n ) );
          else
          {
            if( sign(srez) < 0 && Inf( hyl / srez ) >= tangleu )
            //  lower boundary left of phi = n*Pi/(2n-2)
            //  min( Re( Root( z ) ) ) in lower right corner
              resxl = Inf( Re_Sqrt_point( hxu, hyl, n ) );
            else
            //  lower boundary intersects phi = n*Pi/(2n-2)
            //  min( Re( Root( z ) ) ) on intersection
             resxl = Inf( Re_Sqrt_point( iimz / tangle , hyl, n ) );
          }
          //
          //  max( Re( Root( z ) ) )
          //
          if ( sign(irez) >= 0 || Sup( hyu / irez ) <= tanglel )
          //  upper boundary right of phi = n*Pi/(2n-2)
          //  max( Re( Root( z ) ) ) in upper right corner
            resxu = Sup( Re_Sqrt_point( MpfiClass(srez), MpfiClass(simz), n ) );
          else
          {
            if ( sign(srez) < 0 && Inf( hyu / srez ) >= tangleu )
            //  upper boundary left of phi = n*Pi/(2n-2)
            //  max( Re( Root( z ) ) ) in upper left corner
              resxu = Sup( Re_Sqrt_point( hxl, hyu, n ) );
            else
            //  upper boundary intersects phi = n*Pi/(2n-2)
            //  max( Re( Root( z ) ) ) on upper left or right corner
              resxu = max( Sup( Re_Sqrt_point( hxl, hyu, n ) ), Sup( Re_Sqrt_point( hxu, hyu, n ) ) );
          }
          //
          //  min( Im( Root( z ) ) )
          //
          if ( sign(srez) >= 0  || Sup( hyl / srez ) <= tanglel )
          //  right boundary right of phi = n*Pi/(2n-2)
          //  min( Im( Root( z ) ) ) in lower right corner
            resyl = Inf( Im_Sqrt_point( hxu, hyl, n ) );
          else
          {
            if( Inf( hyu / srez ) >= tangleu )
            //  right boundary left of phi = n*Pi/(2n-2)
            //  min( Im( Root( z ) ) ) in upper right corner
              resyl = Inf( Im_Sqrt_point( hxu, hyu, n ) );
            else
            //  right boundary intersects phi = n*Pi/(2n-2)
            //  min( Im( Root( z ) ) ) on intersection
              resyl = Inf( Im_Sqrt_point( hxu, srez * tangle, n ) );
          }
          //
          //  max( Im( Root( z ) ) )
          //
          if( sign(irez) >= 0 || Sup( hyl / irez ) <= tanglel )
          //  left boundary right of phi = n*Pi/(2n-2)
          //  max( Im( Root( z ) ) ) in upper left corner
            resyu = Sup( Im_Sqrt_point( hxl, hyu, n ) );
          else
          {
            if( Inf( hyu / irez ) >= tangleu )
            //  left boundary left of phi = n*Pi/(2n-2)
            //  max( Im( Root( z ) ) ) in lower left corner
              resyu = Sup( Im_Sqrt_point( hxl, hyl, n ) );
            else
            //  left boundary intersects phi = n*Pi/(2n-2)
            //  max( Im( Root( z ) ) ) on lower or upper left corner
              resyu = max( Sup( Im_Sqrt_point( hxl, hyl, n ) ), Sup( Im_Sqrt_point( hxl, hyu, n ) ) );
          }
          }
          else
          {
          //  z intersects positive real axis
          //  min( Re( Root( z ) ) ) on real line
          //  max( Re( Root( z ) ) ) in lower or upper right corner
            resxl = ( sign(irez) == 0 ? MPFR::MpfrClass(0) : Inf( sqrt( hxl, n ) ) );
            resxu = ( - iimz > simz ? Sup( Re_Sqrt_point( hxu, hyl, n ) ) : Sup( Re_Sqrt_point( hxu, hyu, n ) ) );
            //  min( Im ( sqrt( z ) ) ) in lower left corner
            //  max( Im ( sqrt( z ) ) ) in upper left corner
            resyl = Inf( Im_Sqrt_point( hxl, hyl, n ) );
            resyu = Sup( Im_Sqrt_point( hxl, hyu, n ) );
          }

          // return MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
          MpfciClass res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
          res.RoundPrecision(prec_old);
          MPFI::MpfiClass::SetCurrPrecision(prec_old);
          return res;
        }
      }
    }
}
//
//-- end sqrt -----------------------------------------------------------------

//-- sqrt_all -----------------------------------------------------------------
//
std::list<MpfciClass> sqrt_all( const MpfciClass& z, int n )
//  Entsprechend der Arbeit von M. Neher
//
//  sqrt_all(z,n) computes a list of n intervals containing all n-th roots of z
//
//  For n >=3, computing the optimal interval bounds is very expensive
//  and thus not considered cost-effective.
//
//  Hence, the polar form is used to calculate sqrt_all(z,n)
//  (observed overestimation of Re() and Im() in test cases: 5-15%).
//
//  z is enclosed into an interval in polar coordinates
//  (i.e. a sector of an annulus), from which the roots
//  (also polar intervals) are computed error-free
//  (save roundoff, which is enclosed).
//
//  The final inclusion of the roots into a rectangular complex interval
//  involves some additional overestimation.
//
{
  std::list<MpfciClass> res;

  if( n == 0 )
    {
      res.push_back( MpfciClass( 1.0 ) );
      return res;
    }
  else if( n == 1 )
    {
      res.push_back(z);
      return res;
    }
  else if( n == 2 ) return sqrt_all( z );
  else
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfciClass w;
    MpfiClass
      arg_z = arg( z ), root_abs_z = sqrt( abs( z ), n );

    for(int k = 0; k < n; k++)
    {
      MpfiClass arg_k = ( arg_z + 2 * k * MPFI::MpfiClass::Pi() ) / n;
      w = MpfciClass( root_abs_z * cos( arg_k ), root_abs_z * sin( arg_k ) );
      w.RoundPrecision(prec_old);
      res.push_back( w );
    }
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return res;
  }
}
//
//-- end sqrt_all -------------------------------------------------------------

// -------------------- M. Neher, F. Blomquist --------------------------------
/* ***************************************************************************/
/* *** The hyperbolic functions exp, sin, cos, sinh, cosh are separable:  ****/
/* *** Their real and imaginary parts are products of real functions      ****/
/* ***************************************************************************/
/* ***   With Re(z)=x, Im(z)=y :                                          ****/
/* ***                                                                    ****/
/* ***        exp   :   Re(exp(z)) = exp(x) * cos(y)                      ****/
/* ***                  Im(exp(z)) = exp(x) * sin(y)                      ****/
/* ***                                                                    ****/
/* ***        sin   :   Re(sin(z)) = sin(x) * cosh(y)                     ****/
/* ***                  Im(sin(x)) = cos(x) * sinh(y)                     ****/
/* ***                                                                    ****/
/* ***        cos   :   Re(cos(z)) = cos(x) * cosh(y)                     ****/
/* ***                  Im(sin(x)) = -sin(x) * sinh(y)                    ****/
/* ***                                                                    ****/
/* ***        sinh  :   Re(sinh(z)) = sinh(x) * cos(y)                    ****/
/* ***                  Im(sinh(z)) = cosh(x) * sin(y)                    ****/
/* ***                                                                    ****/
/* ***        cosh  :   Re(cosh(z)) = cosh(x) * cos(y)                    ****/
/* ***                  Im(cosh(z)) = sinh(x) * sin(y)                    ****/
/* ***                                                                    ****/
/* ***************************************************************************/


MpfciClass exp(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res;
  MpfiClass
    A( exp( Re(z) ) ),
    B(      Im(z)   );
  res = MpfciClass( A*cos( B ) , A*sin( B ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}


MPFR::MpfrClass expm1_H1(const MPFR::MpfrClass& x, const MpfciClass& z, bool& Ausl, RoundingMode rnd)
// if rnd==RoundDown calculating x+ln(c1);
// if rnd==RoundUp   calculating x+ln(c2);
// if (Ausl) then cancellation is possible by calculating x+ln(c1) or x+ln(c2)
{
  MPFR::MpfrClass res, c1, c2;
  MpfiClass cosi = cos(Im(z));
  c1 = Inf(cosi);  c2 = Sup(cosi);

  if (rnd==RoundDown)
    res = Inf( ln_cos(Im(z)) );  // res: Abgerundeter Wert con ln(c1);
  else // rnd == RoundUp
    res = Sup( ln_cos(Im(z)) );  // res: Aufgerundeter Wert con ln(c2);
  Ausl = (sign(res)*sign(x) == -1);
  mpfr_add(res.GetValue(), res.GetValue(), getvalue(x), rnd);
  Ausl = ( (Ausl) && (std::abs(expo(x)-expo(res))>1) );

  return res;
}

MPFR::MpfrClass expm1_H(const MPFR::MpfrClass& x, const MpfciClass& z, RoundingMode rnd)
// if rnd==RoundDown calculating exp(x+ln(c1))-1 with sufficient accuracy;
// if rnd==RoundUp   calculating exp(x+ln(c2))-1 with sufficient accuracy;
{
  PrecisionType prec, prec_old = MPFR::MpfrClass::GetCurrPrecision();
  prec = prec_old;

  MPFR::MpfrClass res;
  long int exr, exr_old;
  bool Ausl;

  res = expm1_H1(x,z,Ausl,rnd); // res = x+ln(c1), falls rnd==RoundDown
                                // res = x+ln(c2), falls rnd==RoundUp
  if (Ausl) // Cancellation is possible:
  {
    exr = expo(res);
    int k=0, fac=2;
    do
    {
      k++;
      if (k==6)  fac = 4;
      if (k==10) fac = 8;
      prec = fac*prec;
      MPFR::MpfrClass::SetCurrPrecision(prec);
      exr_old = exr;
      res = expm1_H1(x,z,Ausl,rnd);
      exr = expo(res);
    } while (exr_old != exr);

    MPFR::MpfrClass::SetCurrPrecision(prec+prec_old+5);
    res = expm1_H1(x,z,Ausl,rnd);
    res.RoundPrecision(prec_old, rnd); // Runden zur alten Current-Precision
    MPFR::MpfrClass::SetCurrPrecision(prec_old);
  }
  res = expm1(res,rnd);

  return res;
}

MpfciClass expm1(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res(0);
  MpfiClass X,Y, cosi = cos(Im(z));
  MPFR::MpfrClass c1,c2,x,y,x1,x2;
  x1 = Inf(Re(z));  x2 = Sup(Re(z));

  // Calculating the real part:
  c1 = Inf(cosi);  c2 = Sup(cosi);

  if (c2<=0) // Calculation without cancellation effects:
  {
    x = exp(x2,RoundUp);
    mpfr_mul(x.GetValue(), x.GetValue(), c1.GetValue(), RoundDown);
    mpfr_sub_ui(x.GetValue(), x.GetValue(), (long)1, RoundDown);
    y = exp(x1,RoundDown);
    mpfr_mul(y.GetValue(), y.GetValue(), c2.GetValue(), RoundUp);
    mpfr_sub_ui(y.GetValue(), y.GetValue(), (long)1, RoundUp);
    X = MpfiClass(x,y); // Enclosure of the real part
  }
  else
  {
    if (c1>=0) // Calculation with possible cancellations:
    {
      x = expm1_H(x1,z,RoundDown);
      y = expm1_H(x2,z,RoundUp);
      X = MpfiClass(x,y); // Enclosure of the real part
    }
    else // Inf(cos(Im(z))) <= 0 <= Sup(cos(Im(z))) :
    {
      x = exp(x2,RoundUp);
      mpfr_mul(x.GetValue(), x.GetValue(), c1.GetValue(), RoundDown);
      mpfr_sub_ui(x.GetValue(), x.GetValue(), (long)1, RoundDown);
      y = expm1_H(x2,z,RoundUp);
      X = MpfiClass(x,y); // Enclosure of the real part
    }
  }

  // Calculating the imaginary part:
  Y = exp(Re(z)) * sin(Im(z));

  res = MpfciClass(X,Y);
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass exp2(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  res = exp(z * MPFI::MpfiClass::Ln2());
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass exp10(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  res = exp(z * ln(MpfiClass(10)));
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass sin(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  MpfiClass
    A( Re(z) ),
    B( Im(z) );
  res = MpfciClass( sin( A )*cosh( B ) , cos( A )*sinh( B ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass cos(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  MpfiClass
    A( Re(z) ),
    B( Im(z) );
  res = MpfciClass( cos( A )*cosh( B ) , -sin( A )*sinh( B ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass cosh(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res;
  MpfiClass
    A( Re(z) ),
    B( Im(z) );
  res = MpfciClass( cos( B )*cosh( A ) , sin( B )*sinh( A ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

MpfciClass sinh(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res;
  MpfiClass
    A( Re(z) ),
    B( Im(z) );
  res = MpfciClass( cos( B )*sinh( A ) , sin( B )*cosh( A ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}


//-----------------------------------------------------------------------------
//
//  Section 2: tan, cot, tanh, coth
//
//  The implementation of cot, tanh, and coth is based on tan:
//
//  cot( z )  = tan( pi/2 - z )
//  tanh( z ) = transp( i * tan( transp( i * z ) )
//  coth( z ) = i * cot( i * z ) = i * tan( pi/2 - i * z )
//
//-----------------------------------------------------------------------------

//-- tan ------ M. Neher, F. Blomquist ----------------------------------------
//
//  Complex tangent function
//
void horizontal_check( //------------------------------------------------------
     const MpfiClass& hy,  const MpfiClass& cosh_2y, MPFR::MpfrClass irez, MPFR::MpfrClass srez,
     const MpfiClass& hxl, const MpfiClass& hxu, MPFR::MpfrClass& resxl, MPFR::MpfrClass& resxu )
//
//  Subroutine of tangent function.
//  Check intersections with extremal curves of tan on a horizontal boundary.
//  This subroutine is only called if an intersection occurs.
//  In this case, sinh( 2 * hy ) <> 0.0 (poles are handled before).
//
//  There may be 1 or 2 intersections.
//  If intersections lie next to a boundary of rez, then it is impossible to
//  decide if there are 1 or 2 intersections.
//  In this case, 2 intersections are assumed
//  (valid enclosure, at the expense of a potential slight overestimation).
//
{
  bool both = false, left = false, right = false;

  if (srez - irez > Inf( MPFI::MpfiClass::Pi() ))
  //  2 intersections
    both = true;
  else
  {
    MpfiClass
      res_l = cos( 2 * hxl ) - cosh_2y,
      res_u = cos( 2 * hxu ) - cosh_2y;

    if( Inf( res_l * res_u ) > 0.0 )
    //  2 intersections
      both = true;
    else
    {
      if( Sup( res_l * res_u ) < 0.0 )
      {
      //  1 intersection (3 intersections are Pi() apart)
      //  neither of the intervals res_l and res_u contains zero
        if ( Inf( res_l ) > 0.0 )
          //  "left" intersection
          left = true;
        else
          //  "right" intersection
          right = true;
      }
      else
      //
      //  1 (or both) intersections lie next to a boundary point
      //  here, the task is to decide if 2 intersections occurs
      //  if only 1 intersection takes place, then which one?
      //
      {
        MpfiClass
          sin_2xl = sin( 2 * hxl ),
          sin_2xu = sin( 2 * hxu );

        if ( !Disjoint( MpfiClass(0), res_l ) )
        //  intersection on the left boundary
        {
          if ( Inf( sin_2xl ) >= 0.0 )
          // "left" intersection
          {
            left = true;
            //  remove the intersection by changing res_l!
            res_l = -MpfiClass(1.0);
          }
          else
          {
            if ( Sup( sin_2xl ) <= 0.0 )
            // "right" intersection
            {
              right = true;
              //  remove the intersection by changing res_l!
              res_l = MpfiClass(1.0);
            }
            else
            //  zero is interior point of sin_2xl
            //  if the real sine function has optimal precision,
            //  this case should never happen
              both = true;
          }
        }

        if ( !Disjoint( MpfiClass(0.0), res_u ) )
        //  intersection on the right boundary
        {
          if( Inf( sin_2xu ) >= 0.0 )
          // "left" intersection
          {
            left = true;
            //  remove the intersection by changing res_u!
            res_u = MpfiClass(1);
          }
          else
          {
            if ( Sup( sin_2xu ) <= 0.0 )
            // "right" intersection
            {
              right = true;
              //  remove the intersection by changing res_u!
              res_u = -MpfiClass(1);
            }
            else
            //  zero is interior point of sin_2xu
            //  if the real sine function has optimal precision,
            //  this case should never happen
              both = true;
          }
        }
        //
        //  finally, check if there is a second intersection
        //
        if ( Inf( res_l * res_u ) < 0.0 )
          both = true;
      }
    }
  }
  //
  //  Calculate extremal values
  //
  MpfiClass re_tan = 1 / sinh( 2 * abs( hy ) );

  //  "left" intersection, sin( 2x ) > 0
  if ( left || both )
  {
    resxl = min( resxl, Inf( re_tan ) );
    resxu = max( resxu, Sup( re_tan ) );
  }

  //  "right" intersection, sin( 2x ) < 0
  if ( right || both )
  {
    resxl = min( resxl, - Sup( re_tan ) );
    resxu = max( resxu, - Inf( re_tan ) );
  }
} // end horizontal_check

MpfciClass tan( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;

  MpfiClass
    rez = Re(z),   // rez = z.re(),
    imz = Im(z);   // imz = z.im();

  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  MpfiClass
    hxl(irez), hxu(srez), hyl(iimz), hyu(simz);

  MPFR::MpfrClass
    resxl, resxu, resyl, resyu;
  //
  //  1st: check for poles
  //
  if ( ( !Disjoint( MpfiClass(0), imz ) ) && ( !Disjoint( MpfiClass(0), cos( rez ) ) ) )
  {
    std::cerr << "MpfciClass tan(const MpfciClass& Z); Pole(s) in Z" << std::endl;
    exit(1);
  }
  //
  //  2nd: real part
  //
  //  evaluate tan on vertical boundaries
  //
  MpfiClass
    cos_2rez   = cos( 2 * rez ),
    sinh_imz_2 = sqr( sinh( imz ) );

  MpfiClass
    re_tan_l = sin( 2 * hxl ) / ( 2 * ( sqr( cos( hxl ) ) + sinh_imz_2 ) ),
    re_tan_u = sin( 2 * hxu ) / ( 2 * ( sqr( cos( hxu ) ) + sinh_imz_2 ) );

  resxl = min( Inf( re_tan_l ), Inf( re_tan_u ) );
  resxu = max( Sup( re_tan_l ), Sup( re_tan_u ) );
  //
  //  look for extremal values on horizontal boundaries
  //  if one of the horizontal boundaries is the x-axes,
  //  then the complex tangent is the real tangent on this
  //  boundary, and due to monotonicity, its range
  //  is already included in the ranges of the vertical boundaries
  //
  if( irez < srez )
  {
    MpfiClass
      cosh_2yl = - 1 / cosh( 2 * hyl ),
      cosh_2yu = - 1 / cosh( 2 * hyu );

    if ( !Disjoint( cos_2rez, cosh_2yl ) && iimz != 0.0 )
    // extremal curve intersects lower boundary
      horizontal_check( hyl, cosh_2yl, irez, srez, hxl, hxu, resxl, resxu );

    if ( !Disjoint( cos_2rez, cosh_2yu ) && simz != 0.0 )
    // extremal curve intersects upper boundary
      horizontal_check( hyu, cosh_2yu, irez, srez, hxl, hxu, resxl, resxu );
  }
  //
  //  3rd: imaginary part
  //
  //  evaluate tan on horizontal boundaries
  //
  MpfiClass
    cos_rez_2 = sqr( cos( rez ) );

  MpfiClass
    im_tan_l = sinh( 2 * hyl ) / ( 2 * ( cos_rez_2 + sqr( sinh( hyl ) ) ) ),
    im_tan_u = sinh( 2 * hyu ) / ( 2 * ( cos_rez_2 + sqr( sinh( hyu ) ) ) );

  resyl = min( Inf( im_tan_l ), Inf( im_tan_u ) );
  resyu = max( Sup( im_tan_l ), Sup( im_tan_u ) );

  //
  //  look for extremal values on vertical boundaries
  //  here, the situation is simpler than for the real part
  //  if 2 intersections with extremal curves appear ,
  //  one lies in the lower half plane, the other in the upper half plane
  //
  MpfiClass
    cos_2xl = cos( 2 * hxl ),
    cos_2xu = cos( 2 * hxu );
  MpfiClass im_tan;

  if ( sign(iimz) < 0 )
  //  intersection in lower half plane?
  {
    MpfiClass
      imz_h = MpfiClass( iimz, min( simz, MPFR::MpfrClass(0) ) ),
      cosh_2imz = - 1 / cosh( 2 * imz_h );

    if ( ( !Disjoint( cosh_2imz, cos_2xl ) ) )
    //extremal curve intersects left boundary
    //in this case, sin( 2 * xl ) <> 0.0 (no poles here!)
    {
      im_tan = -1 / abs( sin( 2 * hxl ) );
      resyl = min( resyl, Inf( im_tan ) );
      resyu = max( resyu, Sup( im_tan ) );
    }
    if ( ( !Disjoint( cosh_2imz, cos_2xu ) ) )
    //extremal curve intersects right boundary
    //in this case, sin( 2 * xu ) <> 0.0 (no poles here!)
    {
      im_tan = -1 / abs( sin( 2 * hxu ) );
      resyl = min( resyl, Inf( im_tan ) );
      resyu = max( resyu, Sup( im_tan ) );
    }
  }
  if ( sign(simz) > 0 )
  //  intersection in upper half plane?
  {
    MpfiClass
      imz_h = MpfiClass( max( iimz, MPFR::MpfrClass(0) ), simz ),
      cosh_2imz = -1 / cosh( 2 * imz_h );

    if ( ( !Disjoint( cosh_2imz, cos_2xl ) ) )
    // extremal curve intersects left boundary
    // in this case, sin( 2 * xl ) <> 0.0 (no poles here!)
    {
      im_tan = +1 / abs( sin( 2 * hxl ) );
      resyl = min( resyl, Inf( im_tan ) );
      resyu = max( resyu, Sup( im_tan ) );
    }
    if ( ( !Disjoint( cosh_2imz, cos_2xu ) ) )
    // extremal curve intersects right boundary
    // in this case, sin( 2 * xu ) <> 0.0 (no poles here!)
    {
      im_tan = +1 / abs( sin( 2 * hxu ) );
      resyl = min( resyl, Inf( im_tan ) );
      resyu = max( resyu, Sup( im_tan ) );
    }
  }

  res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
} // end tan

MpfciClass cot(const MpfciClass& z )
{ // Improved cot-function; Blomquist,27.02.2011;
  // cot(z) = tan(Pi/2 - z) is used;
  // In order to avoid cancellation effects the real part
  // Pi()/2 - Re(z) of the complex argument Pi/2 - z
  // is calculated in double precision 2*prec;
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(2*prec);

  MpfiClass re;
  re = MpfiClass::Pi()/2 - Re(z);
  re.RoundPrecision(prec);
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res( MpfciClass(re,-Im(z)) );
  res = tan(res);
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}

//-- tanh ------ M. Neher ---------------------------------------------------
//
//  tanh( z ) = transp( i * tan( transp( i * z ) )
//
MpfciClass tanh(const MpfciClass& z)
{
  MpfciClass res = tan( MpfciClass( Im(z), Re(z), z.GetPrecision() ) );
  return MpfciClass( Im(res), Re(res) );
}
//
//-- end tanh -----------------------------------------------------------------

//-- coth ---------------------------------------------------------------------
//
//   coth( z ) = i * cot( i * z );
//

MpfciClass coth(const MpfciClass& z)
{ // coth( z ) = i * cot( i * z );
    MpfciClass res = cot( MpfciClass( -Im(z), Re(z), z.GetPrecision() ) );
    return( MpfciClass( -Im(res),Re(res) ) );
}
//
//-- end coth -----------------------------------------------------------------


//-- asin ----- M. Neher, F. Blomquist ----------------------------------------
//
//  Analytic inverse sine function
//
MpfiClass f_aux_asin(const MpfiClass& x, const MpfiClass& y )
//
//  auxiliary function for evaluating asin();
//  z = x + i*y;
//  f_aux_asin(x,y) = alpha := ( |z+1| + |z-1| ) / 2 = T(x,y)/2;
//                  = ( sqrt( (x+1)^2+y^2 ) + sqrt( (x-1)^2+y^2 ) ) / 2;
//  f_aux_asin(x,y) is evaluated here only for POINT intervals!
{
  MpfiClass res;
  if (y == 0.0 && abs(x) == 1.0)
    res = 1.0;
  else
    res = (sqrtx2y2(x+1.0,y) + sqrtx2y2(x-1.0,y)) / 2.0;  // Blomquist;
  //  Now correction of possible overestimation of the lower bound of res:
  //  (x is a point interval)
  MPFR::MpfrClass hlb = max( MPFR::MpfrClass(1), abs( Sup( x ) ) );
  if( Inf( res ) < hlb )
  //  Now there is an overestimation! From theory it holds:  Inf(res) >= hlb, and therefore:
    res = MpfiClass( hlb, Sup(res) );

  return res;
}

MpfiClass f_aux_asin_Vn(const MpfiClass& x, const MpfiClass& y)
// normal calculation of
// V := ( |x+1|*{sqrt( (y/(x+1))^2 + 1 ) - 1} + |x-1|*{sqrt( (y/(x-1))^2 + 1 ) - 1} ) / 2;
{
    MpfiClass V,f1,f2;
    f1 = x+1.0;  f2 = x-1.0;
    V = abs(f1)*sqrtp1m1(sqr(y/f1)) + abs(f2)*sqrtp1m1(sqr(y/f2));
    times2pown(V,-1); // Division by 2
    return V;
} // f_aux_asin_Vn

MpfiClass ACOSH_p1(const MpfiClass& x, const MpfiClass& y)
// Calculating an inclusion for acosh(1+V/2) if |x|<1;
// This function is only used for point intervals x,y !
{
  MPFR::MpfrClass r1(Inf(y)), t;
  long int ex(expo(r1));
  MpfiClass res(0.0), u, V;
  if ( sign(r1) != 0)
  {
    V = f_aux_asin_Vn(x,y);
    if ( ex < -(MPFI::MpfiClass::GetCurrPrecision()*3)/2 )
    {
      u = abs(y) / sqrt1mx2(x);
      res.SetInterval( pred(pred(Inf(u))), Sup(u));
    }
    else
      res = acoshp1(V); // usual calculation
  }

  return res;
} // ACOSH_p1

MpfiClass ACOSH_f_aux( const MpfiClass& x, const MpfiClass& y )
// Calculating acosh( f_aux_asin(x,y) ); x,y: point intervals !!
// Blomquist, 28.02.2011;
{
  MpfiClass res, delta, kl;
  MPFR::MpfrClass rx(abs(Inf(x))), ry(abs(Inf(y)));

  if (rx>2.0 || ry>2.0)
    res = acosh( f_aux_asin(x,y) ); // as before!
  else
  { // Now with improvements !!
    if (rx == 1.0)
    {
      delta = abs(y);
      if (expo(Inf(delta)) < -MPFI::MpfiClass::GetCurrPrecision())
      {
        res = sqrt(delta);  // res = sqrt( |y| )
        kl  = res * (1+delta/12);
        res = res * (1-(3*sqr(delta))/80);
        res = MpfiClass( Inf(res), Sup(kl) );
      }
      else
      {
        times2pown(delta,-1); // delta: |y|/2;
        delta = sqrtp1m1(sqr(delta)) + delta;
        res = acoshp1(delta);
      }
    }
    else
      if (rx<1.0)
        res = ACOSH_p1(x,y);
      else
        res = acoshp1( (abs(x)-1.0) + f_aux_asin_Vn(x,y) );
  }
  return res;
} // ACOSH_f_aux

MpfiClass Asin_beta( const MpfiClass& x, const MpfiClass& y )
// Calculating the improved real part of asin(z); Blomquist 19.06.2005;
// Re(asin(z)) = asin[ 2x/(sqrt[(x+1)^2+y^2] + sqrt[(x-1)^2+y^2]) ] = asin[beta]
// Improvements for beta --> +1  and  beta --> -1  are necessary because of nearly
// vertical tangents of the real asin(t)-function for |t|-->+1;
{
  const double c1 = 0.75;
  bool neg_b;
  MPFR::MpfrClass Infxa;
  MpfiClass res,beta,abs_beta,delta,tm,tp,u,v,xa;
  beta = x / ( (sqrtx2y2(1+x,y) + sqrtx2y2(1-x,y))/2 );
  if (Inf(beta)<-1) Inf(beta)=-1;
  if (Sup(beta)> 1) Sup(beta)=1;
  abs_beta = abs(beta);
  if (Inf(abs_beta)<c1)
    res = asin(beta); // Normal calculation
  else
  { // Inf(abs_beta)>=c1; Calculation now with improvements:
    xa = x;
    neg_b = Inf(x)<0;
    if (neg_b)
      xa = -xa; // Inf(xa) >0 :
    Infxa = Inf(xa);
    if (Infxa > 1)
    {
      tm = y/(xa-1);
      tp = y/(xa+1);
      u = sqrtp1m1(sqr(tm));
      v = sqrtp1m1(sqr(tp));
      delta = (tm*tp - u*v) / (2+u+v);
    }
    else
      if (Infxa == 1)
      {
        u = abs(y);
        times2pown(u,-1); // u = |y|/2
        delta = u - sqrtp1m1(sqr(u));
      }
      else
      {
        tp = 1+xa;  tm = 1-xa;
        delta = tm*(sqrt(1+sqr(y/tm))+1) - tp*sqrtp1m1(sqr(y/tp));
        times2pown(delta,-1);
      }
      if (Inf(delta)<0) // Blomquist, 02.03.2011
        delta.SetInterval( MPFR::MpfrClass(0), Sup(delta) );
      res = MPFI::MpfiClass::Pi()/2 - asin( sqrt(delta*(2-delta)) );
      if (neg_b) res = -res;
  }
  return res;
} // Asin_beta

MpfciClass asin(const MpfciClass& z)
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  const MPFR::MpfrClass gr =
    comp( MPFR::MpfrClass(0.530330085889), 1073741822); // upper bound for abs(rez),abs(imz)
  MpfiClass
    rez = Re(z),
    imz = Im(z);
  MpfciClass res;
  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  MpfiClass hxl(irez), hxu(srez), hyl(iimz), hyu(simz);

  MPFR::MpfrClass resxl, resxu, resyl, resyu;

  bool bl    = (sign(iimz) < 0) && (sign(simz)>0),
       raxis = (sign(iimz) ==0) && (sign(simz)==0);

  //
  //  1st: check for singularities
  //
  if( (irez<-1 && (bl || (sign(iimz)<0  && sign(simz)==0))) ||
      (srez >1 && (bl || (sign(iimz)==0 && sign(simz)>0))) )
  {
    std::cerr << "MpfciClass asin(const MpfciClass& z); z contains singularities." << std::endl;
    exit(1);
  }
  //
  //  check for too large bounds of abs(rez) and abs(imz) to prevent
  //  overflow by calculating f_aux_asin(...)
  //
  resxl = max(abs(irez),abs(srez));
  resxu = max(abs(iimz),abs(simz));
  if (resxl>gr || resxu>gr)
  {
    std::cerr << "MpfciClass asin( const MpfciClass& z ); z with too large bounds." << std::endl;
    exit(1);
  }
  //
  //  2nd: real part
  //
  if( sign(iimz) < 0 && sign(simz) > 0 )
  //  z intersects [-1,1]
  {
    if( sign(irez) <= 0 )
      resxl = Inf( asin( hxl ) );
    else
    // resxl = Inf( asin( hxl / f_aux_asin( hxl, interval( max( - iimz, simz ) ) ) ) );
      resxl = Inf( Asin_beta(hxl,MpfiClass( max(-iimz, simz) )) ); // Blomquist, 19.06.2005;
    if( sign(srez) < 0 )
    // resxu = Sup( asin( hxu / f_aux_asin( hxu, interval( max( - iimz, simz ) ) ) ) );
      resxu = Sup( Asin_beta(hxu,MpfiClass( max(-iimz,simz) )) ); // Blomquist, 19.06.2005;
    else
      resxu = Sup( asin( hxu ) );
  }
  else
  {
    if( ( sign(iimz) >= 0 && sign(irez) >= 0 ) || ( sign(simz) <= 0 && sign(irez) <= 0 ) )
    //  left boundary in quadrants I or III
    //  min( Re( z ) ) in upper left corner
    //  resxl = Inf( asin( hxl / f_aux_asin( hxl, hyu ) ) );
      resxl = Inf( Asin_beta(hxl,hyu) ); // Blomquist, 19.06.2005;
    else
    //  left boundary in quadrants II or IV
    //  min( Re( z ) ) in lower left corner
    //  resxl = Inf( asin( hxl / f_aux_asin( hxl, hyl ) ) );
      resxl = Inf( Asin_beta(hxl,hyl) ); // Blomquist, 19.06.2005;
    if ( ( sign(iimz) >= 0 && sign(srez) >= 0 ) || ( sign(simz) <= 0 && sign(srez) <= 0 ) )
    //  right boundary in quadrants I or III
    //  max( Re( z ) ) in lower right corner
    //  resxu = Sup( asin( hxu / f_aux_asin( hxu, hyl ) ) );
      resxu = Sup( Asin_beta(hxu,hyl) ); // Blomquist, 19.06.2005;
    else
    //  right boundary in quadrants II or IV
    //  max( Re( z ) ) in upper right corner
    //  resxu = Sup( asin( hxu / f_aux_asin( hxu, hyu ) ) );
      resxu = Sup( Asin_beta(hxu,hyu) ); // Blomquist, 19.06.2005;
  }
  //
  //  3rd: imaginary part
  //
  if (raxis)
  { // Interval argument is now a subset of the real axis.
    // Blomquist, 16.06.2005;
    if (sign(srez)<0)
      resyl = Inf( ACOSH_f_aux( hxu, hyu ));
    else
      resyl = -Sup( ACOSH_f_aux( hxu, hyu ));
    if (sign(irez)>0)
      resyu = -Inf( ACOSH_f_aux( hxl, hyu ));
    else
      resyu =  Sup( ACOSH_f_aux( hxl, hyu ));
  }
  else
    if( sign(simz) <= 0 )
    //  z in lower half plane
    //  min( Im( z ) ) in point with max |z|
    //  max( Im( z ) ) in point with min |z|
    {
      if( irez < -srez )
      //  most of z in quadrant III
      {
        resyl = -Sup( ACOSH_f_aux( hxl, hyl ) );
        if( sign(srez) < 0 )
          resyu = -Inf( ACOSH_f_aux( hxu, hyu ) );
        else
          resyu = -Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyu ) );
      }
      else
      //  most of z in quadrant IV
      {
        resyl = -Sup( ACOSH_f_aux( hxu, hyl ) );
        if ( sign(irez) > 0 )
          resyu = -Inf( ACOSH_f_aux( hxl, hyu ) );
        else
          resyu = -Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyu ) );
      }
    }
    else
      if( sign(iimz) >= 0 )
      //  z in upper half plane
      //  min( Im( z ) ) in point with min |z|
      //  max( Im( z ) ) in point with max |z|
      {
        if( irez < -srez )  // if( irez + srez < 0.0 )
        //  most of z in quadrant II
        {
          resyu = Sup( ACOSH_f_aux( hxl, hyu ) );
          if( sign(srez) < 0 )
            resyl = Inf( ACOSH_f_aux( hxu, hyl ) );
          else
            resyl = Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyl ) );
        }
        else
        //  most of z in quadrant I
        {
          resyu = Sup( ACOSH_f_aux( hxu, hyu ) );
          if( sign(irez) > 0 )
            resyl = Inf( ACOSH_f_aux( hxl, hyl ) );
          else
            resyl = Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyl ) );
        }
      }
      else
      //  z intersects imaginary axes
      //  min( Im( z ) ) in point in lower half plane with max |z|
      //  max( Im( z ) ) in point in upper half plane with max |z|
      {
        if( irez < -srez )
        //  most of z in quadrants II and IV
        {
          resyl = -Sup( ACOSH_f_aux( hxl, hyl ) );
          resyu =  Sup( ACOSH_f_aux( hxl, hyu ) );
        }
        else
        {
          resyl = -Sup( ACOSH_f_aux( hxu, hyl ) );
          resyu =  Sup( ACOSH_f_aux( hxu, hyu ) );
        }
      }

  res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}
//
//-- end asin -----------------------------------------------------------------


MpfiClass Acos_beta( const MpfiClass& x, const MpfiClass& y )
// Calculating the improved real part of acos(z); Blomquist 05.03.2011;
// Re(acos(z)) = acos[ 2x/(sqrt[(x+1)^2+y^2] + sqrt[(x-1)^2+y^2]) ]
{
  const double c1 = 0.75;
  MpfiClass res(0),beta,delta,tm,tp,u,v,xa;
  MPFR::MpfrClass Infy(Inf(y)),Infx(Inf(x));
  beta = x / ( (sqrtx2y2(1+x,y) + sqrtx2y2(1-x,y))/2 );
  if (Inf(beta)<-1) Inf(beta)=-1;
  if (Sup(beta)> 1) Sup(beta)= 1;

  if (Sup(beta)<c1)
    if (Sup(beta)<-c1)
    { // Improvement for beta --> -1
      xa = -x;       // Inf(xa)>0:
      Infx = -Infx;  // Infx > 0:
      if (Infx > 1)
      {
        tm = y/(xa-1);  tp = y/(xa+1);
        u = sqrtp1m1(sqr(tm));
        v = sqrtp1m1(sqr(tp));
        delta = (tm*tp - u*v) / (2+u+v);
      }
      else
        if (Infx == 1)
        {
          u = abs(y);
          times2pown(u,-1);  // u = |y|/2
          delta = u - sqrtp1m1(sqr(u));
        }
        else
        {
          tp = 1+xa;  tm = 1-xa;
          delta = tm*(sqrt(1+sqr(y/tm))+1) - tp*sqrtp1m1(sqr(y/tp)); // Ist OK!
          times2pown(delta,-1);
        }
        res = MPFI::MpfiClass::Pi() - asin( sqrt(delta*(2-delta)) );
    }
    else
      res = acos(beta); // Normal calculation
  else  // Sup(beta)>=c1
    if (Infx>1)
    {
      tm = y/(x-1);
      if (expo(Sup(tm)) <-(MPFR::MpfrClass::GetCurrPrecision())/2 - 1)
      {
        if (Infy!=0)
        {
          u = abs(Infy) / sqrtx2m1(x);
          res = MpfiClass( pred(Inf(u)), succ(succ(Sup(u))) );
        }
      }
      else
      {
        tp = y/(x+1);
        u = sqrtp1m1(sqr(tm));
        v = sqrtp1m1(sqr(tp));
        delta = (tm*tp - u*v) / (2+u+v);
        res = asin(sqrt(delta*(2-delta)));
      }
    }
    else
      if (Infx==1)
      {
        if (expo(Inf(y))<=-MPFR::MpfrClass::GetCurrPrecision() + 1)
        {
          u = sqrt(abs(y));
          if (Sup(u)==0)
            res = 0;
          else
            res = MpfiClass( pred(Inf(u)), succ(succ(Sup(u))) );
        }
        else
        {
          u = abs(y);
          times2pown(u,-1); // u = |y|/2
          delta = u - sqrtp1m1(sqr(u));
          res = asin( sqrt(delta*(2-delta)) );
        }
      }
      else
      {
        tp = 1+x;  tm = 1-x;
        delta = tm*(sqrt(1+sqr(y/tm))+1) - tp*sqrtp1m1(sqr(y/tp)); // Ist OK!
        times2pown(delta,-1);
        res = asin( sqrt(delta*(2-delta)) );
      }

  return res;
}  // Acos_beta

//-- acos --------- Neher, Blomquist --------------------------------------
//
// MpfciClass acos( const MpfciClass& z )
// {
//   w := acos(z);
//   Re(w) in a new Version,
//   Im(w) = -Im(asin(z));  Blomquist, 06.036.2011;
// }
//
//-- acos -----------------------------------------------------------------


//-- acos -------------------------------------------------------------
//
MpfciClass acos( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  const MPFR::MpfrClass gr =
    comp( MPFR::MpfrClass(0.530330085889), 1073741822); // upper bound for abs(rez),abs(imz)
  MpfiClass
    rez = Re(z),
    imz = Im(z);

  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  MpfiClass
    hxl(irez), hxu(srez), hyl(iimz), hyu(simz);
  MpfciClass res;
  bool bl    = (iimz< 0.0) && (simz>0.0),
       raxis = (iimz==0.0) && (simz==0);
  MPFR::MpfrClass
    resxl, resxu, resyl, resyu;
  //
  //  1st: check for singularities
  //
  if ( (irez<-1 && (bl || (iimz<0  && simz==0))) ||
      (srez >1 && (bl || (iimz==0 && simz>0))) )
  {
    std::cerr << "MpfciClass acos( const MpfciClass& z ); z contains singularities." << std::endl;
    exit(1);
  }
  //
  //  check for too large bounds of abs(rez) and abs(imz) to prevent
  //  overflow by calculating f_aux_asin(...)
  //
  resxl = max(abs(irez),abs(srez));
  resxu = max(abs(iimz),abs(simz));
  if (resxl>gr || resxu>gr)
  {
    std::cerr << "cinterval acos( const cinterval& z ); z with too large bounds." << std::endl;
    exit(1);
  }
  //
  //  2nd: real part
  //
  //  Blomquist, 06.06.2005;
  if( iimz < 0.0 && simz > 0.0 )
  //  z intersects [-1,1] on the x-axis
  {
    if ( sign(irez) <= 0 )
      resxu = Sup( acos( hxl ) );
    else
      resxu = Sup( Acos_beta(hxl,MpfiClass( max(-iimz,simz) )) );

    if( srez < 0.0 )
      resxl = Inf( Acos_beta(hxu,MpfiClass(max(-iimz,simz))) );
    else
      resxl = Inf( acos( hxu ) );
  }
  else
  {
    if (sign(irez)<0 && sign(srez)>0)
    // z intersects the posizive or negative y-axis
      if (sign(iimz) >= 0)
      {
        resxl = Inf( Acos_beta(hxu,hyl) );
        resxu = Sup( Acos_beta(hxl,hyl) );
      }
      else
      {
        resxl = Inf( Acos_beta(hxu,hyu) );
        resxu = Sup( Acos_beta(hxl,hyu) );
      }
    else
    {
      if ( ( sign(iimz) >= 0 && sign(irez) >= 0  ) || ( sign(simz) <= 0 && sign(irez) < 0 ) )
      //  left boundary in quadrants I or III
      //  min( Re( z ) ) in lower right corner
        resxl = Inf( Acos_beta(hxu,hyl) );
      else
      //  left boundary in quadrants II or IV
      //  min( Re( z ) ) in upper right corner
        resxl = Inf( Acos_beta(hxu,hyu) );

      if( ( sign(iimz) >= 0 && sign(srez) > 0 ) || ( sign(simz) <= 0 && sign(srez) <= 0 ) )
      //  right boundary in quadrants I or III
      //  max( Re( z ) ) in upper left corner
        resxu = Sup( Acos_beta(hxl,hyu) );
      else
      //  right boundary in quadrants II or IV
      //  max( Re( z ) ) in lower left corner
        resxu = Sup( Acos_beta(hxl,hyl) );
    }
  }
  //
  //  3rd: imaginary part
  //
  if (raxis)
  { // Interval argument is now a subset of the real axis.
               // Blomquist, 16.06.2005;
    if (sign(srez)<0)
      resyl =  Inf( ACOSH_f_aux( hxu, hyu ));
    else
      resyl = -Sup( ACOSH_f_aux( hxu, hyu ));
    if (sign(irez)>0)
      resyu = -Inf( ACOSH_f_aux( hxl, hyu ));
    else
      resyu =  Sup( ACOSH_f_aux( hxl, hyu ));
  }
  else
    if( sign(simz) <= 0 )
    //  z in lower half plane
    //  min( Im( z ) ) in point with max |z|
    //  max( Im( z ) ) in point with min |z|
    {
      if( irez < -srez )
      //  most of z in quadrant III
      {
        resyl = -Sup( ACOSH_f_aux( hxl, hyl ) );
        if ( sign(srez) < 0 )
          resyu = - Inf( ACOSH_f_aux( hxu, hyu ) );
        else
          resyu = -Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyu ) );
      }
      else
      //  most of z in quadrant IV
      {
        resyl = -Sup( ACOSH_f_aux( hxu, hyl ) );
        if ( sign(irez) > 0 )
          resyu = -Inf( ACOSH_f_aux( hxl, hyu ) );
        else
          resyu = -Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyu ) );
      }
    }
    else
      if( iimz >= 0.0 )
      //  z in upper half plane
      //  min( Im( z ) ) in point with min |z|
      //  max( Im( z ) ) in point with max |z|
      {
        if( irez < -srez )  // if( irez + srez < 0.0 )
        //  most of z in quadrant II
        {
          resyu = Sup( ACOSH_f_aux( hxl, hyu ) );
          if ( sign(srez) < 0 )
            resyl = Inf( ACOSH_f_aux( hxu, hyl ) );
          else
            resyl = Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyl ) );
        }
        else
        //  most of z in quadrant I
        {
          resyu = Sup( ACOSH_f_aux( hxu, hyu ) );
          if ( sign(irez) > 0 )
            resyl = Inf( ACOSH_f_aux( hxl, hyl ) );
          else
            resyl = Inf( ACOSH_f_aux( MPFI::MpfiClass(0), hyl ) );
        }
      }
      else
      //  z intersects imaginary axes
      //  min( Im( z ) ) in point in lower half plane with max |z|
      //  max( Im( z ) ) in point in upper half plane with max |z|
      {
        if( irez < -srez ) // if( irez + srez < 0.0 )
        //  most of z in quadrants II and IV
        {
          resyl = -Sup( ACOSH_f_aux( hxl, hyl ) );
          resyu = Sup( ACOSH_f_aux( hxl, hyu ) );
        }
        else
        {
          resyl = -Sup( ACOSH_f_aux( hxu, hyl ) );
          resyu = Sup( ACOSH_f_aux( hxu, hyu ) );
        }
      }

  res = MpfciClass( MpfiClass( resxl, resxu ), -MpfiClass( resyl, resyu ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}
//
//-- end acos -----------------------------------------------------------------

MpfiClass Atan(const MpfiClass& y, const MpfiClass& x)
// Calculating an inclusion of atan(y/x) with x<>[0,0];
// This help function must only be used for POINT intervals y,x !!
// This function avoids internal overflow by calculating y/x.
{
  MpfiClass res(0);

  if ( sign(Inf(y)) !=0 )
  {
    if (sign(Inf(x))<0)
    {
      if ( sign(Inf(y)) >0 )
        res = atan2(y,x) - MpfiClass::Pi();
      else
        res = atan2(y,x) + MpfiClass::Pi();
    }
    else // x >= 0
      res = atan2(y,x);
  }
  return res;
}

MpfiClass Atan(const MpfiClass& y, const MPFR::MpfrClass& x)
// Calculating an inclusion of atan(y/x) with x<>0.0;
// This help function must only be used for POINT intervals y !!
// This function avoids internal overflow by calculating y/x.
{
    MpfiClass xi(x);
    return Atan(y,xi);
}

//-- atan -------------- Neher, Blomquist ------------------------
//
//  Analytic inverse tangent function
//

void re_vert( const MPFR::MpfrClass& x, const MpfiClass& hx,
              const MPFR::MpfrClass& rew_inf, const MPFR::MpfrClass& rew_sup,
              MPFR::MpfrClass& resxl, MPFR::MpfrClass& resxu )
//
//  Subroutine of analytic inverse tangent function.
//  Evaluate real part on a vertical boundary.
//
{
  if( isZero(x) )
  //  singularities have been handled before, hence Re( w ) > 0
  {
    resxl = 0.0;
    resxu = 0.0;
  }
  else
  {
    if( isPos(x) )
    //  w in quadrants I and/or II
    //  atan is the inverse function of tan(t), t in (-pi/2,pi/2).
    {
      resxl = isPos(rew_sup)? Inf( Atan( 2*hx, rew_sup )/2.0 )
                              : ( isNeg(rew_sup)? Inf( (Atan( 2*hx, rew_sup ) + MpfiClass::Pi() )/2.0 )
                                                : Inf( MpfiClass::Pi()/4 ) );
      resxu = isPos(rew_inf)? Sup( Atan( 2*hx, rew_inf )/2.0 )
                              : ( isNeg(rew_inf) ? Sup( (Atan( 2*hx,rew_inf ) + MpfiClass::Pi() )/2.0 )
                                                 : Sup( MpfiClass::Pi()/4 ) );
    }
    else
    //  w in quadrants III and/or IV
    {
      resxl = isNeg(rew_inf)? Inf( (Atan( 2*hx,rew_inf ) - MpfiClass::Pi())/2.0 )
                            : ( rew_inf > 0.0 ? Inf( Atan( 2*hx,rew_inf )/2.0 )
                                             : -Sup( MpfiClass::Pi()/4 ) );
      resxu = isNeg(rew_sup)? Sup( ( Atan( 2*hx,rew_sup ) - MpfiClass::Pi() )/2.0 )
                            : ( rew_sup > 0.0 ? Sup( Atan( 2*hx,rew_sup )/2.0 )
                                             : -Inf( MpfiClass::Pi()/4 ) );
    }
  }
} //  re_vert

MpfiClass Aux_1_atan(const MPFR::MpfrClass& x)
// x>=0;
// Calculating: ln[ 1+2/(sqrt(1+x^2)-1) ], [x] = x,
// [x] is a point interval !
// Blomquist; 19.02.05;
{
  const int exOv = +536870910;
  const int exUn = -536870900;

  MpfiClass res,
            ix(x),  // ix is point interval with x>=0;
            t;
  long int ex(expo(x)),
           prec = MpfiClass::GetCurrPrecision(),
           prec0 = 677370;

  if (ex>=exOv)
  { // preventing overflow, ex >= +536870910;
    if (ex > prec+2)
    {
      t = 2/ix;
      res = MpfiClass( pred(Inf(t)), succ(succ(Sup(t))) );
    }
    else
    {
      std::cerr << "atan(z): The choosen precision is much too great !" << std::endl;
      exit(1);
    }
  }
  else
    if (ex<=exUn) // x --> 0, ex <= -536870900;
    {
      if ( ex <= -prec/2 -10 && prec <= prec0)
      // ex <= -prec/2 -10 wird wohl immer erfuellt sein!
        res = 2*MpfiClass::Ln2() - 2*ln(ix);
      else // T = ln( 2+x^2+2*sqrt(1+x^2) ) - 2*ln(x);
        res = ln( 2+sqr(ix)+2*sqrt1px2(ix) ) -2*ln(ix);
    }
    else
    { // normal calculation
      t = sqrtp1m1( sqr(ix) ); // t = sqrt(1+x^2)-1
      res = lnp1(2/t); // res = ln[1 + 2/(sqrt(1+x^2)-1) ]
    }
  return res;
} // Aux_1_atan

MpfiClass Q_atan_UPSIGN(const MpfiClass& x, const MpfiClass& y)
{
// x: abs(Re(z));  x is real interval
// y: Inf(Im(z));  y is point interval
// Q_atan_UPSIGN: ln[ 1 + 4y/(x^2+(1-y)^2) ]

  const long int n = 536870910;
  MpfiClass res,t,t1,t2;
  long int ex_x,ex,s;
  if (y==1.0)
  {
    if (Inf(x)>1.0)
    {
      t = 2/x;
      res = lnp1(sqr(t));
    }
    else
      if (Sup(x)<1)
        res = ln(4+sqr(x)) - 2*ln(x);
      else
      { // Punkt 3.:
        t = MpfiClass(Sup(x));  t = 2/t;
        t1 = lnp1(sqr(t));
        t = MpfiClass(Inf(x));
        t2 = ln(4.0+sqr(t)) - 2*ln(t);
        res = MpfiClass(Inf(t1),Sup(t2));
      }
  }
  else
  { // y <> [1,1]
    ex_x = expo( Sup(abs(x)) );
    ex   = expo( Sup(abs(y)) );
    if (ex_x>ex)
      ex = ex_x;  // Maximum
    if (ex>n)
    { // scaling:
      s = n-ex-1;
      t = x;
      times2pown(t,s);  // fast scaling with 2^(s)
      t1 = y;
      times2pown(t1,s); // fast scaling with 2^(s)
      t2 = sqr(t) + sqr( comp(MPFR::MpfrClass(0.5),s+1) - t1 ); // t2: denominator
      t = y / t2; // scaled quotient
      times2pown(t,2*s+2); // back-scaling with 2^(s+2); '+2': factor 4 !!
      res = lnp1(t);
    }
    else
      res = lnp1(4*y/(sqr(x)+sqr(1-y))); // normal calculation
  }
  return res;
} // Q_atan_UPSIGN


void TwoPow2s_y2_x2(const long int s, const MpfiClass& y, const MpfiClass& x, MpfiClass& res)
// 2^(2s) - y^2 - x^2;
// Nur x ist Punktintervall
{
  long int exy( expo(Inf(y)) ), exx( expo(Inf(x)) ),
           prec2( MpfiClass::GetCurrPrecision()/2 );
  MPFR::MpfrClass TwoPows(comp(MPFR::MpfrClass(0.5),s+1));
  // TwoPows = 2^s;
  MPFR::MpfrClass TwoPow_2s(comp(MPFR::MpfrClass(0.5),2*s+1));
  // TwoPows = 2^(2s);
  if (isPoint(y))
  // x,y sind Punktintervalle:
  {
    if ( std::abs(exy-s-1) < std::abs(exx-s-1) )
    { // |y| liegt dichter bei 1
      if (expo(Inf(TwoPows-abs(y))) < -prec2)
        res = (TwoPows-y)*(TwoPows+y) - sqr(x);
      else res = ( TwoPow_2s-sqr(y) ) - sqr(x);
    }
    else
    { // |x| liegt dichter bei 1
      if (expo(Inf(TwoPows-abs(x))) < -prec2)
        res = (TwoPows-x)*(TwoPows+x) - sqr(y);
      else res = (TwoPow_2s-sqr(x)) - sqr(y);
    }
  }
  else // y ist kein Punktintervall
  {
    if (expo(Inf(TwoPows-abs(x))) < -prec2)
      // x liegt sehr dicht bei 2^s
      res = (TwoPows-x)*(TwoPows+x) - sqr(y);
    else // x liegt NICHT dicht bei 2^s
    {
      if ( !hasZero(y) && expo(Inf(TwoPows-abs(y))) < -prec2 && RelDiam(y) < (int)prec2)
      { // y liegt dicht bei 2^s und besitzt kleinen relativen Durchmesser
        res = (TwoPows-y)*(TwoPows+y) - sqr(x);
      }
      else // Normale Rechnung
      {
        res = (TwoPow_2s-sqr(x)) - sqr(y);
      }
    }
  }
} // TwoPow2s_y2_x2

MpfciClass atan( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  if (isNan(z) || isInf(z))
  {
    set_nan(res);
    return res;
  }

  MpfiClass
    rez = Re(z),
    imz = Im(z);

  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  const long int n = 536870910; // For possible scaling

  MpfiClass
    hxl(irez), hxu(srez), hyl(iimz), hyu(simz);

  MPFR::MpfrClass
    resxl, resxu, resyl, resyu;
  //
  //  1st: check for singularities
  //
  if ( ( sign(irez) <= 0 && sign(srez) >= 0 ) && ( iimz <= -1.0 || simz >= 1.0 ) )
  {
    std::cerr << "MpfciClass atan( const MpfciClass& z ); z contains singularities." << std::endl;
    exit(1);
  }
  //
  //  2nd: real part
  //  Re( atan( z ) ) = Arg( w ) / 2, where w = 1 - x^2 - y^2 + i * 2x )
  //
  //  evaluate atan on vertical boundaries
  //
  MpfiClass
  //      y_sqr = sqr( imz ),
  //      rew_l = (1 - y_sqr) - sqr( hxl ),  // Blomquist; before: rew_l = 1 - sqr(hxl) - y_sqr,
  //      rew_u = (1 - y_sqr) - sqr( hxu );  // Blomquist; before: rew_u = 1 - sqr(hxu) - y_sqr;
    rew_l, rew_u;

/*  ------------------------------ Blomquist ---------------------------------------------------  */
/*  ----------       Improvements for Im(z) = [1,1]  or  Im(z) = [-1,-1]        ------------------*/
  bool sqrImz_1 = (iimz==simz) && (iimz==1.0 || iimz==-1.0); // Test for Im(z) = [1,1] or [-1,-1]

  if (sqrImz_1)
  {
      rew_l = -abs(hxl);  hxl = MpfiClass(sign(irez));
      rew_u = -abs(hxu);  hxu = MpfiClass(sign(srez));
  }
  else
  {
    long int ex,s;
    MpfiClass imz_, scf;
    long int ex1 = expo(iimz);  long int ex2 = expo(simz);
    if (ex2>ex1) ex1 = ex2;

    ex = expo(irez);
    if(ex1>ex) ex = ex1; // Maximum
    if (ex>n)
    { // Scaling necessary
      s = n - ex - 1;
      scf = MpfiClass( comp(MPFR::MpfrClass(0.5),s+1) ); // scf: scaling factor 2^s
      times2pown(scf,s); // scf = 2^(2*s);
      times2pown(hxl,s); // hxl = hxl * 2^s
      imz_ = imz;
      times2pown(imz_,s); // imz_ = imz_ * 2^s
      // rew_l = (scf - sqr(imz_)) - sqr(hxl); // here now without overflow!!
      TwoPow2s_y2_x2(s, imz_, hxl, rew_l); // Blomquist, 15.03.2011
      times2pown(hxl,s); // hxl = hxl * 2^s
    }
    else
      // rew_l = (1 - sqr( imz )) - sqr( hxl );
      TwoPow2s_y2_x2(0, imz, hxl, rew_l); // Blomquist, 15.03.2011

    ex = expo(srez);
    if (ex1>ex)
      ex = ex1; // Maximum
    if (ex>n)
    { // Scaling necessary
      s = n - ex - 1;
      scf = MpfiClass( comp(MPFR::MpfrClass(0.5),s+1) ); // scf: scaling factor 2^s
      times2pown(scf,s); // scf = 2^(2*s);
      times2pown(hxu,s); // hxu = hxu * 2^s
      imz_ = imz;
      times2pown(imz_,s); // imz_ = imz_ * 2^s
      // rew_u = (scf - sqr(imz_)) - sqr(hxu); // here now without overflow!!
      TwoPow2s_y2_x2(s, imz_, hxu, rew_u); // Blomquist, 15.03.2011
      times2pown(hxu,s); // hxu = hxu * 2^s
    }
    else
      // rew_u = (1 - sqr( imz )) - sqr( hxu );
      TwoPow2s_y2_x2(0, imz, hxu, rew_u); // Blomquist, 15.03.2011
  }
  //  ------------------------------ Blomquist; 22.02.05; ----------------------------------------

  //
  //  left boundary
  //
  MPFR::MpfrClass rew_inf = Inf( rew_l );
  MPFR::MpfrClass rew_sup = Sup( rew_l );

  re_vert( irez, hxl, rew_inf, rew_sup, resxl, resxu );

  //
  //  right boundary
  //
  rew_inf = Inf( rew_u );
  rew_sup = Sup( rew_u );
  MPFR::MpfrClass res_l, res_u;
  re_vert( srez, hxu, rew_inf, rew_sup, res_l, res_u );

  resxl = min( resxl, res_l );  // Beide Werte sind praktisch gleich
  resxu = max( resxu, res_u );  // Beide Werte sind praktisch gleich
  //
  //  look for extremal values on horizontal boundaries
  //  since atan( x+iy ) = atan( x-iy ),
  //  intersections can be considered in the upper half plane
  //
  MPFR::MpfrClass abs_y_min = Inf( abs( imz ) );

  if ( abs_y_min > 1.0 )
  {
    MpfiClass
      abs_hyl = MpfiClass( abs_y_min ),
      //      abs_hxl = sqrt( sqr( abs_hyl ) - 1.0 );
      abs_hxl = sqrtx2m1(abs_hyl);  // Blomquist;

    if ( Sup( abs_hxl ) > irez && Inf( abs_hxl ) < srez )
    //  extremal curve intersects lower boundary of x+i|y| in quadrant I
    //  intersection in Q I or Q IV: update minimum
    //  resxl = inf( atan( abs_y_min / abs_hxl ) ) / 2.0;
      resxl = Inf( (MpfiClass::Pi() - atan( 1.0 / abs_hxl ) )/2.0 );
    else if( -Inf( abs_hxl ) > irez && -Sup( abs_hxl ) < srez )
    //  extremal curve intersects lower boundary of x+i|y| in quadrant II
    //  intersection in Q II or Q III: update maximum
      resxu = Sup( (atan( 1.0 / abs_hxl ) - MpfiClass::Pi())/2.0 );
  }
  //  3rd: imaginary part
  //  Im( atan( z ) ) = +/- Ln( 1 +/- 4y/( x^2 + (1 -/+ y)^2 ) ) / 4
  //
  //  evaluate atan on horizontal boundaries
  MpfiClass
    abs_rez = abs(rez),
    im_atan_l, im_atan_u;

  if ( sign(iimz) < 0 )

  //    im_atan_l = -ln( 1 - 4 * hyl / ( x_sqr + sqr( 1 + hyl ) ) ) / 4.0;
  //    im_atan_l = -lnp1(-4 * hyl / ( x_sqr + sqr( 1 + hyl ) )) / 4.0;  // Blomquist
    im_atan_l = -Q_atan_UPSIGN(abs_rez,-hyl);  // Blomquist
  else
  //    im_atan_l = ln( 1 + 4 * hyl / ( x_sqr + sqr( 1 - hyl ) ) ) / 4.0;
    im_atan_l = Q_atan_UPSIGN(abs_rez,hyl);  // Blomquist
  times2pown(im_atan_l,-2);
  if (sign(simz) < 0)
  //    im_atan_u = -ln( 1 - 4 * hyu / ( x_sqr + sqr( 1 + hyu ) ) ) / 4.0;
  //    im_atan_u = -lnp1(-4 * hyu / ( x_sqr + sqr( 1 + hyu ) ) ) / 4.0; // Blomquist
    im_atan_u = -Q_atan_UPSIGN(abs_rez,-hyu);  // Blomquist
  else
  //    im_atan_u = ln( 1 + 4 * hyu / ( x_sqr + sqr( 1 - hyu ) ) ) / 4.0;
    im_atan_u = Q_atan_UPSIGN(abs_rez,hyu);  // Blomquist
  times2pown(im_atan_u,-2);
  resyl = min( Inf( im_atan_l ), Inf( im_atan_u ) );
  resyu = max( Sup( im_atan_l ), Sup( im_atan_u ) );
  //
  //  look for extremal values on vertical boundaries,
  //  if vertical boundaries intersect extremal curves
  //
  MPFR::MpfrClass abs_x_min = Inf( abs( rez ) );
  MpfiClass
    x_extr = MpfiClass( abs_x_min ),
    //    y_extr = sqrt( 1.0 + sqr( x_extr ) );
    y_extr = sqrt1px2(x_extr);                     // Blomquist;

  if ( Inf( y_extr ) < simz && Sup( y_extr ) > iimz )
    //  extremal curve intersects left boundary of |x|+iy in quadrant I
    //  update maximum
    //  resyu = Sup( ln( 1 + 4 * y_extr / ( sqr( x_extr ) + sqr( 1 - y_extr ) ) ) ) / 4.0;
    //  resyu = Sup( Aux_1_atan(abs_x_min)/4.0 );    // Blomquist
  {
    rez = Aux_1_atan(abs_x_min);
    times2pown(rez,-2);
    resyu = Sup(rez);
  }

  if ( -Sup( y_extr ) < simz && -Inf( y_extr ) > iimz )
    //  extremal curve intersects left boundary of |x|+iy in quadrant IV
    //  update minimum
    //  resyl = -Sup( ln( 1 + 4 * y_extr / ( sqr( x_extr ) + sqr( 1 - y_extr ) ) ) ) / 4.0;
    //  resyl = -Sup( Aux_1_atan(abs_x_min)/4.0 );  // Blomquist
  {
    rez = Aux_1_atan(abs_x_min);
    times2pown(rez,-2);
    resyl = -Sup(rez);
  }
  res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}
//
//-- end atan -----------------------------------------------------------------

//-- acot ---------------------------------------------------------------------
//
//  Analytic inverse cotangent function
//  acot( z ) = atan( 1/z )
//  The code of acot( z ) is almost identical to the code of atan( z )
//
MpfciClass acot( const MpfciClass& z )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res;
  if (isNan(z) || isInf(z))
  {
    set_nan(res);
    return res;
  }

  MpfiClass
    rez = Re(z),
    imz = Im(z);

  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  const long int n = 536870910; // For possible scaling

  MpfiClass
    hxl(irez), hxu(srez), hyl(iimz), hyu(simz);

  MPFR::MpfrClass
    resxl, resxu, resyl, resyu;
  //
  //  1st: check for singularities
  //
  if ( ( (sign(irez) <= 0) && (sign(srez) >= 0) ) && ( (iimz <= 1.0) && (simz >= -1.0) ) )
  {
    std::cerr << "MpfciClass acot( const MpfciClass& z ): z contains singularities." << std::endl;
    exit(1);
  }
  //
  //  2nd: real part
  //  Re( atan(  z  ) )   = Arg( w ) / 2, where w = 1 - x^2 - y^2 + i * 2x )
  //  Re( atan( 1 / z ) ) = Arg( w ) / 2, where w = x^2 + y^2 - 1 + i * 2x )
  //
  //  evaluate acot on vertical boundaries
  //
  MpfiClass
  //    y_sqr = sqr( imz ),
  //    rew_l = (y_sqr - 1) + sqr(hxl),
  //    rew_u = (y_sqr - 1) + sqr(hxu);
  //    rew_l = (sqr( hxl )-1) + y_sqr,
  //    rew_u = (sqr( hxu )-1) + y_sqr;
    rew_l, rew_u;
//  ------------------------------ Blomquist ---------------------------------------------------
//  ----------       Improvements for Im(z) = [1,1]  or  Im(z) = [-1,-1]        ----------------
  bool sqrImz_1 = (iimz==simz) && (iimz==1.0 || iimz==-1.0); // Test for Im(z) = [1,1] or [-1,-1]

  if (sqrImz_1)
  {
    rew_l = abs(hxl);  hxl = MpfiClass(sign(irez));
    rew_u = abs(hxu);  hxu = MpfiClass(sign(srez));
  }
  else
  {
    long int ex,s;
    MpfiClass imz_, scf;
    long int ex1 = expo(iimz);  long int ex2 = expo(simz);
    if (ex2>ex1)
      ex1 = ex2;

    ex = expo(irez);
    if(ex1>ex)
      ex = ex1; // Maximum
    if (ex>n)
    { // Scaling necessary
      s = n - ex - 1;
      scf = MpfiClass( comp(MPFR::MpfrClass(0.5),s+1) ); // scf: scaling factor 2^s
      times2pown(scf,s); // scf = 2^(2*s);
      times2pown(hxl,s); // hxl = hxl * 2^s
      imz_ = imz;
      times2pown(imz_,s); // imz_ = imz_ * 2^s
      // rew_l = (sqr(imz_) - scf) + sqr(hxl); // here now without overflow!!
      TwoPow2s_y2_x2(s, imz_, hxl, rew_l);
      rew_l = -rew_l;
      times2pown(hxl,s); // hxl = hxl * 2^s
    }
    else
    {
      // rew_l = (sqr( imz ) - 1.0) + sqr( hxl );
      TwoPow2s_y2_x2(0, imz, hxl, rew_l);
      rew_l = -rew_l;
    }

    ex = expo(srez);
    if (ex1>ex)
      ex = ex1; // Maximum
    if (ex>n)
    { // Scaling necessary
      s = n - ex - 1;
      scf = MpfiClass( comp(MPFR::MpfrClass(0.5),s+1) ); // scf: scaling factor 2^s
      times2pown(scf,s); // scf = 2^(2*s);
      times2pown(hxu,s); // hxu = hxu * 2^s
      imz_ = imz;
      times2pown(imz_,s); // imz_ = imz_ * 2^s
      // rew_u = (sqr(imz_) - scf) + sqr(hxu); // here now without overflow!!
      TwoPow2s_y2_x2(s, imz_, hxu, rew_u);
      rew_u = -rew_u;
      times2pown(hxu,s); // hxu = hxu * 2^s
    }
    else
    {
      // rew_u = (sqr( imz )-1.0) + sqr( hxu );
      TwoPow2s_y2_x2(0, imz, hxu, rew_u);
      rew_u = -rew_u;
    }
  }
//  ------------------------------ Blomquist; 22.02.05; ---------------------------------------

  //
  //  left boundary
  //
  MPFR::MpfrClass rew_inf = Inf( rew_l );
  MPFR::MpfrClass rew_sup = Sup( rew_l );
  re_vert( irez, hxl, rew_inf, rew_sup, resxl, resxu );
  //
  //  right boundary
  //
  rew_inf = Inf( rew_u );
  rew_sup = Sup( rew_u );
  MPFR::MpfrClass res_l, res_u;
  re_vert( srez, hxu, rew_inf, rew_sup, res_l, res_u );

  resxl = min( resxl, res_l );
  resxu = max( resxu, res_u );
  //
  //  look for extremal values on horizontal boundaries
  //  since acot( x+iy ) = acot( x-iy ),
  //  intersections can be considered in the upper half plane
  //
  MPFR::MpfrClass abs_y_min = Inf( abs( imz ) );

  if ( abs_y_min > 1.0 )
  {
    MpfiClass
      abs_hyl = MpfiClass( abs_y_min ),
      //  abs_hxl = sqrt( sqr( abs_hyl ) - 1.0 );
      abs_hxl = sqrtx2m1(abs_hyl);  // Blomquist;
    if ( Sup( abs_hxl ) > irez && Inf( abs_hxl ) < srez )
    //  extremal curve intersects lower boundary of x+i|y| in quadrant I
    //  intersection in Q I or Q IV: update maximum
      resxu = Sup( atan( 1.0 / abs_hxl ) / 2.0 );
    if ( -Inf( abs_hxl ) > irez && -Sup( abs_hxl ) < srez )
    //  extremal curve intersects lower boundary of x+i|y| in quadrant II
    //  intersection in Q II or Q III: update minimum
      resxl = -Sup( atan( 1.0 / abs_hxl ) / 2.0 );
  }
  //
  //  3rd: imaginary part
  //  Im( atan( z ) ) = +/- Ln( 1 +/- 4y/( x^2 + (1 -/+ y)^2 ) ) / 4
  //  Im( acot ) = - Im ( atan ): We calculate Im( atan ) and return "-"
  //
  //  evaluate atan on horizontal boundaries
  //
  MpfiClass
  //  x_sqr = sqr( rez ), // overflow is avoided by calling Q_atan_UPSIGN(...)
    im_atan_l, im_atan_u,
    abs_rez = abs(rez);  // Blomquist;
  if ( sign(iimz) < 0 )
  //    im_atan_l = -ln( 1 - 4 * hyl / ( x_sqr + sqr( 1 + hyl ) ) ) / 4.0;
    im_atan_l = -Q_atan_UPSIGN(abs_rez,-hyl);  // Blomquist
  else
  //    im_atan_l = ln( 1 + 4 * hyl / ( x_sqr + sqr( 1 - hyl ) ) ) / 4.0;
    im_atan_l = Q_atan_UPSIGN(abs_rez,hyl);  // Blomquist
  times2pown(im_atan_l,-2);

  if( sign(simz) < 0 )
  //    im_atan_u = -ln( 1 - 4 * hyu / ( x_sqr + sqr( 1 + hyu ) ) ) / 4.0;
    im_atan_u = -Q_atan_UPSIGN(abs_rez,-hyu);  // Blomquist
  else
  //    im_atan_u = ln( 1 + 4 * hyu / ( x_sqr + sqr( 1 - hyu ) ) ) / 4.0;
    im_atan_u = Q_atan_UPSIGN(abs_rez,hyu);  // Blomquist
  times2pown(im_atan_u,-2);

  resyl = min( Inf( im_atan_l ), Inf( im_atan_u ) );
  resyu = max( Sup( im_atan_l ), Sup( im_atan_u ) );
  //
  //  look for extremal values on vertical boundaries,
  //  if vertical boundaries intersect extremal curves
  //
  MPFR::MpfrClass abs_x_min = Inf( abs( rez ) );
  MpfiClass x_extr = MpfiClass( abs_x_min ),
  //    y_extr = sqrt( 1.0 + sqr( x_extr ) );
  y_extr = sqrt1px2(x_extr);  // Blomquist
  if ( Inf( y_extr ) < simz && Sup( y_extr ) > iimz )
  //  extremal curve intersects left boundary of |x|+iy in quadrant I
  //  update maximum
  //  resyu = Sup( ln( 1 + 4 * y_extr / ( sqr( x_extr ) + sqr( 1 - y_extr ) ) ) ) / 4.0;
  //  resyu = Sup( Aux_1_atan(abs_x_min)/4.0 );    // Blomquist
  {
    rez = Aux_1_atan(abs_x_min);
    times2pown(rez,-2);
    resyu = Sup(rez);
  }

  if ( -Sup( y_extr ) < simz && -Inf( y_extr ) > iimz )
  //  extremal curve intersects left boundary of |x|+iy in quadrant IV
  //  update minimum
  //  resyl = -Sup( ln( 1 + 4 * y_extr / ( sqr( x_extr ) + sqr( 1 - y_extr ) ) ) ) / 4.0;
  //  resyl = -Sup( Aux_1_atan(abs_x_min)/4.0 );  // Blomquist
  {
    rez = Aux_1_atan(abs_x_min);
    times2pown(rez,-2);
    resyl = -Sup(rez);
  }

  res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( -resyu, -resyl ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}
//
//-- end acot -----------------------------------------------------------------

MpfciClass asinh( const MpfciClass& z )
//
//  asinh( Z ) = i * asin( -i * z )
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res = asin( MpfciClass( Im(z), -Re(z) ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return MpfciClass( -Im(res), Re(res) );
}
//
//-- end asinh ----------------------------------------------------------------

//-- acosh --------------------------------------------------------------------
//
MpfciClass acosh( const MpfciClass& z )
//
//  acosh( z ) = i * acos( z ) = +/- i * ( pi / 2 - asin( z ) )
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res;

  MpfiClass
    rez = Re(z),
    imz = Im(z);

  MPFR::MpfrClass
    irez = Inf(rez),
    srez = Sup(rez),
    iimz = Inf(imz),
    simz = Sup(imz);

  MpfiClass
    hxl(irez), hxu(srez), hyl(iimz), hyu(simz);

  MPFR::MpfrClass
    resxl, resxu, resyl, resyu;
  //
  //  1st: check for singularities
  //
  if ( ( sign(iimz) <= 0 && sign(simz) >= 0 ) && ( irez < 1.0 ) )
  {
    std::cerr << "MpfciClass acosh( const MpfciClass& z ); z contains singularities." << std::endl;
    exit(1);
  }
  //  With this restriction the complex interval argument and the real axis must not have any common
  //  point, if irez < +1;
  //  So for example the negative real axis must not be touched from above if irez<1, although this
  //  should be possible if the principal branch is considered! So the above restriction is too widely in
  //  some cases;  Blomquist, 21.06.2005;
  //
  //  2nd: z in upper half plane (or on the real axis)
  //  acosh( z ) =  + i * ( pi / 2 - asin( z ) )
  //
  if( sign(iimz)>0 )
  {
    res = acos(z);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return MpfciClass( -Im(res), Re(res) );
  }
  //
  //  3rd: z in lower half plane
  //  acosh( z ) =  - i * ( pi / 2 - asin( z ) )
  //
  if( sign(simz) < 0 )
  {
  // cinterval res = HALFPI() - asin( z );
    MpfciClass res = acos(z);  // Blomquist, 14.06.2005
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return MpfciClass( Im(res), -Re(res) );
  }
  //
  //  z intersects [1,infinity)
  //
  //  real part
  //  minimum on the left on real axes, maximum in lower or upper right corner
  //
  resxl = Inf( acosh( hxl ) );
  MpfiClass ytilde( max( -iimz, simz ) );
  //  resxu = Sup( acosh( f_aux_asin( hxu, ytilde ) ) );
  resxu = Sup( ACOSH_f_aux(hxu,ytilde) ); // Blomquist, 14.06.2005;
  //
  //  imaginary part
  //  minimum in lower left corner, maximum in upper left corner
  //
  //   resyl = -Sup( acos( hxl / f_aux_asin( hxl, hyl ) ) );
  resyl = -Sup( Acos_beta(hxl,hyl) ); // Blomquist, 14.06.2005;
  //  resyu =  Sup( acos( hxl / f_aux_asin( hxl, hyu ) ) );
  resyu = Sup( Acos_beta(hxl,hyu) );

  res = MpfciClass( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return res;
}
//
//-- end acosh ----------------------------------------------------------------

//-- atanh --------------------------------------------------------------------
//
MpfciClass atanh( const MpfciClass& z )
//
//  atanh( z ) = - i * atan( i * z )
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res = atan( MpfciClass( -Im(z), Re(z) ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return MpfciClass( Im(res), -Re(res) );
}
//
//-- end atanh ----------------------------------------------------------------

//-- acoth --------------------------------------------------------------------
//
MpfciClass acoth( const MpfciClass& z )
//
//  acoth( z ) = i * acot( i * z )
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass res = acot(  MpfciClass( -Im(z), Re(z) ) );
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);

  return MpfciClass( -Im(res), Re(res) );
}
//
//-- end acoth ----------------------------------------------------------------

//
//------- power_fast ----------------------------------------------------------

MpfciClass power_fast( const MpfciClass& z, int n )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;
  if( n == 0 )
    res = 1;
  else if( n == 1 )
    res = z;
  else if( n == -1 )
    res = 1 / z;
  else if( n == 2 )
    res = sqr(z);
  else
    //  n >= 3  or  n <= -2
    //  If z is a large interval, z^n is a distorted set, for which the
    //  inclusion into a complex rectangle contains large overestimation.
    //  For example, if  n * Arg( z )  intersects the cartesian axes
    //  more than once then  0  is contained in the rectangular enclosure
    //  of z^n.
    //  For n <= -2, also inversion of z or z^n is required;
    //  both inversions lead to large overestimation of the resulting interval.
    //
    //  The computation of an optimal rectangular enclosure is implemented
    //  in power(z,n). In power_fast(z,n), z is enclosed into a sector S of
    //  an annulus. S^n is again some sector S' of a (different) annulus.
    //  S' is calculated exactly (apart from roundoff), and then enclosed
    //  into a rectangle. There is a certain amount of overestimation
    //  compared with the optimal rectangular enclosure of z^n, but the
    //  calculations are much cheaper here.
  {
    MpfiClass abs_z = abs( z );

    if( n < 0 && Inf( abs_z ) == 0.0 )
    //  z contains 0
    {
      std::cerr << "MpfciClass power_fast(const MpfciClass& z, int n ); z contains 0." << std::endl;
      exit(1);
    }
    if( Sup( abs_z ) == 0.0 )
      res = 0;
    else
    {
      MpfiClass arg_z = arg( z );
      MpfiClass abs_z_n = exp( n * ln( abs_z ) );

      res = MpfciClass( abs_z_n * cos( n * arg_z ),
                        abs_z_n * sin( n * arg_z ) );
    }
  }
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}
//
//-- end power_fast -----------------------------------------------------------

//-- power -------------------- M. Neher --------------------------------------
//
//  Power function for integer powers with optimal (save roundoff) accuracy.
//
//  The extremal curves of Re(z^n) and Im(z^n) are straight lines defined
//  by the rays  arg(z) = k pi/ ( 2n - 2 ), k = 0,...4n-5.
//
//  Intersections of these rays with the boundary of z are called
//  "ray intersections" in the following.
//
MpfciClass power_point( const MpfciClass& z, int n )
//
//  z^n for A POINT INTERVAL z ONLY.
//  Do not use this as a general function
//  - it's only a subroutine for power.
//  The calculation may break down otherwise.
//  The case 0 in z for negative n is handled in power(z,n).
//
{
  if ( Inf( Re(z) ) == 0.0 && Inf( Im(z) ) == 0.0 )
    //  if z is a valid point interval, it must be 0
    return MpfciClass( 0 );
  else
  {
    MpfiClass abs_z = abs( z );
    MpfiClass arg_z = arg( z );
    MpfiClass abs_z_n = exp( n * ln( abs_z ) );

    return MpfciClass( abs_z_n * cos( n * arg_z ),
                       abs_z_n * sin( n * arg_z ) );
  }
}

void update_res( const MpfciClass& res,
                 MPFR::MpfrClass& resxl, MPFR::MpfrClass& resxu,
                 MPFR::MpfrClass& resyl, MPFR::MpfrClass& resyu )
//  Subroutine of power(z,n).
//  Update extremal values of power function.
{
  resxl = min( resxl, Inf( Re(res) ) );
  resxu = max( resxu, Sup( Re(res) ) );
  resyl = min( resyl, Inf( Im(res) ) );
  resyu = max( resyu, Sup( Im(res) ) );
}

void horizontal_check(
     const MpfiClass& hy, MPFR::MpfrClass hyy, const MpfiClass& arg_h,
     MPFR::MpfrClass  irez,  MPFR::MpfrClass srez,
     MPFR::MpfrClass& resxl, MPFR::MpfrClass& resxu,
     MPFR::MpfrClass& resyl, MPFR::MpfrClass& resyu, int n )
//  Subroutine of power(z,n).
//  Check all relevant ray intersections on a horizontal boundary.
{
  int r_int, il1, il2, iu1, iu2;
  MpfciClass res;
  //
  //  Here, the most difficult task is
  //  to determine the relevant ray intersections
  //  Both arg_hl and n can be negative, which makes it very complicated
  //  to decide the correct indexes for the "rightmost" intersections, etc.
  //
  //  To simplify the distinction of cases, we introduce the variable
  //  nofrays (number of rays) = abs( n-1 )
  //
  //  Note that we still have to pass n to power_point
  //
  iu1 = n-1;  if (iu1<0) iu1 = -iu1;
  int nofrays = iu1;

  MPFR::MpfrClass arg_hlR = Inf( 2 * nofrays * arg_h / MpfiClass::Pi() );
  if( sign(arg_hlR) >= 0 )
    r_int = to_int(arg_hlR, RoundToZero);
  else
    r_int = to_int(arg_hlR-1, RoundToZero);
  il1 = r_int + 1;

  arg_hlR = Sup( 2 * nofrays * arg_h / MpfiClass::Pi() );
  if( sign(arg_hlR) >= 0 )
    r_int = to_int(arg_hlR, RoundToZero);
  else
    r_int = to_int(arg_hlR-1, RoundToZero);
  iu1 = int( r_int );

  if( iu1 >= il1 )
  {
   //  at least one ray intersection
   //  maybe more?
      if( iu1 > il1 + 3 )
	//
	//  we're in trouble:
	//  there are more than 4 ray intersections
	//  now we must decide which of these are relevant
	//  depending on il1, iu1, n and on the quadrants,
	//  4 to 7 intersections must be considered
	//
      { // Neu Blomquist 13.12.2010
	if( n > 0 )
	  //  outmost intersections are relevant
	{
	    if( sign(irez) >= 0 )
	      //  z in quadrants I or IV:
	      //  only 4 rightmost intersections are relevant
	      {
		if ( isNeg(hyy) )
		  //  quadrant IV
		  il1 = iu1 - 3;
		else
		  //  quadrant I
		  iu1 = il1 + 3;
	      }
	    else if( sign(srez) <= 0 )
	      //  z in quadrants II or III:
	      //  only 4 leftmost intersections are relevant
	      {
		if( isPos(hyy) )
		  //  quadrant II
		  il1 = iu1 - 3;
		else
		  //  quadrant III
		  iu1 = il1 + 3;
	      }
	    else
	      //  z intersects imaginary axes
	      //  we may have two lists of intersections!
	      {
		iu2 = iu1;
		il2 = iu2 - 3;
		iu1 = il1 + 3;
		//  remove intersection points that are contained in both lists
		if( il2 <= iu1 )
		  il2 = iu1 + 1;
		//
		//  here, list 2 is processed
		//  list 1 is processed below
		//
		for(int i = il2; i <= iu2; i++)
		  {
		    MpfiClass cotangle = cot( ( MpfiClass::Pi() * i ) / ( 2 * nofrays ) );
		    res = power_point( MpfciClass( hy * cotangle , hy ), n );
		    update_res( res, resxl, resxu, resyl, resyu );
		  }
	      }
	}
	else
	  //  n < 0:
	  //  innermost intersections are relevant
	{
	    if( sign(irez) >= 0 )
	      //  z in quadrants I or IV:
	      //  only 4 leftmost intersections are relevant
	      {
		if( isPos(hyy) )
		  //  quadrant I
		  il1 = iu1 - 3;
		else
		  //  quadrant IV
		  iu1 = il1 + 3;
	      }
	    else if( sign(srez) <= 0 )
	      //  z in quadrants II or III:
	      //  only 4 rightmost intersections are relevant
	      {
		if( isNeg(hyy) )
		  //  quadrant III
		  il1 = iu1 - 3;
		else
		  //  quadrant II
		  iu1 = il1 + 3;
	      }
	    else
	      //  z intersects imaginary axes
	      //  we have one lists of 5 to 7 intersections
	      {
		if( isPos(hyy) )
		  {
		    il2 = nofrays - 3;
		    iu2 = nofrays + 3;
		  }
		else
		  {
		    il2 = -nofrays - 3;
		    iu2 = -nofrays + 3;
		  }
		//  list 1 contains all intersections
		//  list 2 is a filter for all relevant intersections
		//  store intersection of lists 1 and 2 in list 1
		il1 = ( il1 > il2 ? il1 : il2 );
		iu1 = ( iu1 < iu2 ? iu1 : iu2 );
	      }
	}
      } // Neu Blomquist 13.12.2010
      //
      //  list 1 has been left for processing
      //
      for (int i = il1; i <= iu1; i++)
      {
	MpfiClass cotangle = cot( ( MpfiClass::Pi() * i ) / ( 2 * nofrays ) );
        res = power_point( MpfciClass( hy * cotangle , hy ), n );
	update_res( res, resxl, resxu, resyl, resyu );
      }
  }
}

void vertical_check(
     const MpfiClass& hx, MPFR::MpfrClass hxx, const MpfiClass& arg_h,
     MPFR::MpfrClass iimz,   MPFR::MpfrClass simz,
     MPFR::MpfrClass& resxl, MPFR::MpfrClass& resxu,
     MPFR::MpfrClass& resyl, MPFR::MpfrClass& resyu, int n )
//  Subroutine of power(z,n).
//  Check all relevant ray intersections on a vertical boundary.
{
  int r_int, il1, il2, iu1, iu2;
  MpfciClass res;
  //
  //  Here, the most difficult task is
  //  to determine the relevant ray intersections
  //  Both arg_hl and n can be negative, which makes it very complicated
  //  to decide the correct indexes for the topmost intersections, etc.
  //
  //  To simplify the distinction of cases, we introduce the variable
  //  nofrays (number of rays) = abs( n-1 )
  //
  //  Note that we still have to pass n to power_point
  //
  iu1 = n-1;  if (iu1<0) iu1 = -iu1;
  int nofrays = iu1;

  MPFR::MpfrClass arg_hlR = Inf( 2 * nofrays * arg_h / MpfiClass::Pi() );
  if( sign(arg_hlR) >= 0 )
    r_int = to_int(arg_hlR, RoundToZero);
  else
    r_int = to_int(arg_hlR-1, RoundToZero);
  il1 = r_int + 1;

  arg_hlR = Sup( 2 * nofrays * arg_h / MpfiClass::Pi() );
  if( sign(arg_hlR) >= 0 )
    r_int = to_int(arg_hlR, RoundToZero);
  else
    r_int = to_int(arg_hlR-1, RoundToZero);
  iu1 = int( r_int );

  if( iu1 >= il1 )
  {
  //  at least one ray intersection
  //  maybe more?
      if( iu1 > il1 + 3 )
	//
	//  we're in trouble:
	//  there are more than 4 ray intersections
	//  now we must decide which of these are relevant
	//  depending on il1, iu1, n and on the quadrants,
	//  4 to 7 intersections must be considered
	//
      { // Neu Blomquist 13.12.2010
	if( n > 0 )
	  //  outmost intersections are relevant
	{
	    if( sign(iimz) >= 0 )
	      //  z in quadrants I or II:
	      //  only 4 topmost intersections are relevant
	      {
		if ( isPos(hxx) )
		  //  quadrant I
		  il1 = iu1 - 3;
		else
		  //  quadrant II
		  iu1 = il1 + 3;
	      }
	    else if( sign(simz) <= 0 )
	      //  z in quadrants III or IV:
	      //  only 4 lowest intersections are relevant
	      {
		if( isNeg(hxx) )
		  //  quadrant III
		  il1 = iu1 - 3;
		else
		  //  quadrant IV
		  iu1 = il1 + 3;
	      }
	    else
	      //  z intersects real axes
	      //  we may have two lists of intersections!
	      {
		iu2 = iu1;
		il2 = iu2 - 3;
		iu1 = il1 + 3;
		//  remove intersection points that are contained in both lists
		if( il2 <= iu1 )
		  il2 = iu1 + 1;
		//
		//  here, list 2 is processed
		//  list 1 is processed below
		//
		for(int i = il2; i <= iu2; i++)
		  {
		    MpfiClass tangle = tan( ( MpfiClass::Pi() * i ) / ( 2 * nofrays ) );
		    res = power_point( MpfciClass( hx, hx * tangle ), n );
		    update_res( res, resxl, resxu, resyl, resyu );
		  }
	      }
	}
	else
	  //  n < 0:
	  //  innermost intersections are relevant
	{
	    if( sign(iimz) >= 0 )
	      //  z in quadrants I or II:
	      //  only 4 lowest intersections are relevant
	      {
		if ( isNeg(hxx) )
		  //  quadrant II
		  il1 = iu1 - 3;
		else
		  //  quadrant I
		  iu1 = il1 + 3;
	      }
	    else if( sign(simz) <= 0 )
	      //  z in quadrants III or IV:
	      //  only 4 topmost intersections are relevant
	      {
		if ( isPos(hxx) )
		  //  quadrant IV
		  il1 = iu1 - 3;
		else
		  //  quadrant III
		  iu1 = il1 + 3;
	      }
	    else
	      //  z intersects real axes
	      //  we have one lists of 5 to 7 intersections
	      {
		if ( isPos(hxx) )
		  {
		    il2 = -3;
		    iu2 =  3;
		  }
		else
		  {
		    il2 = 2 * nofrays - 3;
		    iu2 = 2 * nofrays + 3;
		  }
		//  list 1 contains all intersections
		//  list 2 is a filter for all relevant intersections
		//  store intersection of lists 1 and 2 in list 1
		il1 = ( il1 > il2 ? il1 : il2 );
		iu1 = ( iu1 < iu2 ? iu1 : iu2 );
	      }
	}
      } // Neu Blomquist 13.12.2010
      //
      //  list 1 has been left for processing
      //
      for(int i = il1; i <= iu1; i++)
	{
	  MpfiClass tangle = tan( ( MpfiClass::Pi() * i ) / ( 2 * nofrays ) );
	  res = power_point( MpfciClass( hx, hx * tangle ), n );
	  update_res( res, resxl, resxu, resyl, resyu );
	}
  }
}

MpfciClass power( const MpfciClass& z, int n ) // ---- Neher, Blomquist ----------
//
//  Power function for integer powers with optimal (save roundoff) accuracy.
//
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);
  MpfciClass res;

  if( n == 0 )
    res = MpfciClass( 1 );
  else if( n == 1 )
    res = z;
  else if( n == -1 )
    res = 1 / z;
  else if( n == 2 )
    res = sqr(z);
  else
    //  n >= 3  or  n <= -2
    //
    //  n may have a large absolute value and z may be a large interval.
    //  In this case, we calculate function values at specific points
    //  and look for min and max.
    //
    //  An implementation with fewer function evaluations would be possible,
    //  at the expense of an unreadable source code.
    {
      MpfiClass abs_z = abs( z );

      if ( n < 0 && isZero( Inf(abs_z) ) )
      //  z contains 0
      {
        std::cerr << "MpfciClass power(const MpfciClass& z, int n ); z contains 0." << std::endl;
	exit(1);
      }
      if ( isZero(Sup( abs_z )) )
        res = MpfciClass( 0 );
      else
        {
	  MPFR::MpfrClass
	    irez = Inf(Re(z)),
	    srez = Sup(Re(z)),
	    iimz = Inf(Im(z)),
	    simz = Sup(Im(z));
	  MpfiClass
	    hxl( irez ), hxu( srez ), hyl( iimz ), hyu( simz );
	  MPFR::MpfrClass
	    resxl,  resxu, resyl, resyu;
	  //
	  //  extremal values lie in corner points or on intersections of the
	  //  boundary of z with any ray  arg( w ) = k*Pi/(2*(n-1))
	  //
	  //  first check the corners of z
	  //
	  res = power_point( MpfciClass( hxl, hyl ), n );
	  resxl = Inf( Re(res) );
	  resxu = Sup( Re(res) );
	  resyl = Inf( Im(res) );
	  resyu = Sup( Im(res) );
	  res = power_point( MpfciClass( hxu, hyl ), n );
	  update_res( res, resxl, resxu, resyl, resyu );
	  res = power_point( MpfciClass( hxl, hyu ), n );
	  update_res( res, resxl, resxu, resyl, resyu );
	  res = power_point( MpfciClass( hxu, hyu ), n );
	  update_res( res, resxl, resxu, resyl, resyu );
	  //
	  //  consider the origin, if it is a boundary point
	  //  (negative n have been taken care of above)
	  //
          //	  if( irez * srez <= 0.0 && iimz * simz <= 0.0 &&
          //               irez * srez * iimz * simz == 0.0 )
	  if ( 0<=Re(z) && 0<=Im(z) &&
	       ( isZero(irez) || isZero(srez) || isZero(iimz) || isZero(simz) ) )
	    update_res( MpfciClass(0), resxl, resxu, resyl, resyu );
	  //
	  //  now check for ray intersections
	  //  for each quadrant and each boundary, we must consider
	  //  the function values at at most 4 consecutive intersections
	  //
	  //  Ia: lower boundary
	  //
	  if( iimz != 0.0 )
	    {
	      MpfiClass arg_h = arg( MpfciClass( Re(z), hyl ) );

	      //  check if there are ray intersections
	      horizontal_check( hyl, iimz, arg_h, irez, srez,
				resxl, resxu, resyl, resyu, n );
	    }
	  //  Ib: upper boundary
	  if( simz != 0.0 )
	    {
	      MpfiClass arg_h = arg( MpfciClass( Re(z), hyu ) );

	      //  check if there are ray intersections
	      horizontal_check( hyu, simz, arg_h, irez, srez,
				resxl, resxu, resyl, resyu, n );
	    }
	  //  IIa: left boundary
	  if( irez != 0.0 )
	    {
	      MpfiClass arg_h = arg( MpfciClass( hxl, Im(z) ) );

	      //  check if there are ray intersections
	      vertical_check( hxl, irez, arg_h, iimz, simz,
			      resxl, resxu, resyl, resyu, n );
	    }
	  //  IIb: right boundary
	  if( srez != 0.0 )
	  {
	    MpfiClass arg_h = arg( MpfciClass(  hxu, Im(z) ) );

	    //  check if there are ray intersections
	    vertical_check( hxu, srez, arg_h, iimz, simz,
			    resxl, resxu, resyl, resyu, n );
	  }
	  res = MpfciClass ( MpfiClass( resxl, resxu ), MpfiClass( resyl, resyu ) );
	  // return cinterval( interval( resxl, resxu ), interval( resyl, resyu ) );
	}
    }
  res.RoundPrecision(prec_old);
  MPFI::MpfiClass::SetCurrPrecision(prec_old);
  return res;
}
//
//-- end power ----------------------------------------------------------------


//-- pow ------------------------------------------------------------ 040627 --
//
//  Analytic power function for real interval exponent, based on Ln.
//

MpfciClass pow( const MpfciClass& z, const MpfiClass& p )
{
    return exp( p*Ln(z) );
}

//
//-- end pow ------------------------------------------------------------------

//-- pow ------------------------------------------------------------ 040627 --
//
//  Analytic power function for complex interval exponent, based on Ln.
//

MpfciClass pow( const MpfciClass& z, const MpfciClass& w )
{
    return exp( w*Ln(z) );
}

//
//-- end pow ------------------------------------------------------------------


//-- pow_all -------------------------------------------------------- 041013 --
//
//  Non-analytic power function for real interval exponent.
//
//  If 0 \not\in z, then compute four rectangular intervals that comprehend
//  an annulus which contains all values  zeta^phi, zeta in z, phi in p.
//
//  If 0 in z and negative reals in p, then abort execution
//  (potential modification: return the entire complex plane).
//
std::list<MpfciClass> pow_all( const MpfciClass& z, const MpfiClass& p )
{
  PrecisionType prec = z.GetPrecision(),
            prec_old = MPFR::MpfrClass::GetCurrPrecision();
  if (prec < p.GetPrecision())
    prec = p.GetPrecision();
  if (prec<prec_old) prec = prec_old;
  MPFI::MpfiClass::SetCurrPrecision(prec);

  MpfciClass T;
  MpfiClass abs_z = abs( z );

  if ( isPos( Inf(abs_z) ) )
  {
    MpfiClass abs_z_p = exp( p*ln( abs_z ) );
    //  Inner and outer radii of the annulus are inf/sup( abs_z_n )
    //  Inscribed square has side length sqrt( 2 ) * rad_1
    MpfiClass rad_1 = Inf( abs_z_p ) / sqrt(MpfiClass(2));
    MpfiClass rad_2 = MpfiClass(Sup( abs_z_p ));

    std::list<MpfciClass> res;

    //  4 intervals covering the annulus, counter-clockwise
    T = MpfciClass( MpfiClass(  Inf( rad_1 ),  Sup( rad_2 ) ), MpfiClass( -Sup( rad_1 ),  Sup( rad_2 ) ) );
    T.RoundPrecision(prec_old);
    res.push_back( T );

    T = MpfciClass( MpfiClass( -Sup( rad_2 ),  Sup( rad_1 ) ), MpfiClass(  Inf( rad_1 ),  Sup( rad_2 ) ) );
    T.RoundPrecision(prec_old);
    res.push_back( T );

    T = MpfciClass( MpfiClass( -Sup( rad_2 ), -Inf( rad_1 ) ), MpfiClass( -Sup( rad_2 ),  Sup( rad_1 ) ) );
    T.RoundPrecision(prec_old);
    res.push_back( T );

    T = MpfciClass( MpfiClass( -Sup( rad_1 ),  Sup( rad_2 ) ), MpfiClass( -Sup( rad_2 ), -Inf( rad_1 ) ) );
    T.RoundPrecision(prec_old);
    res.push_back( T );

    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return res;
  }
  else
  //  0 in z
  {
    if ( isPos(Inf( p )) )
    //
    //  All values   zeta^phi, zeta in z, phi in p   lie in a disk
    //
    {
      MpfiClass abs_z_p = exp( p*  ln( MpfiClass( Sup( abs_z ) ) ) );
      MPFR::MpfrClass rad_p = Sup( abs_z_p );

      std::list<MpfciClass> res;

      T = MpfciClass( MpfiClass( -rad_p, rad_p ), MpfiClass( -rad_p, rad_p ) );
      T.RoundPrecision(prec_old);
      res.push_back( T );

      MPFI::MpfiClass::SetCurrPrecision(prec_old);
      return res;
    }
    else
    {
      //
      //  The set   zeta^phi, zeta in z, phi in p   is unbounded
      //  if inf( p ) < 0.  0^p is undefined for p <= 0.
      //
      MPFI::MpfiClass::SetCurrPrecision(prec_old);
      std::cerr << "pow_all(MpfciClass, MpfiClass); 0^p is undefined for p <= 0." << std::endl;
      exit(1);
    }
  }
}
//
//-- end pow_all --------------------------------------------------------------

  MpfciClass reci (const MpfciClass& z)
  // Calculating an optimal inclusion of 1/z;
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);
    MpfciClass res;
    res = MpfciClass( x_div_x2py2(Re(z), Im(z)),  x_div_x2py2(-Im(z), Re(z)) );

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return res;
  }

  MpfciClass sqrt1px2_infty_ci(const MpfiClass& x, const MpfiClass& y)
  {
    MpfciClass res, Z(x,y), Dc;  // res = Z = x + i*y;
    MpfiClass D(-MPFR::minfloat(), MPFR::minfloat());
    Dc = MpfciClass(D, D);  // Dc: complex Delta

    res = reci(Z);
    res = ((2 - res)*(2 + res))/Z;
    times2pown(res,-3);  // res = (2-1/Z)*(2+1/Z)/Z/8
    res = res + Dc;
    res = Z + res; // res: Inclusion of f(Z) = sqrt(1+Z^2), in case of: |Z| ---> +infty;

    return res;
  }

  MpfiClass sqrt1px2_Re(const MpfiClass& x, const MpfiClass& y)
  {
    MpfiClass res, xa(abs(x)) ,ya(abs(y));
    // The comlex interval z = xa + i*ya lies in the first quadrant!
    res = MpfiClass( Re_sqrt1px2(Inf(xa), Sup(ya), RoundDown),
		     Re_sqrt1px2(Sup(xa), Inf(ya), RoundUp  ) );
    return res;
  }

  MpfiClass sqrt1px2_Im(const MpfiClass& x, const MpfiClass& y)
  {
    int k;
    MpfiClass res, xr(x), yr(y);
    MPFR::MpfrClass m, M, t;
    if (!isPos(Sup(x)))  // Sup(x)<=0
    {
      xr = -x; yr = -y;
    }
    if (isNeg(Inf(xr))) k=1;
    else // Inf(xr)>=0:
    {
      if (!isNeg(Inf(yr))) k=2;    // if (Inf(yr)>=0) k=2;
      else
      {
	if (!isPos(Sup(yr))) k=3;  // if (Sup(yr)<=0) k=3;
	else k=4;
      }
    }
    switch (k)
    {
      case 1:
	if (!isNeg(Inf(yr)))
	{
	  res = MpfiClass( Im_sqrt1px2(Inf(xr), Sup(yr), RoundDown),
		           Im_sqrt1px2(Sup(xr), Sup(yr), RoundUp  ) );
	}
	else
	{
	  if (!isPos(Sup(yr)))
            res = MpfiClass( Im_sqrt1px2(Sup(xr), Inf(yr), RoundDown),
		             Im_sqrt1px2(Inf(xr), Inf(yr), RoundUp  ) );
	  else
	  {
	    m = Im_sqrt1px2(Sup(xr), Inf(yr), RoundDown);
	    t = Im_sqrt1px2(Inf(xr), Sup(yr), RoundDown);
	    if (t<m) m=t;
	    M = Im_sqrt1px2(Inf(xr), Inf(yr), RoundUp);
	    t = Im_sqrt1px2(Sup(xr), Sup(yr), RoundUp);
	    if (t>M) M = t;
	    res = MpfiClass(m,M);
	  }
	}
	break;
      case 2:
	res = MpfiClass( Im_sqrt1px2(Inf(xr), Inf(yr), RoundDown),
		         Im_sqrt1px2(Sup(xr), Sup(yr), RoundUp  ) );
	break;
      case 3:
	res = MpfiClass( Im_sqrt1px2(Sup(xr), Inf(yr), RoundDown),
		         Im_sqrt1px2(Inf(xr), Sup(yr), RoundUp  ) );
	break;
      case 4:
	res = MpfiClass( Im_sqrt1px2(Sup(xr), Inf(yr), RoundDown),
		         Im_sqrt1px2(Sup(xr), Sup(yr), RoundUp  ) );
	break;
    }

    return res;
  }

  MpfciClass sqrt1px2(const MpfciClass& z)
  // Calculating an optimal inclusion of sqrt(1+z^2);
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MPFR::MpfrClass
    irez = Inf( Re(z) ),
    srez = Sup( Re(z) ),
    iimz = Inf( Im(z) ),
    simz = Sup( Im(z) );
    bool error(false), err1(false);
    MpfciClass res(0);

    if (iimz>=1)
      error = (simz>1 && isNeg(irez) && srez>=0);
    else
      if (simz<=-1)
	error = (iimz<-1 && isPos(srez) && irez<=0);
    if (!isPos(irez) && !isNeg(srez))
      err1 = (simz>1 && iimz<-1);

    if (error || err1)
    {
      std::cerr << "MpfciClass sqrt1px2(const MpfciClass& z); z not in the principal branch." << std::endl;
      exit(1);
    }

    res = MpfciClass( sqrt1px2_Re(Re(z), Im(z)),  sqrt1px2_Im(Re(z), Im(z)) );

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  }

  MpfciClass sqrt1mx2(const MpfciClass& z)
  // Calculating an optimal inclusion of sqrt(1-z^2);
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfciClass res(Im(z), -Re(z));
    res = sqrt1px2(res);

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  }

  MpfciClass sqrtmx2m1(const MpfciClass& z)
  // Calculating an optimal inclusion of sqrt(-z^2 -1);
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfciClass res(Im(z), -Re(z));
    res = sqrtx2m1(res);

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;
  }

  MpfiClass sqrtx2m1_Re(const MpfiClass& x, const MpfiClass& y)
  {
    MpfiClass res, xa(abs(x)) ,ya(abs(y));
    // The comlex interval z = xa + i*ya lies in the first quadrant!
    res = MpfiClass( Re_sqrtx2m1(Inf(xa), Inf(ya), RoundDown),
		     Re_sqrtx2m1(Sup(xa), Sup(ya), RoundUp  ) );
    return res;
  }

  MpfiClass sqrtx2m1_Im(const MpfiClass& x, const MpfiClass& y)
  {
    MpfiClass res(0), xt(x), yt(y);
    if (isZero(y))
      xt = abs(x);
    else
    {
      if (isZero(x))
	yt = abs(y);
      else
      if ( isNeg(Inf(x)) )
      {
	xt = -x;  yt = -y;
      }
    }
    // The complex Interval xt + i*yt lies only in the right half-plane
    MPFR::MpfrClass
      x1(Inf(xt)),
      x2(Sup(xt)),
      y1(Inf(yt)),
      y2(Sup(yt));

    if (isNeg(y1))
    {
      if (isPos(y2))
	res = MpfiClass( Im_sqrtx2m1(Inf(xt), Inf(yt), RoundDown),
		         Im_sqrtx2m1(Inf(xt), Sup(yt), RoundUp  ) );
      else
	res = MpfiClass( Im_sqrtx2m1(Inf(xt), Inf(yt), RoundDown),
		         Im_sqrtx2m1(Sup(xt), Sup(yt), RoundUp  ) );
    }
    else  // y1 >= 0:
      res = MpfiClass( Im_sqrtx2m1(Sup(xt), Inf(yt), RoundDown),
		       Im_sqrtx2m1(Inf(xt), Sup(yt), RoundUp  ) );

    return res;
  }
/*
  MpfciClass sqrtx2m1(const MpfciClass& z)
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfciClass zt(z);
    if (Inf(Re(z))<0)
      zt = MpfciClass(abs(Re(zt)), Im(zt));

    MPFR::MpfrClass
      x1 = Inf( Re(zt) ),
      x2 = Sup( Re(zt) ),
      y1 = Inf( Im(zt) ),
      y2 = Sup( Im(zt) );

    bool error(false), bl = (x1==x2 && isZero(x1));
    MpfciClass res(0);

    if (isNeg(y1) && isPos(y2))
    {
      if (bl)
	error = false;
      else
        error = (x1<1);
    }
    if (error) goto ENDE;

    if (isZero(y1) && isPos(y2))
    {
      if (bl)
	error = false;
      else
      {
	MPFR::MpfrClass srz = Sup(Re(z));
        error = ( srz>-1 && !(isPos(srz)) ) || (0<Re(z));
      }
    }
    if (error) goto ENDE;

    if (isNeg(y1) && isZero(y2))
    {
      if (bl)
	error = false;
      else
      {
	MPFR::MpfrClass irz = Inf(Re(z));
        error = ( irz<1 && !(isNeg(irz)) ) || (0<Re(z));
      }
    }
    if (error) goto ENDE;

    res = MpfciClass( sqrtx2m1_Re(Re(z), Im(z)),  sqrtx2m1_Im(Re(z), Im(z)) );

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;

ENDE: std::cerr << "MpfciClass sqrtx2m1(const MpfciClass& z); z not in the principal branch." << std::endl;
      exit(1);
  }
*/

  MpfciClass sqrtx2m1(const MpfciClass& z)
  {
    PrecisionType prec = z.GetPrecision(),
              prec_old = MPFR::MpfrClass::GetCurrPrecision();
    if (prec<prec_old) prec = prec_old;
    MPFI::MpfiClass::SetCurrPrecision(prec);

    MpfciClass zt(z);
    if (Inf(Re(z))<0)
      zt = -z;

    MPFR::MpfrClass
      x1 = Inf( Re(zt) ),
      x2 = Sup( Re(zt) ),
      y1 = Inf( Im(zt) ),
      y2 = Sup( Im(zt) );

    bool error(false), bl = (x1==x2 && isZero(x1));
    MpfciClass res(0);

    if ( y1==y2 && isZero(y1))
      error = false;
    else error = (0<Re(zt));
    if (error) goto ENDE;

    if (isNeg(y1))  // 1,2,3
    {
      if (bl)
	error = false;
      else
	error = ( (x2<1 && !(isNeg(y2))) || (x1<1 && isZero(y2)) );
    }
    if (error) goto ENDE;

    error = ( isZero(x1) && isPos(x2) && isNeg(y2) );
    if (error) goto ENDE;

    res = MpfciClass( sqrtx2m1_Re(Re(z), Im(z)),  sqrtx2m1_Im(Re(z), Im(z)) );

    res.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    return res;

ENDE: std::cerr << "MpfciClass sqrtx2m1(const MpfciClass& z); z not in the principal branch." << std::endl;
      exit(1);
  }

}
