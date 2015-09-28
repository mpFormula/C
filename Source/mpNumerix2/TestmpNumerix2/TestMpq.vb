
Imports mpNumerix2


Module TestMpq
    
   
'	
	Sub DemoMpq()
		Console.WriteLine("Hello Mpq!")
	    Dim x, y As New fmpq_t
	    
	    x = "45/67"
	    y = x * x
	    Console.WriteLine("y: " & y)
	End Sub
	
    
    
	Sub MpqMain()
	    DemoMpq()
	End Sub


	
	
End Module
