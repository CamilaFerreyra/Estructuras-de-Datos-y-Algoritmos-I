#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

static void imprimir_entero(int data) {
  printf("%d ", data);
}

static void imprimir_entero_extra(int data, void *extra) {
  printf("%d %s\n", data, (char*)extra);
}

static void suma_enteros_extra(int data, void *extra) {
  *(int*)extra += data; 
}

int main() {
  BTree ll = btree_unir(1, btree_crear(), btree_crear());
  BTree l = btree_unir(2, ll, btree_crear());
  BTree r = btree_unir(3, btree_crear(), btree_crear());
  BTree raiz = btree_unir(4, l, r);

  printf("Pre-order: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_PRE, imprimir_entero);
  puts("");
  
  printf("In-order: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_IN, imprimir_entero);
  puts("");
  
  printf("Post-order: ");
  btree_recorrer(raiz, BTREE_RECORRIDO_POST, imprimir_entero);
  puts("");

  printf("Number of nodes: %d\n", btree_nnodos(raiz));
  printf("Height: %d\n", btree_altura(raiz));
  printf("Searching for 3: %s\n", btree_buscar(raiz, 3) ? "Found" : "Not found");
  printf("Searching for 5: %s\n", btree_buscar(raiz, 5) ? "Found" : "Not found");
  printf("Profundidad de 4: %d\n", btree_profundidad(raiz, 4));
  printf("Profundidad de 2: %d\n", btree_profundidad(raiz, 2));
  printf("Profundidad de 1: %d\n", btree_profundidad(raiz, 1));
  printf("Profundidad de 5: %d\n", btree_profundidad(raiz, 5));
  printf("Number of nodes at depth 1: %d\n", btree_nnodos_profundidad(raiz, 1));
  printf("Number of nodes at depth 2: %d\n", btree_nnodos_profundidad(raiz, 2));
  printf("Number of nodes at depth 3: %d\n", btree_nnodos_profundidad(raiz, 3));
  printf("Suma total: %d\n", btree_sumar(raiz));

  char* palabra = "extra";
  printf("Recorrido extra:\n");
  btree_recorrer_extra(raiz, BTREE_RECORRIDO_IN, imprimir_entero_extra, palabra);
  int* suma = malloc(sizeof(int));
  *suma = 0;
  btree_recorrer_extra(raiz, BTREE_RECORRIDO_IN, suma_enteros_extra, suma);
  printf("sumatoria de datos: %i", *suma); 



  
  btree_destruir(raiz);
  return 0;
}
