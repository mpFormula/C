
Imports System
Imports System.Runtime.InteropServices
Imports System.Text

Public Class gmp_randstate_t

  Friend GmpRandPtr As IntPtr = Nothing

  Public Sub New()
      mp4.Init()
      mpz.Lib_Gmp_Rand_Init(GmpRandPtr)
  End Sub
  
    
  Protected Overrides Sub Finalize()
    mpz.Lib_Gmp_Rand_Clear(GmpRandPtr)
    MyBase.Finalize()
  End Sub


End Class


Public Class randstate_t

  Friend RandPtr As IntPtr = Nothing
  
  
  Public Sub New()
      mp4.Init()
      mpz.Lib_Flint_Rand_Init(RandPtr)
  End Sub
  
    
  Protected Overrides Sub Finalize()
    mpz.Lib_Flint_Rand_Clear(RandPtr)
    MyBase.Finalize()
  End Sub


End Class


Public Class mpz_t


    Friend MpzPtr As IntPtr = Nothing

  
  
  Private Sub Init()
      mp4.Init()
      Lib_Mpz_Init(MpzPtr)
  End Sub





    ''' <summary>
    ''' Create a new mpz_t
    ''' </summary>
    Public Sub New()
        Init()
    End Sub


    Public Sub New(ByVal x As mpz_t)
        Init()
        Lib_Mpz_Set(MpzPtr, x.MpzPtr)
    End Sub



    ''' <summary>
    ''' Create a new mpz_t
    ''' </summary>
    ''' <param name="si32"></param>
    Public Sub New(ByVal si32 As Int32)
        Init()
        Lib_Mpz_Set_Si(MpzPtr, si32)
    End Sub



    Public Sub New(ByVal ui32 As UInt32)
        Init()
        Lib_Mpz_Set_Ui(MpzPtr, ui32)
    End Sub


    Public Sub New(ByVal si64 As Int64)
        Init()
        Lib_Mpz_Set_Si64(MpzPtr, si64)
    End Sub


    Public Sub New(ByVal ui64 As UInt64)
        Init()
        Lib_Mpz_Set_Ui64(MpzPtr, ui64)
    End Sub


    Public Sub New(ByVal d As Double)
        Init()
        Lib_Mpz_Set_D(MpzPtr, d)
    End Sub


    Public Sub New(ByVal s As String)
        Init()
        Lib_Mpz_Set_Str(MpzPtr, s, 10)
    End Sub


    Protected Overrides Sub Finalize()
        Lib_Mpz_Clear(MpzPtr)
        MyBase.Finalize()
    End Sub



    Public Shared Operator IsTrue(ByVal m1 As mpz_t) As Boolean
        Return (m1 = 0)
    End Operator


    Public Shared Operator IsFalse(ByVal m1 As mpz_t) As Boolean
        Return (m1 <> 0)
    End Operator


    Public Overrides Function ToString() As String
        Return mpz.Get_Str(10, MpzPtr)
    End Function


    Public Sub Print()
        Lib_Mpz_Print(MpzPtr)
    End Sub



    Public Function __str__() As String
        Return mpz.Get_Str(10, MpzPtr)
    End Function


    Public Function __repr__() As String
        Return "mpz_t('" & mpz.Get_Str(10, MpzPtr) & "')"
    End Function




    Public Shared Widening Operator CType(ByVal m1 As mpz_t) As String
        Return mpz.Get_Str(10, m1.MpzPtr)
    End Operator


    Public Shared Widening Operator CType(ByVal s As String) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_Str(m1.MpzPtr, s, 10)
        Return m1
    End Operator

    '
    '  Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As Decimal
    ''    Return CDec(m1.x1.Str)
    '    Return CDec("1")
    '  End Operator
    '
    '  Public Shared Widening Operator CType(ByVal dec As Decimal) As mpz_t
    '    Dim m1 As New mpz_t
    ''    m1.x1 = m1.x1.Real(CStr(dec))
    '    Return m1
    '  End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As Double

        'MsgBox("Double")
        Return mpz.Lib_Mpz_Get_D(m1.MpzPtr)
    End Operator


    Public Shared Widening Operator CType(ByVal d As Double) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_D(m1.MpzPtr, d)
        Return m1
    End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As Int32
        Return mpz.Lib_Mpz_Get_Si(m1.MpzPtr)
    End Operator

    Public Shared Widening Operator CType(ByVal si As Int32) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_Si(m1.MpzPtr, si)
        Return m1
    End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As Int64
        Return mpz.Lib_Mpz_Get_Si64(m1.MpzPtr)
    End Operator

    Public Shared Widening Operator CType(ByVal si64 As Int64) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_Si64(m1.MpzPtr, si64)
        Return m1
    End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As UInt32
        Return mpz.Lib_Mpz_Get_Ui(m1.MpzPtr)
    End Operator

    Public Shared Widening Operator CType(ByVal ui As UInt32) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_Ui(m1.MpzPtr, ui)
        Return m1
    End Operator


    Public Shared Narrowing Operator CType(ByVal m1 As mpz_t) As UInt64
        Return mpz.Lib_Mpz_Get_Ui64(m1.MpzPtr)
    End Operator

    Public Shared Widening Operator CType(ByVal ui64 As UInt64) As mpz_t
        Dim m1 As New mpz_t
        mpz.Lib_Mpz_Set_Ui64(m1.MpzPtr, ui64)
        Return m1
    End Operator




    Public Shared Operator =(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) = 0)
    End Operator


    Public Shared Operator <>(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) <> 0)
    End Operator


    Public Shared Operator <=(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) <= 0)
    End Operator


    Public Shared Operator <(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) < 0)
    End Operator


    Public Shared Operator >=(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) >= 0)
    End Operator


    Public Shared Operator >(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As Boolean
        Return (mpz.Lib_Mpz_Cmp(m1.MpzPtr, m2.MpzPtr) > 0)
    End Operator

    '



    Public Shared Operator +(ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Neg(m3.MpzPtr, m1.MpzPtr)
        Return m3
    End Operator



    '***********************************************************************


    Public Shared Operator +(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator




    Public Shared Operator +(ByVal m1 As mpz_t, ByVal ui As UInt32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator

    Public Shared Operator +(ByVal ui As UInt32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpz_t, ByVal si As Int32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator

    Public Shared Operator +(ByVal si As Int32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator




    Public Shared Operator +(ByVal m1 As mpz_t, ByVal si64 As Int64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Si64(m3.MpzPtr, m1.MpzPtr, si64)
        Return m3
    End Operator

    Public Shared Operator +(ByVal si64 As Int64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Si64(m3.MpzPtr, m1.MpzPtr, si64)
        Return m3
    End Operator



    Public Shared Operator +(ByVal m1 As mpz_t, ByVal ui64 As UInt64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Ui64(m3.MpzPtr, m1.MpzPtr, ui64)
        Return m3
    End Operator

    Public Shared Operator +(ByVal ui64 As UInt64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Add_Ui64(m3.MpzPtr, m1.MpzPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Sub(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui As UInt32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Ui_Sub(m3.MpzPtr, ui, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpz_t, ByVal ui As UInt32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Sub_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si As Int32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Si_Sub(m3.MpzPtr, si, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpz_t, ByVal si As Int32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Sub_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator



    Public Shared Operator -(ByVal ui64 As UInt64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Ui64_Sub(m3.MpzPtr, ui64, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpz_t, ByVal ui64 As UInt64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Sub_Ui64(m3.MpzPtr, m1.MpzPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator -(ByVal si64 As Int64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Si64_Sub(m3.MpzPtr, si64, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator -(ByVal m1 As mpz_t, ByVal si64 As Int64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Sub_Si64(m3.MpzPtr, m1.MpzPtr, si64)
        Return m3
    End Operator









    Public Shared Operator *(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator *(ByVal ui As UInt32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpz_t, ByVal ui As UInt32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator



    Public Shared Operator *(ByVal si As Int32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpz_t, ByVal si As Int32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator



    Public Shared Operator *(ByVal ui64 As UInt64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Ui64(m3.MpzPtr, m1.MpzPtr, CUInt(ui64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpz_t, ByVal ui64 As UInt64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Ui64(m3.MpzPtr, m1.MpzPtr, CUInt(ui64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal si64 As Int64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Si64(m3.MpzPtr, m1.MpzPtr, CInt(si64))
        Return m3
    End Operator



    Public Shared Operator *(ByVal m1 As mpz_t, ByVal si64 As Int64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_Si64(m3.MpzPtr, m1.MpzPtr, CInt(si64))
        Return m3
    End Operator




    Public Shared Operator /(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui As UInt32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Ui_Tdiv_Q(m3.MpzPtr, ui, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpz_t, ByVal ui As UInt32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q_Ui(m3.MpzPtr, m1.MpzPtr, ui)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si As Int32, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Si_Tdiv_Q(m3.MpzPtr, si, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpz_t, ByVal si As Int32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q_Si(m3.MpzPtr, m1.MpzPtr, si)
        Return m3
    End Operator



    Public Shared Operator /(ByVal ui64 As UInt64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Ui64_Tdiv_Q(m3.MpzPtr, ui64, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpz_t, ByVal ui64 As UInt64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q_Ui64(m3.MpzPtr, m1.MpzPtr, ui64)
        Return m3
    End Operator



    Public Shared Operator /(ByVal si64 As Int64, ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Si64_Tdiv_Q(m3.MpzPtr, si64, m1.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator /(ByVal m1 As mpz_t, ByVal si64 As Int64) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q_Si64(m3.MpzPtr, m1.MpzPtr, si64)
        Return m3
    End Operator




    '***********************************************************************



    Public Shared Operator &(ByVal m1 As mpz_t, ByVal s As String) As String
        Return m1.ToString() & s
    End Operator


    Public Shared Operator &(ByVal s As String, ByVal m1 As mpz_t) As String
        Return s & m1.ToString
    End Operator





    Public Shared Operator ^(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        Dim n As UInt32 = CUInt(m2)
        mpz.Lib_Mpz_Pow_Ui(m3.MpzPtr, m1.MpzPtr, n)
        Return m3
    End Operator



    Public Shared Operator ^(ByVal m1 As mpz_t, ByVal n As UInt32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Pow_Ui(m3.MpzPtr, m1.MpzPtr, n)
        Return m3
    End Operator


    Public Shared Operator ^(ByVal m1 As mpz_t, ByVal n As Int32) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Pow_Ui(m3.MpzPtr, m1.MpzPtr, CUInt(n))
        Return m3
    End Operator



    Public Function __pow__(ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        Dim n As UInt32 = CUInt(m2)
        mpz.Lib_Mpz_Pow_Ui(m3.MpzPtr, MpzPtr, n)
        Return m3
    End Function



    Public Function __pow__(ByVal n As Int32) As mpz_t
        Dim m3 As New mpz_t()
        '      MsgBox("pow")      
        mpz.Lib_Mpz_Pow_Ui(m3.MpzPtr, MpzPtr, CUInt(n))
        Return m3
    End Function



    Public Function __rpow__(ByVal n1 As Int32) As mpz_t
        Dim m3 As New mpz_t()
        MsgBox("rpow")
        Return m3
    End Function





    Public Function __floordiv__(ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q(m3.MpzPtr, MpzPtr, m2.MpzPtr)
        Return m3
    End Function




    Public Function __floordiv__(ByVal n1 As Int32) As mpz_t
        Dim m3 As New mpz_t()
        Dim m2 As New mpz_t(n1)
        mpz.Lib_Mpz_Tdiv_Q(m3.MpzPtr, MpzPtr, m2.MpzPtr)
        Return m3
    End Function



    Public Shared Operator Mod(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mod(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator



    Public Shared Operator \(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator




    ' OPERATORS ONLY FOR INTEGERS:  

    ' Left Shift
    Public Shared Operator <<(ByVal m1 As mpz_t, ByVal e As Integer) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Mul_2exp(m3.MpzPtr, m1.MpzPtr, CUInt(e))
        Return m3
    End Operator



    ' Right Shift
    Public Shared Operator >>(ByVal m1 As mpz_t, ByVal e As Integer) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Tdiv_Q_2exp(m3.MpzPtr, m1.MpzPtr, CUInt(e))
        Return m3
    End Operator


    ' OnesComplement
    Public Shared Operator Not(ByVal m1 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Complement(m3.MpzPtr, m1.MpzPtr)
        Return m3
    End Operator



    ' Bitwise And
    Public Shared Operator And(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_And(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator


    ' Bitwise Or
    Public Shared Operator Or(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Or(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator


    ' Exclusive OR
    Public Shared Operator Xor(ByVal m1 As mpz_t, ByVal m2 As mpz_t) As mpz_t
        Dim m3 As New mpz_t()
        mpz.Lib_Mpz_Xor(m3.MpzPtr, m1.MpzPtr, m2.MpzPtr)
        Return m3
    End Operator



End Class








Public Module mpz

    ' ******************  Mpz  Internal Functions*****************************



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Gmp_Rand_Init", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Gmp_Rand_Init(ByRef GmpRandPtr As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Clear", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Gmp_Rand_Clear(ByVal GmpRandPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Init", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Flint_Rand_Init(ByRef RandPtr As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Flint_Rand_Clear", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Flint_Rand_Clear(ByVal RandPtr As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Init", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Init(ByRef MpzPtr As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Clear", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Clear(ByVal MpzPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Print", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Print(ByVal MpzPtr As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set(ByVal MpzPtr As IntPtr, ByVal MpzPtr_x As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set_Ui(ByVal MpzPtr As IntPtr, ByVal ui As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set_Si(ByVal MpzPtr As IntPtr, ByVal i As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set_Ui64(ByVal MpzPtr As IntPtr, ByVal ui As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set_Si64(ByVal MpzPtr As IntPtr, ByVal si64 As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Set_D(ByVal MpzPtr As IntPtr, ByVal d As Double)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Set_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
    Friend Sub Lib_Mpz_Set_Str(ByVal MpzPtr As IntPtr, ByVal str As String, ByVal b As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Get_Ui(ByVal MpzPtr As IntPtr) As UInt32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Get_Si(ByVal MpzPtr As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Get_Ui64(ByVal MpzPtr As IntPtr) As UInt64
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Get_Si64(ByVal MpzPtr As IntPtr) As Int64
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_D", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Get_D(ByVal MpzPtr As IntPtr) As Double
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_SizeInBase", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_SizeInBase(ByVal MpzPtr As IntPtr, ByVal base As Int32) As UInt32
    End Function

    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Get_Str", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
    Friend Function Lib_Mpz_Get_Str(ByVal sb As StringBuilder, ByVal base As Int32, ByVal MpzPtr As IntPtr) As IntPtr
    End Function

    Friend Function Get_Str(ByVal base As Int32, ByVal MpzPtr As IntPtr) As String
        Dim StrSize As Int32 = CInt(Lib_Mpz_SizeInBase(MpzPtr, 10))
        Dim sb As New StringBuilder(StrSize)
        Dim res As IntPtr = Lib_Mpz_Get_Str(sb, base, MpzPtr)
        Return sb.ToString()
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Cmp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Mpz_Cmp(ByVal f As IntPtr, ByVal g As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Neg", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Neg(ByVal f As IntPtr, ByVal g As IntPtr)
    End Sub





    '***********************************************************************



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Add", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Add(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Add_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Add_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Add_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Add_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Add_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Add_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Add_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Add_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Sub(ByVal MpzPtrX As IntPtr, ByVal MpzPtrY As IntPtr, ByVal MpzPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Ui_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Ui_Sub(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Sub_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Sub_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Si_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Si_Sub(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Sub_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Sub_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Ui64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Ui64_Sub(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Sub_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Sub_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Si64_Sub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Si64_Sub(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Sub_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Sub_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
    End Sub









    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul(ByVal MpzPtrX As IntPtr, ByVal MpzPtrY As IntPtr, ByVal MpzPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal si As Int64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q(ByVal MpzPtrX As IntPtr, ByVal MpzPtrY As IntPtr, ByVal MpzPtrZ As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Ui_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Ui_Tdiv_Q(ByVal f As IntPtr, ByVal u As UInt32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Si_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Si_Tdiv_Q(ByVal f As IntPtr, ByVal u As Int32, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q_Si", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q_Si(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int32)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Ui64_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Ui64_Tdiv_Q(ByVal f As IntPtr, ByVal u As UInt64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q_Ui64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q_Ui64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt64)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Si64_Tdiv_Q", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Si64_Tdiv_Q(ByVal f As IntPtr, ByVal u As Int64, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q_Si64", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q_Si64(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As Int64)
    End Sub



    '***********************************************************************




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mul_2exp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mul_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Tdiv_Q_2exp", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Tdiv_Q_2exp(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Mod", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Mod(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Complement", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Complement(ByVal f As IntPtr, ByVal g As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_And", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_And(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_OR", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_OR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_XOR", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_XOR(ByVal f As IntPtr, ByVal g As IntPtr, ByVal h As IntPtr)
    End Sub



    ' ******************  Mpz  Internal and Public Functions*****************************


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_Pow_Ui", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_Pow_Ui(ByVal f As IntPtr, ByVal g As IntPtr, ByVal u As UInt32)
    End Sub

    Public Function pow(ByVal y As mpz_t, ByVal u As UInt32) As mpz_t
        Dim x As New mpz_t
        Lib_Mpz_Pow_Ui(x.MpzPtr, y.MpzPtr, u)
        Return x
    End Function



    ' ******************  Mpz Public Functions  *****************************


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Mpz_RandM", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Mpz_RandM(ByVal res_MpzPtr As IntPtr, ByVal state_RandPtr As IntPtr, ByVal m_MpzPtr As IntPtr)
    End Sub


    Public Function randm(ByVal state As randstate_t, ByVal m As mpz_t) As mpz_t
        Dim res As New mpz_t
        Lib_Mpz_RandM(res.MpzPtr, state.RandPtr, m.MpzPtr)
        Return res
    End Function



End Module




