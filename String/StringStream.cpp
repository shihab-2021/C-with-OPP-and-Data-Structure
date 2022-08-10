#include<bits/stdc++.h>
using namespace std;

int main()
{
    string st = "pr og ra mm er";
    // stringstream strm(st);
    stringstream strm;
    strm<<st;

    string st1;
    while (strm>>st1)
    {
        cout << st1 << " ";
    }
    cout << endl;

    return 0;
}