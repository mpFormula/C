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
/*  Datei:  mpficlass.cpp                    */
/*  Zweck:  C++-Wrapper-Klasse fuer          */
/*          die MPFI-Bibliothek              */
/*  Based on    mpfr-3.0.0, mpfi-1.4         */
/*********************************************/


#include "mpficlass.hpp"
#include <cmath>


namespace MPFI{

int MpfiClass::base = 10;

/*------------------------------------------------------*/
/*----------begin constructor and destructors-----------*/
/*------------------------------------------------------*/


    // Initialisieren mit NaN und Current-Precision
    MpfiClass::MpfiClass ()
    {
      mpfi_init2(mpfi_rep, MPFR::MpfrClass::GetCurrPrecision());
    }

    // Initialisieren mit Wert von mpfi und Precision prec.
    MpfiClass::MpfiClass (const mpfi_t& mpfi, PrecisionType prec)
    {
      mpfi_init2(mpfi_rep, prec);
      mpfi_set(mpfi_rep, mpfi);
    }

    // Initialisieren mit Wert von v und Precision prec. Wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet.
//    MpfiClass::MpfiClass (const cxsc::interval& v, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_rep, prec);
//      mpfi_interv_d(mpfi_rep, _double(Inf(v)), _double(Sup(v)));
//    }

    // Initialisieren mit Wert von r und Precision prec; Wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet.
//    MpfiClass::MpfiClass (const cxsc::real& r, PrecisionType prec)
//    {
//      mpfi_init2(mpfi_rep, prec);
//      mpfi_set_d(mpfi_rep, _double(r));
//    }

    // Initialisieren mit Wert von i und Precision prec. Wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet
    MpfiClass::MpfiClass (int i, PrecisionType prec)
    {
      mpfi_init2(mpfi_rep, prec);
      mpfi_set_si(mpfi_rep, (long int)i);
    }

    // Initialisieren mit Wert von d und Precision prec, wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass (const double& d, PrecisionType prec)
    {
      mpfi_init2(mpfi_rep, prec);
      mpfi_set_d(mpfi_rep, d);
    }

    // Der Wert von s wird in ein MpfiClass-Objekt der Praezision prec eingeschlossen.
    // Wenn keine Precision uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass(const std::string& s, PrecisionType prec)
    {
      mpfi_init2(mpfi_rep, prec);   // Blomquist 07.10.2010
      if ( mpfi_set_str(mpfi_rep, const_cast<char *>(s.c_str()), MpfiClass::GetBase()) )
      {
        std::cerr << "Error by string input. Wrong base?" << std::endl;
        exit(1);
      }
      this->swap_endpoints();
    }

    // Initialisieren mit Wert von mpfr und Precision prec. Wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass (const mpfr_t& mpfr, PrecisionType prec)
    {
      mpfi_init2(mpfi_rep, prec);
      mpfi_set_fr(mpfi_rep, mpfr);
    }

    // Initialisieren mit Wert von v und Precision prec. Wenn keine Precision
    // uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass (const MpfiClass& v, PrecisionType prec)
    {
        mpfi_init2(mpfi_rep, prec);
        mpfi_set(mpfi_rep, v.mpfi_rep);
    }

    // Mit v wird ein MpfiClass Intervall y mit der Präzision prec erzeugt,
    // welches das Intervall [v,v] optimal einschliesst. Bei zu kleinem prec
    // muss y kein Punktintervall sein!
    // Wenn keine Praezision uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass (const MPFR::MpfrClass& v, PrecisionType prec)
    {
        mpfi_init2(mpfi_rep, prec);
        mpfi_set_fr(mpfi_rep, getvalue(v));
    }

    // Mit v und w wird ein MpfiClass Intervall mit der Präzision prec erzeugt,
    // welches das Intervall [v,w] optimal einschliesst.
    // Wenn keine Praezision uebergeben wird, wird die Current-Precision verwendet.
    MpfiClass::MpfiClass (const MPFR::MpfrClass& v, const MPFR::MpfrClass& w,
                                                    PrecisionType prec) // Blomquist 12.05.2010
    {
        mpfi_init2(mpfi_rep, prec);
        mpfi_interv_fr( mpfi_rep, getvalue(v), getvalue(w) );
    }

    // Freigabe des Speichers fuer mpfi_rep
    MpfiClass::~MpfiClass ()
    {
      mpfi_clear(mpfi_rep);
    }


/*------------------------------------------------------*/
/*----------end constructor and destructors-------------*/
/*------------------------------------------------------*/


    mpfi_t& MpfiClass::GetValue()
    // Memberfunktion: Liefert Referenz auf mpfi_rep des aktuellen Objekts
    {
        return this->mpfi_rep;
    }

    const mpfi_t& getvalue(const MpfiClass& v)
    {
      return v.mpfi_rep;
    }

    // Setzten von mpfi_rep auf v
    void MpfiClass::SetValue(const mpfi_t& v)
    {
        mpfi_set_prec(mpfi_rep, mpfi_get_prec(v));
        mpfi_set(mpfi_rep, v);
    }


    // Wert von A und B Tauschen
    void swap(MpfiClass& A, MpfiClass& B)
    {
        mpfi_swap(A.mpfi_rep, B.mpfi_rep);
    }

    // Wert von A und B Tauschen
    void swap(MpfiClass& A, mpfi_t& B)
    {
        mpfi_swap(A.mpfi_rep, B);
    }

    /*------------------------------------------------------*/
    /*----------begin Assignment operators -----------------*/
    /*------------------------------------------------------*/

    // Der linke Intervall-Operand erhaelt die Current-Precision und schliesst
    // den Wert des rechten Operanden optimal ein.
    MpfiClass& MpfiClass::operator = (const MpfiClass& v)
    {
      if (this == &v)
      {
        (*this).RoundPrecision(GetCurrPrecision());
        return *this;
      }

      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set(mpfi_rep, v.mpfi_rep);
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const MPFR::MpfrClass& v)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set_fr(mpfi_rep, getvalue(v));
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const mpfi_t& v)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set(mpfi_rep, v);
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const mpfr_t& v)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set_fr(mpfi_rep, v);
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const int& v)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set_si(mpfi_rep, (long int)v);
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const double& v)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      mpfi_set_d(mpfi_rep, v);
      return *this;
    }

    MpfiClass& MpfiClass::operator = (const std::string& s)
    {
      mpfi_set_prec(mpfi_rep, GetCurrPrecision());
      if (mpfi_set_str(mpfi_rep, const_cast<char *>(s.c_str()), MpfiClass::GetBase()) )
      {
         std::cerr << "Error by data input. Wrong base?" << std::endl;
         exit(1);
      }
      // this->RoundPrecision(prec);
      this->swap_endpoints();
      return *this;
    }

  // Zuweisen einer interval-Variablen an das aktuelle Objekt
//  MpfiClass& MpfiClass::operator = (const cxsc::interval& v)
//  {
//    mpfi_set_prec(mpfi_rep, GetCurrPrecision());
//    mpfi_interv_d (mpfi_rep, _double(Inf(v)), _double(Sup(v)));
//    return *this;
//  }

  // Zuweisen einer real-Variablen an das aktuelle Objekt
//  MpfiClass& MpfiClass::operator = (const cxsc::real& r)
//  {
//    mpfi_set_prec(mpfi_rep, GetCurrPrecision());
//    mpfi_set_d (mpfi_rep, _double(r));
//    return *this;
//  }

 /*------------------------------------------------------*/
 /*----------end Assignment operators -------------------*/
 /*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------begin Precision and Rounding Modes----- ----*/
/*------------------------------------------------------*/

    // Setzten der Current-Precision NUR in MpfrClass
    void MpfiClass::SetCurrPrecision (PrecisionType newprec)
    {
        MPFR::MpfrClass::SetCurrPrecision(newprec);
    }

    // Setzten der Precision fuer das aktuelle Objekt, Wert wird geloescht
    void MpfiClass::SetPrecision (PrecisionType newprec)
    {
        mpfi_set_prec(mpfi_rep, newprec);
    }

    // Setzten der Precision fuer das aktuelle Objekt;
    // Der Wert bleibt erhalten, wird aber i.a. gerundet (nach aussen!)
    void MpfiClass::RoundPrecision(PrecisionType newprec)  // Urspruengliche Version
    {
        mpfi_round_prec(mpfi_rep, newprec);
    }

    // Auslesen der Current-Precision:
    const PrecisionType MpfiClass::GetCurrPrecision ()
    {
        return MPFR::MpfrClass::GetCurrPrecision();
    }

    // Auslesen der Precision des Aktuellen Objekts
    PrecisionType MpfiClass::GetPrecision () const
    {
        return mpfi_get_prec(mpfi_rep);
    }

    // Setzten der Basis (Wert zwischen 2-36)
    void MpfiClass::SetBase (int b)
    {
        base = b;
    }

    // Auslesen der aktuellen Basis
    const int MpfiClass::GetBase ()
    {
        return base;
    }

/*------------------------------------------------------*/
/*----------end Precision and Rounding Modes------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start comparison Functions -----------------*/
/*------------------------------------------------------*/

    // Ueberprueft, ob nur positive Zahlen im Intervall enthalten sind,
    // der linke Endpunkt kann 0 sein.
    bool isPos(const MpfiClass& v)
    {
        return mpfi_is_pos(v.mpfi_rep);
    }

    // Ueberprueft ob nur positive Zahlen im Intervall enthalten sind,
    // der linke Endpunkt muss groesser 0 sein.
    bool isStrictlyPos(const MpfiClass& v)
    {
        return mpfi_is_strictly_pos(v.mpfi_rep);
    }

    // Ueberprueft, ob nur "nicht-negative"-Zahlen im Interval enthalten sind.
    bool isNonNeg(const MpfiClass& v)
    {
        return mpfi_is_nonneg(v.mpfi_rep);
    }

    // Ueberprueft, ob nur negative Zahlen im Interval enthalten sind,
    // der Rechte Endpunkt kann 0 sein
    bool isNeg(const MpfiClass& v)
    {
        return mpfi_is_neg(v.mpfi_rep);
    }

    // Ueberprueft, ob nur negative Zahlen im Interval enthalten sind,
    // der Rechte Endpunkt muss kleiner 0 sein.
    bool isStrictlyNeg(const MpfiClass& v)
    {
        return mpfi_is_strictly_neg(v.mpfi_rep);
    }

    // Ueberprueft, ob nur "nicht-positive"-Zahlen im Interval enthalten sind
    bool isNonPos(const MpfiClass& v)
    {
        return mpfi_is_nonpos(v.mpfi_rep);
    }

    // Ueberprueft, ob v = 0 ist.
    bool isZero(const MpfiClass& v)
    {
        return mpfi_is_zero(v.mpfi_rep);
    }

    // Ueberprueft, ob die 0 im Interval enthalten ist.
    bool hasZero(const MpfiClass& v)
    {
        return mpfi_has_zero(v.mpfi_rep);
    }

    // Ueberprueft, ob v = NaN ist
    bool isNan(const MpfiClass& v)
    {
        return mpfi_nan_p(v.mpfi_rep);
    }

    // Ueberprueft, ob v = Inf ist.
    bool isInf(const MpfiClass& v)
    {
        return mpfi_inf_p(v.mpfi_rep);
    }

    // Ueberprueft, ob das Intervall weder unzulaessig noch unendlich ist
    bool isBounded(const MpfiClass& v)
    {
        return mpfi_bounded_p(v.mpfi_rep);
    }

    // Ueberprueft, ob v ein Punktintervall ist.
    bool isPoint(const MpfiClass& v)
    {
      bool bl(false);
      if ( isBounded(v) )
      {
        mpfr_t left_v, right_v;
        mpfr_init2(left_v ,v.GetPrecision());
        mpfr_init2(right_v,v.GetPrecision());

        mpfi_get_left  (left_v,  v.mpfi_rep);
        mpfi_get_right (right_v, v.mpfi_rep);

        bl = (mpfr_equal_p(left_v,right_v) != 0);  // returns true if Inf(v) == Sup(v);

        mpfr_clear (left_v);
        mpfr_clear (right_v);
      }
      return bl;
    }

  void set_Mpfi (MpfiClass& op, const MpfiClass& op1, PrecisionType prec)
  // op erhält die Praezision prec und den Wert von op1, mit op1 <= op;
  // Ohne prec erhält op die Current-Precision, ebenfalls mit op1 <= op;
  {
    op.SetPrecision(prec);  // Setzt die Praezision von op auf prec
    mpfi_set(op.mpfi_rep, op1.mpfi_rep); // Es gilt:  op1 <= op;
  }

  void set_nan (MpfiClass& a)
  // Das gesetzte Intervall hat die Praezision von a
  {
    MPFR::MpfrClass x(0, RoundNearest, a.GetPrecision());
    set_nan(x);
    MpfiClass tmp(x, x, a.GetPrecision() );
    set_Mpfi(a, tmp, a.GetPrecision());
  }

  void set_inf (MpfiClass& a)
  // Das gesetzte Intervall hat die Praezision von a
  {
    MPFR::MpfrClass x(0, RoundNearest, a.GetPrecision());
    MPFR::MpfrClass y(0, RoundNearest, a.GetPrecision());
    set_inf(x,-1);
    set_inf(y,1);
    MpfiClass tmp(x, y, a.GetPrecision() );
    set_Mpfi(a, tmp, a.GetPrecision());
  }

  void set_zero (MpfiClass& a)
  // Das gesetzte Intervall hat die Praezision von a
  {
    MPFR::MpfrClass x(0, RoundNearest, a.GetPrecision());
    set_zero(x,0);
    MpfiClass tmp(x, x, a.GetPrecision() );
    set_Mpfi(a, tmp, a.GetPrecision());
  }


/*------------------------------------------------------*/
/*----------end comparison Functions -------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start Constants (Pi, Euler, log2)----------*/
/*----------setzt mpfi_rep auf entsprechenden-----------*/
/*----------Wert mit mpfi_rep-Precision-----------------*/
/*------------------------------------------------------*/

// Konstanten:  Pi, Euler, Log2 , Catalan

MpfiClass MpfiClass::Pi(PrecisionType prec)    // Blomquist 12.05.2010
{
  MpfiClass res(0.0, prec);
  mpfi_const_pi(res.mpfi_rep);

  return res;
}

MpfiClass MpfiClass::Euler(PrecisionType prec)  // Blomquist 12.05.2010
{
  MpfiClass res(0.0, prec);
  mpfi_const_euler(res.mpfi_rep);

  return res;
}

MpfiClass MpfiClass::Ln2(PrecisionType prec)   // Blomquist 12.05.2010
{
  MpfiClass res(0.0, prec);
  mpfi_const_log2(res.mpfi_rep);

  return res;
}

MpfiClass MpfiClass::Catalan(PrecisionType prec)   // Blomquist 12.05.2010
{
  MpfiClass res(0.0, prec);
  mpfi_const_catalan (res.mpfi_rep);

  return res;
}


