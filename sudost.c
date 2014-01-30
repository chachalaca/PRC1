#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main (int argc, char **argv)
{
int a;
scanf("%i", &a);
if((a&1)==0)
{
printf("cislo je sude \n");
}
else printf("cislo neni sude. \n");
return 0;

}
