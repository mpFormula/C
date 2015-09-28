#include <complex>
#include <mpreal.h>
#include <mpc.h>




using namespace std;
using namespace mpfr;

/*
Classes complex
Complex number class (class template )
Functions

Complex values:

real: Real part of complex (function template )
imag: Imaginary part of complex (function template )
abs: Absolute value of complex (function template )
arg: Phase angle of complex (function template )
norm: Norm of complex (function template )
conj: Complex conjugate (function template )
polar: Complex from polar components (function template )
proj: Complex projection. (function template )


Transcendentals overloads:

cos: Cosine of complex (function template )
cosh: Hyperbolic cosine of complex (function template )
exp: Exponential of complex (function template )
log: Natural logarithm of complex (function template )
log10: Common logarithm of complex (function template )
pow: Power of complex (function template )
sin: Sine of complex (function template )
sinh: Hyperbolic sine of complex (function template )
sqrt: Square root of complex (function template )
tan: Tangent of complex (function template )
tanh: Hyperbolic tangent of complex (function template )
acos: Arc cosine of complex (function template )
acosh: Arc hyperbolic cosine of complex (function template )
asin: Arc sine of complex (function template )
asinh: Arc hyperbolic sine of complex (function template )
atan: Arc tangent of complex (function template )
atanh: Arc hyperbolic tangent of complex (function template )

*/


mpreal abs_mpc(std::complex<mpreal> z1){
    mpc_t x;
    mpfr_t y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpfr_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_abs(y, x, MPFR_RNDN);

    mpreal yr;
    yr = y;
    mpfr_clear(y);
    mpc_clear(x);
    return yr;
}


mpreal arg_mpc(std::complex<mpreal> z1){
    mpc_t x;
    mpfr_t y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpfr_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_arg(y, x, MPFR_RNDN);

    mpreal yr;
    yr = y;
    mpfr_clear(y);
    mpc_clear(x);
    return yr;
}




mpreal norm_mpc(std::complex<mpreal> z1){
    mpc_t x;
    mpfr_t y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpfr_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_norm(y, x, MPFR_RNDN);

    mpreal yr;
    yr = y;
    mpfr_clear(y);
    mpc_clear(x);
    return yr;
}

//conj: Complex conjugate (function template )
//polar: Complex from polar components (function template )
//proj: Complex projection. (function template )



std::complex<mpreal> conjugate_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_conj(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}


// MISSING !!!
//std::complex<mpreal> polar_mpc(std::complex<mpreal> z1){
//    mpc_t x, y;
//    mpc_init2 (x, mpreal::get_default_prec());
//    mpc_init2 (y, mpreal::get_default_prec());
//    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);
//
//    mpc_polar(y, x, MPC_RNDNN);
//
//    std::complex<mpreal> yc;
//    yc.real() = y->re; yc.imag() = y->im;
//    mpc_clear(y);
//    mpc_clear(x);
//    return yc;
//}


std::complex<mpreal> proj_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_proj(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}


std::complex<mpreal> sqrt_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_sqrt(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> pow_mpc(std::complex<mpreal> z1, std::complex<mpreal> z2){
    mpc_t x1, x2, y;
    mpc_init2 (x1, mpreal::get_default_prec());
    mpc_init2 (x2, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x1, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);
    mpc_set_fr_fr(x2, z2.real().mpfr_ptr(),z2.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_pow(y, x1, x2, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x2);
    mpc_clear(x1);
    return yc;
}



std::complex<mpreal> pow_mpc(std::complex<mpreal> z1, mpreal f){
    mpc_t x1, y;
    mpc_init2 (x1, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x1, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_pow_fr(y, x1, f.mpfr_ptr(), MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x1);
    return yc;
}




std::complex<mpreal> pow_mpc(std::complex<mpreal> z1, double d){
    mpc_t x1, y;
    mpc_init2 (x1, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x1, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_pow_d(y, x1, d, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x1);
    return yc;
}



std::complex<mpreal> pow_mpc(std::complex<mpreal> z1, long si){
    mpc_t x1, y;
    mpc_init2 (x1, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x1, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_pow_si(y, x1, si, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x1);
    return yc;
}




std::complex<mpreal> pow_mpc(std::complex<mpreal> z1, unsigned long ui){
    mpc_t x1, y;
    mpc_init2 (x1, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x1, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_pow_ui(y, x1, ui, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x1);
    return yc;
}


std::complex<mpreal> exp_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_exp(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> log_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_log(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> log10_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_log10(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> sin_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_sin(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> cos_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_cos(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> tan_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_tan(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}


std::complex<mpreal> sinh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_sinh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> cosh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_cosh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> tanh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_tanh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> asin_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_asin(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> acos_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_acos(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> atan_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_atan(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}


std::complex<mpreal> asinh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_asinh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




std::complex<mpreal> acosh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_acosh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc(y->re,y->im);
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}



std::complex<mpreal> atanh_mpc(std::complex<mpreal> z1){
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_atanh(y, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
}




 std::complex<mpreal> operator + (std::complex<mpreal> z1, double d)
    {
    mpc_t x, y ;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);
    mpfr_t fr;
    mpfr_init_set_d(fr, d,  mpreal::get_default_rnd());

    mpc_add_fr(y, x, fr, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }





 std::complex<mpreal> operator + (std::complex<mpreal> z1,unsigned long int ui)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_add_ui(y, x, ui, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


 std::complex<mpreal> operator - (std::complex<mpreal> z1,unsigned long int ui)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_sub_ui(y, x, ui, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


 std::complex<mpreal> operator - (unsigned long int ui, std::complex<mpreal> z1)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_ui_sub( y , ui, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


 std::complex<mpreal> operator * (std::complex<mpreal> z1,unsigned long int ui)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_mul_ui(y, x, ui, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


 std::complex<mpreal> operator / (std::complex<mpreal> z1,unsigned long int ui)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_div_ui(y, x, ui, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


 std::complex<mpreal> operator / (unsigned long int ui, std::complex<mpreal> z1)
    {
    mpc_t x, y;
    mpc_init2 (x, mpreal::get_default_prec());
    mpc_init2 (y, mpreal::get_default_prec());
    mpc_set_fr_fr(x, z1.real().mpfr_ptr(),z1.imag().mpfr_ptr(), MPC_RNDNN);

    mpc_ui_div(y, ui, x, MPC_RNDNN);

    std::complex<mpreal> yc;
    yc.real() = y->re; yc.imag() = y->im;
    mpc_clear(y);
    mpc_clear(x);
    return yc;
    }


