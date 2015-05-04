#include "libEigen.h"

#define MP_FUNCTION_INIT \
    (*y0).resizeLike(*x0); \
    int r = (long) (*x0).rows(); \
    int c = (long) (*x0).cols();

#define MP_FUNCTION0_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {(*y0)(i, j) = f((*y0)(i, j)); } }; break;

#define MP_FUNCTION1_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {(*y0)(i, j) = f((*x0)(i, j)) ;} }; break;

#define MP_FUNCTION2_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {(*y0)(i, j) = f((*x0)(i, j), (*x1)(i, j)) ;} }; break;

#define MP_FUNCTION3_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
  {(*y0)(i, j) = f((*x0)(i, j), (*x1)(i, j), (*x2)(i, j)) ;} }; break;

#define MP_FUNCTION_2RESULTS_INT_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
     { int n=0; (*y0)(i, j) = f((*x0)(i, j), &n ); (*y1)(i, j) = n; }}; break;

#define MP_FUNCTION2_2RESULTS_INT_BODY(f) \
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
     { int n=0; (*y0)(i, j) = f((*x0)(i, j), (*x1)(i, j), &n ); (*y1)(i, j) = n; }}; break;

#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)
    #define MP_FUNCTION_2RESULTS_BODY(f) \
    for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
         { mpType n; (*y0)(i, j) = f((*x0)(i, j), &n ); (*y1)(i, j) = n; }}; break;

    #include <cmath>
    mpType const_log2_a(mpType x) {return (mpType) 0.69314718055994530941723212145818L; }
    mpType const_pi_a(mpType x) {return (mpType) 3.1415926535897932384626433832795L; }
    mpType const_euler_gamma_a(mpType x) {return (mpType) 0.5772156649015328606065120900824024310421L; }
    mpType const_catalan_a(mpType x) {return (mpType) 0.915965594177219015054603514932384110774L; }
    mpType sign(mpType x) {return (mpType) (x > 0) ? 1 : ((x < 0) ? -1 : 0); }
    mpType sqr(mpType x) {return (mpType)  (x*x); }
    mpType exp10(mpType x) {mpType ln10 =  2.3025850929940456840179914546844L;  return (mpType) expl(ln10 * x); }
#else
    #define MP_FUNCTION_2RESULTS_BODY(f) \
    for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++) \
         { mpType n; (*y0)(i, j) = f((*x0)(i, j), n ); (*y1)(i, j) = n; }}; break;
#endif // defined



void Std_mpType_Functions0(long what, mpMatrix *y0)
{
    int r = (long) (*y0).rows();
    int c = (long) (*y0).cols();
    switch (what){
        case mp_const_log2:      { MP_FUNCTION0_BODY(const_log2_a);}
        case mp_const_pi:        { MP_FUNCTION0_BODY(const_pi_a);}
        case mp_const_euler:     { MP_FUNCTION0_BODY(const_euler_gamma_a);}
        case mp_const_catalan:   { MP_FUNCTION0_BODY(const_catalan_a);}
    }
}



void Std_mpType_Functions1(long what, mpMatrix *y0, mpMatrix *x0)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Abs:      { MP_FUNCTION1_BODY(abs);}
        case mp_const_Fabs:     { MP_FUNCTION1_BODY(fabs);}
        case mp_const_Sqrt:     { MP_FUNCTION1_BODY(sqrt);}
        case mp_const_Cbrt:     { MP_FUNCTION1_BODY(cbrt);}

        case mp_const_Exp:      { MP_FUNCTION1_BODY(exp);}
        case mp_const_Exp2:     { MP_FUNCTION1_BODY(exp2);}
        case mp_const_Expm1:    { MP_FUNCTION1_BODY(expm1);}

        case mp_const_Log:      { MP_FUNCTION1_BODY(log);}
        case mp_const_Log2:     { MP_FUNCTION1_BODY(log2);}
        case mp_const_Log10:    { MP_FUNCTION1_BODY(log10);}
        case mp_const_Log1p:    { MP_FUNCTION1_BODY(log1p);}

        case mp_const_Ilogb :   { MP_FUNCTION1_BODY(ilogb);} // The value returned by this function is one less than the exponent obtained with frexp
        case mp_const_Logb :    { MP_FUNCTION1_BODY(logb);}  //On most platforms, FLT_RADIX is 2, and thus this function is equivalent to log2 for positive values.

        case mp_const_Sin:      { MP_FUNCTION1_BODY(sin);}
        case mp_const_Cos:      { MP_FUNCTION1_BODY(cos);}
        case mp_const_Tan:      { MP_FUNCTION1_BODY(tan);}
        case mp_const_Sinh:     { MP_FUNCTION1_BODY(sinh);}
        case mp_const_Cosh:     { MP_FUNCTION1_BODY(cosh);}
        case mp_const_Tanh:     { MP_FUNCTION1_BODY(tanh);}
        case mp_const_Asin:     { MP_FUNCTION1_BODY(asin);}
        case mp_const_Acos:     { MP_FUNCTION1_BODY(acos);}
        case mp_const_Atan:     { MP_FUNCTION1_BODY(atan);}
        case mp_const_Asinh:    { MP_FUNCTION1_BODY(asinh);}
        case mp_const_Acosh:    { MP_FUNCTION1_BODY(acosh);}
        case mp_const_Atanh:    { MP_FUNCTION1_BODY(atanh);}

        case mp_const_Erf:      { MP_FUNCTION1_BODY(erf);}
        case mp_const_Erfc:     { MP_FUNCTION1_BODY(erfc);}
        case mp_const_Tgamma:   { MP_FUNCTION1_BODY(tgamma);}
        case mp_const_LGamma:   { MP_FUNCTION1_BODY(lgamma);}

        case mp_const_Ceil:     { MP_FUNCTION1_BODY(ceil);}
        case mp_const_Floor:    { MP_FUNCTION1_BODY(floor);}
        case mp_const_Trunc:    { MP_FUNCTION1_BODY(trunc);}
        case mp_const_Round:    { MP_FUNCTION1_BODY(round);}
        case mp_const_Lround:   { MP_FUNCTION1_BODY(lround);}
        case mp_const_Llround:  { MP_FUNCTION1_BODY(llround);}
        case mp_const_Rint:     { MP_FUNCTION1_BODY(rint);}
        case mp_const_Lrint:    { MP_FUNCTION1_BODY(lrint);}
        case mp_const_Llrint:   { MP_FUNCTION1_BODY(llrint);}
        case mp_const_Nearbyint:{ MP_FUNCTION1_BODY(nearbyint);}


