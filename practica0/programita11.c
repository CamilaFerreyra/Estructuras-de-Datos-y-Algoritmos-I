#include <stdio.h>
void nullify(int *a) {
  a = NULL;
}

/* ejercicio a - 123 123 */

int main() {
  int a[67];
  a[0] = 123;
  printf("%d\n ", a[0]);
  nullify(a);
  printf("%d \n ", a[0]);
  return 0;
}

  /*ejercicio b - Segmentation fault
     int main() {
     char *ptr = "hola mundo";
     ptr[0] = 's';
     printf("%s\n", ptr);
     return 0;
     }
   */
