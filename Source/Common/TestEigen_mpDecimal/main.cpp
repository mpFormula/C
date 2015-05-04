#include <iostream>
#include "mpRealDecimalSupport.h"

using namespace std;
using namespace mpDec;

void t1()
{
	mpDec::set_precision(3000);
//	mpDec::set_decimal32();
//	mpDec::set_decimal64();
//	mpDec::set_decimal128();


	cout << "Hello world!" << endl;
	 mpdec_class d11, d12, d13;
	 d11 = "32342345.53323423445";
	mpdec_class d1  ("4234234.523423443");
	cout << "d1: " << d1 << endl;

	mpdec_class d2 ("544234823423489");
	cout << "d2: " << d2 << endl;

	mpdec_class d3 = d1 * d2;

	d2 = d1 * d3;
	cout << "d2: " << d2 << endl;

	cout <<  "(d1 * d2)^2: " << d1 * d2 << endl;
	cout <<  "d3: " << d3 << endl;
	d11 = 2;
	cout <<  "sqrt(2): " << sqrt(d11) << "   IsNaN: " << isnan(d11) << endl;
	d12 = 1.0;
	cout <<  "d12 " << d12 << endl;
	cout <<  "exp(1) " << exp(d12) << endl;

	cout <<  "max(d1, d2) " << max(d1, d2) << endl;
}


int main()
{
  t1();


  //std::cout << "Press any key to close" << std::endl;
//	std::cin.get();
	return 0;
}
