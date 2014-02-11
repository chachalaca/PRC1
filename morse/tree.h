#include<stdlib.h>
#include<stdio.h>


#ifndef Tree_H
#define        Tree_H

struct Node {
    unsigned long key;
    int val;
    struct Node * right, * left;
};
typedef struct Node Tree;
typedef struct Node Node;


void insert(Tree ** tree, int key, int val);

void deleteTree(Node * tree);

Node* search(Tree * tree, int key);

#endif        /* Tree_H */
