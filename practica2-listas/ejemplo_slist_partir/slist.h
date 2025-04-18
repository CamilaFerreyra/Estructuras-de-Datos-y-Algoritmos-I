#ifndef __SLIST_H__
#define __SLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante) (int dato);

typedef int (*FuncionComparadora) (int a, int b);


typedef struct _SNodo {
  int dato;
  struct _SNodo *sig;
} SNodo;

typedef SNodo *SList;

/**
 * Devuelve una lista vacía.
 */
SList slist_crear();

/**
 * Destruccion de la lista.
 */
void slist_destruir(SList lista);

SList slist_merge(SList a, SList b, FuncionComparadora cmp);

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
 * Copia en el segundo y tercer argumento las mitades de la
 * lista pasada como primer argumento
 */
void slist_partir(SList fuente, SList *l1, SList *l2);

/**
 * Retorna un puntero a la segunda mitad de la lista
 * y trunca la lista argumento a la mitad
 */
SNodo *slist_partir2(SNodo *lista);

#endif /* __SLIST_H__ */
