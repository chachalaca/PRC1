#include<stdlib.h>
#include<stdio.h>
#include "tree.h"



int decode(Tree *tree) {
    FILE *f = NULL;
    int c = 0;
    int slashcount = 0;
    unsigned long morse = 0;
    unsigned long r_morse = 0;
    int i = 0;
    Node *node;



    f = fopen("decoded.txt", "w");
    if (f == NULL) return -1;

    puts ("Zadejte retezec morseovy abecedy");
    do {
        c=getchar();
        slashcount = (c == '/') ? slashcount+1 : 0;

        if(c == '-' || c == '.'){
            morse = morse << 2;
            morse = morse | ((c == '.') ? 1 : 2);

        }
        else if((c == '/' || c == '\n') && morse != 0) {
            node = search(tree, morse);
            if(!node){
                for(i=0;i<16;i++) {
                    r_morse = (morse & 3) | (r_morse << 2);
                    morse = morse >> 2;
                    if((morse & 3) == 0) break;
                }
                printf("error: cannot decode sequence '");
                for(i=0;i<16;i++) {
                    if((r_morse & 3) == 1) {
                        printf(".");
                    }
                    else if((r_morse & 3) == 2) {
                        printf("-");
                    }
                    r_morse = r_morse >> 2;
                    if((r_morse & 3) == 0) break;
                }
                printf("'\n");
            }
            else
                fputc(node->val, f);
            morse = 0;
        }
        else if(slashcount == 2) {
            fputc(' ', f);
        }
        else if(c != '\n'){
            printf("error: invalid character '%c'(%u)\n", c, c);
        }

    } while (c != '\n' && c != EOF);

    fclose(f);

}

int encode(Tree *tree) {
    FILE *f = NULL;
    int c = 0;
    int spacecount = 0;
    unsigned long morse = 0;
    int i = 0;
    Node *node;



    f = fopen("encoded.txt", "w");
    if (f == NULL) return -1;

    puts ("Zadejte text");
    do {
        c=getchar();
        spacecount = (c == ' ') ? spacecount+1 : 0;

        if(c>='a' && c<='z') {
            c = c-32;
        }
        if(c != '\n' && c != ' ') {
            node = search(tree, c);
            if(!node)
                printf("error: cannot decode character '%c'(ASCII %u)\n", c, c);
            else {
                morse = node->val;
                for(i=0;i<16;i++) {
                    if((morse & 3) == 1) {
                        fprintf(f, ".");
                    }
                    else if((morse & 3) == 2) {
                        fprintf(f, "-");
                    }
                    morse = morse >> 2;
                    if((morse & 3) == 0) break;
                }
                fprintf(f, "/");
            }

        }
        if(c == ' ' && spacecount == 1)
            fprintf(f, "/");
    } while (c != '\n' && c != EOF);

    fclose(f);
}

Tree* getTree(FILE *f, int do_decode) {

    Tree *tree = NULL;
    int c = 0;
    unsigned long morse = 0;
    unsigned long r_morse = 0;
    int letter = 0;
    int i = 0;



    while ((c = fgetc(f)) != EOF) {
        if(c == '-' || c == '.'){
            morse = morse << 2;
            morse = morse | ((c == '.') ? 1 : 2);
        }

        else if(c != ' ' && c != '\n')
            letter = c;

        else if(c == '\n' || c == EOF) {
            if(do_decode)
                insert(&tree, morse, letter);
            else {
                for(i=0;i<16;i++) {
                    r_morse = (morse & 3) | (r_morse << 2);
                    morse = morse >> 2;
                    if((morse & 3) == 0) break;
                }
                insert(&tree, letter, r_morse);
            }
            morse = 0;
            r_morse = 0;
            letter = 0;
        }
    }

    fclose(f);

    return tree;
}

int main(int argc, char **argv)
{
    Tree *tree = NULL;
    FILE *f = NULL;
    int i = 0;
    int do_decode = 0;


    for (i = 0; i < argc; i++)
    {
        if(strcmp(argv[i], "decode") == 0) {
            do_decode = 1;
            printf("Decoding\n\n");
        }
        if(strcmp(argv[i], "-f") == 0) {
            if(argc > i){
                f = fopen(argv[i+1], "r");
                if(!f) {
                    printf("warning: cannot load file '%s'. using default definition file.\n", argv[i+1]);
                }
            }
        }
    }

    if(!f) {
        f = fopen("morse.def", "r");
    }
    if(!f) {
        printf("error: cannot load definition file. check if morse.def exists and try again.\n");
        return -1;
    }

    tree = getTree(f, do_decode);

    dump(tree, 0);

    if(do_decode) {
        decode(tree);
    }
    else {
        encode(tree);
    }

    deleteTree(tree);

}
