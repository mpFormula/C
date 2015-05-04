
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32


'<ComClass(mpNum.ClassId, mpNum.InterfaceId, mpNum.EventsId)> _
Public Class mpNum

'#Region "COM Registration"
'  Public Const ClassId As String _
'  = "403A3D44-A659-4677-B3D4-4A873BE6B884"
'  Public Const InterfaceId As String _
'  = "8B54DCB3-BEA8-47DA-BB43-A9B46E2FAD07"
'  Public Const EventsId As String _
'  = "BCC46B6E-5FF4-46F3-ABC5-5E9754C4B074"
'#End Region
'


  Friend NumPtr As IntPtr = Nothing
  Friend mpNumType As Int32 = 4

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
      mp.Init(mpNumType, NumPtr)
    End If
    'x1.ReDim(m, n)
  End Sub
  
  
  ''' <summary>
  ''' Create a new Matrix with some number of rows and columns.  This is the only place where
  ''' the dimensions can be set.
  ''' </summary>
  ''' <param name="n"></param>
  Public Sub New(ByVal n As Integer)
    If mp.HasLibraryNumC() <> 0 Then
      mp.Init(mpNumType, NumPtr)
    End If
  End Sub


  Public Sub New()
    If mp.HasLibraryNumC() <> 0 Then
      mp.Init(mpNumType, NumPtr)
    End If
  End Sub


  Protected Overrides Sub Finalize()
    Console.WriteLine("Release mpNum")
    mp.mpNum_Clear_(NumPtr)
    'x1 = Nothing
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
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As mpNum)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As mpNum)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As mpNum
    Get
      Dim m1 As New mpNum
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As mpNum)
      '      x1.Col(j) = m1.x1
    End Set

  End Property



End Class



'<ComClass(mp.ClassId, mp.InterfaceId, mp.EventsId)> _
Public Class mp

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
  Private Shared Function RootDir() As String
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


  Private Shared Function HasLibraryAmath() As Double
    Static Result As Double = 0
    If Result = 0 Then
      'Dim DLLPath As String = CStr(My.Computer.Registry.GetValue("HKEY_LOCAL_MACHINE\SOFTWARE\THF", "DLLPath", Nothing))
      '      Dim FName As String = "C:\Extra\mpFormula40\Toolbox\mpNum\Win32\Bin\libAmathDouble.dll"
      Dim FName As String = RootDir() & "mpNum\Win64\Bin\libAmathDouble.dll"

      'MsgBox(FName)
      ' MsgBox(DLLPath)
      Result = CDbl(LoadLibrary(FName))
    End If
    If Result = 0 Then
      MsgBox("Could not load supporting library libAmathDouble!")
      Return 0
    Else
      Return 1
    End If
  End Function


  Friend Shared Function HasLibraryNumC() As Double
    Static Result As Double = 0
    If Result = 0 Then
      'Dim DLLPath As String = CStr(My.Computer.Registry.GetValue("HKEY_LOCAL_MACHINE\SOFTWARE\THF", "DLLPath", Nothing))
      Dim DLLPath As String = RootDir() & "mpNum\Win64\Bin"
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

#Region "Properties"

  Private fField As Single = 0

  Public Property FloatProperty() As Single
    Get
      Return Me.fField
    End Get
    Set(ByVal value As Single)
      Me.fField = value
    End Set
  End Property


  Public Function HelloWorld() As String
    Return "HelloWorld from mpLib"
  End Function



#End Region



  Shared Sub New()
    Dim Result As Double = HasLibraryNumC()
    Console.WriteLine("New NumC 32: ", Result.ToString())
  End Sub



  Public Function CNum(ByVal x As Object) As mpNum
    Dim m3 As New mpNum
    '    m3.x1 = mpLib.Real(x)
    Return m3
  End Function



  <DllImport("mpNumC.dll", EntryPoint:="mpNum_Inverse", CallingConvention:=CallingConvention.Cdecl)> _
  Friend Shared Sub mpNum_Inverse(ByRef MatrixA As IntPtr, ByRef MatrixB As IntPtr, ByVal Decomposition As Int32)
  End Sub

''' <summary>
''' Returns the Inverse of a matrix
''' </summary>
''' <remarks>Returns the Inverse of a matrix</remarks>
   Public Shared Sub GetMatrixInverse(ByVal MatrixA As mpNum, ByVal MatrixB As mpNum, ByVal Decomposition As Int32)
    mpNum_Inverse(MatrixA.NumPtr, MatrixB.NumPtr, Decomposition)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="mpNum_BasicArithmetic", CallingConvention:=CallingConvention.Cdecl)> _
  Friend Shared Sub mpNum_BasicArithmetic(ByVal Operation As Int32, ByRef MatrixA As IntPtr, ByRef MatrixB As IntPtr, ByRef MatrixC As IntPtr)
  End Sub


  Public Shared Sub GetMatrixProduct(ByVal MatrixA As mpNum, ByVal MatrixB As mpNum, ByVal MatrixC As mpNum)
    mpNum_BasicArithmetic(5, MatrixA.NumPtr, MatrixB.NumPtr, MatrixC.NumPtr)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="mpNum_SetPrecision", CallingConvention:=CallingConvention.Cdecl)> _
  Public Shared Sub SetPrecision(ByVal prec As Int32)
  End Sub

  
  <DllImport("mpNumC.dll", EntryPoint:="mpNum_Print", CallingConvention:=CallingConvention.Cdecl, CharSet:=CharSet.Ansi)> _
  Friend Shared Sub mpNum_Print(ByVal mpNumType As String, ByRef NumPtr As IntPtr)
  End Sub

  Public Sub PrintMatrix(ByVal Title As String, ByVal x As mpNum)
    mpNum_Print(Title, x.NumPtr)
  End Sub


  Public Shared Sub SetRandomMatrix(ByVal n As Int32, ByVal m As Int32, ByVal x As mpNum)
    mpNum_SetSpecialValue(n, m, 9, x.NumPtr)
  End Sub




  <DllImport("mpNumC.dll", EntryPoint:="mpNum_SetSpecialValue", CallingConvention:=CallingConvention.Cdecl)> _
  Friend Shared Sub mpNum_SetSpecialValue(ByVal n As Int32, ByVal m As Int32, ByVal what As Int32, ByRef NumPtr As IntPtr)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="mpNum_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend Shared Sub Init(ByVal mpNumType As Int32, ByRef NumPtr As IntPtr)
  End Sub


  <DllImport("mpNumC.dll", EntryPoint:="mpNum_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend Shared Sub mpNum_Clear_(ByRef NumPtr As IntPtr)
  End Sub


 

  
''' <summary>
''' Returns the gamma function as implemented in AMath
''' </summary>
''' <param name="x">Number of rows</param>
''' <returns>Gamma(x)</returns>
''' <remarks>Remarks</remarks>
  <DllImport("libAmathDouble.dll", EntryPoint:="amath_gamma", CallingConvention:=CallingConvention.Cdecl)> _
  Public Shared Function GammaAmath(x As Double) As Double
  End Function
  
  
''' <summary>
''' Returns the gamma2 function as implemented in AMath
''' </summary>
''' <param name="x">Number of rows</param>
''' <returns>Gamma(x)</returns>
''' <remarks>Remarks</remarks>
	Public Shared Function GammaAmath2(x As Double) As Double
  		Return x
	End Function


''' <summary>
''' Returns the StdDoubleSum of x and y
''' </summary>
''' <param name="x">Number of rows</param>
''' <param name="y">Number of columns</param>
''' <returns>Sqrt(x^2 + y^2)</returns>
''' <remarks>Remarks</remarks>
  <DllImport("mpNumC.dll", EntryPoint:="Std_Double_Sum", CallingConvention:=CallingConvention.Cdecl)> _
  Public Shared Function StdDoubleSum(x As Double, y As Double) As Double
  End Function




End Class