/*------------------------------------------------------*/
/*-------end Constatnts (Pi, Euler, log2, Catalan)------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start + Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    // Addiert zwei MpfiClass-Objekte
    MpfiClass operator + (const MpfiClass& a, const MpfiClass& b)
    {
      MpfiClass v(0);  // v mit Current-Precision
      mpfi_add(v.mpfi_rep, a.mpfi_rep, b.mpfi_rep);
      return v;
    }

    MpfiClass operator + (const MpfiClass& a, const double& b)
    {
       MpfiClass r(0);
       mpfi_add_d(r.mpfi_rep, a.mpfi_rep, b);
       return r;
    }

//    MpfiClass operator + (const MpfiClass& a, const cxsc::real& b)
//    {
//       MpfiClass r(0);
//       mpfi_add_d(r.mpfi_rep, a.mpfi_rep, _double(b));
//       return r;
//    }

//    MpfiClass operator + (const MpfiClass& a, const cxsc::interval& b)
//    {
//      MpfiClass Ib(b, 53);
//      return a + Ib;
//    }

    MpfiClass operator + (const MpfiClass& a, const int b)
    {
       MpfiClass r(0);
       mpfi_add_si(r.mpfi_rep, a.mpfi_rep, b);
       return r;
    }

    MpfiClass operator + (const MpfiClass& a, const mpfr_t& b)
    {
        MpfiClass r(0);
        mpfi_add_fr(r.mpfi_rep, a.mpfi_rep, b);

        return r;
    }

    MpfiClass operator + (const MpfiClass& a, const MPFR::MpfrClass& b)
    {
        MpfiClass r(0);
        mpfi_add_fr(r.mpfi_rep, a.mpfi_rep, getvalue(b));
        return r;
    }


    MpfiClass operator + (const MpfiClass& a, const mpfi_t& b)
    {
        MpfiClass r(0);
        mpfi_add(r.mpfi_rep, a.mpfi_rep, b);
        return r;
    }

    MpfiClass operator + (const double& a, const MpfiClass& b)
    {
       MpfiClass r(0);
       mpfi_add_d(r.mpfi_rep, b.mpfi_rep, a);
       return r;
    }

//    MpfiClass operator + (const cxsc::real& a, const MpfiClass& b)
//    {
//       MpfiClass r(0);
//       mpfi_add_d(r.mpfi_rep, b.mpfi_rep, _double(a));
//       return r;
//    }

//    MpfiClass operator + (const cxsc::interval& a, const MpfiClass& b)
//    {
//      MpfiClass Ia(a, 53);
//      return Ia + b;
//    }

    MpfiClass operator + (const int a, const MpfiClass& b)
    {
       MpfiClass r(0);
       mpfi_add_si(r.mpfi_rep, b.mpfi_rep, a);
       return r;
    }

    MpfiClass operator + (const mpfr_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_add_fr(r.mpfi_rep, b.mpfi_rep, a);

        return r;
    }

    MpfiClass operator + (const MPFR::MpfrClass& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_add_fr(r.mpfi_rep, b.mpfi_rep, getvalue(a));
        return r;
    }

    MpfiClass operator + (const mpfi_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_add(r.mpfi_rep, b.mpfi_rep, a);

        return r;
    }


    //  Berechne (a+b) und uebergebe diese Summe an a.
    //  Die Praezision von a wird die Current-Precision und zwar
    //  unabhängig von der ursprgl. Praezision von a;
    MpfiClass& operator += (MpfiClass& a, const MpfiClass& b)
    {
      a = a + b;
      return a;
    }

    MpfiClass& operator += (MpfiClass& a, const double& b)
    {
      a = a + b;
      return a;
    }

//    MpfiClass& operator += (MpfiClass& a, const cxsc::real& b)
//    {
//      a = a + _double(b);
//      return a;
//    }

//    MpfiClass& operator += (MpfiClass& a, const cxsc::interval& b)
//    {
//      a = a + b;
//      return a;
//    }

    MpfiClass& operator += (MpfiClass& a, const int b)
    {
      a = a + b;
      return a;
    }

    MpfiClass& operator += (MpfiClass& a, const mpfr_t& b)
    {
      a = a + b;
      return a;
    }

    MpfiClass& operator += (MpfiClass& a, MPFR::MpfrClass& b)
    {
      a = a + b;
      return a;
    }

    MpfiClass& operator += (MpfiClass& a, const mpfi_t& b)
    {
      a = a + b;
      return a;
    }


/*------------------------------------------------------*/
/*----------end + Arithmetic Functions------------------*/
/*------------------------------------------------------*/



/*------------------------------------------------------*/
/*----------start - Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    // Subtraktion zweier MpfiClass-Objekte;
    // Die Praezision der Differenz ist die Current-Precision
    MpfiClass operator - (const MpfiClass& a, const MpfiClass& b)
    {
      MpfiClass v(0);
      mpfi_sub(v.mpfi_rep, a.mpfi_rep, b.mpfi_rep);
      return v;
    }

    MpfiClass operator - (const MpfiClass& a, const double& b)
    {
       MpfiClass r(0);
       mpfi_sub_d(r.mpfi_rep, a.mpfi_rep, b);
       return r;
    }

//    MpfiClass operator - (const MpfiClass& a, const cxsc::real& b)
//    {
//       MpfiClass r(0);
//       mpfi_sub_d(r.mpfi_rep, a.mpfi_rep, _double(b));
//       return r;
//    }

//    MpfiClass operator - (const MpfiClass& a, const cxsc::interval& b)
//    {
//      MpfiClass Ib(b, 53);
//      return a - Ib;
//    }

    MpfiClass operator - (const MpfiClass& a, const int b)
    {
       MpfiClass r(0);
       mpfi_sub_si(r.mpfi_rep, a.mpfi_rep, (long int)b);
       return r;
    }

    MpfiClass operator - (const MpfiClass& a, const mpfr_t& b)
    {
        MpfiClass r(0);
        mpfi_sub_fr(r.mpfi_rep, a.mpfi_rep, b);

        return r;
    }

    MpfiClass operator - (const MpfiClass& a, const MPFR::MpfrClass& b)
    {
        MpfiClass r(0);
        mpfi_sub_fr(r.mpfi_rep, a.mpfi_rep, getvalue(b));
        return r;
    }

    MpfiClass operator - (const MpfiClass& a, const mpfi_t& b)
    {
        MpfiClass r(0);
        mpfi_sub(r.mpfi_rep, a.mpfi_rep, b);

        return r;
    }

    MpfiClass operator - (const double& a, const MpfiClass& b)
    {
       MpfiClass r(0);
       mpfi_d_sub(r.mpfi_rep, a, b.mpfi_rep);
       return r;
    }

//    MpfiClass operator - (const cxsc::real& a, const MpfiClass& b)
//    {
//       MpfiClass r(0);
//       mpfi_d_sub(r.mpfi_rep, _double(a), b.mpfi_rep);
//       return r;
//    }

//    MpfiClass operator - (const cxsc::interval& a, const MpfiClass& b)
//    {
//      MpfiClass Ia(a, 53);
//      return Ia - b;
//    }

    MpfiClass operator - (const int a, const MpfiClass& b)
    {
       MpfiClass r(0);
       mpfi_si_sub(r.mpfi_rep, (long int)a, b.mpfi_rep);
       return r;
    }

    MpfiClass operator - (const mpfr_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_fr_sub(r.mpfi_rep, a, b.mpfi_rep);

        return r;
    }

    MpfiClass operator - (const MPFR::MpfrClass& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_fr_sub(r.mpfi_rep, getvalue(a), b.mpfi_rep);
        return r;
    }

    MpfiClass operator - (const mpfi_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_sub(r.mpfi_rep, a, b.mpfi_rep);

        return r;
    }

    MpfiClass operator - (const MpfiClass& x)
    {
       MpfiClass val(0.0, x.GetPrecision());
       mpfi_neg(val.mpfi_rep, x.mpfi_rep);
       return val;
    }

    MpfiClass operator + (const MpfiClass& x)
    {
       return x;
    }

    // a = a-b; Die Ergebnis-Präzision von a ist die Current-Precision
    MpfiClass& operator -= (MpfiClass& a, const MpfiClass& b)
    {
      a = a - b;
      return a;
    }

    MpfiClass& operator -= (MpfiClass& a, const double& b)
    {
      a = a - b;
      return a;
    }

//    MpfiClass& operator -= (MpfiClass& a, const cxsc::real& b)
//    {
//      a = a - b;
//      return a;
//    }

//    MpfiClass& operator -= (MpfiClass& a, const cxsc::interval& b)
//    {
//      a = a - b;
//      return a;
//    }

    MpfiClass& operator -= (MpfiClass& a, const int b)
    {
      a = a - b;
      return a;
    }

    MpfiClass& operator -= (MpfiClass& a, const mpfr_t& b)
    {
      a = a - b;
      return a;
    }

    MpfiClass& operator -= (MpfiClass& a, const mpfi_t& b)
    {
      a = a - b;
      return a;
    }

    MpfiClass& operator -= (MpfiClass& a, const MPFR::MpfrClass& b)
    {
      a = a - b;
      return a;
    }
/*------------------------------------------------------*/
/*----------end - Arithmetic Functions------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start * Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    // Der Rückgabewert erhaelt die Current-Precision und schliesst
    // in diesem Format das exakte Intervallprodukt a*b optimal ein.
    MpfiClass operator * (const MpfiClass& a, const MpfiClass& b)
    {
      MpfiClass v(0); // v mit Current-Precision initialisiert.
      mpfi_mul(v.mpfi_rep, a.mpfi_rep, b.mpfi_rep);
      return v;
    }

    MpfiClass operator * (const MpfiClass& a, const double& b)
    {
       MpfiClass r(0);
       mpfi_mul_d(r.mpfi_rep, a.mpfi_rep, b);
       return r;
    }

//    MpfiClass operator * (const MpfiClass& a, const cxsc::real& b)
//    {
//       MpfiClass r(0);
//       mpfi_mul_d(r.mpfi_rep, a.mpfi_rep, _double(b));
//       return r;
//    }

//    MpfiClass operator * (const MpfiClass& a, const cxsc::interval& b)
//    {
//      MpfiClass Ib(b, 53);
//      return a * Ib;
//    }

    MpfiClass operator * (const MpfiClass& a, const int b)
    {
       MpfiClass r(0);
       mpfi_mul_si(r.mpfi_rep, a.mpfi_rep, b);
       return r;
    }

    MpfiClass operator * (const MpfiClass& a, const mpfr_t& b)
    {
        MpfiClass r(0);
        mpfi_mul_fr(r.mpfi_rep, a.mpfi_rep, b);
        return r;
    }

    MpfiClass operator * (const MpfiClass& a, const MPFR::MpfrClass& b)
    {
        MpfiClass r(0);
        mpfi_mul_fr(r.mpfi_rep, a.mpfi_rep, getvalue(b));
        return r;
    }

    MpfiClass operator * (const MpfiClass& a, const mpfi_t& b)
    {
        MpfiClass r(0);
        mpfi_mul(r.mpfi_rep, a.mpfi_rep, b);
        return r;
    }

    MpfiClass operator * (const double& a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_mul_d(r.mpfi_rep, b.mpfi_rep, a);
      return r;
    }

//    MpfiClass operator * (const cxsc::real& a, const MpfiClass& b)
//    {
//      MpfiClass r(0);
//      mpfi_mul_d(r.mpfi_rep, b.mpfi_rep, _double(a));
//      return r;
//    }

//    MpfiClass operator * (const cxsc::interval& a, const MpfiClass& b)
//    {
//      MpfiClass Ia(a, 53);
//      return Ia * b;
//    }

    MpfiClass operator * (const int a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_mul_si(r.mpfi_rep, b.mpfi_rep, a);
      return r;
    }

    MpfiClass operator * (const mpfr_t& a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_mul_fr(r.mpfi_rep, b.mpfi_rep, a);
      return r;
    }

    MpfiClass operator * (const MPFR::MpfrClass& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_mul_fr(r.mpfi_rep, b.mpfi_rep, getvalue(a));
        return r;
    }

    MpfiClass operator * (const mpfi_t& a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_mul(r.mpfi_rep, b.mpfi_rep, a);
      return r;
    }


    //  Berechne (a*b) und uebergebe dieses Produkt an a.
    //  Die Praezision von a wird die Current-Precision und zwar
    //  unabhängig von der ursprgl. Praezision von a;
    MpfiClass& operator *= (MpfiClass& a, const MpfiClass& b)
    {
      a = a * b;
      return a;
    }

    MpfiClass& operator *= (MpfiClass& a, const double& b)
    {
      a = a * b;
      return a;
    }

//    MpfiClass& operator *= (MpfiClass& a, const cxsc::real& b)
//    {
//      a = a * b;
//      return a;
//    }

//    MpfiClass& operator *= (MpfiClass& a, const cxsc::interval& b)
//    {
//      a = a * b;
//      return a;
//    }

    MpfiClass& operator *= (MpfiClass& a, const int b)
    {
      a = a * b;
      return a;
    }

    MpfiClass& operator *= (MpfiClass& a, const mpfr_t& b)
    {
      a = a * b;
      return a;
    }

    MpfiClass& operator *= (MpfiClass& a, MPFR::MpfrClass& b)
    {
      a = a * b;
      return a;
    }

    MpfiClass& operator *= (MpfiClass& a, const mpfi_t& b)
    {
      a = a * b;
      return a;
    }

/*------------------------------------------------------*/
/*----------end * Arithmetic Functions------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start / Arithmetic Functions----------------*/
/*------------------------------------------------------*/

    // Dividiert zwei MpfiClass-Objekte
    MpfiClass operator / (const MpfiClass& a, const MpfiClass& b)
    {
      MpfiClass v(0);
      mpfi_div(v.mpfi_rep, a.mpfi_rep, b.mpfi_rep);
      return v;
    }

    MpfiClass operator / (const MpfiClass& a, const double& b)
    {
      MpfiClass r(0);
      mpfi_div_d(r.mpfi_rep, a.mpfi_rep, b);
      return r;
    }

//    MpfiClass operator / (const MpfiClass& a, const cxsc::real& b)
//    {
//      MpfiClass r(0);
//      mpfi_div_d(r.mpfi_rep, a.mpfi_rep, _double(b));
//      return r;
//    }

//    MpfiClass operator / (const MpfiClass& a, const cxsc::interval& b)
//    {
//      MpfiClass Ib(b,53);
//      return a / Ib;
//    }

    MpfiClass operator / (const MpfiClass& a, const int b)
    {
      MpfiClass r(0);
      mpfi_div_si(r.mpfi_rep, a.mpfi_rep, b);
      return r;
    }

    MpfiClass operator / (const MpfiClass& a, const mpfr_t& b)
    {
        MpfiClass r(0);
        mpfi_div_fr(r.mpfi_rep, a.mpfi_rep, b);
        return r;
    }

    MpfiClass operator / (const MpfiClass& a, const MPFR::MpfrClass& b)
    {
        MpfiClass r(0);
        mpfi_div_fr(r.mpfi_rep, a.mpfi_rep, getvalue(b));
        return r;
    }

    MpfiClass operator / (const MpfiClass& a, const mpfi_t& b)
    {
        MpfiClass r(0);
        mpfi_div(r.mpfi_rep, a.mpfi_rep, b);
        return r;
    }

    MpfiClass operator / (const double& a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_d_div(r.mpfi_rep, a, b.mpfi_rep);
      return r;
    }

