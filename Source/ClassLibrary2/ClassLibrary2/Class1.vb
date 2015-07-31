Imports System
Imports System.Console
Imports Microsoft.VisualBasic
Imports Microsoft.VisualBasic.Strings
Imports mpNumericsLib


Public Class mpNum

  Friend x1 As New mp_Real

  Friend NumPtr As IntPtr
  'Shared x1 As New mp_Real
  Private MultMode As Integer = 0

  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  ''' <remarks></remarks>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
    x1.ReDim(m, n)
  End Sub

  ''' <summary>
  ''' 
  ''' </summary>
  ''' <param name="n"></param>
  ''' <remarks></remarks>
  Public Sub New(ByVal n As Integer)
    x1.ReDim(1, n)
  End Sub


  Public Sub New()
    x1.ReDim(1, 1)
  End Sub


  Protected Overrides Sub Finalize()
    'WriteLine("Release mpNum.x1")
    x1 = Nothing
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <value></value>
  ''' <returns>The number of rows in the matrix</returns>
  ''' <remarks></remarks>
  Public ReadOnly Property Rows() As Integer
    Get
      Return x1.Rows
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <value></value>
  ''' <returns>The number of columns in the matrix</returns>
  ''' <remarks></remarks>
  Public ReadOnly Property Cols() As Integer
    Get
      Return x1.Cols
    End Get
  End Property

  Public ReadOnly Property Size() As Integer
    Get
      Return x1.Size
    End Get
  End Property


  Public Function Str() As String
    Return x1.Str
  End Function


  ''' <summary>
  ''' 
  ''' </summary>
  ''' <value></value>
  ''' <returns></returns>
  ''' <remarks></remarks>
  Public Property Prec10() As Integer
    Get
      Return x1.Prec10
    End Get

    Set(ByVal Value As Integer)
      x1.Prec10 = Value
    End Set
  End Property


  Public Property Prec2() As Integer
    Get
      Return x1.Prec2
    End Get

    Set(ByVal Value As Integer)
      x1.Prec2 = Value
    End Set
  End Property

  ''' <summary>
  ''' 
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  ''' <value></value>
  ''' <returns></returns>
  ''' <remarks></remarks>
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' 
  ''' </summary>
  ''' <param name="i"></param>
  ''' <value></value>
  ''' <returns></returns>
  ''' <remarks></remarks>
  Public Property Row(ByVal i As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.Row(i)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.Col(j) = m1.x1
    End Set

  End Property


  Public Property Block(ByVal i As Integer, ByVal j As Integer, ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.Block(i, j, p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.Block(i, j, p, q) = m1.x1
    End Set

  End Property


  Public Property TopLeftCorner(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.TopLeftCorner(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.TopLeftCorner(p, q) = m1.x1
    End Set

  End Property


  Public Property BottomLeftCorner(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.BottomLeftCorner(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.BottomLeftCorner(p, q) = m1.x1
    End Set

  End Property


  Public Property TopRightCorner(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.TopRightCorner(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.TopRightCorner(p, q) = m1.x1
    End Set

  End Property


  Public Property BottomRightCorner(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.BottomRightCorner(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.BottomRightCorner(p, q) = m1.x1
    End Set

  End Property


  Public Property MiddleRows(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.MiddleRows(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.MiddleRows(p, q) = m1.x1
    End Set

  End Property


  Public Property MiddleCols(ByVal p As Integer, ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.MiddleCols(p, q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.MiddleCols(p, q) = m1.x1
    End Set

  End Property



  Public Property TopRows(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.TopRows(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.TopRows(q) = m1.x1
    End Set

  End Property


  Public Property BottomRows(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.BottomRows(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.BottomRows(q) = m1.x1
    End Set

  End Property


  Public Property LeftCols(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.LeftCols(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.LeftCols(q) = m1.x1
    End Set

  End Property


  Public Property RightCols(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.RightCols(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.RightCols(q) = m1.x1
    End Set

  End Property



  Public Property Diagonal(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.Diagonal(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.Diagonal(q) = m1.x1
    End Set

  End Property


  Public Property TriangularView(ByVal q As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      m1.x1 = x1.TriangularView(q)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      x1.TriangularView(q) = m1.x1
    End Set

  End Property


  Public Shared Widening Operator CType(ByVal m1 As mpNum) As String
    Return m1.x1.Str
  End Operator


  'Public Shared Narrowing Operator CType(ByVal s As String) As mpNum
  Public Shared Widening Operator CType(ByVal s As String) As mpNum
    Dim m1 As New mpNum
    m1.x1 = m1.x1.Real(s)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpNum) As Decimal
    Return CDec(m1.x1.Str)
  End Operator

  Public Shared Narrowing Operator CType(ByVal dec As Decimal) As mpNum
    Dim m1 As New mpNum
    m1.x1 = m1.x1.Real(CStr(dec))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpNum) As Double
    Return m1.x1.Dbl
  End Operator

  'Public Shared Narrowing Operator CType(ByVal d As Double) As mpNum
  Public Shared Widening Operator CType(ByVal d As Double) As mpNum
    Dim m1 As New mpNum
    m1.x1 = m1.x1.Real(d)
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpNum) As Long
    Return m1.x1.Lng
  End Operator

  Public Shared Narrowing Operator CType(ByVal si As Long) As mpNum
    Dim m1 As New mpNum
    m1.x1 = m1.x1.Real(CStr(si))
    Return m1
  End Operator


  Public Shared Widening Operator CType(ByVal m1 As mpNum) As ULong
    Return CULng(m1.x1.Lng)
  End Operator

  Public Shared Narrowing Operator CType(ByVal ui As ULong) As mpNum
    Dim m1 As New mpNum
    m1.x1 = m1.x1.Real(CStr(ui))
    Return m1
  End Operator


  Public Shared Operator =(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.EQ(m2.x1))
  End Operator


  Public Shared Operator <>(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.NE(m2.x1))
  End Operator



  Public Shared Operator <=(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.LE(m2.x1))
  End Operator



  Public Shared Operator <(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.LT(m2.x1))
  End Operator


  Public Shared Operator >=(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.GE(m2.x1))
  End Operator


  Public Shared Operator >(ByVal m1 As mpNum, ByVal m2 As mpNum) As Boolean
    Return CBool(m1.x1.GT(m2.x1))
  End Operator


  Public Shared Operator +(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Times_i(-1)
    Return m3
  End Operator


  Public Function m() As mpNum
    Dim m3 As New mpNum()
    m3.x1 = x1
    m3.MultMode = 1
    Return m3
  End Function

  ''' <summary>
  ''' Adds two matrices together and returns a third matrix with the sum.  The matrices need to have the
  ''' same dimensions.
  ''' </summary>
  ''' <param name="m1">First matrix</param>
  ''' <param name="m2">Second matrix</param>
  ''' <returns>A new matrix with the sum of the first two</returns>
  ''' <remarks></remarks>
  Public Shared Operator +(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Plus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator +(ByVal m1 As mpNum, ByVal si As Integer) As mpNum
    Dim m3 As New mpNum()
    'MsgBox("Plus_si")
    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator


  Public Shared Operator +(ByVal si As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    'MsgBox("Plus_si")
    m3.x1 = m1.x1.Plus_i(si)
    Return m3
  End Operator

  Public Shared Operator -(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Minus(m2.x1)
    Return m3
  End Operator


  Public Shared Operator -(ByVal m1 As mpNum, ByVal i As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Minus_i(i)
    Return m3
  End Operator


  Public Shared Operator -(ByVal i As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    'm3.x1 = m1.x1.Minus_i(i)
    m3.x1 = m1.x1.Minus_i_Neg(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum(1, 1)
    If (m1.MultMode = 1) Then
      m3.x1 = m1.x1.TimesMat(m2.x1)
    Else
      m3.x1 = m1.x1.Times(m2.x1)
    End If
    Return m3
  End Operator

  Public Shared Operator *(ByVal m1 As mpNum, ByVal i As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator

  Public Shared Operator *(ByVal i As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Times_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Div(m2.x1)
    Return m3
  End Operator


  Public Shared Operator /(ByVal m1 As mpNum, ByVal i As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Div_i(i)
    Return m3
  End Operator


  Public Shared Operator /(ByVal i As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Div_i_Inv(i)
    Return m3
  End Operator


  Public Shared Operator &(ByVal m1 As mpNum, ByVal s As String) As String
    Return m1.Str & s
  End Operator


  Public Shared Operator &(ByVal s As String, ByVal m1 As mpNum) As String
    Return s & m1.Str
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

  Public Shared Operator ^(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Pow(m2.x1)
    Return m3
  End Operator


  Public Shared Operator ^(ByVal m1 As mpNum, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Pow_i(n)
    Return m3
  End Operator


  Public Shared Operator Mod(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.Mod(m2.x1)
    Return m3
  End Operator


  Public Shared Operator \(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.IntDiv(m2.x1)
    Return m3
  End Operator


  Public Shared Operator <<(ByVal m1 As mpNum, ByVal i As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.RSH(i)
    Return m3
  End Operator


  Public Shared Operator >>(ByVal m1 As mpNum, ByVal i As Integer) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.LSH(i)
    Return m3
  End Operator


  Public Shared Operator IsTrue(ByVal m1 As mpNum) As Boolean
    Return m1.x1.Is_Zero = 0
  End Operator


  Public Shared Operator IsFalse(ByVal m1 As mpNum) As Boolean
    Return m1.x1.Is_Zero <> 0
  End Operator


  Public Shared Operator Not(ByVal m1 As mpNum) As Boolean
    If m1.x1.Is_Zero <> 0 Then
      Return False
    Else
      Return True
    End If
  End Operator


  Public Shared Operator And(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.AND(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Or(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.OR(m2.x1)
    Return m3
  End Operator


  Public Shared Operator Xor(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum()
    m3.x1 = m1.x1.XOR(m2.x1)
    Return m3
  End Operator


  Public Overrides Function ToString() As String
    Return x1.Str
  End Function


  ''' <summary>
  ''' Returns the decription of a matrix
  ''' </summary>
  ''' <remarks></remarks>
  Public Function Description() As String
    Dim s As String = "RealMatrix (" & CStr(Rows) & ", " & CStr(Cols) & ") , Double Precision"
    Return s
  End Function



  ''' <summary>
  ''' Retruns a text representation of the table of a matrix
  ''' </summary>
  ''' <remarks></remarks>
  Public Function Table() As String
    Dim s As String = ""
    s = "Table:" & CStr(Cols) & "@"
    For i As Integer = 1 To Rows
      For j As Integer = 1 To Cols
        's = s & Format(x1(i, j), "E")
        s = s & x1(i, j).Str
        If j <= Cols Then s = s & "#"
      Next
      If i <= Rows Then s = s & "@"
    Next
    Return s
  End Function



  Public Sub Print(Name As String)
    Dim n, m, i, j As Integer
    n = x1.Rows
    m = x1.Cols
    WriteLine("Listing of Matrix " & Name & ",  " & n & " rows x " & m & " columns")
    For i = 1 To n
      WriteLine("Listing Row " & i)
      For j = 1 To m
        WriteLine("x(" & i & ", " & j & "): " & x1(i, j).Str())
      Next
      WriteLine("EndListing Row " & i)
    Next
    WriteLine("EndListing Matrix " & Name)
    WriteLine("")
  End Sub


End Class



Public Class mp

    Private Declare Function mp_hypot22 Lib "mpNumerics.dll" (ByVal x As Double, ByVal y As Double) As Double

    Private Declare Function LoadLibrary Lib "KERNEL32.dll" Alias "LoadLibraryA" (ByVal lpFile As String) As IntPtr

    Public Shared mpLib As New mp_Lib

  Shared Sub New()
    Dim Result As Double = HasLibrary()
    WriteLine("New mpLib 32: ", Result.ToString())
    mpLib.Prec10 = 40
    'mpLib.FloatingPointType = mpFloatingPointEnum.mpBinary
  End Sub

  Protected Overrides Sub Finalize()
    WriteLine("Release mpLib")
    mpLib = Nothing
    MyBase.Finalize()
  End Sub



  Private Shared Function HasLibrary() As Double
    Static Result As Double = 0
    If Result = 0 Then
      Dim DLLPath As String = CStr(My.Computer.Registry.GetValue("HKEY_LOCAL_MACHINE\SOFTWARE\THF", "DLLPath", Nothing))
      Dim FName As String = DLLPath & "\LIB\mpNumerics.dll"
      MsgBox(FName)
      ' MsgBox(DLLPath)
      Result = CDbl(LoadLibrary(FName))
    End If
    If Result = 0 Then
      MsgBox("Could not load supporting library mpNumerics!")
      Return False
    Else
      Return True
    End If
  End Function

    ''' <summary>
    ''' Returns the Hypotenuse of x and y
    ''' </summary>
    ''' <returns>Sqrt(x^2 + y^2).</returns>
    ''' <remarks></remarks>
    ''' 
    Public Shared Function Hypot(x As Double, y As Double) As Double
    If HasLibrary() <> 0 Then Return mp_hypot22(x, y) Else Return 0
    End Function


    Public Shared Property Prec10() As Integer
        Get
            Return mpLib.Prec10
        End Get

        Set(ByVal Value As Integer)
            mpLib.Prec10 = Value
        End Set
    End Property


    Public Shared Property Prec2() As Integer
        Get
            Return mpLib.Prec2
        End Get

        Set(ByVal Value As Integer)
            mpLib.Prec2 = Value
        End Set
    End Property


  Public Shared Property FloatingPointType() As Integer
    Get
      Return mpLib.FloatingPointType
    End Get

    Set(ByVal Value As Integer)
      mpLib.FloatingPointType = Value
    End Set
  End Property


    Public Shared Property Emin() As Integer
        Get
            Return mpLib.Emin
        End Get

        Set(ByVal Value As Integer)
            mpLib.Emin = Value
        End Set
    End Property


    Public Shared Property Emax() As Integer
        Get
            Return mpLib.Emax
        End Get

        Set(ByVal Value As Integer)
            mpLib.Emax = Value
        End Set
    End Property


    Public Shared ReadOnly Property EminMin() As Integer
        Get
            Return mpLib.EminMin
        End Get
    End Property


    Public Shared ReadOnly Property EminMax() As Integer
        Get
            Return mpLib.EminMax
        End Get
    End Property


    Public Shared ReadOnly Property EmaxMin() As Integer
        Get
            Return mpLib.EmaxMin
        End Get
    End Property


    Public Shared ReadOnly Property EmaxMax() As Integer
        Get
            Return mpLib.EmaxMax
        End Get
    End Property


    Public Shared Property DefaultRoundingMode() As Integer
        Get
            Return mpLib.DefaultRoundingMode
        End Get

        Set(ByVal Value As Integer)
            mpLib.DefaultRoundingMode = Value
        End Set
    End Property


    Public Shared Property UnderflowFlag() As Boolean
        Get
            Return mpLib.UnderflowFlag
        End Get

        Set(ByVal Value As Boolean)
            mpLib.UnderflowFlag = Value
        End Set
    End Property


    Public Shared Property OverflowFlag() As Boolean
        Get
            Return mpLib.OverflowFlag
        End Get

        Set(ByVal Value As Boolean)
            mpLib.OverflowFlag = Value
        End Set
    End Property


    Public Shared Property NanFlag() As Boolean
        Get
            Return mpLib.NanFlag
        End Get

        Set(ByVal Value As Boolean)
            mpLib.NanFlag = Value
        End Set
    End Property


    Public Shared Property InexactFlag() As Boolean
        Get
            Return mpLib.InexactFlag
        End Get

        Set(ByVal Value As Boolean)
            mpLib.InexactFlag = Value
        End Set
    End Property


    Public Shared Property ErangeFlag() As Boolean
        Get
            Return mpLib.ErangeFlag
        End Get

        Set(ByVal Value As Boolean)
            mpLib.ErangeFlag = Value
        End Set
    End Property



    Public Shared Sub ClearFlags()
        mpLib.ClearFlags()
    End Sub



  Public Shared Function CNum(ByVal x As Object) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Real(x)
    Return m3
  End Function



  Public Shared Function intBinCoeff(ByVal m1 As mpNum, ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intBinCoeff(m1.x1, n.x1)
    Return m3
  End Function


  Public Shared Function intFactorial(ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFactorial(n.x1)
    Return m3
  End Function


  Public Shared Function intFibonacci(ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFibonacci(n.x1)
    Return m3
  End Function


  Public Shared Function intFibonacci2(ByVal n As mpNum, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFibonacci2(n.x1, m1.x1)
    Return m3
  End Function


  Public Shared Function intGcd(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intGcd(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intGcdExt(ByVal v1 As mpNum, ByVal v2 As mpNum, ByVal b As mpNum, ByVal c As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intGcdExt(v1.x1, v2.x1, b.x1, c.x1)
    Return m3
  End Function


  Public Shared Function intInvertMod(ByVal v1 As mpNum, ByVal v2 As mpNum, ByVal b As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intInvertMod(v1.x1, v2.x1, b.x1)
    Return m3
  End Function



  Public Shared Function intJacobi(ByVal v1 As mpNum, ByVal v2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intJacobi(v1.x1, v2.x1)
    Return m3
  End Function


  Public Shared Function intKronecker(ByVal v1 As mpNum, ByVal v2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intKronecker(v1.x1, v2.x1)
    Return m3
  End Function


  Public Shared Function intLegendre(ByVal v1 As mpNum, ByVal v2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intLegendre(v1.x1, v2.x1)
    Return m3
  End Function



  Public Shared Function intLcm(ByVal v1 As mpNum, ByVal v2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intLcm(v1.x1, v2.x1)
    Return m3
  End Function



  Public Shared Function intLucas(ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intLucas(n.x1)
    Return m3
  End Function


  Public Shared Function intLucas2(ByVal n As mpNum, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intLucas2(n.x1, m1.x1)
    Return m3
  End Function



  Public Shared Function intNextprime(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intNextprime(m1.x1)
    Return m3
  End Function



  Public Shared Function intPow(ByVal m1 As mpNum, ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intPow(m1.x1, n.x1)
    Return m3
  End Function


  Public Shared Function intPowMod(ByVal x1 As mpNum, ByVal x2 As mpNum, ByVal x3 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intPowMod(x1.x1, x2.x1, x3.x1)
    Return m3
  End Function


  Public Shared Function intRemoveFactor(ByVal x1 As mpNum, ByVal x2 As mpNum, ByVal x3 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intRemoveFactor(x1.x1, x2.x1, x3.x1)
    Return m3
  End Function



  Public Shared Function intRoot(ByVal m1 As mpNum, ByVal n As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intRoot(m1.x1, n.x1)
    Return m3
  End Function


  Public Shared Function intRootRem(ByVal m1 As mpNum, ByVal n As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intRootRem(m1.x1, n.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intRrandomb(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intRrandomb(m1.x1)
    Return m3
  End Function


  Public Shared Function intSqrt(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intSqrt(m1.x1)
    Return m3
  End Function


  Public Shared Function intSqrtRem(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intSqrtRem(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intUrandomb(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intUrandomb(m1.x1)
    Return m3
  End Function


  Public Shared Function intUrandomm(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intUrandomm(m1.x1)
    Return m3
  End Function



  Public Shared Function intAbs(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intAbs(m1.x1)
    Return m3
  End Function



  Public Shared Function intAND(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intAND(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function intTestBit(ByVal m1 As mpNum, ByVal i As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intTestBit(m1.x1, i.x1)
    Return m3
  End Function


  Public Shared Sub intComBit(ByVal m1 As mpNum, ByVal i As mpNum)
    'Dim m3 As New mpNum
    mpLib.intComBit(m1.x1, i.x1)
    'Return m3
  End Sub



  Public Shared Function intComplement(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intComplement(m1.x1)
    Return m3
  End Function



  Public Shared Function intHamDist(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intHamDist(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function intIOR(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intIOR(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intLSH(ByVal m1 As mpNum, ByVal i As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intLSH(m1.x1, i.x1)
    Return m3
  End Function


  Public Shared Function intNeg(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intNeg(m1.x1)
    Return m3
  End Function


  Public Shared Function intPopCount(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intPopCount(m1.x1)
    Return m3
  End Function



  Public Shared Function intRSH(ByVal m1 As mpNum, ByVal i As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intRSH(m1.x1, i.x1)
    Return m3
  End Function


  Public Shared Function intScan0(ByVal m1 As mpNum, ByVal i As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intScan0(m1.x1, i.x1)
    Return m3
  End Function


  Public Shared Function intScan1(ByVal m1 As mpNum, ByVal i As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intScan1(m1.x1, i.x1)
    Return m3
  End Function


  Public Shared Function intSgn(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intSgn(m1.x1)
    Return m3
  End Function


  Public Shared Function intXOR(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intXOR(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intMod(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intMod(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intCDiv_q(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intCDiv_q(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intCDiv_r(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intCDiv_r(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function intCDiv_qr(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m3.x1 = mpLib.intCDiv_qr(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function


  Public Shared Function intCDiv_q_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intCDiv_q_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intCDiv_r_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intCDiv_r_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intFDiv_q(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFDiv_q(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intFDiv_r(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFDiv_r(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function intFDiv_qr(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m3.x1 = mpLib.intFDiv_qr(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function


  Public Shared Function intFDiv_q_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFDiv_q_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intFDiv_r_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intFDiv_r_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intTDiv_q(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intTDiv_q(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intTDiv_r(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intTDiv_r(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function intTDiv_qr(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m3.x1 = mpLib.intTDiv_qr(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function


  Public Shared Function intTDiv_q_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intTDiv_q_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function intTDiv_r_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.intTDiv_r_2exp(m1.x1, m2.x1)
    Return m3
  End Function


  'Summary Functions

  Public Shared Function Sum(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Sum(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function Prod(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Prod(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function Mean(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Mean(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function MinCoeff(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MinCoeff(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function MaxCoeff(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MaxCoeff(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function SquaredNorm(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.SquaredNorm(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function Norm(ByVal m1 As mpNum, ByVal mode As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Norm(m1.x1, mode)
    Return m3
  End Function


  Public Shared Function MinCoeffIndex(ByRef i As Integer, ByRef j As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MinCoeffIndex(i, j, m1.x1)
    Return m3
  End Function


  Public Shared Function MaxCoeffIndex(ByRef i As Integer, ByRef j As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MaxCoeffIndex(i, j, m1.x1)
    Return m3
  End Function



  'Re-shaping Functions


  Public Shared Function Transpose(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Transpose(m1.x1)
    Return m3
  End Function


  Public Shared Function Conjugate(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Conjugate(m1.x1)
    Return m3
  End Function


  Public Shared Function Adjoint(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Adjoint(m1.x1)
    Return m3
  End Function


  Public Shared Function AsDiagonal(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.AsDiagonal(m1.x1)
    Return m3
  End Function


  Public Shared Function Reverse(ByVal PartialMode As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Reverse(PartialMode, m1.x1)
    Return m3
  End Function


  Public Shared Function Replicate(ByVal Vertical As Integer, ByVal Horizontal As Integer, ByVal PartialMode As Integer, ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Replicate(Vertical, Horizontal, PartialMode, m1.x1)
    Return m3
  End Function


  Public Shared Function ReSizeLike(ByVal m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.ReSizeLike(m1.x1)
    Return m3
  End Function


  'Inplace Functions


  Public Shared Sub ReSize(i As Integer, j As Integer, ByVal m1 As mpNum)
    mpLib.ReSize(i, j, m1.x1)
  End Sub


  Public Shared Sub ReSizePreserve(i As Integer, j As Integer, ByVal m1 As mpNum)
    mpLib.ReSizePreserve(i, j, m1.x1)
  End Sub


  'Public Shared Sub FillLinear(i As Integer, j As Integer, ByVal m1 As mpNum)
  '  mpLib.FillLinear(i, j, m1.x1)
  'End Sub



  Public Shared Sub TransposeInplace(ByVal m1 As mpNum)
    mpLib.TransposeInplace(m1.x1)
  End Sub


  Public Shared Sub ReverseInplace(ByVal m1 As mpNum)
    mpLib.ReverseInplace(m1.x1)
  End Sub



    'Add the following functions to mpLib:
    'IsDivisible, IsCongruent, IsPerfectPower, IsPerfectSquare, IsProbComposite, IsOdd, IsEven
    'IsInf, IsNan, IsNumber, IsZero, IsRegular, IsInteger
    'IsPos, IsStrictlyPos, IsNonNeg, IsNeg, IsStrictlyNeg, IsNonPos, HasZero, IsBounded, IsEmpty, IsInside, IsStrictlyInside
  ' IsUnordered
    'Fits_ULong, Fits_SLong, Fits_Uint, Fits_Sint, Fits_UShort, Fits_SHort


  Public Shared Function IsOdd(ByVal m1 As mpNum) As Long
    Return mpLib.IsOdd(m1.x1)
  End Function


  Public Shared Function IsEven(ByVal m1 As mpNum) As Long
    Return mpLib.IsEven(m1.x1)
  End Function


  Public Shared Function IsPerfectPower(ByVal m1 As mpNum) As Long
    Return mpLib.IsPerfectPower(m1.x1)
  End Function


  Public Shared Function IsPerfectSquare(ByVal m1 As mpNum) As Long
    Return mpLib.IsPerfectSquare(m1.x1)
  End Function


  Public Shared Function Fits_ULong(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_ULong(m1.x1)
  End Function


  Public Shared Function Fits_SLong(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_SLong(m1.x1)
  End Function


  Public Shared Function Fits_Uint(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_Uint(m1.x1)
  End Function


  Public Shared Function Fits_Sint(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_Sint(m1.x1)
  End Function



  Public Shared Function Fits_UShort(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_UShort(m1.x1)
  End Function


  Public Shared Function Fits_SHort(ByVal m1 As mpNum) As Long
    Return mpLib.Fits_SHort(m1.x1)
  End Function


  Public Shared Function IsDivisible(ByVal m1 As mpNum, ByVal m2 As mpNum) As Long
    Return mpLib.IsDivisible(m1.x1, m2.x1)
  End Function


  Public Shared Function IsDivisible_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum) As Long
    Return mpLib.IsDivisible_2exp(m1.x1, m2.x1)
  End Function


  Public Shared Function IsDefinitelyComposite(ByVal m1 As mpNum, ByVal tries As mpNum) As Long
    Return mpLib.IsDefinitelyComposite(m1.x1, tries.x1)
  End Function


  Public Shared Function IsDefinitelyPrime(ByVal m1 As mpNum, ByVal tries As mpNum) As Long
    Return mpLib.IsDefinitelyPrime(m1.x1, tries.x1)
  End Function


  Public Shared Function IsProbablyPrime(ByVal m1 As mpNum, ByVal tries As mpNum) As Long
    Return mpLib.IsProbablyPrime(m1.x1, tries.x1)
  End Function


  Public Shared Function IsCongruent(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As Long
    Return mpLib.IsCongruent(m1.x1, m2.x1, m3.x1)
  End Function


  Public Shared Function IsCongruent_2exp(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As Long
    Return mpLib.IsCongruent_2exp(m1.x1, m2.x1, m3.x1)
  End Function


  Public Shared Function IsInf(ByVal m1 As mpNum) As Long
    Return mpLib.IsInf_(m1.x1)
  End Function


  Public Shared Function IsNan(ByVal m1 As mpNum) As Long
    Return mpLib.IsNan(m1.x1)
  End Function



  Public Shared Function IsNumber(ByVal m1 As mpNum) As Long
    Return mpLib.IsNumber(m1.x1)
  End Function


  Public Shared Function IsZero(ByVal m1 As mpNum) As Long
    Return mpLib.IsZero(m1.x1)
  End Function


  Public Shared Function IsRegular(ByVal m1 As mpNum) As Long
    Return mpLib.IsRegular(m1.x1)
  End Function


  Public Shared Function IsInteger(ByVal m1 As mpNum) As Long
    Return mpLib.IsInteger(m1.x1)
  End Function




  Public Shared Function IsPos(ByVal m1 As mpNum) As Long
    Return mpLib.IsPos(m1.x1)
  End Function

  Public Shared Function IsStrictlyPos(ByVal m1 As mpNum) As Long
    Return mpLib.IsStrictlyPos(m1.x1)
  End Function

  Public Shared Function IsNonNeg(ByVal m1 As mpNum) As Long
    Return mpLib.IsNonNeg(m1.x1)
  End Function

  Public Shared Function IsNeg(ByVal m1 As mpNum) As Long
    Return mpLib.IsNeg(m1.x1)
  End Function

  Public Shared Function IsStrictlyNeg(ByVal m1 As mpNum) As Long
    Return mpLib.IsStrictlyNeg(m1.x1)
  End Function

  Public Shared Function IsNonPos(ByVal m1 As mpNum) As Long
    Return mpLib.IsNonPos(m1.x1)
  End Function

  Public Shared Function HasZero(ByVal m1 As mpNum) As Long
    Return mpLib.HasZero(m1.x1)
  End Function

  'Public Shared Function IsBounded(ByVal m1 As mpNum) As long
  '  Return mpLib.IsBounded(m1.x1)
  'End Function

  Public Shared Function IsEmpty(ByVal m1 As mpNum) As Long
    Return mpLib.IsEmpty(m1.x1)
  End Function


  Public Shared Function IsInside(ByVal m1 As mpNum, ByVal m2 As mpNum) As Long
    Return mpLib.IsInside(m1.x1, m2.x1)
  End Function


  Public Shared Function IsStrictlyInside(ByVal m1 As mpNum, ByVal m2 As mpNum) As Long
    Return mpLib.IsInside(m1.x1, m2.x1)
  End Function



  Public Shared Function IsUnordered(ByVal m1 As mpNum, ByVal m2 As mpNum) As Long
    Return mpLib.IsUnordered(m1.x1, m2.x1)
  End Function


  'cxsc functions

  Public Shared Function cxsc_abs(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_abs(m1.x1)
    Return m2
  End Function


  Public Shared Function cxsc_sqr(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqr(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_reci(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_reci(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_Sqrt(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_Sqrt(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrt_n(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrt_n(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrt_r(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrt_r(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_cbrt(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_cbrt(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrtp1m1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrtp1m1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrt1px2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrt1px2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrt1mx2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrt1mx2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sqrtx2m1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sqrtx2m1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_exp(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_exp(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_exp2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_exp2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_exp10(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_exp10(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_expm1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_expm1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_expx2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_expx2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_expx2m1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_expx2m1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_expmx2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_expmx2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_expmx2m1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_expmx2m1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_ln(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_ln(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_log2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_log2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_log10(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_log10(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_lnp1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_lnp1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_ln_sin(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_ln_sin(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_ln_cos(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_ln_cos(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sin(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sin(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_cos(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_cos(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_tan(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_tan(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_cot(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_cot(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_asin(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_asin(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_acos(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_acos(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_atan(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_atan(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_acot(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_acot(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sinh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sinh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_cosh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_cosh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_tanh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_tanh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_coth(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_coth(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_asinh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_asinh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_acosh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_acosh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_acoshp1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_acoshp1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_atanh(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_atanh(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_acoth(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_acoth(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_csc(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_csc(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sec(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sec(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_csch(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_csch(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_sech(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_sech(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_erf(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_erf(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_erfc(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_erfc(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_gamma(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_gamma(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_gamma_D(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_gamma_D(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_gamma_reci(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_gamma_reci(m1.x1)
    Return m2
  End Function


  Public Shared Function cxsc_digamma(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_digamma(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_lngamma(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_lngamma(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_factorial(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_factorial(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_zeta(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_zeta(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_Ei(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_Ei(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_Li2(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_Li2(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_J0(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_J0(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_J1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_J1(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_Y0(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_Y0(m1.x1)
    Return m2
  End Function

  Public Shared Function cxsc_Y1(ByVal m1 As mpNum) As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.cxsc_Y1(m1.x1)
    Return m2
  End Function




  Public Shared Function cxsc_x2py2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_x2py2(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function cxsc_x2my2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_x2my2(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_nth_root(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_nth_root(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_Hypot(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_Hypot(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_agm(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_agm(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_ln_sqrtx2y2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_ln_sqrtx2y2(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_power(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_power(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_pow(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_pow(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_atan2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_atan2(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_ln_sqrtxp1_2y2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_ln_sqrtxp1_2y2(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_lgamma(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_lgamma(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function cxsc_Jn(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_Jn(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function cxsc_Yn(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.cxsc_Yn(m1.x1, m2.x1)
    Return m3
  End Function





  ' Complex cxsc Functions

  Public Shared Sub cxsc_cplxNeg(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxNeg(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub


  Public Shared Sub cxsc_cplxConj(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxConj(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxReal(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxReal(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxImag(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxImag(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAbs(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAbs(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxArg(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxArg(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxSqr(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxSqr(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxSqrt(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxSqrt(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxExp(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxExp(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxExp2(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxExp2(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxExp10(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxExp10(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxLn(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxLn(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxLog2(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxLog2(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxLog10(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxLog10(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxSin(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxSin(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxCos(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxCos(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxTan(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxTan(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxCot(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxCot(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAsin(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAsin(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAcos(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAcos(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAtan(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAtan(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAcot(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAcot(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxSinh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxSinh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxCosh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxCosh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxTanh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxTanh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxCoth(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxCoth(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAsinh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAsinh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAcosh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAcosh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAtanh(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAtanh(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxAcoth(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAcoth(x1_re.x1, x1_im.x1, y1_re.x1, y1_im.x1)
  End Sub




  Public Shared Sub cxsc_cplxAdd(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxAdd(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub


  Public Shared Sub cxsc_cplxSub(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxSub(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxMul(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxMul(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxDiv(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxDiv(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxNth_root(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxNth_root(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxPower(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxPower(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxPow_r(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxPow_r(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub

  Public Shared Sub cxsc_cplxPow_c(ByVal x1_re As mpNum, ByVal x1_im As mpNum, ByVal x2_re As mpNum, ByVal x2_im As mpNum, ByVal y1_re As mpNum, ByVal y1_im As mpNum)
    mpLib.cxsc_cplxPow_c(x1_re.x1, x1_im.x1, x2_re.x1, x2_im.x1, y1_re.x1, y1_im.x1)
  End Sub





  ' Real Constants

  Public Shared Function const_Ln2() As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.const_Ln2()
    Return m2
  End Function


  Public Shared Function const_Pi() As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.const_Pi()
    Return m2
  End Function



  Public Shared Function const_Euler() As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.const_Euler()
    Return m2
  End Function


  Public Shared Function const_Catalan() As mpNum
    Dim m2 As New mpNum
    m2.x1 = mpLib.const_Catalan()
    Return m2
  End Function


  ' Real Functions

    Public Shared Function Sign(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sign(m1.x1)
        Return m2
    End Function


    Public Shared Function Neg(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Neg(m1.x1)
        Return m2
    End Function



    Public Shared Function Inv(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Inv(m1.x1)
        Return m2
    End Function



    Public Shared Function Abs(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Abs(m1.x1)
        Return m2
    End Function


    Public Shared Function Abs2(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Abs2(m1.x1)
        Return m2
    End Function



    Public Shared Function Sqrt(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sqrt(m1.x1)
        Return m2
    End Function

    Public Shared Function Exp(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Exp(m1.x1)
        Return m2
    End Function

    Public Shared Function Exp2(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Exp2(m1.x1)
        Return m2
    End Function

    Public Shared Function Exp10(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Exp10(m1.x1)
        Return m2
    End Function

    Public Shared Function Log(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Log(m1.x1)
        Return m2
    End Function

    Public Shared Function Log2(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Log2(m1.x1)
        Return m2
    End Function

    Public Shared Function Log10(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Log10(m1.x1)
        Return m2
    End Function

    Public Shared Function Sin(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sin(m1.x1)
        Return m2
    End Function


    Public Shared Function Cos(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Cos(m1.x1)
        Return m2
    End Function

    Public Shared Function Tan(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Tan(m1.x1)
        Return m2
    End Function

    Public Shared Function Sinh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sinh(m1.x1)
        Return m2
    End Function


    Public Shared Function Cosh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Cosh(m1.x1)
        Return m2
    End Function

    Public Shared Function Tanh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Tanh(m1.x1)
        Return m2
    End Function

    Public Shared Function Asin(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Asin(m1.x1)
        Return m2
    End Function

    Public Shared Function Acos(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Acos(m1.x1)
        Return m2
    End Function

    Public Shared Function Atan(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Atan(m1.x1)
        Return m2
    End Function

    Public Shared Function Asinh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Asinh(m1.x1)
        Return m2
    End Function

    Public Shared Function Acosh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Acosh(m1.x1)
        Return m2
    End Function

    Public Shared Function Atanh(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Atanh(m1.x1)
        Return m2
    End Function




    Public Shared Function Ceil(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Ceil(m1.x1)
        Return m2
    End Function

    Public Shared Function Floor(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Floor(m1.x1)
        Return m2
    End Function


    Public Shared Function Trunc(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Trunc(m1.x1)
        Return m2
    End Function

    Public Shared Function Round(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Round(m1.x1)
        Return m2
    End Function

    Public Shared Function Log1p(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Log1p(m1.x1)
        Return m2
    End Function

    Public Shared Function Expm1(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Expm1(m1.x1)
        Return m2
    End Function

    Public Shared Function Cbrt(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Cbrt(m1.x1)
        Return m2
    End Function

    Public Shared Function Sqrt1pm1(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sqrt1pm1(m1.x1)
        Return m2
    End Function

    Public Shared Function Sinc_pi(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sinc_pi(m1.x1)
        Return m2
    End Function

    Public Shared Function Sinhc_pi(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Sinhc_pi(m1.x1)
        Return m2
    End Function

    Public Shared Function Erf(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Erf(m1.x1)
        Return m2
    End Function

    Public Shared Function Erf_inv(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Erf_inv(m1.x1)
        Return m2
    End Function

    Public Shared Function Erfc(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Erfc(m1.x1)
        Return m2
    End Function

    Public Shared Function Erfc_inv(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Erfc_inv(m1.x1)
        Return m2
    End Function

    Public Shared Function Tgamma(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Tgamma(m1.x1)
        Return m2
    End Function

    Public Shared Function Lgamma(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Lgamma(m1.x1)
        Return m2
    End Function

    Public Shared Function Tgamma1pm1(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Tgamma1pm1(m1.x1)
        Return m2
    End Function

    Public Shared Function Digamma(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Digamma(m1.x1)
        Return m2
    End Function

    Public Shared Function Factorial(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Factorial(m1.x1)
        Return m2
    End Function

    Public Shared Function Unchecked_Factorial(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Unchecked_Factorial(m1.x1)
        Return m2
    End Function

    Public Shared Function Double_Factorial(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Double_Factorial(m1.x1)
        Return m2
    End Function

    Public Shared Function ExpInt_ei(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.ExpInt_ei(m1.x1)
        Return m2
    End Function


    Public Shared Function Zeta(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.Zeta(m1.x1)
        Return m2
    End Function

    Public Shared Function EllInt_2_K(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.EllInt_2_K(m1.x1)
        Return m2
    End Function

    Public Shared Function EllInt_1_K(ByVal m1 As mpNum) As mpNum
        Dim m2 As New mpNum
        m2.x1 = mpLib.EllInt_1_K(m1.x1)
        Return m2
    End Function





  Public Shared Function Powm1(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Powm1(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Hypot(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Hypot(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Ldexp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Ldexp(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Frexp(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Frexp(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Modf(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Modf(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Pow(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Pow(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Fmod(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Fmod(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Atan2(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Atan2(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Copysign(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Copysign(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Max(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Max(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Min(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Min(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Tgamma_ratio(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Tgamma_ratio(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Tgamma_delta_ratio(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Tgamma_delta_ratio(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_p(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_p(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_q(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_q(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Tgamma_lower(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Tgamma_lower(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Tgamma_upper(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Tgamma_upper(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_p_inv(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_p_inv(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_q_inv(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_q_inv(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_p_inva(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_p_inva(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Gamma_q_inva(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_q_inva(m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function Gamma_p_derivative(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Gamma_p_derivative(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Legendre_q(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Legendre_q(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Laguerre(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Laguerre(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Hermite(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Hermite(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Rising_factorial(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Rising_factorial(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Falling_factorial(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Falling_factorial(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Binomial_coefficient(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Binomial_coefficient(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Beta(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Beta(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Expint_n(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Expint_n(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Ellint_3_K(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Ellint_3_K(m1.x1, m2.x1)
    Return m3
  End Function



  Public Shared Function Ellint_2_F(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Ellint_2_F(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Ellint_1_F(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Ellint_1_F(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Ellint_rc(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Ellint_rc(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Cyl_bessel_j(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Cyl_bessel_j(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Cyl_neumann(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Cyl_neumann(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Cyl_bessel_i(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Cyl_bessel_i(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Cyl_bessel_k(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Cyl_bessel_k(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Sph_bessel(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Sph_bessel(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Sph_neumann(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Sph_neumann(m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function Legendre_p(ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Legendre_p(m1.x1, m2.x1)
    Return m3
  End Function





    Public Shared Function IBeta(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
        Dim m4 As New mpNum
        m4.x1 = mpLib.IBeta(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBetac(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBetac(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBeta_non_normalized(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBeta_non_normalized(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBetac_non_normalized(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBetac_non_normalized(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBeta_inv(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBeta_inv(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBetac_inv(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBetac_inv(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBeta_inva(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBeta_inva(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBetac_inva(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBetac_inva(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBeta_invb(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBeta_invb(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBetac_invb(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBetac_invb(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function IBeta_derivative(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.IBeta_derivative(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function Legendre_p_m(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.Legendre_p_m(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function Laguerre_m(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.Laguerre_m(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function EllInt_rf(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.EllInt_rf(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function EllInt_rd(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.EllInt_rd(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function EllInt_3_F(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.EllInt_3_F(m1.x1, m2.x1, m3.x1)
    Return m4
  End Function




    Public Shared Function EllInt_RJ(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
        Dim m5 As New mpNum
        m5.x1 = mpLib.EllInt_RJ(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function Spherical_harmonic_r(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.Spherical_harmonic_r(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function Spherical_harmonic_i(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.Spherical_harmonic_i(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function Hermite_next(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.Hermite_next(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function Laguerre_next(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.Laguerre_next(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function Legendre_next(ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.Legendre_next(m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

















    Public Shared Function SolveCholesky(A As mpNum, b As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SolveSVD(A.x1, b.x1)
        Return m3
    End Function


    Public Shared Function SolveLU(A As mpNum, b As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SolveLU(A.x1, b.x1)
        Return m3
    End Function


    Public Shared Function SolveQR(A As mpNum, b As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SolveQR(A.x1, b.x1)
        Return m3
    End Function


    Public Shared Function SolveSVD(A As mpNum, b As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SolveSVD(A.x1, b.x1)
        Return m3
    End Function


    '	RelErr = Diff.Norm(1)


  Public Shared Function Norm(m1 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.Norm(m1.x1)
    Return m3
  End Function


    Public Shared Function InverseLU(m1 As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.InverseLU(m1.x1)
        Return m3
    End Function

    Public Shared Function InverseQR(m1 As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.InverseQR(m1.x1)
        Return m3
    End Function


    Public Shared Function DetLU(m1 As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.DetLU(m1.x1)
        Return m3
    End Function


    Public Shared Function RankLU(m1 As mpNum) As Integer
        Return mpLib.RankLU(m1.x1)
    End Function


    Public Shared Function JacobiSVD_Full(matA As mpNum, MatrixU As mpNum, MatrixV As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.JacobiSVD_Full(matA.x1, MatrixU.x1, MatrixV.x1)
        Return m3
    End Function



    Public Shared Function SelfAdjointEigenValues(A As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SelfAdjointEigenValues(A.x1)
        Return m3
    End Function


    Public Shared Function SelfAdjointEigenSystem(A As mpNum, v As mpNum) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.SelfAdjointEigenSystem(A.x1, v.x1)
        Return m3
    End Function



  Public Shared Function RandomFill(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.RandomFill(m, n)
    Return m3
  End Function


    Public Shared Function RandomFillSymmetric(ByVal n As Integer) As mpNum
        Dim m3 As New mpNum
        m3.x1 = mpLib.RandomFillSymmetric(n)
        Return m3
    End Function


  Public Shared Function MatrixOfZero(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfZero(m, n)
    Return m3
  End Function

  Public Shared Function MatrixOfOne(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfOne(m, n)
    Return m3
  End Function

  Public Shared Function MatrixOfIdentity(ByVal m As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfIdentity(m)
    Return m3
  End Function

  Public Shared Function MatrixOfNan(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfNan(m, n)
    Return m3
  End Function

  Public Shared Function MatrixOfInfinity(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfInfinity(m, n)
    Return m3
  End Function

  Public Shared Function MatrixOfMinusInfinity(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfMinusInfinity(m, n)
    Return m3
  End Function

  Public Shared Function MatrixOfMinusZero(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixOfMinusZero(m, n)
    Return m3
  End Function


  Public Shared Function MatrixFillLinear(ByVal m As Integer, ByVal n As Integer) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.MatrixFillLinear(m, n)
    Return m3
  End Function



  Public Shared Function BernoulliDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.BernoulliDist(Target, m1.x1, m2.x1)
    Return m3
  End Function


  Public Shared Function ChiSquareDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.ChiSquareDist(Target, m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function ExponentialDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.ExponentialDist(Target, m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function PoissonDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.PoissonDist(Target, m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function RaleighDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.RaleighDist(Target, m1.x1, m2.x1)
    Return m3
  End Function

  Public Shared Function StudentsTDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum) As mpNum
    Dim m3 As New mpNum
    m3.x1 = mpLib.StudentsTDist(Target, m1.x1, m2.x1)
    Return m3
  End Function




  Public Shared Function BetaDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.BetaDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function


  Public Shared Function BinomialDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.BinomialDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function CauchyDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.CauchyDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function ExtremeValueDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.ExtremeValueDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function FisherFDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.FisherFDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function GammaDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.GammaDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function LaplaceDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.LaplaceDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function LogisticDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.LogisticDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function LognormalDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.LognormalDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function NegativeBinomialDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.NegativeBinomialDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function NoncentralChiSquareDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.NoncentralChiSquareDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function NoncentralStudentsTDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.NoncentralStudentsTDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function NormalDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.NormalDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function ParetoDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.ParetoDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function WeibullDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.WeibullDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function

  Public Shared Function UniformDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum) As mpNum
    Dim m4 As New mpNum
    m4.x1 = mpLib.UniformDist(Target, m1.x1, m2.x1, m3.x1)
    Return m4
  End Function



  Public Shared Function HypergeometricDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.HypergeometricDist(Target, m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function NoncentralFisherFDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.NoncentralFisherFDist(Target, m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function NoncentralBetaDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.NoncentralBetaDist(Target, m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function

  Public Shared Function TriangularDist(ByVal Target As Integer, ByVal m1 As mpNum, ByVal m2 As mpNum, ByVal m3 As mpNum, ByVal m4 As mpNum) As mpNum
    Dim m5 As New mpNum
    m5.x1 = mpLib.TriangularDist(Target, m1.x1, m2.x1, m3.x1, m4.x1)
    Return m5
  End Function














    Public Shared Sub Print(A As mpNum, Name As String)
        Dim n, m, i, j As Integer
        n = A.x1.Rows
        m = A.x1.Cols
        WriteLine("Listing of Matrix " & Name & ",  " & n & " rows x " & m & " columns")
        '	Print ("Listing By Rows & Matrix  " & Name)
        For i = 1 To n
            WriteLine("Listing Row " & i)
            For j = 1 To m
                WriteLine("x(" & i & ", " & j & "): " & A.x1(i, j).Str())
            Next
            WriteLine("EndListing Row " & i)
        Next
        WriteLine("EndListing Matrix " & Name)
        WriteLine("")
    End Sub


    Public Shared Function StringToMatrix(s As String) As mpNum
        Dim s1(), s2() As String, i, j, n, m, m1 As Integer
        Dim s0 As String
        Dim A As New mpNum
        'MsgBox("s:" & s)
        s1 = Split(s, "@")
        n = UBound(s1, 1)
        s2 = Split(s1(0), "@")
        m1 = CInt(Val(s2(0)))
        'MsgBox("n:" & n & " m1:" & m1)

        A = RandomFill(n, m1)
        'MsgBox("A(4,4):" & A(4, 4).Str)
        For i = 1 To n
            'MsgBox("i:" & i)
            s2 = Split(s1(i), "#")
            m = UBound(s2, 1)

            For j = 1 To m + 1
                s0 = s2(j - 1)
                'MsgBox("i:" & i & " j:" & j & " s0:" & s0)
                A.x1.Item(i, j) = mpLib.Real(s0)
                'MsgBox("A(i,j):" & A.x1.Item(i, j).Str)
            Next j
        Next i
        'MsgBox("Done!")
        Return A
    End Function

 
End Class
