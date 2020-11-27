#include<stdio.h>
#include<stdlib.h>

int min(int x, int y){
    return (x<=y) ? x : y;
}

int busqFibo(int* numero, int n, int busqueda){
    int penultimo = 0, ultimo = 1, offset = -1, actual = penultimo + ultimo, i;
    
    while(actual < n){
        penultimo = ultimo;
        ultimo = actual;
        actual = penultimo + ultimo;
    }
    
    while(actual > 1){
        i = min(offset + penultimo, n-1);
        
        if(numero[i] < busqueda){
            actual = ultimo;
            ultimo = penultimo;
            penultimo = actual - ultimo;
            offset = i;
        }
        else if(numero[i] > busqueda){
            actual = penultimo;
            ultimo = ultimo - penultimo;
            penultimo = actual - ultimo;
        }
        else{
            return i+1;
        }
    }
    
    if(ultimo && numero[offset+1] == busqueda)
        return offset+1;
    
    return -1;
}

int main(int argc, char *argv[]){
    
    int i = 0, busqueda, b;
    int *numero;
    int n = 0;
    
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
            //n = sizeof(numero)/sizeof(numero[0]);
            b = busqFibo(numero, n, busqueda);
            
            if(b == -1){
                printf("No se encontró el número.\n");
            }
            else{
                printf("El número se encuentra en la posicion: %d\n", b);
            }
        }
    }
    return 0;
}
