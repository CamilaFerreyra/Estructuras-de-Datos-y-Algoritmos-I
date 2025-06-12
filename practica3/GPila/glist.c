#include "glist.h"
#include <stdlib.h>
#include <assert.h>

/**
 * Devuelve una lista vacía.
 */
GList glist_crear() {
    GList lista = {NULL, NULL};
    return lista;
}

/**
 * Destruye la lista y todos sus elementos.
 */
void glist_destruir(GList lista, FuncionDestructora destruir) {
    GNode *nodo = lista.inicio;
    while (nodo != NULL) {
        GNode *temp = nodo;
        nodo = nodo->next;
        if (destruir) {
            destruir(temp->data);
        }
        free(temp);
    }
}

/**
 * Determina si la lista es vacía.
 */
int glist_vacia(GList lista) {
    return lista.inicio == NULL;
}

/**
 * Agrega un elemento al inicio de la lista.
 */
void glist_agregar_inicio(GList* lista, void *dato, FuncionCopia copiar) {
    GNode *nuevo = malloc(sizeof(GNode));
    assert(nuevo != NULL);
    
    nuevo->data = copiar ? copiar(dato) : dato;
    nuevo->next = lista->inicio;
    
    lista->inicio = nuevo;
    
    // Si la lista estaba vacía, el final también es el nuevo nodo
    if (lista->final == NULL) {
        lista->final = nuevo;
    }
}

/**
 * Agrega un elemento al final de la lista.
 */
void glist_agregar_final(GList* lista, void *dato, FuncionCopia copiar) {
    GNode *nuevo = malloc(sizeof(GNode));
    assert(nuevo != NULL);
    
    nuevo->data = copiar ? copiar(dato) : dato;
    nuevo->next = NULL;
    
    if (lista->final == NULL) {
        // Lista vacía
        lista->inicio = nuevo;
        lista->final = nuevo;
    } else {
        lista->final->next = nuevo;
        lista->final = nuevo;
    }
}

/**
 * Recorre la lista aplicando la función visitar.
 */
void glist_recorrer(GList lista, FuncionVisitante visitar) {
    for (GNode *nodo = lista.inicio; nodo != NULL; nodo = nodo->next) {
        visitar(nodo->data);
    }
}

/**
 * Filtra elementos de la lista según el predicado.
 */
GList glist_filtrar(GList lista, FuncionCopia c, Predicado p) {
    GList nueva = glist_crear();
    
    for (GNode *nodo = lista.inicio; nodo != NULL; nodo = nodo->next) {
        if (p(nodo->data)) {
            glist_agregar_final(&nueva, nodo->data, c);
        }
    }
    
    return nueva;
}