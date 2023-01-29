// merge two arrays of same size sorted in decending order
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
    cout << "Merged Sorted array : ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr1[n], arr2[n], arr3[n+n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element of array 1" << i << ":";
        cin >> arr1[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << arr1[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element of array 2" << i << ":";
        cin >> arr2[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr1[i];
    }
    for (i = n; i < n+n; i++)
    {
        arr3[i] = arr1[i-n];
    }
    sortDescending(arr3, n+n);
    return 0;
}