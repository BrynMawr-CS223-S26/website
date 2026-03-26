#include <stdlib.h>

int main() {
  // array of arrays 2D matrix 3x4
  int matrix1[3][4]; // static declaration

  int **matrix = malloc(sizeof(int*) * 3);  // allocate rows first
  for (int i = 0; i < 3; i++) {
    matrix[i] = malloc(sizeof(int) * 4); // allocate each column
  }

  for (int i = 0; i < 3; i++) {
    free(matrix[i]); 
  }
  free(matrix);
  return 0;
}

