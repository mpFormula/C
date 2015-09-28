#include "mpNum_Internal.h"

#ifdef __cplusplus
extern "C"
{
#endif

void mpNum_SetPrecision(int prec)
{
    EigenLib_Mpfr_SetPrecision(prec);
    EigenLib_Mpdec_SetPrecision(prec);
}


 void mpNum_Print(const char * Title, mpNum_t x)
{
    if ((x->NumType) > 0)
    {
        switch (x->NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_Double: {EigenLib_Double_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_Print(Title, x->NumPtr);} break;

        }
    }
    else
    {
        switch (x->NumType) {
            case mp_const_mpType_cplx_Single: {cplx_EigenLib_Float_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_Double: {cplx_EigenLib_Double_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_EigenLib_LongDouble_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_EigenLib_Mpfr_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_EigenLib_Mpfi_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_EigenLib_Mpdec_Print(Title, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpq: {cplx_EigenLib_Mpq_Print(Title, x->NumPtr);} break;

        }
    }
}



extern void mpNum_Init(int NumType, mpNum_t x)
{
    x->NumType = NumType;
   if ((x->NumType) > 0)
   {
        switch (NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_Init(&(x->NumPtr));} break;
            case mp_const_mpType_Double: {EigenLib_Double_Init(&(x->NumPtr));} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_Init(&(x->NumPtr));} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_Init(&(x->NumPtr));} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_Init(&(x->NumPtr));} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_Init(&(x->NumPtr));} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_Init(&(x->NumPtr));} break;

        }
   }
   else
   {
        switch (NumType) {
            case mp_const_mpType_cplx_Single: {cplx_EigenLib_Float_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Double: {cplx_EigenLib_Double_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_EigenLib_LongDouble_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_EigenLib_Mpfr_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_EigenLib_Mpfi_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_EigenLib_Mpdec_Init(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpq: {cplx_EigenLib_Mpq_Init(&(x->NumPtr));} break;

        }
   }
}


extern void mpNum_Clear(mpNum_t x)
{
   if ((x->NumType) > 0)
    {
          switch (x->NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_Double: {EigenLib_Double_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_Clear(&(x->NumPtr));} break;

        }
    }
  else
    {
          switch (x->NumType) {
            case mp_const_mpType_cplx_Single: {cplx_EigenLib_Float_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Double: {cplx_EigenLib_Double_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_EigenLib_LongDouble_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_EigenLib_Mpfr_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_EigenLib_Mpfi_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_EigenLib_Mpdec_Clear(&(x->NumPtr));} break;
            case mp_const_mpType_cplx_Mpq: {cplx_EigenLib_Mpq_Clear(&(x->NumPtr));} break;

        }
    }
}




extern void mpNum_GetItemFromMatrix(mpNum_t DestItem, long row, long col, mpNum_t SourceMatrix)
{
   if ((DestItem->NumType) > 0)
   {
        switch (DestItem->NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_Double: {EigenLib_Double_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_GetItemFromMatrix(DestItem->NumPtr, row, col, SourceMatrix->NumPtr);} break;

        }
   }
   else
   {
        switch (DestItem->NumType) {
//            case mp_const_mpType_cplx_Single: {cplx_SetSpecialValue_Float(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Double: {cplx_SetSpecialValue_Double(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_LongDouble: {cplx_SetSpecialValue_LongDouble(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpfr: {cplx_SetSpecialValue_Mpfr(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpfi: {cplx_SetSpecialValue_Mpfi(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpdec: {cplx_SetSpecialValue_Mpdec(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Fmpq: {cplx_SetSpecialValue_Mpq(m, n, what, x->NumPtr);} break;
        }
   }
}



extern void mpNum_SetItemIntoMatrix(mpNum_t DestMatrix, long row, long col, mpNum_t SourceItem)
{
   if ((DestMatrix->NumType) > 0)
   {
        switch (DestMatrix->NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_Double: {EigenLib_Double_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_SetItemIntoMatrix(DestMatrix->NumPtr, row, col, SourceItem->NumPtr);} break;

        }
   }
   else
   {
        switch (DestMatrix->NumType) {
//            case mp_const_mpType_cplx_Single: {cplx_SetSpecialValue_Float(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Double: {cplx_SetSpecialValue_Double(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_LongDouble: {cplx_SetSpecialValue_LongDouble(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpfr: {cplx_SetSpecialValue_Mpfr(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpfi: {cplx_SetSpecialValue_Mpfi(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Mpdec: {cplx_SetSpecialValue_Mpdec(m, n, what, x->NumPtr);} break;
//            case mp_const_mpType_cplx_Fmpq: {cplx_SetSpecialValue_Mpq(m, n, what, x->NumPtr);} break;
        }
   }
}



extern void mpNum_SetSpecialValue(long m, long n, long what, mpNum_t x)
{
   if ((x->NumType) > 0)
   {
        switch (x->NumType) {
            case mp_const_mpType_Single: {SetSpecialValue_Float(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_Double: {SetSpecialValue_Double(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_LongDouble: {SetSpecialValue_LongDouble(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_Mpfr: {SetSpecialValue_Mpfr(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_Mpfi: {SetSpecialValue_Mpfi(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_Mpdec: {SetSpecialValue_Mpdec(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_Mpq: {SetSpecialValue_Mpq(m, n, what, x->NumPtr);} break;

        }
   }
   else
   {
        switch (x->NumType) {
            case mp_const_mpType_cplx_Single: {cplx_SetSpecialValue_Float(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_Double: {cplx_SetSpecialValue_Double(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_SetSpecialValue_LongDouble(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_SetSpecialValue_Mpfr(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_SetSpecialValue_Mpfi(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_SetSpecialValue_Mpdec(m, n, what, x->NumPtr);} break;
            case mp_const_mpType_cplx_Mpq: {cplx_SetSpecialValue_Mpq(m, n, what, x->NumPtr);} break;

        }
   }
}





extern void mpNum_Inverse(mpNum_t x, mpNum_t m, long Decomposition)
{
   if ((x->NumType) > 0)
   {
        switch (x->NumType) {
            case mp_const_mpType_Single: {EigenLib_Float_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_Double: {EigenLib_Double_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_LongDouble: {EigenLib_LongDouble_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_Mpfr: {EigenLib_Mpfr_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_Mpfi: {EigenLib_Mpfi_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_Mpdec: {EigenLib_Mpdec_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_Mpq: {EigenLib_Mpq_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;

        }
   }
   else
   {
        switch (x->NumType) {
            case mp_const_mpType_cplx_Single: {cplx_EigenLib_Float_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_Double: {cplx_EigenLib_Double_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_EigenLib_LongDouble_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_EigenLib_Mpfr_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_EigenLib_Mpfi_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_EigenLib_Mpdec_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;
            case mp_const_mpType_cplx_Mpq: {cplx_EigenLib_Mpq_Inverse(x->NumPtr, m->NumPtr, Decomposition);} break;

        }
   }
}




extern void mpNum_BasicArithmetic(long what, mpNum_t m, mpNum_t x, mpNum_t z)
{
   if ((x->NumType) > 0)
   {
        switch (x->NumType) {
            case mp_const_mpType_Single: {BasicArithmetic_Float(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_Double: {BasicArithmetic_Double(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_LongDouble: {BasicArithmetic_LongDouble(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_Mpfr: {BasicArithmetic_Mpfr(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_Mpfi: {BasicArithmetic_Mpfi(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_Mpdec: {BasicArithmetic_Mpdec(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_Mpq: {BasicArithmetic_Mpq(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
        }
   }
   else
   {
        switch (x->NumType) {
            case mp_const_mpType_cplx_Single: {cplx_BasicArithmetic_Float(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_Double: {cplx_BasicArithmetic_Double(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_LongDouble: {cplx_BasicArithmetic_LongDouble(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfr: {cplx_BasicArithmetic_Mpfr(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_Mpfi: {cplx_BasicArithmetic_Mpfi(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_Mpdec: {cplx_BasicArithmetic_Mpdec(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
            case mp_const_mpType_cplx_Mpq: {cplx_BasicArithmetic_Mpq(what, m->NumPtr, x->NumPtr, z->NumPtr);} break;
        }
   }
}

//**************************************************************************************************************


//
//extern void mpNum_mpMathFunctions0(long what, mpNum_t y)
//{
//   if ((y->NumType) > 0)
//   {
//        switch (y->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions0(what, y->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions0(what, y->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//
//
//extern void mpNum_mpMathFunctions1(long what, mpNum_t y, mpNum_t x0)
//{
//   if ((x0->NumType) > 0)
//   {
//        switch (x0->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions1(what, y->NumPtr, x0->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//
//
//
//extern void mpNum_mpMathFunctions2(long what, mpNum_t y, mpNum_t x0, mpNum_t x1)
//{
//   if ((x0->NumType) > 0)
//   {
//        switch (x0->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions2(what, y->NumPtr, x0->NumPtr, x1->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//
//
//
//extern void mpNum_mpMathFunctions3(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2)
//{
//   if ((x0->NumType) > 0)
//   {
//        switch (x0->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions3(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//
//
//extern void mpNum_mpMathFunctions4(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2, mpNum_t x3)
//{
//   if ((x0->NumType) > 0)
//   {
//        switch (x0->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions4(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//
//extern void mpNum_mpMathFunctions5(long what, mpNum_t y, mpNum_t x0, mpNum_t x1, mpNum_t x2, mpNum_t x3, mpNum_t x4)
//{
//   if ((x0->NumType) > 0)
//   {
//        switch (x0->NumType) {
//            case mp_const_mpType_Single: {mpMath_Float_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_Double: {mpMath_Double_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_LongDouble: {mpMath_LongDouble_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_Mpfr: {mpMath_Mpfr_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_Mpfi: {mpMath_Mpfi_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_Mpdec: {mpMath_Mpdec_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//            case mp_const_mpType_Mpq: {mpMath_Mpq_Functions5(what, y->NumPtr, x0->NumPtr, x1->NumPtr, x2->NumPtr, x3->NumPtr, x4->NumPtr);} break;
//        }
//   }
//   else
//   {
//// Raise error
//   }
//}
//



#ifdef __cplusplus
}
#endif
