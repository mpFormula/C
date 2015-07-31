#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <gmp.h>
#include <mpfr.h>
#include <flint.h>
#include <fmpz.h>
#include <fmpz_mat.h>
#include <fmpq.h>
#include <fmpq_mat.h>
#include "arb.h"
#include "arb_mat.h"

# include "fmpzxx.h"


using namespace std;

void t0()
{
    cout << "Hello world!" << endl;
    int i = 1;
    cout << sizeof(long) << " " << sizeof(void*) << endl ;
     i = i + 3;

    mpz_t x;
    mpz_t y;
    mpz_t z;

    mpz_init(x);
    mpz_init(y);
    mpz_init(z);
    mpz_set_ui(x, 2);
    mpz_set_ui(y,3);
    mpz_add(z,y,x);

    gmp_printf("%s is an mpz %Zd\n", "here", z);
    printf("Hello world!\n");
    mpz_clear(x);
    mpz_clear(y);
    mpz_clear(z);
}

void t1()
{
   mpfr_t a;
    mpfr_t b;
    mpfr_t c;

    mpfr_init(a);

    mpfr_init(b);
    mpfr_init(c);

    mpfr_set_ui(a,886,MPFR_RNDN);
    mpfr_set_ui(b,65478,MPFR_RNDN);
    mpfr_mul(c,a,b,MPFR_RNDN);

    mpfr_out_str(0, 10, 0, c, MPFR_RNDN);
    mpfr_clear(a);
    mpfr_clear(b);
    mpfr_clear(c);
    printf(" \n");
}


void t2()
{
    fmpz_t x, y;
    fmpz_init (x);
    fmpz_init (y);
    fmpz_set_ui (x, 7);
    fmpz_mul (y, x, x);
    fmpz_print (x);
    flint_printf ("^2 = ");
    fmpz_print (y);
    flint_printf ("\n");
    fmpz_clear (x);
    fmpz_clear (y);

}


void t2a()
{
    fmpq_t x, y;
    fmpq_init (x);
    fmpq_init (y);
    fmpq_set_si (x, 7, 5);
    fmpq_mul (y, x, x);
    fmpq_print (x);
    flint_printf ("^2 = ");
    fmpq_print (y);
    flint_printf ("\n");
    fmpq_clear (x);
    fmpq_clear (y);

}


void t3()
{
    arb_t x;
    arb_init(x);
    arb_const_pi(x, 50 * 3.33);
    arb_printd(x, 50); printf("\n");
    arb_clear(x);

}


void t4()
{
    using namespace flint ;
    fmpzxx x, y;
    x = 7u;
    y = x*x;
    std :: cout << x << "^2 = " << y << std :: endl ;
}


