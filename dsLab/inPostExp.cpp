#include <iostream>
#include <ctype.h>

using namespace std;

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

char pop()
{
    if (top == -1)
    {
        return -1;
    }
    else
    {
        return stack[top--];
    }
}

int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    return 0;
}

// int main(){
//     cout << priority('(') << endl;
//     cout << priority('+') << endl;
//     cout << priority('-') << endl;
//     cout << priority('*') << endl;
//     cout << priority('/') << endl;

//     push(3);
//     push(7);
//     push('+');
//     push('-');
//     push('*');
//     for (int i = 0; i < 5; i++)
//     {
//         int itm = pop();
//         cout << itm << endl;
//     }
    
// }

int main()
{
    char exp[100];
    char *e, x;
    cout << "Enter the Infix expression : ";
    cin >> exp;
    e = exp;
    cout << "The expression in postfix : " << endl;
    while (*e != '\0')
    {
        if (isalnum(*e))
            cout << *e;
        else if (*e == '(')
            push(*e);
        else if (*e == ')')
        {
            while ((x = pop()) != '(')
                cout << x;
        }
        else
        {
            while (priority(stack[top]) >= priority(*e))
                cout << pop();
            push(*e);
        }
        e++;
    }
    while (top != -1)
    {
        cout << pop();
    }
    cout << endl;
    return 0;
}