#include "stdio.h"

void selectionSort(int *numbers, int size)
{
    for (int k = 0; k < size - 1; k++)
    {
        int p = k;
        for (int i = k; i < size; i++)
        {
            if (numbers[i] < numbers[p])
            {
                p = i;
            }
        }
        int temp = numbers[p];
        numbers[p] = numbers[k];
        numbers[k] = temp;
    }
}

int main(int argc, char const *argv[])
{
    int dsSize;
    scanf("%d", &dsSize);

    int numbers[dsSize];
    for (int i = 0; i < dsSize; i++)
    {
        scanf("%d", &numbers[i]);
    }

    selectionSort(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}