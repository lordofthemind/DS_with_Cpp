// #include "iostream"
// demo2.C - Sample C++ program
// int main(void)
// {
//     std::cout << "Hello! This is a C++ program.\n";
//     return 0;
// }

#include <iostream>
using namespace std;

void func(int *arr, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << *((arr + i * n) + j) << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m = 3, n = 3;
    int arr[m][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    func((int *)arr, m, n);
    return 0;
}