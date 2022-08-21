#include<bits/stdc++.h>
#include"MyStack.h"
using namespace std;

int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);

    while (!st.empty())
    {
        cout << st.pop() << endl;
    }
    cout << st.size() << endl;
    if(!st.empty()) 
        cout << st.top() << endl;   
    
    return 0;
    
}