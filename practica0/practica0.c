#include <stdio.h>

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
    printf("Dirección de arregloCaracteres[%d]: %p\n", i, &*p);
    printf("Caracter en posición %d: %c\n", i, *p);
  }

  //imprimo direcciones de memoria de elementos del arreglo - sin p
  for (int i = 0; i < 4; i++) {
    printf("Dirección de arregloCaracteres[%d]: %p\n", i,
           (void *) &arregloCaracteres[i]);
    printf("Caracter en posición %d: %c\n", i, arregloCaracteres[i]);
  }
  return 0;
}
