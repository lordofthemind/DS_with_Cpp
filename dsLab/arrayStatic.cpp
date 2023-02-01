#include <iostream>
using namespace std;

int main() {
    int arr[6] = {5, 6, 2, 8, 3, 5};
    cout << "Element in array are: ";
    cout << endl;
    for (int i = 0; i < 6; i++)
    {
        cout << "Element " << i << " is :" << arr[i] << endl;
    }
    return 0;
}