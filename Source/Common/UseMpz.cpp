
#include "mpNumC_Short.h"

#include <gmp.h>
#include <mpfr.h>
#include <inttypes.h>
#include <stdlib.h>


void Lib_Gmp_Rand_Init(GmpRandPtr* state)
{
    (*state) =  malloc (sizeof(__gmp_randstate_struct));
    gmp_randinit_mt( (__gmp_randstate_struct*) (*state));
}

void Lib_Gmp_Rand_Clear(GmpRandPtr state)
{
    gmp_randclear( (__gmp_randstate_struct*) state);
    free(state);
}


void Lib_Randinit_Set(GmpRandPtr* state1, GmpRandPtr state2)
{
    (*state1) =  malloc (sizeof(__gmp_randstate_struct));
    gmp_randinit_set( (__gmp_randstate_struct*) (*state1), (__gmp_randstate_struct*) state2);
}


void Lib_Randinit_Seed_Ui(GmpRandPtr* state, uint32_t seed)
{
    (*state) =  malloc (sizeof(__gmp_randstate_struct));
    gmp_randinit_mt( (__gmp_randstate_struct*) (*state));
    gmp_randseed_ui( (__gmp_randstate_struct*) (*state), seed);
}


void Lib_Randinit_Seed(GmpRandPtr* state, MpzPtr seed)
{
    (*state) =  malloc (sizeof(__gmp_randstate_struct));
    gmp_randinit_mt( (__gmp_randstate_struct*) (*state));
    gmp_randseed( (__gmp_randstate_struct*) (*state), (mpz_ptr) seed);
}


void Lib_Mpz_Init(MpzPtr* x)
{
    (*x) =  malloc (sizeof(__mpz_struct));
    mpz_init( (mpz_ptr) (*x));
}


void Lib_Mpz_Clear(MpzPtr x)
{
    mpz_clear( (mpz_ptr) x);
    free(x);
}


void Lib_Mpz_Set(MpzPtr res, MpzPtr x)
{
    mpz_set( (mpz_ptr) res, (mpz_ptr) x);
}


void Lib_Mpz_Set_Ui(MpzPtr x, uint32_t u)
{
    mpz_set_ui( (mpz_ptr) x, u);
}


void Lib_Mpz_Set_Si(MpzPtr x, int32_t u)
{
    mpz_set_si( (mpz_ptr) x, u);
}



void Lib_Mpz_Set_Ui64(MpfcPtr x, uint64_t uint64)
{
       mpz_set_ui( (mpz_ptr) x, uint64);


////    printf("Received %llu", uint64);
//    int32_t low32, high32;
//    low32 = (uint32_t)uint64;
//    high32 = (uint64_t)uint64 >> 32;
//    mpz_set_uiui((mpz_ptr) x, high32, low32);
}


void Lib_Mpz_Set_Si64(MpfcPtr x, int64_t sint64)
{
        mpz_set_si( (mpz_ptr) x, sint64);


////    printf("Received %lld", sint64);
//    int32_t low32, high32;
//    low32 = (uint32_t)sint64;
//    high32 = (uint64_t)sint64 >> 32;
//    if (sint64 >= 0)
//        {
////        printf("uiui");
//        mpz_set_uiui((mpz_ptr) x, high32, low32);
//        }
//
//    else
//        {
////        printf("negui");
//        mpz_neg_uiui((mpz_ptr) x, high32, low32);
//        }
}




void Lib_Mpz_Set_D(MpzPtr x, double u)
{
    mpz_set_d( (mpz_ptr) x, u);
}


int32_t Lib_Mpz_Set_Str(MpzPtr x, const char * str , int32_t b)
{
    return mpz_set_str( (mpz_ptr) x, str, b);
}




uint32_t Lib_Mpz_Get_Ui(MpzPtr x)
{
    return mpz_get_ui( (mpz_ptr) x);
}


int32_t Lib_Mpz_Get_Si(MpzPtr x)
{
    return mpz_get_si( (mpz_ptr) x);
}


uint64_t Lib_Mpz_Get_Ui64(MpzPtr x)
{
    char * str = mpz_get_str(NULL , 10, (mpz_ptr) x);
    uint64_t llui = strtoull (str, NULL, 10);
    return llui;
}


