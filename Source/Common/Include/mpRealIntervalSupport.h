// This file is part of a joint effort between Eigen, a lightweight C++ template library
// for linear algebra, and mpfi C++, a C++ interface to mpfi library (http://www.holoborodko.com/pavel/)
//
// Copyright (C) 2010-2012 Pavel Holoborodko <pavel@holoborodko.com>
// Copyright (C) 2010 Konstantin Holoborodko <konstantin@holoborodko.com>
// Copyright (C) 2010 Gael Guennebaud <gael.guennebaud@inria.fr>
//
// This Source Code Form is subject to the terms of the Mozilla
// Public License v. 2.0. If a copy of the MPL was not distributed
// with this file, You can obtain one at http://mozilla.org/MPL/2.0/.

#ifndef EIGEN_MPREALINTERVALSUPPORT_MODULE_H
#define EIGEN_MPREALINTERVALSUPPORT_MODULE_H

#include <Eigen/Core>
#include <mpRealInterval.h>

namespace Eigen {

  template<> struct NumTraits<mpfi::mpRealInterval>
    : GenericNumTraits<mpfi::mpRealInterval>
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

    typedef mpfi::mpRealInterval Real;
    typedef mpfi::mpRealInterval NonInteger;

    inline static Real highest   (long Precision = mpfi::mpRealInterval::get_default_prec())  { return  mpfi::maxval(Precision); }
    inline static Real lowest    (long Precision = mpfi::mpRealInterval::get_default_prec())  { return -mpfi::maxval(Precision); }

    // Constants
    inline static Real Pi       (long Precision = mpfi::mpRealInterval::get_default_prec())     {    return mpfi::const_pi(Precision);        }
    inline static Real Euler    (long Precision = mpfi::mpRealInterval::get_default_prec())     {    return mpfi::const_euler(Precision);     }
    inline static Real Log2     (long Precision = mpfi::mpRealInterval::get_default_prec())     {    return mpfi::const_log2(Precision);      }
    inline static Real Catalan  (long Precision = mpfi::mpRealInterval::get_default_prec())     {    return mpfi::const_catalan(Precision);   }

    inline static Real epsilon  (long Precision = mpfi::mpRealInterval::get_default_prec())     {    return mpfi::machine_epsilon(Precision); }
    inline static Real epsilon  (const Real& x)                                         {    return mpfi::machine_epsilon(x); }

    inline static Real dummy_precision()
    {
        unsigned int weak_prec = ((mpfi::mpRealInterval::get_default_prec()-1) * 90) / 100;
        return mpfi::machine_epsilon(weak_prec);
    }
  };

  namespace internal {

  template<> inline mpfi::mpRealInterval random<mpfi::mpRealInterval>()
  {
    return mpfi::random();
  }

  template<> inline mpfi::mpRealInterval random<mpfi::mpRealInterval>(const mpfi::mpRealInterval& a, const mpfi::mpRealInterval& b)
  {
    return a + (b-a) * random<mpfi::mpRealInterval>();
  }

  inline bool isMuchSmallerThan(const mpfi::mpRealInterval& a, const mpfi::mpRealInterval& b, const mpfi::mpRealInterval& eps)
  {
    return mpfi::abs(a) <= mpfi::abs(b) * eps;
  }

  inline bool isApprox(const mpfi::mpRealInterval& a, const mpfi::mpRealInterval& b, const mpfi::mpRealInterval& eps)
  {
    return mpfi::isEqualFuzzy(a,b,eps);
  }

  inline bool isApproxOrLessThan(const mpfi::mpRealInterval& a, const mpfi::mpRealInterval& b, const mpfi::mpRealInterval& eps)
  {
    return a <= b || mpfi::isEqualFuzzy(a,b,eps);
  }

  template<> inline long double cast<mpfi::mpRealInterval,long double>(const mpfi::mpRealInterval& x)
  { return x.toLDouble(); }

  template<> inline double cast<mpfi::mpRealInterval,double>(const mpfi::mpRealInterval& x)
  { return x.toDouble(); }

  template<> inline long cast<mpfi::mpRealInterval,long>(const mpfi::mpRealInterval& x)
  { return x.toLong(); }

  template<> inline int cast<mpfi::mpRealInterval,int>(const mpfi::mpRealInterval& x)
  { return int(x.toLong()); }

  // Specialize GEBP kernel and traits for mpRealInterval (no need for peeling, nor complicated stuff)
  // This also permits to directly call mpfi's routines and avoid many temporaries produced by mpRealInterval
    template<>
    class gebp_traits<mpfi::mpRealInterval, mpfi::mpRealInterval, false, false>
    {
    public:
      typedef mpfi::mpRealInterval ResScalar;
      enum {
        nr = 2, // must be 2 for proper packing...
        mr = 1,
        WorkSpaceFactor = nr,
        LhsProgress = 1,
        RhsProgress = 1
      };
    };

    template<typename Index, int mr, int nr, bool ConjugateLhs, bool ConjugateRhs>
    struct gebp_kernel<mpfi::mpRealInterval,mpfi::mpRealInterval,Index,mr,nr,ConjugateLhs,ConjugateRhs>
    {
      typedef mpfi::mpRealInterval mpRealInterval;

      EIGEN_DONT_INLINE
      void operator()(mpRealInterval* res, Index resStride, const mpRealInterval* blockA, const mpRealInterval* blockB, Index rows, Index depth, Index cols, mpRealInterval alpha,
                      Index strideA=-1, Index strideB=-1, Index offsetA=0, Index offsetB=0, mpRealInterval* /*unpackedB*/ = 0)
      {
        mpRealInterval acc1, acc2, tmp;

        if(strideA==-1) strideA = depth;
        if(strideB==-1) strideB = depth;

        for(Index j=0; j<cols; j+=nr)
        {
          Index actual_nr = (std::min<Index>)(nr,cols-j);
          mpRealInterval *C1 = res + j*resStride;
          mpRealInterval *C2 = res + (j+1)*resStride;
          for(Index i=0; i<rows; i++)
          {
            mpRealInterval *B = const_cast<mpRealInterval*>(blockB) + j*strideB + offsetB*actual_nr;
            mpRealInterval *A = const_cast<mpRealInterval*>(blockA) + i*strideA + offsetA;
            acc1 = 0;
            acc2 = 0;
            for(Index k=0; k<depth; k++)
            {
              mpfi_mul(tmp.mpfi_ptr(), A[k].mpfi_ptr(), B[0].mpfi_ptr());
              mpfi_add(acc1.mpfi_ptr(), acc1.mpfi_ptr(), tmp.mpfi_ptr());

              if(actual_nr==2) {
                mpfi_mul(tmp.mpfi_ptr(), A[k].mpfi_ptr(), B[1].mpfi_ptr());
                mpfi_add(acc2.mpfi_ptr(), acc2.mpfi_ptr(), tmp.mpfi_ptr());
              }

              B+=actual_nr;
            }

            mpfi_mul(acc1.mpfi_ptr(), acc1.mpfi_ptr(), alpha.mpfi_ptr());
            mpfi_add(C1[i].mpfi_ptr(), C1[i].mpfi_ptr(), acc1.mpfi_ptr());

            if(actual_nr==2) {
              mpfi_mul(acc2.mpfi_ptr(), acc2.mpfi_ptr(), alpha.mpfi_ptr());
              mpfi_add(C2[i].mpfi_ptr(), C2[i].mpfi_ptr(), acc2.mpfi_ptr());
            }
          }
        }
      }
    };

  } // end namespace internal
}

#endif // EIGEN_MPREALINTERVALSUPPORT_MODULE_H
