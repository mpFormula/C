
#include <iostream>
#include <sstream>
#include  "mpRealRationalSupport.h"


using namespace std;
using namespace mpq;


void test_mpq_support()
{
  std::cout  << "Starting test_mpq_support()  "  << "\n";
  // set precision to 256 bits (double has only 53 bits)

mpRealRational x1, x2, x3;
x1 = "33456456456/113";
x2 = "44/53";
x3 = x1 * x2;

std::cout  << "x1: "  << x1 << "\n";
std::cout  << "x2: "  << x2 << "\n";
std::cout  << "x3: "  << x3 << "\n";

}




int main(int argc, char* argv[])
{
    test_mpq_support();
    return 0;
}
