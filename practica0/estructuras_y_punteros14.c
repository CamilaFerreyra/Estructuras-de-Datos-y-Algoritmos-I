#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//representación de agenda de contactos

#define MAX_NOMBRE 100
#define MAX_TEL 20
#define MAX_CONTACTOS 2


typedef struct {
  char nombre[MAX_NOMBRE];
  char tel[MAX_TEL];
  unsigned edad;
} Contacto;

typedef struct {
  Contacto contactos[MAX_CONTACTOS];
  int cantidad;
} Agenda;

Contacto crear_contacto();
char *get_new_line(void);
void actualizar_edad(Contacto *);
void alta_contacto(Agenda *);
void modificar_edad(Agenda *);
void imprimir_contactos(Agenda *);
double prom(Agenda *);

int main() {
  Contacto c = crear_contacto();
  printf("Nuevo contacto creado.\n %s, %u, %s", c.nombre, c.edad, c.tel);
  actualizar_edad(&c);
  printf("\nEdad actualizada: %s, %u\n", c.nombre, c.edad);

  return 0;
}

Contacto crear_contacto() {
  printf("Nuevo Contacto.\n");
  Contacto nuevoContacto;
  printf("Ingrese nombre: ");
  char *nombre = get_new_line();
  if (nombre) {
    strncpy(nuevoContacto.nombre, nombre, MAX_NOMBRE - 1);
    free(nombre);
  }
  printf("Ingrese el teléfono: ");
  char *tel = get_new_line();
  if (tel) {
    strncpy(nuevoContacto.tel, tel, MAX_TEL - 1);
    free(tel);
  }
  printf("Ingrese la edad: ");
  scanf("%u", &nuevoContacto.edad);

  return nuevoContacto;
}

void actualizar_edad(Contacto * contacto) {
  printf("\nIngrese nueva edad: ");
  scanf("%u", &contacto->edad);
}

void alta_contacto(Agenda * a) {
  if (a->cantidad >= MAX_CONTACTOS) {
    printf("ERROR. Agenda llena. No se puede agregar más contactos");
    return;
  }
  Contacto nuevoC = crear_contacto();
  a->contactos[a->cantidad] = nuevoC;
  a->cantidad++;
  printf("\nContacto agregado exitosamente.");

}

void modificar_edad(Agenda * a) {
  if (a->cantidad == 0)
    printf("ERROR. Agenda vacía.");
  char *nombreBuscado = get_new_line();
  if (!nombreBuscado)
    return;

  int encontrado = 0;
  for (int i = 0; i < a->cantidad; i++) {
    if (strcmp(a->contactos[i].nombre, nombreBuscado) == 0) {
      actualizar_edad(&a->contactos[i]);
      encontrado = 1;
      break;
    }
  }
  free(nombreBuscado);

  if (!encontrado) {
    printf("Contacto no encontrado.\n");
  }

}

void imprimir_contactos(Agenda * a) {
  if (a->cantidad == 0) {
    printf("ERROR. Agenda vacía\n");
    return;
  }
  printf("Datos agenda:\n");
  for (int i = 0; i < a->cantidad; i++) {
    printf("Contacto %d: %s, %u, %s",
           i, a->contactos[i].nombre, a->contactos[i].edad,
           a->contactos[i].tel);
  }
}

double prom(Agenda * a) {
  if (a->cantidad == 0) {
    printf("ERROR. Agenda vacía\n");
    return 0;
  }
  
  double acumulador = 0;
  for (int i = 0; i < a->cantidad; i++) {
    acumulador += a->contactos[i].edad;
  }
  return acumulador / a->cantidad;
}

char *get_new_line(void) {
  char c;
  int size = 20;
  int len = 0;
  char *line = malloc(size * sizeof(char));

  if (line == NULL) {
    return NULL;
  }

  while ((c = getchar()) != EOF && c != '\n') {
    line[len++] = c;
    if (len == size) {
      size *= 2;
      char *temp = realloc(line, size * sizeof(char));
      if (temp == NULL) {
        free(line);
        return NULL;
      }
      line = temp;
    }
  }

  if (c == EOF && len == 0) {
    free(line);
    return NULL;
  }

  line[len] = '\0';
  return line;
}
