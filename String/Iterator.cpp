#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st = "abcde";
    string::iterator it1;
    for (it1=st.begin(); it1!=st.end(); it1++)
    {
        cout << *it1 << " ";
    }
    cout << endl;
    string::reverse_iterator it2;
    for (it2=st.rbegin(); it2!=st.rend(); it2++)
    {
        cout << *it2 << " ";
    }
    cout << endl;
    for (string::reverse_iterator it3=st.rbegin(); it3!=st.rend(); it3++)
    {
        cout << *it3 << " ";
    }
    cout << endl;
    for (auto it4=st.rbegin(); it4!=st.rend(); it4++)
    {
        cout << *it4 << " ";
    }
    cout << endl;
    
    return 0;
}