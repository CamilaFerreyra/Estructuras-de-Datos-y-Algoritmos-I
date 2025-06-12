#include "bstree.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>

/**
 * Estructura del nodo del arbol de busqueda binaria.
 * Tiene un puntero al dato (dato),
 * un puntero al nodo raiz del subarbol izquierdo (izq),
 * y un puntero al nodo raiz del subarbol derecho (der).
 */
struct _BST_Nodo {
  void *dato;
  struct _BST_Nodo *izq, *der;
};

/**
 * bstee_crear: Retorna un arbol de busqueda binaria vacio
 */
BSTree bstree_crear() { return NULL; }

/**
 * bstree_destruir: Destruye el arbol y sus datos
 */
void bstree_destruir(BSTree raiz, FuncionDestructora destr) {
  if (raiz != NULL) {
    bstree_destruir(raiz->izq, destr);
    bstree_destruir(raiz->der, destr);
    destr(raiz->dato);
    free(raiz);
  }
};

/**
 * bstree_buscar: Retorna 1 si el dato se encuentra y 0 en caso
 * contrario
 */
int bstree_buscar(BSTree raiz, void *dato, FuncionComparadora comp) {
  if (raiz == NULL)
    return 0;
  else if (comp(dato, raiz->dato) == 0) // raiz->dato == dato
    return 1;
  else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    return bstree_buscar(raiz->izq, dato, comp);
  else // raiz->dato < dato
    return bstree_buscar(raiz->der, dato, comp);
}

/**
 * bstree_insertar: Inserta un dato no repetido en el arbol, manteniendo la
 * propiedad del arbol de busqueda binaria
 */
BSTree bstree_insertar(BSTree raiz, void *dato, FuncionCopiadora copia,
                       FuncionComparadora comp) {
  if (raiz == NULL) { // insertar el dato en un nuevo nodo
    struct _BST_Nodo *nuevoNodo = malloc(sizeof(struct _BST_Nodo));
    assert(nuevoNodo != NULL);
    nuevoNodo->dato = copia(dato);
    nuevoNodo->izq = nuevoNodo->der = NULL;
    return nuevoNodo;
  } else if (comp(dato, raiz->dato) < 0) // dato < raiz->dato
    raiz->izq = bstree_insertar(raiz->izq, dato, copia, comp);
  else if (comp(dato, raiz->dato) > 0) // raiz->dato < dato
    raiz->der = bstree_insertar(raiz->der, dato, copia, comp);
  // si el dato ya se encontraba, no es insertado
  return raiz;
}

/**
 * bstree_recorrer: Recorrido DSF del arbol
 */
void bstree_recorrer(BSTree raiz, BSTreeRecorrido orden,
                     FuncionVisitanteExtra visita, void *extra) {
  if (raiz != NULL) {
    if (orden == BTREE_RECORRIDO_PRE)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->izq, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_IN)
      visita(raiz->dato, extra);
    bstree_recorrer(raiz->der, orden, visita, extra);
    if (orden == BTREE_RECORRIDO_POST)
      visita(raiz->dato, extra);
  }
}

BSTree bstree_menor(BSTree arbol) {
  //busco el menor de los mayores
  if(arbol == NULL) {
    return NULL; //la idea seria que no lleue con null a esta funcion
  } else if(arbol->izq == NULL) {
    return arbol;
  } else {
    return bstree_menor(arbol->izq);
  }
}

BSTree bstree_eliminar(BSTree raiz, void *dato,
      FuncionComparadora comp, FuncionDestructora dest) {
  
  //busqueda del dato
  if(raiz == NULL) {
    //busqueda infructuosa
    printf("no se encuentra el dato en el arbol");
    return NULL;
  }

  if(comp(dato, raiz->dato) == 0) {
    if(raiz->izq == NULL) {
      //lo reemplazo por hijo derecho
      BSTree temp = raiz->der; 
      dest(raiz->dato);
      free(raiz);
      return temp;
    }else if(raiz->der == NULL) {
      BSTree temp = raiz->izq; 
      dest(raiz->dato);
      free(raiz);
      return temp;
    } else {
      printf("tiene dos hijes \n");
      //tiene ambos hijos, reemplazo por menor de los mayores (sucesor)
      BSTree hijoDer = raiz->der; //r
      BSTree sucesor = bstree_menor(hijoDer);
      printf("suc->d: %s | hijDer->d: %s\n", (char*) sucesor->dato, (char*) hijoDer->dato);
      if(comp(sucesor->dato, hijoDer->dato) != 0) {
        //sucesor NO contiguo - hijo derecho NO directo
        //hijo der contiene padre de sucesor
        BSTree padreSucesor = hijoDer; //padre de y
        while(comp(padreSucesor->izq->dato, sucesor->dato) != 0) {
          padreSucesor = padreSucesor->izq;
        }
        printf("encontre al padre sucesor: %s\n", (char*)padreSucesor->dato);
        padreSucesor->izq = sucesor->der; //padre sucesor (arbol der) ya no tiene al sucesor
        sucesor->der = hijoDer; //sucesor->der = r
      }
      //sucesor adyacente
      sucesor->izq = raiz->izq; // sucesor->izq era NULL
      dest(raiz->dato);
      free(raiz);
      return sucesor;
      
      }
    } else if(comp(dato, raiz->dato) > 0) {
      raiz->der = bstree_eliminar(raiz->der, dato, comp, dest);
    } else {
      raiz->izq = bstree_eliminar(raiz->izq, dato, comp, dest);
    }
    return raiz; //devuelvo el arbolito con nueva der xor nueva izq
  
  
}

int bstree_k_esimo_menor(BSTree arbol, int k) {
  //recorrido in-order, k veces
  //k no debe superar la cant de nodos del arbol
  //no debe llegar a null
}