int64_t Lib_Mpz_Get_Si64(MpzPtr x)
{
    char * str = mpz_get_str(NULL , 10, (mpz_ptr) x);
    int64_t lli = strtoll (str, NULL, 10);
    return lli;
}




double Lib_Mpz_Get_D(MpzPtr x)
{
    return mpz_get_d( (mpz_ptr) x);
}


uint32_t Lib_Mpz_SizeInBase(MpzPtr x, int32_t base)
{
    return mpz_sizeinbase( (mpz_ptr) x, base) + 1;
}



char * Lib_Mpz_Get_Str(char * str , int32_t b, MpzPtr x)
{
    return mpz_get_str(str ,b, (mpz_ptr) x);
}



int32_t Lib_Mpz_Cmp(MpzPtr f, MpzPtr g)
{
    return mpz_cmp( (mpz_ptr) f,  (mpz_ptr) g);
}


void Lib_Mpz_Neg(MpzPtr f, MpzPtr g)
{
    mpz_neg( (mpz_ptr) f,  (mpz_ptr) g);
}





void Lib_Mpz_Add(MpzPtr f, MpzPtr g, MpzPtr h)
{
    mpz_add( (mpz_ptr) f,  (mpz_ptr) g,  (mpz_ptr) h);
}


void Lib_Mpz_Add_Ui(MpzPtr f, MpzPtr g,  uint32_t x)
{
    mpz_add_ui( (mpz_ptr) f,  (mpz_ptr) g,  x);
}


void Lib_Mpz_Add_Si(MpzPtr res, MpzPtr x,  int32_t y)
{
    uint32_t t = (uint32_t) y;
    if (y > 0)
        mpz_add_ui( (mpz_ptr) res,  (mpz_ptr) x,  t);
    else
        mpz_sub_ui( (mpz_ptr) res,  (mpz_ptr) x,  t);
}



void Lib_Mpz_Add_Ui64(MpzPtr f, MpzPtr g,  uint64_t uint64)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, uint64);
    mpz_add( (mpz_ptr) f,  (mpz_ptr) g, z);
    mpz_clear(z);
}



void Lib_Mpz_Add_Si64(MpzPtr f, MpzPtr g,  int64_t sint64)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, sint64);
    mpz_add( (mpz_ptr) f,  (mpz_ptr) g, z);
    mpz_clear(z);
}







void Lib_Mpz_Sub(MpzPtr res, MpzPtr x, MpzPtr y)
{
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) x,  (mpz_ptr) y);
}


void Lib_Mpz_Ui_Sub(MpzPtr res,  uint32_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); mpz_set_ui(z, x);
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) z,  (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Sub_Ui(MpzPtr res, MpzPtr x,  uint32_t y)
{
    mpz_sub_ui( (mpz_ptr) res,  (mpz_ptr) x,  y);
}


void Lib_Mpz_Si_Sub(MpzPtr res, int32_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); mpz_set_si(z, x);
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) z,  (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Sub_Si(MpzPtr res, MpzPtr x, int32_t y)
{
    mpz_t z; mpz_init(z); mpz_set_si(z, y);
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) x,  (mpz_ptr) z);
    mpz_clear(z);
}


void Lib_Mpz_Ui64_Sub(MpzPtr res, uint64_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, x);
    mpz_sub( (mpz_ptr) res, z, (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Sub_Ui64(MpzPtr res, MpzPtr x,  uint64_t y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, y);
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) x, z);
    mpz_clear(z);
}


void Lib_Mpz_Si64_Sub(MpzPtr res, int64_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, x);
    mpz_sub( (mpz_ptr) res, z, (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Sub_Si64(MpzPtr res, MpzPtr x,  int64_t y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, y);
    mpz_sub( (mpz_ptr) res,  (mpz_ptr) x, z);
    mpz_clear(z);
}









void Lib_Mpz_Mul(MpzPtr x, MpzPtr y, MpzPtr z)
{
    mpz_mul( (mpz_ptr) x,  (mpz_ptr) y,  (mpz_ptr) z);
}


void Lib_Mpz_Mul_Si(MpzPtr f, MpzPtr g,  int32_t x)
{
    mpz_mul_si( (mpz_ptr) f,  (mpz_ptr) g,  x);
}


void Lib_Mpz_Mul_Ui(MpzPtr f, MpzPtr g,  uint32_t x)
{
    mpz_mul_ui( (mpz_ptr) f,  (mpz_ptr) g,  x);
}



void Lib_Mpz_Mul_Ui64(MpzPtr f, MpzPtr g,  uint64_t uint64)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, uint64);
    mpz_mul( (mpz_ptr) f,  (mpz_ptr) g, z);
    mpz_clear(z);
}



