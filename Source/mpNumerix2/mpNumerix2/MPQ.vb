
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class mpq_t

    Friend MpqPtr As IntPtr = Nothing



    Public Property num() As mpz_t
        Get
            Dim m1 As New mpz_t
            Lib_Mpq_Get_Num(m1.MpzPtr, MpqPtr)
            Return m1
        End Get

        Set(ByVal m1 As mpz_t)
            Lib_Mpq_Set_Num(MpqPtr, m1.MpzPtr)
        End Set
    End Property



    Public Property den() As mpz_t
        Get
            Dim m1 As New mpz_t
            Lib_Mpq_Get_Den(m1.MpzPtr, MpqPtr)
            Return m1
        End Get

        Set(ByVal m1 As mpz_t)
            Lib_Mpq_Set_Den(MpqPtr, m1.MpzPtr)
        End Set
    End Property

  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpq_Init(MpqPtr)
  End Sub


    Public Sub New()
        Init()
    End Sub



    Public Sub New(ByVal p As mpq_t)
        Init()
        Lib_Mpq_Set(MpqPtr, p.MpqPtr)
    End Sub



    Public Sub New(ByVal p As mpz_t)
        Init()
        Lib_Mpq_Set_Mpz(MpqPtr, p.MpzPtr)
    End Sub



    Public Sub New(ByVal p As mpz_t, ByVal q As mpz_t)
        Init()
        Lib_Mpq_Set_Mpz_Frac(MpqPtr, p.MpzPtr, q.MpzPtr)
    End Sub




    Public Sub New(ByVal ui32 As UInt32)
        Init()
        Lib_Mpq_Set_Ui_Ui(MpqPtr, ui32, 1)
    End Sub



    Public Sub New(ByVal si32 As Int32)
        Init()
        Lib_Mpq_Set_Si_Si(MpqPtr, si32, 1)
    End Sub



    Public Sub New(ByVal p As UInt32, ByVal q As UInt32)
        Init()
        Lib_Mpq_Set_Ui_Ui(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As UInt32, ByVal q As Int32)
        Init()
        Lib_Mpq_Set_Ui_Si(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As Int32, ByVal q As UInt32)
        Init()
        Lib_Mpq_Set_Si_Ui(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As Int32, ByVal q As Int32)
        Init()
        Lib_Mpq_Set_Si_Si(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal ui64 As UInt64)
        Init()
        Lib_Mpq_Set_Ui64_Ui64(MpqPtr, ui64, 1)
    End Sub



    Public Sub New(ByVal si64 As Int64)
        Init()
        Lib_Mpq_Set_Si64_Si64(MpqPtr, si64, 1)
    End Sub



    Public Sub New(ByVal p As UInt64, ByVal q As UInt64)
        Init()
        Lib_Mpq_Set_Ui64_Ui64(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As UInt64, ByVal q As Int64)
        Init()
        Lib_Mpq_Set_Ui64_Si64(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As Int64, ByVal q As UInt64)
        Init()
        Lib_Mpq_Set_Si64_Ui64(MpqPtr, p, q)
    End Sub



    Public Sub New(ByVal p As Int64, ByVal q As Int64)
        Init()
        Lib_Mpq_Set_Si64_Si64(MpqPtr, p, q)
    End Sub




    Public Sub New(ByVal d As Double)
        Init()
        Lib_Mpq_Set_D(MpqPtr, d)
    End Sub



    Public Sub New(ByVal s As String)
        Init()
        Lib_Mpq_Set_Str(MpqPtr, s, 10)
    End Sub



    Protected Overrides Sub Finalize()
        Lib_Mpq_Clear(MpqPtr)
        MyBase.Finalize()
    End Sub



    Public Shared Operator IsTrue(ByVal m1 As mpq_t) As Boolean
        Return (m1 = 0)
    End Operator



    Public Shared Operator IsFalse(ByVal m1 As mpq_t) As Boolean
        Return (m1 <> 0)
    End Operator



    Public Sub Print()
        Lib_Mpq_Print(MpqPtr)
    End Sub



    Public Overrides Function ToString() As String
        Return mpq.Get_Str(10, MpqPtr)
    End Function



    Public Function __str__() As String
        Return mpq.Get_Str(10, MpqPtr)
    End Function



    Public Function __repr__() As String
        Return "mpq_t('" & mpq.Get_Str(10, MpqPtr) & "')"
    End Function



    Public Shared Widening Operator CType(ByVal m1 As mpq_t) As String
        Return mpq.Get_Str(10, m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal s As String) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Str(m1.MpqPtr, s, 10)
        Return m1
    End Operator


    '  Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As Decimal
    ''    Return CDec(m1.x1.Str)
    '    Return CDec("1")
    '  End Operator
    '
    '  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpq_t
    '    Dim m1 As New mpq_t
    ''    m1.x1 = m1.x1.Real(CStr(dec))
    '    Return m1
    '  End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As Double
        Return mpq.Lib_Mpq_Get_D(m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal d As Double) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_D(m1.MpqPtr, d)
        Return m1
    End Operator



    Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As Int32
        Return mpq.Lib_Mpq_Get_Si(m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal si As Int32) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Si_Si(m1.MpqPtr, si, 1)
        Return m1
    End Operator



    Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As Int64
        Return mpq.Lib_Mpq_Get_Si64(m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal si64 As Int64) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Si64_Si64(m1.MpqPtr, si64, 1)
        Return m1
    End Operator



    Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As UInt32
        Return mpq.Lib_Mpq_Get_Ui(m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal ui As UInt32) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Ui_Ui(m1.MpqPtr, ui, 1)
        Return m1
    End Operator



    Public Shared Narrowing Operator CType(ByVal m1 As mpq_t) As UInt64
        Return mpq.Lib_Mpq_Get_Ui64(m1.MpqPtr)
    End Operator



    Public Shared Widening Operator CType(ByVal ui64 As UInt64) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Ui64_Ui64(m1.MpqPtr, ui64, 1)
        Return m1
    End Operator



    Public Shared Widening Operator CType(ByVal m1 As mpq_t) As mpz_t
        Dim z1 As New mpz_t
        mpq.Lib_Mpq_Get_Mpz(z1.MpzPtr, m1.MpqPtr)
        Return z1
    End Operator



    Public Shared Widening Operator CType(ByVal z1 As mpz_t) As mpq_t
        Dim m1 As New mpq_t
        mpq.Lib_Mpq_Set_Mpz(m1.MpqPtr, z1.MpzPtr)
        Return m1
    End Operator



    Public Shared Operator =(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) = 0)
    End Operator



    Public Shared Operator <>(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) <> 0)
    End Operator



    Public Shared Operator <=(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) <= 0)
    End Operator



    Public Shared Operator <(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) < 0)
    End Operator



    Public Shared Operator >=(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) >= 0)
    End Operator



    Public Shared Operator >(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As Boolean
        Return (mpq.Lib_Mpq_Cmp(m1.MpqPtr, m2.MpqPtr) > 0)
    End Operator



    Public Shared Operator +(ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t(m1)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Neg(m3.MpqPtr, m1.MpqPtr)
        Return m3
    End Operator


    '***********************************************************************



    Public Shared Operator +(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add(m3.MpqPtr, m1.MpqPtr, m2.MpqPtr)
        Return m3
    End Operator




    Public Shared Operator +(ByVal m1 As mpq_t, ByVal ui As UInt32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator

    Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpq_t, ByVal si As Int32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator

    Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator




    Public Shared Operator +(ByVal m1 As mpq_t, ByVal si64 As Int64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Si64(m3.MpqPtr, m1.MpqPtr, si64)
        Return m3
    End Operator

    Public Shared Operator +(ByVal si64 As Int64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Si64(m3.MpqPtr, m1.MpqPtr, si64)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpq_t, ByVal ui64 As UInt64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Ui64(m3.MpqPtr, m1.MpqPtr, ui64)
        Return m3
    End Operator

    Public Shared Operator +(ByVal ui64 As UInt64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Add_Ui64(m3.MpqPtr, m1.MpqPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Sub(m3.MpqPtr, m1.MpqPtr, m2.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Ui_Sub(m3.MpqPtr, ui, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t, ByVal ui As UInt32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Sub_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Si_Sub(m3.MpqPtr, si, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t, ByVal si As Int32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Sub_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui64 As UInt64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Ui64_Sub(m3.MpqPtr, ui64, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t, ByVal ui64 As UInt64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Sub_Ui64(m3.MpqPtr, m1.MpqPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si64 As Int64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Si64_Sub(m3.MpqPtr, si64, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpq_t, ByVal si64 As Int64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Sub_Si64(m3.MpqPtr, m1.MpqPtr, si64)
        Return m3
    End Operator









    Public Shared Operator *(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul(m3.MpqPtr, m1.MpqPtr, m2.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpq_t, ByVal ui As UInt32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpq_t, ByVal si As Int32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator



    Public Shared Operator *(ByVal ui64 As UInt64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Ui64(m3.MpqPtr, m1.MpqPtr, CUInt(ui64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpq_t, ByVal ui64 As UInt64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Ui64(m3.MpqPtr, m1.MpqPtr, CUInt(ui64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal si64 As Int64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Si64(m3.MpqPtr, m1.MpqPtr, CInt(si64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpq_t, ByVal si64 As Int64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mul_Si64(m3.MpqPtr, m1.MpqPtr, CInt(si64))
        Return m3
    End Operator




    Public Shared Operator /(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div(m3.MpqPtr, m1.MpqPtr, m2.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Ui_Div(m3.MpqPtr, ui, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpq_t, ByVal ui As UInt32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div_Ui(m3.MpqPtr, m1.MpqPtr, ui)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int32, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Si_Div(m3.MpqPtr, si, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpq_t, ByVal si As Int32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div_Si(m3.MpqPtr, m1.MpqPtr, si)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui64 As UInt64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Ui64_Div(m3.MpqPtr, ui64, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpq_t, ByVal ui64 As UInt64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div_Ui64(m3.MpqPtr, m1.MpqPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si64 As Int64, ByVal m1 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Si64_Div(m3.MpqPtr, si64, m1.MpqPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpq_t, ByVal si64 As Int64) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div_Si64(m3.MpqPtr, m1.MpqPtr, si64)
        Return m3
    End Operator




    '***********************************************************************



    Public Shared Operator &(ByVal m1 As mpq_t, ByVal s As String) As String
        Return m1.ToString() & s
    End Operator


    Public Shared Operator &(ByVal s As String, ByVal m1 As mpq_t) As String
        Return s & m1.ToString
    End Operator





    Public Shared Operator ^(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        Dim n As Int32 = CInt(m2)
        mpq.Lib_Mpq_Pow_Si(m3.MpqPtr, m1.MpqPtr, n)
        Return m3
    End Operator



    Public Shared Operator ^(ByVal m1 As mpq_t, ByVal n As UInt32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Pow_Si(m3.MpqPtr, m1.MpqPtr, CInt(n))
        Return m3
    End Operator


    Public Shared Operator ^(ByVal m1 As mpq_t, ByVal n As Int32) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Pow_Si(m3.MpqPtr, m1.MpqPtr, n)
        Return m3
    End Operator



    Public Function __pow__(ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        Dim n As Int32 = CInt(m2)
        mpq.Lib_Mpq_Pow_Si(m3.MpqPtr, MpqPtr, n)
        Return m3
    End Function



    Public Function __pow__(ByVal n As Int32) As mpq_t
        Dim m3 As New mpq_t()
        '      MsgBox("pow")      
        mpq.Lib_Mpq_Pow_Si(m3.MpqPtr, MpqPtr, n)
        Return m3
    End Function



    Public Function __rpow__(ByVal n1 As Int32) As mpq_t
        Dim m3 As New mpq_t()
        MsgBox("rpow")
        Return m3
    End Function





    Public Function __floordiv__(ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div(m3.MpqPtr, MpqPtr, m2.MpqPtr)
        Return m3
    End Function




    Public Function __floordiv__(ByVal n1 As Int32) As mpq_t
        Dim m3 As New mpq_t()
        Dim m2 As New mpq_t(n1)
        mpq.Lib_Mpq_Div(m3.MpqPtr, MpqPtr, m2.MpqPtr)
        Return m3
    End Function



    Public Shared Operator Mod(ByVal m1 As mpq_t, ByVal m2 As mpz_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Mod_Mpz(m3.MpqPtr, m1.MpqPtr, m2.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator \(ByVal m1 As mpq_t, ByVal m2 As mpq_t) As mpq_t
        Dim m3 As New mpq_t()
        mpq.Lib_Mpq_Div(m3.MpqPtr, m1.MpqPtr, m2.MpqPtr)
        Return m3
    End Operator


End Class







Public Module mpq


    ' ******************  Mpq:  Internal Functions  *****************************


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Init", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Init(ByRef MpqPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Clear", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Clear(ByVal MpqPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Print", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Print(ByVal MpqPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui(ByVal MpqPtr As IntPtr, ByVal a As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si(ByVal MpqPtr As IntPtr, ByVal a As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui64(ByVal MpqPtr As IntPtr, ByVal a As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si64(ByVal MpqPtr As IntPtr, ByVal a As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui_Ui(ByVal MpqPtr As IntPtr, ByVal a As UInt32, ByVal b As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui_Si(ByVal MpqPtr As IntPtr, ByVal a As UInt32, ByVal b As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si_Ui(ByVal MpqPtr As IntPtr, ByVal a As Int32, ByVal b As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si_Si(ByVal MpqPtr As IntPtr, ByVal a As Int32, ByVal b As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui64_Ui64(ByVal MpqPtr As IntPtr, ByVal a As UInt64, ByVal b As UInt64)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Ui64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Ui64_Si64(ByVal MpqPtr As IntPtr, ByVal a As UInt64, ByVal b As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si64_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si64_Ui64(ByVal MpqPtr As IntPtr, ByVal a As Int64, ByVal b As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Si64_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Si64_Si64(ByVal MpqPtr As IntPtr, ByVal a As Int64, ByVal b As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Mpz_Frac", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Mpz_Frac(ByVal MpqPtr_x As IntPtr, ByVal MpzPtr_p As IntPtr, ByVal MpzPtr_q As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Mpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Mpz(ByVal MpqPtr_x As IntPtr, ByVal MpzPtr_p As IntPtr)
    End Sub







    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Num", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Num(ByVal MpqPtr_x As IntPtr, ByVal MpzPtr_p As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Den", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_Den(ByVal MpqPtr_x As IntPtr, ByVal MpzPtr_p As IntPtr)
    End Sub











    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set(ByVal MpqPtr_x As IntPtr, ByVal MpqPtr_p As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Set_D(ByVal MpqPtr As IntPtr, ByVal d As Double)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
    Friend Sub Lib_Mpq_Set_Str(ByVal MpqPtr As IntPtr, ByVal str As String, ByVal b As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Get_Ui(ByVal MpqPtr As IntPtr) As UInt32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Get_Si(ByVal MpqPtr As IntPtr) As Int32
    End Function





    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Get_Ui64(ByVal MpqPtr As IntPtr) As UInt64
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Get_Si64(ByVal MpqPtr As IntPtr) As Int64
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Get_D(ByVal MpqPtr As IntPtr) As Double
    End Function






    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Mpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Get_Mpz(ByVal MpzPtr_res As IntPtr, ByVal MpqPtr_x As IntPtr)
    End Sub






    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Num", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Get_Num(ByVal MpzPtr_res As IntPtr, ByVal MpqPtr_x As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Den", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Get_Den(ByVal MpzPtr_res As IntPtr, ByVal MpqPtr_x As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_SizeInBase", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_SizeInBase(ByVal MpqPtr As IntPtr, ByVal base As Int32) As UInt32
    End Function

    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
    Friend Function Lib_Mpq_Get_Str(ByVal sb As StringBuilder, ByVal base As Int32, ByVal MpqPtr As IntPtr) As IntPtr
    End Function

    Friend Function Get_Str(ByVal base As Int32, ByVal MpqPtr As IntPtr) As String
        Dim StrSize As Int32 = CInt(Lib_Mpq_SizeInBase(MpqPtr, 10))
        Dim sb As New StringBuilder(StrSize)
        Dim res As IntPtr = Lib_Mpq_Get_Str(sb, base, MpqPtr)
        Return sb.ToString()
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpq_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Neg", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
    End Sub



    '***********************************************************************




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Add", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Add_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Add_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Add_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Sub(ByVal MpqPtrX As IntPtr, ByVal MpqPtrY As IntPtr, ByVal MpqPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Ui_Sub(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Si_Sub(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Sub_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Ui64_Sub(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Sub_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Si64_Sub(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Sub_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
    End Sub









    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul(ByVal MpqPtrX As IntPtr, ByVal MpqPtrY As IntPtr, ByVal MpqPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div(ByVal MpqPtrX As IntPtr, ByVal MpqPtrY As IntPtr, ByVal MpqPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Ui_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Ui_Div(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Si_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Si_Div(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Ui64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Ui64_Div(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Si64_Div", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Si64_Div(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
    End Sub




    '***********************************************************************








    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Div_2exp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Div_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Mod_Mpz", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Mod_Mpz(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub


    ' ******************  Mpq:  Internal and Public Functions  *****************************


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpq_Pow_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpq_Pow_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
    End Sub

    Public Function pow(ByVal y As mpq_t, ByVal u As Int32) As mpq_t
        Dim x As New mpq_t
        Lib_Mpq_Pow_Si(x.MpqPtr, y.MpqPtr, u)
        Return x
    End Function



End Module
  
  
  
