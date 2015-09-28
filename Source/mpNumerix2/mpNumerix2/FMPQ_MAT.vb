
Imports System
Imports System.Runtime.InteropServices

Public Class fmpq_mat_t



  Friend FmpqMatPtr As IntPtr = Nothing
  
    
    
  
  Private Sub Init(ByVal m As Integer, ByVal n As Integer)
      mp4.Init()
      Lib_Fmpq_Mat_Init(FmpqMatPtr, m, n)
  End Sub

  
  
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
    Lib_Fmpq_Mat_Clear(FmpqMatPtr)
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
  Default Public Property Item(ByVal i As Integer, ByVal j As Integer) As fmpq_t
    Get
      Dim m1 As New fmpq_t
      '      m1.x1.Item(1, 1) = x1.Item(i, j)
      Return m1

    End Get

    Set(ByVal m1 As fmpq_t)
      '      x1.Item(i, j) = m1.x1.Item(1, 1)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a row
  ''' </summary>
  ''' <param name="i"></param>
  Public Property Row(ByVal i As Integer) As fmpq_t
    Get
      Dim m1 As New fmpq_t
      '      m1.x1 = x1.Row(i)
      Return m1

    End Get

    Set(ByVal m1 As fmpq_t)
      '      x1.Row(i) = m1.x1
    End Set

  End Property


  Public Property Col(ByVal j As Integer) As fmpq_t
    Get
      Dim m1 As New fmpq_t
      '      m1.x1 = x1.Col(j)
      Return m1
    End Get

    Set(ByVal m1 As fmpq_t)
      '      x1.Col(j) = m1.x1
    End Set

  End Property



End Class




Public Module fmpq_mat


  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Init(ByRef A As IntPtr, ByVal i As Int32, ByVal j As Int32)
  End Sub

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Clear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Print_Pretty", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Print_Pretty(ByVal A As IntPtr)
  End Sub
  
  Public  Sub MatPrint(ByVal X As fmpq_mat_t)
      Lib_Fmpq_Mat_Print_Pretty(X.FmpqMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Mul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Mul(ByVal X As IntPtr, ByVal Y As IntPtr, ByVal Z As IntPtr)
  End Sub
  
  Public  Sub MatMul(ByVal X As fmpq_mat_t, ByVal Y As fmpq_mat_t, ByVal Z As fmpq_mat_t)
      Lib_Fmpq_Mat_Mul(X.FmpqMatPtr, Y.FmpqMatPtr, Z.FmpqMatPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Fmpq_Mat_Set_Si", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Fmpq_Mat_Set_Si(ByVal FmpqPtr As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32)
  End Sub

  Public  Sub MatSetSi(ByVal X As fmpq_mat_t, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32)
      Lib_Fmpq_Mat_Set_Si(X.FmpqMatPtr, i, j, p, q)
  End Sub



End Module



