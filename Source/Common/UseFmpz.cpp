
#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include <fmpz.h>
#include <fmpz_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"
#include <inttypes.h>




void Lib_Flint_Rand_Init(FlintRandPtr* state)
{
    (*state) =  malloc (sizeof(flint_rand_s));
    flint_randinit( (flint_rand_s*) (*state));
}


void Lib_Flint_Rand_Clear(FlintRandPtr state)
{
    flint_randclear( (flint_rand_s*) (state));
}



void Lib_Fmpz_RandM(FmpzPtr f, FlintRandPtr state, FmpzPtr m)
{
    fmpz_randm((fmpz*) f,  (flint_rand_s*) state, (fmpz*) m);
}



//****************************************************************************


void Lib_Flint_Printf(const char * Title)
{
    flint_printf(Title);
}

void Lib_Fmpz_Print(FmpzPtr x)
{
    fmpz_print( (fmpz*) x);
}


void Lib_Fmpz_Init(FmpzPtr* x)
{
    (*x) =  malloc (sizeof(fmpz));
    fmpz_init( (fmpz*) (*x));
}


void Lib_Fmpz_Clear(FmpzPtr x)
{
    fmpz_clear( (fmpz*) x);
    free(x);
}


void Lib_Fmpz_Set(FmpzPtr res, FmpzPtr x)
{
    fmpz_set( (fmpz*) res, (fmpz*) x);
}


void Lib_Fmpz_Set_Ui(FmpzPtr x, uint32_t u)
{
    fmpz_set_ui( (fmpz*) x, u);
}


void Lib_Fmpz_Set_Si(FmpzPtr x, int32_t u)
{
    fmpz_set_si( (fmpz*) x, u);
}



void Lib_Fmpz_Set_Ui64(MpfcPtr x, uint64_t uint64)
{
//    printf("Received %llu", uint64);
    int32_t low32, high32;
    low32 = (uint32_t)uint64;
    high32 = (uint64_t)uint64 >> 32;
    fmpz_set_uiui((fmpz*) x, high32, low32);
}


void Lib_Fmpz_Set_Si64(MpfcPtr x, int64_t sint64)
{
//    printf("Received %lld", sint64);
    int32_t low32, high32;
    low32 = (uint32_t)sint64;
    high32 = (uint64_t)sint64 >> 32;
    if (sint64 >= 0)
        {
//        printf("uiui");
        fmpz_set_uiui((fmpz*) x, high32, low32);
        }

    else
        {
//        printf("negui");
        fmpz_neg_uiui((fmpz*) x, high32, low32);
        }
}




void Lib_Fmpz_Set_D(FmpzPtr x, double u)
{
    fmpz_set_d( (fmpz*) x, u);
}


int32_t Lib_Fmpz_Set_Str(FmpzPtr x, const char * str , int32_t b)
{
    return fmpz_set_str( (fmpz*) x, str, b);
}




uint32_t Lib_Fmpz_Get_Ui(FmpzPtr x)
{
    return fmpz_get_ui( (fmpz*) x);
}


int32_t Lib_Fmpz_Get_Si(FmpzPtr x)
{
    return fmpz_get_si( (fmpz*) x);
}


uint64_t Lib_Fmpz_Get_Ui64(FmpzPtr x)
{
    char * str = fmpz_get_str(NULL , 10, (fmpz*) x);
    uint64_t llui = strtoull (str, NULL, 10);
    return llui;
}


int64_t Lib_Fmpz_Get_Si64(FmpzPtr x)
{
    char * str = fmpz_get_str(NULL , 10, (fmpz*) x);
    int64_t lli = strtoll (str, NULL, 10);
    return lli;
}




double Lib_Fmpz_Get_D(FmpzPtr x)
{
    return fmpz_get_d( (fmpz*) x);
}


uint32_t Lib_Fmpz_SizeInBase(FmpzPtr x, int32_t base)
{
    return fmpz_sizeinbase( (fmpz*) x, base) + 1;
}



char * Lib_Fmpz_Get_Str(char * str , int32_t b, FmpzPtr x)
{
    return fmpz_get_str(str ,b, (fmpz*) x);
}



int32_t Lib_Fmpz_Cmp(FmpzPtr f, FmpzPtr g)
{
    return fmpz_cmp( (fmpz*) f,  (fmpz*) g);
}


