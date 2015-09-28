
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpfi_t


  Friend MpfiPtr As IntPtr = Nothing
  Friend rc As Int32 = 0



  Public Property left() As mpfr_t
      Get
          Dim m1 As New mpfr_t
          Lib_Mpfi_Get_Left(m1.MpfrPtr, MpfiPtr)
          Return m1
    End Get

    Set(ByVal m1 As mpfr_t)
          Lib_Mpfi_Set_Left(MpfiPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
    End Set
  End Property
  
  
  
  Public Property right() As mpfr_t
    Get
          Dim m1 As New mpfr_t
          Lib_Mpfi_Get_Right(m1.MpfrPtr, MpfiPtr)
          Return m1
    End Get

    Set(ByVal m1 As mpfr_t)
          Lib_Mpfi_Set_Right(MpfiPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
    End Set
  End Property
  
  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpfi_Init(MpfiPtr)
  End Sub




  ''' <summary>
  ''' Create a new mpfi_t
  ''' </summary>
  Public Sub New()
      Init()
  End Sub
  
  
  ''' <summary>
  ''' Create a new mpfi_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Mpfi_Set_Si(MpfiPtr, si32)
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Mpfi_Set_Ui(MpfiPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Lib_Mpfi_Set_Si64(MpfiPtr, si64)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Lib_Mpfi_Set_Ui64(MpfiPtr, ui64)
  End Sub
  

    Public Sub New(ByVal x As Single)
      Init()
      Lib_Mpfi_Set_Flt(MpfiPtr, x)
    End Sub


    Public Sub New(ByVal d As Double)
      Init()
      Lib_Mpfi_Set_D(MpfiPtr, d)
    End Sub




    Public Sub New(ByVal z As fmpz_t)
      Init()
      rc = Lib_Mpfi_Set_Fmpz(MpfiPtr, z.FmpzPtr)
    End Sub



    Public Sub New(ByVal q As fmpq_t)
      Init()
      rc = Lib_Mpfi_Set_Fmpq(MpfiPtr, q.FmpqPtr)
    End Sub



    Public Sub New(ByVal x As mpfr_t)
      Init()
      rc = Lib_Mpfi_Set_Mpfr(MpfiPtr, x.MpfrPtr)
    End Sub



    Public Sub New(ByVal x As mpfi_t)
      Init()
      rc = Lib_Mpfi_Set(MpfiPtr, x.MpfiPtr)
    End Sub
    
    
    
  
  
'*************************************************************




  Public Sub New(ByVal x1 As UInt32, ByVal x2 As UInt32)
      Init()
      rc = Lib_Mpfi_Set_Ui_Ui(MpfiPtr, x1, x2)
  End Sub



  Public Sub New(ByVal x1 As Int32, ByVal x2 As Int32)
      Init()
      rc = Lib_Mpfi_Set_Si_Si(MpfiPtr, x1, x2)
  End Sub



  Public Sub New(ByVal x1 As UInt64, ByVal x2 As UInt64)
      Init()
      rc = Lib_Mpfi_Set_Ui64_Ui64(MpfiPtr, x1, x2)
  End Sub



  Public Sub New(ByVal x1 As Int64, ByVal x2 As Int64)
      Init()
      rc = Lib_Mpfi_Set_Si64_Si64(MpfiPtr, x1, x2)
  End Sub



  Public Sub New(ByVal x1 As Double, ByVal x2 As Double)
      Init()
      rc = Lib_Mpfi_Set_D_D(MpfiPtr, x1, x2)
  End Sub
  


  Public Sub New(ByVal x1 As Single, ByVal x2 As Single)
      Init()
      rc = Lib_Mpfi_Set_Flt_Flt(MpfiPtr, x1, x2)
  End Sub
  
  
  
  Public Sub New(ByVal x1 As fmpz_t, ByVal x2 As fmpz_t)
      Init()
      rc = Lib_Mpfi_Set_Fmpz_Fmpz(MpfiPtr, x1.FmpzPtr,  x2.FmpzPtr)
  End Sub
  
  
  
  Public Sub New(ByVal x1 As fmpq_t, ByVal x2 As fmpq_t)
      Init()
      rc = Lib_Mpfi_Set_Fmpq_Fmpq(MpfiPtr, x1.FmpqPtr, x2.FmpqPtr)
  End Sub
  
  
  
  Public Sub New(ByVal x1 As mpfr_t, ByVal x2 As mpfr_t)
      Init()
      rc = Lib_Mpfi_Set_Mpfr_Mpfr(MpfiPtr, x1.MpfrPtr, x2.MpfrPtr)
  End Sub
  
  
  
'*************************************************************


    
    



  Public Sub New(ByVal s As String)
      Init()
      Lib_Mpfi_Set_Str(MpfiPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Mpfi_Clear(MpfiPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpfi_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpfi_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return mpfi.Get_Str(MpfiPtr, getDPS())
  End Function
  
  
  Public  Sub Print()
      Lib_Mpfi_Print(MpfiPtr)
  End Sub




  Public Function __str__() As String
    Return mpfi.Get_Str(MpfiPtr, getDPS())
  End Function


  Public Function __repr__() As String
    Return  "mpfi_t('" & mpfi.Get_Str( MpfiPtr, getDPS()) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As String
      Return mpfi.Get_Str(m1.MpfiPtr, getDPS())
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As mpfi_t
    Dim m1 As New mpfi_t
    mpfi.Lib_Mpfi_Set_Str(m1.MpfiPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpfi_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpfi_t
'    Dim m1 As New mpfi_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


    Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As Single
        Return mpfi.Lib_Mpfi_Get_Flt(m1.MpfiPtr)
    End Operator
  
  
    Public Shared Widening Operator CType(ByVal d As Single) As mpfi_t
        Dim m1 As New mpfi_t
        m1.rc = mpfi.Lib_Mpfi_Set_Flt(m1.MpfiPtr, d)
        Return m1
    End Operator


    Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As Double
        Return mpfi.Lib_Mpfi_Get_D(m1.MpfiPtr)
    End Operator


    Public Shared Widening Operator CType(ByVal d As Double) As mpfi_t
        Dim m1 As New mpfi_t
        m1.rc = mpfi.Lib_Mpfi_Set_D(m1.MpfiPtr, d)
        Return m1
    End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As mpfi_t) As Int32
    Return mpfi.Lib_Mpfi_Get_Si(m1.MpfiPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpfi_t
    Dim m1 As New mpfi_t
        m1.rc = mpfi.Lib_Mpfi_Set_Si(m1.MpfiPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As Int64
        Return mpfi.Lib_Mpfi_Get_Si64(m1.MpfiPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As mpfi_t
      Dim m1 As New mpfi_t
        m1.rc = mpfi.Lib_Mpfi_Set_Si64(m1.MpfiPtr, si)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As UInt32
    Return mpfi.Lib_Mpfi_Get_Ui(m1.MpfiPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpfi_t
      Dim m1 As New mpfi_t
        m1.rc = mpfi.Lib_Mpfi_Set_Ui(m1.MpfiPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As UInt64
        Return mpfi.Lib_Mpfi_Get_Ui64(m1.MpfiPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As mpfi_t
      Dim m1 As New mpfi_t
        mpfi.Lib_Mpfi_Set_Ui64(m1.MpfiPtr, ui)
    Return m1
  End Operator
  


    Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As fmpz_t
        Dim z1 As New fmpz_t
        mpfi.Lib_Mpfi_Get_Fmpz(z1.FmpzPtr, m1.MpfiPtr)
        Return z1
    End Operator

    Public Shared Narrowing Operator CType(ByVal z As fmpz_t) As mpfi_t
        Dim m1 As New mpfi_t
        mpfi.Lib_Mpfi_Set_Fmpz(m1.MpfiPtr, z.FmpzPtr)
        Return m1
    End Operator




    Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As fmpq_t
        Dim z1 As New fmpq_t
        mpfi.Lib_Mpfi_Get_Fmpq(z1.FmpqPtr, m1.MpfiPtr)
        Return z1
    End Operator

    Public Shared Narrowing Operator CType(ByVal z As fmpq_t) As mpfi_t
        Dim m1 As New mpfi_t
        mpfi.Lib_Mpfi_Set_Fmpq(m1.MpfiPtr, z.FmpqPtr)
        Return m1
    End Operator



    Public Shared Widening Operator CType(ByVal m1 As mpfi_t) As mpfr_t
        Dim z1 As New mpfr_t
        mpfi.Lib_Mpfi_Get_Fmpq(z1.MpfrPtr, m1.MpfiPtr)
        Return z1
    End Operator

    Public Shared Narrowing Operator CType(ByVal z As mpfr_t) As mpfi_t
        Dim m1 As New mpfi_t
        mpfi.Lib_Mpfi_Set_Fmpq(m1.MpfiPtr, z.MpfrPtr)
        Return m1
    End Operator



  
  Public Shared Operator =(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As Boolean
      Return (mpfi.Lib_Mpfi_Cmp(m1.MpfiPtr, m2.MpfiPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpfi_t) As mpfi_t
    Dim m3 As New mpfi_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpfi_t) As mpfi_t
      Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Neg(m3.MpfiPtr, m1.MpfiPtr)
      Return m3
  End Operator
  

    '*********************************


    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal ui As UInt32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator


    Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal si As Int32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator


    Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal ui As UInt64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator


    Public Shared Operator +(ByVal ui As UInt64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal si As Int64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator


    Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal d As Double) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_D(m3.MpfiPtr, m1.MpfiPtr, d)
        Return m3
    End Operator


    Public Shared Operator +(ByVal d As Double, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_D(m3.MpfiPtr, m1.MpfiPtr, d)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal z As fmpz_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Fmpz(m3.MpfiPtr, m1.MpfiPtr, z.FmpzPtr)
        Return m3
    End Operator


    Public Shared Operator +(ByVal z As fmpz_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Fmpz(m3.MpfiPtr, m1.MpfiPtr, z.FmpzPtr)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfi_t, ByVal q As fmpq_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Fmpq(m3.MpfiPtr, m1.MpfiPtr, q.FmpqPtr)
        Return m3
    End Operator


    Public Shared Operator +(ByVal q As fmpq_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Add_Fmpq(m3.MpfiPtr, m1.MpfiPtr, q.FmpqPtr)
        Return m3
    End Operator



    Public Shared Operator +(ByVal x As mpfi_t, ByVal y As mpfr_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Add_Mpfr(res.MpfiPtr, x.MpfiPtr, y.MpfrPtr)
        Return res
    End Operator


    Public Shared Operator +(ByVal x As mpfr_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Add_Mpfr(res.MpfiPtr, y.MpfiPtr, x.MpfrPtr)
        Return res
    End Operator











    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Ui_Sub(m3.MpfiPtr, ui, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal ui As UInt32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Si_Sub(m3.MpfiPtr, si, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal si As Int32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Ui64_Sub(m3.MpfiPtr, ui, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal ui As UInt64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Si64_Sub(m3.MpfiPtr, si, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal si As Int64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator -(ByVal d As Double, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_D_Sub(m3.MpfiPtr, d, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal d As Double) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_D(m3.MpfiPtr, m1.MpfiPtr, d)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal z As fmpz_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Fmpz(m3.MpfiPtr, m1.MpfiPtr, z.FmpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal z As fmpz_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Fmpz_Sub(m3.MpfiPtr, z.FmpzPtr, m1.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpfi_t, ByVal q As fmpq_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Sub_Fmpq(m3.MpfiPtr, m1.MpfiPtr, q.FmpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal q As fmpq_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Fmpq_Sub(m3.MpfiPtr, q.FmpqPtr, m1.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal x As mpfi_t, ByVal y As mpfr_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Sub_Mpfr(res.MpfiPtr, x.MpfiPtr, y.MpfrPtr)
        Return res
    End Operator



    Public Shared Operator -(ByVal x As mpfr_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mpfr_Sub(res.MpfiPtr, x.MpfrPtr, y.MpfiPtr)
        Return res
    End Operator










    Public Shared Operator *(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfi_t, ByVal ui As UInt32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator


    Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfi_t, ByVal si As Int32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator


    Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator




    Public Shared Operator *(ByVal m1 As mpfi_t, ByVal ui As UInt64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator


    Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfi_t, ByVal si As Int64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator


    Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Mul_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator *(ByVal x As mpfi_t, ByVal y As fmpz_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, x.MpfiPtr, y.FmpzPtr)
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpz_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, y.MpfiPtr, x.FmpzPtr)
        Return res
    End Operator



    Public Shared Operator *(ByVal x As mpfi_t, ByVal y As fmpq_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, x.MpfiPtr, y.FmpqPtr)
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpq_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, y.MpfiPtr, x.FmpqPtr)
        Return res
    End Operator



    Public Shared Operator *(ByVal x As mpfi_t, ByVal y As mpfr_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, x.MpfiPtr, y.MpfrPtr)
        Return res
    End Operator


    Public Shared Operator *(ByVal x As mpfr_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mul_Mpfr(res.MpfiPtr, y.MpfiPtr, x.MpfrPtr)
        Return res
    End Operator





    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Ui_Div(m3.MpfiPtr, ui, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal ui As UInt32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Ui(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int32, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Si_Div(m3.MpfiPtr, si, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal si As Int32) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Si(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Ui64_Div(m3.MpfiPtr, ui, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal ui As UInt64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Ui64(m3.MpfiPtr, m1.MpfiPtr, ui)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int64, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Si64_Div(m3.MpfiPtr, si, m1.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal si As Int64) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Si64(m3.MpfiPtr, m1.MpfiPtr, si)
        Return m3
    End Operator



    Public Shared Operator /(ByVal d As Double, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_D_Div(m3.MpfiPtr, d, m1.MpfiPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal d As Double) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_D(m3.MpfiPtr, m1.MpfiPtr, d)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal z As fmpz_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Fmpz(m3.MpfiPtr, m1.MpfiPtr, z.FmpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal z As fmpz_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Fmpz_Div(m3.MpfiPtr, z.FmpzPtr, m1.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfi_t, ByVal q As fmpq_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Div_Fmpq(m3.MpfiPtr, m1.MpfiPtr, q.FmpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal q As fmpq_t, ByVal m1 As mpfi_t) As mpfi_t
        Dim m3 As New mpfi_t()
        m3.rc = mpfi.Lib_Mpfi_Fmpq_Div(m3.MpfiPtr, q.FmpqPtr, m1.MpfiPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal x As mpfi_t, ByVal y As mpfr_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Div_Mpfr(res.MpfiPtr, x.MpfiPtr, y.MpfrPtr)
        Return res
    End Operator



    Public Shared Operator /(ByVal x As mpfr_t, ByVal y As mpfi_t) As mpfi_t
        Dim res As New mpfi_t()
        res.rc = mpfi.Lib_Mpfi_Mpfr_Div(res.MpfiPtr, x.MpfrPtr, y.MpfiPtr)
        Return res
    End Operator





    '*********************************



  
  Public Shared Operator &(ByVal m1 As mpfi_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpfi_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
      Dim m3 As New mpfi_t()
      Dim n As UInt32 = m2
      mpfi.Lib_Mpfi_Pow_Ui(m3.MpfiPtr, m1.MpfiPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpfi_t, ByVal n As UInt32) As mpfi_t
      Dim m3 As New mpfi_t()
      mpfi.Lib_Mpfi_Pow_Ui(m3.MpfiPtr, m1.MpfiPtr, n)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpfi_t, ByVal n As Int32) As mpfi_t
      Dim m3 As New mpfi_t()
      mpfi.Lib_Mpfi_Pow_Ui(m3.MpfiPtr, m1.MpfiPtr, CUInt(n))
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpfi_t) As mpfi_t
      Dim m3 As New mpfi_t()
      Dim n As UInt32 = m2
      mpfi.Lib_Mpfi_Pow_Ui(m3.MpfiPtr, MpfiPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpfi_t
      Dim m3 As New mpfi_t()
'      MsgBox("pow")      
      mpfi.Lib_Mpfi_Pow_Ui(m3.MpfiPtr, MpfiPtr, CUInt(n))
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpfi_t
      Dim m3 As New mpfi_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpfi_t) As mpfi_t
      Dim m3 As New mpfi_t()
        mpfi.Lib_Mpfi_Div(m3.MpfiPtr, MpfiPtr, m2.MpfiPtr)
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpfi_t
      Dim m3 As New mpfi_t()
      Dim m2 As New mpfi_t(n1)
        mpfi.Lib_Mpfi_Div(m3.MpfiPtr, MpfiPtr, m2.MpfiPtr)
    Return m3
  End Function



'  Public Shared Operator Mod(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
'    Dim m3 As New mpfi_t()
'        mpfi.Lib_Mpfi_Mod(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
'    Return m3
'  End Operator



  Public Shared Operator \(ByVal m1 As mpfi_t, ByVal m2 As mpfi_t) As mpfi_t
    Dim m3 As New mpfi_t()
        mpfi.Lib_Mpfi_Div(m3.MpfiPtr, m1.MpfiPtr, m2.MpfiPtr)
    Return m3
  End Operator
  
  
  
  
' OPERATORS ONLY FOR INTEGERS:  
  
' Left Shift
  Public Shared Operator <<(ByVal m1 As mpfi_t, ByVal e As Integer) As mpfi_t
    Dim m3 As New mpfi_t()
    mpfi.Lib_Mpfi_Mul_2ui(m3.MpfiPtr, m1.MpfiPtr, CUInt(e))
    Return m3
  End Operator
  


' Right Shift
  Public Shared Operator >>(ByVal m1 As mpfi_t, ByVal e As Integer) As mpfi_t
    Dim m3 As New mpfi_t()
        mpfi.Lib_Mpfi_Mul_2ui(m3.MpfiPtr, m1.MpfiPtr, CUInt(e))
    Return m3
  End Operator





    Public  Sub put(ByVal y As mpfi_t)
      rc = Lib_Mpfi_Put(MpfiPtr, y.MpfiPtr)
    End Sub

    Public  Sub put(ByVal y As Double)
      rc = Lib_Mpfi_Put_D(MpfiPtr, y)
    End Sub

    Public  Sub put(ByVal y As UInt32)
      rc = Lib_Mpfi_Put_Ui(MpfiPtr, y)
    End Sub

    Public  Sub put(ByVal y As Int32) 
      rc = Lib_Mpfi_Put_Si(MpfiPtr, y)
    End Sub

    Public  Sub put(ByVal y As UInt64)
      rc = Lib_Mpfi_Put_Ui64(MpfiPtr, y)
    End Sub

    Public  Sub put(ByVal y As Int64)
      rc = Lib_Mpfi_Put_Si64(MpfiPtr, y)
    End Sub

    Public  Sub put(ByVal y As fmpz_t)
      rc = Lib_Mpfi_Put_Fmpz(MpfiPtr, y.FmpzPtr)
    End Sub

    Public  Sub put(ByVal y As fmpq_t)
      rc = Lib_Mpfi_Put_Fmpq(MpfiPtr, y.FmpqPtr)
    End Sub

    Public  Sub put(ByVal y As mpfr_t)
      rc = Lib_Mpfi_Put_Mpfr(MpfiPtr, y.MpfrPtr)
    End Sub
    
    
    


    Public  Function contains(ByVal y As mpfi_t) As Boolean
      Return CBool(Lib_Mpfi_Contains(MpfiPtr, y.MpfiPtr))
    End Function

    Public  Function contains(ByVal y As Double) As Boolean
      Return CBool(Lib_Mpfi_Contains_D(MpfiPtr, y))
    End Function

    Public  Function contains(ByVal y As UInt32) As Boolean
      Return CBool(Lib_Mpfi_Contains_Ui(MpfiPtr, y))
    End Function

    Public  Function contains(ByVal y As Int32)  As Boolean
      Return CBool(Lib_Mpfi_Contains_Si(MpfiPtr, y))
    End Function

    Public  Function contains(ByVal y As UInt64) As Boolean
      Return CBool(Lib_Mpfi_Contains_Ui64(MpfiPtr, y))
    End Function

    Public  Function contains(ByVal y As Int64) As Boolean
      Return CBool(Lib_Mpfi_Contains_Si64(MpfiPtr, y))
    End Function

    Public  Function contains(ByVal y As fmpz_t) As Boolean
      Return CBool(Lib_Mpfi_Contains_Fmpz(MpfiPtr, y.FmpzPtr))
    End Function

    Public  Function contains(ByVal y As fmpq_t) As Boolean
      Return CBool(Lib_Mpfi_Contains_Fmpq(MpfiPtr, y.FmpqPtr)) 
    End Function

    Public  Function contains(ByVal y As mpfr_t) As Boolean
      Return CBool(Lib_Mpfi_Contains_Mpfr(MpfiPtr, y.MpfrPtr))
    End Function
    
    
    
    
    
  
  Public Function is_pos() As Boolean
      Return CBool(Lib_Mpfi_Is_Pos(MpfiPtr))
  End Function
  
  Public Function is_strictly_pos() As Boolean
      Return CBool(Lib_Mpfi_Is_Strictly_Pos(MpfiPtr))
  End Function
    
  
  Public Function is_nonneg() As Boolean
      Return CBool(Lib_Mpfi_Is_Nonneg(MpfiPtr))
  End Function
    
  
  Public Function is_neg() As Boolean
      Return CBool(Lib_Mpfi_Is_Neg(MpfiPtr))
  End Function
    
  
  Public Function is_strictly_neg() As Boolean
      Return CBool(Lib_Mpfi_Is_Strictly_Neg(MpfiPtr))
  End Function
    
  
  Public Function is_nonpos() As Boolean
      Return CBool(Lib_Mpfi_Is_Nonpos(MpfiPtr))
  End Function
    
  
  Public Function is_zero() As Boolean
      Return CBool(Lib_Mpfi_Is_Zero(MpfiPtr))
  End Function
    
  
  Public Function has_zero() As Boolean
      Return CBool(Lib_Mpfi_Has_Zero(MpfiPtr))
  End Function
    
  
  Public Function is_nan() As Boolean
      Return CBool(Lib_Mpfi_Nan_P(MpfiPtr))
  End Function
    
  
  Public Function is_inf() As Boolean
      Return CBool(Lib_Mpfi_Inf_P(MpfiPtr))
  End Function
    
  
  Public Function is_bounded() As Boolean
      Return CBool(Lib_Mpfi_Bounded_P(MpfiPtr))
  End Function
    
    
    
    
    


End Class








Public Module mpfi
  
' ******************  Mpfi Internal Functions  *****************************
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfi_Init(ByRef MpfiPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfi_Clear(ByVal MpfiPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfi_Print(ByVal MpfiPtr As IntPtr)
  End Sub
  
  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Ui(ByVal MpfiPtr_res As IntPtr, ByVal ui As UInt32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Si(ByVal MpfiPtr_res As IntPtr, ByVal i As Int32) As Int32
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Ui64(ByVal MpfiPtr_res As IntPtr, ByVal ui As UInt64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Si64(ByVal MpfiPtr_res As IntPtr, ByVal i As Int64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Flt", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Flt(ByVal MpfiPtr_res As IntPtr, ByVal d As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_D(ByVal MpfiPtr_res As IntPtr, ByVal d As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Set_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
    Friend Function Lib_Mpfi_Set_Str(ByVal MpfiPtr_res As IntPtr, ByVal str As String, ByVal b As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Ui(ByVal MpfiPtr As IntPtr) As UInt32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Si(ByVal MpfiPtr As IntPtr) As Int32
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Ui64(ByVal MpfiPtr As IntPtr) As UInt64
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Si64(ByVal MpfiPtr As IntPtr) As Int64
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Flt", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Flt(ByVal MpfiPtr As IntPtr) As Single
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_D(ByVal MpfiPtr As IntPtr) As Double
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Fmpz(ByVal x_FmpzPtr As IntPtr, ByVal y_MpfiPtr As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Fmpq(ByVal x_FmpqPtr As IntPtr, ByVal y_MpfiPtr As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Get_Mpfr(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
    End Function




  
  
    
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Left", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Get_Left(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Get_Right", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Get_Right(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Left", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Set_Left(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Right", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Set_Right(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  

  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Left_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Left_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfiPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Left_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfi_Left_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfiPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Right_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Right_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfiPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Right_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfi_Right_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfiPtr As IntPtr) As Int32
  End Function
  
  Friend  Function Mpfi_Get_Left_Str_2(ByVal MpfiPtr As IntPtr, ByVal digits As UInt32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfi_Left_SnPrintf_SizeInBase10("%.RE", MpfiPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfi_Left_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfiPtr)
    Return sb.ToString()
  End Function
  
  Friend  Function Mpfi_Get_Right_Str_2(ByVal MpfiPtr As IntPtr, ByVal digits As UInt32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfi_Right_SnPrintf_SizeInBase10("%.RE", MpfiPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfi_Right_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfiPtr)
    Return sb.ToString()
  End Function
  
  Friend  Function Get_Str(ByVal MpfiPtr As IntPtr, ByVal digits As UInt32) As String
    Return "[" & Mpfi_Get_Left_Str_2(MpfiPtr, digits) & " ; " & Mpfi_Get_Right_Str_2(MpfiPtr, digits) & "]"
  End Function
  
  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Neg", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Neg(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
    End Function
  


    '***********************************



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y_MpfiPtr As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Ui64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Si64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int64) As Int32
    End Function


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_D(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Add_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Add_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Ui_Sub(ByVal MpfiPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Si_Sub(ByVal MpfiPtr_res As IntPtr, ByVal x As Int32, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Ui64_Sub(ByVal MpfiPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Ui64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Si64_Sub(ByVal MpfiPtr_res As IntPtr, ByVal x As Int64, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Si64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_D_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_D_Sub(ByVal MpfiPtr_res As IntPtr, ByVal x As Double, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_D(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Fmpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Fmpz_Sub(ByVal MpfiPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Fmpq_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Fmpq_Sub(ByVal MpfiPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sub_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Sub_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mpfr_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mpfr_Sub(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Si64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Ui64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt64) As Int32
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_D(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Ui_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Ui_Div(ByVal MpfiPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Si_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Si_Div(ByVal MpfiPtr_res As IntPtr, ByVal x As Int32, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Ui64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Ui64_Div(ByVal MpfiPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Ui64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Si64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Si64_Div(ByVal MpfiPtr_res As IntPtr, ByVal x As Int64, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Si64(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Int64) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_D_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_D_Div(ByVal MpfiPtr_res As IntPtr, ByVal x As Double, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_D(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Double) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Fmpz_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Fmpz_Div(ByVal MpfiPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Fmpq_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Fmpq_Div(ByVal MpfiPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mpfr_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mpfr_Div(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function



  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put(ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_D(ByVal MpfiPtr_x As IntPtr, y As Double) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Ui(ByVal MpfiPtr_x As IntPtr, y As UInt32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Si(ByVal MpfiPtr_x As IntPtr, y As Int32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Ui64(ByVal MpfiPtr_x As IntPtr, y As UInt64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Si64(ByVal MpfiPtr_x As IntPtr, y As Int64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Fmpz(ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Fmpq(ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Put_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Put_Mpfr(ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function
    
    
    
    
'*****************************************

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Strictly_Contains", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Strictly_Contains(ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains(ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function
  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_D(ByVal MpfiPtr_x As IntPtr, y As Double) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Ui(ByVal MpfiPtr_x As IntPtr, y As UInt32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Si(ByVal MpfiPtr_x As IntPtr, y As Int32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Ui64(ByVal MpfiPtr_x As IntPtr, y As UInt64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Si64(ByVal MpfiPtr_x As IntPtr, y As Int64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Fmpz(ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Fmpq(ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Contains_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Contains_Mpfr(ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function
    

    
'*****************************************

    
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Flt_Flt", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Flt_Flt(ByVal MpfiPtr_res As IntPtr, x As Single, y As Single) As Int32
    End Function
  
  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_D_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_D_D(ByVal MpfiPtr_res As IntPtr, x As Double, y As Double) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Ui_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Ui_Ui(ByVal MpfiPtr_res As IntPtr, x As UInt32, y As UInt32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Si_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Si_Si(ByVal MpfiPtr_res As IntPtr, x As Int32, y As Int32) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_UI64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_UI64_Ui64(ByVal MpfiPtr_res As IntPtr, x As UInt64, y As UInt64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Si64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Si64_Si64(ByVal MpfiPtr_res As IntPtr, x As Int64, y As Int64) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Fmpz_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Fmpz_Fmpz(ByVal MpfiPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Fmpq_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Fmpq_Fmpq(ByVal MpfiPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Set_Mpfr_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Set_Mpfr_Mpfr(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function
        
    
    
'*****************************************

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Pos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Pos(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Strictly_Pos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Strictly_Pos(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Nonneg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Nonneg(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Neg(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Strictly_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Strictly_Neg(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Nonpos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Nonpos(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Zero", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Zero(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Has_Zero", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Has_Zero(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Nan_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Nan_P(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Inf_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Inf_P(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Bounded_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Bounded_P(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Is_Empty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Is_Empty(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function

  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Revert_If_Needed", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Revert_If_Needed(ByVal MpfiPtr_x As IntPtr) As Int32
  End Function

  
  
' ******************  Mpfi:  Internal and Public Functions  *****************************


  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp(ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As mpfi_t)  As Int32
      Return Lib_Mpfi_Cmp(x.MpfiPtr, y.MpfiPtr)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_D(ByVal MpfiPtr_x As IntPtr, y As Double) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As Double)  As Int32
      Return Lib_Mpfi_Cmp_D(x.MpfiPtr, y)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Ui(ByVal MpfiPtr_x As IntPtr, y As UInt32) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As UInt32)  As Int32
      Return Lib_Mpfi_Cmp_Ui(x.MpfiPtr, y)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Si(ByVal MpfiPtr_x As IntPtr, y As Int32) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As Int32)  As Int32
      Return Lib_Mpfi_Cmp_Si(x.MpfiPtr, y)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Ui64(ByVal MpfiPtr_x As IntPtr, y As UInt64) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As UInt64)  As Int32
      Return Lib_Mpfi_Cmp_Ui64(x.MpfiPtr, y)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Si64(ByVal MpfiPtr_x As IntPtr, y As Int64) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As Int64)  As Int32
      Return Lib_Mpfi_Cmp_Si64(x.MpfiPtr, y)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Fmpz(ByVal MpfiPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As fmpz_t)  As Int32
      Return Lib_Mpfi_Cmp_Fmpz(x.MpfiPtr, y.FmpzPtr)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Fmpq(ByVal MpfiPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As fmpq_t)  As Int32
      Return Lib_Mpfi_Cmp_Fmpq(x.MpfiPtr, y.FmpqPtr)
    End Function

  
  
    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cmp_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend  Function Lib_Mpfi_Cmp_Mpfr(ByVal MpfiPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
    End Function

    Public  Function cmp(ByVal x As mpfi_t, ByVal y As mpfr_t)  As Int32
      Return Lib_Mpfi_Cmp_Mpfr(x.MpfiPtr, y.MpfrPtr)
    End Function





    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_2ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_2ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal _2exp As UInt32) As Int32
    End Function
    
    Public  Function mul_2exp(ByVal x As mpfi_t, ByVal _2exp As UInt32) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Mul_2ui(res.MpfiPtr, x.MpfiPtr, _2exp)
      Return res
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mul_2si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Mul_2si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal _2exp As Int32) As Int32
    End Function

 
    Public  Function mul_2exp(ByVal x As mpfi_t, ByVal _2exp As Int32) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Mul_2si(res.MpfiPtr, x.MpfiPtr, _2exp)
      Return res
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_2ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_2ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal _2exp As UInt32) As Int32
    End Function
 
    Public  Function div_2exp(ByVal x As mpfi_t, ByVal _2exp As UInt32) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Div_2ui(res.MpfiPtr, x.MpfiPtr, _2exp)
      Return res
    End Function
    
    

    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Div_2si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfi_Div_2si(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal _2exp As Int32) As Int32
    End Function
 
    Public  Function div_2exp(ByVal x As mpfi_t, ByVal _2exp As Int32) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Div_2si(res.MpfiPtr, x.MpfiPtr, _2exp)
      Return res
    End Function
    
    
    
    
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Intersect", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Intersect(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function intersect(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Intersect(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Union", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Union(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function union(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Union(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return res
  End Function
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Bisect", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Bisect(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function bisect(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Bisect(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return res
  End Function

  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Blow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Blow(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As Double) As Int32
  End Function
  
  Public  Function blow(ByVal x As mpfi_t, ByVal y As Double) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Blow(res.MpfiPtr, x.MpfiPtr, y)
      Return res
  End Function

  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Increase", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Increase(ByVal MpfiPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function increase(ByVal x As mpfr_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Increase(res.MpfiPtr, x.MpfrPtr)
      Return res
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Pow(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Pow(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return res
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Pow_Ui(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal y As UInt32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfi_t, ByVal y As UInt32) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Pow_Ui(res.MpfiPtr, x.MpfiPtr, y)
      Return res
  End Function
  
  
  
  
  
' ******************  Mpfi:  Public Functions  *****************************


  
  
  Public  Function left(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Get_Left(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  Public  Function right(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Get_Right(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Diam_Abs", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Diam_Abs(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function diam_abs(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Diam_Abs(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Diam_Rel", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Diam_Rel(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function diam_rel(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Diam_Rel(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Diam", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Diam(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function diam(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Diam(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mag", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Mag(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function mag(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Mag(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mig", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Mig(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function mig(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Mig(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Mid", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Mid(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function mid(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfi_Mid(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Alea", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfi_Alea(ByVal MpfrPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr)
  End Sub
  
  Public  Function alea(ByVal x As mpfi_t) As mpfr_t
      Dim res As New mpfr_t
      Lib_Mpfi_Alea(res.MpfrPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sqr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sqr(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sqr(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sqr(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Inv", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Inv(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function inv(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Inv(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sqrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sqrt(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sqrt(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sqrt(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cbrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Cbrt(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function cbrt(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Cbrt(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Abs", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Abs(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function abs(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Abs(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Log", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Log(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function log(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Log(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Exp(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function exp(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Exp(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Exp2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Exp2(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function exp2(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Exp2(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Cos(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function cos(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Cos(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sin(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sin(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sin(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Tan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Tan(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function tan(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Tan(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sec", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sec(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sec(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sec(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Csc", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Csc(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function csc(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Csc(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cot", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Cot(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function cot(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Cot(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Acos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Acos(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function acos(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Acos(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Asin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Asin(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function asin(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Asin(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Atan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Atan(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function atan(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Atan(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Cosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Cosh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function cosh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Cosh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sinh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sinh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sinh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Tanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Tanh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function tanh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Tanh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Sech", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Sech(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function sech(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Sech(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Csch", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Csch(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function csch(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Csch(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Coth", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Coth(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function coth(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Coth(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Acosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Acosh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function acosh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Acosh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Asinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Asinh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function asinh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Asinh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Atanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Atanh(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function atanh(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Atanh(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Log1p", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Log1p(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function log1p(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Log1p(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Log2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Log2(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function log2(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Log2(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Log10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Log10(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr) As Int32
  End Function
  
  Public  Function log10(ByVal x As mpfi_t) As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Log10(res.MpfiPtr, x.MpfiPtr)
      Return res
  End Function



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Atan2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Atan2(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function atan2(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Atan2(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return x
  End Function



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Hypot", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Hypot(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x As IntPtr, ByVal MpfiPtr_y As IntPtr) As Int32
  End Function
  
  Public  Function hypot(ByVal x As mpfi_t, ByVal y As mpfi_t) As mpfi_t
      Dim res As New mpfi_t(0)
      res.rc = Lib_Mpfi_Hypot(res.MpfiPtr, x.MpfiPtr, y.MpfiPtr)
      Return x
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Const_Log2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Const_Log2(ByVal MpfiPtr_res As IntPtr) As Int32
  End Function
  
  Public  Function const_log2() As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Const_Log2(res.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Const_Pi(ByVal MpfiPtr_res As IntPtr) As Int32
  End Function
  
  Public  Function const_pi() As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Const_Pi(res.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Const_Euler", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Const_Euler(ByVal MpfiPtr_res As IntPtr) As Int32
  End Function
  
  Public  Function const_euler() As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Const_Euler(res.MpfiPtr)
      Return res
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfi_Const_Catalan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfi_Const_Catalan(ByVal MpfiPtr_res As IntPtr) As Int32
  End Function
  
  Public  Function const_catalan() As mpfi_t
      Dim res As New mpfi_t
      res.rc = Lib_Mpfi_Const_Catalan(res.MpfiPtr)
      Return res
  End Function







End Module




