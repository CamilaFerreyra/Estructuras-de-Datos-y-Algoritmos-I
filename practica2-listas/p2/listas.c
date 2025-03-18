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

SNodo* slist_agregar_finalR (SNodo* lista, int dato) {
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

/*
 Muestro el contenido de la lista
*/
void slist_mostrar (SNodo* lista) {
 while(lista != NULL) {
  printf("dato: %i \n", lista->dato);
  lista = lista->sig;
 }
}

/*
 Devuelve la longitud de una lista.
*/
int slist_longitud (SNodo* lista) {
 int longitud = 0;
 while (lista != NULL) {
  longitud ++;
  lista = lista->sig;
 }
 return longitud;
}

/*
 Concatena dos listas, modificando la primera lista pasada.
*/
void slist_concatenar0 (SNodo** lista1, SNodo* lista2) {
 //recorrer la lista2, agregandola a la primera
 while(lista2 != NULL) {
  *lista1 = slist_agregar_finalR(*lista1, lista2->dato);
  lista2 = lista2->sig;
 }
}

/*
 Concatena dos listas, modificando la primera lista pasada.
 es mas eficiente - aprovecha propiedad de las listas
*/
void slist_concatenar1 (SNodo** lista1, SNodo** lista2) {
 if(*lista1 == NULL) {
  *lista1 = *lista2;
 } else {
  //recorro lista1 hasta el final
 //que el ultimo elemento de la primera lista apunte al primero de la segunda
 SNodo* auxiliar = malloc(sizeof(SNodo)); 
 auxiliar = *lista1;
 while(auxiliar->sig != NULL) {
  auxiliar = auxiliar->sig;
 }
 auxiliar->sig = *lista2;
 //*lista1 = auxiliar;
 }
}

/*
 ver por que no se inserta el dato ver si es necesaria lista anterior
 Inserta un dato en una lista en una posición arbitraria.
 
 void slist_insertar (SNodo** lista, int dato) {
  int longitud, random, i = 1;
  SNodo *auxiliar_anterior, *auxiliar_posterior;
  auxiliar_anterior = malloc(sizeof(SNodo));
  auxiliar_anterior = *lista;
  longitud = slist_longitud (auxiliar_anterior);
  random = longitud; //tomar un numero entre 0 y longitud.
  while (i < random) {
   auxiliar_anterior = auxiliar_anterior->sig;
   i++;
  }
  //parto la lista en dos
  //elemento anterior al insertado y elemento posterior
  auxiliar_posterior = malloc(sizeof(SNodo));
  auxiliar_posterior = auxiliar_anterior->sig;
  printf("auxiliar posterior: \n");
  slist_mostrar(auxiliar_posterior);

  printf("auxiliar anterior: \n");
  slist_mostrar(auxiliar_anterior);
  auxiliar_anterior = NULL; //apunto a null para dividirlos
  // si no apunto a null, el elemento se agregaría al final de la lista
  // no se agregaria al lugar arbitrario.
  
  printf("lista truncada: \n");
  slist_mostrar(*lista);

  //auxiliar_anterior = slist_agregar_finalR(auxiliar_anterior, dato);
  slist_agregar_inicio(&auxiliar_posterior, dato);
  printf("auxiliar posterior con dato nuevo: \n");
  slist_mostrar(auxiliar_posterior);

  slist_concatenar1 (&auxiliar_anterior, &auxiliar_posterior);
  printf("lista con dato insertado: \n");
  *lista = auxiliar_anterior;
  slist_mostrar(*lista); 
 }
*/

void slist_insertar (SNodo** lista, int dato) {
 int longitud, posicion, i = 0;
 longitud = slist_longitud (*lista);
 SNodo *lista_posterior, *auxiliar;
 auxiliar = malloc(sizeof(SNodo));
 auxiliar = *lista;
 //numero entre 0 y longitud:
 posicion = 3;
 
 //divido en tres casos
 if (posicion == 0) {
  slist_agregar_inicio (lista, dato);
 } else {
   if (posicion == longitud) {
    *lista = slist_agregar_finalR (*lista, dato);
   } else {
      printf("caso agregar en el medio. \n");
      //recorro la lista hasta cortarla
      while (i < posicion - 1) {
       auxiliar = auxiliar->sig;
       i++;
      }
 
      //armo la lista posterior a la insercion
      lista_posterior = malloc(sizeof(SNodo));
      if(auxiliar->sig != NULL) lista_posterior = auxiliar->sig;
      else lista_posterior = NULL;
 
      auxiliar->sig = NULL;
 
      /*printf("esta es la lista truncada: \n");
      slist_mostrar (*lista);
      printf("esta es la lista posterior: \n");
      slist_mostrar (lista_posterior);
      */
      *lista = slist_agregar_finalR (*lista, dato);
      slist_concatenar1 (lista, &lista_posterior);
 
   }
 }
 
 printf("Se agregó un elemento en la posisción %i", posicion);
 //printf("lista con el nuevo elememento: \n");
 //slist_mostrar(*lista);
}

void slist_eliminar (SNodo** lista) {
 int longitud, posicion;
 SNodo *lista_aux, *lista_posterior;
 lista_aux = malloc(sizeof(SNodo));
 lista_aux = *lista;
 longitud = slist_longitud (*lista);
 posicion = 7;
 if(posicion == 0) {
  //elimino el primer elemento
  *lista = lista_aux->sig;
 } else {
   if (posicion == longitud) {
    for (int i = 0; i < longitud - 1; i++) {
      lista_aux = lista_aux->sig;
    }
    printf("dato que intento eliminar: %i\n\n", lista_aux->dato);
    lista_aux = NULL;
    slist_mostrar(*lista);
   } else {
      //divido en dos listas, elimino el ultimo de la primera y luego concateno.
      for (int i = 0; i < posicion - 1; i++) {
       lista_aux = lista_aux->sig;
      }
   
      lista_posterior = malloc(sizeof(SNodo));
      if (lista_aux->sig != NULL) lista_posterior = lista_aux->sig->sig;
      else lista_posterior = NULL;
   
      lista_aux->sig = NULL;

      printf("esta es la lista truncada: \n");
      slist_mostrar (*lista);
      printf("esta es la lista posterior: \n");
      slist_mostrar (lista_posterior);

      slist_concatenar1(lista, &lista_posterior);
   }
 }
 printf("Se eliminó el elemento de la posición %i\n", posicion);
 slist_mostrar(*lista);

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

/*
 //cuento elementos de la lista
 int longitud;
 longitud = slist_longitud(lista1);
 printf("\n La longitud de la lista es: %i\n", longitud);
 longitud = slist_longitud(lista);
 printf("\n La longitud de la lista1 es: %i\n", longitud);
*/

/*
//concateno lista1 al final de lista
 slist_concatenar1(&lista, &lista1);
 printf("resultado de meterle lista1 al final a la lista: \n");
 slist_mostrar(lista);
*/

 /*
 //inserto dato en una posicion arbitraria
 slist_insertar(&lista, 500);
 */

 slist_eliminar(&lista);
 return 0;
}