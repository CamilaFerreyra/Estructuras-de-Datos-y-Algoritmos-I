#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int palo;                     // 0, 1, 2, 3
  int numero;
} Carta;

typedef struct {
  Carta cartas[47];
} Mazo;

void llenar(Mazo);
void mostrar(Mazo);
Carta azar(Mazo);

int main() {
  Mazo mazo;
  llenar(mazo);
  mostrar(mazo);
  return 0;
}

void llenar(Mazo mazo) {
  for (int i = 0, c = 0; i < 4; i++) {
    for (int j = 1; j <= 12; j++, c++) {

      mazo.cartas[c].palo = i;
      mazo.cartas[c].numero = j;
    }
  }
}

void mostrar(Mazo mazo) {
  for (int i = 0, c = 0; i < 4; i++) {
    for (int j = 0; j <= 12; j++, c++) {
      switch (mazo.cartas[c].palo) {
      case 0:
        printf("BASTO - ");
        break;

      case 1:
        printf("CORAZÓN - ");
        break;

      case 2:
        printf("TRÉBOL - ");
        break;

      case 3:
        printf("PICA - ");
        break;
      default:
        break;
      }
      printf("%d\n", mazo.cartas[c].numero);
    }

  }
}

Carta azar(Mazo mazo) {
  //Carta cartaSeleccionada;
  int indice = rand() % 48;     //numero aleatorio entre 0 y 47
  return mazo.cartas[indice];
}
