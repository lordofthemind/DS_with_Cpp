// Binary search Tree
// Function to search a given key in BST

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

void search(node **tree, int key)
{
    if (*tree == NULL)
    {
        cout << "Not Found" << endl;
        return;
    }
    if (key == (*tree)->data)
    {
        cout << "Found" << endl;
    }
    else if (key < (*tree)->data)
    {
        search(&(*tree)->left, key);
    }
    else if (key > (*tree)->data)
    {
        search(&(*tree)->right, key);
    }
}

int main()
{
    node *root = NULL;
    node *temp;
    int choice;
    int item;
    while (1)
    {
        cout << "1.Insert" << endl;
        cout << "2.Search" << endl;
        cout << "3.Inorder Traversal" << endl;
        cout << "4.Postorder Traversal" << endl;
        cout << "5.Exit" << endl;
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
            cout << "Enter the number to be searched: ";
            cin >> item;
            search(&root, item);
            break;
        case 3:
            cout << "Inorder Traversal of BST: " << endl;
            inorder(root);
            cout << endl;
            break;
        case 4:
            cout << "Postorder Traversal of BST: " << endl;
            postorder(root);
            cout << endl;
            break;
        case 5:
            exit(1);
        default:
            cout << "Wrong choice" << endl;
        }
    }
    return 0;
}