#ifndef __GLIST_H__
#define __GLIST_H__

typedef void (*FuncionDestructora)(void *dato);
typedef void *(*FuncionCopia)(void *dato);
typedef void (*FuncionVisitante)(void *dato);
typedef int (*Predicado) (void *dato);
typedef int (*FuncionComparadora)(void *, void *);

typedef struct _GNode {
  void *data;
  struct _GNode *next;
} GNode;

typedef GNode* GList;

typedef GList SGList;

/**
 * Devuelve una lista vacía.
 */
GList glist_crear();
SGList sglist_crear();

/**
 * Destruccion de la lista.
 */
void glist_destruir(GList lista, FuncionDestructora destruir);
void sglist_destruir(SGList lista, FuncionDestructora destruir);

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista);

/**
 * Agrega un elemento al inicio de la lista.
 */
GList glist_agregar_inicio(GList lista, void *dato, FuncionCopia copiar);

/**
 * Recorrido de la lista, utilizando la funcion pasada.
 */
void glist_recorrer(GList lista, FuncionVisitante visitar);
void sglist_recorrer(SGList lista, FuncionVisitante visitar);
/**
 * (7.a) Dada una lista gral, retorna una nueva lista con los elementos que cumplen con el predicado 
 */
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p);
GList glist_filtrar_R(GList lista, FuncionCopia c, Predicado p);
GList glist_filtrar_R2(GList lista, FuncionCopia c, Predicado p);

/**
 * (8.e) inserta un nuevo dato en una lista ordenada
 */
SGList sglist_insertar(SGList lista, void *dato, FuncionCopia copiar, FuncionComparadora comparar);

/**
 * (8.f) busca un dato en la lista. retorna 1 si lo encuenta, 0 sino.
 */
int sglist_buscar(GList lista, void* dato, FuncionComparadora comparar);

/**
 * (8.g) construye una lista ordenada a partir de un arreglo de elementos y su long
 */
SGList sglist_arr(void **datos, int n, FuncionCopia copiar, FuncionComparadora comparar);

#endif /* __GLIST_H__ */
