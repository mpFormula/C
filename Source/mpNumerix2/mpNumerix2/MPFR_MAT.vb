
Imports System
Imports System.Runtime.InteropServices

Public Class mpfr_mat_t

  Friend MpfrMatPtr As IntPtr = Nothing

    
  
  Private Sub Init()
      mp4.Init()
      Lib_Eigen_Mpfr_Init(MpfrMatPtr)
  End Sub
  
  
  
  Private Sub Init(ByVal m As Integer, ByVal n As Integer)
      mp4.Init()
      Lib_Eigen_Mpfr_Init(MpfrMatPtr)      
      Lib_Eigen_Mpfr_Resize(MpfrMatPtr, m, n)
  End Sub
  
  
  Public Sub New()
      Init()
  End Sub
  
  
  Public Sub New(src As mpfr_mat_t)
      Init()
      
  End Sub
  
  
  ''' <summary>
  ''' Create a new Matrix with m of rows and n columns.  
  ''' </summary>
  ''' <param name="m">Number of rows</param>
  ''' <param name="n">Number of columns</param>
  Public Sub New(ByVal m As Integer, ByVal n As Integer)
      Init(m, n)
  End Sub
  
  
  
  Friend Function DeepCopyPtr(src As IntPtr) As mpfr_mat_t
      Dim n As Int32 = rows()
      Dim m3 As New mpfr_mat_t(n,n)
      For i As Int32 = 0 To n-1
          For j As Int32 = 0 To n-1
            m3(i,i) = item(i,i)
          Next
      Next
    Return m3
  End Function
  
  
  Friend Function DeepCopyMatrix(src As mpfr_mat_t) As mpfr_mat_t
      Dim n As Int32 = src.rows()
      Dim m3 As New mpfr_mat_t(n,n)
      m3 = DeepCopyPtr(src.MpfrMatPtr)
      Return m3
  End Function
  
  
  
  Public Sub New(x As mpfr_t)
        Lib_Eigen_Mpfr_Init(MpfrMatPtr)
        Lib_Eigen_Mpfr_SetCoeff2(x.MpfrPtr, 0, 0, MpfrMatPtr)
  End Sub
  


  Protected Overrides Sub Finalize()
    Lib_Eigen_Mpfr_Clear(MpfrMatPtr)
    MyBase.Finalize()
  End Sub


  ''' <summary>
  ''' The number of rows in the matrix
  ''' </summary>
  ''' <returns>The number of rows in the matrix</returns>
  Public ReadOnly Property rows() As Integer
    Get
      Return Lib_Eigen_Mpfr_GetRows(MpfrMatPtr)
    End Get
  End Property

  ''' <summary>
  ''' The number of columns in the matrix
  ''' </summary>
  ''' <returns>The number of columns in the matrix</returns>
  Public ReadOnly Property cols() As Integer
    Get
      Return Lib_Eigen_Mpfr_GetCols(MpfrMatPtr)
    End Get
  End Property

  Public ReadOnly Property size() As Integer
    Get
      Return Lib_Eigen_Mpfr_GetSize(MpfrMatPtr)
    End Get
  End Property



  ''' <summary>
  ''' Gets and Sets an Item
  ''' </summary>
  ''' <param name="row_i"></param>
  ''' <param name="col_j"></param>
  Default Public Property item(ByVal row_i As Int32, ByVal col_j As Int32) As mpfr_t
    Get
        Dim m1 As New mpfr_t
        Lib_Eigen_Mpfr_GetCoeff2(m1.MpfrPtr, row_i, col_j, MpfrMatPtr)
        Return m1
    End Get

    Set(ByVal m1 As mpfr_t)
        Lib_Eigen_Mpfr_SetCoeff2(m1.MpfrPtr, row_i, col_j, MpfrMatPtr)
    End Set

  End Property

  ''' <summary>
  ''' Gets or Sets a block
  ''' </summary>
  ''' <param name="i"></param>
  ''' <param name="j"></param>
  ''' <param name="p"></param>
  ''' <param name="q"></param>
  Public Property block(ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32) As mpfr_mat_t
    Get
      Dim m1 As New mpfr_mat_t
      Lib_Eigen_Mpfr_Get_Block(m1.MpfrMatPtr, i, j, p, q, MpfrMatPtr)
      Return m1

    End Get

    Set(ByVal m1 As mpfr_mat_t)
      Lib_Eigen_Mpfr_Put_Block(m1.MpfrMatPtr, i, j, p, q, MpfrMatPtr)
    End Set

  End Property


  
  Public Overrides Function ToString() As String
    Return "MpfrMatPtr"
  End Function
  
  
  Public Function str() As String(,)
      Dim res(Rows-1, Cols-1) As String
      Dim m1 As New mpfr_t
      For i As Integer = 0 To Rows-1
          For j As Integer = 0 To Cols-1
            Lib_Eigen_Mpfr_GetCoeff2(m1.MpfrPtr, i, j, MpfrMatPtr)
            res(i,j) = m1.ToString()
          Next j
      Next i
      Return res
  End Function
  
  
    
  Public Function mat() As mpfr_t(,)
      Dim res(Rows-1, Cols-1) As mpfr_t
      Dim m1 As New mpfr_t
      For i As Integer = 0 To Rows-1
          For j As Integer = 0 To Cols-1
            res(i,j) = New mpfr_t()
            Lib_Eigen_Mpfr_GetCoeff2(res(i,j).MpfrPtr, i, j, MpfrMatPtr)
          Next j
      Next i
      Return res
  End Function


  Public Sub print(Title As String)
      Lib_Eigen_Mpfr_Print(Title, MpfrMatPtr)  
  End Sub
  

  Public Sub Random(ByVal n As Int32, ByVal m As Int32)
      Lib_Eigen_Mpfr_SetRandom(MpfrMatPtr, n, m)  
  End Sub
  

  Public Sub RandomSymmetric(ByVal n As Int32, ByVal m As Int32)
      Lib_Eigen_Mpfr_SetRandomSymmetric(MpfrMatPtr, n, m)  
  End Sub
  
  
  
  
  
  Public Function solve(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 0)
    Return x
  End Function

  
  Public Function SolveFullPivLU(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 0)
    Return x
  End Function

  
  Public Function SolveLDLT(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 1)
    Return x
  End Function


  
  Public Function SolveColPivQR(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 2)
    Return x
  End Function



  Public Function SolveFullPivQR(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 3)
    Return x
  End Function



  Public Function SolveSVD(b As mpfr_mat_t) As mpfr_mat_t
    Dim x As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Solve2(x.MpfrMatPtr, MpfrMatPtr, b.MpfrMatPtr, 4)
    Return x
  End Function



  Public Function inverse() As mpfr_mat_t
    Dim m3 As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Inverse(m3.MpfrMatPtr, MpfrMatPtr, 0)
    Return m3
  End Function
  
  
  
  Public Function InverseFullPivLU() As mpfr_mat_t
    Dim m3 As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Inverse(m3.MpfrMatPtr, MpfrMatPtr, 0)
    Return m3
  End Function
  
  
  Public Function InverseColPivQR() As mpfr_mat_t
    Dim m3 As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Inverse(m3.MpfrMatPtr, MpfrMatPtr, 2)
    Return m3
  End Function
  
  
  Public Function InverseFullPivQR() As mpfr_mat_t
    Dim m3 As New mpfr_mat_t()
    Lib_Eigen_Mpfr_Inverse(m3.MpfrMatPtr, MpfrMatPtr, 2)
    Return m3
  End Function
  
  
  Public Function Det() As mpfr_t
      Dim m3 As New mpfr_mat_t(1,1)
      Dim d As New mpfr_t
      Lib_Eigen_Mpfr_Det(m3.MpfrMatPtr, MpfrMatPtr, 0)
      d = m3(0,0)
      Return d
  End Function
  
  
  Public Function Rank() As Int32
    Return Lib_Eigen_Mpfr_Rank(MpfrMatPtr, 0)
  End Function
  
  
  
  
  Public Function SymmetricEigenvalues() As mpfr_mat_t
    Dim m3 As New mpfr_mat_t()
    Lib_Eigen_Mpfr_SelfAdjointEigenValues(m3.MpfrMatPtr, MpfrMatPtr)
    Return m3
  End Function
  
  
  Public Function SubtractFromDiagonal(lambda As mpfr_t) As mpfr_mat_t
      Dim n As Int32 = rows()
      Dim m3 As New mpfr_mat_t(n,n)
      For i As Int32 =0 To n-1
      For j As Int32 =0 To n-1
          m3(i,j) = item(i,j)
      Next
      Next
      For i As Int32 =0 To n-1
          m3(i,i) = m3(i,i) - lambda
      Next
    Return m3
  End Function
  


  Public Sub resize(ByVal rows As Int32, ByVal cols As Int32)
      Lib_Eigen_Mpfr_Resize(MpfrMatPtr, rows, cols)  
  End Sub
  
  
  
  Public Sub conservative_resize(ByVal rows As Int32, ByVal cols As Int32)
      Lib_Eigen_Mpfr_Conservative_Resize(MpfrMatPtr, rows, cols)  
  End Sub
  
  
    Public  Function GT_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_GT_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
    
  Public  Function LT_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_LT_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
  
  Public  Function LE_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_LE_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
  
  Public  Function GE_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_GE_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
  
  Public  Function EQ_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_EQ_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
  
  Public  Function NE_count(ByVal Y As mpfr_mat_t) As UInt32
       Return Lib_Eigen_Mpfr_NE_Count(MpfrMatPtr, Y.MpfrMatPtr)
  End Function
  
  
  

    Public Shared Operator =(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_EQ_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator


    Public Shared Operator <>(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_NE_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator


    Public Shared Operator <=(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_LE_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator


    Public Shared Operator <(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_LT_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator


    Public Shared Operator >=(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_GE_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator


    Public Shared Operator >(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As Boolean
        Return (Lib_Eigen_Mpfr_GT_Count(m1.MpfrMatPtr, m2.MpfrMatPtr) = m1.size)
    End Operator




    Public Shared Operator +(ByVal m1 As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        m3 = m1
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
'        mpz.Lib_Mpz_Neg(m3.MpzPtr, m1.MpzPtr)
        Return m3
    End Operator



    '***********************************************************************


    Public Shared Operator +(ByVal M1 As mpfr_mat_t, ByVal M2 As mpfr_mat_t) As mpfr_mat_t
        Dim Res As New mpfr_mat_t()
        Lib_Eigen_Mpfr_MatAdd(Res.MpfrMatPtr, M1.MpfrMatPtr, M2.MpfrMatPtr)
        Return Res
    End Operator


    Public Shared Operator +(ByVal M1 As mpfr_mat_t, ByVal m2 As mpfr_t) As mpfr_mat_t
        Dim Res As New mpfr_mat_t()
        Dim T As New mpfr_mat_t(m2)
        Lib_Eigen_Mpfr_Mat_Add_Scalar(Res.MpfrMatPtr, M1.MpfrMatPtr, T.MpfrMatPtr)
        Return Res
    End Operator
    
    
    

    Public Shared Operator -(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Lib_Eigen_Mpfr_MatSub(m3.MpfrMatPtr, m1.MpfrMatPtr, m2.MpfrMatPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal M1 As mpfr_mat_t, ByVal m2 As mpfr_t) As mpfr_mat_t
        Dim Res As New mpfr_mat_t()
        Dim T As New mpfr_mat_t(m2)
        Lib_Eigen_Mpfr_Mat_Sub_Scalar(Res.MpfrMatPtr, M1.MpfrMatPtr, T.MpfrMatPtr)
        Return Res
    End Operator
    
    
    

    Public Shared Operator *(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Lib_Eigen_Mpfr_MatMul(m3.MpfrMatPtr, m1.MpfrMatPtr, m2.MpfrMatPtr)
        Return m3
    End Operator


    Public Shared Operator *(ByVal M1 As mpfr_mat_t, ByVal m2 As mpfr_t) As mpfr_mat_t
        Dim Res As New mpfr_mat_t()
        Dim T As New mpfr_mat_t(m2)
        Lib_Eigen_Mpfr_Mat_Mul_Scalar(Res.MpfrMatPtr, M1.MpfrMatPtr, T.MpfrMatPtr)
        Return Res
    End Operator
  
      Public Function cwiseProduct(x As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Lib_Eigen_Mpfr_Mat_cwiseProduct(m3.MpfrMatPtr, x.MpfrMatPtr, MpfrMatPtr)
        Return m3
      End Function
  
      Public Function dotProduct(x As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Lib_Eigen_Mpfr_MatDotProduct(m3.MpfrMatPtr, x.MpfrMatPtr, MpfrMatPtr)
        Return m3
      End Function



    Public Shared Operator /(ByVal m1 As mpfr_mat_t, ByVal m2 As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Dim m4 As New mpfr_mat_t()
        m4 = m2.inverse()
        Lib_Eigen_Mpfr_MatMul(m3.MpfrMatPtr, m1.MpfrMatPtr, m4.MpfrMatPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal M1 As mpfr_mat_t, ByVal m2 As mpfr_t) As mpfr_mat_t
        Dim Res As New mpfr_mat_t()
        Dim T As New mpfr_mat_t(m2)
        Lib_Eigen_Mpfr_Mat_Div_Scalar(Res.MpfrMatPtr, M1.MpfrMatPtr, T.MpfrMatPtr)
        Return Res
    End Operator
  
      Public Function cwiseQuotient(x As mpfr_mat_t) As mpfr_mat_t
        Dim m3 As New mpfr_mat_t()
        Lib_Eigen_Mpfr_Mat_cwiseQuotient(m3.MpfrMatPtr, x.MpfrMatPtr, MpfrMatPtr)
        Return m3
      End Function
  
  

End Class







Public Module mpfr_mat

    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Init", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Init(ByRef A As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Clear", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Clear(ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Print", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Print(Title As String,  ByVal A As IntPtr)
  End Sub



  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Resize", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Resize(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
  End Sub
  


  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Conservative_Resize", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Conservative_Resize(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_SetRandom", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_SetRandom(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_SetRandomSymmetric", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_SetRandomSymmetric(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
  End Sub
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GetCoeff2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_GetCoeff2(ByVal MpfrPtr_X As IntPtr, ByVal row As Int32, ByVal col As Int32, ByVal SourceMatrix As IntPtr)
  End Sub
  
    

  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_SetCoeff2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_SetCoeff2(ByVal MpfrPtr_X As IntPtr, ByVal row As Int32, ByVal col As Int32, ByVal SourceMatrix As IntPtr)
  End Sub
  
    

  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GetRows", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_GetRows(ByVal SourceMatrix As IntPtr) As Int32
  End Function
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GetCols", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_GetCols(ByVal SourceMatrix As IntPtr) As Int32
  End Function
  

    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GetSize", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_GetSize(ByVal SourceMatrix As IntPtr) As Int32
  End Function
  
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Get_Block", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Get_Block(ByVal Result As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32, ByVal Source As IntPtr)
  End Sub
    
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Put_Block", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Put_Block(ByVal Source As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32, ByVal Result As IntPtr)
  End Sub
  

  '*************************************************************************************



      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_MatAdd", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_MatAdd(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_MatSub", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_MatSub(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_MatMul", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_MatMul(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_MatDotProduct", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_MatDotProduct(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  
      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_cwiseProduct", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_cwiseProduct(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_cwiseQuotient", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_cwiseQuotient(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub
  


      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_Add_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_Add_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub

      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_Sub_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_Sub_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub

      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_Mul_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_Mul_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub

      
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Mat_Div_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Mat_Div_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
  End Sub

  
  '*************************************************************************************


'This currently compares only against the first coeff of Y

  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GT_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_GT_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_LT_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_LT_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_LE_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_LE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_GE_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_GE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_EQ_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_EQ_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_NE_Count", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_NE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
  End Function
  
  
  '*************************************************************************************
  
    
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Complex_To_2Reals", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Complex_To_2Reals(ByVal MpfrMatPtr_Res_real As IntPtr, ByVal MpfrMatPtr_Res_imag As IntPtr, ByVal MpfcMatPtr_Src As IntPtr)
  End Sub
  
  
  Public Sub ComplexToReal2(Res_real As mpfr_mat_t, Res_imag As mpfr_mat_t, Src As mpfc_mat_t)
    Lib_Eigen_Complex_To_2Reals(Res_real.MpfrMatPtr, Res_imag.MpfrMatPtr, Src.MpfcMatPtr)
  End Sub
      
  
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_2Reals_To_Complex", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_2Reals_To_Complex(ByVal MpfcMatPtr_Res As IntPtr, ByVal MpfrMatPtr_Src_real As IntPtr, ByVal MpfrMatPtr_Src_imag As IntPtr)
  End Sub
  
  
  Public Sub Real2ToComplex(Res As mpfc_mat_t, Src_real As mpfr_mat_t, Src_imag As mpfr_mat_t)
    Lib_Eigen_2Reals_To_Complex(Res.MpfcMatPtr, Src_real.MpfrMatPtr, Src_imag.MpfrMatPtr)
  End Sub
  
  ' Currently assumes m=n
      Public Function ComplexMatMulRealPairs(x1  As mpfc2_mat_t, x2 As mpfc2_mat_t) As mpfc2_mat_t
        Dim n As Integer = x1.RealMat.rows
        Dim m1 As New mpfc_mat_t(n,n)
        Dim m2 As New mpfc_mat_t(n,n)
        Dim m3 As New mpfc_mat_t(n,n)
        mpfr_mat.Real2ToComplex(m1, x1.RealMat, x1.ImagMat)
        mpfr_mat.Real2ToComplex(m2, x2.RealMat, x2.ImagMat)
        m3 = m1 * m2
        Dim m5 As New mpfc2_mat_t(n,n)
        mpfr_mat.ComplexToReal2(m5.RealMat, m5.ImagMat, m3)
        Return m5
    End Function
    
    
    
    
      
  '*************************************************************************************

    
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Solve2", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Solve2(ByVal Res As IntPtr, ByVal A As IntPtr, ByVal b As IntPtr, Decomposition As Int32)
  End Sub
  
  
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Inverse", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Inverse(ByVal Res As IntPtr, ByVal A As IntPtr,  Decomposition As Int32)
  End Sub


    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Det", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_Det(ByVal Res As IntPtr, ByVal A As IntPtr,  Decomposition As Int32)
  End Sub

    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Rank", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Function Lib_Eigen_Mpfr_Rank(ByVal A As IntPtr,  Decomposition As Int32) As Int32
  End Function

    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_SelfAdjointEigenValues", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfr_SelfAdjointEigenValues(ByVal Res As IntPtr, ByVal A As IntPtr)
  End Sub


  
End Module


