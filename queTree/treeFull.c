#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *lChild;
    struct Node *rChild;
};

struct Node *createNode(int data)
{
    struct Node *newNode;
    newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->lChild = NULL;
    newNode->rChild = NULL;
    printf("Node inserted! %d\n", data);
    return newNode;
}

struct Node *insertNode(struct Node *root, int data)
{
    if (root == NULL)
    {
        root = createNode(data);
        return root;
    }
    struct Node *current = root;
    while (1)
    {
        if (data < current->data)
        {
            if (current->lChild == NULL)
            {
                current->lChild = createNode(data);
                return root;
            }
            current = current->lChild;
        }
        else
        {
            if (current->rChild == NULL)
            {
                current->rChild = createNode(data);
                return root;
            }
            current = current->rChild;
        }
    }
}

struct Node *deleteNode(struct Node *root, int data)
{
    struct Node *parent = NULL;
    struct Node *current = root;
    while (current != NULL && current->data != data)
    {
        parent = current;
        if (data < current->data)
        {
            current = current->lChild;
        }
        else
        {
            current = current->rChild;
        }
    }
    if (current == NULL)
    {
        printf("Node not found!\n");
        return root;
    }
    if (current->lChild == NULL && current->rChild == NULL)
    {
        if (current == root)
        {
            root = NULL;
        }
        else if (current == parent->lChild)
        {
            parent->lChild = NULL;
        }
        else
        {
            parent->rChild = NULL;
        }
        free(current);
    }
    else if (current->lChild == NULL)
    {
        if (current == root)
        {
            root = current->rChild;
        }
        else if (current == parent->lChild)
        {
            parent->lChild = current->rChild;
        }
        else
        {
            parent->rChild = current->rChild;
        }
        free(current);
    }
    else if (current->rChild == NULL)
    {
        if (current == root)
        {
            root = current->lChild;
        }
        else if (current == parent->lChild)
        {
            parent->lChild = current->lChild;
        }
        else
        {
            parent->rChild = current->lChild;
        }
        free(current);
    }
    else
    {
        struct Node *successor = current->rChild;
        parent = current;
        while (successor->lChild != NULL)
        {
            parent = successor;
            successor = successor->lChild;
        }
        current->data = successor->data;
        if (successor == parent->lChild)
        {
            parent->lChild = successor->rChild;
        }
        else
        {
            parent->rChild = successor->rChild;
        }
        free(successor);
    }
    return root;
}

struct Node *searchNode(struct Node *root, int data)
{
    struct Node *current = root;
    while (current != NULL && current->data != data)
    {
        if (data < current->data)
        {
            current = current->lChild;
        }
        else
        {
            current = current->rChild;
        }
    }
    if (current == NULL)
    {
        printf("Node not found!\n");
    }
    return current;
}

void inOrderTraversal(struct Node *root)
{
    if (root != NULL)
    {
        inOrderTraversal(root->lChild);
        printf("%d ", root->data);
        inOrderTraversal(root->rChild);
    }
}

int main()
{
    struct Node *root = NULL;
    root = insertNode(root, 250);
    insertNode(root, 140);
    insertNode(root, 270);
    insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 90);
    insertNode(root, 20);
    insertNode(root, 300);
    insertNode(root, 280);
    insertNode(root, 350);

    printf("Inorder traversal of BST: ");
    inOrderTraversal(root);
    printf("\n");

    struct Node *result = searchNode(root, 280);
    if (result != NULL)
    {
        printf("Node found: %d\n", result->data);
    }

    deleteNode(root, 10);
    deleteNode(root, 30);

    printf("Inorder traversal of BST: ");
    inOrderTraversal(root);
    printf("\n");

    return 0;
}