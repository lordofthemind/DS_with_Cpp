// priority queue using linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    int priority;
    struct Node *next;
} *head = NULL;

// void insert(int data, int priority)
// {
//     struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
//     newNode->data = data;
//     newNode->priority = priority;
//     newNode->next = NULL;

//     if (head == NULL)
//     {
//         head = newNode;
//         return;
//     }

//     if (priority > head->priority)
//     {
//         newNode->next = head;
//         head = newNode;
//         return;
//     }

//     struct Node *temp = head;
//     while (temp->next != NULL && temp->next->priority >= priority)
//     {
//         temp = temp->next;
//     }
//     newNode->next = temp->next;
//     temp->next = newNode;
// }

void insert(int data, int priority)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    if (priority < head->priority)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node *temp = head;
    while (temp->next != NULL && temp->next->priority <= priority)
        temp = temp->next;
    newNode->next = temp->next;
    temp->next = newNode;
}

int delet()
{
    if (head == NULL)
    {
        cout << "Nothing to delete!" << endl;
        return 0;
    }
    struct Node *temp = head;
    head = head->next;
    free(temp);
    return 0;
}

void traverse()
{
    if (head == NULL)
    {
        cout << "Nothing to print!" << endl;
        return;
    }
    struct Node *trvrs;
    trvrs = head;
    while (trvrs->next != NULL)
    {
        cout << trvrs->data << " || " << trvrs->priority;
        if (trvrs->next != NULL)
            cout << " -> ";
        trvrs = trvrs->next;
    }
    cout << trvrs->data << " || " << trvrs->priority << endl;
}

int main()
{
    int ch, val, pri;
    while (1)
    {
        cout << "1. Insert";
        cout << "\n2. Delete";
        cout << "\n3. Traverse";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the value to be inserted: ";
            cin >> val;
            cout << "Enter the priority: ";
            cin >> pri;
            insert(val, pri);
            break;
        case 2:
            delet();
            break;
        case 3:
            traverse();
            break;
        case 4:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}