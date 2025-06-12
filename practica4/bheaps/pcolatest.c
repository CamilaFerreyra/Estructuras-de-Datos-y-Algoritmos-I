#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "PriorityQueue.h"

// Función para imprimir un elemento de la cola
void imprimir_dato(void* dato) {
    char* str = (char*)dato;
    printf("%s", str);
}

// Función de prueba básica
void test_basico() {
    printf("=== Test Básico ===\n");
    PCola cola = cola_prioridad_crear();
    
    printf("La cola está vacía? %s\n", cola_prioridad_es_vacia(cola) ? "Sí" : "No");

   // void *max = cola_prioridad_maximo(cola);
    
    // Insertar elementos
    srand(time(NULL));
    //char* datos[] = {"estrella", "corazon", "diamante", "flor"};
    /*int datos[] = {1,2,3,4};


    for(int i = 0; i < 4; i++) {
      printf("Insertando: %i con prioridad: ", datos[i]);
      int prioridad = rand() % 10;
      printf("%d\n", prioridad);
      cola_prioridad_insertar(cola, &datos[i], prioridad);
    }*/
    cola_prioridad_insertar(cola, "estrella", 10);
    cola_prioridad_insertar(cola, "corazon", 2);
    cola_prioridad_insertar(cola, "diamante", 5);
    cola_prioridad_insertar(cola, "flor", 13);

    printf("La cola está vacía? %s\n", cola_prioridad_es_vacia(cola) ? "Sí" : "No");
    
    // Obtener y eliminar máximos
    // printf("Maximo actual: %s\n", (char*)cola_prioridad_maximo(cola));
    cola_prioridad_eliminar_maximo(cola);
    
    // printf("Maximo actual: %s\n", (char*)cola_prioridad_maximo(cola));
    cola_prioridad_eliminar_maximo(cola);
    
    // printf("Maximo actual: %s\n", (char*)cola_prioridad_maximo(cola));
    cola_prioridad_eliminar_maximo(cola);
    
    // printf("Maximo actual: %s\n", (char*)cola_prioridad_maximo(cola));
    cola_prioridad_eliminar_maximo(cola);
    
    printf("La cola está vacía? %s\n", cola_prioridad_es_vacia(cola) ? "Sí" : "No");
    
    // Liberar memoria
    free(cola->arr);
    free(cola);
}

// Test para verificar el redimensionamiento
void test_redimensionamiento() {
    printf("\n=== Test Redimensionamiento ===\n");
    PCola cola = cola_prioridad_crear();
    
    // Insertar más elementos que la capacidad inicial
    for (int i = 0; i < 15; i++) {
        char* str = malloc(10);
        sprintf(str, "Elemento %d", i);
        cola_prioridad_insertar(cola, str, i);
    }
    
    printf("Capacidad actual: %d\n", cola->capacidad);
    printf("Elementos en cola: %d\n", cola->ultimo + 1);
    
    // Vaciar la cola
    while (!cola_prioridad_es_vacia(cola)) {
        cola_prioridad_eliminar_maximo(cola);
    }
    
}

int main() {
    test_basico();
    test_redimensionamiento();
    return 0;
}