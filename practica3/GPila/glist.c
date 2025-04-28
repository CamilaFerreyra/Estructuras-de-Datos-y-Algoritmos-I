#include "glist.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() { return NULL; }
SGList sglist_crear() { return NULL; }

/**
 * Destruccion de la lista.
 * destroy es una función que libera el dato almacenado.
 */
void glist_destruir(GList list, FuncionDestructora destroy) {
  GNode *nodeToDelete;
  while (list != NULL) {
    nodeToDelete = list;
    list = list->next;
    printf(" destruyendo %d... ", *(int*)(nodeToDelete->data));
    destroy(nodeToDelete->data);
    printf(" free ");
    free(nodeToDelete);
  }
  if(glist_vacia(list)) printf(" La lista quedo vacía.   ");
}

void sglist_destruir(SGList lista, FuncionDestructora destruir) {
  GNode *nodoADestruir;
  while (lista != NULL) {
    nodoADestruir = lista;
    lista = lista->next;
    destruir(nodoADestruir->data);
    free(nodoADestruir);
  }
}

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList list) { return (list == NULL); }
int sglist_vacia(SGList lista) { return (lista == NULL); }

/**
 * Agrega un elemento al inicio de la lista.
 * copy es una función que retorna una copia física del dato.
 */
GList glist_agregar_inicio(GList list, void *data, FuncionCopia copy) {
  GNode *newNode = malloc(sizeof(GNode));
  assert(newNode != NULL);
  newNode->next = list;
  newNode->data = copy(data);
  return newNode;
}

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList list, FuncionVisitante visit) {
  for (GNode *node = list; node != NULL; node = node->next)
    visit(node->data);
}

void sglist_recorrer(SGList lista, FuncionVisitante visitar) {
  for (GNode *nodo = lista; nodo!= NULL; nodo = nodo->next)
    visitar(nodo);
}

GList glist_filtrar(GList lista, FuncionCopia c, Predicado p) {
  GList nuevaLista = glist_crear(); //devuelve null
  //for (temp = lista, temp != NULL, lista = lista->next)
  GList temp = lista;
  while (temp != NULL) {
    if(p(temp->data)) {
      nuevaLista = glist_agregar_inicio(nuevaLista, temp->data, c);
    }
  temp = temp->next;
  }
  return nuevaLista;
  }

GList glist_filtrar_R(GList filtrada, FuncionCopia c, Predicado p) {
  if(filtrada == NULL) return filtrada; //esto es null
  if(p(filtrada->data))
    return glist_agregar_inicio(glist_filtrar_R(filtrada->next, c, p), filtrada->data, c);
  else
    return glist_filtrar_R(filtrada->next, c, p);
}

GList glist_filtrar_R2(GList filtrada, FuncionCopia c, Predicado p) {
  if(filtrada == NULL) return filtrada; //esto es null
  if(p(filtrada->data))
    return glist_agregar_inicio(glist_filtrar_R2(filtrada->next, c, p), filtrada->data, c);
  else
    return glist_filtrar_R2(filtrada->next, c, p);
}

SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copiar, FuncionComparadora comparar) {
  if(sglist_vacia(lista)) {
    return glist_agregar_inicio(lista, dato, copiar);
  } else {
    if(comparar(lista->data, dato) > 0) {
      return glist_agregar_inicio(lista, dato, copiar);
    } else {
      //return sglist_insertar(lista->next, dato, copiar, comparar);
      return glist_agregar_inicio(sglist_insertar(lista->next, dato, copiar, comparar),
              lista->data, copiar);
    }
  }

  if(sglist_vacia(lista) || (comparar(lista->data, dato) >= 0)) {
    return glist_agregar_inicio(lista, dato, copiar);
  } else {
    //return sglist_insertar(lista->next, dato, copiar, comparar);
    return glist_agregar_inicio(sglist_insertar(lista->next, dato, copiar, comparar),
            lista->data, copiar);
  }

}

int sglist_buscar(GList lista, void* dato, FuncionComparadora comparar) {
  if(sglist_vacia(lista)) return 0;
  if(comparar(lista->data, dato) == 0) return 1;
  else {
    if(comparar(lista->data, dato) < 0) return sglist_buscar(lista->next, dato, comparar);
    else return 0;
  }
}

SGList sglist_arr(void **datos, int n, FuncionCopia copiar, FuncionComparadora comparar) {
  SGList lista = sglist_crear();
  for (int i = 0; i < n; i++) {
    lista = sglist_insertar(lista, datos[i], copiar, comparar);
  }
  return lista;
}



