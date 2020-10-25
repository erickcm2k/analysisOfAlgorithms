#include "stdio.h"

void insertionSort(int *numbers, int size)
{
    for (int i = 0; i < size; i++)
    {
        int j = i;
        int temp = numbers[i];
        while ((j > 0) && (temp < numbers[j - 1]))
        {
            numbers[j] = numbers[j - 1];
            j--;
        }
        numbers[j] = temp;
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

    insertionSort(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}