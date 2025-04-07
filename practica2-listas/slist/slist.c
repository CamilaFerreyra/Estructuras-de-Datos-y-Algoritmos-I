#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

SList slist_crear() {
  return NULL;
}

void slist_destruir(SList lista) {
  SNodo *nodoAEliminar;
  while (lista != NULL) {
    nodoAEliminar = lista;
    lista = lista->sig;
    free(nodoAEliminar);
  }
}

int slist_vacia(SList lista) {
  return lista == NULL;
}

SList slist_agregar_final(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = NULL;

  if (lista == NULL)
    return nuevoNodo;

  SList nodo = lista;
  for (;nodo->sig != NULL;nodo = nodo->sig);
  /* ahora 'nodo' apunta al ultimo elemento en la lista */

  nodo->sig = nuevoNodo;
  return lista;
}

SList slist_agregar_inicio(SList lista, int dato) {
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = lista;
  return nuevoNodo;
}

void slist_recorrer(SList lista, FuncionVisitante visit) {
  for (SNodo *nodo = lista; nodo != NULL; nodo = nodo->sig)
    visit(nodo->dato);
}

int slist_longitud(SList lista) {
  //if(lista == NULL) return 0;
  int i = 0;
  for (; lista != NULL; i++) {
    lista = lista->sig;
  }
  return i;
}

SList slist_concatenar(SList lista1, SList lista2) {
  //SList listaNueva = slist_crear();
  SList temp;
  if(lista1 == NULL) {
    temp = lista2;
  } else {
    temp = lista1;
    while (lista1->sig != NULL) {
      lista1 = lista1->sig;
    }
    lista1->sig = lista2;
  }

  return temp;
}

SList slist_insertar(SList lista, int dato) {
 int longitud = slist_longitud(lista);
 if (longitud == 0) return slist_agregar_inicio(lista, dato);
 int posicion = rand() % longitud;
 return slist_insertar_posicion(lista, posicion, dato);
}

SList slist_insertar_posicion(SList lista, int posicion, int dato) {

  if(posicion > slist_longitud(lista) || posicion < 0) {
    printf("Error. No es posible insertar un elemento la posición %d\n", posicion);
    return lista;
  }

  if (posicion == 0) return slist_agregar_inicio(lista, dato);
  
  SNodo *temp = lista;
  for (int i = 0; i < posicion - 1; i++) {
    temp = temp->sig;
  }
  //creo el nuevo nodo
  SNodo *nuevoNodo = malloc(sizeof(SNodo));
  nuevoNodo->dato = dato;
  nuevoNodo->sig = temp->sig;
  temp->sig = nuevoNodo;

  return lista;
}

SList slist_eliminar(SList lista) {
  int longitud = slist_longitud(lista);
  if (longitud == 0) {
    printf("Error. No se pueden eliminar nodos de una lista vacía.");
    return lista;
  }
  int posicion = rand() % longitud;
  return slist_eliminar_posicion(lista, posicion);
}

SList slist_eliminar_posicion(SList lista, int posicion) {
  int longitud = slist_longitud(lista);
  if (posicion > longitud || longitud < 0) {
    printf("Error: no se puede eliminar un dato de la posición %d\n", posicion);
    return lista;
  }

  if(posicion == 0) return lista->sig;

  SNodo *temp = lista;
  for(int i = 0; i < posicion - 1; i++) {
    temp = temp->sig;
  }
  temp->sig = (temp->sig)->sig;
  return lista;
}



// realizable en o(n), ver cómo carajos
SList slist_partir(SList lista) {
  int longLista = slist_longitud(lista);
  int longLista1 = (longLista / 2) + (longLista % 2);
  printf("\nlong de la lista: %d\n", longLista);
  printf("\nlong de la lista1: %d\n", longLista1);
  printf("\nlong de la lista2: %d\n", longLista - longLista1);

  SList lista2;
  for(int i = 0; i < longLista1; lista = lista->sig, i++);
  lista2 = lista->sig;
  lista->sig = NULL;

  return lista2;
}


