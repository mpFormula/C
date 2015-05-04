/* Copyright 2011 David Cleaver
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */


#include <stdio.h>
#include <gmp.h>

/**********************************************************************************************************/

int mpz_lucasu(mpz_t rop, long int p, long int q, mpz_t k)
{
  /* Adaptation of algorithm found in http://joye.site88.net/papers/JQ96lucas.pdf
  /* calculate u[k] of Lucas U sequence for p,q. */
  /* Note: p^2-4q=0 is not tested, not a proper Lucas sequence!! */
  /* Stores U_k(p,q) in rop, Returns 1 on success, 0 on error. */

  int s = 0, j = 0;
  mpz_t uh, vl, vh, ql, qh, tmp;

  int ret_error = 0;
  int ret_success = 1;

  if ((p*p - 4*q) == 0) return ret_error;

  /* {easy out for k<=0, k<0 is handled as k=0} */
  if (mpz_cmp_ui(k,1) < 0)
  {
    mpz_set_ui(rop, 0);
    return ret_success;
  }

  mpz_init_set_si(uh, 1);
  mpz_init_set_si(vl, 2);
  mpz_init_set_si(vh, p);
  mpz_init_set_si(ql, 1);
  mpz_init_set_si(qh, 1);
  mpz_init_set_si(tmp,0);

  s = mpz_scan1(k, 0);
  for (j = mpz_sizeinbase(k,2)-1; j >= s+1; j--)
  {
    /* ql = ql*qh */
    mpz_mul(ql, ql, qh);
    if (mpz_tstbit(k,j) == 1)
    {
      /* qh = ql*q */
      mpz_mul_si(qh, ql, q);

      /* uh = uh*vh */
      mpz_mul(uh, uh, vh);

      /* vl = vh*vl - p*ql */
      mpz_mul(vl, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vl, vl, tmp);

      /* vh = vh*vh - 2*qh */
      mpz_mul(vh, vh, vh);
      mpz_mul_si(tmp, qh, 2);
      mpz_sub(vh, vh, tmp);
    }
    else
    {
      /* qh = ql */
      mpz_set(qh, ql);

      /* uh = uh*vl - ql */
      mpz_mul(uh, uh, vl);
      mpz_sub(uh, uh, ql);

      /* vh = vh*vl - p*ql */
      mpz_mul(vh, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vh, vh, tmp);

      /* vl = vl*vl - 2*ql */
      mpz_mul(vl, vl, vl);
      mpz_mul_si(tmp, ql, 2);
      mpz_sub(vl, vl, tmp);
    }
  }
  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  /* qh = ql*q */
  mpz_mul_si(qh, ql, q);

  /* uh = uh*vl - ql */
  mpz_mul(uh, uh, vl);
  mpz_sub(uh, uh, ql);

  /* vl = vh*vl - p*ql */
  mpz_mul(vl, vh, vl);
  mpz_mul_si(tmp, ql, p);
  mpz_sub(vl, vl, tmp);

  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  for (j = 1; j <= s; j++)
  {
    /* uh = uh*vl */
    mpz_mul(uh, uh, vl);

    /* vl = vl*vl - 2*ql */
    mpz_mul(vl, vl, vl);
    mpz_mul_si(tmp, ql, 2);
    mpz_sub(vl, vl, tmp);

    /* ql = ql*ql */
    mpz_mul(ql, ql, ql);
  }

  mpz_set(rop, uh); /* uh contains our return value */

  mpz_clear(uh);
  mpz_clear(vl);
  mpz_clear(vh);
  mpz_clear(ql);
  mpz_clear(qh);
  mpz_clear(tmp);

  return ret_success;
}/* method mpz_lucasu */

/**********************************************************************************************************/

