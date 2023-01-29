// count a total number of duplicate elements in an array
#include <iostream>
using namespace std;

int main() {
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }            
        }
    }
    cout << "Total number of Duplicate :" << count << endl;
    return 0;
}