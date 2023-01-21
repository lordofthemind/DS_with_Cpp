#include <iostream>
using namespace std;

void display(int *arr, int n, int m){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << *((arr + i * m) + j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n, m, i, j;
    cout << "Input the size of the square matrix (less than 5): ";
    cin >> n << m;
    int arr1[n][m], arr2[n][m];
    cout << "Enter element of matrix :" << endl;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter Element [" << i << "][" << j << "] :";
            cin >> arr1[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            cout << "Enter Element [" << i << "][" << j << "] :";
            cin >> arr2[i][j];
        }
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            arr3[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    cout << "The first matrix is: " << endl;
    display((int *)arr1, n, n);
    cout << "The second matrix is: " << endl;
    display((int *)arr2, n, n);
    cout << "Sum of both matrices is as follow matrix!" << endl;
    display((int *)arr3, n, n);
    return 0;
}