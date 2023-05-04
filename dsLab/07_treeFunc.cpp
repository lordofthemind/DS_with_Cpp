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

// The function takes two arguments: a pointer to a pointer to a node, and a pointer to a node.

// The first if statement checks if the pointer to the pointer to the node is null. If it is, it means that the root of the tree has not been initialized yet, so the pointer to the pointer to the node is set to the new node passed as an argument. This effectively initializes the root of the tree.

// If the pointer to the pointer to the node is not null, it means that the root of the tree has already been initialized. The function then compares the value of the new node to the value of the current node pointed to by the pointer to the pointer to the node.

// If the value of the new node is less than the value of the current node, the function recursively calls itself passing the left child of the current node and the new node as arguments. This continues until the function finds an empty left child node, in which case the new node is inserted there.

// If the value of the new node is greater than the value of the current node, the function recursively calls itself passing the right child of the current node and the new node as arguments. This continues until the function finds an empty right child node, in which case the new node is inserted there.

// Once the new node has been inserted, the function returns.

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


// Tree traversal in C

// #include <stdio.h>
// #include <stdlib.h>

// struct node {
//   int item;
//   struct node* left;
//   struct node* right;
// };

// // Inorder traversal
// void inorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   inorderTraversal(root->left);
//   printf("%d ->", root->item);
//   inorderTraversal(root->right);
// }

// // preorderTraversal traversal
// void preorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   printf("%d ->", root->item);
//   preorderTraversal(root->left);
//   preorderTraversal(root->right);
// }

// // postorderTraversal traversal
// void postorderTraversal(struct node* root) {
//   if (root == NULL) return;
//   postorderTraversal(root->left);
//   postorderTraversal(root->right);
//   printf("%d ->", root->item);
// }

// // Create a new Node
// struct node* createNode(value) {
//   struct node* newNode = malloc(sizeof(struct node));
//   newNode->item = value;
//   newNode->left = NULL;
//   newNode->right = NULL;

//   return newNode;
// }

// // Insert on the left of the node
// struct node* insertLeft(struct node* root, int value) {
//   root->left = createNode(value);
//   return root->left;
// }

// // Insert on the right of the node
// struct node* insertRight(struct node* root, int value) {
//   root->right = createNode(value);
//   return root->right;
// }

// int main() {
//   struct node* root = createNode(1);
//   insertLeft(root, 12);
//   insertRight(root, 9);

//   insertLeft(root->left, 5);
//   insertRight(root->left, 6);

//   insertLeft(root->right, 44);
//   insertRight(root->right, 66);
  
//  // insertLeft(root->left, 55);
//   //insertRight(root->left, 222;
  
//   printf("Inorder traversal \n");
//   inorderTraversal(root);

//   printf("\n Preorder traversal \n");
//   preorderTraversal(root);

//   printf("\nPostorder traversal \n");
//   postorderTraversal(root);
// }