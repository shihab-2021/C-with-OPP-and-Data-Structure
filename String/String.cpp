#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st1 = "abc";
    string st2 = "xyz";

    string add = st1 + st2;
    cout << add << endl;

    if (st1 == st2)
    {
        cout << "Same" << endl;
    }
    else
    {
        cout << "Not same" << endl;
    }
    
    return 0;
}