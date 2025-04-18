#include <stdlib.h>
#include <stdio.h>
#include <time.h>

//recorrido lineal, O(n).
int pico_lineal (int *array, int n) {
 if (n = 1) return 0;
 if (n >= 2 && (array[0] >= array[1])) return 0;
 if (n >= 2 && array[n-1] >= array[n-2]) return n-1;
 for (int i = 1; i < n-1; i++) {
    if (array[i] <= array[i+1] && array[i+1] <= array[i+2])
     return i;
 }
 return -1; //no es necesario, no debería ocurrir
}

//recorrido ¿binario?, O(log(n)).
int pico_binario (int *array, int n) {
 if (array[0] > array[1]) return 0;
 if (array[n - 1] > array[n - 2]) return n -1;
 int inicio = 1, fin = n -2, encontrePico = 0, indice, pico;

 while (inicio <= fin && !encontrePico) {
  indice = (inicio + fin) / 2;
  // indice es pico?
  if (array[indice] < array[indice + 1] 
    && array[indice] < array[indice - 1]) {
     encontrePico = 1;
     pico = indice;
    }
 //no encuentro pico, entonces me desplazo
 //me desplazo derecha como primera opcion
  else if (array[indice] < array[indice + 1]) inicio = indice;
//me desplazo izquierda como segunda opcion
  else fin = indice;
 }
}

int main () {
 int array[5] = {1, 15, 3, 4, 8};
 int indice = pico_lineal(array, 5);
 printf("el pico: %d\n", array[indice]);
 indice = pico_binario(array, 5);
 printf("el pico: %d", array[indice]);
 return 0;
}