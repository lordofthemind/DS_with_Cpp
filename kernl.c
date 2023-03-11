#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10

int insert(int);

int rear = 0, front = 0;
int queue[MAXSIZE];

int insert(int value)
{
        if (rear >= MAXSIZE)
        {
                printf("\nQueue is Full\n");
                return;
        }
        queue[rear++] = value;
        printf("\nInserted value\n");
}

int isEmpty()
{
        if (front == rear)
        {
                printf("\n Queue is Empty\n");
                front = rear = 0;
                return 1;
        }
        return 0;
}

int delete()
{
        if (isEmpty() == 0)
        {
                int item = queue[front++];
                printf("\nDeleted value: %d\n", item);
                return;
        }
}

void display()
{
        if (isEmpty() == 0)
        {
                for (int i = front; i < rear; i++)
                {
                        printf("%d ", queue[i]);
                }
        }
}

void main()
{
        int ch, value;

        while (1)
        {
                printf("\nEnter your choice for QUEUE\n");

                printf("\n1) Insert\n2) Delete\n3) Display\n4) Exit\n");
                scanf("%d", &ch);
                switch (ch)
                {
                case 1:
                        printf("\nEnter value to be inserted\n");
                        scanf("%d", &value);
                        if (value >= 0)
                        {
                                insert(value);
                        }
                        else
                                printf("\nInvalid value\n");
                        break;
                case 2:
                        delete ();
                        break;
                case 3:
                        display();
                        break;
                case 4:
                        exit(0);
                default:
                        printf("\nInvalid choice\n");
                        break;
                }
        }
}