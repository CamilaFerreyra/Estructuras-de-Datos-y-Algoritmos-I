#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
  int *direccion;
  int capacidad;
} ArregloEnteros;

void bubble_sort (float arreglo[], int longitud) {
  for (int i = 0; i < longitud -1; i++) {
    for (int j = 0; j < longitud - i - 1; j++) {
      if (arreglo[j] > arreglo[j + 1]) {
        float aux = arreglo[j];
        arreglo[j] = arreglo[j + 1];
        arreglo[j + 1] = aux;
      }
    }
  }
}

// Funciones básicas

//crear
ArregloEnteros *arreglo_enteros_crear(int capacidad);
//destruir
void arreglo_enteros_destruir(ArregloEnteros * arreglo);
//leer
int arreglo_enteros_leer(ArregloEnteros * arreglo, int pos);
//escribir
int arreglo_enteros_escribir(ArregloEnteros * arreglo, int pos, int dato);
//obtener algun dato
int arreglo_enteros_capacidad(ArregloEnteros * arreglo);
//imprimir todo
void arreglo_enteros_imprimir(ArregloEnteros * arreglo);
//2d
int string_compare(char *, char *);
//2e - compare
int string_subcadena(char *, char *);

//(1)
float mediana(float arreglo[], int largo) {
  //mediana no debe modificar el arreglo original
  if (largo % 2 == 0) {
    //par, retorno promedio;
    float suma = 0;
    for (int i = 0; i < largo; i++) {
      suma += arreglo[i];
    }
    return suma / largo;
  } else {
    float arregloCopia[largo];
    for(int i = 0; i < largo; i++)
      arregloCopia[i] = arreglo[i];
    bubble_sort(arregloCopia, largo);
    for(int i = 0; i < largo; i++)
      printf("\n%f\n",arregloCopia[i]);
    int i = largo / 2 + 1;
    return arregloCopia[i];
  }
}

//ejercicio 2
// a)
int string_len(char *str) {
  int i = 0;
  //for(int i = 0; *(str + i) != '\0'; i++);
  while (*(str + i) != '\0')
    i++;
  return i;
}

// b)
void string_reverse(char *str) {
  int longitud = string_len(str);
  int i = 0, j = longitud - 1;
  while ((i != j) && (i < j)) {
    char aux = str[i];
    printf("\nEsta: %c, quiero %c", str[i], str[j]);
    str[i] = str[j];
    str[j] = aux;
    i++;
    j--;
  }
}

//c)
int string_concat(char *str1, char *str2, int max) {
  //comportamiento indefinido para el caso de que 
  //str1 no tenga el espacio suficiente.
  if (max == 0)
    return 0;
  int largo1 = string_len(str1);
  int largo2 = string_len(str2);
  //no puedo perder mi puntero inicial.
  //usar puntero aux.
  char *aux;
  aux = str1 + largo1; //lo apunto al terminador de una.
  if(max > largo2) max = largo2;
  for (int i = 0; i < max; i++)
    *(aux + i) = *(str2 + i);
    //aux[i] = str2[i];
  *(aux + max + 1) = '\0';
  // 
  return max;
}

int string_compare(char *str1, char *str2) {
  //primero *, luego ++, para la prox iteracion
  while((*str1 == *str2) && *str1 != '\0' && *str2 != '\0') {
    str1++;
    str2++;
  }
  if (*str1 == '\0' && *str2 == '\0')
    return 0;
  if (*str1 < *str2)
    return -1;
  if (*str1 > *str2)
    return 1;
}


int string_subcadena(char *str1, char *str2) {
  //for (; stcm*str1)
}



int main() {
  /*int arreglo[10];
     ArregloEnteros arregloDeEnteros;

     arregloDeEnteros.capacidad = 10;
     arregloDeEnteros->direccion = &arreglo;
     return 0;
   */
  //ejercicio 1
  float arreglo[10] = { 1.0, 1.9, 1.3, 1.4, 1.7, 1.6, 1.5, 1.8, 1.2, 2 };
  printf("La mediana es: %.2f", mediana(arreglo, 9));
  
  //ejercicio 2
  //2.b
  char *cadenaPuntero, cadena[10] = "HOLA";
  printf("\n%s se vuelve: ", cadena);
  string_reverse(cadena);
  printf("%s\n", cadena);

  //2.c concat
  char str1[20] = "Hola1";
  char str2[] = "Chau";
  printf("str1: %s str2: %s. ", str1, str2);
  printf("Se agregaron %d caracteres. La palabra es: %s\n", 
          string_concat(str1, str2, 0), str1);
  
  //2.d compare
  printf("comparación : %d\n", string_compare(str1, str2));

  return 0;
}

/*
ArregloEnteros* arreglo_enteros_crear (int capacidad) {
    struct ArregloEnteros* arregloDeEnteros;
    arregloDeEnteros = malloc(sizeof(ArregloEnteros));

    int arreglo [capacidad];

    ArregloEnteros arregloCreado;
    
    arregloCreado.capacidad = capacidad;
    arregloCreado.direccion = &arreglo; //deberia ser igual que arreglo[0]

    arregloDeEnteros = &arregloCreado;

    return arregloDeEnteros;
}
*/
