#include <iostream>
using namespace std;
#define MAX 10

int arrStack[MAX];
int top = -1, elr;

int isFull()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int itm)
{
    if (isFull())
    {
        cout << "Stack Overflow." << endl;
        return;
    }
    top = top + 1;
    arrStack[top] = itm;
}

void pop()
{
    int item;
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    item = arrStack[top];
    top = top - 1;
    cout << "Element popped is " << item << endl;
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    cout << "Element at top is " << arrStack[top] << endl;
}

void traverse()
{
    int i;
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    else
    {
        cout << "element in stack is: " << endl;
        for (i = 0; i <= top; i++)
        {
            cout << arrStack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int ch = 0;
    while (ch != 8)
    {
        cout << "Choose operation to perform on Stack implemented with array! " << endl;
        cout << "1> Traverse through list." << endl;
        cout << "2> Push element." << endl;
        cout << "3> Pop Element." << endl;
        cout << "4> Is full??" << endl;
        cout << "5> Is empty??" << endl;
        cout << "6> Peek!!" << endl;
        cout << "8> Exit programm." << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            traverse();
            break;
        case 2:
            cout << "Enter element: ";
            cin >> elr;
            push(elr);
            break;
        case 3:
            pop();
            break;
        case 4:
            elr = isFull();
            cout << elr << endl;
            break;
        case 5:
            elr = isEmpty();
            cout << elr << endl;
            break;
        case 6:
            peek();
            break;
        case 7:
            exit;
            break;
        default:
            cout << "Enter valid input." << endl;
            break;
        }
    }
    return 0;
}