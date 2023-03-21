#include <iostream>
using namespace std;

// Define a node for the binary tree
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node with given data and return a pointer to it
Node *newNode(int data)
{
    Node *node = new Node();
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node into the binary tree
Node *insertNode(Node *root, int data)
{
    if (root == NULL)
    {
        root = newNode(data);
        return root;
    }
    if (data < root->data)
    {
        root->left = insertNode(root->left, data);
    }
    else
    {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Traverse the binary tree in pre-order
void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

// Traverse the binary tree in in-order
void inOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

// Traverse the binary tree in post-order
void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main()
{
    Node *root = NULL;

    // Insert nodes into the binary tree
    root = insertNode(root, 10);
    insertNode(root, 5);
    insertNode(root, 15);
    insertNode(root, 3);
    insertNode(root, 8);
    insertNode(root, 12);
    insertNode(root, 18);

    // Traverse the binary tree in pre-order
    cout << "Pre-order traversal: ";
    preOrderTraversal(root);
    cout << endl;

    // Traverse the binary tree in in-order
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // Traverse the binary tree in post-order
    cout << "Post-order traversal: ";
    postOrderTraversal(root);
    cout << endl;

    return 0;
}
