//copy the elements of one array into another array
#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr1[n], arr2[n];
    for (int i = 0; i <= n-1; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr1[i];
    }
    cout << "Original array: ";
    for (int i = 0; i <= n-1; i++)
    {
        cout << arr1[i] << " ";
    }
    for (int i = 0; i <= n-1; i++)
    {
        arr2[i] = arr1[i];
    }
    cout << "Copied array: ";
    for (int i = 0; i <= n-1; i++)
    {
        cout << arr2[i] << " ";
    }
    cout << endl;
    return 0;
}