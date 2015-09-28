
Imports System
Imports System.IO
Imports System.Reflection

Public Module mp4


#Region "External Functions Declarations"

  Private Declare Function LoadLibrary Lib "KERNEL32.dll" Alias "LoadLibraryA" (ByVal lpFile As String) As IntPtr

#End Region


#Region "Helper Functions"

  Private  Function DLLDir() As String
	Dim codeBase As String = Assembly.GetExecutingAssembly().CodeBase
	Dim uri1 As New UriBuilder(codeBase)
	Dim path1 As String = Uri.UnescapeDataString(uri1.Path)
	Dim DLLPath As String = Path.GetDirectoryName(path1) 
	Return DLLPath
  End Function


  Friend  Function HasLibraryNumC() As Double
    Static Result As Double = 0
    If Result = 0 Then
      Dim DLLPath As String = DLLDir()
'      MsgBox(DLLPath)
      Directory.SetCurrentDirectory(DLLPath)
      Dim FName As String = DLLPath & "\mpNumC.dll"      
      Result = CDbl(LoadLibrary(FName))
    End If
    If Result = 0 Then
      MsgBox("Could not load supporting library mpNumC!")
      Return 0
    Else
      Return 1
    End If
  End Function
  
#End Region


  Sub New()
      Init()
  End Sub
  
  
  Sub Init()
    Dim Result As Double = HasLibraryNumC()
'    Console.WriteLine("New NumC 32: ", Result.ToString())      
  End Sub
  
  
  Function getprec() As Int32
      Return mpfr.get_default_prec()
  End Function
'

  Sub SetPrec(prec As Int32) 
      mpfr.set_default_prec(prec)
  End Sub


Function getDPS() As UInt32
    
      Return CUInt(mpfr.get_default_prec()/3.33)
  End Function


Function fmpzNeg(x As fmpz_t) As fmpz_t
    Dim z As fmpz_t
    z=0
    Lib_Fmpz_Neg(z.FmpzPtr, x.FmpzPtr)
    Return z
End Function

End Module











