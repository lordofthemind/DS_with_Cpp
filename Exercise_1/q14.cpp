// insert New value in the array (unsorted list )..

#include <iostream>
using namespace std;

void insertElement(int arr[], int n){
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
    cout << "Final array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

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
    cout << "Array:";
    for (i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    insertElement(arr, n);
    cout << endl;
    return 0;
}

