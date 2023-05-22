#include <stdio.h>
#include <stdlib.h>

struct cLink
{
    int data;
    struct cLink *next;
};

struct cLink *head = NULL;

void insert(int val)
{
    struct cLink *nNode = (struct cLink *)malloc(sizeof(struct cLink));
    nNode->data = val;

    if (head == NULL)
    {
        head = nNode;
        nNode->next = head;
    }
    else
    {
        struct cLink *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = nNode;
        nNode->next = head;
    }
}

void delet()
{
    if (head == NULL)
    {
        printf("NO ITEM\n");
        return;
    }

    struct cLink *temp = head;
    if (temp->next == head)
    {
        printf("Popped - %d\n", temp->data);
        free(temp);
        head = NULL;
    }
    else
    {
        printf("Popped - %d\n", temp->data);
        struct cLink *temp1 = temp->next;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = temp1;
        free(head);
        head = temp1;
    }
}

void traverse()
{
    if (head == NULL)
    {
        printf("NO ITEM\n");
        return;
    }

    struct cLink *temp = head;
    if (temp->next == head)
    {
        printf("%d ", temp->data);
    }
    else
    {
        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }
    printf("\n");
}

void search()
{
    if (head == NULL)
    {
        printf("NO ITEM IN QUEUE\n");
        return;
    }

    int val;
    printf("Enter the value to search: ");
    scanf("%d", &val);

    struct cLink *temp = head;
    do
    {
        if (temp->data == val)
        {
            printf("Value found\n");
            return;
        }
        temp = temp->next;
    } while (temp != head);

    printf("Value not found\n");
}

int main()
{
    int ch, val;
    while (1)
    {
        printf("1. Insert 2. Delete 3. Traverse 4. Search 5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
        case 1:
            printf("Enter the value to insert: ");
            scanf("%d", &val);
            insert(val);
            break;
        case 2:
            delet();
            break;
        case 3:
            traverse();
            break;
        case 4:
            search();
            break;
        case 5:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }

    return 0;
}
