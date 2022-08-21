#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

int prefixEvaluation(string check)
{
    Stack <int> st;
    for(int i=check.length()-1; i>=0; i--)
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
+*423 = 11
-+7*45+20 = 25
*/

int main()
{
    cout << prefixEvaluation("-+7*45+20") << endl;
    return 0;
}