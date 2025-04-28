#ifndef ARREGLOENTEROS_H
#define ARREGLOENTEROS_H

typedef struct {
    int* direccion;
    int capacidad;
    } ArregloEnteros;

ArregloEnteros* arreglo_enteros_crear(int capacidad);

void arreglo_enteros_destruir(ArregloEnteros* arreglo);

int arreglo_enteros_leer(ArregloEnteros* arreglo, int pos);

void arreglo_enteros_escribir(ArregloEnteros* arreglo, int pos, int dato);

int arreglo_enteros_capacidad(ArregloEnteros* arreglo);

void arreglo_enteros_imprimir(ArregloEnteros* arreglo);

void arregloenterosajustar(ArregloEnteros* arreglo, int capacidad); //que ajuste el
//tamano del arreglo. Si la nueva capacidad es menor, el contenido debe ser truncado.

//void arregloenterosinsertar(ArregloEnteros* arreglo, int pos, int dato);


#endif 
