#ifndef __PILA_H__
#define __PILA_H__

#include <stddef.h>
#include "arregloenteros.h"

struct _Pila {
  ArregloEnteros *arr;
  int ultimo;
};

typedef struct _Pila* Pila;

Pila pila_crear (int size);

void pila_destruir (Pila pila);

int pila_es_vacia (Pila pila);

int pila_tope (Pila pila);

void pila_apilar (Pila pila, int num);

void pila_desapilar (Pila pila);

void pila_imprimir (Pila pila);



#endif