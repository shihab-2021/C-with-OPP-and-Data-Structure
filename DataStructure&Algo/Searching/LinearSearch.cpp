#include<bits/stdc++.h>
using namespace std;

int main()
{
    int size, t;
    cin >> size >> t;
    string s;
    cin >> s;
    while (t--)
    {
        string ts;
        cin >> ts;
        if(ts=="pop_back")
            s.pop_back();
        else if(ts=="front")
            cout << s[0] << endl;
        else if(ts=="back")
            cout << s[s.length()-1] << endl;
        else if(ts=="sort")
        {
            int l, r;
            cin >> l >> r;
            sort(s.begin()+(l-1), s.begin()+(r-1));
        }
        else if(ts=="reverse")
        {
            int l, r;
            cin >> l >> r;
            reverse(s[l-1], s[r-1]);
        }
    }
    
    return 0;
}