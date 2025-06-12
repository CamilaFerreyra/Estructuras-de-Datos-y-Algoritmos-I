#ifndef __PILA_H__
#define __PILA_H__

#include <stddef.h>
#include "glist.h"

typedef GList Pila;

void destruir (void *data);
void imprimir (int *data);
int* copiar(int *data);

Pila pila_crear ();

void pila_destruir (Pila pila);

int pila_es_vacia (Pila pila);

int* pila_tope (Pila pila);

/**
 * push
 */
Pila pila_apilar (Pila pila, int *dato);

/**
 * pop
 */
Pila pila_desapilar (Pila pila);

/**
 * muestro la pila comenzando por el primer elemento insertado,
 * finalizando por el tope
 */
void pila_imprimir (Pila pila);

/**
 * Genera una pila invertida.
 */
Pila pila_invertir(Pila pila);

/**
 * 3. Escriba una función que utilice una pila para revertir 
 * el orden de una lista simplemente enlazada.
 */
GList lista_invertir(SGList lista);

#endif