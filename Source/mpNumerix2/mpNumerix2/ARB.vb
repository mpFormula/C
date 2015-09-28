
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class arb_t

  Friend ArbPtr As IntPtr = Nothing
  
  Private Sub Init()
      mp4.Init()
      Lib_Arb_Init(ArbPtr)
  End Sub
  

  Public Sub New()
      Init()
  End Sub


  
  ''' <summary>
  ''' Create a new arb_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      Lib_Arb_Set_Si(ArbPtr, si32)
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      Lib_Arb_Set_Ui(ArbPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Dim si32 As Int32 = CInt(si64)
      Lib_Arb_Set_Si(ArbPtr, si32)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Dim ui32 As UInt32 = CUInt(ui64)
      Lib_Arb_Set_Ui(ArbPtr, ui32)
  End Sub
  

  Public Sub New(ByVal d As Double)
      Init()
      Lib_Arb_Set_D(ArbPtr, d)
  End Sub
  

  Public Sub New(ByVal s As String)
      Init()
      Lib_Arb_Set_Str(ArbPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Arb_Clear(ArbPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As arb_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As arb_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return arb.Arb_Get_Str_2(ArbPtr, getprec(), 0)
  End Function




  Public Function __str__() As String
    Return arb.Arb_Get_Str_2(ArbPtr, getprec(), 0)
  End Function


  Public Function __repr__() As String
    Return  "arb_t('" & arb.Arb_Get_Str_2(ArbPtr, getprec(), 0) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As arb_t) As String
      Return arb.GetStr(m1, getprec(), 0)
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As arb_t
    Dim m1 As New arb_t
    arb.Lib_Arb_Set_Str(m1.ArbPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As arb_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As arb_t
'    Dim m1 As New arb_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Widening Operator CType(ByVal m1 As arb_t) As Double
    
    'MsgBox("Double")
      Return arb.Lib_Arb_Get_D(m1.ArbPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As arb_t
    Dim m1 As New arb_t
    arb.Lib_Arb_Set_D(m1.ArbPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As arb_t) As Int32
    Return arb.Lib_Arb_Get_Si(m1.ArbPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As arb_t
    Dim m1 As New arb_t
      arb.Lib_Arb_Set_Si(m1.ArbPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As arb_t) As Int64
    Return arb.Lib_Arb_Get_Si(m1.ArbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As arb_t
      Dim m1 As New arb_t
      Dim si32 As Int32 = CInt(si)
      arb.Lib_Arb_Set_Si(m1.ArbPtr, si32)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As arb_t) As UInt32
    Return arb.Lib_Arb_Get_Ui(m1.ArbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As arb_t
      Dim m1 As New arb_t
      arb.Lib_Arb_Set_Ui(m1.ArbPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As arb_t) As UInt64
    Return arb.Lib_Arb_Get_Ui(m1.ArbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As arb_t
      Dim m1 As New arb_t
      Dim ui32 As UInt32 = CUInt(ui)
      arb.Lib_Arb_Set_Ui(m1.ArbPtr, ui32)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As arb_t, ByVal m2 As arb_t) As Boolean
      Return (arb.Lib_Arb_Cmp(m1.ArbPtr, m2.ArbPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As arb_t) As arb_t
    Dim m3 As New arb_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Neg(m3.ArbPtr, m1.ArbPtr)
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Add(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As arb_t, ByVal si As Int32) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As arb_t, ByVal si As Int64) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Sub(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As arb_t, ByVal si As Int32) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As arb_t, ByVal si As Int64) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          arb.Lib_Arb_Add_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      Else
          arb.Lib_Arb_Sub_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As arb_t, ByVal si As Int32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Si(m3.ArbPtr, m1.ArbPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As arb_t, ByVal si As Int64) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Si(m3.ArbPtr, m1.ArbPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Si(m3.ArbPtr, m1.ArbPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Si(m3.ArbPtr, m1.ArbPtr, CInt(si), getprec())
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As arb_t, ByVal ui As UInt32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As arb_t, ByVal ui As UInt64) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Ui(m3.ArbPtr, m1.ArbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Mul_Ui(m3.ArbPtr, m1.ArbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As arb_t, ByVal si As Int32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div_Si(m3.ArbPtr, m1.ArbPtr, si, getprec())
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As arb_t, ByVal si As Int64) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div_Si(m3.ArbPtr, m1.ArbPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As arb_t, ByVal ui As UInt32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div_Ui(m3.ArbPtr, m1.ArbPtr, ui, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As arb_t, ByVal ui As UInt64) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div_Ui(m3.ArbPtr, m1.ArbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As arb_t) As arb_t
      Dim m1, m3 As New arb_t()
      m1 = si
      arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As arb_t) As arb_t
      Dim m1, m3 As New arb_t()
      m1 = si
      arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As arb_t) As arb_t
      Dim m1, m3 As New arb_t()
      m1 = ui
      arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As arb_t) As arb_t
      Dim m1, m3 As New arb_t()
      m1 = ui
      arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As arb_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As arb_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Pow(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As arb_t, ByVal n As UInt32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Pow_Si(m3.ArbPtr, m1.ArbPtr, CInt(n), getprec())
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As arb_t, ByVal n As Int32) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Pow_Si(m3.ArbPtr, m1.ArbPtr, n, getprec())
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Pow(m3.ArbPtr, ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As arb_t
      Dim m3 As New arb_t()
'      MsgBox("pow")      
      arb.Lib_Arb_Pow_Si(m3.ArbPtr, ArbPtr, n, getprec())
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As arb_t
      Dim m3 As New arb_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As arb_t) As arb_t
      Dim m3 As New arb_t()
      arb.Lib_Arb_Div(m3.ArbPtr, ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As arb_t
      Dim m3 As New arb_t()
      Dim m2 As New arb_t(n1)
      arb.Lib_Arb_Div(m3.ArbPtr, ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Function


'
'  Public Shared Operator Mod(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
'    Dim m3 As New arb_t()
'        arb.Lib_Arb_Mod(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
'    Return m3
'  End Operator



  Public Shared Operator \(ByVal m1 As arb_t, ByVal m2 As arb_t) As arb_t
    Dim m3 As New arb_t()
        arb.Lib_Arb_Div(m3.ArbPtr, m1.ArbPtr, m2.ArbPtr, getprec())
    Return m3
  End Operator
  
  


End Class








Public Module arb

' ******************  Arb  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Init(ByRef ArbPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Clear(ByVal ArbPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Printd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Printd(ByVal ArbPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Print(ByVal x As arb_t, ByVal prec As Int32)
      Lib_Arb_Printd(x.ArbPtr, prec)
  End Sub
  


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Const_Pi(ByVal ArbPtr As IntPtr, ByVal prec As Int32)
  End Sub

  Public  Sub ConstPi(ByVal x As arb_t, ByVal prec As Int32)
      Lib_Arb_Const_Pi(x.ArbPtr, prec)
  End Sub
  
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Set_Ui(ByVal ArbPtr As IntPtr, ByVal ui As UInt32)
  End Sub

  Public  Sub SetUi(ByVal x As arb_t, ByVal ui As UInt32)
      Lib_Arb_Set_Ui(x.ArbPtr, ui)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Set_Si(ByVal ArbPtr As IntPtr, ByVal i As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As arb_t, ByVal i As Int32)
      Lib_Arb_Set_Si(x.ArbPtr, i)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Set_D(ByVal ArbPtr As IntPtr, ByVal d As Double)
  End Sub

  Public  Sub SetD(ByVal x As arb_t, ByVal d As Double)
      Lib_Arb_Set_D(x.ArbPtr, d)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Arb_Set_Str(ByVal ArbPtr As IntPtr, ByVal str As String, ByVal prec As Int32) As Int32
  End Function

  Public Function SetStr(ByVal x As arb_t, ByVal str As String, ByVal prec As Int32) As Int32
    Return Lib_Arb_Set_Str(x.ArbPtr, str, prec)
  End Function

  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Arb_Get_Ui(ByVal ArbPtr As IntPtr) As UInt32
  End Function

  Public  Function GetUi(ByVal x As arb_t) As UInt32
      Return Lib_Arb_Get_Ui(x.ArbPtr)
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Arb_Get_Si(ByVal ArbPtr As IntPtr) As Int32
  End Function

  Public  Function GetSi(ByVal x As arb_t) As Int32
      Return Lib_Arb_Get_Si(x.ArbPtr)
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Arb_Get_D(ByVal ArbPtr As IntPtr) As Double
  End Function

  Public  Function GetD(ByVal x As arb_t) As Double
      Return Lib_Arb_Get_D(x.ArbPtr)
  End Function
  
  
    
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Arb_SizeInBase10(ByVal FmpqPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As UInt32
  End Function
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Arb_Get_Str(ByVal sb As StringBuilder, ByVal ArbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As IntPtr
  End Function

  Friend  Function Arb_Get_Str_2(ByVal ArbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As String
    Dim StrSize As Int32 = CInt(Lib_Arb_SizeInBase10(ArbPtr, digits, flags))
    Dim sb As  New StringBuilder(StrSize)
    Dim res As IntPtr = Lib_Arb_Get_Str(sb, ArbPtr, digits, flags)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetStr(ByVal x As arb_t, ByVal digits As Int32, ByVal flags As UInt32) As String
    Return Arb_Get_Str_2(x.ArbPtr, digits, flags)
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Arb_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Cmp(ByVal f As arb_t, ByVal g As arb_t) As Int32
      Return Lib_Arb_Cmp(f.ArbPtr, g.ArbPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub

  Public  Sub Neg(ByVal f As arb_t, ByVal g As arb_t)
      Lib_Arb_Neg(f.ArbPtr, g.ArbPtr)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Add(ByVal x As arb_t, ByVal y As arb_t, ByVal z As arb_t, ByVal prec As Int32)
      Lib_Arb_Add(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub AddUi(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Arb_Add_Ui(x.ArbPtr, y.ArbPtr, u, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Sub(ByVal ArbPtrX As IntPtr, ByVal ArbPtrY As IntPtr, ByVal ArbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Sub_(ByVal x As arb_t, ByVal y As arb_t, ByVal z As arb_t, ByVal prec As Int32)
      Lib_Arb_Sub(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Arb_Sub_Ui(x.ArbPtr, y.ArbPtr, u, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mul(ByVal ArbPtrX As IntPtr, ByVal ArbPtrY As IntPtr, ByVal ArbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Mul(ByVal x As arb_t, ByVal y As arb_t, ByVal z As arb_t, ByVal prec As Int32)
      Lib_Arb_Mul(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As arb_t, ByVal y As arb_t, ByVal si As Int32, ByVal prec As Int32)
      Lib_Arb_Mul_Si(x.ArbPtr, y.ArbPtr, si, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub MulUi(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Arb_Mul_Ui(x.ArbPtr, y.ArbPtr, u, prec)
  End Sub
'  
  
  
  
  
  
    

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Div(ByVal ArbPtrX As IntPtr, ByVal ArbPtrY As IntPtr, ByVal ArbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Div(ByVal x As arb_t, ByVal y As arb_t, ByVal z As arb_t, ByVal prec As Int32)
      Lib_Arb_Div(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Div_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub DivSi(ByVal x As arb_t, ByVal y As arb_t, ByVal si As Int32, ByVal prec As Int32)
      Lib_Arb_Div_Si(x.ArbPtr, y.ArbPtr, si, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Div_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub DivUi(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Arb_Div_Ui(x.ArbPtr, y.ArbPtr, u, prec)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32)
      Lib_Arb_Mul_2exp(x.ArbPtr, y.ArbPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Lib_Arb_Div_2exp(ByVal x As arb_t, ByVal y As arb_t, ByVal u As UInt32)
      Lib_Arb_Div_2exp(x.ArbPtr, y.ArbPtr, u)
  End Sub
  
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Pow(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Pow(ByVal x As arb_t, ByVal y As arb_t, ByVal z As arb_t, ByVal prec As Int32)
      Lib_Arb_Pow(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub PowSi(ByVal x As arb_t, ByVal y As arb_t, ByVal u As Int32, ByVal prec As Int32)
      Lib_Arb_Pow_Si(x.ArbPtr, y.ArbPtr, u, prec)
  End Sub
  
  



End Module


