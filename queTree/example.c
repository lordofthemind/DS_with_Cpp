void allocate(int **ptr)
{
    *ptr = (int *)malloc(sizeof(int));
    **ptr = 42;
}

int main()
{
    int *ptr = NULL;
    allocate(&ptr);
    printf("%d\n", *ptr);
    free(ptr);
    return 0;
}

void print_array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", *(arr + i));
    }
    printf("\n");
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};
    print_array(arr, 5);
    return 0;
}

void print_data(void *data, int type)
{
    switch (type)
    {
    case 0:
        printf("%d\n", *(int *)data);
        break;
    case 1:
        printf("%f\n", *(float *)data);
        break;
    case 2:
        printf("%s\n", (char *)data);
        break;
    default:
        printf("Invalid type\n");
        break;
    }
}

int main()
{
    int a = 42;
    float b = 3.14;
    char c[] = "hello";
    print_data(&a, 0);
    print_data(&b, 1);
    print_data(c, 2);
    return 0;
}
