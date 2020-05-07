#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int comp = 0;

int algc(int* array, int size)
{
    assert(size > 1);
    comp = 0;
    int max = 0;
    int maxI = 0;
    for(int i = 0; i < size; i++)
    {
        int count = 0;
        for(int k = 0; k < i; k++)
        {
            comp++;
            if(array[i] > array[k])
            {
                count++;
                if(count > max)
                {
                    max = count;
                    maxI = i;
                }
            }
        }
    }
    if(max == 0)
    {
        return -1;
    }
    return maxI;
}

int main()
{
    int array1[10] = { 1,  9,  2,  8,  3,  4,  5,  3,  7,  2 };
    int array2[10] = { 2,  2,  2,  2,  2,  2,  2,  2,  2,  2 };
    int array3[10] = { 1,  7,  4,  6,  5,  2,  3,  2,  1,  0 };
    int array4[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int array5[10] = {4, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int array6[10] = {4, 5, 3, 3, 3, 3, 3, 3, 3, 3};
    int array7[10] = {4, 5, 1, 3, 3, 3, 3, 3, 3, 3};
    int array8[10] = {4, 5, 1, 2, 3, 3, 3, 3, 3, 3};
    int array9[10] = {4, 5, 1, 2, 6, 3, 3, 3, 3, 3};
    int array10[10] = {4, 5, 1, 2, 6, 8, 3, 3, 3, 3};
    int array11[10] = {4, 5, 1, 2, 6, 8, 7, 3, 3, 3};
    int array12[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 3};
    int array13[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 0};
    


    int al = algc(array1, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array1[al], "comparacoes: ", comp, " indice: ", al);

    al = algc(array2, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array2[al], "comparacoes: ", comp, " indice:", al);

    al = algc(array3, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array3[al], "comparacoes: ", comp, " indice:", al );
    
    al = algc(array4, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array4[al], "comparacoes: ", comp, " indice:", al );

    al = algc(array5, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array5[al], "comparacoes: ", comp, " indice:", al );

    al = algc(array6, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array6[al], "comparacoes: ", comp, " indice:", al );

    al = algc(array7, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array7[al], "comparacoes: ", comp, " indice:", al );

    al = algc(array8, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array8[al], "comparacoes: ", comp, " indice:", al );


    al = algc(array9, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array9[al], "comparacoes: ", comp, " indice:", al );


    al = algc(array10, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array10[al], "comparacoes: ", comp, " indice:", al );


    al = algc(array11, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array11[al], "comparacoes: ", comp, " indice:", al );


    al = algc(array12, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array12[al], "comparacoes: ", comp, " indice:", al );

    al = algc(array13, 10);
    printf("%s %1d %s %1d %s %1d\n", "valor: ", array13[al], "comparacoes: ", comp, " indice:", al );

}