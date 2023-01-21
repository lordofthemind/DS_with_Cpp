// merge two arrays of same size sorted in decending order
#include <iostream>
using namespace std;

int main() {
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i <= n-1; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    for (i = 0; i <= n-1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for (i = 0; i <= n-1; i++)
    {
        for (j = i + 1; j <= n-1; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }            
        }
    }
    cout << "Total number of Duplicate :" << count;
    cout << endl;
    return 0;
}