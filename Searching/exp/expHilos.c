#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct struct_dato{
    int* numero;
    int n;
    int min;
    int max;
    int busqueda;
}dato;

void *busqBin(void *args){
    
    dato* dato1 = (dato*)args;
    int i = 0, med;
    
    if(dato1->max > dato1->n){
        dato1->max = dato1->n;
    }
    
    med = (dato1->min + dato1->max) / 2;
    
    while(dato1->min <= dato1->max){
        med = (dato1->min + dato1->max) / 2;
        
        if(dato1->busqueda == dato1->numero[med]){
            printf("Posicion: %d\n", med + 1);
            break;
        }    
        else if(dato1->busqueda < dato1->numero[med]){
            dato1->max = med - 1;
        }
        else{
            dato1->min = med + 1;
        }
    }
}

int busqExp(int* numero, int n, int busqueda){
    int i = 1;
    pthread_t hilo1;
    pthread_t hilo2;
    
    dato dato1, dato2;
    
    if(busqueda == numero[0]){
        printf("Posicion: 1\n");
        exit(0);
    }
    while(i <= n && numero[i] <= busqueda){
            i *= 2;
    }
    if(i > n){
        i = n;
    }
    
    dato1.numero=numero;
    dato1.n=n;
    dato1.busqueda=busqueda;
    dato1.min = ((i/2)+i)/2;
    dato1.max = i;
    
    dato2.numero=numero;
    dato2.n=n;
    dato2.busqueda=busqueda;
    dato2.min = i / 2;
    dato2.max = (((i/2)+i)/2)+1;
    
    pthread_create(&hilo1, NULL, busqBin, (void*)&dato1);
    pthread_create(&hilo2, NULL, busqBin, (void*)&dato2);
    
    pthread_join(hilo1,NULL);
    pthread_join(hilo2,NULL);
}

int main(int argc, char *argv[]){
    
    int n = 0, i = 0, busqueda, b;
    int *numero;
    
    if(argc < 3){
        printf("Modo de ejecucion: \"%s cantNum NumBusq\"\n", argv[0]);
        return -1;
    }
    else{
        n = atoi(argv[1]);
        busqueda = atoi(argv[2]);
        numero = malloc(sizeof(int) * n);
        if(numero == NULL){
            printf("Error al asignar memoria dinamica.\n");
            return -1;
        }
        else{
            for(i = 0; i < n; i++){
                scanf("%d", &numero[i]);
            }
            if(i == 0){
                printf("Lista de numeros vacia\n");
                return -1;
            }
            busqExp(numero, n, busqueda);
            
            
        }
    }
    return 0;
}
