#include <iostream>
using namespace std;
#define MAX 20


struct aprtmntBldOne
{
    int fltNo;
    string ownrName;
    string ownrPhon;
    bool ltrStack[20];
    struct aprtmntOne *preAdd;
    struct aprtmntOne *nxtAdd;
};
struct aprtmntOne *headAdd;
int top = -1,count = 0;

void beginInsert()
{
    struct aprtmntBldOne *ptr;
    int item;
    ptr = (struct aprtmntBldOne *)malloc(sizeof(struct aprtmntBldOne));
    if (ptr == NULL)
    {
        cout << "Memory Full." << endl;
    }
    else
    {
        cout << "Enter flat no: ";
        cin >> ptr->fltNo;
        cout << "Enter Owner name: ";
        cin >> ptr->ownrName;
        cout << "Enter Phone no: ";
        cin >> ptr->ownrPhon;
        ptr->preAdd = NULL;
        if (headAdd == NULL)
        {
            ptr->nextAdd = NULL;
            headAdd = ptr;
        }
        else
        {
            ptr->nextAdd = headAdd;
            headAdd->prevAdd = ptr;
            headAdd = ptr;
        }
        cout << "Details inserted." << endl;
    }
}

void traverseList()
{
    struct aprtmntBldOne *trvrsAdd;
    trvrsAdd = head;
    if (head == NULL)
    {
        cout << "List is empty, nothing to print." << endl;
    }
    else
    {
        cout << "Reverse of list is as follows..." << endl;
        while (trvrsAdd->next != NULL)
        {
            cout << "Flat no: " << trvrsAdd->fltNo << endl;
            trvrsAdd = trvrsAdd->next;
        }
    }
}


int main()
{
    beginInsert();
    traverseList();
    return 0;
}


// int isEmpty()
// {
//     if (top == NULL)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
// }

// void push(int itm)
// {
//     if (isEmpty())
//     {
//         top = (struct node *)malloc(sizeof(struct node));
//         top->nxtad = NULL;
//         top->data = itm;
//     }
//     else
//     {
//         temp = (struct node *)malloc(sizeof(struct node));
//         temp->nxtad = top;
//         temp->data = itm;
//         top = temp;
//     }
//     count++;
// }

// void pop()
// {
//     int item;
//     top1 = top;
//     if (isEmpty())
//     {
//         cout << "Stack Underflow." << endl;
//         return;
//     }
//     else
//     {
//         top1 = top1->nxtad;
//         item = top->data;
//         cout << "Element popped is " << item << endl;
//         free(top);
//         top = top1;
//         count--;
//     }
// }

// void peek()
// {
//     if (isEmpty())
//     {
//         cout << "Stack Underflow." << endl;
//         return;
//     }
//     cout << "Element at top is " << top->data << endl;
// }

// void size(){
//     cout << count << " element are in the stack rightnow!" << endl;    
// }

// void clear(){
//     temp = top;
//     int item;
//     if (temp == NULL)
//     {
//         cout << "Stack is empty!!" << endl;
//     }
//     else{        
//         while (temp != NULL)
//         {
//             temp = temp->nxtad;
//             item = top->data;
//             cout << "Element popped is " << item << endl;
//             free(top);
//             top = temp;
//             count--;
//         }
//     } 
// }

// void search(){
//     temp = top;
//     int itm, pos = 1, flag = 1;
//     if (temp == NULL)
//     {
//         cout << "Stack is empty!!" << endl;
//     }
//     else{
//         cout << "Enter element to search! : " <<endl;
//         cin >> itm;
//         while (temp != NULL)
//         {
//             if (temp->data == itm)
//             {
//                 cout << "Element found in stack at position " << pos << " from Top." << endl;
//                 return;
//             }else{
//                 flag = 0;
//             }
//             pos++;
//             temp = temp->nxtad;  
//         }
//         if (flag == 0)
//         {
//             cout << "Element not found in stack!" << endl;
//         }
//     }    
// }

// int main()
// {
//     int ch = 0;
//     while (ch != 8)
//     {
//         cout << "Choose operation to perform on Stack implemented with array! " << endl;
//         cout << "1> Push element." << endl;
//         cout << "2> Pop Element." << endl;
//         cout << "3> Is empty??" << endl;
//         cout << "4> Peek!!" << endl;
//         cout << "5> Search" << endl;
//         cout << "6> Size?" << endl;
//         cout << "7> Clear!" << endl;
//         cout << "8> Exit!" << endl;
//         cin >> ch;
//         switch (ch)
//         {
//         case 1:
//             cout << "Enter element: ";
//             cin >> elr;
//             push(elr);
//             break;
//         case 2:
//             pop();
//             break;
//         case 3:
//             elr = isEmpty();
//             cout << elr << endl;
//             break;
//         case 4:
//             peek();
//             break;
//         case 5:
//             search();
//             break;
//         case 6:
//             size();
//             break;
//         case 7:
//             clear();
//             break;
//         case 8:
//             exit;
//             break;
//         default:
//             cout << "Enter valid input." << endl;
//             break;
//         }
//     }
//     return 0;
// }