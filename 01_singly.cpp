#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void traverseList()
{
    struct node *current;
    current = head;
    if (head == NULL)
    {
        cout << "List is empty, nothing to print." << endl;
    }
    else
    {
        cout << "List is as follows..." << endl;
        while (current != NULL)
        {
            cout << current->data;
            if(current->next != NULL)
                cout << " -> ";
            current = current->next;
        }
        cout << endl;
    }
}

void Insert()
{
    struct node *ptr, *trvrs;
    int item;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "Memory Full." << endl;
    }
    else
    {
        cout << "Enter element: ";
        cin >> item;
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
            cout << "Elelment inserted in last." << endl;
        }
        else
        {
            trvrs = head;
            while (trvrs->next != NULL)
            {
                trvrs = trvrs->next;
            }
            trvrs->next = ptr;
            ptr->next = NULL;
            cout << "Element inserted in last." << endl;
        }
    }
}

void randDelete()
{
    struct node *trvrs, *trvrs_1;
    int pos;
    cout << "Enter the location of element you want to delete :" << endl;
    cin >> pos;
    trvrs = head;
    for (int i = 0; i < pos - 1; i++)
    {
        trvrs_1 = trvrs;
        trvrs = trvrs->next;
        if (trvrs == NULL)
        {
            cout << "Can't delete! location out of bound!!" << endl;
            return;
        }
    }
    trvrs_1->next = trvrs->next;
    free(trvrs);
    cout << "Element deleted at position " << pos << endl;
}

int main()
{
    head = NULL;
    int choice;
    while (true)
    {
        cout << "1. Insert an element" << endl;
        cout << "2. Delete an element" << endl;
        cout << "3. Traverse the list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            Insert();
            break;
        case 2:
            randDelete();
            break;
        case 3:
            traverseList();
            break;
        case 4:
            exit(0);
            break;
        default:
            cout << "Invalid choice, please enter a valid choice." << endl;
        }
    }
    return 0;
}