#include <stdio.h>
#define SIZE 10

int main() {
  int i, size_arr = SIZE;
  int array[SIZE];

  array[0] = 1;
  array[1] = 1;

  for (i = 2; i < size_arr; i++) {
    array[i] = array[i-1] + array[i-2];
  }

  for (i = 0; i < size_arr; i++) {
    printf("%d\n", array[i]);
  }

  return 0;
}
