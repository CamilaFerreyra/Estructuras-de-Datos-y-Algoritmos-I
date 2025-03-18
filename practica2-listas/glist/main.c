#include <stdlib.h> 
#include <string.h>
#include <stdio.h>
#include "glist.h"

typedef struct {
    char* nombre;
    char* telefono;
    int edad;
} Contacto;

int mayorA60 (void* data) {
    Contacto* contacto = (Contacto*) data;
    return contacto->edad > 60;
}

void* copiaContacto (void* data) {
    Contacto* contacto = (Contacto*) data;
    Contacto* nuevo = malloc(sizeof(Contacto));

    nuevo->nombre = malloc(sizeof(char)*(strlen(contacto->nombre)+1));
    strcpy(nuevo->nombre, contacto->nombre);
    nuevo->telefono = malloc(sizeof(char)*(strlen(contacto->telefono)+1));
    strcpy(nuevo->telefono, contacto->telefono);
    nuevo->edad = contacto->edad;

    return nuevo;
}

void imprimirContacto (void* data) {
    Contacto* contacto = (Contacto*) data;
    printf("Nombre: %s - Telefono: %s - Edad: %d\n", contacto->nombre, contacto->telefono, contacto->edad);
}

void destruirContacto (void* data) {
    Contacto* contacto = (Contacto*) data;

    free(contacto->nombre);
    free(contacto->telefono);
    free(contacto);
}

int main () {
    GList lista = glist_crear();
    
    Contacto* contacto = malloc(sizeof(Contacto));
    contacto->nombre = malloc(sizeof(char)*100);
    contacto->telefono = malloc(sizeof(char)*100);

    strcpy(contacto->nombre, "Martín");
    strcpy(contacto->telefono, "34356535");
    contacto->edad = 57;
    lista = glist_agregar_inicio(lista, contacto, copiaContacto);

    strcpy(contacto->nombre, "Marta");
    strcpy(contacto->telefono, "34254535");
    contacto->edad = 61;
    lista = glist_agregar_inicio(lista, contacto, copiaContacto);

    strcpy(contacto->nombre, "Fede");
    strcpy(contacto->telefono, "34298735");
    contacto->edad = 45;
    lista = glist_agregar_inicio(lista, contacto, copiaContacto);

    strcpy(contacto->nombre, "Griselda");
    strcpy(contacto->telefono, "34254334");
    contacto->edad = 60;
    lista = glist_agregar_inicio(lista, contacto, copiaContacto);

    strcpy(contacto->nombre, "Alberto");
    strcpy(contacto->telefono, "34254676");
    contacto->edad = 73;
    lista = glist_agregar_inicio(lista, contacto, copiaContacto);

    destruirContacto(contacto);

    printf("Lista Original:\n");
    glist_recorrer(lista, imprimirContacto);


    printf("\nLista Filtrada:\n");
    GList filtrada = glist_filtrar(lista, mayorA60, copiaContacto);
    // GList filtrada = glist_filtrarR(lista, mayorA60, copiaContacto);
    glist_recorrer(filtrada, imprimirContacto);


    glist_destruir(filtrada, destruirContacto);
    glist_destruir(lista, destruirContacto);

    return 0;
}