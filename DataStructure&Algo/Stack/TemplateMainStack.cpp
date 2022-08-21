#include<bits/stdc++.h>
#include"TemplateStack.h"
using namespace std;

int main()
{
    // Stack <int> st;
    // st.push(10);
    // st.push(11);
    // st.push(12);

    // while (!st.empty())
    //     cout << st.pop() << endl;
        
    // cout << st.size() << endl;

    // if(!st.empty()) 
    //     cout << st.top() << endl;   

    Stack <pair <int, char>> st;
    st.push(make_pair(1, 'a'));
    st.push(make_pair(2, 'b'));
    st.push(make_pair(3, 'c'));

    while (!st.empty())
    {
        pair <int, char> check;
        check = st.pop();
        cout << check.first << " | " << check.second << endl;
    }
    cout << st.size() << endl;
    
    if(!st.empty()) 
        cout << st.top().first << " | " << st.top().second << endl;   
    
    return 0;
    
}