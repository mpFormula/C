
Imports mpNumerix2

Module Program
    
    
	Sub DemoFmpz()
		Console.WriteLine("Hello Fmpz!")
	    Dim x, y, z, x1 As New mpFmpz
	    Dim s, s2 As String
	    
	    s = "9999999"
	    Fmpz.SetStr(x1, s, 10)
	    Fmpz.Print(x1)
	    Console.WriteLine("")
	    x1 = x1 ^ 2
'	    s2 = Fmpz.Fmpz_Get_Str(10, x1)
	    s2 = x1
        Console.WriteLine(s2)


	    x = 178.345
'	    Fmpz.Fmpz_Set_Ui(x, 7)
	    Fmpz.Mul(y, x, x)
	    Fmpz.Print(x)
	    Console.WriteLine("")
	    
	    Console.Write("A^2 = ")
	    Fmpz.Print(y)
	    
	    z = y
	    Console.WriteLine("")
	    Fmpz.Print(z)
	    
	    
	    y = y + 3
	    Console.WriteLine("")
	    Fmpz.Print(z)
	    Console.WriteLine("")
	    Fmpz.Print(y)
	    
	    Dim i As Int32 = CInt(y)
	    Console.WriteLine("")
	    Console.WriteLine("i: " & i.ToString())
	    Dim d As Double = y
'	    d = y
        Console.WriteLine("")
        
'        d = Fmpz.GetD(y)
        Console.WriteLine("d: " & d.ToString())
        Dim Result As Boolean
'        Result = (x <= y)
        Result = x.EQ(y)
        Console.WriteLine("Result: " & Result.ToString())
	    
	    
	End Sub
	
	
	Sub DemoFmpq()
		Console.WriteLine("Hello Fmpq!")
	    Dim x, y As New mpFmpq
	    
	    Fmpq.SetSi(x, 7, 5)
	    Fmpq.Mul(y, x, x)
	    Fmpq.Print(x)
	    
	    Console.Write("A^2 = ")
	    Fmpq.Print(y)
	End Sub
	
	
	
	Sub DemoArb()
		Console.WriteLine("Hello Arb!")
			
		Dim prec As Int32 = 50
	    Dim x, y As New mpArb
	    
	    Arb.SetSi(x, 7)
	    Arb.Mul(y, x, x, prec)
	    Arb.Print(x, prec)
	    
	    Console.Write("A^2 = ")
	    Arb.Print(y, prec)
	    
	    Arb.ConstPi(x, prec * 3)
	    Arb.Print(x, prec)
	End Sub
	
	
	
	
	Sub DemoAcb()
		Console.WriteLine("Hello Acb!")
			
		Dim prec As Int32 = 50
	    Dim x, y As New mpAcb
	    
	    Acb.SetSi(x, 7)
	    Acb.Mul(y, x, x, prec)
	    Acb.Print(x, prec)
	    
	    Console.Write("A^2 = ")
	    Acb.Print(y, prec)
	    
	    Acb.ConstPi(x, prec * 3)
	    Acb.Print(x, prec)
	End Sub
	
	
	Sub DemoFmpzMat()
		Console.WriteLine("Hello FmpzMat!")
			
	    Dim n As Int32 = 12
	    Dim A, B As New mpFmpzMat(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            Fmpz.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    Fmpz.MatMul(B, A, A)
	    Fmpz.MatPrint(A)
	    
	    Console.Write("A^2 = ")
	    Fmpz.MatPrint(B)
	End Sub
	
	
	Sub DemoFmpqMat()
		Console.WriteLine("Hello FmpqMat!")
			
	    Dim n As Int32 = 12
	    Dim A, B As New mpFmpqMat(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            Fmpq.MatSetSi(A, i, j, 2*i+j, 5)
	        Next
	    Next
	    
	    Fmpq.MatMul(B, A, A)
	    Fmpq.MatPrint(A)
	    
	    Console.Write("A^2 = ")
	    Fmpq.MatPrint(B)
	End Sub
	
	
		
	Sub DemoArbMat()
		Console.WriteLine("Hello ArbMat!")
			
		Dim prec As Int32 = 50
	    Dim n As Int32 = 12
	    Dim A, B As New mpArbMat(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            Arb.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    Arb.MatMul(B, A, A, prec)
	    Arb.MatPrint(A, prec)
	    
	    Console.Write("A^2 = ")
	    Arb.MatPrint(B, prec)
	End Sub


		
	Sub DemoAcbMat()
		Console.WriteLine("Hello AcbMat!")
			
		Dim prec As Int32 = 50
	    Dim n As Int32 = 2
	    Dim A, B As New mpAcbMat(n, n)
	    
	    For i As int32 = 0 To n-1
	        For j As int32 = 0 To n-1
	            Acb.MatSetUi(A, i, j, 2*i+j)
	        Next
	    Next
	    
	    Acb.MatMul(B, A, A, prec)
	    Acb.MatPrint(A, prec)
	    
	    Console.Write("A^2 = ")
	    Acb.MatPrint(B, prec)
	End Sub

	
	Sub Main()
	    DemoFmpz()
	    Console.WriteLine("")
		Console.Write("Press any key to continue . . . ")
		Console.ReadKey(True)
	End Sub
	

	
	
	
End Module
