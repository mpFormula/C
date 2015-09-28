Imports mpNumerix2

Module TestMpd
    
    
    Sub DemoMpd()
		Console.WriteLine("Hello Mpd!")
	    mpfr.set_default_prec(300)		
		Dim x, y, z, x1 As New mpd_t
	    Dim ui64, ui64a As UInt64
	    Dim si64, si64a As Int64

	    ui64 = UInt64.MaxValue - CULng(1000000000) '18446744073709551615
	    si64 = Int64.MaxValue
	    Console.WriteLine(UInt64.MaxValue)
	    Console.WriteLine(ui64)	    
	    x = New mpd_t( ui64.ToString())
	    Console.WriteLine("x: " & x)
	    ui64a = CULng(x)
	    Console.WriteLine("u: " & ui64a.ToString())
	    
	    Console.WriteLine(Int64.MaxValue)
	    Console.WriteLine(si64)	    
	    y = New mpd_t( si64.ToString())
	    Console.WriteLine("y: " & y)
	    si64a = CLng(y)
	    Console.WriteLine("y: " & si64a.ToString())
	    
    End Sub
    
 	
	
	Sub MpdMain()
	    DemoMpd()
	End Sub
   
   
   
End Module
