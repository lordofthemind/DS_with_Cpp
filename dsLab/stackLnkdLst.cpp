#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *nxtad;
};
struct node *top, *top1, *temp;
int count = 0, elr;

int isEmpty()
{
    if (top == NULL)
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
    if (isEmpty())
    {
        top = (struct node *)malloc(sizeof(struct node));
        top->nxtad = NULL;
        top->data = itm;
    }
    else
    {
        temp = (struct node *)malloc(sizeof(struct node));
        temp->nxtad = top;
        temp->data = itm;
        top = temp;
    }
    count++;
}

void pop()
{
    int item;
    top1 = top;
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    else
    {
        top1 = top1->nxtad;
        item = top->data;
        cout << "Element popped is " << item << endl;
        free(top);
        top = top1;
        count--;
    }
}

void peek()
{
    if (isEmpty())
    {
        cout << "Stack Underflow." << endl;
        return;
    }
    cout << "Element at top is " << top->data << endl;
}

void size(){
    cout << count << " element are in the stack rightnow!" << endl;    
}

void clear(){
    temp = top;
    int item;
    if (temp == NULL)
    {
        cout << "Stack is empty!!" << endl;
    }
    else{        
        while (temp != NULL)
        {
            temp = temp->nxtad;
            item = top->data;
            cout << "Element popped is " << item << endl;
            free(top);
            top = temp;
            count--;
        }
    } 
}

void search(){
    temp = top;
    int itm, pos = 1, flag = 1;
    if (temp == NULL)
    {
        cout << "Stack is empty!!" << endl;
    }
    else{
        cout << "Enter element to search! : " <<endl;
        cin >> itm;
        while (temp != NULL)
        {
            if (temp->data == itm)
            {
                cout << "Element found in stack at position " << pos << " from Top." << endl;
                return;
            }else{
                flag = 0;
            }
            pos++;
            temp = temp->nxtad;  
        }
        if (flag == 0)
        {
            cout << "Element not found in stack!" << endl;
        }
    }    
}

int main()
{
    int ch = 0;
    while (ch != 8)
    {
        cout << "Choose operation to perform on Stack implemented with linked list! " << endl;
        cout << "1> Push element." << endl;
        cout << "2> Pop Element." << endl;
        cout << "3> Is empty??" << endl;
        cout << "4> Peek!!" << endl;
        cout << "5> Search" << endl;
        cout << "6> Size?" << endl;
        cout << "7> Clear!" << endl;
        cout << "8> Exit!" << endl;
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter element: ";
            cin >> elr;
            push(elr);
            break;
        case 2:
            pop();
            break;
        case 3:
            elr = isEmpty();
            cout << elr << endl;
            break;
        case 4:
            peek();
            break;
        case 5:
            search();
            break;
        case 6:
            size();
            break;
        case 7:
            clear();
            break;
        case 8:
            exit;
            break;
        default:
            cout << "Enter valid input." << endl;
            break;
        }
    }
    return 0;
}