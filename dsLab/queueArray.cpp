#include <iostream>
using namespace std;
#define MAX 10

int arrQue[MAX];
int frnt = 0, rear = 0;

int insert(int value)
{
    if (rear >= MAX)
    {
        cout << "Queue is Full." << endl;
        return 0;
    }
    arrQue[rear++] = value;
    cout << "Value inserted." << endl;
    return 0;
}

int isEmpty()
{
    if (frnt == rear)
    {
        cout << "Queue is Empty." << endl;
        frnt = rear = 0;
        return 1;
    }
    return 0;
}

int deleteq()
{
    if (isEmpty() == 0)
    {
        int itm = arrQue[frnt++];
        cout << "Value deleted: " << itm << endl;
        return 1;
    }
    return 0;
}

void display()
{
    cout << "Front=" << frnt << endl;
    cout << "Rear=" << rear << endl;
    
    if (isEmpty() == 0)
    {
        for (int i = frnt; i < rear; i++)
        {
            cout << arrQue[i] << " ";
        }
    }
    cout << endl;
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
            deleteq ();
            break;
        case 3:
            display();
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