#include <stdio.h>
#include <stdlib.h>



int main (int argc, char **argv)
{
  int size = 0;
  int i,j,k;
  scanf("%i\n", &size);

int *matice1 = (int*)malloc(size*size*sizeof(int));
int *matice2 = (int*)malloc(size*size*sizeof(int));




for (i = 0; i < size; i++)
{
  for (j = 0; j < size; j++)
  {
    scanf("%i", &matice1[i*size+j]);

  }
}

for (i = 0; i < size; i++)
{
  for (j = 0; j < size; j++)
  {
    scanf("%i", &matice2[i*size+j]);

  }
}



int sum = 0;

for (i = 0; i < size; i++)
{
  for (j = 0; j < size; j++)
  {

    for(k=0;k<size;k++)
        {
            sum += matice1[i*size+k]*matice2[k*size+j];

        }

    printf("%i ", sum);
    sum = 0;
    if(j==k-1) printf("\n");

  }
}

// ...
free(matice1);
free(matice2);
  return 0;
}
