#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _SNodo {
 int dato;
 struct _SNodo *sig;
} SNodo;

/*
retorno un nuevo inicio cada vez que
me llaman
*/
SNodo* slist_agregar_inicio1 (SNodo* lista, int dato) {
 SNodo* nuevoNodo = malloc(sizeof(SNodo));
 nuevoNodo->dato = dato;
 nuevoNodo->sig = lista; //el inicio pasa a ser un nodo
 return nuevoNodo; //nuevo inicio
}

/*
guardo la direccion del nuevo nodo creado.
con *lista accedo al valor y lugar origical de la
variable que me pasan
*/
void slist_agregar_inicio (SNodo** lista, int dato) {
 SNodo* nuevoNodo = malloc(sizeof(SNodo));
 nuevoNodo->dato = dato;
 nuevoNodo->sig = *lista;
 *lista = nuevoNodo;
}

//intento funcion mostrar el contenido de una lista
void slist_mostrar (SNodo* lista) {
 while(lista != NULL) {
  printf("dato: %i \n", lista->dato);
  lista = lista->sig;
 }
}

void slist_agregar_final (SNodo** inicio, int dato) {
 SNodo* nuevoNodo = malloc(sizeof(SNodo));
 nuevoNodo->dato = dato;
 nuevoNodo->sig = NULL;
 
 if (inicio == NULL) *inicio = nuevoNodo;
  //lista estaba vacia, el nuevo nodo es el primero
 else {
  //lista no esta vacia.
  SNodo* temp = *inicio;
  //voy al final de la lista
  for (; temp->sig != NULL; temp = temp->sig);
  //agrego el nuevo nodo
  temp->sig = nuevoNodo;
 }
}

SNodo slist_agregar_finalR (SNodo* lista, int dato) {
 if (lista == NULL) {
    /*
    SNodo* nuevoNodo = malloc(sizeof(SNodo));
    nuevoNodo->dato = dato;
    nuevoNodo->sig = NULL;
    return nuevoNodo;
    */
    lista = malloc(sizeof(SNodo));
    lista->dato = dato;
    lista->sig = NULL;
    //return lista;
 } else {
    lista->sig = slist_agregar_finalR(lista->sig, dato);
    //return lista;
 }
 return lista;
}

int main () {

//definir una lista es un puntero SNodo que apunte a la lista
//defino el comienzo de mi lista
 SNodo* lista1 = NULL;

 //ejemplo se uso de funcion:
 //SNodo* slist_agregar_inicio (SNodo* lista, int dato)
 lista1 = slist_agregar_inicio1(lista1, 5);
 lista1 = slist_agregar_inicio1(lista1, 9);

 //ejemplo de uso de funcion:
 //void slist_agregar_inicio(SNodo** lista, int dato)
 SNodo* lista = NULL;
 slist_agregar_inicio(&lista, 10);
 slist_agregar_inicio(&lista, 8);
 slist_agregar_inicio(&lista, 6);
 slist_agregar_inicio(&lista, 4);
 slist_agregar_inicio(&lista, 2); 
 slist_mostrar(lista);

 printf ("agrego datos al final de la lista \n");
 slist_agregar_final(&lista, 1);
 slist_agregar_final(&lista, 0);
 slist_mostrar(lista);
 return 0;
}