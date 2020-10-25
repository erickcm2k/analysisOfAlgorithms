#include "stdio.h"

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSort(int *numbers, int size)
{
    int swaps = 0;
    int movements = 0;
    printf("Sorted numbers \n");
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < (size - 1) - i; j++)
        {
            movements++;
            if (numbers[j] > numbers[j + 1])
            {
                swaps++;
                swap(&numbers[j], &numbers[j + 1]);
            }
        }
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

    bubbleSort(numbers, dsSize);

    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}
