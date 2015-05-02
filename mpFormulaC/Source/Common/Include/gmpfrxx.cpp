// this file implements the routines required by gmpfrxx.h

#include "gmpfrxx.h"
#include "stdlib.h"
using namespace std;


// MpFrC is a dummy class holding the static members of mpfr_class
mpfr_rnd_t  MpFrC::rnd = GMP_RNDN;
int         MpFrC::base = 10;




istream & operator>>(istream &s, mpz_ptr a) {
    string tmp;
    s >> tmp;
    mpz_set_str(a, tmp.c_str(), 0);
    return s;
}

ostream& operator<< (ostream &os, mpz_srcptr z)
{
     os << "mpz number: ";
    std::string s;
    s = mpz_class(z).get_str();
    os << s;
	return os;
}


istream & operator>>(istream &s, mpq_ptr a) {
    string tmp;
    s >> tmp;
    mpq_set_str(a, tmp.c_str(), 0);
    return s;
}

ostream& operator<< (ostream &os, mpq_srcptr q)
{
    os << "mpq number: ";
    std::string s;
    s = mpq_class(q).get_str();
    os << s;
	return os;
}


istream & operator>>(istream &s, mpfr_ptr a) {
    string tmp;
    s >> tmp;
    mpfr_set_str(a, tmp.c_str(),
		 mpfr_class::get_base(),
		 mpfr_class::get_rnd());
    // a = tmp.c_str();
    return s;
}


ostream & operator<< (ostream &os, mpfr_srcptr f)
{
    os << "mpfr number: ";
    char format[128];
    int digits = 60;
    sprintf(format,"%%.%dRNg",digits);        // Default format
    char *s = NULL;
    std::string out;
    if(!(mpfr_asprintf(&s,format,f) < 0))
        {
            out = std::string(s);
            mpfr_free_str(s);
        }
    os << out;
	return os;
}




//************************************************************************************


//void mpq_set_mpfr(mpq_ptr w, mpfr_srcptr u)
//{
//
//mpfr_exp_t exponent = mpfr_get_z_2exp(mpq_numref(w), u);
//// mpz_set_ui(mpq_denref(w),1);
//mpz_set_ui(mpq_denref(w),exponent);
////mpz_mul_2exp(mpq_denref(w),mpq_denref(w), exponent);
//}

void mpq_set_mpfr(mpq_ptr w, mpfr_srcptr u)
{
    char *s, *t;
    long k, sz;
    mp_exp_t  e, bits;

    if ( mpfr_zero_p(u) || mpfr_nan_p(u) || mpfr_inf_p(u) ) {
	mpq_set_ui(w, 0, 1);
	return;
    }

    // note: this is done in binary to represent u exactly
    // example:   u=10.1001  -->  s = "101001", e = 2
    s = mpfr_get_str (NULL, &e, 2, 0, u, GMP_RNDN);
    sz = strlen(s);

    t = s+sz;
    while (*(--t) == '0')
	*t = '\0'; // trim trailing zeros

    sz = strlen(s);
    bits = (*s == '-') ? sz-1 : sz; // bits>0 since u!=0

    if (e>=bits) {
	e = sz+e-bits;
	// no denominator needed
	t = (char *) malloc((e+1)*sizeof(char));
	strcpy(t,s);
	for (k=sz; k<e; k++)
	    t[k] = '0';
	t[e] = '\0';
	mpq_set_str(w, t, 2);
	free(t);
	mpfr_free_str(s);
	return;
    }

    e = sz+bits-e+2;
    t = (char *) malloc((e+1)*sizeof(char));
    strcpy(t,s);
    t[sz++] = '/';
    t[sz++] = '1';
    for (k=sz; k<e; k++)
	t[k] = '0';
    t[e] = '\0';
    mpq_set_str(w, t, 2);
    free(t);
    mpfr_free_str(s);
}


