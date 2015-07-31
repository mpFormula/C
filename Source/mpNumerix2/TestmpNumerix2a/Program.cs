
using System;
using mpNumerix2;

namespace TestCSharp2
{
    class Program
    {
        
        static void Demo1()
        {
            Console.WriteLine("Hello AcbMat!");
    
    		Int32 prec = 50;
    		Int32 n = 2;
    		mpAcbMat A = new mpAcbMat(n, n);
    		mpAcbMat B = new mpAcbMat(n, n);
    
    		for (Int32 i = 0; i <= n - 1; i++) {
    			for (Int32 j = 0; j <= n - 1; j++) {
    				Acb.MatSetUi(A, i, j, 2 * i + j);
    			}
    		}
    
    		Acb.MatMul(B, A, A, prec);
    		Acb.MatPrint(A, prec);
    		Console.Write("A^2 = ");
    		Acb.MatPrint(B, prec);

        }
        
        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Demo1();
            Console.Write("Press any key to continue . . . ");
            Console.ReadKey(true);
        }
    }
}