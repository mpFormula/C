
//#pragma once

//#include "stdafx.h"
#include "cxscmpfr.h"
#include <boost/math/bindings/mpfr.hpp>
#include <boost/math/special_functions.hpp>
//#include <boost/math/distributions.hpp>

//      in factorials.hpp, line 154, replace lines:
//      return (n & 1) ? (-val) : (val);
//      return (n & 1) ? (val * static_cast<T>(-1)) : (val);


using namespace boost::math;


// bernoulli
 void boost_mpfr_pdf_bernoulli (mpfr_t z, mpfr_t x, mpfr_t p1)
{
	mpfr_class k = mpfr_class(x);
	mpfr_class p = mpfr_class(p1);
	mpfr_class v = 0;
	if (k == 0)
	{
		v = 1 - p;
	}
	else
	{
		v = p;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_bernoulli_P (mpfr_t z, mpfr_t x, mpfr_t p1)
{
	mpfr_class k = mpfr_class(x);
	mpfr_class p = mpfr_class(p1);
	mpfr_class v = 0;
	if (k == 0)
	{
		v = 1 - p;
	}
	else
	{
		v = 1;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
 }


 void boost_mpfr_cdf_bernoulli_Q (mpfr_t z, mpfr_t x, mpfr_t p1)
{
	mpfr_class k = mpfr_class(x);
	mpfr_class p = mpfr_class(p1);
	mpfr_class v = 0;
	if (k == 0)
	{
		v = 1 - (1 - p);
	}
	else
	{
		v = 0;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_bernoulli_Pinv (mpfr_t z, mpfr_t P, mpfr_t p1)
{
	mpfr_class x = mpfr_class(P);
	mpfr_class p = mpfr_class(p1);
	mpfr_class v = 0;
	if (x <= (1 - p))
	{
		v = 0;
	}
	else
	{
		v = 1;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
 }


 void boost_mpfr_cdf_bernoulli_Qinv (mpfr_t z, mpfr_t Q, mpfr_t p1)
{
	mpfr_class x = mpfr_class(Q);
	mpfr_class p = mpfr_class(p1);
	mpfr_class v = 0;
	if (x <= (1 - p))
	{
		v = 1;
	}
	else
	{
		v = 0;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // cdist
 void boost_mpfr_pdf_cdist (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class v = gamma_p_derivative(mpfr_class(nu)/2, mpfr_class(x)/2)/2;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdist_P (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class v = gamma_p(mpfr_class(nu)/2, mpfr_class(x)/2);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdist_Q (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class v = gamma_q(mpfr_class(nu)/2, mpfr_class(x)/2);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu)
{
	mpfr_class v = 2 * gamma_p_inv(mpfr_class(nu)/2, mpfr_class(P));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu)
{
	mpfr_class v = 2 * gamma_q_inv(mpfr_class(nu)/2, mpfr_class(Q));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // exponentialdist
 void boost_mpfr_pdf_exponentialdist (mpfr_t z, mpfr_t x, mpfr_t lambda)
{
	mpfr_class v = mpfr_class(lambda) * exp(-mpfr_class(lambda) * mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_exponentialdist_P (mpfr_t z, mpfr_t x, mpfr_t lambda)
{
	mpfr_class v = -expm1(-mpfr_class(x) * mpfr_class(lambda));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_exponentialdist_Q (mpfr_t z, mpfr_t x, mpfr_t lambda)
{
	mpfr_class v = exp(-mpfr_class(x) * mpfr_class(lambda));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_exponentialdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lambda)
{
	mpfr_class v = -log1p(-mpfr_class(P)) / mpfr_class(lambda);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_exponentialdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lambda)
{
	mpfr_class v = -log(mpfr_class(Q)) / mpfr_class(lambda);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // poisson
 void boost_mpfr_pdf_poissondist (mpfr_t z, mpfr_t k, mpfr_t lambda)
{
	mpfr_class v = exp(-mpfr_class(lambda)) * pow(mpfr_class(lambda), mpfr_class(k)) / tgamma(mpfr_class(k) + 1);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_poissondist_P (mpfr_t z, mpfr_t k, mpfr_t lambda)
{
	mpfr_class v = gamma_q(mpfr_class(k) + 1, mpfr_class(lambda));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_poissondist_Q (mpfr_t z, mpfr_t k, mpfr_t lambda)
{
	mpfr_class v = gamma_p(mpfr_class(k) + 1, mpfr_class(lambda));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_poissondist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lambda)
{
	mpfr_class v = gamma_q(mpfr_class(lambda) + 1, mpfr_class(P)) - 1;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_poissondist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lambda)
{
	mpfr_class v = gamma_p(mpfr_class(lambda) + 1, mpfr_class(Q)) - 1;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // rayleig
 void boost_mpfr_pdf_rayleighdist (mpfr_t z, mpfr_t x, mpfr_t s)
{
	mpfr_class v = mpfr_class(x) * exp(-(mpfr_class(x) * mpfr_class(x))/2) / ( mpfr_class(s) * mpfr_class(s));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_rayleighdist_P (mpfr_t z, mpfr_t x, mpfr_t s)
{
	mpfr_class v = -expm1(-(mpfr_class(x) * mpfr_class(x))/2) / ( mpfr_class(s) * mpfr_class(s));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_rayleighdist_Q (mpfr_t z, mpfr_t x, mpfr_t s)
{
	mpfr_class v = exp(-(mpfr_class(x) * mpfr_class(x))/2) / ( mpfr_class(s) * mpfr_class(s));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_rayleighdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t s)
{
	mpfr_class v = sqrt(-2 * (mpfr_class(s) * mpfr_class(s))) * log1p(-mpfr_class(P));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_rayleighdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t s)
{
	mpfr_class v = sqrt(-2 * (mpfr_class(s) * mpfr_class(s))) * log(-mpfr_class(Q));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 // Student's t
 void boost_mpfr_pdf_tdist (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class n = mpfr_class(nu);
	mpfr_class t = mpfr_class(x);
	mpfr_class a = pow(n / (n + t * t), (1 + n) / 2);
	mpfr_class b = sqrt(n) * beta(n / 2, mpfr_class(0.5));
	mpfr_class v = a / b;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdist_P (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class n = mpfr_class(nu);
	mpfr_class t = mpfr_class(x);
	mpfr_class v = 0;

	if (n < 2 * t * t)
	{
		v = ibeta(mpfr_class(n / 2), mpfr_class(mpfr_class(0.5)), mpfr_class(n / (n + t * t))) / 2;
	}
	else
	{
		v = ibetac(mpfr_class(0.5), mpfr_class(n / 2), mpfr_class((t * t) / (n + t * t))) / 2;
	}
	if (t > 0) { v = 1 - v;}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdist_Q (mpfr_t z, mpfr_t x, mpfr_t nu)
{
	mpfr_class n = mpfr_class(nu);
	mpfr_class t = -mpfr_class(x);
	mpfr_class v = 0;

	if (n < 2 * t * t)
	{
		v = ibeta(mpfr_class(n / 2), mpfr_class(0.5), mpfr_class(n / (n + t * t))) / 2;
	}
	else
	{
		v = ibetac(mpfr_class(0.5), mpfr_class(n / 2), mpfr_class((t * t) / (n + t * t))) / 2;
	}
	if (t > 0) { v = 1 - v;}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);

}


 void boost_mpfr_cdf_tdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu)
{
	mpfr_class n = mpfr_class(nu);
	mpfr_class p = mpfr_class(P);
	if (p > mpfr_class(0.5)) { p = 1 - p;}
	mpfr_class x = ibeta_inv(mpfr_class(n / 2), mpfr_class(0.5), mpfr_class(2 * p));
	mpfr_class v = sgn(p - 0.5) * sqrt(n * (1 - x) / x);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu)
{
	mpfr_class n = mpfr_class(nu);
	mpfr_class p = mpfr_class(Q);
	if (p > mpfr_class(0.5)) { p = 1 - p;}
	mpfr_class x = ibeta_inv(mpfr_class(n / 2), mpfr_class(0.5), mpfr_class(2 * p));
	mpfr_class v = -sgn(p - 0.5) * sqrt(n * (1 - x) / x);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 // betadist
 void boost_mpfr_pdf_betadist (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class v = ibeta_derivative(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadist_P (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class v = ibeta(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadist_Q (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class v = ibetac(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadist_Pinv (mpfr_t z, mpfr_t P, mpfr_t a, mpfr_t b)
{
	mpfr_class v = ibeta_inv(mpfr_class(a), mpfr_class(b), mpfr_class(P));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t a, mpfr_t b)
{
	mpfr_class v = ibetac_inv(mpfr_class(a), mpfr_class(b), mpfr_class(Q));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // _binomialdist
 void boost_mpfr_pdf_binomialdist (mpfr_t z, mpfr_t k, mpfr_t n, mpfr_t p)
{
	mpfr_class v = ibeta_derivative(mpfr_class(k) + 1, mpfr_class(n) - mpfr_class(k) + 1, mpfr_class(p)) / (mpfr_class(n) + 1);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_binomialdist_P (mpfr_t z, mpfr_t k, mpfr_t n, mpfr_t p)
{
	mpfr_class v = ibetac(mpfr_class(k) + 1, mpfr_class(n) - mpfr_class(k), mpfr_class(p));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_binomialdist_Q (mpfr_t z, mpfr_t k, mpfr_t n, mpfr_t p)
{
	mpfr_class v = ibetac(mpfr_class(k) + 1, mpfr_class(n) - mpfr_class(k), mpfr_class(p));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_binomialdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t n, mpfr_t p)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_binomialdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t n, mpfr_t p)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 // _cauchydist
 void boost_mpfr_pdf_cauchydist (mpfr_t z, mpfr_t x, mpfr_t x0, mpfr_t g)
{
	mpfr_class a = (mpfr_class(x) - mpfr_class(x0)) / mpfr_class(g);
	mpfr_class v = 1 / (const_pi() *  mpfr_class(g) * (1 + a * a));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cauchydist_P (mpfr_t z, mpfr_t x, mpfr_t x0, mpfr_t g)
{
	mpfr_class a = (mpfr_class(x) - mpfr_class(x0)) / mpfr_class(g);
	mpfr_class v = (1 / const_pi()) *  a + mpfr_class(0.5);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cauchydist_Q (mpfr_t z, mpfr_t x, mpfr_t x0, mpfr_t g)
{
	mpfr_class a = (mpfr_class(x) - mpfr_class(x0)) / mpfr_class(g);
	mpfr_class v = -(1 / const_pi()) *  a + mpfr_class(0.5);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cauchydist_Pinv (mpfr_t z, mpfr_t P, mpfr_t x0, mpfr_t g)
{
	mpfr_class v = mpfr_class(x0) +  mpfr_class(g) / tan(const_pi() *  mpfr_class(x0));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cauchydist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t x0, mpfr_t g)
{
	mpfr_class v = mpfr_class(x0) -  mpfr_class(g) / tan(const_pi() *  mpfr_class(x0));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_extreme_valuedist
 void boost_mpfr_pdf_extreme_valuedist (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class d = exp((mpfr_class(a) - mpfr_class(x)) / mpfr_class(b));
	mpfr_class v = d * exp(-d) / mpfr_class(b);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_extreme_valuedist_P (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class d = exp((mpfr_class(a) - mpfr_class(x)) / mpfr_class(b));
	mpfr_class v = exp(-d);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_extreme_valuedist_Q (mpfr_t z, mpfr_t x, mpfr_t a, mpfr_t b)
{
	mpfr_class d = exp((mpfr_class(a) - mpfr_class(x)) / mpfr_class(b));
	mpfr_class v = -expm1(-d);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_extreme_valuedist_Pinv (mpfr_t z, mpfr_t P, mpfr_t a, mpfr_t b)
{
	mpfr_class v = mpfr_class(a) - log(-log(mpfr_class(P))) * mpfr_class(b);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_extreme_valuedist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t a, mpfr_t b)
{
	mpfr_class v = mpfr_class(a) - log(-log1p(-mpfr_class(Q))) * mpfr_class(b);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}





 //_fdist
 void boost_mpfr_pdf_fdist (mpfr_t z, mpfr_t x0, mpfr_t mu, mpfr_t nu)
{
	mpfr_class n1 = mpfr_class(mu);
	mpfr_class n2 = mpfr_class(nu);
	mpfr_class x = mpfr_class(x0);
	mpfr_class z1 = (n2 + n1 * x);
	mpfr_class v = 0;
	if (n1 * x > n2)
	{
		mpfr_class y = (n2 * n1) / (z1 * z1);
		v = y * ibeta_derivative(n2/2, n1/2, n2/(z1));
	}
	else
	{
		mpfr_class y = (z1 * n1 - x * n1) / (z1 * n1);
		v = y * ibeta_derivative(n1/2, n2/2, n1 * x / z1);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdist_P (mpfr_t z, mpfr_t x0, mpfr_t mu, mpfr_t nu)
{
	mpfr_class n1 = mpfr_class(mu);
	mpfr_class n2 = mpfr_class(nu);
	mpfr_class x = mpfr_class(x0);
	mpfr_class z1 = (n2 + n1 * x);
	mpfr_class v = 0;
	if (n1 * x > n2)
	{
		v = ibeta(n1/2, n2/2, (n1 * x) / z1);
	}
	else
	{
		v = ibetac(n2/2, n1/2, n2 / z1);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdist_Q (mpfr_t z, mpfr_t x0, mpfr_t mu, mpfr_t nu)
{
	mpfr_class n1 = mpfr_class(mu);
	mpfr_class n2 = mpfr_class(nu);
	mpfr_class x = mpfr_class(x0);
	mpfr_class z1 = (n2 + n1 * x);
	mpfr_class v = 0;
	if (n1 * x > n2)
	{
		v = ibetac(n1/2, n2/2, (n1 * x) / z1);
	}
	else
	{
		v =  ibeta(n2/2, n1/2, n2 / z1);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu)
{
	mpfr_class n1 = mpfr_class(mu);
	mpfr_class n2 = mpfr_class(nu);
	mpfr_class p = mpfr_class(P);
	mpfr_class a = ibeta_inv(mpfr_class(n1/2), mpfr_class(n2/2), p);
	mpfr_class b = 1 - a;
	mpfr_class v = n2 * a / (n1 * b);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu)
{
	mpfr_class n1 = mpfr_class(mu);
	mpfr_class n2 = mpfr_class(nu);
	mpfr_class p = mpfr_class(Q);
	mpfr_class a = ibetac_inv(mpfr_class(n1/2), mpfr_class(n2/2), p);
	mpfr_class b = 1 - a;
	mpfr_class v = n2 * a / (n1 * b);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_gammadist
 void boost_mpfr_pdf_gammadist (mpfr_t z, mpfr_t x, mpfr_t k, mpfr_t t)
{
	mpfr_class v = gamma_p_derivative(mpfr_class(k), mpfr_class(x) / mpfr_class(t)) / mpfr_class(t);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_gammadist_P (mpfr_t z, mpfr_t x, mpfr_t k, mpfr_t t)
{
	mpfr_class v = gamma_p(mpfr_class(k), mpfr_class(x) / mpfr_class(t));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_gammadist_Q (mpfr_t z, mpfr_t x, mpfr_t k, mpfr_t t)
{
	mpfr_class v = gamma_q(mpfr_class(k), mpfr_class(x) / mpfr_class(t));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_gammadist_Pinv (mpfr_t z, mpfr_t P, mpfr_t k, mpfr_t t)
{
	mpfr_class v = mpfr_class(t) * gamma_p_inv(mpfr_class(k), mpfr_class(P));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_gammadist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t k, mpfr_t t)
{
	mpfr_class v = mpfr_class(t) * gamma_q_inv(mpfr_class(k), mpfr_class(Q));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}





 //_laplacedist
 void boost_mpfr_pdf_laplacedist (mpfr_t z, mpfr_t x0, mpfr_t location, mpfr_t scale)
{
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = exp(-abs(x - mu) / s) / (2 *s);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_laplacedist_P (mpfr_t z, mpfr_t x0, mpfr_t location, mpfr_t scale)
{
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = 0;
	if (x < mu)
	{
		v = exp((x - mu) / s) / s;
	}
	else
	{
		v = 1 - exp((mu - x) / s) / s;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_laplacedist_Q (mpfr_t z, mpfr_t x0, mpfr_t location, mpfr_t scale)
{
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = 0;
	if (-x < mu)
	{
		v = exp((-x - mu) / s) / s;
	}
	else
	{
		v = 1 - exp((x + mu) / s) / s;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_laplacedist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale)
{
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class p = mpfr_class(P);
	mpfr_class v = 0;
	if (p < 0.5)
	{
		v = mu + s * log(2 * p);
	}
	else
	{
		v = mu - s * log(2 - 2 * p);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_laplacedist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale)
{
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class q = mpfr_class(Q);
	mpfr_class v = 0;
	if (q > 0.5)
	{
		v = mu + s * log(2 - 2 * q);
	}
	else
	{
		v = mu - s * log(2 * q);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_logisticdist
 void boost_mpfr_pdf_logisticdist (mpfr_t z, mpfr_t x1, mpfr_t location, mpfr_t scale)
{
	// page 166
	mpfr_class x = mpfr_class(x1);
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class v = exp(-abs(x - mu) / s) / (2 * s);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_logisticdist_P (mpfr_t z, mpfr_t x1, mpfr_t location, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x1);
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class v = 0;
	if (x < mu)
	{
		v = exp((x - mu) / s) / s;
	}
	else
	{
		v = 1 - exp((mu - x) / s) / s;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_logisticdist_Q (mpfr_t z, mpfr_t x1, mpfr_t location, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x1);
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class v = 0;
	if (-x < mu)
	{
		v = exp((-x - mu) / s) / s;
	}
	else
	{
		v = 1 - exp((mu + x) / s) / s;
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
 }


 void boost_mpfr_cdf_logisticdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t location, mpfr_t scale)
{
	mpfr_class p = mpfr_class(P);
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class v = 0;
	if (p < 0.5)
	{
		v = mu + s * log(2 * p);
	}
	else
	{
		v =  mu - s * log(2 - 2 * p);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_logisticdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t location, mpfr_t scale)
{
	mpfr_class q = mpfr_class(Q);
	mpfr_class mu = mpfr_class(location);
	mpfr_class s = mpfr_class(scale);
	mpfr_class v = 0;
	if (q > 0.5)
	{
		v = mu + s * log(2 - 2 * q);
	}
	else
	{
		v =  mu - s * log(2 * q);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_lognormaldist
 void boost_mpfr_pdf_lognormaldist (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = log(mpfr_class(x0));
	mpfr_class v = exp(-((x - m) * (x - m)) / (2 * s * s)) / (mpfr_class(x0) *s * sqrt(2 * const_pi()));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_lognormaldist_P (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = log(mpfr_class(x0));
	mpfr_class v = erfc(-(x - m)/(s * sqrt(mpfr_class(2) ))) / 2;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_lognormaldist_Q (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = log(mpfr_class(x0));
	mpfr_class v = erfc((x - m)/(s * sqrt(mpfr_class(2)))) / 2;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_lognormaldist_Pinv (mpfr_t z, mpfr_t P, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class p = mpfr_class(P);
	mpfr_class v = exp(m - s * sqrt(mpfr_class(2)) * erfc_inv(2*p));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_lognormaldist_Qinv (mpfr_t z, mpfr_t P, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class p = mpfr_class(P);
	mpfr_class v = exp(m + s * sqrt(mpfr_class(2)) * erfc_inv(2*p));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_negative_binomialdist
 void boost_mpfr_pdf_negative_binomialdist (mpfr_t z, mpfr_t x, mpfr_t k0, mpfr_t r0)
{
	mpfr_class p = mpfr_class(x);
	mpfr_class k = mpfr_class(k0);
	mpfr_class r = mpfr_class(r0);
	mpfr_class v = (p / (r + k)) * ibeta_derivative(r, (k+1), p);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_negative_binomialdist_P (mpfr_t z, mpfr_t x, mpfr_t k0, mpfr_t r0)
{
	mpfr_class p = mpfr_class(x);
	mpfr_class k = mpfr_class(k0);
	mpfr_class r = mpfr_class(r0);
	mpfr_class v = ibeta(r, k+1, p);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_negative_binomialdist_Q  (mpfr_t z, mpfr_t x, mpfr_t k0, mpfr_t r0)
{
	mpfr_class p = mpfr_class(x);
	mpfr_class k = mpfr_class(k0);
	mpfr_class r = mpfr_class(r0);
	mpfr_class v = ibetac(r, k+1, p);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_negative_binomialdist_Pinv (mpfr_t z, mpfr_t x, mpfr_t k0, mpfr_t r0)
{
	mpfr_class p = mpfr_class(x);
	mpfr_class P = mpfr_class(k0);
	mpfr_class r = mpfr_class(r0);
	mpfr_class v = ibeta_invb(r, p, P) - 1;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_negative_binomialdist_Qinv (mpfr_t z, mpfr_t x, mpfr_t k0, mpfr_t r0)
{
	mpfr_class p = mpfr_class(x);
	mpfr_class P = mpfr_class(k0);
	mpfr_class r = mpfr_class(r0);
	mpfr_class v = ibetac_invb(r, p, P) - 1;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_cdistn
 void boost_mpfr_pdf_cdistn (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdistn_P (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdistn_Q (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_cdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_tdistn
 void boost_mpfr_pdf_tdistn (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdistn_P (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdistn_Q (mpfr_t z, mpfr_t x, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_tdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_ndist
 void boost_mpfr_pdf_ndist (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = exp(-((x - m) * (x - m)) / (2 * s * s)) / (s * sqrt(2 * const_pi()));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_ndist_P (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = erfc(-(x - m)/(s * sqrt(mpfr_class(2) ))) / 2;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_ndist_Q (mpfr_t z, mpfr_t x0, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class x = mpfr_class(x0);
	mpfr_class v = erfc((x - m)/(s * sqrt(mpfr_class(2)))) / 2;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_ndist_Pinv (mpfr_t z, mpfr_t P, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class p = mpfr_class(P);
	mpfr_class v = m - s * sqrt(mpfr_class(2)) * erfc_inv(2*p);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_ndist_Qinv (mpfr_t z, mpfr_t P, mpfr_t mean, mpfr_t sigma)
{
	mpfr_class m = mpfr_class(mean);
	mpfr_class s = mpfr_class(sigma);
	mpfr_class p = mpfr_class(P);
	mpfr_class v = m + s * sqrt(mpfr_class(2)) * erfc_inv(2*p);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_paretodist
 void boost_mpfr_pdf_paretodist (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = a * pow(b, a) / pow(x, a +1);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_paretodist_P (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = 1 - pow(b / x, a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_paretodist_Q (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = -pow(b / x, a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_paretodist_Pinv (mpfr_t z, mpfr_t P, mpfr_t shape, mpfr_t scale)
{
	mpfr_class p = mpfr_class(P);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = b / pow(1 - p, 1 / a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_paretodist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t shape, mpfr_t scale)
{
	mpfr_class q = mpfr_class(Q);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = b / pow(q, 1 / a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_weibulldist
 void boost_mpfr_pdf_weibulldist (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = a * pow(b, -a) * pow(x, a - 1) * exp(-pow(x/b, a));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_weibulldist_P (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = -expm1(-pow(x/b, a));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_weibulldist_Q (mpfr_t z, mpfr_t x0, mpfr_t shape, mpfr_t scale)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = exp(-pow(x/b, a));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_weibulldist_Pinv (mpfr_t z, mpfr_t P, mpfr_t shape, mpfr_t scale)
{
	mpfr_class p = mpfr_class(P);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = b *  pow((-log1p(-p)), 1 / a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_weibulldist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t shape, mpfr_t scale)
{
	mpfr_class q = mpfr_class(Q);
	mpfr_class a = mpfr_class(shape);
	mpfr_class b = mpfr_class(scale);
	mpfr_class v = b * pow((-log(q)), 1 / a);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_uniformdist
 void boost_mpfr_pdf_uniformdist (mpfr_t z, mpfr_t x0, mpfr_t lower, mpfr_t upper)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(lower);
	mpfr_class b = mpfr_class(upper);
	mpfr_class v = 0;
	if ((x < a) || (x > b))
	{
		v = 0;
	}
	else
	{
		v = 1 / (b - a);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_uniformdist_P (mpfr_t z, mpfr_t x0, mpfr_t lower, mpfr_t upper)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(lower);
	mpfr_class b = mpfr_class(upper);
	mpfr_class v = 0;
	// needs 3rd case
	if ((x < a) || (x > b))
	{
		v = 0;
	}
	else
	{
		v = (x - a) / (b - a);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_uniformdist_Q (mpfr_t z, mpfr_t x0, mpfr_t lower, mpfr_t upper)
{
	mpfr_class x = mpfr_class(x0);
	mpfr_class a = mpfr_class(lower);
	mpfr_class b = mpfr_class(upper);
	mpfr_class v = 0;
	// needs 3rd case
	if ((x < a) || (x > b))
	{
		v = 0;
	}
	else
	{
		v = (b - x) / (b - a);
	}
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_uniformdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lower, mpfr_t upper)
{
	mpfr_class p = mpfr_class(P);
	mpfr_class a = mpfr_class(lower);
	mpfr_class b = mpfr_class(upper);
	mpfr_class v = p * (b - a) + a;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_uniformdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lower, mpfr_t upper)
{
	mpfr_class q = mpfr_class(Q);
	mpfr_class a = mpfr_class(lower);
	mpfr_class b = mpfr_class(upper);
	mpfr_class v = -q * (b - a) + b;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}





 //_hypergeometricdist
 void boost_mpfr_pdf_hypergeometricdist (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_hypergeometricdist_P (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_hypergeometricdist_Q (mpfr_t z, mpfr_t x, mpfr_t r, mpfr_t n, mpfr_t N)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_hypergeometricdist_Pinv (mpfr_t z, mpfr_t P, mpfr_t r, mpfr_t n, mpfr_t N)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_hypergeometricdist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t r, mpfr_t n, mpfr_t N)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}





 //_fdistn
 void boost_mpfr_pdf_fdistn (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdistn_P (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdistn_Q (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_fdistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




 //_betadistn
 void boost_mpfr_pdf_betadistn (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadistn_P (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadistn_Q (mpfr_t z, mpfr_t x, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadistn_Pinv (mpfr_t z, mpfr_t P, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_betadistn_Qinv (mpfr_t z, mpfr_t Q, mpfr_t mu, mpfr_t nu, mpfr_t nc)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



 //_triangulardist
 void boost_mpfr_pdf_triangulardist (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_triangulardist_P (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_triangulardist_Q (mpfr_t z, mpfr_t x, mpfr_t lower, mpfr_t mode, mpfr_t upper)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_triangulardist_Pinv (mpfr_t z, mpfr_t P, mpfr_t lower, mpfr_t mode, mpfr_t upper)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


 void boost_mpfr_cdf_triangulardist_Qinv (mpfr_t z, mpfr_t Q, mpfr_t lower, mpfr_t mode, mpfr_t upper)
{
	mpfr_class v = -999;
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}






















// Gamma function

void boost_mpfr_tgamma(mpfr_t z, mpfr_t x)
{
	mpfr_class v = tgamma(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_tgamma1pm1(mpfr_t z, mpfr_t x)
{
	mpfr_class v = tgamma1pm1(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_lgamma(mpfr_t z, mpfr_t x)
{
	mpfr_class v = lgamma(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_digamma(mpfr_t z, mpfr_t x)
{
	mpfr_class v = digamma(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_tgamma_ratio(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = tgamma_ratio(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_tgamma_delta_ratio(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = tgamma_delta_ratio(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_p(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_p(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_q(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_q(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_tgamma_lower(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = tgamma_lower(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_tgamma_upper(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = tgamma(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_p_inv(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_p_inv(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_q_inv(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_q_inv(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_p_inva(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_p_inva(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_q_inva(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_q_inva(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_gamma_p_derivative(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = gamma_p_derivative(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_factorial(mpfr_t z, unsigned int i)
{
	mpfr_class v = factorial<mpfr_class>(i);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_unchecked_factorial(mpfr_t z, unsigned int i)
{
	mpfr_class v = unchecked_factorial<mpfr_class>(i);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_double_factorial(mpfr_t z, unsigned int i)
{
	mpfr_class v = double_factorial<mpfr_class>(i);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_rising_factorial(mpfr_t z, mpfr_t x, unsigned int i)
{
	mpfr_class v = rising_factorial<mpfr_class>(mpfr_class(x), i);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_falling_factorial(mpfr_t z, mpfr_t x, unsigned int i)
{
	mpfr_class v = falling_factorial<mpfr_class>(mpfr_class(x), i);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_binomial_coefficien(mpfr_t z,  unsigned int i, unsigned int j)
{
	mpfr_class v = falling_factorial<mpfr_class>(i, j);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Beta function



void boost_mpfr_beta(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = beta(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ibeta(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibeta(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ibetac(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibetac(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ibeta_non_normalized(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = beta(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibetac_non_normalized(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = betac(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibeta_inv(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibeta_inv(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibetac_inv(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibetac_inv(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibeta_inv2(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x, mpfr_t y)
{
	mpfr_class temp;
	mpfr_class v = ibeta_inv(mpfr_class(a), mpfr_class(b), mpfr_class(x), &temp);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
	mpfr_set(y, temp.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ibetac_inv2(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x, mpfr_t y)
{
	mpfr_class temp;
	mpfr_class v = ibetac_inv(mpfr_class(a), mpfr_class(b), mpfr_class(x), &temp);
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
	mpfr_set(y, temp.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibeta_inva(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibeta_inva(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibetac_inva(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibetac_inva(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ibeta_invb(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibeta_invb(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibetac_invb(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibetac_invb(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ibeta_derivative(mpfr_t z, mpfr_t a, mpfr_t b, mpfr_t x)
{
	mpfr_class v = ibeta_derivative(mpfr_class(a), mpfr_class(b), mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Error function

void boost_mpfr_erf(mpfr_t z, mpfr_t x)
{
	mpfr_class v = erf(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_erfc(mpfr_t z, mpfr_t x)
{
	mpfr_class v = erfc(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_erf_inv(mpfr_t z, mpfr_t x)
{
	mpfr_class v = erf_inv(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_erfc_inv(mpfr_t z, mpfr_t x)
{
	mpfr_class v = erfc_inv(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Polynomials


void boost_mpfr_legendre_p(mpfr_t z, int n, mpfr_t x)
{
	mpfr_class v = legendre_p(n, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_legendre_p_m(mpfr_t z, int n, int m, mpfr_t x)
{
	mpfr_class v = legendre_p(n, m, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_legendre_q(mpfr_t z, int n, mpfr_t x)
{
	mpfr_class v = legendre_q(n, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_legendre_next(mpfr_t z, int n, mpfr_t x, mpfr_t Pl, mpfr_t Plm1)
{
	mpfr_class v = legendre_next(n, mpfr_class(x), mpfr_class(Pl), mpfr_class(Plm1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_legendre_next_m1(mpfr_t z, int n, int m, mpfr_t x, mpfr_t Pl, mpfr_t Plm1)
{
	mpfr_class v = legendre_next(n, m, mpfr_class(x), mpfr_class(Pl), mpfr_class(Plm1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




void boost_mpfr_laguerre(mpfr_t z, int n, mpfr_t x)
{
	mpfr_class v = laguerre(n, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_laguerre_m(mpfr_t z, int n, int m, mpfr_t x)
{
	mpfr_class v = laguerre(n, m, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_laguerre_next(mpfr_t z, int n, mpfr_t x, mpfr_t Ln, mpfr_t Lnm1)
{
	mpfr_class v = laguerre_next(n, mpfr_class(x), mpfr_class(Ln), mpfr_class(Lnm1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_laguerre_next_m1(mpfr_t z, int n, int m, mpfr_t x, mpfr_t Ln, mpfr_t Lnm1)
{
	mpfr_class v = laguerre_next(n, m, mpfr_class(x), mpfr_class(Ln), mpfr_class(Lnm1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_hermite(mpfr_t z, int n, mpfr_t x)
{
	mpfr_class v = hermite(n, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_hermite_next_m1(mpfr_t z, int n, mpfr_t x, mpfr_t Hn, mpfr_t Hnm1)
{
	mpfr_class v = hermite_next(n, mpfr_class(x), mpfr_class(Hn), mpfr_class(Hnm1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_spherical_harmonic_r(mpfr_t z, int n, int m, mpfr_t theta, mpfr_t phi)
{
	mpfr_class v = spherical_harmonic_r(n, m, mpfr_class(theta), mpfr_class(phi));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_spherical_harmonic_i(mpfr_t z, int n, int m, mpfr_t theta, mpfr_t phi)
{
	mpfr_class v = spherical_harmonic_i(n, m, mpfr_class(theta), mpfr_class(phi));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}





//Bessel Functions


void boost_mpfr_cyl_bessel_j(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = cyl_bessel_j(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_cyl_neumann(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = cyl_neumann(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_cyl_bessel_i(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = cyl_bessel_i(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_cyl_bessel_k(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = cyl_bessel_k(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sph_bessel(mpfr_t z, unsigned nu,  mpfr_t y)
{
	mpfr_class v = sph_bessel(nu, mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sph_neumann(mpfr_t z, unsigned nu,  mpfr_t y)
{
	mpfr_class v = sph_neumann(nu, mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



//Elliptic Integrals


void boost_mpfr_ellint_rf(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1)
{
	mpfr_class v = ellint_rf(mpfr_class(x), mpfr_class(y), mpfr_class(z1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ellint_rd(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1)
{
	mpfr_class v = ellint_rd(mpfr_class(x), mpfr_class(y), mpfr_class(z1));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_ellint_rj(mpfr_t z, mpfr_t x, mpfr_t y, mpfr_t z1, mpfr_t p)
{
	mpfr_class v = ellint_rj(mpfr_class(x), mpfr_class(y), mpfr_class(z1), mpfr_class(p));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_rc(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = ellint_rc(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




void boost_mpfr_ellint_1_F(mpfr_t z, mpfr_t k, mpfr_t phi)
{
	mpfr_class v = ellint_1(mpfr_class(k), mpfr_class(phi));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_1_K(mpfr_t z, mpfr_t k)
{
	mpfr_class v = ellint_1(mpfr_class(k));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_2_F(mpfr_t z, mpfr_t k, mpfr_t phi)
{
	mpfr_class v = ellint_2(mpfr_class(k), mpfr_class(phi));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_2_K(mpfr_t z, mpfr_t k)
{
	mpfr_class v = ellint_2(mpfr_class(k));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_3_F(mpfr_t z, mpfr_t k, mpfr_t n, mpfr_t phi)
{
	mpfr_class v = ellint_3(mpfr_class(k), mpfr_class(n), mpfr_class(phi));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_ellint_3_K(mpfr_t z, mpfr_t k, mpfr_t n)
{
	mpfr_class v = ellint_3(mpfr_class(k), mpfr_class(n));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Zeta Function

void boost_mpfr_zeta(mpfr_t z, mpfr_t x)
{
	mpfr_class v = zeta(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Exponential Integral

void boost_mpfr_expint_n(mpfr_t z, unsigned n, mpfr_t x)
{
	mpfr_class v = expint(n, mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_expint_ei(mpfr_t z, mpfr_t x)
{
	mpfr_class v = expint(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


// Log and Exp

void boost_mpfr_log1p(mpfr_t z, mpfr_t x)
{
	mpfr_class v = log1p(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_expm1(mpfr_t z, mpfr_t x)
{
	mpfr_class v = expm1(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_cbrt(mpfr_t z, mpfr_t x)
{
	mpfr_class v = cbrt(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sqrt1pm1(mpfr_t z, mpfr_t x)
{
	mpfr_class v = sqrt1pm1(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}



void boost_mpfr_powm1(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = powm1(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_hypot(mpfr_t z, mpfr_t x, mpfr_t y)
{
	mpfr_class v = hypot(mpfr_class(x), mpfr_class(y));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sinc_pi(mpfr_t z, mpfr_t x)
{
	mpfr_class v = sinc_pi(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sinhc_pi(mpfr_t z, mpfr_t x)
{
	mpfr_class v = sinhc_pi(mpfr_class(x));
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}


void boost_mpfr_sinhc_pi2(mpfr_t z, mpfr_t x)
{
	mpfr_class v =  sinhc_pi(mpfr_class(x));
	//return v.get_mpfr_t();
	mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
}




//
// double boost_pdf_ndist (const mpfr_t x, const mpfr_t mean, const mpfr_t std)
//{
//   normal_distribution<mpfr_class>  dist(mpfr_class(mean), mpfr_class(std));
//   mpfr_class v = cdf<mpfr_class>(dist,  mpfr_class(x));
//	 return 1.0;
//}


//
// double boost_cdf_ndist_P (const double x, const double mean, const double std)
//{
//   normal_distribution<double>  dist((mean), (std));
//   double v =  cdf(dist,  double(x));
//   return v;
//}
//
// double boost_pdf_ndist (const double x, const double mean, const double std)
//{
//   normal_distribution<double>  dist(double(mean), double(std));
//   double v = cdf(dist,  double(x));
//}



//
// void boost_pdf_ndist (mpfr_t z,  mpfr_t nu,  mpfr_t lambda)
//{
//   non_central_chi_squared_distribution<mpfr_class>  dist(mpfr_class(nu), mpfr_class(lambda));
//   mpfr_class v = cdf<mpfr_class>(dist,  mpfr_class(z));
//   mpfr_set(z, v.get_mpfr_t(), GMP_RNDN);
//}

