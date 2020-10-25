#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void shellSort(int *numbers, int n)
{
    int k = trunc(n / 2);
    while (k >= 1)
    {
        int b = 1;
        while (b != 0)
        {
            b = 0;
            for (int i = k; i > (n - 1); i--)
            {
                if (numbers[i - k] > numbers[i])
                {
                    // swap(&numbers[i], &numbers[i - k]);
                    int temp = numbers[i];
                    numbers[i] = numbers[i - k];
                    numbers[i - k] = temp;
                    b++;
                }
            }
        }
        k = trunc(k / 2);
    }
}

// void shellSort2(int *array, int n)
// {
//     for (int interval = n / 2; interval > 0; interval /= 2)
//     {
//         for (int i = interval; i < n; i++)
//         {
//             int temp = array[i];
//             int j;
//             for (j = i; j >= interval && array[j - interval] > temp; j -= interval)
//             {
//                 array[j] = array[j - interval];
//             }
//             array[j] = temp;
//         }
//     }
// }

int main(int argc, char const *argv[])
{
    int size = 10000000;
    int *array = malloc(size * sizeof(int));
    printf("%d", size);
    int dsSize;
    scanf("%d", &dsSize);

    int numbers[dsSize];
    for (int i = 0; i < dsSize; i++)
    {
        scanf("%d", &array[i]);
    }

    shellSort(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", array[i]);
    }

    return 0;
}