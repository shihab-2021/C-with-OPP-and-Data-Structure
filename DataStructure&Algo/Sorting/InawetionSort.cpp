#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size;
    cin >> size;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Before Sorting: ";
    printArray(arr, size);
    cout << endl;

    // Insertion Sort
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i-1;
        while(arr[j] > key && j>=0)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
    cout << endl;
    cout << "After Sorting: ";
    printArray(arr, size);
    cout << endl;
    
    return 0;
}
