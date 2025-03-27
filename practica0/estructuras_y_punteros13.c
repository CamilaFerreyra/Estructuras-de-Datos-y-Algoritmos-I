#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int palo;                     // 0, 1, 2, 3
  int numero;
} Carta;

typedef struct {
  Carta mazo[47];
} Mazo;

void llenar(Mazo);
Carta azar(Mazo);

void llenar(Mazo mazo) {
  for (int i = 0; i < 4; i++) {
    for (int j = 1; j <= 12; j++) {
      
    }
  }
}
