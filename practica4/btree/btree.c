#include "btree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

struct _BTNodo {
  int dato;
  struct _BTNodo *left;
  struct _BTNodo *right;
};

/**
 * Devuelve un árbol vacío.
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
                    FuncionVisitante visit) {
  
  if(arbol == NULL) return;
  switch (orden) {
  case BTREE_RECORRIDO_PRE:
    visit(arbol->dato); //visit raíz
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    break;
  case BTREE_RECORRIDO_IN:
    btree_recorrer(arbol->left, orden, visit);
    visit(arbol->dato); //visit raíz
    btree_recorrer(arbol->right, orden, visit);
  break;
  case BTREE_RECORRIDO_POST:
    btree_recorrer(arbol->left, orden, visit);
    btree_recorrer(arbol->right, orden, visit);
    visit(arbol->dato); //visit raíz
    break;
  }
  return;
}

void btree_recorrer2(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit) {
  
  if (arbol == NULL) return;

  if(orden == BTREE_RECORRIDO_PRE)
    visit(arbol->dato);
  btree_recorrer2(arbol->left, orden, visit);
  if(orden == BTREE_RECORRIDO_IN)
    visit(arbol->dato);
  btree_recorrer2(arbol->right,orden,visit);
  if(orden == BTREE_RECORRIDO_POST)
    visit(arbol->dato);
}


int btree_nnodos(BTree arbol) {
  //podría hacer un map?
  //hacer recursivamente
  if (arbol == NULL) return 0;
  return 1 + btree_nnodos(arbol->left) +
          btree_nnodos(arbol->right);
}

int btree_buscar(BTree arbol, int dato) {
  if(btree_empty(arbol)) return 0;
  if(arbol->dato == dato) return 1;
  if(btree_buscar(arbol->left, dato) + 
     btree_buscar(arbol->right, dato) > 0)
    return 1;
}

BTree btree_copiar(BTree arbol) { 
  if(arbol == NULL) return NULL;
  BTree nuevoNodo = malloc(sizeof(struct _BTNodo));
  assert(nuevoNodo != NULL);
  nuevoNodo->dato = arbol->dato;
  nuevoNodo->left = btree_copiar(arbol->left);
  nuevoNodo->right = btree_copiar(arbol->right);
  return nuevoNodo;
}

int btree_altura(BTree arbol) {
  //mayor camino de la raiz a una hoja.
  //si el árbol es vacío, la altura es 0.
  //si el árbol tiene un solo nodo, la altura es 0.
  if (btree_empty(arbol)) return -1;
  if (arbol->left == NULL && arbol->right == NULL) return 0; //hoja
  int alturaDer = btree_altura(arbol->right);
  int alturaIzq = btree_altura(arbol->left);
  return (alturaDer > alturaIzq ? alturaDer : alturaIzq) + 1;
}

int btree_nnodos_profundidad(BTree arbol, int profundidad) {
//la profundidad es del nodo a la raiz.
  if(btree_empty(arbol)) return 0;
  if(profundidad == 0) return 1;
  return btree_nnodos_profundidad(arbol->left, profundidad-1) +
         btree_nnodos_profundidad(arbol->right, profundidad-1);
}

int btree_profundidad(BTree arbol, int dato) {
  if(btree_empty(arbol)) return -1;
  if(arbol->dato == dato) return 0;
  int profundidadIzq = btree_profundidad(arbol->left, dato);
  if(profundidadIzq >= 0) return profundidadIzq + 1;
  int profundidadDer = btree_profundidad(arbol->right, dato);
  if(profundidadDer >= 0) return profundidadDer + 1;
  return -1; //dato no encontrado
}

int btree_sumar (BTree arbol) {
  if(btree_empty(arbol)) return 0;
  return arbol->dato + btree_sumar(arbol->left) + btree_sumar(arbol->right);
}

void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
                        FuncionVisitanteExtra visit_extra, void *extra) {
  if(btree_empty(arbol)) return;
  if(orden == BTREE_RECORRIDO_PRE)
    visit_extra(arbol->dato, extra);
  btree_recorrer_extra(arbol->left, orden, visit_extra, extra);
  if(orden == BTREE_RECORRIDO_IN)
    visit_extra(arbol->dato, extra);
  btree_recorrer_extra(arbol->right, orden, visit_extra, extra);
  if(orden == BTREE_RECORRIDO_POST)
    visit_extra(arbol->dato, extra);
}
