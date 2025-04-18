#ifndef __DLIST_H__
#define __DLIST_H__

#include <stddef.h>

typedef void (*FuncionVisitante)(int dato);

typedef struct _DNodo {
  int dato;
  struct _DNodo *sig;
  struct _DNodo *ant;
} DNodo;

typedef struct {
  DNodo *primero;
  DNodo *ultimo;
} DList;

typedef enum {
  DLIST_RECORRIDO_HACIA_DELANTE,
  DLIST_RECORRIDO_HACIA_ATRAS
} DListOrdenRecorrido;

// Crea una lista vacía.
DList dlist_crear();

// Crea un puntero a nodo con el dato recibido
DNodo* dlist_crear_nodo(int dato);

// Destruye una lista.
void dlist_destruir(DList lista);

// Determina si la lista es vacía.
int dlist_vacia(DList lista);

// Agrega un elemento al final de la lista.
DList dlist_agregar_final(DList lista, int dato);

// Agrega un elemento al inicio de la lista.
DList dlist_agregar_inicio(DList lista, int dato);


/**
 * Recorrido de la lista, utilizando la funcion pasada.
 * se debe especificar el orden del recorrido
 */
void dlist_recorrer(DList lista, FuncionVisitante visit,
                    DListOrdenRecorrido ord);

void dlist_recorrer_rec(DList lista, FuncionVisitante visit,
                    DListOrdenRecorrido ord);

void dlist_recorrer_rec_aux(DNodo* nodo, FuncionVisitante visit,
  DListOrdenRecorrido ord);

#endif                          /* __DLIST_H__ */
