#include <stdio.h>

//Começa em -1 porque a chamada no main não conta
int t1Calls = -1;
int t2Calls = -1;
int t3Calls = -1;

int t1(int n)
{
    t1Calls++;

    if (n == 0)
        return 0;

    return (t1(n / 3) + n);
}

int t2(int n)
{
    t2Calls++;

    if (n <= 2)
        return n;

    return (t2(n / 3) + t2((n + 2) / 3) + n);
}

int t3(int n)
{
    t3Calls++;

    if (n <= 2)
        return n;

    if (n % 3 == 0)
        return 2 * t3(n / 3) + n;

    return (t3(n / 3) + t3((n + 2) / 3) + n);
}

int main(void)
{
    printf("n	T1(n)	N de Chamadas Recursivas	T2(n)	N de Chamadas Recursivas	T3(n)	N de Chamadas Recursivas\n");
    printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
    for (int n = 0; n <= 200; n++)
    {
        int t1res = t1(n);
        int t2res = t2(n);
        int t3res = t3(n);

        printf("%d %10d %16d %20d %20d %20d %15d\n", n, t1res, t1Calls, t2res, t2Calls, t3res, t3Calls);
        t1Calls = -1;
        t2Calls = -1;
        t3Calls = -1;
    }
}