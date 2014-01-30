#include <stdio.h>
#include <stdlib.h>

const int step = 5;

int main (int argc, char **argv)
{
  char *pole = NULL, *pole2;
  int i = 0;
  int capacity = 0;
  int c;
  while ((c = getchar()) != EOF)
  {
    if (i >= capacity)
    {
      capacity += step;
      pole2 = realloc(pole, capacity*sizeof(char));
      if (!pole2)
      {
        printf("dosla pamet\n");
        free(pole);
        return -1;
      }
      pole = pole2;
    }
    pole[i++] = c;
  }
  int j;
  for (j = i - 1; j >= 0; j--)
    putchar(pole[j]);
  free(pole);
  return 0;
}
