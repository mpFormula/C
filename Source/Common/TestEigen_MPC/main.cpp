
#include <iostream>
#include <sstream>
#include <complex>
#include "mprealsupport.h"
#include <mpc_mpreal.h>
//#include <Eigen/LU>
//#include <Eigen/Eigenvalues>



using namespace std;
using namespace mpfr;
//using namespace Eigen;
//
//typedef Matrix<mpreal,Dynamic,Dynamic>  MatrixXmpfr;
//typedef Matrix<complex<mpreal>,Dynamic,Dynamic>  MatrixXmpc;

//
//void test_mpreal_support()
//{
//  std::cout  << "Starting test_mpreal_support()  "  << "\n";
//  // set precision to 256 bits (double has only 53 bits)
//  mpreal::set_default_prec(256);
//  typedef Matrix<mpreal,Eigen::Dynamic,Eigen::Dynamic> MatrixXmp;
//
//  std::cout  << "epsilon =         " << NumTraits<mpreal>::epsilon() << "\n";
//  std::cout  << "dummy_precision = " << NumTraits<mpreal>::dummy_precision() << "\n";
//  std::cout  << "highest =         " << NumTraits<mpreal>::highest() << "\n";
//  std::cout  << "lowest =          " << NumTraits<mpreal>::lowest() << "\n";
//
//  int s = 3;
//  MatrixXmp A = MatrixXmp::Random(s,s);
//  MatrixXmp B = MatrixXmp::Random(s,s);
//  MatrixXmp S = A.adjoint() * A;
//  std::cout  << "Matrix A:  "  << "\n";
//  std::cout  <<  A  << "\n";
//  std::cout  << "Matrix B  "  << "\n";
//  std::cout  <<  B  << "\n";
//  std::cout  << "Matrix S  "  << "\n";
//  std::cout  <<  S  << "\n";
//
//  MatrixXmp X;
//// Cholesky
//  X = S.selfadjointView<Lower>().llt().solve(B);
////    VERIFY_IS_APPROX((S.selfadjointView<Lower>()*X).eval(),B);
//  std::cout  << "Matrix X, Cholesky  "  << "\n";
//  std::cout  <<  X  << "\n";
//
//// partial LU
//  X = A.lu().solve(B);
////    VERIFY_IS_APPROX((A*X).eval(),B);
//  std::cout  << "Matrix X, partial LU  "  << "\n";
//  std::cout  <<  X  << "\n";
//
//// symmetric eigenvalues
//  SelfAdjointEigenSolver<MatrixXmp> eig(S);
////    VERIFY_IS_EQUAL(eig.info(), Success);
////    VERIFY( (S.selfadjointView<Lower>() * eig.eigenvectors()).isApprox(eig.eigenvectors() * eig.eigenvalues().asDiagonal(), NumTraits<mpreal>::dummy_precision()*1e3) );
//  std::cout  << "eig(s)  "  << "\n";
//  std::cout  <<  (S.selfadjointView<Lower>() * eig.eigenvectors())  << "\n";
//  std::cout  << "eig(s)  "  << "\n";
//  std::cout  <<  eig.eigenvectors() * eig.eigenvalues().asDiagonal()  << "\n";
//}
//
//
//
//void t1()
//{
//   using mpfr::mpreal;
//    using std::cout;
//    using std::endl;
//
//    // Required precision of computations in decimal digits
//    // Play with it to check different precisions
//    const int digits = 50;
//
//    // Setup default precision for all subsequent computations
//    // MPFR accepts precision in bits - so we do the conversion
//    mpreal::set_default_prec(mpfr::digits2bits(digits));
//
//    // Compute all the vital characteristics of mpreal (in current precision)
//    // Analogous to lamch from LAPACK
//    const mpreal one         =    1.0;
//    const mpreal zero        =    0.0;
//    const mpreal eps         =    std::numeric_limits<mpreal>::epsilon();
//    const int    base        =    std::numeric_limits<mpreal>::radix;
//    const mpreal prec        =    eps * base;
//    const int bindigits      =    std::numeric_limits<mpreal>::digits(); // eqv. to mpfr::mpreal::get_default_prec();
//    const mpreal rnd         =    std::numeric_limits<mpreal>::round_error();
//    const mpreal maxval      =    std::numeric_limits<mpreal>::max();
//    const mpreal minval      =    std::numeric_limits<mpreal>::min();
//    const mpreal small       =    one / maxval;
//    const mpreal sfmin       =    (small > minval) ? small * (one + eps) : minval;
//    const mpreal round       =    std::numeric_limits<mpreal>::round_style();
//    const int    min_exp     =    std::numeric_limits<mpreal>::min_exponent;
//    const mpreal underflow   =    std::numeric_limits<mpreal>::min();
//    const int    max_exp     =    std::numeric_limits<mpreal>::max_exponent;
//    const mpreal overflow    =    std::numeric_limits<mpreal>::max();
//
//    // Additionally compute pi with required accuracy - just for fun :)
//    const mpreal pi          =    mpfr::const_pi();
//
//    cout.precision(digits);    // Show all the digits
//    cout << "pi         =    "<<    pi          << endl;
//    cout << "eps        =    "<<    eps         << endl;
//    cout << "base       =    "<<    base        << endl;
//    cout << "prec       =    "<<    prec        << endl;
//    cout << "b.digits   =    "<<    bindigits   << endl;
//    cout << "rnd        =    "<<    rnd         << endl;
//    cout << "maxval     =    "<<    maxval      << endl;
//    cout << "minval     =    "<<    minval      << endl;
//    cout << "small      =    "<<    small       << endl;
//    cout << "sfmin      =    "<<    sfmin       << endl;
//    cout << "1/sfmin    =    "<<    1 / sfmin   << endl;
//    cout << "round      =    "<<    round       << endl;
//    cout << "max_exp    =    "<<    max_exp     << endl;
//    cout << "min_exp    =    "<<    min_exp     << endl;
//    cout << "underflow  =    "<<    underflow   << endl;
//    cout << "overflow   =    "<<    overflow    << endl;
//
//}
//
//
//
//std::complex<mpreal> operator_mpc(std::complex<mpreal> z){
//    std::complex<mpreal> y;
// //   unsigned long int ui = 4;
//    double ui = 4.6;
//    y = z + ui;
// //   y = z - ui;
//    return y;
//}
//

