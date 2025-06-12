#include "btree.h"
#include <assert.h>
#include <stdlib.h>
#include "pila.h"

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear() { return NULL; }

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo) {
  if (nodo != NULL) {
    btree_destruir(nodo->left);
    btree_destruir(nodo->right);
    free(nodo);
  }
}

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo) { return nodo == NULL; }

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right) {
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = dato;
  nuevoNodo->left = left;
  nuevoNodo->right = right;
  return nuevoNodo;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;

  switch (orden) {
    case BTREE_RECORRIDO_PRE:
      visit(arbol->dato);
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
      break;
    case BTREE_RECORRIDO_IN:
      btree_recorrer(arbol->left, orden, visit);
      visit(arbol->dato);
      btree_recorrer(arbol->right, orden, visit);
      break;
    case BTREE_RECORRIDO_POST:
      btree_recorrer(arbol->left, orden, visit);
      btree_recorrer(arbol->right, orden, visit);
      visit(arbol->dato);
      break;
    default:
      assert(0);
  };
  return;
}

/**
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer_alternativo(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitanteInt visit) {
  if (arbol == NULL)
    return;
  
  if (orden == BTREE_RECORRIDO_PRE)
    visit(arbol->dato);

  btree_recorrer(arbol->left, orden, visit);

  if (orden == BTREE_RECORRIDO_IN)
    visit(arbol->dato);

  btree_recorrer(arbol->right, orden, visit);

  if (orden == BTREE_RECORRIDO_POST)
    visit(arbol->dato);
}

void* no_copia (void* dato){
  return dato;
}

void no_destruir (void* dato){
  return;
}

void btree_recorrer_pre_it(BTree arbol, FuncionVisitanteInt visit) {
  if (btree_empty(arbol))
    return;

  Pila pila_de_nodos = pila_crear();

  pila_de_nodos = pila_apilar(pila_de_nodos, arbol, no_copia);

  while(!pila_vacia(pila_de_nodos)) {

    BTree nodo_actual = pila_tope(pila_de_nodos, no_copia);
    visit(nodo_actual->dato);

    pila_de_nodos = pila_desapilar(pila_de_nodos, no_destruir);

    if (!btree_empty(nodo_actual->right))
      pila_de_nodos = pila_apilar(pila_de_nodos, nodo_actual->right, no_copia);

    if (!btree_empty(nodo_actual->left))
      pila_de_nodos = pila_apilar(pila_de_nodos, nodo_actual->left, no_copia);
  }

  pila_destruir(pila_de_nodos, no_destruir);  
}