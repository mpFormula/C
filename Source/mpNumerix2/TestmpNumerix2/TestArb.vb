
Imports mpNumerix2


Module TestArb
    
	Sub DemoArb()
		Console.WriteLine("Hello Arb!")
		Dim x, y As New arb_t
		Console.WriteLine("prec: " & mp4.getprec())
	    x = 178.341
        x = x * x
        Console.WriteLine("x: " & x)
        
        mp4.SetPrec(200)
		Console.WriteLine("prec: " & mp4.getprec())
	    x = 178.341
        x = x * x
        Console.WriteLine("x: " & x)


		Console.WriteLine("prec: " & mp4.getprec())
	    x = "178.341"
        x = x * x
        Console.WriteLine("x: " & x)
        
        mp4.SetPrec(200)
		Console.WriteLine("prec: " & mp4.getprec())
	    x = "178.341"
        x = x * x
        Console.WriteLine("x: " & x)
        
	End Sub
	
		
	Sub DemoArbMat()
		Console.WriteLine("Hello ArbMat!")
			
		Dim prec As Int32 = 50
	    Dim n As Int32 = 12
	    Dim A, B As New arb_mat_t(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            arb_mat.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    arb_mat.MatMul(B, A, A, prec)
	    arb_mat.MatPrint(A, prec)
	    
	    Console.Write("A^2 = ")
	    arb_mat.MatPrint(B, prec)
	End Sub

		
	
    Sub ArbMain()
        DemoArb()
        DemoArbMat()
	End Sub

	
	
End Module
