// find the second largest element in an array
#include <iostream>
using namespace std;

void scndLargestElement(int arr[], int n){
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = i + 1; j <= n - 1; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }        
    }
    cout << "Second largest element in array : ";
    cout << arr[n-2] << " "<< endl;    
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
    scndLargestElement(arr, n);
    return 0;
}