int mpz_lucasumod(mpz_t rop, long int p, long int q, mpz_t k, mpz_t n)
{
  /* Adaptation of algorithm found in http://joye.site88.net/papers/JQ96lucas.pdf
  /* calculate u[k] (modulo n) of Lucas U sequence for p,q. */
  /* Note: p^2-4q=0 is not tested, not a proper Lucas sequence!! */
  /* Stores U_k(p,q) (mod n) in rop, Returns 1 on success, 0 on error. */

  int s = 0, j = 0;
  mpz_t uh, vl, vh, ql, qh, tmp;

  int ret_error = 0;
  int ret_success = 1;

  if ((p*p - 4*q) == 0) return ret_error;

  /* {easy out for k<=0, k<0 is handled as k=0} */
  if (mpz_cmp_ui(k,1) < 0)
  {
    mpz_set_ui(rop, 0);
    return ret_success;
  }

  mpz_init_set_si(uh, 1);
  mpz_init_set_si(vl, 2);
  mpz_init_set_si(vh, p);
  mpz_init_set_si(ql, 1);
  mpz_init_set_si(qh, 1);
  mpz_init_set_si(tmp,0);

  s = mpz_scan1(k, 0);
  for (j = mpz_sizeinbase(k,2)-1; j >= s+1; j--)
  {
    /* ql = ql*qh (mod n) */
    mpz_mul(ql, ql, qh);
    mpz_mod(ql, ql, n);
    if (mpz_tstbit(k,j) == 1)
    {
      /* qh = ql*q */
      mpz_mul_si(qh, ql, q);

      /* uh = uh*vh (mod n) */
      mpz_mul(uh, uh, vh);
      mpz_mod(uh, uh, n);

      /* vl = vh*vl - p*ql (mod n) */
      mpz_mul(vl, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vl, vl, tmp);
      mpz_mod(vl, vl, n);

      /* vh = vh*vh - 2*qh (mod n) */
      mpz_mul(vh, vh, vh);
      mpz_mul_si(tmp, qh, 2);
      mpz_sub(vh, vh, tmp);
      mpz_mod(vh, vh, n);
    }
    else
    {
      /* qh = ql */
      mpz_set(qh, ql);

      /* uh = uh*vl - ql (mod n) */
      mpz_mul(uh, uh, vl);
      mpz_sub(uh, uh, ql);
      mpz_mod(uh, uh, n);

      /* vh = vh*vl - p*ql (mod n) */
      mpz_mul(vh, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vh, vh, tmp);
      mpz_mod(vh, vh, n);

      /* vl = vl*vl - 2*ql (mod n) */
      mpz_mul(vl, vl, vl);
      mpz_mul_si(tmp, ql, 2);
      mpz_sub(vl, vl, tmp);
      mpz_mod(vl, vl, n);
    }
  }
  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  /* qh = ql*q */
  mpz_mul_si(qh, ql, q);

  /* uh = uh*vl - ql */
  mpz_mul(uh, uh, vl);
  mpz_sub(uh, uh, ql);

  /* vl = vh*vl - p*ql */
  mpz_mul(vl, vh, vl);
  mpz_mul_si(tmp, ql, p);
  mpz_sub(vl, vl, tmp);

  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  for (j = 1; j <= s; j++)
  {
    /* uh = uh*vl (mod n) */
    mpz_mul(uh, uh, vl);
    mpz_mod(uh, uh, n);

    /* vl = vl*vl - 2*ql (mod n) */
    mpz_mul(vl, vl, vl);
    mpz_mul_si(tmp, ql, 2);
    mpz_sub(vl, vl, tmp);
    mpz_mod(vl, vl, n);

    /* ql = ql*ql (mod n) */
    mpz_mul(ql, ql, ql);
    mpz_mod(ql, ql, n);
  }

  mpz_mod(rop, uh, n); /* uh contains our return value */

  mpz_clear(uh);
  mpz_clear(vl);
  mpz_clear(vh);
  mpz_clear(ql);
  mpz_clear(qh);
  mpz_clear(tmp);

  return ret_success;
}/* method mpz_lucasumod */

/**********************************************************************************************************/

