// This file is part of a joint effort between Eigen, a lightweight C++ template library
// for linear algebra, and MPFR C++, a C++ interface to MPFR library (http://www.holoborodko.com/pavel/)
//
// Copyright (C) 2010-2012 Pavel Holoborodko <pavel@holoborodko.com>
// Copyright (C) 2010 Konstantin Holoborodko <konstantin@holoborodko.com>
// Copyright (C) 2010 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_MPREALDECIMALSUPPORT_MODULE_H
#define EIGEN_MPREALDECIMALSUPPORT_MODULE_H

#include <Eigen/Core>
#include <mpRealDecimal.h>

namespace Eigen {

  template<> struct NumTraits<mpDec::mpdec_class>
    : GenericNumTraits<mpDec::mpdec_class>
  {
    enum {
      IsInteger = 0,
      IsSigned = 1,
      IsComplex = 0,
      RequireInitialization = 1,
      ReadCost = 10,
      AddCost = 10,
      MulCost = 40
    };

    typedef mpDec::mpdec_class Real;
    typedef mpDec::mpdec_class NonInteger;

    inline static Real highest   (long Precision = mpDec::mpdec_class::get_default_prec())  { return  mpDec::maxval(Precision); }
    inline static Real lowest    (long Precision = mpDec::mpdec_class::get_default_prec())  { return -mpDec::maxval(Precision); }

    // Constants
    inline static Real Pi       ()     {    return mpDec::const_pi();        }
    inline static Real Euler    ()     {    return mpDec::const_euler();     }
    inline static Real Log2     ()     {    return mpDec::const_log2();      }
    inline static Real Catalan  ()     {    return mpDec::const_catalan();   }

    inline static Real epsilon  (long Precision = mpDec::mpdec_class::get_default_prec())     {    return mpDec::machine_epsilon(Precision); }

    inline static Real epsilon  (const Real& x)                                         {    return mpDec::machine_epsilon(x); }

    inline static Real dummy_precision()
    {
        size_t weak_prec = ((mpDec::mpdec_class::get_default_prec()-1) * 90) / 100;
        return mpDec::machine_epsilon(weak_prec);
    }
  };

  namespace internal {

  template<> inline mpDec::mpdec_class random<mpDec::mpdec_class>()
  {
    return mpDec::random();
  }

  template<> inline mpDec::mpdec_class random<mpDec::mpdec_class>(const mpDec::mpdec_class& a, const mpDec::mpdec_class& b)
  {
    return a + (b-a) * random<mpDec::mpdec_class>();
  }

  inline bool isMuchSmallerThan(const mpDec::mpdec_class& a, const mpDec::mpdec_class& b, const mpDec::mpdec_class& eps)
  {
    return mpDec::abs(a) <= mpDec::abs(b) * eps;
  }

  inline bool isApprox(const mpDec::mpdec_class& a, const mpDec::mpdec_class& b, const mpDec::mpdec_class& eps)
  {
    return mpDec::isEqualFuzzy(a,b,eps);
  }

  inline bool isApproxOrLessThan(const mpDec::mpdec_class& a, const mpDec::mpdec_class& b, const mpDec::mpdec_class& eps)
  {
    return a <= b || mpDec::isEqualFuzzy(a,b,eps);
  }

  //template<> inline long double cast<mpDec::mpdec_class,long double>(const mpDec::mpdec_class& x)
  //{ return x.toLDouble(); }

  template<> inline double cast<mpDec::mpdec_class,double>(const mpDec::mpdec_class& x)
  { return x.toDouble(); }

  template<> inline long cast<mpDec::mpdec_class,long>(const mpDec::mpdec_class& x)
  { return x.toLong(); }

  template<> inline int cast<mpDec::mpdec_class,int>(const mpDec::mpdec_class& x)
  { return int(x.toLong()); }

  // Specialize GEBP kernel and traits for mpreal (no need for peeling, nor complicated stuff)
  // This also permits to directly call mpfr's routines and avoid many temporaries produced by mpreal
    template<>
    class gebp_traits<mpDec::mpdec_class, mpDec::mpdec_class, false, false>
    {
    public:
      typedef mpDec::mpdec_class ResScalar;
      enum {
        nr = 2, // must be 2 for proper packing...
        mr = 1,
        WorkSpaceFactor = nr,
        LhsProgress = 1,
        RhsProgress = 1
      };
    };

    template<typename Index, int mr, int nr, bool ConjugateLhs, bool ConjugateRhs>
    struct gebp_kernel<mpDec::mpdec_class,mpDec::mpdec_class,Index,mr,nr,ConjugateLhs,ConjugateRhs>
    {
      typedef mpDec::mpdec_class mpdec_class;

      EIGEN_DONT_INLINE
      void operator()(mpdec_class* res, Index resStride, const mpdec_class* blockA, const mpdec_class* blockB, Index rows, Index depth, Index cols, mpdec_class alpha,
                      Index strideA=-1, Index strideB=-1, Index offsetA=0, Index offsetB=0, mpdec_class* /*unpackedB*/ = 0)
      {
        mpdec_class acc1, acc2, tmp;

        if(strideA==-1) strideA = depth;
        if(strideB==-1) strideB = depth;

        for(Index j=0; j<cols; j+=nr)
        {
          Index actual_nr = (std::min<Index>)(nr,cols-j);
          mpdec_class *C1 = res + j*resStride;
          mpdec_class *C2 = res + (j+1)*resStride;
          for(Index i=0; i<rows; i++)
          {
            mpdec_class *B = const_cast<mpdec_class*>(blockB) + j*strideB + offsetB*actual_nr;
            mpdec_class *A = const_cast<mpdec_class*>(blockA) + i*strideA + offsetA;
            acc1 = 0;
            acc2 = 0;
            for(Index k=0; k<depth; k++)
            {
              mpd_mul(tmp.mpd_ptr(), A[k].mpd_ptr(), B[0].mpd_ptr(), mpdec_class::GetContext());
              mpd_add(acc1.mpd_ptr(), acc1.mpd_ptr(), tmp.mpd_ptr(),  mpdec_class::GetContext());

              if(actual_nr==2) {
                mpd_mul(tmp.mpd_ptr(), A[k].mpd_ptr(), B[1].mpd_ptr(), mpdec_class::GetContext());
                mpd_add(acc2.mpd_ptr(), acc2.mpd_ptr(), tmp.mpd_ptr(),  mpdec_class::GetContext());
              }

              B+=actual_nr;
            }

            mpd_mul(acc1.mpd_ptr(), acc1.mpd_ptr(), alpha.mpd_ptr(), mpdec_class::GetContext());
            mpd_add(C1[i].mpd_ptr(), C1[i].mpd_ptr(), acc1.mpd_ptr(),  mpdec_class::GetContext());

            if(actual_nr==2) {
              mpd_mul(acc2.mpd_ptr(), acc2.mpd_ptr(), alpha.mpd_ptr(), mpdec_class::GetContext());
              mpd_add(C2[i].mpd_ptr(), C2[i].mpd_ptr(), acc2.mpd_ptr(),  mpdec_class::GetContext());
            }
          }
        }
      }
    };

  } // end namespace internal
}

#endif // EIGEN_MPREALDECIMALSUPPORT_MODULE_H
