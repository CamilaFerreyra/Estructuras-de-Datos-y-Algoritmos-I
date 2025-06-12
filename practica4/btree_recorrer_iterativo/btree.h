#ifndef __BTREE_H__
#define __BTREE_H__


typedef void (*FuncionVisitanteInt)(int dato);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;


typedef struct _BTNodo *BTree;

/**
 * Devuelve un arbol vacío.
 */
BTree btree_crear();

/**
 * Destruccion del árbol.
 */
void btree_destruir(BTree nodo);

/**
 * Indica si el árbol es vacío.
 */
int btree_empty(BTree nodo);

/**
 * Crea un nuevo arbol, con el dato dado en el nodo raiz, y los subarboles dados
 * a izquierda y derecha.
 */
BTree btree_unir(int dato, BTree left, BTree right);

/**
 * Dado un orden y un arbol lo recorre utilizando una función visitante.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteInt visit);

/**
 * Dado un orden y un arbol lo recorre utilizando una función visitante.
 */
void btree_recorrer_alternativo(BTree arbol, BTreeOrdenDeRecorrido orden, FuncionVisitanteInt visit);

/**
 * Recorrido del arbol preorder iterativo, utilizando la funcion pasada.
 */
void btree_recorrer_pre_it(BTree arbol, FuncionVisitanteInt visit);

#endif /* __BTREE_H__ */
