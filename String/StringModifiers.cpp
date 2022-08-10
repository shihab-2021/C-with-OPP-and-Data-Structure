#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st = "abc";
    st.assign("xyz"); // st=xyz
    cout << "After assigned: " << st << endl;

    string st1 = "abc";
    string st2 = "xyz";
    st1.append(st2); // st1 = abcxyz
    cout << "After append: " << st1 << endl;

    st1.pop_back();
    cout << "After pop back: " << st1 << endl;
    st1.push_back('z');
    cout << "After pop back: " << st1 << endl;

    st.insert(0, "abc");
    cout << "After insert: " << st << endl;

    st.erase(3, 3);
    cout << "After erase: " << st << endl;

    st1 = "abc";
    st2 = "xyz";
    swap(st1, st2);
    cout << "st1 is: " << st1 << " | st2 is: " << st2 << endl;

    return 0;
}