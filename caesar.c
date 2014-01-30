#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>


int main (int argc, char **argv)
{
	int c,d,e=0;
	
	
	d = atoi(argv[1]);

	if(argc>2) {
	  e = atoi(argv[2]);
	}

	puts ("Zadejte text");
	do {
		c=getchar();
		if(c>=65 && c<=90) {
		    	c += 32;
		} 
		if(c>=97 && c<=122) {
		  c -= 97;
		  if(e==1) {
		    c = (c+d)%26;
		  }
		  else { 
		    c = (c-d);
		    if(c<0) {
		      c += 26;
		    }
		  }
		  c += 97;
		  
		  putchar (c);
		}
		
	} while (c != 10);
	
	return 0;

}