int mpz_lucasv(mpz_t rop, long int p, long int q, mpz_t k)
{
  /* Adaptation of algorithm found in http://joye.site88.net/papers/JQ96lucas.pdf
  /* calculate v[k] of Lucas V sequence for p,q. */
  /* Note: p^2-4q=0 is not tested, not a proper Lucas sequence!! */
  /* Stores V_k(p,q) in rop, Returns 1 on success, 0 on error. */

  int s = 0, j = 0;
  mpz_t vl, vh, ql, qh, tmp;

  int ret_error = 0;
  int ret_success = 1;

  if ((p*p - 4*q) == 0) return ret_error;

  /* {easy out for k<=0, k<0 is handled as k=0} */
  if (mpz_cmp_ui(k,1) < 0)
  {
    mpz_set_ui(rop, 2);
    return ret_success;
  }

  mpz_init_set_si(vl, 2);
  mpz_init_set_si(vh, p);
  mpz_init_set_si(ql, 1);
  mpz_init_set_si(qh, 1);
  mpz_init_set_si(tmp,0);

  s = mpz_scan1(k, 0);
  for (j = mpz_sizeinbase(k,2)-1; j >= s+1; j--)
  {
    /* ql = ql*qh */
    mpz_mul(ql, ql, qh);
    if (mpz_tstbit(k,j) == 1)
    {
      /* qh = ql*q */
      mpz_mul_si(qh, ql, q);

      /* vl = vh*vl - p*ql */
      mpz_mul(vl, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vl, vl, tmp);

      /* vh = vh*vh - 2*qh */
      mpz_mul(vh, vh, vh);
      mpz_mul_si(tmp, qh, 2);
      mpz_sub(vh, vh, tmp);
    }
    else
    {
      /* qh = ql */
      mpz_set(qh, ql);

      /* vh = vh*vl - p*ql */
      mpz_mul(vh, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vh, vh, tmp);

      /* vl = vl*vl - 2*ql */
      mpz_mul(vl, vl, vl);
      mpz_mul_si(tmp, ql, 2);
      mpz_sub(vl, vl, tmp);
    }
  }
  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  /* qh = ql*q */
  mpz_mul_si(qh, ql, q);

  /* vl = vh*vl - p*ql */
  mpz_mul(vl, vh, vl);
  mpz_mul_si(tmp, ql, p);
  mpz_sub(vl, vl, tmp);

  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  for (j = 1; j <= s; j++)
  {
    /* vl = vl*vl - 2*ql */
    mpz_mul(vl, vl, vl);
    mpz_mul_si(tmp, ql, 2);
    mpz_sub(vl, vl, tmp);

    /* ql = ql*ql */
    mpz_mul(ql, ql, ql);
  }

  mpz_set(rop, vl); /* vl contains our return value */

  mpz_clear(vl);
  mpz_clear(vh);
  mpz_clear(ql);
  mpz_clear(qh);
  mpz_clear(tmp);

  return ret_success;
}/* method mpz_lucasv */

/**********************************************************************************************************/

int mpz_lucasvmod(mpz_t rop, long int p, long int q, mpz_t k, mpz_t n)
{
  /* Adaptation of algorithm found in http://joye.site88.net/papers/JQ96lucas.pdf
  /* calculate v[k] (modulo n) of Lucas V sequence for p,q. */
  /* Note: p^2-4q=0 is not tested, not a proper Lucas sequence!! */
  /* Stores V_k(p,q) (mod n) in rop, Returns 1 on success, 0 on error. */

  int s = 0, j = 0;
  mpz_t vl, vh, ql, qh, tmp;

  int ret_error = 0;
  int ret_success = 1;

  if ((p*p - 4*q) == 0) return ret_error;

  /* {easy out for k<=0, k<0 is handled as k=0} */
  if (mpz_cmp_ui(k,1) < 0)
  {
    mpz_set_ui(rop, 2);
    mpz_mod(rop, rop, n);
    return ret_success;
  }

  mpz_init_set_si(vl, 2);
  mpz_init_set_si(vh, p);
  mpz_init_set_si(ql, 1);
  mpz_init_set_si(qh, 1);
  mpz_init_set_si(tmp,0);

  s = mpz_scan1(k, 0);
  for (j = mpz_sizeinbase(k,2)-1; j >= s+1; j--)
  {
    /* ql = ql*qh (mod n) */
    mpz_mul(ql, ql, qh);
    mpz_mod(ql, ql, n);
    if (mpz_tstbit(k,j) == 1)
    {
      /* qh = ql*q */
      mpz_mul_si(qh, ql, q);

      /* vl = vh*vl - p*ql (mod n) */
      mpz_mul(vl, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vl, vl, tmp);
      mpz_mod(vl, vl, n);

      /* vh = vh*vh - 2*qh (mod n) */
      mpz_mul(vh, vh, vh);
      mpz_mul_si(tmp, qh, 2);
      mpz_sub(vh, vh, tmp);
      mpz_mod(vh, vh, n);
    }
    else
    {
      /* qh = ql */
      mpz_set(qh, ql);

      /* vh = vh*vl - p*ql (mod n) */
      mpz_mul(vh, vh, vl);
      mpz_mul_si(tmp, ql, p);
      mpz_sub(vh, vh, tmp);
      mpz_mod(vh, vh, n);

      /* vl = vl*vl - 2*ql (mod n) */
      mpz_mul(vl, vl, vl);
      mpz_mul_si(tmp, ql, 2);
      mpz_sub(vl, vl, tmp);
      mpz_mod(vl, vl, n);
    }
  }
  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  /* qh = ql*q */
  mpz_mul_si(qh, ql, q);

  /* vl = vh*vl - p*ql */
  mpz_mul(vl, vh, vl);
  mpz_mul_si(tmp, ql, p);
  mpz_sub(vl, vl, tmp);

  /* ql = ql*qh */
  mpz_mul(ql, ql, qh);

  for (j = 1; j <= s; j++)
  {
    /* vl = vl*vl - 2*ql (mod n) */
    mpz_mul(vl, vl, vl);
    mpz_mul_si(tmp, ql, 2);
    mpz_sub(vl, vl, tmp);
    mpz_mod(vl, vl, n);

    /* ql = ql*ql (mod n) */
    mpz_mul(ql, ql, ql);
    mpz_mod(ql, ql, n);
  }

  mpz_mod(rop, vl, n); /* vl contains our return value */

  mpz_clear(vl);
  mpz_clear(vh);
  mpz_clear(ql);
  mpz_clear(qh);
  mpz_clear(tmp);

  return ret_success;
}/* method mpz_lucasvmod */

