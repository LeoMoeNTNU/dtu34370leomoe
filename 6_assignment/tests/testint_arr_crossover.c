#include "../int_arr_crossover.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100

void print_array(int *arr, int length)
{
    for (int i = 0; i < length; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void)
{
    srand(time(NULL));
    int parent1[MAX_LENGTH] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int parent2[MAX_LENGTH] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    int child[MAX_LENGTH] = {0};

    int_arr_crossover(parent1, parent2, child, 10);
    print_array(child, 10);
    return 0;
}