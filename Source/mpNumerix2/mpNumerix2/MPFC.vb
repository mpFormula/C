
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text



Public Class mpfc_t

  Friend MpfcPtr As IntPtr = Nothing
  Friend rc As Int32 = 0



  Public Property returncode() As Int32
    Get
      Return rc
    End Get

    Set(ByVal r As Int32)
        rc = r
    End Set
  End Property
    
  
  
  Public Property prec() As Int32
    Get
        Return Lib_Mpfc_Get_Prec(MpfcPtr)
    End Get

    Set(ByVal prec As Int32)
        Lib_Mpfc_Set_Prec(MpfcPtr, prec)
    End Set
  End Property

  

  Public Property real() As mpfr_t
      Get
          Dim m1 As New mpfr_t
          m1.rc = Lib_Mpfc_Get_Real(m1.MpfrPtr, MpfcPtr, mpfr.GetDefaultRoundingMode())
          Return m1
    End Get

    Set(ByVal m1 As mpfr_t)
          rc = Lib_Mpfc_Set_Real(MpfcPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
    End Set
  End Property
  
  
  
  Public Property imag() As mpfr_t
    Get
          Dim m1 As New mpfr_t
          m1.rc = Lib_Mpfc_Get_Imag(m1.MpfrPtr, MpfcPtr, mpfr.GetDefaultRoundingMode())
          Return m1
    End Get

    Set(ByVal m1 As mpfr_t)
          rc = Lib_Mpfc_Set_Imag(MpfcPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
    End Set
  End Property
  
  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpfc_Init(MpfcPtr)
  End Sub
  
  
  
  Public Sub New()
      Init()
  End Sub
  
  
  
  Public Sub New(ByVal x As mpfc_t)
      Init()
      rc = Lib_Mpfc_Set(MpfcPtr, x.MpfcPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal ui32 As UInt32)
      Init()
      rc = Lib_Mpfc_Set_Ui(MpfcPtr, ui32, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal si32 As Int32)
      Init()
      rc = Lib_Mpfc_Set_Si(MpfcPtr, si32, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal ui64 As UInt64)
      Init()
      rc = Lib_Mpfc_Set_Ui64(MpfcPtr, ui64, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal si64 As Int64)
      Init()
      rc = Lib_Mpfc_Set_Si64(MpfcPtr, si64, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal d As Double)
      Init()
      rc = Lib_Mpfc_Set_D(MpfcPtr, d, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal z As fmpz_t)
      Init()
      rc = Lib_Mpfc_Set_Fmpz(MpfcPtr, z.FmpzPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal q As fmpq_t)
      Init()
      rc = Lib_Mpfc_Set_Fmpq(MpfcPtr, q.FmpqPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal x As mpfr_t)
      Init()
      rc = Lib_Mpfc_Set_Mpfr(MpfcPtr, x.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
'*************************************************************




  Public Sub New(ByVal x1 As UInt32, ByVal x2 As UInt32)
      Init()
      rc = Lib_Mpfc_Set_Ui_Ui(MpfcPtr, x1, x2, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal x1 As Int32, ByVal x2 As Int32)
      Init()
      rc = Lib_Mpfc_Set_Si_Si(MpfcPtr, x1, x2, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal x1 As UInt64, ByVal x2 As UInt64)
      Init()
      rc = Lib_Mpfc_Set_Ui64_Ui64(MpfcPtr, x1, x2, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal x1 As Int64, ByVal x2 As Int64)
      Init()
      rc = Lib_Mpfc_Set_Si64_Si64(MpfcPtr, x1, x2, mpfr.GetDefaultRoundingMode())
  End Sub



  Public Sub New(ByVal x1 As Double, ByVal x2 As Double)
      Init()
      rc = Lib_Mpfc_Set_D_D(MpfcPtr, x1, x2, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal x1 As fmpz_t, ByVal x2 As fmpz_t)
      Init()
      rc = Lib_Mpfc_Set_Fmpz_Fmpz(MpfcPtr, x1.FmpzPtr,  x2.FmpzPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal x1 As fmpq_t, ByVal x2 As fmpq_t)
      Init()
      rc = Lib_Mpfc_Set_Fmpq_Fmpq(MpfcPtr, x1.FmpqPtr, x2.FmpqPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal x1 As mpfr_t, ByVal x2 As mpfr_t)
      Init()
      rc = Lib_Mpfc_Set_Mpfr_Mpfr(MpfcPtr, x1.MpfrPtr, x2.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
'*************************************************************





  Public Sub New(ByVal s As String)
        Init()
        Lib_Mpfc_Set_Str(MpfcPtr, s, 10, mpfr.GetDefaultRoundingMode())
  End Sub



  Protected Overrides Sub Finalize()
    Lib_Mpfc_Clear(MpfcPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpfc_t) As Boolean
      Return (m1 = 0)
  End Operator



  Public Shared Operator IsFalse(ByVal m1 As mpfc_t) As Boolean
      Return (m1 <> 0)
  End Operator



  Public Overrides Function ToString() As String
    Return mpfc.Get_Str( MpfcPtr, getDPS(), mpfr.GetDefaultRoundingMode())
  End Function
  
  
  
  Public  Sub Print(ByVal prec As Int32)
      Lib_Mpfc_Printd(MpfcPtr, prec)
  End Sub



  Public Function __str__() As String
    Return mpfc.Get_Str(MpfcPtr,  getDPS(), mpfr.GetDefaultRoundingMode())
  End Function


  Public Function __repr__() As String
    Return  "mpfc_t('" & mpfc.Get_Str(MpfcPtr, getDPS(), mpfr.GetDefaultRoundingMode()) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpfc_t) As String
      Return mpfc.Get_Str(m1.MpfcPtr,  getDPS(), mpfr.GetDefaultRoundingMode())
  End Operator


  Public Shared Narrowing Operator CType(ByVal s As String) As mpfc_t
    Dim m1 As New mpfc_t
    mpfc.Lib_Mpfc_Set_Str(m1.MpfcPtr, s, 10, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator

'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpfc_t
'    Dim m1 As New mpfc_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_D(m1.MpfcPtr, d, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal si As Int32) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Si(m1.MpfcPtr, si, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal si64 As Int64) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Si64(m1.MpfcPtr, si64, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Ui(m1.MpfcPtr, ui, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal ui64 As UInt64) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Ui64(m1.MpfcPtr, ui64, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal x As fmpz_t) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Fmpz(m1.MpfcPtr, x.FmpzPtr, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal x As fmpq_t) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Fmpq(m1.MpfcPtr, x.FmpqPtr, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal x As mpfr_t) As mpfc_t
    Dim m1 As New mpfc_t
      m1.rc = mpfc.Lib_Mpfc_Set_Mpfr(m1.MpfcPtr, x.MpfrPtr, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As Boolean
      Return (mpfc.Lib_Mpfc_Cmp(m1.MpfcPtr, m2.MpfcPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As Boolean
      Return (mpfc.Lib_Mpfc_Cmp(m1.MpfcPtr, m2.MpfcPtr) <> 0)
  End Operator



  Public Shared Operator +(ByVal m1 As mpfc_t) As mpfc_t
    Dim m3 As New mpfc_t(m1)
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpfc_t) As mpfc_t
      Dim m3 As New mpfc_t()
      m3.rc = mpfc.Lib_Mpfc_Neg(m3.MpfcPtr, m1.MpfcPtr, mpfr.GetDefaultRoundingMode())
      Return m3
  End Operator
  


    '*********************************



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal ui As UInt32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal si As Int32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal ui As UInt64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal ui As UInt64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal si As Int64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal d As Double) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_D(m3.MpfcPtr, m1.MpfcPtr, d, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal d As Double, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_D(m3.MpfcPtr, m1.MpfcPtr, d, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal z As fmpz_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Fmpz(m3.MpfcPtr, m1.MpfcPtr, z.FmpzPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal z As fmpz_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Fmpz(m3.MpfcPtr, m1.MpfcPtr, z.FmpzPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpfc_t, ByVal q As fmpq_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Fmpq(m3.MpfcPtr, m1.MpfcPtr, q.FmpqPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator +(ByVal q As fmpq_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Add_Fmpq(m3.MpfcPtr, m1.MpfcPtr, q.FmpqPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator +(ByVal x As mpfc_t, ByVal y As mpfr_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Add_Mpfr(res.MpfcPtr, x.MpfcPtr, y.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator +(ByVal x As mpfr_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Add_Mpfr(res.MpfcPtr, y.MpfcPtr, x.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator











    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Ui_Sub(m3.MpfcPtr, ui, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal ui As UInt32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Si_Sub(m3.MpfcPtr, si, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal si As Int32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Ui64_Sub(m3.MpfcPtr, ui, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal ui As UInt64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Si64_Sub(m3.MpfcPtr, si, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal si As Int64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal d As Double, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_D_Sub(m3.MpfcPtr, d, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal d As Double) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_D(m3.MpfcPtr, m1.MpfcPtr, d, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal z As fmpz_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Fmpz(m3.MpfcPtr, m1.MpfcPtr, z.FmpzPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal z As fmpz_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Fmpz_Sub(m3.MpfcPtr, z.FmpzPtr, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpfc_t, ByVal q As fmpq_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Sub_Fmpq(m3.MpfcPtr, m1.MpfcPtr, q.FmpqPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal q As fmpq_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Fmpq_Sub(m3.MpfcPtr, q.FmpqPtr, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator -(ByVal x As mpfc_t, ByVal y As mpfr_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Sub_Mpfr(res.MpfcPtr, x.MpfcPtr, y.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator



    Public Shared Operator -(ByVal x As mpfr_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mpfr_Sub(res.MpfcPtr, x.MpfrPtr, y.MpfcPtr, GetDefaultRoundingMode())
        Return res
    End Operator










    Public Shared Operator *(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfc_t, ByVal ui As UInt32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfc_t, ByVal si As Int32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator




    Public Shared Operator *(ByVal m1 As mpfc_t, ByVal ui As UInt64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpfc_t, ByVal si As Int64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Mul_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator
        


    Public Shared Operator *(ByVal x As mpfc_t, ByVal y As fmpz_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, x.MpfcPtr, y.FmpzPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpz_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, y.MpfcPtr, x.FmpzPtr, GetDefaultRoundingMode())
        Return res
    End Operator
    


    Public Shared Operator *(ByVal x As mpfc_t, ByVal y As fmpq_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, x.MpfcPtr, y.FmpqPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpq_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, y.MpfcPtr, x.FmpqPtr, GetDefaultRoundingMode())
        Return res
    End Operator
    
    

    Public Shared Operator *(ByVal x As mpfc_t, ByVal y As mpfr_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, x.MpfcPtr, y.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator *(ByVal x As mpfr_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mul_Mpfr(res.MpfcPtr, y.MpfcPtr, x.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator





    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Ui_Div(m3.MpfcPtr, ui, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal ui As UInt32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Ui(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int32, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Si_Div(m3.MpfcPtr, si, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal si As Int32) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Si(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Ui64_Div(m3.MpfcPtr, ui, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal ui As UInt64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Ui64(m3.MpfcPtr, m1.MpfcPtr, ui, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int64, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Si64_Div(m3.MpfcPtr, si, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal si As Int64) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Si64(m3.MpfcPtr, m1.MpfcPtr, si, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal d As Double, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_D_Div(m3.MpfcPtr, d, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator


    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal d As Double) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_D(m3.MpfcPtr, m1.MpfcPtr, d, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal z As fmpz_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Fmpz(m3.MpfcPtr, m1.MpfcPtr, z.FmpzPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal z As fmpz_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Fmpz_Div(m3.MpfcPtr, z.FmpzPtr, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpfc_t, ByVal q As fmpq_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Div_Fmpq(m3.MpfcPtr, m1.MpfcPtr, q.FmpqPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal q As fmpq_t, ByVal m1 As mpfc_t) As mpfc_t
        Dim m3 As New mpfc_t()
        m3.rc = mpfc.Lib_Mpfc_Fmpq_Div(m3.MpfcPtr, q.FmpqPtr, m1.MpfcPtr, GetDefaultRoundingMode())
        Return m3
    End Operator



    Public Shared Operator /(ByVal x As mpfc_t, ByVal y As mpfr_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Div_Mpfr(res.MpfcPtr, x.MpfcPtr, y.MpfrPtr, GetDefaultRoundingMode())
        Return res
    End Operator



    Public Shared Operator /(ByVal x As mpfr_t, ByVal y As mpfc_t) As mpfc_t
        Dim res As New mpfc_t()
        res.rc = mpfc.Lib_Mpfc_Mpfr_Div(res.MpfcPtr, x.MpfrPtr, y.MpfcPtr, GetDefaultRoundingMode())
        Return res
    End Operator





    '*********************************





  Public Shared Operator &(ByVal m1 As mpfc_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpfc_t) As String
      Return s & m1.ToString
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal y As Double) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_D(m3.MpfcPtr, m1.MpfcPtr, y, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal n As UInt32) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_Ui(m3.MpfcPtr, m1.MpfcPtr, n, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal n As Int32) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_Si(m3.MpfcPtr, m1.MpfcPtr, n, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal m2 As fmpz_t) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_Fmpz(m3.MpfcPtr, m1.MpfcPtr, m2.FmpzPtr, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal m2 As fmpq_t) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_Fmpq(m3.MpfcPtr, m1.MpfcPtr, m2.FmpqPtr, getprec())
    Return m3
  End Operator



  Public Shared Operator ^(ByVal m1 As mpfc_t, ByVal m2 As mpfr_t) As mpfc_t
    Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow_Mpfr(m3.MpfcPtr, m1.MpfcPtr, m2.MpfrPtr, getprec())
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpfc_t) As mpfc_t
      Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Pow(m3.MpfcPtr, MpfcPtr, m2.MpfcPtr, getprec())
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpfc_t
      Dim m3 As New mpfc_t()
'      MsgBox("pow")      
      mpfc.Lib_Mpfc_Pow_Si(m3.MpfcPtr, MpfcPtr, n, getprec())
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpfc_t
      Dim m3 As New mpfc_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpfc_t) As mpfc_t
      Dim m3 As New mpfc_t()
      mpfc.Lib_Mpfc_Div(m3.MpfcPtr, MpfcPtr, m2.MpfcPtr, getprec())
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpfc_t
      Dim m3 As New mpfc_t()
      Dim m2 As New mpfc_t(n1)
      mpfc.Lib_Mpfc_Div(m3.MpfcPtr, MpfcPtr, m2.MpfcPtr, getprec())
    Return m3
  End Function


'
'  Public Shared Operator Mod(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
'    Dim m3 As New mpfc_t()
'        mpfc.Lib_Mpfc_Mod(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, getprec())
'    Return m3
'  End Operator



  Public Shared Operator \(ByVal m1 As mpfc_t, ByVal m2 As mpfc_t) As mpfc_t
    Dim m3 As New mpfc_t()
        mpfc.Lib_Mpfc_Div(m3.MpfcPtr, m1.MpfcPtr, m2.MpfcPtr, getprec())
    Return m3
  End Operator
  
  


End Class





Public Module mpfc
  
  
  
' ******************  Mpfc  Internal Functions*****************************
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfc_Init(ByRef MpfcPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfc_Clear(ByVal MpfcPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Printd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfc_Printd(ByVal MpfcPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Sub Lib_Mpfc_Set_Prec(ByVal MpfrPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Get_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Function Lib_Mpfc_Get_Prec(ByVal MpfrPtr As IntPtr) As Int32
  End Function
  



  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  

  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Ui(ByVal MpfcPtr As IntPtr, ByVal ui As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Si(ByVal MpfcPtr As IntPtr, ByVal i As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Ui64(ByVal MpfcPtr As IntPtr, ByVal ui As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Si64(ByVal MpfcPtr As IntPtr, ByVal i As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_D(ByVal MpfcPtr As IntPtr, ByVal d As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
'  **************************************************************


  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Ui_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Ui_Ui(ByVal MpfcPtr As IntPtr, ByVal x1 As UInt32, ByVal x2 As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Si_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Si_Si(ByVal MpfcPtr As IntPtr, ByVal x1 As Int32, ByVal x2 As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Ui64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Ui64_Ui64(ByVal MpfcPtr As IntPtr, ByVal x1 As UInt64, ByVal x2 As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Si64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Si64_Si64(ByVal MpfcPtr As IntPtr, ByVal x1 As Int64, ByVal x2 As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_D_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_D_D(ByVal MpfcPtr As IntPtr, ByVal x1 As Double, ByVal x2 As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Fmpz_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Fmpz_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal FmpzPtr_x1 As IntPtr, ByVal FmpzPtr_x2 As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Fmpq_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Fmpq_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal FmpqPtr_x1 As IntPtr, ByVal FmpqPtr_x2 As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Mpfr_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Mpfr_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x1 As IntPtr, ByVal MpfrPtr_x2 As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  




'  **************************************************************

  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Get_Real", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Get_Real(ByVal MpfrPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Get_Imag", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Get_Imag(ByVal MpfrPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Real", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Real(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Imag", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Set_Imag(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfc_Set_Str(ByVal MpfcPtr As IntPtr, ByVal str As String, ByVal base As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Real_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Real_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfcPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Real_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfc_Real_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfcPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Imag_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Imag_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfcPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Imag_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfc_Imag_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfcPtr As IntPtr) As Int32
  End Function
  
  Friend  Function Mpfcr_Get_Real_Str_2(ByVal MpfcPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfc_Real_SnPrintf_SizeInBase10("%.RE", MpfcPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfc_Real_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfcPtr)
    Return sb.ToString()
  End Function
  
    Friend  Function Mpfcr_Get_Imag_Str_2(ByVal MpfcPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfc_Imag_SnPrintf_SizeInBase10("%.RE", MpfcPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfc_Imag_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfcPtr)
    Return sb.ToString()
  End Function
  
  Friend  Function Get_Str(ByVal MpfcPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Return Mpfcr_Get_Real_Str_2(MpfcPtr, digits, rnd) & " + " & Mpfcr_Get_Imag_Str_2(MpfcPtr, digits, rnd) & "j"
  End Function
  
  


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Cmp(ByVal MpfcPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Neg", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Neg(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
    End Function




    '***********************************



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y_MpfcPtr As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Ui(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Si(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Ui64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Si64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
    End Function


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_D(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Add_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Add_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Ui_Sub(ByVal MpfcPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Ui(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Si_Sub(ByVal MpfcPtr_res As IntPtr, ByVal x As Int32, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Si(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Ui64_Sub(ByVal MpfcPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Ui64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Si64_Sub(ByVal MpfcPtr_res As IntPtr, ByVal x As Int64, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Si64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_D_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_D_Sub(ByVal MpfcPtr_res As IntPtr, ByVal x As Double, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_D(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Fmpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Fmpz_Sub(ByVal MpfcPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Fmpq_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Fmpq_Sub(ByVal MpfcPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sub_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Sub_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mpfr_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mpfr_Sub(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Si(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Ui(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Si64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Ui64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_D(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mul_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Ui_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Ui_Div(ByVal MpfcPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Ui(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Si_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Si_Div(ByVal MpfcPtr_res As IntPtr, ByVal x As Int32, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Si(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Ui64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Ui64_Div(ByVal MpfcPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Ui64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Si64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Si64_Div(ByVal MpfcPtr_res As IntPtr, ByVal x As Int64, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Si64(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_D_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_D_Div(ByVal MpfcPtr_res As IntPtr, ByVal x As Double, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_D(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Fmpz(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Fmpz_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Fmpz_Div(ByVal MpfcPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Fmpq(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Fmpq_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Fmpq_Div(ByVal MpfcPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Div_Mpfr(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mpfr_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpfc_Mpfr_Div(ByVal MpfcPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr, ByVal rnd As Int32) As Int32
    End Function





  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32) As Int32
  End Function
  
  
  
  
' ******************  Mpfc:  Internal and Public Functions  *****************************
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow(res.MpfcPtr, x.MpfcPtr, y.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_D(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Double, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As Double) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow_D(res.MpfcPtr, x.MpfcPtr, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As Int32) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow_Si(res.MpfcPtr, x.MpfcPtr, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As UInt32) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow_Ui(res.MpfcPtr, x.MpfcPtr, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_Fmpz(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As fmpz_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow(res.MpfcPtr, x.MpfcPtr, y.FmpzPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_Fmpq(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As fmpq_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow(res.MpfcPtr, x.MpfcPtr, y.FmpqPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Pow_Mpfr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Pow_Mpfr(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfc_t, ByVal y As mpfr_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Pow(res.MpfcPtr, x.MpfcPtr, y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
' ******************  Mpfc:  Public Functions  *****************************
  
  
    
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Set_Nan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfc_Set_Nan(ByVal MpfcPtr_res As IntPtr)
  End Sub
  
  Public  Function nan() As mpfc_t
      Dim res As New mpfc_t
      Lib_Mpfc_Set_Nan(res.MpfcPtr)
      res.rc = 0
      Return res  
  End Function
    
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Swap", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfc_Swap(ByVal MpfcPtr_x As IntPtr, ByVal MpfcPtr_y As IntPtr)
  End Sub
  
  Public  Sub swap(x As mpfc_t, y As mpfc_t)
      Lib_Mpfc_Swap(x.MpfcPtr, y.MpfcPtr)
  End Sub

  
  
  
  Public  Function real(ByVal x As mpfc_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfc_Get_Real(res.MpfrPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  Public  Function imag(ByVal x As mpfc_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfc_Get_Imag(res.MpfrPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Arg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Arg(ByVal MpfrPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function arg(ByVal x As mpfc_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfc_Arg(res.MpfrPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Abs", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Abs(ByVal MpfrPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function abs(ByVal x As mpfc_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfc_Abs(res.MpfrPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Norm", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Norm(ByVal MpfrPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function norm(ByVal x As mpfc_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfc_Norm(res.MpfrPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
'**************************************  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Proj", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Proj(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function proj(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Proj(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Conj", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Conj(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function conj(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Conj(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sqr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Sqr(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sqr(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Sqr(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sqrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Sqrt(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sqrt(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Sqrt(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Exp(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function exp(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Exp(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Log", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Log(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Log(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Log10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Log10(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log10(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Log10(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Sin(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sin(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Sin(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Cos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Cos(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cos(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Cos(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Tan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Tan(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function tan(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Tan(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Sinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Sinh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sinh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Sinh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Cosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Cosh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cosh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Cosh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Tanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Tanh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function tanh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Tanh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Asin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Asin(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function asin(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Asin(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Acos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Acos(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function acos(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Acos(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Atan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Atan(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function atan(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Atan(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Asinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Asinh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function asinh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Asinh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Acosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Acosh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function acosh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Acosh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfc_Atanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfc_Atanh(ByVal MpfcPtr_res As IntPtr, ByVal MpfcPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function atanh(ByVal x As mpfc_t) As mpfc_t
      Dim res As New mpfc_t
      res.rc = Lib_Mpfc_Atanh(res.MpfcPtr, x.MpfcPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  
End Module


