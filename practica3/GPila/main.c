#include "gcola.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int main () {
  Pila pila;
  pila = pila_crear();
  int *uno = malloc(sizeof(int)); 
  int *dos = malloc(sizeof(int));
  int *tres = malloc(sizeof(int));

  *uno = 13;
  *dos = 14;
  *tres = 15;

  pila = pila_apilar(pila, uno);
  pila = pila_apilar(pila, dos);
  pila = pila_apilar(pila, tres);

  pila_imprimir(pila);
  printf("\nPila tope: %d", *(pila_tope(pila)));

  pila = pila_desapilar(pila);
  pila_imprimir(pila);
  printf("\nPila tope: %d", *(pila_tope(pila)));

  pila_imprimir(NULL);
  //DUDA POSTA TENGO QUE LLEVARLO A NULL
  // DESPUES??????
  pila_destruir(pila);
  pila = NULL;  //ESTO ME PARECE RARO

  pila_imprimir(pila);


  
  return 0;
}