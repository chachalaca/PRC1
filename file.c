#include <stdio.h>

int main() {
FILE *f1, *f2;
char c;
int n;

f1 = fopen("source.txt", "r");

f2 = fopen("dest.txt", "w");


n=0;

while((c=fgetc(f1))!=EOF) {

    if((n==0 || c != '\n')) {
        fputc(c, f2);
        n=0;
    }
    if (c == '\n') {
        n++;
    }

}

fcloseall();
}