void Lib_Fmpz_Neg(FmpzPtr f, FmpzPtr g)
{
    fmpz_neg( (fmpz*) f,  (fmpz*) g);
}





void Lib_Fmpz_Add(FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_add( (fmpz*) f,  (fmpz*) g,  (fmpz*) h);
}


void Lib_Fmpz_Add_Ui(FmpzPtr f, FmpzPtr g,  uint32_t x)
{
    fmpz_add_ui( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Add_Si(FmpzPtr res, FmpzPtr x,  int32_t y)
{
    uint32_t t = (uint32_t) y;
    if (y > 0)
        fmpz_add_ui( (fmpz*) res,  (fmpz*) x,  t);
    else
        fmpz_sub_ui( (fmpz*) res,  (fmpz*) x,  t);
}



void Lib_Fmpz_Add_Ui64(FmpzPtr f, FmpzPtr g,  uint64_t uint64)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, uint64);
    fmpz_add( (fmpz*) f,  (fmpz*) g, z);
    fmpz_clear(z);
}



void Lib_Fmpz_Add_Si64(FmpzPtr f, FmpzPtr g,  int64_t sint64)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, sint64);
    fmpz_add( (fmpz*) f,  (fmpz*) g, z);
    fmpz_clear(z);
}







void Lib_Fmpz_Sub(FmpzPtr res, FmpzPtr x, FmpzPtr y)
{
    fmpz_sub( (fmpz*) res,  (fmpz*) x,  (fmpz*) y);
}


