#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "PriorityQueue.h"

#define PCOLA_SIZE 10

PCola cola_prioridad_crear() {
  PCola PCola = malloc(sizeof(struct _PCola));
  PCola->arr = malloc(sizeof(void*) * PCOLA_SIZE);
  PCola->capacidad = 10;
  PCola->ultimo = -1;
  return PCola;
}

int cola_prioridad_es_vacia(PCola pCola) {
  return pCola->ultimo == -1;
}

int comp_key(Elem* a, Elem* b) {
  return a->key - b->key;
}

void* cola_dummy_copy(void* a) {
  return a;
}

void cola_dummy_dest(void* a) {
  (void) a;
  return;
}

void* cola_prioridad_maximo(PCola pCola) {
  //retorna el elemento de maxima prioridad, pero no lo elimina
  if(cola_prioridad_es_vacia(pCola)) {
    printf("No se puede obtener el elemento maximo, ya que la cola esta vacia.");
    return NULL;
  }
  //printf("voy a heapcolear");
  //crear un heap desde array y hacer pop
  BHeap bHeapPCola = bheap_crear_desde_arr(pCola->arr, pCola->ultimo+1, 
    (FuncionComparadora)comp_key,cola_dummy_copy,cola_dummy_dest);
  
  Elem* elemMax = bHeapPCola->arr[0];

  return elemMax;
}

int comp_dato(Elem* a, Elem* b) {
  return strcmp(a->dato, b->dato);
}

void dest_dato(void* dato) {
  free(dato);
  return;
}

void dest_elem(Elem* elem) {
  if(elem == NULL) return;
  free(elem->dato);
  free(elem);
}

void cola_prioridad_eliminar_maximo(PCola pCola) {
  if(cola_prioridad_es_vacia(pCola)) {
    printf("No se puede eliminar el elemento maximo, ya que la cola esta vacia.");
    return;
  }
  Elem* elemEliminar = (Elem*)cola_prioridad_maximo(pCola); //modo heap
  printf("Maximo actual: %s\n", (char*)elemEliminar->dato);
  //dest_elem(elemEliminar); // TODO: Arreglar, no anda

  free(elemEliminar);
  pCola->arr[0] = pCola->arr[pCola->ultimo--];

  return;
}

void cola_prioridad_insertar(PCola PCola, void* dato, int key) {
  //es necesario ver qué pasa cuando la cola esta vacia? 
  //nopi, -1 + 1 = 0.
  Elem* nuevoElem = malloc(sizeof(struct _Elem));
  assert(nuevoElem!= NULL);
  
  nuevoElem->dato = dato;
  nuevoElem->key = key;
  
  if(PCola->ultimo + 1 >= PCola->capacidad) {
    //busco más capacidad.
    PCola->arr = realloc(PCola->arr, sizeof(void*)*PCola->capacidad*2);
    assert(PCola->arr != NULL);
    PCola->capacidad *= 2;
  }
  PCola->arr[++PCola->ultimo] = (void*)nuevoElem;
}
