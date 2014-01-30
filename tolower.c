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
		if(c>=65 && c<=90) {
		    	putchar(c+32);
		} else {
			putchar(c);
		}
	} while (c != 10);
	
	return 0;

}



