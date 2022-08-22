#include<bits/stdc++.h>
#include"MyQueue.h"
using namespace std;

int main()
{
    Queue q;
    int n;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        int value;
        cin >> value;
        q.push(value);
    }
    while(!q.empty())
        cout << q.pop() << endl;
    
    if(!q.empty())
    {
        cout << q.Front() << endl;
        cout << q.Back() << endl;
    }

    return 0;
}