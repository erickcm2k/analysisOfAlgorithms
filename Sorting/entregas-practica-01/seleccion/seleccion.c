#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"

void seleccion(int *A, int n)
{
    int k, p, i, temp;
    for (k = 0; k < (n - 1); k++)
    {
        p = k;
        for (i = k + 1; i < n; i++)
        {
            if (A[i] < A[p])
            {
                p = i;
            }
        }
        temp = A[p];
        A[p] = A[k];
        A[k] = temp;
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
    seleccion(A, n);
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