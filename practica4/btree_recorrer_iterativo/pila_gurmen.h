#ifndef __COLA_H__
#define __COLA_H__

#include "stdlib.h"
#include "stdio.h"

typedef void (*FuncionVisitante)(void*);
typedef void* (*FuncionCopia)(void*);
typedef void (*FuncionDestructora)(void*);

typedef struct _Pila *Pila;

Pila pila_crear();

void pila_destruir(Pila pila, FuncionDestructora d);

int pila_vacia(Pila pila);

void *pila_tope(Pila pila, FuncionCopia f);

Pila pila_apilar(Pila pila, void *dato, FuncionCopia f);

Pila pila_desapilar(Pila pila, FuncionDestructora);

void pila_imprimir(Pila pila, FuncionVisitante f);

#endif
