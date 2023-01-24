// find sum of right diagonals of a matrix
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, rightDgSum = 0;
    cout << "Input the size of the square matrix (less than 5): ";
    cin >> n;
    if (n >= 5)
    {
        cout << "Try again!" << endl;
        exit;
    }
    int arr[n][n];
    cout << "Enter element of matrix :" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << "Enter Element [" << i << "][" << j << "] :";
            cin >> arr[i][j];
        }
    }
    cout << "Matrix is :" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            if ((i + j) == (n - 1))
            {
                cout << arr[i][j];
                rightDgSum += arr[i][j];
            }
        }
        cout << endl;
    }
    cout << "The sum of right diagonal of matrix is: " << rightDgSum << endl;
    return 0;
}