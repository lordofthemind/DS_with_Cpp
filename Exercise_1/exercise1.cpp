#include <iostream>
using namespace std;

int enterArrayLen(int n){
    cout << "Enter length of array: ";
    cin >> n;
    return n;
}

void enterArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter Element  [" << i << "] :";
        cin >> arr[i];
    }
}

void display1DArray(int arr[], int n)
{
    cout << "Element in array are: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void displayArrayRev(int arr[], int n)
{
    cout << "Reverse array: ";
    for (int i = n - 1; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void addElement(int arr[], int n){
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }
    cout << "Sum of element in array are: ";
    cout << sum << endl;
}

void copyArray(int arr[], int n){
    int arr2[n];
    for (int i = 0; i < n; i++)
    {
        arr2[i] = arr[i];
    }
    cout << "Copied ";
    display1DArray(arr2, n);
}

void countDuplicate(int arr[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break;
            }            
        }
    }
    cout << "Total number of Duplicate :" << count << endl;
}

void sortDescending(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if(arr[i] < arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        
    }
    cout << "Sorted ";
    display1DArray(arr, n);
}

void merge2Array(int arr[], int n){    
    int i, arr1[n], arr3[n+n];
    cout << "Enter value in second array." << endl;
    for (i = 0; i < n; i++)
    {
        cout << "Enter Element [" << i << "] :";
        cin >> arr1[i];
    }
    for (i = 0; i < n; i++)
    {
        arr3[i] = arr[i];
    }
    for (i = n; i < n+n; i++)
    {
        arr3[i] = arr1[i-n];
    }
    cout << "Merged ";
    sortDescending(arr3, n+n);
}

void oddEven(int arr[], int n){
    int oi = 0, ei = 0, i, eSize = 0, oSize = 0;
    for (int i = 0; i < n; i++)
    {
        if ((arr[i] % 2) == 0)
        {
            eSize++;
        }else{
            oSize++;
        }
    }
    
    int arrEven[eSize], arrOdd[oSize];
    
    for (i = 0; i < n; i++)
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

void sortAscending(int arr[], int n){
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
    cout << "Sorted ";
    display1DArray(arr, n);
}

void insertElementUnsort(int arr[], int n){
    int el;
    cout << "Enter element to insert: " << endl;
    cin >>el;
    int narr[n+1];
    narr[0] = el;
    for (int i = 0; i < n; i++)
    {
        narr[i +1 ] = arr[i];
    }
    n++;
    display1DArray(narr, n);        
}


void insertElementSort(int arr[], int n){
    sortAscending(arr, n);
    int el;
    cout << "Enter element to insert: " << endl;
    cin >>el;
    int narr[n+1];
    narr[0] = el;
    for (int i = 0; i < n; i++)
    {
        narr[i +1 ] = arr[i];
    }
    n++;
    sortAscending(narr, n);
}

void posDelet(int arr[], int n)
{
    int pos;
    cout << "Enter position of element: " << endl;
    cin >> pos;
    if (pos > n)
    {
        cout << "\nThis is out of range.\n";
    }
    else
    {
        --pos;
        for (int i = pos; i < n; i++)
        {
            arr[i] = arr[i + 1];
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        cout << arr[i] << " ";

    }
    cout << endl;
}


int main()
{
    int n, ch;
    n = enterArrayLen(n);
    int arr[n];
    cout << "Enter Question number: ";
    cin >> ch;
    switch (ch)
    {
    case 1:
        enterArray(arr, n);
        display1DArray(arr, n);        
        break;
    case 2:        
        enterArray(arr, n);
        displayArrayRev(arr, n);
        break;
    case 3:        
        enterArray(arr, n);
        addElement(arr, n);
        break;
    case 4:        
        enterArray(arr, n);
        copyArray(arr, n);
        break;
    case 5:        
        enterArray(arr, n);
        countDuplicate(arr, n);
        break;
    case 6:        
        cout << "Pending" << endl;
        break;
    case 7:        
        enterArray(arr, n);
        merge2Array(arr, n);
        break;
    case 8:        
        cout << "Pending" << endl;
        break;
    case 9:        
        enterArray(arr, n);
        sortDescending(arr, n);
        cout << "Maximum element :" << arr[0] << endl << "Minimum element :" << arr[n-1] << endl;
        break;
    case 10:        
        enterArray(arr, n);
        oddEven(arr, n);
        break;
    case 11:        
        enterArray(arr, n);
        sortAscending(arr, n);
        break;
    case 12:        
        enterArray(arr, n);
        sortDescending(arr, n);
        break;
    case 13:        
        enterArray(arr, n);
        insertElementUnsort(arr, n);
        break;
    case 14:        
        enterArray(arr, n);
        insertElementSort(arr, n);
        break;
    case 15:        
        enterArray(arr, n);
        posDelet(arr, n);
        break;
    case 16:        
        enterArray(arr, n);
        sortAscending(arr, n);
        cout << "Second largest element : " << arr[n-2] << endl;
        break;
    case 17:        
        enterArray(arr, n);
        sortAscending(arr, n);
        cout << "Second smallest element : " << arr[1] << endl;
        break;
    case 18:        
        enterArray(arr, n);
        sortAscending(arr, n);
        cout << "Second smallest element : " << arr[1] << endl;
        break;
    
    default:
        break;
    }
    return 0;
}