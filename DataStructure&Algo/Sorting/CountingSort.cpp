#include<bits/stdc++.h>
using namespace std;

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int size, max;
    cin >> size;
    int arr[size];

    // Step 1: Input array and Finding max
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
        if(i==0)
            max = arr[i];
        else
        {
            if(max<arr[i])
                max = arr[i];
        }
    }

    cout << "Before Sort: ";
    printArr(arr, size);

    cout << "Step-1: Max number is:  " << max << endl;

    // Step 2: Initialization of 'count' array
    int count[max+1] = {0};

    // Step 3: Frequency calculation
    for (int i = 0; i < size; i++)
    {
        count[arr[i]]++;
    }
    cout << "Step-2: Frequency calculation count array:  ";
    for (int i = 0; i < max+1; i++)
    {
        cout << count[i] << "  ";
    }
    cout << endl;

    // Step 4: Cumulative Sum
    for (int i = 1; i <= max; i++)
    {
        count[i] += count[i-1];
    }
    cout << "Step-3: Cumulative Sum in count array:  ";
    for (int i = 0; i < max+1; i++)
    {
        cout << count[i] << "  ";
    }
    cout << endl;
    
    // Step 5: Final array --> Backward Traversal of basic array
    int finalArr[size];
    for (int i = size-1; i >= 0; i--)
    {
        count[arr[i]]--;
        int k = count[arr[i]];
        finalArr[k] = arr[i];
    }
    
    cout << "Step-4: After Sort: ";
    printArr(finalArr, size);

    return 0;
}