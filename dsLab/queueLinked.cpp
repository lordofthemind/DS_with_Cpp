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
            cout << trvr->data;
            if (trvr->next != NULL)
                cout << " -> ";
            trvr = trvr->next;
        }
        cout << endl;
    }
}

int main()
{
    int ch, value;

    while (1)
    {
        cout << "Enter your choice for QUEUE!" << endl;

        cout << "1) Insert\n2) Delete\n3) Display\n4) Exit" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "\nEnter value to be inserted: " << endl;
            cin >> value;
            if (value >= 0)
            {
                insert(value);
            }
            else
                cout << "Invalid value\n"
                     << endl;
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
            break;
        }
    }
    return 0;
}