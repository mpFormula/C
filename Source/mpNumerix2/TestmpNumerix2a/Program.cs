using System;
using mpNumerix2;

static class Program
{
	public static void Main()
	{
		Console.WriteLine("Hello World!");

		mp mp = new mp();
		mp.SetPrecision(40);
		mpNum MatrixA = new mpNum();
		mpNum MatrixB = new mpNum();
		mpNum MatrixC = new mpNum();

		Int32 n = 4;
		mp.SetRandomMatrix(n, n, MatrixA);
		mp.PrintMatrix("Here is the matrix A:", MatrixA);

		mp.GetMatrixInverse(MatrixB, MatrixA, 0);
		mp.PrintMatrix("Here is the matrix B:", MatrixB);

		mp.GetMatrixProduct(MatrixA, MatrixB, MatrixC);
		mp.PrintMatrix("Here is the product C = A * B:", MatrixC);


		double Result = 55;
		Console.WriteLine("Result: " + Result.ToString());

//		Result = mp.GammaAmath(5);
//		Console.WriteLine("ResultGamma: " + Result.ToString());


//		for (long i = 1; i <= 10; i++) {
//			Result = mp.StdDoubleSum(5 * i, 6);
//			Console.WriteLine("Result: " + Result.ToString());
//		}

		Console.Write("Press any key to continue . . . ");
		Console.ReadKey(true);
	}
}
