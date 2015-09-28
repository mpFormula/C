
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text





Public Class mpfci_t


  Friend MpfiPtr_re As IntPtr = Nothing
  Friend MpfiPtr_im As IntPtr = Nothing
  Friend rc_re As Int32 = 0
  Friend rc_im As Int32 = 0
  
  


  Public Property real() As mpfi_t
      Get
          Dim m1 As New mpfi_t
          Lib_Mpfi_Set(m1.MpfiPtr, MpfiPtr_re)
          Return m1
    End Get

    Set(ByVal m1 As mpfi_t)
          Lib_Mpfi_Set(MpfiPtr_re, m1.MpfiPtr)
    End Set
  End Property
  
  
  
  Public Property imag() As mpfi_t
    Get
          Dim m1 As New mpfi_t
          Lib_Mpfi_Set(m1.MpfiPtr, MpfiPtr_im)
          Return m1
    End Get

    Set(ByVal m1 As mpfi_t)
          Lib_Mpfi_Set(MpfiPtr_re, m1.MpfiPtr)
    End Set
  End Property
  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpfci_Init(MpfiPtr_re, MpfiPtr_im)
  End Sub

  
  
  Public Sub New()
      Init()
  End Sub
  
  
  
  Public Sub New(ByVal x As mpfci_t)
      Init()
      Lib_Mpfci_Set(MpfiPtr_re, MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
  End Sub
  
  
  
  
  
  Public Sub New(ByVal x_re As Int32)
      Init()
      Lib_Mpfci_Set_Si(MpfiPtr_re, MpfiPtr_im, x_re)
  End Sub


  Public Sub New(ByVal x_re As UInt32)
      Init()
      Lib_Mpfci_Set_Ui(MpfiPtr_re, MpfiPtr_im, x_re)
  End Sub
  

  Public Sub New(ByVal x_re As Double)
      Init()
      Lib_Mpfci_Set_D(MpfiPtr_re, MpfiPtr_im, x_re)
  End Sub
  

  Public Sub New(ByVal x_re As String)
      Init()
      Lib_Mpfci_Set_Str(MpfiPtr_re, MpfiPtr_im, x_re, 10)
  End Sub
  
  
  ''' <summary>
  ''' Create a new mpfci_t
  ''' </summary>
  ''' <param name="x_re"></param>
  ''' <param name="x_im"></param>
  Public Sub New(ByVal x_re As Int32, ByVal x_im As Int32)
      Init()
      Lib_Mpfci_Set_Si_Si(MpfiPtr_re, MpfiPtr_im, x_re, x_im)
  End Sub


  Public Sub New(ByVal x_re As UInt32, ByVal x_im As UInt32)
      Init()
      Lib_Mpfci_Set_Ui_Ui(MpfiPtr_re, MpfiPtr_im, x_re, x_im)
  End Sub
  

  Public Sub New(ByVal x_re As Double, ByVal x_im As Double)
      Init()
      Lib_Mpfci_Set_D_D(MpfiPtr_re, MpfiPtr_im, x_re, x_im)
  End Sub
  

  Public Sub New(ByVal x_re As String, ByVal x_im As String)
      Init()
      Lib_Mpfci_Set_Str_Str(MpfiPtr_re, MpfiPtr_im, x_re, x_im, 10)
  End Sub
  
  
  
  
  Protected Overrides Sub Finalize()
'    Lib_Mpfci_Clear(MpfiPtr_re, MpfiPtr_im)
    MyBase.Finalize()
  End Sub

'
'
'  Public Shared Operator IsTrue(ByVal m1 As mpfci_t) As Boolean
'      Return (m1 = 0)
'  End Operator
'
'
'  Public Shared Operator IsFalse(ByVal m1 As mpfci_t) As Boolean
'      Return (m1 <> 0)
'  End Operator


  Public Overrides Function ToString() As String
    Return mpfci.Get_Str(MpfiPtr_re, MpfiPtr_im, getDPS())
  End Function
  
  
  
  Public  Sub Print()
      Lib_Mpfci_Print(MpfiPtr_re, MpfiPtr_im)
  End Sub



  Public Function __str__() As String
    Return mpfci.Get_Str(MpfiPtr_re, MpfiPtr_im, getDPS())
  End Function


  Public Function __repr__() As String
    Return  "mpfci_t('" & mpfci.Get_Str( MpfiPtr_re, MpfiPtr_im, getDPS()) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpfci_t) As String
      Return mpfci.Get_Str(m1.MpfiPtr_re, m1.MpfiPtr_im, getDPS())
  End Operator


  Public Shared Widening Operator CType(ByVal s As String) As mpfci_t
    Dim m1 As New mpfci_t
    mpfci.Lib_Mpfci_Set_Str(m1.MpfiPtr_re, m1.MpfiPtr_im, s, 10)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As Boolean
      Return (mpfci.Lib_Mpfci_Cmp(m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As Boolean
      Return (mpfci.Lib_Mpfci_Cmp(m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im) <> 0)
  End Operator



  Public Shared Operator +(ByVal m1 As mpfci_t) As mpfci_t
    Dim m2 As New mpfci_t(m1)
    Return m2
  End Operator


  Public Shared Operator -(ByVal m1 As mpfci_t) As mpfci_t
      Dim m2 As New mpfci_t()
      mpfci.Lib_Mpfci_Neg(m2.MpfiPtr_re, m2.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im)
      Return m2
  End Operator




  
  Public Shared Operator +(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As mpfci_t
      Dim m3 As New mpfci_t()
      mpfci.Lib_Mpfci_Add(m3.MpfiPtr_re, m3.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im)
    Return m3
  End Operator

  
  
  Public Shared Operator -(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As mpfci_t
      Dim m3 As New mpfci_t()
      mpfci.Lib_Mpfci_Sub(m3.MpfiPtr_re, m3.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im)
    Return m3
  End Operator



  
  Public Shared Operator *(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As mpfci_t
      Dim m3 As New mpfci_t()
      mpfci.Lib_Mpfci_Mul(m3.MpfiPtr_re, m3.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im)
    Return m3
  End Operator

  
  
  Public Shared Operator /(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As mpfci_t
      Dim m3 As New mpfci_t()
      mpfci.Lib_Mpfci_Div(m3.MpfiPtr_re, m3.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im)
    Return m3
  End Operator

  
  
  Public Shared Operator ^(ByVal m1 As mpfci_t, ByVal m2 As mpfci_t) As mpfci_t
      Dim m3 As New mpfci_t()
      mpfci.Lib_Mpfci_Pow(m3.MpfiPtr_re, m3.MpfiPtr_im, m1.MpfiPtr_re, m1.MpfiPtr_im, m2.MpfiPtr_re, m2.MpfiPtr_im)
    Return m3
  End Operator
  
  
  
  



End Class








Public Module mpfci
  
  
  
' ******************  Mpfci  Internal Functions*****************************
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Init(ByRef MpfiPtr_res_re As IntPtr, ByRef MpfiPtr_res_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Clear(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Print(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr)
  End Sub
  
  
  
    
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_Ui(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal ui As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_Si(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal i As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_D(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal d As Double)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Mpfci_Set_Str(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub
  
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Ui_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_Ui_Ui(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal x_re As UInt32, ByVal x_im As UInt32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Si_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_Si_Si(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal x_re As Int32, ByVal x_im As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_D_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Set_D_D(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal x_re As Double, ByVal x_im As Double)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Set_Str_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Mpfci_Set_Str_Str(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal x_re As String, ByVal x_im As String, ByVal b As Int32)
  End Sub
  
  
  Friend  Function Get_Str(ByVal MpfiPtr_re As IntPtr, ByVal MpfiPtr_im As IntPtr, ByVal digits As UInt32) As String
    Return mpfi.Get_Str(MpfiPtr_re, digits) & " + " & mpfi.Get_Str(MpfiPtr_im, digits) &"j"
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Mpfci_Cmp( ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr) As Int32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Neg(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Add(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Sub(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Mul(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Div", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Div(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr)
  End Sub
  
  
  
  
  
  
' ******************  Mpfci:  Internal and Public Functions  *****************************
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Pow", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Pow(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr,  ByVal MpfiPtr_y_re As IntPtr, ByVal MpfiPtr_y_im As IntPtr)
  End Sub
  
  
  
  Public  Function pow(ByVal x As mpfci_t, ByVal y As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Pow(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im, y.MpfiPtr_re, y.MpfiPtr_im)
      Return res
  End Function
  
  
  
  
  
  
  
' ******************  Mpfci:  Internal and Public Functions  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Sqr", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Sqr(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function sqr(ByVal x As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Sqr(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Log", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Log(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function log(ByVal x As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Log(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Exp(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function exp(ByVal x As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Exp(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Cos", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Cos(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function cos(ByVal x As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Cos(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Sin", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Sin(ByVal MpfiPtr_res_re As IntPtr, ByVal MpfiPtr_res_im As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function sin(ByVal x As mpfci_t) As mpfci_t
      Dim res As New mpfci_t
      Lib_Mpfci_Sin(res.MpfiPtr_re, res.MpfiPtr_im, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Abs", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Abs(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function abs(ByVal x As mpfci_t) As mpfi_t
      Dim res As New mpfi_t
      Lib_Mpfci_Abs(res.MpfiPtr, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpfci_Arg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Mpfci_Arg(ByVal MpfiPtr_res As IntPtr, ByVal MpfiPtr_x_re As IntPtr, ByVal MpfiPtr_x_im As IntPtr)
  End Sub
  
  Public  Function arg(ByVal x As mpfci_t) As mpfi_t
      Dim res As New mpfi_t
      Lib_Mpfci_Arg(res.MpfiPtr, x.MpfiPtr_re, x.MpfiPtr_im)
      Return res
  End Function
  
  
  
  
  
End Module