//******************************************************************************
        case mp_const_Sgn:     { MP_FUNCTION1_BODY(sign);}
        case mp_const_Abs2:    { MP_FUNCTION1_BODY(sqr);}
        case mp_const_Exp10:   { MP_FUNCTION1_BODY(exp10);}

    }
}


void Std_mpType_Functions2(long what, mpMatrix *y0, mpMatrix *x0,  mpMatrix *x1)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Hypot:          { MP_FUNCTION2_BODY(hypot);}
        case mp_const_Ldexp:          { MP_FUNCTION2_BODY(ldexp);}
        case mp_const_Scalbn:         { MP_FUNCTION2_BODY(scalbn);}    // scalbn(x,n) = x * FLT_RADIX^n. On most platforms, FLT_RADIX is 2, making this function equivalent to ldexp.
        case mp_const_Scalbln:        { MP_FUNCTION2_BODY(scalbln);}   // scalbln(x,n) = x * FLT_RADIX^n. On most platforms, FLT_RADIX is 2, making this function equivalent to ldexp.
        case mp_const_Pow:            { MP_FUNCTION2_BODY(pow);}
        case mp_const_Fmod:           { MP_FUNCTION2_BODY(fmod);}
        case mp_const_Atan2:          { MP_FUNCTION2_BODY(atan2);}
        case mp_const_Copysign:       { MP_FUNCTION2_BODY(copysign);}
        case mp_const_Max:            { MP_FUNCTION2_BODY(fmax);}
        case mp_const_Min:            { MP_FUNCTION2_BODY(fmin);}
        case mp_const_Dim:            { MP_FUNCTION2_BODY(fdim);}
        case mp_const_Remainder:      { MP_FUNCTION2_BODY(remainder);}
        case mp_const_Nextafter:      { MP_FUNCTION2_BODY(nextafter);}
        case mp_const_Nexttoward:     { MP_FUNCTION2_BODY(nexttoward);}
    }
}


void Std_mpType_Functions3(long what, mpMatrix *y0, mpMatrix *x0,  mpMatrix *x1,  mpMatrix *x2)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Fma:  { MP_FUNCTION3_BODY(fma);}
    }
}


void Std_mpType_Functions_2Results(long what, mpMatrix *y0, mpMatrix *y1,  mpMatrix *x0)
{
    MP_FUNCTION_INIT
    (*y1).resizeLike(*x0);
    switch (what){
        case mp_const_Frexp:   { MP_FUNCTION_2RESULTS_INT_BODY(frexp);}
        case mp_const_Modf:    { MP_FUNCTION_2RESULTS_BODY(modf);}
    }
}


void Std_mpType_Functions2_2Results(long what, mpMatrix *y0, mpMatrix *y1,  mpMatrix *x0,  mpMatrix *x1)
{
    MP_FUNCTION_INIT
    (*y1).resizeLike(*x0);
    switch (what){
        case mp_const_Remquo:   { MP_FUNCTION2_2RESULTS_INT_BODY(remquo);}
    }
}




