#include <stdlib.h>
#include <stdio.h>
#include "slist.h"

void slist_partir(SList lista, SList *primera_mitad, SList *segunda_mitad) {
  SNodo *temp = lista;
  int len = slist_longitud(lista);
  
  int i = 0;
  for (; i < (len / 2) + 1; i++, temp = temp->sig)
    *primera_mitad = slist_agregar_final(*primera_mitad, temp->dato);

  for (; i < len; i++, temp = temp->sig)
    *segunda_mitad = slist_agregar_final(*segunda_mitad, temp->dato);
}

SNodo *slist_partir2(SNodo *lista) {
  SNodo *temp = lista;
  int len = slist_longitud(lista);
  
  for (int i = 0; i < (len - 1) / 2; i++, temp = temp->sig);

  SNodo *segunda_mitad = temp->sig;
  temp->sig = NULL;
  return segunda_mitad;  
}

void imprimir_enteros(int n) { printf("%i ", n); }

int main() {

    // Creamos la lista [1, 2, 3, 4, 5]
    SList ls = slist_crear();
    ls = slist_agregar_inicio(ls, 5);
    ls = slist_agregar_inicio(ls, 4);
    ls = slist_agregar_inicio(ls, 3);
    ls = slist_agregar_inicio(ls, 2);
    ls = slist_agregar_inicio(ls, 1);

    // Mostramos en pantalla
    printf("Lista original:\n");
    slist_recorrer(ls, imprimir_enteros);

    // Separamos creando dos listas nuevas
    SList primer_mitad  = slist_crear();
    SList segunda_mitad = slist_crear();

    slist_partir(ls, &primer_mitad, &segunda_mitad);

    // Mostramos las listas separadas
    printf("\n\nListas nuevas luego de partir:\n");
    slist_recorrer(primer_mitad, imprimir_enteros);
    printf("\n");
    slist_recorrer(segunda_mitad, imprimir_enteros);
    printf("\n");

    // Separamos en dos, pero ahora si modificamos la lista
    SList ls_segunda = slist_partir2(ls);

    // Mostramos ambas en pantalla
    printf("\nListas luego de partir, habiendo modificado la lista original:\n");
    slist_recorrer(ls, imprimir_enteros);
    printf("\n");
    slist_recorrer(ls_segunda, imprimir_enteros);
    printf("\n");

    // Liberamos la lista original, que quedo partida en ls y ls_segunda
    slist_destruir(ls);
    slist_destruir(ls_segunda);

    // Y las dos listas nuevas
    slist_destruir(primer_mitad);
    slist_destruir(segunda_mitad);

    return 0;
}