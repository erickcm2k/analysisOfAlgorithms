#include "stdio.h"
long long movements = 0;
int test[] = {-1, 0, 1, 2, 3, 5, 15, 20, 100, 409, 500, 593, 1000, 1471, 1500, 2801, 3000, 5000, 10000, 20000};

void function1(int n)
{
    for (int j = 10; j < 5 * n; j *= 2)
    {
        movements++;
    }
    printf("[%d] -> %lld \n", n, movements);
    movements = 0;
}

void function2(int n)
{
    for (int j = n; j > 1; j /= 2)
    {
        if (j < (n / 2))
        {
            for (int k = 0; k < n; k += 2)
            {
                movements++;
            }
        }
    }
    movements = 0;
    printf("[%d] -> %lld \n", n, movements);
}

void function3(int n)
{
    for (int i = 0; i < 5 * n; i += 2)
    {
        for (int j = 0; j < 2 * n; j++)
        {
            for (int k = j; k < n; k++)
            {
                movements++;
            }
        }
    }
    printf("[%d] -> %lld \n", n, movements);
    movements = 0;
}

void function4(int n)
{
    int i = n;
    while (i > 0)
    {
        for (int j = n; i < j; j /= 2)
        {
            movements++;
        }
    }
    printf("[%d] -> %lld \n", n, movements);
    movements = 0;
}

void function5(int n)
{
    for (int i = 1; i < 4 * n; i *= 2)
    {
        for (int j = i; j < 5 * n; j += 3)
        {
            movements++;
        }
    }
    printf("[%d] -> %lld \n", n, movements);
    movements = 0;
}

int main()
{
    // scanf("%d", &n);

    for (int i = 0; i < 20; i++)
    {
        function5(test[i]);
    }
}