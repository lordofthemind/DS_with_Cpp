#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
struct node *head;

void line()
{
    cout << "+++++++++++++++++++++++++++++++++++" << endl;
}

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
            cout << current->data << " <-> ";
            current = current->next;
        }
        cout << endl;
    }
}

void traverseListRev()
{
    struct node *current;
    current = head;
    if (head == NULL)
    {
        cout << "List is empty, nothing to print." << endl;
    }
    else
    {
        cout << "Reverse of list is as follows..." << endl;
        while (current->next != NULL)
        {
            current = current->next;
        }
        while (current->prev != NULL)
        {
            cout << current->data << " <-> ";
            current = current->prev;
        }
        cout << current->data << endl;
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
        ptr->prev = NULL;
        if (head == NULL)
        {
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->next = head;
            head->prev = ptr;
            head = ptr;
        }
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
        ptr->next = NULL;
        if (head == NULL)
        {
            ptr->prev = NULL;
            head = ptr;
        }
        else
        {
            trvrs = head;
            while (trvrs->next != NULL)
            {
                trvrs = trvrs->next;
            }
            trvrs->next = ptr;
            ptr->prev = trvrs;
        }
        cout << "Element inserted in last." << endl;
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
        ptr->prev = trvrs;
        trvrs->next->prev = ptr;
        trvrs->next = ptr;
        cout << "Element inserted after " << pos << endl;
    }
}

void beginDelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "Memory underflow." << endl;
    }
    else if (head->next == NULL)
    {
        head = NULL;
        free(head);
        cout << "Only element deleted." << endl;
    }
    else
    {
        ptr = head;
        head = ptr->next;
        head->prev = NULL;
        free(ptr);
        cout << "Element Deleted from begining." << endl;
    }
}

void endDelete()
{
    struct node *trvrs;
    if (head == NULL)
    {
        cout << "Memory underflow." << endl;
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
            trvrs = trvrs->next;
        }
        trvrs->prev->next = NULL;
        free(trvrs);
        cout << "Element deleted from last." << endl;
    }
}

void randDelete()
{
    struct node *trvrs;
    int pos, cnt = 0;
    cout << "Enter the location of element you want to delete :" << endl;
    cin >> pos;
    pos--;
    trvrs = head;
    while (trvrs != NULL && cnt < pos)
    {
        trvrs = trvrs->next;
        cnt++;
    }
    if (trvrs == NULL)
    {
        cout << "Can't delete! location out of bound!!" << endl;
        return;
    }
    if (trvrs == head)
    {
        head = head->next;
        head->prev = NULL;
    }
    else if (trvrs->next == NULL)
    {
        trvrs->prev->next = NULL;
    }
    else
    {
        trvrs->prev->next = trvrs->next;
        trvrs->next->prev = trvrs->prev;
    }
    free(trvrs);
    cout << "Element deleted at position " << pos << endl;
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
                flag = 1;
            }
            else
            {
                flag = 0;
            }
            pos++;
            trvrs = trvrs->next;
        }
        if (flag == 0)
        {
            cout << "item not found!" << endl;
        }
    }
}

int main()
{
    int ch = 0;
    while (ch != 10)
    {
        cout << "Choose operation to perform on doubly linked list: " << endl;
        cout << "1> Search in list." << endl;
        cout << "2> Traverse through list." << endl;
        cout << "3> Insert in ending of list." << endl;
        cout << "4> Insert in begining of list." << endl;
        cout << "5> Insert at a position in list." << endl;
        cout << "6> Delete from ending of list." << endl;
        cout << "7> Delete from begining of list." << endl;
        cout << "8> Delete from a position in list." << endl;
        cout << "9> Traverse through list reverse." << endl;
        cout << "10> Exit programm." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            search();
            traverseList();
            line();
            break;
        case 2:
            traverseList();
            line();
            break;
        case 3:
            endInsert();
            traverseList();
            line();
            break;
        case 4:
            beginInsert();
            traverseList();
            line();
            break;
        case 5:
            randInsert();
            traverseList();
            line();
            break;
        case 6:
            endDelete();
            traverseList();
            line();
            break;
        case 7:
            beginDelete();
            traverseList();
            line();
            break;
        case 8:
            randDelete();
            traverseList();
            line();
            break;
        case 9:
            traverseListRev();
            traverseList();
            line();
            break;
        case 10:
            exit;
            line();
            break;
        default:
            cout << "Enter valid input." << endl;
            break;
        }
    }
    return 0;
}