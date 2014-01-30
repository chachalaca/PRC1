#include <stdio.h>

// porovna dve hodnoty typu int
int compare (const void *a, const void *b)
{
  if(*((int*)a) > *((int*)b)) return 1;
  if(*((int*)a) == *((int*)b)) return 0;
  if(*((int*)a) < *((int*)b)) return -1;

}

// prehodi hodnoty na pozicich first a second
void swap (void *first, void *second, int size)
{
  if (first == second) return;
  int i;
  char *f = (char*)first;
  char *s = (char*)second;
  char b;

  for(i=0;i<size;i++) {
    b = *(f+i);
    *(f+i) = *(s+i);
    *(s+i) = b;
  }
}

// vysvetlete kod nasledujici funkce
void* partition (void *base, int n, int size, void *index, int(*compare)(const void*, const void*))
{
  int i;
  char *store = (char*)base;
  char *basec = (char*)base;
  swap (index, basec + (n - 1)*size, size); // hodi pivot na konec
  for (i = 0; i < n - 1; i++)
  {
      if (compare(basec + i*size, basec + (n - 1)*size) <= 0) // porovnava postupne prvky od zacatku s pivotem
      {
        swap(basec + i*size, store, size); // pokud je mensi nez pivot, tak hodi prvek na zacatek
        store += size; // posune o delku datoveho typu
      }
  }
  swap(store, basec + (n - 1)*size, size); // vrati pivot na misto
  return store; // dostavame pole rozdelene pivotem na mensi prvky pred a vetsi prvky za, fce vraci ukazatel na pivot
}

void my_qsort (void *base, int n, int size, int(*compare)(const void*, const void*))
{
  if (n <= 1) return;
  char* basec = (char*)base;
  char *newp = (char*)partition(base, n, size, basec + ((n - 1) / 2)*size, compare);

  // doplnte volani funkci
  // leva podcast aktualni casti
  my_qsort(basec , (newp - basec)/size, size, compare);
  // prava podcast aktualni casti
  my_qsort(newp+size ,n + (basec - newp)/size - 1 , size, compare);
}

int main(int argc, char **argv)
{
  printf("zadejte velikost pole: ");
  int s;
  scanf("%i", &s);
  int *arr = (int*)malloc((sizeof(int))*s);
  if(arr == NULL){printf("chyba v alokaci "); return;}
  int i;
  for(i=0;i<s;i++) {
    scanf("%i", &arr[i]);
  }

  //int pole[10] = {1, 3, 2, 1, 6, 4, 8, 2, 3, 5};
  // 3 je vetsi nez 2
   //printf("compare vraci %d\n", compare(&pole[1], &pole[2]));

  // 1 je mensi nez 6
   //printf("compare vraci %d\n", compare(&pole[3], &pole[4]));

  // 1 se rovna 1
//printf("compare vraci %d\n", compare(&pole[3], &pole[3]));

  // prehodi prvek 0 a 1
   //swap(&pole[0], &pole[1], sizeof(int));
  my_qsort(arr, s, sizeof(int), compare);
  int j;
  for (j = 0; j < s; j++) {
    printf("%d\n", arr[j]);
  }
  free(arr);
  return 0;

}
