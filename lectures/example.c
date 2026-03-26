#include <stdio.h>

int func(int a, int b); // forward declaration

int main() {
	int x, y;  // declare two integers
	x = 4;
	y = 7;
	y = func(x, y);
  for (int i = 0; i < 3; i++) {
	  printf("%d, %d\n", x, y);
  }
   
  return 0; 
}

int func(int a, int b) {
	a += 5;
	if (a > 10) return 0;
	return a - b;
}
