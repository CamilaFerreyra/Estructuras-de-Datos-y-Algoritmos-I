#include "arregloenteros.h"
#include <stdio.h>
#include <stdlib.h>

ArregloEnteros* arreglo_enteros_crear(int capacidad){

    ArregloEnteros* bloque = malloc(sizeof(ArregloEnteros)); 

    bloque->capacidad=capacidad;

    bloque->direccion = malloc(sizeof(int) * capacidad);

    return bloque;
}

void arreglo_enteros_destruir(ArregloEnteros* arreglo){
    free (arreglo->direccion);
    free (arreglo);
}

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos){
    return arreglo->direccion[pos];
}

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato){
    arreglo->direccion[pos] = dato; 
}

int arreglo_enteros_capacidad(ArregloEnteros* arreglo){
    return arreglo->capacidad;
}
void arreglo_enteros_imprimir(ArregloEnteros* arreglo){
    for (int i=0; i<arreglo->capacidad; i++){
        printf("%d ", arreglo->direccion[i]);
    }
    printf("\n");
}

void arregloenterosajustar(ArregloEnteros* arreglo, int capacidad){
    arreglo->direccion = realloc(arreglo->direccion, sizeof(int)*capacidad);
}
