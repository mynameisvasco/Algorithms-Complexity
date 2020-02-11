#include<math.h>
#include<stdio.h>

int main(void)
{
    int rowNumber;

    printf("Row number:");
    scanf ("%d", &rowNumber);

    printf("number, square_root, square\n");
    printf("--------------------------------------\n");

    for(int i = 1; i < rowNumber + 1; ++i)
    {
        printf("%6d %12.4f %10d \n", i, sqrt(i), i*i);
    }

    return 0;
}