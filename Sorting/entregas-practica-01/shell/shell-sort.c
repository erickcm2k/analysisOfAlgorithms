#include "stdio.h"
#include "math.h"
#include "stdlib.h"
#include "tiempo.h"

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
    double utime0, stime0, wtime0, utime1, stime1, wtime1, n;

    if (argc != 2)
    {
        printf("\nIndique el tamanio del algoritmo.\n", argv[0]);
        exit(1);
    }
    else
    {
        n = atoi(argv[1]);
    }

    int *numbers = (int *)malloc(sizeof(int) * n);
    printf("\n\nSize of test is: [%.0f]\n\n", n);
    // algorithm begin
    uswtime(&utime0, &stime0, &wtime0);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &numbers[i]);
    }

    shellSort(numbers, n);

    uswtime(&utime1, &stime1, &wtime1);

    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    return 0;
}