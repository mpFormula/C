
#define Use_fmpq

#include "mpNumC.h"

#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"



void Lib_Fmpq_Print(FmpqPtr x)
{
    fmpq_print( (fmpq*) x);
}


void Lib_Fmpq_Init(FmpqPtr* x)
{
    (*x) =  malloc (sizeof(fmpq));
    fmpq_init( (fmpq*) (*x));
}

void Lib_Fmpq_Clear(FmpqPtr x)
{
    fmpq_clear( (fmpq*) x);
    free(x);
}



void Lib_Fmpq_Set(FmpqPtr res, FmpqPtr x)
{
    fmpq_set( (fmpq*) res, (fmpq*) x);
}


void Lib_Fmpq_Set_Ui(FmpqPtr x, uint32_t p)
{
    Lib_Fmpz_Set_Ui( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Ui( fmpq_denref((fmpq*) x), 1);
}


void Lib_Fmpq_Set_Si(FmpqPtr x, int32_t p)
{
    Lib_Fmpz_Set_Si( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si( fmpq_denref((fmpq*) x), 1);
}


void Lib_Fmpq_Set_Ui64(FmpqPtr x, uint64_t p)
{
    Lib_Fmpz_Set_Ui64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Ui( fmpq_denref((fmpq*) x), 1);
}


void Lib_Fmpq_Set_Si64(FmpqPtr x, int64_t p)
{
    Lib_Fmpz_Set_Si64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si( fmpq_denref((fmpq*) x), 1);
}



void Lib_Fmpq_Set_Ui_Ui(FmpqPtr x, uint32_t p, uint32_t q)
{
    Lib_Fmpz_Set_Ui( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Ui( fmpq_denref((fmpq*) x), q);
}


void Lib_Fmpq_Set_Ui_Si(FmpqPtr x, uint32_t p, int32_t q)
{
    Lib_Fmpz_Set_Ui( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si( fmpq_denref((fmpq*) x), q);
}


void Lib_Fmpq_Set_Si_Ui(FmpqPtr x, int32_t p, uint32_t q)
{
    fmpq_set_si( (fmpq*) x, p, q);
}



void Lib_Fmpq_Set_Si_Si(FmpqPtr x, int32_t p, int32_t q)
{
    Lib_Fmpz_Set_Si( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si( fmpq_denref((fmpq*) x), q);
}




void Lib_Fmpq_Set_Ui64_Ui64(FmpqPtr x, uint64_t p, uint64_t q)
{
    Lib_Fmpz_Set_Ui64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Ui64( fmpq_denref((fmpq*) x), q);
}


void Lib_Fmpq_Set_Ui64_Si64(FmpqPtr x, uint64_t  p, int64_t  q)
{
    Lib_Fmpz_Set_Ui64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si64( fmpq_denref((fmpq*) x), q);
}


void Lib_Fmpq_Set_Si64_Ui64(FmpqPtr x, int64_t  p, uint64_t  q)
{
    Lib_Fmpz_Set_Si64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Ui64( fmpq_denref((fmpq*) x), q);
}



void Lib_Fmpq_Set_Si64_Si64(FmpqPtr x, int64_t  p, int64_t  q)
{
    Lib_Fmpz_Set_Si64( fmpq_numref((fmpq*) x), p);
    Lib_Fmpz_Set_Si64( fmpq_denref((fmpq*) x), q);
}



void Lib_Fmpq_Set_Fmpz_Frac(FmpqPtr x, FmpzPtr p, FmpzPtr q)
{
    fmpq_set_fmpz_frac( (fmpq*) x, (fmpz*) p, (fmpz*) q);
}


void Lib_Fmpq_Set_Fmpz(FmpqPtr x, FmpzPtr p)
{
    fmpz_set( fmpq_numref((fmpq*) x), (fmpz*) p);
    fmpz_set_si( fmpq_denref((fmpq*) x), 1);
}


void Lib_Fmpq_Set_Num(FmpqPtr x, FmpzPtr p)
{
    fmpz_set( fmpq_numref((fmpq*) x), (fmpz*) p);
}


void Lib_Fmpq_Set_Den(FmpqPtr x, FmpzPtr p)
{
    fmpz_set( fmpq_denref((fmpq*) x), (fmpz*) p);
}



void Lib_Fmpq_Set_D(FmpqPtr x, double d)
{
mpq_t rop;
mpq_init (rop);
mpq_set_d (rop, d);
fmpq_set_mpq ( (fmpq*)x ,rop);
mpq_clear (rop);
}


int32_t Lib_Fmpq_Set_Str(FmpqPtr x, const char * str , int32_t b)
{
mpq_t rop;
mpq_init (rop);
mpq_set_str (rop, str, b);
fmpq_set_mpq ( (fmpq*)x ,rop);
mpq_clear (rop);
 //   return fmpq_set_str( (fmpq*) x, str, b);
 return 1;
}


double Lib_Fmpq_Get_D(FmpqPtr x)
{
    mpq_t rop;
    mpq_init (rop);
    fmpq_get_mpq (rop, (fmpq*)x);

    double d = mpq_get_d (rop);
    mpq_clear (rop);
    return d;
}


uint32_t Lib_Fmpq_Get_Ui(FmpqPtr x)
{
    return (uint32_t) Lib_Fmpq_Get_D(x);
}


int32_t Lib_Fmpq_Get_Si(FmpqPtr x)
{
    return (int32_t) Lib_Fmpq_Get_D(x);
}


void Lib_Fmpq_Get_Fmpz(FmpzPtr res, FmpqPtr x)
{
    Lib_Fmpz_Tdiv_Q((fmpz*) res, fmpq_numref((fmpq*) x), fmpq_denref((fmpq*) x));
}


void Lib_Fmpq_Get_Num(FmpzPtr res, FmpqPtr x)
{
    fmpz_set((fmpz*) res, fmpq_numref((fmpq*) x));
}


void Lib_Fmpq_Get_Den(FmpzPtr res, FmpqPtr x)
{
    fmpz_set((fmpz*) res, fmpq_denref((fmpq*) x));
}


uint64_t Lib_Fmpq_Get_Ui64(FmpqPtr x)
{
    fmpq_t z; fmpq_init(z);
    Lib_Fmpq_Get_Fmpz(z, (fmpq*) x);
    uint64_t res = Lib_Fmpz_Get_Ui64(z);
    fmpq_clear(z);
    return res;
}


int64_t Lib_Fmpq_Get_Si64(FmpqPtr x)
{
    fmpq_t z; fmpq_init(z);
    Lib_Fmpq_Get_Fmpz(z, (fmpq*) x);
    int64_t res = Lib_Fmpz_Get_Si64(z);
    fmpq_clear(z);
    return res;
}



uint32_t Lib_Fmpq_SizeInBase(FmpqPtr x, int32_t base)
{
    return fmpz_sizeinbase( fmpq_numref((fmpq*) x) , base)
         + fmpz_sizeinbase( fmpq_denref((fmpq*) x) , base) + 3;
}


char * Lib_Fmpq_Get_Str(char * str , int32_t b, FmpqPtr x)
{
    return fmpq_get_str(str ,b, (fmpq*) x);
}



int32_t Lib_Fmpq_Cmp(FmpqPtr f, FmpqPtr g)
{
    return fmpq_cmp( (fmpq*) f,  (fmpq*) g);
}


void Lib_Fmpq_Neg(FmpqPtr res, FmpqPtr x)
{
    fmpq_neg( (fmpq*) res,  (fmpq*) x);
}


void Lib_Fmpq_Add(FmpqPtr res, FmpqPtr x, FmpqPtr y)
{
    fmpq_add( (fmpq*) res,  (fmpq*) x,  (fmpq*) y);
}


void Lib_Fmpq_Add_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Ui(q, y);
    fmpq_add( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}



void Lib_Fmpq_Add_Si(FmpqPtr res, FmpqPtr x, int32_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Si(q, y);
    fmpq_add( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}


void Lib_Fmpq_Add_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Ui64(q, y);
    fmpq_add( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}



void Lib_Fmpq_Add_Si64(FmpqPtr res, FmpqPtr x,  int64_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Si64(q, y);
    fmpq_add( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}






void Lib_Fmpq_Sub(FmpqPtr res, FmpqPtr x, FmpqPtr y)
{
    fmpq_sub( (fmpq*) res,  (fmpq*) x,  (fmpq*) y);
}


void Lib_Fmpq_Ui_Sub(FmpqPtr res,  uint32_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui(z, x);
    fmpq_sub( (fmpq*) res, z,  (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Sub_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui(z, y);
    fmpq_sub( (fmpq*) res,  (fmpq*) y, z);
    fmpq_clear(z);
}


void Lib_Fmpq_Si_Sub(FmpqPtr res, int32_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si(z, x);
    fmpq_sub( (fmpq*) res,  (fmpq*) z,  (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Sub_Si(FmpqPtr res, FmpqPtr x, int32_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si(z, y);
    fmpq_sub( (fmpq*) res,  (fmpq*) x,  (fmpq*) z);
    fmpq_clear(z);
}


void Lib_Fmpq_Ui64_Sub(FmpqPtr res, uint64_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui64(z, x);
    fmpq_sub( (fmpq*) res, z, (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Sub_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui64(z, y);
    fmpq_sub( (fmpq*) res,  (fmpq*) x, z);
    fmpq_clear(z);
}


void Lib_Fmpq_Si64_Sub(FmpqPtr res, int64_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si64(z, x);
    fmpq_sub( (fmpq*) res, z, (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Sub_Si64(FmpqPtr res, FmpqPtr x,  int64_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si64(z, y);
    fmpq_sub( (fmpq*) res,  (fmpq*) x, z);
    fmpq_clear(z);
}











void Lib_Fmpq_Mul(FmpqPtr res, FmpqPtr x, FmpqPtr y)
{
    fmpq_mul( (fmpq*) res,  (fmpq*) x,  (fmpq*) y);
}


void Lib_Fmpq_Mul_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Ui(q, y);
    fmpq_mul( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}



void Lib_Fmpq_Mul_Si(FmpqPtr res, FmpqPtr x, int32_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Si(q, y);
    fmpq_mul( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}


void Lib_Fmpq_Mul_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Ui64(q, y);
    fmpq_mul( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}



void Lib_Fmpq_Mul_Si64(FmpqPtr res, FmpqPtr x,  int64_t y)
{
    fmpq_t q; fmpq_init(q); Lib_Fmpq_Set_Si64(q, y);
    fmpq_mul( (fmpq*) res,  (fmpq*) x, q);
    fmpq_clear(q);
}














void Lib_Fmpq_Div(FmpqPtr res, FmpqPtr x, FmpqPtr y)
{
    fmpq_div( (fmpq*) res,  (fmpq*) x,  (fmpq*) y);
}


void Lib_Fmpq_Ui_Div(FmpqPtr res,  uint32_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui(z, x);
    fmpq_div( (fmpq*) res, z,  (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Div_Ui(FmpqPtr res, FmpqPtr x,  uint32_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui(z, y);
    fmpq_div( (fmpq*) res,  (fmpq*) y, z);
    fmpq_clear(z);
}


void Lib_Fmpq_Si_Div(FmpqPtr res, int32_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si(z, x);
    fmpq_div( (fmpq*) res,  (fmpq*) z,  (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Div_Si(FmpqPtr res, FmpqPtr x, int32_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si(z, y);
    fmpq_div( (fmpq*) res,  (fmpq*) x,  (fmpq*) z);
    fmpq_clear(z);
}


void Lib_Fmpq_Ui64_Div(FmpqPtr res, uint64_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui64(z, x);
    fmpq_div( (fmpq*) res, z, (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Div_Ui64(FmpqPtr res, FmpqPtr x,  uint64_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Ui64(z, y);
    fmpq_div( (fmpq*) res,  (fmpq*) x, z);
    fmpq_clear(z);
}


void Lib_Fmpq_Si64_Div(FmpqPtr res, int64_t x, FmpqPtr y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si64(z, x);
    fmpq_div( (fmpq*) res, z, (fmpq*) y);
    fmpq_clear(z);
}


void Lib_Fmpq_Div_Si64(FmpqPtr res, FmpqPtr x,  int64_t y)
{
    fmpq_t z; fmpq_init(z); Lib_Fmpq_Set_Si64(z, y);
    fmpq_div( (fmpq*) res,  (fmpq*) x, z);
    fmpq_clear(z);
}








void Lib_Fmpq_Mul_2exp(FmpqPtr x, FmpqPtr y, uint32_t e)
{
    fmpq_mul_2exp(  (fmpq*) x,  (fmpq*) y,  e);
}


void Lib_Fmpq_Div_2exp(FmpqPtr x, FmpqPtr y, uint32_t e)
{
    fmpq_div_2exp(  (fmpq*) x,  (fmpq*) y,  e);
}

void Lib_Fmpq_Div_Fmpz(FmpqPtr x, FmpqPtr y, FmpzPtr z)
{
    fmpq_div_fmpz( (fmpq*) x,  (fmpq*) y,  (fmpz*) z);
}


 int32_t Lib_Fmpq_Mod_Fmpz ( FmpqPtr f, FmpqPtr g, FmpzPtr h)
{
    return fmpq_mod_fmpz (  (fmpz*) f,  (fmpq*) g, (fmpz*) h);
}


 void Lib_Fmpq_Pow_Si ( FmpqPtr f, FmpqPtr g, int32_t e)
{
    fmpq_pow_si( (fmpq*) f,  (fmpq*) g,  e);
}





//***************************************************



void Lib_Fmpq_Mat_Print_Pretty(FmpqMatPtr A)
{
    fmpq_mat_print( (fmpq_mat_struct*) A);
}


void Lib_Fmpq_Mat_Init(FmpqMatPtr* A, int32_t i, int32_t j)
{
    (*A) =  malloc (sizeof(fmpq_mat_struct));
    fmpq_mat_init( (fmpq_mat_struct*) (*A), i, j);
}

void Lib_Fmpq_Mat_Clear(FmpqMatPtr A)
{
    fmpq_mat_clear( (fmpq_mat_struct*) A);
    free(A);
}


void Lib_Fmpq_Mat_Mul(FmpqMatPtr X, FmpqMatPtr Y, FmpqMatPtr Z)
{
    fmpq_mat_mul( (fmpq_mat_struct*) X,  (fmpq_mat_struct*) Y,  (fmpq_mat_struct*) Z);
}



void Lib_Fmpq_Mat_Set_Si(FmpqMatPtr A, int32_t i, int32_t j, int32_t p, int32_t q)
{
    fmpq_set_si ( fmpq_mat_entry ((fmpq_mat_struct*)A, i, j), p, q);
}






#undef  Use_fmpq
