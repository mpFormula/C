
Imports mpNumerix2


Module TestAcb
  	
	
	Sub DemoAcb()
		Console.WriteLine("Hello Acb!")
			
		Dim prec As Int32 = 50
	    Dim x, y As New acb_t
	    
	    acb.SetSi(x, 7)
	    acb.Mul(y, x, x, prec)
	    acb.Print(x, prec)
	    
	    Console.Write("A^2 = ")
	    acb.Print(y, prec)
	    
	    acb.ConstPi(x, prec * 3)
	    acb.Print(x, prec)
	End Sub
	
	

		
	Sub DemoAcbMat()
		Console.WriteLine("Hello AcbMat!")
			
		Dim prec As Int32 = 50
	    Dim n As Int32 = 2
	    Dim A, B As New acb_mat_t(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            acb_mat.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    acb_mat.MatMul(B, A, A, prec)
	    acb_mat.MatPrint(A, prec)
	    
	    Console.Write("A^2 = ")
	    acb_mat.MatPrint(B, prec)
	End Sub
	
	
    Sub AcbMain()
        DemoAcb()
        DemoAcbMat()
	End Sub

	
	
End Module
