
#include "mpNumC_Short.h"

#include <gmp.h>
#include <mpfr.h>
#include <stdlib.h>


void Lib_Mpq_Init(MpqPtr* x)
{
    (*x) =  malloc (sizeof(__mpz_struct));
    mpq_init( (mpq_ptr) (*x));
}

void Lib_Mpq_Clear(MpqPtr x)
{
    mpq_clear( (mpq_ptr) x);
    free(x);
}



void Lib_Mpq_Set(MpqPtr res, MpqPtr x)
{
    mpq_set( (mpq_ptr) res, (mpq_ptr) x);
}


void Lib_Mpq_Set_Ui(MpqPtr x, uint32_t p)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_ui( mpq_denref((mpq_ptr) x), 1);
}


void Lib_Mpq_Set_Si(MpqPtr x, int32_t p)
{
    mpz_set_si( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), 1);
}


void Lib_Mpq_Set_Ui64(MpqPtr x, uint64_t p)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_ui( mpq_denref((mpq_ptr) x), 1);

//    Lib_Mpz_Set_Ui64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Ui( mpq_denref((mpq_ptr) x), 1);

}


void Lib_Mpq_Set_Si64(MpqPtr x, int64_t p)
{
    mpz_set_si( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), 1);

//    Lib_Mpz_Set_Si64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Si( mpq_denref((mpq_ptr) x), 1);
}



void Lib_Mpq_Set_Ui_Ui(MpqPtr x, uint32_t p, uint32_t q)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_ui( mpq_denref((mpq_ptr) x), q);
}


void Lib_Mpq_Set_Ui_Si(MpqPtr x, uint32_t p, int32_t q)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), q);
}


void Lib_Mpq_Set_Si_Ui(MpqPtr x, int32_t p, uint32_t q)
{
    mpq_set_si( (mpq_ptr) x, p, q);
}



void Lib_Mpq_Set_Si_Si(MpqPtr x, int32_t p, int32_t q)
{
    mpz_set_si( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), q);
}




void Lib_Mpq_Set_Ui64_Ui64(MpqPtr x, uint64_t p, uint64_t q)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_ui( mpq_denref((mpq_ptr) x), q);

//    Lib_Mpz_Set_Ui64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Ui64( mpq_denref((mpq_ptr) x), q);

}


void Lib_Mpq_Set_Ui64_Si64(MpqPtr x, uint64_t  p, int64_t  q)
{
    mpz_set_ui( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), q);

//    Lib_Mpz_Set_Ui64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Si64( mpq_denref((mpq_ptr) x), q);

}


void Lib_Mpq_Set_Si64_Ui64(MpqPtr x, int64_t  p, uint64_t  q)
{
    mpz_set_si( mpq_numref((mpq_ptr) x), p);
    mpz_set_ui( mpq_denref((mpq_ptr) x), q);

//    Lib_Mpz_Set_Si64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Ui64( mpq_denref((mpq_ptr) x), q);

}



void Lib_Mpq_Set_Si64_Si64(MpqPtr x, int64_t  p, int64_t  q)
{
    mpz_set_si( mpq_numref((mpq_ptr) x), p);
    mpz_set_si( mpq_denref((mpq_ptr) x), q);

//    Lib_Mpz_Set_Si64( mpq_numref((mpq_ptr) x), p);
//    Lib_Mpz_Set_Si64( mpq_denref((mpq_ptr) x), q);

}



void Lib_Mpq_Set_Mpz(MpqPtr x, MpzPtr p)
{
    mpz_set( mpq_numref((mpq_ptr) x), (mpz_ptr) p);
    mpz_set_si( mpq_denref((mpq_ptr) x), 1);
}


void Lib_Mpq_Set_Num(MpqPtr x, MpzPtr p)
{
    mpz_set( mpq_numref((mpq_ptr) x), (mpz_ptr) p);
}


void Lib_Mpq_Set_Den(MpqPtr x, MpzPtr p)
{
    mpz_set( mpq_denref((mpq_ptr) x), (mpz_ptr) p);
}



