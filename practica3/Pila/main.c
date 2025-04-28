#include "pila.h"
#include <stdio.h>

int main () {
  Pila pila1 = pila_crear(2);
  pila_apilar(pila1, 13);
  pila_apilar(pila1, 14);
  pila_imprimir(pila1);


  printf("Tope: %d\n", pila_tope(pila1));

  pila_desapilar(pila1);
  printf("Tope: %d\n", pila_tope(pila1));
  pila_imprimir(pila1);

  //pila1->arr[0] = 13;
  //pila1->arr[1] = 14;

  pila_imprimir(pila1);
  
  return 0;
}