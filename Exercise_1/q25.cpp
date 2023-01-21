// find sum of rows and columns of a Matrix
#include <iostream>
using namespace std;

//function to find and display sum of each column
void columnSum(int arr[size][size], int m, int n){
    int sum;
    
    //finding column sum
    for(int i = 0; i < n; i++){
        sum = 0;
        
        for(int j = 0;j < m; j++){
            sum = sum + arr[j][i];      //adding each element of column
        }
        cout<<"Addition of column "<<i + 1<<" is: "<<sum<<endl;   
    }
}

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
            if (i == j)
            {
                cout << arr[i][j];
                rightDgSum += arr[i][j];
            }
        }
        cout << endl;
    }
    columnSum(arr, n ,n);
    cout << "The sum of right diagonal of matrix is: " << rightDgSum << endl;
    return 0;
}