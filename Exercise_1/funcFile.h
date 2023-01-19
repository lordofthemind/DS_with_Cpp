#include <iostream>
using namespace std;

int arrInpt(){
    int n;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i <= n-1; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    for (int i = 0; i <= n-1; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}