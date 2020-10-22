#include "stdio.h"
#include "math.h"

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void shellSort(int *numbers, int size)
{
    int k = trunc(size / 2);
    while (k >= 1)
    {
        int b = 1;
        while (b != 0)
        {
            b = 0;
            for (int i = k; i > (size - 1); i++)
            {
                if (numbers[i - k] > numbers[i])
                {
                    swap(&numbers[i], &numbers[i - k]);
                    b++;
                }
            }
        }
        k = trunc(k / 2);
    }
}
void shellSortGFG(int *numbers, int size)
{
    int k = trunc(size / 2);
    while (k >= 1)
    {
        int b = 1;
        while (b != 0)
        {
            b = 0;
            for (int i = k; i > (size - 1); i++)
            {
                if (numbers[i - k] > numbers[i])
                {
                    swap(&numbers[i], &numbers[i - k]);
                    b++;
                }
            }
        }
        k = trunc(k / 2);
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

    shellSortGFG(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}