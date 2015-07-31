
#define Use_Fmpz

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



void Lib_Fmpz_Set_Ui(FmpzPtr x, unsigned int u)
{
    fmpz_set_ui( (fmpz*) x, u);
}


void Lib_Fmpz_Set_Si(FmpzPtr x, int u)
{
    fmpz_set_si( (fmpz*) x, u);
}


void Lib_Fmpz_Set_D(FmpzPtr x, double u)
{
    fmpz_set_d( (fmpz*) x, u);
}


int Lib_Fmpz_Set_Str(FmpzPtr x, const char * str , int b)
{
    return fmpz_set_str( (fmpz*) x, str, b);
}


unsigned int Lib_Fmpz_Get_Ui(FmpzPtr x)
{
    return fmpz_get_ui( (fmpz*) x);
}


int Lib_Fmpz_Get_Si(FmpzPtr x)
{
    return fmpz_get_si( (fmpz*) x);
}


double Lib_Fmpz_Get_D(FmpzPtr x)
{
    return fmpz_get_d( (fmpz*) x);
}


char * Lib_Fmpz_Get_Str(char * str , int b, FmpzPtr x)
{
    return fmpz_get_str(str ,b, (fmpz*) x);
}



int Lib_Fmpz_Cmp(FmpzPtr f, FmpzPtr g)
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


void Lib_Fmpz_Add_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x)
{
    fmpz_add_ui( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Sub(FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_sub( (fmpz*) f,  (fmpz*) g,  (fmpz*) h);
}


void Lib_Fmpz_Sub_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x)
{
    fmpz_sub_ui( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Mul(FmpzPtr x, FmpzPtr y, FmpzPtr z)
{
    fmpz_mul( (fmpz*) x,  (fmpz*) y,  (fmpz*) z);
}


void Lib_Fmpz_Mul_Si(FmpzPtr f, FmpzPtr g,  int x)
{
    fmpz_mul_si( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Mul_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x)
{
    fmpz_mul_ui( (fmpz*) f,  (fmpz*) g,  x);
}




void Lib_Fmpz_Tdiv_Q(FmpzPtr x, FmpzPtr y, FmpzPtr z)
{
    fmpz_tdiv_q( (fmpz*) x,  (fmpz*) y,  (fmpz*) z);
}


void Lib_Fmpz_Tdiv_Q_Si(FmpzPtr f, FmpzPtr g,  int x)
{
    fmpz_tdiv_q_si( (fmpz*) f,  (fmpz*) g,  x);
}


void Lib_Fmpz_Tdiv_Q_Ui(FmpzPtr f, FmpzPtr g,  unsigned int x)
{
    fmpz_tdiv_q_ui( (fmpz*) f,  (fmpz*) g,  x);
}



 void Lib_Fmpz_Mul_2exp ( FmpzPtr f, FmpzPtr g, unsigned int e)
{
    fmpz_mul_2exp( (fmpz*) f,  (fmpz*) g,  e);
}


 void Lib_Fmpz_Tdiv_Q_2exp ( FmpzPtr f, FmpzPtr g, unsigned int e)
{
    fmpz_tdiv_q_2exp( (fmpz*) f,  (fmpz*) g,  e);
}


 void Lib_Fmpz_Mod ( FmpzPtr f, FmpzPtr g, FmpzPtr h)
{
    fmpz_mod (  (fmpz*) f,  (fmpz*) g, (fmpz*) h);
}


 void Lib_Fmpz_Pow_Ui ( FmpzPtr f, FmpzPtr g, unsigned int e)
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


void Lib_Fmpz_Mat_Init(FmpzMatPtr* A, long i, long j)
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



void Lib_Fmpz_Mat_Set_Ui(FmpzMatPtr A, long i, long j, long u)
{
    fmpz_set_ui ( fmpz_mat_entry ((fmpz_mat_struct*)A, i, j), u);
}




#undef  Use_Fmpz
