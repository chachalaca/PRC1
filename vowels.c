#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>


int main (int argc, char **argv)
{
	int c,d=0;

	puts ("Zadejte text");
	do {
		c=getchar();
		if(c==65 || c==69 || c==73 || c==79 || c==85 || c==97 || c==101 || c==105 || c==111 || c==117 || c==89 || c==121) {
		    	
		} else {
			putchar(c);
		}
	} while (c != 10);
	
	return 0;

}



