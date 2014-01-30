#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

void swap(int *a, int *b) {
  int c = *a;
  *a = *b;
  *b = c;
   
}

int main (int argc, char **argv)
{
	int a=3, b=5;
	swap( &a, &b);
	printf("%i %i\n", a, b);
	return 0;

}





