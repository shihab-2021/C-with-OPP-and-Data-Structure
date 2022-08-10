#include<bits/stdc++.h>
using namespace std;

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
        int flag = 0;
        for (int i = 0; i < size; i++)
        {
            if(arr[i] == checkValue)
            {
                flag = 1;
                cout << "Index No: " << i << " Position No: " << i+1 << endl;
            }
        }
        if(flag == 0)
            cout << "Not Found!" << endl;
        
        cout << endl << "Do you want to continue searching? (Y/N) : " ;
        cin >> c;
    }
    
    return 0;
}