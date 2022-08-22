#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;

int precisionCalculate(char c)
{
    if(c == '^')
        return 3;
    else if(c == '/' || c == '*')
        return 2;
    else if(c == '+' || c == '-')
        return 1;
    else 
        return -1;
}

string infixToPrefix(string check)
{
    reverse(check.begin(), check.end()); // it is a build in function to reverse a string
    Stack <char> st;
    string result;
    for(int i=0; i<check.length(); i++)
    {
        if(check[i] >= '0' && check[i] <= '9')
            result += check[i];
        else if(check[i] == ')')
            st.push(check[i]);
        else if(check[i] == '(')
        {
            while(!st.empty() && st.top() != ')')
                result += st.pop();
            if(!st.empty())
                st.pop();
        }        
        else
        {
            while(!st.empty() && precisionCalculate(st.top()) >= precisionCalculate(check[i]))
                result += st.pop();
            st.push(check[i]);
        }
    }
    while(!st.empty())
        result += st.pop();
    reverse(result.begin(), result.end());
    return result;
}

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

int main()
{
    // string infix = "(1+2)*(3+4)";
    string infix = "(1+2)*(3*4)";
    string prefix;
    prefix = infixToPrefix(infix);
    cout << prefix << endl << prefixEvaluation(prefix) << endl;
}