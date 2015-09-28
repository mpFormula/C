
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class acb_t



  Friend AcbPtr As IntPtr = Nothing
  
  
  Private Sub Init()
      mp4.Init()
      Lib_Acb_Init(AcbPtr)
  End Sub


  Public Sub New()
      Init()
  End Sub


  
  ''' <summary>
  ''' Create a new acb_t
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
      Init()
      acb.Lib_Acb_Set_Si(AcbPtr, si32)
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
      Init()
      acb.Lib_Acb_Set_Ui(AcbPtr, ui32)
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
      Init()
      Dim si32 As Int32 = CInt(si64)
      acb.Lib_Acb_Set_Si(AcbPtr, si32)
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
      Init()
      Dim ui32 As UInt32 = CUInt(ui64)
      acb.Lib_Acb_Set_Ui(AcbPtr, ui32)
  End Sub
  

  Public Sub New(ByVal d As Double)
      Init()
      acb.Lib_Acb_Set_D(AcbPtr, d)
  End Sub
  

  Public Sub New(ByVal s As String)
      Init()
      acb.Lib_Acb_Set_Str(AcbPtr, s, 10)
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Lib_Acb_Clear(AcbPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As acb_t) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As acb_t) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return acb.Acb_Get_Str_2(AcbPtr, getprec(), 0)
  End Function




  Public Function __str__() As String
    Return acb.Acb_Get_Str_2(AcbPtr, getprec(), 0)
  End Function


  Public Function __repr__() As String
    Return  "acb_t('" & acb.Acb_Get_Str_2(AcbPtr, getprec(), 0) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As acb_t) As String
      Return acb.GetStr(m1, getprec(), 0)
  End Operator


  Public Shared Narrowing Operator CType(ByVal s As String) As acb_t
    Dim m1 As New acb_t
    acb.Lib_Acb_Set_Str(m1.AcbPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As acb_t) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As acb_t
