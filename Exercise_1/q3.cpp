// find the sum of all elements of the array
#include <iostream>
using namespace std;

int main() {
    int n, sum = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of element in array are: ";
    cout << sum << endl;
    return 0;
}