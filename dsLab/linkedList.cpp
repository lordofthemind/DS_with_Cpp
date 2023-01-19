#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head;

void beginInsert()
{
    struct node *ptr;
    ptr = (struct node *)malloc(sizeof(struct node *));

    int item;
    if (ptr == NULL)
    {
        cout << "Overflow" << endl;
    }
    else
    {
        cout << "Enter the element :" << endl;
        cin >> item;
        ptr->data = item;
        ptr->next = head;
        head = ptr;
        ptr = NULL;
        free(ptr);
        cout << "Element inserted!" << endl;
    }
}

void display()
{
    struct node *ptr;
    ptr = head;

    if (ptr == NULL)
    {
        cout << "No element to print!" << endl;
    }
    else
    {
        cout << "Element in Linked-list are :" << endl;
        while (ptr != NULL)
        {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
        cout << endl;
    }
}

int main()
{
    beginInsert();
    display();
    return 0;
}

// #include <iostream>
// using namespace std;

// int main()
// {
//     struct node
//     {
//         int data;
//         struct node *next;
//     };
//     struct node *head;
//     struct node *ptr;

//     ptr = (struct node *)malloc(sizeof(struct node *));

//     int item;
//     if (ptr == NULL)
//     {
//         cout << "Overflow" << endl;
//     }
//     else
//         {
//         cout << "Enter the element :"<< endl;
//         cin >> item;
//         ptr->data = item;
//         ptr->next = head;
//         head = ptr;
//         //ptr = NULL;
//         //free(ptr);
//         cout << "Element inserted!" << endl;
//         }

//     // struct node *ptr;

//     if (ptr == NULL)
//     {
//         cout << "No element to print!" << endl;
//     }
//     else
//     {
//         cout << "Element in Linked-list are :"<< endl;
//        while (ptr!= NULL)
//       {
//             cout << "Element in Linked-list are :"<< endl;
//             cout << ptr->data <<" " << endl;
//             ptr = ptr->next;
//        }

//     }

//     return 0;
// }