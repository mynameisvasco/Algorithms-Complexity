#include <stdio.h>

int nMult = 0;

int motzkin(int n)
{
    if (n < 2)
        return 1;

    int sum = motzkin(n - 1);
    for (int k = 0; k <= n - 2; k++)
    {
        sum += motzkin(k) * motzkin(n - 2 - k);
        nMult++;
    }
    return sum;
}

int dynamicMotzkin(int n)
{
    int values[n + 1];
    for (int i = 0; i <= n; i++)
    {
        if (i < 2)
        {
            values[i] = 1;
            continue;
        }
        int a = values[i - 1];
        for (int k = 0; k <= i - 2; k++)
        {
            a += values[k] * values[i - 2 - k];
            nMult++;
        }
        values[i] = a;
    }
    return values[n];
}

int main(void)
{
    printf("n:  |  mottskin (rec) |  mults (rec)  |  mottskin (dynamic)  |  mults (dynamic)\n");
    for (int i = 0; i <= 15; i++)
    {
        printf("%1d %13d %13d", i, motzkin(i), nMult);
        nMult = 0;
        printf("%23d %15d\n ", dynamicMotzkin(i), nMult);
        nMult = 0;
    }
}