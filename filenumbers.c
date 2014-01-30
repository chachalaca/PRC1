#include <stdio.h>

int main() {
FILE *f1, *f2;
char c;
int n;

f1 = fopen("source.txt", "r");

f2 = fopen("dest.txt", "w");


n=1;

while((c=fgetc(f1))!=EOF) {
    if(n==1) {
       fprintf(f2, "%06d ", n);
       n++;
    }
    if((c == '\n')) {
        fputc(c, f2);
        fprintf(f2, "%06d ", n);

        n++;
    }
    else {fputc(c, f2);}


}

fclose(f1);
fclose(f2);
}
