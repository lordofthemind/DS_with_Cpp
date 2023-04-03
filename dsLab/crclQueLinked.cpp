// implement circular linked list and operation.
#include <iostream>
using namespace std;

struct cLink
{
    int data;
    struct cLink *next;
} *head = NULL;

void insert(int val)
{
    struct cLink *nNode;
    nNode = (struct cLink *)malloc(sizeof(struct cLink));
    nNode->data = val;

    if (head == NULL)
    {
        head = nNode;
        nNode->next = head;
    }
    else
    {
        struct cLink *temp;
        temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = nNode;
        nNode->next = head;
    }
}

int delet()
{
    struct cLink *temp;
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
    struct cLink *temp;
    temp = head;
    while (temp->next != head)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << temp->data << " ";
}

int search()
{
    int val;
    cout << "Enter the value to search: ";
    cin >> val;
    struct cLink *temp;
    temp = head;
    while (temp->next != head)
    {
        if (temp->data == val)
        {
            cout << "Value found" << endl;
            return 0;
        }
        temp = temp->next;
    }
    if (temp->data == val)
    {
        cout << "Value found" << endl;
        return 0;
    }
    cout << "Value not found" << endl;
    return 0;
}

int main()
{
    int ch, val;
    while (1)
    {
        cout << "1. Insert 2. Delete 3. Traverse 4. Search 5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter the value to insert: ";
            cin >> val;
            insert(val);
            break;
        case 2:
            delet();
            break;
        case 3:
            traverse();
            cout << endl;
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
        default:
            cout << "Invalid choice" << endl;
        }
    }
    return 0;
}