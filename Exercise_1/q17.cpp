//find the second smallest element in an array
#include <iostream>
using namespace std;

void scndSmalestElement(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    cout << "Second smallest element in array : ";
    cout << arr[1] << " "<< endl;
    
}

int main()
{
    int i, j, n, count = 0;
    cout << "Enter length of array: ";
    cin >> n;
    int arr[n];
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element " << i << ":";
        cin >> arr[i];
    }
    scndSmalestElement(arr, n);
    return 0;
}