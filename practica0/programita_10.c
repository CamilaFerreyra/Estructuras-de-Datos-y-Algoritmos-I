#include <stdio.h>
#include <stdlib.h>

char *copiar_cadena(char *cad, int longitud) {
  char *a = malloc(sizeof(char) * longitud);
  a = cad;

  return a;
}

/*char *copiar_cadena_cami(char *cad, int longitud) {
  char *doble = malloc(sizeof(char) * longitud);
  while(*cad != '\0') {
    *doble++ = *cad++;
  }
}*/

int main() {
  char a[10] = "hola";
  char *b = copiar_cadena(a, 10);
  printf("%s %s\n", a, b);
  *b = 's';
  printf("%s %s\n", a, b);
  return 0;
}

/*DUDA: evidentemente b está apuntando a a, si cambio 
"el contenido de lo que está siendo apuntado por b" (*b == b[0])
cambio a

*/
