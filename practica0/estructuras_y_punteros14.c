#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//representación de agenda de contactos

#define MAX_NOMBRE 100
#define MAX_TEL 20

typedef struct {
  char nombre[MAX_NOMBRE];
  char tel[MAX_TEL];
  unsigned edad;
} Contacto;

Contacto crear_contacto();
char *get_new_line(void);
void actualizar_edad(Contacto *);

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
