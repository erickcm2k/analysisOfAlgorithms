#include "stdio.h"
long long movements = 0;
int test[] = {-1, 0, 1, 2, 3, 5, 15, 20, 100, 409, 500, 593, 1000, 1471, 1500, 2801, 3000, 5000, 10000, 20000};
int A[] = {};

void f1(int n)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = n; j > 1; j /= 2)
        {
            movements++;
            int temp = A[j];
            A[j] = A[j + 1];
            A[j + 1] = temp;
        }
    }
    printf("[%d] -> %lld \n", n, movements);
    movements = 0;
}

int main()
{

    for (int i = 0; i < 20; i++)
    {
        f1(test[i]);
    }
}