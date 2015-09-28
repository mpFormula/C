Imports mpNumerix2

Module TestMpz
    
    Sub DemoMpz()
		Console.WriteLine("Hello Mpz!")
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
	
	    
    
	Sub MpzMain()
	    DemoMpz()
	End Sub

	
End Module
