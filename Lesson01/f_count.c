#include <stdio.h>

int count[4] = {0,0,0,0};

unsigned int f1 (unsigned int n)
{
    unsigned int i, j, r = 0;

    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
        {
            r += 1;
            count[0] += 1;
        }

    return r;
}

unsigned int f2 (unsigned int n)
{
    unsigned int i, j, r = 0;
    
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i; j++)
        {
            r += 1;
            count[1] += 1;
        }
    
    return r;
}

unsigned int f3 (unsigned int n)
{
    unsigned int i, j, r = 0;

    for (i = 1; i <= n; i++)
        for (j = i; j <= n; j++)
        {
            r += j;
            count[2] += 1;
        }

    return r;
}

unsigned int f4 (unsigned int n)
{
    unsigned int i, j, r = 0;

    for (i = 1; i <= n; i++)
        for (j = i; j >= 1; j /= 10)
        {
            r += i;
            count[3] += 1;
        }
    
    return r;
}

int main()
{
    int n = 0;
    printf("n -> ");
    scanf ("%d", &n);
    printf("n, f1(n), no iteracoes, f2(n), no iteracoes, f3(n), no iteracoes, f4(n), no iteracoes\n"); 
    for(int i = 0; i < n; i++)
    {
        int f1n = f1(i);
        int f2n = f2(i);
        int f3n = f3(i);
        int f4n = f4(i);
        printf("%d %6d %14d %4d %14d %4d %14d %4d %14d\n", i, f1n, count[0], f2n, count[1], f3n, count[2], f4n, count[3]);
        for(int k = 0; k < 4; k++)
        {
            count[k] = 0;
        }
    }
}