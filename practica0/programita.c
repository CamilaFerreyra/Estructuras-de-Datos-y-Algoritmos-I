#include <stdio.h>

int *direccion_local(int x) {
  int *p;
  p = &x;
  return p;
  //retunr &x; está mal mal muy mal.
}

int main() {
  int *prt = NULL;
  int num = 2;
  prt = direccion_local(num);
  printf("%d\n", *prt);
  return 0;
}
