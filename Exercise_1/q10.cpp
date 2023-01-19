//separate odd and even integers in separate arrays.

#include <iostream>
using namespace std;

void oddEven(int arr[], int n){
    int oi = 0, ei = 0, i, eSize = 0, oSize = 0;
    for (int i = 0; i <= n - 1; i++)
    {
        if ((arr[i] % 2) == 0)
        {
            eSize++;
        }else{
            oSize++;
        }
    }

    // cout << eSize<<endl;
    // cout << oSize<<endl;

    int arrEven[eSize], arrOdd[oSize];
    
    for (i = 0; i <= n - 1; i++)
    {
        if ((arr[i] % 2) == 0)
        {
            arrEven[ei] = arr[i];
            ei++;
        }else{
            arrOdd[oi] = arr[i];
            oi++;
        }
    }
    cout << "Even elements are: ";
    for (i = 0; i <= eSize - 1; i++)
    {
        cout << arrEven[i] << " ";
    }
    cout << endl;
    cout << "Odd elements are: ";
    for (i = 0; i <= oSize - 1; i++)
    {
        cout << arrOdd[i] << " ";
    }
    cout << endl;
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
    cout << endl;
    oddEven(arr, n);
    cout << endl;
    return 0;
}