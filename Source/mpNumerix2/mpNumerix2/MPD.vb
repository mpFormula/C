
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpd_t


  Friend MpdPtr As IntPtr = Nothing

  
    
  Private Sub Init()
      mp4.Init()
      Lib_Mpd_Init(MpdPtr)
  End Sub

  ''' <summary>
  ''' Create a new mpd_t
  ''' </summary>
  Public Sub New()
      Init()
  End Sub
  
  
  ''' <summary>
  ''' Create a new mpd_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Mpd_Set_Si(MpdPtr, si32)
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Mpd_Set_Ui(MpdPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Dim si32 As Int32 = CInt(si64)
      mpd.Lib_Mpd_Set_Si(MpdPtr, si32)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Dim ui32 As UInt32 = CUInt(ui64)
      mpd.Lib_Mpd_Set_Ui(MpdPtr, ui32)
  End Sub
  

  Public Sub New(ByVal d As Double)
      Init()
      Lib_Mpd_Set_D(MpdPtr, d)
  End Sub
  

  Public Sub New(ByVal s As String)
      Init()
      Lib_Mpd_Set_Str(MpdPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Mpd_Clear(MpdPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpd_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpd_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return mpd.Mpd_Get_Str_2(10, MpdPtr)
  End Function




  Public Function __str__() As String
    Return mpd.Mpd_Get_Str_2(10, MpdPtr)
  End Function


  Public Function __repr__() As String
    Return  "mpd_t('" & mpd.Mpd_Get_Str_2(10, MpdPtr) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpd_t) As String
      Return mpd.GetStr(10, m1)
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As mpd_t
    Dim m1 As New mpd_t
    mpd.Lib_Mpd_Set_Str(m1.MpdPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpd_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpd_t
'    Dim m1 As New mpd_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Widening Operator CType(ByVal m1 As mpd_t) As Double
    
    'MsgBox("Double")
      Return mpd.Lib_Mpd_Get_D(m1.MpdPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpd_t
    Dim m1 As New mpd_t
    mpd.Lib_Mpd_Set_D(m1.MpdPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As mpd_t) As Int32
    Return mpd.Lib_Mpd_Get_Si(m1.MpdPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpd_t
    Dim m1 As New mpd_t
      mpd.Lib_Mpd_Set_Si(m1.MpdPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpd_t) As Int64
    Return mpd.Lib_Mpd_Get_Si(m1.MpdPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As mpd_t
      Dim m1 As New mpd_t
      Dim si32 As Int32 = CInt(si)
      mpd.Lib_Mpd_Set_Si(m1.MpdPtr, si32)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpd_t) As UInt32
    Return mpd.Lib_Mpd_Get_Ui(m1.MpdPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpd_t
      Dim m1 As New mpd_t
      mpd.Lib_Mpd_Set_Ui(m1.MpdPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpd_t) As UInt64
    Return mpd.Lib_Mpd_Get_Ui(m1.MpdPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As mpd_t
      Dim m1 As New mpd_t
      Dim ui32 As UInt32 = CUInt(ui)
      mpd.Lib_Mpd_Set_Ui(m1.MpdPtr, ui32)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As Boolean
      Return (mpd.Lib_Mpd_Cmp(m1.MpdPtr, m2.MpdPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpd_t) As mpd_t
    Dim m3 As New mpd_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Neg(m3.MpdPtr, m1.MpdPtr)
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Add(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As mpd_t, ByVal si As Int32) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As mpd_t, ByVal si As Int64) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Sub(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As mpd_t, ByVal si As Int32) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpd_t, ByVal si As Int64) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          mpd.Lib_Mpd_Add_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      Else
          mpd.Lib_Mpd_Sub_Ui(m3.MpdPtr, m1.MpdPtr, ui)
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As mpd_t, ByVal si As Int32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Si(m3.MpdPtr, m1.MpdPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpd_t, ByVal si As Int64) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Si(m3.MpdPtr, m1.MpdPtr, CInt(si))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Si(m3.MpdPtr, m1.MpdPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Si(m3.MpdPtr, m1.MpdPtr, CInt(si))
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As mpd_t, ByVal ui As UInt32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Ui(m3.MpdPtr, m1.MpdPtr, ui)
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As mpd_t, ByVal ui As UInt64) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Ui(m3.MpdPtr, m1.MpdPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Ui(m3.MpdPtr, m1.MpdPtr, ui)
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Mul_Ui(m3.MpdPtr, m1.MpdPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpd_t, ByVal si As Int32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q_Si(m3.MpdPtr, m1.MpdPtr, si)
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpd_t, ByVal si As Int64) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q_Si(m3.MpdPtr, m1.MpdPtr, CInt(si))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpd_t, ByVal ui As UInt32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q_Ui(m3.MpdPtr, m1.MpdPtr, ui)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpd_t, ByVal ui As UInt64) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q_Ui(m3.MpdPtr, m1.MpdPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As mpd_t) As mpd_t
      Dim m1, m3 As New mpd_t()
      m1 = si
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As mpd_t) As mpd_t
      Dim m1, m3 As New mpd_t()
      m1 = si
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As mpd_t) As mpd_t
      Dim m1, m3 As New mpd_t()
      m1 = ui
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As mpd_t) As mpd_t
      Dim m1, m3 As New mpd_t()
      m1 = ui
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As mpd_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpd_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim n As UInt32 = m2
      mpd.Lib_Mpd_Pow_Ui(m3.MpdPtr, m1.MpdPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpd_t, ByVal n As UInt32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Pow_Ui(m3.MpdPtr, m1.MpdPtr, n)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpd_t, ByVal n As Int32) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Pow_Ui(m3.MpdPtr, m1.MpdPtr, CUInt(n))
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      Dim n As UInt32 = m2
      mpd.Lib_Mpd_Pow_Ui(m3.MpdPtr, MpdPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpd_t
      Dim m3 As New mpd_t()
'      MsgBox("pow")      
      mpd.Lib_Mpd_Pow_Ui(m3.MpdPtr, MpdPtr, CUInt(n))
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpd_t
      Dim m3 As New mpd_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, MpdPtr, m2.MpdPtr)
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As mpd_t
      Dim m3 As New mpd_t()
      Dim m2 As New mpd_t(n1)
      mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, MpdPtr, m2.MpdPtr)
    Return m3
  End Function



  Public Shared Operator Mod(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
    Dim m3 As New mpd_t()
        mpd.Lib_Mpd_Mod(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator



  Public Shared Operator \(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
    Dim m3 As New mpd_t()
        mpd.Lib_Mpd_Tdiv_Q(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator
  
  
  
  
' OPERATORS ONLY FOR INTEGERS:  
  
' Left Shift
  Public Shared Operator <<(ByVal m1 As mpd_t, ByVal e As Integer) As mpd_t
    Dim m3 As New mpd_t()
    mpd.Lib_Mpd_Mul_2exp(m3.MpdPtr, m1.MpdPtr, CUInt(e))
    Return m3
  End Operator
  


' Right Shift
  Public Shared Operator >>(ByVal m1 As mpd_t, ByVal e As Integer) As mpd_t
    Dim m3 As New mpd_t()
    mpd.Lib_Mpd_Tdiv_Q_2exp(m3.MpdPtr, m1.MpdPtr, CUInt(e))
    Return m3
  End Operator
  

' OnesComplement
  Public Shared Operator Not(ByVal m1 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
        mpd.Lib_Mpd_Complement(m3.MpdPtr, m1.MpdPtr)
    Return m3
  End Operator



' Bitwise And
  Public Shared Operator And(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
        mpd.Lib_Mpd_And(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator


' Bitwise Or
  Public Shared Operator Or(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
        mpd.Lib_Mpd_Or(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator


' Exclusive OR
  Public Shared Operator Xor(ByVal m1 As mpd_t, ByVal m2 As mpd_t) As mpd_t
      Dim m3 As New mpd_t()
        mpd.Lib_Mpd_Xor(m3.MpdPtr, m1.MpdPtr, m2.MpdPtr)
    Return m3
  End Operator



End Class








Public Module mpd
  
' ******************  Fmpz  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Init(ByRef MpdPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Clear(ByVal MpdPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Print(ByVal MpdPtr As IntPtr)
  End Sub
  
  Public  Sub Print(ByVal x As mpd_t)
      Lib_Mpd_Print(x.MpdPtr)
  End Sub
  


  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Set_Ui(ByVal MpdPtr As IntPtr, ByVal ui As UInt32)
  End Sub

  Public  Sub SetUi(ByVal x As mpd_t, ByVal ui As UInt32)
      Lib_Mpd_Set_Ui(x.MpdPtr, ui)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Set_Si(ByVal MpdPtr As IntPtr, ByVal i As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpd_t, ByVal i As Int32)
      Lib_Mpd_Set_Si(x.MpdPtr, i)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Set_D(ByVal MpdPtr As IntPtr, ByVal d As Double)
  End Sub

  Public  Sub SetD(ByVal x As mpd_t, ByVal d As Double)
      Lib_Mpd_Set_D(x.MpdPtr, d)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Mpd_Set_Str(ByVal MpdPtr As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub

  Public Sub SetStr(ByVal x As mpd_t, ByVal str As String, ByVal b As Int32)
    Lib_Mpd_Set_Str(x.MpdPtr, str, b)
  End Sub

  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpd_Get_Ui(ByVal MpdPtr As IntPtr) As UInt32
  End Function

  Public  Function GetUi(ByVal x As mpd_t) As UInt32
      Return Lib_Mpd_Get_Ui(x.MpdPtr)
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpd_Get_Si(ByVal MpdPtr As IntPtr) As Int32
  End Function

  Public  Function GetSi(ByVal x As mpd_t) As Int32
      Return Lib_Mpd_Get_Si(x.MpdPtr)
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpd_Get_D(ByVal MpdPtr As IntPtr) As Double
  End Function

  Public  Function GetD(ByVal x As mpd_t) As Double
      Return Lib_Mpd_Get_D(x.MpdPtr)
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpd_SizeInBase10(ByVal MpdPtr As IntPtr) As UInt32
  End Function

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Mpd_Get_Str(ByVal sb As StringBuilder, ByVal MpdPtr As IntPtr) As IntPtr
  End Function
  
  
  
Friend  Function Mpd_Get_Str_2(ByVal base As Int32, ByVal MpdPtr As IntPtr) As String
    Dim StrSize As Int32 = CInt(Lib_Mpd_SizeInBase10(MpdPtr))
    Dim sb As  New StringBuilder(StrSize)    
    Dim res As IntPtr = Lib_Mpd_Get_Str(sb, MpdPtr)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetStr(ByVal base As Int32, ByVal x As mpd_t) As String
    Return Mpd_Get_Str_2(base, x.MpdPtr)
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpd_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Cmp(ByVal f As mpd_t, ByVal g As mpd_t) As Int32
      Return Lib_Mpd_Cmp(f.MpdPtr, g.MpdPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub

  Public  Sub Neg(ByVal f As mpd_t, ByVal g As mpd_t)
      Lib_Mpd_Neg(f.MpdPtr, g.MpdPtr)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Add(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_Add(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub AddUi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Add_Ui(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Sub(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Sub_(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_Sub(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Sub_Ui(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Mul(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Mul(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_Mul(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal si As Int32)
      Lib_Mpd_Mul_Si(x.MpdPtr, y.MpdPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub MulUi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Mul_Ui(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Tdiv_Q(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub TdivQ(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_Tdiv_Q(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Tdiv_Q_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Tdiv_Q_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub TdivQSi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal si As Int32)
      Lib_Mpd_Tdiv_Q_Si(x.MpdPtr, y.MpdPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Tdiv_Q_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Tdiv_Q_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQUi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Tdiv_Q_Ui(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Mul_2exp(x.MpdPtr, y.MpdPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Tdiv_Q_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Tdiv_Q_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQ2exp(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Tdiv_Q_2exp(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Mod", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Mod(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Mod_(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_Mod(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub PowUi(ByVal x As mpd_t, ByVal y As mpd_t, ByVal u As UInt32)
      Lib_Mpd_Pow_Ui(x.MpdPtr, y.MpdPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_Complement", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_Complement(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  Public  Sub Complement(ByVal x As mpd_t, ByVal y As mpd_t)
      Lib_Mpd_Complement(x.MpdPtr, y.MpdPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_And", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_And(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub And_(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_And(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_OR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_OR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub OR_(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_OR(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpd_XOR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpd_XOR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub XOR_(ByVal x As mpd_t, ByVal y As mpd_t, ByVal z As mpd_t)
      Lib_Mpd_XOR(x.MpdPtr, y.MpdPtr, z.MpdPtr)
  End Sub
  
  


End Module




