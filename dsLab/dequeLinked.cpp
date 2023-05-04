// implement double ended queue using linked list and perform operation.
#include <iostream>
using namespace std;

struct dLink
{
    int data;
    struct dLink *next;
    struct dLink *prev;
} *head = NULL;

void insert(int val)
{
    struct dLink *nNode;
    nNode = (struct dLink *)malloc(sizeof(struct dLink));
    nNode->data = val;

    if (head == NULL)
    {
        head = nNode;
        nNode->next = head;
        nNode->prev = head;
    }
    else
    {
        struct dLink *temp;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = nNode;
        nNode->prev = temp;
        nNode->next = head;
        head->prev = nNode;
    }
}

int delet()
{
    struct dLink *temp;
    if (head == NULL)
        printf("\nUNDERFLOW");
    temp = head;
    while (temp->next != head)
    {
        temp = temp->next;
    }
    if (temp->next = head)
    {
        head = NULL;
        return 0;
    }

    temp->next = head->next;
    head = head->next;
    return 0;
}

void traverse()
{
    struct dLink *temp;
    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}


