#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

void reverseSentence(string check)
{
    Stack <string> st;
    for (int i = 0; i < check.length(); i++)
    {
        string word = "";
        while (i<check.length() && check[i] != ' ')
        {
            word += check[i];
            i++;
        }
        st.push(word);
    }
    while(!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}

int main()
{
    string s = "This is stack";
    reverseSentence(s);

    return 0;
}