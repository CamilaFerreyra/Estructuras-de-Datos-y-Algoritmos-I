#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include "BinaryHeap.h"
#include <stdlib.h>

typedef int (*FuncionComparadora) (void* dato1, void* dato2);
typedef void* (*FuncionCopiadora) (void* dato);
typedef void (*FuncionDestructora) (void* dato);
typedef void (*FuncionVisitante) (void* dato);

typedef struct _Elem{
    void* dato;
    int key;
} Elem;

typedef struct _PCola{
  void **arr;
  int capacidad;
  int ultimo;
 }* PCola;


PCola cola_prioridad_crear();

int cola_prioridad_es_vacia(PCola pCola);

void* cola_prioridad_maximo(PCola pCola);

void cola_prioridad_eliminar_maximo(PCola pCola);

void cola_prioridad_insertar(PCola pCola, void* dato, int key);
#endif