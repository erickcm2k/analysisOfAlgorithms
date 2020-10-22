#include "stdio.h"
long long movements = 0;
int test[] = {-1, 0, 1, 2, 3, 5, 15, 20, 100, 409, 500, 593, 1000, 1471, 1500, 2801, 3000, 5000, 10000, 20000};
void function1(int i)
{
    for (int j = 10; j < 5 * test[i]; j *= 2)
    {
        movements++;
    }
    printf("[%d] -> %lld \n", test[i], movements);
    movements = 0;
}

void function2(int i)
{
    for (int j = test[i]; j > 1; j /= 2)
    {
        printf("j = %d ; test[i]/2 = %d \n", j, test[i] / 2);
        if (j < (test[i] / 2))
        {
            for (int k = 0; k < test[i]; k += 2)
            {
                movements++;
                // printf("Algoritmos");
            }
        }
        // if (j < (test[i] / 2))
        // {
        //     for (int k = 0; k < test[i]; k += 2)
        //     {
        //         movements++;
        //         // printf("Algoritmos");
        //     }
        // }
    }
    printf("[%d] -> %lld \n", test[i], movements);
    movements = 0;
}

void function3(int n)
{
    for (int i = 0; i < 5 * test[n]; i += 2)
    {
        for (int j = 0; j < 2 * test[n]; j++)
        {
            for (int k = j; k < test[n]; k++)
            {
                movements++;
            }
        }
    }
    printf("[%d] -> %lld \n", test[n], movements);
    movements = 0;
}

int main()
{
    // scanf("%d", &n);

    for (int i = 0; i < 20; i++)
    {
        function3(i);
    }
}