//
//void t2()
//{
//MatrixXcf A = MatrixXcf::Random(4,4);
//cout << "Here is a random 4x4 matrix, A:" << endl << A << endl << endl;
//
//ComplexEigenSolver<MatrixXcf> ces;
//ces.compute(A);
//cout << "The eigenvalues of A are:" << endl << ces.eigenvalues() << endl;
//cout << "The matrix of eigenvectors, V, is:" << endl << ces.eigenvectors() << endl << endl;
//
//complex<float> lambda = ces.eigenvalues()[0];
//cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
//MatrixXcf v = ces.eigenvectors().col(0);
//cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
//cout << "... and A * v = " << endl << A * v << endl << endl;
//
//cout << "Finally, V * D * V^(-1) = " << endl << ces.eigenvectors() * ces.eigenvalues().asDiagonal() * ces.eigenvectors().inverse() << endl;
//}
//
//
//
//void t2a()
//{
// const int digits = 30;
// //const int digits15 = 15;
// mpreal::set_default_prec(256);
// mpreal::set_default_prec(mpfr::digits2bits(digits));
// const mpreal pi          =    mpfr::const_pi();
//
// cout.precision(digits);
//
//    cout << "pi         =    "<<    pi          << endl;
//
//
//MatrixXmpc A = MatrixXmpc::Random(4,4);
//cout << "Here is a random 4x4 matrix, A:" << endl << A << endl << endl;
//
//ComplexEigenSolver<MatrixXmpc> ces;
//ces.compute(A);
//cout << "The eigenvalues of A are:" << endl << ces.eigenvalues() << endl;
//cout << "The matrix of eigenvectors, V, is:" << endl << ces.eigenvectors() << endl << endl;
//
//complex<mpreal> lambda = ces.eigenvalues()[0];
//cout << "Consider the first eigenvalue, lambda = " << lambda << endl;
//MatrixXmpc v = ces.eigenvectors().col(0);
//cout << "If v is the corresponding eigenvector, then lambda * v = " << endl << lambda * v << endl;
//cout << "... and A * v = " << endl << A * v << endl << endl;
//
//cout << "Finally, V * D * V^(-1) = " << endl << ces.eigenvectors() * ces.eigenvalues().asDiagonal() * ces.eigenvectors().inverse() << endl;
//}
//


void t3()
{
using std::cout;
using std::endl;
using std::complex;

 const int digits = 100;
 const int digits15 = 15;
 mpreal::set_default_prec(256);
 mpreal::set_default_prec(mpfr::digits2bits(digits));

 const mpreal pi          =    mpfr::const_pi();
 cout.precision(digits);
 cout << "pi         =    "<<    pi          << endl;

 std::complex<mpreal> Input_mpc ("3.1","4.1");
 cout << "The value of " << "Input_mpc" << " is " << Input_mpc << '\n';
// cout << "The value of " << "operator(Input_mpc)" << " is " << operator_mpc(Input_mpc) << '\n';

 std::complex<mpreal> Function_std = std::sqrt(Input_mpc);
 cout << "The value of " << "Function_std(Input_mpc)" << " is " << Function_std << '\n';

 std::complex<mpreal> Function_mpc = sqrt_mpc(Input_mpc);
 cout << "The value of " << "mpc-Function(Input_mpc)" << " is " << Function_mpc << '\n';

 cout.precision(digits15);
 std::complex<double> complex_double (3.1,4.1);
 cout << "The sqrt of " << complex_double << " is " << std::sqrt(complex_double) << '\n';
}



int main(int argc, char* argv[])
{
//    t1();
//    test_mpreal_support();
//    t2a();
    t3();

    return 0;
}
