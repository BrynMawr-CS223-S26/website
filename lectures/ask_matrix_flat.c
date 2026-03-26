#include <stdlib.h>

int main() {
  // flat 2D matrix 3x4
  int matrix1[3][4]; // static declaration

  int *matrix = malloc(sizeof(int) * 3 * 4); 
  free(matrix);
  return 0;
}

