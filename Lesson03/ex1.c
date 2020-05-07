#include <stdio.h>
#include <math.h>
#include <assert.h>

int comp = 0;

int difLastElem(int* array, int size)
{
    assert(size > 1);
    comp = 0;
    int dif = 0;
    for(int i = 1; i < size; i++)
    {
        comp++;
        if(array[i] != array[i-1])
        {
            dif++;
        }
    }

    return dif;

}

int main()
{
    int array1[10] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int array2[10] = {4, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    int array3[10] = {4, 5, 3, 3, 3, 3, 3, 3, 3, 3};
    int array4[10] = {4, 5, 1, 3, 3, 3, 3, 3, 3, 3};
    int array5[10] = {4, 5, 1, 2, 3, 3, 3, 3, 3, 3};
    int array6[10] = {4, 5, 1, 2, 6, 3, 3, 3, 3, 3};
    int array7[10] = {4, 5, 1, 2, 6, 8, 3, 3, 3, 3};
    int array8[10] = {4, 5, 1, 2, 6, 8, 7, 3, 3, 3};
    int array9[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 3};
    int array10[10] = {4, 5, 1, 2, 6, 8, 7, 9, 3, 0};

    printf("%s %s\n", "Resultado", "Operacoes");
    int dif1 = difLastElem(array1, 10);
    printf("%1d %1d\n", dif1, comp);

    int dif2 = difLastElem(array2, 10);
    printf("%1d %1d\n", dif2, comp);

    int dif3 = difLastElem(array3, 10);
    printf("%1d %1d\n", dif3, comp);

    int dif4 = difLastElem(array4, 10);
    printf("%1d %1d\n", dif4, comp);

    int dif5 = difLastElem(array5, 10);
    printf("%1d %1d\n", dif5, comp);

    int dif6 = difLastElem(array6, 10);
    printf("%1d %1d\n", dif6, comp);

    int dif7 = difLastElem(array7, 10);
    printf("%1d %1d\n", dif7, comp);

    int dif8 = difLastElem(array8, 10);
    printf("%1d %1d\n", dif8, comp);

    int dif9 = difLastElem(array9, 10);
    printf("%1d %1d\n", dif9, comp);

    int dif10 = difLastElem(array10, 10);
    printf("%1d %1d\n", dif10, comp);
    return 0;
}