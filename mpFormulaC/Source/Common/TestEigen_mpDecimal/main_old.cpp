
#include <iostream>
#include <sstream>
#include  "mpRealDecimal.h"


using namespace std;
using namespace mpDec;


void test_mpDec_support()
{
  std::cout  << "Starting test_mpfi_support()  "  << "\n";
  // set precision to 256 bits (double has only 53 bits)

mpRealInterval x1, x2, x3;
x1 = 3.3456456456;
x2 = 4.4;
x3 = x1 * x2;

std::cout  << "x1: "  << x1 << "\n";
std::cout  << "x2: "  << x2 << "\n";
std::cout  << "x3: "  << x3 << "\n";

}




int main(int argc, char* argv[])
{
    test_mpDec_support();
    return 0;
}
