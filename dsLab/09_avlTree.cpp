// Avl tree with insertion and rotation

#include <iostream>
using namespace std;

struct node
{
    int data;
    node *left;
    node *right;
};

void insert(node **tree, node *item)
{
    if (!(*tree))
    {
        *tree = item;
        return;
    }
    if (item->data < (*tree)->data)
    {
        insert(&(*tree)->left, item);
    }
    else if (item->data > (*tree)->data)
    {
        insert(&(*tree)->right, item);
    }
}

