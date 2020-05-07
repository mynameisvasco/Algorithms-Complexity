#include <stdio.h>
#include <assert.h>
#include "elapsed_time.h"
#include <math.h>

/* definition of the 64-bit unsigned integer type */
typedef unsigned long long u64;

int pnn = 35;

u64 PnRecursive(int n)
{
    assert(n >= 0);
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }
    
    return 3 * PnRecursive(n-1) + 2 * PnRecursive(n-2);
}

u64 PnIterative(int n)
{
    assert(n >= 0);
    if(n == 0)
    {
        return 0;
    }
    else if(n == 1)
    {
        return 1;
    }

    u64 a = 0;
    u64 b = 1;
    u64 c = 0;

    for(int i = 2; i <= n; i++)
    {
        c = 3 * b + 2 * a;
        a = b;
        b = c;
    }

    return c;
}

u64 PnRecurrent(int n)
{
    long double a = powl(0.5 * (3 + sqrtl(17)), n);
    long double b = powl(0.5 * (3 - sqrtl(17)), n);

    return (a - b) / sqrtl(17);
}

u64 PnExp(int n)
{
    long double c1 = 0.24253562503633297352;
    long double c2 = 1.27019663313689157536;

    return round(c1 * exp(c2*n));
}

int main()
{
    (void)elapsed_time();
    u64 pn = PnRecursive(pnn);
    double time = elapsed_time();
    printf("P(%1d), Recursive -> %1llu, after %3.4f seconds\n", pnn, pn, time);


    (void)elapsed_time();
    pn = PnIterative(pnn);
    time = elapsed_time();
    printf("P(%1d), Iteration -> %1llu, after %3.4f seconds\n", pnn, pn, time);

    (void)elapsed_time();
    pn = PnRecurrent(pnn);
    time = elapsed_time();
    printf("P(%1d), Recurrent -> %1llu, after %3.4f seconds\n", pnn, pn, time);

    (void)elapsed_time();
    pn = PnExp(pnn);
    time = elapsed_time();
    printf("P(%1d), Exponencial -> %1llu, after %3.4f seconds\n", pnn, pn, time);
    
}