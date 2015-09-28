
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class fmpq_t
  
  Friend FmpqPtr As IntPtr = Nothing
  
  
  
  Public Property num() As fmpz_t
      Get
          Dim m1 As New fmpz_t
          Lib_Fmpq_Get_Num(m1.FmpzPtr, FmpqPtr)
          Return m1
    End Get

    Set(ByVal m1 As fmpz_t)
          Lib_Fmpq_Set_Num(FmpqPtr, m1.FmpzPtr)
    End Set
  End Property
  
  
  
  Public Property den() As fmpz_t
    Get
          Dim m1 As New fmpz_t
          Lib_Fmpq_Get_Den(m1.FmpzPtr, FmpqPtr)
          Return m1
    End Get

    Set(ByVal m1 As fmpz_t)
          Lib_Fmpq_Set_Den(FmpqPtr, m1.FmpzPtr)
    End Set
  End Property
  
  
    
  Private Sub Init()
      mp4.Init()
      Lib_Fmpq_Init(FmpqPtr)
  End Sub
  
  
  
  Public Sub New()
      Init()
  End Sub
  
  
  
  Public Sub New(ByVal p As fmpq_t)
      Init()
      fmpq.Lib_Fmpq_Set(FmpqPtr, p.FmpqPtr)
  End Sub
  
  
  
  Public Sub New(ByVal x As mpfr_t)
      Init()
      Lib_Mpfr_Get_Fmpq(FmpqPtr, x.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  
  
  Public Sub New(ByVal p As fmpz_t)
      Init()
      Lib_Fmpq_Set_Fmpz(FmpqPtr, p.FmpzPtr)
  End Sub
  
  
  
  Public Sub New(ByVal p As fmpz_t, ByVal q As fmpz_t)
      Init()
      Lib_Fmpq_Set_Fmpz_Frac(FmpqPtr, p.FmpzPtr, q.FmpzPtr)
  End Sub
  
  
  
  
  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Fmpq_Set_Ui_Ui(FmpqPtr, ui32, 1)
  End Sub
  
  
  
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Fmpq_Set_Si_Si(FmpqPtr, si32, 1)
  End Sub
  
  
  
  Public Sub New(ByVal p As UInt32, ByVal q As UInt32)
      Init()
      Lib_Fmpq_Set_Ui_Ui(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As UInt32, ByVal q As Int32)
      Init()
      Lib_Fmpq_Set_Ui_Si(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As Int32, ByVal q As UInt32)
      Init()
      Lib_Fmpq_Set_Si_Ui(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As Int32, ByVal q As Int32)
      Init()
      Lib_Fmpq_Set_Si_Si(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Lib_Fmpq_Set_Ui64_Ui64(FmpqPtr, ui64, 1)
  End Sub
  
  
  
  Public Sub New(ByVal si64 As Int64)
      Init()
      Lib_Fmpq_Set_Si64_Si64(FmpqPtr, si64, 1)
  End Sub
  
  
  
  Public Sub New(ByVal p As UInt64, ByVal q As UInt64)
      Init()
      Lib_Fmpq_Set_Ui64_Ui64(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As UInt64, ByVal q As Int64)
      Init()
      Lib_Fmpq_Set_Ui64_Si64(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As Int64, ByVal q As UInt64)
      Init()
      Lib_Fmpq_Set_Si64_Ui64(FmpqPtr, p, q)
  End Sub
  
  
  
  Public Sub New(ByVal p As Int64, ByVal q As Int64)
      Init()
      Lib_Fmpq_Set_Si64_Si64(FmpqPtr, p, q)
  End Sub
  
  
  
  
  Public Sub New(ByVal d As Double)
      Init()
      Lib_Fmpq_Set_D(FmpqPtr, d)
  End Sub
  
  
  
  Public Sub New(ByVal s As String)
      Init()
      Lib_Fmpq_Set_Str(FmpqPtr, s, 10)
  End Sub
  
  
  
  Protected Overrides Sub Finalize()
    Lib_Fmpq_Clear(FmpqPtr)
    MyBase.Finalize()
  End Sub
  
  
  
  Public Shared Operator IsTrue(ByVal m1 As fmpq_t) As Boolean
      Return (m1 = 0)
  End Operator
  
  
  
  Public Shared Operator IsFalse(ByVal m1 As fmpq_t) As Boolean
      Return (m1 <> 0)
  End Operator
  
  
  
  Public  Sub Print()
      Lib_Fmpq_Print(FmpqPtr)
  End Sub
  
  
  
  Public Overrides Function ToString() As String
    Return fmpq.Get_Str(10, FmpqPtr)
  End Function
  
  
  
  Public Function __str__() As String
    Return fmpq.Get_Str(10, FmpqPtr)
  End Function
  
  
  
  Public Function __repr__() As String
    Return  "fmpq_t('" & fmpq.Get_Str(10, FmpqPtr) & "')"
  End Function
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As fmpq_t) As String
      Return fmpq.Get_Str(10, m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal s As String) As fmpq_t
    Dim m1 As New fmpq_t
    fmpq.Lib_Fmpq_Set_Str(m1.FmpqPtr, s, 10)
    Return m1
  End Operator


'  Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As fmpq_t
'    Dim m1 As New fmpq_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As Double
      Return fmpq.Lib_Fmpq_Get_D(m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As fmpq_t
    Dim m1 As New fmpq_t
    fmpq.Lib_Fmpq_Set_D(m1.FmpqPtr, d)
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As Int32
    Return fmpq.Lib_Fmpq_Get_Si(m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal si As Int32) As fmpq_t
    Dim m1 As New fmpq_t
      fmpq.Lib_Fmpq_Set_Si_Si(m1.FmpqPtr, si, 1)
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As Int64
    Return fmpq.Lib_Fmpq_Get_Si64(m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal si64 As Int64) As fmpq_t
      Dim m1 As New fmpq_t
      fmpq.Lib_Fmpq_Set_Si64_Si64(m1.FmpqPtr, si64, 1)
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As UInt32
    Return fmpq.Lib_Fmpq_Get_Ui(m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal ui As UInt32) As fmpq_t
      Dim m1 As New fmpq_t
      fmpq.Lib_Fmpq_Set_Ui_Ui(m1.FmpqPtr, ui, 1)
    Return m1
  End Operator
  
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpq_t) As UInt64
    Return fmpq.Lib_Fmpq_Get_Ui64(m1.FmpqPtr)
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal ui64 As UInt64) As fmpq_t
      Dim m1 As New fmpq_t
      fmpq.Lib_Fmpq_Set_Ui64_Ui64(m1.FmpqPtr, ui64, 1)
    Return m1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal m1 As fmpq_t) As fmpz_t
    Dim z1 As New fmpz_t
    fmpq.Lib_Fmpq_Get_Fmpz(z1.FmpzPtr, m1.FmpqPtr)
    Return z1
  End Operator
  
  
  
  Public Shared Widening Operator CType(ByVal z1 As fmpz_t) As fmpq_t
      Dim m1 As New fmpq_t
      fmpq.Lib_Fmpq_Set_Fmpz(m1.FmpqPtr, z1.FmpzPtr)
    Return m1
  End Operator
  
  
  
  Public Shared Operator =(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) = 0)
  End Operator
  
  
  
  Public Shared Operator <>(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) <> 0)
  End Operator
  
  
  
  Public Shared Operator <=(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) <= 0)
  End Operator
  
  
  
  Public Shared Operator <(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) < 0)
  End Operator
  
  
  
  Public Shared Operator >=(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) >= 0)
  End Operator
  
  
  
  Public Shared Operator >(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As Boolean
      Return (fmpq.Lib_Fmpq_Cmp(m1.FmpqPtr, m2.FmpqPtr) > 0)
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t(m1)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Neg(m3.FmpqPtr, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  '***********************************************************************
  
  
  
  Public Shared Operator +(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Add(m3.FmpqPtr, m1.FmpqPtr, m2.FmpqPtr)
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As fmpq_t, ByVal ui As UInt32) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
    Return m3
  End Operator
  
  Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
    Return m3
  End Operator
  
  

  Public Shared Operator +(ByVal m1 As fmpq_t, ByVal si As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Si(m3.FmpqPtr, m1.FmpqPtr, si)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal si As Int32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Si(m3.FmpqPtr, m1.FmpqPtr, si)
    Return m3
  End Operator
  
  
  
  
  Public Shared Operator +(ByVal m1 As fmpq_t, ByVal si64 As Int64) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Si64(m3.FmpqPtr, m1.FmpqPtr, si64)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal si64 As Int64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Si64(m3.FmpqPtr, m1.FmpqPtr, si64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As fmpq_t, ByVal ui64 As UInt64) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Ui64(m3.FmpqPtr, m1.FmpqPtr, ui64)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal ui64 As UInt64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Add_Ui64(m3.FmpqPtr, m1.FmpqPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Sub(m3.FmpqPtr, m1.FmpqPtr, m2.FmpqPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Ui_Sub(m3.FmpqPtr, ui, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t, ByVal ui As UInt32) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Sub_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
      Return m3
  End Operator



  Public Shared Operator -(ByVal si As Int32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Si_Sub(m3.FmpqPtr, si, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t, ByVal si As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Sub_Si(m3.FmpqPtr, m1.FmpqPtr, si)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui64 As UInt64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Ui64_Sub(m3.FmpqPtr, ui64, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t, ByVal ui64 As UInt64) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Sub_Ui64(m3.FmpqPtr, m1.FmpqPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal si64 As Int64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Si64_Sub(m3.FmpqPtr, si64, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpq_t, ByVal si64 As Int64) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Sub_Si64(m3.FmpqPtr, m1.FmpqPtr, si64)
      Return m3
  End Operator
  
  
  
  
  
  
  
  
  
  Public Shared Operator *(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul(m3.FmpqPtr, m1.FmpqPtr, m2.FmpqPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpq_t, ByVal ui As UInt32) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Si(m3.FmpqPtr, m1.FmpqPtr, si)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpq_t, ByVal si As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Si(m3.FmpqPtr, m1.FmpqPtr, si)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal ui64 As UInt64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Ui64(m3.FmpqPtr, m1.FmpqPtr, CUInt(ui64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpq_t, ByVal ui64 As UInt64) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Ui64(m3.FmpqPtr, m1.FmpqPtr, CUInt(ui64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si64 As Int64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Si64(m3.FmpqPtr, m1.FmpqPtr, CInt(si64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpq_t, ByVal si64 As Int64) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Mul_Si64(m3.FmpqPtr, m1.FmpqPtr, CInt(si64))
    Return m3
  End Operator
  
  
  
  
  Public Shared Operator /(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Div(m3.FmpqPtr, m1.FmpqPtr, m2.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Ui_Div(m3.FmpqPtr, ui, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpq_t, ByVal ui As UInt32) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Div_Ui(m3.FmpqPtr, m1.FmpqPtr, ui)
      Return m3
  End Operator



  Public Shared Operator /(ByVal si As Int32, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Si_Div(m3.FmpqPtr, si, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpq_t, ByVal si As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Div_Si(m3.FmpqPtr, m1.FmpqPtr, si)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui64 As UInt64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Ui64_Div(m3.FmpqPtr, ui64, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpq_t, ByVal ui64 As UInt64) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Div_Ui64(m3.FmpqPtr, m1.FmpqPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal si64 As Int64, ByVal m1 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Si64_Div(m3.FmpqPtr, si64, m1.FmpqPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpq_t, ByVal si64 As Int64) As fmpq_t
      Dim m3 As New fmpq_t()
          fmpq.Lib_Fmpq_Div_Si64(m3.FmpqPtr, m1.FmpqPtr, si64)
      Return m3
  End Operator
  
  
  
  
  '***********************************************************************
  
  
  
  Public Shared Operator &(ByVal m1 As fmpq_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As fmpq_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      Dim n As Int32 = CInt(m2)
      fmpq.Lib_Fmpq_Pow_Si(m3.FmpqPtr, m1.FmpqPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As fmpq_t, ByVal n As UInt32) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Pow_Si(m3.FmpqPtr, m1.FmpqPtr, CInt(n))
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As fmpq_t, ByVal n As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Pow_Si(m3.FmpqPtr, m1.FmpqPtr, n)
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      Dim n As Int32 = CInt(m2)
      fmpq.Lib_Fmpq_Pow_Si(m3.FmpqPtr, FmpqPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
'      MsgBox("pow")      
      fmpq.Lib_Fmpq_Pow_Si(m3.FmpqPtr, FmpqPtr, n)
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As fmpq_t) As fmpq_t
      Dim m3 As New fmpq_t()
      fmpq.Lib_Fmpq_Div(m3.FmpqPtr, FmpqPtr, m2.FmpqPtr)
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As fmpq_t
      Dim m3 As New fmpq_t()
      Dim m2 As New fmpq_t(n1)
      fmpq.Lib_Fmpq_Div(m3.FmpqPtr, FmpqPtr, m2.FmpqPtr)
    Return m3
  End Function



  Public Shared Operator Mod(ByVal m1 As fmpq_t, ByVal m2 As fmpz_t) As fmpq_t
    Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Mod_Fmpz(m3.FmpqPtr, m1.FmpqPtr, m2.FmpzPtr)
    Return m3
  End Operator



  Public Shared Operator \(ByVal m1 As fmpq_t, ByVal m2 As fmpq_t) As fmpq_t
    Dim m3 As New fmpq_t()
        fmpq.Lib_Fmpq_Div(m3.FmpqPtr, m1.FmpqPtr, m2.FmpqPtr)
    Return m3
  End Operator
  

End Class







Public Module fmpq
  
  
' ******************  Fmpq:  Internal Functions  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Init(ByRef FmpqPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Clear(ByVal FmpqPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Print(ByVal FmpqPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui(ByVal FmpqPtr As IntPtr, ByVal a As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si(ByVal FmpqPtr As IntPtr, ByVal a As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui64(ByVal FmpqPtr As IntPtr, ByVal a As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si64(ByVal FmpqPtr As IntPtr, ByVal a As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui_Ui(ByVal FmpqPtr As IntPtr, ByVal a As UInt32, ByVal b As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui_Si(ByVal FmpqPtr As IntPtr, ByVal a As UInt32, ByVal b As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si_Ui(ByVal FmpqPtr As IntPtr, ByVal a As Int32, ByVal b As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si_Si(ByVal FmpqPtr As IntPtr, ByVal a As Int32, ByVal b As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui64_Ui64(ByVal FmpqPtr As IntPtr, ByVal a As UInt64, ByVal b As UInt64)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Ui64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Ui64_Si64(ByVal FmpqPtr As IntPtr, ByVal a As UInt64, ByVal b As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si64_Ui64(ByVal FmpqPtr As IntPtr, ByVal a As Int64, ByVal b As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si64_Si64(ByVal FmpqPtr As IntPtr, ByVal a As Int64, ByVal b As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Fmpz_Frac", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Fmpz_Frac(ByVal FmpqPtr_x As IntPtr, ByVal FmpzPtr_p As IntPtr, ByVal FmpzPtr_q As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Fmpz(ByVal FmpqPtr_x As IntPtr, ByVal FmpzPtr_p As IntPtr)
  End Sub
  
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Num", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Num(ByVal FmpqPtr_x As IntPtr, ByVal FmpzPtr_p As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Den", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Den(ByVal FmpqPtr_x As IntPtr, ByVal FmpzPtr_p As IntPtr)
  End Sub
  
  
  
  
  
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set(ByVal FmpqPtr_x As IntPtr, ByVal FmpqPtr_p As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_D(ByVal FmpqPtr As IntPtr, ByVal d As Double)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Fmpq_Set_Str(ByVal FmpqPtr As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Get_Ui(ByVal FmpqPtr As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Get_Si(ByVal FmpqPtr As IntPtr) As Int32
  End Function
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Get_Ui64(ByVal FmpqPtr As IntPtr) As UInt64
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Get_Si64(ByVal FmpqPtr As IntPtr) As Int64
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Get_D(ByVal FmpqPtr As IntPtr) As Double
  End Function
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Get_Fmpz(ByVal FmpzPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr)
  End Sub
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Num", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Get_Num(ByVal FmpzPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Den", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Get_Den(ByVal FmpzPtr_res As IntPtr, ByVal FmpqPtr_x As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_SizeInBase", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_SizeInBase(ByVal FmpqPtr As IntPtr, ByVal base As Int32) As UInt32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Fmpq_Get_Str(ByVal sb As StringBuilder, ByVal base As Int32, ByVal FmpqPtr As IntPtr) As IntPtr
  End Function

  Friend  Function Get_Str(ByVal base As Int32, ByVal FmpqPtr As IntPtr) As String
    Dim StrSize As Int32 = CInt(Lib_Fmpq_SizeInBase(FmpqPtr, 10))
    Dim sb As  New StringBuilder(StrSize)
    Dim res As IntPtr = Lib_Fmpq_Get_Str(sb, base, FmpqPtr)
    Return sb.ToString()
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpq_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  
  
  '***********************************************************************
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Add_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Add_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Add_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Sub(ByVal FmpqPtrX As IntPtr, ByVal FmpqPtrY As IntPtr, ByVal FmpqPtrZ As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Ui_Sub(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Si_Sub(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Sub_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
  End Sub
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Ui64_Sub(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Sub_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Si64_Sub(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Sub_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
  End Sub
  
  
  
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul(ByVal FmpqPtrX As IntPtr, ByVal FmpqPtrY As IntPtr, ByVal FmpqPtrZ As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div(ByVal FmpqPtrX As IntPtr, ByVal FmpqPtrY As IntPtr, ByVal FmpqPtrZ As IntPtr)
  End Sub  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Ui_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Ui_Div(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Si_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Si_Div(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
  End Sub
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Ui64_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Ui64_Div(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Si64_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Si64_Div(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
  End Sub
  
  
  
  
  '***********************************************************************
  
  
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mod_Fmpz", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mod_Fmpz(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
' ******************  Fmpq:  Internal and Public Functions  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
  End Sub
  
  Public  Function pow(ByVal y As fmpq_t, ByVal u As Int32) As fmpq_t
      Dim x As New fmpq_t
      Lib_Fmpq_Pow_Si(x.FmpqPtr, y.FmpqPtr, u)
      Return x
  End Function
  
  
  
End Module
  
  
  
