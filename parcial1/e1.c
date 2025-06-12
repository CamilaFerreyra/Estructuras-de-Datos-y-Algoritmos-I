#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 5

#define POSICION_A_AGREGAR_INIT 0
#define POSICION_A_ELIMINAR_INIT -1

typedef struct _Cola {
  int datos[N];
  int posicionAAgregar, posicionAEliminar;
} Cola;

// Muta a la cola a su estado inicial.
void cola_inicializar(Cola *p) {
  p->posicionAAgregar = POSICION_A_AGREGAR_INIT;
  p->posicionAEliminar = POSICION_A_ELIMINAR_INIT;
}

// Crea una cola.
Cola *cola_crear() {
  Cola *new = malloc(sizeof(Cola));
  assert(new != NULL);
  cola_inicializar(new);
  return new;
}

// Libera la cola.
void cola_destruir(Cola *p) { free(p); }

// true si la cola está vacía, false en caso contrario.
bool cola_esta_vacia(Cola *p) {
  return p->posicionAEliminar == POSICION_A_ELIMINAR_INIT;
}

// true si la cola está llena, false en caso contrario.
bool cola_esta_llena(Cola *p) {
  return p->posicionAAgregar == p->posicionAEliminar;
}

// Computa el próximo índice de la cola en orden de inserción.
int proxima_posicion(int posicion) { return (posicion + 1) % N; }

// Agrega el valor a la cola si hay lugar. Si no hay lugar, no lo agrega.
void cola_enqueue(Cola *p, int datoAAgregar) {
  if (cola_esta_llena(p)) {
    return;
  }

  p->datos[p->posicionAAgregar] = datoAAgregar;
  if (cola_esta_vacia(p)) {
    p->posicionAEliminar = 0;
  }
  p->posicionAAgregar = proxima_posicion(p->posicionAAgregar);
}

// Remueve el proximo elemento de la cola si no es vacía. Si es vacía, se
// imprime un mensaje en stdout y el comportamiento es indefinido.
int cola_dequeue(Cola *p) {
  if (p->posicionAEliminar == -1) {
    printf("ERROR: vacia\n");
  }
  int ret = p->datos[p->posicionAEliminar];

  p->posicionAEliminar = proxima_posicion(p->posicionAEliminar);
  if (p->posicionAAgregar == p->posicionAEliminar) {
    cola_inicializar(p);
  }

  return ret;
}

// Convierte la cola dada a una representación de la misma en la string dada.
void cola_string(Cola *p, char *buf, size_t buf_size) {
  size_t bytes_written = 0;

  if (cola_esta_vacia(p)) {
    bytes_written += snprintf(buf, buf_size, "< <");
    return;
  }

  bytes_written = snprintf(buf + bytes_written, buf_size - bytes_written, "< ");
  int current_index = p->posicionAEliminar % N;
  int finish_on = p->posicionAAgregar % N;
  do {
    bytes_written += snprintf(buf + bytes_written, buf_size - bytes_written,
                              "%d ", p->datos[current_index]);
    current_index = proxima_posicion(current_index);
  } while (current_index != finish_on);

  bytes_written += snprintf(buf + bytes_written, buf_size - bytes_written, "<");
}

// Imprime en stdout la representación en string de la cola dada.
void cola_imprimir(Cola *cola) {
  size_t buf_size = 500;
  char buf[buf_size];

  cola_string(cola, buf, buf_size);

  printf("%s\n", buf);
}

// true si la representación en string de la cola dada es igual al string dado,
// false en caso contrario.
bool cola_streq(Cola *cola, const char *cola_str) {
  size_t buf_size = 500;
  char buf[buf_size];

  cola_string(cola, buf, buf_size);

  return strcmp(buf, cola_str) == 0;
}

// Imprime en stdout una representación de la cola considerando el struct
// subyacente. Útil para depurar.
void cola_debug_print(Cola *p) {
  // índices
  for (int i = 0; i < N; i++) {
    printf("%d\t", i);
  }

  printf("\n=== add: %d ==== del: %d ==========================\n",
         p->posicionAAgregar, p->posicionAEliminar);

  // valores
  for (int i = 0; i < N; i++) {
    printf("%d\t", p->datos[i]);
  }

  printf("\n\n");
}

