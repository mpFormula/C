Imports mpNumerix2

Module TestMpfr
    
    
    Sub DemoMpfr()
		Console.WriteLine("Hello Mpfr!")
	    mpfr.set_default_prec(300)		
		Dim x, y, z, x1 As New mpfr_t
	    Dim ui64, ui64a As UInt64
	    Dim si64, si64a As Int64

	    ui64 = UInt64.MaxValue - CULng(1000000000) '18446744073709551615
	    si64 = Int64.MaxValue
	    Console.WriteLine(UInt64.MaxValue)
	    Console.WriteLine(ui64)	    
	    x = New mpfr_t( ui64)
	    Console.WriteLine("x: " & x)
	    ui64a = CULng(x)
	    Console.WriteLine("u: " & ui64a.ToString())
	    
	    Console.WriteLine(Int64.MaxValue)
	    Console.WriteLine(si64)	    
	    y = New mpfr_t( si64)
	    Console.WriteLine("y: " & y)
	    si64a = CLng(y)
	    Console.WriteLine("y: " & si64a.ToString())
	    
    End Sub
    
    
    
    Sub DemoMpfrMat()
		Console.WriteLine("Hello MpfrMat!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfr_t()	    
	    Dim x1, y1, z1, x2, z2 As New mpfr_mat_t
	    x1.random(4, 4)
	    x1.Print("x1: ")
	    
	    x2 = x1
	    x2.Print("x2: ")
	    
	    y1 = x1.Inverse()
	    y1.Print("y1: ")
	    z1 = x1 * y1
	    z1.Print("z1: ")
	    
	    z2 = x1/x2
	    z2.Print("z2: ")
	    
	    Coeff = x1(1,1)
	    Console.WriteLine("Coeff: " & Coeff)
        Coeff2 = 1.11111111111
	    Console.WriteLine("Coeff2: " & Coeff2)
	    y1(1,1) = Coeff2
	    y1.Print("y1: ")
	    
	    
	    Console.WriteLine("Rows: " & x1.Rows)
	    Console.WriteLine("Cols: " & x1.Cols)
	    Console.WriteLine("Size: " & x1.Size)
	    
	    Dim count As UInt32
	    count = y1.GT_count(x1)
	    
	    Console.WriteLine("GT: " & count)
	    
	    z1 = x1.block(0,0,1,1)
	    z1.Print("z1: ")
	    Dim A As New mpfr_mat_t(3,5)
	    A.Print("A: ")
	    A.resize(2,4)
	    A.Print("A: ")
	    x1.conservative_resize(2,5)
	    x1.Print("x1: ")
	    Dim b0 As New mpfr_t
	    b0 = "0.1"
	    Dim B As New mpfr_mat_t(b0)
	    B.Print("B: ")
	    Dim C As New mpfr_mat_t("0.2")
	    C.Print("C: ")
	    
    End Sub
    
    
    
    Sub DemoMpfrMatSolve()
		Console.WriteLine("Hello MpfrMat!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfr_t()	    
	    Dim A, b, X, b2, Diff As New mpfr_mat_t
	    A.random(4, 4)
	    A.Print("A: ")
	    
	    B.random(4, 4)
	    B.Print("B: ")
	    
	    X = A.solve(b)
'	    X = A.SolveFullPivLU(b)
'	    X = A.SolveLDLT(b)  '' NEEDS TO BE SYMMETRIC !!!!
'	    X = A.SolveColPivQR(b)
'	    X = A.SolveFullPivQR(b)
'	    X = A.SolveSVD(b)
	    
	    X.Print("X: ")
	    
	    b2 = A * X
	    b2.Print("b2: ")
	    
	    Diff = b - b2
	    Diff.Print("Diff: ")
    End Sub
    
    
    Sub DemoMpfrMatInverse()
		Console.WriteLine("Hello MpfrMat!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfr_t()	    
	    Dim x1, y1, z1, x2, z2 As New mpfr_mat_t
	    x1.random(4, 4)
	    x1.Print("x1: ")
	    
	    x2 = x1
	    x2.Print("x2: ")
	    
	    y1 = x1.Inverse()
'	    y1 = x1.InverseFullPivLU()
'	    y1 = x1.InverseColPivQR()
'	    y1 = x1.InverseFullPivQR()
	    
	    
	    
	    y1.Print("y1: ")
	    z1 = x1 * y1
	    z1.Print("z1: ")
	    
	    Dim det As New mpfr_t
	    det = z1.Det()
'	    det.Print()
	    Console.WriteLine("det(z1): " & det)

	    Dim rank As Integer = z1.Rank
	    Console.WriteLine("rank(z1): " & rank)
	    
    End Sub    
    
    
    Sub DemoMpfrMatSolveSymmetric()
		Console.WriteLine("Hello MpfrMatSymmetric!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfr_t()	    
	    Dim A, b, X, b2, Diff As New mpfr_mat_t
	    A.RandomSymmetric(4, 4)
	    A.Print("A: ")
	    
	    B.Random(4, 4)
	    B.Print("B: ")
	    
'	    X = A.solve(b)
'	    X = A.SolveFullPivLU(b)
	    X = A.SolveLDLT(b)  '' MATRIX A NEEDS TO BE SYMMETRIC !!!!
'	    X = A.SolveColPivQR(b)
'	    X = A.SolveFullPivQR(b)
'	    X = A.SolveSVD(b)
	    
	    X.Print("X: ")
	    
	    b2 = A * X
	    b2.Print("b2: ")
	    
	    Diff = b - b2
	    Diff.Print("Diff: ")
    End Sub
    
    
    
    Sub DemoMpfrMatSymmetricEigenvalues()
		Console.WriteLine("Hello MpfrMatSymmetric!")
		mpfr.set_default_prec(300)		
		Dim n As Int32 = 4
		Dim d As New mpfr_t()	    
	    Dim A, B, X, b2, Diff As New mpfr_mat_t
	    A.RandomSymmetric(n, n)
'	    A.Print("A: ")
	    B = A.SymmetricEigenvalues()
	    B.Print("B: ")
	    
	    For i As Int32= 0 To n-1
	    X = A.SubtractFromDiagonal(B(i,0))
'	    X.print("X: ")
	    d = X.Det()
	    Console.WriteLine("Det(A - lambda" & i & "): " & d)
	    next
    End Sub
    
    
    
	Sub MpfrMain()
'	    DemoMpfr()
        DemoMpfrMat()
'    DemoMpfrMatSolve()
'    DemoMpfrMatInverse()
'    DemoMpfrMatSolveSymmetric
'    DemoMpfrMatSymmetricEigenvalues
	End Sub
    
    
    
    
   
End Module
