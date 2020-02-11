#include <stdio.h>

int main()
{
    char name[50];
    puts("What is your name?");
    fgets(name, 50, stdin);
    printf("Hello %s!\n", name);
    return 0;
}