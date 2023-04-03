#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;            // data value held by the node
    struct Node *lChild; // pointer to left child node
    struct Node *rChild; // pointer to right child node
};

// create a new node with the given data value
struct Node *newNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node)); // allocate memory for new node
    newNode->data = data;                                              // set data value
    newNode->lChild = NULL;                                            // set left child pointer to NULL
    newNode->rChild = NULL;                                            // set right child pointer to NULL
    return newNode;                                                    // return pointer to new node
}

// insert a new node with the given data value into the binary tree rooted at root
struct Node *insertNode(struct Node *root, int data)
{
    struct Node *new_node = newNode(data); // create a new node with the given data value
    if (root == NULL)
    { // if the root is NULL, the new node becomes the root
        root = new_node;
        return root;
    }
    struct Node *current = root; // start at the root node
    while (1)
    {
        if (data < current->data)
        { // if the new data value is less than the current node's data value
            if (current->lChild == NULL)
            { // if the current node's left child pointer is NULL, insert the new node here
                current->lChild = new_node;
                break;
            }
            current = current->lChild; // move to the left child node
        }
        else
        {
            if (current->rChild == NULL)
            { // if the current node's right child pointer is NULL, insert the new node here
                current->rChild = new_node;
                break;
            }
            current = current->rChild; // move to the right child node
        }
    }
    return root; // return the root node of the binary tree
}

int main()
{
    struct Node *root = NULL;    // initialize the root node pointer to NULL
    root = insertNode(root, 50); // insert the root node with data value 50
    insertNode(root, 30);        // insert a node with data value 30
    insertNode(root, 20);        // insert a node with data value 20
    insertNode(root, 40);        // insert a node with data value 40
    insertNode(root, 70);        // insert a node with data value 70
    insertNode(root, 60);        // insert a node with data value 60
    insertNode(root, 80);        // insert a node with data value 80
    printf("Binary tree after insertion: %d %d %d %d %d %d %d\n",
           root->data, root->lChild->data, root->lChild->lChild->data,
           root->lChild->rChild->data, root->rChild->data,
           root->rChild->lChild->data, root->rChild->rChild->data); // print the data values of the nodes in the binary tree
    return 0;                                                       // indicate successful program execution
}



struct Node* insertNode(struct Node* root, int data) {
    struct Node* new_node = newNode(data);
    if (root == NULL) {
        root = new_node;
        return root;
    }
    struct Node* current = root;
    while (1) {
        if (data < current->data) {
            if (current->lChild == NULL) {
                current->lChild = new_node;
                break;
            }
            current = current->lChild;
        } else {
            if (current->rChild == NULL) {
                current->rChild = new_node;
                break;
            }
            current = current->rChild;
        }
    }
    return root;
}