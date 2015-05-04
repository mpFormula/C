
#include "libEigen.h"
#include "MpMathToNative.h"


#define MP_FUNCTION_INIT \
    (*y0).resizeLike(*x0); \
    int r = (long) (*x0).rows(); \
    int c = (long) (*x0).cols();


#if defined (Use_Mpfr) ||  defined (Use_Mpfi) || defined (Use_Arb) || defined (Use_Mpq) || defined (Use_Mpdec)

void mpMath_mpType_Functions0(long what, mpMatrix *y0)
{
int r = (long) (*y0).rows(); \
int c = (long) (*y0).cols();

int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      char* s = npFunction00s(dps, FunctionEnum);
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}


void mpMath_mpType_Functions1(long what, mpMatrix *y0, mpMatrix *x0)
{
MP_FUNCTION_INIT
int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      std::string s0 = ((*x0)(i, j)).toString();
      char* s = npFunction01s(dps, FunctionEnum, s0.c_str());
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}



void mpMath_mpType_Functions2(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1)
{
MP_FUNCTION_INIT
int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      std::string s0 = ((*x0)(i, j)).toString();
      std::string s1 = ((*x1)(i, j)).toString();
      char* s = npFunction02s(dps, FunctionEnum, s0.c_str(), s1.c_str());
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}



void mpMath_mpType_Functions3(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2)
{
MP_FUNCTION_INIT
int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      std::string s0 = ((*x0)(i, j)).toString();
      std::string s1 = ((*x1)(i, j)).toString();
      std::string s2 = ((*x2)(i, j)).toString();
      char* s = npFunction03s(dps, FunctionEnum, s0.c_str(), s1.c_str(), s2.c_str());
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}



void mpMath_mpType_Functions4(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2, mpMatrix *x3)
{
MP_FUNCTION_INIT
int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      std::string s0 = ((*x0)(i, j)).toString();
      std::string s1 = ((*x1)(i, j)).toString();
      std::string s2 = ((*x2)(i, j)).toString();
      std::string s3 = ((*x3)(i, j)).toString();
      char* s = npFunction04s(dps, FunctionEnum, s0.c_str(), s1.c_str(), s2.c_str(), s3.c_str());
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}


void mpMath_mpType_Functions5(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2, mpMatrix *x3, mpMatrix *x4)
{
MP_FUNCTION_INIT
int dps = 100;
int FunctionEnum = what;
for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {
      std::string s0 = ((*x0)(i, j)).toString();
      std::string s1 = ((*x1)(i, j)).toString();
      std::string s2 = ((*x2)(i, j)).toString();
      std::string s3 = ((*x3)(i, j)).toString();
      std::string s4 = ((*x4)(i, j)).toString();
      char* s = npFunction05s(dps, FunctionEnum, s0.c_str(), s1.c_str(), s2.c_str(), s3.c_str(), s4.c_str());
      mpType temp(s);
      ((*y0)(i, j)) = temp;
  }
 };
}


#endif

#if defined (Use_Float) ||  defined (Use_Double)  || defined (Use_LongDouble)


void mpMath_mpType_Functions0(long what, mpMatrix *y0)
{

    int r = (long) (*y0).rows(); \
    int c = (long) (*y0).cols();

    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)

  {(*y0)(i, j) = npFunction00d(dps, FunctionEnum);} };

}



void mpMath_mpType_Functions1(long what, mpMatrix *y0, mpMatrix *x0)
{

    MP_FUNCTION_INIT
    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {(*y0)(i, j) = npFunction01d(dps, FunctionEnum, (*x0)(i, j));} };

}


void mpMath_mpType_Functions2(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1)
{

    MP_FUNCTION_INIT
    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {(*y0)(i, j) = npFunction02d(dps, FunctionEnum, (*x0)(i, j), (*x1)(i, j));} };

}


void mpMath_mpType_Functions3(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2)
{

    MP_FUNCTION_INIT
    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {(*y0)(i, j) = npFunction03d(dps, FunctionEnum, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j));} };

}


void mpMath_mpType_Functions4(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2, mpMatrix *x3)
{

    MP_FUNCTION_INIT
    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {(*y0)(i, j) = npFunction04d(dps, FunctionEnum, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j), (*x3)(i, j));} };

}


void mpMath_mpType_Functions5(long what, mpMatrix *y0, mpMatrix *x0, mpMatrix *x1, mpMatrix *x2, mpMatrix *x3, mpMatrix *x4)
{

    MP_FUNCTION_INIT
    int dps = 100;
    int FunctionEnum = what;

for (int i = 0; i < r; i++) {for (int j = 0; j < c; j++)
  {(*y0)(i, j) = npFunction05d(dps, FunctionEnum, (*x0)(i, j), (*x1)(i, j), (*x2)(i, j), (*x3)(i, j), (*x4)(i, j));} };

}

#endif


//
//void mpMath_mpType_cplx_Functions1(long what, mpMatrixC *y0, mpMatrixC *x0)
//{
//    MP_FUNCTION_INIT
//    switch (what){
//        case mp_const_Real:      { MP_FUNCTION1_BODY_OLD(real);}
//
//
//    }
//}
//
//
//void mpMath_mpType_cplx_Functions2(long what, mpMatrixC *y0, mpMatrixC *x0,  mpMatrixC *x1)
//{
//    MP_FUNCTION_INIT
//    switch (what){
//        case mp_const_Pow:            { MP_FUNCTION2_BODY_OLD(pow);}
//    }
//}