void Lib_Mpq_Set_D(MpqPtr x, double d)
{
mpq_set_d ((mpq_ptr)x, d);
}


int32_t Lib_Mpq_Set_Str(MpqPtr x, const char * str , int32_t b)
{
    return mpq_set_str ((mpq_ptr) x, str, b);
}


double Lib_Mpq_Get_D(MpqPtr x)
{
    return mpq_get_d ((mpq_ptr) x);
}


uint32_t Lib_Mpq_Get_Ui(MpqPtr x)
{
    return (uint32_t) mpq_get_d( (mpq_ptr) x);
}


int32_t Lib_Mpq_Get_Si(MpqPtr x)
{
    return (int32_t) mpq_get_d( (mpq_ptr) x);
}


void Lib_Mpq_Get_Mpz(MpzPtr res, MpqPtr x)
{
    mpz_tdiv_q((mpz_ptr) res, mpq_numref((mpq_ptr) x), mpq_denref((mpq_ptr) x));
}


void Lib_Mpq_Get_Num(MpzPtr res, MpqPtr x)
{
    mpz_set((mpz_ptr) res, mpq_numref((mpq_ptr) x));
}


void Lib_Mpq_Get_Den(MpzPtr res, MpqPtr x)
{
    mpz_set((mpz_ptr) res, mpq_denref((mpq_ptr) x));
}


uint64_t Lib_Mpq_Get_Ui64(MpqPtr x)
{
    return (uint64_t) mpq_get_d( (mpq_ptr) x);


//    mpq_t z; mpq_init(z);
//    Lib_Mpq_Get_Mpz(z, (mpq_ptr) x);
//    uint64_t res = Lib_Mpz_Get_Ui64(z);
//    mpq_clear(z);
//    return res;
}


int64_t Lib_Mpq_Get_Si64(MpqPtr x)
{
    return (int64_t) mpq_get_d( (mpq_ptr) x);

//    mpq_t z; mpq_init(z);
//    Lib_Mpq_Get_Mpz(z, (mpq_ptr) x);
//    int64_t res = Lib_Mpz_Get_Si64(z);
//    mpq_clear(z);
//    return res;


}



uint32_t Lib_Mpq_SizeInBase(MpqPtr x, int32_t base)
{
    return mpz_sizeinbase( mpq_numref((mpq_ptr) x) , base)
         + mpz_sizeinbase( mpq_denref((mpq_ptr) x) , base) + 3;
}


char * Lib_Mpq_Get_Str(char * str , int32_t b, MpqPtr x)
{
    return mpq_get_str(str ,b, (mpq_ptr) x);
}



int32_t Lib_Mpq_Cmp(MpqPtr f, MpqPtr g)
{
    return mpq_cmp( (mpq_ptr) f,  (mpq_ptr) g);
}


void Lib_Mpq_Neg(MpqPtr res, MpqPtr x)
{
    mpq_neg( (mpq_ptr) res,  (mpq_ptr) x);
}


void Lib_Mpq_Add(MpqPtr res, MpqPtr x, MpqPtr y)
{
    mpq_add( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) y);
}