//    MpfiClass operator / (const cxsc::real& a, const MpfiClass& b)
//    {
//      MpfiClass r(0);
//      mpfi_d_div(r.mpfi_rep, _double(a), b.mpfi_rep);
//      return r;
//    }

//    MpfiClass operator / (const cxsc::interval& a, const MpfiClass& b)
//    {
//      MpfiClass Ia(a, 53);
//      return Ia / b;
//    }

    MpfiClass operator / (const int a, const MpfiClass& b)
    {
      MpfiClass r(0);
      mpfi_si_div(r.mpfi_rep, a, b.mpfi_rep);
      return r;
    }

    MpfiClass operator / (const mpfr_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_fr_div(r.mpfi_rep, a, b.mpfi_rep);

        return r;
    }

    MpfiClass operator / (const MPFR::MpfrClass& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_fr_div(r.mpfi_rep, getvalue(a), b.mpfi_rep);
        return r;
    }

    MpfiClass operator / (const mpfi_t& a, const MpfiClass& b)
    {
        MpfiClass r(0);
        mpfi_div(r.mpfi_rep, a, b.mpfi_rep);

        return r;
    }

    // a /= b; The precision of the result a is the Current-Precision
    MpfiClass& operator /= (MpfiClass& a, const MpfiClass& b)
    {
      a = a / b;
      return a;
    }

    MpfiClass& operator /= (MpfiClass& a, const double& b)
    {
      a = a / b;
      return a;
    }

//    MpfiClass& operator /= (MpfiClass& a, const cxsc::real& b)
//    {
//      a = a / b;
//      return a;
//    }

//    MpfiClass& operator /= (MpfiClass& a, const cxsc::interval& b)
//    {
//      a = a / b;
//      return a;
//    }

    MpfiClass& operator /= (MpfiClass& a, const int b)
    {
      a = a / b;
      return a;
    }

    MpfiClass& operator /= (MpfiClass& a, const mpfr_t& b)
    {
      a = a / b;
      return a;
    }

    MpfiClass& operator /= (MpfiClass& a, MPFR::MpfrClass& b)
    {
      a = a / b;
      return a;
    }

    MpfiClass& operator /= (MpfiClass& a, const mpfi_t& b)
    {
      a = a / b;
      return a;
    }


