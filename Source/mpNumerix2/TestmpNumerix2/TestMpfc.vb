
Imports mpNumerix2


Module TestMpfc
    
                
    Sub DemoMpfcMat()
		Console.WriteLine("Hello MpfcMat!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfc_t()	    
	    Dim x1, y1, z1, x2, z2 As New mpfc_mat_t
	    x1 = mpfc_mat.RandomMatrix(4, 4)
	    x1.Print("x1: ")
	    
	    x2 = x1
	    x2.Print("x2: ")
	    
	    y1 = x1.Inverse()
	    y1.Print("y1: ")
	    z1 = x1 * y1
	    z1.Print("z1: ")
	    
	    z2 = x1/x2
	    z2.Print("z2: ")
	    
	    Coeff = x1(0,0)
	    Console.WriteLine("Coeff: " & Coeff)
	    Coeff2 = 999
	    Console.WriteLine("Coeff2: " & Coeff2)
	    z2(0,0) = Coeff2
	    z2.Print("z2: ")
    End Sub
    
                
    Sub DemoMpfc2Mat()
		Console.WriteLine("Hello Mpfc2Mat!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfc_t()	    
		Dim x1, y1, z1, x2, z2 As New mpfc2_mat_t
		x1.RealMat.random(4,4)
		x1.ImagMat.random(4,4)
		x1.print("New complex matrix x1")
		
		y1.RealMat.random(4,4)
		y1.ImagMat.random(4,4)
		y1.print("New complex matrix y1")
		
		z1 = x1 + y1
		z1.print("New complex matrix z1 = x1 + y1")
		
			    
	    Coeff = x1(0,0)
	    Console.WriteLine("Coeff: " & Coeff)
	    Coeff2 = 999
	    Console.WriteLine("Coeff2: " & Coeff2)
	    z1(0,0) = Coeff2
	    z1.Print("z2: ")

		
    End Sub
    
    
                
    Sub DemoMpfcMatBoth()
		Console.WriteLine("Hello MpfcMatBoth!")
		mpfr.set_default_prec(100)		
		Dim Coeff, Coeff2 As New mpfc_t()	    
		Dim x1 As New mpfc_mat_t
		Dim x1_re, x1_im As New mpfr_mat_t(4,4)
		Dim y1 As New mpfc_mat_t(4,4)

	    x1 = mpfc_mat.RandomMatrix(4, 4)
	    x1.Print("x1: ")
	    
	    mpfr_mat.ComplexToReal2(x1_re, x1_im, x1)
	    x1_re.Print("x1_re: ")
	    x1_im.Print("x1_im: ")
	    
	    Console.WriteLine("prec1: " & prec.ToString())
	    
	    
	    Dim prec1 As Integer = x1_re(1,1).prec
	    
	    y1 = mpfc_mat.RandomMatrix(4, 4)
	    Dim prec2 As Integer = y1(1,1).prec
	    Console.WriteLine("prec2: " & prec.ToString())
	    
	    mpfr_mat.Real2ToComplex(y1, x1_re, x1_im)
	    
	    y1.Print("y1: ")
	    
    End Sub
    
    
    Sub DemoMpfcMatInverse()
		Console.WriteLine("Hello MpfcMat!")
		mpfr.set_default_prec(100)	
		Dim n As Integer = 4
		
		Dim A, B, C As New mpfc2_mat_t(n,n)
		A.RealMat.random(n,n)
		A.ImagMat.random(n,n)
		A.print("A: ")
		
		B = A.inverse()
		B.print("B (inverse of A): ")
		
		C = A * B
		C.print("C (= A * B): ")
		
		Dim x1, y1, z1, x2, z2 As New mpfc_mat_t
		x1 = mpfc_mat.RandomMatrix(n, n)
		mpfr_mat.Real2ToComplex(x1, A.RealMat, A.ImagMat)
		
	    x1.Print("x1: ")
	    y1 = x1.Inverse()
	    y1.Print("y1 (inverse of x1): ")
	    
		z1 = x1 * y1
		z1.print("z1 (= x1 * y1): ")
		
		Dim d As mpfc_t = z1.Det()
		Console.WriteLine("Det(z1): " & d)

    End Sub
    
    
    Sub DemoMpfcMatEigenvalues()
		Console.WriteLine("Hello MpfcMatEigenvalues!")
		mpfr.set_default_prec(400)		
		Dim n As Int32 = 44
		Dim d As New mpfc_t()	    
		Dim A, B, X As New mpfc_mat_t(n,n)
		Dim A_re, A_im As New mpfr_mat_t(n,n)
		Dim B_re, B_im As New mpfr_mat_t(n,n)
		Dim X_re, X_im As New mpfr_mat_t(n,n)
		
	    A = mpfc_mat.RandomMatrix(n, n)
	    A.Print("A: ")
	    
	    mpfr_mat.ComplexToReal2(A_re, A_im, A)
'	    A_re.print("A_re: ")
'	    A_im.print("A_im: ")
	    
	    
	    B = A.Eigenvalues()
	    B.Print("B: ")
	    
	    mpfr_mat.ComplexToReal2(B_re, B_im, B)
'	    B_re.print("B_re: ")
'	    B_im.print("B_im: ")
	    
	    For i As Int32= 0 To n-1
'	    For i As Int32= 0 To 0
	    X_re = A_re.SubtractFromDiagonal(B_re(i,0))
	    X_im = A_im.SubtractFromDiagonal(B_im(i,0))
	    
'	    X_re.print("X_re: ")
'	    X_im.print("X_im: ")
	    
	    mpfr_mat.Real2ToComplex(X, X_re, X_im)
'	    X.print("X: ")
	    d = X.Det()
	    Console.WriteLine("Det(A - lambda" & i & "): " & d)
	    next
	    
	    
	    
'	    For i As Int32= 0 To n-1
'For i As Int32= 0 To 0
'    
'
'    
'	    X = A.SubtractFromDiagonal(B(i,0))
'	    X.print("X: ")
'	    d = X.Det()
'	    Console.WriteLine("Det(A - lambda" & i & "): " & d)
'	    next

    End Sub
    
    
	Sub MpfcMain()
	    DemoMpfcMat()
'        DemoMpfcMatBoth()
'        DemoMpfcMatInverse()
'	    DemoMpfc2Mat()
'        DemoMpfcMatEigenvalues()
	End Sub
    
    
    
End Module

