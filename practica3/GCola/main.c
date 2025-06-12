#include <stdio.h>
#include <stdlib.h>
#include "cola.h"
#include <time.h>

static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int main(int argc, char *argv[]) {

  DList lista = dlist_crear();
  lista = dlist_agregar_final(lista, 10);
  lista = dlist_agregar_inicio(lista, 5);
  lista = dlist_agregar_final(lista, 20);

  printf("Recorrido hacia adelante: ");
  dlist_recorrer(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_DELANTE);
  printf("\n");
  dlist_recorrer_rec(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_DELANTE);

  printf("\nRecorrido hacia atrás: ");
  dlist_recorrer(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_ATRAS);
  printf("\n");
  dlist_recorrer_rec(lista, imprimir_entero, DLIST_RECORRIDO_HACIA_ATRAS);

  dlist_destruir(lista);

  printf("\nCOLAS\n");
  Cola cola = cola_crear();
  cola = cola_encolar(cola, 29);
  cola = cola_encolar(cola, 30);
  cola = cola_encolar(cola, 31);
  cola = cola_encolar(cola, 32);
  cola_imprimir(cola);
  printf("\nDesencolo: ");
  cola = cola_desencolar(cola);
  cola = cola_desencolar(cola);
  cola_imprimir(cola);
  cola_destruir(cola);
  cola = cola_crear();
  cola_imprimir(cola);

  return 0;
}
