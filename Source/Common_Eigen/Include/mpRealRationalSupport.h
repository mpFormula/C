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

#ifndef EIGEN_MPREALRationalSUPPORT_MODULE_H
#define EIGEN_MPREALRationalSUPPORT_MODULE_H

#include <Eigen/Core>
#include <mpRealRational.h>

namespace Eigen {

  template<> struct NumTraits<mpq::mpRealRational>
    : GenericNumTraits<mpq::mpRealRational>
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

    typedef mpq::mpRealRational Real;
    typedef mpq::mpRealRational NonInteger;

    inline static Real highest   ()  { return  mpq::maxval(); }
    inline static Real lowest    ()  { return -mpq::maxval(); }

    // Constants
//    inline static Real Pi       ()     {    return mpq::const_pi();        }
//    inline static Real Euler    ()     {    return mpq::const_euler();     }
//    inline static Real Log2     ()     {    return mpq::const_log2();      }
//    inline static Real Catalan  ()     {    return mpq::const_catalan();   }

    inline static Real epsilon  ()     {    return mpq::machine_epsilon(); }
    inline static Real epsilon  (const Real& x)                                         {    return mpq::machine_epsilon(x); }

    inline static Real dummy_()
    {
        //unsigned int weak_prec = ((mpq::mpRealRational::get_default_prec()-1) * 90) / 100;
        return mpq::machine_epsilon(Real("0.9E-1000"));
    }
  };

  namespace internal {

  template<> inline mpq::mpRealRational random<mpq::mpRealRational>()
  {
    return mpq::random();
  }

  template<> inline mpq::mpRealRational random<mpq::mpRealRational>(const mpq::mpRealRational& a, const mpq::mpRealRational& b)
  {
    return a + (b-a) * random<mpq::mpRealRational>();
  }

  inline bool isMuchSmallerThan(const mpq::mpRealRational& a, const mpq::mpRealRational& b, const mpq::mpRealRational& eps)
  {
    return mpq::abs(a) <= mpq::abs(b) * eps;
  }

  inline bool isApprox(const mpq::mpRealRational& a, const mpq::mpRealRational& b, const mpq::mpRealRational& eps)
  {
    return mpq::isEqualFuzzy(a,b,eps);
  }

  inline bool isApproxOrLessThan(const mpq::mpRealRational& a, const mpq::mpRealRational& b, const mpq::mpRealRational& eps)
  {
    return a <= b || mpq::isEqualFuzzy(a,b,eps);
  }

  template<> inline long double cast<mpq::mpRealRational,long double>(const mpq::mpRealRational& x)
  { return x.toLDouble(); }

  template<> inline double cast<mpq::mpRealRational,double>(const mpq::mpRealRational& x)
  { return x.toDouble(); }

  template<> inline long cast<mpq::mpRealRational,long>(const mpq::mpRealRational& x)
  { return x.toLong(); }

  template<> inline int cast<mpq::mpRealRational,int>(const mpq::mpRealRational& x)
  { return int(x.toLong()); }

  // Specialize GEBP kernel and traits for mpRealRational (no need for peeling, nor complicated stuff)
  // This also permits to directly call mpfi's routines and avoid many temporaries produced by mpRealRational
    template<>
    class gebp_traits<mpq::mpRealRational, mpq::mpRealRational, false, false>
    {
    public:
      typedef mpq::mpRealRational ResScalar;
      enum {
        nr = 2, // must be 2 for proper packing...
        mr = 1,
        WorkSpaceFactor = nr,
        LhsProgress = 1,
        RhsProgress = 1
      };
    };

    template<typename Index, int mr, int nr, bool ConjugateLhs, bool ConjugateRhs>
    struct gebp_kernel<mpq::mpRealRational,mpq::mpRealRational,Index,mr,nr,ConjugateLhs,ConjugateRhs>
    {
      typedef mpq::mpRealRational mpRealRational;

      EIGEN_DONT_INLINE
      void operator()(mpRealRational* res, Index resStride, const mpRealRational* blockA, const mpRealRational* blockB, Index rows, Index depth, Index cols, mpRealRational alpha,
                      Index strideA=-1, Index strideB=-1, Index offsetA=0, Index offsetB=0, mpRealRational* /*unpackedB*/ = 0)
      {
        mpRealRational acc1, acc2, tmp;

        if(strideA==-1) strideA = depth;
        if(strideB==-1) strideB = depth;

        for(Index j=0; j<cols; j+=nr)
        {
          Index actual_nr = (std::min<Index>)(nr,cols-j);
          mpRealRational *C1 = res + j*resStride;
          mpRealRational *C2 = res + (j+1)*resStride;
          for(Index i=0; i<rows; i++)
          {
            mpRealRational *B = const_cast<mpRealRational*>(blockB) + j*strideB + offsetB*actual_nr;
            mpRealRational *A = const_cast<mpRealRational*>(blockA) + i*strideA + offsetA;
            acc1 = 0;
            acc2 = 0;
            for(Index k=0; k<depth; k++)
            {
              mpq_mul(tmp.mpq_ptr(), A[k].mpq_ptr(), B[0].mpq_ptr());
              mpq_add(acc1.mpq_ptr(), acc1.mpq_ptr(), tmp.mpq_ptr());

              if(actual_nr==2) {
                mpq_mul(tmp.mpq_ptr(), A[k].mpq_ptr(), B[1].mpq_ptr());
                mpq_add(acc2.mpq_ptr(), acc2.mpq_ptr(), tmp.mpq_ptr());
              }

              B+=actual_nr;
            }

            mpq_mul(acc1.mpq_ptr(), acc1.mpq_ptr(), alpha.mpq_ptr());
            mpq_add(C1[i].mpq_ptr(), C1[i].mpq_ptr(), acc1.mpq_ptr());

            if(actual_nr==2) {
              mpq_mul(acc2.mpq_ptr(), acc2.mpq_ptr(), alpha.mpq_ptr());
              mpq_add(C2[i].mpq_ptr(), C2[i].mpq_ptr(), acc2.mpq_ptr());
            }
          }
        }
      }
    };

  } // end namespace internal
}

#endif // EIGEN_MPREALRationalSUPPORT_MODULE_H
