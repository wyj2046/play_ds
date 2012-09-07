#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/* g(m, n) = 0                        (m = 0, n >= 0) */
/*            = g(m - 1, 2n) + n;        (m >= 0 0, n >= 0) *\/ */

int g_recurse(int m, int n)
{
    if (m == 0 && n >= 0) 
	return 0;
    return (g_recurse(m - 1, 2*n) + n);
}

int g_nonrecursive(int m, int n)
{
    int result = 0;;

    for (; m > 0 && n >= 0; m--, n *= 2) 
	result += n;

    return result;
}

 /* f(n) = n + 1         (n = 0) */
 /*           n * f(n/2)        (n > 0) */

int f_recurse(int n)
{
    if (n == 0) 
	return 1;
    return (n * f_recurse(n/2));
}

int f_nonrecursive(int n)
{
    int result = 1;
    for (; n != 0; n = n / 2)
    {
	result = n * result;
    }
    
    return result;
}

int f_nonrecursive2(int n)
{
    int result;

    for (result = 1; n > 0; n /= 2) 
	result *= n;

    return result++;
}

int factorial(int n)
{
    if (n == 0)
    {
	return 1;
    }
    else
    {
	return factorial(n-1) * n;
    }
}

int factorial_tail_recursive(int n, int acc)
{
    if (n == 0)
    {
	return acc;
    }
    return factorial_tail_recursive(n-1, acc*n);
}

int factorial_loop_optimized(int n, int acc)
{
    while (true)
    {
	if (n == 0)
	{
	    return acc;
	}
	acc *= n;
	n--;
    }
}

int nonfactorial(int n)
{
    int result = 1;
    for (; n > 0; --n)
    {
	result = result * n;
    }
    return result;
}

int fibonacci (int n)
{
    if (n < 2)
    {
	return n;
    }
    else
    {
	return fibonacci(n-1) + fibonacci(n-2);
    }
}

int fibonacci_tail_recursive(int n, int acc1, int acc2)
{
    if (n == 0)
    {
	return acc1;
    }
    return fibonacci_tail_recursive(n-1, acc2, acc1+acc2);
}

int fibonacci_loop_optimized(int n, int acc1, int acc2)
{
    while (true)
    {
	if (n == 0)
	{
	    return acc1;
	}
	int temp = acc1;
	acc1 = acc2;
	acc2 = temp + acc2;
	--n;
    }
}

/* int nonfibonacci (int n) */
/* { */
/*     int result = 0; */
/*     for (; n >= 2; ) */
/*     { */
	
/*     } */
/*     return result; */
/* } */

/* akm(m, n) = n + 1;                        (m = 0时) */
/*                     akm(m - 1, 1);                (n = 0时) */
/*                     akm(m - 1, akm(m, n - 1));        (m != 0且n != 0时) */

int akm_recursive(int m, int n)
{
    if (m == 0)
    {
	return n+1;
    }
    else if (n == 0)
    {
	return akm_recursive(m-1, 1);
    }
    else
    {
	int temp = akm_recursive(m, n-1);
	return akm_recursive(m-1, temp);
    }
}

int main(int argc, char *argv[])
{
    /* int result = g_recurse(5, 10); */
    /* printf ("%d\n", result); */
    /* result = g_nonrecursive(5, 10); */
    /* printf ("%d\n", result); */

    /* int result = f_recurse(10); */
    /* printf ("%d\n", result); */
    /* result = f_nonrecursive(10); */
    /* printf ("%d\n", result); */

    /* int result = factorial(5); */
    /* printf ("%d\n", result); */
    /* result = nonfactorial(5); */
    /* printf ("%d\n", result); */

    /* int result = fibonacci(7); */
    /* printf ("%d\n", result); */
    /* result = fibonacci_tail_recursive(7, 0, 1); */
    /* printf ("%d\n", result); */
    /* result = fibonacci_loop_optimized(7, 0, 1); */
    /* printf ("%d\n", result); */
    
    /* int result = akm_recursive(4, 0); */
    /* printf ("%d\n", result); */

    int result = f(100);
    printf ("%d\n", result);
    return 0;
}
