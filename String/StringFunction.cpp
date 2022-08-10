#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st = "abcdefg";
    cout << "Length of the string now: " << st.length() << endl;

    cout << "The string: " << st << " | size: " << st.size() << endl;
    st.resize(4);
    cout << "The string: " << st << " | size: " << st.size() << endl;

    st.clear();
    cout << "The string: " << st << " | size: " << st.size() << endl;

    if(st.empty())
        cout << "Yes" << endl;
    else 
        cout << "No" << endl;

    st = "abcdefg";
    cout << "At 4 char: " << st.at(4) << endl;
    cout << "At front char: " << st.front() << endl;
    cout << "At back char: " << st.back() << endl;
    return 0;
}