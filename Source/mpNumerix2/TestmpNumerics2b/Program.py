
#Load CLR
import clr
import sys
import System
from System import Console 

sys.path.append(r"E:\Extra\mpFormulaTDM\mpFormulaC\Source\mpNumerix2\mpNumerix2\bin\Release")

#Load the mpNumerics library
clr.AddReference ("mpNumerix2.dll")
from mpNumerix2 import mp, mpNum

Console.WriteLine("Hello World!")

mp = mp()
mp.SetPrecision(40)
MatrixA = mpNum()
MatrixB = mpNum()
MatrixC = mpNum()

n = 4
mp.SetRandomMatrix(n, n, MatrixA)
mp.PrintMatrix("Here is the matrix A:", MatrixA)

mp.GetMatrixInverse(MatrixB, MatrixA, 0)
mp.PrintMatrix("Here is the matrix B:", MatrixB)

mp.GetMatrixProduct(MatrixA, MatrixB, MatrixC)
mp.PrintMatrix("Here is the product C = A * B:", MatrixC)

#Result = 55
#Console.WriteLine("Result: " + Result.ToString())
#Result = mp.GammaAmath(5)
#Console.WriteLine("ResultGamma: " + Result.ToString())

#i = 1
#while i <= 10:
#	Result = mp.StdDoubleSum(5 * i, 6)
#	Console.WriteLine("Result: " + Result.ToString())
#	i = i + 1
	
Console.Write("Press any key to continue . . . ")
Console.ReadKey(True)