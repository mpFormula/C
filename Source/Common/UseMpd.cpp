

#include "mpNumC_Short.h"

#include "mpdecimal.h"



#include <string.h>

   void* GetMpdContext()
    {
        static mpd_context_t* GlobalCtx = NULL;
        if (GlobalCtx == NULL)
        {
            GlobalCtx = (mpd_context_t*)malloc(sizeof(mpd_context_t));
            mpd_init(GlobalCtx, 34);
        }
        return GlobalCtx;
    }




void Lib_Mpd_Printd(MpdPtr x)
{
    mpd_print( (mpd_t *) x);
}


void Lib_Mpd_Init(MpdPtr* x)
{
    (*x) =  mpd_new( (mpd_context_t*)GetMpdContext());
    mpd_set_i32((mpd_t*) (*x), 0, (mpd_context_t*) GetMpdContext());
}

void Lib_Mpd_Clear(MpdPtr x)
{
    mpd_del((mpd_t *) x);
}


void Lib_Mpd_Set_Si(MpdPtr x, int32_t a)
{
    mpd_set_i32( (mpd_t *) x, a, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Set_Ui(MpdPtr x, uint32_t a)
{
    mpd_set_u32( (mpd_t *) x, a, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Set_D(MpdPtr x, double d)
{
    char my_string[26];   //To hold . and null
    sprintf(my_string,"%.15E",d);
	mpd_set_string((mpd_t *) x, my_string, (mpd_context_t*) GetMpdContext());
}



void Lib_Mpd_Set_Str(MpdPtr x, const char * str)
{
    mpd_set_string( (mpd_t *) x, str, (mpd_context_t*) GetMpdContext());
}



uint32_t Lib_Mpd_Get_Ui(MpdPtr x)
{
    return mpd_get_u32( (mpd_t *) x, (mpd_context_t*) GetMpdContext());
}


int32_t Lib_Mpd_Get_Si(MpdPtr x)
{
    return mpd_get_i32( (mpd_t *) x, (mpd_context_t*) GetMpdContext());
}



double Lib_Mpd_Get_D(MpdPtr x)
{
    char *s = mpd_to_sci((mpd_t *) x, 1);
    return atof(s);
}



uint32_t Lib_Mpd_SizeInBase10(MpdPtr x)
{
    char *src = mpd_to_sci((mpd_t *) x, 1);
    uint32_t res = strlen(src) + 1;
    free(src);
    return res;
}


char * Lib_Mpd_Get_Str(char * dest , MpdPtr x)
{
    char * src = mpd_to_sci((mpd_t *) x, 1);
    char * res =  strcpy(dest, src);
    free(src);
    return res;
}


int32_t Lib_Mpd_Cmp(MpdPtr f, MpdPtr g)
{
    return mpd_cmp((mpd_t *) f, (mpd_t *) g, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Neg(MpdPtr f, MpdPtr g)
{
    mpd_minus( (mpd_t *) f,  (mpd_t *) g, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Add(MpdPtr f, MpdPtr g, MpdPtr h)
{
    mpd_add( (mpd_t *) f,  (mpd_t *) g,  (mpd_t *) h, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Add_Ui(MpdPtr f, MpdPtr g,  uint32_t x)
{
    mpd_add_u32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Sub(MpdPtr f, MpdPtr g, MpdPtr h)
{
    mpd_sub( (mpd_t *) f,  (mpd_t *) g,  (mpd_t *) h, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Sub_Ui(MpdPtr f, MpdPtr g,  uint32_t x)
{
    mpd_sub_u32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Mul(MpdPtr x, MpdPtr y, MpdPtr z)
{
    mpd_mul( (mpd_t *) x,  (mpd_t *) y,  (mpd_t *) z, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Mul_Si(MpdPtr f, MpdPtr g,  int32_t x)
{
    mpd_mul_i32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Mul_Ui(MpdPtr f, MpdPtr g,  uint32_t x)
{
    mpd_mul_u32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}



void Lib_Mpd_Div(MpdPtr x, MpdPtr y, MpdPtr z)
{
    mpd_div( (mpd_t *) x,  (mpd_t *) y,  (mpd_t *) z, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Div_Si(MpdPtr f, MpdPtr g,  int32_t x)
{
    mpd_div_i32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}


void Lib_Mpd_Div_Ui(MpdPtr f, MpdPtr g,  uint32_t x)
{
    mpd_div_u32( (mpd_t *) f,  (mpd_t *) g,  x, (mpd_context_t*) GetMpdContext());
}


//
//void Lib_Mpd_Mul_2exp(MpdPtr x, MpdPtr y,  int32_t e, int32_t rnd)
//{
//    mpd_mul_2si(  (mpd_t *) x,  (mpd_t *) y,  e, (mpd_context_t*) GetMpdContext());
//}
//
//
//void Lib_Mpd_Div_2exp(MpdPtr x, MpdPtr y,  int32_t e, int32_t rnd)
//{
//    mpd_div_2si(  (mpd_t *) x,  (mpd_t *) y,  e, (mpd_context_t*) GetMpdContext());
//}

//void Lib_Mpd_Div_Fmpz(MpdPtr x, MpdPtr y, FmpzPtr z, int32_t rnd)
//{
//    mpd_div_fmpz( (mpd_t *) x,  (mpd_t *) y,  (fmpz*) z, (mpd_context_t*) GetMpdContext());
//}

//
// int32_t Lib_Mpd_Mod_Fmpz ( MpdPtr f, MpdPtr g, FmpzPtr h)
//{
//    return mpd_mod_fmpz (  (fmpz*) f,  (mpd_t *) g, (fmpz*) h);
//}

//
// void Lib_Mpd_Pow_Si ( MpdPtr f, MpdPtr g, int32_t e, int32_t rnd)
//{
//    mpd_pow_si( (mpd_t *) f,  (mpd_t *) g,  e, (mpd_context_t*) GetMpdContext());
//}


void Lib_Mpd_Pow(MpdPtr x, MpdPtr y, MpdPtr z)
{
    mpd_pow( (mpd_t *) x,  (mpd_t *) y,  (mpd_t *) z, (mpd_context_t*) GetMpdContext());
}



























//***************************************************


//
//void Lib_Mpd_Mat_Print_Pretty(MpdMatPtr A, int32_t digits)
//{
//    mpd_mat_printd( (mpd_mat_struct*) A, digits);
//}
//
//
//void Lib_Mpd_Mat_Init(MpdMatPtr* A, int32_t i, int32_t j)
//{
//    (*A) =  malloc (sizeof(mpd_mat_struct));
//    mpd_mat_init( (mpd_mat_struct*) (*A), i, j);
//}
//
//void Lib_Mpd_Mat_Clear(MpdMatPtr A)
//{
//    mpd_mat_clear( (mpd_mat_struct*) A);
//    free(A);
//}
//
//
//void Lib_Mpd_Mat_Mul(MpdMatPtr X, MpdMatPtr Y, MpdMatPtr Z, int32_t digits)
//{
//    mpd_mat_mul( (mpd_mat_struct*) X,  (mpd_mat_struct*) Y,  (mpd_mat_struct*) Z, digits);
//}
//
//
//
//void Lib_Mpd_Mat_Set_Ui(MpdMatPtr A, int32_t i, int32_t j, int32_t u)
//{
//    mpd_set_ui ( mpd_mat_entry ((mpd_mat_struct*)A, i, j), u);
//}