/**********************************************************************************************************/

int main(int argc, char* argv[])
{
  int max_k = 20;
  int i = 0;
  int p = 1;
  int q = -1;
  mpz_t res;
  mpz_t n;
  mpz_t zk;
  mpz_t z1e6;

  if (argc != 4)
  {
    printf("usage: %s <p> <q> <n>\n", argv[0]);
    printf("where p,q are parameters defining the Lucas U and V sequences.\n");
    printf(" and use n to calculate the Lucas sequence modulo n.\n");
    printf(" (if n is < 2, no modulus is performed)\n");
    return 0;
  }

  mpz_init_set_ui(res, 0);
  mpz_init_set_ui(n, 0);
  mpz_init_set_ui(zk, 0);
  mpz_init_set_ui(z1e6, 1000000);

  p = strtol(argv[1], NULL, 10);
  q = strtol(argv[2], NULL, 10);
  mpz_set_str(n, argv[3], 10);

  printf("p = %d\n", p);
  printf("q = %d\n", q);
  gmp_printf("n = %Zd\n\n", n);

  printf("MPZ Lucas U Sequence:\n");
  for (i = 0; i < max_k; i++)
  {
    mpz_set_ui(zk, i);
    mpz_lucasu(res,p,q,zk);
    gmp_printf("%6Zd, ", res);
  }
  printf("\n\n");

  if (mpz_cmp_ui(n, 2) >= 0)
  {
    printf("MPZ Lucas U (Mod N) Sequence:\n");
    for (i = 0; i < max_k; i++)
    {
      mpz_set_ui(zk, i);
      mpz_lucasumod(res,p,q,zk,n);
      gmp_printf("%6Zd, ", res);
    }
    printf("\n\n");
  }

  printf("MPZ Lucas V Sequence:\n");
  for (i = 0; i < max_k; i++)
  {
    mpz_set_ui(zk, i);
    mpz_lucasv(res,p,q,zk);
    gmp_printf("%6Zd, ", res);
  }
  printf("\n\n");

  if (mpz_cmp_ui(n, 2) >= 0)
  {
    printf("MPZ Lucas V (Mod N) Sequence:\n");
    for (i = 0; i < max_k; i++)
    {
      mpz_set_ui(zk, i);
      mpz_lucasvmod(res,p,q,zk,n);
      gmp_printf("%6Zd, ", res);
    }
    printf("\n\n");
  }

  printf("Number of digits in the 1000000th Fibonacci number:\n");
  mpz_lucasu(res,1,-1,z1e6);
  printf("%d\n\n", mpz_sizeinbase(res, 10));

  mpz_clear(res);
  mpz_clear(n);
  mpz_clear(zk);
  mpz_clear(z1e6);

  return 0;
}