void Lib_Mpq_Add_Ui(MpqPtr res, MpqPtr x,  uint32_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Ui(q, y);
    mpq_add( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}



void Lib_Mpq_Add_Si(MpqPtr res, MpqPtr x, int32_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Si(q, y);
    mpq_add( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}


void Lib_Mpq_Add_Ui64(MpqPtr res, MpqPtr x,  uint64_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Ui64(q, y);
    mpq_add( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}



void Lib_Mpq_Add_Si64(MpqPtr res, MpqPtr x,  int64_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Si64(q, y);
    mpq_add( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}






void Lib_Mpq_Sub(MpqPtr res, MpqPtr x, MpqPtr y)
{
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) y);
}


void Lib_Mpq_Ui_Sub(MpqPtr res,  uint32_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui(z, x);
    mpq_sub( (mpq_ptr) res, z,  (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Sub_Ui(MpqPtr res, MpqPtr x,  uint32_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui(z, y);
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) y, z);
    mpq_clear(z);
}


void Lib_Mpq_Si_Sub(MpqPtr res, int32_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si(z, x);
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) z,  (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Sub_Si(MpqPtr res, MpqPtr x, int32_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si(z, y);
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) z);
    mpq_clear(z);
}


void Lib_Mpq_Ui64_Sub(MpqPtr res, uint64_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui64(z, x);
    mpq_sub( (mpq_ptr) res, z, (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Sub_Ui64(MpqPtr res, MpqPtr x,  uint64_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui64(z, y);
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) x, z);
    mpq_clear(z);
}


void Lib_Mpq_Si64_Sub(MpqPtr res, int64_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si64(z, x);
    mpq_sub( (mpq_ptr) res, z, (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Sub_Si64(MpqPtr res, MpqPtr x,  int64_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si64(z, y);
    mpq_sub( (mpq_ptr) res,  (mpq_ptr) x, z);
    mpq_clear(z);
}











void Lib_Mpq_Mul(MpqPtr res, MpqPtr x, MpqPtr y)
{
    mpq_mul( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) y);
}


void Lib_Mpq_Mul_Ui(MpqPtr res, MpqPtr x,  uint32_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Ui(q, y);
    mpq_mul( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}



void Lib_Mpq_Mul_Si(MpqPtr res, MpqPtr x, int32_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Si(q, y);
    mpq_mul( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}


void Lib_Mpq_Mul_Ui64(MpqPtr res, MpqPtr x,  uint64_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Ui64(q, y);
    mpq_mul( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}



void Lib_Mpq_Mul_Si64(MpqPtr res, MpqPtr x,  int64_t y)
{
    mpq_t q; mpq_init(q); Lib_Mpq_Set_Si64(q, y);
    mpq_mul( (mpq_ptr) res,  (mpq_ptr) x, q);
    mpq_clear(q);
}














void Lib_Mpq_Div(MpqPtr res, MpqPtr x, MpqPtr y)
{
    mpq_div( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) y);
}


void Lib_Mpq_Ui_Div(MpqPtr res,  uint32_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui(z, x);
    mpq_div( (mpq_ptr) res, z,  (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Div_Ui(MpqPtr res, MpqPtr x,  uint32_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui(z, y);
    mpq_div( (mpq_ptr) res,  (mpq_ptr) y, z);
    mpq_clear(z);
}


void Lib_Mpq_Si_Div(MpqPtr res, int32_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si(z, x);
    mpq_div( (mpq_ptr) res,  (mpq_ptr) z,  (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Div_Si(MpqPtr res, MpqPtr x, int32_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si(z, y);
    mpq_div( (mpq_ptr) res,  (mpq_ptr) x,  (mpq_ptr) z);
    mpq_clear(z);
}


void Lib_Mpq_Ui64_Div(MpqPtr res, uint64_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui64(z, x);
    mpq_div( (mpq_ptr) res, z, (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Div_Ui64(MpqPtr res, MpqPtr x,  uint64_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Ui64(z, y);
    mpq_div( (mpq_ptr) res,  (mpq_ptr) x, z);
    mpq_clear(z);
}


void Lib_Mpq_Si64_Div(MpqPtr res, int64_t x, MpqPtr y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si64(z, x);
    mpq_div( (mpq_ptr) res, z, (mpq_ptr) y);
    mpq_clear(z);
}


void Lib_Mpq_Div_Si64(MpqPtr res, MpqPtr x,  int64_t y)
{
    mpq_t z; mpq_init(z); Lib_Mpq_Set_Si64(z, y);
    mpq_div( (mpq_ptr) res,  (mpq_ptr) x, z);
    mpq_clear(z);
}








void Lib_Mpq_Mul_2exp(MpqPtr x, MpqPtr y, uint32_t e)
{
    mpq_mul_2exp(  (mpq_ptr) x,  (mpq_ptr) y,  e);
}


void Lib_Mpq_Div_2exp(MpqPtr x, MpqPtr y, uint32_t e)
{
    mpq_div_2exp(  (mpq_ptr) x,  (mpq_ptr) y,  e);
}
