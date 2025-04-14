#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

DList dlist_crear() {
  DList lista = { NULL, NULL };
  return lista;
}

//implementar crear_nodo();
DNodo* dlist_crear_nodo(int dato) {
 DNodo* nodo = malloc(sizeof(DNodo));
 nodo->dato = dato;
 return nodo;
}

void dlist_destruir(DList lista) {
  DNodo *nodo = lista.primero;
  while (nodo != NULL) {
    DNodo *temp = nodo;
    nodo = nodo->sig;
    free(temp);
  }
}

int dlist_vacia(DList lista) {
  return lista.primero == NULL;
}

DList dlist_agregar_final(DList lista, int dato) {
  DNodo *nuevo = dlist_crear_nodo(dato);
  nuevo->sig = NULL;
  nuevo->ant = lista.ultimo;

  if (lista.ultimo == NULL) {
    //lista vacía
    //lista.ultimo = nuevo;
    lista.primero = nuevo;
  } else {
    (lista.ultimo)->sig = nuevo;
    //lista.ultimo = nuevo;
  }
  lista.ultimo = nuevo;

  return lista;
}

DList dlist_agregar_inicio(DList lista, int dato) {
  DNodo *nuevo = dlist_crear_nodo(dato);
  nuevo->ant = NULL;
  nuevo->sig = lista.primero;

  if (lista.primero == NULL) {
    //lista vacía
    //lista.primero = nuevo;
    lista.ultimo = nuevo;
  } else {
    (lista.primero)->ant = nuevo;
    //lista.primero = nuevo;
  }
  lista.primero = nuevo;

  return lista;
}

void dlist_recorrer(DList lista, FuncionVisitante visit,
                    DListOrdenRecorrido ord) {
  if (lista.primero == NULL)
    return;                     //lista vacía

  if (ord == DLIST_RECORRIDO_HACIA_ATRAS) {
    // Recorrido desde el último hasta el primero
    // <---<---<
    DNodo *nodo = lista.ultimo;
    while (nodo != NULL) {
      visit(nodo->dato);
      nodo = nodo->ant;
    }
  } else {
    //desde el primero hasta el último
    // >--->--->
    DNodo *nodo = lista.primero;
    while (nodo != NULL) {
      visit(nodo->dato);
      nodo = nodo->sig;
    }
  }
}

/** comentario: cuando mi estructura no es definida de manera recursiva,
* quizas me conviene buscar una estructura recursiva dentro. 
* En este caso el nodo si está definido recursivamente.
* Busco función auxiliar que recorra los nodos.
*/
void dlist_recorrer_rec(DList lista, FuncionVisitante visit,
  DListOrdenRecorrido ord) { 
  if (ord == DLIST_RECORRIDO_HACIA_ATRAS) {
    // Recorrido desde el último hasta el primero
    // <-----<------<
    DNodo *nodo = lista.ultimo;
    if (nodo != NULL) {
      //visit(nodo->dato);
      //DList temp = {lista.primero,nodo->ant};
      //dlist_recorrer_rec(temp, visit, ord);
      dlist_recorrer_rec_aux(nodo, visit, ord);
    }
  } else {
    // Recorrido desde el primero hasta el último
    // >--->--->
    DNodo *nodo = lista.primero;
    if (nodo != NULL) {
      //visit(nodo->dato);
      //DList temp = {nodo->sig,lista.ultimo};
      //dlist_recorrer_rec(temp, visit, ord);
      dlist_recorrer_rec_aux(nodo, visit, ord);

    }
  }
  }

void dlist_recorrer_rec_aux(DNodo* nodo,
  FuncionVisitante visit, DListOrdenRecorrido ord) {
  visit(nodo->dato);
  if(nodo->ant != NULL && ord == DLIST_RECORRIDO_HACIA_ATRAS) {
    dlist_recorrer_rec_aux(nodo->ant, visit, ord);
  }
  if(nodo->sig != NULL && ord == DLIST_RECORRIDO_HACIA_DELANTE) {
    dlist_recorrer_rec_aux(nodo->sig, visit, ord);
  }
    
}
