#include<bits/stdc++.h>
#include"TemplateQueue.h"
using namespace std;

typedef pair <char, int> myType;
int main()
{
    Queue <myType> q;
    int n; 
    cin >> n;
    for(int i=0; i<n; i++)
    {
        char c1;
        int c2;
        cin >> c1 >> c2;
        q.push(make_pair(c1, c2));
    }
    while(!q.empty())
    {
        myType check;
        check = q.pop();
        cout << check.first << " | " << check.second << endl;
    }
    if(!q.empty())
    {
        myType check;
        check = q.Front();
        cout << check.first << " | " << check.second << endl;
        check = q.Back();
        cout << check.first << " | " << check.second << endl;
    }

    // Queue <int> q;
    // int n;
    // cin >> n;
    // for(int i=0; i<n; i++)
    // {
    //     int value;
    //     cin >> value;
    //     q.push(value);
    // }
    // while(!q.empty())
    //     cout << q.pop() << endl;
    
    // if(!q.empty())
    // {
    //     cout << q.Front() << endl;
    //     cout << q.Back() << endl;
    // }

    return 0;
}