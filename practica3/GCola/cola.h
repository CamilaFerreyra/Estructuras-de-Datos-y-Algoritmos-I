#ifndef __COLA_H__
#define __COLA_H__

#include <stddef.h>
#include "dlist.h"

typedef DList Cola;

Cola cola_crear();
void cola_destruir(Cola cola);
int cola_es_vacia(Cola cola);
int cola_inicio(Cola cola);
Cola cola_encolar (Cola cola, int dato);
Cola cola_desencolar (Cola cola);
void cola_imprimir (Cola cola);

#endif
