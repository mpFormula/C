
Imports mpNumerix64

Module Program
	
	Sub Main()
		Console.WriteLine("Hello World!")
			
	    Dim mp As New mp
	    mp.SetPrecision(40)
	    Dim MatrixA As New mpNum, MatrixB As New mpNum, MatrixC As New mpNum
	    
	    Dim n As Int32 = 4
	    mp.SetRandomMatrix(n, n, MatrixA)
	    mp.PrintMatrix("Here is the matrix A:", MatrixA)
	
	    mp.GetMatrixInverse(MatrixB, MatrixA, 0)
	    mp.PrintMatrix("Here is the matrix B:", MatrixB)
	
	    mp.GetMatrixProduct(MatrixA, MatrixB, MatrixC)
	    mp.PrintMatrix("Here is the product C = A * B:", MatrixC)
	
	
	    Dim Result As Double = 55
	    Console.WriteLine("Result: " & Result.ToString())
			
	    Result = mp.GammaAmath(5)
	    Console.WriteLine("ResultGamma: " & Result.ToString())
			
		For i As Long =1 To 10
		Result = mp.StdDoubleSum(5*i,6)
		Console.WriteLine("Result: " & Result.ToString())
		Next i
			
		Console.Write("Press any key to continue . . . ")
		Console.ReadKey(True)
	End Sub
	
End Module
