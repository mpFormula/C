
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpdc_t


  Friend MpdcPtr As IntPtr = Nothing
  
    
  Private Sub Init()
      mp4.Init()
      Lib_Mpdc_Init(MpdcPtr)
  End Sub


  ''' <summary>
  ''' Create a new mpdc_t
  ''' </summary>
  Public Sub New()
      Init()
  End Sub
  
  
  ''' <summary>
  ''' Create a new mpdc_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Mpdc_Set_Si(MpdcPtr, si32)
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Mpdc_Set_Ui(MpdcPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Dim si32 As Int32 = CInt(si64)
      mpdc.Lib_Mpdc_Set_Si(MpdcPtr, si32)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Dim ui32 As UInt32 = CUInt(ui64)
      mpdc.Lib_Mpdc_Set_Ui(MpdcPtr, ui32)
  End Sub
  

  Public Sub New(ByVal d As Double)
      Init()
      mpdc.Lib_Mpdc_Set_D(MpdcPtr, d)
  End Sub
  

  Public Sub New(ByVal s As String)
      Init()
      mpdc.Lib_Mpdc_Set_Str(MpdcPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Mpdc_Clear(MpdcPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpdc_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpdc_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return mpdc.Mpd_Get_Str_2(10, MpdcPtr)
  End Function




  Public Function __str__() As String
    Return mpdc.Mpd_Get_Str_2(10, MpdcPtr)
  End Function


  Public Function __repr__() As String
    Return  "mpdc_t('" & mpdc.Mpd_Get_Str_2(10, MpdcPtr) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpdc_t) As String
      Return mpdc.GetStr(10, m1)
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As mpdc_t
    Dim m1 As New mpdc_t
    mpdc.Lib_Mpdc_Set_Str(m1.MpdcPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpdc_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpdc_t
'    Dim m1 As New mpdc_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Widening Operator CType(ByVal m1 As mpdc_t) As Double
    
    'MsgBox("Double")
      Return mpdc.Lib_Mpdc_Get_D(m1.MpdcPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpdc_t
    Dim m1 As New mpdc_t
    mpdc.Lib_Mpdc_Set_D(m1.MpdcPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As mpdc_t) As Int32
    Return mpdc.Lib_Mpdc_Get_Si(m1.MpdcPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpdc_t
    Dim m1 As New mpdc_t
      mpdc.Lib_Mpdc_Set_Si(m1.MpdcPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpdc_t) As Int64
    Return mpdc.Lib_Mpdc_Get_Si(m1.MpdcPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As mpdc_t
      Dim m1 As New mpdc_t
      Dim si32 As Int32 = CInt(si)
      mpdc.Lib_Mpdc_Set_Si(m1.MpdcPtr, si32)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpdc_t) As UInt32
    Return mpdc.Lib_Mpdc_Get_Ui(m1.MpdcPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpdc_t
      Dim m1 As New mpdc_t
      mpdc.Lib_Mpdc_Set_Ui(m1.MpdcPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpdc_t) As UInt64
    Return mpdc.Lib_Mpdc_Get_Ui(m1.MpdcPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As mpdc_t
      Dim m1 As New mpdc_t
      Dim ui32 As UInt32 = CUInt(ui)
      mpdc.Lib_Mpdc_Set_Ui(m1.MpdcPtr, ui32)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As Boolean
      Return (mpdc.Lib_Mpdc_Cmp(m1.MpdcPtr, m2.MpdcPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpdc_t) As mpdc_t
    Dim m3 As New mpdc_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Neg(m3.MpdcPtr, m1.MpdcPtr)
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Add(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As mpdc_t, ByVal si As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As mpdc_t, ByVal si As Int64) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Sub(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As mpdc_t, ByVal si As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpdc_t, ByVal si As Int64) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpdc.Lib_Mpdc_Add_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      Else
          mpdc.Lib_Mpdc_Sub_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As mpdc_t, ByVal si As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Si(m3.MpdcPtr, m1.MpdcPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpdc_t, ByVal si As Int64) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Si(m3.MpdcPtr, m1.MpdcPtr, CInt(si))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Si(m3.MpdcPtr, m1.MpdcPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Si(m3.MpdcPtr, m1.MpdcPtr, CInt(si))
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As mpdc_t, ByVal ui As UInt32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As mpdc_t, ByVal ui As UInt64) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Ui(m3.MpdcPtr, m1.MpdcPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Mul_Ui(m3.MpdcPtr, m1.MpdcPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpdc_t, ByVal si As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q_Si(m3.MpdcPtr, m1.MpdcPtr, si)
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpdc_t, ByVal si As Int64) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q_Si(m3.MpdcPtr, m1.MpdcPtr, CInt(si))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpdc_t, ByVal ui As UInt32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q_Ui(m3.MpdcPtr, m1.MpdcPtr, ui)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpdc_t, ByVal ui As UInt64) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q_Ui(m3.MpdcPtr, m1.MpdcPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As mpdc_t) As mpdc_t
      Dim m1, m3 As New mpdc_t()
      m1 = si
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As mpdc_t) As mpdc_t
      Dim m1, m3 As New mpdc_t()
      m1 = si
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As mpdc_t) As mpdc_t
      Dim m1, m3 As New mpdc_t()
      m1 = ui
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As mpdc_t) As mpdc_t
      Dim m1, m3 As New mpdc_t()
      m1 = ui
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As mpdc_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpdc_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim n As UInt32 = m2
      mpdc.Lib_Mpdc_Pow_Ui(m3.MpdcPtr, m1.MpdcPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpdc_t, ByVal n As UInt32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Pow_Ui(m3.MpdcPtr, m1.MpdcPtr, n)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpdc_t, ByVal n As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Pow_Ui(m3.MpdcPtr, m1.MpdcPtr, CUInt(n))
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim n As UInt32 = m2
      mpdc.Lib_Mpdc_Pow_Ui(m3.MpdcPtr, MpdcPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
'      MsgBox("pow")      
      mpdc.Lib_Mpdc_Pow_Ui(m3.MpdcPtr, MpdcPtr, CUInt(n))
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, MpdcPtr, m2.MpdcPtr)
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpdc_t
      Dim m3 As New mpdc_t()
      Dim m2 As New mpdc_t(n1)
      mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, MpdcPtr, m2.MpdcPtr)
    Return m3
  End Function



  Public Shared Operator Mod(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
    Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_Mod(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator



  Public Shared Operator \(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
    Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_Tdiv_Q(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator
  
  
  
  
' OPERATORS ONLY FOR INTEGERS:  
  
' Left Shift
  Public Shared Operator <<(ByVal m1 As mpdc_t, ByVal e As Integer) As mpdc_t
    Dim m3 As New mpdc_t()
    mpdc.Lib_Mpdc_Mul_2exp(m3.MpdcPtr, m1.MpdcPtr, CUInt(e))
    Return m3
  End Operator
  


' Right Shift
  Public Shared Operator >>(ByVal m1 As mpdc_t, ByVal e As Integer) As mpdc_t
    Dim m3 As New mpdc_t()
    mpdc.Lib_Mpdc_Tdiv_Q_2exp(m3.MpdcPtr, m1.MpdcPtr, CUInt(e))
    Return m3
  End Operator
  

' OnesComplement
  Public Shared Operator Not(ByVal m1 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_Complement(m3.MpdcPtr, m1.MpdcPtr)
    Return m3
  End Operator



' Bitwise And
  Public Shared Operator And(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_And(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator


' Bitwise Or
  Public Shared Operator Or(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_Or(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator


' Exclusive OR
  Public Shared Operator Xor(ByVal m1 As mpdc_t, ByVal m2 As mpdc_t) As mpdc_t
      Dim m3 As New mpdc_t()
        mpdc.Lib_Mpdc_Xor(m3.MpdcPtr, m1.MpdcPtr, m2.MpdcPtr)
    Return m3
  End Operator



End Class








Public Module mpdc
  
' ******************  Fmpz  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Init(ByRef MpdcPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Clear(ByVal MpdcPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Print(ByVal MpdcPtr As IntPtr)
  End Sub
  
  Public  Sub Print(ByVal x As mpdc_t)
      Lib_Mpdc_Print(x.MpdcPtr)
  End Sub
  


  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Set_Ui(ByVal MpdcPtr As IntPtr, ByVal ui As UInt32)
  End Sub

  Public  Sub SetUi(ByVal x As mpdc_t, ByVal ui As UInt32)
      Lib_Mpdc_Set_Ui(x.MpdcPtr, ui)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Set_Si(ByVal MpdcPtr As IntPtr, ByVal i As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpdc_t, ByVal i As Int32)
      Lib_Mpdc_Set_Si(x.MpdcPtr, i)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Set_D(ByVal MpdcPtr As IntPtr, ByVal d As Double)
  End Sub

  Public  Sub SetD(ByVal x As mpdc_t, ByVal d As Double)
      Lib_Mpdc_Set_D(x.MpdcPtr, d)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Mpdc_Set_Str(ByVal MpdcPtr As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub

  Public Sub SetStr(ByVal x As mpdc_t, ByVal str As String, ByVal b As Int32)
    Lib_Mpdc_Set_Str(x.MpdcPtr, str, b)
  End Sub

  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpdc_Get_Ui(ByVal MpdcPtr As IntPtr) As UInt32
  End Function

  Public  Function GetUi(ByVal x As mpdc_t) As UInt32
      Return Lib_Mpdc_Get_Ui(x.MpdcPtr)
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpdc_Get_Si(ByVal MpdcPtr As IntPtr) As Int32
  End Function

  Public  Function GetSi(ByVal x As mpdc_t) As Int32
      Return Lib_Mpdc_Get_Si(x.MpdcPtr)
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpdc_Get_D(ByVal MpdcPtr As IntPtr) As Double
  End Function

  Public  Function GetD(ByVal x As mpdc_t) As Double
      Return Lib_Mpdc_Get_D(x.MpdcPtr)
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpdc_SizeInBase10(ByVal MpdcPtr As IntPtr) As UInt32
  End Function

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpdc_Get_Str(ByVal sb As StringBuilder, ByVal MpdcPtr As IntPtr) As IntPtr
  End Function
  
  
  
Friend  Function Mpd_Get_Str_2(ByVal base As Int32, ByVal MpdcPtr As IntPtr) As String
    Dim StrSize As Int32 = CInt(Lib_Mpdc_SizeInBase10(MpdcPtr))
    Dim sb As  New StringBuilder(StrSize)    
    Dim res As IntPtr = Lib_Mpdc_Get_Str(sb, MpdcPtr)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetStr(ByVal base As Int32, ByVal x As mpdc_t) As String
    Return Mpd_Get_Str_2(base, x.MpdcPtr)
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpdc_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Cmp(ByVal f As mpdc_t, ByVal g As mpdc_t) As Int32
      Return Lib_Mpdc_Cmp(f.MpdcPtr, g.MpdcPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub

  Public  Sub Neg(ByVal f As mpdc_t, ByVal g As mpdc_t)
      Lib_Mpdc_Neg(f.MpdcPtr, g.MpdcPtr)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Add(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_Add(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub AddUi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Add_Ui(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Sub(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Sub_(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_Sub(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Sub_Ui(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Mul(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Mul(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_Mul(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal si As Int32)
      Lib_Mpdc_Mul_Si(x.MpdcPtr, y.MpdcPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub MulUi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Mul_Ui(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Tdiv_Q(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub TdivQ(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_Tdiv_Q(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Tdiv_Q_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Tdiv_Q_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub TdivQSi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal si As Int32)
      Lib_Mpdc_Tdiv_Q_Si(x.MpdcPtr, y.MpdcPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Tdiv_Q_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Tdiv_Q_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQUi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Tdiv_Q_Ui(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Mul_2exp(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Tdiv_Q_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Tdiv_Q_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQ2exp(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Tdiv_Q_2exp(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Mod", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Mod(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Mod_(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_Mod(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub PowUi(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal u As UInt32)
      Lib_Mpdc_Pow_Ui(x.MpdcPtr, y.MpdcPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_Complement", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_Complement(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  Public  Sub Complement(ByVal x As mpdc_t, ByVal y As mpdc_t)
      Lib_Mpdc_Complement(x.MpdcPtr, y.MpdcPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_And", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_And(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub And_(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_And(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_OR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_OR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub OR_(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_OR(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpdc_XOR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpdc_XOR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub XOR_(ByVal x As mpdc_t, ByVal y As mpdc_t, ByVal z As mpdc_t)
      Lib_Mpdc_XOR(x.MpdcPtr, y.MpdcPtr, z.MpdcPtr)
  End Sub
  
  


End Module