void t5()
{
    long i, j;
    fmpz_mat_t A;
    fmpz_mat_t B;
    fmpz_mat_init (A, 2, 2);
    fmpz_mat_init (B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    fmpz_set_ui ( fmpz_mat_entry (A, i, j), 2*i+j);
    fmpz_mat_mul (B, A, A);
    flint_printf ("A = \n");
    fmpz_mat_print_pretty (A);
    flint_printf ("\n");
    flint_printf ("A^2 = \n");
    fmpz_mat_print_pretty (B);
    fmpz_mat_clear (A);
    fmpz_mat_clear (B);
}


void t6()
{
    long i, j;
    fmpq_mat_t A;
    fmpq_mat_t B;
    fmpq_mat_init (A, 2, 2);
    fmpq_mat_init (B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    fmpz_set_ui ( fmpq_mat_entry_num (A, i, j), 2*i+j);
    fmpq_mat_mul (B, A, A);
    flint_printf ("A = \n");
    fmpq_mat_print (A);
    flint_printf ("A^2 = \n");
    fmpq_mat_print (B);
    fmpq_mat_clear (A);
    fmpq_mat_clear (B);
}

void t7()
{
    long digits = 20;
    long prec = 60;
    long i, j;
    arb_mat_t A;
    arb_mat_t B;
    arb_mat_init (A, 2, 2);
    arb_mat_init (B, 2, 2);
    for (i = 0; i < 2; i++)
    for (j = 0; j < 2; j++)
    arb_set_ui ( arb_mat_entry (A, i, j), 2*i+j);
    arb_mat_mul_classical (B, A, A, prec);
    flint_printf ("A = \n");
    arb_mat_printd (A, digits);
    flint_printf ("A^2 = \n");
    arb_mat_printd (B, digits);
    arb_mat_clear (A);
    arb_mat_clear (B);
}



void t5a()
{
    long n = 4;
    fmpz_mat_t A, B, C;
    fmpz_t den;
    FLINT_TEST_INIT(state);


    fmpz_mat_init (A, n, n);
    fmpz_mat_init (B, n, n);
    fmpz_mat_init (C, n, n);
    fmpz_init(den);

    fmpz_mat_randtest(A, state, 20);
    flint_printf ("A = \n");
    fmpz_mat_print_pretty (A);

    int result = fmpz_mat_inv(B, den, A);

    flint_printf ("\n B = \n");
    fmpz_mat_print_pretty (B);

    fmpz_mat_mul(C, A, B);

    flint_printf ("\n C = \n");
    fmpz_mat_print_pretty (C);

    flint_printf ("\n den = \n");
    fmpz_print (den);

    printf ("\n result: %d", result);
    fmpz_mat_clear (A);
    fmpz_mat_clear (B);
    fmpz_mat_clear (C);
    fmpz_clear (den);

    FLINT_TEST_CLEANUP(state);
}


void t6a()
{
    long n = 4;
    fmpq_mat_t A, B, C;
    FLINT_TEST_INIT(state);

    fmpq_mat_init (A, n, n);
    fmpq_mat_init (B, n, n);
    fmpq_mat_init (C, n, n);

    fmpq_mat_randtest(A, state, 20);
    flint_printf ("A = \n");
    fmpq_mat_print (A);

    int result = fmpq_mat_inv(B, A);

    flint_printf ("\n B = \n");
    fmpq_mat_print (B);

    fmpq_mat_mul(C, A, B);

    flint_printf ("\n C = \n");
    fmpq_mat_print (C);

    printf ("\n result: %d", result);
    fmpq_mat_clear (A);
    fmpq_mat_clear (B);
    fmpq_mat_clear (C);

    FLINT_TEST_CLEANUP(state);
}


void t7a()
{
    long digits = 20;
    long prec = 160;
    long n = 4;
    arb_mat_t A, B, C;
    fmpq_mat_t A_fmpq;
    FLINT_TEST_INIT(state);

    arb_mat_init (A, n, n);
    arb_mat_init (B, n, n);
    arb_mat_init (C, n, n);
    fmpq_mat_init (A_fmpq, n, n);

    fmpq_mat_randtest(A_fmpq, state, 20);
    arb_mat_set_fmpq_mat(A, A_fmpq, prec);
    flint_printf ("A = \n");
    arb_mat_printd (A, digits);

    int result = arb_mat_inv(B, A, prec);

    flint_printf ("\n B = \n");
    arb_mat_printd (B, digits);

    arb_mat_mul(C, A, B, prec);

    flint_printf ("\n C = \n");
    arb_mat_printd (C, digits);

    printf ("\n result: %d", result);
    arb_mat_clear (A);
    arb_mat_clear (B);
    arb_mat_clear (C);
    fmpq_mat_clear (A_fmpq);

    FLINT_TEST_CLEANUP(state);
}


int main()
{
//    t0();
//    t1();
//    t2();
//    t2a();
//    t3();
//    t4();
 //   t5();
//    t6();
//    t7();
//
//    t5a();
//    t6a();
    t7a();
//    char str [80];
//    scanf ("%s",str);
    return 0;
}

