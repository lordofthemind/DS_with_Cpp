// sort elements of the array in descending order.

#include <iostream>
using namespace std;

void posDelet(int arr[], int n)
{
    int pos;
    cout << "Enter position of element: " << endl;
    cin >> pos;
    if (pos > n)
    {
        cout << "\nThis is out of range.\n";
    }
    else
    {
        --pos;
        for (int i = pos; i <= n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    for (int i = 0; i <= n - 2; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
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
    cout << "Original Array:";
    for (i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    posDelet(arr, n);
    cout << endl;
    return 0;
}