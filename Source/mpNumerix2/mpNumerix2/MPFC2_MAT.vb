
Imports System
Imports System.IO
Imports System.Runtime.InteropServices
Imports Microsoft.Win32
Imports System.Text



Public Class mpfc2_mat_t

    Public RealMat As mpfr_mat_t
    Public ImagMat As mpfr_mat_t


    Public Sub New()
            RealMat = New mpfr_mat_t()
            ImagMat = New mpfr_mat_t()
    End Sub


    ''' <summary>
    ''' Create a new Matrix with m of rows and n columns.  
    ''' </summary>
    ''' <param name="m">Number of rows</param>
    ''' <param name="n">Number of columns</param>
    Public Sub New(ByVal m As Integer, ByVal n As Integer)
            RealMat = New mpfr_mat_t(m, n)
            ImagMat = New mpfr_mat_t(m, n)
    End Sub


    Public Sub New(x As mpfc_t)
            RealMat = New mpfr_mat_t(x.real())
            ImagMat = New mpfr_mat_t(x.imag())
    End Sub




    ''' <summary>
    ''' The number of rows in the matrix
    ''' </summary>
    ''' <returns>The number of rows in the matrix</returns>
    Public ReadOnly Property rows() As Integer
        Get
            Return RealMat.rows()
        End Get
    End Property

    ''' <summary>
    ''' The number of columns in the matrix
    ''' </summary>
    ''' <returns>The number of columns in the matrix</returns>
    Public ReadOnly Property cols() As Integer
        Get
            Return RealMat.cols()
        End Get
    End Property

    Public ReadOnly Property size() As Integer
        Get
            Return RealMat.size()
        End Get
    End Property



    ''' <summary>
    ''' Gets and Sets an Item
    ''' </summary>
    ''' <param name="row_i"></param>
    ''' <param name="col_j"></param>
    Default Public Property item(ByVal row_i As Int32, ByVal col_j As Int32) As mpfc_t
        Get
            Dim m1_re, m1_im As New mpfr_t
            m1_re = RealMat.item(row_i, col_j)
            m1_im = ImagMat.item(row_i, col_j)
            Dim m1 As New mpfc_t(m1_re, m1_im)
            Return m1
        End Get

        Set(ByVal m1 As mpfc_t)
            RealMat(row_i, col_j) = m1.real()
            ImagMat(row_i, col_j) = m1.imag()
        End Set

    End Property

    ''' <summary>
    ''' Gets or Sets a block
    ''' </summary>
    ''' <param name="i"></param>
    ''' <param name="j"></param>
    ''' <param name="p"></param>
    ''' <param name="q"></param>
    Public Property block(ByVal i As Int32, ByVal j As Int32, ByVal p As Int32, ByVal q As Int32) As mpfc2_mat_t
        Get
            Dim m1 As New mpfc2_mat_t
            m1.RealMat = RealMat.block(i, j, p, q)
            m1.ImagMat = ImagMat.block(i, j, p, q)
            Return m1
        End Get

        Set(ByVal m1 As mpfc2_mat_t)
            RealMat.block(i, j, p, q) = m1.RealMat
            ImagMat.block(i, j, p, q) = m1.ImagMat
        End Set
    End Property



    Public Overrides Function ToString() As String
        Return "Mpfc2MatPtr"
    End Function


    Public Function str() As String(,)
        Dim res(rows - 1, cols - 1) As String
        '        Dim m1 As New mpfc_t
        For i As Integer = 0 To rows - 1
            For j As Integer = 0 To cols - 1
                '                m1 = item(i, j)
                '                Lib_Eigen_Mpfc_GetCoeff2(m1.MpfcPtr, i, j, MpfcMatPtr)
                res(i, j) = item(i, j).ToString()
            Next j
        Next i
        Return res
    End Function



    Public Function mat() As mpfc_t(,)
        Dim res(rows - 1, cols - 1) As mpfc_t
        '        Dim m1 As New mpfc_t
        For i As Integer = 0 To rows - 1
            For j As Integer = 0 To cols - 1
                res(i, j) = item(i, j)
                '                Lib_Eigen_Mpfc_GetCoeff2(res(i, j).MpfcPtr, i, j, MpfcMatPtr)
            Next j
        Next i
        Return res
    End Function


    Public Sub print(Title As String)
        RealMat.print("Real part: " & Title)
        ImagMat.print("Imaginary part: " & Title)
    End Sub



    Public Function inverse() As mpfc2_mat_t
        Dim n As Integer = RealMat.rows
        Dim m3 As New mpfc_mat_t(n,n)
        Dim m4 As New mpfc_mat_t(n,n)
        mpfr_mat.Real2ToComplex(m3, RealMat, ImagMat)
        
        Lib_Eigen_Mpfc_Inverse(m4.MpfcMatPtr, m3.MpfcMatPtr, 0)
        Dim m5 As New mpfc2_mat_t(n,n)
        mpfr_mat.ComplexToReal2(m5.RealMat, m5.ImagMat, m4)

        Return m5
    End Function







    Public Sub resize(ByVal rows As Int32, ByVal cols As Int32)
        RealMat.resize(rows, cols)
        ImagMat.resize(rows, cols)
    End Sub



    Public Sub conservative_resize(ByVal rows As Int32, ByVal cols As Int32)
        RealMat.conservative_resize(rows, cols)
        ImagMat.conservative_resize(rows, cols)
    End Sub




    '
    '
    '    Public Shared Operator =(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_EQ_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '
    '    Public Shared Operator <>(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_NE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '
    '    Public Shared Operator <=(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_LE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '
    '    Public Shared Operator <(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_LT_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '
    '    Public Shared Operator >=(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_GE_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '
    '    Public Shared Operator >(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As Boolean
    '        Return (Lib_Eigen_Mpfc_GT_Count(m1.MpfcMatPtr, m2.MpfcMatPtr) = m1.size)
    '    End Operator
    '
    '


    Public Shared Operator +(ByVal m1 As mpfc2_mat_t) As mpfc2_mat_t
        Dim m3 As New mpfc2_mat_t()
        m3 = m1
        Return m3
    End Operator


    Public Shared Operator -(ByVal m1 As mpfc2_mat_t) As mpfc2_mat_t
        Dim m3 As New mpfc2_mat_t()
        '        mpz.Lib_Mpz_Neg(m3.MpzPtr, m1.MpzPtr)
        Return m3
    End Operator



    '***********************************************************************


    Public Shared Operator +(ByVal M1 As mpfc2_mat_t, ByVal M2 As mpfc2_mat_t) As mpfc2_mat_t
        Dim Res As New mpfc2_mat_t()
        Res.RealMat = M1.RealMat + M2.RealMat
        Res.ImagMat = M1.ImagMat + M2.ImagMat
        Return Res
    End Operator


    Public Shared Operator +(ByVal M1 As mpfc2_mat_t, ByVal m2 As mpfc_t) As mpfc2_mat_t
        Dim Res As New mpfc2_mat_t()
        Res.RealMat = M1.RealMat + m2.real
        Res.ImagMat = M1.ImagMat + m2.imag
        Return Res
    End Operator




    Public Shared Operator -(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As mpfc2_mat_t
        Dim Res As New mpfc2_mat_t()
        Res.RealMat = M1.RealMat - M2.RealMat
        Res.ImagMat = M1.ImagMat - M2.ImagMat
        Return Res
    End Operator


    Public Shared Operator -(ByVal M1 As mpfc2_mat_t, ByVal m2 As mpfc_t) As mpfc2_mat_t
        Dim Res As New mpfc2_mat_t()
        Res.RealMat = M1.RealMat - m2.real
        Res.ImagMat = M1.ImagMat - m2.imag
        Return Res
    End Operator



    ' Wrong! Needs adjustment
    Public Shared Operator *(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As mpfc2_mat_t
        Return ComplexMatMulRealPairs(m1, m2)
    End Operator


    ' Wrong! Needs adjustment. Implement multiplication of complex scalar with real matrix
    Public Shared Operator *(ByVal M1 As mpfc2_mat_t, ByVal m2 As mpfc_t) As mpfc2_mat_t
        Dim Res As New mpfc2_mat_t()
        Res.RealMat = M1.RealMat - m2.real
        Res.ImagMat = M1.ImagMat - m2.imag
        Return Res
    End Operator

    '    Public Function cwiseProduct(x As mpfc2_mat_t) As mpfc2_mat_t
    '        Dim m3 As New mpfc2_mat_t()
    '        Lib_Eigen_Mpfc_Mat_cwiseProduct(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
    '        Return m3
    '    End Function
    '
    '    Public Function dotProduct(x As mpfc2_mat_t) As mpfc2_mat_t
    '        Dim m3 As New mpfc2_mat_t()
    '        Lib_Eigen_Mpfc_MatDotProduct(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
    '        Return m3
    '    End Function



    '    Public Shared Operator /(ByVal m1 As mpfc2_mat_t, ByVal m2 As mpfc2_mat_t) As mpfc2_mat_t
    '        Dim m3 As New mpfc2_mat_t()
    '        Dim m4 As New mpfc2_mat_t()
    '        m4 = m2.inverse()
    '        Lib_Eigen_Mpfc_MatMul(m3.MpfcMatPtr, m1.MpfcMatPtr, m4.MpfcMatPtr)
    '        Return m3
    '    End Operator
    '
    '
    '    Public Shared Operator /(ByVal M1 As mpfc2_mat_t, ByVal m2 As mpfc_t) As mpfc2_mat_t
    '        Dim Res As New mpfc2_mat_t()
    '        Dim T As New mpfc2_mat_t(m2)
    '        Lib_Eigen_Mpfc_Mat_Div_Scalar(Res.MpfcMatPtr, M1.MpfcMatPtr, T.MpfcMatPtr)
    '        Return Res
    '    End Operator
    '
    '    Public Function cwiseQuotient(x As mpfc2_mat_t) As mpfc2_mat_t
    '        Dim m3 As New mpfc2_mat_t()
    '        Lib_Eigen_Mpfc_Mat_cwiseQuotient(m3.MpfcMatPtr, x.MpfcMatPtr, MpfcMatPtr)
    '        Return m3
    '    End Function



End Class


