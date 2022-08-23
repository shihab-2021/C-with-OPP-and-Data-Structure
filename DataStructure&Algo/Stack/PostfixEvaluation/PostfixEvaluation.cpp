#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

int postfixEvaluation(string check)
{
    Stack <int> st;
    for(int i=0; i<check.length(); i++)
    {
        if(check[i] >= '0' && check[i] <= '9')
            st.push(check[i] - '0');
        else // check[i] ----> Operator
        {
            int a = st.pop();
            int b = st.pop();
            switch (check[i])
            {
            case '+':
                st.push(a+b);
                break;
            case '-':
                st.push(a-b);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(a/b);
                break;
            case '^':
                st.push(pow(a, b));
                break;
            
            default:
                break;
            }
        }
    }
    return st.top();
}

/*
12+34** = 36
*/

int main()
{
    cout << postfixEvaluation("12+34**") << endl;
    return 0;
}