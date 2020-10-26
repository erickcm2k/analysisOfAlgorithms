#include "stdio.h"
#include "math.h"
#include "stdlib.h"

void swap(int *n1, int *n2)
{
    int temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}


void shellSort(int *numbers, int num)
{
    int j, k, tmp;
    for (int i = num / 2; i > 0; i = i / 2)
    {
        for (j = i; j < num; j++)
        {
            for (k = j - i; k >= 0; k = k - i)
            {
                if (numbers[k + i] >= numbers[k])
                    break;
                else
                {
                    tmp = numbers[k];
                    numbers[k] = numbers[k + i];
                    numbers[k + i] = tmp;
                }
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

    shellSort(numbers, dsSize);
    printf("Sorted numbers \n");
    for (int i = 0; i < dsSize; i++)
    {
        printf("%d \n", numbers[i]);
    }

    return 0;
}