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
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
}

void beginInsert()
{
    struct node *ptr;
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
        ptr->next = head;
        head = ptr;
        cout << "Element inserted." << endl;
    }
}

void endInsert()
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

void randInsert()
{
    struct node *ptr, *trvrs;
    int item, i, pos;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        cout << "Memory Full." << endl;
    }
    else
    {
        cout << "Enter the location of element after which you want to insert: ";
        cin >> pos;
        pos--;
        trvrs = head;
        for (i = 0; i < pos; i++)
        {
            trvrs = trvrs->next;
            if (trvrs == NULL)
            {
                cout << "Can't insert, location out of bound." << endl;
                return;
            }
        }
        cout << "Enter element: ";
        cin >> item;
        ptr->data = item;
        ptr->next = trvrs->next;
        trvrs->next = ptr;
        cout << "Element inserted after " << pos << endl;
    }
}

void beginDelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "Nothing to delete." << endl;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        free(ptr);
        cout << "Element Deleted from begining." << endl;
    }
}

void endDelete()
{
    struct node *trvrs, *trvrs_1;
    if (head == NULL)
    {
        cout << "Memory Full." << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "Only element in list deleted." << endl;
    }
    else
    {
        trvrs = head;
        while (trvrs->next != NULL)
        {
            trvrs_1 = trvrs;
            trvrs = trvrs->next;
        }
        trvrs_1->next = NULL;
        free(trvrs);
        cout << "Element deleted from last." << endl;
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
    cout << "Element deleted at position " << pos + 1 << endl;
}

void search()
{
    struct node *trvrs;
    int item, pos = 0, flag = 0;
    trvrs = head;
    if (head == NULL)
    {
        cout << "List is empty." << endl;
    }
    else
    {
        cout << "Enter element you are looking for : ";
        cin >> item;
        while (trvrs != NULL)
        {
            if (trvrs->data == item)
            {
                cout << "element found at location " << pos + 1 << endl;
            }
            else
            {
                flag = 1;
            }
            pos++;
            trvrs = trvrs->next;
            if (flag == 0)
            {
                cout << "item not found!" << endl;
            }
        }
    }
}

int main()
{
    int ch = 0;
    while (ch != 9)
    {
        cout << "Choose operation to perform on singly linked list: " << endl;
        cout << "1> Search in list." << endl;
        cout << "2> Traverse through list." << endl;
        cout << "3> Insert in ending of list." << endl;
        cout << "4> Insert in begining of list." << endl;
        cout << "5> Insert at a position in list." << endl;
        cout << "6> Delete from ending of list." << endl;
        cout << "7> Delete from begining of list." << endl;
        cout << "8> Delete from a position in list." << endl;
        cout << "9> Exit programm." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            search();
            traverseList();
            break;
        case 2:
            traverseList();
            break;
        case 3:
            endInsert();
            traverseList();
            break;
        case 4:
            beginInsert();
            traverseList();
            break;
        case 5:
            randInsert();
            traverseList();
            break;
        case 6:
            endDelete();
            traverseList();
            break;
        case 7:
            beginDelete();
            traverseList();
            break;
        case 8:
            randDelete();
            traverseList();
            break;
        case 9:
            exit;
            break;
        default:
            cout << "Enter valid input." << endl;
            break;
        }
    }
    return 0;
}