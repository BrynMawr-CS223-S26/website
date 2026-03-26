#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void init_values(int* a, int* b, int* c) {

  *a = rand() % 10;
  *b = rand() % 10;
  *c = rand() % 10;
}

int main() {
  srand(time(0));

  int x, y, z;
  init_values(&x, &y, &z);
  printf("%d %d %d\n", x, y, z);
  return 0;
}
