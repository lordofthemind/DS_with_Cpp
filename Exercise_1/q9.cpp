// find the maximum and minimum element in an array
#include <iostream>
using namespace std;

void elMaxMin(int arr[], int n){
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    cout << "Maximum Element : " << arr[0] << endl;
    cout << "Minimum Element : " << arr[n-1] << endl;
}

int main() {
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element of array" << i << ":";
        cin >> arr[i];
    }
    for (i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    elMaxMin(arr, n);
    return 0;
}