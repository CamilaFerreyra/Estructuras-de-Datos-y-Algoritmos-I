#include "glist.h"
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void (*ToString)(void *dato, char *buf, size_t buf_size);

// Función para copiar un dato al nodo de una lista.
void *entero_copiar(void *data) { return data; }

// Función para destruir el dato de un nodo de la lista.
void entero_destruir(void *data) {
  // Ignora warning de variable no utilizada.
  (void)data;

  return;
}

// Función para convertir un dato a string.
void entero_string(void *dato, char *buf, size_t buf_size) {
  snprintf(buf, buf_size, "%d", *(int *)dato);
}

// Función auxiliar para glist_posiciones_multiplo.
GList glist_posiciones_multiplo_aux(GList gl, int i, int idx) {
  if (glist_vacia(gl)) {
    return glist_crear();
  }

  GList ret = glist_posiciones_multiplo_aux(gl->next, i, idx + 1);

  if (idx % i == 0) {
    ret = glist_agregar_inicio(ret, gl->data, entero_copiar);
  }
  return ret;
}

// Construye y retorna una nueva lista enlazada con los datos de los nodos de la
// lista enlazada dada que se encuentran en posiciones múltiplos del entero
// dado.
GList glist_posiciones_multiplo(GList gl, int i) {
  return glist_posiciones_multiplo_aux(gl, i, 0);
}

// Convierte la lista dada a una representación de la misma en la string dada.
// Devuelve la cantidad de bytes escritos.
void glist_string(GList gl, char *buf, size_t buf_size, ToString to_string) {
  size_t bytes_written = 0;
  size_t elem_buf_size = 50;
  char elem_buf[elem_buf_size];

  for (GNode *node = gl; node != NULL; node = node->next) {
    to_string(node->data, elem_buf, elem_buf_size);
    bytes_written += snprintf(buf + bytes_written, buf_size - bytes_written,
                              "%s -> ", elem_buf);
  }
}

// true si la representación en string de la cola dada es igual al string dado,
// false en caso contrario.
bool glist_streq(GList gl, const char *glist_str) {
  size_t buf_size = 500;
  char buf[buf_size];

  glist_string(gl, buf, buf_size, entero_string);

  return strcmp(buf, glist_str) == 0;
}

void test_glist_posiciones_multiplo() {
  GList original = glist_crear();
  size_t data_len = 17;
  int data[data_len];

  for (int i = data_len - 1; i >= 0; i--) {
    data[i] = i;
    original = glist_agregar_inicio(original, &data[i], entero_copiar);
  }

  assert(glist_streq(original,
                     "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 "
                     "-> 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> "));

  GList multiplos3 = glist_posiciones_multiplo(original, 3);
  assert(glist_streq(multiplos3, "0 -> 3 -> 6 -> 9 -> 12 -> 15 -> "));
  // También verificamos que la lista original no haya mutado:
  assert(glist_streq(original,
                     "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 "
                     "-> 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> "));

  GList multiplos2 = glist_posiciones_multiplo(original, 2);
  assert(glist_streq(multiplos2,
                     "0 -> 2 -> 4 -> 6 -> 8 -> 10 -> 12 -> 14 -> 16 -> "));
  // También verificamos que la lista original no haya mutado:
  assert(glist_streq(original,
                     "0 -> 1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10 "
                     "-> 11 -> 12 -> 13 -> 14 -> 15 -> 16 -> "));

  glist_destruir(original, entero_destruir);
  glist_destruir(multiplos3, entero_destruir);
  glist_destruir(multiplos2, entero_destruir);
}

int main(int argc, char *argv[]) {
  // Ignora warning de variable no utilizada.
  (void)argc;
  (void)argv;

  test_glist_posiciones_multiplo();

  printf("Tests satisfactorios!\n");

  return 0;
}