void Lib_Mpz_Mul_Si64(MpzPtr f, MpzPtr g,  int64_t sint64)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, sint64);
    mpz_mul( (mpz_ptr) f,  (mpz_ptr) g, z);
    mpz_clear(z);
}










void Lib_Mpz_Tdiv_Q(MpzPtr res, MpzPtr x, MpzPtr y)
{
    mpz_tdiv_q( (mpz_ptr) res,  (mpz_ptr) x,  (mpz_ptr) y);
}


void Lib_Mpz_Ui_Tdiv_Q(MpzPtr res,  uint32_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); mpz_set_si(z, x);
    mpz_tdiv_q( (mpz_ptr) res,  (mpz_ptr) z,  (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Tdiv_Q_Ui(MpzPtr res, MpzPtr x,  uint32_t y)
{
    mpz_tdiv_q_ui( (mpz_ptr) res,  (mpz_ptr) x,  y);
}


void Lib_Mpz_Si_Tdiv_Q(MpzPtr res,  int32_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); mpz_set_si(z, x);
    mpz_tdiv_q( (mpz_ptr) res,  (mpz_ptr) z,  (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Tdiv_Q_Si(MpzPtr res, MpzPtr x,  uint32_t y)
{
    mpz_tdiv_q_ui( (mpz_ptr) res,  (mpz_ptr) x,  y);
}



void Lib_Mpz_Ui64_Tdiv_Q(MpzPtr res, uint64_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, x);
    mpz_tdiv_q( (mpz_ptr) res, z, (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Tdiv_Q_Ui64(MpzPtr res, MpzPtr x,  uint64_t y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Ui64(z, y);
    mpz_tdiv_q( (mpz_ptr) res,  (mpz_ptr) x, z);
    mpz_clear(z);
}


void Lib_Mpz_Si64_Tdiv_Q(MpzPtr res, int64_t x, MpzPtr y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, x);
    mpz_tdiv_q( (mpz_ptr) res, z, (mpz_ptr) y);
    mpz_clear(z);
}


void Lib_Mpz_Tdiv_Q_Si64(MpzPtr res, MpzPtr x,  int64_t y)
{
    mpz_t z; mpz_init(z); Lib_Mpz_Set_Si64(z, y);
    mpz_tdiv_q( (mpz_ptr) res,  (mpz_ptr) x, z);
    mpz_clear(z);
}










 void Lib_Mpz_Mul_2exp ( MpzPtr f, MpzPtr g, uint32_t e)
{
    mpz_mul_2exp( (mpz_ptr) f,  (mpz_ptr) g,  e);
}


 void Lib_Mpz_Tdiv_Q_2exp ( MpzPtr f, MpzPtr g, uint32_t e)
{
    mpz_tdiv_q_2exp( (mpz_ptr) f,  (mpz_ptr) g,  e);
}


 void Lib_Mpz_Mod ( MpzPtr f, MpzPtr g, MpzPtr h)
{
    mpz_mod (  (mpz_ptr) f,  (mpz_ptr) g, (mpz_ptr) h);
}


 void Lib_Mpz_Pow_Ui ( MpzPtr f, MpzPtr g, uint32_t e)
{
    mpz_pow_ui( (mpz_ptr) f,  (mpz_ptr) g,  e);
}



 void Lib_Mpz_Complement ( MpzPtr f, MpzPtr g)
{
    mpz_com (  (mpz_ptr) f,  (mpz_ptr) g);
}


 void Lib_Mpz_And ( MpzPtr f, MpzPtr g, MpzPtr h)
{
    mpz_and (  (mpz_ptr) f,  (mpz_ptr) g, (mpz_ptr) h);
}


 void Lib_Mpz_OR ( MpzPtr f, MpzPtr g, MpzPtr h)
{
    mpz_ior (  (mpz_ptr) f,  (mpz_ptr) g, (mpz_ptr) h);
}


 void Lib_Mpz_XOR ( MpzPtr f, MpzPtr g, MpzPtr h)
{
    mpz_xor (  (mpz_ptr) f,  (mpz_ptr) g, (mpz_ptr) h);
}

