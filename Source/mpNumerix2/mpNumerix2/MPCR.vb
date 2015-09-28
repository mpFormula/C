
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpfcr_t

  Friend MpfcrPtr As IntPtr = Nothing


  Public Sub New()
    If mp4.HasLibraryNumC() <> 0 Then
      mpfcr.Init(MpfcrPtr)
    End If
  End Sub


  
  ''' <summary>
  ''' Create a new mpfcr_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
        mpfcr.Lib_Mpfcr_Set_Si(MpfcrPtr, si32, mpfr.GetDefaultRoundingMode())
    End If
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
        mpfcr.Lib_Mpfcr_Set_Ui(MpfcrPtr, ui32, mpfr.GetDefaultRoundingMode())
    End If
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
      Dim si32 As Int32 = CInt(si64)
      mpfcr.Lib_Mpfcr_Set_Si(MpfcrPtr, si32, mpfr.GetDefaultRoundingMode())
    End If
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
      Dim ui32 As UInt32 = CUInt(ui64)
      mpfcr.Lib_Mpfcr_Set_Ui(MpfcrPtr, ui32, mpfr.GetDefaultRoundingMode())
    End If
  End Sub
  

  Public Sub New(ByVal d As Double)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
        mpfcr.Lib_Mpfcr_Set_D(MpfcrPtr, d, mpfr.GetDefaultRoundingMode())
    End If
  End Sub
  

  Public Sub New(ByVal s As String)
    If mp4.HasLibraryNumC() <> 0 Then
        mpfcr.Init(MpfcrPtr)
        mpfcr.Lib_Mpfcr_Set_Str(MpfcrPtr, s, 10, mpfr.GetDefaultRoundingMode())
    End If
  End Sub
  
  
  Protected Overrides Sub Finalize()
    mpfcr.Clear(MpfcrPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpfcr_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpfcr_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return mpfcr.Mpfcr_Get_Str_2( MpfcrPtr, getDPS(), mpfr.GetDefaultRoundingMode())
  End Function




  Public Function __str__() As String
    Return mpfcr.Mpfcr_Get_Str_2(MpfcrPtr,  getDPS(), mpfr.GetDefaultRoundingMode())
  End Function


  Public Function __repr__() As String
    Return  "mpfcr_t('" & mpfcr.Mpfcr_Get_Str_2(MpfcrPtr, getDPS(), mpfr.GetDefaultRoundingMode()) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpfcr_t) As String
      Return mpfcr.GetStr(m1,  getDPS(), mpfr.GetDefaultRoundingMode())
  End Operator


  Public Shared Narrowing Operator CType(ByVal s As String) As mpfcr_t
    Dim m1 As New mpfcr_t
    mpfcr.Lib_Mpfcr_Set_Str(m1.MpfcrPtr, s, 10, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpfcr_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpfcr_t
'    Dim m1 As New mpfcr_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


'Public Shared Widening Operator CType(ByVal m1 As mpfcr_t) As Double
'    
'    'MsgBox("Double")
'      Return mpfcr.Lib_Mpfcr_Get_D(m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
'  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpfcr_t
    Dim m1 As New mpfcr_t
    mpfcr.Lib_Mpfcr_Set_D(m1.MpfcrPtr, d, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator


'  Public Shared Narrowing Operator CType(ByVal m1 As mpfcr_t) As Int32
'    Return mpfcr.Lib_Mpfcr_Get_Si(m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
'  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpfcr_t
    Dim m1 As New mpfcr_t
      mpfcr.Lib_Mpfcr_Set_Si(m1.MpfcrPtr, si, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
'  Public Shared Widening Operator CType(ByVal m1 As mpfcr_t) As Int64
'    Return mpfcr.Lib_Mpfcr_Get_Si(m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
'  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As mpfcr_t
      Dim m1 As New mpfcr_t
      Dim si32 As Int32 = CInt(si)
      mpfcr.Lib_Mpfcr_Set_Si(m1.MpfcrPtr, si32, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator


'  Public Shared Widening Operator CType(ByVal m1 As mpfcr_t) As UInt32
'    Return mpfcr.Lib_Mpfcr_Get_Ui(m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
'  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpfcr_t
      Dim m1 As New mpfcr_t
      mpfcr.Lib_Mpfcr_Set_Ui(m1.MpfcrPtr, ui, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
'  Public Shared Widening Operator CType(ByVal m1 As mpfcr_t) As UInt64
'    Return mpfcr.Lib_Mpfcr_Get_Ui(m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
'  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As mpfcr_t
      Dim m1 As New mpfcr_t
      Dim ui32 As UInt32 = CUInt(ui)
      mpfcr.Lib_Mpfcr_Set_Ui(m1.MpfcrPtr, ui32, mpfr.GetDefaultRoundingMode())
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As Boolean
      Return (mpfcr.Lib_Mpfcr_Cmp(m1.MpfcrPtr, m2.MpfcrPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpfcr_t) As mpfcr_t
    Dim m3 As New mpfcr_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Neg(m3.MpfcrPtr, m1.MpfcrPtr, mpfr.GetDefaultRoundingMode())
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Add(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As mpfcr_t, ByVal si As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As mpfcr_t, ByVal si As Int64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Sub(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As mpfcr_t, ByVal si As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpfcr_t, ByVal si As Int64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpfcr.Lib_Mpfcr_Add_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      Else
          mpfcr.Lib_Mpfcr_Sub_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As mpfcr_t, ByVal si As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Si(m3.MpfcrPtr, m1.MpfcrPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpfcr_t, ByVal si As Int64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Si(m3.MpfcrPtr, m1.MpfcrPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Si(m3.MpfcrPtr, m1.MpfcrPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Si(m3.MpfcrPtr, m1.MpfcrPtr, CInt(si), getprec())
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As mpfcr_t, ByVal ui As UInt32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As mpfcr_t, ByVal ui As UInt64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Ui(m3.MpfcrPtr, m1.MpfcrPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Mul_Ui(m3.MpfcrPtr, m1.MpfcrPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpfcr_t, ByVal si As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div_Si(m3.MpfcrPtr, m1.MpfcrPtr, si, getprec())
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpfcr_t, ByVal si As Int64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div_Si(m3.MpfcrPtr, m1.MpfcrPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfcr_t, ByVal ui As UInt32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div_Ui(m3.MpfcrPtr, m1.MpfcrPtr, ui, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpfcr_t, ByVal ui As UInt64) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div_Ui(m3.MpfcrPtr, m1.MpfcrPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m1, m3 As New mpfcr_t()
      m1 = si
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m1, m3 As New mpfcr_t()
      m1 = si
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m1, m3 As New mpfcr_t()
      m1 = ui
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m1, m3 As New mpfcr_t()
      m1 = ui
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As mpfcr_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpfcr_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Pow(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpfcr_t, ByVal n As UInt32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Pow_Si(m3.MpfcrPtr, m1.MpfcrPtr, CInt(n), getprec())
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpfcr_t, ByVal n As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Pow_Si(m3.MpfcrPtr, m1.MpfcrPtr, n, getprec())
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Pow(m3.MpfcrPtr, MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
'      MsgBox("pow")      
      mpfcr.Lib_Mpfcr_Pow_Si(m3.MpfcrPtr, MpfcrPtr, n, getprec())
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpfcr_t) As mpfcr_t
      Dim m3 As New mpfcr_t()
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpfcr_t
      Dim m3 As New mpfcr_t()
      Dim m2 As New mpfcr_t(n1)
      mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Function


'
'  Public Shared Operator Mod(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
'    Dim m3 As New mpfcr_t()
'        mpfcr.Lib_Mpfcr_Mod(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
'    Return m3
'  End Operator



  Public Shared Operator \(ByVal m1 As mpfcr_t, ByVal m2 As mpfcr_t) As mpfcr_t
    Dim m3 As New mpfcr_t()
        mpfcr.Lib_Mpfcr_Div(m3.MpfcrPtr, m1.MpfcrPtr, m2.MpfcrPtr, getprec())
    Return m3
  End Operator
  
  


End Class





Public Module mpfcr

' ******************  Mpfcr  *****************************




  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Init(ByRef MpfcrPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Clear(ByVal MpfcrPtr As IntPtr)
  End Sub


'
'  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Printd", CallingConvention:=CallingConvention.Cdecl)> _
'  Friend  Sub Lib_Mpfcr_Printd(ByVal MpfcrPtr As IntPtr, ByVal prec As Int32)
'  End Sub
'  
'  Public  Sub Print(ByVal x As mpfcr_t, ByVal prec As Int32)
'      Lib_Mpfcr_Printd(x.MpfcrPtr, prec)
'  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Set_Ui(ByVal MpfcrPtr As IntPtr, ByVal ui As UInt32, ByVal rnd As Int32)
  End Sub

  Public  Sub SetUi(ByVal x As mpfcr_t, ByVal ui As UInt32, ByVal rnd As Int32)
      Lib_Mpfcr_Set_Ui(x.MpfcrPtr, ui, rnd)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Set_Si(ByVal MpfcrPtr As IntPtr, ByVal i As Int32, ByVal rnd As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpfcr_t, ByVal i As Int32, ByVal rnd As Int32)
      Lib_Mpfcr_Set_Si(x.MpfcrPtr, i, rnd)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Set_D(ByVal MpfcrPtr As IntPtr, ByVal d As Double, ByVal rnd As Int32)
  End Sub

  Public  Sub SetD(ByVal x As mpfcr_t, ByVal d As Double, ByVal rnd As Int32)
      Lib_Mpfcr_Set_D(x.MpfcrPtr, d, rnd)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfcr_Set_Str(ByVal MpfcrPtr As IntPtr, ByVal str As String, ByVal base As Int32, ByVal rnd As Int32) As Int32
  End Function

  Public Function SetStr(ByVal x As mpfcr_t, ByVal str As String, ByVal base As Int32, ByVal rnd As Int32) As Int32
    Return Lib_Mpfcr_Set_Str(x.MpfcrPtr, str, base, rnd)
  End Function

  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Real_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfcr_Real_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfcrPtr As IntPtr) As Int32
  End Function
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Real_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfcr_Real_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfcrPtr As IntPtr) As Int32
  End Function
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Imag_SnPrintf_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfcr_Imag_SnPrintf_SizeInBase10(ByVal Templ As String,  ByVal MpfcrPtr As IntPtr) As Int32
  End Function
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Imag_SnPrintf", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpfcr_Imag_SnPrintf(ByVal sb As StringBuilder, ByVal digits As UInt32, ByVal Templ As String,  ByVal MpfcrPtr As IntPtr) As Int32
  End Function
  
  
  
  
  
  Friend  Function Mpfcr_Get_Real_Str_2(ByVal MpfcrPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfcr_Real_SnPrintf_SizeInBase10("%.RE", MpfcrPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfcr_Real_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfcrPtr)
    Return sb.ToString()
  End Function
  
  

  Public  Function GetRealStr(ByVal x As mpfcr_t, ByVal digits As UInt32,  ByVal rnd As Int32) As String
      Return Mpfcr_Get_Real_Str_2(x.MpfcrPtr, digits, rnd)
  End Function


  
  
  Friend  Function Mpfcr_Get_Imag_Str_2(ByVal MpfcrPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Dim StrSize As Int32 = CInt(Lib_Mpfcr_Imag_SnPrintf_SizeInBase10("%.RE", MpfcrPtr)) + 2
    Dim sb As  New StringBuilder(StrSize)
    Dim res As Int32 = Lib_Mpfcr_Imag_SnPrintf(sb, CUInt(StrSize), "%.RE", MpfcrPtr)
    Return sb.ToString()
  End Function
  
  

  Public  Function GetImagStr(ByVal x As mpfcr_t, ByVal digits As UInt32,  ByVal rnd As Int32) As String
      Return Mpfcr_Get_Imag_Str_2(x.MpfcrPtr, digits, rnd)
  End Function



  Friend  Function Mpfcr_Get_Str_2(ByVal MpfcrPtr As IntPtr, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Return Mpfcr_Get_Real_Str_2(MpfcrPtr, digits, rnd) & " + " & Mpfcr_Get_Imag_Str_2(MpfcrPtr, digits, rnd) & "j"
  End Function
  
  
  
  Public  Function GetStr(ByVal x As mpfcr_t, ByVal digits As UInt32, ByVal rnd As Int32) As String
    Return GetRealStr(x, digits, rnd) & " + " & GetImagStr(x, digits, rnd) & "j"
  End Function
  




  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfcr_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Cmp(ByVal f As mpfcr_t, ByVal g As mpfcr_t) As Int32
      Return Lib_Mpfcr_Cmp(f.MpfcrPtr, g.MpfcrPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Neg(ByVal f As IntPtr, ByVal g As IntPtr, ByVal rnd As Int32)
  End Sub

  Public  Sub Neg(ByVal f As mpfcr_t, ByVal g As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Neg(f.MpfcrPtr, g.MpfcrPtr, rnd)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Add(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal z As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Add(x.MpfcrPtr, y.MpfcrPtr, z.MpfcrPtr, rnd)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub AddUi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32, ByVal rnd As Int32)
      Lib_Mpfcr_Add_Ui(x.MpfcrPtr, y.MpfcrPtr, u, rnd)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Sub(ByVal MpfcrPtrX As IntPtr, ByVal MpfcrPtrY As IntPtr, ByVal MpfcrPtrZ As IntPtr, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Sub_(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal z As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Sub(x.MpfcrPtr, y.MpfcrPtr, z.MpfcrPtr, rnd)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32, ByVal rnd As Int32)
      Lib_Mpfcr_Sub_Ui(x.MpfcrPtr, y.MpfcrPtr, u, rnd)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Mul(ByVal MpfcrPtrX As IntPtr, ByVal MpfcrPtrY As IntPtr, ByVal MpfcrPtrZ As IntPtr, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Mul(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal z As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Mul(x.MpfcrPtr, y.MpfcrPtr, z.MpfcrPtr, rnd)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal si As Int32, ByVal rnd As Int32)
      Lib_Mpfcr_Mul_Si(x.MpfcrPtr, y.MpfcrPtr, si, rnd)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub MulUi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32, ByVal rnd As Int32)
      Lib_Mpfcr_Mul_Ui(x.MpfcrPtr, y.MpfcrPtr, u, rnd)
  End Sub
'  
  
  
  
  
  
    

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Div(ByVal MpfcrPtrX As IntPtr, ByVal MpfcrPtrY As IntPtr, ByVal MpfcrPtrZ As IntPtr, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Div(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal z As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Div(x.MpfcrPtr, y.MpfcrPtr, z.MpfcrPtr, rnd)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Div_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub DivSi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal si As Int32, ByVal rnd As Int32)
      Lib_Mpfcr_Div_Si(x.MpfcrPtr, y.MpfcrPtr, si, rnd)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Div_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub DivUi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32, ByVal rnd As Int32)
      Lib_Mpfcr_Div_Ui(x.MpfcrPtr, y.MpfcrPtr, u, rnd)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32)
      Lib_Mpfcr_Mul_2exp(x.MpfcrPtr, y.MpfcrPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Lib_Mpfcr_Div_2exp(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As UInt32)
      Lib_Mpfcr_Div_2exp(x.MpfcrPtr, y.MpfcrPtr, u)
  End Sub
  
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Pow(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal rnd As Int32)
  End Sub
  
  Public  Sub Pow(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal z As mpfcr_t, ByVal rnd As Int32)
      Lib_Mpfcr_Pow(x.MpfcrPtr, y.MpfcrPtr, z.MpfcrPtr, rnd)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfcr_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfcr_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32, ByVal rnd As Int32)
  End Sub
  
  Public  Sub PowSi(ByVal x As mpfcr_t, ByVal y As mpfcr_t, ByVal u As Int32, ByVal rnd As Int32)
      Lib_Mpfcr_Pow_Si(x.MpfcrPtr, y.MpfcrPtr, u, rnd)
  End Sub
  
  



  
  
End Module


