#include <stdio.h>

int main() {
FILE *f2;
int i, j;

f2 = fopen("dest.txt", "w");
for(i=1;i<=10; i++) {
    for(j=1;j<=10;j++) {

        fprintf(f2, "%i %i %i\n", i, j, i*j);
    }

}

fcloseall();
}
