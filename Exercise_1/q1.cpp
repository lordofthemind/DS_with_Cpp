//  store elements in an array and print it
#include <iostream>
using namespace std;

int main()
{
    int arr[10];
    for (int i = 0; i <= 9; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    cout << "Element in array are: ";
    for (int i = 0; i <= 9; i++)
    {
        cout << arr[i];
    }
    cout << endl;
    return 0;
}