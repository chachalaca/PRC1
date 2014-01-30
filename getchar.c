#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>


int main (int argc, char **argv)
{
	int c,d=0;

	puts ("Zadejte cele cislo");
	do {
	c=getchar();
	if((c>=48 and c<=57) or c==10) {
	    	if(c!=10) {
			d+=(c-48);
			d=d*10;
		}
		else {d=d/10;}
	} else {
		puts ("Nebylo zadano cislo.");
		return 1;
	}
	} while (c != 10);
	printf("%i\n", d);
	return 0;

}



