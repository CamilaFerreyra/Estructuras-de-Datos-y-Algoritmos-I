#include "cola.h"
#include "dlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

void visit (int dato) {
    printf(" %d ", dato);
}

Cola cola_crear() {
  return dlist_crear();
}

void cola_destruir(Cola cola) {
  dlist_destruir(cola);
}

int cola_es_vacia(Cola cola) {
    return dlist_vacia(cola);
}

int cola_inicio(Cola cola) {
  if(!cola_es_vacia(cola))
   return cola.primero->dato;
  else
    return -1;
}

Cola cola_encolar (Cola cola, int dato) {
  DNodo *nodo = malloc(sizeof(DNodo));
  nodo->dato = dato;
  // DNodo* nodo = dlist_crear_nodo(dato);
  nodo->sig = NULL;
  nodo->ant = cola.ultimo;
  if(cola_es_vacia(cola)) {
    cola.primero = nodo;
  } else {
      (cola.ultimo)->sig = nodo;
    }
  cola.ultimo = nodo;
  return cola;
}

Cola cola_desencolar(Cola cola) {
  if(!cola_es_vacia(cola)) {
    DNodo *aux = cola.primero;
    cola.primero = aux->sig;
    (cola.primero)->ant = NULL;
    free(aux);
  }
  return cola;
}

void cola_imprimir (Cola cola) {
  dlist_recorrer(cola, (FuncionVisitante)visit, DLIST_RECORRIDO_HACIA_DELANTE);
}


