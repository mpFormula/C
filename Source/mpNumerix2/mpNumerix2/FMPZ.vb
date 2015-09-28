
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class fmpz_t


  Friend FmpzPtr As IntPtr = Nothing
  
  
    
  Private Sub Init()
      mp4.Init()
      Lib_Fmpz_Init(FmpzPtr)
  End Sub
  
  

  ''' <summary>
  ''' Create a new fmpz_t
  ''' </summary>
  Public Sub New()
      Init()
  End Sub
  
  
  Public Sub New(ByVal x As fmpz_t)
      Init()
      Lib_Fmpz_Set(FmpzPtr, x.FmpzPtr)
  End Sub
  
  
  Public Sub New(ByVal x As fmpq_t)
      Init()
      Lib_Fmpq_Get_Fmpz(FmpzPtr, x.FmpqPtr)
  End Sub
  
  
  
  Public Sub New(ByVal x As mpfr_t)
      Init()
      Lib_Mpfr_Get_Fmpz(FmpzPtr, x.MpfrPtr, mpfr.GetDefaultRoundingMode())
  End Sub
  
  
  ''' <summary>
  ''' Create a new fmpz_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Fmpz_Set_Si(FmpzPtr, si32)
  End Sub
  
  

  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Fmpz_Set_Ui(FmpzPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Lib_Fmpz_Set_Si64(FmpzPtr, si64)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Lib_Fmpz_Set_Ui64(FmpzPtr, ui64)
  End Sub
  

  Public Sub New(ByVal d As Double)
      Init()
      Lib_Fmpz_Set_D(FmpzPtr, d)
  End Sub
  

  Public Sub New(ByVal s As String)
      Init()
      Lib_Fmpz_Set_Str(FmpzPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Fmpz_Clear(FmpzPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As fmpz_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As fmpz_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return fmpz.Get_Str(10, FmpzPtr)
  End Function
  
  
  Public  Sub Print()
      Lib_Fmpz_Print(FmpzPtr)
  End Sub



  Public Function __str__() As String
    Return fmpz.Get_Str(10, FmpzPtr)
  End Function


  Public Function __repr__() As String
    Return  "fmpz_t('" & fmpz.Get_Str(10, FmpzPtr) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As fmpz_t) As String
      Return fmpz.Get_Str(10, m1.FmpzPtr)
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As fmpz_t
    Dim m1 As New fmpz_t
    fmpz.Lib_Fmpz_Set_Str(m1.FmpzPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As fmpz_t
'    Dim m1 As New fmpz_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As Double
    
    'MsgBox("Double")
      Return fmpz.Lib_Fmpz_Get_D(m1.FmpzPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As fmpz_t
    Dim m1 As New fmpz_t
    fmpz.Lib_Fmpz_Set_D(m1.FmpzPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As Int32
    Return fmpz.Lib_Fmpz_Get_Si(m1.FmpzPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As fmpz_t
    Dim m1 As New fmpz_t
      fmpz.Lib_Fmpz_Set_Si(m1.FmpzPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As Int64
    Return fmpz.Lib_Fmpz_Get_Si64(m1.FmpzPtr)
  End Operator
  
  Public Shared Widening Operator CType(ByVal si64 As Int64) As fmpz_t
      Dim m1 As New fmpz_t
      fmpz.Lib_Fmpz_Set_Si64(m1.FmpzPtr, si64)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As UInt32
    Return fmpz.Lib_Fmpz_Get_Ui(m1.FmpzPtr)
  End Operator
  
  Public Shared Widening Operator CType(ByVal ui As UInt32) As fmpz_t
      Dim m1 As New fmpz_t
      fmpz.Lib_Fmpz_Set_Ui(m1.FmpzPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Narrowing Operator CType(ByVal m1 As fmpz_t) As UInt64
    Return fmpz.Lib_Fmpz_Get_Ui64(m1.FmpzPtr)
  End Operator
  
  Public Shared Widening Operator CType(ByVal ui64 As UInt64) As fmpz_t
      Dim m1 As New fmpz_t
      fmpz.Lib_Fmpz_Set_Ui64(m1.FmpzPtr, ui64)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As Boolean
      Return (fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As fmpz_t) As fmpz_t
    Dim m3 As New fmpz_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Neg(m3.FmpzPtr, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  '***********************************************************************
  
  
  Public Shared Operator +(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Add(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As fmpz_t, ByVal ui As UInt32) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  
  Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  
  

  Public Shared Operator +(ByVal m1 As fmpz_t, ByVal si As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Si(m3.FmpzPtr, m1.FmpzPtr, si)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal si As Int32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  
  
  
  Public Shared Operator +(ByVal m1 As fmpz_t, ByVal si64 As Int64) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Si64(m3.FmpzPtr, m1.FmpzPtr, si64)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal si64 As Int64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Si64(m3.FmpzPtr, m1.FmpzPtr, si64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator +(ByVal m1 As fmpz_t, ByVal ui64 As UInt64) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Ui64(m3.FmpzPtr, m1.FmpzPtr, ui64)
      Return m3
  End Operator
  
  Public Shared Operator +(ByVal ui64 As UInt64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Add_Ui64(m3.FmpzPtr, m1.FmpzPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Sub(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Ui_Sub(m3.FmpzPtr, ui, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpz_t, ByVal ui As UInt32) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Return m3
  End Operator



  Public Shared Operator -(ByVal si As Int32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Si_Sub(m3.FmpzPtr, si, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpz_t, ByVal si As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Sub_Si(m3.FmpzPtr, m1.FmpzPtr, si)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal ui64 As UInt64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Ui64_Sub(m3.FmpzPtr, ui64, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpz_t, ByVal ui64 As UInt64) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Sub_Ui64(m3.FmpzPtr, m1.FmpzPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal si64 As Int64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Si64_Sub(m3.FmpzPtr, si64, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As fmpz_t, ByVal si64 As Int64) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Sub_Si64(m3.FmpzPtr, m1.FmpzPtr, si64)
      Return m3
  End Operator
  
  
  
  
  
  
  
  
  
  Public Shared Operator *(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpz_t, ByVal ui As UInt32) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpz_t, ByVal si As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal ui64 As UInt64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Ui64(m3.FmpzPtr, m1.FmpzPtr, CUInt(ui64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpz_t, ByVal ui64 As UInt64) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Ui64(m3.FmpzPtr, m1.FmpzPtr, CUInt(ui64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si64 As Int64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Si64(m3.FmpzPtr, m1.FmpzPtr, CInt(si64))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal m1 As fmpz_t, ByVal si64 As Int64) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Mul_Si64(m3.FmpzPtr, m1.FmpzPtr, CInt(si64))
    Return m3
  End Operator
  
  
  
  
  Public Shared Operator /(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Ui_Tdiv_Q(m3.FmpzPtr, ui, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpz_t, ByVal ui As UInt32) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Tdiv_Q_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Return m3
  End Operator



  Public Shared Operator /(ByVal si As Int32, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Si_Tdiv_Q(m3.FmpzPtr, si, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpz_t, ByVal si As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Tdiv_Q_Si(m3.FmpzPtr, m1.FmpzPtr, si)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui64 As UInt64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Ui64_Tdiv_Q(m3.FmpzPtr, ui64, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpz_t, ByVal ui64 As UInt64) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Tdiv_Q_Ui64(m3.FmpzPtr, m1.FmpzPtr, ui64)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal si64 As Int64, ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Si64_Tdiv_Q(m3.FmpzPtr, si64, m1.FmpzPtr)
      Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal m1 As fmpz_t, ByVal si64 As Int64) As fmpz_t
      Dim m3 As New fmpz_t()
          fmpz.Lib_Fmpz_Tdiv_Q_Si64(m3.FmpzPtr, m1.FmpzPtr, si64)
      Return m3
  End Operator
  
  
  
  
  '***********************************************************************
  
  
  
  Public Shared Operator &(ByVal m1 As fmpz_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As fmpz_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      Dim n As UInt32 = CUInt( m2)
      fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As fmpz_t, ByVal n As UInt32) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, n)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As fmpz_t, ByVal n As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, CUInt(n))
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      Dim n As UInt32 = CUInt( m2)
      fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, FmpzPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
'      MsgBox("pow")      
      fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, FmpzPtr, CUInt(n))
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
      fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, FmpzPtr, m2.FmpzPtr)
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As fmpz_t
      Dim m3 As New fmpz_t()
      Dim m2 As New fmpz_t(n1)
      fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, FmpzPtr, m2.FmpzPtr)
    Return m3
  End Function



  Public Shared Operator Mod(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
    Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Mod(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator



  Public Shared Operator \(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
    Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  
  
' OPERATORS ONLY FOR INTEGERS:  
  
' Left Shift
  Public Shared Operator <<(ByVal m1 As fmpz_t, ByVal e As Integer) As fmpz_t
    Dim m3 As New fmpz_t()
    fmpz.Lib_Fmpz_Mul_2exp(m3.FmpzPtr, m1.FmpzPtr, CUInt(e))
    Return m3
  End Operator
  


' Right Shift
  Public Shared Operator >>(ByVal m1 As fmpz_t, ByVal e As Integer) As fmpz_t
    Dim m3 As New fmpz_t()
    fmpz.Lib_Fmpz_Tdiv_Q_2exp(m3.FmpzPtr, m1.FmpzPtr, CUInt(e))
    Return m3
  End Operator
  

' OnesComplement
  Public Shared Operator Not(ByVal m1 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Complement(m3.FmpzPtr, m1.FmpzPtr)
    Return m3
  End Operator



' Bitwise And
  Public Shared Operator And(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_And(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator


' Bitwise Or
  Public Shared Operator Or(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Or(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator


' Exclusive OR
  Public Shared Operator Xor(ByVal m1 As fmpz_t, ByVal m2 As fmpz_t) As fmpz_t
      Dim m3 As New fmpz_t()
        fmpz.Lib_Fmpz_Xor(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator



End Class








Public Module fmpz
  
' ******************  Fmpz  Internal Functions*****************************
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Gmp_Rand_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Gmp_Rand_Init(ByRef GmpRandPtr As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Gmp_Rand_Clear(ByVal GmpRandPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Flint_Rand_Init(ByRef RandPtr As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Flint_Rand_Clear(ByVal RandPtr As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Init(ByRef FmpzPtr As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Clear(ByVal FmpzPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Print(ByVal FmpzPtr As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set(ByVal FmpzPtr As IntPtr, ByVal FmpzPtr_x As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Ui(ByVal FmpzPtr As IntPtr, ByVal ui As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Si(ByVal FmpzPtr As IntPtr, ByVal i As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Ui64(ByVal FmpzPtr As IntPtr, ByVal ui As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Si64(ByVal FmpzPtr As IntPtr, ByVal si64 As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_D(ByVal FmpzPtr As IntPtr, ByVal d As Double)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Fmpz_Set_Str(ByVal FmpzPtr As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Ui(ByVal FmpzPtr As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Si(ByVal FmpzPtr As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Ui64(ByVal FmpzPtr As IntPtr) As UInt64
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Si64(ByVal FmpzPtr As IntPtr) As Int64
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_D(ByVal FmpzPtr As IntPtr) As Double
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_SizeInBase", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_SizeInBase(ByVal FmpzPtr As IntPtr, ByVal base As Int32) As UInt32
  End Function
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Fmpz_Get_Str(ByVal sb As StringBuilder, ByVal base As Int32, ByVal FmpzPtr As IntPtr) As IntPtr
  End Function
  
  Friend  Function Get_Str(ByVal base As Int32, ByVal FmpzPtr As IntPtr) As String
    Dim StrSize As Int32 = CInt(Lib_Fmpz_SizeInBase(FmpzPtr, 10))
    Dim sb As  New StringBuilder(StrSize)    
    Dim res As IntPtr = Lib_Fmpz_Get_Str(sb, base, FmpzPtr)
    Return sb.ToString()
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  
  
  
  
  '***********************************************************************
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Ui_Sub(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Si_Sub(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
  End Sub
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Ui64_Sub(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Si64_Sub(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
  End Sub
  
  
  
  
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Ui_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Ui_Tdiv_Q(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Si_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Si_Tdiv_Q(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
  End Sub
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Ui64_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Ui64_Tdiv_Q(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Si64_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Si64_Tdiv_Q(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Si64", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
  End Sub
  
  
  
  '***********************************************************************
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mod", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mod(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Complement", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Complement(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_And", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_And(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_OR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_OR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_XOR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_XOR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  
  
  ' ******************  Fmpz  Internal and Public Functions*****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Function pow(ByVal y As fmpz_t, ByVal u As UInt32) As fmpz_t
      Dim x As New fmpz_t
      Lib_Fmpz_Pow_Ui(x.FmpzPtr, y.FmpzPtr, u)
      Return x
  End Function
  
  
  
  ' ******************  Fmpz Public Functions  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_RandM", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_RandM(ByVal res_FmpzPtr As IntPtr, ByVal state_RandPtr As IntPtr, ByVal m_FmpzPtr As IntPtr)
  End Sub
  
  
  Public  Function randm(ByVal state As randstate_t, ByVal m As fmpz_t) As fmpz_t
      Dim res As New fmpz_t
      Lib_Fmpz_RandM(res.FmpzPtr, state.RandPtr, m.FmpzPtr)
      Return res
  End Function
  
  
  
End Module




