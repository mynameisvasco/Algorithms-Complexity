#include<stdio.h>

int main(void)
{
    char c = 'c';
    short s = 1;
    int i = 3;
    long l = 3;
    long long ll = 123;
    float f = 12.2;
    double d = 12.3;

    printf("sizeof(void*) --> %d\n", sizeof(void *));
    printf("sizeof(char) --> %d\n", sizeof(c));
    printf("sizeof(int) --> %d\n", sizeof(i));
    printf("sizeof(long) --> %d\n", sizeof(l));
    printf("sizeof(long long) --> %d\n", sizeof(ll));
    printf("sizeof(float) --> %d\n", sizeof(f));
    printf("sizeof(double) --> %d\n", sizeof(d));
    return 0;
}