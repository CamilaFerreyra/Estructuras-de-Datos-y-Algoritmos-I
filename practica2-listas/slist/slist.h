#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

//sinónimos de tipos
typedef void (*FuncionVisitante) (int dato);

typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo* SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

/**
 * Determina si la lista es vacía.
 */
int slist_vacia(SList lista);

/**
 * Agrega un elemento al final de la lista.
 */
SList slist_agregar_final(SList lista, int dato);

/**
 * Agrega un elemento al inicio de la lista.
 */
SList slist_agregar_inicio(SList lista, int dato);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void slist_recorrer(SList lista, FuncionVisitante visit);

/**
 * (a) Retorna la longitud de una lista
 */
int slist_longitud(SList lista);

/**
 * (b) Retorna una lista, concatenación de las listas que recibe
 */
SList slist_concatenar(SList lista1, SList lista2);

/**
 * (c) Inserta un dato en una lista en una posición arbitraria.
 */
SList slist_insertar(SList lista, int dato);

/**
 * (c.1) Inserta un dato en una lista en una posición arbitraria.
 */
SList slist_insertar_posicion(SList lista, int posicion, int dato);

/**
 * (l) Recibe una lista y la divide a la mitad.
 * Retorna un puntero al primer elemento de la segunda mitad.
 * Si la lista tiene (2n+1) elementos, la primer lista tendrá (n+1) elementos.
 */

 SList slist_partir(SList lista);
#endif /* __SLIST_H__ */
