#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tiempo.h"
  
int search(int arr[], int n, int x) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        if (arr[i] == x) 
            return i; 
    return -1; 
} 

/*int main(void) 
{ 
    int arr[] = { 2, 3, 4, 10, 40 }; 
    int x = 40; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int result = search(arr, n, x); 
    (result == -1) 
        ? printf("Element is not present in array\n") 
        : printf("Element is present at index %d\n", result); 
    return 0; 
}*/
int main(int argc,char *argv[]){
    double utime0, stime0, wtime0,utime1, stime1, wtime1;
    int *A,n,i;
    n=atoi(argv[1]);
    int x = 1843349527; 
    uswtime(&utime0, &stime0, &wtime0);
    A=malloc(sizeof(int)*n);
    
    for(i=0;i<n;i++)
        scanf("%d",&A[i]);
        /*for(i=0;i<n;i++)
        printf("%d\n",A[i]);*/
    
     int result = search(A, n, x); 
    (result == -1) 
        ? printf("Element is not present in array\n") 
        : printf("Element is present at index %d\n", result);


    uswtime(&utime1, &stime1, &wtime1);
    printf("\n");
	printf("real (Tiempo total)  %.10f s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10f s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	
	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n",  wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n",  utime1 - utime0);
	printf("sys (Tiempo en acciónes de E/S)  %.10e s\n",  stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n",100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
    
    return 0;
}