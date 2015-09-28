
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text



Public Class mpfc_mat_t

    Friend MpfcMatPtr As IntPtr = Nothing


    Public Sub New()
            Lib_Eigen_Mpfc_Init(MpfcMatPtr)
    End Sub


    ''' <summary>
    ''' Create a new Matrix with m of rows and n columns.  
    ''' </summary>
    ''' <param name="m">Number of rows</param>
    ''' <param name="n">Number of columns</param>
    Public Sub New(ByVal m As Integer, ByVal n As Integer)
            Lib_Eigen_Mpfc_Init(MpfcMatPtr)
            Lib_Eigen_Mpfc_Resize(MpfcMatPtr, m, n)
    End Sub


    Public Sub New(x As mpfc_t)
            Lib_Eigen_Mpfc_Init(MpfcMatPtr)
            Lib_Eigen_Mpfc_SetCoeff2(x.MpfcPtr, 0, 0, MpfcMatPtr)
    End Sub



    Protected Overrides Sub Finalize()
        Lib_Eigen_Mpfc_Clear(MpfcMatPtr)
        MyBase.Finalize()
    End Sub


    ''' <summary>
    ''' The number of rows in the matrix
    ''' </summary>
    ''' <returns>The number of rows in the matrix</returns>
    Public ReadOnly Property rows() As Integer
        Get
            Return Lib_Eigen_Mpfc_GetRows(MpfcMatPtr)
        End Get
    End Property

    ''' <summary>
    ''' The number of columns in the matrix
    ''' </summary>
    ''' <returns>The number of columns in the matrix</returns>
    Public ReadOnly Property cols() As Integer
        Get
            Return Lib_Eigen_Mpfc_GetCols(MpfcMatPtr)
        End Get
    End Property

    Public ReadOnly Property size() As Integer
        Get
            Return Lib_Eigen_Mpfc_GetSize(MpfcMatPtr)
        End Get
    End Property



    ''' <summary>
    ''' Gets and Sets an Item
    ''' </summary>
    ''' <param name="row_i"></param>
    ''' <param name="col_j"></param>
    Default Public Property item(ByVal row_i As Int32, ByVal col_j As Int32) As mpfc_t
        Get
            Dim m1 As New mpfc_t
            Lib_Eigen_Mpfc_GetCoeff2(m1.MpfcPtr, row_i, col_j, MpfcMatPtr)
            Return m1
        End Get

    Set(ByVal m1 As mpfc_t)
            Console.WriteLine("In set item")
            Lib_Eigen_Mpfc_SetCoeff2(m1.MpfcPtr, row_i, col_j, MpfcMatPtr)
        End Set

    End Property

    ''' <summary>
    ''' Gets or Sets a block
    ''' </summary>
    ''' <param name="i"></param>
    ''' <param name="j"></param>
    ''' <param name="p"></param>
    ''' <param name="q"></param>
    Public Property block(ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32) As mpfc_mat_t
        Get
            Dim m1 As New mpfc_mat_t
            Lib_Eigen_Mpfc_Get_Block(m1.MpfcMatPtr, i, j, p, q, MpfcMatPtr)
            Return m1

        End Get

        Set(ByVal m1 As mpfc_mat_t)
            Lib_Eigen_Mpfc_Put_Block(m1.MpfcMatPtr, i, j, p, q, MpfcMatPtr)
        End Set

    End Property



    Public Overrides Function ToString() As String
        Return "MpfcMatPtr"
    End Function


    Public Function str() As String(,)
        Dim res(rows - 1, cols - 1) As String
        Dim m1 As New mpfc_t
        For i As Integer = 0 To rows - 1
            For j As Integer = 0 To cols - 1
                Lib_Eigen_Mpfc_GetCoeff2(m1.MpfcPtr, i, j, MpfcMatPtr)
                res(i, j) = m1.ToString()
            Next j
        Next i
        Return res
    End Function



    Public Function mat() As mpfc_t(,)
        Dim res(rows - 1, cols - 1) As mpfc_t
        Dim m1 As New mpfc_t
        For i As Integer = 0 To rows - 1
            For j As Integer = 0 To cols - 1
                res(i, j) = New mpfc_t()
                Lib_Eigen_Mpfc_GetCoeff2(res(i, j).MpfcPtr, i, j, MpfcMatPtr)
            Next j
        Next i
        Return res
    End Function


    Public Sub print(Title As String)
        Lib_Eigen_Mpfc_Print(Title, MpfcMatPtr)
    End Sub



    Public Function inverse() As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_Inverse(m3.MpfcMatPtr, MpfcMatPtr, 0)
        Return m3
    End Function




 
  Public Function Det() As mpfc_t
      Dim m3 As New mpfc_mat_t(1,1)
      Dim d As New mpfc_t
      Lib_Eigen_Mpfc_Det(m3.MpfcMatPtr, MpfcMatPtr, 0)
      d = m3(0,0)
      Return d
  End Function
  
  
'  Public Function Rank() As Int32
'    Return Lib_Eigen_Mpfr_Rank(MpfrMatPtr, 0)
'  End Function
  
  
  
  
  Public Function Eigenvalues() As mpfc_mat_t
    Dim m3 As New mpfc_mat_t()
    Lib_Eigen_Mpfc_EigenValues(m3.MpfcMatPtr, MpfcMatPtr)
    Return m3
  End Function
  
  
  Public Function SubtractFromDiagonal(lambda As mpfc_t) As mpfc_mat_t
      Dim n As Int32 = rows()
      Dim m3 As New mpfc_mat_t(n,n)
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
        Lib_Eigen_Mpfc_Resize(MpfcMatPtr, rows, cols)
    End Sub



    Public Sub conservative_resize(ByVal rows As Int32, ByVal cols As Int32)
        Lib_Eigen_Mpfc_Conservative_Resize(MpfcMatPtr, rows, cols)
    End Sub





    Public Shared Operator =(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_EQ_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator


    Public Shared Operator <>(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_NE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator


    Public Shared Operator <=(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_LE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator


    Public Shared Operator <(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_LT_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator


    Public Shared Operator >=(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_GE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator


    Public Shared Operator >(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As Boolean
        Return (Lib_Eigen_Mpfc_GT_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    End Operator




    Public Shared Operator +(ByVal m1 As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        m3 = m1
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        '        mpz.Lib_Mpz_Neg(m3.MpzPtr, m1.MpzPtr)
        Return m3
    End Operator



    '***********************************************************************


    Public Shared Operator +(ByVal M1 As mpfc_mat_t, ByVal M2 As mpfc_mat_t) As mpfc_mat_t
        Dim Res As New mpfc_mat_t()
        Lib_Eigen_Mpfc_MatAdd(Res.MpfcMatPtr, M1.MpfcMatPtr, M2.MpfcMatPtr)
        Return Res
    End Operator


    Public Shared Operator +(ByVal M1 As mpfc_mat_t, ByVal m2 As mpfc_t) As mpfc_mat_t
        Dim Res As New mpfc_mat_t()
        Dim T As New mpfc_mat_t(m2)
        Lib_Eigen_Mpfc_Mat_Add_Scalar(Res.MpfcMatPtr, M1.MpfcMatPtr, T.MpfcMatPtr)
        Return Res
    End Operator




    Public Shared Operator -(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_MatSub(m3.MpfcMatPtr, m1.MpfcMatPtr, m2.MpfcMatPtr)
        Return m3
    End Operator


    Public Shared Operator -(ByVal M1 As mpfc_mat_t, ByVal m2 As mpfc_t) As mpfc_mat_t
        Dim Res As New mpfc_mat_t()
        Dim T As New mpfc_mat_t(m2)
        Lib_Eigen_Mpfc_Mat_Sub_Scalar(Res.MpfcMatPtr, M1.MpfcMatPtr, T.MpfcMatPtr)
        Return Res
    End Operator




    Public Shared Operator *(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_MatMul(m3.MpfcMatPtr, m1.MpfcMatPtr, m2.MpfcMatPtr)
        Return m3
    End Operator


    Public Shared Operator *(ByVal M1 As mpfc_mat_t, ByVal m2 As mpfc_t) As mpfc_mat_t
        Dim Res As New mpfc_mat_t()
        Dim T As New mpfc_mat_t(m2)
        Lib_Eigen_Mpfc_Mat_Mul_Scalar(Res.MpfcMatPtr, M1.MpfcMatPtr, T.MpfcMatPtr)
        Return Res
    End Operator

    Public Function cwiseProduct(x As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_Mat_cwiseProduct(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
        Return m3
    End Function

    Public Function dotProduct(x As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_MatDotProduct(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
        Return m3
    End Function



    Public Shared Operator /(ByVal m1 As mpfc_mat_t, ByVal m2 As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Dim m4 As New mpfc_mat_t()
        m4 = m2.inverse()
        Lib_Eigen_Mpfc_MatMul(m3.MpfcMatPtr, m1.MpfcMatPtr, m4.MpfcMatPtr)
        Return m3
    End Operator


    Public Shared Operator /(ByVal M1 As mpfc_mat_t, ByVal m2 As mpfc_t) As mpfc_mat_t
        Dim Res As New mpfc_mat_t()
        Dim T As New mpfc_mat_t(m2)
        Lib_Eigen_Mpfc_Mat_Div_Scalar(Res.MpfcMatPtr, M1.MpfcMatPtr, T.MpfcMatPtr)
        Return Res
    End Operator

    Public Function cwiseQuotient(x As mpfc_mat_t) As mpfc_mat_t
        Dim m3 As New mpfc_mat_t()
        Lib_Eigen_Mpfc_Mat_cwiseQuotient(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
        Return m3
    End Function



End Class







Public Module mpfc_mat


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Init", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Init(ByRef A As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Clear", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Clear(ByVal A As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Print", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Print(Title As String, ByVal A As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Resize", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Resize(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Conservative_Resize", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Conservative_Resize(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
    End Sub

    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_SetRandom", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_SetRandom(ByVal MatrixPtr_Res As IntPtr, ByVal rows As Int32, ByVal cols As Int32)
    End Sub






    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GetCoeff2a", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_GetCoeff2(ByVal MpfcPtr_X As IntPtr, ByVal row As Int32, ByVal col As Int32, ByVal SourceMatrix As IntPtr)
    End Sub





    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_SetCoeff2a", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_SetCoeff2(ByVal MpfcPtr_X As IntPtr, ByVal row As Int32, ByVal col As Int32, ByVal SourceMatrix As IntPtr)
    End Sub





    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GetRows", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_GetRows(ByVal SourceMatrix As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GetCols", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_GetCols(ByVal SourceMatrix As IntPtr) As Int32
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GetSize", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_GetSize(ByVal SourceMatrix As IntPtr) As Int32
    End Function




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Get_Block", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Get_Block(ByVal Result As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32, ByVal Source As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Put_Block", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Put_Block(ByVal Source As IntPtr, ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32, ByVal Result As IntPtr)
    End Sub


    '*************************************************************************************




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_MatAdd", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_MatAdd(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_MatSub", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_MatSub(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_MatMul", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_MatMul(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_MatDotProduct", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_MatDotProduct(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_cwiseProduct", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_cwiseProduct(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_cwiseQuotient", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_cwiseQuotient(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub




    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_Add_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_Add_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_Sub_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_Sub_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_Mul_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_Mul_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Mat_Div_Scalar", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Mat_Div_Scalar(ByVal Res As IntPtr, ByVal X As IntPtr, ByVal Y As IntPtr)
    End Sub


    '*************************************************************************************


    'This currently compares only against the first coeff of Y

    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GT_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_GT_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function GT_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_GT_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_LT_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_LT_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function LT_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_LT_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_LE_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_LE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function LE_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_LE_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_GE_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_GE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function GE_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_GE_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_EQ_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_EQ_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function EQ_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_EQ_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function



    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_NE_Count", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Function Lib_Eigen_Mpfc_NE_Count(ByVal X As IntPtr, ByVal Y As IntPtr) As UInt32
    End Function

    Public Function NE_count(ByVal X As mpfc_mat_t, ByVal Y As mpfc_mat_t) As UInt32
        Return Lib_Eigen_Mpfc_NE_Count(X.MpfcMatPtr, Y.MpfcMatPtr)
    End Function




    '*************************************************************************************





    Public Function RandomMatrix(ByVal n As Int32, ByVal m As Int32) As mpfc_mat_t
        Dim Res As New mpfc_mat_t
        Lib_Eigen_Mpfc_SetRandom(Res.MpfcMatPtr, n, m)
        Return Res
    End Function


    <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Inverse", CallingConvention:=CallingConvention.Cdecl)> _
    Friend Sub Lib_Eigen_Mpfc_Inverse(ByVal Res As IntPtr, ByVal X As IntPtr, Decomposition As Int32)
    End Sub
    
    
    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_Det", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfc_Det(ByVal Res As IntPtr, ByVal A As IntPtr,  Decomposition As Int32)
  End Sub

'    
'  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfr_Rank", CallingConvention:=CallingConvention.Cdecl)> _
'  Friend  Function Lib_Eigen_Mpfr_Rank(ByVal A As IntPtr,  Decomposition As Int32) As Int32
'  End Function

    
  <DllImport("mpNumC.dll", EntryPoint:="Lib_Eigen_Mpfc_EigenValues", CallingConvention:=CallingConvention.Cdecl)> _
  Friend  Sub Lib_Eigen_Mpfc_EigenValues(ByVal Res As IntPtr, ByVal A As IntPtr)
  End Sub

    


End Module


