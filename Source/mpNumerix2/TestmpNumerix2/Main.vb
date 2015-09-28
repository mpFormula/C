
Module Program
	
	Sub Main()
	    
	    Console.BufferHeight = 10000      'Int16.MaxValue -1
	    Console.BufferWidth = 400
	    Console.ForegroundColor = ConsoleColor.Black
        Console.BackgroundColor = ConsoleColor.White

        Console.Clear()

	    
'	    AcbMain()
'	    ArbMain()
'	    FmpqMain()
'	    FmpzMain()
	    
'	    MpdMain()
'	    MpdcMain()

'	    MpfcMain()
'	    MpfciMain()
'	    MpfiMain()
'	    MpfrMain()
'	    MpqMain()
	    MpzMain()

        Console.WriteLine("Press the key q to exit . . . ")
        Console.SetCursorPosition(0,0)
'	    Dim m1 As String = "The current window width is {0}, and the current window height is {1}."
		Dim info As ConsoleKeyInfo
		Dim ch As String
		ch = ""
		While (ch <> "q")
    		info = Console.ReadKey(True)
    		ch = info.KeyChar.ToString()
'            Console.WriteLine(m1, Console.WindowWidth, Console.WindowHeight)
		End While
		
	End Sub
	
End Module
