// print all unique elements in an array.

#include <iostream>
using namespace std;

void printDistinct(int arr[], int n)
{
    // Pick all elements one by one
    for (int i = 0; i < n; i++)
    {
        // Check if the picked element is already printed
        int j;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;

        // If not printed earlier, then print it
        if (i == j)
            cout << arr[i] << " ";
    }
}

int main()
{
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i <= n - 1; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    cout << "Original Array:";
    for (i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "Distinct Array:" << endl;
    printDistinct(arr, n);
    cout << endl;
    return 0;
}