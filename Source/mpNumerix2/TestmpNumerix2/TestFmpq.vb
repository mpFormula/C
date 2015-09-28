
Imports mpNumerix2


Module TestFmpq
    
   
'	
	Sub DemoFmpq()
		Console.WriteLine("Hello Fmpq!")
	    Dim x, y As New fmpq_t
	    
	    x = "45/67"
	    y = x * x
	    Console.WriteLine("y: " & y)
	End Sub
	
	
		
	Sub DemoFmpqMat()
		Console.WriteLine("Hello FmpqMat!")
			
	    Dim n As Int32 = 12
	    Dim A, B As New fmpz_mat_t(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            fmpz_mat.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    fmpz_mat.MatMul(B, A, A)
	    fmpz_mat.MatPrint(A)
	    
	    Console.Write("A^2 = ")
	    fmpz_mat.MatPrint(B)
	End Sub
	
    Sub FmpqMain()
        DemoFmpq()
        DemoFmpqMat()
	End Sub
	

	
	
End Module
