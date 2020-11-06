#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
void insercion(int *A, int n)
{
    int temp, i, j;
    for (i = 0; i < n; i++)
    {
        j = i;
        temp = A[i];
        while (j > 0 && temp < A[j - 1])
        {
            A[j] = A[j - 1];
            j--;
        }
        A[j] = temp;
    }
}

int main(int argc, char *argv[])
{
    double utime0, stime0, wtime0, utime1, stime1, wtime1;
    int *A, n, i;
    n = atoi(argv[1]);
    uswtime(&utime0, &stime0, &wtime0);
    A = malloc(sizeof(int) * n);

    for (i = 0; i < n; i++)
        scanf("%d", &A[i]);
    /*for(i=0;i<n;i++)
        printf("%d\n",A[i]);*/
    insercion(A, n);
    uswtime(&utime1, &stime1, &wtime1);
    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    //Mostrar los tiempos en formato exponecial
    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acciónes de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    return 0;
}