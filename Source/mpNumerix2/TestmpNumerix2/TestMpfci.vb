
Imports mpNumerix2


Module TestMpfci
    
    
    Sub DemoMpfci()
		Console.WriteLine("Hello Mpfci!")
	    mpfr.set_default_prec(100)		
	    Dim x, y, z, x1 As New mpfci_t
	    Dim ui32 As UInt32
'	    Dim ui32, ui32a As UInt32
'	    Dim si32, si32a As Int32
        ui32 = 37
	    x = New mpfci_t( ui32)
	    Console.WriteLine("x: " & x.real.ToString() & " + " & x.imag.ToString() & "j")
	    Console.WriteLine("x: " & x.ToString())
	    y.real = New mpfi_t(ui32) 
	    Console.WriteLine("y_re: " & y.real)
	    
    End Sub
    
 	
	
	Sub MpfciMain()
	    DemoMpfci()
	End Sub
    
	
	
End Module
