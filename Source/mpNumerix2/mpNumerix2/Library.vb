
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text


'<ComClass(mpFmpz.ClassId, mpFmpz.InterfaceId, mpFmpz.EventsId)> _
Public Class mpFmpz

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'

  Friend FmpzPtr As IntPtr = Nothing


  ''' <summary>
  ''' Create a new mpFmpz
  ''' </summary>
  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Fmpz.Init(FmpzPtr)
    End If
  End Sub
  
  
  ''' <summary>
  ''' Create a new mpFmpz
  ''' </summary>
  ''' <param name="si32"></param>
  Public Sub New(ByVal si32 As Int32)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
        Fmpz.Lib_Fmpz_Set_Si(FmpzPtr, si32)
    End If
  End Sub


  Public Sub New(ByVal ui32 As UInt32)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
        Fmpz.Lib_Fmpz_Set_Ui(FmpzPtr, ui32)
    End If
  End Sub
  

  Public Sub New(ByVal si64 As Int64)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
      Dim si32 As Int32 = CInt(si64)
      Fmpz.Lib_Fmpz_Set_Si(FmpzPtr, si32)
    End If
  End Sub
  

  Public Sub New(ByVal ui64 As UInt64)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
      Dim ui32 As UInt32 = CUInt(ui64)
      Fmpz.Lib_Fmpz_Set_Ui(FmpzPtr, ui32)
    End If
  End Sub
  

  Public Sub New(ByVal d As Double)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
        Fmpz.Lib_Fmpz_Set_D(FmpzPtr, d)
    End If
  End Sub
  

  Public Sub New(ByVal s As String)
    If mp.HasLibraryNumC() <> 0 Then
        Fmpz.Init(FmpzPtr)
        Fmpz.Lib_Fmpz_Set_Str(FmpzPtr, s, 10)
    End If
  End Sub
  
  
  Protected Overrides Sub Finalize()
    Fmpz.Clear(FmpzPtr)
    MyBase.Finalize()
  End Sub



  Public Shared Operator IsTrue(ByVal m1 As mpFmpz) As Boolean
      Return (m1 = 0)
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpFmpz) As Boolean
      Return (m1 <> 0)
  End Operator


  Public Overrides Function ToString() As String
    Return Fmpz.Fmpz_Get_Str_2(10, FmpzPtr)
  End Function




  Public Function __str__() As String
    Return Fmpz.Fmpz_Get_Str_2(10, FmpzPtr)
  End Function


  Public Function __repr__() As String
    Return  "mpFmpz('" & Fmpz.Fmpz_Get_Str_2(10, FmpzPtr) & "')"
  End Function




  Public Shared Widening Operator CType(ByVal m1 As mpFmpz) As String
      Return Fmpz.GetStr(10, m1)
  End Operator


  Public Shared Narrowing Operator CType(ByVal s As String) As mpFmpz
    Dim m1 As New mpFmpz
    Fmpz.Lib_Fmpz_Set_Str(m1.FmpzPtr, s, 10)
    Return m1
  End Operator

'
'  Public Shared Narrowing Operator CType(ByVal m1 As mpFmpz) As Decimal
''    Return CDec(m1.x1.Str)
'    Return CDec("1")
'  End Operator
'
'  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpFmpz
'    Dim m1 As New mpFmpz
''    m1.x1 = m1.x1.Real(CStr(dec))
'    Return m1
'  End Operator


Public Shared Widening Operator CType(ByVal m1 As mpFmpz) As Double
    
    'MsgBox("Double")
      Return Fmpz.Lib_Fmpz_Get_D(m1.FmpzPtr)
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal d As Double) As mpFmpz
    Dim m1 As New mpFmpz
    Fmpz.Lib_Fmpz_Set_D(m1.FmpzPtr, d)
    Return m1
  End Operator


  Public Shared Narrowing Operator CType(ByVal m1 As mpFmpz) As Int32
    Return Fmpz.Lib_Fmpz_Get_Si(m1.FmpzPtr)
  End Operator

  Public Shared Widening Operator CType(ByVal si As Int32) As mpFmpz
    Dim m1 As New mpFmpz
      Fmpz.Lib_Fmpz_Set_Si(m1.FmpzPtr, si)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpFmpz) As Int64
    Return Fmpz.Lib_Fmpz_Get_Si(m1.FmpzPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal si As Int64) As mpFmpz
      Dim m1 As New mpFmpz
      Dim si32 As Int32 = CInt(si)
      Fmpz.Lib_Fmpz_Set_Si(m1.FmpzPtr, si32)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpFmpz) As UInt32
    Return Fmpz.Lib_Fmpz_Get_Ui(m1.FmpzPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt32) As mpFmpz
      Dim m1 As New mpFmpz
      Fmpz.Lib_Fmpz_Set_Ui(m1.FmpzPtr, ui)
    Return m1
  End Operator
  
  
  Public Shared Widening Operator CType(ByVal m1 As mpFmpz) As UInt64
    Return Fmpz.Lib_Fmpz_Get_Ui(m1.FmpzPtr)
  End Operator
  
  Public Shared Narrowing Operator CType(ByVal ui As UInt64) As mpFmpz
      Dim m1 As New mpFmpz
      Dim ui32 As UInt32 = CUInt(ui)
      Fmpz.Lib_Fmpz_Set_Ui(m1.FmpzPtr, ui32)
    Return m1
  End Operator
  
  
  
  
  Public Shared Operator =(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) = 0)
  End Operator


  Public Shared Operator <>(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) <> 0)
  End Operator


  Public Shared Operator <=(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) <= 0)
  End Operator


  Public Shared Operator <(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) < 0)
  End Operator


  Public Shared Operator >=(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) >= 0)
  End Operator


  Public Shared Operator >(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As Boolean
      Return (Fmpz.Lib_Fmpz_Cmp(m1.FmpzPtr, m2.FmpzPtr) > 0)
  End Operator
  
'



  Public Shared Operator +(ByVal m1 As mpFmpz) As mpFmpz
    Dim m3 As New mpFmpz()
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Neg(m3.FmpzPtr, m1.FmpzPtr)
      Return m3
  End Operator
  

  
  
  Public Shared Operator +(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Add(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  

  Public Shared Operator +(ByVal m1 As mpFmpz, ByVal si As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
    'MsgBox("Plus_si")
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal m1 As mpFmpz, ByVal si As Int64) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
    Return m3
  End Operator
  

  Public Shared Operator +(ByVal si As Int64, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
    Return m3
  End Operator
  
  
  
  Public Shared Operator -(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Sub(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  


  Public Shared Operator -(ByVal m1 As mpFmpz, ByVal si As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpFmpz, ByVal si As Int64) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si > 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
      Return m3
  End Operator


  Public Shared Operator -(ByVal si As Int64, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim ui As UInt32 = CUInt(Math.Abs(si))
      If (si < 0) Then
          Fmpz.Lib_Fmpz_Add_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      Else
          Fmpz.Lib_Fmpz_Sub_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
      End If
      Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  

  
  Public Shared Operator *(ByVal m1 As mpFmpz, ByVal si As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal m1 As mpFmpz, ByVal si As Int64) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, CInt(si))
    Return m3
  End Operator
  
  
  
  Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal si As Int64, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Si(m3.FmpzPtr, m1.FmpzPtr, CInt(si))
    Return m3
  End Operator


  Public Shared Operator *(ByVal m1 As mpFmpz, ByVal ui As UInt32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  

  Public Shared Operator *(ByVal m1 As mpFmpz, ByVal ui As UInt64) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator

  
  Public Shared Operator *(ByVal ui As UInt64, ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Mul_Ui(m3.FmpzPtr, m1.FmpzPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
      Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpFmpz, ByVal si As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Tdiv_Q_Si(m3.FmpzPtr, m1.FmpzPtr, si)
    Return m3
  End Operator
  
  

  Public Shared Operator /(ByVal m1 As mpFmpz, ByVal si As Int64) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Tdiv_Q_Si(m3.FmpzPtr, m1.FmpzPtr, CInt(si))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpFmpz, ByVal ui As UInt32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Tdiv_Q_Ui(m3.FmpzPtr, m1.FmpzPtr, ui)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal m1 As mpFmpz, ByVal ui As UInt64) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Tdiv_Q_Ui(m3.FmpzPtr, m1.FmpzPtr, CUInt(ui))
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int32, ByVal m2 As mpFmpz) As mpFmpz
      Dim m1, m3 As New mpFmpz()
      m1 = si
      Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator /(ByVal si As Int64, ByVal m2 As mpFmpz) As mpFmpz
      Dim m1, m3 As New mpFmpz()
      m1 = si
      Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  
  Public Shared Operator /(ByVal ui As UInt32, ByVal m2 As mpFmpz) As mpFmpz
      Dim m1, m3 As New mpFmpz()
      m1 = ui
      Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator

  
  Public Shared Operator /(ByVal ui As UInt64, ByVal m2 As mpFmpz) As mpFmpz
      Dim m1, m3 As New mpFmpz()
      m1 = ui
      Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  Public Shared Operator &(ByVal m1 As mpFmpz, ByVal s As String) As String
      Return m1.ToString() & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpFmpz) As String
      Return s & m1.ToString
  End Operator



  
  
  Public Shared Operator ^(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim n As UInt32 = m2
      Fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, n)
    Return m3
  End Operator
  


  Public Shared Operator ^(ByVal m1 As mpFmpz, ByVal n As UInt32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, n)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpFmpz, ByVal n As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      Fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, m1.FmpzPtr, CUInt(n))
    Return m3
  End Operator



  Public Function __pow__(ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
      Dim n As UInt32 = m2
      Fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, FmpzPtr, n)
    Return m3
  End Function



  Public Function __pow__(ByVal n As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
'      MsgBox("pow")      
      Fmpz.Lib_Fmpz_Pow_Ui(m3.FmpzPtr, FmpzPtr, CUInt(n))
    Return m3
  End Function



  Public Function __rpow__(ByVal n1 As Int32) As mpFmpz
      Dim m3 As New mpFmpz()
      MsgBox("rpow")
    Return m3
  End Function




  Public Shared Operator Mod(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
    Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_Mod(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator



  Public Shared Operator \(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
    Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_Tdiv_Q(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator
  
  
  
  
' OPERATORS ONLY FOR INTEGERS:  
  
' Left Shift
  Public Shared Operator <<(ByVal m1 As mpFmpz, ByVal e As Integer) As mpFmpz
    Dim m3 As New mpFmpz()
    Fmpz.Lib_Fmpz_Mul_2exp(m3.FmpzPtr, m1.FmpzPtr, CUInt(e))
    Return m3
  End Operator
  


' Right Shift
  Public Shared Operator >>(ByVal m1 As mpFmpz, ByVal e As Integer) As mpFmpz
    Dim m3 As New mpFmpz()
    Fmpz.Lib_Fmpz_Tdiv_Q_2exp(m3.FmpzPtr, m1.FmpzPtr, CUInt(e))
    Return m3
  End Operator
  

' OnesComplement
  Public Shared Operator Not(ByVal m1 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_Complement(m3.FmpzPtr, m1.FmpzPtr)
    Return m3
  End Operator



' Bitwise And
  Public Shared Operator And(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_And(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator


' Bitwise Or
  Public Shared Operator Or(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_Or(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator


' Exclusive OR
  Public Shared Operator Xor(ByVal m1 As mpFmpz, ByVal m2 As mpFmpz) As mpFmpz
      Dim m3 As New mpFmpz()
        Fmpz.Lib_Fmpz_Xor(m3.FmpzPtr, m1.FmpzPtr, m2.FmpzPtr)
    Return m3
  End Operator



End Class




'<ComClass(mpFmpq.ClassId, mpFmpq.InterfaceId, mpFmpq.EventsId)> _
Public Class mpFmpq

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend FmpqPtr As IntPtr = Nothing


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Fmpq.Init(FmpqPtr)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Fmpq.Clear(FmpqPtr)
    MyBase.Finalize()
  End Sub



  Public Function Str() As String
    Return "1"
  End Function




End Class



'<ComClass(mpArb.ClassId, mpArb.InterfaceId, mpArb.EventsId)> _
Public Class mpArb

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend ArbPtr As IntPtr = Nothing


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Arb.Init(ArbPtr)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Arb.Clear(ArbPtr)
    MyBase.Finalize()
  End Sub

  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function



End Class



'<ComClass(mpAcb.ClassId, mpAcb.InterfaceId, mpAcb.EventsId)> _
Public Class mpAcb

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend AcbPtr As IntPtr = Nothing


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Acb.Init(AcbPtr)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Acb.Clear(AcbPtr)
    MyBase.Finalize()
  End Sub



  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function



End Class




'<ComClass(mpFmpzMat.ClassId, mpFmpzMat.InterfaceId, mpFmpzMat.EventsId)> _
Public Class mpFmpzMat

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend FmpzMatPtr As IntPtr = Nothing


  'Shared x1 As New mp_Real
  Private MultMode As Integer = 0

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
    If mp.HasLibraryNumC() <> 0 Then
      Fmpz.MatInit(FmpzMatPtr, m, n)
    End If

  End Sub
  


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Fmpz.MatInit(FmpzMatPtr, 1, 1)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Console.WriteLine("Release mpFmpzMat")
    Fmpz.MatClear(FmpzMatPtr)
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <returns>The number of rows in the matrix</returns>
  Public ReadOnly Property Rows() As Integer
    Get
      '    	Return x1.Rows
      Return 1
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <returns>The number of columns in the matrix</returns>
  Public ReadOnly Property Cols() As Integer
    Get
      '    	Return x1.Cols
      Return 1
    End Get
  End Property

  Public ReadOnly Property Size() As Integer
    Get
      '    	Return x1.Size
      Return 1
    End Get
  End Property


  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function


  ''' <summary>
  ''' Gets and Item
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpFmpz
    Get
      Dim m1 As New mpFmpz
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As mpFmpz)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As mpFmpz
    Get
      Dim m1 As New mpFmpz
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As mpFmpz)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpFmpz
    Get
      Dim m1 As New mpFmpz
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpFmpz)
      '      x1.Col(j) = m1.x1
    End Set

  End Property








  Public Shared Widening Operator CType(ByVal m1 As mpFmpzMat) As String
      '    Return m1.x1.Str
      Return "1"
  End Operator


  'Public Shared Narrowing Operator CType(ByVal s As String) As mpFmpzMat
  Public Shared Widening Operator CType(ByVal s As String) As mpFmpzMat
    Dim m1 As New mpFmpzMat
'    m1.x1 = m1.x1.Real(s)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpFmpzMat) As Decimal
'    Return CDec(m1.x1.Str)
    Return CDec("1")
  End Operator

  Public Shared Narrowing Operator CType(ByVal dec As Decimal) As mpFmpzMat
    Dim m1 As New mpFmpzMat
'    m1.x1 = m1.x1.Real(CStr(dec))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpFmpzMat) As Double
      '    Return m1.x1.Dbl
      Return 1.0
  End Operator

  'Public Shared Narrowing Operator CType(ByVal d As Double) As mpFmpzMat
  Public Shared Widening Operator CType(ByVal d As Double) As mpFmpzMat
    Dim m1 As New mpFmpzMat
'    m1.x1 = m1.x1.Real(d)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpFmpzMat) As Long
'    Return m1.x1.Lng
    Return 1
    
  End Operator

  Public Shared Narrowing Operator CType(ByVal si As Long) As mpFmpzMat
    Dim m1 As New mpFmpzMat
'    m1.x1 = m1.x1.Real(CStr(si))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpFmpzMat) As ULong
'    Return CULng(m1.x1.Lng)
    Return 1
  End Operator

  Public Shared Narrowing Operator CType(ByVal ui As ULong) As mpFmpzMat
    Dim m1 As New mpFmpzMat
'    m1.x1 = m1.x1.Real(CStr(ui))
    Return m1
  End Operator


  Public Shared Operator =(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'      Return CBool(m1.x1.EQ(m2.x1))
      Return True
  End Operator


  Public Shared Operator <>(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'    Return CBool(m1.x1.NE(m2.x1))
      Return True
  End Operator



  Public Shared Operator <=(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'    Return CBool(m1.x1.LE(m2.x1))
      Return True
  End Operator



  Public Shared Operator <(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'    Return CBool(m1.x1.LT(m2.x1))
      Return True
  End Operator


  Public Shared Operator >=(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'    Return CBool(m1.x1.GE(m2.x1))
      Return True
  End Operator


  Public Shared Operator >(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As Boolean
'    Return CBool(m1.x1.GT(m2.x1))
      Return True
  End Operator


  Public Shared Operator +(ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Times_i(-1)
    Return m3
  End Operator


  ''' <summary>
  ''' Adds two matrices together and returns a third matrix with the sum.  The matrices need to have the
  ''' same dimensions.
  ''' </summary>
  ''' <param name="m1">First matrix</param>
  ''' <param name="m2">Second matrix</param>
  ''' <returns>A new matrix with the sum of the first two</returns>
  ''' <remarks></remarks>
  Public Shared Operator +(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Plus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator +(ByVal m1 As mpFmpzMat, ByVal si As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
    'MsgBox("Plus_si")
'    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Integer, ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
    'MsgBox("Plus_si")
'    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator

  Public Shared Operator -(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Minus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpFmpzMat, ByVal i As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Minus_i(i)
    Return m3
  End Operator


  Public Shared Operator -(ByVal i As Integer, ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
    'm3.x1 = m1.x1.Minus_i(i)
'    m3.x1 = m1.x1.Minus_i_Neg(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    If (m1.MultMode = 1) Then
'      m3.x1 = m1.x1.TimesMat(m2.x1)
'    Else
'      m3.x1 = m1.x1.Times(m2.x1)
'    End If
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As mpFmpzMat, ByVal i As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal i As Integer, ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Div(m2.x1)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As mpFmpzMat, ByVal i As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Div_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal i As Integer, ByVal m1 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Div_i_Inv(i)
    Return m3
  End Operator


  Public Shared Operator &(ByVal m1 As mpFmpzMat, ByVal s As String) As String
'      Return m1.Str & s
      Return "1"
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpFmpzMat) As String
'    Return s & m1.Str
      Return "1"
  End Operator



  ' New operators for COM:
  ' Pow, Mod, IntDiv, LSh, Rsh, AND, OR, XOR
  ' New Functions for COM:
  ' IsTrue, IsFalse, NOT

  '>>
  '<<
  'AND
  'OR
  'XOR
  'IsTrue
  'IsFalse
  'NOT

  Public Shared Operator ^(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Pow(m2.x1)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpFmpzMat, ByVal n As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Pow_i(n)
    Return m3
  End Operator


  Public Shared Operator Mod(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.Mod(m2.x1)
    Return m3
  End Operator


  Public Shared Operator \(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.IntDiv(m2.x1)
    Return m3
  End Operator


  Public Shared Operator <<(ByVal m1 As mpFmpzMat, ByVal i As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.RSH(i)
    Return m3
  End Operator


  Public Shared Operator >>(ByVal m1 As mpFmpzMat, ByVal i As Integer) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.LSH(i)
    Return m3
  End Operator


  Public Shared Operator IsTrue(ByVal m1 As mpFmpzMat) As Boolean
'      Return m1.x1.Is_Zero = 0
      Return True
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpFmpzMat) As Boolean
'    Return m1.x1.Is_Zero <> 0
      Return True
  End Operator


  Public Shared Operator Not(ByVal m1 As mpFmpzMat) As Boolean
'    If m1.x1.Is_Zero <> 0 Then
'      Return False
'    Else
'      Return True
'    End If
      Return True
    
  End Operator


  Public Shared Operator And(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.AND(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Or(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.OR(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Xor(ByVal m1 As mpFmpzMat, ByVal m2 As mpFmpzMat) As mpFmpzMat
    Dim m3 As New mpFmpzMat()
'    m3.x1 = m1.x1.XOR(m2.x1)
    Return m3
  End Operator


  Public Overrides Function ToString() As String
      '    Return x1.Str
      Return "1"
  End Function








End Class


'<ComClass(mpFmpqMat.ClassId, mpFmpqMat.InterfaceId, mpFmpqMat.EventsId)> _
Public Class mpFmpqMat

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend FmpqMatPtr As IntPtr = Nothing

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
    If mp.HasLibraryNumC() <> 0 Then
      Fmpq.MatInit(FmpqMatPtr, m, n)
    End If
  End Sub
  
  


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Fmpq.MatInit(FmpqMatPtr, 1, 1)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Fmpq.MatClear(FmpqMatPtr)
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <returns>The number of rows in the matrix</returns>
  Public ReadOnly Property Rows() As Integer
    Get
      '    	Return x1.Rows
      Return 1
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <returns>The number of columns in the matrix</returns>
  Public ReadOnly Property Cols() As Integer
    Get
      '    	Return x1.Cols
      Return 1
    End Get
  End Property

  Public ReadOnly Property Size() As Integer
    Get
      '    	Return x1.Size
      Return 1
    End Get
  End Property


  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function


  Public Property Prec10() As Integer
    Get
      '    	Return x1.Prec10
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec10 = Value
    End Set
  End Property


  Public Property Prec2() As Integer
    Get
      '    	Return x1.Prec2
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec2 = Value
    End Set
  End Property

  ''' <summary>
  ''' Gets and Item
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpFmpq
    Get
      Dim m1 As New mpFmpq
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As mpFmpq)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As mpFmpq
    Get
      Dim m1 As New mpFmpq
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As mpFmpq)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpFmpq
    Get
      Dim m1 As New mpFmpq
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpFmpq)
      '      x1.Col(j) = m1.x1
    End Set

  End Property



End Class



'<ComClass(mpArbMat.ClassId, mpArbMat.InterfaceId, mpArbMat.EventsId)> _
Public Class mpArbMat

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend ArbMatPtr As IntPtr = Nothing

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
    If mp.HasLibraryNumC() <> 0 Then
      Arb.MatInit(ArbMatPtr, m, n)
    End If
  End Sub
  


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Arb.MatInit(ArbMatPtr, 1, 1)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Console.WriteLine("Release mpArb")
    Arb.MatClear(ArbMatPtr)
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <returns>The number of rows in the matrix</returns>
  Public ReadOnly Property Rows() As Integer
    Get
      '    	Return x1.Rows
      Return 1
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <returns>The number of columns in the matrix</returns>
  Public ReadOnly Property Cols() As Integer
    Get
      '    	Return x1.Cols
      Return 1
    End Get
  End Property

  Public ReadOnly Property Size() As Integer
    Get
      '    	Return x1.Size
      Return 1
    End Get
  End Property


  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function


  Public Property Prec10() As Integer
    Get
      '    	Return x1.Prec10
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec10 = Value
    End Set
  End Property


  Public Property Prec2() As Integer
    Get
      '    	Return x1.Prec2
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec2 = Value
    End Set
  End Property

  ''' <summary>
  ''' Gets and Item
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpArb
    Get
      Dim m1 As New mpArb
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As mpArb)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As mpArb
    Get
      Dim m1 As New mpArb
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As mpArb)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpArb
    Get
      Dim m1 As New mpArb
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpArb)
      '      x1.Col(j) = m1.x1
    End Set

  End Property



End Class



'<ComClass(mpAcbMat.ClassId, mpAcbMat.InterfaceId, mpAcbMat.EventsId)> _
Public Class mpAcbMat

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend AcbMatPtr As IntPtr = Nothing

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
    If mp.HasLibraryNumC() <> 0 Then
      Acb.MatInit(AcbMatPtr, m, n)
    End If
  End Sub
  


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      Acb.MatInit(AcbMatPtr, 1, 1)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Acb.MatClear(AcbMatPtr)
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <returns>The number of rows in the matrix</returns>
  Public ReadOnly Property Rows() As Integer
    Get
      '    	Return x1.Rows
      Return 1
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <returns>The number of columns in the matrix</returns>
  Public ReadOnly Property Cols() As Integer
    Get
      '    	Return x1.Cols
      Return 1
    End Get
  End Property

  Public ReadOnly Property Size() As Integer
    Get
      '    	Return x1.Size
      Return 1
    End Get
  End Property


  Public Function Str() As String
    '  	Return x1.Str
    Return "1"
  End Function


  Public Property Prec10() As Integer
    Get
      '    	Return x1.Prec10
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec10 = Value
    End Set
  End Property


  Public Property Prec2() As Integer
    Get
      '    	Return x1.Prec2
      Return 1
    End Get

    Set(ByVal Value As Integer)
      '      x1.Prec2 = Value
    End Set
  End Property

  ''' <summary>
  ''' Gets and Item
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpAcb
    Get
      Dim m1 As New mpAcb
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As mpAcb)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As mpAcb
    Get
      Dim m1 As New mpAcb
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As mpAcb)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpAcb
    Get
      Dim m1 As New mpAcb
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpAcb)
      '      x1.Col(j) = m1.x1
    End Set

  End Property



End Class





'<ComClass(Fmpz.ClassId, Fmpz.InterfaceId, Fmpz.EventsId)> _
Public Module mp

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "9BF0EA6E-1C75-4D35-9D38-3D960CD978B4"
'  Public Const InterfaceId As String _
'  = "9842D62B-4960-4446-9B14-971D843B471C"
'  Public Const EventsId As String _
'  = "A18AA124-CE61-4051-A5E5-2A1815A215B0"
'#End Region


#Region "External Functions Declarations"
  Private Declare Function LoadLibrary Lib "KERNEL32.dll" Alias "LoadLibraryA" (ByVal lpFile As String) As IntPtr


#End Region


#Region "Helper Functions"
  Private  Function RootDir() As String
    Dim regKey As RegistryKey
    Dim RootPath As String = "Not set"
    Try
      regKey = Registry.CurrentUser.OpenSubKey("SOFTWARE\mpFormulaToolbox", False)
      RootPath = (regKey.GetValue("RootPath", "Not set")).ToString()
      regKey.Close()
    Catch ex As Exception
      MsgBox("RootDir not set")
    End Try
    Return RootPath
  End Function



  Friend  Function HasLibraryNumC() As Double
    Static Result As Double = 0
    If Result = 0 Then
      'Dim DLLPath As String = CStr(My.Computer.Registry.GetValue("HKEY_LOCAL_MACHINE\SOFTWARE\THF", "DLLPath", Nothing))
      Dim DLLPath As String = RootDir() & "..\mpFormulaC\mpNum\Win32"
      Directory.SetCurrentDirectory(DLLPath)

      Dim FName As String = DLLPath & "\mpNumC.dll"
      'MsgBox(FName)
      ' MsgBox(DLLPath)
      Result = CDbl(LoadLibrary(FName))
    End If
    If Result = 0 Then
      MsgBox("Could not load supporting library mpNumC!")
      Return 0
    Else
      Return 1
    End If
  End Function
#End Region


   Sub New()
    Dim Result As Double = HasLibraryNumC()
    Console.WriteLine("New NumC 32: ", Result.ToString())
  End Sub

'

End Module

Public Module Fmpz
  
' ******************  Fmpz  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Init(ByRef FmpzPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Clear(ByVal FmpzPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Print(ByVal FmpzPtr As IntPtr)
  End Sub
  
  Public  Sub Print(ByVal x As mpFmpz)
      Lib_Fmpz_Print(x.FmpzPtr)
  End Sub
  


  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Ui(ByVal FmpzPtr As IntPtr, ByVal ui As UInt32)
  End Sub

  Public  Sub SetUi(ByVal x As mpFmpz, ByVal ui As UInt32)
      Lib_Fmpz_Set_Ui(x.FmpzPtr, ui)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_Si(ByVal FmpzPtr As IntPtr, ByVal i As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpFmpz, ByVal i As Int32)
      Lib_Fmpz_Set_Si(x.FmpzPtr, i)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Set_D(ByVal FmpzPtr As IntPtr, ByVal d As Double)
  End Sub

  Public  Sub SetD(ByVal x As mpFmpz, ByVal d As Double)
      Lib_Fmpz_Set_D(x.FmpzPtr, d)
  End Sub
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Sub Lib_Fmpz_Set_Str(ByVal FmpzPtr As IntPtr, ByVal str As String, ByVal b As Int32)
  End Sub

  Public Sub SetStr(ByVal x As mpFmpz, ByVal str As String, ByVal b As Int32)
    Lib_Fmpz_Set_Str(x.FmpzPtr, str, b)
  End Sub

  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Ui(ByVal FmpzPtr As IntPtr) As UInt32
  End Function

  Public  Function GetUi(ByVal x As mpFmpz) As UInt32
      Return Lib_Fmpz_Get_Ui(x.FmpzPtr)
  End Function


  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_Si(ByVal FmpzPtr As IntPtr) As Int32
  End Function

  Public  Function GetSi(ByVal x As mpFmpz) As Int32
      Return Lib_Fmpz_Get_Si(x.FmpzPtr)
  End Function
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Get_D(ByVal FmpzPtr As IntPtr) As Double
  End Function

  Public  Function GetD(ByVal x As mpFmpz) As Double
      Return Lib_Fmpz_Get_D(x.FmpzPtr)
  End Function
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend  Function Lib_Fmpz_Get_Str(ByVal sb As StringBuilder, ByVal base As Int32, ByVal FmpzPtr As IntPtr) As IntPtr
  End Function

  Friend  Function Fmpz_Get_Str_2(ByVal base As Int32, ByVal FmpzPtr As IntPtr) As String
    Dim sb As  New StringBuilder(10000)
    Dim res As IntPtr = Lib_Fmpz_Get_Str(sb, base, FmpzPtr)
    Return sb.ToString()
  End Function
  
  
  Public  Function GetStr(ByVal base As Int32, ByVal x As mpFmpz) As String
    Dim sb As  New StringBuilder(10000)
    Dim res As IntPtr = Lib_Fmpz_Get_Str(sb, base, x.FmpzPtr)
    Return sb.ToString()
  End Function

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Fmpz_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
  End Function

  Public  Function Cmp(ByVal f As mpFmpz, ByVal g As mpFmpz) As Int32
      Return Lib_Fmpz_Cmp(f.FmpzPtr, g.FmpzPtr)
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Neg", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub

  Public  Sub Neg(ByVal f As mpFmpz, ByVal g As mpFmpz)
      Lib_Fmpz_Neg(f.FmpzPtr, g.FmpzPtr)
  End Sub
  
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Add(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_Add(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub AddUi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Add_Ui(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Sub_(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_Sub(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Sub_Ui(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Sub_Ui(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub Mul(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_Mul(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub MulSi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal si As Int32)
      Lib_Fmpz_Mul_Si(x.FmpzPtr, y.FmpzPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub MulUi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Mul_Ui(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q(ByVal FmpzPtrX As IntPtr, ByVal FmpzPtrY As IntPtr, ByVal FmpzPtrZ As IntPtr)
  End Sub
  
  Public  Sub TdivQ(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_Tdiv_Q(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub

  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
  End Sub
  
  Public  Sub TdivQSi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal si As Int32)
      Lib_Fmpz_Tdiv_Q_Si(x.FmpzPtr, y.FmpzPtr, si)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQUi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Tdiv_Q_Ui(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub Mul2exp(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Mul_2exp(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Tdiv_Q_2exp", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Tdiv_Q_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub TdivQ2exp(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Tdiv_Q_2exp(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mod", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mod(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub Mod_(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_Mod(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
  End Sub
  
  Public  Sub PowUi(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal u As UInt32)
      Lib_Fmpz_Pow_Ui(x.FmpzPtr, y.FmpzPtr, u)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Complement", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Complement(ByVal f As IntPtr, ByVal g As IntPtr)
  End Sub
  
  Public  Sub Complement(ByVal x As mpFmpz, ByVal y As mpFmpz)
      Lib_Fmpz_Complement(x.FmpzPtr, y.FmpzPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_And", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_And(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub And_(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_And(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_OR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_OR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub OR_(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_OR(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_XOR", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_XOR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
  End Sub
  
  Public  Sub XOR_(ByVal x As mpFmpz, ByVal y As mpFmpz, ByVal z As mpFmpz)
      Lib_Fmpz_XOR(x.FmpzPtr, y.FmpzPtr, z.FmpzPtr)
  End Sub
  
  
  
' ******************  FmpzMat  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatInit(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatClear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Print_Pretty(ByVal A As IntPtr)
  End Sub
  
  Public  Sub MatPrint(ByVal X As mpFmpzMat)
      Lib_Fmpz_Mat_Print_Pretty(X.FmpzMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr)
  End Sub
  
  Public  Sub MatMul(ByVal X As mpFmpzMat, ByVal Y As mpFmpzMat, ByVal Z As mpFmpzMat)
      Lib_Fmpz_Mat_Mul(X.FmpzMatPtr, Y.FmpzMatPtr, Z.FmpzMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Set_Ui(ByVal FmpzPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
  End Sub

  Public  Sub MatSetUi(ByVal X As mpFmpzMat, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
      Lib_Fmpz_Mat_Set_Ui(X.FmpzMatPtr, i, j, u)
  End Sub



End Module

Public Module Fmpq

  
' ******************  Fmpq  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Init(ByRef FmpqPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Clear(ByVal FmpqPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Print(ByVal FmpqPtr As IntPtr)
  End Sub
  
  Public  Sub Print(ByVal x As mpFmpq)
      Lib_Fmpq_Print(x.FmpqPtr)
  End Sub
  



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mul(ByVal FmpqPtrX As IntPtr, ByVal FmpqPtrY As IntPtr, ByVal FmpqPtrZ As IntPtr)
  End Sub
  
  Public  Sub Mul(ByVal x As mpFmpq, ByVal y As mpFmpq, ByVal z As mpFmpq)
      Lib_Fmpq_Mul(x.FmpqPtr, y.FmpqPtr, z.FmpqPtr)
  End Sub

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Set_Si(ByVal FmpqPtr As IntPtr, ByVal a As Int32, ByVal b As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpFmpq, ByVal a As Int32, ByVal b As Int32)
      Lib_Fmpq_Set_Si(x.FmpqPtr, a, b)
  End Sub


  
  
' ******************  FmpqMat  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatInit(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatClear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Print_Pretty(ByVal A As IntPtr)
  End Sub
  
  Public  Sub MatPrint(ByVal X As mpFmpqMat)
      Lib_Fmpq_Mat_Print_Pretty(X.FmpqMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr)
  End Sub
  
  Public  Sub MatMul(ByVal X As mpFmpqMat, ByVal Y As mpFmpqMat, ByVal Z As mpFmpqMat)
      Lib_Fmpq_Mat_Mul(X.FmpqMatPtr, Y.FmpqMatPtr, Z.FmpqMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Set_Si(ByVal FmpqPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32)
  End Sub

  Public  Sub MatSetSi(ByVal X As mpFmpqMat, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32)
      Lib_Fmpq_Mat_Set_Si(X.FmpqMatPtr, i, j, p, q)
  End Sub



End Module

Public Module Arb

 
  
' ******************  Arb  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Init(ByRef ArbPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Clear(ByVal ArbPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Printd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Printd(ByVal ArbPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Print(ByVal x As mpArb, ByVal prec As Int32)
      Lib_Arb_Printd(x.ArbPtr, prec)
  End Sub
  



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mul(ByVal ArbPtrX As IntPtr, ByVal ArbPtrY As IntPtr, ByVal ArbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Mul(ByVal x As mpArb, ByVal y As mpArb, ByVal z As mpArb, ByVal prec As Int32)
      Lib_Arb_Mul(x.ArbPtr, y.ArbPtr, z.ArbPtr, prec)
  End Sub

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Set_Si(ByVal ArbPtr As IntPtr, ByVal u As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpArb, ByVal u As Int32)
      Lib_Arb_Set_Si(x.ArbPtr, u)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Const_Pi(ByVal ArbPtr As IntPtr, ByVal prec As Int32)
  End Sub

  Public  Sub ConstPi(ByVal x As mpArb, ByVal prec As Int32)
      Lib_Arb_Const_Pi(x.ArbPtr, prec)
  End Sub

  
  
' ******************  ArbMat  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatInit(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatClear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mat_Print_Pretty(ByVal A As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub MatPrint(ByVal X As mpArbMat, ByVal prec As Int32)
      Lib_Arb_Mat_Print_Pretty(X.ArbMatPtr, prec)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub MatMul(ByVal X As mpArbMat, ByVal Y As mpArbMat, ByVal Z As mpArbMat, ByVal prec As Int32)
      Lib_Arb_Mat_Mul(X.ArbMatPtr, Y.ArbMatPtr, Z.ArbMatPtr, prec)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Arb_Mat_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Arb_Mat_Set_Ui(ByVal ArbPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
  End Sub

  Public  Sub MatSetUi(ByVal X As mpArbMat, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
      Lib_Arb_Mat_Set_Ui(X.ArbMatPtr, i, j, u)
  End Sub




End Module

Public Module Acb

 
  
' ******************  Acb  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Init(ByRef AcbPtr As IntPtr)
  End Sub
 

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Clear(ByVal AcbPtr As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Printd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Printd(ByVal AcbPtr As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Print(ByVal x As mpAcb, ByVal prec As Int32)
      Lib_Acb_Printd(x.AcbPtr, prec)
  End Sub
  



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mul(ByVal AcbPtrX As IntPtr, ByVal AcbPtrY As IntPtr, ByVal AcbPtrZ As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub Mul(ByVal x As mpAcb, ByVal y As mpAcb, ByVal z As mpAcb, ByVal prec As Int32)
      Lib_Acb_Mul(x.AcbPtr, y.AcbPtr, z.AcbPtr, prec)
  End Sub

  

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Set_Si(ByVal AcbPtr As IntPtr, ByVal u As Int32)
  End Sub

  Public  Sub SetSi(ByVal x As mpAcb, ByVal u As Int32)
      Lib_Acb_Set_Si(x.AcbPtr, u)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Const_Pi", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Const_Pi(ByVal AcbPtr As IntPtr, ByVal prec As Int32)
  End Sub

  Public  Sub ConstPi(ByVal x As mpAcb, ByVal prec As Int32)
      Lib_Acb_Const_Pi(x.AcbPtr, prec)
  End Sub

  
  
' ******************  AcbMat  *****************************
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatInit(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub MatClear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mat_Print_Pretty(ByVal A As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub MatPrint(ByVal X As mpAcbMat, ByVal prec As Int32)
      Lib_Acb_Mat_Print_Pretty(X.AcbMatPtr, prec)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr, ByVal prec As Int32)
  End Sub
  
  Public  Sub MatMul(ByVal X As mpAcbMat, ByVal Y As mpAcbMat, ByVal Z As mpAcbMat, ByVal prec As Int32)
      Lib_Acb_Mat_Mul(X.AcbMatPtr, Y.AcbMatPtr, Z.AcbMatPtr, prec)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Acb_Mat_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Acb_Mat_Set_Ui(ByVal AcbPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
  End Sub

  Public  Sub MatSetUi(ByVal X As mpAcbMat, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
      Lib_Acb_Mat_Set_Ui(X.AcbMatPtr, i, j, u)
  End Sub









''' <summary>
''' Returns the StdDoubleSum of x and y
''' </summary>
''' <param name="x">Number of rows</param>
''' <param name="y">Number of columns</param>
''' <returns>Sqrt(x^2 + y^2)</returns>
''' <remarks>Remarks</remarks>
  <DllImport("mpNumC.dll", EntryPoint:="Std_Double_Sum", CallingConvention:=CallingConvention.Cdecl)> _
  Public  Function StdDoubleSum(x As Double, y As Double) As Double
  End Function
  
  
End Module

