#include <stdio.h>

int main() {
    char textoA[30] = "Agarrate Cataaa";
    char textoB[30] = "El Cuarteto de Nos";
    char* p = textoA;
    char* q = textoB;
    printf("textoA: %s\ntextoB: %s\n", textoA, textoB);

    while(*p++ = *q++);

    printf("while(*p++ = *q++);\n");
    printf("textoA: %s\ntextoB: %s\n", textoA, textoB);

    return 0;
}

/*Sin importar el tamaño de los arreglos,
el while copia el segundo en el primero.*/