/*------------------------------------------------------*/
/*----------end / Arithmetic Functions------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start extended Arithmetic Functions---------*/
/*------------------------------------------------------*/

    // Erzeugt ein neues Objekt val mit allen Werten t^2, mit t aus v
    MpfiClass sqr(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_sqr(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit dem Wert von 1/v
    MpfiClass reci(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_inv(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit der Wurzel aus v
    MpfiClass sqrt(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_sqrt(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    MpfiClass sqrtp1m1(const MpfiClass& x)
    // Calculating an inclusion of sqrt(x+1)-1;                           Blomquist 25.06.2010
    // The precision of res is the actual precision of x.
    {
      PrecisionType prec     = x.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      MPFR::MpfrClass l, r;

      l = MPFR::sqrtp1m1(Inf(x),RoundDown);
      r = MPFR::sqrtp1m1(Sup(x),RoundUp);

      res.SetInterval(l,r);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass sqrtx2m1(const MpfiClass& x)
    // Calculating an inclusion of sqrt(x^2-1);                           Blomquist 25.06.2010
    // The precision of res is the actual precision of x.
    {
      PrecisionType prec     = x.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass absx(0);

      mpfi_abs(absx.mpfi_rep, x.mpfi_rep);  // absx = |x|
      absx.SetInterval(MPFR::sqrtx2m1(Inf(absx), RoundDown),MPFR::sqrtx2m1(Sup(absx), RoundUp));

      absx.RoundPrecision(prec_old);           // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return absx;
    }

    MpfiClass agm (const MpfiClass& x, const MpfiClass& y) // Blomquist 01.12.2010
    {
      PrecisionType precx(x.GetPrecision()), precy(y.GetPrecision());
      MpfiClass res(0);
      MPFR::MpfrClass l,r;
      l = agm( Inf(x, precx), Inf(y, precy), RoundDown);
      r = agm( Sup(x, precx), Sup(y, precy), RoundUp);
      res.SetInterval(l, r);
      return res;
    }

    MpfiClass ln_sqrtx2y2(const MpfiClass& x, const MpfiClass& y)
    {
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
        prec = x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass ax(0), ay(0);
      mpfi_abs (ax.mpfi_rep, x.mpfi_rep);  // ax = abs(x)
      mpfi_abs (ay.mpfi_rep, y.mpfi_rep);  // ay = abs(y)

      MPFR::MpfrClass l, r;

      l = MPFR::ln_sqrtx2y2(Inf(ax), Inf(ay), RoundDown);
      r = MPFR::ln_sqrtx2y2(Sup(ax), Sup(ay), RoundUp);

      ax.SetInterval(l,r);
      ax.RoundPrecision(prec_old);             // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return ax;
    }

    MPFR::MpfrClass x_div_M(const MpfiClass& x, const MpfiClass& y)
    // Calculating the maximum M;
    // Inf(x)>=0 and  Inf(y)>=0 are assumed but not checked here.
    {
      int k(0);
      MPFR::MpfrClass res, x1(Inf(x)), x2(Sup(x)), y1(Inf(y)), y2(Sup(y));
      if (isPoint(x) && isPoint(y))
	res = x_div_x2py2(Inf(x), Inf(y), RoundUp);
      else
      {
	if (x2 <= y1)        { k=1; goto Fertig; }
	if (y2 <= x1)	     { k=5; goto Fertig; }
	if (x1<y)            { k=2; goto Fertig; }
	if (x2<y)            { k=4; goto Fertig; }
	if (y1<=x && y2<=x)  { k=3; goto Fertig; }
Fertig:
	switch(k)
        {
	  case 1: res = x_div_x2py2(x2, y1, RoundUp);
	          break;
	  case 2:
	  case 5: res = x_div_x2py2(x1, y1, RoundUp);
	          break;
	  case 3:
	  case 4: res = x_div_x2py2(y1, y1, RoundUp);
	          break;
        }
      }

      return res;
    }

    MPFR::MpfrClass x_div_m(const MpfiClass& x, const MpfiClass& y)
    // Calculating the minimum m
    {
      int k(0);
      MPFR::MpfrClass res, x1(Inf(x)), x2(Sup(x)), y1(Inf(y)), y2(Sup(y)), t;
      if (isPoint(x) && isPoint(y))
	res = x_div_x2py2(Inf(x), Inf(y), RoundDown);
      else
      {
	if (x2 <= y1)        { k=1; goto Fertig; }
	if (y2 <= x1)	     { k=5; goto Fertig; }
	if (x1<y)            { k=2; goto Fertig; }
	if (x2<y)            { k=4; goto Fertig; }
	if (y1<=x && y2<=x)  { k=3; goto Fertig; }
Fertig:
	switch(k)
        {
	  case 1:
	  case 4: res = x_div_x2py2(x1, y2, RoundDown);
	          break;
	  case 2: res = x_div_x2py2(x1, y2, RoundDown);
	          t   = x_div_x2py2(x2, y2, RoundDown);
		  if (t<res) res = t;
	          break;
	  case 3: res = x_div_x2py2(x1, y2, RoundDown);
	          if (x2>y2)
		  {
		    t = x_div_x2py2(x2, y2, RoundDown);
		    if (t<res) res = t;
		  }
		  break;
	  case 5: res = x_div_x2py2(x2, y2, RoundDown);
	          break;
        }
      }

      return res;
    }

    MpfiClass x_div_x2py2(const MpfiClass& x, const MpfiClass& y)
    // Calculating an optimal inclusion of x/(x^2+y^2);
    // 0 <= x  and  0 <= y  leads to an error message!
    {
      int k;
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
        prec = x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      if (0<=x && 0<=y)
      {
        std::cerr << "Error in MpfiClass x_div_x2py2(const MpfiClass& x, const MpfiClass& y): 0 <= x and 0 <= y" << std::endl;
        exit(1);
      }
      MpfiClass Y(0), res;
      mpfi_abs (Y.mpfi_rep, y.mpfi_rep);  // Y = abs(y);

      if (Inf(x)>=0)
	k=1; // Inf(x)>=0
      else   // Inf(x)<0
      {
	if (isNeg(Sup(x)))
	  k = 2; // Sup(x)<0
	else k = 3; // Inf(x)<0, Sup(x)>=0;
      }

      MPFR::MpfrClass m, M(0);

      switch(k)
      {
	case 1: m = x_div_m(x,Y);
	        M = x_div_M(x,Y);
		break;
	case 2: res = -x; // res in the 1. quadrant
                m = x_div_m(res,Y);
		M = x_div_M(res,Y);
		swap(m,M);
		m = -m;  M = -M;
                break;
	case 3: res.SetInterval(M,-Inf(x)); // res = [0,-Inf(x)]
	        m = -x_div_M(res,Y);
		res.SetInterval(M,Sup(x));  // res = [0,Sup(x)]
		M = x_div_M(res,Y);
		break;
      }

      res.SetInterval(m,M);

      res.RoundPrecision(prec_old);             // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);    // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass ln_sqrtxp1_2y2(const MpfiClass& x, const MpfiClass& y)
    {
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
        prec = x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec);
      MpfiClass Y( abs(y) ), res(0);
      MPFR::MpfrClass x1(Inf(x)),x2(Sup(x)),
                      y1(Inf(Y)),y2(Sup(Y)), l, r;
      if (x1>=-1)
      {
	l = MPFR::ln_sqrtxp1_2y2(x1, y1, RoundDown);
	r = MPFR::ln_sqrtxp1_2y2(x2, y2, RoundUp  );
      }
      else
      {
	if (x2<=-1)
	{
	  l = MPFR::ln_sqrtxp1_2y2(x2, y1, RoundDown);
	  r = MPFR::ln_sqrtxp1_2y2(x1, y2, RoundUp  );
	}
	else // -1 ist Element von [x1,x2]
	{
	  l = MPFR::ln_sqrtxp1_2y2(MPFR::MpfrClass(-1), y1, RoundDown);
	  mpfr_add_ui(y1.GetValue(), x1.GetValue(), 2, RoundUp); // y1 = x1+2;
	  if (y1<=-x2)
	    r = MPFR::ln_sqrtxp1_2y2(x1, y2, RoundUp);
	  else r = MPFR::ln_sqrtxp1_2y2(x2, y2, RoundUp);
	}
      }

      res.SetInterval(l,r);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass sqrtx2y2(const MpfiClass& x, const MpfiClass& y)
    {
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
        prec = x.GetPrecision();
      else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass val(0);
      mpfi_hypot(val.mpfi_rep, x.mpfi_rep, y.mpfi_rep);
      val.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return val;
    }

    MpfiClass sqrt1mx2(const MpfiClass& x)
    // Calculating an inclusion of sqrt(1-x^2);                           Blomquist 26.06.2010
    // The precision of res is the actual precision of x.
    {
      PrecisionType prec     = x.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass absx(0);

      mpfi_abs(absx.mpfi_rep, x.mpfi_rep);  // absx = |x|

      MPFR::MpfrClass l, r;
      l = MPFR::sqrt1mx2(Inf(absx),RoundUp);
      r = MPFR::sqrt1mx2(Sup(absx),RoundDown);

      absx.SetInterval(r,l);
      absx.RoundPrecision(prec_old);           // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return absx;
    }

    MpfiClass sqrt1px2(const MpfiClass& x)                               // Blomquist 30.06.2010
    // Calculating an inclusion of sqrt(1+x^2);
    // The precision of res is the actual precision of x.
    {
      PrecisionType prec     = x.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass absx(0);

      mpfi_abs(absx.mpfi_rep, x.mpfi_rep);    // absx = |x|

      MPFR::MpfrClass l, r;

      l = MPFR::sqrt1px2(Inf(absx),RoundDown);
      r = MPFR::sqrt1px2(Sup(absx),RoundUp);
      absx.SetInterval(l,r);
      absx.RoundPrecision(prec_old);           // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return absx;
    }

    MpfiClass sqrt_N(unsigned long int k)
    // Calculating an inclusion of sqrt(k);
    // The precision of res is always the actual DefaultPrecision.
    {
      MpfiClass res(0);
      MPFR::MpfrClass l, r;

      l = MPFR::sqrt_n(k, RoundDown);
      r = MPFR::sqrt_n(k, RoundUp);

      res.SetInterval(l,r);
      return res;
    }

    // Liefert ein Einschliessung val aller Betragselementen von v, wobei die
    // Präzision von val durch prec bestimmt wird.
    // Wird prec nicht gesetzt, so erhaelt val die Current-Precision.
    MpfiClass abs(const MpfiClass& v, PrecisionType prec)
    {
        MpfiClass val(0, prec); // Rueckgabewert mit aktueller Current_precision!
        mpfi_abs(val.mpfi_rep, v.mpfi_rep);
        return val;
    }


    MpfiClass x2my2(const MpfiClass& x, const MpfiClass& y)
    {
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
             prec = x.GetPrecision();
        else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass absx(0), absy(0);
      mpfi_abs(absx.mpfi_rep, x.mpfi_rep);
      mpfi_abs(absy.mpfi_rep, y.mpfi_rep);
      MPFR::MpfrClass l, r;
      l = x2my2(Inf(absx), Sup(absy), RoundDown);
      r = x2my2(Sup(absx), Inf(absy), RoundUp);
      absx.SetInterval(l,r);
      absx.RoundPrecision(prec_old);           // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return absx;
    }

    MpfiClass x2py2(const MpfiClass& x, const MpfiClass& y)
    {
      PrecisionType prec,
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if ( x.GetPrecision() >= y.GetPrecision() )
             prec = x.GetPrecision();
        else prec = y.GetPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass absx(0), absy(0);
      mpfi_abs(absx.mpfi_rep, x.mpfi_rep);
      mpfi_abs(absy.mpfi_rep, y.mpfi_rep);
      MPFR::MpfrClass l, r;
      l = x2py2(Inf(absx), Inf(absy), RoundDown);
      r = x2py2(Sup(absx), Sup(absy), RoundUp);
      absx.SetInterval(l,r);
      absx.RoundPrecision(prec_old);           // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return absx;
    }

    // Calculating  a^n;
    MpfiClass power(const MpfiClass& a, int n)                            // Blomquist 06.06.2010
    {
      PrecisionType prec     = a.GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      int N(n), k(-1), r = prec;
      //  prec: increased precision by facor 1.03, in order to
      //        get optimal inclusions
      MpfiClass res(1.0), h(1.0);
      bool neg(n<0);

      if (neg) N = -N;  // N >=0
      if (N==0) goto ende;
      if (N==1) res = a;
      else
      {  // N>1
        mpfi_abs(h.mpfi_rep, a.mpfi_rep);  // h = abs(a);
        while(N>0)
        {
          k++;
          r = N % 2;
          if (k==0)
            if (r==1) res = a;
            else res = 1.0;
          else
          {
            mpfi_mul(h.mpfi_rep,h.mpfi_rep,h.mpfi_rep); // h = h*h
            if (r==1)
              mpfi_mul(res.mpfi_rep,res.mpfi_rep,h.mpfi_rep); // res = res*h
          }
          N = N / 2;
        }
      }
      if (neg) res = reci(res);
ende: res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    } // power

    // Calculating  a^n;
    MpfiClass power(const MpfiClass& a, long int n)                       // Blomquist 07.06.2010
    {
      PrecisionType prec     = a.GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      long int N(n), k(-1), r = prec;
      //  prec: increased precision by facor 1.03, in order to
        //      get an optimal inclusion of the result res.
      MpfiClass res(1.0), h(1.0);
      bool neg(n<0);

      if (neg) N = -N;  // N >=0
      if (N==0) goto ende;
      if (N==1) res = a;
      else
      {  // N>1
        mpfi_abs(h.mpfi_rep, a.mpfi_rep);  // h = abs(a);
        while(N>0)
        {
          k++;
          r = N % 2;
          if (k==0)
            if (r==1) res = a;
            else res = 1.0;
          else
          {
            mpfi_mul(h.mpfi_rep, h.mpfi_rep, h.mpfi_rep); // h = h*h
            if (r==1)
            mpfi_mul(res.mpfi_rep, res.mpfi_rep, h.mpfi_rep); // res = res*h
          }
          N = N / 2;
        }
      }
      if (neg) res = reci(res);
ende: res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass pow(const MpfiClass& x, const MpfiClass& e)                 // Blomquist 09.06.2010
    // Calculating an inclusion of  x^e
    // The result precision is the Current-Precision;
    {
        bool fertig = false,
             Infe_Supe;
        long int k;

        PrecisionType prec, prec_old = MPFR::MpfrClass::GetCurrPrecision();
        if ( x.GetPrecision() >= e.GetPrecision() )
             prec = x.GetPrecision();
        else prec = e.GetPrecision();
        if (prec < 64) prec = 64;
        if (prec < prec_old) prec = prec_old;
        MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

        MpfiClass y(0);

        mpfr_t supabs_E, tmp, tmp1;
        mpfr_init2(supabs_E, prec);
        mpfi_mag (supabs_E, e.mpfi_rep); // supabs_E: Maximum aller Beträge aus e

        mpfr_t left_E, right_E;
        mpfr_init2(left_E , prec);
        mpfr_init2(right_E, prec);

        mpfi_get_left  (left_E,  e.mpfi_rep);
        mpfi_get_right (right_E, e.mpfi_rep);

        Infe_Supe = (mpfr_equal_p(left_E,right_E) != 0); // returns true if Inf(e) == Sup(e);

        if (Infe_Supe)
        {
          mpfr_init_set_si (tmp, 2147483647, RoundNearest);

          if (mpfr_less_p (supabs_E,tmp ) != 0)
          {
            mpfr_rint_trunc (supabs_E, right_E, RoundNearest);
            if (mpfr_equal_p(supabs_E, right_E) != 0)
            {
              k = mpfr_get_si(right_E, RoundNearest);
              y = power(x, k);
              fertig = true;
            }
          }
        }

        if (!fertig)
        {
          mpfr_init2(supabs_E, prec);
          mpfi_get_left  (supabs_E,  x.mpfi_rep);  // supabs_E = Inf(x)
          mpfr_init2(tmp, prec);
          mpfi_get_right (tmp,  x.mpfi_rep);       // tmp      = Sup(x)

          // if ( Inf(x) == Sup(x) && Sup(x) == 1.0 )
          mpfr_init(tmp1);
          mpfr_init_set_si (tmp1, 1, RoundNearest);
          if ( mpfr_equal_p(supabs_E,tmp) != 0 && mpfr_equal_p(tmp,tmp1) != 0 )
            y = x;
          else
            // if ( Inf(e) == Sup(e) && Sup(e) == 1.0 )
            if ( Infe_Supe && mpfr_equal_p(right_E,tmp1) != 0 )
              y = x;
            else
            {
              mpfr_init_set_si (tmp1, 0, RoundNearest);
              // if ( Inf(e) == Sup(e) && Sup(e) == 0.0 )
              if ( Infe_Supe && mpfr_equal_p(right_E,tmp1) != 0 )
                y = 1.0;
              else
              {
                MpfiClass val(x);
                mpfi_log(val.mpfi_rep, val.mpfi_rep);              // val: ln(x)
                mpfi_mul(val.mpfi_rep, e.mpfi_rep, val.mpfi_rep);  // val: e*ln(x)
                mpfi_exp (y.mpfi_rep, val.mpfi_rep);               // y  : exp( e*ln(x) )
              }
            }
           mpfr_clear (tmp1);
        }

        mpfr_clear (left_E);
        mpfr_clear (tmp);
        mpfr_clear (right_E);
        mpfr_clear (supabs_E);
        y.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
        MpfiClass::SetCurrPrecision(prec_old); // Wiederherstellen der alten Current-Precision
        return y;
    }

//    MpfiClass pow(const MpfiClass& x, const cxsc::interval& e)
//    {
//      MpfiClass y(e, 53);
//      return pow(x,y);
//    }

    MpfiClass pow(const MpfiClass& x, const MPFR::MpfrClass& e)
    {
      MpfiClass y(e, e.GetPrecision());
      return pow(x,y);
    }

//    MpfiClass pow(const MpfiClass& x, const cxsc::real& e)
//    {
//      MpfiClass y(e, 53);
//      return pow(x,y);
//    }

    MpfiClass pow(const MpfiClass& x, const double& e)
    {
      MpfiClass y(e, 53);
      return pow(x,y);
    }

    void times2pown (MpfiClass& r, const long int n)  // Blomquist 17.05.2010
    // Calculating r*2^n without changing the precision of r
    {
      mpfi_mul_2si(r.mpfi_rep, r.mpfi_rep, n);
    }

    MPFR::MpfrClass Inf(const MpfiClass& v, PrecisionType prec)      // Blomquist 27.11.2010
    // Der linke Randpunkt von v wird in das Format der Current-Precision
    // in Richtung -inf gerundet und dann zurueckgegeben.
    // Im Fall  Precision (v) <= Curren-Precision,   bzw.
    //          Precision (v) =  Curren-Precision,
    // was in der Praxis der Normalfall sein wird, wird der linke
    // Randpunkt  EXAKT  zurueckgegeben.
    {
      MPFR::MpfrClass x(0, RoundNearest, prec);
      mpfi_get_left(x.GetValue(), v.mpfi_rep);
      return x;
    }

    MPFR::MpfrClass Sup(const MpfiClass& v, PrecisionType prec)      // Blomquist 27.11.2010
    // Beschreibg. sinngemaess wie bei Inf(...)
    {
      MPFR::MpfrClass x(0, RoundNearest, prec);
      mpfi_get_right(x.GetValue(), v.mpfi_rep);
      return x;
    }

/*------------------------------------------------------*/
/*----------end extended Arithmetic Functions-----------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start Special Functions --------------------*/
/*------------------------------------------------------*/

    // Erzeugt ein neues Objekt mit dem Logarithmus von v
    MpfiClass ln(const MpfiClass& v){

        MpfiClass val(0);
        mpfi_log(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit exp(v)
    MpfiClass exp(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_exp(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit exp2(v) = 2^v
    MpfiClass exp2(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_exp2(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit exp10(v) = 10^v
    MpfiClass exp10(const MpfiClass& v)   // Blomquist 17.07.2010
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      mpfr_t links, rechts;

      mpfr_init2(links, prec);
      mpfr_init2(rechts, prec);

      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);

      mpfr_exp10(links,  links,  RoundDown);
      mpfr_exp10(rechts, rechts, RoundUp);

      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);

      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    // Erzeugt ein neues Objekt mit cos(v)
    MpfiClass cos(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_cos(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit sin(v)
    MpfiClass sin(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_sin(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit tan(v)
    MpfiClass tan(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_tan(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    MpfiClass cot(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_cot(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit acos(v)
    MpfiClass acos(const MpfiClass& v)
    {
        MpfiClass val(0.0, v.GetPrecision());
        mpfi_acos(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit asin(v)
    MpfiClass asin(const MpfiClass& v)
    {
        MpfiClass val(0.0, v.GetPrecision());
        mpfi_asin(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit atan(v)
    MpfiClass atan(const MpfiClass& v)
    {
      MpfiClass val(0);
      mpfi_atan(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    // The interval function ATAN2() can be used as Arg-function
    // for complex intervals   z = Re(z) + i*Im(z),   with:
    // Re(z) = x  and  Im(z) = y;
    // If the negative real axis is touched from below then an
    // error message is generated.
    MpfiClass ATAN2(const MpfiClass& y, const MpfiClass& x)
    {
      MpfiClass res(0); // res initialisiert mit Current-Precision
      if (Inf(y)<0 && Sup(y)>=0 && Inf(x)<0)
      {
        std::cerr << "Error in ATAN2(): The interval y touches the negative axis from below!" << std::endl;
        exit(1);
      }
      mpfi_atan2(res.mpfi_rep, y.mpfi_rep, x.mpfi_rep);
      return res;
    }

    MpfiClass atan2(const MpfiClass& y, const MpfiClass& x)
    {
      MpfiClass res(0);
      mpfi_atan2(res.mpfi_rep, y.mpfi_rep, x.mpfi_rep);
      return res;
    }

    // Erzeugt ein neues Objekt mit acot(v)  Blomquist 18.05.2010
    MpfiClass acot(const MpfiClass& v)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);               // Initialisiert mit neuer Current-Precision
      MPFR::MpfrClass links, rechts;  // Initialisiert mit neuer Current-Precision

      links  = acot(Inf(v), RoundUp);
      rechts = acot(Sup(v), RoundDown);
      res.SetInterval(rechts, links);

      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    // Erzeugt ein neues Objekt mit cosh(v)
    MpfiClass cosh(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_cosh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit sinh(v)
    MpfiClass sinh(const MpfiClass& v){

        MpfiClass val(0);
        mpfi_sinh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit tanh(v)
    MpfiClass tanh(const MpfiClass& v){

        MpfiClass val(0);
        mpfi_tanh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit coth(v)     // Blomquist 20.09.2010
    MpfiClass coth(const MpfiClass& v)
    {
      MpfiClass val(0);
      mpfi_coth(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    MpfiClass csc (const MpfiClass& v)  // 1/sin
    {
      MpfiClass val(0);
      mpfi_csc(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    MpfiClass sec (const MpfiClass& v)  // 1/cos
    {
      MpfiClass val(0);
      mpfi_sec(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    MpfiClass csch(const MpfiClass& v)  // 1/sinh
    {
      MpfiClass val(0);
      mpfi_csch(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    MpfiClass sech(const MpfiClass& v)  // 1/cosh
    {
      MpfiClass val(0);
      mpfi_sech(val.mpfi_rep, v.mpfi_rep);
      return val;
    }

    // Erzeugt ein neues Objekt mit acosh(v)
    MpfiClass acosh(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_acosh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit acoshp1(v)
    MpfiClass acoshp1(const MpfiClass& x)
    {
      PrecisionType prec     = x.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision;
      MpfiClass res(0);
      MPFR::MpfrClass l, r;

      l = MPFR::acoshp1(Inf(x),RoundDown);
      r = MPFR::acoshp1(Sup(x),RoundUp);
      res.SetInterval(l,r);

      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    // Erzeugt ein neues Objekt mit asinh(v)
    MpfiClass asinh(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_asinh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit atanh(v)
    MpfiClass atanh(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_atanh(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit acoth(v)  // Blomquist 18.05.2010
    MpfiClass acoth(const MpfiClass& v)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass val(0), x(0);
      MPFR::MpfrClass u1,u2;
      bool neg;

      x = v;
      neg = ( isNeg(Inf(x)) );
      if (neg)
        x = -x;     // Symmetry to the origin
      u1 = Inf(x);
      u2 = Sup(x);

      if (u1<1.0)
        val = "NaN";
      else
      {
        u1 = acoth(u1,RoundUp);
        u2 = acoth(u2,RoundDown);
        val.SetInterval(u2,u1);
        if (neg) val = -val;
      }
      val.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return val;
    }

    // Erzeugt ein neues Objekt mit log(1+v)
    MpfiClass lnp1(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_log1p(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit exp(v)-1
    MpfiClass expm1(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_expm1(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    MpfiClass expmx2(const MpfiClass& v)   // Blomquist 11.08.2010
    // exp(-x^2)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision;
      MpfiClass res(0);
      MpfiClass a_v(abs(v));
      MPFR::MpfrClass links, rechts;
      links = expmx2(Inf(a_v), RoundUp);
      rechts = expmx2(Sup(a_v), RoundDown);

      res.SetInterval(rechts, links);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass expmx2m1(const MpfiClass& v)   // Blomquist 11.08.2010
    // exp(-x^2) - 1;
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // neue Current-Precision prec

      MpfiClass res(0);
      MpfiClass a_v(abs(v));
      MPFR::MpfrClass links, rechts;
      links = expmx2m1(Inf(a_v), RoundUp);
      rechts = expmx2m1(Sup(a_v), RoundDown);

      res.SetInterval(rechts, links);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass expx2(const MpfiClass& v)   // Blomquist 11.08.2010
    // exp(+x^2)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      MpfiClass a_v(abs(v));
      MPFR::MpfrClass links, rechts;
      links = expx2(Inf(a_v), RoundDown);
      rechts = expx2(Sup(a_v), RoundUp);

      res.SetInterval(rechts, links);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass expx2m1(const MpfiClass& v)   // Blomquist 11.08.2010
    // exp(+x^2) - 1;
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      MpfiClass a_v(abs(v));
      MPFR::MpfrClass links, rechts;
      links = expx2m1(Inf(a_v), RoundDown);
      rechts = expx2m1(Sup(a_v), RoundUp);
      res.SetInterval(rechts, links);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    // Erzeugt ein neues Objekt mit log_2(v)
    MpfiClass log2(const MpfiClass& v)
    {
        MpfiClass val(0);
        mpfi_log2(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    // Erzeugt ein neues Objekt mit log_10(v)
    MpfiClass log10(const MpfiClass& v){

        MpfiClass val(0);
        mpfi_log10(val.mpfi_rep, v.mpfi_rep);
        return val;
    }

    MpfiClass ln_cos(const MpfiClass& v)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      if ( diam(v) > MPFR::MpfrClass::Pi(RoundDown) )
      {
        set_nan(res);
        return res;
      }
      MPFR::MpfrClass rechts(0), links(0), tmp(0);
      tmp    = -sin(Inf(v));  // Calculating the derivatives of cos(v)
      rechts = -sin(Sup(v));  // at the boundary points of v
      if ( sign(tmp)*sign(rechts)<=0 )
      {
        links  = ln_cos(Inf(v), RoundDown);
        rechts = ln_cos(Sup(v), RoundDown);
        if ( isNumber(links) && isNumber(rechts) )
        {
          if (rechts<links)
            links = rechts;
          rechts = 0;
        }
      }
      else // either monotonically increasing or monotonically decreasing:
      {
        if (sign(tmp)>0) // monotonically increasing:
        {
          links  = ln_cos(Inf(v), RoundDown);
          rechts = ln_cos(Sup(v), RoundUp);
        }
        else  // monotonically decreasing:
        {
          links  = ln_cos(Sup(v), RoundDown);
          rechts = ln_cos(Inf(v), RoundUp);
        }
      }
      res.SetInterval(links, rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass ln_sin(const MpfiClass& v)
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      if ( diam(v) > MPFR::MpfrClass::Pi(RoundDown) )
      {
        set_nan(res);
        return res;
      }
      MPFR::MpfrClass rechts(0), links(0), tmp(0);
      tmp    = cos(Inf(v)); // Calculating the derivatives of sin(v)
      rechts = cos(Sup(v)); // at the boundary points of v
      if ( sign(tmp)*sign(rechts)<=0 )
      {
        links  = ln_sin(Inf(v), RoundDown);
        rechts = ln_sin(Sup(v), RoundDown);
        if ( isNumber(links) && isNumber(rechts) )
        {
          if (rechts<links)
            links = rechts;
          rechts = 0;
        }
      }
      else // either monotonically increasing or monotonically decreasing:
      {
        if (sign(tmp)>0) // monotonically increasing:
        {
          links  = ln_sin(Inf(v), RoundDown);
          rechts = ln_sin(Sup(v), RoundUp);
        }
        else  // monotonically decreasing:
        {
          links  = ln_sin(Sup(v), RoundDown);
          rechts = ln_sin(Inf(v), RoundUp);
        }
      }
      res.SetInterval(links, rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass erf(const MpfiClass& v)   // Blomquist 14.05.2010
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      mpfr_t links, rechts;
      mpfr_init2(links, prec);
      mpfr_init2(rechts, prec);

      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);

      mpfr_erf(links,  links,  RoundDown);
      mpfr_erf(rechts, rechts, RoundUp);

      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);

      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass erfc(const MpfiClass& v)   // Blomquist 17.05.2010
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Neue Current-Precision prec

      MpfiClass res(0);
      mpfr_t links, rechts;

      mpfr_init2(links, prec);
      mpfr_init2(rechts, prec);

      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);

      mpfr_erfc(links,  links,  RoundUp);
      mpfr_erfc(rechts, rechts, RoundDown);

      res.SetInterval(rechts,links);
      mpfr_clear(links);  mpfr_clear(rechts);

      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    bool PoleInInterval(const MpfiClass& v)
    // Prueft, ob die Pole 0,-1,-2, ...  in v liegen
    {
      bool res(false);

      MPFR::MpfrClass links;
      links = Inf(v);

      if (links <= 0)
      {
        MPFR::MpfrClass rechts, tmp;
        rechts = Sup(v);
        tmp = Ceil(links);
        res = (links == tmp || rechts >= tmp);
      }

      return res;
    }

    MpfiClass digamma(const MpfiClass& v)   // Blomquist 20.07.2010
    // digamma(x) = gamma'(x) / gamma(x);
    // If one of the poles 0,-1,-2,... is in v then an error message is generated.
    // For all arguments of the interval v a nearly optimal inclusion of all
    // function values of the digamma function is calculated.
    {
      if (PoleInInterval(v))
      {
        std::cerr << "Error in digamma(const MpfiClass& v):  Pole in interval v" << std::endl;
        exit(1);
      }
      // No pole in Interval v:
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      mpfr_t links, rechts;
      mpfr_init2(links, prec);
      mpfr_init2(rechts, prec);

      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);

      mpfr_digamma(links,  links,  RoundDown);
      mpfr_digamma(rechts, rechts, RoundUp);

      res.SetInterval(links, rechts);

      mpfr_clear(links);
      mpfr_clear(rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass gamma_D(const MpfiClass& v)                            // Blomquist 21.07.2010
    // If one of the poles 0,-1,-2,... is in v then an error message is generated.
    // For all arguments of the interval v a nearly optimal inclusion of all
    // function values of the first derivative of the gamma function is calculated.
    {
      if (PoleInInterval(v))
      {
        std::cerr << "Error in gamma_D(const MpfiClass& v):  Pole in interval v" << std::endl;
        exit(1);
      }
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      MPFR::MpfrClass links, rechts, tmp;

      links = Inf(v);
      rechts = Sup(v);

      if (links >= 0)
      // Linker Randpunkt >= 0:
      {
        links  = gamma_D(links,  RoundDown);
        rechts = gamma_D(rechts, RoundUp);
      }
      else // linker Randpunkt < 0;
      {
        tmp = Ceil(links);
        if (isEven(tmp)) // Gamma'(x) ist monoton fallend:
        {
          tmp = links;
          links  = gamma_D(rechts, RoundDown);
          rechts = gamma_D(tmp, RoundUp);
        }
        else // Gamma'(x) ist monotn wachsend:
        {
          links  = gamma_D(links , RoundDown);
          rechts = gamma_D(rechts, RoundUp);
        }
      }
      res.SetInterval(links, rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    // Ei(v);  Inf(v) >= 0;
    MpfiClass Ei(const MpfiClass& v)   // Blomquist 19.05.2010
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      mpfr_t links, rechts;

      mpfr_init2(links, prec);
      mpfr_init2(rechts,prec);

      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);

      mpfr_eint(links,  links,  RoundDown);
      mpfr_eint(rechts, rechts, RoundUp);

      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass cbrt(const MpfiClass& v)
    {
      MpfiClass res(0.0, v.GetPrecision());
      mpfi_cbrt (res.mpfi_rep, v.mpfi_rep);
      return res;
    }

    MpfiClass sqrt(const MpfiClass& v, unsigned long int n) // Blomquist 19.05.2010
    {
      PrecisionType prec     = v.MpfiClass::GetPrecision(),
                    prec_old = MPFR::MpfrClass::GetCurrPrecision();
      if (prec < prec_old) prec = prec_old;
      MpfiClass::SetCurrPrecision(prec); // Die neue Current-Precision prec ist mindestens
                                         // gleich der alten Current-Precision!
      MpfiClass res(0);
      mpfr_t links, rechts;

      mpfr_init2(links, prec);
      mpfr_init2(rechts,prec);
      mpfi_get_left(links,   v.mpfi_rep);
      mpfi_get_right(rechts, v.mpfi_rep);
      mpfr_root(links, links, n, RoundDown);
      mpfr_root(rechts, rechts, n, RoundUp);
      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);
      res.RoundPrecision(prec_old);            // Runden auf die alte Current-Precision
      MpfiClass::SetCurrPrecision(prec_old);   // Wiederherstellen der alten Current-Precision
      return res;
    }

    MpfiClass ifactorial (unsigned long int n)
    {
      PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision();
      MpfiClass res(0);
      mpfr_t links, rechts;
      mpfr_init2(links, prec);
      mpfr_init2(rechts,prec);

      mpfr_fac_ui(links,  n, RoundDown);
      mpfr_fac_ui(rechts, n, RoundUp);

      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);

      return res;
    }

    MpfiClass izeta (unsigned long int n )
    {
      PrecisionType prec = MPFR::MpfrClass::GetCurrPrecision();
      MpfiClass res(0);
      mpfr_t links, rechts;
      mpfr_init2(links, prec);
      mpfr_init2(rechts,prec);

      mpfr_zeta_ui(links,  n, RoundDown);
      mpfr_zeta_ui(rechts, n, RoundUp);

      res.SetInterval(links, rechts);
      mpfr_clear(links);  mpfr_clear(rechts);

      return res;
    }

/*------------------------------------------------------*/
/*----------end Special Functions ----------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*----------start Interval Functions--------------------*/
/*------------------------------------------------------*/

   // Ergebniss wird in der uebergebenen mpfr_t-Variable gespeichert
   // "Ober-Grenze(v)" - "Unter-Grenze(v)" wird in val gespeichert
   // Praezision(val) = Praezision(v);
   void diam(const MpfiClass& v, mpfr_t& val)
   {
       mpfr_init2(val, v.GetPrecision());
       mpfi_diam_abs(val, v.mpfi_rep);
   }

    void RelDiam(const MpfiClass& x, mpfr_t& val)                            // Blomquist 02.07.2010
    // Calculates the uprounded absolute diam if 0 in val,
    // otherwise the uprounded maximum of the relative diameter;
    // Praezision(val) = Praezision(v);
    {
       PrecisionType prec = x.GetPrecision();
       mpfr_init2(val, prec);
       // mpfi_diam(val, x.mpfi_rep);  // Urspruenglich
       if (0<=x)
          mpfi_diam_abs(val, x.mpfi_rep);
       else
       {
          mpfr_t l, r;
          MpfiClass x_scl(x, prec);
          long int ex_l, ex_r, emax = mpfr_get_emax ();
          mpfr_init2(l, prec);
          mpfi_get_left(l, x.mpfi_rep);    // l = Inf(x)
          mpfr_init2(r, prec);
          mpfi_get_right(r, x.mpfi_rep);   // r = Sup(x)

          ex_l = mpfr_get_exp(l);  ex_r = mpfr_get_exp(r);
          if (ex_r > ex_l) ex_l = ex_r;  // ex_l = max(ex_l,ex_r);
          ex_r = emax - ex_l - 10;       // Mit exr ist zu skalieren:
          mpfi_mul_2si(x_scl.mpfi_rep, x_scl.mpfi_rep, ex_r);
          // Calculating the absolute error:
          mpfi_diam_abs(val, x_scl.mpfi_rep);  // val = absolute error;
          // Calculating the minimum of |x_scl|
          mpfi_mig (l, x_scl.mpfi_rep);  // l = Min{ |x_scl| } = <|x_scl|>
          mpfr_div(val, val, l, RoundUp);
          mpfr_clear(l);  mpfr_clear(r);
       }
    }

    // Auslesen des groessten absoluten Wertes von v
    void AbsMax(const MpfiClass& v, mpfr_t& val)
    {
        mpfr_init2(val, v.GetPrecision());
        mpfi_mag(val, v.mpfi_rep);
    }

    // Auslesen des kleinsten absoluten Wertes von v
    void AbsMin(const MpfiClass& v, mpfr_t& val)
    {
        mpfr_init2(val, v.GetPrecision());
        mpfi_mig(val, v.mpfi_rep);
    }

    // Auslesen der Mitte von v
    void mid(const MpfiClass& v, mpfr_t& val)
    {
        mpfr_init2(val, v.GetPrecision());
        mpfi_mid(val, v.mpfi_rep);
    }


    void random(const MpfiClass& v, mpfr_t& val)
    // Calculating a random number val out of v;
    // Precision(val) = precision(v);
    {
        mpfr_init2(val, v.GetPrecision());
        mpfi_alea(val, v.mpfi_rep);
    }

    // Auslesen des Exponenten e vom Durchmessers von v;
    // -e ist die Anzahl der exakten Dezimalstellen der Einschließung v,
    // falls 0 nicht in v enthalten ist.
    // Nur fuer den internen Gebrauch! (common_decimals)
    mpfr_exp_t get_diam_exp(const MpfiClass& v)
    {
        mpfr_t a;
        mpfr_init2(a, v.GetPrecision());

        RelDiam(v, a);

        mpfr_exp_t e;
        char* s;
        // s = mpfr_get_str(NULL, &e, MpfiClass::GetBase(), 5, a, MpfiClass::GetCurrRndMode());
        s = mpfr_get_str(NULL, &e, MpfiClass::GetBase(), 5, a, RoundNearest);
        mpfr_clear(a);

        return e;
    }

    MpfiClass Blow(const MpfiClass& x, const MPFR::MpfrClass& eps)              // Blomquist 03.07.2010
    // eps-inflation as defined in cxsc
    // Precision(inflated interval) = precision(x);
    {
       PrecisionType prec = x.GetPrecision();
       MpfiClass res(0.0, prec), tmp(0.0, prec);

       MPFR::MpfrClass EPS  (0, RoundNearest, prec),
                       right(0, RoundNearest, prec);
       mpfr_abs (EPS.GetValue(), getvalue(eps), RoundNearest);  // EPS = |eps|
       // Berechnung von EPS*x
       mpfi_mul_fr (res.mpfi_rep, x.mpfi_rep, EPS.GetValue());   // res = EPS*x
       // Berechnung von 1+EPS (aufgerundet):
       mpfr_add_si (EPS.GetValue(), EPS.GetValue(), 1, RoundUp); // EPS = 1+EPS
       // Berechnung von (1+EPS)*x
       mpfi_mul_fr (tmp.mpfi_rep, x.mpfi_rep, EPS.GetValue());   // tmp = (1+EPS)*x
       // Berechnung von (1+EPS)*x - EPS*x
       mpfi_sub (tmp.mpfi_rep, tmp.mpfi_rep, res.mpfi_rep);      // tmp = (1+EPS)*x - EPS*x
       mpfi_get_left  (EPS.GetValue(), tmp.mpfi_rep);            // EPS = Inf(tmp)
       mpfr_nextbelow (EPS.GetValue());                          // EPS = pred( Inf(tmp) )
       mpfi_get_right (right.GetValue(), tmp.mpfi_rep);          // right = Sup(tmp)
       mpfr_nextabove (right.GetValue());                        // right = succ( Sup(tmp) )
       res.SetInterval(EPS,right);

       return res;
    }

    // Returns the upwards rounded absolute diameter of the interval v;
    // The result precision is the precision of v;
    MPFR::MpfrClass diam(const MpfiClass& v)
    {
        MPFR::MpfrClass val(0, RoundNearest, v.GetPrecision());
        mpfi_diam_abs(val.GetValue(), v.mpfi_rep);
        return val;
    }

    // Returns the upwards rounded relative diameter of x if x does not
    // contain zero, otherwise the upwards rounded absolute diameter of x.
    // The result precision is the precision of x;
    MPFR::MpfrClass RelDiam(const MpfiClass& x)
    {
       PrecisionType prec = x.GetPrecision();
       MPFR::MpfrClass res(0, RoundNearest, prec);

       if (0<=x)
          mpfi_diam_abs(res.GetValue(), x.mpfi_rep);
       else
       {
          mpfr_t l, r;
          MpfiClass x_scl(x, prec);  // x_scl = x, EXAKT!
          long int ex_l, ex_r, emax = mpfr_get_emax ();
          // l = Inf(x);  r = Sup(x);
          mpfr_init2(l, prec);
          mpfi_get_left(l, x.mpfi_rep);    // l = Inf(x)
          mpfr_init2(r, prec);
          mpfi_get_right(r, x.mpfi_rep);   // r = Sup(x)

          // ex_l = expo(l);   ex_r = expo(r);
          ex_l = mpfr_get_exp(l);  ex_r = mpfr_get_exp(r);
          if (ex_r > ex_l) ex_l = ex_r;  // ex_l = max(ex_l,ex_r);
          ex_r = emax - ex_l - 10;       // Mit exr ist zu skalieren:
          mpfi_mul_2si(x_scl.mpfi_rep, x_scl.mpfi_rep, ex_r);  // Multiplication with 2^(ex_r) without overflow
          // Calculating the absolute error:
          mpfi_diam_abs(res.GetValue(), x_scl.mpfi_rep);  // res = absolute error;
          // Calculating the minimum of |x_scl|
          mpfi_mig (l, x_scl.mpfi_rep);                   // l = Min{ |x_scl| } = <|x_scl|>
          mpfr_div(res.GetValue(), res.GetValue(), l, RoundUp);

          mpfr_clear(l);  mpfr_clear(r);
       }
       return res;
    }

// ------------------------------------------------------------------------------

    int in (const MPFR::MpfrClass& x, const MpfiClass& y)
    {
      MpfiClass t(x, x.GetPrecision());
      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
    }

    int in (const mpfr_t& x, const MpfiClass& y)
    {
      MpfiClass t(x, mpfr_get_prec(x));
      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
    }

    int in (const double& x, const MpfiClass& y)
    {
      MpfiClass t(x, 53);
      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
    }

//    int in (const cxsc::real& x, const MpfiClass& y)
//    {
//      MpfiClass t(x, 53);
//      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
//    }

    int in (const int& x, const MpfiClass& y)
    {
      MpfiClass t(x, 64);
      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
    }

    int in (const MpfiClass& x, const MpfiClass& y)
    {
      MpfiClass t(x, x.GetPrecision());
      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
    }

    int in (const mpfi_t& x, const MpfiClass& y)
    {
      return mpfi_is_strictly_inside(x, y.mpfi_rep);
    }

//    int in (const cxsc::interval& x, const MpfiClass& y)
//    {
//      MpfiClass t(x, 53);
//      return mpfi_is_strictly_inside(t.mpfi_rep, y.mpfi_rep);
//    }

// -----------------------------------------------------------------------

    MPFR::MpfrClass AbsMax(const MpfiClass& v)
    {
        MPFR::MpfrClass val(0, RoundNearest, v.GetPrecision());
        mpfi_mag(val.GetValue(), v.mpfi_rep);
        return val;
    }

    MPFR::MpfrClass AbsMin(const MpfiClass& v)
    {
        MPFR::MpfrClass val(0, RoundNearest, v.GetPrecision());
        mpfi_mig(val.GetValue(), v.mpfi_rep);
        return val;
    }

    MPFR::MpfrClass mid(const MpfiClass& v)
    // Calculating the middle of v;
    // Precision(mid) = precision(v);  --->  mid lies in v;
    // Be carefull: If mid is later on rounded into a format
    // with lower precision then the new mid must not be an
    // element of v !  So don't round the calculated mid value.
    {
        MPFR::MpfrClass val(0, RoundNearest, v.GetPrecision());
        mpfi_mid(val.GetValue(), v.mpfi_rep);
        return val;
    }

    MPFR::MpfrClass random (const MpfiClass& v)
    // Calculating a random number out of v;
    // Precision(number) = precision(v);
    {
        MPFR::MpfrClass val(0, RoundNearest, v.GetPrecision());
        mpfi_alea(val.GetValue(), v.mpfi_rep);
        return val;
    }

/*------------------------------------------------------*/
/*----------end Interval Functions----------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start Operating on Endpoint Functions ------*/
/*------------------------------------------------------*/

    // Ergebnis wird in der uebergebenen mpfr_t-Variable gespeichert

    // Der linke Endpunkt wird in val gespeichert
    void MpfiClass::GetLeft(mpfr_t& val)
    {
        mpfi_get_left(val, mpfi_rep);
    }

    // Der rechte Endpunkt wird in val gespeichert
    void MpfiClass::GetRight(mpfr_t& val)
    {
        mpfi_get_right(val, mpfi_rep);
    }

    // Sollten die Endpunkte in falscher Reihenfolge sein,
    // d.h. linker Endpunkt > rechter Endpunkt, werden Sie getauscht
    int MpfiClass::swap_endpoints()
    {
        return mpfi_revert_if_needed(mpfi_rep);
    }


// ----------------------------------------------------------------------------------
// --------  Operators for calculating the convex hull of a and b  ------------------
// ----------------------------------------------------------------------------------
    MpfiClass operator | ( const MpfiClass& a, const MpfiClass& b )
    {
      PrecisionType prec;
      if(a.GetPrecision() >= b.GetPrecision())
           prec = a.GetPrecision();
      else prec = b.GetPrecision();

      MpfiClass res(a, prec);
      mpfi_put(res.mpfi_rep, b.mpfi_rep);
      return res;
    }

    MpfiClass operator | ( const double& a, const MpfiClass& b )
    {
      PrecisionType prec = b.GetPrecision();
      if(53 > prec) prec = 53;
      MpfiClass res(b, prec);
      mpfi_put_d(res.mpfi_rep, a);
      return res;
    }

    MpfiClass operator | ( const MpfiClass& b, const double& a )
    {
      PrecisionType prec = b.GetPrecision();
      if(53 > prec) prec = 53;
      MpfiClass res(b, prec);
      mpfi_put_d(res.mpfi_rep, a);
      return res;
    }

//    MpfiClass operator | ( const cxsc::real& a, const MpfiClass& b )
//    {
//      PrecisionType prec = b.GetPrecision();
//      if(53 > prec) prec = 53;
//      MpfiClass res(b, prec);
//      mpfi_put_d(res.mpfi_rep, cxsc::_double(a));
//      return res;
//    }

//    MpfiClass operator | ( const MpfiClass& b, const cxsc::real& a )
//    {
//      PrecisionType prec = b.GetPrecision();
//      if(53 > prec) prec = 53;
//      MpfiClass res(b, prec);
//      mpfi_put_d(res.mpfi_rep, cxsc::_double(a));
//      return res;
//    }

//    MpfiClass operator | ( const cxsc::interval& a, const MpfiClass& b )
//    {
//      PrecisionType prec = b.GetPrecision();
//      if(53 > prec) prec = 53;
//      MpfiClass res(b, prec);
//      MpfiClass x(a, prec);
//      mpfi_put(res.mpfi_rep, x.mpfi_rep);
//      return res;
//    }

//    MpfiClass operator | ( const MpfiClass& b, const cxsc::interval& a )
//    {
//      PrecisionType prec = b.GetPrecision();
//      if(53 > prec) prec = 53;
//      MpfiClass res(b, prec);
//      MpfiClass x(a, prec);
//      mpfi_put(res.mpfi_rep, x.mpfi_rep);
//      return res;
//    }

    MpfiClass operator | ( int i, const MpfiClass& b )
    {
      PrecisionType prec = b.GetPrecision();
      if(64 > prec) prec = 64;
      MpfiClass res(b, prec);
      mpfi_put_si(res.mpfi_rep, i);
      return res;
    }

    MpfiClass operator | ( const MpfiClass& b, int i )
    {
      PrecisionType prec = b.GetPrecision();
      if(64 > prec) prec = 64;
      MpfiClass res(b, prec);
      mpfi_put_si(res.mpfi_rep, i);
      return res;
    }

    MpfiClass operator | ( const MpfiClass& b, const mpfr_t& u )
    {
      PrecisionType prec = b.GetPrecision();
      if(mpfr_get_prec(u) > prec) prec = mpfr_get_prec(u);
      MpfiClass res(b, prec);
      mpfi_put_fr(res.mpfi_rep, u);
      return res;
    }

    MpfiClass operator | ( const mpfr_t& u, const MpfiClass& b )
    {
      PrecisionType prec = b.GetPrecision();
      if(mpfr_get_prec(u) > prec) prec = mpfr_get_prec(u);
      MpfiClass res(b, prec);
      mpfi_put_fr(res.mpfi_rep, u);
      return res;
    }

    MpfiClass operator | ( const MpfiClass& b, const mpfi_t& u )
    {
      PrecisionType prec = b.GetPrecision();
      if(mpfi_get_prec(u) > prec) prec = mpfi_get_prec(u);
      MpfiClass res(b, prec);
      mpfi_put(res.mpfi_rep, u);
      return res;
    }

    MpfiClass operator | ( const mpfi_t& u, const MpfiClass& b )
    {
      PrecisionType prec = b.GetPrecision();
      if(mpfi_get_prec(u) > prec) prec = mpfi_get_prec(u);
      MpfiClass res(b, prec);
      mpfi_put(res.mpfi_rep, u);
      return res;
    }

    MpfiClass operator | ( const MpfiClass& b, const MPFR::MpfrClass& u )
    {
      PrecisionType prec = b.GetPrecision();
      if(u.GetPrecision() > prec) prec = u.GetPrecision();
      MpfiClass res(b, prec);
      MpfiClass x(u, prec);
      mpfi_put(res.mpfi_rep, x.mpfi_rep);
      return res;
    }

    MpfiClass operator | ( const MPFR::MpfrClass& u, const MpfiClass& b )
    {
      PrecisionType prec = b.GetPrecision();
      if(u.GetPrecision() > prec) prec = u.GetPrecision();
      MpfiClass res(b, prec);
      MpfiClass x(u, prec);
      mpfi_put(res.mpfi_rep, x.mpfi_rep);
      return res;
    }

    MpfiClass & operator |= (MpfiClass& a, const MpfiClass& b)
    {
      PrecisionType prec = a.GetPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }

    MpfiClass & operator |= (MpfiClass& a, const double& b)
    {
      PrecisionType prec = a.GetPrecision();
      if (53 > prec) prec = 53;
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }

//    MpfiClass & operator |= ( MpfiClass& a, const cxsc::real& b )
//    {
//      PrecisionType prec = a.GetPrecision();
//      if (53 > prec) prec = 53;
//      MpfiClass tmp(a|b, prec);
//      set_Mpfi(a, tmp, prec);
//      return a;
//    }

//    MpfiClass & operator |= ( MpfiClass& a, const cxsc::interval& b )
//    {
//      PrecisionType prec = a.GetPrecision();
//      if (53 > prec) prec = 53;
//      MpfiClass tmp(a|b, prec);
//      set_Mpfi(a, tmp, prec);
//      return a;
//    }

    MpfiClass & operator |= (MpfiClass& a, int b)
    {
      PrecisionType prec = a.GetPrecision();
      if (64 > prec) prec = 64;
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }

    MpfiClass & operator |= (MpfiClass& a, const mpfr_t& b)
    {
      PrecisionType prec = a.GetPrecision();
      if (mpfr_get_prec(b) > prec) prec = mpfr_get_prec(b);
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }

    MpfiClass & operator |= (MpfiClass& a, const mpfi_t& b)
    {
      PrecisionType prec = a.GetPrecision();
      if (mpfi_get_prec(b) > prec) prec = mpfi_get_prec(b);
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }

    MpfiClass & operator |= (MpfiClass& a, const MPFR::MpfrClass& b)
    {
      PrecisionType prec = a.GetPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      MpfiClass tmp(a|b, prec);
      set_Mpfi(a, tmp, prec);
      return a;
    }


// -----------------------------------------------------------------------------------
// --------  Operators for calculating the intersection of a and b  ------------------
// --------       if (a & b) is empty [@NaN,@NaN] is returned       ------------------
// -- The precision of the returned interval is the maximum of the precision of a,b --
// -----------------------------------------------------------------------------------

    MpfiClass operator & (const MpfiClass& a, const MpfiClass& b )
    {
      PrecisionType prec;
      if(a.GetPrecision() >= b.GetPrecision())
           prec = a.GetPrecision();
      else prec = b.GetPrecision();
      MpfiClass res(0.0, prec);

      if (mpfi_cmp (a.mpfi_rep, b.mpfi_rep) == 0) // Intersection is not empty
         mpfi_intersect (res.mpfi_rep, a.mpfi_rep, b.mpfi_rep);
      else
         set_nan (res);

      return res;
    }

    MpfiClass operator & ( const MpfiClass& a, const double& b )
    {
      MpfiClass x(b, 53);
      return a & x;
    }

    MpfiClass operator & ( const double& b, const MpfiClass& a )
    {
      MpfiClass x(b, 53);
      return a & x;
    }

//    MpfiClass operator & ( const MpfiClass& a, const cxsc::real& b )
//    {
//      MpfiClass x(b, 53);
//      return a & x;
//    }

//    MpfiClass operator & ( const cxsc::real& b, const MpfiClass& a )
//    {
//      MpfiClass x(b, 53);
//      return a & x;
//    }

//    MpfiClass operator & ( const MpfiClass& a, const cxsc::interval& b )
//    {
//      MpfiClass x(b, 53);
//      return a & x;
//    }

//    MpfiClass operator & ( const cxsc::interval& b, const MpfiClass& a )
//    {
//      MpfiClass x(b, 53);
//      return a & x;
//    }

    MpfiClass operator & ( const MpfiClass& a, int b )
    {
      MpfiClass x(b, 64);
      return a & x;
    }

    MpfiClass operator & ( int b, const MpfiClass& a )
    {
      MpfiClass x(b, 64);
      return a & x;
    }

    MpfiClass operator & ( const MpfiClass& a, const MPFR::MpfrClass& b )
    {
      MpfiClass x(b, b.GetPrecision());
      return a & x;
    }

    MpfiClass operator & ( const MPFR::MpfrClass& b, const MpfiClass& a )
    {
      MpfiClass x(b, b.GetPrecision());
      return a & x;
    }

    MpfiClass operator & ( const MpfiClass& a, const mpfr_t& b )
    {
      MpfiClass x(b, mpfr_get_prec(b));
      return a & x;
    }

    MpfiClass operator & ( const mpfr_t& b, const MpfiClass& a )
    {
      MpfiClass x(b, mpfr_get_prec(b));
      return a & x;
    }

    MpfiClass operator & ( const MpfiClass& a, const mpfi_t& b )
    {
      MpfiClass x(b, mpfi_get_prec(b));
      return a & x;
    }

    MpfiClass operator & ( const mpfi_t& b, const MpfiClass& a )
    {
      MpfiClass x(b, mpfi_get_prec(b));
      return a & x;
    }


    MpfiClass & operator &= ( MpfiClass& a, const MpfiClass& b )
    {
      PrecisionType prec = a.GetPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      set_Mpfi(a, a&b, prec);
      return a;
    }

    MpfiClass & operator &= ( MpfiClass& a, const double& b )
    {
      PrecisionType prec = a.GetPrecision();
      if (53 > prec) prec = 53;
      set_Mpfi(a, a&b, prec);
      return a;
    }

//    MpfiClass & operator &= ( MpfiClass& a, const cxsc::real& b )
//    {
//      PrecisionType prec = a.GetPrecision();
//      if (53 > prec) prec = 53;
//      set_Mpfi(a, a&b, prec);
//      return a;
//    }

//    MpfiClass & operator &= ( MpfiClass& a, const cxsc::interval& b )
//    {
//      PrecisionType prec = a.GetPrecision();
//      if (53 > prec) prec = 53;
//      set_Mpfi(a, a&b, prec);
//      return a;
//    }

    MpfiClass & operator &= ( MpfiClass& a, int b )
    {
      PrecisionType prec = a.GetPrecision();
      if (64 > prec) prec = 64;
      set_Mpfi(a, a&b, prec);
      return a;
    }

    MpfiClass & operator &= ( MpfiClass& a, const MPFR::MpfrClass& b )
    {
      PrecisionType prec = a.GetPrecision();
      if (b.GetPrecision() > prec) prec = b.GetPrecision();
      set_Mpfi(a, a&b, prec);
      return a;
    }

    MpfiClass & operator &= ( MpfiClass& a, const mpfr_t& b )
    {
      PrecisionType prec = a.GetPrecision();
      if (mpfr_get_prec(b) > prec) prec = mpfr_get_prec(b);
      set_Mpfi(a, a&b, prec);
      return a;
    }

    MpfiClass & operator &= ( MpfiClass& a, const mpfi_t& b )
    {
      PrecisionType prec = a.GetPrecision();
      if (mpfi_get_prec(b) > prec) prec = mpfi_get_prec(b);
      set_Mpfi(a, a&b, prec);
      return a;
    }

    // Memberfunktionen:  Aufruf  x.SetInterval(a, b);
    // Ein bereits initialisiertes Interval x der Praezision prec wird zu einem
    // Intervall x gleicher Präzision, welches das Intervall [a,b] optimal einschliesst;
    // Ist prec kleiner als M := Max{Paezision(a), Paezision(b)}, so wird x
    // eine Überschaetzung von [a,b], mit [a,b] <= x, d.h. [a,b] enthalten in x.
    // Gilt prec >= M, so gilt x = [a,b]; Dies gilt also insbesondere immer dann, wenn
    // Die Praezisionen von x und M uebereinstimmen, was in der Praxis der Normalfall ist.
    void MpfiClass::SetInterval(const double& a, const double& b)
    {
        mpfi_interv_d(mpfi_rep, a, b);
    }

//    void MpfiClass::SetInterval(const cxsc::real& a, const cxsc::real& b)
//    {
//        mpfi_interv_d( mpfi_rep, cxsc::_double(a), cxsc::_double(b) );
//    }

    void MpfiClass::SetInterval(const int& a, const int& b){

        mpfi_interv_si(mpfi_rep, (long int)a, (long int)b);
    }

    void MpfiClass::SetInterval(const mpfr_t& a, const mpfr_t& b){

        mpfi_interv_fr(mpfi_rep, a, b);
    }

    void MpfiClass::SetInterval(const MPFR::MpfrClass& a, const MPFR::MpfrClass& b)
    {
      mpfi_interv_fr(mpfi_rep, getvalue(a), getvalue(b));
    }

/*------------------------------------------------------*/
/*----------end Operating on Endpoint Functions---------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start Set Functions ------------------------*/
/*------------------------------------------------------*/

  bool MpfiClass::isEmpty()
  // Member function returns 1 if the endpoints of the
  // actual object are in reverse order, zero outherwise
  {
    return mpfi_is_empty(mpfi_rep);
  }

  bool Disjoint (const MpfiClass& a, const MpfiClass& b ) // Test for disjointedness
  {                                                       //------------------------
    return (Inf(a) > Sup(b)) || (Inf(b) > Sup(a));
  }


/*------------------------------------------------------*/
/*----------end Set Functions---------------------------*/
/*------------------------------------------------------*/


/*------------------------------------------------------*/
/*----------start Compare Functions --------------------*/
/*------------------------------------------------------*/


    // Vergleichsfunktionen
    // Liefern -1 wenn w < v, 0 wenn w und v sich ueberlappen, +1 wenn w > v ist
/*
    int compare(const MpfiClass& w, const MpfiClass& v){
        std::cout << "Hallo in compare " << std::endl;
        return mpfi_cmp(w.mpfi_rep, v.mpfi_rep);  // liefert bei Anwendung teils totalen Quatsch!!
    }

    int compare(const MpfiClass& w, const mpfi_t& fi){

        return mpfi_cmp(w.mpfi_rep, fi);
    }

    int compare(const MpfiClass& w, const double& d){

        return mpfi_cmp_d(w.mpfi_rep, d);
    }

    int compare(const MpfiClass& w, const int& i){

        return mpfi_cmp_si(w.mpfi_rep, (long long)i);
    }

    int compare(const MpfiClass& w, const long long& si){

        return mpfi_cmp_si(w.mpfi_rep, si);
    }

    int compare(const MpfiClass& w, const unsigned int& i){

        return mpfi_cmp_ui(w.mpfi_rep, (unsigned long long) i);
    }

    int compare(const MpfiClass& w, const unsigned long long& ui){

        return mpfi_cmp_ui(w.mpfi_rep, ui);
    }


    int compare(const MpfiClass& w, const mpfr_t& fr){

        return mpfi_cmp_fr(w.mpfi_rep, fr);
    }

    int compare(const MpfiClass& w, const MPFR::MpfrClass& f){

        MPFR::MpfrClass fr(f);

        return mpfi_cmp_fr(w.mpfi_rep, fr.GetValue());
    }
*/

/*------------------------------------------------------*/
/*----------end Compare Functions-----------------------*/
/*------------------------------------------------------*/

    // Binaere Ausgabe (geht auch ueber base = 2);
    void print_binary(const MpfiClass& v)
    {
        mpfi_print_binary(v.mpfi_rep);
    }

    // Ausgabe Operator
     std::ostream& operator << (std::ostream& os, const MpfiClass& v)
     {
        // Ausgabe der mpfi-Variablen in der gewuenschten Basis mit cout.precision() Stellen
        mpfi_out_str (stdout , MpfiClass::base, std::cout.precision() , v.mpfi_rep); // Alte Version
        // mpfi_out_str (stdout , MpfiClass::base, MpfiClass::GetCurrPrecision() , v.mpfi_rep); // Versuch
        return os;
     }

    // Eingabe Operator:
    // Der string darf intern keine Leerzeichen enthalten!
    // Das erzeugte MpfiClass-Objekt besitzt die Current-Precision und schliesst
    // den string-Eingabewert garantiert ein.
    std::istream& operator >> (std::istream& is, MpfiClass& v)
    {
      is >> std::ws;

      bool hilf = true;
      char c;
      std::string input;
      // Solange einlesen, bis eof oder ein Leerzeichen erreicht ist
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
            input += c;
      }

      input += "\0";

      PrecisionType prec =  v.GetPrecision();

      if (mpfi_set_str(v.mpfi_rep, const_cast<char *>(input.c_str()), MpfiClass::GetBase()) )
      {
         std::cerr << "Error by string input. Wrong base or wrong string format?" << std::endl;
         exit(1);
      }
      v.RoundPrecision(prec);

      return is;
    } // istream


  bool compare_equal (const MpfiClass& v, const MpfiClass& w)             // Blomquist 25.05.2010
  {
     mpfr_t cmp1, cmp2;
     bool l_endpunkt = false, r_endpunkt = false;
     // Initialisieren mit Precision von v und w
     mpfr_init2(cmp1, v.GetPrecision());
     mpfr_init2(cmp2, w.GetPrecision());
     // Einlesen der linken Endpunkte
     mpfi_get_left(cmp1, v.mpfi_rep);
     mpfi_get_left(cmp2, w.mpfi_rep);
     // Wenn die beiden Linken Endpunkte identisch sind, setzte
     // l_endpunkt auf true
     if (mpfr_equal_p(cmp1,cmp2) != 0) l_endpunkt = true; // Blomquist 25.05.2010

     // Einlesen der rechten Endpunkte
     mpfi_get_right(cmp1, v.mpfi_rep);
     mpfi_get_right(cmp2, w.mpfi_rep);
     // Wenn die beiden rechten Endpunkte identisch sind, setzte
     // r_endpunkt auf true
     if (mpfr_equal_p(cmp1,cmp2) != 0) r_endpunkt = true; // Blomquist 25.05.2010
     // Speicher der beiden mpfr_t Variablen freigeben
     mpfr_clear(cmp1);
     mpfr_clear(cmp2);
     // Wenn beide Endpunkte von v und w identisch sind,
     // geben true zurueck, ansonsten false
     if (l_endpunkt == true && r_endpunkt == true) return true;
     else return false;
  }

  bool compare_less (const MpfiClass& v, const MpfiClass& w)              // Blomquist 26.11.2010
  {
    return mpfi_is_strictly_inside(v.mpfi_rep, w.mpfi_rep);
  }

  bool compare_lessequal (const MpfiClass& v, const MpfiClass& w)         // Blomquist 26.11.2010
  {
     return mpfi_is_inside (v.mpfi_rep, w.mpfi_rep);
  }

/*------------------------------------------------------*/
/*----------start Comparison operators------------------*/
/*------------------------------------------------------*/

    bool operator == (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
      return compare_equal(v,w);
    }

    bool operator == (const double& v, const MpfiClass& w)                 // Blomquist 26.05.2010
    {
      MpfiClass x(v, 53);
      return compare_equal(x,w);
    }

    bool operator == (const int v, const MpfiClass& w)                    // Blomquist 26.05.2010
    {
      MpfiClass x(v, 64);
      return compare_equal(x,w);
    }

//    bool operator == (const cxsc::real& v, const MpfiClass& w)            // Blomquist 26.05.2010
//    {
//      MpfiClass x(v, 53);
//      return compare_equal(x,w);
//    }

    bool operator == (const MpfiClass& v, const double& w)                 // Blomquist 26.05.2010
    {
      MpfiClass x(w, 53);
      return compare_equal(x,v);
    }

    bool operator == (const MpfiClass& v, const int w)                    // Blomquist 26.05.2010
    {
      MpfiClass x(w, 64);
      return compare_equal(x,v);
    }

//    bool operator == (const MpfiClass& v, const cxsc::real& w)                  // Blomquist 26.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_equal(x,v);
//    }

    bool operator == (const MpfiClass& v, const mpfr_t& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, mpfr_get_prec(w)); // x = w, EXAKT!
      return compare_equal(x,v);
    }

    bool operator == (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, mpfi_get_prec(w)); // x = w, EXAKT!
      return compare_equal(x,v);
    }

    bool operator == (const mpfr_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfr_get_prec(v));
      return compare_equal(x,w);
    }

    bool operator == (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfi_get_prec(v));
      return compare_equal(x,w);
    }

    bool operator == (const MpfiClass& v, const MPFR::MpfrClass& w)       // Blomquist 26.05.2010
    {
      MpfiClass x(w, w.GetPrecision());
      return compare_equal(x,v);
    }

    bool operator == (const MPFR::MpfrClass& v, const MpfiClass& w)       // Blomquist 26.05.2010
    {
      MpfiClass x(v, v.GetPrecision());
      return compare_equal(x,w);
    }

//    bool operator == (const cxsc::interval& w, const MpfiClass& v)        // Blomquist 28.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_equal(v,x);
//    }

//    bool operator == (const MpfiClass& v, const cxsc::interval& w)      // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_equal(v,x);
//    }

    bool operator != (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
        return not(v == w);
    }

    bool operator != (const double& v, const MpfiClass& w)                 // Blomquist 26.05.2010
    {
        return not(v == w);
    }

//    bool operator != (const cxsc::real& v, const MpfiClass& w)                 // Blomquist 26.05.2010
//    {
//        return not(v == w);
//    }

    bool operator != (const int v, const MpfiClass& w)                    // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const MpfiClass& v, const double& w)                // Blomquist 26.05.2010
    {
      return not(v == w);
    }

//    bool operator != (const MpfiClass& v, const cxsc::real& w)            // Blomquist 26.05.2010
//    {
//      return not(v == w);
//    }

    bool operator != (const MpfiClass& v, const int w)                    // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const MpfiClass& v, const mpfr_t& w)                // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const MpfiClass& v, const MPFR::MpfrClass& w)       // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const MPFR::MpfrClass& v, const MpfiClass& w)       // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const mpfr_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      return not(v == w);
    }

    bool operator != (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      return not(v == w);
    }

//    bool operator != (const MpfiClass& v, const cxsc::interval& w)      // Blomquist 27.05.2010
//    {
//      return not(v == w);
//    }

//    bool operator != (const cxsc::interval& w, const MpfiClass& v)        // Blomquist 27.05.2010
//    {
//      return not(v == w);
//    }

    bool operator <  (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
      return compare_less(v,w);
    }

    bool operator <  (const double& v, const MpfiClass& w)                 // Blomquist 26.05.2010
    {
      MpfiClass x(v, 53);
      return compare_less(x,w);
    }

    bool operator <  (const int v, const MpfiClass& w)                    // Blomquist 26.05.2010
    {
      MpfiClass x(v, 64);
      return compare_less(x,w);
    }

    bool operator <  (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, mpfi_get_prec(w));
      return compare_less(v,x);
    }

    bool operator <  (const mpfr_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfr_get_prec(v));
      return compare_less(x,w);
    }

    bool operator <  (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfi_get_prec(v));
      return compare_less(x,w);
    }

    bool operator <  (const MPFR::MpfrClass& v, const MpfiClass& w)       // Blomquist 26.05.2010
    {
      MpfiClass x(v, v.GetPrecision());
      return compare_less(x,w);
    }

//    bool operator < (const MpfiClass& v, const cxsc::interval& w)        // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_less(v,x);
//    }

//    bool operator < (const cxsc::interval& w, const MpfiClass& v)        // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_less(x,v);
//    }

//    bool operator < (const cxsc::real& w, const MpfiClass& v)             // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_less(x,v);
//    }

    bool operator <= (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
      return compare_lessequal(v,w);
    }

    bool operator <= (const double& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, 53);
      return compare_lessequal(x,w);
    }

    bool operator <= (const int v, const MpfiClass& w)                    // Blomquist 26.05.2010
    {
      MpfiClass x(v, 64);
      return compare_lessequal(x,w);
    }

    bool operator <= (const MpfiClass& v, const double& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, 53);
      return compare_lessequal(v,x);
    }

    bool operator <= (const MpfiClass& v, const int w)                    // Blomquist 26.05.2010
    {
      MpfiClass x(w, 64);
      return compare_lessequal(v,x);
    }

    bool operator <= (const MpfiClass& v, const mpfr_t& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, mpfr_get_prec(w));
      return compare_lessequal(v,x);
    }

    bool operator <= (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(w, mpfi_get_prec(w));
      return compare_lessequal(v,x);
    }

    bool operator <= (const mpfr_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfr_get_prec(v));
      return compare_lessequal(x,w);
    }

    bool operator <= (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      MpfiClass x(v, mpfi_get_prec(v));
      return compare_lessequal(x,w);
    }

    bool operator <= (const MpfiClass& v, const MPFR::MpfrClass& w)       // Blomquist 26.05.2010
    {
      MpfiClass x(w, w.GetPrecision());
      return compare_lessequal(v,x);
    }

    bool operator <= (const MPFR::MpfrClass& v, const MpfiClass& w)       // Blomquist 26.05.2010
    {
      MpfiClass x(v, v.GetPrecision());
      return compare_lessequal(x,w);
    }

//    bool operator <= (const cxsc::interval& w, const MpfiClass& v)        // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_lessequal(x,v);
//    }

//    bool operator <= (const MpfiClass& v, const cxsc::interval& w)        // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_lessequal(v,x);
//    }

//    bool operator <= (const MpfiClass& v, const cxsc::real& w)           // Blomquist 24.11.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_lessequal(v,x);
//    }

//    bool operator <= (const cxsc::real& w, const MpfiClass& v)            // Blomquist 27.05.2010
//    {
//      MpfiClass x(w, 53);
//      return compare_lessequal(x,v);
//    }

    bool operator >  (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const MpfiClass& v, const double& w)                // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const MpfiClass& v, const int w)                    // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const MpfiClass& v, const mpfr_t& w)                // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
      return (w < v);
    }

    bool operator >  (const MpfiClass& v, const MPFR::MpfrClass& w)       // Blomquist 26.05.2010
    {
      return (w < v);
    }

//    bool operator > (const MpfiClass& v, const cxsc::interval& w)         // Blomquist 27.05.2010
//    {
//      return (w < v);
//    }

//    bool operator > (const cxsc::interval& w, const MpfiClass& v)         // Blomquist 27.05.2010
//    {
//      return (v < w);
//    }

//    bool operator > (const MpfiClass& v, const cxsc::real& w)             // Blomquist 27.05.2010
//    {
//      return (w < v);
//    }

    bool operator >= (const MpfiClass& v, const MpfiClass& w)             // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const double& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
        return (w <= v);
    }

//    bool operator >= (const cxsc::real& v, const MpfiClass& w)            // Blomquist 24.11.2010
//    {
//        return (w <= v);
//    }

    bool operator >= (const int v, const MpfiClass& w)                    // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MpfiClass& v, const double& w)                // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MpfiClass& v, const int w)                    // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MpfiClass& v, const mpfr_t& w)                // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MpfiClass& v, const mpfi_t& w)                // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const mpfi_t& v, const MpfiClass& w)                // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MpfiClass& v, const MPFR::MpfrClass& w)       // Blomquist 26.05.2010
    {
        return (w <= v);
    }

    bool operator >= (const MPFR::MpfrClass& v, const MpfiClass& w)       // Blomquist 26.05.2010
    {
        return (w <= v);
    }

//    bool operator >= (const MpfiClass& v, const cxsc::interval& w)        // Blomquist 27.05.2010
//    {
//      return (w <= v);
//    }

//    bool operator >= (const cxsc::interval& w, const MpfiClass& v)        // Blomquist 27.05.2010
//    {
//      return (v <= w);
//    }

//    bool operator >= (const MpfiClass& v, const cxsc::real& w)            // Blomquist 27.05.2010
//    {
//      return (w <= v);
//    }

/*------------------------------------------------------*/
/*----------end Comparison operators--------------------*/
/*------------------------------------------------------*/

/*------------------------------------------------------*/
/*---------- start Funktionen---------------------------*/
/*------------------------------------------------------*/


    // Ausgabe Operator fuer mpfi_t Variablen
    std::ostream& operator << (std::ostream& os, mpfi_t& v)
    {
        mpfi_out_str (stdout , MpfiClass::GetBase(), std::cout.precision() , v);
        return os;
    }

    // The function void random(...) delivers a MpfiClass random interval r with endpoints in [0,1]
    // by the following instructions inside a function, for example in: int main(void);
    // 1.   gmp_randstate_t state;  (Declaration of variable state)
    // 2.   initialization (state); (Initialization of state)
    // 3.   MpfiClass r;            (Declaration of interval class object r)
    // 4.   random (r, state);      (Function call delivers the first random interval r)
    // 5.   random (r, state);      (Function call delivers the second random interval r) ...
    void random(MpfiClass& v, gmp_randstate_t state)
    {
        mpfr_t lw, rw;

        mpfr_init2(lw, v.GetPrecision());
        mpfr_init2(rw, v.GetPrecision());
        mpfr_urandomb(lw, state);
        mpfr_urandomb(rw, state);

        v.SetInterval(lw,rw);
        // swap endpoints if necessary to get a regular interval
        v.swap_endpoints();

        mpfr_clear(lw);
        mpfr_clear(rw);
    }

    int common_decimals (const MpfiClass& x)  // Kraemer, Blomquist 25.06.2010
    {
      // Calculating the correct decimals of the inclusion x
      mpfr_t l,r;
      long int k(0);

      mpfr_init2(l,x.GetPrecision());
      mpfi_get_left(l, x.mpfi_rep);    // l = Inf(x)
      mpfr_init2(r,x.GetPrecision());
      mpfi_get_right(r, x.mpfi_rep);   // r = Sup(x)

      if ( mpfr_number_p (l) != 0 && mpfr_number_p (r) != 0 )
      { // Inf(x) and Sup(x) are defined floating-point numbers
        if (RelDiam(x) == 0.0) k = (long int) floor(x.GetPrecision()/3.321928094887362);
        else
        {
          k = (0<=x)? 0 : -get_diam_exp(x);
          if (k<0) k = 0;
        }
      }
      mpfr_clear(l);  mpfr_clear(r);
      return k;
    }

/*------------------------------------------------------*/
/*---------- End Funktionen-----------------------------*/
/*------------------------------------------------------*/

  std::string to_string (const MpfiClass& t, PrecisionType prec)
  {
    return "[" + to_string(Inf(t),RoundDown,prec) + ", " + to_string(Sup(t),RoundUp,prec) + "]";
  }


/*------------------------------------------------------*/
/*----------start C-XSC Functions-----------------------*/
/*------------------------------------------------------*/

    MpfiClass string2Mpfi (const std::string& s, const PrecisionType prec)
    {
      MpfiClass res(s, prec);
      return res;
    }

//    MpfiClass real2Mpfi(const cxsc::real& v)  // Blomquist 28.09.2010
//    {
//      MpfiClass res(0, 53);  // Liefert Punktintervall res;
//      mpfi_set_d(res.mpfi_rep, _double(v));
//      return res;
//    }

    MpfiClass double2Mpfi(const double& v)  // Blomquist 28.09.2010
    {
      MpfiClass res(0, 53);  // Liefert Punktintervall res;
      mpfi_set_d(res.mpfi_rep, v);
      return res;
    }

//    MpfiClass interval2Mpfi(const cxsc::interval& v)
//    {
//      MpfiClass res(0, 53);
//      mpfi_interv_d (res.mpfi_rep, _double(Inf(v)), _double(Sup(v)));
//      return res;
//    }

    MpfiClass int2Mpfi(const int v)
    {
      MpfiClass res(0, 64);  // Liefert Punktintervall res mit v;
      mpfi_set_si(res.mpfi_rep, (long int)v);
      return res;
    }

    MpfiClass MpfrClass2Mpfi(const MPFR::MpfrClass& v)
    {
      MpfiClass res(0, v.GetPrecision());  // Liefert Punktintervall res mit v;
      mpfi_set_fr(res.mpfi_rep, getvalue(v));
      return res;
    }

    MpfiClass mpfr_t2Mpfi(const mpfr_t& v)
    {
      MpfiClass res(0, mpfr_get_prec(v));  // Liefert Punktintervall res mit v;
      mpfi_set_fr(res.mpfi_rep, v);
      return res;
    }

    MpfiClass mpfi_t2Mpfi(const mpfi_t& v)
    {
      MpfiClass res(v, mpfi_get_prec(v));  // Liefert Intervall res mit res = v;
      return res;
    }

//    cxsc::interval to_interval(const MpfiClass& v)  // Blomquist 03.10.2010
//    {
//      return cxsc::interval(to_real(Inf(v,53), RoundDown), to_real(Sup(v,53), RoundUp));
//    }

    // Umwandlung einer Hexadezimalzahl in eine Dezimalzahl
    int HexToDez(const char& c)
    {
        switch(c){
            case('0'): return 0; break;
            case('1'): return 1; break;
            case('2'): return 2; break;
            case('3'): return 3; break;
            case('4'): return 4; break;
            case('5'): return 5; break;
            case('6'): return 6; break;
            case('7'): return 7; break;
            case('8'): return 8; break;
            case('9'): return 9; break;
            case('A'): return 10; break;
            case('B'): return 11; break;
            case('C'): return 12; break;
            case('D'): return 13; break;
            case('E'): return 14; break;
            case('F'): return 15; break;
            default:   return -1;  break;
        }
    }

    // Umwandlung einer Hexadezimalzahl in eine Binaerzahl
    std::string HexToBin(const char& c)
    {
        switch(c){
            case('0'): return "0000"; break;
            case('1'): return "0001"; break;
            case('2'): return "0010"; break;
            case('3'): return "0011"; break;
            case('4'): return "0100"; break;
            case('5'): return "0101"; break;
            case('6'): return "0110"; break;
            case('7'): return "0111"; break;
            case('8'): return "1000"; break;
            case('9'): return "1001"; break;
            case('A'): return "1010"; break;
            case('B'): return "1011"; break;
            case('C'): return "1100"; break;
            case('D'): return "1101"; break;
            case('E'): return "1110"; break;
            case('F'): return "1111"; break;
            default:   return "xxxx";  break;
        }
    }

    // Umwandlung eines hexadezimalen Strings in einen binaeren String
    std::string tobinaer(std::string zahl, std::string exp)
    {
        std::stringstream res;
        // Einlesen des Vorzeichens
        res << zahl[0];

        // Berechnen des Exponenten
        int e = HexToDez(exp[0])*256 + HexToDez(exp[1])*16 + HexToDez(exp[2]) - 1023;

        // Pruefe ob die Zahl Unendlich oder NaN ist
        if(exp == "7FF" || exp == "000"){
            // Wenn der Exponent "7FF" ist, ist die Zahl Unendlich
            if(exp == "7FF"){
                res << "@Inf@";
            }
            // Wenn der Exponent "000" ist, pruefe ob es eine denormalisierte Zahl ist oder ob es sich um die 0 handelt
            else if(exp == "000"){
                bool denormalisiert = false;
                //Wenn das erste Zeichen nicht 1 ist, ist es eine Denormalisierte Zahl
                if(zahl[1] != '1') denormalisiert = true;
                //Wenn andere Zeichen als nullen in der Mantisse stehen, ist es eine Denormalisierte Zahl
                for(int i = 2; i <  (int) zahl.length(); i++){
                        if(zahl[i] != '0') denormalisiert = true;
                    }
                //Wenn es eine Denormalisierte Zahl ist, wird der Ergebniss String auf NaN gesetzt,
                //ansonsten auf 0.0
                if(denormalisiert == false) res << "0.0";
                else{
                    res.str("@NaN@");
                }
            }
        }
        else{
            // Umwandlung der Hexadezimal-Werte in Binaer Werte
            for(int i = 1; i <  (int) zahl.length(); i++){
                // An der zweiten Stelle wird ein Punkt eingefuegt
                if(i==2) res << '.';
                // Umwandlung der Zahl in einen Binaeren String
                res << HexToBin(zahl[i]);
            }
            // Anfuegen des Exponenten
            res << "e" << e;
        }
        return res.str();
    }

  void Interval_Scaling(MpfiClass& z, long int& k)
  // With the input value z=a the two output values z=A and k are calculated.
  // A = a*2^ (-k) is calculated in order to avoid an overflow by calculating 2*A*A.
  {
    long int p;
    k = 0;
    if (isBounded(z))
    {
      if (!isZero(z))
      {
        k = expo(Inf(z));
        p = expo(Sup(z));
        if (p>k) k = p;
        k = 536870910 - k;
        mpfi_mul_2si(z.mpfi_rep, z.mpfi_rep, k);
        k = -k;
      }
    }
    else set_nan(z);
  }

  MpfiClass scal_prod(const MpfiClass& a, const MpfiClass& b,
                      const MpfiClass& c, const MpfiClass& d)
  {
    PrecisionType prec_old = MPFI::MpfiClass::GetCurrPrecision(),
                  prec = a.GetPrecision();
    if (b.GetPrecision() > prec) prec = b.GetPrecision();
    if (c.GetPrecision() > prec) prec = c.GetPrecision();
    if (d.GetPrecision() > prec) prec = d.GetPrecision();
    if (prec<MPFI::MpfiClass::GetCurrPrecision())
      prec = MPFI::MpfiClass::GetCurrPrecision();
    MPFI::MpfiClass::SetCurrPrecision(2*prec);

    long int kA, kB, kC;
    MpfiClass A(a), B(b), C;

    Interval_Scaling(A, kA);
    Interval_Scaling(B, kB);
    // Berechnung von a*b:
    kA = kA + kB;
    A = A*B;
    // Berechnung von c*d:
    B = c;  C = d;
    Interval_Scaling(B, kB);
    Interval_Scaling(C, kC);
    kB = kB + kC;
    B = B*C;
    // Jetzt folgt die Addition der Produkte A+B:
    // Vorher muss auf den groessten Exponenten skaliert werden;
    if (kA>=kB)
      times2pown(B, kB-kA);
    else
    {
      times2pown(A, kA-kB);
      kA = kB;
    }
    // Jetzt ist kA der groessere Exponent:
    A = A + B;
    times2pown(A,kA); // erst hier kann Overflow auftreten!
    A.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);
    return A;
  }

// ------ Functions for calculating an optimal komplex interval division ---------

  void P_Interval_Scaling(MpfiClass& z, long int& k)
  // With the input POINT interval z=a the two output values z=A and k are calculated.
  // A = a*2^ (-k) is calculated in order to avoid an overflow by calculating 2*A*A.
  {
    k = 0;
    if (isBounded(z))
    {
      if (!isZero(z))
      {
        k = 536870910 - expo(Inf(z));
        mpfi_mul_2si(z.mpfi_rep, z.mpfi_rep, k);
        k = -k;
      }
    }
    else set_nan(z);
  }


  static const int maxexpo1 = 1073741823;  // Zweier-Exponent von MaxFloat()

  MpfiClass product (const MPFR::MpfrClass& a, const MPFR::MpfrClass& b,
                     const MPFR::MpfrClass& c, const MPFR::MpfrClass& d,
                     long int& k)
  {
//    long int kA, kB, kC;

    long int kB, kC;

    MpfiClass A(a), B(b), C;

    P_Interval_Scaling(A, k);
    P_Interval_Scaling(B, kB);
    // Berechnung von a*b:
    k = k + kB;
    A = A*B;
    // Berechnung von c*d:
    B = c;  C = d;
    P_Interval_Scaling(B, kB);
    P_Interval_Scaling(C, kC);
    kB = kB + kC;
    B = B*C;
    // Jetzt folgt die Addition der Produkte A+B:
    // Vorher muss auf den groessten Exponenten skaliert werden;
    if (k>=kB)
      times2pown(B, kB-k);
    else
    {
      times2pown(A, k-kB);
      k = kB;
    }
    // Jetzt ist kA der groessere Exponent:
    return A+B;
  } // End product()

  MPFR::MpfrClass quotient (const MpfiClass& z, const long int kz,
                            const MpfiClass& n, const long int kn, const int rnd)
  {
    PrecisionType prec_old = MPFI::MpfiClass::GetCurrPrecision(),
                  prec = z.GetPrecision();
    MPFI::MpfiClass::SetCurrPrecision(prec); // z,n wurden in doppelter Präzision berechnet;
    MpfiClass q;

    q = z / n;
    times2pown(q, kz-kn);
    q.RoundPrecision(prec_old);
    MPFI::MpfiClass::SetCurrPrecision(prec_old);

    switch(rnd)
    {
      case -1: return Inf(q);
      case 0 : return mid(q);
      case 1 : return Sup(q);
      default: return mid(q);
    }
  }

/*------------------------------------------------------*/
/*----------end C-XSC Functions-------------------------*/
/*------------------------------------------------------*/

}
