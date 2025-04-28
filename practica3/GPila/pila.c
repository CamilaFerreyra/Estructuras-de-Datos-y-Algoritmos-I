#include "pila.h"
#include <stdio.h>
#include <stdlib.h>

void destruir (void *data) {
  free((int*)data);
}

void imprimir (int *data) {
  printf("%d ", *data);
}

void* copiar_entero(void *data) {
  int* copia = malloc(sizeof(int));
  *copia = *(int*)data;
  return copia;
}

Pila pila_crear() {
  return glist_crear();
  //Pila pila = NULL;
}

void pila_destruir (Pila pila) {
  printf("comienza aniquilación");
  glist_destruir(pila, free);
  //*pila = NULL;
}

int pila_es_vacia(Pila pila) {
  if (pila == NULL) return 1;
  else return 0;
  //return glist_vacia(pila);
 // return (pila == NULL);
}

int* pila_tope (Pila pila) {
  if(!pila_es_vacia(pila))
    return (pila->data);
  else return NULL;
}

Pila pila_apilar(Pila pila, int *dato) {
  return glist_agregar_inicio(pila, (void*)dato, copiar_entero);
  //realocar
}

Pila pila_desapilar(Pila pila) {
  //pop
  if(!pila_es_vacia(pila)) {
    Pila aux = pila;
    pila = pila->next;
    free(aux->data);
    free(aux);
  }
  return pila;
}

void pila_imprimir(Pila pila) {
  if(pila_es_vacia(pila)) {
    printf("Pila vacía.\n");
  }
  else {
    printf("\nPila: ");
    Pila pilaInvertida = pila_invertir(pila);
    glist_recorrer(pilaInvertida, (FuncionVisitante)imprimir);
    //seria correcto aliminar la invertida
  }
}

Pila pila_invertir(Pila pila) {
  if(!(pila_es_vacia(pila))) {
    Pila pilaInvertida = pila_crear();
    Pila aux = pila;
    while (!pila_es_vacia(aux)) {
      pilaInvertida = pila_apilar(pilaInvertida, aux->data);
      aux = aux->next;
    }
    return pilaInvertida;
  }
  return pila;
}