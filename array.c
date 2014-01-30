#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <limits.h>


void insertionSort(int array[10]) {
	int value;
	int j;
	for(int i=1;i<10;i++){
		value = array[i];
		j=i-1;
	
	while(j>=0 and array[j] > value) {
		array[j+1]=array[j];
		j=j-1;
	} 
	array[j+1]=value;
	}
	
}

int main (int argc, char **argv)
{
	int array[10];
	for(int i=0;i<10;i++)
		{
		array[i] = array[i]%10;
		
		}

	insertionSort(array);
	for(int i=0;i<10;i++)
		{
		
		printf("%i\n", array[i]);
		}

}


