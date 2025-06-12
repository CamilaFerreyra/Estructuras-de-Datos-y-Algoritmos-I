#ifndef __BTREE_H__
#define __BTREE_H__

typedef void (*FuncionVisitante)(int dato);
typedef void (*FuncionVisitanteExtra) (int dato, void *extra);

typedef enum {
  BTREE_RECORRIDO_IN,
  BTREE_RECORRIDO_PRE,
  BTREE_RECORRIDO_POST
} BTreeOrdenDeRecorrido;

typedef struct _BTNodo* BTree;

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
 * Recorrido del arbol, utilizando la funcion pasada.
 */
void btree_recorrer(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit);
void btree_recorrer2(BTree arbol, BTreeOrdenDeRecorrido orden,
                    FuncionVisitante visit);

/**
 * 3.a
 */
int btree_nnodos(BTree arbol);

/**
 * 3.b
 */
int btree_buscar(BTree arbol, int dato);

/**
 * 3.c
 */
BTree btree_copiar(BTree arbol);

/**
 * 3.d
 */
int btree_altura(BTree arbol);

/**
 * 3.e
 */
int btree_nnodos_profundidad(BTree arbol, int profundidad);
//la profundidad es del nodo a la raiz.

/**
 * 3.f
 */
int btree_profundidad(BTree arbol, int dato);

/**
 * 3.g 
 */
int btree_sumar (BTree arbol);

/**
 * 4.a
 */
void btree_recorrer_extra(BTree arbol, BTreeOrdenDeRecorrido orden,
                        FuncionVisitanteExtra visit, void *extra);
/**
 * 10. Retorna el k-esimo menor elemento del árbol ordenadito
 */
int bstree_k_esimo_menor(BTree arbol, int k);

#endif /* __BTREE_H__ */
