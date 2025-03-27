#include <stdio.h>

typedef struct {
  double x;
  double y;
} Punto;

Punto medio(Punto, Punto);

int main() {
  Punto a = { 3.5, 4.5 };
  Punto b = { 7, 10 };
  Punto centro = medio(a, b);

  printf("Punto a: (%.2f, %.2f)\n", a.x, a.y);
  printf("Punto b: (%.2f, %.2f)\n", b.x, b.y);
  printf("Punto medio: (%.2f, %.2f)\n", centro.x, centro.y);

  return 0;
}

Punto medio(Punto a, Punto b) {
  //Punto centro = {(a.x+b.x) / 2, (a.y+b.y) / 2};
  Punto centro;
  centro.x = (a.x + b.x) / 2.0;
  centro.y = (a.y + b.y) / 2.0;
  return centro;
}
