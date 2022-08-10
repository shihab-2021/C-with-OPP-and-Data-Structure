#include<bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int x, int lb, int ub)
{
    if(lb<=ub)
    {
        int mid = (lb + ub) / 2;
        if(x == arr[mid]) 
            return mid;
        else if(x > arr[mid])
            binarySearch(arr, x, mid+1, ub);
        else
            binarySearch(arr, x, lb, mid-1);
    }
    else
        return -1;
}

int main()
{
    int size;
    cout << "Please enter the number of input: ";
    cin >> size;
    int arr[size];
    cout << "Please enter the inputs one by one: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    char c;
    cout << "Do you want to search? (Y/N) : " ;
    cin >> c;
    while (toupper(c) == 'Y')
    {
        int checkValue;
        cout << "Please enter the value you want to search: ";
        cin >> checkValue;
        int indexNumber = binarySearch(arr, checkValue, 0, size-1);
        if(indexNumber == -1)
            cout << "Not Found!" << endl;
        else
            cout << "Index No: " << indexNumber << " Position No: " << indexNumber+1 << endl;
        
        cout << endl << "Do you want to continue searching? (Y/N) : " ;
        cin >> c;
    }
    
    return 0;
}