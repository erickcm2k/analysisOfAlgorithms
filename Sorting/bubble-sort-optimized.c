#include "stdio.h"
#include "stdbool.h"
void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void bubbleSortOptimized(int *numbers, int size)
{
    bool changes = true;
    int i = 0;
    while ((i < size) && (changes != false))
    {
        changes = false;
        for (int j = 0; j < (size - 1) - i; j++)
        {
            if (numbers[i] < numbers[j])
            {
                swap(&numbers[i], &numbers[j]);
                changes = true;
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

    bubbleSortOptimized(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}

