
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpfr_t

  Friend MpfrPtr As IntPtr = Nothing
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
        Return Lib_Mpfr_Get_Prec(MpfrPtr)
    End Get

    Set(ByVal prec As Int32)
        Lib_Mpfr_Set_Prec(MpfrPtr, prec)
    End Set
  End Property
  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpfr_Init(MpfrPtr)
  End Sub
  
  
  Public Sub New()
      Init()
  End Sub
  


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Ui(MpfrPtr, ui32, mpfr.GetDefaultRoundingMode())
  End Sub
  
   

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Ui64(MpfrPtr, ui64, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  Public Sub New(ByVal si32 As Int32)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Si(MpfrPtr, si32, mpfr.GetDefaultRoundingMode())
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Si64(MpfrPtr, si64, mpfr.GetDefaultRoundingMode())
  End Sub
  

  Public Sub New(ByVal d As Single)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Flt(MpfrPtr, d, mpfr.GetDefaultRoundingMode())
  End Sub
  
  

  Public Sub New(ByVal d As Double)
      Init()
      rc = mpfr.Lib_Mpfr_Set_D(MpfrPtr, d, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal z As fmpz_t)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Fmpz(MpfrPtr, z.FmpzPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  Public Sub New(ByVal q As fmpq_t)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Fmpq(MpfrPtr, q.FmpqPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  


    Public Sub New(ByVal x As mpfr_t)
      Init()
      rc = mpfr.Lib_Mpfr_Set(MpfrPtr, x.MpfrPtr, mpfr.GetDefaultRoundingMode())
    End Sub
    
    
    
    
    
  
  Public Sub New(ByVal s As String)
      Init()
      rc = mpfr.Lib_Mpfr_Set_Str(MpfrPtr, s, 10, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Mpfr_Clear(MpfrPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpfr_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpfr_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return mpfr.Get_Str( MpfrPtr, 10, getDPS(), mpfr.GetDefaultRoundingMode())
  End Function




  Public Function __str__() As String
    Return mpfr.Get_Str(MpfrPtr, 10, getDPS(), mpfr.GetDefaultRoundingMode())
  End Function


  Public Function __repr__() As String
    Return  "mpfr_t('" & mpfr.Get_Str(MpfrPtr, 10, getDPS(), mpfr.GetDefaultRoundingMode()) & "')"
  End Function
  
  
    
  Public  Sub Print()
      Lib_Mpfr_Print("%.RE", MpfrPtr)
  End Sub




  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As String
      Return mpfr.Get_Str(m1.MpfrPtr, 10, getDPS(), mpfr.GetDefaultRoundingMode())
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As mpfr_t
    Dim m1 As New mpfr_t
    m1.rc = mpfr.Lib_Mpfr_Set_Str(m1.MpfrPtr, s, 10, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpfr_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpfr_t
'    Dim m1 As New mpfr_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator





  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As UInt32
    Return mpfr.Lib_Mpfr_Get_Ui(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpfr_t
      Dim m1 As New mpfr_t
      m1.rc = mpfr.Lib_Mpfr_Set_Ui(m1.MpfrPtr, ui, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As UInt64
    Return mpfr.Lib_Mpfr_Get_Ui64(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui64 As UInt64) As mpfr_t
      Dim m1 As New mpfr_t
      m1.rc = mpfr.Lib_Mpfr_Set_Ui64(m1.MpfrPtr, ui64, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As mpfr_t) As Int32
    Return mpfr.Lib_Mpfr_Get_Si(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpfr_t
    Dim m1 As New mpfr_t
      m1.rc = mpfr.Lib_Mpfr_Set_Si(m1.MpfrPtr, si, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As Int64
    Return mpfr.Lib_Mpfr_Get_Si64(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si64 As Int64) As mpfr_t
      Dim m1 As New mpfr_t
      m1.rc = mpfr.Lib_Mpfr_Set_Si64(m1.MpfrPtr, si64, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As Single
      Return mpfr.Lib_Mpfr_Get_Flt(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Single) As mpfr_t
    Dim m1 As New mpfr_t
    m1.rc = mpfr.Lib_Mpfr_Set_Flt(m1.MpfrPtr, d, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As Double
      Return mpfr.Lib_Mpfr_Get_D(m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpfr_t
    Dim m1 As New mpfr_t
    m1.rc = mpfr.Lib_Mpfr_Set_D(m1.MpfrPtr, d, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As fmpz_t
      Dim z1 As New fmpz_t
      mpfr.Lib_Mpfr_Get_Fmpz(z1.FmpzPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
      Return z1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal z As fmpz_t) As mpfr_t
    Dim m1 As New mpfr_t
    m1.rc = mpfr.Lib_Mpfr_Set_Fmpz(m1.MpfrPtr, z.FmpzPtr, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpfr_t) As fmpq_t
      Dim q1 As New fmpq_t
      mpfr.Lib_Mpfr_Get_Fmpz(q1.FmpqPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
      Return q1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal q As fmpq_t) As mpfr_t
    Dim m1 As New mpfr_t
    m1.rc = mpfr.Lib_Mpfr_Set_Fmpq(m1.MpfrPtr, q.FmpqPtr, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As Boolean
      Return (mpfr.Lib_Mpfr_Cmp(m1.MpfrPtr, m2.MpfrPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpfr_t) As mpfr_t
    Dim m3 As New mpfr_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Neg(m3.MpfrPtr, m1.MpfrPtr, mpfr.GetDefaultRoundingMode())
      Return m3
  End Operator
  



    '*********************************

  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Add(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal ui As UInt32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal si As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal ui As UInt64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal ui As UInt64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal si As Int64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal d As Double) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_D(m3.MpfrPtr, m1.MpfrPtr, d, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal d As Double, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_D(m3.MpfrPtr, m1.MpfrPtr, d, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal z As fmpz_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Fmpz(m3.MpfrPtr, m1.MpfrPtr, z.FmpzPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal z As fmpz_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Fmpz(m3.MpfrPtr, m1.MpfrPtr, z.FmpzPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As mpfr_t, ByVal q As fmpq_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Fmpq(m3.MpfrPtr, m1.MpfrPtr, q.FmpqPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator +(ByVal q As fmpq_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Add_Fmpq(m3.MpfrPtr, m1.MpfrPtr, q.FmpqPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  
  
  
  
  
  
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Sub(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Ui_Sub(m3.MpfrPtr, ui, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal ui As UInt32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Si_Sub(m3.MpfrPtr, si, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal si As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui As UInt64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Ui64_Sub(m3.MpfrPtr, ui, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal ui As UInt64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Si64_Sub(m3.MpfrPtr, si, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal si As Int64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
      Return m3
  End Operator
    
  
  
  Public Shared Operator -(ByVal d As Double, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_D_Sub(m3.MpfrPtr, d, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal d As Double) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_D(m3.MpfrPtr, m1.MpfrPtr, d, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal z As fmpz_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Fmpz(m3.MpfrPtr, m1.MpfrPtr, z.FmpzPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -( ByVal z As fmpz_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Fmpz_Sub(m3.MpfrPtr, z.FmpzPtr, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpfr_t, ByVal q As fmpq_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Sub_Fmpq(m3.MpfrPtr, m1.MpfrPtr, q.FmpqPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator -( ByVal q As fmpq_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Fmpq_Sub(m3.MpfrPtr, q.FmpqPtr, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  
  
  
  
  
  
  
  Public Shared Operator *(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As mpfr_t, ByVal ui As UInt32) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As mpfr_t, ByVal si As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  
  Public Shared Operator *(ByVal m1 As mpfr_t, ByVal ui As UInt64) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As mpfr_t, ByVal si As Int64) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Mul_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
    Return m3
  End Operator
        


    Public Shared Operator *(ByVal x As mpfr_t, ByVal y As fmpz_t) As mpfr_t
        Dim res As New mpfr_t()
        res.rc = mpfr.Lib_Mpfr_Mul_Fmpz(res.MpfrPtr, x.MpfrPtr, y.FmpzPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpz_t, ByVal y As mpfr_t) As mpfr_t
        Dim res As New mpfr_t()
        res.rc = mpfr.Lib_Mpfr_Mul_Fmpz(res.MpfrPtr, y.MpfrPtr, x.FmpzPtr, GetDefaultRoundingMode())
        Return res
    End Operator
    


    Public Shared Operator *(ByVal x As mpfr_t, ByVal y As fmpq_t) As mpfr_t
        Dim res As New mpfr_t()
        res.rc = mpfr.Lib_Mpfr_Mul_Fmpq(res.MpfrPtr, x.MpfrPtr, y.FmpqPtr, GetDefaultRoundingMode())
        Return res
    End Operator


    Public Shared Operator *(ByVal x As fmpq_t, ByVal y As mpfr_t) As mpfr_t
        Dim res As New mpfr_t()
        res.rc = mpfr.Lib_Mpfr_Mul_Fmpq(res.MpfrPtr, y.MpfrPtr, x.FmpqPtr, GetDefaultRoundingMode())
        Return res
    End Operator
  
  
  
  
  
  
  
  
  
  
  
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Div(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Ui_Div(m3.MpfrPtr, ui, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal ui As UInt32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Ui(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Si_Div(m3.MpfrPtr, si, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal si As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Si(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Ui64_Div(m3.MpfrPtr, ui, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal ui As UInt64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Ui64(m3.MpfrPtr, m1.MpfrPtr, ui, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Si64_Div(m3.MpfrPtr, si, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal si As Int64) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Si64(m3.MpfrPtr, m1.MpfrPtr, si, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal d As Double, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_D_Div(m3.MpfrPtr, d, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal d As Double) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_D(m3.MpfrPtr, m1.MpfrPtr, d, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal z As fmpz_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Fmpz(m3.MpfrPtr, m1.MpfrPtr, z.FmpzPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal z As fmpz_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Fmpz_Div(m3.MpfrPtr, z.FmpzPtr, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As mpfr_t, ByVal q As fmpq_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Div_Fmpq(m3.MpfrPtr, m1.MpfrPtr, q.FmpqPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal q As fmpq_t, ByVal m1 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
          m3.rc = mpfr.Lib_Mpfr_Fmpq_Div(m3.MpfrPtr, q.FmpqPtr, m1.MpfrPtr, GetDefaultRoundingMode())
      Return m3
  End Operator
  
  
  
  
    '*********************************

  
  
  
  
  
  Public Shared Operator &(ByVal m1 As mpfr_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpfr_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Pow(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpfr_t, ByVal n As UInt32) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Pow_Si(m3.MpfrPtr, m1.MpfrPtr, CInt(n), GetDefaultRoundingMode())
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpfr_t, ByVal n As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Pow_Si(m3.MpfrPtr, m1.MpfrPtr, n, GetDefaultRoundingMode())
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Pow(m3.MpfrPtr, MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
'      MsgBox("pow")      
      m3.rc = mpfr.Lib_Mpfr_Pow_Si(m3.MpfrPtr, MpfrPtr, n, GetDefaultRoundingMode())
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpfr_t) As mpfr_t
      Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Div(m3.MpfrPtr, MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpfr_t
      Dim m3 As New mpfr_t()
      Dim m2 As New mpfr_t(n1)
      m3.rc = mpfr.Lib_Mpfr_Div(m3.MpfrPtr, MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Function




  Public Shared Operator \(ByVal m1 As mpfr_t, ByVal m2 As mpfr_t) As mpfr_t
    Dim m3 As New mpfr_t()
      m3.rc = mpfr.Lib_Mpfr_Div(m3.MpfrPtr, m1.MpfrPtr, m2.MpfrPtr, GetDefaultRoundingMode())
    Return m3
  End Operator
  
  
  
  Public Function fits_ulong() As Boolean
      Return CBool(mpfr.Lib_Fits_Ulong_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_slong() As Boolean
      Return CBool(mpfr.Lib_Fits_Slong_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_uint() As Boolean
      Return CBool(mpfr.Lib_Fits_Uint_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_sint() As Boolean
      Return CBool(mpfr.Lib_Fits_Sint_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_ushort() As Boolean
      Return CBool(mpfr.Lib_Fits_Ushort_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_sshort() As Boolean
      Return CBool(mpfr.Lib_Fits_Sshort_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_uintmax() As Boolean
      Return CBool(mpfr.Lib_Fits_Uintmax_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function fits_intmax() As Boolean
      Return CBool(mpfr.Lib_Fits_Intmax_P(MpfrPtr, GetDefaultRoundingMode()))
  End Function
  
  
  
  Public Function is_infinity() As Boolean
      Return CBool(mpfr.Lib_Mpfr_Inf_P(MpfrPtr))
  End Function
  
  
  
  Public Function is_number() As Boolean
      Return CBool(mpfr.Lib_Mpfr_Number_P(MpfrPtr))
  End Function
  
  
  
  Public Function is_zero() As Boolean
      Return CBool(mpfr.Lib_Mpfr_Zero_P(MpfrPtr))
  End Function
  
  
  
  Public Function is_regular() As Boolean
      Return CBool(mpfr.Lib_Mpfr_Regular_P(MpfrPtr))
  End Function
  
  
  ' needs second argument
  Public Function is_unordered() As Boolean
      Return CBool(mpfr.Lib_Mpfr_Unordered_P(MpfrPtr))
  End Function
  
  
  
  
  
  
  
  
  
  
  
End Class





Public Module mpfr

' ******************  Mpfr  Internal Functions*****************************
  
  
  
  Public Property prec() As Int32
    Get
        Return get_default_prec()
    End Get

    Set(ByVal prec As Int32)
        set_default_prec(prec)
    End Set
  End Property
  
  
  
  Public Property rounding_mode() As Int32
    Get
        Return GetDefaultRoundingMode()
    End Get

    Set(ByVal rnd As Int32)
        set_default_rounding_mode(rnd)
    End Set
  End Property
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Default_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Sub set_default_prec(ByVal prec As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Default_Rounding_Mode", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Sub set_default_rounding_mode(ByVal rnd As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Default_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Function get_default_prec() As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Default_Rounding_Mode", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function GetDefaultRoundingMode() As Int32
  End Function
  
  
  
  Public  Function get_default_rounding_mode() As Int32
      Return GetDefaultRoundingMode()
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Init(ByRef MpfrPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Clear(ByVal MpfrPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Sub Lib_Mpfr_Set_Prec(ByVal MpfrPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Prec", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Function Lib_Mpfr_Get_Prec(ByVal MpfrPtr As IntPtr) As Int32
  End Function
  
  
'*****************************************************************************  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set(ByVal x_MpfrPtr As IntPtr, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Ui(ByVal x_MpfrPtr As IntPtr, ByVal ui As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Si(ByVal x_MpfrPtr As IntPtr, ByVal i As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Ui64(ByVal x_MpfrPtr As IntPtr, ByVal ui64 As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Si64(ByVal x_MpfrPtr As IntPtr, ByVal si64 As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Flt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Flt(ByVal x_MpfrPtr As IntPtr, ByVal d As Single, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_D(ByVal x_MpfrPtr As IntPtr, ByVal d As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Fmpz(ByVal x_MpfrPtr As IntPtr, ByVal y_FmpzPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Set_Fmpq(ByVal x_MpfrPtr As IntPtr, ByVal y_FmpqPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfr_Set_Str(ByVal MpfrPtr As IntPtr, ByVal str As String, ByVal base As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Ui(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Si(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Ui64(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As UInt64
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Si64(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As Int64
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Flt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Flt(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As Single
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_D(ByVal MpfrPtr As IntPtr, ByVal rnd As Int32) As Double
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Fmpz(ByVal x_FmpzPtr As IntPtr, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32)  As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Get_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Get_Fmpq(ByVal x_FmpqPtr As IntPtr, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32)  As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Print(Templ As String, ByVal MpfrPtr As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfrPtr As IntPtr) As Int32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfr_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfrPtr As IntPtr) As Int32
  End Function
  
  Friend  Function Get_Str(ByVal MpfrPtr As IntPtr, ByVal base As Int32, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfr_SnPrintf_SizeInBase10("%.RE", MpfrPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfr_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfrPtr)
    Return sb.ToString()
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Cmp(ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Neg(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Ui(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Ui64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Si64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_D(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Fmpz(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Add_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Add_Fmpq(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui_Sub(ByVal MpfrPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Ui(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Si_Sub(ByVal MpfrPtr_res As IntPtr, ByVal x As Int32, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui64_Sub(ByVal MpfrPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Ui64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Si64_Sub(ByVal MpfrPtr_res As IntPtr, ByVal x As Int64, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Si64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_D_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_D_Sub(ByVal MpfrPtr_res As IntPtr, ByVal x As Double, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_D(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Fmpz(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fmpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fmpz_Sub(ByVal MpfrPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sub_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sub_Fmpq(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fmpq_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fmpq_Sub(ByVal MpfrPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Ui(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Si64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Ui64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_D(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Fmpz(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_Fmpq(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui_Div(ByVal MpfrPtr_res As IntPtr, ByVal x As UInt32, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Ui(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Si_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Si_Div(ByVal MpfrPtr_res As IntPtr, ByVal x As Int32, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui64_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui64_Div(ByVal MpfrPtr_res As IntPtr, ByVal x As UInt64, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Ui64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Si64_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Si64_Div(ByVal MpfrPtr_res As IntPtr, ByVal x As Int64, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Si64(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Int64, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_D_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_D_Div(ByVal MpfrPtr_res As IntPtr, ByVal x As Double, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_D(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As Double, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Fmpz(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpzPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fmpz_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fmpz_Div(ByVal MpfrPtr_res As IntPtr, ByVal FmpzPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_Fmpq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_Fmpq(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal FmpqPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fmpq_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fmpq_Div(ByVal MpfrPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr, ByVal MpfrPtr_y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Mul_2si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Mul_2si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Div_2si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Div_2si(ByVal MpfrPtr_res As IntPtr, ByVal MpfrPtr_x As IntPtr, ByVal y As UInt32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Ulong_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Ulong_P(ByVal MpfrPtr_res As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Slong_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Slong_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Uint_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Uint_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Sint_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Sint_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Ushort_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Ushort_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Sshort_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Sshort_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Uintmax_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Uintmax_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fits_Intmax_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fits_Intmax_P(ByVal MpfrPtr_x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Inf_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Inf_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Number_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Number_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Zero_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Zero_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Regular_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Regular_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Unordered_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Unordered_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Integer_P", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Integer_P(ByVal MpfrPtr_x As IntPtr) As Int32
  End Function
  
  
  
' ******************  Mpfr:  Internal and Public Functions*****************************  

  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Pow(ByVal res_MpfrPtr As IntPtr, ByVal x_MpfrPtr As IntPtr, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfr_t, ByVal y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Pow(res.MpfrPtr, x.MpfrPtr, y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Pow_Ui(ByVal res_MpfrPtr As IntPtr, ByVal x_MpfrPtr As IntPtr, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfr_t, ByVal y As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Pow_Ui(res.MpfrPtr, x.MpfrPtr, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Pow_Si(ByVal res_MpfrPtr As IntPtr, ByVal x_MpfrPtr As IntPtr, ByVal y As Int32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfr_t, ByVal y As Int32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Pow_Si(res.MpfrPtr, x.MpfrPtr, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Pow_Z", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Pow_Z(ByVal res_MpfrPtr As IntPtr, ByVal x_MpfrPtr As IntPtr, ByVal y_FmpzPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As mpfr_t, ByVal y As fmpz_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Pow_Z(res.MpfrPtr, x.MpfrPtr, y.FmpzPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui_Pow_Ui(ByVal res_MpfrPtr As IntPtr, ByVal x As UInt32, ByVal y As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As UInt32, ByVal y As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Ui_Pow_Ui(res.MpfrPtr, x, y, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ui_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ui_Pow(ByVal res_MpfrPtr As IntPtr, ByVal x As UInt32, ByVal y_MpfrPtr As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function pow(ByVal x As UInt32, ByVal y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Ui_Pow(res.MpfrPtr, x, y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  
  
' ******************  Mpfr:  Public Functions*****************************  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Nan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Set_Nan(ByVal x_MpfrPtr As IntPtr)
  End Sub
  
  Public  Function nan() As mpfr_t
      Dim x As New mpfr_t
      Lib_Mpfr_Set_Nan(x.MpfrPtr)
      x.rc = 0
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Inf", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Set_Inf(ByVal x_MpfrPtr As IntPtr, sign As Int32)
  End Sub
  
  Public  Function inf(sign As Int32) As mpfr_t
      Dim x As New mpfr_t
      Lib_Mpfr_Set_Inf(x.MpfrPtr, sign)
      x.rc = 0
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Set_Zero", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Set_Zero(ByVal x_MpfrPtr As IntPtr, sign As Int32)
  End Sub
  
  Public  Function zero(sign As Int32) As mpfr_t
      Dim x As New mpfr_t
      Lib_Mpfr_Set_Zero(x.MpfrPtr, sign)
      x.rc = 0
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Swap", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Swap(ByVal x_MpfrPtr As IntPtr, ByVal y_MpfrPtr As IntPtr)
  End Sub
  
  Public  Sub swap(x As mpfr_t, y As mpfr_t)
      Lib_Mpfr_Swap(x.MpfrPtr, y.MpfrPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sgn", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sgn(ByVal x_MpfrPtr As IntPtr) As Int32
  End Function
  
  Public  Function sgn(x As mpfr_t) As Int32
      Return Lib_Mpfr_Sgn(x.MpfrPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Const_Log2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Const_Log2(ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function const_log2() As mpfr_t
      Dim x As New mpfr_t
      x.rc = Lib_Mpfr_Const_Log2(x.MpfrPtr, GetDefaultRoundingMode())
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Const_Pi(ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function const_pi() As mpfr_t
      Dim x As New mpfr_t
      x.rc = Lib_Mpfr_Const_Pi(x.MpfrPtr, GetDefaultRoundingMode())
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Const_Euler", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Const_Euler(ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function const_euler() As mpfr_t
      Dim x As New mpfr_t
      x.rc = Lib_Mpfr_Const_Euler(x.MpfrPtr, GetDefaultRoundingMode())
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Const_Catalan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Const_Catalan(ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function const_catalan() As mpfr_t
      Dim x As New mpfr_t
      x.rc = Lib_Mpfr_Const_Catalan(x.MpfrPtr, GetDefaultRoundingMode())
      Return x  
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sqr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sqr(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sqr(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sqr(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sqrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sqrt(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sqrt(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sqrt(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rec_Sqrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rec_Sqrt(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rec_sqrt(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rec_Sqrt(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Cbrt", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Cbrt(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cbrt(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Cbrt(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Abs", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Abs(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function abs(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Abs(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Log", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Log(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Log(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Log2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Log2(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log2(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Log2(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Log10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Log10(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log10(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Log10(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Exp(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function exp(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Exp(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Exp2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Exp2(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function exp2(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Exp2(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Exp10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Exp10(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function exp10(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Exp10(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Cos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Cos(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cos(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Cos(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sin(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sin(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sin(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Tan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Tan(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function tan(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Tan(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sec", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sec(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sec(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sec(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Csc", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Csc(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function csc(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Csc(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Cot", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Cot(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cot(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Cot(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Acos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Acos(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function acos(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Acos(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Asin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Asin(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function asin(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Asin(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Atan", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Atan(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function atan(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Atan(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Cosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Cosh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function cosh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Cosh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sinh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sinh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sinh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Tanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Tanh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function tanh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Tanh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sech", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sech(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sech(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sech(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Csch", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Csch(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function csch(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Csch(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Coth", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Coth(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function coth(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Coth(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Acosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Acosh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function acosh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Acosh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Asinh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Asinh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function asinh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Asinh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Atanh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Atanh(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function atanh(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Atanh(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Log1p", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Log1p(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function log1p(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Log1p(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Expm1", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Expm1(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function expm1(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Expm1(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Eint", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Eint(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function eint(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Eint(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Li2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Li2(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function li2(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Li2(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Gamma", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Gamma(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function gamma(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Gamma(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Lngamma", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Lngamma(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function lngamma(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Lngamma(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Digamma", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Digamma(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function digamma(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Digamma(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Zeta", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Zeta(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function zeta(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Zeta(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Erf", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Erf(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function erf(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Erf(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Erfc", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Erfc(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function erfc(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Erfc(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_J0", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_J0(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function j0(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_J0(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_J1", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_J1(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function j1(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_J1(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Y0", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Y0(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function y0(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Y0(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Y1", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Y1(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function y1(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Y1(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ai", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ai(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function ai(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Ai(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rint", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rint(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rint(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rint(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rint_Ceil", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rint_Ceil(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rint_ceil(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rint_Ceil(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rint_Floor", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rint_Floor(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rint_floor(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rint_Floor(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rint_Round", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rint_Round(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rint_round(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rint_Round(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Rint_Trunc", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Rint_Trunc(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function rint_trunc(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Rint_Trunc(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Frac", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Frac(ByVal res As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function frac(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Frac(res.MpfrPtr, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Ceil", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Ceil(ByVal res As IntPtr, ByVal y As IntPtr) As Int32
  End Function
  
  Public  Function ceil(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Ceil(res.MpfrPtr, x.MpfrPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Floor", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Floor(ByVal res As IntPtr, ByVal y As IntPtr) As Int32
  End Function
  
  Public  Function floor(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Floor(res.MpfrPtr, x.MpfrPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Round", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Round(ByVal res As IntPtr, ByVal y As IntPtr) As Int32
  End Function
  
  Public  Function round(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Round(res.MpfrPtr, x.MpfrPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Trunc", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Trunc(ByVal res As IntPtr, ByVal y As IntPtr) As Int32
  End Function
  
  Public  Function trunc(x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Trunc(res.MpfrPtr, x.MpfrPtr)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sqrt_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sqrt_Ui(ByVal res As IntPtr, ByVal u As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sqrt(u As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sqrt_Ui(res.MpfrPtr, u, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fac_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fac_Ui(ByVal res As IntPtr, ByVal u As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function fac(u As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Fac_Ui(res.MpfrPtr, u, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Zeta_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Zeta_Ui(ByVal res As IntPtr, ByVal u As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function zeta(u As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Zeta_Ui(res.MpfrPtr, u, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Dim", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Dim(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function dim_(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Dim(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sin_Cos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sin_Cos(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sin_cos(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sin_Cos(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Atan2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Atan2(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function atan2(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Atan2(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Sinh_Cosh", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Sinh_Cosh(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function sinh_cosh(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Sinh_Cosh(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Agm", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Agm(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function agm(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Agm(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Hypot", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Hypot(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function hypot(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Hypot(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Modf", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Modf(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function modf(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Modf(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fmod", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fmod(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function fmod(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Fmod(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Remainder", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Remainder(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function remainder(x As mpfr_t, y As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Remainder(res.MpfrPtr, x.MpfrPtr,  y.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Root", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Root(ByVal res As IntPtr, ByVal x As IntPtr, ByVal u As UInt32, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function root(ByVal x As mpfr_t, ByVal u As UInt32) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Root(res.MpfrPtr, x.MpfrPtr,  u, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Jn", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Jn(ByVal res As IntPtr, ByVal n As UInt32, ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function jn(ByVal n As UInt32, ByVal x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Jn(res.MpfrPtr, n, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Yn", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Yn(ByVal res As IntPtr, ByVal n As UInt32, ByVal x As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function yn(ByVal n As UInt32, ByVal x As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Yn(res.MpfrPtr, n, x.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fma", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fma(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal z As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function fma(ByVal x As mpfr_t, ByVal y As mpfr_t, ByVal z As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Fma(res.MpfrPtr, x.MpfrPtr, y.MpfrPtr, z.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Fms", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfr_Fms(ByVal res As IntPtr, ByVal x As IntPtr, ByVal y As IntPtr, ByVal z As IntPtr, ByVal rnd As Int32) As Int32
  End Function
  
  Public  Function fms(ByVal x As mpfr_t, ByVal y As mpfr_t, ByVal z As mpfr_t) As mpfr_t
      Dim res As New mpfr_t
      res.rc = Lib_Mpfr_Fms(res.MpfrPtr, x.MpfrPtr, y.MpfrPtr, z.MpfrPtr, GetDefaultRoundingMode())
      Return res
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfr_Urandomb", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfr_Urandomb(ByVal MpfrPtr_res As IntPtr, ByVal GmpRandPtr_state As IntPtr)
  End Sub
  
  
  Public  Function urandomb(ByVal state As gmp_randstate_t) As mpfr_t
      Dim res As New mpfr_t
      Lib_Mpfr_Urandomb(res.MpfrPtr, state.GmpRandPtr)
      Return res
  End Function
  
  
  
End Module