void boost_mpType_Functions1Bool(long what, mpMatrix *x, long * result)
{
	int r = (long) (*x).rows();
	int c = (long) (*x).cols();
	*result = 0;
	long temp = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			switch (what){
				case mp_const_IsOdd: temp = 0;  break;
				case mp_const_IsEven: temp = 0;  break;
				case mp_const_IsPerfectPower: temp = 0;  break;
				case mp_const_IsPerfectSquare: temp = 0;  break;
				case mp_const_fits_ulong: temp = 0;  break;
				case mp_const_fits_slong: temp = 0;  break;
				case mp_const_fits_uint: temp = 0;  break;
				case mp_const_fits_sint: temp = 0;  break;
				case mp_const_fits_ushort: temp = 0;  break;
				case mp_const_fits_sshort: temp = 0;  break;

				case mp_const_isInf: temp = 0;  break;
				case mp_const_isNan: temp = 0;  break;
				case mp_const_isNumber: temp = 0;  break;
				case mp_const_isZero: temp = 0;  break;
				case mp_const_isRegular: temp = 0;  break;
				case mp_const_isInteger: temp = 0;  break;

				case mp_const_IsPos: temp = 0;  break;
				case mp_const_IsStrictlyPos: temp = 0;  break;
				case mp_const_IsNonNeg: temp = 0;  break;
				case mp_const_IsNeg: temp = 0;  break;
				case mp_const_IsStrictlyNeg: temp = 0;  break;
				case mp_const_IsNonPos: temp = 0;  break;
				case mp_const_HasZero: temp = 0;  break;
				case mp_const_IsEmpty: temp = 0;  break;
				default: temp = 0; break;
			}
			*result = *result + temp;
		};
	};
}



void boost_mpType_Functions2Bool(long what, mpMatrix *x, mpMatrix *y, long * result)
{
	int r = (long) (*x).rows();
	int c = (long) (*x).cols();
	*result = 0;
	long temp = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			switch (what){
				case mp_const_IsDivisible: temp =  0;  break;
				case mp_const_IsDivisible_2exp: temp = 0;  break;
				case mp_const_IsDefinitelyComposite: temp = 0;  break;
				case mp_const_IsDefinitelyPrime: temp = 0;  break;
				case mp_const_IsProbablyPrime: temp = 0;  break;
				case mp_const_IsUnordered: temp = 0;  break;
				case mp_const_IsInside: temp = 0;  break;
				case mp_const_IsStrictlyInside: temp = 0;  break;
				default: temp = 0; break;
			}
			*result = *result + temp;
		};
	};
}


void boost_mpType_Functions3Bool(long what, mpMatrix *x, mpMatrix *y, mpMatrix *z, long * result)
{
	int r = (long) (*x).rows();
	int c = (long) (*x).cols();
	*result = 0;
	long temp = 0;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			switch (what){
				case mp_const_IsCongruent: temp =  0;  break;
				case mp_const_IsCongruent_2exp: temp =  0;  break;

				default: temp = 0; break;
			}
			*result = *result + temp;
		};
	};
}






void Std_mpType_cplx_Functions1(long what, mpMatrixC *y0, mpMatrixC *x0)
{
    MP_FUNCTION_INIT
    switch (what){
// returning real result
        case mp_const_Real:      { MP_FUNCTION1_BODY(real);}
        case mp_const_Imag:      { MP_FUNCTION1_BODY(imag);}
        case mp_const_Abs:      { MP_FUNCTION1_BODY(abs);}
        case mp_const_Arg:     { MP_FUNCTION1_BODY(arg);}
        case mp_const_cplx_Norm:     { MP_FUNCTION1_BODY(norm);}

        case mp_const_Conj:     { MP_FUNCTION1_BODY(conj);}
//        case mp_const_Polar:     { MP_FUNCTION1_BODY(polar);}
 //       case mp_const_Proj:     { MP_FUNCTION1_BODY(proj);}

        case mp_const_Cos:      { MP_FUNCTION1_BODY(cos);}
        case mp_const_Cosh:     { MP_FUNCTION1_BODY(cosh);}
        case mp_const_Exp:      { MP_FUNCTION1_BODY(exp);}
        case mp_const_Log:      { MP_FUNCTION1_BODY(log);}
        case mp_const_Log10:    { MP_FUNCTION1_BODY(log10);}
// Pow
        case mp_const_Sin:      { MP_FUNCTION1_BODY(sin);}
        case mp_const_Sinh:     { MP_FUNCTION1_BODY(sinh);}
        case mp_const_Sqrt:     { MP_FUNCTION1_BODY(sqrt);}
        case mp_const_Tan:      { MP_FUNCTION1_BODY(tan);}
        case mp_const_Tanh:     { MP_FUNCTION1_BODY(tanh);}
        case mp_const_Acos:     { MP_FUNCTION1_BODY(acos);}
        case mp_const_Acosh:    { MP_FUNCTION1_BODY(acosh);}
        case mp_const_Asin:     { MP_FUNCTION1_BODY(asin);}
        case mp_const_Asinh:    { MP_FUNCTION1_BODY(asinh);}
        case mp_const_Atan:     { MP_FUNCTION1_BODY(atan);}
        case mp_const_Atanh:    { MP_FUNCTION1_BODY(atanh);}


    }
}


void Std_mpType_cplx_Functions2(long what, mpMatrixC *y0, mpMatrixC *x0,  mpMatrixC *x1)
{
    MP_FUNCTION_INIT
    switch (what){
        case mp_const_Pow:            { MP_FUNCTION2_BODY(pow);}
    }
}


