#include <stdio.h>
#include <stdlib.h>

int busqBin(int* numero, int cant, int busqueda, int max){
    
    int i, min, med;
    min = max / 2;
    
    if(max > cant){
        max = cant;
    }
    med = (min + max) / 2;
    
    while(min <= max){
        med = (min + max) / 2;
        
        if(busqueda == numero[med]){
            return med + 1;
        }    
        else if(busqueda < numero[med]){
            max = med - 1;
        }
        else{
            min = med + 1;
        }
    }
    
    return -1;
}

int busqExp(int* numero, int max, int busqueda){
    int i = 1;
    
    if(numero[0] == busqueda){
        return 0;
    }
    
    while(i < max && numero[i] <= busqueda){
            i *= 2;
    }
    
    return busqBin(numero, max, busqueda, i);
    
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
            
            b = busqExp(numero, n, busqueda);
            
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
