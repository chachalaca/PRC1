#include <stdio.h>
int compare (const void *a, const void *b)
{
  if(*((int*)a) > *((int*)b)) return 1;
  if(*((int*)a) == *((int*)b)) return 0;
  if(*((int*)a) < *((int*)b)) return -1;
 
}

int main() {
  int a = 2;
  int b = 3;
  printf("%i", compare(&b, &a));
  
}