// create binary tree using linked list and do some operations
// including: preorder, inorder, postorder

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

void inorder(node *tree)
{
    if (tree)
    {
        inorder(tree->left);
        cout << tree->data << " ";
        inorder(tree->right);
    }
}

void postorder(node *tree)
{
    if (tree)
    {
        postorder(tree->left);
        postorder(tree->right);
        cout << tree->data << " ";
    }
}

void preorder(node *tree)
{
    if (tree)
    {
        cout << tree->data << " ";
        preorder(tree->left);
        preorder(tree->right);
    }
}

int main(){
    node *root = NULL, *temp;
    int choice;
    while (1)
    {
        cout << "1.Insert\n2.Inorder\n3.Preorder\n4.Postorder\n5.Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            temp = new node;
            cout << "Enter the number to be inserted: ";
            cin >> temp->data;
            insert(&root, temp);
            break;
        case 2:
            cout << "Inorder Traversal: ";
            inorder(root);
            cout << endl;
            break;
        case 3:
            cout << "Preorder Traversal: ";
            preorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal: ";
            postorder(root);
            cout << endl;
            break;
        case 5:
            exit(0);
        default:
            cout << "Wrong choice." << endl;
        }
    }
}