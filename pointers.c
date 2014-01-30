#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>


int main (int argc, char **argv)
{
	int pole[10] = {1,2,4,8,5,6,7,3,9,10};
	pole ++;
	vypispole(pole);
	
	return 0;

}

void vypispole(int* pole) {
  int i;
  for(i=0;i<10;i++) {
      printf("%i\n", *(pole+i));
  }
  
}



