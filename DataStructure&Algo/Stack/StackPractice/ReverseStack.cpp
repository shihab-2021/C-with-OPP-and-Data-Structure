#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

void insertAtBottom(Stack <int> &check, int checkElement)
{
    if(check.empty())
    {
        check.push(checkElement);
        return;
    }
    int topElement = check.top();
    check.pop();
    insertAtBottom(check, checkElement);

    check.push(topElement);
}

void reverseStack(Stack <int> &check)
{
    if(check.empty())
        return;
    int topElement = check.top();
    check.pop();
    reverseStack(check);
    insertAtBottom(check, topElement);
}

int main()
{
    Stack <int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    reverseStack(st);

    while(!st.empty())
    {
        cout << st.pop() << endl;
    }

    return 0;
}