#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n;

    stack<int> st;
    for(int i=0; i<n; i++)
    {
        cin >> a;
        st.push(a); 
    }
    cout << "Size " << st.size() << endl;
    if(st.empty())
        cout << "Stack is empty!!" << endl;
    else 
        cout << "Stack is not empty!!!" << endl;
    for(int i=0; i<n; i++)
    {
        cout << st.top() << endl;
        st.pop();
    }
    if(st.empty())
        cout << "Stack is empty!!" << endl;
    else 
        cout << "Stack is not empty!!!" << endl;

    return 0;
}