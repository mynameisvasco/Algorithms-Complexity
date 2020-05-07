#include <stdio.h>
#include <assert.h>

static int seq1[10] = { 1, 2, 2, 2, 3, 3, 4, 5, 8, 8 };
static int seq2[10] = { 1, 2, 2, 2, 3, 3, 3, 3, 8, 8 };
static int seq3[7] = { 1, 2, 3, 2, 1, 3, 4 };
static int seq4[10] = { 1, 2, 5, 4, 7, 0, 3, 9, 6, 8 };
static int seq5[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };

int size = 10;
int shifts = 0;
int comps = 0;

void remove_duplicates(int* a, int* size)
{
    assert(size > 0);
    for(int i = 0; i < *size; i++)
    {
        for(int k = i + 1; k < *size; k++)
        {
            comps++;
            if(a[i] == a[k])
            {
                (*size)--;
                for(int j = k; j < *size; j++)
                {
                    a[j] = a[j+1];
                    shifts++;
                }
                k--;
            }
        }
    }
}

void print_arr(int* a, int* size)
{
    printf("[");

    for(int i = 0; i < *size; i++)
    {
        printf("%d,", a[i]);
    }

    printf("]");
}

int main(void) 
{
    print_arr(seq1, &size);
    remove_duplicates(seq1, &size);
    print_arr(seq1, &size);
    printf(" -> Comparacoes: %d Shifs: %d\n", comps, shifts);
    shifts = 0;
    comps = 0;

    print_arr(seq2, &size);
    remove_duplicates(seq2, &size);
    print_arr(seq2, &size);
    printf(" -> Comparacoes: %d Shifs: %d\n", comps, shifts);
    shifts = 0;
    comps = 0;

    size = 7;
    print_arr(seq3, &size);
    remove_duplicates(seq3, &size);
    print_arr(seq3, &size);
    printf(" -> Comparacoes: %d Shifs: %d\n", comps, shifts);
    shifts = 0;
    comps = 0;

    size = 10;
    print_arr(seq4, &size);
    remove_duplicates(seq4, &size);
    print_arr(seq4, &size);
    printf(" -> Comparacoes: %d Shifs: %d\n", comps, shifts);
    shifts = 0;
    comps = 0;

    size = 10;
    print_arr(seq5, &size);
    remove_duplicates(seq5, &size);
    print_arr(seq5, &size);
    printf(" -> Comparacoes: %d Shifs: %d\n", comps, shifts);
    shifts = 0;
    comps = 0;


    return 0;
}