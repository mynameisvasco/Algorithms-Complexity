#include <stdio.h>
#include <math.h>

int main()
{
    int n = 3;
    int iter = 0;
    for(int i = 0; i < 9; i++)
    {
        for(int k = 0; k < 9; k++)
        {
            for(int j = 0; j < 9; j++)
            {
                int number = i * 100 + k * 10  + j * 1;
                if(number > 100)
                {
                    int algSum = pow(i, n) + pow(k, n) + pow(j, n);
                    if(number == algSum)
                    {
                        printf("%d \n", number);
                    }
                }
            }
            iter++;
        }
    }

    printf("Finished after %d iterations", iter);
}