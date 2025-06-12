#include "pila.h"
#include <stdio.h>
#include <stdlib.h>
/*struct _Pila {
  ArregloEnteros *arr; arr[0] == *(arr+0)
  int ultimo;
};
typedef struct _Pila* Pila;
*/
Pila pila_crear(int size) {
  //Pila pila = malloc(sizeof(Pila));
  Pila pila = malloc(sizeof(Pila));
  pila->arr = arreglo_enteros_crear(size);
  pila->ultimo = -1;
  return pila;
}

void pila_destruir (Pila pila) {
  arreglo_enteros_destruir(pila->arr);
  free(pila);
}

int pila_es_vacia(Pila pila) {
  return pila->ultimo == -1;
}

int pila_tope (Pila pila) {
  if(!pila_es_vacia(pila))
    return pila->arr->direccion[pila->ultimo];
  else return -1;
}

void pila_apilar(Pila pila, int num) {
  pila->arr->direccion[(pila->ultimo)+1] = num;
  pila->ultimo++;
  //realocar
}

void pila_desapilar(Pila pila) {
  //pop
  //cuand esta vacia
  if(!pila_es_vacia(pila))
    pila->ultimo--;
}

void pila_imprimir (Pila pila) {
  printf("Pila: ");
  int size = pila->ultimo + 1;
  for(int i = 0; i < size; i++) {
    printf("%d\n", pila->arr->direccion[i]);
  }
}