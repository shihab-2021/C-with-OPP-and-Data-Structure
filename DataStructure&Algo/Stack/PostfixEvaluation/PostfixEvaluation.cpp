#include<bits/stdc++.h>
#include"../TemplateStack.h"
using namespace std;    

void printSt(Stack<int> st)
{
    string z="";
    int size = st.size();
    int arr[st.size()];
    int j=0;
        while(!st.empty())
        {
            arr[j] = st.pop();
            j++;
        }
        // reverse(z.begin(), z.end());
        for (int i = size-1; i >= 0; i--)
        {
            st.push(arr[i]);
            z += (to_string(arr[i]) + "  ");
        }
        
        cout << "Stack status:  " << z << endl;
}

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
                st.push(b-a);
                break;
            case '*':
                st.push(a*b);
                break;
            case '/':
                st.push(b/a);
                break;
            case '^':
                st.push(pow(b, a));
                break;
            
            default:
                break;
            }
        }
        cout << check[i] << "   -->   " << st.top() << endl;
        printSt(st);
        cout << endl;
    }
    return st.top();
}

/*
12+34** = 36
*/

int main()
{
    // cout << postfixEvaluation("12+34**") << endl;
    cout << postfixEvaluation("562^726/-+*781+*54*+-") << endl;
    return 0;
}