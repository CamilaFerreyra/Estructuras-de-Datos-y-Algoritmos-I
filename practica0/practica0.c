#include <stdio.h>
#include <stdlib.h>

void set_first(int[]);
void set_in(int *);
void swap(int *, int *);
char *get_new_line(void);
int par_impar(int);
int apply(int (*)(int), int);

int main() {
  //declaro variables locales
  int entero = 13;
  float flotante = 0.13;
  char caracter = 'C';
  char arregloCaracteres[5] = { 'H', 'o', 'l', 'a', '\0' };

  //imprimo direcciones de memoria de variables
  printf("Dirección de 'entero': %p\n", (void *) &entero);
  printf("Dirección de 'flotante': %p\n", (void *) &flotante);
  printf("Dirección de 'caracter': %p\n", (void *) &caracter);

  char *p;
  p = &arregloCaracteres[0];
  //imprimo direcciones de memoria de elementos del arreglo - con p
  for (int i = 0; *p != '\0'; p++, i++) {
    printf("Dirección de arregloCaracteres[%d]: %p   ;   ", i, &*p);
    printf("Caracter en posición %d: %c\n", i, *p);
  }

  //imprimo direcciones de memoria de elementos del arreglo - sin p
  for (int i = 0; i < 4; i++) {
    printf("Dirección de arregloCaracteres[%d]: %p  ;  ", i,
           (void *) &arregloCaracteres[i]);
    printf("Caracter en posición %d: %c\n", i, arregloCaracteres[i]);
  }

  int arreglito[3];
  /*arreglito[0] = 1;
     arreglito[2] = 2;
     arreglito[3] = 3;
   */

  for (int i = 0; i < 3; i++) {
    arreglito[i] = i + 3;
  }

  set_first(arreglito);

  for (int i = 0; i < 3; i++) {
    printf("Caracter en posición %d: %d\n", i, arreglito[i]);

  }

  int *punteroInt;
  punteroInt = &arreglito[1];
  //set_in(punteroInt);

  int *p1 = &arreglito[1], *p2 = &arreglito[2];

  //swap(arreglito[1], arreglito[2]);
  swap(p1, p2);



  for (int i = 0; i < 3; i++) {
    printf("Caracter en posición %d: %d\n", i, arreglito[i]);

  }

  /*
     printf("Ingrese una línea: ");
     char *line = get_new_line();
     if (line != NULL) {
     printf("Línea ingresada: %s\n", line);
     free(line);
     } */

  /*
     // Reservamos 100 bytes de memoria
     char *memoria = malloc(100);

     if (memoria == NULL) {
     printf("Error: No se pudo asignar memoria\n");
     return 1;
     }

     printf("Memoria de 100 bytes asignada en %p\n", (void *) memoria);

     // Primera liberación (correcta)
     free(memoria);
     printf("Memoria liberada por primera vez\n");

     Segunda liberación (incorrecta)
     free(memoria);
     printf("Memoria liberada por segunda vez\n");
   */

  int numero = 13;
  printf("numerito: %d", numero);
  //void *punteroFuncion;
  //punteroFuncion = &par_impar;
  numero = apply(par_impar, numero);
  printf(" - funcion(numerito): %d\n", numero);


  return 0;
}

void set_first(int arreglito[]) {

  arreglito[0] = 0;

}

void set_in(int *p) {
  if (*p == 0)
    *p = 1;
  else
    *p = 0;
}

void swap(int *p1, int *p2) {
  int temp;
  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
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

int par_impar(int n) {
  if (n % 2 == 0)
    return 0;
  else
    return 1;
}
int apply(int (*funcion)(int), int value) {
  //verifico si el puntero no es nulo
  if(funcion == NULL) {
    fprintf(stderr, "Error: puntero a función nulo \n");
    return -1;                  //valor de error 
  }
  return funcion(value);
}
