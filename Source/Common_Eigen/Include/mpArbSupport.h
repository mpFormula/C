// This file is part of a joint effort between Eigen, a lightweight C++ template library
// for linear algebra, and mparb C++, a C++ interface to mparb library (http://www.holoborodko.com/pavel/)
//
// Copyright (C) 2010-2012 Pavel Holoborodko <pavel@holoborodko.com>
// Copyright (C) 2010 Konstantin Holoborodko <konstantin@holoborodko.com>
// Copyright (C) 2010 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_MPARBSUPPORT_MODULE_H
#define EIGEN_MPARBSUPPORT_MODULE_H

#include <Eigen/Core>
#include <mpArb.h>

namespace Eigen {

  template<> struct NumTraits<mparb::mpArb>
    : GenericNumTraits<mparb::mpArb>
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

    typedef mparb::mpArb Real;
    typedef mparb::mpArb NonInteger;

    inline static Real highest   (long Precision = mparb::mpArb::get_default_prec())  { return  mparb::maxval(Precision); }
    inline static Real lowest    (long Precision = mparb::mpArb::get_default_prec())  { return -mparb::maxval(Precision); }

    // Constants
    inline static Real Pi       (long Precision = mparb::mpArb::get_default_prec())     {    return mparb::const_pi(Precision);        }
    inline static Real Euler    (long Precision = mparb::mpArb::get_default_prec())     {    return mparb::const_euler(Precision);     }
    inline static Real Log2     (long Precision = mparb::mpArb::get_default_prec())     {    return mparb::const_log2(Precision);      }
    inline static Real Catalan  (long Precision = mparb::mpArb::get_default_prec())     {    return mparb::const_catalan(Precision);   }

    inline static Real epsilon  (long Precision = mparb::mpArb::get_default_prec())     {    return mparb::machine_epsilon(Precision); }
    inline static Real epsilon  (const Real& x)                                         {    return mparb::machine_epsilon(x); }

    inline static Real dummy_precision()
    {
        unsigned int weak_prec = ((mparb::mpArb::get_default_prec()-1) * 90) / 100;
        return mparb::machine_epsilon(weak_prec);
    }
  };

  namespace internal {

  template<> inline mparb::mpArb random<mparb::mpArb>()
  {
    return mparb::random();
  }

  template<> inline mparb::mpArb random<mparb::mpArb>(const mparb::mpArb& a, const mparb::mpArb& b)
  {
    return a + (b-a) * random<mparb::mpArb>();
  }

  inline bool isMuchSmallerThan(const mparb::mpArb& a, const mparb::mpArb& b, const mparb::mpArb& eps)
  {
    return mparb::abs(a) <= mparb::abs(b) * eps;
  }

  inline bool isApprox(const mparb::mpArb& a, const mparb::mpArb& b, const mparb::mpArb& eps)
  {
    return mparb::isEqualFuzzy(a,b,eps);
  }

  inline bool isApproxOrLessThan(const mparb::mpArb& a, const mparb::mpArb& b, const mparb::mpArb& eps)
  {
    return a <= b || mparb::isEqualFuzzy(a,b,eps);
  }

  template<> inline long double cast<mparb::mpArb,long double>(const mparb::mpArb& x)
  { return x.toLDouble(); }

  template<> inline double cast<mparb::mpArb,double>(const mparb::mpArb& x)
  { return x.toDouble(); }

  template<> inline long cast<mparb::mpArb,long>(const mparb::mpArb& x)
  { return x.toLong(); }

  template<> inline int cast<mparb::mpArb,int>(const mparb::mpArb& x)
  { return int(x.toLong()); }

  // Specialize GEBP kernel and traits for mpArb (no need for peeling, nor complicated stuff)
  // This also permits to directly call mparb's routines and avoid many temporaries produced by mpArb
    template<>
    class gebp_traits<mparb::mpArb, mparb::mpArb, false, false>
    {
    public:
      typedef mparb::mpArb ResScalar;
      enum {
        nr = 2, // must be 2 for proper packing...
        mr = 1,
        WorkSpaceFactor = nr,
        LhsProgress = 1,
        RhsProgress = 1
      };
    };

    template<typename Index, int mr, int nr, bool ConjugateLhs, bool ConjugateRhs>
    struct gebp_kernel<mparb::mpArb,mparb::mpArb,Index,mr,nr,ConjugateLhs,ConjugateRhs>
    {
      typedef mparb::mpArb mpArb;

      EIGEN_DONT_INLINE
      void operator()(mpArb* res, Index resStride, const mpArb* blockA, const mpArb* blockB, Index rows, Index depth, Index cols, mpArb alpha,
                      Index strideA=-1, Index strideB=-1, Index offsetA=0, Index offsetB=0, mpArb* /*unpackedB*/ = 0)
      {
        mpArb acc1, acc2, tmp;

        if(strideA==-1) strideA = depth;
        if(strideB==-1) strideB = depth;

        for(Index j=0; j<cols; j+=nr)
        {
          Index actual_nr = (std::min<Index>)(nr,cols-j);
          mpArb *C1 = res + j*resStride;
          mpArb *C2 = res + (j+1)*resStride;
          for(Index i=0; i<rows; i++)
          {
            mpArb *B = const_cast<mpArb*>(blockB) + j*strideB + offsetB*actual_nr;
            mpArb *A = const_cast<mpArb*>(blockA) + i*strideA + offsetA;
            acc1 = 0;
            acc2 = 0;
            for(Index k=0; k<depth; k++)
            {
              arb_mul(tmp.arb_ptr(), A[k].arb_ptr(), B[0].arb_ptr(), mpfr_get_default_prec());
              arb_add(acc1.arb_ptr(), acc1.arb_ptr(), tmp.arb_ptr(), mpfr_get_default_prec());

              if(actual_nr==2) {
                arb_mul(tmp.arb_ptr(), A[k].arb_ptr(), B[1].arb_ptr(), mpfr_get_default_prec());
                arb_add(acc2.arb_ptr(), acc2.arb_ptr(), tmp.arb_ptr(), mpfr_get_default_prec());
              }

              B+=actual_nr;
            }

            arb_mul(acc1.arb_ptr(), acc1.arb_ptr(), alpha.arb_ptr(), mpfr_get_default_prec());
            arb_add(C1[i].arb_ptr(), C1[i].arb_ptr(), acc1.arb_ptr(), mpfr_get_default_prec());

            if(actual_nr==2) {
              arb_mul(acc2.arb_ptr(), acc2.arb_ptr(), alpha.arb_ptr(), mpfr_get_default_prec());
              arb_add(C2[i].arb_ptr(), C2[i].arb_ptr(), acc2.arb_ptr(), mpfr_get_default_prec());
            }
          }
        }
      }
    };

  } // end namespace internal
}

#endif // EIGEN_MPARBSUPPORT_MODULE_H
