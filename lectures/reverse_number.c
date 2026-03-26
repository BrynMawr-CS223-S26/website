#include <stdio.h>
#include <stdlib.h>

int main() {
  printf("Enter the size of the array: ");
  int x;
  scanf(" %i", &x);

  int* arr = malloc(sizeof(int) * x);

  int val;
  for (int i = x-1; i >= 0; i--) {
    printf("Enter a number: ");
    scanf(" %d", &val);
    arr[i] = val;
  }

  printf("The reverse order is ");
  for (int i = 0; i < x; i++) {
    printf("%i ", arr[i]);
  }
  printf("\n");

  free(arr);
  return 0;
}
