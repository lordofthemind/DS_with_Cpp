// find the sum of left diagonals of a matrix
#include <iostream>
using namespace std;

int main()
{
    int n, i, j, leftDgSum = 0;
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
            if (i == j)
            {
                cout << arr[i][j];
                leftDgSum += arr[i][j];
            }
        }
        cout << endl;
    }
    cout << "The sum of left diagonal of matrix is: " << leftDgSum << endl;
    return 0;
}