'    Dim m1 As New acb_t
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Widening Operator CType(ByVal m1 As acb_t) As Double
    
    'MsgBox("Double")
      Return acb.Lib_Acb_Get_D(m1.AcbPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As acb_t
    Dim m1 As New acb_t
    acb.Lib_Acb_Set_D(m1.AcbPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As acb_t) As Int32
    Return acb.Lib_Acb_Get_Si(m1.AcbPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As acb_t
    Dim m1 As New acb_t
      acb.Lib_Acb_Set_Si(m1.AcbPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As acb_t) As Int64
    Return acb.Lib_Acb_Get_Si(m1.AcbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As acb_t
      Dim m1 As New acb_t
      Dim si32 As Int32 = CInt(si)
      acb.Lib_Acb_Set_Si(m1.AcbPtr, si32)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As acb_t) As UInt32
    Return acb.Lib_Acb_Get_Ui(m1.AcbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As acb_t
      Dim m1 As New acb_t
      acb.Lib_Acb_Set_Ui(m1.AcbPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As acb_t) As UInt64
    Return acb.Lib_Acb_Get_Ui(m1.AcbPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As acb_t
      Dim m1 As New acb_t
      Dim ui32 As UInt32 = CUInt(ui)
      acb.Lib_Acb_Set_Ui(m1.AcbPtr, ui32)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As acb_t, ByVal m2 As acb_t) As Boolean
      Return (acb.Lib_Acb_Eq(m1.AcbPtr, m2.AcbPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As acb_t, ByVal m2 As acb_t) As Boolean
      Return (acb.Lib_Acb_Ne(m1.AcbPtr, m2.AcbPtr) <> 0)
  End Operator



  Public Shared Operator +(ByVal m1 As acb_t) As acb_t
    Dim m3 As New acb_t()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Neg(m3.AcbPtr, m1.AcbPtr)
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Add(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As acb_t, ByVal si As Int32) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As acb_t, ByVal si As Int64) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Sub(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As acb_t, ByVal si As Int32) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As acb_t, ByVal si As Int64) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          acb.Lib_Acb_Add_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      Else
          acb.Lib_Acb_Sub_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As acb_t, ByVal si As Int32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Si(m3.AcbPtr, m1.AcbPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As acb_t, ByVal si As Int64) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Si(m3.AcbPtr, m1.AcbPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Si(m3.AcbPtr, m1.AcbPtr, si, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Si(m3.AcbPtr, m1.AcbPtr, CInt(si), getprec())
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As acb_t, ByVal ui As UInt32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As acb_t, ByVal ui As UInt64) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Ui(m3.AcbPtr, m1.AcbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Mul_Ui(m3.AcbPtr, m1.AcbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As acb_t, ByVal si As Int32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div_Si(m3.AcbPtr, m1.AcbPtr, si, getprec())
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As acb_t, ByVal si As Int64) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div_Si(m3.AcbPtr, m1.AcbPtr, CInt(si), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As acb_t, ByVal ui As UInt32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div_Ui(m3.AcbPtr, m1.AcbPtr, ui, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As acb_t, ByVal ui As UInt64) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div_Ui(m3.AcbPtr, m1.AcbPtr, CUInt(ui), getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As acb_t) As acb_t
      Dim m1, m3 As New acb_t()
      m1 = si
      acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As acb_t) As acb_t
      Dim m1, m3 As New acb_t()
      m1 = si
      acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As acb_t) As acb_t
      Dim m1, m3 As New acb_t()
      m1 = ui
      acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As acb_t) As acb_t
      Dim m1, m3 As New acb_t()
      m1 = ui
      acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As acb_t, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As acb_t) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Pow(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As acb_t, ByVal n As UInt32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Pow_Si(m3.AcbPtr, m1.AcbPtr, CInt(n), getprec())
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As acb_t, ByVal n As Int32) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Pow_Si(m3.AcbPtr, m1.AcbPtr, n, getprec())
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Pow(m3.AcbPtr, AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As acb_t
      Dim m3 As New acb_t()
'      MsgBox("pow")      
      acb.Lib_Acb_Pow_Si(m3.AcbPtr, AcbPtr, n, getprec())
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As acb_t
      Dim m3 As New acb_t()
      MsgBox("rpow")
    Return m3
  End Function
  
  
  


  Public Function __floordiv__(ByVal m2 As acb_t) As acb_t
      Dim m3 As New acb_t()
      acb.Lib_Acb_Div(m3.AcbPtr, AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Function




  Public Function __floordiv__(ByVal n1 As Int32) As acb_t
      Dim m3 As New acb_t()
      Dim m2 As New acb_t(n1)
      acb.Lib_Acb_Div(m3.AcbPtr, AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Function





  Public Shared Operator \(ByVal m1 As acb_t, ByVal m2 As acb_t) As acb_t
    Dim m3 As New acb_t()
        acb.Lib_Acb_Div(m3.AcbPtr, m1.AcbPtr, m2.AcbPtr, getprec())
    Return m3
  End Operator
  
  



End Class







Public Module acb

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Init(ByRef AcbPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Clear(ByVal AcbPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Printd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Printd(ByVal AcbPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Print(ByVal x As acb_t, ByVal prec As Int32)
      Lib_Acb_Printd(x.AcbPtr, prec)
  End Sub
  



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Const_Pi(ByVal AcbPtr As IntPtr, ByVal prec As Int32)
  End Sub

  Public  Sub ConstPi(ByVal x As acb_t, ByVal prec As Int32)
      Lib_Acb_Const_Pi(x.AcbPtr, prec)
  End Sub
  
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Set_Ui(ByVal AcbPtr As IntPtr, ByVal ui As UInt32)
  End Sub

  Public  Sub SetUi(ByVal x As acb_t, ByVal ui As UInt32)
      Lib_Acb_Set_Ui(x.AcbPtr, ui)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Set_Si(ByVal AcbPtr As IntPtr, ByVal i As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As acb_t, ByVal i As Int32)
      Lib_Acb_Set_Si(x.AcbPtr, i)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Set_D(ByVal AcbPtr As IntPtr, ByVal d As Double)
  End Sub

  Public  Sub SetD(ByVal x As acb_t, ByVal d As Double)
      Lib_Acb_Set_D(x.AcbPtr, d)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_Real_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Acb_Set_Real_Str(ByVal AcbPtr As IntPtr, ByVal str As String, ByVal prec As Int32) As Int32
  End Function

  Public Function SetRealStr(ByVal x As acb_t, ByVal str As String, ByVal prec As Int32) As Int32
    Return Lib_Acb_Set_Real_Str(x.AcbPtr, str, prec)
  End Function

  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_Imag_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Acb_Set_Imag_Str(ByVal AcbPtr As IntPtr, ByVal str As String, ByVal prec As Int32) As Int32
  End Function

  Public Function SetImagStr(ByVal x As acb_t, ByVal str As String, ByVal prec As Int32) As Int32
    Return Lib_Acb_Set_Imag_Str(x.AcbPtr, str, prec)
  End Function
  
  
  Public Function Set2Str(ByVal x As acb_t, ByVal RealStr As String, ByVal ImagStr As String, ByVal prec As Int32) As Int32
    Dim re as Int32 = Lib_Acb_Set_Real_Str(x.AcbPtr, RealStr, prec)
    Dim im As Int32 = Lib_Acb_Set_Imag_Str(x.AcbPtr, RealStr, prec)
    Return re + im
  End Function
  
  
  
  Public Function Lib_Acb_Set_Str(ByVal AcbPtr As IntPtr, ByVal Str As String, ByVal prec As Int32) As Int32
    Dim re as Int32 = Lib_Acb_Set_Real_Str(AcbPtr, Str, prec)
    Dim im As Int32 = Lib_Acb_Set_Imag_Str(AcbPtr, Str, prec)
    Return re + im
  End Function
  
  
  Public Function SetStr(ByVal x As acb_t, ByVal Str As String, ByVal prec As Int32) As Int32
    Dim re as Int32 = Lib_Acb_Set_Real_Str(x.AcbPtr, Str, prec)
    Dim im As Int32 = Lib_Acb_Set_Imag_Str(x.AcbPtr, Str, prec)
    Return re + im
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Get_Ui(ByVal AcbPtr As IntPtr) As UInt32
  End Function

  Public  Function GetUi(ByVal x As acb_t) As UInt32
      Return Lib_Acb_Get_Ui(x.AcbPtr)
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Get_Si(ByVal AcbPtr As IntPtr) As Int32
  End Function

  Public  Function GetSi(ByVal x As acb_t) As Int32
      Return Lib_Acb_Get_Si(x.AcbPtr)
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Get_D(ByVal AcbPtr As IntPtr) As Double
  End Function

  Public  Function GetD(ByVal x As acb_t) As Double
      Return Lib_Acb_Get_D(x.AcbPtr)
  End Function
  
  
  
  
  
  
  
  
  
      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Real_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Real_SizeInBase10(ByVal FmpqPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As UInt32
  End Function


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Imag_SizeInBase10", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Imag_SizeInBase10(ByVal FmpqPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As UInt32
  End Function

  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Get_Real_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Acb_Get_Real_Str(ByVal sb As StringBuilder, ByVal AcbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As IntPtr
  End Function
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Get_Imag_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Acb_Get_Imag_Str(ByVal sb As StringBuilder, ByVal AcbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As IntPtr
  End Function
  
  
  Friend  Function Acb_Get_Real_Str_2(ByVal AcbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As String
    Dim StrSize As Int32 = CInt(Lib_Acb_Real_SizeInBase10(AcbPtr, digits, flags))
    Dim sb As  New StringBuilder(StrSize)
    Dim res As IntPtr = Lib_Acb_Get_Real_Str(sb, AcbPtr, digits, flags)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetRealStr(ByVal x As acb_t, ByVal digits As Int32, ByVal flags As UInt32) As String
    Return Acb_Get_Real_Str_2(x.AcbPtr, digits, flags)
  End Function



  Friend  Function Acb_Get_Imag_Str_2(ByVal AcbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As String
    Dim StrSize As Int32 = CInt(Lib_Acb_Imag_SizeInBase10(AcbPtr, digits, flags))
    Dim sb As  New StringBuilder(StrSize)
    Dim res As IntPtr = Lib_Acb_Get_Imag_Str(sb, AcbPtr, digits, flags)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetImagStr(ByVal x As acb_t, ByVal digits As Int32, ByVal flags As UInt32) As String
    Return Acb_Get_Imag_Str_2(x.AcbPtr, digits, flags)
  End Function
  
  

  Friend  Function Acb_Get_Str_2(ByVal AcbPtr As IntPtr, ByVal digits As Int32, ByVal flags As UInt32) As String
    Return Acb_Get_Real_Str_2(AcbPtr, digits, flags) & " + " & Acb_Get_Imag_Str_2(AcbPtr, digits, flags) & "j"
  End Function
  
  
  
  Public  Function GetStr(ByVal x As acb_t, ByVal digits As Int32, ByVal flags As UInt32) As String
    Return GetRealStr(x, digits, flags) & " + " & GetImagStr(x, digits, flags) & "j"
  End Function
  


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Eq", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Eq(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Eq(ByVal f As acb_t, ByVal g As acb_t) As Int32
      Return Lib_Acb_Eq(f.AcbPtr, g.AcbPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Ne", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Acb_Ne(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Ne(ByVal f As acb_t, ByVal g As acb_t) As Int32
      Return Lib_Acb_Ne(f.AcbPtr, g.AcbPtr)
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub

  Public  Sub Neg(ByVal f As acb_t, ByVal g As acb_t)
      Lib_Acb_Neg(f.AcbPtr, g.AcbPtr)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Add(ByVal x As acb_t, ByVal y As acb_t, ByVal z As acb_t, ByVal prec As Int32)
      Lib_Acb_Add(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub AddUi(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Acb_Add_Ui(x.AcbPtr, y.AcbPtr, u, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Sub(ByVal AcbPtrX As IntPtr, ByVal AcbPtrY As IntPtr, ByVal AcbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Sub_(ByVal x As acb_t, ByVal y As acb_t, ByVal z As acb_t, ByVal prec As Int32)
      Lib_Acb_Sub(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Acb_Sub_Ui(x.AcbPtr, y.AcbPtr, u, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mul(ByVal AcbPtrX As IntPtr, ByVal AcbPtrY As IntPtr, ByVal AcbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Mul(ByVal x As acb_t, ByVal y As acb_t, ByVal z As acb_t, ByVal prec As Int32)
      Lib_Acb_Mul(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As acb_t, ByVal y As acb_t, ByVal si As Int32, ByVal prec As Int32)
      Lib_Acb_Mul_Si(x.AcbPtr, y.AcbPtr, si, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub MulUi(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Acb_Mul_Ui(x.AcbPtr, y.AcbPtr, u, prec)
  End Sub
'  
  
  
  
  
  
    

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Div(ByVal AcbPtrX As IntPtr, ByVal AcbPtrY As IntPtr, ByVal AcbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Div(ByVal x As acb_t, ByVal y As acb_t, ByVal z As acb_t, ByVal prec As Int32)
      Lib_Acb_Div(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Div_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub DivSi(ByVal x As acb_t, ByVal y As acb_t, ByVal si As Int32, ByVal prec As Int32)
      Lib_Acb_Div_Si(x.AcbPtr, y.AcbPtr, si, prec)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Div_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32, ByVal prec As Int32)
  End Sub
  
  Public  Sub DivUi(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32, ByVal prec As Int32)
      Lib_Acb_Div_Ui(x.AcbPtr, y.AcbPtr, u, prec)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32)
      Lib_Acb_Mul_2exp(x.AcbPtr, y.AcbPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Lib_Acb_Div_2exp(ByVal x As acb_t, ByVal y As acb_t, ByVal u As UInt32)
      Lib_Acb_Div_2exp(x.AcbPtr, y.AcbPtr, u)
  End Sub
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Pow(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Pow(ByVal x As acb_t, ByVal y As acb_t, ByVal z As acb_t, ByVal prec As Int32)
      Lib_Acb_Pow(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32, ByVal prec As Int32)
  End Sub
  
  Public  Sub PowSi(ByVal x As acb_t, ByVal y As acb_t, ByVal u As Int32, ByVal prec As Int32)
      Lib_Acb_Pow_Si(x.AcbPtr, y.AcbPtr, u, prec)
  End Sub
  
  
  
  
  
  
  
  

End Module