// Tests para la operación enqueue de la cola.
void test_cola_enqueue() {
  Cola *p = cola_crear();

  assert(cola_streq(p, "< <"));

  cola_enqueue(p, 1);
  assert(cola_streq(p, "< 1 <"));

  cola_enqueue(p, 5651);
  assert(cola_streq(p, "< 1 5651 <"));

  cola_enqueue(p, 420);
  assert(cola_streq(p, "< 1 5651 420 <"));

  cola_enqueue(p, 69);
  assert(cola_streq(p, "< 1 5651 420 69 <"));

  cola_enqueue(p, 133742069);
  assert(cola_streq(p, "< 1 5651 420 69 133742069 <"));

  cola_enqueue(p, 551551511); // sin efecto
  assert(cola_streq(p, "< 1 5651 420 69 133742069 <"));

  cola_enqueue(p, -1010101); // sin efecto
  assert(cola_streq(p, "< 1 5651 420 69 133742069 <"));

  cola_destruir(p);
}

// Tests para la operación dequeue de la cola.
void test_cola_dequeue() {
  Cola *p = cola_crear();
  int result;

  cola_enqueue(p, 1);
  cola_enqueue(p, 5651);
  cola_enqueue(p, 420);
  cola_enqueue(p, 69);
  cola_enqueue(p, 133742069);
  assert(cola_streq(p, "< 1 5651 420 69 133742069 <"));

  result = cola_dequeue(p);
  assert(result == 1);
  assert(cola_streq(p, "< 5651 420 69 133742069 <"));

  result = cola_dequeue(p);
  assert(result == 5651);
  assert(cola_streq(p, "< 420 69 133742069 <"));

  result = cola_dequeue(p);
  assert(result == 420);
  assert(cola_streq(p, "< 69 133742069 <"));

  result = cola_dequeue(p);
  assert(result == 69);
  assert(cola_streq(p, "< 133742069 <"));

  result = cola_dequeue(p);
  assert(result == 133742069);
  assert(cola_streq(p, "< <"));

  cola_destruir(p);
}

// Tests para las operaciones enqueue y dequeue de la cola funcionando en
// conjunto.
void test_cola_enqueue_and_dequeue() {
  Cola *p = cola_crear();
  int result;

  cola_enqueue(p, 998);
  cola_enqueue(p, 66115);
  cola_enqueue(p, -92);
  assert(cola_streq(p, "< 998 66115 -92 <"));

  result = cola_dequeue(p);
  assert(result == 998);
  assert(cola_streq(p, "< 66115 -92 <"));

  cola_enqueue(p, 12);
  cola_enqueue(p, 42069);
  cola_enqueue(p, 24414);
  cola_enqueue(p, -7754);    // sin efecto
  cola_enqueue(p, -86567);   // sin efecto
  cola_enqueue(p, 345);      // sin efecto
  cola_enqueue(p, -142);     // sin efecto
  cola_enqueue(p, 4541);     // sin efecto
  cola_enqueue(p, -2222222); // sin efecto
  cola_enqueue(p, 1);        // sin efecto
  assert(cola_streq(p, "< 66115 -92 12 42069 24414 <"));

  result = cola_dequeue(p);
  assert(result == 66115);
  assert(cola_streq(p, "< -92 12 42069 24414 <"));

  cola_enqueue(p, 24414);
  cola_enqueue(p, 767);  // sin efecto
  cola_enqueue(p, -591); // sin efecto
  cola_enqueue(p, 8581); // sin efecto
  cola_enqueue(p, 1);    // sin efecto
  cola_enqueue(p, 6912); // sin efecto
  assert(cola_streq(p, "< -92 12 42069 24414 24414 <"));

  result = cola_dequeue(p);
  assert(result == -92);
  assert(cola_streq(p, "< 12 42069 24414 24414 <"));

  result = cola_dequeue(p);
  assert(result == 12);
  assert(cola_streq(p, "< 42069 24414 24414 <"));

  cola_enqueue(p, 0);
  assert(cola_streq(p, "< 42069 24414 24414 0 <"));

  result = cola_dequeue(p);
  assert(result == 42069);
  assert(cola_streq(p, "< 24414 24414 0 <"));

  result = cola_dequeue(p);
  assert(result == 24414);
  assert(cola_streq(p, "< 24414 0 <"));

  result = cola_dequeue(p);
  assert(result == 24414);
  assert(cola_streq(p, "< 0 <"));

  result = cola_dequeue(p);
  assert(result == 0);
  assert(cola_streq(p, "< <"));

  cola_destruir(p);
}

int main(int argc, char *argv[]) {
  // Ignora warning de variable no utilizada.
  (void)argc;
  (void)argv;

  test_cola_enqueue();
  test_cola_dequeue();
  test_cola_enqueue_and_dequeue();

  printf("Tests satisfactorios!\n");

  return 0;
}