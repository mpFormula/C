
#Load CLR
import clr
import sys
import System
from System import Console 

#sys.path.append(r"I:\Data\mpFormulaTDM\mpFormulaC\Source\mpNumerix2\mpNumerix2\bin\Release")

sys.path.append(r"C:\Extra\mpFormulaTDM\mpFormulaC\Source\mpNumerix2\mpNumerix2\bin\Release")


#Load the mpNumerics library
clr.AddReference ("mpNumerix2.dll")
from mpNumerix2 import *

Console.WriteLine("Hello World!")

Console.WriteLine("Hello AcbMat!")
prec = 50
n = 2
A = mpAcbMat(n, n)
B = mpAcbMat(n, n)
i = 0
while i <= n - 1:
    j = 0
    while j <= n - 1:
        Acb.MatSetUi(A, i, j, 2 * i + j)
        j += 1
    i += 1
Acb.MatMul(B, A, A, prec)
Acb.MatPrint(A, prec)
Console.Write("A^2 = ")
Acb.MatPrint(B, prec)


Console.Write("Press any key to continue . . . ")
Console.ReadKey(True)