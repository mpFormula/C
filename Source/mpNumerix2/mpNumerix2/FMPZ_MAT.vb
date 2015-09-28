
Imports System
Imports System.Runtime.InteropServices

Public Class fmpz_mat_t



  Friend FmpzMatPtr As IntPtr = Nothing
  
    
    
  
  Private Sub Init(ByVal m As Integer, ByVal n As Integer)
      mp4.Init()
      Lib_Fmpz_Mat_Init(FmpzMatPtr, m, n)
  End Sub
  
  

  'Shared x1 As New mp_Real
  Private MultMode As Integer = 0

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
      Init(m, n)
  End Sub
  


  Public Sub New()
      Init(1, 1)
  End Sub


  Protected Overrides Sub Finalize()
    Lib_Fmpz_Mat_Clear(FmpzMatPtr)
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
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As fmpz_t
    Get
      Dim m1 As New fmpz_t
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As fmpz_t)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As fmpz_t
    Get
      Dim m1 As New fmpz_t
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As fmpz_t)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As fmpz_t
    Get
      Dim m1 As New fmpz_t
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As fmpz_t)
      '      x1.Col(j) = m1.x1
    End Set

  End Property








  Public Shared Widening Operator CType(ByVal m1 As fmpz_mat_t) As String
      '    Return m1.x1.Str
      Return "1"
  End Operator


  'Public Shared Narrowing Operator CType(ByVal s As String) As fmpz_mat_t
  Public Shared Widening Operator CType(ByVal s As String) As fmpz_mat_t
    Dim m1 As New fmpz_mat_t
'    m1.x1 = m1.x1.Real(s)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As fmpz_mat_t) As Decimal
'    Return CDec(m1.x1.Str)
    Return CDec("1")
  End Operator

  Public Shared Narrowing Operator CType(ByVal dec As Decimal) As fmpz_mat_t
    Dim m1 As New fmpz_mat_t
'    m1.x1 = m1.x1.Real(CStr(dec))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As fmpz_mat_t) As Double
      '    Return m1.x1.Dbl
      Return 1.0
  End Operator

  'Public Shared Narrowing Operator CType(ByVal d As Double) As fmpz_mat_t
  Public Shared Widening Operator CType(ByVal d As Double) As fmpz_mat_t
    Dim m1 As New fmpz_mat_t
'    m1.x1 = m1.x1.Real(d)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As fmpz_mat_t) As Long
'    Return m1.x1.Lng
    Return 1
    
  End Operator

  Public Shared Narrowing Operator CType(ByVal si As Long) As fmpz_mat_t
    Dim m1 As New fmpz_mat_t
'    m1.x1 = m1.x1.Real(CStr(si))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As fmpz_mat_t) As ULong
'    Return CULng(m1.x1.Lng)
    Return 1
  End Operator

  Public Shared Narrowing Operator CType(ByVal ui As ULong) As fmpz_mat_t
    Dim m1 As New fmpz_mat_t
'    m1.x1 = m1.x1.Real(CStr(ui))
    Return m1
  End Operator


  Public Shared Operator =(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'      Return CBool(m1.x1.EQ(m2.x1))
      Return True
  End Operator


  Public Shared Operator <>(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'    Return CBool(m1.x1.NE(m2.x1))
      Return True
  End Operator



  Public Shared Operator <=(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'    Return CBool(m1.x1.LE(m2.x1))
      Return True
  End Operator



  Public Shared Operator <(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'    Return CBool(m1.x1.LT(m2.x1))
      Return True
  End Operator


  Public Shared Operator >=(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'    Return CBool(m1.x1.GE(m2.x1))
      Return True
  End Operator


  Public Shared Operator >(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As Boolean
'    Return CBool(m1.x1.GT(m2.x1))
      Return True
  End Operator


  Public Shared Operator +(ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
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
  Public Shared Operator +(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Plus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator +(ByVal m1 As fmpz_mat_t, ByVal si As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
    'MsgBox("Plus_si")
'    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Integer, ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
    'MsgBox("Plus_si")
'    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator

  Public Shared Operator -(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Minus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As fmpz_mat_t, ByVal i As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Minus_i(i)
    Return m3
  End Operator


  Public Shared Operator -(ByVal i As Integer, ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
    'm3.x1 = m1.x1.Minus_i(i)
'    m3.x1 = m1.x1.Minus_i_Neg(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    If (m1.MultMode = 1) Then
'      m3.x1 = m1.x1.TimesMat(m2.x1)
'    Else
'      m3.x1 = m1.x1.Times(m2.x1)
'    End If
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As fmpz_mat_t, ByVal i As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal i As Integer, ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Div(m2.x1)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As fmpz_mat_t, ByVal i As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Div_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal i As Integer, ByVal m1 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Div_i_Inv(i)
    Return m3
  End Operator


  Public Shared Operator &(ByVal m1 As fmpz_mat_t, ByVal s As String) As String
'      Return m1.Str & s
      Return "1"
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As fmpz_mat_t) As String
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

  Public Shared Operator ^(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Pow(m2.x1)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As fmpz_mat_t, ByVal n As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Pow_i(n)
    Return m3
  End Operator


  Public Shared Operator Mod(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.Mod(m2.x1)
    Return m3
  End Operator


  Public Shared Operator \(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.IntDiv(m2.x1)
    Return m3
  End Operator


  Public Shared Operator <<(ByVal m1 As fmpz_mat_t, ByVal i As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.RSH(i)
    Return m3
  End Operator


  Public Shared Operator >>(ByVal m1 As fmpz_mat_t, ByVal i As Integer) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.LSH(i)
    Return m3
  End Operator


  Public Shared Operator IsTrue(ByVal m1 As fmpz_mat_t) As Boolean
'      Return m1.x1.Is_Zero = 0
      Return True
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As fmpz_mat_t) As Boolean
'    Return m1.x1.Is_Zero <> 0
      Return True
  End Operator


  Public Shared Operator Not(ByVal m1 As fmpz_mat_t) As Boolean
'    If m1.x1.Is_Zero <> 0 Then
'      Return False
'    Else
'      Return True
'    End If
      Return True
    
  End Operator


  Public Shared Operator And(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.AND(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Or(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.OR(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Xor(ByVal m1 As fmpz_mat_t, ByVal m2 As fmpz_mat_t) As fmpz_mat_t
    Dim m3 As New fmpz_mat_t()
'    m3.x1 = m1.x1.XOR(m2.x1)
    Return m3
  End Operator


  Public Overrides Function ToString() As String
      '    Return x1.Str
      Return "1"
  End Function


End Class





Public Module fmpz_mat
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Init(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Clear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Print_Pretty(ByVal A As IntPtr)
  End Sub
  
  Public  Sub MatPrint(ByVal X As fmpz_mat_t)
      Lib_Fmpz_Mat_Print_Pretty(X.FmpzMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr)
  End Sub
  
  Public  Sub MatMul(ByVal X As fmpz_mat_t, ByVal Y As fmpz_mat_t, ByVal Z As fmpz_mat_t)
      Lib_Fmpz_Mat_Mul(X.FmpzMatPtr, Y.FmpzMatPtr, Z.FmpzMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpz_Mat_Set_Ui", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpz_Mat_Set_Ui(ByVal FmpzPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
  End Sub

  Public  Sub MatSetUi(ByVal X As fmpz_mat_t, ByVal i As Int32, ByVal j As Int32, ByVal u As Int32)
      Lib_Fmpz_Mat_Set_Ui(X.FmpzMatPtr, i, j, u)
  End Sub



End Module


