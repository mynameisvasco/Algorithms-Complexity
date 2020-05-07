#include<stdio.h>

void printArray(char* s, int* a, int size)
{
    printf("%s :", s);
    for(int i = 0; i < size; i++)
    {
        printf("%d,", a[i]);
    }
    printf("\n");
}

void cumSum(int* a, int* b, int size)
{
    int c = 0;
    for(int i = 0; i < size; i++)
    {
        c = c + a[i];
        b[i] = c;
    }
    printf("\n");
}

int main(void)
{
    int a[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    printArray("a", a, 12);

    int b[12];
    cumSum(a, b, 12);
    printArray("b", b, 12);

    return 0;
}
