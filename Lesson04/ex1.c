#include <stdio.h>

static int seq1[10] = {1, 3, 4, 5, 5, 6, 7, 7, 8, 9};
static int seq2[10] = {1, 2, 4, 5, 5, 6, 7, 8, 8, 9};
static int seq3[10] = {1, 2, 3, 6, 8, 8, 8, 9, 9, 9};
static int seq4[10] = {1, 2, 3, 4, 6, 7, 7, 8, 8, 9};
static int seq5[10] = {1, 2, 3, 4, 5, 7, 7, 8, 8, 9};
static int seq6[10] = {1, 2, 3, 4, 5, 6, 8, 8, 9, 9};
static int seq7[10] = {1, 2, 3, 4, 5, 6, 7, 9, 9, 9};
static int seq8[10] = {1, 2, 3, 4, 5, 6, 7, 8, 8, 9};
static int seq9[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 9};
static int seq10[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

int adds = 0;

int continua(int* seq, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        adds += 1;
        if(seq[i] + 1 != seq[i+1])
        {
            return 1;
        }
    }
    
    return 0;
}

int main(void)
{
    int result = continua(seq1, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;

    result = continua(seq2, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;

    result = continua(seq3, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq4, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq5, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq6, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq7, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq8, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq9, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    result = continua(seq10, 10);
    printf("Resultado: %d, Operacoes: %d\n", result, adds);
    adds = 0;
    

    return 0; 
}