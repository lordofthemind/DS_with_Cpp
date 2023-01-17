#include <iostream>
using namespace std;

int main() {
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
    for (int i = n-1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}