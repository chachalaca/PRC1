#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>

float random_number(float min_num, float max_num)
        {
        
  	float cislo = rand()/(1.0 + RAND_MAX);        
        return (cislo*(max_num-min_num)+min_num);
        }

int main (int argc, char **argv)
{
	float x,y,above=0,under=0;
	int i;

	srand(time(0));
	for(i=1; i<10000000; i++) {
				
		x =  (rand()/(1.0 + RAND_MAX)*M_PI);        
		y =  (rand()/(1.0 + RAND_MAX)*1);
		
		if(sin(x)>y) {
			under++;
		}
		else { above++; }
		
	}

	printf("plocha pod funkci sinus: %f \n", under/(under+above)*M_PI);
	return 0;

}



