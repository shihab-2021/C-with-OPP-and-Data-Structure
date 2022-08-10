#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st = "programming";
    cout << "Find char 'm' from the left side: " << st.find('m') << endl;
    cout << "Find char 'm' from the right side: " << st.rfind('m') << endl;

    cout << "Find char 'm' from the left side: " << st.find_first_of('m') << endl;
    cout << "Find char 'm' from the right side: " << st.find_last_of('m') << endl;

    cout << "Find first not found of 'p': " << st.find_first_not_of('p') << endl;
    cout << "Find last not found of 'g': " << st.find_last_not_of('g') << endl;

    cout << "Substring: " << st.substr(0, 7) << endl;

    return 0;
}