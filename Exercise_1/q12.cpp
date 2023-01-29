//sort elements of the array in descending order.

#include <iostream>
using namespace std;

void sortDescending(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    cout << "Sorted array : ";
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
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    cout << "Original Array:";
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sortDescending(arr, n);
    cout << endl;
    return 0;
}