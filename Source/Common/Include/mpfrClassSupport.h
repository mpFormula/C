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

#ifndef EIGEN_mpfr_classSUPPORT_MODULE_H
#define EIGEN_mpfr_classSUPPORT_MODULE_H

#include <Eigen/Core>
#include <gmpfrxx.h>

namespace Eigen {


  template<> struct NumTraits<mpfr_class>
    : GenericNumTraits<mpfr_class>
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

    typedef mpfr_class Real;
    typedef mpfr_class NonInteger;

    inline static Real highest   ()  { return  std::numeric_limits<mpfr_class>::max();}
    inline static Real lowest   ()  { return  -std::numeric_limits<mpfr_class>::max();}

    // Constants
    inline static Real Pi()      {return const_pi();}
    inline static Real Euler()   {return const_euler();}
    inline static Real Log2()    {return const_log2();}
    inline static Real Catalan() {return const_catalan();}

 //   inline static Real epsilon  (long Precision = mpfr_class::get_default_prec())     {    return mpfr::machine_epsilon(Precision); }
    inline static Real epsilon  ()  {return std::numeric_limits<mpfr_class>::epsilon();}


 //   inline static Real epsilon  (const Real& x)                                         {    return mpfr::machine_epsilon(x); }

    inline static Real dummy_precision()
    {
 //       unsigned int weak_prec = ((mpfr_class::get_dprec()-1) * 90) / 100;
        return (10.0/9.0) * std::numeric_limits<mpfr_class>::epsilon();
 //       return mpfr::machine_epsilon(weak_prec);
    }
  };

  namespace internal {

  template<> inline mpfr_class random<mpfr_class>()
  {
       return mpfr_class(std::rand()/(double)RAND_MAX);
    //return mpfr::random();
  }

  template<> inline mpfr_class random<mpfr_class>(const mpfr_class& a, const mpfr_class& b)
  {
    return a + (b-a) * random<mpfr_class>();
  }

  inline bool isMuchSmallerThan(const mpfr_class& a, const mpfr_class& b, const mpfr_class& eps)
  {
    return abs(a) <= (abs(b) * eps);
  }

  inline bool isApprox(const mpfr_class& a, const mpfr_class& b, const mpfr_class& eps)
  {
    return abs(a - b) <= (min)(abs(a), abs(b)) * eps;
    //return mpfr::isEqualFuzzy(a,b,eps);
  }

  inline bool isApproxOrLessThan(const mpfr_class& a, const mpfr_class& b, const mpfr_class& eps)
  {
    return a <= b || isApprox(a,b,eps);
  //  return a <= b || mpfr::isEqualFuzzy(a,b,eps);
  }

  template<> inline long double cast<mpfr_class,long double>(const mpfr_class& x)
  { return x.get_ld();}

  template<> inline double cast<mpfr_class,double>(const mpfr_class& x)
  { return x.get_d();}

  template<> inline long cast<mpfr_class,long>(const mpfr_class& x)
    { return x.get_si();}

  template<> inline int cast<mpfr_class,int>(const mpfr_class& x)
      { return int(x.get_si());}

  // Specialize GEBP kernel and traits for mpfr_class (no need for peeling, nor complicated stuff)
    template<>
    class gebp_traits<mpfr_class, mpfr_class, false, false>
    {
    public:
      typedef mpfr_class ResScalar;
      enum {
        nr = 2, // must be 2 for proper packing...
        mr = 1,
        WorkSpaceFactor = nr,
        LhsProgress = 1,
        RhsProgress = 1
      };
    };

    template<typename Index, int mr, int nr, bool ConjugateLhs, bool ConjugateRhs>
    struct gebp_kernel<mpfr_class,mpfr_class,Index,mr,nr,ConjugateLhs,ConjugateRhs>
    {
 //     typedef mpfr_class mpfr_class;

      EIGEN_DONT_INLINE
      void operator()(mpfr_class* res, Index resStride, const mpfr_class* blockA, const mpfr_class* blockB, Index rows, Index depth, Index cols, mpfr_class alpha,
                      Index strideA=-1, Index strideB=-1, Index offsetA=0, Index offsetB=0, mpfr_class* /*unpackedB*/ = 0)
      {
        mpfr_class acc1, acc2, tmp;

        if(strideA==-1) strideA = depth;
        if(strideB==-1) strideB = depth;

        for(Index j=0; j<cols; j+=nr)
        {
          Index actual_nr = (std::min<Index>)(nr,cols-j);
          mpfr_class *C1 = res + j*resStride;
          mpfr_class *C2 = res + (j+1)*resStride;
          for(Index i=0; i<rows; i++)
          {
            mpfr_class *B = const_cast<mpfr_class*>(blockB) + j*strideB + offsetB*actual_nr;
            mpfr_class *A = const_cast<mpfr_class*>(blockA) + i*strideA + offsetA;
            acc1 = 0;
            acc2 = 0;
            for(Index k=0; k<depth; k++)
            {
              mpfr_mul(tmp.get_mpfr_t(), A[k].get_mpfr_t(), B[0].get_mpfr_t(), mpfr_class::get_rnd());
              mpfr_add(acc1.get_mpfr_t(), acc1.get_mpfr_t(), tmp.get_mpfr_t(),  mpfr_class::get_rnd());

              if(actual_nr==2) {
                mpfr_mul(tmp.get_mpfr_t(), A[k].get_mpfr_t(), B[1].get_mpfr_t(), mpfr_class::get_rnd());
                mpfr_add(acc2.get_mpfr_t(), acc2.get_mpfr_t(), tmp.get_mpfr_t(),  mpfr_class::get_rnd());
              }

              B+=actual_nr;
            }

            mpfr_mul(acc1.get_mpfr_t(), acc1.get_mpfr_t(), alpha.get_mpfr_t(), mpfr_class::get_rnd());
            mpfr_add(C1[i].get_mpfr_t(), C1[i].get_mpfr_t(), acc1.get_mpfr_t(),  mpfr_class::get_rnd());

            if(actual_nr==2) {
              mpfr_mul(acc2.get_mpfr_t(), acc2.get_mpfr_t(), alpha.get_mpfr_t(), mpfr_class::get_rnd());
              mpfr_add(C2[i].get_mpfr_t(), C2[i].get_mpfr_t(), acc2.get_mpfr_t(),  mpfr_class::get_rnd());
            }
          }
        }
      }
    };

  } // end namespace internal
}

#endif // EIGEN_mpfr_classSUPPORT_MODULE_H
