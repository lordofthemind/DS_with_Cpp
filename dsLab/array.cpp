#include <iostream>
using namespace std;

void arrayCopy(int arr[], int n){
    int carr[n], i;
    for (int i = 0; i < n; i++)
    {
        carr[i] = arr[i];
    }
    cout << "Element in copied array are: ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " is :" << carr[i] << endl;
    }
    
}

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    cout << "Element in array are: ";
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Element " << i << " is :" << arr[i] << endl;
    }
    arrayCopy(arr, n);
    return 0;
}