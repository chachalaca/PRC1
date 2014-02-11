
#include "tree.h"


void insert(Tree ** tree, int key, int val)
{
    Node *tmp = NULL;
    if(!(*tree))
    {
        tmp = (Node *)malloc(sizeof(Node));
        tmp->left = tmp->right = NULL;
        tmp->key = key;
        tmp->val = val;
        *tree = tmp;
        return;
    }

    if(key < (*tree)->key)
    {
        insert(&(*tree)->left, key, val);
    }
    else if(key > (*tree)->key)
    {
        insert(&(*tree)->right, key, val);
    }

}

void deleteTree(Tree * tree)
{
    if (tree)
    {
        deleteTree(tree->left);
        deleteTree(tree->right);
        free(tree);
    }
}

Node* search(Tree * tree, int key)
{
    if(!tree)
    {
        return NULL;
    }

    if(key < tree->key)
    {
        search(tree->left, key);
    }
    else if(key > tree->key)
    {
        search(tree->right, key);
    }
    else if(key == tree->key)
    {
        return tree;
    }
}


