// Insertion - adding a new node to the list
// Deletion - removing a node from the list
// Traversal - visiting all the nodes in the list
// Searching - finding a specific node in the list
// Sorting - rearranging the nodes in a specific order
// Reversal - reversing the order of the nodes in the list.

#include <iostream>
using namespace std;

struct node
{
    struct node *prev;
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
            cout << current->data << " ";
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
        cout << "Memory overflow." << endl;
    }
    else
    {
        cout << "Enter element: ";
        cin >> item;
        if (head == NULL)
        {
            ptr->data = item;
            ptr->prev = NULL;
            ptr->next = NULL;
            head = ptr;
        }
        else
        {
            ptr->data = item;
            ptr->prev = NULL;
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
        cout << "Memory overflow." << endl;
    }
    else
    {
        cout << "Enter element: ";
        cin >> item;
        ptr->data = item;
        if (head == NULL)
        {
            ptr->next = NULL;
            head->prev = NULL;
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
            ptr->next = NULL;
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
        cout << "Memory overflow." << endl;
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
        trvrs->next = ptr;
        trvrs->next->prev = ptr;
        cout << "Element inserted after " << pos << endl;
    }
}

void beginDelete()
{
    struct node *ptr;
    if (head == NULL)
    {
        cout << "Memory underflow." << endl;
    }else if (head->next == NULL){
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
    struct node *trvrs, *temp;
    int pos;
    cout << "Enter the location of element you want to delete :" << endl;
    cin >> pos;
    trvrs = head;
    for (int i = 0; i < pos - 1; i++)
    {
        trvrs = trvrs->next;
        if (trvrs->next == NULL)
        {
            cout << "Can't delete! location out of bound!!" << endl;
            return;
        }
        else if (trvrs->next->next == NULL)
        {
            trvrs->next = NULL;
        }
    }
    temp = trvrs->next;
    trvrs->next = temp->next;
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

    beginInsert();
    // search();
    endInsert();
    endInsert();
    endInsert();
    endInsert();
    traverseList();
    // randInsert();
    // beginDelete();
    traverseList();
    traverseListRev();
    // endDelete();
    // randDelete();
    return 0;
}

// int main()
// {
//     int ch = 0;
//     while (ch != 9)
//     {
//         cout << "Choose operation to perform on doubly linked list: " << endl;
//         cout << "1> Search in list." << endl;
//         cout << "2> Traverse through list." << endl;
//         cout << "3> Insert in ending of list." << endl;
//         cout << "4> Insert in begining of list." << endl;
//         cout << "5> Insert at a position in list." << endl;
//         cout << "6> Delete from ending of list." << endl;
//         cout << "7> Delete from begining of list." << endl;
//         cout << "8> Delete from a position in list." << endl;
//         cout << "9> Exit programm." << endl;
//         cin >> ch;
//         switch (ch)
//         {
//         case 1:
//             search();
//             break;
//         case 2:
//             traverseList();
//             break;
//         case 3:
//             endInsert();
//             break;
//         case 4:
//             beginInsert();
//             break;
//         case 5:
//             randInsert();
//             break;
//         case 6:
//             endDelete();
//             break;
//         case 7:
//             beginDelete();
//             break;
//         case 8:
//             randDelete();
//             break;
//         case 9:
//             exit;
//             break;
//         default:
//             cout << "Enter valid input." << endl;
//             break;
//         }
//     }
//     return 0;
// }