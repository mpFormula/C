Imports mpNumerix2

Module TestFmpz
    
    Sub DemoFmpz()
		Console.WriteLine("Hello Fmpz!")
	    Dim x, y, z, x1 As New fmpz_t
	    Dim s, s2 As String
	    Dim ui64, ui64a As UInt64
	    Dim si64, si64a As Int64
	    
	    ui64 = UInt64.MaxValue 
	    Console.WriteLine(ui64)
	    x= ui64
	    Console.WriteLine("x: " & x)
	    ui64a = CULng(x)
	    Console.WriteLine("u: " & ui64a.ToString())
	    
	    si64 = Int64.MinValue
	    Console.WriteLine(si64)	    
	    y= si64
	    Console.WriteLine("y: " & y)
	    si64a = CLng(y)
	    Console.WriteLine("y: " & si64a.ToString())
	    z = y
	    z = 1 + z
	    s = "9999999"
	    x1 = s
'	    Fmpz.Print(x1)
	    Console.WriteLine("")
	    x1 = x1 ^ 2
	    s2 = x1
        Console.WriteLine(s2)
        z = mp4.fmpzNeg(4)

        x = 178.345
        x = x * x
        Console.WriteLine("x: " & x)
        Console.WriteLine("" & x) 
	End Sub
	
	Sub DemoFmpzMat()
		Console.WriteLine("Hello FmpzMat!")
			
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
	
	
	
	Sub FmpzMain()
        DemoFmpz()
        DemoFmpzMat()
	End Sub

	
	
End Module
