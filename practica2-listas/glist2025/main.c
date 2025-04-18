#include "contacto.h"
#include "glist.h"
#include <stdio.h>
#include <stdlib.h>

int mayor60 (void *contacto) {
  //definir como void* y castear a Contacto*
  return (((Contacto*)contacto)->edad) > 60;
}

int main() {

  GList lista = glist_crear();
  SGList listaOrdenada = sglist_crear();
  Contacto *contactos[6], *contactoNuevo;
  contactos[0] = contacto_crear("Pepe Argento", "3412695452", 61);
  contactos[1] = contacto_crear("Moni Argento", "3412684759", 60);
  contactos[2] = contacto_crear("Coqui Argento", "3415694286", 32);
  contactos[3] = contacto_crear("Paola Argento", "3416259862", 29);
  contactos[4] = contacto_crear("Maria Elena Fuseneco", "3416874594", 59);
  contactos[5] = contacto_crear("Dardo Fuseneco", "3416894526", 64);
 
  contactoNuevo = contacto_crear("Girasol", "3412232323", 13);
  
// castear explícitamente a void.
// dos opciones: castear la función en la llamada
//               definir la función con argumento void* y castear a tipo *Contacto en la definición
  for (int i = 0; i < 6; ++i) {
    lista =
        glist_agregar_inicio(lista, contactos[i], (FuncionCopia)contacto_copia);
    /*contacto_destruir(contactos[i]);
    listaOrdenada =
        sglist_insertar(listaOrdenada, contactos[i], (FuncionCopia)contacto_copia, (FuncionComparadora)contacto_comparar);
    //contacto_destruir(contactos[i]);
    */
  }

  printf("Lista:\n");
  glist_recorrer(lista, (FuncionVisitante)contacto_imprimir);

  //glist_destruir(lista, (FuncionDestructora)contacto_destruir);

  GList mayores60;
  printf("\nmayores de 60\n");
  mayores60 = glist_filtrar_R(lista, (FuncionCopia)contacto_copia, (Predicado)mayor60);
  glist_recorrer(mayores60, (FuncionVisitante)contacto_imprimir);

  //asigno elementos a lista ordenada
  listaOrdenada = sglist_arr((void**)contactos, 6, (FuncionCopia)contacto_copia, (FuncionComparadora)contacto_comparar);
  //muestro lista ordenada:
  printf("\nLista ordenada:\n");
  glist_recorrer(listaOrdenada, (FuncionVisitante)contacto_imprimir);

  //busco contacto:
  printf("\n¿Se encuentra el contacto? %i\n", sglist_buscar(listaOrdenada,contactos[0], (FuncionComparadora)contacto_comparar));
  contacto_imprimir(contactos[0]);
  printf("\n¿Se encuentra el contacto? %i\n", sglist_buscar(listaOrdenada,contactoNuevo, (FuncionComparadora)contacto_comparar));
  contacto_imprimir(contactoNuevo);

  return 0;
}