#include <stdio.h>

int main() {
  int x;
  float y;
  char s[100]; 
  printf("Enter values: \n");
  scanf(" %d%f%s", &x, &y, s); 
  printf("%d\n", x);
  printf("%f\n", y);
  printf("%s\n", s);

  printf("%p\n", s); // print pointer
  return 0;
}

