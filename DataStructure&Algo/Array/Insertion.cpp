#include<bits/stdc++.h>
using namespace std;

void PrintArray(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int array[50];
    int size;
    cin >> size;
    for (int i = 0; i < size; i++)
    {
        cin >> array[i];
    }
    cout << "Given array: ";
    PrintArray(array, size);

    int pos, value;
    cout << "Position of the insertion: ";
    cin >> pos;
    cout << "Value of the insertion: ";
    cin >> value;
    if(pos < 0 || pos > size)
    {
        cout << "Invalid Index";
    }
    else
    {
        for (int i = size-1; i >= pos; i--)
        {
            array[i+1] = array[i];
        }
        array[pos] = value;
    }
    cout << "Array After the insertion:";
    PrintArray(array, size+1);
    
    return 0;
}