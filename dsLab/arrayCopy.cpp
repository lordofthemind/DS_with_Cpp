#include <iostream>
using namespace std;

void arrayCopy(int arr[], int n){
    int carr[n], i;
    for (int i = 0; i < n; i++)
    {
        carr[i] = arr[i];
    }
    cout << "Element in copied array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << carr[i] << " ";
    }
    cout << endl;
    
}


void arrayRevCopy(int arr[], int n){
    int carr[n], i, j;
    // for (i = 0, j = n-1; i < n, j = 0; i++, j--)
    // j = n;
    for (i = 0, j = n-1; i < n ; i++, j--)
    {
        carr[j] = arr[i];

    }
    cout << "Element in copied array in reverse are: ";
    for (int i = 0; i < n; i++)
    {
        cout << carr[i] << " ";
    }
    cout << endl;    
}

int main() {
    int arr[6] = {2, 7, 9, 4, 5, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    arrayCopy(arr, n);
    arrayRevCopy(arr, n);
    return 0;
}