void Lib_Fmpz_Ui_Sub(FmpzPtr res,  uint32_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); fmpz_set_ui(z, x);
    fmpz_sub( (fmpz*) res,  (fmpz*) z,  (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Sub_Ui(FmpzPtr res, FmpzPtr x,  uint32_t y)
{
    fmpz_sub_ui( (fmpz*) res,  (fmpz*) x,  y);
}


void Lib_Fmpz_Si_Sub(FmpzPtr res, int32_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); fmpz_set_si(z, x);
    fmpz_sub( (fmpz*) res,  (fmpz*) z,  (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Sub_Si(FmpzPtr res, FmpzPtr x, int32_t y)
{
    fmpz_t z; fmpz_init(z); fmpz_set_si(z, y);
    fmpz_sub( (fmpz*) res,  (fmpz*) x,  (fmpz*) z);
    fmpz_clear(z);
}


void Lib_Fmpz_Ui64_Sub(FmpzPtr res, uint64_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, x);
    fmpz_sub( (fmpz*) res, z, (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Sub_Ui64(FmpzPtr res, FmpzPtr x,  uint64_t y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, y);
    fmpz_sub( (fmpz*) res,  (fmpz*) x, z);
    fmpz_clear(z);
}


void Lib_Fmpz_Si64_Sub(FmpzPtr res, int64_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, x);
    fmpz_sub( (fmpz*) res, z, (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Sub_Si64(FmpzPtr res, FmpzPtr x,  int64_t y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, y);
    fmpz_sub( (fmpz*) res,  (fmpz*) x, z);
    fmpz_clear(z);
}









void Lib_Fmpz_Mul(FmpzPtr x, FmpzPtr y, FmpzPtr z)
{
    fmpz_mul( (fmpz*) x,  (fmpz*) y,  (fmpz*) z);
}


void Lib_Fmpz_Mul_Si(FmpzPtr f, FmpzPtr g,  int32_t x)
{
    fmpz_mul_si( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Mul_Ui(FmpzPtr f, FmpzPtr g,  uint32_t x)
{
    fmpz_mul_ui( (fmpz*) f,  (fmpz*) g,  x);
}



void Lib_Fmpz_Mul_Ui64(FmpzPtr f, FmpzPtr g,  uint64_t uint64)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, uint64);
    fmpz_mul( (fmpz*) f,  (fmpz*) g, z);
    fmpz_clear(z);
}



void Lib_Fmpz_Mul_Si64(FmpzPtr f, FmpzPtr g,  int64_t sint64)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, sint64);
    fmpz_mul( (fmpz*) f,  (fmpz*) g, z);
    fmpz_clear(z);
}










void Lib_Fmpz_Tdiv_Q(FmpzPtr res, FmpzPtr x, FmpzPtr y)
{
    fmpz_tdiv_q( (fmpz*) res,  (fmpz*) x,  (fmpz*) y);
}


void Lib_Fmpz_Ui_Tdiv_Q(FmpzPtr res,  uint32_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); fmpz_set_si(z, x);
    fmpz_tdiv_q( (fmpz*) res,  (fmpz*) z,  (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Tdiv_Q_Ui(FmpzPtr res, FmpzPtr x,  uint32_t y)
{
    fmpz_tdiv_q_ui( (fmpz*) res,  (fmpz*) x,  y);
}


void Lib_Fmpz_Si_Tdiv_Q(FmpzPtr res,  int32_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); fmpz_set_si(z, x);
    fmpz_tdiv_q( (fmpz*) res,  (fmpz*) z,  (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Tdiv_Q_Si(FmpzPtr res, FmpzPtr x,  int32_t y)
{
    fmpz_tdiv_q_si( (fmpz*) res,  (fmpz*) x,  y);
}



void Lib_Fmpz_Ui64_Tdiv_Q(FmpzPtr res, uint64_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, x);
    fmpz_tdiv_q( (fmpz*) res, z, (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Tdiv_Q_Ui64(FmpzPtr res, FmpzPtr x,  uint64_t y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Ui64(z, y);
    fmpz_tdiv_q( (fmpz*) res,  (fmpz*) x, z);
    fmpz_clear(z);
}


void Lib_Fmpz_Si64_Tdiv_Q(FmpzPtr res, int64_t x, FmpzPtr y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, x);
    fmpz_tdiv_q( (fmpz*) res, z, (fmpz*) y);
    fmpz_clear(z);
}


void Lib_Fmpz_Tdiv_Q_Si64(FmpzPtr res, FmpzPtr x,  int64_t y)
{
    fmpz_t z; fmpz_init(z); Lib_Fmpz_Set_Si64(z, y);
    fmpz_tdiv_q( (fmpz*) res,  (fmpz*) x, z);
    fmpz_clear(z);
}










 void Lib_Fmpz_Mul_2exp ( FmpzPtr f, FmpzPtr g, uint32_t e)
{
    fmpz_mul_2exp( (fmpz*) f,  (fmpz*) g,  e);
}


 void Lib_Fmpz_Tdiv_Q_2exp ( FmpzPtr f, FmpzPtr g, uint32_t e)
{
    fmpz_tdiv_q_2exp( (fmpz*) f,  (fmpz*) g,  e);
}


 void Lib_Fmpz_Mod ( FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_mod (  (fmpz*) f,  (fmpz*) g, (fmpz*) h);
}


 void Lib_Fmpz_Pow_Ui ( FmpzPtr f, FmpzPtr g, uint32_t e)
{
    fmpz_pow_ui( (fmpz*) f,  (fmpz*) g,  e);
}



 void Lib_Fmpz_Complement ( FmpzPtr f, FmpzPtr g)
{
    fmpz_complement (  (fmpz*) f,  (fmpz*) g);
}


 void Lib_Fmpz_And ( FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_and (  (fmpz*) f,  (fmpz*) g, (fmpz*) h);
}


 void Lib_Fmpz_OR ( FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_or (  (fmpz*) f,  (fmpz*) g, (fmpz*) h);
}


 void Lib_Fmpz_XOR ( FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_xor (  (fmpz*) f,  (fmpz*) g, (fmpz*) h);
}



//***************************************************



void Lib_Fmpz_Mat_Print_Pretty(FmpzMatPtr A)
{
    fmpz_mat_print_pretty( (fmpz_mat_struct*) A);
}


void Lib_Fmpz_Mat_Init(FmpzMatPtr* A, int32_t i, int32_t j)
{
    (*A) =  malloc (sizeof(fmpz_mat_struct));
    fmpz_mat_init( (fmpz_mat_struct*) (*A), i, j);
}

void Lib_Fmpz_Mat_Clear(FmpzMatPtr A)
{
    fmpz_mat_clear( (fmpz_mat_struct*) A);
    free(A);
}


void Lib_Fmpz_Mat_Mul(FmpzMatPtr X, FmpzMatPtr Y, FmpzMatPtr Z)
{
    fmpz_mat_mul( (fmpz_mat_struct*) X,  (fmpz_mat_struct*) Y,  (fmpz_mat_struct*) Z);
}



void Lib_Fmpz_Mat_Set_Ui(FmpzMatPtr A, int32_t i, int32_t j, int32_t u)
{
    fmpz_set_ui ( fmpz_mat_entry ((fmpz_mat_struct*)A, i, j), u);
}

