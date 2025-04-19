#include <stdio.h>
#include <stdlib.h>
#include "slist.h"
#include <time.h>


static void imprimir_entero(int dato) {
  printf("%d ", dato);
}

int intcmp (int a, int b) {
  if (a == b) return 0;
  if (a < b) return -1;
  else return 1;
}

int main(int argc, char *argv[]) {

  srand(time(NULL));

  SList lista = slist_crear();

  lista = slist_agregar_inicio(lista, 3);
  lista = slist_agregar_inicio(lista, 2);
  lista = slist_agregar_inicio(lista, 1);
  lista = slist_agregar_final(lista, 4);

  slist_recorrer(lista, imprimir_entero);
  puts("");

  //slist_destruir(lista);
  printf("largo de la lista: %d\n", slist_longitud(lista));

  SList lista2 = slist_crear();
  lista2 = slist_agregar_final(lista2, 0);

  printf("\nlistas antes: \n");
  slist_recorrer(lista, imprimir_entero);
  printf("\n");

  slist_recorrer(lista2, imprimir_entero);

  printf("\nlistas despues: \n");
  SList lista3;
  lista3 = slist_concatenar(lista, lista2);
  slist_recorrer(lista, imprimir_entero);
  slist_recorrer(lista3, imprimir_entero);

  printf("\nParto listas:\n");
  SList lista4;
  lista4 = slist_partir(lista);
  printf("\nprimera parte:\n");
  slist_recorrer(lista, imprimir_entero);
  printf("\nsegunda parte:\n");
  slist_recorrer(lista4, imprimir_entero);

  printf("\nInserto datos\n");
  slist_recorrer(lista, imprimir_entero);
  printf("\n");
  lista = slist_insertar_posicion(lista, 0, 13);
  // DUDA slist_insertar(lista, 14);
  // por qué esa línea de arriba no da error?
  // esta en la posición cero si funciona mal, pues pierde la cabecera:
  // slist_insertar_posicion(lista, 0, 13);
  
  
  /* esto funciona ok
  lista = slist_insertar(lista, 14);
  slist_recorrer(lista, imprimir_entero);

  printf("\nElimino nodo random en lista\n");
  lista = slist_eliminar(lista);
  slist_recorrer(lista, imprimir_entero);

  printf("\nContiene?\n");
  printf("¿El elemento %d está en lista?: %d",13, slist_contiene(lista, 13));
*/
  printf("\nlista:");
  slist_recorrer(lista, imprimir_entero);
  printf("\nlista4:");
  slist_recorrer(lista4, imprimir_entero);
  SList listaInterseccion = slist_intersecar_custom(lista, lista3, (FuncionComparadora)intcmp);
  printf("\nlista interseccion entre lista y lista4:");
  slist_recorrer(listaInterseccion, imprimir_entero);

  SList listaIntercalada = slist_intercalar(lista4, lista);
  printf("\nlista intercalación de lista4 y lista:");
  slist_recorrer(listaIntercalada, imprimir_entero);

  printf("\nLista intercalada ordenada:\n");
  SList intercadalaOrdenada = slist_ordenar(listaIntercalada, (FuncionComparadora)intcmp);
  slist_recorrer(intercadalaOrdenada, imprimir_entero);





  return 0;
}
