// insert New value in the array (sorted list )..

#include <iostream>
using namespace std;

void insertElement(int arr[], int n);
void sortAscending(int arr[], int n);

int main()
{
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i <= n - 1; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    cout << "Original Array:";
    for (i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertElement(arr, n);
    cout << endl;
    return 0;
}

void insertElement(int arr[], int n){
    sortAscending(arr, n);
    int el;
    cout << "Enter element to insert: " << endl;
    cin >>el;
    int narr[n+1];
    narr[0] = el;
    for (int i = 0; i < n; i++)
    {
        narr[i +1 ] = arr[i];
    }
    n++;
    sortAscending(narr, n);
}

void sortAscending(int arr[], int n){
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    cout << "Sorted array : ";
    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    
}