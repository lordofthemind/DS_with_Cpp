// implement queue using linked list and all operations on it.

// Path: queTree/queTest.cpp
// Compare this snippet from dsLab/queueLinked.cpp:
#include <iostream>
using namespace std;

struct que
{
    int data;
    struct que *next;
};
struct que *frnt;
struct que *rear;

int insert(int vl)
{
    struct que *ptr;
    ptr = (struct que *)malloc(sizeof(struct que));
    ptr->data = vl;
    if (frnt == NULL)
    {
        frnt = rear = ptr;
        frnt->next = rear->next = NULL;
        return 0;
    }
    else
    {
        rear->next = ptr;
        rear = ptr;
        rear->next = NULL;
        return 0;
    }
}

int deleteq()
{
    struct que *ptr;
    if (frnt == NULL)
    {
        cout << "Queue is empty." << endl;
        return 0;
    }
    else
    {
        ptr = frnt;
        int el = frnt->data;
        frnt = frnt->next;
        free(ptr);
        cout << "Deleted " << el << endl;
    }
    return 0;
}

void traverse()
{
    struct que *trvr;
    if (frnt == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }
    else
    {
        trvr = frnt;
        while (trvr != NULL)
        {
            cout << trvr->data << " ";
            trvr = trvr->next;
        }
        cout << endl;
    }
}

int main()
{
    int ch, vl;
    while (1)
    {
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Traverse" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter value to be inserted: ";
            cin >> vl;
            if (vl >= 0)
            {
                insert(vl);
            }
            else
                cout << "Invalid value" << endl;
            break;
        case 2:
            deleteq();
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
